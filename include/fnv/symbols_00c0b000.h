#pragma once

class Cb50Ctx;
class Cb50Owner;
struct FNV_A1;
struct FNV_Node;
struct FUN_00c0bbd0_Arg;
struct S_00c0bba0_A;
struct S_00c0bba0_B;

// 0x00c0bb50
void CopyOwnerValuesToItems(::Cb50Ctx *, ::Cb50Owner *, unsigned char);
// 0x00c0bba0
void SetDstValueFromB(::S_00c0bba0_A *, ::S_00c0bba0_B *);
// 0x00c0bbd0
void FUN_00c0bbd0(::FUN_00c0bbd0_Arg *);
// 0x00c0bc00
void SetNodeResultValue(::FNV_A1 *, ::FNV_Node *, intptr_t);
