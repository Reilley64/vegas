
// src/havok/common/internal/convexhull/hkplaneequationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/convexhull/hkplaneequationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <xmmintrin.h>
#include "fnv_simd.h"
#include <cmath>
#include "fnv/symbols_00dd6000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_0104d000.h"
#include <math.h>
#include "fnv/symbols_simd.h"
#include <new>
#include "fnv/decl/FUN_00d74d40_cls.h"
#include "fnv/decl/S00d76120_cls.h"
#include "fnv/decl/enumeration_rework__PlaneHull.h"
#include "fnv/decl/fnv_00d76940__FUN_00d76940_cls.h"
#include "fnv/decl/fnv_00d76ca0__FUN_00d76ca0.h"
struct Arg
{
    void* data;
    int count;
};

struct B
{
    int f0;
    int f1;
    int f2;
    int f3;

};

struct A
{
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;

};

// @fnv 0x00dd6270
int __cdecl ProcessArg(Arg* a, intptr_t second)
{
    if (a->count < 4)
    {
        return 1;
    }

    B objB;
    A objA;

    new ((void *)&(objA)) ::fnv_00d76ca0::FUN_00d76ca0();

    int count = a->count;
    void* data = a->data;

    void* q = ((void *)(reinterpret_cast<::FUN_00d74d40_cls *>(&(objB))->FUN_00d74d40()));
    int iResult = reinterpret_cast<::enumeration_rework::PlaneHull *>(&(objA))->FUN_00d774a0((const ::enumeration_rework::PlaneVector *)(data), count, (intptr_t)(q));

    if (iResult != -1)
    {
        reinterpret_cast<::S00d76120_cls *>(&(objA))->FUN_00d76120(1, (*(::S00d76120_Arr *)(second)));
        reinterpret_cast<::fnv_00d76940::FUN_00d76940_cls *>(&(objA))->FUN_00d76940();
        return 0;
    }

    reinterpret_cast<::fnv_00d76940::FUN_00d76940_cls *>(&(objA))->FUN_00d76940();
    return 1;
}


typedef __m128 hkQuadReal;
struct S00dd6380_hkSimdReal
{
    hkQuadReal m_vValue;
    __forceinline S00dd6380_hkSimdReal(const hkQuadReal& r) : m_vValue(r)
    {}
    __forceinline S00dd6380_hkSimdReal(const float& f) : m_vValue(_mm_load_ss(&f))
    {}
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};
struct S00dd6380_hkVector4
{
    hkQuadReal m_vComponents;
    __forceinline void operator=(const S00dd6380_hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setCross(const S00dd6380_hkVector4& v1, const S00dd6380_hkVector4& v2)
    {
        m_vComponents = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2)),
                                   _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                              _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9)));
    }
    __forceinline S00dd6380_hkSimdReal dot3(const S00dd6380_hkVector4& a) const
    {
        const hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const hkQuadReal sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    __forceinline void set(const S00dd6380_hkSimdReal& a, const S00dd6380_hkSimdReal& b, const S00dd6380_hkSimdReal& c,
                           const S00dd6380_hkSimdReal& d)
    {
        hkQuadReal ac = _mm_unpacklo_ps(a.m_vValue, c.m_vValue);
        hkQuadReal bd = _mm_unpacklo_ps(b.m_vValue, d.m_vValue);
        m_vComponents = _mm_unpacklo_ps(ac, bd);
    }
    template <int I> __forceinline S00dd6380_hkSimdReal getSimdAt() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, I * 0x55);
    }
    __forceinline void setMul4(const S00dd6380_hkSimdReal& r, const S00dd6380_hkVector4& v)
    {
        m_vComponents = _mm_mul_ps(r.m_vValue, v.m_vComponents);
    }
    __forceinline void addMul4(const S00dd6380_hkSimdReal& r, const S00dd6380_hkVector4& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.m_vValue, v.m_vComponents));
    }
    __forceinline void mul4(float r)
    {
        hkQuadReal s = _mm_load_ss(&r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), m_vComponents);
    }
    __forceinline float operator()(int i) const
    {
        return fnv_simd_as<float>(m_vComponents)[i];
    }
};
__forceinline void SetCrossPtr(S00dd6380_hkVector4* dst, const S00dd6380_hkVector4* v1, const S00dd6380_hkVector4* v2)
{
    dst->setCross(*v1, *v2);
}
struct S00dd6380_hkMatrix3
{
    S00dd6380_hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};
template <typename T> __forceinline void hkSwap(T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}
struct S00dd6380_PointResult
{
    S00dd6380_hkVector4 m_kPoint;
    int m_kPointA, m_kPointB, m_iThirdValue;
};
struct S00dd6380_PlaneSet
{
    S00dd6380_hkVector4* m_kPlaneArray;
    int m_iValue;
};

// Keep SP1 scalar negations separate from its packed-mask lowering.
__forceinline __m128 Dd6380NegativeDistances(const float& x, const float& y, const float& z)
{
    if (_MSC_FULL_VER >= 150030729)
    {
        const float nx = -x;
        const float ny = -y;
        const float nz = -z;
        return _mm_setr_ps(nx, ny, nz, 0.0f);
    }
    else
    {
        return _mm_setr_ps(-x, -y, -z, 0.0f);
    }
}
// @fnv 0x00dd6380
int FUN_00dd6380(S00dd6380_PlaneSet* set, int a, int b, int c, S00dd6380_PointResult* out)
{
    const S00dd6380_hkVector4* planes = set->m_kPlaneArray;
    S00dd6380_hkMatrix3 m;
    m.m_kColumn0.setCross(planes[b], planes[c]);
    m.m_kColumn1.setCross(planes[c], planes[a]);
    SetCrossPtr(&m.m_kColumn2, &planes[a], &planes[b]);
    const float det = planes[a].dot3(m.m_kColumn0);
    if ((float)fabs(det) < 1.1920928955078125e-07f)
        return 1;
    const float invDet = 1.0f / det;
    S00dd6380_hkVector4 d;
    d.m_vComponents = Dd6380NegativeDistances(fnv_simd_as<float>(planes[a].m_vComponents)[3], fnv_simd_as<float>(planes[b].m_vComponents)[3],
                                              fnv_simd_as<float>(planes[c].m_vComponents)[3]);
    S00dd6380_hkVector4 p;
    p.setMul4(d.getSimdAt<1>(), m.m_kColumn1);
    p.addMul4(d.getSimdAt<0>(), m.m_kColumn0);
    p.addMul4(d.getSimdAt<2>(), m.m_kColumn2);
    out->m_kPoint = p;
    out->m_kPoint.mul4(invDet);
    out->m_kPointA = a;
    out->m_kPointB = b;
    out->m_iThirdValue = c;
    if (a > b)
        hkSwap(out->m_kPointA, out->m_kPointB);
    return 0;
}
struct VectorComponentValue
{
    hkQuadReal m_vValue;
    VectorComponentValue()
    {}
    VectorComponentValue(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
    VectorComponentValue(const hkQuadReal& r) : m_vValue(r)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
};
struct hkVector4
{
    hkQuadReal m_vComponents;
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setAddMul4(const hkVector4& a, const hkVector4& b, const VectorComponentValue& r)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(r.broadcast(), b.m_vComponents), a.m_vComponents);
    }
    void setCross(const hkVector4& av, const hkVector4& bv)
    {
        hkQuadReal a = _mm_load_ps(fnv_simd_as<float>(av.m_vComponents));
        hkQuadReal b = _mm_load_ps(fnv_simd_as<float>(bv.m_vComponents));
        hkQuadReal c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
        hkQuadReal c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    void set(float x, float y, float z, float w)
    {
        hkQuadReal xz = _mm_unpacklo_ps(_mm_set_ss(x), _mm_set_ss(z));
        hkQuadReal yw = _mm_unpacklo_ps(_mm_set_ss(y), _mm_set_ss(w));
        m_vComponents = _mm_unpacklo_ps(xz, yw);
    }
    void setMul4(const VectorComponentValue& r, const hkVector4& a)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), a.m_vComponents);
    }
    void mul4(const VectorComponentValue& r)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), m_vComponents);
    }
    void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    float getW() const
    {
        return fnv_simd_as<float>(m_vComponents)[3];
    }
    VectorComponentValue getComponent(int i) const
    {
        return i == 0   ? VectorComponentValue(_mm_shuffle_ps(m_vComponents, m_vComponents, 0))
               : i == 1 ? VectorComponentValue(_mm_shuffle_ps(m_vComponents, m_vComponents, 0x55))
                        : VectorComponentValue(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa));
    }
    void setNeg4(const hkVector4& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, DAT_010c44d0);
    }
    VectorComponentValue dot3(const hkVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
    }
};
struct PointResult
{
    hkVector4 m_kPoint;
    int m_kPointA, m_kPointB, m_iThirdValue;
};
struct PlaneSet
{
    hkVector4* m_kPlaneArray;
    int m_iValue;
};
// @fnv 0x00dd6510
int FUN_00dd6510(const hkVector4* direction, PlaneSet* set, int first, int second, PointResult* neg, PointResult* pos)
{
    neg->m_kPointA = -1;
    neg->m_kPointB = -1;
    neg->m_iThirdValue = -1;
    pos->m_kPointA = -1;
    pos->m_kPointB = -1;
    pos->m_iThirdValue = -1;
    bool initialized = false;
    for (int i = 0; i < set->m_iValue; i++)
    {
        if (i == first || i == second)
            continue;
        PointResult p;
        if (FUN_00dd6380((S00dd6380_PlaneSet*)set, first, second, i, (S00dd6380_PointResult*)&p) != 0)
            continue;
        if (!initialized)
        {
            pos->m_kPoint.setAddMul4(p.m_kPoint, *direction, VectorComponentValue(-100000.0f));
            neg->m_kPoint.setNeg4(pos->m_kPoint);
            initialized = true;
        }
        hkVector4 d;
        d.setSub4(pos->m_kPoint, p.m_kPoint);
        if (d.dot3(set->m_kPlaneArray[i]) > -1.1920928955078125e-7f)
        {
            pos->m_kPoint = p.m_kPoint;
            pos->m_kPointA = p.m_kPointA;
            pos->m_kPointB = p.m_kPointB;
            pos->m_iThirdValue = p.m_iThirdValue;
        }
        hkVector4 e;
        e.setSub4(neg->m_kPoint, p.m_kPoint);
        if (e.dot3(set->m_kPlaneArray[i]) > -1.1920928955078125e-7f)
        {
            neg->m_kPoint = p.m_kPoint;
            neg->m_kPointA = p.m_kPointA;
            neg->m_kPointB = p.m_kPointB;
            neg->m_iThirdValue = p.m_iThirdValue;
        }
    }
    if (neg->m_kPointA == -1)
    {
        if (pos->m_kPointA != -1)
        {
            neg->m_kPointA = pos->m_kPointA;
            neg->m_kPointB = pos->m_kPointB;
            neg->m_iThirdValue = pos->m_iThirdValue;
        }
        else
            return 1;
    }
    if (pos->m_kPointA == -1)
    {
        if (neg->m_kPointA == -1)
            return 1;
        pos->m_kPointA = neg->m_kPointA;
        pos->m_kPointB = neg->m_kPointB;
        pos->m_iThirdValue = neg->m_iThirdValue;
    }
    return 0;
}
