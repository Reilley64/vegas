#pragma once

class TESFile;
class TESForm;

class TESAnimation {
public:
    // 0x0047f9f0
    ~TESAnimation();
    // 0x0047faa0
    void LoadComponent(::TESForm *, ::TESFile *);
    // 0x0047fd90
    bool HasSpecialAnimations();
};
