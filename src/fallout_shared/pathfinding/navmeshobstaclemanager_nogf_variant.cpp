
// src/fallout_shared/pathfinding/navmeshobstaclemanager_nogf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout_shared/pathfinding/navmeshobstaclemanager.cpp lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include <new>
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C006c6030.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostA.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ListReader.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Map62d0.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/ObstacleMgrX.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_006c5ce0__FUN_006c5ce0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_0106c000.h"
#include "navmeshobstaclemanager_decls.h"

#include <xmmintrin.h>
struct V3
{
    float x, y, z;
};
struct S006c4ad0_Obs
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    V3 pos;
};
struct S006c4ad0_Ptr
{
    S006c4ad0_Obs* p;
    S006c4ad0_Ptr(S006c4ad0_Obs* q);
    void FUN_0045cec0();
    ~S006c4ad0_Ptr();
};
struct S006c4ad0_Body;
struct S006c4ad0_Ref2
{
    void* FUN_004b4ec0();
};
struct S006c4ad0_Queue
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual unsigned int Count();
};
struct S006c4ad0_Body
{
};
struct S006c4ad0_Map
{
};
struct S006c4ad0_List
{
};
__declspec(align(16)) struct S006c4ad0_Holder3
{
    __m128 q;
};
struct ObsMgr
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    S006c4ad0_List list3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    S006c4ad0_Queue queueA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    S006c4ad0_Map mapE0;
    void FUN_006c4ad0();
};

// @fnv 0x006c4ad0
void ObsMgr::FUN_006c4ad0()
{
    unsigned int count = queueA0.Count();
    for (unsigned int i = 0; i < count; i++)
    {
        S006c4ad0_Body* body;
        reinterpret_cast<::C006c6030 *>(&(queueA0))->FUN_006c6030(&body);
        S006c4ad0_Ptr sp(0);
        if (reinterpret_cast<::Map62d0 *>(&(mapE0))->FUN_006c62d0((unsigned int)(body), (void **)(::S006c4ad0_Ptr *)(&sp)))
        {
            S006c4ad0_Holder3 h;
            new ((void *)&(h)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(((::S006c4ad0_Ref2 *)(reinterpret_cast<::FUN_00620b80_shell *>((body))->GetReferenceFlags()))->FUN_004b4ec0())));
            V3 v;
            new ((void *)&(v)) ::Vec3();
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&v)), (*(const ::hkVector4 *)(&h)));
            V3 tmp;
            if (reinterpret_cast<::TESCombatStyle *>((((::V3 *)(reinterpret_cast<::FUN_00439ef0_class *>(&(v))->FUN_00439ef0((::NiPoint3 *)(::V3 *)(&tmp), (*(const ::NiPoint3 *)(&((::S006c4ad0_Obs *)(::FUN_00559450((int *)&(sp))))->pos)))))))->UpdateCombatStyle() > ::fnv_006c4d30::kObsDist)
                reinterpret_cast<::ObstacleMgrX *>(this)->FUN_006c1760((*(const ::ObstPtrX *)(&sp)));
            reinterpret_cast<::ListReader *>(&(list3C))->FUN_00631620((*(const ::NodeValue *)(&sp)));
        }
    }
}
