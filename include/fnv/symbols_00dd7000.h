#pragma once

class S_00dd7d00_Bool;
struct S_00dd7d00_Item;
struct hkFreeListNode;

// 0x00dd70f0
unsigned char *CompareLessThan(unsigned char *, unsigned int, unsigned int);
// 0x00dd7280
int SumFreeListSizes(::hkFreeListNode *);
// 0x00dd73d0
void *FUN_00dd73d0(void *, unsigned int);
// 0x00dd7d00
void FUN_00dd7d00(::S_00dd7d00_Item **, int, int, S_00dd7d00_Bool (*)(S_00dd7d00_Item *, S_00dd7d00_Item *));
// 0x00dd7e00
namespace fnv_00dd7e00 { unsigned int FUN_00dd7e00(unsigned int); }
// 0x00dd7e70
int FUN_00dd7e70(int);
