#pragma once

struct DepthLimit;
struct FUN_00db7c00_obj;
struct GraphTable;

// 0x00db7790
int Crc32ShiftRight8(unsigned int);
// 0x00db7c00
void FUN_00db7c00(::FUN_00db7c00_obj *);
// 0x00db7c20
void InitLoadedObject(void *, int);
// 0x00db7c40
namespace fnv_00db7c40 { const void *FUN_00db7c40(); }
// 0x00db7cb0
int FUN_00db7cb0(int *);
// 0x00db7e70
int FUN_00db7e70(void *, void *, ::GraphTable *, ::DepthLimit *);
