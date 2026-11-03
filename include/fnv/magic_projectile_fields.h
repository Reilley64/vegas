#pragma once

class MagicCaster;
class MagicItem;

// The MagicProjectile data members the magic projectile code reads through folded 4-byte getters: the caster
// (0x009185e0, PlayerMover::GetActorStateFlags) and the spell (0x00810fd0, EffectSetting::GetArchetype).
struct MagicProjectileFields
{
    char pad00[0x94];
    MagicCaster *caster;
    MagicItem *spell;
};
