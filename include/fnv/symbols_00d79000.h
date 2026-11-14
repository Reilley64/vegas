#pragma once

class S00d79ab0_Hull;
class S00d79ab0_Vector4;
struct D79580_Array;
struct FUN_00d79510_A;
struct FUN_00d79510_B;
struct FUN_00d79510_Object;
struct S00d79250_Obj;
struct S00d79250_Objs;
struct S00d79250_Shape;
struct S00d79250_World;
struct S_00d79f90_World;
template <class> class S00d79ab0_Array;

// 0x00d79060
void CallWithPair(int, int, int);
// 0x00d79250
void FUN_00d79250(::S00d79250_World *, ::S00d79250_Shape *, ::S00d79250_Obj **, ::S00d79250_Objs *, float);
// 0x00d79510
bool FUN_00d79510(::FUN_00d79510_A *, ::FUN_00d79510_B *, ::FUN_00d79510_Object *, float);
// 0x00d79580
bool FUN_00d79580(::S_00d79f90_World *, ::D79580_Array *, ::D79580_Array *, float);
// 0x00d79ab0
void FUN_00d79ab0(const ::S00d79ab0_Hull *, const ::S00d79ab0_Array< ::S00d79ab0_Vector4> &, ::S00d79ab0_Array< ::S00d79ab0_Hull *> &, float);
// 0x00d79f90
void FUN_00d79f90(::S_00d79f90_World *, int, void *, int, float);
