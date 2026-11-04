#pragma once
#include <cstdint>

struct ActorProxy;

struct ProcessProxy {
public:
    // 0x008ff0b0
    unsigned char FUN_008ff0b0(::ActorProxy *, intptr_t, ::ActorProxy *);
};
