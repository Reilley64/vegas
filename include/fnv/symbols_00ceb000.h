#pragma once

struct hkVector4;
struct BodyList;
struct ConstraintList;
struct FUN_00cebe80_Struct;
struct MassProperties;
struct Receiver2;
struct Skeleton;
struct Target;
struct V4;
struct hkBool;

// 0x00ceb2c0
::Skeleton *FUN_00ceb2c0(::BodyList *, ::ConstraintList *);
// 0x00ceb8d0
::hkBool IsDegenerateTriangle(const ::hkVector4 &, const ::hkVector4 &, const ::hkVector4 &, float);
// 0x00ceba60
int FUN_00ceba60(float, float, ::Target *);
// 0x00cebaf0
int FUN_00cebaf0(const ::V4 &, float, ::MassProperties &);
// 0x00cebbb0
int FUN_00cebbb0(void *, float, ::Receiver2 *);
// 0x00cebe80
void FUN_00cebe80(::FUN_00cebe80_Struct *, float, float *);
// 0x00cebf30
void AddInertiaTensor(float *, float, float *);
