#include "fnv/decl/FUN_0050e960_cls.h"
#include "actorvalue_vector.h"

// @fnv 0x0050ec30
ActorValueShortVector* ActorValueShortVector::Subtract(ActorValueShortVector* result,
                                                       const ActorValueShortVector& other)
{
    reinterpret_cast<::FUN_0050e960_cls *>((result))->FUN_0050e960(x - other.x, y - other.y, z - other.z);
    return result;
}
