#pragma once

#include <cstdint>

struct TMapStandIn {
public:
    // 0x00470200
    void InsertOrUpdate(std::uintptr_t, void *);
};
