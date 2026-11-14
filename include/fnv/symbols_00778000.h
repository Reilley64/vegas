#pragma once
#include <cstdint>

class TESObjectREFR;
namespace fnv_00778b80 { struct NiPoint3; }
namespace fnv_00778c20 { struct Tile179; }

// 0x00778930
int GetExtraDataShort(const ::TESObjectREFR *);
// 0x00778970
intptr_t GetField18C(char *);
// 0x00778990
namespace fnv_00778990 { void UpdateRadiationInfo(int, int, int); }
// 0x00778a90
namespace fnv_00778a90 { void UpdateHealthInfoTiles(int, int, int); }
// 0x00778b40
bool ClearPmeIfMatches(intptr_t);
// 0x00778b80
namespace fnv_00778b80 { float ComputeObjectAngleDelta(::fnv_00778b80::NiPoint3, ::fnv_00778b80::NiPoint3); }
// 0x00778c20
namespace fnv_00778c20 { void FUN_00778c20(::fnv_00778c20::Tile179 *, float, float); }
