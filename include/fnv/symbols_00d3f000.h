#pragma once

class D3FE10Manager;
namespace fnv_00d3f620 { struct S_00d3f620_Obj; }
namespace fnv_00d3fe90 { struct Params; }
struct Agent;
struct D3FE10Entry;
struct D3FE10Header;
struct D3FE70Info;
struct FUN_00d3fd60_cls;
struct FUN_00d3fd60_cls_Ref;
struct FUN_00d3fda0_table;
struct S_00d3fb20_CdBody;
struct S_00d3fb20_Collector;
struct S_00d3fb20_Input;

// 0x00d3f040
void FUN_00d3f040(const void *, const void *, const void *, void *);
// 0x00d3f4c0
void *FUN_00d3f4c0(void *, void *, void *, int);
// 0x00d3f620
namespace fnv_00d3f620 { ::fnv_00d3f620::S_00d3f620_Obj *FUN_00d3f620(int, int, int, int); }
// 0x00d3fb20
void FUN_00d3fb20(const ::S_00d3fb20_CdBody &, const ::S_00d3fb20_CdBody &, const ::S_00d3fb20_Input &, ::S_00d3fb20_Collector &);
// 0x00d3fce0
namespace fnv_00d3fce0 { void FUN_00d3fce0(void *); }
// 0x00d3fd00
void FUN_00d3fd00(::Agent *);
// 0x00d3fd60
void *RemoveEntryByKey(::FUN_00d3fd60_cls_Ref *, ::FUN_00d3fd60_cls *, unsigned short);
// 0x00d3fda0
int FindOrClaimEntry(int, ::FUN_00d3fda0_table *, unsigned short);
// 0x00d3fe10
::D3FE10Entry *ResetEntryAgents(::D3FE10Header *, ::D3FE10Entry *, ::D3FE10Manager *, void *);
// 0x00d3fe70
::D3FE10Entry *FUN_00d3fe70(::D3FE10Header *, ::D3FE10Entry *, ::D3FE10Manager *, ::D3FE70Info);
// 0x00d3fe90
namespace fnv_00d3fe90 { void *FUN_00d3fe90(::fnv_00d3fe90::Params *, unsigned char *, unsigned char *, int, int); }
