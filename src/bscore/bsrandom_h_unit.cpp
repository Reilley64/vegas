
#include "bsrandom_singleton.h"
// @fnv 0x0049fef0
bsrandom_singleton::MersenneTwister* bsrandom_singleton::MersenneTwister::GetRandomGenerator()
{
    if (!DAT_011c57f8)
        DAT_011c57f8 = new MersenneTwister;
    return DAT_011c57f8;
}
