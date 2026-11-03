
// src/fallout/ai/combat/combatdialoguemanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatdialoguemanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/P029Manager.h"
#include "fnv/symbols_0097a000.h"
struct CombatController
{
};
struct AlchemyItem
{
public:
    void *FUN_004030b0();
};
struct TESAmmoInitCalls
{
};
struct CombatDialogueHandler
{
    bool FUN_00983970(CombatController*, int, int, bool);
};
// Calls FUN_004030b0 with the dialogue type, topic and interrupt flag, passes the result through GetFieldBC, then calls TryStartDialogue with the combat controller.
// @fnv 0x00983970
bool CombatDialogueHandler::FUN_00983970(CombatController* apCombatController, int aiDialogueType, int aiDialogueTopic,
                                         bool abInterrupt)
{
    return reinterpret_cast<::P029Manager *>(this)->TryStartDialogue(
        (::P029Actor *)(((unsigned int)(::GetFieldBC((::FUN_0097ae90_Class *)(((TESAmmoInitCalls*)apCombatController))
                )))),
        apCombatController, {}, {}, {}, {});
}
