#pragma once

class NiPoint3;
namespace seg6b9 { struct S6Point; }
struct FUN_006b9940_cls;
struct NiPoint2;
struct NiPoint3;
struct NiPoint3Out;
struct S006b9a10_Pt;
struct V006b9b10;

// 0x006b9790
bool FUN_006b9790(const ::NiPoint3 &, const ::NiPoint3 &, const ::NiPoint3 &, const ::NiPoint3 &, ::NiPoint3Out *);
// 0x006b9820
bool ComputeBarycentricCoordinates(const float *, const float *, const float *, const float *, float *);
// 0x006b9940
void FUN_006b9940(::FUN_006b9940_cls *, ::FUN_006b9940_cls *, ::FUN_006b9940_cls *);
// 0x006b9a10
int FUN_006b9a10(const ::S006b9a10_Pt &, const ::S006b9a10_Pt &, const ::S006b9a10_Pt &, const ::S006b9a10_Pt &, ::S006b9a10_Pt &);
// 0x006b9b10
float DistanceToSegment(::V006b9b10 *, ::V006b9b10 *, ::V006b9b10 *, unsigned char *);
// 0x006b9c20
namespace seg6b9 { ::seg6b9::S6Point GetClosestPointOnSegment(const ::seg6b9::S6Point &, const ::seg6b9::S6Point &, const ::seg6b9::S6Point &); }
// 0x006b9cf0
bool FUN_006b9cf0(const ::NiPoint3 &, const ::NiPoint3 &, const ::NiPoint3 &, const ::NiPoint3 &, float &, float, float);
// 0x006b9e90
bool FUN_006b9e90(const ::NiPoint2 &, const ::NiPoint2 &, const ::NiPoint2 &, const ::NiPoint2 &, ::NiPoint2 &);
