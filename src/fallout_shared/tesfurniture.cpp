// fallout_shared/tesfurniture.cpp: TESFurniture, TESObjectACTI (21 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00558dd0_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00993000.h"
#include "fnv/symbols_00c54000.h"
#include "tesfurniture_tesfurniture.h"

// @fnv 0x00508f70
void TESFurniture::ResetFormData()
{
    m_iMarkerCount = 0;
    TESObjectACTI::ResetFormData();
}

// Skips initialization if the form is already initialized; otherwise initializes the destructible object form, then calls two further setup steps.
// @fnv 0x00508f90
void TESFurniture::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;
    BGSDestructibleObjectForm::InitItem(this);
    InitializeMarkerFlags();
    SetInitializationState(true);
}

// @fnv 0x005093f0
bool TESFurniture::GetCanSitOn()
{
    if (m_iMarkerCount & 0x40000000)
        return true;
    else
        return false;
}

// @fnv 0x00509420
bool TESFurniture::GetCanSleepOn()
{
    if (m_iMarkerCount & 0x80000000)
        return true;
    else
        return false;
}

// Returns true if the marker bit for aiMarker (below 0x20) is set in the marker mask.
// @fnv 0x00509450
bool TESFurniture::IsMarkerEnabled(unsigned int aiMarker)
{
    bool bEnabled = false;
    if (aiMarker < 0x20)
    {
        unsigned int iMask = 1 << aiMarker;
        if (m_iMarkerCount & iMask)
            bEnabled = true;
    }
    return bEnabled;
}

// @fnv 0x005094f0
bool TESFurniture::IsFurnitureSleepMarker(unsigned int auMarker)
{
    bool bSleep = false;
    if (auMarker < 10)
        bSleep = true;
    return bSleep;
}

// Returns true when auMarker is between 10 and 20 inclusive or equals 26, otherwise false.
// @fnv 0x00509510
bool TESFurniture::IsFurnitureSitMarker(unsigned int auMarker)
{
    bool bSit = false;
    if (auMarker >= 10 && auMarker <= 20 || auMarker == 26)
        bSit = true;
    return bSit;
}

// @fnv 0x00508fd0
bool TESFurniture::Load(TESFile* file)
{
    CHUNK_ID chunk;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    while ((chunk = static_cast<CHUNK_ID>(((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))) != 0)
    {
        switch (chunk)
        {
        case CHUNK_ID_EDID_ID: {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case CHUNK_ID_OBND_ID:
            readOBNDSubRecord(file);
            break;
        case CHUNK_ID_FULL_ID:
            ::ReadFullName(this, file);
            break;
        case CHUNK_ID_MODL_ID:
        case CHUNK_ID_MODD_ID:
        case CHUNK_ID_MODT_ID:
        case CHUNK_ID_MOSD_ID:
            TESModel::LoadModelData(this, file);
            break;
        case CHUNK_ID_MODS_ID: {
            void* textureSwapData;
            unsigned int textureSwapSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            textureSwapData = _alloca(textureSwapSize);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureSwapData), textureSwapSize);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(textureSwapData, textureSwapSize,
                                 reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((static_cast<TESFileFormVersion*>(file)))->FUN_00403570());
            break;
        }
        case CHUNK_ID_SCRI_ID: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::Script *)(reinterpret_cast<Script*>(scriptID)));
            TESScriptableForm::InitItem(this);
            break;
        }
        case CHUNK_ID_DEST_ID:
        case CHUNK_ID_DSTD_ID:
            ::FUN_004781e0(this, file);
            break;
        case CHUNK_ID_MNAM_ID:
            file->GetChunkData(reinterpret_cast<unsigned int*>(&m_iMarkerCount));
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Returns the offset for a marker index (1-40) from the marker table, scaling the z component by afScale - 1.
// @fnv 0x00509920
NiPoint3 TESFurniture::GetMarkerOffset(unsigned int auMarkerIndex, float afScale)
{
    NiPoint3 offset = NiPoint3::ZERO;
    if (auMarkerIndex > 0 && auMarkerIndex <= 40)
    {
        offset.x = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(g_ppFurnitureMarkerOffsetSettings[auMarkerIndex - 1][0]))))->f;
        offset.y = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(g_ppFurnitureMarkerOffsetSettings[auMarkerIndex - 1][1]))))->f;
        offset.z = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(g_ppFurnitureMarkerOffsetSettings[auMarkerIndex - 1][2]))))->f * (afScale - 1.0f);
    }
    return offset;
}

// @fnv 0x005104f0
TESObjectACTI::TESObjectACTI()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_ACTI_ID)));
    ResetFormData();
    SetInitializationState(true);
}

// @fnv 0x00509350
void TESFurniture::InitializeMarkerFlags()
{
    if (reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0())
        return;
    if (m_iMarkerCount == 0)
    {
        if (!((::NiAVObject *)(::FUN_00c54400((::C54400Owner *)(::NiNode *)(Create3DModel(0))))))
            ::FUN_005b5e40();
        else
            ::FUN_005b5e40();
        vfn_150(0);
    }
}


// @fnv 0x00509490
int FUN_00509490(char* pThis)
{
    return ((int)(::FUN_009938b0((const unsigned short *)(void *)(pThis + 0xc))));
}

struct NiStream;
struct FurnitureMark
{
    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
    NiPoint3 Position;
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    char _pad_f[1];
};
struct FUN_005094b0_shell : public FurnitureMark
{
    unsigned int FUN_005094b0();
};

// @fnv 0x005094b0
unsigned int FUN_005094b0_shell::FUN_005094b0()
{
    return m_ucFlags;
}

struct DummyArr
{
};

struct DummyThis
{
    char pad[0xc];
    DummyArr arr;
};

struct StackArg
{
    int val;
};

// @fnv 0x005094d0
void FUN_005094d0(DummyThis* this_ptr, StackArg param_1)
{
    reinterpret_cast<::FUN_00558dd0_class *>(&(this_ptr->arr))->FUN_00558dd0(param_1.val);
}

struct FUN_005099c0_shell : public TESFurniture
{
    float GetFurnitureHeading(unsigned int);
};

struct FurnitureMarkerData
{
    int unk0;
    int unk4;
    SettingT<GameSettingCollection>* pHeadingSetting;
    int unkC;
};
extern FurnitureMarkerData DAT_01189fa4[];

// Returns the heading float from the furniture marker setting at aiIndex-1 when aiIndex is in 1..0x28, otherwise 0.0f.
// @fnv 0x005099c0
float FUN_005099c0_shell::GetFurnitureHeading(unsigned int aiIndex)
{
    float fheading = 0.0f;
    if (aiIndex > 0 && aiIndex <= 0x28)
    {
        fheading = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)(DAT_01189fa4[aiIndex - 1].pHeadingSetting))))->f;
    }
    return fheading;
}

struct FUN_00508e00 : public TESObjectACTI
{
    FUN_00508e00();
    virtual ~FUN_00508e00();
};

// @fnv 0x00508e00
FUN_00508e00::FUN_00508e00()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x27)));
    ((TESFurniture*)this)->ResetFormData();
    SetInitializationState(true);
}

void operator delete(void*);

struct FUN_00508eb0_obj
{
    void FUN_00508ee0();
    void* Destroy(unsigned int flags);
};

struct FUN_00508ee0 : public TESObjectACTI
{
    virtual ~FUN_00508ee0();
};
// Calls FUN_00508ee0, then deletes this object if flags has bit 0 set, and returns this.
// @fnv 0x00508eb0
void* FUN_00508eb0_obj::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00508ee0 *>(this)->FUN_00508ee0::~FUN_00508ee0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor for this TESObjectACTI subclass that calls ClearData().
// @fnv 0x00508ee0
FUN_00508ee0::~FUN_00508ee0()
{
    ClearData();
}

struct S_00487010
{
};
struct S_0048a520
{
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct S_00477f20
{
};

struct FUN_00509280_obj : public TESFurniture
{
    void FUN_00509280();
};

// @fnv 0x00509280
void FUN_00509280_obj::FUN_00509280()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)((char*)this + 0x30))))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)((char*)this + 0x3c))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    ((S_0048cca0*)((char*)this + 0x5c))->FUN_0048cca0();
    reinterpret_cast<::FUN_00477f20_shell *>((((S_00477f20*)((char*)this + 0x68))))->FUN_00477f20();
    FUN_00485910(0x4d414e4d, m_iMarkerCount);
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

struct FUN_005092f0_obj : public TESFurniture
{
    void CopyFromFurniture(TESForm* apCopy);
};

// @fnv 0x005092f0
void FUN_005092f0_obj::CopyFromFurniture(TESForm* apCopy)
{
    TESFurniture* pcopy = dynamic_cast<TESFurniture*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(apCopy);
    m_iMarkerCount = pcopy->m_iMarkerCount;
    InitializeMarkerFlags();
}

struct FUN_00509540_obj : public TESFurniture
{
    bool FUN_00485270(TESForm*);
    bool FUN_00509540(TESForm* apCompare);
};

// @fnv 0x00509540
bool FUN_00509540_obj::FUN_00509540(TESForm* apCompare)
{
    TESFurniture* pcomp = dynamic_cast<TESFurniture*>(apCompare);
    if (!pcomp)
        return true;
    if (FUN_00485270(pcomp))
        return true;
    if (m_iMarkerCount != pcomp->m_iMarkerCount)
        return true;
    return false;
}
