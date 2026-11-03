#pragma once

struct A6830Actor;
struct A69C0Actor;
struct A69C0Weapon;
struct Actor;
struct ConeRef;
struct NiPoint3;
struct S_009a6770_Ref;
struct S_009a68b0_Obj;
struct S_009a68b0_Pt;
struct S_009a68b0_Ref;
struct S_009a6d70_Actor;
struct S_9a64d0_Ref;

// 0x009a60e0
::Actor *FUN_009a60e0(::Actor *, float);
// 0x009a64d0
float FUN_009a64d0(::S_9a64d0_Ref *, ::S_9a64d0_Ref *, bool);
// 0x009a6770
float FUN_009a6770(::S_009a6770_Ref *, ::S_009a6770_Ref *);
// 0x009a6830
float FUN_009a6830(::A6830Actor *, int, float);
// 0x009a68b0
::S_009a68b0_Pt FUN_009a68b0(::S_009a68b0_Ref *, ::S_009a68b0_Obj *, ::S_009a68b0_Pt *, float);
// 0x009a69c0
float GetActorReach(::A69C0Actor *, ::A69C0Weapon *);
// 0x009a6ae0
bool IsTargetInCone(::ConeRef *, ::ConeRef *, float *);
// 0x009a6d70
bool IsWithinAimLimits(::S_009a6d70_Actor *, ::NiPoint3 *, float, float);
// 0x009a6e90
bool FUN_009a6e90(void *, void *, float, float, float, float, float, float, float, ::NiPoint3 *, int *, float *);
