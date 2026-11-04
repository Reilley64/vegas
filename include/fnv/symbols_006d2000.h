#pragma once

class PathingRequestOptimalLocation;
class PathingSolution;
struct NavMeshContext;
struct NavMeshRoute;

// 0x006d23d0
namespace fnv_006d23d0 { bool BuildOptimalPathSolution(::PathingRequestOptimalLocation *, ::PathingSolution *); }
// 0x006d2c40
float GetFieldB4Float(char *);
// 0x006d2c80
bool FUN_006d2c80(::NavMeshContext *, ::NavMeshRoute *);
