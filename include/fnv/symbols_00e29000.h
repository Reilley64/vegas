#pragma once

#include "fnv/ray_similarity_math.h"

class S29cd0_hkVector4;
struct E29250Matrix6;
struct FUN_00e29620_class;
struct S29cd0_hkpWorldRayCastBundleCommand;
struct S29cd0_hkpWorldRayCastCommand;
struct S29cd0_hkpWorldRayCastOutput;
struct WrappedPointer;

// 0x00e29250
void FUN_00e29250(::E29250Matrix6 &, const ::E29250Matrix6 &);
// 0x00e29470
void FUN_00e29470(void *, ::WrappedPointer, ::WrappedPointer);
// 0x00e298f0
void FUN_00e298f0(::FUN_00e29620_class *, intptr_t);
// 0x00e29cd0
extern "C" void FUN_00e29cd0(int *, int, const ::S29cd0_hkVector4 *, const ::S29cd0_hkVector4 *, int, float, float, ::S29cd0_hkpWorldRayCastOutput *, ::S29cd0_hkpWorldRayCastCommand *, int &, ::S29cd0_hkpWorldRayCastBundleCommand *, int &);
