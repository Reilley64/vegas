#pragma once

#include "fnv/decl/FUN_0044a4c0.h"

extern unsigned int g_010173f0;

namespace fnv_00ac87b0 {

// String owner used only by the 0x00ac87b0 parser family. Keeping its typed
// identity separate prevents this source-local wrapper from being confused
// with unrelated classes that inherited the same decompiler placeholder.
struct String final : FUN_0044a4c0 {
    String() = default;
    String(const char* text) : FUN_0044a4c0(text) {}
    String(const String&) = default;
    String(String&&) noexcept = default;
    String& operator=(const String&) = default;
    String& operator=(String&&) noexcept = default;

    String(const String& other, unsigned int offset)
    {
        assign(other, offset, static_cast<unsigned int>(::g_010173f0));
    }

    ~String() = default;
};

}  // namespace fnv_00ac87b0
