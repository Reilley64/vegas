#pragma once

struct SpawnedObject;
struct Vec4f;

// 0x00e53090
int Factorial(int);
// 0x00e53130
namespace fnv_00e53130 { int BinomialCoefficient(int, int); }
// 0x00e533a0
float *FUN_00e533a0(float *, float, ::SpawnedObject *);
// 0x00e535a0
float FUN_00e535a0(const ::Vec4f *, const ::Vec4f *);
// 0x00e53830
int FindFloatInterval(int, int, float, float **);
// 0x00e538a0
void ComputeBasisFunctions(int, float, int, float **, float *);
