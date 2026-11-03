#pragma once
#include <cstdint>

struct FUN_00e984d0_Struct;
struct GeometryRelatedType;
struct NiVBBlock;

// 0x00e983f0
bool FUN_00e983f0(const char *, char *, char *, char *, char *);
// 0x00e98430
bool FUN_00e98430(const char *, char *, unsigned int);
// 0x00e984d0
void FUN_00e984d0(::FUN_00e984d0_Struct *, intptr_t, int);
// 0x00e98500
unsigned int FreeVBBlock(::NiVBBlock *, void *, unsigned int);
// 0x00e98730
void FUN_00e98730(intptr_t, intptr_t, int);
// 0x00e98890
void *CreateVertexShaderChecked(void *, void *, uintptr_t, void *, uintptr_t, uintptr_t);
// 0x00e988d0
::GeometryRelatedType *FUN_00e988d0(void *);
