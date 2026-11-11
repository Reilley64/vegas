
// src/havok/physics/collide/shape/convex/box/hkpboxshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/box/hkpboxshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/FunctionContext.h"
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010c7000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkpBoxShape.h"
#include "fnv/decl/fnv_00c9e120__hkAabbUtilC9E1.h"
#include "fnv/symbols_simd.h"

// @fnv 0x00c9db70
int __cdecl FUN_00c9db70()
{
    return 8;
}

// Returns the smaller of the two float arguments.
// @fnv 0x00c9e0f0
float __cdecl FUN_00c9e0f0(float a, float b)
{
    return a < b ? a : b;
}


struct FUN_00c9db80_class
{
    void FUN_00c9db80();
};

// @fnv 0x00c9db80
void FUN_00c9db80_class::FUN_00c9db80()
{
    *reinterpret_cast<void**>(this) = &::DAT_0102e388;
}

struct MemoryManager
{
    virtual ~MemoryManager() {}
    virtual void unused() {}
    virtual void Free(void* object, unsigned short size) = 0;
};

struct MemoryRouter
{
    unsigned char unknown1[16];
    MemoryManager* manager;
};

struct FUN_00c9e1b0_class
{
    void* vftable;
    unsigned short size;

    void* FUN_00c9e1b0(unsigned char flags);
};

MemoryRouter* __cdecl _D1A0E0GetMemoryRouter();

// Calls FUN_00c9db80, then if bit 0 of flags is set frees this through the memory router's manager, and returns this.
// @fnv 0x00c9e1b0
void* FUN_00c9e1b0_class::FUN_00c9e1b0(unsigned char flags)
{
    reinterpret_cast<::FUN_00c9db80_class *>(this)->FUN_00c9db80();

    if (flags & 1)
    {
        MemoryRouter* router = _D1A0E0GetMemoryRouter();
        router->manager->Free(this, size);
    }

    return this;
}

// FUN_00c9e1a0: stub returning constant 0x30 (two unused stack params).
// @fnv 0x00c9e1a0
int FUN_00c9e1a0(int a1, int a2)
{
    return 0x30;
}



// @fnv 0x00c9db60
void __cdecl FUN_00c9db60(int a, int* b) {
    return reinterpret_cast<::FunctionContext *>((a))->FUN_00c90360(&(*reinterpret_cast<int *>(&::g_01268940)), {});
}

class hkAabb;

void __cdecl ComputeAabbFromTransform(const hkTransform& transform, const hkVector4& halfExtents, hkReal tolerance, hkAabb& out);

struct FUN_00c9dc10_class : public hkpBoxShape
{
    void GetAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const;
};

// Computes the shape's AABB by calling ComputeAabbFromTransform with the transform, the shape's half extents and tolerance added to a stored value.
// @fnv 0x00c9dc10
void FUN_00c9dc10_class::GetAabb(const hkTransform& transform, hkReal tolerance, hkAabb& out) const
{
    ComputeAabbFromTransform(transform, m_vHalfExtents, m_fSphereRadius + tolerance, out);
}


struct VectorExtents { float x, y, z, w; };

struct CenteredPointBounds {
    void* m_ppVirtualMethodTable;
    unsigned short m_usAllocationSize;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_iType;
    float m_fSphereRadius;
    float m_localCenterX;
    float m_localCenterY;
    float m_localCenterZ;
    VectorExtents m_vHalfExtents;

    CenteredPointBounds* SetExtentsAndRadius(const float* extents, float radius);
};

// @fnv 0x00c9ddb0
CenteredPointBounds* CenteredPointBounds::SetExtentsAndRadius(const float* extents, float radius)
{
    m_fSphereRadius = radius;
    m_sReferenceCount = 1;
    m_ulUserData = 0;
    m_iType = 4;
    m_ppVirtualMethodTable = &(*reinterpret_cast<void * *>(&::DAT_010c70b4));
    m_vHalfExtents = *reinterpret_cast<const VectorExtents*>(extents);

    float smaller = m_vHalfExtents.x < m_vHalfExtents.y ? m_vHalfExtents.x : m_vHalfExtents.y;
    m_vHalfExtents.w = smaller;
    m_vHalfExtents.w = m_vHalfExtents.z < m_vHalfExtents.w ? m_vHalfExtents.z : m_vHalfExtents.w;
    return this;
}


struct S00c9dc40_Box : public hkpBoxShape
{
    void FUN_00c9dc40(const float* src, float* dst);
};

// @fnv 0x00c9dc40
void S00c9dc40_Box::FUN_00c9dc40(const float* src, float* dst)
{
    hkVector4 e = m_vHalfExtents;
    __m128 v = _mm_and_ps(_mm_load_ps(src), DAT_010c44d0);
    v = _mm_xor_ps(v, _mm_load_ps(&e.x));
    _mm_store_ps(&e.x, v);
    int m = _mm_movemask_ps(_mm_cmplt_ps(v, _mm_setzero_ps()));
    *(unsigned*)&e.w = (m & 7) | 0x3F000000;
    _mm_store_ps(dst, _mm_load_ps(&e.x));
}

// @fnv 0x00c9dcb0
extern "C" void ZeroResult(__m128* result)
{
    *result = _mm_setzero_ps();
}

namespace fnv_00c9e120 {


extern const __m128 DAT_01017d10;
extern const __m128 DAT_010c44d0;

struct hkVector4C9E1 {
    __m128 m_vComponents;

    void setBroadcast(const hkVector4C9E1& v, int i);
    void setMul4(const hkVector4C9E1& a, const hkVector4C9E1& b) { m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents); }
    void setAbs4(const hkVector4C9E1& v) { m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10); }
    void setNeg4(const hkVector4C9E1& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0); }
    void setAdd4(const hkVector4C9E1& a, const hkVector4C9E1& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    void add4(const hkVector4C9E1& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
    hkVector4C9E1() {}
    hkVector4C9E1(const hkVector4C9E1& v) { m_vComponents = v.m_vComponents; }
    void operator=(const hkVector4C9E1& v) { m_vComponents = v.m_vComponents; }
    void SetAllComponents(float f) { m_vComponents = _mm_set_ps1(f); }
};

struct hkTransformC9E1 {
    hkVector4C9E1 m_kColumn0;
    hkVector4C9E1 m_kColumn1;
    hkVector4C9E1 m_kColumn2;
    hkVector4C9E1 m_vTranslation;
};

struct hkAabbC9E1 {
    hkVector4C9E1 m_kMinimumCorner;
    hkVector4C9E1 m_kMaximumCorner;
};

// Computes an AABB in world space from a transform, a point, and an extra radius, storing the result in kAabbOut.
// @fnv 0x00c9e120
void hkAabbUtilC9E1::ComputeAabbFromTransform(const hkTransformC9E1& kLocalToWorld, const hkVector4C9E1& m_kPoint2, float fExtraRadius, hkAabbC9E1& kAabbOut)
{
    hkVector4C9E1 kX;
    kX.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(m_kPoint2.m_vComponents, m_kPoint2.m_vComponents, 0x00), kLocalToWorld.m_kColumn0.m_vComponents);
    hkVector4C9E1 kY;
    kY.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(m_kPoint2.m_vComponents, m_kPoint2.m_vComponents, 0x55), kLocalToWorld.m_kColumn1.m_vComponents);
    hkVector4C9E1 kZ;
    kZ.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(m_kPoint2.m_vComponents, m_kPoint2.m_vComponents, 0xaa), kLocalToWorld.m_kColumn2.m_vComponents);
    kX.setAbs4(kX);
    kY.setAbs4(kY);
    kZ.setAbs4(kZ);
    hkVector4C9E1 kExtra;
    kExtra.SetAllComponents(fExtraRadius);
    hkVector4C9E1 kExtent;
    kExtent.setAdd4(kX, kY);
    kZ.add4(kExtra);
    kExtent.add4(kZ);
    hkVector4C9E1 kNeg;
    kNeg.setNeg4(kExtent);
    hkVector4C9E1 kMinPoint;
    kMinPoint.setAdd4(kNeg, kLocalToWorld.m_vTranslation);
    hkVector4C9E1 kMaxPoint;
    kMaxPoint.setAdd4(kLocalToWorld.m_vTranslation, kExtent);
    kAabbOut.m_kMaximumCorner = kMaxPoint;
    kAabbOut.m_kMinimumCorner = kMinPoint;
}
}  // namespace fnv_00c9e120

struct hkpBoxShape_Local : public hkpBoxShape
{
    void SetHalfExtents(const hkVector4& halfExtents);
};

// Copies halfExtents into m_vHalfExtents and stores the minimum of x, y, and z into the w component.
// @fnv 0x00c9db90
void hkpBoxShape_Local::SetHalfExtents(const hkVector4& halfExtents)
{
    *(__m128*)&m_vHalfExtents = *(__m128*)&halfExtents;
    m_vHalfExtents.w = (m_vHalfExtents.x < m_vHalfExtents.y) ? m_vHalfExtents.x : m_vHalfExtents.y;
    m_vHalfExtents.w = (m_vHalfExtents.w > m_vHalfExtents.z) ? m_vHalfExtents.z : m_vHalfExtents.w;
}

struct FUN_00c9dbf0_class
{
    unsigned char m_ucUnknownByte[0x20];
    hkVector4 m_vHalfExtents;

    void GetHalfExtents(hkVector4& result) const;
};

// @fnv 0x00c9dbf0
void FUN_00c9dbf0_class::GetHalfExtents(hkVector4& result) const
{
    _mm_store_ps(reinterpret_cast<float*>(&result),
                 _mm_load_ps(reinterpret_cast<const float*>(&m_vHalfExtents)));
}


extern "C" const __m128 DAT_010c7030[8];

struct BoxShapeHelper : public hkpBoxShape
{
    void* FUN_00c9dd30(__m128* sphereBuffer) const;
};

// Multiplies the half-extents and sphere radius by DAT_010c7030 coefficients and writes the results into sphereBuffer.
// @fnv 0x00c9dd30
void* BoxShapeHelper::FUN_00c9dd30(__m128* sphereBuffer) const
{
    __declspec(align(16)) hkVector4 extents = m_vHalfExtents;
    extents.w = m_fSphereRadius;

    __m128 v = *(__m128*)&extents;
    int i = 3;
    const __m128* src = DAT_010c7030 + 1;
    __m128* dst = sphereBuffer + 1;
    for (; i >= 0; i--) {
        __m128 b = _mm_mul_ps(src[0], v);
        __m128 a = _mm_mul_ps(src[-1], v);
        dst[-1] = a;
        dst[0] = b;
        src += 2; dst += 2;
    }

    return sphereBuffer;
}



struct BRMonitorStream
{
    struct CommandTimingEntry
    {
        const char* m_pCommandName;
        hkUint32 m_uiStartTicks;
        hkUint32 m_uiEndTicks;

        void setTime()
        {
            _ReadWriteBarrier();
            hkUint32 ticks;
            ticks = static_cast<unsigned int>(__rdtsc());
            m_uiStartTicks = ticks;
        }
    };

    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;


    static BRMonitorStream& GetMonitorStream() { return *(BRMonitorStream*)TlsGetValue(::DAT_0126835c); }
    bool memoryAvailable() const { return m_kRayEnd < m_pCurrentCommand; }


    void timerCommandEarly(const char* name) {
        if (memoryAvailable()) {
            CommandTimingEntry* h=(CommandTimingEntry*)m_kRayEnd;
            h->m_pCommandName=name;
            _ReadWriteBarrier();
            hkUint32 ticks;
            ticks = static_cast<unsigned int>(__rdtsc());
            _ReadWriteBarrier();
            h->m_uiStartTicks=ticks;
            m_kRayEnd=(char*)(h+1);
        }
    }

    void timerCommand(const char* name)
    {
        if (memoryAvailable())
        {
            CommandTimingEntry* h = (CommandTimingEntry*)m_kRayEnd;
            h->m_pCommandName = name;
            h->setTime();
            m_kRayEnd = (char*)(h + 1);
        }
    }
};

extern const __m128 g_brSignMask;

struct BRVector4
{
    __m128 m_vComponents;

    void operator=(const BRVector4& v) { m_vComponents = v.m_vComponents; }
    hkReal& operator()(int i) { return reinterpret_cast<float*>(&m_vComponents)[i]; }
    const hkReal& operator()(int i) const { return reinterpret_cast<const float*>(&m_vComponents)[i]; }
    void SetAllComponents(hkReal r) { m_vComponents = _mm_set_ps1(r); }
    void setAdd4(const BRVector4& a, const BRVector4& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    void setNeg4(const BRVector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, g_brSignMask); }
    void setZero4() { m_vComponents = _mm_setzero_ps(); }
    int compareLessThanEqual4(const BRVector4& v) const { return _mm_movemask_ps(_mm_cmple_ps(m_vComponents, v.m_vComponents)); }
};

struct BRBool
{
    char m_cBooleanValue;

    BRBool(bool b) : m_cBooleanValue(b) {}
};

struct BRRayCastInput
{
    BRVector4 m_vFrom;
    BRVector4 m_vTo;
};

struct BRRayCastOutput
{
    BRVector4 m_vHitNormal;
    hkReal m_fHitFraction;
    hkInt32 m_iExtraInfo;
    int unk18; int unk1c;
    hkUint32 m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;

    void setKey(hkUint32 key) { m_uiShapeKeys[m_uiShapeKeyIndex] = key; }
};

struct RayBoxShape : hkpBoxShape
{
    BRBool FUN_00c9de40(const BRRayCastInput& input, BRRayCastOutput& results) const;
};

// @fnv 0x00c9de40
BRBool RayBoxShape::FUN_00c9de40(const BRRayCastInput& input, BRRayCastOutput& results) const
{
    BRMonitorStream::GetMonitorStream().timerCommand("TtrcBox");

    BRVector4 tolerance4;
    tolerance4.SetAllComponents(m_fSphereRadius);
    BRVector4 halfExtents;
    halfExtents.setAdd4(tolerance4, *(const BRVector4*)&m_vHalfExtents);
    BRVector4 negHalfExtents;
    negHalfExtents.setNeg4(halfExtents);

    int fromOutsidePos = halfExtents.compareLessThanEqual4(input.m_vFrom) & 7;
    int fromOutsideNeg = input.m_vFrom.compareLessThanEqual4(negHalfExtents) & 7;
    int toOutsidePos = halfExtents.compareLessThanEqual4(input.m_vTo) & 7;
    int toOutsideNeg = input.m_vTo.compareLessThanEqual4(negHalfExtents) & 7;

    if ((fromOutsidePos & toOutsidePos) || (fromOutsideNeg & toOutsideNeg) || !(fromOutsideNeg | fromOutsidePos))
    {
        BRMonitorStream::GetMonitorStream().timerCommandEarly("Et");
        return false;
    }

    hkReal tEnter = 0.0f;
    BRVector4 normal;

    const int axisMasks[3] = { 1, 2, 4 };
    int checkMask = fromOutsidePos | toOutsidePos;
    int enterMask = fromOutsidePos;
    hkReal tExit = results.m_fHitFraction;
    hkReal sign = 1.0f;

    for (int side = 1; side >= 0; side--)
    {
        int i = 0;
        const float* component = &input.m_vFrom(2);
        do
        {
            if (checkMask & axisMasks[i + 2])
            {
                hkReal ext = negHalfExtents(i + 2);
                hkReal fromDist = component[0] * sign + ext;
                hkReal toDist = component[4] * sign + ext;
                hkReal t = fromDist / (fromDist - toDist);
                if (enterMask & axisMasks[i + 2])
                {
                    if (t >= tEnter)
                    {
                        tEnter = t;
                        normal.setZero4();
                        normal(i + 2) = sign;
                    }
                }
                else
                {
                    if (!(t > tExit))
                    {
                        tExit = t;
                    }
                }
                if (tExit < tEnter)
                {
                    BRMonitorStream::GetMonitorStream().timerCommand("Et");
                    return false;
                }
            }
        } while (--component, --i >= -2);
        checkMask = toOutsideNeg | fromOutsideNeg;
        enterMask = fromOutsideNeg;
        sign = -1.0f;
    }

    results.m_fHitFraction = tEnter;
    results.m_vHitNormal = normal;
    results.setKey(0xffffffff);

    BRMonitorStream::GetMonitorStream().timerCommand("Et");
    return true;
}

// Moved from hkpboxshape_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/symbols_00c85000.h"
int __cdecl FUN_00c9db70();
float __cdecl FUN_00c9e0f0(float a, float b);
int FUN_00c9e1a0(int a1, int a2);
void __cdecl FUN_00c9db60(int a, int* b);


extern "C" const __m128 DAT_010c7030[];

struct FUN_00c9dcd0_vertex
{
    union
    {
        __m128 quad;
        struct
        {
            float x;
            float y;
            float z;
            unsigned int id;
        };
    };
};

struct FUN_00c9dcd0_object
{
    unsigned char unknown00[0x20];
    __m128 halfExtents;

    void FUN_00c9dcd0(const unsigned short* ids, int count, FUN_00c9dcd0_vertex* output);
};

// @fnv 0x00c9dcd0
void FUN_00c9dcd0_object::FUN_00c9dcd0(const unsigned short* ids, int count, FUN_00c9dcd0_vertex* output)
{
    for (int i = count - 1; i >= 0; --i)
    {
        unsigned int id = *ids;
        __m128 value = _mm_mul_ps(DAT_010c7030[id], halfExtents);

        output->quad = value;
        output->id = id | 0x3f000000u;

        ++output;
        ++ids;
    }
}
#include "generated/data/havok/physics/collide/shape/convex/box/hkpboxshape.inc"
