
// src/havok/physics/collide/agent/miscagent/bv/hkpbvagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/bv/hkpbvagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCollisionDispatcher.h"
#include "havok/hkMemoryRouter.h"
#include <new>
#include "fnv/symbols_00c85000.h"
#include <cstddef>
#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
#include <windows.h>
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/symbols_00d45000.h"
#include "fnv/symbols_00d46000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_01076000.h"
#include "fnv/symbols_010ce000.h"
#include "fnv/symbols_01268000.h"
struct FUN_00d452a0_vtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(float, float, void*);
};
struct FUN_00d452a0
{
    const void* a;
    int b;
    const void* c;
    FUN_00d452a0_vtbl* p1;
    FUN_00d452a0_vtbl* p2;
    void Method(float f, float g, void* arg);
};
// Calls v10(f, g, arg) on p1, and also on p2 when p2 is non-null.
// @fnv 0x00d452a0
void FUN_00d452a0::Method(float afValue, float agValue, void* arg)
{
    p1->v10(afValue, agValue, arg);
    if (p2)
        p2->v10(afValue, agValue, arg);
}

struct FUN_00cfbbe0_vtbl
{
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    char b1;
    char b2;
};
struct FUN_00cfbbe0
{
};
// @fnv 0x00d45f80
void __cdecl ConfigureVtblHandlers(FUN_00cfbbe0* p)
{
    FUN_00cfbbe0_vtbl t1;
    t1.v0 = (void*)((void (&)())::fnv_00d45f30::FUN_00d45f30);
    t1.v1 = (void*)((void (&)())::FUN_00d46010);
    t1.v2 = (void*)((void (&)())::FUN_00d46050);
    t1.v3 = (void*)((void (&)())::FUN_00d46090);
    t1.b1 = 1;
    t1.b2 = 1;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((p))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::FUN_00cfbbe0_vtbl *)(&t1), -1, 0x1b);
    t1.v0 = (void*)((void (&)())::FUN_00d45480);
    t1.v1 = (void*)((void (&)())::FUN_00d45dd0);
    t1.v2 = (void*)((void (&)())::FUN_00d45af0);
    t1.v3 = (void*)((void (&)())::FUN_00d45800);
    t1.b1 = 0;
    t1.b2 = 1;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((p))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::FUN_00cfbbe0_vtbl *)(&t1), 0x1b, -1);
}

struct TargetVtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(void* arg);
};

struct TargetClass
{
    virtual ~TargetClass();
    int unk04;
    int unk08;
    TargetVtbl* p1;
    TargetVtbl* p2;

    void FUN_00d45230(void* arg);
};

// Calls v7(arg) on p1 and, if set, on p2 (then clears p2), and finally deletes this object.
// @fnv 0x00d45230
void TargetClass::FUN_00d45230(void* arg)
{
    p1->v7(arg);
    if (p2)
    {
        p2->v7(arg);
        p2 = 0;
    }
    delete this;
}

struct WorkerIface
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(void*);
};
struct Worker
{
    int a, b, c;
    WorkerIface* p1;
    WorkerIface* p2;
    void FUN_00d45270(void* value);
};
// Forwards value to the v9 method of p1 and, if p2 is non-null, to the v9 method of p2.
// @fnv 0x00d45270
void Worker::FUN_00d45270(void* value)
{
    p1->v9(value);
    if (p2)
        p2->v9(value);
}

struct FUN_00d45310_target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(int value);
};
struct FUN_00d45310_owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d45310_target* unk10;
    void FUN_00d45310(int value);
};
// @fnv 0x00d45310
void FUN_00d45310_owner::FUN_00d45310(int value)
{
    if (unk10)
        unk10->v12(value);
}

struct D45350CdBody;

struct D45350Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    const D45350Shape* m_childA;
    int unk14;
    const D45350Shape* m_childB;
};

struct D45350CdBody
{
    const D45350Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const D45350CdBody* m_parent;

    D45350CdBody(const D45350CdBody* parent) : m_parent(parent)
    {
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const D45350Shape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

struct D45350Collector
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void process(const D45350CdBody& body, void* a, void* b, void* c);
};

struct D45350Agent
{
    int unk00;
    int unk04;
    int unk08;
    D45350Collector* m_collectorA;
    D45350Collector* m_collectorB;

    void ProcessShapeChildren(const D45350CdBody& body, void* a, void* b, void* c);
};

// Builds a child body from the shape's m_childA and m_childB and passes it to m_collectorA and, if present, m_collectorB.
// @fnv 0x00d45350
void D45350Agent::ProcessShapeChildren(const D45350CdBody& body, void* apArg1, void* apArg2, void* apArg3)
{
    const D45350Shape* shape = body.m_pCollisionShape;
    D45350CdBody child(&body);
    child.SetCollisionShapeAndKey(shape->m_childA, 0xffffffff);
    m_collectorA->process(child, apArg1, apArg2, apArg3);
    if (m_collectorB)
    {
        child.SetCollisionShapeAndKey(shape->m_childB, 0);
        m_collectorB->process(child, apArg1, apArg2, apArg3);
    }
}


struct Functor_d46010
{
    void* m_vtbl;
    bool m_flag;
    void* m_uiFilterValue;
};


// Builds a Functor_d46010 with the given value and a false flag, then passes it with b, a and c to FUN_00d45dd0.
// @fnv 0x00d46010
void __cdecl FUN_00d46010(const void* aiArg1, const void* aiArg2, const void* aiArg3, void* aiValue)
{
    Functor_d46010 f;
    f.m_uiFilterValue = aiValue;
    f.m_flag = false;
    f.m_vtbl = (*reinterpret_cast<char (*)[]>(&::DAT_010ce81c));
    ::FUN_00d45dd0((*static_cast<const ::S_00d45dd0_CdBody *>(aiArg2)), (*static_cast<const ::S_00d45dd0_CdBody *>(aiArg1)), (*static_cast<const ::S_00d45dd0_Input *>(aiArg3)), (*(::S_00d45dd0_CollectorBase *)(&f)));
}

struct FUN_00d452f0_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(void* arg);
};

struct FUN_00d452f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d452f0_vt* m_p2;

    void DispatchToVt(void* arg);
};

// @fnv 0x00d452f0
void FUN_00d452f0_cls::DispatchToVt(void* arg)
{
    if (m_p2)
    {
        m_p2->v11(arg);
    }
}

// The object at +0x10 is a polymorphic sub-object; the original tail-jumps to
// its virtual at vtable offset 0x34 (slot 13) when it is not null.
struct SlotVt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(void* arg);
};

struct FUN_00d45330_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SlotVt* m_pFlagTarget;

    void CallSlotVt13(void* arg);
};

// @fnv 0x00d45330
void FUN_00d45330_cls::CallSlotVt13(void* arg)
{
    if (m_pFlagTarget != 0)
    {
        m_pFlagTarget->v13(arg);
    }
}

extern char DAT_010cf3cc;

struct FUN_00d453d0_Shape
{
    const void* m_vtable;
    unsigned short m_memSizeAndFlags;
    short m_referenceCount;
    unsigned int m_userData;
    int m_type;
};

struct FUN_00d453d0_BvShape : FUN_00d453d0_Shape
{
    const FUN_00d453d0_Shape* m_boundingVolumeShape;
};


// Offsets are the 32-bit release's.

struct FUN_00d453d0_Input
{
    hkpCollisionDispatcher* m_dispatcher;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_createPredictiveAgents;  // +0x14
};

// The child body handed to the bounding-volume agent.
struct FUN_00d453d0_args
{
    const FUN_00d453d0_Shape* m_00;
    int m_04;
    const void* m_08;
    const void* m_0C;
};

class FUN_00d453d0_cls
{
  public:
    FUN_00d453d0_cls* Construct(FUN_00d452a0* a1, void* a2, void* a3, void* a4);

    const void* m_vptr;    // 0x00
    unsigned short unk04;  // 0x04
    unsigned short m_06;   // 0x06
    void* m_08;            // 0x08
    void* m_0C;            // 0x0c
    void* m_10;            // 0x10, the child agent
};

// Initialises the object's vtable and fields, builds the child body from a1, and creates the child agent through the dispatcher's agent2 table.
// @fnv 0x00d453d0
FUN_00d453d0_cls* FUN_00d453d0_cls::Construct(FUN_00d452a0* a1, void* apArg2, void* apArg3, void* aiValue)
{
    m_vptr = &DAT_010cf3cc;
    m_06 = 1;
    m_08 = aiValue;

    FUN_00d453d0_args args;
    args.m_08 = a1->c;
    const FUN_00d453d0_Shape* shapeB = *static_cast<const FUN_00d453d0_Shape* const*>(apArg2);
    const FUN_00d453d0_Input* input = static_cast<const FUN_00d453d0_Input*>(apArg3);
    args.m_0C = a1;
    const FUN_00d453d0_Shape* y = static_cast<const FUN_00d453d0_BvShape*>(a1->a)->m_boundingVolumeShape;
    hkpCollisionDispatcher* dispatcher = input->m_dispatcher;
    args.m_00 = y;
    args.m_04 = -1;
    const signed char (*tab)[32] = (input->m_createPredictiveAgents != 0) ? dispatcher->m_agent2TypesPred : dispatcher->m_agent2Types;
    unsigned char idx = tab[y->m_type][shapeB->m_type];
    void* fn = dispatcher->m_agent2Func[idx].m_createFunc;
    m_0C = ((void*(__cdecl*)(FUN_00d453d0_args*, void*, void*, void*))fn)(&args, apArg2, apArg3, aiValue);
    m_10 = 0;
    return this;
}




class D45480ReferencedObject
{
  public:
    static void* operator new(size_t nbytes)
    {
        D45480ReferencedObject* b =
            static_cast<D45480ReferencedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~D45480ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class D45480Object : public D45480ReferencedObject
{
  public:
    __declspec(nothrow) D45480Object(void* a, void* b, void* c, void* d);

    void* m_contactMgr;           // +0x08
    void* m_boundingVolumeAgent;  // +0x0c
    void* m_childAgent;           // +0x10
};

// Allocates a D45480Object via its four-argument constructor and returns the new object.
// @fnv 0x00d45480
D45480Object* __cdecl FUN_00d45480(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    return new D45480Object(apArg1, apArg2, apArg3, apArg4);
}


struct FUN_00d46050_cls
{
    void* vt;
    float f;
    int d;
};

// Builds a FUN_00d46050_cls from DAT_0104da48 and a4, then calls FUN_00d45af0 with a2, a1, a3 and a pointer to it.
// @fnv 0x00d46050
void __cdecl FUN_00d46050(int aiArg1, int aiArg2, int aiArg3, int aiValue)
{
    FUN_00d46050_cls local;
    local.f = ::DAT_0104da48;
    local.d = aiValue;
    local.vt = &(*reinterpret_cast<char *>(&::DAT_010ce7fc));
    ((void(__cdecl*)(int, int, int, FUN_00d46050_cls*))((void (&)())::FUN_00d45af0))(aiArg2, aiArg1, aiArg3, &local);
}

struct CallTarget_00d45350
{
    int ProcessShapeChildren(int, int, int, int);
};
struct SearchObject
{
    int FUN_00d46180(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
};
// @fnv 0x00d46180
int SearchObject::FUN_00d46180(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3)
{
    unsigned int callResult0 =
        (unsigned int)((CallTarget_00d45350*)this)->ProcessShapeChildren((int)arg1, (int)arg0, (int)arg2, (int)arg3);
    return (int)callResult0;
}

struct FUN_00d461a0_Args
{
    void* unk00;
    char unk04;
    void* unk08;
};


struct FUN_00d461a0_Owner
{
    int unk00;
    int unk04;
    int unk08;
    void* unk0c;
    void* unk10;
    virtual void DispatchWithArgs(const void*, const void*, const void*, void*);
};

namespace fnv_00d461e0 {

struct Rec
{
    void* m_p;
    float m_f;
    int m_i;
};

struct FUN_00d461e0_Cls
{
    void GetPenetrations(int, int, int, Rec*);
    void FUN_00d461e0(int a1, int a2, int a3, int a4);
};

// Builds a Rec from a4, DAT_0104da48 and DAT_010ce7fc, then calls GetPenetrations with a2, a1, a3 and the Rec.
// @fnv 0x00d461e0
void FUN_00d461e0_Cls::FUN_00d461e0(int aiArg1, int aiArg2, int aiArg3, int aiValue)
{
    Rec rec;
    rec.m_i = aiValue;
    rec.m_f = ::DAT_0104da48;
    rec.m_p = &(*reinterpret_cast<void * *>(&::DAT_010ce7fc));
    GetPenetrations(aiArg2, aiArg1, aiArg3, &rec);
}
}  // namespace fnv_00d461e0

extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern char DAT_010cebd0;

struct MonStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pRayCursor;
};
struct MonEntry
{
    const char* name;
    unsigned int ticks;
    int unk08;
};
struct MonEntryObj
{
    const char* name;
    unsigned int ticks;
    int unk08;
    const char* obj;
};

inline void TimerBeginObj(const char* name, const char* obj)
{
    MonStream* ms = (MonStream*)TlsGetValue(DAT_0126835c);
    MonEntryObj* p = (MonEntryObj*)ms->m_kRayEnd;
    if ((char*)p < ms->m_pRayCursor)
    {
        p->name = name;
        p->obj = obj;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        p->ticks = t;
        ms->m_kRayEnd = (char*)(p + 1);
    }
}
inline void TimerMark(const char* name)
{
    MonStream* ms = (MonStream*)TlsGetValue(DAT_0126835c);
    MonEntry* p = (MonEntry*)ms->m_kRayEnd;
    if ((char*)p < ms->m_pRayCursor)
    {
        p->name = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        p->ticks = t;
        ms->m_kRayEnd = (char*)(p + 1);
    }
}

extern char DAT_010cf414[];
extern char DAT_010cf404[];

struct BvShape
{
    int unk00, unk04, unk08;
    unsigned int m_type;
    BvShape* m_boundingShape;
    int unk14;
    BvShape* m_pContainedShape;
};
struct CdBody
{
    BvShape* m_pCollisionShape;
    unsigned int m_key;
    unsigned int m_pMotionState;
    CdBody* m_parent;
};
struct CollisionInput;
typedef void(__cdecl* CollideFn)(CdBody* a, CdBody* b, CollisionInput* input, void* collector);
struct CollisionInput
{
    const hkpCollisionDispatcher* m_pCollisionDispatcher;
};
struct EarlyOutCollector
{
    void* m_vtbl;
    bool m_bHasHit;
};
union BeginRecordOrCollector
{
    volatile unsigned int tick;
    EarlyOutCollector early;
};

// @fnv 0x00d45af0
void __cdecl FUN_00d45af0(CdBody* bodyA, CdBody* bodyB, CollisionInput* input, void* collector)
{
    CdBody child;
    BeginRecordOrCollector scratch;
    {
        MonStream* ms = (MonStream*)TlsGetValue(DAT_0126835c);
        MonEntryObj* p = (MonEntryObj*)ms->m_kRayEnd;
        if ((char*)p < ms->m_pRayCursor)
        {
            p->name = DAT_010cf414;
            p->obj = DAT_010cf404;
            _ReadWriteBarrier();
            scratch.tick = (unsigned int)__rdtsc();
            p->ticks = scratch.tick;
            ms->m_kRayEnd = (char*)(p + 1);
        }
    }
    BvShape* bv = bodyA->m_pCollisionShape;
    child.m_parent = bodyA;
    child.m_pMotionState = bodyA->m_pMotionState;
    child.m_pCollisionShape = bv->m_boundingShape;
    child.m_key = 0xffffffff;
    unsigned int typeB = bodyB->m_pCollisionShape->m_type;
    const hkpCollisionDispatcher* dispatcher = input->m_pCollisionDispatcher;
    CollideFn firstHandler = reinterpret_cast<CollideFn>(
        dispatcher->m_agent2Func[(unsigned char)dispatcher->m_agent2Types[child.m_pCollisionShape->m_type][typeB]].m_getPenetrationsFunc);
    scratch.early.m_vtbl = &DAT_010cebd0;
    scratch.early.m_bHasHit = false;
    firstHandler(&child, bodyB, input, &scratch.early);
    if (scratch.early.m_bHasHit)
    {
        TimerMark(DAT_010cec4c);
        child.m_pCollisionShape = bv->m_pContainedShape;
        child.m_key = 0;
        dispatcher = input->m_pCollisionDispatcher;
        reinterpret_cast<CollideFn>(
            dispatcher->m_agent2Func[(unsigned char)dispatcher->m_agent2Types[child.m_pCollisionShape->m_type][typeB]].m_getClosestPointsFunc)(
            &child, bodyB, input, collector);
    }
    TimerMark(::str_01076f38);
}

struct S00d454c0_Input
{
    const hkpCollisionDispatcher* m_pCollisionDispatcher;
    int unk04, unk08, unk0c, unk10;
    int m_useAlt;
};
struct S00d454c0_Agent;
typedef S00d454c0_Agent*(__cdecl* S00d454c0_CreateFn)(CdBody* a, CdBody* b, S00d454c0_Input* input, void* mgr);
struct S00d454c0_Agent
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void ProcessAgent(CdBody* a, CdBody* b, S00d454c0_Input* input, void* result);
    virtual void cleanup(void* constraintOwner);
};
struct S00d454c0_Filter
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void check(CdBody* a, CdBody* b, S00d454c0_Input* input, EarlyOutCollector* out);
};
__forceinline S00d454c0_Agent* S00d454c0_getNewAgent(const hkpCollisionDispatcher* d, CdBody& a, CdBody& b, S00d454c0_Input& input,
                                                     void* mgr)
{
    unsigned int typeA = a.m_pCollisionShape->m_type;
    unsigned int typeB = b.m_pCollisionShape->m_type;
    const signed char (*agents)[32] = input.m_useAlt ? d->m_agent2TypesPred : d->m_agent2Types;
    int idx = (unsigned char)agents[typeA][typeB];
    S00d454c0_CreateFn f = reinterpret_cast<S00d454c0_CreateFn>(d->m_agent2Func[idx].m_createFunc);
    return f(&a, &b, &input, mgr);
}
struct S00d454c0_Result
{
    int unk00;
    void* m_pConstraintOwner;
};
struct S00d454c0_Owner
{
    int unk00;
    int unk04;
    void* m_pManager;
    S00d454c0_Filter* m_iFilter;
    S00d454c0_Agent* m_pCollisionAgent;
    void FUN_00d454c0(CdBody* bodyA, CdBody* bodyB, S00d454c0_Input* input, S00d454c0_Result* result);
};
// @fnv 0x00d454c0
void S00d454c0_Owner::FUN_00d454c0(CdBody* bodyA, CdBody* bodyB, S00d454c0_Input* input, S00d454c0_Result* result)
{
    TimerBeginObj(DAT_010cf414, DAT_010cf404);
    BvShape* shape = bodyA->m_pCollisionShape;
    CdBody body;
    body.m_parent = bodyA;
    body.m_pMotionState = bodyA->m_pMotionState;
    body.m_pCollisionShape = shape->m_boundingShape;
    body.m_key = 0xffffffff;
    EarlyOutCollector out;
    out.m_vtbl = &DAT_010cebd0;
    out.m_bHasHit = false;
    m_iFilter->check(&body, bodyB, input, &out);
    if (out.m_bHasHit)
    {
        TimerMark(DAT_010cec4c);
        body.m_pCollisionShape = shape->m_pContainedShape;
        body.m_key = 0;
        if (!m_pCollisionAgent)
        {
            m_pCollisionAgent = S00d454c0_getNewAgent(input->m_pCollisionDispatcher, body, *bodyB, *input, m_pManager);
        }
        m_pCollisionAgent->ProcessAgent(&body, bodyB, input, result);
    }
    else if (m_pCollisionAgent)
    {
        m_pCollisionAgent->cleanup(result->m_pConstraintOwner);
        m_pCollisionAgent = 0;
    }
    TimerMark(::str_01076f38);
}



struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
};

struct Agent : AgentBase
{
    void FUN_00d46220(void* a, void* b, void* c, Simplex* s);
};

// Calls base FUN_00d454c0, then updates vertex SIMD data and swaps simplex dimension and id fields when the closest point distance changed.
// @fnv 0x00d46220
void Agent::FUN_00d46220(void* a, void* b, void* c, Simplex* apSimplex)
{
    SimplexVertex* pVertex = apSimplex->m_kRayEnd;
    float oldDistance = apSimplex->m_fClosestPointDistanceSquared;
    reinterpret_cast<::S00d454c0_Owner *>(this)->FUN_00d454c0(static_cast<::CdBody *>(b), static_cast<::CdBody *>(a), static_cast<::S00d454c0_Input *>(c), (::S00d454c0_Result *)(apSimplex));
    for (; pVertex < apSimplex->m_kRayEnd; pVertex++)
    {
        const __m128* pb = &pVertex->m_kPointB;
        __m128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        pVertex->m_kPointA = _mm_add_ps(_mm_mul_ps(w, pVertex->m_kPointB), pVertex->m_kPointA);
        pVertex->m_kPointB = _mm_xor_ps(pVertex->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != apSimplex->m_fClosestPointDistanceSquared)
    {
        __m128* n = &apSimplex->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = apSimplex->m_dims.m_ucLowNibble;
            apSimplex->m_dims.m_ucLowNibble = apSimplex->m_dims.m_ucHighNibble;
            apSimplex->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = apSimplex->m_ucDimensionA;
            apSimplex->m_ucDimensionA = apSimplex->m_ucDimensionB;
            apSimplex->m_ucDimensionB = t;
        }
        int last = apSimplex->m_ucDimensionA + apSimplex->m_ucDimensionB - 1;
        unsigned short t0 = apSimplex->m_ids[0];
        apSimplex->m_ids[0] = apSimplex->m_ids[last];
        apSimplex->m_ids[last] = t0;
        if ((apSimplex->m_ucDimensionA & apSimplex->m_ucDimensionB) == 2)
        {
            unsigned short t1 = apSimplex->m_ids[1];
            apSimplex->m_ids[1] = apSimplex->m_ids[2];
            apSimplex->m_ids[2] = t1;
        }
    }
}


struct __declspec(align(16)) D45800Collector
{
    void* m_vtbl;
    float m_fEarlyOutDistance;
    bool m_bHasHit;
    int pad0c;
    float m_vContactPosition[4];
    float m_vHitNormal[3];
    float m_fClosestPointDistanceSquared;
    D45800Collector()
    {
        m_vtbl = &DAT_010cebe0;
        m_fClosestPointDistanceSquared = ::DAT_0104da48;
        m_fEarlyOutDistance = ::DAT_0104da48;
        m_bHasHit = false;
    }
};

static inline CollideFn D45800Get(CollisionInput* input, BvShape* a, unsigned int typeB)
{
    const hkpCollisionDispatcher* disp = input->m_pCollisionDispatcher;
    return reinterpret_cast<CollideFn>(disp->m_agent2Func[(unsigned char)disp->m_agent2Types[a->m_type][typeB]].m_linearCastFunc);
}

static __forceinline void D458Begin(const char* name, const char* obj, volatile unsigned int& t)
{
    MonStream* ms = (MonStream*)TlsGetValue(DAT_0126835c);
    MonEntryObj* p = (MonEntryObj*)ms->m_kRayEnd;
    if ((char*)p < ms->m_pRayCursor)
    {
        p->name = name;
        p->obj = obj;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        p->ticks = t;
        ms->m_kRayEnd = (char*)(p + 1);
    }
}
static __forceinline void D458Mark(const char* name, volatile unsigned int& t)
{
    MonStream* ms = (MonStream*)TlsGetValue(DAT_0126835c);
    MonEntry* p = (MonEntry*)ms->m_kRayEnd;
    if ((char*)p < ms->m_pRayCursor)
    {
        p->name = name;
        _ReadWriteBarrier();
        t = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        p->ticks = t;
        ms->m_kRayEnd = (char*)(p + 1);
    }
}

typedef void(__cdecl* CollideFn5)(CdBody* a, CdBody* b, CollisionInput* input, void* c, void* d);

// Tests bodyA's bounding shape against bodyB via a dispatched collide function, then if a hit is found, re-tests the contained shape.
// @fnv 0x00d45800
void __cdecl FUN_00d45800(CdBody* bodyA, CdBody* bodyB, CollisionInput* input, void* c, void* d)
{
    volatile unsigned int ticks;
    D458Begin(DAT_010cf414, DAT_010cf404, ticks);
    BvShape* bvShape = bodyA->m_pCollisionShape;
    CdBody tmp;
    tmp.m_parent = bodyA;
    tmp.m_pMotionState = bodyA->m_pMotionState;
    tmp.m_pCollisionShape = bvShape->m_boundingShape;
    tmp.m_key = 0xffffffff;
    unsigned int typeB = bodyB->m_pCollisionShape->m_type;
    CollideFn5 fn = (CollideFn5)D45800Get(input, tmp.m_pCollisionShape, typeB);
    D45800Collector coll;
    fn(&tmp, bodyB, input, &coll, &coll);
    if (coll.m_bHasHit)
    {
        D458Mark(DAT_010cec4c, ticks);
        tmp.m_pCollisionShape = bvShape->m_pContainedShape;
        tmp.m_key = 0;
        fn = (CollideFn5)D45800Get(input, tmp.m_pCollisionShape, typeB);
        fn(&tmp, bodyB, input, c, d);
    }
    D458Mark(::str_01076f38, ticks);
}


struct __declspec(align(16)) Key_d2e9
{
    unsigned int m_k0;
    unsigned int m_k1;
    unsigned int m_k2;
    unsigned int m_k3;
};

struct Input_d2e9
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    union
    {
        __m128 m_vComponents;
        Key_d2e9 m_key;
    };
    int unk60, unk64, unk68, unk6c;
};

struct Record_d2e9
{
    const unsigned int* m_vtbl;
    float m_fScalar;
    Key_d2e9 m_key;
    void* m_uiFilterValue;
};


// Copies input, XORs its m_vComponents with DAT_010c44d0, builds a Record_d2e9 with a4, and calls FUN_00d45800 with a second record when a5 is non-zero.
// @fnv 0x00d46090
void __cdecl FUN_00d46090(void* a2, void* a1, const Input_d2e9* input, void* a4, void* a5)
{
    Input_d2e9 local = *input;
    local.m_vComponents = _mm_xor_ps(input->m_vComponents, DAT_010c44d0);

    Record_d2e9 rec;
    rec.m_vtbl = &(*reinterpret_cast<unsigned int *>(&::UNK_010ce80c));
    rec.m_fScalar = ::DAT_0104da48;
    rec.m_key = input->m_key;
    rec.m_uiFilterValue = a4;

    if (a5 != 0)
    {
        Record_d2e9 rec2;
        rec2.m_vtbl = &(*reinterpret_cast<unsigned int *>(&::UNK_010ce80c));
        rec2.m_fScalar = ::DAT_0104da48;
        rec2.m_key = input->m_key;
        rec2.m_uiFilterValue = a5;
        ::FUN_00d45800(static_cast<::CdBody *>(a1), static_cast<::CdBody *>(a2), (::CollisionInput *)(::Input_d2e9 *)(&local), &rec, &rec2);
    }
    else
    {
        ::FUN_00d45800(static_cast<::CdBody *>(a1), static_cast<::CdBody *>(a2), (::CollisionInput *)(::Input_d2e9 *)(&local), &rec, 0);
    }
}

#include <windows.h>
#include "fnv/symbols_simd.h"

struct S_00d45970_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = *(volatile unsigned int*)&t;
    }
};

struct S_00d45970_TimerBeginListCommand : S_00d45970_TimerCommand
{
    const char* m_pFirst;
};

struct S_00d45970_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00d45970_MonitorStream& GetMonitorStream()
    {
        return *(S_00d45970_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

struct S_00d45970_Shape
{
    void* vtbl;
    int unk04;
    int unk08;
    int m_type;
};

struct S_00d45970_BvShape : S_00d45970_Shape
{
    const S_00d45970_Shape* m_pBvShapeReference;
    void* m_childVtbl;
    const S_00d45970_Shape* m_pContainedShape;
};

struct S_00d45970_CdBody
{
    const S_00d45970_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S_00d45970_CdBody* m_parent;
    S_00d45970_CdBody(const S_00d45970_CdBody* parent) : m_parent(parent)
    {
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const S_00d45970_Shape* s, unsigned int key)
    {
        m_pCollisionShape = s;
        m_uiCollisionShapeKey = key;
    }
};

struct S_00d45970_CollectorBase
{
    virtual void AddCdBodyPair(const S_00d45970_CdBody&, const S_00d45970_CdBody&);
    virtual void reset();
};

struct S_00d45970_FlagCollector : S_00d45970_CollectorBase
{
    bool m_bHit;
    S_00d45970_FlagCollector()
    {
        m_bHit = false;
    }
    virtual void AddCdBodyPair(const S_00d45970_CdBody&, const S_00d45970_CdBody&);
    virtual void reset();
};

struct S_00d45970_Agent;
struct S_00d45970_Input;
struct S_00d45970_ContactMgr;

typedef S_00d45970_Agent*(__cdecl* S_00d45970_CreateFunc)(const S_00d45970_CdBody&, const S_00d45970_CdBody&,
                                                          const S_00d45970_Input&, S_00d45970_ContactMgr*);


struct S_00d45970_Dispatcher : hkpCollisionDispatcher
{
    __forceinline int getAgentType(int typeA, int typeB, unsigned int predictive) const
    {
        return (unsigned char)(predictive ? m_agent2TypesPred : m_agent2Types)[typeA][typeB];
    }
    S_00d45970_Agent* getNewCollisionAgent(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB,
                                           const S_00d45970_Input& input, S_00d45970_ContactMgr* mgr) const;
};

struct S_00d45970_Input
{
    S_00d45970_Dispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_bCreatePredictiveAgents;
};

__forceinline S_00d45970_Agent* S_00d45970_Dispatcher::getNewCollisionAgent(const S_00d45970_CdBody& bodyA,
                                                                            const S_00d45970_CdBody& bodyB,
                                                                            const S_00d45970_Input& input,
                                                                            S_00d45970_ContactMgr* mgr) const
{
    int typeA = bodyA.m_pCollisionShape->m_type;
    int typeB = bodyB.m_pCollisionShape->m_type;
    int idx = getAgentType(typeA, typeB, input.m_bCreatePredictiveAgents);
    S_00d45970_CreateFunc f = reinterpret_cast<S_00d45970_CreateFunc>(m_agent2Func[idx].m_createFunc);
    return f(bodyA, bodyB, input, mgr);
}

struct S_00d45970_Output;

struct S_00d45970_Agent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void getPenetrations(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB,
                                 const S_00d45970_Input& input, S_00d45970_CollectorBase& collector);
};

struct S_00d45970_BvAgent;

struct S_00d45970_BvAgentBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void getPenetrations(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB,
                                 const S_00d45970_Input& input, S_00d45970_CollectorBase& collector);
};

struct S_00d45970_BvAgent
{
    void* vtbl;
    int unk04;
    S_00d45970_ContactMgr* m_pContactManager;
    S_00d45970_BvAgentBase* m_pBoundingVolumeAgent;
    S_00d45970_Agent* m_pAgent;

    void GetPenetrations(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB, const S_00d45970_Input& input,
                         S_00d45970_CollectorBase& result);
};

// Checks bounding volume overlap, then dispatches to the contained shape agent to collect penetrations into result.
// @fnv 0x00d45970
void S_00d45970_BvAgent::GetPenetrations(const S_00d45970_CdBody& bodyA, const S_00d45970_CdBody& bodyB,
                                         const S_00d45970_Input& input, S_00d45970_CollectorBase& result)
{
    {
        S_00d45970_MonitorStream& mStream = S_00d45970_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            S_00d45970_TimerBeginListCommand* h = (S_00d45970_TimerBeginListCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "LthkpBvAgent";
            h->m_pFirst = "StcheckBvShape";
            _ReadWriteBarrier();
            h->setTime();
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }

    {
        const S_00d45970_BvShape* bvShape = (const S_00d45970_BvShape*)bodyA.m_pCollisionShape;

        S_00d45970_CdBody newBodyA(&bodyA);
        newBodyA.SetCollisionShapeAndKey(bvShape->m_pBvShapeReference, 0xffffffff);

        S_00d45970_FlagCollector checker;
        m_pBoundingVolumeAgent->getPenetrations(newBodyA, bodyB, input, checker);

        if (checker.m_bHit)
        {
            {
                S_00d45970_MonitorStream& mStream = S_00d45970_MonitorStream::GetMonitorStream();
                if (mStream.memoryAvailable())
                {
                    S_00d45970_TimerCommand* h = (S_00d45970_TimerCommand*)mStream.m_kRayEnd;
                    h->m_pCommandName = "Stchild";
                    _ReadWriteBarrier();
                    h->setTime();
                    mStream.m_kRayEnd = (char*)(h + 1);
                }
            }
            newBodyA.SetCollisionShapeAndKey(bvShape->m_pContainedShape, 0);
            if (!m_pAgent)
            {
                m_pAgent =
                    input.m_pCollisionDispatcher->getNewCollisionAgent(newBodyA, bodyB, input, m_pContactManager);
            }
            m_pAgent->getPenetrations(newBodyA, bodyB, input, result);
        }
    }

    {
        S_00d45970_MonitorStream& mStream = S_00d45970_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            S_00d45970_TimerCommand* h = (S_00d45970_TimerCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "lt";
            _ReadWriteBarrier();
            h->setTime();
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }
}


struct S_00d45c50_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = *(volatile unsigned int*)&t;
    }
};

struct S_00d45c50_TimerBeginListCommand : S_00d45c50_TimerCommand
{
    const char* m_pFirst;
};

struct S_00d45c50_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00d45c50_MonitorStream& GetMonitorStream()
    {
        return *(S_00d45c50_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

struct S_00d45c50_Shape
{
    void* vtbl;
    int unk04;
    int unk08;
    int m_type;
};

struct S_00d45c50_BvShape : S_00d45c50_Shape
{
    const S_00d45c50_Shape* m_pBvShapeReference;
    void* m_childVtbl;
    const S_00d45c50_Shape* m_pContainedShape;
};

struct S_00d45c50_CdBody
{
    const S_00d45c50_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S_00d45c50_CdBody* m_parent;
    S_00d45c50_CdBody(const S_00d45c50_CdBody* parent) : m_parent(parent)
    {
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const S_00d45c50_Shape* s, unsigned int key)
    {
        m_pCollisionShape = s;
        m_uiCollisionShapeKey = key;
    }
};

struct S_00d45c50_CollectorBase
{
    virtual void AddCdBodyPair(const S_00d45c50_CdBody&, const S_00d45c50_CdBody&);
    virtual void reset();
};

struct S_00d45c50_FlagCollector : S_00d45c50_CollectorBase
{
    bool m_bHit;
    S_00d45c50_FlagCollector()
    {
        m_bHit = false;
    }
    virtual void AddCdBodyPair(const S_00d45c50_CdBody&, const S_00d45c50_CdBody&);
    virtual void reset();
};

struct S_00d45c50_Agent;
struct S_00d45c50_Input;
struct S_00d45c50_ContactMgr;

typedef S_00d45c50_Agent*(__cdecl* S_00d45c50_CreateFunc)(const S_00d45c50_CdBody&, const S_00d45c50_CdBody&,
                                                          const S_00d45c50_Input&, S_00d45c50_ContactMgr*);


struct S_00d45c50_Dispatcher : hkpCollisionDispatcher
{
    __forceinline int getAgentType(int typeA, int typeB, unsigned int predictive) const
    {
        return (unsigned char)(predictive ? m_agent2TypesPred : m_agent2Types)[typeA][typeB];
    }
    S_00d45c50_Agent* getNewCollisionAgent(const S_00d45c50_CdBody& bodyA, const S_00d45c50_CdBody& bodyB,
                                           const S_00d45c50_Input& input, S_00d45c50_ContactMgr* mgr) const;
};

struct S_00d45c50_Input
{
    S_00d45c50_Dispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int m_bCreatePredictiveAgents;
};

__forceinline S_00d45c50_Agent* S_00d45c50_Dispatcher::getNewCollisionAgent(const S_00d45c50_CdBody& bodyA,
                                                                            const S_00d45c50_CdBody& bodyB,
                                                                            const S_00d45c50_Input& input,
                                                                            S_00d45c50_ContactMgr* mgr) const
{
    int typeA = bodyA.m_pCollisionShape->m_type;
    int typeB = bodyB.m_pCollisionShape->m_type;
    int idx = getAgentType(typeA, typeB, input.m_bCreatePredictiveAgents);
    S_00d45c50_CreateFunc f = reinterpret_cast<S_00d45c50_CreateFunc>(m_agent2Func[idx].m_createFunc);
    return f(bodyA, bodyB, input, mgr);
}

struct S_00d45c50_Output;

struct S_00d45c50_Agent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void ProcessAgent(const S_00d45c50_CdBody& bodyA, const S_00d45c50_CdBody& bodyB,
                                  const S_00d45c50_Input& input, S_00d45c50_Output& result);
};

struct S_00d45c50_BvAgent;

struct S_00d45c50_BvAgentBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void getPenetrations(const S_00d45c50_CdBody& bodyA, const S_00d45c50_CdBody& bodyB,
                                 const S_00d45c50_Input& input, S_00d45c50_CollectorBase& collector);
};

struct S_00d45c50_BvAgent
{
    void* vtbl;
    int unk04;
    S_00d45c50_ContactMgr* m_pContactManager;
    S_00d45c50_BvAgentBase* m_pBoundingVolumeAgent;
    S_00d45c50_Agent* m_pAgent;

    void FUN_00d45c50(const S_00d45c50_CdBody& bodyA, const S_00d45c50_CdBody& bodyB, const S_00d45c50_Input& input,
                      S_00d45c50_Output& result);
};
// Builds an argument struct from DAT_010ce81c and a4, then forwards a2, a1, a3 and the struct to FUN_00d45c50.
// @fnv 0x00d461a0
void FUN_00d461a0_Owner::DispatchWithArgs(const void* aiArg1, const void* aiArg2, const void* aiArg3, void* aiArg4)
{
    FUN_00d461a0_Args l;
    l.unk08 = aiArg4;
    l.unk04 = 0;
    l.unk00 = (*reinterpret_cast<char (*)[]>(&::DAT_010ce81c));
    reinterpret_cast<::S_00d45c50_BvAgent *>((this))->FUN_00d45c50((*static_cast<const ::S_00d45c50_CdBody *>(aiArg2)), (*static_cast<const ::S_00d45c50_CdBody *>(aiArg1)), (*static_cast<const ::S_00d45c50_Input *>(aiArg3)), (*(::S_00d45c50_Output *)(&l)));
}

// Checks bounding volume penetration between two collision bodies and, on hit, dispatches the contained-shape collision agent to fill the output result.
// @fnv 0x00d45c50
void S_00d45c50_BvAgent::FUN_00d45c50(const S_00d45c50_CdBody& bodyA, const S_00d45c50_CdBody& bodyB,
                                      const S_00d45c50_Input& input, S_00d45c50_Output& result)
{
    {
        S_00d45c50_MonitorStream& mStream = S_00d45c50_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            S_00d45c50_TimerBeginListCommand* h = (S_00d45c50_TimerBeginListCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "LthkpBvAgent";
            h->m_pFirst = "StcheckBvShape";
            _ReadWriteBarrier();
            h->setTime();
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }

    {
        const S_00d45c50_BvShape* bvShape = (const S_00d45c50_BvShape*)bodyA.m_pCollisionShape;

        S_00d45c50_CdBody newBodyA(&bodyA);
        newBodyA.SetCollisionShapeAndKey(bvShape->m_pBvShapeReference, 0xffffffff);

        S_00d45c50_FlagCollector checker;
        m_pBoundingVolumeAgent->getPenetrations(newBodyA, bodyB, input, checker);

        if (checker.m_bHit)
        {
            {
                S_00d45c50_MonitorStream& mStream = S_00d45c50_MonitorStream::GetMonitorStream();
                if (mStream.memoryAvailable())
                {
                    S_00d45c50_TimerCommand* h = (S_00d45c50_TimerCommand*)mStream.m_kRayEnd;
                    h->m_pCommandName = "Stchild";
                    _ReadWriteBarrier();
                    h->setTime();
                    mStream.m_kRayEnd = (char*)(h + 1);
                }
            }
            newBodyA.SetCollisionShapeAndKey(bvShape->m_pContainedShape, 0);
            if (!m_pAgent)
            {
                m_pAgent =
                    input.m_pCollisionDispatcher->getNewCollisionAgent(newBodyA, bodyB, input, m_pContactManager);
            }
            m_pAgent->ProcessAgent(newBodyA, bodyB, input, result);
        }
    }

    {
        S_00d45c50_MonitorStream& mStream = S_00d45c50_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            S_00d45c50_TimerCommand* h = (S_00d45c50_TimerCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "lt";
            _ReadWriteBarrier();
            h->setTime();
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }
}


struct S_00d45dd0_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        unsigned int t = (unsigned int)__rdtsc();
        m_uiStartTicks = *(volatile unsigned int*)&t;
    }
};

struct S_00d45dd0_TimerBeginListCommand : S_00d45dd0_TimerCommand
{
    const char* m_pFirst;
};

struct S_00d45dd0_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static S_00d45dd0_MonitorStream& GetMonitorStream()
    {
        return *(S_00d45dd0_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
};

struct S_00d45dd0_Shape
{
    void* vtbl;
    int unk04;
    int unk08;
    int m_type;
};

struct S_00d45dd0_BvShape : S_00d45dd0_Shape
{
    const S_00d45dd0_Shape* m_pBvShapeReference;
    void* m_childVtbl;
    const S_00d45dd0_Shape* m_pContainedShape;
};

struct S_00d45dd0_CdBody
{
    const S_00d45dd0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S_00d45dd0_CdBody* m_parent;
    S_00d45dd0_CdBody(const S_00d45dd0_CdBody* parent) : m_parent(parent)
    {
        m_pMotionState = parent->m_pMotionState;
    }
    void SetCollisionShapeAndKey(const S_00d45dd0_Shape* s, unsigned int key)
    {
        m_pCollisionShape = s;
        m_uiCollisionShapeKey = key;
    }
};

struct S_00d45dd0_CollectorBase
{
    virtual void AddCdBodyPair(const S_00d45dd0_CdBody&, const S_00d45dd0_CdBody&);
    virtual void reset();
};

struct S_00d45dd0_FlagCollector : S_00d45dd0_CollectorBase
{
    bool m_bHit;
    S_00d45dd0_FlagCollector()
    {
        m_bHit = false;
    }
    virtual void AddCdBodyPair(const S_00d45dd0_CdBody&, const S_00d45dd0_CdBody&);
    virtual void reset();
};

struct S_00d45dd0_Input;

typedef void(__cdecl* S_00d45dd0_PenFunc)(const S_00d45dd0_CdBody&, const S_00d45dd0_CdBody&, const S_00d45dd0_Input&,
                                          S_00d45dd0_CollectorBase&);

struct S_00d45dd0_Funcs
{
    void* unk00;
    S_00d45dd0_PenFunc m_pQueryPenetrationsFunc;
    void* unk08;
    void* unk0C;
    void* unk10;
};

struct S_00d45dd0_Dispatcher
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    unsigned char m_agent2TypeMap[32][32];
    unsigned char m_agent3TypeMap[32][32];
    S_00d45dd0_Funcs m_agent2Funcs[64];

    __forceinline S_00d45dd0_PenFunc getPenetrationsFunc(int typeA, int typeB) const
    {
        return m_agent2Funcs[m_agent2TypeMap[typeA][typeB]].m_pQueryPenetrationsFunc;
    }
};

struct S_00d45dd0_Input
{
    S_00d45dd0_Dispatcher* m_pCollisionDispatcher;
};

// Checks BvShape containment for bodyA against bodyB, then queries penetrations on the contained shape if a hit is found.
// @fnv 0x00d45dd0
void __cdecl FUN_00d45dd0(const S_00d45dd0_CdBody& bodyA, const S_00d45dd0_CdBody& bodyB, const S_00d45dd0_Input& input,
                          S_00d45dd0_CollectorBase& result)
{
    {
        S_00d45dd0_MonitorStream& mStream = S_00d45dd0_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            S_00d45dd0_TimerBeginListCommand* h = (S_00d45dd0_TimerBeginListCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "LthkpBvAgent";
            h->m_pFirst = "StcheckBvShape";
            _ReadWriteBarrier();
            h->setTime();
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }

    {
        const S_00d45dd0_BvShape* bvShape = (const S_00d45dd0_BvShape*)bodyA.m_pCollisionShape;

        S_00d45dd0_CdBody newBodyA(&bodyA);
        newBodyA.SetCollisionShapeAndKey(bvShape->m_pBvShapeReference, 0xffffffff);

        int typeB = bodyB.m_pCollisionShape->m_type;
        S_00d45dd0_PenFunc f =
            input.m_pCollisionDispatcher->getPenetrationsFunc(newBodyA.m_pCollisionShape->m_type, typeB);
        S_00d45dd0_FlagCollector checker;
        f(newBodyA, bodyB, input, checker);

        if (checker.m_bHit)
        {
            {
                S_00d45dd0_MonitorStream& mStream = S_00d45dd0_MonitorStream::GetMonitorStream();
                if (mStream.memoryAvailable())
                {
                    S_00d45dd0_TimerCommand* h = (S_00d45dd0_TimerCommand*)mStream.m_kRayEnd;
                    h->m_pCommandName = "Stchild";
                    _ReadWriteBarrier();
                    h->setTime();
                    mStream.m_kRayEnd = (char*)(h + 1);
                }
            }
            newBodyA.SetCollisionShapeAndKey(bvShape->m_pContainedShape, 0);
            input.m_pCollisionDispatcher->getPenetrationsFunc(newBodyA.m_pCollisionShape->m_type,
                                                              typeB)(newBodyA, bodyB, input, result);
        }
    }

    {
        S_00d45dd0_MonitorStream& mStream = S_00d45dd0_MonitorStream::GetMonitorStream();
        if (mStream.memoryAvailable())
        {
            S_00d45dd0_TimerCommand* h = (S_00d45dd0_TimerCommand*)mStream.m_kRayEnd;
            h->m_pCommandName = "lt";
            _ReadWriteBarrier();
            h->setTime();
            mStream.m_kRayEnd = (char*)(h + 1);
        }
    }
}

struct __declspec(align(16)) Vector228
{
    float x, y, z, w;
};
extern "C" void _ReadWriteBarrier(void);


unsigned __int64 __cdecl __rdtsc(void);

struct BvProfBuf
{
    DWORD unk00;
    char* m_pCur;
    DWORD unk08;
    char* m_pRecordEnd;
};

struct BvRec16
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
    const char* m_pName2;
};

struct BvRec12
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct BvA;
struct BvX;
struct BvRes
{
    const BvX* m_00;
    DWORD m_04;
    const void* m_08;
    BvA* m_parent;
};

struct Contact228
{
    Vector228 normal;
    union
    {
        Vector228 position;
        struct
        {
            float px, py, pz, distance;
        };
    };
};
class hkpCdPointCollector
{
  public:
    virtual ~hkpCdPointCollector()
    {}
    virtual void addContactPoint(const Contact228& point) = 0;
    virtual void reset();
    float m_fLimit;
};
class hkpSimpleClosestContactCollector : public hkpCdPointCollector
{
  public:
    unsigned char m_bOk;
    Contact228 contact;
    hkpSimpleClosestContactCollector()
    {
        contact.distance = ::DAT_0104da48;
        m_fLimit = ::DAT_0104da48;
        m_bOk = 0;
    }
    virtual ~hkpSimpleClosestContactCollector()
    {}
    virtual void addContactPoint(const Contact228& point);
    virtual void reset();
};

struct BvAVtbl
{
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    const BvX* m_10;
    DWORD m_14;
    const BvX* m_18;
};

struct BvA
{
    BvAVtbl* m_vt;
    DWORD unk04;
    const void* m_08;
};

struct BvBVtbl
{
    void* v0;
    void* v1;
    void* v2;
    DWORD m_0c;
};

struct BvB
{
    BvBVtbl* m_vt;
};

struct BvC
{
    hkpCollisionDispatcher* m_vt;
    DWORD unk04;
    DWORD unk08;
    DWORD unk0C;
    DWORD unk10;
    DWORD m_14;
};

struct BvX
{
    DWORD unk00;
    DWORD unk04;
    DWORD unk08;
    DWORD m_0c;
};

class BvHost
{
  public:
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(BvRes* r, void* a2, void* a3, void* a4, void* a5);
};

typedef BvHost*(__cdecl* BvLookupFn)(BvRes*, BvB*, BvC*, void*);

class Agent228
{
  public:
    DWORD unk00;
    DWORD unk04;
    void* m_08;
    BvHost* m_0c;
    BvHost* m_10;

    void CheckBvShape(BvA* a1, BvB* a2, BvC* a3, void* a4, void* a5);
};

// Profiles and runs a Havok BV shape check against a2/a3, caching the result host in m_10 and invoking its v5 callback when a contact is found.
// @fnv 0x00d45660
void Agent228::CheckBvShape(BvA* a1, BvB* a2, BvC* a3, void* a4, void* a5)
{
    volatile DWORD tick;
    BvProfBuf* pBuf = (BvProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        BvRec16* pRec = (BvRec16*)pBuf->m_pCur;
        pRec->m_pName = "LthkpBvAgent";
        pRec->m_pName2 = "StcheckBvShape";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pRec->m_iTick = tick;
        pBuf->m_pCur = reinterpret_cast<char*>(pRec + 1);
    }

    BvAVtbl* shape = a1->m_vt;
    BvRes r;

    r.m_parent = a1;
    r.m_08 = a1->m_08;
    r.m_00 = shape->m_10;
    r.m_04 = 0xffffffff;
    // Aligned raw storage for the explicitly managed collector lifetime.
    struct Storage228
    {
        Vector228 first, second, third;
    } collectorStorage;
    hkpSimpleClosestContactCollector& collector = *new (&collectorStorage) hkpSimpleClosestContactCollector;

    m_0c->v5(&r, a2, a3, &collector, &collector);

    if (collector.m_bOk != 0)
    {
        BvProfBuf* pb = (BvProfBuf*)TlsGetValue(DAT_0126835c);
        if (pb->m_pCur < pb->m_pRecordEnd)
        {
            BvRec12* pr = (BvRec12*)pb->m_pCur;
            pr->m_pName = "Stchild";
            _ReadWriteBarrier();
            tick = (DWORD)__rdtsc();
            pr->m_iTick = tick;
            pb->m_pCur = reinterpret_cast<char*>(pr + 1);
        }

        const BvX* p = shape->m_18;
        r.m_00 = p;
        r.m_04 = 0;
        if (m_10 == 0)
        {
            hkpCollisionDispatcher* vt = a3->m_vt;
            DWORD tbl = a2->m_vt->m_0c;
            DWORD row = p->m_0c;
            const signed char (*base)[32] = vt->m_agent2TypesPred;
            if (a3->m_14 == 0)
                base = vt->m_agent2Types;
            unsigned char k = base[row][tbl];
            BvLookupFn fn = (BvLookupFn)vt->m_agent2Func[k].m_createFunc;
            void* extra = m_08;
            m_10 = fn(&r, a2, a3, extra);
        }

        m_10->v5(&r, a2, a3, a4, a5);
    }

    pBuf = (BvProfBuf*)TlsGetValue(DAT_0126835c);
    if (pBuf->m_pCur < pBuf->m_pRecordEnd)
    {
        BvRec12* pr = (BvRec12*)pBuf->m_pCur;
        pr->m_pName = "lt";
        _ReadWriteBarrier();
        tick = (DWORD)__rdtsc();
        pr->m_iTick = tick;
        pBuf->m_pCur = reinterpret_cast<char*>(pr + 1);
    }
    collector.hkpSimpleClosestContactCollector::~hkpSimpleClosestContactCollector();
}

namespace fnv_00d45f30 {
// FUN_00d45f30 : cdecl 4-arg factory. Gets the global allocator holder,
// allocates a 0x14 byte block through the allocator's virtual Alloc slot,
// stamps a 16-bit size at +4, runs the out-of-line base constructor with the
// four arguments, stores the derived vtable and returns the block.




// The bounding-volume agent (0x14 bytes on 32-bit); SpawnedObject is its symmetric version.
struct SpawnedBase
{
    virtual void v0();
    unsigned short m_iElementCount;
    short m_sReferenceCount;
    void* m_contactMgr;           // +0x08
    void* m_boundingVolumeAgent;  // +0x0c
    void* m_childAgent;           // +0x10
    SpawnedBase(void* a, void* b, void* c, void* d);
};

struct SpawnedObject : SpawnedBase
{
    SpawnedObject(void* a, void* b, void* c, void* d) : SpawnedBase(a, b, c, d)
    {}
    virtual void v1();
};


// Allocates a SpawnedObject from the heap, records its size, and constructs it in place with the two bodies swapped.
// @fnv 0x00d45f30
void* __cdecl FUN_00d45f30(void* a1, void* a2, void* a3, void* a4)
{
    SpawnedObject* pObj = static_cast<SpawnedObject*>(hkMemoryRouter::getInstance().heap().blockAlloc(sizeof(SpawnedObject)));
    pObj->m_iElementCount = sizeof(SpawnedObject);
    return new (pObj) SpawnedObject(a2, a1, a3, a4);
}
}  // namespace fnv_00d45f30



struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};

struct __declspec(align(16)) Block
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
    Vec4 m_vec;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

struct __declspec(align(16)) Event
{
    const void* vtbl;
    float m_fHitFraction;
    Vec4 m_vec;
    void* m_kCollisionBody;
};

struct Host
{
};

struct Owner
{
    void FUN_00d46340(void* a1, void* a2, const Block* p, void* a4, void* a5);
};

// Copies p with its m_vec XORed by DAT_010c44d0, builds an Event from a4 (and a second from a5 if non-zero), and calls Host::Dispatch(a2, a1, ...).
// @fnv 0x00d46340
void Owner::FUN_00d46340(void* a1, void* a2, const Block* p, void* a4, void* a5)
{
    Event ev;
    ev.m_fHitFraction = ::DAT_0104da48;
    Block blk = *p;
    ev.m_vec = p->m_vec;
    ev.m_kCollisionBody = a4;
    _mm_store_ps((float*)&blk.m_vec, _mm_xor_ps(*(const __m128*)&p->m_vec, DAT_010c44d0));
    ev.vtbl = &(*reinterpret_cast<unsigned int *>(&::UNK_010ce80c));

    Event ctx;
    if (a5 != 0)
    {
        ctx.vtbl = &(*reinterpret_cast<unsigned int *>(&::UNK_010ce80c));
        ctx.m_fHitFraction = ::DAT_0104da48;
        ctx.m_vec = p->m_vec;
        ctx.m_kCollisionBody = a5;
        reinterpret_cast<::Agent228 *>((reinterpret_cast<Host*>(this)))->CheckBvShape(static_cast<::BvA *>(a2), static_cast<::BvB *>(a1), (::BvC *)(::Block *)(&blk), &ev, &ctx);
    }
    else
    {
        reinterpret_cast<::Agent228 *>((reinterpret_cast<Host*>(this)))->CheckBvShape(static_cast<::BvA *>(a2), static_cast<::BvB *>(a1), (::BvC *)(::Block *)(&blk), &ev, nullptr);
    }
}

#include "generated/data/havok/physics/collide/agent/miscagent/bv/hkpbvagent.inc"
