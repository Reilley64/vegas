#pragma once
#include <cstdint>

struct UpdateObject;

struct UpdateOwner {
public:
    // 0x006056f0
    void FUN_006056f0(::UpdateObject *);
    // 0x0098e990
    void UpdateElements(std::uintptr_t);
};
