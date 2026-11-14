#pragma once

struct Arg1;
struct S2db70_Out;
struct S2db70_Shape;
class S2db70_Vector4;
struct Arg2;
struct OutItem;
struct S_00dfaac0_Transform;
class hkTransform;

// 0x00dfaac0
int TestPenetration(const ::S2db70_Shape *, const ::S2db70_Shape *, const ::S_00dfaac0_Transform &, float, ::S2db70_Vector4 *, ::S2db70_Vector4 *, ::S2db70_Vector4 *, int, ::S2db70_Out *);
// 0x00dfaba0
int FUN_00dfaba0(const ::hkTransform *, ::Arg1 *, ::Arg2 **, int, const ::hkTransform *, ::OutItem **);
