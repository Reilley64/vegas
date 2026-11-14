#pragma once

class BSBatchRenderer;
namespace fnv_00b9ac80 { struct SortBound; }
namespace fnv_00b9ac80 { struct SortCamera; }
struct FUN_00b9a4d0_Obj;

// 0x00b9a4d0
void FUN_00b9a4d0(::FUN_00b9a4d0_Obj *, int, int);
// 0x00b9abc0
void DispatchPass(void *, int, void *, bool);
// 0x00b9ac80
namespace fnv_00b9ac80 { void AddSortedGroup(::BSBatchRenderer *, int, ::fnv_00b9ac80::SortBound *, bool, ::fnv_00b9ac80::SortCamera *, bool); }
