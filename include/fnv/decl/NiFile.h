#pragma once

class NiFile {
public:
    // 0x00aa15a0
    bool Flush();
    // 0x00aa1690
    ~NiFile();
    // 0x00aa1750
    unsigned int FileRead(void *, unsigned int);
    // 0x00aa85c0
    static unsigned int RequestFileAccess(const char *, unsigned int, unsigned int);
};
