#pragma once
#include <cstdint>

class BA50F00Interpolator;
namespace fnv_00a50180 { struct FUN_00a4fff0; }
struct FInterpX;
struct FUN_00a501b0_obj;

// 0x00a50180
namespace fnv_00a50180 { ::fnv_00a50180::FUN_00a4fff0 *FUN_00a50180(); }
// 0x00a501b0
bool FUN_00a501b0(::FUN_00a501b0_obj *, intptr_t, ::FUN_00a501b0_obj *);
// 0x00a50840
void *FUN_00a50840();
// 0x00a50ad0
void *FUN_00a50ad0();
// 0x00a50b10
unsigned char FUN_00a50b10(int);
// 0x00a50b30
bool IsInterpEqual(::FInterpX *, intptr_t, ::FInterpX *);
// 0x00a50f00
::BA50F00Interpolator *CreateEvaluator();
