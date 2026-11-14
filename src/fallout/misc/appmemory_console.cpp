// Heap-owned startup portion of the canonical native MemoryManager.
#include "fnv/decl/MemoryManager.h"
#include <new>

// @fnv 0x00866e00
void MemoryManager::InitializeHeaps()
{
    if (!heaps_.Initialize())
        throw std::bad_alloc();
}

#include "generated/data/fallout/misc/appmemory_console.inc"
