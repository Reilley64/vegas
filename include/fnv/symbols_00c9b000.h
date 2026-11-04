#pragma once

class NiAVObject;
class NiPoint3;
class Obj_c9b;
namespace fnv_00c9b470 { struct Scene; }
struct FUN_00c9aeb0_t;
struct SceneObject;

// 0x00c9b020
::FUN_00c9aeb0_t *FUN_00c9b020();
// 0x00c9b250
void FUN_00c9b250(::SceneObject *, float, bool);
// 0x00c9b470
namespace fnv_00c9b470 { void ApplyCollisionEffect(::fnv_00c9b470::Scene *, float); }
// 0x00c9b670
void FUN_00c9b670(::NiAVObject *, const ::NiPoint3 &, unsigned int, float, bool);
// 0x00c9bdf0
void FUN_00c9bdf0(::Obj_c9b *, float);
