#pragma once

class NavMesh;
class NavMeshInfo;
class NavMeshTriangleEdgeReference;
class NavMeshTriangleReference;
class PathingRequest;
struct NavMeshNodeInfo;
struct PathingRequest;
struct PathingSolution;
template <class, class> class AStarNode;
template <class, unsigned int> class BSSimpleArray;

struct NavMeshSearch {
public:
    // 0x00698f40
    bool Search(int, int);
    // 0x006a6b70
    bool ComputePath(const ::PathingRequest *, const ::NavMeshTriangleReference &, const ::NavMeshTriangleReference &, ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *, ::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *, ::BSSimpleArray< ::NavMeshInfo *, 1024> *);
    // 0x006a6ef0
    void SetSearchNodeTriangle(::AStarNode< ::NavMeshTriangleReference, ::NavMeshTriangleEdgeReference> *, ::NavMesh *, unsigned short);
    // 0x006a79c0
    bool HasReachedGoal(const ::AStarNode< ::NavMeshTriangleReference, ::NavMeshTriangleEdgeReference> *);
    // 0x006a7c40
    ~NavMeshSearch();
    // 0x006a8b60
    bool Search(::PathingRequest *, ::NavMeshNodeInfo *, ::PathingSolution *, void *);
};
