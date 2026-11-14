#pragma once

namespace fnv_00c7a990 { struct S_arr; }
namespace fnv_00c7a990 { struct S_item; }
struct InputMap;
struct ObjectContext;
struct S_c7a410_Obj;

// 0x00c7a2d0
void EnableBehaviorsByKind(::InputMap *);
// 0x00c7a380
void UpdateEntriesByKind(::ObjectContext *);
// 0x00c7a410
void FUN_00c7a410(::S_c7a410_Obj *, char *);
// 0x00c7a990
namespace fnv_00c7a990 { void CollectItemValues(::fnv_00c7a990::S_item *, ::fnv_00c7a990::S_arr *, ::fnv_00c7a990::S_arr *); }
