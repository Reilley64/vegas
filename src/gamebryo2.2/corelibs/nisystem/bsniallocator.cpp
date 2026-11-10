
// src/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstring>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00aa4200_Helper.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/ni_allocator.h"
#include <cstdlib>
#include <limits>

// The recorded bodies write through the manager's result without a null check.
// Native policy, not recovered behaviour: a successful request behaves as
// recorded, including the zero fill; a request the manager refuses, or whose
// size plus alignment does not fit the manager's unsigned entry, returns null
// and writes nothing.
static bool FitsWithAlignment(unsigned int size, unsigned char alignment)
{
    return size <= std::numeric_limits<unsigned int>::max() - alignment;
}

// Aligned blocks keep the distance back to the manager's block in the byte
// before the returned address.
static void* AlignManagerBlock(void* block, unsigned char alignment)
{
    char* memory = static_cast<char*>(block);
    unsigned char offset = alignment - ((alignment - 1) & (unsigned char)(uintptr_t)memory);
    memory += offset;
    memory[-1] = offset;
    return memory;
}

// @fnv 0x00aa24a0
NiAllocator::~NiAllocator()
{}

// @fnv 0x00aa2230
BSNiAllocator::BSNiAllocator()
{}

// Allocates memory (aligned for event 7, otherwise plain) from g_memoryManager, zeroes sizeInBytes bytes, and returns the pointer.
// @fnv 0x00aa2240
void* BSNiAllocator::Allocate(unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                              bool provideAccurateSizeOnDeallocate, const char* file, int line,
                              const char* function)
{
    void* memory;
    if (eventType == 7)
    {
        unsigned int size = sizeInBytes;
        unsigned char byteAlignment = (unsigned char)alignment;
        if (!FitsWithAlignment(size, byteAlignment))
            return nullptr;
        void* block = g_memoryManager.FUN_00aa3e40(size + byteAlignment);
        if (!block)
            return nullptr;
        memory = AlignManagerBlock(block, byteAlignment);
    }
    else
    {
        memory = g_memoryManager.Allocate(sizeInBytes, file, line, function);
        if (!memory)
            return nullptr;
    }
    std::memset(memory, 0, sizeInBytes);
    return memory;
}

// @fnv 0x00aa22b0
void BSNiAllocator::Deallocate(void* memory, int eventType, unsigned int sizeInBytes)
{
    if (eventType == 10)
    {
        if (memory)
        {
            memory = (char*)memory - *((unsigned char*)memory - 1);
            g_memoryManager.FUN_00aa4060(memory);
            return;
        }
    }
    else
    {
        g_memoryManager.FUN_00aa4060(memory);
    }
}

// For event 8, reallocates the aligned block and restores its offset byte; otherwise forwards to FUN_00aa4200.
// @fnv 0x00aa22f0
void* BSNiAllocator::Reallocate(void* memory, unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                                bool provideAccurateSizeOnDeallocate, unsigned int sizeCurrent, const char* file,
                                int line, const char* function)
{
    if (eventType == 8)
    {
        unsigned int size = sizeInBytes;
        unsigned char byteAlignment = (unsigned char)alignment;
        if (memory != 0)
        {
            if (!FitsWithAlignment(size, byteAlignment))
                return nullptr;
            char* base = (char*)memory - ((unsigned char*)memory)[-1];
            void* block = g_memoryManager.Reallocate(base, byteAlignment + size);
            if (!block)
                return nullptr;
            return AlignManagerBlock(block, byteAlignment);
        }
        return 0;
    }
    return reinterpret_cast<::FUN_00aa4200_Helper *>(&::g_memoryManager)->FUN_00aa4200(memory, sizeInBytes, (uintptr_t)(file), line, (uintptr_t)(function));
}

// Allocates memory (aligned for event 0xd, otherwise plain) from g_memoryManager, zeroes sizeInBytes bytes, and returns the pointer.
// @fnv 0x00aa2370
void* BSNiAllocator::Alloc(unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                           bool provideAccurateSizeOnDeallocate, const char* file, int line, const char* function)
{
    void* memory;
    if (eventType == 0xd)
    {
        unsigned int size = sizeInBytes;
        unsigned char byteAlignment = (unsigned char)alignment;
        if (!FitsWithAlignment(size, byteAlignment))
            return nullptr;
        void* block = g_memoryManager.FUN_00aa3e40(size + byteAlignment);
        if (!block)
            return nullptr;
        memory = AlignManagerBlock(block, byteAlignment);
    }
    else
    {
        memory = g_memoryManager.Allocate(sizeInBytes, file, line, function);
        if (!memory)
            return nullptr;
    }
    std::memset(memory, 0, sizeInBytes);
    return memory;
}

// @fnv 0x00aa23e0
void BSNiAllocator::Free(void* memory, int eventType, unsigned int sizeInBytes)
{
    if (eventType == 0x10)
    {
        if (!memory)
            return;
        memory = (char*)memory - *((unsigned char*)memory - 1);
        g_memoryManager.FUN_00aa4060(memory);
        return;
    }
    g_memoryManager.FUN_00aa4060(memory);
}

// @fnv 0x00aa2420
void* BSNiAllocator::Realloc(void* memory, unsigned int& sizeInBytes, unsigned int& alignment, int eventType,
                             bool provideAccurateSizeOnDeallocate, unsigned int sizeCurrent, const char* file,
                             int line, const char* function)
{
    if (eventType == 14)
    {
        unsigned int size = sizeInBytes;
        unsigned char byteAlignment = (unsigned char)alignment;
        if (memory)
        {
            if (!FitsWithAlignment(size, byteAlignment))
                return nullptr;
            char* base = (char*)memory - ((unsigned char*)memory)[-1];
            void* block = g_memoryManager.Reallocate(base, byteAlignment + size);
            if (!block)
                return nullptr;
            return AlignManagerBlock(block, byteAlignment);
        }
        return 0;
    }
    return reinterpret_cast<::FUN_00aa4200_Helper *>(&::g_memoryManager)->FUN_00aa4200(memory, sizeInBytes, (uintptr_t)(file), line, (uintptr_t)(function));
}

// No body is identified for slots 7 and 8 of this class: its unit has no room
// for one between 0x00aa2230 and 0x00aa24d0, and its table is not in the
// generated data. The object has no state and every other slot forwards to the
// already started g_memoryManager, so these do nothing. That is native policy,
// not recovered behaviour.
void BSNiAllocator::Initialize()
{}

void BSNiAllocator::Shutdown()
{}

// @fnv 0x00aa4200
void* FUN_00aa4200_Helper::FUN_00aa4200(void* old, unsigned int size, uintptr_t a, unsigned int b, uintptr_t c)
{
    void* result2 = 0;
    unsigned int oldSize;
    oldSize = ((MemoryManager*)this)->Size(old);
    if (oldSize)
    {
        result2 = reinterpret_cast<::MemoryManagerStandIn *>((((MemoryManager*)this)))->FUN_00aa3e40(size);
        if (oldSize > size)
            oldSize = size;
        std::memmove(result2, old, oldSize);
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)this)))->FUN_00aa4060(old);
    }
    else
    {
        void* tmp = old;
        tmp = std::realloc(tmp, size);
        result2 = tmp;
    }
    return result2;
}
