#pragma once

class S9d540_BoxBV;
class S9d540_HalfSpaceBV;
class S9d540_Pt;
struct BvPt;
struct Capsule72;
struct Half72;
struct HalfSpaceBV;
struct NiBoundingVolume;
struct PA_e9d150;
struct Plane;
struct Pt3;
struct Pt;
struct V3_e9d150;
struct Vec72;

// 0x00e9d070
bool FUN_00e9d070(float, ::HalfSpaceBV *, ::Pt3 *, ::HalfSpaceBV *, ::Pt3 *);
// 0x00e9d150
bool FUN_00e9d150(float, ::PA_e9d150 *, ::V3_e9d150 *, ::V3_e9d150 *, ::V3_e9d150 *, ::V3_e9d150 *, ::V3_e9d150 *);
// 0x00e9d2c0
bool FUN_00e9d2c0(float, const ::NiBoundingVolume &, const ::BvPt &, const ::NiBoundingVolume &, const ::BvPt &, float &, ::BvPt &, bool, ::BvPt &, ::BvPt &);
// 0x00e9d540
bool FUN_00e9d540(float, const ::S9d540_HalfSpaceBV &, const ::S9d540_Pt &, const ::S9d540_BoxBV &, const ::S9d540_Pt &, float &, ::S9d540_Pt &, bool, ::S9d540_Pt &, ::S9d540_Pt &);
// 0x00e9da30
bool SweepCapsuleAgainstHalf(float, const ::Half72 &, const ::Vec72 &, const ::Capsule72 &, const ::Vec72 &, float &, ::Vec72 &, bool, ::Vec72 *__restrict, ::Vec72 *);
// 0x00e9dfa0
bool IntersectPlanes(float, ::Plane *, ::Pt *, ::Plane *, ::Pt *, float *, ::Pt *, bool, ::Pt *, ::Pt *);
