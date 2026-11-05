#include "havok/hkMemorySystem.h"

#include <algorithm>
#include <cstdlib>
#include <limits>
#include <new>

int hkNativeSolverAllocator::getAllocatedSize(const void*, int bytes)
{
    if (bytes <= 0 || bytes > std::numeric_limits<int>::max() - 15)
        return 0;
    return (bytes + 15) & ~15;
}

hkNativeSolverAllocator::~hkNativeSolverAllocator() { Release(); }

// Retained 0x00d5e8a0 compares against the whole arena, not current free ranges.
bool hkNativeSolverAllocator::canAllocTotal(int bytes)
{
    std::lock_guard lock(mutex);
    return bytes <= capacity;
}

bool hkNativeSolverAllocator::Initialize(int bytes)
{
    std::lock_guard lock(mutex);
    if (start || bytes < 0)
        return false;
    if (!bytes)
        return true;
    int adjusted = bytes;
    void* block = allocator.bufAlloc(adjusted);
    if (!block)
        return false;
    start = static_cast<char*>(block);
    capacity = adjusted;
    return true;
}

void hkNativeSolverAllocator::Release()
{
    std::lock_guard lock(mutex);
    if (liveBlocks)
        std::abort();
    allocator.bufFree(start, capacity);
    start = nullptr;
    capacity = cursor = liveBytes = peakBytes = 0;
    freeRanges = nullptr;
}

// Native range storage replaces the retained allocator's fixed bookkeeping array.
// Best fit, the 0x400 split threshold and adjusted whole-hole allocation follow 0x00d5e9b0.
void* hkNativeSolverAllocator::Allocate(int& bytes, bool adjust)
{
    std::lock_guard lock(mutex);
    int extent = getAllocatedSize(nullptr, bytes);
    if (!start || !extent)
        return nullptr;
    Range** best = nullptr;
    for (Range** link = &freeRanges; *link; link = &(*link)->next)
        if ((*link)->bytes >= extent && (!best || (*link)->bytes < (*best)->bytes))
            best = link;
    void* result;
    if (best)
    {
        Range* range = *best;
        result = range;
        const int remaining = range->bytes - extent;
        const bool split = remaining && (!adjust || (extent > 1024 && remaining > extent / 2));
        if (split)
        {
            Range* next = range->next;
            *best = ::new (static_cast<char*>(result) + extent) Range{next, remaining};
        }
        else
        {
            extent = range->bytes;
            *best = range->next;
        }
    }
    else
    {
        if (extent > capacity - cursor)
            return nullptr;
        result = start + cursor;
        cursor += extent;
    }
    bytes = extent;
    ++liveBlocks;
    liveBytes += extent;
    peakBytes = std::max(peakBytes, liveBytes);
    return result;
}

void* hkNativeSolverAllocator::blockAlloc(int bytes) { return Allocate(bytes, false); }
void* hkNativeSolverAllocator::bufAlloc(int& bytes) { return Allocate(bytes, true); }

// Retained 0x00d5eb10 inserts ordered free ranges, merges neighbours and collapses the bump tail.
void hkNativeSolverAllocator::blockFree(void* block, int bytes)
{
    if (!block)
        return;
    std::lock_guard lock(mutex);
    bytes = getAllocatedSize(block, bytes);
    char* address = static_cast<char*>(block);
    if (!bytes || !start || address < start || address >= start + cursor ||
        bytes > start + cursor - address || !liveBlocks)
        std::abort();
    --liveBlocks;
    liveBytes -= bytes;
    Range** link = &freeRanges;
    Range* previous = nullptr;
    while (*link && reinterpret_cast<char*>(*link) < address)
    {
        previous = *link;
        link = &(*link)->next;
    }
    Range* range;
    if (previous && reinterpret_cast<char*>(previous) + previous->bytes == address)
    {
        range = previous;
        range->bytes += bytes;
    }
    else
    {
        range = ::new (block) Range{*link, bytes};
        *link = range;
    }
    if (range->next && reinterpret_cast<char*>(range) + range->bytes == reinterpret_cast<char*>(range->next))
    {
        range->bytes += range->next->bytes;
        range->next = range->next->next;
    }
    for (Range** tail = &freeRanges; *tail; tail = &(*tail)->next)
        if (reinterpret_cast<char*>(*tail) + (*tail)->bytes == start + cursor)
        {
            cursor = static_cast<int>(reinterpret_cast<char*>(*tail) - start);
            *tail = nullptr;
            break;
        }
}

void hkNativeSolverAllocator::getMemoryStatistics(MemoryStatistics& statistics)
{
    std::lock_guard lock(mutex);
    statistics = {};
    statistics.allocated = capacity;
    statistics.inUse = liveBytes;
    statistics.peakInUse = peakBytes;
    statistics.available = statistics.totalAvailable = capacity - liveBytes;
    statistics.largestBlock = capacity - cursor;
    for (Range* range = freeRanges; range; range = range->next)
        statistics.largestBlock = std::max(statistics.largestBlock, range->bytes);
}
void hkNativeSolverAllocator::resetPeakMemoryStatistics()
{
    std::lock_guard lock(mutex);
    peakBytes = liveBytes;
}
