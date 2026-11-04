
// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "fnv/symbols_00dae000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
struct S_00dad640_Entry
{
    unsigned short unk0;
    unsigned short id;
    unsigned int unk4;
};

struct S_00dad640_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[1];
};

struct S_00dad640_Target
{
    virtual void unk0();
    virtual void unk4();
    virtual void unk8();
    virtual void unkC();
    virtual void unk10();
    virtual void Release(unsigned short id, void* arg);
};

// @fnv 0x00dad640
void ReleaseAllEntries(S_00dad640_Set* set, S_00dad640_Target* target, void* arg)
{
    for (unsigned int i = 0; i < set->count; i++)
    {
        unsigned short id = set->entries[i].id;
        if (id != 0xffff)
            target->Release(id, arg);
    }
    set->count = 0;
    set->unk0 = 0;
    set->unk1 = 0;
}

struct S_00dad4d0_Key
{
    unsigned short ids[4];
    unsigned char numA;
    unsigned char numB;
};
struct S_00dad4d0_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dad4d0_Raw
{
    unsigned int lo;
    unsigned int hi;
};
struct S_00dad4d0_Set
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad4d0_Entry entries[1];

    unsigned short Id(unsigned char off)
    {
        return *(unsigned short*)((char*)&entries[count] + (off >> 3));
    }
};

// @fnv 0x00dad4d0
bool FindAndPromoteEntry(S_00dad4d0_Set* set, S_00dad4d0_Key* key)
{
    unsigned i;
    for (i = 0; i < set->count; i++)
    {
        S_00dad4d0_Entry* pEntry = &set->entries[i];
        if (key->numA == pEntry->numA && key->numB == pEntry->numB)
        {
            int iIdCount = key->numA + key->numB;
            if (key->ids[0] == set->Id(pEntry->offs[0]) && key->ids[1] == set->Id(pEntry->offs[1]) &&
                (iIdCount <= 2 || key->ids[2] == set->Id(pEntry->offs[2])) &&
                (iIdCount <= 3 || key->ids[3] == set->Id(pEntry->offs[3])))
            {
                if (i > 0)
                {
                    S_00dad4d0_Raw* pRawEntries = (S_00dad4d0_Raw*)set->entries;
                    S_00dad4d0_Raw rawTemp = pRawEntries[i];
                    pRawEntries[i] = pRawEntries[0];
                    pRawEntries[0] = rawTemp;
                }
                return true;
            }
        }
    }
    if (key->numA == 1 || key->numB == 1)
    {
        for (unsigned uiScanIndex = 0; uiScanIndex < set->count; uiScanIndex++)
        {
            S_00dad4d0_Entry* pEntry = &set->entries[uiScanIndex];
            if (key->numA == 1 && pEntry->numA == 1 && set->Id(pEntry->offs[0]) == key->ids[0])
            {
                pEntry->numA = 0;
                pEntry->numB = 0;
                return false;
            }
            if (key->numB == 1 && pEntry->numB == 1 && set->Id(pEntry->offs[pEntry->numA]) == key->ids[key->numA])
            {
                pEntry->numA = 0;
                pEntry->numB = 0;
                return false;
            }
        }
    }
    return false;
}


// @fnv 0x00dae340
void __cdecl FUN_00dae340(S_00dad640_Set* set, unsigned int index)
{
    unsigned int n = set->count;
    unsigned int last = n - 1;
    set->count = (unsigned char)last;
    unsigned int* puiDst = (unsigned int*)&set->entries[last];
    set->entries[index] = set->entries[last];
    unsigned int* puiSrc = (unsigned int*)&set->entries[n];
    int iShift = ((int)set->unk1 + (int)set->unk0 - 1) >> 1;
    unsigned int* puiBaseDst = puiDst;
    for (; iShift >= 0; iShift--)
    {
        *puiDst = *(unsigned int*)((char*)puiSrc + ((char*)puiDst - (char*)puiBaseDst));
        ++puiDst;
    }
    ::FUN_00dae220(iShift, (::S_00dae220_Set *)(set));
}

#include "fnv/symbols_simd.h"

class Scalar
{
    __m128 q;

  public:
    Scalar()
    {}
    Scalar(const __m128& x) : q(x)
    {}

    operator float() const
    {
        float x;
        _mm_store_ss(&x, q);
        return x;
    }
    __forceinline const __m128& packet() const
    {
        return q;
    }
    __forceinline __m128 splat() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
    Scalar(float input)
    {
        q = _mm_load_ss(&input);
    }
    __forceinline const __m128& getQuad() const
    {
        return q;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(q, q, 0);
    }
};
__forceinline Scalar operator+(const Scalar& a, const Scalar& b)
{
    return _mm_add_ss(a.packet(), b.packet());
}
__forceinline Scalar operator-(const Scalar& a, const Scalar& b)
{
    return _mm_sub_ss(a.packet(), b.packet());
}
__forceinline Scalar operator/(const Scalar& a, const Scalar& b)
{
    return _mm_div_ss(a.packet(), b.packet());
}
struct Comparison
{
    __m128 bits;
    enum
    {
        MASK_XY = 3,
        MASK_W = 8
    };
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(bits);
    }
    __forceinline int anyIsSet(int mask) const
    {
        return GetLaneMask() & mask;
    }
};
class Vector
{
    __m128 q;

  public:
    __forceinline Vector()
    {}
    __forceinline Vector(const Vector& a) : q(a.q)
    {}
    __forceinline Vector(const __m128& a) : q(a)
    {}
    __forceinline operator __m128() const
    {
        return q;
    }
    __forceinline void operator=(const Vector& a)
    {
        q = a.q;
    }
    __forceinline void operator=(const __m128& a)
    {
        q = a;
    }
    __forceinline __m128& packet()
    {
        return q;
    }
    __forceinline const __m128& packet() const
    {
        return q;
    }
    __forceinline float& operator()(int n)
    {
        return reinterpret_cast<float*>(&q)[n];
    }
    __forceinline const float& operator()(int n) const
    {
        return q[n];
    }
    __forceinline Scalar getSimdAt(int n) const
    {
        switch (n)
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
    __forceinline void setSub4(const Vector& a, const Vector& b)
    {
        q = _mm_sub_ps(a.q, b.q);
    }
    __forceinline void setCross(const Vector& a, const Vector& b)
    {
        __m128 first;
        first = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xc9), _mm_shuffle_ps(b.q, b.q, 0xd2));
        __m128 second;
        second = _mm_mul_ps(_mm_shuffle_ps(a.q, a.q, 0xd2), _mm_shuffle_ps(b.q, b.q, 0xc9));
        q = _mm_sub_ps(first, second);
    }
    __forceinline Scalar dot3(const Vector& a) const
    {
        __m128 product = _mm_mul_ps(q, a.q);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(product, product, 0x55), product);
        return _mm_add_ss(_mm_shuffle_ps(product, product, 0xaa), xy);
    }
    __forceinline Scalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline Scalar inverseLength() const
    {
        __m128 half = _mm_set_ss(0.5f), three = _mm_set_ss(3.0f), zero = _mm_set_ss(0.0f);
        __m128 squared = dot3(*this).packet();
        __m128 iszero = _mm_cmpeq_ss(squared, zero);
        __m128 estimate = _mm_rsqrt_ss(squared);
        __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(squared, estimate), estimate));
        return _mm_andnot_ps(iszero, _mm_mul_ss(_mm_mul_ss(half, estimate), correction));
    }
    __forceinline void normalize3()
    {
        __m128 inverse = inverseLength().splat();
        q = _mm_mul_ps(inverse, q);
    }
    __forceinline void setInterpolate4(const Vector& a, const Vector& b, const Scalar& t)
    {
        static const __m128 one = {1.0f, 1.0f, 1.0f, 1.0f};
        __m128 weight = t.splat(), complement = _mm_sub_ps(one, weight);
        q = _mm_add_ps(_mm_mul_ps(complement, a.q), _mm_mul_ps(weight, b.q));
    }
    __forceinline void setAddMul4(const Vector& a, const Vector& b, const Scalar& t)
    {
        q = _mm_add_ps(a.q, _mm_mul_ps(t.splat(), b.q));
    }
    __forceinline void setNeg4(const Vector& a)
    {
        static const __declspec(align(16)) unsigned int mask[4] = {0x80000000, 0x80000000, 0x80000000, 0x80000000};
        q = _mm_xor_ps(a.q, *reinterpret_cast<const __m128*>(mask));
    }
    __forceinline Comparison compareLessThanZero4() const
    {
        Comparison c;
        c.bits = _mm_cmplt_ps(q, _mm_setzero_ps());
        return c;
    }
};
namespace VectorUtil {
__forceinline void dot3_3vs3(const Vector& a, const Vector& b, const Vector& c, const Vector& d, const Vector& e,
                             const Vector& f, Vector& result)
{
    __m128 x = _mm_mul_ps(a.packet(), b.packet()), y = _mm_mul_ps(c.packet(), d.packet()),
           z = _mm_mul_ps(e.packet(), f.packet());
    __m128 low, high;
    low = _mm_unpacklo_ps(x, y);
    high = _mm_shuffle_ps(_mm_unpackhi_ps(x, y), z, 0xe4);
    x = _mm_movelh_ps(low, z);
    y = _mm_shuffle_ps(_mm_movehl_ps(x, low), z, 0xd4);
    z = high;
    result.packet() = _mm_add_ps(_mm_add_ps(x, y), z);
}
__forceinline void dot3_1vs4(const Vector& normal, const Vector& a, const Vector& b, const Vector& c, const Vector& d,
                             Vector& result)
{
    __m128 x = _mm_mul_ps(a.packet(), normal.packet()), y = _mm_mul_ps(b.packet(), normal.packet());
    __m128 z = _mm_mul_ps(c.packet(), normal.packet()), w = _mm_mul_ps(d.packet(), normal.packet());
    __m128 t3, t2, t1, t0;
    t0 = _mm_shuffle_ps(x, y, 0x44);
    t2 = _mm_shuffle_ps(x, y, 0xee);
    t1 = _mm_shuffle_ps(z, w, 0x44);
    t3 = _mm_shuffle_ps(z, w, 0xee);
    x = _mm_shuffle_ps(t0, t1, 0x88);
    y = _mm_shuffle_ps(t0, t1, 0xdd);
    z = _mm_shuffle_ps(t2, t3, 0x88);
    w = _mm_shuffle_ps(t2, t3, 0xdd);
    result.packet() = _mm_add_ps(_mm_add_ps(x, y), z);
}
__forceinline void dot3_2vs2(const Vector& a, const Vector& b, const Vector& c, const Vector& d, Vector& result)
{
    __m128 x = _mm_mul_ps(a.packet(), c.packet()), y = _mm_mul_ps(a.packet(), d.packet());
    __m128 z = _mm_mul_ps(b.packet(), c.packet()), w = _mm_mul_ps(b.packet(), d.packet());
    __m128 t3, t2, t1, t0;
    t0 = _mm_shuffle_ps(x, y, 0x44);
    t2 = _mm_shuffle_ps(x, y, 0xee);
    t1 = _mm_shuffle_ps(z, w, 0x44);
    t3 = _mm_shuffle_ps(z, w, 0xee);
    x = _mm_shuffle_ps(t0, t1, 0x88);
    y = _mm_shuffle_ps(t0, t1, 0xdd);
    z = _mm_shuffle_ps(t2, t3, 0x88);
    w = _mm_shuffle_ps(t2, t3, 0xdd);
    result.packet() = _mm_add_ps(_mm_add_ps(x, y), z);
}
}

class FloatField
{
    float v;

  public:
    __forceinline FloatField()
    {}
    __forceinline FloatField(float x) : v(x)
    {}
    __forceinline float value() const
    {
        return v;
    }
    __forceinline operator float() const
    {
        return value();
    }
    __forceinline void operator=(float x)
    {
        v = x;
    }
};
struct ContactVertex : Vector
{
};
struct ContactWork
{
    ContactVertex vertices[16];
    Vector direction;
    FloatField radiusA, radiusB, tolerance, toleranceSquared;
    __forceinline const Vector& vertex(unsigned int off) const
    {
        return *reinterpret_cast<const ContactVertex*>(reinterpret_cast<const char*>(vertices) + off);
    }
};

struct ContactResult
{
    Vector point, delta, normal;
};

static __forceinline int pointPoint(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    Vector separation;
    separation.setSub4(a, b);
    float squared = separation.lengthSquared3();
    if (squared > w.toleranceSquared)
        return 1;
    r.delta = separation;
    r.normal = w.direction;
    r.point = a;
    return 0;
}
static __forceinline int pointEdge(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    r.point = a;
    r.normal = w.direction;
    Vector edge, first, second, area, weights;
    edge.setSub4(c, b);
    first.setSub4(c, a);
    second.setSub4(a, b);
    area.setCross(edge, first);
    VectorUtil::dot3_3vs3(first, edge, second, edge, area, area, weights);
    float squared = edge.lengthSquared3();
    int negative = weights.compareLessThanZero4().anyIsSet(Comparison::MASK_XY);
    if (weights(3) > w.toleranceSquared * squared || negative)
        return 1;
    Scalar fraction = weights.getSimdAt(0) / (weights.getSimdAt(0) + weights.getSimdAt(1));
    Vector closest;
    closest.setInterpolate4(b, c, fraction);
    r.delta.setSub4(a, closest);
    return 0;
}
static __forceinline int edgePoint(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    r.normal = w.direction;
    Vector keepB(b);
    Vector edge, first, second, area, weights;
    edge.setSub4(keepB, a);
    first.setSub4(keepB, c);
    second.setSub4(c, a);
    area.setCross(edge, first);
    VectorUtil::dot3_3vs3(first, edge, second, edge, area, area, weights);
    float squared = edge.lengthSquared3();
    int negative = weights.compareLessThanZero4().anyIsSet(Comparison::MASK_XY);
    if (weights(3) > w.toleranceSquared * squared || negative)
        return 1;
    Scalar fraction = weights.getSimdAt(0) / (weights.getSimdAt(0) + weights.getSimdAt(1));
    r.point.setInterpolate4(keepB, a, fraction);
    r.delta.setSub4(r.point, c);
    return 0;
}
static __forceinline int pointFace(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    const Vector& d = w.vertex(f.offs[3]);
    r.point = a;
    r.delta.setSub4(a, b);
    Vector edge0, edge1, edge2, normal, weights;
    edge0.setSub4(d, c);
    edge1.setSub4(b, d);
    edge2.setSub4(c, b);
    normal.setCross(edge0, edge1);
    normal.normalize3();
    {
        Vector ray0, ray1, ray2, side0, side1, side2;
        ray0.setSub4(a, c);
        ray1.setSub4(a, d);
        ray2.setSub4(a, b);
        side0.setCross(ray0, edge0);
        side1.setCross(ray1, edge1);
        side2.setCross(ray2, edge2);
        VectorUtil::dot3_1vs4(normal, side0, side1, side2, w.direction, weights);
    }
    r.normal = normal;
    int mask = weights.compareLessThanZero4().GetLaneMask();
    if (mask & Comparison::MASK_W)
        r.normal.setNeg4(normal);
    return (mask & 7) ^ 7;
}
static __forceinline int facePoint(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    const Vector& d = w.vertex(f.offs[3]);
    r.point = d;
    r.delta.setSub4(a, d);
    Vector edge0, edge1, edge2, normal, weights;
    edge0.setSub4(c, b);
    edge1.setSub4(a, c);
    edge2.setSub4(b, a);
    normal.setCross(edge0, edge1);
    normal.normalize3();
    {
        Vector ray0, ray1, ray2, side0, side1, side2;
        ray0.setSub4(d, b);
        ray1.setSub4(d, c);
        ray2.setSub4(d, a);
        side0.setCross(ray0, edge0);
        side1.setCross(ray1, edge1);
        side2.setCross(ray2, edge2);
        VectorUtil::dot3_1vs4(normal, side0, side1, side2, w.direction, weights);
    }
    Scalar projection = r.delta.dot3(normal);
    r.point.setAddMul4(d, normal, projection);
    r.normal = normal;
    int mask = weights.compareLessThanZero4().GetLaneMask();
    if (mask & Comparison::MASK_W)
        r.normal.setNeg4(normal);
    return (mask & 7) ^ 7;
}
static __forceinline int edgeEdge(const ContactWork& w, const S_00dad4d0_Entry& f, ContactResult& r)
{
    const Vector& a = w.vertex(f.offs[0]);
    const Vector& b = w.vertex(f.offs[1]);
    const Vector& c = w.vertex(f.offs[2]);
    const Vector& d = w.vertex(f.offs[3]);
    Vector edgeA, edgeB, diffA, diffB, normal, ortA, ortB, weights;
    edgeA.setSub4(b, a);
    edgeB.setSub4(d, c);
    diffA.setSub4(a, c);
    diffB.setSub4(b, d);
    normal.setCross(edgeA, edgeB);
    ortA.setCross(edgeA, normal);
    ortB.setCross(edgeB, normal);
    r.normal = w.direction;
    VectorUtil::dot3_2vs2(diffA, diffB, ortB, ortA, weights);
    int mask = weights.compareLessThanZero4().GetLaneMask();
    if (mask != 3 && mask != 12)
        return 1;
    Scalar x = weights.getSimdAt(0);
    Scalar fraction = x / (x - weights.getSimdAt(2));
    r.point.setInterpolate4(a, b, fraction);
    Scalar y = weights.getSimdAt(1);
    Scalar other = y / (y - weights.getSimdAt(3));
    Vector closest;
    closest.setInterpolate4(c, d, other);
    r.delta.setSub4(r.point, closest);
    return 0;
}
struct EntryParameter
{
    const S_00dad4d0_Entry* p;
};
// Switches on 4 * f.numA + f.numB to call pointPoint, pointEdge, pointFace, edgePoint, edgeEdge or facePoint; returns 1 for other combinations.
// @fnv 0x00dad990
static __declspec(noinline) int FUN_00dad990(const ContactWork& w, ContactResult& r, EntryParameter entry)
{
    const S_00dad4d0_Entry& f = *entry.p;
    switch (4 * f.numA + f.numB)
    {
    case 0:
        return 1;
    case 5:
        return pointPoint(w, f, r);
    case 6:
        return pointEdge(w, f, r);
    case 7:
        return pointFace(w, f, r);
    case 9:
        return edgePoint(w, f, r);
    case 10:
        return edgeEdge(w, f, r);
    case 13:
        return facePoint(w, f, r);
    default:
        return 1;
    }
}
int FnvHavok_hkpgskmanifoldutil_probeCaller(const ContactWork& w, ContactResult& r, const S_00dad4d0_Entry* f)
{
    EntryParameter e = {f};
    return FUN_00dad990(w, r, e);
}

// Moved from hkpgskmanifoldutil_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/gskmanifold/hkpgskmanifoldutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/symbols_00dad000.h"
#include "fnv/symbols_0104d000.h"
void FUN_00dae220(int unused, S_00dad640_Set* set);
void __cdecl FUN_00dae340(S_00dad640_Set* set, unsigned int index);

struct __declspec(align(16)) S_00daee00_Vec
{
    float x;
    float y;
    float z;
    float w;

    void setSub4(const S_00daee00_Vec& a, const S_00daee00_Vec& b)
    {
        *(__m128*)this = _mm_sub_ps(*(const __m128*)&a, *(const __m128*)&b);
    }
    void setCross(const S_00daee00_Vec& a, const S_00daee00_Vec& b)
    {
        __m128 v1 = *(const __m128*)&a;
        __m128 v2 = *(const __m128*)&b;
        __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xc9), _mm_shuffle_ps(v2, v2, 0xd2));
        __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xd2), _mm_shuffle_ps(v2, v2, 0xc9));
        *(__m128*)this = _mm_sub_ps(c0, c1);
    }
    void storeLengthSquared3(float& f) const
    {
        __m128 v = *(const __m128*)this;
        __m128 x2 = _mm_mul_ps(v, v);
        __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        _mm_store_ss(&f, r);
    }
};

struct S_00daee00_Point
{
    S_00daee00_Vec pos;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
};

struct S_00daee00
{
    S_00daee00_Point points[5];
    int FUN_00daee00();
};

// @fnv 0x00daee00
int S_00daee00::FUN_00daee00()
{
    // The fallback phase reuses the completed geometric reduction scratch.
    float maxDist = 0.0f;
    float minDist = ::DAT_0104da48;
    float distance;
    float dr;
    struct PointSelection
    {
        float dists[4];
        int used[5];
    } ls;
    int* used = ls.used;
    float* dists = ls.dists;
    for (int k = 0; k < 5; k++)
        used[k] = 0;
    int farIdx = 0;
    int nearIdx = 0;

    for (int i = 0; i < 4; i++)
    {
        S_00daee00_Vec diff;
        diff.setSub4(points[4].pos, points[i].pos);
        diff.storeLengthSquared3(distance);
        float d = distance;
        dists[i] = d;
        if (maxDist < d)
        {
            maxDist = d;
            farIdx = i;
        }
        if (d < minDist)
        {
            minDist = d;
            nearIdx = i;
        }
    }
    dr = points[4].unk1C - points[nearIdx].unk1C;
    used[farIdx] = 1;

    int idx2 = 4;
    const S_00daee00_Vec& farPos = points[farIdx].pos;
    maxDist *= 1.05f;
    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            S_00daee00_Vec diff;
            diff.setSub4(points[farIdx].pos, points[i].pos);
            diff.storeLengthSquared3(distance);
            float d = distance;
            if (d > maxDist)
            {
                maxDist = d;
                idx2 = i;
            }
        }
    }
    used[idx2] = 1;

    int idx3 = 0;
    S_00daee00_Vec edge;
    edge.setSub4(farPos, points[idx2].pos);
    float maxDist3 = 0.0f;
    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            S_00daee00_Vec diff;
            diff.setSub4(points[i].pos, farPos);
            S_00daee00_Vec cross;
            cross.setCross(diff, edge);
            cross.storeLengthSquared3(distance);
            float d = distance;
            if (d > maxDist3)
            {
                maxDist3 = d;
                idx3 = i;
            }
        }
    }
    used[idx3] = 1;

    int idx4 = 0;
    const S_00daee00_Vec& thirdPos = points[idx3].pos;
    maxDist3 = 0.0f;
    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            S_00daee00_Vec diff;
            diff.setSub4(thirdPos, points[i].pos);
            diff.storeLengthSquared3(distance);
            float d = distance;
            if (d > maxDist3)
            {
                maxDist3 = d;
                idx4 = i;
            }
        }
    }
    used[idx4] = 1;

    if (!used[4] && dr < 0.0f && minDist < 526.0 * dr * dr)
    {
        maxDist = 0.030461745f;
        int result = 4;
        float base = points[4].unk1C;
        for (int i = 0; i < 4; i++)
        {
            minDist = points[i].unk1C - base;
            dr = minDist * minDist;
            minDist = dr + 1e-9f;
            if (minDist > dists[i] * maxDist)
            {
                maxDist = minDist / (dists[i] + 1e-9f);
                result = i;
            }
        }
        return result;
    }

    for (int i = 0; i < 5; i++)
    {
        if (!used[i])
        {
            return i;
        }
    }
    return 0;
}

struct S_00dad720_Vec
{
    __m128 m_afExtents[16];
    __m128 m_v100;
    int unk110;
    int unk114;
    int unk118;
    float m_pFreeList;
};

struct S_00dad720_Out
{
    __m128 m_v0;
    __m128 m_v10;
    __m128 m_v20;
};

struct S_00dad720_Rec
{
    int unk0;
    unsigned char m_kPointA;
    unsigned char m_kPointB;
    unsigned char m_iThirdValue;
};


static __forceinline __m128 Cross3(const __m128& a, const __m128& b)
{
    __m128 t0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(t1, t0);
}

static __forceinline __m128 Dot3_3vs3(const __m128& a0, const __m128& b0, const __m128& a1, const __m128& b1,
                                      const __m128& a2, const __m128& b2)
{
    __m128 m0 = _mm_mul_ps(a0, b0);
    __m128 m1 = _mm_mul_ps(a1, b1);
    __m128 m2 = _mm_mul_ps(a2, b2);
    __m128 tmp = _mm_unpacklo_ps(m0, m1);
    __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m0, m1), m2, 0xe4);
    m0 = _mm_movelh_ps(tmp, m2);
    m1 = _mm_shuffle_ps(_mm_movehl_ps(m0, tmp), m2, 0xd4);
    m2 = ctmp;
    return _mm_add_ps(_mm_add_ps(m0, m1), m2);
}

// @fnv 0x00dad720
static __declspec(noinline) int FUN_00dad720(S_00dad720_Rec* rec, S_00dad720_Vec* vecs, S_00dad720_Out* out)
{
    const __m128& pa = *(__m128*)((char*)vecs + rec->m_kPointA);
    const __m128& pb = *(__m128*)((char*)vecs + rec->m_kPointB);
    const __m128& pc = *(__m128*)((char*)vecs + rec->m_iThirdValue);
    out->m_v0 = pa;
    out->m_v20 = vecs->m_v100;
    const __m128& b = pb;
    const __m128& c = pc;
    const __m128& a = pa;
    __m128 e1 = _mm_sub_ps(c, b);
    __m128 e0 = _mm_sub_ps(c, a);
    __m128 n = Cross3(e0, e1);
    __m128 dots = Dot3_3vs3(e0, e1, _mm_sub_ps(a, b), e1, n, n);
    __declspec(align(16)) float d[4];
    _mm_store_ps(d, dots);
    __m128 sq = _mm_mul_ps(e1, e1);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    float lenSq;
    _mm_store_ss(&lenSq, s);
    if (!(d[3] > vecs->m_pFreeList * lenSq) && !(_mm_movemask_ps(_mm_cmplt_ps(dots, _mm_setzero_ps())) & 3))
    {
        __m128 sum = _mm_add_ss(dots, _mm_shuffle_ps(dots, dots, 0x55));
        __m128 t = _mm_div_ss(dots, sum);
        t = _mm_shuffle_ps(t, t, 0);
        __m128 p = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, t), b), _mm_mul_ps(c, t));
        out->m_v10 = _mm_sub_ps(a, p);
        return 0;
    }
    return 1;
}
void* volatile g_rec;
void* volatile g_vecs;
void* volatile FnvHavok_hkpgskmanifoldutil_g_out;
volatile int g_res;
void CallTarget_dad720()
{
    S_00dad720_Out* o = (S_00dad720_Out*)FnvHavok_hkpgskmanifoldutil_g_out;
    g_res = FUN_00dad720((S_00dad720_Rec*)g_rec, (S_00dad720_Vec*)g_vecs, o);
}
namespace fnv_00dad860 {
#include <xmmintrin.h>

typedef float hkReal;
typedef __m128 hkQuadReal;

class VectorComponentValue
{
  public:
    __forceinline VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    __forceinline operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
};
typedef const VectorComponentValue& hkSimdRealParameter;

__forceinline VectorComponentValue operator+(hkSimdRealParameter r, hkSimdRealParameter s)
{
    return _mm_add_ss(r.getQuad(), s.getQuad());
}
__forceinline VectorComponentValue operator/(hkSimdRealParameter r, hkSimdRealParameter s)
{
    return _mm_div_ss(r.getQuad(), s.getQuad());
}

class Vector4Comparison
{
  public:
    enum Mask
    {
        MASK_XY = 3
    };
    __forceinline int anyIsSet(Mask m) const
    {
        return _mm_movemask_ps(m_uiMask) & m;
    }
    hkQuadReal m_uiMask;
};

class hkVector4
{
  public:
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setCross(const hkVector4& v0, const hkVector4& v1)
    {
        hkQuadReal cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        hkQuadReal cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                            _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline void setInterpolate4(const hkVector4& v0, const hkVector4& v1, hkSimdRealParameter _t)
    {
        static __declspec(align(16)) const float cw[4] = {1.0f, 1.0f, 1.0f, 1.0f};
        hkQuadReal t = _t.broadcast();
        hkQuadReal s = _mm_sub_ps(*(const hkQuadReal*)&cw, t);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), xySum);
    }
    __forceinline VectorComponentValue lengthSquared3() const
    {
        return this->dot3(*this);
    }
    __forceinline Vector4Comparison compareLessThanZero4() const
    {
        hkVector4 zero;
        zero.m_vComponents = _mm_setzero_ps();
        Vector4Comparison m;
        m.m_uiMask = _mm_cmplt_ps(m_vComponents, zero.m_vComponents);
        return m;
    }
    __forceinline VectorComponentValue getSimdAt(int i) const
    {
        switch (i)
        {
        case 0:
            return m_vComponents;
        case 1:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
        case 2:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
        default:
            return _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
        }
    }
    __forceinline hkReal& operator()(int a)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[a];
    }
    hkQuadReal m_vComponents;
};

namespace hkVector4Util_S {
__forceinline void dot3_3vs3(const hkVector4& a0, const hkVector4& b0, const hkVector4& a1, const hkVector4& b1,
                             const hkVector4& a2, const hkVector4& b2, hkVector4& dotsOut)
{
    hkQuadReal c0 = _mm_mul_ps(a0.m_vComponents, b0.m_vComponents);
    hkQuadReal c1 = _mm_mul_ps(a1.m_vComponents, b1.m_vComponents);
    hkQuadReal c2 = _mm_mul_ps(a2.m_vComponents, b2.m_vComponents);
    {
        hkQuadReal _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, _MM_SHUFFLE(3, 2, 1, 0));
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, _MM_SHUFFLE(3, 1, 1, 0));
        c2 = _ctmp;
    }
    dotsOut.m_vComponents = _mm_add_ps(_mm_add_ps(c0, c1), c2);
}
}

template <typename T> class ValueWrapper
{
  public:
    __forceinline operator T() const
    {
        return m_kStorage;
    }
    T m_kStorage;
};

struct MeshVertexBasisData
{
    hkVector4 m_pMeshVertexBuffer[16];
    hkVector4 m_kFirstBasisVector;
    ValueWrapper<hkReal> m_kBoxBasisVector;
    ValueWrapper<hkReal> m_kThirdBasisVector;
    ValueWrapper<hkReal> m_kFourthBasisVector;
    ValueWrapper<hkReal> m_fMinimumCollisionSeparation;
    __forceinline const hkVector4& getVertexA(unsigned int offset) const
    {
        return *(const hkVector4*)((const char*)this + offset);
    }
    __forceinline const hkVector4& getVertexB(unsigned int offset) const
    {
        return *(const hkVector4*)((const char*)this + offset);
    }
};

struct AlignedPairData
{
    unsigned short m_ucDimensionA;
    unsigned short m_ucDimensionB;
    unsigned char m_vert0;
    unsigned char m_vert1;
    unsigned char m_vert2;
};

struct TriangleClosestPointInfo
{
    hkVector4 m_vContactPosition;
    hkVector4 m_vHitNormal;
    hkVector4 m_kTriangleNormal;
};

// @fnv 0x00dad860
static __declspec(noinline) int FUN_00dad860(const MeshVertexBasisData& work, const AlignedPairData& point,
                                             TriangleClosestPointInfo& out)
{
    const hkVector4& a0 = work.getVertexA(point.m_vert0);
    const hkVector4& a1 = work.getVertexA(point.m_vert1);
    const hkVector4& b0 = work.getVertexB(point.m_vert2);

    out.m_kTriangleNormal = work.m_kFirstBasisVector;

    hkVector4 edge;
    edge.setSub4(a1, a0);
    hkVector4 d1;
    d1.setSub4(a1, b0);
    hkVector4 d0;
    d0.setSub4(b0, a0);
    hkVector4 cross;
    cross.setCross(edge, d1);

    hkVector4 dots;
    hkVector4Util_S::dot3_3vs3(d1, edge, d0, edge, cross, cross, dots);

    hkReal lenSq = edge.lengthSquared3();
    if (dots(3) > work.m_fMinimumCollisionSeparation * lenSq || dots.compareLessThanZero4().anyIsSet(Vector4Comparison::MASK_XY))
    {
        return 1;
    }
    VectorComponentValue t = dots.getSimdAt(0) / (dots.getSimdAt(0) + dots.getSimdAt(1));
    out.m_vContactPosition.setInterpolate4(a1, a0, t);
    out.m_vHitNormal.setSub4(out.m_vContactPosition, b0);
    return 0;
}

const MeshVertexBasisData* volatile g_work;
const AlignedPairData* volatile g_point;
TriangleClosestPointInfo* volatile g_out;
int S00dad860_Call()
{
    return FUN_00dad860(*g_work, *g_point, *g_out);
}
}  // namespace fnv_00dad860

struct S_00dae220_Entry
{
    unsigned char numA;
    unsigned char numB;
    unsigned char unk2;
    unsigned char unk3;
    unsigned char offs[4];
};
struct S_00dae220_Set
{
    unsigned char numA;
    unsigned char numB;
    unsigned char count;
    unsigned char unk3;
    S_00dae220_Entry entries[1];
};

// @fnv 0x00dae220
void FUN_00dae220(int unused, S_00dae220_Set* set)
{
    __declspec(align(16)) unsigned char used[16];
    unsigned int remap[16];
    unsigned int i;

    _mm_store_ps((float*)used, _mm_setzero_ps());
    for (i = 0; i < set->count; i++)
    {
        S_00dae220_Entry* e = &set->entries[i];
        int n = e->numA + e->numB;
        used[e->offs[0] >> 4] = 1;
        used[e->offs[1] >> 4] = 1;
        if (n >= 3)
            used[e->offs[2] >> 4] = 1;
        if (n == 4)
            used[e->offs[3] >> 4] = 1;
    }

    unsigned short* ids = (unsigned short*)&set->entries[set->count];
    int total = set->numA + set->numB;
    int kept = 0;
    int j = 0;
    unsigned int off = 0;
    for (; j < total; j++)
    {
        remap[j] = off;
        if (used[j])
        {
            ids[kept] = ids[j];
            kept++;
            off += 16;
        }
    }

    unsigned char numA = (unsigned char)(remap[set->numA] >> 4);
    set->numA = numA;
    set->numB = (unsigned char)(kept - numA);

    for (i = 0; i < set->count; i++)
    {
        S_00dae220_Entry* e = &set->entries[i];
        e->offs[0] = (unsigned char)remap[e->offs[0] >> 4];
        e->offs[1] = (unsigned char)remap[e->offs[1] >> 4];
        e->offs[2] = (unsigned char)remap[e->offs[2] >> 4];
        e->offs[3] = (unsigned char)remap[e->offs[3] >> 4];
    }
}

extern "C" void _ReadWriteBarrier(void);

struct ContactManifold
{
    unsigned char unk0;
    unsigned char unk1;
    unsigned char count;
    unsigned char unk3;
    S_00dad640_Entry entries[4];
};

struct ContactRecord
{
    __m128 position;
    __m128 normal;
    unsigned id;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
};
struct ContactCache
{
    ContactRecord points[4];
};
struct ContactContext
{
    unsigned unk00;
    void* userData;
};
struct ContactManager
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual unsigned short add(void* a, void* b, void* c, ContactContext* context, S_00dad4d0_Key* key,
                               ContactRecord* point);
    virtual void slot4();
    virtual void remove(unsigned short id, void* userData);
};

static inline void CopyContact(ContactRecord& destination, const ContactRecord& source)
{
    destination.position = source.position;
    destination.normal = source.normal;
    destination.id = source.id;
}

// Four contact entries are followed immediately by a variable-length vertex table.
// For smaller manifolds the table starts after the last live entry.
static inline unsigned short* VertexIds(ContactManifold* set)
{
    return reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(&set->entries) + set->count * 8);
}
static inline S_00dad4d0_Entry& ContactEntry(ContactManifold* set, unsigned index)
{
    return *reinterpret_cast<S_00dad4d0_Entry*>(reinterpret_cast<char*>(&set->entries) + index * 8);
}

static void FUN_00dae220(int, ContactManifold* set);

// @fnv 0x00daf1e0
int FUN_00daf1e0(ContactManifold* set, void* a, void* b, void* c, ContactContext* context, S_00dad4d0_Key* key,
                 ContactRecord* point, ContactCache* cache, ContactManager* manager, int defer)
{
    int replaced = 4;
    unsigned short id;
    if (set->count == 4)
    {
        int index = reinterpret_cast<::S_00daee00 *>((cache))->FUN_00daee00();
        if (index == 4)
            return 5;
        manager->remove(set->entries[index].id, context->userData);
        S_00dad640_Entry* added = &set->entries[index];
        if (index)
            *added = set->entries[0];
        else
            *added = set->entries[1];
        FUN_00dae220(index, set);
        id = manager->add(a, b, c, context, key, point);
        if (id == 0xffff)
        {
            set->entries[0] = set->entries[3];
            unsigned res = set->count;
            unsigned newCount = res - 1;
            set->count = static_cast<unsigned char>(newCount);
            volatile unsigned* destination =
                reinterpret_cast<unsigned*>(reinterpret_cast<char*>(&set->entries) + newCount * 8);
            const unsigned* source = reinterpret_cast<const unsigned*>(reinterpret_cast<char*>(&set->entries) + res * 8);
            for (int words = (set->unk0 + set->unk1 - 1) >> 1; words >= 0; --words)
                *destination++ = *source++;
            CopyContact(cache->points[index], cache->points[3]);
            return 6;
        }
        ContactRecord* fresh = *(ContactRecord* volatile*)&point;
        fresh->id = id;
        CopyContact(cache->points[index], *fresh);
        replaced = index;
    }
    else
    {
        if (defer && key->numB != 3)
        {
            id = 0xffff;
        }
        else
        {
            id = manager->add(a, b, c, context, key, point);
            if (id == 0xffff)
                return 5;
        }
        point->id = id;
        unsigned res = set->count;
        unsigned newCount = res + 1;
        int lastWord = (set->unk1 + set->unk0 - 1) >> 1;
        unsigned* destination = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(&set->entries) + newCount * 8) + lastWord;
        unsigned* source = reinterpret_cast<unsigned*>(reinterpret_cast<char*>(&set->entries) + res * 8) + lastWord;
        for (; 0 <= lastWord; --lastWord)
            *destination-- = *source--;
        set->entries[res] = set->entries[0];
        set->count = static_cast<unsigned char>(newCount);
    }

    S_00dad4d0_Entry& entry = ContactEntry(set, 0);
    entry.numA = key->numA;
    entry.numB = key->numB;
    *reinterpret_cast<unsigned*>(entry.offs) = 0;
    *reinterpret_cast<unsigned short*>(&entry.unk2) = id;
    unsigned short* vertices = VertexIds(set);
    unsigned selected = 0;
    for (int i = 0; i < key->numA; ++i)
    {
        unsigned index = 0;
        unsigned short vertex = key->ids[i];
        while (index < set->unk0)
        {
            if (vertices[index] == vertex)
                goto foundA;
            ++index;
        }
        {
            unsigned end = set->unk0 + set->unk1;
            while (end > index)
            {
                vertices[end] = vertices[end - 1];
                --end;
            }
            vertices[index] = vertex;
            ++set->unk0;
            _ReadWriteBarrier();
            selected += 0x10;
        }
    foundA:
        entry.offs[i] = static_cast<unsigned char>(index << 4);
    }
    {
        if (selected)
        {
            S_00dad4d0_Entry* previous = &ContactEntry(set, 1);
            for (unsigned contact = 1; contact < set->count; ++contact, ++previous)
            {
                for (unsigned j = previous->numA; j < previous->numB + previous->numA; ++j)
                    previous->offs[j] += static_cast<unsigned char>(selected);
            }
        }
    }
    int i = 0;
    if (i < key->numB)
    {
        do
        {
            unsigned short vertex = key->ids[key->numA + i];
            long index = set->unk0;
            int end;
            end = set->unk0 + set->unk1;
            while (index < end)
            {
                if (vertices[index] == vertex)
                    goto foundB;
                ++index;
            }
            vertices[index] = vertex;
            set->unk1++;
        foundB:
            entry.offs[key->numA + i] = static_cast<unsigned char>(index << 4);
            ++i;
        } while (i < key->numB);
    }
    return replaced;
}

// Compact the shared vertex table and re-encode every contact's offsets.
static __declspec(noinline) void FUN_00dae220(int, ContactManifold* set)
{
    __declspec(align(16)) unsigned int usedWords[4];
    _mm_store_ps(reinterpret_cast<float*>(usedWords), _mm_setzero_ps());
    unsigned char* used = reinterpret_cast<unsigned char*>(usedWords);
    unsigned remap[16];
    unsigned contactCount = set->count;
    unsigned char* offs = ContactEntry(set, 0).offs;
    for (unsigned k = 0; k < contactCount; ++k)
    {
        int total = offs[-4] + offs[-3];
        used[offs[0] >> 4] = 1;
        used[offs[1] >> 4] = 1;
        if (total >= 3)
            used[offs[2] >> 4] = 1;
        if (total == 4)
            used[offs[3] >> 4] = 1;
        offs += 8;
    }
    unsigned short* vertices = reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(&set->entries) + contactCount * 8);
    int total = set->unk0 + set->unk1;
    unsigned count = 0;
    unsigned offset = 0;
    for (int i = 0; i < total; ++i)
    {
        remap[i] = offset;
        if (used[i])
        {
            vertices[count++] = vertices[i];
            offset += 16;
        }
    }
    unsigned countA = remap[set->unk0] >> 4;
    set->unk0 = static_cast<unsigned char>(countA);
    set->unk1 = static_cast<unsigned char>(count - countA);
    for (unsigned i = 0; i < set->count; ++i)
    {
        S_00dad4d0_Entry& entry = ContactEntry(set, i);
        entry.offs[0] = static_cast<unsigned char>(remap[entry.offs[0] >> 4]);
        entry.offs[1] = static_cast<unsigned char>(remap[entry.offs[1] >> 4]);
        entry.offs[2] = static_cast<unsigned char>(remap[entry.offs[2] >> 4]);
        entry.offs[3] = static_cast<unsigned char>(remap[entry.offs[3] >> 4]);
    }
}

// Moved from hkpgskmanifoldutil_gs_nogs_variant.cpp (VEGAS-15).
struct S_00dad6a0_Vec
{
    __m128 m_afExtents[16];
    __m128 m_v100;
    int unk110;
    int unk114;
    int unk118;
    float m_pFreeList;
};

struct S_00dad6a0_Out
{
    __m128 m_v0;
    __m128 m_v10;
    __m128 m_v20;
};

struct S_00dad6a0_Rec
{
    int unk0;
    unsigned char m_kPointA;
    unsigned char m_kPointB;
};
// @fnv 0x00dad6a0
static __declspec(noinline) int FUN_00dad6a0(S_00dad6a0_Rec* rec, S_00dad6a0_Vec* vecs, S_00dad6a0_Out* out)
{
    const __m128& pa = *(__m128*)((char*)vecs + rec->m_kPointA);
    const __m128& pb = *(__m128*)((char*)vecs + rec->m_kPointB);
    __m128 d = _mm_sub_ps(pa, pb);
    __m128 sq = _mm_mul_ps(d, d);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
    float f;
    _mm_store_ss(&f, s);
    if (f > vecs->m_pFreeList)
    {
        return 1;
    }
    out->m_v10 = d;
    out->m_v20 = vecs->m_v100;
    out->m_v0 = pa;
    return 0;
}
void CallTarget_dad6a0()
{
    S_00dad6a0_Out* o = (S_00dad6a0_Out*)FnvHavok_hkpgskmanifoldutil_g_out;
    g_res = FUN_00dad6a0((S_00dad6a0_Rec*)g_rec, (S_00dad6a0_Vec*)g_vecs, o);
    g_res = FUN_00dad6a0((S_00dad6a0_Rec*)g_rec, (S_00dad6a0_Vec*)g_vecs, o);
}

// Moved from hkpgskmanifoldutil_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
#include "fnv/symbols_00daf000.h"
static int FUN_00dad720(S_00dad720_Rec* rec, S_00dad720_Vec* vecs, S_00dad720_Out* out);
void CallTarget_dad720();
void FUN_00dae220(int unused, S_00dae220_Set* set);
class Mask
{
    __m128 bits;
    friend class Vec;

  public:
    enum
    {
        MASK_XY = 3
    };
    __forceinline int anyIsSet(int m) const
    {
        return _mm_movemask_ps(bits) & m;
    }
    __forceinline int GetLaneMask() const
    {
        return _mm_movemask_ps(bits);
    }
};
class Vec
{
    __m128 value;

  public:
    __forceinline Vec()
    {}
    __forceinline Vec(const Vec& input) : value(input.value)
    {}
    __forceinline void operator=(const Vec& input)
    {
        value = input.value;
    }
    __forceinline void operator=(const __m128& input)
    {
        value = input;
    }
    __forceinline __m128& getQuad()
    {
        return value;
    }
    __forceinline const __m128& getQuad() const
    {
        return value;
    }
    __forceinline float& operator()(int n)
    {
        return reinterpret_cast<float*>(&value)[n];
    }
    __forceinline const float& operator()(int n) const
    {
        return reinterpret_cast<const float*>(&value)[n];
    }
    __forceinline void setZero4()
    {
        value = _mm_setzero_ps();
    }
    __forceinline void setSub4(const Vec& a, const Vec& b)
    {
        value = _mm_sub_ps(a.value, b.value);
    }
    __forceinline void setAdd4(const Vec& a, const Vec& b)
    {
        value = _mm_add_ps(a.value, b.value);
    }
    __forceinline void setCross(const Vec& a, const Vec& b)
    {
        __m128 left = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xc9), _mm_shuffle_ps(b.value, b.value, 0xd2));
        __m128 right = _mm_mul_ps(_mm_shuffle_ps(a.value, a.value, 0xd2), _mm_shuffle_ps(b.value, b.value, 0xc9));
        value = _mm_sub_ps(left, right);
    }
    __forceinline Scalar dot3(const Vec& b) const
    {
        __m128 terms = _mm_mul_ps(value, b.value);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(terms, terms, 0x55), terms);
        return _mm_add_ss(_mm_shuffle_ps(terms, terms, 0xaa), sum);
    }
    __forceinline Scalar lengthSquared3() const
    {
        return dot3(*this);
    }
    __forceinline Scalar lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 square = dot3(*this).getQuad();
        const __m128 equal = _mm_cmpeq_ss(square, zero);
        const __m128 approx = _mm_rsqrt_ss(square);
        const __m128 refined =
            _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, approx), approx)));
        return _mm_andnot_ps(equal, refined);
    }
    __forceinline void normalize3()
    {
        __m128 reciprocal = lengthInverse3().broadcast();
        value = _mm_mul_ps(reciprocal, value);
    }
    __forceinline Scalar getSimdAt(int n) const
    {
        switch (n)
        {
        case 0:
            return value;
        case 1:
            return _mm_shuffle_ps(value, value, 0x55);
        case 2:
            return _mm_shuffle_ps(value, value, 0xaa);
        default:
            return _mm_shuffle_ps(value, value, 0xff);
        }
    }
    __forceinline void setInterpolate4(const Vec& a, const Vec& b, const Scalar& fraction)
    {
        __m128 t = fraction.broadcast();
        __m128 s = _mm_sub_ps(::DAT_010ec7f0, t);
        value = _mm_add_ps(_mm_mul_ps(s, a.value), _mm_mul_ps(t, b.value));
    }
    __forceinline void setAddMul4(const Vec& a, const Vec& b, const Scalar& scale)
    {
        value = _mm_add_ps(a.value, _mm_mul_ps(scale.broadcast(), b.value));
    }
    __forceinline void setNeg4(const Vec& a)
    {
        value = _mm_xor_ps(a.value, DAT_010c44d0);
    }
    __forceinline Mask compareLessThanZero4() const
    {
        Mask result;
        result.bits = _mm_cmplt_ps(value, _mm_setzero_ps());
        return result;
    }
};
template <class T> class Field
{
    T value;

  public:
    __forceinline Field()
    {}
    __forceinline Field(T input) : value(input)
    {}
    __forceinline void operator=(T input)
    {
        value = input;
    }
    __forceinline T val() const
    {
        return value;
    }
    __forceinline T operator->() const
    {
        return value;
    }
    __forceinline operator T() const
    {
        return val();
    }
};
namespace Parallel {
__forceinline void dot3_3vs3(const Vec& a, const Vec& b, const Vec& c, const Vec& d, const Vec& e, const Vec& f,
                             Vec& result)
{
    __m128 ab = _mm_mul_ps(a.getQuad(), b.getQuad());
    __m128 cd = _mm_mul_ps(c.getQuad(), d.getQuad());
    __m128 ef = _mm_mul_ps(e.getQuad(), f.getQuad());
    __m128 lower = _mm_unpacklo_ps(ab, cd);
    __m128 upper = _mm_shuffle_ps(_mm_unpackhi_ps(ab, cd), ef, 0xe4);
    ab = _mm_movelh_ps(lower, ef);
    cd = _mm_shuffle_ps(_mm_movehl_ps(ab, lower), ef, 0xd4);
    ef = upper;
    result.getQuad() = _mm_add_ps(_mm_add_ps(ab, cd), ef);
}
__forceinline void dot3_1vs4(const Vec& v, const Vec& a, const Vec& b, const Vec& c, const Vec& d, Vec& result)
{
    __m128 va = _mm_mul_ps(a.getQuad(), v.getQuad());
    __m128 vb = _mm_mul_ps(b.getQuad(), v.getQuad());
    __m128 vc = _mm_mul_ps(c.getQuad(), v.getQuad());
    __m128 vd = _mm_mul_ps(d.getQuad(), v.getQuad());
    __m128 abLo = _mm_shuffle_ps(va, vb, 0x44);
    __m128 abHi = _mm_shuffle_ps(va, vb, 0xee);
    __m128 cdLo = _mm_shuffle_ps(vc, vd, 0x44);
    __m128 cdHi = _mm_shuffle_ps(vc, vd, 0xee);
    va = _mm_shuffle_ps(abLo, cdLo, 0x88);
    vb = _mm_shuffle_ps(abLo, cdLo, 0xdd);
    vc = _mm_shuffle_ps(abHi, cdHi, 0x88);
    vd = _mm_shuffle_ps(abHi, cdHi, 0xdd);
    result.getQuad() = _mm_add_ps(_mm_add_ps(va, vb), vc);
}
__forceinline void dot3_2vs2(const Vec& a, const Vec& b, const Vec& c, const Vec& d, Vec& result)
{
    __m128 ac = _mm_mul_ps(a.getQuad(), c.getQuad());
    __m128 ad = _mm_mul_ps(a.getQuad(), d.getQuad());
    __m128 bc = _mm_mul_ps(b.getQuad(), c.getQuad());
    __m128 bd = _mm_mul_ps(b.getQuad(), d.getQuad());
    __m128 aLo = _mm_shuffle_ps(ac, ad, 0x44);
    __m128 aHi = _mm_shuffle_ps(ac, ad, 0xee);
    __m128 bLo = _mm_shuffle_ps(bc, bd, 0x44);
    __m128 bHi = _mm_shuffle_ps(bc, bd, 0xee);
    ac = _mm_shuffle_ps(aLo, bLo, 0x88);
    ad = _mm_shuffle_ps(aLo, bLo, 0xdd);
    bc = _mm_shuffle_ps(aHi, bHi, 0x88);
    bd = _mm_shuffle_ps(aHi, bHi, 0xdd);
    result.getQuad() = _mm_add_ps(_mm_add_ps(ac, ad), bc);
}
}

struct Feature
{
    unsigned char dimensionA, dimensionB;
    unsigned short id;
    unsigned char vertices[4];
};
struct Manifold
{
    unsigned char verticesA, verticesB, count, reserved;
    Feature features[4];
};
struct CdVertex : Vec
{
};
struct WorkData
{
    CdVertex points[16];
    Vec axis;
    Field<float> radiusA, radiusB, tolerance, maxDistanceSq;
    const Vec& getA(unsigned int offset) const
    {
        return *reinterpret_cast<const CdVertex*>(reinterpret_cast<const char*>(points) + offset);
    }
    const Vec& getB(unsigned int offset) const
    {
        return *reinterpret_cast<const CdVertex*>(reinterpret_cast<const char*>(points) + offset);
    }
};
struct Converted
{
    Vec position, difference, normal;
};
struct ProcessPoint
{
    Vec position, normal;
    Field<unsigned int> id;
    unsigned int extra0, extra1, extra2;
};
struct ProcessOutput
{
    Field<ProcessPoint*> next;
    Field<void*> owner;
    ProcessPoint* reserve(int)
    {
        return next;
    }
    void commit(int n)
    {
        next = next.val() + n;
    }
    void abort(int)
    {}
};
struct Manager
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void remove(unsigned short, void*);
};

__forceinline int pointPair(const WorkData& data, const Feature& feature, Converted& out)
{
    const Vec& a = data.getA(feature.vertices[0]);
    const Vec& b = data.getB(feature.vertices[1]);
    Vec difference;
    difference.setSub4(a, b);
    float square = difference.lengthSquared3();
    if (square > data.maxDistanceSq)
        return 1;
    out.difference = difference;
    out.normal = data.axis;
    out.position = a;
    return 0;
}
__forceinline int pointSegment(const WorkData& data, const Feature& feature, Converted& out)
{
    const Vec& a = data.getA(feature.vertices[0]);
    const Vec& b = data.getB(feature.vertices[1]);
    const Vec& c = data.getB(feature.vertices[2]);
    out.position = a;
    out.normal = data.axis;
    Vec edge;
    edge.setSub4(c, b);
    Vec fromC;
    fromC.setSub4(c, a);
    Vec fromB;
    fromB.setSub4(a, b);
    Vec cross;
    cross.setCross(edge, fromC);
    Vec products;
    Parallel::dot3_3vs3(fromC, edge, fromB, edge, cross, cross, products);
    float square = edge.lengthSquared3();
    int outside = products.compareLessThanZero4().anyIsSet(Mask::MASK_XY);
    if (products(3) > data.maxDistanceSq * square || outside)
        return 1;
    Scalar fraction = products.getSimdAt(0) / (products.getSimdAt(0) + products.getSimdAt(1));
    Vec onSegment;
    onSegment.setInterpolate4(b, c, fraction);
    out.difference.setSub4(a, onSegment);
    return 0;
}
__forceinline Vec copyVector(const Vec& input)
{
    Vec result;
    result = input;
    return result;
}
__forceinline int segmentPoint(const WorkData& data, const Feature& feature, Converted& out)
{
    const Vec& a = data.getA(feature.vertices[0]);
    const Vec& b = data.getB(feature.vertices[1]);
    const Vec& c = data.getB(feature.vertices[2]);
    out.normal = data.axis;
    const Vec& aValue = copyVector(a);
    Vec edge;
    edge.setSub4(b, aValue);
    Vec fromB;
    fromB.setSub4(b, c);
    Vec fromA;
    fromA.setSub4(c, a);
    Vec cross;
    cross.setCross(edge, fromB);
    Vec products;
    Parallel::dot3_3vs3(fromB, edge, fromA, edge, cross, cross, products);
    float square = edge.lengthSquared3();
    int outside = products.compareLessThanZero4().anyIsSet(Mask::MASK_XY);
    if (products(3) > data.maxDistanceSq * square || outside)
        return 1;
    Scalar fraction = products.getSimdAt(0) / (products.getSimdAt(0) + products.getSimdAt(1));
    out.position.setInterpolate4(b, a, fraction);
    out.difference.setSub4(out.position, c);
    return 0;
}
__forceinline int pointTriangle(const WorkData& data, const Feature& feature, Converted& out)
{
    const Vec& a = data.getA(feature.vertices[0]);
    const Vec& b = data.getB(feature.vertices[1]);
    const Vec& c = data.getB(feature.vertices[2]);
    const Vec& d = data.getB(feature.vertices[3]);
    out.position = a;
    out.difference.setSub4(a, b);
    Vec edge0;
    edge0.setSub4(d, c);
    Vec edge1;
    edge1.setSub4(b, d);
    Vec edge2;
    edge2.setSub4(c, b);
    Vec normal;
    normal.setCross(edge0, edge1);
    normal.normalize3();
    Vec products;
    {
        Vec toC;
        toC.setSub4(a, c);
        Vec toD;
        toD.setSub4(a, d);
        Vec toB;
        toB.setSub4(a, b);
        Vec side0;
        side0.setCross(toC, edge0);
        Vec side1;
        side1.setCross(toD, edge1);
        Vec side2;
        side2.setCross(toB, edge2);
        Parallel::dot3_1vs4(normal, side0, side1, side2, data.axis, products);
    }
    out.normal = normal;
    int mask = products.compareLessThanZero4().GetLaneMask();
    if (mask & 8)
        out.normal.setNeg4(normal);
    return (~mask) & 7;
}
__forceinline int trianglePoint(const WorkData& data, const Feature& feature, Converted& out)
{
    const Vec& a = data.getA(feature.vertices[0]);
    const Vec& b = data.getB(feature.vertices[1]);
    const Vec& c = data.getB(feature.vertices[2]);
    const Vec& d = data.getB(feature.vertices[3]);
    out.position = d;
    out.difference.setSub4(a, d);
    Vec edge0;
    edge0.setSub4(c, b);
    Vec edge1;
    edge1.setSub4(a, c);
    Vec edge2;
    edge2.setSub4(b, a);
    Vec normal;
    normal.setCross(edge0, edge1);
    normal.normalize3();
    Vec products;
    {
        Vec toB;
        toB.setSub4(d, b);
        Vec toC;
        toC.setSub4(d, c);
        Vec toA;
        toA.setSub4(d, a);
        Vec side0;
        side0.setCross(toB, edge0);
        Vec side1;
        side1.setCross(toC, edge1);
        Vec side2;
        side2.setCross(toA, edge2);
        Parallel::dot3_1vs4(normal, side0, side1, side2, data.axis, products);
    }
    Scalar projection = out.difference.dot3(normal);
    out.position.setAddMul4(d, normal, projection);
    out.normal = normal;
    int mask = products.compareLessThanZero4().GetLaneMask();
    if (mask & 8)
        out.normal.setNeg4(normal);
    return (~mask) & 7;
}
__forceinline int segmentPair(const WorkData& data, const Feature& feature, Converted& out)
{
    const Vec& a = data.getA(feature.vertices[0]);
    const Vec& b = data.getA(feature.vertices[1]);
    const Vec& c = data.getB(feature.vertices[2]);
    const Vec& d = data.getB(feature.vertices[3]);
    Vec edgeA;
    edgeA.setSub4(b, a);
    Vec edgeB;
    edgeB.setSub4(d, c);
    Vec difference0;
    difference0.setSub4(a, c);
    Vec difference1;
    difference1.setSub4(b, d);
    Vec normal;
    normal.setCross(edgeA, edgeB);
    Vec ortA;
    ortA.setCross(edgeA, normal);
    Vec ortB;
    ortB.setCross(edgeB, normal);
    out.normal = data.axis;
    Vec products;
    Parallel::dot3_2vs2(difference0, difference1, ortB, ortA, products);
    int mask = products.compareLessThanZero4().GetLaneMask();
    if (mask != 3 && mask != 12)
        return 1;
    Scalar first = products.getSimdAt(0);
    Scalar t = first / (first - products.getSimdAt(2));
    out.position.setInterpolate4(a, b, t);
    Scalar second = products.getSimdAt(1);
    Scalar u = second / (second - products.getSimdAt(3));
    Vec onB;
    onB.setInterpolate4(c, d, u);
    out.difference.setSub4(out.position, onB);
    return 0;
}
__forceinline int convert(const WorkData& data, const Feature& feature, Converted& out)
{
    switch (feature.dimensionA * 4 + feature.dimensionB)
    {
    case 0:
        return 1;
    case 5:
        return pointPair(data, feature, out);
    case 6:
        return pointSegment(data, feature, out);
    case 7:
        return pointTriangle(data, feature, out);
    case 9:
        return segmentPoint(data, feature, out);
    case 10:
        return segmentPair(data, feature, out);
    case 13:
        return trianglePoint(data, feature, out);
    default:
        return 1;
    }
}
__forceinline void downshift(Manifold& manifold, int oldCount, int newCount)
{
    unsigned int* dst = reinterpret_cast<unsigned int*>(&manifold.features[newCount]);
    unsigned int* src = reinterpret_cast<unsigned int*>(&manifold.features[oldCount]);
    for (int n = (manifold.verticesA + manifold.verticesB - 1) >> 1; n >= 0; --n)
        *dst++ = *src++;
}
static __declspec(noinline) void FUN_00dae220(Manifold* manifold)
{
    unsigned char used[16] = {0};
    unsigned int pointCount = manifold->count;
    for (unsigned int p = 0; p < pointCount; ++p)
    {
        const Feature& f = manifold->features[p];
        int dimensions = f.dimensionA + f.dimensionB;
        used[f.vertices[0] >> 4] = 1;
        used[f.vertices[1] >> 4] = 1;
        if (dimensions >= 3)
            used[f.vertices[2] >> 4] = 1;
        if (dimensions == 4)
            used[f.vertices[3] >> 4] = 1;
    }
    unsigned short* ids = reinterpret_cast<unsigned short*>(&manifold->features[pointCount]);
    int total = manifold->verticesA + manifold->verticesB;
    int map[16];
    int outCount = 0;
    int offset = 0;
    for (int i = 0; i < total; ++i)
    {
        map[i] = offset;
        if (used[i])
        {
            ids[outCount++] = ids[i];
            offset += 16;
        }
    }
    int newA = map[manifold->verticesA] >> 4;
    manifold->verticesA = static_cast<unsigned char>(newA);
    manifold->verticesB = static_cast<unsigned char>(outCount - newA);
    for (unsigned int p = 0; p < manifold->count; ++p)
    {
        Feature& f = manifold->features[p];
        f.vertices[0] = static_cast<unsigned char>(map[f.vertices[0] >> 4]);
        f.vertices[1] = static_cast<unsigned char>(map[f.vertices[1] >> 4]);
        f.vertices[2] = static_cast<unsigned char>(map[f.vertices[2] >> 4]);
        f.vertices[3] = static_cast<unsigned char>(map[f.vertices[3] >> 4]);
    }
}

// @fnv 0x00dae3a0
void __cdecl FUN_00dae3a0(Manifold& manifold, const WorkData& data, int start, ProcessOutput& output, Manager* mgr)
{
    unsigned int oldCount = manifold.count;
    unsigned int count = oldCount;
    for (unsigned int index = start; index < count; ++index)
    {
        ProcessPoint* point = output.reserve(1);
        Feature& feature = manifold.features[index];
        Converted converted;
        converted.position.setZero4();
        converted.difference.setZero4();
        converted.normal.setZero4();
        int result = convert(data, feature, converted);
        if (result == 0)
        {
            const Vec& normal = converted.normal;
            float distance = normal.dot3(converted.difference);
            float radiusSum = data.radiusA + data.radiusB;
            Scalar shift = data.radiusB - distance;
            distance -= radiusSum;
            if (distance < data.tolerance)
            {
                point->position.setAddMul4(converted.position, normal, shift);
                point->normal = normal;
                point->normal(3) = distance;
                point->id = feature.id;
                output.commit(1);
                continue;
            }
        }
        output.abort(1);
        if (feature.id != 0xffff)
            mgr->remove(feature.id, output.owner.val());
        --count;
        feature = manifold.features[count];
        --index;
    }
    if (oldCount > count)
    {
        manifold.count = static_cast<unsigned char>(count);
        downshift(manifold, oldCount, count);
        FUN_00dae220(&manifold);
    }
}
