#pragma once
#include <cstdint>

struct SerializedObject {
public:
    // 0x00cf4670
    void SerializeToStream(intptr_t);
};
