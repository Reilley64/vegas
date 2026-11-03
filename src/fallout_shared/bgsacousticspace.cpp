// fallout_shared/bgsacousticspace.cpp: BGSAcousticSpace (12 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_0040e500_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004d6170_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0050e9f0_shell.h"
#include "fnv/decl/FUN_0068a810_class.h"
#include "fnv/decl/FUN_0068a830_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0058a000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_009e3000.h"
#include "bgsacousticspace.h"
#include <malloc.h>

static const char s_kAcousticDawnSoundWarning[] =
    "MASTERFILE: Could not find pDawnSound (%08X) for activator '%s' (%08X).";
static const char s_kAcousticNoonSoundWarning[] =
    "MASTERFILE: Could not find pNoonSound (%08X) for activator '%s' (%08X).";
static const char s_kAcousticDuskSoundWarning[] =
    "MASTERFILE: Could not find pDuskSound (%08X) for activator '%s' (%08X).";
static const char s_kAcousticNightSoundWarning[] =
    "MASTERFILE: Could not find pNightSound (%08X) for activator '%s' (%08X).";
static const char s_kAcousticRegionWarning[] =
    "MASTERFILE: Could not find sound region (%08X) for activator '%s' (%08X).";
static const char s_kAcousticWallaSoundWarning[] =
    "MASTERFILE: Could not find pWallaSound (%08X) for activator '%s' (%08X).";

// Resets all sound pointers and related fields to zero/default values.
// @fnv 0x00589980
void BGSAcousticSpace::ResetFormData()
{
    pDawnSound = 0;
    pNoonSound = 0;
    pDuskSound = 0;
    pNightSound = 0;
    pWallaSound = 0;
    m_iFlags = 0;
    m_bIsInterior = true;
    pRegion = 0;
    m_eCellEnvironmentType = CELL_ENVIRO_TYPE_CET_DEFAULT;
}

// @fnv 0x0058a200
char GetByteAtOffset48(void* this_ptr)
{
    return static_cast<char*>(this_ptr)[0x30];
}

struct FUN_00589f50_shell
{
    void SetSound(void* apSound);
};
// Loads an acoustic space record from a TESFile, reading the editor ID, OBND, SNAM sound slots, WNAM, RDAT region, ANAM type and INAM interior flag chunks.
// @fnv 0x00589d30
bool BGSAcousticSpace::Load(TESFile* file)
{
    unsigned int soundFormID = 0;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int m_uiSoundEntryCount = 0;
    int chunk;
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
        case 0x4D414E53:  // SNAM
            soundFormID = 0;
            file->GetChunkData(&soundFormID);
            if (m_uiSoundEntryCount == 4)
                reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((::TESObjectREFR *)(::TESSound *)(reinterpret_cast<TESSound*>(soundFormID)));
            else if (m_uiSoundEntryCount == 3)
                reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(::TESSound *)(reinterpret_cast<TESSound*>(soundFormID)));
            else if (m_uiSoundEntryCount == 2)
                reinterpret_cast<::FUN_00409480_shell *>(this)->FUN_00409480((::TESActorBase *)(::TESSound *)(reinterpret_cast<TESSound*>(soundFormID)));
            else if (m_uiSoundEntryCount == 1)
                reinterpret_cast<::FUN_0040e500_shell *>(this)->SetValue((std::intptr_t)(reinterpret_cast<TESSound*>(soundFormID)));
            else
                reinterpret_cast<::LowProcess *>(this)->SetCurrentBoundObject((::TESBoundObject *)(::TESSound *)(reinterpret_cast<TESSound*>(soundFormID)));
            m_uiSoundEntryCount++;
            break;
        case 0x4D414E57:  // WNAM
            file->GetChunkData(reinterpret_cast<unsigned int*>(&m_iFlags));
            break;
        case 0x54414452:  // RDAT
            soundFormID = 0;
            file->GetChunkData(&soundFormID);
            pRegion = reinterpret_cast<TESRegion*>(static_cast<std::uintptr_t>(soundFormID));
            break;
        case 0x4D414E41:  // ANAM
            file->GetChunkData(&soundFormID);
            reinterpret_cast<::FUN_00589f50_shell *>(this)->SetSound((*(void * *)&(const ::CELL_ENVIRO_TYPE &)(static_cast<CELL_ENVIRO_TYPE>(soundFormID))));
            break;
        case 0x4D414E49:  // INAM
        {
            unsigned int interiorFlag;
            file->GetChunkData(&interiorFlag);
            if (interiorFlag == 0)
                m_bIsInterior = false;
            else
                m_bIsInterior = true;
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x00589f50
void FUN_00589f50_shell::SetSound(void* apSound)
{
    *(std::intptr_t*)((char*)this + 0x4c) = (std::intptr_t)apSound;
}

struct Standin00589930
{
    void* FUN_00589930(unsigned int);
};
struct NiFormArray
{
};
class BGSCameraShot;
template <class> class BSSimpleList;
struct BGSCameraPath
{
    virtual ~BGSCameraPath()
    {}
public:
    ::BGSCameraPath *GetPrevPath();
public:
    ::BSSimpleList< ::BGSCameraShot *> *GetShotList();
};
// @fnv 0x005899f0
void BGSAcousticSpace::InitItem()
{
    unsigned int formID;
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;
    formID = (unsigned int)(std::uintptr_t)(pDawnSound);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pDawnSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!pDawnSound)
            ::FUN_005b5e40();
    }
    formID = (unsigned int)(std::uintptr_t)(pNoonSound);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pNoonSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!pNoonSound)
            ::FUN_005b5e40();
    }
    formID = (unsigned int)(std::uintptr_t)(pDuskSound);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pDuskSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!pDuskSound)
            ::FUN_005b5e40();
    }
    formID = (unsigned int)(std::uintptr_t)(pNightSound);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pNightSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!pNightSound)
            ::FUN_005b5e40();
    }
    formID = (unsigned int)(std::uintptr_t)(pRegion);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pRegion = dynamic_cast<TESRegion*>(::FUN_004839c0(formID));
        if (!pRegion)
            ::FUN_005b5e40();
    }
    formID = (unsigned int)(std::uintptr_t)(pWallaSound);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pWallaSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!pWallaSound)
            ::FUN_005b5e40();
    }
    SetInitializationState(true);
}
struct FUN_0058b630_shell
{
    char _pad[0x2c];
    NiFormArray* m_aiIndexedValues;
    BGSCameraPath* GetCameraPathAt(unsigned int);
};
// Returns the BGSCameraPath at index idx from the form array, or null if the array is absent or the form is not a camera path.
// @fnv 0x0058b630
BGSCameraPath* FUN_0058b630_shell::GetCameraPathAt(unsigned int uiIndex)
{
    BGSCameraPath* result = 0;
    if (m_aiIndexedValues)
        result = dynamic_cast<BGSCameraPath*>(reinterpret_cast<::FUN_004d6170_shell *>((m_aiIndexedValues))->FUN_004d6170(uiIndex));
    return result;
}

extern int DAT_010320fc;


struct FUN_00589960_shell
{
    void FUN_00589960();
};
// Calls FUN_00589960, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00589930
void* Standin00589930::FUN_00589930(unsigned int flags)
{
    reinterpret_cast<::FUN_00589960_shell *>(this)->FUN_00589960();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00589960
void FUN_00589960_shell::FUN_00589960()
{
    *reinterpret_cast<int**>(this) = &DAT_010320fc;
    reinterpret_cast<::FUN_0050e9f0_shell *>((this))->FUN_0050e9f0();
}

struct FUN_0058a120_shell : BGSAcousticSpace
{
    void CopyFromAcousticSpace(TESForm* apCopy);
};
struct FUN_00792780_Class
{
    void SetByteAtOffset30(unsigned char);
};
struct CP_008c48d0
{
};
struct TESTopicInfo
{
    TESRegion* GetParentQuest();
};
struct EP_008c48d0
{
};
struct BSOcclusionPlane
{
};
struct Idle_008b2010
{
};
struct BGSAddonNode
{
    void SetIndex(std::uintptr_t);
};
struct FUN_005e78f0_t
{
};
struct FUN_0068a810_shell
{
};
// Casts apCopy to BGSAcousticSpace, copies its sound, index, region and environment fields into this, then calls FUN_004851b0.
// @fnv 0x0058a120
void FUN_0058a120_shell::CopyFromAcousticSpace(TESForm* apCopy)
{
    BGSAcousticSpace* pcopy = dynamic_cast<BGSAcousticSpace*>(apCopy);
    if (!pcopy)
        return;
    ((FUN_00792780_Class*)this)->SetByteAtOffset30(GetByteAtOffset48(pcopy));
    reinterpret_cast<::LowProcess *>(this)->SetCurrentBoundObject((::TESBoundObject *)(::TESSound *)(((::TESSound *)(reinterpret_cast<::BGSCameraPath *>((((CP_008c48d0*)pcopy)))->GetPrevPath()))));
    reinterpret_cast<::FUN_0040e500_shell *>(this)->SetValue((std::intptr_t)(((::TESSound *)(::GetField38((char *)(((TESTopicInfo*)pcopy)))))));
    reinterpret_cast<::FUN_00409480_shell *>(this)->FUN_00409480((::TESActorBase *)(::TESSound *)(((::TESSound *)(reinterpret_cast<::Twin_00639b40 *>((((EP_008c48d0*)pcopy)))->GetEntryPoint()))));
    reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(::TESSound *)(((::TESSound *)(reinterpret_cast<::LowProcess *>((((BSOcclusionPlane*)pcopy)))->GetTarget()))));
    reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((::TESObjectREFR *)(::TESSound *)(((::TESSound *)(reinterpret_cast<::LowProcess *>((((Idle_008b2010*)pcopy)))->GetActiveCombatTarget()))));
    ((BGSAddonNode*)this)->SetIndex(((std::uintptr_t)(reinterpret_cast<::FUN_0068a830_shell *>((((BGSAddonNode*)pcopy)))->GetGrass())));
    pRegion = ((TESTopicInfo*)pcopy)->GetParentQuest();
    reinterpret_cast<::FUN_00589f50_shell *>(this)->SetSound((*(void * *)&(const ::CELL_ENVIRO_TYPE &)((CELL_ENVIRO_TYPE)reinterpret_cast<::FUN_0068a810_class *>((((FUN_0068a810_shell*)pcopy)))->GetField4C())));
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pcopy);
}

struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct P09AS
{
};


struct FUN_00589f70_shell
{
    void FUN_00589f70();
};

// @fnv 0x00589f70
void FUN_00589f70_shell::FUN_00589f70()
{
    unsigned int questFormID;
    unsigned int formID;

    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();

    questFormID = 0;
    if (((::TESSound *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(this)))->GetPrevPath())) != 0)
    {
        questFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::TESSound *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(this)))->GetPrevPath())))))->FUN_0084e3a0()));
    }
    ::FUN_00485910(0x4d414e53, questFormID);

    questFormID = 0;
    if (((::TESSound *)(::GetField38((char *)(reinterpret_cast<TESTopicInfo*>(this))))) != 0)
    {
        questFormID =
            ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::TESSound *)(::GetField38((char *)(reinterpret_cast<TESTopicInfo*>(this))))))))->FUN_0084e3a0()));
    }
    ::FUN_00485910(0x4d414e53, questFormID);

    questFormID = 0;
    if (((::TESSound *)(reinterpret_cast<::Twin_00639b40 *>((reinterpret_cast<EP_008c48d0*>(this)))->GetEntryPoint())) != 0)
    {
        questFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::TESSound *)(reinterpret_cast<::Twin_00639b40 *>((reinterpret_cast<EP_008c48d0*>(this)))->GetEntryPoint())))))->FUN_0084e3a0()));
    }
    ::FUN_00485910(0x4d414e53, questFormID);

    questFormID = 0;
    if (((::TESSound *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<BSOcclusionPlane*>(this)))->GetTarget())) != 0)
    {
        questFormID =
            ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::TESSound *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<BSOcclusionPlane*>(this)))->GetTarget())))))->FUN_0084e3a0()));
    }
    ::FUN_00485910(0x4d414e53, questFormID);

    questFormID = 0;
    if (((::TESSound *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<Idle_008b2010*>(this)))->GetActiveCombatTarget())) != 0)
    {
        questFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::TESSound *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<Idle_008b2010*>(this)))->GetActiveCombatTarget())))))->FUN_0084e3a0()));
    }
    ::FUN_00485910(0x4d414e53, questFormID);

    ::FUN_00485910(0x4d414e57, *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x50));

    if (reinterpret_cast<TESTopicInfo*>(this)->GetParentQuest() != 0)
    {
        formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(reinterpret_cast<TESTopicInfo*>(this)->GetParentQuest())))->FUN_0084e3a0()));
        ::FUN_00485910(0x54414452, formID);
    }

    ::FUN_00485910(0x4d414e41, reinterpret_cast<::FUN_0068a810_class *>((reinterpret_cast<P09AS*>(this)))->GetField4C());

    if (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x30) != 0)
    {
        ::FUN_00485910(0x4d414e49, 1);
    }
    else
    {
        ::FUN_00485910(0x4d414e49, 0);
    }

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

namespace fnv_0058a220 {
struct FUN_005e79a0_t
{
};

struct P09AS
{
};

struct FUN_0058a220_shell
{
    bool IsNotEqual(TESForm*);
};

// @fnv 0x0058a220
bool FUN_0058a220_shell::IsNotEqual(TESForm* apCompare)
{
    BGSAcousticSpace* pcomp = dynamic_cast<BGSAcousticSpace*>(apCompare);
    if (!pcomp)
        return true;

    if (static_cast<unsigned char>(GetByteAtOffset48(this)) != static_cast<unsigned char>(GetByteAtOffset48(pcomp)))
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(pcomp))
        return true;

    if (((::TESSound *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(this)))->GetPrevPath())) != ((::TESSound *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(pcomp)))->GetPrevPath())))
        return true;

    if (((::TESSound *)(::GetField38((char *)(reinterpret_cast<TESTopicInfo*>(this))))) !=
        ((::TESSound *)(::GetField38((char *)(reinterpret_cast<TESTopicInfo*>(pcomp))))))
        return true;

    if (((::TESSound *)(reinterpret_cast<::Twin_00639b40 *>((reinterpret_cast<EP_008c48d0*>(this)))->GetEntryPoint())) != ((::TESSound *)(reinterpret_cast<::Twin_00639b40 *>((reinterpret_cast<EP_008c48d0*>(pcomp)))->GetEntryPoint())))
        return true;

    if (((::TESSound *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<BSOcclusionPlane*>(this)))->GetTarget())) !=
        ((::TESSound *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<BSOcclusionPlane*>(pcomp)))->GetTarget())))
        return true;

    if (((::TESSound *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<Idle_008b2010*>(this)))->GetActiveCombatTarget())) != ((::TESSound *)(reinterpret_cast<::LowProcess *>((reinterpret_cast<Idle_008b2010*>(pcomp)))->GetActiveCombatTarget())))
        return true;

    if (((std::uintptr_t)(reinterpret_cast<::FUN_0068a830_shell *>((reinterpret_cast<BGSAddonNode*>(this)))->GetGrass())) != ((unsigned int)(std::uintptr_t)(reinterpret_cast<::FUN_0068a830_shell *>((reinterpret_cast<BGSAddonNode*>(pcomp)))->GetGrass())))
        return true;

    if (reinterpret_cast<TESTopicInfo*>(this)->GetParentQuest() !=
        reinterpret_cast<TESTopicInfo*>(pcomp)->GetParentQuest())
        return true;

    if (reinterpret_cast<::FUN_0068a810_class *>((reinterpret_cast<P09AS*>(this)))->GetField4C() != reinterpret_cast<::FUN_0068a810_class *>((reinterpret_cast<P09AS*>(pcomp)))->GetField4C())
        return true;

    return false;
}
}  // namespace fnv_0058a220

class FUN_0050e820 : public TESForm
{
  public:
    FUN_0050e820();
    virtual ~FUN_0050e820();
};

class FUN_005898c0 : public FUN_0050e820
{
  public:
    FUN_005898c0();
    virtual ~FUN_005898c0();
};

// Sets the form type to ASPC and calls FUN_00589980.
// @fnv 0x005898c0
FUN_005898c0::FUN_005898c0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_ASPC_ID)));
    reinterpret_cast<::BGSAcousticSpace *>(this)->ResetFormData();
}
