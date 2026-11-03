#pragma once

class ActorValueOwner;
class C644810Actor;
class InventoryStackRecord;
struct DmgWeapon;
struct OCActor;
struct Obj641;
struct Obj;

// 0x00644300
int CompareObjects(int, int);
// 0x00644520
namespace fnv_00644520 { float FUN_00644520(); }
// 0x00644540
namespace fnv_00644540 { float ScaleByGameSetting(float, float, bool); }
// 0x00644580
float FUN_00644580(::Obj *, int, int, bool, bool);
// 0x00644680
float CalculateWeightedValue(::Obj641 *, int, int, bool, bool, bool, bool, bool);
// 0x006447d0
float FUN_006447d0(const char *);
// 0x00644810
bool CheckChanceSuccess(::C644810Actor *, float, bool, bool, bool);
// 0x00644970
float FUN_00644970(void *);
// 0x00644990
namespace fnv_00644990 { float FUN_00644990(void *, int, float, bool); }
// 0x00644a70
unsigned short FUN_00644a70(::OCActor *, bool, bool, float, float, bool, bool, unsigned short);
// 0x00644ce0
float FUN_00644ce0(::ActorValueOwner *, ::DmgWeapon *, float, float, int, bool, ::InventoryStackRecord *, bool);
