#pragma once

class TESFile;

class TESDescription {
public:
    // 0x00482c50
    TESDescription();
    // 0x00482d50
    static void ReadDescriptionFromFile(::TESDescription *, ::TESFile *);
};
