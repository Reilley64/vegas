
// src/havok/common/internal/collide/gsk/hkgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/collide/gsk/hkgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv_simd.h"
#include <xmmintrin.h>
#include "fnv/decl/Solver.h"
#include "fnv/symbols_00e62000.h"
#include "fnv/decl/FUN_004b4ab0_Class.h"
#include "fnv/symbols_00e4b000.h"
#include "fnv/symbols_00d22000.h"
extern "C" void _ReadWriteBarrier(void);


#include "fnv/symbols_simd.h"

typedef float hkReal;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setCross(const hkVector4& v1, const hkVector4& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setNeg4(const hkVector4& v);
    __forceinline int lessZeroXYZ() const
    {
        return _mm_movemask_ps(_mm_cmplt_ps(m_vComponents, _mm_setzero_ps())) & 7;
    }
};


__forceinline void hkVector4::setNeg4(const hkVector4& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, ::DAT_010c44d0);
}

static __forceinline int hkDot3LessZero(const hkVector4& a, const hkVector4& b)
{
    __m128 p = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    __m128 xyz = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p));
    return _mm_movemask_ps(xyz) & 1;
}

static __forceinline void hkTranspose3(hkVector4& c0, hkVector4& c1, hkVector4& c2)
{
    __m128 tmp = _mm_unpacklo_ps(c0.m_vComponents, c1.m_vComponents);
    __m128 ctmp = _mm_unpackhi_ps(c0.m_vComponents, c1.m_vComponents);
    c0.m_vComponents = _mm_movelh_ps(tmp, c2.m_vComponents);
    c1.m_vComponents = _mm_shuffle_ps(_mm_movehl_ps(c0.m_vComponents, tmp), c2.m_vComponents, 0xd4);
    c2.m_vComponents = _mm_shuffle_ps(ctmp, c2.m_vComponents, 0xe4);
}

static __forceinline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                                    const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
{
    hkVector4 c0;
    c0.setMul4(a0, b0);
    hkVector4 c1;
    c1.setMul4(a1, b1);
    hkVector4 c2;
    c2.setMul4(a2, b2);
    hkTranspose3(c0, c1, c2);
    dotsOut.setAdd4(c0, c1);
    dotsOut.add4(c2);
}

template <class T> static __forceinline void hkSwap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

struct TriangleVerts
{
    hkVector4 m_kVertices[3];
    hkVector4 m_extra30;
    hkVector4 m_extra40;
    hkVector4 m_extra50;
};

struct TriangleSolver
{
    hkVector4 m_barycentric;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_flipped;
    hkVector4 m_kPoint;
    hkVector4 m_unk30;
    hkVector4 m_unk40;
    hkVector4 m_unk50;
    hkVector4 m_unk60;
    hkVector4 m_unk70;
    hkVector4 m_unk80;
    hkVector4 m_unk90;
    hkVector4 m_kSmartReference;

    int FUN_00e4da90(const hkVector4& p, TriangleVerts& tri, hkVector4& normalOut);
};

// Computes three dot products into m_barycentric, stores the normal, and may flip the winding and swap values when mask is 7.
// @fnv 0x00e4da90
int TriangleSolver::FUN_00e4da90(const hkVector4& p, TriangleVerts& tri, hkVector4& normalOut)
{
    hkVector4 e0;
    e0.setSub4(tri.m_kVertices[2], tri.m_kVertices[1]);
    hkVector4 e1;
    e1.setSub4(tri.m_kVertices[0], tri.m_kVertices[2]);
    hkVector4 e2;
    e2.setSub4(tri.m_kVertices[1], tri.m_kVertices[0]);

    hkVector4 normal;
    normal.setCross(e0, e1);

    hkVector4 d1;
    d1.setSub4(p, tri.m_kVertices[1]);
    hkVector4 d2;
    d2.setSub4(p, tri.m_kVertices[2]);
    hkVector4 d0;
    d0.setSub4(p, tri.m_kVertices[0]);

    hkVector4 c0;
    c0.setCross(d1, e0);
    hkVector4 c1;
    c1.setCross(d2, e1);
    hkVector4 c2;
    c2.setCross(d0, e2);

    dot3_3vs3(c0, normal, c1, normal, c2, normal, m_barycentric);

    int mask = m_barycentric.lessZeroXYZ();
    normalOut = normal;
    if (mask == 7)
    {
        hkVector4 diff;
        diff.setSub4(m_kPoint, m_kSmartReference);
        if (hkDot3LessZero(diff, normal))
        {
            normal.setNeg4(normal);
            hkSwap(tri.m_kVertices[0], tri.m_kVertices[1]);
            _ReadWriteBarrier();
            normalOut = normal;
            hkSwap(fnv_simd_as<float>(m_barycentric.m_vComponents)[0], fnv_simd_as<float>(m_barycentric.m_vComponents)[1]);
            hkVector4* __restrict pExtra = &tri.m_extra40;
            hkSwap(pExtra[0], pExtra[1]);
            m_flipped = 1;
        }
    }
    return mask;
}

namespace fnv_00e4dc70 {

struct hkVector4
{
    __m128 m_vComponents;
    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const hkVector4& a, const hkVector4& b)
    {
        const __m128 a1 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9);
        const __m128 a2 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2);
        const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9);
        const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2);
        const __m128 c0 = _mm_mul_ps(a1, b2);
        const __m128 c1 = _mm_mul_ps(a2, b1);
        m_vComponents = _mm_sub_ps(c0, c1);
    }
    void setMul4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    int lessZero3() const
    {
        return _mm_movemask_ps(_mm_cmplt_ps(m_vComponents, _mm_setzero_ps())) & 7;
    }
    int FUN_00e4dc70(const hkVector4&, const hkVector4*, void*);
};
static inline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                             const hkVector4& a2, const hkVector4& b2, hkVector4& out)
{
    __m128 d0 = _mm_mul_ps(a0.m_vComponents, b0.m_vComponents);
    __m128 d1 = _mm_mul_ps(a1.m_vComponents, b1.m_vComponents);
    __m128 d2 = _mm_mul_ps(a2.m_vComponents, b2.m_vComponents);
    {
        __m128 low, high;
        low = _mm_unpacklo_ps(d0, d1);
        high = _mm_shuffle_ps(_mm_unpackhi_ps(d0, d1), d2, 0xe4);
        d0 = _mm_movelh_ps(low, d2);
        d1 = _mm_shuffle_ps(_mm_movehl_ps(d0, low), d2, 0xd4);
        d2 = high;
    }
    out.m_vComponents = _mm_add_ps(_mm_add_ps(d0, d1), d2);
}

// Computes three dot products of cross products with the normal, stores them, and returns a bitmask of negative first three components.
// @fnv 0x00e4dc70
int hkVector4::FUN_00e4dc70(const hkVector4& point, const hkVector4* apTriangle, void*)
{
    const hkVector4& v0 = apTriangle[0];
    const hkVector4& v1 = apTriangle[1];
    const hkVector4& v2 = apTriangle[2];
    hkVector4 e0;
    e0.setSub4(v2, v1);
    hkVector4 e1;
    e1.setSub4(v0, v2);
    hkVector4 e2;
    e2.setSub4(v1, v0);
    hkVector4 n;
    n.setCross(e0, e1);
    hkVector4 p1;
    p1.setSub4(point, v1);
    hkVector4 p2;
    p2.setSub4(point, v2);
    hkVector4 p0;
    p0.setSub4(point, v0);
    hkVector4 c0;
    c0.setCross(p1, e0);
    hkVector4 c1;
    c1.setCross(p2, e1);
    hkVector4 c2;
    c2.setCross(p0, e2);
    dot3_3vs3(c0, n, c1, n, c2, n, *this);
    return lessZero3();
}
}  // namespace fnv_00e4dc70


struct Out
{
    int* p;
    Out(int* a) : p(a)
    {}
};
static const __m128 one4 = {1, 1, 1, 1};

struct Scalar
{
    __m128 q;
    Scalar()
    {}
    Scalar(const __m128& a) : q(a)
    {}
    operator float() const
    {
        float value;
        _mm_store_ss(&value, q);
        return value;
    }
    __m128 broadcast() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
inline Scalar operator*(const Scalar& a, const Scalar& b)
{
    return _mm_mul_ss(a.q, b.q);
}
inline Scalar operator-(const Scalar& a, const Scalar& b)
{
    return _mm_sub_ss(a.q, b.q);
}
inline Scalar operator/(const Scalar& a, const Scalar& b)
{
    return _mm_div_ss(a.q, b.q);
}
struct V
{
    union
    {
        __m128 q;
        struct
        {
            unsigned x, y, z, w;
        };
    };
    V()
    {}
    V(const V& a) : x(a.x), y(a.y), z(a.z), w(a.w)
    {}
    V& operator=(const V& a)
    {
        q = a.q;
        return *this;
    }
    void sub(const V& a, const V& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    void cross(const V& a, const V& b)
    {
        __m128 l = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 r = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(l, r);
    }
    Scalar dot(const V& b) const
    {
        __m128 p = _mm_mul_ps(q, b.q);
        __m128 t = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), t);
    }
    void interpolate(const V& a, const V& b, const Scalar& f)
    {
        __m128 t = f.broadcast();
        __m128 s = _mm_sub_ps(one4, t);
        q = _mm_add_ps(_mm_mul_ps(s, a.q), _mm_mul_ps(t, b.q));
    }
    Scalar component(int i) const
    {
        switch (i)
        {
        case 0:
            return q;
        case 1:
            return _mm_shuffle_ps(q, q, 0x55);
        case 2:
            return _mm_shuffle_ps(q, q, 0xaa);
        default:
            return _mm_shuffle_ps(q, q, 0xff);
        }
    }
};
static __forceinline void Swap(V& a, V& b)
{
    V saved = a;
    a = b;
    b = saved;
}
static __forceinline bool ComparePlane(const V& oldValue, const V& newValue, int i, int j)
{
    Scalar oldI = oldValue.component(i);
    Scalar oldJ = oldValue.component(j);
    Scalar deltaI = newValue.component(i) - oldI;
    Scalar deltaJ = newValue.component(j) - oldJ;
    return float(oldJ * deltaI) > float(oldI * deltaJ);
}

struct Shape
{
    V points[4];
    V anchors[3];
};
struct Clip
{
    V point;
    V separation;
    float distance;
};
struct Both
{
    Clip first;
    Clip second;
};

static __forceinline void ThreeDots(const V& first, const V& firstWeight, const V& second, const V& secondWeight,
                                    const V& third, const V& thirdWeight, V& out)
{
    __m128 products0 = _mm_mul_ps(first.q, firstWeight.q);
    __m128 products1 = _mm_mul_ps(second.q, secondWeight.q);
    __m128 products2 = _mm_mul_ps(third.q, thirdWeight.q);
    __m128 lower = _mm_unpacklo_ps(products0, products1);
    __m128 upper = _mm_shuffle_ps(_mm_unpackhi_ps(products0, products1), products2, 0xe4);
    products0 = _mm_movelh_ps(lower, products2);
    products1 = _mm_shuffle_ps(_mm_movehl_ps(products0, lower), products2, 0xd4);
    products2 = upper;
    out.q = _mm_add_ps(_mm_add_ps(products0, products1), products2);
}

static __forceinline int mask(const V& p, const Shape* b)
{
    V e0, e1, e2, n, d0, d1, d2, c0, c1, c2;
    e0.sub(b->points[2], b->points[1]);
    e1.sub(b->points[0], b->points[2]);
    e2.sub(b->points[1], b->points[0]);
    n.cross(e0, e1);
    d0.sub(p, b->points[1]);
    d1.sub(p, b->points[2]);
    d2.sub(p, b->points[0]);
    c0.cross(d0, e0);
    c1.cross(d1, e1);
    c2.cross(d2, e2);
    V sum;
    ThreeDots(c0, n, c1, n, c2, n, sum);
    return _mm_movemask_ps(_mm_cmplt_ps(sum.q, _mm_setzero_ps())) & 7;
}
static __forceinline void ReplaceSelected(V& point, V& anchor, const V& newPoint, const V& newAnchor, int* count)
{
    point = newPoint;
    anchor = newAnchor;
    *count = 2;
}

static __forceinline void CollapseFirst(Shape* shape, const V& point, int* count)
{
    *count = 1;
    shape->points[0] = point;
    shape->anchors[0] = shape->anchors[1];
}

struct State
{
    V origin;
    int m10, m14, m18, m1c;
    V m20, m30, m40, m50, m60, m70, m80, m90, ma0, mb0, mc0, md0, me0, mf0, m100, m110;
    V direction;
    int FUN_00e4dc70(V*, Shape*, V*);
    int FUN_00e4bbe0(Shape*, Shape*, int*, int*, unsigned char, int);
};
// Branches on flag, updates shape points and anchors, writes through out1 or out2 on selected paths, and returns status values.
// @fnv 0x00e4bbe0
int State::FUN_00e4bbe0(Shape* apShapeA, Shape* apShapeB, int* __restrict apOutCount1, int* __restrict apOutCount2,
                        unsigned char flag, int val)
{
    if (flag)
    {
        V edge0, edge1, normal;
        edge0.sub(apShapeB->points[1], apShapeB->points[2]);
        edge1.sub(apShapeB->points[0], apShapeB->points[2]);
        normal.cross(edge0, edge1);
        V d0;
        d0.sub(apShapeA->points[0], apShapeB->points[0]);
        Scalar s0 = d0.dot(normal);
        d0.sub(apShapeA->points[1], apShapeB->points[0]);
        Scalar s1 = d0.dot(normal);
        if (_mm_movemask_ps((s0 * s1).q) & 1)
        {
            Scalar t = s0 / (s0 - s1);
            V p;
            p.interpolate(apShapeA->points[0], apShapeA->points[1], t);
            if (mask(p, apShapeB) == 7)
                return 1;
        }
        else
        {
            if (float(s0 * s0) > float(s1 * s1))
            {
                Swap(apShapeA->points[0], apShapeA->points[1]);
                Swap(apShapeA->anchors[0], apShapeA->anchors[1]);
            }
            if (reinterpret_cast<::TriangleSolver *>(this)->FUN_00e4da90((*(const ::hkVector4 *)(apShapeA)), (*(::TriangleVerts *)(apShapeB)), (*(::hkVector4 *)(&direction))) == 7)
            {
                *apOutCount1 = 1;
                return 0;
            }
        }
        V diff;
        diff.sub(apShapeA->points[1], apShapeA->points[0]);
        Clip clip0, clip1;
        Clip* later = &clip1;
        ::FUN_00d22e40((*(const ::hkVector4 *)(apShapeA)), (*(const ::hkVector4 *)(&diff)), (*(const ::hkVector4 *)(&apShapeB->points[2])), (*(const ::hkVector4 *)(&edge0)), (*(::VectorPairResult *)(&clip0)));
        ::FUN_00d22e40((*(const ::hkVector4 *)(apShapeA)), (*(const ::hkVector4 *)(&diff)), (*(const ::hkVector4 *)(&apShapeB->points[2])), (*(const ::hkVector4 *)(&edge1)), (*(::VectorPairResult *)(later)));
        int index = clip0.distance > clip1.distance ? 1 : 0;
        ReplaceSelected(apShapeB->points[index], apShapeB->anchors[index], apShapeB->points[2], apShapeB->anchors[2],
                        apOutCount2);
        return 2;
    }
    else
    {
        V saved = origin;
        V* end = &apShapeA->points[0];
        V d0;
        d0.sub(*end, apShapeB->points[0]);
        Scalar s0 = d0.dot(direction);
        ++end;
        d0.sub(*end, apShapeB->points[0]);
        Scalar s1 = d0.dot(direction);
        if (_mm_movemask_ps((s0 * s1).q) & 1)
        {
            V p;
            p.interpolate(apShapeA->points[0], *end, s0 / (s0 - s1));
            if (mask(p, apShapeB) == 7)
                return 1;
        }
        int r = FUN_00e4dc70(end, apShapeB, &direction);
        if (r == 7)
        {
            CollapseFirst(apShapeA, *end, apOutCount1);
            m14 = val;
            return 0;
        }
        *apOutCount2 = 2;
        if (r == 6)
            goto replace0;
        if (r == 5)
            goto replace1;
        if (r == 3)
            goto done;
        if (r == 1)
        {
            if (ComparePlane(saved, origin, 1, 2))
                goto done;
            goto replace1;
        }
        if (r == 2)
        {
            if (ComparePlane(saved, origin, 2, 0))
                goto replace0;
            goto done;
        }
        else if (r == 4)
        {
            if (ComparePlane(saved, origin, 0, 1))
                goto replace1;
        }
    replace0:
        apShapeB->points[0] = apShapeB->points[2];
        apShapeB->anchors[0] = apShapeB->anchors[2];
    done:
        return 2;
    replace1:
        apShapeB->points[1] = apShapeB->points[2];
        apShapeB->anchors[1] = apShapeB->anchors[2];
        return 2;
    }
}
struct __declspec(align(16)) Scalar4
{
    float x, y, z, w;
};
union FourFloatVector
{
    __m128 quad;
    Scalar4 value;
    struct
    {
        unsigned int x, y, z, w;
    } bits;
};
struct Transform
{
    FourFloatVector columns[4];
};
struct Differences
{
    Scalar4 d0, d1, d2, d3;
};
struct SimplexContext
{
    SimplexContext()
    {}
    Transform transform;
    Scalar4 tolerance;
    float epsilon;
    const void* shapeA;
    const void* shapeB;
    int status;
    FourFloatVector* pointsA;
    FourFloatVector* pointsB;
    Scalar4* differences;
    int count;
};
struct Simplex
{
    __m128 unk00, unk10;
    FourFloatVector pointsA[4];
    __m128 unk60, unk70, unk80, unk90;
    FourFloatVector transformedB[4];
    FourFloatVector pointsB[4];
    FourFloatVector result;
    void FUN_00e4c230(const void*, const void*, const Transform*, int*, int*, FourFloatVector*);
};
// @fnv 0x00e4c230
void Simplex::FUN_00e4c230(const void* shapeA, const void* shapeB, const Transform* transform, int* countA, int* countB,
                           FourFloatVector* output)
{
    int simplexCount = 4;
    if (*countB >= 3)
    {
        if (*countB > 3)
        {
            pointsA[3].quad = pointsA[0].quad;
        }
        else if (*countA > 1)
        {
            pointsA[3].quad = pointsA[1].quad;
            pointsB[3].quad = pointsB[0].quad;
            transformedB[3].quad = transformedB[0].quad;
        }
        else
            simplexCount = 3;
        pointsA[1].quad = pointsA[0].quad;
        pointsA[2].quad = pointsA[0].quad;
    }
    else if (*countA >= 3)
    {
        if (*countA > 3)
        {
            pointsB[3].quad = pointsB[0].quad;
            transformedB[3].quad = transformedB[0].quad;
        }
        else if (*countB > 1)
        {
            pointsA[3].quad = pointsA[0].quad;
            pointsB[3].quad = pointsB[1].quad;
            transformedB[3].quad = transformedB[1].quad;
        }
        else
            simplexCount = 3;
        pointsB[1].quad = pointsB[0].quad;
        transformedB[1].quad = transformedB[0].quad;
        pointsB[2].quad = pointsB[0].quad;
        transformedB[2].quad = transformedB[0].quad;
    }
    else
    {
        Scalar4 t = pointsA[0].value;
        __m128 a = _mm_load_ps(&t.x);
        pointsA[*countA].quad = a;
        pointsA[*countA + 1].quad = a;
        t = pointsB[0].value;
        __m128 b = _mm_load_ps(&t.x);
        pointsB[*countB].quad = b;
        pointsB[*countB + 1].quad = b;
        t = transformedB[0].value;
        __m128 tb = _mm_load_ps(&t.x);
        transformedB[*countB].quad = tb;
        transformedB[*countB + 1].quad = tb;
        simplexCount = 1;
    }
    Differences differences;
    SimplexContext context;
    float tolerance = 0.0001f;
    context.epsilon = 0.0001f * 0.0001f;
    _mm_store_ps(&differences.d0.x, _mm_sub_ps(pointsA[0].quad, transformedB[0].quad));
    _mm_store_ps(&differences.d1.x, _mm_sub_ps(pointsA[1].quad, transformedB[1].quad));
    _mm_store_ps(&differences.d2.x, _mm_sub_ps(pointsA[2].quad, transformedB[2].quad));
    _mm_store_ps(&differences.d3.x, _mm_sub_ps(pointsA[3].quad, transformedB[3].quad));
    context.transform.columns[0].quad = transform->columns[0].quad;
    context.transform.columns[1].quad = transform->columns[1].quad;
    context.transform.columns[2].quad = transform->columns[2].quad;
    context.transform.columns[3].quad = transform->columns[3].quad;
    _mm_store_ps(&context.tolerance.x, _mm_shuffle_ps(_mm_load_ss(&tolerance), _mm_load_ss(&tolerance), 0));
    context.shapeA = shapeA;
    context.shapeB = shapeB;
    context.status = 0;
    context.pointsA = pointsA;
    context.pointsB = pointsB;
    context.differences = &differences.d0;
    context.count = simplexCount;
    if (reinterpret_cast<::Solver *>(&(context))->FUN_00e63770((::E63Out *)(output)) == 5)
    {
        ::FUN_00e62740((::Shape *)(shapeA), (::Shape *)(shapeB), (const ::Matrix *)(transform), (::Vec *)(pointsA), (::Vec *)(pointsB), (::SamplingOutPair_e62740 *)(output));
        *countA = 1;
        *countB = 1;
    }
    else
    {
        *countA = 3;
        *countB = 3;
        if ((pointsA[1].bits.w & 0xc0ffffff) == (pointsA[2].bits.w & 0xc0ffffff) ||
            (pointsA[0].bits.w & 0xc0ffffff) == (pointsA[2].bits.w & 0xc0ffffff))
            --*countA;
        if (*countA >= 2 && ((pointsA[0].bits.w ^ pointsA[1].bits.w) & 0xc0ffffff) == 0)
        {
            --*countA;
            pointsA[0].quad = pointsA[*countA].quad;
        }
        if ((pointsB[1].bits.w & 0xc0ffffff) == (pointsB[2].bits.w & 0xc0ffffff) ||
            (pointsB[0].bits.w & 0xc0ffffff) == (pointsB[2].bits.w & 0xc0ffffff))
            --*countB;
        if (*countB >= 2 && ((pointsB[0].bits.w ^ pointsB[1].bits.w) & 0xc0ffffff) == 0)
        {
            --*countB;
            pointsB[0].quad = pointsB[*countB].quad;
        }
        Scalar4 c0 = transform->columns[0].value;
        Scalar4 c1 = transform->columns[1].value;
        Scalar4 c2 = transform->columns[2].value;
        Scalar4 c3 = transform->columns[3].value;
        __m128 x = _mm_load_ps(&c0.x);
        __m128 y = _mm_load_ps(&c1.x);
        __m128 z = _mm_load_ps(&c2.x);
        __m128 t = _mm_load_ps(&c3.x);
        int i = *countB - 1;
        FourFloatVector* src = &pointsB[i];
        do
        {
            __m128 p = src->quad;
            src[-4].quad = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0x55), y), _mm_mul_ps(_mm_shuffle_ps(p, p, 0), x)),
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p, p, 0xaa), z), t));
            --i;
            --src;
        } while (i >= 0);
        if (*countA + *countB > 4)
        {
            if (*countA > *countB)
            {
                *countA = 3;
                *countB = 1;
            }
            else
            {
                *countB = 3;
                *countA = 1;
            }
        }
    }
    result.quad = output->quad;
}


typedef float Real;
typedef unsigned char UChar;
typedef signed char SChar;

template <class T> class Pad
{
  public:
    __forceinline Pad()
    {}
    __forceinline Pad(T e) : m_kStorage(e)
    {}
    __forceinline void operator=(T e)
    {
        m_kStorage = e;
    }
    __forceinline T val() const
    {
        return m_kStorage;
    }
    __forceinline T operator->() const
    {
        return m_kStorage;
    }
    __forceinline operator T() const
    {
        return val();
    }

  private:
    T m_kStorage;
};

class SReal
{
  public:
    SReal(const __m128& x) : m_vValue(x)
    {}
    SReal(Real x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    SReal()
    {}
    operator Real() const
    {
        Real s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

class Vec4;

class VComp
{
  public:
    enum Mask
    {
        MASK_NONE = 0,
        MASK_X = 1,
        MASK_Y = 2,
        MASK_XY = 3,
        MASK_Z = 4,
        MASK_XZ = 5,
        MASK_YZ = 6,
        MASK_XYZ = 7,
        MASK_W = 8,
        MASK_XW = 9,
        MASK_YW = 10,
        MASK_XYW = 11,
        MASK_ZW = 12,
        MASK_XZW = 13,
        MASK_YZW = 14,
        MASK_XYZW = 15
    };
    __forceinline int allAreSet(Mask m) const
    {
        return (_mm_movemask_ps(m_uiMask) & m) == m;
    }
    __forceinline int anyIsSet(Mask m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }
    __forceinline int allAreSet() const
    {
        return _mm_movemask_ps(m_uiMask) == MASK_XYZW;
    }
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(m_uiMask);
    }
    __forceinline int GetLaneMask(Mask m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }

  private:
    __m128 m_uiMask;
    friend class Vec4;
};


class Rot;
class Xform;

class Vec4
{
  public:
    __forceinline void operator=(const Vec4& v);
    __forceinline void operator=(const __m128& v);
    __forceinline void set(Real x, Real y, Real z, Real w = 0);
    __forceinline void SetAllComponents(const SReal& x);
    __forceinline void setZero4();
    __forceinline int getInt24W() const;
    __forceinline void setSub4(const Vec4& a, const Vec4& b);
    __forceinline void setAddMul4(const Vec4& a, const Vec4& b, const SReal& r);
    __forceinline void setCross(const Vec4& a, const Vec4& b);
    __forceinline void setInterpolate4(const Vec4& a, const Vec4& b, const SReal& t);
    __forceinline VComp compareLessThan4(const Vec4& a) const;
    __forceinline VComp compareLessThanZero4() const;
    __forceinline VComp compareGreaterThan4(const Vec4& a) const;
    __forceinline void setNeg4(const Vec4& v);
    void FUN_00c7f700(const Rot& a, const Vec4& b);
    __forceinline void rotInvDir(const Rot& a, const Vec4& b);
    __forceinline void xformPos(const Xform& a, const Vec4& b);
    __forceinline SReal dot3(const Vec4& a) const;
    __forceinline SReal length3() const;
    __forceinline SReal lengthInverse3() const;
    __forceinline SReal normalizeWithLength3();
    __forceinline void fastNormalize3NonZero();
    __forceinline Real& operator()(int i);
    __forceinline const Real& operator()(int i) const;
    __forceinline SReal getSimdAt(int i) const;
    __forceinline __m128& getQuad();
    __forceinline const __m128& getQuad() const;

  private:
    __m128 m_vComponents;

  public:
    operator __m128() const
    {
        return m_vComponents;
    }
};

class Mat3
{
  public:
    __forceinline Mat3()
    {}
    __forceinline Vec4& getColumn(int i);
    __forceinline const Vec4& getColumn(int i) const;

  protected:
    Vec4 m_kColumn0;
    Vec4 m_kColumn1;
    Vec4 m_kColumn2;
};

class Rot : public Mat3
{
};

class Xform
{
  public:
    __forceinline Xform()
    {}
    __forceinline Xform(const Xform& t);
    __forceinline const Vec4& getTranslation() const;
    __forceinline Rot& getRotation();
    __forceinline const Rot& getRotation() const;

  public:
    Rot m_rotation;
    Vec4 m_vTranslation;
};

inline __m128& Vec4::getQuad()
{
    return m_vComponents;
}
inline const __m128& Vec4::getQuad() const
{
    return m_vComponents;
}
inline void Vec4::set(Real a, Real b, Real c, Real d)
{
    m_vComponents = _mm_setr_ps(a, b, c, d);
}
inline void Vec4::SetAllComponents(const SReal& a)
{
    m_vComponents = _mm_shuffle_ps(a.getQuad(), a.getQuad(), 0);
}
inline void Vec4::setZero4()
{
    m_vComponents = _mm_setzero_ps();
}
int Vec4::getInt24W() const
{
    return (reinterpret_cast<const unsigned int*>(this))[3] & ~0x3f000000;
}
inline void Vec4::setSub4(const Vec4& v0, const Vec4& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void Vec4::setAddMul4(const Vec4& a, const Vec4& b, const SReal& r)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
}
inline void Vec4::setCross(const Vec4& v0, const Vec4& v1)
{
    __m128 cross0;
    cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1;
    cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                        _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
inline void Vec4::setInterpolate4(const Vec4& v0, const Vec4& v1, const SReal& _t)
{
    __m128 t = _t.broadcast();
    __m128 s = _mm_sub_ps(::DAT_010ec7f0, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}
inline VComp Vec4::compareLessThan4(const Vec4& a) const
{
    VComp m;
    m.m_uiMask = _mm_cmplt_ps(m_vComponents, a.m_vComponents);
    return m;
}
inline VComp Vec4::compareLessThanZero4() const
{
    Vec4 zero;
    zero.setZero4();
    VComp m;
    m.m_uiMask = _mm_cmplt_ps(m_vComponents, zero);
    return m;
}
inline VComp Vec4::compareGreaterThan4(const Vec4& a) const
{
    return a.compareLessThan4(*this);
}
inline SReal Vec4::dot3(const Vec4& a) const
{
    __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
}
inline SReal Vec4::length3() const
{
    return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
inline SReal Vec4::lengthInverse3() const
{
    const __m128 half = _mm_set_ss(0.5f);
    const __m128 three = _mm_set_ss(3.0f);
    const __m128 zero = _mm_set_ss(0.0f);
    const __m128 len2 = this->dot3(*this).getQuad();
    const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
    const __m128 approx = _mm_rsqrt_ss(len2);
    const __m128 refined =
        _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
    return _mm_andnot_ps(len2EqualsZero, refined);
}
inline SReal Vec4::normalizeWithLength3()
{
    __m128 len2 = this->dot3(*this).getQuad();
    __m128 lenInv = lengthInverse3().broadcast();
    m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    return _mm_mul_ss(len2, lenInv);
}
inline void Vec4::fastNormalize3NonZero()
{
    __m128 len2 = this->dot3(*this).getQuad();
    SReal approx = _mm_rsqrt_ss(len2);
    m_vComponents = _mm_mul_ps(m_vComponents, approx.broadcast());
}
inline SReal Vec4::getSimdAt(int i) const
{
    switch (i)
    {
    case 0:
        return m_vComponents;
    case 1:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0x55);
    case 2:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xaa);
    case 3:
    default:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
}

inline Vec4& Mat3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}
inline const Vec4& Mat3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}

Xform::Xform(const Xform& t)
{
    const Vec4 r0 = t.m_rotation.getColumn(0);
    const Vec4 r1 = t.m_rotation.getColumn(1);
    const Vec4 r2 = t.m_rotation.getColumn(2);
    const Vec4 r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}
const Vec4& Xform::getTranslation() const
{
    return m_vTranslation;
}
Rot& Xform::getRotation()
{
    return m_rotation;
}
const Rot& Xform::getRotation() const
{
    return m_rotation;
}

inline void Vec4::rotInvDir(const Rot& r, const Vec4& b)
{
    __m128 c0 = r.getColumn(0).m_vComponents;
    __m128 c1 = r.getColumn(1).m_vComponents;
    __m128 c2 = r.getColumn(2).m_vComponents;
    {
        __m128 _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, 0xe4);
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, 0xd4);
        c2 = _ctmp;
    }
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(c0, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(c1, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

inline void Vec4::xformPos(const Xform& t, const Vec4& b)
{
    const Rot& r = t.getRotation();
    __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    __m128 r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    __m128 r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    __m128 r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.getTranslation().m_vComponents));
}

inline int __cdecl isNeg(const SReal& r0)
{
    return _mm_movemask_ps(r0.getQuad()) & VComp::MASK_X;
}

class VUtil
{
  public:
    __forceinline static void __cdecl mulSigns4(Vec4& inout, const Vec4& signs);
    __forceinline static void __cdecl TransformPointArray(const Xform& t, const Vec4* vectorsIn, int numVectors,
                                                          Vec4* vectorsOut);
    __forceinline static void __cdecl dot3_3vs3(const Vec4& a0, const Vec4& b0, const Vec4& a1, const Vec4& b1,
                                                const Vec4& a2, const Vec4& b2, Vec4& dotsOut);
    __forceinline static void __cdecl dot3_4vs4(const Vec4& a0, const Vec4& b0, const Vec4& a1, const Vec4& b1,
                                                const Vec4& a2, const Vec4& b2, const Vec4& a3, const Vec4& b3,
                                                Vec4& dotsOut);
};

inline void __cdecl VUtil::mulSigns4(Vec4& inout, const Vec4& signs)
{
    inout.getQuad() = _mm_xor_ps(inout.getQuad(), _mm_and_ps(signs.getQuad(), ::DAT_010c44d0));
}

inline void __cdecl VUtil::TransformPointArray(const Xform& t, const Vec4* vectorsIn, int numVectors, Vec4* vectorsOut)
{
    Xform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i].xformPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}

inline void __cdecl VUtil::dot3_4vs4(const Vec4& a0, const Vec4& b0, const Vec4& a1, const Vec4& b1, const Vec4& a2,
                                     const Vec4& b2, const Vec4& a3, const Vec4& b3, Vec4& dotsOut)
{
    dotsOut(0) = a0.dot3(b0);
    dotsOut(1) = a1.dot3(b1);
    dotsOut(2) = a2.dot3(b2);
    dotsOut(3) = a3.dot3(b3);
}

class SegUtil
{
  public:
    enum
    {
        CLSLS_POINTA_START = 1,
        CLSLS_POINTA_END = 2,
        CLSLS_POINTB_START = 4,
        CLSLS_POINTB_END = 8
    };
    struct Result
    {
        Vec4 m_kFirstVector;
        Vec4 m_kClosestPointOnSecond;
        Pad<Real> m_fValue;
    };
};

extern const SChar DAT_010ececc[];
extern const SChar DAT_010eced4[];

struct GskOut
{
    Vec4 m_vPointOnShapeA;
    Vec4 m_vPointOnShapeB;
};

struct GskCache
{
    UChar m_ausVertexIds[4];
    UChar m_ucVertexCount;
    UChar m_ucUnknownByte;
};

struct GskShape
{
    virtual ~GskShape()
    {}
    virtual void GetSupportPoint(const Vec4& direction, Vec4* supportingVertexOut) const = 0;
    virtual void GetVerticesForIds(UChar* ids, int numIds, Vec4* verticesOut) const;
};

enum GskStatus
{
    GSK_OK = 0,
    GSK_PD_HEURISTIC_SAMPLING = 1,
    GSK_PD_OUT_OF_MEMORY = 2,
    GSK_PD_DISTANCE_TOO_BIG = 3,
    GSK_PENETRATING = 4,
    GSK_PD_UNSOLVABLE = 5
};


extern const VComp::Mask DAT_010ec600[];
extern const VComp::Mask DAT_010ec5f0[];

class Gsk
{
  public:
    struct Input
    {
        Xform m_kTransform;
        Pad<const GskShape*> m_pShapeA;
        Pad<const GskShape*> m_pShapeB;
        SReal m_fBlendWeight;
    };

    GskStatus FUN_00e4c730(const Input& input, GskCache* __restrict cache, GskOut& output);

    enum
    {
        GSK_NONE_NONE = 0,
        GSK_POINT_POINT = 9,
        GSK_POINT_EDGE = 10,
        GSK_EDGE_POINT = 17,
        GSK_POINT_TRIANGLE = 11,
        GSK_TRIANGLE_POINT = 25,
        GSK_EDGE_TRIANGLE = 19,
        GSK_TRIANGLE_EDGE = 26,
        GSK_POINT_TETRA = 12,
        GSK_TETRA_POINT = 33,
        GSK_EDGE_EDGE = 18
    };
    enum NextCase
    {
        NEXT_IS_BREAK = 0,
        NEXT_IS_PENETRATION = 1,
        NEXT_IS_EDGE_EDGE = 2
    };
    enum SupportTypes
    {
        BUILD_NEG_SUPPORT = -1,
        BUILD_NO_SUPPORT = 0,
        BUILD_POS_SUPPORT = 1
    };
    enum SupportState
    {
        SUPPORT_CHANGED = 0,
        DONT_CALL_GET_SUPPORTING_VERTEX_A = 1,
        DONT_CALL_GET_SUPPORTING_VERTEX_B = -1
    };
    enum ReduceDimensionResult
    {
        REDUCE_DIMENSION_OK = 0,
        REDUCE_DIMENSION_PENETRATION = 1
    };

  protected:
    int checkTri0(const Vec4& support, Vec4* __restrict vertices, Vec4& normalOut);
    int isPointInTriangle(const Vec4& point, const Vec4* __restrict vertices);
    NextCase FUN_00e4bbe0(Vec4* __restrict vertexA, Vec4* __restrict vertexB, Pad<int>& dimA, Pad<int>& dimB,
                          bool comingFromEdgeEdge, SupportTypes supportType);
    __forceinline ReduceDimensionResult reduceDimension(Pad<int>& dimA, Pad<int>& dimB, Vec4& support);
    void FUN_00e4c230(const GskShape* shapeA, const GskShape* shapeB, const Xform& aTb, Pad<int>& dimA, Pad<int>& dimB,
                      GskOut& output);

  public:
    Vec4 m_pCachedPoint;
    Pad<int> m_iCacheState;
    SupportState m_eSupportState;
    Pad<unsigned int> m_uiCacheFlags;
    Pad<int> m_iFeatureChange;
    Vec4 m_akPackedVerticesA[4];
    Vec4 m_iFadeNodeMode[4];
    Vec4 m_akCachedVectors[4];
    Vec4 m_akPackedVerticesB[4];
    Vec4 m_pSupport;
    SegUtil::Result m_kVectorPairResult;
};

static __forceinline int process_point_edge(Vec4* __restrict vertexA, Vec4* __restrict vertexB, int dimB, Vec4& support,
                                            Gsk::SupportTypes stype)
{
    Vec4 edge;
    edge.setSub4(vertexB[1], vertexB[0]);
    Vec4 a;
    a.setSub4(vertexB[1], vertexA[0]);
    Vec4 b;
    b.setSub4(vertexB[0], vertexA[0]);
    SReal adot = a.dot3(edge);
    SReal bdot = b.dot3(edge);
    int aneg = isNeg(adot);
    int bneg = isNeg(bdot);
    if (aneg != bneg)
    {
        edge.fastNormalize3NonZero();
        Vec4 c;
        c.setCross(a, b);
        if (stype == Gsk::BUILD_POS_SUPPORT)
        {
            support.setCross(edge, c);
        }
        else
        {
            support.setCross(c, edge);
        }
    }
    else
    {
        if (aneg)
        {
            vertexB[0] = vertexB[1];
            vertexB[4] = vertexB[5];
        }
        dimB = 1;
        if (stype == Gsk::BUILD_POS_SUPPORT)
        {
            support.setSub4(vertexA[0], vertexB[0]);
        }
        else
        {
            support.setSub4(vertexB[0], vertexA[0]);
        }
    }
    return dimB;
}

Gsk::ReduceDimensionResult Gsk::reduceDimension(Pad<int>& dimA, Pad<int>& dimB, Vec4& support)
{
    m_eSupportState = SUPPORT_CHANGED;
    while (1)
    {
        switch ((dimA << 3) | dimB)
        {
        case GSK_POINT_POINT:
        case_point_point:
            m_pSupport.setSub4(m_akPackedVerticesA[0], m_akCachedVectors[0]);
            break;

        case GSK_POINT_EDGE:
        case_point_edge:
            dimB = process_point_edge(m_akPackedVerticesA, m_akCachedVectors, dimB, m_pSupport, BUILD_POS_SUPPORT);
            break;

        case GSK_EDGE_POINT:
        case_edge_point:
            dimA = process_point_edge(m_akCachedVectors, m_akPackedVerticesA, dimA, m_pSupport, BUILD_NEG_SUPPORT);
            break;

        case GSK_POINT_TRIANGLE:
        case_point_triangle: {
            int mask = reinterpret_cast<::TriangleSolver *>(this)->FUN_00e4da90((const ::hkVector4 &)(m_akPackedVerticesA[0]), (::TriangleVerts &)(m_akCachedVectors), (::hkVector4 &)(m_pSupport));
            if (mask == VComp::MASK_XYZ)
            {
                break;
            }
            int CI = DAT_010ececc[mask];
            dimB = 2;
            if (CI < 0)
            {
                CI += 8;
                CI &= 3;
                m_akCachedVectors[CI] = m_akCachedVectors[2];
                m_akPackedVerticesB[CI] = m_akPackedVerticesB[2];
                goto case_point_edge;
            }
            int LI = DAT_010eced4[CI];
            int UI = DAT_010eced4[CI + 2];

            Vec4 diff;
            diff.setSub4(m_akPackedVerticesA[0], m_akCachedVectors[CI]);
            Vec4 ledge;
            ledge.setSub4(m_akCachedVectors[LI], m_akCachedVectors[CI]);
            Vec4 uedge;
            uedge.setSub4(m_akCachedVectors[UI], m_akCachedVectors[CI]);

            if (isNeg(diff.dot3(ledge)))
            {
                Vec4 hA = m_akCachedVectors[2];
                Vec4 hB = m_akPackedVerticesB[2];
                m_akCachedVectors[LI] = hA;
                m_akPackedVerticesB[LI] = hB;
                if (isNeg(diff.dot3(uedge)))
                {
                    if (UI == dimB)
                    {
                        UI = LI;
                    }
                    dimB = 1;
                    hA = m_akCachedVectors[1];
                    hB = m_akPackedVerticesB[1];
                    m_akCachedVectors[UI] = hA;
                    m_akPackedVerticesB[UI] = hB;
                    goto case_point_point;
                }
            }
            else
            {
                Vec4 hA = m_akCachedVectors[2];
                Vec4 hB = m_akPackedVerticesB[2];
                m_akCachedVectors[UI] = hA;
                m_akPackedVerticesB[UI] = hB;
            }
        }
            goto case_point_edge;

        case GSK_TRIANGLE_POINT:
        case_triangle_point: {
            int mask = reinterpret_cast<::TriangleSolver *>(this)->FUN_00e4da90((const ::hkVector4 &)(m_akCachedVectors[0]), (::TriangleVerts &)(m_akPackedVerticesA), (::hkVector4 &)(m_pSupport));
            if (mask == VComp::MASK_XYZ)
            {
                break;
            }
            int CI = DAT_010ececc[mask];
            dimA = 2;
            if (CI < 0)
            {
                CI += 8;
                CI &= 3;
                m_akPackedVerticesA[CI] = m_akPackedVerticesA[2];
                goto case_edge_point;
            }
            int LI = DAT_010eced4[CI];
            int UI = DAT_010eced4[CI + 2];

            Vec4 diff;
            diff.setSub4(m_akCachedVectors[0], m_akPackedVerticesA[CI]);
            Vec4 ledge;
            ledge.setSub4(m_akPackedVerticesA[LI], m_akPackedVerticesA[CI]);
            Vec4 uedge;
            uedge.setSub4(m_akPackedVerticesA[UI], m_akPackedVerticesA[CI]);

            if (isNeg(diff.dot3(ledge)))
            {
                m_akPackedVerticesA[LI] = m_akPackedVerticesA[2];
                if (isNeg(diff.dot3(uedge)))
                {
                    if (UI == dimA)
                    {
                        UI = LI;
                    }
                    dimA = 1;
                    m_akPackedVerticesA[UI] = m_akPackedVerticesA[1];
                    goto case_point_point;
                }
            }
            else
            {
                m_akPackedVerticesA[UI] = m_akPackedVerticesA[2];
            }
        }
            goto case_edge_point;

        case GSK_EDGE_TRIANGLE: {
            NextCase nextcase =
                FUN_00e4bbe0(m_akPackedVerticesA, m_akCachedVectors, dimA, dimB, m_iCacheState == 2, BUILD_POS_SUPPORT);
            switch (nextcase)
            {
            case NEXT_IS_EDGE_EDGE:
                goto case_edge_edge;
            case NEXT_IS_PENETRATION:
                goto penetration;
            }
        }
        break;

        case GSK_TRIANGLE_EDGE: {
            NextCase nextcase =
                FUN_00e4bbe0(m_akCachedVectors, m_akPackedVerticesA, dimB, dimA, m_iCacheState == 2, BUILD_NEG_SUPPORT);
            switch (nextcase)
            {
            case NEXT_IS_EDGE_EDGE:
                goto case_edge_edge;
            case NEXT_IS_PENETRATION:
                goto penetration;
            }
        }
        break;

        case GSK_EDGE_EDGE:
        case_edge_edge: {
            Vec4 a0 = m_akPackedVerticesA[0];
            Vec4 a1 = m_akPackedVerticesA[1];
            Vec4 b0 = m_akCachedVectors[0];
            Vec4 b1 = m_akCachedVectors[1];
            Vec4 edgeA;
            edgeA.setSub4(a1, a0);
            Vec4 edgeB;
            edgeB.setSub4(b1, b0);

            m_pSupport.setCross(edgeA, edgeB);
            Vec4 planeB;
            planeB.setCross(m_pSupport, edgeA);
            Vec4 planeA;
            planeA.setCross(m_pSupport, edgeB);

            Vec4 a0minusB0;
            a0minusB0.setSub4(a0, b0);
            Vec4 b1minusA0;
            b1minusA0.setSub4(b1, a0);
            Vec4 b0minusA1;
            b0minusA1.setSub4(b0, a1);

            Vec4 dots;
            VUtil::dot3_4vs4(a0minusB0, planeA, b0minusA1, planeA, a0minusB0, planeB, b1minusA0, planeB, dots);
            Vec4 zero;
            zero.setZero4();
            VComp comp = dots.compareGreaterThan4(zero);

            if (comp.allAreSet())
            {
                SReal a = dots.getSimdAt(0);
                SReal b = dots.getSimdAt(1);
                SReal r = a / (a + b);
                m_kVectorPairResult.m_kFirstVector.setInterpolate4(a0, a1, r);
                {
                    Vec4 sign;
                    sign.getQuad() = m_pSupport.dot3(a0minusB0).broadcast();
                    VUtil::mulSigns4(m_pSupport, sign);
                }
                break;
            }

            int mask = comp.GetLaneMask();
            switch (mask)
            {
            case VComp::MASK_XZW:
                m_akPackedVerticesA[0] = m_akPackedVerticesA[1];
            case VComp::MASK_YZW:
                dimA = 1;
                goto case_point_edge;
            case VComp::MASK_XYZ:
                m_akCachedVectors[0] = m_akCachedVectors[1];
                m_akPackedVerticesB[0] = m_akPackedVerticesB[1];
            case VComp::MASK_XYW:
                dimB = 1;
                goto case_edge_point;
            }

            int result = ::FUN_00d22e40((const ::hkVector4 &)(a0), (const ::hkVector4 &)(edgeA), (const ::hkVector4 &)(b0), (const ::hkVector4 &)(edgeB), (::VectorPairResult &)(m_kVectorPairResult));
            if (result == 0)
            {
                {
                    Vec4 sign;
                    sign.getQuad() = m_pSupport.dot3(a0minusB0).broadcast();
                    VUtil::mulSigns4(m_pSupport, sign);
                }
                break;
            }

            if (result & SegUtil::CLSLS_POINTA_START)
            {
                Vec4 v1 = m_akPackedVerticesA[1];
                m_akPackedVerticesA[0] = v1;
                dimA = 1;
            }
            else if (result & SegUtil::CLSLS_POINTA_END)
            {
                dimA = 1;
            }

            if (result & SegUtil::CLSLS_POINTB_START)
            {
                Vec4 v1 = m_akCachedVectors[1];
                m_akCachedVectors[0] = v1;
                m_akPackedVerticesB[0] = m_akPackedVerticesB[1];
                dimB = 1;
            }
            else if (result & SegUtil::CLSLS_POINTB_END)
            {
                dimB = 1;
            }
        }
            continue;

        case GSK_POINT_TETRA: {
            int maxIndex = ::FUN_00e4b810((const ::FaceVector &)(m_akPackedVerticesA[0]), (const ::FaceVector *)(m_akCachedVectors), 1.0f);
            if (maxIndex >= 0)
            {
                dimB = dimB - 1;
                m_akCachedVectors[maxIndex] = m_akCachedVectors[3];
                m_akPackedVerticesB[maxIndex] = m_akPackedVerticesB[3];
                goto case_point_triangle;
            }
        }
            goto penetration;

        case GSK_TETRA_POINT: {
            int maxIndex = ::FUN_00e4b810((const ::FaceVector &)(m_akCachedVectors[0]), (const ::FaceVector *)(m_akPackedVerticesA), -1.0f);
            if (maxIndex >= 0)
            {
                dimA = dimA - 1;
                m_akPackedVerticesA[maxIndex] = m_akPackedVerticesA[3];
                goto case_triangle_point;
            }
        }
            goto penetration;

        case GSK_NONE_NONE:

        default:
        penetration:
            return REDUCE_DIMENSION_PENETRATION;
        }
        break;
    }
    m_iCacheState = dimB;
    return REDUCE_DIMENSION_OK;
}

// @fnv 0x00e4c730
GskStatus Gsk::FUN_00e4c730(const Input& input, GskCache* __restrict cache, GskOut& output)
{
    const GskShape* shapeA = input.m_pShapeA;
    const GskShape* shapeB = input.m_pShapeB;

    Pad<int> dimA;
    Pad<int> dimB;

    if (cache)
    {
        int dimAb = cache->m_ucVertexCount;
        dimB = dimAb & 0xf;
        dimA = dimAb >> 4;

        shapeB->GetVerticesForIds(cache->m_ausVertexIds + dimA, dimB, &m_akPackedVerticesB[0]);
        shapeA->GetVerticesForIds(cache->m_ausVertexIds, dimA, &m_akPackedVerticesA[0]);
        VUtil::TransformPointArray(input.m_kTransform, &m_akPackedVerticesB[0], dimB, &m_akCachedVectors[0]);
    }
    else
    {
        dimA = 1;
        dimB = 1;
        Vec4 dir;
        dir.set(1.0f, 0.0f, 0.0f, 0.0f);
        Vec4 dirNeg;
        dirNeg.setNeg4(dir);
        reinterpret_cast<::FUN_004b4ab0_Class *>(&(dirNeg))->FUN_004b4ab0((intptr_t)&(input.m_kTransform.getRotation()), (intptr_t)&(dirNeg));
        shapeA->GetSupportPoint(dir, &m_akPackedVerticesA[0]);
        shapeB->GetSupportPoint(dirNeg, &m_akPackedVerticesB[0]);
        m_akCachedVectors[0].FUN_00c7f700(input.m_kTransform.getRotation(), m_akPackedVerticesB[0]);
    }

    SReal terminationEps = 1e-5f;
    GskStatus result = GSK_OK;
    while (1)
    {
        terminationEps = terminationEps * SReal(1.4f);
        int dim = dimA + dimB;
        ReduceDimensionResult reduceDimensionResult = reduceDimension(dimA, dimB, m_pSupport);

        m_iFeatureChange = m_iFeatureChange | (dimA + dimB - dim);

        {
            SReal supportLengthSquared = m_pSupport.normalizeWithLength3();
            Vec4 diff;
            diff.setSub4(m_akPackedVerticesA[0], m_akCachedVectors[0]);
            SReal distUnscaled = diff.dot3(m_pSupport);

            if (reduceDimensionResult != REDUCE_DIMENSION_OK || distUnscaled < terminationEps ||
                supportLengthSquared < terminationEps * terminationEps)
            {
                m_iFeatureChange = 1;

                if (!m_uiCacheFlags.val())
                {
                    FUN_00e4c230(shapeA, shapeB, input.m_kTransform, dimA, dimB, output);
                    result = GSK_OK;
                }
                else
                {
                    if (dimA + dimB > 4)
                    {
                        if (dimA > dimB)
                        {
                            dimA = 3;
                            dimB = 1;
                        }
                        else
                        {
                            dimA = 1;
                            dimB = 3;
                        }
                    }
                    result = GSK_PENETRATING;
                }
                goto END_AND_EXPORT_CACHE;
            }
        }

        Vec4 supportA;
        supportA.setNeg4(m_pSupport);
        Vec4 supportB;
        supportB.rotInvDir(input.m_kTransform.getRotation(), m_pSupport);

        Vec4 newVertexA;
        shapeA->GetSupportPoint(supportA, &newVertexA);
        Vec4 newVertexBinB;
        shapeB->GetSupportPoint(supportB, &newVertexBinB);

        Vec4& newVertexBinA = m_akCachedVectors[dimB];
        newVertexBinA.xformPos(input.m_kTransform, newVertexBinB);

        {
            Vec4 ref;
            ref.set(input.m_fBlendWeight, terminationEps, terminationEps, terminationEps);
            Vec4 eps4;
            eps4.SetAllComponents(terminationEps);
            Vec4 diff;
            diff.setSub4(newVertexA, newVertexBinA);
            Vec4 diffA0;
            diffA0.setSub4(newVertexA, m_akPackedVerticesA[0]);
            Vec4 diffA1;
            diffA1.setSub4(newVertexA, m_akPackedVerticesA[1]);
            Vec4 diffA2;
            diffA2.setSub4(newVertexA, m_akPackedVerticesA[2]);
            Vec4 diffB0;
            diffB0.setSub4(newVertexBinB, m_akPackedVerticesB[0]);
            Vec4 diffB1;
            diffB1.setSub4(newVertexBinB, m_akPackedVerticesB[1]);
            Vec4 diffB2;
            diffB2.setSub4(newVertexBinB, m_akPackedVerticesB[2]);
            Vec4 dots;
            VUtil::dot3_3vs3(m_pSupport, diff, supportA, diffA0, supportB, diffB0, dots);
            Vec4 dots2;
            VUtil::dot3_4vs4(supportA, diffA1, supportA, diffA2, supportB, diffB1, supportB, diffB2, dots2);

            VComp c = dots.compareGreaterThan4(ref);
            VComp shouldIgnore = dots2.compareLessThan4(eps4);
            int mask = c.GetLaneMask(VComp::MASK_XYZ);

            switch (mask)
            {
            default:
                break;

            case VComp::MASK_X:
            case VComp::MASK_XY:
            case VComp::MASK_XZ:
            case VComp::MASK_XYZ:
                result = GSK_PD_DISTANCE_TOO_BIG;
                goto END_AND_EXPORT_CACHE;

            case VComp::MASK_YZ:
                if (dots.getSimdAt(2) < dots.getSimdAt(1))
                {
                    goto CASE_B;
                }

            case VComp::MASK_Y: {
                if (!shouldIgnore.anyIsSet(DAT_010ec600[dimA]))
                {
                    m_akPackedVerticesA[dimA] = newVertexA;
                    dimA = dimA + 1;
                    m_iFeatureChange = 1;
                    continue;
                }
                break;
            }

            case VComp::MASK_Z:
            CASE_B: {
                if (!shouldIgnore.anyIsSet(DAT_010ec5f0[dimB]))
                {
                    m_akPackedVerticesB[dimB] = newVertexBinB;
                    dimB = dimB + 1;
                    m_iFeatureChange = 1;
                    continue;
                }
                break;
            }
            }
        }

        break;
    }

    {
        Vec4 diff;
        diff.setSub4(m_akPackedVerticesA[0], m_akCachedVectors[0]);
        Vec4 normalInA;
        normalInA = m_pSupport;
        SReal dist = diff.dot3(normalInA);
        normalInA.set(normalInA.getSimdAt(0), normalInA.getSimdAt(1), normalInA.getSimdAt(2), dist);
        output.m_vPointOnShapeA = normalInA;
        m_pSupport = normalInA;

        Vec4 pointAinA;
        if (dimA == 1)
        {
            pointAinA = m_akPackedVerticesA[0];
        }
        else if (dimB == 1)
        {
            pointAinA.setAddMul4(m_akCachedVectors[0], normalInA, dist);
        }
        else
        {
            pointAinA = m_kVectorPairResult.m_kFirstVector;
        }
        output.m_vPointOnShapeB = pointAinA;
    }

END_AND_EXPORT_CACHE:

    if (cache)
    {
        cache->m_ausVertexIds[0] = UChar(m_akPackedVerticesA[0].getInt24W());
        cache->m_ausVertexIds[1] = UChar(m_akPackedVerticesA[1].getInt24W());
        cache->m_ausVertexIds[2] = UChar(m_akPackedVerticesA[2].getInt24W());
        cache->m_ausVertexIds[dimA + 0] = UChar(m_akPackedVerticesB[0].getInt24W());
        cache->m_ausVertexIds[dimA + 1] = UChar(m_akPackedVerticesB[1].getInt24W());
        cache->m_ausVertexIds[dimA + 2] = UChar(m_akPackedVerticesB[2].getInt24W());
        cache->m_ucVertexCount = UChar((dimA << 4) | dimB);
    }

    return result;
}

#include "generated/data/havok/common/internal/collide/gsk/hkgsk.inc"
