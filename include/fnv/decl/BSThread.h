#pragma once

class BSThread {
public:
    // 0x00aa6360
    BSThread();
    // 0x00aa6540
    void SetName(const char *);
    // 0x00aa6550
    void SetSchedulingPriority(unsigned int);
    // 0x00aa6560
    void SetThreadPriority(int);
};
