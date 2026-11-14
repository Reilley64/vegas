#pragma once

struct NiPoint3;
class TESObjectCELL;
class TESWorldSpace;

struct SetupPathingLocation {
public:
    // 0x006dd280
    void FUN_006dd280(const ::NiPoint3 &, ::TESObjectCELL *, ::TESWorldSpace *);
};
