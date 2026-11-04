#pragma once
#include <cstdint>

class NiAVObject;
class ShadowSceneNode;
namespace fnv_00b5b260 { struct LightOwnerA; }
namespace fnv_00b5b260 { struct LightOwnerB; }
namespace fnv_00b5b260 { struct S00b5b260_Geom; }
namespace fnv_00b5b410 { struct Light; }
namespace fnv_00b5b410 { struct Obj; }
struct FUN_00b5b4a0_item;
struct FUN_00b5b4a0_self;

// 0x00b5b060
void FUN_00b5b060(char *, int);
// 0x00b5b150
void ProcessNodeChildren(void *, int, void *);
// 0x00b5b1c0
void FUN_00b5b1c0(::ShadowSceneNode *, intptr_t, ::NiAVObject *);
// 0x00b5b1f0
void FUN_00b5b1f0(::ShadowSceneNode *, int);
// 0x00b5b260
namespace fnv_00b5b260 { bool FUN_00b5b260(::fnv_00b5b260::S00b5b260_Geom *, ::ShadowSceneNode *, void *, ::fnv_00b5b260::LightOwnerA *, ::fnv_00b5b260::LightOwnerB *); }
// 0x00b5b410
namespace fnv_00b5b410 { bool FUN_00b5b410(::fnv_00b5b410::Obj *, void *, ::fnv_00b5b410::Light **, bool); }
// 0x00b5b4a0
::FUN_00b5b4a0_item *FUN_00b5b4a0(::FUN_00b5b4a0_self *, int, int);
