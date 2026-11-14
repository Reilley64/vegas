#pragma once

class NiBlendInterpolator;
struct NiFloatInterpController;
struct NiGeomMorpherUpdateTask;

// 0x00a56560
::NiBlendInterpolator *ConstructBlendInterpolator(::NiBlendInterpolator *, int, bool, float, unsigned char);
// 0x00a565c0
void *FUN_00a565c0();
// 0x00a56b30
::NiFloatInterpController *CreateFloatInterpController();
// 0x00a56f90
::NiGeomMorpherUpdateTask *PopMorpherUpdateTask();
