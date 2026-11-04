#pragma once

namespace fnv_00c8e800 { struct Object; }
namespace fnv_00c8e800 { struct Vector; }
struct HavokObject;
struct SpawnedObject;
struct StrArr;

// 0x00c8e800
namespace fnv_00c8e800 { void AccumulateCenterOfMass(::fnv_00c8e800::Object *, ::fnv_00c8e800::Vector *, float *); }
// 0x00c8ecf0
void FUN_00c8ecf0(::HavokObject *);
// 0x00c8ed70
::SpawnedObject *FUN_00c8ed70();
// 0x00c8ee20
void AddMotionTypeName(::StrArr *, int);
