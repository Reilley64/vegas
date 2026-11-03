#pragma once

struct Count;
struct FloatLess;

// 0x00e50d90
void AccumulateNeighborSum(float, const float *, float *, int);
// 0x00e50e50
void FUN_00e50e50(float, float *, const float *, int);
// 0x00e50f10
void FUN_00e50f10(float *, int, int, ::FloatLess);
// 0x00e50fa0
void DeinterleaveFloats(const float *, float *, ::Count);
