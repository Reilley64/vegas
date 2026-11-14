#pragma once

class TESFile;

class DecalData {
public:
    // 0x00593240
    DecalData();
    // 0x005932b0
    void Copy(::DecalData *);
    // 0x00593450
    void Load(::TESFile *);
};
