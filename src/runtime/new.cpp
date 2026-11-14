#include "fnv/symbols_00401000.h"

#include <cstddef>
#include <new>
#include <limits>

// The replaceable global allocation functions. The original release's
// operator new and operator delete (0x00401000, 0x00401030) take memory from
// the game's MemoryManager, and so do new and delete expressions for game
// objects, the standard library and the array and sized forms here. Gamebryo's
// NiMemObject allocations reach the same MemoryManager through BSNiAllocator,
// so a block is always freed into the heap it came from.

void* operator new(std::size_t size)
{
    // The legacy entry has an unsigned-size contract. Never truncate a native
    // new-expression before crossing that boundary (including new[]).
    if (size > std::numeric_limits<unsigned int>::max())
        throw std::bad_alloc();
    void* memory = FUN_00401000(static_cast<unsigned int>(size ? size : 1));
    if (memory == nullptr)
        throw std::bad_alloc();
    return memory;
}

void* operator new[](std::size_t size)
{
    return ::operator new(size);
}

void operator delete(void* memory) noexcept
{
    FUN_00401030(memory);
}

void operator delete[](void* memory) noexcept
{
    FUN_00401030(memory);
}

void operator delete(void* memory, std::size_t) noexcept
{
    FUN_00401030(memory);
}

void operator delete[](void* memory, std::size_t) noexcept
{
    FUN_00401030(memory);
}
