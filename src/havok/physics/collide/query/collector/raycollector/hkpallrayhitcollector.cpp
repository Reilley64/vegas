
// src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cf0000.h"
struct Item;
void __cdecl FUN_00c852c0(Item* arr, int low, int high, int a4);

class FUN_00c855f0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Item* m_10;
    int m_14;

    void FUN_00c855f0();
};

// If m_14 exceeds 1, calls FUN_00c852c0 on m_10 with 0 and m_14 - 1.
// @fnv 0x00c855f0
void FUN_00c855f0_cls::FUN_00c855f0()
{
    union
    {
        volatile unsigned char b;
        int i;
    } flag;
    flag.b = 0;
    if (m_14 > 1)
    {
        FUN_00c852c0(m_10, 0, m_14 - 1, flag.i);
    }
}

#include <xmmintrin.h>
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};


struct ChainNode
{
    int unk00;
    int unk04;
    int unk08;
    ChainNode* m_pNext;
};

struct ChainOwner
{
    int unk00;
    int unk04;
    int unk08;
    ChainNode* m_pHead;
};

struct SourceEntry
{
    __m128 m_v0;
    float m_f10;
    int m_i14;
    int m_i18;
    int m_i1C;
};

struct SpawnedEntry
{
    __m128 m_v0;
    float m_f10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    ChainNode* m_pReferencedNode;
    int m_i54;
    int m_i58;
    int m_i5C;
};

struct EntryListNode
{
    SpawnedEntry* m_pData;
    unsigned int m_uCount;
    unsigned int m_uCapFlags;
};

struct FUN_00c85520_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EntryListNode m_kNode;

    void AddEntry(ChainOwner* apOwner, SourceEntry* apSource);
};

// Grows the SpawnedEntry list if full, appends a new entry copying fields from apSource, and links it to the last ChainNode in apOwner.
// @fnv 0x00c85520
void FUN_00c85520_cls::AddEntry(ChainOwner* apOwner, SourceEntry* apSource)
{
    EntryListNode* pList = &m_kNode;
    AudioHolder* pHolder = static_cast<AudioHolder*>(::FUN_00c85750());
    if (pList->m_uCount == (pList->m_uCapFlags & 0x3fffffffu))
    {
        ::ResizeAudioStream(pHolder->m_pAllocator, (::AudioStream *)(pList), sizeof(SpawnedEntry));
    }

    SpawnedEntry* pNew = pList->m_pData + pList->m_uCount;
    if (pNew != 0)
    {
        pNew->m_f10 = 1.0f;
        pNew->m_i14 = -1;
        pNew->m_i40 = 0;
        pNew->m_i20 = -1;
        pNew->m_pReferencedNode = 0;
    }

    SpawnedEntry* pDst = pList->m_pData + pList->m_uCount;
    pList->m_uCount++;

    pDst->m_v0 = apSource->m_v0;
    pDst->m_f10 = apSource->m_f10;
    pDst->m_i14 = apSource->m_i14;
    pDst->m_i18 = apSource->m_i18;
    pDst->m_i1C = apSource->m_i1C;
    ::CollectValuesReversed((int *)(void *)(&pDst->m_i20), 8, (::LinkedEntry *)(apOwner));

    ChainNode* pLast = (ChainNode*)apOwner;
    while (pLast->m_pNext != 0)
    {
        pLast = pLast->m_pNext;
    }
    pDst->m_pReferencedNode = pLast;
}

// Moved from hkpallrayhitcollector_gs_nogs_variant.cpp (VEGAS-15).
// src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector_gs_nogs_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct __declspec(align(16)) Item
{
    __m128 v;
    float key;
    int unk14;
    int shapeKeys[10];
    void* u40;
    __declspec(align(16)) void* u50;

    __forceinline Item()
    {
        shapeKeys[2] = -1;
    }

    __forceinline Item(const Item& rhs)
    {
        v = rhs.v;
        key = rhs.key;
        unk14 = rhs.unk14;
        for (int n = 0; n < 10; ++n)
            shapeKeys[n] = rhs.shapeKeys[n];
        u40 = rhs.u40;
        u50 = rhs.u50;
    }

    __forceinline Item& operator=(const Item& rhs)
    {
        v = rhs.v;
        key = rhs.key;
        unk14 = rhs.unk14;
        for (int n = 0; n < 10; ++n)
            shapeKeys[n] = rhs.shapeKeys[n];
        u40 = rhs.u40;
        u50 = rhs.u50;
        return *this;
    }
};

static __forceinline bool lessThan(const Item& a, const Item& b)
{
    return a.key < b.key;
}

template <typename T> static __forceinline void swap(T& a, T& b)
{
    T t;
    t = b;
    b = a;
    a = t;
}

// @fnv 0x00c852c0
void __cdecl FUN_00c852c0(Item* arr, int low, int high, int a4)
{
    int i = low;
    int j = high;
    Item pivot = arr[(low + high) >> 1];

    do
    {
        while (lessThan(arr[i], pivot))
            i++;
        while (lessThan(pivot, arr[j]))
            j--;

        if (j >= i)
        {
            if (j == i)
            {
                j--;
                i++;
            }
            else
            {
                swap(arr[i], arr[j]);
                j--;
                i++;
            }
        }
    } while (i <= j);

    if (low < j)
        FUN_00c852c0(arr, low, j, a4);
    if (i < high)
        FUN_00c852c0(arr, i, high, a4);
}
