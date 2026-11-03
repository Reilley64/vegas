
// src/fallout/ai/combat/combatutilities_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x009a7940: the skeleton of src/fallout/ai/combat/combatutilities.cpp
// with declarations corrected to what the original code does (unit: extern "C" float __cdecl FUN_005b9e80(float); -> #pragma strict_gs_check(on) extern "C" float __cdecl FUN_005). Move the function to its real unit once
// that unit declares it this way.

// src/fallout/ai/combat/combatutilities.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatutilities.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/AngleView.h"
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSAnimGroupSequence.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00458e20_shell.h"
#include "fnv/decl/FUN_0045bb20_cls.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0db0_class.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004fd420_shell.h"
#include "fnv/decl/FUN_00508050_Class.h"
#include "fnv/decl/FUN_00553ee0_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_0059ceb0_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00646f50_shell.h"
#include "fnv/decl/FUN_00647790_shell.h"
#include "fnv/decl/FUN_006b99e0_class.h"
#include "fnv/decl/FUN_008854d0_.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008e26a0_C.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_00963730_cls.h"
#include "fnv/decl/FUN_00980070_shell.h"
#include "fnv/decl/FUN_00981920_Class.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MobileObject.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/SightActor.h"
#include "fnv/decl/TESAnimGroup.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_008be420__Dd.h"
#include "fnv/decl/fnv_00965620__AimPlayer.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00416000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b2000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_0057d000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_009a6000.h"
#include "fnv/symbols_009a7000.h"
#include "fnv/symbols_009a8000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101a000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0103c000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f2000.h"
#pragma strict_gs_check(on)
float __cdecl FUN_009a7dd0(float a, float b, float c);
extern int DAT_011a558c;
extern "C" int DAT_011a558c;
float ScaleCharToFloat(char arg);
struct FUN_009a9f00_shell
{
    void SetFieldE0(float value);
};
struct BGSProjectile
{
};
struct FUN_009a7f80_shell : BGSProjectile
{
    bool FUN_009a7f80() const;
};
long __cdecl ScaleByRatio(float a);
struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};
struct TESObjectREFR
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual NiPoint3* v125() = 0;
};
struct GameSettingCollection;
template <typename T> struct SettingT
{
    float* Float();
};
struct PathingRequest
{
    float GetTargetRadius();
public:
    float GetActorRadius();
};
struct Standin77900
{
    float FUN_00477900();
};
float __cdecl ComputeExplosionDamageFalloff(float, float, float);
extern int DAT_011a5590;
extern int DAT_011a5590;
int ExpandFlagBits(int flags, char index);
struct FUN_00966980_shell
{
    char _pad[0x64];
    float _f64;
    float FUN_00966980();
};
struct A69C0Weapon
{
};
struct A69C0Actor
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual void vfunc100();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual void vfunc22C();
    virtual void vfunc230();
    virtual void vfunc234();
    virtual void vfunc238();
    virtual void vfunc23C();
    virtual void vfunc240();
    virtual void vfunc244();
    virtual void vfunc248();
    virtual void vfunc24C();
    virtual void vfunc250();
    virtual void vfunc254();
    virtual void vfunc258();
    virtual void vfunc25C();
    virtual void vfunc260();
    virtual void vfunc264();
    virtual void vfunc268();
    virtual void vfunc26C();
    virtual void vfunc270();
    virtual void vfunc274();
    virtual void vfunc278();
    virtual void vfunc27C();
    virtual void vfunc280();
    virtual void vfunc284();
    virtual void vfunc288();
    virtual void vfunc28C();
    virtual void vfunc290();
    virtual void vfunc294();
    virtual void vfunc298();
    virtual void vfunc29C();
    virtual void vfunc2A0();
    virtual void vfunc2A4();
    virtual void vfunc2A8();
    virtual void vfunc2AC();
    virtual void vfunc2B0();
    virtual void vfunc2B4();
    virtual void vfunc2B8();
    virtual void vfunc2BC();
    virtual void vfunc2C0();
    virtual void vfunc2C4();
    virtual void vfunc2C8();
    virtual void vfunc2CC();
    virtual void vfunc2D0();
    virtual void vfunc2D4();
    virtual void vfunc2D8();
    virtual void vfunc2DC();
    virtual void vfunc2E0();
    virtual void vfunc2E4();
    virtual void vfunc2E8();
    virtual void vfunc2EC();
    virtual void vfunc2F0();
    virtual void vfunc2F4();
    virtual void vfunc2F8();
    virtual void vfunc2FC();
    virtual void vfunc300();
    virtual void vfunc304();
    virtual void vfunc308();
    virtual void vfunc30C();
    virtual void vfunc310();
    virtual void vfunc314();
    virtual void vfunc318();
    virtual void vfunc31C();
    virtual void vfunc320();
    virtual void vfunc324();
    virtual void vfunc328();
    virtual void vfunc32C();
    virtual void vfunc330();
    virtual void vfunc334();
    virtual void vfunc338();
    virtual void vfunc33C();
    virtual void vfunc340();
    virtual void vfunc344();
    virtual void vfunc348();
    virtual void vfunc34C();
    virtual void vfunc350();
    virtual void vfunc354();
    virtual void vfunc358();
    virtual void vfunc35C();
    virtual void vfunc360();
    virtual void vfunc364();
    virtual void vfunc368();
    virtual void vfunc36C();
    virtual void vfunc370();
    virtual void vfunc374();
    virtual void vfunc378();
    virtual void vfunc37C();
    virtual float GetUnarmedReach();

};
float FUN_00755660(float);
extern float runtimeInitializationFloat1935;
struct FUN_009a7f00_obj
{
};
unsigned char FUN_009a98a0(unsigned int a, unsigned char b);
struct AlchemyItem
{
    void* FUN_004030b0();
};
struct Actor
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual bool IsValidTarget64();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void* GetSlot116();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual void vfunc1F4();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual bool IsSlot139(bool abArg);
    virtual void vfunc230();
    virtual void vfunc234();
    virtual void vfunc238();
    virtual void vfunc23C();
    virtual void vfunc240();
    virtual void vfunc244();
    virtual void vfunc248();
    virtual void vfunc24C();
    virtual void vfunc250();
    virtual void vfunc254();
    virtual void vfunc258();
    virtual void vfunc25C();
    virtual void vfunc260();
    virtual void vfunc264();
    virtual void vfunc268();
    virtual void vfunc26C();
    virtual void vfunc270();
    virtual void vfunc274();
    virtual void vfunc278();
    virtual void vfunc27C();
    virtual void vfunc280();
    virtual void vfunc284();
    virtual void vfunc288();
    virtual void vfunc28C();
    virtual void vfunc290();
    virtual void vfunc294();
    virtual void vfunc298();
    virtual void vfunc29C();
    virtual void vfunc2A0();
    virtual void vfunc2A4();
    virtual void vfunc2A8();
    virtual void vfunc2AC();
    virtual void vfunc2B0();
    virtual void vfunc2B4();
    virtual void vfunc2B8();
    virtual void vfunc2BC();
    virtual void vfunc2C0();
    virtual void vfunc2C4();
    virtual void vfunc2C8();
    virtual void vfunc2CC();
    virtual void vfunc2D0();
    virtual void vfunc2D4();
    virtual void vfunc2D8();
    virtual void vfunc2DC();
    virtual void vfunc2E0();
    virtual void vfunc2E4();
    virtual void vfunc2E8();
    virtual void vfunc2EC();
    virtual void vfunc2F0();
    virtual void vfunc2F4();
    virtual void vfunc2F8();
    virtual void vfunc2FC();
    virtual void vfunc300();
    virtual void vfunc304();
    virtual void vfunc308();
    virtual void vfunc30C();
    virtual void vfunc310();
    virtual void vfunc314();
    virtual void vfunc318();
    virtual void vfunc31C();
    virtual void vfunc320();
    virtual void vfunc324();
    virtual void vfunc328();
    virtual void vfunc32C();
    virtual void vfunc330();
    virtual void vfunc334();
    virtual void vfunc338();
    virtual void vfunc33C();
    virtual void vfunc340();
    virtual void vfunc344();
    virtual void vfunc348();
    virtual void vfunc34C();
    virtual void vfunc350();
    virtual void vfunc354();
    virtual void vfunc358();
    virtual void vfunc35C();
    virtual bool IsSlot216();
    virtual void vfunc364();
    virtual void vfunc368();
    virtual void vfunc36C();
    virtual void vfunc370();
    virtual void vfunc374();
    virtual void vfunc378();
    virtual void vfunc37C();
    virtual void vfunc380();
    virtual void vfunc384();
    virtual void vfunc388();
    virtual void vfunc38C();
    virtual void vfunc390();
    virtual void vfunc394();
    virtual void vfunc398();
    virtual void vfunc39C();
    virtual void vfunc3A0();
    virtual void vfunc3A4();
    virtual void vfunc3A8();
    virtual void vfunc3AC();
    virtual void vfunc3B0();
    virtual void vfunc3B4();
    virtual void vfunc3B8();
    virtual void vfunc3BC();
    virtual void vfunc3C0();
    virtual void vfunc3C4();
    virtual void vfunc3C8();
    virtual void vfunc3CC();
    virtual void vfunc3D0();
    virtual void vfunc3D4();
    virtual void vfunc3D8();
    virtual void vfunc3DC();
    virtual void vfunc3E0();
    virtual void vfunc3E4();
    virtual void vfunc3E8();
    virtual void vfunc3EC();
    virtual void vfunc3F0();
    virtual void vfunc3F4();
    virtual void vfunc3F8();
    virtual void vfunc3FC();
    virtual void vfunc400();
    virtual void vfunc404();
    virtual void vfunc408();
    virtual void vfunc40C();
    virtual void vfunc410();
    virtual void vfunc414();
    virtual void vfunc418();
    virtual void vfunc41C();
    virtual void vfunc420();
    virtual void vfunc424();
    virtual struct AlchemyItem* GetSlot266();

public:
    bool IsSneaking();
};
struct ExtraFollower
{
    int unk00;
    int unk04;
    int unk08;
    struct FollowerNode* unk0C;
};
struct FollowerNode
{
};
struct FUN_00422700_shell
{
    ExtraFollower* FUN_00422700();
};
struct ExtraDataList;
struct TopicInfoArray
{
};
struct ContNode;
struct PlayerStub
{
};
struct S_9a64d0_Pt
{
    float x;
    float y;
    float z;
    S_9a64d0_Pt operator-(const S_9a64d0_Pt& rhs) const;
};
struct S_9a64d0_Ref
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual bool IsActor();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual S_9a64d0_Pt GetBoundsMinimum();
    virtual S_9a64d0_Pt GetBoundsMaximum();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual S_9a64d0_Pt* GetPos();
};
struct S_9a64d0_Actor : S_9a64d0_Ref
{
};
struct S_9a64d0_Setting
{
    float* Float();
};
struct S_009a6770_Pt
{
    float x;
    float y;
    float z;
};
struct S_009a6770_Ref
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual bool IsX();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual S_009a6770_Pt* GetPos(S_009a6770_Pt* out);
};
struct A6830Actor : A69C0Actor
{
};
struct S_009a68b0_Pt
{
    float x, y, z;
    S_009a68b0_Pt()
    {}
    S_009a68b0_Pt(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
struct S_009a68b0_Z
{
};
struct S_009a68b0_Obj
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual bool vfn64();
};
struct S_009a68b0_Ref : TESObjectREFR
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual void vfn88();
    virtual void vfn89();
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual void vfn93();
    virtual void vfn94();
    virtual void vfn95();
    virtual void vfn96();
    virtual void vfn97();
    virtual void vfn98();
    virtual void vfn99();
    virtual void vfn100();
    virtual void vfn101();
    virtual void vfn102();
    virtual void vfn103();
    virtual void vfn104();
    virtual void vfn105();
    virtual void vfn106();
    virtual void vfn107();
    virtual void vfn108();
    virtual void vfn109();
    virtual void vfn110();
    virtual void vfn111();
    virtual void vfn112();
    virtual void vfn113();
    virtual void vfn114();
    virtual void vfn115();
    virtual void vfn116();
    virtual void vfn117();
    virtual void vfn118();
    virtual void vfn119();
    virtual void vfn120();
    virtual void vfn121();
    virtual void vfn122();
    virtual void vfn123();
    virtual void vfn124();
    virtual void vfn125();
    virtual void vfn126();
    virtual void vfn127();
    virtual void vfn128();
    virtual void vfn129();
    virtual void vfn130();
    virtual void vfn131();
    virtual void vfn132();
    virtual void vfn133();
    virtual void vfn134();
    virtual void vfn135();
    virtual void vfn136();
    virtual void vfn137();
    virtual void vfn138();
    virtual void vfn139();
    virtual S_009a68b0_Z* vfn266();
};
struct ConePoint
{
    float x, y, z;
};
struct ConeWeaponSkill
{
};
struct ConeWeapon
{
};
struct ConeProcess
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
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual ConeWeapon* GetLoadedForm();
};
struct ConeRef
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
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();

    virtual bool IsActor();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
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
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
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
    virtual const ConePoint& GetPos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool IsDead(int i);
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float GetCurrentTargetDistance(int i);

};
struct ConePlayer : ConeRef
{
};
struct ConeSetting
{
};
float __cdecl FUN_00408840(float f);
float __cdecl FUN_009a6a40(int iSkill);
static const char s_szProjectileNode[] = "ProjectileNode";
extern const char g_szConeEnd[] = "";
struct S_009a6d70_Point
{
    float x, y, z;
    S_009a6d70_Point()
    {}
    S_009a6d70_Point(const S_009a6d70_Point& o) : x(o.x), y(o.y), z(o.z)
    {}
};
struct S_009a6d70_Actor
{
};
float FUN_00408840(float value);
struct S_009a7670_P3
{
    float x, y, z;
    S_009a7670_P3()
    {}
};
struct S_009a7670_Setting
{
};
struct Vec3
{
    float x;
    float y;
    float z;
public:
    Vec3();
};
struct GlobalSetting
{
};
struct ShotActor
{
};
struct FUN_009a7fa0_cls
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
    virtual bool v64();
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
    virtual NiPoint3* v118(NiPoint3* out);
    virtual NiPoint3* v119(NiPoint3* out);
};
struct S_009a82b0_Point3
{
    float x;
    float y;
    float z;
    S_009a82b0_Point3();
};
struct S_009a82b0_Point2
{
    float x;
    float y;
    S_009a82b0_Point2();
    S_009a82b0_Point2(float ax, float ay);
};
struct S_009a82b0_Ref
{
    virtual void vfunc000();
    virtual void vfunc004();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void vfunc0EC();
    virtual void vfunc0F0();
    virtual void vfunc0F4();
    virtual void vfunc0F8();
    virtual void vfunc0FC();
    virtual bool IsActor();
    virtual void vfunc104();
    virtual void vfunc108();
    virtual void vfunc10C();
    virtual void vfunc110();
    virtual void vfunc114();
    virtual void vfunc118();
    virtual void vfunc11C();
    virtual void vfunc120();
    virtual void vfunc124();
    virtual void vfunc128();
    virtual void vfunc12C();
    virtual void vfunc130();
    virtual void vfunc134();
    virtual void vfunc138();
    virtual void vfunc13C();
    virtual void vfunc140();
    virtual void vfunc144();
    virtual void vfunc148();
    virtual void vfunc14C();
    virtual void vfunc150();
    virtual void vfunc154();
    virtual void vfunc158();
    virtual void vfunc15C();
    virtual void vfunc160();
    virtual void vfunc164();
    virtual void vfunc168();
    virtual void vfunc16C();
    virtual void vfunc170();
    virtual void vfunc174();
    virtual void vfunc178();
    virtual void vfunc17C();
    virtual void vfunc180();
    virtual void vfunc184();
    virtual void vfunc188();
    virtual void vfunc18C();
    virtual void vfunc190();
    virtual void vfunc194();
    virtual void vfunc198();
    virtual void vfunc19C();
    virtual void vfunc1A0();
    virtual void vfunc1A4();
    virtual void vfunc1A8();
    virtual void vfunc1AC();
    virtual void vfunc1B0();
    virtual void vfunc1B4();
    virtual void vfunc1B8();
    virtual void vfunc1BC();
    virtual void vfunc1C0();
    virtual void vfunc1C4();
    virtual void vfunc1C8();
    virtual void vfunc1CC();
    virtual void vfunc1D0();
    virtual void vfunc1D4();
    virtual void vfunc1D8();
    virtual void vfunc1DC();
    virtual void vfunc1E0();
    virtual void vfunc1E4();
    virtual void vfunc1E8();
    virtual void vfunc1EC();
    virtual void vfunc1F0();
    virtual S_009a82b0_Point3* GetPos();
    virtual void vfunc1F8();
    virtual void vfunc1FC();
    virtual void vfunc200();
    virtual void vfunc204();
    virtual void vfunc208();
    virtual void vfunc20C();
    virtual void vfunc210();
    virtual void vfunc214();
    virtual void vfunc218();
    virtual void vfunc21C();
    virtual void vfunc220();
    virtual void vfunc224();
    virtual void vfunc228();
    virtual void vfunc22C();
    virtual void vfunc230();
    virtual void vfunc234();
    virtual void vfunc238();
    virtual void vfunc23C();
    virtual void vfunc240();
    virtual void vfunc244();
    virtual void vfunc248();
    virtual void vfunc24C();
    virtual void vfunc250();
    virtual void vfunc254();
    virtual void vfunc258();
    virtual void vfunc25C();
    virtual void vfunc260();
    virtual void vfunc264();
    virtual void vfunc268();
    virtual void vfunc26C();
    virtual void vfunc270();
    virtual void vfunc274();
    virtual void vfunc278();
    virtual void vfunc27C();
    virtual void vfunc280();
    virtual void vfunc284();
    virtual void vfunc288();
    virtual void vfunc28C();
    virtual void vfunc290();
    virtual void vfunc294();
    virtual void vfunc298();
    virtual void vfunc29C();
    virtual void vfunc2A0();
    virtual void vfunc2A4();
    virtual void vfunc2A8();
    virtual void vfunc2AC();
    virtual void vfunc2B0();
    virtual void vfunc2B4();
    virtual void vfunc2B8();
    virtual float GetCurrentTargetDistance(int a);
};
struct S_009a8460_Actor
{
    virtual void unk_000();
    virtual void unk_001();
    virtual void unk_002();
    virtual void unk_003();
    virtual void unk_004();
    virtual void unk_005();
    virtual void unk_006();
    virtual void unk_007();
    virtual void unk_008();
    virtual void unk_009();
    virtual void unk_010();
    virtual void unk_011();
    virtual void unk_012();
    virtual void unk_013();
    virtual void unk_014();
    virtual void unk_015();
    virtual void unk_016();
    virtual void unk_017();
    virtual void unk_018();
    virtual void unk_019();
    virtual void unk_020();
    virtual void unk_021();
    virtual void unk_022();
    virtual void unk_023();
    virtual void unk_024();
    virtual void unk_025();
    virtual void unk_026();
    virtual void unk_027();
    virtual void unk_028();
    virtual void unk_029();
    virtual void unk_030();
    virtual void unk_031();
    virtual void unk_032();
    virtual void unk_033();
    virtual void unk_034();
    virtual void unk_035();
    virtual void unk_036();
    virtual void unk_037();
    virtual void unk_038();
    virtual void unk_039();
    virtual void unk_040();
    virtual void unk_041();
    virtual void unk_042();
    virtual void unk_043();
    virtual void unk_044();
    virtual void unk_045();
    virtual void unk_046();
    virtual void unk_047();
    virtual void unk_048();
    virtual void unk_049();
    virtual void unk_050();
    virtual void unk_051();
    virtual void unk_052();
    virtual void unk_053();
    virtual void unk_054();
    virtual void unk_055();
    virtual void unk_056();
    virtual void unk_057();
    virtual void unk_058();
    virtual void unk_059();
    virtual void unk_060();
    virtual void unk_061();
    virtual void unk_062();
    virtual void unk_063();
    virtual bool vfn_0100();
    virtual void unk_065();
    virtual void unk_066();
    virtual void unk_067();
    virtual void unk_068();
    virtual void unk_069();
    virtual void unk_070();
    virtual void unk_071();
    virtual void unk_072();
    virtual void unk_073();
    virtual void unk_074();
    virtual void unk_075();
    virtual void unk_076();
    virtual void unk_077();
    virtual void unk_078();
    virtual void unk_079();
    virtual void unk_080();
    virtual void unk_081();
    virtual void unk_082();
    virtual void unk_083();
    virtual void unk_084();
    virtual void unk_085();
    virtual void unk_086();
    virtual void unk_087();
    virtual void unk_088();
    virtual void unk_089();
    virtual void unk_090();
    virtual void unk_091();
    virtual void unk_092();
    virtual void unk_093();
    virtual void unk_094();
    virtual void unk_095();
    virtual void unk_096();
    virtual void unk_097();
    virtual void unk_098();
    virtual void unk_099();
    virtual void unk_100();
    virtual void unk_101();
    virtual void unk_102();
    virtual void unk_103();
    virtual void unk_104();
    virtual void unk_105();
    virtual void unk_106();
    virtual void unk_107();
    virtual void unk_108();
    virtual void unk_109();
    virtual void unk_110();
    virtual void unk_111();
    virtual void unk_112();
    virtual void unk_113();
    virtual void unk_114();
    virtual void unk_115();
    virtual void unk_116();
    virtual void unk_117();
    virtual NiPoint3* vfn_01d8(NiPoint3* p);
    virtual NiPoint3* vfn_01dc(NiPoint3* p);
    virtual void unk_120();
    virtual void unk_121();
    virtual void unk_122();
    virtual void unk_123();
    virtual void unk_124();
    virtual void unk_125();
    virtual void unk_126();
    virtual void unk_127();
    virtual void unk_128();
    virtual void unk_129();
    virtual void unk_130();
    virtual void unk_131();
    virtual void unk_132();
    virtual void unk_133();
    virtual void unk_134();
    virtual void unk_135();
    virtual void unk_136();
    virtual void unk_137();
    virtual void unk_138();
    virtual bool vfn_022c(int p);
    virtual bool vfn_0230();

};
extern float DAT_011a5594;
struct NiVecOps
{
};
struct TrajAux
{
};
struct TrajRef
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
    virtual bool v64();
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
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual TrajAux* v266();
};
struct TrajOut;
struct TrajVec
{
    float x;
    float y;
    float z;
};
struct TrajWeapon
{
};
struct TrajActor
{
};
struct FUN_009a8df0_vec
{
    float x;
    float y;
    float z;
};
struct AimPoint
{
    float x, y, z;
};
struct AimIntSetting
{
};
float __cdecl FUN_009a7dd0(float fDist, float fAngleDifference, float fSpeed);
struct S_009a9180_Weapon
{
};
struct S_009a9180_Actor
{
};
struct S_009a9180_Projectile : FUN_009a7f00_obj
{
};
struct S_009a9180_Data
{
};
struct S_009a9180_Setting
{
};
struct DebugPoint
{
    float x;
    float y;
    float z;
};
class RgbaColor
{
  public:
    float r;
    float g;
    float b;
    float a;
    RgbaColor(float fR, float fG, float fB, float fA);
};
struct NiAVObject
{
};
class TES
{
  public:
};
class GlobalObject_0044f440
{
  public:
    float* Float();
};
extern GlobalObject_0044f440 g_011f1c24;
float __cdecl FUN_009a6a40(int id);
struct Pt3
{
    float x;
    float y;
    float z;
};
struct CombatPlanningPosition
{
    Pt3 origin;
    unsigned int count;
};
struct Effect
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int GetType();
};
struct CombatPlan
{
    bool FUN_00981940(int a);
};
struct Ref;
struct Holder
{
};
struct Ref
{
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
    virtual int v26();
    virtual int v27();
    virtual int v28();
    virtual int v29();
    virtual int v30();
    virtual int v31();
    virtual int v32();
    virtual int v33();
    virtual int v34();
    virtual int v35();
    virtual int v36();
    virtual int v37();
    virtual int v38();
    virtual int v39();
    virtual int v40();
    virtual int v41();
    virtual int v42();
    virtual int v43();
    virtual int v44();
    virtual int v45();
    virtual int v46();
    virtual int v47();
    virtual int v48();
    virtual int v49();
    virtual int v50();
    virtual int v51();
    virtual int v52();
    virtual int v53();
    virtual int v54();
    virtual int v55();
    virtual int v56();
    virtual int v57();
    virtual int v58();
    virtual int v59();
    virtual int v60();
    virtual int v61();
    virtual int v62();
    virtual int v63();
    virtual int v64();
    virtual int v65();
    virtual int v66();
    virtual int v67();
    virtual int v68();
    virtual int v69();
    virtual int v70();
    virtual int v71();
    virtual int v72();
    virtual int v73();
    virtual int v74();
    virtual int v75();
    virtual int v76();
    virtual int v77();
    virtual int v78();
    virtual int v79();
    virtual int v80();
    virtual int v81();
    virtual int v82();
    virtual int v83();
    virtual int v84();
    virtual int v85();
    virtual int v86();
    virtual int v87();
    virtual int v88();
    virtual int v89();
    virtual int v90();
    virtual int v91();
    virtual int v92();
    virtual int v93();
    virtual int v94();
    virtual int v95();
    virtual int v96();
    virtual int v97();
    virtual int v98();
    virtual int v99();
    virtual int v100();
    virtual int v101();
    virtual int v102();
    virtual int v103();
    virtual int v104();
    virtual int v105();
    virtual int v106();
    virtual int v107();
    virtual int v108();
    virtual int v109();
    virtual int v110();
    virtual int v111();
    virtual int v112();
    virtual int v113();
    virtual int v114();
    virtual int v115();
    virtual int v116();
    virtual int v117();
    virtual int v118();
    virtual int v119();
    virtual int v120();
    virtual int v121();
    virtual int v122();
    virtual int v123();
    virtual int v124();
    virtual int v125();
    virtual int v126();
    virtual int v127();
    virtual int v128();
    virtual int v129();
    virtual int v130();
    virtual int v131();
    virtual int v132();
    virtual int v133();
    virtual int v134();
    virtual int v135();
    virtual int v136();
    virtual int v137();
    virtual int v138();
    virtual int v139();
    virtual int v140();
    virtual int v141();
    virtual int v142();
    virtual int v143();
    virtual int v144();
    virtual int v145();
    virtual int v146();
    virtual int v147();
    virtual int v148();
    virtual int v149();
    virtual int v150();
    virtual int v151();
    virtual int v152();
    virtual int v153();
    virtual int v154();
    virtual int v155();
    virtual int v156();
    virtual int v157();
    virtual int v158();
    virtual int v159();
    virtual int v160();
    virtual int v161();
    virtual int v162();
    virtual int v163();
    virtual int v164();
    virtual int v165();
    virtual int v166();
    virtual int v167();
    virtual int v168();
    virtual int v169();
    virtual int v170();
    virtual int v171();
    virtual int v172();
    virtual int v173();
    virtual int v174();
    virtual int v175();
    virtual int v176();
    virtual int v177();
    virtual int v178();
    virtual int v179();
    virtual int v180();
    virtual int v181();
    virtual int v182();
    virtual int v183();
    virtual int v184();
    virtual int v185();
    virtual int v186();
    virtual int v187();
    virtual int v188();
    virtual int v189();
    virtual int v190();
    virtual int v191();
    virtual int v192();
    virtual int v193();
    virtual int v194();
    virtual int v195();
    virtual int v196();
    virtual int v197();
    virtual int v198();
    virtual int v199();
    virtual int v200();
    virtual int v201();
    virtual int v202();
    virtual int v203();
    virtual int v204();
    virtual int v205();
    virtual int v206();
    virtual int v207();
    virtual int v208();
    virtual int v209();
    virtual int v210();
    virtual int v211();
    virtual int v212();
    virtual int v213();
    virtual int v214();
    virtual int v215();
    virtual int v216();
    virtual int v217();
    virtual int v218();
    virtual int v219();
    virtual int v220();
    virtual int v221();
    virtual int v222();
    virtual int v223();
    virtual int v224();
    virtual int v225();
    virtual int v226();
    virtual int v227();
    virtual int v228();
    virtual int v229();
    virtual int v230();
    virtual int v231();
    virtual int v232();
    virtual int v233();
    virtual int v234();
    virtual int v235();
    virtual int v236();
    virtual int v237();
    virtual int v238();
    virtual int v239();
    virtual int v240();
    virtual int v241();
    virtual int v242();
    virtual int v243();
    virtual int v244();
    virtual int v245();
    virtual int v246();
    virtual int v247();
    virtual int v248();
    virtual int v249();
    virtual int v250();
    virtual int v251();
    virtual int v252();
    virtual int v253();
    virtual int v254();
    virtual int v255();
    virtual int v256();
    virtual int v257();
    virtual int v258();
    virtual int v259();
    virtual int v260();
    virtual int v261();
    virtual int v262();
    virtual int v263();
    virtual int v264();
    virtual int v265();
    virtual CombatPlan* GetCombatPlan();
};
struct Mgr
{
    Holder* FUN_009a4250(Ref* a);
};
struct Glob
{
};
struct FUN_006d5320
{
    CombatPlan* obj;
    Pt3 pos;
    float angle;
    char dir;
    unsigned char flag;
    FUN_006d5320();
};
long __cdecl ScaleByRatio(float a);
float __cdecl ScaleCharToFloat(char a);
unsigned char FUN_009a98a0(unsigned int a, unsigned char b);
int ExpandFlagBits(int flags, char index);

struct __declspec(align(16)) SightVector4
{
    float components[4];
};
struct SightFilter
{
    unsigned int bits;
    SightFilter(int bits);
};
struct __declspec(align(16)) SightRayInput
{
    SightVector4 from, to;
    bool enableShapeCollectionFilter;
    SightFilter filter;
};
struct __declspec(align(16)) SightRayOutput
{
    SightVector4 normal;
    float hitFraction;
    unsigned int m_uiExtraInfo, unk18, unk1c;
    unsigned int shapeKeys[8];
    void* rootCollidable;
    unsigned int unk44, unk48, unk4c;
    void* hitObject;
};
struct SightRayHitCollector
{
    virtual ~SightRayHitCollector();
    virtual void AddRayHit(const void*, const SightRayOutput&);
    float earlyOutHitFraction;
};
struct __declspec(align(16)) hkpClosestRayHitCollector : SightRayHitCollector
{
    SightRayOutput output;
    SightFilter filter;
    float distance;
    hkpClosestRayHitCollector(int layer, const SightFilter* filter);
    ~hkpClosestRayHitCollector();
};
struct __declspec(align(16)) BhkPickData
{
    SightRayInput input;
    SightRayOutput output;
    SightVector4 startBounds;
    void* unkA0;
    hkpClosestRayHitCollector* collector;
    unsigned int collectorMode;
    bool enabled;
    BhkPickData();
    void FUN_004a3f70(SightFilter filter);
};
struct SightCell
{
};
struct SightReference
{
    virtual void unknown00();
    virtual void unknown01();
    virtual void unknown02();
    virtual void unknown03();
    virtual void unknown04();
    virtual void unknown05();
    virtual void unknown06();
    virtual void unknown07();
    virtual void unknown08();
    virtual void unknown09();
    virtual void unknown10();
    virtual void unknown11();
    virtual void unknown12();
    virtual void unknown13();
    virtual void unknown14();
    virtual void unknown15();
    virtual void unknown16();
    virtual void unknown17();
    virtual void unknown18();
    virtual void unknown19();
    virtual void unknown20();
    virtual void unknown21();
    virtual void unknown22();
    virtual void unknown23();
    virtual void unknown24();
    virtual void unknown25();
    virtual void unknown26();
    virtual void unknown27();
    virtual void unknown28();
    virtual void unknown29();
    virtual void unknown30();
    virtual void unknown31();
    virtual void unknown32();
    virtual void unknown33();
    virtual void unknown34();
    virtual void unknown35();
    virtual void unknown36();
    virtual void unknown37();
    virtual void unknown38();
    virtual void unknown39();
    virtual void unknown40();
    virtual void unknown41();
    virtual void unknown42();
    virtual void unknown43();
    virtual void unknown44();
    virtual void unknown45();
    virtual void unknown46();
    virtual void unknown47();
    virtual void unknown48();
    virtual void unknown49();
    virtual void unknown50();
    virtual void unknown51();
    virtual void unknown52();
    virtual void unknown53();
    virtual void unknown54();
    virtual void unknown55();
    virtual void unknown56();
    virtual void unknown57();
    virtual void unknown58();
    virtual void unknown59();
    virtual void unknown60();
    virtual void unknown61();
    virtual void unknown62();
    virtual bool IsMobileObject();
    SightFilter FUN_00931ed0();
};
struct SightMobileReference : SightReference
{
};
class GlobalObject_0045d260
{
  public:
};
// @fnv 0x009a7940
bool __cdecl FUN_009a7940(SightReference* source, SightReference* target, const NiPoint3& from, const NiPoint3& to,
                          int unused, int requestedLayer)
{
    reinterpret_cast<::TESForm *>(&(g_011f1c7c))->ClearData();
    int layer = 37;
    if (requestedLayer != -1)
        layer = requestedLayer;
    NiPoint3 start = from;
    start.z += ::GetScaleOrHeightDelta((::TESObjectREFR *)(source), 1);
    NiPoint3 end = to;
    if (target)
        end.z += ::FUN_009a8460((::S_009a8460_Actor *)(target), 2, true);
    BhkPickData ray;
    SightFilter filter = source->FUN_00931ed0();
    if (target && target->IsMobileObject())
    {
        SightMobileReference* mobile = static_cast<SightMobileReference*>(target);
        filter = mobile->FUN_00931ed0();
    }
    hkpClosestRayHitCollector collector(layer, &filter);
    reinterpret_cast<::FUN_0059ceb0_shell *>(&(ray))->FUN_0059ceb0(&collector);
    filter = source->FUN_00931ed0();
    reinterpret_cast<::FUN_004a39f0_shell *>(&(filter))->FUN_004a39f0(layer);
    ray.FUN_004a3f70(filter);
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(ray))->FUN_004a3da0((void *)&(start));
    reinterpret_cast<::FUN_004a3eb0_shell *>(&(ray))->FUN_004a3eb0((void *)&(end));
    void* hit = reinterpret_cast<::FUN_00553ee0_shell *>((((::SightCell *)(reinterpret_cast<::LowProcess *>((source))->GetTarget()))))->FUN_00553ee0((::TESObjectREFR *)(::BhkPickData *)(&ray));
    if (!hit)
    {
        reinterpret_cast<::TESForm *>(&(g_011f1c7c))->ClearData();
        return true;
    }
    SightReference* hitRef = ((::SightReference *)(::FUN_0056f930((::NiAVObject *)(hit))));
    if (target && hitRef == target)
    {
        reinterpret_cast<::TESForm *>(&(g_011f1c7c))->ClearData();
        return true;
    }
    reinterpret_cast<::TESForm *>(&(g_011f1c7c))->ClearData();
    return false;
}
