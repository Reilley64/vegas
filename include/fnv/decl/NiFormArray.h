#pragma once

class TESForm;

class NiFormArray {
public:
    // 0x004d6100
    unsigned int GetIndexOfForm(::TESForm *);
    // 0x0061bc10
    void SetFormAtIndex(unsigned int, ::TESForm *);
    // 0x0061bd20
    void SetSize(unsigned int, unsigned int *);
};
