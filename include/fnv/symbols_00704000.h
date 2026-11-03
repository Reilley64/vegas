#pragma once

#include <cstdint>

class TESObjectREFR;
class Tile;

// 0x00704000
void FUN_00704000();
// 0x00704010
char FUN_00704010(const char *, int, int, std::intptr_t, ...);
// 0x00704140
namespace fnv_00704140 { int FUN_00704140(); }
// 0x00704170
namespace fnv_00704170 { void UpdatePipboyMapVisibility(bool, bool); }
// 0x00704390
void FUN_00704390();
// 0x007043d0
namespace fnv_007043d0 { bool FUN_007043d0(); }
// 0x00704400
char FUN_00704400();
// 0x00704420
namespace fnv_00704420 { void FUN_00704420(bool); }
// 0x00704450
void FUN_00704450(char);
// 0x00704490
namespace fnv_00704490 { int FUN_00704490(); }
// 0x007044c0
void FUN_007044c0(bool, bool, bool);
// 0x00704690
namespace fnv_00704690 { void FUN_00704690(std::uintptr_t); }
// 0x007046c0
namespace fnv_007046c0 { int FUN_007046c0(); }
// 0x007046f0
namespace fnv_007046f0 { void FUN_007046f0(bool, bool, bool); }
// 0x007048c0
namespace fnv_007048c0 { ::Tile *CreateInventoryMenuIfModifierKey(); }
// 0x007048f0
namespace sleep704 { void FUN_007048f0(bool, bool, bool); }
// 0x00704af0
namespace fnv_00704af0 { void FUN_00704af0(); }
// 0x00704bc0
void FUN_00704bc0();
// 0x00704be0
namespace fnv_00704be0 { int FUN_00704be0(); }
// 0x00704c10
void ShowStatsMenu(bool, bool);
// 0x00704e10
void FUN_00704e10(int);
// 0x00704ed0
int FUN_00704ed0(::TESObjectREFR *, int);
// 0x00704f50
namespace fnv_00704f50 { void FUN_00704f50(); }
// 0x00704f80
namespace fnv_00704f80 { void FUN_00704f80(unsigned int, unsigned int); }
// 0x00704fc0
namespace fnv_00704fc0 { void FUN_00704fc0(int, int); }
