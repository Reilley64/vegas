
// src/fallout_shared/pathfinding/pathsmoother.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathsmoother.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/AvoidPath.h"
#include "fnv/decl/F08.h"
#include "fnv/decl/FNV_006ef920.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_006b3160_shell.h"
#include "fnv/decl/FUN_006f02e0_Class.h"
#include "fnv/decl/FUN_006f1c10_Path.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/HeightPath.h"
#include "fnv/decl/Host_6f03a0.h"
#include "fnv/decl/PSSolution.h"
#include "fnv/decl/PathSmoother.h"
#include "fnv/decl/PathingLocationOwner.h"
#include "fnv/decl/SHStub.h"
#include "fnv/decl/SMPPath.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_006f1d30__PathSmoother.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_0084b5c0__FUN_0084b5c0_Array.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0069e000.h"
struct FUN_006ed4e0_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};

struct FUN_006f25d0_shell
{
    void __thiscall FUN_006f25d0();
};

struct FUN_006ed510_shell
{
    void __thiscall FUN_006ed510();
};
// Calls FUN_006ed510, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x006ed4e0
void* FUN_006ed4e0_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_006ed510_shell *>(this)->FUN_006ed510();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct GlobalObject_00869f00
{
    virtual ~GlobalObject_00869f00();
};
struct FUN_006f25b0 : GlobalObject_00869f00
{
    ~FUN_006f25b0();
};
struct FUN_006f25d0 : FUN_006f25b0
{
    ~FUN_006f25d0();
};
// @fnv 0x006ed510
void __thiscall FUN_006ed510_shell::FUN_006ed510()
{
    reinterpret_cast<::FUN_006f25d0 *>((((FUN_006f25d0_shell*)((char*)this + 0x2c))))->FUN_006f25d0::~FUN_006f25d0();
}
// Destructor that calls Clear(true) on the global object.
// @fnv 0x006f25d0
FUN_006f25d0::~FUN_006f25d0()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct PooledEntry
{
};

struct EntryPool
{
    int unk00, unk04, unk08, unk0c;
    ~EntryPool();
};

struct EntryArrayBase
{
    void* m_vtbl;
    int unk04, unk08, unk0c, unk10;
    PooledEntry*& FUN_00877a30(unsigned int uiIndex);
};

struct EntryArrayA : EntryArrayBase
{
    ~EntryArrayA();
};
struct EntryArrayB : EntryArrayBase
{
    ~EntryArrayB();
};
struct EntryArrayC : EntryArrayBase
{
    ~EntryArrayC();
};
struct EntryTable
{
    int unk00;
    ~EntryTable();
};

struct FUN_006ed220
{
    char pad00[0x30];
    EntryPool m_kEntryPool;
    EntryArrayA m_kActive;
    EntryArrayA m_kPending;
    EntryArrayB m_kFreeA;
    EntryArrayB m_kFreeB;
    EntryArrayC m_kFreeC;
    EntryTable m_kTable;

    ~FUN_006ed220();
};

// @fnv 0x006ed220
FUN_006ed220::~FUN_006ed220()
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kActive))->GetName())); i++)
    {
        reinterpret_cast<::FUN_006ed4e0_shell *>((m_kActive.FUN_00877a30(i)))->DestroyIfFlagged(0);
        reinterpret_cast<::SHStub *>(&(m_kEntryPool))->FUN_00aa5610(m_kActive.FUN_00877a30(i));
    }
    if (!reinterpret_cast<::FUN_0076b610_Class *>(&(m_kPending))->FUN_0076b610())
        reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(&(m_kPending))->FUN_009a4320(0, 1);
    if (!reinterpret_cast<::FUN_0076b610_Class *>(&(m_kPending))->FUN_0076b610())
        reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(&(m_kPending))->FUN_009a4320(0, 1);
    for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kPending))->GetName())); j++)
    {
        reinterpret_cast<::FUN_006ed4e0_shell *>((m_kPending.FUN_00877a30(j)))->DestroyIfFlagged(0);
        reinterpret_cast<::SHStub *>(&(m_kEntryPool))->FUN_00aa5610(m_kPending.FUN_00877a30(j));
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_kActive))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_kPending))->Clear(true);
    for (unsigned int k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kFreeA))->GetName())); k++)
        reinterpret_cast<::SHStub *>(&(m_kEntryPool))->FUN_00aa5610(m_kFreeA.FUN_00877a30(k));
    for (unsigned int l = 0; l < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kFreeB))->GetName())); l++)
        reinterpret_cast<::SHStub *>(&(m_kEntryPool))->FUN_00aa5610(m_kFreeB.FUN_00877a30(l));
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_kFreeA))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_kFreeB))->Clear(true);
    for (unsigned int m = 0; m < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kFreeC))->GetName())); m++)
        reinterpret_cast<::SHStub *>(&(m_kEntryPool))->FUN_00aa5610(m_kFreeC.FUN_00877a30(m));
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_kFreeC))->Clear(true);
}

struct Triple
{
    int unk00;
    int unk04;
    int unk08;
};

struct SubSlot
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;

};

struct ArgObj
{
};

struct Holder
{
};

struct NodeA
{
};

struct Gate
{
};

struct FUN_006ed530_cls
{
    Gate* m_00;
    NodeA* m_04;
    Triple m_08;
    Triple m_14;
    int m_20;
    int m_24;
    int m_28;
    float m_2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    SubSlot m_40;
    SubSlot m_54;
    SubSlot m_68;
    SubSlot m_7c;
    SubSlot m_90;

    bool FUN_006ed530(NodeA* a1, ArgObj* a2, ArgObj* a3, Triple* a4, Triple* a5, int a6, Gate* a7, unsigned char a8);
};

// @fnv 0x006ed530
bool FUN_006ed530_cls::FUN_006ed530(NodeA* apNode, ArgObj* apArgObj, ArgObj* apArgObj2, Triple* apTripleA,
                                    Triple* apTripleB, int aiValue, Gate* apGate, unsigned char abForce)
{
    bool bResult;

    m_04 = apNode;
    m_08 = *apTripleA;
    m_14 = *apTripleB;
    m_20 = (int)apArgObj;
    m_24 = (int)apArgObj2;
    m_28 = aiValue;
    m_00 = apGate;
    m_2c = ::GetFloatAtOffset68((const char *)(m_04));

    if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apArgObj))->GetName())) == 1)
    {
        reinterpret_cast<::PathingLocationOwner *>(this)->FUN_006ed730((*(const ::NiPoint3 *)(apTripleA)), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_0068efb0_shell *>(((*(Holder**)((void *)(reinterpret_cast<::FUN_006b3160_shell *>((apArgObj))->FUN_006b3160(0))))))->FUN_0068efb0()))));
        reinterpret_cast<::PathingLocationOwner *>(this)->FUN_006ed730((*(const ::NiPoint3 *)(apTripleB)), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_0068efb0_shell *>(((*(Holder**)((void *)(reinterpret_cast<::FUN_006b3160_shell *>((apArgObj))->FUN_006b3160(0))))))->FUN_0068efb0()))));
        return true;
    }

    reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>(&(m_40))->FUN_0084b5c0(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apArgObj2))->GetName())) << 1);
    reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>(&(m_54))->FUN_0084b5c0(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apArgObj2))->GetName())) << 1);
    reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>(&(m_68))->FUN_0084b5c0(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apArgObj2))->GetName())) << 1);
    reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>(&(m_7c))->FUN_0084b5c0(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apArgObj2))->GetName())) << 1);
    reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>(&(m_90))->FUN_0084b5c0(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apArgObj2))->GetName())) << 1);

    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_40))->Clear(0);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_54))->Clear(0);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_68))->Clear(0);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_7c))->Clear(0);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(m_90))->Clear(0);

    reinterpret_cast<::PathSmoother *>(this)->FUN_006ed850();
    reinterpret_cast<::F08 *>(this)->FUN_006eef80();
    bResult = reinterpret_cast<::FNV_006ef920 *>(this)->CheckEdges();
    reinterpret_cast<::FUN_006f02e0_Class *>(this)->CopyNodePositions();
    reinterpret_cast<::Host_6f03a0 *>(this)->FUN_006f03a0();
    reinterpret_cast<::SMPPath *>(this)->SmoothNodes();
    reinterpret_cast<::HeightPath *>(this)->FlattenPathPoints();
    reinterpret_cast<::PSSolution *>(this)->BuildLocations();
    reinterpret_cast<::AvoidPath *>(this)->ClipPathAgainstObstacles();

    if (abForce != 0 || reinterpret_cast<::FUN_0076b610_Class *>((apGate))->FUN_0076b610())
    {
        reinterpret_cast<::FUN_006f1c10_Path *>(this)->AppendSegments(1, 1);
        reinterpret_cast<::fnv_006f1d30::PathSmoother *>(this)->SmoothPathDirections();
    }
    return bResult;
}
