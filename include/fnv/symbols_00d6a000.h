#pragma once

class D6A140Interface;
struct FUN_00c90e00_Obj;
struct MotionInput;
struct S_00d6adf0_Obj;
struct VtblForwarder;

// 0x00d6a140
::D6A140Interface *FUN_00d6a140(const void *);
// 0x00d6a810
namespace fnv_00d6a810 { void *FUN_00d6a810(int); }
// 0x00d6ad00
namespace fnv_00d6ad00 { int FUN_00d6ad00(int); }
// 0x00d6adf0
void FUN_00d6adf0(::S_00d6adf0_Obj *);
// 0x00d6ae10
void ConstructHkDerived(void *, int);
// 0x00d6ae50
namespace sd6ae50 { const char *FUN_00d6ae50(); }
// 0x00d6ae90
void FUN_00d6ae90(::FUN_00c90e00_Obj *, int);
// 0x00d6aeb0
int FUN_00d6aeb0(::VtblForwarder *);
// 0x00d6aec0
int FUN_00d6aec0();
// 0x00d6aef0
void FUN_00d6aef0(const ::MotionInput *, void *);
