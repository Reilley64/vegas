#include "fnv/memory/engine_heap.h"
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <new>

namespace fnv::memory {
namespace {
constexpr std::size_t Alignment = alignof(std::max_align_t);
constexpr std::size_t MaximumBlock = 0x0fffffff; // source size/flags boundary
std::size_t AlignedSize(std::size_t bytes) noexcept
{
    if (bytes > MaximumBlock - Alignment + 1) return 0;
    return (std::max(bytes, 2*sizeof(void*)) + Alignment - 1) & ~(Alignment - 1);
}
bool Inside(const VirtualRegion& region, const void* memory) noexcept
{
    const auto address = reinterpret_cast<std::uintptr_t>(memory);
    const auto base = reinterpret_cast<std::uintptr_t>(region.base);
    return region.base && address >= base && address - base < region.reserved;
}
}
std::size_t EngineHeap::SizeOf(const Block* block) noexcept { return block->sizeAndFlags & ~Free; }
EngineHeap::Block* EngineHeap::Next(Block* block) noexcept
{ return reinterpret_cast<Block*>(reinterpret_cast<std::byte*>(block) + sizeof(Block) + SizeOf(block)); }
EngineHeap::Links EngineHeap::LoadLinks(const Block* block) noexcept
{
    Links links;
    std::memcpy(&links, block + 1, sizeof(links));
    return links;
}
void EngineHeap::StoreLinks(Block* block, Links links) noexcept { std::memcpy(block + 1, &links, sizeof(links)); }
std::size_t EngineHeap::Bucket(std::size_t bytes) const noexcept { return std::min(bytes/Alignment - 1, std::size_t(1024)); }
// 00aa9d30/9e50: the two ends and both intrusive links have one owner.
void EngineHeap::AddFree(Block* block) noexcept
{
    auto& list = lists_[Bucket(SizeOf(block))];
    block->sizeAndFlags |= Free;
    StoreLinks(block, {list.tail, nullptr});
    if (list.tail) {
        auto links = LoadLinks(list.tail); links.previous = block; StoreLinks(list.tail, links);
    } else list.head = block;
    list.tail = block;
}
void EngineHeap::RemoveFree(Block* block) noexcept
{
    auto& list = lists_[Bucket(SizeOf(block))];
    auto links = LoadLinks(block);
    if (links.next) {
        auto next = LoadLinks(links.next); next.previous = links.previous; StoreLinks(links.next, next);
    } else list.head = links.previous;
    if (links.previous) {
        auto previous = LoadLinks(links.previous); previous.next = links.next; StoreLinks(links.previous, previous);
    } else list.tail = links.next;
    block->sizeAndFlags &= ~Free;
}
bool EngineHeap::Initialize(std::size_t reserve, std::size_t commit, const char* name) noexcept
{
    if (!region_.Reserve(reserve, commit)) return false;
    name_ = name;
    minimumCommit_ = region_.committed;
    return true;
}
void EngineHeap::Shutdown() noexcept
{
    LockGuard guard(lock_);
    region_.Release();
    for (auto& list : lists_) list = {};
    used_ = allocated_ = allocationCount_ = minimumCommit_ = 0;
    last_ = nullptr;
    name_ = nullptr;
}
bool EngineHeap::Contains(const void* memory) const noexcept { return Inside(region_, memory); }
// Native semantic move of 00aa8f50: search size classes, split a free block,
// otherwise append to the committed end and grow the same reserved arena.
void* EngineHeap::Allocate(std::size_t bytes) noexcept
{
    bytes = AlignedSize(bytes);
    if (!bytes) return nullptr;
    LockGuard guard(lock_);
    Block* chosen = nullptr;
    for (auto bucket = Bucket(bytes); bucket < 1025 && !chosen; ++bucket) {
        for (auto* block = lists_[bucket].tail; block; block = LoadLinks(block).next) {
            const auto size = SizeOf(block);
            if (size >= bytes) { chosen = block; break; }
        }
    }
    if (chosen) {
        const auto available = SizeOf(chosen);
        RemoveFree(chosen);
        // A remainder must contain a full native header AND both free links.
        if (available - bytes >= sizeof(Block) + 2*sizeof(void*)) {
            auto* next = Next(chosen);
            auto* remainder = ::new (reinterpret_cast<std::byte*>(chosen) + sizeof(Block) + bytes)
                Block{chosen, available - bytes - sizeof(Block)};
            if (chosen == last_) last_ = remainder;
            else next->previous = remainder;
            chosen->sizeAndFlags = bytes;
            AddFree(remainder);
        }
    } else {
        const auto total = bytes + sizeof(Block);
        if (!region_.base || total > region_.reserved - used_ || !region_.Commit(used_ + total)) return nullptr;
        chosen = ::new (region_.base + used_) Block{last_, bytes};
        last_ = chosen;
        used_ += total;
    }
    allocated_ += sizeof(Block) + SizeOf(chosen);
    ++allocationCount_;
    return chosen + 1;
}
// 00aa9970: retain predecessor identity and repair the following back link.
void EngineHeap::Coalesce(Block* first, Block* second) noexcept
{
    RemoveFree(first);
    RemoveFree(second);
    first->sizeAndFlags += sizeof(Block) + SizeOf(second);
    if (second == last_) last_ = first;
    else Next(second)->previous = first;
    second->~Block();
    AddFree(first);
}
// Validate exact live payload identity before reading any pointer-derived
// header. Reservation membership alone includes uncommitted and free storage.
EngineHeap::Block* EngineHeap::FindAllocation(const void* memory) noexcept
{
    if (!Contains(memory)) return nullptr;
    for (std::size_t offset = 0; offset < used_;) {
        auto* block = reinterpret_cast<Block*>(region_.base + offset);
        if (block + 1 == memory)
            return block->sizeAndFlags & Free ? nullptr : block;
        offset += sizeof(Block) + SizeOf(block);
    }
    return nullptr;
}
void EngineHeap::Deallocate(void* memory) noexcept
{
    if (!memory) return;
    LockGuard guard(lock_);
    auto* block = FindAllocation(memory);
    if (!block) std::abort();
    allocated_ -= sizeof(Block) + SizeOf(block);
    --allocationCount_;
    AddFree(block);
    while (block->previous && (block->previous->sizeAndFlags & Free)) {
        auto* previous = block->previous;
        Coalesce(previous, block); block = previous;
    }
    while (block != last_ && (Next(block)->sizeAndFlags & Free)) Coalesce(block, Next(block));
    // 00aa9a70: trim consecutive trailing free blocks, then decommit only
    // whole OS pages above both the used end and the source minimum commit.
    while (last_ && (last_->sizeAndFlags & Free)) {
        auto* tail = last_;
        last_ = tail->previous;
        used_ -= sizeof(Block) + SizeOf(tail);
        RemoveFree(tail);
        tail->~Block();
    }
    region_.Trim(std::max(used_, minimumCommit_));
}
std::size_t EngineHeap::Size(const void* memory) noexcept
{
    LockGuard guard(lock_);
    auto* block = FindAllocation(memory);
    return block ? SizeOf(block) : 0;
}
HeapStatistics EngineHeap::Statistics() noexcept
{
    LockGuard guard(lock_);
    return {name_, region_.reserved, region_.committed, used_, allocationCount_, used_ - allocated_};
}
bool EngineHeap::CheckIntegrity() noexcept
{
    LockGuard guard(lock_);
    if (!region_.base) return used_ == 0 && last_ == nullptr;
    std::size_t offset = 0, allocated = 0, freeBlocks = 0, allocations = 0;
    Block* previous = nullptr;
    while (offset < used_) {
        if (used_ - offset < sizeof(Block)) return false;
        auto* block = reinterpret_cast<Block*>(region_.base + offset);
        const auto bytes = SizeOf(block);
        if (block->previous != previous || bytes < 2*sizeof(void*) || bytes%Alignment ||
            bytes > used_ - offset - sizeof(Block)) return false;
        if (block->sizeAndFlags & Free) ++freeBlocks;
        else { allocated += sizeof(Block) + bytes; ++allocations; }
        previous = block;
        offset += sizeof(Block) + bytes;
    }
    if (previous != last_ || allocated != allocated_ || allocations != allocationCount_ ||
        used_ > region_.committed) return false;
    std::size_t listedFreeBlocks = 0;
    for (std::size_t bucket = 0; bucket < 1025; ++bucket) {
        Block* next = nullptr;
        std::size_t visited = 0;
        for (auto* block = lists_[bucket].tail; block; block = LoadLinks(block).next) {
            const auto address = reinterpret_cast<std::uintptr_t>(block);
            const auto base = reinterpret_cast<std::uintptr_t>(region_.base);
            if (++visited > used_/sizeof(Block) || address < base || address - base >= used_ ||
                (address-base)%Alignment || !(block->sizeAndFlags & Free) ||
                Bucket(SizeOf(block)) != bucket || LoadLinks(block).previous != next) return false;
            next = block;
            ++listedFreeBlocks;
        }
        if (next != lists_[bucket].head) return false;
    }
    return listedFreeBlocks == freeBlocks;
}
// Source ResetHeap is a collective operation, not destruction/recreation of
// the owner. Callers must detach all allocations before invoking it.
void EngineHeap::Reset() noexcept
{
    LockGuard guard(lock_);
    for (auto& list : lists_) list = {};
    used_ = allocated_ = allocationCount_ = 0;
    last_ = nullptr;
    region_.Trim(minimumCommit_);
}
bool EngineLinearHeap::Initialize(std::size_t bytes) noexcept
{
    if (!region_.Reserve(bytes, bytes)) return false;
    capacity_ = bytes;
    return true;
}
void EngineLinearHeap::Shutdown() noexcept
{
    LockGuard guard(lock_);
    region_.Release();
    used_ = capacity_ = 0;
}
bool EngineLinearHeap::Contains(const void* memory) const noexcept { return Inside(region_, memory); }
void* EngineLinearHeap::Allocate(std::size_t bytes) noexcept
{
    bytes = AlignedSize(bytes);
    if (!bytes) return nullptr;
    LockGuard guard(lock_);
    if (!region_.base || bytes + Alignment > capacity_ - used_) return nullptr;
    auto* header = region_.base + used_;
    std::memcpy(header, &bytes, sizeof(bytes));
    used_ += Alignment + bytes;
    return header + Alignment;
}
void EngineLinearHeap::Deallocate(void*) noexcept {}
std::size_t EngineLinearHeap::FindAllocation(const void* memory) const noexcept
{
    if (!Contains(memory)) return 0;
    for (std::size_t offset = 0; offset < used_;) {
        std::size_t bytes;
        std::memcpy(&bytes, region_.base + offset, sizeof(bytes));
        if (region_.base + offset + Alignment == memory) return bytes;
        offset += Alignment + bytes;
    }
    return 0;
}
std::size_t EngineLinearHeap::Size(const void* memory) noexcept
{
    LockGuard guard(lock_);
    return FindAllocation(memory);
}
HeapStatistics EngineLinearHeap::Statistics() noexcept
{
    LockGuard guard(lock_);
    std::size_t count = 0;
    for (std::size_t offset = 0; offset < used_; ++count) {
        std::size_t bytes;
        std::memcpy(&bytes, region_.base + offset, sizeof(bytes));
        offset += Alignment + bytes;
    }
    return {"Auxiliary", region_.reserved, region_.committed, used_, count, region_.committed - used_};
}
bool EngineLinearHeap::CheckIntegrity() noexcept
{
    LockGuard guard(lock_);
    std::size_t offset = 0;
    while (offset < used_) {
        if (used_ - offset < Alignment) return false;
        std::size_t bytes;
        std::memcpy(&bytes, region_.base + offset, sizeof(bytes));
        if (bytes%Alignment || bytes > used_ - offset - Alignment) return false;
        offset += Alignment + bytes;
    }
    return used_ <= capacity_ && capacity_ <= region_.committed;
}
void EngineLinearHeap::Reset() noexcept { LockGuard guard(lock_); used_ = 0; }
}
