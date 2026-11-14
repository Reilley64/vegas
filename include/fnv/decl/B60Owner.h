#pragma once

struct B60State;

struct B60Owner {
public:
    // 0x00dd8b60
    void AdvanceState(unsigned char *, ::B60State *);
};
