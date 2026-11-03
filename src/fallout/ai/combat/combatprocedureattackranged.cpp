
// src/fallout/ai/combat/combatprocedureattackranged.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureattackranged.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/combat_controller_fields.h"
#include <cstdint>
#include "fnv/decl/AngleView.h"
#include "fnv/decl/AnimSequenceStub.h"
#include "fnv/decl/BSAnimGroupSequence.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/CombatDialogueHandler.h"
#include "fnv/decl/CombatProcedureEx.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_004301b0_shell.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00497280_shell.h"
#include "fnv/decl/FUN_0051f5f0_shell.h"
#include "fnv/decl/FUN_00524b40_class.h"
#include "fnv/decl/FUN_005f3780_shell.h"
#include "fnv/decl/FUN_00639aa0_shell.h"
#include "fnv/decl/FUN_00645c40_Class.h"
#include "fnv/decl/FUN_00645c60_shell.h"
#include "fnv/decl/FUN_00645c80_Class.h"
#include "fnv/decl/FUN_0070f490_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00894900_shell.h"
#include "fnv/decl/FUN_008b3c90_class.h"
#include "fnv/decl/FUN_008d7f40_shell.h"
#include "fnv/decl/FUN_0097fa50_Class.h"
#include "fnv/decl/FUN_00980070_shell.h"
#include "fnv/decl/FUN_00981970_shell.h"
#include "fnv/decl/FUN_009865b0_shell.h"
#include "fnv/decl/FUN_00996de0_Class.h"
#include "fnv/decl/FUN_00996e00_shell.h"
#include "fnv/decl/FUN_00996ed0_shell.h"
#include "fnv/decl/FUN_00996ef0_shell.h"
#include "fnv/decl/FUN_009a5eb0_shell.h"
#include "fnv/decl/FUN_009ca6c0_class.h"
#include "fnv/decl/FUN_009caac0_shell.h"
#include "fnv/decl/FUN_009d1b10_shell.h"
#include "fnv/decl/FUN_009d1b30_class.h"
#include "fnv/decl/FUN_009d1b50_shell.h"
#include "fnv/decl/FUN_009d1b90_Class.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiTMapBase.h"
#include "fnv/decl/Pawn.h"
#include "fnv/decl/Standin77900.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESObjectACTI.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/ThreatManager.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008b3bd0__FUN_008b3bd0_shell.h"
#include "fnv/decl/fnv_0097cd10__CombatActionStandIn.h"
#include "fnv/decl/fnv_0097ee90__DummyInner.h"
#include "fnv/decl/fnv_00996ea0__MyProc.h"
#include "fnv/decl/fnv_00998980__FUN_00998980_shell.h"
#include "fnv/decl/fnv_0099abc0__FUN_0099abc0_This.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005f2000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_008b3000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_0097f000.h"
#include "fnv/symbols_009a6000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01090000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011f1000.h"
extern void* DAT_01090ed4;

struct FUN_009ca6c0_shell
{
    void FUN_009ca6c0();
};

struct FUN_009d0980_shell
{
    void FUN_009d0980();
};

void FUN_009ca6c0_shell::FUN_009ca6c0()
{}

// @fnv 0x009d0980
void FUN_009d0980_shell::FUN_009d0980()
{
    *(void**)this = &DAT_01090ed4;
    reinterpret_cast<::FUN_009ca6c0_class *>((((FUN_009ca6c0_shell*)this)))->FUN_009ca6c0();
}

struct FUN_009d09f0_shell
{
    void SetByteAtOffsetC6(char c);
};

// @fnv 0x009d09f0
void FUN_009d09f0_shell::SetByteAtOffsetC6(char acValue)
{
    ((char*)this)[0xc6] = acValue;
}

struct FUN_009d0a10_shell
{
    void SetByteAt142(unsigned char value);
};

// @fnv 0x009d0a10
void FUN_009d0a10_shell::SetByteAt142(unsigned char value)
{
    *(unsigned char*)((char*)this + 0x142) = value;
}

struct Actor;
class CombatProcedureAttackRanged
{
  public:
    void FUN_009d1dc0(Actor* apOpponent);
};

// @fnv 0x009d1dc0
void CombatProcedureAttackRanged::FUN_009d1dc0(Actor* apOpponent)
{
    reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((intptr_t)("Disarmed"));
}


struct FUN_009d0950_shell
{
    void* FUN_009d0950(unsigned int flags);
};

// Calls FUN_009d0980 on this, frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009d0950
void* FUN_009d0950_shell::FUN_009d0950(unsigned int flags)
{
    ((FUN_009d0980_shell*)this)->FUN_009d0980();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_009cc4d0_shell
{
};
struct CombatProcedure
{
};
struct FUN_009d1c30_shell
{
};
struct FUN_009d09a0_shell
{
    void FUN_009d09a0();
};
namespace fnv_009d2310 {
struct BGSSaveFormBuffer
{
};
struct CombatProcedure
{
};
struct FUN_009a5eb0_shell
{
};
struct CombatProcedureAttackRanged_shell : CombatProcedure
{
    void FUN_009d2310(BGSSaveFormBuffer* buffer);
};
// @fnv 0x009d2310
void CombatProcedureAttackRanged_shell::FUN_009d2310(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00996ed0_shell *>(this)->SaveToBuffer((::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<char*>(this) + 0x10, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<char*>(this) + 0x14, 12, 0);
    reinterpret_cast<::FUN_009a5eb0_shell *>((reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x20)))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>((reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x30)))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>((reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x40)))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>((reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x28)))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buffer));
    reinterpret_cast<::FUN_009a5eb0_shell *>((reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x38)))->FUN_009a5eb0((::BGSSaveFormBuffer *)(buffer));
}
}  // namespace fnv_009d2310

struct BGSLoadFormBuffer
{
    virtual unsigned char FUN_00996f80();
};
struct TimeoutTimer
{
    void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
public:
    float FUN_006b9130();
public:
    bool CheckTimer();
public:
    void FUN_00910b10();
};
struct CombatProcedure_Helper
{
};
struct CombatProcedureAttackRanged_LoadGame
{
    void FUN_009d23a0(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x009d23a0
void CombatProcedureAttackRanged_LoadGame::FUN_009d23a0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_00996ef0_shell *>((((CombatProcedure_Helper*)this)))->FUN_00996ef0(apLoadGameBuffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x10)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x14)), 0xc);
    ((TimeoutTimer*)((char*)this + 0x20))->LoadGame(apLoadGameBuffer);
    ((TimeoutTimer*)((char*)this + 0x30))->LoadGame(apLoadGameBuffer);
    ((TimeoutTimer*)((char*)this + 0x40))->LoadGame(apLoadGameBuffer);
    ((TimeoutTimer*)((char*)this + 0x28))->LoadGame(apLoadGameBuffer);
    if (apLoadGameBuffer->FUN_00996f80() >= 0xa)
        ((TimeoutTimer*)((char*)this + 0x38))->LoadGame(apLoadGameBuffer);
}

class D1C30Process
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void vfn288();
    virtual void vfn28C();
    virtual void vfn290();
    virtual void vfn294();
    virtual void vfn298();
    virtual void vfn29C();
    virtual void vfn2A0();
    virtual void vfn2A4();
    virtual void vfn2A8();
    virtual void vfn2AC();
    virtual void vfn2B0();
    virtual void vfn2B4();
    virtual void vfn2B8();
    virtual void vfn2BC();
    virtual void vfn2C0();
    virtual void vfn2C4();
    virtual void vfn2C8();
    virtual void vfn2CC();
    virtual void vfn2D0();
    virtual void vfn2D4();
    virtual void vfn2D8();
    virtual void vfn2DC();
    virtual void vfn2E0();
    virtual void vfn2E4();
    virtual void vfn2E8();
    virtual void vfn2EC();
    virtual void vfn2F0();
    virtual void vfn2F4();
    virtual void vfn2F8();
    virtual void vfn2FC();
    virtual void vfn300();
    virtual void vfn304();
    virtual void vfn308();
    virtual void vfn30C();
    virtual void vfn310();
    virtual void vfn314();
    virtual void vfn318();
    virtual void vfn31C();
    virtual void vfn320();
    virtual void vfn324();
    virtual void vfn328();
    virtual void vfn32C();
    virtual void vfn330();
    virtual void vfn334();
    virtual void vfn338();
    virtual void vfn33C();
    virtual void vfn340();
    virtual void vfn344();
    virtual void vfn348();
    virtual void vfn34C();
    virtual void vfn350();
    virtual void vfn354();
    virtual void vfn358();
    virtual void vfn35C();
    virtual void vfn360();
    virtual void vfn364();
    virtual void vfn368();
    virtual void vfn36C();
    virtual void vfn370();
    virtual void vfn374();
    virtual void vfn378();
    virtual void vfn37C();
    virtual void vfn380();
    virtual void vfn384();
    virtual void vfn388();
    virtual void vfn38C();
    virtual void vfn390();
    virtual void vfn394();
    virtual void vfn398();
    virtual void vfn39C();
    virtual void vfn3A0();
    virtual void vfn3A4();
    virtual void vfn3A8();
    virtual void vfn3AC();
    virtual void vfn3B0();
    virtual void vfn3B4();
    virtual void vfn3B8();
    virtual void vfn3BC();
    virtual void vfn3C0();
    virtual void vfn3C4();
    virtual void vfn3C8();
    virtual void vfn3CC();
    virtual void vfn3D0();
    virtual void vfn3D4();
    virtual void vfn3D8();
    virtual void vfn3DC();
    virtual void vfn3E0();
    virtual void vfn3E4();
    virtual void vfn3E8();
    virtual void vfn3EC();
    virtual void vfn3F0();
    virtual void vfn3F4();
    virtual void vfn3F8();
    virtual void vfn3FC();
    virtual void vfn400();
    virtual void vfn404();
    virtual void vfn408();
    virtual void vfn40C();
    virtual void vfn410();
    virtual void vfn414();
    virtual void vfn418();
    virtual void vfn41C();
    virtual void vfn420();
    virtual void vfn424();
    virtual void vfn428();
    virtual void vfn42C();
    virtual void vfn430();
    virtual void SetFlagA(int iValue);
    virtual void vfn438();
    virtual void vfn43C();
    virtual void vfn440();
    virtual void vfn444();
    virtual void vfn448();
    virtual void vfn44C();
    virtual void vfn450();
    virtual void vfn454();
    virtual void vfn458();
    virtual void vfn45C();
    virtual void vfn460();
    virtual void vfn464();
    virtual void vfn468();
    virtual void vfn46C();
    virtual void vfn470();
    virtual void vfn474();
    virtual void vfn478();
    virtual void vfn47C();
    virtual void vfn480();
    virtual void vfn484();
    virtual void vfn488();
    virtual void vfn48C();
    virtual void vfn490();
    virtual void vfn494();
    virtual void vfn498();
    virtual void vfn49C();
    virtual void vfn4A0();
    virtual void vfn4A4();
    virtual void vfn4A8();
    virtual void vfn4AC();
    virtual void vfn4B0();
    virtual void vfn4B4();
    virtual void vfn4B8();
    virtual void vfn4BC();
    virtual void vfn4C0();
    virtual void vfn4C4();
    virtual void vfn4C8();
    virtual void vfn4CC();
    virtual void vfn4D0();
    virtual void vfn4D4();
    virtual void vfn4D8();
    virtual void vfn4DC();
    virtual void vfn4E0();
    virtual void vfn4E4();
    virtual void vfn4E8();
    virtual void vfn4EC();
    virtual void vfn4F0();
    virtual void vfn4F4();
    virtual void vfn4F8();
    virtual void vfn4FC();
    virtual void vfn500();
    virtual void vfn504();
    virtual void vfn508();
    virtual void vfn50C();
    virtual void vfn510();
    virtual void vfn514();
    virtual void vfn518();
    virtual void vfn51C();
    virtual void vfn520();
    virtual void vfn524();
    virtual void vfn528();
    virtual void vfn52C();
    virtual void vfn530();
    virtual void vfn534();
    virtual void vfn538();
    virtual void vfn53C();
    virtual void vfn540();
    virtual void vfn544();
    virtual void vfn548();
    virtual void vfn54C();
    virtual void vfn550();
    virtual void vfn554();
    virtual void vfn558();
    virtual void vfn55C();
    virtual void vfn560();
    virtual void vfn564();
    virtual void vfn568();
    virtual void vfn56C();
    virtual void vfn570();
    virtual void vfn574();
    virtual void vfn578();
    virtual void vfn57C();
    virtual void vfn580();
    virtual void vfn584();
    virtual void vfn588();
    virtual void vfn58C();
    virtual void vfn590();
    virtual void vfn594();
    virtual void vfn598();
    virtual void vfn59C();
    virtual void vfn5A0();
    virtual void vfn5A4();
    virtual void vfn5A8();
    virtual void vfn5AC();
    virtual void vfn5B0();
    virtual void vfn5B4();
    virtual void vfn5B8();
    virtual void vfn5BC();
    virtual void vfn5C0();
    virtual void vfn5C4();
    virtual void vfn5C8();
    virtual void vfn5CC();
    virtual void vfn5D0();
    virtual void vfn5D4();
    virtual void vfn5D8();
    virtual void vfn5DC();
    virtual void vfn5E0();
    virtual void vfn5E4();
    virtual void vfn5E8();
    virtual void vfn5EC();
    virtual void vfn5F0();
    virtual void vfn5F4();
    virtual void vfn5F8();
    virtual void vfn5FC();
    virtual void vfn600();
    virtual void vfn604();
    virtual void vfn608();
    virtual void vfn60C();
    virtual void vfn610();
    virtual void vfn614();
    virtual void vfn618();
    virtual void vfn61C();
    virtual void vfn620();
    virtual void vfn624();
    virtual void vfn628();
    virtual void vfn62C();
    virtual void vfn630();
    virtual void vfn634();
    virtual void vfn638();
    virtual void vfn63C();
    virtual void vfn640();
    virtual void vfn644();
    virtual void vfn648();
    virtual void vfn64C();
    virtual void vfn650();
    virtual void vfn654();
    virtual void vfn658();
    virtual void vfn65C();
    virtual void vfn660();
    virtual void vfn664();
    virtual void vfn668();
    virtual void vfn66C();
    virtual void vfn670();
    virtual void vfn674();
    virtual void vfn678();
    virtual void vfn67C();
    virtual void vfn680();
    virtual void vfn684();
    virtual void vfn688();
    virtual void vfn68C();
    virtual void vfn690();
    virtual void vfn694();
    virtual void vfn698();
    virtual void vfn69C();
    virtual void vfn6A0();
    virtual void vfn6A4();
    virtual void vfn6A8();
    virtual void vfn6AC();
    virtual void vfn6B0();
    virtual void vfn6B4();
    virtual void vfn6B8();
    virtual void vfn6BC();
    virtual void vfn6C0();
    virtual void vfn6C4();
    virtual void vfn6C8();
    virtual void vfn6CC();
    virtual void vfn6D0();
    virtual void vfn6D4();
    virtual void vfn6D8();
    virtual void vfn6DC();
    virtual void SetFlagB(int iValue);
};

class D1C30Actor
{
  public:
};

class D1C30Owner
{
  public:
};

class D1C30Helper
{
  public:
};

class D1C30Task
{
  public:
    void ResetTask();

    int unk00;
    D1C30Owner* m_pkOwnerManager;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    D1C30Helper m_kHelper;
};
// @fnv 0x009d09a0
void FUN_009d09a0_shell::FUN_009d09a0()
{
    Actor* pattacker;
    pattacker = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>((((FUN_009cc4d0_shell*)this)))->FUN_00996de0()));
    reinterpret_cast<::fnv_00996ea0::MyProc *>((((CombatProcedure*)this)))->FUN_00996ea0();
    ((FUN_009d0a10_shell*)*(void**)((char*)this + 4))->SetByteAt142(0);
    reinterpret_cast<::D1C30Task *>((((FUN_009d1c30_shell*)this)))->ResetTask();
    ((FUN_009d09f0_shell*)*(void**)((char*)this + 4))->SetByteAtOffsetC6(-1);
}

// @fnv 0x009d1c30
void D1C30Task::ResetTask()
{
    D1C30Actor* pkActor = ((::D1C30Actor *)(reinterpret_cast<CombatControllerFields*>(m_pkOwnerManager)->pActor));
    ((::D1C30Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkActor))->GetBaseTexture()))->SetFlagB(0);
    ((::D1C30Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkActor))->GetBaseTexture()))->SetFlagA(0);
    reinterpret_cast<::TimeoutTimer *>(&(m_kHelper))->FUN_00910b10();
}

struct FUN_009d1d30_Vec3
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};

class FUN_009d1d30_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int m_10;
    FUN_009d1d30_Vec3 m_14;

    FUN_009d1d30_Vec3* GetTrajectory(FUN_009d1d30_Vec3* apOut, unsigned int auiArg);
    bool GetVec3(FUN_009d1d30_Vec3* apDst, unsigned int auiArg);
};

// Writes m_14 to apDst when m_10 is 3, or recomputes m_14 via GetTrajectory for m_10 1 or 2, returning false otherwise.
// @fnv 0x009d1d30
bool FUN_009d1d30_cls::GetVec3(FUN_009d1d30_Vec3* apDst, unsigned int auiArg)
{
    switch (m_10)
    {
    case 3:
        *apDst = m_14;
        return true;
    case 1:
    case 2: {
        FUN_009d1d30_Vec3 vecTmp;
        m_14 = *GetTrajectory(&vecTmp, auiArg);
        *apDst = m_14;
        return true;
    }
    default:
        return false;
    }
}


struct Actor;

struct Sub14
{
};

struct Target
{
};

struct Holder04
{
};


struct FUN_009d1de0_cls
{
    int unk00;
    Holder04* m_04;
    int unk08;
    int unk0C;
    int unk10;
    Sub14 m_14;

    bool FUN_009d1de0();
};

// @fnv 0x009d1de0
bool FUN_009d1de0_cls::FUN_009d1de0()
{
    if (((unsigned char)(reinterpret_cast<::NiPoint3 *>(&(m_14))->FUN_004390c0((*(const ::NiPoint3 *)(&(*reinterpret_cast<char *>((void *)&::NiPoint3::ZERO))))))) != 0)
    {
        return false;
    }
    Actor* actor = ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    Target* target = ((::Target *)(::FUN_007031c0((intptr_t)(m_04))));
    float f2 = FUN_00404010(reinterpret_cast<::FUN_009d1b10_shell *>((target))->GetTarget(), DAT_0101e580) * ::DAT_01023128;
    float fX = f2;
    bool r9 = ::IsWithinAimLimits((::S_009a6d70_Actor *)(actor), (::NiPoint3 *)(void *)(&m_14), f2, fX);
    return r9;
}

struct RPoint
{
    float x, y, z;
    float Heading();
    RPoint operator-(const RPoint&) const;
};
struct RAngle
{
    float radians;
    float Heading();
};
struct RAnimation;
struct RActor;
struct RProcess
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual int AttackState();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual bool IsReady();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual void slot42c();
    virtual void slot430();
    virtual void slot434();
    virtual unsigned char AttackFlag(RActor*);
    virtual void SetAttackFlag(unsigned char);
};
struct RActor
{

    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActor();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual RAnimation* GetAnimation();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual RPoint* GetPosition();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual bool IsDead(int);
};
struct RGroup
{
};
struct RSequence
{
};
struct RSequenceBase
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual RSequence* GetControllerSequence(int);
};

struct RMap
{
};
struct RAnimation
{
};
struct RProjectile
{
};
struct RWeaponInfo
{
};
struct RWeapon
{
};
struct RTuning
{
};
struct RState
{
    RAngle AimDirection();
};
struct RContext
{
};
struct RTimer
{
    float time;
    int state;
};
struct RManager
{
};
struct RWorld
{
};
struct RSetting
{
};
int __cdecl GetType(unsigned short);
float __cdecl DirectionLength(RPoint*);
void __cdecl MuzzlePosition(RPoint*, RActor*);
float __cdecl ShotTravel(RWeaponInfo*, RPoint, RPoint, int, float);
struct RAttack
{
    int unk00;
    RContext* context;
    int unk08;
    int unk0c;
    int state;
    RPoint aim;
    RTimer blocked, burst, pause, shot, retry;
    void UpdateAttack();
};
struct RHitPoint : RPoint
{
    RHitPoint();
};
class Process9D1
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void vfn288();
    virtual void vfn28C();
    virtual void vfn290();
    virtual void vfn294();
    virtual void vfn298();
    virtual void vfn29C();
    virtual void vfn2A0();
    virtual void vfn2A4();
    virtual void vfn2A8();
    virtual void vfn2AC();
    virtual void vfn2B0();
    virtual void vfn2B4();
    virtual void vfn2B8();
    virtual void vfn2BC();
    virtual void vfn2C0();
    virtual void vfn2C4();
    virtual void vfn2C8();
    virtual void vfn2CC();
    virtual void vfn2D0();
    virtual void vfn2D4();
    virtual void vfn2D8();
    virtual void vfn2DC();
    virtual void vfn2E0();
    virtual void vfn2E4();
    virtual void vfn2E8();
    virtual void vfn2EC();
    virtual void vfn2F0();
    virtual void vfn2F4();
    virtual void vfn2F8();
    virtual void vfn2FC();
    virtual void vfn300();
    virtual void vfn304();
    virtual void vfn308();
    virtual void vfn30C();
    virtual void vfn310();
    virtual void vfn314();
    virtual void vfn318();
    virtual void vfn31C();
    virtual void vfn320();
    virtual void vfn324();
    virtual void vfn328();
    virtual void vfn32C();
    virtual void vfn330();
    virtual void vfn334();
    virtual void vfn338();
    virtual void vfn33C();
    virtual void vfn340();
    virtual void vfn344();
    virtual void vfn348();
    virtual void vfn34C();
    virtual void vfn350();
    virtual void vfn354();
    virtual void vfn358();
    virtual void vfn35C();
    virtual void vfn360();
    virtual void vfn364();
    virtual void vfn368();
    virtual void vfn36C();
    virtual void vfn370();
    virtual void vfn374();
    virtual void vfn378();
    virtual void vfn37C();
    virtual void vfn380();
    virtual void vfn384();
    virtual void vfn388();
    virtual void vfn38C();
    virtual void vfn390();
    virtual void vfn394();
    virtual void vfn398();
    virtual void vfn39C();
    virtual void vfn3A0();
    virtual void vfn3A4();
    virtual void vfn3A8();
    virtual void vfn3AC();
    virtual void vfn3B0();
    virtual void vfn3B4();
    virtual void vfn3B8();
    virtual void vfn3BC();
    virtual void vfn3C0();
    virtual void vfn3C4();
    virtual void vfn3C8();
    virtual void vfn3CC();
    virtual void vfn3D0();
    virtual void vfn3D4();
    virtual void vfn3D8();
    virtual void vfn3DC();
    virtual void vfn3E0();
    virtual void vfn3E4();
    virtual void vfn3E8();
    virtual void vfn3EC();
    virtual void vfn3F0();
    virtual void vfn3F4();
    virtual void vfn3F8();
    virtual void vfn3FC();
    virtual void vfn400();
    virtual void vfn404();
    virtual void vfn408();
    virtual void vfn40C();
    virtual void vfn410();
    virtual void vfn414();
    virtual void vfn418();
    virtual void vfn41C();
    virtual void vfn420();
    virtual void vfn424();
    virtual void vfn428();
    virtual void vfn42C();
    virtual void vfn430();
    virtual void SetUpdateFlag(int iFlag);
    virtual void vfn438();
    virtual void vfn43C();
    virtual void vfn440();
    virtual void vfn444();
    virtual void vfn448();
    virtual void vfn44C();
    virtual void vfn450();
    virtual void vfn454();
    virtual void vfn458();
    virtual void vfn45C();
    virtual void vfn460();
    virtual void vfn464();
    virtual void vfn468();
    virtual void vfn46C();
    virtual void vfn470();
    virtual void vfn474();
    virtual void vfn478();
    virtual void vfn47C();
    virtual void vfn480();
    virtual void vfn484();
    virtual void vfn488();
    virtual void vfn48C();
    virtual void vfn490();
    virtual void vfn494();
    virtual void vfn498();
    virtual void vfn49C();
    virtual void vfn4A0();
    virtual void vfn4A4();
    virtual void vfn4A8();
    virtual void vfn4AC();
    virtual void vfn4B0();
    virtual void vfn4B4();
    virtual void vfn4B8();
    virtual void vfn4BC();
    virtual void vfn4C0();
    virtual void vfn4C4();
    virtual void vfn4C8();
    virtual void vfn4CC();
    virtual void vfn4D0();
    virtual void vfn4D4();
    virtual void vfn4D8();
    virtual void vfn4DC();
    virtual void vfn4E0();
    virtual void vfn4E4();
    virtual void vfn4E8();
    virtual void vfn4EC();
    virtual void vfn4F0();
    virtual void vfn4F4();
    virtual void vfn4F8();
    virtual void vfn4FC();
    virtual void vfn500();
    virtual void vfn504();
    virtual void vfn508();
    virtual void vfn50C();
    virtual void vfn510();
    virtual void vfn514();
    virtual void vfn518();
    virtual void vfn51C();
    virtual void vfn520();
    virtual void vfn524();
    virtual void vfn528();
    virtual void vfn52C();
    virtual void vfn530();
    virtual void vfn534();
    virtual void vfn538();
    virtual void vfn53C();
    virtual void vfn540();
    virtual void vfn544();
    virtual void vfn548();
    virtual void vfn54C();
    virtual void vfn550();
    virtual void vfn554();
    virtual void vfn558();
    virtual void vfn55C();
    virtual void vfn560();
    virtual void vfn564();
    virtual void vfn568();
    virtual void vfn56C();
    virtual void vfn570();
    virtual void vfn574();
    virtual void vfn578();
    virtual void vfn57C();
    virtual void vfn580();
    virtual void vfn584();
    virtual void vfn588();
    virtual void vfn58C();
    virtual void vfn590();
    virtual void vfn594();
    virtual void vfn598();
    virtual void vfn59C();
    virtual void vfn5A0();
    virtual void vfn5A4();
    virtual void vfn5A8();
    virtual void vfn5AC();
    virtual void vfn5B0();
    virtual void vfn5B4();
    virtual void vfn5B8();
    virtual void vfn5BC();
    virtual void vfn5C0();
    virtual void vfn5C4();
    virtual void vfn5C8();
    virtual void vfn5CC();
    virtual void vfn5D0();
    virtual void vfn5D4();
    virtual void vfn5D8();
    virtual void vfn5DC();
    virtual void vfn5E0();
    virtual void vfn5E4();
    virtual void vfn5E8();
    virtual void vfn5EC();
    virtual void vfn5F0();
    virtual void vfn5F4();
    virtual void vfn5F8();
    virtual void vfn5FC();
    virtual void vfn600();
    virtual void vfn604();
    virtual void vfn608();
    virtual void vfn60C();
    virtual void vfn610();
    virtual void vfn614();
    virtual void vfn618();
    virtual void vfn61C();
    virtual void vfn620();
    virtual void vfn624();
    virtual void vfn628();
    virtual void vfn62C();
    virtual void vfn630();
    virtual void vfn634();
    virtual void vfn638();
    virtual void vfn63C();
    virtual void vfn640();
    virtual void vfn644();
    virtual void vfn648();
    virtual void vfn64C();
    virtual void vfn650();
    virtual void vfn654();
    virtual void vfn658();
    virtual void vfn65C();
    virtual void vfn660();
    virtual void vfn664();
    virtual void vfn668();
    virtual void vfn66C();
    virtual void vfn670();
    virtual void vfn674();
    virtual void vfn678();
    virtual void vfn67C();
    virtual void vfn680();
    virtual void vfn684();
    virtual void vfn688();
    virtual void vfn68C();
    virtual void vfn690();
    virtual void vfn694();
    virtual void vfn698();
    virtual void vfn69C();
    virtual void vfn6A0();
    virtual void vfn6A4();
    virtual void vfn6A8();
    virtual void vfn6AC();
    virtual void vfn6B0();
    virtual void vfn6B4();
    virtual void vfn6B8();
    virtual void vfn6BC();
    virtual void vfn6C0();
    virtual void vfn6C4();
    virtual void vfn6C8();
    virtual void vfn6CC();
    virtual void vfn6D0();
    virtual void vfn6D4();
    virtual void vfn6D8();
    virtual void vfn6DC();
    virtual void SetActive(bool bActive);
};

class Actor9D1
{
  public:
};

class Mobile9D1
{
  public:
};

class Timer9D1
{
  public:
};

class Controller9D1
{
  public:
    void FUN_009d1bc0(bool bActive);

    void* m_ppVirtualMethodTable;
    Mobile9D1* m_pkMobile;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    Timer9D1 m_kTimer;
};

// Sets the mobile actor's process active state, sets update flag 1, and resets the timer.
// @fnv 0x009d1bc0
void Controller9D1::FUN_009d1bc0(bool bActive)
{
    Actor9D1* pkActor = ((::Actor9D1 *)(reinterpret_cast<CombatControllerFields*>(m_pkMobile)->pActor));
    ((::Process9D1 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkActor))->GetBaseTexture()))->SetActive(bActive);
    ((::Process9D1 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pkActor))->GetBaseTexture()))->SetUpdateFlag(1);
    reinterpret_cast<::TimeoutTimer *>(&(m_kTimer))->FUN_00910b10();
}

class FUN_009d0890_base
{
  public:
    virtual ~FUN_009d0890_base();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    FUN_009d0890_base();
};

struct FUN_00906f60
{
    unsigned int m_00;
    unsigned int m_04;
    FUN_00906f60();
};

struct FUN_009d0890_Vec3
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

class FUN_009d0890 : public FUN_009d0890_base
{
  public:
    virtual ~FUN_009d0890();
    unsigned int m_10;
    FUN_009d0890_Vec3 m_14;
    FUN_00906f60 m_20;
    FUN_00906f60 m_28;
    FUN_00906f60 m_30;
    FUN_00906f60 m_38;
    FUN_00906f60 m_40;

    FUN_009d0890();
};

// Initializes the base class, sets m_10 to 0, and copies a Vec3 from DAT_011f426c into m_14.
// @fnv 0x009d0890
FUN_009d0890::FUN_009d0890()
    : FUN_009d0890_base(), m_10(0), m_14(*reinterpret_cast<const FUN_009d0890_Vec3*>(&(*reinterpret_cast<char *>((void *)&::NiPoint3::ZERO))))
{}

struct RangedVec
{
    float x, y, z;
};
struct RangedTimer
{
    float start;
    float duration;
};
struct RangedActor
{
};
struct RangedDisplay
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void __cdecl Print(int, int, const char*, ...);
};
struct RangedSetting
{
};
void __cdecl FUN_009a88e0(RangedVec*, RangedActor*, RangedVec);
float __cdecl FUN_00408840(float);
struct RangedDebug
{
    int unk00;
    Holder04* owner;
    int unk08, unk0c;
    unsigned int state;
    RangedVec location;
    RangedTimer blocked, firing, cooldown, delay, suppress;
    void PrintDebugInfo(RangedDisplay*, int, int);
};
// Prints the ranged combat state, timer values, target location and weapon firing arc to the debug display.
// @fnv 0x009d1e80
void RangedDebug::PrintDebugInfo(RangedDisplay* display, int iX, int iY)
{
    RangedActor* actor = ((::RangedActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    switch (state)
    {
    case 0:
        display->Print(iX, iY, "IDLE");
        break;
    case 1:
        display->Print(iX, iY, "FIRING");
        if (reinterpret_cast<::FUN_0097fa50_Class *>(&(firing))->FUN_0097fa50())
            display->Print(iX, iY, "Firing Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(firing))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(firing))->FUN_006b9130());
        if (reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00())
            display->Print(iX, iY, "Target location: %.02f, %.02f, %.02f", location.x, location.y, location.z);
        if (!reinterpret_cast<::TimeoutTimer *>(&(delay))->CheckTimer())
            display->Print(iX, iY, "Firing Delay Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(delay))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(delay))->FUN_006b9130());
        break;
    case 2:
        display->Print(iX, iY, "COOLDOWN");
        display->Print(iX, iY, "Cooldown Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(cooldown))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(cooldown))->FUN_006b9130());
        break;
    case 3:
        display->Print(iX, iY, "SUPPRESSIVE_FIRE");
        display->Print(iX, iY, "Suppression location: %.02f, %.02f, %.02f", location.x, location.y, location.z);
        display->Print(iX, iY, "Suppressive Fire Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(suppress))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(suppress))->FUN_006b9130());
        if (!reinterpret_cast<::TimeoutTimer *>(&(delay))->CheckTimer())
            display->Print(iX, iY, "Firing Delay Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(delay))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(delay))->FUN_006b9130());
        break;
    }
    if (reinterpret_cast<::FUN_0097fa50_Class *>(&(blocked))->FUN_0097fa50())
        display->Print(iX, iY, "Explosive Projectile Blocked Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(blocked))->FUN_00435e00(),
                       reinterpret_cast<::TimeoutTimer *>(&(blocked))->FUN_006b9130());
    Target* target = ((::Target *)(::FUN_007031c0((intptr_t)(owner))));
    if (reinterpret_cast<::NiPlane *>(&(location))->operator==((*(const ::NiPlane *)(&(*reinterpret_cast<char *>((void *)&::NiPoint3::ZERO))))) && target && reinterpret_cast<::FUN_009d1b10_shell *>((target))->GetTarget() > 0.0)
    {
        RangedVec unused;
        FUN_009a88e0(&unused, actor, location);
        float limit = reinterpret_cast<::AngleView *>((actor))->GetAdjustedAngle();
        unused.z = ::WrapAngle(unused.z);
        float arc = 0.0f;
        float heading = FUN_00408840(FUN_004b15e0(limit, unused.z, &arc));
        float direction = reinterpret_cast<::FUN_009d1b10_shell *>((target))->GetTarget();
        if (!((unsigned char)(reinterpret_cast<::fnv_008b3bd0::FUN_008b3bd0_shell *>((actor))->FUN_008b3bd0())))
        {
            direction *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RangedSetting *>(&::originalRuntimeFloatSetting428))))));
            display->Print(iX, iY, "Weapon firing arc: ( %.2f/%.2f ) degrees (Stationary)",
                           heading * 2.0 * 57.2957763671875, direction);
        }
        else
        {
            display->Print(iX, iY, "Weapon firing arc: ( %.2f/%.2f ) degrees (Moving)",
                           heading * 2.0 * 57.2957763671875, direction);
        }
    }
}

struct Target2
{
};
struct Holder2
{
};
void __cdecl ComputeTrajectory(FUN_009d1d30_Vec3* apOut, Actor* apA, Actor* apB, unsigned int auiArg, int aiVal,
                               float afVal, int aiFlag);
struct CombatThing
{
    int unk00;
    Holder2* m_04;
    FUN_009d1d30_Vec3 GetTrajectory(uintptr_t auiArg);
};
// @fnv 0x009d0a30
void RAttack::UpdateAttack()
{
    RActor* actor = ((::RActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    RActor* target = ((::RActor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    RState* combat2 = ((::RState *)(reinterpret_cast<::InterfaceManager *>((context))->FUN_00586150()));
    RContext* allies8 = ((::RContext *)(reinterpret_cast<::EffectSetting *>((context))->GetCastSound()));
    unsigned int attack20 = 255;
    RWeapon* weapon0 = ((::RWeapon *)(::FUN_007031c0((intptr_t)(context))));
    RAnimation* animation0 = actor->GetAnimation();
    if (!weapon0 || !animation0 || !((::RWeaponInfo *)(reinterpret_cast<::Thing *>((weapon0))->GetOrFallback((intptr_t)(actor)))))
    {
        reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((intptr_t)("Missing either weapon, animation, or weapon projectile"));
        return;
    }
    float fov16 = reinterpret_cast<::FUN_00639aa0_shell *>((((::RTuning *)(reinterpret_cast<CombatControllerFields*>((context))->pCombatStyle))))->FUN_00639aa0();
    if (fov16 > 0.0 && target &&
        !::IsWithinAimLimits((::S_009a6d70_Actor *)(actor), (::NiPoint3 *)(::RPoint *)(target->GetPosition()), float(fov16 * 0.01745329238474369), 6.2831854820251465f))
    {
        reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((intptr_t)("Target outside targeting FOV"));
        return;
    }
    RWeaponInfo* info1 = ((::RWeaponInfo *)(reinterpret_cast<::Thing *>((weapon0))->GetOrFallback((intptr_t)(actor))));
    bool automatic77 = reinterpret_cast<::FUN_00524b40_class *>((weapon0))->FUN_00524b40();
    bool burstWeapon = automatic77 || reinterpret_cast<::FUN_00645c80_Class *>((weapon0))->IsFlagSet();
    bool tooClose34 = false;
    RPoint destination;
    reinterpret_cast<::CombatThing *>(this)->GetTrajectory((uintptr_t)(&destination));
    bool ready = ((::RProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->IsReady() || reinterpret_cast<::FUN_00894900_shell *>((actor))->FUN_00894900();
    if (((unsigned char)(reinterpret_cast<::FUN_00981970_shell *>((context))->FUN_00981970())))
        ready = false;
    if (state != 0 && !ready)
    {
        reinterpret_cast<::D1C30Task *>(this)->ResetTask();
        state = 0;
    }
    if (ready)
    {
        float minRange6 = 0.0f;
        float idealRange = 0.0f;
        float maxRange = 0.0f;
        ::FUN_009a9180((::S_009a9180_Actor *)(context), (::S_009a9180_Data *)(weapon0), &minRange6, &idealRange, &maxRange);
        RPoint targetPosition2 = destination;
        if (target)
            targetPosition2.z = target->GetPosition()->z;
        RPoint rangeDelta = targetPosition2 - *actor->GetPosition();
        float distance = reinterpret_cast<::TESCombatStyle *>((void *)&(rangeDelta))->UpdateCombatStyle();
        if (distance > maxRange * maxRange)
            ready = false;
        if (distance < minRange6 * minRange6)
            tooClose34 = true;
    }
    if (::FUN_0097fb20((::CombatState *)(combat2)))
        aim = destination;

    if (::FUN_0097fb20((::CombatState *)(combat2)) && reinterpret_cast<::fnv_0097ee90::DummyInner *>((combat2))->FUN_0097ee90() && ready)
    {
        switch (state)
        {
        case 1:
            if (burstWeapon)
            {
                if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(burst))->FUN_0097fa50() && reinterpret_cast<::CombatTargetTimestamp *>((void *)&(const ::RAngle &)(combat2->AimDirection()))->FUN_006a7f50() != -::DAT_01090e90)
                {
                    float duration1 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RSetting *>(&::g_011ceef0))))));
                    unsigned short group = reinterpret_cast<::FUN_004301b0_shell *>((animation0))->FUN_004301b0(4);
                    if (GetType(group) == 80 || GetType(group) == 86)
                    {
                        RSequenceBase* sequence;
                        if (reinterpret_cast<::NiTMapBase *>((((::RMap *)(reinterpret_cast<::FUN_00497280_shell *>((animation0))->GetFieldAt124()))))->Lookup(group, (::AnimSequenceBase *&)(sequence)))
                        {
                            RGroup* animGroup0 = ((::RGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((sequence->GetControllerSequence(-1)))->GetAnimGroup()));
                            float start = reinterpret_cast<::FUN_005f3780_shell *>((animGroup0))->FUN_005f3780(0);
                            float end = reinterpret_cast<::FUN_005f3780_shell *>((animGroup0))->FUN_005f3780(1);
                            duration1 += end - start;
                        }
                    }
                    reinterpret_cast<::FUN_008d7f40_shell *>(&(burst))->FUN_008d7f40(duration1);
                }
                if (reinterpret_cast<::FUN_0097fa50_Class *>(&(burst))->FUN_0097fa50() && reinterpret_cast<::TimeoutTimer *>(&(burst))->CheckTimer())
                {
                    reinterpret_cast<::D1C30Task *>(this)->ResetTask();
                    reinterpret_cast<::FUN_008d7f40_shell *>(&(pause))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RSetting *>(&::g_011cf21c)))))));
                    state = 2;
                }
            }
            break;
        case 2:
            if (reinterpret_cast<::TimeoutTimer *>(&(pause))->CheckTimer())
            {
                reinterpret_cast<::FUN_009d1b90_Class *>((combat2))->SetNegatedTimestamp();
                reinterpret_cast<::Controller9D1 *>(this)->FUN_009d1bc0(automatic77);
                state = 1;
            }
            break;
        default:
            reinterpret_cast<::TimeoutTimer *>(&(retry))->FUN_00910b10();
            reinterpret_cast<::Controller9D1 *>(this)->FUN_009d1bc0(automatic77);
            state = 1;
            break;
        }
    }
    else
    {
        switch (state)
        {
        case 1:
            reinterpret_cast<::Controller9D1 *>(this)->FUN_009d1bc0(automatic77);
            state = 3;
            reinterpret_cast<::FUN_008d7f40_shell *>(&(retry))->FUN_008d7f40(2.0f);
            break;
        case 2:
            if (reinterpret_cast<::TimeoutTimer *>(&(pause))->CheckTimer())
            {
                reinterpret_cast<::Controller9D1 *>(this)->FUN_009d1bc0(automatic77);
                state = 3;
                reinterpret_cast<::FUN_008d7f40_shell *>(&(retry))->FUN_008d7f40(2.0f);
            }
            break;
        case 3:
            if (reinterpret_cast<::TimeoutTimer *>(&(retry))->CheckTimer())
            {
                reinterpret_cast<::D1C30Task *>(this)->ResetTask();
                state = 0;
            }
            break;
        case 0:
            if (ready && !reinterpret_cast<::TimeoutTimer *>(&(retry))->CheckTimer())
            {
                reinterpret_cast<::Controller9D1 *>(this)->FUN_009d1bc0(automatic77);
                state = 3;
            }
            break;
        }
    }
    if (target && reinterpret_cast<::fnv_0097ee90::DummyInner *>((combat2))->FUN_0097ee90())
        reinterpret_cast<::CombatDialogueHandler *>(((*reinterpret_cast<::RManager * *>(&::CombatAssessment::DAT_011f1708))))->FUN_00983970((::CombatController *)(context), 2, 0, 0);
    bool close2 = false;
    if (target)
    {
        float nearRange = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RSetting *>(&::originalRuntimeFloatSetting387)))))) * reinterpret_cast<::MiddleHighProcess *>((weapon0))->GetLightIntensity();
        RPoint nearDelta20 = *actor->GetPosition() - *target->GetPosition();
        if (reinterpret_cast<::TESCombatStyle *>((void *)&(nearDelta20))->UpdateCombatStyle() > nearRange * nearRange)
            close2 = true;
    }
    reinterpret_cast<::FUN_009d09f0_shell *>((context))->SetByteAtOffsetC6(close2);
    if (reinterpret_cast<::FUN_009d1b10_shell *>((weapon0))->GetTarget() > 0.0)
    {
        float angle = float(reinterpret_cast<::FUN_009d1b10_shell *>((weapon0))->GetTarget() * 0.01745329238474369);
        if (!((unsigned char)(reinterpret_cast<::fnv_008b3bd0::FUN_008b3bd0_shell *>((actor))->FUN_008b3bd0())))
            angle *= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RSetting *>(&::originalRuntimeFloatSetting428))))));
        if (reinterpret_cast<::NiPlane *>(&(aim))->operator==((const ::NiPlane &)((*reinterpret_cast<::RPoint *>((void *)&::NiPoint3::ZERO)))) && ::IsWithinAimLimits((::S_009a6d70_Actor *)(actor), (::NiPoint3 *)(::RPoint *)(&aim), angle, ::DAT_01090e90))
            reinterpret_cast<::FUN_009d0a10_shell *>((context))->SetByteAt142(4);
        else
            reinterpret_cast<::FUN_009d0a10_shell *>((context))->SetByteAt142(0);
    }
    if (state == 0)
    {
        if (target && !::fnv_008b3c10::FUN_008b3c10((::fnv_008b3c10::CombatState *)(combat2)) && (::FUN_0097fb20((::CombatState *)(combat2)) || (reinterpret_cast<::fnv_00998980::FUN_00998980_shell *>((combat2))->FUN_00998980() && reinterpret_cast<::fnv_0097ee90::DummyInner *>((combat2))->FUN_0097ee90())))
        {
            if (reinterpret_cast<::NiPlane *>(&(aim))->operator==((const ::NiPlane &)((*reinterpret_cast<::RPoint *>((void *)&::NiPoint3::ZERO)))) || reinterpret_cast<::fnv_0099abc0::FUN_0099abc0_This *>((combat2))->UpdateLastSeenFiringLocation((*(::fnv_0099abc0::NiPoint3 *)(&aim))))
                reinterpret_cast<::CombatProcedureEx *>(this)->SetLookAtPoint((const ::NiPoint3 &)(aim), 2);
            else
                reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
        }
        else
            reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
        return;
    }
    if (reinterpret_cast<::NiPoint3 *>(&(aim))->FUN_004390c0((const ::NiPoint3 &)((*reinterpret_cast<::RPoint *>((void *)&::NiPoint3::ZERO)))))
        aim = destination;
    if (reinterpret_cast<::NiPlane *>(&(aim))->operator==((const ::NiPlane &)((*reinterpret_cast<::RPoint *>((void *)&::NiPoint3::ZERO)))))
        reinterpret_cast<::CombatProcedureEx *>(this)->SetLookAtPoint((const ::NiPoint3 &)(aim), 4);
    if (state == 2)
        return;
    if (!reinterpret_cast<::FUN_009d1de0_cls *>(this)->FUN_009d1de0() && !tooClose34)
        return;
    if (!reinterpret_cast<::TimeoutTimer *>(&(shot))->CheckTimer())
        return;
    bool fire24 = false;
    unsigned char attackFlag12 = 1;
    if (automatic77)
    {
        bool canAttack = true;
        attackFlag12 = ((::RProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->AttackFlag(actor);
        if (::FUN_005f25d0(reinterpret_cast<::FUN_004301b0_shell *>((animation0))->FUN_004301b0(4)))
        {
            int sequenceState = reinterpret_cast<::FUN_0070f490_Class *>((animation0))->GetSlotValue(4);
            if (sequenceState < 1 || sequenceState >= 2)
                canAttack = false;
        }
        if (canAttack && attackFlag12)
            fire24 = true;
    }
    else
    {
        switch (((::RProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->AttackState())
        {
        case 4:
            if (reinterpret_cast<::FUN_0070f490_Class *>((animation0))->GetSlotValue(4) == 3)
                fire24 = true;
            break;
        case -1:
            fire24 = true;
            break;
        }
    }
    if (!fire24)
        return;

    RHitPoint hitPoint2;
    RActor* hit16 = 0;
    RActor* hitActor9 = 0;
    float fraction41 = 0.0f;
    RPoint muzzle23;
    MuzzlePosition(&muzzle23, actor);
    bool collision25 = ::FUN_009a6e90(actor, info1, 0.0f, *(const ::NiPoint3 *)&(muzzle23), *(const ::NiPoint3 *)&(destination), (::NiPoint3 *)&hitPoint2, (void **)&hit16, &fraction41);
    if (collision25)
    {
        bool blockedShot = false;
        switch (state)
        {
        case 1:
            if (hit16 && hit16->IsActor())
            {
                hitActor9 = hit16;
                if (hitActor9 == ((::RActor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00())) || reinterpret_cast<::FUN_009865b0_shell *>((allies8))->FUN_009865b0((intptr_t)(hitActor9)))
                    blockedShot = true;
            }
            if (!blockedShot)
            {
                RProjectile* explosive = ((::RProjectile *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(info1))));
                if (explosive)
                {
                    RPoint hitDelta0 = hitPoint2 - destination;
                    float hitDistance = reinterpret_cast<::NiPoint3 *>(&(hitDelta0))->ComputeMagnitude();
                    if (hitDistance <= reinterpret_cast<::Standin77900 *>((explosive))->FUN_00477900())
                        blockedShot = true;
                }
            }
            break;
        case 3:
            if (!hit16 || !hit16->IsActor())
            {
                if (fraction41 > 0.5)
                    blockedShot = true;
            }
            else if (hit16 && hit16->IsActor() && !hit16->IsDead(0) && reinterpret_cast<::FUN_009865b0_shell *>((allies8))->FUN_009865b0((intptr_t)(hit16)))
                blockedShot = true;
            if (!blockedShot)
            {
                state = 0;
                reinterpret_cast<::D1C30Task *>(this)->ResetTask();
                reinterpret_cast<::TimeoutTimer *>(&(retry))->FUN_00910b10();
                return;
            }
            break;
        }
        if (blockedShot)
            reinterpret_cast<::fnv_0097cd10::CombatActionStandIn *>((((::RState *)(reinterpret_cast<::InterfaceManager *>((context))->FUN_00586150()))))->FUN_0097cd10(0);
        else
        {
            if (!((unsigned char)(reinterpret_cast<::FUN_008b3c90_class *>((((::RState *)(reinterpret_cast<::InterfaceManager *>((context))->FUN_00586150()))))->GetByteAtOffset114())))
                reinterpret_cast<::fnv_0097cd10::CombatActionStandIn *>((((::RState *)(reinterpret_cast<::InterfaceManager *>((context))->FUN_00586150()))))->FUN_0097cd10(1);
            return;
        }
    }
    RProjectile* projectile = ((::RProjectile *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(info1))));
    if (projectile)
    {
        RPoint impact = aim;
        if (collision25)
            impact = hitPoint2;
        float travel = ShotTravel(info1, muzzle23, impact, 0, 0.0f);
        if (!reinterpret_cast<::ThreatManager *>(((*reinterpret_cast<::RWorld * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->IsThreatWithinLimits((::ThreatActor *)(actor), (::ThreatActor *)(projectile), (*(const ::ThreatPosition *)(&impact)), travel))
        {
            fire24 = false;
            if (!reinterpret_cast<::FUN_0097fa50_Class *>(&(blocked))->FUN_0097fa50())
                reinterpret_cast<::FUN_008d7f40_shell *>(&(blocked))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RSetting *>(&::originalRuntimeFloatSetting358)))))));
            else if (reinterpret_cast<::TimeoutTimer *>(&(blocked))->CheckTimer())
                reinterpret_cast<::TESObjectACTI *>((((::RState *)(reinterpret_cast<::InterfaceManager *>((context))->FUN_00586150()))))->SetActivateSound((::TESSound *)(projectile));
        }
        else
        {
            reinterpret_cast<::TESObjectACTI *>((((::RState *)(reinterpret_cast<::InterfaceManager *>((context))->FUN_00586150()))))->SetActivateSound((::TESSound *)(::RProjectile *)(0));
            reinterpret_cast<::TimeoutTimer *>(&(blocked))->FUN_00910b10();
        }
    }
    if (fire24)
    {
        switch (((signed char)(reinterpret_cast<::AnimSequenceStub *>((animation0))->FUN_00495e40((float *)(0)))))
        {
        case 51:
            attack20 = 38;
            break;
        case 52:
            attack20 = 44;
            break;
        case 53:
            attack20 = 50;
            break;
        case 54:
            attack20 = 56;
            break;
        case 55:
            attack20 = 62;
            break;
        case 56:
            attack20 = 68;
            break;
        case 108:
            attack20 = 26;
            break;
        default:
            if (weapon0 && reinterpret_cast<::FUN_0051f5f0_shell *>((weapon0))->GetByteAt11D() != 255)
                attack20 = reinterpret_cast<::FUN_0051f5f0_shell *>((weapon0))->GetByteAt11D();
            else
                attack20 = 32;
            break;
        }
        ((::RProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->SetAttackFlag(attackFlag12);
        bool attacked = reinterpret_cast<::Pawn *>((actor))->TryAttack(attack20);
        if (attacked && !automatic77)
        {
            float minDelay = reinterpret_cast<::FUN_00645c40_Class *>((weapon0))->GetField174Float() * reinterpret_cast<::FUN_009d1b30_class *>((void *)(((::RTuning *)(reinterpret_cast<CombatControllerFields*>((context))->pCombatStyle))))->GetFloatAtOffset50();
            float maxDelay = reinterpret_cast<::FUN_00645c60_shell *>((weapon0))->GetField178Float() * reinterpret_cast<::FUN_009d1b50_shell *>((((::RTuning *)(reinterpret_cast<CombatControllerFields*>((context))->pCombatStyle))))->GetField54Float();
            reinterpret_cast<::FUN_008d7f40_shell *>(&(shot))->FUN_008d7f40(RandomFloat(minDelay, maxDelay));
        }
        if (projectile && ::IsExplosionRadiusValid((::PathingRequest *)(projectile)))
            reinterpret_cast<::CombatDialogueHandler *>(((*reinterpret_cast<::RManager * *>(&::CombatAssessment::DAT_011f1708))))->FUN_00983970((::CombatController *)(context), 2, 4, 1);
    }
}
// Computes and returns a vector using ComputeTrajectory, or returns the vector at DAT_011f426c if FUN_00996e00 returns null.
// @fnv 0x009d1c90
FUN_009d1d30_Vec3 CombatThing::GetTrajectory(uintptr_t auiArg)
{
    Actor* pActor2;
    FUN_009d1d30_Vec3 kResult3;
    Target2* pTarget;

    pActor2 = ((::Actor *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    if (!pActor2)
        return *(FUN_009d1d30_Vec3*)&(*reinterpret_cast<char *>((void *)&::NiPoint3::ZERO));
    pTarget = ((::Target2 *)(::FUN_007031c0((intptr_t)(m_04))));
    ComputeTrajectory(&kResult3, ((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0())), pActor2, auiArg, reinterpret_cast<::Thing *>((pTarget))->GetOrFallback((intptr_t)(((::Actor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0())))), 0.0f, 0);
    return kResult3;
}

#include "generated/data/fallout/ai/combat/combatprocedureattackranged.inc"
