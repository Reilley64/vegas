
// src/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nisystem/bsniallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstring>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00aa4200_Helper.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
#include <cstdlib>
struct MM
{
};
struct BSNiAllocator
{
    void FUN_00aa22b0(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes);
};
// @fnv 0x00aa22b0
void BSNiAllocator::FUN_00aa22b0(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes)
{
    if (aiAllocationType == 10)
    {
        if (pvMemory)
        {
            pvMemory = (char*)pvMemory - *((unsigned char*)pvMemory - 1);
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(pvMemory);
            return;
        }
    }
    else
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MM *>(&::g_memoryManager))))->FUN_00aa4060(pvMemory);
    }
}

namespace fnv_00aa23e0 {
struct MemoryManager
{
};
// @fnv 0x00aa23e0
void FUN_00aa23e0(void* pvMemory, int aiAllocationType, unsigned int stSizeInBytes)
{
    if (aiAllocationType == 0x10)
    {
        if (!pvMemory)
            return;
        pvMemory = (char*)pvMemory - *((unsigned char*)pvMemory - 1);
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00aa23e0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(pvMemory);
        return;
    }
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00aa23e0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(pvMemory);
}
}  // namespace fnv_00aa23e0

namespace fnv_00aa24a0 {
struct MemoryManager
{
};
extern int DAT_010a24d0;
struct BSNiAllocator
{
    void* Destroy(unsigned int);
};
// Sets the vtable pointer to DAT_010a24d0 and, when bit 0 of flags is set, deallocates this via g_memoryManager, then returns this.
// @fnv 0x00aa24a0
void* BSNiAllocator::Destroy(unsigned int flags)
{
    *(void**)this = (void*)&DAT_010a24d0;
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00aa24a0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00aa24a0

struct SpawnHeap_cls
{
};


// For eType 8, reallocates pBlock with extra *pAdjust bytes and fixes the header offset; otherwise forwards to FUN_00aa4200.
// @fnv 0x00aa22f0
char* ResizeHeapBlock(char* pBlock, int* pSize, unsigned char* pAdjust, int eType, int a5, int a6, int a7,
                                int a8, int a9)
{
    SpawnHeap_cls* heap = reinterpret_cast<SpawnHeap_cls*>(&(*reinterpret_cast<::MM *>(&::g_memoryManager)));
    if (eType == 8)
    {
        int sz = *pSize;
        unsigned char ucAdjust = *pAdjust;
        if (pBlock != 0)
        {
            unsigned char ucHeader = (unsigned char)pBlock[-1];
            char* base = pBlock - ucHeader;
            char* r = ((char *)(reinterpret_cast<::MemoryManager *>((heap))->Reallocate(base, ucAdjust + sz)));
            unsigned char adj = ucAdjust - (unsigned char)((ucAdjust - 1) & (unsigned char)(uintptr_t)r);
            r += adj;
            r[-1] = (char)adj;
            return r;
        }
        return 0;
    }
    return ((char *)(reinterpret_cast<::FUN_00aa4200_Helper *>((heap))->FUN_00aa4200(pBlock, *pSize, a7, a8, a9)));
}

struct NiAllocGlobal
{
    int unk00;
};



// @fnv 0x00aa2370
uintptr_t AllocateAlignedBuffer(unsigned int* puiSize, unsigned char* pucAlignByte, int aiAlignMode,
                                             int aiUnused, intptr_t a5, int a6, intptr_t a7)
{
    uintptr_t r;
    if (aiAlignMode == 0xd)
    {
        unsigned int uiSize = *puiSize;
        unsigned char ucAlignByte = *pucAlignByte;
        uintptr_t base = ((uintptr_t)(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::NiAllocGlobal *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize + ucAlignByte)));
        unsigned char adj = (unsigned char)(ucAlignByte - ((ucAlignByte - 1) & (unsigned char)base));
        *(unsigned char*)(base + adj - 1) = adj;
        r = base + adj;
    }
    else
    {
        r = ((uintptr_t)(reinterpret_cast<::MemoryManager *>(&((*reinterpret_cast<::NiAllocGlobal *>(&::g_memoryManager))))->Allocate(*puiSize, (const char *)(a5), a6, (const char *)(a7))));
    }
    std::memset((void *)(r), 0, *puiSize);
    return r;
}


class MemoryManagerAA2
{
  public:
};


enum NiMemEventTypeAA2
{
    NI_UNKNOWN,
    NI_OPER_NEW,
    NI_OPER_NEW_ARRAY,
    NI_OPER_DELETE,
    NI_OPER_DELETE_ARRAY,
    NI_MALLOC,
    NI_REALLOC,
    NI_ALIGNEDMALLOC
};

// Allocates memory (aligned or plain) via g_kMemoryManagerAA2, zeroes stSizeInBytes bytes, and returns the pointer.
// @fnv 0x00aa2240
void* AllocateZeroedMemory(unsigned int& stSizeInBytes, unsigned int& stAlignment,
                                     NiMemEventTypeAA2 eMemEventType, bool bProvideAccurateSizeOnDeallocate,
                                     const char* pcFile, int iLine, const char* pcFunction)
{
    void* pvMem;
    if (eMemEventType == NI_ALIGNEDMALLOC)
    {
        unsigned int stSize = stSizeInBytes;
        unsigned char ucAlignment = (unsigned char)stAlignment;
        char* pcMem = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::MemoryManagerAA2 *>(&::g_memoryManager))))->FUN_00aa3e40(stSize + ucAlignment);
        unsigned char ucOffset = ucAlignment - ((ucAlignment - 1) & (unsigned char)(uintptr_t)pcMem);
        pcMem += ucOffset;
        pcMem[-1] = ucOffset;
        pvMem = pcMem;
    }
    else
    {
        pvMem = reinterpret_cast<::MemoryManager *>(&((*reinterpret_cast<::MemoryManagerAA2 *>(&::g_memoryManager))))->Allocate(stSizeInBytes, pcFile, iLine, pcFunction);
    }
    std::memset(pvMem, 0, stSizeInBytes);
    return pvMem;
}

class BAA2420MemoryManager
{
  public:
};


// @fnv 0x00aa2420
void* FUN_00aa2420(void* pvMem, unsigned int& uiSize, unsigned char& ucAlignment, int aiAllocationType,
                             bool bProvideSize, unsigned int uiCurrentSize, const char* pcFile, int iLine,
                             const char* pcFunction)
{
    if (aiAllocationType == 14)
    {
        unsigned int uiNewSize = uiSize;
        unsigned char ucAlign = ucAlignment;
        if (pvMem)
        {
            char* pcBase = (char*)pvMem - ((unsigned char*)pvMem)[-1];
            char* pcNew = (char*)reinterpret_cast<::MemoryManager *>(&((*reinterpret_cast<::BAA2420MemoryManager *>(&::g_memoryManager))))->Reallocate(pcBase, ucAlign + uiNewSize);
            unsigned char ucOffset = ucAlign - ((ucAlign - 1) & (unsigned char)(uintptr_t)pcNew);
            pcNew += ucOffset;
            pcNew[-1] = ucOffset;
            return pcNew;
        }
        return 0;
    }
    return reinterpret_cast<::FUN_00aa4200_Helper *>(&((*reinterpret_cast<::BAA2420MemoryManager *>(&::g_memoryManager))))->FUN_00aa4200(pvMem, uiSize, (uintptr_t)(pcFile), iLine, (uintptr_t)(pcFunction));
}



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
