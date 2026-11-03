#pragma once
#include <cstdint>

namespace fnv_00d86050 { struct D86050Self; }
struct DataD8616;
struct DataD861;
struct NiStreamD8616;
struct NiStreamD861;

// 0x00d86050
namespace fnv_00d86050 { void FUN_00d86050(::fnv_00d86050::D86050Self *); }
// 0x00d86100
void FUN_00d86100(::NiStreamD861 &, ::DataD861 *);
// 0x00d86160
void FUN_00d86160(::NiStreamD8616 &, ::DataD8616 *);
// 0x00d86680
int CountBitsInWords(const unsigned int *, int);
// 0x00d868a0
char *FUN_00d868a0(intptr_t);
// 0x00d86b80
int ReadSignedValueBySize(const void *);
// 0x00d86bc0
void FUN_00d86bc0(intptr_t, intptr_t);
