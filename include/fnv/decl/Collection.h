#pragma once

struct Ref;
struct State;

struct Collection {
public:
    // 0x005273c0
    bool FindNextRef(::State *, ::Ref **, ::Ref **, unsigned int);
};
