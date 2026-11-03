// fallout/misc/saveload/bgschangeflags_decls.h: declares FormChangeMask, FormChangeRecord, BGSChangeFlagsState

#include "fnv/decl/BSFlags.h"
#include "fnv/symbols_00559000.h"
class GlobalObject_008c71b0
{
  public:
    int value;
    GlobalObject_008c71b0(int value);
};
class FormChangeMask
{
  public:
    unsigned int flags;
    static FormChangeMask HasFormChanged(FormChangeMask changes, FormChangeMask forced, int type, bool enabled);
};
class FormChangeRecord
{
  public:
    unsigned int flags;
};
class BGSChangeFlagsState
{
  public:
    unsigned char padding[0x28];
    unsigned int flags;
    void CombineFlags(bool enabled);
};
