#pragma once

class TESForm;
class TESObjectREFR;

class BGSOpenCloseForm {
public:
    // 0x0047a490
    static bool HasOpenCloseComponent(::TESForm *);
    // 0x0047aec0
    static bool SetOpenState(::TESObjectREFR *, bool, bool);
};
