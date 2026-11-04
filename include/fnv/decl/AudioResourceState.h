#pragma once

struct Description;
struct Receiver;

struct AudioResourceState {
public:
    // 0x00dbebe0
    void *ResolveSound(::Receiver *, ::Description *);
};
