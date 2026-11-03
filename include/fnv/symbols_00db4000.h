#pragma once

struct Arg2;
struct Arg3;
struct Arg4;
struct Arg6;
struct In;
struct S_00db4b50_A;
struct S_00db4b50_Out;
struct SweepObj;
struct SweepOut;
struct VecS;

// 0x00db4180
void ProcessCollision(::In *, void *, ::Arg2 *, ::Arg3 *, ::Arg4 *, ::VecS *, ::Arg6 *);
// 0x00db4b50
void FUN_00db4b50(::S_00db4b50_A *, float, ::S_00db4b50_Out *);
// 0x00db4e40
void FUN_00db4e40(::SweepObj *, float *, ::SweepOut *);
