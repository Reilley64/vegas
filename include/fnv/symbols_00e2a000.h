#pragma once

struct CastOutput;
struct E29Out1;
struct E29Out2;
struct FNV_Vec4;
struct InputStruct;
struct S_00df8990_Obj;
struct SplitChunk;

// 0x00e2a010
void FUN_00e2a010(int, ::FNV_Vec4 *, ::FNV_Vec4 *, int, float, float, char *, ::E29Out1 *, int *, ::E29Out2 *, int *);
// 0x00e2aa70
void InitSplitChunks(int, int, int, int, int, ::SplitChunk *);
// 0x00e2abf0
void FUN_00e2abf0(void *, ::S_00df8990_Obj *, int, ::CastOutput *);
// 0x00e2acf0
void FUN_00e2acf0(void *, ::InputStruct *, void *, float *);
