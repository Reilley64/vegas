#pragma once
#include <cstdint>

class RayVector;
class Vec4;
class hkCpuWorldRayCastCollector;
class hkpFixedBufferRayHitCollector;
struct BundleCommand;
struct Chain;
struct E2baaDst;
struct E2baaSrc;
struct FilterRays_Node;
struct FilterRays_Ray;
struct FilterRays_Tree;
struct Input;
struct Manager;
struct Node;
struct RayCastRequest;
struct RayQuerySet;

// 0x00e2b070
void FUN_00e2b070(const ::Input *, ::BundleCommand *, void *, ::RayVector &, void *, void *, void *, void *, int *);
// 0x00e2b9b0
void FUN_00e2b9b0(::Chain *, ::Node *, ::Manager *);
// 0x00e2baa0
::E2baaDst *FUN_00e2baa0(::E2baaDst *, ::E2baaSrc *, intptr_t);
// 0x00e2baf0
::RayQuerySet FUN_00e2baf0(const ::Vec4 &, const ::Vec4 &, const ::Vec4 &, const ::Vec4 &, const ::Vec4 &, const ::Vec4 &, const ::Vec4 &, const ::Vec4 &, int);
// 0x00e2bbd0
void FUN_00e2bbd0(const ::FilterRays_Tree *, const ::FilterRays_Node *, const void *, const ::FilterRays_Ray *, ::hkCpuWorldRayCastCollector *, ::hkpFixedBufferRayHitCollector *, const ::RayCastRequest *, const void *, float *, int *, int, int, int, int, int *, int &, int *, int &, ::FilterRays_Node &, ::FilterRays_Node &);
