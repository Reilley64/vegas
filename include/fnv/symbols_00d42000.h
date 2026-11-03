#pragma once

namespace fnv_00d42800 { class D42800Agent; }
namespace fnv_00d42800 { struct D42800CdBody; }
namespace fnv_00d42800 { struct D42800CollisionInput; }
namespace fnv_00d42800 { struct D42800ContactMgr; }
struct Agent;
struct CollisionBody_00d42f40;
struct CollisionInput_00d42f40;
struct FUN_00d42730_obj;
struct Header;
struct InputA;
struct InputB;
struct InputC;
struct S_00d42d60_CdBody;
struct S_00d42d60_Collector;
struct S_00d42d60_Input;

// 0x00d42730
int CallVirtualMethod(int, int, int, ::FUN_00d42730_obj *);
// 0x00d42800
namespace fnv_00d42800 { ::fnv_00d42800::D42800Agent *FUN_00d42800(const ::fnv_00d42800::D42800CdBody &, const ::fnv_00d42800::D42800CdBody &, const ::fnv_00d42800::D42800CollisionInput &, ::fnv_00d42800::D42800ContactMgr *); }
// 0x00d42960
void FUN_00d42960(::Agent *);
// 0x00d42a70
::Header *BuildHeaderAndDispatchHandler(::InputA *, ::InputB *, ::InputC *, void *);
// 0x00d42d60
void DispatchClosestPoints(const ::S_00d42d60_CdBody &, const ::S_00d42d60_CdBody &, const ::S_00d42d60_Input &, ::S_00d42d60_Collector *, ::S_00d42d60_Collector *);
// 0x00d42e50
void FUN_00d42e50(const ::CollisionBody_00d42f40 *, const ::CollisionBody_00d42f40 *, const ::CollisionInput_00d42f40 *, void *);
// 0x00d42f40
void ProcessTransformShapeCollision(const ::CollisionBody_00d42f40 *, const ::CollisionBody_00d42f40 *, const ::CollisionInput_00d42f40 *, void *);
