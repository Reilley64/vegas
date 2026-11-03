#pragma once

#include <cstdint>

class D85660Object;
namespace fnv_00d853a0 { struct FUN_00d853a0_cls; }
namespace fnv_00d853f0 { struct ObjD853; }
namespace fnv_00d85440 { class D85440Shape; }
namespace fnv_00d854e0 { struct D_Stub; }
namespace fnv_00d854e0 { struct Src_Stub; }
namespace fnv_00d85530 { struct SpawnedObject; }
namespace fnv_00d85530 { struct SpawnedSource; }
namespace fnv_00d85570 { struct FUN_00d85570_cls; }
namespace fnv_00d85610 { struct FUN_00d85610_cls; }
namespace fnv_00d856b0 { struct FUN_00d856b0_cls; }
struct D85Msg;
struct FUN_00d85360_cls;
struct ListenerOwner;
struct Object858;

// 0x00d85360
::FUN_00d85360_cls *FUN_00d85360(intptr_t);
// 0x00d853a0
namespace fnv_00d853a0 { ::fnv_00d853a0::FUN_00d853a0_cls *FUN_00d853a0(intptr_t); }
// 0x00d853f0
namespace fnv_00d853f0 { ::fnv_00d853f0::ObjD853 *FUN_00d853f0(char *); }
// 0x00d85440
namespace fnv_00d85440 { ::fnv_00d85440::D85440Shape *CloneShape(const ::fnv_00d85440::D85440Shape *); }
// 0x00d85490
namespace fnv_00d85490 { void *CloneAllocatedObject(int *); }
// 0x00d854e0
namespace fnv_00d854e0 { ::fnv_00d854e0::D_Stub *CloneStub(::fnv_00d854e0::Src_Stub *); }
// 0x00d85530
namespace fnv_00d85530 { ::fnv_00d85530::SpawnedObject *FUN_00d85530(::fnv_00d85530::SpawnedSource *); }
// 0x00d85570
namespace fnv_00d85570 { ::fnv_00d85570::FUN_00d85570_cls *CloneWithInit(intptr_t); }
// 0x00d855c0
namespace fnv_00d855c0 { void *CloneDataBlock(void *); }
// 0x00d85610
namespace fnv_00d85610 { ::fnv_00d85610::FUN_00d85610_cls *CloneWithCopiedPayload(intptr_t); }
// 0x00d85660
::D85660Object *FUN_00d85660(const ::D85660Object *);
// 0x00d856b0
namespace fnv_00d856b0 { ::fnv_00d856b0::FUN_00d856b0_cls *CloneWithAllocatedCopy(intptr_t); }
// 0x00d85700
::Object858 *FUN_00d85700(::Object858 *);
// 0x00d858f0
::Object858 *FUN_00d858f0(::Object858 *);
// 0x00d85ef0
void FUN_00d85ef0(::ListenerOwner *);
// 0x00d85fa0
void FUN_00d85fa0(::D85Msg);
