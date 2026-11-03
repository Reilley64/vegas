// bscore/memorymanager.cpp: MemoryManager, TESQuest, TESActorBaseData, Actor and more (21 functions)

#include <windows.h>
#include <cstring>
#include "fnv/decl/AA4610Allocator.h"
#include "fnv/decl/AE91F0Map.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00aa45a0_Class.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/RecursiveLock.h"
#include "fnv/decl/S_00adc830_Map.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/fnv_00404f70__FUN_00404f70_shell.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00aa7000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01272000.h"
#include "memorymanager_identity.h"
#include "memorymanager_memory.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// @fnv 0x00aa4150
void* MemoryManager::Reallocate(void* apBlock, unsigned int size)
{
    void* allocation = 0;
    unsigned int copySize = Size(apBlock);
    if (copySize)
    {
        allocation = reinterpret_cast<::MemoryManagerStandIn *>(this)->FUN_00aa3e40(size);
        if (copySize > size)
            copySize = size;
        memmove(allocation, apBlock, copySize);
        reinterpret_cast<::FNV_MemoryManager *>(this)->FUN_00aa4060(apBlock);
    }
    else
    {
        void* resized = apBlock;
        resized = realloc(resized, size);
        allocation = resized;
    }
    return allocation;
}

// Returns the allocation size of a pointer by checking the owning MemoryPool, then the heap for the pointer or its physical address, falling back to _msize.
// @fnv 0x00aa44c0
unsigned int MemoryManager::Size(const void* pointer)
{
    unsigned int size;
    MemoryPool* pool = MemoryPool::ms_pPoolAddressMap[reinterpret_cast<size_t>(pointer) >> kPoolAddressRegionShift];
    if (pool && pool->PointerInPool(pointer))
        size = pool->GetBlockSize();
    else
    {
        IMemoryHeap* heap = ((::IMemoryHeap *)(reinterpret_cast<::FUN_00aa45a0_Class *>(this)->FindItemByArg((int)(pointer))));
        if (heap)
            size = heap->Size(pointer, 0);
        else
        {
            heap = ((::IMemoryHeap *)(reinterpret_cast<::AA4610Allocator *>(this)->FindPoolContaining((void *)(pointer))));
            if (heap)
                size = heap->Size(pointer, 0);
            else
            {
                unsigned int systemSize = 0;
                systemSize = _msize(const_cast<void*>(pointer));
                size = systemSize;
            }
        }
    }
    return size;
}

// @fnv 0x005f5760
PerkEntryConditionSet* TESQuest::GetConditions()
{
    return reinterpret_cast<PerkEntryConditionSet*>(reinterpret_cast<unsigned char*>(this) + 0x54);
}

// @fnv 0x00461580
bool TESActorBaseData::GetFlag(unsigned int flag) const
{
    return m_uiActorFlags & flag;
}

// @fnv 0x0087f4c0
SEX Actor::GetSex()
{
    return GetActorBase()->GetSex();
}

// Sets the ExtraHealth extra data value to health, creating and adding a new ExtraHealth if none exists.
// @fnv 0x00419970
void ExtraDataList::SetExtraHealth(float health)
{
    ExtraHealth* extra = static_cast<ExtraHealth*>(reinterpret_cast<::fnv_00410220::FUN_00410220_shell *>(this)->FUN_00410220(0x25));
    if (extra)
        extra->fHealthPercent = health;
    else
    {
        extra = new ExtraHealth(health);
        reinterpret_cast<::fnv_0040ff60::FUN_0040ff60_shell *>(this)->FUN_0040ff60(extra);
    }
}

// @fnv 0x0042f5d0
void* Reallocate(void* pointer, unsigned int size)
{
    return FUN_00401020()->Reallocate(pointer, size);
}

// Looks up the scrap heap for the current thread ID, creating and storing a new one if none exists, and returns it.
// @fnv 0x00aa42e0
ScrapHeapBuffer* MemoryManager::GetGeneralAllocator()
{
    unsigned long threadID = GetCurrentThreadId();
    ScrapHeapBuffer* heap = 0;
    reinterpret_cast<::S_00adc830_Map *>(&(threadScrapHeaps))->GetAt(threadID, (::S_00adc830_Entry *&)(heap));
    if (!heap)
    {
        heap = new ScrapHeapBuffer;
        threadScrapHeaps.SetAt(threadID, heap);
    }
    return heap;
}

struct FUN_00473960_shell : public TESFile
{
    void FUN_00473960();
};

void __cdecl Deallocate(void*);

// If the pointer at offset 0x420 is non-null, deallocates it and clears the pointer and the count at offset 0x424.
// @fnv 0x00473960
void FUN_00473960_shell::FUN_00473960()
{
    if (*(void**)&this->m_pDecompressedFormBuffer != 0)
    {
        ::FUN_00401030(*(void**)&this->m_pDecompressedFormBuffer);
        *(void**)&this->m_pDecompressedFormBuffer = 0;
        this->m_uiAuxBufferSize = 0;
    }
}

struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
struct FUN_00aa3cc0_shell : public MemoryManager
{
    void CreateMemoryPool(unsigned int, unsigned int, char*);
};

struct MemCtxGuard
{
    int iOld;
    static int GetCtx()
    {
        return (*reinterpret_cast<int *>(&::currentAllocationContext));
    }
    static void SetCtx(int c)
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = c;
    }
    MemCtxGuard(int c)
    {
        iOld = GetCtx();
        SetCtx(c);
    }
    ~MemCtxGuard()
    {
        SetCtx(iOld);
    }
};
struct MemoryPoolView : public MemoryPool
{
    bool HasMemory()
    {
        return *(void**)((char*)this + 4) != 0;
    }
};
// Creates a MemoryPool with the given block and pool sizes and description, deleting it if it has no memory; returns early when aiBlockSize is below 8.
// @fnv 0x00aa3cc0
void FUN_00aa3cc0_shell::CreateMemoryPool(unsigned int aiBlockSize, unsigned int aiPoolSize, char* apDesc)
{
    MemCtxGuard tempMemContext(3);
    if (aiBlockSize < 8)
        return;
    m_bPoolAllocationEnabled = false;
    MemoryPool* pnewPool = new MemoryPool(aiBlockSize, aiPoolSize, apDesc);
    if (!static_cast<MemoryPoolView*>(pnewPool)->HasMemory())
    {
        delete pnewPool;
    }
    m_bPoolAllocationEnabled = true;
}

struct FUN_00aa3a10_shell
{
    void ClearFlagAndSetByte();
};

struct FUN_00aa3a10_tls_struct
{
    unsigned char pad[0x2b4];
    unsigned int flag;
};

__declspec(thread) FUN_00aa3a10_tls_struct g_fun_tls;

// Clears the TLS flag and sets the first byte of this object to 1.
// @fnv 0x00aa3a10
void FUN_00aa3a10_shell::ClearFlagAndSetByte()
{
    (*reinterpret_cast<::FUN_00aa3a10_tls_struct *>(&::g_tlsBlock)).flag = 0;
    *(unsigned char*)this = 1;
}

struct _RTL_CRITICAL_SECTION;
extern _RTL_CRITICAL_SECTION DAT_011f6234;
// @fnv 0x00aa4460
void FUN_00aa4460()
{
    InterlockedIncrement(&DAT_011f6234);
}

struct _RTL_CRITICAL_SECTION;
extern _RTL_CRITICAL_SECTION DAT_011f6234;
// @fnv 0x00aa4470
void FUN_00aa4470()
{
    InterlockedDecrement(&DAT_011f6234);
}

extern char DAT_011f6230;

// @fnv 0x00aa4480
void FUN_00aa4480(unsigned char value)
{
    DAT_011f6230 = value;
}

namespace fnv_00aa4490 {
extern unsigned int DAT_011f6234;

// @fnv 0x00aa4490
bool FUN_00aa4490()
{
    if (DAT_011f6234 > 0)
        return true;
    return false;
}
}  // namespace fnv_00aa4490

extern char DAT_011f6230;

// @fnv 0x00aa44b0
char __cdecl FUN_00aa44b0()
{
    return DAT_011f6230;
}

struct FUN_00aa46a0_holder
{
    char pad0[2];
    unsigned short countA;
    unsigned short countB;
    char pad1[2];
    void** tableA;
    char pad2[0x118];
    void** tableB;
    void* GetEntryAt(unsigned int index);
};

// Returns the entry at index from tableA if index < countA, otherwise from tableB at index - countA when that offset is < countB; returns 0 otherwise.
// @fnv 0x00aa46a0
void* FUN_00aa46a0_holder::GetEntryAt(unsigned int index)
{
    void* pEntry = 0;
    if (index < countA)
    {
        pEntry = tableA[index];
    }
    else if (index - countA < countB)
    {
        pEntry = tableB[index - countA];
    }
    return pEntry;
}

struct FUN_00aa39c0_tls
{
    unsigned char unk0000[0x2b4];
    unsigned int m_2b4;
};

void ClearMemoryPoolTables();

class FUN_00aa39c0_cls
{
  public:
    unsigned char m_00;
    void FUN_00aa39c0();
};

// Calls ClearMemoryPoolTables, InitializeHeaps, FUN_00866770 and FUN_00483710, sets m_00 to 1 and clears g_tls.m_2b4.
// @fnv 0x00aa39c0
void FUN_00aa39c0_cls::FUN_00aa39c0()
{
    ClearMemoryPoolTables();
    reinterpret_cast<::MemoryManager *>(this)->InitializeHeaps();
    m_00 = 1;
    reinterpret_cast<::MemoryManager *>(this)->FUN_00866770();
    reinterpret_cast<::TESForm *>(this)->ClearData();
    (*reinterpret_cast<::FUN_00aa39c0_tls *>(&::g_tlsBlock)).m_2b4 = 0;
}

extern FUN_00aa46a0_holder DAT_011f6238;
extern unsigned short DAT_011f623a;
extern unsigned short DAT_011f623c;
struct S_00aa4400_Obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
};
inline int S_Sum(int a, int b)
{
    return a + b;
}
inline int S_Sum(unsigned short a, unsigned short b)
{
    return a + b;
}
// Sums DAT_011f623a and DAT_011f623c, then for each index up to that sum fetches an object from DAT_011f6238 and calls its v0b virtual method.
// @fnv 0x00aa4400
void CallVirtualOnEachElement()
{
    int iTotal = S_Sum(DAT_011f623a, DAT_011f623c);
    S_00aa4400_Obj* pElement;
    for (int i = 0; i < iTotal; i++)
    {
        pElement = (S_00aa4400_Obj*)DAT_011f6238.GetEntryAt(i);
        pElement->v0b();
    }
}

__forceinline void operator delete[](void* p)
{
    reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(p);
}
struct ScrapView
{
    ~ScrapView();
    static __forceinline void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(p);
    }
};
struct HeapView
{
    virtual ~HeapView();
};
struct WeightedMapNode
{
    WeightedMapNode* unk00;
};
struct MapView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(WeightedMapNode*);
    virtual void slot5();
    virtual void slot6(WeightedMapNode*);
    unsigned int unk04;
    WeightedMapNode** unk08;
    void* unk0C;
    ~MapView();
    __forceinline WeightedMapNode* First()
    {
        for (unsigned int i = 0; i < unk04; ++i)
        {
            if (unk08[i])
                return unk08[i];
        }
        return 0;
    }
    inline void ClearAll()
    {
        for (unsigned int bucket = 0; bucket < unk04; ++bucket)
        {
            while (unk08[bucket])
            {
                WeightedMapNode* node = unk08[bucket];
                unk08[bucket] = unk08[bucket]->unk00;
                slot4(node);
                slot6(node);
            }
        }
        unk0C = 0;
    }
};
inline void FreeArray(void* p)
{
    reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(p);
}
struct FUN_00aa5950_s
{
    ~FUN_00aa5950_s();
    static __forceinline void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(p);
    }
};
extern FUN_00aa5950_s* DAT_011f63b4;
inline void FUN_00aa5950()
{
    delete DAT_011f63b4;
    DAT_011f63b4 = 0;
}
struct PoolView
{
    ~PoolView();
    static __forceinline void operator delete(void* p)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&(g_memoryManager))->FUN_00aa4060(p);
    }
};
extern PoolView* DAT_011f67b8[256];
inline void DestroyMemoryPools()
{
    for (unsigned int i = 0; i < 256; ++i)
    {
        delete DAT_011f67b8[i];
        DAT_011f67b8[i] = 0;
    }
}
struct FUN_00aa3a40
{
    bool unk00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    HeapView** unk08;
    void* unk0C[66];
    MapView unk114;
    HeapView** unk124;
    ~FUN_00aa3a40();
};
// @fnv 0x00aa3a40
FUN_00aa3a40::~FUN_00aa3a40()
{
    WeightedMapNode* position = unk114.First();
    unsigned long key;
    ScrapView* heap;
    while (position)
    {
        reinterpret_cast<::RecursiveLock *>(&(unk114))->Unlock((::BSCriticalSectionEntry **)&(position), (unsigned int *)&(key), (unsigned int *)&(heap));
        delete heap;
    }
    reinterpret_cast<::AE91F0Map *>(&(unk114))->ClearAll();
    FUN_00aa5950();
    reinterpret_cast<::TESForm *>(this)->ClearData();
    DestroyMemoryPools();
    std::memset(unk0C, 0, 0x108);
    unk00 = false;
    if (unk08)
    {
        for (unsigned short i = 0; i < unk02; ++i)
        {
            delete unk08[i];
            unk08[i] = 0;
        }
        delete[] unk08;
    }
    if (unk124)
    {
        for (unsigned short j = 0; j < unk04; ++j)
        {
            delete unk124[j];
            unk124[j] = 0;
        }
        delete[] unk124;
    }
}

namespace fnv_00aa43a0 {

class ItemAA43
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void Update();
};

class FUN_00aa46a0_holder
{
  public:
    short unk00;
    unsigned short m_count2;
    unsigned short m_count4;

    int GetCount()
    {
        return m_count2 + m_count4;
    }
    void FUN_00aa43a0(int unused);
};

// Calls FUN_00aa7370, then iterates over all entries and calls Update on each ItemAA43.
// @fnv 0x00aa43a0
void FUN_00aa46a0_holder::FUN_00aa43a0(int unused)
{
    ::FUN_00aa7370();
    ItemAA43* pkItem;
    int ItemUpdateArray = GetCount();
    for (int i = 0; i < ItemUpdateArray; i++)
    {
        pkItem = (ItemAA43*)reinterpret_cast<::FUN_00aa46a0_holder *>(this)->GetEntryAt(i);
        pkItem->Update();
    }
}
}  // namespace fnv_00aa43a0
