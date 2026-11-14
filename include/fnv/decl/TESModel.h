#pragma once

class TESFile;

class TESModel {
public:
    // 0x004892d0
    static void LoadModelData(::TESModel *, ::TESFile *);
    // 0x00589560
    void WriteToStream();
};
