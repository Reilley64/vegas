
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/FUN_009a5170_Class.h"
#include "fnv/decl/FUN_00aa62e0_shell.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_00aa6000.h"
class TESFile;
class BGSReconstructFormsInFileMap;
class BGSReconstructFormsInAllFilesMap
{
  public:
    void* GetFirstPos();
};
class BGSSaveLoadChangesMap
{
  public:
};
class Actor
{
  public:
};
class CombatThreatRecord
{
  public:
    ~CombatThreatRecord();
};
class CombatTargetMapLock
{
  public:
};
class CombatTargetMap
{
  public:
    unsigned char mapStorage[16];
    CombatTargetMapLock lock;
    void ResetTargetMap();
};
