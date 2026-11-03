#ifndef FNV_ACTIVE_EFFECT_FIELDS_H
#define FNV_ACTIVE_EFFECT_FIELDS_H

class MagicItem;
class EffectItem;
class MagicTarget;
class MagicCaster;

// The leading data members of ActiveEffect, for effect units whose ActiveEffect
// stand-ins declare no fields. The 32-bit getters folded into 0x0059bb30
// (ActorMover::GetCurrentMoveModeType) read `caster` when called on an effect.
struct ActiveEffectFields
{
    void* vtable;
    float timeElapsed;
    MagicItem* magicItem;
    EffectItem* effectItem;
    bool applied;
    bool terminated;
    unsigned char flags12;
    unsigned char byte13;
    unsigned int field14;
    float magnitude;
    float duration;
    MagicTarget* target;
    MagicCaster* caster;
};

#endif
