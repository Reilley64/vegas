#pragma once
#include <cstdint>

struct D88310Bool;
struct D88310Stream;
struct D88470Elem;
struct D88470Obj;
struct D88580Entity;
struct S883_Island;
struct S883_TaskHeader;
struct S88_Array;
struct S88_Instance;
struct S88_QueryIn;
struct S88_Resources;
struct S88b50_Entity;
struct S88b50_Island;
struct State;
struct hkStepInfoD881;
struct hkStepInfoD886;
struct hkpConstraintQueryInD881;
struct hkpConstraintSolverResourcesD881;
struct hkpConstraintSolverResourcesD886;
struct hkpEntityD886;
struct hkpSolverInfoD881;

// 0x00d88040
void FUN_00d88040(int);
// 0x00d881d0
void InitializeConstraintSolverResources(::hkStepInfoD881 *, ::hkpSolverInfoD881 *, ::hkpConstraintQueryInD881 *, char *, int, ::hkpConstraintSolverResourcesD881 *);
// 0x00d88300
void FUN_00d88300();
// 0x00d88310
::D88310Bool FUN_00d88310(const ::D88310Stream *, const void *, int);
// 0x00d88340
void FUN_00d88340(::State *, int);
// 0x00d883c0
intptr_t FUN_00d883c0(const ::S883_Island &, char *, int, ::S883_TaskHeader &);
// 0x00d88470
::D88310Bool CheckTotalsWithinLimits(::D88470Obj *, ::D88470Elem **, int);
// 0x00d88580
void FUN_00d88580(void *, void *, int, ::D88580Entity **, int);
// 0x00d88670
void FUN_00d88670(::hkpConstraintSolverResourcesD886 &, ::hkpEntityD886 *const *, unsigned int);
// 0x00d88760
void FUN_00d88760(::S88_Resources &, ::S88_Instance **, int, ::S88_Array &);
// 0x00d889f0
namespace fnv_00d889f0 { void *FUN_00d889f0(void *); }
// 0x00d88b50
int FUN_00d88b50(const ::hkStepInfoD886 &, const void *, ::S88_QueryIn &, ::S88b50_Island &, void *, int, ::S88b50_Entity *const *, int);
