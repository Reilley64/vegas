#pragma once

struct FUN_00d08400_cls;
struct Target;
struct hkpWorldB90;
template <class> class hkArrayD08C;
template <class> struct hkArray;

// 0x00d081f0
int CompareByNestedValue(int **, int **);
// 0x00d083e0
void FUN_00d083e0(void *);
// 0x00d08400
void DispatchToOffsetTarget(::FUN_00d08400_cls *, unsigned short);
// 0x00d08ac0
void FUN_00d08ac0(::hkArray< ::Target *> *, int);
// 0x00d08b90
void FUN_00d08b90(::hkArrayD08C<int *> &, ::hkpWorldB90 *);
