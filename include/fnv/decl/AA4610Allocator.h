#pragma once

class AA4610Pool;

class AA4610Allocator {
public:
    // 0x00aa4610
    ::AA4610Pool *FindPoolContaining(void *);
};
