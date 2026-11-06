// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00ee6000.h"

#include <cstring>

// Native transpose of a 4x4 float matrix into caller-owned storage.
// @fnv 0x00ee6dd4
void* FUN_00ee6dd4(void* pOut, const void* pM)
{
    static_assert(sizeof(float) == 4);
    // Stage every element before writing pOut so exact in-place calls are safe.
    // Copy representations rather than aliasing the callers' matrix structs.
    unsigned char transposed[16 * sizeof(float)];
    const auto* source = static_cast<const unsigned char*>(pM);
    for (unsigned int row = 0; row < 4; ++row)
        for (unsigned int column = 0; column < 4; ++column)
            std::memcpy(transposed + (row * 4 + column) * sizeof(float),
                        source + (column * 4 + row) * sizeof(float), sizeof(float));
    std::memcpy(pOut, transposed, sizeof(transposed));
    return pOut;
}
