#pragma once

namespace vecb1e2 { struct VcConstIterator; }
namespace vecb1e2 { struct VcIterator; }

namespace vecb1e2 {
struct VcVector {
public:
    // 0x00b1e2f0
    void FUN_00b1e2f0();
    // 0x00b1f800
    ::vecb1e2::VcIterator erase(::vecb1e2::VcConstIterator, ::vecb1e2::VcConstIterator);
};
}
