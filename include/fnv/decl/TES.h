#pragma once

class NiPoint3;
struct GridCell;
struct TESObjectREFR;

struct TES {
public:
    // 0x00451e40
    bool IsRefUsable(::TESObjectREFR *);
    // 0x00452580
    int FindCellAtPosition(const ::NiPoint3 *, bool);
    // 0x00457050
    ::GridCell *FUN_00457050(int, int);
    // 0x008c45a0
    void FUN_008c45a0(unsigned char);
};
