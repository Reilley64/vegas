// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/tls.h"

// @fnv 0x0046e8a0
int __cdecl FUN_0046e8a0()
{
    return static_cast<int>(g_tlsBlock.messageWarningDisableCount);
}

// @fnv 0x004fffe0
void __cdecl FUN_004fffe0(int value)
{
    g_tlsBlock.messageWarningDisableCount = static_cast<unsigned int>(value);
}
