#pragma once

struct Elem;

struct ElemPool {
public:
    // 0x00d9cd80
    int AllocElem(int, int, const ::Elem &);
};
