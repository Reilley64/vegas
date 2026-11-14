#pragma once

struct FnvBool;
struct NativeInput;
struct NativeOutput;
struct NativePose;
struct NativeSolver;
struct RayHit;
struct RayIn;

// 0x00cd85c0
::FnvBool FUN_00cd85c0(float, const ::RayIn &, ::RayHit &);
// 0x00cd8d90
extern "C" void FUN_00cd8d90(::NativeSolver *, void *, const ::NativeInput &, ::NativeOutput &, ::NativePose &);
