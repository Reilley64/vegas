// gamebryo2.2/corelibs/nimain/niobject_declarations.h: declares NiObject
#ifndef FNV_NIOBJECT_UNIT_DECLARATIONS_H
#define FNV_NIOBJECT_UNIT_DECLARATIONS_H

#include "fnv/decl/NiObject_b.h"
#include "niobject_nirefobject.h"

struct NiRTTI;

// Unit-private declaration view. NiObject's supplied canonical layout is
// NiRefObject with no additional fields. The bundled headers stay unchanged.
struct NiObject : public NiRefObject
{
  public:
    NiObject* DynamicCast(const NiRTTI* rtti);
};


#endif
