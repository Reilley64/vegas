#pragma once

class GeomVector;
struct CubeBox;
struct SphereInput276;
struct SphereOutput276;
struct hkVector4;

// 0x00de94b0
float FUN_00de94b0(const ::hkVector4 &, const ::hkVector4 &, const ::hkVector4 &, float *);
// 0x00de9590
void FUN_00de9590(::CubeBox *);
// 0x00de9650
extern "C" void FUN_00de9650(::SphereInput276 *, ::SphereOutput276 *);
// 0x00de9e10
float FUN_00de9e10(float *, float *, float *, float *, float *);
// 0x00de9f10
float FUN_00de9f10(const ::GeomVector &, const ::GeomVector &, const ::GeomVector &, const ::GeomVector &, ::GeomVector &, ::GeomVector *);
