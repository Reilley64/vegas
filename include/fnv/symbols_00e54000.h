#pragma once

class E54B50Vector4;
struct FUN_00e532b0_class;
struct FUN_00e54ad0_cls;
struct FUN_00e54b20_src;
struct KnotVector;
struct L;
struct SampleVec;
template <class> struct CurveArg;

// 0x00e54110
float EvaluateBasisFunction(int, int, const float *const *, int, float);
// 0x00e544c0
void FUN_00e544c0(int, int, float **, ::KnotVector **, float, int, ::KnotVector *, int, float);
// 0x00e54630
namespace e54 { ::KnotVector FUN_00e54630(int, int, float **, ::KnotVector **, float); }
// 0x00e548f0
bool *IsSampleBoundary(bool *, int, float **, int);
// 0x00e54ae0
// 0x00e54b20
void LookupAndConsume(::FUN_00e54b20_src *, unsigned int);
// 0x00e54b50
float Vector4NormalizedDot(const ::E54B50Vector4 &, const ::E54B50Vector4 &);
// 0x00e54ba0
float FUN_00e54ba0(const ::FUN_00e54ad0_cls &, const ::FUN_00e54ad0_cls &);
// 0x00e54c10
void FUN_00e54c10(int, ::L *);
// 0x00e54cb0
float FUN_00e54cb0(int, int, float **, void *, const ::SampleVec *, int, int, float, float);
// 0x00e54fa0
void FUN_00e54fa0(int, ::CurveArg<float **>, ::CurveArg<int>, ::CurveArg<int>, ::CurveArg<int>, ::CurveArg<int>, ::CurveArg<float **>, ::CurveArg<float **>, ::CurveArg<int>, ::CurveArg<int>, float, float, bool);
