#pragma once

namespace fnv_00ea2030 { struct CenteredPointBounds; }
namespace fnv_00ea2030 { struct SphereShape; }
struct BoxVolume;
struct V3;

// 0x00ea2030
namespace fnv_00ea2030 { bool FUN_00ea2030(float, const ::fnv_00ea2030::CenteredPointBounds *, const void *, const ::fnv_00ea2030::SphereShape *, const void *); }
// 0x00ea2190
bool IntersectsTriangle(float, const ::BoxVolume &, const ::V3 &, const ::V3 &, const ::V3 &, const ::V3 &, const ::V3 &);
