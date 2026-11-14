#pragma once

class BE04D90Object;
namespace fnv_00e04bb0 { struct TypeNode; }
namespace fnv_00e04bb0 { struct VisitMap; }
struct Member;
struct TypeNode;
struct VisitMap;

// 0x00e049c0
int FUN_00e049c0(int, int);
// 0x00e04af0
void VisitTypeMembers(::TypeNode *, ::VisitMap *, unsigned int, void (*)(Member *));
// 0x00e04bb0
namespace fnv_00e04bb0 { void VisitTypeNode(::fnv_00e04bb0::TypeNode *, ::fnv_00e04bb0::VisitMap *); }
// 0x00e04d30
void RegisterContextHandlers(void *, void *, int);
// 0x00e04d90
void ProcessObjectArray(::BE04D90Object **, int);
