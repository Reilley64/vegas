#pragma once

namespace fnv_00d94340 { class Target_00d94340; }
namespace fnv_00d94340 { struct Arg_00d94340; }
namespace fnv_00d94570 { struct Fnv94570_Ctx; }
namespace fnv_00d94570 { struct Fnv94570_Obj; }
struct Arg0;
struct Arg1;
struct Arg2;
struct D942F0Island;
struct D94Body;
struct D94Obj;
struct S00d944d0_Arg1;
struct S00d944d0_Arg2;
struct S00d944d0_Obj;
struct S00d947e0_Data;
struct S00d947e0_Obj;
struct S00d947e0_Queue;
struct S_00d943d0_Ctx;
struct S_00d943d0_Item;
struct S_00d943d0_Obj;
struct S_00d94c40_Context;
struct S_00d94c40_Job;
struct S_00d94c40_JobQueue;
struct SolverObject;

// 0x00d942f0
void ClearFlagsAndMarkDirty(::D942F0Island *, void *);
// 0x00d94340
namespace fnv_00d94340 { void FUN_00d94340(int, ::fnv_00d94340::Target_00d94340 *, ::fnv_00d94340::Arg_00d94340 *); }
// 0x00d943d0
void FUN_00d943d0(::S_00d943d0_Ctx *, ::S_00d943d0_Obj *, ::S_00d943d0_Item *);
// 0x00d944d0
void FUN_00d944d0(::S00d944d0_Obj *, ::S00d944d0_Arg1 *, ::S00d944d0_Arg2 *);
// 0x00d94570
namespace fnv_00d94570 { void FUN_00d94570(::fnv_00d94570::Fnv94570_Obj **, void *, ::fnv_00d94570::Fnv94570_Ctx *); }
// 0x00d94670
void LogIntegrateVelocity(::Arg0 *, ::Arg1 *, ::Arg2 *);
// 0x00d94730
void FUN_00d94730(::Arg0 *, ::Arg1 *, ::SolverObject *);
// 0x00d947e0
void FUN_00d947e0(::S00d947e0_Obj **, ::S00d947e0_Queue *, ::S00d947e0_Data *);
// 0x00d94a80
void FUN_00d94a80(::Arg0 *, ::Arg1 *, ::Arg2 *);
// 0x00d94c40
void ExecuteConstraintCallbacks(::S_00d94c40_Context *, ::S_00d94c40_JobQueue *, ::S_00d94c40_Job *);
// 0x00d94df0
int FUN_00d94df0(char *, ::D94Obj *, ::D94Body *);
