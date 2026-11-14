#ifndef FNV_ITEMCHANGE_H
#define FNV_ITEMCHANGE_H

#include "fnv/decl/FUN_004bcdb0_shell.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "layout_support.h"
class InventoryStackRecord
{
  public:
    BSSimpleList<ExtraDataList*>* m_pExtraDataLists;  // +0x0
    float GetArmorDamageThreshold(Actor* actor);
    static float GetConditionPercent(float health);
    bool SetEquipmentState(int effect, float& value);
    static float RoundToNearestStep(float value, float maximum);
    int m_iCountChange;             // +0x4
    TESBoundObject* m_pItemObject;  // +0x8
};
#endif
