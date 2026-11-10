#pragma once

class ActorPathingMessageQueue;
struct PathingRequest;
template <class> class NiPointer;

struct PathingTaskShell {
public:
    // 0x006e9db0
    void AssignRequestAndQueue(::PathingRequest *, ::NiPointer< ::ActorPathingMessageQueue>);
};
