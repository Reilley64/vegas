// fallout_shared/teshealthform.cpp: TESHealthForm, HealthComponentComparison (7 functions)

#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "teshealthform_decls.h"

static const int kInitializeDataComponentValue1 = 100;

// @fnv 0x00487220
void TESHealthForm::InitializeComponent()
{
    m_uiHealthValue = kInitializeDataComponentValue1;
}

// Returns the health of form if it is a TESHealthForm, otherwise returns 0.
// @fnv 0x004873d0
unsigned int TESHealthForm::GetBaseHealth(TESForm* form)
{
    TESHealthForm* health = ((::TESHealthForm *)(::GetHealthForm(form)));
    if (health)
        return health->GetHealth();
    else
        return 0;
}

extern int DAT_0101abd8;

// Initialises a BaseFormComponent: runs the base constructor, installs the vtable from DAT_0101abd8, calls FUN_0047b540, and returns pThis.
// @fnv 0x004871d0
void* FUN_004871d0(BaseFormComponent* pThis)
{
    ::FUN_00402d30((int *)(pThis));
    *(int**)pThis = &DAT_0101abd8;
    reinterpret_cast<::TESHealthForm *>((pThis))->InitializeComponent();
    return pThis;
}

struct FUN_00487200_shell : public TESHealthForm
{
    void FUN_00487200();
};

struct TESFile_Access
{
};

// @fnv 0x00487200
void FUN_00487200_shell::FUN_00487200()
{
    *reinterpret_cast<const char**>(this) = " rH";
    reinterpret_cast<::TESForm *>((reinterpret_cast<TESFile_Access*>(this)))->ClearData();
}

unsigned int _FNV_GetFormType(void* pForm);

struct TESHealthForm_Dummy
{
};

struct TESObjectWEAP_Dummy
{
    char pad[0x94];
};
struct TESObjectWEAP_Derived : TESObjectWEAP_Dummy, TESHealthForm_Dummy
{
};

struct TESObjectARMO_Dummy
{
    char pad[0x68];
};
struct TESObjectARMO_Derived : TESObjectARMO_Dummy, TESHealthForm_Dummy
{
};

struct TESActorBase_Dummy
{
    char pad[0xb0];
};
struct TESActorBase_Derived : TESActorBase_Dummy, TESHealthForm_Dummy
{
};

// Returns apForm cast to TESHealthForm_Dummy if its form type is weapon, armor, or actor base, otherwise null.
// @fnv 0x004872e0
TESHealthForm_Dummy* __cdecl GetHealthForm(TESForm* apForm)
{
    TESHealthForm_Dummy* pHealthForm = 0;
    if (apForm)
    {
        switch (_FNV_GetFormType(apForm))
        {
        case 0x28: {
            TESObjectWEAP_Derived* pform = reinterpret_cast<TESObjectWEAP_Derived*>(apForm);
            pHealthForm = pform;
            break;
        }
        case 0x18: {
            TESObjectARMO_Derived* pform = reinterpret_cast<TESObjectARMO_Derived*>(apForm);
            pHealthForm = pform;
            break;
        }
        case 0x2a:
        case 0x2b: {
            TESActorBase_Derived* pform = reinterpret_cast<TESActorBase_Derived*>(apForm);
            pHealthForm = pform;
            break;
        }
        }
    }
    return pHealthForm;
}

struct PackedRecordData;
class Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
class ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct MagicItemForm;
class NiAVObject;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
class TESActorBase;
struct TESActorBaseData;
struct TESAmmo;
class TESBoundObject;
class TESContainer;
struct TESFaction;
class TESForm;
struct TESLevItem;
struct TESLevSpell;
class TESObject;
class TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
class TESObjectREFR;
class TESObjectWEAP;
class TESPackage;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00487240_shell : public TESHealthForm
{
    void CopyHealthForm(BaseFormComponent*);
};

struct TESRaceForm
{
};
// @fnv 0x00487240
void FUN_00487240_shell::CopyHealthForm(BaseFormComponent* apCopyFC)
{
    TESHealthForm* pCopy = dynamic_cast<TESHealthForm*>(apCopyFC);
    if (!pCopy)
        return;
    reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)this)))->Initialize((::CombatController *)(pCopy->m_uiHealthValue));
}

class HealthComponentComparison : public TESHealthForm
{
  public:
    bool FUN_00487290(BaseFormComponent* component);
};

// Returns true if the given component is not a TESHealthForm or its health value differs from this form's health value.
// @fnv 0x00487290
bool HealthComponentComparison::FUN_00487290(BaseFormComponent* component)
{
    TESHealthForm* casted = dynamic_cast<TESHealthForm*>(component);
    if (!casted)
        return true;
    if (m_uiHealthValue != casted->m_uiHealthValue)
        return true;
    return false;
}
