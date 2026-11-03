// fallout_shared/bgstalkingactivator.cpp: BGSTalkingActivator, Pathing, TalkingActivatorComparison, TESObjectACTI and more (23 functions)

#include <new>
#include "fnv/decl/ACTIView.h"
#include "fnv/decl/ActiV511.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSProjectileFloatNode.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_004011d0_shell.h"
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
#include "fnv/decl/FUN_00510770_shell.h"
#include "fnv/decl/FUN_00511860_holder.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_005118c0.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0056b190__FUN_0056b190_shell.h"
#include "fnv/decl/fnv_00572380__Fn572380.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0056b000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006d4000.h"
#include "fnv/symbols_011c8000.h"
#include "bgstalkingactivator.h"
#include <malloc.h>

static const char s_kTalkingVoiceTypeWarning[] =
    "MASTERFILE: Could not find voice type (%08X) for activator '%s' (%08X).";

// @fnv 0x004fe7a0
void BGSTalkingActivator::ResetFormData()
{
    m_kFactionList = 0;
    TESObjectACTI::ResetFormData();
}

// @fnv 0x004fe7c0
void BGSTalkingActivator::InitItem()
{
    unsigned int voiceTypeID;
    if (GetInitialized())
        return;
    reinterpret_cast<::FUN_00510770_shell *>(this)->FUN_00510770();
    m_pTempRef = 0;
    voiceTypeID = reinterpret_cast<unsigned int>(m_kFactionList);
    if (voiceTypeID)
    {
        ::ResolveFormID((unsigned int *)&(voiceTypeID), GetFile(-1));
        m_kFactionList = dynamic_cast<BGSVoiceType*>(::FUN_004839c0(voiceTypeID));
        if (!m_kFactionList)
            ::FUN_005b5e40();
    }
    SetInitializationState(true);
}

#include "bgstalkingactivator_radio.h"

// @fnv 0x004ff1a0
void BGSTalkingActivator::FindRadioStations(TESObjectREFR* ref, BSSimpleList<TESObjectREFR*>* stations,
                                            BSSimpleList<float>* distances)
{
    if (!stations || !ref || !((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())))
        return;
    TESWorldSpace* m_pContainingWorldspace = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((ref))->FUN_00575d70()));
    TESObjectCELL* m_pReferenceCell = 0;
    if (!m_pContainingWorldspace)
        m_pReferenceCell = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget()));
    float fDistance = FLT_MAX;
    bool bReferencePresent = false;
    BSSimpleList<TESObjectREFR*>* pCurrent = &(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011c8264));
    while (pCurrent && !pCurrent->IsEmpty())
    {
        TESObjectREFR* pCurrentRadioStation = ((::TESObjectREFR *)(new ((void *)(pCurrent)) ::Vec3()));
        bReferencePresent = false;
        fDistance = FLT_MAX;
        if (!pCurrentRadioStation->GetDisabled() || !m_pContainingWorldspace)
        {
            switch (pCurrentRadioStation->GetRadioRangeType())
            {
            case RADIO_RADIUS: {
                TESObjectREFR* pExteriorRef = ::FUN_0056b140((::TESObjectREFR *)(pCurrentRadioStation));
                if (!pExteriorRef)
                    pExteriorRef = pCurrentRadioStation;
                TESWorldSpace* pStationWorldSpace = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((pExteriorRef))->FUN_00575d70()));
                if (!pStationWorldSpace)
                    ::FUN_005b5e40();
                else
                {
                    if (m_pContainingWorldspace && m_pContainingWorldspace == pStationWorldSpace)
                        fDistance = reinterpret_cast<::fnv_00572380::Fn572380 *>((ref))->FUN_00572380((::fnv_00572380::NiP3Sub *)&(*pExteriorRef->GetPos()));
                    else if (!m_pContainingWorldspace)
                        fDistance = Pathing::FindPathDistance(
                            PathingLocation(pCurrentRadioStation), PathingLocation(ref),
                            reinterpret_cast<::fnv_0056b190::FUN_0056b190_shell *>((pCurrentRadioStation))->FUN_0056b190(), 0, Pathing::RADIO_LOCKS);
                    if (fDistance < reinterpret_cast<::fnv_0056b190::FUN_0056b190_shell *>((pCurrentRadioStation))->FUN_0056b190())
                        bReferencePresent = true;
                }
            }
            break;
            case RADIO_EVERYWHERE:
                bReferencePresent = true;
                fDistance = -1.0f;
                break;
            case RADIO_WORLDSPACE: {
                TESWorldSpace* pStationWorldSpace = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((pCurrentRadioStation))->FUN_00575d70()));
                if (!pStationWorldSpace)
                    ::FUN_005b5e40(
                        );
                else if (m_pContainingWorldspace)
                {
                    if (m_pContainingWorldspace == pStationWorldSpace)
                    {
                        bReferencePresent = true;
                        fDistance = -1.0f;
                    }
                }
                else
                {
                    PathingPath path;
                    if (::FUN_006d4d20((::LocS *)&(const ::PathingLocation &)(PathingLocation(pCurrentRadioStation)), (::LocS *)&(const ::PathingLocation &)(PathingLocation(ref)),
                                                           &path, (*(int *)&(const ::Pathing::TELEPORT_DOOR_PATH_RESTRICTION &)(Pathing::ONE_WORLDSPACE)), 0.0f, 0,
                                                           (*(int *)&(const ::Pathing::DOOR_LOCK_DISPOSITION &)(Pathing::IGNORE_LOCKS))))
                    {
                        bReferencePresent = true;
                        fDistance = -1.0f;
                        unsigned int count = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(path.Spaces))->GetName()));
                        for (unsigned int i = 0; i < count; ++i)
                        {
                            TESWorldSpace* pathWorld = path.Spaces.GetAt(i).m_pContainingWorldspace;
                            if (pathWorld && pathWorld != pStationWorldSpace)
                            {
                                bReferencePresent = false;
                                break;
                            }
                        }
                    }
                }
            }
            break;
            case RADIO_INTERIORS:
                if (m_pReferenceCell)
                {
                    PathingPath path;
                    if ((((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())) && ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pCurrentRadioStation))->GetTarget())) &&
                         ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())) == ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pCurrentRadioStation))->GetTarget()))) ||
                        ::FUN_006d4d20((::LocS *)&(const ::PathingLocation &)(PathingLocation(pCurrentRadioStation)), (::LocS *)&(const ::PathingLocation &)(PathingLocation(ref)),
                                                           &path, (*(int *)&(const ::Pathing::TELEPORT_DOOR_PATH_RESTRICTION &)(Pathing::INTERIOR_ONLY)), 0.0f, 0,
                                                           (*(int *)&(const ::Pathing::DOOR_LOCK_DISPOSITION &)(Pathing::IGNORE_LOCKS))))
                    {
                        bReferencePresent = true;
                        fDistance = -1.0f;
                        unsigned int count = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(path.Spaces))->GetName()));
                        for (unsigned int i = 0; i < count; ++i)
                        {
                            if (path.Spaces.GetAt(i).m_pContainingWorldspace)
                            {
                                bReferencePresent = false;
                                break;
                            }
                        }
                    }
                }
                break;
            case RADIO_CELL:
                if (((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())) && ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pCurrentRadioStation))->GetTarget())) &&
                    ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())) == ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pCurrentRadioStation))->GetTarget())))
                {
                    bReferencePresent = true;
                    fDistance = -1.0f;
                }
                break;
            }
            if (bReferencePresent)
            {
                stations->AddHead(pCurrentRadioStation);
                if (distances)
                    reinterpret_cast<::BGSProjectileFloatNode *>((distances))->AddHead(fDistance);
            }
        }
        pCurrent = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((pCurrent))->FUN_00726070()));
    }
}

#include "bgstalkingactivator_load.h"

// Reads the record header and iterates chunks, dispatching each to the matching sub-record loader until no chunks remain, then returns true.
// @fnv 0x004fe890
bool BGSTalkingActivator::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunk;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            ::ReadFullName(this, file);
            break;
        case 'LDOM':
        case 'TDOM':
        case 'DDOM':
        case 'DSOM':
            TESModel::LoadModelData(this, file);
            break;
        case 'SDOM': {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            void* pChunkData = _alloca(size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pChunkData), size);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(pChunkData, size, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((static_cast<TESFileFormVersion*>(file)))->FUN_00403570());
        }
        break;
        case 'IRCS': {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::Script *)(reinterpret_cast<Script*>(scriptID)));
            TESScriptableForm::InitItem(this);
        }
        break;
        case 'TSED':
        case 'DTSD':
            ::FUN_004781e0(this, file);
            break;
        case 'MANS': {
            unsigned int soundID = 0;
            file->GetChunkData(&soundID);
            SetLoopingSound(reinterpret_cast<TESSound*>(soundID));
        }
        break;
        case 'MANI': {
            unsigned int templateID = 0;
            file->GetChunkData(&templateID);
            // Radio-template setter is folded with this canonical +0x7C setter.
            reinterpret_cast<EffectSetting*>(this)->SetEnchantEffectShader(
                reinterpret_cast<TESEffectShader*>(templateID));
        }
        break;
        case 'MANV': {
            unsigned int voiceID = 0;
            file->GetChunkData(&voiceID);
            SetVoiceType(reinterpret_cast<BGSVoiceType*>(voiceID));
        }
        break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Returns true if form is a talking activator (form type 0x16) whose IsRadioStation check succeeds.
// @fnv 0x004fede0
bool BGSTalkingActivator::IsRadioStation(TESForm* form, unsigned int data)
{
    bool result = false;
    if (form && form->GetFormType() == 0x16)
    {
        BGSTalkingActivator* activator = static_cast<BGSTalkingActivator*>(form);
        if (activator->IsRadioStation())
            result = true;
    }
    return result;
}

// If ref is non-null and its object reference is a radio station, adds ref to the head of the list.
// @fnv 0x004ff150
void BGSTalkingActivator::AddRadioStation(TESObjectREFR* ref)
{
    if (ref && IsRadioStation(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())), 0))
        (*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011c8264)).AddHead(ref);
}

// @fnv 0x004febf0
void BGSTalkingActivator::SetVoiceType(BGSVoiceType* apVoiceType)
{
    m_kFactionList = apVoiceType;
}

// @fnv 0x004febb0
void TESObjectACTI::SetLoopingSound(TESSound* sound)
{
    m_pSoundEffect = sound;
}

// @fnv 0x004febd0
void EffectSetting::SetEnchantEffectShader(TESEffectShader* shader)
{
    pEnchantEffectShader = shader;
}

// @fnv 0x004fedc0
bool BGSTalkingActivator::IsRadioStation()
{
    return reinterpret_cast<::FUN_004011d0_shell *>(this)->FUN_004011d0();
}

struct Actor;
struct FUN_00516bf0_shell : public BGSTalkingActivator
{
    Actor* FUN_00516bf0();
};

// @fnv 0x00516bf0
Actor* FUN_00516bf0_shell::FUN_00516bf0()
{
    return *(Actor**)((char*)this + 0x90);
}

struct Elem12
{
    int data[3];
};

struct ArrayObj
{
    int unk0;
    Elem12* m_pBase;
};

struct StackIdx
{
    unsigned int i;
};

// @fnv 0x006a1440
Elem12& __fastcall FUN_006a1440(ArrayObj* pThis, StackIdx aiIndex)
{
    return pThis->m_pBase[aiIndex.i];
}

// @fnv 0x004ff190
void FUN_004ff190()
{
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011c8264))))->RemoveAll();
}

struct FUN_004fe6e0_Class
{
    void __thiscall FUN_004fe710();
    void* __thiscall FUN_004fe6e0(unsigned int);
};
struct PlayerMover
{
    unsigned int GetActorStateFlags();
};
struct Proxy00511120
{
};
struct FUN_004fecf0_ : BGSTalkingActivator
{
    void CopyVoiceTypeFromActivator(TESForm*);
};
// @fnv 0x004fecf0
void FUN_004fecf0_::CopyVoiceTypeFromActivator(TESForm* apCopy)
{
    BGSTalkingActivator* acti = dynamic_cast<BGSTalkingActivator*>(apCopy);
    if (!acti)
        return;
    reinterpret_cast<::ActiV511 *>((((Proxy00511120*)this)))->FUN_00511120(apCopy);
    SetVoiceType((BGSVoiceType*)((PlayerMover*)acti)->GetActorStateFlags());
}

struct FormChangeMask
{
    int flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(int);
};
struct BGSSaveFormBuffer : public BGSLoadFormBuffer
{
};
struct FUN_00511860_shell
{
};
struct FUN_004ff800_shell : public FUN_00511860_shell
{
    void FUN_004ff800(BGSSaveFormBuffer*);
};
// @fnv 0x004ff800
void FUN_004ff800_shell::FUN_004ff800(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00511860_holder *>(this)->FUN_00511860((::BGSSaveFormBuffer *)(apSaveGameBuffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apSaveGameBuffer->GetChangeFlags(0x800000)))->FUN_004280f0())
        reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(((void**)this)[36]), 0);
}

namespace fnv_004ff850 {
struct FormChangeMask
{
    int m_uiFileCount;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(int);
};
struct Base005118c0
{
};
struct FUN_004ff850_shell
{
    char _pad[0x90];
    int _90;
    void LoadForm(BGSLoadFormBuffer*);
};
// @fnv 0x004ff850
void FUN_004ff850_shell::LoadForm(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::S_005118c0 *>((((Base005118c0*)this)))->FUN_005118c0((::FUN_00428110_cls *)(apLoadGameBuffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_004ff850::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(0x800000)))->FUN_004280f0())
    {
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&_90));
    }
}
}  // namespace fnv_004ff850

namespace fnv_004ff930 {
struct FormChangeMask
{
    unsigned int m_flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetOldChangeFlags(unsigned int);
};
struct FUN_004ff930_shell : TESForm
{
    void RevertAndClearField(BGSLoadFormBuffer*);
};
// @fnv 0x004ff930
void FUN_004ff930_shell::RevertAndClearField(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert((unsigned int)apLoadGameBuffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_004ff930::FormChangeMask &)(apLoadGameBuffer->GetOldChangeFlags(0x800000)))->FUN_004280f0())
        *(int*)((char*)this + 0x90) = 0;
}
}  // namespace fnv_004ff930

struct S_00477f20
{
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
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
struct FUN_004fec10_shell
{
    void FUN_004fec10();
};
// @fnv 0x004fec10
void FUN_004fec10_shell::FUN_004fec10()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<S_00487010*>(reinterpret_cast<char*>(this) + 0x30)))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<S_0048a520*>(reinterpret_cast<char*>(this) + 0x3c)))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<S_0048cca0*>(reinterpret_cast<char*>(this) + 0x5c)->FUN_0048cca0();
    reinterpret_cast<::FUN_00477f20_shell *>((reinterpret_cast<S_00477f20*>(reinterpret_cast<char*>(this) + 0x68)))->FUN_00477f20();
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x74))
    {
        unsigned int id =
            ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x74))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e53, id);
    }
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x94))
    {
        unsigned int id =
            ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x94))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e56, id);
    }
    if (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x7c))
    {
        unsigned int id =
            ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x7c))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e49, id);
    }
    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

extern void* DAT_01025520;

struct FUN_004fe640 : public TESObjectACTI
{
    FUN_004fe640();
    virtual ~FUN_004fe640();
};

// @fnv 0x004fe640
FUN_004fe640::FUN_004fe640()
{
    *(void**)((char*)this + 0x70) = &DAT_01025520;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x16)));
    reinterpret_cast<BGSTalkingActivator*>(this)->BGSTalkingActivator::ResetFormData();
}

class C4FE710BoundAnimObject
{
  public:
    virtual ~C4FE710BoundAnimObject();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

class C4FE710FullName
{
  public:
    virtual ~C4FE710FullName();
    int unk04;
    int unk08;
};

class C4FE710ModelTextureSwap
{
  public:
    virtual ~C4FE710ModelTextureSwap();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class C4FE710ScriptableForm
{
  public:
    virtual ~C4FE710ScriptableForm();
    int unk04;
    int unk08;
};

class C4FE710DestructibleObjectForm
{
  public:
    virtual ~C4FE710DestructibleObjectForm();
    int unk04;
};

class C4FE710SoundForm
{
  public:
    virtual ~C4FE710SoundForm();
};

class C4FE710Activator : public C4FE710BoundAnimObject,
                         public C4FE710FullName,
                         public C4FE710ModelTextureSwap,
                         public C4FE710ScriptableForm,
                         public C4FE710DestructibleObjectForm,
                         public C4FE710SoundForm
{
  public:
    virtual ~C4FE710Activator();

};

class FUN_004fe710 : public C4FE710Activator
{
  public:
    virtual ~FUN_004fe710();
};
// Calls FUN_004fe710, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x004fe6e0
void* __thiscall FUN_004fe6e0_Class::FUN_004fe6e0(unsigned int flags)
{
    reinterpret_cast<::FUN_004fe710 *>(this)->FUN_004fe710::~FUN_004fe710();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004fe710
FUN_004fe710::~FUN_004fe710()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

class Actor : public TESObjectREFR
{
  public:
    virtual ~Actor();
};
struct FUN_004534f0_shell
{
public:
    void FUN_004534f0(unsigned int);
};
struct FUN_004280f0_shell
{
};
struct FUN_00428110_shell
{
    FUN_004280f0_shell* FUN_00428110(unsigned int* a1, unsigned int a2);
};
struct FUN_004ff8a0_shell : public BGSTalkingActivator
{
    void FUN_004ff8a0(void* arg);
};
// Calls FUN_004534f0, then conditionally replaces m_pTempRef with an Actor cast of the form returned by FUN_004839c0.
// @fnv 0x004ff8a0
void FUN_004ff8a0_shell::FUN_004ff8a0(void* arg)
{
    ((FUN_004534f0_shell*)this)->FUN_004534f0((unsigned int)(arg));
    unsigned int local;
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((((FUN_00428110_shell*)arg)->FUN_00428110(&local, 0x800000)))->FUN_004280f0({}))
    {
        m_pTempRef =
            (TESObjectREFR*)(m_pTempRef != 0 ? dynamic_cast<Actor*>(FUN_004839c0((unsigned int)m_pTempRef)) : 0);
    }
}

struct ActivatorComparison
{
};

struct TalkingActivatorComparison : BGSTalkingActivator
{
    BGSVoiceType* __thiscall FUN_009185e0();
    bool __thiscall FUN_004fed50(TESForm* form);
};

BGSVoiceType* __thiscall TalkingActivatorComparison::FUN_009185e0()
{
    return m_kFactionList;
}

// Returns true if form is not a BGSTalkingActivator, FUN_005111e0 returns true, or the two FUN_009185e0 results differ.
// @fnv 0x004fed50
bool __thiscall TalkingActivatorComparison::FUN_004fed50(TESForm* form)
{
    BGSTalkingActivator* activator = dynamic_cast<BGSTalkingActivator*>(form);
    if (!activator)
        return true;
    if (reinterpret_cast<::ACTIView *>((reinterpret_cast<ActivatorComparison*>(this)))->FUN_005111e0(form))
        return true;
    if (((::BGSVoiceType *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())) != ((::BGSVoiceType *)(reinterpret_cast<::PlayerMover *>((static_cast<TalkingActivatorComparison*>(activator)))->GetActorStateFlags())))
        return true;
    return false;
}
