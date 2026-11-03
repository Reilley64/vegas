// fallout_shared/tesimagespacemodifiableform.cpp: TESImageSpaceModifiableForm (5 functions)

#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008c6060_shell.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "tesimagespacemodifiableform_decls.h"

// Resolves the stored form ID to a TESImageSpaceModifier via the owner's file and warns if it cannot be found.
// @fnv 0x00487490
void TESImageSpaceModifiableForm::InitItem(TESForm* owner)
{
    if (m_pImageSpaceModifier)
    {
        unsigned int formID = (unsigned int)m_pImageSpaceModifier;
        if (owner)
            ::ResolveFormID((unsigned int *)&(formID), owner->GetFile(-1));
        m_pImageSpaceModifier = dynamic_cast<TESImageSpaceModifier*>(::FUN_004839c0(formID));
        if (!m_pImageSpaceModifier)
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
    }
}

struct BaseFormComponent
{
    virtual ~BaseFormComponent()
    {}
};
struct FUN_004875c0_shell : BaseFormComponent
{
    bool FUN_004875c0(BaseFormComponent* apCompareFC);
};

extern int DAT_0101cbd8;

// Initialises the BaseFormComponent base, installs the vtable from DAT_0101cbd8, calls FUN_008c6060, and returns pThis.
// @fnv 0x00487420
void* FUN_00487420(void* pThis)
{
    ::FUN_00402d30((int *)(((BaseFormComponent*)pThis)));
    *(int**)pThis = &DAT_0101cbd8;
    reinterpret_cast<::FUN_008c6060_shell *>((pThis))->FUN_008c6060();
    return pThis;
}


struct FUN_00487450_shell
{
    int m_auiShapeKeys;
    TESForm* m_field_4;
    void FUN_00487450();
};

// @fnv 0x00487450
void FUN_00487450_shell::FUN_00487450()
{
    if (m_field_4)
    {
        unsigned int id = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_field_4))->FUN_0084e3a0()));
        ::FUN_00485910(0x4D414E4D, id);
    }
}

extern int DAT_01186ae8;

class SpawnedHelper
{
  public:
};

class FUN_00487570_cls
{
  public:
    void FUN_00487570(unsigned int a1);
};

// @fnv 0x00487570
void FUN_00487570_cls::FUN_00487570(unsigned int a1)
{
    SpawnedHelper* pHelper =
        (SpawnedHelper*)dynamic_cast<::TESImageSpaceModifiableForm *>(reinterpret_cast<::BaseFormComponent *>(a1));
    if (pHelper == 0)
    {
    }
    else
    {
        reinterpret_cast<::CombatProcedure *>((this))->Initialize((::CombatController *)(void *)(reinterpret_cast<::Callees *>((pHelper))->FUN_00726070()));
    }
}

// Returns true if the cast fails or the two calls to _ref_00726070() return different values.
// @fnv 0x004875c0
bool FUN_004875c0_shell::FUN_004875c0(BaseFormComponent* apCompareFC)
{
    TESImageSpaceModifiableForm* pCompareImageSpaceForm = dynamic_cast<TESImageSpaceModifiableForm*>(apCompareFC);
    if (!pCompareImageSpaceForm)
        return true;
    if (((int)(reinterpret_cast<::Callees *>((this))->FUN_00726070())) != ((int)(reinterpret_cast<::Callees *>((reinterpret_cast<BaseFormComponent*>(pCompareImageSpaceForm)))->FUN_00726070())))
        return true;
    return false;
}
