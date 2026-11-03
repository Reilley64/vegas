// fallout/interface/interface_rebase_TESRecipe.h: declares TESRecipe
#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_TESRECIPE_DECLARATION_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_TESRECIPE_DECLARATION_H
#include "interface_rebase_TESForm.h"
#include "interface_rebase_TESFullName.h"
#include "interface_rebase_TESCondition.h"
class TESRecipeCategory;
class QuantityData;
class TESRecipe : public TESForm, public TESFullName
{
  public:
    TESRecipe();
    ~TESRecipe();
    struct Data
    {
        ActorValue::Index eReqSkill;
        int iReqSkillLevel;
        unsigned int uiCategoryID;
        unsigned int uiSubCategoryID;
    };
    Data kData;
    PerkEntryConditionSet kConditions;
    BSSimpleList<QuantityData*> kIngredients;
    BSSimpleList<QuantityData*> kOutputs;
    BSSimpleList<QuantityData*> kGarbageCollection;
    TESRecipeCategory* pCategory;
    TESRecipeCategory* pSubCategory;
    void SetRequiredSkill(ActorValue::Index);
};
#endif
