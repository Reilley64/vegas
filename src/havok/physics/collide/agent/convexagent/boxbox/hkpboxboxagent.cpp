
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
    return ((void *)(::FUN_00dacc00((intptr_t)(apFirst), (intptr_t)(apSecond), (intptr_t)(a3), (intptr_t)(a4))));
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

#include "generated/data/havok/physics/collide/agent/convexagent/boxbox/hkpboxboxagent.inc"
