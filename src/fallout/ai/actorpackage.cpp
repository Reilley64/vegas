
// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/actorpackage.cpp
//
// ActorPackageData. The package reference is refcounted through AddRef and
// Release; runtime-created packages are destroyed once the last reference
// goes away. PTYPE enumerators match guardpackage.h.

// ---- Minimal local declarations: layout-relevant members only ----

// The original TU reached NULL through the game core headers; this
// standalone reconstruction defines it directly.
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_005277d0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00857bd0.h"
#include "fnv/decl/FUN_0085a290_t.h"
#include "fnv/decl/FUN_0085a2e0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008c6920_shell.h"
#include "fnv/decl/FakeGame.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_006777b0__FUN_006777b0_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00670000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_0096a000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#define NULL 0

typedef enum
{
    PTYPE_NONE = -1,
    PTYPE_EXPLORE = 0,
    PTYPE_FOLLOW,
    PTYPE_ESCORT,
    PTYPE_EAT,
    PTYPE_SLEEP,
    PTYPE_WANDER,
    PTYPE_TRAVEL,
    PTYPE_ACCOMPANY,
    PTYPE_USEITEMAT,
    PTYPE_AMBUSH,
    PTYPE_FLEE_NON_COMBAT,
    PTYPE_CAST_MAGIC,
    PTYPE_SANDBOX,
    PTYPE_PATROL,
    PTYPE_GUARD,
    PTYPE_DIALOGUE,
    PTYPE_USEWEAPON,
    PTYPE_FIND,
    PTYPE_COMBAT,
    PTYPE_COMBAT_LOW,
    PTYPE_ACTIVATE,
    PTYPE_ALARM,
    PTYPE_FLEE,
    PTYPE_TRESPASS,
    PTYPE_SPECTATOR,
    PTYPE_GREET,
    PTYPE_GET_UP,
    PTYPE_DO_NOTHING,
    PTYPE_IN_GAME_DIALOGUE,
    PTYPE_SURFACE,
    PTYPE_SEARCH_FOR_ATTACKER,
    PTYPE_AVOID_RADIATION,
    PTYPE_EXPLOSION_REACTION,
    PTYPE_GRENDADE_MINE_REACTION,
    PTYPE_STEAL_WARNING,
    PTYPE_PICKPOCKET_WARNING,
    PTYPE_MOVEMENT_BLOCKED,
    PTYPE_SANDMAN,
    PTYPE_CANNIBAL,
    PTYPE_BACK_UP,
    PTYPE_COUNT
} PTYPE;

class TESObjectREFR
{
};

class Actor : public TESObjectREFR
{
};

class TESFile;
template <class T> class BSStringT;
class BGSSaveFormBuffer;

class BGSLoadFormBuffer
{
  public:
};

class BaseFormComponent
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* apOther);
    virtual bool CompareWithBase(BaseFormComponent* apOther);
};

class TESForm : public BaseFormComponent
{
  public:
    virtual ~TESForm();
    virtual void InitializeComponent();
    virtual void ClearData();
    virtual bool Unk_07();
    virtual bool LoadForm(TESFile* apFile);
    virtual bool Unk_09(void* apArg);
    virtual bool AppendForm(TESFile* apFile);
    virtual void SaveForm();
    virtual bool LoadForm2(TESFile* apFile);
    virtual void WriteFormInfo(TESFile* apFile);
    virtual bool Unk_0E(void* apArg);
    virtual bool Sort(TESForm* apForm);
    virtual TESForm* CreateForm(void* apArg0, void* apMapToAddTo);
    virtual void Unk_11(void* apArg);
    virtual void MarkAsModified(unsigned int auiFlags);
    virtual void MarkAsUnmodified(unsigned int auiFlags);
    virtual unsigned int GetSaveSize(unsigned int auiVersion);
    virtual void Unk_15(void* apArg);
    virtual void SaveGame(unsigned int auiVersion);
    virtual void LoadGame(void* apArg);
    virtual void LoadGame2(unsigned int auiVersion);
    virtual void Unk_19(void* apArg);
    virtual void Unk_1A();
    virtual void Unk_1B(void* apArg0, void* apArg1);
    virtual void Revert(unsigned int auiVersion);
    virtual void Unk_1D(void* apArg);
    virtual void Unk_1E(void* apArg);
    virtual bool Unk_1F(void* apArg);
    virtual void Unk_20(void* apArg);
    virtual void Unk_21(void* apArg);
    virtual void InitItem();
    virtual unsigned int GetTypeID();
    virtual void GetDebugName(BSStringT<char>* apDst);
    virtual bool IsQuestItem();
    virtual bool Unk_26();
    virtual bool Unk_27();
    virtual bool Unk_28();
    virtual bool Unk_29(bool abSet);
    virtual bool Unk_2A(bool abSet);
    virtual bool Unk_2B();
    virtual bool Unk_2C();
    virtual bool Unk_2D();
    virtual bool Unk_2E();
    virtual void Unk_2F(bool abSet);
    virtual bool Unk_30();
    virtual void MarkForDeletion(bool abSet);
    virtual void SetAltered(bool abSet);
    virtual void SetQuestItem(bool abSet);
    virtual void Unk_34(bool abSet);
    virtual void Unk_35(bool abSet);
    virtual void Unk_36(bool abSet);
    virtual void Unk_37();
    virtual void readOBNDSubRecord(TESFile* apFile);
    virtual bool IsActor_InEditor();
    virtual bool IsBoundObject();
    virtual bool Unk_3B();
    virtual bool GetIsReference() const;
    virtual bool Unk_3D();
    virtual bool Unk_3E();
    virtual bool IsMobileObject() const;
    virtual bool IsActor();
    virtual unsigned int Unk_41();
    virtual void CopyFrom(const TESForm* apForm);
    virtual bool Compare(TESForm* apForm);
    virtual bool CheckFormGRUP(void* apArg);
    virtual void InitFormGRUP(void* apDst, void* apArg1);
    virtual bool Unk_46();
    virtual bool Unk_47();
    virtual bool Unk_48(unsigned int aeFormType);
    virtual bool Unk_49(void* apArg0, void* apArg1, void* apArg2, void* apArg3, void* apArg4);
    virtual void SetRefID(unsigned int auiRefID, bool abGenerateID);
    virtual char* GetName2();
    virtual char* GetName() const;
};

class TESPackage : public TESForm
{
  public:
    bool IsMustComplete();
    PTYPE GetPackType();
};

class BGSSaveLoadGame
{
  public:
};

class TESSaveLoadGame
{
  public:
};

class TESDataHandler
{
  public:
};

class PlayerCharacter
{
  public:
    unsigned char m_padding208[0x208];
    TESPackage* pCurrentPackage;
};

class Calendar
{
  public:
    float GetGameTime();
};

class ActorPackageData
{
  public:
    virtual ~ActorPackageData();
    virtual void SetReferenceTarget(TESObjectREFR* apReference);
    virtual PTYPE GetPackageType();
    virtual void SaveGame(BGSSaveFormBuffer* apBuffer);
    virtual void LoadGame(BGSLoadFormBuffer* apBuffer);
    virtual void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    static ActorPackageData* CreatePackageData(PTYPE aeType);
};

typedef enum
{
    GUARD_STATE_INIT = 0,
    GUARD_STATE_IDLE = 1,
    GUARD_STATE_WAIT_TO_ATTACK = 2
} GUARD_STATE;

class GuardActorPackageData : public ActorPackageData
{
  public:
    GUARD_STATE eState;     // +0x4
    Actor* pWarningTarget;  // +0x8
    int iWarningCount;      // +0xC
    float m_fWarningTimer;  // +0x10
    virtual void SetReferenceTarget(TESObjectREFR* apReference);
};

class ActorPackageContext
{
  public:
    TESPackage* pPackage;     // +0x0
    ActorPackageData* pData;  // +0x4
    TESObjectREFR* pTarget;   // +0x8
    int m_iPackageValue;      // +0xC
    float m_fPackageValue;    // +0x10
    unsigned int iFlags;      // +0x14
    void Clear();
    void SetPackageAndTarget(TESPackage* apPackage, TESObjectREFR* apTarget);
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer);
};


static const char s_kPackageTypeChangedWarning[] =
    "Package '%s' (%08X) changed type from %s to %s, so the actor package data was replaced";

// Clears the stored actor reference if it matches the passed reference.
// @fnv 0x008c5ec0
void GuardActorPackageData::SetReferenceTarget(TESObjectREFR* apReference)
{
    if (apReference == pWarningTarget)
        pWarningTarget = NULL;
}

// Reads a package form ID, package type and package data from the buffer, then reads flags and target, creating the package if needed.
// @fnv 0x008c6730
void ActorPackageContext::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    unsigned int iFormID = 0;
    bool bResult = reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apBuffer))->FUN_008648e0((unsigned int *)(void *)(&iFormID));
    bool bCreated;
    if (iFormID || bResult)
    {
        char cDataType;
        bCreated = false;
        if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(iFormID))
        {
            char cPackageType = 0;
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&cPackageType), 1);
            if (cPackageType != -1)
            {
                pPackage = ::CreatePackageByType((*(int *)&(const ::PTYPE &)((PTYPE)cPackageType)));
                reinterpret_cast<::FakeGame *>((::g_BGSSaveLoadGame))->SetFormIDMapping(iFormID, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pPackage))->FUN_0084e3a0())));
                pPackage->LoadGame(apBuffer);
            }
            else
            {
                pPackage = (TESPackage*)iFormID;
                bCreated = true;
            }
        }
        else
        {
            pPackage = iFormID ? dynamic_cast<TESPackage*>(::FUN_004839c0(iFormID)) : NULL;
        }
        cDataType = -1;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&cDataType), 1);
        if (cDataType != -1)
        {
            pData = ActorPackageData::CreatePackageData((PTYPE)cDataType);
            pData->LoadGame(apBuffer);
        }
        else
        {
            delete pData;
            pData = NULL;
        }
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_iPackageValue), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fPackageValue), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iFlags), 4);
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apBuffer))->FUN_008648e0((unsigned int *)(void *)(&pTarget));
        if (bCreated)
            reinterpret_cast<::FUN_008c6920_shell *>(this)->SetFlag(0, true);
    }
    if (bResult)
        Clear();
}

#include "actorpackage_getters.h"

// @fnv 0x004fd3e0
TESSound* EffectSetting::GetHitSound()
{
    return hitSound;
}

extern int DAT_01031fac;

struct FUN_00527770_arg
{
    unsigned int val;
};


// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00527770
int* FUN_00527770(int* self, FUN_00527770_arg a)
{
    reinterpret_cast<::FUN_005277d0_Class *>((self))->InitBuffer((*(unsigned int *)&(const ::FUN_00527770_arg &)(a)));
    *self = (int)&DAT_01031fac;
    return self;
}

struct FUN_008c5e70_shell : public ActorPackageContext
{
    void DeleteData();
};

// Deletes pData if it is non-null.
// @fnv 0x008c5e70
void FUN_008c5e70_shell::DeleteData()
{
    if (pData)
        delete pData;
}

struct FUN_008c6030_shell : public TESPackage
{
    unsigned int FUN_008c6030();
};
// @fnv 0x008c5ef0
void ActorPackageContext::Clear()
{
    if (pPackage)
    {
        if (pPackage == ::_g_thePlayer->pCurrentPackage)
            ::_g_thePlayer->pCurrentPackage = NULL;
        if (!((int)(reinterpret_cast<::FUN_008c6030_shell *>((pPackage))->FUN_008c6030())) && pPackage->IsMustComplete())
        {
            TESPackage* pOldPackage = pPackage;
            pPackage = NULL;
            if (reinterpret_cast<::FUN_0047c850 *>((::g_TESSaveLoadGame))->EvaluateCondition())
                reinterpret_cast<::FUN_0085a2e0_Class *>((::g_TESSaveLoadGame))->FUN_0085a2e0(pOldPackage);
            else
                delete pOldPackage;
        }
        else
        {
            pPackage = NULL;
        }
    }
    if (pData)
    {
        delete pData;
        pData = NULL;
    }
    m_fPackageValue = -1.0F;
    m_iPackageValue = -1;
    iFlags = 0;
    pTarget = NULL;
}


// @fnv 0x008c6030
unsigned int FUN_008c6030_shell::FUN_008c6030()
{
    unsigned int newRefCount = ((unsigned int)(::WaitForSingleObjectEx((long *)(void *)((char*)this + 0x7c))));
    return newRefCount;
}

struct FUN_008c6100_shell : public TESPackage
{
    unsigned int FUN_008c6100();
};
// @fnv 0x008c6080
void ActorPackageContext::SetPackageAndTarget(TESPackage* apPackage, TESObjectREFR* apTarget)
{
    if (apPackage == pPackage)
        return;
    Clear();
    if (apPackage)
    {
        reinterpret_cast<::FUN_008c6100_shell *>((apPackage))->FUN_008c6100();
        m_fPackageValue = (*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetGameTime();
        pPackage = apPackage;
        pData = ActorPackageData::CreatePackageData(apPackage->GetPackType());
        m_iPackageValue = 0;
        pTarget = apTarget;
    }
}

unsigned int __cdecl InitScriptRunLock(void*);

// Calls InitScriptRunLock on the object at offset 0x7c and returns its result.
// @fnv 0x008c6100
unsigned int FUN_008c6100_shell::FUN_008c6100()
{
    unsigned int newRefCount = InitScriptRunLock((char*)this + 0x7c);
    return newRefCount;
}

struct FUN_008c6130_shell : public ActorPackageContext
{
    void MovePackageData(ActorPackageContext*);
};

// @fnv 0x008c6130
void FUN_008c6130_shell::MovePackageData(ActorPackageContext* apDestPackageInstance)
{
    apDestPackageInstance->pPackage = pPackage;
    apDestPackageInstance->pData = pData;
    apDestPackageInstance->m_iPackageValue = m_iPackageValue;
    apDestPackageInstance->m_fPackageValue = m_fPackageValue;
    pPackage = NULL;
    pData = NULL;
    m_iPackageValue = -1;
    m_fPackageValue = -1.0f;
}

struct FUN_008c6b00_shell : public ActorPackageContext
{
    bool FUN_008c6b00(int);
};
// @fnv 0x008c6b20
void ActorPackageContext::ApplyLoadBuffer(BGSLoadFormBuffer* apBuffer)
{
    if (reinterpret_cast<::FUN_008c6b00_shell *>(this)->FUN_008c6b00(0))
        reinterpret_cast<::FUN_008c6920_shell *>(this)->SetFlag(0, false);
    else if (pPackage && reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pPackage))->FUN_0084e3a0()))))
        pPackage->Unk_21(apBuffer);
    if (pData && pPackage)
    {
        if (pPackage->GetPackType() != pData->GetPackageType())
        {
            ::FUN_00845cc0(s_kPackageTypeChangedWarning, pPackage->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pPackage))->FUN_0084e3a0())),
                       g_packageTypeNames[pData->GetPackageType()], g_packageTypeNames[pPackage->GetPackType()]);
            delete pData;
            pData = ActorPackageData::CreatePackageData(pPackage->GetPackType());
        }
    }
}

// Returns true if the bit for aeFlag is set in the 32-bit flags field at offset 0x14 of this object.
// @fnv 0x008c6b00
bool FUN_008c6b00_shell::FUN_008c6b00(int aeFlag)
{
    return ((1 << aeFlag) & *(unsigned int*)((char*)this + 0x14)) ? true : false;
}

struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESFile;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
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
struct FUN_008c6060_shell : public BGSClipRoundsForm
{
    void FUN_008c6060();
};

// @fnv 0x008c6060
void FUN_008c6060_shell::FUN_008c6060()
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 4) = 0;
}

struct FUN_008c65a0_shell
{
    void* pPackage;
    void FUN_008c65a0(int aiFlags);
};
// @fnv 0x008c65a0
void FUN_008c65a0_shell::FUN_008c65a0(int aiFlags)
{
    if ((aiFlags & 0) && pPackage)
        ((ActorPackageContext*)this)->Clear();
}

struct DataHandler
{
};

struct TESObjectREFRHelper
{
};

struct FUN_0084aa90_shell
{
    unsigned int FUN_0084aa90(unsigned int auiFormID);
};

struct FUN_009611e0_shell
{
    int FUN_009611e0();
};

struct FUN_006777b0_shell
{
};


struct FUN_008c6970_shell : public ActorPackageContext
{
    void FUN_008c6970(BGSLoadFormBuffer* apBuffer);
};

// @fnv 0x008c6970
void FUN_008c6970_shell::FUN_008c6970(BGSLoadFormBuffer* apBuffer)
{
    if (reinterpret_cast<::FUN_008c6b00_shell *>(this)->FUN_008c6b00(0))
    {
        unsigned int uiPackageFormID = ((FUN_0084aa90_shell*)::g_BGSSaveLoadGame)->FUN_0084aa90((unsigned int)pPackage);
        pPackage = uiPackageFormID ? dynamic_cast<TESPackage*>(::FUN_004839c0(uiPackageFormID)) : 0;
    }
    else if (pPackage && reinterpret_cast<::BSShaderRenderUtility *>((((DataHandler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pPackage))->FUN_0084e3a0()))))
    {
        pPackage->Unk_19(apBuffer);
    }
    if (pPackage)
    {
        if (((FUN_009611e0_shell*)pPackage)->FUN_009611e0() == -1)
            reinterpret_cast<::fnv_006777b0::FUN_006777b0_shell *>((((FUN_006777b0_shell*)pPackage)))->ComputePackageFlags(0);
        reinterpret_cast<::FUN_008c6100_shell *>((pPackage))->FUN_008c6100();
        int iCount = FUN_0096a820(((FUN_009611e0_shell*)pPackage)->FUN_009611e0());
        if (m_iPackageValue >= iCount)
            m_iPackageValue = iCount - 1;
    }
    if (pData)
        pData->InitLoadGame(apBuffer);
    pTarget = pTarget ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)pTarget)) : 0;
    if (pTarget)
        reinterpret_cast<::fnv_00564db0::FUN_00564db0_cls *>((((TESObjectREFRHelper*)pTarget)))->FUN_00564db0(true);
}

struct NvGate
{
};
struct NvInner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual unsigned short v83();
};
struct NvOuter
{
    NvInner* m_pInner;
    unsigned short ComputeTotal(int aiFlags);
};
// @fnv 0x008c61a0
unsigned short NvOuter::ComputeTotal(int aiFlags)
{
    int total = 0;
    total += 4;
    if (m_pInner != 0)
    {
        unsigned int uiValue = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pInner))->FUN_0084e3a0()));
        if ((aiFlags & 0) != 0)
        {
            if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::NvGate * *>(&::g_dataHandler))))->IsRenderTargetId(uiValue))
            {
                bool b = ((bool)(reinterpret_cast<struct ::FUN_0041ca90 *>((m_pInner))->get()));
                total += 1;
                if ((aiFlags & 0) == 0)
                {
                    total += m_pInner->v83();
                }
            }
        }
        total += 4;
    }
    total += 4;
    return (unsigned short)total;
}

class BGSSaveFormBuffer
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual int GetVersion();
};

struct TESPackageEx : public TESPackage
{
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual bool IsDataValidForVersion(int aiVersion);
};

struct ActorPackageSaver : public ActorPackageContext
{
    void SavePackage(BGSSaveFormBuffer* apBuffer);
};

// Saves the package's type, data, flags and target to the buffer, writing -1 for the type when the package data is invalid for the buffer version.
// @fnv 0x008c65d0
void ActorPackageSaver::SavePackage(BGSSaveFormBuffer* apBuffer)
{
    int iVersion = apBuffer->GetVersion();
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pPackage), 0);
    if (pPackage)
    {
        if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pPackage))->FUN_0084e3a0()))))
        {
            char cType = pPackage->GetPackType();
            if (!((TESPackageEx*)pPackage)->IsDataValidForVersion(iVersion))
                cType = -1;
            reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&cType, 1, 0);
            if (cType != -1)
                pPackage->Unk_15(apBuffer);
        }
        char cDataType = pData ? pData->GetPackageType() : -1;
        reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&cDataType, 1, 0);
        if (cDataType != -1)
            pData->SaveGame(apBuffer);
        reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&m_iPackageValue, 4, 0);
        reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&m_fPackageValue, 4, 0);
        reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&iFlags, 4, 0);
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pTarget), 0);
    }
}

class TESForm;
class TESPackage;
struct Manager
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0a();
    virtual void slot0b();
    virtual void slot0c();
    virtual void slot0d();
    virtual void slot0e();
    virtual void slot0f();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1a();
    virtual void slot1b();
    virtual void slot1c();
    virtual void slot1d();
    virtual void slot1e();
    virtual void slot1f();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot2a();
    virtual void slot2b();
    virtual void slot2c();
    virtual void slot2d();
    virtual void slot2e();
    virtual void slot2f();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot3a();
    virtual void slot3b();
    virtual void slot3c();
    virtual void slot3d();
    virtual void slot3e();
    virtual void slot3f();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot4a();
    virtual void slot4b();
    virtual void slot4c();
    virtual void slot4d();
    virtual void slot4e();
    virtual void slot4f();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void dispatch();
};
struct Handler
{
};
struct Owner
{
    Manager* manager;
    int unk04, unk08, interval;
    void FUN_008c64d0(unsigned, unsigned);
};
// @fnv 0x008c64d0
void Owner::FUN_008c64d0(unsigned a, unsigned auiUnused)
{
    if (manager)
    {
        if (a & 0)
        {
            if (a & 0)
            {
                Manager* pManager = manager;
                reinterpret_cast<::ActorPackageContext *>(this)->SetPackageAndTarget(dynamic_cast<TESPackage*>(FUN_004839c0((unsigned)pManager)), (::TESObjectREFR *)(0));
            }
            else
            {
                if (reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::Handler * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((manager))->FUN_0084e3a0()))))
                    manager->dispatch();
            }
        }
        if (manager)
        {
            int elapsed = FUN_0096a820(reinterpret_cast<::FUN_009611e0_shell *>((manager))->FUN_009611e0());
            if (interval >= elapsed)
                interval = elapsed - 1;
        }
    }
}

struct PackageSaveWriter
{
};

struct PackageVirtuals : public TESPackage
{
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
};
struct ActorPackageLegacySave : public ActorPackageContext
{
    void FUN_008c6250(unsigned int auiFlags);
};
// Writes the package form ID, writes m_iPackageValue when the ID is nonzero, and always writes m_fPackageValue.
// @fnv 0x008c6250
void ActorPackageLegacySave::FUN_008c6250(unsigned int auiFlags)
{
    unsigned int auiFormId = 0;
    if (pPackage != NULL)
    {
        auiFormId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pPackage))->FUN_0084e3a0()));
    }
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::PackageSaveWriter * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&auiFormId), 4);
    if (auiFormId != 0)
    {
        if ((auiFlags & 0) != 0 && reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(auiFormId))
        {
            unsigned char ucType = pPackage->GetPackType();
            reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::PackageSaveWriter * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&ucType, 1);
            if ((auiFlags & 0) == 0)
            {
                static_cast<PackageVirtuals*>(pPackage)->Unk_54();
            }
        }
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::PackageSaveWriter * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&m_iPackageValue, 4);
    }
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::PackageSaveWriter * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&m_fPackageValue, 4);
}


struct LoadedPackage : public TESPackage
{
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void InitAfterLoad();
};

struct SaveLoadStub
{
};


struct ActorPackageLoad : public ActorPackageContext
{
    void FUN_008c6320(int aiFlags, int aiUnused);
};

// @fnv 0x008c6320
void ActorPackageLoad::FUN_008c6320(int aiFlags, int aiUnused)
{
    unsigned int auiFormId;
    bool bRead = reinterpret_cast<::FUN_00857aa0 *>((((SaveLoadStub*)::g_TESSaveLoadGame)))->ValidateFormIDArray(&auiFormId, 4);
    Clear();
    bool bFailed = false;
    if (auiFormId)
    {
        if ((aiFlags & 0) && reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->IsRenderTargetId(auiFormId))
        {
            unsigned char ucType;
            reinterpret_cast<::FUN_008579e0_shell *>((((SaveLoadStub*)::g_TESSaveLoadGame)))->FUN_008579e0(&ucType, 1);
            if (!(aiFlags & 0))
            {
                LoadedPackage* pNew = ((::LoadedPackage *)(reinterpret_cast<::FUN_0085a290_t *>((((SaveLoadStub*)::g_TESSaveLoadGame)))->FUN_0085a240(auiFormId, ucType)));
                pNew->InitAfterLoad();
                SetPackageAndTarget(pNew, 0);
                if (reinterpret_cast<::FUN_009611e0_shell *>((pNew))->FUN_009611e0() == -1)
                {
                    reinterpret_cast<::fnv_006777b0::FUN_006777b0_shell *>((pNew))->ComputePackageFlags(pTarget);
                }
            }
            else
            {
                SetPackageAndTarget((TESPackage*)auiFormId, 0);
            }
        }
        else
        {
            SetPackageAndTarget(dynamic_cast<TESPackage*>(::FUN_004839c0(auiFormId)), 0);
            if (pPackage)
            {
                reinterpret_cast<::fnv_006777b0::FUN_006777b0_shell *>((((LoadedPackage*)pPackage)))->ComputePackageFlags(pTarget);
            }
            else
            {
                bFailed = true;
            }
        }
        reinterpret_cast<::FUN_008579e0_shell *>((((SaveLoadStub*)::g_TESSaveLoadGame)))->FUN_008579e0(&m_iPackageValue, 4);
    }
    else if (bRead)
    {
        reinterpret_cast<::FUN_00857bd0 *>((((SaveLoadStub*)::g_TESSaveLoadGame)))->Init(4);
        reinterpret_cast<::FUN_0041fd00_shell *>(this)->FUN_0041fd00(0);
        bFailed = true;
    }
    if (bFailed)
    {
        if (auiFormId)
        {
            ::FUN_005b5e40();
        }
        else
        {
            ::FUN_005b5e40();
        }
        reinterpret_cast<::FUN_0041fd00_shell *>(this)->FUN_0041fd00(-1);
    }
    reinterpret_cast<::FUN_008579e0_shell *>((((SaveLoadStub*)::g_TESSaveLoadGame)))->FUN_008579e0(&m_fPackageValue, 4);
}
