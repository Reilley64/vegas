#pragma once

class hkVector4;
struct ContactConstraint;
struct ContactParams;
struct Jac;
struct Node56;
struct OutRef;
struct Output56;

// 0x00df56a0
int FUN_00df56a0(::Node56 *, ::Output56 **, int, int *, int *);
// 0x00df5e80
void FUN_00df5e80(const ::Jac *, const ::hkVector4 *, const ::hkVector4 *, ::OutRef);
// 0x00df5f80
float FUN_00df5f80(::ContactConstraint *, ::ContactParams *, void *, void *);
