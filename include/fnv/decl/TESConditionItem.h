#pragma once

class TESObjectREFR;

class TESConditionItem {
public:
    // 0x00681490
    float GetConditionValue();
    // 0x006814e0
    bool GetValueIsGlobal() const;
    // 0x00681600
    bool ContainsTrait(::TESObjectREFR *, ::TESObjectREFR *, bool &);
};
