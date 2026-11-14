#pragma once

class TESObjectARMO;
struct ArmorRater;

struct ArmorContainer {
public:
    // 0x004829c0
    ::TESObjectARMO *FindBestArmorForSlot(::ArmorRater *, int);
};
