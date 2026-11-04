#pragma once
#include <cstdint>

class TESBoundObject;

namespace ActorInventoryQueryViews {
struct ActorQuery {
public:
    // 0x00891db0
    bool FUN_00891db0(::TESBoundObject *, intptr_t, int, uintptr_t, int &);
};
}
