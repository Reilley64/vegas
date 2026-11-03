#pragma once

namespace fnv_00e51070 { struct Count; }
struct QParam_00e51660;
struct S00e51a60_BlockDesc;

// 0x00e51070
namespace fnv_00e51070 { void FUN_00e51070(const float *, float *, ::fnv_00e51070::Count); }
// 0x00e51140
extern "C" void FUN_00e51140(float *, unsigned int);
// 0x00e51660
void DecodeQuantizedBlock(const unsigned char *__restrict, const ::QParam_00e51660 *, float *, int);
// 0x00e51a60
unsigned int DecodeBlock(const unsigned char *, ::S00e51a60_BlockDesc &, unsigned char *, unsigned int);
// 0x00e51da0
int FUN_00e51da0(int, const char *);
