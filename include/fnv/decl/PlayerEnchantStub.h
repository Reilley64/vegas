#pragma once
#include <cstdint>

class TESBoundObject;

struct PlayerEnchantStub {
public:
    // 0x0095eb10
    void RemoveEnchantment(::TESBoundObject *, intptr_t);
};
