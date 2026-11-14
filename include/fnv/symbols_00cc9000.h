#pragma once

namespace fnv_00cc9e60 { struct bhkBvTreeShape; }
struct PhysicsObject;
struct S00cc96b0_ScaleObject;

// 0x00cc96b0
void FUN_00cc96b0(float, ::S00cc96b0_ScaleObject *);
// 0x00cc9700
::PhysicsObject *CreatePhysicsObject();
// 0x00cc9e60
namespace fnv_00cc9e60 { ::fnv_00cc9e60::bhkBvTreeShape *CreateBhkBvTreeShape(); }
