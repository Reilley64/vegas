#pragma once
#include <cstdint>

struct ArrayData;
struct D5C110VertexArray;
struct InputBuffer;
struct S_00d5ac50_M;
struct S_00d5ac50_R;
struct S_00d5ac50_V;
struct hkBool;

// 0x00d5a510
void LoadIntoArray(const ::InputBuffer *, uintptr_t, ::ArrayData *);
// 0x00d5a5e0
void InitAndSetB(void *, intptr_t);
// 0x00d5a630
void FUN_00d5a630(void *, intptr_t, intptr_t);
// 0x00d5a6a0
void FUN_00d5a6a0(const void *, ::D5C110VertexArray &);
// 0x00d5a6e0
::hkBool FUN_00d5a6e0(float (*)[4], int);
// 0x00d5ac50
::S_00d5ac50_R FUN_00d5ac50(::S_00d5ac50_M &, ::S_00d5ac50_V *, ::S_00d5ac50_V *, ::S_00d5ac50_V *);
