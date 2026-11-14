#pragma once

namespace ProcessAgentCFEDD0 { struct hkpAgentNnEntryProcessAgentCFEDD0; }
namespace ProcessAgentCFEDD0 { struct hkpProcessCollisionInputProcessAgentCFEDD0; }
namespace ProcessAgentCFEDD0 { struct hkpProcessCollisionOutputProcessAgentCFEDD0; }
namespace fnv_00cfeca0 { struct Record; }
namespace fnv_00cfeca0 { struct State; }
struct CFE820Pool;
struct CollidableBody;
struct CollidableNode;
struct CollisionAgentEntry;
struct Dispatcher;
struct Entry;
struct FUN_00cfeba0_Obj;
struct S_cfe020_Entry;
struct S_cfe020_Pool;
struct Vector;
struct hkpAgentNnEntryCFEA;
struct hkpCollisionDispatcherCFEA;

// 0x00cfe020
void FUN_00cfe020(::S_cfe020_Pool *, ::S_cfe020_Entry *);
// 0x00cfe1d0
::Entry *FUN_00cfe1d0(::Entry *, ::Entry *, ::Vector *, unsigned int, unsigned char *);
// 0x00cfe8a0
::CollisionAgentEntry *FUN_00cfe8a0(::CFE820Pool *, ::CollidableNode *, ::CollidableBody *, ::CollidableNode *, ::CollidableBody *, unsigned char, int, ::Dispatcher *, void *);
// 0x00cfea30
void FUN_00cfea30(void *, ::hkpAgentNnEntryCFEA *, ::hkpCollisionDispatcherCFEA *, void *);
// 0x00cfeba0
void FUN_00cfeba0(::FUN_00cfeba0_Obj *, void **, void *);
// 0x00cfeca0
namespace fnv_00cfeca0 { ::fnv_00cfeca0::Record *CloneRecord(::fnv_00cfeca0::State *, const ::fnv_00cfeca0::Record *); }
// 0x00cfedd0
namespace ProcessAgentCFEDD0 { extern "C" void FUN_00cfedd0(::ProcessAgentCFEDD0::hkpAgentNnEntryProcessAgentCFEDD0 *, const ::ProcessAgentCFEDD0::hkpProcessCollisionInputProcessAgentCFEDD0 &, ::ProcessAgentCFEDD0::hkpProcessCollisionOutputProcessAgentCFEDD0 &); }
