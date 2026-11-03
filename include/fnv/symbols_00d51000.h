#pragma once

class hkpGenericConstraintDataScheme;
namespace fnv_00d51170 { struct AnglePool; }
namespace fnv_00d51170 { struct AngleRecord; }
struct D51760Buffer;
struct D51760Stats;
struct GenericConstraintRuntime;
struct SixteenWordFloatRecord;
struct SolverStateD510;
struct d51390_ctx;
struct d51390_pool;
struct hkVector4;

// 0x00d51060
void FUN_00d51060(const char **, const float **, void *, ::SolverStateD510 *, void *, void *);
// 0x00d51100
void FUN_00d51100(int **, int *, void *, int *, int *, int);
// 0x00d51170
namespace fnv_00d51170 { void FUN_00d51170(int **__restrict, ::fnv_00d51170::AngleRecord **, int, ::fnv_00d51170::AnglePool *, void *, void *); }
// 0x00d51270
void FUN_00d51270(const int **, const ::hkVector4 **, ::hkpGenericConstraintDataScheme *, ::GenericConstraintRuntime *, ::SixteenWordFloatRecord *, void **);
// 0x00d51390
void FUN_00d51390(int **, float **, int, ::d51390_pool *, ::d51390_ctx *, void *);
// 0x00d51760
void FUN_00d51760(::D51760Buffer *, ::D51760Stats *);
