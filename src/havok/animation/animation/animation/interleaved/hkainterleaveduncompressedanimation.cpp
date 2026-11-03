
// src/havok/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/interleaved/hkainterleaveduncompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_simd.h"
#include "fnv/decl/FUN_005611c0_t.h"
#include "fnv/symbols_00c85000.h"
#include <windows.h>
#include "fnv/decl/FUN_00e2f7c0_Class.h"
#include "fnv/symbols_00e3f000.h"
#include "fnv/symbols_01268000.h"
#include "havok/hkaInterleavedUncompressedAnimation.h"

struct FUN_00e3f950_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int FUN_00e3f950(int a, int b);
};

// @fnv 0x00e3f950
int FUN_00e3f950_class::FUN_00e3f950(int aiUnused1, int aiUnused2)
{
    int result = 1;
    if (m_10 > 0)
        result = 2;
    if (m_14 > 0)
        ++result;
    return result;
}

struct FUN_00e3f970_class
{
    int FUN_00e3f970();
};
// @fnv 0x00e3f970
int FUN_00e3f970_class::FUN_00e3f970()
{
    int* p = (int*)this;
    int a = p[5];
    int b = p[4];
    return (((a * 8 + 31) & ~15) + b * 3 * 32 + 64);
}

struct FUN_00e3f990_class
{
    int GetRatio();
};

// @fnv 0x00e3f990
int FUN_00e3f990_class::GetRatio()
{
    if (*(int*)((char*)this + 0x10))
        return *(int*)((char*)this + 0x2c) / *(int*)((char*)this + 0x10);
    return *(int*)((char*)this + 0x38) / *(int*)((char*)this + 0x14);
}

struct FUN_00e3f920_class
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FUN_00e3f920(float, int, int, int);
};
// Invokes virtual function at offset 0x10 passing a, m_10, b, m_14, c, d.
// @fnv 0x00e3f920
void FUN_00e3f920_class::FUN_00e3f920(float afValue, int b, int c, int d)
{
    ((void(*)(void*, float, int, int, int, int, int))(*reinterpret_cast<void***>(this))[4])(
        this, afValue, *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x10), b,
        *reinterpret_cast<int*>(reinterpret_cast<unsigned char*>(this) + 0x14), c, d);
}

struct S00e3fb60_Anim : public hkaInterleavedUncompressedAnimation
{
    void FUN_00e2f7c0(float time, int& frameIndex, float& weight) const;
    void FUN_00e3fb60(float time, const short* tracks, int numTracks, float* out);
};

__declspec(noinline) void S00e3fb60_Anim::FUN_00e2f7c0(float time, int& frameIndex, float& weight) const
{
    unsigned int numPoses = m_kTransforms.m_iElementCount / m_iNumTransformTracks;
    float f = (time / m_fAnimationDuration) * (float)(numPoses - 1);
    unsigned int i = (unsigned int)f;
    frameIndex = i;
    weight = f - (float)i;
}

// Interpolates float animation tracks between two frames at the given time, writing results to out.
// @fnv 0x00e3fb60
void S00e3fb60_Anim::FUN_00e3fb60(float time, const short* tracks, int numTracks, float* out)
{
    int frameIndex;
    FUN_00e2f7c0(time, frameIndex, time);
    float invWeight = 1.0f - time;
    for (unsigned int i = 0; i < (unsigned int)numTracks; ++i)
    {
        short track = tracks[i];
        if (track >= 0)
        {
            int n = m_iNumberOfFloatTracks;
            if (track < n)
            {
                const float* frame0 = &m_kFloats.m_data[frameIndex * n];
                out[i] = frame0[track + n] * time + frame0[track] * invWeight;
            }
        }
    }
}

struct S00e3fd20_Desc
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    void FUN_00e3fd20(int scale, int unused1, int* out, int unused2);
};

// Writes a descriptor into out, storing this pointer, a 0x40 size, and optional segment and alignment data based on m_10 and m_14.
// @fnv 0x00e3fd20
void S00e3fd20_Desc::FUN_00e3fd20(int scale, int unused1, int* out, int unused2)
{
    out[0] = (int)this;
    out[1] = 0x40;

    int segment = 1;

    if (m_10 > 0)
    {
        out[3] = m_10 * scale * 0x30 + m_28;
        out[4] = m_10 * 0x60;
        segment = 2;
    }

    if (m_14 > 0)
    {
        int* descriptor = out + segment * 3;
        int count = *(volatile int*)&m_14;

        unsigned int address = (unsigned int)m_34 + count * scale * 4;
        unsigned char offset = (unsigned char)address;
        offset &= 0xf;
        address &= 0xfffffff0;

        descriptor[0] = (int)address;
        *((unsigned char*)descriptor + 8) = offset;
        descriptor[1] = (int)((offset + count * 8 + 0xf) & 0xfffffff0);
    }
}

#include <xmmintrin.h>
struct QsTransformX
{
    __m128 m_vTranslation, m_rotation, m_vScale;
};
struct XformArrayX
{
    QsTransformX* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    XformArrayX() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000)
    {}
};
struct FloatArrayX
{
    float* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    FloatArrayX() : m_data(0), m_iElementCount(0), m_iCapacityState((int)0x80000000)
    {}
};

struct SrcAnimX
{
    void* m_vfptr;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_type;
    float m_fAnimationDuration;
    int m_iNumTransformTracks;
    int m_iNumberOfFloatTracks;
    void* m_pExtractedMotion;
    void* m_annotData;
    int m_annotSize;
    int m_annotCapacityAndFlags;
    XformArrayX m_kTransforms;
    FloatArrayX m_kFloats;
};

class HeapMgrX
{
  public:
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void* AllocateBufferWithSize(int* numBytes)
    {
        return 0;
    }
    virtual void ReturnMemory(void* data, int numBytes)
    {}
};

struct AudioSvcX
{
    int m_00, m_04, m_08, m_0c;
    HeapMgrX* m_pStreamAllocator;
};

class BaseAnimX
{
  public:
    BaseAnimX(SrcAnimX* src);
};

class FUN_00e402e0 : public BaseAnimX
{
  public:
    FUN_00e402e0(SrcAnimX* src);
    void* m_vfptr;
    int m_unk04, m_unk08, m_unk0c, m_unk10, m_unk14, m_unk18, m_unk1c, m_unk20, m_unk24;
    XformArrayX m_kTransforms;
    FloatArrayX m_kFloats;
};

void* FUN_00c85750();
extern int DAT_010e5474;

// Copies transform and float track arrays from src into m_kTransforms and m_kFloats, resizing via the audio service heap manager when capacity is insufficient.
// @fnv 0x00e402e0
FUN_00e402e0::FUN_00e402e0(SrcAnimX* apSrcAnim)
    : BaseAnimX(apSrcAnim), m_vfptr((void*)&DAT_010e5474), m_kTransforms(), m_kFloats()
{
    {
        HeapMgrX* pHeapMgr = ((AudioSvcX*)FUN_00c85750())->m_pStreamAllocator;
        int iCapacity = m_kTransforms.m_iCapacityState & 0x3FFFFFFF;
        if (iCapacity < apSrcAnim->m_kTransforms.m_iElementCount)
        {
            if ((m_kTransforms.m_iCapacityState & 0x80000000) == 0)
                pHeapMgr->ReturnMemory(m_kTransforms.m_data, iCapacity * 48);
            int numBytes = apSrcAnim->m_kTransforms.m_iElementCount * 48;
            m_kTransforms.m_data = (QsTransformX*)pHeapMgr->AllocateBufferWithSize(&numBytes);
            m_kTransforms.m_iCapacityState = numBytes / 48;
        }
        int iNumTransforms = apSrcAnim->m_kTransforms.m_iElementCount;
        m_kTransforms.m_iElementCount = iNumTransforms;
        QsTransformX* pDstTransforms = m_kTransforms.m_data;
        const QsTransformX* s = apSrcAnim->m_kTransforms.m_data;
        for (int i = 0; i < iNumTransforms; i++)
        {
            pDstTransforms[i].m_vTranslation = s[i].m_vTranslation;
            pDstTransforms[i].m_rotation = s[i].m_rotation;
            pDstTransforms[i].m_vScale = s[i].m_vScale;
        }
    }
    {
        HeapMgrX* pHeapMgr = ((AudioSvcX*)FUN_00c85750())->m_pStreamAllocator;
        int iCapacity = m_kFloats.m_iCapacityState & 0x3FFFFFFF;
        if (iCapacity < apSrcAnim->m_kFloats.m_iElementCount)
        {
            if ((m_kFloats.m_iCapacityState & 0x80000000) == 0)
                pHeapMgr->ReturnMemory(m_kFloats.m_data, iCapacity * 4);
            int numBytes = apSrcAnim->m_kFloats.m_iElementCount * 4;
            m_kFloats.m_data = (float*)pHeapMgr->AllocateBufferWithSize(&numBytes);
            m_kFloats.m_iCapacityState = numBytes / 4;
        }
        int iNumFloats = apSrcAnim->m_kFloats.m_iElementCount;
        m_kFloats.m_iElementCount = iNumFloats;
        const float* s = apSrcAnim->m_kFloats.m_data;
        float* pDstTransforms = m_kFloats.m_data;
        for (int i = 0; i < iNumFloats; i++)
            pDstTransforms[i] = s[i];
    }
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
typedef void*(* TlsGetValueFn)(unsigned long);

struct ProfRec
{
    const char* m_pName;
    unsigned int m_iTick;
    unsigned int unk08;
};

struct ProfBuf
{
    int unk00;
    ProfRec* m_pCur;
    int unk08;
    ProfRec* m_pRecordEnd;
};

struct QsTm
{
    __m128 t;
    __m128 r;
    __m128 s;
};
struct QsT
{
    float v[12];
};
struct SampleRec
{
    int a;
    int b;
    char c;
};

inline SampleRec* S00e3ffc0_zero(SampleRec* recs)
{
    recs[0].a = 0;
    recs[0].b = 0;
    recs[0].c = 0;
    recs[1].a = 0;
    recs[1].b = 0;
    recs[1].c = 0;
    recs[2].a = 0;
    recs[2].b = 0;
    recs[2].c = 0;
    return recs;
}
struct FUN_00e2f7c0_Obj
{
};
__forceinline int S00e3ffc0_getFrame(FUN_00e2f7c0_Obj* o, float t, float* d)
{
    int f;
    reinterpret_cast<::FUN_00e2f7c0_Class *>((o))->FUN_00e2f7c0(t, (unsigned int *)(int *)(&f), d);
    return f;
}

struct hkaAnimSlot : hkaInterleavedUncompressedAnimation
{
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void SampleIndividualTracks(int frame, float delta, SampleRec* recs, int n);
    void FUN_00e3ffc0(float time, unsigned int nT, QsT* tOut, unsigned int nF, float* fOut, int a6);
};

// Samples the animation into tOut and fOut, using the last frame when time is at or beyond the animation duration.
// @fnv 0x00e3ffc0
void hkaAnimSlot::FUN_00e3ffc0(float time, unsigned int nT, QsT* tOut, unsigned int nF, float* fOut, int a6)
{
    TlsGetValueFn pfnTlsGetValue = &TlsGetValue;
    union
    {
        volatile unsigned int tick;
        float delta;
    } u;
    {
        ProfBuf* pProfLog = (ProfBuf*)pfnTlsGetValue(DAT_0126835c);
        ProfRec* pCurRec = pProfLog->m_pCur;
        if (pCurRec < pProfLog->m_pRecordEnd)
        {
            pCurRec->m_pName = "TtsamplePose";
            _ReadWriteBarrier();
            u.tick = (unsigned int)__rdtsc();
            pCurRec->m_iTick = u.tick;
            pProfLog->m_pCur = pCurRec + 1;
        }
    }
    if (time >= m_fAnimationDuration)
    {
        for (unsigned int i = 0; i < nT; ++i)
        {
            const QsTm* s = (const QsTm*)m_kTransforms.m_data + (m_kTransforms.m_iElementCount - m_iNumTransformTracks + i);
            QsTm* d = (QsTm*)tOut + i;
            d->t = s->t;
            d->r = s->r;
            d->s = s->s;
        }
        for (unsigned int iFloat = 0; iFloat < nF; ++iFloat)
            fOut[iFloat] = m_kFloats.m_data[m_kFloats.m_iElementCount - m_iNumberOfFloatTracks + iFloat];
        {
            ProfBuf* pProfLog = (ProfBuf*)pfnTlsGetValue(DAT_0126835c);
            ProfRec* pCurRec = pProfLog->m_pCur;
            if (pCurRec < pProfLog->m_pRecordEnd)
            {
                pCurRec->m_pName = "Et";
                _ReadWriteBarrier();
                u.tick = (unsigned int)__rdtsc();
                pCurRec->m_iTick = u.tick;
                pProfLog->m_pCur = pCurRec + 1;
            }
        }
        return;
    }
    {
        int frame = S00e3ffc0_getFrame((FUN_00e2f7c0_Obj*)this, time, &u.delta);
        SampleRec recs[3];
        SampleIndividualTracks(frame, u.delta, S00e3ffc0_zero(recs), 3);
        ::FUN_00e3fda0(frame, u.delta, nT, (::hkQsTransform *)(tOut), nF, fOut, (const ::DataChunk *)(recs), 3);
    }
    {
        ProfBuf* pProfLog = (ProfBuf*)pfnTlsGetValue(DAT_0126835c);
        ProfRec* pCurRec = pProfLog->m_pCur;
        if (pCurRec < pProfLog->m_pRecordEnd)
        {
            pCurRec->m_pName = "Et";
            _ReadWriteBarrier();
            u.tick = (unsigned int)__rdtsc();
            pCurRec->m_iTick = u.tick;
            pProfLog->m_pCur = pCurRec + 1;
        }
    }
}

class hkQuaternionE40;

class hkVector4E40
{
  public:
    __m128 m_vComponents;

    __forceinline hkVector4E40& operator=(const hkVector4E40& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }

    __forceinline void setAdd4(const hkVector4E40& a, const hkVector4E40& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4E40& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void setMul4(const hkVector4E40& a, const hkVector4E40& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void addMul4(const hkVector4E40& a, const hkVector4E40& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void addMul4(__m128 s, const hkVector4E40& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4E40& a)
    {
        m_vComponents = _mm_xor_ps(a.m_vComponents, ::DAT_010c44d0);
    }
    __forceinline void setCross(const hkVector4E40& v1, const hkVector4E40& v2)
    {
        __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                   _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline __m128 dot3(const hkVector4E40& v) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, v.m_vComponents);
        __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)), sum);
    }
    __forceinline void setReciprocal4(const hkVector4E40& v)
    {
        __m128 r = _mm_rcp_ps(v.m_vComponents);
        __m128 rr = _mm_mul_ps(_mm_mul_ps(r, v.m_vComponents), r);
        m_vComponents = _mm_sub_ps(_mm_add_ps(r, r), rr);
    }
    void SetRotatedDirection(const hkQuaternionE40& q, const hkVector4E40& dir);
    void setRotatedInverseDir(const hkQuaternionE40& q, const hkVector4E40& dir);
};

class hkQuaternionE40
{
  public:
    hkVector4E40 m_vec;

    __forceinline void SetConjugate(const hkQuaternionE40& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
    __declspec(noinline) void SetProduct(const hkQuaternionE40& q0, const hkQuaternionE40& q1)
    {
        __m128 a = q0.m_vec.m_vComponents;
        __m128 b = q1.m_vec.m_vComponents;
        __m128 cross = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 1, 0, 2)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 0, 2, 1))),
            _mm_mul_ps(_mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 0, 2, 1)), _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 1, 0, 2))));
        __m128 aw = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 bw = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3, 3, 3, 3));
        __m128 imag = _mm_add_ps(_mm_mul_ps(bw, a), _mm_add_ps(_mm_mul_ps(aw, b), cross));
        __m128 prod = _mm_mul_ps(b, a);
        __m128 dot = _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(2, 2, 2, 2)),
                                _mm_add_ss(_mm_shuffle_ps(prod, prod, _MM_SHUFFLE(1, 1, 1, 1)), prod));
        __m128 real = _mm_sub_ps(prod, _mm_shuffle_ps(dot, dot, 0));
        m_vec.m_vComponents = _mm_shuffle_ps(imag, _mm_unpackhi_ps(imag, real), _MM_SHUFFLE(3, 0, 1, 0));
    }
};

__forceinline void hkVector4E40::SetRotatedDirection(const hkQuaternionE40& quat, const hkVector4E40& direction)
{
    hkVector4E40 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4E40 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4E40 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4E40 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

__forceinline void hkVector4E40::setRotatedInverseDir(const hkQuaternionE40& quat, const hkVector4E40& direction)
{
    hkVector4E40 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    hkVector4E40 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.m_vComponents = _mm_add_ps(q2minus1.m_vComponents, ::DAT_010c71e0);
    hkVector4E40 ret;
    ret.setMul4(direction, q2minus1);
    __m128 imagDotDir = quat.m_vec.dot3(direction);
    ret.addMul4(imagDotDir, quat.m_vec);
    hkVector4E40 imagCrossDir;
    imagCrossDir.setCross(direction, quat.m_vec);
    ret.addMul4(imagCrossDir, qreal);
    setAdd4(ret, ret);
}

class hkQsTransformE40
{
  public:
    hkVector4E40 m_vTranslation;
    hkQuaternionE40 m_rotation;
    hkVector4E40 m_vScale;

    __forceinline void SetConjugate(const hkQsTransformE40& t)
    {
        m_vTranslation.setRotatedInverseDir(t.m_rotation, t.m_vTranslation);
        m_vTranslation.setNeg4(m_vTranslation);
        m_rotation.SetConjugate(t.m_rotation);
        hkVector4E40 s;
        s.m_vComponents = _mm_shuffle_ps(
            t.m_vScale.m_vComponents, _mm_unpackhi_ps(t.m_vScale.m_vComponents, DAT_010c7170), _MM_SHUFFLE(3, 0, 1, 0));
        m_vScale.setReciprocal4(s);
        m_vScale.m_vComponents = _mm_and_ps(m_vScale.m_vComponents, DAT_010c4c10);
    }
    __forceinline void SetProduct(const hkQsTransformE40& t1, const hkQsTransformE40& t2)
    {
        hkVector4E40 temp;
        temp.SetRotatedDirection(t1.m_rotation, t2.m_vTranslation);
        m_vTranslation.setAdd4(temp, t1.m_vTranslation);
        ::fnv_00c66320::FUN_00c66320((__m128 *)&(m_rotation), (void *)&(t1.m_rotation), (const __m128 *)&(t2.m_rotation), {});
        m_vScale.setMul4(t1.m_vScale, t2.m_vScale);
    }
};

class FUN_00e401d0Owner
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iNumTracks;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    hkQsTransformE40* m_pkTransforms;
    int m_iNumTransforms;

    void FUN_00e401d0(int iTrack, const hkQsTransformE40& kTransform);
};

// @fnv 0x00e401d0
void FUN_00e401d0Owner::FUN_00e401d0(int iTrack, const hkQsTransformE40& kTransform)
{
    int iTransformCountPerTrack = m_iNumTransforms / m_iNumTracks;
    for (int i = 0; i < iTransformCountPerTrack; i++)
    {
        int iIndex = m_iNumTracks * i + iTrack;
        hkQsTransformE40 kOld;
        kOld = m_pkTransforms[iIndex];
        m_pkTransforms[iIndex].SetProduct(kTransform, kOld);
    }
}


class S00e3f9b0_SimdReal
{
  public:
    S00e3f9b0_SimdReal(const __m128& x) : m_vValue(x)
    {}
    S00e3f9b0_SimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    S00e3f9b0_SimdReal()
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const __m128& getQuad() const
    {
        return m_vValue;
    }

  private:
    __m128 m_vValue;
};

class S00e3f9b0_Vec4
{
  public:
    __forceinline S00e3f9b0_Vec4()
    {}
    __forceinline S00e3f9b0_Vec4(const S00e3f9b0_Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void operator=(const S00e3f9b0_Vec4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setMul4(const S00e3f9b0_SimdReal& r, const S00e3f9b0_Vec4& v1)
    {
        m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
    }
    __forceinline void addMul4(const S00e3f9b0_SimdReal& r, const S00e3f9b0_Vec4& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    __forceinline void setInterpolate4(const S00e3f9b0_Vec4& v0, const S00e3f9b0_Vec4& v1, const S00e3f9b0_SimdReal& _t)
    {
        __m128 t = _t.broadcast();
        __m128 s = _mm_sub_ps(::DAT_010ec7f0, t);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(v1.m_vComponents, t));
    }
    inline S00e3f9b0_SimdReal dot4(const S00e3f9b0_Vec4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 sum0 = _mm_add_ps(_mm_shuffle_ps(x2, x2, 0x4e), x2);
        __m128 sum1 = _mm_shuffle_ps(sum0, sum0, 0xb1);
        return _mm_add_ps(sum0, sum1);
    }
    __m128 m_vComponents;
};

class S00e3f9b0_Quat
{
  public:
    inline S00e3f9b0_Quat()
    {}
    inline void operator=(const S00e3f9b0_Quat& q)
    {
        m_vec = q.m_vec;
    }
    S00e3f9b0_Vec4 m_vec;
};

class S00e3f9b0_QsT
{
  public:
    __forceinline S00e3f9b0_QsT(const S00e3f9b0_QsT& t)
    {
        m_vTranslation = t.m_vTranslation;
        m_rotation = t.m_rotation;
        m_vScale = t.m_vScale;
    }
    __forceinline void setInterpolate4(const S00e3f9b0_QsT& a, const S00e3f9b0_QsT& b, const S00e3f9b0_SimdReal& t)
    {
        const __m128 ts = t.broadcast();
        m_vScale.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, ts), a.m_vScale.m_vComponents),
                                            _mm_mul_ps(ts, b.m_vScale.m_vComponents));
        m_vTranslation.setInterpolate4(a.m_vTranslation, b.m_vTranslation, t);

        const float oneMinusT = 1.0f - float(t);

        const float signedT = (a.m_rotation.m_vec.dot4(b.m_rotation.m_vec) < 0.0f) ? -t : t;

        S00e3f9b0_Quat out;
        S00e3f9b0_Vec4 v;
        v.setMul4(S00e3f9b0_SimdReal(signedT), b.m_rotation.m_vec);
        v.addMul4(S00e3f9b0_SimdReal(oneMinusT), a.m_rotation.m_vec);
        out.m_vec = v;
        reinterpret_cast<::FUN_005611c0_t *>(&(out))->FUN_005611c0();

        m_rotation = out;
    }
    S00e3f9b0_Vec4 m_vTranslation;
    S00e3f9b0_Quat m_rotation;
    S00e3f9b0_Vec4 m_vScale;
};

struct S00e3f9b0_Anim : public hkaInterleavedUncompressedAnimation
{
    void FUN_00e2f7c0(float time, int& frame, float& delta) const;
    void FUN_00e3f9b0(float time, const short* tracks, unsigned int numTracks, S00e3f9b0_QsT* transformsOut) const;
};

// @fnv 0x00e3f9b0
void S00e3f9b0_Anim::FUN_00e3f9b0(float time, const short* tracks, unsigned int numTracks,
                                  S00e3f9b0_QsT* transformsOut) const
{
    int frame;
    float delta;
    FUN_00e2f7c0(time, frame, delta);

    for (unsigned int i = 0; i < numTracks; ++i)
    {
        const short track = tracks[i];
        if (track < 0 || track >= m_iNumTransformTracks)
        {
            continue;
        }
        const S00e3f9b0_QsT* base = (const S00e3f9b0_QsT*)m_kTransforms.m_data + m_iNumTransformTracks * frame;
        S00e3f9b0_QsT a = base[track];
        S00e3f9b0_QsT b = base[track + m_iNumTransformTracks];
        transformsOut[i].setInterpolate4(a, b, delta);
    }
}

namespace E3fda0Simd {


}struct DataChunk
{
    const unsigned char* m_data;
    unsigned int m_iElementCount;
    unsigned char m_offset;
};

struct Vec4
{
    float x, y, z, w;
};

struct FUN_005611c0_t
{
    float x, y, z, w;
    void FUN_005611c0();
};


inline float scalarValue(__m128 value)
{
    float result;
    _mm_store_ss(&result, value);
    return result;
}

struct VectorLane
{
    union
    {
        __m128 v;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct TransformLane
{
    VectorLane translation, rotation, scale;
};
// @fnv 0x00e3fda0
void FUN_00e3fda0(unsigned int frameIndex, float frameDelta, unsigned int maxNumTransformTracks,
                  hkQsTransform* transformOutArg, int maxNumFloatTracks, float* floatOutArg,
                  const DataChunk* dataChunks, int numDataChunks)
{
    const hkaAnimation* anim = (const hkaAnimation*)dataChunks[0].m_data;
    int chunkIndex = 1;
    if (anim->m_iNumTransformTracks > 0)
    {
        const TransformLane* __restrict pose0 = (const TransformLane*)dataChunks[1].m_data;
        const TransformLane* __restrict pose1 = pose0 + anim->m_iNumTransformTracks;
        if (maxNumTransformTracks > 0)
        {
            TransformLane* transformTracksOut = (TransformLane*)transformOutArg;
            for (unsigned int left = 0; left < maxNumTransformTracks; ++left)
            {
                __m128 invScalar;
                (void)invScalar;

                __m128 tss = _mm_load_ss(&frameDelta);
                __m128 tAll = _mm_shuffle_ps(tss, tss, 0);
                __m128 ones = (*reinterpret_cast<const __m128*>(&::DAT_010ec7f0));
                __m128 inv = _mm_sub_ps(ones, tAll);
                __m128 scale = _mm_add_ps(_mm_mul_ps(inv, pose0->scale.v),
                                                                  _mm_mul_ps(tAll, pose1->scale.v));
                transformTracksOut->scale.v = scale;

                ones = (*reinterpret_cast<const __m128*>(&::DAT_010ec7f0));
                inv = _mm_sub_ps(ones, tAll);
                __m128 trans = _mm_add_ps(_mm_mul_ps(inv, pose0->translation.v),
                                                                  _mm_mul_ps(tAll, pose1->translation.v));
                transformTracksOut->translation.v = trans;

                __m128 r0 = pose0->rotation.v;
                float oneMinus = 1.0f - scalarValue(tss);
                __m128 prod = _mm_mul_ps(r0, pose1->rotation.v);
                prod = _mm_add_ps(_mm_shuffle_ps(prod, prod, 0x4e), prod);
                prod = _mm_add_ps(_mm_shuffle_ps(prod, prod, 0xb1), prod);
                Vec4 pos;
                _mm_store_ps(&pos.x, tss);
                Vec4 neg;
                const Vec4* picked;
                if (scalarValue(prod) < 0.0f)
                {
                    _mm_store_ps(
                        &neg.x,
                        _mm_sub_ss((*reinterpret_cast<const __m128*>(&DAT_010c7160)), tss));
                    picked = &neg;
                }
                else
                {
                    picked = &pos;
                }
                __m128 chosen = _mm_load_ps(&picked->x);
                float signedT = scalarValue(chosen);
                __m128 signedScalar = _mm_load_ss(&signedT);
                invScalar = _mm_load_ss(&oneMinus);
                __m128 signedAll = _mm_shuffle_ps(signedScalar, signedScalar, 0);
                __m128 invAll = _mm_shuffle_ps(invScalar, invScalar, 0);
                FUN_005611c0_t quat;
                _mm_store_ps(&quat.x,
                                         _mm_add_ps(_mm_mul_ps(signedAll, pose1->rotation.v),
                                                                _mm_mul_ps(invAll, r0)));
                quat.FUN_005611c0();
                transformTracksOut->rotation.v = _mm_load_ps(&quat.x);
                pose0++;
                pose1++;
                transformTracksOut++;
            }
        }
        chunkIndex = 2;
    }
    if (anim->m_iNumberOfFloatTracks > 0)
    {
        const DataChunk* floats = &dataChunks[chunkIndex];
        const float* b;
        (void)b;
        float t;
        (void)t;
        const float* a;
        (void)a;
        float oneMinus;
        (void)oneMinus;
        a = (const float*)(floats->m_data + floats->m_offset);
        b = a + anim->m_iNumberOfFloatTracks;
        t = frameDelta;
        oneMinus = 1.0f - t;
        unsigned int i = 0;
        for (; i < (unsigned int)maxNumFloatTracks; ++i)
        {
            floatOutArg[i] = *a * oneMinus + t * *b;
            a++;
            b++;
        }
    }
}
