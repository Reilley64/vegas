#pragma once
#include <cstdint>

struct RSItem;
struct RSMActor;
struct RSMTile;
struct RSTile;

// 0x007b7020
namespace fnv_007b7020 { void FUN_007b7020(intptr_t); }
// 0x007b7570
::RSMTile *CreateRepairServicesMenu(::RSMActor *);
// 0x007b7920
void UpdateRepairMenuTile(::RSTile *, ::RSItem *);
