#pragma once

struct SelectionTile;

struct SelectionList {
public:
    // 0x0072a660
    void UpdateSelection(bool);
    // 0x007a7a60
    void UpdateSelectionState();
    // 0x007d9000
    bool ApplySelectionAction(::SelectionTile *, int);
};
