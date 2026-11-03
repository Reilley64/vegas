#pragma once
#include <cstdint>

struct NiProperty;
struct S_00a8f2c0_Arg;
struct S_00a8f2c0_Obj;

// 0x00a8f260
void *CreateObjA8F260(int, int);
// 0x00a8f2c0
::S_00a8f2c0_Obj *CreateFadeNodeFromArg(int, int, ::S_00a8f2c0_Arg *);
// 0x00a8f3e0
int FUN_00a8f3e0(intptr_t, intptr_t, intptr_t, intptr_t, intptr_t, intptr_t, intptr_t);
// 0x00a8f3f0
int FUN_00a8f3f0(int, int, int, int, int, int, int, int);
// 0x00a8f440
void *FUN_00a8f440(void *);
// 0x00a8f580
::NiProperty *CreateProperty();
// 0x00a8f870
void RunRegistryHandlers();
// 0x00a8fe20
uintptr_t FUN_00a8fe20(unsigned int *);
// 0x00a8ff80
void *FUN_00a8ff80();
// 0x00a8ffc0
namespace fnv_00a8ffc0 { void *FUN_00a8ffc0(); }
