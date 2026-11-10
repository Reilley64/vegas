
// src/havok/physics/collide/shape/hkpshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/hkpshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "havok/hkpShape.h"

// @fnv 0x00c9e3f0
int FUN_00c9e3f0(void* p, int size)
{
    return -1;
}

#include "fnv/symbols_simd.h"



namespace hkC9E5 {
struct VectorComponentValue
{
    __m128 m_vValue;

    operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

struct hkVector4
{
    __m128 m_vComponents;

    hkVector4()
    {}
    hkVector4(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void mul4(const __m128& s)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, s);
    }
    void setFlipSign(const hkVector4& v, const hkVector4& sign)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, _mm_and_ps(sign.m_vComponents, DAT_010c44d0));
    }
    VectorComponentValue dot3(const hkVector4& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        VectorComponentValue r;
        r.m_vValue = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
        return r;
    }
};

struct hkMatrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;

    void setIdentity()
    {
        hkVector4 kZero;
        kZero.setZero4();
        m_kColumn0 = kZero;
        m_kColumn1 = kZero;
        m_kColumn2 = kZero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

class hkTransform
{
  public:
    hkMatrix3 m_rotation;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

class hkAabb
{
  public:
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw();
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
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const hkTransform& kLocalToWorld, float fTolerance, hkAabb& kOut) const = 0;

    float FUN_00c9e560(const hkVector4& kDirection) const;

    unsigned long m_ulUserData;
    unsigned int m_type;
};

// Computes the support point of the shape's AABB along kDirection and returns its dot product with kDirection.
// @fnv 0x00c9e560
float hkpShape::FUN_00c9e560(const hkVector4& kDirection) const
{
    hkTransform kLocalToWorld;
    kLocalToWorld.setIdentity();
    const float fTolerance = 0.0f;
    hkAabb kAabb;
    getAabb(kLocalToWorld, fTolerance, kAabb);

    hkVector4 kTargetCenter;
    kTargetCenter.setAdd4(kAabb.m_kMinimumCorner, kAabb.m_kMaximumCorner);
    kTargetCenter.mul4(::DAT_010c71d0);
    hkVector4 kHalfExtent;
    kHalfExtent.setSub4(kAabb.m_kMaximumCorner, kAabb.m_kMinimumCorner);
    kHalfExtent.mul4(::DAT_010c71d0);

    hkVector4 kSupport;
    kSupport.setFlipSign(kHalfExtent, kDirection);
    kSupport.add4(kTargetCenter);
    return kSupport.dot3(kDirection);
}
}

// Moved from hkpshape_gs_nogs_variant.cpp (VEGAS-15).

// src/havok/physics/collide/shape/hkpshape_gs_nogs_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/shape/hkpshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/shape/hkpshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/hkpshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/symbols_010c9000.h"
int FUN_00c9e3f0(void* p, int size);
struct hkSimdVector4
{
    __m128 m_vComponents;
};

struct Vector4Comparison
{
    __m128 m_uiMask;
};

struct hkFourTransposedPoints
{
    hkSimdVector4 m_kVertices[3];
};

struct ShapeRayCastQuery
{
    hkSimdVector4 m_vFrom;
    hkSimdVector4 m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct ShapeRayBundleCastInput
{
    hkFourTransposedPoints m_vFrom;
    hkFourTransposedPoints m_vTo;
    hkUint32 m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};

struct ShapeRayCastOutput
{
    char m_data[0x50];
};

struct ShapeRayCastOutputArray
{
    ShapeRayCastOutput m_akRayOutputs[4];
};

struct hkBoolRet
{
    hkBool m_cBooleanValue;
};

class hkpShapeBase : public hkpShape
{
  public:
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual hkBoolRet RayCast(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
    Vector4Comparison FUN_00c9e400(const ShapeRayBundleCastInput& input, ShapeRayCastOutputArray& results,
                                   const Vector4Comparison& mask) const;
};

static inline void extractPoints(const hkFourTransposedPoints& p, __m128* out)
{
    __m128 r0 = p.m_kVertices[0].m_vComponents;
    __m128 r1 = p.m_kVertices[1].m_vComponents;
    __m128 r2 = p.m_kVertices[2].m_vComponents;
    __m128 r3 = _mm_setzero_ps();
    _MM_TRANSPOSE4_PS(r0, r1, r2, r3);
    out[0] = r0;
    out[1] = r1;
    out[2] = r2;
    out[3] = r3;
}

// @fnv 0x00c9e400
Vector4Comparison hkpShapeBase::FUN_00c9e400(const ShapeRayBundleCastInput& input, ShapeRayCastOutputArray& results,
                                             const Vector4Comparison& mask) const
{
    __m128 from[4];
    __m128 to[4];
    extractPoints(input.m_vFrom, from);
    extractPoints(input.m_vTo, to);

    ShapeRayCastQuery singleInput;
    singleInput.m_uiFilterInfo = input.m_uiFilterInfo;
    singleInput.m_pRayShapeCollectionFilter = input.m_pRayShapeCollectionFilter;

    int resultMask = 0;
    for (int i = 0; i < 4; i++)
    {
        if (_mm_movemask_ps(mask.m_uiMask) & (*reinterpret_cast<const int (*)[4]>(&::DAT_010c92e0))[i])
        {
            singleInput.m_vFrom.m_vComponents = from[i];
            singleInput.m_vTo.m_vComponents = to[i];
            hkBoolRet hit = RayCast(singleInput, results.m_akRayOutputs[i]);
            if (hit.m_cBooleanValue)
            {
                resultMask |= (*reinterpret_cast<const int (*)[4]>(&::DAT_010c92e0))[i];
            }
        }
    }

    Vector4Comparison result;
    result.m_uiMask = (*reinterpret_cast<const __m128 (*)[16]>(&::DAT_01268460))[resultMask];
    return result;
}
