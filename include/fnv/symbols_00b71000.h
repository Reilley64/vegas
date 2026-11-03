#pragma once

class BlobObj_cls;
class NiPoint3;
class ThreeByThreeMatrix;
namespace fnv_00b71130 { struct LProp; }
struct BeamStage;
struct FUN_00b71360_water;
struct NiD3DShader;

// 0x00b71130
namespace fnv_00b71130 { void SetLightColor(unsigned int, ::fnv_00b71130::LProp *, float); }
// 0x00b71360
void FUN_00b71360(unsigned int, ::FUN_00b71360_water *, float);
// 0x00b71410
void FUN_00b71410(void *, int);
// 0x00b71720
void *FUN_00b71720(char *);
// 0x00b71920
::BlobObj_cls *CreateBlobObj();
// 0x00b719c0
double FUN_00b719c0(double, double);
// 0x00b71a40
void BuildTransformMatrix(float *, const ::ThreeByThreeMatrix &, const ::NiPoint3 &, float);
// 0x00b71b10
void FUN_00b71b10(::BeamStage *, ::NiD3DShader *);
