#pragma once

class hkpConstraintInstance;
class hkpModifierConstraintAtom;
namespace fnv_00d27ac0 { struct Constraint; }
namespace fnv_00d27ac0 { struct ConstraintPointer; }
struct D27690_Instance;
struct D27690_Owner;
struct FUN_00d277f0_arg;
struct FUN_00d277f0_node;
struct S_00d27820_P;
struct hkpConstraintInstance;
struct hkpConstraintOwner;
struct hkpModifierConstraintAtom;

// 0x00d275a0
void ReplaceEntry(int, int, int, unsigned short);
// 0x00d27690
void FUN_00d27690(::D27690_Instance *, ::D27690_Owner *, unsigned int);
// 0x00d277c0
::hkpModifierConstraintAtom *FindModifierConstraintAtom(::hkpConstraintInstance *, unsigned int);
// 0x00d277f0
::FUN_00d277f0_node *FUN_00d277f0(::FUN_00d277f0_arg *);
// 0x00d27820
void DetachRecord(::S_00d27820_P *);
// 0x00d27960
void FUN_00d27960(::hkpConstraintInstance *, ::hkpConstraintOwner &, ::hkpModifierConstraintAtom *);
// 0x00d27ac0
namespace fnv_00d27ac0 { ::fnv_00d27ac0::ConstraintPointer *FUN_00d27ac0(void *, ::fnv_00d27ac0::Constraint *); }
