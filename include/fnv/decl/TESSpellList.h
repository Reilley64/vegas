#pragma once

struct BGSLoadFormBuffer;
class TESForm;

class TESSpellList {
public:
    // 0x0048cfe0
    TESSpellList();
    // 0x0048d0d0
    void ClearComponent();
    // 0x0048d400
    void InitItem(::TESForm *);
    // 0x0048e140
    void LoadGame(::BGSLoadFormBuffer *);
};
