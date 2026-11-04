#pragma once

class Event7CA;
namespace fnv_007ca5f0 { struct FUN_007ca5f0_Argument; }
namespace fnv_007caa80 { struct Button_7caa80; }
struct CA4D0Entry;
struct CsParam;
struct FUN_007ca530_Params;
struct FUN_007ca860_Arg;
struct FUN_007ca8e0_Params;

// 0x007ca4d0
void UpdateEntryRankText(::CA4D0Entry *);
// 0x007ca530
void DispatchStateCallback(::FUN_007ca530_Params *);
// 0x007ca5f0
namespace fnv_007ca5f0 { void UpdateLodVisibility(::fnv_007ca5f0::FUN_007ca5f0_Argument *); }
// 0x007ca7a0
void FUN_007ca7a0(::CsParam *);
// 0x007ca860
void CallVfunc60WithGlobalOffset(::FUN_007ca860_Arg *);
// 0x007ca8a0
void FUN_007ca8a0(::Event7CA *);
// 0x007ca8e0
void DispatchSourceCallback(::FUN_007ca8e0_Params *);
// 0x007caa80
namespace fnv_007caa80 { void PlaySpecialBookSoundAndSetStat(::fnv_007caa80::Button_7caa80 *); }
// 0x007cabb0
void FUN_007cabb0();
// 0x007cabf0
namespace fnv_007cabf0 { void FUN_007cabf0(); }
// 0x007cac30
void FUN_007cac30();
