#pragma once

namespace fnv_00774800 { struct Tile; }
namespace fnv_007748b0 { struct Tile; }
struct BarTile;

// 0x00774800
namespace fnv_00774800 { void FUN_00774800(::fnv_00774800::Tile *, int); }
// 0x007748b0
namespace fnv_007748b0 { void UpdateMeterTile(::fnv_007748b0::Tile *, float, int, int, int); }
// 0x00774b00
void UpdateBarWidths(::BarTile *, ::BarTile *, float, float, int, int);
