#pragma once

class TESFile;
class TESForm;
class TESObjectREFR;

class PerkEntryConditionSet {
public:
    // 0x005e9f60
    PerkEntryConditionSet();
    // 0x00680960
    void Load(::TESFile *);
    // 0x00680a20
    void InitItem(::TESForm *);
    // 0x00680b70
    bool Compare(::PerkEntryConditionSet *);
    // 0x00680c30
    bool ContainsTrait(::TESObjectREFR *, ::TESObjectREFR *);
    // 0x00680c60
    bool ContainsTrait(::TESObjectREFR *, ::TESObjectREFR *, bool &, bool);
    // 0x00680fe0
    void InitializeConditionItems();
};
