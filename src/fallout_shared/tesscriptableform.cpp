// fallout_shared/tesscriptableform.cpp: TESScriptableForm (6 functions)

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
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "tesscriptableform_decls.h"

// Resolves the stored script ID to a Script and warns if it cannot be found, then marks the item as initialized.
// @fnv 0x0048cd90
void TESScriptableForm::InitItem(TESForm* owner)
{
    if (m_bHasScript)
        return;
    if (m_pFormScript)
    {
        unsigned int scriptID = (unsigned int)m_pFormScript;
        ::ResolveFormID((unsigned int *)&(scriptID), owner->GetFile(-1));
        m_pFormScript = dynamic_cast<Script*>(::FUN_004839c0(scriptID));
        if (!m_pFormScript)
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
    m_bHasScript = true;
}

extern int DAT_0101d518;
void FUN_0048cc80(void* pThis);

// Initialises a BaseFormComponent: runs its base constructor, installs the vtable at DAT_0101d518, calls FUN_0048cc80, and returns pThis.
// @fnv 0x0048cc50
void* FUN_0048cc50(BaseFormComponent* apComponent)
{
    ::FUN_00402d30((int *)(apComponent));
    *(int**)apComponent = &DAT_0101d518;
    FUN_0048cc80(apComponent);
    return apComponent;
}

struct BGSMenuIcon;
struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct TESBoundObject;
struct TESIcon;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob12
{
    char b[12];
};
struct BGSMessageIcon : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    static void LoadMessageIcon(BGSMessageIcon*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    TESIcon* GetIcon();
    char* GetMessageIconTextureName();
    unsigned int GetMessageIconTextureNameLength();
    void SetMessageIconTextureName(char*);
    void* __vecDelDtor(unsigned int);
    char Icon[12];
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
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
struct FUN_0048cc80_shell : public BGSMessageIcon
{
    void FUN_0048cc80();
};

// @fnv 0x0048cc80
void FUN_0048cc80_shell::FUN_0048cc80()
{
    *(int*)((char*)this + 4) = 0;
    ((char*)this)[8] = 0;
}

struct S_0048cca0
{
    int field_0;
    TESForm* field_4;
    void FUN_0048cca0();
};
// @fnv 0x0048cca0
void S_0048cca0::FUN_0048cca0()
{
    if (field_4)
    {
        unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((field_4))->FUN_0084e3a0()));
        ::FUN_00485910(0x49524353, formID);
    }
}

namespace fnv_0048cce0 {
struct BGSMenuIcon;
struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct TESBoundObject;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
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
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
struct TESIcon : public TESTexture
{
    virtual char* GetTextureResourcePath();
    void* __vecDelDtor(unsigned int);
};
struct BGSMessageIcon : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    static void LoadMessageIcon(BGSMessageIcon*, TESFile*);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    TESIcon* GetIcon();
    char* GetMessageIconTextureName();
    unsigned int GetMessageIconTextureNameLength();
    void SetMessageIconTextureName(char*);
    void* __vecDelDtor(unsigned int);
    TESIcon Icon;
};
struct TESWeightForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static float GetWeightForForm(TESForm*, bool);
    float GetWeightForForm();
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
struct FUN_0048cce0_shell : public TESScriptableForm
{
    void CopyFromScriptableForm(BaseFormComponent*);
};

struct TESRaceForm
{
};
struct Ref00726070
{
};
// Casts apCopyFC to TESScriptableForm and, if successful, initializes this TESRaceForm from the copy's referenced form.
// @fnv 0x0048cce0
void FUN_0048cce0_shell::CopyFromScriptableForm(BaseFormComponent* apCopyFC)
{
    TESScriptableForm* pCopy = dynamic_cast<TESScriptableForm*>(apCopyFC);
    if (!pCopy)
        return;
    reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)this)))->Initialize((::CombatController *)(((unsigned int)(reinterpret_cast<::Callees *>((((Ref00726070*)pCopy)))->FUN_00726070()))));
}
}  // namespace fnv_0048cce0

struct Helper_00726070
{
};
struct Holder_0048cd30
{
    bool FUN_0048cd30(BaseFormComponent*);
};
// Casts a to TESScriptableForm and returns true if the cast fails or the two objects' _ref_00726070 values differ, false otherwise.
// @fnv 0x0048cd30
bool Holder_0048cd30::FUN_0048cd30(BaseFormComponent* apComponent)
{
    TESScriptableForm* b = dynamic_cast<TESScriptableForm*>(apComponent);
    if (!b)
        return true;
    if (((unsigned int)(reinterpret_cast<::Callees *>((reinterpret_cast<Helper_00726070*>(this)))->FUN_00726070())) !=
        ((unsigned int)(reinterpret_cast<::Callees *>((reinterpret_cast<Helper_00726070*>(b)))->FUN_00726070())))
        return true;
    return false;
}
