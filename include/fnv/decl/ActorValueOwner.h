#pragma once

namespace ActorValue { enum Index; }

class ActorValueOwner {
public:
    // 0x005f78e0
    ActorValueOwner();
    // 0x0066ef20
    int GetActorValueAsInteger(::ActorValue::Index);
    // 0x0066ef50
    float GetActorValueFloatByIndex(::ActorValue::Index);
};
