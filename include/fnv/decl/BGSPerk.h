#pragma once

class Actor;

class BGSPerk {
public:
    // 0x005eb980
    void ApplyPerkEntries(::Actor *, unsigned char, bool);
    // 0x007dd8a0
    bool IsPerkHidden() const;
};
