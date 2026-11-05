#include "fnv/symbols_00401000.h"
#include "runtime/crt.h"

// Replaces the integer pointed to by p with the result of calling FUN_00ec3bad on its current value.
// @fnv 0x00401080
void FUN_00401080(int* piValue)
{
    int* q = piValue;
    *q = fnv::crt::byteswap_ulong(*q);
}
