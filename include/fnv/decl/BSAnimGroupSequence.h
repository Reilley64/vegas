#pragma once

class TESAnimGroup;

class BSAnimGroupSequence {
public:
    // 0x0048f7f0
    ::TESAnimGroup *GetAnimGroup() const;
    // 0x004ef9a0
    unsigned char GetPriority(const char *, unsigned int *);
};
