#ifndef FNV_PATHINGINFO_H
#define FNV_PATHINGINFO_H
#include "fnv/decl/NiRefObject.h"
#include "fnv/symbols_0040b000.h"
#include "fnv/symbols_0101d000.h"
#include "pathinginfo_decls.h"
class PathingInfo
{
  public:
    const unsigned char* vtable;
    unsigned int references;
    PathingInfo();
};
// @fnv 0x004968b0
PathingInfo::PathingInfo()
{
    vtable = &(*reinterpret_cast<const unsigned char *>(&::DAT_0101dce4));
    references = 0;
    ::FUN_0040b460((unsigned int *)(void *)((void*)&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount))));
}
#endif
