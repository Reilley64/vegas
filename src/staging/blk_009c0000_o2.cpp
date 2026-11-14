
// src/staging/blk_009c0000_o2.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, o2 code style). Not a real source path: move functions to their real units once identified.

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "../../include/layout_support.h"
#include "fnv/decl/Actor.h"
#include "fnv/decl/Class_007f68a0.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3fb0_shell.h"
#include "fnv/decl/FUN_009795c0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009c5af0__FUN_009c5af0_shell.h"
#include "fnv/symbols_0070c000.h"
#include "fnv/symbols_009c0000.h"
#include "fnv/symbols_011de000.h"

// sub ecx,0x3e0; jmp FUN_008d1130 == MSVC adjustor thunk (11 bytes, thiscall).
// Derived overrides a virtual that both bases declare; the second base's vtable gets a thunk
// that moves this back by the first base's size (0x3e0 = vptr + 247 ints).
struct PrimaryBase_009c6a20
{
    virtual void FUN_009c6a20();
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
    int unk3C;
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
    int unkA0;
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
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
};

struct SecondaryBase_009c6a20
{
    virtual void FUN_009c6a20();
};

struct Derived_009c6a20 : PrimaryBase_009c6a20, SecondaryBase_009c6a20
{
    Derived_009c6a20();
// @fnv 0x009c6a20
    virtual void FUN_009c6a20();
};

Derived_009c6a20::Derived_009c6a20()
{}

struct xP3
{
    xP3();
    float x, y, z;
    xP3 operator-(const xP3&) const;
};

struct xFilter
{
    xFilter(int);
    unsigned int m_uiFilterValue;
};

struct xAllHits
{
    xAllHits();
    virtual ~xAllHits();
    int m_q[0xc7];
};

struct __declspec(align(16)) xPick
{
    xPick();
    void FUN_004a3f70(xFilter);
    char m_buf[0xb0];
};

struct xWorld
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual bool FUN_c8(xPick*);
};

struct xCell;

struct xOwner
{
    xFilter FUN_0070c440();
};

struct xActor;

struct xActor
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
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual xP3* FUN_1f4();
    char m_pad04[0xf8];
    xActor* m_fc;
    xFilter FUN_00931ed0();
    bool FUN_009c40c0();
};

// @fnv 0x009c40c0
bool xActor::FUN_009c40c0()
{
    if (m_fc != (*reinterpret_cast<::xActor * *>(&::_g_thePlayer)))
        return false;
    xPick PICK;
    xP3 PLPOS;
    xP3 MYPOS;
    xP3 DIR;
    MYPOS = *FUN_1f4();
    PLPOS = *(*reinterpret_cast<::xActor * *>(&::_g_thePlayer))->FUN_1f4();
    PLPOS.z = PLPOS.z + ::FUN_0070c3b0((::FUN_0070c3b0_Dummy *)((*reinterpret_cast<::xActor * *>(&::_g_thePlayer)))) * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>(((*reinterpret_cast<::xActor * *>(&::_g_thePlayer))))->FUN_00567400();
    DIR = MYPOS - PLPOS;
    xOwner* OWNER = ((::xOwner *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()));
    xFilter FILTER(0);
    if (OWNER)
        FILTER = OWNER->FUN_0070c440();
    else
        FILTER = (*reinterpret_cast<::xActor * *>(&::_g_thePlayer))->FUN_00931ed0();
    reinterpret_cast<::FUN_004a39f0_shell *>(&(FILTER))->FUN_004a39f0(6);
    PICK.FUN_004a3f70(FILTER);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(PICK))->FUN_004a3da0(&PLPOS);
    reinterpret_cast<::Class_007f68a0 *>(&(PICK))->FUN_007f68a0((*(const ::NiPoint3 *)(&DIR)));
    xAllHits HITS;
    reinterpret_cast<::FUN_004a3fb0_shell *>(&(PICK))->FUN_004a3fb0((::hkpAllRayHitCollector *)(::xAllHits *)(&HITS));
    xWorld* WORLD = ((::xWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::xCell *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::xActor * *>(&::_g_thePlayer))))->GetTarget()))))->FUN_004543c0()));
    bool RES = WORLD->FUN_c8(&PICK);
    float DIST = 3.402823466e+38F;
    RES = RES | reinterpret_cast<::fnv_009c5af0::FUN_009c5af0_shell *>(this)->GetWaterPlaneIntersection((::fnv_009c5af0::Proxy *)(::xPick *)(&PICK), &DIST);
    if (RES)
        RES = ::FUN_009c0d80((::Scene *)(::xPick *)(&PICK), (::Controller *)(::xActor *)(this), (int)(std::uintptr_t)(((void *)(reinterpret_cast<::Actor *>(this)->GetActorBase()))), (float *)(0), 1, DIST) != 0;
    if (RES)
        reinterpret_cast<::FUN_009795c0_shell *>(this)->FUN_009795c0(0.0f);
    return RES;
}
