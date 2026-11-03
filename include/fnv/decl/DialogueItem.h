#pragma once

class DialogueResponse;
class TESObjectREFR;

class DialogueItem {
public:
    // 0x0083c7b0
    bool SelectDefaultResponseList();
    // 0x0083c820
    ::DialogueResponse *GetActiveResponse();
};

// 0x005e3fa0 returns the pointer at +0x6c. Several classes share it (DialogueItem's own copy is in
// dialogueitem.cpp); it cannot be declared next to the bool SelectDefaultResponseList above.
struct FUN_005e3fa0_getter {
    ::TESObjectREFR *FUN_005e3fa0();
};
