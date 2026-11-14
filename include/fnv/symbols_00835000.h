#pragma once

class BGSTalkingActivator;
class TESObjectREFR;
class TESTopic;
namespace fnv_008359e0 { struct RadioSource; }
struct ReferenceView;
struct S_008356e0_Item;
struct S_008356e0_Ref;
struct TESObjectREFR_Stub;

// 0x008356e0
::S_008356e0_Item *FUN_008356e0(void *, ::S_008356e0_Ref *);
// 0x008357e0
void FUN_008357e0(int *, bool);
// 0x00835810
void FUN_00835810(::TESObjectREFR_Stub *, ::ReferenceView *);
// 0x00835980
void FUN_00835980(::TESObjectREFR_Stub *);
// 0x008359e0
namespace fnv_008359e0 { void FUN_008359e0(::fnv_008359e0::RadioSource *, bool); }
// 0x00835b90
namespace fnv_00835b90 { bool FUN_00835b90(::TESObjectREFR *); }
// 0x00835be0
void FUN_00835be0(::BGSTalkingActivator *, ::TESTopic *);
