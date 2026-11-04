#pragma once
class MagicItem;
class EffectItem;

class TESResponse;

struct FUN_00824570_shell {
public:
    // 0x00824570
    void DispelMatchingActiveEffects(::EffectItem *, ::MagicItem *, ::TESResponse *);
};
