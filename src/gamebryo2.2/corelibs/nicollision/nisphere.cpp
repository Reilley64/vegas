// gamebryo2.2/corelibs/nicollision/nisphere.cpp: free functions (1 function)
#include "fnv/decl/NiPoint3.h"
#include "nisphere_decls.h"

// Returns true when the plane comparison against other is not unequal, i.e. negates FUN_004390c0.
// @fnv 0x00439090
bool NiPlane::operator==(const NiPlane& other)
{
    return !reinterpret_cast<::NiPoint3 *>(this)->FUN_004390c0((const ::NiPoint3 &)(other));
}
