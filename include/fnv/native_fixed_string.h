#pragma once

#include "fnv/fixed_string_handle.h"

// The owning fixed-string handle. Units that still manage the count by hand
// keep the plain layout view in NiFixedString.h; a unit includes only one.
class NiFixedString
{
public:
    char* m_kHandle;

    NiFixedString() noexcept;
    // 0x00438170
    NiFixedString(const char* text) noexcept;
    // 0x0048af40
    NiFixedString(const NiFixedString& other) noexcept;
    // 0x004381b0
    ~NiFixedString() noexcept;

    // 0x00a2e750
    NiFixedString& operator=(const char* text) noexcept;
    NiFixedString& operator=(const NiFixedString& other) noexcept;

    // 0x0048af70
    int IsNotEmpty() const noexcept;

    // Defined in nigeommorphercontroller.cpp.
    operator const char*() const;
    // 0x004b9900, defined in blk_004a0000_od.cpp: destroys, then frees when bit 0 of flags is set.
    void* FUN_004b9900(unsigned int flags);
};

static_assert(sizeof(NiFixedString) == sizeof(char*));
