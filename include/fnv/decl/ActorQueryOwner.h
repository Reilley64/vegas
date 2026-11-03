#pragma once

class Actor;
class TESObjectREFR;
template <class> class BSSimpleList;

class ActorQueryOwner {
public:
    // 0x009719e0
    ::BSSimpleList< ::Actor *> *FindDialogueSpeakers(::TESObjectREFR *, bool);
};
