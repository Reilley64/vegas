#pragma once

class TESForm;
class TESObjectREFR;

class TESSaveLoadGame {
public:
    // 0x00855100
    ::TESObjectREFR *QueueRemoveReferenceChange(unsigned int);
    // 0x0085a410
    void FinalizeForm(::TESForm *);
};
