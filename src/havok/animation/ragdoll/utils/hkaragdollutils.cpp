
// src/havok/animation/ragdoll/utils/hkaragdollutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/ragdoll/utils/hkaragdollutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstddef>
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00ce9000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01095000.h"
#include <xmmintrin.h>
#include "fnv/decl/Cb0StringCopy.h"
#include "fnv/decl/FUN_00cb0a60.h"
#include "fnv/decl/SStringPtr.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include <new>
#include "fnv/decl/CA8890Object.h"
#include "fnv/decl/CC0280Writer.h"
#include "fnv/decl/FUN_00c7f690_cls.h"
#include "fnv/decl/FUN_00ce2510.h"
#include "fnv/decl/FUN_00ce50b0_cls.h"
#include "fnv/decl/FUN_00d733e0.h"
#include "fnv/decl/FUN_00d73410.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/S_00ce5070_QsTransform.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/cf5990_TransformShape.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cdd000.h"
#include "fnv/symbols_00cea000.h"
#include "fnv/symbols_00d74000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_010cb000.h"
#include "fnv/symbols_01268000.h"
extern "C"
{
    int __cdecl FUN_00cea030(void*, void*);
    int __cdecl FUN_00ce9db0(void*, void*);
    int __cdecl FUN_00ce9e90(void*);
}

// @fnv 0x00cea7c0
int __cdecl FUN_00cea7c0(void* apFirst, void* apSecond, void* apThird)
{
    if (FUN_00cea030(apFirst, apSecond))
        return 1;
    if (FUN_00ce9db0(apSecond, apThird))
        return 1;
    if (FUN_00ce9e90(apSecond))
        return 1;
    return 0;
}

struct Item
{
    int unk00[11];
    int unk2c;
};
struct Container
{
    int unk00[2];
    Item** items;
    int unk0c;
    int unk10;
    intptr_t unk14;
    int unk18;
};
struct Counter
{
    int unk00[12];
    int unk30;
};
// Sets unk2c of every item in the container to value, increments counter->unk30 and passes the new count to AssignNodeFlags with c->unk14 and c->unk18.
// @fnv 0x00ce9fa0
void __cdecl FUN_00ce9fa0(Container* pContainer, int value, Counter* counter)
{
    for (int i = 0; i < pContainer->unk0c; ++i)
        pContainer->items[i]->unk2c = value;
    int count = ++counter->unk30;
    ::AssignNodeFlags((::Node **)(pContainer->unk14), pContainer->unk18, count);
}

struct Inner
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getSomething();
};

struct Obj
{
    char pad0[0xc];
    Inner* inner;
};

struct hkErrStream
{
    void* p1;
    void* p2;
    void* p3;
    hkErrStream(void* buf, int size) throw();
    ~hkErrStream() throw();
    hkErrStream& operator<<(const char* str) throw();
};

struct hkError
{
    virtual ~hkError() throw();
    virtual void unk0();
    virtual void unk1();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};


// Returns true if obj->inner->getSomething() is one of 0,1,2,6,7,8; otherwise optionally reports an unsupported-constraint error and returns false.
// @fnv 0x00ce9ba0
static bool IsSupportedRagdollConstraint(Obj* obj, bool reportError) throw()
{
    int val = obj->inner->getSomething();
    switch (val)
    {
    case 0:
    case 1:
    case 2:
    case 6:
    case 7:
    case 8:
        return true;
    default:
        break;
    }
    if (reportError)
    {
        unsigned int buf[128];
        hkErrStream stream(buf, 512);
        reinterpret_cast<::SinkOwner *>((void *)&(const ::hkErrStream &)(stream))->FUN_00cc01c0("Unsupported type of constraint in rag doll");
        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabbabf3b, (char*)buf, ".\\Utils\\hkaRagdollUtils.cpp", 129);
    }
    return false;
}

void caller(Obj* obj)
{
    IsSupportedRagdollConstraint(obj, true);
}

struct SpawnedAllocator
{
    virtual void* release();
    virtual void* allocate(int size);
};

struct SpawnedGlobal
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SpawnedAllocator* m_pAllocator;
};

SpawnedGlobal* __cdecl FUN_00c85750() throw();

struct SpawnedObject
{
    int unk00;
    unsigned short m_size04;
};

struct SourceRecord
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
    int m_i2c;
};

// Allocates a 0x30-byte SpawnedObject from the global allocator and initializes it from src's fields, returning Init's result.
// @fnv 0x00ce9ff0
intptr_t __cdecl SpawnObjectFromRecord(SourceRecord* pSourceRecord)
{
    SpawnedGlobal* holder = FUN_00c85750();
    SpawnedAllocator* pAllocator = holder->m_pAllocator;
    SpawnedObject* obj = (SpawnedObject*)pAllocator->allocate(0x30);
    obj->m_size04 = 0x30;
    int iValue = pSourceRecord->m_i2c;
    return ((intptr_t)(new ((void *)(obj)) ::FUN_00ce2510((intptr_t)(&pSourceRecord->unk08), (intptr_t)(&pSourceRecord->unk14), iValue, (::ObjectArray<int> *)(void *)(&pSourceRecord->unk20))));
}

struct Node
{
    int unk00, unk04, unk08, unk0c, unk10;
    void* source;
    void* destination;
};
template <class T> struct GameArray
{
    T* data;
    int count;
    int capacity;
    __forceinline void assign(const T* source, int size) throw();
};
typedef GameArray<void*> IntArray;
typedef GameArray<Node*> NodeArray;
struct HeapAllocator
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void* allocate(int* size);
    virtual void release(void* data, int size);
};
struct ScratchAllocator
{
    unsigned char* cursor;
    int unk04, unk08, unk0c;
    HeapAllocator* heap;
};
struct ScratchArray
{
    int* data;
    int count;
    unsigned int capacity;
    int* initial;
    __forceinline int& operator[](int index) throw()
    {
        return data[index];
    }
};
struct LogText
{
    int unk00, unk04, unk08;
    void FUN_00cb1600(void* storage, int length) throw();
    LogText(void* storage, int length) throw()
    {
        FUN_00cb1600(storage, length);
    }
    ~LogText() throw()
    {
        FUN_00cc00e0();
    }
    void FUN_00cc00e0() throw();
};
extern "C" const char DAT_010cbde0[];
extern "C" const char DAT_010cbdec[];
extern "C" const char DAT_010cbe00[];
struct BSAudio;
BSAudio* __cdecl _FUN_00c85750() throw();
static ScratchAllocator* scratchState() throw()
{
    return reinterpret_cast<ScratchAllocator*>(_FUN_00c85750());
}
static int* reserveScratch(int bytes) throw()
{
    ScratchAllocator* allocator = scratchState();
    int* result = reinterpret_cast<int*>(allocator->cursor);
    allocator->cursor += bytes;
    return result;
}
static __forceinline void reserveArray(HeapAllocator* allocator, ScratchArray* array, int size) throw()
{
    int capacity = array->capacity & 0x3fffffff;
    if (capacity < size)
    {
        int doubled = capacity * 2;
        int newCapacity = size < doubled ? doubled : size;
        ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(array), newCapacity, 4);
    }
}
static __forceinline void fillWords(int* destination, int value, int count) throw()
{
    for (int index = 0; index < count; ++index)
        *destination++ = value;
}
static __forceinline void clearAndFree(HeapAllocator* allocator, ScratchArray* array) throw()
{
    array->count = 0;
    if (!(array->capacity & 0x80000000))
        allocator->release(array->data, (array->capacity & 0x3fffffff) * 4);
    array->data = 0;
    array->capacity = 0x80000000;
}
struct LocalArray : ScratchArray
{
    LocalArray(int size, int bytes) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        int* allocation = reserveScratch(bytes);
        data = allocation;
        capacity = size | 0x80000000;
        initial = allocation;
    }
    LocalArray(int size, int* output) throw()
    {
        data = 0;
        count = 0;
        capacity = 0x80000000;
        ScratchAllocator* allocator = scratchState();
        int* allocation = reinterpret_cast<int*>(allocator->cursor);
        *output = (size * 4 + 127) & ~127;
        allocator->cursor += *output;
        data = allocation;
        capacity = size | 0x80000000;
        initial = allocation;
    }
    __forceinline void SetSizeAndGrow(int size, int value) throw()
    {
        reserveArray(scratchState()->heap, this, size);
        int num = size - count;
        int* destination = data + count;
        fillWords(destination, value, num);
        count = size;
    }
    __forceinline ~LocalArray() throw()
    {
        int* allocation = initial;
        if (allocation == data)
            count = 0;
        scratchState()->cursor = reinterpret_cast<unsigned char*>(allocation);
        clearAndFree(scratchState()->heap, this);
    }
};
static __forceinline void freeBuffer(HeapAllocator* allocator, void* data, unsigned int capacity) throw()
{
    if (!(capacity & 0x80000000))
        allocator->release(data, (capacity & 0x3fffffff) * 4);
}
template <class T> struct LocalBuffer
{
    T* data;
    int count;
    unsigned int capacity;
    LocalBuffer(int size, int bytes) throw()
    {
        count = size;
        data = reinterpret_cast<T*>(reserveScratch(bytes));
        capacity = size | 0x80000000;
    }
    __forceinline ~LocalBuffer() throw()
    {
        scratchState()->cursor = reinterpret_cast<unsigned char*>(data);
        freeBuffer(scratchState()->heap, data, capacity);
    }
    __forceinline T& operator[](int index) throw()
    {
        return data[index];
    }
};
template <class T> __forceinline void GameArray<T>::assign(const T* source, int size) throw()
{
    HeapAllocator* allocator = scratchState()->heap;
    int available = capacity & 0x3fffffff;
    if (available < size)
    {
        if (!(capacity & 0x80000000))
            allocator->release(data, available * 4);
        int bytes = size * 4;
        data = reinterpret_cast<T*>(allocator->allocate(&bytes));
        capacity = bytes / 4;
    }
    count = size;
    T* destination = data;
    for (int index = 0; index < size; ++index)
        destination[index] = source[index];
}

template <class T> static __forceinline void swapItems(T& first, T& second) throw()
{
    T temporary = first;
    first = second;
    second = temporary;
}
static int findNode(const IntArray* nodes, void* value)
{
    int count = nodes->count;
    for (int index = 0; index < count; ++index)
        if (nodes->data[index] == value)
            return index;
    return -1;
}
// Checks link count and endpoint membership, then orders nodes by successor-chain length and reorders links accordingly.
// @fnv 0x00cea030
extern "C" int __cdecl FUN_00cea030(void* apNodes, void* apLinks)
{
    IntArray* nodes = static_cast<IntArray*>(apNodes);
    NodeArray* links = static_cast<NodeArray*>(apLinks);
    int nodeCount = nodes->count;
    int linkCount = links->count;
    if (linkCount != nodeCount - 1)
    {
        int messageStorage[128];
        hkErrStream message(messageStorage, 512);
        reinterpret_cast<::SinkOwner *>((((::LogText *)&(reinterpret_cast<::CC0280Writer *>((((::LogText *)(reinterpret_cast<::SinkOwner *>((((::LogText *)&(reinterpret_cast<::CC0280Writer *>((((::LogText *)(reinterpret_cast<::SinkOwner *>((reinterpret_cast<LogText*>(&message)))->FUN_00cc01c0(DAT_010cbde0)))))->WriteInt(nodeCount - 1)))))->FUN_00cc01c0(DAT_010cbdec)))))->WriteInt(linkCount)))))->FUN_00cc01c0(DAT_010cbe00);
        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabba54bb, reinterpret_cast<const char*>(messageStorage), DAT_010cbd34, 0x144);
        return 1;
    }
    int nodeBytes;
    LocalArray linkPosition(nodeCount, &nodeBytes);
    linkPosition.SetSizeAndGrow(nodeCount, 0);
    LocalBuffer<int> permutation(nodeCount, nodeBytes);
    LocalArray successor(nodeCount, nodeBytes);
    successor.SetSizeAndGrow(nodeCount, -1);
    for (int edgeIndex = 0; edgeIndex < linkCount; ++edgeIndex)
    {
        Node* edge = links->data[edgeIndex];
        void* destination = edge->destination;
        void* source = edge->source;
        int sourceIndex = findNode(nodes, source);
        int targetIndex = findNode(nodes, destination);
        if (sourceIndex < 0 || targetIndex < 0)
            return 1;
        if (successor[sourceIndex] != -1 || linkPosition[sourceIndex] != 0)
            return 1;
        linkPosition[sourceIndex] = edgeIndex;
        successor[sourceIndex] = targetIndex;
    }
    {
        LocalArray chainDepth(nodeCount, nodeBytes);
        chainDepth.SetSizeAndGrow(nodeCount, 0);
        for (int index = 0; index < nodeCount; ++index)
        {
            for (int next = successor[index]; next != -1; next = successor[next])
                ++chainDepth[index];
        }
        for (int index = 0; index < nodeCount; ++index)
            permutation[index] = index;
        for (int left = 0; left < nodeCount - 1; ++left)
        {
            for (int right = left + 1; right < nodeCount; ++right)
            {
                if (chainDepth[left] > chainDepth[right])
                {
                    swapItems(chainDepth[left], chainDepth[right]);
                    swapItems(permutation[left], permutation[right]);
                }
            }
        }
    }
    LocalBuffer<void*> sortedNodes(nodeCount, nodeBytes);
    LocalBuffer<Node*> sortedEdges(linkCount, (linkCount * 4 + 127) & ~127);
    for (int index = 0; index < nodeCount; ++index)
    {
        int original = permutation[index];
        sortedNodes[index] = nodes->data[original];
        if (index > 0)
        {
            int position = linkPosition[original];
            if (position >= 0)
                sortedEdges[index - 1] = links->data[position];
            else
                sortedEdges[index - 1] = 0;
        }
    }
    nodes->assign(sortedNodes.data, nodeCount);
    links->assign(sortedEdges.data, linkCount);
    return 0;
}

namespace fnv_00ceaf60 {
struct HeapAllocator
{
    virtual void slot0();
    virtual void* AllocateMemoryBlock(int bytes) throw();
    virtual void slot2();
    virtual void* allocate(int* bytes) throw();
    virtual void release(void* data, int bytes) throw();
};
struct ScratchAllocator
{
    unsigned char* cursor;
    int unk04, unk08, unk0c;
    HeapAllocator* heap;
};
static ScratchAllocator* scratchState() throw()
{
    return reinterpret_cast<ScratchAllocator*>(FUN_00c85750());
}
template <class T> static __forceinline T* allocateBuffer(HeapAllocator* allocator, int& count) throw()
{
    if (count)
    {
        int bytes = count * sizeof(T);
        T* data = (T*)allocator->allocate(&bytes);
        count = bytes / sizeof(T);
        return data;
    }
    return 0;
}
static __forceinline void freeBuffer(HeapAllocator* allocator, void* data, int capacity) throw()
{
    if (!(capacity & 0x80000000))
        allocator->release(data, capacity & 0x3fffffff);
}
static __forceinline char& maskAt(char* const& data, int index) throw()
{
    return data[index];
}
template <class T> struct ArrayBase
{
    T* data;
    int size;
    int capacity;
    __forceinline ArrayBase() throw()
    {
        data = 0;
        size = 0;
        capacity = 0x80000000;
    }
    __forceinline ArrayBase(int count) throw()
    {
        int allocatedCount = count;
        data = allocateBuffer<T>(scratchState()->heap, allocatedCount);
        capacity = allocatedCount ? allocatedCount : 0x80000000;
        size = count;
    }
    __forceinline int GetLogicalSize() const throw()
    {
        return size;
    }
    __forceinline T& operator[](int index) throw()
    {
        return data[index];
    }
    __forceinline const T& operator[](int index) const throw()
    {
        return data[index];
    }
    __forceinline void AddBack(HeapAllocator* allocator, const T& value) throw()
    {
        if (size == (capacity & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(allocator), (::AudioStream *)(void *)(this), sizeof(T));
        data[size] = value;
        ++size;
    }
    __forceinline void ClearAndRelease(HeapAllocator* allocator) throw()
    {
        size = 0;
        if (!(capacity & 0x80000000))
            allocator->release(data, (capacity & 0x3fffffff) * sizeof(T));
        data = 0;
        capacity = 0x80000000;
    }
};
template <class T> struct Array : ArrayBase<T>
{
    __forceinline Array() throw()
    {}
    __forceinline Array(int count) throw() : ArrayBase<T>(count)
    {}
    __forceinline void clear() throw()
    {
        ClearAndRelease(scratchState()->heap);
    }
    __forceinline void AddBack(const T& value) throw()
    {
        ArrayBase<T>::AddBack(scratchState()->heap, value);
    }
};
struct RigidBody;
struct Constraint;
struct Skeleton
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int boneCount;
};
struct Ragdoll
{
    unsigned int unk00;
    unsigned short memorySizeAndFlags, referenceCount;
    ArrayBase<RigidBody*> bodies;
    ArrayBase<Constraint*> constraints;
    ArrayBase<int> boneMap;
    Skeleton* skeleton;
    __forceinline Skeleton* getSkeleton() const throw()
    {
        return skeleton;
    }
    __forceinline RigidBody* getBody(int bone) const throw()
    {
        int mapped = boneMap[bone];
        return mapped < 0 ? 0 : bodies[mapped];
    }
    __forceinline Constraint* GetConstraintForBone(int bone) const throw()
    {
        int mapped = boneMap[bone];
        return --mapped < 0 ? 0 : constraints[mapped];
    }
};
// Splits a Ragdoll into two output Ragdolls by partitioning bones into hierarchy descendants of source and the rest.
// @fnv 0x00ceaf60
void __cdecl FUN_00ceaf60(Ragdoll* original, int aiSourceBone, Ragdoll** first, Ragdoll** second)
{
    Ragdoll** outputs[2];
    outputs[0] = first;
    outputs[1] = second;
    const char selectors[2] = {0, 1};
    int maskCount = original->skeleton->boneCount;
    char* mask = allocateBuffer<char>(scratchState()->heap, maskCount);
    int maskCapacity = maskCount ? maskCount : 0x80000000;
    ::MarkHierarchyDescendants((::Hierarchy *)(original->skeleton), aiSourceBone, (unsigned char *)(mask), 1);
    for (int partition = 0; partition < 2; ++partition)
    {
        Array<RigidBody*> bodies;
        Array<Constraint*> constraints;
        Array<int> remap;
        for (int bone = 0; bone < original->skeleton->boneCount; ++bone)
        {
            if (maskAt(mask, bone) != selectors[partition])
            {
                remap.AddBack(-1);
                continue;
            }
            RigidBody* body = original->getBody(bone);
            Constraint* constraint = original->GetConstraintForBone(bone);
            if (!body)
            {
                remap.AddBack(-1);
                continue;
            }
            remap.AddBack(bodies.GetLogicalSize());
            bodies.AddBack(body);
            if (bone != aiSourceBone && bone != 0)
                constraints.AddBack(constraint);
        }
        Ragdoll* result = (Ragdoll*)scratchState()->heap->AllocateMemoryBlock(0x30);
        result->memorySizeAndFlags = 0x30;
        result = ((::fnv_00ceaf60::Ragdoll *)(new ((void *)(result)) ::FUN_00ce2510((intptr_t)&(bodies), (intptr_t)&(constraints), (intptr_t)(original->getSkeleton()), (::ObjectArray<int> *)&(remap))));
        *outputs[partition] = result;
        HeapAllocator* allocator = scratchState()->heap;
        remap.size = 0;
        if (!(remap.capacity & 0x80000000))
            allocator->release(remap.data, (remap.capacity & 0x3fffffff) * 4);
        remap.data = 0;
        remap.capacity = 0x80000000;
        constraints.clear();
        bodies.clear();
    }
    freeBuffer(scratchState()->heap, mask, maskCapacity);
}
}  // namespace fnv_00ceaf60

extern "C" void _ReadWriteBarrier();

#include "fnv/symbols_simd.h"


struct hkBoolR
{
    char m_cBooleanValue;
    hkBoolR()
    {}
    hkBoolR(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class ScalarValue
{
    __m128 m_uiFilterValue;

  public:
    ScalarValue()
    {}
    ScalarValue(const __m128& a) : m_uiFilterValue(a)
    {}
    __forceinline const __m128& getQuad() const
    {
        return m_uiFilterValue;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_uiFilterValue, m_uiFilterValue, 0);
    }
};
struct hkQuaternion;
struct hkXform;
class hkVec4
{
    __m128 m_vComponents;

  public:
    operator __m128() const
    {
        return m_vComponents;
    }
    __forceinline __m128& getQuad();
    __forceinline const __m128& getQuad() const;
    void operator=(const hkVec4& a);
    void operator=(const __m128& a);
    void setAdd4(const hkVec4& a, const hkVec4& b);
    void setMul4(const hkVec4& a, const hkVec4& b);
    void setAddMul4(const hkVec4& a, const hkVec4& b, const hkVec4& c);
    void addMul4(const hkVec4& a, const hkVec4& b);
    void addMul4(const ScalarValue& a, const hkVec4& b);
    void setNeg4(const hkVec4& a);
    void setNeg3(const hkVec4& a);
    void setCross(const hkVec4& a, const hkVec4& b);
    ScalarValue dot3(const hkVec4& a) const;
    ScalarValue scalarAt(int i) const;
    void SetAllComponents(const ScalarValue& a);
    void sub4(const hkVec4& a);
    void setXYZW(const hkVec4& xyz, const hkVec4& w);
    void setBroadcast(const hkVec4& a, int i);
    void broadcast(int i);
    void setReciprocal4(const hkVec4& a);
    void setReciprocal3(const hkVec4& a);
    void setXYZ0(const hkVec4& a);
    void SetRotatedDirection(const hkQuaternion& a, const hkVec4& b);
    void setRotatedInverseDir(const hkQuaternion& a, const hkVec4& b);
};
struct hkQuaternion
{
    hkVec4 m_vec;
    const hkVec4& getImag() const;
    void SetConjugate(const hkQuaternion& a);
    inline void FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b);
};
inline const hkVec4& hkQuaternion::getImag() const
{
    return m_vec;
}
inline void hkQuaternion::SetConjugate(const hkQuaternion& a)
{
    m_vec.setNeg3(a.getImag());
}
inline __m128& hkVec4::getQuad()
{
    return m_vComponents;
}
inline const __m128& hkVec4::getQuad() const
{
    return m_vComponents;
}
inline void hkVec4::operator=(const hkVec4& a)
{
    m_vComponents = a.m_vComponents;
}
inline void hkVec4::operator=(const __m128& a)
{
    getQuad() = a;
}
inline void hkVec4::setAdd4(const hkVec4& a, const hkVec4& b)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVec4::setMul4(const hkVec4& a, const hkVec4& b)
{
    m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
}
inline void hkVec4::setAddMul4(const hkVec4& a, const hkVec4& b, const hkVec4& c)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(b.m_vComponents, c.m_vComponents));
}
inline void hkVec4::addMul4(const hkVec4& a, const hkVec4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
}
inline void hkVec4::addMul4(const ScalarValue& a, const hkVec4& b)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.broadcast(), b.m_vComponents));
}
inline void hkVec4::setNeg4(const hkVec4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, ::DAT_010c44d0);
}
inline void hkVec4::setNeg3(const hkVec4& a)
{
    m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c4c00);
}
inline void hkVec4::setCross(const hkVec4& a, const hkVec4& b)
{
    __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 201),
                              _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 210));
    __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 210),
                               _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 201));
    m_vComponents = _mm_sub_ps(first, second);
}
inline ScalarValue hkVec4::dot3(const hkVec4& a) const
{
    __m128 products = _mm_mul_ps(m_vComponents, a.m_vComponents);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 85), products);
    return _mm_add_ss(_mm_shuffle_ps(products, products, 170), xy);
}
inline void hkVec4::setBroadcast(const hkVec4& a, int i)
{
    if (i == 0)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0);
    else if (i == 1)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 85);
    else if (i == 2)
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 170);
    else
        m_vComponents = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 255);
}
inline void hkVec4::broadcast(int i)
{
    setBroadcast(*this, i);
}
static inline __m128 reciprocalQuad(__m128 a)
{
    __m128 estimate = _mm_rcp_ps(a);
    return _mm_sub_ps(_mm_add_ps(estimate, estimate), _mm_mul_ps(_mm_mul_ps(estimate, a), estimate));
}
inline void hkVec4::setReciprocal4(const hkVec4& a)
{
    m_vComponents = reciprocalQuad(a.m_vComponents);
}
__forceinline void hkVec4::SetRotatedDirection(const hkQuaternion& a, const hkVec4& b)
{
    hkVec4 half;
    half.getQuad() = ::DAT_010c71e0;
    hkVec4 real;
    real.setBroadcast(a.m_vec, 3);
    hkVec4 factor;
    factor.setAddMul4(half, real, real);
    hkVec4 result;
    result.setMul4(b, factor);
    hkVec4 dot;
    dot.getQuad() = a.getImag().dot3(b).getQuad();
    dot.broadcast(0);
    result.addMul4(dot, a.getImag());
    hkVec4 cross;
    cross.setCross(a.getImag(), b);
    result.addMul4(real, cross);
    setAdd4(result, result);
}
__forceinline void hkVec4::setRotatedInverseDir(const hkQuaternion& a, const hkVec4& b)
{
    hkVec4 half;
    half.getQuad() = ::DAT_010c71e0;
    hkVec4 real;
    real.setBroadcast(a.m_vec, 3);
    hkVec4 factor;
    factor.setAddMul4(half, real, real);
    hkVec4 result;
    result.setMul4(b, factor);
    hkVec4 dot;
    dot.getQuad() = a.getImag().dot3(b).getQuad();
    dot.broadcast(0);
    result.addMul4(dot, a.getImag());
    hkVec4 cross;
    cross.setCross(b, a.getImag());
    result.addMul4(real, cross);
    setAdd4(result, result);
}

inline ScalarValue hkVec4::scalarAt(int i) const
{
    switch (i)
    {
    case 0:
        return getQuad();
    case 1:
        return _mm_shuffle_ps(getQuad(), getQuad(), 85);
    case 2:
        return _mm_shuffle_ps(getQuad(), getQuad(), 170);
    default:
        return _mm_shuffle_ps(getQuad(), getQuad(), 255);
    }
}
inline void hkVec4::SetAllComponents(const ScalarValue& a)
{
    getQuad() = a.broadcast();
}
inline void hkVec4::sub4(const hkVec4& a)
{
    getQuad() = _mm_sub_ps(getQuad(), a.getQuad());
}
inline void hkVec4::setXYZW(const hkVec4& xyz, const hkVec4& w)
{
    getQuad() = _mm_shuffle_ps(xyz.getQuad(), _mm_unpackhi_ps(xyz.getQuad(), w.getQuad()), 196);
}
inline void hkQuaternion::FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b)
{
    hkVec4 cross;
    cross.setCross(a.getImag(), b.getImag());
    cross.addMul4(a.m_vec.scalarAt(3), b.getImag());
    cross.addMul4(b.m_vec.scalarAt(3), a.getImag());
    hkVec4 projection;
    projection.SetAllComponents(a.m_vec.dot3(b.m_vec));
    hkVec4 product;
    product.setMul4(a.m_vec, b.m_vec);
    product.sub4(projection);
    m_vec.setXYZW(cross, product);
}

inline void hkVec4::setReciprocal3(const hkVec4& a)
{
    hkVec4 one;
    one.getQuad() = DAT_010c7170;
    hkVec4 combined;
    combined.setXYZW(a, one);
    setReciprocal4(combined);
}
inline void hkVec4::setXYZ0(const hkVec4& a)
{
    m_vComponents = _mm_and_ps(a, DAT_010c4c10);
}
struct hkQsXform
{
    hkVec4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVec4 m_vScale;

    hkBoolR FUN_00ce5120(const hkQsXform& other, float eps) const;

    __forceinline void SetProduct(const hkQsXform& t1, const hkQsXform& t2)
    {
        hkVec4 extra;
        extra.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(t1.m_vTranslation, extra);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), (void *)&(t1.m_rotation), (const __m128 *)&(t2.m_rotation), {});
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
    __forceinline void SetConjugate(const hkQsXform& t)
    {

        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVec4 reciprocal;
        reciprocal.setReciprocal3(t.m_vScale);
        m_vScale.setXYZ0(reciprocal);
    }
};

struct hkXform
{
    hkVec4 m_kColumn0;
    hkVec4 m_kColumn1;
    hkVec4 m_kColumn2;
    hkVec4 m_vTranslation;
};

struct MassA
{
    void* unk00;
    void* unk04;
    unsigned char unk08, unk09, unk0a, unk0b;
};
struct MassB
{
    hkVec4 unk00;
};
struct ErrorIface
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void SetErrorCodeEnabled(int id, hkBoolR enabled);
    virtual hkBoolR isEnabled(int id);
};
struct ShapeObj
{
    int unk00;
    unsigned short m_usMemSizeAndFlags;
};
struct Body
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void SetCollisionShapeAndKey(ShapeObj* shape);
    void* m_pCollisionShape;
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
    char m_bFlag;
    int unkec;
    hkXform m_kMotionTransform;
    hkVec4 m_vCenterOfMass0;
    hkVec4 m_vCenterOfMass1;
};


struct MemoryRouter : SpawnedGlobal
{
    __forceinline SpawnedAllocator& heap()
    {
        return *m_pAllocator;
    }
};

static __forceinline ErrorIface* GetError()
{
    return (ErrorIface*)(*reinterpret_cast<::hkError * *>(&::DAT_01268360));
}

// @fnv 0x00ce9880
static __declspec(noinline) int FUN_00ce9880(const hkQsXform& t, Body* body)
{
    if (t.FUN_00ce5120((*reinterpret_cast<::hkQsXform *>(&::DAT_01268700)), ::AngularDashpotApplyD4DCB0::DAT_01017d00).m_cBooleanValue == 0)
    {
        hkQsXform bodyQs;
        reinterpret_cast<::S_00ce5070_QsTransform *>(&(bodyQs))->FUN_00ce5070((*(const ::S_00ce5070_Transform *)(&body->m_kMotionTransform)));

        hkQsXform combined;
        combined.SetProduct(bodyQs, t);
        hkQsXform inv;
        inv.SetConjugate(t);
        hkVec4 com = body->m_vCenterOfMass1;
        hkBoolR bErrorEnabled = GetError()->isEnabled(0x2ff8c16f);
        GetError()->SetErrorCodeEnabled(0x2ff8c16f, false);
        hkXform kXform;
        {
            void* shape = body->m_pCollisionShape;
            reinterpret_cast<::FUN_00ce50b0_cls *>((void *)&(inv))->FUN_00ce50b0((::CB2FC0Object *)(void *)(&kXform));
            ShapeObj* pShapeObj = (ShapeObj*)((MemoryRouter*)FUN_00c85750())->heap().allocate(0x70);
            pShapeObj->m_usMemSizeAndFlags = 0x70;
            ShapeObj* pTransformedShape = ((::ShapeObj *)(reinterpret_cast<::cf5990_TransformShape *>((pShapeObj))->FUN_00cf5990((::hkpShape *)(shape), (const ::hkTransform &)(kXform))));
            body->SetCollisionShapeAndKey(pTransformedShape);
            reinterpret_cast<::hkReferencedObjectC905 *>((pTransformedShape))->FUN_00c905b0();
        }
        {
            MassA a;
            new ((void *)&(a)) ::FUN_00d733e0();
            MassB b;
            new ((void *)&(b)) ::FUN_00d73410();
            ::FUN_00d748d0((::hkpEntityD748 *)(body), (intptr_t)(&a), (intptr_t)(&b));
        }
        GetError()->SetErrorCodeEnabled(0x2ff8c16f, bErrorEnabled);
        reinterpret_cast<::FUN_00ce50b0_cls *>((void *)&(combined))->FUN_00ce50b0((::CB2FC0Object *)(void *)(&kXform));
        reinterpret_cast<::CA8890Object *>((body))->FUN_00ca8890((intptr_t)&(kXform));
        if (body->m_bFlag != 5)
        {
            hkVec4 lc;
            reinterpret_cast<::FUN_00c7f690_cls *>(&(lc))->FUN_00c7f690((const ::S_00c7f690_M *)&(kXform), (const ::S_00c7f690_V *)&(com));
            reinterpret_cast<::Owner *>((body))->FUN_00ca85f0((uintptr_t)&(lc));
        }
    }
    return 0;
}
volatile intptr_t g_inT;
volatile intptr_t g_inBody;
volatile int g_out;
void CallTarget_ce9880()
{
    g_out = FUN_00ce9880(*(const hkQsXform*)g_inT, (Body*)g_inBody);
}

static bool IsSupportedRagdollConstraint(Obj* obj, bool reportError) throw();


struct Vec4
{
    float x, y, z, w;
};
struct PivotVec;
struct __declspec(align(16)) V4A
{
    float x, y, z, w;
};
struct __declspec(align(16)) Qs
{
    V4A translation;
    V4A rotation;
    V4A scale;
};

struct Shape
{
    virtual int v0();
    virtual int v1();
};

struct List
{
    Body** items;
    int count;
};

static __declspec(noinline) Vec4* FUN_00ce9c40(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    return (Vec4*)((char*)inner + (t <= 8 ? 0x20 : 0x50));
}

struct A1W
{
    List* p;
    A1W(List* q) : p(q)
    {}
};
struct __declspec(align(16)) PivotVec
{
    float x, y, z, w;
    __m128 quad() const
    {
        return _mm_load_ps(&x);
    }
    void setQuad(__m128 q)
    {
        _mm_store_ps(&x, q);
    }
    void operator=(const PivotVec& v)
    {
        setQuad(v.quad());
    }
    void SetAllComponents(float a)
    {
        setQuad(_mm_set_ps1(a));
    }
    float lengthSquared3() const
    {
        __m128 x2 = _mm_mul_ps(quad(), quad());
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        float r;
        _mm_store_ss(&r, _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum));
        return r;
    }
};

struct __declspec(align(16)) PivotXform
{
    PivotVec m_vTranslation;
    PivotVec m_rotation;
    PivotVec m_vScale;
};

// @fnv 0x00ce9db0
int __cdecl FUN_00ce9db0(A1W constraints, void* warnOnAlignment)
{
    const int numConstraints = constraints.p->count;
    int result = 0;
    for (int c = 0; c < numConstraints; c++)
    {
        Body* constraint = constraints.p->items[c];
        if (!IsSupportedRagdollConstraint(constraint, true))
        {
            result = 1;
            continue;
        }
        PivotVec pivotInA = *(const PivotVec*)FUN_00ce9c40(constraint);
        Shape* shape = constraint->shape;
        PivotXform childFromConstraint;
        childFromConstraint.m_rotation = *(const PivotVec*)&DAT_010c71b0;
        childFromConstraint.m_vScale.SetAllComponents(::DAT_01012068);
        childFromConstraint.m_vTranslation = pivotInA;
        if (childFromConstraint.m_vTranslation.lengthSquared3() > DAT_010959f4)
        {
            if (FUN_00ce9880((Qs*)&childFromConstraint, shape) != 0)
                result = 1;
        }
    }
    return result;
}struct StringRef
{
    const char* text;
    StringRef() throw()
    {
        new ((void *)this) struct ::FUN_00cb0a60();
    }
};
struct Bone
{
    StringRef name;
    bool lockTranslation;
};
struct Quaternion
{
    __m128 value;
    __forceinline const __m128& getVector() const
    {
        return value;
    }
    __declspec(noinline) void FUN_00c66320(const Quaternion*, const Quaternion*) throw();
};
struct Transform
{
    __m128 translation;
    __forceinline const __m128& getTranslation() const
    {
        return translation;
    }
    Quaternion rotation;
    __m128 scale;
    __forceinline const __m128& getScale() const
    {
        return scale;
    }
};
struct SimdVector
{
    __m128 quad;
    __forceinline SimdVector()
    {}
    __forceinline SimdVector(__m128 inputValue) : quad(inputValue)
    {}
    __forceinline operator __m128() const
    {
        return quad;
    }
};
static __forceinline void composeTransforms(Transform& destination, const Transform& parent, const Transform& child)
{
    SimdVector qForward = parent.rotation.value;
    SimdVector wForward = _mm_shuffle_ps(qForward, qForward, 0xff);
    SimdVector vForward = child.translation;
    __m128 dotForward = _mm_mul_ps(vForward, qForward);
    __m128 dForward = _mm_add_ss(_mm_shuffle_ps(dotForward, dotForward, 0x55), dotForward);
    dForward = _mm_add_ss(_mm_shuffle_ps(dotForward, dotForward, 0xaa), dForward);
    __m128 crossForward =
        _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(qForward, qForward, 0xc9), _mm_shuffle_ps(vForward, vForward, 0xd2)),
                   _mm_mul_ps(_mm_shuffle_ps(qForward, qForward, 0xd2), _mm_shuffle_ps(vForward, vForward, 0xc9)));
    __m128 tForward = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(wForward, wForward), DAT_010c71e0), vForward);
    crossForward = _mm_mul_ps(crossForward, wForward);
    tForward = _mm_add_ps(tForward, _mm_mul_ps(_mm_shuffle_ps(dForward, dForward, 0), qForward));
    tForward = _mm_add_ps(crossForward, tForward);
    destination.translation = _mm_add_ps(_mm_add_ps(tForward, tForward), parent.translation);
    ::fnv_00c66320::FUN_00c66320((__m128 *)&(destination.rotation), (void *)(&parent.rotation), (const __m128 *)(const ::Quaternion *)(&child.rotation), {});
    destination.scale = _mm_mul_ps(child.scale, parent.scale);
}
template <class T> struct Array
{
    T* data;
    int size;
    int capacity;
    Array() throw() : data(0), size(0), capacity(0x80000000)
    {}
    void reserve(SpawnedAllocator* allocator, int count) throw()
    {
        int available = capacity & 0x3fffffff;
        if (available < count)
        {
            int grown = available * 2;
            if (count >= grown)
                grown = count;
            ::FUN_00c908c0((::SpawnedObject *)(allocator), (::SpawnedArray *)(void *)(this), grown, sizeof(T));
        }
    }
    void reserve(int count) throw()
    {
        SpawnedGlobal* holder = FUN_00c85750();
        reserve(holder->m_pAllocator, count);
    }
    void resize(int count) throw()
    {
        reserve(count);
        size = count;
    }
    __forceinline void SetSizeAndGrow(int count) throw();
};
static __forceinline void destroyBones(Bone* bone, int count) throw()
{
    for (int i = 0; i < count; ++i)
    {
        ::FUN_00cb0c00((intptr_t)(bone));
        ++bone;
    }
}
static __forceinline void constructBones(Bone* bone, int count) throw()
{
    for (int i = 0; i < count; ++i, ++bone)
    {
        if (bone)
        {
            new ((void *)&(bone->name)) struct ::FUN_00cb0a60();
            bone->lockTranslation = false;
        }
    }
}
template <> __forceinline void Array<Bone>::SetSizeAndGrow(int count) throw()
{
    reserve(count);
    destroyBones(data + count, size - count);
    constructBones(data + size, count - size);
    size = count;
}
struct SkeletonHeader
{
    const void* vtable;
    unsigned short memorySize;
    unsigned short references;
    __forceinline SkeletonHeader() throw() : references(1), memorySize(0x48)
    {
        vtable = &(*reinterpret_cast<unsigned int *>(&::DAT_010c4dec));
    }
};
struct Skeleton : SkeletonHeader
{
    StringRef name;
    Array<short> parents;
    Array<Bone> bones;
    Array<Transform> pose;
    Array<StringRef> floatSlots;
    Array<int> localFrames;
    __forceinline Skeleton() throw()
    {}
    __forceinline void* operator new(std::size_t bytes)
    {
        SpawnedGlobal* holder = FUN_00c85750();
        SpawnedAllocator* allocator = holder->m_pAllocator;
        Skeleton* result = static_cast<Skeleton*>(allocator->allocate(bytes));
        result->memorySize = static_cast<unsigned short>(bytes);
        return result;
    }
};
struct RigidBody
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
    const char* name;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
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
    Transform transform;
};
struct BodyList
{
    RigidBody** data;
    int size;
    int capacity;
};
struct Constraint
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    RigidBody* parent;
};
struct ConstraintList
{
    Constraint** data;
    int size;
    int capacity;
};

// @fnv 0x00ceb2c0
Skeleton* __cdecl FUN_00ceb2c0(BodyList* bodies, ConstraintList* constraints) throw()
{
    Skeleton* result = new Skeleton;
    int count = bodies->size;
    result->bones.SetSizeAndGrow(count);
    result->parents.resize(count);
    result->pose.resize(count);
    for (int i = 0; i < count; ++i)
    {
        int parentIndex = -1;
        if (i)
        {
            RigidBody* parent = constraints->data[i - 1]->parent;
            for (int j = 0; j < i; ++j)
            {
                if (bodies->data[j] == parent)
                {
                    parentIndex = j;
                    break;
                }
            }
        }
        result->parents.data[i] = (short)parentIndex;
        RigidBody* body = bodies->data[i];
        Bone& currentBone = result->bones.data[i];
        if (parentIndex >= 0)
        {
            RigidBody* parent = bodies->data[parentIndex];
            Transform childPose, parentPose;
            reinterpret_cast<::S_00ce5070_QsTransform *>(&(childPose))->FUN_00ce5070((*(const ::S_00ce5070_Transform *)(&body->transform)));
            reinterpret_cast<::S_00ce5070_QsTransform *>(&(parentPose))->FUN_00ce5070((*(const ::S_00ce5070_Transform *)(&parent->transform)));
            Transform& output = result->pose.data[i];
            const __m128& q = parentPose.rotation.value;
            SimdVector w = _mm_shuffle_ps(q, q, 0xff);
            SimdVector v = parentPose.getTranslation();
            SimdVector dot = _mm_mul_ps(q, v);
            SimdVector d = _mm_add_ss(_mm_shuffle_ps(dot, dot, 0x55), dot);
            d = _mm_add_ss(_mm_shuffle_ps(dot, dot, 0xaa), d);
            __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xc9), _mm_shuffle_ps(q, q, 0xd2)),
                                      _mm_mul_ps(_mm_shuffle_ps(v, v, 0xd2), _mm_shuffle_ps(q, q, 0xc9)));
            cross = _mm_mul_ps(cross, w);
            SimdVector t = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(w, w), DAT_010c71e0), v);
            t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(d, d, 0), q));
            t = _mm_add_ps(cross, t);
            Transform inversePose;
            t = _mm_add_ps(t, t);
            t = _mm_xor_ps(t, DAT_010c44d0);
            inversePose.translation = t;
            inversePose.rotation.value = _mm_xor_ps(q, ::DAT_010c4c00);
            __m128 scale = parentPose.scale;
            __m128 scaleWithOne = _mm_shuffle_ps(scale, _mm_unpackhi_ps(scale, ::DAT_010c7170), 0xc4);
            __m128 reciprocal = _mm_rcp_ps(scaleWithOne);
            __m128 inverseScale = _mm_and_ps(_mm_sub_ps(_mm_add_ps(reciprocal, reciprocal),
                                                        _mm_mul_ps(_mm_mul_ps(reciprocal, scaleWithOne), reciprocal)),
                                             ::DAT_010c4c10);
            inversePose.scale = inverseScale;
            composeTransforms(output, inversePose, childPose);
        }
        else
        {
            reinterpret_cast<::S_00ce5070_QsTransform *>(&(result->pose.data[i]))->FUN_00ce5070((*(const ::S_00ce5070_Transform *)(&body->transform)));
        }
        const char* name = reinterpret_cast<const char*>(reinterpret_cast<uintptr_t>(body->name) & ~1u);
        if (name)
            reinterpret_cast<::SStringPtr *>(&(currentBone.name))->FUN_00cb0c10(name);
        else
        {
            int buffer[128];
            hkErrStream stream(buffer, 512);
            reinterpret_cast<::SinkOwner *>((void *)&(const ::hkErrStream &)(stream))->FUN_00cc01c0("Rigid Body name could not be found");
            (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabbacc14, reinterpret_cast<const char*>(buffer), ".\\Utils\\hkaRagdollUtils.cpp",
                                  558);
        }
        currentBone.lockTranslation = i != 0;
    }
    if (result->bones.size > 0)
        reinterpret_cast<::Cb0StringCopy *>(&(result->name))->FUN_00cb0c30((*(const ::CB0StringPtr *)(result->bones.data)));
    return result;
}

struct InnerShape
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
    virtual void unk7();
    virtual int getType();
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
};
struct ShapeOwner
{
    int unk00;
    int unk04;
    int unk08;
    InnerShape* inner;
};
extern char str_010cbd50[];

// @fnv 0x00ce9c40
static __declspec(noinline) void* FUN_00ce9c40(ShapeOwner* owner)
{
    InnerShape* shape = owner->inner;
    switch (shape->getType())
    {
    case 0:
        return &shape->unk20;
    case 1:
        return &shape->unk50;
    case 2:
        return &shape->unk50;
    case 6:
        return &shape->unk50;
    case 7:
        return &shape->unk50;
    case 8:
        return &shape->unk20;
    default: {
        char buf[0x200];
        hkErrStream os(buf, sizeof(buf));
        reinterpret_cast<::SinkOwner *>((void *)&(const ::hkErrStream &)(os))->FUN_00cc01c0(str_010cbd50);
        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabbabf3b, buf, ::DAT_010cbd34, 0xb4);
    }
        return 0;
    }
}

struct Builder390
{
    unsigned int unk00, unk04, unk08;
};
struct Constraint390
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned int GetType();
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
};
struct Owner390
{
    unsigned int unk00, unk04, unk08;
    Constraint390* data;
};
// @fnv 0x00ce9cf0
static __declspec(noinline) void* FUN_00ce9cf0(Owner390* owner)
{
    Constraint390* data = owner->data;
    switch (data->GetType())
    {
    case 0:
        return &data->unk30;
    case 1:
        return &data->unk90;
    case 2:
        return &data->unk90;
    case 6:
        return &data->unk90;
    case 7:
        return &data->unk90;
    case 8:
        return &data->unk20;
    case 3:
    case 4:
    case 5:
    default: {
        char message[512];
        Builder390 stream;
        new ((void *)&(stream)) ::FUN_00cb1600(message, sizeof(message));
        reinterpret_cast<::SinkOwner *>(&(stream))->FUN_00cc01c0("Unsupported type of constraint in rag doll.");
        (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabbabf3b, message, ".\\Utils\\hkaRagdollUtils.cpp", 230);
        reinterpret_cast<struct ::FUN_00cc00e0 *>(&(stream))->FUN_00cc00e0::~FUN_00cc00e0();
        return 0;
    }
    }
}__declspec(align(16)) struct Vec4
{
    int x;
    int y;
    int z;
    int w;
};

struct Target
{
};

static __declspec(noinline) Target* FUN_00ce9cf0(Obj* obj) throw()
{
    Inner* inner = obj->inner;
    int t = inner->getSomething();
    if (t <= 8)
        return (Target*)((char*)inner + 0x30);
    return 0;
}

// @fnv 0x00ce9e90
extern "C" int __cdecl FUN_00ce9e90(void* p)
{
    List* list = (List*)p;
    int count = list->count;
    for (int i = 0; i < count; i++)
    {
        Body* b = list->items[i];
        if (IsSupportedRagdollConstraint(b, true))
        {
            char* shape = b->shape;
            char* owner = b->owner;
            Vec4 v = *(Vec4*)(shape + 0x120);
            Vec4* vel = FUN_00ce9c40(b);
            *(__m128*)vel = _mm_setzero_ps();
            Target* target = FUN_00ce9cf0(b);
            reinterpret_cast<::FUN_00c7f690_cls *>((target))->FUN_00c7f690((const ::S_00c7f690_M *)(void *)(owner + 0xf0), (const ::S_00c7f690_V *)(::Vec4 *)(&v));
        }
        if (b->inner->getSomething() == 8)
        {
            int buf[0x80];
            hkErrStream stream(buf, 0x200);
            reinterpret_cast<::SinkOwner *>((void *)&(const ::hkErrStream &)(stream))->FUN_00cc01c0("Unusual : Aligning constraint spaces of a stiff spring.");
            (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabba876d, (const char*)buf, ".\\Utils\\hkaRagdollUtils.cpp", 0x134);
        }
    }
    return 0;
}

#include "generated/data/havok/animation/ragdoll/utils/hkaragdollutils.inc"
