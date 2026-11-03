#pragma once

class ActorValueOwner;
class InventoryStackRecord;
class TESAmmo;
class TESObjectWEAP;
namespace ActorValue { enum Index; }

class CombatDamageCalculator {
public:
    // 0x00645380
    static float CalculateWeaponDamage(::ActorValueOwner *, ::TESObjectWEAP *, float, bool, ::InventoryStackRecord *, bool, bool, int, float, float, bool, bool, ::TESAmmo *);
    // 0x00646360
    static float CalculateArmorDamageThreshold(unsigned short, float);
    // 0x006465f0
    static float GetDamageMultiplier(float, float);
    // 0x00646800
    static float GetActorValueMultiplier(::ActorValueOwner *, ::ActorValue::Index, bool);
};
