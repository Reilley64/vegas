#pragma once

class TESFile;
class TESForm;

class BGSIdleCollection {
public:
    // 0x004797e0
    void InitializeComponent();
    // 0x00479b00
    void InitItem(::TESForm *);
    // 0x00479c40
    void Load(::TESFile *);
    // 0x00479e80
    int GetPickType();
};
