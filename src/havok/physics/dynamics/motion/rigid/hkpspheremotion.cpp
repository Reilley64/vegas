
// src/havok/physics/dynamics/motion/rigid/hkpspheremotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpspheremotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010c9000.h"
#include "havok/hkpSphereMotion.h"

struct hkVector4D12
{
    float x, y, z, w;
};

struct hkMatrix3D12
{
    hkVector4D12 m_kColumn0;
    hkVector4D12 m_kColumn1;
    hkVector4D12 m_kColumn2;
};

template <class T> inline T hkMax2D12(T x, T y)
{
    return x > y ? x : y;
}

class hkpSphereMotionD12
{
  public:
    virtual ~hkpSphereMotionD12();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D12 m_kMotionState[11];
    hkVector4D12 m_kInertiaAndMassInv;

    void FUN_00d1e290(const hkMatrix3D12& inertia);
};

// Stores the reciprocal of the largest diagonal inertia component into m_kInertiaAndMassInv for the sphere motion.
// @fnv 0x00d1e290
void hkpSphereMotionD12::FUN_00d1e290(const hkMatrix3D12& inertia)
{
    float a = hkMax2D12(hkMax2D12(inertia.m_kColumn0.x, inertia.m_kColumn1.y), inertia.m_kColumn2.z);
    float fInvMaxDiag;
    if (a > 0.0f)
        fInvMaxDiag = 1.0f / a;
    else
        fInvMaxDiag = 0.0f;
    m_kInertiaAndMassInv.x = fInvMaxDiag;
    m_kInertiaAndMassInv.y = fInvMaxDiag;
    m_kInertiaAndMassInv.z = fInvMaxDiag;
}

class hkpSphereMotion_L : public hkpMotion
{
  public:
    void SetInertiaAndMassInv(const float* param_2);
};

// Computes the minimum of param_2[0], param_2[5] and param_2[10] and stores it in m_kInertiaAndMassInv x, y and z.
// @fnv 0x00d1e320
void hkpSphereMotion_L::SetInertiaAndMassInv(const float* param_2)
{
    float v0 = param_2[0];
    float v5 = param_2[5];

    float minVal;
    if (v0 < v5)
    {
        minVal = v0;
    }
    else
    {
        minVal = v5;
    }

    float v10 = param_2[10];

    float result;
    if (minVal < v10)
    {
        result = minVal;
    }
    else
    {
        result = v10;
    }

    this->m_kInertiaAndMassInv.x = result;
    this->m_kInertiaAndMassInv.y = result;
    this->m_kInertiaAndMassInv.z = result;
}



struct hkVector4D1E41
{
    __m128 m_vComponents;

    __m128 getSimdAt3() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    void setMul4(const __m128& s, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents);
    }
    void setMul4(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setSub4(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1E41& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void setCross(const hkVector4D1E41& a, const hkVector4D1E41& b)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};

class hkBaseObjectD1E41
{
  public:
    virtual ~hkBaseObjectD1E41() throw();
};

class hkReferencedObjectD1E41 : public hkBaseObjectD1E41
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpSphereMotionD1E41 : public hkReferencedObjectD1E41
{
  public:
    void ApplyImpulse(const hkVector4D1E41& kImpulse, const hkVector4D1E41& kPos);

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E41 m_motionState0[5];
    hkVector4D1E41 m_kCenterOfMass1;
    hkVector4D1E41 m_motionState1[5];
    hkVector4D1E41 m_kInertiaAndMassInv;
    hkVector4D1E41 m_kTranslationalVelocity;
    hkVector4D1E41 m_kAngularVelocity;
};

// Adds impulse times inverse mass to translational velocity and (pos - center of mass) cross impulse times inverse inertia to angular velocity.
// @fnv 0x00d1e410
void hkpSphereMotionD1E41::ApplyImpulse(const hkVector4D1E41& kImpulse, const hkVector4D1E41& kPos)
{
    hkVector4D1E41 kDeltaLin;
    kDeltaLin.setMul4(m_kInertiaAndMassInv.getSimdAt3(), kImpulse);
    m_kTranslationalVelocity.add4(kDeltaLin);

    hkVector4D1E41 kRelPos;
    kRelPos.setSub4(kPos, m_kCenterOfMass1);
    hkVector4D1E41 kAngImpulse;
    kAngImpulse.setCross(kRelPos, kImpulse);
    hkVector4D1E41 kDeltaAng;
    kDeltaAng.setMul4(kAngImpulse, m_kInertiaAndMassInv);
    m_kAngularVelocity.add4(kDeltaAng);
}

class hkVector4D1E4
{
  public:
    __m128 m_vComponents;
    void setMul4(const hkVector4D1E4& a, const hkVector4D1E4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1E4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

class hkpSphereMotionD1E4
{
  public:
    virtual ~hkpSphereMotionD1E4();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_deactivationNumInactiveFrames0;
    unsigned short m_deactivationNumInactiveFrames1;
    unsigned short m_pad0e;
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
    hkVector4D1E4 m_kInertiaAndMassInv;
    hkVector4D1E4 m_kTranslationalVelocity;
    hkVector4D1E4 m_kAngularVelocity;
    const hkVector4D1E4& AddAngularImpulse(const hkVector4D1E4& imp);
};

// Multiplies m_kInertiaAndMassInv by imp into a temporary, adds it to m_kAngularVelocity, and returns imp.
// @fnv 0x00d1e4a0
const hkVector4D1E4& hkpSphereMotionD1E4::AddAngularImpulse(const hkVector4D1E4& imp)
{
    hkVector4D1E4 dangVel;
    dangVel.setMul4(m_kInertiaAndMassInv, imp);
    m_kAngularVelocity.add4(dangVel);
    return imp;
}

namespace fnv_00d1e5a0 {


struct hkSimdRealD1E5A
{
    __m128 m_vValue;

    hkSimdRealD1E5A(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    hkSimdRealD1E5A operator+(const hkSimdRealD1E5A& r) const
    {
        return _mm_add_ss(m_vValue, r.m_vValue);
    }
};

struct hkVector4D1E5A
{
    __m128 m_vComponents;

    void setSub4(const hkVector4D1E5A& a, const hkVector4D1E5A& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const hkVector4D1E5A& a, const hkVector4D1E5A& b)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2),
                                         _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    hkSimdRealD1E5A dot3(const hkVector4D1E5A& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    hkSimdRealD1E5A lengthSquared3() const
    {
        return dot3(*this);
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

class hkBaseObjectD1E5A
{
  public:
    virtual ~hkBaseObjectD1E5A() throw();
};

class hkReferencedObjectD1E5A : public hkBaseObjectD1E5A
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpSphereMotionD1E5A : public hkReferencedObjectD1E5A
{
  public:
    void ComputeVelocityAndInverseVirtualMass(const hkVector4D1E5A& kPos, const hkVector4D1E5A& kNormal, float& fVelOut,
                                              float& fInvVirtMassOut) const;

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E5A m_motionState0[5];
    hkVector4D1E5A m_kCenterOfMass1;
    hkVector4D1E5A m_motionState1[5];
    hkVector4D1E5A m_kInertiaAndMassInv;
    hkVector4D1E5A m_kTranslationalVelocity;
    hkVector4D1E5A m_kAngularVelocity;
};

// Computes velocity along kNormal at kPos from angular and translational velocity, and an inverse virtual mass from the inertia, mass inverse and cross term.
// @fnv 0x00d1e5a0
void hkpSphereMotionD1E5A::ComputeVelocityAndInverseVirtualMass(const hkVector4D1E5A& kPos,
                                                                const hkVector4D1E5A& kNormal, float& fVelOut,
                                                                float& fInvVirtMassOut) const
{
    hkVector4D1E5A kArm;
    kArm.setSub4(kPos, m_kCenterOfMass1);
    hkVector4D1E5A kRel;
    kRel.setCross(kNormal, kArm);
    fVelOut = m_kAngularVelocity.dot3(kRel) + m_kTranslationalVelocity.dot3(kNormal);
    fInvVirtMassOut = m_kInertiaAndMassInv(0) * kRel.lengthSquared3() + m_kInertiaAndMassInv(3);
}
}  // namespace fnv_00d1e5a0



struct FUN_00d1e1d0_cls : hkpSphereMotion
{
    void FUN_00d1e1d0(hkMatrix3* out);
};

// Reads m_kInertiaAndMassInv.x (replaced by DAT_0104da4c if below DAT_010c9300) and writes a matrix at out with its reciprocal on the diagonal, zeros elsewhere.
// @fnv 0x00d1e1d0
void FUN_00d1e1d0_cls::FUN_00d1e1d0(hkMatrix3* out)
{
    hkReal x = m_kInertiaAndMassInv.x;
    hkReal y = (double)x < DAT_010c9300 ? ::DAT_0104da4c : x;
    hkMatrix3* p0 = out;
    float* p = reinterpret_cast<float*>(p0);
    hkReal inv = 1.0f / y;
    _mm_store_ps(p, _mm_setzero_ps());
    _mm_store_ps(p + 4, _mm_setzero_ps());
    _mm_store_ps(p + 8, _mm_setzero_ps());
    p[0] = inv;
    p[5] = inv;
    p[10] = inv;
}


class SphereInverseWorld : public hkpSphereMotion
{
  public:
    void FUN_00d1e3d0(hkMatrix3* out) const;
};

// Writes a diagonal hkMatrix3 with m_kInertiaAndMassInv.x on the diagonal and zeros elsewhere into out.
// @fnv 0x00d1e3d0
void SphereInverseWorld::FUN_00d1e3d0(hkMatrix3* out) const
{
    float inverse = m_kInertiaAndMassInv.x;
    __m128 zero = _mm_setzero_ps();
    __m128* columns = reinterpret_cast<__m128*>(out);
    columns[0] = zero;
    columns[1] = zero;
    columns[2] = zero;
    volatile hkMatrix3* diagonal = out;
    diagonal->m_kColumn0.x = inverse;
    diagonal->m_kColumn1.y = inverse;
    diagonal->m_kColumn2.z = inverse;
}


struct TestMotion : public hkpSphereMotion
{
    void FUN_00d1e390(hkMatrix3& inertiaInvOut);
};

// Zeroes the 3x3 matrix and sets its diagonal entries to the scalar m_kInertiaAndMassInv.x value.
// @fnv 0x00d1e390
void TestMotion::FUN_00d1e390(hkMatrix3& inertiaInvOut)
{
    hkReal val = m_kInertiaAndMassInv.x;
    __m128 zero = _mm_setzero_ps();
    __m128* col = (__m128*)&inertiaInvOut;
    for (int i = 0; i < 3; ++i)
    {
        col[i] = zero;
    }
    inertiaInvOut.m_kColumn0.x = val;
    inertiaInvOut.m_kColumn1.y = val;
    inertiaInvOut.m_kColumn2.z = val;
}

// Moved from hkpspheremotion_gs_nogs_variant.cpp (VEGAS-15).

struct C
{
    char pad[0xc0];
    float m_vScale;
    void FUN_00d1e230(float* out);
};
// @fnv 0x00d1e230
void C::FUN_00d1e230(float* out)
{
    float t = m_vScale;
    float s;
    if (::DAT_010c9300 > t)
        s = ::DAT_0104da4c;
    else
        s = t;
    float inv = 1.0f / s;
    __m128 zero = _mm_setzero_ps();
    _mm_store_ps(out, zero);
    _mm_store_ps(out + 4, zero);
    _mm_store_ps(out + 8, zero);
    out[0] = inv;
    out[5] = inv;
    out[10] = inv;
}

// Moved from hkpspheremotion_rtm_variant.cpp (VEGAS-15).


struct hkSimdRealD1E5
{
    __m128 m_vValue;

    hkSimdRealD1E5(const float& f) : m_vValue(_mm_shuffle_ps(_mm_load_ss(&f), _mm_load_ss(&f), 0))
    {}
};

struct hkVector4D1E5
{
    __m128 m_vComponents;

    void setMul4(const hkSimdRealD1E5& s, const hkVector4D1E5& b)
    {
        m_vComponents = _mm_mul_ps(s.m_vValue, b.m_vComponents);
    }
};

class hkpMotionD1E5
{
  public:
    virtual ~hkpMotionD1E5() throw();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void SetCollisionShape(const hkVector4D1E5& kImpulse);

    void FUN_00d1e560(float fMoveElapsedTime, const hkVector4D1E5& kForce);
};

// @fnv 0x00d1e560
void hkpMotionD1E5::FUN_00d1e560(float fMoveElapsedTime, const hkVector4D1E5& kForce)
{
    hkVector4D1E5 kImpulse;
    kImpulse.setMul4(fMoveElapsedTime, kForce);
    SetCollisionShape(kImpulse);
}

// Moved from hkpspheremotion_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).

struct ScalarE4
{
    __m128 value;
    ScalarE4(float f) : value(_mm_load_ss(&f))
    {}
    ScalarE4(const __m128& v) : value(v)
    {}
    __m128 splat() const
    {
        return _mm_shuffle_ps(value, value, 0);
    }
};
struct VectorE4
{
    __m128 value;
    void scale(const ScalarE4& s, const VectorE4& v)
    {
        value = _mm_mul_ps(s.splat(), v.value);
    }
    void add(const VectorE4& v)
    {
        value = _mm_add_ps(value, v.value);
    }
};
struct SphereE4 : hkpSphereMotion
{
    void FUN_00d1e4d0(float dt, const VectorE4& force);
    void impulse(const VectorE4& v)
    {
        VectorE4 change;
        __m128 mass = _mm_load_ps(&m_kInertiaAndMassInv.x);
        change.scale(ScalarE4(_mm_shuffle_ps(mass, mass, 255)), v);
        ((VectorE4&)m_kTranslationalVelocity).add(change);
    }
};
// @fnv 0x00d1e4d0
void SphereE4::FUN_00d1e4d0(float dt, const VectorE4& force)
{
    VectorE4 v;
    ScalarE4 time(dt);
    _ReadWriteBarrier();
    v.scale(time, force);
    _ReadWriteBarrier();
    impulse(v);
}


struct FUN_00d1e520_cls
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void Dispatch(const __m128& t, int b);
    void FUN_00d1e520(float f, const __m128* a, int b);
};

// @fnv 0x00d1e520
void FUN_00d1e520_cls::FUN_00d1e520(float f, const __m128* a, int b)
{
    __m128 s = _mm_load_ss(&f);
    __m128 bc = _mm_shuffle_ps(s, s, 0);
    __m128 t = _mm_mul_ps(bc, *a);
    Dispatch(t, b);
}
