#pragma once

struct ActorProcessView;

struct InventoryListView {
public:
    // 0x004d1180
    float GetInventoryWeight(::ActorProcessView *);
};
