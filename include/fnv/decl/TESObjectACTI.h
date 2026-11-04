#pragma once

class TESSound;

class TESObjectACTI {
public:
    // 0x00442a80
    void SetActivateSound(::TESSound *);
    // 0x004febb0
    void SetLoopingSound(::TESSound *);
    // 0x005104f0
    TESObjectACTI();
};
