// The buffer that FUN_0086d480 returns and the function, in a unit of
// their own so that a link that reaches them loads no other code
// (VEGAS-128). They were defined in src/fallout/misc/main.cpp (VEGAS-112).
// FUN_0086d480 calls nothing, so it is declared noexcept: a caller in
// main.cpp then compiles its call as one that cannot throw, as it did while
// the definition was in that unit.
#include "fnv/symbols_0086d000.h"

char DAT_01202e98[260];
// @fnv 0x0086d480
char* __cdecl FUN_0086d480() noexcept
{
    // BGSSaveLoadManager::GetSaveDirectory copies a folder of up to 260
    // characters there. The recipe binds the next address, 0x01202fa0, 264
    // bytes after the buffer.
    static_assert(sizeof(DAT_01202e98) == 260);
    return DAT_01202e98;
}
