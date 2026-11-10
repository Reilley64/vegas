#pragma once

class NavMeshEdgePoint;
struct NiPoint3;

struct ClearanceSearch {
public:
    // 0x006b25f0
    bool FUN_006b25f0(const ::NavMeshEdgePoint &, const ::NiPoint3 &, ::NavMeshEdgePoint *, bool, bool, float &);
};
