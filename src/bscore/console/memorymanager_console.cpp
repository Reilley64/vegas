
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_011f6000.h"
struct MemoryPool;


// @fnv 0x00aa6840
void ClearMemoryPoolTables()
{
    unsigned int uiIndex;
    for (uiIndex = 0; uiIndex < 0x100; ++uiIndex)
        DAT_011f67b8[uiIndex] = 0;
    unsigned int uiIndex2;
    for (uiIndex2 = 0; uiIndex2 < 0x100; ++uiIndex2)
        ::ms_pPoolAddressMap[uiIndex2] = 0;
}

#include "generated/data/bscore/console/memorymanager_console.inc"
