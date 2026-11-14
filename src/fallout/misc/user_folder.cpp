// The user folder buffer and the function that returns it (VEGAS-109), in a
// unit of their own so that a link that reaches them loads no other code
// (VEGAS-127). They were defined in src/staging/blk_004c0000_od.cpp.
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_01202000.h"

char DAT_01202fa0[260];
// @fnv 0x004dc110
char* FUN_004dc110()
{
    // Callers write up to 260 characters through the result. The recipe
    // binds the next address, 0x012030a4, 260 bytes after the buffer.
    static_assert(sizeof(DAT_01202fa0) == 260);
    return DAT_01202fa0;
}
