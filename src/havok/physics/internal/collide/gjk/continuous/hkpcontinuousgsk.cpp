// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include "fnv/decl/FUN_004b4ab0_Class.h"
#include "fnv/decl/GapSolver.h"
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/symbols_00cf1000.h"
#include "fnv/symbols_010c9000.h"
struct S_00db4b50_B
{
    float unk00;
    int unk04;
    float unk08;
};
struct S_00db4b50_A
{
    char* unk00;
    char* unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S_00db4b50_B* unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
};
struct S_00db4b50_Out
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    float unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
};

struct S_00db4b50_Sub
{
    void FUN_00c7f700(void* p, void* q);
    void FUN_00c7f640(void* p, void* q);
};

__forceinline void S_rotInv(const __m128* r, const __m128* in, int n, __m128* out)
{
    __m128 a0 = r[0], a1 = r[1], a2 = r[2];
    {
        __m128 t0 = _mm_unpacklo_ps(a0, a1);
        __m128 t1 = _mm_unpackhi_ps(a0, a1);
        a0 = _mm_movelh_ps(t0, a2);
        a1 = _mm_shuffle_ps(_mm_movehl_ps(a0, t0), a2, 0xd4);
        a2 = _mm_shuffle_ps(t1, a2, 0xe4);
    }
    for (int i = 0; i < n; i++)
    {
        __m128 v = in[i];
        __m128 s = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), a1), _mm_mul_ps(_mm_shuffle_ps(v, v, 0), a0));
        out[i] = _mm_add_ps(s, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), a2));
    }
}

// Calls FUN_00cf1710 twice using a's two pointers and b's values, fills out via sub-object calls and S_rotInv, and sets out->unkcc to -a->unk14.
// @fnv 0x00db4b50
void FUN_00db4b50(S_00db4b50_A* a, float f, S_00db4b50_Out* out)
{
    S_00db4b50_B* b = a->unk40;
    float t = b->unk08 * f;
    ::fnv_00cf1710::FUN_00cf1710((*(const ::fnv_00cf1710::hkSweptTransformL *)(a->unk00 + 0x40)), b->unk00, t, (*(::fnv_00cf1710::hkTransformL *)(out)));
    ::fnv_00cf1710::FUN_00cf1710((*(const ::fnv_00cf1710::hkSweptTransformL *)(a->unk04 + 0x40)), b->unk00, t, (*(::fnv_00cf1710::hkTransformL *)(&out->unk40)));
    void* m = &out->unk80;
    reinterpret_cast<::hkTransformCB22 *>((((S_00db4b50_Sub*)m)))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(out)), (*(const ::hkTransformCB22 *)(&out->unk40)));
    ((S_00db4b50_Sub*)&out->unkc0)->FUN_00c7f700(m, &a->unk20);
    ((S_00db4b50_Sub*)&out->unkd0)->FUN_00c7f640(m, &a->unk30);
    out->unkcc = -a->unk14;
    *(__m128*)&out->unk110 = *(__m128*)(a->unk00 + 0x80);
    S_rotInv((const __m128*)&out->unk00, (const __m128*)&a->unk60, 2, (__m128*)&out->unkf0);
    ((S_00db4b50_Sub*)&out->unk120)->FUN_00c7f640(m, a->unk04 + 0x80);
    reinterpret_cast<::FUN_004b4ab0_Class *>((((S_00db4b50_Sub*)&out->unke0)))->FUN_004b4ab0((int)(out), (int)(&a->unk50));
}

namespace fnv_00db52c0 {

union Vec4
{
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
};
struct Transform
{
    Vec4 row0, row1, row2, translation;
};
struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4 vector20;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    Vec4 vectora0;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    Vec4 vector130;
};
struct Pair
{
    int unk00, unk04, unk08, unk0c;
    float radius;
};
struct PairArg
{
    Pair* p;
};
struct OutArg
{
    Vec4* p;
};

static __forceinline void calculate(Vec4& output, const Transform& frame, __m128 r)
{
    __m128 x3 = frame.row0.v;
    __m128 x1 = frame.row1.v;
    __m128 x5 = frame.row2.v;
    __m128 x2 = x3;
    x2 = _mm_unpacklo_ps(x2, x1);
    x3 = _mm_unpackhi_ps(x3, x1);
    __m128 x4 = x2;
    x4 = _mm_movelh_ps(x4, x5);
    x1 = x4;
    x1 = _mm_movehl_ps(x1, x2);
    x1 = _mm_shuffle_ps(x1, x5, 0xd4);
    x2 = r;
    x2 = _mm_shuffle_ps(x2, r, 0x55);
    x2 = _mm_mul_ps(x2, x1);
    x1 = r;
    x1 = _mm_shuffle_ps(x1, r, 0);
    x1 = _mm_mul_ps(x1, x4);
    x3 = _mm_shuffle_ps(x3, x5, 0xe4);
    r = _mm_shuffle_ps(r, r, 0xaa);
    x2 = _mm_add_ps(x2, x1);
    x3 = _mm_mul_ps(x3, r);
    x2 = _mm_add_ps(x2, x3);
    output.v = x2;
}
// @fnv 0x00db52c0
static __declspec(noinline) void FUN_00db52c0(Shape* obj, const Transform* mat, const Transform* other, Pair* apPairA,
                                              Pair* apPairB, OutArg a3, Vec4* apResult)
{
    Vec4* out = a3.p;
    Transform localTransform;
    Vec4 shapeResult;
    reinterpret_cast<::hkTransformCB22 *>(&(localTransform))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(mat)), (*(const ::hkTransformCB22 *)(other)));
    reinterpret_cast<::GapSolver *>((obj))->FUN_00daad40((const ::GapShape *)(apPairA), (const ::GapShape *)(apPairB), (*(const ::GapTransform *)(&localTransform)), (*(::GapVector *)(&shapeResult)));

    __m128 v = shapeResult.v;
    __m128 p = _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), mat->row1.v);
    p = _mm_add_ps(p, _mm_mul_ps(_mm_shuffle_ps(v, v, 0), mat->row0.v));
    p = _mm_add_ps(p, _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), mat->row2.v));
    out->v = p;

    __m128 q;
    if (obj->unk00 == 1)
        q = obj->vector20.v;
    else if (obj->unk04 == 1)
    {
        q = _mm_shuffle_ps(v, v, 0xff);
        q = _mm_shuffle_ps(q, q, 0);
        q = _mm_mul_ps(q, v);
        q = _mm_add_ps(q, obj->vectora0.v);
    }
    else
        q = obj->vector130.v;

    double distance = shapeResult.w;
    __m128 w = _mm_shuffle_ps(v, v, 0xff);
    __m128 w2 = _mm_shuffle_ps(w, w, 0);
    __m128 r = _mm_sub_ps(q, _mm_mul_ps(w2, v));
    r = _mm_sub_ps(r, localTransform.translation.v);
    calculate(*apResult, localTransform, r);
    out->w = (distance - apPairA->radius) - apPairB->radius;
}
extern Shape* volatile inputObj;
extern const Transform* volatile inputMat;
extern const Transform* volatile inputOther;
extern Pair* volatile inputPair1;
extern Pair* volatile inputPair2;
extern Vec4* volatile inputOut1;
extern Vec4* volatile inputOut2;
void emit_function()
{
    PairArg p1 = {inputPair1}, p2 = {inputPair2};
    OutArg o1 = {inputOut1}, o2 = {inputOut2};
    FUN_00db52c0(inputObj, inputMat, inputOther, p1.p, p2.p, o1, o2.p);
}
}  // namespace fnv_00db52c0

static inline void* getMemoryRouter() { return ::FUN_00c85750(); }
struct Table
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    unsigned int(* f2c)(struct Ctrl*);
    void(* f30)(struct Ctrl*, unsigned int);
};
struct Ctrl
{
    Table* tab;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float f10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    float fa0;
};
struct Stat
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    float fa0;
};
struct ObjA
{
    Ctrl* ctrl;
    unsigned int unk04;
    void* p8;
};
struct ObjB
{
    Ctrl* ctrl;
    unsigned int unk04;
    Stat* p8;
};
struct In
{
    ObjA* a;
    ObjB* b;
    unsigned int unk08;
    unsigned char* p0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    __m128 v70;
};
struct Out
{
    void* f0;
    void* f4;
    unsigned int f8;
    unsigned int f0c;
    unsigned int f10;
    float f14;
    float f18;
    float f1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned char* f40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    __m128 f50;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    float f6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    float f7c;
};
// Fills out from in: stores both p8 pointers and the f10 sum, reserves v*16 bytes (rounded to 128) from FUN_00c85750's cursor, and computes f18 and f1c.
// @fnv 0x00db53f0
static __declspec(noinline) void FUN_00db53f0(In* in, Out* out)
{
    ObjA* a = in->a;
    ObjB* b = in->b;
    Ctrl* pCtrlA = a->ctrl;
    Ctrl* pCtrlB = b->ctrl;
    Stat* pStatA = (Stat*)a->p8;
    Stat* pStatB = (Stat*)b->p8;
    out->f0 = pStatA;
    out->f4 = pStatB;
    out->f14 = pCtrlB->f10 + pCtrlA->f10;
    out->f50 = in->v70;
    out->f40 = in->p0c + 0x50;
    int v = pCtrlA->tab->f2c(pCtrlA);
    out->f10 = v;
    out->f0c = v;
    unsigned int* pBlockCursor = (unsigned int*)getMemoryRouter();
    unsigned int uiBlockStart = *pBlockCursor;
    int sz = v * 16;
    sz = sz + 0x7f;
    sz = sz & 0xffffff80;
    *pBlockCursor = uiBlockStart + sz;
    out->f8 = uiBlockStart;
    pCtrlA->tab->f30(pCtrlA, uiBlockStart);
    float t1 = pStatB->fa0 * out->f7c * out->f7c;
    float t2 = pStatA->fa0 * out->f6c * out->f6c;
    float t = t1 + t2;
    out->f18 = t;
    out->f1c = (float)(1.0 / ((double)t + ::DAT_010c9300));
}

extern In* volatile inputIn;
extern Out* volatile inputOut;
void emit_function()
{
    FUN_00db53f0(inputIn, inputOut);
}

// Moved from hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <math.h>
#include "fnv/symbols_00db4000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_simd.h"
struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    hkVector4& operator=(const hkVector4& o)
    {
        *(__m128*)this = *(const __m128*)&o;
        return *this;
    }
    __m128& q()
    {
        return *(__m128*)this;
    }
    const __m128& q() const
    {
        return *(const __m128*)this;
    }
};

struct SweepObj
{
    void* unk00;
    void* unk04;
    hkVector4* m_items;
    int m_uiItemCount;
    int unk10;
    int unk14;
    float m_18;
    float m_1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    float m_44;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    float m_80;
};

struct SweepOut
{
    float t;
    int unk04, unk08, unk0c;
    hkVector4 v;
};

struct SweepState
{
    hkVector4 r00, r10, r20, r30, r40, r50, r60, r70, r80, r90, ra0, rb0;
    hkVector4 n;   // c0
    hkVector4 o;   // d0
    hkVector4 c;   // e0
    hkVector4 a;   // f0
    hkVector4 b;   // 100
    hkVector4 oa;  // 110
    hkVector4 ob;  // 120
};


static inline __m128 Cross(const __m128& a, const __m128& b)
{
    __m128 c0 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xc9), _mm_shuffle_ps(b, b, 0xd2));
    __m128 c1 = _mm_mul_ps(_mm_shuffle_ps(a, a, 0xd2), _mm_shuffle_ps(b, b, 0xc9));
    return _mm_sub_ps(c0, c1);
}

static inline __m128 Dot3(const __m128& a, const __m128& b)
{
    __m128 x2 = _mm_mul_ps(a, b);
    __m128 r = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), r);
}

static inline __m128 Dot4xyz1(const __m128& a, const __m128& b)
{
    __m128 xx = _mm_mul_ps(a, b);
    __m128 x2 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0xaa), _mm_shuffle_ps(b, b, 0xff));
    __m128 x3 = _mm_add_ss(_mm_shuffle_ps(xx, xx, 0x55), xx);
    return _mm_add_ps(x2, x3);
}

// @fnv 0x00db4e40
void __cdecl FUN_00db4e40(SweepObj* obj, float* p, SweepOut* out)
{
    float tEnd = 1.0f;
    float tCur = obj->m_80;
    int num = obj->m_uiItemCount;
    float tPrev = tCur;
    if (num == 0)
        return;
    do
    {
        SweepState st;
        ::FUN_00db4b50((::S_00db4b50_A *)(obj), tCur, (::S_00db4b50_Out *)(::SweepState *)(&st));
        int i = *(volatile int*)&num;
        hkVector4* it = obj->m_items;
        float dt = tEnd - tCur;
        hkVector4* dst = it;
        num = 0;
        float margin = obj->m_44 * dt;
        float tNext = tEnd;
        for (; --i >= 0; it++)
        {
            float dist;
            _mm_store_ss(&dist, Dot4xyz1(_mm_sub_ps(it->q(), st.o.q()), st.n.q()));
            if (dist > p[0] + margin)
                continue;
            float d0 = dist - p[0];
            __m128 v1 = _mm_sub_ps(it->q(), st.oa.q());
            __m128 v2 = _mm_sub_ps(it->q(), st.ob.q());
            __m128 x = _mm_sub_ps(Cross(st.a.q(), v1), st.c.q());
            x = _mm_sub_ps(x, Cross(st.b.q(), v2));
            float vel;
            _mm_store_ss(&vel, Dot3(x, st.n.q()));
            float d1 = d0 + vel * dt;
            float lim = dt * 0.5 * dt * obj->m_18;
            if (d1 > lim)
                continue;
            if (dist < p[0])
            {
                if (tCur == obj->m_80)
                {
                    out->t = tCur;
                    tEnd = tCur;
                    out->v = *it;
                }
                else
                {
                    float w = it->w;
                    tEnd = w;
                    tEnd = ::FUN_00db4ca0(obj, p, (const __m128 *)(it), tPrev, tCur, w, dist, vel, (::Out *)(out));
                }
            }
            else
            {
                hkVector4 tmp = *it;
                *it = *dst;
                *dst = tmp;
                dst->w = dist;
                num++;
                dst++;
                float g = dist - p[1];
                float h = 2.0 * g * obj->m_1c;
                if (h > dt * dt)
                    continue;
                float k = p[0] - p[1];
                float m = 2.0 * k * obj->m_1c;
                float r = sqrtf(h);
                if (vel >= 0.0f)
                {
                    r = vel * obj->m_1c * 2.0f + r;
                }
                else
                {
                    float n2 = -vel * obj->m_1c;
                    if (n2 > r)
                        r = n2;
                }
                if (r > dt)
                    continue;
                float r3 = sqrtf(m) + r;
                float hi = p[2];
                if (!(r3 > hi))
                    r3 = hi;
                float u = r3 + tCur;
                if (!(tNext < u))
                    tNext = u;
            }
        }
        if (tEnd < tCur)
            return;
        if (tCur == tNext && tEnd <= tCur)
            return;
        tPrev = tCur;
        tCur = tNext;
    } while (num != 0);
}

// Adapted from the project's prior contributor draft of 24 October 2026.
// The same-file caller lets VC2008 reproduce the private register convention.


// @fnv 0x00db49b0
static __declspec(noinline) float FUN_00db49b0(char* a, char* b, __m128* p, __m128* v0, __m128* v1, __m128* v2, float t)
{
    float tmp;
    float d1;
    __m128 vb = *v1;
    __m128 q = _mm_mul_ps(_mm_xor_ps(*v2, DAT_010c44d0), vb);
    tmp = (t - *(float*)(a + 0x4c)) * *(float*)(a + 0x5c);
    __m128 v0x = *v0;
    __m128 qy = _mm_add_ss(_mm_shuffle_ps(q, q, 0x55), q);
    _mm_store_ss(&d1, _mm_add_ss(_mm_shuffle_ps(q, q, 0xaa), qy));

    __m128 ev = _mm_set1_ps(tmp);
    __m128 L = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, ev), *(__m128*)(a + 0x40)),
                          _mm_mul_ps(*(__m128*)(a + 0x50), ev));
    __m128 w = _mm_sub_ps(v0x, L);
    __m128 c = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(*p, *p, 0xc9), _mm_shuffle_ps(w, w, 0xd2)),
                          _mm_mul_ps(_mm_shuffle_ps(*p, *p, 0xd2), _mm_shuffle_ps(w, w, 0xc9)));
    c = _mm_mul_ps(c, vb);
    __m128 cy = _mm_add_ss(_mm_shuffle_ps(c, c, 0x55), c);
    _mm_store_ss(&tmp, _mm_add_ss(_mm_shuffle_ps(c, c, 0xaa), cy));

    float r = tmp;
    // This ordering also preserves the original unordered comparison behavior.
    d1 = (float)(((r <= 0) ? r * DAT_010290f0 : r / DAT_010290f0) + d1);

    tmp = (t - *(float*)(b + 0x4c)) * *(float*)(b + 0x5c);
    ev = _mm_set1_ps(tmp);
    L = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, ev), *(__m128*)(b + 0x40)),
                   _mm_mul_ps(*(__m128*)(b + 0x50), ev));
    w = _mm_sub_ps(v0x, L);
    // Keep one local copy for both shuffles of the second vector.
    __m128 plane1 = p[1];
    c = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(plane1, plane1, 0xc9), _mm_shuffle_ps(w, w, 0xd2)),
                   _mm_mul_ps(_mm_shuffle_ps(plane1, plane1, 0xd2), _mm_shuffle_ps(w, w, 0xc9)));
    c = _mm_mul_ps(c, vb);
    cy = _mm_add_ss(_mm_shuffle_ps(c, c, 0x55), c);
    _mm_store_ss(&tmp, _mm_add_ss(_mm_shuffle_ps(c, c, 0xaa), cy));

    r = tmp;
    if (r >= 0)
    {
        d1 = (float)(d1 - r * DAT_010290f0);
    }
    else
    {
        d1 = (float)(d1 - r / DAT_010290f0);
    }
    return d1;
}

__m128* volatile dbPlanes;
char* volatile dbBodyA;
char* volatile dbBodyB;
__m128* volatile dbPoint;
__m128* volatile dbDirection;
__m128* volatile dbVelocity;
volatile float dbTime;
volatile float dbResult;
void evaluatePlaneDistance()
{
    dbResult = FUN_00db49b0(dbBodyA, dbBodyB, dbPlanes, dbPoint, dbDirection, dbVelocity, dbTime);
}

// Moved from hkpcontinuousgsk_gs_nogs_variant.cpp (VEGAS-15).
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_0106b000.h"
struct __declspec(align(16)) Sample
{
    unsigned int d[76];
};
  // 0.5
  // 0.1
   // 0.1f
  // 0.9
   // 0.9f
// @fnv 0x00db4ca0
float FUN_00db4ca0(void* a, const float* target, const __m128* origin, float A, float B, float C, float D, int unused,
                   Out* res)
{
    float t = A;
    float eps = (float)(target[4] * ::DAT_010290b0);
    for (int i = 0; i < 10; i++)
    {
        if (*target >= C)
            break;
        float d = D - C;
        if (d > -eps)
            break;
        t = (*target - C) / d;
        if (!(i & 1))
        {
            if (!(t > DAT_0101ffa0))
                t = ::DAT_0101e2bc;
            if (!(t < DAT_0106b9e8))
                t = DAT_010177e8;
        }
        Sample s;
        t = (1.0f - t) * A + B * t;
        ::FUN_00db4b50((::S_00db4b50_A *)(a), t, (::S_00db4b50_Out *)(::Sample *)(&s));
        __m128 w = *(__m128*)&s.d[48];
        __m128 v = _mm_mul_ps(_mm_sub_ps(*origin, *(__m128*)&s.d[52]), w);
        __m128 p = _mm_add_ss(_mm_shuffle_ps(v, v, 0xaa), _mm_shuffle_ps(w, w, 0xff));
        __m128 q = _mm_add_ss(_mm_shuffle_ps(v, v, 0x55), v);
        float r;
        _mm_store_ss(&r, _mm_add_ps(p, q));
        float e = (float)fabs((float)(r - *target));
        if (e < eps)
            break;
        if (r < *target)
        {
            B = t;
            D = r;
        }
        else
        {
            A = t;
            C = r;
        }
    }
    if (t < res->t)
    {
        res->t = t;
        res->pos = *origin;
    }
    return res->t;
}

// Moved from hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp (VEGAS-15).

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-28 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/ThisClass.h"
#include "fnv/symbols_00c98000.h"
#include "fnv/symbols_00da8000.h"
// Adapted from the project's prior contributor draft of 24 October 2026.
// The same-file caller lets VC2008 reproduce the private register convention.
static float FUN_00db49b0(char* a, char* b, __m128* p, __m128* v0, __m128* v1, __m128* v2, float t);
void evaluatePlaneDistance();

extern "C" const float DAT_010d5384;
typedef float hkReal;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
typedef signed long __w64 hkLong;
enum hkResult
{
    HK_SUCCESS = 0,
    HK_FAILURE = 1
};
typedef size_t hk_size_t;
typedef hkReal hkTime;
__forceinline hkLong __cdecl hkGetByteOffset(const void* base, const void* pntr)
{
    return hkLong(pntr) - hkLong(base);
}
template <typename TYPE> __forceinline TYPE* __cdecl hkAddByteOffset(TYPE* base, hkLong offset)
{
    return reinterpret_cast<TYPE*>(reinterpret_cast<char*>(base) + offset);
}
class FinishingFlag
{
  public:
    FinishingFlag() : m_bFinishing(0)
    {}
    int m_bFinishing;
};
class hkClass;
typedef int hkBool32;
class hkBool
{
  public:
    typedef char CompileTimeTrueType;
    inline hkBool()
    {}
    inline hkBool(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
    inline operator bool() const
    {
        return m_cBooleanValue != 0;
    }

  private:
    char m_cBooleanValue;
public:
    __forceinline hkBool()
    {}
    __forceinline hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    __forceinline operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    __forceinline hkBool& operator=(bool e)
    {
        m_cBooleanValue = (char)e;
        return *this;
    }

          
    char m_cBooleanValue;
};
extern "C"
{
    extern const hkReal g_afRealLookupTable[256];
}
class QuantizedFloat8
{
  public:
    enum
    {
        MAX_VALUE = 256
    };
    inline QuantizedFloat8()
    {}
    QuantizedFloat8& operator=(const float& fv);
    inline QuantizedFloat8(const float f)
    {
        *this = f;
    }
    inline operator float() const
    {
        return g_afRealLookupTable[m_uiFilterValue];
    }

  public:
    hkUint8 m_uiFilterValue;
};
template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    hkEnum()
    {}
    operator ENUM() const
    {
        return static_cast<ENUM>(m_kStorage);
    }
    void operator=(ENUM e)
    {
        m_kStorage = static_cast<STORAGE>(e);
    }

  private:
    STORAGE m_kStorage;
};
template <typename TYPE> class ValueWrapper
{
  public:
    __forceinline ValueWrapper()
    {}
    __forceinline void operator=(TYPE e)
    {
        m_kStorage = e;
    }
    __forceinline TYPE val() const
    {
        return m_kStorage;
    }
    __forceinline TYPE operator->() const
    {
        return m_kStorage;
    }
    __forceinline operator TYPE() const
    {
        return val();
    }

  private:
    TYPE m_kStorage;
};

template <typename T> struct TypeSizeConstant
{
    enum
    {
        val = sizeof(T)
    };
};
class hkMemoryAllocator
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t, void* p)
    {
        return p;
    }
    virtual void* AllocateMemoryBlock(int numBytes) = 0;
    virtual void ReleaseBlock(void* p, int numBytes) = 0;

  public:
    enum MemoryState
    {
        MEMORY_STATE_OK,
        MEMORY_STATE_OUT_OF_MEMORY
    };
};
struct StringPointerTriple
{
  public:
    __forceinline StringPointerTriple();
    void* allocateStack(int numBytes, const char* what);
    __forceinline void deallocateStack(void* p);
    __forceinline int getFreeStackSize()
    {
        return int(hkGetByteOffset(m_next, m_kRayEnd));
    }

  protected:
    ValueWrapper<void*> m_next;
    ValueWrapper<void*> m_kRayEnd;
public:
    __forceinline void* allocateStack(int numBytes, const char* what)
    {
        void* current = m_pTileTemplate;
        m_pTileTemplate = hkAddByteOffset(current, numBytes);
        return current;
    }
    __forceinline void deallocateStack(void* p)
    {
        m_pTileTemplate = p;
    }
};
__forceinline void* StringPointerTriple::allocateStack(int numBytes, const char* what)
{
    ;
    if (numBytes > getFreeStackSize())
    {
        ;
    }
    void* current = m_next;
    m_next = hkAddByteOffset(current, numBytes);
    return current;
}
void StringPointerTriple::deallocateStack(void* p)
{
    ;
    m_next = p;
}
class NineIntegerRecord
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t, void* p)
    {
        return p;
    }
    typedef hkMemoryAllocator Allocator;
    static NineIntegerRecord& __cdecl GetMonitorStream();
    inline StringPointerTriple& stack()
    {
        return m_aiEntries;
    }
    inline Allocator& temp()
    {
        return *m_pTemp;
    }
    inline Allocator& heap()
    {
        return *m_pStreamAllocator;
    }

  protected:
    StringPointerTriple m_aiEntries;
    Allocator* m_pTemp;
    Allocator* m_pStreamAllocator;
    Allocator* m_pDebugAllocator;
public:
    static __forceinline NineIntegerRecord& GetMonitorStream()
    {
        return *static_cast<NineIntegerRecord*>(getMemoryRouter());
    }
    __forceinline StringPointerTriple& stack()
    {
        return m_aiEntries;
    }
};
template <typename TYPE> __forceinline TYPE* __cdecl hkAllocateStack(int n, const char* what = 0)
{
    NineIntegerRecord& mem = NineIntegerRecord::GetMonitorStream();
    return static_cast<TYPE*>(
        mem.stack().allocateStack((((n * TypeSizeConstant<TYPE>::val) + ((128) - 1)) & (~((128) - 1))), what));
}
template <typename TYPE> __forceinline void __cdecl hkDeallocateStack(TYPE* ptr)
{
    NineIntegerRecord::GetMonitorStream().stack().deallocateStack(static_cast<void*>(ptr));
}
class hkBaseObject
{
  public:
    static const struct ClassMemberDescriptor Members[];
    __forceinline virtual ~hkBaseObject()
    {}

  public:
    __forceinline hkBaseObject()
    {}
};
class hkStatisticsCollector;
class hkReferencedObject : public hkBaseObject
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(hkStatisticsCollector* collector, const hkClass* cls) const;

  public:
    enum
    {
        MASK_MEMSIZE = 0x7fff
    };
    hkUint16 m_usMemSizeAndFlags;

  public:
    hkReferencedObject(class FinishingFlag flag)
    {}
};
template <bool N> struct BooleanTypeConstant
{
    typedef BooleanTypeConstant<N> type;
    enum
    {
        result = N
    };
};
typedef BooleanTypeConstant<true> hkTypeIsPod;
struct RouterHeapAllocatorProvider
{
    hkMemoryAllocator& get(const void*)
    {
        return NineIntegerRecord::GetMonitorStream().heap();
    }
};
template <typename T> class HavokElementArray
{
  public:
    typedef HavokElementArray<T> ThisType;

  protected:
    __forceinline HavokElementArray(const HavokElementArray& a)
    {
        ;
    }

  public:
    __forceinline void _useExternalArray(T*, int cap);

  protected:
    __forceinline HavokElementArray<T>& copyFromArray(hkMemoryAllocator&, const HavokElementArray<T>& src, hkTypeIsPod);

  public:
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        FLAG_MASK = int(0xC0000000),
        DONT_DEALLOCATE_FLAG = int(0x80000000),
        FORCE_SIGNED = -1
    };

  protected:
    friend class hkStatisticsCollector;

  public:
    HavokElementArray(FinishingFlag f)
    {}
};
template <typename T, typename Allocator = RouterHeapAllocatorProvider> class hkArray : public HavokElementArray<T>
{
  public:
    typedef Allocator AllocatorType;

  protected:
    __forceinline hkArray(const hkArray& a);

  public:
    __forceinline hkArray& operator=(const HavokElementArray<T>& a);
};

;
typedef __m128 hkQuadReal;
class hkVector4X;
typedef const hkVector4X& hkVector4XParameter;
class VectorComponentValue
{
  public:
    VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    VectorComponentValue(hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline hkQuadReal broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }
    __forceinline const hkQuadReal& getQuad() const
    {
        return m_vValue;
    }

  private:
    hkQuadReal m_vValue;
public:
    __forceinline VectorComponentValue(const hkQuadReal& x) : m_vValue(x)
    {}
    __forceinline VectorComponentValue(hkReal x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline VectorComponentValue()
    {}
    __forceinline operator hkReal() const
    {
        hkReal s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};
typedef const VectorComponentValue& hkSimdRealParameter;
class hkVector4XComparison;
typedef const hkVector4XComparison& hkVector4XComparisonParameter;
namespace MathUtilities {
inline hkReal __cdecl fabs(hkReal r)
{
    return ::fabsf(r);
}
inline hkBool __cdecl equal(hkReal x, hkReal y, hkReal tolerance2 = 1e-5f)
{
    return MathUtilities::fabs(x - y) < tolerance2;
}
template <typename T> inline T __cdecl max2(T x, T y)
{
    return x > y ? x : y;
}
template <typename T> inline T __cdecl min2(T x, T y)
{
    return x < y ? x : y;
}
}
class hkRotation;
class hkTransform;
class hkVector4X
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline void operator=(const hkVector4X& v);
    __forceinline int getInt24W() const;
    __forceinline void add4(const hkVector4X& a);
    __forceinline void sub4(const hkVector4X& a);
    __forceinline void setSub4(const hkVector4X& a, const hkVector4X& b);
    __forceinline void setMul4(hkSimdRealParameter r, const hkVector4X& a);
    __forceinline void addMul4(hkSimdRealParameter r, const hkVector4X& a);
    __forceinline void setAddMul4(const hkVector4X& a, const hkVector4X& b, hkSimdRealParameter r);
    __forceinline void setAddMul4(const hkVector4X& a, const hkVector4X& x, const hkVector4X& y);
    __forceinline void setCross(const hkVector4X& a, const hkVector4X& b);
    __forceinline void setInterpolate4(const hkVector4X& a, const hkVector4X& b, hkSimdRealParameter t);
    __forceinline void setNeg3(const hkVector4X& v);
    __forceinline void setNeg4(const hkVector4X& v);
    void SetRotatedDirection(const hkRotation& a, const hkVector4X& b);
    void setRotatedInverseDir(const hkRotation& a, const hkVector4X& b);
    void SetTransformedPoint(const hkTransform& a, const hkVector4X& b);
    __forceinline void _setRotatedInverseDir(const hkRotation& a, const hkVector4X& b);
    __forceinline void _setTransformedPos(const hkTransform& a, const hkVector4X& b);
    __forceinline VectorComponentValue dot3(const hkVector4X& a) const;
    __forceinline VectorComponentValue length3() const;
    __forceinline hkReal& operator()(int i);
    __forceinline const hkReal& operator()(int i) const;
    __forceinline VectorComponentValue getSimdAt(int i) const;
    __forceinline void setBroadcast(hkVector4XParameter v, int i);

  private:
    hkQuadReal m_vComponents;

  public:
    operator hkQuadReal() const
    {
        return m_vComponents;
    }
};
class hkQuaternion
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    hkVector4X m_vec;

  protected:
    void setFlippedRotation(const hkVector4X& from);
};
class hkMatrix3
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline hkVector4X& getColumn(int i);
    __forceinline const hkVector4X& getColumn(int i) const;

  protected:
    hkVector4X m_kColumn0;
    hkVector4X m_kColumn1;
    hkVector4X m_kColumn2;
public:
    __forceinline hkMatrix3()
    {}
    __forceinline hkVector4& getColumn(int x)
    {
        return (&m_kColumn0)[x];
    }
    __forceinline const hkVector4& getColumn(int x) const
    {
        return (&m_kColumn0)[x];
    }
};
class __declspec(align(16)) hkRotation : public hkMatrix3
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
};
class hkTransform
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    __forceinline hkTransform()
    {}
    __forceinline hkTransform(const hkTransform& r);
    __forceinline const hkVector4X& getTranslation() const;
    __forceinline hkRotation& getRotation();
    __forceinline const hkRotation& getRotation() const;

  private:
    hkRotation m_rotation;
    hkVector4X m_vTranslation;
public:
    __forceinline hkTransform(const hkTransform& t)
    {
        const hkVector4 r0 = t.m_rotation.getColumn(0);
        const hkVector4 r1 = t.m_rotation.getColumn(1);
        const hkVector4 r2 = t.m_rotation.getColumn(2);
        const hkVector4 r3 = t.m_rotation.getColumn(3);
        m_rotation.getColumn(0) = r0;
        m_rotation.getColumn(1) = r1;
        m_rotation.getColumn(2) = r2;
        m_rotation.getColumn(3) = r3;
    }
    __forceinline hkRotation& getRotation()
    {
        return m_rotation;
    }
    __forceinline const hkRotation& getRotation() const
    {
        return m_rotation;
    }
    __forceinline const hkVector4& getTranslation() const
    {
        return m_vTranslation;
    }
    __forceinline void SetMulInverse(const hkTransform& a, const hkTransform& b)
    {
        reinterpret_cast<::hkTransformCB22 *>(this)->FUN_00cb22f0((const ::hkTransformCB22 &)(a), (const ::hkTransformCB22 &)(b));
    }
};
class hkSweptTransform
{
  public:
    static const struct ClassMemberDescriptor Members[];

  public:
    __forceinline void _approxTransformAt(hkTime time, hkTransform& transformOut) const;
    __forceinline hkReal getInterpolationValue(hkTime t) const;
    __forceinline hkTime getBaseTime() const;
    __forceinline hkReal getInvDeltaTime() const;

  public:
    hkVector4X m_vCenterOfMass0;
    hkVector4X m_vCenterOfMass1;
    hkQuaternion m_qRotation0;
    hkQuaternion m_qRotation1;
    hkVector4X m_vCenterOfMassLocal;
public:
    __forceinline hkReal getBaseTime() const
    {
        return m_vCenterOfMass0(3);
    }
    __forceinline hkReal getInvDeltaTime() const
    {
        return m_vCenterOfMass1(3);
    }
    __forceinline hkReal getInterpolationValue(hkTime t) const
    {
        hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
        return dt;
    }
};
inline void hkVector4X::operator=(const hkVector4X& v)
{
    m_vComponents = v.m_vComponents;
}
int hkVector4X::getInt24W() const
{
    return (reinterpret_cast<const hkUint32*>(this))[3] & ~0x3f000000;
}
inline void hkVector4X::add4(const hkVector4X& v)
{
    m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
}
inline void hkVector4X::sub4(const hkVector4X& v)
{
    m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
}
inline void hkVector4X::setSub4(const hkVector4X& v0, const hkVector4X& v1)
{
    m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
}
inline void hkVector4X::setNeg3(const hkVector4X& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, *(const hkQuadReal*)&(*reinterpret_cast<const unsigned int (*)[4]>(&::DAT_010c4c00)));
}
inline void hkVector4X::setMul4(hkSimdRealParameter r, const hkVector4X& v1)
{
    m_vComponents = _mm_mul_ps(r.broadcast(), v1.m_vComponents);
}
inline void hkVector4X::addMul4(hkSimdRealParameter r, const hkVector4X& v1)
{
    m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
}
inline void hkVector4X::setAddMul4(const hkVector4X& a, const hkVector4X& b, hkSimdRealParameter r)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(r.broadcast(), b.m_vComponents));
}
inline void hkVector4X::setAddMul4(const hkVector4X& a, const hkVector4X& x, const hkVector4X& y)
{
    m_vComponents = _mm_add_ps(a.m_vComponents, _mm_mul_ps(x.m_vComponents, y.m_vComponents));
}
inline void hkVector4X::setCross(const hkVector4X& v0, const hkVector4X& v1)
{
    hkQuadReal cross0;
    cross0 =
        _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))),
                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))));
    hkQuadReal cross1;
    cross1 =
        _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, (((3) << 6) | ((1) << 4) | ((0) << 2) | ((2)))),
                   _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, (((3) << 6) | ((0) << 4) | ((2) << 2) | ((1)))));
    m_vComponents = _mm_sub_ps(cross0, cross1);
}
inline void hkVector4X::setInterpolate4(const hkVector4X& v0, const hkVector4X& v1, hkSimdRealParameter _t)
{
    hkQuadReal t = _t.broadcast();
    hkQuadReal s = _mm_sub_ps(::DAT_010ec7f0, t);
    m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(t, v1.m_vComponents));
}
inline void hkVector4X::setNeg4(const hkVector4X& v)
{
    m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c44d0);
}
inline void hkVector4X::_setRotatedInverseDir(const hkRotation& r, const hkVector4X& b)
{
    hkQuadReal c0 = r.getColumn(0).m_vComponents;
    hkQuadReal c1 = r.getColumn(1).m_vComponents;
    hkQuadReal c2 = r.getColumn(2).m_vComponents;
    {
        hkQuadReal _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, (((3) << 6) | ((2) << 4) | ((1) << 2) | ((0))));
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, (((3) << 6) | ((1) << 4) | ((1) << 2) | ((0))));
        c2 = _ctmp;
    };
    const hkQuadReal b0 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    const hkQuadReal r0 = _mm_mul_ps(c0, b0);
    const hkQuadReal b1 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1))));
    const hkQuadReal r1 = _mm_mul_ps(c1, b1);
    const hkQuadReal b2 =
        _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2))));
    const hkQuadReal r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
inline void hkVector4X::_setTransformedPos(const hkTransform& t, const hkVector4X& b)
{
    const hkRotation& r = t.getRotation();
    hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    hkQuadReal r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1))));
    hkQuadReal r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2))));
    hkQuadReal r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.getTranslation().m_vComponents));
}
inline VectorComponentValue hkVector4X::dot3(const hkVector4X& a) const
{
    hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
    hkQuadReal xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1)))), x2);
    return _mm_add_ss(_mm_shuffle_ps(x2, x2, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2)))), xySum);
}
inline VectorComponentValue hkVector4X::length3() const
{
    return _mm_sqrt_ss(this->dot3(*this).getQuad());
}
inline hkReal& hkVector4X::operator()(int a)
{
    return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal& hkVector4X::operator()(int a) const
{
    return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline VectorComponentValue hkVector4X::getSimdAt(int i) const
{
    switch (i)
    {
    case 0:
        return m_vComponents;
    case 1:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, (((1) << 6) | ((1) << 4) | ((1) << 2) | ((1))));
    case 2:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, (((2) << 6) | ((2) << 4) | ((2) << 2) | ((2))));
    case 3:
    default:
        return _mm_shuffle_ps(m_vComponents, m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3))));
    }
}
inline void hkVector4X::setBroadcast(const hkVector4X& v, int i)
{
    if (i == 0)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((0) << 6) | ((0) << 4) | ((0) << 2) | ((0))));
    }
    else if (i == 3)
    {
        m_vComponents =
            _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, (((3) << 6) | ((3) << 4) | ((3) << 2) | ((3))));
    }
}
inline void hkVector4X::setRotatedInverseDir(const hkRotation& t, const hkVector4X& v)
{
    _setRotatedInverseDir(t, v);
}
inline hkVector4X& hkMatrix3::getColumn(int x)
{
    return (&m_kColumn0)[x];
}
inline const hkVector4X& hkMatrix3::getColumn(int x) const
{
    return (&m_kColumn0)[x];
}
const hkVector4X& hkTransform::getTranslation() const
{
    return m_vTranslation;
}
hkRotation& hkTransform::getRotation()
{
    return m_rotation;
}
const hkRotation& hkTransform::getRotation() const
{
    return m_rotation;
}
hkTransform::hkTransform(const hkTransform& t)
{
    const hkVector4X r0 = t.m_rotation.getColumn(0);
    const hkVector4X r1 = t.m_rotation.getColumn(1);
    const hkVector4X r2 = t.m_rotation.getColumn(2);
    const hkVector4X r3 = t.m_rotation.getColumn(3);
    m_rotation.getColumn(0) = r0;
    m_rotation.getColumn(1) = r1;
    m_rotation.getColumn(2) = r2;
    m_rotation.getColumn(3) = r3;
}
hkTime hkSweptTransform::getBaseTime() const
{
    return hkTime(m_vCenterOfMass0(3));
}
hkReal hkSweptTransform::getInvDeltaTime() const
{
    return m_vCenterOfMass1(3);
}
hkReal hkSweptTransform::getInterpolationValue(hkTime t) const
{
    ;
    hkReal dt = (t - getBaseTime()) * getInvDeltaTime();
    ;
    ;
    return dt;
}
class MemoryUtils
{
  public:
    enum ReplaceType
    {
        REPLACE_ONE,
        REPLACE_ALL
    };
    static __forceinline void __cdecl memClear16(void* dst, int numQuads);

  private:
    static void copyAndReplace(char* dest, const char* orig, int origLen, const MemoryUtils& from,
                               const MemoryUtils& to, const hkArray<int>& indices);
};
void __cdecl MemoryUtils::memClear16(void* dst, int numQuads)
{
    ;
    hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
    {
        for (int i = 0; i < numQuads; i++)
        {
            dst32[0] = 0;
            dst32[1] = 0;
            dst32[2] = 0;
            dst32[3] = 0;
            dst32 += 4;
        }
    }
}
class hkMotionState
{
  public:
    static const struct ClassMemberDescriptor Members[];
    inline const hkSweptTransform& getSweptTransform() const;

  protected:
    hkTransform m_kMotionTransform;
    class hkSweptTransform m_kSweptTransform;

  public:
    hkVector4X m_kDeltaAngle;
    hkReal m_fObjectRadius;
public:
    __forceinline const hkSweptTransform& getSweptTransform() const
    {
        return m_kSweptTransform;
    }
};
const hkSweptTransform& hkMotionState::getSweptTransform() const
{
    return m_kSweptTransform;
}
class hkAabb
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    hkVector4X m_kMinimumCorner;
};
class hkSphere
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  protected:
    hkVector4X m_pos;
};
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
  public:
    static const struct ClassMemberDescriptor Members[];
    inline hkVector4X& getPosition();
    inline const hkVector4X& getNormal() const;
    inline hkVector4X& getSeparatingNormal();
    inline void setSeparatingNormal(const hkVector4X& separatingNormal);
    inline void setDistance(hkReal d);

  protected:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    hkVector4X m_vContactPosition;
    hkVector4X m_vSeparatingNormal;
public:
    __forceinline const hkVector4& getPosition() const
    {
        return m_vContactPosition;
    }
    __forceinline const hkVector4& getNormal() const
    {
        return m_vSeparatingNormal;
    }
    __forceinline hkVector4& getPosition()
    {
        return m_vContactPosition;
    }
    __forceinline const hkVector4& getSeparatingNormal() const
    {
        return m_vSeparatingNormal;
    }
    __forceinline hkVector4& getSeparatingNormal()
    {
        return m_vSeparatingNormal;
    }
    __forceinline void setSeparatingNormal(const hkVector4& separatingNormal)
    {
        m_vSeparatingNormal = separatingNormal;
    }
    __forceinline void setDistance(hkReal d)
    {
        m_vSeparatingNormal(3) = d;
    }
};
inline const hkVector4X& hkContactPoint::getNormal() const
{
    return m_vSeparatingNormal;
}
inline hkVector4X& hkContactPoint::getPosition()
{
    return m_vContactPosition;
}
inline hkVector4X& hkContactPoint::getSeparatingNormal()
{
    return m_vSeparatingNormal;
}
inline void hkContactPoint::setSeparatingNormal(const hkVector4X& separatingNormal)
{
    m_vSeparatingNormal = separatingNormal;
}
inline void hkContactPoint::setDistance(hkReal d)
{
    m_vSeparatingNormal(3) = d;
}
class Vector4WithInt24W : public hkVector4X
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    int GetValueForType() const
    {
        return getInt24W();
    }
};
enum CollisionShapeType
{
    HK_SHAPE_INVALID = 0,
    HK_SHAPE_SPHERE,
    HK_FIRST_SHAPE_TYPE = HK_SHAPE_SPHERE,
    HK_SHAPE_CYLINDER,
    HK_SHAPE_TRIANGLE,
    HK_SHAPE_BOX,
    HK_SHAPE_CAPSULE,
    HK_SHAPE_CONVEX_VERTICES,
    HK_SHAPE_COLLECTION,
    HK_SHAPE_BV_TREE,
    HK_SHAPE_LIST,
    HK_SHAPE_MOPP,
    HK_SHAPE_CONVEX_TRANSLATE,
    HK_SHAPE_CONVEX_TRANSFORM,
    HK_SHAPE_SAMPLED_HEIGHT_FIELD,
    HK_SHAPE_EXTENDED_MESH,
    HK_SHAPE_TRANSFORM,
    HK_SHAPE_COMPRESSED_MESH,
    HK_SHAPE_MAX_ID_SPU = HK_SHAPE_COMPRESSED_MESH + 1,
    HK_SHAPE_CONVEX,
    HK_SHAPE_PACKED_CONVEX_VERTICES,
    HK_SHAPE_MOPP_EMBEDDED,
    HK_SHAPE_CONVEX_PIECE,
    HK_SHAPE_MULTI_SPHERE,
    HK_SHAPE_CONVEX_LIST,
    HK_SHAPE_TRIANGLE_COLLECTION,
    HK_SHAPE_MULTI_RAY,
    HK_SHAPE_HEIGHT_FIELD,
    HK_SHAPE_SPHERE_REP,
    HK_SHAPE_BV,
    HK_SHAPE_PLANE,
    HK_SHAPE_PHANTOM_CALLBACK,
    HK_SHAPE_USER0,
    HK_SHAPE_USER1,
    HK_SHAPE_USER2,
    HK_SHAPE_MAX_ID,
    HK_SHAPE_ALL = -1
public:
    HK_SHAPE_CONVEX_VERTICES = 3
};
class hkpCollisionDispatcher;
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody;
class hkpShapeContainer;
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpConvexShape;
class hkpShape : public hkReferencedObject
{
  public:
    static const struct ClassMemberDescriptor Members[];
    __forceinline hkpShape(CollisionShapeType type);
    __forceinline CollisionShapeType getType() const;
    virtual hkReal getMaximumProjection(const hkVector4X& direction) const;
    virtual const hkpShapeContainer* GetShapeContainer() const
    {
        return 0;
    }
    virtual bool isConvex() const
    {
        return false;
    }
    struct PhysicsShape
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p, sizeof(hkpShape::PhysicsShape));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        bool m_bIsConvex;
        bool m_bIsConvexPiece;
        bool m_bIsComposite;
    };
    virtual int CalcSizeForSpu(const PhysicsShape& input, int spuBufferSizeLeft) const;

  protected:
    virtual void CalculateAabb(const hkTransform& localToWorld, hkReal tolerance, hkAabb& out) const = 0;
    virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const = 0;
    virtual void CastRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const = 0;
    virtual hkVector4XComparison CastRayBundle(const ShapeRayBundleCastInput& input, ShapeRayCastOutputArray& output,
                                               hkVector4XComparisonParameter mask) const;

  public:
    static void __cdecl resetShapeFunctions();

  public:
  public:
    hkUlong m_ulUserData;

  public:
    hkEnum<CollisionShapeType, hkUint32> m_type;

  public:
    hkpShape(class FinishingFlag flag) : hkReferencedObject(flag)
    {
        if (flag.m_bFinishing)
        {
            m_type = HK_SHAPE_INVALID;
        }
    }
};
__declspec(align(16)) class AlignedHkpShape : public hkpShape
{
    AlignedHkpShape();
};
CollisionShapeType hkpShape::getType() const
{
    return static_cast<const AlignedHkpShape*>(this)->m_type;
}
class hkpCdBody
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    friend class hkpCollidable;
    __forceinline const hkpShape* getShape() const;

  public:
    explicit __forceinline hkpCdBody(const hkpCdBody* parent);
    __forceinline const hkMotionState* GetMotionState() const;

  public:
    const hkpShape* m_pCollisionShape;
    hkpShapeKey m_uiCollisionShapeKey;
    const void* m_pMotionState;
public:
    __forceinline const hkpShape* getShape() const
    {
        return m_pCollisionShape;
    }
    __forceinline const hkMotionState* GetMotionState() const
    {
        return reinterpret_cast<const hkMotionState*>(m_pMotionState);
    }
};
const hkMotionState* hkpCdBody::GetMotionState() const
{
    return static_cast<const hkMotionState*>(m_pMotionState);
}
const hkpShape* hkpCdBody::getShape() const
{
    return m_pCollisionShape;
}
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
struct AgentProcessingInput
{
    ValueWrapper<const hkpCdBody*> m_pBodyA;
    ValueWrapper<const hkpCdBody*> m_pBodyB;
    ValueWrapper<const hkpCdBody*> m_pAdditionalCollidableBody;
    ValueWrapper<const GskAgentInput*> m_pRayCastInput;
    ValueWrapper<hkpContactMgr*> m_pContactManager;
    hkTransform m_kTransform;
};
struct AgentSubtypeMarker : public AgentProcessingInput
{
    ValueWrapper<hkReal> m_fSubtypeValue;
    hkVector4X m_vSubtypePosition;
};
struct CollisionQualityInfo
{
    __declspec(align(16)) hkReal m_fMinimumCollisionSeparation;
    hkReal m_fMinimumExtraSeparation;
    hkReal m_fMaximumExtraSeparation;
    hkReal m_fTimeOfImpactSeparation;
    ValueWrapper<hkBool32> m_iQualityInfoValue10;
    hkBool m_bUseContinuousPhysics;
    hkReal m_fCreateContactThreshold;
    hkReal m_fManifoldTimeDistance;
    hkReal m_fMinimumSafeDeltaTime;
    hkReal m_fMinimumAbsoluteTimeOfImpact;
    hkReal m_fMinimumTimeOfImpactDelta;
    hkReal m_fMaximumTimeOfImpactDelta;
    hkReal m_fMaximumConstraintViolation;
    hkReal m_fMaximumLinearVelocity;
    hkReal m_fMaximumAngularVelocity;
    hkUint16 m_usValueAtOffset3C;
    hkBool m_bEnableToiWeldRejection;
};
class hkpCollisionFilter;
class hkpConvexListFilter;
struct CollisionAgentContext
{
  public:
    hkReal getTolerance() const
    {
        return m_fScalar;
    }

  public:
    ValueWrapper<hkpCollisionDispatcher*> m_pCollisionDispatcher;
    ValueWrapper<hkReal> m_fScalar;
    ValueWrapper<const hkpCollisionFilter*> m_iFilter;
    ValueWrapper<const hkpConvexListFilter*> m_pConvexListCollisionFilter;
    mutable ValueWrapper<hkBool32> m_bCreatePredictiveAgents;
    struct AabbBoundsAndScale
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(
                    p, sizeof(CollisionAgentContext::AabbBoundsAndScale));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        hkVector4X m_kAabbMin;
        hkVector4X m_kAabbMaximum;
        hkVector4X m_kAabbScale;
    };
    AabbBoundsAndScale m_aiValues;
};
struct CollisionContactResults;
class ConvexFeaturePairCache;
class ContactImpulseInfo
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    inline ContactImpulseInfo();
    inline void init();

  public:
    hkReal m_fAccumulatedImpulse;
    hkReal m_fImpulseLimit;
public:
    __forceinline ContactImpulseInfo()
    {
        init();
    }
    __forceinline void init()
    {
        m_fAccumulatedImpulse = 0.0f;
        m_fImpulseLimit = 0.0f;
    }
};
inline void ContactImpulseInfo::init()
{
    m_fAccumulatedImpulse = 0.0f;
    m_fImpulseLimit = 0.0f;
}
inline ContactImpulseInfo::ContactImpulseInfo()
{
    init();
}
class hkContactPointMaterial
{
  public:
    static const struct ClassMemberDescriptor Members[];

  protected:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    hkUlong m_ulUserData;
    QuantizedFloat8 m_fSlipAngle;
    hkUint8 m_fElasticity;

  public:
    QuantizedFloat8 m_usFlags;

  public:
    void reset()
    {
        m_fSlipAngle.m_uiFilterValue = 0;
        m_usFlags.m_uiFilterValue = 0;
        m_fElasticity = 0;
        m_flags = CONTACT_IS_NEW;
    }
    enum FlagEnum
    {
        CONTACT_IS_NEW = 1,
        CONTACT_USES_SOLVER_PATH2 = 2,
        CONTACT_BREAKOFF_OBJECT_ID = 4,
        CONTACT_IS_DISABLED = 8
    };
    hkUint8 m_flags;
public:
    __forceinline hkContactPointMaterial()
    {}
};
class PhysicsMaterial : public ContactImpulseInfo, public hkContactPointMaterial
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    hkReal m_uiUserData;
    typedef hkUint32 UserData;
public:
    __forceinline PhysicsMaterial()
    {}
};
__declspec(align(16)) class ContactDataPhysicsMaterial : public PhysicsMaterial
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    void set(const ContactDataPhysicsMaterial& other)
    {
        *this = other;
    }
    UserData m_aiContactData[7];
};
class hkpContactMgr : public hkReferencedObject
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        hkReferencedObject* b = static_cast<hkReferencedObject*>(
            NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));
        b->m_usMemSizeAndFlags = static_cast<hkUint16>(nbytes);
        ;
        return b;
    }
    enum Type
    {
        TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
        TYPE_REPORT_CONTACT_MGR,
        TYPE_CONVEX_LIST_CONTACT_MGR,
        TYPE_NULL_CONTACT_MGR,
        TYPE_USER_CONTACT_MGR,
        TYPE_MAX
    };
    enum ToiAccept
    {
        TOI_ACCEPT = 0,
        TOI_REJECT = 1
    };
    __forceinline ToiAccept addToi(const hkpCdBody& a, const hkpCdBody& b, const GskAgentInput& input,
                                   WorldOperationEntry& output, hkTime toi, hkContactPoint& cp,
                                   const ConvexFeaturePairCache* gskCache, hkReal& projectedVelocity,
                                   PhysicsMaterial& propertiesOut);
    __forceinline void removeToi(class hkpConstraintOwner& constraintOwner, PhysicsMaterial& properties);

  public:
    virtual hkContactPointId CreateContactPoint(const hkpCdBody& a, const hkpCdBody& b, const GskAgentInput& input,
                                                WorldOperationEntry& output, const ConvexFeaturePairCache* contactCache,
                                                hkContactPoint& cp) = 0;
    virtual hkResult ReserveContactPoints(int numPoints) = 0;
    virtual void removeContactPointImpl(hkContactPointId cpId, hkpConstraintOwner& constraintOwner) = 0;
    virtual void ProcessCollisionContact(const hkpCollidable& a, const hkpCollidable& b, const GskAgentInput& input,
                                    CollisionContactResults& collisionData) = 0;
    virtual ToiAccept AddToi(const hkpCdBody& a, const hkpCdBody& b, const GskAgentInput& input,
                                 WorldOperationEntry& output, hkTime toi, hkContactPoint& cp,
                                 const ConvexFeaturePairCache* gskCache, hkReal& projectedVelocity,
                                 PhysicsMaterial& propertiesOut) = 0;
    virtual void UpdatePhysicsMaterial(class hkpConstraintOwner& constraintOwner, PhysicsMaterial& properties) = 0;

  public:
    Type m_type;
};
hkpContactMgr::ToiAccept hkpContactMgr::addToi(const hkpCdBody& a, const hkpCdBody& b, const GskAgentInput& input,
                                               WorldOperationEntry& output, hkTime toi, hkContactPoint& cp,
                                               const ConvexFeaturePairCache* gskCache, hkReal& projectedVelocity,
                                               PhysicsMaterial& propertiesOut)
{
    return AddToi(a, b, input, output, toi, cp, gskCache, projectedVelocity, propertiesOut);
}
void hkpContactMgr::removeToi(class hkpConstraintOwner& constraintOwner, PhysicsMaterial& properties)
{
    UpdatePhysicsMaterial(constraintOwner, properties);
}
struct ContactPointWithId
{
    hkContactPoint m_kPoint;
    ValueWrapper<hkUint32> m_usContactPointId;
};
class hkStepInfo
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    __declspec(align(16)) ValueWrapper<hkTime> m_uiStartTime;
    ValueWrapper<hkTime> m_fEndTime;
    ValueWrapper<hkReal> m_fTimeStep;
    ValueWrapper<hkReal> m_fInverseDeltaTime;
};
struct hkpAgent1nSector;
struct GskAgentInput : public CollisionAgentContext
{
  public:
    GskAgentInput() : m_pAgent1nSector(0)
    {}

  public:
    hkStepInfo m_pStepInfo;
    mutable ValueWrapper<CollisionQualityInfo*> m_pCollisionQualityInfo;
    mutable hkpAgent1nSector* m_pAgent1nSector;
};
class ConvexFeaturePairCache
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    hkUint16 m_kVertices[4];

  public:
    void init(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& btoa);
};
__declspec(align(16)) class HeapContactFeatureCache : public ConvexFeaturePairCache
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    void set(const HeapContactFeatureCache& other)
    {
        *this = other;
    }
};
enum
{
    HK_MAX_CONTACT_POINT = 256
};
struct FourByteState;
struct CollisionContactResults
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }
    inline hkBool hasToi() const;

  public:
    ValueWrapper<ContactPointWithId*> m_pAlignedPairData;
    ValueWrapper<hkpConstraintOwner*> m_pConstraintOwner;
    ContactPointWithId m_akContactPoints[HK_MAX_CONTACT_POINT];
    struct CollisionCacheState
    {
      public:
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(
                    p, sizeof(CollisionContactResults::CollisionCacheState));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        inline CollisionCacheState();
        inline void flip();

      public:
        hkContactPoint m_vContactPoint;
        ValueWrapper<hkReal> m_uiCommandId;
        ValueWrapper<hkReal> m_fSeparation;
        HeapContactFeatureCache m_kGskCache;
        ContactDataPhysicsMaterial m_kProperties;
    };
    struct CollisionCacheState m_fTimeOfImpact;
};
inline hkBool CollisionContactResults::hasToi() const
{
    return m_fTimeOfImpact.m_uiCommandId != 3.40282e+38f;
}
struct WorldOperationEntry : public CollisionContactResults
{
  public:
    __forceinline void* __cdecl operator new(hk_size_t nbytes)
    {
        ;
        void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
        ;
        return obj;
    }

  public:
    struct ContactPointAgentEntry
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(
                    p, sizeof(WorldOperationEntry::ContactPointAgentEntry));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        ContactPointWithId* m_vContactPoint;
        FourByteState* m_pAgentEntry;
        void* m_pUserData;
    };
    struct ContactPointBuffer
    {
        __forceinline void* __cdecl operator new(hk_size_t nbytes)
        {
            ;
            void* obj = NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));
            ;
            return obj;
        }
        __forceinline void __cdecl operator delete(void* p)
        {
            if (p)
            {
                ;
                NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(
                    p, sizeof(WorldOperationEntry::ContactPointBuffer));
            }
        }
        __forceinline void* __cdecl operator new(hk_size_t n, void* p)
        {
            ;
            return p;
        }
        __forceinline void* __cdecl operator new[](hk_size_t, void* p)
        {
            return p;
        }
        __forceinline void __cdecl operator delete(void*, void*)
        {}
        __forceinline void __cdecl operator delete[](void*, void*)
        {}
        class CommandArgument;
        void reset()
        {
            m_pFirstFreeContactPoint = &m_akContactRecords[0];
            m_ppFirstFreeContactPointer = &m_apContactPointPointers[0];
        }
        ContactPointAgentEntry* m_pFirstFreeContactPoint;
        ContactPointWithId** m_ppFirstFreeContactPointer;
        ContactPointWithId* m_apContactPointPointers[HK_MAX_CONTACT_POINT];
        ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
    };

  public:
    ValueWrapper<ContactPointBuffer*> m_akContactRecords;
};
namespace MotionUtilities {
__forceinline void __cdecl calcAngularTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                              hkVector4X* deltaAngleOut0, hkVector4X* deltaAngleOut1);
}
void __cdecl MotionUtilities::calcAngularTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                                 hkVector4X* __restrict deltaAngleOut0,
                                                 hkVector4X* __restrict deltaAngleOut1)
{
    const hkSweptTransform& st0 = ms0.getSweptTransform();
    const hkSweptTransform& st1 = ms1.getSweptTransform();
    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();
    hkVector4X ang0;
    ang0.setMul4(f0, ms0.m_kDeltaAngle);
    hkVector4X ang1;
    ang1.setMul4(f1, ms1.m_kDeltaAngle);
    deltaAngleOut0[0] = ang0;
    deltaAngleOut1[0] = ang1;
}
namespace hkVector4XUtil {
__forceinline void __cdecl TransformPointArray(const hkTransform& t, const hkVector4X* vectorsIn, int numVectors,
                                               hkVector4X* vectorsOut);
}
inline void __cdecl hkVector4XUtil::TransformPointArray(const hkTransform& t, const hkVector4X* vectorsIn,
                                                        int numVectors, hkVector4X* vectorsOut)
{
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
class hkpSphereRepShape : public hkpShape
{
  public:
    static const struct ClassMemberDescriptor Members[];
    __forceinline int getNumCollisionSpheres() const;
    __forceinline const hkSphere* getCollisionSpheres(hkSphere* sphereBuffer) const;

  protected:
    virtual int GetNumCollisionSpheres() const = 0;
    virtual const hkSphere* GetCollisionSpheres(hkSphere* sphereBuffer) const = 0;

  public:
    hkpSphereRepShape(CollisionShapeType type) : hkpShape(type)
    {}
    hkpSphereRepShape(FinishingFlag flag) : hkpShape(flag)
    {
        m_type = HK_SHAPE_SPHERE_REP;
    }
};
int hkpSphereRepShape::getNumCollisionSpheres() const
{
    return this->GetNumCollisionSpheres();
}
const hkSphere* hkpSphereRepShape::getCollisionSpheres(hkSphere* sphereBuffer) const
{
    return this->GetCollisionSpheres(sphereBuffer);
}
class hkpConvexShape : public hkpSphereRepShape
{
  public:
    static const struct ClassMemberDescriptor Members[];
    virtual void GetFirstVertex(hkVector4X& v) const = 0;
    inline hkReal getRadius() const;
    enum WeldResult
    {
        WELD_RESULT_REJECT_CONTACT_POINT,
        WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
        WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
    };
    __forceinline hkpConvexShape::WeldResult weldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                                                              hkVector4X& contactPointWs,
                                                              const hkTransform* thisObjTransform,
                                                              const hkpConvexShape* collidingShape,
                                                              const hkTransform* collidingTransform,
                                                              hkVector4X& separatingNormalInOut) const;

  protected:
    virtual void GetSupportVertex(hkVector4XParameter direction, Vector4WithInt24W& supportingVertexOut) const = 0;
    virtual void GetVerticesFromIds(const hkpVertexId* ids, int numIds, Vector4WithInt24W* vertixArrayOut) const = 0;
    virtual int WeldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints, hkVector4X& contactPointWs,
                                 const hkTransform* thisObjTransform, const hkpConvexShape* collidingShape,
                                 const hkTransform* collidingTransform, hkVector4X& separatingNormalInOut) const;

  protected:
    inline hkpConvexShape(CollisionShapeType type, hkReal radius);
    hkReal m_fSphereRadius;

  public:
    hkpConvexShape(FinishingFlag flag) : hkpSphereRepShape(flag)
    {
        m_type = HK_SHAPE_CONVEX;
    }
};
inline hkReal hkpConvexShape::getRadius() const
{
    return m_fSphereRadius;
}
hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(hkpVertexId* featurePoints, hkUint8& numFeaturePoints,
                                                            hkVector4X& contactPointWs,
                                                            const hkTransform* thisObjTransform,
                                                            const hkpConvexShape* collidingShape,
                                                            const hkTransform* collidingTransform,
                                                            hkVector4X& separatingNormalInOut) const
{
    return (WeldResult)this->WeldContactPoint(featurePoints, numFeaturePoints, contactPointWs, thisObjTransform,
                                              collidingShape, collidingTransform, separatingNormalInOut);
}
struct ContactPointWeldingParameters
{
    ValueWrapper<hkReal> m_fMinimumTimeOfImpactDelta;
    ValueWrapper<hkReal> m_fCreateContactThreshold;
    ValueWrapper<hkReal> m_fThirdContactParameter;
    ValueWrapper<hkReal> m_fMaximumAngularVelocity;
    ValueWrapper<hkReal> m_fMaximumConstraintViolation;
};
struct ConvexCollisionQueryData
{
    ValueWrapper<const hkMotionState*> m_pFirstQueryData;
    ValueWrapper<const hkMotionState*> m_pSecondQueryData;
    ValueWrapper<hkVector4X*> m_akPackedVerticesA;
    ValueWrapper<int> m_iStridedVertexCount;
    ValueWrapper<int> m_iSecondPackedVertexCount;
    ValueWrapper<hkReal> m_kFourthBasisVector;
    ValueWrapper<hkReal> m_fSecondBasisScalar;
    ValueWrapper<hkReal> m_fThirdBasisScalar;
    hkVector4X m_vFirstStoredVector;
    hkVector4X m_vSecondStoredVector;
    ValueWrapper<const hkStepInfo*> m_pStepInfo;
    ValueWrapper<hkReal> m_fStepTimeParameter;
    hkVector4X m_vSubtypePosition;
    hkVector4X m_avSubtypeVectors[2];
    ValueWrapper<hkReal> m_fFinalQueryParameter;
public:
    __forceinline ConvexCollisionQueryData()
    {}
};
struct ScalarVectorData
{
    ScalarVectorData()
    {
        m_fScale = 1.0f;
    }
    ValueWrapper<hkReal> m_fScale;
    hkVector4X m_vVector;
public:
    __forceinline ScalarVectorData() : m_Rt(1.0f)
    {}
};
struct CollisionSolverInput
{
    hkTransform m_pTransformB;
    hkTransform m_pTransformA;
    hkTransform m_kTransform;
    hkVector4X m_kTriangleNormal;
    hkVector4X m_vContactNormal;
    hkVector4X m_vLinearVelocity;
    hkVector4X m_vAngularVelocity[2];
    hkVector4X m_vMassCenterA;
    hkVector4X m_vMassCenterB;
public:
    __forceinline CollisionSolverInput()
    {}
};
enum hkpGskStatus
{
    HK_GSK_OK,
    HK_GSK_2,
    HK_GSK_3
};
class ConvexShapePairCache
{
  public:
    __forceinline void getClosestPointAinA(const hkVector4X& separatingNormal, hkVector4X& pointInA)
    {
        if (m_ucDimensionA == 1)
        {
            pointInA = m_akPackedVerticesA[0];
        }
        else if (m_ucDimensionB == 1)
        {
            pointInA = m_akCachedVectors[0];
            pointInA.addMul4(separatingNormal.getSimdAt(3), separatingNormal);
        }
        else
        {
            pointInA = m_kVectorPairResult[0];
        }
    }
    ValueWrapper<int> m_ucDimensionA;
    ValueWrapper<int> m_ucDimensionB;
    ValueWrapper<int> m_ucFeatureTypeA;
    int m_unkA;
    int m_unkB;
    Vector4WithInt24W m_akPackedVerticesA[4];
    hkVector4X m_unkC0;
    hkVector4X m_unkC1;
    hkVector4X m_unkC2;
    hkVector4X m_unkC3;
    hkVector4X m_akCachedVectors[4];
    Vector4WithInt24W m_akPackedVerticesB[4];
    hkVector4X m_pSupport;
    hkVector4X m_kVectorPairResult[3];
public:
    __forceinline ConvexShapePairCache() : m_uiCacheFlags(0)
    {}
    __forceinline void setFeatureChange(int f)
    {
        m_iFeatureChange = f;
    }
    __forceinline void init(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const ConvexFeaturePairCache& cache)
    {
        m_ucDimensionA = cache.m_ucDimensionA;
        m_ucDimensionB = cache.m_ucDimensionB;
        m_ucFeatureTypeA = cache.m_ucFeatureTypePair & 0xf;
        m_ucFeatureTypeB = (cache.m_ucFeatureTypePair >> 4) & 0xf;
        setFeatureChange(0);
        shapeA->GetVerticesForIds(cache.m_kVertices, m_ucDimensionA, &m_akPackedVerticesA[0]);
        shapeB->GetVerticesForIds(cache.m_kVertices + m_ucDimensionA, m_ucDimensionB, &m_akPackedVerticesB[0]);
    }
    int FUN_00daad40(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB, const hkTransform& aTb,
                     hkVector4& separatingNormal);
    __forceinline int GetClosestPoint(const hkpConvexShape* shapeA, const hkpConvexShape* shapeB,
                                        const hkTransform& aTb, hkVector4& separatingNormal)
    {
        return FUN_00daad40(shapeA, shapeB, aTb, separatingNormal);
    }
    __forceinline void WriteContactFeatureCache(ConvexFeaturePairCache& cache) const
    {
        reinterpret_cast<::ThisClass *>((void *)this)->FUN_00da9790((::Dest *)&(cache));
    }
    __forceinline void checkForChangesAndUpdateCache(ConvexFeaturePairCache& cache) const
    {
        if (!m_iFeatureChange)
            return;
        reinterpret_cast<::ThisClass *>((void *)this)->FUN_00da9790((::Dest *)&(cache));
    }
    __forceinline void getClosestPointAinA(const hkVector4& separatingNormal, hkVector4& pointOnAinA)
    {
        if (m_ucDimensionA == 1)
        {
            pointOnAinA = m_akPackedVerticesA[0];
        }
        else if (m_ucDimensionB == 1)
        {
            pointOnAinA = m_akCachedVectors[0];
            pointOnAinA.addMul4(separatingNormal.getSimdAt(3), separatingNormal);
        }
        else
        {
            pointOnAinA = m_closestLineSegResult.m_kFirstVector;
        }
    }
};
__forceinline void hk4dGskCollPInputInitialize(const AgentSubtypeMarker& in3,
                                               ConvexCollisionQueryData& collPInput)
{
    const hkpConvexShape* shapeA = (const hkpConvexShape*)in3.m_pBodyA->getShape();
    const hkpConvexShape* shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
    const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
    const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
    collPInput.m_pFirstQueryData = msA;
    collPInput.m_pSecondQueryData = msB;
    collPInput.m_kFourthBasisVector = shapeA->getRadius() + shapeB->getRadius();
    collPInput.m_vSubtypePosition = in3.m_vSubtypePosition;
    collPInput.m_pStepInfo = &in3.m_pRayCastInput->m_pStepInfo;
    int numSpheres = shapeA->getNumCollisionSpheres();
    collPInput.m_iSecondPackedVertexCount = numSpheres;
    collPInput.m_iStridedVertexCount = numSpheres;
    collPInput.m_akPackedVerticesA = hkAllocateStack<hkVector4X>(numSpheres);
    shapeA->getCollisionSpheres((hkSphere*)collPInput.m_akPackedVerticesA.val());
    hkReal mA = msA->m_fObjectRadius * collPInput.m_avSubtypeVectors[0](3) * collPInput.m_avSubtypeVectors[0](3);
    hkReal mB = msB->m_fObjectRadius * collPInput.m_avSubtypeVectors[1](3) * collPInput.m_avSubtypeVectors[1](3);
    collPInput.m_fSecondBasisScalar = mA + mB;
    collPInput.m_fThirdBasisScalar = 1.0f / (collPInput.m_fSecondBasisScalar + 1.192092896e-07F);
}
__forceinline hkReal hk4dGskCalcPointVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                              const hkVector4X& separatingPoint, const hkVector4X& separatingNormal,
                                              const hkVector4X& linearTimInfo, const hkVector4X* deltaAngles, hkReal t)
{
    hkVector4X relVel;
    relVel.setNeg4(linearTimInfo);
    {
        hkReal relT = msA->getSweptTransform().getInterpolationValue(t);
        hkVector4X massCenter;
        massCenter.setInterpolate4(msA->getSweptTransform().m_vCenterOfMass0, msA->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4X relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4X arm;
        arm.setCross(deltaAngles[0], relPos);
        relVel.add4(arm);
    }
    {
        hkReal relT = msB->getSweptTransform().getInterpolationValue(t);
        hkVector4X massCenter;
        massCenter.setInterpolate4(msB->getSweptTransform().m_vCenterOfMass0, msB->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4X relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4X arm;
        arm.setCross(deltaAngles[1], relPos);
        relVel.sub4(arm);
    }
    hkReal separatingVelocity = relVel.dot3(separatingNormal);
    return separatingVelocity;
}
static __declspec(noinline) hkReal
    CalcSeparatingVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                                    const hkVector4X& separatingPoint,
                                                    const hkVector4X& separatingNormal, const hkVector4X& linearTimInfo,
                                                    const hkVector4X* deltaAngles, hkReal t)
{
    const float angularVelocityFactor = 1.2f;
    hkVector4X relVel;
    relVel.setNeg4(linearTimInfo);
    hkReal separatingVelocity = relVel.dot3(separatingNormal);
    {
        hkReal relT = msA->getSweptTransform().getInterpolationValue(t);
        hkVector4X massCenter;
        massCenter.setInterpolate4(msA->getSweptTransform().m_vCenterOfMass0, msA->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4X relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4X arm;
        arm.setCross(deltaAngles[0], relPos);
        hkReal angVelPart = arm.dot3(separatingNormal);
        if (angVelPart <= 0.0f)
        {
            separatingVelocity += angVelPart * angularVelocityFactor;
        }
        else
        {
            separatingVelocity += angVelPart / angularVelocityFactor;
        }
    }
    {
        hkReal relT = msB->getSweptTransform().getInterpolationValue(t);
        hkVector4X massCenter;
        massCenter.setInterpolate4(msB->getSweptTransform().m_vCenterOfMass0, msB->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4X relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4X arm;
        arm.setCross(deltaAngles[1], relPos);
        hkReal angVelPart = arm.dot3(separatingNormal);
        if (angVelPart >= 0.0f)
        {
            separatingVelocity -= angVelPart * angularVelocityFactor;
        }
        else
        {
            separatingVelocity -= angVelPart / angularVelocityFactor;
        }
    }
    return separatingVelocity;
}
__forceinline void hk4dGskCalcWorstCaseProjectedVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                                         const hkVector4X& separatingNormal,
                                                         const hkVector4X& linearTimInfo, const hkVector4X* deltaAngles,
                                                         hkReal& realProjectedLinearDelta,
                                                         hkReal& projectedAngularDelta)
{
    hkVector4X crossAngleA;
    crossAngleA.setCross(deltaAngles[0], separatingNormal);
    hkVector4X crossAngleB;
    crossAngleB.setCross(deltaAngles[1], separatingNormal);
    hkReal lenA = hkReal(crossAngleA.length3()) * msA->m_fObjectRadius;
    hkReal lenB = hkReal(crossAngleB.length3()) * msB->m_fObjectRadius;
    projectedAngularDelta = lenA + lenB;
    realProjectedLinearDelta = linearTimInfo.dot3(separatingNormal);
}
static __forceinline void hkGskRecalcContact(ConvexShapePairCache* gsk, const hkVector4X* masterNormalA,
                                             hkVector4X* pointBinAOut, hkVector4X* supportOut)
{
    ::FUN_00da8a00((::ContactVector *)(gsk->m_akPackedVerticesA), (::ContactVector *)(gsk->m_akCachedVectors), gsk->m_ucDimensionA,
                               gsk->m_ucDimensionB, (*(const ::ContactVector *)(masterNormalA)), (*(::ContactVector *)(pointBinAOut)), (*(::ContactVector *)(supportOut)));
}
// @fnv 0x00db54b0
static __declspec(noinline) void FUN_00db54b0(const AgentSubtypeMarker& in3, ContactPointWeldingParameters& tol,
                                              ConvexShapePairCache& gsk, int featureChange,
                                              const hkVector4X& oldMasterNormal, const hkVector4X* deltaAngles,
                                              hkReal startRt, hkReal endRt, hkReal distance0, hkReal distance1,
                                              WorldOperationEntry& out)
{
    CollisionSolverInput mat;
    hkReal Rt = startRt;
    hkReal distance = distance0;
    hkTransform wTa;
    hkTransform wTb;
    hkTransform aTb;
    const hkpConvexShape* shapeA = (const hkpConvexShape*)in3.m_pBodyA->getShape();
    const hkpConvexShape* shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
    hkReal radiusSum = shapeA->getRadius();
    radiusSum += shapeB->getRadius();
    hkReal velocityBasedOnDistance = (distance1 - distance0) / (endRt - startRt);
    hkVector4X normalA;
    hkVector4X pointA;
    for (int iteration = 0; iteration < 10; iteration++)
    {
        hkReal delta = distance1 - distance0;
        if (delta > -tol.m_fMaximumConstraintViolation)
        {
            endRt = startRt;
            delta = 0.5f;
        }
        hkBool earlyOut;
        if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(MathUtilities::equal(distance1, tol.m_fMinimumTimeOfImpactDelta, tol.m_fMaximumConstraintViolation)))->FUN_005609f0())
        {
            earlyOut = true;
            featureChange = 0;
            Rt = endRt;
        }
        else
        {
            earlyOut = false;
            hkReal rel = (tol.m_fMinimumTimeOfImpactDelta - distance0) / delta;
            rel = ::FUN_00c98210(rel, 0.1f);
            rel = MathUtilities::min2(rel, 0.9f);
            Rt = (1.0f - rel) * startRt + endRt * rel;
        }
        const hkStepInfo* stepInfo = &in3.m_pRayCastInput->m_pStepInfo;
        hkReal timeAddon = stepInfo->m_fTimeStep * Rt;
        ::fnv_00cf1710::FUN_00cf1710((const ::fnv_00cf1710::hkSweptTransformL &)(in3.m_pBodyA->GetMotionState()->getSweptTransform()), stepInfo->m_uiStartTime,
                                 timeAddon, (::fnv_00cf1710::hkTransformL &)(wTa));
        ::fnv_00cf1710::FUN_00cf1710((const ::fnv_00cf1710::hkSweptTransformL &)(in3.m_pBodyB->GetMotionState()->getSweptTransform()), stepInfo->m_uiStartTime,
                                 timeAddon, (::fnv_00cf1710::hkTransformL &)(wTb));
        reinterpret_cast<::hkTransformCB22 *>(&(aTb))->FUN_00cb22f0((const ::hkTransformCB22 &)(wTa), (const ::hkTransformCB22 &)(wTb));
        if (featureChange)
        {
            const hkpConvexShape* shapeA = (const hkpConvexShape*)in3.m_pBodyA->getShape();
            const hkpConvexShape* shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
            reinterpret_cast<::GapSolver *>(&(gsk))->FUN_00daad40((const ::GapShape *)(shapeA), (const ::GapShape *)(shapeB), (const ::GapTransform &)(aTb), (::GapVector &)(normalA));
            gsk.getClosestPointAinA(normalA, pointA);
        }
        else
        {
            hkVector4XUtil::TransformPointArray(aTb, gsk.m_akPackedVerticesB, gsk.m_ucDimensionB,
                                                gsk.m_akCachedVectors);
            hkVector4X oldMasterNormalInA;
            reinterpret_cast<::FUN_004b4ab0_Class *>(&(oldMasterNormalInA))->FUN_004b4ab0((int)&(wTa.getRotation()), (int)&(oldMasterNormal));
            hkGskRecalcContact(&gsk, &oldMasterNormalInA, &pointA, &normalA);
        }
        distance = normalA(3) - radiusSum;
        if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(MathUtilities::equal(distance, tol.m_fMinimumTimeOfImpactDelta, tol.m_fMaximumConstraintViolation)))->FUN_005609f0() ||
            reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(earlyOut))->FUN_005609f0())
        {
            break;
        }
        if (startRt == endRt)
        {
            break;
        }
        if (tol.m_fMinimumTimeOfImpactDelta > distance)
        {
            endRt = Rt;
            distance1 = distance;
        }
        else
        {
            startRt = Rt;
            distance0 = distance;
        }
    }
    const hkStepInfo* stepInfo = &in3.m_pRayCastInput->m_pStepInfo;
    hkReal deltaTime = ::FUN_00c98210(stepInfo->m_fTimeStep.val() * Rt, tol.m_fMaximumAngularVelocity.val());
    hkReal toi = stepInfo->m_uiStartTime + deltaTime;
    ;
    ;
    if (toi < out.m_fTimeOfImpact.m_uiCommandId && stepInfo->m_fEndTime - tol.m_fMaximumAngularVelocity > toi)
    {
        HeapContactFeatureCache cache;
        hkReal separatingVelocity;
        const hkpConvexShape* shapeA = (const hkpConvexShape*)in3.m_pBodyA->getShape();
        hkpContactMgr::ToiAccept cbResult;
        hkContactPoint cp;
        {
            const hkMotionState* msA;
            hkVector4X pointWs;
            hkpConvexShape::WeldResult weldResult;
            const hkMotionState* msB;
            pointWs.SetTransformedPoint(wTa, pointA);
            cp.getSeparatingNormal().SetRotatedDirection(wTa.getRotation(), normalA);
            cp.getPosition().setAddMul4(pointWs, cp.getSeparatingNormal(), -shapeA->getRadius() - distance);
            cp.setDistance(distance);
            weldResult = hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
            hkVector4X weldedNormal = cp.getSeparatingNormal();
            if (in3.m_pBodyB->getShape()->getType() == HK_SHAPE_TRIANGLE)
            {
                {
                    hkpVertexId featurePoints[3];
                    hkUint8 numFeaturePoints;
                    const hkpConvexShape* shapeB;
                    numFeaturePoints = gsk.m_ucDimensionB;
                    featurePoints[0] = gsk.m_akPackedVerticesB[0].GetValueForType();
                    featurePoints[1] =
                        numFeaturePoints < 2 ? 0xffff : hkpVertexId(gsk.m_akPackedVerticesB[1].GetValueForType());
                    featurePoints[2] =
                        numFeaturePoints < 3 ? 0xffff : hkpVertexId(gsk.m_akPackedVerticesB[2].GetValueForType());
                    shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
                    weldResult = shapeB->weldContactPoint(featurePoints, numFeaturePoints, cp.getPosition(), &wTb,
                                                          shapeA, &wTa, weldedNormal);
                }
                cp.setSeparatingNormal(weldedNormal);
            EXAMINE_WELD_RESULTS:
                if (weldResult == hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT &&
                    reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(in3.m_pRayCastInput->m_pCollisionQualityInfo->m_bEnableToiWeldRejection))->FUN_005609f0())
                {
                    return;
                }
            }
            else if (in3.m_pBodyA->getShape()->getType() == HK_SHAPE_TRIANGLE)
            {
                hkpVertexId featurePoints[3];
                hkUint8 numFeaturePoints;
                hkVector4X dist;
                hkVector4X pointOnA;
                const hkpConvexShape* shapeB;
                numFeaturePoints = gsk.m_ucDimensionA;
                featurePoints[0] = gsk.m_akPackedVerticesA[0].GetValueForType();
                featurePoints[1] =
                    numFeaturePoints < 2 ? 0xffff : hkpVertexId(gsk.m_akPackedVerticesA[1].GetValueForType());
                featurePoints[2] =
                    numFeaturePoints < 3 ? 0xffff : hkpVertexId(gsk.m_akPackedVerticesA[2].GetValueForType());
                dist.setBroadcast(weldedNormal, 3);
                pointOnA.setAddMul4(cp.getPosition(), weldedNormal, dist);
                weldedNormal.setNeg3(weldedNormal);
                shapeB = (const hkpConvexShape*)in3.m_pBodyB->getShape();
                weldResult = shapeA->weldContactPoint(featurePoints, numFeaturePoints, pointOnA, &wTa, shapeB, &wTb,
                                                      weldedNormal);
                weldedNormal.setNeg3(weldedNormal);
                cp.setSeparatingNormal(weldedNormal);
                goto EXAMINE_WELD_RESULTS;
            }
            msA = in3.m_pBodyA->GetMotionState();
            msB = in3.m_pBodyB->GetMotionState();
            separatingVelocity = hk4dGskCalcPointVelocity(msA, msB, cp.getPosition(), cp.getNormal(),
                                                          in3.m_vSubtypePosition, deltaAngles, toi);
            if (weldResult == hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED &&
                separatingVelocity > -1.1920929e-7f)
            {
                ConvexCollisionQueryData collPInput;
                collPInput.m_fFinalQueryParameter = Rt;
                MotionUtilities::calcAngularTimInfo(*msA, *msB, in3.m_pRayCastInput->m_pStepInfo.m_fTimeStep,
                                                    &collPInput.m_avSubtypeVectors[0], &collPInput.m_avSubtypeVectors[1]);
                {
                    hkReal realProjectedLinearDelta;
                    hkReal projectedAngularDelta;
                    hk4dGskCalcWorstCaseProjectedVelocity(msA, msB, cp.getNormal(), in3.m_vSubtypePosition,
                                                          collPInput.m_avSubtypeVectors, realProjectedLinearDelta,
                                                          projectedAngularDelta);
                    collPInput.m_fStepTimeParameter = realProjectedLinearDelta + projectedAngularDelta;
                }
                hk4dGskCollPInputInitialize(in3, collPInput);
                reinterpret_cast<::FUN_004b4ab0_Class *>(&(collPInput.m_vFirstStoredVector))->FUN_004b4ab0((int)&(wTb.getRotation()), (int)&(cp.getNormal()));
                collPInput.m_vSecondStoredVector = gsk.m_akPackedVerticesB[0];
                if (collPInput.m_akPackedVerticesA.val())
                {
                    ScalarVectorData collidePointsOut;
                    ::FUN_00db4e40((::SweepObj *)&(collPInput), (float *)&(tol), (::SweepOut *)&(collidePointsOut));
                    hkDeallocateStack<hkVector4X>(collPInput.m_akPackedVerticesA.val());
                    if (collidePointsOut.m_fScale < 1.0f)
                    {
                        hkVector4X newPos;
                        newPos.SetTransformedPoint(wTa, collidePointsOut.m_vVector);
                        cp.getPosition() = newPos;
                    }
                }
            }
            if (velocityBasedOnDistance < separatingVelocity)
            {
                if (separatingVelocity * 1.2f < velocityBasedOnDistance)
                {
                    separatingVelocity = velocityBasedOnDistance;
                }
                else
                {
                    separatingVelocity = CalcSeparatingVelocity(
                        in3.m_pBodyA->GetMotionState(), in3.m_pBodyB->GetMotionState(), cp.getPosition(),
                        cp.getNormal(), in3.m_vSubtypePosition, deltaAngles, toi);
                    separatingVelocity = MathUtilities::min2(0.0f, separatingVelocity);
                }
            }
            separatingVelocity *= stepInfo->m_fInverseDeltaTime;
        }
        ContactDataPhysicsMaterial properties;
        MemoryUtils::memClear16(&properties, 3);
        properties.m_uiUserData = DAT_010d5384;
        reinterpret_cast<::ThisClass *>((void *)&(gsk))->FUN_00da9790((::Dest *)&(cache));
        cbResult = in3.m_pContactManager->addToi(*in3.m_pBodyA, *in3.m_pBodyB, *in3.m_pRayCastInput, out, toi, cp,
                                                 &cache, separatingVelocity, properties);
        if (cbResult == hkpContactMgr::TOI_ACCEPT)
        {
            if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(out.hasToi()))->FUN_005609f0())
            {
                in3.m_pContactManager->removeToi(*out.m_pConstraintOwner, out.m_fTimeOfImpact.m_kProperties);
            }
            out.m_fTimeOfImpact.m_fSeparation = separatingVelocity;
            out.m_fTimeOfImpact.m_vContactPoint = cp;
            out.m_fTimeOfImpact.m_uiCommandId = toi;
            out.m_fTimeOfImpact.m_kProperties.set(properties);
            out.m_fTimeOfImpact.m_kGskCache.set(cache);
        }
    }
}
void hk_user(const AgentSubtypeMarker& in3, ContactPointWeldingParameters& tol, ConvexShapePairCache& gsk, int featureChange,
             const hkVector4X& oldMasterNormal, const hkVector4X* deltaAngles, hkReal startRt, hkReal endRt,
             hkReal distance0, hkReal distance1, WorldOperationEntry& out)
{
    FUN_00db54b0(in3, tol, gsk, featureChange, oldMasterNormal, deltaAngles, startRt, endRt, distance0, distance1, out);
}

// Moved from hkpcontinuousgsk_gs_nogs_variant_rtm_variant.cpp (VEGAS-15).
void FUN_00db4b50(void* a, float t, Sample* out);
typedef float hkTime;


template <typename TYPE> class ValueWrapper
{
  public:
    __forceinline ValueWrapper()
    {}
    __forceinline ValueWrapper(TYPE e) : m_kStorage(e)
    {}
    __forceinline void operator=(TYPE e)
    {
        m_kStorage = e;
    }
    __forceinline TYPE val() const
    {
        return m_kStorage;
    }
    __forceinline TYPE operator->() const
    {
        return m_kStorage;
    }
    __forceinline operator TYPE() const
    {
        return val();
    }

  private:
    TYPE m_kStorage;
};
namespace MathUtilities {

template <typename T> __forceinline T min2(T x, T y)
{
    return x < y ? x : y;
}
template <typename T> __forceinline T max2(T x, T y)
{
    return x > y ? x : y;
}
__forceinline hkReal fabs(hkReal r)
{
    return ::fabsf(r);
}
__forceinline hkBool equal(hkReal x, hkReal y, hkReal tolerance2)
{
    return MathUtilities::fabs(x - y) < tolerance2;
}
}

class hkMatrix3;

__forceinline void hkVector4::_setMul3(const hkMatrix3& a, const hkVector4& b)
{
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    const hkQuadReal r0 = _mm_mul_ps(a.getColumn(0).m_vComponents, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    const hkQuadReal r1 = _mm_mul_ps(a.getColumn(1).m_vComponents, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    const hkQuadReal r2 = _mm_mul_ps(a.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void hkVector4::_setRotatedDir(const hkRotation& r, const hkVector4& v)
{
    _setMul3(r, v);
}
__forceinline void hkVector4::_setRotatedInverseDir(const hkRotation& r, const hkVector4& b)
{
    hkQuadReal c0 = r.getColumn(0).m_vComponents;
    hkQuadReal c1 = r.getColumn(1).m_vComponents;
    hkQuadReal c2 = r.getColumn(2).m_vComponents;
    {
        hkQuadReal _tmp, _ctmp;
        _tmp = _mm_unpacklo_ps(c0, c1);
        _ctmp = _mm_shuffle_ps(_mm_unpackhi_ps(c0, c1), c2, _MM_SHUFFLE(3, 2, 1, 0));
        c0 = _mm_movelh_ps(_tmp, c2);
        c1 = _mm_shuffle_ps(_mm_movehl_ps(c0, _tmp), c2, _MM_SHUFFLE(3, 1, 1, 0));
        c2 = _ctmp;
    }
    const hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    const hkQuadReal r0 = _mm_mul_ps(c0, b0);
    const hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    const hkQuadReal r1 = _mm_mul_ps(c1, b1);
    const hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    const hkQuadReal r2 = _mm_mul_ps(c2, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
__forceinline void hkVector4::_setTransformedPos(const hkTransform& t, const hkVector4& b)
{
    const hkRotation& r = t.getRotation();
    hkQuadReal b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(0, 0, 0, 0));
    hkQuadReal r0 = _mm_mul_ps(r.getColumn(0).m_vComponents, b0);
    hkQuadReal b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(1, 1, 1, 1));
    hkQuadReal r1 = _mm_mul_ps(r.getColumn(1).m_vComponents, b1);
    hkQuadReal b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(2, 2, 2, 2));
    hkQuadReal r2 = _mm_mul_ps(r.getColumn(2).m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, t.getTranslation().m_vComponents));
}
__forceinline void hkVector4::_setTransformedInversePos(const hkTransform& a, const hkVector4& b)
{
    hkVector4 t0;
    t0.setSub4(b, a.getTranslation());
    _setRotatedInverseDir(a.getRotation(), t0);
}
namespace MotionUtilities {

__forceinline void calcAngularTimInfo(const hkMotionState& ms0, const hkMotionState& ms1, hkReal deltaTime,
                                      hkVector4* __restrict deltaAngleOut0, hkVector4* __restrict deltaAngleOut1)
{
    const hkSweptTransform& st0 = ms0.getSweptTransform();
    const hkSweptTransform& st1 = ms1.getSweptTransform();
    hkReal f0 = deltaTime * st0.getInvDeltaTime();
    hkReal f1 = deltaTime * st1.getInvDeltaTime();
    hkVector4 ang0;
    ang0.setMul4(f0, ms0.m_kDeltaAngle);
    hkVector4 ang1;
    ang1.setMul4(f1, ms1.m_kDeltaAngle);
    deltaAngleOut0[0] = ang0;
    deltaAngleOut1[0] = ang1;
}
}

class hkSphere;
template <typename ENUM, typename STORAGE> class hkEnum
{
  public:
    __forceinline operator ENUM() const
    {
        return (ENUM)m_kStorage;
    }

  private:
    STORAGE m_kStorage;
};

class hkpConstraintOwner;
class HeapContactFeatureCache : public ConvexFeaturePairCache
{
  public:
    __forceinline void set(const HeapContactFeatureCache& o)
    {
        *this = o;
    }
};
class ContactDataPhysicsMaterial : public PhysicsMaterial
{
  public:
    __forceinline ContactDataPhysicsMaterial()
    {}
    __forceinline void set(const ContactDataPhysicsMaterial& o)
    {
        *this = o;
    }
    hkReal m_uiUserData;
    int m_internal14, m_internal18, m_internal1c;
    int m_extended0, m_extended1, m_extended2, m_extended3;
};
struct ContactPointRecord
{
    hkContactPoint m_vContactPoint;
    ValueWrapper<hkReal> m_uiCommandId;
    ValueWrapper<hkReal> m_pfSeparatingVelocity;
    int m_unk08, m_unk0c;
    HeapContactFeatureCache m_kGskCache;
    ContactDataPhysicsMaterial m_kProperties;
};

class hkLineSegmentResult
{
  public:
    hkVector4 m_kFirstVector;
    hkVector4 m_kClosestPointOnSecond;
    ValueWrapper<hkReal> m_t;
};

__forceinline void hkGskRecalcContact(const ConvexShapePairCache& gsk, const hkVector4& separatingNormal,
                                      hkVector4& pointOnA, hkVector4& normalOut)
{
    ::FUN_00da8a00((::ContactVector *)(gsk.m_akPackedVerticesA), (::ContactVector *)(gsk.m_akCachedVectors), gsk.m_ucDimensionA, gsk.m_ucDimensionB,
                 (const ::ContactVector &)(separatingNormal), (::ContactVector &)(pointOnA), (::ContactVector &)(normalOut));
}

template <typename T> __forceinline T* hkAddByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}
template <typename T> __forceinline T* hkAllocateStack(int n, const char* what = 0)
{
    NineIntegerRecord& mem = NineIntegerRecord::GetMonitorStream();
    return static_cast<T*>(mem.stack().allocateStack((n * sizeof(T) + 127) & ~127, what));
}
template <typename T> __forceinline void hkDeallocateStack(T* ptr)
{
    NineIntegerRecord::GetMonitorStream().stack().deallocateStack(ptr);
}

namespace MemoryUtils {
__forceinline void memClear16(void* dst, int numQuads)
{
    hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
    {
        for (int i = 0; i < numQuads; i++)
        {
            dst32[0] = 0;
            dst32[1] = 0;
            dst32[2] = 0;
            dst32[3] = 0;
            dst32 += 4;
        }
    }
}
}
namespace hkVector4Util_S {
__forceinline void checkRegisters(hkUint32 registerMask)
{}
__forceinline void TransformPointArray(const hkTransform& t, const hkVector4* vectorsIn, int numVectors,
                                       hkVector4* vectorsOut)
{
    checkRegisters(0xf0000000);
    hkTransform unaliased = t;
    int i = numVectors - 1;
    do
    {
        vectorsOut[i]._setTransformedPos(unaliased, vectorsIn[i]);
    } while (--i >= 0);
}
}
void FUN_00db4b50(const ConvexCollisionQueryData& input, hkReal Rt, CollisionSolverInput& mat);

static hkReal hk4dGskCollidePointWithPlaneFinal(const ConvexCollisionQueryData& input,
                                                const ContactPointWeldingParameters& tol, const hkVector4& vertex, hkReal startRt,
                                                hkReal endRt, hkReal distance0, hkReal distance1, hkReal velocity,
                                                ScalarVectorData& out)
{
    CollisionSolverInput mat;
    hkReal Rt = startRt;
    hkReal distance = distance0;
    const hkReal accuracy = tol.m_fMaximumConstraintViolation * 0.25;
    for (int iteration = 0; iteration < 10; iteration++)
    {
        if (distance0 <= tol.m_fMinimumTimeOfImpactDelta)
            break;
        hkReal delta = distance1 - distance0;
        if (delta <= -accuracy)
            break;
        hkReal rel = (tol.m_fMinimumTimeOfImpactDelta - distance0) / delta;
        if ((iteration & 1) == 0)
        {
            rel = ::FUN_00c98210(rel, 0.1f);
            rel = MathUtilities::min2(rel, 0.9f);
        }
        Rt = (1.0f - rel) * startRt + endRt * rel;
        FUN_00db4b50(input, Rt, mat);
        hkVector4 diff;
        diff.setSub4(vertex, mat.m_pointOnPlaneA);
        distance = diff.dot4xyz1(mat.m_vPointOnPlaneB);
        if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(MathUtilities::equal(distance, tol.m_fMinimumTimeOfImpactDelta, accuracy)))->FUN_005609f0())
            break;
        if (distance < tol.m_fMinimumTimeOfImpactDelta)
        {
            endRt = Rt;
            distance1 = distance;
        }
        else
        {
            startRt = Rt;
            distance0 = distance;
        }
    }
    if (Rt < out.m_Rt)
    {
        out.m_Rt = Rt;
        out.m_collidePoint = vertex;
    }
    return out.m_Rt;
}

void __cdecl FUN_00db4e40(const ConvexCollisionQueryData& input, const ContactPointWeldingParameters& tol,
                          ScalarVectorData& out)
{
    hkReal maxRt = 1.0f;
    hkReal currentRt = input.m_fFinalQueryParameter;
    hkReal previousRt = currentRt;
    int numVertices = input.m_iStridedVertexCount;
    while (numVertices)
    {
        CollisionSolverInput mat;
        FUN_00db4b50(input, currentRt, mat);
        hkVector4* vertex = input.m_akPackedVerticesA;
        hkVector4* insert = vertex;
        const hkReal restRt = 1.0f - currentRt;
        const hkReal maxTravel = input.m_fStepTimeParameter * restRt;
        hkReal nextRt = 1.0f;
        int i = numVertices;
        numVertices = 0;
        for (i = i - 1; i >= 0; vertex += 1, i--)
        {
            hkVector4 toPlane;
            toPlane.setSub4(*vertex, mat.m_pointOnPlaneA);
            const hkReal distance = toPlane.dot4xyz1(mat.m_vPointOnPlaneB);
            if (distance >= tol.m_fCreateContactThreshold + maxTravel)
                continue;
            hkVector4 relA;
            relA.setSub4(*vertex, mat.m_massCenterA);
            hkVector4 relB;
            relB.setSub4(*vertex, mat.m_vMassCenterB);
            hkVector4 crossA;
            crossA.setCross(mat.m_deltaAnglesA[0], relA);
            hkVector4 crossB;
            crossB.setCross(mat.m_deltaAnglesA[1], relB);
            hkVector4 velocity;
            velocity.setSub4(crossA, mat.m_linearTimInfoA);
            velocity.sub4(crossB);
            const hkReal approach = velocity.dot3(mat.m_vPointOnPlaneB);
            const hkReal gap = distance - tol.m_fCreateContactThreshold;
            const hkReal atEnd = approach * restRt + gap;
            const hkReal accelTerm = restRt * 0.5 * restRt * input.m_fSecondBasisScalar;
            if (atEnd > accelTerm)
                continue;
            if (distance < tol.m_fCreateContactThreshold)
            {
                if (currentRt == input.m_fFinalQueryParameter)
                {
                    out.m_Rt = currentRt;
                    out.m_collidePoint = *vertex;
                    maxRt = currentRt;
                }
                else
                {
                    maxRt = hk4dGskCollidePointWithPlaneFinal(input, tol, *vertex, previousRt, currentRt, (*vertex)(3),
                                                              distance, approach, out);
                }
                continue;
            }
            hkVector4 swapTemp = *vertex;
            *vertex = *insert;
            *insert = swapTemp;
            (*insert)(3) = distance;
            insert += 1;
            numVertices++;
            const hkReal safeDist = distance - tol.m_fMinimumTimeOfImpactDelta;
            const hkReal minDist = tol.m_fCreateContactThreshold - tol.m_fMinimumTimeOfImpactDelta;
            const hkReal d2 = safeDist * 2.0 * input.m_fThirdBasisScalar;
            if (restRt * restRt <= d2)
                continue;
            const hkReal d3 = minDist * 2.0 * input.m_fThirdBasisScalar;
            hkReal step = sqrtf(d2);
            if (approach < 0.0f)
            {
                step += input.m_fThirdBasisScalar * approach + input.m_fThirdBasisScalar * approach;
            }
            else
            {
                step = ::FUN_00c98210(step, -approach * input.m_fThirdBasisScalar);
            }
            if (step >= restRt)
                continue;
            hkReal candidate = step + sqrtf(d3);
            candidate = ::FUN_00c98210(candidate, tol.m_fMinimumSafeDeltaTime.val());
            nextRt = MathUtilities::min2(nextRt, currentRt + candidate);
        }
        if (maxRt <= currentRt)
            break;
        if (nextRt == currentRt && maxRt > currentRt)
            break;
        previousRt = currentRt;
        currentRt = nextRt;
        nextRt = maxRt;
    }
}

static __forceinline void hk4dGskCalcSeparatingNormal(const hkTransform& tA, const hkTransform& tB,
                                                      const hkpConvexShape* shapeA, const hkpConvexShape* shapeB,
                                                      ConvexShapePairCache& gsk, hkVector4& separatingNormalOut,
                                                      hkVector4& pointOnBInB)
{
    hkTransform aTb;
    reinterpret_cast<::hkTransformCB22 *>(&(aTb))->FUN_00cb22f0((const ::hkTransformCB22 &)(tA), (const ::hkTransformCB22 &)(tB));
    hkVector4 separatingNormalA;
    gsk.GetClosestPoint(shapeA, shapeB, aTb, separatingNormalA);
    separatingNormalOut._setRotatedDir(tA.getRotation(), separatingNormalA);
    hkVector4 pointInA;
    gsk.getClosestPointAinA(separatingNormalA, pointInA);
    pointInA.subMul4(separatingNormalA.getSimdAt(3), separatingNormalA);
    pointOnBInB._setTransformedInversePos(aTb, pointInA);
    separatingNormalOut(3) = separatingNormalA(3) - shapeA->getRadius() - shapeB->getRadius();
}

static __forceinline void hk4dGskCalcWorstCaseProjectedVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                                                const hkVector4& separatingNormal,
                                                                const hkVector4& linearTimInfo,
                                                                const hkVector4* deltaAngles,
                                                                hkReal& realProjectedLinearDelta,
                                                                hkReal& projectedAngularDelta)
{
    hkVector4 crossAngleA;
    crossAngleA.setCross(deltaAngles[0], separatingNormal);
    hkVector4 crossAngleB;
    crossAngleB.setCross(deltaAngles[1], separatingNormal);
    hkReal lenA = crossAngleA.length3() * msA->m_fObjectRadius;
    hkReal lenB = crossAngleB.length3() * msB->m_fObjectRadius;
    projectedAngularDelta = lenA + lenB;
    realProjectedLinearDelta = linearTimInfo.dot3(separatingNormal);
}

static __forceinline void hk4dGskCollPInputInitialize(const AgentSubtypeMarker& in3,
                                                      ConvexCollisionQueryData& input)
{
    const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
    const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
    const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
    const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
    input.m_pFirstQueryData = msA;
    input.m_pSecondQueryData = msB;
    input.m_kFourthBasisVector = shapeA->getRadius() + shapeB->getRadius();
    input.m_vSubtypePosition = in3.m_vSubtypePosition;
    input.m_pStepInfo = &in3.m_pRayCastInput->m_pStepInfo;
    int numVertices = shapeA->getNumCollisionSpheres();
    input.m_iSecondPackedVertexCount = numVertices;
    input.m_iStridedVertexCount = numVertices;
    input.m_akPackedVerticesA = hkAllocateStack<hkVector4>(numVertices);
    shapeA->getCollisionSpheres(reinterpret_cast<hkSphere*>(input.m_akPackedVerticesA.val()));
    const hkReal a = msA->m_fObjectRadius * input.m_avSubtypeVectors[0](3) * input.m_avSubtypeVectors[0](3);
    const hkReal b = msB->m_fObjectRadius * input.m_avSubtypeVectors[1](3) * input.m_avSubtypeVectors[1](3);
    input.m_fSecondBasisScalar = a + b;
    input.m_fThirdBasisScalar = 1.0f / (input.m_fSecondBasisScalar + 1.1920928955078125e-07);
}

static __forceinline hkReal hk4dGskCalcPointVelocity(const hkMotionState* msA, const hkMotionState* msB,
                                                     const hkVector4& separatingPoint,
                                                     const hkVector4& separatingNormal, const hkVector4& linearTimInfo,
                                                     const hkVector4* deltaAngles, hkTime t)
{
    hkVector4 relVel;
    relVel.setNeg4(linearTimInfo);
    {
        const hkReal relT = msA->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msA->getSweptTransform().m_vCenterOfMass0, msA->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[0], relPos);
        relVel.add4(arm);
    }
    {
        const hkReal relT = msB->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msB->getSweptTransform().m_vCenterOfMass0, msB->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[1], relPos);
        relVel.sub4(arm);
    }
    const hkReal separatingVelocity = relVel.dot3(separatingNormal);
    return separatingVelocity;
}

static __declspec(noinline) hkReal FUN_00db49b0(const hkMotionState* msA, const hkMotionState* msB,
                                                const hkVector4& separatingPoint, const hkVector4& separatingNormal,
                                                const hkVector4& linearTimInfo, const hkVector4* deltaAngles, hkTime t)
{
    const hkReal angularVelocityFactor = 1.2f;
    hkVector4 relVel;
    relVel.setNeg4(linearTimInfo);
    hkReal separatingVelocity = relVel.dot3(separatingNormal);
    {
        const hkReal relT = msA->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msA->getSweptTransform().m_vCenterOfMass0, msA->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[0], relPos);
        const hkReal angVelPart = arm.dot3(separatingNormal);
        if (angVelPart <= 0.0f)
            separatingVelocity += angVelPart * angularVelocityFactor;
        else
            separatingVelocity += angVelPart / angularVelocityFactor;
    }
    {
        const hkReal relT = msB->getSweptTransform().getInterpolationValue(t);
        hkVector4 massCenter;
        massCenter.setInterpolate4(msB->getSweptTransform().m_vCenterOfMass0, msB->getSweptTransform().m_vCenterOfMass1,
                                   relT);
        hkVector4 relPos;
        relPos.setSub4(separatingPoint, massCenter);
        hkVector4 arm;
        arm.setCross(deltaAngles[1], relPos);
        const hkReal angVelPart = arm.dot3(separatingNormal);
        if (angVelPart >= 0.0f)
            separatingVelocity -= angVelPart * angularVelocityFactor;
        else
            separatingVelocity -= angVelPart / angularVelocityFactor;
    }
    return separatingVelocity;
}

static __forceinline void UpdateConvexShapePairCache(const AgentSubtypeMarker& in3, ContactPointWeldingParameters& tol,
                                              ConvexShapePairCache& gsk, int featureChange,
                                              const hkVector4& oldMasterNormal, const hkVector4* deltaAngles,
                                              hkReal startRt, hkReal endRt, hkReal distance0, hkReal distance1,
                                              WorldOperationEntry& out)
{
    CollisionSolverInput mat;
    hkVector4 normalA;
    hkVector4 pointA;
    hkReal Rt = startRt;
    hkReal distance = distance0;
    hkTransform wTa;
    hkTransform wTb;
    hkTransform aTb;
    hkReal radiusSum;
    {
        const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
        const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
        radiusSum = shapeA->getRadius();
        radiusSum += shapeB->getRadius();
    }
    const hkReal velocityBasedOnDistance = (distance1 - distance0) / (endRt - startRt);
    for (int iteration = 0; iteration < 10; iteration++)
    {
        hkReal delta = distance1 - distance0;
        if (delta > -tol.m_fMaximumConstraintViolation)
        {
            endRt = startRt;
            delta = 0.5f;
        }
        hkBool earlyOut;
        if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(MathUtilities::equal(distance1, tol.m_fMinimumTimeOfImpactDelta, tol.m_fMaximumConstraintViolation)))->FUN_005609f0())
        {
            earlyOut = true;
            featureChange = 0;
            Rt = endRt;
        }
        else
        {
            earlyOut = false;
            hkReal rel = (tol.m_fMinimumTimeOfImpactDelta - distance0) / delta;
            rel = ::FUN_00c98210(rel, 0.1f);
            rel = MathUtilities::min2(rel, 0.9f);
            Rt = (1.0f - rel) * startRt + endRt * rel;
        }
        {
            const hkStepInfo& stepInfo = in3.m_pRayCastInput->m_pStepInfo;
            const hkReal timeAddon = stepInfo.m_fTimeStep * Rt;
            ::fnv_00cf1710::FUN_00cf1710((const ::fnv_00cf1710::hkSweptTransformL &)(in3.m_pBodyA->GetMotionState()->getSweptTransform()), stepInfo.m_uiStartTime, timeAddon, (::fnv_00cf1710::hkTransformL &)(wTa));
            ::fnv_00cf1710::FUN_00cf1710((const ::fnv_00cf1710::hkSweptTransformL &)(in3.m_pBodyB->GetMotionState()->getSweptTransform()), stepInfo.m_uiStartTime, timeAddon, (::fnv_00cf1710::hkTransformL &)(wTb));
        }
        reinterpret_cast<::hkTransformCB22 *>(&(aTb))->FUN_00cb22f0((const ::hkTransformCB22 &)(wTa), (const ::hkTransformCB22 &)(wTb));
        if (featureChange)
        {
            const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
            const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
            gsk.GetClosestPoint(shapeA, shapeB, aTb, normalA);
            gsk.getClosestPointAinA(normalA, pointA);
        }
        else
        {
            hkVector4Util_S::TransformPointArray(aTb, gsk.m_akPackedVerticesB, gsk.m_ucDimensionB,
                                                 gsk.m_akCachedVectors);
            hkVector4 oldMasterNormalInA;
            oldMasterNormalInA._setRotatedInverseDir(wTa.getRotation(), oldMasterNormal);
            hkGskRecalcContact(gsk, oldMasterNormalInA, pointA, normalA);
        }
        distance = normalA(3) - radiusSum;
        if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(MathUtilities::equal(distance, tol.m_fMinimumTimeOfImpactDelta, tol.m_fMaximumConstraintViolation)))->FUN_005609f0() ||
            reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(earlyOut))->FUN_005609f0())
        {
            break;
        }
        if (startRt == endRt)
        {
            break;
        }
        if (distance < tol.m_fMinimumTimeOfImpactDelta)
        {
            endRt = Rt;
            distance1 = distance;
        }
        else
        {
            startRt = Rt;
            distance0 = distance;
        }
    }
    const hkStepInfo& stepInfo = in3.m_pRayCastInput->m_pStepInfo;
    const hkReal deltaTime = ::FUN_00c98210(stepInfo.m_fTimeStep.val() * Rt, tol.m_fMaximumAngularVelocity.val());
    hkTime toi = stepInfo.m_uiStartTime + deltaTime;
    if (toi < out.m_fTimeOfImpact.m_uiCommandId && toi < (stepInfo.m_fEndTime - tol.m_fMaximumAngularVelocity))
    {
        const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
        hkContactPoint cp;
        hkReal separatingVelocity;
        {
            hkVector4 pointWs;
            pointWs.SetTransformedPoint(wTa, pointA);
            cp.getSeparatingNormal().SetRotatedDirection(wTa.getRotation(), normalA);
            cp.getPosition().setAddMul4(pointWs, cp.getSeparatingNormal(), -shapeA->getRadius() - distance);
            cp.setDistance(distance);
            hkpConvexShape::WeldResult weldResult = hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED;
            hkVector4 weldedNormal = cp.getSeparatingNormal();
            if (in3.m_pBodyB->getShape()->getType() == HK_SHAPE_CONVEX_VERTICES)
            {
                hkUint8 numFeaturePoints = (hkUint8)gsk.m_ucDimensionB.val();
                hkpVertexId featurePoints[3];
                featurePoints[0] = (hkpVertexId)gsk.m_akPackedVerticesB[0].GetValueForType();
                featurePoints[1] =
                    (hkpVertexId)(numFeaturePoints < 2 ? 0xffff : gsk.m_akPackedVerticesB[1].GetValueForType());
                featurePoints[2] =
                    (hkpVertexId)(numFeaturePoints < 3 ? 0xffff : gsk.m_akPackedVerticesB[2].GetValueForType());
                const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
                weldResult = shapeB->weldContactPoint(featurePoints, numFeaturePoints, cp.getPosition(), &wTb, shapeA,
                                                      &wTa, weldedNormal);
                cp.setSeparatingNormal(weldedNormal);
            EXAMINE_WELD_RESULTS:
                if (weldResult == hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT &&
                    reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(in3.m_pRayCastInput->m_pCollisionQualityInfo->m_bEnableToiWeldRejection))->FUN_005609f0())
                {
                    return;
                }
            }
            else if (in3.m_pBodyA->getShape()->getType() == HK_SHAPE_CONVEX_VERTICES)
            {
                hkUint8 numFeaturePoints = (hkUint8)gsk.m_ucDimensionA.val();
                hkpVertexId featurePoints[3];
                featurePoints[0] = (hkpVertexId)gsk.m_akPackedVerticesA[0].GetValueForType();
                featurePoints[1] =
                    (hkpVertexId)(numFeaturePoints < 2 ? 0xffff : gsk.m_akPackedVerticesA[1].GetValueForType());
                featurePoints[2] =
                    (hkpVertexId)(numFeaturePoints < 3 ? 0xffff : gsk.m_akPackedVerticesA[2].GetValueForType());
                hkVector4 dist;
                dist.setBroadcast(weldedNormal, 3);
                hkVector4 pointOnA;
                pointOnA.setAddMul4(cp.getPosition(), weldedNormal, dist);
                weldedNormal.setNeg3(weldedNormal);
                const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
                weldResult = shapeA->weldContactPoint(featurePoints, numFeaturePoints, pointOnA, &wTa, shapeB, &wTb,
                                                      weldedNormal);
                weldedNormal.setNeg3(weldedNormal);
                cp.setSeparatingNormal(weldedNormal);
                goto EXAMINE_WELD_RESULTS;
            }
            const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
            const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
            separatingVelocity = hk4dGskCalcPointVelocity(msA, msB, cp.getPosition(), cp.getNormal(),
                                                          in3.m_vSubtypePosition, deltaAngles, toi);
            if (weldResult == hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED &&
                separatingVelocity > -1.1920929e-07f)
            {
                ConvexCollisionQueryData collPInput;
                collPInput.m_fFinalQueryParameter = Rt;
                {
                    MotionUtilities::calcAngularTimInfo(*msA, *msB, in3.m_pRayCastInput->m_pStepInfo.m_fTimeStep,
                                                        &collPInput.m_avSubtypeVectors[0], &collPInput.m_avSubtypeVectors[1]);
                    hkReal realProjectedLinearDelta, projectedAngularDelta;
                    hk4dGskCalcWorstCaseProjectedVelocity(msA, msB, cp.getNormal(), in3.m_vSubtypePosition,
                                                          collPInput.m_avSubtypeVectors, realProjectedLinearDelta,
                                                          projectedAngularDelta);
                    collPInput.m_fStepTimeParameter = realProjectedLinearDelta + projectedAngularDelta;
                    hk4dGskCollPInputInitialize(in3, collPInput);
                    collPInput.m_vFirstStoredVector.setRotatedInverseDir(wTb.getRotation(), cp.getNormal());
                    collPInput.m_vSecondStoredVector = gsk.m_akPackedVerticesB[0];
                }
                if (collPInput.m_akPackedVerticesA.val())
                {
                    ScalarVectorData collidePointsOut;
                    FUN_00db4e40(collPInput, tol, collidePointsOut);
                    hkDeallocateStack(collPInput.m_akPackedVerticesA.val());
                    if (collidePointsOut.m_Rt < 1.0f)
                    {
                        hkVector4 newPos;
                        newPos.SetTransformedPoint(wTa, collidePointsOut.m_collidePoint);
                        cp.getPosition() = newPos;
                    }
                }
            }
            if (velocityBasedOnDistance < separatingVelocity)
            {
                if (velocityBasedOnDistance > separatingVelocity * 1.2000000476837158)
                {
                    separatingVelocity = velocityBasedOnDistance;
                }
                else
                {
                    separatingVelocity =
                        FUN_00db49b0(in3.m_pBodyA->GetMotionState(), in3.m_pBodyB->GetMotionState(), cp.getPosition(),
                                     cp.getNormal(), in3.m_vSubtypePosition, deltaAngles, toi);
                    separatingVelocity = MathUtilities::min2(0.0f, separatingVelocity);
                }
            }
            separatingVelocity *= stepInfo.m_fInverseDeltaTime;
        }
        ContactDataPhysicsMaterial properties;
        MemoryUtils::memClear16(&properties, 3);
        properties.m_uiUserData = DAT_010d5384;
        HeapContactFeatureCache cache;
        reinterpret_cast<::ThisClass *>((void *)&(gsk))->FUN_00da9790((::Dest *)&(cache));
        int cbResult =
            in3.m_pContactManager->addToi(*in3.m_pBodyA.val(), *in3.m_pBodyB.val(), *in3.m_pRayCastInput.val(), out,
                                          toi, cp, &cache, separatingVelocity, properties);
        if (cbResult == 0)
        {
            if (reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(out.hasToi()))->FUN_005609f0())
            {
                in3.m_pContactManager->removeToi(*out.m_pConstraintOwner.val(), out.m_fTimeOfImpact.m_kProperties);
            }
            out.m_fTimeOfImpact.m_pfSeparatingVelocity = separatingVelocity;
            out.m_fTimeOfImpact.m_vContactPoint = cp;
            out.m_fTimeOfImpact.m_uiCommandId = toi;
            out.m_fTimeOfImpact.m_kProperties.set(properties);
            out.m_fTimeOfImpact.m_kGskCache.set(cache);
        }
    }
}

// @fnv 0x00db60c0
__declspec(noinline) void __cdecl FUN_00db60c0(const AgentSubtypeMarker& in3, const hkReal allowedPenetrationDepth,
                                               const hkReal minSeparation, const hkReal toiSeparation,
                                               ConvexFeaturePairCache& gskCache, hkVector4& separatingNormal,
                                               WorldOperationEntry& out)
{
    ContactPointWeldingParameters tol;
    {
        const CollisionQualityInfo& qi = *in3.m_pRayCastInput->m_pCollisionQualityInfo.val();
        tol.m_fCreateContactThreshold = minSeparation;
        tol.m_fMinimumTimeOfImpactDelta = toiSeparation;
        tol.m_fMaximumConstraintViolation = qi.m_fMaximumConstraintViolation * allowedPenetrationDepth;
        tol.m_fMinimumSafeDeltaTime = ::FUN_00c98210(qi.m_fMinimumSafeDeltaTime * allowedPenetrationDepth,
                                                          qi.m_fMinimumAbsoluteTimeOfImpact) *
                                      in3.m_pRayCastInput->m_pStepInfo.m_fInverseDeltaTime;
        tol.m_fMaximumAngularVelocity = qi.m_fMaximumAngularVelocity;
    }
    const hkpConvexShape* shapeA = static_cast<const hkpConvexShape*>(in3.m_pBodyA->getShape());
    const hkpConvexShape* shapeB = static_cast<const hkpConvexShape*>(in3.m_pBodyB->getShape());
    const hkMotionState* msA = in3.m_pBodyA->GetMotionState();
    const hkMotionState* msB = in3.m_pBodyB->GetMotionState();
    ConvexCollisionQueryData collPInput;
    collPInput.m_akPackedVerticesA = 0;
    hkBool collPInputNormalInitialized = false;
    hkBool collPIgnore = false;
    MotionUtilities::calcAngularTimInfo(*msA, *msB, in3.m_pRayCastInput->m_pStepInfo.m_fTimeStep,
                                        &collPInput.m_avSubtypeVectors[0], &collPInput.m_avSubtypeVectors[1]);
    {
        int numIter = 0;
        ConvexShapePairCache gsk;
        gsk.init(shapeA, shapeB, gskCache);
        hkVector4 lastMasterNormal;
        lastMasterNormal.setZero4();
        hkReal lastDistance = separatingNormal(3);
        int featureChange = 1;
        hkReal Rt = 0.0f;
        hkReal endRt = 1.0f;
        hkReal lastRt = 0.0f;
        while (1)
        {
            const hkReal currentDistance = separatingNormal(3);
            if (currentDistance <= tol.m_fMinimumTimeOfImpactDelta + tol.m_fMaximumConstraintViolation)
            {
                UpdateConvexShapePairCache(in3, tol, gsk, featureChange, lastMasterNormal, collPInput.m_avSubtypeVectors, lastRt,
                                    Rt, lastDistance, currentDistance, out);
                goto END;
            }
            const hkReal restRt = endRt - Rt;
            if (restRt <= 0.0f)
            {
                goto END;
            }
            hkReal realProjectedLinearDelta, projectedAngularDelta;
            hk4dGskCalcWorstCaseProjectedVelocity(msA, msB, separatingNormal, in3.m_vSubtypePosition,
                                                  collPInput.m_avSubtypeVectors, realProjectedLinearDelta,
                                                  projectedAngularDelta);
            const hkReal worstCaseApproachingDelta = realProjectedLinearDelta + projectedAngularDelta;
            const hkReal distAtT1 = separatingNormal(3) - worstCaseApproachingDelta * restRt;
            if (worstCaseApproachingDelta <= 0.0f || distAtT1 > tol.m_fCreateContactThreshold)
            {
                goto END;
            }
            const hkReal maxAllowedTravelDistance = separatingNormal(3) - tol.m_fCreateContactThreshold;
            hkReal safeTimeStep = maxAllowedTravelDistance / worstCaseApproachingDelta;
            if (safeTimeStep < 0.2f && !reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(collPIgnore))->FUN_005609f0() && reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(collPInputNormalInitialized))->FUN_005609f0() &&
                realProjectedLinearDelta * 1.0 < projectedAngularDelta)
            {
                if (!collPInput.m_akPackedVerticesA)
                {
                    hk4dGskCollPInputInitialize(in3, collPInput);
                    if (!collPInput.m_akPackedVerticesA.val())
                    {
                        collPIgnore = true;
                        goto skipPointPlaneOptimization;
                    }
                }
                collPInput.m_fFinalQueryParameter = Rt;
                collPInput.m_fStepTimeParameter = worstCaseApproachingDelta;
                ScalarVectorData collidePointsOut;
                FUN_00db4e40(collPInput, tol, collidePointsOut);
                const hkReal newSafeTimeStep = collidePointsOut.m_Rt - Rt;
                if (newSafeTimeStep < safeTimeStep * 2.0)
                {
                    collPIgnore = true;
                }
                safeTimeStep = ::FUN_00c98210(safeTimeStep, newSafeTimeStep);
            }
        skipPointPlaneOptimization:
            if (Rt + safeTimeStep >= endRt)
            {
                goto END;
            }
            lastRt = Rt;
            safeTimeStep = ::FUN_00c98210(tol.m_fMinimumSafeDeltaTime.val(), safeTimeStep);
            Rt += safeTimeStep;
            Rt = MathUtilities::min2(Rt, endRt);
            lastMasterNormal = separatingNormal;
            lastDistance = separatingNormal(3);
            {
                numIter++;
                const hkStepInfo& stepInfo = in3.m_pRayCastInput->m_pStepInfo;
                const hkReal timeAddon = stepInfo.m_fTimeStep * Rt;
                hkTransform tA;
                ::fnv_00cf1710::FUN_00cf1710((const ::fnv_00cf1710::hkSweptTransformL &)(msA->getSweptTransform()), stepInfo.m_uiStartTime, timeAddon, (::fnv_00cf1710::hkTransformL &)(tA));
                hkTransform tB;
                ::fnv_00cf1710::FUN_00cf1710((const ::fnv_00cf1710::hkSweptTransformL &)(msB->getSweptTransform()), stepInfo.m_uiStartTime, timeAddon, (::fnv_00cf1710::hkTransformL &)(tB));
                hk4dGskCalcSeparatingNormal(tA, tB, shapeA, shapeB, gsk, separatingNormal, collPInput.m_vSecondStoredVector);
                featureChange = gsk.m_iFeatureChange;
                collPInputNormalInitialized = true;
                collPInput.m_vFirstStoredVector._setRotatedInverseDir(tB.getRotation(), separatingNormal);
            }
        }
    END:
        if (collPInput.m_akPackedVerticesA)
        {
            hkDeallocateStack(collPInput.m_akPackedVerticesA.val());
        }
        gsk.checkForChangesAndUpdateCache(gskCache);
    }
}
#include "generated/data/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk_gs_ehsc_nogs_noehsc_variant_rtm_variant.inc"
