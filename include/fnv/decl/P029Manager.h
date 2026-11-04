#pragma once

struct P029Actor;
struct P029Input;

struct P029Manager {
public:
    // 0x009839b0
    bool TryStartDialogue(::P029Actor *, void *, int, int, bool, ::P029Input *);
};
