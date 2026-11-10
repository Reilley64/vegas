#pragma once
#include <cstdint>

class ActorValueOwner;
class FloatSource;
struct FUN_00647a30_Flag;
struct FUN_00647a30_Obj;
class TESObjectARMO;
class TESObjectWEAP;

// 0x006477b0
float FUN_006477b0(int);
// 0x006477e0
float FUN_006477e0(intptr_t);
// 0x00647870
namespace fnv_00647870 { float ComputeScaledCount(unsigned int, unsigned int, unsigned int); }
// 0x00647920
float ComputeSquaredRatioComplement(float, float);
// 0x006479e0
float FUN_006479e0(::FloatSource *);
// 0x00647a30
float FUN_00647a30(::FUN_00647a30_Obj *, ::FUN_00647a30_Flag *, float);
// 0x00647ae0
int ComputeScaledSettingSum(float);
// 0x00647b70
int FUN_00647b70(int, int);
// 0x00647ba0
void ClampInt(int *, int, int);
// 0x00647bd0
void ClampUInt(unsigned int *, unsigned int, unsigned int);
// 0x00647d10
float FUN_00647d10(::ActorValueOwner *, ::TESObjectWEAP *, ::TESObjectARMO *, bool, bool, bool, bool);
// 0x00647f00
float FUN_00647f00(void *, void *, void *, bool, bool, bool, bool);
// 0x00647fd0
float FUN_00647fd0(::ActorValueOwner *);
