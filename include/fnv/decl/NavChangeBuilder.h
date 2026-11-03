#pragma once

struct NavMeshOwner;
struct NavObstaclePtr;

struct NavChangeBuilder {
public:
    // 0x006bbd30
    bool FUN_006bbd30(::NavMeshOwner *, const ::NavObstaclePtr &, int);
};
