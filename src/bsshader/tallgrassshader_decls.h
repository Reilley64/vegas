// bsshader/tallgrassshader_decls.h: declares MemoryManager, TallGrassShader

#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/symbols_011f6000.h"
class MemoryManager
{
  public:
};
// The lazily allocated constants object; constructor identity is unresolved.
class FUN_00ba94b0
{
  public:
    FUN_00ba94b0(unsigned int);
    char data[20];
};
class TallGrassShader
{
  public:
    char prefix[60];
    FUN_00ba94b0* constants;
    void InitializeConstants(unsigned int);
};
