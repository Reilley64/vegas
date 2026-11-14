#pragma once

struct CallTarget;
struct DispatchContext;
struct DispatchNode;
struct SortPair8;

// 0x00d04200
void QuickSortPairs(::SortPair8 *, int, int, bool (*)(const SortPair8 *, const SortPair8 *));
// 0x00d04380
int FUN_00d04380(void *, int);
// 0x00d043b0
int FUN_00d043b0(void *);
// 0x00d043c0
int FUN_00d043c0(::CallTarget *, int);
// 0x00d043d0
int FUN_00d043d0();
// 0x00d043e0
int FUN_00d043e0();
// 0x00d04550
int FUN_00d04550(void *, void *, void *);
// 0x00d04570
int FUN_00d04570(::DispatchContext *, int, ::DispatchNode *);
