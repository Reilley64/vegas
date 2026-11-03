// fallout_shared/bgsdehydration_decls.h: declares BGSTerrainManager, WaitableObject

#include <windows.h>
#include <cmath>
#include "fnv/decl/FUN_009611e0_shell.h"
class BGSTerrainManager
{
  public:
public:
    unsigned int GetMinLevel();
};
float ConvertDoubleResult(float value);
unsigned long WaitForSingleObjectEx(long* value);
class WaitableObject
{
  public:
    virtual void vfn_0000();
    virtual void vfn_0004();
    long references;
    void FUN_00401970();
};
