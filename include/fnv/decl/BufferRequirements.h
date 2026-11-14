#pragma once

struct CountProvider;

struct BufferRequirements {
public:
    // 0x00dd4b80
    int ComputeRequiredSize(::CountProvider *);
};
