#pragma once

class CountingSemaphore;
class GlobalObject_00869f00;
class LKTile;
struct BGSSaveFormBuffer;
struct LockRef;

// 0x0078d080
void FUN_0078d080();
// 0x0078d280
void FUN_0078d280(bool);
// 0x0078d3b0
::CountingSemaphore *InitSemaphore(::CountingSemaphore *);
// 0x0078d6b0
void SaveLoadScreenData(::BGSSaveFormBuffer *);
// 0x0078d880
namespace fnv_0078d880 { void *FUN_0078d880(void *); }
// 0x0078d8b0
void FUN_0078d8b0(::GlobalObject_00869f00 *);
// 0x0078db00
::LKTile *CreateLockpickMenu(::LockRef *, int, bool);
