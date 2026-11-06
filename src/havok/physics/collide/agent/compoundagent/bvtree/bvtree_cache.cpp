#include "havok/BvTreeCache.h"

unsigned char DAT_011b4284 = 1;

// @fnv 0x00d2f530
void FUN_00d2f530(unsigned char* p)
{
    *p = DAT_011b4284;
}

// @fnv 0x00d2f540
void FUN_00d2f540(unsigned char value)
{
    DAT_011b4284 = value;
}
