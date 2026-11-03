#pragma once

class ActorValueOwner;
class InventoryStackRecord;
class TESAmmo;
class TESObjectREFR;
class TESObjectWEAP;
struct DamageExtra;

// 0x006450c0
bool FUN_006450c0(::TESObjectWEAP *);
// 0x006450f0
float GetWeaponDamage(::TESObjectWEAP *, float, ::DamageExtra *, ::TESAmmo *);
// 0x00645d00
float FUN_00645d00(::ActorValueOwner *, ::TESObjectWEAP *, ::InventoryStackRecord *);
// 0x00645dc0
namespace fnv_00645dc0 { float FUN_00645dc0(::TESObjectREFR *, ::TESObjectWEAP *, bool, ::InventoryStackRecord *); }
