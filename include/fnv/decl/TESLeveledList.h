#pragma once

struct BGSLoadFormBuffer;
class TESContainer;

class TESLeveledList {
public:
    // 0x0042e680
    void FUN_0042e680(unsigned char);
    // 0x00487740
    void InitializeComponent();
    // 0x00487770
    void ClearComponent();
    // 0x004877e0
    bool GetAllBelow();
    // 0x004878a0
    bool GetUseAll();
    // 0x00487900
    void InitializeLeveledList();
    // 0x00487f70
    void PopulateContainerWithLeveledItems(unsigned short, unsigned short, ::TESContainer *, int);
    // 0x00488f10
    void Revert(::BGSLoadFormBuffer *);
};
