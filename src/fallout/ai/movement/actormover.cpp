// fallout/ai/movement/actormover.cpp: ActorMover, Mover, Tgt_b, MobileObject and more (79 functions)

#include "fnv/simple_array_item.h"
#include <cstdint>
#include "fnv/result_slot.h"
#include <new>
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Dummy.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cbc0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00505c00_shell.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f0b50_shell.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_006a9520_Class.h"
#include "fnv/decl/FUN_006a9560_Class.h"
#include "fnv/decl/FUN_006b05d0_shell.h"
#include "fnv/decl/FUN_006d2c00_shell.h"
#include "fnv/decl/FUN_006d3ac0_Class.h"
#include "fnv/decl/FUN_006dc6e0_Class.h"
#include "fnv/decl/FUN_006e22f0_shell.h"
#include "fnv/decl/FUN_006e2330_shell.h"
#include "fnv/decl/FUN_006e2b50_shell.h"
#include "fnv/decl/FUN_006e2b70_shell.h"
#include "fnv/decl/FUN_006e2b90.h"
#include "fnv/decl/FUN_006e2bb0_shell.h"
#include "fnv/decl/FUN_006e78b0_shell.h"
#include "fnv/decl/FUN_006e8d50_shell.h"
#include "fnv/decl/FUN_0072ba80_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865db0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_0087f350_shell.h"
#include "fnv/decl/FUN_0087f390_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_008843a0_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008985d0_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008ad8f0Class.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_008c6b00_shell.h"
#include "fnv/decl/FUN_008df1c0_Class.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009d9ec0_shell.h"
#include "fnv/decl/FakeHolder.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/PathBuilder.h"
#include "fnv/decl/Pathing.h"
#include "fnv/decl/PathingActorData.h"
#include "fnv/decl/PathingLocationProxy.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_FUN_006b05a0.h"
#include "fnv/decl/SaveSolution.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaitableObject.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00494390__MovementAnimation.h"
#include "fnv/decl/fnv_00495be0__PriorityAnimation.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00587550__FUN_00587550_shell.h"
#include "fnv/decl/fnv_006b7850__FUN_006b7850_shell.h"
#include "fnv/decl/fnv_006e78d0__FUN_006e78d0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_0088d640__FUN_0088d640_shell.h"
#include "fnv/decl/fnv_008a0b10__FUN_008a0b10_shell.h"
#include "fnv/decl/fnv_008ad1c0__MoveSelf454.h"
#include "fnv/decl/fnv_008bc7f0__FUN_008bc7f0_holder.h"
#include "fnv/decl/fnv_008be280__FloatValueProvider.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_009d9f20__FUN_009d9f20_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00573000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006c9000.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_006d5000.h"
#include "fnv/symbols_008b6000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_008e7000.h"
#include "fnv/symbols_00984000.h"
#include "fnv/symbols_009da000.h"
#include "fnv/symbols_009db000.h"
#include "fnv/symbols_009e7000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "actormover_fnv_decls.h"

// @fnv 0x008b3d10
bool ActorMover::HasLookAtTarget()
{
    return m_bHasLookAtTarget;
}
// @fnv 0x009ddb50
bool ActorMover::IsMovementActive()
{
    return eState == 4;
}
// @fnv 0x009de080
void ActorMover::ResetMovementData()
{
    m_bHasMovementData = false;
    m_uiMovementFlags = 0;
}

// @fnv 0x009dd0a0
void ActorMover::StopMoving()
{
    ClearMovementPath();
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

// @fnv 0x00931850
PROCESS_TYPE MobileObject::GetCurrentProcessLevel()
{
    if (m_pBaseProcess)
        return (*(::PROCESS_TYPE *)(reinterpret_cast<::FUN_0045cd60_shell *>((m_pBaseProcess))->FUN_0045cd60()));
    return PROCESS_TYPE_PROCESS_TYPE_NONE;
}
// @fnv 0x009de230
void ActorMover::RunProcedure()
{
    m_kLookAtTargetPosition = ::NiPoint3::ZERO;
    m_bHasLookAtTarget = false;
    reinterpret_cast<::TESForm *>(this)->ClearData();
}
// @fnv 0x009ddbb0
bool ActorMover::GetPathingDelta(NiPoint3& delta)
{
    bool valid = false;
    if (m_bHasPathingDelta)
    {
        m_bHasPathingDelta = false;
        delta = m_kPathingDelta;
        valid = true;
    }
    return valid;
}
// @fnv 0x009dd150
void ActorMover::ClearMovementPath()
{
    if (eState != 6)
    {
        if (m_pPathHandler && !m_pPathHandler->vfn_34())
            eState = 6;
        m_bMovementComplete = true;
    }
    if (bPathingFailed)
        m_bMovementComplete = true;
    UpdateMovementStatus(false);
}
#include "actormover_tesobjectmisc.h"

// @fnv 0x009db930
void TESObjectMISC::SetLoopingSound(TESSound* sound)
{
    pLoopingSound = sound;
}

struct GameSettingCollection
{
    virtual void v0();
    virtual void v1(void*);
};
struct FUN_0040e130
{
    FUN_0040e130(int, float);
    ~FUN_0040e130();
    virtual void vfn_0();
};
struct FUN_0040e0b0 : public FUN_0040e130
{
    FUN_0040e0b0(int a, float b);
};
// @fnv 0x0040e0b0
FUN_0040e0b0::FUN_0040e0b0(int a, float b) : FUN_0040e130(a, b)
{
    ::GetGameSettingCollection()->v1(this);
}

class BSFadeNode
{
  public:
};

class ActorPathingMessageQueue : public BSFadeNode
{
  public:
    char pad[0x1c];
    ActorPathingMessageQueue();
};

struct Ptr_0066b0d0
{
    Ptr_0066b0d0& FUN_0066b0d0(NiNode*);
};

struct Deletable_009daf80
{
    virtual ~Deletable_009daf80();
};

struct Sub_009057d0
{
};

struct VTable_009daf80
{
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
};

// @fnv 0x009daf80
void FUN_009daf80(TESForm* pForm)
{
    *(int*)((char*)pForm + 0x6c) = 6;
    ((Ptr_0066b0d0*)((char*)pForm + 0x1c))->FUN_0066b0d0(0);
    ((Ptr_0066b0d0*)((char*)pForm + 0x20))->FUN_0066b0d0(0);
    if (*(Deletable_009daf80**)((char*)pForm + 0x24) != 0)
    {
        delete *(Deletable_009daf80**)((char*)pForm + 0x24);
        *(Deletable_009daf80**)((char*)pForm + 0x24) = 0;
    }
    if (*(unsigned char*)((char*)pForm + 0x74) != 0)
    {
        reinterpret_cast<::FakeHolder *>((((Sub_009057d0*)((char*)pForm + 0x30))))->AssignObject(new ActorPathingMessageQueue);
        *(unsigned char*)((char*)pForm + 0x74) = 0;
    }
    ((VTable_009daf80*)pForm)->vfn_4();
    pForm->TESForm::ClearData();
}

class PathingRequest;

struct FUN_009db090_shell
{
};

struct FUN_009dba30_fix : public ActorMover
{
    bool FUN_009dba30(const PathingRequest* apRequest);
};

struct PathingSolution
{
};
struct ArrHelper
{
};
struct Mover : public ActorMover
{
    bool FUN_009dc530();
};
// @fnv 0x009dcdb0
bool ActorMover::HasActiveMovement()
{
    if (m_bHasMovementData)
        return false;
    if (eState == 4)
        return true;
    if (m_bMovementActive)
        return true;
    if (!m_pActorNode.operator->() || !reinterpret_cast<::Mover *>(((m_pActorNode).operator->()))->FUN_009dc530() || bPathingFailed)
        return false;
    return true;
}
// @fnv 0x009dc530
bool Mover::FUN_009dc530()
{
    if (reinterpret_cast<::FUN_0076b610_Class *>((void *)(((ArrHelper*)&this->m_kLookAtTargetPosition.y)))->FUN_0076b610())
        return false;
    if (*(int*)&this->m_kPathingDelta.z != -1 && *(int*)((char*)this + 0x1c) != -1 &&
        reinterpret_cast<::FUN_0076b610_Class *>((void *)(((ArrHelper*)((char*)this + 0x20))))->FUN_0076b610())
        return false;
    if (reinterpret_cast<::FUN_006b05d0_shell *>((((PathingSolution*)this)))->FUN_006b05d0())
        return true;
    return true;
}

struct FUN_009dc950_Vtbl
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c(int);
};

struct FUN_009dc950_Obj
{
    char pad[0x24];
    FUN_009dc950_Vtbl* p24;
};

struct FUN_009dc950_Arg
{
    int val;
};

// If pThis->p24 is set, calls its vtable slot v5c with a1.val.
// @fnv 0x009dc950
void ForwardValueToVtbl(FUN_009dc950_Obj* pThis, FUN_009dc950_Arg aArg)
{
    if (pThis->p24)
    {
        pThis->p24->v5c(aArg.val);
    }
}

class BSOcclusionPlane
{
  public:
    int GetCullResult() const;
};


struct FUN_009dcae0_struct
{
    char pad[0x28];
    BSOcclusionPlane* ptr;
};

// @fnv 0x009dcae0
bool FUN_009dcae0(FUN_009dcae0_struct* pOcclusionPlaneStruct)
{
    if (!pOcclusionPlaneStruct->ptr->GetCullResult() ||
        !::FUN_00450ff0((void *)(reinterpret_cast<TESObjectCELL*>(pOcclusionPlaneStruct->ptr->GetCullResult()))) ||
        ::_g_thePlayer->IsSleepingOrResting())
    {
        return false;
    }
    return true;
}

namespace fnv_009dcd40 {
struct StrHelper
{
    operator const char*() const;
};
struct Mover : public ActorMover
{
    bool FUN_009dcd40();
};
// @fnv 0x009dcd40
bool Mover::FUN_009dcd40()
{
    if (*((unsigned char*)&this->m_bMovementActive))
    {
        return false;
    }
    else if (this->eState == 6 || this->eState == 7)
    {
        return true;
    }
    else if (((const char*)*(StrHelper*)((char*)this + 0x20) &&
              reinterpret_cast<::Mover *>((((NiNode*)(const char*)*(StrHelper*)((char*)this + 0x20))))->FUN_009dc530()) ||
             this->eState == 4)
    {
        return false;
    }
    else
    {
        return true;
    }
}
}  // namespace fnv_009dcd40

struct FUN_009dd130_shell : public ActorMover
{
    unsigned int FUN_009dd130();
};
// Returns the preferred move mode type when pathing failed, otherwise returns the stored move mode.
// @fnv 0x009ddb70
unsigned int ActorMover::GetActorStateFlags()
{
    unsigned int uiMoveMode = bPathingFailed ? reinterpret_cast<::FUN_009dd130_shell *>(this)->FUN_009dd130() : m_uiMovementMode;
    return uiMoveMode;
}
// New bodies are reconstructed from the complete supplied PC instruction spans.
// @fnv 0x009dd0c0
void ActorMover::ForceStopMoving()
{
    ClearMovementPath();
    if (m_bMovementComplete)
    {
        m_bMovementComplete = false;
        SetMovementMode(true);
        m_uiMovementMode = reinterpret_cast<::FUN_009dd130_shell *>(this)->FUN_009dd130();
        m_kPathingDelta = ::NiPoint3::ZERO;
        m_bHasPathingDelta = true;
    }
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

// @fnv 0x009dd130
unsigned int FUN_009dd130_shell::FUN_009dd130()
{
    return this->unk34 & 0xff00;
}

namespace fnv_009dd1c0 {
struct FUN_009dd1c0_shell : public ActorMover
{
    void FUN_009dd1c0(bool);
};

class BSFadeNode
{
  public:
};

class ActorPathingMessageQueue
{
  public:
    char pad[0x1c];
    ActorPathingMessageQueue();
};

struct Helper_009057d0
{
};

struct Helper_PathHandler_70
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
};

}  // namespace fnv_009dd1c0
template <> class NiPointer<NiNode*>
{
  public:
    NiPointer<NiNode>& operator=(NiNode*);
};
namespace fnv_009dd1c0 {

// @fnv 0x009dd1c0
void FUN_009dd1c0_shell::FUN_009dd1c0(bool abClearHandler)
{
    switch (eState)
    {
    case 7:
    case 8:
        break;
    default:
        eState = 6;
        break;
    }

    ((NiPointer<NiNode*>*)&request)->operator=(0);
    ((NiPointer<NiNode*>*)&m_pActorNode)->operator=(0);

    if (m_pPathHandler && abClearHandler)
        ((Helper_PathHandler_70*)m_pPathHandler)->v70();

    if (m_bMovementActive)
    {
        reinterpret_cast<::FakeHolder *>((((Helper_009057d0*)((char*)this + 0x30))))->AssignObject(new ActorPathingMessageQueue);
        m_bMovementActive = false;
    }

    UpdateMovementStatus(false);
    ((TESForm*)this)->TESForm::ClearData();
}
}  // namespace fnv_009dd1c0

struct FUN_009ddf60_shell : public ActorMover
{
    void SetMoveModeFlags(unsigned int);
};

void* FUN_009dff40(void*, int, void*, void*);

struct Dummy_0xe4
{
    char pad[0xe4];
    Dummy_0xe4(void* a, void* b)
    {
        FUN_009dff40(this, 0, a, b);
    }
};

// Stores the high byte of auiPreferredMoveMode into bits 8-15 of the field at offset 0x34, lazily creating the object at 0x24, and the low nibble into bits 0-3.
// @fnv 0x009ddf60
void FUN_009ddf60_shell::SetMoveModeFlags(unsigned int auiPreferredMoveMode)
{
    if (auiPreferredMoveMode & 0xff00)
    {
        if (*(void**)&this->m_pPathHandler == 0)
        {
            *(void**)&this->m_pPathHandler = new Dummy_0xe4(this->unk28, this);
        }
        this->unk34 =
            (this->unk34 & 0xf) | (auiPreferredMoveMode & 0xff00);
    }
    if (auiPreferredMoveMode & 0xf)
    {
        this->unk34 =
            (auiPreferredMoveMode & 0xf) | (this->unk34 & 0xff00);
    }
}

namespace fnv_009dfa00 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
struct NiMemObject
{
    char _pad_0[1];
};
struct FUN_009dfa00_shell : public ActorMover
{
    void FUN_009dfa00(BGSLoadFormBuffer*);
};

class PathingRequest
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual int GetType();
};

class ActorPathingMessageQueue
{
  public:
    char pad[0x1c];
    ActorPathingMessageQueue();
};

class PathManager
{
  public:
    bool BuildPath(NiPointer<PathingRequest>, NiPointer<ActorPathingMessageQueue>, bool);
};

}  // namespace fnv_009dfa00
template <> class NiPointer<fnv_009dfa00::PathingRequest>
{
  public:
    fnv_009dfa00::PathingRequest* p;
    NiPointer(const NiPointer<fnv_009dfa00::PathingRequest>&);
    ~NiPointer();
    operator fnv_009dfa00::PathingRequest*() const;
    fnv_009dfa00::PathingRequest* operator->() const;
};

template <> class NiPointer<fnv_009dfa00::ActorPathingMessageQueue>
{
  public:
    fnv_009dfa00::ActorPathingMessageQueue* p;
    NiPointer(const NiPointer<fnv_009dfa00::ActorPathingMessageQueue>&);
    ~NiPointer();
    operator fnv_009dfa00::ActorPathingMessageQueue*() const;
    NiPointer<fnv_009dfa00::ActorPathingMessageQueue>& operator=(fnv_009dfa00::ActorPathingMessageQueue*);
};

template <> class NiPointer<fnv_009dfa00::Actor>
{
  public:
    fnv_009dfa00::Actor* p;
    operator fnv_009dfa00::Actor*() const;
};

namespace fnv_009dfa00 {
struct PathingRequestLOS
{
};

// @fnv 0x009dfa00
void FUN_009dfa00_shell::FUN_009dfa00(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (m_bMovementActive && *(NiPointer<PathingRequest>*)((char*)this + 0x1c))
    {
        bool bforceFail = false;
        if ((*(NiPointer<PathingRequest>*)((char*)this + 0x1c))->GetType() == 5)
        {
            PathingRequestLOS* plosRequest =
                (PathingRequestLOS*)(PathingRequest*)*(NiPointer<PathingRequest>*)((char*)this + 0x1c);
            if (!(*(const ::NiPointer< ::fnv_009dfa00::Actor> *)(::FUN_00984230((char *)(plosRequest)))))
                bforceFail = true;
        }
        if (!*(NiPointer<ActorPathingMessageQueue>*)((char*)this + 0x30))
            *(NiPointer<ActorPathingMessageQueue>*)((char*)this + 0x30) = new ActorPathingMessageQueue();
        if (bforceFail ||
            !((::fnv_009dfa00::PathManager *)(::GetPathManager()))->BuildPath(*(NiPointer<PathingRequest>*)((char*)this + 0x1c),
                                                 *(NiPointer<ActorPathingMessageQueue>*)((char*)this + 0x30), true))
        {
            UpdateMovementStatus(true);
            m_bMovementActive = false;
        }
    }
}
}  // namespace fnv_009dfa00

namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x009daec0
void* DelStandIn::DestroyIfFlagged(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

namespace p07 {
struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
};
struct PosObj
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
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPos();
};
struct FUN_008bb5c0_tgt
{
    char pad[0x28];
    PosObj* obj;
    void* FUN_009dce80(float, bool);
    void* FUN_009dce20(NiPoint3, bool);
};
// @fnv 0x009dce20
void* FUN_008bb5c0_tgt::FUN_009dce20(NiPoint3 aPoint, bool abFlag)
{
    NiPoint3 kDelta = aPoint - *obj->GetPos();
    {
        float fDistance = ::GetDirectionAngle((const ::NiPoint3 *)&(kDelta));
        return FUN_009dce80(fDistance, abFlag);
    }
}
}

namespace fnv_009de420 {
struct FUN_009de420_shell : public ActorMover
{
    bool HasPathingSolution();
};

struct Flt
{
    operator unsigned int() const;
};
struct PathingSolution
{
};

// Returns true if the Flt at offset 0x20 is non-zero and its PathingSolution FUN_006b05d0 check succeeds; otherwise false.
// @fnv 0x009de420
bool FUN_009de420_shell::HasPathingSolution()
{
    if (*(const Flt*)((char*)this + 0x20) &&
        reinterpret_cast<::FUN_006b05d0_shell *>((((PathingSolution*)(uintptr_t)*(const Flt*)((char*)this + 0x20))))->FUN_006b05d0())
        return true;
    return false;
}
}  // namespace fnv_009de420

struct NP
{
    void* p;
    ~NP();
};
struct Ptr2_006e9e20
{
    void* p;
    ~Ptr2_006e9e20();
};
struct _Mem_2064
{
    int d[2];
    ~_Mem_2064();
};
void FUN_009daf80(TESForm*);
struct FUN_009daef0
{
    virtual ~FUN_009daef0();
    int pad0[6];
    NP m_kFirstNP;
    NP m_pActorNode;
    int pad1[3];
    Ptr2_006e9e20 m_pPointer;
    int pad3[4];
    _Mem_2064 m_kMemoryBuffer;
};
// Destructor that forwards the object to FUN_009daf80, passing it as a TESForm pointer.
// @fnv 0x009daef0
FUN_009daef0::~FUN_009daef0()
{
    FUN_009daf80((TESForm*)this);
}

namespace fnv_009db950 {
struct ActorPathingMessageQueue
{
    char data[0x1c];
    ActorPathingMessageQueue();
};
struct NP_0081c630
{
    void* p;
    NP_0081c630& operator=(void* v);
};
struct Sub_009057d0
{
    void* p;
};
struct MoverState
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void ClearData();
    char pad0[0x18];
    NP_0081c630 m_kFirstNP;
    NP_0081c630 m_pActorNode;
    char pad1[0x0c];
    Sub_009057d0 m_pPointer;
    char pad2[0x3e];
    bool m_bMovementComplete;
    char pad3;
    bool m_bMovementActive;
    void UpdateMovementStatus(bool failed);
    void ResetMoverState(bool clearWaiting);
};
// @fnv 0x009db950
void MoverState::ResetMoverState(bool clearWaiting)
{
    m_bMovementComplete = false;
    ClearData();
    m_kFirstNP = 0;
    if (m_bMovementActive)
    {
        reinterpret_cast<::FakeHolder *>(&(m_pPointer))->AssignObject(new ActorPathingMessageQueue());
        if (clearWaiting)
            m_bMovementActive = false;
    }
    m_pActorNode = 0;
    UpdateMovementStatus(false);
    ((TESForm*)this)->TESForm::ClearData();
}
}  // namespace fnv_009db950

struct PathingRequestHelper
{
    int data[0x2a];
    PathingRequestHelper();
    virtual ~PathingRequestHelper();
};
struct Tgt_b
{
    char pad[0x28];
    void* pActor;
    bool FUN_009dba50(intptr_t a, intptr_t b, intptr_t c, float d, intptr_t e);
};
// Builds a PathingRequestHelper via SetupPathingRequest from pActor and the given arguments, then returns the result of FUN_009dba30 on it.
// @fnv 0x009dba50
bool Tgt_b::FUN_009dba50(intptr_t aiArg1, intptr_t aiArg2, intptr_t aiArg3, float afArg4, intptr_t aiArg5)
{
    PathingRequestHelper request;
    ::fnv_009dbc90::SetupPathingRequest((::Actor *)(pActor), (::fnv_009dbc90::PathingRequest *)(::PathingRequestHelper *)(&request), (*(const ::NiPoint3 *)(aiArg1)), (::TESObjectCELL *)(aiArg2), (::TESWorldSpace *)(aiArg3), afArg4, (void *)(aiArg5));
    return reinterpret_cast<::FUN_009dba30_fix *>(this)->FUN_009dba30((const ::PathingRequest *)(::PathingRequestHelper *)(&request));
}

namespace fnv_009dbb60 {
struct PathingRequestHelper
{
    int data[0x2a];
    PathingRequestHelper();
    virtual ~PathingRequestHelper();
};
struct Tgt_b
{
    char pad[0x28];
    void* pActor;
    bool FUN_009dbb60(intptr_t a, intptr_t b, intptr_t c, float d, float e, intptr_t f);
};
// @fnv 0x009dbb60
bool Tgt_b::FUN_009dbb60(intptr_t aiArg1, intptr_t aiArg2, intptr_t aiArg3, float afValue, float afArg4, intptr_t aiArg5)
{
    PathingRequestHelper request;
    ::fnv_009dbc90::SetupPathingRequest((::Actor *)(pActor), (::fnv_009dbc90::PathingRequest *)(::fnv_009dbb60::PathingRequestHelper *)(&request), (*(const ::NiPoint3 *)(aiArg1)), (::TESObjectCELL *)(aiArg2), (::TESWorldSpace *)(aiArg3), afArg4, (void *)(aiArg5));
    ::SetTargetAngle((char *)&(request), afValue);
    return reinterpret_cast<::FUN_009dba30_fix *>(this)->FUN_009dba30((const ::PathingRequest *)(::fnv_009dbb60::PathingRequestHelper *)(&request));
}
}  // namespace fnv_009dbb60

namespace fnv_00564db0 {
struct TESObjectREFR
{
};
struct ArrSI
{
};

struct FUN_00564db0_cls
{
    void FUN_00564db0(bool abVal);
};

// @fnv 0x00564db0
void FUN_00564db0_cls::FUN_00564db0(bool abVal)
{
    intptr_t iflags = SimpleArraySize((((ArrSI*)this)));
    if (abVal)
        iflags |= 0x40000;
    else
        iflags &= 0xfffbffff;
    reinterpret_cast<::TESRegionGrassObject *>((((TESObjectREFR*)this)))->AssignLandTexture((::TESLandTexture *)(iflags));
}
}  // namespace fnv_00564db0

struct TypeValueCount
{
    int iType;
    float fValue;
    int iCount;
};
struct FUN_00691c90_shell
{
    virtual ~FUN_00691c90_shell();
    TypeValueCount* pBuffer;
    unsigned int iSize;
    unsigned int iAllocSize;
    void FUN_00691c90(unsigned int auiIndex, unsigned int auiCount);
};
// @fnv 0x00691c90
void FUN_00691c90_shell::FUN_00691c90(unsigned int auiIndex, unsigned int auiCount)
{
    unsigned int uiMoveCount = FUN_0042f5a0(iSize - auiIndex - auiCount, auiCount);
    reinterpret_cast<::FUN_0072ba80_shell *>(this)->FUN_0072ba80(&pBuffer[auiIndex], auiCount);
    reinterpret_cast<::FUN_006dc6e0_Class *>(this)->FUN_006dc6e0((char *)(::TypeValueCount *)(&pBuffer[auiIndex]), (char *)(::TypeValueCount *)(pBuffer + iSize - uiMoveCount), uiMoveCount);
    iSize -= auiCount;
}

struct FUN_006d3ae0
{
    void SetValue(float value);
};

// @fnv 0x006d3ae0
void FUN_006d3ae0::SetValue(float value)
{
    *(float*)((char*)this + 0x68) = value;
}

struct FUN_009de060_Class
{
    unsigned char m_071;
    int m_038;
    void FUN_009de060(int param);
};

// @fnv 0x009de060
void FUN_009de060_Class::FUN_009de060(int aiValue)
{
    *(unsigned char*)((char*)this + 0x71) = 1;
    *(int*)((char*)this + 0x38) = aiValue;
}

namespace fnv_009de160 {
struct PathingSolution;
struct ActorAvoidListNode
{
    Actor* pItem;
    ActorAvoidListNode* pNext;
};
struct Dummy_0xe4 : ActorPathHandler
{
    Dummy_0xe4(void* apActor, void* apMover);
    Actor* pActor;
    ActorMover* pMover;
    PathingSolution* pCurrentPathingSolution;
    PATH_HANDLER_RESULT eLastResult;
    float m_fFirstPathingScalar;
    float m_fSecondPathingScalar;
    NiPoint3 m_kPathVector1;
    NiPoint3 m_kPathVector2;
    NiPoint3 m_kPathVector3;
    NiPoint3 m_kActorPosition;
    NiPoint3 m_kPathVector4;
    ActorAvoidListNode ActorAvoidEntryList;
    unsigned int ByteAndFlagState;
    unsigned int m_uiPathPointIndex;
    float m_fPathValue1;
    float m_fPathValue2;
    float m_fSplineParameter;
    float m_fPathValue4;
    float m_fPathValue5;
    int m_iPathValue1;
    float m_fPathValue6;
    float m_fPathValue7;
    float m_fPathValue8;
    float m_fPathValue9;
    float m_fPathValue10;
    float m_fPathValue11;
    float m_fPathValue12;
    float m_fPathValue13;
    NiPoint3 m_kPathVector5;
    float m_fPathValue14;
    float m_fPathValue15;
    float m_fPathValue16;
    float m_fPathValue17;
    float m_fPathValue18;
    bool m_bHasPathingSolution;
    bool m_bPathingRequestPending;
    float m_fElapsedTime;
    int eState;
    int m_iPathParameter1;
    int m_iPathParameter2;
    int m_iPathValue2;
    TESObjectREFR* m_pPathTargetReference;
    bool m_bPathFlag1;
    bool m_bPathFlag2;
    float fDoorWaitTime;
};
struct FUN_009de160_shell : ActorMover
{
    void SetMoveTarget(NiPoint3 aTarget);
};
// @fnv 0x009de160
void FUN_009de160_shell::SetMoveTarget(NiPoint3 aTarget)
{
    m_kLookAtTargetPosition = aTarget;
    m_bHasLookAtTarget = true;
    if (((MobileObject*)*(Actor**)&this->unk28)->GetCurrentProcessLevel())
        return;
    if (!m_pPathHandler)
        m_pPathHandler = new Dummy_0xe4(*(Actor**)&this->unk28, this);
    ((TESForm*)this)->TESForm::ClearData();
}
}  // namespace fnv_009de160

struct FUN_009deff0_Class
{
    void SetFlagA3(bool b);
};
// @fnv 0x009deff0
void FUN_009deff0_Class::SetFlagA3(bool abValue)
{
    ((char*)this)[0xa3] = abValue;
}

namespace fnv_009dfb80 {
struct ActorPathingMessageQueue
{
    ActorPathingMessageQueue();
    void* vtable;
    unsigned int m_uiRefCount;
    void* pHead;
    void* pTail;
    unsigned int iCount;
    void* pLock;
    unsigned int m_uiMessageCount;
};
struct NP
{
    NP& operator=(void*);
};
struct Sub_009057d0
{
};
struct PathHandlerBase
{
    virtual ~PathHandlerBase();
};
struct FUN_009dfb80_t : ActorMover
{
    void ResetPathingState(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x009dfb80
void FUN_009dfb80_t::ResetPathingState(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (m_bMovementActive)
        reinterpret_cast<::FakeHolder *>((((Sub_009057d0*)((char*)this + 0x30))))->AssignObject(new ActorPathingMessageQueue);
    eState = 0;
    *(NP*)&request = 0;
    *(NP*)&m_pActorNode = 0;
    delete (PathHandlerBase*)m_pPathHandler;
    m_pPathHandler = 0;
    this->unk34 = 0x101;
    UpdateMovementStatus(false);
    *(unsigned short*)((char*)this + 0x40) = 0xffff;
    *(unsigned short*)((char*)this + 0x42) = 0xffff;
    m_bMovementStateFlag = false;
    m_bMovementComplete = false;
    m_bMovementActive = false;
    m_bMovementPaused = false;
    m_kLookAtTargetPosition = ::NiPoint3::ZERO;
    m_kPathingDelta = ::NiPoint3::ZERO;
    m_bHasLookAtTarget = false;
    m_bHasMovementData = false;
    *(bool*)((char*)this + 0x78) = false;
    m_bHasPathingDelta = false;
    m_uiMovementFlags = 0;
    m_uiMovementMode = 0;
    this->unk2c = 0;
    *(int*)((char*)this + 0x84) = 0;
    *(unsigned int*)((char*)this + 0x7c) = 0;
    *(unsigned int*)((char*)this + 0x80) = 0;
}
}  // namespace fnv_009dfb80

struct SeqObj
{
};

struct FUN_0045cec0_Class
{
    void FUN_0045cec0();
};

// @fnv 0x0045cec0
void FUN_0045cec0_Class::FUN_0045cec0()
{
    if (*(void**)this != 0)
    {
        reinterpret_cast<::WaitableObject *>((((SeqObj*)*(void**)this)))->FUN_00401970();
    }
}

struct FUN_009dfd50Class
{
};

struct FUN_009ddb30Class
{
    virtual void FUN_009ddb30();
};

// @fnv 0x009ddb30
void FUN_009ddb30Class::FUN_009ddb30()
{
    reinterpret_cast<::PathBuilder *>((((FUN_009dfd50Class*)((char*)this + 8))))->FUN_009dfd50();
}

namespace fnv_009dbb10 {
struct LowProcess
{
    TESSound* GetTarget();
};
struct Tgt_b
{
    bool FUN_009dbb10(TESObjectREFR*, float, int);
};
// @fnv 0x009dbb10
bool Tgt_b::FUN_009dbb10(TESObjectREFR* apRef, float afValue, int aiValue)
{
    return reinterpret_cast<::Tgt_b *>(this)->FUN_009dba50((intptr_t)apRef->GetPos(), (intptr_t)((LowProcess*)apRef)->GetTarget(), (intptr_t)((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((void *)(apRef))->FUN_00575d70())),
                        afValue, aiValue);
}
}  // namespace fnv_009dbb10

class TESSound;
class TESObjectREFR;
struct LowProcess
{
    TESSound* GetTarget();
public:
    ::TESObjectREFR *GetActiveCombatTarget();
};
struct H009dbc30
{
    void FUN_009dbc30(TESObjectREFR*, float, intptr_t);
};
// Calls FUN_009dbb60 with the reference's position, target sound, world space, Z angle, and the two given values.
// @fnv 0x009dbc30
void H009dbc30::FUN_009dbc30(TESObjectREFR* apReference, float afValue, intptr_t aiValue)
{
    reinterpret_cast<::fnv_009dbb60::Tgt_b *>(this)->FUN_009dbb60((intptr_t)(apReference->GetPos()), (intptr_t)(((LowProcess*)apReference)->GetTarget()), (intptr_t)(((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((void *)(apReference))->FUN_00575d70()))),
                 (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(apReference))->GetData())).z, afValue, aiValue);
}

struct Inner009dcab0
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual int f12();
};
struct Unk009dcab0
{
    char _pad[36];
    Inner009dcab0* p;
    int FUN_009dcab0();
};
// Returns the value from the inner object's f12() if p is non-null, otherwise returns 0.
// @fnv 0x009dcab0
int Unk009dcab0::FUN_009dcab0()
{
    if (p != 0)
        return p->f12();
    else
        return 0;
}

struct Flt
{
    int val;
    operator unsigned int();
};
struct Obj009dcb30
{
    virtual bool f00();
    virtual bool f01();
    virtual bool f02();
    virtual bool f03();
    virtual bool f04();
    virtual bool f05();
    virtual bool f06();
    virtual bool f07();
    virtual bool f08();
    virtual bool f09();
    virtual bool f10();
    virtual bool f11();
    virtual bool f12();
    virtual bool f13();
    virtual bool f14();
    virtual bool f15();
};
struct Holder009dcb30
{
    char _pad[0x20];
    Flt _f;
    Obj009dcb30* _o;
    bool FUN_009dcb30();
};
// Returns true if _o is null, _f is zero, or the NiNode at _f fails FUN_009dc530; otherwise returns _o->f15().
// @fnv 0x009dcb30
bool Holder009dcb30::FUN_009dcb30()
{
    if (_o && (unsigned int)_f && reinterpret_cast<::Mover *>((((NiNode*)(uintptr_t)_f)))->FUN_009dc530())
        return _o->f15();
    return true;
}

namespace fnv_009dcb90 {
struct Flt
{
    int _x;
    operator unsigned int();
};
struct SlotObj
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual bool vf16();
};
struct MyHolder
{
    char _pad[0x20];
    Flt _f;
    SlotObj* _p;
    bool FUN_009dcb90();
};
// Returns true if _p is set, _f is non-zero and its FUN_009dc530 check passes, then returns _p->vf16(); otherwise returns false.
// @fnv 0x009dcb90
bool MyHolder::FUN_009dcb90()
{
    if (_p && (unsigned int)_f && reinterpret_cast<::Mover *>((((NiNode*)(uintptr_t)_f)))->FUN_009dc530())
        return _p->vf16();
    return 0;
}
}  // namespace fnv_009dcb90

struct Handler_9dcbf0
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual float f7();
};
struct Outer_9dcbf0
{
    char _pad[0x24];
    Handler_9dcbf0* pHandler;
    float FUN_009dcbf0();
};
// Returns the value from pHandler if it is set, otherwise returns 0.0f.
// @fnv 0x009dcbf0
float Outer_9dcbf0::FUN_009dcbf0()
{
    if (pHandler)
        return pHandler->f7();
    else
        return 0.0f;
}

struct FUN_009dcc20_Iface
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual void F3();
    virtual void F4();
    virtual void F5();
    virtual float F6();
};
struct FUN_009dcc20_Holder
{
    char _pad[0x24];
    FUN_009dcc20_Iface* mPtr;
    float FUN_009dcc20();
};
// Returns the value from mPtr by calling its F6 method, or 0.0f when mPtr is null.
// @fnv 0x009dcc20
float FUN_009dcc20_Holder::FUN_009dcc20()
{
    if (mPtr)
        return mPtr->F6();
    else
        return 0.0f;
}

struct Handler_009dcc50
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual float f10();
};
struct StandIn_009dcc50
{
    unsigned char _pad[0x24];
    Handler_009dcc50* m_pPathHandler;
    float FUN_009dcc50();
};
// Returns the value from the handler pointer if set, otherwise returns 0.0f.
// @fnv 0x009dcc50
float StandIn_009dcc50::FUN_009dcc50()
{
    if (m_pPathHandler)
        return m_pPathHandler->f10();
    else
        return 0.0f;
}

namespace fnv_009dccf0 {
struct Flt
{
    int x;
    operator unsigned int();
};
struct Holder
{
    virtual bool v00()
    {
        return false;
    }
    virtual bool v01()
    {
        return false;
    }
    virtual bool v02()
    {
        return false;
    }
    virtual bool v03()
    {
        return false;
    }
    virtual bool v04()
    {
        return false;
    }
    virtual bool v05()
    {
        return false;
    }
    virtual bool v06()
    {
        return false;
    }
    virtual bool v07()
    {
        return false;
    }
    virtual bool v08()
    {
        return false;
    }
    virtual bool v09()
    {
        return false;
    }
    virtual bool v10()
    {
        return false;
    }
    virtual bool v11()
    {
        return false;
    }
    virtual bool v12()
    {
        return false;
    }
    virtual bool v13()
    {
        return false;
    }
    virtual bool v14()
    {
        return false;
    }
    virtual bool v15()
    {
        return false;
    }
    virtual bool v16()
    {
        return false;
    }
    virtual bool v17()
    {
        return false;
    }
};
struct S009dccf0
{
    char _pad[0x20];
    Flt m_kHandle;
    Holder* _h;
    bool FUN_009dccf0();
};
// @fnv 0x009dccf0
bool S009dccf0::FUN_009dccf0()
{
    if (!(unsigned int)m_kHandle || !reinterpret_cast<::Mover *>((((NiNode*)(uintptr_t)m_kHandle)))->FUN_009dc530())
        return false;
    return _h->v17();
}
}  // namespace fnv_009dccf0

struct FUN_009de040_class
{
    void ClearFlags(unsigned int mask);
};

// @fnv 0x009de040
void FUN_009de040_class::ClearFlags(unsigned int mask)
{
    *(unsigned int*)((char*)this + 0x34) &= ~mask;
}

namespace fnv_009de110 {
struct Flt
{
    int v;
    operator unsigned int();
};
struct Vt009
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual bool func(int a, int b);
};
struct Unk
{
    char _pad[0x20];
    Flt flt;
    Vt009* ptr;
    bool FUN_009de110(int a, int b);
};
// Returns false if flt is zero or ptr is null; otherwise calls ptr->func(a, b) and returns its result.
// @fnv 0x009de110
bool Unk::FUN_009de110(int aiArg1, int aiArg2)
{
    if ((unsigned int)flt && ptr)
        return ptr->func(aiArg1, aiArg2);
    return false;
}
}  // namespace fnv_009de110

struct Unk009DE3A0
{
    void SetFormID(TESForm*);
};
// Stores the form's form ID at offset 0x2c, or 0 when pForm is null.
// @fnv 0x009de3a0
void Unk009DE3A0::SetFormID(TESForm* pForm)
{
    *(unsigned int*)((char*)this + 0x2c) = pForm ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pForm))->FUN_0084e3a0())) : 0;
}

namespace fnv_009de3e0 {
struct Flt
{
    operator unsigned int();
};
struct StandIn009DE3E0
{
    char _pad[0x20];
    Flt m_kHandle;
    bool FUN_009de3e0();
};
// @fnv 0x009de3e0
bool StandIn009DE3E0::FUN_009de3e0()
{
    if ((unsigned int)m_kHandle && reinterpret_cast<::Mover *>((((NiNode*)(uintptr_t)m_kHandle)))->FUN_009dc530())
        return true;
    return false;
}
}  // namespace fnv_009de3e0

class TESObjectCELL;
struct PathingLocation
{
public:
    ::PathingLocation &operator=(const ::PathingLocation &);
public:
    ::TESObjectCELL *GetContainingCell();
public:
    bool HasValidTriangle_006dd6a0();
public:
    void ResetLocation();
};

struct FUN_009de460
{
    char pad[0x44];
    PathingLocation m_pathingLocation;
    PathingLocation* GetPathingLocation();
};

// Returns a pointer to m_pathingLocation if its FUN_006a9520 check fails, otherwise returns null.
// @fnv 0x009de460
PathingLocation* FUN_009de460::GetPathingLocation()
{
    if (!reinterpret_cast<::FUN_006a9520_Class *>(&(m_pathingLocation))->FUN_006a9520())
        return &m_pathingLocation;
    return 0;
}

namespace fnv_006e29f0 {
struct _Mem_2064
{
    char pad[0x28];
    ~_Mem_2064();
};
struct PathingLocation : _Mem_2064
{
    PathingLocation(TESObjectREFR* ref);
    PathingLocation& operator=(const PathingLocation& o);
};
struct FUN_006d3ae0
{
};
struct PathingActorData
{
    PathingActorData& operator=(const PathingActorData& o);
};
struct FUN_006e2b50_shell
{
};
struct FUN_006e2b70_shell
{
};
struct FUN_006e2b90
{
};
struct FUN_006e2bb0_shell
{
};
struct FUN_008be280_shell
{
};
struct FUN_006e29f0_sub
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
    virtual bool v10();
};
struct FUN_006e29f0_shell
{
    void InitFromActor(Actor* apActor);
};

// Copies pathing location, value, flags and actor-base data from apActor into this object.
// @fnv 0x006e29f0
void FUN_006e29f0_shell::InitFromActor(Actor* apActor)
{
    reinterpret_cast<::PathingLocation *>((void *)&(const ::fnv_006e29f0::PathingLocation &)(*(PathingLocation*)((char*)this + 0xc)))->operator=((const ::PathingLocation &)((const ::fnv_006e29f0::PathingLocation &)(PathingLocation((TESObjectREFR*)apActor))));
    reinterpret_cast<::FUN_006d3ae0 *>((((FUN_006d3ae0*)this)))->SetValue((float)(reinterpret_cast<::fnv_008be280::FloatValueProvider *>((((FUN_008be280_shell*)apActor)))->FUN_008be280() * ::DAT_010290b8));
    reinterpret_cast<::PathingActorData *>((void *)&(const ::fnv_006e29f0::PathingActorData &)(*(PathingActorData*)this))->operator=((const ::PathingActorData &)(*(PathingActorData*)apActor));
    reinterpret_cast<::FUN_006e2b70_shell *>((((FUN_006e2b70_shell*)this)))->SetCanSwim(reinterpret_cast<::FUN_0087f350_shell *>((apActor))->FUN_0087f350());
    reinterpret_cast<::FUN_006e2b90 *>((((FUN_006e2b90*)this)))->SetFlag(reinterpret_cast<::FUN_0087f390_shell *>((apActor))->FUN_0087f390());
    if (apActor->Unk_87())
    {
        reinterpret_cast<::FUN_006e2b50_shell *>((((FUN_006e2b50_shell*)this)))->SetCantOpenDoors(((FUN_006e29f0_sub*)((char*)apActor->GetActorBase() + 0x30))->v10());
    }
    reinterpret_cast<::FUN_006e2bb0_shell *>((((FUN_006e2bb0_shell*)this)))->SetInitialPathHeading(apActor->GetCurrentTargetDistance(false));
}
}  // namespace fnv_006e29f0

namespace fnv_009dbc90 {
class _Mem_2064
{
  public:
    ~_Mem_2064();
};

class PathingLocation : public _Mem_2064
{
  public:
    PathingLocation(NiPoint3 const& arPoint, TESObjectCELL* apCell, TESWorldSpace* apWorldSpace);
    int data[10];
};

class PathingRequest
{
  public:
    void SetDestination(PathingLocation* apDest);
    void SetCenterRadius(float afRadius);
};

struct PathingRequest_b
{
    void SetAvoidNodeArray(void* apAvoidNodes);
};

struct FUN_006e2b50_shell
{
};

struct FUN_006e2b70_shell
{
};

struct FUN_006e2b90
{
};

struct TESPackage
{
};

struct Dummy
{
};


struct ActorBaseComponent30
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual bool v10();
};

// @fnv 0x009dbc90
void __cdecl SetupPathingRequest(Actor* apActor, PathingRequest* apRequest, NiPoint3 const& aGoalLocation,
                                 TESObjectCELL* apCell, TESWorldSpace* apWorldSpace, float afTargetRadius,
                                 void* apAvoidNodes)
{
    PathingLocation pathingLocation(aGoalLocation, apCell, apWorldSpace);
    reinterpret_cast<::fnv_006e29f0::FUN_006e29f0_shell *>((apRequest))->InitFromActor(apActor);
    apRequest->SetDestination(&pathingLocation);
    if (afTargetRadius <= 0.0)
    {
        apRequest->SetCenterRadius(::TESPackage::GetPackageDefaultFloat());
    }
    else
    {
        apRequest->SetCenterRadius(afTargetRadius);
    }
    ((PathingRequest_b*)apRequest)->SetAvoidNodeArray(apAvoidNodes);
    if (apActor->Unk_87())
    {
        reinterpret_cast<::FUN_006e2b50_shell *>((((FUN_006e2b50_shell*)apRequest)))->SetCantOpenDoors(((ActorBaseComponent30*)((char*)apActor->GetActorBase() + 0x30))->v10());
    }
    reinterpret_cast<::FUN_006e2b70_shell *>((((FUN_006e2b70_shell*)apRequest)))->SetCanSwim(reinterpret_cast<::FUN_005f0b50_shell *>((apActor->GetActorBase()))->FUN_005f0b50());
    reinterpret_cast<::FUN_006e2b90 *>((((FUN_006e2b90*)apRequest)))->SetFlag(reinterpret_cast<::Dummy *>((((Dummy*)apActor->GetActorBase())))->FUN_005f0c40());
}
}  // namespace fnv_009dbc90

namespace fnv_009dc7f0 {
struct BGSSaveLoadGame
{
};
struct Flt
{
    operator unsigned int();
};
struct PathingSolution
{
};
struct ActorStub_009dc7f0
{
    void TryMove(int);
};
struct VObj_009dc7f0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual bool v0d();
};
struct DoorTeleportSpaceReceiver
{
    char pad00[0x20];
    Flt kPath;
    char pad21[3];
    VObj_009dc7f0* pObj;
    Actor* pActor;
    char pad2c[0x14];
    unsigned short usNode;
    unsigned short usLastNode;
    char pad44[0x31];
    bool bFlag;
    void UpdateTeleportPathState();
};
// Updates the actor's sit/sleep handling and the teleport path flag based on the path object's state and node counts.
// @fnv 0x009dc7f0
void DoorTeleportSpaceReceiver::UpdateTeleportPathState()
{
    if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture()))->GetSitSleepState() == 4 || ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture()))->GetSitSleepState() == 9)
        return;
    else if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor))->GetBaseTexture()))->GetSitSleepState())
    {
        reinterpret_cast<::fnv_0088d640::FUN_0088d640_shell *>((((ActorStub_009dc7f0*)pActor)))->FUN_0088d640();
        return;
    }
    if (!pObj || reinterpret_cast<::fnv_009dcd40::Mover *>(this)->FUN_009dcd40())
    {
        if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_009dc7f0::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
            ((ActorStub_009dc7f0*)pActor)->TryMove(0);
    }
    else if (bFlag && pObj->v0d())
    {
        if (!kPath)
            return;
        if (usNode == usLastNode && usNode < ::FUN_005a4320((char *)(((PathingSolution*)(uintptr_t)kPath))) - 1)
            return;
        bFlag = false;
    }
    else
    {
        if (pObj->v0d())
            return;
        bFlag = true;
    }
}
}  // namespace fnv_009dc7f0

namespace fnv_009df8c0 {
struct ActiveEffect;
struct Actor;
struct BGSIdleCollection;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct CombatAction;
struct CombatGoal;
struct ActorCombatGroup;
struct CombatPlan;
struct CombatBehavior;
struct CombatProcedure;
struct CombatState;
struct IDebugText;
struct InventoryStackRecord;
struct ThreeByThreeMatrix;
struct NiQuaternion;
struct LocationDescriptor;
struct DurationData;
struct PackageTargetRecord;
struct Projectile;
struct Script;
struct TESCombatStyle;
struct PerkEntryConditionSet;
struct TESEscortPackageData;
struct TESFile;
struct TESIdleForm;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESPackageData;
struct TESPatrolPackageData;
struct TESTopic;
struct TESUseWeaponPackageData;
struct TESWorldSpace;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
struct FUN_009df8c0_shell : public ActorMover
{
    void FUN_009df8c0(BGSLoadFormBuffer*);
};

struct CombatController
{
    ActorCombatGroup* GetCombatGroup();
};
class BSPortalGraph;
struct HighActorCullerCell
{
};
struct GO
{
    GO(intptr_t);
    ~GO();
    void* p;
};
struct Flt
{
    operator unsigned int();
};
class PathingActorData
{
  public:
    PathingActorData& operator=(const PathingActorData&);
};
struct FUN_009d9ec0_shell
{
};
struct SPathHandler
{
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void h7();
    virtual void h8();
    virtual void h9();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual void h13();
    virtual void h14();
    virtual void h15();
    virtual void h16();
    virtual void h17();
    virtual void h18();
    virtual void h19();
    virtual void h20();
    virtual void h21();
    virtual void h22();
    virtual void h23();
    virtual void h24();
    virtual void h25();
    virtual void h26();
    virtual void h27();
    virtual void h28();
    virtual void h29();
    virtual void h30();
    virtual void h31();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct SPathReq
{
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual int GetType();
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct SActor
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
    virtual void a64();
    virtual void a65();
    virtual void a66();
    virtual void a67();
    virtual void a68();
    virtual void a69();
    virtual void a70();
    virtual void a71();
    virtual void a72();
    virtual void a73();
    virtual void a74();
    virtual void a75();
    virtual void a76();
    virtual void a77();
    virtual void a78();
    virtual void a79();
    virtual void a80();
    virtual void a81();
    virtual void a82();
    virtual void a83();
    virtual void a84();
    virtual void a85();
    virtual void a86();
    virtual void a87();
    virtual void a88();
    virtual void a89();
    virtual void a90();
    virtual void a91();
    virtual void a92();
    virtual void a93();
    virtual void a94();
    virtual void a95();
    virtual void a96();
    virtual void a97();
    virtual void a98();
    virtual void a99();
    virtual void a100();
    virtual void a101();
    virtual void a102();
    virtual void a103();
    virtual void a104();
    virtual void a105();
    virtual void a106();
    virtual void a107();
    virtual void a108();
    virtual void a109();
    virtual void a110();
    virtual void a111();
    virtual void a112();
    virtual void a113();
    virtual void a114();
    virtual void a115();
    virtual void a116();
    virtual void a117();
    virtual void a118();
    virtual void a119();
    virtual void a120();
    virtual void a121();
    virtual void a122();
    virtual void a123();
    virtual void a124();
    virtual void a125();
    virtual void a126();
    virtual void a127();
    virtual void a128();
    virtual void a129();
    virtual void a130();
    virtual void a131();
    virtual void a132();
    virtual void a133();
    virtual void a134();
    virtual void a135();
    virtual void a136();
    virtual void a137();
    virtual void a138();
    virtual void a139();
    virtual void a140();
    virtual void a141();
    virtual void a142();
    virtual void a143();
    virtual void a144();
    virtual void a145();
    virtual void a146();
    virtual void a147();
    virtual void a148();
    virtual void a149();
    virtual void a150();
    virtual void a151();
    virtual void a152();
    virtual void a153();
    virtual void a154();
    virtual void a155();
    virtual void a156();
    virtual void a157();
    virtual void a158();
    virtual void a159();
    virtual void a160();
    virtual void a161();
    virtual void a162();
    virtual void a163();
    virtual void a164();
    virtual void a165();
    virtual void a166();
    virtual void a167();
    virtual void a168();
    virtual void a169();
    virtual void a170();
    virtual void a171();
    virtual void a172();
    virtual void a173();
    virtual void a174();
    virtual void a175();
    virtual void a176();
    virtual void a177();
    virtual void a178();
    virtual void a179();
    virtual void a180();
    virtual void a181();
    virtual void a182();
    virtual void a183();
    virtual void a184();
    virtual void a185();
    virtual void a186();
    virtual void a187();
    virtual void a188();
    virtual void a189();
    virtual void a190();
    virtual void a191();
    virtual void a192();
    virtual void a193();
    virtual void a194();
    virtual void a195();
    virtual void a196();
    virtual void a197();
    virtual void a198();
    virtual void a199();
    virtual void a200();
    virtual void a201();
    virtual void a202();
    virtual void a203();
    virtual void a204();
    virtual void a205();
    virtual void a206();
    virtual void a207();
    virtual void a208();
    virtual void a209();
    virtual void a210();
    virtual void a211();
    virtual void a212();
    virtual void a213();
    virtual void a214();
    virtual void a215();
    virtual void a216();
    virtual void a217();
    virtual void a218();
    virtual void a219();
    virtual void a220();
    virtual void a221();
    virtual void a222();
    virtual void a223();
    virtual void a224();
    virtual void a225();
    virtual void a226();
    virtual void a227();
    virtual void a228();
    virtual void a229();
    virtual void a230();
    virtual void a231();
    virtual void a232();
    virtual void a233();
    virtual void a234();
    virtual void a235();
    virtual void a236();
    virtual void a237();
    virtual void a238();
    virtual void a239();
    virtual void a240();
    virtual void a241();
    virtual void a242();
    virtual void a243();
    virtual void a244();
    virtual void a245();
    virtual void a246();
    virtual void a247();
    virtual void a248();
    virtual void a249();
    virtual void a250();
    virtual void a251();
    virtual void a252();
    virtual void a253();
    virtual void a254();
    virtual void a255();
    virtual void a256();
    virtual void a257();
    virtual void a258();
    virtual void a259();
    virtual void a260();
    virtual void a261();
    virtual void a262();
    virtual void a263();
    virtual void a264();
    virtual void a265();
    virtual CombatController* GetCombatController();
};

struct MoverView
{
    char pad[0x1c];
    Flt m_kFirstNP;
    int pad2;
    SPathHandler* m_pPathHandler;
    SActor* pActor;
};
// @fnv 0x009df8c0
void FUN_009df8c0_shell::FUN_009df8c0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (((MoverView*)this)->m_pPathHandler)
        ((MoverView*)this)->m_pPathHandler->LoadGame(apLoadGameBuffer);
    if (((MoverView*)this)->m_kFirstNP)
    {
        if (((SPathReq*)(uintptr_t)((MoverView*)this)->m_kFirstNP)->GetType() == 5)
        {
            FUN_009d9ec0_shell* plosRequest = (FUN_009d9ec0_shell*)(uintptr_t)((MoverView*)this)->m_kFirstNP;
            CombatController* pcombatController = ((MoverView*)this)->pActor->GetCombatController();
            if (pcombatController && ((::fnv_009df8c0::ActorCombatGroup *)(reinterpret_cast<::EffectSetting *>((pcombatController))->GetCastSound())))
            {
                GO kGraph((intptr_t)((::fnv_009df8c0::BSPortalGraph *)(reinterpret_cast<::fnv_009d9f20::FUN_009d9f20_shell *>((((HighActorCullerCell*)((::fnv_009df8c0::ActorCombatGroup *)(reinterpret_cast<::EffectSetting *>((pcombatController))->GetCastSound())))))->FUN_009d9f20())));
                reinterpret_cast<::FUN_009d9ec0_shell *>((plosRequest))->AssignAtOffsetB0(&kGraph);
            }
        }
        ((SPathReq*)(uintptr_t)((MoverView*)this)->m_kFirstNP)->LoadGame(apLoadGameBuffer);
        reinterpret_cast<::PathingActorData *>((void *)&(const ::fnv_009df8c0::PathingActorData &)(*(PathingActorData*)(uintptr_t)((MoverView*)this)->m_kFirstNP))->operator=((const ::PathingActorData &)(*(PathingActorData*)((MoverView*)this)->pActor));
    }
}
}  // namespace fnv_009df8c0

struct PathingRequest;
struct PathingSolution;
struct FUN_006d0b80
{
    FUN_006d0b80(PathingRequest*, PathingSolution*);
    ~FUN_006d0b80();
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
    int f5;
    int f6;
    int f7;
    int f8;
    int f9;
    int f10;
    int f11;
    int f12;
};
// Constructs a FUN_006d0b80 from the request and solution, then returns the result of FUN_006c93d0 on it.
// @fnv 0x006d53b0
int FUN_006d53b0(PathingRequest* pRequest, PathingSolution* b)
{
    FUN_006d0b80 obj(pRequest, b);
    return ::fnv_006c93d0::FUN_006c93d0((::fnv_006c93d0::Dummy_006c93a0 *)&(obj));
}

struct TESForm;
void FUN_009daf80(TESForm*);
struct Sol11
{
};
struct QueueVt11;
struct Req11
{
};
struct Node11
{
    void* FUN_00717e50();
};
struct Loc11
{
    int m_00;
    Loc11& operator=(const Loc11&);
};
template <class T> class NiPointer;
template <> class NiPointer<Sol11>
{
  public:
    Sol11* m_pObject;
    NiPointer();
    NiPointer(const NiPointer<Sol11>&);
    ~NiPointer();
    NiPointer& operator=(const NiPointer<Sol11>&);
    operator Sol11*() const;
};
template <> class NiPointer<Req11>
{
  public:
    Req11* m_pObject;
    NiPointer();
    NiPointer(const NiPointer<Req11>&);
    ~NiPointer();
    NiPointer& operator=(const NiPointer<Req11>&);
    operator Req11*() const;
};
template <> class NiPointer<QueueVt11>
{
  public:
    QueueVt11* m_pObject;
    NiPointer();
    NiPointer(const NiPointer<QueueVt11>&);
    ~NiPointer();
    NiPointer& operator=(const NiPointer<QueueVt11>&);
    operator QueueVt11*() const;
};
struct Msg11
{
    int m_type;
    NiPointer<Sol11> m_sol;
    Msg11();
    ~Msg11();
};
struct ActorVt11
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool v22c(int);
    virtual bool v230();
};
struct ProcVt11
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual int v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual int v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual int v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual void v6d4();
    virtual void v6d8();
    virtual void v6dc();
    virtual void v6e0();
    virtual void v6e4();
    virtual void v6e8();
    virtual void v6ec();
    virtual void v6f0();
    virtual void v6f4();
    virtual void v6f8();
    virtual bool v6fc();
};
struct HandlerVt11
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual int v10(float);
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v70();
};
struct QueueVt11
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual bool v10(void*);
};
struct Proc11 : public ProcVt11
{
};
struct Actor11 : public ActorVt11
{
};
struct Mover11
{
    void* m_vt;
    float m_look[3];
    float m_delta[3];
    NiPointer<Req11> m_req;
    NiPointer<Sol11> m_path;
    HandlerVt11* m_handler;
    Actor11* m_actor;
    int m_2c;
    NiPointer<QueueVt11> m_queue;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    Loc11 m_loc;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_uiContentCount;
    unsigned char m_failed;
    unsigned char m_71;
    unsigned char m_72;
    unsigned char m_73;
    unsigned char m_waiting;
    unsigned char m_75;
    unsigned char m_76;
    unsigned char m_77;
    unsigned char m_78;
    void SetEnabled(int);
    void FUN_009dc120(float f);
};

// UpdateFlagFromTarget: thiscall, void. Calls bool vslot 0x34 on the object at this+0x24.
// Stand-in layout: vptr at 0, pointer at +0x24, flag byte at +0x75.

class FUN_009dc780_target
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual bool v34();
};

class FUN_009dc780_cls
{
  public:
    virtual void unkVirtual00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    FUN_009dc780_target* m_24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    unsigned char unk74;
    bool m_75;

    void UpdateFlagFromTarget();
};

// Sets m_75 based on whether m_24 is non-null and its v34() returns non-zero; clears m_75 when v34() returns 0.
// @fnv 0x009dc780
void FUN_009dc780_cls::UpdateFlagFromTarget()
{
    if (m_24 == 0)
    {
    }
    else
    {
        if (m_75 != 0 && m_24->v34() == 0)
        {
            m_75 = 0;
        }
        else
        {
            if (m_24->v34() == 0)
            {
            }
            else
            {
                m_75 = 1;
            }
        }
    }
}

struct DcVec
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

class DcStubA
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11(DcVec* out, float f);
};

class DcStubB
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual DcVec* v125();
};

class FUN_009dcc80_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    DcStubA* m_24;
    DcStubB* m_28;
    DcVec* GetVec(DcVec* out, float f);
};

// Writes a DcVec to out via m_24->v11(out, f) when m_24 is set, otherwise copies the vector returned by m_28->v125(), and returns out.
// @fnv 0x009dcc80
DcVec* FUN_009dcc80_cls::GetVec(DcVec* out, float f)
{
    if (m_24 != 0)
    {
        m_24->v11(out, f);
        return out;
    }
    else
    {
        *out = *m_28->v125();
        return out;
    }
}

struct PkgTriple
{
    void* a;
    void* b;
    void* c;
};

class PkgSlotObj
{
  public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void ProcessOut(PkgTriple* out);
};

class PkgSlotHolder
{
  public:
    virtual void unkSlot000();
    virtual void unkSlot001();
    virtual void unkSlot002();
    virtual void unkSlot003();
    virtual void unkSlot004();
    virtual void unkSlot005();
    virtual void unkSlot006();
    virtual void unkSlot007();
    virtual void unkSlot008();
    virtual void unkSlot009();
    virtual void unkSlot010();
    virtual void unkSlot011();
    virtual void unkSlot012();
    virtual void unkSlot013();
    virtual void unkSlot014();
    virtual void unkSlot015();
    virtual void unkSlot016();
    virtual void unkSlot017();
    virtual void unkSlot018();
    virtual void unkSlot019();
    virtual void unkSlot020();
    virtual void unkSlot021();
    virtual void unkSlot022();
    virtual void unkSlot023();
    virtual void unkSlot024();
    virtual void unkSlot025();
    virtual void unkSlot026();
    virtual void unkSlot027();
    virtual void unkSlot028();
    virtual void unkSlot029();
    virtual void unkSlot030();
    virtual void unkSlot031();
    virtual void unkSlot032();
    virtual void unkSlot033();
    virtual void unkSlot034();
    virtual void unkSlot035();
    virtual void unkSlot036();
    virtual void unkSlot037();
    virtual void unkSlot038();
    virtual void unkSlot039();
    virtual void unkSlot040();
    virtual void unkSlot041();
    virtual void unkSlot042();
    virtual void unkSlot043();
    virtual void unkSlot044();
    virtual void unkSlot045();
    virtual void unkSlot046();
    virtual void unkSlot047();
    virtual void unkSlot048();
    virtual void unkSlot049();
    virtual void unkSlot050();
    virtual void unkSlot051();
    virtual void unkSlot052();
    virtual void unkSlot053();
    virtual void unkSlot054();
    virtual void unkSlot055();
    virtual void unkSlot056();
    virtual void unkSlot057();
    virtual void unkSlot058();
    virtual void unkSlot059();
    virtual void unkSlot060();
    virtual void unkSlot061();
    virtual void unkSlot062();
    virtual void unkSlot063();
    virtual void unkSlot064();
    virtual void unkSlot065();
    virtual void unkSlot066();
    virtual void unkSlot067();
    virtual void unkSlot068();
    virtual void unkSlot069();
    virtual void unkSlot070();
    virtual void unkSlot071();
    virtual void unkSlot072();
    virtual void unkSlot073();
    virtual void unkSlot074();
    virtual void unkSlot075();
    virtual void unkSlot076();
    virtual void unkSlot077();
    virtual void unkSlot078();
    virtual void unkSlot079();
    virtual void unkSlot080();
    virtual void unkSlot081();
    virtual void unkSlot082();
    virtual void unkSlot083();
    virtual void unkSlot084();
    virtual void unkSlot085();
    virtual void unkSlot086();
    virtual void unkSlot087();
    virtual void unkSlot088();
    virtual void unkSlot089();
    virtual void unkSlot090();
    virtual void unkSlot091();
    virtual void unkSlot092();
    virtual void unkSlot093();
    virtual void unkSlot094();
    virtual void unkSlot095();
    virtual void unkSlot096();
    virtual void unkSlot097();
    virtual void unkSlot098();
    virtual void unkSlot099();
    virtual void unkSlot100();
    virtual void unkSlot101();
    virtual void unkSlot102();
    virtual void unkSlot103();
    virtual void unkSlot104();
    virtual void unkSlot105();
    virtual void unkSlot106();
    virtual void unkSlot107();
    virtual void unkSlot108();
    virtual void unkSlot109();
    virtual void unkSlot110();
    virtual void unkSlot111();
    virtual void unkSlot112();
    virtual void unkSlot113();
    virtual void unkSlot114();
    virtual void unkSlot115();
    virtual void unkSlot116();
    virtual void unkSlot117();
    virtual void unkSlot118();
    virtual void unkSlot119();
    virtual void unkSlot120();
    virtual void unkSlot121();
    virtual void unkSlot122();
    virtual void unkSlot123();
    virtual void unkSlot124();
    virtual PkgTriple* GetTriple();
};

class PkgHelperObj
{
  public:
};

class FUN_009de0a0_cls
{
  public:
    unsigned int unk00[8];
    unsigned int m_20;
    PkgSlotObj* m_24;
    PkgSlotHolder* m_28;

    PkgTriple* FUN_009de0a0(PkgTriple* out);
};

// Returns a triple: copies it from m_28's GetTriple when the m_20 helper check fails or m_24 is null, otherwise lets m_24 fill it via ProcessOut.
// @fnv 0x009de0a0
PkgTriple* FUN_009de0a0_cls::FUN_009de0a0(PkgTriple* out)
{
    if (::FUN_00559450((int *)(reinterpret_cast<PkgHelperObj*>(&m_20))) == 0 || m_24 == 0)
    {
        *out = *m_28->GetTriple();
        return out;
    }
    else
    {
        m_24->ProcessOut(out);
        return out;
    }
}

struct PathCoordinate
{
};
struct PathQuery
{
    PathCoordinate* FUN_00717e50(NiPoint3*);
};
struct PathNode : NiNode
{
    PathQuery* FUN_009ddb30();
};
struct FUN_009de2b0_shell : ActorMover
{
    bool GetPathCoordinate(NiPoint3* position);
};

struct Fx_Arg
{
};

struct Fx_Obj
{
    intptr_t Lookup();
};

struct Fx_Node
{
    Fx_Obj* Find();
};

struct Fx_Sub
{
};

struct FUN_009de330_cls
{
    char unk00[0x20];
    Fx_Sub sub;

    bool ApplyNodeLookup(Fx_Arg* arg);
};

// If sub's node exists, tests it, finds its object, applies the object's lookup to arg and returns true; otherwise returns false.
// @fnv 0x009de330
bool FUN_009de330_cls::ApplyNodeLookup(Fx_Arg* arg)
{
    Fx_Obj* obj;

    if (((::Fx_Node *)(::FUN_00559450((int *)&(sub)))) != 0)
    {
        if (reinterpret_cast<::Mover *>((((::Fx_Node *)(::FUN_00559450((int *)&(sub))))))->FUN_009dc530())
        {
            obj = ((::Fx_Node *)(::FUN_00559450((int *)&(sub))))->Find();
            if (obj != 0)
            {
                reinterpret_cast<::PathingLocation *>((arg))->operator=((*(const ::PathingLocation *)(obj->Lookup())));
                return true;
            }
        }
    }
    return false;
}

struct ActorX
{
    int FUN_00931850();
};

struct ReqT
{
};

struct SolT
{
};

template <class T> struct RefPtr
{
    T* p;
    T* FUN_00559450();
};

struct HandlerX
{
    virtual ~HandlerX();
    virtual int vfn_04(float a, float b);
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58(HandlerX* a);
};

struct Pt3
{
    float x, y, z;
};

struct ThisCls
{
    void* vtable;
    Pt3 m_04;
    Pt3 m_10;
    RefPtr<ReqT> m_1c;
    RefPtr<SolT> m_20;
    HandlerX* m_24;
    ActorX* m_28;
    void* m_2c;
    void* m_30;
    void* m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned short m_40;
    unsigned short m_42;
    void* m_44;
    void* m_48;
    void* m_4c;
    void* m_50;
    void* m_54;
    void* m_58;
    void* m_5c;
    void* m_60;
    void* m_64;
    void* m_68;
    int m_6c;
    void SetEnabled(int a);
    void UpdatePathingState(float a1);
};

struct FUN_009e0190
{
    void* member00;
    void* member04;
    void* member08;
    void* member0c;
    void* member10;
    void* member14;
    void* member18;
    void* member1c;
    void* member20;
    void* member24;
    void* member28;
    void* member2c;
    void* member30;
    void* member34;
    void* member38;
    void* member3c;
    void* member40;
    void* member44;
    void* member48;
    void* member4c;
    void* member50;
    void* member54;
    void* member58;
    void* member5c;
    void* member60;
    void* member64;
    void* member68;
    void* member6c;
    void* member70;
    void* member74;
    void* member78;
    void* member7c;
    void* member80;
    void* member84;
    void* member88;
    void* member8c;
    void* member90;
    void* member94;
    void* member98;
    void* member9c;
    void* membera0;
    void* membera4;
    void* membera8;
    void* memberac;
    void* memberb0;
    void* memberb4;
    void* memberb8;
    void* memberbc;
    void* memberc0;
    void* memberc4;
    void* memberc8;
    void* membercc;
    void* memberd0;
    void* memberd4;
    void* memberd8;
    void* memberdc;
    void* membere0;
    FUN_009e0190(ActorX* a, ThisCls* b, RefPtr<SolT>& c, ReqT* d);
};

struct FUN_009ea770
{
    void* member00;
    void* member04;
    void* member08;
    void* member0c;
    void* member10;
    void* member14;
    void* member18;
    void* member1c;
    FUN_009ea770(ActorX* a, ThisCls* b, RefPtr<SolT>& c, ReqT* d);
};

class PathingRequest;
struct PathingSolution;

class PointX
{
  public:
    float x;
    float y;
    float z;
    PointX operator-(const PointX& arPoint) const;
};

class PathingLocationX
{
  public:
};

class VirtualPathingNodeX
{
  public:
    PathingLocationX& GetLocation();
};

class PathingSolutionX
{
  public:
};

class PathingRequestX
{
  public:
};

class MoverActorX
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual PointX* GetPos();
};

class ActorMoverX;

class ActorMoverX
{
  public:
    void* vtable;
    NiPoint3 m_kLookAtTargetPosition;
    NiPoint3 m_kPathingDelta;
    NiPointer<PathingRequestX> m_kFirstNP;
    NiPointer<PathingSolutionX> m_pActorNode;
    void* m_pPathHandler;
    MoverActorX* pActor;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int eState;

    int UpdatePathHandler();
    void SetPathFailed(bool abFailed);
    void HandlePathResult(int aiResult);
};
// @fnv 0x009dc590
void ActorMover::UpdateMovement(float elapsed)
{
    if (m_bMovementPaused)
        return;
    ActorPathHandler::PATH_HANDLER_RESULT result = m_pPathHandler->vfn_0c(elapsed);
    reinterpret_cast<::ActorMoverX *>(this)->HandlePathResult((*(int *)&(result)));
}

struct MovementStatus
{
};
struct MovementActor
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual void slot100();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual MovementStatus* GetStatus();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void* CanMove();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual void slot2bc();
    virtual void slot2c0();
    virtual void UpdateBlockedMovement(float);
};
struct MovementHandler
{
    virtual ~MovementHandler();
    virtual void slot04();
    virtual bool Update(float, bool);
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual bool IsValid();
};
struct MovementUpdate : Mover11
{
    bool FUN_009dce80(float delta, bool force);
};

// @fnv 0x009dce80
bool MovementUpdate::FUN_009dce80(float delta, bool force)
{
    bool result = false;
    reinterpret_cast<::fnv_009db950::MoverState *>(this)->ResetMoverState(1);
    if (((MovementActor*)m_actor)->GetStatus() && reinterpret_cast<::fnv_00495be0::PriorityAnimation *>((((MovementActor*)m_actor)->GetStatus()))->IsHighestPriority())
        m_78 = true;
    if (!reinterpret_cast<::FUN_008843a0_shell *>((((MovementActor*)m_actor)))->FUN_008843a0() || ((MovementActor*)m_actor)->CanMove())
    {
        m_uiContentCount = 6;
        result = true;
    }
    else if (!FUN_009dcae0((FUN_009dcae0_struct*)this))
    {
        m_uiContentCount = 6;
        ((MovementActor*)m_actor)->UpdateBlockedMovement(delta);
        result = true;
    }
    if (!result)
    {
        if (m_handler && !((MovementHandler*)m_handler)->IsValid())
        {
            delete (MovementHandler*)m_handler;
            m_handler = 0;
        }
        if (!m_handler)
            m_handler = (HandlerVt11*)new Dummy_0xe4(m_actor, this);
        if (((MovementHandler*)m_handler)->Update(delta, force))
        {
            m_uiContentCount = 4;
            result = true;
        }
        else
        {
            m_uiContentCount = 6;
            result = false;
        }
    }
    reinterpret_cast<::TESForm *>(this)->ClearData();
    return result;
}

struct PathVec
{
    float x, y, z;
    PathVec operator-(const PathVec&) const;
};
struct PathPosition
{
};
struct PathEntry
{
    PathPosition* GetData();
};
struct PathActor;
struct PathRequest
{
    void Update(PathActor*);
    bool IsValid();
};
struct PathSolution
{
    PathEntry* Last();
    unsigned Start();
    bool IsValid();
};
template <class T> struct PathPtr
{
    T* p;
    T* Get();
};
struct PathHandler
{
    virtual ~PathHandler();
    virtual int Start(float, float);
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual float Distance();
    virtual float Progress();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual unsigned Current();
    virtual bool Finished();
};
struct PathActor
{
    int Exists();
};
struct SmallPathHandler : PathHandler
{
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    SmallPathHandler(PathActor*, void*, PathPtr<PathSolution>*, PathRequest*);
};
struct LargePathHandler : SmallPathHandler
{
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc, unke0;
    LargePathHandler(PathActor*, void*, PathPtr<PathSolution>*, PathRequest*);
};
struct SpecialPathActor
{
    void MoveTo(const PathVec&);
};
struct RegularPathActor
{
    virtual void v000();
};
struct FUN_009dd2d0_cls
{
    void* vtable;
    PathVec look, delta;
    PathPtr<PathRequest> request;
    PathPtr<PathSolution> path;
    PathHandler* handler;
    PathActor* actor;
    int unk2c, unk30, unk34, unk38, unk3c;
    unsigned short first, last;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    int state;
    void Finish(int);
    void UpdatePathMovement();
};
struct MoveActor
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void MoveTo(const PathVec&);
public:
    bool TryMove(bool);
};
namespace ActorMovement {
struct Vec
{
    float x, y, z;
};
struct Cell
{
};
struct World
{
};
struct Area
{
};
struct Map
{
};
struct Actor
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual Vec* Position();
    int FUN_00931850();
    Cell* FUN_008d6f30();
};
struct Reference
{
    Vec FUN_005c3420();
};
struct Request
{
};
struct Pointer
{
    Request* value;
};
struct Queue
{
    unsigned int value;
};
struct Clock
{
};
extern float DAT_0109222c, DAT_01092230, DAT_01092234;
struct Mover
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    Pointer request;
    unsigned int unk20;
    unsigned int unk24;
    Actor* actor;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    Queue queue;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    bool enabled;
    char unk71, unk72, unk73;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int lastTime;
    unsigned int startTime;
    int retries;
    void SetEnabled(bool);
    void UpdateTargeting();
};
// @fnv 0x009de490
void Mover::SetEnabled(bool abEnabled)
{
    enabled = abEnabled;
    if (!abEnabled)
        reinterpret_cast<::FUN_006d2c00_shell *>(&(queue))->FUN_006d2c00();
    if (abEnabled)
    {
        if (actor->FUN_00931850() == 3 && (!actor->FUN_008d6f30() || !reinterpret_cast<::TESObjectCELL *>((actor->FUN_008d6f30()))->IsCellInterior()))
        {
            int xSlot14 = int(actor->Position()->x) >> 12;
            int y = int(actor->Position()->y) >> 12;
            if (!xSlot14 && !y &&
                !((intptr_t)(reinterpret_cast<::fnv_006b7850::FUN_006b7850_shell *>((((::ActorMovement::Area *)(reinterpret_cast<::Owner45A *>(((*reinterpret_cast<::ActorMovement::Map * *>(&::g_TES))))->FUN_0045af00()))))->FUN_006b7850({}, {}))))
                reinterpret_cast<::fnv_008ad1c0::MoveSelf454 *>((actor))->FUN_008ad1c0((intptr_t)&(const ::ActorMovement::Vec &)(((::ActorMovement::Reference *)(::FUN_006a9540((char *)(((::ActorMovement::Request *)(::FUN_00559450((int *)&(request))))))))->FUN_005c3420()), 0.0f,
                                    (::TESObjectCELL *)(reinterpret_cast<::FUN_009611e0_shell *>((((::ActorMovement::Reference *)(::FUN_006a9540((char *)(((::ActorMovement::Request *)(::FUN_00559450((int *)&(request))))))))))->FUN_009611e0()),
                                    (::TESWorldSpace *)(((int)(reinterpret_cast<::BGSTerrainManager *>((((::ActorMovement::Reference *)(::FUN_006a9540((char *)(((::ActorMovement::Request *)(::FUN_00559450((int *)&(request))))))))))->GetMinLevel()))), 0, 1);
        }
        float intervalSlot1 = reinterpret_cast<::Actor *>((actor))->IsVisible(7) ? DAT_0109222c : DAT_01092230;
        if (((::ActorMovement::Request *)(::FUN_00559450((int *)&(request)))))
        {
            Cell* fromSlot12 = ((::ActorMovement::Cell *)(reinterpret_cast<::PathingLocation *>((((::ActorMovement::Reference *)(::GetOffsetC((intptr_t)(((::ActorMovement::Request *)(::FUN_00559450((int *)&(request))))))))))->GetContainingCell()));
            Cell* to = ((::ActorMovement::Cell *)(reinterpret_cast<::PathingLocation *>((((::ActorMovement::Reference *)(::FUN_006a9540((char *)(((::ActorMovement::Request *)(::FUN_00559450((int *)&(request))))))))))->GetContainingCell()));
            if (fromSlot12 && to)
            {
                bool fromAboveSlot13 = ((double)(reinterpret_cast<::FUN_0045cbc0_shell *>(((*reinterpret_cast<::ActorMovement::Map * *>(&::g_TES))))->GetCellHeightAtPosition(
                                           (const ::NiPoint3 *)&(const ::ActorMovement::Vec &)(((::ActorMovement::Reference *)(::GetOffsetC((intptr_t)(((::ActorMovement::Request *)(::FUN_00559450((int *)&(request))))))))->FUN_005c3420()), (::CellView *)(fromSlot12)))) >
                                       ((::ActorMovement::Reference *)(::GetOffsetC((intptr_t)(((::ActorMovement::Request *)(::FUN_00559450((int *)&(request))))))))->FUN_005c3420().z;
                bool toAboveSlot1 =
                    ((double)(reinterpret_cast<::FUN_0045cbc0_shell *>(((*reinterpret_cast<::ActorMovement::Map * *>(&::g_TES))))->GetCellHeightAtPosition((const ::NiPoint3 *)&(const ::ActorMovement::Vec &)(((::ActorMovement::Reference *)(::FUN_006a9540((char *)(((::ActorMovement::Request *)(::FUN_00559450((int *)&(request))))))))->FUN_005c3420()), (::CellView *)(to)))) >
                    ((::ActorMovement::Reference *)(::FUN_006a9540((char *)(((::ActorMovement::Request *)(::FUN_00559450((int *)&(request))))))))->FUN_005c3420().z;
                if (fromAboveSlot13 != toAboveSlot1)
                    intervalSlot1 = DAT_01092234;
            }
        }
        float elapsedSlot0 = (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ActorMovement::Clock *>(&::g_timeGlobal))))->FUN_00825c00() - lastTime) * ::DAT_01016978;
        float total = (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ActorMovement::Clock *>(&::g_timeGlobal))))->FUN_00825c00() - startTime) * ::DAT_01016978;
        if (elapsedSlot0 >= intervalSlot1)
        {
            retries = 0;
            lastTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ActorMovement::Clock *>(&::g_timeGlobal))))->FUN_00825c00();
            startTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ActorMovement::Clock *>(&::g_timeGlobal))))->FUN_00825c00();
        }
        else if (total >= intervalSlot1 && retries >= 2)
        {
            UpdateTargeting();
            retries = 0;
            lastTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ActorMovement::Clock *>(&::g_timeGlobal))))->FUN_00825c00();
            startTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ActorMovement::Clock *>(&::g_timeGlobal))))->FUN_00825c00();
        }
        else
        {
            ++retries;
            lastTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ActorMovement::Clock *>(&::g_timeGlobal))))->FUN_00825c00();
        }
        reinterpret_cast<::TESForm *>(this)->ClearData();
    }
}
}

namespace fnv_009de8b0 {
struct Vec3
{
    float x;
    float y;
    float z;
};
struct Pt3
{
    float x;
    float y;
    float z;
};
struct PLoc
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    PLoc(void* refr);
    ~PLoc();
    Vec3 FUN_005c3420();
};
struct Req
{
    float FUN_009b0bd0();
};
struct SPtr
{
    void* p;
};
struct HandlerV
{
    virtual void h00();
    virtual void h01();
    virtual void h02();
    virtual void h03();
    virtual void h04();
    virtual void h05();
    virtual void h06();
    virtual void h07();
    virtual void h08();
    virtual void h09();
    virtual void h10();
    virtual void h11();
    virtual void h12();
    virtual bool V34();
    virtual void h14();
    virtual void h15();
    virtual void h16();
    virtual void h17();
    virtual void h18();
    virtual void h19();
    virtual void h20();
    virtual void h21();
    virtual void h22();
    virtual void h23();
    virtual void h24();
    virtual void h25();
    virtual void h26();
    virtual void h27();
    virtual void h28();
    virtual bool V74();
    int m_04;
    int m_08;
    SPtr sp0c;
};
struct PathSol
{
};
struct ProjBase
{
};
struct RefrV
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Vec3* GetPos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void Call2a8(Vec3*);
};
struct Actor13 : public RefrV
{
    int FUN_00931850();
};
struct Player13 : public RefrV
{
    void* FUN_008d6f30();
};
struct TES
{
};
struct TESWorldSpace;
struct TESObjectREFR;
struct Helper13
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    int m_98;
    int m_9c;
    int m_a0;
    int m_a4;
    int m_a8;
    int m_ac;
    int m_b0;
    Helper13();
    ~Helper13();
    void FUN_006d1bc0(const PLoc& loc);
    void FUN_006d3b00(float f);
    void FUN_006d3ae0(float f);
    void FUN_006e2b90(bool b);
};
struct S_FUN_006b05a0
{
};
struct ContNode;
ContNode* FUN_00717e50(void* p);
struct Sol13
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    Sol13();
    ~Sol13();
    Vec3 GetPointAtDistance(float a, float b);
};
struct Tgt13
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    SPtr spReq;
    SPtr pCurrentPathingSolution;
    HandlerV* handler;
    Actor13* actor;
    void FUN_009df010(Pt3* p);
    void UpdateTargeting();
};
// @fnv 0x009de8b0
void Tgt13::UpdateTargeting()
{
    if (handler != 0)
    {
        if (((void *)(::FUN_00559450((int *)&(handler->sp0c)))) != 0)
        {
            if (handler->V74())
            {
                reinterpret_cast<::TESForm *>(this)->ClearData();
                return;
            }
        }
    }
    uintptr_t bA4;
    uintptr_t zX;
    bool iAB;
    iAB = false;
    if (((void *)(::FUN_00559450((int *)&(spReq)))) == 0)
        return;
    if (reinterpret_cast<::fnv_008bc7f0::FUN_008bc7f0_holder *>((actor))->FUN_008bc7f0((intptr_t)((*reinterpret_cast<::fnv_009de8b0::Player13 * *>(&::_g_thePlayer)))))
    {
        if (handler != 0)
        {
            if (((void *)(::FUN_00559450((int *)&(pCurrentPathingSolution)))) != 0)
            {
                if (!handler->V34())
                {
                    if (!reinterpret_cast<::FUN_006b05d0_shell *>((((PathSol*)((void *)(::FUN_00559450((int *)&(pCurrentPathingSolution)))))))->FUN_006b05d0())
                    {
                        reinterpret_cast<::FUN_008985d0_shell *>((actor))->FUN_008985d0();
                        return;
                    }
                }
            }
        }
        if (reinterpret_cast<::FUN_00589850_Class *>((void *)&(const ::fnv_009de8b0::Vec3 &)((*(::fnv_009de8b0::Vec3 *)(reinterpret_cast<::FUN_00439ef0_class *>((actor->GetPos()))->FUN_00439ef0((::NiPoint3 *)(::fnv_009de8b0::Vec3 *)((*reinterpret_cast<::fnv_009de8b0::Player13 * *>(&::_g_thePlayer))->GetPos()), *(const ::NiPoint3 *)nullptr)))))->FUN_00589850() >
            ((Req*)((void *)(::FUN_00559450((int *)&(spReq)))))->FUN_009b0bd0() * 2)
            iAB = true;
    }
    if (actor->FUN_00931850() == 0)
    {
        bA4 = ((uintptr_t)(reinterpret_cast<::PathingLocation *>((void *)(((::fnv_009de8b0::PLoc *)(::GetOffsetC((intptr_t)(((Req*)((void *)(::FUN_00559450((int *)&(spReq)))))))))))->GetContainingCell()));
        zX = ((uintptr_t)(reinterpret_cast<::PathingLocation *>((void *)(((::fnv_009de8b0::PLoc *)(::FUN_006a9540((char *)(((Req*)((void *)(::FUN_00559450((int *)&(spReq)))))))))))->GetContainingCell()));
        if (0 != bA4 && 0 != zX)
        {
            bool resultB;
            resultB = reinterpret_cast<::FUN_0045cbc0_shell *>(((*reinterpret_cast<::fnv_009de8b0::TES * *>(&::g_TES))))->GetCellHeightAtPosition((const ::NiPoint3 *)(::fnv_009de8b0::Vec3 *)(&ResultSlot(((::fnv_009de8b0::PLoc *)(::GetOffsetC((intptr_t)(((Req*)((void *)(::FUN_00559450((int *)&(spReq)))))))))->FUN_005c3420())), (::CellView *)(bA4)) >
                      ((::fnv_009de8b0::PLoc *)(::GetOffsetC((intptr_t)(((Req*)((void *)(::FUN_00559450((int *)&(spReq)))))))))->FUN_005c3420().z;
            bool y6;
            y6 = reinterpret_cast<::FUN_0045cbc0_shell *>(((*reinterpret_cast<::fnv_009de8b0::TES * *>(&::g_TES))))->GetCellHeightAtPosition((const ::NiPoint3 *)(::fnv_009de8b0::Vec3 *)(&ResultSlot(((::fnv_009de8b0::PLoc *)(::FUN_006a9540((char *)(((Req*)((void *)(::FUN_00559450((int *)&(spReq)))))))))->FUN_005c3420())), (::CellView *)(zX)) >
                 ((::fnv_009de8b0::PLoc *)(::FUN_006a9540((char *)(((Req*)((void *)(::FUN_00559450((int *)&(spReq)))))))))->FUN_005c3420().z;
            if (resultB != y6)
                iAB = true;
        }
        PLoc aLoc4(actor);
        reinterpret_cast<::PathingLocationProxy *>(&(aLoc4))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0));
        if (!reinterpret_cast<::PathingLocation *>(&(aLoc4))->HasValidTriangle_006dd6a0())
            iAB = true;
    }
    if (iAB)
    {
        Helper13 solution4;
        reinterpret_cast<::FUN_006d3ac0_Class *>(&(solution4))->AssignPathingLocation((*(const ::PathingLocation *)(((::fnv_009de8b0::PLoc *)(::FUN_006a9540((char *)(((Req*)((void *)(::FUN_00559450((int *)&(spReq))))))))))));
        solution4.FUN_006d1bc0(actor);
        solution4.FUN_006d3b00(10.0f);
        reinterpret_cast<::FUN_006d3ae0 *>(&(solution4))->SetValue((float)(reinterpret_cast<::fnv_008be280::FloatValueProvider *>((actor))->FUN_008be280() * (double)0.6f));
        reinterpret_cast<::PathingActorData *>(&(solution4))->operator=((*(const ::PathingActorData *)(actor)));
        reinterpret_cast<::FUN_008ad8f0Class *>(&(solution4))->SetByteAtOffset9B(1);
        reinterpret_cast<::FUN_009deff0_Class *>(&(solution4))->SetFlagA3(true);
        reinterpret_cast<::FUN_006e2b50_shell *>(&(solution4))->SetCantOpenDoors(false);
        reinterpret_cast<::FUN_006e2b70_shell *>(&(solution4))->SetCanSwim(reinterpret_cast<::FUN_005f0b50_shell *>((((::fnv_009de8b0::ProjBase *)(reinterpret_cast<::Actor *>((actor))->GetActorBase()))))->FUN_005f0b50());
        reinterpret_cast<::FUN_006e2b90 *>(&(solution4))->SetFlag(reinterpret_cast<::Dummy *>((((::fnv_009de8b0::ProjBase *)(reinterpret_cast<::Actor *>((actor))->GetActorBase()))))->FUN_005f0c40());
        reinterpret_cast<::FUN_008df1c0_Class *>(&(solution4))->SetByteAtA1(1);
        Pt3 idx;
        void* _limitA;
        _limitA = (*reinterpret_cast<::fnv_009de8b0::Player13 * *>(&::_g_thePlayer))->FUN_008d6f30();
        {
            Sol13 bB4;
            if (::Pathing::BuildPath((::PathingRequest *)(::fnv_009de8b0::Helper13 *)(&solution4), (::PathingSolution *)(::fnv_009de8b0::Sol13 *)(&bB4)))
            {
                if (::GetObjectFlags((char *)&(bB4)) >= 2)
                {
                    float iB2;
                    iB2 = 128.0f;
                    if (reinterpret_cast<::fnv_008be280::FloatValueProvider *>((actor))->FUN_008be280() * (double)0.5f > 100.0)
                        iB2 = ::DAT_01032adc;
                    float i4;
                    i4 = reinterpret_cast<::fnv_006e78d0::FUN_006e78d0_shell *>(&(bB4))->GetTotalPathLength();
                    float cell3;
                    cell3 = i4 - iB2;
                    if (cell3 < ::_DAT_01012060)
                        cell3 = (float)(i4 * (double)0.5f);
                    *(Vec3*)&idx = bB4.GetPointAtDistance(0.0f, cell3);
                }
                else
                {
                    return;
                }
            }
            else
            {
                if (::GetObjectFlags((char *)&(bB4)) == 0)
                {
                    return;
                }
                else
                {
                    *(Vec3*)&idx = ((PLoc*)FUN_00717e50(reinterpret_cast<::S_FUN_006b05a0 *>((((S_FUN_006b05a0*)&bB4)))->FUN_006b05a0()))->FUN_005c3420();
                }
            }
            reinterpret_cast<::TESForm *>(this)->ClearData();
            if (reinterpret_cast<::fnv_008bc7f0::FUN_008bc7f0_holder *>((actor))->FUN_008bc7f0((intptr_t)((*reinterpret_cast<::fnv_009de8b0::Player13 * *>(&::_g_thePlayer)))) &&
                ((::fnv_009de8b0::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((TESObjectREFR*)actor))->FUN_00575d70())) != ((::fnv_009de8b0::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((TESObjectREFR*)(*reinterpret_cast<::fnv_009de8b0::Player13 * *>(&::_g_thePlayer))))->FUN_00575d70())))
            {
                ::fnv_00573800::FUN_00573800((::fnv_00573800::MoveRef *)(actor), (::fnv_00573800::MoveCell *)(void *)((*reinterpret_cast<::fnv_009de8b0::Player13 * *>(&::_g_thePlayer))->FUN_008d6f30()), (::fnv_00573800::MoveWorld *)(void *)(((::fnv_009de8b0::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((TESObjectREFR*)(*reinterpret_cast<::fnv_009de8b0::Player13 * *>(&::_g_thePlayer))))->FUN_00575d70()))));
                actor->Call2a8((Vec3*)&idx);
            }
            else
            {
                FUN_009df010(&idx);
            }
        }
    }
}
}  // namespace fnv_009de8b0

class BGSSaveFormBuffer
{
  public:
};
struct TimeGlobal
{
};
struct SavedRequest
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual unsigned char GetType();
    virtual void v14();
    virtual void Save(BGSSaveFormBuffer*);
};
struct SavedSolution
{
};
template <class T> struct SavePointer
{
    T* object;
    T* FUN_00559450() const;
};
struct SavedLocation
{
    virtual void Save(BGSSaveFormBuffer*);
};
struct SavedHandler : ActorPathHandler
{
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void Save(BGSSaveFormBuffer*);
};
struct FUN_009df100_shell
{
    void* vtable;
    NiPoint3 lookAtPoint;
    NiPoint3 cachedMoveDelta;
    SavePointer<SavedRequest> request;
    SavePointer<SavedSolution> path;
    SavedHandler* handler;
    Actor* actor;
    unsigned int reference;
    void* queue;
    unsigned int movement34;
    unsigned int movement38;
    unsigned int movement3c;
    unsigned short movement40;
    unsigned short movement42;
    SavedLocation location;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int state;
    bool pathingFailed;
    bool forceMoveMode;
    bool stopNextUpdate;
    bool faceTarget;
    bool waitingForPath;
    bool processLevelChanged;
    bool inDialog;
    bool validDelta;
    bool field78;
    unsigned int timeStamp;
    unsigned int field80;
    unsigned int field84;
    void FUN_009df100(BGSSaveFormBuffer* buffer);
};
// Writes movement, pathing, state and timing fields to the save buffer, then saves the location, reference, request, path and handler.
// @fnv 0x009df100
void FUN_009df100_shell::FUN_009df100(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&movement40, 2, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&movement42, 2, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&pathingFailed, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&movement34, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&forceMoveMode, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&movement38, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&stopNextUpdate, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&faceTarget, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&lookAtPoint, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&cachedMoveDelta, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&movement3c, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&waitingForPath, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&processLevelChanged, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&validDelta, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&inDialog, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&field78, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&state, 4, 0);
    unsigned int elapsed = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() - timeStamp;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&elapsed, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&field84, 4, 0);
    location.Save(buffer);
    reinterpret_cast<::FUN_00865db0_shell *>((buffer))->FUN_00865db0(reference, 0);
    unsigned char flags = 0;
    if (((::SavedRequest *)(::FUN_00559450((int *)&(request)))))
        flags |= 1;
    if (((::SavedSolution *)(::FUN_00559450((int *)&(path)))))
        flags |= 2;
    if (handler)
        flags |= handler->vfn_34() ? 8 : 4;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&flags, 1, 0);
    if (((::SavedRequest *)(::FUN_00559450((int *)&(request)))))
    {
        unsigned char type = ((::SavedRequest *)(::FUN_00559450((int *)&(request))))->GetType();
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&type, 1, 0);
        ((::SavedRequest *)(::FUN_00559450((int *)&(request))))->Save(buffer);
    }
    if (((::SavedSolution *)(::FUN_00559450((int *)&(path)))))
        reinterpret_cast<::SaveSolution *>((((::SavedSolution *)(::FUN_00559450((int *)&(path))))))->FUN_006e8b10((::SaveBuffer *)(buffer));
    if (handler)
        handler->Save(buffer);
}

namespace loadpath {
struct Buffer
{
    virtual unsigned char Version();
};
struct Clock
{
};
struct ObjectResolver
{
};
struct Node
{
    ObjectResolver* Data();
};
struct Solution
{
    Solution();
    int a00;
    int a04;
    int a08;
    int a0c;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
    int a24;
    int a28;
    int a2c;
    int a30;
    int a34;
    int a38;
    int a3c;
    int a40;
};
struct Request
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Load(Buffer*);
};
Request* MakeRequest(unsigned int);
template <class T> struct Ptr
{
    T* p;
    Ptr& FUN_0066b0d0(T*);
    operator T*();
    T* operator->();
};
struct ProcessFlags
{
};
struct Process
{
    int a00;
    ProcessFlags flags;
};
struct Actor
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual const char* Name();
};
struct Location
{
    virtual void v00();
    virtual void Load(Buffer*);
};
struct Handler
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void Load(Buffer*);
};
struct Mover;
struct VirtualHandler : Handler
{
    VirtualHandler(Actor*, Mover*, Ptr<Solution>&, Request*);
    int a04;
    int a08;
    int a0c;
    int a10;
    int a14;
    int a18;
    int a1c;
};
struct NormalHandler : Handler
{
    NormalHandler(Actor*, Mover*, Ptr<Solution>&, Request*);
    int a04;
    int a08;
    int a0c;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
    int a24;
    int a28;
    int a2c;
    int a30;
    int a34;
    int a38;
    int a3c;
    int a40;
    int a44;
    int a48;
    int a4c;
    int a50;
    int a54;
    int a58;
    int a5c;
    int a60;
    int a64;
    int a68;
    int a6c;
    int a70;
    int a74;
    int a78;
    int a7c;
    int a80;
    int a84;
    int a88;
    int a8c;
    int a90;
    int a94;
    int a98;
    int a9c;
    int aa0;
    int aa4;
    int aa8;
    int aac;
    int ab0;
    int ab4;
    int ab8;
    int abc;
    int ac0;
    int ac4;
    int ac8;
    int acc;
    int ad0;
    int ad4;
    int ad8;
    int adc;
    int ae0;
};
struct Mover
{
    int a00;
    struct Vector
    {
        float x, y, z;
    } look, delta;
    Ptr<Request> request;
    Ptr<Solution> path;
    Handler* handler;
    Actor* actor;
    int ref;
    int a30;
    int a34;
    int a38;
    int a3c;
    short a40;
    short a42;
    Location loc;
    int a48;
    int a4c;
    int a50;
    int a54;
    int a58;
    int a5c;
    int a60;
    int a64;
    int a68;
    int state;
    unsigned char a70, a71, a72, a73, a74, a75, a76, a77, a78;
    unsigned int elapsed;
    int a80;
    int a84;
    void FUN_009df3d0(Buffer*);
};
// Reads the mover's saved fields from a buffer, reconstructs its request, path and handler, and forces a failure if the path is stale.
// @fnv 0x009df3d0
void Mover::FUN_009df3d0(Buffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a40), 2);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a42), 2);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a70), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a34), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a71), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a38), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a72), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a73), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&look), 12);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&delta), 12);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a3c), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a74), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a75), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a77), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a76), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a78), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&state), 4);
    if (buffer->Version() >= 14)
    {
        unsigned int uiSavedTime = 0;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&uiSavedTime), 4);
        if (uiSavedTime < reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::loadpath::Clock *>(&::g_timeGlobal))))->FUN_00825c00())
            elapsed = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::loadpath::Clock *>(&::g_timeGlobal))))->FUN_00825c00() - uiSavedTime;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a84), 4);
    }
    if (buffer->Version() >= 7)
        loc.Load(buffer);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&ref));
    unsigned char uiStaleFlags = 0;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&uiStaleFlags), 1);
    if (uiStaleFlags & 1)
    {
        unsigned char uiRequestKind = 0;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&uiRequestKind), 1);
        request.FUN_0066b0d0(MakeRequest(uiRequestKind));
        ((Request*)request)->Load(buffer);
        if (actor && ((::loadpath::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture())) && !reinterpret_cast<::FUN_008c6b00_shell *>(&(((::loadpath::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->flags))->FUN_008c6b00(0))
            reinterpret_cast<::PathingActorData *>((((Request*)request)))->operator=((*(const ::PathingActorData *)(actor)));
    }
    bool flags = false;
    if (uiStaleFlags & 2)
    {
        path.FUN_0066b0d0(new Solution);
        reinterpret_cast<::FUN_006e8d50_shell *>((((Solution*)path)))->FUN_006e8d50((::BGSLoadFormBuffer *)(buffer));
        for (unsigned int index = 0; index < ::FUN_005a4320((char *)(((Solution*)path))); ++index)
        {
            if (::FUN_006ca830((const unsigned int *)(((::loadpath::Node *)(reinterpret_cast<::FUN_006e78b0_shell *>((((Solution*)path)))->FUN_006e78b0(index))))) &&
                !((void *)(reinterpret_cast<::PathingLocationProxy *>((((ObjectResolver*)((::loadpath::Node *)(reinterpret_cast<::FUN_006e78b0_shell *>((((Solution*)path)))->FUN_006e78b0(index)))->Data())))->GetAssociatedNavMesh())))
            {
                ::FUN_005b5e40();
                flags = true;
                break;
            }
        }
    }
    if (uiStaleFlags & 4)
    {
        handler = new VirtualHandler(actor, this, path, request);
    }
    else if (uiStaleFlags & 8)
    {
        handler = new NormalHandler(actor, this, path, request);
    }
    if (handler)
        handler->Load(buffer);
    if (flags)
    {
        ::FUN_009daf80((::TESForm *)this);
        state = 7;
        reinterpret_cast<::ActorMovement::Mover *>(this)->SetEnabled(1);
    }
}
}

struct Process884750
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual bool IsBusy();
};
struct Actor884750
{
    int unk00;
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    Process884750* m_pkProcess;
    int GetAnimAction();
    bool FUN_00884750();
};

class ActorPathingMessageQueue;
class PathingRequest;
template <class> class NiPointer;
struct PathManager
{
    PathManager();
    virtual ~PathManager();
public:
    bool BuildPath(::NiPointer< ::PathingRequest>, ::NiPointer< ::ActorPathingMessageQueue>, bool);
};
extern PathManager DAT_011c5290;
void __cdecl FUN_00fc8480();
void __cdecl _atexit(void(__cdecl*)(void));
// Returns a pointer to a function-local static PathManager.
// @fnv 0x0047d0b0
PathManager* __cdecl GetPathManager()
{
    static PathManager pManager;
    return &pManager;
}

struct FUN_0050d4a0_shell
{
    bool FUN_0050d4a0();
};

struct FUN_008a0b10_shell
{
};

struct FUN_008a7570_shell
{
    int FUN_008a7570();
};
// Returns false if the actor is loading, has anim action 7, or is the busy player, otherwise true.
// @fnv 0x00884750
bool Actor884750::FUN_00884750()
{
    if (reinterpret_cast<::FUN_0047c850 *>(this)->EvaluateCondition())
        return false;
    int iAction = reinterpret_cast<::FUN_008a7570_shell *>(this)->FUN_008a7570();
    if (iAction == 7)
        return false;
    if (this == (*reinterpret_cast<::Actor884750 * *>(&::_g_thePlayer)) && m_pkProcess && m_pkProcess->IsBusy())
        return false;
    return true;
}

struct FUN_00884750_shell
{
};

struct FUN_008eea60_shell
{
    bool FUN_008eea60();
};

struct DummyTimer
{
};

struct FrameMoveTimeView14
{
};
struct TimeGlobal;

class NiControllerSequence
{
  public:
};

struct BSAnimGroupSequence : public NiControllerSequence
{
};

class FUN_00491040_shell
{
  public:
    BSAnimGroupSequence* FUN_00491040(int section);
};

class AnimData : public FUN_00491040_shell
{
  public:
};

class ActorPathHandler_Standin : public ActorPathHandler
{
  public:
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual unsigned int GetActorStateFlags();
    virtual bool GetPathingDelta(NiPoint3* outDelta);
};

class NiPoint3Ex : public NiPoint3
{
  public:
    NiPoint3Ex(float, float, float);
};

class ActorMover_Standin
{
  public:
    void* vtable;
    NiPoint3 m_kLookAtTargetPosition;
    NiPoint3 m_kPathingDelta;
    void* request;
    NiPointer<NiNode> m_pActorNode;
    ActorPathHandler_Standin* m_pPathHandler;
    Actor* pActor;
    int unk2c, unk30, unk34;
    unsigned int m_uiMovementFlags;
    unsigned int m_uiMovementMode;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    int eState;
    bool bPathingFailed;
    bool m_bHasMovementData;
    bool m_bMovementComplete;
    bool m_bHasLookAtTarget;
    bool m_bMovementActive;
    bool m_bMovementStateFlag;
    bool m_bMovementPaused;
    bool m_bHasPathingDelta;
    bool bUnk78;

    void FUN_009ddc00();
};
// @fnv 0x009dc120
void Mover11::FUN_009dc120(float f)
{
    if (m_72)
    {
        m_78 = 1;
        reinterpret_cast<::fnv_009dd1c0::FUN_009dd1c0_shell *>(this)->FUN_009dd1c0(1);
        m_72 = 0;
    }
    if (m_actor->v22c(0))
    {
        if (m_handler)
        {
            m_handler->v70();
        }
        goto END;
    }
    {
        Proc11* proc = ((::Proc11 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((m_actor))->GetBaseTexture()));
        if (proc == 0)
            goto END;
        if (proc->v610() == 4)
            goto END;
        if (((intptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((proc))->FUN_0045cd60())) != reinterpret_cast<::fnv_009334b0::FUN_009334b0_shell *>((m_actor))->GetCellLoadState())
            goto END;
        if (proc->v4bc() != 0)
            goto END;
        if (m_actor->v230())
            goto END;
        if (proc->v40c() != 0)
            goto END;
        if (proc->v6fc())
            goto END;
        if (m_75)
        {
            m_75 = 0;
            reinterpret_cast<::FUN_009dd2d0_cls *>(this)->UpdatePathMovement();
        }
        if (!m_failed)
        {
            if (!m_waiting)
            {
                if ((Sol11*)m_path && reinterpret_cast<::Mover *>((((Sol11*)m_path)))->FUN_009dc530())
                {
                    m_uiContentCount = 3;
                    reinterpret_cast<::ActorMover *>(this)->UpdateMovement(f);
                    goto END;
                }
            }
            else
            {
                Msg11 msg;
                if (((QueueVt11*)m_queue)->v10(&msg))
                {
                    switch (msg.m_type)
                    {
                    case 0:
                        m_uiContentCount = 3;
                        m_waiting = 0;
                        m_path = msg.m_sol;
                        reinterpret_cast<::ThisCls *>(this)->UpdatePathingState(f);
                        break;
                    case 1: {
                        m_waiting = 0;
                        m_path = msg.m_sol;
                        if ((Sol11*)m_path && reinterpret_cast<::Mover *>((((Sol11*)m_path)))->FUN_009dc530() && ((bool)(reinterpret_cast<::FUN_006a9560_Class *>((((Req11*)m_req)))->GetByteAtOffset9B())))
                        {
                            m_uiContentCount = 3;
                            reinterpret_cast<::ThisCls *>(this)->UpdatePathingState(f);
                            break;
                        }
                        m_uiContentCount = 7;
                        SetEnabled(1);
                        if ((Sol11*)m_path)
                        {
                            int idx = ((int)(reinterpret_cast<::BGSTerrainManager *>((((Sol11*)m_path)))->GetMinLevel()));
                            if (idx != -1)
                            {
                                if (::FUN_005a4320((char *)(((Sol11*)m_path))) > 0)
                                {
                                    void* node = reinterpret_cast<::FUN_006e78b0_shell *>((((Sol11*)m_path)))->FUN_006e78b0(idx);
                                    if (node)
                                    {
                                        reinterpret_cast<::PathingLocation *>((void *)&(const ::Loc11 &)(m_loc))->operator=((const ::PathingLocation &)(*(Loc11*)((Node11*)node)->FUN_00717e50()));
                                        reinterpret_cast<::PathingLocation *>(&(m_loc))->ResetLocation();
                                    }
                                }
                            }
                        }
                        FUN_009daf80((TESForm*)this);
                        break;
                    }
                    default:
                        break;
                    }
                    goto END;
                }
                goto SECB;
            }
        }
    }
SECB:
    if (!((Sol11*)m_path && reinterpret_cast<::Mover *>((((Sol11*)m_path)))->FUN_009dc530() && !m_failed))
    {
        if (m_handler)
        {
            if (m_handler->v10(f) == 5)
            {
                m_uiContentCount = 6;
            }
        }
    }
END:
    reinterpret_cast<::ActorMover_Standin *>(this)->FUN_009ddc00();
    reinterpret_cast<::TESForm *>(this)->ClearData();
}

// Computes the actor's movement delta from animation or pathing, adjusts movement mode flags, and stores the result in m_kPathingDelta.
// @fnv 0x009ddc00
void ActorMover_Standin::FUN_009ddc00()
{
    bool bHaveValidDelta = false;
    unsigned int mode = 0;
    NiPoint3 moveDelta = ::NiPoint3::ZERO;

    if (this->m_bHasMovementData)
    {
        mode = this->m_uiMovementFlags;
        AnimData* anim = this->pActor->GetAnimData();
        if (anim)
        {
            if (((FUN_0050d4a0_shell*)this->pActor)->FUN_0050d4a0())
            {
                reinterpret_cast<::fnv_00494390::MovementAnimation *>((anim))->GetMovement((::fnv_00494390::MotionPoint *)(::NiPoint3 *)(&moveDelta), (::fnv_00494390::MotionActor *)(this->pActor), 1, 0);
            }
            else
            {
                reinterpret_cast<::fnv_00494390::MovementAnimation *>((anim))->GetMovement((::fnv_00494390::MotionPoint *)(::NiPoint3 *)(&moveDelta), (::fnv_00494390::MotionActor *)(this->pActor), 0, 1);
            }
        }
        else
        {
            if (!this->pActor->IsVisible(7))
            {
                moveDelta = NiPoint3Ex(0.0f,
                                       reinterpret_cast<::fnv_008a0b10::FUN_008a0b10_shell *>((((FUN_008a0b10_shell*)this->pActor)))->FUN_008a0b10() *
                                           reinterpret_cast<::Twin_0084d030 *>((((FrameMoveTimeView14*)&(*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal)))))->GetStoredFloatValue(),
                                       0.0f);
            }
        }
        bHaveValidDelta = true;
    }
    else
    {
        if (this->m_pPathHandler)
        {
            mode = this->m_pPathHandler->GetActorStateFlags();
            if (this->m_pPathHandler->GetPathingDelta(&moveDelta))
            {
                bHaveValidDelta = true;
            }
            if (this->bUnk78)
            {
                mode &= ~0xF;
                moveDelta = ::NiPoint3::ZERO;
                bHaveValidDelta = true;
                switch (((FUN_008a7570_shell*)this->pActor)->FUN_008a7570())
                {
                case 0xc:
                case 0xd:
                case 0xe:
                    this->bUnk78 = false;
                    bHaveValidDelta = false;
                    break;
                default:
                    AnimData* anim = this->pActor->GetAnimData();
                    if (!anim || !reinterpret_cast<::fnv_00495be0::PriorityAnimation *>((anim))->IsHighestPriority())
                    {
                        this->bUnk78 = false;
                    }
                    break;
                }
            }
        }
    }

    if (mode & 0x200)
    {
        if (!reinterpret_cast<::Actor884750 *>((((FUN_00884750_shell*)this->pActor)))->FUN_00884750())
        {
            mode &= ~0x200;
            mode |= 0x100;
        }
    }

    if (mode & 0x400)
    {
        if (!((FUN_008eea60_shell*)this->pActor)->FUN_008eea60())
        {
            mode &= ~0x400;
        }
    }

    if ((mode & 0x400) != (this->m_uiMovementMode & 0x400))
    {
        AnimData* anim = this->pActor->GetAnimData();
        if (!anim || (anim->FUN_00491040(0) && ((intptr_t)(reinterpret_cast<::LowProcess *>((anim->FUN_00491040(0)))->GetActiveCombatTarget())) != 1) ||
            (anim->FUN_00491040(1) && ((intptr_t)(reinterpret_cast<::LowProcess *>((anim->FUN_00491040(1)))->GetActiveCombatTarget())) != 1) ||
            (anim->FUN_00491040(4) && ((intptr_t)(reinterpret_cast<::LowProcess *>((anim->FUN_00491040(4)))->GetActiveCombatTarget())) != 1) ||
            ((FUN_008a7570_shell*)this->pActor)->FUN_008a7570() != -1)
        {
            mode &= ~0x400;
            mode |= (this->m_uiMovementMode & 0x400);
        }
    }

    this->m_uiMovementMode = mode;
    this->m_kPathingDelta = moveDelta;
    this->m_bHasPathingDelta = bHaveValidDelta;
    reinterpret_cast<::TESForm *>((((DummyTimer*)this)))->ClearData();
}

class BackgroundPathLocation14
{
  public:
};

struct Cell14
{
};

struct MobileObject_Helper
{
    void* FUN_008d6f30();
};

struct NiPoint3_sub
{
};


class NiMemObject
{
  public:
};

struct BackgroundQueueAssign14
{
};

class PathingRequest
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual unsigned int vfn_10();
    BackgroundPathLocation14& GetOffsetC();
    float GetSmoothingRandomness();
    void IncRefCount();
    void DecRefCount();
public:
    float GetCenterRadius();
};

template <> class NiPointer<PathingRequest>
{
  public:
    PathingRequest* m_pObject;
    NiPointer();
    NiPointer(PathingRequest*);
    NiPointer(const NiPointer<PathingRequest>&);
    ~NiPointer();
    NiPointer& operator=(PathingRequest*);
    operator PathingRequest*() const;
};

template <> class NiPointer<ActorPathingMessageQueue>
{
  public:
    ActorPathingMessageQueue* m_pObject;
    NiPointer();
    NiPointer(ActorPathingMessageQueue*);
    NiPointer(const NiPointer<ActorPathingMessageQueue>&);
    ~NiPointer();
    NiPointer& operator=(ActorPathingMessageQueue*);
    operator ActorPathingMessageQueue*() const;
};

// Subclasses of PathingRequest: size in bytes minus 4 (for PathingRequest vtable)
// FUN_006e26a0: 0xb0 total -> 0xac
struct FUN_006e26a0 : public NiMemObject, public PathingRequest
{
    FUN_006e26a0(const PathingRequest*);
    int pad0_00;
    int pad0_01;
    int pad0_02;
    int pad0_03;
    int pad0_04;
    int pad0_05;
    int pad0_06;
    int pad0_07;
    int pad0_08;
    int pad0_09;
    int pad0_0a;
    int pad0_0b;
    int pad0_0c;
    int pad0_0d;
    int pad0_0e;
    int pad0_0f;
    int pad0_10;
    int pad0_11;
    int pad0_12;
    int pad0_13;
    int pad0_14;
    int pad0_15;
    int pad0_16;
    int pad0_17;
    int pad0_18;
    int pad0_19;
    int pad0_1a;
    int pad0_1b;
    int pad0_1c;
    int pad0_1d;
    int pad0_1e;
    int pad0_1f;
    int pad0_20;
    int pad0_21;
    int pad0_22;
    int pad0_23;
    int pad0_24;
    int pad0_25;
    int pad0_26;
    int pad0_27;
    int pad0_28;
    int pad0_29;
    int pad0_2a;
};

// FUN_006e5400: 0xb4 total -> 0xb0
struct FUN_006e5400 : public NiMemObject, public PathingRequest
{
    FUN_006e5400(const PathingRequest*);
    int pad3_00;
    int pad3_01;
    int pad3_02;
    int pad3_03;
    int pad3_04;
    int pad3_05;
    int pad3_06;
    int pad3_07;
    int pad3_08;
    int pad3_09;
    int pad3_0a;
    int pad3_0b;
    int pad3_0c;
    int pad3_0d;
    int pad3_0e;
    int pad3_0f;
    int pad3_10;
    int pad3_11;
    int pad3_12;
    int pad3_13;
    int pad3_14;
    int pad3_15;
    int pad3_16;
    int pad3_17;
    int pad3_18;
    int pad3_19;
    int pad3_1a;
    int pad3_1b;
    int pad3_1c;
    int pad3_1d;
    int pad3_1e;
    int pad3_1f;
    int pad3_20;
    int pad3_21;
    int pad3_22;
    int pad3_23;
    int pad3_24;
    int pad3_25;
    int pad3_26;
    int pad3_27;
    int pad3_28;
    int pad3_29;
    int pad3_2a;
    int pad3_2b;
};

// FUN_006e5640: 0xdc total -> 0xd8
struct FUN_006e5640 : public NiMemObject, public PathingRequest
{
    FUN_006e5640(const PathingRequest*);
    int pad4_00;
    int pad4_01;
    int pad4_02;
    int pad4_03;
    int pad4_04;
    int pad4_05;
    int pad4_06;
    int pad4_07;
    int pad4_08;
    int pad4_09;
    int pad4_0a;
    int pad4_0b;
    int pad4_0c;
    int pad4_0d;
    int pad4_0e;
    int pad4_0f;
    int pad4_10;
    int pad4_11;
    int pad4_12;
    int pad4_13;
    int pad4_14;
    int pad4_15;
    int pad4_16;
    int pad4_17;
    int pad4_18;
    int pad4_19;
    int pad4_1a;
    int pad4_1b;
    int pad4_1c;
    int pad4_1d;
    int pad4_1e;
    int pad4_1f;
    int pad4_20;
    int pad4_21;
    int pad4_22;
    int pad4_23;
    int pad4_24;
    int pad4_25;
    int pad4_26;
    int pad4_27;
    int pad4_28;
    int pad4_29;
    int pad4_2a;
    int pad4_2b;
    int pad4_2c;
    int pad4_2d;
    int pad4_2e;
    int pad4_2f;
    int pad4_30;
    int pad4_31;
    int pad4_32;
    int pad4_33;
    int pad4_34;
    int pad4_35;
};

// FUN_006e5940: 0xd8 total -> 0xd4
struct FUN_006e5940 : public NiMemObject, public PathingRequest
{
    FUN_006e5940(const PathingRequest*);
    int pad5_00;
    int pad5_01;
    int pad5_02;
    int pad5_03;
    int pad5_04;
    int pad5_05;
    int pad5_06;
    int pad5_07;
    int pad5_08;
    int pad5_09;
    int pad5_0a;
    int pad5_0b;
    int pad5_0c;
    int pad5_0d;
    int pad5_0e;
    int pad5_0f;
    int pad5_10;
    int pad5_11;
    int pad5_12;
    int pad5_13;
    int pad5_14;
    int pad5_15;
    int pad5_16;
    int pad5_17;
    int pad5_18;
    int pad5_19;
    int pad5_1a;
    int pad5_1b;
    int pad5_1c;
    int pad5_1d;
    int pad5_1e;
    int pad5_1f;
    int pad5_20;
    int pad5_21;
    int pad5_22;
    int pad5_23;
    int pad5_24;
    int pad5_25;
    int pad5_26;
    int pad5_27;
    int pad5_28;
    int pad5_29;
    int pad5_2a;
    int pad5_2b;
    int pad5_2c;
    int pad5_2d;
    int pad5_2e;
    int pad5_2f;
    int pad5_30;
    int pad5_31;
    int pad5_32;
    int pad5_33;
    int pad5_34;
};

// FUN_006e6010: 0xbc total -> 0xb8
struct FUN_006e6010 : public NiMemObject, public PathingRequest
{
    FUN_006e6010(const PathingRequest*);
    int pad6_00;
    int pad6_01;
    int pad6_02;
    int pad6_03;
    int pad6_04;
    int pad6_05;
    int pad6_06;
    int pad6_07;
    int pad6_08;
    int pad6_09;
    int pad6_0a;
    int pad6_0b;
    int pad6_0c;
    int pad6_0d;
    int pad6_0e;
    int pad6_0f;
    int pad6_10;
    int pad6_11;
    int pad6_12;
    int pad6_13;
    int pad6_14;
    int pad6_15;
    int pad6_16;
    int pad6_17;
    int pad6_18;
    int pad6_19;
    int pad6_1a;
    int pad6_1b;
    int pad6_1c;
    int pad6_1d;
    int pad6_1e;
    int pad6_1f;
    int pad6_20;
    int pad6_21;
    int pad6_22;
    int pad6_23;
    int pad6_24;
    int pad6_25;
    int pad6_26;
    int pad6_27;
    int pad6_28;
    int pad6_29;
    int pad6_2a;
    int pad6_2b;
    int pad6_2c;
    int pad6_2d;
};

// FUN_006e5db0: 0xc0 total -> 0xbc
struct FUN_006e5db0 : public NiMemObject, public PathingRequest
{
    FUN_006e5db0(const PathingRequest*);
    int pad7_00;
    int pad7_01;
    int pad7_02;
    int pad7_03;
    int pad7_04;
    int pad7_05;
    int pad7_06;
    int pad7_07;
    int pad7_08;
    int pad7_09;
    int pad7_0a;
    int pad7_0b;
    int pad7_0c;
    int pad7_0d;
    int pad7_0e;
    int pad7_0f;
    int pad7_10;
    int pad7_11;
    int pad7_12;
    int pad7_13;
    int pad7_14;
    int pad7_15;
    int pad7_16;
    int pad7_17;
    int pad7_18;
    int pad7_19;
    int pad7_1a;
    int pad7_1b;
    int pad7_1c;
    int pad7_1d;
    int pad7_1e;
    int pad7_1f;
    int pad7_20;
    int pad7_21;
    int pad7_22;
    int pad7_23;
    int pad7_24;
    int pad7_25;
    int pad7_26;
    int pad7_27;
    int pad7_28;
    int pad7_29;
    int pad7_2a;
    int pad7_2b;
    int pad7_2c;
    int pad7_2d;
    int pad7_2e;
};

// FUN_006e4d20: 0x10c total -> 0x108
struct FUN_006e4d20 : public NiMemObject, public PathingRequest
{
    FUN_006e4d20(const PathingRequest*);
    int pad8_00;
    int pad8_01;
    int pad8_02;
    int pad8_03;
    int pad8_04;
    int pad8_05;
    int pad8_06;
    int pad8_07;
    int pad8_08;
    int pad8_09;
    int pad8_0a;
    int pad8_0b;
    int pad8_0c;
    int pad8_0d;
    int pad8_0e;
    int pad8_0f;
    int pad8_10;
    int pad8_11;
    int pad8_12;
    int pad8_13;
    int pad8_14;
    int pad8_15;
    int pad8_16;
    int pad8_17;
    int pad8_18;
    int pad8_19;
    int pad8_1a;
    int pad8_1b;
    int pad8_1c;
    int pad8_1d;
    int pad8_1e;
    int pad8_1f;
    int pad8_20;
    int pad8_21;
    int pad8_22;
    int pad8_23;
    int pad8_24;
    int pad8_25;
    int pad8_26;
    int pad8_27;
    int pad8_28;
    int pad8_29;
    int pad8_2a;
    int pad8_2b;
    int pad8_2c;
    int pad8_2d;
    int pad8_2e;
    int pad8_2f;
    int pad8_30;
    int pad8_31;
    int pad8_32;
    int pad8_33;
    int pad8_34;
    int pad8_35;
    int pad8_36;
    int pad8_37;
    int pad8_38;
    int pad8_39;
    int pad8_3a;
    int pad8_3b;
    int pad8_3c;
    int pad8_3d;
    int pad8_3e;
    int pad8_3f;
    int pad8_40;
    int pad8_41;
};

struct PathManager14
{
};

struct PathManager;
PathManager* __cdecl GetPathManager();
void FUN_009daf80(TESForm*);

struct Handler14
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual bool v34();
    virtual void v38(PathingRequest*);
};

class ActorMoverBuildPath14
{
  public:
    void* m_vt;
    NiPoint3 m_look;
    NiPoint3 m_delta;
    NiPointer<PathingRequest> m_req;
    void* m_path;
    Handler14* m_handler;
    MobileObject_Helper* m_actor;
    int m_2c;
    NiPointer<ActorPathingMessageQueue> m_queue;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_uiContentCount;
    unsigned char m_failed;
    unsigned char m_71;
    unsigned char m_72;
    unsigned char m_73;
    unsigned char m_waiting;
    unsigned char m_75;
    unsigned char m_76;
    unsigned char m_77;
    int m_78;
    int m_7c;
    int m_80;
    intptr_t m_84;


    bool FUN_009db090(const PathingRequest* apRequest);
};
// @fnv 0x009dba30
bool FUN_009dba30_fix::FUN_009dba30(const PathingRequest* apRequest)
{
    return reinterpret_cast<::ActorMoverBuildPath14 *>((((FUN_009db090_shell*)this)))->FUN_009db090(apRequest);
}



class NiPoint3;
struct TaskQueueInterface
{
public:
    static ::TaskQueueInterface *GetSingleton();
public:
    ::NiPoint3 &QueueActorAnimationTask(::NiPoint3 &);
};
// @fnv 0x009de2b0
bool FUN_009de2b0_shell::GetPathCoordinate(NiPoint3* position)
{
    if (m_pActorNode.operator->() && reinterpret_cast<::Mover *>((m_pActorNode.operator->()))->FUN_009dc530())
    {
        PathQuery* query = reinterpret_cast<PathNode*>(m_pActorNode.operator->())->FUN_009ddb30();
        if (query)
        {
            NiPoint3 coordinate;
            *position = *((::NiPoint3 *)&(reinterpret_cast<::TaskQueueInterface *>((query->FUN_00717e50(&coordinate)))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
            return true;
        }
    }
    return false;
}
// Handles a pathing result code: on failure sets state 7 and resets the path, on success checks completion and distance to the last node.
// @fnv 0x009dc5e0
void ActorMoverX::HandlePathResult(int aiResult)
{
    switch (aiResult)
    {
    case 1:
    case 2:
    case 3:
    case 4:
        eState = 7;
        reinterpret_cast<::ActorMover *>(this)->ClearMovementPath();
        SetPathFailed(true);
        break;
    case 5:
    case 6: {
        int iUpdateResult = UpdatePathHandler();
        if (!reinterpret_cast<::FUN_006b05d0_shell *>(((m_pActorNode).operator->()))->FUN_006b05d0())
        {
            if (aiResult == 6 && eState != 7)
            {
                eState = 3;
            }
            reinterpret_cast<::ActorMover *>(this)->ClearMovementPath();
        }
        else if (iUpdateResult != 1)
        {
            if (::GetObjectFlags((char *)((m_pActorNode).operator->())) > 0)
            {
                PointX kDelta =
                    (*(::PointX *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(((::VirtualPathingNodeX *)(reinterpret_cast<::FUN_006e78b0_shell *>(((m_pActorNode).operator->()))->FUN_006e78b0(reinterpret_cast<::BGSTerrainManager *>(((m_pActorNode).operator->()))->GetMinLevel())))->GetLocation()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))) -
                    *pActor->GetPos();
                if (reinterpret_cast<::FUN_00595c80_shell *>((void *)&(kDelta))->GetSquaredXYLength() <= reinterpret_cast<::PathingRequest *>((void *)((m_kFirstNP).operator->()))->GetCenterRadius() * reinterpret_cast<::PathingRequest *>((void *)((m_kFirstNP).operator->()))->GetCenterRadius())
                {
                    break;
                }
            }
            eState = 7;
            SetPathFailed(true);
            ::FUN_009daf80((::TESForm *)(::ActorMoverX *)(this));
            reinterpret_cast<::ActorMover *>(this)->ClearMovementPath();
        }
    }
    break;
    }
}
// Builds a request from apRequest, notifies the handler when present, then submits it to the path manager or returns early.
// @fnv 0x009db090
bool ActorMoverBuildPath14::FUN_009db090(const PathingRequest* apRequest)
{
    bool result5 = false;
    bool sleeping;
    ((PathingRequest*)apRequest)->vfn_0c();
    m_uiContentCount = 1;
    reinterpret_cast<::fnv_009db950::MoverState *>(this)->ResetMoverState(0);
    if (!reinterpret_cast<::FUN_006a9520_Class *>((((::BackgroundPathLocation14 *)(::FUN_006a9540((char *)(((PathingRequest*)apRequest)))))))->FUN_006a9520())
    {
        BackgroundPathLocation14* locA5 = &((PathingRequest*)apRequest)->GetOffsetC();
        BackgroundPathLocation14* locB2 = ((::BackgroundPathLocation14 *)(::FUN_006a9540((char *)(((PathingRequest*)apRequest)))));
        uintptr_t cell2 = ((uintptr_t)(reinterpret_cast<::PathingLocation *>((void *)(locA5))->GetContainingCell()));
        bool bNotInterior2 = !(cell2 != 0 && reinterpret_cast<::TESObjectCELL *>((((Cell14*)cell2)))->IsCellInterior());
        bool same3 =
            bNotInterior2 ? (((void *)(reinterpret_cast<::BGSTerrainManager *>((locA5))->GetMinLevel())) == ((void *)(reinterpret_cast<::BGSTerrainManager *>((locB2))->GetMinLevel()))) : (cell2 == ((uintptr_t)(reinterpret_cast<::PathingLocation *>((void *)(locB2))->GetContainingCell())));
        bool zA3 = (reinterpret_cast<::TaskQueueInterface *>((void *)(locA5))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr).z < reinterpret_cast<::FUN_0057b0a0_shell *>((void *)(m_actor))->FUN_0057b0a0() + 50.0f);
        bool zB9 = (reinterpret_cast<::TaskQueueInterface *>((void *)(locB2))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr).z < reinterpret_cast<::FUN_0057b0a0_shell *>((void *)(m_actor))->FUN_0057b0a0() + 50.0f);
        if (same3 && !zA3 && !zB9)
        {
            NiPoint3 diff8 = reinterpret_cast<::TaskQueueInterface *>((void *)(locA5))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr) - reinterpret_cast<::TaskQueueInterface *>((void *)(locB2))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
            if ((double)reinterpret_cast<::FUN_00595c80_shell *>((void *)(((NiPoint3_sub*)&diff8)))->GetSquaredXYLength() <=
                (double)reinterpret_cast<::PathingRequest *>((void *)(((PathingRequest*)apRequest)))->GetCenterRadius() *
                    (double)reinterpret_cast<::PathingRequest *>((void *)(((PathingRequest*)apRequest)))->GetCenterRadius())
            {
                if ((double)std::abs(diff8.z) <= (double)((PathingRequest*)apRequest)->GetSmoothingRandomness())
                {
                    reinterpret_cast<::fnv_009dd1c0::FUN_009dd1c0_shell *>(this)->FUN_009dd1c0(1);
                    bool flag = true;
                    if (reinterpret_cast<::FUN_00505c00_shell *>((((PathingRequest*)apRequest)))->FUN_00505c00())
                    {
                        flag = reinterpret_cast<::MovementUpdate *>(this)->FUN_009dce80(reinterpret_cast<::FUN_00507e10_shell *>((((PathingRequest*)apRequest)))->FUN_00507e10(), true);
                    }
                    return flag;
                }
            }
        }
    }
    switch (((PathingRequest*)apRequest)->vfn_10())
    {
    case 0: {
        m_req = new FUN_006e26a0(apRequest);
        break;
    }
    case 3: {
        m_req = new FUN_006e5400(apRequest);
        break;
    }
    case 4: {
        m_req = new FUN_006e5640(apRequest);
        break;
    }
    case 5: {
        m_req = new FUN_006e5940(apRequest);
        break;
    }
    case 6: {
        m_req = new FUN_006e6010(apRequest);
        break;
    }
    case 7: {
        m_req = new FUN_006e5db0(apRequest);
        break;
    }
    case 8: {
        m_req = new FUN_006e4d20(apRequest);
        break;
    }
    }
    reinterpret_cast<::PathingLocation *>(&(((PathingRequest*)m_req)->GetOffsetC()))->ResetLocation();
    reinterpret_cast<::PathingLocation *>((((::BackgroundPathLocation14 *)(::FUN_006a9540((char *)(((PathingRequest*)m_req)))))))->ResetLocation();
    reinterpret_cast<::PathingActorData *>((((PathingRequest*)m_req)))->operator=((*(const ::PathingActorData *)(m_actor)));
    reinterpret_cast<::TESForm *>(this)->ClearData();
    reinterpret_cast<::TESObjectMISC *>((((PathingRequest*)m_req)))->SetLoopingSound((::TESSound *)(m_84 + 3));
    if (!m_failed && m_handler != 0)
    {
        m_handler->v38((PathingRequest*)m_req);
    }
    if (m_handler != 0 && m_handler->v34())
    {
        ::fnv_009e71b0::FUN_009e71b0(m_actor, (::fnv_009e71b0::Request75 *)(::PathingRequest *)((PathingRequest*)m_req), (::fnv_009e71b0::Handler75 *)(m_handler));
    }
    else
    {
        if (m_actor->FUN_008d6f30() != 0)
        {
            if (FUN_00450ff0(m_actor->FUN_008d6f30()))
            {
                ::fnv_009e71b0::FUN_009e71b0(m_actor, (::fnv_009e71b0::Request75 *)(::PathingRequest *)((PathingRequest*)m_req), (::fnv_009e71b0::Handler75 *)(void *)(0));
            }
        }
    }
    {
        sleeping = _g_thePlayer->IsSleepingOrResting();
        if ((ActorPathingMessageQueue*)m_queue == 0)
        {
            reinterpret_cast<::FakeHolder *>((((BackgroundQueueAssign14*)&m_queue)))->AssignObject(new ActorPathingMessageQueue());
        }
        if (!reinterpret_cast<::PathManager *>((((PathManager14*)GetPathManager())))->BuildPath(m_req, m_queue, !sleeping))
        {
            (FUN_009daf80)((TESForm*)this);
            m_uiContentCount = 7;
            reinterpret_cast<::ActorMovement::Mover *>(this)->SetEnabled(1);
        }
        else
        {
            m_waiting = 1;
            result5 = true;
        }
    }
    return result5;
}

class Actor;
struct FUN_0087b650_shell
{
public:
    void QueueActorLocationTask(::Actor *, void *);
};
// Checks the pathing request/solution state, swaps m_24 for a new handler, then calls vfn_04 and HandlePathResult with the result.
// @fnv 0x009dbdc0
void ThisCls::UpdatePathingState(float a1)
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
    bool flag;
    if (::GetObjectFlags((char *)(((::SolT *)(::FUN_00559450((int *)&(m_20)))))) > 0)
    {
        if (m_28->FUN_00931850())
        {
            flag = false;
            reinterpret_cast<::PathingActorData *>((((::ReqT *)(::FUN_00559450((int *)&(m_1c))))))->operator=((*(const ::PathingActorData *)(m_28)));
            switch (FUN_006d53b0((PathingRequest*)((::ReqT *)(::FUN_00559450((int *)&(m_1c)))), (PathingSolution*)((::SolT *)(::FUN_00559450((int *)&(m_20))))))
            {
                break;
            case -1:
            case 0:
                m_6c = 7;
                SetEnabled(1);
                return;
            }
        }
        else
        {
            flag = true;
        }
    }
    else
    {
        if (!m_28->FUN_00931850())
        {
            flag = true;
            reinterpret_cast<::PathingActorData *>((((::ReqT *)(::FUN_00559450((int *)&(m_1c))))))->operator=((*(const ::PathingActorData *)(m_28)));
            switch (::QueryPathScope((PathingRequest*)((::ReqT *)(::FUN_00559450((int *)&(m_1c)))), (PathingSolution*)((::SolT *)(::FUN_00559450((int *)&(m_20)))), (void *)(0)))
            {
                break;
            case -1:
            case 0:
                reinterpret_cast<::MoveActor *>((m_28))->TryMove(1);
                m_6c = 7;
                SetEnabled(1);
                return;
            }
        }
        else
        {
            flag = false;
        }
    }
    if (flag)
    {
        m_40 = reinterpret_cast<::FUN_009611e0_shell *>((((::SolT *)(::FUN_00559450((int *)&(m_20))))))->FUN_009611e0();
        m_42 = ((int)(reinterpret_cast<::BGSTerrainManager *>((((::SolT *)(::FUN_00559450((int *)&(m_20))))))->GetMinLevel()));
        HandlerX* old = m_24;
        m_24 = (HandlerX*)new FUN_009e0190(m_28, this, m_20, ((::ReqT *)(::FUN_00559450((int *)&(m_1c)))));
        m_24->vfn_58(old);
        if (old)
        {
            delete old;
        }
    }
    else
    {
        m_40 = 0;
        m_42 = ((int)(::FUN_005a4320((char *)(((::SolT *)(::FUN_00559450((int *)&(m_20)))))))) - 1;
        if (m_24)
        {
            delete m_24;
        }
        m_24 = (HandlerX*)new FUN_009ea770(m_28, this, m_20, ((::ReqT *)(::FUN_00559450((int *)&(m_1c)))));
    }
    int res = m_24->vfn_04(0.0f, a1);
    reinterpret_cast<::ActorMoverX *>(this)->HandlePathResult(res);
}
// Advances the actor along the path: recomputes the current segment from handler progress, updates or extends the path, and rebuilds the handler.
// @fnv 0x009dd2d0
void FUN_009dd2d0_cls::UpdatePathMovement()
{
    unsigned current;
    float progress;
    uintptr_t next;
    int result6;
    float fraction;
    if (!((::PathSolution *)(::FUN_00559450((int *)&(path)))) || !((::PathRequest *)(::FUN_00559450((int *)&(request)))))
    {
        delete handler;
        handler = 0;
        state = 6;
        Finish(0);
        return;
    }
    if (actor->Exists())
    {
        if (!handler->Finished())
            return;
        if (last == first)
            current = last + 1;
        else
        {
            progress = handler->Progress();
            current = (unsigned)(int)::FUN_004e4450((last - first) * progress);
            current += first;
        }
        if (current > ::FUN_005a4320((char *)(((::PathSolution *)(::FUN_00559450((int *)&(path)))))) - 1)
            current = ::FUN_005a4320((char *)(((::PathSolution *)(::FUN_00559450((int *)&(path)))))) - 1;
        reinterpret_cast<::PathingActorData *>((((::PathRequest *)(::FUN_00559450((int *)&(request))))))->operator=((*(const ::PathingActorData *)(actor)));
        switch (::FUN_006d53b0((::PathingRequest *)(::PathRequest *)(((::PathRequest *)(::FUN_00559450((int *)&(request))))), (::PathingSolution *)(::PathSolution *)(((::PathSolution *)(::FUN_00559450((int *)&(path)))))))
        {
        case 1:
            first = (unsigned short)current;
            last = (unsigned short)(::FUN_005a4320((char *)(((::PathSolution *)(::FUN_00559450((int *)&(path)))))) - 1);
            break;
        case -1:
        case 0:
            state = 7;
            Finish(1);
            return;
        }
        delete handler;
        handler = new SmallPathHandler(actor, this, &path, ((::PathRequest *)(::FUN_00559450((int *)&(request)))));
        handler->Start((float)first, 0.0f);
        return;
    }
    if (handler->Finished())
        next = first + 1;
    else
        next = handler->Current() > 0 ? handler->Current() - 1 : 0;
    if (next >= ::FUN_005a4320((char *)(((::PathSolution *)(::FUN_00559450((int *)&(path)))))) - 1)
    {
        if (::FUN_008c7aa0())
            reinterpret_cast<::FUN_0087b650_shell *>((((::SpecialPathActor *)(::TaskQueueInterface::GetSingleton()))))->QueueActorLocationTask((::Actor *)&(const ::PathVec &)((*(::PathVec *)&(reinterpret_cast<::TaskQueueInterface *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))->Last()->GetData()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))), {});
        else
            ((MoveActor*)actor)->MoveTo((*(::PathVec *)&(reinterpret_cast<::TaskQueueInterface *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))->Last()->GetData()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))));
        reinterpret_cast<::fnv_009dd1c0::FUN_009dd1c0_shell *>(this)->FUN_009dd1c0(1);
        return;
    }
    reinterpret_cast<::PathingActorData *>((((::PathRequest *)(::FUN_00559450((int *)&(request))))))->operator=((*(const ::PathingActorData *)(actor)));
    switch (::QueryPathScope(((::PathRequest *)(::FUN_00559450((int *)&(request)))), ((::PathSolution *)(::FUN_00559450((int *)&(path)))), (void *)(next)))
    {
    case 2:
        first = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))))->FUN_009611e0()));
        last = reinterpret_cast<::BGSTerrainManager *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))))->GetMinLevel();
        break;
    case -1:
    case 0:
        if (reinterpret_cast<::FUN_006b05d0_shell *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))))->FUN_006b05d0() && ((bool)(reinterpret_cast<::FUN_006a9560_Class *>((((::PathRequest *)(::FUN_00559450((int *)&(request))))))->GetByteAtOffset9B())) && ((void *)(::GetObjectFlags((char *)(((::PathSolution *)(::FUN_00559450((int *)&(path)))))))))
        {
            first = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))))->FUN_009611e0()));
            last = reinterpret_cast<::BGSTerrainManager *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))))->GetMinLevel();
        }
        else
        {
            reinterpret_cast<::MoveActor *>((actor))->TryMove(1);
            state = 8;
            Finish(1);
            return;
        }
        break;
    }
    if (first == last)
    {
        reinterpret_cast<::fnv_009dd1c0::FUN_009dd1c0_shell *>(this)->FUN_009dd1c0(1);
        return;
    }
    fraction = 0.0f;
    if (!handler->Finished())
    {
        PathVec startPoint = (*(::PathVec *)&(reinterpret_cast<::TaskQueueInterface *>((((::PathEntry *)(reinterpret_cast<::FUN_006e78b0_shell *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))))->FUN_006e78b0(((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))))->FUN_009611e0())))))->GetData()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
        PathVec endPoint6 = (*(::PathVec *)&(reinterpret_cast<::TaskQueueInterface *>((((::PathEntry *)(reinterpret_cast<::FUN_006e78b0_shell *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))))->FUN_006e78b0(reinterpret_cast<::BGSTerrainManager *>((((::PathSolution *)(::FUN_00559450((int *)&(path))))))->GetMinLevel())))->GetData()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
        float distance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::PathVec &)((endPoint6 - startPoint)))->ComputeMagnitude();
        fraction = handler->Distance() / distance;
    }
    delete handler;
    handler = new LargePathHandler(actor, this, &path, ((::PathRequest *)(::FUN_00559450((int *)&(request)))));
    result6 = handler->Start(fraction, 0.0f);
    if (result6 == 5 || result6 == 6)
    {
        reinterpret_cast<::ActorMoverX *>(this)->HandlePathResult(result6);
        reinterpret_cast<::fnv_009dd1c0::FUN_009dd1c0_shell *>(this)->FUN_009dd1c0(1);
    }
}

struct FUN_0087b190_shell
{
    void QueueActorTask(Actor*);
};

struct SetLoc_S
{
};

struct PlayerSleepView
{
};
struct TESWorldSpace_SV
{
};

struct TESObjectREFR_Ext : TESObjectREFR
{
};

struct ActorMoverLocation14
{
    void* vtable;
    NiPoint3 m_kLookAtTargetPosition;
    NiPoint3 m_kPathingDelta;
    void* request;
    NiPointer<NiNode> m_pActorNode;
    ActorPathHandler* m_pPathHandler;
    Actor* pActor;

    bool FUN_009df010(const NiPoint3& aNewLoc);
};

// @fnv 0x009df010
bool ActorMoverLocation14::FUN_009df010(const NiPoint3& aNewLoc)
{
    if (::FUN_008c7aa0())
    {
        ((FUN_0087b650_shell*)::TaskQueueInterface::GetSingleton())->QueueActorLocationTask(pActor, (void *)(&aNewLoc));
        ((FUN_0087b190_shell*)::TaskQueueInterface::GetSingleton())->QueueActorTask(pActor);
    }
    else
    {
        pActor->Unk_AA((NiPoint3&)aNewLoc);
    }

    reinterpret_cast<::Reference *>((((SetLoc_S*)pActor)))->FUN_00575830((::Position *)&(aNewLoc));

    TESWorldSpace_SV* pworld = (TESWorldSpace_SV*)((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((void *)(pActor))->FUN_00575d70()));
    if (!pworld)
        return true;

    TESObjectCELL* pcurrentCell = pActor->GetParentCell();
    TESObjectCELL* pnewcell = reinterpret_cast<::fnv_00587550::FUN_00587550_shell *>((pworld))->FUN_00587550((const ::fnv_00587550::NiPoint3 &)(aNewLoc));
    if (pcurrentCell != pnewcell)
    {
        ::fnv_00573800::FUN_00573800((::fnv_00573800::MoveRef *)(pActor), (::fnv_00573800::MoveCell *)(::TESObjectCELL *)(0), (::fnv_00573800::MoveWorld *)(pworld));
    }

    if (!pActor->GetProcessTier() && !reinterpret_cast<::PlayerCharacter *>((((PlayerSleepView*)(*reinterpret_cast<::Actor884750 * *>(&::_g_thePlayer)))))->IsSleepingOrResting())
        return false;

    return true;
}

namespace PathEndCheck14 {
struct Node
{
};
struct Solution
{
};
struct SolutionPtr
{
    Solution* object;
};
struct Handler
{
    void* vtable;
    unsigned int unk04, unk08;
    SolutionPtr path;
};
struct Mover
{
    void* vtable;
    ::NiPoint3 m_kLookAtTargetPosition, m_kPathingDelta;
    void* request;
    SolutionPtr currentPath;
    Handler* m_pPathHandler;
    ::Actor* pActor;
    unsigned int unk2c, unk30, unk34;
    unsigned int m_uiMovementFlags, m_uiMovementMode;
    unsigned short currentNode, lastNode;
    unsigned int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    int eState;
    int FUN_009dc980();
};

// Handles a zero lastNode case, checks the current path node, and conditionally calls path routines before returning 0, 1, or 2.
// @fnv 0x009dc980
int Mover::FUN_009dc980()
{
    Node* pnode;
    if (!lastNode)
    {
        eState = 7;
        reinterpret_cast<::ActorMovement::Mover *>(this)->SetEnabled(true);
        reinterpret_cast<::ActorMover *>(this)->StopMoving();
        return 2;
    }
    currentNode = lastNode;
    if (::GetObjectFlags((char *)(((::PathEndCheck14::Solution *)(::FUN_00559450((int *)&(currentPath)))))) > 0)
    {
        pnode = &(*(::PathEndCheck14::Node *)(reinterpret_cast<::S_FUN_006b05a0 *>((((::PathEndCheck14::Solution *)(::FUN_00559450((int *)&(currentPath))))))->FUN_006b05a0()));
        if (reinterpret_cast<::FUN_006e2330_shell *>((pnode))->FUN_006e2330())
        {
            if (!reinterpret_cast<::FUN_006e22f0_shell *>((pnode))->FUN_006e22f0(pActor) && !((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pActor))->GetBaseTexture()))->GetCurrentFadeState())
            {
                eState = 7;
                reinterpret_cast<::ActorMovement::Mover *>(this)->SetEnabled(true);
                reinterpret_cast<::ActorMover *>(this)->ClearMovementPath();
                return 2;
            }
            else
            {
                ::FUN_006c93a0((::Dummy_006c93a0 *)(::PathEndCheck14::Solution *)(((::PathEndCheck14::Solution *)(::FUN_00559450((int *)&(currentPath))))));
                return 1;
            }
        }
    }
    if (currentNode >= ::FUN_005a4320((char *)(((::PathEndCheck14::Solution *)(::FUN_00559450((int *)&(m_pPathHandler->path)))))) - 1)
        reinterpret_cast<::ActorMover *>(this)->ClearMovementPath();
    return 0;
}
}

#include "generated/data/fallout/ai/movement/actormover.inc"
