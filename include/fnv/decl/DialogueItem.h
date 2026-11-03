#pragma once

class DialogueResponse;
class TESObjectREFR;

class DialogueItem {
public:
    // 0x005e3fa0
    ::TESObjectREFR *FUN_005e3fa0();
    // 0x0083c7b0
    bool SelectDefaultResponseList();
    // 0x0083c820
    ::DialogueResponse *GetActiveResponse();
};
