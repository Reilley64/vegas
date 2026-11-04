#pragma once
#include <cstdint>

struct PointE69;

// 0x00e69410
unsigned char InitD3D9CreateFunctions();
// 0x00e69510
bool SetModeFlags(int, int *, unsigned int *);
// 0x00e69a60
void *FUN_00e69a60();
// 0x00e69b60
float *WriteVertex(float *, const ::PointE69 &, const ::PointE69 &, uintptr_t, float, float, float);
// 0x00e69d00
unsigned int MapCodeToIndex(unsigned int);
// 0x00e69e50
unsigned int FUN_00e69e50(int);
