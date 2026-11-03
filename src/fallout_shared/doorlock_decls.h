// fallout_shared/doorlock_decls.h: declares TESObjectREFR, LowProcess, ExtraRadioData, MemoryManager, ActorData and more
#ifndef FNV_DOORLOCK_DECLS_H
#define FNV_DOORLOCK_DECLS_H


#include <new>

#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/fnv_00567960__FUN_00567960_shell.h"
#include "fnv/decl/s5679f0__Owner.h"
#include "fnv/symbols_00401000.h"
class TESActorBase;
class TESObjectCELL;
class TESObjectREFR;
class TESGlobal;
class TESForm;
class LockExtraData;
class ExtraRadioData;
class TESActorBase;
class InventoryChanges;

class TESObjectREFR
{
  public:
    ExtraRadioData* GetExtraRadioData();
};

class LowProcess
{
  public:
    TESObjectREFR* GetTarget();
};

class ExtraRadioData
{
  public:
};

class MemoryManager
{
  public:
};

class FUN_00411b00;

class ActorData
{
  public:
    unsigned char layoutPadding[12];
    ActorData(Actor* actor);
};

class PathingActorData
{
  public:
    TESActorBase* m_pActorBaseFormItem;
    InventoryChanges* m_pInventoryChangesValue;
    bool m_bCanIgnoreLocks;
    unsigned char layoutPadding9[3];

    PathingActorData& operator=(const PathingActorData& other);
};

#endif
