// fallout_shared/tesenchantableform.cpp: TESEnchantableForm (7 functions)

#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "tesenchantableform_amount.h"
#include "tesenchantableform_decls.h"

// Resolves the form's enchantment by form ID, warns when it is missing or has an invalid effect trigger, and clears it on failure.
// @fnv 0x00483210
void TESEnchantableForm::InitItem(TESForm* owner)
{
    if (m_pEnchantment)
    {
        unsigned int formID = reinterpret_cast<unsigned int>(m_pEnchantment);
        if (owner)
            ::ResolveFormID((unsigned int *)&(formID), owner->GetFile(-1));

        m_pEnchantment = dynamic_cast<EnchantmentItem*>(::FUN_004839c0(formID));
        if (!m_pEnchantment)
        {
            if (owner)
            {
                if (reinterpret_cast<BGSCameraPath*>(owner)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            else
                ::FUN_005b5e40();
        }

        if (m_pEnchantment && owner && !m_pEnchantment->IsValidObject(owner))
        {
            ::FUN_005b5e40(
                );
            m_pEnchantment = 0;
        }
    }
}

// @fnv 0x00483170
void TESEnchantableForm::SetFormEnchantmentAmount(unsigned short amount)
{
    m_usEnchantmentAmount = amount;
}


struct FUN_0047bd70_shell
{
    void* vtable;
    TESForm* m_pEnchantment;
    unsigned short m_usEnchantmentAmount;
    void FUN_0047bd70();
};

// @fnv 0x0047bd70
void FUN_0047bd70_shell::FUN_0047bd70()
{
    unsigned int tempint;
    if (m_pEnchantment != 0)
    {
        tempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pEnchantment))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d544945, tempint);
    }
    if (m_usEnchantmentAmount != 0)
    {
        ::FUN_00485950((void *)(0x544d4145), m_usEnchantmentAmount);
    }
}

struct ExplosionEffectSettings;
struct BGSImpactData;
struct BGSImpactDataSet;
struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct QueuedFile;
struct TESBoundObject;
struct TESImageSpaceModifier;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectLIGH;
struct TESFormList;
struct TESObjectREFR;
struct TESSound;
struct FileEntryList;
struct TESWaterForm;
struct blob12
{
    char b[12];
};
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
struct BGSPreloadable : public BaseFormComponent
{
    virtual void QueueResourceLoad(int, QueuedFile*);
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESImageSpaceModifiableForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    void InitItem(TESForm*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    TESImageSpaceModifier* GetFormImageSpaceModifying();
    void SetFormImageSpaceModifying(TESImageSpaceModifier*);
    TESImageSpaceModifier* m_pImageSpaceModifier;
};
struct FUN_004830d0_shell : public TESEnchantableForm
{
    void FUN_004830d0();
};
// @fnv 0x004830a0
TESEnchantableForm::TESEnchantableForm()
{
    reinterpret_cast<::FUN_004830d0_shell *>(this)->FUN_004830d0();
}

// Clears the enchantment form's fields, setting the casting type to 4 and zeroing the other two members.
// @fnv 0x004830d0
void FUN_004830d0_shell::FUN_004830d0()
{
    m_pEnchantment = 0;
    m_usEnchantmentAmount = 0;
    m_eCastingType = (MagicSystemCastingType)4;
}

struct TESActorBaseData
{
    unsigned short GetFatigue() const;
};

struct TESFormList
{
};

struct FUN_00483190_shell : public TESEnchantableForm
{
    bool FUN_00483190(BaseFormComponent* component);
};

// Compares the enchantable form against component by first entry and fatigue, returning true when they differ or the cast fails.
// @fnv 0x00483190
bool FUN_00483190_shell::FUN_00483190(BaseFormComponent* component)
{
    TESEnchantableForm* other = dynamic_cast<TESEnchantableForm*>(component);
    if (!other)
        return true;
    if (reinterpret_cast<::Callees *>((reinterpret_cast<TESFormList*>(this)))->FUN_00726070() != reinterpret_cast<::Callees *>((reinterpret_cast<TESFormList*>(other)))->FUN_00726070())
        return true;
    if (reinterpret_cast<TESActorBaseData*>(this)->GetFatigue() !=
        reinterpret_cast<TESActorBaseData*>(other)->GetFatigue())
        return true;
    return false;
}

struct Enchantable_483100 : public TESEnchantableForm
{
    virtual int GetCastingType4();
    unsigned short GetFormEnchantmentAmount();
    void CopyEnchantmentFrom(BaseFormComponent* apComponent);
};

// Casts apComponent to TESEnchantableForm and copies its enchantment, enchantment amount and casting type onto this form.
// @fnv 0x00483100
void Enchantable_483100::CopyEnchantmentFrom(BaseFormComponent* apComponent)
{
    TESEnchantableForm* pForm = dynamic_cast<TESEnchantableForm*>(apComponent);
    if (!pForm)
        return;
    reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::EnchantmentItem *)(((::EnchantmentItem *)(reinterpret_cast<::Callees *>((((Enchantable_483100*)pForm)))->FUN_00726070()))));
    SetFormEnchantmentAmount(((Enchantable_483100*)pForm)->GetFormEnchantmentAmount());
    reinterpret_cast<::FUN_0041fd00_shell *>(this)->FUN_0041fd00(((Enchantable_483100*)pForm)->GetCastingType4());
}
