#pragma once

class FormChangeMask;
class TESForm;
class TESObjectCELL;

class BGSSaveLoadGame {
public:
    // 0x00444d20
    bool GetInitingForms() const;
    // 0x00849b10
    void FormReconstructionMap(::TESObjectCELL *);
    // 0x0084a5b0
    void ClearFormChanges();
    // 0x0084a690
    void NotifyFormIDChanged(::TESForm *, ::FormChangeMask, bool);
    // 0x0084a6d0
    bool HasFormChangeFlags(::TESForm *, ::FormChangeMask);
    // 0x0084a740
    bool IsFormChanged(::TESForm *);
    // 0x0084a7c0
    void HasFormChanges(::TESForm *);
};
