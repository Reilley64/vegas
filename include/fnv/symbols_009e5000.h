#pragma once

class Actor;
namespace fnv_009e5690 { class Actor; }
namespace fnv_009e5690 { struct PathingRequest; }
namespace fnv_009e5690 { struct ActorAvoidEntryList; }
namespace fnv_009e5690 { struct NiPoint3_ext; }
struct TES;

// 0x009e54a0
namespace fnv_009e54a0 { bool UpdateAliveActorList(); }
// 0x009e55e0
::Actor *FUN_009e55e0(::TES *);
// 0x009e5690
namespace fnv_009e5690 { void EvaluateAvoidance(::fnv_009e5690::Actor *, ::fnv_009e5690::PathingRequest *, unsigned int, const ::fnv_009e5690::NiPoint3_ext *, void *, ::fnv_009e5690::ActorAvoidEntryList *); }
