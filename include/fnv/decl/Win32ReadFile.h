#pragma once

struct Win32ReadFile {
public:
    // 0x00afecd0
    int Read(void *, unsigned int, int, unsigned long long *);
};
