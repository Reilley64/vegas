#pragma once

class TESEffectShader;
class TESSound;

class EffectSetting {
public:
    // 0x00405e60
    void FUN_00405e60();
    // 0x00408880
    bool HasEffectID();
    // 0x004088a0
    bool UsesAssociatedActorValue();
    // 0x004088c0
    int FUN_004088c0();
    // 0x00408970
    int QueueAssociatedItem();
    // 0x004089c0
    int NormalizeEffectLoadedCount();
    // 0x00408a20
    bool HasNoAssociatedActorValue();
    // 0x004fb070
    ::TESSound *GetCastSound();
    // 0x004fb090
    void SetBoltSound(::TESSound *);
    // 0x004fd3e0
    ::TESSound *GetHitSound();
    // 0x004febd0
    void SetEnchantEffectShader(::TESEffectShader *);
    // 0x007df1b0
    bool IsScriptEffect();
    // 0x00810fd0
    int GetArchetype();
};
