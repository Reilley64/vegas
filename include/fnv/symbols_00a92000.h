#pragma once
#include <cstdint>

class NiFixedString;

// 0x00a923f0
void *FUN_00a923f0();
// 0x00a92660
int FUN_00a92660(const float *, intptr_t, const float *);
// 0x00a92960
bool FindTexTypeIndex(const ::NiFixedString &, unsigned int &);
// 0x00a929b0
void *FUN_00a929b0();
// 0x00a92a60
char *FUN_00a92a60(const char *, unsigned int);
// 0x00a92b00
namespace fnv_00a92b00 { char *BuildProjectionModeString(const char *, int); }
