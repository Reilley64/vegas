#pragma once

struct Context;
struct Node;
struct Receiver;

struct Walk {
public:
    // 0x00476dd0
    int WalkTree(::Node *, ::Receiver *, unsigned int, ::Context *, void *);
};
