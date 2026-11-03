
// src/havok/common/base/thread/jobqueue/hkjobqueue.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/jobqueue/hkjobqueue.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include <new>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/fnv_00d04b50__Owner.h"
#include "fnv/decl/fnv_00d057f0__ItemPool.h"
#include "fnv/symbols_00d2c000.h"
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/ArrayRecord.h"
#include "fnv/decl/CBF490Lists.h"
#include "fnv/decl/FUN_00d04370_cls.h"
#include "fnv/decl/FUN_00d04390.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb1000.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_00d01000.h"
#include "fnv/symbols_00d04000.h"
#include "fnv/symbols_00d88000.h"
#include "fnv/symbols_00d96000.h"
#include "fnv/symbols_00da3000.h"
#include "fnv/symbols_00e2a000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_01268000.h"
struct FUNObj
{
    struct Entry
    {
        int first;
        int second;
        int third;
        int fourth;
    };
    Entry entries[15];
    void SetEntry(int index, int first, int second, int third, int fourth);
};

// Writes the four given values into the entry at index + 15 of the entries array.
// @fnv 0x00d044c0
void FUNObj::SetEntry(int index, int first, int second, int third, int fourth)
{
    Entry& entry = entries[index + 15];
    entry.first = first;
    entry.second = second;
    entry.third = third;
    entry.fourth = fourth;
}


struct UnsignedShortCountBlock
{
    unsigned short unk00;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
    unsigned short unk10;
    unsigned short unk12;
    unsigned short unk14;
    unsigned short unk16;
    unsigned short unk18;
    unsigned short unk1A;
    unsigned short unk1C;
    unsigned short unk1E;
    unsigned short unk20;
    unsigned short counts[5];
};

struct ItemManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    void* values[5];
    int count;
    void RemoveItemReference(int index, UnsignedShortCountBlock* refs);
};

struct Bucket
{
    intptr_t unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct Registry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    Bucket buckets[1];
};
__declspec(align(16)) struct RequestContext
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
};
struct Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    intptr_t unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int count;
    void FUN_00d04a80(int, int);
};
struct Item
{
    int data[32];
};

struct ItemPool
{
    Item* m_items;
    int m_pRayCursor;
    int m_free;
    int m_unk0c;
    int m_uiItemCount;

    void Insert(const Item& item);
};

struct PoolSet
{
    char m_auiShapeKeys[0x2c];
    ItemPool m_pools[1];
};

struct Mgr
{
    void InsertItemAndNotify(PoolSet* set, const Item& item, int flag);
};

struct Obj
{
    int ForwardWithZero(intptr_t a, int b);
};

struct S_00d056a0_Allocator
{
    virtual void v0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct S_00d056a0_Router
{
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
    S_00d056a0_Allocator* m_pStreamAllocator;
    S_00d056a0_Allocator* heap()
    {
        return m_pStreamAllocator;
    }
};


struct S_00d056a0_Elem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
};

struct S_00d056a0
{
    S_00d056a0_Elem* m_data;
    int m_iElementCount;
    void FUN_00d056a0();
};

// @fnv 0x00d056a0
void S_00d056a0::FUN_00d056a0()
{
    int n = m_iElementCount;
    if (n)
    {
        S_00d056a0_Elem* pData = m_data;
        static_cast<S_00d056a0_Router*>(::FUN_00c85750())->heap()->ReleaseBlock(pData, n * sizeof(S_00d056a0_Elem));
    }
}

struct D057A0Element
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

struct D057A0Queue
{
    D057A0Element* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void FUN_00d057a0(const D057A0Element& element);
};

namespace fnv_00d057f0 {
struct Item
{
    int data[32];
};

struct ItemPool
{
    Item* m_items;
    int m_pRayCursor;
    int m_free;
    int m_unk0c;
    int m_uiItemCount;

    void Grow(int newCapacity);
    void FUN_00d057f0(const Item& item);
};

// Grows the pool if full, then stores item at the next free slot and increments the count.
// @fnv 0x00d057f0
void ItemPool::FUN_00d057f0(const Item& item)
{
    if (m_uiItemCount >= m_pRayCursor)
    {
        if (!m_pRayCursor)
            Grow(8);
        else
            Grow(m_pRayCursor * 2);
    }
    if (!m_free)
        m_free = m_pRayCursor;
    --m_free;
    m_items[m_free] = item;
    ++m_uiItemCount;
}
}  // namespace fnv_00d057f0

struct CallTarget
{
};

// @fnv 0x00d043c0
int __cdecl FUN_00d043c0(CallTarget* apTarget, int aiValue)
{
    return ((int)(reinterpret_cast<::FUN_00d04390 *>((apTarget))->wait(aiValue)));
}


struct FUN_00d04450_cls
{
    int unk00;

    void SetValue(int a1);
};

// ---------------------------------------------------------------------------
// ReleasePendingCounts - releases the pending semaphore counts of one object.
//
// The object keeps a table of semaphores at offset 0x78 and the number of
// table entries that are in use at offset 0x8c.  The argument is a block of
// per entry counters that starts at offset 0x22.  Every counter is taken
// over, cleared and the semaphore of that entry is released once for every
// count that was pending.
// ---------------------------------------------------------------------------

// The semaphore object; only released through FUN_00d043c0.
struct FnvSemaphore;

// Releases a semaphore count times.

// The block of pending counters handed to ReleasePendingCounts.
struct FnvReleaseCounts
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned short unk20;
    unsigned short pending[8];  // 0x22
};

// The object that owns the semaphores.
struct FnvReleaseSet
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    FnvSemaphore* pSemaphores[5];  // 0x78
    int count;                     // 0x8c

    void ReleasePendingCounts(FnvReleaseCounts* pCounts);
};

// For each semaphore up to count, clears its pending count and releases that many single counts on the semaphore.
// @fnv 0x00d044f0
void FnvReleaseSet::ReleasePendingCounts(FnvReleaseCounts* pCounts)
{
    for (int i = 0; i < count; i++)
    {
        int pending = pCounts->pending[i];

        pCounts->pending[i] = 0;

        while (pending > 0)
        {
            ::FUN_00d043c0((::CallTarget *)(pSemaphores[i]), 1);
            pending--;
        }
    }
}

struct SpawnedEntry
{
    unsigned char m_key1;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    unsigned char m_key2;
    unsigned char m_uiFilterValue;
    unsigned char unk06;
    unsigned char unk07;
};

class FUN_00d04890_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    int m_30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    int m_48;

    int LookupSpawnedEntry(const unsigned char* p);
};
// Looks up the pool index for item, inserts it into that pool via Insert or Insert2 depending on flag, then notifies with the index and set.
// @fnv 0x00d04b00
void Mgr::InsertItemAndNotify(PoolSet* set, const Item& item, int abUseInsert2)
{
    int idx = reinterpret_cast<::FUN_00d04890_cls *>(this)->LookupSpawnedEntry((const unsigned char *)&(item));
    ItemPool& pool = set->m_pools[idx];
    if (!abUseInsert2)
        pool.Insert(item);
    else
        reinterpret_cast<::D057A0Queue *>(&(pool))->FUN_00d057a0((const ::D057A0Element &)(item));
    reinterpret_cast<::ItemManager *>(this)->RemoveItemReference(idx, (::UnsignedShortCountBlock *)(set));
}

// Scans up to m_48 entries for one matching p[0] and p[1], returning its byte at offset 8*i+0x3d, else p[1]+m_30.
// @fnv 0x00d04890
int FUN_00d04890_cls::LookupSpawnedEntry(const unsigned char* pKey)
{
    int i = 0;
    if (m_48 > 0)
    {
        unsigned char ucKey2 = pKey[1];
        unsigned char* pEntry = reinterpret_cast<unsigned char*>(&unk3c);
        do
        {
            if (ucKey2 == pEntry[-4])
            {
                unsigned char k = pKey[0];
                if (k == pEntry[0])
                {
                    return reinterpret_cast<unsigned char*>(this)[8 * i + 0x3d];
                }
            }
            pEntry += 8;
            ++i;
        } while (i < m_48);
    }
    return pKey[1] + m_30;
}


struct FUN_00d048e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int m_34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int m_4c;
    int m_50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int m_78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int m_8c;

    void ProcessPendingEntries(char* tbl);
};
// @fnv 0x00d04990
void ItemManager::RemoveItemReference(int index, UnsignedShortCountBlock* refs)
{
    if (index < count)
    {
        unsigned short refCount = refs->counts[index];
        if (refCount > 0)
        {
            refs->counts[index] = refCount - 1;
            ::FUN_00d043c0((::CallTarget *)(values[index]), 1);
            return;
        }
    }
    reinterpret_cast<::FUN_00d048e0_cls *>(this)->ProcessPendingEntries((char *)(refs));
}

// Scans entries from m_4c to m_50 then m_34 for pending flags, and if found decrements the entry's counter and calls FUN_00d043c0 with its m_78 value.
// @fnv 0x00d048e0
void FUN_00d048e0_cls::ProcessPendingEntries(char* tbl)
{
    unsigned char pending = 0;
    int i = m_4c;
    while (i < m_50)
    {
        if (*(int*)(tbl + 0x3c + i * 0x14) != 0)
        {
            pending = 1;
            if (*(unsigned short*)(tbl + 0x22 + i * 2) != 0)
            {
                goto found;
            }
        }
        ++i;
    }
    {
        int end = m_34;
        while (i < end)
        {
            if (*(int*)(tbl + 0x3c + i * 0x14) != 0)
            {
                goto scan;
            }
            ++i;
        }
    }
    if (pending == 0)
    {
        return;
    }
scan:
    for (i = m_4c; i < m_8c; ++i)
    {
        if (*(unsigned short*)(tbl + 0x22 + i * 2) != 0)
        {
            goto found;
        }
    }
    return;
found:
    *(unsigned short*)(tbl + 0x22 + i * 2) += 0xffff;
    ::FUN_00d043c0((::CallTarget *)((&this->m_78)[i]), 1);
}

struct __declspec(align(16)) D049D0LockInfo
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
};

struct D049D0Simulation
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_enabled;
};

struct D049D0World
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    D049D0Simulation* m_pSimulation;


    void SetSimulationEnabled(int enabled);
};


struct __declspec(align(16)) D04B90Object
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

struct D04B90World
{
    void addCopy(D04B90Object* copy, void* userData);
    void AddObjectCopy(const D04B90Object* object, void* userData);
};

// @fnv 0x00d04b90
void D04B90World::AddObjectCopy(const D04B90Object* object, void* userData)
{
    D04B90Object copy;
    ::FUN_00cb1260(&copy, object, object->m_usMemSizeAndFlags);
    addCopy(&copy, userData);
}


class FUN_00d05450_cls
{
  public:
    unsigned int m_00;
    unsigned char m_04;
    unsigned char unk05;
    unsigned short unk06;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    FUN_00d05450_cls* Init();
};

// @fnv 0x00d05450
FUN_00d05450_cls* FUN_00d05450_cls::Init()
{
    unsigned int value;
    unsigned int* dst = &m_08;
    *(volatile unsigned int*)&m_0c = 0;
    *(volatile unsigned int*)&m_10 = 0;
    *(volatile unsigned int*)&m_14 = 0x80000000u;
    *(volatile unsigned int*)&m_00 = 1;
    ::GetProcessorCount((int *)(unsigned int *)(&value));
    *dst = value;
    m_04 = 1;
    return this;
}

// ---------------------------------------------------------------------------
// InitHookTable
//
// A free cdecl function taking one pointer; it fills a global table of 17
// default handlers, bumps a counter member of the object to at least 2 and
// then registers two handler descriptors (array + count + two callbacks) in
// the object's dispatch table, followed by two more registration helpers.
//
// The unit file of the pack is empty, so every type used here is a stand-in:
// only the member offsets and the calling conventions matter.
// ---------------------------------------------------------------------------

typedef void(__cdecl* HookFn)(void*, void*);

// The 16 byte descriptor that SetEntry stores into the object's table.
struct HookInfo
{
    HookFn* m_ppData;   // +0x00  pointer to the handler array
    int m_uiItemCount;  // +0x04  number of entries in that array
    HookFn m_f1;        // +0x08  first callback
    HookFn m_f2;        // +0x0c  second callback
};

// Stand-in for the object the argument points at.  Only +0x60 is touched by
// this function; the table that SetEntry writes into starts at +0xf0.
struct TargetObj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    void QueueOperation(int a, int b, int c);
};

// The global handler array (17 entries) and the callbacks that go into it.
extern HookFn g_hookTable[17];


// Two more registration helpers, both cdecl with one pointer argument.

// Fills g_hookTable with hookDefault_00d01e50, raises p->unk60 to at least 2, registers two hook pairs via SetEntry, then calls FUN_00da3400 and FUN_00da3480.
// @fnv 0x00d2cca0
void __cdecl InitHookTable(TargetObj* apTarget)
{
    g_hookTable[0] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[1] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[2] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[3] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[4] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[5] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[6] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[7] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[8] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[9] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[10] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[11] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[12] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[13] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[14] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[15] = ((void (&)(void *, void *))::DispatchNodeByKind);
    g_hookTable[16] = ((void (&)(void *, void *))::DispatchNodeByKind);

    // The array and the count are live across the branch below, so they are
    // kept in callee saved registers and materialised in the entry block.
    HookInfo info;
    info.m_ppData = g_hookTable;
    info.m_uiItemCount = 17;

    if (apTarget->unk60 < 2)
    {
        apTarget->unk60 = 2;
    }

    apTarget->QueueOperation(0, 0xc, 1);

    info.m_f1 = ((void (&)(void *, void *))::PopPart);
    info.m_f2 = ((void (&)(void *, void *))::fnv_00d969e0::FUN_00d969e0);
    reinterpret_cast<::FUNObj *>((apTarget))->SetEntry(0, (*(int *)&(const ::HookInfo &)(info)), {}, {}, {});

    info.m_f1 = ((void (&)(void *, void *))::SplitRecord);
    info.m_f2 = ((void (&)(void *, void *))::TryCreateSubtype14Job);
    reinterpret_cast<::FUNObj *>((apTarget))->SetEntry(1, (*(int *)&(const ::HookInfo &)(info)), {}, {}, {});

    ::FUN_00da3400((::DispatcherDA34 *)(apTarget));
    ::fnv_00da3480::FUN_00da3480((::fnv_00da3480::DispatcherDA34 *)(apTarget));
}

struct D04A20Allocator;

struct D04A20MemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    D04A20Allocator* m_pStreamAllocator;

    D04A20Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
}

struct D04A20Operation
{
    void* m_object;
    bool m_flag;
    int m_data;
};

struct D04A20OperationArray
{
    D04A20Operation* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    D04A20Operation& AllocatePair()
    {
        D04A20Allocator& alloc = (*static_cast<D04A20MemoryRouter*>(::FUN_00c85750())).heap();
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&alloc), (::AudioStream *)(void *)(this), sizeof(D04A20Operation));
        return m_data[m_iElementCount++];
    }
};

struct D04A20World
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    D04A20OperationArray m_pPendingOperations;

    void QueueOperation(void* object, bool flag, int data);
};


struct D05490Base
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    D05490Base(int spinCount) throw();
};

struct SrcCfg
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
};

struct SubObj
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    int m_i14;
    SubObj() throw();
};

struct PoolEntry
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
    int m_i10;
    PoolEntry() throw();
};

struct PoolTable
{
    static void* operator new(std::size_t nbytes) throw()
    {
        return static_cast<S_00d056a0_Router*>(::FUN_00c85750())->heap()->AllocateMemoryBlock(nbytes);
    }

    unsigned short m_counts[12];
    int m_i18;
    int m_i1c;
    unsigned char m_b20;
    unsigned char m_b21;
    unsigned char m_b22;
    unsigned char m_b23;
    int m_i24;
    int m_i28;
    PoolEntry m_entries[16];
    PoolEntry& operator[](int i)
    {
        return m_entries[i];
    }
    int m_i16c;
};

struct Slot16
{
    intptr_t m_i00;
    int m_i04;
    void* m_p08;
    void* m_p0c;
};

struct D05490Array
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    D05490Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};


struct FUN_00d05490 : D05490Base
{

    PoolTable* volatile m_pTable;
    void* m_pFn1;
    void* m_pFn2;
    int m_uiItemCount;
    int m_i28;
    int m_i2c;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3c;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4c;
    int m_i50;
    int m_i54;
    SubObj m_sub;
    int m_i70;
    volatile unsigned char m_b74;
    unsigned char m_b75;
    unsigned char m_b76;
    unsigned char m_b77;
    int m_i78;
    int m_i7c;
    int m_i80;
    int m_i84;
    int m_i88;
    int m_i8c;
    int m_i90;
    int m_i94;
    int m_i98;
    int m_i9c;
    int m_ia0;
    int m_ia4;
    int m_ia8;
    int m_iac;
    int m_ib0;
    int m_ib4;
    int m_ib8;
    int m_ibc;
    int m_ic0;
    int m_ic4;
    int m_ic8;
    int m_icc;
    int m_id0;
    int m_id4;
    int m_id8;
    int m_idc;
    int m_ie0;
    int m_ie4;
    int m_ie8;
    int m_iec;
    Slot16 m_slots[11];
    D05490Array m_aiIndexedValues;

    FUN_00d05490(SrcCfg* a1) throw();
};

typedef int(__cdecl* DispatchHandler)(void*, void*, void*);

// Reads a byte index from item, scales it by 16, and calls the handler at that offset in context's dispatch table.
// @fnv 0x00d04550
int __cdecl FUN_00d04550(void* context, void* argument, void* item)
{
    unsigned int index = ((unsigned char*)item)[1];
    index *= 16;
    return (*(DispatchHandler*)((char*)context + 0xf8 + index))(context, argument, item);
}

template <typename T> inline T* hkAllocateChunk(int n)
{
    return static_cast<T*>(static_cast<S_00d056a0_Router*>(::FUN_00c85750())->heap()->AllocateMemoryBlock(n * sizeof(T)));
}

template <typename T> inline void hkDeallocateChunk(T* p, int n)
{
    static_cast<S_00d056a0_Router*>(::FUN_00c85750())->heap()->ReleaseBlock(p, n * sizeof(T));
}

struct hkQueue128
{
    S_00d056a0_Elem* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    void FUN_00d056d0(int n);
};
// @fnv 0x00d057a0
void D057A0Queue::FUN_00d057a0(const D057A0Element& element)
{
    if (m_iNodeCount >= m_pRayCursor)
    {
        if (m_pRayCursor == 0)
            reinterpret_cast<::hkQueue128 *>(this)->FUN_00d056d0(8);
        else
            reinterpret_cast<::hkQueue128 *>(this)->FUN_00d056d0(m_pRayCursor * 2);
    }
    if (m_pTail == m_pRayCursor)
        m_pTail = 0;
    m_data[m_pTail++] = element;
    m_iNodeCount++;
}

// Grows the underlying element array to at least n slots, copying existing nodes and resetting the ring indices.
// @fnv 0x00d056d0
void hkQueue128::FUN_00d056d0(int aiMinCapacity)
{
    if (m_pRayCursor < aiMinCapacity)
    {
        if (m_pRayCursor * 2 >= aiMinCapacity)
        {
            aiMinCapacity = m_pRayCursor * 2;
        }

        S_00d056a0_Elem* newData = hkAllocateChunk<S_00d056a0_Elem>(aiMinCapacity);

        if (m_data)
        {
            if (m_iNodeCount)
            {
                if (m_pTail <= m_pFirstNode)
                {
                    int numHead = m_pRayCursor - m_pFirstNode;
                    int numTail = m_pTail;
                    ::FUN_00cb1260(newData, m_data + m_pFirstNode, numHead * sizeof(S_00d056a0_Elem));
                    ::FUN_00cb1260(newData + numHead, m_data, numTail * sizeof(S_00d056a0_Elem));
                }
                else
                {
                    ::FUN_00cb1260(newData, m_data + m_pFirstNode, m_iNodeCount * sizeof(S_00d056a0_Elem));
                }
            }
            m_pFirstNode = 0;
            m_pTail = m_iNodeCount;
        }

        if (m_pRayCursor)
        {
            hkDeallocateChunk<S_00d056a0_Elem>(m_data, m_pRayCursor);
        }

        m_data = newData;
        m_pRayCursor = aiMinCapacity;
    }
}

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" const char str_010ccd90[];

static __forceinline short& Ref212(Registry* r, unsigned char sub)
{
    return reinterpret_cast<short*>(r)[sub];
}
struct LunaOwner : Owner
{
    int ProcessCallback(intptr_t param_2, intptr_t param_3, int param_4);
};
// @fnv 0x00d05190
int Obj::ForwardWithZero(intptr_t aiFirst, int aiSecond)
{
    return reinterpret_cast<::LunaOwner *>(this)->ProcessCallback(0, aiFirst, aiSecond);
}

struct LunaTrace
{
    int unk00;
    unsigned int* current;
    int unk08;
    unsigned int* end;
};

struct LunaCallbackItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Item payload;
};


struct TimerEntry
{
    const char* m_name;
    unsigned int m_uiCommandId;
    int m_auiShapeKeys;
};

struct MonitorStream
{
    int unk00;
    char* m_cur;
    int unk08;
    char* m_kRayEnd;
};

struct ArrayOfJobs
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct FUN_00d04bd0_cls : Owner
{
    void AddJobBatch(ArrayOfJobs* jobs, int priority);
};


struct S_00d05020_Job
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

struct S_00d05020_Queue
{
    S_00d05020_Job* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;


    void increaseCapacity()
    {
        if (m_pRayCursor == 0)
            reinterpret_cast<::hkQueue128 *>(this)->FUN_00d056d0(8);
        else
            reinterpret_cast<::hkQueue128 *>(this)->FUN_00d056d0(m_pRayCursor * 2);
    }

    void enqueueInFront(const S_00d05020_Job& element)
    {
        if (m_iNodeCount >= m_pRayCursor)
            increaseCapacity();
        if (m_pFirstNode == 0)
            m_pFirstNode = m_pRayCursor;
        --m_pFirstNode;
        m_data[m_pFirstNode] = element;
        m_iNodeCount++;
    }

    void enqueue(const S_00d05020_Job& element)
    {
        if (m_iNodeCount >= m_pRayCursor)
            increaseCapacity();
        if (m_pTail == m_pRayCursor)
            m_pTail = 0;
        m_data[m_pTail++] = element;
        m_iNodeCount++;
    }
};

struct S_00d05020_DynamicData
{
    short m_sQueueCounts[8];
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    S_00d05020_Queue m_kQueues[8];
};

struct S_00d05020_JobQueue
{
    int FUN_00d05020(int originalJobType, int priority, S_00d05020_Job& jobInOut, int waitStatus);
};

namespace fnv_00df8570 {
typedef unsigned long DWORD;
extern const char str_010dba98[];
struct S00df8570_Trace
{
    int status;
    unsigned int* next;
    int reserved;
    unsigned int* end;
};
struct S00df8570_Input
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int* outCount;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int entryCount;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
};
struct S00df8570_Rec
{
    unsigned char kind;
    unsigned char option;
    unsigned char active;
    unsigned char reserved;
    short stride;
    short sentinel;
    int m08;
    int m0c;
    int m10;
    intptr_t m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    S00df8570_Rec()
    {
        option = 3;
        sentinel = -1;
        m10 = 0;
        m18 = 0;
        active = 1;
        m30 = 0;
        m14 = 0;
        m60 = 0;
        kind = 5;
        stride = 0x70;
    }
};
struct S00df8570_Result
{
    void* values[92];
};
struct S00df8570_Enc
{
    int FUN_00d04400(S00df8570_Result* result);
    void FUN_00d04420(intptr_t output);
};
// Writes trace markers, copies input fields into records, calls InitSplitChunks, encodes and inserts items, then calls ProcessCallback and returns its result.
// @fnv 0x00df8570
int __cdecl FUN_00df8570(S00df8570_Enc* encoder, S00df8570_Input* input)
{
    volatile unsigned int stamp;
    intptr_t output;
    {
        S00df8570_Trace* trace = static_cast<S00df8570_Trace*>(TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))));
        unsigned int* next = trace->next;
        if (next < trace->end)
        {
            next[0] = reinterpret_cast<uintptr_t>(str_010dba98);
            _ReadWriteBarrier();
            stamp = static_cast<unsigned int>(__rdtsc());
            next[1] = stamp;
            trace->next = next + 3;
        }
    }
    __declspec(align(16)) S00df8570_Rec records[4];
    int count = input->entryCount;
    if (count > 4)
        count = 4;
    *input->outCount = count;
    if (count > 0)
    {
        records[0].m14 = reinterpret_cast<intptr_t>(input->outCount);
        records[0].m10 = input->m10;
        records[0].m1c = input->m1c;
        records[0].m20 = input->m20;
        records[0].m24 = input->m24;
        records[0].m38 = input->entryCount;
        records[0].m28 = input->m28;
        records[0].m2c = input->m2c;
        records[0].m30 = input->m30;
        records[0].m3c = input->m3c;
        records[0].m34 = input->m34;
        records[0].m40 = input->m40;
        records[0].m60 = 1;
        ::InitSplitChunks(input->m50, input->entryCount, input->m20, input->m10, count, (::SplitChunk *)(records));
        S00df8570_Result result;
        output = (int)encoder->FUN_00d04400(&result);
        for (int i = 0; i < count; ++i)
            reinterpret_cast<::Mgr *>((encoder))->InsertItemAndNotify((::PoolSet *)(output), (*(const ::Item *)(&records[i])), 0);
        encoder->FUN_00d04420(output);
    }
    int iResult = reinterpret_cast<::LunaOwner *>((encoder))->ProcessCallback((intptr_t)(input), (intptr_t)(input), 0);
    {
        S00df8570_Trace* trace = static_cast<S00df8570_Trace*>(TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c))));
        unsigned int* next = trace->next;
        if (next < trace->end)
        {
            next[0] = reinterpret_cast<uintptr_t>(::DAT_010c41f8);
            _ReadWriteBarrier();
            reinterpret_cast<volatile unsigned int&>(output) = static_cast<unsigned int>(__rdtsc());
            next[1] = reinterpret_cast<volatile unsigned int&>(output);
            trace->next = next + 3;
        }
    }
    return iResult;
}
}  // namespace fnv_00df8570

namespace fnv_00d04b50 {
struct QueueState
{
    void* storage;
    unsigned int capacity, front, back, size;
};
struct __declspec(align(16)) Buffer
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned short unk20, ref0, ref1, ref2, ref3, ref4;
    QueueState slot0, slot1, slot2, slot3, slot4, slot5, slot6, slot7;
    QueueState slot8, slot9, slot10, slot11, slot12, slot13, slot14, slot15;
};
struct Owner
{
    Buffer* FUN_00d04400(Buffer* scratch);
    void FUN_00d04420(Buffer* work);
    void FUN_00d04b50(void* first, unsigned int second);
};
// Passes a stack Buffer to FUN_00d04400, calls FUN_00d04b00 with its result and the arguments, then passes that result to FUN_00d04420.
// @fnv 0x00d04b50
void Owner::FUN_00d04b50(void* first, unsigned int second)
{
    Buffer scratch;
    Buffer* work = FUN_00d04400(&scratch);
    reinterpret_cast<::Mgr *>(this)->InsertItemAndNotify((::PoolSet *)(work), (*(const ::Item *)(first)), second);
    FUN_00d04420(work);
}
}  // namespace fnv_00d04b50

namespace fnv_00d055c0 {
struct S_00d055c0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08(void* p, int bytes) throw();
    virtual void vfn_0c();
    virtual void vfn_10(void* p, int bytes) throw();
    __forceinline void ReleaseBlock(void* p, int bytes) throw()
    {
        vfn_08(p, bytes);
    }
    __forceinline void ReturnMemory(void* p, int bytes) throw()
    {
        vfn_10(p, bytes);
    }
};
struct S_00d055c0_Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    S_00d055c0_Heap* m10;
    __forceinline S_00d055c0_Heap& heap()
    {
        return *m10;
    }
};

struct S_00d055c0_Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};
struct S_00d055c0_Pool
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    S_00d055c0_Elem e[16];
    int unk16c;
};
struct S_00d055c0_Handle
{
};
struct S_00d055c0_Cont
{
    int unk00;
};
struct S_00d055c0_Arr12
{
    void* m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void _clearAndDeallocate(S_00d055c0_Heap& h) throw()
    {
        int cap = m_cap;
        m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
            h.ReturnMemory(m_data, (cap & 0x3fffffff) * 12);
        m_data = 0;
        m_cap = 0x80000000;
    }
};
extern void(* DAT_00fdf058)(void*);

struct S_00d055c0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S_00d055c0_Pool* unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    S_00d055c0_Cont unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    unsigned char unk74;
    S_00d055c0_Handle* unk78[5];
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    S_00d055c0_Arr12 unk1a0;
    void FUN_00d055c0();
};

// Releases the pool and handle objects, clears and deallocates Arr12 storage, calls FUN_00cbf490, then calls DAT_00fdf058 with this.
// @fnv 0x00d055c0
void S_00d055c0_Obj::FUN_00d055c0()
{
    S_00d055c0_Pool* pool = unk18;
    if (pool)
    {
        S_00d055c0_Elem* p = pool->e + 16;
        int n = 15;
        do
        {
            p--;
            reinterpret_cast<::S_00d056a0 *>((p))->FUN_00d056a0();
        } while (--n >= 0);
        static_cast<S_00d055c0_Router*>(::FUN_00c85750())->heap().ReleaseBlock(pool, 0x170);
    }
    if (unk74)
    {
        for (int i = 0; i < unk8c; i++)
        {
            S_00d055c0_Handle* h = unk78[i];
            if (h)
            {
                reinterpret_cast<::FUN_00d04370_cls *>((h))->FUN_00d04370();
                static_cast<S_00d055c0_Router*>(::FUN_00c85750())->heap().ReleaseBlock(h, 4);
            }
        }
    }
    {
        S_00d055c0_Heap& heap = static_cast<S_00d055c0_Router*>(::FUN_00c85750())->heap();
        unk1a0._clearAndDeallocate(heap);
    }
    reinterpret_cast<::CBF490Lists *>(&(unk58))->ClearLists();
    DAT_00fdf058(this);
}
}  // namespace fnv_00d055c0

namespace fnv_00d889f0 {
struct ScratchBlock
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned short unk7C;
};

struct SlotAllocator
{
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void vSlot08();
    virtual void vSlot0C();
    virtual void vSlot10(unsigned int a, unsigned int b);
};

struct AllocHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    SlotAllocator* m_pAllocator;
};


// Initializes fields of a local ScratchBlock, passes it to FUN_00d883c0, then conditionally calls vSlot10 on m_pAllocator.
// @fnv 0x00d889f0
void* __cdecl FUN_00d889f0(void* a1)
{
    __declspec(align(16)) ScratchBlock s;
    s.unk0C = 1;
    s.unk10 = 1;
    s.unk14 = 0;
    s.unk18 = 0;
    s.unk1C = 0;
    s.unk5C = 0;
    s.unk60 = 0;
    s.unk68 = 0;
    s.unk6C = 0;
    s.unk70 = 0;
    s.unk74 = 0;
    s.unk78 = 0;
    s.unk64 = 0x80000000u;
    s.unk7C = 0;
    void* obj = ((void *)(::FUN_00d883c0((*(const ::S883_Island *)(a1)), (char *)(0), 0, (*(::S883_TaskHeader *)(&s)))));
    AllocHolder* pAllocHolder = static_cast<AllocHolder*>(::FUN_00c85750());
    SlotAllocator* alloc = pAllocHolder->m_pAllocator;
    unsigned int flag = s.unk64;
    if ((flag & 0x80000000u) == 0)
        alloc->vSlot10(s.unk5C, (flag & 0x3FFFFFFFu) * 4);
    return obj;
}
}  // namespace fnv_00d889f0


static const char kTraceFinishJob[] = "TtfinishJob";
static const char kTraceEnd[] = "Et";

struct TraceRecord
{
    const char* m_pName;
    unsigned long m_iTick;
    unsigned long unk08;
};

struct TraceBuffer
{
    unsigned long unk00;
    TraceRecord* m_pCur;
    unsigned long unk08;
    TraceRecord* m_pRecordEnd;
};

struct TraceArg
{
    unsigned char unk00;
    unsigned char m_uiEdgeIndex;
    unsigned short unk02;
    unsigned long unk04;
};

struct JobOut
{
    int m_iResultCode;
    int unk04;
    int unk08;
    int unk0C;
};

class Worker
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int(__cdecl* m_pfn20)(Worker*, PoolSet*, TraceArg*, int*);


    void FUN_00d04d80(TraceArg* p, int flag);
};

struct __declspec(align(16)) DispatchJob
{
    unsigned char m_eSubtype;
    unsigned char m_type;
    unsigned short m_iElementCount;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

__forceinline unsigned int ReadTick(volatile unsigned int* tick)
{
    *tick = (unsigned int)__rdtsc();
    return *tick;
}

struct TimerSamples
{
    volatile unsigned int cloth;
    volatile unsigned int pathfinding;
    volatile unsigned int physicsSecondary;
    volatile unsigned int characterProxy;
    volatile unsigned int raycast;
    volatile unsigned int userJob;
    volatile unsigned int behavior;
    volatile unsigned int unknownJob;
    volatile unsigned int collision;
    volatile unsigned int end;
    volatile unsigned int physics;
    volatile unsigned int animation;
};

struct JobFetchView
{
};

struct Dispatcher : FUN_00d05490
{
    int FUN_00d051b0();
};

// Fetches and executes a loop of DispatchJob entries, recording start and end ticks into the TLS MonitorStream for each job type.
// @fnv 0x00d051b0
int Dispatcher::FUN_00d051b0()
{
    TimerSamples samples;
    DispatchJob job;
    int result = reinterpret_cast<::Obj *>((((JobFetchView*)this)))->ForwardWithZero((intptr_t)&job, 0);
    if (result != 0)
        return result;
    do
    {
        switch (job.m_type)
        {
        case 0: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtPhysics";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.physics);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        case 1: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtPhysics";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.physicsSecondary);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        case 2: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtCollision Query";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.collision);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        case 3: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtRayCast Query";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.raycast);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        case 4: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtAnimation";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.animation);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        case 5: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtBehavior";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.behavior);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        case 6: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtCloth";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.cloth);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        case 7: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtPathfinding";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.pathfinding);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        case 9: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtCharacter Proxy";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.characterProxy);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        case 10: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtUserJob";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.userJob);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        default: {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "TtUnknownJobs";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.unknownJob);
                stream->m_cur = (char*)(cur + 1);
            }
        }
        break;
        }
        typedef int(__cdecl * Handler)(Dispatcher*, DispatchJob*);
        result = ((Handler*)m_slots[job.m_type].m_i00)[job.m_eSubtype](this, &job);
        {
            MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
            TimerEntry* cur = (TimerEntry*)stream->m_cur;
            if ((char*)cur < stream->m_kRayEnd)
            {
                cur->m_name = "Et";
                _ReadWriteBarrier();
                cur->m_uiCommandId = ReadTick(&samples.end);
                stream->m_cur = (char*)(cur + 1);
            }
        }
    } while (result == 0);
    return result;
}


struct QueueLockView : Owner
{
    Registry* FUN_00d04400(RequestContext* storage);
};

// @fnv 0x00d04400
Registry* QueueLockView::FUN_00d04400(RequestContext*)
{
    EnterCriticalSection(this);
    return reinterpret_cast<Registry*>(unk18);
}


struct CriticalSectionOwner
{
    void FUN_00d04420(Registry* data);
};
// @fnv 0x00d04a80
void Owner::FUN_00d04a80(int first, int second)
{
    RequestContext context;
    Registry* data = reinterpret_cast<::QueueLockView *>(this)->FUN_00d04400(&context);
    reinterpret_cast<::hkQueue128 *>(&((&data->buckets[0])[unk30 + first]))->FUN_00d056d0(second);
    for (int i = 0; i < count; ++i)
        reinterpret_cast<::hkQueue128 *>(&((&data->buckets[0])[*((unsigned char*)this + 0x3d + i * 8)]))->FUN_00d056d0(second);
    reinterpret_cast<::CriticalSectionOwner *>(this)->FUN_00d04420(data);
}
// Stores a1 into a field of the object at this+0x18, decrements a per-index counter in the buffer from FUN_00d04400, and calls FUN_00d043c0 when it was positive.
// @fnv 0x00d04450
void FUN_00d04450_cls::SetValue(int aiValue)
{
    __declspec(align(16)) unsigned int buf[0x5c];
    char* obj = (char*)((void *)(reinterpret_cast<::QueueLockView *>(this)->FUN_00d04400((::RequestContext *)(buf))));
    *(int*)(*(char**)((char*)this + 0x18) + 0x18) = aiValue;
    if (*(unsigned short*)(obj + 0x22 + *(signed char*)((char*)this + 0xea) * 2) > 0)
    {
        unsigned short dec = 0xffff;
        *(unsigned short*)(obj + 0x22 + *(signed char*)((char*)this + 0xea) * 2) += dec;
        ::FUN_00d043c0((::CallTarget *)(((int*)((char*)this + 0x78))[*(signed char*)((char*)this + 0xea)]), 1);
    }
    reinterpret_cast<::CriticalSectionOwner *>(this)->FUN_00d04420((::Registry *)(obj));
}
// Locks the world, stores enabled into the simulation's m_enabled, disables it when enabled is false, then unlocks.
// @fnv 0x00d049d0
void D049D0World::SetSimulationEnabled(int enabled)
{
    D049D0LockInfo info;
    void* lockHandle = ((void *)(reinterpret_cast<::QueueLockView *>(this)->FUN_00d04400((::RequestContext *)(::D049D0LockInfo *)(&info))));
    m_pSimulation->m_enabled = enabled;
    if (!enabled)
        reinterpret_cast<::FnvReleaseSet *>(this)->ReleasePendingCounts((::FnvReleaseCounts *)(lockHandle));
    reinterpret_cast<::CriticalSectionOwner *>(this)->FUN_00d04420((::Registry *)(lockHandle));
}
// Copies each job into a registry bucket, inserts it at the front or tail according to priority, and removes its item reference.
// @fnv 0x00d04bd0
void FUN_00d04bd0_cls::AddJobBatch(ArrayOfJobs* jobs, int priority)
{
    MonitorStream* stream = (MonitorStream*)TlsGetValue(DAT_0126835c);
    TimerEntry* cur = (TimerEntry*)stream->m_cur;
    if ((char*)cur < stream->m_kRayEnd)
    {
        cur->m_name = "TtAddJobBatch";
        _ReadWriteBarrier();
        volatile unsigned int tsc = (unsigned int)__rdtsc();
        cur->m_uiCommandId = tsc;
        stream->m_cur = (char*)(cur + 1);
    }

    RequestContext requestContext;
    Registry* reg = reinterpret_cast<::QueueLockView *>((this))->FUN_00d04400(&requestContext);

    for (int i = 0; i < jobs->m_iElementCount; i++)
    {
        void* pJob = jobs->m_data[i];
        Item localJob;
        ::FUN_00cb1260(&localJob, pJob, *(unsigned short*)((char*)pJob + 4));

        int queueIdx = reinterpret_cast<::FUN_00d04890_cls *>((this))->LookupSpawnedEntry((const unsigned char *)(void *)(&localJob));

        if (priority == 0)
        {
            Bucket* queue = &reg->buckets[queueIdx];
            if (queue->unk10 >= queue->unk04)
            {
                if (queue->unk04 == 0)
                {
                    reinterpret_cast<::hkQueue128 *>((queue))->FUN_00d056d0(8);
                }
                else
                {
                    reinterpret_cast<::hkQueue128 *>((queue))->FUN_00d056d0(queue->unk04 + queue->unk04);
                }
            }
            if (queue->unk08 == 0)
            {
                queue->unk08 = queue->unk04;
            }
            queue->unk08--;
            *(Item*)((char*)queue->unk00 + (queue->unk08 << 7)) = localJob;
            queue->unk10++;
        }
        else
        {
            Bucket* queue = &reg->buckets[queueIdx];
            if (queue->unk10 >= queue->unk04)
            {
                if (queue->unk04 == 0)
                {
                    reinterpret_cast<::hkQueue128 *>((queue))->FUN_00d056d0(8);
                }
                else
                {
                    reinterpret_cast<::hkQueue128 *>((queue))->FUN_00d056d0(queue->unk04 + queue->unk04);
                }
            }
            if (queue->unk0C == queue->unk04)
            {
                queue->unk0C = 0;
            }
            *(Item*)((char*)queue->unk00 + (queue->unk0C << 7)) = localJob;
            queue->unk0C += 1;
            queue->unk10 += 1;
        }

        reinterpret_cast<::ItemManager *>((this))->RemoveItemReference(queueIdx, (::UnsignedShortCountBlock *)(reg));
    }

    reinterpret_cast<::CriticalSectionOwner *>((this))->FUN_00d04420(reg);

    MonitorStream* streamEnd = (MonitorStream*)TlsGetValue(DAT_0126835c);
    TimerEntry* curEnd = (TimerEntry*)streamEnd->m_cur;
    if ((char*)curEnd < streamEnd->m_kRayEnd)
    {
        curEnd->m_name = "Et";
        _ReadWriteBarrier();
        volatile unsigned int tscEnd = (unsigned int)__rdtsc();
        curEnd->m_uiCommandId = tscEnd;
        streamEnd->m_cur = (char*)(curEnd + 1);
    }
}
// Records trace markers, runs the job callback on a pool node, inserts the result item, syncs, and releases the node.
// @fnv 0x00d04d80
void Worker::FUN_00d04d80(TraceArg* apTraceArg, int flag)
{
    volatile unsigned long tick;
    JobOut out;
    Item item;
    RequestContext ctx;

    TraceBuffer* pTraceBuf = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    if (pTraceBuf->m_pCur < pTraceBuf->m_pRecordEnd)
    {
        TraceRecord* pTraceRec = pTraceBuf->m_pCur;
        pTraceRec->m_pName = kTraceFinishJob;
        _ReadWriteBarrier();
        tick = (unsigned long)__rdtsc();
        pTraceRec->m_iTick = tick;
        pTraceBuf->m_pCur = pTraceRec + 1;
    }

    PoolSet* pPoolNode = ((::PoolSet *)(reinterpret_cast<::QueueLockView *>(this)->FUN_00d04400(&ctx)));
    if (m_pfn20(this, pPoolNode, apTraceArg, &out.m_iResultCode) == 0)
    {
        int idx = reinterpret_cast<::FUN_00d04890_cls *>(this)->LookupSpawnedEntry((const unsigned char *)(::Item *)(&item));
        if (out.m_iResultCode == 0)
            reinterpret_cast<::fnv_00d057f0::ItemPool *>(&(pPoolNode->m_pools[idx]))->FUN_00d057f0((const ::fnv_00d057f0::Item &)(item));
        else
            reinterpret_cast<::D057A0Queue *>(&(pPoolNode->m_pools[idx]))->FUN_00d057a0((const ::D057A0Element &)(item));
        reinterpret_cast<::ItemManager *>(this)->RemoveItemReference(idx, (::UnsignedShortCountBlock *)(pPoolNode));
    }

    if (flag == 0)
        --((short*)pPoolNode)[apTraceArg->m_uiEdgeIndex];  // per-index reference counts open the pool set

    reinterpret_cast<::CriticalSectionOwner *>(this)->FUN_00d04420((::Registry *)(pPoolNode));

    pTraceBuf = (TraceBuffer*)TlsGetValue(DAT_0126835c);
    if (pTraceBuf->m_pCur < pTraceBuf->m_pRecordEnd)
    {
        TraceRecord* pTraceRec = pTraceBuf->m_pCur;
        pTraceRec->m_pName = kTraceEnd;
        _ReadWriteBarrier();
        tick = (unsigned long)__rdtsc();
        pTraceRec->m_iTick = tick;
        pTraceBuf->m_pCur = pTraceRec + 1;
    }
}

// @fnv 0x00d04420
void CriticalSectionOwner::FUN_00d04420(Registry* data)
{
    LeaveCriticalSection(this);
}


// hkBase.lib debug info; byte-exact with the game under the Havok release flags.
struct RTL_CRITICAL_SECTION_
{
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
};

typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef std::size_t hk_size_t;

class hkMemoryAllocator
{
  public:
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes) = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;
};

class NineIntegerRecord
{
  public:
    static NineIntegerRecord& __cdecl GetMonitorStream();
    inline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    void* m_stackNext;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocator* m_pTemp;
    hkMemoryAllocator* m_pStreamAllocator;
};

class hkBool
{
  public:
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    inline hkBool& operator=(bool e)
    {
        m_cBooleanValue = static_cast<char>(e);
        return *this;
    }
    char m_cBooleanValue;
};

struct RouterHeapAllocatorProvider
{
    hkMemoryAllocator& get(const void*)
    {
        return NineIntegerRecord::GetMonitorStream().heap();
    }
};

template <typename T> class HavokElementArray
{
  public:
    __forceinline T& operator[](int i);
    __forceinline int GetLogicalSize() const;

  protected:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T, typename Allocator = RouterHeapAllocatorProvider> class hkArray : public HavokElementArray<T>
{
  public:
    typedef Allocator AllocatorType;
};

template <typename T> __forceinline int HavokElementArray<T>::GetLogicalSize() const
{
    return m_iElementCount;
}

class BusyWaitingSemaphore
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        return obj;
    }
    __forceinline void __cdecl operator delete(void* p)
    {
        if (p)
        {
            NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p, sizeof(BusyWaitingSemaphore));
        }
    }
    BusyWaitingSemaphore(int initialCount = 0, int maxCount = 1000);
    ~BusyWaitingSemaphore();

  protected:
    void* m_pCompletionSemaphore;
};
typedef BusyWaitingSemaphore hkSemaphoreBusyWait;

enum JobCategory
{
    HK_JOB_TYPE_MAX = 11
};

struct CellJobConfiguration
{
    enum CellRules
    {
        PPU_CAN_TAKE_SPU_TASKS,
        PPU_CANNOT_TAKE_SPU_TASKS
    };
    CellRules m_eCellRules;
    hkBool m_bCellConfigurationFlag;
    int m_iCellConfigurationValue;
    hkArray<hkArray<int> > m_kNestedIntegerLists;
};

struct ThreePointerIntegerRecord
{
    void* m_pFirstPointer;
    int m_iIntegerValue;
    void* m_pSecondPointer;
    void* m_pThirdPointer;
};

class JobDispatcher
{
  public:
    struct JobQueueWaitState
    {
        short m_sQueueCounts[HK_JOB_TYPE_MAX];
        int m_iWaitCount;
        int m_eWaitPolicy;
        hkBool m_bWaiting;
        hkUint16 m_auiThreadIds[MAX_NUM_THREAD_TYPES];
    };

    void FUN_00d04590();

    RTL_CRITICAL_SECTION_ m_pWorldLock;
    JobQueueWaitState* m_data;
    void* m_pSecondPointer;
    void* m_pThirdPointer;

    int iFirstInteger;
    int iSecondInteger;
    int iThirdInteger;
    int iFourthInteger;
    int m_iFifthIntegerInRun;

    struct JobCategorySubtypeRecord
    {
        JobCategory m_eJobType;
        hkUint8 m_ucSubType;
        hkUint8 m_ucAdditionalJobByte;
    };
    JobCategorySubtypeRecord akSubtypeRecords[2];
    int iPostArrayInteger;

    int m_iSecondIntegerAfterJobTypePairs;
    int m_iThirdIntegerAfterJobTypePairs;

    int m_iFourthIntegerAfterJobTypePairs;

    CellJobConfiguration kThreadState;

    int m_iIntegerAfterCellConfig;
    hkBool bIsActive;

    hkSemaphoreBusyWait* apThreadSemaphores[MAX_NUM_THREAD_TYPES];
    int iSemaphoreCount;

    hkInt8 aacThreadTypeNames[MAX_NUM_THREAD_TYPES][18];

    hkInt8 acFourByteValues[4];

    ThreePointerIntegerRecord m_akJobTypeEntries[HK_JOB_TYPE_MAX];

    struct JobCategoryThreadInfo
    {
        JobCategory m_eJobType;
        hkUint8 m_ucSubType;
        int m_uiThreadId;
    };
    hkArray<JobCategoryThreadInfo> kJobEntries;
};

// @fnv 0x00d04590
void JobDispatcher::FUN_00d04590()
{
    int numSharedCaches = kThreadState.m_kNestedIntegerLists.GetLogicalSize() == 0
                              ? 1
                              : kThreadState.m_kNestedIntegerLists.GetLogicalSize();
    iPostArrayInteger = kJobEntries.GetLogicalSize();

    if (!reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(kThreadState.m_bCellConfigurationFlag))->FUN_005609f0())
    {
        iSecondInteger = iFirstInteger;
    }
    else
    {
        iSecondInteger = 0;
    }

    iThirdInteger = iSecondInteger + numSharedCaches;
    iFourthInteger = kJobEntries.GetLogicalSize() + iThirdInteger;
    m_iFifthIntegerInRun = iFourthInteger + iFirstInteger;

    m_iSecondIntegerAfterJobTypePairs = iSecondInteger;

    m_iThirdIntegerAfterJobTypePairs = iFourthInteger;

    if (kThreadState.m_kNestedIntegerLists.GetLogicalSize() > 0)
    {
        for (int i = 0; i < kThreadState.m_iCellConfigurationValue; i++)
        {
            acFourByteValues[i] = -1;
        }
        for (int i = 0; i < kThreadState.m_kNestedIntegerLists.GetLogicalSize(); i++)
        {
            for (int j = 0; j < kThreadState.m_kNestedIntegerLists[i].GetLogicalSize(); j++)
            {
                acFourByteValues[kThreadState.m_kNestedIntegerLists[i][j]] = hkInt8(iSecondInteger + i);
            }
        }
        for (int i = 0; i < kThreadState.m_iCellConfigurationValue; i++)
        {
            ;  // HK_ASSERT: every CPU thread has a cache queue (release build: compiled out)
        }
    }

    if (kThreadState.m_kNestedIntegerLists.GetLogicalSize() == 0)
    {
        for (int i = 0; i < kThreadState.m_iCellConfigurationValue; i++)
        {
            acFourByteValues[i] = hkInt8(iSecondInteger);
        }
    }

    for (int i = 0; i < numSharedCaches; i++)
    {
        hkInt8* table = &aacThreadTypeNames[i + iSecondInteger][0];
        *table++ = hkInt8(i + iSecondInteger);

        for (int j = 0; j < kThreadState.m_kNestedIntegerLists.GetLogicalSize(); j++)
        {
            if (i != j)
            {
                *table++ = hkInt8(j + iSecondInteger);
            }
        }

        for (int j = 0; j < iFirstInteger; j++)
        {
            *table++ = hkInt8(j + iFourthInteger);
        }
        if (kThreadState.m_eCellRules == CellJobConfiguration::PPU_CAN_TAKE_SPU_TASKS)
        {
            for (int j = 0; j < iFirstInteger; j++)
            {
                *table++ = hkInt8(j);
            }
        }

        for (int j = 0; j < iPostArrayInteger; j++)
        {
            *table++ = hkInt8(j + iThirdInteger);
        }

        *table++ = -1;
    }

    for (int i = 0; i < iPostArrayInteger; i++)
    {
        akSubtypeRecords[i].m_eJobType = kJobEntries[i].m_eJobType;
        akSubtypeRecords[i].m_ucSubType = kJobEntries[i].m_ucSubType;
        akSubtypeRecords[i].m_ucAdditionalJobByte = hkUint8(i + iThirdInteger);

        int originalSemaphoreIndex = acFourByteValues[kJobEntries[i].m_uiThreadId];
        acFourByteValues[kJobEntries[i].m_uiThreadId] = akSubtypeRecords[i].m_ucAdditionalJobByte;

        hkInt8* table = &aacThreadTypeNames[i + iThirdInteger][0];
        *table++ = hkInt8(i + iThirdInteger);

        for (int j = 0; aacThreadTypeNames[originalSemaphoreIndex][j] != -1; j++)
        {
            if (aacThreadTypeNames[originalSemaphoreIndex][j] != akSubtypeRecords[i].m_ucAdditionalJobByte)
            {
                *table++ = aacThreadTypeNames[originalSemaphoreIndex][j];
            }
        }
        *table++ = -1;
    }

    int numSemaphores = iFourthInteger;

    m_iFourthIntegerAfterJobTypePairs = acFourByteValues[0];
    bool newSemaphoreNeeded = false;
    for (int i = 1; i < kThreadState.m_iCellConfigurationValue; i++)
    {
        if (acFourByteValues[i] == acFourByteValues[0])
        {
            newSemaphoreNeeded = true;
            break;
        }
    }
    if (newSemaphoreNeeded)
    {
        acFourByteValues[0] = hkInt8(numSemaphores);
        numSemaphores++;
    }

    if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(bIsActive))->FUN_005609f0())
    {
        for (int i = 0; i < iSemaphoreCount; i++)
        {
            delete apThreadSemaphores[i];
        }
    }

    iSemaphoreCount = numSemaphores;

    for (int i = 0; i < iSemaphoreCount; i++)
    {
        m_data->m_auiThreadIds[i] = 0;
        apThreadSemaphores[i] = new hkSemaphoreBusyWait(0, 1000);
    }

    bIsActive = true;
}

extern const char str_010ccd70[];
struct MonEntry { void* name; int tick; int unk08; };
struct MonStream { int unk00; MonEntry* m_cur; int unk08; MonEntry* m_kRayEnd; };
static __forceinline void CaptureMarker(void* marker)
{
    MonStream* s = (MonStream*)TlsGetValue(DAT_0126835c);
    MonEntry* entry=s->m_cur;
    if (entry < s->m_kRayEnd) {
        entry->name = marker;
        unsigned int ticks;
        ticks = static_cast<unsigned int>(__rdtsc());
        entry->tick = ticks;
        s->m_cur=entry+1;
    }
}
struct __declspec(align(16)) ItemBuf { int data[32]; };
struct Bucket20
{
    ItemBuf* m_base;
    int m_pRayCursor;
    int m_pFirstNode;
    int unk0C;
    int m_uiItemCount;
};
struct Refs
{
    unsigned short w00; unsigned short w02; unsigned short w04; unsigned short w06;
    unsigned short w08; unsigned short w0A; unsigned short w0C; unsigned short w0E;
    unsigned short w10; unsigned short w12; unsigned short w14; unsigned short w16;
    int f18;
    int f1C;
    unsigned short w20;
    unsigned short pending[5];
    Bucket20 buckets[1];
    bool IsClear(int m) const { if (f18 & m) return false; return true; }
};
struct BSRenderedTexture;
struct FUN_00b37880;
struct FakeObj;
struct Helper;
struct Output;
struct P1;
struct P3;
struct Param;
struct Ptr;
struct Refs;
struct VirtObj;
struct Wrap;

struct Host
{
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18;
    ItemFn m_fn1C;
    int unk20;
    int m_count24;
    int unk28; int unk2C;
    int m_bucketBase30;
    int unk34; int unk38; int unk3C; int unk40; int unk44; int unk48;
    int m_lo4C;
    int m_hi50;
    int m_def54;
    int unk58; int unk5C; int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74;
    int* m_iSlotIds[5];
    int unk8C; int unk90; int unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8;
    int unkAC; int unkB0; int unkB4; int unkB8; int unkBC; int unkC0; int unkC4; int unkC8;
    int unkCC; int unkD0; int unkD4; int unkD8; int unkDC; int unkE0; int unkE4;
    unsigned short wE8;
    signed char bEA;
    unsigned char bEB;
    __forceinline int tryPop(Refs* refs,int a4) {
    int v;
    if (TlsGetValue((*reinterpret_cast<int *>(&::g_dwTlsIndex))) == 0)
        v = m_def54;
    else
        v = ((signed char*)TlsGetValue((*reinterpret_cast<int *>(&::g_dwTlsIndex))))[(intptr_t)this + 0xea];
    signed char* cursor = (signed char*)this + (v * 9 + 0x48) * 2;
    int cur = *cursor;
    while(cur >= 0) {
        Bucket20* bucket = (Bucket20*)((char*)refs + cur*20+0x2c);
        ++cursor;
        if(bucket->m_uiItemCount != 0) {
        ItemBuf item;
        item = bucket->m_base[bucket->m_pFirstNode];
        int head = bucket->m_pFirstNode + 1;
        bucket->m_pFirstNode = head;
        if (head == bucket->m_pRayCursor)
            bucket->m_pFirstNode = 0;
        bucket->m_uiItemCount--;
        int r = m_fn1C(this, refs, &item, a4);
        if (r == 1) {
            reinterpret_cast<::fnv_00d057f0::ItemPool *>((bucket))->FUN_00d057f0((*(const ::fnv_00d057f0::Item *)(&item)));
            reinterpret_cast<::ItemManager *>(this)->RemoveItemReference(cur, (::UnsignedShortCountBlock *)(refs));
        }
        ((unsigned short*)refs)[((unsigned char*)&item)[1]]++;
        return cur;
        }
        cur=*cursor;
    }
    return -1;
    }
    int FUN_00d05840(int a1, Refs* refs, int a3, int a4);
public:
    // 0x0050de60
    bool FUN_0050de60(::Ptr, float *, ::P3 *);
    // 0x005174d0
    void *FUN_005174d0(unsigned int);
    // 0x00639c90
    bool FUN_00639c90(unsigned int);
    // 0x0068b4c0
    bool FUN_0068b4c0(::Param *);
    // 0x00872f50
    ::BSRenderedTexture *FUN_00872f50(::P1 *, ::BSRenderedTexture *, unsigned char, unsigned char);
    // 0x0087ae60
    void QueueCheckTask(::FakeObj *);
    // 0x00913fb0
    void FUN_00913fb0(::VirtObj *);
    // 0x009a3780
    void ProcessElements(::Helper *);
    // 0x00b18f60
    void FUN_00b18f60(::FUN_00b37880 *);
    // 0x00b8b3b0
    void FUN_00b8b3b0();
    // 0x00dbf930
    void WriteArray(const ::Wrap &, int);
    // 0x00df9fe0
    int FUN_00df9fe0(::Output *, int *);
};
// @fnv 0x00d05840
int Host::FUN_00d05840(int a1, Refs* refs, int a3, int a4)
{
    int ediVal = tryPop(refs,a4);
    if (a1 != -1 && a1 != ediVal) reinterpret_cast<::ItemManager *>(this)->RemoveItemReference(a1,(::UnsignedShortCountBlock *)(refs));
    if (ediVal >= 0) { reinterpret_cast<::CriticalSectionOwner *>(this)->FUN_00d04420((::Registry *)(refs)); return 0; }
    {
        int total = 0;
        for(int i=m_lo4C;i<m_hi50;++i) total += refs->buckets[i].m_uiItemCount;
        if (total != 0)
            goto tail_check;
        int mask = 0;
        for (int k = 0; k < m_count24; k++) {
            mask |= ((((short*)refs)[k] > 0 || refs->buckets[m_bucketBase30 + k].m_uiItemCount != 0) ? 1 : 0) << k;
        }
        bool none = refs->IsClear(mask) != 0;
        bool maskZero = mask == 0;
        if (none) {
            if (TlsGetValue((*reinterpret_cast<int *>(&::g_dwTlsIndex))) == 0) {
                if (maskZero)
                    reinterpret_cast<::FnvReleaseSet *>(this)->ReleasePendingCounts((::FnvReleaseCounts *)(refs));
                reinterpret_cast<::CriticalSectionOwner *>(this)->FUN_00d04420((::Registry *)(refs));
                return 2;
            }
            if (refs->pending[bEA] > 0) {
                refs->pending[bEA]--;
                ::FUN_00d043c0((::CallTarget *)((intptr_t)m_iSlotIds[bEA]), 1);
            }
        }
        if (maskZero && refs->f1C != 1) {
            reinterpret_cast<::FnvReleaseSet *>(this)->ReleasePendingCounts((::FnvReleaseCounts *)(refs));
            reinterpret_cast<::CriticalSectionOwner *>(this)->FUN_00d04420((::Registry *)(refs));
            return 2;
        }
    }
tail_check:
    if (a3 == 1) {
        reinterpret_cast<::CriticalSectionOwner *>(this)->FUN_00d04420((::Registry *)(refs));
        return 1;
    }
    {
        int idx = ((signed char*)TlsGetValue((*reinterpret_cast<int *>(&::g_dwTlsIndex))))[(intptr_t)&this->bEA];
        refs->pending[idx]++;
        reinterpret_cast<::CriticalSectionOwner *>(this)->FUN_00d04420((::Registry *)(refs));
        CaptureMarker((void*)str_010ccd70);
        ::FUN_00d043b0((void *)((intptr_t)m_iSlotIds[idx]));
        CaptureMarker((void*)::DAT_010c41f8);
        return -1;
    }
}



// Appends an operation with the given object, flag and data to the pending array, then processes pending operations.
// @fnv 0x00d04a20
void D04A20World::QueueOperation(void* object, bool flag, int data)
{
    D04A20Operation& op = m_pPendingOperations.AllocatePair();
    op.m_object = object;
    op.m_flag = flag;
    op.m_data = data;
    reinterpret_cast<::JobDispatcher *>(this)->FUN_00d04590();
}
// Initializes the TLS value, allocates a PoolTable, sets up its entries and slot callbacks, then calls FinishInit.
// @fnv 0x00d05490
FUN_00d05490::FUN_00d05490(SrcCfg* pConfig) throw() : D05490Base(0)
{
    TlsSetValue(g_dwTlsIndex, 0);
    m_pTable = new PoolTable;
    m_b74 = 0;
    m_pTable->m_b20 = 0;
    m_pTable->m_i1c = 0;
    reinterpret_cast<::ArrayRecord *>(&(m_sub))->FUN_00d05b50((*(const ::ArrayRecord *)(pConfig)));
    m_uiItemCount = pConfig->m_i18;
    m_i70 = 0;
    for (int i = 0; i < 16; ++i)
    {
        reinterpret_cast<::hkQueue128 *>(&((*m_pTable)[i]))->FUN_00d056d0(0x80);
    }
    m_pTable->m_i18 = 0;
    for (int k = 0; k < m_uiItemCount; ++k)
    {
        m_slots[k].m_i04 = 0;
        m_slots[k].m_i00 = 0;
        m_slots[k].m_p08 = (void*)((void (&)())::FUN_00d043d0);
        m_slots[k].m_p0c = (void*)((void (&)())::FUN_00d043e0);
        m_pTable->m_counts[k] = 0;
        m_pTable->m_i18 |= 1 << k;
    }
    m_pFn1 = (void*)((void (&)())::FUN_00d04550);
    m_pFn2 = (void*)((void (&)())::FUN_00d04570);
    m_i8c = 0;
    reinterpret_cast<::JobDispatcher *>(this)->FUN_00d04590();
}
// When param_2 is nonzero, invokes the owner callback and inserts its payload; repeats FUN_00d05840 until it returns a value other than -1.
// @fnv 0x00d04e80
int LunaOwner::ProcessCallback(intptr_t param_2, intptr_t param_3, int param_4)
{
    union Phase212
    {
        volatile unsigned int tick;
        Registry* registry;
    };
    Phase212 phase;
    {
        LunaTrace* trace = (LunaTrace*)TlsGetValue(::DAT_0126835c);
        unsigned int* cursor = trace->current;
        if (cursor < trace->end)
        {
            *cursor = (uintptr_t)str_010ccd90;
            _ReadWriteBarrier();
            phase.tick = static_cast<unsigned int>(__rdtsc());
            cursor[1] = phase.tick;
            cursor += 3;
            trace->current = cursor;
        }
    }

    int result;
    for (;;)
    {
        RequestContext context;
        phase.registry = reinterpret_cast<::QueueLockView *>(this)->FUN_00d04400(&context);
        int index = -1;
        if (param_2 != 0)
        {
            LunaCallbackItem item;
            typedef int(__cdecl * OwnerCallback)(Owner*, Registry*, int, LunaCallbackItem*);
            if (((OwnerCallback)unk20)(this, phase.registry, param_2, &item) == 0)
            {
                index = reinterpret_cast<::FUN_00d04890_cls *>(this)->LookupSpawnedEntry((const unsigned char *)(::Item *)(&item.payload));
                Bucket* bucket = &phase.registry->buckets[index];
                int capacity = bucket->unk04;

                if (item.unk00 == 0)
                {
                    if (bucket->unk10 >= capacity)
                    {
                        if (capacity == 0)
                            reinterpret_cast<::hkQueue128 *>((bucket))->FUN_00d056d0(8);
                        else
                            reinterpret_cast<::hkQueue128 *>((bucket))->FUN_00d056d0(capacity * 2);
                    }
                    if (bucket->unk08 == 0)
                        bucket->unk08 = bucket->unk04;
                    --bucket->unk08;
                    Item* destination = (Item*)(bucket->unk00 + bucket->unk08 * 0x80);
                    *destination = item.payload;
                    ++bucket->unk10;
                }
                else
                {
                    if (bucket->unk10 >= capacity)
                    {
                        if (capacity == 0)
                            reinterpret_cast<::hkQueue128 *>((bucket))->FUN_00d056d0(8);
                        else
                            reinterpret_cast<::hkQueue128 *>((bucket))->FUN_00d056d0(capacity * 2);
                    }
                    if (bucket->unk0C == bucket->unk04)
                        bucket->unk0C = 0;
                    Item* destination = (Item*)(bucket->unk00 + bucket->unk0C * 0x80);
                    *destination = item.payload;
                    ++bucket->unk0C;
                    ++bucket->unk10;
                }
            }

            unsigned char sub = *(unsigned char*)(param_2 + 1);
            --Ref212(phase.registry, sub);
            param_2 = 0;
        }

        result = reinterpret_cast<::Host *>(this)->FUN_00d05840(index, (::Refs *)(phase.registry), param_4, param_3);
        if (result != -1)
            break;
    }

    {
        LunaTrace* trace = (LunaTrace*)TlsGetValue(::DAT_0126835c);
        unsigned int* cursor = trace->current;
        if (cursor < trace->end)
        {
            *cursor = (uintptr_t)::DAT_010c41f8;
            _ReadWriteBarrier();
            volatile unsigned int stamp = static_cast<unsigned int>(__rdtsc());
            cursor[1] = (unsigned int)stamp;
            cursor += 3;
            trace->current = cursor;
        }
    }

    return result;
}
// Enqueues a job at the front or tail of a queue, then repeats FUN_00d05840 until it returns a value other than -1.
// @fnv 0x00d05020
int S_00d05020_JobQueue::FUN_00d05020(int aiJobType, int priority, S_00d05020_Job& jobInOut, int waitStatus)
{
    volatile unsigned int tick;
    {
        MonitorStream* s = (MonitorStream*)TlsGetValue(::DAT_0126835c);
        if (s->m_cur < s->m_kRayEnd)
        {
            TimerEntry* h = (TimerEntry*)s->m_cur;
            h->m_name = "TtGetNextJob";
            _ReadWriteBarrier();
            tick = (unsigned int)__rdtsc();
            h->m_uiCommandId = tick;
            s->m_cur = (char*)(h + 1);
        }
    }
    RequestContext dynamicDataStorage;
    bool jobToAdd = true;
    int result;
    do
    {
        S_00d05020_DynamicData* data = ((::S_00d05020_DynamicData *)(reinterpret_cast<::QueueLockView *>(this)->FUN_00d04400((::RequestContext *)(char *)((char*)&dynamicDataStorage))));
        int queueIndex = -1;
        if (jobToAdd)
        {
            data->m_sQueueCounts[aiJobType]--;
            queueIndex = reinterpret_cast<::FUN_00d04890_cls *>(this)->LookupSpawnedEntry((const unsigned char *)&(jobInOut));
            S_00d05020_Queue& queue = data->m_kQueues[queueIndex];
            if (priority == 0)
                queue.enqueueInFront(jobInOut);
            else
                queue.enqueue(jobInOut);
            jobToAdd = false;
        }
        result = reinterpret_cast<::Host *>(this)->FUN_00d05840(queueIndex, (::Refs *)(data), waitStatus, (intptr_t)&(jobInOut));
    } while (result == -1);
    {
        MonitorStream* s = (MonitorStream*)TlsGetValue(::DAT_0126835c);
        if (s->m_cur < s->m_kRayEnd)
        {
            TimerEntry* h = (TimerEntry*)s->m_cur;
            h->m_name = "Et";
            _ReadWriteBarrier();
            tick = (unsigned int)__rdtsc();
            h->m_uiCommandId = tick;
            s->m_cur = (char*)(h + 1);
        }
    }
    return result;
}

#include "generated/data/havok/common/base/thread/jobqueue/hkjobqueue.inc"
