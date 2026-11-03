#pragma once

namespace fnv_0072f210 { struct BarterItem; }
namespace fnv_0072f210 { struct BarterTile; }
struct F070Entry;

// 0x0072f070
int CompareF070Entries(::F070Entry *, ::F070Entry *);
// 0x0072f210
namespace fnv_0072f210 { void UpdateBarterItemTile(::fnv_0072f210::BarterTile *, ::fnv_0072f210::BarterItem *); }
// 0x0072f6f0
namespace fnv_0072f6f0 { void UpdateBarterQuantity(int); }
// 0x0072fa60
void FUN_0072fa60(int);
// 0x0072fa80
int FUN_0072fa80(int);
