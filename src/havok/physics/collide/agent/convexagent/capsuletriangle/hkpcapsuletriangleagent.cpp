
// src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "havok/hkMemoryRouter.h"
#include <new>
#include "fnv/symbols_00c85000.h"
#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/symbols_00cd6000.h"
#include "fnv/symbols_00d37000.h"
#include "fnv/symbols_00d38000.h"
#include "fnv/symbols_00d39000.h"
#include "fnv/symbols_00d3a000.h"
#include "fnv/symbols_00d3b000.h"
#include "fnv/symbols_00daf000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010ce000.h"
#include "fnv/symbols_01268000.h"



typedef void (__cdecl *S_00d389f0_Func)();

struct S_00d389f0_AgentFuncs
{
    S_00d389f0_Func m_pCreateFunc;
    S_00d389f0_Func m_pQueryPenetrationsFunc;
    S_00d389f0_Func m_getClosestPointsFunc;
    S_00d389f0_Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

// @fnv 0x00d3ab90
void __cdecl FUN_00d3ab90(S_00d389f0_AgentFuncs* apTable)
{
    apTable->m_pCreateFunc = ((void (&)())::CreateAllocatedObject);
    apTable->m_pQueryPenetrationsFunc = ((void (&)())::fnv_00d3b1a0::FUN_00d3b1a0);
    apTable->m_getClosestPointsFunc = ((void (&)())::FUN_00d3b220);
    apTable->m_pLinearCastFunc = ((void (&)())::FUN_00d3ac80);
    apTable->m_bIsFlipped = true;
    apTable->m_bIsPredictive = false;
}

struct S_00d389f0_Dispatcher
{
};

// Registers two agent function tables with the dispatcher, one for type 3 to 0x15 and one for 0x15 to 3.
// @fnv 0x00d389f0
void __cdecl FUN_00d389f0(S_00d389f0_Dispatcher* dispatcher)
{
    {
        S_00d389f0_AgentFuncs agentFuncs;
        agentFuncs.m_pCreateFunc = ((void (&)())::CreateTriAgent2);
        agentFuncs.m_pQueryPenetrationsFunc = ((void (&)())::FUN_00d38ac0);
        agentFuncs.m_getClosestPointsFunc = ((void (&)())::FUN_00d38ed0);
        agentFuncs.m_pLinearCastFunc = ((void (&)())::FUN_00d3ac80);
        agentFuncs.m_bIsFlipped = true;
        agentFuncs.m_bIsPredictive = false;
        reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(agentFuncs), 3, 0x15);
    }
    {
        S_00d389f0_AgentFuncs agentFuncs;
        agentFuncs.m_pCreateFunc = ((void (&)())::fnv_00d37da0::CreateTriAgent);
        agentFuncs.m_pQueryPenetrationsFunc = ((void (&)())::FUN_00d38130);
        agentFuncs.m_getClosestPointsFunc = ((void (&)())::FUN_00d386c0);
        agentFuncs.m_pLinearCastFunc = ((void (&)())::FUN_00daf8e0);
        agentFuncs.m_bIsFlipped = false;
        agentFuncs.m_bIsPredictive = false;
        reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(agentFuncs), 0x15, 3);
    }
}

struct ReceiverBase { virtual void Release(unsigned int value); int unk04; };
struct NoteDispatcher {
    virtual void Unknown00(unsigned int, void*);
    virtual void Unknown04(unsigned int, void*);
    virtual void Unknown08(unsigned int, void*);
    virtual void Unknown0C(unsigned int, void*);
    virtual void Unknown10(unsigned int, void*);
    virtual void Dispatch(unsigned int id, void* value);
};
struct FUN_00d39930_class : ReceiverBase {
    NoteDispatcher* dispatcher;
    unsigned short receiverIds[3];
    void DispatchToReceivers(void* value);
};
// Dispatches value to each non-0xFFFF receiver id via dispatcher, then releases this if non-null.
// @fnv 0x00d39930
void FUN_00d39930_class::DispatchToReceivers(void* value)
{
    unsigned short* id = receiverIds;
    int count = 3;
    do {
        unsigned int current = *id;
        if ((unsigned short)current != 0xFFFF)
            dispatcher->Dispatch(current, value);
        ++id;
    } while (--count != 0);
    if (this)
        Release(1);
}


struct CallbackState {
    const int* m_pIntegerValue;
    float m_fFirstLightParameter;
    int m_iValue;
};







extern char DAT_010cef38[];

struct FUN_00d39980_cls {
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    void* m_i08;
    unsigned short m_w0C;
    unsigned short m_w0E;
    unsigned short m_w10;
    unsigned short m_w12;
    float m_triangleCache[5];
};





struct hkVector4 {
    __m128 m_vComponents;
    void operator=(const hkVector4& o) { m_vComponents = o.m_vComponents; }
    void setBroadcast3(const hkVector4& v) { m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff); }
    void mul4(const hkVector4& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
    void add4(const hkVector4& a) { m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents); }
    void addMul4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents)); }
    void setNeg4(const hkVector4& v) { m_vComponents = _mm_xor_ps(v.m_vComponents, ::DAT_010c4c00); }
    void neg() { m_vComponents = _mm_xor_ps(m_vComponents, ::DAT_010c4c00); }
};

struct Elem_d3b260 {
    hkVector4 m_pos;
    hkVector4 m_dir;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct Buffer_d3b260 {
    Elem_d3b260* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Elem_d3b260 m_pElements[256];
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int unk3034;
    int unk3038;
    int unk303c;
    unsigned short m_idx[4];
    unsigned char m_kPointA;
    unsigned char m_kPointB;
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};




struct __declspec(align(16)) FourWord {
    unsigned int x, y, z, w;
};

struct __declspec(align(16)) FourFloat {
    union { __m128 simd; FourWord words; };
};

struct __declspec(align(16)) MotionPacket {
    unsigned int word00;
    unsigned int word04;
    unsigned int word08;
    unsigned int word0c;
    unsigned int word10;
    unsigned int word14;
    unsigned int word18;
    unsigned int word1c;
    unsigned int word20;
    unsigned int word24;
    unsigned int word28;
    unsigned int word2c;
    unsigned int word30;
    unsigned int word34;
    unsigned int word38;
    unsigned int word3c;
    unsigned int word40;
    unsigned int word44;
    unsigned int word48;
    unsigned int word4c;
    FourFloat direction;
    unsigned int trailing60, trailing64, trailing68, trailing6c;
};

struct __declspec(align(16)) MotionCallData {
    const void* descriptor;
    float scale;
    FourWord direction;
    void* mode;
};



// Copies the input packet, XORs its direction with DAT_010c44d0, builds primary/secondary MotionCallData and calls FUN_00daf8e0.
// @fnv 0x00d3ac80
void __cdecl FUN_00d3ac80(const void* first, const void* second,
                           const MotionPacket* apPacket, void* mode,
                           void* optionalMode)
{
    MotionPacket packetCopy = *apPacket;
    packetCopy.direction.simd = _mm_xor_ps(apPacket->direction.simd, ::DAT_010c44d0);
    const void* descriptor = &UNK_010ce80c;
    MotionCallData primary;
    primary.descriptor = descriptor;
    primary.scale = ::DAT_0104da48;
    primary.direction = apPacket->direction.words;
    primary.mode = mode;

    if (optionalMode) {
        MotionCallData secondary;
        secondary.descriptor = descriptor;
        secondary.scale = ::DAT_0104da48;
        secondary.direction = apPacket->direction.words;
        secondary.mode = optionalMode;
        ::FUN_00daf8e0(static_cast<const ::IterativeSweep_hkpCdBody *>(second), static_cast<const ::IterativeSweep_hkpCdBody *>(first), (const ::IterativeSweep_hkpLinearCastCollisionInput *)(::MotionPacket *)(&packetCopy), (::IterativeSweep_hkpCdPointCollector *)(::MotionCallData *)(&primary), (::IterativeSweep_hkpCdPointCollector *)(::MotionCallData *)(&secondary));
    } else {
        ::FUN_00daf8e0(static_cast<const ::IterativeSweep_hkpCdBody *>(second), static_cast<const ::IterativeSweep_hkpCdBody *>(first), (const ::IterativeSweep_hkpLinearCastCollisionInput *)(::MotionPacket *)(&packetCopy), (::IterativeSweep_hkpCdPointCollector *)(::MotionCallData *)(&primary), (::IterativeSweep_hkpCdPointCollector *)(::MotionCallData *)(0));
    }
}

struct FUN_00d3b160_tmp { const void* vt; unsigned char flag; unsigned int a4; };
struct CallbackHost_d3b160 {
    void FUN_00d3b160(void*, void*, void*, unsigned int);
};

struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};

struct Mat4 {
    Vec4 row0, row1, row2, row3;
};

static __forceinline float SqLenLane(__m128 x)
{
    __m128 sq = _mm_mul_ps(x, x);
    __m128 yx = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
    __m128 zyx = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), yx);
    float r;
    _mm_store_ss(&r, zyx);
    return r;
}

// Computes Newton-refined inverse square roots of four vector lengths from pts and stores them plus a fifth value into out.
// @fnv 0x00cd72a0
void __cdecl ComputeInverseLengths(__m128* pts, float* out)
{
    __m128 c = pts[2];
    __m128 a = pts[0];
    __m128 b = pts[1];

    __m128 v = _mm_sub_ps(c, b);
    __m128 u = _mm_sub_ps(a, c);
    __m128 w = _mm_sub_ps(b, a);

    __m128 p = _mm_mul_ps(_mm_shuffle_ps(u, u, 0xc9), _mm_shuffle_ps(v, v, 0xd2));
    __m128 q = _mm_mul_ps(_mm_shuffle_ps(u, u, 0xd2), _mm_shuffle_ps(v, v, 0xc9));
    __m128 x = _mm_sub_ps(q, p);

    __declspec(align(16)) float lens[4];
    float fSqLen = SqLenLane(v);
    lens[0] = fSqLen;
    fSqLen = SqLenLane(u);
    lens[1] = fSqLen;
    fSqLen = SqLenLane(w);
    lens[2] = fSqLen;
    fSqLen = SqLenLane(x);
    lens[3] = fSqLen;

    __m128 l = _mm_load_ps(lens);
    __m128 r = _mm_rsqrt_ps(l);
    __m128 t = _mm_mul_ps(_mm_mul_ps(r, l), r);
    __m128 k1 = _mm_sub_ps(DAT_010c71c0, t);
    __m128 k2 = _mm_mul_ps(r, DAT_010c71d0);
    __m128 inv = _mm_mul_ps(k1, k2);

    _mm_store_ps(lens, inv);
    out[0] = lens[0];
    out[1] = lens[1];
    out[2] = lens[2];
    out[3] = lens[3];
    out[4] = fSqLen * lens[3];
}

struct __declspec(align(16)) ScalarVector {
    int x, y, z, w;
    __m128 quad() const { return *(const __m128*)this; }
};
struct Xf {
    ScalarVector r0, r1, r2, t;
};
struct Vt {
    void* f00; void* f04; void* f08; void* f0c;
    void* f10; void* f14; void* f18; void* f1c;
    void* f20; void* f24; void* f28; void* f2c;
    void* f30; void* f34; void* f38; void* f3c;
    int (*fn)(void*, void*, void*, void*, void*, void*, void*, void*);
};
struct ShapeInterface {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual int refine(void*,void*,void*,void*,void*,void*,void*);
};
struct Shape : ShapeInterface {
    int unk04;
    int unk08;
    int unk0c;
    float radius;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 vertices[3];
};
struct Obj {
    Shape* base;
    int u;
    Xf* xf;
};
struct Par {
    float a;
    int flag;
    float c;
};
struct Info {
    unsigned char count;
    unsigned char type;
    unsigned short feature;
    int index;
};
struct Contact {
    __m128 normal;
    __m128 position;
    Contact& operator=(const Contact& c) { normal = c.normal; position = c.position; return *this; }
    void FUN_00caad60(void* arg);
};



static __forceinline void xform(const Xf& m, const __m128* src, __m128* dst, int hi)
{
    ScalarVector column0 = m.r0;
    __m128 c0 = column0.quad();
    ScalarVector column1 = m.r1;
    __m128 c1 = column1.quad();
    ScalarVector column2 = m.r2;
    __m128 c2 = column2.quad();
    ScalarVector translation = m.t;
    __m128 ct = translation.quad();
    for (int i = hi; i >= 0; --i) {
        __m128 v = src[i];
        __m128 x = _mm_shuffle_ps(v, v, 0);
        __m128 y = _mm_shuffle_ps(v, v, 0x55);
        __m128 z = _mm_shuffle_ps(v, v, 0xaa);
        dst[i] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, c1), _mm_mul_ps(x, c0)), _mm_add_ps(_mm_mul_ps(z, c2), ct));
    }
}

struct CollisionWorkspace { __m128 la[2]; __m128 lb[3]; };
// Transforms shape vertices, runs a collision query, optionally refines the contact, and writes the result to out.
// @fnv 0x00d39bf0
int __cdecl FUN_00d39bf0(Obj* a, Obj* b, Par* volatile apParams, void* q, Contact* apContactOut)
{
    CollisionWorkspace workspace;
    Shape* shapes[2];
    shapes[0] = a->base;
    shapes[1] = b->base;

    xform(*a->xf, (const __m128*)shapes[0]->vertices, workspace.la, 1);

    xform(*b->xf, (const __m128*)shapes[1]->vertices, workspace.lb, 2);

    Info info[3];
    __m128 res[6];
    Par* input = apParams;
    ::FUN_00cd6520((const ::ContactVector *)(workspace.la), shapes[0]->radius, (const ::ContactVector *)(workspace.lb), shapes[1]->radius, (const float *)(q), input->c, 0, reinterpret_cast<::ContactRecord *>(res), reinterpret_cast<::Feature *>(info));

    float fDistA = res[1][3];
    float fDistB = res[3][3];
    int idx;
    if (fDistA < fDistB) {
        if (!(fDistA < input->c)) goto fail;
        idx = 0;
    } else {
        if (!(fDistB < input->c)) goto fail;
        idx = 1;
    }

    unsigned char n;
    n = info[idx].count;
    if (input->flag != 0 && n > 0) {
        const ScalarVector& source = *(ScalarVector*)(res + idx * 2 + 1);
        ScalarVector t;
        t.x = source.x;
        t.y = source.y;
        t.z = source.z;
        t.w = source.w;
        Xf* transformA = a->xf;
        Xf* transformB = b->xf;
        int r = shapes[1]->refine(&info[idx].feature, &n, res + idx * 2, transformB, shapes[0], transformA, &t);
        if (r != 0) { if (r == 1) ((Contact*)(res + idx * 2))->FUN_00caad60(&t); } else goto fail;
    }

    *apContactOut = ((Contact*)res)[idx];
    return 1;
fail:
    return 0;
}

#include <windows.h>
#include "fnv/symbols_simd.h"

extern "C" void _ReadWriteBarrier(void);
unsigned __int64 __cdecl __rdtsc(void);

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

typedef ScalarVector Vec4f;

struct ContactMatrix
{
    Vec4f row[4];
};

struct VirtObj
{
    virtual void v00();
    virtual void Run(const void* a, const void* b);
};

struct ManifoldPoint
{
    __m128 pos;
    int unk10;
    int unk14;
    int unk18;
    float dist;
};

struct HitRec
{
    ManifoldPoint pt0;
    ManifoldPoint pt1;
    ManifoldPoint pt2;
};

struct Context
{
    HitRec hit;
    __m128 capsule[2];
    __m128 triangle[3];
};


struct hkpShape
{
    const void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    void* m_userData;
    int m_type;
    float m_fSphereRadius;  // +0x10
    __m128 m_kVertices[4];  // +0x20
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    unsigned int m_shapeKey;
    const ContactMatrix* m_kMotionState;
};

static __forceinline void transform(Vec4* out, const hkpShape* shape, int count, const ContactMatrix* m)
{
    __m128 r0 = m->row[0].quad();
    __m128 r1 = m->row[1].quad();
    __m128 r2 = m->row[2].quad();
    __m128 r3 = m->row[3].quad();

    const __m128* v = shape->m_kVertices;
    for (int i = count - 1; i >= 0; --i) {
        __m128 vi = v[i];
        __m128 x = _mm_shuffle_ps(vi, vi, 0x00);
        __m128 y = _mm_shuffle_ps(vi, vi, 0x55);
        __m128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        __m128 a = _mm_add_ps(_mm_mul_ps(y, r1), _mm_mul_ps(x, r0));
        __m128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(__m128*)&out[i] = _mm_add_ps(a, b);
    }
}

struct CollisionInput { void* m_dispatcher; int unk04; float tolerance; };

// Transforms the capsule's two and the triangle's three vertices by their bodies' motions, then calls FUN_00cd6520 with the results, the
// two radii, a4, the input's tolerance, a5 and a6.
// @fnv 0x00d399f0
void __cdecl TransformAndDispatch(const hkpCdBody* a1, const hkpCdBody* a2, const CollisionInput* pExtra, void* a4, int a5, ::ContactRecord* a6)
{
    const hkpShape* shapeA = a1->m_pCollisionShape;
    const hkpShape* shapeB = a2->m_pCollisionShape;

    Vec4 aTransformedA[2];
    transform(aTransformedA, shapeA, 2, a1->m_kMotionState);

    Vec4 aTransformedB[3];
    transform(aTransformedB, shapeB, 3, a2->m_kMotionState);

    ::FUN_00cd6520((const ::ContactVector *)(void *)(&aTransformedA[0]),
                 shapeA->m_fSphereRadius,
                 (const ::ContactVector *)(void *)(&aTransformedB[0]),
                 shapeB->m_fSphereRadius,
                 (const float *)(a4),
                 pExtra->tolerance,
                 a5,
                 a6,
                 (::Feature *)(0));
}


struct __declspec(align(16)) RowPair { Vec4f first, second; };

struct CapsuleTriangleAgent {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void FUN_00d3a620(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInput* input, VirtObj* collector);
};
// Builds a temporary object holding a4 and a cleared flag with a vtable, then calls FUN_00d3a620 with a2, a1, a3 and that object.
// @fnv 0x00d3b160
void CallbackHost_d3b160::FUN_00d3b160(void* a1, void* a2, void* a3, unsigned int a4)
{
    FUN_00d3b160_tmp t;
    t.a4 = a4;
    t.flag = 0;
    t.vt = &DAT_010ce81c;
    reinterpret_cast<::CapsuleTriangleAgent *>(this)->FUN_00d3a620((*(const ::hkpCdBody *)(a2)), (*(const ::hkpCdBody *)(a1)), (const ::CollisionInput *)(a3), (::VirtObj *)(void *)(&t));
}

// Transforms capsule and triangle vertices into world space, tests for intersection, and reports a hit to the collector if found.
// @fnv 0x00d3a620
void CapsuleTriangleAgent::FUN_00d3a620(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const CollisionInput* input, VirtObj* collector)
{
    volatile DWORD tick;
    ProfBuf* pBuf = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf->m_pCur;
        pRec->m_pName = "TtCapsTriangle";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = pRec + 1;
    }

    Context ctx;
    const hkpShape* capsuleShape = bodyA.m_pCollisionShape;
    const hkpShape* triangleShape = bodyB.m_pCollisionShape;
    const ContactMatrix* transformA = bodyA.m_kMotionState;

    {
        RowPair xyRows;
        __declspec(align(16)) Vec4f c2;
        __declspec(align(16)) Vec4f c3;
        xyRows.first = transformA->row[0];
        xyRows.second = transformA->row[1];
        c2 = transformA->row[2];
        c3 = transformA->row[3];
        __m128 r0 = _mm_load_ps((const float*)&xyRows.first);
        __m128 r1 = _mm_load_ps((const float*)&xyRows.second);
        for (int i = 1; i >= 0; i--)
        {

            __m128 r2 = *(__m128*)&c2;
            __m128 r3 = *(__m128*)&c3;

            __m128 v = capsuleShape->m_kVertices[i];
            __m128 t = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0), r0), _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), r1));
            ctx.capsule[i] = _mm_add_ps(t, _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), r2), r3));
        }

    }

    const ContactMatrix* transformB = bodyB.m_kMotionState;
    {
        __declspec(align(16)) Vec4f d0;
        __declspec(align(16)) Vec4f d1;
        RowPair translationAndZ;
        d0 = transformB->row[0];
        d1 = transformB->row[1];
        translationAndZ.second = transformB->row[2];
        translationAndZ.first = transformB->row[3];
        for (int i = 2; i >= 0; i--)
        {
            __m128 s1 = *(__m128*)&d1;
            __m128 s2 = *(__m128*)&translationAndZ.second;
            __m128 s3 = *(__m128*)&translationAndZ.first;
            __m128 s0 = *(__m128*)&d0;
            __m128 v = triangleShape->m_kVertices[i];
            __m128 t = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), s0);
            t = _mm_add_ps(t, _mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), s1));
            ctx.triangle[i] = _mm_add_ps(t, _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), s2), s3));
        }

    }

    ::FUN_00cd6520((const ::ContactVector *)(ctx.capsule), capsuleShape->m_fSphereRadius, (const ::ContactVector *)(ctx.triangle), triangleShape->m_fSphereRadius, (const float *)(void *)(&this->unk14), input->tolerance, 0, (::ContactRecord *)(::HitRec *)(&ctx.hit), (::Feature *)(0));
    if (ctx.hit.pt0.dist < 0.0f || ctx.hit.pt1.dist < 0.0f)
    {
        collector->Run(&bodyA, &bodyB);
    }

    ProfBuf* pBuf2 = (ProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf2->m_pCur < pBuf2->m_pRecordEnd)
    {
        ProfRec* pRec = pBuf2->m_pCur;
        pRec->m_pName = "Et";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf2->m_pCur = pRec + 1;
    }
}

namespace fnv_00d3b1a0 {

struct LocalState_d3b1a0 {
    const int* m_pIntegerValue;
    unsigned char m_bZero;
    int m_iValue;
};

typedef void (__cdecl *Call_d3a8c0)(int, int, int, LocalState_d3b1a0*);

// Initialises a LocalState_d3b1a0 with param4, a zero flag and a pointer to DAT_010ce81c, then calls FUN_00d3a8c0 with param2, param1, param3 and the state.
// @fnv 0x00d3b1a0
void __cdecl FUN_00d3b1a0(int param1, int param2, int param3, int aiValue) {
    LocalState_d3b1a0 state;
    state.m_iValue = aiValue;
    state.m_bZero = 0;
    state.m_pIntegerValue = &(*reinterpret_cast<const int *>(&::DAT_010ce81c));

    Call_d3a8c0 call = (Call_d3a8c0)((void (&)())::FUN_00d3a8c0);
    call(param2, param1, param3, &state);
}
}  // namespace fnv_00d3b1a0

namespace fnv_00d3b1e0 {
struct CpuCallData { void* descriptor; float bound; unsigned int value; };
struct CpuObject {
    void FUN_00d39ef0(void*, void*, unsigned int, CpuCallData*);
    void FUN_00d3b1e0(void*, void*, unsigned int, unsigned int);
};
// Builds a CpuCallData from fourth, DAT_0104da48 and &DAT_010ce7fc, then calls FUN_00d39ef0 with second, first, third and that data.
// @fnv 0x00d3b1e0
void CpuObject::FUN_00d3b1e0(void* first, void* second, unsigned int third, unsigned int fourth)
{
    CpuCallData data;
    data.value = fourth;
    data.bound = ::DAT_0104da48;
    data.descriptor = &::DAT_010ce7fc;
    FUN_00d39ef0(second, first, third, &data);
}
}  // namespace fnv_00d3b1e0


struct ContactNormalSetter : Contact
{
    ContactNormalSetter* FUN_00caad60(const __m128* source);
};

// Copies the x, y and z components of *source into position, keeping position's existing w, and returns this.
// @fnv 0x00caad60
ContactNormalSetter* ContactNormalSetter::FUN_00caad60(const __m128* source)
{
    __m128 incoming = *source;
    __m128 current = position;
    __m128 high = _mm_unpackhi_ps(incoming, current);
    position = _mm_shuffle_ps(incoming, high, 0xc4);
    return this;
}

struct MonitorRecord { const char* name; unsigned int time; unsigned int unk08; };
struct MonitorStream { unsigned int unk00; MonitorRecord* cursor; unsigned int unk08; MonitorRecord* end; };
struct __declspec(align(16)) PlainVector { int x,y,z,w; __m128 quad() const { return *(const __m128*)this; } };
struct PlainMatrix { PlainVector r0,r1,r2,t; };
struct ContactRecord {
    __m128 position;
    __m128 normal;
    ContactRecord& operator=(const ContactRecord& o) { position=o.position; normal=o.normal; return *this; }
    void FUN_00caad60(const PlainVector*);
};
struct CacheRecord { unsigned char flag; unsigned char unk01; unsigned short feature; unsigned int unk04; };
union __declspec(align(16)) TransformCacheScratch { PlainVector column; CacheRecord cache[3]; };
struct CollisionShape;
struct CapsuleShapeInterface {
    virtual void slot00(); virtual void slot04(); virtual void slot08(); virtual void slot0c();
    virtual void slot10(); virtual void slot14(); virtual void slot18(); virtual void slot1c();
    virtual void slot20(); virtual void slot24(); virtual void slot28(); virtual void slot2c();
    virtual void slot30(); virtual void slot34(); virtual void slot38(); virtual void slot3c();
    virtual int process(unsigned short*,unsigned char*,ContactRecord*,const PlainMatrix*,const CollisionShape*,const PlainMatrix*,PlainVector*);
};
struct CollisionShape : CapsuleShapeInterface {
    unsigned int unk04,unk08,unk0c;
    float radius;
    unsigned int unk14,unk18,unk1c;
    hkVector4 points[3];
};
struct BodyRecord { const CollisionShape* shape; unsigned int unk04; const PlainMatrix* matrix; };
struct PointEvent { ContactRecord contact; const BodyRecord* a; const BodyRecord* b; unsigned int unk28,unk2c; };
struct Collector { virtual void slot00(); virtual void accept(const PointEvent*); };
struct ContactResults { ContactRecord points[3]; };
struct CollisionAgent {
    unsigned int unk00,unk04,unk08,unk0c,unk10,cache14;
    void FUN_00d39ef0(const BodyRecord& a,const BodyRecord& b,const CollisionInput& input,Collector* output);
};
// @fnv 0x00d39ef0
void CollisionAgent::FUN_00d39ef0(const BodyRecord& a,const BodyRecord& b,const CollisionInput& input,Collector* output) {
    {
        MonitorStream* stream=(MonitorStream*)TlsGetValue(DAT_0126835c);
        if(stream->cursor < stream->end) {
            MonitorRecord* rec=stream->cursor;
            rec->name="TtCapsTriangle";
            unsigned int ticks;
            ticks = static_cast<unsigned int>(__rdtsc());
            rec->time=ticks;
            stream->cursor=rec+1;
        }
    }
    {
    PointEvent event;
    event.a=&a; event.b=&b;
    TransformCacheScratch transformCache;
    hkVector4 pointsA[2];
    hkVector4 pointsB[3];
    const CollisionShape* shapeA=a.shape;
    const CollisionShape* shapeB=b.shape;
    xform(*(const Xf*)a.matrix,&shapeA->points[0].m_vComponents,&pointsA[0].m_vComponents,1);
    xform(*(const Xf*)b.matrix,&shapeB->points[0].m_vComponents,&pointsB[0].m_vComponents,2);
    ContactResults result;
    CacheRecord* cache=transformCache.cache;
    ::FUN_00cd6520((const ::ContactVector *)(pointsA),shapeA->radius,(const ::ContactVector *)(pointsB),shapeB->radius,(const float *)(void *)(&cache14),input.tolerance,0,(::ContactRecord *)(::ContactResults *)(&result),(::Feature *)(cache));
    int index;
    if(result.points[0].normal[3] < result.points[1].normal[3]) {
        if(!(input.tolerance > result.points[0].normal[3])) goto done;
        index=0;
    } else {
        if(!(input.tolerance > result.points[1].normal[3])) goto done;
        index=1;
    }
    {
        unsigned char flag=cache[index].flag;
        if(input.unk04 && flag>0) {
            PlainVector normal=*(const PlainVector*)&result.points[index].normal;
            const PlainMatrix* transformA=a.matrix;
            const PlainMatrix* transformB=b.matrix;
            ContactRecord* contact=&result.points[index];
            int outcome=const_cast<CollisionShape*>(shapeB)->process(&cache[index].feature,&flag,contact,transformB,shapeA,transformA,&normal);
            if(outcome==0) goto done;
            if(outcome==1) result.points[index].FUN_00caad60(&normal);
        }
        event.contact=result.points[index];
        output->accept(&event);
    }
    }
done:
    {
        MonitorStream* stream=(MonitorStream*)TlsGetValue(DAT_0126835c);
        if(stream->cursor < stream->end) {
            MonitorRecord* rec=stream->cursor;
            rec->name="Et";
            unsigned int ticks;
            ticks = static_cast<unsigned int>(__rdtsc());
            rec->time=ticks;
            stream->cursor=rec+1;
        }
    }
}

extern char DAT_010cef80[];
struct Timer { char* volatile name; unsigned time; unsigned extra; };
struct TimerPair { int unused; Timer* current; int unused2; Timer* end; };
struct Body { Shape* shape; int unused; Mat4* matrix; };
struct Input { int unk00,unk04; float tolerance; };
struct PenetrationCollector { virtual void unused(); virtual void add(Body*, Body*); };
struct AlignedPairData { Vec4 position, normal; };
struct Result { AlignedPairData points[3]; };
struct Cache { float inverseEdge0,inverseEdge1,inverseEdge2,inverseNormal,normalLength; };
struct OutputA { Vec4 points[2]; };
struct OutputB { Vec4 points[3]; };
struct Locals { Result result; OutputA outA; OutputB outB; };
static __forceinline void mytransform(Vec4* out, const Shape* shape, int count, const Mat4* m)
{
    struct Rows { Vec4 p3,p2,p1,p0; } p;
    p.p0 = m->row0; p.p1 = m->row1; p.p2 = m->row2; p.p3 = m->row3;
    __m128 r0 = *(__m128*)&p.p0, r1 = *(__m128*)&p.p1, r2 = *(__m128*)&p.p2, r3 = *(__m128*)&p.p3;
    const __m128* v = (const __m128*)shape->vertices;
    for (int i = count - 1; i >= 0; --i) {
        __m128 vi = v[i];
        __m128 x = _mm_shuffle_ps(vi, vi, 0);
        __m128 y = _mm_shuffle_ps(vi, vi, 0x55);
        __m128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        __m128 a = _mm_add_ps(_mm_mul_ps(r0, x), _mm_mul_ps(r1, y));
        __m128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(__m128*)&out[i] = _mm_add_ps(a, b);
    }
}
static __forceinline void mytransform2(Vec4* out, const Shape* shape, int count, const Mat4* m)
{
    __m128 r0,r1,r2,r3; (void)r1; (void)r2; 
    struct Rows { Vec4 p0,p1,p2,p3; } p;
    p.p0 = m->row0; p.p1 = m->row1; p.p2 = m->row2; p.p3 = m->row3;
    r0 = _mm_load_ps((const float*)&p.p0); r1 = _mm_load_ps((const float*)&p.p1); r2 = _mm_load_ps((const float*)&p.p2); r3 = _mm_load_ps((const float*)&p.p3);
    const __m128* __restrict v = (const __m128*)shape->vertices;
    int i = count - 1;
    do {
        __m128 vi = v[i];
        __m128 x = _mm_shuffle_ps(vi, vi, 0); __m128 y = _mm_shuffle_ps(vi, vi, 0x55); __m128 z = _mm_shuffle_ps(vi, vi, 0xaa);
        __m128 a = _mm_add_ps(_mm_mul_ps(y, r1), _mm_mul_ps(x, r0));
        __m128 b = _mm_add_ps(_mm_mul_ps(z, r2), r3);
        *(__m128*)&out[i] = _mm_add_ps(b, a);
    } while (--i >= 0);
}
// Transforms two body shapes, tests for penetration, and adds the pair to the collector if the result normals indicate overlap.
// @fnv 0x00d3a8c0
void __cdecl FUN_00d3a8c0(Body* apBodyA, Body* apBodyB, Input* input, PenetrationCollector* collector)
{
    TimerPair* state = (TimerPair*)TlsGetValue(DAT_0126835c);
    Timer* timer = state->current;
    if (timer < state->end) {
        timer->name = DAT_010cef80;
        _ReadWriteBarrier();
        volatile unsigned t = (unsigned)__rdtsc();
        timer->time = t;
        state->current = timer + 1;
    }
    Locals l;
    Cache cache;
    ::ComputeInverseLengths((__m128 *)(void *)((void*)apBodyB->shape->vertices), (float *)(void *)(&cache));
    Shape* pShapeA = apBodyA->shape;
    Shape* pShapeB = apBodyB->shape;
    mytransform(l.outA.points, pShapeA, 2, apBodyA->matrix);
    mytransform2(l.outB.points, pShapeB, 3, apBodyB->matrix);
    ::FUN_00cd6520((const ::ContactVector *)(void *)(&l.outA), pShapeA->radius, (const ::ContactVector *)(void *)(&l.outB), pShapeB->radius, (const float *)(void *)(&cache), input->tolerance, 0, reinterpret_cast<::ContactRecord *>(&l.result), (::Feature *)(0));
    if (l.result.points[0].normal.w < 0.0f || l.result.points[1].normal.w < 0.0f)
        collector->add(apBodyA, apBodyB);
    state = (TimerPair*)TlsGetValue(DAT_0126835c);
    timer = state->current;
    if (timer < state->end) {
        timer->name = DAT_010c41f8;
        _ReadWriteBarrier();
        volatile unsigned t = (unsigned)__rdtsc();
        timer->time = t;
        state->current = timer + 1;
    }
}

// Moved from hkpcapsuletriangleagent_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).
// src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/symbols_00c85000.h"
void FUN_00d3ab60(void* apObject);
void __cdecl FUN_00d3ab90(S_00d389f0_AgentFuncs* apTable);
void __cdecl TransformAndDispatch(const hkpCdBody* a1, const hkpCdBody* a2, const CollisionInput* pExtra, void* a4, int a5, ::ContactRecord* a6);
int __cdecl FUN_00d39bf0(Obj* a, Obj* b, Par* volatile p, void* q, Contact* out);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef uintptr_t hkUlong;
typedef size_t hk_size_t;
class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass;
typedef int hkBool32;
class hkBool
{
public:
typedef char CompileTimeTrueType;inline hkBool(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
hkEnum(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
private:
STORAGE m_kStorage;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline void operator=(TYPE e)
{
m_kStorage=e;
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_kStorage;};
template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;};
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline virtual ~hkBaseObject(){}
public:
__forceinline hkBaseObject(){}
};
class hkStatisticsCollector;
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
virtual const hkClass*GetClassType()const;
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};

typedef __m128 hkQuadReal;
class hkVector4_S;
typedef const hkVector4_S&hkVector4Parameter;
class Vector4Comparison;
typedef const Vector4Comparison&hkVector4ComparisonParameter;
class hkTransform;
class hkVector4_S
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4_S&v);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4_S&b);
__forceinline const hkReal&operator()(int i)const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};
class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline hkVector4_S&getColumn(int i);
__forceinline const hkVector4_S&getColumn(int i)const;
protected:
hkVector4_S m_kColumn0;
hkVector4_S m_kColumn1;
hkVector4_S m_kColumn2;};
class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
__forceinline hkTransform(const hkTransform&r);
__forceinline const hkVector4_S&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVector4_S m_vTranslation;};
inline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4_S::_setTransformedPos(const hkTransform&t,const hkVector4_S&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
inline const hkReal&hkVector4_S::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline hkVector4_S&hkMatrix3::getColumn(int x)
{
return(&m_kColumn0)[x];
}
inline const hkVector4_S&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4_S&hkTransform::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
hkTransform::hkTransform(const hkTransform&t)
{
const hkVector4_S r0=t.m_rotation.getColumn(0);
const hkVector4_S r1=t.m_rotation.getColumn(1);
const hkVector4_S r2=t.m_rotation.getColumn(2);
const hkVector4_S r3=t.m_rotation.getColumn(3);
m_rotation.getColumn(0)=r0;
m_rotation.getColumn(1)=r1;
m_rotation.getColumn(2)=r2;
m_rotation.getColumn(3)=r3;}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
return*(*reinterpret_cast<::hkThreadLocalData< ::StringCursor *> *>(&::DAT_0126835c)).getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
public:
struct Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime();
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32 ticks;
ticks = static_cast<unsigned int>(__rdtsc());
m_uiStartTicks=ticks;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
hkVector4_S m_kMinimumCorner;};
class hkSphere
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
protected:
hkVector4_S m_pos;};
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkVector4_S&getPosition();
inline hkVector4_S&getSeparatingNormal();
inline void setNormal(const hkVector4_S&normal);
inline hkReal getDistance()const;
protected:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
hkVector4_S m_vContactPosition;
hkVector4_S m_vSeparatingNormal;};
inline hkVector4_S&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVector4_S&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline hkReal hkContactPoint::getDistance()const
{
return m_vSeparatingNormal(3);
}
class Vector4WithInt24W:public hkVector4_S
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}};
enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
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
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
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
HK_SHAPE_ALL=-1
};
class hkpCollisionDispatcher;
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
struct ShapeRayBundleCastInput;
struct ShapeRayCastOutputArray;
class hkpRayHitCollector;
class hkpCdBody_S;
class hkpShapeContainer;
typedef hkUint16 hkpVertexId;
typedef hkUint32 hkpShapeKey;
class hkpShape_S:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape_S(CollisionShapeType type);
virtual hkReal getMaximumProjection(const hkVector4_S&direction)const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(hkpShape_S::PhysicsShape));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
virtual void CastRayWithCollector(const ShapeRayCastQuery&input,const hkpCdBody_S&cdBody,hkpRayHitCollector&collector)const=0;
virtual Vector4Comparison CastRayBundle(const ShapeRayBundleCastInput&input,ShapeRayCastOutputArray&output,hkVector4ComparisonParameter mask)const;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32>m_type;
public:
hkpShape_S(class FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};
class hkpCdBody_S
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape_S*getShape()const;
public:
explicit __forceinline hkpCdBody_S(const hkpCdBody_S*parent);
public:
const hkpShape_S*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};
const hkTransform&hkpCdBody_S::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkpShape_S*hkpCdBody_S::getShape()const
{
return m_pCollisionShape;
}
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
class hkpCollisionAgent;
struct CollisionAgentContext
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;};
class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;
class hkpCollisionDispatcher:public hkReferencedObject
{
public:
enum{
HK_MAX_RESPONSE_TYPE=8,
HK_MAX_SHAPE_TYPE=32,
HK_MAX_AGENT2_TYPES=64,
HK_MAX_AGENT3_TYPES=16,
HK_MAX_COLLISION_QUALITIES=8
};
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
typedef hkpCollisionAgent*(__cdecl*CreateFunc)(const hkpCdBody_S&collA,const hkpCdBody_S&collB,const CollisionAgentContext&env,hkpContactMgr*mgr);
typedef void(__cdecl*GetPenetrationsFunc)(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
typedef void(__cdecl*GetClosestPointsFunc)(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&output);
typedef void(__cdecl*LinearCastFunc)(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector);
struct CollisionAgentFunctionTable
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(CollisionAgentFunctionTable));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
CreateFunc m_pCreateFunc;
GetPenetrationsFunc m_pQueryPenetrationsFunc;
GetClosestPointsFunc m_pGetPenetrationsFunc;
LinearCastFunc m_pLinearCastFunc;
hkBool m_bIsFlipped;
hkBool m_bIsPredictive;
CollisionAgentFunctionTable():m_bIsFlipped(false),m_bIsPredictive(false){}
};
public:
hkpCollisionDispatcher(CreateFunc defaultCreationFunction,hkpContactMgrFactory*defaultContactMgrFactory);
public:
struct IntegerPair
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(IntegerPair));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
CollisionShapeType m_iSecond;
CollisionShapeType m_iFirst;
};
struct AgentTypePairPriority
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(AgentTypePairPriority));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
char m_iAgentTypeA;
char m_iAgentTypeB;
char m_priority;
};
typedef AgentTypePairPriority DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
protected:
void internalRegisterCollisionAgent(hkUchar agentTypesTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE],int agentType,CollisionShapeType typeA,CollisionShapeType typeB,CollisionShapeType origA,CollisionShapeType origB,DebugTable*debugTable,int recursionDepth);
public:
enum CollisionQualityLevel
{
COLLISION_QUALITY_INVALID,
COLLISION_QUALITY_PSI,
COLLISION_QUALITY_SIMPLIFIED_TOI,
COLLISION_QUALITY_TOI,
COLLISION_QUALITY_TOI_HIGHER,
COLLISION_QUALITY_TOI_FORCED,
COLLISION_QUALITY_CHARACTER,
COLLISION_QUALITY_TMP_EXPAND_MANIFOLD
};
public:
hkReal m_fExpectedMaxLinearVelocity;};
struct ContactPointPair
{
ContactPointPair(const hkpCdBody_S&a,const hkpCdBody_S&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody_S&m_pBodyA;
const hkpCdBody_S&m_pBodyB;};
class hkpCdPointCollector
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
inline virtual ~hkpCdPointCollector();
virtual void AddCdPoint(const ContactPointPair&point)=0;
protected:
hkReal m_fEarlyOutDistance;};
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void ProcessAgent(const hkpCdBody_S&a,const hkpCdBody_S&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
protected:
inline virtual ~hkpCollisionAgent();
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();};
class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}};
struct MaterialIndexedTriangle
{
hkUint8 m_uiMaterialIndex;
hkpVertexId m_auiVertexIds[3];
};
class TriangleDistanceUtility
{
public:
static void __cdecl calcBarycentricCoordinates(hkVector4Parameter pos,hkVector4Parameter t0,hkVector4Parameter t1,hkVector4Parameter t2,ValueWrapper<hkReal>result[3]);
struct PointTriangleCache
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(TriangleDistanceUtility::PointTriangleCache));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkReal m_afCacheComponents[3];
hkReal m_fFirstCacheValue;
hkReal m_fSecondCacheValue;
};
protected:
TriangleDistanceUtility();};
class hkpCapsuleTriangleAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl InitAgentFunc(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl initAgentFuncInverse(hkpCollisionDispatcher::CollisionAgentFunctionTable&f);
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
static void __cdecl registerAgent2(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getClosestPoints(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,hkpCdPointCollector&pointDetails);
static void __cdecl FUN_00d3a280(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);
virtual void getPenetrations(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void cleanup(hkpConstraintOwner&constraintOwner);
protected:
friend class hkpCapsuleConvexWelderAgent;
__forceinline hkpCapsuleTriangleAgent(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createCapsuleTriangleAgent(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createTriangleCapsuleAgent(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
private:
static void __cdecl getClosestPointsPublic(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&cache,int searchManifold,hkContactPoint*points);
static __forceinline void __cdecl getClosestPointsInl(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&cache,int searchManifold,hkContactPoint*points,MaterialIndexedTriangle*featureOutput=0);
public:
enum ClosestPointResult
{
ST_CP_MISS,
ST_CP_HIT,
};
private:
static __forceinline ClosestPointResult getClosestPointInternal(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&m_pAccessManager,hkContactPoint&cpoint);
public:
static ClosestPointResult __cdecl ComputeClosestPoints(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&m_pAccessManager,hkContactPoint&cpoint);
protected:
hkContactPointId m_usContactPointId[3];
TriangleDistanceUtility::PointTriangleCache m_kClosestPointCache;
};
class hkpSphereRepShape:public hkpShape_S
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
virtual const hkSphere*GetCollisionSpheres(hkSphere*sphereBuffer)const=0;
public:
hkpSphereRepShape(CollisionShapeType type):hkpShape_S(type){}
hkpSphereRepShape(FinishingFlag flag):hkpShape_S(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
class hkpConvexShape:public hkpSphereRepShape
{
public:
static const struct ClassMemberDescriptor Members[];
virtual void GetFirstVertex(hkVector4_S&v)const=0;
inline hkReal getRadius()const;enum WeldResult
{
WELD_RESULT_REJECT_CONTACT_POINT,
WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED,
WELD_RESULT_ACCEPT_CONTACT_POINT_UNMODIFIED
};
__forceinline hkpConvexShape::WeldResult weldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,
hkVector4_S&contactPointWs,const hkTransform*thisObjTransform,
const hkpConvexShape*collidingShape,const hkTransform*collidingTransform,hkVector4_S&separatingNormalInOut)const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
virtual void GetVerticesFromIds(const hkpVertexId*ids,int numIds,Vector4WithInt24W*vertixArrayOut)const=0;
virtual int WeldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,hkVector4_S&contactPointWs,const hkTransform*thisObjTransform,const hkpConvexShape*collidingShape,const hkTransform*collidingTransform,hkVector4_S&separatingNormalInOut)const;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};
inline hkReal hkpConvexShape::getRadius()const
{
return m_fSphereRadius;
}
hkpConvexShape::WeldResult hkpConvexShape::weldContactPoint(hkpVertexId*featurePoints,hkUint8&numFeaturePoints,
hkVector4_S&contactPointWs,const hkTransform*thisObjTransform,
const hkpConvexShape*collidingShape,const hkTransform*collidingTransform,hkVector4_S&separatingNormalInOut)const
{
return(WeldResult)this->WeldContactPoint(featurePoints,numFeaturePoints,
contactPointWs,thisObjTransform,
collidingShape,collidingTransform,separatingNormalInOut);}
class hkpCapsuleShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkVector4_S*GetIndexedVertices()const;
public:
hkpCapsuleShape(FinishingFlag flag):hkpConvexShape(flag){m_type=HK_SHAPE_CAPSULE;}
protected:
hkVector4_S m_kVertexA;};
const hkVector4_S*hkpCapsuleShape::GetIndexedVertices()const
{
return&m_kVertexA;
}

class hkpTriangleShape:public hkpConvexShape
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline const hkVector4_S*GetIndexedVertices()const;
protected:
hkUint16 m_kWeldingInfo;
hkVector4_S m_kVertexA;
public:
void setType(){m_type=HK_SHAPE_TRIANGLE;}
};
const hkVector4_S*hkpTriangleShape::GetIndexedVertices()const
{
return&m_kVertexA;
}

// @fnv 0x00d39980
FUN_00d39980_cls* __cdecl CreateAllocatedObject(const void* a1, const void* a2, const void* a3, void* a4)
{
    FUN_00d39980_cls* pObject = static_cast<FUN_00d39980_cls*>(hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(FUN_00d39980_cls)));
    pObject->m_w04 = sizeof(FUN_00d39980_cls);
    pObject->m_w06 = 1;
    pObject->m_i08 = a4;
    pObject->m_w0C = 0xffff;
    pObject->m_w0E = 0xffff;
    pObject->m_w10 = 0xffff;
    pObject->m_vptr = DAT_010ceefc;
    const hkpTriangleShape* triangle = static_cast<const hkpTriangleShape*>(static_cast<const hkpCdBody_S*>(a1)->m_pCollisionShape);
    ::ComputeInverseLengths(const_cast<__m128*>(reinterpret_cast<const __m128*>(triangle->GetIndexedVertices())), pObject->m_triangleCache);
    pObject->m_vptr = DAT_010cef38;
    return pObject;
}
namespace hkVector4Util_S
{
__forceinline void __cdecl TransformPointArray(const hkTransform&t,const hkVector4_S*vectorsIn,int numVectors,hkVector4_S*vectorsOut);}
inline void __cdecl hkVector4Util_S::TransformPointArray(const hkTransform&t,const hkVector4_S*vectorsIn,int numVectors,hkVector4_S*vectorsOut)
{
hkTransform unaliased=t;
int i=numVectors-1;
do
{
vectorsOut[i]._setTransformedPos(unaliased,vectorsIn[i]);
}while(--i>=0);}
__forceinline void __cdecl hkpCapsuleTriangleAgent::getClosestPointsInl(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&cache,int searchManifold,hkContactPoint*points,MaterialIndexedTriangle*featureOutput)
{
const hkpCapsuleShape*capsuleA=static_cast<const hkpCapsuleShape*>(bodyA.getShape());
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
hkVector4_S endPoints[2];hkVector4Util_S::TransformPointArray(bodyA.getTransform(),capsuleA->GetIndexedVertices(),2,endPoints);
hkVector4_S triVertices[3];hkVector4Util_S::TransformPointArray(bodyB.getTransform(),triB->GetIndexedVertices(),3,triVertices);
::FUN_00cd6520((const ::ContactVector *)(endPoints),capsuleA->getRadius(),(const ::ContactVector *)(triVertices),triB->getRadius(),(const float *)&(cache),input.getTolerance(),searchManifold,(::ContactRecord *)(points),(::Feature *)(featureOutput));}
__forceinline hkpCapsuleTriangleAgent::ClosestPointResult hkpCapsuleTriangleAgent::getClosestPointInternal(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,TriangleDistanceUtility::PointTriangleCache&cache,hkContactPoint&cpoint)
{
const hkpCapsuleShape*capsuleA=static_cast<const hkpCapsuleShape*>(bodyA.getShape());
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
hkContactPoint points[3];
MaterialIndexedTriangle featureOutput[3];
getClosestPointsInl(bodyA,bodyB,input,cache,0,points,featureOutput);
const hkReal dist0=points[0].getDistance();
const hkReal dist1=points[1].getDistance();
int Id=-1;
if(dist0<dist1)
{
if(input.getTolerance()>dist0)
{
Id=0;
}
}
else
{
if(input.getTolerance()>dist1)
{
Id=1;
}
}
if(Id !=-1)
{
hkUint8 numFeaturePoints=featureOutput[Id].m_uiMaterialIndex;
if(input.m_collisionQuality.val()&&numFeaturePoints>0)
{
hkVector4_S weldedNormal=points[Id].getSeparatingNormal();
hkpConvexShape::WeldResult result=triB->weldContactPoint(&featureOutput[Id].m_auiVertexIds[0],numFeaturePoints,points[Id].getPosition(),&bodyB.getTransform(),capsuleA,&bodyA.getTransform(),weldedNormal);
if(result==hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT)
{
return ST_CP_MISS;
}
else if(result==hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED)
{
points[Id].setNormal(weldedNormal);
}
}
cpoint=points[Id];
return ST_CP_HIT;
}
return ST_CP_MISS;}
// @fnv 0x00d3a280
void __cdecl hkpCapsuleTriangleAgent::FUN_00d3a280(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "CapsTriangle";h->setTime();mStream.setEnd((char*)(h+1));}};
TriangleDistanceUtility::PointTriangleCache cache;
{
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
::ComputeInverseLengths((__m128 *)(triB->GetIndexedVertices()),(float *)&(cache));
}
ContactPointPair event(bodyA,bodyB);
if(getClosestPointInternal(bodyA,bodyB,input,cache,event.m_kPoint))
{
collector.AddCdPoint(event);
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}

enum hkResult { HK_SUCCESS=0, HK_FAILURE=1 };
typedef hkReal hkTime;
struct FourByteState;

class ConvexFeaturePairCache;
class hkpContactMgr:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
enum Type
{
TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
TYPE_REPORT_CONTACT_MGR,
TYPE_CONVEX_LIST_CONTACT_MGR,
TYPE_NULL_CONTACT_MGR,
TYPE_USER_CONTACT_MGR,
TYPE_MAX
};__forceinline hkContactPointId addContactPoint(const hkpCdBody_S&a,const hkpCdBody_S&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp);
__forceinline void removeContactPoint(hkContactPointId cpId,hkpConstraintOwner&constraintOwner);
public:
virtual hkContactPointId CreateContactPoint(const hkpCdBody_S&a,const hkpCdBody_S&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp)=0;
virtual hkResult ReserveContactPoints(int numPoints)=0;
virtual void removeContactPointImpl(hkContactPointId cpId,hkpConstraintOwner&constraintOwner)=0;public:
Type m_type;};
hkContactPointId hkpContactMgr::addContactPoint(const hkpCdBody_S&a,const hkpCdBody_S&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp)
{
return CreateContactPoint(a,b,input,output,contactCache,cp);
}
void hkpContactMgr::removeContactPoint(hkContactPointId cpId,hkpConstraintOwner&constraintOwner)
{
removeContactPointImpl(cpId,constraintOwner);
}
struct ContactPointWithId
{
hkContactPoint m_kPoint;
ValueWrapper<hkUint32>m_usContactPointId;};

class hkStepInfo
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}public:
__declspec(align(16))ValueWrapper<hkTime>m_uiStartTime;};
struct hkpAgent1nSector;
struct GskAgentInput:public CollisionAgentContext
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable hkpAgent1nSector*m_pAgent1nSector;};
enum{HK_MAX_CONTACT_POINT=256};
struct CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}
public:
ValueWrapper<ContactPointWithId*>m_pAlignedPairData;
ValueWrapper<hkpConstraintOwner*>m_pConstraintOwner;};
struct WorldOperationEntry:public CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}inline ContactPointWithId*reserveContactPoints(int numberOfPoints=1)
{
return m_pAlignedPairData;
}
inline void commitContactPoints(int numberOfPoints=1)
{
m_pAlignedPairData=m_pAlignedPairData+numberOfPoints;
;
}
public:
struct ContactPointAgentEntry
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(WorldOperationEntry::ContactPointAgentEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ContactPointWithId*m_vContactPoint;
FourByteState*m_pAgentEntry;
void*m_pUserData;
};
struct ContactPointBuffer
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=hkMemoryRouter::getInstance().heap().blockAlloc(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;hkMemoryRouter::getInstance().heap().blockFree(p,sizeof(WorldOperationEntry::ContactPointBuffer));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
void reset()
{
m_pFirstFreeContactPoint=&m_akContactRecords[0];
m_ppFirstFreeContactPointer=&m_apContactPointPointers[0];
}
ContactPointAgentEntry*m_pFirstFreeContactPoint;
ContactPointWithId**m_ppFirstFreeContactPointer;
ContactPointWithId*m_apContactPointPointers[HK_MAX_CONTACT_POINT];
ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
};
public:
ValueWrapper<ContactPointBuffer*>m_akContactRecords;};
static __forceinline void updateXYZ(hkVector4_S& dst,const hkVector4_S& xyz) {
    reinterpret_cast<hkQuadReal&>(dst)=_mm_shuffle_ps(xyz,_mm_unpackhi_ps(xyz,dst),0xc4);
}
inline void hkContactPoint::setNormal(const hkVector4_S& normal) { updateXYZ(m_vSeparatingNormal,normal); }
static __forceinline void capsuleTriClosest(const hkpCdBody_S& a,const hkpCdBody_S& b,const CollisionAgentContext& input,TriangleDistanceUtility::PointTriangleCache& cache,int manifold,hkContactPoint* points,MaterialIndexedTriangle* features)
{
    const hkpCapsuleShape* capsule=static_cast<const hkpCapsuleShape*>(a.getShape());
    const hkpTriangleShape* triangle=static_cast<const hkpTriangleShape*>(b.getShape());
    hkVector4_S ends[2];
    hkVector4Util_S::TransformPointArray(a.getTransform(),capsule->GetIndexedVertices(),2,ends);
    hkVector4_S vertices[3];
    hkVector4Util_S::TransformPointArray(b.getTransform(),triangle->GetIndexedVertices(),3,vertices);
    ::FUN_00cd6520((const ::ContactVector *)(ends),capsule->getRadius(),(const ::ContactVector *)(vertices),triangle->getRadius(),(const float *)&(cache),input.getTolerance(),manifold,(::ContactRecord *)(points),(::Feature *)(features));
}
struct CapsuleTriProcess : hkpCapsuleTriangleAgent {
    void FUN_00d3ad70(const hkpCdBody_S&,const hkpCdBody_S&,const GskAgentInput&,WorldOperationEntry&);
};
// @fnv 0x00d3ad70
void CapsuleTriProcess::FUN_00d3ad70(const hkpCdBody_S&bodyA,const hkpCdBody_S&bodyB,const GskAgentInput&input,WorldOperationEntry&result)
{
;
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "CapsuleTri";h->setTime();mStream.setEnd((char*)(h+1));}};
const hkpCapsuleShape*capsuleA=static_cast<const hkpCapsuleShape*>(bodyA.getShape());
const hkpTriangleShape*triB=static_cast<const hkpTriangleShape*>(bodyB.getShape());
hkContactPoint points[3];
MaterialIndexedTriangle featureOutput[3];
capsuleTriClosest(bodyA,bodyB,input,m_kClosestPointCache,1,points,featureOutput);
for(int p=0;p<3;p++)
{
if(points[p].getDistance()<input.getTolerance())
{
hkUint8 numFeaturePoints=featureOutput[p].m_uiMaterialIndex;
if(numFeaturePoints>0)
{
hkVector4_S weldedNormal=points[p].getSeparatingNormal();
hkpConvexShape::WeldResult weldResult=triB->weldContactPoint(&featureOutput[p].m_auiVertexIds[0],numFeaturePoints,points[p].getPosition(),&bodyB.getTransform(),capsuleA,&bodyA.getTransform(),weldedNormal);
if(weldResult==hkpConvexShape::WELD_RESULT_REJECT_CONTACT_POINT)
{
if(m_usContactPointId[p]!=(0xffff))
{
m_pContactManager->removeContactPoint(m_usContactPointId[p],*result.m_pConstraintOwner.val());
m_usContactPointId[p]=(0xffff);
}
continue;
}
else if(weldResult==hkpConvexShape::WELD_RESULT_ACCEPT_CONTACT_POINT_MODIFIED)
{
points[p].setNormal(weldedNormal);
}
}
if(m_usContactPointId[p]==(0xffff))
{
m_usContactPointId[p]=m_pContactManager->addContactPoint(bodyA,bodyB,input,result,0,points[p]);
}
if(m_usContactPointId[p]!=(0xffff))
{
ContactPointWithId*point=result.reserveContactPoints(1);
result.commitContactPoints(1);
point->m_kPoint.getPosition()=points[p].getPosition();
point->m_kPoint.getSeparatingNormal()=points[p].getSeparatingNormal();
point->m_usContactPointId=m_usContactPointId[p];
}
}
else
{
if(m_usContactPointId[p]!=(0xffff))
{
m_pContactManager->removeContactPoint(m_usContactPointId[p],*result.m_pConstraintOwner.val());
m_usContactPointId[p]=(0xffff);
}
}
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}

// Moved from the base unit after the variant classes (VEGAS-15).

struct Agent_d3b260 : CapsuleTriProcess {
    void FUN_00d3b260(const void* a, const void* b, const void* c, Buffer_d3b260* buf);
};

// @fnv 0x00d3b260
void Agent_d3b260::FUN_00d3b260(const void* a, const void* b, const void* c, Buffer_d3b260* apBuffer)
{
    float dist = apBuffer->m_fHitFraction;
    Elem_d3b260* e = apBuffer->m_kRayEnd;
    FUN_00d3ad70(*static_cast<const hkpCdBody_S*>(b), *static_cast<const hkpCdBody_S*>(a), *static_cast<const GskAgentInput*>(c), (*(::WorldOperationEntry *)(apBuffer)));
    for (; e < apBuffer->m_kRayEnd; e++)
    {
        hkVector4 w;
        w.setBroadcast3(e->m_dir);
        w.mul4(e->m_dir);
        w.add4(e->m_pos);
        e->m_pos = w;
        e->m_dir.setNeg4(e->m_dir);
    }
    if (dist != apBuffer->m_fHitFraction)
    {
        apBuffer->m_vHitNormal.neg();
        unsigned char n = apBuffer->m_ucLowNibble;
        apBuffer->m_ucLowNibble = apBuffer->m_ucHighNibble;
        apBuffer->m_ucHighNibble = n;
        unsigned char t = apBuffer->m_kPointA;
        apBuffer->m_kPointA = apBuffer->m_kPointB;
        apBuffer->m_kPointB = t;
        int idx = apBuffer->m_kPointA + apBuffer->m_kPointB - 1;
        unsigned short w = apBuffer->m_idx[0];
        apBuffer->m_idx[0] = apBuffer->m_idx[idx];
        apBuffer->m_idx[idx] = w;
        if ((apBuffer->m_kPointA & apBuffer->m_kPointB) == 2)
        {
            unsigned short usTmp = apBuffer->m_idx[1];
            apBuffer->m_idx[1] = apBuffer->m_idx[2];
            apBuffer->m_idx[2] = usTmp;
        }
    }
}

// Builds a CallbackState with a max float, the given value and a constant pointer, then passes it to FUN_00d3a280 with the three pointers reordered.
// @fnv 0x00d3b220
void __cdecl FUN_00d3b220(void* apOne, void* apTwo, void* apThree, int aiValue)
{
    CallbackState kState;
    kState.m_fFirstLightParameter = 3.40282e+38f;
    kState.m_iValue = aiValue;
    kState.m_pIntegerValue = &(*reinterpret_cast<const int *>(&::DAT_010ce7fc));
    hkpCapsuleTriangleAgent::FUN_00d3a280(*static_cast<const hkpCdBody_S*>(apTwo), *static_cast<const hkpCdBody_S*>(apOne), *static_cast<const CollisionAgentContext*>(apThree), (*(::hkpCdPointCollector *)(&kState)));
}

// Moved from hkpcapsuletriangleagent_rtm_variant.cpp (VEGAS-15).
#include "fnv/decl/FUN_00cfbcc0_cls.h"

// Writes the four agent functions into p and clears its flipped and predictive flags.
// @fnv 0x00d3ab60
__declspec(noinline) void FUN_00d3ab60(void* p)
{
    S_00d389f0_AgentFuncs* s = (S_00d389f0_AgentFuncs*)p;
    s->m_pCreateFunc = (S_00d389f0_Func)((void (&)())::fnv_00d398c0::CreateObjectFromFactory);
    s->m_pQueryPenetrationsFunc = (S_00d389f0_Func)((void (&)())::FUN_00d3a8c0);
    s->m_getClosestPointsFunc = (S_00d389f0_Func)((void (&)())::hkpCapsuleTriangleAgent::FUN_00d3a280);
    s->m_pLinearCastFunc = (S_00d389f0_Func)((void (&)())::FUN_00daf8e0);
    s->m_bIsFlipped = 0;
    s->m_bIsPredictive = 0;
}

// @fnv 0x00d3abc0
void __cdecl FUN_00d3abc0(S_00d389f0_Dispatcher* obj)
{
    S_00d389f0_AgentFuncs s;
    s.m_bIsFlipped = 0;
    s.m_bIsPredictive = 0;
    FUN_00d3ab90(&s);
    reinterpret_cast<::FUN_00cfbbe0_cls *>((obj))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(s), 3, 5);
    s.m_bIsFlipped = 0;
    s.m_bIsPredictive = 0;
    FUN_00d3ab60(static_cast<void*>(&s));
    reinterpret_cast<::FUN_00cfbbe0_cls *>((obj))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(s), 5, 3);
}

struct FNVHookOwner
{
};
// @fnv 0x00d3ac20
void FUN_00d3ac20(FNVHookOwner* p)
{
    S_00d389f0_AgentFuncs h;
    h.m_bIsFlipped = false;
    h.m_bIsPredictive = false;
    FUN_00d3ab90(&h);
    reinterpret_cast<::FUN_00cfbcc0_cls *>((p))->AddSpawnEntry((::SpawnRequest *)(void *)(&h), 3, 5);
    h.m_bIsFlipped = false;
    h.m_bIsPredictive = false;
    FUN_00d3ab60(&h);
    reinterpret_cast<::FUN_00cfbcc0_cls *>((p))->AddSpawnEntry((::SpawnRequest *)(void *)(&h), 5, 3);
}
#include "generated/data/havok/physics/collide/agent/convexagent/capsuletriangle/hkpcapsuletriangleagent.inc"
