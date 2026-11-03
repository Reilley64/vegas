#pragma once
#include <cstdint>

namespace list71a { struct L71Item; }
namespace list71a { struct L71Tile; }

namespace list71a {
struct L71Menu {
public:
    // 0x0071a320
    ::list71a::L71Tile *FUN_0071a320(intptr_t, const char *, int (*)(list71a::L71Item *, list71a::L71Item *), ::list71a::L71Tile *);
};
}
