#pragma once

namespace fnv_00d0b040 { struct TargetClass; }
struct EntryList_b2089;
struct FUN_00d0bc20_Outer;
struct FUN_00d0bd30_p;
struct PairEntryArray;
struct World_b2089;

// 0x00d0b040
namespace fnv_00d0b040 { void FUN_00d0b040(::fnv_00d0b040::TargetClass *); }
// 0x00d0bc20
unsigned char *FUN_00d0bc20(unsigned char *, ::FUN_00d0bc20_Outer *, unsigned int);
// 0x00d0bd30
int FUN_00d0bd30(float, ::FUN_00d0bd30_p *, float *, int, char **);
// 0x00d0be80
void PartitionMotionPairs(::PairEntryArray *, int *, int);
// 0x00d0bf30
void FUN_00d0bf30(::World_b2089 *, ::EntryList_b2089 *);
