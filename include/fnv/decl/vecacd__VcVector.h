#pragma once

namespace vecacd { struct VcConstIterator; }
namespace vecacd { struct VcIterator; }

namespace vecacd {
struct VcVector {
public:
    // 0x00acdba0
    void FUN_00acdba0();
    // 0x00ad0110
    ::vecacd::VcIterator erase(::vecacd::VcConstIterator, ::vecacd::VcConstIterator);
};
}
