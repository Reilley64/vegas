// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/miscagent/multirayconvex/hkpmultirayconvexagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <windows.h>
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00d37000.h"
#include "fnv/symbols_00d3a000.h"
#include "fnv/symbols_00daf000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010c4000.h"
#include "fnv/symbols_010ce000.h"
#include "fnv/symbols_01268000.h"
struct FUN_00d37690_Class
{
    void ForwardToFunction(intptr_t a, intptr_t b, intptr_t c, intptr_t d);
};
void FUN_00d378a0(int a, int b, int c, int d);
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
struct Payload
{
    const char* name;
    float value;
    int id;
};
void FUN_00d378a0(int aiArg1, int aiArg2, int aiArg3, int aiId);
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
extern "C" D376B0MemoryRouter& __cdecl FUN_00c85750();
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
        D376B0Allocator& alloc = FUN_00c85750().heap();
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

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
#include "fnv/symbols_simd.h"
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
    __m128 _mm_load_ss(const float*);
}


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
