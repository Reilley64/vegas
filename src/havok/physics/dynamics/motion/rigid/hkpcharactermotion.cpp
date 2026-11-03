
// src/havok/physics/dynamics/motion/rigid/hkpcharactermotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpcharactermotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "havok/hkpCharacterMotion.h"

struct hkVector4D1E
{
    float x, y, z, w;
};

struct hkMatrix3D1E
{
    hkVector4D1E m_kColumn0;
    hkVector4D1E m_kColumn1;
    hkVector4D1E m_kColumn2;
};

template <class T> inline T hkMax2D1E(T x, T y)
{
    return x > y ? x : y;
}

class hkpCharacterMotionD1E
{
  public:
    virtual ~hkpCharacterMotionD1E();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E m_kMotionState[11];
    hkVector4D1E m_kInertiaAndMassInv;

    void SetInertiaAndMassInv(const hkMatrix3D1E& inertia);
};

// Computes the reciprocal of the largest diagonal element of the inertia matrix and stores it in all three components of m_kInertiaAndMassInv.
// @fnv 0x00d1ed40
void hkpCharacterMotionD1E::SetInertiaAndMassInv(const hkMatrix3D1E& inertia)
{
    float a = hkMax2D1E(hkMax2D1E(inertia.m_kColumn0.x, inertia.m_kColumn1.y), inertia.m_kColumn2.z);
    float fInvMaxDiag;
    if (a > 0.0f)
        fInvMaxDiag = 1.0f / a;
    else
        fInvMaxDiag = 0.0f;
    m_kInertiaAndMassInv.x = fInvMaxDiag;
    m_kInertiaAndMassInv.y = fInvMaxDiag;
    m_kInertiaAndMassInv.z = fInvMaxDiag;
}

struct FUN_00d1edd0_stub
{
    void SetMinOfThree(const float* src);
};

// Stores the minimum of src[0], src[5], and src[10] into the three floats at offsets 0xc0, 0xc4, and 0xc8 of this.
// @fnv 0x00d1edd0
void FUN_00d1edd0_stub::SetMinOfThree(const float* src)
{
    float a = src[0];
    float b = src[5];
    float c = a < b ? a : b;
    float fThird = src[10];
    float fMinAll = c < fThird ? c : fThird;
    *(float*)((char*)this + 0xc0) = fMinAll;
    *(float*)((char*)this + 0xc4) = fMinAll;
    *(float*)((char*)this + 0xc8) = fMinAll;
}



struct hkVector4D1EE
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

struct hkMatrix3D1EE
{
    hkVector4D1EE m_kColumn0;
    hkVector4D1EE m_kColumn1;
    hkVector4D1EE m_kColumn2;

    float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    void setDiagonal(float m00, float m11, float m22)
    {
        setZero();
        (*this)(0, 0) = m00;
        (*this)(1, 1) = m11;
        (*this)(2, 2) = m22;
    }
};

class hkBaseObjectD1EE
{
  public:
    virtual ~hkBaseObjectD1EE() throw();
};

class hkReferencedObjectD1EE : public hkBaseObjectD1EE
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpSphereMotionD1EE : public hkReferencedObjectD1EE
{
  public:
    void FUN_00d1ee40(hkMatrix3D1EE& kInertiaInv) const;

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1EE m_kMotionState[11];
    hkVector4D1EE m_kInertiaAndMassInv;
};

// Fills kInertiaInv with a diagonal matrix whose entries are the inverse inertia stored in m_kInertiaAndMassInv.
// @fnv 0x00d1ee40
void hkpSphereMotionD1EE::FUN_00d1ee40(hkMatrix3D1EE& kInertiaInv) const
{
    float fInv = m_kInertiaAndMassInv(0);
    kInertiaInv.setDiagonal(fInv, fInv, fInv);
}

namespace fnv_00d1ee80 {


struct hkVector4D1E8x
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

struct hkMatrix3D1E8x
{
    hkVector4D1E8x m_kColumn0;
    hkVector4D1E8x m_kColumn1;
    hkVector4D1E8x m_kColumn2;

    float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }
    void setZero()
    {
        m_kColumn0.setZero4();
        m_kColumn1.setZero4();
        m_kColumn2.setZero4();
    }
    void setDiagonal(float m00, float m11, float m22)
    {
        setZero();
        (*this)(0, 0) = m00;
        (*this)(1, 1) = m11;
        (*this)(2, 2) = m22;
    }
};

class hkBaseObjectD1E8x
{
  public:
    virtual ~hkBaseObjectD1E8x() throw();
};

class hkReferencedObjectD1E8x : public hkBaseObjectD1E8x
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpSphereMotionD1E8x : public hkReferencedObjectD1E8x
{
  public:
    void FUN_00d1ee80(hkMatrix3D1E8x& kInertiaInv) const;

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1E8x m_kMotionState[11];
    hkVector4D1E8x m_kInertiaAndMassInv;
};

// Fills kInertiaInv with a diagonal matrix whose entries are all the inverse inertia value stored in m_kInertiaAndMassInv.
// @fnv 0x00d1ee80
void hkpSphereMotionD1E8x::FUN_00d1ee80(hkMatrix3D1E8x& kInertiaInv) const
{
    float fInv = m_kInertiaAndMassInv(0);
    kInertiaInv.setDiagonal(fInv, fInv, fInv);
}
}  // namespace fnv_00d1ee80

namespace fnv_00d1ef50 {


struct hkVector4D1EF
{
    __m128 m_vComponents;

    void setMul4(const hkVector4D1EF& a, const hkVector4D1EF& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4D1EF& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

class hkBaseObjectD1EF
{
  public:
    virtual ~hkBaseObjectD1EF() throw();
};

class hkReferencedObjectD1EF : public hkBaseObjectD1EF
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpSphereMotionD1EF : public hkReferencedObjectD1EF
{
  public:
    void ApplyImpulse(const hkVector4D1EF& kImpulse);

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4D1EF m_kMotionState[11];
    hkVector4D1EF m_kInertiaAndMassInv;
    hkVector4D1EF m_kTranslationalVelocity;
    hkVector4D1EF m_kAngularVelocity;
};

// Multiplies m_kInertiaAndMassInv by kImpulse and adds the result to m_kAngularVelocity.
// @fnv 0x00d1ef50
void hkpSphereMotionD1EF::ApplyImpulse(const hkVector4D1EF& kImpulse)
{
    hkVector4D1EF kDelta;
    kDelta.setMul4(m_kInertiaAndMassInv, kImpulse);
    m_kAngularVelocity.add4(kDelta);
}
}  // namespace fnv_00d1ef50

struct __declspec(align(16)) FUN_00d1ecc0_Matrix
{
    float m_Values[12];
};

struct FUN_00d1ecc0_Class
{
    unsigned char m_Padding[0xc0];
    float m_InertiaLocal;

    void FUN_00d1ecc0(FUN_00d1ecc0_Matrix& inertia) const;
};

// Writes to inertia three rows of four floats with 1/m_InertiaLocal at indices 0, 5 and 10 and zeros elsewhere.
// @fnv 0x00d1ecc0
void FUN_00d1ecc0_Class::FUN_00d1ecc0(FUN_00d1ecc0_Matrix& inertia) const
{
    const float value = 1.0f / m_InertiaLocal;
    const __m128 zero = _mm_setzero_ps();

    *reinterpret_cast<__m128*>(&inertia.m_Values[0]) = zero;
    *reinterpret_cast<__m128*>(&inertia.m_Values[4]) = zero;
    *reinterpret_cast<__m128*>(&inertia.m_Values[8]) = zero;

    inertia.m_Values[0] = value;
    inertia.m_Values[5] = value;
    inertia.m_Values[10] = value;
}

struct FUN_00d1ed00_t
{
    void GetInverseDiagonal(float* out);
};

// Writes to out three rows of four floats with 1/(float at offset 0xC0) at indices 0, 5 and 10 and zeros elsewhere.
// @fnv 0x00d1ed00
void FUN_00d1ed00_t::GetInverseDiagonal(float* out)
{
    float inv = 1.0f / ((float*)this)[48];
    __m128 z = _mm_setzero_ps();
    *(__m128*)out = z;
    *(__m128*)(out + 4) = z;
    *(__m128*)(out + 8) = z;
    out[0] = inv;
    out[5] = inv;
    out[10] = inv;
}


struct hkSimdRealX
{
    __m128 m_vValue;
    hkSimdRealX(__m128 r) : m_vValue(r)
    {}
};

struct hkVector4X
{
    __m128 m_vComponents;

    hkSimdRealX getW() const
    {
        return hkSimdRealX(_mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
    }
    void addMul4(const hkSimdRealX& s, const hkVector4X& v)
    {
        m_vComponents =
            _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), v.m_vComponents));
    }
    void setSub4(const hkVector4X& a, const hkVector4X& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setCross(const hkVector4X& v1, const hkVector4X& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xd2));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    void setMul4(const hkVector4X& a, const hkVector4X& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void add4(const hkVector4X& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

class hkpSphereMotionX
{
  public:
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    hkVector4X m_kMotionTransform[4];
    hkVector4X m_vCenterOfMass0;
    hkVector4X m_vCenterOfMass1;
    hkVector4X m_rest[5];
    hkVector4X m_kInertiaAndMassInv;
    hkVector4X m_kTranslationalVelocity;
    hkVector4X m_kAngularVelocity;

    void FUN_00d1eec0(const hkVector4X& imp, const hkVector4X& p);
};

// Adds imp scaled by the W of m_kInertiaAndMassInv to translational velocity, and (p - center of mass) x imp scaled by m_kInertiaAndMassInv to angular velocity.
// @fnv 0x00d1eec0
void hkpSphereMotionX::FUN_00d1eec0(const hkVector4X& imp, const hkVector4X& p)
{
    m_kTranslationalVelocity.addMul4(m_kInertiaAndMassInv.getW(), imp);
    hkVector4X relMassCenter;
    relMassCenter.setSub4(p, m_vCenterOfMass1);
    hkVector4X crossWs;
    crossWs.setCross(relMassCenter, imp);
    hkVector4X deltaVelWs;
    deltaVelWs.setMul4(crossWs, m_kInertiaAndMassInv);
    m_kAngularVelocity.add4(deltaVelWs);
}

union Vector
{
    __m128 quad;
    struct
    {
        float x, y, z, w;
    };
};
union Scalar
{
    __m128 quad;
    float real;
};
struct Simd
{
    __m128 quad;
};
union Vec
{
    __m128 quad;
    struct
    {
        float x, y, z, w;
    };

    __forceinline void mulFloat(float s)
    {
        quad = _mm_mul_ps(_mm_set_ps1(s), quad);
    }
    __forceinline void setFloat(float s, const Vec& v)
    {
        quad = _mm_mul_ps(_mm_set_ps1(s), v.quad);
    }
    __forceinline void mulSimd(const Simd& s)
    {
        quad = _mm_mul_ps(_mm_shuffle_ps(s.quad, s.quad, 0), quad);
    }
    __forceinline void setSimd(const Simd& s, const Vec& v)
    {
        quad = _mm_mul_ps(_mm_shuffle_ps(s.quad, s.quad, 0), v.quad);
    }
    __forceinline void add(const Vec& v)
    {
        quad = _mm_add_ps(v.quad, quad);
    }
    __forceinline void addMul(const Simd& s, const Vec& v)
    {
        quad = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(s.quad, s.quad, 0), v.quad), quad);
    }
    __forceinline Simd getW() const
    {
        Simd r;
        r.quad = _mm_shuffle_ps(quad, quad, 255);
        return r;
    }
};
class Motion
{
    hkVector4 m_00, m_10, m_20, m_30, m_40, m_50, m_60, m_70, m_80, m_90, m_a0, m_b0;
    Vec mass, velocity;

  public:
    void FUN_00d1ef80(float s, const Vec& force);
};
// Multiplies force by timestep s, scales by mass.getW(), and adds the result to velocity.
// @fnv 0x00d1ef80
void Motion::FUN_00d1ef80(float afTimestep, const Vec& force)
{
    __m128 timestep = _mm_load_ps1(&afTimestep);
    Vec impulse;
    impulse.quad = _mm_mul_ps(timestep, force.quad);
    Simd w = mass.getW();
    Vec weighted = impulse;
    weighted.mulSimd(w);
    velocity.add(weighted);
}

// Moved from hkpcharactermotion_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).


struct S00d1f050_Obj : hkpCharacterMotion
{
    void FUN_00d1f050(const hkVector4* pos, const hkVector4* normal, float* out_vel, float* out_inv_mass) const;
};

// @fnv 0x00d1f050
void S00d1f050_Obj::FUN_00d1f050(const hkVector4* pos, const hkVector4* normal, float* out_vel,
                                 float* out_inv_mass) const
{
    __m128 com = _mm_load_ps((const float*)&m_kMotionState.m_kSweptTransform.m_vCenterOfMass1);
    __m128 arm = _mm_sub_ps(_mm_load_ps((const float*)pos), com);
    __m128 n = _mm_load_ps((const float*)normal);
    __m128 lin = _mm_mul_ps(_mm_load_ps((const float*)&m_kTranslationalVelocity), n);
    __m128 cross = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(n, n, 0xc9), _mm_shuffle_ps(arm, arm, 0xd2)),
                              _mm_mul_ps(_mm_shuffle_ps(n, n, 0xd2), _mm_shuffle_ps(arm, arm, 0xc9)));
    __m128 ang = _mm_mul_ps(_mm_load_ps((const float*)&m_kAngularVelocity), cross);
    __m128 a1 = _mm_add_ss(_mm_shuffle_ps(ang, ang, 0x55), ang);
    __m128 a2 = _mm_add_ss(_mm_shuffle_ps(ang, ang, 0xaa), a1);
    __m128 l1 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0x55), lin);
    __m128 l2 = _mm_add_ss(_mm_shuffle_ps(lin, lin, 0xaa), l1);
    __m128 sum = _mm_add_ss(a2, l2);
    float fv = _mm_cvtss_f32(sum);
    *out_vel = fv;
    *out_inv_mass = m_kInertiaAndMassInv.w;
}

// Moved from hkpcharactermotion_rtm_variant.cpp (VEGAS-15).


class FUN_00d1efd0_cls
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20(hkVector4& out, int arg3);
    void FUN_00d1efd0(float s, const hkVector4& v, int arg3);
};

// @fnv 0x00d1efd0
void FUN_00d1efd0_cls::FUN_00d1efd0(float s, const hkVector4& v, int arg3)
{
    __declspec(align(16)) hkVector4 t;
    __m128 x = _mm_load_ss(&s);
    __m128 k = _mm_shuffle_ps(x, x, 0);
    __m128 r = _mm_mul_ps(k, _mm_load_ps(&v.x));
    _mm_store_ps(&t.x, r);
    this->v20(t, arg3);
}

class hkStatisticsCollector;
class CharacterTorqueMotion : public hkpCharacterMotion
{
  public:
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(hkStatisticsCollector*, const hkClass*) const;
    virtual void SetBodyMass(float);
    virtual void SetMassInv(float);
    virtual void GetInverseScaleMatrix(hkMatrix3&) const;
    virtual void GetInertiaLocal(hkMatrix3&) const;
    virtual void SetInertiaLocal(const hkMatrix3&);
    virtual void SetInertiaInvLocal(const hkMatrix3&);
    virtual void GetInertiaInvLocal(hkMatrix3&) const;
    virtual void GetLocalInverseInertia(hkMatrix3&) const;
    virtual void SetCenterOfMassInLocal(const hkVector4&);
    virtual void SetWorldPosition(const hkVector4&);
    virtual void SetBodyOrientation(const hkQuaternion&);
    virtual void SetPositionAndRotation(const hkVector4&, const hkQuaternion&);
    virtual void SetGeometryTransform(const hkTransform&);
    virtual void SetTranslationalVelocity(const hkVector4&);
    virtual void SetRotationalVelocity(const hkVector4&);
    virtual void GetProjectedPointVelocity(const hkVector4&, const hkVector4&, float&, float&) const;
    virtual void SetCollisionShape(const hkVector4&);
    virtual void ApplyImpulseAtPoint(const hkVector4&, const hkVector4&);
    virtual void ApplyAngularImpulseToBodies(const hkVector4&);
    void FUN_00d1f010(float step, const hkVector4& torque);
};
// @fnv 0x00d1f010
void CharacterTorqueMotion::FUN_00d1f010(float step, const hkVector4& torque)
{
    __declspec(align(16)) hkVector4 angularStep;
    __m128 scalar = _mm_load_ss(&step);
    __m128 scale = _mm_shuffle_ps(scalar, scalar, 0);
    _mm_store_ps(&angularStep.x, _mm_mul_ps(scale, _mm_load_ps(&torque.x)));
    ApplyAngularImpulseToBodies(angularStep);
}
