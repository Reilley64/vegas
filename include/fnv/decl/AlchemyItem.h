#pragma once

class TESSound;

class AlchemyItem {
public:
    // 0x00402ea0
    void ResetFormData();
    // 0x00402ef0
    void ClearData();
    // 0x004030b0
    void *FUN_004030b0();
    // 0x004030d0
    void SetSound(::TESSound *);
};
