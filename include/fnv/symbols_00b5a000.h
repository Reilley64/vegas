#pragma once

#include <cstdint>

class NiRefObject;
struct FUN_00b5aa40_self;
struct FUN_00b5ac60_self;
struct FUN_00b5ade0_arr;

// 0x00b5a8c0
void FUN_00b5a8c0(std::intptr_t, int, int, int, int, int);
// 0x00b5a980
int FUN_00b5a980(int *, int *);
// 0x00b5aa40
void *FUN_00b5aa40(::FUN_00b5aa40_self *, int);
// 0x00b5aa70
int CompareFloatAtOffsetC(const void *, const void *);
// 0x00b5ac20
void *GetListItemAt(char *, int, unsigned int);
// 0x00b5ac60
int FUN_00b5ac60(::FUN_00b5ac60_self *, int);
// 0x00b5ade0
void FUN_00b5ade0(::FUN_00b5ade0_arr *, int, unsigned int, bool);
// 0x00b5aee0
void AssignRefObject(char *, int, ::NiRefObject *);
// 0x00b5af30
void FUN_00b5af30(char *, int, ::NiRefObject *);
