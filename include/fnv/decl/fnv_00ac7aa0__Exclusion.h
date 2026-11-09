#pragma once

#include "fnv/decl/FUN_0044a4c0.h"

namespace fnv_00ac7aa0 {

// Owned exclusion value for FUN_00ac7aa0. The source-local FnvString material
// operations are not provided by the archive, so callers copy bytes into this
// complete canonical owner instead of treating another string layout as one.
struct Exclusion final : FUN_0044a4c0 {
    Exclusion() = default;
    explicit Exclusion(const char* text) : FUN_0044a4c0(text) {}
    Exclusion(const char* text, size_type length)
    {
        assign(text, length);
    }
};

}  // namespace fnv_00ac7aa0
