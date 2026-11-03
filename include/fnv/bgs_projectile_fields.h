#pragma once

class TESSound;

// The sound of a projectile form (BGSProjectile), as Projectile code reads it directly. The release build reads it
// through the folded 4-byte getter at 0x00810fd0 (EffectSetting::GetArchetype). The padding keeps the 32-bit offset
// (+0x98) until the members before it are modelled.
struct BGSProjectileFields
{
    char pad000[0x98];
    TESSound* pSound;
};
