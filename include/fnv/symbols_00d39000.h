#pragma once

class hkpCollisionDispatcherD398;
struct Context;
struct D390Callback;
struct D390HandleTable;
struct FUN_00d390a0_Flags;
struct FUN_00d390a0_Out;
struct FUN_00d390a0_Owner;
struct FUN_00d39980_cls;
struct FourFloatVector;
struct Header;
struct Pair;

// 0x00d39030
void RemoveKeyFromTable(int, unsigned short *, unsigned short);
// 0x00d39060
void InsertIntoSlotArray(void *, unsigned short *, unsigned short);
// 0x00d390a0
char *InitOutputDefaults(::FUN_00d390a0_Owner *, ::FUN_00d390a0_Flags *, ::FUN_00d390a0_Out *);
// 0x00d390e0
unsigned short *ReleaseHandles(void *, ::D390HandleTable *, ::D390Callback *, void *);
// 0x00d39130
void FUN_00d39130(int, int, int, int, int);
// 0x00d39390
unsigned short *FUN_00d39390(::Pair *, ::Header *, unsigned short *, ::FourFloatVector *, ::Context *);
// 0x00d39840
void FUN_00d39840(::hkpCollisionDispatcherD398 *);
// 0x00d398c0
namespace fnv_00d398c0 { extern "C" void *CreateObjectFromFactory(int, int *, int, int); }
// 0x00d39980
::FUN_00d39980_cls *CreateAllocatedObject(int, int, int, int);
