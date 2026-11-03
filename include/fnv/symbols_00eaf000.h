#pragma once

class OriginDirectionPair;
struct S_Seg;
struct Segment3;
struct TrianglePointSet;
struct Vector3;

// 0x00eaf1f0
float DistanceSquaredToSegment(const ::Vector3 &, const ::Segment3 &, float *);
// 0x00eaf310
float FUN_00eaf310(const ::S_Seg &, const ::S_Seg &, float &, float &);
// 0x00eaff20
float FUN_00eaff20(const ::OriginDirectionPair &, const ::TrianglePointSet &, float &, float &, float &);
