#pragma once
class NiStream;

class NiExtraData;
struct FUN_00a7b6c0_T;
struct FUN_00a7b700_T;
struct FUN_00a7b870_T;

// 0x00a7b380
::NiExtraData *FUN_00a7b380();
// 0x00a7b6c0
void FUN_00a7b6c0(::FUN_00a7b6c0_T *, int, unsigned short, unsigned short *);
// 0x00a7b700
void FUN_00a7b700(::FUN_00a7b700_T *, int, unsigned short, unsigned int);
// 0x00a7b790
void *FUN_00a7b790();
// 0x00a7b7d0
struct FUN_00a7b7d0_shell { void FUN_00a7b7d0(::NiStream& kStream); };
// 0x00a7b870
::FUN_00a7b870_T *FUN_00a7b870(::FUN_00a7b870_T *, int);
// 0x00a7be30
unsigned int GetMipLevelCount(unsigned int, unsigned int);
