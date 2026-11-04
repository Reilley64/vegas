
// src/havok/physics/collide/shape/deprecated/storagemesh/hkpstoragemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/storagemesh/hkpstoragemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <xmmintrin.h>
#include <new>
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/hkpPhysicsSystemD29.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_01267000.h"
#include "havok/hkpStorageMeshShape.h"


class hkVector4D4B
{
  public:
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4D4B& v)
    {
        m_vComponents = v.m_vComponents;
    }
};



template <class T> __forceinline void copyD4B(T* pDst, const T* pSrc, int n)
{
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

template <class T> class hkArrayD4B
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD4B() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }

    __forceinline hkArrayD4B& operator=(const hkArrayD4B& a)
    {
        hkMemoryAllocator& kHeap = hkMemoryRouter::getInstance().heap();
        if (getCapacity() < a.m_iElementCount)
        {
            if ((m_iCapacityState & 0x80000000) == 0)
                kHeap.bufFree(m_data, getCapacity() * sizeof(T));
            int iNumBytes = a.m_iElementCount * sizeof(T);
            m_data = static_cast<T*>(kHeap.bufAlloc(iNumBytes));
            m_iCapacityState = iNumBytes / static_cast<int>(sizeof(T));
        }
        m_iElementCount = a.m_iElementCount;
        copyD4B<T>(m_data, a.m_data, m_iElementCount);
        return *this;
    }
};

class hkpShapeD4B
{
  public:
    virtual ~hkpShapeD4B() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
};

class hkpShapeContainerD4B
{
  public:
    virtual ~hkpShapeContainerD4B() throw();
};

struct hkpMeshShapeSubpartD4B
{
    const void* m_vertexBase;
    int m_vertexStriding;
    int m_numVertices;
    const void* m_indexBase;
    signed char m_stridingType;
    signed char m_materialIndexStridingType;
    unsigned short m_flags;
    int m_indexStriding;
    int m_flipAlternateTriangles;
    int m_numTriangles;
    const void* m_materialIndexBase;
    int m_materialIndexStriding;
    const void* m_materialBase;
    int m_materialStriding;
    int m_numMaterials;
    int m_triangleOffset;
};

class FUN_00dcd310 : public hkpShapeD4B, public hkpShapeContainerD4B
{
  public:
    FUN_00dcd310(float fRadius, int iNumBitsForSubpartIndex) throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
    int unk18;
    int unk1C;
    hkVector4D4B m_kScaling;
    int m_iNumBitsForSubpartIndex;
    hkArrayD4B<hkpMeshShapeSubpartD4B> m_kSubparts;
    hkArrayD4B<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    float m_fSphereRadius;
    int unk54;
    int unk58;
    int unk5C;

    void FUN_00d4b480(const hkpMeshShapeSubpartD4B& kSubpart) throw();
};

class FUN_00d4bab0 : public FUN_00dcd310
{
  public:
    FUN_00d4bab0(const FUN_00dcd310& kOther) throw();
    virtual ~FUN_00d4bab0() throw();

    hkArrayD4B<int> m_60;
};

// @fnv 0x00d4bab0
FUN_00d4bab0::FUN_00d4bab0(const FUN_00dcd310& kOther) throw()
    : FUN_00dcd310(kOther.m_fSphereRadius, kOther.m_iNumBitsForSubpartIndex)
{
    m_kScaling = kOther.m_kScaling;
    m_ulUserData = kOther.m_ulUserData;
    m_bDisableWelding = kOther.m_bDisableWelding;
    for (int i = 0; i < kOther.m_kSubparts.GetLogicalSize(); i++)
        FUN_00d4b480(kOther.m_kSubparts[i]);
    m_kWeldingInfo = kOther.m_kWeldingInfo;
    m_eWeldingType = kOther.m_eWeldingType;
}

namespace fnv_00d4bc00 {


template <typename T> struct hkArrayD4BC
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void _clearAndDeallocate(hkMemoryAllocator& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~hkArrayD4BC() throw()
    {
        _clearAndDeallocate(hkMemoryRouter::getInstance().heap());
    }
};

class hkReferencedObjectD4BC
{
  public:
    virtual ~hkReferencedObjectD4BC() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class FUN_00d4bc00 : public hkReferencedObjectD4BC
{
  public:
    hkArrayD4BC<hkReal> m_kVertices;
    hkArrayD4BC<hkUint16> m_kIndices16;
    hkArrayD4BC<hkUint32> m_kIndices32;
    hkArrayD4BC<hkUint8> m_kMaterialIndices8;
    hkArrayD4BC<hkUint32> m_kMaterials;
    hkArrayD4BC<hkUint16> m_kMaterialIndices16;

    virtual ~FUN_00d4bc00() throw();
};

// Destructor that releases the six hkArray members of the object via their own destructors.
// @fnv 0x00d4bc00
FUN_00d4bc00::~FUN_00d4bc00() throw()
{}
}  // namespace fnv_00d4bc00

namespace fnv_00d4bd30 {


class FUN_00d4bc00
{
  public:
    virtual ~FUN_00d4bc00() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkMemoryRouter::getInstance().heap().blockFree(p, static_cast<FUN_00d4bc00*>(p)->m_usMemSizeAndFlags);
    }

    FUN_00d4bc00* DestroyAndFree(unsigned int uiFlags) throw();
};

// Runs the destructor, then frees the object through operator delete when bit 0 of uiFlags is set, and returns this.
// @fnv 0x00d4bd30
FUN_00d4bc00* FUN_00d4bc00::DestroyAndFree(unsigned int uiFlags) throw()
{
    reinterpret_cast<::fnv_00d4bc00::FUN_00d4bc00 *>((this))->fnv_00d4bc00::FUN_00d4bc00::~FUN_00d4bc00();
    if (uiFlags & 1)
        FUN_00d4bc00::operator delete(this);
    return this;
}
}  // namespace fnv_00d4bd30

namespace fnv_00d4be00 {

struct FUN_00d4b400_Obj
{
    void FUN_00d4b400();
};



class FUN_00d4be00_cls : public hkpStorageMeshShape
{
  public:
    FUN_00d4be00_cls* FUN_00d4be00(int flags);
};

// @fnv 0x00d4be00
FUN_00d4be00_cls* FUN_00d4be00_cls::FUN_00d4be00(int flags)
{
    ((FUN_00d4b400_Obj*)this)->FUN_00d4b400();
    if (flags & 1)
    {
        hkMemoryRouter::getInstance().heap().blockFree(this, m_usMemSizeAndFlags);
    }
    return this;
}
}  // namespace fnv_00d4be00



namespace hkRouterD4B4 {
}

template <typename T> struct hkArrayD4B4
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    void _clearAndDeallocate(hkMemoryAllocator& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    ~hkArrayD4B4() throw()
    {
        _clearAndDeallocate(hkMemoryRouter::getInstance().heap());
    }
};

class hkRefD4B4
{
  public:
};

class hkBaseAD4B4
{
  public:
    virtual ~hkBaseAD4B4() throw();
    int unk04, unk08, unk0C;
};

class hkBaseBD4B4
{
  public:
    virtual void V0() throw();
};

class FUN_00d4bd60 : public hkBaseAD4B4, public hkBaseBD4B4
{
  public:
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C;

    virtual ~FUN_00d4bd60() throw();
};

class FUN_00d4b400 : public FUN_00d4bd60
{
  public:
    hkArrayD4B4<hkRefD4B4*> m_children;

    virtual ~FUN_00d4b400() throw();
    virtual void V0() throw();
};

// Destructor that calls FUN_00c905b0 on each element of m_children.
// @fnv 0x00d4b400
FUN_00d4b400::~FUN_00d4b400() throw()
{
    for (int i = 0; i < m_children.GetLogicalSize(); i++)
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((m_children.m_data[i]))->FUN_00c905b0();
    }
}

class hkRefObjD4BB
{
  public:
    hkRefObjD4BB()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkRefObjD4BB();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

template <class T> class hkArrayD4BB
{
  public:
    hkArrayD4BB() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class FUN_00d4bbb0 : public hkRefObjD4BB
{
  public:
    hkArrayD4BB<int> m_array08;
    hkArrayD4BB<int> m_array14;
    hkArrayD4BB<int> m_array20;
    hkArrayD4BB<int> m_array2C;
    hkArrayD4BB<int> m_array38;
    hkArrayD4BB<int> m_array44;

    FUN_00d4bbb0();
    virtual ~FUN_00d4bbb0();
};

// Default constructor for FUN_00d4bbb0 that leaves the inherited hkRefObjD4BB and the six hkArrayD4BB<int> members at their default-initialized state.
// @fnv 0x00d4bbb0
FUN_00d4bbb0::FUN_00d4bbb0()
{}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual inherited through a second base.
struct FnvHavok00d4bdf0_PrimaryBase
{
    virtual void FUN_00d4bdf0();
    int unk04;
    int unk08;
    int unk0C;
};

struct FnvHavok00d4bdf0_SecondaryBase
{
    virtual void FUN_00d4bdf0();
};

struct FnvHavok00d4bdf0_Derived : FnvHavok00d4bdf0_PrimaryBase, FnvHavok00d4bdf0_SecondaryBase
{
    FnvHavok00d4bdf0_Derived();
// @fnv 0x00d4bdf0
    virtual void FUN_00d4bdf0();
};

FnvHavok00d4bdf0_Derived::FnvHavok00d4bdf0_Derived()
{}

extern "C" void _ReadWriteBarrier();


static __declspec(noinline) int __cdecl FUN_00d4b390(int a, int n)
{
    switch (a)
    {
    case 1:
        return n + 2;
    case 2:
        return 2 * n + 1;
    default:
        return 3 * n;
    }
}

struct Trivial480
{
};
struct Complex480
{
};
struct CopyOps480
{
    template <class T> static __forceinline void initialize(T*, int, Trivial480)
    {}
    template <class T> static __forceinline void fill(T* dest, int count, const T& value, Trivial480)
    {
        for (int j = 0; j < count; ++j)
            dest[j] = value;
    }
    template <class T> static __forceinline void fill(T* dest, int count, const T& value, Complex480)
    {
        for (int j = 0; j < count; ++j)
        {
            T* slot = dest + j;
            __assume(slot != 0);
            new (slot) T(value);
        }
    }
};
struct HeapPolicy480
{
    __forceinline hkMemoryAllocator& get(const void*)
    {
        return hkMemoryRouter::getInstance().heap();
    }
};
template <class T> struct CoreArray480
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* data480()
    {
        return m_data;
    }
    T& back480()
    {
        return m_data[m_iElementCount - 1];
    }
    T* last480()
    {
        return m_data + m_iElementCount - 1;
    }

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int n)
    {
        return m_data[n];
    }
    const T& operator[](int n) const
    {
        return m_data[n];
    }
    __forceinline void reserveHeap480(hkMemoryAllocator& heap, int needed)
    {
        int capacity = getCapacity();
        if (capacity < needed)
        {
            int doubled = 2 * capacity;
            int result = needed < doubled ? doubled : needed;
            ::FUN_00c908c0((::SpawnedObject *)(void *)(&heap), (::SpawnedArray *)(void *)(this), result, sizeof(T));
        }
    }
    __forceinline T* appendHeap480(hkMemoryAllocator& heap, int count)
    {
        int oldSize = m_iElementCount;
        reserveHeap480(heap, m_iElementCount + count);
        CopyOps480::initialize(m_data + m_iElementCount, count, Trivial480());
        m_iElementCount += count;
        return m_data + oldSize;
    }
    __forceinline void pushHeap480(hkMemoryAllocator& heap, const T& value)
    {
        if (m_iElementCount == getCapacity())
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&heap), (::AudioStream *)(void *)(this), sizeof(T));
        CopyOps480::fill(m_data + m_iElementCount, 1, value, Trivial480());
        m_iElementCount++;
    }
};
template <class T> struct Arr480 : CoreArray480<T>
{
    __forceinline void growIfFull()
    {
        hkMemoryAllocator& heap = HeapPolicy480().get(this);
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&heap, this, sizeof(T));
    }
    __forceinline void growIfFull2()
    {
        growIfFull();
    }
    __forceinline void AddBack(const T& value)
    {
        pushHeap480(HeapPolicy480().get(this), value);
    }
    __forceinline void pushBack2(const T& value)
    {
        AddBack(value);
    }
    __forceinline T* appendRange(int count)
    {
        return appendHeap480(HeapPolicy480().get(this), count);
    }
    __forceinline T* appendRange2(int count)
    {
        return appendRange(count);
    }
    __forceinline T* appendRangeP(int count)
    {
        return appendRange(count);
    }
};
template <class Arr> __forceinline void GrowIfFull480(Arr& arr, int elemSize)
{
    hkMemoryAllocator& heap = hkMemoryRouter::getInstance().heap();
    if (arr.m_iElementCount == (arr.m_iCapacityState & 0x3fffffff))
        ::ResizeAudioStream((::AudioAllocator *)(&heap), (::AudioStream *)(void *)(&arr), elemSize);
}
template <class Arr> __forceinline void ReserveCount480(Arr& arr, int count, int elemSize)
{
    hkMemoryAllocator* heap = &hkMemoryRouter::getInstance().heap();
    int cap = arr.m_iCapacityState & 0x3fffffff;
    int need = arr.m_iElementCount + count;
    if (cap < need)
    {
        int newCap = cap + cap;
        if (newCap < need)
            newCap = need;
        FUN_00c908c0(heap, &arr, newCap, elemSize);
    }
}

__forceinline hkpMeshShapeSubpartD4B* ExpandInit480(hkArrayD4B<hkpMeshShapeSubpartD4B>& arr)
{
    GrowIfFull480(arr, sizeof(hkpMeshShapeSubpartD4B));
    hkpMeshShapeSubpartD4B* e = &arr.m_data[arr.m_iElementCount];
    if (e)
    {
        e->m_materialIndexStridingType = 1;
        e->m_materialIndexStriding = 0;
        e->m_materialStriding = 0;
        e->m_numMaterials = 1;
        e->m_materialBase = 0;
        e->m_materialIndexBase = 0;
        e->m_triangleOffset = -1;
        e->m_flipAlternateTriangles = 0;
    }
    return &arr.m_data[arr.m_iElementCount++];
}

struct Storage480
{
    const void* vptr;
    unsigned short GetAllocationSize;
    unsigned short refCount;
    Arr480<float> verts;
    Arr480<unsigned short> idx16;
    Arr480<int> idx32;
    Arr480<unsigned char> mat8;
    Arr480<int> extra;
    Arr480<unsigned short> mat16;
    Storage480* FUN_00d4bbb0();
};

// Copies a mesh subpart's vertex, index, material, and extra data into owned storage arrays and updates the subpart's pointers and strides.
// @fnv 0x00d4b480
void FUN_00dcd310::FUN_00d4b480(const hkpMeshShapeSubpartD4B& kSubpart) throw()
{
    hkpMeshShapeSubpartD4B* pSubpart = ExpandInit480(m_kSubparts);

    Storage480* storage = static_cast<Storage480*>(hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(Storage480)));
    storage->GetAllocationSize = sizeof(Storage480);
    storage = ((::Storage480 *)(new ((void *)(storage)) ::FUN_00d4bbb0()));

    Arr480<Storage480*>& arr60 = (Arr480<Storage480*>&)static_cast<FUN_00d4bab0*>(this)->m_60;
    arr60.AddBack(storage);
    storage = arr60.m_data[arr60.m_iElementCount - 1];
    int numFloats = kSubpart.m_numVertices * 3;

    {
        Arr480<float>& verts = storage->verts;
        float* dst = verts.appendRange(numFloats);
        const float* src = (const float*)kSubpart.m_vertexBase;
        for (int i = 0; i < kSubpart.m_numVertices; i++)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst += 3;
            src = (const float*)((const char*)src + kSubpart.m_vertexStriding);
        }
        pSubpart->m_vertexBase = verts.m_data;
        pSubpart->m_vertexStriding = 12;
        pSubpart->m_numVertices = kSubpart.m_numVertices;
    }

    const void* idxDst;
    if (kSubpart.m_stridingType == 1)
    {
        int a = (int)((unsigned int)kSubpart.m_indexStriding >> 1);
        int iClamped = a;
        if (iClamped > 2)
            iClamped = 3;
        pSubpart->m_indexStriding = iClamped + iClamped;
        int numIndices = FUN_00d4b390(a, kSubpart.m_numTriangles);
        Arr480<unsigned short>& arr = storage->idx16;
        unsigned short* dst = arr.appendRange(numIndices);
        idxDst = dst;
        const unsigned short* src = (const unsigned short*)kSubpart.m_indexBase;
        for (int i = 0; i < kSubpart.m_numTriangles; i++)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst = (unsigned short*)((char*)dst + pSubpart->m_indexStriding);
            src = (const unsigned short*)((const char*)src + kSubpart.m_indexStriding);
        }
    }
    else
    {
        int a = (int)((unsigned int)kSubpart.m_indexStriding >> 2);
        int iClamped = a;
        if (iClamped > 2)
            iClamped = 3;
        pSubpart->m_indexStriding = (iClamped << 2);
        int numIndices = FUN_00d4b390(a, kSubpart.m_numTriangles);
        Arr480<int>& arr = storage->idx32;
        int* dst = arr.appendRange2(numIndices);
        idxDst = dst;
        const int* src = (const int*)kSubpart.m_indexBase;
        for (int i = 0; i < kSubpart.m_numTriangles; i++)
        {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            dst = (int*)((char*)dst + pSubpart->m_indexStriding);
            src = (const int*)((const char*)src + kSubpart.m_indexStriding);
        }
    }

    pSubpart->m_stridingType = kSubpart.m_stridingType;
    pSubpart->m_numTriangles = kSubpart.m_numTriangles;
    pSubpart->m_flipAlternateTriangles = kSubpart.m_flipAlternateTriangles;
    pSubpart->m_indexBase = idxDst;
    pSubpart->m_materialIndexStridingType = kSubpart.m_materialIndexStridingType;

    const void* materialIndices = kSubpart.m_materialIndexBase;
    if (materialIndices != 0)
    {
        if (kSubpart.m_materialIndexStridingType == 1)
        {

            if (kSubpart.m_materialIndexStriding == 0)
            {
                storage->mat8.pushBack2(*(const unsigned char*)materialIndices);
                pSubpart->m_materialIndexBase = &storage->mat8.back480();
            }
            else
            {
                unsigned char* dst = storage->mat8.appendRange(kSubpart.m_numTriangles);
                pSubpart->m_materialIndexBase = dst;
                const unsigned char* src = (const unsigned char*)kSubpart.m_materialIndexBase;
                for (int i = 0; i < kSubpart.m_numTriangles; i++)
                {
                    dst[i] = src[0];
                    src += kSubpart.m_materialIndexStriding;
                }
            }
        }
        else
        {
            Arr480<unsigned short>& arr = storage->mat16;
            if (kSubpart.m_materialIndexStriding == 0)
            {
                arr.pushBack2(*(const unsigned short*)materialIndices);
                pSubpart->m_materialIndexBase = arr.m_data + arr.m_iElementCount - 1;
            }
            else
            {
                unsigned short* dst = arr.appendRange(kSubpart.m_numTriangles);
                pSubpart->m_materialIndexBase = dst;
                const unsigned short* src = (const unsigned short*)kSubpart.m_materialIndexBase;
                for (int i = 0; i < kSubpart.m_numTriangles; i++)
                {
                    dst[i] = src[0];
                    src = (const unsigned short*)((const char*)src + kSubpart.m_materialIndexStriding);
                }
            }
        }
        int matStride = kSubpart.m_materialIndexStriding;
        pSubpart->m_materialIndexStriding = matStride;
        if (matStride != 0)
        {
            switch ((signed char)pSubpart->m_materialIndexStridingType)
            {
            case 1:
                pSubpart->m_materialIndexStriding = 1;
                break;
            case 2:
                pSubpart->m_materialIndexStriding = 2;
                break;
            }
        }
    }
    else
    {
        pSubpart->m_materialIndexBase = 0;
        pSubpart->m_materialIndexStriding = 0;
    }

    if (pSubpart->m_materialIndexBase != 0)
    {
        Arr480<int>& arr = storage->extra;
        if (kSubpart.m_materialStriding == 0)
        {
            const int* pExtraSrc = (const int*)kSubpart.m_materialBase;
            arr.pushBack2(*pExtraSrc);
            pSubpart->m_materialStriding = 0;
            pSubpart->m_numMaterials = 1;
        }
        else
        {
            int* dst = arr.appendRange(kSubpart.m_numMaterials);
            const int* pExtraSrc = (const int*)kSubpart.m_materialBase;
            for (int i = 0; i < kSubpart.m_numMaterials; i++)
            {
                dst[i] = pExtraSrc[0];
                pExtraSrc = (const int*)((const char*)pExtraSrc + kSubpart.m_materialStriding);
            }
            pSubpart->m_materialStriding = 4;
            pSubpart->m_numMaterials = kSubpart.m_numMaterials;
        }
        pSubpart->m_materialBase = arr.m_data;
    }
    else
    {
        pSubpart->m_numMaterials = 1;
        pSubpart->m_materialBase = &DAT_01267e30;
        pSubpart->m_materialStriding = 0;
        pSubpart->m_materialIndexBase = &DAT_01267e30;
    }
    pSubpart->m_triangleOffset = kSubpart.m_triangleOffset;
}

namespace fnv_00d4ba30 {
struct FinishingFlag
{
    int m_bFinishing;
};

template <class T> struct hkArrayD4B
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T* begin()
    {
        return m_data;
    }
};

class hkpShapeContainerD4B
{
  public:
    virtual ~hkpShapeContainerD4B();
};

struct hkpMeshSubpartD4B
{
    const float* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int m_iStridedVertexCount;
    const void* m_pMaterialDataBase;
    unsigned char m_ucIndexStridingType;
    unsigned char m_iMaterialIndexType;
    short unk12;
    int m_iMaterialStriding;
    int m_bFlipAlternateTriangles;
    int m_iTriangleCount;
    const void* m_pVertexBase;
    int m_iVertexStriding;
    const void* m_pIndexBase;
    int m_iNumTriangles;
    int m_iIndexStriding;
    int m_iTriangleOffset;
};

class hkpShapeD4B
{
  public:
    virtual ~hkpShapeD4B();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    int m_type;
};

class FUN_00dcd380 : public hkpShapeD4B, public hkpShapeContainerD4B
{
  public:
    virtual ~FUN_00dcd380();
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    hkArrayD4B<hkpMeshSubpartD4B> m_kSubparts;

    FUN_00dcd380(FinishingFlag flag);
};

struct hkpSubpartStorageD4B
{
    void* vtbl;
    int m_memSizeAndRefCount;
    hkArrayD4B<float> m_kVertices;
    hkArrayD4B<unsigned short> m_kIndices16;
    hkArrayD4B<unsigned int> m_kIndices32;
    hkArrayD4B<unsigned char> m_kMaterialIndices8;
    hkArrayD4B<unsigned int> m_kMaterials;
    hkArrayD4B<unsigned short> m_kMaterialIndices16;
};

class FUN_00d4ba30 : public FUN_00dcd380
{
  public:
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    hkArrayD4B<hkpSubpartStorageD4B*> m_kStorage;

    FUN_00d4ba30(FinishingFlag flag);
    virtual ~FUN_00d4ba30();
};

// Constructor: calls the base constructor and, if flag.m_bFinishing is set, points each subpart's data fields at the begin of the matching storage arrays.
// @fnv 0x00d4ba30
FUN_00d4ba30::FUN_00d4ba30(FinishingFlag flag) : FUN_00dcd380(flag)
{
    if (flag.m_bFinishing)
    {
        for (int i = 0; i < m_kSubparts.GetLogicalSize(); i++)
        {
            hkpMeshSubpartD4B& part = m_kSubparts[i];
            hkpSubpartStorageD4B& storage = *m_kStorage[i];
            part.m_pMaterialIndexBase = storage.m_kVertices.begin();
            if (part.m_ucIndexStridingType == 1)
                part.m_pMaterialDataBase = storage.m_kIndices16.begin();
            else
                part.m_pMaterialDataBase = storage.m_kIndices32.begin();
            if (part.m_iMaterialIndexType == 1)
                part.m_pVertexBase = storage.m_kMaterialIndices8.begin();
            else
                part.m_pVertexBase = storage.m_kMaterialIndices16.begin();
            part.m_pIndexBase = storage.m_kMaterials.begin();
        }
    }
}
}  // namespace fnv_00d4ba30

namespace fnv_00d4bd60 {



template <class T> class hkArrayD4BD
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD4BD() throw()
    {
        hkMemoryAllocator& kAlloc = hkMemoryRouter::getInstance().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

namespace hkD4BD {
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw()
    {}
};

class hkReferencedObject : public hkBaseObject
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShape : public hkReferencedObject
{
  public:
    unsigned long m_ulUserData;
    int m_type;
};

class hkpShapeContainer
{
  public:
    virtual ~hkpShapeContainer() throw()
    {}
};

class hkpShapeCollection : public hkpShape, public hkpShapeContainer
{
  public:
    bool m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct TriangleD4BD
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34;
};
}

class FUN_00d4bd60
{
  public:
    ~FUN_00d4bd60();

    hkD4BD::hkpShapeCollection m_kCollection;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    hkArrayD4BD<hkD4BD::TriangleD4BD> m_kTriangles;
    hkArrayD4BD<unsigned short> m_kMaterialIndices;
};

// Destructor for a triangle collection object that owns a shape collection, a triangle array, and a material index array.
// @fnv 0x00d4bd60
FUN_00d4bd60::~FUN_00d4bd60()
{}
}  // namespace fnv_00d4bd60

namespace fnv_00dcebd0 {
template <typename T> static __forceinline void CopyElements(T* dest, const T* src, int count)
{
    for (int index = 0; index < count; ++index)
        dest[index] = src[index];
}

struct FUN_00dcebd0_Class
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    int m_reserved10;
    unsigned char m_bDisableWelding;
    unsigned char m_eCollectionType;
    unsigned short m_reserved16;
    int m_reserved18;
    int m_reserved1c;
    float m_scalingX, m_scalingY, m_scalingZ, m_scalingW;
    int m_iNumBitsForSubpartIndex;
    void* m_subpartsData;
    int m_subpartsSize;
    int m_subpartsCapacity;
    void* m_weldingInfoData;
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void FUN_00dcebd0(const FUN_00dcebd0_Class& source);
};
// Calls FUN_00d06290(source), then copies source's int array into this, reallocating through the thread allocator when capacity is smaller.
// @fnv 0x00dcebd0
void FUN_00dcebd0_Class::FUN_00dcebd0(const FUN_00dcebd0_Class& source)
{
    reinterpret_cast<::hkpPhysicsSystemD29 *>(this)->FUN_00d06290((const ::hkpPhysicsSystemD29 &)(source));
    hkMemoryAllocator* allocator = &hkMemoryRouter::getInstance().heap();
    int capacity = m_iCapacityState & 0x3fffffff;
    if (capacity < source.m_iElementCount)
    {
        if ((m_iCapacityState & 0x80000000u) == 0)
        {
            allocator->bufFree(m_data, capacity * sizeof(int));
        }
        int bytes = source.m_iElementCount * sizeof(int);
        m_data = static_cast<int*>(allocator->bufAlloc(bytes));
        m_iCapacityState = bytes / 4;
    }
    m_iElementCount = source.m_iElementCount;
    CopyElements(m_data, source.m_data, m_iElementCount);
}
}  // namespace fnv_00dcebd0
