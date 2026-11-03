
// src/havok/physics/collide/agent3/machine/nn/hkplinkedcollidable.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/nn/hkplinkedcollidable.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d04000.h"
#include "fnv/symbols_00d08000.h"
#include "havok/hkpLinkedCollidable.h"

struct FUN_00d08210_Entry
{
    void* collisionAgent;
    unsigned short collisionIndices[2];
    unsigned int metadata08, metadata0C, metadata10;
    hkpLinkedCollidable* owner;
};
struct FUN_00d08210_Pair
{
    FUN_00d08210_Entry* entry;
    unsigned int key;
};
struct FUN_00d08210_Collidable : hkpLinkedCollidable
{
    void UpdateCollisionIndices();
};
// @fnv 0x00d08210
void FUN_00d08210_Collidable::UpdateCollisionIndices()
{
    if (m_kCollisionEntries.m_iElementCount > 1)
        ::QuickSortPairs((::SortPair8 *)(::FUN_00d08210_Pair *)((FUN_00d08210_Pair*)m_kCollisionEntries.m_data), 0, m_kCollisionEntries.m_iElementCount - 1,
                       (bool (*)(const SortPair8 *, const SortPair8 *))(((int (&)(const FUN_00d08210_Pair *, const FUN_00d08210_Pair *))::CompareByNestedValue)));
    for (int index = 0; index < m_kCollisionEntries.m_iElementCount; ++index)
    {
        volatile FUN_00d08210_Pair* pair = ((volatile FUN_00d08210_Pair*)m_kCollisionEntries.m_data) + index;
        FUN_00d08210_Entry* entry = pair->entry;
        entry->collisionIndices[this == entry->owner] = (unsigned short)index;
    }
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}
inline void operator delete(void*, void*)
{}

class hkMemoryAllocatorD082;

struct hkMemoryRouterD082
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD082* m_pStreamAllocator;

    hkMemoryAllocatorD082& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD082 {
extern "C" hkMemoryRouterD082& __cdecl FUN_00c85750() throw();
}


struct ItemD082
{
    int m_kPointA;
    int m_kPointB;
};


template <class T> __forceinline void copyD082(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <class T> __forceinline void constructWithArrayD082(T* pDst, int n, const T* pSrc)
{
    for (int i = 0; i < n; i++)
        new (pDst + i) T(pSrc[i]);
}

template <class T> class hkArrayD082
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T* begin()
    {
        return m_data;
    }

    __forceinline void _copyFromArray(hkMemoryRouterD082& kRouter, const hkArrayD082& a)
    {
        hkMemoryAllocatorD082& kAlloc = kRouter.heap();
        const int iSize = m_iElementCount;
        const int iSrcSize = a.m_iElementCount;
        int iCopiedCount = (iSrcSize > iSize) ? iSize : iSrcSize;
        if (getCapacity() < iSrcSize)
        {
            int iCap2 = 2 * getCapacity();
            int iNewCap = (iSrcSize < iCap2) ? iCap2 : iSrcSize;
            ::FUN_00c908c0((::SpawnedObject *)&(kAlloc), (::SpawnedArray *)(void *)(this), iNewCap, sizeof(T));
        }
        copyD082(m_data, a.m_data, iCopiedCount);
        constructWithArrayD082(m_data + iCopiedCount, iSrcSize - iCopiedCount, a.m_data + iCopiedCount);
        m_iElementCount = iSrcSize;
    }
    __forceinline hkArrayD082& operator=(const hkArrayD082& a)
    {
        _copyFromArray(hkRouterD082::FUN_00c85750(), a);
        return *this;
    }
};

template <class T> inline void quickSortD082(T* pArr, int iSize, bool(__cdecl* pfnCmp)(const T&, const T&))
{
    if (iSize > 1)
        ::QuickSortPairs((::SortPair8 *)(pArr), 0, iSize - 1, (bool (*)(const SortPair8 *, const SortPair8 *))(pfnCmp));
}

class ContainerD082
{
  public:
    int unk00, unk04, unk08, unk0C;
    signed char m_cIndex;
    char unk11[0x3f];
    hkArrayD082<ItemD082> m_kUnsortedGeometryList;
    int unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84, unk88;
    int unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8;
    int unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4;
    unsigned char m_aucTypes[8];

    void CopyAndSortGeometryList(hkArrayD082<ItemD082>& kOut) const;
};

// Copies m_kUnsortedGeometryList into kOut and quick-sorts it by nested value when m_aucTypes[m_cIndex] is 5.
// @fnv 0x00d08260
void ContainerD082::CopyAndSortGeometryList(hkArrayD082<ItemD082>& kOut) const
{
    kOut = m_kUnsortedGeometryList;
    if (m_aucTypes[m_cIndex] == 5)
        quickSortD082(kOut.begin(), kOut.GetLogicalSize(), ((bool (&)(const ItemD082 &, const ItemD082 &))::CompareByNestedValue));
}
