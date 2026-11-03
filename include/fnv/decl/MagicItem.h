#pragma once

class TESForm;

class MagicItem {
public:
    // 0x0040a250
    static ::MagicItem *GetMagicItemByID(unsigned int);
    // 0x0040a420
    void Preload(bool);
    // 0x0040b470
    bool IsLoaded();
    // 0x0040b6b0
    bool IsLoading();
    // 0x0040c030
    void LoadEffectsFromForm(::TESForm *);
};
