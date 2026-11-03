#pragma once

namespace fnv_00da4aa0 { class Q24; }
namespace fnv_00da4aa0 { struct Q14; }
namespace fnv_00da4aa0 { struct Q30; }
namespace fnv_00da4aa0 { struct Q6; }
struct BlockPoolArray;
struct S_00da40e0_AgentData;
struct S_00da40e0_ConstraintOwner;
struct S_00da40e0_ContactMgr;
struct S_00da40e0_Dispatcher;
struct S_00da40e0_Entry;
struct S_00da40e0_Input;

// 0x00da40e0
::S_00da40e0_Entry *ProcessCollisionEntry(const ::S_00da40e0_Input &, ::S_00da40e0_Entry *, ::S_00da40e0_AgentData *);
// 0x00da42b0
void FUN_00da42b0(::BlockPoolArray *, ::S_00da40e0_Dispatcher *, ::S_00da40e0_ContactMgr *, ::S_00da40e0_ConstraintOwner &);
// 0x00da4430
void InitBlockPool(::BlockPoolArray *);
// 0x00da48e0
void FUN_00da48e0(void *, const void *);
// 0x00da4900
void FUN_00da4900(void *, void *);
// 0x00da4aa0
namespace fnv_00da4aa0 { void FUN_00da4aa0(::fnv_00da4aa0::Q30 &, const ::fnv_00da4aa0::Q14 &, const ::fnv_00da4aa0::Q24 *, const unsigned int *, ::fnv_00da4aa0::Q6 &); }
