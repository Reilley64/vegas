#ifndef FNV_ACTIVE_EFFECT_FIELDS_H
#define FNV_ACTIVE_EFFECT_FIELDS_H

class MagicItem;
class EffectItem;
class MagicTarget;
class MagicCaster;

// The leading data members of ActiveEffect (as in magic/activeeffect_local.h),
// for effect units whose ActiveEffect stand-ins declare no fields. The 32-bit
// getter folded into 0x0059bb30 (ActorMover::GetCurrentMoveModeType) reads
// `target` when called on an effect, and the one folded into 0x0055b980
// (BGSMessageInitAccess::GetIconFormID) reads `spellType`.
struct ActiveEffectFields
{
    void* vtable;
    float magnitude;
    MagicItem* spell;
    EffectItem* effect;
    bool active;
    bool effectFlag;
    bool wasPlaying;
    bool pickResultFound;
    bool effectState;
    int flags;
    float elapsedTime;
    float duration;
    MagicTarget* target;
    MagicCaster* caster;
    int spellType;
    unsigned int soundHandle[3];
    void* source;
    void* hitEffectList;
    MagicItem* magicItem;
};

// The ValueModifierEffect member after ActiveEffect.
struct ValueModifierEffectFields : ActiveEffectFields
{
    int actorValue;
};

#endif
