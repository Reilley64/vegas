#pragma once

class ActiveEffect;
class Actor;
class MagicCaster;
class MagicItem;

class MagicTarget {
public:
    // 0x00822b40
    ::Actor *GetOwnerActor() const;
    // 0x00822b90
    bool HasSpell(::MagicItem *, bool);
    // 0x00823c40
    void UpdateActiveEffects(float);
    // 0x00824400
    void Dispel(::MagicItem *, ::MagicCaster *, ::ActiveEffect *);
    // 0x00824970
    void DispelAllEffects();
    // 0x00825550
    static ::MagicTarget *GetMagicTargetByID(unsigned int);
};
