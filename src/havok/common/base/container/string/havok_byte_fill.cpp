#include "fnv/havok_byte_fill.h"

#include <cstring>

// @fnv 0x00cb1280
void __cdecl FUN_00cb1280(void* dest, int value, uintptr_t count)
{
    std::memset(dest, value, count);
}
