#pragma once

struct PhysicsMaterial;
struct hkContactPoint;
struct hkpConstraintOwner;

struct hkpSimpleContactConstraintData {
public:
    // 0x00d92df0
    int FUN_00d92df0(::hkpConstraintOwner &, ::hkContactPoint **, ::PhysicsMaterial **);
};
