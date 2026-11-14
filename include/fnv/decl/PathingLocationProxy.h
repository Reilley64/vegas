#pragma once

class FindTriangleForLocationFilter;
class NavMeshInfo;

class PathingLocationProxy {
public:
    // 0x006dd540
    const ::NavMeshInfo *GetAssociatedNavMesh();
    // 0x006dd6f0
    bool FindContainingTriangle(::FindTriangleForLocationFilter *);
};
