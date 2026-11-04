#pragma once

struct Constraint;
struct Ragdoll;
struct RigidBody;
struct Skeleton;
template <class> struct Array;

// 0x00cea030
extern "C" int FUN_00cea030(void *, void *);
// 0x00cea810
::Ragdoll *FUN_00cea810(::Skeleton *, const ::Array< ::RigidBody *> &, const ::Array< ::Constraint *> &);
