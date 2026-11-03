#pragma once

class Actor;
class ActorMover;
class PathingRequest;
class PathingSolution;
template <class> class NiPointer;

class VirtualActorPathHandler {
public:
    // 0x009ea770
    VirtualActorPathHandler(::Actor *, ::ActorMover *, ::NiPointer< ::PathingSolution> &, ::PathingRequest *);
};
