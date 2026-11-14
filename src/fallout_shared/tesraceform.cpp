// fallout_shared/tesraceform.cpp: TESRaceForm, TESNPC, ActorValue, TESActorBase (5 functions)

#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0066e000.h"
#include "tesraceform_decls.h"

// Resolves the stored race form ID against the owner's file, looks up the TESRace, and warns if the race cannot be found.
// @fnv 0x0048b920
void TESRaceForm::InitItem(TESForm* owner)
{
    if (m_pRace)
    {
        unsigned int formID = (unsigned int)(std::uintptr_t)(m_pRace);
        ::ResolveFormID((unsigned int *)&(formID), owner->GetFile(-1));
        m_pRace = dynamic_cast<TESRace*>(::FUN_004839c0(formID));
        if (!m_pRace)
        {
            if (owner)
            {
                if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            else
            {
                ::FUN_005b5e40();
            }
        }
    }
}

// Returns a skill value from kData arrays (plus offset unless Unk_51), otherwise delegates to ActorValueOwner::GetActorValue.
// @fnv 0x00607850
int TESNPC::GetActorValue(ActorValue::Index actorValue)
{
    int value = 0;
    if (::FUN_0047f060((*(int *)&(actorValue))))
    {
        int skillIndex = static_cast<signed char>(ActorValue::ToArrayIndex(2, actorValue));
        value = kData.ucSkillValues[skillIndex];
        if (!Unk_51())
            value += kData.ucSkillOffsets[skillIndex];
    }
    else
    {
        value = ActorValueOwner::GetActorValue(actorValue);
    }
    return value;
}

// Casts component to TESRaceForm and, if successful, sets this form's race to the component's race.
// @fnv 0x0048b870
void TESRaceForm::BaseFormRecord(BaseFormComponent* component)
{
    TESRaceForm* raceForm = dynamic_cast<TESRaceForm*>(component);
    if (!raceForm)
        return;
    reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::TESRace *)(((::TESRace *)(reinterpret_cast<::Callees *>((void *)(raceForm))->FUN_00726070()))));
}

// Returns the actor value for the given ActorValue::Index converted to float.
// @fnv 0x005f7480
float TESActorBase::GetCurrentActorValue(ActorValue::Index actorValue)
{
    return static_cast<float>(GetActorValue(actorValue));
}

struct FUN_0048b8c0_shell : TESRaceForm
{
    bool IsEqualToBase(BaseFormComponent* apCompareFC);
};

// Returns true if apCompareFC is not a TESRaceForm or its race differs from this form's race; otherwise false.
// @fnv 0x0048b8c0
bool FUN_0048b8c0_shell::IsEqualToBase(BaseFormComponent* apCompareFC)
{
    TESRaceForm* pcompare = dynamic_cast<TESRaceForm*>(apCompareFC);
    if (!pcompare)
        return true;
    if (((::TESRace *)(reinterpret_cast<::Callees *>((void *)(this))->FUN_00726070())) != ((::TESRace *)(reinterpret_cast<::Callees *>((void *)(pcompare))->FUN_00726070())))
        return true;
    return false;
}
