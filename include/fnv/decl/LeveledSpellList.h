#pragma once

#include <cstdint>

struct LeveledSpellList {
public:
    // 0x0050bd60
    void SelectLeveledSpell(void *, unsigned short, std::uintptr_t *, unsigned short *, unsigned char);
};
