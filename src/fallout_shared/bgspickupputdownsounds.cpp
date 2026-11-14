// fallout_shared/bgspickupputdownsounds.cpp: TESIcon, BGSPickupPutdownSounds (8 functions)

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
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "bgspickupputdownsounds_decls.h"
#include "bgspickupputdownsounds_types_BGSPickupPutdownSounds.h"

// @fnv 0x00402c20
TESIcon::TESIcon() : TESTexture()
{}

// Resolves the pickup and putdown sound form IDs to TESSound objects, warning when either sound cannot be found.
// @fnv 0x0047b6a0
void BGSPickupPutdownSounds::InitItem(TESForm* owner)
{
    struct InitData
    {
        unsigned int formID;
        TESFile* file;
    } initData;

    initData.formID = (unsigned int)(std::uintptr_t)m_pPickupSound;
    initData.file = owner ? owner->GetFile(-1) : 0;

    if (initData.formID)
    {
        ::ResolveFormID((unsigned int *)&(initData.formID), initData.file);
        m_pPickupSound = dynamic_cast<TESSound*>(::FUN_004839c0(initData.formID));
        if (!m_pPickupSound)
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

    initData.formID = (unsigned int)(std::uintptr_t)m_pPutdownSound;
    if (initData.formID)
    {
        ::ResolveFormID((unsigned int *)&(initData.formID), initData.file);
        m_pPutdownSound = dynamic_cast<TESSound*>(::FUN_004839c0(initData.formID));
        if (!m_pPutdownSound)
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

extern int DAT_0101abd8;
void FUN_0047b540(void* pThis);

// Initialises the BaseFormComponent base, installs the vtable from DAT_0101abd8, calls FUN_0047b540, and returns pThis.
// @fnv 0x0047b4f0
void* FUN_0047b4f0(BaseFormComponent* apComponent)
{
    ::FUN_00402d30((int *)(apComponent));
    *(int**)apComponent = &DAT_0101abd8;
    FUN_0047b540(apComponent);
    return apComponent;
}

struct BGSMenuIcon;
struct BGSMessageIcon;
struct BGSTextureSet;
struct BipedAnim;
class NiAVObject;
struct NiPoint3;
class Script;
class TESBoundObject;
class TESModel;
class TESModelTextureSwap;
class TESObject;
struct TESFormList;
class TESObjectREFR;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob12
{
    char b[12];
};
struct BGSClipRoundsForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetClipRounds(TESForm*);
    int GetClipRounds();
    void SetFormClipRounds(int);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucClipRounds;
    char _pad_5[3];
};
class TESFullName : public BaseFormComponent
{
  public:
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
struct TESScriptableForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static Script* GetScriptForForm(TESForm*);
    Script* GetScriptForForm();
    static char* GetFormScriptEditorID(TESForm*);
    char* GetFormScriptEditorID();
    static void SetFormScript(TESForm*, Script*);
    void SetFormScript(Script*);
    Script* m_pFormScript;
    bool m_bHasScript;
    char _pad_9[3];
};
struct TESWeightForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static float GetWeightForForm(TESForm*, bool);
    void SetFormWeight(float);
    void* __vecDelDtor(unsigned int);
    float fWeight;
};
struct BGSEquipType : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetEquipType(TESForm*);
    int GetEquipType();
    void SetEquipType(int);
    static BGSMenuIcon* GetEquipTypeIcon(int);
    static char* GetEquipTypeName(int);
    static void GenerateDefaultMenuIcons();
    int m_eEquipType;
};
struct FUN_0047b540_shell : public BGSClipRoundsForm
{
    void FUN_0047b540();
};

// @fnv 0x0047b540
void FUN_0047b540_shell::FUN_0047b540()
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
}

class TESObjectREFR
{
};
struct TESRaceForm
{
};
struct ArrSI
{
};
struct CombatNode
{
};
struct FUN_0047b5d0_cls
{
    void FUN_0047b5d0(BaseFormComponent* component);
};
// If component casts to BGSPickupPutdownSounds, initializes this as TESRaceForm from its FUN_00726070 result and sets TESObjectREFR flags from its GetFlags.
// @fnv 0x0047b5d0
void FUN_0047b5d0_cls::FUN_0047b5d0(BaseFormComponent* component)
{
    BGSPickupPutdownSounds* source = dynamic_cast<BGSPickupPutdownSounds*>(component);
    if (!source)
        return;
    reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)this)))->Initialize((::CombatController *)(((std::uintptr_t)(reinterpret_cast<::Callees *>((((CombatNode*)source)))->FUN_00726070()))));
    reinterpret_cast<::TESRegionGrassObject *>((((TESObjectREFR*)this)))->AssignLandTexture((::TESLandTexture *)(((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)source)))->GetName()))));
}

namespace fnv_0047b560 {
struct ArrSI
{
};
struct ItemList
{
};
struct FUN_0047b560_shell : public TESForm
{
    void LogFormIDs();
};
// @fnv 0x0047b560
void FUN_0047b560_shell::LogFormIDs()
{
    if (reinterpret_cast<::Callees *>((((ItemList*)this)))->FUN_00726070())
    {
        unsigned int id = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)reinterpret_cast<::Callees *>((((ItemList*)this)))->FUN_00726070())))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e59, id);
    }
    if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName())))
    {
        unsigned int id = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)((std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)this)))->GetName())))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e5a, id);
    }
}
}  // namespace fnv_0047b560

namespace fnv_0047b630 {
struct ArrSI
{
};

struct FUN_0047b630_shell
{
    bool IsSamePickupPutdownSounds(BaseFormComponent* component);
};

// Casts component to BGSPickupPutdownSounds and returns false only if its FUN_00726070 result and GetFlags both match this object's.
// @fnv 0x0047b630
bool FUN_0047b630_shell::IsSamePickupPutdownSounds(BaseFormComponent* component)
{
    BGSPickupPutdownSounds* pickup = dynamic_cast<BGSPickupPutdownSounds*>(component);
    if (pickup == 0)
        return true;
    if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>(this)->FUN_00726070())) != ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((reinterpret_cast<FUN_0047b630_shell*>(pickup)))->FUN_00726070())) ||
        ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(this)))->GetName())) != ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(pickup)))->GetName())))
        return true;
    return false;
}
}  // namespace fnv_0047b630

extern int DAT_0101abd8;

struct FUN_0047b520_shell : TESForm
{
    void FUN_0047b520();
};

// @fnv 0x0047b520
void FUN_0047b520_shell::FUN_0047b520()
{
    *(int**)this = &DAT_0101abd8;
    TESForm::ClearData();
}
