#include "fnv/symbols_00407000.h"
#include "runtime/crt.h"

// Replaces the short value pointed to by p with the result of FUN_00ec3bda applied to it.
// @fnv 0x00407a90
void __cdecl FUN_00407a90(short* psValue)
{
    short* tmp = psValue;
    *tmp = fnv::crt::byteswap_ushort(*tmp);
}
