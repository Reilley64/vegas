#pragma once

class NiPoint3;
struct NavMeshTriList;
struct ObstacleDataPtr;

struct NavMeshOverlap {
public:
    // 0x006987d0
    void FUN_006987d0(const ::ObstacleDataPtr &, const ::NiPoint3 &, ::NavMeshTriList *);
};
