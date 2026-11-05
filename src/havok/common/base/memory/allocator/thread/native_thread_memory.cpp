#include "havok/hkMemorySystem.h"

#include <algorithm>
#include <cstdlib>

int hkNativeThreadMemory::SizeClass(int bytes)
{
    int index = 1;
    while (index < 16 && bytes > sizes[index])
        ++index;
    return index;
}

hkNativeThreadMemory::~hkNativeThreadMemory()
{
    if (allocator)
        std::abort();
}

void hkNativeThreadMemory::Attach(hkSystemMemoryAllocator& backing)
{
    if (allocator)
        std::abort();
    allocator = &backing;
}

// Retained 0x00d2c3c0/0x00d2c5a0 refill at most four blocks and cache the rest.
void* hkNativeThreadMemory::blockAlloc(int bytes)
{
    if (!allocator || bytes <= 0)
        return nullptr;
    void* result;
    if (bytes > 8192)
        result = allocator->blockAlloc(bytes);
    else
    {
        const int index = SizeClass(bytes);
        Cache& cache = caches[index];
        if (cache.head)
        {
            result = cache.head;
            cache.head = cache.head->next;
            --cache.count;
        }
        else
        {
            void* blocks[4]{};
            allocator->blockAllocBatch(blocks, 4, sizes[index]);
            result = blocks[0];
            for (int i = 1; i < 4; ++i)
                if (blocks[i])
                {
                    auto* node = static_cast<Node*>(blocks[i]);
                    node->next = cache.head;
                    cache.head = node;
                    ++cache.count;
                }
        }
    }
    if (result)
        allocator->ClaimAllocation(result, liveBlocks);
    return result;
}

// Retained 0x00d2c450/0x00d2c600 trim to half of the eight-block cache limit.
void hkNativeThreadMemory::blockFree(void* block, int bytes)
{
    if (!block)
        return;
    if (!allocator || bytes <= 0)
        std::abort();
    // Cache residency is independent of the cache supplying an external block.
    allocator->RelinquishAllocation(block);
    const int extent = allocator->getAllocatedSize(block, bytes);
    const int index = SizeClass(bytes);
    // A direct shared-heap block can be smaller than this cache's size class.
    // Return it to that heap rather than exposing a larger extent on reuse.
    if (bytes > 8192 || extent != sizes[index])
    {
        allocator->blockFree(block, extent);
        return;
    }
    Cache& cache = caches[index];
    if (cache.count >= 8)
        while (cache.count > 4)
        {
            void* batch[4];
            const int count = std::min(4, cache.count - 4);
            for (int i = 0; i < count; ++i)
            {
                batch[i] = cache.head;
                cache.head = cache.head->next;
                --cache.count;
            }
            allocator->blockFreeBatch(batch, count, sizes[index]);
        }
    auto* node = static_cast<Node*>(block);
    node->next = cache.head;
    cache.head = node;
    ++cache.count;
}

void* hkNativeThreadMemory::bufAlloc(int& bytes)
{
    void* result = blockAlloc(bytes);
    if (result && bytes <= 8192)
        bytes = sizes[SizeClass(bytes)];
    return result;
}

int hkNativeThreadMemory::getAllocatedSize(const void* block, int bytes)
{
    if (block)
        return allocator->getAllocatedSize(block, bytes);
    return bytes > 0 && bytes <= 8192 ? sizes[SizeClass(bytes)] : bytes;
}

// Retained 0x00d2c520/0x00d2c7a0 drain all 17 caches in reverse order.
void hkNativeThreadMemory::Release()
{
    if (!allocator)
        return;
    if (HasLiveAllocations())
        std::abort();
    for (int index = 16; index >= 0; --index)
    {
        Cache& cache = caches[index];
        while (cache.head)
        {
            void* blocks[4];
            int count = 0;
            while (count < 4 && cache.head)
            {
                blocks[count++] = cache.head;
                cache.head = cache.head->next;
                --cache.count;
            }
            allocator->blockFreeBatch(blocks, count, sizes[index]);
        }
    }
    allocator = nullptr;
}

void hkNativeThreadMemory::getMemoryStatistics(MemoryStatistics& statistics)
{
    statistics = {};
    for (int i = 1; i < 17; ++i)
        statistics.available += caches[i].count * sizes[i];
    statistics.totalAvailable = statistics.available;
}
void hkNativeThreadMemory::resetPeakMemoryStatistics() {}
