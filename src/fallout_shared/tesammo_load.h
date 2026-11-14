// fallout_shared/tesammo_load.h: declares TESFileFormVersion, TESTextureLoader, CombatProcedure, TESRegionGrassObject, BGSImpactData and more

#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "tesammo_decls.h"
class TESFileFormVersion
{
  public:
};
class TESTextureLoader
{
  public:
};
struct CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};
class TESLandTexture;
class TESRegionGrassObject
{
  public:
    void AssignLandTexture(TESLandTexture*);
};
class BGSImpactData
{
  public:
};
class EncounterZoneData
{
  public:
    void Endian();
};
class TESAmmoNVEndian
{
  public:
};
class ActorCause;
class ScriptVariableInfo;
