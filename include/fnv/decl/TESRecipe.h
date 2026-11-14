#pragma once

class RecipeCraftingInfo;
namespace ActorValue { enum Index; }
struct NiPoint3;

class TESRecipe {
public:
    // 0x00430830
    ::RecipeCraftingInfo *GetData();
    // 0x00572500
    ::NiPoint3 *FUN_00572500(::NiPoint3 *, float);
    // 0x005a80a0
    void ClearData();
    // 0x007037c0
    void SetRequiredSkill(::ActorValue::Index);
};
