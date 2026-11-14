#pragma once

class NiNode;
class TESObjectREFR;
template <class> class BSSimpleList;

struct Animation {
public:
    // 0x0048ff50
    void FUN_0048ff50();
    // 0x0048ffd0
    bool Init(::BSSimpleList<const char *> *, ::NiNode *, ::TESObjectREFR *, bool);
    // 0x00498910
    void SpecialIdleFree(bool, bool);
    // 0x009442a0
    float FUN_009442a0() const;
};
