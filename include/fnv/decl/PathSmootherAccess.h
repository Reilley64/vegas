#pragma once

class NavMeshEdgePoint;
class NiPoint3;

class PathSmootherAccess {
public:
    // 0x006b2060
    bool FindPath(const ::NavMeshEdgePoint &, const ::NiPoint3 &, ::NavMeshEdgePoint *, float &);
};
