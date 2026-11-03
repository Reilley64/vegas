#pragma once
#include <cstdint>

class Actor;
template <class> class BSSimpleList;

struct ZOwner {
public:
    // 0x00971c30
    ::BSSimpleList< ::Actor *> *CollectActorsByPackage(intptr_t, int, bool);
};
