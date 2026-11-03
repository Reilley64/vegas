#pragma once

class NiAVObject;
namespace fnv_00558430 { struct ThreeByThreeMatrix; }
struct NiNode_00558310;
struct NiPoint3;
struct RenderStats;
struct SpawnedVecC;

// 0x00558200
unsigned int FUN_00558200(char *);
// 0x00558310
::NiAVObject *FUN_00558310(::NiNode_00558310 *);
// 0x00558430
namespace fnv_00558430 { bool UpdateAndCheckBudget(int, const ::NiPoint3 *, const ::fnv_00558430::ThreeByThreeMatrix *, ::SpawnedVecC *); }
// 0x005586e0
void WriteRenderStatsFile(::RenderStats *);
