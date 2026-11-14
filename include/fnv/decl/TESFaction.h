#pragma once

struct BGSLoadFormBuffer;

class TESFaction {
public:
    // 0x005a2270
    bool GetPCAnEnemy() const;
    // 0x005fc800
    void ResetFormData();
    // 0x005fc840
    void ClearData();
    // 0x005fc860
    void ClearReactions();
    // 0x005fcf80
    void InitItem();
    // 0x005fd730
    void LoadGame(::BGSLoadFormBuffer *);
    // 0x005fd800
    void Revert(::BGSLoadFormBuffer *);
};
