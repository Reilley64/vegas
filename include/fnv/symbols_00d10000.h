#pragma once

struct BpBoundNode;
struct BpBoundWords;
struct D107A0RTTI;
struct Entry;
struct S00d10b30_Bnd;
struct S00d10b30_Node;

// 0x00d10790
::D107A0RTTI *FUN_00d10790();
// 0x00d107a0
const ::D107A0RTTI *FUN_00d107a0();
// 0x00d10b30
void FUN_00d10b30(::S00d10b30_Node *, int, const ::S00d10b30_Bnd *);
// 0x00d10d10
void FUN_00d10d10(::BpBoundNode *, int, const ::BpBoundWords *);
// 0x00d10ea0
::Entry *LowerBoundEntry(::Entry *, ::Entry *, unsigned short);
