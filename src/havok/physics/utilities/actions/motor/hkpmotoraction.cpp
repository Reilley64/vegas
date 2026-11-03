
// src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/motor/hkpmotoraction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_00d2b260.h"
#include "havok/hkpMotorAction.h"

#include <xmmintrin.h>
extern int DAT_010d0944;

struct FUN_00d2b260_Obj
{
};

struct hkVec4
{
    __m128 quad;
    __forceinline void normalize3();
};

__forceinline void hkVec4::normalize3()
{
    __m128 v = quad;
    __m128 sq = _mm_mul_ps(v, v);
    __m128 t = _mm_add_ps(_mm_shuffle_ps(sq, sq, 0x4e), sq);
    __m128 d = _mm_add_ps(_mm_shuffle_ps(t, t, 0xb1), t);

    __m128 rs = _mm_rsqrt_ss(d);
    __m128 mask = _mm_cmpeq_ss(d, _mm_set_ss(0.0f));
    __m128 dr = _mm_mul_ss(_mm_mul_ss(d, rs), rs);
    __m128 inv = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), rs), _mm_sub_ss(_mm_set_ss(3.0f), dr));
    __m128 sel = _mm_andnot_ps(mask, inv);
    quad = _mm_mul_ps(_mm_shuffle_ps(sel, sel, 0), v);
}

struct FUN_00d4d720
{
    int* m_vtbl;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_pEntity;
    int unk1c;
    hkVec4 m_kAxisEndPoints;
    volatile float m_fSpinRate;
    volatile float m_fGain;
    volatile unsigned char m_bSlotEnabled;

    FUN_00d4d720(int entity, const float* axis, float spinRate, float gain);
};

// Calls FUN_00d2b260(entity, 0), sets the vtable, loads and normalizes axis, stores spinRate and gain, and sets m_bSlotEnabled to 1.
// @fnv 0x00d4d720
FUN_00d4d720::FUN_00d4d720(int entity, const float* axis, float spinRate, float gain)
{
    new ((void *)(reinterpret_cast<FUN_00d2b260_Obj*>(this))) ::FUN_00d2b260((::FUN_00c90510_Entity *)(entity), 0);
    m_vtbl = &DAT_010d0944;
    m_kAxisEndPoints.quad = _mm_load_ps(axis);
    m_fSpinRate = spinRate;
    m_fGain = gain;
    m_bSlotEnabled = 1;
    m_kAxisEndPoints.normalize3();
}

// Moved from hkpmotoraction_ehsc_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/utilities/actions/motor/hkpmotoraction_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/motor/hkpmotoraction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>

class hkpRigidBody;
class hkpPhantom;

struct hkMemoryAllocatorMA
{
    virtual ~hkMemoryAllocatorMA();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct hkMemoryRouterMA
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorMA* m_pStreamAllocator;
    hkMemoryAllocatorMA& heap()
    {
        return *m_pStreamAllocator;
    }
};

hkMemoryRouterMA& __cdecl FUN_00c85750();

template <class T> struct hkArrayMA
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

class hkpMotorActionMA : public hkpMotorAction
{
  public:
    void* operator new(size_t nbytes)
    {
        hkReferencedObject* b =
            static_cast<hkReferencedObject*>(FUN_00c85750().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        return b;
    }
    void operator delete(void*, unsigned int);

    hkpMotorActionMA(hkpRigidBody* body, const hkVector4& axis, hkReal spinRate, hkReal gain);

    hkpAction* FUN_00d4d7f0(const hkArrayMA<hkpEntity*>& newEntities, const hkArrayMA<hkpPhantom*>& newPhantoms) const;
};

// @fnv 0x00d4d7f0
hkpAction* hkpMotorActionMA::FUN_00d4d7f0(const hkArrayMA<hkpEntity*>& newEntities,
                                          const hkArrayMA<hkpPhantom*>& newPhantoms) const
{
    if (newEntities.GetLogicalSize() != 1)
        return 0;

    if (newPhantoms.GetLogicalSize() != 0)
        return 0;

    hkpMotorActionMA* ma = new hkpMotorActionMA((hkpRigidBody*)newEntities[0], m_kAxisEndPoints, m_fSpinRate, m_fGain);
    ma->m_bSlotEnabled = m_bSlotEnabled;
    ma->m_ulUserData = m_ulUserData;

    return ma;
}

// Moved from hkpmotoraction_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).

// src/havok/physics/utilities/actions/motor/hkpmotoraction_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/actions/motor/hkpmotoraction_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/utilities/actions/motor/hkpmotoraction_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/actions/motor/hkpmotoraction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/actions/motor/hkpmotoraction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_004b4ab0_Class.h"
#include "fnv/decl/FUN_00c7f750_shell.h"
#include "fnv/decl/hkpEntityC9C.h"

struct SimdReal
{
    __m128 m_vValue;
    SimdReal(const __m128& x) : m_vValue(x)
    {}
    SimdReal(float f)
    {
        m_vValue = _mm_load_ss(&f);
    }
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};
struct Vec4
{
    __m128 m_vComponents;
    SimdReal dot3(const Vec4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 res = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xAA), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        return res;
    }
    void setMul4(const SimdReal& r, const Vec4& a)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), a.m_vComponents);
    }
        // FUN_00c7f750
    void FUN_00c7f700(const void* rot, const Vec4& v);  // FUN_00c7f700
};

struct __declspec(align(16)) Mat3
{
    Vec4 c0, c1, c2;
};

struct TimeInterval
{
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
};

struct Motion
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void GetInertiaLocal(Mat3& m) const;
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void StepMotion(float dt, const Vec4& t);
    int unk04;
    int unk08;
    int unk0C;
    hkMatrix3 m_rotation;  // +0xf0 in body
};

struct RigidBody
{
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    Motion m_pMotionState;
      // FUN_00c9c1d0

    inline void StepMotion(float dt, const Vec4& t)
    {
        reinterpret_cast<::hkpEntityC9C *>(this)->FUN_00c9c1d0();
        m_pMotionState.StepMotion(dt, t);
    }
};

struct MotorAction : hkpMotorAction
{
    void FUN_00d4d860(const TimeInterval& stepInfo);
};

// @fnv 0x00d4d860
void MotorAction::FUN_00d4d860(const TimeInterval& stepInfo)
{
    if (!m_bSlotEnabled)
        return;
    RigidBody* rb = reinterpret_cast<RigidBody*>(m_pEntity);

    Vec4 currentAngVel;
    reinterpret_cast<::FUN_004b4ab0_Class *>(&(currentAngVel))->FUN_004b4ab0((int)(&rb->m_pMotionState.m_rotation), (int)(reinterpret_cast<char*>(rb) + 0x1c0));

    const Vec4& axis = reinterpret_cast<const Vec4&>(m_kAxisEndPoints);
    float currentRate = currentAngVel.dot3(axis);
    float deltaRate = m_fSpinRate - currentRate;
    Vec4 angularDelta;
    angularDelta.setMul4(deltaRate * m_fGain, axis);

    Mat3 worldInertia;
    rb->m_pMotionState.GetInertiaLocal(worldInertia);

    reinterpret_cast<::FUN_00c7f750_shell *>(&(angularDelta))->FUN_00c7f750((float *)(&worldInertia), (float *)&(angularDelta));
    angularDelta.FUN_00c7f700(&rb->m_pMotionState.m_rotation, angularDelta);

    rb->StepMotion(stepInfo.m_fTimeStep, angularDelta);
}
