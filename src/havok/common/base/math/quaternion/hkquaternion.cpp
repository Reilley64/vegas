
// src/havok/common/base/math/quaternion/hkquaternion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/quaternion/hkquaternion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

/* PACKET-DECLARATIONS IS PROVIDED BY THE CHECKER; DO NOT INCLUDE IT IN YOUR SUBMISSION.
   Only submit the TARGET definition and any genuinely missing declarations that are required
   for compilation. Do not write or repeat packet-declarations, nor any headers that might
   be present in the checker's context. */

#include <cstdint>
#include "fnv_simd.h"
#include "fnv/symbols_00c74000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0102b000.h"
#include "fnv/symbols_simd.h"
#include "fnv/decl/FUN_00827200_class.h"
#include "fnv/decl/HkFloatCheck.h"
class FUN_005611c0_t
{
  public:
    void FUN_005611c0();
    void FUN_00cb2830(float* pts);
};

static float g_sink2550;

extern "C" double cb2550_clobber(double x);

// In-file stand-in for the helper. Its shape (not its bytes) is what matters:
// pts stays live across an ABI-clobbering call, so it gets a callee-saved
// home and the private convention passes it in esi; obj is read
// exactly once, late, so it stays on the stack.
static __declspec(noinline) void FUN_00cb2550(FUN_005611c0_t* obj, float* pts)
{
    float s = pts[0] * pts[1];
    s = (float)cb2550_clobber(s);
    s += pts[5];
    g_sink2550 = s;
    if (s > 1.0e9f)
        *(int*)obj = 0;
}

// @fnv 0x00cb2830
void FUN_005611c0_t::FUN_00cb2830(float* apPoints)
{
    FUN_00cb2550(this, apPoints);
    FUN_005611c0();
}

#include <xmmintrin.h>
#include <math.h>
struct FUN_00cb24c0_cls
{
    __m128 m_00;
    unsigned char* IsNormalized(unsigned char* flag);
};

// Checks whether the squared length is within 0.001 of 1.0, ANDs that with the existing flag, and stores the result.
// @fnv 0x00cb24c0
unsigned char* FUN_00cb24c0_cls::IsNormalized(unsigned char* apResult)
{
    reinterpret_cast<::HkFloatCheck *>(this)->FUN_00c7f500((bool *)(apResult));
    __m128 t = _mm_mul_ps(m_00, m_00);
    __m128 a = _mm_add_ps(_mm_shuffle_ps(t, t, 0x4e), t);
    __m128 vSumAll = _mm_add_ps(_mm_shuffle_ps(a, a, 0xb1), a);
    float fLengthSq;
    _mm_store_ss(&fLengthSq, vSumAll);
    float fDiff = fLengthSq - 1.0;
    fDiff = fabsf(fDiff);
    bool bIsNormalized = fDiff < 0.001f;
    unsigned char r;
    if (*apResult && bIsNormalized)
        r = 1;
    else
        r = 0;
    *apResult = r;
    return apResult;
}

struct Block64
{
    __m128 v0;
    __m128 v1;
    __m128 v2;
    __m128 v3;
};

struct SubObj
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;

};

__declspec(align(16)) struct FUN_00cf5950_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    SubObj m_sub;
    Block64 m_block;

    void CopyBlock(Block64* src);
};

// Copies the four 128-bit vectors from src into m_block, then calls m_sub.CallSub on the copied block.
// @fnv 0x00cf5950
void FUN_00cf5950_cls::CopyBlock(Block64* src)
{
    Block64* dst = &m_block;
    dst->v0 = src->v0;
    dst->v1 = src->v1;
    dst->v2 = src->v2;
    dst->v3 = src->v3;
    reinterpret_cast<::FUN_00827200_class *>(&(m_sub))->FUN_00cb26e0((intptr_t)(dst));
}

struct S00cb2550_V4
{
    union
    {
        __m128 q;
        float v[4];
    };
};

struct S00cb2550_Rot
{
    float m[3][4];
    float operator()(int r, int c) const
    {
        return m[c][r];
    }
};

struct S00cb2550_Quat
{
    S00cb2550_V4 q;
};

// Converts a rotation matrix to a quaternion and stores the quaternion in self->q.
// @fnv 0x00cb2550
static __declspec(noinline) void FUN_00cb2550(S00cb2550_Quat* apQuat, const S00cb2550_Rot& arRot)
{
    S00cb2550_V4 v;
    float trace = arRot(0, 0) + arRot(1, 1) + arRot(2, 2);
    if (trace > 0)
    {
        float s = sqrtf((float)(trace + 1.0));
        float t = (float)(0.5 / s);
        v.v[0] = (arRot(2, 1) - arRot(1, 2)) * t;
        v.v[1] = (arRot(0, 2) - arRot(2, 0)) * t;
        v.v[2] = (arRot(1, 0) - arRot(0, 1)) * t;
        v.v[3] = (float)(0.5 * s);
        apQuat->q.q = v.q;
    }
    else
    {
        int next[3];
        next[0] = 1;
        next[1] = 2;
        next[2] = 0;
        int iMax = 0;
        if (arRot(1, 1) > arRot(0, 0))
            iMax = 1;
        if (arRot(2, 2) > arRot(iMax, iMax))
            iMax = 2;
        int j = next[iMax];
        int k = next[j];
        float s = sqrtf((float)(arRot(iMax, iMax) - (arRot(j, j) + arRot(k, k)) + 1.0));
        float t = (float)(0.5 / s);
        v.v[iMax] = (float)(s * 0.5);
        v.v[3] = (arRot(k, j) - arRot(j, k)) * t;
        v.v[j] = (arRot(j, iMax) + arRot(iMax, j)) * t;
        v.v[k] = (arRot(k, iMax) + arRot(iMax, k)) * t;
        apQuat->q.q = v.q;
    }
}

void S00cb2550_caller(S00cb2550_Quat* q, const S00cb2550_Rot& r)
{
    FUN_00cb2550(q, r);
}
namespace fnv_00cb2700 {


union VecStorage
{
    __m128 quad;
    float axis[4];
};

struct PerpendicularVector
{
    __m128 m_result;

    void FUN_00cb2700(const float* v);
};

extern "C" double fabs(double);
extern const float DAT_01011d78;
extern "C" void _ReadWriteBarrier();

static __forceinline __m128 inverse_length(__m128 t)
{
    __m128 mask = _mm_cmpeq_ss(t, _mm_set_ss(0.0f));
    __m128 inv = _mm_rsqrt_ss(t);
    __m128 xi = _mm_mul_ss(_mm_mul_ss(t, inv), inv);
    __m128 yy = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), inv), _mm_sub_ss(_mm_set_ss(DAT_01017718), xi));
    return _mm_andnot_ps(mask, yy);
}

// @fnv 0x00cb2700
void PerpendicularVector::FUN_00cb2700(const float* v)
{
    VecStorage w;
    float a;
    float b;
    float c;
    int i0 = 0;
    int i1 = i0 + 1;
    int i2 = i0 + 2;

    {
        volatile float rounded = (float)fabs((double)v[0]);
        a = rounded;
    }
    {
        volatile float rounded = (float)fabs((double)v[1]);
        b = rounded;
    }
    {
        volatile float rounded = (float)fabs((double)v[2]);
        c = rounded;
    }

    if (b < a)
    {
        a = b;
        i1 = 0;
        i0 = i2 - 1;
    }
    if (c < a)
    {
        i2 = i0;
    }

    w.quad = _mm_setzero_ps();
    w.axis[i1] = v[i2];
    w.axis[i2] = -v[i1];

    float zz = 0.0f;
    __m128 sq = _mm_mul_ps(w.quad, w.quad);
    __m128 p1 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 p2 = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 t = _mm_add_ss(p1, sq);
    t = _mm_add_ss(p2, t);

    __m128 s = inverse_length(t);

    __m128 sv = _mm_shuffle_ps(s, s, 0);
    __m128 r = _mm_mul_ps(sv, w.quad);
    fnv_simd_as<float>(r)[3] = zz;
    m_result = r;
}
}extern double DAT_010c8758;
inline __m128 scalar(float f)
{
    return _mm_load_ss(&f);
}
class Rotation
{
  public:
    __m128 m_v;
    void FUN_00cb2850(const __m128* a, const __m128* b, float t);
};
// @fnv 0x00cb2850
void Rotation::FUN_00cb2850(const __m128* a, const __m128* b, float t)
{
    __m128 va = *a;
    __m128 vb = *b;
    __m128 products = _mm_mul_ps(vb, va);
    __m128 sum = _mm_add_ps(products, _mm_shuffle_ps(products, products, 0x4e));
    sum = _mm_add_ps(sum, _mm_shuffle_ps(sum, sum, 0xb1));
    float dot;
    float d;
    _mm_store_ss(&dot, sum);
    d = dot;
    float sign = 1.0f;
    if (dot < 0.0f)
    {
        d = -dot;
        sign = ::DAT_01012054;
    }
    __m128 result;
    if (d < DAT_010c8758)
    {
        float angle = ClampedAcos(d);
        float inverse = 1.0f / sqrtf(1.0f - d * d);
        float angle_t = angle * t;
        __m128 first_vector = scalar(sinf(angle - angle_t) * inverse);
        float second = sinf(angle_t) * inverse;
        __m128 weighted_first = _mm_mul_ps(_mm_shuffle_ps(first_vector, first_vector, 0), va);
        __m128 second_vector = scalar(second * sign);
        result = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(second_vector, second_vector, 0), vb), weighted_first);
    }
    else
    {
        __m128 first_vector = scalar(1.0f - t);
        __m128 second_vector = scalar(t * sign);
        result = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(second_vector, second_vector, 0), vb),
                            _mm_mul_ps(_mm_shuffle_ps(first_vector, first_vector, 0), va));
    }
    __m128 half = _mm_set_ss(::fnv_00c88020::DAT_01016248);
    __m128 three = _mm_set_ss(::DAT_01017718);
    __m128 zero = _mm_set_ss(::DAT_01011d78);
    __m128 squares = _mm_mul_ps(result, result);
    __m128 sum0 = _mm_add_ps(_mm_shuffle_ps(squares, squares, 0x4e), squares);
    __m128 norm_sum = _mm_add_ps(sum0, _mm_shuffle_ps(sum0, sum0, 0xb1));
    __m128 is_zero = _mm_cmpeq_ss(norm_sum, zero);
    __m128 reciprocal = _mm_rsqrt_ss(norm_sum);
    __m128 corrected = _mm_mul_ss(_mm_mul_ss(half, reciprocal),
                                  _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(norm_sum, reciprocal), reciprocal)));
    corrected = _mm_andnot_ps(is_zero, corrected);
    __m128 scale = _mm_shuffle_ps(corrected, corrected, 0);
    m_v = _mm_mul_ps(scale, result);
}struct hkVector4
{
    union
    {
        __m128 m_vComponents;
        float m_f[4];
    };

    inline float& operator()(int i)
    {
        return m_f[i];
    }
    inline const float& operator()(int i) const
    {
        return m_f[i];
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    void FUN_00cb2450(const hkVector4& axis, float angle);
    void FUN_00cb2a50(const hkVector4& v);
};

extern const double DAT_010c8760;


namespace MathUtilities {
inline float fabs(float f)
{
    return fabsf(f);
}
}

// @fnv 0x00cb2a50
void hkQuaternion::FUN_00cb2a50(const hkVector4& v)
{
    __m128 q_w = _mm_shuffle_ps(m_vec.m_vComponents, m_vec.m_vComponents, 0xff);

    __m128 prod0 = _mm_mul_ps(v.m_vComponents, m_vec.m_vComponents);
    __m128 sum0 = _mm_add_ss(_mm_shuffle_ps(prod0, prod0, 0x55), prod0);
    __m128 dot0 = _mm_add_ss(_mm_shuffle_ps(prod0, prod0, 0xaa), sum0);

    __m128 q_c9 = _mm_shuffle_ps(m_vec.m_vComponents, m_vec.m_vComponents, 0xc9);
    __m128 q_d2 = _mm_shuffle_ps(m_vec.m_vComponents, m_vec.m_vComponents, 0xd2);

    __m128 v_c9 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xc9);
    __m128 qd2_vc9 = _mm_mul_ps(q_d2, v_c9);
    __m128 v_d2 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xd2);
    __m128 qc9_vd2 = _mm_mul_ps(q_c9, v_d2);
    __m128 cross = _mm_sub_ps(qc9_vd2, qd2_vc9);

    __m128 term1 = _mm_mul_ps(cross, q_w);
    __m128 w2 = _mm_mul_ps(q_w, q_w);
    __m128 w2_sub_half = _mm_add_ps(w2, (*reinterpret_cast<const ::hkVector4 *>((void *)&::DAT_010c71e0)).m_vComponents);

    __m128 dot0_shuf = _mm_shuffle_ps(dot0, dot0, 0);
    __m128 term2 = _mm_mul_ps(dot0_shuf, m_vec.m_vComponents);
    __m128 term3 = _mm_mul_ps(w2_sub_half, v.m_vComponents);

    __m128 add1 = _mm_add_ps(term3, term2);
    __m128 add2 = _mm_add_ps(term1, add1);
    __m128 v_rot = _mm_add_ps(add2, add2);

    // dot3(v, v_rot)
    __m128 prod1 = _mm_mul_ps(v.m_vComponents, v_rot);
    __m128 sum1 = _mm_add_ss(_mm_shuffle_ps(prod1, prod1, 0x55), prod1);
    __m128 dot1 = _mm_add_ss(_mm_shuffle_ps(prod1, prod1, 0xaa), sum1);

    float dot;
    _mm_store_ss(&dot, dot1);

    if (dot - 1.0f > DAT_010c8760)
    {
        m_vec.m_vComponents = (*reinterpret_cast<const ::hkVector4 *>((void *)&::DAT_010c71b0)).m_vComponents;
        return;
    }

    hkVector4 axis;

    if (dot + 1.0f < DAT_01016978)
    {
        int i0 = 0;
        int i1 = 1;
        int i2 = 2;

        float f0 = MathUtilities::fabs(v(0));
        float f1 = MathUtilities::fabs(v(1));
        float f2 = MathUtilities::fabs(v(2));

        if (f1 < f0)
        {
            f0 = f1;
            i1 = 0;
            i0 = 1;
        }
        if (f2 < f0)
        {
            i2 = i0;
        }

        axis.m_vComponents = _mm_setzero_ps();
        axis(i1) = v(i2);
        axis(i2) = -v(i1);

        FUN_00cb2450(axis, ::DAT_0102b3c8);
        return;
    }

    __m128 vrot_c9 = _mm_shuffle_ps(v_rot, v_rot, 0xc9);
    __m128 vrot_d2 = _mm_shuffle_ps(v_rot, v_rot, 0xd2);

    __m128 t1 = _mm_mul_ps(vrot_c9, v_d2);
    __m128 t2 = _mm_mul_ps(vrot_d2, v_c9);
    __m128 cross2 = _mm_sub_ps(t2, t1);
    __m128 cp_sq = _mm_mul_ps(cross2, cross2);
    __m128 cp_sum1 = _mm_add_ss(_mm_shuffle_ps(cp_sq, cp_sq, 0x55), cp_sq);
    __m128 len_sq = _mm_add_ss(_mm_shuffle_ps(cp_sq, cp_sq, 0xaa), cp_sum1);

    __m128 rsqrt = _mm_rsqrt_ss(len_sq);

    __m128 step1 = _mm_mul_ss(_mm_mul_ss(len_sq, rsqrt), rsqrt);
    __m128 is_zero = _mm_cmpeq_ss(len_sq, _mm_set_ss(0.0f));
    __m128 sub_step = _mm_sub_ss(_mm_set_ss(3.0f), step1);
    __m128 mul1 = _mm_mul_ss(_mm_set_ss(0.5f), rsqrt);
    __m128 mul2 = _mm_mul_ss(mul1, sub_step);
    __m128 inv_len = _mm_andnot_ps(is_zero, mul2);
    __m128 inv_len_bcast = _mm_shuffle_ps(inv_len, inv_len, 0);

    axis.m_vComponents = _mm_mul_ps(inv_len_bcast, cross2);

    FUN_00cb2450(axis, ClampedAcos(dot));
}

__declspec(align(16)) struct FUN_00cb2450_cls
{
    __m128 m_00;
    void FUN_00cb2450(__m128* v, float a1);
};
struct LFrame
{
    float unk04;
    float x;
    volatile float s;
};
// @fnv 0x00cb2450
void FUN_00cb2450_cls::FUN_00cb2450(__m128* v, float a1)
{
    LFrame f;
    f.x = (float)(a1 * 0.5);
    f.s = (float)sin((double)f.x);
    f.s = f.s;
    __m128 t = _mm_load_ss((const float*)&f.s);
    __m128 splat = _mm_shuffle_ps(t, t, 0);
    __m128 vv = *v;
    m_00 = _mm_mul_ps(splat, vv);
    f.s = (float)cos((double)f.x);
    ((float*)this)[3] = f.s;
}

#include "generated/data/havok/common/base/math/quaternion/hkquaternion.inc"
