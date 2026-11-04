#pragma once

#include <cstdint>

class BA2BA10Stream;
namespace fnv_00a2bc60 { struct SpawnTarget; }
struct A2BBF0Record;
struct A2BDE0BezRotKey;
struct ArrayElementA2BE60;
struct BA2BA10Key;
struct BezPosKey;
struct Inner_00a6db50;
struct PositionSplineKey;
struct S_00a2b050_Obj;
struct S_00a2b050_V3;
struct Spl_a2b6d0_Key;
struct Vector3;

// 0x00a2b050
::S_00a2b050_V3 *ComputeInterpolatedPosition(float, ::S_00a2b050_Obj *, uintptr_t, ::S_00a2b050_V3 *);
// 0x00a2b130
void FUN_00a2b130(float, const float *, uintptr_t, ::Vector3 *);
// 0x00a2b410
void FUN_00a2b410(::PositionSplineKey *, unsigned int);
// 0x00a2b6d0
float FUN_00a2b6d0(::Spl_a2b6d0_Key *, int);
// 0x00a2b850
bool InsertBezPosKey(float, ::BezPosKey **, unsigned int *);
// 0x00a2ba10
void SaveKey(::BA2BA10Stream &, ::BA2BA10Key *);
// 0x00a2baa0
void FUN_00a2baa0(int, int);
// 0x00a2bb00
namespace fnv_00a2bb00 { void *AllocateElement76Array(std::intptr_t, unsigned int); }
// 0x00a2bb60
void FUN_00a2bb60(std::intptr_t, std::intptr_t, unsigned int);
// 0x00a2bb90
namespace fnv_00a2bb90 { int FUN_00a2bb90(); }
// 0x00a2bbf0
void FUN_00a2bbf0(::A2BBF0Record *, const ::A2BBF0Record *);
// 0x00a2bc60
namespace fnv_00a2bc60 { void InvokeSpawnTarget(float, char *, char *, ::fnv_00a2bc60::SpawnTarget *); }
// 0x00a2bc90
::Inner_00a6db50 *ScaleAndApply(::Inner_00a6db50 *, float, const float *);
// 0x00a2bde0
bool BezRotKeyEqual(const ::A2BDE0BezRotKey &, const ::A2BDE0BezRotKey &);
// 0x00a2be60
::ArrayElementA2BE60 *FUN_00a2be60(unsigned int);
