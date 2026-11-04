#pragma once

namespace ActorValue { enum Index; }

class ActorValueStore {
public:
    // 0x008c6e90
    ActorValueStore();
    // 0x008c6eb0
    void ResetCacheValues();
    // 0x008c6f40
    void InvalidateValue(::ActorValue::Index);
};
