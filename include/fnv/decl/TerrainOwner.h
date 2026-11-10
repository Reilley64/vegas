#pragma once

struct NiPoint3;
struct TerrainInput;

struct TerrainOwner {
public:
    // 0x0053bc10
    bool FUN_0053bc10();
    // 0x0053caf0
    bool ComputeTerrainNormalAndTangent(::TerrainInput *, ::NiPoint3 *, ::NiPoint3 *);
};
