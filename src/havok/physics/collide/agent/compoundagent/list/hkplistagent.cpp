// src/havok/physics/collide/agent/compoundagent/list/hkplistagent.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent/compoundagent/list/hkplistagent.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/symbols_00d36000.h"
#include "fnv/symbols_00d97000.h"
#include "fnv/symbols_00da3000.h"
#include "fnv/symbols_00da4000.h"
struct hkAgent1nMachine
{
    void __thiscall InvalidateTim(void*);
};

struct hkpListAgent
{
    char m0[0x10];
    void __thiscall FUN_00d36850(void* arg);
};

// @fnv 0x00d36850
void __thiscall hkpListAgent::FUN_00d36850(void* arg)
{
    ::FUN_00da3510((*(::AgentSectorPointerArray *)((char*)this + 0x10)), (*(::CollisionAgentContext *)(arg)));
}


// @fnv 0x00d36b00
void __stdcall FUN_00d36b00(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    ::FUN_00d36990();
}

struct Owner
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00d36870(float a1, float a2, int a3);
};
// Forwards the three arguments to FUN_00da35f0 with the object's field at offset 0x10 as its first argument.
// @fnv 0x00d36870
void Owner::FUN_00d36870(float afValue1, float afValue2, int aiValue)
{
    ::FUN_00da35f0((::Da35Stream ***)(void *)((char*)this + 0x10), afValue1, afValue2, (void **)(aiValue));
}


// @fnv 0x00d36940
void __stdcall FUN_00d36940(void* apArg1, void* apArg2, void* apArg3, void* apArg4)
{
    ::FUN_00d36920();
}


// Forwards all five arguments to FUN_00d36930.
// @fnv 0x00d36960
void __stdcall FUN_00d36960(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    ::FUN_00d36930();
}


struct FUN_00d36820_cls
{
    virtual void v00(int a);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void FUN_00d36820(int a1);
};

// Calls FUN_00da42b0 with &unk10, unk0C, unk08 and a1, then invokes v00(1).
// @fnv 0x00d36820
void FUN_00d36820_cls::FUN_00d36820(int aiValue)
{
    ::FUN_00da42b0((::BlockPoolArray *)(void *)(&unk10), (::S_00da40e0_Dispatcher *)(unk0C), (::S_00da40e0_ContactMgr *)(unk08), (*(::S_00da40e0_ConstraintOwner *)(aiValue)));
    this->v00(1);
}

struct S_00d368a0_Arg
{
    int unk00;
    int unk04;
    int m_field08;
};


struct S_00d368a0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_sub10;

    void FUN_00d368a0(S_00d368a0_Arg* a, int unused);
};

// @fnv 0x00d368a0
void S_00d368a0::FUN_00d368a0(S_00d368a0_Arg* a, int unused)
{
    ::FUN_00d97250((::Hdr *)(void *)(&m_sub10), (char **)(a->m_field08), (::Logger *)(a));
}


struct VirtTarget
{
    virtual int v00();
    virtual int v04();
    virtual int v08();
    virtual int v0c();
    virtual int v10();
};

struct CallArgs
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct FUN_00d368c0_cls
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    int unk10;
    void FUN_00d368c0(void* a1, void* a2, void* a3, void* a4);
};
// Builds a CallArgs from the four arguments and m_08, calls v10 on a2, then passes it to FUN_00da48e0 with this+0x10.
// @fnv 0x00d368c0
void FUN_00d368c0_cls::FUN_00d368c0(void* a1, void* a2, void* a3, void* a4)
{
    CallArgs s;
    s.unk00 = (int)a1;
    s.unk10 = (int)a3;
    int iStored = m_08;
    s.unk04 = (int)a2;
    s.unk14 = iStored;
    s.unk18 = (int)a4;
    s.unk0C = (*(VirtTarget**)a2)->v10();
    ::FUN_00da48e0((int)((char*)this + 0x10), (int)(&s));
}
