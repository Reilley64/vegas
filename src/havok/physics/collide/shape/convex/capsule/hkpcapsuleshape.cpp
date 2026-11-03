
// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <bit>
#include "fnv/decl/FunctionContext.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkpCapsuleShape.h"


// @fnv 0x00d22360
void __cdecl FUN_00d22360(char const* const* arg1, char const* const* arg2)
{
    reinterpret_cast<::FunctionContext *>((void *)(arg1))->FUN_00c90360((void *)(&(*reinterpret_cast<const char *const *>(&::g_01268940))), {});
}

// @fnv 0x00d22350
int __cdecl FUN_00d22350()
{
    return 2;
}

// @fnv 0x00d22d60
int FUN_00d22d60(int a, int b)
{
    return 0x40;
}

#include "fnv/symbols_simd.h"

class FUN_00d223f0_cls
{
  public:
    void GatherIndexedVectors(unsigned short const* indices, int count, hkVector4* out);
};

// @fnv 0x00d223f0
void FUN_00d223f0_cls::GatherIndexedVectors(unsigned short const* indices, int count, hkVector4* out)
{
    int iRemaining = count - 1;
    if (iRemaining < 0)
    {
        return;
    }
    hkVector4* pOut = out;
    unsigned short const* p = indices;
    do
    {
        unsigned int uiIndex = *p;
        __m128 v = _mm_load_ps(reinterpret_cast<float const*>(reinterpret_cast<char*>(this) + uiIndex + 0x20));
        _mm_store_ps(reinterpret_cast<float*>(pOut), v);
        *reinterpret_cast<unsigned int*>(&pOut->w) = uiIndex | 0x3f000000;
        pOut++;
        p++;
        iRemaining--;
    } while (iRemaining >= 0);
}

struct __declspec(align(16)) hkVector4D224
{
    __m128 m_vComponents;

    hkVector4D224()
    {}
    hkVector4D224(const hkVector4D224& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class FUN_00d22480_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkVector4D224 m_vector;

    hkVector4D224 FUN_00d22480() const;
};

// @fnv 0x00d22480
hkVector4D224 FUN_00d22480_cls::FUN_00d22480() const
{
    return m_vector;
}

struct FUN_00d224a0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 unk20;
    __m128 unk30;

    void FUN_00d224a0(__m128* result);
};

// @fnv 0x00d224a0
void FUN_00d224a0_Data::FUN_00d224a0(__m128* result)
{
    result[0] = unk20;
    result[1] = unk30;
}

extern int DAT_010ce25c;
union __declspec(align(16)) AlignedHKVector4
{
    __m128 simd;
    struct
    {
        float x, y, z, w;
    };
};
struct FUN_00d22590_Class : hkpCapsuleShape
{
    FUN_00d22590_Class* FUN_00d22590(const AlignedHKVector4& first, const AlignedHKVector4& second,
                                                float radius);
};
// Initializes a capsule shape from two points and a radius, storing the radius in both endpoints' w components and setting the type to 5.
// @fnv 0x00d22590
FUN_00d22590_Class* FUN_00d22590_Class::FUN_00d22590(const AlignedHKVector4& first,
                                                                const AlignedHKVector4& second, float radius)
{
    m_fSphereRadius = radius;
    m_sReferenceCount = 1;
    m_ulUserData = 0;
    m_type = 5;
    *reinterpret_cast<void**>(this) = &DAT_010ce25c;
    reinterpret_cast<AlignedHKVector4*>(&m_kVertexA)->simd = first.simd;
    reinterpret_cast<AlignedHKVector4*>(&m_kVertexB)->simd = second.simd;
    *reinterpret_cast<volatile float*>(&m_kVertexA.w) = radius;
    *reinterpret_cast<volatile float*>(&m_kVertexB.w) = radius;
    return this;
}

struct __declspec(align(16)) Point4
{
    float x, y, z, w;
};
struct ClosestLineResult
{
    float distance;
    float fractionA;
    float fractionB;
    float extraValue;
    Point4 pointA;
    Point4 pointB;
};
// Calls FUN_00d231b0 to compute the closest points between two lines and writes the points, fractions and distance to the output pointers.
// @fnv 0x00d22700
void __cdecl GetClosestLinePoints(const Point4& aLineAStart, const Point4& aLineAEnd, const Point4& aLineBStart,
                                  const Point4& aLineBEnd, float* pfDistance, float* pfFractionA, float* pfFractionB,
                                  Point4* pointA, Point4* pointB)
{
    ClosestLineResult result;
    ::FUN_00d231b0((const __m128 *)&(aLineAStart), (const __m128 *)&(aLineAEnd), (const __m128 *)&(aLineBStart), (const __m128 *)&(aLineBEnd), (::ClosestPointResult *)(::ClosestLineResult *)(&result));
    *reinterpret_cast<__m128*>(pointA) = *reinterpret_cast<const __m128*>(&result.pointA);
    *reinterpret_cast<__m128*>(pointB) = *reinterpret_cast<const __m128*>(&result.pointB);
    *pfFractionA = result.fractionA;
    *pfFractionB = result.fractionB;
    *pfDistance = result.distance;
}


class Aabb_d22440
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 m_kMin;
    __m128 m_kMax;

    void FUN_00d22440(__m128* pkCenter) const;
};

// Stores (m_kMax + m_kMin) scaled by the float at DAT_01016248 into pkCenter.
// @fnv 0x00d22440
void Aabb_d22440::FUN_00d22440(__m128* pkCenter) const
{
    __m128 sum = _mm_add_ps(m_kMax, m_kMin);
    *pkCenter = sum;
    __m128 kHalf = _mm_load_ss(&::fnv_00c88020::DAT_01016248);
    kHalf = _mm_shuffle_ps(kHalf, kHalf, 0);
    *pkCenter = _mm_mul_ps(kHalf, sum);
}


// Projects a point onto a line segment defined by two endpoints, clamping the result to the segment bounds and writing it to out.
// @fnv 0x00d224c0
void __cdecl FUN_00d224c0(float* apPoint, float* apStart, float* apEnd, float* out)
{
    __m128 vStart = _mm_load_ps(apStart);
    __m128 vEnd = _mm_load_ps(apEnd);
    __m128 vPoint = _mm_load_ps(apPoint);

    __m128 xmm2 = vStart;
    __m128 xmm3 = vEnd;
    __m128 xmm4 = vPoint;

    __m128 xmm1 = _mm_sub_ps(xmm3, xmm2);
    __m128 xmm0 = _mm_sub_ps(xmm2, xmm4);

    xmm0 = _mm_mul_ps(xmm0, xmm1);

    __m128 temp4 = xmm0;
    temp4 = _mm_shuffle_ps(temp4, xmm0, 0x55);
    temp4 = _mm_add_ss(temp4, xmm0);

    __m128 temp5 = xmm0;
    temp5 = _mm_shuffle_ps(temp5, xmm0, 0xaa);
    temp5 = _mm_add_ss(temp5, temp4);

    float negDot;
    float lenSq;

    _mm_store_ss(&negDot, temp5);
    negDot = -negDot;

    __m128 l0 = _mm_mul_ps(xmm1, xmm1);
    __m128 ls1 = _mm_shuffle_ps(l0, l0, 0x55);
    ls1 = _mm_add_ss(ls1, l0);
    __m128 ls2 = _mm_shuffle_ps(l0, l0, 0xaa);
    ls2 = _mm_add_ss(ls2, ls1);

    _mm_store_ss(&lenSq, ls2);

    if (negDot <= 0.0f)
    {
        _mm_store_ps(out, vStart);
        return;
    }

    if (lenSq <= negDot)
    {
        _mm_store_ps(out, vEnd);
        return;
    }

    negDot /= lenSq;

    __m128 tVec = _mm_load_ss(&negDot);
    __m128 tBroadcast = _mm_shuffle_ps(tVec, tVec, 0);
    __m128 scaledDiff = _mm_mul_ps(xmm1, tBroadcast);
    __m128 result = _mm_add_ps(vStart, scaledDiff);

    _mm_store_ps(out, result);
}

struct hkSimdRealD223
{
    __m128 m_vValue;

    hkSimdRealD223(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkVector4D223
{
    __m128 m_vComponents;

    hkVector4D223()
    {}
    hkVector4D223(const hkVector4D223& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D223& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setSub4(const hkVector4D223& a, const hkVector4D223& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD223 dot3(const hkVector4D223& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    void setInt24W(int i)
    {
        m_vComponents[3] = std::bit_cast<float>(i | 0x3f000000);
    }
};

class hkBaseObjectD223
{
  public:
    virtual ~hkBaseObjectD223() throw();
};

class hkReferencedObjectD223 : public hkBaseObjectD223
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpCapsuleShapeD223 : public hkReferencedObjectD223
{
  public:
    void FUN_00d22370(const hkVector4D223& kDirection, hkVector4D223& kSupportingVertexOut) const;

    unsigned int m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
    unsigned int unk14, unk18, unk1C;
    hkVector4D223 m_kVertexA;
    hkVector4D223 m_kVertexB;
};

// Picks vertex A or B by the sign of (B - A) dot kDirection, writes it to kSupportingVertexOut, and stores the vertex id (0 or 16) in W.
// @fnv 0x00d22370
void hkpCapsuleShapeD223::FUN_00d22370(const hkVector4D223& kDirection, hkVector4D223& kSupportingVertexOut) const
{
    hkVector4D223 kDelta;
    kDelta.setSub4(m_kVertexB, m_kVertexA);
    const float fDot = kDelta.dot3(kDirection);
    int iVertexId;
    if (fDot < 0.0f)
    {
        kSupportingVertexOut = m_kVertexA;
        iVertexId = 0;
    }
    else
    {
        kSupportingVertexOut = m_kVertexB;
        iVertexId = sizeof(hkVector4D223);
    }
    kSupportingVertexOut.setInt24W(iVertexId);
}


struct hkTransformq;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void SetAllComponents(hkReal x)
    {
        m_vComponents = _mm_set_ps1(x);
    }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void sub4(const hkVector4q& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn);
};

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

union hkVector4U
{
    hkVector4 m_vec;
    __m128 m_vComponents;
};

struct hkTransformU
{
    hkVector4U m_kColumn0;
    hkVector4U m_kColumn1;
    hkVector4U m_kColumn2;
    hkVector4U m_vTranslation;

    __forceinline void set(const hkTransform& t)
    {
        m_kColumn0.m_vec = t.m_rotation.m_kColumn0;
        m_kColumn1.m_vec = t.m_rotation.m_kColumn1;
        m_kColumn2.m_vec = t.m_rotation.m_kColumn2;
        m_vTranslation.m_vec = t.m_vTranslation;
    }
};

__forceinline void hkVector4q::SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn)
{
    const __m128 b = bIn.m_vComponents;
    const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
    const __m128 r0 = _mm_mul_ps(a.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
    const __m128 r1 = _mm_mul_ps(a.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, a.m_vTranslation.m_vComponents));
}

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

static __forceinline void hkTransformPoints(const hkTransform& t, const hkVector4q* vectorsIn, int numVectors,
                                            hkVector4q* vectorsOut)
{
    hkVector4U c0;
    c0.m_vec = t.m_rotation.m_kColumn0;
    hkVector4U c1;
    c1.m_vec = t.m_rotation.m_kColumn1;
    hkVector4U c2;
    c2.m_vec = t.m_rotation.m_kColumn2;
    hkVector4U trans;
    trans.m_vec = t.m_vTranslation;
    int i = numVectors - 1;
    do
    {
        const __m128 b = vectorsIn[i].m_vComponents;
        const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
        const __m128 r0 = _mm_mul_ps(c0.m_vComponents, b0);
        const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
        const __m128 r1 = _mm_mul_ps(c1.m_vComponents, b1);
        const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
        const __m128 r2 = _mm_mul_ps(c2.m_vComponents, b2);
        vectorsOut[i].m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, trans.m_vComponents));
    } while (--i >= 0);
}

class hkpCapsuleShapeAabb : public hkpCapsuleShape
{
  public:
    void FUN_00d225e0(const hkTransform& localToWorld, hkReal tolerance, hkAabbq& out) const;
};

// Computes the world-space AABB of the capsule by transforming its two vertices and expanding by the sphere radius plus tolerance.
// @fnv 0x00d225e0
void hkpCapsuleShapeAabb::FUN_00d225e0(const hkTransform& localToWorld, hkReal tolerance, hkAabbq& out) const
{
    hkVector4q tol4;
    tol4.SetAllComponents(m_fSphereRadius + tolerance);

    hkVector4q obj[2];
    hkTransformPoints(localToWorld, reinterpret_cast<const hkVector4q*>(&m_kVertexA), 2, &obj[0]);

    out.m_kMinimumCorner.setMin4(obj[0], obj[1]);
    out.m_kMinimumCorner.sub4(tol4);
    out.m_kMaximumCorner.setMax4(obj[0], obj[1]);
    out.m_kMaximumCorner.add4(tol4);
}

// Moved from hkpcapsuleshape_ehsc_noehsc_variant_rtm_variant.cpp (VEGAS-15).
#include <intrin.h>
#include <windows.h>
#include <cmath>
void __cdecl FUN_00d22360(char const* const* arg1, char const* const* arg2);
int __cdecl FUN_00d22350();
int FUN_00d22d60(int a, int b);
void __cdecl FUN_00d231b0(const Point4& a, const Point4& b,
                            const Point4& c, const Point4& d,
                            ClosestLineResult* out);
void __cdecl GetClosestLinePoints(const Point4& aLineAStart, const Point4& aLineAEnd, const Point4& aLineBStart, const Point4& aLineBEnd, float* pfDistance, float* pfFractionA, float* pfFractionB, Point4* pointA, Point4* pointB);
void __cdecl FUN_00d224c0(float* arg1, float* arg2, float* arg3, float* out);


class S00d22760_SimdReal {
public:
    __forceinline S00d22760_SimdReal(const __m128& x) : m_vValue(x) {}
    __forceinline S00d22760_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    __forceinline S00d22760_SimdReal() {}
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const __m128& getQuad() const { return m_vValue; }
private:
    __m128 m_vValue;
};
typedef const S00d22760_SimdReal& S00d22760_SimdParam;
static __forceinline S00d22760_SimdReal operator-(S00d22760_SimdParam r) {
    return _mm_sub_ss(DAT_010c7160, r.getQuad());
}
class __declspec(align(16)) S00d22760_Vec {
public:
    __forceinline S00d22760_Vec() {}
    __forceinline S00d22760_Vec(const S00d22760_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void operator=(const S00d22760_Vec& v) { m_vComponents = v.m_vComponents; }
    __forceinline void setZero4() { m_vComponents = _mm_setzero_ps(); }
    __forceinline void setSub4(const S00d22760_Vec& a, const S00d22760_Vec& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAddMul4(const S00d22760_Vec& a, const S00d22760_Vec& b, S00d22760_SimdParam r) {
        m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
    }
    __forceinline void setInterpolate4(const S00d22760_Vec& v0, const S00d22760_Vec& v1, S00d22760_SimdParam _t) {
        __m128 t = _t.broadcast();
        __m128 s = _mm_sub_ps(DAT_010ec7f0, t);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
    }
    __forceinline S00d22760_SimdReal dot3(const S00d22760_Vec& a) const {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00d22760_SimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline S00d22760_SimdReal lengthInverse3() const {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3() {
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline S00d22760_SimdReal normalizeWithLength3() {
        __m128 len2 = this->dot3(*this).getQuad();
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
        return _mm_mul_ss(len2, lenInv);
    }
    __m128 m_vComponents;
};
class S00d22760_Bool {
public:
    __forceinline S00d22760_Bool() {}
    __forceinline S00d22760_Bool(bool b) { m_cBooleanValue = (char)b; }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
    char m_cBooleanValue;
};
struct S00d22760_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    __forceinline void setTime() {
        unsigned int ticks;
        ticks = static_cast<unsigned int>(__rdtsc());
        m_uiStartTicks = ticks;
    }
};
class S00d22760_Stream {
public:
    __forceinline static S00d22760_Stream& GetMonitorStream() { return *(S00d22760_Stream*)TlsGetValue(DAT_0126835c); }
    __forceinline S00d22760_Bool memoryAvailable() { return m_kRayEnd < m_pCurrentCommand; }
    __forceinline char* GetStreamEnd() { return m_kRayEnd; }
    __forceinline void setEnd(char* e) { m_kRayEnd = e; }
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};
class S00d22760_TimeHelper {
public:
    __forceinline S00d22760_TimeHelper() {}
    __forceinline ~S00d22760_TimeHelper() {
        S00d22760_Stream& mStream = S00d22760_Stream::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            S00d22760_TimerCommand* h = reinterpret_cast<S00d22760_TimerCommand*>(mStream.GetStreamEnd());
            h->m_pCommandName = "Et";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
};
struct __declspec(align(16)) S00d22760_Input {
    __forceinline S00d22760_Input() : m_uiFilterInfo(0), m_pRayShapeCollectionFilter(0) {}
    S00d22760_Vec m_vFrom;
    S00d22760_Vec m_vTo;
    unsigned int m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
};
struct __declspec(align(16)) S00d22760_Output {
    S00d22760_Vec m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_pad18;
    int m_pad1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    __forceinline void setKey(unsigned int key) { m_uiShapeKeys[m_uiShapeKeyIndex] = key; }
};
static __forceinline float S00d22760_sqrtf(float r) { return (float)sqrt(r); }
struct __declspec(align(16)) S00d22760_LineResult {
    __forceinline S00d22760_LineResult() {}
    float m_fValue;
    float m_fFirstParameter;
    float m_fSecondParameter;
    float unk0c;
    S00d22760_Vec m_kFirstVector;
    S00d22760_Vec m_kSecondVector;
};
int __cdecl FUN_00d231b0(const S00d22760_Vec& A, const S00d22760_Vec& dA, const S00d22760_Vec& B, const S00d22760_Vec& dB, S00d22760_LineResult& result);
__declspec(noinline) void __cdecl GetClosestLinePoints(const S00d22760_Vec& A, const S00d22760_Vec& dA, const S00d22760_Vec& B, const S00d22760_Vec& dB, float& distSquared, float& t, float& u, S00d22760_Vec& p, S00d22760_Vec& q)
{
    S00d22760_LineResult result;
    FUN_00d231b0(A, dA, B, dB, result);
    p = result.m_kFirstVector;
    q = result.m_kSecondVector;
    t = result.m_fFirstParameter;
    u = result.m_fSecondParameter;
    distSquared = result.m_fValue;
}
__declspec(noinline) void __cdecl FUN_00d224c0(const S00d22760_Vec& A, const S00d22760_Vec& B, const S00d22760_Vec& B2, S00d22760_Vec& pt)
{
    S00d22760_Vec d12;
    d12.setSub4(B, A);
    S00d22760_Vec dB;
    dB.setSub4(B2, B);
    float S2 = dB.dot3(d12);
    float D2 = dB.dot3(dB);
    float u = -S2;
    if (u <= 0.0f) {
        pt = B;
    } else if (D2 <= u) {
        pt = B2;
    } else {
        u /= D2;
        pt.setAddMul4(B, dB, u);
    }
}
S00d22760_Bool __cdecl FUN_00cd85c0(float radius, const S00d22760_Input& input, S00d22760_Output& results);

class S00d22760_Capsule : public hkpConvexShape {
public:
    enum { HIT_CAP0 = 0, HIT_CAP1 = 1, HIT_BODY = 2 };
    __forceinline const S00d22760_Vec* GetIndexedVertices() const { return &m_kVertexA; }
    __forceinline const S00d22760_Vec& getVertex(int i) const { return GetIndexedVertices()[i]; }
    __declspec(noinline) S00d22760_Bool FUN_00d22760(const S00d22760_Input& input, S00d22760_Output& results) const;
    int unk14;
    int unk18;
    int unk1c;
    S00d22760_Vec m_kVertexA;
    S00d22760_Vec m_kVertexB;
};

// @fnv 0x00d22760
__declspec(noinline) S00d22760_Bool S00d22760_Capsule::FUN_00d22760(const S00d22760_Input& input, S00d22760_Output& results) const
{
    {
        S00d22760_Stream& mStream = S00d22760_Stream::GetMonitorStream();
        if (mStream.memoryAvailable()) {
            S00d22760_TimerCommand* h = reinterpret_cast<S00d22760_TimerCommand*>(mStream.GetStreamEnd());
            h->m_pCommandName = "TtrcCapsule";
            h->setTime();
            mStream.setEnd((char*)(h + 1));
        }
    }
    S00d22760_TimeHelper timeblock206;
    {
        S00d22760_Vec res;
        FUN_00d224c0(input.m_vFrom, getVertex(0), getVertex(1), res);
        S00d22760_Vec join;
        join.setSub4(input.m_vFrom, res);
        float sToCylDistSq = join.lengthSquared3();
        if (sToCylDistSq < m_fSphereRadius * m_fSphereRadius) {
            goto returnFalse;
        }
        float infInfDistSquared = 3.40282e+38f;
        S00d22760_Vec dA;
        dA.setSub4(input.m_vTo, input.m_vFrom);
        S00d22760_Vec dB;
        dB.setSub4(getVertex(1), getVertex(0));
        float t;
        float u;
        S00d22760_Vec p;
        S00d22760_Vec q;
        GetClosestLinePoints(input.m_vFrom, dA, getVertex(0), dB, infInfDistSquared, t, u, p, q);
        if (infInfDistSquared > m_fSphereRadius * m_fSphereRadius) {
            goto returnFalse;
        }
        S00d22760_Vec axis;
        axis = dB;
        float axisLength;
        float ipT;
        {
            const float axisLengthSqrd = axis.lengthSquared3();
            if (axisLengthSqrd > 1.192092896e-07f) {
                axisLength = axis.normalizeWithLength3();
            } else {
                axisLength = 0.0f;
                axis.setZero4();
            }
            S00d22760_Vec dir = dA;
            S00d22760_SimdReal component = dir.dot3(axis);
            S00d22760_Vec flatDir;
            flatDir.setAddMul4(dir, axis, -component);
            const float flatDirLengthSquared3 = flatDir.lengthSquared3();
            if (flatDirLengthSquared3 != 0.0f) {
                float d = (m_fSphereRadius * m_fSphereRadius - infInfDistSquared) / flatDirLengthSquared3;
                ipT = t - S00d22760_sqrtf(d);
            } else {
                ipT = -1.0f;
            }
        }
        if (ipT >= results.m_fHitFraction) {
            goto returnFalse;
        }
        float pointAProj = getVertex(0).dot3(axis);
        S00d22760_Vec intersectPt;
        intersectPt.setInterpolate4(input.m_vFrom, input.m_vTo, ipT);
        const float ptProj = intersectPt.dot3(axis);
        float ptHeight = ptProj - pointAProj;
        if (ipT >= 0.0f && ptHeight > 0.0f && axisLength > ptHeight) {
            S00d22760_Vec projPtOnAxis;
            projPtOnAxis.setInterpolate4(getVertex(0), getVertex(1), ptHeight / axisLength);
            S00d22760_Vec normal;
            normal.setSub4(intersectPt, projPtOnAxis);
            normal.normalize3();
            results.m_vHitNormal = normal;
            results.m_fHitFraction = ipT;
            results.m_iExtraInfo = HIT_BODY;
            results.setKey(0xffffffff);
            return S00d22760_Bool(true);
        }
        {
            float fromLocalProj = input.m_vFrom.dot3(axis);
            float projParam = fromLocalProj - pointAProj;
            S00d22760_Vec fromPtProjAxis;
            fromPtProjAxis.setInterpolate4(getVertex(0), getVertex(1), projParam / axisLength);
            S00d22760_Vec axisToRayStart;
            axisToRayStart.setSub4(input.m_vFrom, fromPtProjAxis);
            if (ipT < 0.0f && axisToRayStart.lengthSquared3() > m_fSphereRadius * m_fSphereRadius) {
                goto returnFalse;
            }
            S00d22760_Input subInput;
            const int extra = (ptHeight <= 0.0f) ? HIT_CAP0 : HIT_CAP1;
            subInput.m_vFrom.setSub4(input.m_vFrom, getVertex(extra));
            subInput.m_vTo.setSub4(input.m_vTo, getVertex(extra));
            if (FUN_00cd85c0(m_fSphereRadius, subInput, results)) {
                results.m_iExtraInfo = extra;
                return S00d22760_Bool(true);
            }
            return S00d22760_Bool(false);
        }
    }
returnFalse:
    return S00d22760_Bool(false);
}
