#pragma once

struct NiPoint3;
struct hkVector4;

// 0x00458060
void FUN_00458060(bool);
// 0x004580e0
char FUN_004580e0();
// 0x00458140
char FUN_00458140();
// 0x00458180
void UpdateIfEnabled(int);
// 0x004583f0
void FUN_004583f0(unsigned char);
// 0x00458620
::NiPoint3 &SetNiPoint3FromHkVector4(::NiPoint3 &, const ::hkVector4 &);
// 0x004587d0
float FUN_004587d0(float);
// 0x00458b20
void *FUN_00458b20();
// 0x00458b50
namespace fnv_00458b50 { void FUN_00458b50(void *); }
