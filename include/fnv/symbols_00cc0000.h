#pragma once

class hkOstream;
namespace fnv_00cc0b50 { struct InputBool223; }
namespace fnv_00cc0b50 { struct SpawnedObject; }
struct CC0D30Result;
struct Island;
struct ItemOwner;
struct S_00cc0d60_R;
struct S_00cc0ed0_Blocks;
struct S_00cc0f40_Coll;
struct S_00cc0f40_In;
struct hkClassS;
struct hkResultS;

// 0x00cc0410
void FUN_00cc0410(::hkOstream *, const char *, ...);
// 0x00cc0b50
namespace fnv_00cc0b50 { unsigned char *FUN_00cc0b50(unsigned char *, unsigned int, unsigned int, unsigned int, ::fnv_00cc0b50::InputBool223, unsigned int, ::fnv_00cc0b50::SpawnedObject *); }
// 0x00cc0bc0
::hkResultS FUN_00cc0bc0(const void *, const ::hkClassS &, int, int, int);
// 0x00cc0d30
::CC0D30Result FUN_00cc0d30(const void *, const void *, void *, int);
// 0x00cc0d60
::S_00cc0d60_R FUN_00cc0d60(void *, void *, int, int, int);
// 0x00cc0e20
::Island *PickIslandByValue(unsigned int, ::Island *, ::Island *);
// 0x00cc0ea0
void FUN_00cc0ea0(::ItemOwner *, void *);
// 0x00cc0ed0
void ProcessBlocks(::S_00cc0ed0_Blocks *, float, float, int);
// 0x00cc0f40
void FUN_00cc0f40(::S_00cc0f40_Coll *, ::S_00cc0f40_Coll *, ::S_00cc0f40_In *);
