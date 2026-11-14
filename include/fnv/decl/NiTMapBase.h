#pragma once

class AnimSequenceBase;

struct NiTMapBase {
public:
    // 0x0049c390
    bool Lookup(unsigned short, ::AnimSequenceBase *&);
};
