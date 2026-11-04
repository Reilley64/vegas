#pragma once

class NiFormArray;
class TESObjectREFR;

class TESIdleForm {
public:
    // 0x005fe3b0
    void ResetFormData();
    // 0x005fe400
    void ClearData();
    // 0x005fe770
    ::NiFormArray *AssignParentPath();
    // 0x005ff430
    bool IsValidForReferences(::TESObjectREFR *, ::TESObjectREFR *, bool);
};
