#pragma once

class ActiveEffect;
class TESObjectREFR;

class MagicHitEffect {
public:
    // 0x0081b700
    MagicHitEffect(::TESObjectREFR *, ::ActiveEffect *);
    // 0x0081bc50
    void ResetTargetPointer();
};
