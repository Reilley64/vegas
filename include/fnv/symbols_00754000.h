#pragma once

namespace fnv_00754de0 { struct ActorOps; }
namespace fnv_00754de0 { struct TileOps; }
struct Actor;
struct FUN_00754460_self;

// 0x00754460
void FUN_00754460(::FUN_00754460_self *, int);
// 0x00754cf0
bool DestroyCompanionWheelMenu(int);
// 0x00754d90
bool FUN_00754d90(::Actor *);
// 0x00754de0
namespace fnv_00754de0 { ::fnv_00754de0::TileOps *OpenCompanionMenu(::fnv_00754de0::ActorOps *); }
