#ifndef FNV_TESOBJECTWEAP_HEADER_UNIT_H
#define FNV_TESOBJECTWEAP_HEADER_UNIT_H

#include "fnv/decl/FUN_004bcf60_shell.h"
#include "fnv/decl/TimeoutTimer.h"
#include "tesobjectweap_types.h"

// @fnv 0x00521690
void TESObjectWEAP::SetMeleeBlockSound(TESSound* sound)
{
    m_pWeaponSound6 = sound;
}

// @fnv 0x004be380
float TESObjectWEAP::GetWeightForForm(bool modded)
{
    if (modded)
    {
        return reinterpret_cast<::TimeoutTimer *>((void *)this)->FUN_006b9130() -
               reinterpret_cast<::FUN_004bcf60_shell *>((void *)this)->GetEffectValue((*(int *)&(const ::WEAPON_MOD_EFFECT &)(WEAPON_MOD_EFFECT_WEAPON_MOD_DECREASE_WEIGHT)), 0);
    }
    else
    {
        return reinterpret_cast<::TimeoutTimer *>((void *)this)->FUN_006b9130();
    }
}
#endif
