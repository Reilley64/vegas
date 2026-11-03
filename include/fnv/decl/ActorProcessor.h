#pragma once
#include <cstdint>

struct CollectionItem;
struct OutputRenderer;

struct ActorProcessor {
public:
    // 0x00476cb0
    int ProcessCollectionTree(::CollectionItem *, intptr_t, unsigned int, ::OutputRenderer *);
};
