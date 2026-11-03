
// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00d06000.h"
#include "fnv/symbols_00d21000.h"
#include "fnv/symbols_01269000.h"
#include "havok/hkpConvexPieceMeshShape.h"

struct HkpStandIn;

struct HkpAllocator
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void release(HkpStandIn* object, unsigned short size) = 0;
};

struct HkpRouter
{
    void* reserved;
    unsigned char padding[12];
    HkpAllocator* allocator;
};

struct HkpStandIn
{
    virtual void v0() = 0;

    HkpStandIn* FUN_00e01010(int flags);

    unsigned short value;
};

HkpRouter* _D1A0E0GetMemoryRouter();

struct FUN_00e49100_t
{
    int GetNextKey(int key);
};

// @fnv 0x00e49100
int FUN_00e49100_t::GetNextKey(int key)
{
    void* shape = *(void**)((char*)this + 8);
    int iMaxKey = *(int*)((char*)shape + 0x24) + *(int*)((char*)shape + 0x18);
    int iNextKey = key + 1;
    if (iNextKey >= iMaxKey)
        iNextKey = -1;
    return iNextKey;
}

struct FUN_00e49290_Target
{
    // Virtual stub that returns 0 for the given int argument.
// @fnv 0x00e49290
    virtual int FUN_00e49290_f0(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f1(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f2(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f3(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f4(int)
    {
        return 0;
    }
};

struct FUN_00e49290_Owner
{
    unsigned char pad[0x10];
    FUN_00e49290_Target target;
};

struct FUN_00e49290_Data
{
    unsigned char pad0[8];
    int* p8;
    unsigned char pad1[8];
    int* p14;
    unsigned int count;
    unsigned char pad2[4];
    int* p20;
};

struct FUN_00e49290_Class
{
    unsigned char pad[8];
    FUN_00e49290_Data* data;
    FUN_00e49290_Owner* owner;

    int FUN_00e49290(unsigned int index);
};

int FUN_00e49290_Class::FUN_00e49290(unsigned int index)
{
    int result;

    if (index < this->data->count)
    {
        int i = this->data->p14[index];
        result = this->data->p8[i + 1];
    }
    else
    {
        result = this->data->p20[index - this->data->count];
    }

    return this->owner->target.FUN_00e49290_f4(result);
}

// @fnv 0x00e49030
int FUN_00e49030()
{
    return 0;
}

struct Ref
{
};
struct P
{
    virtual ~P()
    {}
    int a, b, c;
};
struct S
{
    virtual ~S()
    {}
    int d;
};
struct Ptr
{
    Ref* p;
    ~Ptr()
    {
        reinterpret_cast<::hkReferencedObjectC905 *>((p))->FUN_00c905b0();
    }
};
struct D : P, S
{
    Ptr m18;
    Ptr m1c;
    __forceinline ~D()
    {}
    void FUN_00e490d0();
};
// Calls FUN_00e490d0, then if flags has bit 0 set, releases this through the memory router's allocator with this->value as size, and returns this.
// @fnv 0x00e01010
HkpStandIn* HkpStandIn::FUN_00e01010(int flags)
{
    reinterpret_cast<::D *>((this))->FUN_00e490d0();

    if (flags & 1)
    {
        HkpRouter* router = _D1A0E0GetMemoryRouter();
        HkpAllocator* allocator = router->allocator;
        allocator->release(this, this->value);
    }

    return this;
}
// Destroys the object by invoking its destructor.
// @fnv 0x00e490d0
void D::FUN_00e490d0()
{
    this->D::~D();
}

class GlobalObjectO2_00d472a0;


template <class T> class hkArrayE494
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
};

class hkStatisticsCollectorE494
{
  public:
    virtual ~hkStatisticsCollectorE494() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    hkBool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayE494<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = ::fnv_00d06f80::FUN_00d06f80((const char *)(pData), kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
public:
    template <class T> void addArray(const char* pcName, const hkArrayE494<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

class hkxStreamE494;
class hkDisplayMeshE494;

struct hkMeshSectionE494
{
    int unk00;
    int unk04;
    hkArrayE494<hkxStreamE494*> m_indexStreams;
    hkArrayE494<hkxStreamE494*> m_vertexStreams;
    hkArrayE494<hkxStreamE494*> m_materialStreams;
};

class hkReferencedObjectE494
{
  public:
    virtual ~hkReferencedObjectE494() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

};

class hkDisplayGeometryE494 : public hkReferencedObjectE494
{
  public:
    hkMeshSectionE494* m_kCriticalSection;
    hkDisplayMeshE494* m_pDisplayMesh;

    void AddToStatisticsCollector(hkStatisticsCollectorE494* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const
        throw();
};

// Adds the vertex, material and index stream arrays and the display mesh to pkCollector, then forwards to the base statistics routine.
// @fnv 0x00e49410
void hkDisplayGeometryE494::AddToStatisticsCollector(hkStatisticsCollectorE494* pkCollector,
                                                     const GlobalObjectO2_00d472a0* pkClass) const throw()
{
    pkCollector->addArray("Stream", m_kCriticalSection->m_vertexStreams);
    pkCollector->addArray("Stream", m_kCriticalSection->m_materialStreams);
    pkCollector->addArray("Stream", m_kCriticalSection->m_indexStreams);
    pkCollector->addChildObject("DisplayMesh", m_pDisplayMesh, 0);
    ::FUN_00d213e0((const char *const *)this, (const char *const *)(pkCollector));
}

// Stores whether bit bitIndex % 31 of word bitIndex / 31, at bits[bits[0] + 1 + word], is set into *found, and returns found.
// @fnv 0x00e49040
unsigned char* FUN_00e49040(unsigned char* pbResult, const int* bits, unsigned int bitIndex)
{
    unsigned int wordIndex = bitIndex / 31;
    unsigned int bitWithinWord = bitIndex % 31;
    unsigned int mask = 1u << bitWithinWord;
    *pbResult = (bits[bits[0] + wordIndex + 1] & mask) != 0;
    return pbResult;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual declared by both bases.
struct PrimaryBase
{
    virtual void FUN_00e01040();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00e01040();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e01040
    virtual void FUN_00e01040();
};

Derived::Derived()
{}

// Moved from hkpconvexpiecemeshshape_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00e49000.h"
int FUN_00e49030();
int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

#include <xmmintrin.h>

class hkBoolE49
{
  public:
    hkBoolE49(bool b) : m_cBooleanValue((char)b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

struct hkVector4E49
{
    __m128 m_vComponents;

    inline hkVector4E49& operator=(const hkVector4E49& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

struct ShapeBufferE49
{
    __declspec(align(16)) unsigned char m_data[0x200];
};

class TriangleShapeE49
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4E49 m_kVertices[3];
};

class ShapeContainerE49
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual const TriangleShapeE49* GetShapeForKey(int iKey, ShapeBufferE49& kBuffer) const;
};

class MeshShapeE49
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ShapeContainerE49 m_container;
};

struct FaceTableE49
{
    int unk00;
    int unk04;
    int* m_piFaceData;
    int unk0c;
    int unk10;
    int* m_piFaceStart;
    unsigned int m_uiNumFaces;
    int unk1c;
    int* m_piTriangleKeys;
};

class FUN_00e607c0
{
  public:
    FUN_00e607c0(float fRadius);

    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkVector4E49* m_pkVertices;
    int m_iNumVertices;
    MeshShapeE49* m_pkMesh;
    int* m_piKeys;
    int m_iNumKeys;
};

class PieceBaseE49
{
  public:
    virtual void unk00();
    int unk04;
    int unk08;
    int unk0c;
};

class PieceAgentE49
{
  public:
    virtual void unk00();
    int unk04;
    FaceTableE49* m_pkFaces;
    MeshShapeE49* m_pkMesh;
    float m_fBoundRadius;

    FUN_00e607c0* FUN_00e49120(unsigned int uiIndex, void* pvMemory);
};

class PieceSourceE49 : public PieceBaseE49, public PieceAgentE49
{
  public:
    __declspec(noinline) hkBoolE49 FUN_00e49040(const int* piFace, int m_iEdgeNumber) const
    {
        int iWord = m_iEdgeNumber / 31;
        int iBit = m_iEdgeNumber % 31;
        return (piFace[piFace[0] + iWord + 1] & (1 << iBit)) != 0;
    }
};

// @fnv 0x00e49120
FUN_00e607c0* PieceAgentE49::FUN_00e49120(unsigned int uiIndex, void* pvMemory)
{
    FUN_00e607c0* pkPieces = new (pvMemory) FUN_00e607c0(m_fBoundRadius);
    pkPieces->m_pkMesh = m_pkMesh;

    ShapeBufferE49 kBuffer;
    if (uiIndex < m_pkFaces->m_uiNumFaces)
    {
        int iStart = m_pkFaces->m_piFaceStart[uiIndex];
        const int* piData = m_pkFaces->m_piFaceData;
        const int* j = &piData[iStart];
        pkPieces->m_iNumKeys = *j;
        pkPieces->m_piKeys = (int*)(j + 1);
        hkVector4E49* pkOut = (hkVector4E49*)(((uintptr_t)pvMemory + 0x3b) & ~(uintptr_t)15);
        pkPieces->m_pkVertices = pkOut;
        pkPieces->m_iNumVertices = 0;
        for (int i = 0; i < pkPieces->m_iNumKeys; i++)
        {
            int iKey = pkPieces->m_piKeys[i];
            const TriangleShapeE49* pkTriangle = m_pkMesh->m_container.GetShapeForKey(iKey, kBuffer);
            int piFace = 0;
            do
            {
                if ((*(::hkBoolE49 *)(::FUN_00e49040((unsigned char *)(static_cast<PieceSourceE49*>(this)), j, i * 3 + piFace))))
                {
                    *pkOut = pkTriangle->m_kVertices[piFace];
                    pkOut++;
                    pkPieces->m_iNumVertices++;
                }
                piFace++;
            } while (piFace < 3);
        }
    }
    else
    {
        pkPieces->m_iNumKeys = 1;
        int* piKeys = &m_pkFaces->m_piTriangleKeys[uiIndex - m_pkFaces->m_uiNumFaces];
        pkPieces->m_piKeys = piKeys;
        hkVector4E49* pkOut = (hkVector4E49*)(((uintptr_t)pvMemory + 0x3b) & ~(uintptr_t)15);
        pkPieces->m_pkVertices = pkOut;
        pkPieces->m_iNumVertices = 3;
        int iKey = pkPieces->m_piKeys[0];
        const TriangleShapeE49* pkTriangle = m_pkMesh->m_container.GetShapeForKey(iKey, kBuffer);
        pkOut[0] = pkTriangle->m_kVertices[0];
        pkOut[1] = pkTriangle->m_kVertices[1];
        pkOut[2] = pkTriangle->m_kVertices[2];
    }
    return pkPieces;
}

struct xVec4
{
    __m128 m_vComponents;
    __forceinline void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void setMin4(const xVec4& a, const xVec4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const xVec4& a, const xVec4& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};
struct xAabb
{
    xVec4 m_kMinimumCorner;
    xVec4 m_kMaximumCorner;
};
struct xTransform;
typedef __declspec(align(16)) int xShapeBuffer[128];

struct xChild
{
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void getAabb(const xTransform& t, float tolerance, xAabb& out) const;
};
struct xContainer
{
    virtual void k0();
    virtual void k1();
    virtual int GetFirstKey() const;
    virtual int GetNextShapeKey(int key) const;
    virtual void k4();
    virtual const xChild* GetShapeForKey(int key, xShapeBuffer& buffer) const;
};
struct xShapeBase
{
    virtual void s0();
    int a, b, c;
};
struct xCollection : xShapeBase, xContainer
{
    void FUN_00e492d0(const xTransform& t, float tolerance, xAabb& out) const;
};

// @fnv 0x00e492d0
void xCollection::FUN_00e492d0(const xTransform& t, float tolerance, xAabb& out) const
{
    out.m_kMinimumCorner.set(3.40282e+38f, 3.40282e+38f, 3.40282e+38f, 0.0f);
    out.m_kMaximumCorner.set(-3.40282e+38f, -3.40282e+38f, -3.40282e+38f, 0.0f);
    xShapeBuffer shapeBuffer;
    for (int key = GetFirstKey(); key != -1; key = GetNextShapeKey(key))
    {
        const xChild* child = GetShapeForKey(key, shapeBuffer);
        xAabb childAabb;
        child->getAabb(t, tolerance, childAabb);
        out.m_kMinimumCorner.setMin4(out.m_kMinimumCorner, childAabb.m_kMinimumCorner);
        out.m_kMaximumCorner.setMax4(out.m_kMaximumCorner, childAabb.m_kMaximumCorner);
    }
}
