#pragma once

struct NavObj;
struct Pt3;

struct NavOwner {
public:
    // 0x006a0ac0
    float ComputePathCost(::NavObj *, const ::Pt3 &, const ::Pt3 &, ::NavObj *);
};
