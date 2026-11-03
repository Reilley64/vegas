// fallout_shared/tesrecipe.cpp: TESRecipe, TESRecipeCategory (4 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_005a8040_class.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006a9000.h"
#include "tesrecipe.h"
#include <malloc.h>

static const char s_kRecipeCategoryWarning[] =
    "MASTERFILE: Recipe Category (%08X) not found in InitItem for Recipe (%08X) '%s'.";
static const char s_kRecipeSubCategoryWarning[] =
    "MASTERFILE: Recipe (sub)Category (%08X) not found in InitItem for Recipe (%08X) '%s'.";

// @fnv 0x005a80a0
void TESRecipe::ClearData()
{
    ((::PerkEntryConditionSet *)(::FUN_006a9540((char *)this)))->InitializeConditionItems();
    reinterpret_cast<::FileMatchList *>((((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))))->RemoveAll();
    reinterpret_cast<::FileMatchList *>((((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->RemoveAll();
    reinterpret_cast<::FileMatchList *>((((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()))))->RemoveAll();
    reinterpret_cast<::TESRecipe *>(this)->SetRequiredSkill((::ActorValue::Index)(-1));
    reinterpret_cast<::FUN_0061cc40_shell *>(this)->FUN_0061cc40(0);
    reinterpret_cast<::FUN_005a8040_class *>(this)->SetField54((int)(0));
    reinterpret_cast<::LowProcess *>(this)->SetPackageObjectType((int)(0));
}

// Initializes recipe category, subcategory, and ingredient/output lists by resolving form IDs, then marks the form as initialized.
// @fnv 0x005a7e00
void TESRecipe::InitItem()
{
    TESForm* item;
    TESForm* form;
    QuantityData* component;
    TESRecipeCategory* category;
    BSSimpleList<QuantityData*>* compList;
    unsigned int level;
    unsigned int id;
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;
    reinterpret_cast<::PerkEntryConditionSet *>((static_cast<TESConditionInit*>(&RecipeItemProcessor)))->InitItem(this);
    level = GetData()->m_iRequiredLevel;
    category = 0;
    id = GetData()->CategoryID;
    if (id)
    {
        ::ResolveFormID((unsigned int *)&(id), GetFile(-1));
        category = dynamic_cast<TESRecipeCategory*>(::FUN_004839c0(id));
        if (!category)
            ::FUN_005b5e40();
        else
            reinterpret_cast<::FUN_005a8040_class *>(this)->SetField54((std::intptr_t)(category));
    }
    category = 0;
    id = GetData()->SubCategoryID;
    if (id)
    {
        ::ResolveFormID((unsigned int *)&(id), GetFile(-1));
        category = dynamic_cast<TESRecipeCategory*>(::FUN_004839c0(id));
        if (!category)
            ::FUN_005b5e40();
        else
            reinterpret_cast<::LowProcess *>(this)->SetPackageObjectType((int)(category));
    }
    compList = ((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()));
    component = 0;
    while (compList && (compList->m_item))
    {
        component = (compList->m_item);
        compList = ((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<::Callees *>((compList))->FUN_00726070()));
        form = ::FUN_004839c0((unsigned int)reinterpret_cast<std::uintptr_t>(((::TESForm *)(reinterpret_cast<::Callees *>((component))->FUN_00726070()))));
        reinterpret_cast<::CombatProcedure *>((component))->Initialize((::CombatController *)(form));
    }
    compList = ((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    component = 0;
    while (compList && (compList->m_item))
    {
        component = (compList->m_item);
        compList = ((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<::Callees *>((compList))->FUN_00726070()));
        item = ::FUN_004839c0((unsigned int)reinterpret_cast<std::uintptr_t>(((::TESForm *)(reinterpret_cast<::Callees *>((component))->FUN_00726070()))));
        reinterpret_cast<::CombatProcedure *>((component))->Initialize((::CombatController *)(item));
    }
    SetInitializationState(true);
}

// Parses recipe chunks (ID, OBND, FNAM, DATA, CND, CRIN, CRO, CRQ) from a TESFile, building ingredient and output lists from QuantityData entries.
// @fnv 0x005a8110
bool TESRecipe::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    QuantityData* component;
    unsigned int formID;
    bool bOutput;
    int chunk;
    ClearData();
    if (formType != 0x6A)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    component = 0;
    formID = 0;
    bOutput = false;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* buffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4C4C5546:  // FULL
            ::ReadFullName(this, file);
            break;
        case 0x41544144:  // DATA
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00414220_shell *>(&(data))->FUN_00414220();
            break;
        case 0x41445443:  // CTDA
            ((::PerkEntryConditionSet *)(::FUN_006a9540((char *)this)))->Load(file);
            break;
        case 0x4C494352:  // RCIL
        {
            bOutput = false;
            component = new QuantityData;
            unsigned int ingredientID = 0;
            file->GetChunkData(&ingredientID);
            ::ResolveFormID((unsigned int *)&(ingredientID), GetFile(-1));
            formID = ingredientID;
            break;
        }
        case 0x444F4352:  // RCOD
        {
            bOutput = true;
            component = new QuantityData;
            unsigned int outputID = 0;
            file->GetChunkData(&outputID);
            ::ResolveFormID((unsigned int *)&(outputID), GetFile(-1));
            formID = outputID;
            break;
        }
        case 0x59514352:  // RCQY
        {
            unsigned int quantity = 0;
            file->GetChunkData(&quantity);
            reinterpret_cast<::FUN_00537e90 *>((component))->SetQuantity(quantity);
            break;
        }
        }
        if (component && ((unsigned int)(::FUN_00559450((int *)(component)))) > 0 && formID > 0)
        {
            reinterpret_cast<::CombatProcedure *>((component))->Initialize((::CombatController *)(::TESForm *)(reinterpret_cast<TESForm*>(formID)));
            if (bOutput)
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00905820((void *)&(component));
            else
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::QuantityData *> *)(reinterpret_cast<struct ::FUN_005a8080 *>(this)->GetField()))))->FUN_00905820((void *)&(component));
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Loads a TESRecipeCategory record from a file, validating form type 0x6B and parsing EDIT, OBND, FNAM, and DATA chunks.
// @fnv 0x005a7910
bool TESRecipeCategory::Load(TESFile* file)
{
    int chunk;
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x6B)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* pEditorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEditorID), 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4C4C5546:  // FULL
            ::ReadFullName(this, file);
            break;
        case 0x41544144:  // DATA
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &data, sizeof(data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::TESForm *>(&(data))->ClearData();
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}
