#pragma once

namespace ObstacleBounds { struct Obstacle; }
namespace fnv_006c2050 { struct Flt; }
namespace fnv_006c2050 { struct S2f850; }
namespace fnv_006c2210 { class NiAVObject; }
namespace fnv_006c2210 { struct Flt; }
struct FNVNode;
struct FNVResult;

// 0x006c2050
namespace fnv_006c2050 { bool FUN_006c2050(const ::fnv_006c2050::Flt *, ::fnv_006c2050::S2f850 *); }
// 0x006c2210
namespace fnv_006c2210 { bool RegisterCollisionObstacles(::fnv_006c2210::NiAVObject *, ::fnv_006c2210::Flt *); }
// 0x006c2550
bool FindNodeData(::FNVNode *, ::FNVResult *);
// 0x006c2650
namespace ObstacleBounds { bool UpdateObstacleBounds(::ObstacleBounds::Obstacle *); }
