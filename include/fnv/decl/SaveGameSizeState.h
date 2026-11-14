#pragma once

struct SaveGameSizeState {
public:
    // 0x006e9670
    void InitSizeState(unsigned int, unsigned int);
    // 0x008453a0
    void RecordRequestedSize(unsigned int, unsigned int);
};
