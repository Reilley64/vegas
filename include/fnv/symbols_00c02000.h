#pragma once

#include <cstdint>

struct FNV_Node;
struct FUN_00c02c30_Obj;

// 0x00c02340
namespace ShaderBias { void FUN_00c02340(); }
// 0x00c02c30
void FUN_00c02c30(void *, int, ::FUN_00c02c30_Obj *, int);
// 0x00c02f30
int FUN_00c02f30(::FNV_Node *, int);
// 0x00c02f70
void UpdateFlagHolders(unsigned int);
