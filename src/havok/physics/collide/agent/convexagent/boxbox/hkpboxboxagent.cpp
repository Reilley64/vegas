
// src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/decl/FUN_00db0920_cls.h"
#include "fnv/decl/hkpGskBaseAgent_S.h"
#include "fnv/symbols_00d40000.h"
#include "fnv/symbols_00d41000.h"
#include "fnv/symbols_00dac000.h"
#include "fnv/symbols_00daf000.h"
struct FUN_00d408e0_1
{
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    unsigned char b1;
    unsigned char b2;
};

// Fills the struct with four function pointers and clears two byte flags.
// @fnv 0x00d408e0
void __cdecl FUN_00d408e0(FUN_00d408e0_1* a)
{
    a->p1 = (void*)&((void *(&)())::FUN_00d401d0);
    a->p2 = (void*)&((void *(&)())::FUN_00d406c0);
    a->p3 = (void*)&((void *(&)())::hkpGskBaseAgent_S::FUN_00dac450);
    a->p4 = (void*)&((void *(&)())::FUN_00daf8e0);
    a->b1 = 0;
    a->b2 = 0;
}

struct S_00d40180_Target
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14(unsigned short id, void* p);
};
struct S_00d40180_Entry
{
    unsigned short unk0;
    unsigned short m_iOwnerObjectOffset;
};
struct S_00d40180
{
    virtual ~S_00d40180();
    int unk4;
    S_00d40180_Target* m_target;
    int unkC;
    S_00d40180_Entry m_entries[8];
    unsigned char unk30;
    unsigned char m_uiItemCount;
    void DispatchAndDelete(void* p);
};
// @fnv 0x00d40180
void S_00d40180::DispatchAndDelete(void* apArg)
{
    for (int i = 0; i < m_uiItemCount; i++)
        m_target->vfn_14(m_entries[i].m_iOwnerObjectOffset, apArg);
    delete this;
}

typedef void(__cdecl* D41FD0Func)();

struct D41FD0AgentFuncs
{
    D41FD0Func m_pCreateFunc;
    D41FD0Func m_pQueryPenetrationsFunc;
    D41FD0Func m_pGetPenetrationsFunc;
    D41FD0Func m_pLinearCastFunc;
    bool m_bIsFlipped;
    bool m_bIsPredictive;
};

struct D41FD0CollisionDispatcher
{
};


// Fills a collision agent function table with the static agent callbacks and registers it for collision type pair 0x12/0x12.
// @fnv 0x00d41fd0
void __cdecl RegisterStaticCollisionAgent(D41FD0CollisionDispatcher* dispatcher)
{
    D41FD0AgentFuncs agentFuncs;
    agentFuncs.m_pCreateFunc = ((void (&)())::CreateSpawnObject);
    agentFuncs.m_pQueryPenetrationsFunc = ((void (&)())::TestGsk);
    agentFuncs.m_pGetPenetrationsFunc = ((void (&)())::hkpGskBaseAgent_S::FUN_00dac450);
    agentFuncs.m_pLinearCastFunc = ((void (&)())::FUN_00daf8e0);
    agentFuncs.m_bIsFlipped = false;
    agentFuncs.m_bIsPredictive = true;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(agentFuncs), 0x12, 0x12);
}

extern "C" const double DAT_010cf200;
extern "C" char DAT_010cf1c4;
extern "C" void* __cdecl FUN_00c85750(void);

class Allocator
{
  public:
    virtual void* Get0(void);
    virtual void* Alloc(unsigned int size);
};

class Holder
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    Allocator* m_pAllocator;
};

class SrcObj
{
  public:
    void* unk00;
    void* unk04;
    float m_08;
};

class SubStub
{
  public:
};

class SpawnedObject
{
  public:
    void* vptr;
    unsigned short m_04;
    unsigned short m_06;
    void* m_08;
};

// @fnv 0x00d401d0
void* FUN_00d401d0(void* apFirst, void* apSecond, void* a3, void* a4)
{
    SrcObj* src = (SrcObj*)a3;
    float fSrcValue = src->m_08;
    float fLimit = (float)(*(float*)((char*)*(void**)apFirst + 0x2c) * DAT_010cf200);
    if (fSrcValue >= fLimit)
    {
        goto callPath;
    }
    fLimit = (float)(*(float*)((char*)*(void**)apSecond + 0x2c) * DAT_010cf200);
    if (src->m_08 >= fLimit)
    {
        goto callPath;
    }
    Holder* pHolder = (Holder*)FUN_00c85750();
    Allocator* pAllocator = pHolder->m_pAllocator;
    SpawnedObject* pSpawned = (SpawnedObject*)pAllocator->Alloc(0x50);
    pSpawned->m_04 = 0x50;
    pSpawned->m_06 = 1;
    pSpawned->m_08 = a4;
    pSpawned->vptr = &DAT_010cf1c4;
    reinterpret_cast<::FUN_00db0920_cls *>((((SubStub*)((char*)pSpawned + 0x10))))->FUN_00db0920();
    return pSpawned;
callPath:
    return ((void *)(::FUN_00dacc00((int)(apFirst), (int)(apSecond), (int)(a3), (int)(a4))));
}

extern "C" void __cdecl FUN_00d40470(void* a, void* b, void* c, void* d);

// @fnv 0x00d406a0
extern "C" void FUN_00d406a0(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    FUN_00d40470(apArg1, apArg2, apArg3, apArg4);
}

typedef void(__cdecl* FUN_00d406c0_fn4)(void*, void*, void*, void*);


// @fnv 0x00d408c0
void FUN_00d408c0(void* a1, void* a2, void* a3, void* a4)
{
    ((FUN_00d406c0_fn4)((void *(&)())::FUN_00d406c0))(a1, a2, a3, a4);
}

__declspec(noinline) void __cdecl FUN_00d408e0(FUN_00d408e0_1*);

struct BoxAgentRegistry
{
};

// Initializes a FUN_00d408e0_1 struct with zeroed fields, calls FUN_00d408e0 to populate it, and registers it with pkObj via FUN_00cfbbe0.
// @fnv 0x00d40910
void __cdecl FUN_00d40910(BoxAgentRegistry* pkObj)
{
    FUN_00d408e0_1 kFuncs;
    kFuncs.b1 = 0;
    kFuncs.b2 = 0;
    FUN_00d408e0(&kFuncs);
    reinterpret_cast<::FUN_00cfbbe0_cls *>((pkObj))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(kFuncs), 4, 4);
}

// Moved from hkpboxboxagent_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <windows.h>
#include "fnv/decl/Manifold__NDetector.h"
#include "fnv/decl/ThisCls.h"
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_01268000.h"
void __cdecl FUN_00d408e0(FUN_00d408e0_1* a);
void FUN_00d408c0(void* a1, void* a2, void* a3, void* a4);

#include <xmmintrin.h>
struct hkVector4_d409
{
    __m128 m_vComponents;
};

struct hkRotation_d409
{
    hkVector4_d409 m_kColumn0;
    hkVector4_d409 m_kColumn1;
    hkVector4_d409 m_kColumn2;
};

__forceinline void setRotatedInverseDir_d409(hkVector4_d409& out, const hkRotation_d409& r, const hkVector4_d409& v)
{
    __m128 c0 = r.m_kColumn0.m_vComponents;
    __m128 c1 = r.m_kColumn1.m_vComponents;
    __m128 c2 = r.m_kColumn2.m_vComponents;
    {
        __m128 t = _mm_unpacklo_ps(c0, c1);
        __m128 ct = _mm_unpackhi_ps(c0, c1);
        c0 = _mm_movelh_ps(t, c2);
        c1 = _mm_movehl_ps(c0, t);
        c1 = _mm_shuffle_ps(c1, c2, 0xd4);
        c2 = _mm_shuffle_ps(ct, c2, 0xe4);
    }
    __m128 b1 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x55);
    __m128 b0 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0x00);
    __m128 b2 = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xaa);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(_mm_mul_ps(b1, c1), _mm_mul_ps(b0, c0)), _mm_mul_ps(b2, c2));
}

struct RotatedDir_d409
{
    hkVector4_d409 unk00;
    hkVector4_d409 unk10;
    hkRotation_d409 m_rotation;
    hkVector4_d409 m_dir;
    hkVector4_d409 unk60;
    hkVector4_d409 unk70;
    hkVector4_d409 unk80;
    hkVector4_d409 unk90;
    hkVector4_d409 unkA0;
    hkVector4_d409 unkB0;
    hkVector4_d409 m_dirCopy;
    hkVector4_d409 m_localDir;

    void FUN_00d40940();
};

// @fnv 0x00d40940
void RotatedDir_d409::FUN_00d40940()
{
    m_dirCopy.m_vComponents = m_dir.m_vComponents;
    setRotatedInverseDir_d409(m_localDir, m_rotation, m_dirCopy);
}

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier();
struct MonitorRecord
{
    const char* marker;
    unsigned int timestamp;
    unsigned int unk08;
};
struct ThreadState
{
    void* unk00;
    MonitorRecord* current04;
    void* unk08;
    MonitorRecord* end0C;
};
struct V4
{
    union
    {
        __m128 m;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct Vector
{
    __m128 m;
};
struct Shape
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0C;
    float scalar10;
    float unk14;
    float unk18;
    float unk1C;
    Vector values20;
    __forceinline float radius() const
    {
        return scalar10;
    }
};
struct Input
{
    Shape* shape;
    int unk04;
    void* data08;
};
struct Parameters
{
    int unk00;
    int unk04;
    float offset08;
};
struct Callback
{
    virtual void unused();
    virtual void handle(Input*, Input*);
};
struct Transform
{
    Vector a, b, c, d;
};
struct Job
{
    Input* first;
    Input* second;
    Parameters* parameters08;
    void* data0C;
    void* unk10;
    void* dataA14;
    void* dataB18;
    Transform transform20;
    V4 minA60, minB70;
    Vector tolerance80, expandedA90, expandedBA0;
    float toleranceB0;
    float epsilonB4;
    int unkB8;
    int unkBC;
    Vector translationC0, translationD0, translationE0, translationF0;
    Vector axis100, axis110, axis120;
};
class Manager
{
  public:
    void* unk00;
    void* unk04;
    void* data08;
    void* unk0C;
    Callback callback10;
    void FUN_00d40280(Input* a, Input* b, Parameters* parameters, void* p4);
};
inline void timer(const char* tag)
{
    ThreadState* s = (ThreadState*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    MonitorRecord* r = s->current04;
    if (r < s->end0C)
    {
        r->marker = tag;
        _ReadWriteBarrier();
        volatile unsigned int stamp = (unsigned int)__rdtsc();
        r->timestamp = stamp;
        s->current04 = r + 1;
    }
}
inline __m128 splat(float v)
{
    return _mm_set1_ps(v);
}
// @fnv 0x00d40280
void Manager::FUN_00d40280(Input* a, Input* b, Parameters* parameters, void* p4)
{
    timer("TtBoxBox");
    Shape* kIter;
    kIter = a->shape;
    Shape* tolerance = b->shape;
    struct Work
    {
        V4 minB, minA;
        Transform t;
        Job job;
    } w;
    V4* __restrict minA = &w.minA;
    V4* __restrict minB = &w.minB;
    _mm_store_ps(&minA->x, _mm_add_ps(splat(kIter->radius()), kIter->values20.m));
    _mm_store_ps(&minB->x, _mm_add_ps(splat(tolerance->radius()), tolerance->values20.m));
    Transform* __restrict t = &w.t;
    Job* __restrict job = &w.job;
    reinterpret_cast<::hkTransformCB22 *>((t))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(a->data08)), (*(const ::hkTransformCB22 *)(b->data08)));
    const float shapeB = parameters->offset08;
    job->toleranceB0 = shapeB;
    job->epsilonB4 = 0.01f;
    job->transform20.a.m = t->a.m;
    job->transform20.b.m = t->b.m;
    job->transform20.c.m = t->c.m;
    job->data0C = data08;
    job->parameters08 = parameters;
    job->unk10 = p4;
    job->dataA14 = a->data08;
    job->dataB18 = b->data08;
    job->transform20.d.m = t->d.m;
    job->first = a;
    job->second = b;
    job->minA60 = *minA;
    job->minB70 = *minB;
    job->tolerance80.m = splat(shapeB);
    job->expandedA90.m = _mm_add_ps(splat(shapeB), minA->m);
    job->expandedBA0.m = _mm_add_ps(splat(shapeB), minB->m);
    reinterpret_cast<::Manifold::NDetector *>((job))->FUN_00db2960((*(::Manifold::NManifold *)(&callback10)));
    timer("Et");
}
struct Query
{
    Input* first;
    Input* second;
    unsigned int count08, count0C, count10;
    void* dataA;
    void* dataB;
    unsigned int unk1C;
    Transform transform20;
    V4 minA60, minB70;
    Vector tolerance80, expandedA90, expandedBA0;
    float toleranceB0;
    float epsilonB4;
    int unkB8;
    int unkBC;
    Vector translationC0, translationD0, separationE0, separationF0, axis100, axis110, axis120;
    __forceinline void init(Input* a, Input* b, const Transform& t, const V4& minA, const V4& minB, float tolerance,
                            float epsilon)
    {
        first = a;
        second = b;
        count08 = 0;
        count0C = 0;
        count10 = 0;
        dataA = a->data08;
        dataB = b->data08;
        transform20.a.m = t.a.m;
        transform20.b.m = t.b.m;
        transform20.c.m = t.c.m;
        transform20.d.m = t.d.m;
        minA60 = minA;
        minB70 = minB;
        toleranceB0 = tolerance;
        epsilonB4 = epsilon;
        tolerance80.m = _mm_set1_ps(tolerance);
        expandedA90.m = _mm_add_ps(_mm_set1_ps(tolerance), minA.m);
        expandedBA0.m = _mm_add_ps(_mm_set1_ps(tolerance), minB.m);
    }
};
// @fnv 0x00d406c0
void __cdecl FUN_00d406c0(Input* a, Input* b, Parameters* parameters, Callback* callback)
{
    timer("TtBoxBox");
    Shape* shapeA = a->shape;
    Shape* shapeB = b->shape;
    struct CollisionWork
    {
        V4 minB, minA;
        Transform relative;
        Query query;
    } work;
    V4* __restrict minA = &work.minA;
    V4* __restrict minB = &work.minB;
    _mm_store_ps(&minA->x, _mm_add_ps(splat(shapeA->radius()), shapeA->values20.m));
    _mm_store_ps(&minB->x, _mm_add_ps(splat(shapeB->radius()), shapeB->values20.m));
    Transform* __restrict transform = &work.relative;
    Query* __restrict query = &work.query;
    reinterpret_cast<::hkTransformCB22 *>((transform))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(a->data08)), (*(const ::hkTransformCB22 *)(b->data08)));
    query->init(a, b, *transform, *minA, *minB, parameters->offset08, 0.01f);
    reinterpret_cast<::RotatedDir_d409 *>((query))->FUN_00d40940();
    if (!reinterpret_cast<::ThisCls *>((query))->FUN_00db0ec0((::Vec4f *)(::Vector *)(&query->tolerance80)))
        callback->handle(a, b);
    timer("Et");
}

// Moved from hkpboxboxagent_gs_nogs_variant.cpp (VEGAS-15).

// src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent_gs_nogs_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include <intrin.h>
#include "fnv/decl/BoxAgent.h"
inline void* operator new(size_t, void* p) { return p; }




struct TimerEntry70 {
    const char* name;
    unsigned int ticks;
    unsigned int unused;
};

struct TimerStream70 {
    void* unk00;
    TimerEntry70* top;
    TimerEntry70* start;
    TimerEntry70* end;
};

struct __declspec(align(16)) Vec70 {
    union { __m128 quad; struct { float x,y,z,w; }; };
    Vec70() {}
    Vec70& operator=(const Vec70& a) {
        quad=a.quad;
        return *this;
    }
};

struct Transform70 {
    Vec70 x, y, z, t;
    Transform70() {}
    Transform70(const Transform70& a) {
        x = a.x;
        y = a.y;
        z = a.z;
        t = a.t;
    }
};

struct Shape70 {
    int unk00, unk04, unk08, unk0c;
    float radius;
    int unk14, unk18, unk1c;
    Vec70 half;
    float GetRadius() const { return radius; }
};

struct Body70 {
    Shape70* shape;
    int unk04;
    Transform70* transform;
};

struct Input70 {
    int unk00, unk04;
    float tolerance;
    float GetTolerance() const { return tolerance; }
};

struct Contact70 {
    Vec70 point, normal;
    Body70* a;
    Body70* b;
};

struct Collector70 {
    virtual void Unknown();
    virtual void Add(Contact70*);
};

struct hkBool70 {
    char m_cBooleanValue;
    hkBool70() {}
    hkBool70(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};

struct Query70 {
    Body70* bodyA;
    Body70* bodyB;
    int flags08, flags0c, flags10;
    Transform70* transformA;
    Transform70* transformB;
    int unk1c;
    Transform70 relative;
    Vec70 halfA, halfB, toleranceVec, expandedA, expandedB;
    float tolerance, epsilon;
    int unkB8, unkBC;
    Vec70 workC0, workD0, workE0, workF0, work100, work110, work120;

    Query70() {}
    __forceinline Query70(Body70* a, Body70* b, const Transform70& rel, const Vec70& ha, const Vec70& hb, float tol)
        : bodyA(a), bodyB(b), flags08(0), flags0c(0), flags10(0),
          transformA(a->transform), transformB(b->transform), relative(rel),
          halfA(ha), halfB(hb), tolerance(tol), epsilon(0.01f) {
        toleranceVec.quad=_mm_set1_ps(tol);
        expandedA.quad=_mm_add_ps(toleranceVec.quad, ha.quad);
        expandedB.quad=_mm_add_ps(toleranceVec.quad, hb.quad);
    }

};

struct CollisionWork70 {
    Contact70 contact;
    Transform70 relative;
    Query70 query;
};

// @fnv 0x00d40470
extern "C" void __cdecl FUN_00d40470(void* first, void* second, void* rawInput, void* rawCollector)
{
    {
        TimerStream70* stream = (TimerStream70*)TlsGetValue(::DAT_0126835c);
        if (stream->top < stream->end) {
            TimerEntry70* r = stream->top;
            r->name = "TtBoxBox";
            unsigned int stamp;
            stamp = static_cast<unsigned int>(__rdtsc());
            r->ticks = stamp;
            stream->top = r + 1;
        }
    }

    Body70* a = (Body70*)first;
    Body70* b = (Body70*)second;
    Contact70 contact;
    Transform70 relative;
    Query70 query;
    Shape70* sa = a->shape;
    Shape70* sb = b->shape;
    Vec70 hb, ha;
    float r_ha=sa->GetRadius();
    ha; ha.quad=_mm_set1_ps(r_ha);
    ha.quad=_mm_add_ps(sa->half.quad, ha.quad);
    float r_hb=sb->GetRadius();
    hb; hb.quad=_mm_set1_ps(r_hb);
    hb.quad=_mm_add_ps(sb->half.quad, hb.quad);

    reinterpret_cast<::hkTransformCB22 *>(&(relative))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(a->transform)), (*(const ::hkTransformCB22 *)(b->transform)));

    new (&query) Query70(a, b, relative, ha, hb, ((Input70*)rawInput)->GetTolerance());

    contact.a = a;
    contact.b = b;

    hkBool70 hit = (*(::hkBool70 *)&(reinterpret_cast<::BoxAgent *>(&(query))->FUN_00db2750((*(::hkBool *)(&contact)), *(::hkContactPoint *)nullptr)));

    if (hit) {
        ((Collector70*)rawCollector)->Add(&contact);
    }

    {
        TimerStream70* stream = (TimerStream70*)TlsGetValue(::DAT_0126835c);
        if (stream->top < stream->end) {
            TimerEntry70* r = stream->top;
            r->name = "Et";
            unsigned int stamp;
            stamp = static_cast<unsigned int>(__rdtsc());
            r->ticks = stamp;
            stream->top = r + 1;
        }
    }
}
#include "generated/data/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.inc"
