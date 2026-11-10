#pragma once

class NavMesh;
class NavMeshTriangleReference;

struct NavMeshSearchClosePoint {
public:
    // 0x006a8d20
    void SetNodeFromTriangle(::NavMeshTriangleReference *, ::NavMesh *, unsigned short);
};
