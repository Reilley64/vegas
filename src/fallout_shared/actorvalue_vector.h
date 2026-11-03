// fallout_shared/actorvalue_vector.h: declares ActorValueShortVector
#ifndef FNV_ACTORVALUE_VECTOR_H
#define FNV_ACTORVALUE_VECTOR_H
// Three signed components observed in the PC implementation.
#include "fnv/decl/FUN_0050e960_cls.h"
struct ActorValueShortVector
{
    short x, y, z;
    ActorValueShortVector* Subtract(ActorValueShortVector* result, const ActorValueShortVector& other);
};
#endif
