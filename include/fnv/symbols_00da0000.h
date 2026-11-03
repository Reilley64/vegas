#pragma once

struct AudioStream;
struct FNVCloud_0f10;
struct FUN_00da0720_Class;
struct FUN_00da0740_vt;
struct FUN_00da08a0_cls;
struct FUN_00da0af0_Class;
struct RadixRecord;

// 0x00da0010
void RadixSort(::RadixRecord *, int, ::RadixRecord *);
// 0x00da0720
void FUN_00da0720(::FUN_00da0720_Class *);
// 0x00da0740
void FUN_00da0740(::FUN_00da0740_vt *);
// 0x00da0760
void FUN_00da0760(void *, void *);
// 0x00da0780
const void *FUN_00da0780();
// 0x00da07b0
void FUN_00da07b0(void *, void *);
// 0x00da07d0
namespace fnv_00da07d0 { const void *FUN_00da07d0(); }
// 0x00da08a0
int FUN_00da08a0(::FUN_00da08a0_cls *);
// 0x00da08c0
void FUN_00da08c0(void **);
// 0x00da08e0
void FUN_00da08e0(void *, int);
// 0x00da0920
void ConstructDA0920Object(void *, int);
// 0x00da0af0
void FUN_00da0af0(::FUN_00da0af0_Class *);
// 0x00da0b10
void FUN_00da0b10(int *);
// 0x00da0ba0
unsigned char *CheckDuplicateValues(unsigned char *, int *);
// 0x00da0f10
void FUN_00da0f10(::FNVCloud_0f10 *, ::AudioStream *, ::AudioStream *, float);
