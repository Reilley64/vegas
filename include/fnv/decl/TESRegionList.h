#pragma once

struct TESRegion;

struct TESRegionList {
public:
    // 0x004f6600
    bool AddRegion(::TESRegion *);
};
