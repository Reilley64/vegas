#pragma once

class TESAnimGroup;
struct UShortArg;

// 0x005f2400
namespace fnv_005f2400 { int FUN_005f2400(unsigned short); }
// 0x005f2450
void SetAnimGroupType(::TESAnimGroup *, ::UShortArg);
// 0x005f25d0
bool FUN_005f25d0(unsigned short);
// 0x005f2700
bool IsValidCharCode(int);
// 0x005f2720
bool IsIronSightsAnimGroup(unsigned short);
// 0x005f2750
bool FUN_005f2750(int);
