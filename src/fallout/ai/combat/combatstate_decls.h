// fallout/ai/combat/combatstate_decls.h: declares InventoryChanges, CombatLocations, CombatLOS, CombatPrefix, CombatState
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_004c8f30_shell.h"
#include "fnv/decl/FUN_008be220_cls.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_00884000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_011d5000.h"
class TESObjectREFR;
class TESForm;
class TESObjectREFR;
class InventoryChanges
{
  public:
public:
    static ::InventoryChanges *CreateForReference(::TESObjectREFR *);
};
class CombatLocations
{
  public:
    virtual void Clear();
};
class CombatLOS
{
  public:
};
class CombatPrefix
{
  public:
    virtual void PrefixSlot();
    char pad04[0x64];
    CombatLOS* los;
    char pad6c[0x3c];
};
class CombatState : public CombatPrefix, public CombatLocations
{
  public:
    int GetInventoryItemCount(TESForm*);
    void ProcessCoverLOSResult();
    char padac[0x3c];
    void* unke8;
    char padec[0x90];
    float timer, offsetX, offsetY;
    void UpdateCombatStateData(int, float*, float*, float);
};

class GlobalObject_0044f440
{
  public:
};
