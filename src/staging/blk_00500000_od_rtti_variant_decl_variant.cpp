
// src/staging/blk_00500000_od_rtti_variant_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00515040: the skeleton of src/staging/blk_00500000_od_rtti_variant.cpp
// with declarations corrected to what the original code does (unit: struct Actor : public ActorVTable { virtual bool ActorCh -> class ActorValueOwner { public: virtual void AVO00(); ). Move the function to its real unit once
// that unit declares it this way.

// src/staging/blk_00500000_od_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectREFR). The skeleton of src/staging/blk_00500000_od.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.
// src/staging/blk_00500000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "fnv/decl/ActorInventoryQueryViews__ActorQuery.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DoorAccessData.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0044a970_Cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_004e4600_shell.h"
#include "fnv/decl/FUN_004e4620_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00505c00_shell.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_0050c630_helper.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_0057c850_cls.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_00644a50_shell.h"
#include "fnv/decl/FUN_006a9560_Class.h"
#include "fnv/decl/FUN_00792760_shell.h"
#include "fnv/decl/FUN_0084d310_class.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_00962810_Class.h"
#include "fnv/decl/FUN_00962850_Class.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_009e8670.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5e930.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/NiPointLight.h"
#include "fnv/decl/NiTriGeom2.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/ParticleShader.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESEffectShader.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESGrass.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004bc450__FUN_004bc450_S.h"
#include "fnv/decl/fnv_0050c660__FUN_0050c660_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0087ad50__Host.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00503000.h"
#include "fnv/symbols_00505000.h"
#include "fnv/symbols_0050c000.h"
#include "fnv/symbols_0050d000.h"
#include "fnv/symbols_0050e000.h"
#include "fnv/symbols_0050f000.h"
#include "fnv/symbols_00510000.h"
#include "fnv/symbols_00519000.h"
#include "fnv/symbols_0051d000.h"
#include "fnv/symbols_0054a000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01021000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c8000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f8000.h"
#include "../../include/layout_support.h"
struct FUN_00505c20_class
{
    unsigned char GetByteAtOffset9A();
};
struct NiNode;
struct GO
{
    void* operator=(void*);
};
struct FUN_00507550_Class
{
    void FUN_00507550(void* p);
};
struct FUN_00507570_Class
{
    void FUN_00507570(float value);
};
struct FUN_00507610_Class
{
    void FUN_00507610(float value);
};
struct FUN_005076c0Class
{
    void __thiscall FUN_005076c0(float value);
};
struct FUN_005076e0_Class
{
    void FUN_005076e0(float value);
};
struct FUN_00507720_Class
{
    void __thiscall FUN_00507720(float value);
};
struct FUN_00507740_Class
{
    void FUN_00507740(int value);
};
struct FUN_00507760_Class
{
    void FUN_00507760(int value);
};
struct FUN_00507780
{
    void SetBoltsRadiusStrength(float value);
};
struct FUN_005077a0_Class
{
    void FUN_005077a0(float value);
};
struct Flt
{
    operator unsigned int();
};
struct FUN_00507d80_Class
{
    unsigned int FUN_00507d80();
};
struct FUN_00508050_Class
{
    float FUN_00508050();
};
struct FUN_00508070_class
{
    float FUN_00508070();
};
struct FUN_00509890_class
{
    void* __thiscall FUN_00509890(bool);
};
struct FUN_0050d1d0_class
{
    bool IsFlag8Set() const;
};
struct FUN_0050d1f0_Class
{
    bool __thiscall FUN_0050d1f0() const;
};
struct FUN_0050d210_Class
{
    bool IsFlag80Set() const;
};
struct FUN_0050d230_class
{
    bool FUN_0050d230() const;
};
struct FUN_00510110_class
{
    void FUN_00510110();
};
struct TESObject
{
};
struct FUN_00510360_Class
{
    void* FUN_00510360(TESObject* p);
};
struct BGSTerrainManager
{
    unsigned int GetMinLevel();
};
struct FUN_00510380_Class
{
    unsigned int __thiscall GetTerrainMinLevel(BGSTerrainManager* a);
};
struct FUN_005103a0_class
{
    void __thiscall FUN_005103a0(const char* a, const char* b);
};
extern "C" int __cdecl _memcmp(const void* s1, const void* s2, unsigned int n);
extern "C" void* __cdecl FUN_00eca2e0(void* p, int c, size_t n);
struct ArrSI
{
    unsigned int HasFlag10000000();
};
struct FUN_00519020_Class
{
    void SetField688(int value);
};
struct FUN_008256d0_list
{
    bool FUN_008256d0();
};
struct FUN_005194d0_shell_base
{
    bool FUN_005194d0();
};
extern "C" void* DAT_0102b3d0;
struct FUN_00519b20_cls
{
    void* m_p;
    void* __thiscall FUN_00519b20(void* arg);
};
struct Unk_00a5e930
{
};
struct FUN_0051cfe0_Class
{
    unsigned int __thiscall FUN_0051cfe0();
};
struct FUN_0051f4d0_class
{
    unsigned int GetField1CC();
};
struct FUN_0051f4f0_Class
{
    void FUN_0051f4f0(int value);
};
struct FUN_0051f530_class
{
    void __thiscall FUN_0051f530(int value);
};
extern void* DAT_0102b3f0;
struct FUN_00519c50_class
{
    void* pVft;
    int _0x4;
    void* _0x8;
    void __thiscall FUN_00519c50();
};
void __cdecl FUN_005010f0();
struct FUN_005010c0_class
{
    void __thiscall FUN_005010f0();
    void* __thiscall FUN_005010c0(unsigned int flags);
};
struct NiPoint4
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_00507660_class
{
    void FUN_00507660(NiPoint4 p);
};
struct FUN_00519b50_class
{
    void __thiscall FUN_00519bf0();
    void* __thiscall FUN_00519b50(unsigned int flags);
};
struct FUN_00519c50_class;
struct FUN_00519c80_class
{
    void* __thiscall FUN_00519c80(unsigned int flags);
};
struct FUN_00501cd0_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    unsigned int m_10;
    void* m_14;
    void* __thiscall FUN_00501cd0();
};
struct TESForm;
struct FUN_00507590_Data
{
    float a;
    float b;
    float c;
};
struct FUN_00507590_Class
{
    void __thiscall SetData(FUN_00507590_Data v);
};
struct Vec12_5075c0
{
    int x;
    int y;
    int z;
};
struct S5075c0
{
    void __thiscall FUN_005075c0(Vec12_5075c0 v);
};
struct FUN_00507630_Cls
{
    unsigned char _pad[0xC4];
    NiPoint4 fld;
    void __thiscall SetPoint(NiPoint4 p);
};
struct FUN_00507690_Class
{
    char _pad[0xe4];
    NiPoint4 m_0xe4;
    void __thiscall FUN_00507690(NiPoint4 v);
};
struct BGSImpactData
{
    float FUN_009a9350() const;
};
struct PathingRequest
{
    float GetActorRadius();
public:
    float GetGoalZDelta();
};
struct FUN_00508100_shell
{
    float FUN_00508100();
};
struct BSFaceGenMorphData
{
    float FUN_00508120();
};
struct FUN_00759450_shell
{
    float FUN_00759450();
};
struct FUN_005082b0_shell
{
};
struct FUN_00508090_shell
{
    void FUN_00508090(float a, float b, float c, unsigned char d);
};
struct FUN_0050e640_Holder
{
    char _0[4];
    unsigned char _4;
    bool __thiscall MatchesValue(unsigned char v);
};
struct AVH
{
};
struct FUN_00514fd0_class
{
    int __thiscall FUN_00514fd0();
};
struct LH
{
    bool IsInList(int&);
};
struct FUN_00519500_class
{
    bool HasEntry(int a);
};
struct FUN_00519b20
{
    void* __thiscall ConstructArray(unsigned int n);
};
struct TESGrassBase
{
    TESGrassBase();
    ~TESGrassBase();
    void SetFormType(int);
    unsigned char m_00;
    unsigned char m_01;
    unsigned char m_02;
    unsigned char m_03;
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    unsigned char m_07;
    unsigned char m_08;
    unsigned char m_09;
    unsigned char m_0a;
    unsigned char m_0b;
    unsigned char m_0c;
    unsigned char m_0d;
    unsigned char m_0e;
    unsigned char m_0f;
    unsigned char m_10;
    unsigned char m_11;
    unsigned char m_12;
    unsigned char m_13;
    unsigned char m_14;
    unsigned char m_15;
    unsigned char m_16;
    unsigned char m_17;
    unsigned char m_18;
    unsigned char m_19;
    unsigned char m_1a;
    unsigned char m_1b;
    unsigned char m_1c;
    unsigned char m_1d;
    unsigned char m_1e;
    unsigned char m_1f;
    unsigned char m_20;
    unsigned char m_21;
    unsigned char m_22;
    unsigned char m_23;
    unsigned char m_24;
    unsigned char m_25;
    unsigned char m_26;
    unsigned char m_27;
    unsigned char m_28;
    unsigned char m_29;
    unsigned char m_2a;
    unsigned char m_2b;
    unsigned char m_2c;
    unsigned char m_2d;
    unsigned char m_2e;
    unsigned char m_2f;
};
struct TESGrassModel
{
    TESGrassModel();
    ~TESGrassModel();
    void* vft;
};
struct FUN_00509a10 : TESGrassBase
{
    TESGrassModel m_30;
    FUN_00509a10();
};
extern int DAT_01028364;
extern int DAT_01028378;
extern int DAT_0102838c;
extern int DAT_010283a0;
extern int DAT_010283b4;
extern int DAT_010283d4;
extern int DAT_010283e8;
extern int DAT_01028408;
extern int DAT_0102842c;
extern int DAT_01028444;
struct TESObjectMISC
{
    TESObjectMISC();
    ~TESObjectMISC();
};
struct SFTX
{
    void SetFormType(int);
};
struct FUN_0050a5a0 : TESObjectMISC
{
    FUN_0050a5a0();
    void SetFormType(int);
};
struct TESObjectREFR_Flags
{
    void __thiscall SetRefFlag40000000(bool set);
};
struct Setting_S
{
};
struct S_004ed780
{
    S_004ed780* FUN_004ed780(float value);
};
struct GlobalObject_0044f440 : Setting_S
{
};
struct FUN_0050e620_S
{
};
struct GlobalObject_0045cf30 : FUN_0050e620_S
{
};
struct S0042fa20
{
};
struct GlobalObject_0045cfe0 : S0042fa20
{
};
extern unsigned char DAT_011c8fa0;
bool __cdecl InitSettingsDefaults();
struct TESBoundObject;
struct Actor;
struct LockExtraData
{
    void* pVft;
    TESBoundObject* pKey;
    bool IsLocked();
};
struct P01RefA
{
    virtual ~P01RefA();  // the original class is polymorphic (rtti_variants.py)
};
struct TESObjectREFR : public P01RefA
{
public:
    float GetScale();
};
struct ActorVTable
{
    virtual bool V00();
    virtual bool V01();
    virtual bool V02();
    virtual bool V03();
    virtual bool V04();
    virtual bool V05();
    virtual bool V06();
    virtual bool V07();
    virtual bool V08();
    virtual bool V09();
    virtual bool V10();
    virtual bool V11();
    virtual bool V12();
    virtual bool V13();
    virtual bool V14();
    virtual bool V15();
    virtual bool V16();
    virtual bool V17();
    virtual bool V18();
    virtual bool V19();
    virtual bool V20();
    virtual bool V21();
    virtual bool V22();
    virtual bool V23();
    virtual bool V24();
    virtual bool V25();
    virtual bool V26();
    virtual bool V27();
    virtual bool V28();
    virtual bool V29();
    virtual bool V30();
    virtual bool V31();
    virtual bool V32();
    virtual bool V33();
    virtual bool V34();
    virtual bool V35();
    virtual bool V36();
    virtual bool V37();
    virtual bool V38();
    virtual bool V39();
    virtual bool V40();
    virtual bool V41();
    virtual bool V42();
    virtual bool V43();
    virtual bool V44();
    virtual bool V45();
    virtual bool V46();
    virtual bool V47();
    virtual bool V48();
    virtual bool V49();
    virtual bool V50();
    virtual bool V51();
    virtual bool V52();
    virtual bool V53();
    virtual bool V54();
    virtual bool V55();
    virtual bool V56();
    virtual bool V57();
    virtual bool V58();
    virtual bool V59();
    virtual bool V60();
    virtual bool V61();
    virtual bool V62();
    virtual bool V63();
};
class ActorValueOwner
{
  public:
    virtual void AVO00();
    virtual void AVO01();
    virtual void AVO02();
    virtual void AVO03();
    virtual void AVO04();
    virtual void AVO05();
    virtual void AVO06();
    virtual int GetBaseActorValue(ActorValue::Index index);
};
struct ActorPad04 : public ActorVTable
{
    char pad04[0xa0];
};
struct Actor : public ActorPad04, public ActorValueOwner
{
    virtual bool ActorCheck();
    virtual void V65();
    virtual void V66();
    virtual void V67();
    virtual void V68();
    virtual void V69();
    virtual void V70();
    virtual void V71();
    virtual void V72();
    virtual void V73();
    virtual void V74();
    virtual void V75();
    virtual void V76();
    virtual void V77();
    virtual void V78();
    virtual void V79();
    virtual void V80();
    virtual void V81();
    virtual void V82();
    virtual void V83();
    virtual void V84();
    virtual void V85();
    virtual void V86();
    virtual void V87();
    virtual void V88();
    virtual void V89();
    virtual void V90();
    virtual void V91();
    virtual void V92();
    virtual void V93();
    virtual void V94();
    virtual void V95();
    virtual void V96();
    virtual void V97();
    virtual void V98();
    virtual void V99();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210();
    virtual void V211();
    virtual void V212();
    virtual void V213();
    virtual void V214();
    virtual void V215();
    virtual bool CanUseSkillBook();
    virtual void V217();
    virtual void V218();
    virtual void V219();
    virtual void V220();
    virtual void V221();
    virtual void V222();
    virtual void V223();
    virtual void V224();
    virtual void V225();
    virtual void V226();
    virtual void V227();
    virtual void V228();
    virtual void V229();
    virtual void V230();
    virtual void V231();
    virtual void V232();
    virtual void ModActorValue(ActorValue::Index index, float amount, int unk);
};
struct FUN_00516cd0_class
{
    bool __thiscall CanUseLockedRef(TESObjectREFR* ref, Actor* actor, bool useLockpick);
};
int DAT_011c6200;
struct FUN_00505b80_cls
{
    unsigned char DispatchByType(int aType);
};
class ThisBase_c40
{
  public:
    virtual ~ThisBase_c40();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;

    ThisBase_c40();
};
class ThisMember18_c40
{
  public:
    ThisMember18_c40();
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    int m_34;
    int m_38;
    int m_3C;
    int m_40;
    int m_44;
    int m_48;
    int m_4C;
    int m_50;
    int m_54;
    int m_58;
    int m_5C;
    int m_60;
    int m_64;
    int m_68;
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
    int m_80;
    int m_84;
    int m_88;
    int m_8C;
    int m_90;
    int m_94;
    int m_98;
    int m_9C;
    int m_A0;
    int m_A4;
    int m_A8;
    int m_AC;
    int m_B0;
    int m_B4;
    int m_B8;
    int m_BC;
    int m_C0;
    int m_C4;
    int m_C8;
    int m_CC;
    int m_D0;
    int m_D4;
    int m_D8;
    int m_DC;
    int m_E0;
    int m_E4;
    int m_E8;
    int m_EC;
    int m_F0;
    int m_F4;
    int m_F8;
    int m_FC;
    int m_100;
    int m_104;
    int m_108;
    int m_10C;
    int m_110;
    int m_114;
    int m_118;
    int m_11C;
    int m_120;
    int m_124;
    int m_128;
    int m_12C;
    int m_130;
    int m_134;
};
class ThisMemberD_c40
{
  public:
    int m_00;
    int m_04;
    int m_08;

    ThisMemberD_c40();
    ~ThisMemberD_c40();
};
class FUN_00505c40 : public ThisBase_c40
{
  public:
    ThisMember18_c40 m_18;
    ThisMemberD_c40 m_14c;
    ThisMemberD_c40 m_158;
    ThisMemberD_c40 m_164;

    FUN_00505c40();
    virtual ~FUN_00505c40();
    virtual void unk00();
};
class FUN_00507da0_cls
{
  public:
    int unk00;
    void FUN_00507da0(float a, float b, float c, unsigned char flag);
};
extern float runtimeInitializationFloat2255;
class B5081D0Actor
{
  public:

    float FUN_005081d0(float fTime);
};
extern float runtimeInitializationFloat2255;
class C508240Ref
{
  public:

    float FUN_00508240(float fDistance);
};
namespace std {
float abs(float);
}
struct Envelope
{
    float UpdateEnvelope(float current, float rate, float elapsed, unsigned char releasing, float attack, float decay,
                         float hold, float maximum, float minimum);
};
extern char DAT_01026bd0;
extern char DAT_01026a4c;
extern char DAT_01026a34;
extern char DAT_01026a10;
extern char DAT_010269fc;
extern char DAT_010269e8;
extern char DAT_010269d8;
class ActorStateBase
{
  public:
    ActorStateBase();
    void* m_00;
    int m_04;
    int m_08;
};
class ActorStateSub
{
  public:
    ActorStateSub();
    ~ActorStateSub();
    void* m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
};
class FUN_00508450_cls : public ActorStateBase
{
  public:
    FUN_00508450_cls();
    ActorStateSub m_0c;
    void* m_3c;
    int m_40;
    int m_44;
    void* m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    void* m_68;
    int m_6c;
    int m_70;
    void* m_74;
    int m_78;
    void* m_7c;
};
struct FUN_0050a850_Primary
{
    virtual ~FUN_0050a850_Primary();
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
};
struct FUN_0050a850_Secondary30
{
    virtual ~FUN_0050a850_Secondary30();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct FUN_0050a850_Secondary4c
{
    virtual ~FUN_0050a850_Secondary4c();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct FUN_0050a850 : FUN_0050a850_Primary, FUN_0050a850_Secondary30, FUN_0050a850_Secondary4c
{
    virtual ~FUN_0050a850();
};
class B0B8F0Form
{
  public:
    B0B8F0Form();
    virtual ~B0B8F0Form();

    void SetFormType(int eType);

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
};
class B0B8F0Component
{
  public:
    B0B8F0Component();
    virtual ~B0B8F0Component();
};
class FUN_0050b8f0 : public B0B8F0Form, public B0B8F0Component
{
  public:
    FUN_0050b8f0();
    virtual ~FUN_0050b8f0();
};
class Obj50DDB0
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    unsigned int m_uiValue1;

    void FUN_0050ddb0(bool bSet);
};
struct S_0050de20_Obj
{
    int unk00;
    int unk04;
    void IncRefCount();
    void DecRefCount();
};
struct S_0050de20_A
{
    NiPointer<S_0050de20_Obj> unk00;
    int unk04;
};
struct S_0050de20_Class
{
    bool __thiscall FUN_0050de20(S_0050de20_A* a, int b);
};
struct S_5102e0_Node
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual ~S_5102e0_Node();
    int unk04f;
    int unk08f;
    int unk0cf;
    int unk10f;
    int unk14f;
    int unk18f;
};
struct S_5102e0_List
{
    int unk00;
    int unk04;
    S_5102e0_Node* head;
    void FUN_005102e0();
};
struct FUN_005103d0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int m_14;
    unsigned int FindSubstring(char* a1, unsigned int start, unsigned int count);
};
struct NiTPointerMapBase
{
    virtual ~NiTPointerMapBase();
};
struct FUN_00519bf0 : NiTPointerMapBase
{
    virtual ~FUN_00519bf0();
};
// FUN_0051cf00 (132 bytes) - the constructor of NiBillboardNode.
//
//   0051cf00  55                    push ebp
//   0051cf01  8bec                  mov ebp, esp
//   0051cf03  6aff                  push -1
//   0051cf05  68e84bef00            push __ehhandler
//   0051cf0a  64a100000000          mov eax, dword ptr fs:[0]
//   0051cf10  50                    push eax
//   0051cf11  51                    push ecx            <- this home [ebp-0x10]
//   0051cf12  a1bc161c01            mov eax, __security_cookie
//   0051cf17  33c5                  xor eax, ebp
//   0051cf19  50                    push eax            <- cookie [ebp-0x14]
//   0051cf1a  8d45f4                lea eax, [ebp-0xc]
//   0051cf1d  64a300000000          mov dword ptr fs:[0], eax
//   0051cf23  894df0                mov dword ptr [ebp-0x10], ecx
//   0051cf26  6a00                  push 0
//   0051cf28  8b4df0                mov ecx, dword ptr [ebp-0x10]
//   0051cf2b  e8801d5400            call 0xa5ecb0        <- base ctor
//   0051cf30  c745fc00000000        mov dword ptr [ebp-4], 0      <- EH state 0
//   0051cf37  8b45f0                mov eax, dword ptr [ebp-0x10]
//   0051cf3a  c70044bf0201          mov dword ptr [eax], 0x102bf44  <- own vftable
//   0051cf40  33c9                  xor ecx, ecx
//   0051cf42  8b55f0                mov edx, dword ptr [ebp-0x10]
//   0051cf45  66898aac000000        mov word ptr [edx+0xac], cx
//   0051cf4c  8b45f0                mov eax, dword ptr [ebp-0x10]
//   0051cf4f  d9ee                  fldz
//   0051cf51  d998b0000000          fstp dword ptr [eax+0xb0]
//   0051cf57  6a01                  push 1
//   0051cf59  8b4df0                mov ecx, dword ptr [ebp-0x10]
//   0051cf5c  e89f000000            call 0x51d000
//   0051cf61  6a01                  push 1
//   0051cf63  8b4df0                mov ecx, dword ptr [ebp-0x10]
//   0051cf66  e8f5000000            call 0x51d060
//   0051cf6b  c745fcffffffff        mov dword ptr [ebp-4], 0xffffffff
//   0051cf72  8b45f0                mov eax, dword ptr [ebp-0x10]
//   0051cf75  8b4df4                mov ecx, dword ptr [ebp-0xc]
//   0051cf78  64890d00000000        mov dword ptr fs:[0], ecx
//   0051cf7f  59                    pop ecx
//   0051cf80  8be5                  mov esp, ebp
//   0051cf82  5d                    pop ebp
//   0051cf83  c3                    ret
//
// The module is an unoptimised (/Od) build, and this is a constructor of a
// POLYMORPHIC class whose vftable lives at 0x102bf44
// (tools/pe.py rtti 0x102bf44 -> .?AVNiBillboardNode@@).  Three facts drive
// the shape:
//
//  * the class has a base class with a NON-TRIVIAL destructor, so the
//    constructor gets an exception-handling frame: the "push -1 / push
//    __ehhandler / mov eax,fs:[0]" prologue, the state word at [ebp-4] (0
//    right after the base ctor call, -1 at scope exit) and, because MSVC
//    2008 arms the /GS cookie for every function that carries an EH frame,
//    the "mov eax,__security_cookie / xor eax,ebp / push eax" trio;
//  * a constructor returns `this` in EAX, so the vptr store goes THROUGH
//    EAX ("mov eax,[ebp-0x10] / mov dword ptr [eax],<vftable>"); under /Od
//    the `this` home is reloaded from the frame for every use;
//  * /Od re-reads `this` from the frame for every use and materialises a
//    call argument into a scratch register, so the base ctor call and the
//    two member calls are all "push arg / mov ecx,[ebp-0x10] / call".
//
// The base class is a stand-in: only its SIZE matters (the derived members
// have to land on +0xac and +0xb0) and its constructor/destructor are
// declared but never defined, so the call target and the cleanup funclet
// are bound by the checker from the original's own bytes.
struct NiBillboardBase
{
    virtual void vfunc_base();
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
    int unkA0;
    int unkA4;
    int unkA8;
    NiBillboardBase(int flags);
    ~NiBillboardBase();
};
struct FUN_0051cf00_NiBillboardNode : public NiBillboardBase
{
    unsigned short m_0ac;
    float m_0b0;
    virtual void vfunc_node();
    FUN_0051cf00_NiBillboardNode();
    ~FUN_0051cf00_NiBillboardNode();
};
class FormPart508
{
  public:
    virtual void InitItem();
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
};
class ModelPart508
{
  public:
    virtual void GetModelFilePath();
    int unk04;
    int unk08;
};
class ScriptPart508
{
  public:
    virtual void GetScript();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
class DestructPart508
{
  public:
    virtual void GetDestructible();
    int unk04;
    int unk08;
};
class SoundPart508
{
  public:
    virtual void GetSoundByEditorID();
    int unk04;
};
class WaterPart508
{
  public:
    virtual void GetWater();
    int unk04;
};
class ActivatorBase508 : public FormPart508,
                         public ModelPart508,
                         public ScriptPart508,
                         public DestructPart508,
                         public SoundPart508,
                         public WaterPart508
{
  public:
    virtual ~ActivatorBase508();

};
class ListPart508
{
  public:
    virtual void GetList();

    int unk04;
    int unk08;
};
class FUN_00508510_Activator : public ListPart508, public ActivatorBase508
{
  public:
    virtual ~FUN_00508510_Activator();
};
struct Item;
struct List
{
};
struct Item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};
struct T
{
};
extern double DAT_01029100;
extern double DAT_010290e8;
extern double DAT_010290e0;
extern double DAT_010290d8;
extern double DAT_010290c8;
float __cdecl FUN_00408840(float v);
struct NiUpdateData
{
    float m_kPointA;
    bool m_kPointB;
    int m_iThirdValue;
    NiUpdateData(float a, bool b, int c);
};
struct Obj
{
};
struct Ptr
{
    void* m_p;
    ~Ptr();
};
struct TimeGlobal
{
};
struct SettingObj
{
};
struct TQ
{
};
struct P3
{
    int unk00;
    int unk04;
    int unk08;
    float m_iThirdValue;
};
struct Host
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
    unsigned int m_a8;
    int unkAC;
    int unkB0;
    float m_b4;
    bool FUN_0050de60(Ptr p1, float* p2, P3* p3);
};
struct Region
{
};
struct Reference
{
};
struct Node
{
    bool Empty();
    void** Item();
    unsigned int Size();
};
struct SelectionMap
{
    int vtable;
    int size;
    int table;
    int count;
    SelectionMap(unsigned int);
    ~SelectionMap();
};
struct Selector
{
    Node* List();
    void* FindRandomSelection(Reference*, int);
};
struct PlayerSelection
{
};

struct StrMem
{
    char* data;
    unsigned short length, capacity;
    StrMem();
    ~StrMem();
};
struct StringSetting552
{
};
struct FloatSetting552
{
};
namespace ActorValue {
}
struct SkillBookEffect552
{
    ActorValue::Index FUN_00514fd0();
    bool FUN_00515040(TESObjectREFR* reference);
};
// @fnv 0x00515040
bool SkillBookEffect552::FUN_00515040(TESObjectREFR* reference)
{
    bool applied = false;
    Actor* actor2 = dynamic_cast<Actor*>(reference);
    if (!actor2->CanUseSkillBook())
        return applied;
    if (((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((actor2))->FUN_00493bb0())) && !FUN_00702360())
    {
        ::DispatchMessageToSink((int)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting552 *>(&::g_011d4ccc))))->GetMenuTitle()))), 0, (int)(0), (int)(0), DAT_010162c0, false);
        return applied;
    }
    ActorValue::Index skill2 = FUN_00514fd0();
    if (::FUN_0047f060((*(int *)&(skill2))))
    {
        if ((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))->GetBaseActorValue(skill2) < 200)
        {
            float amount5 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting552 *>(&::g_011c9284))))));
            StrMem message;
            ::ApplyPerkModifiers(11, (*reinterpret_cast<::Actor * *>(&::_g_thePlayer)), &amount5);
            (*reinterpret_cast<::Actor * *>(&::_g_thePlayer))->ModActorValue(skill2, amount5, 0);
            ::TopicMenuController::IncrementMiscStat(15);
            ::FUN_00406f60((::FUN_00406f90_this *)(::StrMem *)(&message), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::StringSetting552 *>(&::g_011d49c0))))->GetMenuTitle())), ActorValue::GetActorValueName(skill2),
                         static_cast<int>(amount5));
            ::DispatchMessageToSink((int)(((const char *)(::FUN_00559450((int *)&(message))))), 1, (int)(0), (int)(0), DAT_010162c0, false);
            applied = true;
        }
    }
    return applied;
}
