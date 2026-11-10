#pragma once

class MagicItem;
struct NiPoint3;
struct AETargetList;

struct AEGatherer {
public:
    // 0x00818ce0
    void GatherTargetsInArea(::MagicItem *, unsigned int, ::NiPoint3, ::AETargetList *);
};
