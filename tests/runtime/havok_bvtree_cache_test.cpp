#include "havok/BvTreeCache.h"

#include <bit>
#include <cstdio>

int main()
{
    unsigned char value = 0;
    FUN_00d2f530(&value);
    if (value != 1 || DAT_011b4284 != 1) return 1;
    for (unsigned int i = 0; i != 256; ++i)
    {
        const auto byte = static_cast<unsigned char>(i);
        FUN_00d2f540(byte);
        FUN_00d2f530(&value);
        if (value != byte || DAT_011b4284 != byte) return 2;
        // Existing cache readers interpret this storage through char, not bool.
        if ((*reinterpret_cast<char*>(&DAT_011b4284) != 0) != (i != 0)) return 3;
        if (std::bit_cast<signed char>(DAT_011b4284) !=
            (i < 128 ? static_cast<int>(i) : static_cast<int>(i) - 256)) return 4;
        DAT_011b4284 = static_cast<unsigned char>(255 - i);
        FUN_00d2f530(&value);
        if (value != 255 - i) return 5;
    }
    FUN_00d2f540(1);
    std::puts("BvTree public entries: initial byte, all 256 values, signed interpretations, shared mutation passed");
}
