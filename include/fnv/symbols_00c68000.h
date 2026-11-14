#pragma once

class C6A2E0AVObject;
namespace sc68e90 { struct Event; }
struct CollisionObjectCountContext;
struct NiCollisionObject;
struct S_00c68900_Context;
struct S_00c68900_Node;
struct SourcePoint;

// 0x00c68750
void FUN_00c68750(const ::SourcePoint *);
// 0x00c68900
void FUN_00c68900(::S_00c68900_Node *, ::S_00c68900_Context *, void (*)(void *, S_00c68900_Context *));
// 0x00c68e90
namespace sc68e90 { void FUN_00c68e90(void *, ::sc68e90::Event *); }
// 0x00c68ec0
bool FUN_00c68ec0(::C6A2E0AVObject *, ::CollisionObjectCountContext *, void (*)(NiCollisionObject *, CollisionObjectCountContext *));
