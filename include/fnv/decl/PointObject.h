#pragma once

struct RegionNode;

struct PointObject {
public:
    // 0x004f7620
    bool IsInRegion(::RegionNode *, float);
};
