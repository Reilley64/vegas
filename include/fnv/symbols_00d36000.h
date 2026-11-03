#pragma once
#include <cstdint>

class hkpCollisionDispatcherD367;
struct A1Rec;
struct D362Script;
struct FUN_00d36270_s;
struct FUN_00d36b20;
struct SortEntry;
struct SortEntryLess;
struct SortPair;

// 0x00d36270
void FUN_00d36270(::FUN_00d36270_s *);
// 0x00d362c0
void FUN_00d362c0(::D362Script *);
// 0x00d36360
void FUN_00d36360(::SortEntry *, int, int, ::SortEntryLess);
// 0x00d36520
extern "C" void FUN_00d36520(::SortPair *, int, int, unsigned int);
// 0x00d365d0
int FUN_00d365d0(::A1Rec *, int, int, int, int);
// 0x00d367b0
void FUN_00d367b0(intptr_t);
// 0x00d367d0
void FUN_00d367d0(::hkpCollisionDispatcherD367 *);
// 0x00d36920
void FUN_00d36920();
// 0x00d36930
extern "C" void FUN_00d36930();
// 0x00d36940
void FUN_00d36940(void *, void *, void *, void *);
// 0x00d36960
void FUN_00d36960(intptr_t, intptr_t, intptr_t, intptr_t, intptr_t);
// 0x00d36990
void FUN_00d36990();
// 0x00d36b00
void FUN_00d36b00(int, int, int, int);
// 0x00d36b70
::FUN_00d36b20 *FUN_00d36b70(int, int, int *, int);
// 0x00d36bb0
void FUN_00d36bb0(void **);
// 0x00d36be0
namespace fnv_00d36be0 { void *FUN_00d36be0(int, int, int, int); }
// 0x00d36c60
void FUN_00d36c60(void *);
