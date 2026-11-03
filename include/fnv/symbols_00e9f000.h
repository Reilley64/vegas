#pragma once

namespace fnv_00e9fdc0 { struct Capsule; }
namespace fnv_00e9fdc0 { struct Vec3; }
struct Capsule;
struct S_00e9f400_P3;
struct S_Capsule;
struct S_Sphere;
struct S_Vec3;
struct Vec3;
struct Vec3e;

// 0x00e9f400
bool FUN_00e9f400(float, int, int, int, int, float *, ::S_00e9f400_P3 *, bool, ::S_00e9f400_P3 *, ::S_00e9f400_P3 *);
// 0x00e9f510
bool FUN_00e9f510(float, int, int, int, int, float *, ::Vec3e *, bool, ::Vec3e *, ::Vec3e *);
// 0x00e9f620
bool SweepSphereAgainstCapsule(float, ::S_Capsule *, const ::S_Vec3 *, ::S_Sphere *, const ::S_Vec3 *);
// 0x00e9f760
bool IsCapsuleSweptHit(float, ::S_Capsule *, const ::S_Vec3 *, ::S_Capsule *, const ::S_Vec3 *);
// 0x00e9f8c0
bool CapsuleTriangleIntersect(float, ::Capsule *, ::Vec3 *, ::Vec3 *, ::Vec3 *, ::Vec3 *, ::Vec3 *);
// 0x00e9fdc0
namespace fnv_00e9fdc0 { bool FUN_00e9fdc0(float, ::fnv_00e9fdc0::Capsule *, ::fnv_00e9fdc0::Vec3 *, const ::fnv_00e9fdc0::Vec3 *, ::fnv_00e9fdc0::Vec3 *, ::fnv_00e9fdc0::Vec3 *, ::fnv_00e9fdc0::Vec3 *, float *, ::fnv_00e9fdc0::Vec3 *, bool, ::fnv_00e9fdc0::Vec3 *, ::fnv_00e9fdc0::Vec3 *); }
