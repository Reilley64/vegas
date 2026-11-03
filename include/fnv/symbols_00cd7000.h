#pragma once

class FUN_00cd7e80;
struct Mid;
struct P;
struct S_00cd7850_Cache;
struct S_00cd7850_Features;
struct S_00cd7850_Result;
struct S_00cd7850_Vec;
struct SrcD;

// 0x00cd7530
void FUN_00cd7530(::P, ::P, ::Mid, long long);
// 0x00cd7850
int FUN_00cd7850(const ::S_00cd7850_Vec &, const ::S_00cd7850_Vec *, const ::S_00cd7850_Cache &, ::S_00cd7850_Result &, ::S_00cd7850_Features *);
// 0x00cd7f50
::FUN_00cd7e80 *CreateFromSource(::SrcD *);
