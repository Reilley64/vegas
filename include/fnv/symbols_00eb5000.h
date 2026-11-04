#pragma once

struct OrientedBox;
struct Point3Lite;
struct S00eb50f0_Seg;
struct Triangle3;

// 0x00eb50f0
float FUN_00eb50f0(const ::S00eb50f0_Seg *, const ::OrientedBox *, float *, float *, float *, float *);
// 0x00eb5450
float GetSquaredDistanceToTriangle(const ::Point3Lite &, const ::Triangle3 &, float *, float *);
