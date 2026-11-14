#pragma once

struct BGSLoadFormBuffer;
class TESForm;

class TESReactionForm {
public:
    // 0x0048bb10
    void ClearReactionList();
    // 0x0048bc30
    void InitItem(::TESForm *);
    // 0x0048cb40
    void InitLoadGame(::BGSLoadFormBuffer *);
};
