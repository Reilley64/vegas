#pragma once

enum S00cb4230_MotionType;
namespace fnv_00cb4000 { struct ListItem; }
namespace fnv_00cb4000 { struct ListOwner; }
namespace fnv_00cb4640 { struct TaskCtx; }
namespace fnv_00cb4790 { struct Array; }
namespace fnv_00cb4790 { struct ActorOwner; }
namespace fnv_00cb4790 { struct EntryOwner; }
struct MotionFlag31;
struct Node4;
struct Obj;
struct ThisObj;
struct hkpSimulationIsland;
struct hkpWorld;

// 0x00cb4000
namespace fnv_00cb4000 { void RemoveListItem(::fnv_00cb4000::ListOwner *, ::fnv_00cb4000::ListItem *volatile); }
// 0x00cb4230
void FUN_00cb4230(::ThisObj *, ::S00cb4230_MotionType, ::MotionFlag31, ::MotionFlag31, ::Node4 *);
// 0x00cb4640
namespace fnv_00cb4640 { void FUN_00cb4640(::fnv_00cb4640::TaskCtx *, ::fnv_00cb4640::TaskCtx *, int); }
// 0x00cb4740
void FUN_00cb4740(::Obj *, ::Obj *);
// 0x00cb4790
namespace fnv_00cb4790 { void CollectActorEntries(::fnv_00cb4790::ActorOwner *, ::fnv_00cb4790::EntryOwner *, ::fnv_00cb4790::Array *); }
// 0x00cb4c60
void FUN_00cb4c60(::hkpWorld *, ::hkpSimulationIsland *, ::hkpSimulationIsland *);
