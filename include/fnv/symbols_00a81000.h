#pragma once

#include <cstdint>

class NiStream;
struct BSFadeNode;
struct FUN_00a81760_obj;
struct S;

// 0x00a813c0
namespace fnv_00a813c0 { void InitTrigTables(); }
// 0x00a814e0
::BSFadeNode *FUN_00a814e0();
// 0x00a81590
namespace fnv_00a81590 { void FUN_00a81590(); }
// 0x00a81760
::FUN_00a81760_obj *FUN_00a81760();
// 0x00a819e0
void FUN_00a819e0();
// 0x00a81a20
void FUN_00a81a20();
// 0x00a81a80
void FUN_00a81a80();
// 0x00a81b30
int CompareFloatDescending(::S *, ::S *);
// 0x00a81b80
int FUN_00a81b80(const unsigned short *, const unsigned short *);
// 0x00a81fb0
::BSFadeNode *FUN_00a81fb0();
// 0x00a81fe0
struct FUN_00a81fe0_shell { bool FUN_00a81fe0(::NiStream &); };
