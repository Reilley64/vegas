#pragma once

class HkVec4;
struct Aabb16;
struct Collector;
struct HkRayBundle;
struct KdNode;
struct Node16;
struct PrimIds;
struct QueryAabb;
struct QueryObj;
struct RayQuerySet;
struct RealVec;
struct S00d1b4d0_Bounds;
struct S00d1b4d0_Callback;
struct S00d1b4d0_Entry;
struct S00d1b4d0_List;
struct S00d1b4d0_Node;
struct S00d1b7f0_Input;
struct hkAabbTree16;

// 0x00d1b290
void QueryKdTree(void *, ::KdNode *, const ::Aabb16 *, const float *, const float *, const ::QueryAabb *__restrict, ::PrimIds *);
// 0x00d1b4d0
int FUN_00d1b4d0(::S00d1b4d0_Node *, ::S00d1b4d0_Entry *, const ::RealVec &, const ::RealVec &, ::S00d1b4d0_Bounds *, int, ::S00d1b4d0_List *, ::S00d1b4d0_Callback *, unsigned int **, int);
// 0x00d1b850
void FUN_00d1b850(::QueryObj *, void *, void *);
// 0x00d1b930
void FUN_00d1b930(::S00d1b7f0_Input *, int, int, int);
// 0x00d1b9b0
void FUN_00d1b9b0(::QueryObj *, const void *, void *);
// 0x00d1bad0
float FUN_00d1bad0(float *, float *);
// 0x00d1bb50
::HkRayBundle FUN_00d1bb50(const ::HkVec4 &, const ::HkVec4 &, const ::HkVec4 &, const ::HkVec4 &, const ::HkVec4 &, const ::HkVec4 &, const ::HkVec4 &, const ::HkVec4 &, int);
// 0x00d1bfa0
void FUN_00d1bfa0(const ::hkAabbTree16 *, const ::Node16 *, const ::Node16 *, const ::RayQuerySet &, ::Collector *const *, const float *);
