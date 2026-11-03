#pragma once

class ActorValueOwner428;
class GameSettingCollection;
namespace fnv_00643670 { struct Dummy; }
namespace fnv_006439d0 { struct ActorValueOwner; }
namespace fnv_00643a10 { struct ActorValueOwner; }
namespace fnv_00643a70 { struct ActorValueOwner; }
namespace fnv_00643b50 { class ActorValueOwner; }
namespace fnv_00643ff0 { struct Actor; }
struct ActorBase1;
struct ActorStub;
struct FUN_0066ef50_Class;
struct S00643870_Base1;

// 0x00643400
int ComputeClampedSettingSum(int, int, float);
// 0x006434f0
float FUN_006434f0(int);
// 0x00643540
namespace fnv_00643540 { void GetSettingPairValues(int, float *, float *); }
// 0x006435c0
float FUN_006435c0(int, int);
// 0x00643670
namespace fnv_00643670 { void FUN_00643670(::fnv_00643670::Dummy *); }
// 0x006436c0
float ComputeActorLevel(::ActorBase1 *, float);
// 0x00643820
void FUN_00643820(int *);
// 0x00643870
float FUN_00643870(::S00643870_Base1 *, float);
// 0x006439d0
namespace fnv_006439d0 { float FUN_006439d0(::fnv_006439d0::ActorValueOwner *); }
// 0x00643a10
namespace fnv_00643a10 { float FUN_00643a10(::fnv_00643a10::ActorValueOwner *); }
// 0x00643a50
float FUN_00643a50();
// 0x00643a70
namespace fnv_00643a70 { float FUN_00643a70(::fnv_00643a70::ActorValueOwner *); }
// 0x00643b10
float FUN_00643b10(::ActorValueOwner428 *);
// 0x00643b50
namespace fnv_00643b50 { float FUN_00643b50(::fnv_00643b50::ActorValueOwner *, int); }
// 0x00643bd0
float FUN_00643bd0(void *, int);
// 0x00643bf0
void GetSkillAttributeAndBase(int, int *, float *);
// 0x00643c90
float GetSkillValue(::ActorStub *, int, bool);
// 0x00643e40
float FUN_00643e40(::FUN_0066ef50_Class *, int);
// 0x00643ed0
float FUN_00643ed0(::GameSettingCollection *, int);
// 0x00643f20
namespace fnv_00643f20 { float FUN_00643f20(float); }
// 0x00643f70
float ScaleByGlobalFloat(float);
// 0x00643f90
float FUN_00643f90(float);
// 0x00643fa0
float AddScaledSetting(float);
// 0x00643fd0
namespace fnv_00643fd0 { float AddRuntimeFloatSetting(float); }
// 0x00643ff0
namespace fnv_00643ff0 { float GetFollowerOffset(::fnv_00643ff0::Actor *, ::fnv_00643ff0::Actor *); }
