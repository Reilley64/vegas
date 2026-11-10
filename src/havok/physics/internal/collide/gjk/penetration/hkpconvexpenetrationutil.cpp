
// src/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "havok/hkMemoryRouter.h"
#include <xmmintrin.h>
#include "fnv/decl/DFB0B0_Owner.h"
#include "fnv/decl/Hull.h"
#include "fnv/symbols_00e2d000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_010db000.h"
#include "fnv/symbols_01268000.h"

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void operator=(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};

struct Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};

struct Obj
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_auiShapeKeys[4];
    Entry m_usTrailingValue[4];
    void SetEntries(const hkVector4* a, const hkVector4* b, const hkVector4* c);
};

// @fnv 0x00dfaf80
void Obj::SetEntries(const hkVector4* aVecA, const hkVector4* aVecB, const hkVector4* aVecC)
{
    m_num = 4;
    for (int iIndex = 0; iIndex < 4; iIndex++)
    {
        m_usTrailingValue[iIndex].m_kPointA = aVecA[iIndex];
        m_usTrailingValue[iIndex].m_kPointB = aVecB[iIndex];
        m_usTrailingValue[iIndex].m_iThirdValue = aVecC[iIndex];
        m_usTrailingValue[iIndex].m_flag = 0;
    }
    reinterpret_cast<::Hull *>(this)->FUN_00e2d440();
    m_iThirdValue = 0;
}

struct FUN_00df9c40_Obj
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
    __m128* unk60;
    __m128* unk64;
    __m128* unk68;
    int unk6C;

    void PushVectorTriple(const __m128* src);
};

// Stores the three __m128 values from src into the arrays at unk68, unk60 and unk64 at index unk6C, then increments unk6C.
// @fnv 0x00df9c40
void FUN_00df9c40_Obj::PushVectorTriple(const __m128* src)
{
    int idx = this->unk6C;
    this->unk68[idx] = src[0];
    this->unk60[idx] = src[1];
    this->unk64[idx] = src[2];
    this->unk6C = idx + 1;
}


struct S00cd7530_SimdReal
{
    __m128 m_vValue;
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct S00cd7530_Vec
{
    __m128 m_vComponents;
    __forceinline void setSub4(const S00cd7530_Vec& a, const S00cd7530_Vec& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline S00cd7530_SimdReal dot3(const S00cd7530_Vec& a) const
    {
        __m128 m = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 y = _mm_shuffle_ps(m, m, 0x55);
        __m128 xy = _mm_add_ss(y, m);
        __m128 z = _mm_shuffle_ps(m, m, 0xaa);
        S00cd7530_SimdReal r;
        r.m_vValue = _mm_add_ss(z, xy);
        return r;
    }
};

__forceinline void scalarDots(const S00cd7530_Vec& Q, const S00cd7530_Vec& R, float& QQ, float& RR, float& QR)
{
    QQ = Q.dot3(Q);
    _mm_store_ss(&RR, R.dot3(R).m_vValue);
    QR = R.dot3(Q);
}
// Computes barycentric coordinates of a point relative to a triangle defined by three vertices and stores the result in a float array.
// @fnv 0x00cd7530
void FUN_00cd7530(const S00cd7530_Vec* pos, const S00cd7530_Vec* t0, const S00cd7530_Vec* t1, const S00cd7530_Vec* t2,
                  float* result)
{
    S00cd7530_Vec Q;
    Q.setSub4((*t0), *t1);
    S00cd7530_Vec R;
    R.setSub4((*t2), *t1);
    float QQ, RR, QR;
    scalarDots(Q, R, QQ, RR, QR);

    const float QQRR = QQ * RR;
    const float QRQR = QR * QR;
    const float Det = QQRR - QRQR;
    if (Det > 0.0f)
    {
        const float invDet = 1.0f / Det;
        S00cd7530_Vec relPos;
        relPos.setSub4(*t1, (*pos));
        const float sq = relPos.dot3(Q);
        const float sr = relPos.dot3(R);
        const float q = sr * QR - RR * sq;
        const float r = sq * QR - QQ * sr;
        result[0] = invDet * q;
        result[1] = invDet * (Det - q - r);
        result[2] = invDet * r;
    }
    else
    {
        S00cd7530_Vec S;
        S.setSub4((*t0), (*t2));
        const float SS = S.dot3(S);
        if (QQ >= RR)
        {
            if (SS >= QQ)
            {
                result[1] = 0.0f;
                if (SS > 0.0f)
                {
                    S00cd7530_Vec relPos;
                    relPos.setSub4((*pos), (*t2));
                    const float t = relPos.dot3(S) / SS;
                    result[0] = t;
                    result[2] = 1.0f - t;
                }
                else
                {
                    result[0] = 0.0f;
                    result[2] = 0.0f;
                }
            }
            else
            {
                S00cd7530_Vec relPos;
                relPos.setSub4((*pos), *t1);
                const float t = relPos.dot3(Q) / QQ;
                result[0] = t;
                result[1] = 1.0f - t;
                result[2] = 0.0f;
            }
        }
        else
        {
            if (SS >= RR)
            {
                S00cd7530_Vec relPos;
                relPos.setSub4((*pos), (*t2));
                const float t = relPos.dot3(S) / SS;
                result[0] = t;
                result[1] = 0.0f;
                result[2] = 1.0f - t;
            }
            else
            {
                S00cd7530_Vec relPos;
                relPos.setSub4((*pos), *t1);
                const S00cd7530_SimdReal dot = relPos.dot3(R);
                result[0] = 0.0f;
                const float t = float(dot) / RR;
                result[2] = t;
                result[1] = 1.0f - t;
            }
        }
    }
}


struct S00dfa940_Entry
{
    hkVector4 m_iThirdValue;
    hkVector4 m_kPointA;
    hkVector4 m_kPointB;
    int m_flag;
};

struct S00dfa940_Simplex
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_num;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    S00dfa940_Entry m_usTrailingValue[0xBA];
    int m_t0;
    int m_t1;
    int m_t2;
    int m_t3;

};

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <windows.h>
#include "fnv/symbols_simd.h"

struct S_00dfaac0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        volatile unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = t;
    }
};

struct S_00dfaac0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00dfaac0_MonitorStream& GetMonitorStream()
    {
        return *(S_00dfaac0_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    void timer(const char* name)
    {
        if (memoryAvailable())
        {
            S_00dfaac0_TimerCommand* h = (S_00dfaac0_TimerCommand*)m_kRayEnd;
            h->m_pCommandName = name;
            _ReadWriteBarrier();
            h->setTime();
            m_kRayEnd = reinterpret_cast<char*>(h + 1);
        }
    }
};


extern "C"
{
    void FUN_00e2d6c0(void*, void*, void*, void*, void*);

}


struct Arg1
{
    int unk00, unk04, unk08, unk0c;
    float float10;
};

struct Arg2
{
    int unk00, unk04, unk08, unk0c;
    float float10;
    float getRadius() const
    {
        return float10;
    }
};

struct OutItem
{
    hkVector4 point;
    hkVector4 direction;
};

struct NormalSplats
{
    __m128 x;
    __m128 z;
};

struct LocalStruct70
{
    hkVector4 m_v0;
    hkVector4 m_v1;
    float m_f;
};

class hkTransform
{
  public:
    hkVector4 m_rotation[3];
    hkVector4 m_vTranslation;
    void operator=(const hkTransform& o)
    {
        *(__m128*)this = *(const __m128*)&o.m_rotation[0];
        m_rotation[1] = o.m_rotation[1];
        m_rotation[2] = o.m_rotation[2];
        m_vTranslation = o.m_vTranslation;
    }
};

struct WorkObject
{
    int unk00, unk04;
    int m_num;
    int unk0c, unk10, unk14, unk18, unk1c;
    Entry m_usTrailingValue[186];
    hkVector4 unk2ea0;
    Entry* allocEntry()
    {
        Entry* e = &m_usTrailingValue[m_num++];
        e->m_flag = 0;
        return e;
    }
};

struct Item
{
    hkTransform m_matrix;
    __m128 m_vec40;
    float m_float50;
    Arg1* m_arg1;
    Arg2* m_arg2;
    int m_unk5C;
    hkVector4* m_ptr60;
    hkVector4* m_ptr64;
    hkVector4* m_ptr68;
    int m_unk6C;
    hkVector4 m_vec70[4];
    hkVector4 m_vecB0[4];
    hkVector4 m_vecF0[4];
    Arg2* m_arg2_copy;
    OutItem* m_arg5;
    int unk138, unk13c;
    WorkObject m_obj;
    DFB0B0_Entry* m_nearest;
    int unk2ff4, unk2ff8, unk2ffc;

    void init(Arg1* a1, Arg2* a2, const hkTransform& trans, float eps, hkVector4* v70, hkVector4* vB0, hkVector4* vF0,
              int u6c)
    {
        m_matrix = trans;
        m_vec40 = _mm_set_ps1(eps);
        m_float50 = eps * eps;
        m_arg1 = a1;
        m_arg2 = a2;
        m_ptr60 = v70;
        m_ptr64 = vB0;
        m_unk5C = 0;
        m_ptr68 = vF0;
        m_unk6C = u6c;
    }

};

struct WorkArray
{
    Item* data;
    Item& operator[](int i)
    {
        return ((Item*)data)[i];
    }
    Item* begin()
    {
        return data;
    }
};


// Moved from hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_004b4ab0_Class.h"
#include "fnv/decl/FanSpace__FanBuilder.h"
#include "fnv/decl/FloatPair.h"



class hkMatrix3DF9B;

struct hkVector4DF9B
{
    __m128 m_vComponents;

    hkVector4DF9B()
    {}
    hkVector4DF9B(const hkVector4DF9B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4DF9B& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void _setRotatedDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b);
    __forceinline void _setRotatedInverseDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b);
    void setSub4(const hkVector4DF9B& a, const hkVector4DF9B& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setNeg4(const hkVector4DF9B& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
    }
    __forceinline void _setTransformedPos(const struct hkTransformDF9B& t, const hkVector4DF9B& b);
};

class hkMatrix3DF9B
{
  public:
    __forceinline void SetMulInverse(const hkMatrix3DF9B& kA, const hkMatrix3DF9B& kB)
    {
        hkMatrix3DF9B kATrans;
        kATrans.m_kColumn0 = kA.m_kColumn0;
        kATrans.m_kColumn1 = kA.m_kColumn1;
        kATrans.m_kColumn2 = kA.m_kColumn2;
        kATrans.transpose();
        for (int i = 0; i < 3; i++)
        {
            hkVector4DF9B kCol = kB.getColumn(i);
            getColumn(i)._setRotatedDir(kATrans, kCol);
        }
    }

    hkVector4DF9B& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    const hkVector4DF9B& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    __forceinline void transpose()
    {
        __m128 tmp = _mm_unpacklo_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents);
        __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(m_kColumn0.m_vComponents, m_kColumn1.m_vComponents),
                                     m_kColumn2.m_vComponents, 0xe4);
        m_kColumn0.m_vComponents = _mm_movelh_ps(tmp, m_kColumn2.m_vComponents);
        tmp = _mm_movehl_ps(m_kColumn0.m_vComponents, tmp);
        m_kColumn1.m_vComponents = _mm_shuffle_ps(tmp, m_kColumn2.m_vComponents, 0xd4);
        m_kColumn2.m_vComponents = ctmp;
    }

    hkVector4DF9B m_kColumn0;
    hkVector4DF9B m_kColumn1;
    hkVector4DF9B m_kColumn2;
};

__forceinline void hkVector4DF9B::_setRotatedDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(r.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(r.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(r.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

__forceinline void hkVector4DF9B::_setRotatedInverseDir(const hkMatrix3DF9B& r, const hkVector4DF9B& b)
{
    hkVector4DF9B kC0 = r.m_kColumn0;
    hkVector4DF9B kC1 = r.m_kColumn1;
    hkVector4DF9B kC2 = r.m_kColumn2;
    __m128 tmp = _mm_unpacklo_ps(kC0.m_vComponents, kC1.m_vComponents);
    const __m128 ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(kC0.m_vComponents, kC1.m_vComponents), kC2.m_vComponents, 0xe4);
    kC0.m_vComponents = _mm_movelh_ps(tmp, kC2.m_vComponents);
    tmp = _mm_movehl_ps(kC0.m_vComponents, tmp);
    kC1.m_vComponents = _mm_shuffle_ps(tmp, kC2.m_vComponents, 0xd4);
    kC2.m_vComponents = ctmp;
    const __m128 r0 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), kC0.m_vComponents);
    const __m128 r1 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), kC1.m_vComponents);
    const __m128 r2 = _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), kC2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

struct hkTransformDF9B
{
    hkMatrix3DF9B m_rotation;
    hkVector4DF9B m_vTranslation;
};

__forceinline void hkVector4DF9B::_setTransformedPos(const hkTransformDF9B& t, const hkVector4DF9B& b)
{
    const __m128 r0 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00), t.m_rotation.m_kColumn0.m_vComponents);
    const __m128 r1 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55), t.m_rotation.m_kColumn1.m_vComponents);
    const __m128 r2 =
        _mm_mul_ps(_mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa), t.m_rotation.m_kColumn2.m_vComponents);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.m_vTranslation.m_vComponents));
}

struct hkVector4StoreDF9B
{
    __declspec(align(16)) float m_v[4];

    void operator=(const hkVector4DF9B& v)
    {
        _mm_store_ps(m_v, v.m_vComponents);
    }
    operator const hkVector4DF9B&() const
    {
        return *reinterpret_cast<const hkVector4DF9B*>(m_v);
    }
};

struct hkpCdVertexPairDF9B
{
    hkVector4DF9B m_vContactPosition;
    hkVector4DF9B m_kVertexA;
    hkVector4DF9B m_kVertexB;
};

class hkpConvexShapeDF9B
{
  public:
    virtual void v00();
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
    virtual void GetSupportPoint(const hkVector4DF9B& kDirection, hkVector4DF9B& kSupportOut) const = 0;
};

class hkpMinkowskiDF9B
{
  public:
    void FUN_00df9b50(const hkVector4DF9B& kDirection, hkpCdVertexPairDF9B& kOut) const;

    hkTransformDF9B m_kTransform;
    unsigned int unk40, unk44, unk48, unk4C, unk50;
    const hkpConvexShapeDF9B* m_pShapeA;
    const hkpConvexShapeDF9B* m_pShapeB;
};

// @fnv 0x00df9b50
void hkpMinkowskiDF9B::FUN_00df9b50(const hkVector4DF9B& kDirection, hkpCdVertexPairDF9B& kOut) const
{
    m_pShapeA->GetSupportPoint(kDirection, kOut.m_kVertexA);
    hkVector4DF9B kNegDir;
    kNegDir.setNeg4(kDirection);
    hkVector4DF9B kRotated;
    kRotated._setRotatedInverseDir(m_kTransform.m_rotation, kNegDir);
    hkVector4StoreDF9B kLocalDir;
    kLocalDir = kRotated;
    m_pShapeB->GetSupportPoint(kLocalDir, kOut.m_kVertexB);
    hkVector4DF9B kBInA;
    kBInA._setTransformedPos(m_kTransform, kOut.m_kVertexB);
    kOut.m_vContactPosition.setSub4(kOut.m_kVertexA, kBInA);
}


struct __declspec(align(16)) S00df9ef0_Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct S00df9ef0_Hit
{
    S00df9ef0_Vec4 a;
    S00df9ef0_Vec4 b;
    S00df9ef0_Vec4 c;
    int d;
};

struct S00df9ef0_Obj
{

    void FUN_00df9ef0(S00df9ef0_Vec4* p, const S00df9ef0_Vec4* r, S00df9ef0_Hit* q, float* outF);
};

static float S00df9ef0_Dot3(__m128 v)
{
    __m128 s1 = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), s1);
    float f;
    _mm_store_ss(&f, s);
    return f;
}

// @fnv 0x00df9ef0
void S00df9ef0_Obj::FUN_00df9ef0(S00df9ef0_Vec4* p, const S00df9ef0_Vec4* r, S00df9ef0_Hit* q, float* outF)
{
    S00df9ef0_Hit h;
    S00df9ef0_Vec4 neg;
    _mm_store_ps(&neg.x, _mm_xor_ps(_mm_load_ps(&p->x), DAT_010c44d0));
    reinterpret_cast<::hkpMinkowskiDF9B *>((this))->FUN_00df9b50((*(const ::hkVector4DF9B *)(p)), (*(::hkpCdVertexPairDF9B *)(&h.a)));
    S00df9ef0_Hit* qq = q;
    reinterpret_cast<::hkpMinkowskiDF9B *>((this))->FUN_00df9b50((*(const ::hkVector4DF9B *)(&neg)), (*(::hkpCdVertexPairDF9B *)(&qq->a)));

    float f1 = S00df9ef0_Dot3(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(&h.a.x), _mm_load_ps(&r->x)), _mm_load_ps(&p->x)));
    float f2 = S00df9ef0_Dot3(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(&qq->a.x), _mm_load_ps(&r->x)), _mm_load_ps(&neg.x)));

    if (f1 >= f2)
    {
        __m128 vb = _mm_load_ps(&h.b.x);
        _mm_store_ps(&qq->a.x, _mm_load_ps(&h.a.x));
        _mm_store_ps(&qq->b.x, vb);
        _mm_store_ps(&qq->c.x, _mm_load_ps(&h.c.x));
        qq->d = h.d;
        *outF = f1;
    }
    else
    {
        *outF = f2;
    }
}


struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Tri
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const Vec4* m_p0;
    int unk14;
    int unk18;
    int unk1C;
    const Vec4* m_p1;
    int unk24;
    int unk28;
    int unk2C;
    const Vec4* m_p2;
};

struct Edges
{
    Vec4 e0;
    Vec4 e1;
    Vec4 e2;
};

struct Result4 : Vec4
{
};

struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int m_iThirdValue;
    int m_10;
};

struct Tester
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
    Vec4 m_40;
    int FUN_00df9c90(Shape* shape, const Tri* tri, const Vec4* pos, int* result);
};

// @fnv 0x00df9c90
int Tester::FUN_00df9c90(Shape* shape, const Tri* tri, const Vec4* pos, int* result)
{
    Edges edges;
    __m128 p = *(const __m128*)pos;
    *(__m128*)&edges.e0 = _mm_sub_ps(p, *(const __m128*)tri->m_p0);
    *(__m128*)&edges.e1 = _mm_sub_ps(p, *(const __m128*)tri->m_p1);
    *(__m128*)&edges.e2 = _mm_sub_ps(p, *(const __m128*)tri->m_p2);
    Result4 bary;
    reinterpret_cast<::FUN_004b4ab0_Class *>(&(bary))->FUN_004b4ab0(reinterpret_cast<intptr_t>(&edges), reinterpret_cast<intptr_t>(tri));
    if (_mm_movemask_ps(_mm_cmplt_ps(*(__m128*)&bary, *(__m128*)&m_40)) & 7)
    {
        *result = 0;
        return 1;
    }
    int a = 0;
    ::ParserContext* b;
    if (reinterpret_cast<::FloatPair *>((shape))->FUN_00dfb040((::ParserContext *)(tri), pos, &a, &b))
    {
        *result = 3;
        return 1;
    }
    if (shape->m_iThirdValue - shape->m_10 + 100 < a)
    {
        *result = 2;
        return 1;
    }
    if (reinterpret_cast<::FanSpace::FanBuilder *>((shape))->FUN_00e2d1b0(a, reinterpret_cast<::FanSpace::FanEdge *>(b), (::FanSpace::FanVertex *)(pos)))
    {
        *result = 3;
        return 1;
    }
    return 0;
}

// Moved from hkpconvexpenetrationutil_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/fnv_00e2d550__HullWalker.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00cd7000.h"
#include "fnv/symbols_00dfa000.h"
#include "fnv/symbols_01267000.h"
extern "C"
{
    void FUN_00e2d6c0(void*, void*, void*, void*, void*);

}



struct S_00df9d90_Bary
{
    float v[3];
    float get(int i) const
    {
        return v[i];
    }
};
__forceinline __m128 S_00df9d90_Ss(float f)
{
    return _mm_load_ss(&f);
}
__forceinline __m128 S_00df9d90_Mul(__m128 s, const __m128& v)
{
    return _mm_mul_ps(_mm_shuffle_ps(s, s, 0), v);
}

struct S_00df9d90_Src
{
    __m128 unk00;
    __m128* unk10;
    int unk14, unk18, unk1c;
    __m128* unk20;
    int unk24, unk28, unk2c;
    __m128* unk30;
    int unk34, unk38, unk3c;
    float unk40;
};

struct S_00df9d90_Out
{
    __m128 unk00;
    __m128 unk10;
    float unk20;
};

struct S_00df9d90_Owner;
struct S_00df9d90_OwnerP
{
    S_00df9d90_Owner* p;
    S_00df9d90_Owner* val() const
    {
        return p;
    }
};
struct S_00df9d90_OutP
{
    S_00df9d90_Out* p;
    S_00df9d90_Out* val() const
    {
        return p;
    }
};
struct S_00df9d90_Owner
{
};


struct S_00df9d90_This
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c;
    int unk50;
    const void* m_shapeA;
    const void* m_shapeB;
    int unk5c;
    __m128* unk60;
    __m128* unk64;
    __m128* unk68;
    int unk6c;
    S_00df9d90_Out* FUN_00df9d90(S_00df9d90_OwnerP owner, S_00df9d90_Src* s, S_00df9d90_OutP outp);
};

// @fnv 0x00df9d90
S_00df9d90_Out* S_00df9d90_This::FUN_00df9d90(S_00df9d90_OwnerP owner, S_00df9d90_Src* s, S_00df9d90_OutP outp)
{
    S_00df9d90_Bary bary;
    for (int i = 0; i < 10; i++)
    {
        unk68[0] = s->unk10[0];
        unk68[1] = s->unk20[0];
        unk68[2] = s->unk30[0];
        const S00cd7530_Vec* corners = reinterpret_cast<const S00cd7530_Vec*>(unk68);
        ::FUN_00cd7530(reinterpret_cast<const S00cd7530_Vec*>(&DAT_01267e30), &corners[0], &corners[1], &corners[2], bary.v);
        if (!(bary.v[0] < 0.0f || bary.v[1] < 0.0f || bary.v[2] < 0.0f))
            break;
        s = ((::S_00df9d90_Src *)(reinterpret_cast<::fnv_00e2d550::HullWalker *>((owner.val()))->FUN_00e2d550((::fnv_00e2d550::HullFace *)(s))));
    }
    __m128* p1 = s->unk10;
    unk60[0] = p1[1];
    unk64[0] = p1[2];
    __m128* p2 = s->unk20;
    unk60[1] = p2[1];
    unk64[1] = p2[2];
    __m128* p3 = s->unk30;
    unk60[2] = p3[1];
    unk64[2] = p3[2];
    unk6c = 3;
    S_00df9d90_Out* o = outp.val();
    __m128 w0 = _mm_load_ss(&bary.v[0]);
    __m128 w1 = S_00df9d90_Ss(bary.get(1));
    __m128 w2 = S_00df9d90_Ss(bary.get(2));
    o->unk10 = _mm_add_ps(_mm_add_ps(S_00df9d90_Mul(w1, unk60[1]), S_00df9d90_Mul(w0, unk60[0])),
                          S_00df9d90_Mul(w2, unk60[2]));
    o->unk20 = -s->unk40;
    o->unk00 = _mm_xor_ps(s->unk00, ::DAT_010c44d0);
    return o;
}

// Moved from hkpconvexpenetrationutil_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).
#include <cmath>
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_010c9000.h"

extern "C" void _ReadWriteBarrier();
extern "C" void _ReadBarrier();
#include <math.h>

struct Scalar
{
    __m128 v;
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, v);
        return f;
    }
};
struct Vector
{
    union
    {
        __m128 v;
        float f[4];
    };
    __forceinline void operator=(const Vector& b)
    {
        v = b.v;
    }
    __forceinline void sub(const Vector& a, const Vector& b)
    {
        v = _mm_sub_ps(a.v, b.v);
    }
    __forceinline Scalar dot(const Vector& b) const
    {
        __m128 t = _mm_mul_ps(v, b.v);
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(t, t, 0x55), t);
        Scalar s;
        s.v = _mm_add_ss(_mm_shuffle_ps(t, t, 0xaa), xy);
        return s;
    }
    __forceinline Scalar sum() const
    {
        __m128 xy = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
        Scalar s;
        s.v = _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), xy);
        return s;
    }
    __forceinline void cross(const Vector& a, const Vector& b)
    {
        __m128 x = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xc9), _mm_shuffle_ps(b.v, b.v, 0xd2));
        __m128 y = _mm_mul_ps(_mm_shuffle_ps(a.v, a.v, 0xd2), _mm_shuffle_ps(b.v, b.v, 0xc9));
        v = _mm_sub_ps(x, y);
    }
    __forceinline void normalize()
    {
        __m128 half = _mm_set_ss(0.5f);
        __m128 three = _mm_set_ss(3.0f);
        __m128 zero = _mm_set_ss(0.0f);
        __m128 len = dot(*this).v;
        __m128 eq = _mm_cmpeq_ss(len, zero);
        __m128 inv = _mm_rsqrt_ss(len);
        __m128 factor = _mm_mul_ss(_mm_mul_ss(half, inv), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len, inv), inv)));
        factor = _mm_andnot_ps(eq, factor);
        v = _mm_mul_ps(_mm_shuffle_ps(factor, factor, 0), v);
    }
};
struct Support
{
    Vector c, a, b;
    int flag;
};
struct Output
{
    Vector direction, point;
    float distance;
};
struct Host
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Vector v30;
    float f40;
    int unk44;
    int unk48;
    int unk4c;
    float thresh;
    const void* m_shapeA;
    const void* m_shapeB;
    int unk5c;
    Vector* mat;
    Vector* m_verticesB;
    Vector* pts;
    int feat;
    void PushVectorTriple(const Support* support);
    int FUN_00df9fe0(Output* out, int* pfeat);
};

static inline float absScalar(float v)
{
    return fabsf(v);
}
static __forceinline void makePerp(const Vector& edge, Vector& perp)
{
    int idx = 0, other = 1, sel = 2;
    float a0 = absScalar(edge.f[0]);
    float a1 = absScalar(edge.f[1]);
    float a2 = absScalar(edge.f[2]);
    if (a1 < a0)
    {
        other = 0;
        idx = 1;
        a0 = a1;
    }
    if (a2 < a0)
    {
        sel = idx;
        idx = 2;
    }
    perp.v = _mm_setzero_ps();
    perp.f[other] = edge.f[sel];
    perp.f[sel] = -edge.f[other];
}
// @fnv 0x00df9fe0
int Host::FUN_00df9fe0(Output* out, int* pfeat)
{
    const Vector* point;
    int best = -1;
    Vector normal, initial, scratch;
    Support support, support2;
    switch (feat)
    {
    case 0:
        goto stage0;
    case 1:
        goto stage1;
    case 2:
        goto stage2;
    case 3:
        goto stage3;
    case 4:
        goto stage4;
    default:
        goto failedDefault;
    }
stage4: {
    Vector e1, e2, d;
    e1.sub(pts[0], pts[1]);
    e2.sub(pts[1], pts[2]);
    normal.cross(e1, e2);
    float len = normal.dot(normal);
    d.sub(pts[3], pts[0]);
    float dot = normal.dot(d);
    float prod = thresh * len;
    if (dot * dot <= prod)
    {
        if (best < 3)
        {
            feat = 3;
            goto stage3;
        }
        *pfeat = 3;
        _ReadWriteBarrier();
        return 1;
    }
    *pfeat = 0;
    _ReadWriteBarrier();
    return 0;
}
stage3: {
    Vector e1, e2;
    e1.sub(pts[0], pts[1]);
    e2.sub(pts[1], pts[2]);
    normal.cross(e1, e2);
    float len = normal.dot(normal);
    if (len == 0.0f)
    {
        int two = 2;
        if (best < two)
        {
            feat = two;
            goto stage2;
        }
        goto outLine;
    }
    goto triangleSupport;
}
stage2: {
    Vector e;
    e.sub(pts[0], pts[1]);
    float len = e.dot(e);
    if (!(len <= thresh))
        goto lineSupport;
}
    if (best < 1)
    {
        feat = 1;
        goto stage1;
    }
    *pfeat = 3;
    return 1;
stage1: {
    point = pts;
    float len = point[0].dot(point[0]);
    if (!(len <= thresh))
        goto pointSupport;
}
    if (best < 0)
    {
        feat = 0;
        goto stage0;
    }
    *pfeat = 3;
    return 1;
stage0: {
    Scalar simdLen = v30.dot(v30);
    _ReadBarrier();
    float lv = simdLen;
    {
        __m128 mask = DAT_010c44d0;
        __m128 v = v30.v;
        initial.v = _mm_xor_ps(v, mask);
    }
    if (lv <= thresh)
        initial.v = ::DAT_01268380;
    reinterpret_cast<::hkpMinkowskiDF9B *>(this)->FUN_00df9b50((*(const ::hkVector4DF9B *)(&initial)), (*(::hkpCdVertexPairDF9B *)(&support)));
    PushVectorTriple(&support);
    point = pts;
    float nextLen = point[0].dot(point[0]);
    if (nextLen <= thresh)
        goto outPoint;
    best = 0;
    goto stage1;
}
pointSupport: {
    point = pts;
    best = 1;
    reinterpret_cast<::hkpMinkowskiDF9B *>(this)->FUN_00df9b50((*(const ::hkVector4DF9B *)(point)), (*(::hkpCdVertexPairDF9B *)(&support2)));
    Vector delta, negative;
    delta.sub(support2.c, pts[0]);
    float distance = delta.dot(delta);
    negative.v = _mm_xor_ps(point->v, DAT_010c44d0);
    reinterpret_cast<::hkpMinkowskiDF9B *>(this)->FUN_00df9b50((*(const ::hkVector4DF9B *)(&negative)), (*(::hkpCdVertexPairDF9B *)(&support)));
    Vector delta2;
    delta2.sub(support.c, pts[0]);
    float distance2 = delta2.dot(delta2);
    if (distance >= distance2)
    {
        PushVectorTriple(&support2);
        goto stage2;
    }
    PushVectorTriple(&support);
    goto stage2;
}
lineSupport: {
    Vector perp, second;
    scratch.sub(pts[0], pts[1]);
    best = 2;
    makePerp(scratch, perp);
    second.cross(scratch, perp);
    perp.normalize();
    second.normalize();
    float d1, d2;
    reinterpret_cast<::S00df9ef0_Obj *>(this)->FUN_00df9ef0((::S00df9ef0_Vec4 *)(&perp), reinterpret_cast<const ::S00df9ef0_Vec4 *>(pts), (::S00df9ef0_Hit *)(::Support *)(&support), &d1);
    reinterpret_cast<::S00df9ef0_Obj *>(this)->FUN_00df9ef0((::S00df9ef0_Vec4 *)(&second), reinterpret_cast<const ::S00df9ef0_Vec4 *>(pts), (::S00df9ef0_Hit *)(::Support *)(&support2), &d2);
    if (d1 > d2)
    {
        PushVectorTriple(&support);
        goto stage3;
    }
    PushVectorTriple(&support2);
    goto stage3;
}
triangleSupport: {
    best = 3;
    normal.normalize();
    float distance;
    reinterpret_cast<::S00df9ef0_Obj *>(this)->FUN_00df9ef0((::S00df9ef0_Vec4 *)(&normal), reinterpret_cast<const ::S00df9ef0_Vec4 *>(pts), (::S00df9ef0_Hit *)(::Support *)(&support), &distance);
    if (distance < f40)
        goto outTriangle;
    PushVectorTriple(&support);
    goto stage4;
}
outPoint: {
    const Vector* finalPoint = pts;
    Scalar len;
    len.v = _mm_sqrt_ss(finalPoint[0].dot(finalPoint[0]).v);
    out->distance = len;
    out->direction = initial;
    out->point = support.a;
    *pfeat = 0;
    _ReadWriteBarrier();
    return 1;
}
outLine: {
    out->distance = 0.0f;
    Vector edge;
    edge.sub(pts[0], pts[1]);
    makePerp(edge, out->direction);
    out->direction.normalize();
    Vector ab;
    ab.v = _mm_and_ps(pts[0].v, DAT_01017d10);
    float s = ab.sum(), u = ab.sum();
    float t = s / (s + u + ::DAT_010c9300);
    __m128 ts = _mm_load_ss(&t);
    ts = _mm_shuffle_ps(ts, ts, 0);
    out->point.v = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, ts), mat[0].v), _mm_mul_ps(mat[1].v, ts));
    *pfeat = 0;
    _ReadWriteBarrier();
    return 1;
}
outTriangle: {
    out->distance = 0.0f;
    out->direction = normal;
    const S00cd7530_Vec* corners = reinterpret_cast<const S00cd7530_Vec*>(pts);
    FUN_00cd7530(reinterpret_cast<const S00cd7530_Vec*>(&::DAT_01267e30), &corners[0], &corners[1], &corners[2], scratch.f);
    __m128 c0 = _mm_load_ss(&scratch.f[0]);
    __m128 c1, c2;
    {
        float y = scratch.f[1];
        c1 = _mm_load_ss(&y);
    }
    {
        float z = scratch.f[2];
        c2 = _mm_load_ss(&z);
    }
    __m128 t1 = _mm_mul_ps(_mm_shuffle_ps(c1, c1, 0), mat[1].v);
    __m128 t0 = _mm_mul_ps(_mm_shuffle_ps(c0, c0, 0), mat[0].v);
    __m128 t2 = _mm_mul_ps(_mm_shuffle_ps(c2, c2, 0), mat[2].v);
    out->point.v = _mm_add_ps(_mm_add_ps(t1, t0), t2);
    *pfeat = 0;
    _ReadWriteBarrier();
    return 1;
}
failedDefault:
    *pfeat = 3;
    return 1;
}
// Moved below the stand-in views it uses (VEGAS-15).
// @fnv 0x00dfaba0
int FUN_00dfaba0(const hkTransform* transform, Arg1* arg1, Arg2** arg2, int count, const hkTransform* arg4,
                 OutItem** arg5)
{
    WorkArray storage;
    hkMemoryRouter& router = hkMemoryRouter::getInstance();
    storage.data = static_cast<Item*>(static_cast<void*>(router.m_stackCurrent));
    router.m_stackCurrent += (count * sizeof(Item) + 127) & ~127;
    Item* buffer = storage.begin();

    LocalStruct70 local_s;
    hkVector4 out_vec;

    {
        int arr[2];
        int workId = 0;
        for (int i = 0; i < count; ++i)
        {
            Item* item = &storage[workId];
            item->m_arg2_copy = arg2[i];
            item->m_arg5 = arg5[i];
            item->init(arg1, arg2[i], *arg4, 0.0001f, item->m_vec70, item->m_vecB0, item->m_vecF0, 0);

            if (reinterpret_cast<::Host *>((item))->FUN_00df9fe0((::Output *)(::LocalStruct70 *)(&local_s), arr) == 1)
            {
                count--;
            }
            else
            {
                Item* p = item;
                ++workId;
                reinterpret_cast<::Obj *>(&(p->m_obj))->SetEntries(p->m_vec70, p->m_vecB0, p->m_vecF0);
            }
        }

        if (count > 2)
        {
            count = 2;
        }
        else if (count < 2)
        {
            hkMemoryRouter::getInstance().m_stackCurrent = static_cast<char*>(static_cast<void*>(buffer));
            return 1;
        }

        arr[0] = 0;
        arr[1] = 0;

        bool flag;
        do
        {
            FUN_00e2d6c0(&buffer[0].m_obj, &buffer[1].m_obj, &out_vec, &buffer[0].m_nearest, &buffer[1].m_nearest);
            flag = false;
            Item* pItem = buffer;
            for (int i = 0; i < count; ++i, ++pItem)
            {
                if (arr[i] == 2 || pItem->m_obj.m_num < 55)
                {
                    continue;
                }
                Entry* entry = pItem->m_obj.allocEntry();
                reinterpret_cast<::hkpMinkowskiDF9B *>((pItem))->FUN_00df9b50(*reinterpret_cast<const ::hkVector4DF9B *>(pItem->m_nearest), (*(::hkpCdVertexPairDF9B *)(entry)));
                if (reinterpret_cast<::Tester *>((pItem))->FUN_00df9c90((::Shape *)&(pItem->m_obj), reinterpret_cast<const ::Tri *>(pItem->m_nearest), (const ::Vec4 *)(entry), &arr[i]) == 1)
                {
                    if (arr[i] == 3)
                    {
                        hkMemoryRouter::getInstance().m_stackCurrent = static_cast<char*>(static_cast<void*>(buffer));
                        return 1;
                    }
                }
                else
                {
                    flag = true;
                }
            }
        } while (flag);
    }

    float neg_w = -out_vec.w;
    hkVector4 neg_vec_v;
    neg_vec_v = out_vec;
    __m128 neg_vec = _mm_xor_ps(*(__m128*)&neg_vec_v, ::DAT_010c44d0);
    float f10 = arg1->float10;

    Item* pItem = buffer;
    for (int i = 0; i < count; ++i, ++pItem)
    {
        reinterpret_cast<::S_00df9d90_This *>(pItem)->FUN_00df9d90(
            S_00df9d90_OwnerP{reinterpret_cast<::S_00df9d90_Owner *>(&pItem->m_obj)},
            reinterpret_cast<::S_00df9d90_Src *>(pItem->m_nearest), S_00df9d90_OutP{reinterpret_cast<::S_00df9d90_Out *>(&local_s)});

        __m128 normal_y;
        __m128 normal_x, normal_z;
        normal_y = _mm_shuffle_ps(neg_vec, neg_vec, 0x55);
        normal_z = _mm_shuffle_ps(neg_vec, neg_vec, 0xAA);
        normal_x = _mm_shuffle_ps(neg_vec, neg_vec, 0x00);
        *(__m128*)&pItem->m_arg5->direction =
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_load_ps((const float*)&normal_y), *(__m128*)&transform->m_rotation[1]),
                                  _mm_mul_ps(normal_x, *(__m128*)&transform->m_rotation[0])),
                       _mm_mul_ps(_mm_load_ps((const float*)&normal_z), *(__m128*)&transform->m_rotation[2]));

        __m128 pt_y = _mm_mul_ps(_mm_shuffle_ps(*(__m128*)&local_s.m_v1, *(__m128*)&local_s.m_v1, 0x55),
                                 *(__m128*)&transform->m_rotation[1]);
        __m128 pt_x = _mm_mul_ps(_mm_shuffle_ps(*(__m128*)&local_s.m_v1, *(__m128*)&local_s.m_v1, 0x00),
                                 *(__m128*)&transform->m_rotation[0]);
        __m128 pt_z = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128*)&local_s.m_v1, *(__m128*)&local_s.m_v1, 0xAA),
                                            *(__m128*)&transform->m_rotation[2]),
                                 *(__m128*)&transform->m_vTranslation);
        float w = neg_w - f10 - pItem->m_arg2_copy->getRadius();
        *(__m128*)&pItem->m_arg5->point = _mm_add_ps(_mm_add_ps(pt_y, pt_x), pt_z);
        pItem->m_arg5->direction.w = w;
    }

    hkMemoryRouter::getInstance().m_stackCurrent = static_cast<char*>(static_cast<void*>(buffer));
    return 0;
}

double FUN_00df9ae0();

struct S00dfa940_Solver
{
    hkTransform m_transform;
    __m128 m_tolerance;
    float m_toleranceSq;
    const void* m_shapeA;
    const void* m_shapeB;
    int m_5c;
    const hkVector4* m_60;
    const hkVector4* m_64;
    const hkVector4* m_68;
    int m_6c;

    // Same field setup as Item::init.
    void init(const void* shapeA, const void* shapeB, const hkTransform& transform, float epsilon,
              const hkVector4* verticesA, const hkVector4* verticesB, const hkVector4* differences, int count)
    {
        m_transform = transform;
        m_tolerance = _mm_set_ps1(epsilon);
        m_toleranceSq = epsilon * epsilon;
        m_shapeA = shapeA;
        m_shapeB = shapeB;
        m_5c = 0;
        m_60 = verticesA;
        m_64 = verticesB;
        m_68 = differences;
        m_6c = count;
    }

    int FUN_00dfa940(Output* out);
};

// Loops building simplex entries until FUN_00df9fe0/FUN_00df9c90 give a result; on result 3 retries up to 0x14 times, adding an offset to m_30; returns status.
// @fnv 0x00dfa940
int S00dfa940_Solver::FUN_00dfa940(Output* out)
{
    S00dfa940_Simplex simplex;
    hkVector4 tmp;
    int res;
    DFB0B0_Entry* nearest;
    int ret;
    S00dfa940_Entry* e;

    for (;;)
    {
        res = 0;
        if (reinterpret_cast<::Host *>(this)->FUN_00df9fe0(out, &res) == 1)
        {
            ret = res;
            if (ret != 3)
                goto out;
        }
        else
        {
            reinterpret_cast<::Obj *>(&(simplex))->SetEntries(m_60, m_64, m_68);
            nearest = reinterpret_cast<::DFB0B0_Owner *>(&(simplex))->GetNearestEntry();
            e = &simplex.m_usTrailingValue[simplex.m_num++];
            e->m_flag = 0;
            reinterpret_cast<::hkpMinkowskiDF9B *>(this)->FUN_00df9b50(*reinterpret_cast<const ::hkVector4DF9B *>(nearest), *reinterpret_cast<::hkpCdVertexPairDF9B *>(e));
            if (reinterpret_cast<::Tester *>(this)->FUN_00df9c90((::Shape *)(::S00dfa940_Simplex *)(&simplex), reinterpret_cast<const ::Tri *>(nearest), (const ::Vec4 *)(e), &res) != 1)
            {
                for (;;)
                {
                    int n = simplex.m_num;
                    if (n >= 0x37)
                    {
                        ret = 2;
                        goto done;
                    }
                    nearest = reinterpret_cast<::DFB0B0_Owner *>(&(simplex))->GetNearestEntry();
                    simplex.m_num++;
                    e = &simplex.m_usTrailingValue[n];
                    e->m_flag = 0;
                    reinterpret_cast<::hkpMinkowskiDF9B *>(this)->FUN_00df9b50(*reinterpret_cast<const ::hkVector4DF9B *>(nearest), *reinterpret_cast<::hkpCdVertexPairDF9B *>(e));
                    if (reinterpret_cast<::Tester *>(this)->FUN_00df9c90((::Shape *)(::S00dfa940_Simplex *)(&simplex), reinterpret_cast<const ::Tri *>(nearest), (const ::Vec4 *)(e), &res) == 1)
                        break;
                }
            }
            ret = res;
            if (ret != 3)
                goto done;
        }
        if (++m_5c == 1)
        {
            m_6c = 1;
            continue;
        }
        if (m_5c >= 0x14)
            goto out;
        m_6c = 0;
        float f = (float)((FUN_00df9ae0() - ::DAT_01032980) * DAT_010dbb40);
        tmp.x = f;
        tmp.y = f;
        tmp.z = f;
        *(__m128*)&tmp = _mm_add_ps(*(__m128*)&m_transform.m_vTranslation, *(__m128*)&tmp);
        m_transform.m_vTranslation = tmp;
    }
done:
    reinterpret_cast<::S_00df9d90_This *>(this)->FUN_00df9d90(
        S_00df9d90_OwnerP{reinterpret_cast<::S_00df9d90_Owner *>(&simplex)}, reinterpret_cast<::S_00df9d90_Src *>(nearest),
        S_00df9d90_OutP{reinterpret_cast<::S_00df9d90_Out *>(out)});
out:
    return ret;
}

struct S_00dfaac0_Transform
{
    float m[16];
};

struct S_00dfaac0_Penetration : S00dfa940_Solver
{
    S_00dfaac0_Penetration(const ::S2db70_Shape* shapeA, const ::S2db70_Shape* shapeB, const S_00dfaac0_Transform& t,
                           float epsilon, ::S2db70_Vector4* verticesA, ::S2db70_Vector4* verticesB,
                           ::S2db70_Vector4* differences, int count)
    {
        init(shapeA, shapeB, reinterpret_cast<const hkTransform&>(t), epsilon, reinterpret_cast<const hkVector4*>(verticesA),
             reinterpret_cast<const hkVector4*>(verticesB), reinterpret_cast<const hkVector4*>(differences), count);
    }
};


// Constructs a Penetration object and calls FUN_00dfa940; if it returns 3, calls FUN_00e2db70 and returns 1, otherwise returns the original result.
// @fnv 0x00dfaac0
int __cdecl TestPenetration(const ::S2db70_Shape* a, const ::S2db70_Shape* b, const S_00dfaac0_Transform& t, float f,
                            ::S2db70_Vector4* c, ::S2db70_Vector4* d, ::S2db70_Vector4* e, int g, ::S2db70_Out* out)
{
    S_00dfaac0_MonitorStream::GetMonitorStream().timer("TtPenetration");
    S_00dfaac0_Penetration penetration(a, b, t, f, c, d, e, g);
    int result = penetration.FUN_00dfa940(reinterpret_cast<::Output *>(out));
    if (result == 3)
    {
        ::FUN_00e2db70(a, b, reinterpret_cast<const ::S2db70_Transform &>(t), *c, *d, *out);
        result = 1;
    }
    S_00dfaac0_MonitorStream::GetMonitorStream().timer("Et");
    return result;
}

#include "generated/data/havok/physics/internal/collide/gjk/penetration/hkpconvexpenetrationutil.inc"
