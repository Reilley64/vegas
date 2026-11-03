#pragma once

class SaveLoadFile {
public:
    // 0x008461e0
    SaveLoadFile(const char *, bool, unsigned int);
    // 0x00846300
    unsigned int Read(void *, unsigned int);
    // 0x00846400
    unsigned int GetFilePosition();
    // 0x00846440
    void SetFilePosition(int);
};
