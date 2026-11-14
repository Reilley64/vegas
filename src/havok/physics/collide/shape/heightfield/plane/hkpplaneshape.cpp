
// src/havok/physics/collide/shape/heightfield/plane/hkpplaneshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/plane/hkpplaneshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
#include "fnv/decl/FUN_00c7f750_shell.h"
#include "fnv/decl/FunctionContext.h"
#include "fnv/symbols_00d26000.h"
#include "fnv/symbols_010d0000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_01269000.h"
#include "havok/hkpPlaneShape.h"
#include <xmmintrin.h>
#include "fnv/symbols_simd.h"


struct FUN_00d552c0_StandIn : hkpPlaneShape
{
    void FUN_00d552c0(const ::hkTransformD262*, float, ::hkAabbD262*);
};

// Forwards param1, the objects at offsets 0x30 and 0x20 of this, param2 and param3 to FUN_00d26230.
// @fnv 0x00d552c0
void FUN_00d552c0_StandIn::FUN_00d552c0(const ::hkTransformD262* param1, float param2, ::hkAabbD262* param3)
{
    ::FUN_00d26230(*param1, reinterpret_cast<const ::hkVector4D262&>(m_kAabbHalfExtents), reinterpret_cast<const ::hkVector4D262&>(m_kAabbCenter), param2, *param3);
}

struct GlobalObjectO2_00d472a0;

class hkStatisticsCollectorD54F;

class hkReferencedObjectD54F
{
  public:
    virtual ~hkReferencedObjectD54F() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

};

class hkObjectD54F : public hkReferencedObjectD54F
{
  public:
    void FUN_00d54f80(hkStatisticsCollectorD54F* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const;
};

// @fnv 0x00d54f80
void hkObjectD54F::FUN_00d54f80(hkStatisticsCollectorD54F* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const
{
    reinterpret_cast<::FunctionContext *>((void *)this)->FUN_00c90360(pkCollector, (void *)(&g_01269b84));
}

struct __declspec(align(16)) Vector4D54F90
{
    float x;
    float y;
    float z;
    float w;
};
struct RayCastOutputD54F90
{
    RayCastOutputD54F90() : m_iExtraInfo(-1), m_uiShapeKeyIndex(0)
    {
        m_uiShapeKeys[0] = -1;
    }
    Vector4D54F90 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_pad18;
    int m_pad1C;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};
struct BoolD54F90
{
    char m_cBooleanValue;
};
struct RayCastInputD54F90;
struct CdBodyD54F90
{
    int unk00;
    int unk04;
    const void* m_pMotionState;
};
struct CollectorD54F90
{
    virtual void CollectRayHit(const CdBodyD54F90& kBody, const RayCastOutputD54F90& kOutput);
    float m_fEarlyOutHitFraction;
};
struct ShapeD54F90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual BoolD54F90 RayCast(const RayCastInputD54F90& kInput, RayCastOutputD54F90& kOutput) const;
    void FUN_00d54f90(const RayCastInputD54F90& kInput, const CdBodyD54F90& kBody, CollectorD54F90& kCollector) const;
};

// Performs a ray cast against the shape, and if a hit is found, transforms the hit normal and forwards the result to the collector.
// @fnv 0x00d54f90
void ShapeD54F90::FUN_00d54f90(const RayCastInputD54F90& kInput, const CdBodyD54F90& kBody,
                               CollectorD54F90& kCollector) const
{
    RayCastOutputD54F90 kOutput;
    kOutput.m_fHitFraction = kCollector.m_fEarlyOutHitFraction;
    BoolD54F90 kHit = RayCast(kInput, kOutput);
    if (kHit.m_cBooleanValue)
    {
        reinterpret_cast<::FUN_00c7f750_shell *>((void *)(kBody.m_pMotionState))->FUN_00c7f750((float *)&(kOutput.m_vHitNormal), {});
        kCollector.CollectRayHit(kBody, kOutput);
    }
}

#include <xmmintrin.h>

struct PlaneShape_00d551d0 : hkpPlaneShape
{
    PlaneShape_00d551d0* FUN_00d551d0(const hkVector4& p, const hkVector4* box);
};

// Sets type 0x1c, stores p in m_kTriangleNormal, and sets the AABB center and half-extents from the two corner vectors in box.
// @fnv 0x00d551d0
PlaneShape_00d551d0* PlaneShape_00d551d0::FUN_00d551d0(const hkVector4& p, const hkVector4* box)
{
    m_ulUserData = 0;
    m_type = 0x1c;
    *(void**)this = &(*reinterpret_cast<char *>(&::DAT_010d0e18));
    m_sReferenceCount = 1;
    *(__m128*)&m_kTriangleNormal = *(const __m128*)&p;
    *(__m128*)&m_kAabbCenter = _mm_mul_ps(_mm_add_ps(*(const __m128*)&box[1], *(const __m128*)&box[0]), DAT_010c71d0);
    *(__m128*)&m_kAabbHalfExtents =
        _mm_mul_ps(_mm_sub_ps(*(const __m128*)&box[1], *(const __m128*)&box[0]), DAT_010c71d0);
    return this;
}

struct __declspec(align(16)) PlaneVector
{
    __m128 value;
    __forceinline float Dot3(const PlaneVector& other) const
    {
        __m128 product = _mm_mul_ps(value, other.value);
        __m128 y = _mm_shuffle_ps(product, product, 0x55);
        __m128 z = _mm_shuffle_ps(product, product, 0xaa);
        __m128 sum = _mm_add_ss(y, product);
        __m128 total = _mm_add_ss(z, sum);
        return _mm_cvtss_f32(total);
    }
};
struct PlaneReference
{
    unsigned short memoryFlags;
    short referenceCount;
    PlaneReference() : referenceCount(1)
    {}
    virtual ~PlaneReference();
};
struct PlaneShapeBase : PlaneReference
{
    unsigned int userData;
    unsigned int type;
    PlaneShapeBase(unsigned int shapeType) : userData(0), type(shapeType)
    {}
};
struct FUN_00d55240 : PlaneShapeBase
{
    PlaneVector plane, centerVector, extentVector;
    FUN_00d55240(const PlaneVector& normal, const PlaneVector& center, const PlaneVector& extents);
    virtual ~FUN_00d55240();
};
// Initialises a plane shape with the given normal, center and extents, computing the plane offset as the negative dot of normal and center.
// @fnv 0x00d55240
FUN_00d55240::FUN_00d55240(const PlaneVector& normal, const PlaneVector& center, const PlaneVector& extents)
    : PlaneShapeBase(28)
{
    plane.value = normal.value;
    plane.value[3] = -normal.Dot3(center);
    centerVector.value = center.value;
    extentVector.value = extents.value;
}

namespace fnv_00d552f0 {
extern "C" const __m128 DAT_010ec7f0;

extern "C" const char DAT_010d1074[];
extern "C" const char DAT_010c41f8[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static MonitorStream* GetMonitorStream()
    {
        return (MonitorStream*)TlsGetValue(::DAT_0126835c);
    }
};

static const char s_kEndTimer[] = "Et";
static __forceinline void TimerMark(const char* name, volatile unsigned int& t)
{
    MonitorStream* s = MonitorStream::GetMonitorStream();
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        CommandTimingEntry* h = (CommandTimingEntry*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct TimerScopeD55
{
    volatile unsigned int& m_t;
    __forceinline TimerScopeD55(const char* name, volatile unsigned int& t) : m_t(t)
    {
        TimerMark(name, m_t);
    }
    __forceinline ~TimerScopeD55()
    {
        TimerMark("Et", m_t);
    }
};

class HkBoolD55
{
  public:
    char m_cBooleanValue;
    HkBoolD55(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class Vec4D55
{
  public:
    __m128 m_vComponents;
    Vec4D55& operator=(const Vec4D55& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
    float dot4xyz1(const Vec4D55& p) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, p.m_vComponents);
        __m128 w = _mm_shuffle_ps(p.m_vComponents, p.m_vComponents, 0xff);
        __m128 z = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), w);
        __m128 y = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        float r;
        _mm_store_ss(&r, _mm_add_ps(z, y));
        return r;
    }
};

struct RayInputD55
{
    Vec4D55 m_vFrom;
    Vec4D55 m_vTo;
};

struct RayOutputD55
{
    Vec4D55 m_vHitNormal;
    float m_fromDist;
    int m_iExtraInfo;
    int pad[2];
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    void setKey(unsigned int key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};

static inline void Dot4xyz1(float* out, const Vec4D55& p, const Vec4D55& a)
{
    __m128 x2 = _mm_mul_ps(a.m_vComponents, p.m_vComponents);
    __m128 w = _mm_shuffle_ps(p.m_vComponents, p.m_vComponents, 0xff);
    __m128 z = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), w);
    __m128 y = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    _mm_store_ss(out, _mm_add_ps(z, y));
}

class PlaneShapeD55
{
  public:
    int pad[4];
    Vec4D55 m_kTriangleNormal;
    Vec4D55 m_kAabbCenter;
    Vec4D55 m_kAabbHalfExtents;
    HkBoolD55 FUN_00d552f0(const RayInputD55& input, RayOutputD55& results) const;
};

// @fnv 0x00d552f0
HkBoolD55 PlaneShapeD55::FUN_00d552f0(const RayInputD55& input, RayOutputD55& results) const
{
    union
    {
        volatile unsigned int t;
        float d;
    } u;
    TimerScopeD55 timer("TtrcPlane", u.t);
    float& fromDist = u.d;
    Dot4xyz1(&fromDist, m_kTriangleNormal, input.m_vFrom);
    float toDist;
    Dot4xyz1(&toDist, m_kTriangleNormal, input.m_vTo);
    if (fromDist >= 0.0f && toDist < 0.0f)
    {
        fromDist = fromDist / (fromDist - toDist);
        __m128 t = _mm_set_ps1(fromDist);
        __m128 s = _mm_sub_ps(DAT_010ec7f0, t);
        __m128 hit = _mm_add_ps(_mm_mul_ps(s, input.m_vFrom.m_vComponents), _mm_mul_ps(input.m_vTo.m_vComponents, t));
        __m128 diff = _mm_and_ps(_mm_sub_ps(hit, m_kAabbCenter.m_vComponents), DAT_01017d10);
        if ((_mm_movemask_ps(_mm_cmple_ps(diff, m_kAabbHalfExtents.m_vComponents)) & 7) == 7)
        {
            results.m_fromDist = fromDist;
            results.m_vHitNormal = m_kTriangleNormal;
            results.setKey(0xffffffff);
            return true;
        }
    }
    return false;
}
}  // namespace fnv_00d552f0

// Moved from hkpplaneshape_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).

struct SimdReal
{
    __m128 m_vValue;
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct VecCompare
{
    __m128 m_uiMask;
    bool allAreSetXYZ() const
    {
        return (_mm_movemask_ps(m_uiMask) & 7) == 7;
    }
};

struct Vec4
{
    __m128 m_vComponents;

    SimdReal dot4xyz1(const Vec4& x) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, x.m_vComponents);
        __m128 w = _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), w);
        SimdReal s;
        s.m_vValue = _mm_add_ps(r, _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2));
        return s;
    }
    void setInterpolate4(const Vec4& a, const Vec4& b, float t)
    {
        __m128 tt = _mm_set1_ps(t);
        m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, tt), a.m_vComponents), _mm_mul_ps(b.m_vComponents, tt));
    }
    void sub4(const Vec4& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    void setAbs4(const Vec4& a)
    {
        m_vComponents = _mm_and_ps(a.m_vComponents, ::DAT_01017d10);
    }
    VecCompare compareLessThanEqual4(const Vec4& a) const
    {
        VecCompare c;
        c.m_uiMask = _mm_cmple_ps(m_vComponents, a.m_vComponents);
        return c;
    }
};

struct __declspec(align(16)) AlignedVec4
{
    float x;
    float y;
    float z;
    float w;
};

struct RayInput
{
    Vec4 m_vFrom;
    Vec4 m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    float m_fSphereRadius;
    float m_fRayDistance;
};

struct RayOutput
{
    RayOutput()
    {
        m_uiShapeKeyIndex = 0;
        m_iExtraInfo = -1;
        m_shapeKey0 = -1;
    }
    AlignedVec4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    void* unk18;
    int unk1C;
    int m_shapeKey0;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int m_uiShapeKeyIndex;
    int unk44;
    int unk48;
    int unk4C;
};

struct CdBody;

struct RayCollector
{
    virtual void CollectRayHit(const CdBody& body, const RayOutput& out) = 0;
};

struct PlaneShapeStandIn
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Vec4 m_kTriangleNormal;
    Vec4 m_kAabbCenter;
    Vec4 m_kAabbHalfExtents;

    void FUN_00d55000(const RayInput& input, const CdBody& body, RayCollector& collector) const;
};

// @fnv 0x00d55000
void PlaneShapeStandIn::FUN_00d55000(const RayInput& input, const CdBody& body, RayCollector& collector) const
{
    float radius = input.m_fSphereRadius;
    float fromDist = m_kTriangleNormal.dot4xyz1(input.m_vFrom) - radius;
    float toDist = m_kTriangleNormal.dot4xyz1(input.m_vTo) - radius;
    if (!(toDist >= 0.0f))
    {
        if (!(fromDist - toDist < input.m_fRayDistance))
        {
            float frac = (fromDist <= 0.0f) ? 0.0f : fromDist / (fromDist - toDist);
            Vec4 hitPoint;
            hitPoint.setInterpolate4(input.m_vFrom, input.m_vTo, frac);
            hitPoint.sub4(m_kAabbCenter);
            hitPoint.setAbs4(hitPoint);
            if (hitPoint.compareLessThanEqual4(m_kAabbHalfExtents).allAreSetXYZ())
            {
                RayOutput out;
                _mm_store_ps(&out.m_vHitNormal.x, m_kTriangleNormal.m_vComponents);
                out.m_fHitFraction = frac;
                collector.CollectRayHit(body, out);
            }
        }
    }
}

struct FUN_00d55160_Source
{
    float* points;
    int count;
};
class FUN_00d55160_StandIn : public hkpPlaneShape
{
  public:
    void FUN_00d55160(FUN_00d55160_Source* source, float* destination);
};
// @fnv 0x00d55160
void FUN_00d55160_StandIn::FUN_00d55160(FUN_00d55160_Source* source, float* destination)
{
    float* output = destination;
    float* points = source->points;
    int count = source->count - 1;
    if (count < 0)
        return;
    do
    {
        __m128 plane = _mm_load_ps(&this->m_kTriangleNormal.x);
        _mm_store_ps(output, plane);
        __m128 planeForProduct = _mm_load_ps(&this->m_kTriangleNormal.x);
        __m128 point = _mm_load_ps(points);
        __m128 product = _mm_mul_ps(point, planeForProduct);
        __m128 planeW = _mm_shuffle_ps(planeForProduct, planeForProduct, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 sum = _mm_shuffle_ps(product, product, _MM_SHUFFLE(2, 2, 2, 2));
        sum = _mm_add_ss(sum, planeW);
        __m128 term = _mm_shuffle_ps(product, product, _MM_SHUFFLE(1, 1, 1, 1));
        term = _mm_add_ss(term, product);
        sum = _mm_add_ps(sum, term);
        float value;
        _mm_store_ss(&value, sum);
        output[3] = value - points[3];
        output += 4;
        points += 4;
        --count;
    } while (count >= 0);
}
