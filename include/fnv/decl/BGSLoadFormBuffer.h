#pragma once

#include "fnv/decl/BGSLoadGameBuffer.h"

class BGSLoadFormBuffer : public BGSLoadGameBuffer {
public:
    // 0x008643b0
    BGSLoadFormBuffer();
    // 0x008a81c0
    unsigned char GetVersion() override;
};
