#pragma once

struct RefVolSrc;

class RefVolAccum {
public:
    // 0x00b65f60
    void UpdateOrAddItem(unsigned int, const ::RefVolSrc *, bool);
};
