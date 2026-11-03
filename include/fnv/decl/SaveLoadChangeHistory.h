#pragma once

class SaveLoadFile;

class SaveLoadChangeHistory {
public:
    // 0x00848e10
    void Init();
    // 0x0084dff0
    void AddNote(const char *, ...);
    // 0x0084e190
    void Load(::SaveLoadFile *);
};
