#pragma once

class BGSLoadFormBuffer;
class BGSLoadGameBuffer;
class TESForm;

class BGSLoadGameSubBuffer {
public:
    // 0x00864e20
    ::BGSLoadFormBuffer *CreateFormBuffer(::TESForm *);
    // 0x008655a0
    void LoadGame(::BGSLoadGameBuffer *);
};
