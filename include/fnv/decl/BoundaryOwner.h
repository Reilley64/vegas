#pragma once

class TESObjectCELL;
struct BoundaryBox;

struct BoundaryOwner {
public:
    // 0x00627980
    void BuildWalls(::TESObjectCELL *, const ::BoundaryBox *);
};
