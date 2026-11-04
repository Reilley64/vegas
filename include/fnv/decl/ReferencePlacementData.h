#pragma once

class TESObjectCELL;
class TESWorldSpace;

class ReferencePlacementData {
public:
    // 0x00849280
    ReferencePlacementData();
    // 0x0084e610
    bool GetCellAndWorld(::TESObjectCELL *&, ::TESWorldSpace *&);
};
