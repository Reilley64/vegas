#pragma once

class Actor;
class ActorValueOwner646;
class ActorValueOwner;
class TESObjectREFR;
class TESObjectWEAP646;
class TESObjectWEAP;
struct AVOwnerStub_646400;
struct ChanceModifier;
struct CombatActorForm;
struct CombatDebugLog;
struct DamageAmmo;
struct DamageWeapon;
struct FUN_00647730_shell;

// 0x00646060
float ComputeWeaponDamage(::CombatActorForm *, ::DamageWeapon *, float, ::DamageAmmo *, void *, void *);
// 0x00646250
float FUN_00646250(int, int);
// 0x00646260
float FUN_00646260(::Actor *);
// 0x006462e0
float FUN_006462e0(float, float);
// 0x00646310
void FUN_00646310(void *, bool, float *, float *);
// 0x006463a0
float FUN_006463a0(int);
// 0x006463e0
float FUN_006463e0(float);
// 0x00646400
bool FUN_00646400(::AVOwnerStub_646400 *, int);
// 0x00646580
float FUN_00646580(::ActorValueOwner *, int);
// 0x00646660
float FUN_00646660(float, float);
// 0x006466e0
float RemapValueBySettings(float, bool);
// 0x00646910
float ComputeWeaponDamageModifier(::Actor *, ::TESObjectWEAP *, void *, bool, bool, bool, bool);
// 0x00646d80
float GetWeaponDPS(::ActorValueOwner646 *, ::TESObjectWEAP646 *);
// 0x00646e50
void RollChanceOutcome(void *, ::ChanceModifier *, int, int, int, bool, unsigned char *, unsigned char *);
// 0x00646f70
float GetHitChance(::ActorValueOwner *, ::TESObjectREFR *, ::TESObjectWEAP *, void *, void *, float, const char *, ::FUN_00647730_shell *, float, float, float, ::CombatDebugLog *);
