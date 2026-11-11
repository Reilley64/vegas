#pragma once

#include "fnv/fixed_string_handle.h"

// The owning fixed-string handle, and the one shared declaration of the class.
// NiFixedString.h includes it. A unit that holds fixed strings by value without
// the owner's constructor and destructor defines FNV_KEEPS_PLAIN_NIFIXEDSTRING
// before its includes and gets the plain layout view of that header instead.
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
