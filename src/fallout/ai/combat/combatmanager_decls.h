// fallout/ai/combat/combatmanager_decls.h: declares CombatThreatMap, SettingT_GameSettingCollection_
#ifndef FNV_COMBATMANAGER_DECLS_H
#define FNV_COMBATMANAGER_DECLS_H


#include "fnv/decl/B8EB30Group.h"
#include "fnv/decl/FUN_009865b0_shell.h"
#include "fnv/decl/FUN_00990890_shell.h"
#include "fnv/decl/FUN_009a5cd0_cls.h"
#include "fnv/decl/Target.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011de000.h"
#include "combatmanager_types_CombatManager.h"
#include "PlayerCharacter.h"
#include "AutoMemContext.h"

class BGSLoadGameBuffer;

class ActorCombatGroup
{
  public:
    CombatTargetTimestamp GetLastDetectedTimestamp(Actor* actor);
};

struct BGSSaveFormBuffer;
class CombatThreatMap
{
  public:
public:
    void SaveThreats(::BGSSaveFormBuffer *);
};

class SettingT_GameSettingCollection_
{
  public:
};


typedef ActorCombatGroup*(__thiscall* ActorGetCombatGroupProc)(Actor* actor);

#endif
