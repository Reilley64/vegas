#pragma once

class Actor;
template <class> class BSSimpleList;

struct ZOwner {
public:
    // 0x00971c30
    ::BSSimpleList< ::Actor *> *CollectActorsByPackage(int, int, bool);
};
