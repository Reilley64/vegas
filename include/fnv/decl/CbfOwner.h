#pragma once
#include <cstdint>

class CbfTarget;
struct CbfSrc;

struct CbfOwner {
public:
    // 0x00cbf860
    void FUN_00cbf860(::CbfTarget *, ::CbfSrc *, int *, intptr_t, intptr_t);
};
