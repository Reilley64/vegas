#pragma once

class A27250FloatKey;
class A27250Stream;
class A27C80Point3;
namespace fnv_00a27e40 { struct Vec3Output; }
namespace sa27320 { struct Key; }
namespace sa27320 { struct Stream; }
struct A27760Data;
struct A27BD0BezKey;
struct A27C80CubicKey;
struct AnimTarget;
struct BezFloatKey;
struct FUN_00a27b60_rec;
struct P3;
struct PKey;
struct TCBKeyS;
struct TempArrayElement;
struct Vec3S;

// 0x00a27040
::TempArrayElement *AllocateTempArray(unsigned int);
// 0x00a27080
bool FUN_00a27080(float, ::BezFloatKey *&, unsigned int &);
// 0x00a27250
::A27250FloatKey *LoadFloatKeys(::A27250Stream &, unsigned int);
// 0x00a27320
namespace sa27320 { void SaveKeys(::sa27320::Stream &, const ::sa27320::Key *, unsigned int); }
// 0x00a273a0
int FUN_00a273a0();
// 0x00a27450
void ApplyAnimToTarget(int, ::AnimTarget *);
// 0x00a27470
void FUN_00a27470(int, int, int, int *);
// 0x00a276a0
::P3 GetKeyPosAtTime(float, ::PKey *, int, unsigned int, unsigned char);
// 0x00a27760
bool AreDataEqual(const ::A27760Data *, const ::A27760Data *);
// 0x00a27b00
int FUN_00a27b00();
// 0x00a27b60
void FUN_00a27b60(::FUN_00a27b60_rec *, const ::FUN_00a27b60_rec *);
// 0x00a27bd0
bool BezKeyEqual(const ::A27BD0BezKey &, const ::A27BD0BezKey &);
// 0x00a27c40
void *AllocateElem64Array(unsigned int);
// 0x00a27c80
void EvaluateCubicKey(float, const ::A27C80CubicKey &, unsigned int, ::A27C80Point3 &);
// 0x00a27d60
void FUN_00a27d60(float, ::TCBKeyS *, uintptr_t, ::Vec3S *);
// 0x00a27e40
namespace fnv_00a27e40 { extern "C" void FUN_00a27e40(float, const float *, uintptr_t, ::fnv_00a27e40::Vec3Output *); }
