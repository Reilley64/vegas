#include "havok/hkMemorySystem.h"

#include <algorithm>
#include <cstdlib>
#include <limits>
#include <new>
#include <utility>

namespace
{
// Native ownership metadata, not an original-release block layout.
struct alignas(16) AllocationHeader
{
    std::atomic<std::size_t>* owner = nullptr;
    int payloadBytes;
};

// The legacy interface saturates; internal totals remain exact across frees/resets.
int LegacyByteCount(std::size_t bytes)
{
    return static_cast<int>(std::min(bytes, static_cast<std::size_t>(std::numeric_limits<int>::max())));
}
}

hkSystemMemoryAllocator::~hkSystemMemoryAllocator()
{
    if (liveBlocks)
        std::abort();
}

// Retained free-list 0x00d5fca0 uses 16-byte classes through 0x280.
// The native system backend owns each block; no original page layout is assumed.
int hkSystemMemoryAllocator::getAllocatedSize(const void* block, int bytes)
{
    if (block)
        return (static_cast<const AllocationHeader*>(block) - 1)->payloadBytes;
    return bytes > 0 && bytes <= 640 ? (bytes + 15) & ~15 : bytes;
}

void* hkSystemMemoryAllocator::blockAlloc(int bytes)
{
    if (bytes <= 0)
        return nullptr;
    bytes = getAllocatedSize(nullptr, bytes);
    const auto payloadBytes = static_cast<std::size_t>(bytes);
    if (payloadBytes > std::numeric_limits<std::size_t>::max() - sizeof(AllocationHeader))
        return nullptr;
    void* storage = backing.Allocate(payloadBytes + sizeof(AllocationHeader));
    if (!storage)
        return nullptr;
    auto* header = ::new (storage) AllocationHeader{nullptr, bytes};
    std::lock_guard lock(mutex);
    ++liveBlocks;
    liveBytes += payloadBytes;
    peakBytes = std::max(peakBytes, liveBytes);
    return header + 1;
}

void hkSystemMemoryAllocator::blockFree(void* block, int bytes)
{
    if (!block)
        return;
    bytes = getAllocatedSize(block, bytes);
    RelinquishAllocation(block);
    auto* header = static_cast<AllocationHeader*>(block) - 1;
    header->~AllocationHeader();
    backing.Free(header, static_cast<std::size_t>(bytes) + sizeof(AllocationHeader));
    std::lock_guard lock(mutex);
    --liveBlocks;
    liveBytes -= bytes;
}

void hkSystemMemoryAllocator::ClaimAllocation(void* block, std::atomic<std::size_t>& owner)
{
    if (!block)
        return;
    auto* header = static_cast<AllocationHeader*>(block) - 1;
    if (header->owner)
        std::abort();
    header->owner = &owner;
    owner.fetch_add(1, std::memory_order_relaxed);
}

void hkSystemMemoryAllocator::RelinquishAllocation(void* block)
{
    if (!block)
        return;
    auto* header = static_cast<AllocationHeader*>(block) - 1;
    if (auto* owner = std::exchange(header->owner, nullptr))
        owner->fetch_sub(1, std::memory_order_release);
}

void* hkSystemMemoryAllocator::bufAlloc(int& bytes)
{
    void* block = blockAlloc(bytes);
    if (block)
        bytes = getAllocatedSize(block, bytes);
    return block;
}

void hkSystemMemoryAllocator::getMemoryStatistics(MemoryStatistics& statistics)
{
    std::lock_guard lock(mutex);
    statistics = {};
    statistics.allocated = statistics.inUse = LegacyByteCount(liveBytes);
    statistics.peakInUse = LegacyByteCount(peakBytes);
}

void hkSystemMemoryAllocator::resetPeakMemoryStatistics()
{
    std::lock_guard lock(mutex);
    peakBytes = liveBytes;
}
