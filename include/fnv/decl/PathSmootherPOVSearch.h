#pragma once

class CircularArc;
class NavMeshEdgePoint;
class NavMeshInfo;
class NavMeshTriangleEdgeReference;
class NavMeshTriangleReference;
class NiPoint3;
class PathSmootherPOVPoint;
class PathingRequest;
class PathingSolution;
class Sphere;
template <class, unsigned int> class BSSimpleArray;

class PathSmootherPOVSearch {
public:
    // 0x006ad690
    ~PathSmootherPOVSearch();
    // 0x006ad770
    bool SearchForPath(::PathingRequest *, const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> &, const ::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> &, const ::NiPoint3 &, const ::NiPoint3 &, ::PathingSolution *, ::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *, ::BSSimpleArray<const ::NavMeshInfo *, 1024> *);
    // 0x006af2b0
    void CollectUniqueNavMeshes();
    // 0x006af500
    void BuildSmoothedPath();
    // 0x006b23d0
    bool FUN_006b23d0(const ::NavMeshEdgePoint &, ::Sphere &, ::CircularArc);
    // 0x006b2c00
    bool CalculatePathCost(::PathSmootherPOVPoint *, ::PathSmootherPOVPoint *, const ::NiPoint3 &, const ::NiPoint3 &, float *);
};
