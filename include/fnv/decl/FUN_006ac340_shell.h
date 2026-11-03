#pragma once

struct NavMeshTriangleEdgeReference;
struct NavMeshTriangleReference;
struct PathingRequest;
template <class, int> struct BSSimpleArray;

struct FUN_006ac340_shell {
public:
    // 0x006ac340
    bool BuildPathingLocationAndSearch(::PathingRequest *, const ::NavMeshTriangleReference &, const ::NavMeshTriangleReference &, ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *, ::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *);
};
