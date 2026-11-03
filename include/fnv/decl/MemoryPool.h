#pragma once

class MemoryPool {
public:
    // 0x00aa6610
    bool CommitPage(unsigned int, char *&);
};
