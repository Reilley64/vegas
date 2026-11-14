#pragma once

namespace fnv_00cb5000 { struct OwnerObj; }
namespace fnv_00cb5000 { struct PtrVec; }
namespace fnv_00cb5420 { struct S_00cb5420_Container; }
namespace fnv_00cb5420 { struct S_00cb5420_Item; }
namespace fnv_00cb5480 { struct ListItem; }
namespace fnv_00cb5480 { struct LockedList; }
namespace fnv_00cb5500 { struct Entry; }
namespace fnv_00cb59f0 { struct S_00cb59f0_A; }
namespace fnv_00cb59f0 { struct S_00cb59f0_B; }
namespace fnv_00cb5b10 { struct EntityRec; }
namespace fnv_00cb5b10 { struct WorldRec; }
namespace fnv_00cb5dd0 { struct Context; }
namespace fnv_00cb5dd0 { struct Manager; }
namespace fnv_00cb5dd0 { struct Producer; }
namespace fnv_00cb5dd0 { template <class> struct Array; }
namespace fnv_00cb5f50 { struct S_00cb5f50_Constraint; }
namespace fnv_00cb5f50 { struct S_00cb5f50_Entity; }
namespace fnv_00cb5f50 { struct S_00cb5f50_World; }
namespace fnv_00cb5f50 { template <class> struct S_00cb5f50_Array; }
struct Evt;
struct ObjA;
struct ObjB;
struct Owner;
struct S00cb5100_Body;
struct S00cb5100_World;
struct S00cb5310_Node;
struct S00cb5310_Owner;
struct S55Owner;
struct S_00cb5d00_Owner;
struct S_00cb5d00_Query;

// 0x00cb5000
namespace fnv_00cb5000 { void FUN_00cb5000(::fnv_00cb5000::OwnerObj *, ::fnv_00cb5000::PtrVec *); }
// 0x00cb5100
void FUN_00cb5100(::S00cb5100_World *, ::S00cb5100_Body *, bool);
// 0x00cb5310
void FUN_00cb5310(::S00cb5310_Owner *, ::S00cb5310_Node *);
// 0x00cb5420
namespace fnv_00cb5420 { void AddItemToContainer(::fnv_00cb5420::S_00cb5420_Container *, ::fnv_00cb5420::S_00cb5420_Item *); }
// 0x00cb5480
namespace fnv_00cb5480 { void FUN_00cb5480(::fnv_00cb5480::LockedList *, ::fnv_00cb5480::ListItem *); }
// 0x00cb5500
namespace fnv_00cb5500 { void AddEntryToList(void *, ::fnv_00cb5500::Entry *); }
// 0x00cb5570
void FUN_00cb5570(::ObjA *, ::ObjB *, ::ObjB *);
// 0x00cb55d0
void FUN_00cb55d0(::S55Owner *);
// 0x00cb59f0
namespace fnv_00cb59f0 { void FUN_00cb59f0(::fnv_00cb59f0::S_00cb59f0_A *, ::fnv_00cb59f0::S_00cb59f0_B *); }
// 0x00cb5b10
namespace fnv_00cb5b10 { void QueryEntityIntoBuffer(::fnv_00cb5b10::WorldRec *, ::fnv_00cb5b10::EntityRec *); }
// 0x00cb5c10
void FUN_00cb5c10(::Owner *, ::Evt *);
// 0x00cb5d00
void FUN_00cb5d00(::S_00cb5d00_Owner *, ::S_00cb5d00_Query *);
// 0x00cb5dd0
namespace fnv_00cb5dd0 { void CollectProducers(::fnv_00cb5dd0::Context *, ::fnv_00cb5dd0::Manager *, ::fnv_00cb5dd0::Array< ::fnv_00cb5dd0::Producer> *); }
// 0x00cb5f50
namespace fnv_00cb5f50 { void ApplyConstraintsToEntity(::fnv_00cb5f50::S_00cb5f50_World *, ::fnv_00cb5f50::S_00cb5f50_Entity *, const ::fnv_00cb5f50::S_00cb5f50_Array< ::fnv_00cb5f50::S_00cb5f50_Constraint *> *); }
