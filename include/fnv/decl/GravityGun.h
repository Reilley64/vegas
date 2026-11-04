#pragma once

struct GGRigidBody;
struct GGTransform;
struct GGWorld;

struct GravityGun {
public:
    // 0x00e45a60
    ::GGRigidBody *FUN_00e45a60(const ::GGTransform &, const ::GGRigidBody *, const ::GGWorld *);
};
