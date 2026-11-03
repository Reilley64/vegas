
// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/symbols_00c85000.h"
#include <new>
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d37000.h"
#include "fnv/symbols_00d3a000.h"
#include "fnv/symbols_00daf000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010ce000.h"
struct FUN_00d37690_Class
{
    void ForwardToFunction(void* a, void* b, const void* c, void* d);
};

// @fnv 0x00d37690
void FUN_00d37690_Class::ForwardToFunction(void* aiArg1, void* aiArg2, const void* aiArg3, void* aiArg4)
{
    ::FUN_00d374f0((*(const ::S_00d374f0_CdBody *)(aiArg1)), (*(const ::S_00d374f0_CdBody *)(aiArg2)), aiArg3, (::S_00d374f0_Collector *)(aiArg4));
}

void FUN_00d378a0(void* a, void* b, void* c, void* d);

struct FUN_00cfbbe0_Arg
{
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    char f4;
    char f5;
};

struct FUN_00cfbbe0_Class
{
};

// Builds two FUN_00cfbbe0_Arg descriptors from function pointers and flags and passes each to FUN_00cfbbe0 with size arguments 0x12/0x18 and 0x18/0x12.
// @fnv 0x00d377d0
void FUN_00d377d0(void* pClass)
{
    FUN_00cfbbe0_Class* p = (FUN_00cfbbe0_Class*)pClass;
    FUN_00cfbbe0_Arg arg;
    arg.f0 = (void*)&((void (&)(int, int, int, int))::fnv_00d37780::FUN_00d37780_impl);
    arg.f1 = (void*)&((void (&)(int, int, int, int))::FUN_00d37860);
    arg.f2 = (void*)&FUN_00d378a0;
    arg.f3 = (void*)&((void (&)())::FUN_00d3ac80);
    arg.f4 = 1;
    arg.f5 = 1;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((p))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::FUN_00cfbbe0_Arg *)(&arg), 0x12, 0x18);
    arg.f0 = (void*)&::fnv_00d37740::FUN_00d37740;
    arg.f1 = (void*)&((void (&)(int, int, int, int))::FUN_00d374f0);
    arg.f2 = (void*)&((void (&)(int, int, int, int))::FUN_00d37280);
    arg.f3 = (void*)&((void (&)())::FUN_00daf8e0);
    arg.f4 = 0;
    arg.f5 = 1;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((p))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::FUN_00cfbbe0_Arg *)(&arg), 0x18, 0x12);
}

struct Handler
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void process(unsigned short index, int argument);
};
struct Owner
{
    virtual ~Owner();
    int unk04;
    Handler* handler;
    unsigned short* values;
    int count;
    void ProcessValuesAndDelete(int argument);
};
// Calls handler->process for each non-0xffff value in values, then deletes this.
// @fnv 0x00d36fc0
void Owner::ProcessValuesAndDelete(int argument)
{
    int length = count;
    for (int i = 0; i < length; ++i)
    {
        unsigned short index = values[i];
        if (index != 0xffff)
            handler->process(index, argument);
    }
    delete this;
}

struct S_00d37860_Base
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    bool m_bHit;
    S_00d37860_Base() : m_bHit(false)
    {}
};

struct S_00d37860_Collector : S_00d37860_Base
{
    int m_iFilter;
    S_00d37860_Collector(int filter) : m_iFilter(filter)
    {}
    virtual void f1();
};


// Builds a collector from filter and runs FUN_00d374f0 with b, a, c and the collector.
// @fnv 0x00d37860
void FUN_00d37860(void* a, void* b, void* c, int filter)
{
    S_00d37860_Collector collector(filter);
    ::FUN_00d374f0((*(const ::S_00d374f0_CdBody *)(b)), (*(const ::S_00d374f0_CdBody *)(a)), c, (::S_00d374f0_Collector *)(::S_00d37860_Collector *)(&collector));
}

struct Payload
{
    const char* name;
    float value;
    void* id;
};
// Builds a Payload from DAT_010ce7fc, DAT_0104da48 and d, then passes it with b, a and c to FUN_00d37280.
// @fnv 0x00d378a0
void FUN_00d378a0(void* aiArg1, void* aiArg2, void* aiArg3, void* aiId)
{
    Payload p;
    p.name = (*reinterpret_cast<const char (*)[]>(&::DAT_010ce7fc));
    p.value = ::DAT_0104da48;
    p.id = aiId;
    ::FUN_00d37280((*(const ::hkpCdBody *)(aiArg2)), (*(const ::hkpCdBody *)(aiArg1)), (*(const ::CollisionAgentContext *)(aiArg3)), (*(::hkpCdPointCollector *)(&p)));
}

struct D376B0Allocator;

struct D376B0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D376B0Allocator* m_pStreamAllocator;

    D376B0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};


class D376B0ReferencedObject
{
  public:
    D376B0ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

// hkInplaceArray<hkUint16, 4> without a destructor (Havok was built without EH).
struct D376B0IndexArray
{
    unsigned short* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned short m_kStorage[4];

    D376B0IndexArray() : m_data(m_kStorage), m_iElementCount(0), m_iCapacityState(0x80000004)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void SetSizeAndGrow(int n)
    {
        D376B0Allocator& alloc = static_cast<D376B0MemoryRouter*>(::FUN_00c85750())->heap();
        const int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            ::FUN_00c908c0((::SpawnedObject *)(::D376B0Allocator *)(&alloc), (::SpawnedArray *)(void *)(this), newSize, sizeof(unsigned short));
        }
        m_iElementCount = n;
    }
};

struct D376B0Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_numChildren;
};

struct D376B0ShapeRef
{
    D376B0Shape* m_pCollisionShape;
};

class D376B0Filter : public D376B0ReferencedObject
{
  public:
    D376B0Filter(void* userData) : m_ulUserData(userData)
    {}

    void* m_ulUserData;
};

class FUN_00d376b0 : public D376B0Filter
{
  public:
    FUN_00d376b0(const D376B0ShapeRef& shape, void* ReportDiagnostic, void* unused1, void* userData);
    virtual void unk00();

    D376B0IndexArray m_ppIndices;
};

// Constructs a filter from a shape reference, sizing an index array to the shape's child count and filling it with 0xffff.
// @fnv 0x00d376b0
FUN_00d376b0::FUN_00d376b0(const D376B0ShapeRef& shape, void* pUnused, void* unused1, void* userData)
    : D376B0Filter(userData)
{
    int n = shape.m_pCollisionShape->m_numChildren;
    m_ppIndices.SetSizeAndGrow(n);
    for (int i = 0; i < n; i++)
        m_ppIndices.m_data[i] = 0xffff;
}

namespace fnv_00d37740 {
struct S_00d376b0_Class
{
    int unk00;
    short unk04;
    void FUN_00d376b0(int a, int b, int c, int d);
};

struct S_00d37740_Interface
{
    virtual void FUN_00d37740_Unknown() = 0;
    virtual S_00d376b0_Class* FUN_00d37740_Method(int a) = 0;
};

struct S_00d37740_Object
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d37740_Interface* unk10;
};


// @fnv 0x00d37740
void FUN_00d37740(void* aiArg1, void* aiArg2, void* aiArg3, void* aiArg4)
{
    S_00d37740_Object* obj = static_cast<S_00d37740_Object*>(::FUN_00c85750());
    S_00d376b0_Class* result = obj->unk10->FUN_00d37740_Method(0x20);

    result->unk04 = 0x20;
    new ((void *)(result)) ::FUN_00d376b0((*(const ::D376B0ShapeRef *)(aiArg1)), (void *)(aiArg2), (void *)(aiArg3), (void *)(aiArg4));
}
}  // namespace fnv_00d37740

namespace fnv_00d37780 {
// FUN_00d37780 - the original returns the freshly allocated object in EAX
// (`mov eax, esi` right before the epilogue), but the unit declares it as
// `void FUN_00d37780(int,int,int,int)`, so the definition carries the real
// return type under a name that still contains the canary tag.
struct Allocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int size);
    virtual void Free(void* p);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Allocator* m_pAllocator;
};


struct SpawnedObject
{
    virtual ~SpawnedObject()
    {}
    unsigned short m_iElementCount;
};

struct FUN_00d376b0_cls
{
    int unk00;
    void FUN_00d376b0(int a, int b, int c, int d);
};

// @fnv 0x00d37780
void* FUN_00d37780_impl(void* aiArg1, void* aiArg2, void* aiArg3, void* aiArg4)
{
    AllocHolder* pAllocHolder = static_cast<AllocHolder*>(::FUN_00c85750());
    Allocator* alloc = pAllocHolder->m_pAllocator;
    SpawnedObject* obj = (SpawnedObject*)alloc->Alloc(0x20);
    obj->m_iElementCount = 0x20;
    new ((void *)(((FUN_00d376b0_cls*)obj))) ::FUN_00d376b0((*(const ::D376B0ShapeRef *)(aiArg2)), (void *)(aiArg1), (void *)(aiArg3), (void *)(aiArg4));
    // the original writes the derived vtable pointer into the object here
    obj->SpawnedObject::~SpawnedObject();
    return obj;
}
}  // namespace fnv_00d37780

// Moved from hkpmultirayconvexagent_gs_ehsc_nogs_noehsc_variant.cpp (VEGAS-15).

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <intrin.h>
#include <windows.h>
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_01268000.h"

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
#include <xmmintrin.h>
#include "fnv/symbols_simd.h"

struct S_00d374f0_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d374f0_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d374f0_Timer(const char* name) {
    S_00d374f0_MonitorStream* s = (S_00d374f0_MonitorStream*)TlsGetValue(::DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand) {
        S_00d374f0_TimerCommand* h = (S_00d374f0_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = *(volatile unsigned int*)&t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

// hkVector4 stand-in: 4 floats (an __m128 member would add a GS cookie)
struct __declspec(align(16)) S_00d374f0_Vector4 {
    float x, y, z, w;
    __m128& q() { return reinterpret_cast<__m128&>(*this); }
    const __m128& q() const { return reinterpret_cast<const __m128&>(*this); }
};

struct __declspec(align(16)) S_00d374f0_Transform {
    S_00d374f0_Vector4 m_kColumn0;
    S_00d374f0_Vector4 m_kColumn1;
    S_00d374f0_Vector4 m_kColumn2;
    S_00d374f0_Vector4 m_vTranslation;
};

static __forceinline void S_00d374f0_SetTransformedPos(S_00d374f0_Vector4& out, const S_00d374f0_Transform& t, const S_00d374f0_Vector4& b)
{
    const __m128 xb = _mm_shuffle_ps(b.q(), b.q(), 0x00);
    const __m128 yb = _mm_shuffle_ps(b.q(), b.q(), 0x55);
    const __m128 zb = _mm_shuffle_ps(b.q(), b.q(), 0xaa);
    const __m128 t0 = _mm_mul_ps(xb, t.m_kColumn0.q());
    const __m128 t1 = _mm_mul_ps(yb, t.m_kColumn1.q());
    const __m128 t2 = _mm_mul_ps(zb, t.m_kColumn2.q());
    out.q() = _mm_add_ps(_mm_add_ps(t1, t0), _mm_add_ps(t2, t.m_vTranslation.q()));
}

struct S_00d374f0_Bool {
    char m_cBooleanValue;
    S_00d374f0_Bool() {}
    operator bool() const { return m_cBooleanValue != 0; }
};

struct __declspec(align(16)) S_00d374f0_RayInput {
    S_00d374f0_Vector4 m_vFrom;
    S_00d374f0_Vector4 m_vTo;
    unsigned int m_uiFilterInfo;
    const void* m_pRayShapeCollectionFilter;
    S_00d374f0_RayInput() : m_uiFilterInfo(0), m_pRayShapeCollectionFilter(0) {}
};

struct __declspec(align(16)) S_00d374f0_RayOutputBase {
    S_00d374f0_Vector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int unk18;
    int unk1c;
    S_00d374f0_RayOutputBase() { m_fHitFraction = 1.0f; m_iExtraInfo = -1; }
};

struct __declspec(align(16)) S_00d374f0_RayOutput : S_00d374f0_RayOutputBase {
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    S_00d374f0_RayOutput() { m_uiShapeKeyIndex = 0; m_uiShapeKeys[0] = 0xffffffff; }
};

struct S_00d374f0_ConvexShape {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual S_00d374f0_Bool RayCast(const S_00d374f0_RayInput& input, S_00d374f0_RayOutput& output) const;
};

struct S_00d374f0_Ray {
    S_00d374f0_Vector4 m_kRayStart;
    S_00d374f0_Vector4 m_kRayEnd;
};

struct S_00d374f0_MultiRayShape {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d374f0_Ray* m_data;
    int m_iElementCount;
    int m_pRayCursor;
};

struct S_00d374f0_CdBody {
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00d374f0_Transform* m_pMotionState;
    const S_00d374f0_CdBody* m_parent;
};

struct S_00d374f0_Collector {
    virtual ~S_00d374f0_Collector();
    virtual void AddCdBodyPair(const S_00d374f0_CdBody& a, const S_00d374f0_CdBody& b);
    S_00d374f0_Bool m_fHitDistance;
};

// @fnv 0x00d374f0
void FUN_00d374f0(const S_00d374f0_CdBody& bodyA, const S_00d374f0_CdBody& bodyB, const void* input, S_00d374f0_Collector* collector)
{
    S_00d374f0_Timer("TtmultiRay-cnvx-getPen");
    const S_00d374f0_MultiRayShape* msA = (const S_00d374f0_MultiRayShape*)bodyA.m_pCollisionShape;
    const S_00d374f0_ConvexShape* convexB = (const S_00d374f0_ConvexShape*)bodyB.m_pCollisionShape;

    S_00d374f0_Collector* col = collector;
    S_00d374f0_Transform bTa;
    reinterpret_cast<::hkTransformCB22 *>(&(bTa))->FUN_00cb22f0((const ::hkTransformCB22 &)(*bodyB.m_pMotionState), (const ::hkTransformCB22 &)(*bodyA.m_pMotionState));

    int nRays = msA->m_iElementCount;
    const S_00d374f0_Ray* rayA = msA->m_data;
    S_00d374f0_RayInput rayInput;
    S_00d374f0_RayOutput rayResults;
    while (nRays-- && !col->m_fHitDistance)
    {
        S_00d374f0_SetTransformedPos(rayInput.m_vFrom, bTa, rayA->m_kRayStart);
        S_00d374f0_SetTransformedPos(rayInput.m_vTo, bTa, rayA->m_kRayEnd);
        S_00d374f0_Bool hit = convexB->RayCast(rayInput, rayResults);
        if (hit.m_cBooleanValue)
        {
            col->AddCdBodyPair(bodyA, bodyB);
        }
        rayA++;
    }
    S_00d374f0_Timer("Et");
}
struct Event378 { const char* tag; unsigned time; unsigned other; };
struct Timer378 { int unused; Event378* current; int unknown; Event378* end; };
inline void timer378(const char* tag) {
    Timer378* timer = (Timer378*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));
    if (timer->current < timer->end) {
        Event378* e = timer->current;
        e->tag = tag;
        unsigned time;
        time = static_cast<unsigned int>(__rdtsc());
        e->time = time;
        timer->current = e + 1;
    }
}
struct V378 { union { __m128 v; struct { float x,y,z,w; }; }; };
struct Transform378 {
    __m128 x,y,z,t;
};
struct Segment378 { V378 from,to; };
struct Ray378 { V378 from,to; unsigned filter; unsigned userData; };
struct OutputBase378 { V378 normal; float fraction; int m_uiExtraInfo; };
struct Output378 : OutputBase378 { unsigned shapeKeys[8]; int keyIndex; };
struct Bool378 { char value; };
struct Shape378 {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual Bool378 RayCast(const Ray378&, Output378&) const;
    int field04,field08,field0c;
    Segment378* rays;
    int count;
    int field18;
    float radius;
};
struct Body378 { Shape378* shape; int other; Transform378* transform; };
struct Contact378 {
    V378 position;
    V378 normal;
    unsigned index;
    unsigned material;
    unsigned userData;
    unsigned other;
    void FUN_00c7f640(void*, void*);
};
struct Normal378 { __m128 v; void FUN_00c7f700(void*, void*); };
struct ContactBuffer378 { Contact378* current; int context; };
struct ContactManager378 {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual unsigned short add(Body378*, Body378*, void*, ContactBuffer378*, int, Contact378*);
    virtual void slot4();
    virtual void remove(unsigned short, int);
};
struct Agent378 {
    virtual void slot0();
    int unknown;
    ContactManager378* manager;
    unsigned short* indices;
    void FUN_00d378e0(Body378*, Body378*, void*, ContactBuffer378*);
};
inline __m128 transform378(const Transform378& t, __m128 p) {
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p,p,0x55),t.y),_mm_mul_ps(_mm_shuffle_ps(p,p,0),t.x)),
                      _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(p,p,0xaa),t.z),t.t));
}
struct Scratch378 { Ray378 ray; Transform378 relative; V378 position; };
// @fnv 0x00d378e0
void Agent378::FUN_00d378e0(Body378* a, Body378* b, void* input, ContactBuffer378* buffer) {
    timer378(DAT_010ceda8);
    struct { int count; Shape378* target; Shape378* source; } shapes;
    shapes.source = a->shape;
    shapes.target = b->shape;
    Scratch378 scratch;
    reinterpret_cast<::hkTransformCB22 *>(&(scratch.relative))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(b->transform)),(*(const ::hkTransformCB22 *)(a->transform)));
    shapes.count = shapes.source->count;
    scratch.ray.filter = 0;
    scratch.ray.userData = 0;
    Segment378* current = shapes.source->rays;
    for (int i=0; i<shapes.count; ++current, ++i) {
        Output378 hit;
        scratch.ray.from.v = transform378(scratch.relative,current->from.v);
        scratch.ray.to.v = transform378(scratch.relative,current->to.v);
        hit.fraction = 1.0f;
        hit.m_uiExtraInfo = -1;
        hit.shapeKeys[0] = -1;
        hit.keyIndex = 0;
        Bool378 DidHit = shapes.target->RayCast(scratch.ray,hit);
        if (!DidHit.value) {
            unsigned short id = indices[i];
            if (id != 0xffff) {
                manager->remove(id,buffer->context);
                indices[i] = 0xffff;
            }
        } else {
            Contact378* contact = buffer->current;
            __m128 fraction = _mm_set1_ps(hit.fraction);
            scratch.position.v = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0,fraction),scratch.ray.from.v),_mm_mul_ps(fraction,scratch.ray.to.v));
            contact->FUN_00c7f640(b->transform,&scratch.position);
            ((Normal378*)&contact->normal)->FUN_00c7f700(b->transform,&hit.normal);
            contact->normal.w = (hit.fraction-1.0)*current->from.w+shapes.source->radius;
            if (indices[i] == 0xffff) {
                unsigned short iContactPointId = manager->add(a,b,input,buffer,0,contact); indices[i] = iContactPointId;
            }
            if (indices[i] != 0xffff) {
                ++buffer->current;
                contact->index = indices[i];
            }
        }
    }
    timer378(DAT_010c41f8);
}

// Moved from hkpmultirayconvexagent_rtm_variant.cpp (VEGAS-15).
void FUN_00d378a0(void* aiArg1, void* aiArg2, void* aiArg3, void* aiId);


extern "C" unsigned __int64 __rdtsc();

extern "C" void _ReadWriteBarrier();





struct MonitorEvent
{
    const char* name;
    unsigned time;
    unsigned extra;
};

struct MonitorStream
{
    int unk00;
    MonitorEvent* current;
    int unk08;
    MonitorEvent* end;
};

static void timer(const char* name, volatile unsigned& ticks)
{

    MonitorStream* stream = (MonitorStream*)TlsGetValue((*reinterpret_cast<unsigned int *>(&::DAT_0126835c)));

    MonitorEvent* event = stream->current;

    if (event < stream->end)
    {

        event->name = name;

        _ReadWriteBarrier();

        ticks = (unsigned)__rdtsc();

        event->time = ticks;

        stream->current = event + 1;
    }
}

union RayVector
{
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
};

struct RayTransform
{

    __m128 col0, col1, col2, translation;


    __m128 point(__m128 v) const
    {

        return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), col1),

                                     _mm_mul_ps(_mm_shuffle_ps(v, v, 0), col0)),

                          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), col2), translation));
    }

    __m128 direction(__m128 v) const
    {

        return _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v, v, 0x55), col1),

                                     _mm_mul_ps(_mm_shuffle_ps(v, v, 0), col0)),

                          _mm_mul_ps(_mm_shuffle_ps(v, v, 0xaa), col2));
    }
};

struct Ray
{
    RayVector from, to;
};

struct ShapeRayInput
{
    __m128 from, to;
    unsigned filter;
    int collection;
};

struct ShapeRayOutput
{

    __m128 normal;

    float fraction;

    int m_uiExtraInfo;

    int unk18;

    int unk1c;

    unsigned shapeKeys[8];

    int level;

    ShapeRayOutput()
    {
        fraction = 1.0f;
        m_uiExtraInfo = -1;
        shapeKeys[0] = -1;
        level = 0;
    }
    void reset()
    {
        fraction = 1.0f;
        m_uiExtraInfo = -1;
        shapeKeys[0] = -1;
        level = 0;
    }
};

struct __declspec(align(2)) RayBool
{
    unsigned char unk0;
    unsigned char value;
};

struct RayShape
{

    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();

    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();

    virtual void RayCast(unsigned char* result, const ShapeRayInput&, ShapeRayOutput&) const;

    int unk04;
    int unk08;
    int unk0c;

    Ray* rays;
    int count;
    int capacity;
    float radius;
};

struct RayBody
{
    RayShape* shape;
    unsigned key;
    RayTransform* transform;
    RayBody* parent;
};

struct RayHit
{
    __m128 position;
    RayVector normal;
    const RayBody* bodyA;
    const RayBody* bodyB;
};

struct RayCollector
{
    virtual void slot0();
    virtual void AddHit(const RayHit&);
};

struct RayLocals
{
    RayHit hit;
    RayTransform relative;
};

// @fnv 0x00d37010
void FUN_00d37010(const RayBody* a, const RayBody* b, void* unused, RayCollector* collector)
{

    union
    {
        volatile unsigned ticks;
        int remaining;
    } counter;

    timer(DAT_010ceda8, counter.ticks);

    RayShape* shape = a->shape;

    RayShape* target = b->shape;

    RayLocals L;
    ShapeRayInput input;

    reinterpret_cast<::hkTransformCB22 *>(&(L.relative))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(b->transform)), (*(const ::hkTransformCB22 *)(a->transform)));

    int count = shape->count;

    Ray* ray = shape->rays;

    L.hit.bodyB = b;

    L.hit.bodyA = a;

    input.filter = 0;

    input.collection = 0;

    if (count > 0)
        for (counter.remaining = count; counter.remaining; --counter.remaining)
        {

            ShapeRayOutput output;
            __m128 from = ray->from.v;

            input.from = L.relative.point(from);

            __m128 to = ray->to.v;

            input.to = L.relative.point(to);

            RayBool success;
            target->RayCast(&success.value, input, output);

            if (success.value)
            {

                float fraction = output.fraction;

                __m128 t = _mm_load_ss(&fraction);
                t = _mm_shuffle_ps(t, t, 0);

                __m128 p = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, t), input.from), _mm_mul_ps(t, input.to));

                const RayTransform* world = b->transform;

                L.hit.position = world->point(p);

                L.hit.normal.v = world->direction(output.normal);

                L.hit.normal.w = (fraction - 1.0) * ray->from.w + shape->radius;

                collector->AddHit(L.hit);
            }

            ++ray;
        }

    timer(DAT_010c41f8, counter.ticks);
}

// Moved from hkpmultirayconvexagent_gs_nogs_variant_rtm_variant.cpp (VEGAS-15).
// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <cstddef>
#include "fnv/decl/FUN_005609f0_shell.h"


typedef float hkReal;
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
__forceinline ValueWrapper(TYPE e)
:m_kStorage(e)
{
}
__forceinline TYPE val()const
{
return m_kStorage;
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
class hkMemoryAllocator
{
public:
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};
struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;};
class NineIntegerRecord
{
public:
typedef hkMemoryAllocator Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;};
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
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
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
template<bool N>struct BooleanTypeConstant{typedef BooleanTypeConstant<N>type;enum{result=N};};
typedef BooleanTypeConstant<true>hkTypeIsPod;
struct RouterHeapAllocatorProvider
{
hkMemoryAllocator&get(const void*){return NineIntegerRecord::GetMonitorStream().heap();}
};
template<typename T>
class HavokElementArray
{
public:
typedef HavokElementArray<T>ThisType;
protected:
__forceinline HavokElementArray(const HavokElementArray&a){;}
public:
__forceinline void _useExternalArray(T*,int cap);
__forceinline int GetLogicalSize()const;
typedef const T*const_iterator;
__forceinline const_iterator begin()const;
protected:
__forceinline HavokElementArray<T>&copyFromArray(hkMemoryAllocator&,const HavokElementArray<T>&src,hkTypeIsPod);
public:
enum
{
CAPACITY_MASK=int(0x3FFFFFFF),
FLAG_MASK=int(0xC0000000),
DONT_DEALLOCATE_FLAG=int(0x80000000),
FORCE_SIGNED=-1
};
protected:
friend class hkStatisticsCollector;
T*m_data;
int m_iElementCount;
int m_iCapacityState;
public:
HavokElementArray(FinishingFlag f){}
};
template<typename T,typename Allocator=RouterHeapAllocatorProvider>
class hkArray:public HavokElementArray<T>
{
public:
typedef Allocator AllocatorType;hkArray(FinishingFlag f):HavokElementArray<T>(f){}
protected:
__forceinline hkArray(const hkArray&a);
public:
__forceinline hkArray&operator=(const HavokElementArray<T>&a);};
template<typename T,unsigned N,typename Allocator=RouterHeapAllocatorProvider>
class hkInplaceArray:public hkArray<T,Allocator>
{
public:
typedef hkInplaceArray<T,N,Allocator>mytype;
public:
T m_kStorage[N];
public:
hkInplaceArray(FinishingFlag f):hkArray<T,Allocator>(f){}
};
template<typename T>
__forceinline int HavokElementArray<T>::GetLogicalSize()const
{
return m_iElementCount;
}
template<typename T>
typename HavokElementArray<T>::const_iterator HavokElementArray<T>::begin()const
{
return m_data;
}

typedef __m128 hkQuadReal;
class hkVector4;
typedef const hkVector4&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
VectorComponentValue(hkReal x)
{
m_vValue=_mm_load_ss(&x);
}
__forceinline hkQuadReal broadcast()const
{
return _mm_shuffle_ps(m_vValue,m_vValue,0);
}
private:
hkQuadReal m_vValue;};
typedef const VectorComponentValue&hkSimdRealParameter;
class hkMatrix3;
class hkRotation;
class hkTransform;
class hkVector4
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void setInterpolate4(const hkVector4&a,const hkVector4&b,hkSimdRealParameter t);
__forceinline void _setMul3(const hkMatrix3&a,const hkVector4&b);
__forceinline void _setRotatedDir(const hkRotation&a,const hkVector4&b);
__forceinline void _setTransformedPos(const hkTransform&a,const hkVector4&b);
__forceinline hkReal&operator()(int i);
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
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline const hkVector4&getColumn(int i)const;
protected:
hkVector4 m_kColumn0;
hkVector4 m_kColumn1;
hkVector4 m_kColumn2;};
class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline const hkVector4&getTranslation()const;
__forceinline const hkRotation&getRotation()const;
private:
hkRotation m_rotation;
hkVector4 m_vTranslation;};
inline void hkVector4::setInterpolate4(const hkVector4&v0,const hkVector4&v1,hkSimdRealParameter _t)
{
extern const hkQuadReal DAT_010ec7f0;
hkQuadReal t=_t.broadcast();
hkQuadReal s=_mm_sub_ps(DAT_010ec7f0,t);
m_vComponents=_mm_add_ps(
_mm_mul_ps(s,v0.m_vComponents),
_mm_mul_ps(t,v1.m_vComponents));}
inline void hkVector4::_setMul3(const hkMatrix3&a,const hkVector4&b)
{
const hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
const hkQuadReal r0=_mm_mul_ps(a.getColumn(0).m_vComponents,b0);
const hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
const hkQuadReal r1=_mm_mul_ps(a.getColumn(1).m_vComponents,b1);
const hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
const hkQuadReal r2=_mm_mul_ps(a.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),r2);}
inline void hkVector4::_setRotatedDir(const hkRotation&r,const hkVector4&v)
{
_setMul3(r,v);
}
inline void hkVector4::_setTransformedPos(const hkTransform&t,const hkVector4&b)
{
const hkRotation&r=t.getRotation();
hkQuadReal b0=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((0)<<6)|((0)<<4)|((0)<<2)|((0))));
hkQuadReal r0=_mm_mul_ps(r.getColumn(0).m_vComponents,b0);
hkQuadReal b1=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((1)<<6)|((1)<<4)|((1)<<2)|((1))));
hkQuadReal r1=_mm_mul_ps(r.getColumn(1).m_vComponents,b1);
hkQuadReal b2=_mm_shuffle_ps(b.m_vComponents,b.m_vComponents,(((2)<<6)|((2)<<4)|((2)<<2)|((2))));
hkQuadReal r2=_mm_mul_ps(r.getColumn(2).m_vComponents,b2);
m_vComponents=_mm_add_ps(_mm_add_ps(r0,r1),_mm_add_ps(r2,t.getTranslation().m_vComponents));}
inline hkReal&hkVector4::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal&hkVector4::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
inline const hkVector4&hkMatrix3::getColumn(int x)const
{
return(&m_kColumn0)[x];
}
const hkVector4&hkTransform::getTranslation()const
{
return m_vTranslation;
}
const hkRotation&hkTransform::getRotation()const
{
return m_rotation;
}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
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
hkBool m_bFlag;
public:
struct Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
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
typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkVector4&getPosition();
inline hkVector4&getSeparatingNormal();
inline void setDistance(hkReal d);
protected:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4 m_vContactPosition;
hkVector4 m_vSeparatingNormal;};
inline hkVector4&hkContactPoint::getPosition()
{
return m_vContactPosition;
}
inline hkVector4&hkContactPoint::getSeparatingNormal()
{
return m_vSeparatingNormal;
}
inline void hkContactPoint::setDistance(hkReal d)
{
m_vSeparatingNormal(3)=d;
}
class Vector4WithInt24W:public hkVector4
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
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
class hkAabb;
struct ShapeRayCastQuery;
struct ShapeRayCastOutput;
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
virtual hkReal getMaximumProjection(const hkVector4&direction)const;
__forceinline hkBool RayCast(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const;
virtual const hkpShapeContainer*GetShapeContainer()const{return 0;}
virtual bool isConvex()const{return false;}
struct PhysicsShape
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpShape::PhysicsShape));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
bool m_bIsConvex;
bool m_bIsConvexPiece;
bool m_bIsComposite;
};
virtual int CalcSizeForSpu(const PhysicsShape&input,int spuBufferSizeLeft)const;
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
virtual hkBool IntersectRayWithShape(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const=0;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<CollisionShapeType,hkUint32>m_type;
public:
hkpShape(class FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};
hkBool hkpShape::RayCast(const ShapeRayCastQuery&input,ShapeRayCastOutput&output)const
{
return IntersectRayWithShape(input,output);
}
struct RayCastHitResult
{
inline RayCastHitResult();
inline void reset();
hkVector4 m_vHitNormal;
hkReal m_fHitFraction;
int m_iExtraInfo;};
void RayCastHitResult::reset()
{
m_fHitFraction=1.0f;
m_iExtraInfo=-1;
}
RayCastHitResult::RayCastHitResult()
{
reset();
}
struct ShapeRayCastOutput:public RayCastHitResult
{
public:
enum{MAX_HIERARCHY_DEPTH=8};
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline ShapeRayCastOutput();
private:
__forceinline void _reset();
public:
hkpShapeKey m_uiShapeKeys[MAX_HIERARCHY_DEPTH];
private:
int m_uiShapeKeyIndex;};
void ShapeRayCastOutput::_reset()
{
m_uiShapeKeyIndex=0;
m_uiShapeKeys[0]=0xffffffff;
}
ShapeRayCastOutput::ShapeRayCastOutput()
{
_reset();
}
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
class hkpCollisionDispatcher;
class hkpConstraintOwner;
struct CollisionAgentContext;
struct GskAgentInput;
struct WorldOperationEntry;
struct ContactPointPair
{
ContactPointPair(const hkpCdBody&a,const hkpCdBody&b):m_pBodyA(a),m_pBodyB(b){}
hkContactPoint m_kPoint;
const hkpCdBody&m_pBodyA;
const hkpCdBody&m_pBodyB;};
class hkpCdPointCollector
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
inline virtual ~hkpCdPointCollector();
virtual void AddCdPoint(const ContactPointPair&point)=0;
protected:
hkReal m_fEarlyOutDistance;};
class hkpCdBodyPairCollector;
class hkpContactMgr;
class hkpCollisionAgent:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
public:
virtual void ProcessAgent(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&result)=0;
protected:
inline virtual ~hkpCollisionAgent();
protected:
hkpContactMgr*m_pContactManager;
public:
inline hkpContactMgr*getContactMgr();};
class hkpIterativeLinearCastAgent:public hkpCollisionAgent
{
public:
__forceinline void*__cdecl operator new(std::size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}};
class hkpMultiRayConvexAgent:public hkpIterativeLinearCastAgent
{
public:
static void __cdecl RegisterCapsuleCapsuleAgent(hkpCollisionDispatcher*dispatcher);
virtual inline void ProcessAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const GskAgentInput&input,WorldOperationEntry&result);
virtual void getPenetrations(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
static void __cdecl m_pVirtualFunction1(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpCdBodyPairCollector&collector);
virtual void getClosestPoints(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector);

virtual void cleanup(hkpConstraintOwner&constraintOwner);
protected:
hkpMultiRayConvexAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createMultiRayConvexAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
static hkpCollisionAgent*__cdecl createConvexMultiRayAgent(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,hkpContactMgr*mgr);
protected:
struct ContactPointIdEntry
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpMultiRayConvexAgent::ContactPointIdEntry));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkContactPointId m_usContactPointId;
};
hkInplaceArray<ContactPointIdEntry,4>m_kContactPointIds;
};
class hkpSphereRepShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
public:
hkpSphereRepShape(CollisionShapeType type):hkpShape(type){}
hkpSphereRepShape(FinishingFlag flag):hkpShape(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
class hkpConvexShape:public hkpSphereRepShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};
class hkpMultiRayShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
struct Ray
{
__forceinline void*__cdecl operator new(std::size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpMultiRayShape::Ray));}}__forceinline void*__cdecl operator new(std::size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](std::size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
static const struct ClassMemberDescriptor Members[];static const hkClass&__cdecl staticClass();struct DefaultStruct;
hkVector4 m_kRayStart;
hkVector4 m_kRayEnd;
};
public:
hkpMultiRayShape(const Ray*rays,int nRays,hkReal rayPenetrationDistance=0.0f);
inline const hkArray<Ray>&getRays()const{return m_kRays;}
inline hkReal getRayPenetrationDistance()const{return m_fRayRadius;}
protected:
hkArray<struct Ray>m_kRays;
hkReal m_fRayRadius;
public:
hkpMultiRayShape(FinishingFlag flag):hkpShape(flag),m_kRays(flag){m_type=HK_SHAPE_MULTI_RAY;}
};
class hkpRayShapeCollectionFilter;
struct ShapeRayCastQuery
{
inline ShapeRayCastQuery();
hkVector4 m_vFrom;
hkVector4 m_vTo;
hkUint32 m_uiFilterInfo;
const hkpRayShapeCollectionFilter*m_pRayShapeCollectionFilter;};
inline ShapeRayCastQuery::ShapeRayCastQuery()
:m_uiFilterInfo(0),
m_pRayShapeCollectionFilter(0)
{
}

// @fnv 0x00d37280
void __cdecl FUN_00d37280(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const CollisionAgentContext&input,class hkpCdPointCollector&collector)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName=::DAT_010ceda8;h->setTime();mStream.setEnd((char*)(h+1));}};
const hkpMultiRayShape*msA=static_cast<const hkpMultiRayShape*>(bodyA.getShape());
const hkpConvexShape*convexB=static_cast<const hkpConvexShape*>(bodyB.getShape());
hkTransform bTa;reinterpret_cast<::hkTransformCB22 *>(&(bTa))->FUN_00cb22f0((const ::hkTransformCB22 &)(bodyB.getTransform()),(const ::hkTransformCB22 &)(bodyA.getTransform()));
const hkArray<hkpMultiRayShape::Ray>&RaysA=msA->getRays();
int nRays=RaysA.GetLogicalSize();
const hkpMultiRayShape::Ray*rayA=RaysA.begin();
ContactPointPair event(bodyA,bodyB);
ShapeRayCastQuery rayInput;
for(int i=0;i<nRays;i++)
{
ShapeRayCastOutput rayResults;
rayInput.m_vFrom._setTransformedPos(bTa,rayA->m_kRayStart);
rayInput.m_vTo._setTransformedPos(bTa,rayA->m_kRayEnd);
hkBool rayHit=convexB->RayCast(rayInput,rayResults);
if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(rayHit))->FUN_005609f0())
{
const hkVector4&normal=rayResults.m_vHitNormal;
const hkReal dist=rayResults.m_fHitFraction;
hkVector4 hitpoint;hitpoint.setInterpolate4(rayInput.m_vFrom,rayInput.m_vTo,dist);
event.m_kPoint.getPosition()._setTransformedPos(bodyB.getTransform(),hitpoint);
event.m_kPoint.getSeparatingNormal()._setRotatedDir(bodyB.getTransform().getRotation(),normal);
event.m_kPoint.setDistance((dist-1.0f)*rayA->m_kRayStart(3)+msA->getRayPenetrationDistance());
collector.AddCdPoint(event);
}
rayA++;
}
{StringCursor&mStream=StringCursor::GetMonitorStream();if(reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::hkBool &)(mStream.memoryAvailable()))->FUN_005609f0()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName=::DAT_010c41f8;h->setTime();mStream.setEnd((char*)(h+1));}};
}
#include "generated/data/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_ehsc_nogs_noehsc_variant.inc"
#include "generated/data/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_gs_nogs_variant_rtm_variant.inc"
