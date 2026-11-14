#pragma once

class NavMeshTriangleEdgeReference;
class NavMeshTriangleReference;
struct PathingRequest;
template <class, unsigned int> class BSSimpleArray;

struct FUN_006ac340_shell {
public:
    // 0x006ac340
    bool BuildPathingLocationAndSearch(::PathingRequest *, const ::NavMeshTriangleReference &, const ::NavMeshTriangleReference &, ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *, ::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *);
};
