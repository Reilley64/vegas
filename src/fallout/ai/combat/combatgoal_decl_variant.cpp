
// src/fallout/ai/combat/combatgoal_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x009843b0: the skeleton of src/fallout/ai/combat/combatgoal.cpp
// with declarations corrected to what the original code does (combatgoal.h: CombatGoal += bool FUN_009843b0(class CombatStateValues* values); BSSimpleList<UnsignedIdHandle*>* FUN_00717e50();; layout_support.h: void Sort(int (FNV_CDECL *compare)(T, T)); }; -> void Sort(int (FNV_CDECL *compare)(T, T)); BSSimpl). Move the function to its real unit once
// that unit declares it this way.

#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00984470_Class.h"
#include "fnv/decl/FUN_009aadc0_cls.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "combatgoal_decl_combatgoal.h"

class UnsignedIdHandle
{
  public:
    int type;
    int value;
};
class CombatStateValues
{
  public:
};
// @fnv 0x009843b0
bool CombatGoal::FUN_009843b0(CombatStateValues* values)
{
    BSSimpleList<UnsignedIdHandle*>* current = ((::BSSimpleList< ::UnsignedIdHandle *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    UnsignedIdHandle* value;
    int state;
    int type;
    while (current && ((::UnsignedIdHandle *)(new ((void *)(current)) ::Vec3())))
    {
        value = ((::UnsignedIdHandle *)(new ((void *)(current)) ::Vec3()));
        state = ::FUN_00559450((int *)(value));
        type = ((int)(reinterpret_cast<::Callees *>((value))->FUN_00726070()));
        if (state == 21)
        {
            if (((unsigned int)(reinterpret_cast<::FUN_00984470_Class *>((values))->GetCombatGoal(type))))
                return false;
        }
        else if (state == 22)
        {
            if (!((unsigned int)(reinterpret_cast<::FUN_00984470_Class *>((values))->GetCombatGoal(type))))
                return false;
        }
        else
        {
            if (!((bool)(reinterpret_cast<::FUN_009aadc0_cls *>((values))->FUN_009aadc0(state, type))))
                return false;
        }
        current = ((::BSSimpleList< ::UnsignedIdHandle *> *)(reinterpret_cast<::CombatWorldStateListNode *>((current))->GetNext()));
    }
    return true;
}
