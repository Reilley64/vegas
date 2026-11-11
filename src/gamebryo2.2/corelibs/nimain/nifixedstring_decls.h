// gamebryo2.2/corelibs/nimain/nifixedstring_decls.h: declares NiFixedString, NiGlobalStringTable
#ifndef FNV_NIFIXEDSTRING_DECLS_H
#define FNV_NIFIXEDSTRING_DECLS_H
#include <windows.h>
#include "fnv/symbols_0109b000.h"
#include "fnv/native_fixed_string.h"
struct NiGlobalStringTable
{
  public:
    static char* AddString(const char* pcString);
};
#endif
