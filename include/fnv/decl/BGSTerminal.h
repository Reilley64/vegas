#pragma once

class TESFile;

class BGSTerminal {
public:
    // 0x004ffc50
    void ResetFormData();
    // 0x00500000
    bool Load(::TESFile *);
};
