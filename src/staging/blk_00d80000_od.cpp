
// src/staging/blk_00d80000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"
#include <xmmintrin.h>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00cdf6d0_t.h"
#include "fnv/decl/hkMatrix4CD60.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00d88000.h"
#include <new>
#include "fnv/decl/FUN_00df3110.h"
#include "fnv/decl/hkKdTreeBuilder.h"
#include "fnv/symbols_00d9d000.h"
#include "fnv/symbols_00df3000.h"
#include "fnv/symbols_00df5000.h"
#include "fnv/symbols_01268000.h"

struct BaseD85
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
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
};

struct ObjD85 : BaseD85
{
    short unk90;
    char unk92;
    short unk94;
    short unk96;
    __m128 unka0;
    __m128 unkb0;
    __m128 unkc0;
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
    ObjD85& FUN_00d85ba0(const ObjD85& o);
};

struct __declspec(align(16)) StandinClass
{
    unsigned short unk00;
    __m128 value10;
    __m128 value20;
    __m128 value30;
    __m128 value40;
    __m128 value50;
    __m128 value60;
    __m128 value70;
    __m128 value80;
    StandinClass& FUN_00d85300(const StandinClass* source);
};

// @fnv 0x00d85ba0
ObjD85& ObjD85::FUN_00d85ba0(const ObjD85& o)
{
    reinterpret_cast<::StandinClass *>(this)->FUN_00d85300((const ::StandinClass *)&(o));
    unk90 = o.unk90;
    unk92 = o.unk92;
    unk94 = o.unk94;
    unk96 = o.unk96;
    unka0 = o.unka0;
    unkb0 = o.unkb0;
    unkc0 = o.unkc0;
    unkd0 = o.unkd0;
    unkd4 = o.unkd4;
    unkd8 = o.unkd8;
    unke0 = o.unke0;
    unke4 = o.unke4;
    unke8 = o.unke8;
    unkec = o.unkec;
    unkf0 = o.unkf0;
    unkf4 = o.unkf4;
    unkf8 = o.unkf8;
    unkfc = o.unkfc;
    unk100 = o.unk100;
    unk104 = o.unk104;
    unk108 = o.unk108;
    unk10c = o.unk10c;
    unk110 = o.unk110;
    unk114 = o.unk114;
    unk118 = o.unk118;
    unk11c = o.unk11c;
    unk120 = o.unk120;
    unk124 = o.unk124;
    unk128 = o.unk128;
    unk12c = o.unk12c;
    return *this;
}

// @fnv 0x00d85300
StandinClass& StandinClass::FUN_00d85300(const StandinClass* source)
{
    unk00 = source->unk00;
    value10 = source->value10;
    value20 = source->value20;
    value30 = source->value30;
    value40 = source->value40;
    value50 = source->value50;
    value60 = source->value60;
    value70 = source->value70;
    value80 = source->value80;
    return *this;
}

namespace fnv_00d925b0 {

typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkContactPoint
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vSeparatingNormal;
};

struct UInt32Value
{
    hkUint32 m_data;
};

struct __declspec(align(16)) hkpSimpleContactConstraintDataInfo
{
    hkUint32 m_flags;
    hkUint32 m_uiEdgeIndex;
    float m_internalData0;
    float m_rhsRolling0;
    float m_rhsRolling1;
    float m_rollingFrictionMultiplier;
    float m_internalData1;
    hkUint32 m_data7;
};

struct hkpSimpleContactConstraintAtom
{
    hkUint16 m_type;
    hkUint16 m_usSizeOfAllAtoms;
    hkUint16 m_usNumContactPoints;
    hkUint16 m_usMaxNumContactPoints;
    hkUint8 m_ucNumReservedContactPoints;
    hkUint8 m_ucNumContactPointProperties;
    hkUint8 m_ucContactPointPropertiesStriding;
    hkUint8 unk0B;
    hkUint16 m_usMaxNumContactPointProperties;
    hkUint16 unk0E;
    hkpSimpleContactConstraintDataInfo m_info;

    __forceinline hkContactPoint* getContactPoints() const
    {
        return (hkContactPoint*)(this + 1);
    }
    __forceinline UInt32Value* getContactPointPropertiesStream() const
    {
        return (UInt32Value*)((char*)getContactPoints() + sizeof(hkContactPoint) * m_usMaxNumContactPoints);
    }
    __forceinline int getContactPointPropertiesStriding() const
    {
        return m_ucContactPointPropertiesStriding;
    }
};

__forceinline void memCpy4(void* dst, const void* src, int numWords)
{
    const hkUint32* src32 = (const hkUint32*)src;
    hkUint32* dst32 = (hkUint32*)dst;
    for (int i = 0; i < numWords; i++)
    {
        *(dst32++) = *(src32++);
    }
}

// @fnv 0x00d925b0
void FUN_00d925b0(hkpSimpleContactConstraintAtom* dst, const hkpSimpleContactConstraintAtom* src)
{
    dst->m_info = src->m_info;
    dst->m_usNumContactPoints = src->m_usNumContactPoints;

    hkContactPoint* dstCp = dst->getContactPoints();
    UInt32Value* dstProps = dst->getContactPointPropertiesStream();
    const hkContactPoint* srcCp = src->getContactPoints();
    const UInt32Value* srcProps = src->getContactPointPropertiesStream();
    int striding = src->getContactPointPropertiesStriding();
    for (int i = 0; i < src->m_usNumContactPoints; i++)
    {
        *(dstCp++) = *(srcCp++);
        memCpy4(dstProps, srcProps, striding >> 2);
        dstProps = (UInt32Value*)((char*)dstProps + striding);
        srcProps = (const UInt32Value*)((const char*)srcProps + striding);
    }
}
}

// namespace fnv_00d925b0


struct hkVector4Stub
{
    __m128 m_vComponents;
    float& operator()(int i)
    {
        return ((float*)this)[i];
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    void operator=(const hkVector4Stub& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct hkTransformStub
{
    hkVector4Stub m_kColumn0;
    hkVector4Stub m_kColumn1;
    hkVector4Stub m_kColumn2;
    hkVector4Stub m_vTranslation;
    void setIdentity()
    {
        hkVector4Stub zero;
        zero.setZero4();
        m_kColumn0 = zero;
        m_kColumn1 = zero;
        m_kColumn2 = zero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
        m_vTranslation.setZero4();
    }
};

struct ShapeStub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType() const;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ShapeStub* unk18;
};

struct ShapeWithVectors : ShapeStub
{
    int unk1c;
    hkVector4Stub m_kShapeVectorData[1];
};

struct ShapeWithTransforms : ShapeStub
{
    int unk1c;
    hkTransformStub m_kTransforms[1];
};

// @fnv 0x00d84ee0
void FUN_00d84ee0(ShapeStub* shape, int key, hkTransformStub* out)
{
    for (;;)
    {
        out->setIdentity();
        switch (shape->getType())
        {
        case 12:
            shape = shape->unk18;
            break;
        case 13:
            shape = ((::ShapeStub *)(reinterpret_cast<::FUN_00cdf6d0_t *>((shape))->FUN_00cdf6d0()));
            break;
        case 1:
            reinterpret_cast<::hkMatrix4CD60 *>((out))->FUN_00c6cd60((*(const ::hkMatrix4CD60 *)(&((ShapeWithTransforms*)shape)->m_kTransforms[key])));
            return;
        case 2:
            reinterpret_cast<::hkMatrix4CD60 *>((out))->FUN_00c6cd60((*(const ::hkMatrix4CD60 *)(&((ShapeWithTransforms*)shape)->m_kTransforms[key])));
            return;
        case 6:
            reinterpret_cast<::hkMatrix4CD60 *>((out))->FUN_00c6cd60((*(const ::hkMatrix4CD60 *)(&((ShapeWithTransforms*)shape)->m_kTransforms[key])));
            return;
        case 7:
            reinterpret_cast<::hkMatrix4CD60 *>((out))->FUN_00c6cd60((*(const ::hkMatrix4CD60 *)(&((ShapeWithTransforms*)shape)->m_kTransforms[key])));
            return;
        case 14:
            reinterpret_cast<::hkMatrix4CD60 *>((out))->FUN_00c6cd60((*(const ::hkMatrix4CD60 *)(&((ShapeWithTransforms*)shape)->m_kTransforms[key])));
            return;
        case 9:
            reinterpret_cast<::hkMatrix4CD60 *>((out))->FUN_00c6cd60((*(const ::hkMatrix4CD60 *)(&((ShapeWithTransforms*)shape)->m_kTransforms[key])));
            return;
        case 0:
            out->m_vTranslation = ((ShapeWithVectors*)shape)->m_kShapeVectorData[key];
            return;
        case 8:
            out->m_vTranslation = ((ShapeWithVectors*)shape)->m_kShapeVectorData[key];
            return;
        case 15:
            out->m_vTranslation = ((ShapeWithVectors*)shape)->m_kShapeVectorData[key];
            return;
        default:
            return;
        }
    }
}

struct hkMemoryAllocatorS
{
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void* BufRealloc(void* pOld, int oldNumBytes, int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <class T> void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem * sizeof(T));
    }
};

struct hkMemoryRouterS;

hkMemoryRouterS* FUN_00c85750();

struct hkMemoryRouterS
{
    static hkMemoryRouterS& GetMonitorStream()
    {
        return *FUN_00c85750();
    }
    hkMemoryAllocatorS& heap()
    {
        return *m_pStreamAllocator;
    }
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorS* m_pStreamAllocator;
};

hkMemoryRouterS* FUN_00c85750();

template <class T> struct hkArrayS
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayS() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void clear()
    {
        m_iElementCount = 0;
    }
    void _clearAndDeallocate(hkMemoryAllocatorS& alloc)
    {
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc._bufFree<T>(m_data, getCapacity());
        }
    }
    ~hkArrayS()
    {
        _clearAndDeallocate(hkMemoryRouterS::GetMonitorStream().heap());
    }
};

struct __declspec(align(16)) QueryCollector
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float m20[4];
    float m30[4];
    float m40[4];
    int unk50;
    int unk54;
    int unk58;
    hkArrayS<void*> m_kHits;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    short unk7C;
    QueryCollector()
        : unk0C(1), unk10(1), unk14(0), unk18(0), unk1C(0), unk68(0), unk6C(0), unk70(0), unk74(0), unk78(0), unk7C(0)
    {}
};

// @fnv 0x00d88aa0
int FUN_00d88aa0(void* a)
{
    QueryCollector collector;
    return ::FUN_00d883c0((*(const ::S883_Island *)(a)), (char *)(0), 0, (*(::S883_TaskHeader *)(&collector)));
}

struct __declspec(align(16)) S00d9db60_ProjectedEntry
{
    unsigned short m_kMinimumCorner[3];
    unsigned short m_usFirstVectorPadding;
    unsigned short m_kMaximumCorner[3];
    unsigned short m_usSecondVectorPadding;
    __forceinline void operator=(const S00d9db60_ProjectedEntry& other)
    {
        *(__m128*)this = *(const __m128*)&other;
    }
    __forceinline void reset()
    {
        m_kMinimumCorner[0] = m_kMinimumCorner[1] = m_kMinimumCorner[2] = 0;
        m_kMaximumCorner[0] = m_kMaximumCorner[1] = m_kMaximumCorner[2] = 0xffff;
    }
};

struct S00d9db60_Allocator
{
    virtual ~S00d9db60_Allocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T> __forceinline T* _bufAlloc(int& reqNumInOut)
    {
        const int SIZE_ELEM = sizeof(T);
        int n = reqNumInOut * SIZE_ELEM;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n / SIZE_ELEM;
        return static_cast<T*>(p);
    }
    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(T);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};

struct S00d9db60_Router
{
    void* m_stackCur;
    void* m_stackEnd;
    void* m_stackBase;
    S00d9db60_Allocator* m_pTemp;
    S00d9db60_Allocator* m_pStreamAllocator;
    __forceinline S00d9db60_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S00d9db60_Router* __cdecl FUN_00c85750();

struct S00d9db60_HeapAllocator
{
    __forceinline S00d9db60_Allocator& get(const void*)
    {
        return FUN_00c85750()->heap();
    }
};

template <typename T> struct S00d9db60_Array
{
    enum
    {
        DONT_DEALLOCATE_FLAG = 0x80000000,
        CAPACITY_MASK = 0x3fffffff
    };
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline S00d9db60_Array(int n) : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {
        S00d9db60_Allocator& a = S00d9db60_HeapAllocator().get(this);
        T* p = n ? a._bufAlloc<T>(n) : 0;
        int cap = n ? n : DONT_DEALLOCATE_FLAG;
        setOwnedData(p, n, cap);
    }
    __forceinline void setOwnedData(T* ptr, int size, int capacity)
    {
        m_data = ptr;
        m_iElementCount = size;
        m_iCapacityState = capacity;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    __forceinline void clear()
    {
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease()
    {
        S00d9db60_Allocator& alloc = S00d9db60_HeapAllocator().get(this);
        clear();
        if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
            alloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = DONT_DEALLOCATE_FLAG;
    }
    __forceinline T* begin()
    {
        return m_data;
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct S00d9db60_Node
{
    unsigned int m_word0, m_word1;
};

struct S00d9db60_KdTree
{
    S00d9db60_Array<S00d9db60_Node> m_kNodeCollection;
    int m_iNumNodes;
    int m_iNumPrimitives;
    int m_iNumProjectedEntries;
    int m_iNumReservedEmptyNodes;
    S00d9db60_Array<S00d9db60_ProjectedEntry> m_kProjectedEntries;
    __forceinline S00d9db60_Array<S00d9db60_Node>& getNodes()
    {
        return m_kNodeCollection;
    }
    __forceinline S00d9db60_Node* getRoot()
    {
        return m_kNodeCollection.begin();
    }
    __forceinline int getNumReservedEmptyNodes() const
    {
        return m_iNumReservedEmptyNodes;
    }
    __forceinline S00d9db60_ProjectedEntry* getProjectedEntries()
    {
        return m_kProjectedEntries.begin();
    }
};

struct S00d9db60_Mediator
{
    virtual ~S00d9db60_Mediator();
    virtual void reserved1();
    virtual void reserved2();
    virtual int GetNumEntries() const = 0;
};

struct S00d9db60_WorkingSet
{
    S00d9db60_ProjectedEntry* m_pProjectedEntryBegin;
    S00d9db60_ProjectedEntry* m_pProjectedEntryEnd;
};

struct S00d9db60_TreeStream
{
    S00d9db60_Node* m_pTreeNode;
};

struct S00d9db60_Comparison
{
    __m128 m_uiMask;
    __forceinline void setXYZ()
    {
        m_uiMask = (*reinterpret_cast<const __m128 *>(&::DAT_012684d0));
    }
};

struct S00d9db60_SparseWriter
{
    enum
    {
        BUFFER_SIZE = 16
    };
    __m128 m_kVectorBuffer[BUFFER_SIZE];
    int m_uiEdgeIndex;
      // constructor
      // flush, from the inline destructor
};

struct S00d9db60_BuildRecursiveInput
{
    S00d9db60_WorkingSet* m_pWorkingSet;
    int m_iFirstInputValue;
    int m_iSecondInputValue;
    int m_iThirdValue;
    int m_iFourthInputValue;
    S00d9db60_ProjectedEntry m_kBounds;
    S00d9db60_SparseWriter* m_pStreamWriter;
    S00d9db60_Comparison m_kComparison;
    __forceinline S00d9db60_BuildRecursiveInput() : m_iSecondInputValue(-1)
    {
        m_kComparison.setXYZ();
    }
};

// @fnv 0x00d9db60
void __cdecl FUN_00d9db60(S00d9db60_Mediator& mediator, S00d9db60_KdTree* tree)
{
    S00d9db60_Node* root = tree->getRoot();

    S00d9db60_Array<S00d9db60_ProjectedEntry> entriesA(mediator.GetNumEntries());
    S00d9db60_Array<S00d9db60_ProjectedEntry> entriesB(mediator.GetNumEntries());

    S00d9db60_WorkingSet buffers;
    buffers.m_pProjectedEntryBegin = entriesA.begin();
    buffers.m_pProjectedEntryEnd = entriesB.begin();

    ::FillAabbArray((::S_00d9dab0_Coll *)(::S00d9db60_Mediator *)(&mediator), 0, mediator.GetNumEntries(), (::S_00d9dab0_Aabb16 *)(::S00d9db60_ProjectedEntry *)(entriesA.begin()));

    S00d9db60_ProjectedEntry rootBounds;
    rootBounds.reset();

    if (mediator.GetNumEntries() < 8)
    {
        int numReservedEmptyNodes = tree->getNumReservedEmptyNodes();
        ::MixChannels((void *)&(buffers), (int *)(::S00d9db60_Node *)(tree->m_kNodeCollection.begin()), (int)(tree->getProjectedEntries()),
                    (void *)(tree->m_kNodeCollection.GetLogicalSize()), mediator.GetNumEntries(), (int *)(numReservedEmptyNodes),
                    (int *)&(tree->m_iNumNodes));
        entriesB.ClearAndRelease();
        entriesA.ClearAndRelease();
        return;
    }

    S00d9db60_BuildRecursiveInput subTreeInputs[4];
    S00d9db60_WorkingSet subTreeBuffers[4];
    subTreeInputs[0].m_pWorkingSet = &subTreeBuffers[0];
    subTreeInputs[1].m_pWorkingSet = &subTreeBuffers[1];
    subTreeInputs[2].m_pWorkingSet = &subTreeBuffers[2];
    subTreeInputs[3].m_pWorkingSet = &subTreeBuffers[3];

    int numPrimitivesPerSubTree[4];
    ::hkKdTreeBuilder::FUN_00df37b0((const ::hkKdTreeBuildInput::WorkingSet &)(buffers), (::KdTreeNode *)(root), tree->m_kNodeCollection.GetLogicalSize(), mediator.GetNumEntries(), (::hkKdTreeBuildInput::ProjectedBoundsContext *)(subTreeInputs),
                 numPrimitivesPerSubTree, (const ::FieldlessRecord &)(rootBounds));

    int numReservedEmptyNodes = tree->getNumReservedEmptyNodes();
    int emptyNodesPerSubTree[4];
    emptyNodesPerSubTree[0] = numReservedEmptyNodes / 4;
    emptyNodesPerSubTree[1] = numReservedEmptyNodes / 4;
    emptyNodesPerSubTree[2] = numReservedEmptyNodes / 4;
    emptyNodesPerSubTree[3] =
        numReservedEmptyNodes - emptyNodesPerSubTree[0] - emptyNodesPerSubTree[1] - emptyNodesPerSubTree[2];

    int currentNodeIdx = 8;
    int subTreeDepths[4];
    for (int i = 0; i < 4; i++)
    {
        S00d9db60_WorkingSet ws;
        ws.m_pProjectedEntryBegin = subTreeInputs[i].m_pWorkingSet->m_pProjectedEntryBegin;
        ws.m_pProjectedEntryEnd = subTreeInputs[i].m_pWorkingSet->m_pProjectedEntryEnd;

        S00d9db60_BuildRecursiveInput input;
        input.m_pWorkingSet = &ws;
        input.m_iFirstInputValue = subTreeInputs[i].m_iFirstInputValue;
        input.m_iThirdValue = subTreeInputs[i].m_iThirdValue;
        input.m_iFourthInputValue = subTreeInputs[i].m_iFourthInputValue;
        input.m_kBounds = subTreeInputs[i].m_kBounds;
        input.m_iSecondInputValue = tree->m_kNodeCollection.GetLogicalSize();

        S00d9db60_SparseWriter writer;
        new ((void *)&(writer)) ::FUN_00df3110();
        input.m_pStreamWriter = &writer;

        int depth = 1;
        S00d9db60_TreeStream stream;
        stream.m_pTreeNode = root + currentNodeIdx;
        numPrimitivesPerSubTree[i] += emptyNodesPerSubTree[i] + (emptyNodesPerSubTree[i] & 1);
        currentNodeIdx += numPrimitivesPerSubTree[i];

        subTreeDepths[i] = ::FUN_00df56a0((::Node56 *)&(input), (::Output56 **)(::S00d9db60_TreeStream *)(&stream), (int)(tree->getProjectedEntries()), &depth, &emptyNodesPerSubTree[i]);
        subTreeDepths[i] += 2;
        ::FUN_00df3160();
    }

    ::FUN_00d9d950((::S9d950_Owner *)(tree), mediator.GetNumEntries(), (const ::S9d950_Box *)(subTreeDepths), numPrimitivesPerSubTree);
    entriesB.ClearAndRelease();
    entriesA.ClearAndRelease();
}
