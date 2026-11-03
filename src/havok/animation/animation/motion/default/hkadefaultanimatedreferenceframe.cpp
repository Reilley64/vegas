
// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00e41080_Obj
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
    float unk30;

    float GetUnk30();
};

// Returns the float stored at offset 0x30 of this object.
// @fnv 0x00e41080
float FUN_00e41080_Obj::GetUnk30()
{
    return unk30;
}

#include <cstdint>
#include "fnv_simd.h"
#include "fnv/symbols_simd.h"
#include "fnv/symbols_00e41000.h"
#include <new>
#include "fnv/decl/FUN_00cb1600.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/FloatArgStream.h"
#include "fnv/decl/Quat74.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01268000.h"
#include <math.h>
#include <xmmintrin.h>
struct E41090Vector4
{
    __m128 m_vComponents;

    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct E41090Bool
{
    char m_cBooleanValue;
    E41090Bool& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};

struct FUN_00e41090
{
    FUN_00e41090();

    int unk00;
    int unk04;
    float unk08;
    int unk0C;
    E41090Bool unk10;
    E41090Bool unk11;
    E41090Bool unk12;
    E41090Bool unk13;
    int unk14;
    int unk18;
    int unk1C;
    E41090Vector4 m_vStart;
    E41090Vector4 m_vEnd;
};

// @fnv 0x00e41090
FUN_00e41090::FUN_00e41090()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0.0f;
    unk0C = 2;
    unk10 = false;
    unk11 = true;
    unk12 = false;
    unk13 = false;
    m_vStart.set(0.0f, 0.0f, 1.0f, 0.0f);
    m_vEnd.set(1.0f, 0.0f, 0.0f, 0.0f);
}


struct __declspec(align(16)) Projection363_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned char flag10;
    unsigned char flag11;
    unsigned char flag12;
    unsigned char flag13;
    int unk14;
    int unk18;
    int unk1C;
    __m128 vec20;
    __m128 vec30;
};

struct Projection363_Input
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Projection363_Helper
{
    __m128 rotation;
    int FUN_00cb2ca0(void* p, Vec4* f2, float* f1);
};

__forceinline __m128 Dot363(const __m128& a, const __m128& b)
{
    __m128 m = _mm_mul_ps(a, b);
    __m128 p = _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m);
    __m128 q = _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), p);
    return _mm_shuffle_ps(q, q, 0);
}
__forceinline __m128 Project363(const __m128& v, const __m128& axis)
{
    return _mm_mul_ps(Dot363(v, axis), axis);
}
__forceinline __m128 Cross363(const __m128& v1, const __m128& v2)
{
    const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xc9), _mm_shuffle_ps(v2, v2, 0xd2));
    const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1, v1, 0xd2), _mm_shuffle_ps(v2, v2, 0xc9));
    return _mm_sub_ps(cross0, cross1);
}
struct OutVec
{
    __m128 m_vComponents;
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void add4(const __m128& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v);
    }
};

struct Motion363
{
    __m128 vector;
    Projection363_Helper angular;
};

// @fnv 0x00e41220
void FUN_00e41220(Projection363_Owner* a, Motion363* __restrict b, Projection363_Input* c, OutVec* out)
{
    __m128 A = a->vec20;
    const __m128& v = b->vector;
    __m128 T2 = Project363(v, A);
    __m128 T4 = Project363(v, (Cross363(a->vec20, a->vec30)));
    __m128 T1 = Project363(v, a->vec30);
    out->setZero4();
    if (a->flag11 != 0)
    {
        out->add4(T1);
    }
    if (a->flag10 != 0)
    {
        out->add4(T2);
    }
    if (a->flag12 != 0)
    {
        out->add4(T4);
    }
    if (a->flag13 != 0)
    {
        float f1;
        Vec4 f2;
        Projection363_Helper* h = &b->angular;
        h->FUN_00cb2ca0(&a->vec20, &f2, &f1);
        float target = c->unk0C;
        const double PI = 3.14159265358979323846f;
        const double TWO_PI = 6.28318530717958647692f;
        while (f1 - target > PI)
        {
            f1 -= TWO_PI;
        }
        while (f1 - target < -PI)
        {
            f1 += TWO_PI;
        }
        fnv_simd_as<float>(out->m_vComponents)[3] = f1;
    }
    else
    {
        fnv_simd_as<float>(out->m_vComponents)[3] = 0.0f;
    }
}

struct VectorComponentValue
{
    __m128 value;
    VectorComponentValue(const __m128& v) : value(v)
    {}
    const __m128& getQuad() const
    {
        return value;
    }
};
struct hkQuaternion;
struct hkVector4
{
    __m128 v;
    hkVector4()
    {}
    hkVector4(const hkVector4& a) : v(a.v)
    {}
    void operator=(const hkVector4& a)
    {
        v = a.v;
    }
    __m128& getQuad()
    {
        return v;
    }
    const __m128& getQuad() const
    {
        return v;
    }
    operator __m128() const
    {
        return v;
    }
    void setAdd4(const hkVector4& a, const hkVector4& b)
    {
        v = _mm_add_ps(a.v, b.v);
    }
    void setSub4(const hkVector4& a, const hkVector4& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    void setMul4(const hkVector4& a, const hkVector4& b)
    {
        v = _mm_mul_ps(a.v, b.v);
    }
    void setAddMul4(const hkVector4& a, const hkVector4& b, const hkVector4& c)
    {
        v = _mm_add_ps(a.v, _mm_mul_ps(b.v, c.v));
    }
    void addMul4(const hkVector4& a, const hkVector4& b)
    {
        v = _mm_add_ps(v, _mm_mul_ps(a.v, b.v));
    }
    void add4(const hkVector4& a)
    {
        v = _mm_add_ps(v, a.v);
    }
    void sub4(const hkVector4& a)
    {
        v = _mm_sub_ps(v, a.v);
    }
    void SetAllComponents(float a)
    {
        v = _mm_set1_ps(a);
    }
    void SetAllComponents(const VectorComponentValue& a)
    {
        v = _mm_shuffle_ps(a.getQuad(), a.getQuad(), 0);
    }
    void broadcast(int i)
    {
        if (i == 0)
            v = _mm_shuffle_ps(v, v, 0);
        else if (i == 1)
            v = _mm_shuffle_ps(v, v, 0x55);
        else if (i == 2)
            v = _mm_shuffle_ps(v, v, 0xaa);
        else if (i == 3)
            v = _mm_shuffle_ps(v, v, 0xff);
    }
    void setBroadcast(const hkVector4& a, int i)
    {
        if (i == 0)
            v = _mm_shuffle_ps(a.v, a.v, 0);
        else if (i == 1)
            v = _mm_shuffle_ps(a.v, a.v, 0x55);
        else if (i == 2)
            v = _mm_shuffle_ps(a.v, a.v, 0xaa);
        else if (i == 3)
            v = _mm_shuffle_ps(a.v, a.v, 0xff);
    }
    VectorComponentValue dot3(const hkVector4& a) const
    {
        __m128 prod = _mm_mul_ps(v, a.v);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(prod, prod, 0x55), prod);
        return _mm_add_ss(_mm_shuffle_ps(prod, prod, 0xaa), xy);
    }
    void setCross(const hkVector4& a, const hkVector4& b)
    {
        __m128 first = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xc9), _mm_shuffle_ps(b.v, b.v, 0xd2));
        __m128 second = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xd2), _mm_shuffle_ps(b.v, b.v, 0xc9));
        v = _mm_sub_ps(first, second);
    }
    void setXYZW(const hkVector4& a, const hkVector4& b)
    {
        __m128 high = _mm_unpackhi_ps(a.v, b.v);
        v = _mm_shuffle_ps(a.v, high, 0xc4);
    }
    void setReciprocal3(const hkVector4& a);
    void setXYZ0(const hkVector4& a);
    void setNeg4(const hkVector4& a);
    void setNeg3(const hkVector4& a);
    __forceinline void SetRotatedDirection(const hkQuaternion& q, const hkVector4& direction);
    __forceinline void setRotatedInverseDir(const hkQuaternion& q, const hkVector4& direction);
};
inline __m128 reciprocal(__m128 x)
{
    __m128 r = _mm_rcp_ps(x);
    return _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, x), r));
}
inline void hkVector4::setReciprocal3(const hkVector4& a)
{
    hkVector4 one;
    one.getQuad() = (*reinterpret_cast<const ::hkVector4 *>(&::DAT_010c7170)).getQuad();
    hkVector4 joined;
    joined.setXYZW(a, one);
    v = reciprocal(joined.v);
}
inline void hkVector4::setXYZ0(const hkVector4& a)
{
    v = _mm_and_ps(a, (*reinterpret_cast<const ::hkVector4 *>(&::DAT_010c4c10)).v);
}
inline void hkVector4::setNeg4(const hkVector4& a)
{
    v = _mm_xor_ps(a.v, (*reinterpret_cast<const ::hkVector4 *>((void *)&::DAT_010c44d0)).v);
}
inline void hkVector4::setNeg3(const hkVector4& a)
{
    v = _mm_xor_ps(a.v, (*reinterpret_cast<const ::hkVector4 *>(&::DAT_010c4c00)).v);
}
struct hkQuaternion
{
    hkVector4 m_vec;
    const hkVector4& getImag() const
    {
        return m_vec;
    }
    void SetConjugate(const hkQuaternion& q)
    {
        m_vec.setNeg3(q.getImag());
    }
    void FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b);
};
inline void hkQuaternion::FUN_00c66320(const hkQuaternion& a, const hkQuaternion& b)
{
    hkVector4 imaginary;
    imaginary.setCross(a.getImag(), b.getImag());
    hkVector4 aw;
    aw.setBroadcast(a.m_vec, 3);
    hkVector4 bw;
    bw.setBroadcast(b.m_vec, 3);
    imaginary.addMul4(aw, b.getImag());
    imaginary.addMul4(bw, a.getImag());
    hkVector4 dot;
    dot.SetAllComponents(a.m_vec.dot3(b.m_vec));
    hkVector4 product;
    product.setMul4(a.m_vec, b.m_vec);
    product.sub4(dot);
    m_vec.setXYZW(imaginary, product);
}
__forceinline void hkVector4::SetRotatedDirection(const hkQuaternion& q, const hkVector4& direction)
{
    hkVector4 half;
    half.getQuad() = (*reinterpret_cast<const ::hkVector4 *>((void *)&::DAT_010c71e0)).getQuad();
    hkVector4 real;
    real.setBroadcast(q.m_vec, 3);
    hkVector4 factor;
    factor.setAddMul4(half, real, real);
    hkVector4 sum;
    sum.setMul4(direction, factor);
    hkVector4 dot;
    dot.getQuad() = q.getImag().dot3(direction).getQuad();
    dot.broadcast(0);
    sum.addMul4(dot, q.getImag());
    hkVector4 cross;
    cross.setCross(q.getImag(), direction);
    sum.addMul4(real, cross);
    setAdd4(sum, sum);
}
__forceinline void hkVector4::setRotatedInverseDir(const hkQuaternion& q, const hkVector4& direction)
{
    hkVector4 half;
    half.getQuad() = (*reinterpret_cast<const ::hkVector4 *>((void *)&::DAT_010c71e0)).getQuad();
    hkVector4 real;
    real.setBroadcast(q.m_vec, 3);
    hkVector4 factor;
    factor.setAddMul4(half, real, real);
    hkVector4 sum;
    sum.setMul4(direction, factor);
    hkVector4 dot;
    dot.getQuad() = q.getImag().dot3(direction).getQuad();
    dot.broadcast(0);
    sum.addMul4(dot, q.getImag());
    hkVector4 cross;
    cross.setCross(direction, q.getImag());
    sum.addMul4(real, cross);
    setAdd4(sum, sum);
}
struct hkTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
    __forceinline hkTransform()
    {}
    __forceinline void SetConjugate(const hkTransform& a)
    {
        m_vTranslation.setRotatedInverseDir(a.m_rotation, a.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(a.m_rotation);
        hkVector4 scale;
        scale.setReciprocal3(a.m_vScale);
        m_vScale.setXYZ0(scale);
    }
    __forceinline void SetProduct(const hkTransform& a, const hkTransform& b)
    {
        hkVector4 shift;
        shift.SetRotatedDirection(a.m_rotation, b.m_vTranslation);
        m_vTranslation.setAdd4(a.m_vTranslation, shift);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), (void *)&(a.m_rotation), (const __m128 *)&(b.m_rotation), {});
        m_vScale.setMul4(a.m_vScale, b.m_vScale);
    }
    __forceinline void SetMulInverse(const hkTransform& a, const hkTransform& b)
    {
        hkTransform inv;
        inv.SetConjugate(a);
        SetProduct(inv, b);
    }
};
struct AnimatedFrame
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void EvaluateTransform(float time, hkTransform& out) const;
    int unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    float m_fAnimationDuration;
    void FUN_00e413d0(float time, float nextTime, int loops, hkTransform& output) const;
};
// @fnv 0x00e413d0
void AnimatedFrame::FUN_00e413d0(float time, float nextTime, int loops, hkTransform& output) const
{
    hkTransform start;
    EvaluateTransform(time, start);
    hkTransform next;
    EvaluateTransform(nextTime, next);
    if (loops != 0)
    {
        hkTransform cycle;
        EvaluateTransform(m_fAnimationDuration, cycle);
        const unsigned count = loops < 0 ? -loops : loops;
        for (unsigned i = 0; i < count; ++i)
        {
            if (loops < 0)
            {
                hkTransform temp;
                temp.SetMulInverse(cycle, next);
                next = temp;
            }
            else
            {
                hkTransform temp;
                temp.SetProduct(cycle, next);
                next = temp;
            }
        }
    }
    output.SetMulInverse(start, next);
    output.m_vScale.SetAllComponents(1.0f);
}


struct __declspec(align(16)) S00e41100_Vec4
{
    float m_v[4];
    __m128 getQuad() const
    {
        return _mm_load_ps(m_v);
    }
    void setQuad(__m128 q)
    {
        _mm_store_ps(m_v, q);
    }
};

struct S00e41100_Quat
{
    S00e41100_Vec4 m_vec;
    void FUN_00cb2450(const S00e41100_Vec4& axis, float angle);
};

struct S00e41100_hkQsTransform
{
    S00e41100_Vec4 m_vTranslation;
    S00e41100_Quat m_rotation;
    S00e41100_Vec4 m_vScale;
};

struct S00e41100_LinearKeyTrack
{
    virtual ~S00e41100_LinearKeyTrack();
    S00e41100_Vec4 m_kAxisEndPoints;
    S00e41100_Vec4 m_unk20;
    float m_fAnimationDuration;
    S00e41100_Vec4* m_keys;
    int m_numKeys;
    int m_iCapacityState;

    void FUN_00e41100(float time, S00e41100_hkQsTransform& out);
};

// @fnv 0x00e41100
void S00e41100_LinearKeyTrack::FUN_00e41100(float time, S00e41100_hkQsTransform& out)
{
    int last = m_numKeys - 1;
    float dt = m_fAnimationDuration / last;
    __m128 v;
    if (time >= m_fAnimationDuration)
    {
        v = m_keys[m_numKeys - 1].getQuad();
    }
    else if (time < 0.0f)
    {
        v = m_keys[0].getQuad();
    }
    else
    {
        int i = (int)(time / dt);
        if (i == last)
        {
            i--;
        }
        float f = time / dt - i;
        S00e41100_Vec4 a = m_keys[i];
        S00e41100_Vec4 b = m_keys[i + 1];
        __m128 t = _mm_load_ss(&f);
        t = _mm_shuffle_ps(t, t, 0);
        v = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, t), a.getQuad()), _mm_mul_ps(b.getQuad(), t));
    }
    out.m_vTranslation.setQuad(v);
    out.m_rotation.FUN_00cb2450(m_kAxisEndPoints, fnv_simd_as<float>(v)[3]);
    out.m_vScale.setQuad(_mm_set_ps1(1.0f));
}

__declspec(noinline) void hkQuaternion::FUN_00c74ac0(const void* pa, const void* pb) throw()
{
    const __m128 a = ((const hkQuaternion*)pa)->v;
    const __m128 b = ((const hkQuaternion*)pb)->v;
    __m128 xyz = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(b, b, 0xc9), _mm_shuffle_ps(a, a, 0xd2)),
                            _mm_mul_ps(_mm_shuffle_ps(b, b, 0xd2), _mm_shuffle_ps(a, a, 0xc9)));
    __m128 aw = _mm_shuffle_ps(a, a, 0xff);
    aw = _mm_shuffle_ps(aw, aw, 0);
    xyz = _mm_sub_ps(xyz, _mm_mul_ps(aw, b));
    __m128 bw = _mm_shuffle_ps(b, b, 0xff);
    bw = _mm_shuffle_ps(bw, bw, 0);
    xyz = _mm_add_ps(xyz, _mm_mul_ps(bw, a));
    __m128 prod = _mm_mul_ps(a, b);
    __m128 half = _mm_add_ps(_mm_shuffle_ps(prod, prod, 0x4e), prod);
    __m128 dot = _mm_add_ps(_mm_shuffle_ps(half, half, 0xb1), half);
    dot = _mm_shuffle_ps(dot, dot, 0);
    __m128 upper = _mm_unpackhi_ps(xyz, dot);
    v = _mm_shuffle_ps(xyz, upper, 0xc4);
}
struct hkMemoryAllocator
{
    int unk00;
};
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* mem, void* arr, intptr_t newCap, int elemSize) throw();
template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& a, int n)
    {
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&a, this, newSize, sizeof(T));
        }
    }
};
struct Config
{
    const hkTransform* m_kTransforms;
    int m_numQsTransforms;
    float m_fAnimationDuration;
    int m_iValueAfterAnimationDuration;
    bool m_unk10;
    bool m_unk11;
    bool m_unk12;
    bool m_bFlag13;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4 m_vStart;
    hkVector4 m_vEnd;
};
class hkOstream
{
    void* m_ppVirtualMethodTable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;

  public:
    hkOstream(void* buf, int len) throw()
    {
        new ((void *)this) ::FUN_00cb1600(buf, len);
    }
    ~hkOstream() throw()
    {
        reinterpret_cast<struct ::FUN_00cc00e0 *>(this)->FUN_00cc00e0::~FUN_00cc00e0();
    }
    hkOstream& operator<<(const char* str) throw()
    {
        return (*(::hkOstream *)(reinterpret_cast<::SinkOwner *>(this)->FUN_00cc01c0(str)));
    }
    hkOstream& operator<<(float val) throw()
    {
        return (*(::hkOstream *)(reinterpret_cast<::FloatArgStream *>(this)->WriteFloat(val)));
    }
};
class hkError
{
  public:
    virtual ~hkError() throw();
    virtual void unk1() throw();
    virtual void unk2() throw();
    virtual void message(int type, unsigned int id, const char* desc, const char* file, int line) throw();
};
extern int DAT_010e57a4;
extern const char DAT_010ebe28[], DAT_010ebdec[], DAT_010ebdcc[], DAT_010ebde0[], DAT_010ebd70[];
extern "C" void __cdecl FUN_00e41220(const Config* cfg, const void* v1, void* outV, const void* v2) throw();
extern "C" void __cdecl FUN_00e41bf0(void* outTransform, float time, const hkTransform* transforms, int numTransforms,
                                     float duration) throw();
struct MemoryRouter
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" MemoryRouter* __cdecl FUN_00c85750() throw();
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* mem, void* arr, intptr_t newCap, int elemSize) throw();
struct QuatHelper
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};
class FUN_00e41830
{
  public:
    int* m_ppVirtualMethodTable;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_unk08;
    int m_unk0C;
    hkVector4 m_vStart;
    hkVector4 m_vEnd;
    float m_fAnimationDuration;
    hkArray<hkVector4> m_kAnimationVectorSamples;
    FUN_00e41830(const Config& config) throw();
};
static __forceinline float dot3(__m128 a, __m128 b)
{
    __m128 m = _mm_mul_ps(a, b);
    __m128 y = _mm_shuffle_ps(m, m, 0x55);
    __m128 m_plus_y = _mm_add_ss(y, m);
    __m128 z = _mm_shuffle_ps(m, m, 0xaa);
    __m128 res = _mm_add_ss(z, m_plus_y);
    float out;
    _mm_store_ss(&out, res);
    return out;
}
static __forceinline __m128 cross(const __m128& a, const __m128& b)
{
    __m128 a_yzx = _mm_shuffle_ps(a, a, 0xc9);
    __m128 b_zxy = _mm_shuffle_ps(b, b, 0xd2);
    __m128 a_zxy = _mm_shuffle_ps(a, a, 0xd2);
    __m128 b_yzx = _mm_shuffle_ps(b, b, 0xc9);
    return _mm_sub_ps(_mm_mul_ps(a_yzx, b_zxy), _mm_mul_ps(a_zxy, b_yzx));
}
static __forceinline float my_fabs(float f)
{
    return fabsf(f);
}

// @fnv 0x00e41830
FUN_00e41830::FUN_00e41830(const Config& config) throw() : m_ppVirtualMethodTable(&DAT_010e57a4), m_sReferenceCount(1)
{
    int numSamples =
        config.m_iValueAfterAnimationDuration == -1 ? config.m_numQsTransforms : config.m_iValueAfterAnimationDuration;
    hkArray<hkVector4>& samples = m_kAnimationVectorSamples;
    m_vStart.v = config.m_vStart.v;
    m_vEnd.v = config.m_vEnd.v;
    float duration = config.m_fAnimationDuration;
    m_fAnimationDuration = duration;
    float dt = duration / (float)(numSamples - 1);
    hkVector4 tempV0;
    hkTransform startTransform;
    startTransform.m_vTranslation.v = config.m_kTransforms[0].m_vTranslation.v;
    startTransform.m_rotation.v = config.m_kTransforms[0].m_rotation.v;
    startTransform.m_vScale.v = config.m_kTransforms[0].m_vScale.v;
    {
        hkVector4 outV0;
        tempV0.v = _mm_setzero_ps();
        FUN_00e41220(&config, &DAT_01268700, &tempV0, &outV0);
        tempV0.v = outV0.v;
    }
    if (config.m_bFlag13)
    {
        float dotForward = my_fabs(config.m_vEnd.dot3(tempV0).getReal());
        hkVector4 cr;
        cr.v = cross(config.m_vStart.v, config.m_vEnd.v);
        float dotSide = my_fabs(cr.dot3(tempV0).getReal());
        if (dotForward > 0.01f || dotSide > 0.01f)
        {
            {
                char buf[512];
                hkOstream os(buf, 512);
                reinterpret_cast<::SinkOwner *>(&(os))->FUN_00cc01c0(DAT_010ebe28);
                (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabba9245, (const char*)buf, DAT_010ebdec, 88);
            }
            {
                char buf[512];
                hkOstream os(buf, 512);
                reinterpret_cast<::SinkOwner *>(&((*(::hkOstream *)(reinterpret_cast<::FloatArgStream *>(&((*(::hkOstream *)(reinterpret_cast<::SinkOwner *>(&((*(::hkOstream *)(reinterpret_cast<::FloatArgStream *>(&((*(::hkOstream *)(reinterpret_cast<::SinkOwner *>(&(os))->FUN_00cc01c0(DAT_010ebdcc)))))->WriteFloat(dotForward)))))->FUN_00cc01c0(DAT_01012630)))))->WriteFloat(dotSide)))))->FUN_00cc01c0(DAT_010ebde0);
                (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabba9245, (const char*)buf, DAT_010ebdec, 89);
            }
            {
                char buf[512];
                hkOstream os(buf, 512);
                reinterpret_cast<::SinkOwner *>(&(os))->FUN_00cc01c0(DAT_010ebd70);
                (*reinterpret_cast<::hkError * *>(&::DAT_01268360))->message(1, 0xabba9245, (const char*)buf, DAT_010ebdec, 90);
            }
        }
    }
    hkMemoryAllocator& mem = FUN_00c85750()->heap();
    const int cap = samples.m_iCapacityState & 0x3fffffff;
    if (cap < numSamples)
    {
        int newCap = cap + cap;
        if (numSamples >= newCap)
        {
            newCap = numSamples;
        }
        FUN_00c908c0(&mem, &samples, newCap, sizeof(hkVector4));
    }
    samples.m_iElementCount = numSamples;
    for (int i = 0; i < numSamples; ++i)
    {
        __m128 unitScale = _mm_set1_ps(1.0f);
        float time = (float)i * dt;
        hkTransform curTransform;
        FUN_00e41bf0(&curTransform, time, config.m_kTransforms, config.m_numQsTransforms, config.m_fAnimationDuration);
        QuatHelper qh;
        reinterpret_cast<::Quat74 *>(&(qh.m_rotation))->FUN_00c74ac0((*(const ::Quat74 *)(&curTransform.m_rotation)), (*(const ::Quat74 *)(&startTransform.m_rotation)));
        qh.m_vTranslation.v = _mm_sub_ps(curTransform.m_vTranslation.v, startTransform.m_vTranslation.v);
        qh.m_vScale.v = unitScale;
        hkVector4 sampleOut;
        FUN_00e41220(&config, &qh, &tempV0, &sampleOut);
        __m128 sample = sampleOut.v;
        samples.m_data[i].v = sample;
        tempV0.v = sample;
    }
}

#include "generated/data/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.inc"
