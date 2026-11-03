
// src/havok/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/spherebox/hkpsphereboxagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00d3c590
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/decl/S00d3c910_SphereBoxAgent.h"
#include "fnv/symbols_00d3a000.h"
#include "fnv/symbols_00d3c000.h"
#include "fnv/symbols_00d3d000.h"
#include "fnv/symbols_00daf000.h"
#include "fnv/symbols_0104d000.h"
#include "fnv/symbols_010ce000.h"
void __stdcall ForwardToD3C440(int a, int b, int c, int d)
{
    ::FUN_00d3c440((const ::S_00d3c440_Body *)(a), (const ::S_00d3c440_Body *)(b), c, (::S_00d3c440_Collector *)(d));
}

struct Conversion
{
    void (*convert)();
    void (*create)();
    void (*copy)();
    void (*destroy)();
    bool enabled;
    bool supported;
};
struct Registry
{
};
// Fills a Conversion with function pointers and flags and registers it twice with the registry, once for 4->1 and once for 1->4.
// @fnv 0x00d3cef0
void __cdecl FUN_00d3cef0(Registry* registry)
{
    Conversion conversion;
    conversion.convert = ((void (&)())::FUN_00d3c400);
    conversion.create = ((void (&)())::FUN_00d3cfc0);
    conversion.copy = ((void (&)())::FlipAndDispatchCollector);
    conversion.destroy = ((void (&)())::FUN_00d3ac80);
    conversion.enabled = true;
    conversion.supported = false;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((registry))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::Conversion *)(&conversion), 4, 1);
    conversion.convert = ((void (&)())::CreateD3C380Obj);
    conversion.create = ((void (&)())::FUN_00d3c440);
    conversion.copy = ((void (&)())::FUN_00d3cc00);
    conversion.destroy = ((void (&)())::FUN_00daf8e0);
    conversion.enabled = false;
    conversion.supported = false;
    reinterpret_cast<::FUN_00cfbbe0_cls *>((registry))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)(::Conversion *)(&conversion), 1, 4);
}

struct hkpSymmetricAgentFlipCollector
{
    virtual void unk00();
    float unk04;
    int unk08;
};
// Builds a hkpSymmetricAgentFlipCollector from DAT_0104da48 and arg4, then calls FUN_00d3cc00 with arg2, arg1, arg3 and the collector.
// @fnv 0x00d3d040
void __cdecl FlipAndDispatchCollector(void* arg1, void* arg2, int arg3, int arg4)
{
    hkpSymmetricAgentFlipCollector local;
    local.unk04 = ::DAT_0104da48;
    local.unk08 = arg4;
    ::FUN_00d3cc00((*(const ::hkpCdBody *)(arg2)), (*(const ::hkpCdBody *)(arg1)), (*(const ::CollisionAgentContext *)(arg3)), (*(::hkpCdPointCollector *)(&local)));
}

struct S_00d3c3c0_Holder
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14(unsigned int idx, int arg);
};
struct S_00d3c3c0_Obj
{
    virtual void v00(int flag);
    int unk04;
    S_00d3c3c0_Holder* unk08;
    unsigned short unk0c;
    void FUN_00d3c3c0(int arg);
};
// If unk0c is not 0xffff, calls v14 on unk08 with unk0c and arg, then calls v00 with 1.
// @fnv 0x00d3c3c0
void S_00d3c3c0_Obj::FUN_00d3c3c0(int arg)
{
    int idx = unk0c;
    if ((unsigned short)idx != 0xffff)
        unk08->v14(idx, arg);
    v00(1);
}

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct ObjAllocator
{
    virtual void unk00();
    virtual void* Alloc(unsigned int size);
};

struct SmallRecord
{
    void* m_vptr;
    unsigned short m_w04;
    unsigned short m_w06;
    int m_i08;
    unsigned short m_w0C;
};

extern char DAT_010cf018[];

AllocHolder* FUN_00c85750();

// @fnv 0x00d3c400
void __cdecl FUN_00d3c400(int aiUnused1, int aiUnused2, int aiUnused3, int d)
{
    AllocHolder* pAllocHolder = FUN_00c85750();
    ObjAllocator* allocator = (ObjAllocator*)pAllocHolder->m_pAllocator;
    SmallRecord* pRecord = (SmallRecord*)allocator->Alloc(0x10);
    pRecord->m_w04 = 0x10;
    pRecord->m_w06 = 1;
    pRecord->m_i08 = d;
    pRecord->m_w0C = 0xffff;
    pRecord->m_vptr = DAT_010cf018;
}

class D3CF80CollectorBase
{
  public:
    D3CF80CollectorBase() : m_bHit(false)
    {}
    virtual void AddCdPoint(const void* pkEvent) = 0;

    bool m_bHit;
};

class D3CF80Collector : public D3CF80CollectorBase
{
  public:
    D3CF80Collector(int iFilter) : m_iFilter(iFilter)
    {}
    virtual void AddCdPoint(const void* pkEvent);

    int m_iFilter;
};

class D3CF80Agent
{
  public:
    void CollectFilteredEvents(void* pkA, void* pkB, void* pkInput, int iFilter);
};

// @fnv 0x00d3cf80
void D3CF80Agent::CollectFilteredEvents(void* pkA, void* pkB, void* pkInput, int iFilter)
{
    D3CF80Collector kCollector(iFilter);
    ::ForwardToD3C440((int)this, (int)(pkB), (int)(pkA), (int)(pkInput));
}


struct FlipCollectorLocal
{
    void* unk00;
    unsigned char unk04;
    int unk08;
};

// Builds a FlipCollectorLocal from DAT_010ce81c and a4, then calls FUN_00d3c440 with a2, a1, a3 and the local's address.
// @fnv 0x00d3cfc0
void __cdecl FUN_00d3cfc0(int aiArg1, int aiArg2, int aiArg3, int a4)
{
    FlipCollectorLocal local;
    local.unk08 = a4;
    local.unk04 = 0;
    local.unk00 = (*reinterpret_cast<char (*)[]>(&::DAT_010ce81c));
    ::FUN_00d3c440((const ::S_00d3c440_Body *)(aiArg2), (const ::S_00d3c440_Body *)(aiArg1), aiArg3, (::S_00d3c440_Collector *)((int)&local));
}

struct CpuCallData
{
    void* descriptor;
    float bound;
    unsigned int value;
};
struct CpuObject
{
    void FUN_00d3d000(void*, void*, unsigned int, unsigned int);
};
// Builds a CpuCallData from fourth, DAT_0104da48 and DAT_010ce7fc, then forwards second, first, third and the data to FUN_00d3c910.
// @fnv 0x00d3d000
void CpuObject::FUN_00d3d000(void* first, void* second, unsigned int third, unsigned int fourth)
{
    CpuCallData callData;
    callData.value = fourth;
    callData.bound = ::DAT_0104da48;
    callData.descriptor = &DAT_010ce7fc;
    reinterpret_cast<::S00d3c910_SphereBoxAgent *>(this)->FUN_00d3c910((*(const ::S00d3c910_CdBody *)(second)), (*(const ::S00d3c910_CdBody *)(first)), (*(const ::S00d3c910_CollisionInput *)(third)), (*(::S00d3c910_CdPointCollector *)(&callData)));
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
#include "fnv/symbols_simd.h"
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
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
    void FUN_00d3c5b0(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void FUN_00d3d080(int a, int b, int c, Simplex* s);
};

// @fnv 0x00d3d080
void Agent::FUN_00d3d080(int a, int b, int c, Simplex* s)
{
    SimplexVertex* v = s->m_kRayEnd;
    float oldDistance = s->m_fClosestPointDistanceSquared;
    AgentBase::FUN_00d3c5b0(b, a, c, s);
    for (; v < s->m_kRayEnd; v++)
    {
        const __m128* pb = &v->m_kPointB;
        __m128 w = _mm_shuffle_ps(*pb, *pb, 0xff);
        v->m_kPointA = _mm_add_ps(_mm_mul_ps(w, v->m_kPointB), v->m_kPointA);
        v->m_kPointB = _mm_xor_ps(v->m_kPointB, DAT_010c4c00);
    }
    if (oldDistance != s->m_fClosestPointDistanceSquared)
    {
        __m128* n = &s->m_vHitNormal;
        *n = _mm_xor_ps(*n, DAT_010c4c00);
        {
            unsigned char t = s->m_dims.m_ucLowNibble;
            s->m_dims.m_ucLowNibble = s->m_dims.m_ucHighNibble;
            s->m_dims.m_ucHighNibble = t;
        }
        {
            unsigned char t = s->m_ucDimensionA;
            s->m_ucDimensionA = s->m_ucDimensionB;
            s->m_ucDimensionB = t;
        }
        int last = s->m_ucDimensionA + s->m_ucDimensionB - 1;
        unsigned short t0 = s->m_ids[0];
        s->m_ids[0] = s->m_ids[last];
        s->m_ids[last] = t0;
        if ((s->m_ucDimensionA & s->m_ucDimensionB) == 2)
        {
            unsigned short t1 = s->m_ids[1];
            s->m_ids[1] = s->m_ids[2];
            s->m_ids[2] = t1;
        }
    }
}
