// fallout_shared/combatformulas_decls.h: declares TESObjectARMO, CombatDamageCalculator

#include "fnv/symbols_004be000.h"
#include "fnv/symbols_00645000.h"
#include "fnv/symbols_00647000.h"
#include "combatformulas_form.h"
#include "combatformulas_item.h"
#include "combatformulas_health.h"
class TESObjectARMO : public TESForm
{
  public:
};
class CombatDamageCalculator
{
  public:
    static float CalculateWeaponDamage(ActorValueOwner*, TESObjectWEAP*, float, bool, InventoryStackRecord*, bool, bool, int,
                                       float, float, bool, bool, TESAmmo*);
    static float GetActorValueMultiplier(ActorValueOwner*, ActorValue::Index, bool);
    static float GetDamageMultiplier(float, float);
    static float CalculateArmorDamageThreshold(unsigned short rating, float condition);
};
