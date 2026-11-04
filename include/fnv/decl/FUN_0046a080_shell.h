#pragma once

#include <cstdint>

class TESObjectCELL;
class TESObjectREFR;
class TESWorldSpace;
struct NiPoint3;

struct FUN_0046a080_shell {
public:
    // 0x0046a080
    std::intptr_t CreateExplosion(::TESObjectREFR *, ::NiPoint3 *, ::NiPoint3 *, ::TESObjectCELL *, ::TESWorldSpace *);
};
