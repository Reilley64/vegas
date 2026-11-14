// gamebryo2.2/corelibs/nicollision/nisphere_decls.h: declares NiPlane
#ifndef FNV_NISPHERE_DECLS_H
#define FNV_NISPHERE_DECLS_H
#include "fnv/decl/NiPoint3.h"
struct NiPlane
{
  public:
    float normal[3];
    float constant;
    bool operator==(const NiPlane& other);
};
#endif
