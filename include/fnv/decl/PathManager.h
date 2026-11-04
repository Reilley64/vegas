#pragma once

class ActorPathingMessageQueue;
class PathingRequest;
template <class> class NiPointer;

class PathManager {
public:
    // 0x006eb8c0
    bool Initialize();
    // 0x006eb9d0
    bool BuildPath(::NiPointer< ::PathingRequest>, ::NiPointer< ::ActorPathingMessageQueue>, bool);
};
