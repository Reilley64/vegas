#pragma once

class TESObjectCELL;
class TESWorldSpace;

struct FUN_00461c20_Holder {
public:
    // 0x00461c20
    ::TESObjectCELL *GetOrCreateCell(int, int, ::TESWorldSpace *, bool);
};
