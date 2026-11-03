
// src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"
#include <new>
#include "fnv/decl/FUN_00cfbbe0_cls.h"
#include "fnv/decl/FUN_00dabf10_cls.h"
#include "fnv/decl/hkTransformCB22.h"
#include "fnv/decl/hkpGskBaseAgent_S.h"
#include "fnv/symbols_00dac000.h"
#include "fnv/symbols_00dad000.h"
#include "fnv/symbols_00dae000.h"
#include "fnv/symbols_00daf000.h"
#include "fnv/symbols_00db4000.h"
struct FUN_00dacc70_vt
{
    void (*m_pVirtualFunction0)();
    void (*m_pVirtualFunction1)();
    void (*m_pVirtualFunction2)();
    void (*m_pVirtualFunction3)();
    unsigned char b0;
    unsigned char b1;
};

// Assigns four function pointers to the object's vtable slots and clears its two byte fields.
// @fnv 0x00dacc70
void __cdecl InitVtable(FUN_00dacc70_vt* p)
{
    p->m_pVirtualFunction0 = (void (*)())((void (&)())::FUN_00dacc00);
    p->m_pVirtualFunction1 = (void (*)())((void (&)())::TestGsk);
    p->m_pVirtualFunction2 = (void (*)())((void (&)())::hkpGskBaseAgent_S::FUN_00dac450);
    p->m_pVirtualFunction3 = (void (*)())((void (&)())::FUN_00daf8e0);
    p->b0 = 0;
    p->b1 = 0;
}


struct FUN_00dacaf0_vt
{
    void(* dtor)(void*, int);
};

struct FUN_00dacaf0
{
    FUN_00dacaf0_vt* vt;  // +0x00
    void* field4;         // +0x04
    void* field8;         // +0x08
    char pad[0x24];       // +0x0c..0x2f
    char field30[0x10];   // +0x30
    void cleanup(void* arg);
};

// Calls ReleaseAllEntries with field30, field8 and arg, then invokes the virtual destructor on this with flag 1.
// @fnv 0x00dacaf0
void FUN_00dacaf0::cleanup(void* arg)
{
    ::ReleaseAllEntries((::S_00dad640_Set *)(void *)(&field30[0]), (::S_00dad640_Target *)(field8), arg);
    vt->dtor(this, 1);
}


struct hkpGskfAgent
{
    struct ContactPoint
    {
        unsigned short m_unk0;
        unsigned short m_id;
        unsigned int m_unk4;
    };
    // The manifold that FUN_00dae340 and ReleaseAllEntries take as an S_00dad640_Set.
    struct Manifold
    {
        unsigned char m_unk0;
        unsigned char m_unk1;
        unsigned char m_numContactPoints;
        unsigned char m_unk3;
        ContactPoint m_contactPoints[1];
    };

    unsigned char m_pad00[0x30];
    Manifold m_manifold;  // +0x30

    void FUN_00dacb20(unsigned short id);
};

// Looks for the contact point with a matching id and, if found, calls FUN_00dae340 with the manifold and its index.
// @fnv 0x00dacb20
void hkpGskfAgent::FUN_00dacb20(unsigned short id)
{
    int count = m_manifold.m_numContactPoints;
    for (int i = 0; i < count; ++i)
    {
        if (m_manifold.m_contactPoints[i].m_id == id)
        {
            ::FUN_00dae340((::S_00dad640_Set *)(void *)&m_manifold, i);
            return;
        }
    }
}

struct FUN_00dacb60_class
{
    unsigned char m_pad00[0x32];
    unsigned char m_uiItemCount;
    unsigned char m_pad01[3];

    struct Potential
    {
        unsigned short m_uiFilterValue;
        unsigned char m_auiShapeKeys[6];
    };

    Potential m_potentials[256];

    void AddPotential(unsigned short value);
};

// @fnv 0x00dacb60
void FUN_00dacb60_class::AddPotential(unsigned short value)
{
    int count = m_uiItemCount;
    int i;

    for (i = 0; i < count; ++i)
    {
        if (m_potentials[i].m_uiFilterValue == 0xffff)
        {
            m_potentials[i].m_uiFilterValue = value;
            return;
        }
    }
}

extern int DAT_010d5224;

struct GskNode;

struct FUN_00dabf10
{
    void* m_pVtbl;
    char m_b0[44];
    int m_i0;
    FUN_00dabf10(GskNode*, GskNode*, void*);
    ~FUN_00dabf10();
};

struct FUN_00dacbd0 : FUN_00dabf10
{
    FUN_00dacbd0(GskNode* a, GskNode* b, void* c);
    ~FUN_00dacbd0();
};

// Initializes the derived object: sets its vtable pointer to DAT_010d5224 and clears m_i0 after the base constructor runs.
// @fnv 0x00dacbd0
FUN_00dacbd0::FUN_00dacbd0(GskNode* a, GskNode* b, void* c) : FUN_00dabf10(a, b, c)
{
    m_pVtbl = &DAT_010d5224;
    m_i0 = 0;
}

struct hkSlotDACB
{
    unsigned char m_00;
    unsigned char m_01;
    short m_iOwnerObjectOffset;
    int m_04;
};

class hkObjDACB
{
  public:
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C;
    short unk30;
    unsigned char m_numSlots;
    unsigned char unk33;
    hkSlotDACB m_slots[8];

    void ClearSlotById(short id);
};

// @fnv 0x00dacba0
void hkObjDACB::ClearSlotById(short id)
{
    for (int i = 0; i < m_numSlots; i++)
    {
        hkSlotDACB& kSlot = m_slots[i];
        if (kSlot.m_iOwnerObjectOffset == id)
        {
            kSlot.m_00 = 0;
            kSlot.m_01 = 0;
            return;
        }
    }
}

struct Dvec4
{
    float x, y, z, w;
};

struct __declspec(align(16)) Dsub
{
    Dvec4 v0, v1, v2, v3;
    Dvec4 unk40, unk50;
};

struct Dtask
{
    void* f00;
    void* f04;
    int f08;
    void* f0c;
    int f10;
    int unk14;
    int unk18;
    int unk1c;
    Dsub sub;
};

struct Dctx
{
    int f0;
    int f1;
    int f2;
    int f3;
};

struct Dsrc
{
    int unk00;
    int unk04;
    Dvec4* f08;
};

struct Drecv
{
    int unk00;
    int unk04;
    int f08;
    int f0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int f20;
    int unk24;
    int unk28;
    int unk2c;
    int f30;

    void FUN_00daccd0(Dsrc* a1, Dsrc* a2, Dsrc* a3, void* a4);
};


// Fills a Dtask from a1, a2, a3 and f08, calls FUN_00cb22f0 on its sub with a1->f08 and a2->f08, then ProcessCollision with the task, tmp, f0c, f30, f20 and a4.
// @fnv 0x00daccd0
void Drecv::FUN_00daccd0(Dsrc* a1, Dsrc* a2, Dsrc* a3, void* a4)
{
    Dctx ctx;
    Dtask res;
    res.f08 = 0;
    res.f00 = a1;
    res.f04 = a2;
    res.f10 = f08;
    res.f0c = a3;
    reinterpret_cast<::hkTransformCB22 *>(&(res.sub))->FUN_00cb22f0((*(const ::hkTransformCB22 *)(a1->f08)), (*(const ::hkTransformCB22 *)(a2->f08)));
    ::ProcessCollision((::In *)(::Dtask *)(&res), &ctx.f0, (::Arg2 *)(int *)(&ctx.f1), (::Arg3 *)(int *)(&f0c), (::Arg4 *)(int *)(&f30), (::VecS *)(int *)(&f20), (::Arg6 *)(a4));
}



namespace hkRouterDACC {
}

struct hkAllocHeaderDACC
{
    void* vtable;
    unsigned short allocationSize;
};

inline void* allocateAgentDACC(int nbytes)
{
    void* b = hkMemoryRouter::getInstance().heap().blockAlloc(nbytes);
    static_cast<hkAllocHeaderDACC*>(b)->allocationSize = (unsigned short)nbytes;
    return b;
}

struct GskInitDACC : FUN_00dacbd0
{
    FUN_00dabf10* FUN_00dacbd0(int, int, int);
    FUN_00dabf10* FUN_00dabf10(int, int, int);
};

// If c is nonzero, allocates 0x80 bytes and calls FUN_00dacbd0; otherwise allocates 0x30 bytes and calls FUN_00dabf10; returns the constructed object.
// @fnv 0x00dacc00
FUN_00dabf10* __cdecl FUN_00dacc00(GskNode* a, GskNode* b, const void* unused, void* c)
{
    if (c)
        return ((::FUN_00dabf10 *)(new ((void *)(static_cast<GskInitDACC*>(allocateAgentDACC(0x80)))) ::FUN_00dacbd0(a, b, c)));
    return ((::FUN_00dabf10 *)(reinterpret_cast<::FUN_00dabf10_cls *>((static_cast<GskInitDACC*>(allocateAgentDACC(0x30))))->FUN_00dabf10(a, b, 0)));
}

__declspec(noinline) void __cdecl InitVtable(FUN_00dacc70_vt* p);

typedef FUN_00dacc70_vt D41FD0AgentFuncs;

struct D41FD0CollisionDispatcher
{
};

// Builds an agent function table with b0 and b1 zeroed and InitVtable, and registers it with the dispatcher for the pair 0x12, 0x12.
// @fnv 0x00dacca0
void __cdecl FUN_00dacca0(D41FD0CollisionDispatcher* dispatcher)
{
    D41FD0AgentFuncs funcs;
    funcs.b0 = 0;
    funcs.b1 = 0;
    InitVtable(&funcs);
    reinterpret_cast<::FUN_00cfbbe0_cls *>((dispatcher))->FUN_00cfbbe0((::FUN_00cfbbe0_rec *)&(funcs), 0x12, 0x12);
}

// Moved from hkpgskfagent_rtm_variant.cpp (VEGAS-15).
// src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/convexagent/gjk/hkpgskfagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
#include <windows.h>
#include "fnv/symbols_01268000.h"
void __cdecl InitVtable(FUN_00dacc70_vt* p);

extern "C"
{
    unsigned __int64 __rdtsc();
    void _ReadWriteBarrier();
}

typedef unsigned long DWORD;

extern const char str_010ceca0[];

struct hkMonitorStreamS
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static hkMonitorStreamS& GetMonitorStream()
    {
        return *(hkMonitorStreamS*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    char* GetStreamEnd()
    {
        return m_kRayEnd;
    }
    void setEnd(char* e)
    {
        m_kRayEnd = e;
    }
};
struct SweepFactors
{
    union
    {
        volatile unsigned int ticks;
        float a;
    };
    union
    {
        volatile unsigned int laterTicks;
        float b;
    };
};
struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        m_uiStartTicks = t;
    }
};
struct TimedNameRecord : CommandTimingEntry
{
    const char* m_pFirst;
};

struct hkVector4S
{
    __m128 m_vComponents;
    __forceinline void setSub4(const hkVector4S& a, const hkVector4S& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void mul4(float r)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, _mm_set_ps1(r));
    }
    __forceinline void add4(const hkVector4S& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    float& operator()(int i)
    {
        return ((float*)&m_vComponents)[i];
    }
    const float& operator()(int i) const
    {
        return ((const float*)&m_vComponents)[i];
    }
    __forceinline void setMul4(float r, const hkVector4S& a)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, _mm_set_ps1(r));
    }
    __forceinline void addMul4(float r, const hkVector4S& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, _mm_set_ps1(r)));
    }
};

struct hkMotionStateS
{
    __m128 unk00;
    __m128 unk10;
    __m128 unk20;
    __m128 unk30;
    hkVector4S m_vCenterOfMass0;
    hkVector4S m_vCenterOfMass1;
    __m128 unk60;
    __m128 unk70;
    __m128 unk80;
    hkVector4S m_kDeltaAngle;
    float m_fObjectRadius;
};

struct hkCdBodyS
{
    int unk00;
    int unk04;
    hkMotionStateS* m_pMotionState;
};

struct hkInputS
{
    int unk00;
    int unk04;
    float m_fScalar;
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
    float m_uiStartTime;
    float m_fEndTime;
    float m_fTimeStep;
    float m_fInverseDeltaTime;
};

static __forceinline void calcTimInfo(const hkMotionStateS& ms0, const hkMotionStateS& ms1, float deltaTime,
                                      hkVector4S& timInfo, SweepFactors& work)
{
    work.b = deltaTime;
    work.a = work.b * (*(const volatile float*)&(ms0.m_vCenterOfMass1(3)));
    work.b *= ms1.m_vCenterOfMass1(3);
    __m128 r0 = _mm_load_ss(&work.a);
    __m128 s0 = _mm_shuffle_ps(r0, r0, 0);
    timInfo.m_vComponents = (_mm_add_ps(
        (_mm_mul_ps((_mm_sub_ps((ms0.m_vCenterOfMass0.m_vComponents), (ms0.m_vCenterOfMass1.m_vComponents))), s0)),
        (_mm_mul_ps((_mm_shuffle_ps((_mm_load_ss(&work.b)), (_mm_load_ss(&work.b)), 0)),
                    (_mm_sub_ps((ms1.m_vCenterOfMass1.m_vComponents), (ms1.m_vCenterOfMass0.m_vComponents)))))));
    timInfo(3) =
        (*(const volatile float*)&(ms0.m_kDeltaAngle(3))) * work.a * (*(const volatile float*)&(ms0.m_fObjectRadius)) +
        (*(const volatile float*)&(ms1.m_kDeltaAngle(3))) * work.b * (*(const volatile float*)&(ms1.m_fObjectRadius));
}

struct hkGskAgentS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    float m_fFloatValue;
    int unk1c;
    hkVector4S m_vSeparatingNormal;
    void FUN_00dacd50(const hkCdBodyS& a, const hkCdBodyS& b, const hkInputS& input, void* result);
};

// @fnv 0x00dacd50
void hkGskAgentS::FUN_00dacd50(const hkCdBodyS& a, const hkCdBodyS& b, const hkInputS& input, void* result)
{
    SweepFactors work;
    {
        hkMonitorStreamS& s = hkMonitorStreamS::GetMonitorStream();
        if (s.memoryAvailable())
        {
            TimedNameRecord* h = (TimedNameRecord*)s.GetStreamEnd();
            h->m_pCommandName = "LtGskAgent";
            h->m_pFirst = "StTim";
            _ReadWriteBarrier();
            work.ticks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_uiStartTicks = work.ticks;
            s.setEnd((char*)(h + 1));
        }
    }
    if (m_fFloatValue != input.m_uiStartTime)
    {
        hkVector4S timInfo;
        calcTimInfo(*a.m_pMotionState, *b.m_pMotionState, input.m_fTimeStep, timInfo, work);
        if (m_vSeparatingNormal(3) > input.m_fScalar)
        {
            __m128 p = _mm_mul_ps(m_vSeparatingNormal.m_vComponents, timInfo.m_vComponents);
            __m128 w = _mm_shuffle_ps(timInfo.m_vComponents, timInfo.m_vComponents, 0xff);
            __m128 z = _mm_shuffle_ps(p, p, 0xaa);
            __m128 y = _mm_shuffle_ps(p, p, 0x55);
            __m128 d = _mm_add_ps(_mm_add_ss(z, w), _mm_add_ss(y, p));
            _mm_store_ss(&work.b, d);
            m_vSeparatingNormal(3) -= work.b;
            if (m_vSeparatingNormal(3) > input.m_fScalar)
                goto END;
        }
    }
    {
        hkMonitorStreamS& s = hkMonitorStreamS::GetMonitorStream();
        if (s.memoryAvailable())
        {
            CommandTimingEntry* h = (CommandTimingEntry*)s.GetStreamEnd();
            h->m_pCommandName = str_010ceca0;
            _ReadWriteBarrier();
            work.laterTicks = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            h->m_uiStartTicks = work.laterTicks;
            s.setEnd((char*)(h + 1));
        }
    }
    m_fFloatValue = input.m_fEndTime;
    reinterpret_cast<::Drecv *>(this)->FUN_00daccd0((::Dsrc *)&(a), (::Dsrc *)&(b), (::Dsrc *)&(input), result);
END: {
    hkMonitorStreamS& s = hkMonitorStreamS::GetMonitorStream();
    if (s.memoryAvailable())
    {
        CommandTimingEntry* h = (CommandTimingEntry*)s.GetStreamEnd();
        h->m_pCommandName = "lt";
        _ReadWriteBarrier();
        work.laterTicks = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        h->m_uiStartTicks = work.laterTicks;
        s.setEnd((char*)(h + 1));
    }
}
}
#include "generated/data/havok/physics/collide/agent/convexagent/gjk/hkpgskfagent_rtm_variant.inc"
