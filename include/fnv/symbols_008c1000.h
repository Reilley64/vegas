#pragma once
#include <cstdint>

class ListWalkNode;
class ListWalkTarget;
class TESForm;
class TESObjectREFR;
namespace fnv_008c1010 { struct FactionCheck1010; }
namespace fnv_008c1470 { struct TargetThis; }
namespace fnv_008c1b50 { struct BoolWrap; }
struct BoolWrap;
struct VTable_008c13d0_1;

// 0x008c1010
namespace fnv_008c1010 { bool FUN_008c1010(::TESObjectREFR *, ::TESForm *, ::fnv_008c1010::FactionCheck1010 *); }
// 0x008c1210
bool WalkListForTarget(::ListWalkNode *, ::ListWalkTarget *);
// 0x008c13d0
bool FUN_008c13d0(::VTable_008c13d0_1 *);
// 0x008c1470
namespace fnv_008c1470 { void UpdateAlchemyCastSound(::fnv_008c1470::TargetThis *); }
// 0x008c1ac0
void FUN_008c1ac0(void *, ::BoolWrap);
// 0x008c1b50
namespace fnv_008c1b50 { void SetFlag40000000(char *, ::fnv_008c1b50::BoolWrap); }
// 0x008c1bc0
bool FUN_008c1bc0(intptr_t);
