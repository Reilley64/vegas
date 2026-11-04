#pragma once

class BSGameSound {
public:
    // 0x00ae97a0
    void Copy(::BSGameSound *, bool);
    // 0x00ae9cf0
    bool HasSoundFlagTwo();
    // 0x00ae9d10
    bool CanStartPlayback();
    // 0x00ae9d50
    bool LoadFromFilename(bool);
    // 0x00ae9d80
    static unsigned int ComputeSoundNameHash(const char *);
    // 0x00ae9de0
    bool Prepare();
};
