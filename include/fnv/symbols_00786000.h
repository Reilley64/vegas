#pragma once

namespace fnv_007864e0 { class TESObjectREFR; }
namespace fnv_007864e0 { class Tile; }
namespace fnv_00786570 { class BGSPerk; }
namespace fnv_00786570 { class Tile; }
namespace fnv_007865d0 { class BGSPerk; }
namespace fnv_007865d0 { template <class> class ListBoxItem; }
struct LevelValue;
class Tile;

// 0x00786170
void FUN_00786170(::Tile *, int);
// 0x00786200
void FUN_00786200(::Tile *);
// 0x00786240
void FUN_00786240(::LevelValue *, int);
// 0x007864e0
namespace fnv_007864e0 { void FUN_007864e0(::fnv_007864e0::Tile *, ::fnv_007864e0::TESObjectREFR *); }
// 0x00786570
namespace fnv_00786570 { void FUN_00786570(::fnv_00786570::Tile *, ::fnv_00786570::BGSPerk *); }
// 0x007865d0
namespace fnv_007865d0 { int ComparePerkListItems(::fnv_007865d0::ListBoxItem< ::fnv_007865d0::BGSPerk *> *, ::fnv_007865d0::ListBoxItem< ::fnv_007865d0::BGSPerk *> *); }
