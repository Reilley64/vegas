#pragma once

class NiPoint3;
struct NavEdgeHit;

struct FUN_00698160_t {
public:
    // 0x00698160
    ::NavEdgeHit FindEdgeIntersection(unsigned short, int, const ::NiPoint3 &, const ::NiPoint3 &);
};
