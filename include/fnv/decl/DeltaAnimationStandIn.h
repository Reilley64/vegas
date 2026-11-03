#pragma once

struct CompressedBlockRange;

class DeltaAnimationStandIn {
public:
    // 0x00e34bb0
    void GetCompressedBlockRange(unsigned int, unsigned int, ::CompressedBlockRange *);
};
