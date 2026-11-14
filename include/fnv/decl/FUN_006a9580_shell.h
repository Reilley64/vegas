#pragma once

class NavMesh;
class NavMeshTriangleEdgeReference;
class NavMeshTriangleReference;
template <class, class> class AStarNode;

struct FUN_006a9580_shell {
public:
    // 0x006a9580
    void SetNodeFleeCost(::AStarNode< ::NavMeshTriangleReference, ::NavMeshTriangleEdgeReference> *, ::NavMesh *, unsigned short);
};
