#pragma once

#include <cstdint>

class TESFile;
struct Arg_004727f0;

// 0x004720a0
int FUN_004720a0(char *);
// 0x00472380
int FUN_00472380(std::intptr_t);
// 0x004727f0
bool ReadChunkInt(::TESFile *, ::Arg_004727f0);
