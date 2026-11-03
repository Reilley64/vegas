// fallout_shared/bgsbipedmodellist.cpp: BGSBipedModelList (8 functions)

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00480d50_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008c6060_shell.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "bgsbipedmodellist_decls.h"
// Returns the biped model list of a TESForm if it is an NPC or armor, otherwise null.
// @fnv 0x00475020
BGSBipedModelList* BGSBipedModelList::GetBipedModelList(TESForm* form)
{
    BGSBipedModelList* result = 0;
    if (form)
    {
        switch (form->GetFormType())
        {
        case kNPC: {
            TESNPC* npc = static_cast<TESNPC*>(form);
            result = npc ? &npc->biped : 0;
            break;
        }
        case kArmor: {
            TESObjectARMO* armor = static_cast<TESObjectARMO*>(form);
            result = armor ? &armor->biped : 0;
            break;
        }
        }
    }
    return result;
}

// Resolves the list form by ID, warns if it is missing or not a BGSListForm, and validates each entry as a biped model.
// @fnv 0x00474da0
void BGSBipedModelList::InitItem(TESForm* owner)
{
    unsigned int formID = (unsigned int)list;
    if (formID)
    {
        TESFile* file = owner ? owner->GetFile(-1) : 0;
        ::ResolveFormID((unsigned int *)&(formID), file);
        list = dynamic_cast<BGSListForm*>(::FUN_004839c0(formID));
        bool bad;
        if (!list)
        {
            if (owner)
            {
                if (((BGSCameraPath*)owner)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            else
                ::FUN_005b5e40();
        }
        else
        {
            bad = false;
            BSSimpleList<BGSPerkEntry*>* iter = (BSSimpleList<BGSPerkEntry*>*)((BGSCameraPath*)list)->GetConditions();
            TESForm* entry;
            while (iter && !((BSSimpleList<BGSCameraShot*>*)iter)->IsEmpty())
            {
                TESBipedModelForm* model;
                entry = (TESForm*)((::BGSPerkEntry *)(new ((void *)(iter)) ::Vec3()));
                model = ::TESBipedModelForm::GetFormAsBipedModel(entry);
                if (!model)
                {
                    ::FUN_005b5e40();
                    list = 0;
                    break;
                }
                else
                    reinterpret_cast<::FUN_00480d50_shell *>((model))->FUN_00480d50(true);
                iter = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
            }
        }
    }
}

struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};
struct FUN_00474fc0_shell : BGSBipedModelList
{
    bool FUN_00474fc0(BaseFormComponent* apCompareFC);
};

extern int DAT_0101a4c4;

// Initialises the BaseFormComponent at pThis, installs the vtable from DAT_0101a4c4, calls FUN_008c6060, and returns pThis.
// @fnv 0x00474d10
void* __fastcall FUN_00474d10(void* pThis)
{
    ::FUN_00402d30((int *)(((BaseFormComponent*)pThis)));
    *(int**)pThis = &DAT_0101a4c4;
    reinterpret_cast<::FUN_008c6060_shell *>((pThis))->FUN_008c6060();
    return pThis;
}


struct FUN_00474d60_shell
{
    int _pad;
    TESForm* m_pForm;
    void __thiscall FUN_00474d60();
};

// @fnv 0x00474d60
void __thiscall FUN_00474d60_shell::FUN_00474d60()
{
    if (m_pForm)
    {
        unsigned int id = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pForm))->FUN_0084e3a0()));
        ::FUN_00485910(0x4c504942, id);
    }
}

struct FUN_00479350_shell
{
    void FUN_00479350();
};
// @fnv 0x00479350
void FUN_00479350_shell::FUN_00479350()
{
    unsigned int tempint;
    tempint = *(unsigned int*)((char*)this + 4);
    ::FUN_00485910(0x50595445, tempint);
}

extern int DAT_0101a4c4;

struct Date
{
    ~Date();
};

struct FUN_00474d40_shell : Date
{
    ~FUN_00474d40_shell();
};

// @fnv 0x00474d40
FUN_00474d40_shell::~FUN_00474d40_shell()
{
    *reinterpret_cast<int**>(this) = &DAT_0101a4c4;
}

// Returns true if apCompareFC is not a BGSBipedModelList or its GetNext differs from this GetNext, otherwise false.
// @fnv 0x00474fc0
bool FUN_00474fc0_shell::FUN_00474fc0(BaseFormComponent* apCompareFC)
{
    BGSBipedModelList* pcomp = dynamic_cast<BGSBipedModelList*>(apCompareFC);
    if (!pcomp)
        return true;
    if (((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<FUN_00474fc0_shell*>(pcomp)))->FUN_00726070())) != ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((this))->FUN_00726070())))
        return true;
    return false;
}

struct TESRaceForm
{
};

struct FUN_00474f70_shell : BaseFormComponent
{
    void FUN_00474f70(BaseFormComponent* apCopyFC);
};

// Passes the GetNext() value from apCopyFC to TESRaceForm::Initialize.
// @fnv 0x00474f70
void FUN_00474f70_shell::FUN_00474f70(BaseFormComponent* apCopyFC)
{
    BGSBipedModelList* pCopyFC = dynamic_cast<BGSBipedModelList*>(apCopyFC);
    if (!pCopyFC)
        return;
    reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)this)))->Initialize((::CombatController *)((unsigned int)((::BSSimpleList< ::BGSBipedModelList> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSBipedModelList>*)pCopyFC)))->FUN_00726070()))));
}
