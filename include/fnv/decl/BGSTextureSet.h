#pragma once

class QueuedFile;

class BGSTextureSet {
public:
    // 0x005922e0
    BGSTextureSet();
    // 0x005924d0
    void ClearData();
    // 0x005930e0
    void LoadTextures(int, ::QueuedFile *, bool);
};
