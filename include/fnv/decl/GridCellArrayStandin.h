#pragma once

class TESObjectCELL;

struct GridCellArrayStandin {
public:
    // 0x004ba550
    void SetCellAt(unsigned int, unsigned int, ::TESObjectCELL *);
};
