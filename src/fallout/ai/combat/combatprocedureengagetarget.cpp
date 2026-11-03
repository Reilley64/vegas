
// src/fallout/ai/combat/combatprocedureengagetarget.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureengagetarget.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/ActorStandIn.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/CombatProcedureEx.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00507610_Class.h"
#include "fnv/decl/FUN_00527990_shell.h"
#include "fnv/decl/FUN_00527a80_shell.h"
#include "fnv/decl/FUN_00527b70_shell.h"
#include "fnv/decl/FUN_00527ba0_This.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_006e2980_shell.h"
#include "fnv/decl/FUN_006e4320_Class.h"
#include "fnv/decl/FUN_006e4ef0_shell.h"
#include "fnv/decl/FUN_006e5ee0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008b3960_Class.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008b3bf0_shell.h"
#include "fnv/decl/FUN_008d7f40_shell.h"
#include "fnv/decl/FUN_0097ede0_cls.h"
#include "fnv/decl/FUN_0097fa50_Class.h"
#include "fnv/decl/FUN_0097fb00_cls.h"
#include "fnv/decl/FUN_00996de0_Class.h"
#include "fnv/decl/FUN_00996e00_shell.h"
#include "fnv/decl/FUN_00996ed0_shell.h"
#include "fnv/decl/FUN_00996ef0_shell.h"
#include "fnv/decl/FUN_0099e190_cls.h"
#include "fnv/decl/FUN_009a0240_shell.h"
#include "fnv/decl/FUN_009ca6c0_class.h"
#include "fnv/decl/FUN_009caac0_shell.h"
#include "fnv/decl/FUN_009d4f30_shell.h"
#include "fnv/decl/FUN_009d4f50_cls.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/Pathing.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008b3880__FUN_008b3880_target.h"
#include "fnv/decl/fnv_0097fa90__FUN_0097fa90_Class.h"
#include "fnv/decl/fnv_0098ddd0__FUN_0098ddd0_shell.h"
#include "fnv/decl/fnv_00996e20__FUN_00996e20_shell.h"
#include "fnv/decl/fnv_00996e40__FUN_00996e40_shell.h"
#include "fnv/decl/fnv_00996ea0__MyProc.h"
#include "fnv/decl/fnv_0099abc0__FUN_0099abc0_This.h"
#include "fnv/decl/fnv_0099e840__FUN_0099e840_cls.h"
#include "fnv/decl/fnv_009a02a0__FUN_009a02a0_struct.h"
#include "fnv/decl/fnv_009a0ec0__FUN_009a0ec0_shell.h"
#include "fnv/decl/fnv_009a5f90__FUN_009a5f90_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_008b3000.h"
#include "fnv/symbols_0097f000.h"
#include "fnv/symbols_009a7000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_01050000.h"
#include "fnv/symbols_01053000.h"
#include "fnv/symbols_0108e000.h"
struct Actor
{
public:
    bool IsSneaking();
};

struct CombatProcedure
{
};

struct CombatProcedureEngageTarget : public CombatProcedure
{
    void FUN_009d3b50();
};

// @fnv 0x009d3b50
void CombatProcedureEngageTarget::FUN_009d3b50()
{
    reinterpret_cast<::fnv_00996e40::FUN_00996e40_shell *>(this)->FUN_00996e40();
    reinterpret_cast<::FUN_008b3ab0_shell *>((((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()))))->FUN_008b3ab0();
    reinterpret_cast<::fnv_00996ea0::MyProc *>((((CombatProcedure*)this)))->FUN_00996ea0();
}


struct FUN_009d3b00_shell
{
    void* Destroy(unsigned int flags);
};

struct FUN_009ca6c0_shell
{
};
extern void* DAT_01091514;
struct FUN_009d3b30_shell
{
    void FUN_009d3b30();
};
// Calls FUN_009d3b30, then deletes this if flags has bit 1 set, and returns this.
// @fnv 0x009d3b00
void* FUN_009d3b00_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_009d3b30_shell *>(this)->FUN_009d3b30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x009d3b30
void FUN_009d3b30_shell::FUN_009d3b30()
{
    *reinterpret_cast<void**>(this) = &DAT_01091514;
    reinterpret_cast<::FUN_009ca6c0_class *>((reinterpret_cast<FUN_009ca6c0_shell*>(this)))->FUN_009ca6c0();
}

struct BGSSaveFormBuffer
{
};

struct CoordinateTriple
{
};

class BGSLoadGameBuffer;
struct CombatTargetTimestamp
{
public:
    void LoadGame(::BGSLoadGameBuffer *);
};

struct CombatProcedureSaveGameHelper
{
};

struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer*);
};

struct FUN_009d5880_shell
{
    void FUN_009d5880(BGSSaveFormBuffer*);
};

// @fnv 0x009d5880
void FUN_009d5880_shell::FUN_009d5880(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00996ed0_shell *>((reinterpret_cast<CombatProcedureSaveGameHelper*>(this)))->SaveToBuffer(buffer);

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x14), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x18), 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x1C), 4, 0);

    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x20)->FUN_009a5eb0(buffer);
    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x28)->FUN_009a5eb0(buffer);

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x30), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x31), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x32), 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x34), 12, 0);

    reinterpret_cast<::FUN_00527b70_shell *>((reinterpret_cast<CoordinateTriple*>(reinterpret_cast<char*>(this) + 0x40)))->FUN_00527b70((::BGSSaveGameBuffer *)(buffer));
    reinterpret_cast<::FUN_00527b70_shell *>((reinterpret_cast<CoordinateTriple*>(reinterpret_cast<char*>(this) + 0x50)))->FUN_00527b70((::BGSSaveGameBuffer *)(buffer));

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x33), 1, 0);

    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((reinterpret_cast<CombatTargetTimestamp*>(reinterpret_cast<char*>(this) + 0x60)))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(buffer));
}

namespace fnv_009d5990 {
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
};

struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
};

struct CombatProcedure_Helper
{
};

struct TimeoutTimer
{
};

struct CombatTargetTimestamp
{
};

struct FUN_00527ba0_Class
{
};


struct FUN_009d5990_shell : public CombatProcedureEngageTarget
{
    void FUN_009d5990(BGSLoadFormBuffer* buffer);
};

// Loads the combat procedure's fields from the buffer, reading a version-gated float and two sub-objects, with extra fields for versions 10 and 14.
// @fnv 0x009d5990
void FUN_009d5990_shell::FUN_009d5990(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00996ef0_shell *>((reinterpret_cast<CombatProcedure_Helper*>(this)))->FUN_00996ef0((::BGSLoadFormBuffer *)(buffer));

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x14)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x18)), 4);

    if (buffer->GetVersion() >= 14)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x1c)), 4);
    }
    else
    {
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x1c) = ::DAT_01022958;
    }

    reinterpret_cast<::TimeoutTimer *>((reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x20)))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::TimeoutTimer *>((reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x28)))->LoadGame((::BGSLoadFormBuffer *)(buffer));

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x30)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x31)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x32)), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x34)), 12);

    reinterpret_cast<::FUN_00527ba0_This *>((reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x40)))->FUN_00527ba0((::BGSLoadGameBuffer *)(buffer));
    reinterpret_cast<::FUN_00527ba0_This *>((reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x50)))->FUN_00527ba0((::BGSLoadGameBuffer *)(buffer));

    if (buffer->GetVersion() >= 10)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x33)), 1);
        reinterpret_cast<::CombatTargetTimestamp *>((reinterpret_cast<CombatTargetTimestamp*>(reinterpret_cast<char*>(this) + 0x60)))->LoadGame((::BGSLoadGameBuffer *)(buffer));
    }
}
}  // namespace fnv_009d5990

namespace Engage {
extern const float DAT_0101e57c;
extern bool DAT_011a5b70;
struct Vec4
{
    float x, y, z, w;
};
struct Timer
{
    float value;
};
struct Query
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Query();
    void* FUN_0097b940();
};
struct RequestA
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
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    RequestA();
    ~RequestA();
};
struct RequestB
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
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    RequestB();
    ~RequestB();
};
struct Controller
{
};
struct Context
{
};
struct Actor
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
    virtual void* Destination();
    bool SetPathingRequestAvoidNodes(void*);
};
struct Procedure
{
    int unk00;
    Context* context;
    int unk08, unk0c, unk10;
    float range, height, angle;
    int unk20, unk24, unk28, unk2c;
    char unk30, unk31, unk32;
    bool active;
    int unk34, unk38, unk3c;
    Vec4 point, target;
    Timer time;
    bool CheckAndApply(bool);
};
// @fnv 0x009d5000
bool Procedure::CheckAndApply(bool mode)
{
    if (((double)(reinterpret_cast<::FUN_00435e00_t *>(&(time))->FUN_00435e00())) < ::DAT_01020998)
        return false;
    active = true;
    if (DAT_011a5b70)
    {
        Actor* actor = ((::Engage::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
        Actor* targetActor3 = ((::Engage::Actor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
        RequestA request;
        reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actor))->PathToLocation((::fnv_008b3880::PathingRequest *)(void *)(&request), targetActor3->Destination(), ((void *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget())),
                              ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actor))->FUN_00575d70())), false, {});
        reinterpret_cast<::FUN_00507610_Class *>(&(request))->FUN_00507610(range);
        reinterpret_cast<::FUN_006e5ee0_Class *>(&(request))->FUN_006e5ee0(height);
        reinterpret_cast<::FUN_006e4ef0_shell *>(&(request))->FUN_006e4ef0(range * ::DAT_01011588);
        reinterpret_cast<::FUN_006e4320_Class *>(&(request))->FUN_006e4320(angle);
        if (!actor->SetPathingRequestAvoidNodes(&request))
            return false;
        target = (*(::Engage::Vec4 *)(reinterpret_cast<::FUN_00575650_Class *>((targetActor3))->FUN_00575650({})));
        reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(mode ? 3 : 1);
        active = false;
        return true;
    }
    else
    {
        Actor* actor2 = ((::Engage::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
        Actor* targetActor2 = ((::Engage::Actor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
        Query query2;
        Controller* controller5 = ((::Engage::Controller *)(reinterpret_cast<::InterfaceManager *>((context))->FUN_00586150()));
        if (!reinterpret_cast<::fnv_0099e840::FUN_0099e840_cls *>((controller5))->FUN_0099e840(range, height, range * ::DAT_01011588, angle, (::fnv_0099e840::FUN_0099b8b0_shell *)(::Engage::Query *)(&query2), true))
            return false;
        if (!reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>((controller5))->FUN_009a02a0((const ::fnv_009a02a0::CoordinateTriple &)((*(::Engage::Vec4 *)(new ((void *)&(query2)) ::Vec3()))), true, false))
            return false;
        RequestB request2;
        reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actor2))->PathToLocation((::fnv_008b3880::PathingRequest *)(void *)(&request2), query2.FUN_0097b940(), ((void *)(reinterpret_cast<::LowProcess *>((actor2))->GetTarget())),
                               ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actor2))->FUN_00575d70())), false, {});
        if (!actor2->SetPathingRequestAvoidNodes(&request2))
            return false;
        point = (*(::Engage::Vec4 *)(new ((void *)&(query2)) ::Vec3()));
        target = (*(::Engage::Vec4 *)(reinterpret_cast<::FUN_00575650_Class *>((targetActor2))->FUN_00575650({})));
        reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(mode ? 3 : 1);
        return true;
    }
}
}

namespace fnv_009d5410 {
static const char text_0[] = "INITIALIZING";
static const char text_1[] = "HOLDING";
static const char text_2[] = "Holding Timer: %.02f/%.02f";
static const char text_3[] = "CROUCHING";
static const char text_4[] = "Crouching Timer: %.02f/%.02f";
static const char text_5[] = "MOVING_OPTIMAL_CLOSE";
static const char text_6[] = "Range: %.2f - %.2f";
static const char text_7[] = "Target movement distance: %.2f/%.2f";
static const char text_8[] = "MOVING_OPTIMAL_FAR";
static const char text_9[] = "Range: %.2f - %.2f";
static const char text_10[] = "Target movement distance: %.2f/%.2f";
static const char text_11[] = "APPROACHING_TARGET";
static const char text_12[] = "DODGING FORWARD/BACKWARD";
static const char text_13[] = "DODGING LEFT/RIGHT";
static const char text_14[] = "Lost LOS.  Stop Moving Timer: %.02f/%.02f";
static const char text_15[] = "MOVING_TO_TARGET";
static const char text_16[] = "Optimal location pathing CheckMovement failed: %.02f/%.02f";
static const char text_17[] = "Optimal location pathing LOS check failed: %.02f/%.02f";
static const char text_18[] = "Optimal location path building failed: %.02f/%.02f";
struct Point
{
    float x, y, z;
    int world;
};
struct Ref
{
    Point Location();
};
struct Timer
{
    float start;
    float value;
};
struct Output
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void __cdecl Print(int, int, const char*, ...);
};
struct Engage
{
    int unk00, unk04, unk08, unk0c;
    unsigned state;
    float range14, range18;
    int unk1c;
    Timer timer20, timer28;
    bool enabled;
    char unk31, unk32;
    signed char result;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    Point target;
    Timer timer60;
    void PrintDebugInfo(Output* out, int a, int b);
};
// Prints state-specific debug text for the engage state, plus a timer-based message when timer60 has elapsed less than 5 seconds.
// @fnv 0x009d5410
void Engage::PrintDebugInfo(Output* pOutput, int a, int b)
{
    Ref* actor = ((::fnv_009d5410::Ref *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    switch (state)
    {
    case 0:
        pOutput->Print(a, b, text_0);
        break;
    case 1:
        pOutput->Print(a, b, text_1);
        pOutput->Print(a, b, text_2, reinterpret_cast<::FUN_00435e00_t *>(&(timer20))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(timer20))->FUN_006b9130());
        break;
    case 2:
        pOutput->Print(a, b, text_3);
        pOutput->Print(a, b, text_4, reinterpret_cast<::FUN_00435e00_t *>(&(timer20))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(timer20))->FUN_006b9130());
        break;
    case 3:
        pOutput->Print(a, b, text_5);
        pOutput->Print(a, b, text_6, range14, range18);
        if (actor)
        {
            Point location = (*(::fnv_009d5410::Point *)(reinterpret_cast<::FUN_00575650_Class *>((actor))->FUN_00575650({})));
            pOutput->Print(a, b, text_7, reinterpret_cast<::FUN_00527a80_shell *>(&(location))->DistanceTo((::FUN_00527a80_shell *)(::fnv_009d5410::Point *)(&target)), 200.0);
        }
        break;
    case 4:
        pOutput->Print(a, b, text_8);
        pOutput->Print(a, b, text_9, range14, range18);
        if (actor)
        {
            Point location = (*(::fnv_009d5410::Point *)(reinterpret_cast<::FUN_00575650_Class *>((actor))->FUN_00575650({})));
            pOutput->Print(a, b, text_10, reinterpret_cast<::FUN_00527a80_shell *>(&(location))->DistanceTo((::FUN_00527a80_shell *)(::fnv_009d5410::Point *)(&target)), 200.0);
        }
        break;
    case 5:
        pOutput->Print(a, b, text_11);
        break;
    case 8:
        pOutput->Print(a, b, text_15);
        break;
    case 6:
        pOutput->Print(a, b, text_12);
        break;
    case 7:
        pOutput->Print(a, b, text_13);
        if (enabled && reinterpret_cast<::FUN_0097fa50_Class *>(&(timer28))->FUN_0097fa50())
        {
            pOutput->Print(a, b, text_14, reinterpret_cast<::FUN_00435e00_t *>(&(timer28))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(timer28))->FUN_006b9130());
        }
        break;
    }
    if (reinterpret_cast<::FUN_00435e00_t *>(&(timer60))->FUN_00435e00() < 5.0)
    {
        if (result == -1)
        {
            pOutput->Print(a, b, text_16, reinterpret_cast<::fnv_0097fa90::FUN_0097fa90_Class *>(&(timer60))->GetClampedDifference(), 5.0);
        }
        else if (result == -2)
        {
            pOutput->Print(a, b, text_17, reinterpret_cast<::fnv_0097fa90::FUN_0097fa90_Class *>(&(timer60))->GetClampedDifference(), 5.0);
        }
        else
        {
            pOutput->Print(a, b, text_18, reinterpret_cast<::fnv_0097fa90::FUN_0097fa90_Class *>(&(timer60))->GetClampedDifference(), 5.0);
        }
    }
}
}  // namespace fnv_009d5410

namespace fnv_009d3b80 {
struct NiPoint3
{
    float x, y, z;
    NiPoint3();
};

struct RawPoint
{
    float x, y, z;
};

struct Location
{
    RawPoint pos;
    void* cell;
    float GetDistSq(Location* other);
};

struct Stamp
{
    float m_fTime;
    Stamp(float t);
};

struct TimeoutTimer : public Stamp
{
    float m_fEnd;
};

struct PathRequest
{
    unsigned int unk00[44];
    PathRequest();
    ~PathRequest();
};

struct SearchRequest
{
    unsigned int unk00[8];
    SearchRequest();
    void* GetResult();
};

struct ProcessObj
{
    virtual void w000();
    virtual void w001();
    virtual void w002();
    virtual void w003();
    virtual void w004();
    virtual void w005();
    virtual void w006();
    virtual void w007();
    virtual void w008();
    virtual void w009();
    virtual void w00a();
    virtual void w00b();
    virtual void w00c();
    virtual void w00d();
    virtual void w00e();
    virtual void w00f();
    virtual void w010();
    virtual void w011();
    virtual void w012();
    virtual void w013();
    virtual void w014();
    virtual void w015();
    virtual void w016();
    virtual void w017();
    virtual void w018();
    virtual void w019();
    virtual void w01a();
    virtual void w01b();
    virtual void w01c();
    virtual void w01d();
    virtual void w01e();
    virtual void w01f();
    virtual void w020();
    virtual void w021();
    virtual void w022();
    virtual void w023();
    virtual void w024();
    virtual void w025();
    virtual void w026();
    virtual void w027();
    virtual void w028();
    virtual void w029();
    virtual void w02a();
    virtual void w02b();
    virtual void w02c();
    virtual void w02d();
    virtual void w02e();
    virtual void w02f();
    virtual void w030();
    virtual void w031();
    virtual void w032();
    virtual void w033();
    virtual void w034();
    virtual void w035();
    virtual void w036();
    virtual void w037();
    virtual void w038();
    virtual void w039();
    virtual void w03a();
    virtual void w03b();
    virtual void w03c();
    virtual void w03d();
    virtual void w03e();
    virtual void w03f();
    virtual void w040();
    virtual void w041();
    virtual void w042();
    virtual void w043();
    virtual void w044();
    virtual void w045();
    virtual void w046();
    virtual void w047();
    virtual void w048();
    virtual void w049();
    virtual void w04a();
    virtual void w04b();
    virtual void w04c();
    virtual void w04d();
    virtual void w04e();
    virtual void w04f();
    virtual void w050();
    virtual void w051();
    virtual void w052();
    virtual void w053();
    virtual void w054();
    virtual void w055();
    virtual void w056();
    virtual void w057();
    virtual void w058();
    virtual void w059();
    virtual void w05a();
    virtual void w05b();
    virtual void w05c();
    virtual void w05d();
    virtual void w05e();
    virtual void w05f();
    virtual void w060();
    virtual void w061();
    virtual void w062();
    virtual void w063();
    virtual void w064();
    virtual void w065();
    virtual void w066();
    virtual void w067();
    virtual void w068();
    virtual void w069();
    virtual void w06a();
    virtual void w06b();
    virtual void w06c();
    virtual void w06d();
    virtual void w06e();
    virtual void w06f();
    virtual void w070();
    virtual void w071();
    virtual void w072();
    virtual void w073();
    virtual void w074();
    virtual void w075();
    virtual void w076();
    virtual void w077();
    virtual void w078();
    virtual void w079();
    virtual void w07a();
    virtual void w07b();
    virtual void w07c();
    virtual void w07d();
    virtual void w07e();
    virtual void w07f();
    virtual void w080();
    virtual void w081();
    virtual void w082();
    virtual void w083();
    virtual void w084();
    virtual void w085();
    virtual void w086();
    virtual void w087();
    virtual void w088();
    virtual void w089();
    virtual void w08a();
    virtual void w08b();
    virtual void w08c();
    virtual void w08d();
    virtual void w08e();
    virtual void w08f();
    virtual void w090();
    virtual void w091();
    virtual void w092();
    virtual void w093();
    virtual void w094();
    virtual void w095();
    virtual void w096();
    virtual void w097();
    virtual void w098();
    virtual void w099();
    virtual void w09a();
    virtual void w09b();
    virtual void w09c();
    virtual void w09d();
    virtual void w09e();
    virtual void w09f();
    virtual void w0a0();
    virtual void w0a1();
    virtual void w0a2();
    virtual void w0a3();
    virtual void w0a4();
    virtual void w0a5();
    virtual void w0a6();
    virtual void w0a7();
    virtual void w0a8();
    virtual void w0a9();
    virtual void w0aa();
    virtual void w0ab();
    virtual void w0ac();
    virtual void w0ad();
    virtual void w0ae();
    virtual void w0af();
    virtual void w0b0();
    virtual void w0b1();
    virtual void w0b2();
    virtual void w0b3();
    virtual void w0b4();
    virtual void w0b5();
    virtual void w0b6();
    virtual void w0b7();
    virtual void w0b8();
    virtual void w0b9();
    virtual void w0ba();
    virtual void w0bb();
    virtual void w0bc();
    virtual void w0bd();
    virtual void w0be();
    virtual void w0bf();
    virtual void w0c0();
    virtual void w0c1();
    virtual void w0c2();
    virtual void w0c3();
    virtual void w0c4();
    virtual void w0c5();
    virtual void w0c6();
    virtual void w0c7();
    virtual void w0c8();
    virtual void w0c9();
    virtual void w0ca();
    virtual void w0cb();
    virtual void w0cc();
    virtual void w0cd();
    virtual void w0ce();
    virtual void w0cf();
    virtual void w0d0();
    virtual void w0d1();
    virtual void w0d2();
    virtual void w0d3();
    virtual void w0d4();
    virtual void w0d5();
    virtual void w0d6();
    virtual void w0d7();
    virtual void w0d8();
    virtual void w0d9();
    virtual void w0da();
    virtual void w0db();
    virtual void w0dc();
    virtual void w0dd();
    virtual void w0de();
    virtual void w0df();
    virtual void w0e0();
    virtual void w0e1();
    virtual void w0e2();
    virtual void w0e3();
    virtual void w0e4();
    virtual void w0e5();
    virtual void w0e6();
    virtual void w0e7();
    virtual void w0e8();
    virtual void w0e9();
    virtual void w0ea();
    virtual void w0eb();
    virtual void w0ec();
    virtual void w0ed();
    virtual void w0ee();
    virtual void w0ef();
    virtual void w0f0();
    virtual void w0f1();
    virtual void w0f2();
    virtual void w0f3();
    virtual void w0f4();
    virtual void w0f5();
    virtual void w0f6();
    virtual void w0f7();
    virtual void w0f8();
    virtual void w0f9();
    virtual void w0fa();
    virtual void w0fb();
    virtual void w0fc();
    virtual void w0fd();
    virtual void w0fe();
    virtual void w0ff();
    virtual void w100();
    virtual void w101();
    virtual bool CheckFlag(int flag);
};

struct ActorObj
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual NiPoint3* GetLookPos();
    bool StartPath(PathRequest* req);
    bool GetFallbackPos(NiPoint3* out);
};

struct CombatCtrlObj
{
    bool CanReachPos(NiPoint3* pos, void* cell, int a, int b);
};

struct CombatOwner
{
};

extern double DAT_01091138;


class EngageProc
{
  public:
    void* vtbl;
    CombatOwner* m_pSharedOwner;
    int unk08;
    int unk0C;
    int m_iFadeIndex;
    float m_fMinRange;
    float m_fMaxRange;
    float m_fFarRange;
    TimeoutTimer m_timer20;
    TimeoutTimer m_timer28;
    bool m_bDodgeWait;
    bool m_bCovered;
    bool m_bDodging;
    signed char m_cFallback;
    NiPoint3 m_dodgePos;
    Location m_dest;
    Location m_lastTarget;
    Stamp m_stamp60;

    void ResetState();
    void UpdateEngagement();
};

// @fnv 0x009d3b80
void EngageProc::UpdateEngagement()
{
    ActorObj* actorZ = ((::fnv_009d3b80::ActorObj *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    ActorObj* target = ((::fnv_009d3b80::ActorObj *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    CombatCtrlObj* ctrlD = ((::fnv_009d3b80::CombatCtrlObj *)(reinterpret_cast<::InterfaceManager *>((m_pSharedOwner))->FUN_00586150()));
    if (target == 0)
    {
        return;
    }
    NiPoint3 avoidPos2;
    if (reinterpret_cast<::fnv_0099abc0::FUN_0099abc0_This *>((ctrlD))->UpdateLastSeenFiringLocation((*(::fnv_0099abc0::NiPoint3 *)(&avoidPos2))))
    {
        reinterpret_cast<::CombatProcedureEx *>(this)->SetLookAtPoint((*(const ::NiPoint3 *)(&avoidPos2)), true);
    }
    if (!((bool)(reinterpret_cast<::FUN_009a0240_shell *>((m_pSharedOwner))->GetFixedNormals())))
    {
        m_iFadeIndex = 1;
        return;
    }
    float oldMinB = m_fMinRange;
    float oldMax = m_fMaxRange;
    ::FUN_009a9180((::S_009a9180_Actor *)(m_pSharedOwner), (::S_009a9180_Data *)(void *)(((void *)(::FUN_007031c0((int)(m_pSharedOwner))))), &m_fMinRange, &m_fMaxRange, &m_fFarRange);
    bool changed = false;
    if (oldMinB != m_fMinRange || oldMax != m_fMaxRange)
    {
        changed = true;
    }
    Location targetLocX;
    reinterpret_cast<::FUN_00575650_Class *>((target))->FUN_00575650((::FUN_00575650_Result *)(::fnv_009d3b80::Location *)(&targetLocX));
    Location actorLocY;
    reinterpret_cast<::FUN_00575650_Class *>((actorZ))->FUN_00575650((::FUN_00575650_Result *)(::fnv_009d3b80::Location *)(&actorLocY));
    float distSqD = actorLocY.GetDistSq(&targetLocX);
    bool tooFar4 = distSqD > m_fMaxRange * m_fMaxRange;
    bool tooClose4 = distSqD < m_fMinRange * m_fMinRange;
    bool veryFar5 = distSqD > m_fFarRange * m_fFarRange;

    switch (m_iFadeIndex)
    {
    case 0:
        reinterpret_cast<::FUN_008d7f40_shell *>(&(m_timer20))->FUN_008d7f40(::RandomFloat(::DAT_0101e2bc, ::fnv_00c88020::DAT_01016248));
        m_iFadeIndex = 1;
        break;
    case 1:
    case 2: {
        if (reinterpret_cast<::FUN_00435e00_t *>((void *)&(const ::fnv_009d3b80::Stamp &)((*(::fnv_009d3b80::Stamp *)(reinterpret_cast<::FUN_0097fb00_cls *>((ctrlD))->GetValue98({})))))->FUN_00435e00() > ::DAT_01011588 && distSqD < DAT_01091138 &&
            reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>((ctrlD))->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(&targetLocX)), 1, 0))
        {
            PathRequest req;
            reinterpret_cast<::ActorStandIn *>((actorZ))->BuildPathingRequest((::PathingRequest *)(::fnv_009d3b80::PathRequest *)(&req), (*(const ::NiPoint3 *)(((::fnv_009d3b80::NiPoint3 *)(new ((void *)&(targetLocX)) ::Vec3())))), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(targetLocX))->FUN_0084e3a0()))), ::DAT_01012054, (::PathingAvoidNodeArray *)(0));
            if (actorZ->StartPath(&req))
            {
                m_dest = targetLocX;
                reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(1);
                m_iFadeIndex = 5;
                return;
            }
        }
        if (m_bCovered)
        {
            if (reinterpret_cast<::FUN_00435e00_t *>(&(m_timer20))->FUN_00435e00() < ::DAT_01011588)
            {
                if (!::FUN_0097fb20((::CombatState *)(ctrlD)))
                {
                    m_bDodging = true;
                    m_bCovered = false;
                }
            }
            else
            {
                m_bCovered = false;
            }
        }
        if (m_bDodging)
        {
            if (reinterpret_cast<::TimeoutTimer *>(&(m_timer20))->CheckTimer() || reinterpret_cast<::FUN_00435e00_t *>(&(m_timer20))->FUN_00435e00() > ::g_01012070)
            {
                m_bCovered = false;
                m_bDodging = false;
                m_bDodgeWait = ::FUN_0097fb20((::CombatState *)(ctrlD));
                reinterpret_cast<::TimeoutTimer *>(&(m_timer28))->FUN_00910b10();
                PathRequest req2;
                reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actorZ))->PathToLocation((::fnv_008b3880::PathingRequest *)(::fnv_009d3b80::PathRequest *)(&req2), &m_dodgePos, (void *)(((int)(reinterpret_cast<::LowProcess *>((actorZ))->GetTarget()))), (void *)(((int)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actorZ))->FUN_00575d70()))), 0.0f, (::fnv_008b3880::PathingAvoidNodeArray *)(0));
                if (actorZ->StartPath(&req2))
                {
                    reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(1);
                    m_iFadeIndex = 7;
                    return;
                }
            }
        }
        if (tooFar4 || tooClose4)
        {
            float threshold = ::DAT_010162c0;
            if (tooFar4 && veryFar5)
            {
                threshold = ::DAT_0101e2bc;
            }
            if (reinterpret_cast<::TimeoutTimer *>(&(m_timer20))->CheckTimer() || threshold < reinterpret_cast<::FUN_00435e00_t *>(&(m_timer20))->FUN_00435e00())
            {
                if (reinterpret_cast<::Engage::Procedure *>(this)->CheckAndApply(veryFar5))
                {
                    if (tooFar4)
                    {
                        m_iFadeIndex = 3;
                    }
                    else
                    {
                        m_iFadeIndex = 4;
                    }
                    return;
                }
                if (!veryFar5)
                {
                    SearchRequest search;
                    float dodgeDist = ::RandomFloat(::DAT_0101e704, ::DAT_01032adc);
                    if (reinterpret_cast<::FUN_0099e190_cls *>((ctrlD))->SelectAndMoveToPoint((::MyMover *)(::fnv_009d3b80::SearchRequest *)(&search), tooFar4 ? 4 : 8, 0, dodgeDist, ::DAT_0104e0e8))
                    {
                        PathRequest req34;
                        reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actorZ))->PathToLocation((::fnv_008b3880::PathingRequest *)(::fnv_009d3b80::PathRequest *)(&req34), search.GetResult(), (void *)(((int)(reinterpret_cast<::LowProcess *>((actorZ))->GetTarget()))), (void *)(((int)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actorZ))->FUN_00575d70()))),
                                            ::g_011c9040_arg1, (::fnv_008b3880::PathingAvoidNodeArray *)(0));
                        RawPoint dir;
                        reinterpret_cast<::TaskQueueInterface *>((((::fnv_009d3b80::RawPoint *)(::GetOffsetC((int)&(req34))))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
                        reinterpret_cast<::FUN_006e2980_shell *>(&(req34))->FUN_006e2980((::NiPoint3 *)(::fnv_009d3b80::RawPoint *)(&dir), dodgeDist + ::DAT_010231d8);
                        if (!actorZ->StartPath(&req34))
                        {
                            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Cannot setup path to dodge location"));
                            return;
                        }
                        reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(1);
                        m_iFadeIndex = 6;
                        return;
                    }
                }
                else
                {
                    if (reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>((ctrlD))->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(&targetLocX)), 1, 0))
                    {
                        PathRequest req4;
                        reinterpret_cast<::ActorStandIn *>((actorZ))->BuildPathingRequest((::PathingRequest *)(::fnv_009d3b80::PathRequest *)(&req4), (*(const ::NiPoint3 *)(((::fnv_009d3b80::NiPoint3 *)(new ((void *)&(targetLocX)) ::Vec3())))), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(targetLocX))->FUN_0084e3a0()))), ::DAT_0101e704,
                                            (::PathingAvoidNodeArray *)(0));
                        if (!actorZ->StartPath(&req4))
                        {
                            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Cannot setup path to target location"));
                            return;
                        }
                        m_dest = targetLocX;
                        reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(3);
                        m_iFadeIndex = 8;
                        return;
                    }
                    else
                    {
                        int coordX3 = 0;
                        int coordY = 0;
                        reinterpret_cast<::FUN_00527990_shell *>(&(targetLocX))->FUN_00527990(&coordX3, &coordY);
                        NiPoint3 navPos3;
                        if (::Pathing::FindClosestPathingPoint((::TESWorldSpace *)(coordY), (::TESObjectCELL *)(coordX3), (*(const ::NiPoint3 *)(((::fnv_009d3b80::NiPoint3 *)(new ((void *)&(targetLocX)) ::Vec3())))), (::NiPoint3 *)(::fnv_009d3b80::NiPoint3 *)(&navPos3)))
                        {
                            if (ctrlD->CanReachPos(&navPos3, ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(targetLocX))->FUN_0084e3a0())), 1, 0))
                            {
                                PathRequest req5;
                                reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actorZ))->PathToLocation((::fnv_008b3880::PathingRequest *)(::fnv_009d3b80::PathRequest *)(&req5), &navPos3, (void *)(coordX3), (void *)(coordY), ::DAT_0101e704, (::fnv_008b3880::PathingAvoidNodeArray *)(0));
                                if (!actorZ->StartPath(&req5))
                                {
                                    reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Cannot setup path to target location"));
                                    return;
                                }
                                reinterpret_cast<::fnv_0098ddd0::FUN_0098ddd0_shell *>(&(m_dest))->FUN_0098ddd0(&navPos3);
                                reinterpret_cast<::FUN_0041fd00_shell *>(&(m_dest))->FUN_0041fd00((int)(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(targetLocX))->FUN_0084e3a0()))));
                                reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(3);
                                m_iFadeIndex = 8;
                                return;
                            }
                        }
                    }
                }
            }
        }
        if (reinterpret_cast<::TimeoutTimer *>(&(m_timer20))->CheckTimer())
        {
            bool canDodge = true;
            if (!((::fnv_009d3b80::ProcessObj *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actorZ))->GetBaseTexture()))->CheckFlag(5) || !((::fnv_009d3b80::ProcessObj *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actorZ))->GetBaseTexture()))->CheckFlag(6))
            {
                canDodge = false;
            }
            if (canDodge && !::RandomBoolean(::DAT_0101622c))
            {
                float dist = 0.0f;
                m_bDodgeWait = ::FUN_0097fb20((::CombatState *)(ctrlD));
                if (m_bDodgeWait)
                {
                    dist = ::RandomFloat(::DAT_0101e704, ::DAT_01050b98);
                }
                else
                {
                    dist = ::RandomFloat(::DAT_0101e6ec, ::runtimeFloatSettingDefault548);
                }
                reinterpret_cast<::TimeoutTimer *>(&(m_timer28))->FUN_00910b10();
                SearchRequest search2;
                if (reinterpret_cast<::FUN_0099e190_cls *>((ctrlD))->SelectAndMoveToPoint((::MyMover *)(::fnv_009d3b80::SearchRequest *)(&search2), 3, 0, dist, ::DAT_0104e0e8))
                {
                    PathRequest req62;
                    reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actorZ))->PathToLocation((::fnv_008b3880::PathingRequest *)(::fnv_009d3b80::PathRequest *)(&req62), search2.GetResult(), (void *)(((int)(reinterpret_cast<::LowProcess *>((actorZ))->GetTarget()))), (void *)(((int)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actorZ))->FUN_00575d70()))),
                                        ::g_011c9040_arg1, (::fnv_008b3880::PathingAvoidNodeArray *)(0));
                    RawPoint dir2;
                    reinterpret_cast<::TaskQueueInterface *>((((::fnv_009d3b80::RawPoint *)(::GetOffsetC((int)&(req62))))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
                    reinterpret_cast<::FUN_006e2980_shell *>(&(req62))->FUN_006e2980((::NiPoint3 *)(::fnv_009d3b80::RawPoint *)(&dir2), dist + ::DAT_010231d8);
                    if (!actorZ->StartPath(&req62))
                    {
                        reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)("Cannot setup path to dodge location"));
                        return;
                    }
                    m_bCovered = true;
                    m_dodgePos = *actorZ->GetLookPos();
                    reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(1);
                    m_iFadeIndex = 7;
                    return;
                }
            }
            if (reinterpret_cast<::FUN_009d4f50_cls *>(this)->FUN_009d4f50())
            {
                bool moving = reinterpret_cast<::Actor *>((actorZ))->IsSneaking();
                if (moving)
                {
                    if (::RandomBoolean(::fnv_00c88020::DAT_01016248))
                    {
                        m_iFadeIndex = 2;
                    }
                    else
                    {
                        reinterpret_cast<::fnv_00996e40::FUN_00996e40_shell *>(this)->FUN_00996e40();
                        m_iFadeIndex = 1;
                    }
                }
                else
                {
                    reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(2);
                    m_iFadeIndex = 2;
                }
            }
            else
            {
                m_iFadeIndex = 1;
            }
            reinterpret_cast<::FUN_008d7f40_shell *>(&(m_timer20))->FUN_008d7f40(::RandomFloat(::DAT_010162c0, ::DAT_0101712c));
        }
    }
    break;
    case 6:
    case 7:
        m_bDodging = false;
        if (reinterpret_cast<::FUN_008b3b90_shell *>((actorZ))->FUN_008b3b90())
        {
            if (!reinterpret_cast<::FUN_008b3960_Class *>((actorZ))->FUN_008b3960())
            {
                reinterpret_cast<::FUN_009d4f30_shell *>((ctrlD))->SetByteAtOffset188ToFF();
            }
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(reinterpret_cast<::FUN_008b3960_Class *>((actorZ))->FUN_008b3960() ? "Pathing failed while dodging" : "Path Building failed to dodge"));
            return;
        }
        if (m_iFadeIndex == 7)
        {
            if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(m_timer28))->FUN_0097fa50())
            {
                if (m_bDodgeWait && !::FUN_0097fb20((::CombatState *)(ctrlD)))
                {
                    reinterpret_cast<::FUN_008d7f40_shell *>(&(m_timer28))->FUN_008d7f40(::fnv_00c88020::DAT_01016248);
                }
            }
            else if (reinterpret_cast<::TimeoutTimer *>(&(m_timer28))->CheckTimer())
            {
                reinterpret_cast<::FUN_008b3ab0_shell *>((actorZ))->FUN_008b3ab0();
                m_bDodgeWait = false;
                reinterpret_cast<::TimeoutTimer *>(&(m_timer28))->FUN_00910b10();
            }
        }
        if (((bool)(reinterpret_cast<::TeleportableReference *>((actorZ))->GetTeleportDestinationForm())))
        {
            if (reinterpret_cast<::FUN_009d4f50_cls *>(this)->FUN_009d4f50() && ::RandomBoolean(::fnv_00c88020::DAT_01016248))
            {
                reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(2);
                m_iFadeIndex = 2;
            }
            else
            {
                m_iFadeIndex = 1;
            }
            reinterpret_cast<::FUN_008d7f40_shell *>(&(m_timer20))->FUN_008d7f40(::RandomFloat(::DAT_010162c0, ::DAT_0101712c));
        }
        break;
    case 3:
    case 4:
    case 5:
    case 8: {
        m_bDodging = false;
        bool done = false;
        bool fallback = false;
        if (reinterpret_cast<::FUN_008b3b90_shell *>((actorZ))->FUN_008b3b90())
        {
            if (!reinterpret_cast<::FUN_008b3960_Class *>((actorZ))->FUN_008b3960())
            {
                if (m_iFadeIndex == 4 || m_iFadeIndex == 3)
                {
                    m_stamp60 = ::FUN_00435dd0();
                    done = true;
                }
                else
                {
                    reinterpret_cast<::fnv_009a0ec0::FUN_009a0ec0_shell *>((ctrlD))->SetNodeBlockAndTimestamp((const ::fnv_009a0ec0::FUN_009a0ec0_Block *)(::fnv_009d3b80::Location *)(&m_dest));
                    if (m_iFadeIndex == 8)
                    {
                        done = true;
                    }
                }
            }
            if (!done)
            {
                switch (m_iFadeIndex)
                {
                case 8:
                    reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(reinterpret_cast<::FUN_008b3960_Class *>((actorZ))->FUN_008b3960() ? "Pathing failed while moving to target"
                                                : "Path Building failed to move to target"));
                    break;
                case 5:
                    reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(reinterpret_cast<::FUN_008b3960_Class *>((actorZ))->FUN_008b3960() ? "Pathing failed while approaching target"
                                                : "Path Building failed to approach target"));
                    break;
                case 3:
                    reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(reinterpret_cast<::FUN_008b3960_Class *>((actorZ))->FUN_008b3960() ? "Pathing failed while moving to optimal far location"
                                                : "Path Building failed to move to optimal far location"));
                    break;
                case 4:
                    reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((int)(reinterpret_cast<::FUN_008b3960_Class *>((actorZ))->FUN_008b3960() ? "Pathing failed while moving to optimal close location"
                                                : "Path Building failed to move to optimal close location"));
                    break;
                }
                return;
            }
        }
        if (!done)
        {
            switch (m_iFadeIndex)
            {
            case 8:
                if (::FUN_0097fb20((::CombatState *)(ctrlD)) && !veryFar5)
                {
                    done = true;
                }
                break;
            case 5:
                if (::FUN_0097fb20((::CombatState *)(ctrlD)))
                {
                    done = true;
                }
                break;
            case 3:
                if (distSqD < m_fMinRange * m_fMinRange)
                {
                    done = true;
                }
                break;
            }
        }
        if (m_iFadeIndex == 3 || m_iFadeIndex == 4)
        {
            if (!done && m_cFallback == 0 && !reinterpret_cast<::FUN_008b3bf0_shell *>((actorZ))->FUN_008b3bf0())
            {
                m_cFallback = 1;
                NiPoint3 fallbackPos;
                if (actorZ->GetFallbackPos(&fallbackPos))
                {
                    if (!ctrlD->CanReachPos(&fallbackPos, ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(actorLocY))->FUN_0084e3a0())), 0, 0))
                    {
                        m_cFallback = -1;
                    }
                    else if (!::FUN_009a7940((::SightReference *)(actorZ), (::SightReference *)(target), (*(const ::NiPoint3 *)(&fallbackPos)), (*(const ::NiPoint3 *)(target->GetLookPos())), 0, -1))
                    {
                        m_cFallback = -2;
                    }
                    if (m_cFallback < 0)
                    {
                        done = true;
                        fallback = true;
                        m_stamp60 = ::FUN_00435dd0();
                    }
                }
            }
            if (!done)
            {
                float moved = targetLocX.GetDistSq(&m_lastTarget);
                if ((changed || moved > ::DAT_0108e058) && reinterpret_cast<::Engage::Procedure *>(this)->CheckAndApply(veryFar5))
                {
                    return;
                }
            }
        }
        if (done)
        {
            if (fallback)
            {
                ::FUN_008b3ad0((void *)(actorZ));
            }
            else
            {
                reinterpret_cast<::FUN_008b3ab0_shell *>((actorZ))->FUN_008b3ab0();
            }
        }
        if (((bool)(reinterpret_cast<::TeleportableReference *>((actorZ))->GetTeleportDestinationForm())) || done)
        {
            if (reinterpret_cast<::FUN_009d4f50_cls *>(this)->FUN_009d4f50() && ::RandomBoolean(::fnv_00c88020::DAT_01016248))
            {
                reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(2);
                m_iFadeIndex = 2;
            }
            else
            {
                m_iFadeIndex = 1;
            }
            float delay = ::RandomFloat(::DAT_010162c0, ::DAT_0101712c);
            if (changed)
            {
                delay = ::DAT_01013ea4;
            }
            reinterpret_cast<::FUN_008d7f40_shell *>(&(m_timer20))->FUN_008d7f40(delay);
        }
    }
    break;
    }
}
}  // namespace fnv_009d3b80

struct FUN_009ca680
{
    virtual void v0();
    int unk04;
    int unk08;
    int unk0c;
    FUN_009ca680();
    ~FUN_009ca680();
};

struct FUN_00906f60
{
    int a, b;
    FUN_00906f60();
};

struct FUN_0097ee20_shell
{
    int data[4];
    FUN_0097ee20_shell()
    {
        reinterpret_cast<::FUN_0097ede0_cls *>(this)->FUN_0097ede0();
    }
};

struct FUN_00435de0_ctor
{
    int data[4];
    FUN_00435de0_ctor(float val);
};

struct NiPoint3_T
{
    float x, y, z;
};
extern float DAT_010914d0;

struct FUN_009d3a00 : public FUN_009ca680
{
    int unk10;
    float f14, f18, f1c;
    FUN_00906f60 m20;
    FUN_00906f60 m28;
    bool b30, b31, b32, b33;
    NiPoint3_T pt34;
    FUN_0097ee20_shell m40;
    FUN_0097ee20_shell m50;
    FUN_00435de0_ctor m60;

    FUN_009d3a00();
};

// Constructor for FUN_009d3a00 that initializes base class, member fields, and sets m60 to negative DAT_010914d0.
// @fnv 0x009d3a00
FUN_009d3a00::FUN_009d3a00()
    : FUN_009ca680(), unk10(0), f14(0.0f), f18(0.0f), f1c(0.0f), m20(), m28(), b30(false), b31(false), b32(false),
      b33(true), pt34((*reinterpret_cast<::NiPoint3_T *>((void *)&::NiPoint3::ZERO))), m40(), m50(), m60(-DAT_010914d0)
{}

#include "generated/data/fallout/ai/combat/combatprocedureengagetarget.inc"
