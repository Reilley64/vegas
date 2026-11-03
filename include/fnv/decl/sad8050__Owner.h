#pragma once

#include <cstdint>

namespace sad8050 {
struct Owner {
public:
    // 0x00ad8050
    void ForwardToManager(std::intptr_t, int);
};
}
