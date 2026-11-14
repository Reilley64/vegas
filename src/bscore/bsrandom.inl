
// bscore/bsrandom.inl
//
// Random helpers defined only by bsrandom.cpp.
#include "fnv/decl/FUN_00476b90_shell.h"
#include "fnv/decl/FUN_00476be0_Class.h"
#include "bsrandom.h"

// @fnv 0x00476c00
MersenneTwister* MersenneTwister::GetRandomGenerator()
{
    static MersenneTwister s_instance;
    return &s_instance;
}

// @fnv 0x00476b70
float RandomFloat(float lo, float hi)
{
    return MersenneTwister::GetRandomGenerator()->FUN_00476b90(lo, hi);
}

// @fnv 0x005c5420
float RandomFloat0To1()
{
    return MersenneTwister::GetRandomGenerator()->Float0To1();
}

// @fnv 0x004dff00
bool RandomBoolean(float chance)
{
    return MersenneTwister::GetRandomGenerator()->Bool(chance);
}

// @fnv 0x004dff60
float MersenneTwister::Float0To1()
{
    unsigned int value = FUN_00476be0();
    return (float)(value * (1.0 / 4294967296.0));
}

// @fnv 0x004dff20
bool MersenneTwister::Bool(float chance)
{
    return chance >= Float0To1();
}
