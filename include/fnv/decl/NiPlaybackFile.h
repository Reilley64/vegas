#pragma once

class NiPlaybackFile {
public:
    // 0x00ec0ac0
    bool FindString(const char *, bool, bool, bool);
    // 0x00ec0cd0
    bool InitPlayback(const char *, bool, bool, bool);
};
