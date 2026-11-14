#include "havok/hkMemoryRouter.h"

#include <algorithm>
#include <cstring>

hkMemoryAllocator::~hkMemoryAllocator() = default;

void* hkMemoryAllocator::bufAlloc(int& bytes) { return blockAlloc(bytes); }
void hkMemoryAllocator::bufFree(void* block, int bytes) { blockFree(block, bytes); }

// Retained 0x00cbf280 allocates the adjusted extent, copies min(old,new), then frees.
// Native failure leaves the old allocation and the requested extent unchanged.
void* hkMemoryAllocator::bufRealloc(void* old, int oldBytes, int& bytes)
{
    int adjusted = bytes;
    void* block = bufAlloc(adjusted);
    if (!block)
        return nullptr;
    if (old)
        std::memcpy(block, old, std::min(oldBytes, adjusted));
    bufFree(old, oldBytes);
    bytes = adjusted;
    return block;
}

void hkMemoryAllocator::blockAllocBatch(void** blocks, int count, int bytes)
{
    int allocated = 0;
    try
    {
        for (; allocated < count; ++allocated)
            blocks[allocated] = blockAlloc(bytes);
    }
    catch (...)
    {
        blockFreeBatch(blocks, allocated, bytes);
        throw;
    }
}

void hkMemoryAllocator::blockFreeBatch(void** blocks, int count, int bytes)
{
    for (int i = 0; i < count; ++i)
        if (blocks[i])
            blockFree(blocks[i], bytes);
}

bool hkMemoryAllocator::forwardToCanAllocTotal(int bytes) { return canAllocTotal(bytes); }
bool hkMemoryAllocator::canAllocTotal(int) { return true; }
