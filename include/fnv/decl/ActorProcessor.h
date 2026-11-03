#pragma once

struct CollectionItem;
struct OutputRenderer;

struct ActorProcessor {
public:
    // 0x00476cb0
    int ProcessCollectionTree(::CollectionItem *, int, unsigned int, ::OutputRenderer *);
};
