
// src/havok/physics/internal/collide/mopp/builder/mediator/shape/hkpmoppshapemediator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/mopp/builder/mediator/shape/hkpmoppshapemediator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dd51f0
#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include "fnv/decl/FUN_00dd51d0_class.h"
int ReadIntField(const void* a, int* piValue)
{
    *piValue = *(const int*)((const char*)a + 4);
    return 1;
}

struct FUN_00dd5260_T
{
    int a;
    int b;
    int c;
    int d;
    int e;
};

// Copies the five-int struct pointed to by pSrc into the struct pointed to by pDst.
// @fnv 0x00dd5260
void FUN_00dd5260(FUN_00dd5260_T* pSrc, int a1, int a2, int a3, FUN_00dd5260_T* pDst)
{
    *pDst = *pSrc;
}

struct FUN_00dd5210_Interface
{
    virtual void First();
    virtual void Second();
    virtual int GetValue();
    virtual int UseValue(int value);
};

struct FUN_00dd5210_Record
{
    int value;
    int reserved;
    int unk08;
    int unk0c;
    int unk10;
};

struct FUN_00dd5210_Object
{
    int unk00;
    int unk04;
    FUN_00dd5210_Interface* unk08;
    int unk0c;
    void FillRecords(FUN_00dd5210_Record* records);
};

// Fills count records with successive values from unk08, starting at GetValue() and advancing via UseValue().
// @fnv 0x00dd5210
void FUN_00dd5210_Object::FillRecords(FUN_00dd5210_Record* records)
{
    int count = unk0c;
    int value = unk08->GetValue();
    if (count > 0)
    {
        do
        {
            records->value = value;
            records->reserved = 0;
            ++records;
            value = unk08->UseValue(value);
            --count;
        } while (count != 0);
    }
}

struct SpawnedSource
{
    virtual void First();
    virtual int Second();
};

struct SpawnedBase
{
    virtual ~SpawnedBase()
    {}
};

class FUN_00dd52a0_cls : public SpawnedBase
{
  public:
    short unk04;
    unsigned short m_flag06;
    SpawnedSource* m_src08;
    int m_result0c;

    FUN_00dd52a0_cls* InitFromSource(SpawnedSource* src);
};

// Sets m_flag06 to 1, destroys the base, stores src in m_src08, stores src->Second() in m_result0c and returns this.
// @fnv 0x00dd52a0
FUN_00dd52a0_cls* FUN_00dd52a0_cls::InitFromSource(SpawnedSource* pSource)
{
    m_flag06 = 1;
    this->SpawnedBase::~SpawnedBase();
    m_src08 = pSource;
    m_result0c = pSource->Second();
    return this;
}

struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    CpuObject* FUN_00dd55a0(unsigned int flags);
};
// @fnv 0x00dd55a0
CpuObject* CpuObject::FUN_00dd55a0(unsigned int flags)
{
    reinterpret_cast<::FUN_00dd51d0_class *>(this)->FUN_00dd51d0();
    if (flags & 1)
    {
        hkMemoryRouter* holder = &hkMemoryRouter::getInstance();
        holder->m_heap->blockFree(this, size);
    }
    return this;
}

// @fnv 0x00dd51e0
void FUN_00dd51e0(int, int)
{}

struct FnvCpu_FUN_00dd5290_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    int value;
    int FUN_00dd5290();
};
// @fnv 0x00dd5290
int FnvCpu_FUN_00dd5290_CpuObject::FUN_00dd5290()
{
    return value;
}

#include "fnv/symbols_simd.h"


typedef float hkReal;
typedef unsigned int hkpShapeKey;

struct __declspec(align(16)) hkVector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setNeg4(const hkVector4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, ::DAT_010c44d0);
    }
};

struct __declspec(align(16)) hkpShapeBuffer
{
    int m_data[128];
};

struct hkpShape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual hkReal getMaximumProjection(const hkVector4& direction) const;
};

struct hkpShapeContainer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const hkpShape* GetShapeForKey(hkpShapeKey key, hkpShapeBuffer& buffer) const;
};

struct ProjectionSample
{
    hkpShapeKey m_key;
    int m_unk04;
    hkReal m_kMinimumCorner;
    hkReal m_kMaximumCorner;
    int m_unk10;
};

struct ProjectionShape
{
    int unk00;
    int unk04;
    hkpShapeContainer* m_container;

    void ComputeProjectionRange(const hkVector4& direction, int unused, ProjectionSample* samples, int numSamples,
                                hkReal* minOut, hkReal* maxOut);
};

// @fnv 0x00dd52d0
void ProjectionShape::ComputeProjectionRange(const hkVector4& direction, int unused, ProjectionSample* samples,
                                             int numSamples, hkReal* minOut, hkReal* maxOut)
{
    hkpShapeBuffer buffer;
    hkReal fMinCorner;
    hkReal fMaxCorner;
    hkReal minProj;
    hkReal maxProj;
    {
        hkpShapeKey key = samples[0].m_key;
        const hkpShape* pShape = m_container->GetShapeForKey(key, buffer);
        if (pShape)
        {
            fMaxCorner = pShape->getMaximumProjection(direction);
            hkVector4 negDirection;
            negDirection.setNeg4(direction);
            fMinCorner = -pShape->getMaximumProjection(negDirection);
        }
        else
        {
            fMinCorner = 0.0f;
            fMaxCorner = 0.0f;
        }
        samples[0].m_kMinimumCorner = fMinCorner;
        samples[0].m_kMaximumCorner = fMaxCorner;
        maxProj = fMaxCorner;
        minProj = fMinCorner;
    }
    for (int i = 1; i < numSamples; i++)
    {
        hkpShapeKey key = samples[i].m_key;
        const hkpShape* pShape = m_container->GetShapeForKey(key, buffer);
        if (pShape)
        {
            fMaxCorner = pShape->getMaximumProjection(direction);
            hkVector4 negDirection;
            negDirection.setNeg4(direction);
            fMinCorner = -pShape->getMaximumProjection(negDirection);
        }
        else
        {
            fMinCorner = 0.0f;
            fMaxCorner = 0.0f;
        }
        samples[i].m_kMinimumCorner = fMinCorner;
        samples[i].m_kMaximumCorner = fMaxCorner;
        if (fMinCorner < minProj)
        {
            minProj = fMinCorner;
        }
        if (fMaxCorner > maxProj)
        {
            maxProj = fMaxCorner;
        }
    }
    *minOut = minProj;
    *maxOut = maxProj;
}

// Moved from hkpmoppshapemediator_gs_nogs_variant.cpp (VEGAS-15).
#include "fnv/symbols_00c85000.h"
int ReadIntField(const void* a, int* b);
void FUN_00dd5260(FUN_00dd5260_T* pSrc, int a1, int a2, int a3, FUN_00dd5260_T* pDst);
void FUN_00dd51e0(int, int);


namespace fnv_00dd5440 {


struct hkVector4
{
    __m128 m_vComponents;
    __forceinline void setNeg4(const hkVector4& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
};

struct hkpShapeBuffer
{
    char m_data[512];
};

struct hkpConvexShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual float getSupport(const hkVector4& direction) const;
};

struct hkpShapeContainer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const hkpConvexShape* GetShapeForKey(unsigned int key, hkpShapeBuffer& buffer) const;
};

struct hkpChildKey
{
    unsigned int m_key;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
};

struct ExtentCalculator
{
    int m_unk00;
    int m_unk04;
    const hkpShapeContainer* m_container;

    void FUN_00dd5440(const hkVector4& direction, int unused, const hkpChildKey* keys, int numKeys, float* minOut,
                      float* maxOut) const;
};

// @fnv 0x00dd5440
void ExtentCalculator::FUN_00dd5440(const hkVector4& direction, int unused, const hkpChildKey* keys, int numKeys,
                                    float* minOut, float* maxOut) const
{
    hkpShapeBuffer buffer;
    float lo;
    float hi;

    unsigned int key = keys[0].m_key;
    const hkpConvexShape* shape = m_container->GetShapeForKey(key, buffer);
    if (shape)
    {
        hi = shape->getSupport(direction);
        hkVector4 negDir;
        negDir.setNeg4(direction);
        lo = -shape->getSupport(negDir);
    }
    else
    {
        lo = 0.0f;
        hi = 0.0f;
    }

    float fTargetUpperBound = lo;
    float fMinimumInputValue = hi;

    for (int i = 1; i < numKeys; i++)
    {
        key = keys[i].m_key;
        shape = m_container->GetShapeForKey(key, buffer);
        if (shape)
        {
            hi = shape->getSupport(direction);
            hkVector4 negDir;
            negDir.setNeg4(direction);
            lo = -shape->getSupport(negDir);
        }
        else
        {
            lo = 0.0f;
            hi = 0.0f;
        }

        if (lo < fTargetUpperBound)
        {
            fTargetUpperBound = lo;
        }
        if (hi > fMinimumInputValue)
        {
            fMinimumInputValue = hi;
        }
    }

    *minOut = fTargetUpperBound;
    *maxOut = fMinimumInputValue;
}
}  // namespace fnv_00dd5440
#include "generated/data/havok/physics/internal/collide/mopp/builder/mediator/shape/hkpmoppshapemediator_gs_nogs_variant.inc"
