#pragma once
#include <cstdint>

namespace fnv_007d6ff0 { struct DebrisData; }
namespace fnv_007d6ff0 { class Tile; }

namespace fnv_007d6ff0 {
struct FUN_007d6ff0_shell {
public:
    // 0x007d6ff0
    ::fnv_007d6ff0::Tile *CreateListItem(intptr_t, const char *, int (*)(fnv_007d6ff0::DebrisData *, fnv_007d6ff0::DebrisData *), const char *);
};
}
