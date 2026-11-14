#pragma once

struct SCGeometry;
struct SCMapEntry;

struct SCConstantMap {
public:
    // 0x00e86ca0
    int LoadConstant(unsigned int, ::SCMapEntry *, ::SCGeometry *, void *, void *, void *, unsigned int, void *);
};
