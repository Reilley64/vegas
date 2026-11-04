#pragma once

struct SaveFile;

struct ReconstructSession {
public:
    // 0x00847df0
    bool LoadSaveGame(::SaveFile *, bool);
};
