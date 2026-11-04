
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00476000.h"
struct S_0062e910
{
    float RandomSignedFloat(float fImpulseRadiusSquared);
};
// @fnv 0x0062e910
float S_0062e910::RandomSignedFloat(float afRange)
{
    return RandomFloat(-afRange, afRange);
}
