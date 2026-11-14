#pragma once

class BGSImpactDataSet;
class ExplosionEffectSettings;

class BGSExplosion {
public:
    // 0x004fadc0
    ::ExplosionEffectSettings *FUN_004fadc0();
    // 0x004fb0b0
    void FUN_004fb0b0(::BGSImpactDataSet *);
    // 0x009ad5a0
    float GetScaledValue();
};
