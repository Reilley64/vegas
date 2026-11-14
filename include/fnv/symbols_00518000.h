#pragma once

class Actor;
class LockExtraData;
class TESObjectREFR;

// 0x00518cf0
namespace fnv_00518cf0 { void PlaySoundForRef(unsigned int); }
// 0x00518e60
bool CanActivateDoor(::LockExtraData *, ::Actor *, ::TESObjectREFR *, bool, bool);
// 0x00518f80
void FUN_00518f80(unsigned int);
