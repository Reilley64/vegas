#pragma once

struct BGSLoadFormBuffer;

struct TESReactionFormLoad {
public:
    // 0x0048c640
    void LoadReactions(unsigned int, ::BGSLoadFormBuffer *);
};
