#include "fnv/memory/fixed_pool.h"

#include <algorithm>
#include <cstring>
#include <exception>
#include <limits>
#include <new>

namespace fnv::memory {
namespace {
constexpr std::size_t BitsPerWord = sizeof(std::uint64_t) * 8;

bool Add(std::size_t first, std::size_t second, std::size_t& result) noexcept
{
    if (first > (std::numeric_limits<std::size_t>::max)() - second)
        return false;
    result = first + second;
    return true;
}
} // namespace

bool FixedPool::Initialize(std::size_t blockBytes, std::size_t reserveBytes,
                           const char* name) noexcept
{
    std::lock_guard guard(lock_);
    if (region_.base)
        return blockBytes_ == blockBytes && region_.reserved == reserveBytes;

    const auto pageBytes = NativePageSize();
    const auto alignment = alignof(std::max_align_t);
    if (!pageBytes || !blockBytes || blockBytes > pageBytes ||
        blockBytes > (std::numeric_limits<std::size_t>::max)() - (alignment - 1))
        return false;

    stride_ = (std::max(blockBytes, sizeof(FreeBlock)) + alignment - 1) &
              ~(alignment - 1);
    slotsPerPage_ = pageBytes / stride_;
    if (!slotsPerPage_ || !region_.Reserve(reserveBytes, 0)) {
        stride_ = slotsPerPage_ = 0;
        return false;
    }

    pageCount_ = region_.reserved / pageBytes;
    const auto capacity = pageCount_ * slotsPerPage_;
    const auto bitWords = (capacity + BitsPerWord - 1) / BitsPerWord;
    std::size_t countBytes = 0;
    std::size_t bitBytes = 0;
    std::size_t metadataBytes = 0;
    if (pageCount_ > (std::numeric_limits<std::size_t>::max)() / sizeof(std::uint16_t) ||
        bitWords > (std::numeric_limits<std::size_t>::max)() / sizeof(std::uint64_t)) {
        region_.Release();
        pageCount_ = stride_ = slotsPerPage_ = 0;
        return false;
    }
    countBytes = pageCount_ * sizeof(std::uint16_t);
    countBytes = (countBytes + alignof(std::uint64_t) - 1) &
                 ~(alignof(std::uint64_t) - 1);
    bitBytes = bitWords * sizeof(std::uint64_t);
    if (!Add(countBytes, bitBytes, metadataBytes) ||
        !metadata_.Reserve(metadataBytes, metadataBytes)) {
        region_.Release();
        pageCount_ = stride_ = slotsPerPage_ = 0;
        return false;
    }

    pageCounts_ = reinterpret_cast<std::uint16_t*>(metadata_.base);
    allocationBits_ = reinterpret_cast<std::uint64_t*>(metadata_.base + countBytes);
    std::fill_n(pageCounts_, pageCount_, std::uint16_t{0xffff});
    std::memset(allocationBits_, 0, bitBytes);
    blockBytes_ = blockBytes;
    name_ = name;
    return true;
}

void FixedPool::Shutdown() noexcept
{
    std::lock_guard guard(lock_);
    free_ = nullptr;
    pageCounts_ = nullptr;
    allocationBits_ = nullptr;
    pageCount_ = slotsPerPage_ = blockBytes_ = stride_ = 0;
    committedPages_ = allocatedBlocks_ = 0;
    name_ = nullptr;
    metadata_.Release();
    region_.Release();
}

bool FixedPool::ContainsAddress(const void* memory) const noexcept
{
    std::lock_guard guard(lock_);
    if (!memory || !region_.base)
        return false;
    const auto address = reinterpret_cast<std::uintptr_t>(memory);
    const auto base = reinterpret_cast<std::uintptr_t>(region_.base);
    return address >= base && address - base < region_.reserved;
}

bool FixedPool::IsExactSlotLocked(const void* memory, std::size_t& slot) const noexcept
{
    if (!memory || !region_.base)
        return false;
    const auto address = reinterpret_cast<std::uintptr_t>(memory);
    const auto base = reinterpret_cast<std::uintptr_t>(region_.base);
    if (address < base || address - base >= region_.reserved)
        return false;
    const auto offset = static_cast<std::size_t>(address - base);
    const auto pageBytes = NativePageSize();
    const auto pageIndex = offset / pageBytes;
    const auto pageOffset = offset % pageBytes;
    if (pageCounts_[pageIndex] == 0xffff || pageOffset % stride_)
        return false;
    const auto pageSlot = pageOffset / stride_;
    if (pageSlot >= slotsPerPage_)
        return false;
    slot = pageIndex * slotsPerPage_ + pageSlot;
    return true;
}

bool FixedPool::IsAllocatedLocked(std::size_t slot) const noexcept
{
    return (allocationBits_[slot / BitsPerWord] &
            (std::uint64_t{1} << (slot % BitsPerWord))) != 0;
}

void FixedPool::SetAllocatedLocked(std::size_t slot, bool allocated) noexcept
{
    auto& word = allocationBits_[slot / BitsPerWord];
    const auto mask = std::uint64_t{1} << (slot % BitsPerWord);
    if (allocated)
        word |= mask;
    else
        word &= ~mask;
}

void FixedPool::PushLocked(void* memory) noexcept
{
    auto* block = ::new (memory) FreeBlock{nullptr, free_};
    if (free_)
        free_->previous = block;
    free_ = block;
}

bool FixedPool::CommitPageLocked(std::size_t pageIndex) noexcept
{
    const auto pageBytes = NativePageSize();
    if (pageIndex >= pageCount_ || pageCounts_[pageIndex] != 0xffff ||
        !region_.CommitRange(pageIndex * pageBytes, pageBytes))
        return false;
    auto* page = region_.base + pageIndex * pageBytes;
    for (std::size_t index = 0; index < slotsPerPage_; ++index)
        PushLocked(page + index * stride_);
    pageCounts_[pageIndex] = 0;
    ++committedPages_;
    return true;
}

void* FixedPool::Allocate() noexcept
{
    std::lock_guard guard(lock_);
    if (!region_.base)
        return nullptr;
    if (!free_) {
        std::size_t pageIndex = 0;
        while (pageIndex < pageCount_ && pageCounts_[pageIndex] != 0xffff)
            ++pageIndex;
        if (pageIndex == pageCount_ || !CommitPageLocked(pageIndex))
            return nullptr;
    }

    auto* block = free_;
    free_ = block->next;
    if (free_)
        free_->previous = nullptr;
    block->~FreeBlock();

    std::size_t slot = 0;
    if (!IsExactSlotLocked(block, slot) || IsAllocatedLocked(slot))
        std::terminate();
    SetAllocatedLocked(slot, true);
    ++pageCounts_[slot / slotsPerPage_];
    ++allocatedBlocks_;
    return block;
}

bool FixedPool::Deallocate(void* memory) noexcept
{
    if (!memory)
        return true;
    std::lock_guard guard(lock_);
    std::size_t slot = 0;
    if (!IsExactSlotLocked(memory, slot) || !IsAllocatedLocked(slot))
        return false;
    SetAllocatedLocked(slot, false);
    --pageCounts_[slot / slotsPerPage_];
    --allocatedBlocks_;
    PushLocked(memory);
    return true;
}

std::size_t FixedPool::Size(const void* memory) const noexcept
{
    std::lock_guard guard(lock_);
    std::size_t slot = 0;
    return IsExactSlotLocked(memory, slot) && IsAllocatedLocked(slot)
        ? blockBytes_ : 0;
}

FixedPoolStatistics FixedPool::Statistics() const noexcept
{
    std::lock_guard guard(lock_);
    return {name_, blockBytes_, stride_, region_.reserved,
            pageCount_ * slotsPerPage_, committedPages_, allocatedBlocks_};
}

bool FixedPool::IsInitialized() const noexcept
{
    std::lock_guard guard(lock_);
    return region_.base != nullptr;
}

} // namespace fnv::memory
