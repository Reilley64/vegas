// bscore/bssimplearray_private_decls.h: declares BSSimpleArrayPacketEffect, BSSimpleArrayPacketDebug, NiNode, PacketNodeRecord, PathingGraphNode and more
#ifndef FNV_BSSIMPLEARRAY_PRIVATE_DECLS_H
#define FNV_BSSIMPLEARRAY_PRIVATE_DECLS_H


#include <cstdlib>
#include <cstring>
#include "fnv/decl/FUN_006e3c90_cls.h"
#include "fnv/decl/FUN_00761540_cls.h"
#include "fnv/decl/FUN_007883b0.h"
#include "fnv/decl/FUN_00afcde0_shell.h"
#include "fnv/decl/S006d0510.h"
#include "fnv/decl/SHStub.h"
#include "fnv/symbols_0106c000.h"
typedef int(__cdecl* BSSimpleArrayCompare)(const void*, const void*);
// Canonical placeholder for the runtime copy routine at 0x00ec7230 (_memmove is 0x00ec44d0).

template <class T, unsigned int N> class BSSimpleArray
{
  public:
    virtual ~BSSimpleArray() = 0;

  protected:
    virtual T* _Allocate(unsigned int count);
    virtual void _Deallocate(T* items);
    virtual T* _Reallocate(T* items, unsigned int count);

  public:
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void FUN_006b3eb0(unsigned int, bool);
    void ReleaseElements(T* items, unsigned int count);
    void InitializeItems(T* items, unsigned int count);
    unsigned int BinarySearch(T& value, BSSimpleArrayCompare compare);
    unsigned int ReserveIndex();
    unsigned int Add(T& value);
    void InsertInSortedOrder(T& value, BSSimpleArrayCompare compare);
    void Insert(unsigned int index, T& value);
    void Clear(bool freeBuffer);
    T& GetAt(unsigned int index);
    void SetSize(unsigned int size, bool shrinkBuffer);
    template <unsigned int M> void CopyTo(BSSimpleArray<T, M>* destination);
    template <class U> unsigned int Find(U& value, unsigned int start, bool(__cdecl* compare)(T&, U&));

  private:
    void UpdateEntryValue(T* destination, T* source, unsigned int count);
    void ReallocateStorage(unsigned int newCapacity, unsigned int preserveCount);

  protected:
    void _InitialSetup(unsigned int capacity, unsigned int initialSize);
};

extern unsigned int DAT_0106f798;
extern unsigned int DAT_01073e50;
class BSSimpleArrayPacketEffect
{
  public:
};
extern unsigned int DAT_0109504c;
class BSSimpleArrayPacketDebug
{
  public:
};

class NiAVObject;
class TESObjectREFR;
class NiNode;
template <class T> class NiTNewInterface;
template <class T, class Allocator> class NiTArray
{
  public:
    T& GetAt(unsigned int);
};
template <class T> class NiPointer
{
  public:
    T* operator->() const;
};
class NiNode
{
    char prefix[0x9c];
    NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> > children;

  public:
    NiAVObject* GetAt(unsigned int);
};

class PacketNodeRecord
{
    char storage[0x30];
};
class PathingGraphNode
{
    char storage[0x3c];
};
class BSSimpleArrayPacketNode
{
  public:
};
class BSSimpleArrayPacketReserve
{
  public:
};

#include <stddef.h>
namespace Tile {
class Value;
}
class BGSBodyPart;
class BGSReconstructFormsMap;
class OffsetData
{
  public:
    unsigned int iOffset;
    BGSReconstructFormsMap* m_pFormLookupMap;
};
class ScrapHeapBuffer
{
  public:
};
template <class T, unsigned int N> class BSScrapArray : public BSSimpleArray<T, N>
{
  public:
    ScrapHeapBuffer* m_pAllocator;

  protected:
    virtual void _Deallocate(T* items);
};
template <class T> class NiRect
{
  public:
    T m_fMinimumU, m_fMaximumU, m_fMinimumV, m_fMaximumV;
};
class ButtonIcon
{
  public:
    float m_fGlyphWidthInPixels, m_fHorizontalOffset, m_fGlyphVerticalOffset, m_fHorizontalSpacing;
    NiRect<float> m_kTextureCoordinates;
};
#include "SandboxProcedureData.h"
class NiPoint3
{
  public:
    float x, y, z;
};
enum PathingAvoidNode__AVOID_NODE_TYPE
{
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE = 0,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_CYLINDER = 1,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE_ACTOR = 2
};
class PathingAvoidanceNode
{
  public:
    NiPoint3 m_kLocation, TwoComponentVector;
    float fRadius, m_fPathingCostCur;
    PathingAvoidNode__AVOID_NODE_TYPE eType;
};

// This real specialization isolates its private helper ABI from legacy accepted declarations.
template <> class BSSimpleArray<PathingAvoidanceNode, 1024>
{
  public:
    virtual ~BSSimpleArray();

  protected:
    virtual PathingAvoidanceNode* _Allocate(unsigned int count);
    virtual void _Deallocate(PathingAvoidanceNode* items);
    virtual PathingAvoidanceNode* _Reallocate(PathingAvoidanceNode* items, unsigned int count);
    void _InitialSetup(unsigned int capacity, unsigned int initialSize);

  public:
    PathingAvoidanceNode* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

  private:
};

typedef BSSimpleArray<Tile::Value*, 8> BSSimpleArrayTileLayout;
typedef BSScrapArray<OffsetData, 1024> BSScrapArrayOffsetLayout;
typedef BSSimpleArray<PathingAvoidanceNode, 1024> BSSimpleArrayAvoidLayout;

#endif
