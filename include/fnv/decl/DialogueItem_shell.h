#pragma once

class BGSLoadFormBuffer;
class DialogueResponse;

struct DialogueItem_shell {
public:
    // 0x0083c970
    ::DialogueResponse *GetResponseByIndex(short);
    // 0x0083cf40
    void LoadDialogueItem(::BGSLoadFormBuffer *);
};
