#pragma once
#include <cstdint>

class NiShaderConstantMapEntry;
struct ConstantTarget;
struct ExtraDataStandIn;

// 0x00e830f0
int SetConstantSum(::ConstantTarget *, intptr_t, intptr_t, int, int, int);
// 0x00e83320
int FUN_00e83320(::ConstantTarget *, intptr_t, intptr_t, int, int, int);
// 0x00e83550
void SetAffineMatrix(float *, const float *, bool, bool, int);
// 0x00e83840
const void *GetShaderConstantValue(::NiShaderConstantMapEntry *, ::ExtraDataStandIn *);
// 0x00e83a90
const void *GetConstantData(void *);
