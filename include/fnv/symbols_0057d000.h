#pragma once
#include <cstdint>

class NiFixedString;
class NiPoint3;
namespace TerrainLOD { struct Point3; }
namespace fnv_0057de00 { class LODLand; }
namespace fnv_0057de00 { class NiPoint3; }
namespace fnv_0057de00 { struct LODSettings; }
struct Mgr;

// 0x0057d090
::NiFixedString *FUN_0057d090();
// 0x0057d0a0
namespace TerrainLOD { void FUN_0057d0a0(::TerrainLOD::Point3, ::TerrainLOD::Point3, float); }
// 0x0057d4f0
void FUN_0057d4f0(::Mgr *, std::intptr_t, ::NiPoint3, ::NiPoint3, float, float, float);
// 0x0057dd70
float FUN_0057dd70(float);
// 0x0057de00
namespace fnv_0057de00 { void GenerateGrassPositions(int, int, int, ::fnv_0057de00::LODLand *, void *, const ::fnv_0057de00::NiPoint3 &, std::intptr_t, ::fnv_0057de00::NiPoint3, ::fnv_0057de00::LODSettings *, float *, int, float, unsigned short, int, float, unsigned char, unsigned char); }
