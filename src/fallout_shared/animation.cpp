#include "AutoMemContext.h"
// fallout_shared/animation.cpp: TESAnimGroup, Animation, AnimSequenceMultiple, TaskQueueInterface and more (156 functions)

#include <cstdint>
#include "fnv/game_timer.h"
#include <new>
#include <cctype>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/AnimationSequence.h"
#include "fnv/decl/B4EFE80Object.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BindSequence.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/ControllerOwner.h"
#include "fnv/decl/CtrlSeqOwner.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FOPipboyManager.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00445200_holder.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_0047d3b0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_0048fb20_Class.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_004938c0_class.h"
#include "fnv/decl/FUN_004938e0_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_0049c250_shell.h"
#include "fnv/decl/FUN_0049c510.h"
#include "fnv/decl/FUN_0049c5d0_cls.h"
#include "fnv/decl/FUN_004d8a00_Class.h"
#include "fnv/decl/FUN_004eeb00.h"
#include "fnv/decl/FUN_004eec60_shell.h"
#include "fnv/decl/FUN_004eecb0_Class.h"
#include "fnv/decl/FUN_004efa50_Holder.h"
#include "fnv/decl/FUN_004efb10_shell.h"
#include "fnv/decl/FUN_004f0040_shell.h"
#include "fnv/decl/FUN_004f05c0_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_00507b00Class.h"
#include "fnv/decl/FUN_0054da00_class.h"
#include "fnv/decl/FUN_005597d0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0058d630_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f23e0_shell.h"
#include "fnv/decl/FUN_005f2b60_cls.h"
#include "fnv/decl/FUN_005f3780_shell.h"
#include "fnv/decl/FUN_005f4c40_shell.h"
#include "fnv/decl/FUN_005ff770_shell.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00621b00_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00857bd0.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a16d0_shell.h"
#include "fnv/decl/FUN_008a7570_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b0140_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a30160_cls.h"
#include "fnv/decl/FUN_00a307c0_cls.h"
#include "fnv/decl/FUN_00a30c80_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a6e960_shell.h"
#include "fnv/decl/FUN_00b63680_shell.h"
#include "fnv/decl/FUN_00c75b40_cls.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ListHolder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiPointer_KFModel.h"
#include "fnv/decl/NiRefObject.h"
#include "fnv/decl/NiTMapBase.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S004eee_Owner.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SaveOwner_b9539.h"
#include "fnv/decl/SeqA34f20.h"
#include "fnv/decl/StrOwner.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegionDataMap.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TargetClass.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_004471c0__FUN_004471c0_shell.h"
#include "fnv/decl/fnv_00451530__FUN_00451530_shell.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004efb20__FUN_004efb20_shell.h"
#include "fnv/decl/fnv_004efbc0__HY.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_0087ac60__FUN_0087AC60_Holder.h"
#include "fnv/decl/fnv_0087ad00__H0087ad00.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00897910__AnimOwner.h"
#include "fnv/decl/fnv_008a73e0__FUN_008a73e0_shell.h"
#include "fnv/decl/fnv_008b28c0__This8b.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00a328b0__SeqExt.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0047b000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00490000.h"
#include "fnv/symbols_00491000.h"
#include "fnv/symbols_00493000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_00496000.h"
#include "fnv/symbols_00497000.h"
#include "fnv/symbols_00499000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005f2000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00716000.h"
#include "fnv/symbols_00718000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_00a2e000.h"
#include "fnv/symbols_00a2f000.h"
#include "fnv/symbols_00a58000.h"
#include "fnv/symbols_00a6e000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b4f000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_00c4b000.h"
#include "fnv/symbols_00c81000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_0102c000.h"
#include "fnv/symbols_01197000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01267000.h"
#include "animation_decls.h"
// @fnv 0x0048f810
Animation::Animation() : m_acHeaderData(0), m_acReservedBytes(0), LocalInput(0), LocalStateValue(0)
{
    m_acHeaderData = 0;
    m_pObjectNode = 0;
    m_kNodeTranslation = NiPoint3::ZERO;
    m_kRootTranslation = NiPoint3::ZERO;
    m_fAnimationAmount = 0.0f;
    m_cState = -1;
    m_cSkipNextBlend = 0;
    reinterpret_cast<::FUN_0048fb20_Class *>(this)->UpdateFlags(0, 255, 0);
    m_pAttachedReference = 0;
    m_pCurrentSequence = 0;
    time = 0.0f;
    m_acReservedBytes = 0;
    LocalInput = 0;
    LocalStateValue = 0;
    LocalOutput[0] = 0;
    LocalOutput[1] = 0;
    m_pOwnerReference = new NiTPointerMap<unsigned short, AnimSequenceBase*>(101);
    memset(m_acNodeName, 0, 32);
    memset(m_pChildTile, 0, 32);
    memset(group, 255, 16);
    memset(usReloadGroup, 255, 16);
    memset(action, -1, 32);
    memset(m_acTargetName, -1, 32);
    memset(m_acAnimationName, -1, 32);
    m_fMovementRate = 1.0f;
    m_fCombatAnimationRate = 1.0f;
    m_fEquipAnimationRate = 1.0f;
    m_fReloadAnimationRate = 1.0f;
    m_fAnimationTimeScale = 1.0f;
    m_usQueuedGroup = 255;
    m_bIsPlaying = false;
}

struct FUN_0048ef40_shell : public AnimSequenceBase
{
    void FUN_0048ef40();
};

extern int DAT_0101d8e8;

// @fnv 0x0048ef40
void FUN_0048ef40_shell::FUN_0048ef40()
{
    *(int**)this = &DAT_0101d8e8;
}

namespace fnv_0048f010 {
struct TESAnimGroup;
struct AnimSequenceSingle : public AnimSequenceBase
{
    virtual void __vslot_0();
    virtual bool IsSingleSeq();
    virtual void AssignSequence(BSAnimGroupSequence*, bool);
    virtual bool SetSequenceActive(BSAnimGroupSequence*, bool);
    virtual BSAnimGroupSequence* GetSequenceAtIndex(char);
    virtual BSAnimGroupSequence* GetControllerSequence(TESAnimGroup*);
    virtual char ContainsSequence(BSAnimGroupSequence*);
    void __local_vftable_ctor_closure();
    BSAnimGroupSequence* pForwardSequence;
};
struct FUN_0048f010_shell : public AnimSequenceSingle
{
    void SetAnimSequence(BSAnimGroupSequence*, bool);
};

template <typename K, typename V> struct NiTMap
{
    void NewItem(void*);
};
class CombatThreatRecord;
class NiAVObject
{
  public:
    NiFixedString& GetName();
    void FUN_00401970();
};
struct WaitableObject
{
};

// @fnv 0x0048f010
void FUN_0048f010_shell::SetAnimSequence(BSAnimGroupSequence* apSeq, bool abReleaseModelLoader)
{
    if (pForwardSequence)
    {
        if (abReleaseModelLoader)
        {
            ((NiTMap<unsigned int, CombatThreatRecord*>*)g_modelLoader)
                ->NewItem((void*)(const char*)(*(::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((((NiAVObject*)pForwardSequence)))->GetLinkToList())));
        }
        ((NiAVObject*)pForwardSequence)->FUN_00401970();
    }
    pForwardSequence = apSeq;
    if (pForwardSequence)
    {
        reinterpret_cast<::FUN_0040f6e0_class *>((((WaitableObject*)pForwardSequence)))->FUN_0040f6e0();
    }
}
}  // namespace fnv_0048f010

extern int DAT_0101d908;

struct GlobalObject_0048f200
{
    int pad[3];
    GlobalObject_0048f200();
};

struct SingleSeq
{
    virtual ~SingleSeq();
    virtual void AssignSequence(BSAnimGroupSequence*, bool);
    virtual void __vslot_2();
    virtual void __vslot_3();
    virtual BSAnimGroupSequence* GetSequenceAtIndex(int);
};

struct FUN_0048f1b0
{
    void* m_ppVirtualMethodTable;
    FUN_0048f1b0();
    ~FUN_0048f1b0();
};

struct FUN_0048f0c0 : public FUN_0048f1b0
{
    void* m_pSingleSequence;
    FUN_0048f0c0(SingleSeq* apSingleSeq);
};

extern int DAT_0101d8e8;

// @fnv 0x0048f1b0
int* FUN_0048f1b0(int* pThis)
{
    *pThis = (std::intptr_t)&DAT_0101d8e8;
    return pThis;
}


// @fnv 0x0048f200
void* FUN_0048f200(void* pThis)
{
    ::FUN_00718d90((::InventoryStackRecord *)(pThis));
    return pThis;
}

struct TESAnimGroup;
class TESObjectREFR;
struct SequenceListHead48
{
};
struct FUN_006317a0_struct
{
    intptr_t AddEight(intptr_t);
};
template <class T> struct NiTPointerList_SV
{
    void* DereferenceIfNotNull(void*) const;
};
struct AnimSequenceMultiple
{
    int _00;
    SequenceListHead48* m_pSingleSequence;
    BSAnimGroupSequence* FUN_0048f790(TESAnimGroup* apAnimGroup);
};

struct FUN_0048f3a0_shell : public AnimSequenceMultiple
{
    void FUN_0048f3a0(BSAnimGroupSequence*, bool);
};
// @fnv 0x0048f0c0
FUN_0048f0c0::FUN_0048f0c0(SingleSeq* apSingleSeq)
{
    m_ppVirtualMethodTable = &DAT_0101d908;
    m_pSingleSequence = new GlobalObject_0048f200;
    reinterpret_cast<::FUN_0048f3a0_shell *>(this)->FUN_0048f3a0(apSingleSeq->GetSequenceAtIndex(-1), true);
    apSingleSeq->AssignSequence(0, false);
    delete apSingleSeq;
}

struct WaitableObject
{
public:
    void FUN_00401970();
};
struct ST_0048f3a0
{
};
// Calls a function on seq, then passes seq by address to a function on the object at this+4.
// @fnv 0x0048f3a0
void FUN_0048f3a0_shell::FUN_0048f3a0(BSAnimGroupSequence* seq, bool b)
{
    reinterpret_cast<::FUN_0040f6e0_class *>((((WaitableObject*)seq)))->FUN_0040f6e0();
    reinterpret_cast<::FUN_005597d0_shell *>(((*(ST_0048f3a0**)&this->m_pSingleSequence)))->FUN_005597d0((int *)(::BSAnimGroupSequence **)(&seq));
}

struct TaskQueueInterface
{
  public:
    void FUN_004902f0(bool);
public:
    static void CopyStringToBuffer(char *, unsigned int, const char *);
public:
    static ::TaskQueueInterface *GetSingleton();
public:
    void QueueReferenceStateTask(bool);
};

// @fnv 0x004902f0
void TaskQueueInterface::FUN_004902f0(bool bUpdate)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(bUpdate, 2);
}

class NiAVObject;
struct FUN_00490310_shell : public TESObjectREFR
{
    NiAVObject* FUN_00490310(NiAVObject*, NiFixedString*);
};


// @fnv 0x00490310
NiAVObject* FUN_00490310_shell::FUN_00490310(NiAVObject* apRoot, NiFixedString* apSearch)
{
    return ((::NiAVObject *)(::FUN_00c4b310((::ObjQ *)(apRoot), (const char *)(apSearch), 1)));
}

class NiAVObject;
namespace fnv_00490d90 {
struct FUN_00490d90_shell : public NiControllerManager
{
    NiAVObject* FUN_00490d90();
};

class GlobalObject_004aff00
{
  public:
    unsigned int GetSize(void);
};

template <class T, unsigned int N> class BSSimpleArray
{
  public:
    T& GetAt(unsigned int);
};

template <class T> class BSStringT
{
  public:
    operator const char*(void) const;
};

class TESChallenge
{
  public:
};

// @fnv 0x00490d90
NiAVObject* FUN_00490d90_shell::FUN_00490d90()
{
    if (this->unk68)
    {
        for (unsigned int uiIndex = 0;
             uiIndex < reinterpret_cast<::FUN_00658930_class *>((reinterpret_cast<GlobalObject_004aff00*>(reinterpret_cast<char*>(this) + 0x34)))->GetShortAtOffsetA();
             ++uiIndex)
        {
            if (reinterpret_cast<const BSStringT<char>&>(
                    reinterpret_cast<BSSimpleArray<unsigned int, 1024>*>(reinterpret_cast<char*>(this) + 0x34)
                        ->GetAt(uiIndex))
                    .
                    operator const char*())
            {
                return reinterpret_cast<NiAVObject*>(
                    ((std::intptr_t)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((const_cast<TESChallenge*>(
                        reinterpret_cast<const TESChallenge*>(reinterpret_cast<const BSStringT<char>&>(
                                                                  reinterpret_cast<BSSimpleArray<unsigned int, 1024>*>(
                                                                      reinterpret_cast<char*>(this) + 0x34)
                                                                      ->GetAt(uiIndex))
                                                                  .
                                                                  operator const char*()))))->FUN_005f5f80())));
            }
        }
    }
    return 0;
}
}  // namespace fnv_00490d90

struct TESAnimGroup;
struct AnimSequenceSingle : public AnimSequenceBase
{
    virtual void __vslot_0();
    virtual bool IsSingleSeq();
    virtual void AssignSequence(BSAnimGroupSequence*, bool);
    virtual bool SetSequenceActive(BSAnimGroupSequence*, bool);
    virtual BSAnimGroupSequence* GetSequenceAtIndex(char);
    virtual BSAnimGroupSequence* GetControllerSequence(TESAnimGroup*);
    virtual char ContainsSequence(BSAnimGroupSequence*);
    void __local_vftable_ctor_closure();
    BSAnimGroupSequence* pForwardSequence;
};
struct FUN_00490e10_shell : public AnimSequenceSingle
{
    void ConstructAnimSequenceSingle(void*);
};

void FUN_0048f1b0(void* pThis);
extern int DAT_0101d8c8;

// @fnv 0x00490e10
void* ConstructAnimSequenceSingle(AnimSequenceSingle* pThis)
{
    FUN_0048f1b0(pThis);
    *reinterpret_cast<void**>(pThis) = &DAT_0101d8c8;
    pThis->pForwardSequence = 0;
    return pThis;
}

namespace fnv_00490e40 {
struct FUN_00490e40_shell : public AnimIdle
{
    BSAnimGroupSequence* FUN_00490e40();
};

template <class T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x00490e40
BSAnimGroupSequence* FUN_00490e40_shell::FUN_00490e40()
{
    return (BSAnimGroupSequence*)(const char*)*(BSStringT<char>*)((char*)this + 0x18);
}
}  // namespace fnv_00490e40

namespace fnv_00490f80 {
template <class T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x00490f80
const char* FUN_00490f80(char* pThis)
{
    return *(const BSStringT<char>*)(pThis + 0x69c);
}
}  // namespace fnv_00490f80

class NiSkinInstance;

class NiTriBasedGeom
{
  public:
};

struct _FakeNiAVObject
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual NiNode* IsSceneNode();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual NiTriBasedGeom* IsTriBasedGeom();
};

struct _FakeNiNode
{
    unsigned int FUN_0043b480();
};

// Recursively checks whether apAVObject or any descendant is a NiTriBasedGeom with a skin instance, returning true if found.
// @fnv 0x004910d0
bool __cdecl FUN_004910d0(NiAVObject* apAVObject)
{
    bool bretVal = false;
    if (!apAVObject)
        return bretVal;

    NiTriBasedGeom* pGeom = reinterpret_cast<_FakeNiAVObject*>(apAVObject)->IsTriBasedGeom();
    if (pGeom && ((::NiSkinInstance *)(::fnv_0043fad0::FUN_0043fad0((const char *)(pGeom)))))
        return true;

    NiNode* pnode = reinterpret_cast<_FakeNiAVObject*>(apAVObject)->IsSceneNode();
    if (pnode)
    {
        for (unsigned int n = 0; n < reinterpret_cast<_FakeNiNode*>(pnode)->FUN_0043b480(); ++n)
        {
            NiAVObject* pChildObject = reinterpret_cast<::NiNode *>((reinterpret_cast<_FakeNiNode*>(pnode)))->GetAt(n);
            if (pChildObject)
            {
                bretVal = FUN_004910d0(pChildObject);
                if (bretVal)
                    return bretVal;
            }
        }
    }
    return bretVal;
}

struct FUN_00493750_Helper
{
    char pad[0x10];
    char val;
};

// @fnv 0x00493750
int FUN_00493750(const FUN_00493750_Helper* apHelper)
{
    return apHelper->val;
}

struct FUN_00493770_shell : public NiControllerSequence
{
    float FUN_00493770();
};

class BGSCameraShot
{
  public:
};

struct NiControllerSequence_helper
{
};

namespace fnv_004937a0 {
struct NiInterpolator;
struct FUN_004937a0_shell : public NiControllerSequence
{
    NiInterpolator* FUN_004937a0(unsigned int);
};

// @fnv 0x004937a0
template <class T> class BSStringT
{
  public:
    operator const T*() const;
};
NiInterpolator* FUN_004937a0_shell::FUN_004937a0(unsigned int i)
{
    return (NiInterpolator*)(const char*)*(BSStringT<char>*)((char*)(*(char**)((char*)this + 0x14)) + (i << 4));
}
}  // namespace fnv_004937a0

namespace fnv_00493800 {
class BGSCameraShot
{
  public:
    float FUN_00639aa0(void);
};

struct FUN_00493800_impl : public Animation
{
    float FUN_00493800(BGSCameraShot* apSequence);
};

// @fnv 0x00493800
float FUN_00493800_impl::FUN_00493800(BGSCameraShot* apSequence)
{
    return apSequence->FUN_00639aa0() + this->time;
}
}  // namespace fnv_00493800

struct FUN_00493830_shell : public Animation
{
    bool FUN_00493830();
};

bool _ref_008256d0(void* pThis);

// @fnv 0x00493830
bool FUN_00493830_shell::FUN_00493830()
{
    return !_ref_008256d0(reinterpret_cast<char*>(&this->kfModelList));
}

struct FUN_00493860_shell : public Animation
{
    void FUN_00493860(bool);
};

struct ST_00493860
{
};
struct FUN_00493b90_shell : public Animation
{
    bool FUN_00493b90();
};

struct FUN_00493990_helper
{
};

struct FUN_004941c0_shell : public NiPoint3
{
    NiPoint3* ScaleByInverse(float);
};

// Multiplies x, y and z by the reciprocal of fScalar and returns this.
// @fnv 0x004941c0
NiPoint3* FUN_004941c0_shell::ScaleByInverse(float fScalar)
{
    float fReciprocal = 1.0f / fScalar;
    x *= fReciprocal;
    y *= fReciprocal;
    z *= fReciprocal;
    return this;
}

namespace fnv_00494210 {
template <class T> struct BSStringT
{
    operator const char*() const;
};
struct BGSMessageInitAccess
{
};
struct FUN_00494210_item
{
    char pad[4];
    BSStringT<char> s;
    char pad2[0xb];
};
struct FUN_00494210_cls
{
    char pad[0x14];
    FUN_00494210_item* items;
    unsigned int GetItemIconFormID(unsigned int i);
};
// @fnv 0x00494210
unsigned int FUN_00494210_cls::GetItemIconFormID(unsigned int uiIndex)
{
    if (items[uiIndex].s.operator const char*())
        return reinterpret_cast<::BGSMessageInitAccess *>((((BGSMessageInitAccess*)items[uiIndex].s.operator const char*())))->GetIconFormID();
    return 0;
}
}  // namespace fnv_00494210

struct NiStream;
struct blob32
{
    char b[32];
};
struct NiQuatTransform
{
    void* GetTranslate();
    void GetTransformScale(void*);
    void* GetRotate();
    void SetLocalRotation(void*);
    float GetScale();
    void SetScale(float);
    bool IsTranslateValid();
    bool IsRotateValid();
    bool IsScaleValid();
    bool IsMarkedInvalid();
    void Invert(NiQuatTransform*);
    void TransformBy(NiQuatTransform*);
    struct blob32 CombineTransforms(void*);
    void MakeInvalid();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void GetViewerStrings(void*);
    void SetTranslateValid(bool);
    void SetRotateValid(bool);
    void SetScaleValid(bool);
    NiPoint3 m_kTranslate;
    char m_kRotate[16];
    float m_fScale;
};
struct FUN_004942c0_shell : public NiQuatTransform
{
    bool IsTranslateXNotNegatedConstant();
};

extern float DAT_0101d890;

// Returns whether m_kTranslate.x differs from the negation of DAT_0101d890.
// @fnv 0x004942c0
bool FUN_004942c0_shell::IsTranslateXNotNegatedConstant()
{
    return m_kTranslate.x != -DAT_0101d890;
}

struct FUN_00494300_shell : public Animation
{
    short FUN_00494300(unsigned short);
};

enum ANIM_GROUP_ENUM;
class TESAnimGroup
{
  public:
    float GetAnimationSpeed() const;
public:
    ::ANIM_GROUP_ENUM GetType() const;
public:
    static bool IsActionTypeValid(unsigned short);
public:
    static bool IsAimAnimation(unsigned short);
public:
    bool IsJumpAnimation() const;
};

struct AnimSequenceBase_vtable
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual bool vfn_c();
    virtual BSAnimGroupSequence* vfn_10(int);
};


// @fnv 0x00494300
short FUN_00494300_shell::FUN_00494300(unsigned short asAnimGroup)
{
    AnimSequenceBase* panimSeq;
    TESAnimGroup* panimGroup;

    if (!reinterpret_cast<::NiTMapBase *>((void *)(m_pOwnerReference))->Lookup(asAnimGroup, panimSeq))
        return 0;

    if (reinterpret_cast<AnimSequenceBase_vtable*>(panimSeq)->vfn_c())
    {
        if (!reinterpret_cast<AnimSequenceBase_vtable*>(panimSeq)->vfn_10(-1))
        {
            return 0;
        }
        else
        {
            panimGroup = reinterpret_cast<::BSAnimGroupSequence *>((void *)(reinterpret_cast<AnimSequenceBase_vtable*>(panimSeq)->vfn_10(-1)))->GetAnimGroup();
        }
    }
    else
    {
        return 0;
    }

    return panimGroup->GetAnimationSpeed();
}

struct TESAnimGroup;
struct FUN_004946a0_shell : public Animation
{
    void FUN_004946a0(TESAnimGroup*);
};

class TESActorBaseData
{
  public:
};

struct FUN_00493d50_helper
{
    void CheckAnimGroupMovement(TESAnimGroup*);
};

// @fnv 0x004946a0
void FUN_004946a0_shell::FUN_004946a0(TESAnimGroup* pAnimGroup)
{
    if (!pAnimGroup)
        return;

    if (this->group[1] == 0xff &&
        this->usReloadGroup[1] == 0xff &&
        reinterpret_cast<::FUN_0047d3b0_shell *>((reinterpret_cast<TESActorBaseData*>(pAnimGroup)))->FUN_0047d3b0() == 0)
    {
        this->usReloadGroup[1] =
            reinterpret_cast<::FUN_0047d3b0_shell *>((reinterpret_cast<TESActorBaseData*>(pAnimGroup)))->FUN_0047d3b0();
    }

    reinterpret_cast<FUN_00493d50_helper*>(this)->CheckAnimGroupMovement(pAnimGroup);
}

struct FUN_00494710_shell : public Animation
{
    bool FUN_00494710(unsigned short);
};

// @fnv 0x00494710
bool FUN_00494710_shell::FUN_00494710(unsigned short ausGroupIndex)
{
    AnimSequenceBase* panimSeq;
    return reinterpret_cast<::NiTMapBase *>((void *)(m_pOwnerReference))->Lookup(ausGroupIndex, panimSeq);
}

// @fnv 0x00495460
float GetFloatAtOffset1C(char* pThis)
{
    return *(float*)(pThis + 0x1c);
}

struct FUN_00495480_shell : public NiControllerSequence
{
    void FUN_00495480(float);
};

// Stores the given value at offset 0x1c and clamps it to a minimum of 0.0 if negative.
// @fnv 0x00495480
void FUN_00495480_shell::FUN_00495480(float afValue)
{
    *(float*)((char*)this + 0x1c) = afValue;
    if (*(float*)((char*)this + 0x1c) < 0.0)
    {
        *(float*)((char*)this + 0x1c) = 0.0f;
    }
}

// Returns the larger of the two bytes at offsets 0x29 and 0x2a of pThis.
// @fnv 0x004954e0
unsigned char GetMaxOfTwoBytes(unsigned char* pThis)
{
    return pThis[0x2a] > pThis[0x29] ? pThis[0x2a] : pThis[0x29];
}

// Returns the larger of the bytes at offsets 0x2b and 0x29 of pThis.
// @fnv 0x00495520
unsigned char GetMaxByte(unsigned char* pThis)
{
    return pThis[0x2b] > pThis[0x29] ? pThis[0x2b] : pThis[0x29];
}

struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag(void);
};


// @fnv 0x00495580
unsigned char FUN_00495580()
{
    return *(*reinterpret_cast<::ProcessLists *>(&::g_01267c30)).GetLifeStateControlFlag();
}

class NiAVObject;
struct ThreeByThreeMatrix;
struct RagdollAnimationData;
struct bhkConstraint;
struct bhkPoseArray;
struct bhkRagdollController;
struct bhkRigidBody;
struct bhkShapePhantom;
struct bhkWorld;
struct RigidBodyShape;
struct hkQsTransform;
struct hkVector4;
struct hkaFootPlacementIkSolver;
struct SkeletonPoseData;
struct FirstForwardDeclaredType;
struct hkaRagdollInstance;
struct SecondForwardDeclaredType;
struct hkaSkeleton;
struct RagdollController;
struct hkpConstraintMotor;
struct hkpRigidBody;
struct blob1
{
    char b[1];
};

// @fnv 0x004955a0
bool FUN_004955a0(bhkRagdollController* pThis)
{
    return *((bool*)pThis + 0x222);
}

namespace fnv_00495d00 {
struct FUN_00495d00_shell : public NiControllerManager
{
    unsigned int FUN_00495d00();
};

class GlobalObject_004aff00
{
  public:
    unsigned int GetSize(void);
};

// @fnv 0x00495d00
unsigned int FUN_00495d00_shell::FUN_00495d00()
{
    return reinterpret_cast<::FUN_00658930_class *>((((GlobalObject_004aff00*)((char*)this + 0x34))))->GetShortAtOffsetA();
}
}  // namespace fnv_00495d00

namespace fnv_00495d20 {
struct FUN_00495d20_shell : public NiControllerManager
{
    NiControllerSequence* FUN_00495d20(unsigned int);
};

template <typename T> class BSStringT
{
  public:
    operator const char*() const;
};

template <typename T, unsigned int N> class BSSimpleArray
{
  public:
    T& GetAt(unsigned int);
};

// Returns the controller sequence stored at the given index in the array at offset 0x34, reinterpreted as a NiControllerSequence pointer.
// @fnv 0x00495d20
NiControllerSequence* FUN_00495d20_shell::FUN_00495d20(unsigned int uiIndex)
{
    return (NiControllerSequence*)(const char*)reinterpret_cast<BSStringT<char>&>(
        reinterpret_cast<BSSimpleArray<unsigned int, 1024>*>((char*)this + 0x34)->GetAt(uiIndex));
}
}  // namespace fnv_00495d20

struct FUN_00495f30_shell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    std::intptr_t FUN_00495f30(int* out);
};

// @fnv 0x00495f30
std::intptr_t FUN_00495f30_shell::FUN_00495f30(int* piValue)
{
    *piValue = unk0C;
    return unk10;
}

namespace fnv_00496080 {
struct FUN_00496080_shell : public Animation
{
    void FUN_00496080(int, float);
};


template <typename T> class BSStringT
{
  public:
    operator const char*() const;
};

class TESChallenge
{
  public:
};

struct NiControllerManager_DeactivateAccess
{
};

// @fnv 0x00496080
void FUN_00496080_shell::FUN_00496080(int aeSection, float afEaseOutTime)
{
    int esection = aeSection;
    switch (esection)
    {
    case 20:
        if (::fnv_00702640::FUN_00702640() != 1)
        {
            FUN_00496080(7, afEaseOutTime);
            if (!this->m_cSkipNextBlend)
                FUN_00496080(0, afEaseOutTime);
        }
        FUN_00496080(1, afEaseOutTime);
    case 21:
        if (::fnv_00702640::FUN_00702640() != 1)
            FUN_00496080(2, afEaseOutTime);
        FUN_00496080(3, afEaseOutTime);
    case 4:
        FUN_00496080(5, afEaseOutTime);
        FUN_00496080(6, afEaseOutTime);
        esection = 4;
        break;
    }

    if (*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0xd8) && esection < 8 &&
        reinterpret_cast<NiControllerSequence**>(&this->m_pChildTile[0])[esection] &&
        ((std::intptr_t)(reinterpret_cast<::LowProcess *>((reinterpret_cast<NiControllerSequence**>(&this->m_pChildTile[0])[esection]))->GetActiveCombatTarget())))
    {
        if (reinterpret_cast<::LowProcess *>((reinterpret_cast<TESChallenge**>(&this->m_pChildTile[0])[esection]))->GetPackageObjectType())
        {
            reinterpret_cast<::NiControllerManager *>((reinterpret_cast<NiControllerManager_DeactivateAccess*>(
                const_cast<char*>(static_cast<const char*>(
                    *reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0xd8))))))->StopSequence(reinterpret_cast<NiControllerSequence*>(
                                   reinterpret_cast<::LowProcess *>((reinterpret_cast<TESChallenge**>(&this->m_pChildTile[0])[esection]))->GetPackageObjectType()),
                               afEaseOutTime);
        }
        reinterpret_cast<::NiControllerManager *>((reinterpret_cast<NiControllerManager_DeactivateAccess*>(
            const_cast<char*>(
                static_cast<const char*>(*reinterpret_cast<BSStringT<char>*>(reinterpret_cast<char*>(this) + 0xd8))))))->StopSequence(reinterpret_cast<NiControllerSequence**>(&this->m_pChildTile[0])[esection],
                           afEaseOutTime);
        if (esection == 1)
            *reinterpret_cast<NiControllerSequence**>(&this->m_pCurrentSequence) =
                reinterpret_cast<NiControllerSequence**>(&this->m_pChildTile[0])[esection];
    }

    reinterpret_cast<NiControllerSequence**>(&this->m_pChildTile[0])[esection] = 0;
    (&this->group[0])[esection] = 0xff;
    (&this->usReloadGroup[0])[esection] = 0xff;
    reinterpret_cast<int*>(&this->action[0])[esection] = -1;
}
}  // namespace fnv_00496080

struct FUN_00496280_shell : public Animation
{
    void FUN_00496280();
};


struct NiPoint3;
class NiAVObject
{
  public:
public:
    ::NiPoint3 &FUN_0043c490();
};

class Model
{
  public:
};

class NiTimeController
{
  public:
};

class NiBlendAccumTransformInterpolator
{
  public:
    void ResetAccumulation(void);
};

class FakeVtable_00496280
{
  public:
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
    virtual void* vc4(int);
};

namespace fnv_00496420 {
struct NiStream;
struct blob32
{
    char b[32];
};
struct NiQuatTransform
{
    void* GetTranslate();
    void GetTransformScale(void*);
    void* GetRotate();
    void SetLocalRotation(void*);
    float GetScale();
    void SetScale(float);
    bool IsTranslateValid();
    bool IsRotateValid();
    bool IsScaleValid();
    bool IsMarkedInvalid();
    void Invert(NiQuatTransform*);
    void TransformBy(NiQuatTransform*);
    struct blob32 CombineTransforms(void*);
    void MakeInvalid();
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void GetViewerStrings(void*);
    void SetTranslateValid(bool);
    void SetRotateValid(bool);
    void SetScaleValid(bool);
    NiPoint3 m_kTranslate;
    char m_kRotate[16];
    float m_fScale;
};
struct FUN_00496420_shell : public NiQuatTransform
{
    void FUN_00496420(float);
};

struct _CallHelper_FUN_00496420
{
    void FUN_004964a0(bool);
};

// @fnv 0x00496420
void FUN_00496420_shell::FUN_00496420(float fScale)
{
    m_fScale = fScale;
    reinterpret_cast<_CallHelper_FUN_00496420*>(this)->FUN_004964a0(true);
}
}  // namespace fnv_00496420

struct FUN_004964d0_shell : public Animation
{
    void FUN_004964d0();
};
// @fnv 0x00496280
void FUN_00496280_shell::FUN_00496280()
{
    if (this->m_pObjectNode == 0)
        return;

    reinterpret_cast<::FUN_004964d0_shell *>((this))->FUN_004964d0();
    reinterpret_cast<::FUN_0043fa80_s *>(((this->m_pObjectNode)))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&(*reinterpret_cast<char *>(&::DAT_011a9448)))));
    reinterpret_cast<::FUN_00440460_S *>(((*(NiAVObject**)&this->m_pObjectNode)))->FUN_00440460((const ::V3 *)&(NiPoint3::ZERO));

    NiTimeController* pTimeController = (NiTimeController*)(((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)((*(Model**)&this->m_pObjectNode))))));
    while (pTimeController)
    {
        FakeVtable_00496280* pinter = (FakeVtable_00496280*)((void *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<const char *const *>(&::g_011f3714))), (::NiObject *)(pTimeController))));
        if (pinter)
        {
            void* pinter2 = pinter->vc4(0);
            if (pinter2)
            {
                NiBlendAccumTransformInterpolator* pBlendInterpolator =
                    (NiBlendAccumTransformInterpolator*)((void *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f371c))), (::NiObject *)(pinter2))));
                if (pBlendInterpolator)
                {
                    pBlendInterpolator->ResetAccumulation();
                }
            }
        }
        pTimeController = ((::NiTimeController *)(::fnv_004a8a90::FUN_004a8a90((char *)(pTimeController))));
    }
}

// Sets the NiPoint3 at offset 0x1c of this Animation object to NiPoint3::ZERO.
// @fnv 0x004964d0
void FUN_004964d0_shell::FUN_004964d0()
{
    this->m_kRootTranslation = NiPoint3::ZERO;
}

struct FUN_00496550_shell : public Animation
{
    float GetMinBlendValue(NiNode*);
};

struct Calendar
{
};

// @fnv 0x00496550
float FUN_00496550_shell::GetMinBlendValue(NiNode* apNode)
{
    float fMinBlend = 1.0f;
    if (apNode != 0)
    {
        float fblendValue = ::GetFloatProperty((std::intptr_t)(apNode), (const char *)(0));
        if (fblendValue < fMinBlend)
            fMinBlend = fblendValue;
        if (apNode != m_pObjectNode)
        {
            fblendValue = GetMinBlendValue((NiNode*)((std::uintptr_t)(reinterpret_cast<::FUN_009611e0_shell *>((((Calendar*)apNode)))->FUN_009611e0())));
            if (fblendValue < fMinBlend)
                fMinBlend = fblendValue;
        }
    }
    return fMinBlend;
}

// Sets the object's vtable to vftable_NiRefObject and calls FinishScriptRunLock on DAT_011f4400.
// @fnv 0x00496910
void FUN_00496910(int** apObject)
{
    *apObject = &::DAT_0101dce4;
    ::WaitForSingleObjectEx((long *)(void *)((void*)&(*reinterpret_cast<volatile long *>(&::NiRefObject::ms_lObjectCount))));
}

namespace fnv_00496940 {
struct FUN_00496940_shell : public Animation
{
    NiControllerManager* FUN_00496940();
};

template <typename T> class BSStringT
{
  public:
    operator const char*() const;
};

// @fnv 0x00496940
NiControllerManager* FUN_00496940_shell::FUN_00496940()
{
    return (NiControllerManager*)(const char*)*(BSStringT<char>*)((char*)this + 0xd8);
}
}  // namespace fnv_00496940

void FUN_004969b0(void*);

struct FUN_00496980_caller
{
    void* FUN_00496980(unsigned int flags);
};

// Calls FUN_004969b0 on this, then frees this with NiMemObject::operator delete when flags has bit 1 set, and returns this.
// @fnv 0x00496980
void* FUN_00496980_caller::FUN_00496980(unsigned int flags)
{
    FUN_004969b0(this);
    if (flags & 1)
    {
        reinterpret_cast<void(__cdecl*)(void*, unsigned int)>(&((void (&)(void *, unsigned int) noexcept)::FUN_00aa1460))(this, 0x38);
    }
    return this;
}

namespace fnv_00496fe0 {
template <class T> struct BSStringT
{
    operator const char*() const;
};
struct FUN_00496fe0_tgt
{
};
struct FUN_00496fe0_cls
{
    char pad0[8];
    int state;
    int kind;
    char pad1[8];
    NiPointer<NiNode> node;
    char pad2[0x34 - 0x1c];
    FUN_00496fe0_tgt* tgt;
    bool FUN_00496fe0(NiNode* n);
};
// @fnv 0x00496fe0
bool FUN_00496fe0_cls::FUN_00496fe0(NiNode* apNode)
{
    if (state != 1)
        return false;
    node = apNode;
    state = 2;
    if (kind == 3)
        reinterpret_cast<::fnv_008a73e0::FUN_008a73e0_shell *>((tgt))->FUN_008a73e0(0xd, (::fnv_008a73e0::BSAnimGroupSequence *)(((BSStringT<char>*)&node)->operator const char*()));
    return true;
}
}  // namespace fnv_00496fe0

struct FUN_004974a0_shell : public Animation
{
    void FUN_004974a0();
};

// @fnv 0x004974a0
void FUN_004974a0_shell::FUN_004974a0()
{
    this->m_cSkipNextBlend = 1;
}

class ActiveEffect;
class Actor;
struct ActorMover;
class ActorValueOwner;
struct AlchemyItem;
class BGSImpactDataSet;
struct BGSLoadFormBuffer;
class BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimNote;
class BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
class DialogueResponse;
struct DetectionParameters;
class EffectItem;
class ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanFloatQuery;
struct IDebugText;
class InventoryStackRecord;
class MagicCaster;
class MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
class MagicTarget;
class MobileObject;
class NiAVObject;
struct NiColor;
struct NiFormArray;
struct LocationDescriptor;
class PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
class Projectile;
class QueuedFile;
struct SpellItem;
class TESActorBase;
struct TESClass;
struct TESCombatStyle;
class PerkEntryConditionSet;
struct TESFaction;
class TESFile;
class TESForm;
class TESIdleForm;
class TESModel;
class TESModelTextureSwap;
class TESObject;
class TESObjectBOOK;
class TESObjectCELL;
class TESObjectWEAP;
class TESPackage;
struct TESRace;
struct TESSkill;
struct FileEntryList;
class TESTopic;
class TESTopicInfo;
class TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
class bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00497f20_shell : public Animation
{
    void FUN_00497f20(TESIdleForm*, Actor*, int, int);
};

struct BSFadeNode
{
};

struct TES
{
};

void FUN_004965d0(void* pThis, int, TESIdleForm*, int, int, Actor*, int, Animation*);

struct AnimIdleStub : public BSFadeNode
{
    char pad[0x38];
    AnimIdleStub(TESIdleForm* a1, int a2, int a3, Actor* a4, int a5, Animation* a6);
};

struct VTable0x390
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
    virtual void v390(TESIdleForm*);
};

namespace fnv_00498170 {
struct FUN_00498170_shell : public Animation
{
    bool FUN_00498170();
};

template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

class bhkWorldObject;
struct bhkCollisionObject
{
  public:
};

struct TESObjectREFR_GetFlags_Helper
{
};

// @fnv 0x00498170
bool FUN_00498170_shell::FUN_00498170()
{
    if (reinterpret_cast<BSStringT<char>*>(&LocalStateValue)->operator const char*() &&
        ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<TESObjectREFR_GetFlags_Helper*>(
            const_cast<char*>(reinterpret_cast<BSStringT<char>*>(&LocalStateValue)->operator const char*()))))->GetName())) == 1 &&
        AddAnimation(
            reinterpret_cast<KFModel*>(
                ((::fnv_00498170::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(reinterpret_cast<bhkCollisionObject*>(
                    const_cast<char*>(reinterpret_cast<BSStringT<char>*>(&LocalStateValue)->operator const char*()))))))),
            false))
    {
        reinterpret_cast<NiPointer<NiNode>*>(&LocalStateValue)->operator=(0);
        return true;
    }
    return false;
}
}  // namespace fnv_00498170

struct FUN_00498910_shell : public Animation
{
    void FUN_00498910(bool, bool);
};

namespace fnv_00498cf0 {
struct FUN_00498cf0_shell : public Animation
{
    BSAnimGroupSequence* FUN_00498cf0();
};

template <class T> class BSStringT
{
  public:
    operator const T*() const;
};

// @fnv 0x00498cf0
BSAnimGroupSequence* FUN_00498cf0_shell::FUN_00498cf0()
{
    if (!*(BSStringT<char>*)((char*)this + 0x124))
        return 0;
    return reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)(const char*)*(BSStringT<char>*)((char*)this + 0x124))))->FUN_00490e40();
}
}  // namespace fnv_00498cf0

struct FUN_00498ea0_wrap
{
    bool impl(BSAnimGroupSequence* pSequence);
};

// Checks the four AnimIdle pointers at offsets 0x124-0x130 and returns true if any of their sequences equals pSequence.
// @fnv 0x00498ea0
bool FUN_00498ea0_wrap::impl(BSAnimGroupSequence* pSequence)
{
    if (*(NiPointer<AnimIdle>*)((char*)this + 0x124) != 0)
    {
        if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)*(NiPointer<AnimIdle>*)((char*)this + 0x124))))->FUN_00490e40() == pSequence)
            return true;
    }
    if (*(NiPointer<AnimIdle>*)((char*)this + 0x128) != 0)
    {
        if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)*(NiPointer<AnimIdle>*)((char*)this + 0x128))))->FUN_00490e40() == pSequence)
            return true;
    }
    if (*(NiPointer<AnimIdle>*)((char*)this + 0x12c) != 0)
    {
        if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)*(NiPointer<AnimIdle>*)((char*)this + 0x12c))))->FUN_00490e40() == pSequence)
            return true;
    }
    if (*(NiPointer<AnimIdle>*)((char*)this + 0x130) != 0)
    {
        if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)*(NiPointer<AnimIdle>*)((char*)this + 0x130))))->FUN_00490e40() == pSequence)
            return true;
    }
    return false;
}

namespace fnv_00498f80 {
template <class T> struct BSStringT
{
    int x;
    operator const char*() const;
};
struct FUN_00498f80_flags
{
};
struct FUN_00498f80_cls
{
    char pad[0x124];
    BSStringT<char> a;
    BSStringT<char> b;
    bool FUN_00498f80();
};
// @fnv 0x00498f80
bool FUN_00498f80_cls::FUN_00498f80()
{
    if (a.operator const char*())
    {
        if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)a.operator const char*())))->FUN_00490e40() == 0)
        {
            if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((FUN_00498f80_flags*)a.operator const char*())))->GetName())) == 3)
                return false;
            return true;
        }
        else
        {
            switch (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)a.operator const char*())))->FUN_00490e40()))->GetActiveCombatTarget())))
            {
            case 2:
            case 5:
                return true;
            }
        }
    }
    if (b.operator const char*())
    {
        if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)b.operator const char*())))->FUN_00490e40() == 0)
        {
            return true;
        }
        else
        {
            switch (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)b.operator const char*())))->FUN_00490e40()))->GetActiveCombatTarget())))
            {
            case 2:
            case 5:
                return true;
            }
        }
    }
    return false;
}
}  // namespace fnv_00498f80

struct FUN_0049bb20_cls : public NiMemObject
{
    void* FUN_0049bb20(unsigned int f);
};
// Calls FUN_004eeb00, then if bit 0 of f is set frees this with operator delete and returns this.
// @fnv 0x0049bb20
void* FUN_0049bb20_cls::FUN_0049bb20(unsigned int auiFlags)
{
    reinterpret_cast<::FUN_004eeb00 *>(this)->FUN_004eeb00::~FUN_004eeb00();
    if (auiFlags & 1)
        ((void(__cdecl*)(void*, int)) & ((void (&)(void *, unsigned int) noexcept)::FUN_00aa1460))(this, 0x78);
    return this;
}

struct FUN_00508100_shell : public NiControllerSequence
{
    float FUN_00508100();
};

// @fnv 0x00508100
float FUN_00508100_shell::FUN_00508100()
{
    return *(float*)((char*)this + 0x30);
}

struct _Stub_FUN_00508d90
{
    char pad[8];
    unsigned char m_ucSectionPriorities[8];
    unsigned char method(int aeSection);
};

// @fnv 0x00508d90
unsigned char _Stub_FUN_00508d90::method(int aeSection)
{
    return m_ucSectionPriorities[aeSection];
}

struct FUN_00639aa0_shell : public NiControllerSequence
{
    float FUN_00639aa0();
};
// @fnv 0x00493770
float FUN_00493770_shell::FUN_00493770()
{
    return reinterpret_cast<::FUN_00639aa0_shell *>((((BGSCameraShot*)this)))->FUN_00639aa0() - reinterpret_cast<::FUN_00759450_shell *>((((NiControllerSequence_helper*)this)))->FUN_00759450();
}

// @fnv 0x00639aa0
float FUN_00639aa0_shell::FUN_00639aa0()
{
    return *(float*)((char*)this + 0x48);
}

struct FUN_006d2c40_dummy
{
    float m_func();
};

// @fnv 0x006d2c40
float GetFieldB4Float(char* pObject)
{
    return *(float*)(pObject + 0xb4);
}

namespace fnv_00825c00 {
class ActiveEffect;
class Actor;
class BSExtraData;
class EffectItem;
class MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
class MagicTarget;
struct SpellItem;
class TESObjectCELL;
struct hkpRigidBody;
struct blob12
{
    char b[12];
};
struct GameTimerRecord
{
    void Update();
    void Update(unsigned int);
    float GetSeconds();
    float GetUnmodifiedSeconds();
    unsigned int GetTime();
    unsigned int GetStartTime();
    void ClampAt(unsigned int);
    bool QEnabled();
    bool GetSecondsIsZero();
    void SetGlobalTimeMultiplier(float, bool);
    static void SetGlobalTimeMultiplierCache();
    void RestoreGlobalTimeMultiplierCache();
    static float QGlobalTimeMultiplier();
    static float QGlobalTimeMultiplierTarget();
    static void UpdateGlobalTimeMultiplier();
    void SetUseGlobalTimeMultiplierTarget(bool);
    bool QUseGlobalTimeMultiplierTarget();
    float GetRealTimeSeconds();
    void Enable();
    void Disable();
    void Init(unsigned int);
    unsigned char m_ucFirstTimerByte;
    char _pad_1[3];
    float m_fFirstTimerValue;
    float m_fSecondTimerValue;
    float fTimeSinceScaleStart;
    float m_fFourthTimerValue;
    unsigned int m_uiFirstTimerValue;
    unsigned int m_uiSecondTimerValue;
    bool m_bFirstTimerFlag;
    bool m_bSecondTimerFlag;
    char _pad_1e[2];
};
class MagicCaster
{
  public:
    virtual void CastSpellOnCaster(SpellItem*, bool);
    virtual void CastSpellOnSelf(SpellItem*, bool);
    virtual void CastSpellAtLocation(SpellItem*, bool);
    virtual void CastMagicItem(MagicItem*, bool, MagicTarget*, float, bool);
    virtual void CastSpellAtTarget(SpellItem*, MagicTarget*, bool);
    virtual void CastMagicItemOnObject(MagicItem*, TESBoundObject*, bool);
    virtual MagicTarget* GetSpellTarget();
    virtual void UpdateCastState();
    virtual void CompleteCast();
    virtual void SpellCast(MagicItem*, bool);
    virtual bool CanCast(MagicItem*, float*, int*, bool);
    virtual TESObjectREFR* GetCasterReference();
    virtual NiNode* GetMagicNode();
    virtual MagicItem* GetSelectedMagicItem();
    virtual bool HasActiveEffect(ActiveEffect*);
    virtual float GetCasterEffectiveness(bool, float);
    virtual void SetSelectedMagicItem(MagicItem*);
    virtual MagicTarget* GetCurrentMagicTarget();
    virtual void SetMagicTarget(MagicTarget*);
    virtual ActiveEffect* CreateActiveEffect(MagicItem*, EffectItem*, TESBoundObject*);
    void UpdateCaster(float);
    bool CastSpell(MagicItem*, MagicTarget*, bool);
    void EndAim();
    bool CanCastSpellOnObject(TESBoundObject*);
    void RemoveCastingArt();
    void LaunchMagicProjectile(MagicItem*, TESObjectCELL*, struct blob12, MagicProjectile*, TESObjectREFR*, bool, float,
                               float);
    void LaunchMagicProjectile(MagicItem*, MagicProjectile*, TESObjectREFR*, bool, float, float);
    void LaunchMagicProjectile(float, TESBoundObject*, bool, float, bool);
    void CreateSpellImpactEffect(struct blob12, TESObjectCELL*, MagicItem*, EffectItem*, void*, float, float);
    void ApplyMagicEffectToActor(Actor*, struct blob12, EffectItem*, float);
    void ExplodeRigidBody(hkpRigidBody*, struct blob12, EffectItem*, float);
    bool CanCastOnTarget(MagicTarget*, MagicItem*);
    Actor* GetCasterActor();
    int GetState();
    void SetMagicLight(MagicEffectCollection*);
    MagicEffectCollection* GetMagicLight();
    void UpdateMagicCaster(float);
    unsigned int GetCasterHandle();
    static MagicCaster* GetCasterByHandle(unsigned int);
    void FireRefData();
    void ApplyMagicEffect(MagicItem*, ActiveEffect*, TESObjectCELL*, struct blob12, MagicTarget*, MagicProjectile*,
                          void*, bool*, float);
    bool RunExplosionLOSPick(struct blob12, Actor*);
    void CreateMagicProjectile(MagicItem*, int, struct blob12, void*);
    bool AddEffectToTarget(MagicTarget*, struct blob12, MagicItem*, ActiveEffect*, bool);
    void SetState(int, char*);
    void* __vecDelDtor(unsigned int);
    MagicEffectCollection* apTargetLight;
    int eState;
};
struct FUN_00825c00_shell : public GameTimerRecord
{
    std::uintptr_t FUN_00825c00();
};

// @fnv 0x00825c00
std::uintptr_t FUN_00825c00_shell::FUN_00825c00()
{
    return m_uiFirstTimerValue;
}
}  // namespace fnv_00825c00

namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0048efc0(unsigned int flags);
};
// @fnv 0x0048efc0
void* DelStandIn::FUN_0048efc0(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct NiFixedStr
{
    operator const char*() const;
};
struct SeqObj
{
    NiFixedStr& GetName();
};
struct ModelLoaderStub
{
    void NewItem(void*);
};
struct FUN_0048ef40
{
    virtual ~FUN_0048ef40();
};
struct FUN_0048ee70 : public FUN_0048ef40
{
    SeqObj* pForwardSequence;
    ~FUN_0048ee70();
};
// @fnv 0x0048ee70
FUN_0048ee70::~FUN_0048ee70()
{
    char seqFilename[260];
    if (pForwardSequence)
    {
        ::TaskQueueInterface::CopyStringToBuffer(seqFilename, 260, (*(::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((pForwardSequence))->GetLinkToList())));
        reinterpret_cast<::WaitableObject *>((pForwardSequence))->FUN_00401970();
        ((ModelLoaderStub*)g_modelLoader)->NewItem(seqFilename);
    }
}

namespace fnv_0048f450 {
struct TESAnimGroup;
struct AnimSequenceMultiple : public AnimSequenceBase
{
    virtual void __vslot_0();
    virtual bool IsSingleSeq();
    virtual void AssignSequence(BSAnimGroupSequence*, bool);
    virtual bool SetSequenceActive(BSAnimGroupSequence*, bool);
    virtual BSAnimGroupSequence* GetSequenceAtIndex(char);
    virtual BSAnimGroupSequence* GetControllerSequence(TESAnimGroup*);
    BSAnimGroupSequence* FindSequence(BSAnimGroupSequence*, int);
    virtual char ContainsSequence(BSAnimGroupSequence*);
    void* m_pSingleSequence;
};
struct FUN_0048f450_shell : public AnimSequenceMultiple
{
    BSAnimGroupSequence* GetSequenceByIndex(char);
};

struct ArrSI
{
};
struct Flt
{
    operator std::uintptr_t() const;
};
struct FUN_006317a0_struct
{
};
struct NiTPointerList_TESObjectREFR
{
};
struct SeqListT : public ArrSI, public Flt, public FUN_006317a0_struct, public NiTPointerList_TESObjectREFR
{
};
// Returns the BSAnimGroupSequence at aiSequenceIndex, or a random one when the index is -1 or out of range, by walking the list.
// @fnv 0x0048f450
BSAnimGroupSequence* FUN_0048f450_shell::GetSequenceByIndex(char aiSequenceIndex)
{
    BSAnimGroupSequence* pForwardSequence;
    void* listIt;
    int iTargetIndex;
    if (aiSequenceIndex != -1 && (unsigned int)aiSequenceIndex < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)m_pSingleSequence)))->GetName())))
        iTargetIndex = aiSequenceIndex;
    else
        iTargetIndex = ::DialogueRandom() % ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)m_pSingleSequence)))->GetName()));
    listIt = *(void**)(m_pSingleSequence);
    while (listIt)
    {
        pForwardSequence = *(BSAnimGroupSequence**)((int *)(reinterpret_cast<::FUN_006317a0_struct *>((((FUN_006317a0_struct*)m_pSingleSequence)))->AddEight((std::intptr_t)listIt)));
        if (iTargetIndex-- == 0)
            return pForwardSequence;
        listIt = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((void *)(((NiTPointerList_TESObjectREFR*)m_pSingleSequence)))->DereferenceIfNotNull((int **)(listIt))));
    }
    return 0;
}
}  // namespace fnv_0048f450

namespace fnv_00493d50 {
struct TESAnimGroup;
struct FUN_00493d50_shell : public Animation
{
    void CheckAnimGroupMovement(TESAnimGroup*);
};

struct AnimSequenceBase_Helper
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual class AnimIdle* vfn_04(int);
};

struct NiInterpolator
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual bool vfn_35(float, void*, void*);
};

struct Flt
{
    int m;
    operator std::uintptr_t() const;
};

struct SoundH
{
};

struct FUN_00759450_shell
{
};

struct FUN_00508100_shell
{
};

class TESChallenge
{
  public:
};

class NiAVObject
{
  public:
    NiFixedString& GetName();
};

struct FUN_00490d90_shell
{
};

struct AnimIdle_Helper : public SoundH, public FUN_00759450_shell
{
};

struct Animation_Layout
{
    char pad_00[0x08];
    Flt m_acHeaderData;  // +0x08
    char pad_0c[0xcc];
    Flt m_acReservedBytes;                                                       // +0xd8
    NiTPointerMap<unsigned short, AnimSequenceBase*>* m_pOwnerReference;  // +0xdc
};

struct FUN_0047d3b0_shell
{
};

enum ANIM_GROUP_ENUM
{
};

struct TESAnimGroup
{
    unsigned int GetType();
    static ANIM_GROUP_ENUM __cdecl GetType(unsigned short);
    int GetMoveAnimGroup();
};

struct FUN_005f4c40_shell
{
};

struct NiFixedString_access
{
    operator const char*() const;
};

struct NiPoint3_sub : public NiPoint3
{
    NiPoint3 operator-(const NiPoint3&) const;
};

class NiQuatTransform
{
  public:
    float m[8];
    NiQuatTransform();
};

struct FUN_004941c0_shell
{
};

struct AnimGroupInfo
{
    const char* name;
    unsigned char bNoMove;
    int pad_08;
    unsigned int moveType;
    int pad_10[5];
};


// @fnv 0x00493d50
void FUN_00493d50_shell::CheckAnimGroupMovement(TESAnimGroup* apAnimGroup)
{
    unsigned short sanimGroup = reinterpret_cast<::FUN_0047d3b0_shell *>((((FUN_0047d3b0_shell*)apAnimGroup)))->FUN_0047d3b0();
    unsigned int eanimGroup = apAnimGroup->GetType();
    AnimSequenceBase* panimSeq;
    if (!((Animation_Layout*)this)->m_acReservedBytes ||
        !reinterpret_cast<::NiTMapBase *>((void *)(((Animation_Layout*)this)->m_pOwnerReference))->Lookup(sanimGroup, panimSeq))
        return;
    if (eanimGroup == 1 || eanimGroup == 2)
        return;
    NiAVObject* pbip01 = ((::fnv_00493d50::NiAVObject *)(reinterpret_cast<::fnv_00490d90::FUN_00490d90_shell *>((((FUN_00490d90_shell*)(std::uintptr_t)((Animation_Layout*)this)->m_acReservedBytes)))->FUN_00490d90()));
    if (!pbip01)
    {
        Warning("ANIMATION: Could not find AccumRoot in animation '%s'.",
                (const char*)((
                    const NiFixedString_access&)((*(::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((((NiAVObject*)(std::uintptr_t)((Animation_Layout*)this)->m_acHeaderData)))->GetLinkToList())))));
        return;
    }
    bool bcheckForMovement = false;
    int estart = 0;
    int estop = 1;
    if (((AnimSequenceBase_Helper*)panimSeq)->vfn_04(-1) && !(*reinterpret_cast<fnv_00493d50::AnimGroupInfo (*)[]>(&::DAT_011977d8))[eanimGroup].bNoMove)
    {
        switch ((*reinterpret_cast<fnv_00493d50::AnimGroupInfo (*)[]>(&::DAT_011977d8))[eanimGroup].moveType)
        {
        case 0:
        case 1:
            estart = 0;
            estop = 1;
            bcheckForMovement = true;
            break;
        case 2:
            estart = 0;
            estop = 3;
            bcheckForMovement = true;
            break;
        case 5:
            estart = 0;
            estop = 4;
            bcheckForMovement = true;
            break;
        case 6:
            estart = 0;
            estop = 2;
            bcheckForMovement = true;
            break;
        case 7:
            estart = 0;
            estop = 4;
            bcheckForMovement = true;
            break;
        case 8:
            estart = 0;
            estop = 3;
            bcheckForMovement = true;
            break;
        case 9:
            estart = 0;
            estop = 3;
            bcheckForMovement = true;
            break;
        }
    }
    if (bcheckForMovement)
    {
        NiPointer<AnimIdle> spseq(((AnimSequenceBase_Helper*)panimSeq)->vfn_04(-1));
        NiPoint3 interpDelta = NiPoint3::ZERO;
        for (unsigned int n = 0; n < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*(AnimIdle_Helper**)(&spseq))))->FUN_0084e3a0())); ++n)
        {
            if (((int)(reinterpret_cast<::fnv_00494210::FUN_00494210_cls *>(((*(AnimIdle_Helper**)(&spseq))))->GetItemIconFormID(n))) ==
                ((int)(std::uintptr_t)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>(((*(TESChallenge**)(&spseq))))->FUN_005f5f80())))
            {
                NiInterpolator* pinterp = ((::fnv_00493d50::NiInterpolator *)(reinterpret_cast<::fnv_004937a0::FUN_004937a0_shell *>(((*(AnimIdle_Helper**)(&spseq))))->FUN_004937a0(n)));
                float fstartTime = reinterpret_cast<::FUN_00759450_shell *>(((*(FUN_00759450_shell**)(&spseq))))->FUN_00759450();
                float fstopTime = reinterpret_cast<::FUN_00508100_shell *>(((*(FUN_00508100_shell**)(&spseq))))->FUN_00508100();
                NiQuatTransform quatStart;
                NiQuatTransform quatStop;
                pinterp->vfn_35(fstartTime, 0, &quatStart);
                pinterp->vfn_35(fstopTime, 0, &quatStop);
                if (reinterpret_cast<::FUN_004942c0_shell *>(&(quatStart))->IsTranslateXNotNegatedConstant() && reinterpret_cast<::FUN_004942c0_shell *>(&(quatStop))->IsTranslateXNotNegatedConstant())
                {
                    NiPoint3 delta = (*(const ::fnv_00493d50::NiPoint3_sub *)((void *)&(quatStop))) - (*(const ::fnv_00493d50::NiPoint3_sub *)((void *)&(quatStart)));
                    reinterpret_cast<::FUN_004941c0_shell *>((((FUN_004941c0_shell*)&delta)))->ScaleByInverse(fstopTime - fstartTime);
                    reinterpret_cast<::FUN_005f4c40_shell *>((((FUN_005f4c40_shell*)apAnimGroup)))->SetSpeed(&delta);
                }
                break;
            }
        }
    }
    switch (TESAnimGroup::GetType(sanimGroup))
    {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        if (reinterpret_cast<::TESAnimGroup *>((void *)(apAnimGroup))->GetAnimationSpeed() == ::_DAT_01012060)
        {
            Warning("ANIMATION: AnimGroup '%s%s%s' for '%s' was exported with 'Animate in Place' from MAX.\r\n",
                    ::DAT_01197794[apAnimGroup->GetMoveAnimGroup()], ::DAT_011977a4[((int)(reinterpret_cast<::FUN_005f23e0_shell *>((apAnimGroup))->FUN_005f23e0()))],
                    (*reinterpret_cast<fnv_00493d50::AnimGroupInfo (*)[]>(&::DAT_011977d8))[apAnimGroup->GetType()].name,
                    (const char*)((
                        const NiFixedString_access&)((*(::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((((NiAVObject*)(std::uintptr_t)((Animation_Layout*)this)->m_acHeaderData)))->GetLinkToList())))));
        }
        break;
    }
}
}  // namespace fnv_00493d50

int __cdecl GetType(unsigned short);
struct AnimGroupInfo
{
    int iType;
    int rest[8];
};
struct SeqIface
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual bool IsSingleSeq();
    virtual SeqIface* GetSequenceAtIndex(int);
};
struct FUN_004948c0_shell : public Animation
{
    SeqIface* GetSequenceForGroup(unsigned short, int);
    SeqIface* FUN_004949a0(SeqIface*, unsigned short, int);
};
namespace fnv_00495740 {
struct FUN_00495740_shell : public Animation
{
    unsigned short ResolveAnimGroup(unsigned short, bool);
};

enum ANIM_GROUP_ENUM
{
    ANIM_GROUP_ENUM_NONE = 0
};
class TESAnimGroup
{
  public:
    static ANIM_GROUP_ENUM __cdecl GetType(unsigned short);
};
class PlayerCharacter : public TESObjectREFR
{
  public:
    Animation* GetAnimation(bool) const;
};
struct AnimGroupInfo
{
    const char* name;
    bool supportsVariants;
    int sequenceType;
    int keyType;
    int unk10;
    int unk14[4];
};

// Resolves an animation group to an available sequence group, recursing through variant and iron-sights fallbacks and returning 0 when none is found.
// @fnv 0x00495740
unsigned short FUN_00495740_shell::ResolveAnimGroup(unsigned short asAnimGroup, bool abRecursive)
{
    AnimSequenceBase* panimSeq;
    unsigned short sreturnGroup;
    unsigned short stestGroup;

    if (reinterpret_cast<::NiTMapBase *>((void *)(((Animation*)this)->m_pOwnerReference))->Lookup(asAnimGroup, panimSeq) && panimSeq->GetSequenceAtIndex(-1))
        return asAnimGroup;

    if (asAnimGroup & 0x8000)
    {
        sreturnGroup = ResolveAnimGroup(asAnimGroup & 0x7fff, true);
        if ((sreturnGroup & 0xff) == (asAnimGroup & 0xff) ||
            (::IsIronSightsAnimGroup(asAnimGroup) && (sreturnGroup & 0xff) == ((asAnimGroup - 3) & 0xff)))
            return sreturnGroup;
    }

    if (((Animation*)this)->m_pAttachedReference == (*reinterpret_cast<::fnv_00495740::PlayerCharacter * *>(&::_g_thePlayer)) && (Animation*)this == reinterpret_cast<::PlayerCharacter *>((void *)((*reinterpret_cast<::fnv_00495740::PlayerCharacter * *>(&::_g_thePlayer))))->GetAnimation(true) &&
        (asAnimGroup & 0x7000))
    {
        switch ((*reinterpret_cast<fnv_00495740::AnimGroupInfo (*)[]>(&::DAT_011977d8))[asAnimGroup & 0xff].sequenceType)
        {
        case 4:
        case 5:
        case 6:
            sreturnGroup = ResolveAnimGroup(asAnimGroup & 0xfff, true);
            if ((sreturnGroup & 0xff) == (asAnimGroup & 0xff) ||
                (::IsIronSightsAnimGroup(asAnimGroup) && (sreturnGroup & 0xff) == ((asAnimGroup - 3) & 0xff)))
                return sreturnGroup;
        }
    }

    if (::IsIronSightsAnimGroup(asAnimGroup))
        return ResolveAnimGroup(asAnimGroup - 3, true);

    switch ((*reinterpret_cast<fnv_00495740::AnimGroupInfo (*)[]>(&::DAT_011977d8))[TESAnimGroup::GetType(asAnimGroup)].sequenceType)
    {
    case 5:
    case 6:
        return 0;
    }

    if (asAnimGroup & 0xf00)
    {
        switch (::fnv_005f2400::FUN_005f2400(asAnimGroup))
        {
        case 3:
            if (reinterpret_cast<::NiTMapBase *>((void *)(((Animation*)this)->m_pOwnerReference))->Lookup(asAnimGroup & 0xf0ff | 0x200, panimSeq) &&
                panimSeq->GetSequenceAtIndex(-1))
                return asAnimGroup & 0xf0ff | 0x200;
            break;
        case 2:
        case 4:
            break;
        default:
            if (reinterpret_cast<::NiTMapBase *>((void *)(((Animation*)this)->m_pOwnerReference))->Lookup(asAnimGroup & 0xf0ff | 0x400, panimSeq) &&
                panimSeq->GetSequenceAtIndex(-1))
                return asAnimGroup & 0xf0ff | 0x400;
        }
        if (reinterpret_cast<::NiTMapBase *>((void *)(((Animation*)this)->m_pOwnerReference))->Lookup(asAnimGroup & 0xf0ff, panimSeq) &&
            panimSeq->GetSequenceAtIndex(-1))
            return asAnimGroup & 0xf0ff;
    }

    if (asAnimGroup & 0x8000)
    {
        sreturnGroup = ResolveAnimGroup(asAnimGroup & 0x7fff, true);
        if ((sreturnGroup & 0xff) == (asAnimGroup & 0xff))
            return sreturnGroup;
    }

    if (asAnimGroup && 0x7f00)
    {
        stestGroup = 0xff;
        switch (TESAnimGroup::GetType(asAnimGroup))
        {
        case 7:
            stestGroup = asAnimGroup & 0x7f00 | 3;
            break;
        case 8:
            stestGroup = asAnimGroup & 0x7f00 | 4;
            break;
        case 9:
            stestGroup = asAnimGroup & 0x7f00 | 5;
            break;
        case 10:
            stestGroup = asAnimGroup & 0x7f00 | 6;
        }
        if (stestGroup != 0xff)
        {
            sreturnGroup = ResolveAnimGroup(stestGroup, true);
            if ((sreturnGroup & 0xff) == (stestGroup & 0xff))
                return sreturnGroup;
        }
    }

    if (abRecursive)
        return 0;

    if (asAnimGroup & 0x7000)
    {
        sreturnGroup = ResolveAnimGroup(asAnimGroup & 0xfff, true);
        if ((sreturnGroup & 0xff) == (asAnimGroup & 0xff))
            return sreturnGroup;
    }

    if (asAnimGroup & 0xff)
    {
        stestGroup = asAnimGroup & 0x7f00;
        return ResolveAnimGroup(stestGroup, false);
    }
    return 0;
}
}  // namespace fnv_00495740

namespace fnv_004969b0 {
struct EBase
{
    int pad;
    virtual ~EBase();
};
struct NP
{
    int p;
    ~NP();
};
struct KFModel;
struct KFP
{
    KFModel* p;
    ~KFP();
};
struct FUN_004969b0;
void __cdecl DetachObjectModels(FUN_004969b0*);
struct FUN_004969b0 : public EBase
{
    int eFlags;
    int eType;
    KFP m_kActorValueData;
    int m_iSectionIndex;
    NP pForwardSequence;
    int m_iSectionValues[2];
    NP m_kSectionEntries[2];
    ~FUN_004969b0();
};
// @fnv 0x004969b0
FUN_004969b0::~FUN_004969b0()
{
    DetachObjectModels(this);
}
}  // namespace fnv_004969b0

struct FUN_00497040_shell : public AnimIdle
{
    void FUN_00497040(Animation*);
};

struct Flt
{
    operator std::uintptr_t() const;
};
struct HA
{
    int GetAnimAction();
};
// @fnv 0x00497040
void FUN_00497040_shell::FUN_00497040(Animation* apAnimation)
{
    if (*(int*)((char*)this + 8) == 2)
    {
        if (!(unsigned int)*(Flt*)((char*)this + 0x18) ||
            ((unsigned int)*(Flt*)((char*)this + 0x18),
             ((std::intptr_t)(reinterpret_cast<::LowProcess *>(((*(NiControllerSequence**)((char*)this + 0x18))))->GetActiveCombatTarget()))) == 0)
        {
            *(int*)((char*)this + 8) = 3;
            if (*(HA**)((char*)this + 0x34) && reinterpret_cast<::FUN_008a7570_shell *>(((*(HA**)((char*)this + 0x34))))->FUN_008a7570() == 0xd)
                reinterpret_cast<::fnv_008a73e0::FUN_008a73e0_shell *>(((*(HA**)((char*)this + 0x34))))->FUN_008a73e0(-1, (::fnv_008a73e0::BSAnimGroupSequence *)(0));
            if (*(int*)((char*)this + 0xc) == 2 || *(int*)((char*)this + 0xc) == 3)
            {
                if (apAnimation)
                    apAnimation->SpecialIdleFree(true, false);
            }
        }
    }
}

namespace fnv_0049bca0 {
struct FUN_0049bca0_shell : public Animation
{
    void FUN_0049bca0(float, NiPoint3*, bool);
};

struct FUN_00440460_S
{
};
struct FUN_004efe80_S
{
};
struct Flt
{
};
class TESDataHandler
{
};
// @fnv 0x0049bca0
void FUN_0049bca0_shell::FUN_0049bca0(float afTime, NiPoint3* apTranslate, bool abControllers)
{
    if ((*(FUN_00440460_S**)&this->m_pObjectNode))
        reinterpret_cast<::FUN_00440460_S *>(((*(FUN_00440460_S**)&this->m_pObjectNode)))->FUN_00440460((const ::V3 *)(const ::NiPoint3 *)(&this->m_kRootTranslation));
    reinterpret_cast<::B4EFE80Object *>((((::fnv_0049bca0::FUN_004efe80_S *)(::FUN_00559450((int *)(((Flt*)((char*)this + 8))))))))->UpdateControllers({}, {});
    if ((*(FUN_00440460_S**)&this->m_pObjectNode))
    {
        if (apTranslate)
        {
            *apTranslate = *((::NiPoint3 *)&(reinterpret_cast<::NiAVObject *>((((TESDataHandler*)(*(FUN_00440460_S**)&this->m_pObjectNode))))->FUN_0043c490()));
        }
        reinterpret_cast<::FUN_00440460_S *>(((*(FUN_00440460_S**)&this->m_pObjectNode)))->FUN_00440460((const ::V3 *)(const ::NiPoint3 *)(&NiPoint3::ZERO));
    }
}
}  // namespace fnv_0049bca0

class AnimSequenceBase;
struct MapItem
{
    MapItem* m_pkNext;
    unsigned short m_key;
    AnimSequenceBase* m_val;
};
struct MapBase
{
    virtual ~MapBase();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeysEqual(unsigned short k1, unsigned short k2);
    virtual void SetValue(MapItem* pkItem, unsigned short key, AnimSequenceBase* val);
    virtual void ClearValue(MapItem* pkItem);
    virtual MapItem* NewItem();
    unsigned int m_uiHashSize;
    MapItem** m_ppkHashTable;
    unsigned int m_uiCount;
    void SetOrInsert(unsigned short key, AnimSequenceBase* val);
};

// Looks up the key in the hash bucket; updates the existing item's value, or allocates a new item, inserts it at the bucket head and increments the count.
// @fnv 0x0049c170
void MapBase::SetOrInsert(unsigned short key, AnimSequenceBase* val)
{
    unsigned int uiIndex = this->KeyToHashIndex(key);
    MapItem* pkItem = this->m_ppkHashTable[uiIndex];
    unsigned int uiDepth = 0;
    while (pkItem)
    {
        uiDepth++;
        if (this->IsKeysEqual(key, pkItem->m_key))
        {
            pkItem->m_val = val;
            return;
        }
        pkItem = pkItem->m_pkNext;
    }
    pkItem = this->NewItem();
    this->SetValue(pkItem, key, val);
    pkItem->m_pkNext = this->m_ppkHashTable[uiIndex];
    this->m_ppkHashTable[uiIndex] = pkItem;
    this->m_uiCount++;
}


// If the counter at p+0x10 is positive, calls FinishScriptRunLock on that field.
// @fnv 0x0043bac0
void FinishScriptRunLockIfActive(void* p)
{
    if (*(int*)((char*)p + 0x10) > 0)
        ::WaitForSingleObjectEx((long *)(void *)((char*)p + 0x10));
}

extern float DAT_0101d890;

// @fnv 0x004954c0
void SetNegatedGlobal(void* thisPtr)
{
    *(float*)((char*)thisPtr + 0x48) = -DAT_0101d890;
}

struct FUN_00497280_shell
{
    unsigned int fieldAt124;
    std::uintptr_t GetFieldAt124();
};

// @fnv 0x00497280
std::uintptr_t FUN_00497280_shell::GetFieldAt124()
{
    return *(std::uintptr_t*)((char*)this + 0xDC);
}

extern NiFixedString* DAT_011c61bc;

// @fnv 0x00499b70
NiFixedString* __cdecl FUN_00499b70()
{
    return DAT_011c61bc;
}

extern NiFixedString* DAT_011c61c0;

// @fnv 0x00499b80
NiFixedString* __cdecl FUN_00499b80()
{
    return DAT_011c61c0;
}

bool _ref_008256d0(void* pThis);

struct FUN_00726070_standin
{
};

// @fnv 0x0049bd30
int GetListCount(void* pThis)
{
    int count = 0;
    if (!_ref_008256d0((char*)pThis + 0x104))
    {
        FUN_00726070_standin* list = (FUN_00726070_standin*)((char*)pThis + 0x104);
        while (list)
        {
            ++count;
            list = ((::FUN_00726070_standin *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
        }
    }
    return count;
}

struct NiRTTI
{
    char* GetName();
    void* GetBaseRTTI();
    char* m_pcName;
    void* m_pBaseRTTI;
};

struct NiObject
{
    NiObject* DynamicCast(NiRTTI const*);
};

// @fnv 0x00653270
NiObject* __cdecl FUN_00653270(NiRTTI const* pkRTTI, NiObject* pkObject)
{
    if (!pkObject)
        return 0;
    return pkObject->DynamicCast(pkRTTI);
}

struct FileListNode
{
};
struct FUN_00490330_t : public Animation
{
    void FUN_00490330(BSSimpleList<const char*>* apFileList, const char* apPath);
};

namespace fnv_004955c0 {
struct FUN_00496080_t
{
};
struct FUN_00494710_shell
{
};
struct SeqIface;
struct FUN_004948c0_shell
{
    SeqIface* FUN_004949a0(SeqIface*, unsigned short, int);
};
struct NiControllerManagerStandIn
{
};
struct FUN_004955c0_t : public Animation
{
    void FUN_004955c0(int aeSequenceType, unsigned short ausGroup, int aeAction, float afTime, bool abFlag);
};

// @fnv 0x004955c0
void FUN_004955c0_t::FUN_004955c0(int aeSequenceType, unsigned short ausGroup, int aeAction, float afTime, bool abFlag)
{
    int iSlot = aeSequenceType;
    switch (iSlot)
    {
    case 0x14:
        iSlot = 1;
        break;
    case 0x15:
        iSlot = 4;
        break;
    }
    if (aeAction == -1)
    {
        reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>((((FUN_00496080_t*)this)))->FUN_00496080(aeSequenceType, 0.0f);
        if (ausGroup != 0xff)
        {
            AnimSequenceBase* pAnimSeqBase;
            if (reinterpret_cast<::NiTMapBase *>((void *)(m_pOwnerReference))->Lookup(ausGroup, pAnimSeqBase))
            {
                if (pAnimSeqBase->GetSequenceAtIndex(abFlag))
                {
                    m_pChildTile[iSlot] = pAnimSeqBase->GetSequenceAtIndex(abFlag);
                    reinterpret_cast<::NiControllerManager *>((((NiControllerManagerStandIn*)(NiControllerManager*)m_acReservedBytes)))->ActivateControllerSequence(m_pChildTile[iSlot], 0, false, 1.0f, 0.0f, 0);
                }
            }
        }
    }
    else
    {
        if (reinterpret_cast<::FUN_00494710_shell *>((((FUN_00494710_shell*)this)))->FUN_00494710(ausGroup))
        {
            AnimSequenceBase* pBase;
            if (reinterpret_cast<::NiTMapBase *>((void *)(m_pOwnerReference))->Lookup(ausGroup, pBase))
            {
                BSAnimGroupSequence* pSequence = pBase->GetSequenceAtIndex(abFlag);
                ((FUN_004948c0_shell*)this)->FUN_004949a0((SeqIface*)pSequence, ausGroup, aeSequenceType);
            }
            action[iSlot] = (ANIM_GROUP_ACTION)aeAction;
        }
    }
    group[iSlot] = ausGroup;
    time = afTime;
}
}  // namespace fnv_004955c0

class Script
{
};
struct ArrSI
{
};
struct FUN_00498d30_t : public Animation
{
    bool HasIdleForm(TESIdleForm* apIdleForm);
};

// @fnv 0x00498d30
bool FUN_00498d30_t::HasIdleForm(TESIdleForm* apIdleForm)
{
    if (LocalInput && ((::TESIdleForm *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((((Script*)(AnimIdle*)LocalInput)))->GetIconFormID())) == apIdleForm &&
        ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)(AnimIdle*)LocalInput)))->GetName())) != 1)
        return true;
    if (LocalStateValue && ((::TESIdleForm *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((((Script*)(AnimIdle*)LocalStateValue)))->GetIconFormID())) == apIdleForm &&
        ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)(AnimIdle*)LocalStateValue)))->GetName())) != 1)
        return true;
    if (LocalOutput[0])
    {
        if (((::TESIdleForm *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((((Script*)(AnimIdle*)LocalOutput[0])))->GetIconFormID())) == apIdleForm)
            return true;
        else if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::ArrSI *>(&::g_011f2250))))->GetName())) == 4 && reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)LocalOutput[0])))->FUN_00490e40())
            return true;
    }
    if (LocalOutput[1])
    {
        if (((::TESIdleForm *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((((Script*)(AnimIdle*)LocalOutput[1])))->GetIconFormID())) == apIdleForm)
            return true;
        else if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::ArrSI *>(&::g_011f2250))))->GetName())) == 4 && reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)LocalOutput[1])))->FUN_00490e40())
            return true;
    }
    return false;
}

struct Setting_S
{
};
struct hkpCharacterContext
{
};
struct CameraShotHelper
{
};
struct FUN_009c8d60_t
{
    float FUN_009c8d60();
};

// @fnv 0x009c8d60
float FUN_009c8d60_t::FUN_009c8d60()
{
    float fMultiplier = 1.0f;
    if (*(int*)((char*)this + 8) == 4)
    {
        if (*(CameraShotHelper**)((char*)this + 0x10) && !reinterpret_cast<::FUN_0058d630_shell *>(((*(CameraShotHelper**)((char*)this + 0x10))))->FUN_0058d630())
            fMultiplier = 1.0f;
        else if (*(CameraShotHelper**)((char*)this + 0x10) &&
                 reinterpret_cast<::FUN_00507b00Class *>(((*(CameraShotHelper**)((char*)this + 0x10))))->GetField4C() > 0.0)
            fMultiplier = reinterpret_cast<::FUN_00507b00Class *>(((*(CameraShotHelper**)((char*)this + 0x10))))->GetField4C();
        else
            fMultiplier = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::g_011cfcec))))));
    }
    fMultiplier = FUN_009443f0() / ::FUN_00716440() * fMultiplier;
    return fMultiplier;
}

struct FUN_0048ef90_shell
{
    unsigned int FUN_0048ef90(unsigned int dummy);
};

// @fnv 0x0048ef90
unsigned int FUN_0048ef90_shell::FUN_0048ef90(unsigned int dummy)
{
    return *(unsigned int*)((char*)this + 4);
}

struct FUN_0048efb0_shell
{
    char FUN_0048efb0(int arg1);
};

// @fnv 0x0048efb0
char FUN_0048efb0_shell::FUN_0048efb0(int arg1)
{
    return -1;
}

struct FUN_00493880_shell
{
    unsigned char m_flags;
    void SetFlag(bool set, unsigned char mask);
};
// @fnv 0x00493860
void FUN_00493860_shell::FUN_00493860(bool f)
{
    reinterpret_cast<::FUN_00493880_shell *>((((ST_00493860*)this)))->SetFlag(f, true);
}

// Sets or clears the bits of m_flags selected by mask, according to set.
// @fnv 0x00493880
void FUN_00493880_shell::SetFlag(bool set, unsigned char mask)
{
    if (set)
        m_flags |= mask;
    else
        m_flags &= ~mask;
}

struct FUN_00493990_shell
{
    bool HasFlag(unsigned char aFlag);
};
// @fnv 0x00493b90
bool FUN_00493b90_shell::FUN_00493b90()
{
    return reinterpret_cast<::FUN_00493990_shell *>((((FUN_00493990_helper*)this)))->HasFlag(1);
}

// @fnv 0x00493990
bool FUN_00493990_shell::HasFlag(unsigned char aFlag)
{
    return (*reinterpret_cast<unsigned char*>(this) & aFlag) != 0;
}

namespace fnv_004939b0 {
struct ST_00493860
{
    void SetFlag(bool, int);
    void FUN_004939b0(bool argument0);
};

void ST_00493860::SetFlag(bool, int)
{}

// @fnv 0x004939b0
void ST_00493860::FUN_004939b0(bool argument0)
{
    reinterpret_cast<::FUN_00493880_shell *>(this)->SetFlag(argument0, 2);
}
}  // namespace fnv_004939b0

struct FUN_00495560_shell
{
    int m_01c4;
    std::intptr_t GetFieldAt(int index);
};

// @fnv 0x00495560
std::intptr_t FUN_00495560_shell::GetFieldAt(int index)
{
    return ((std::intptr_t*)((char*)this + 0x1c4))[index];
}

struct FUN_004964a0_shell
{
    void FUN_004964a0(bool abFlag);
};

extern float DAT_0101d890;

// If abFlag is false, stores the negated DAT_0101d890 into the float at this+0x1c.
// @fnv 0x004964a0
void FUN_004964a0_shell::FUN_004964a0(bool abFlag)
{
    if (!abFlag)
        *(float*)((char*)this + 0x1c) = -DAT_0101d890;
}

struct FUN_00496960_shell
{
    void SetByteAt14E(unsigned char value);
};

// @fnv 0x00496960
void FUN_00496960_shell::SetByteAt14E(unsigned char value)
{
    *(unsigned char*)((char*)this + 0x14e) = value;
}

struct GO
{
    GO& operator=(void*);
};

struct FUN_004970e0_shell
{
    GO m_GO;
    void AssignGO(void* p);
};

// @fnv 0x004970e0
void FUN_004970e0_shell::AssignGO(void* apValue)
{
    ((GO*)((char*)this + 0x18))->operator=(apValue);
}

struct FUN_0049bd90_shell : KFModel
{
    void FUN_0049bd90(void* a1);
};

struct FUN_004f05c0_shell
{
    void ApplyFlagsToEntries(void* a1);
};

void FUN_004f05c0_shell::ApplyFlagsToEntries(void* a1)
{}

// @fnv 0x0049bd90
void FUN_0049bd90_shell::FUN_0049bd90(void* a1)
{
    void* seq = ((void *)(reinterpret_cast<::TESRegionDataMap *>(this)->GetRegionMapName()));
    if (seq)
        reinterpret_cast<::FUN_004f05c0_cls *>((((FUN_004f05c0_shell*)seq)))->ApplyFlagsToEntries((std::uintptr_t)(a1));
}

namespace fnv_0048f080 {
class BSAnimGroupSequence;
struct MyBase080
{
    virtual void Dummy() = 0;
    virtual void Target(BSAnimGroupSequence*, bool) = 0;
};
struct AnimSequenceSingle : MyBase080
{
    BSAnimGroupSequence* pForwardSequence;
    bool FUN_0048f080(BSAnimGroupSequence* apSeq, bool abReleaseModelLoader);
};
// @fnv 0x0048f080
bool AnimSequenceSingle::FUN_0048f080(BSAnimGroupSequence* apSeq, bool abReleaseModelLoader)
{
    if (pForwardSequence == apSeq)
    {
        Target(0, abReleaseModelLoader);
        return true;
    }
    return false;
}
}  // namespace fnv_0048f080

namespace fnv_0048f1d0 {
struct AnimSequenceMultiple
{
    void FUN_0048f220();
    void* FUN_0048f1d0(unsigned int flags);
};
// Calls FUN_0048f220, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0048f1d0
void* AnimSequenceMultiple::FUN_0048f1d0(unsigned int flags)
{
    FUN_0048f220();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_0048f1d0

struct S48f370
{
    void* FUN_0048f370(unsigned int);
};
// Calls FUN_0054da00 on this, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x0048f370
void* S48f370::FUN_0048f370(unsigned int flags)
{
    reinterpret_cast<::FUN_0054da00_class *>((this))->FUN_0054da00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct ThisStub
{
    void UpdateAnimationForRef(void* apRef);
    void FUN_00493900(void* apRef);
};
struct C00493930
{
    bool FUN_00493970();
    bool FUN_00493930();
};
extern float DAT_0101d890;
struct S00496440
{
    float field0;
    void FUN_00496440(bool);
};
// If b is false, sets field0 to the negation of DAT_0101d890.
// @fnv 0x00496440
void S00496440::FUN_00496440(bool b)
{
    if (!b)
        field0 = -DAT_0101d890;
}

struct Modifier
{
    void SetValue(float);
};
extern float DAT_0101d890;
struct FUN_00496470_shell
{
    char _pad[12];
    Modifier m;
    void FUN_00496470(bool);
};
// If flag is false, sets the modifier's value to the negation of DAT_0101d890.
// @fnv 0x00496470
void FUN_00496470_shell::FUN_00496470(bool flag)
{
    if (!flag)
        reinterpret_cast<::FUN_004f5d90_shell *>(&(m))->FUN_004f5d90(-DAT_0101d890);
}

struct EBase
{
    ~EBase();
};
struct FUN_004968e0_shell : EBase
{
    void* FUN_004968e0(unsigned int);
};
// Runs the base destructor, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004968e0
void* FUN_004968e0_shell::FUN_004968e0(unsigned int flags)
{
    ::FUN_00496910((int **)(this));
    if (flags & 1)
        ::FUN_00aa1460(this, 8);
    return this;
}

namespace fnv_00498230 {
struct Flt
{
    operator std::uintptr_t() const;
};
struct LowProcess
{
    void SetCurrentBoundObject(void*);
};
struct HA
{
};
bool FUN_00498290(void*);
struct Holder
{
    bool FUN_00498230(void*);
};
// @fnv 0x00498230
bool Holder::FUN_00498230(void* apActor)
{
    if (FUN_00498290(this))
    {
        reinterpret_cast<::LowProcess *>(((*(LowProcess**)((char*)this + 0x124))))->SetCurrentBoundObject((::TESBoundObject *)(apActor));
        reinterpret_cast<::fnv_008a73e0::FUN_008a73e0_shell *>((((HA*)apActor)))->FUN_008a73e0(0xD, (::fnv_008a73e0::BSAnimGroupSequence *)(void *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((*(AnimIdle**)((char*)this + 0x124))))->FUN_00490e40()));
        return true;
    }
    return false;
}
}  // namespace fnv_00498230

namespace fnv_004985b0 {
struct Flt
{
    operator std::uintptr_t() const;
};
struct TESObjectREFR_GetFlags_Helper
{
};
struct FUN_004985b0_Owner
{
    bool IsFlaggedAsTwo();
};
// @fnv 0x004985b0
bool FUN_004985b0_Owner::IsFlaggedAsTwo()
{
    if ((unsigned int)*(Flt*)((char*)this + 0x124) == 0)
        return 0;
    return ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(((*(TESObjectREFR_GetFlags_Helper**)((char*)this + 0x124))))->GetName())) == 2;
}
}  // namespace fnv_004985b0

struct S_0049c050
{
    void* Construct(int);
};
extern int DAT_0101ded0;
struct Holder_49c080
{
    void* FUN_0049c080(unsigned int);
};
// Calls FUN_0049c510, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0049c080
void* Holder_49c080::FUN_0049c080(unsigned int flags)
{
    reinterpret_cast<::FUN_0049c510 *>(this)->FUN_0049c510::~FUN_0049c510();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct NiTPointerList
{
    void* Find(TESForm* const&, void*);
    TESForm* FindOrSelf(TESForm* const&);
};
// @fnv 0x0049c0b0
TESForm* NiTPointerList::FindOrSelf(TESForm* const& form)
{
    void* ptr = Find(form, 0);
    return ptr ? ((::TESForm *)(std::uintptr_t)(reinterpret_cast<::FUN_0049c5d0_cls *>(this)->RemoveNode((::ListLink_b5187 **)(void **)(&ptr)))) : form;
}

struct FUN_004bc1f0_S
{
    void FUN_004bc1f0(float, float, float);
};
struct S00739970
{
    unsigned char _pad[0x0DBC];
    FUN_004bc1f0_S* _p;
    void FUN_00739970(bool);
};
// Calls FUN_004bc1f0 on _p with zero x/y and a z of g_011da6a4_arg1 when b is false, or 0.0 when b is true.
// @fnv 0x00739970
void S00739970::FUN_00739970(bool b)
{
    if (!b)
    {
        _p->FUN_004bc1f0(0.0f, 0.0f, g_011da6a4_arg1);
    }
    else
    {
        _p->FUN_004bc1f0(0.0f, 0.0f, 0.0f);
    }
}

namespace fnv_00921e30 {
struct Flt
{
    operator std::uintptr_t() const;
};
struct StandIn
{
    char _pad[0x124];
    Flt m_kHandle;
    BSAnimGroupSequence* FUN_00921e30();
};
// @fnv 0x00921e30
BSAnimGroupSequence* StandIn::FUN_00921e30()
{
    return m_kHandle ? reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((AnimIdle*)(std::uintptr_t)m_kHandle)))->FUN_00490e40() : 0;
}
}  // namespace fnv_00921e30

namespace fnv_004937c0 {
struct TESAnimGroup
{
    unsigned short sType;
    bool FUN_004937c0();
};

// @fnv 0x004937c0
bool TESAnimGroup::FUN_004937c0()
{
    return ::TESAnimGroup::IsAimAnimation(*(unsigned short*)((char*)this + 0x10));
}
}  // namespace fnv_004937c0

namespace fnv_004937e0 {
struct TESAnimGroup
{
    bool FUN_004937e0();
};

// @fnv 0x004937e0
bool TESAnimGroup::FUN_004937e0()
{
    return ::TESAnimGroup::IsActionTypeValid(*(unsigned short*)((char*)this + 0x10));
}
}  // namespace fnv_004937e0

namespace fnv_00493970 {
struct FUN_00493990_shell
{
    bool FUN_00493970();
};

// @fnv 0x00493970
bool FUN_00493990_shell::FUN_00493970()
{
    return reinterpret_cast<::FUN_00493990_shell *>(this)->HasFlag(2);
}
}  // namespace fnv_00493970

struct FUN_0049c100_shell
{
    void* vft;
    int count;
    void* data;
    int unused;
    FUN_0049c100_shell* FUN_0049c100(int n);
};
// Calls FUN_0049c100 with a, stores the address of DAT_0101ded0 into this, and returns this.
// @fnv 0x0049c050
void* S_0049c050::Construct(int a)
{
    reinterpret_cast<::FUN_0049c100_shell *>(this)->FUN_0049c100(a);
    *(void**)this = (void*)&DAT_0101ded0;
    return this;
}
// Sets the vtable, stores n in count, allocates count*4 zeroed bytes into data and returns this.
// @fnv 0x0049c100
FUN_0049c100_shell* FUN_0049c100_shell::FUN_0049c100(int aiCount)
{
    vft = (void*)&DAT_0101def0;
    count = aiCount;
    unused = 0;
    unsigned int uiSize = count * 4;
    data = ::FUN_00aa1070(uiSize);
    memset(data, 0, count * 4);
    return this;
}

namespace fnv_00495d50 {
struct Flt
{
    unsigned char _d[0x18];
    operator std::uintptr_t() const;
};
struct Holder_00495d50
{
    unsigned char _pad0[0xE];
    unsigned char f0E;
    unsigned char f0F;
    unsigned char _pad10[4];
    Flt* p14;
    unsigned int v18;
    unsigned int GetValueForIndex(unsigned char);
};
// Returns v18 when f0E is 1 and a equals f0F, otherwise converts p14[a] to unsigned int.
// @fnv 0x00495d50
unsigned int Holder_00495d50::GetValueForIndex(unsigned char a)
{
    if (f0E == 1 && a == f0F)
        return v18;
    return (unsigned int)p14[a];
}
}  // namespace fnv_00495d50

struct TESAnimGroup;
struct SeqHack
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual BSAnimGroupSequence* GetSeq(int);
};
struct GrpHack
{
};
struct HackAnim
{
    char _pad[0xdc];
    NiTPointerMap<unsigned short, AnimSequenceBase*>* m_pOwnerReference;
    TESAnimGroup* FUN_00496500(unsigned short asGroup);
};
// Looks up the sequence for asGroup in the map and returns the anim group from its sequence, or null if not found.
// @fnv 0x00496500
TESAnimGroup* HackAnim::FUN_00496500(unsigned short asGroup)
{
    AnimSequenceBase* panimSeq;
    if (reinterpret_cast<::NiTMapBase *>((void *)(m_pOwnerReference))->Lookup(asGroup, panimSeq))
    {
        return reinterpret_cast<::BSAnimGroupSequence *>((((GrpHack*)((SeqHack*)panimSeq)->GetSeq(-1))))->GetAnimGroup();
    }
    return 0;
}

struct FakeRef
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
    virtual void v125();
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
    virtual bool Virt(int);
};
struct FakeAnim
{
    unsigned short GetSerializedSize(void* apRef);
};
// Returns 2 plus the animation's size for apRef when apAnimation is set and apRef's Virt(0) check fails.
// @fnv 0x0049aa20
unsigned short GetAnimationSize(void* apRef, void* apAnimation)
{
    unsigned short usSize = 0;
    usSize += 2;
    if (apAnimation)
    {
        if (!((FakeRef*)apRef)->Virt(0))
        {
            usSize += ((FakeAnim*)apAnimation)->GetSerializedSize(apRef);
        }
    }
    return usSize;
}

namespace fnv_00490e60 {
struct FUN_00490e60_shell : public Animation
{
    bool ShouldQueueAnimations();
};

struct Flt
{
    operator std::uintptr_t();
};
struct _FUN_00822510_Class
{
    bool operator==(int) const;
};
struct PC_00605d70
{
    NiNode* GetNode(bool);
};
struct GlobalObject_0045cfe0
{
};
struct BGSSaveLoadGame
{
};
struct AIThreadManager
{
};
struct Interface
{
    enum enumMenus
    {
        kMenu_Dummy = 0
    };
    static bool IsMenuActive(enumMenus, unsigned int);
};
struct FUN_00451530_shell
{
};

// @fnv 0x00490e60
bool FUN_00490e60_shell::ShouldQueueAnimations()
{
    bool bqueueAnims = false;
    bqueueAnims = true;
    if (!(*reinterpret_cast<::fnv_00490e60::PC_00605d70 * *>(&::_g_thePlayer)) || !((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_00490e60::PC_00605d70 * *>(&::_g_thePlayer))))->FUN_00950bb0(false))) || !*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_00490e60::GlobalObject_0045cfe0 *>(&::g_011c5778)))))))
    {
        bqueueAnims = false;
    }
    else if (*(NiNode**)((char*)this + 8) == ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_00490e60::PC_00605d70 * *>(&::_g_thePlayer))))->FUN_00950bb0(false))) ||
             *(NiNode**)((char*)this + 8) == ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::fnv_00490e60::PC_00605d70 * *>(&::_g_thePlayer))))->FUN_00950bb0(true))) ||
             reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::fnv_00490e60::_FUN_00822510_Class &)(*(const _FUN_00822510_Class*)((char*)this + 8)))->operator==(((std::intptr_t)(::fnv_00490f80::FUN_00490f80((char *)((*reinterpret_cast<::fnv_00490e60::PC_00605d70 * *>(&::_g_thePlayer))))))))
    {
        if (!Interface::IsMenuActive((Interface::enumMenus)0x40c, 0))
            bqueueAnims = false;
    }
    else if (reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00490e60::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
    {
        bqueueAnims = false;
    }
    else if (this->m_pAttachedReference == ((::TESObjectREFR *)(::FUN_0047b200())))
    {
        bqueueAnims = false;
    }
    else if (::FUN_00702360())
    {
        bqueueAnims = false;
    }
    else if (reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(((*reinterpret_cast<::fnv_00490e60::FUN_00451530_shell * *>(&::g_TES))))->FUN_00451530())
    {
        bqueueAnims = false;
    }
    return bqueueAnims;
}
}  // namespace fnv_00490e60

namespace fnv_0048f720 {
struct Flt
{
    operator std::uintptr_t();
};
struct FUN_006317a0_struct
{
};
struct NiTPointerList
{
};
struct FUN_0048f720_shell
{
    AnimSequenceBase base;
    void* m_pSingleSequence;
    char FindSequenceIndex(BSAnimGroupSequence* apSeq);
};
// Walks the sequence list from the head, returning the zero-based index of apSeq or -1 if it is not found.
// @fnv 0x0048f720
char FUN_0048f720_shell::FindSequenceIndex(BSAnimGroupSequence* apSeq)
{
    void* listIt = *(void**)(m_pSingleSequence);
    char iIndex = 0;
    while (listIt)
    {
        BSAnimGroupSequence* pSequence =
            *(BSAnimGroupSequence**)reinterpret_cast<::FUN_006317a0_struct *>((((FUN_006317a0_struct*)m_pSingleSequence)))->AddEight((std::intptr_t)listIt);
        if (apSeq == pSequence)
            return iIndex;
        ++iIndex;
        listIt = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((((NiTPointerList*)m_pSingleSequence)))->DereferenceIfNotNull((int **)(listIt))));
    }
    return -1;
}
}  // namespace fnv_0048f720

namespace fnv_00497100 {
struct Flt
{
    operator std::uintptr_t();
};
struct FUN_004efb10_shell
{
};
struct FUN_00497100_shell
{
    unsigned short FUN_00497100();
};
// Computes a size: sums 4+4+4+1, and if the field at offset 0x18 is nonzero adds its FUN_004efb10 result plus 1.
// @fnv 0x00497100
unsigned short FUN_00497100_shell::FUN_00497100()
{
    unsigned short v = 0;
    v += 4;
    v += 4;
    v += 4;
    v += 1;
    if ((unsigned int)*(Flt*)((char*)this + 0x18))
        v += (unsigned short)(unsigned short)reinterpret_cast<::FUN_004efb10_shell *>(((*(FUN_004efb10_shell**)((char*)this + 0x18))))->FUN_004efb10() +
             1;
    return v;
}
}  // namespace fnv_00497100

namespace fnv_004981f0 {
struct GO
{
    operator std::uintptr_t() const;
};

struct Crime
{
    TESObjectREFR* GetTarget();
};

struct FUN_004981f0_shell
{
    bool FUN_004981f0();
};

// Returns true if the GO at offset 0x124 is nonzero and its Crime target equals 1, otherwise false.
// @fnv 0x004981f0
bool FUN_004981f0_shell::FUN_004981f0()
{
    if (!((GO*)((char*)this + 0x124))->operator std::uintptr_t())
        return false;
    return (std::uintptr_t)((::TESObjectREFR *)(reinterpret_cast<::Twin_0044ddc0 *>((((Crime*)((GO*)((char*)this + 0x124))->operator std::uintptr_t())))->GetName())) == 1;
}
}  // namespace fnv_004981f0

namespace fnv_0048f220 {
struct NiFixedStr
{
    operator const char*() const;
};
struct SeqObj
{
    NiFixedStr& GetName();
};
struct ModelLoaderStub
{
    void NewItem(void*);
};
struct FUN_0048ef40
{
    virtual ~FUN_0048ef40();
};

struct SeqNameList
{
    SeqObj*& GetAt(void* pos);
    ~SeqNameList();
};

struct FUN_0048f220 : public FUN_0048ef40
{
    SeqNameList* pList;
    virtual ~FUN_0048f220();
};

// Iterates the sequence name list, copies each entry's name, calls FUN_00401970 on it, passes the name to g_modelLoader->NewItem, then deletes the list.
// @fnv 0x0048f220
FUN_0048f220::~FUN_0048f220()
{
    if (pList)
    {
        void* pos = ((void *)(::FUN_00559450((int *)(pList))));
        while (pos)
        {
            SeqObj* pForwardSequence = ((::fnv_0048f220::SeqObj *)(reinterpret_cast<::FUN_006317a0_struct *>((pList))->AddEight((std::intptr_t)(pos))));
            char acName[260];
            ::TaskQueueInterface::CopyStringToBuffer(acName, 260, (*(::fnv_0048f220::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((pForwardSequence))->GetLinkToList())));
            reinterpret_cast<::WaitableObject *>((pForwardSequence))->FUN_00401970();
            ((ModelLoaderStub*)g_modelLoader)->NewItem(acName);
            pos = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((pList))->DereferenceIfNotNull((int **)(pos))));
        }
        delete pList;
    }
}
}  // namespace fnv_0048f220

struct S_00490400_Anim : public Animation
{
    void FUN_00490400(BSSimpleList<const char*>* apFileList);
};

struct NiTextKeyStub
{
    float m_fTime;
    NiFixedString m_kText;
    const NiFixedString& GetText() const;
    float GetTime() const;
};

struct NiTextKeyExtraDataStub
{
};

struct NiControllerSequenceStub
{
    NiTextKeyExtraDataStub* GetTextKeys();
};

struct AnimSequenceStub
{
    int unk00[60];
    NiControllerSequenceStub* m_pkSequence;
    char FUN_00495e40(float* pfTime);
};

// Scans the sequence's text keys for one starting with "a:" and returns the lowercased character after the prefix, optionally storing its time.
// @fnv 0x00495e40
char AnimSequenceStub::FUN_00495e40(float* pfOutTime)
{
    const char* pcPrefixVal = "a:";
    if (!m_pkSequence)
        return 0;
    NiTextKeyExtraDataStub* _pkTextKeys = m_pkSequence->GetTextKeys();
    unsigned int kUiNumKeys;
    NiTextKeyStub* pkKeys6 = ((::NiTextKeyStub *)(reinterpret_cast<::FUN_00495f30_shell *>((_pkTextKeys))->FUN_00495f30((int *)&(kUiNumKeys))));
    unsigned int uiPrefixLen = ::FUN_0044a670(pcPrefixVal);
    if (!uiPrefixLen)
        return 0;
    for (unsigned int i4 = 0; i4 < kUiNumKeys; i4++)
    {
        const char* pcText9 = pkKeys6[i4].GetText();
        if (pcText9 && !fnv::crt::strnicmp(pcText9, pcPrefixVal, uiPrefixLen))
        {
            if (pfOutTime)
                *pfOutTime = reinterpret_cast<::CombatTargetTimestamp *>((void *)&(pkKeys6[i4]))->FUN_006a7f50();
            return tolower(pcText9[uiPrefixLen]);
        }
    }
    return 0;
}

template <class T> class NiPtr
{
  public:
    T* m_pObject;
    operator T*() const;
    NiPtr<T>& operator=(T* object);
};

struct SaveLoadStub
{
};

unsigned short FUN_004efaa0();

struct AnimGroupStub
{
    unsigned int GetType();
};

struct GroupSeqStub
{
    AnimGroupStub* GetAnimGroup();
};

struct KFModelStub
{
    AnimGroupStub* GetAnimGroup();
};

struct SeqBaseStub
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual GroupSeqStub* GetSequenceAtIndex(int);
};

struct SeqMapStub
{
    bool GetAt(unsigned short key, SeqBaseStub*& result) const;
};

struct AnimStub
{
    GroupSeqStub* FUN_004949a0(GroupSeqStub* apSeq, unsigned short asGroup, int aiFlag);
};

struct QueuedAnimStub
{
    int unk00;
    int unk04;
    int iState;
    int unk0C;
    NiPtr<KFModelStub> m_pRenderedNodeEntry;
    int unk14;
    NiPtr<GroupSeqStub> pListSequence;

    void LoadQueuedAnim(float afTime, AnimStub* apAnimation);
};

struct ActiveManager
{
};
extern "C" ActiveManager* DAT_011de45c;
struct ParameterObject
{
};
struct StringManager
{
    const unsigned char* FUN_00408d60();
};
struct MessageInfo
{
    int id;
    unsigned char kind;
};
struct MessageProvider
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void slot_0d4();
    virtual void slot_0d8();
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void slot_0e8();
    virtual void slot_0ec();
    virtual void slot_0f0();
    virtual void slot_0f4();
    virtual void slot_0f8();
    virtual void slot_0fc();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_10c();
    virtual void slot_110();
    virtual void slot_114();
    virtual void slot_118();
    virtual void slot_11c();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_12c();
    virtual int GetDisplayValue();
};
// Computes a message size by summing fixed and variable field sizes, then logs the total with the message id and display value.
// @fnv 0x004974c0
unsigned short __cdecl GetMessageSize(void* unused, ParameterObject* param)
{
    unsigned short count = 0;
    unsigned short usInitialSize = count;
    if (((unsigned char)(reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame))))->FUN_00862110())))
    {
        count += 4;
        count += 2;
    }
    count += 4;
    if (param != 0 && ((int)(reinterpret_cast<::BGSMessageInitAccess *>((param))->GetIconFormID())))
    {
        count += 2;
        count += reinterpret_cast<::fnv_00497100::FUN_00497100_shell *>((param))->FUN_00497100();
    }
    if (*(*reinterpret_cast<::StringManager *>(&::g_011de4e8)).FUN_00408d60())
    {
        MessageInfo* message = ((::MessageInfo *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (message)
        {
            MessageProvider* provider = ((::MessageProvider *)(::FUN_004839c0(message->id)));
            ::FUN_0040fbe0(::DAT_01012cb0, count - usInitialSize, message->id, provider->GetDisplayValue(),
                         *(int*)((char*)message + 5), 0x11f3, DAT_0101d930);
        }
        else
        {
            ::FUN_0040fbe0(::DAT_01012c78, count - usInitialSize, 0x11f3, DAT_0101d930);
        }
    }
    return count;
}

struct Seq_49bdc0
{
};
struct FUN_0049bdc0_shell : Animation
{
    void SetAnimationAmount(float amount);
    void FUN_00494740(unsigned short, int, int, int);
};
// @fnv 0x0049bdc0
void FUN_0049bdc0_shell::SetAnimationAmount(float amount)
{
    if (amount == 0.0)
    {
        if (m_pChildTile[3])
        {
            reinterpret_cast<::AnimationSequence *>((((Seq_49bdc0*)m_pChildTile[3])))->FUN_00a34ba0(0.0f, true);
            reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(3, 0.0f);
        }
    }
    else
    {
        if (!m_pChildTile[3])
        {
            FUN_00494740(0xe1, 1, -1, -1);
            if (m_pChildTile[3])
            {
                reinterpret_cast<::AnimationSequence *>((((Seq_49bdc0*)m_pChildTile[3])))->FUN_00a34ba0(reinterpret_cast<::FUN_00759450_shell *>((((Seq_49bdc0*)m_pChildTile[3])))->FUN_00759450() + time, true);
            }
        }
        if (m_pChildTile[3] && ((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((((Seq_49bdc0*)m_pChildTile[3])))->GetActiveCombatTarget())) == 1)
        {
            float delta =
                reinterpret_cast<::FUN_00508100_shell *>((((Seq_49bdc0*)m_pChildTile[3])))->FUN_00508100() - reinterpret_cast<::FUN_00759450_shell *>((((Seq_49bdc0*)m_pChildTile[3])))->FUN_00759450();
            m_fTimeOffset = reinterpret_cast<::FUN_00759450_shell *>((((Seq_49bdc0*)m_pChildTile[3])))->FUN_00759450() + delta * amount;
            reinterpret_cast<::fnv_00a328b0::SeqExt *>((((Seq_49bdc0*)m_pChildTile[3])))->FUN_00a328b0(m_fTimeOffset - time, true);
        }
    }
}

struct Seq_48f3d0
{
};
struct List_48f3d0
{
};
struct C48F3D0
{
    int unk00;
    List_48f3d0* pList;
    bool FUN_0048f3d0(Seq_48f3d0* pForwardSequence, bool b);
};
// @fnv 0x0048f3d0
bool C48F3D0::FUN_0048f3d0(Seq_48f3d0* pItem, bool abUnused)
{
    reinterpret_cast<::WaitableObject *>((pItem))->FUN_00401970();
    reinterpret_cast<::NiTPointerList *>((pList))->FindOrSelf((::TESForm *const &)(pItem));
    if (reinterpret_cast<::FUN_0076b610_Class *>((pList))->FUN_0076b610())
    {
        List_48f3d0* a = pList;
        List_48f3d0* p = a;
        p ? reinterpret_cast<::S48f370 *>((p))->FUN_0048f370(1) : 0;
        pList = 0;
        return true;
    }
    return false;
}

struct BNFixedString
{
    operator const char*() const;
};

struct BNObject
{
    BNFixedString& GetName();
};

struct BNObjectList
{
    BNObject*& GetAt(void* apPos);
};

char* __cdecl BNStrchr(char* apString, int aiChar);

struct BNLookup
{
    int unk00;
    BNObjectList* m_pObjectList;

    BNObject* FindObjectByNameVariant(BNObject* apObject, int aiVariant);
};
// Looks up the sequence base for a group, resolves its type when type is -1, picks a single or multiple sequence, and passes it to FUN_004949a0.
// @fnv 0x004948c0
SeqIface* FUN_004948c0_shell::GetSequenceForGroup(unsigned short group, int type)
{
    AnimSequenceBase* pSeqBase;
    SeqIface* pseqX;
    SeqIface* pSeqMultiple;
    int iType;
    if (group == 0xff || !reinterpret_cast<::NiTMapBase *>((void *)(m_pOwnerReference))->Lookup(group, pSeqBase))
        return 0;
    iType = type;
    if (iType == -1)
        iType = (*reinterpret_cast<AnimGroupInfo (*)[]>(&::DAT_011977e0))[GetType(group)].iType;
    switch (iType)
    {
    case 5:
    case 6:
        if (!((SeqIface*)pSeqBase)->IsSingleSeq())
        {
            pSeqMultiple = (SeqIface*)pSeqBase;
            pseqX = ((::SeqIface *)(reinterpret_cast<::BNLookup *>((pSeqMultiple))->FindObjectByNameVariant((::BNObject *)(*(void**)&this->m_pChildTile[4]), iType)));
            break;
        }
    default:
        pseqX = ((SeqIface*)pSeqBase)->GetSequenceAtIndex(-1);
    }
    return FUN_004949a0(pseqX, group, type);
}

// @fnv 0x0048f500
BNObject* BNLookup::FindObjectByNameVariant(BNObject* apObject, int aiVariant)
{
    void* pPosVal = ((void *)(::FUN_00559450((int *)(m_pObjectList))));
    char* pName3 = (char*)strrchr((*(::BNFixedString *)(reinterpret_cast<::TESTopicInfoData *>((apObject))->GetLinkToList())), '\\');
    char* pSuffix4;
    char acBufferX[260];

    if (!pName3)
        return 0;

    switch (aiVariant)
    {
    case 5:
        ::FUN_004046f0(acBufferX, pName3);
        pSuffix4 = BNStrchr(acBufferX, '_');
        if (pSuffix4)
        {
            ::FUN_004046f0(pSuffix4, "Up");
            pSuffix4 = BNStrchr(pName3, '_');
            std::strcat(acBufferX, pSuffix4);
        }
        else
            std::strcat(acBufferX, "Up");
        pName3 = acBufferX;
        break;
    case 6:
        ::FUN_004046f0(acBufferX, pName3);
        pSuffix4 = BNStrchr(acBufferX, '_');
        if (pSuffix4)
        {
            ::FUN_004046f0(pSuffix4, "Down");
            pSuffix4 = BNStrchr(pName3, '_');
            std::strcat(acBufferX, pSuffix4);
        }
        else
            std::strcat(acBufferX, "Down");
        pName3 = acBufferX;
        break;
    }

    while (pPosVal)
    {
        BNObject* pObject = ((::BNObject *)(reinterpret_cast<::FUN_006317a0_struct *>((m_pObjectList))->AddEight((std::intptr_t)(pPosVal))));
        char* pObjectName = (char*)strrchr((*(::BNFixedString *)(reinterpret_cast<::TESTopicInfoData *>((pObject))->GetLinkToList())), '\\');
        if (pObjectName && !::FUN_00404dc0(pObjectName, pName3))
            return pObject;
        pPosVal = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((m_pObjectList))->DereferenceIfNotNull((int **)(pPosVal))));
    }
    return 0;
}

struct Group490
{
    int GetType();
};
struct Root490;
struct Model490
{
    operator const char*() const;
};
struct GroupPtr490
{
    Group490* value;
    GroupPtr490(Group490*);
    ~GroupPtr490();
    operator Group490*() const;
};
struct String490
{
    String490(const char*);
    ~String490();
    operator const char*() const;
    const char* value;
};
struct Root490
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
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
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual Root490* Find(const String490&);
    String490& GetName();
    int GetState();
};
struct Seq490 : Root490
{
    Seq490(Group490*, Root490*);
    void GetTarget(unsigned int, char*);
    Group490* GetAnimGroup();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
};
struct Base490
{
    virtual ~Base490();
    virtual void Set(Seq490*, bool);
    virtual bool Remove(Seq490*, bool);
    virtual bool IsSingle();
    virtual Seq490* Get(int);
};
struct Single490 : Base490
{
    Single490();
    Seq490* sequence;
};
struct Multiple490 : Base490
{
    Multiple490(Single490*);
    void* list;
};
struct Map490
{
    bool GetAt(unsigned short, Base490*&) const;
};
struct Manager490
{
    void Remove(Seq490*);
    bool Add(Seq490*, int*, bool);
};
struct ManagerPtr490
{
    Manager490* value;
    operator Manager490*() const;
};
struct RootPtr490
{
    Root490* value;
    operator Root490*() const;
};
struct Idle490
{
    Seq490* GetControllerSequence();
};
struct IdlePtr490
{
    Idle490* value;
    operator Idle490*() const;
};
struct List490
{
    void* head;
    void* tail;
};
using Context490 = ::AutoMemContext;
struct Info490
{
    unsigned char multiple;
    unsigned char u01;
    unsigned short u02;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    int u18;
    int u1c;
    int u20;
};
extern const char DAT_0101da38[];
extern const char DAT_0101d9a8[];
extern const char DAT_0101d970[];
void Warning490(const char*, ...);
bool Menu490(int, unsigned int);
struct Anim490
{
    int unk00;
    int unk04;
    RootPtr490 root;
    Root490* accum;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    unsigned short groups[8];
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    ManagerPtr490 manager;
    Map490* map;
    Seq490* current[8];
    Seq490* last;
    List490 models;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    IdlePtr490 idle;
    IdlePtr490 queued;
    int unk134;
    bool AddModel(Model490* model, bool queue);
};
// Validates files, root and actor, loads KF models into the animation list, creates the controller manager and optionally activates the first sequence.
// @fnv 0x0048ffd0
bool Animation::Init(BSSimpleList<const char*>* files, NiNode* root, TESObjectREFR* actor, bool activate)
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_ANIMATION, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 568);
    if (!files || !root || !actor)
        return false;
    m_pAttachedReference = actor;
    AnimSequenceBase* pSequence;
    if (m_pOwnerReference && reinterpret_cast<::NiTMapBase *>((void *)(m_pOwnerReference))->Lookup(0, pSequence))
        return false;
    bool bIsCreature = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((actor))->FUN_007af430()))->GetFormType() == 42;
    m_acHeaderData = root;
    for (int i = 0; i <= 7; ++i)
        if (DAT_01199bcc[i])
            m_acNodeName[i] =
                reinterpret_cast<::FUN_00490310_shell *>((static_cast<TESObjectREFR_AnimationExt*>(actor)))->FUN_00490310((::NiAVObject *)(root), (::NiFixedString *)(DAT_01199bcc[i]));
    reinterpret_cast<::TaskQueueInterface *>(((m_acHeaderData).operator->()))->FUN_004902f0(false);
    m_acReservedBytes = new NiControllerManager(m_acHeaderData, true);
    bool bQueue = IsAnimationLoaded();
    while (!files->IsEmpty())
    {
        const char* file = (files->m_item);
        KFModel* model = ((::KFModel *)(reinterpret_cast<::fnv_004471c0::FUN_004471c0_shell *>((g_modelLoader))->LoadKFModel((char *)(file))));
        if (model && ((void *)(reinterpret_cast<::TESRegionDataMap *>((model))->GetRegionMapName())))
            reinterpret_cast<::Anim490 *>(this)->AddModel((::Model490 *)(model), bQueue);
        delete file;
        files->RemoveHead();
    }
    if (m_pObjectNode)
        reinterpret_cast<::FUN_0043fa80_s *>((m_pObjectNode))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&(*reinterpret_cast<char *>(&::DAT_011a9448)))));
    delete files;
    bool m_bHeaderParsed = reinterpret_cast<::NiTMapBase *>((void *)(m_pOwnerReference))->Lookup(0, pSequence);
    if (m_bHeaderParsed && activate)
    {
        BSAnimGroupSequence* anim = pSequence->GetSequenceAtIndex(-1);
        if (anim)
        {
            reinterpret_cast<::SeqA34f20 *>((anim))->StartSequence(100, true, 1.0f, 0.0f, (::SeqA34f20 *)(::NiControllerSequence *)(0), false);
            NiUpdateData update(0.0f, true, false);
            reinterpret_cast<::FUN_00a59c60_cls *>(((m_acHeaderData).operator->()))->FUN_00a59c60((std::intptr_t)&(update));
            anim->Deactivate(0.0f, false);
        }
    }
    return m_bHeaderParsed;
}
// Builds a path from apPath, "SpecialAnims" and each file name, loads the KF model and adds it as an animation.
// @fnv 0x00490330
void FUN_00490330_t::FUN_00490330(BSSimpleList<const char*>* apFileList, const char* apPath)
{
    BSSimpleList<const char*>* pfileList;
    if (!apFileList)
        return;
    pfileList = apFileList;
    while (pfileList)
    {
        KFModel* pkfModel;
        char message[260];
        const char* pfilename;
        bool bqueueAnims;
        pfilename = *((const char **)((void *)(((FileListNode*)pfileList))));
        ::FUN_00406d00(message, 260, "%s\\%s\\%s", apPath, "SpecialAnims", pfilename);
        pkfModel = ((::KFModel *)(reinterpret_cast<::fnv_004471c0::FUN_004471c0_shell *>((g_modelLoader))->LoadKFModel((char *)(message))));
        bqueueAnims = IsAnimationLoaded();
        if (pkfModel)
            reinterpret_cast<::Anim490 *>(this)->AddModel((::Model490 *)(pkfModel), bqueueAnims);
        pfileList = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((((FileListNode*)pfileList)))->FUN_00726070()));
    }
}
// Loads each path in the list as a KF model, adds it as an animation with a flag from ShouldQueueAnimations, then frees the paths and the list.
// @fnv 0x00490400
void S_00490400_Anim::FUN_00490400(BSSimpleList<const char*>* apFileList)
{
    if (!apFileList)
        return;
    {
        AutoMemContext kContextX((MEM_CONTEXT)0x33, true,
                                 "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 0x2ee);
        bool bFlag = reinterpret_cast<::fnv_00490e60::FUN_00490e60_shell *>((this))->ShouldQueueAnimations();
        while (!apFileList->IsEmpty())
        {
            const char* pcPath7 = (apFileList->m_item);
            KFModel* m_kModelObjectsItem = ((::KFModel *)(reinterpret_cast<::fnv_004471c0::FUN_004471c0_shell *>((g_modelLoader))->LoadKFModel((char *)(pcPath7))));
            reinterpret_cast<::Anim490 *>((this))->AddModel((::Model490 *)(m_kModelObjectsItem), bFlag);
            delete pcPath7;
            apFileList->RemoveHead();
        }
        delete apFileList;
    }
}
// @fnv 0x004972a0
void QueuedAnimStub::LoadQueuedAnim(float afTime, AnimStub* apAnimation)
{
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&iState, 4);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&unk0C, 4);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&unk14, 4);
    unsigned char bHasModel;
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&bHasModel, 1);
    if (bHasModel)
    {
        unsigned char cIndex;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&cIndex, 1);
        if (reinterpret_cast<::Anim490 *>((apAnimation))->AddModel((::Model490 *)(::KFModelStub *)(m_pRenderedNodeEntry), false))
        {
            if (iState == 2)
            {
                SeqBaseStub* pSeqBase;
                if (reinterpret_cast<::NiTMapBase *>((void *)(((::SeqMapStub *)(reinterpret_cast<::FUN_00497280_shell *>((apAnimation))->GetFieldAt124()))))->Lookup(((::AnimGroupStub *)(reinterpret_cast<::TESRegionDataMap *>((static_cast<KFModelStub*>(m_pRenderedNodeEntry)))->GetRegionMapName()))->GetType(),
                                                         (::AnimSequenceBase *&)(pSeqBase)))
                {
                    reinterpret_cast<::FUN_004974a0_shell *>((apAnimation))->FUN_004974a0();
                    pListSequence =
                        apAnimation->FUN_004949a0(pSeqBase->GetSequenceAtIndex(cIndex),
                                                  ((::AnimGroupStub *)(reinterpret_cast<::TESRegionDataMap *>((static_cast<KFModelStub*>(m_pRenderedNodeEntry)))->GetRegionMapName()))->GetType(), unk14);
                }
            }
            else if (iState == 0)
            {
                iState = 1;
            }
            else if (iState == 3)
            {
                SeqBaseStub* pSeqBase2 = 0;
                if (reinterpret_cast<::NiTMapBase *>((void *)(((::SeqMapStub *)(reinterpret_cast<::FUN_00497280_shell *>((apAnimation))->GetFieldAt124()))))->Lookup(((::AnimGroupStub *)(reinterpret_cast<::TESRegionDataMap *>((static_cast<KFModelStub*>(m_pRenderedNodeEntry)))->GetRegionMapName()))->GetType(),
                                                         (::AnimSequenceBase *&)(pSeqBase2)))
                {
                    pListSequence = pSeqBase2->GetSequenceAtIndex(cIndex);
                }
            }
        }
        if (pListSequence)
        {
            reinterpret_cast<::fnv_004efbc0::HY *>((static_cast<GroupSeqStub*>(pListSequence)))->FUN_004efbc0(afTime);
        }
        reinterpret_cast<::FUN_00857bd0 *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_TESSaveLoadGame))))->Init(FUN_004efaa0());
    }
    else if (iState == 0)
    {
        iState = 1;
    }
}
// Adds a model's animation sequence to the manager, queuing it or replacing the current sequence for its group, with warnings on failure.
// @fnv 0x00490500
bool Anim490::AddModel(Model490* model, bool queue)
{
    GroupPtr490 group(((::Group490 *)(reinterpret_cast<::TESRegionDataMap *>((model))->GetRegionMapName())));
    if (!(Group490*)group)
        return false;
    int groupTypeTmp = ((Group490*)group)->GetType();
    unsigned short code = reinterpret_cast<::FUN_0047d3b0_shell *>((((Group490*)group)))->FUN_0047d3b0();
    if (groupTypeTmp == 255)
    {
        if (((::Root490 *)(reinterpret_cast<::StrOwner *>((model))->FUN_007fa950())))
            Warning490(DAT_0101da38, (const char*)(*(::String490 *)(reinterpret_cast<::TESTopicInfoData *>((((::Root490 *)(reinterpret_cast<::StrOwner *>((model))->FUN_007fa950()))))->GetLinkToList())), (const char*)*model);
        return false;
    }
    Context490 memContext(51, true, DAT_0101d930, 794);
    Base490* base = 0;
    if (!reinterpret_cast<::NiTMapBase *>((void *)(map))->Lookup(code, (::AnimSequenceBase *&)(base)))
    {
        base = new Single490;
        reinterpret_cast<::MapBase *>((map))->SetOrInsert(code, (::AnimSequenceBase *)(base));
    }
    if (base->IsSingle() && base->Get(-1))
    {
        if ((*reinterpret_cast<Info490 (*)[]>(&::DAT_011977dc))[groupTypeTmp].multiple)
        {
            reinterpret_cast<::FUN_0049c250_shell *>((map))->FUN_0049c250(code);
            Single490* single = (Single490*)base;
            base = new Multiple490(single);
            reinterpret_cast<::MapBase *>((map))->SetOrInsert(code, (::AnimSequenceBase *)(base));
        }
        else
        {
            if (((::Group490 *)(reinterpret_cast<::BSAnimGroupSequence *>((base->Get(-1)))->GetAnimGroup())) == ((::Group490 *)(reinterpret_cast<::TESRegionDataMap *>((model))->GetRegionMapName())))
                return true;
            bool remove = true;
            if ((Idle490*)idle && ((::Seq490 *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((Idle490*)idle)))->FUN_00490e40())) == base->Get(-1))
                remove = false;
            else if ((Idle490*)queued && ((::Seq490 *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((Idle490*)queued)))->FUN_00490e40())) == base->Get(-1))
                remove = false;
            if (remove)
            {
                if (base->Get(-1) == last)
                    last = 0;
                reinterpret_cast<::CtrlSeqOwner *>((((Manager490*)manager)))->ReleaseObject((::NiRefObject *)(::Seq490 *)(base->Get(-1)));
            }
            Seq490* old = base->Get(-1);
            if (old)
            {
                for (int index = 0; index < 8; index++)
                {
                    if (current[index] == old)
                    {
                        current[index] = 0;
                        groups[index] = 0;
                    }
                }
            }
            if (last && base->Get(-1) == last)
                last = 0;
            base->Set(0, true);
        }
    }
    if (queue && !Menu490(1036, 0) && groupTypeTmp != 23 && groupTypeTmp != 0 && groupTypeTmp != 224)
    {
        ::FUN_0043be10((char *)(model));
        reinterpret_cast<::Callees *>(&(models))->FUN_00905820((void *)&(model));
    }
    else
    {
        Root490* original4 = ((::Root490 *)(reinterpret_cast<::StrOwner *>((model))->FUN_007fa950()));
        if (groupTypeTmp >= 3 && groupTypeTmp <= 16 && ((int)(reinterpret_cast<::ActorMover *>((original4))->GetCurrentMoveModeType())) == 2)
        {
            reinterpret_cast<::FUN_0049c250_shell *>((map))->FUN_0049c250(code);
            delete base;
            return false;
        }
        Seq490* seq = 0;
        bool aCompatible = ::FUN_0043b300((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011c7d74))), (::NiAVObject *)(original4));
        if (aCompatible && ((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((original4))->FUN_00726070())) == 1)
            seq = (Seq490*)original4;
        else
            seq = new Seq490(((::Group490 *)(reinterpret_cast<::TESRegionDataMap *>((model))->GetRegionMapName())), original4);
        base->Set(seq, true);
        bool added = ::AttachSeqToOwner((::Owner *)(((Manager490*)manager)), (std::intptr_t)(seq), (::Seq *)(int *)(&(*reinterpret_cast<int *>(&::DAT_011f49e0))), (int *)(true), {});
        if (!added)
        {
            bool removed = false;
            Warning490(DAT_0101d9a8, (const char*)(*(::String490 *)(reinterpret_cast<::TESTopicInfoData *>((seq))->GetLinkToList())), (const char*)(*(::String490 *)(reinterpret_cast<::TESTopicInfoData *>((((Root490*)root)))->GetLinkToList())));
            ::FUN_0043b2b0(true);
            for (unsigned int target = 0; target < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((seq))->FUN_0084e3a0())); target++)
            {
                char* name = 0;
                reinterpret_cast<::FUN_00a307c0_cls *>((seq))->GetEntryText(target, name);
                if (!((Root490*)root)->Find(String490(name)))
                    Warning490(DAT_0101d970, name);
                delete name;
            }
            ::FUN_0043b2b0(false);
            if (seq)
            {
                if (seq == last)
                    last = 0;
                reinterpret_cast<::CtrlSeqOwner *>((((Manager490*)manager)))->ReleaseObject((::NiRefObject *)(seq));
                removed = base->Remove(seq, true);
            }
            if (base && removed)
            {
                reinterpret_cast<::FUN_0049c250_shell *>((map))->FUN_0049c250(code);
                delete base;
            }
            return false;
        }
        else
        {
            if (!accum)
                accum = ((::Root490 *)(reinterpret_cast<::fnv_00490d90::FUN_00490d90_shell *>((((Manager490*)manager)))->FUN_00490d90()));
            reinterpret_cast<::FUN_004946a0_shell *>(this)->FUN_004946a0((::TESAnimGroup *)(::Group490 *)(((::Group490 *)(reinterpret_cast<::TESRegionDataMap *>((model))->GetRegionMapName()))));
        }
    }
    return true;
}

typedef FNV_NiPoint3_Canonical AnimPoint3;

class IdleReplayDelayEntry
{
  public:
    TESIdleForm* m_pIdleForm;
    float m_fDelay;
};

struct AnimGroupInfoStub
{
    unsigned int GetGroupType();
};

struct InterpStub
{
    void* GetInterpolator(int aiIndex);
};

struct SeqStub : public BSAnimGroupSequence
{
    AnimGroupInfoStub* GetAnimGroup() const;
    void* GetInterpolator(int aiIndex);
};

struct BlendStub
{
};

struct ControllerStub
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
    virtual BlendStub* GetInterpolator(int aiIndex);
};

struct AccumRootStub
{
    const NiFixedString& GetName() const;
};

struct BoneStub
{
    const NiFixedString& GetName() const;
};

struct WeaponStub
{
};

struct ActorStub : public Actor
{
    void SetAnimAction(int aiAction, BSAnimGroupSequence* apSeq);
};

struct IdleStub
{
    void Update(Animation* apAnimation);
};

struct PlayerStub
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
    virtual void v40c();
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
    virtual void QueueReloadGroup(unsigned short asGroup, bool abFlag);
};

struct TimeGlobalStub
{
};
struct IntSettingStub
{
};
class GlobalObject_0044f440
{
  public:
};
class GlobalObjectO2_00a7b610
{
};
struct VATSStub
{
    void* GetTarget();
};
struct TESAnimGroupActionEntry
{
    int iSequenceType;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

bool __cdecl IsVATSCameraActive();

struct FUN_00491180_shell : public Animation
{
    BSAnimGroupSequence* PlayGroupEx(unsigned short asGroup, int aeFlags, int aiLoops, int aeSection);
    void FUN_00491180(TESObjectREFR* apRef, float afDelta, float afTime);
};

class NiTimeController;
struct AnimRoot3D
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void UpdateNode(NiUpdateData&, unsigned int);
    void SetControllers(NiTimeController*);
};
struct GlobalObject2_0040c150
{
};
struct BGSSaveLoadGame
{
};

struct AnimSwap
{
    int unk00;
    int unk04;
    NiPointer<AnimRoot3D> m_pRootNode;
    AnimRoot3D* pOther;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    float fTime;
    void FUN_00493bd0();
};
// Calls UpdateAnimationForRef with apRef, then calls FUN_00493bd0.
// @fnv 0x00493900
void ThisStub::FUN_00493900(void* apRef)
{
    UpdateAnimationForRef(apRef);
    reinterpret_cast<::AnimSwap *>(this)->FUN_00493bd0();
}
// If FUN_00493970 succeeds, calls FUN_00493bd0 and FUN_004939b0(0), then returns true; otherwise returns false.
// @fnv 0x00493930
bool C00493930::FUN_00493930()
{
    if (FUN_00493970())
    {
        reinterpret_cast<::AnimSwap *>(this)->FUN_00493bd0();
        reinterpret_cast<::fnv_004939b0::ST_00493860 *>(this)->FUN_004939b0(0);
        return true;
    }
    return false;
}

// If both animation roots exist, temporarily detaches their controllers, updates the first node with fTime, then restores the controllers.
// @fnv 0x00493bd0
void AnimSwap::FUN_00493bd0()
{
    if (!m_pRootNode || !pOther)
        return;
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject2_0040c150 *>(&::g_011c3ea4)))))) > 1 && !(*reinterpret_cast<char *>(&::DAT_011e07a8)) && !reinterpret_cast<::fnv_00493970::FUN_00493990_shell *>(this)->FUN_00493970() && !reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((g_BGSSaveLoadGame))->FUN_0042ce10())
    {
        reinterpret_cast<::fnv_004939b0::ST_00493860 *>(this)->FUN_004939b0(1);
        return;
    }
    NiUpdateData kUpdate(fTime, true, false);
    NiPointer<NiTimeController> spCtrlA(((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)((m_pRootNode).operator->())))));
    NiPointer<NiTimeController> spCtrlB2(((::NiTimeController *)(::fnv_0043b230::FUN_0043b230((const char *)(pOther)))));
    m_pRootNode->SetControllers(0);
    pOther->SetControllers(0);
    m_pRootNode->UpdateNode(kUpdate, 0);
    m_pRootNode->SetControllers(spCtrlA);
    pOther->SetControllers(spCtrlB2);
}

namespace AnimationBlend {
struct BlendAnimation;
struct BlendSequence;
struct BlendString
{
    const char* FUN_0043b1b0();
};
struct BlendObject
{
};
struct BlendGroup
{
    int FUN_005f2420();
    int GetMoveAnimGroup();
};
struct BlendGroupPtr
{
    BlendGroup* value;
    BlendGroupPtr(BlendGroup*);
    ~BlendGroupPtr();
};
struct BlendNodePtr
{
    BlendObject* value;
};
struct BlendSequence
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
    virtual void Deactivate(float, int);
};
struct BlendProcess
{
};
struct BlendRagdoll
{
};
struct BlendActor
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
    virtual bool IsActor();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    BlendRagdoll* ragdoll;
};
struct BlendManager
{
};
struct BlendManagerPtr
{
    BlendManager* value;
};
struct BlendSettings
{
};
struct BlendGame
{
};
extern BlendGame* DAT_011de45c;
struct BlendMode
{
};
struct BlendMain
{
};
extern const char DAT_0101dc58[], DAT_0101dbe8[], DAT_0101db90[];
struct BlendGroupInfo
{
    int section, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
int FUN_005f2440(unsigned short);
bool FUN_00702680(int, int);
void FUN_005b5e40(const char*, ...);
struct BlendAnimation
{
    int unk00;
    BlendActor* actor;
    BlendNodePtr node;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    unsigned short groups[8];
    int flags[8];
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    BlendManagerPtr manager;
    int unkdc;
    BlendSequence* sequences[16];
    signed char force;
    BlendSequence* FUN_004949a0(BlendSequence*, unsigned short, int);
};
// @fnv 0x004949a0
BlendSequence* BlendAnimation::FUN_004949a0(BlendSequence* apSequence, unsigned short group, int aiRequestedSection)
{
    if (reinterpret_cast<::FUN_00498ea0_wrap *>(this)->impl((::BSAnimGroupSequence *)(apSequence)))
        return 0;
    int type4 = FUN_005f2440(group);
    int section3 = aiRequestedSection;
    BlendActor* owner2 = actor;
    if (section3 == -1)
        section3 = (*reinterpret_cast<AnimationBlend::BlendGroupInfo (*)[]>(&::DAT_011977e0))[type4].section;
    int originalSection = section3;
    switch (section3)
    {
    case 20:
        section3 = 1;
        break;
    case 21:
        section3 = 4;
        break;
    }
    BlendSequence* previous2 = sequences[section3];
    int previousType = FUN_005f2440(groups[section3]);
    bool synchronize = false;
    std::intptr_t state = 0;
    if (previous2)
        state = ((std::intptr_t)(reinterpret_cast<::LowProcess *>((previous2))->GetActiveCombatTarget()));
    if (!apSequence || group == 255)
        return 0;
    if (apSequence)
    {
        if (section3 == 4 || section3 == 5 || section3 == 6)
        {
            if (actor == (*reinterpret_cast<::AnimationBlend::BlendActor * *>(&::_g_thePlayer)) && this == ((::AnimationBlend::BlendAnimation *)(reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::AnimationBlend::BlendActor * *>(&::_g_thePlayer))))->GetAnimation(1))))
            {
                reinterpret_cast<::FUN_00495480_shell *>((apSequence))->FUN_00495480(section3 == 4 ? 1.0f : 0.0f);
            }
            else
            {
                BlendProcess* process = ((::AnimationBlend::BlendProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()));
                bool reset = true;
                if ((::TESAnimGroup::IsAimAnimation((unsigned short)type4) || ::TESAnimGroup::IsActionTypeValid((unsigned short)type4)) && process &&
                    ((int)(std::uintptr_t)(reinterpret_cast<::FUN_0045cd60_shell *>((process))->FUN_0045cd60())) <= 1)
                {
                    BlendProcess* highProcess = process;
                    BlendSequence* priorA = ((::AnimationBlend::BlendSequence *)(reinterpret_cast<::FUN_00495560_shell *>((highProcess))->GetFieldAt(section3 - 4)));
                    if (priorA)
                    {
                        reinterpret_cast<::FUN_00495480_shell *>((apSequence))->FUN_00495480(::GetFloatAtOffset1C((char *)(priorA)));
                        reset = false;
                    }
                }
                if (reset && (section3 == 5 || section3 == 6))
                    reinterpret_cast<::FUN_00495480_shell *>((apSequence))->FUN_00495480(0.0f);
            }
        }
        if (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((apSequence))->GetActiveCombatTarget())) == 3)
            apSequence->Deactivate(0.0f, 0);
        if (((((std::intptr_t)(reinterpret_cast<::LowProcess *>((apSequence))->GetActiveCombatTarget())) != 0 && !((void *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((apSequence))->GetCurrentMoveModeType()))) ||
             (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((apSequence))->GetActiveCombatTarget())) == 1 && apSequence == previous2)) &&
            (!::FUN_00702360() || ((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((apSequence))->GetActiveCombatTarget())) == 1))
        {
            flags[section3] = 0;
            ::SetNegatedGlobal((void *)(apSequence));
            return apSequence;
        }
        if (::FUN_00702360() && ((::AnimationBlend::BlendObject *)(::FUN_00559450((int *)&(node)))) == ((::AnimationBlend::BlendObject *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::AnimationBlend::BlendActor * *>(&::_g_thePlayer))))->FUN_00950bb0(0))) && !reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::AnimationBlend::BlendGame * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() &&
            !((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::AnimationBlend::BlendMode *>(&::g_011f2250))))->GetName())))
        {
        }
        else if (::fnv_00705a00::FUN_00705a00() && ((::AnimationBlend::BlendObject *)(::FUN_00559450((int *)&(node)))) == ((::AnimationBlend::BlendObject *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::AnimationBlend::BlendActor * *>(&::_g_thePlayer))))->FUN_00950bb0(1))) && type4 == 1 &&
                 aiRequestedSection == 0 && previous2)
        {
            reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(originalSection, 0.0f);
            previous2 = 0;
            force = 1;
        }
        else if (previous2 && section3 == 2)
        {
            int priorType = ((::AnimationBlend::BlendGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((previous2))->GetAnimGroup()))->FUN_005f2420();
            if (type4 == 226 || (type4 == 240 && priorType >= 230 && priorType <= 235))
            {
                reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(originalSection, 0.0f);
                previous2 = 0;
            }
        }
        else if (state && previous2)
        {
            if (state != 1)
            {
                if (actor != (*reinterpret_cast<::AnimationBlend::BlendActor * *>(&::_g_thePlayer)) && section3 == 1)
                    return 0;
                reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(originalSection, 0.0f);
                previous2 = 0;
            }
            else if (originalSection != section3 || force || ((std::intptr_t)(reinterpret_cast<::LowProcess *>((apSequence))->GetActiveCombatTarget())) != 0)
            {
                reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(originalSection, 0.0f);
            }
            else if (originalSection == 4 && (type4 <= 25 || type4 > 212) && !::TESAnimGroup::IsAimAnimation((unsigned short)type4))
            {
                reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(5, 0.0f);
                reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(6, 0.0f);
            }
        }
        groups[section3] = group;
        sequences[section3] = apSequence;
        if ((!::FUN_00702360() || ((::AnimationBlend::BlendObject *)(::FUN_00559450((int *)&(node)))) != ((::AnimationBlend::BlendObject *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::AnimationBlend::BlendActor * *>(&::_g_thePlayer))))->FUN_00950bb0(0)))) && apSequence && previous2)
        {
            BlendGroupPtr newGroup3(((::AnimationBlend::BlendGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((apSequence))->GetAnimGroup())));
            BlendGroupPtr oldGroup(((::AnimationBlend::BlendGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((previous2))->GetAnimGroup())));
            if (((signed char)(reinterpret_cast<::FOPipboyManager *>((((::AnimationBlend::BlendGroup *)(::FUN_00559450((int *)&(oldGroup))))))->IsUnk28Set())) &&
                ((signed char)(reinterpret_cast<::FOPipboyManager *>((((::AnimationBlend::BlendGroup *)(::FUN_00559450((int *)&(oldGroup))))))->IsUnk28Set())) == ((signed char)(reinterpret_cast<::FOPipboyManager *>((((::AnimationBlend::BlendGroup *)(::FUN_00559450((int *)&(newGroup3))))))->IsUnk28Set())))
            {
                if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((previous2))->FUN_0084e3a0())) == ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apSequence))->FUN_0084e3a0())))
                {
                    if (reinterpret_cast<::FUN_00a30c80_shell *>((apSequence))->FUN_00a30c80(previous2))
                        synchronize = true;
                    else
                        FUN_005b5e40(DAT_0101dc58, ((::AnimationBlend::BlendString *)(reinterpret_cast<::TESTopicInfoData *>((previous2))->GetLinkToList()))->FUN_0043b1b0(),
                                     ((::AnimationBlend::BlendString *)(reinterpret_cast<::TESTopicInfoData *>((apSequence))->GetLinkToList()))->FUN_0043b1b0(),
                                     ((::AnimationBlend::BlendString *)(reinterpret_cast<::TESTopicInfoData *>((((::AnimationBlend::BlendObject *)(::FUN_00559450((int *)&(node))))))->GetLinkToList()))->FUN_0043b1b0());
                }
                else
                    FUN_005b5e40(DAT_0101dbe8, ((::AnimationBlend::BlendString *)(reinterpret_cast<::TESTopicInfoData *>((previous2))->GetLinkToList()))->FUN_0043b1b0(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((previous2))->FUN_0084e3a0())),
                                 ((::AnimationBlend::BlendString *)(reinterpret_cast<::TESTopicInfoData *>((apSequence))->GetLinkToList()))->FUN_0043b1b0(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apSequence))->FUN_0084e3a0())),
                                 ((::AnimationBlend::BlendString *)(reinterpret_cast<::TESTopicInfoData *>((((::AnimationBlend::BlendObject *)(::FUN_00559450((int *)&(node))))))->GetLinkToList()))->FUN_0043b1b0());
            }
            if (synchronize && apSequence == previous2)
            {
                FUN_005b5e40(DAT_0101db90, ((::AnimationBlend::BlendString *)(reinterpret_cast<::TESTopicInfoData *>((previous2))->GetLinkToList()))->FUN_0043b1b0(),
                             ((::AnimationBlend::BlendString *)(reinterpret_cast<::TESTopicInfoData *>((((::AnimationBlend::BlendObject *)(::FUN_00559450((int *)&(node))))))->GetLinkToList()))->FUN_0043b1b0());
                synchronize = false;
            }
        }
        float duration = *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AnimationBlend::BlendSettings *>(&::g_011c56fc))))));
        unsigned char priority = 0;
        if (previous2)
            priority = ::GetMaxByte((unsigned char *)(((::AnimationBlend::BlendGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((previous2))->GetAnimGroup()))));
        if (::GetMaxOfTwoBytes((unsigned char *)(((::AnimationBlend::BlendGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((apSequence))->GetAnimGroup())))) > priority)
            priority = ::GetMaxOfTwoBytes((unsigned char *)(((::AnimationBlend::BlendGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((apSequence))->GetAnimGroup()))));
        if (priority)
            duration = priority / ::DAT_0101db88;
        if ((::FUN_00702360() && reinterpret_cast<::_FUN_00822510_Class *>(&(node))->operator==((std::intptr_t)(((::AnimationBlend::BlendObject *)(::fnv_00490f80::FUN_00490f80((char *)((*reinterpret_cast<::AnimationBlend::BlendActor * *>(&::_g_thePlayer))))))))) || FUN_00702680(1036, 0))
            duration = *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AnimationBlend::BlendSettings *>(&::g_011c5740))))));
        if (type4 >= 177 && type4 <= 199 && previous2 && owner2 != (*reinterpret_cast<::AnimationBlend::BlendActor * *>(&::_g_thePlayer)) && duration < ::DAT_01011588)
        {
            switch (((::AnimationBlend::BlendGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((apSequence))->GetAnimGroup()))->GetMoveAnimGroup())
            {
            case 1:
                if (((::AnimationBlend::BlendGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((previous2))->GetAnimGroup()))->GetMoveAnimGroup() != 1)
                    duration = ::fnv_00c88020::DAT_01016248;
                break;
            default:
                if (((::AnimationBlend::BlendGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((previous2))->GetAnimGroup()))->GetMoveAnimGroup() == 1)
                    duration = ::fnv_00c88020::DAT_01016248;
                break;
            }
        }
        if (::TESAnimGroup::IsActionTypeValid((unsigned short)previousType) && type4 >= 173 && type4 <= 199 && owner2 == (*reinterpret_cast<::AnimationBlend::BlendActor * *>(&::_g_thePlayer)))
            duration = 0.0f;
        if (force)
            duration = 0.0f;
        duration /= *((const float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AnimationBlend::BlendSettings *>(&::g_011c5724))))));
        reinterpret_cast<::fnv_00a328b0::SeqExt *>((apSequence))->FUN_00a328b0(0.0f, 0);
        if (!previous2 && (section3 == 5 || section3 == 6))
            reinterpret_cast<::NiControllerManager *>((((::AnimationBlend::BlendManager *)(::FUN_00559450((int *)&(manager))))))->ActivateControllerSequence((::NiControllerSequence *)(apSequence), 0, 1, ::GetFloatAtOffset1C((char *)(apSequence)), duration, (::NiControllerSequence *)(0));
        else if (duration < ::DAT_01016408)
            reinterpret_cast<::NiControllerManager *>((((::AnimationBlend::BlendManager *)(::FUN_00559450((int *)&(manager))))))->ActivateControllerSequence((::NiControllerSequence *)(apSequence), 0, 1, ::GetFloatAtOffset1C((char *)(apSequence)), 0.0f, (::NiControllerSequence *)(0));
        else if (synchronize)
            ::CallFUN_00a351d0((::FUN_00a351d0_cls *)(previous2), (std::intptr_t)(apSequence), duration, 0,
                                                         ::GetFloatAtOffset1C((char *)(previous2)), ::GetFloatAtOffset1C((char *)(apSequence)));
        else
        {
            bool blended = false;
            if (previous2 && ((std::intptr_t)(reinterpret_cast<::LowProcess *>((previous2))->GetActiveCombatTarget())))
                blended = ::sa2e280::FUN_00a2e280((::sa2e280::Sequence *)(previous2), (::sa2e280::Sequence *)(apSequence), duration, 0, 1,
                                                ::GetFloatAtOffset1C((char *)(apSequence)), 0);
            if (!blended)
            {
                if (reinterpret_cast<::fnv_00451530::FUN_00451530_shell *>(((*reinterpret_cast<::AnimationBlend::BlendMain * *>(&::g_TES))))->FUN_00451530())
                    reinterpret_cast<::NiControllerManager *>((((::AnimationBlend::BlendManager *)(::FUN_00559450((int *)&(manager))))))->ActivateControllerSequence((::NiControllerSequence *)(apSequence), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
                else
                {
                    if (actor && actor->IsActor())
                    {
                        BlendActor* blendActor = actor;
                        if (((bool)(::FUN_00495580())) && blendActor->ragdoll && ::FUN_004955a0((::bhkRagdollController *)(blendActor->ragdoll)))
                            reinterpret_cast<::FUN_00c75b40_cls *>((blendActor->ragdoll))->UpdateBoneLocalTransforms();
                    }
                    ::FUN_00a2f800((::NiControllerSequence *)(apSequence), 0.0f, duration, 0, 0);
                }
            }
        }
        if (previous2 && previous2 != apSequence)
        {
            switch (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((previous2))->GetActiveCombatTarget())))
            {
            case 1:
            case 2:
            case 5:
                reinterpret_cast<::NiControllerManager *>((((::AnimationBlend::BlendManager *)(::FUN_00559450((int *)&(manager))))))->StopSequence((::NiControllerSequence *)(previous2), 0.0f);
                break;
            }
        }
    }
    flags[section3] = 0;
    return apSequence;
}

}

// GetSequenceForKey : Animation::GetSequenceForKey(BSAnimGroupSequence*, unsigned short)
//
// The original (149 bytes, unoptimised build) is:
//
//   push ebp / mov ebp,esp / sub esp,0x10
//   mov [ebp-0x10],ecx            <- the "this" home
//   movzx eax,word [ebp+0xc]      <- the unsigned short argument
//   cmp eax,0xff / je <ret0>      <- the "||" short circuit: the invalid key
//   lea ecx,[ebp-8] / push ecx    <- &out of the map lookup
//   movzx edx,word [ebp+0xc] / push edx
//   mov eax,[ebp-0x10] / mov ecx,[eax+0xdc] / call GetAt
//   ...
//
// so the class member at +0xdc is the animation-sequence map and the map's
// value is the sequence object the following virtual call is made on.
//
// The two early exits (the invalid key and the failed map lookup) share ONE
// "return 0" block in the original; the short-circuit "||" of the two tests
// is what makes cl 15.00.30729.01 emit that single block.

struct FNV_SeqMapStandIn
{
    bool GetAt(unsigned short key, SeqIface*& result) const;
};

struct FNV_AnimationOwner : public Animation
{
    BSAnimGroupSequence* GetSequenceForKey(BSAnimGroupSequence* pSequence, unsigned short usKey);
};

// @fnv 0x00495da0
BSAnimGroupSequence* FNV_AnimationOwner::GetSequenceForKey(BSAnimGroupSequence* pSequence, unsigned short usKey)
{
    SeqIface* pFound;
    if (usKey == 0xff || !reinterpret_cast<::NiTMapBase *>((void *)(((FNV_SeqMapStandIn*)m_pOwnerReference)))->Lookup(usKey, (::AnimSequenceBase *&)(pFound)))
        return 0;

    SeqIface* _pUse = 0;
    if (!pFound->IsSingleSeq())
        _pUse = pFound;

    if (!_pUse)
        return 0;

    SeqIface* pSeqObj = ((::SeqIface *)(reinterpret_cast<::BNLookup *>((_pUse))->FindObjectByNameVariant((::BNObject *)(pSequence), -1)));
    if (!pSeqObj)
        return 0;

    return (BSAnimGroupSequence*)((::SeqIface *)(reinterpret_cast<::AnimationBlend::BlendAnimation *>((((FUN_004948c0_shell*)this)))->FUN_004949a0((::AnimationBlend::BlendSequence *)(pSeqObj), usKey, -1)));
}

struct SequenceRef
{
    signed char* FUN_0043b1b0();
};
struct TrackEntry
{
    void* controller;
    void* interpolationData;
    SequenceRef* FUN_00717e50();
};
struct SequenceInterface : BSAnimGroupSequence
{
    FUN_00495f30_shell* FUN_00700300();
};

struct AnimationInterface : Animation
{
    char FUN_00495f50(int sequenceIndex, int actionId, float* outTime);
};
// @fnv 0x00495f50
char AnimationInterface::FUN_00495f50(int sequenceIndex, int actionId, float* outTime)
{
    if (outTime != 0)
        *outTime = 0.0f;

    if (m_pChildTile[sequenceIndex] == 0 || actionId == 0)
        return 0;

    int entries;
    float tracks = reinterpret_cast<::TESObjectREFR *>((static_cast<SequenceInterface*>(m_pChildTile[sequenceIndex])))->GetScale();
    FUN_00495f30_shell* sequenceTime = static_cast<SequenceInterface*>(m_pChildTile[sequenceIndex])->FUN_00700300();
    TrackEntry* key = reinterpret_cast<TrackEntry*>(sequenceTime->FUN_00495f30(&entries));
    unsigned int trackCount = ::FUN_0044a670((const char *)(std::uintptr_t)(actionId));
    if (!trackCount)
        return 0;

    for (unsigned int i = 0; i < static_cast<unsigned int>(entries); ++i)
    {
        signed char* object = key[i].FUN_00717e50()->FUN_0043b1b0();
        if (object != 0 && fnv::crt::strnicmp((const char *)(object), (const char *)(std::uintptr_t)(actionId), trackCount) == 0 && tracks <= reinterpret_cast<::CombatTargetTimestamp *>(&(key[i]))->FUN_006a7f50())
        {
            if (outTime != 0)
                *outTime = reinterpret_cast<::CombatTargetTimestamp *>(&(key[i]))->FUN_006a7f50();
            return std::tolower(object[trackCount]);
        }
    }
    return 0;
}

class IdleAnimGroupAccess498
{
  public:
    unsigned int FUN_005f2420();
};
class TESIdleForm
{
  public:
};
class IdleReplayDelayAccess498
{
  public:
    TESIdleForm* idle;
    float delay;
};
class IdleModelAccess : public KFModel
{
  public:
};
class AnimIdleAccess : public AnimIdle
{
  public:
};
class AnimationAccess : public Animation
{
  public:
    bool FUN_00498290();
};
// @fnv 0x00497f20
void FUN_00497f20_shell::FUN_00497f20(TESIdleForm* apIdleForm, Actor* apActor, int aeSection, int aeType)
{
    AutoMemContext tempMemContext((MEM_CONTEXT)0x33, true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 0x129d);
    int etype = aeType;
    switch (aeSection)
    {
    case 0:
    case 1:
    case 0x14:
        etype = 3;
        break;
    }
    *(NiPointer<NiNode>*)((char*)this + 0x128) =
        (NiNode*)new AnimIdleStub(apIdleForm, aeSection, etype, apActor, 0, this);
    ((VTable0x390*)((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((((TES*)apActor)))->GetBaseTexture())))->v390(apIdleForm);
    reinterpret_cast<::AnimationAccess *>((this))->FUN_00498290();
}

struct IdleLogName
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
    virtual const char* Name();
};
struct IdleLogDword
{
    unsigned char b0, b1, b2, b3;
};
struct IdleLog
{
    unsigned int id;
    unsigned char kind;
    IdleLogDword flags;
    unsigned char index;
};
struct IdleStream
{
};
struct FUN_004965d0 : NiMemObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    FUN_004965d0(TESIdleForm*, int, int, Actor*, int, Animation*);
};
typedef struct FUN_004965d0 IdleLoadTask;
extern void __cdecl FUN_005b5e40(const char*, ...);
extern const char DAT_0101dcec[];
// Reads an idle block from the stream, creates an IdleLoadTask for the matching TESIdleForm and logs block-size mismatches.
// @fnv 0x004977e0
IdleLoadTask* __cdecl LoadIdleAnimation(Actor* actor, Animation* animation, float time)
{
    AutoMemContext context4((MEM_CONTEXT)51, true, DAT_0101d930, 0x1218);
    IdleLoadTask* result2 = 0;
    unsigned short blockSize4 = 0;
    unsigned int start = 0;
    if (reinterpret_cast<::FUN_00862110_cls *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned int magic;
        reinterpret_cast<::FUN_008579e0_shell *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&magic, 4);
        if (magic != 0x424c4f4b)
        {
            IdleLog* log = ((::IdleLog *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))));
            if (log)
            {
                IdleLogName* name = (IdleLogName*)FUN_004839c0(log->id);
                FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_01015718)), DAT_0101d930, 0x121c, log->id, name->Name(), log->index,
                             *(unsigned int*)&log->flags);
            }
            else
                FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_010156a8)), DAT_0101d930, 0x121c, ((bool)(reinterpret_cast<::FUN_008df040_shell *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008df040())));
        }
        start = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579e0_shell *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&blockSize4, 2);
    }
    unsigned int id4;
    bool present4 = reinterpret_cast<::FUN_00857aa0 *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->ValidateFormIDArray((unsigned int *)(void *)(&id4), 4);
    if (id4 || present4)
    {
        unsigned short size;
        reinterpret_cast<::FUN_008579e0_shell *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0(&size, 2);
        TESIdleForm* idle = 0;
        if (id4)
            idle = dynamic_cast<TESIdleForm*>(FUN_004839c0(id4));
        if (idle)
        {
            result2 = new IdleLoadTask(idle, 7, 1, actor, 1, 0);
            reinterpret_cast<::QueuedAnimStub *>((result2))->LoadQueuedAnim(time, (::AnimStub *)(animation));
        }
        else
        {
            FUN_005b5e40(DAT_0101dcec, id4, ((IdleLogName*)actor)->Name());
            reinterpret_cast<::FUN_00857bd0 *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->Init(size);
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned int position = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        IdleLog* logEndA = ((::IdleLog *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))));
        if (logEndA)
        {
            IdleLogName* nameEnd = (IdleLogName*)FUN_004839c0(logEndA->id);
            if (position > start + blockSize4)
                FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_01015588)), position - (start + blockSize4), DAT_0101d930, 0x1237, logEndA->id,
                             nameEnd->Name(), logEndA->index, *(unsigned int*)&logEndA->flags);
            else if (position < start + blockSize4)
                FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_01015500)), start + blockSize4 - position, DAT_0101d930, 0x1237, logEndA->id,
                             nameEnd->Name(), logEndA->index, *(unsigned int*)&logEndA->flags);
        }
        else
        {
            if (position > start + blockSize4)
                FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_010154a0)), position - (start + blockSize4), DAT_0101d930, 0x1237,
                             ((bool)(reinterpret_cast<::FUN_008df040_shell *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008df040())));
            else if (position < start + blockSize4)
                FUN_005b5e40((*reinterpret_cast<const char (*)[]>(&::fnv_008d0bc0::DAT_01015440)), start + blockSize4 - position, DAT_0101d930, 0x1237,
                             ((bool)(reinterpret_cast<::FUN_008df040_shell *>((((IdleStream*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008df040())));
        }
    }
    return result2;
}

extern "C" const char DAT_0101dd28[];

struct FUN_00497ca0_shell : public Animation
{
    void FUN_00497ca0(TESIdleForm*, int);
};

namespace fnv_00498030 {
struct BGSSaveLoadGame
{
};
struct AnimationFinish
{
};
struct WorkerAnimation : Animation
{
    void FUN_00498030(TESIdleForm*, Actor*, int);
};
// @fnv 0x00498030
void WorkerAnimation::FUN_00498030(TESIdleForm* idle, Actor* actor, int section)
{
    AutoMemContext h(MEM_CONTEXT_MEM_CONTEXT_ANIMATION, true,
                     "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 4797);
    Animation* p = this;
    if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00498030::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
    {
        LocalStateValue = (AnimIdle*)new AnimIdleStub(idle, section, 0, actor, 0, this);
    }
    else
    {
        LocalStateValue = (AnimIdle*)new AnimIdleStub(idle, section, 0, actor, 1, 0);
    }
    reinterpret_cast<::fnv_00498170::FUN_00498170_shell *>((((AnimationFinish*)p)))->FUN_00498170();
}
}  // namespace fnv_00498030

namespace fnv_00499080 {
struct FUN_00499080_shell : public Animation
{
    void FUN_00499080();
};

struct ControllerManagerSequences
{
};

// @fnv 0x00499080
void FUN_00499080_shell::FUN_00499080()
{
    if (!m_acReservedBytes)
        return;
    unsigned int sequenceCount = reinterpret_cast<::fnv_00495d00::FUN_00495d00_shell *>(((NiControllerManager*)m_acReservedBytes))->FUN_00495d00();

    for (unsigned int index = 0; index < sequenceCount; ++index)
    {
        NiControllerSequence* sequence =
            reinterpret_cast<::fnv_00495d20::FUN_00495d20_shell *>((((ControllerManagerSequences*)(NiControllerManager*)m_acReservedBytes)))->FUN_00495d20(index);
        NiObject* matchingObject = FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011c7d74)), (NiObject*)sequence);
        if (matchingObject)
        {
            reinterpret_cast<::FUN_004efa50_Holder *>((matchingObject))->ClearItemField2();
        }
    }
    while (((FUN_00493830_shell*)this)->FUN_00493830())
    {
        KFModel* model = (kfModelList.m_item);
        FinishScriptRunLockIfActive(model);
        FinishScriptRunLockIfActive(model);
        kfModelList.RemoveHead();
    }
}
}  // namespace fnv_00499080

struct S_00499160_Node;
struct S_00499160_Ctl
{
};
struct S_00499160_Mgr
{
    virtual void vfn_00();
    virtual void vfn_04();
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
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8(int a, int b);
};
struct S_00499160_Seq
{
};
struct S_00499160_Obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual S_00499160_Node* vfn_0c();
};
struct S_00499160_Node
{
    unsigned int FUN_0043b480();
};

// @fnv 0x00499160
void __cdecl FUN_00499160(S_00499160_Obj* obj)
{
    if (!obj)
        return;
    S_00499160_Ctl* c = ((::S_00499160_Ctl *)(::fnv_0043b230::FUN_0043b230((const char *)(obj))));
    while (c)
    {
        S_00499160_Mgr* m = (S_00499160_Mgr*)FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f3714)), (NiObject*)c);
        if (m)
        {
            m->vfn_c8(0, 0);
        }
        else
        {
            S_00499160_Seq* s = (S_00499160_Seq*)FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36bc)), (NiObject*)c);
            if (s)
                reinterpret_cast<::FUN_00a30160_cls *>((s))->FUN_00a30160();
        }
        c = ((::S_00499160_Ctl *)(::fnv_004a8a90::FUN_004a8a90((char *)(c))));
    }
    S_00499160_Node* node = obj->vfn_0c();
    if (node)
    {
        for (unsigned int i = 0; i < node->FUN_0043b480(); i++)
        {
            S_00499160_Obj* child = ((::S_00499160_Obj *)(reinterpret_cast<::NiNode *>((node))->GetAt(i)));
            FUN_00499160(child);
        }
    }
}

struct ResetRoot
{
};
struct ResetSequence
{
    NiFixedStr& GetName();
};
struct ResetPalette
{
    void Clear();
};
struct ResetManager
{
};
template <class T> struct ResetPointer
{
    T* value;
    operator T*() const;
};
struct ResetAnimation
{
    int unk00;
    int unk04;
    ResetPointer<ResetRoot> root;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    ResetPointer<ResetManager> manager;
    int unkdc;
    void* currentSequences[8];
    void FUN_00499240(bool attach);
};
// @fnv 0x00499240
void ResetAnimation::FUN_00499240(bool attach)
{
    if (!(ResetManager*)manager)
        return;
    void* paletteVal = ((void *)(::fnv_00537bd0::GetStringAtOffset((const char *)(((ResetManager*)manager)))));
    if (paletteVal)
    {
        ResetPalette* castPalette3 = ((::ResetPalette *)(::FUN_00653270((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f4a04))), (::NiObject *)(paletteVal))));
        if (castPalette3)
            reinterpret_cast<::FUN_00a6e960_shell *>((castPalette3))->FUN_00a6e960();
    }
    void* controller5 = ((void *)(reinterpret_cast<::MyHost *>((((ResetRoot*)root)))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f36bc))))));
    void* otherController = ((void *)(reinterpret_cast<::MyHost *>((((ResetRoot*)root)))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f36e4))))));
    if (controller5)
        reinterpret_cast<::ControllerOwner *>((((ResetRoot*)root)))->FUN_00a5c480((::NiTimeController *)(controller5));
    if (otherController)
        reinterpret_cast<::ControllerOwner *>((((ResetRoot*)root)))->FUN_00a5c480((::NiTimeController *)(otherController));
    reinterpret_cast<::NiControllerManager *>((((ResetManager*)manager)))->DeactivateAllSequences(0.0f);
    unsigned int priority2 = 0;
    for (unsigned int first4 = 0; first4 < reinterpret_cast<::fnv_00495d00::FUN_00495d00_shell *>((((ResetManager*)manager)))->FUN_00495d00(); ++first4)
    {
        ResetSequence* seqFirst4 = ((::ResetSequence *)(reinterpret_cast<::fnv_00495d20::FUN_00495d20_shell *>((((ResetManager*)manager)))->FUN_00495d20(first4)));
        if (seqFirst4 && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((seqFirst4))->FUN_0084e3a0())) > priority2)
            priority2 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((seqFirst4))->FUN_0084e3a0()));
    }
    for (unsigned int second7 = 0; second7 < reinterpret_cast<::fnv_00495d00::FUN_00495d00_shell *>((((ResetManager*)manager)))->FUN_00495d00(); ++second7)
    {
        ResetSequence* seqSecond3 = ((::ResetSequence *)(reinterpret_cast<::fnv_00495d20::FUN_00495d20_shell *>((((ResetManager*)manager)))->FUN_00495d20(second7)));
        if (seqSecond3)
        {
            if (attach)
            {
                if (!((void *)(reinterpret_cast<::MyHost *>((((ResetRoot*)root)))->FUN_00a5c570((const ::MyRTTI *)(const void *)(&(*reinterpret_cast<int *>(&::g_011f36bc)))))) && priority2)
                    reinterpret_cast<::TargetClass *>((seqSecond3))->FUN_004eedd0((std::intptr_t)((ResetRoot*)root), priority2);
                if (*(const unsigned short*)(const char*)(*(::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((seqSecond3))->GetLinkToList())) != 0x5f5f)
                    reinterpret_cast<::BindSequence *>((seqSecond3))->FUN_00a32c70((bool)((ResetRoot*)root));
            }
            else
            {
                reinterpret_cast<::S004eee_Owner *>((seqSecond3))->UpdateEntryStates();
                reinterpret_cast<::TargetClass *>((seqSecond3))->FUN_004eedd0((std::intptr_t)((ResetRoot*)root), priority2);
            }
        }
    }
    for (int section = 0; section < 8; ++section)
    {
        if (currentSequences[section])
            reinterpret_cast<::NiControllerManager *>((((ResetManager*)manager)))->ActivateControllerSequence((::NiControllerSequence *)(currentSequences[section]), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
    }
}

namespace fnv_004994f0 {
struct FUN_004994f0_shell : Animation
{
    void FUN_004994f0(int section, bool restoreAction);
};
struct BlendActor : Actor
{
};
struct BlendGroup : TESAnimGroup
{
    int GetMoveAnimGroup();
};
extern "C" TESDataHandler* DAT_011c3f2c;
// @fnv 0x004994f0
void FUN_004994f0_shell::FUN_004994f0(int section, bool restoreAction)
{
    int kIndex = section;
    switch (section)
    {
    case 20:
        kIndex = 1;
        break;
    case 21:
        kIndex = 4;
        break;
    }
    BlendActor* actor = static_cast<BlendActor*>(m_pAttachedReference);
    if (kIndex == 1)
        m_kNodeTranslation = ::NiPoint3::ZERO;
    BSAnimGroupSequence* sequence_ = m_pChildTile[kIndex];
    float timeTmp = 0.0f;
    if (sequence_ && !m_cSkipNextBlend)
    {
        timeTmp = *((float *)&(::FUN_00403e20((float *)(void *)(&(*reinterpret_cast<int *>(&::g_011c56fc))))));
        char frames = GetMaxByte(reinterpret_cast<unsigned char*>(reinterpret_cast<::BSAnimGroupSequence *>((void *)(sequence_))->GetAnimGroup()));
        if (frames)
            timeTmp = frames / 30.0;
        timeTmp /= *((float *)&(::FUN_00403e20((float *)(void *)(&(*reinterpret_cast<int *>(&::g_011c5724))))));
    }
    bool allowed = true;
    bool _overrideFlag = false;
    bool aChanged = false;
    if (m_pAttachedReference && (kIndex == 4 || section == 20) && reinterpret_cast<::FUN_008a16d0_shell *>((actor))->FUN_008a16d0() && !reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004226e0())
    {
        if (restoreAction && reinterpret_cast<::FUN_008a7570_shell *>((actor))->FUN_008a7570() == 2 && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetActorProcessTime())
            _overrideFlag = true;
        else
            aChanged = true;
        if (kIndex == 4)
        {
            allowed = false;
            if ((reinterpret_cast<::FUN_008a7570_shell *>((actor))->FUN_008a7570() == 9 || reinterpret_cast<::FUN_008a7570_shell *>((actor))->FUN_008a7570() == 17) && actor != (*reinterpret_cast<::Actor * *>(&::_g_thePlayer)) && timeTmp < 0.5)
            {
                switch (static_cast<BlendGroup*>(reinterpret_cast<::BSAnimGroupSequence *>((void *)(sequence_))->GetAnimGroup())->GetMoveAnimGroup())
                {
                case 1:
                    if (!reinterpret_cast<::Actor *>((actor))->IsSneaking())
                        timeTmp = 0.5f;
                    break;
                default:
                    if (reinterpret_cast<::Actor *>((actor))->IsSneaking())
                        timeTmp = 0.5f;
                    break;
                }
            }
            reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(5, timeTmp);
            reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(6, timeTmp);
        }
    }
    if (allowed)
        reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(section, timeTmp);
    if (_overrideFlag)
    {
        ANIM_GROUP_ENUM group =
            reinterpret_cast<::TESAnimGroup *>((void *)(static_cast<BlendGroup*>(reinterpret_cast<::BSAnimGroupSequence *>((void *)(((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetActorProcessTime()))->GetAnimGroup())))->GetType();
        if (::FUN_005f2750((*(int *)&(group))))
            group = static_cast<ANIM_GROUP_ENUM>(group - 3);
        reinterpret_cast<::fnv_008b28c0::This8b *>((actor))->PlayAnimationSequence(group, (::fnv_008b28c0::Anim8b *)(::Animation *)(this));
    }
    else if (aChanged)
    {
        reinterpret_cast<::fnv_008b28c0::This8b *>((actor))->PlayAnimationSequence(17, (::fnv_008b28c0::Anim8b *)(::Animation *)(this));
    }
}
}  // namespace fnv_004994f0

struct SequenceSize : BSAnimGroupSequence
{
};
struct SaveVersion : ActiveManager
{
};
struct CasterView
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
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
    virtual int IsSpecial();
};
struct ActorView : MobileObject
{
    CasterView caster;
};
struct SceneObject;
struct SceneResult
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual SceneObject* GetNode();
};
struct ManagerView
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
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
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual SceneResult* Find(NiFixedString*);
};
struct ControllerView
{
};
struct AnimationView : Animation
{
};
struct SceneProperty
{
};
struct SceneObject
{
    SceneProperty* FUN_0045bc00(unsigned int);
};
struct SequenceController : NiObject
{
};
struct MessageRecord
{
    int id;
    unsigned char kind;
    unsigned char parameter[4];
};
// Accumulates the serialized byte size of the animation, including group sequences, idle data, and an optional scene sequence, and logs the total when enabled.
// @fnv 0x004997f0
unsigned short FakeAnim::GetSerializedSize(void* apRef)
{
    unsigned short p = 0;
    unsigned short i = p;
    if (((unsigned char)(reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame))))->FUN_00862110())))
    {
        p += 4;
        p += 2;
    }
    p += 4;
    p += 4;
    p += 12;
    p += 4;
    p += 1;
    p += 1;
    char h;
    for (h = 0; h < 8; ++h)
    {
        if (((Animation*)this)->group[h] != 255 && ((Animation*)this)->group[h] != 65535)
        {
            p += 2;
            p += 4;
            p += 4;
            p += 2;
            p += 4;
            p += 1;
            if (((Animation*)this)->m_pChildTile[h])
                p += reinterpret_cast<::FUN_004efb10_shell *>((((SequenceSize*)((Animation*)this)->m_pChildTile[h])))->FUN_004efb10();
        }
    }
    Actor* a = 0;
    if (apRef && ((TESObjectREFR*)apRef)->IsActor())
        a = (Actor*)apRef;
    if ((AnimIdle*)((Animation*)this)->LocalStateValue)
        p += GetMessageSize(a, (ParameterObject*)(AnimIdle*)((Animation*)this)->LocalStateValue);
    else
        p += GetMessageSize(a, (ParameterObject*)(AnimIdle*)((Animation*)this)->LocalInput);
    p += 1;
    if (reinterpret_cast<::FUN_008df040_shell *>((((SaveVersion*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008df040() >= 64)
        p += 1;
    if (((ActorView*)a)->caster.IsSpecial())
    {
        SceneResult* result = ((::ManagerView *)(::fnv_00537bd0::GetStringAtOffset((const char *)(((::ControllerView *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((((AnimationView*)this)))->FUN_00496940()))))))->Find(FUN_00499b70());
        if (result)
        {
            SceneObject* node = result->GetNode();
            if (node)
            {
                SceneProperty* pSceneProperty = ((::SceneProperty *)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0)));
                if (pSceneProperty)
                {
                    NiObject* object = ((::NiObject *)(::fnv_0043b230::FUN_0043b230((const char *)(pSceneProperty))));
                    SequenceController* controller = (SequenceController*)FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), object);
                    if (controller)
                    {
                        SequenceSize* sequence = ((::SequenceSize *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((controller))->FUN_0047a520((::fnv_0047a520::NFSHelper *)(::NiFixedString *)(FUN_00499b80()))));
                        if (sequence)
                        {
                            p += reinterpret_cast<::FUN_004efb10_shell *>((sequence))->FUN_004efb10();
                            p += 4;
                        }
                    }
                }
            }
        }
    }
    if (*(*reinterpret_cast<::StringManager *>(&::g_011de4e8)).FUN_00408d60())
    {
        MessageRecord* message = (MessageRecord*)((::MessageInfo *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (message)
        {
            MessageProvider* provider = ((::MessageProvider *)(::FUN_004839c0(message->id)));
            ::FUN_0040fbe0(::DAT_01012cb0, p - i, message->id, provider->GetDisplayValue(),
                         *(unsigned int*)message->parameter, 5560, DAT_0101d930);
        }
        else
        {
            ::FUN_0040fbe0(::DAT_01012c78, p - i, 5560, DAT_0101d930);
        }
    }
    return p;
}

namespace fnv_00499b90 {
struct PaddedByte
{
    unsigned char b00, b01, b02, b03, b04;
    unsigned char value;
};
extern char UNK_0101ddc8;

struct Stream_00499b90
{
};
struct Detect_00499b90
{
    unsigned char* FUN_00408d60();
};
struct Lookup_00499b90
{
};
struct Elem_00499b90
{
};
struct Span_00499b90
{
};
struct Root_00499b90
{
};
struct NodeMgr_00499b90
{
};
struct Chan_00499b90
{
    int FUN_0045bc00(unsigned int uA);
};
struct Bc_00499b90
{
    int FUN_0045bc00(unsigned int uA);
};
struct Chan2_00499b90
{
};
struct Chan3_00499b90
{
};
struct Anim_00499b90
{
};
struct OutObj_00499b90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual char FUN_0018(std::uintptr_t uVal);
};
struct ChnObj_00499b90
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int FUN_000c();
};
struct NodeObj_00499b90
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
    virtual int FUN_0034();
};
struct MemObj_00499b90
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
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void* v8c(NiFixedString*);
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
    virtual unsigned int FUN_0130();
};
struct Class2_00499b90
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
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void* v8c(NiFixedString*);
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
    virtual bool FUN_0100();
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
    virtual unsigned int FUN_0130();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
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
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    NodeObj_00499b90 m_88;
};
struct Holder_00499b90
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float f10[3];
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned short f4c[8];
    unsigned int f5c[8];
    unsigned int f7c[8];
    unsigned short f9c[8];
    unsigned int fac[8];
    char fcc;
    char unkcd, unkce, unkcf;
    unsigned int fd0;
    unsigned int unkd4;
    unsigned int unkd8;
    void* fdc;
    void* fe0[8];
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    char f120;
    char unk121, unk122, unk123;
    void* f124;
    void* f128;
    void WriteToStream(Class2_00499b90* param_2);
};
// Serializes the holder's fields and per-slot data to the stream, writing a KOLB block header and patching its length afterwards.
// @fnv 0x00499b90
void Holder_00499b90::WriteToStream(Class2_00499b90* pClass2)
{
    unsigned short lengthA5;
    unsigned int uStart7;
    std::uintptr_t uMark2;
    char cb_;
    char bMask7;
    unsigned char bFlagVal;
    Class2_00499b90* pPi14;
    void __cdecl FUN_005b5e40(void*, ...);
    lengthA5 = 0;
    uMark2 = 0;
    uStart7 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
    if (*((Detect_00499b90*)&(*reinterpret_cast<::StringManager *>(&::g_011de4e8)))->FUN_00408d60() != '\0')
    {
        uStart7 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
    }
    if (reinterpret_cast<::FUN_00862110_cls *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned int uKolb;
        uKolb = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&uKolb), 4);
        uMark2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&lengthA5), 2);
    }
    reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->unk10c), 4);
    reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->unk110), 4);
    reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(this->f10), 0xc);
    reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->unk48), 4);
    reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->fcc), 1);
    bMask7 = 0;
    for (cb_ = 0; (char)cb_ < 8; cb_++)
    {
        if (this->f4c[cb_] != 0xff && this->f4c[cb_] != 0xffff)
        {
            bMask7 |= 1 << cb_;
        }
    }
    reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&bMask7), 1);
    for (cb_ = 0; (char)cb_ < 8; cb_++)
    {
        if (this->f4c[cb_] != 0xff && this->f4c[cb_] != 0xffff)
        {
            reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->f4c[cb_]), 2);
            reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->f5c[cb_]), 4);
            reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->f7c[cb_]), 4);
            reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->f9c[cb_]), 2);
            reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->fac[cb_]), 4);
            unsigned char bId;
            void* pOut;
            bId = 0xff;
            if (reinterpret_cast<::NiTMapBase *>((((Lookup_00499b90*)this->fdc)))->Lookup(this->f4c[cb_], (*(::AnimSequenceBase * *)(&pOut))))
            {
                bId = (unsigned char)((OutObj_00499b90*)pOut)->FUN_0018((std::uintptr_t)this->fe0[cb_]);
            }
            if (this->fe0[cb_] == 0)
            {
                FUN_005b5e40(&UNK_0101ddc8, pClass2->FUN_0130(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pClass2))->FUN_0084e3a0())), (int)cb_, (int)this->f4c[cb_],
                             this->f5c[cb_]);
                bId = 0xfe;
            }
            reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&bId), 1);
            if (this->fe0[cb_] != 0)
            {
                reinterpret_cast<::fnv_004efb20::FUN_004efb20_shell *>((((Elem_00499b90*)this->fe0[cb_])))->FUN_004efb20(*(float*)&this->fd0);
            }
        }
    }
    pPi14 = 0;
    if (pClass2 != 0)
    {
        if (pClass2->FUN_0100())
        {
            pPi14 = pClass2;
        }
    }
    if (((unsigned int)(::FUN_00559450((int *)(((Span_00499b90*)&this->f128))))) != 0)
    {
        ::fnv_004975e0::FUN_004975e0(pPi14, (::fnv_004975e0::SavedAnim *)(((std::uintptr_t)(::FUN_00559450((int *)(((Span_00499b90*)&this->f128)))))), (std::intptr_t)(((void*)this)), *(float*)&this->fd0);
    }
    else
    {
        ::fnv_004975e0::FUN_004975e0(pPi14, (::fnv_004975e0::SavedAnim *)(((std::uintptr_t)(::FUN_00559450((int *)(((Span_00499b90*)&this->f124)))))), (std::intptr_t)(((void*)this)), *(float*)&this->fd0);
    }
    reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&this->f120), 1);
    bFlagVal = 0;
    if (pPi14->m_88.FUN_0034() != 0)
    {
        void* pV;
        pV = ((Class2_00499b90*)((void *)(::fnv_00537bd0::GetStringAtOffset((const char *)(((NodeMgr_00499b90*)((void *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((((Root_00499b90*)((void*)this))))->FUN_00496940()))))))))
                 ->v8c(FUN_00499b70());
        if (pV != 0)
        {
            std::intptr_t iVar;
            iVar = ((ChnObj_00499b90*)pV)->FUN_000c();
            if (iVar != 0)
            {
                Chan_00499b90* p38;
                p38 = (Chan_00499b90*)(std::uintptr_t)((reinterpret_cast<::S_FUN_0045bc00 *>((((Bc_00499b90*)iVar)))->FUN_0045bc00(0)));
                if (p38 != 0)
                {
                    std::uintptr_t u38;
                    std::uintptr_t u3c3;
                    u38 = ((std::uintptr_t)(::fnv_0043b230::FUN_0043b230((const char *)(((Chan2_00499b90*)p38)))));
                    u3c3 = (std::uintptr_t)((void *)(::FUN_00653270((const ::NiRTTI *)(void *)(&(*reinterpret_cast<char *>(&::g_011f36ac))), (::NiObject *)(u38))));
                    if (u3c3 != 0)
                    {
                        std::uintptr_t u40;
                        u40 = reinterpret_cast<::fnv_0047a520::Fn47a520 *>((((Chan3_00499b90*)u3c3)))->FUN_0047a520((::fnv_0047a520::NFSHelper *)((std::uintptr_t)FUN_00499b80()));
                        if (u40 != 0)
                        {
                            bFlagVal = 1;
                            if (reinterpret_cast<::FUN_008df040_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008df040() >= 0x40)
                            {
                                reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&bFlagVal), 1);
                            }
                            reinterpret_cast<::fnv_004efb20::FUN_004efb20_shell *>((((Elem_00499b90*)u40)))->FUN_004efb20(*(float*)&this->fd0);
                            float f44;
                            void* pSequence3;
                            pSequence3 = reinterpret_cast<::Callees *>(&(pPi14->m_88))->FUN_00726070();
                            f44 = 0.0f;
                            if (pSequence3 != 0)
                            {
                                f44 = reinterpret_cast<::FUN_00621b00_shell *>((((Anim_00499b90*)pSequence3)))->FUN_00621b00();
                            }
                            reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&f44), 4);
                        }
                    }
                }
            }
        }
    }
    if (reinterpret_cast<::FUN_008df040_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008df040() >= 0x40 && bFlagVal == 0)
    {
        reinterpret_cast<::FUN_008579b0_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&bFlagVal), 1);
    }
    if (*((Detect_00499b90*)&(*reinterpret_cast<::StringManager *>(&::g_011de4e8)))->FUN_00408d60() != '\0')
    {
        unsigned int u50_2;
        std::uintptr_t u4c4;
        u50_2 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        u4c4 = ((std::uintptr_t)(reinterpret_cast<::EffectSetting *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->GetHitSound()));
        if (u4c4 != 0)
        {
            MemObj_00499b90* p54;
            p54 = (MemObj_00499b90*)((void *)(::FUN_004839c0(*(unsigned int*)u4c4)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00862110())
    {
        unsigned int u58;
        unsigned int u5c;
        u58 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((Stream_00499b90*)(*reinterpret_cast<::ActiveManager * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00();
        u5c = uMark2;
        if (u58 > u5c + 0xffff)
        {
            FUN_005b5e40(&(*reinterpret_cast<char *>((void *)&::DAT_01015318)), (std::uintptr_t)&(*reinterpret_cast<char *>((void *)&::DAT_0101d930)), 0x1628);
        }
        *(unsigned short*)uMark2 = (unsigned short)(u58 - u5c);
    }
}
}  // namespace fnv_00499b90

namespace fnv_0049bb70 {
class IdleReplayDelayEntry
{
};

struct NiControllerManager_ext
{
};

struct ReplayDelayNode
{
};

struct FUN_0049bb70_shell : public FUN_00496280_shell
{
    void RemoveItemFromMap(NiPointer<AnimIdle>*);
    void FUN_0049bb70(intptr_t);
};

// @fnv 0x0049bb70
void FUN_0049bb70_shell::FUN_0049bb70(intptr_t aiUnused)
{
    m_cSkipNextBlend = 0;
    reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(20, 0.0f);
    FUN_00496280();
    if (LocalInput)
    {
        RemoveItemFromMap(&LocalInput);
    }
    LocalInput = 0;
    if (LocalStateValue)
    {
        RemoveItemFromMap(&LocalStateValue);
    }
    LocalStateValue = 0;
    m_pChildTile[7] = 0;
    reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(7, 0.0f);
    if (m_acReservedBytes)
    {
        reinterpret_cast<::NiControllerManager *>((((NiControllerManager_ext*)(NiControllerManager*)m_acReservedBytes)))->DeactivateAllSequences(0.0f);
    }
    ReplayDelayNode* pIter = (ReplayDelayNode*)&m_acTrailingData;
    while (pIter)
    {
        IdleReplayDelayEntry* pDelay = *((::fnv_0049bb70::IdleReplayDelayEntry **)((void *)(pIter)));
        delete pDelay;
        pIter = ((::fnv_0049bb70::ReplayDelayNode *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>((((ReplayDelayNode*)&m_acTrailingData)))->RemoveAll();
}
}  // namespace fnv_0049bb70

namespace fnv_0049bf10 {

struct TimeGlobal
{
};

struct SeqStub
{
    int GetState();
    void Update(float afTime, bool abFlag);
};

struct ManagerStub
{
};

// @fnv 0x0049bf10
void SetSequenceProgress(float afPercent, ManagerStub* apManager, SeqStub* apSequence)
{
    if (!apManager || !apSequence)
        return;

    if (afPercent == ::_DAT_01012060)
    {
        if (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((apSequence))->GetActiveCombatTarget())) == 1)
        {
            reinterpret_cast<::fnv_00a328b0::SeqExt *>((apSequence))->FUN_00a328b0(0.0f, true);
            reinterpret_cast<::AnimationSequence *>((apSequence))->FUN_00a34ba0(0.0f, true);
        }
    }
    else
    {
        if (((std::intptr_t)(reinterpret_cast<::LowProcess *>((apSequence))->GetActiveCombatTarget())) == 0)
        {
            reinterpret_cast<::TaskQueueInterface *>((apManager))->QueueReferenceStateTask(true);
            reinterpret_cast<::NiControllerManager *>((apManager))->ActivateControllerSequence((::NiControllerSequence *)(apSequence), 0, false, 1.0f, 0.0f, (::NiControllerSequence *)(::fnv_0049bf10::SeqStub *)(0));
            reinterpret_cast<::AnimationSequence *>((apSequence))->FUN_00a34ba0(::fnv::timer::Time() / 1000.0 + reinterpret_cast<::FUN_00759450_shell *>((apSequence))->FUN_00759450(), true);
        }
        if (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((apSequence))->GetActiveCombatTarget())) == 1)
        {
            float fScaleMultiplier = reinterpret_cast<::FUN_00508100_shell *>((apSequence))->FUN_00508100() - reinterpret_cast<::FUN_00759450_shell *>((apSequence))->FUN_00759450();
            float fTime2 = reinterpret_cast<::FUN_00759450_shell *>((apSequence))->FUN_00759450() + fScaleMultiplier * afPercent;
            reinterpret_cast<::fnv_00a328b0::SeqExt *>((apSequence))->FUN_00a328b0(fTime2 - ::fnv::timer::Time() / 1000.0f, true);
        }
    }
}
}  // namespace fnv_0049bf10

namespace fnv_004939d0 {

struct PathingRequest
{
  public:
};

struct AnimNode_Vtable
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual PathingRequest* vfn_10();
};

struct FUN_00493b90_shell
{
};

struct FUN_00493860_shell
{
};

struct FUN_004f8960_shell
{
};

struct FUN_00493bb0_shell
{
};

struct FUN_008b0140_shell
{
};

struct FUN_0084e3a0_shell
{
};

struct FUN_00b63680_shell
{
};

struct FUN_00b7b930_Ctx;

class _FakeNiNode : public NiNode
{
  public:
};

struct FUN_0043c490_shell
{
};

struct FUN_004f0040_shell
{
};

class AnimationShell : public Animation
{
  public:
    void UpdateAnimationForRef(TESObjectREFR* apRef);
};

// @fnv 0x004939d0
void AnimationShell::UpdateAnimationForRef(TESObjectREFR* apRef)
{
    if (!m_acHeaderData || !m_pObjectNode)
        return;

    if (reinterpret_cast<::FUN_00493b90_shell *>((reinterpret_cast<FUN_00493b90_shell*>(this)))->FUN_00493b90())
        return;

    bool bOther = apRef != (*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer));
    bool bNearLimit2 = false;

    NiNode* pNode5 = apRef->GetNiNode();
    PathingRequest* pReq = pNode5 ? reinterpret_cast<AnimNode_Vtable*>(pNode5)->vfn_10() : 0;

    if (bOther && (reinterpret_cast<::FUN_004f8960_shell *>((reinterpret_cast<FUN_004f8960_shell*>(apRef)))->FUN_004f8960() == 1 ||
                   ((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((reinterpret_cast<FUN_00493bb0_shell*>(apRef)))->FUN_00493bb0()))))
    {
        bOther = false;
    }
    else if (pReq && ::GetFieldB4Float((char *)(pReq)) <= 0.0)
    {
        bNearLimit2 = true;
    }

    reinterpret_cast<::FUN_008b0140_shell *>((reinterpret_cast<FUN_008b0140_shell*>(apRef)))->SetVisibilityMask(true, 1);

    FUN_00b7b930_Ctx* pCtx5 = ((::fnv_004939d0::FUN_00b7b930_Ctx *)(::FUN_00b4f5c0()));
    if (pCtx5 && reinterpret_cast<::FUN_00b63680_shell *>((reinterpret_cast<FUN_00b63680_shell*>(pCtx5)))->CheckVolumeState(
                     reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<FUN_0084e3a0_shell*>(apRef)))->FUN_0084e3a0(), false))
    {
        reinterpret_cast<::FUN_008b0140_shell *>((reinterpret_cast<FUN_008b0140_shell*>(apRef)))->SetVisibilityMask(false, 2);
    }
    else
    {
        reinterpret_cast<::FUN_008b0140_shell *>((reinterpret_cast<FUN_008b0140_shell*>(apRef)))->SetVisibilityMask(true, 2);
    }

    if (pReq && ::GetFieldB4Float((char *)(pReq)) < 0.00001f)
    {
        reinterpret_cast<::FUN_008b0140_shell *>((reinterpret_cast<FUN_008b0140_shell*>(apRef)))->SetVisibilityMask(false, 4);
    }
    else
    {
        reinterpret_cast<::FUN_008b0140_shell *>((reinterpret_cast<FUN_008b0140_shell*>(apRef)))->SetVisibilityMask(true, 4);
    }

    float fOldZ =
        reinterpret_cast<::NiAVObject *>((reinterpret_cast<FUN_0043c490_shell*>(reinterpret_cast<::NiNode *>((static_cast<_FakeNiNode*>(m_pObjectNode)))->GetAt(0))))->FUN_0043c490().z;

    reinterpret_cast<::FUN_004f0040_shell *>((reinterpret_cast<FUN_004f0040_shell*>((NiNode*)m_acHeaderData)))->UpdateControls(time);

    m_kNodeTranslation.z = reinterpret_cast<::NiAVObject *>((reinterpret_cast<FUN_0043c490_shell*>(reinterpret_cast<::NiNode *>((static_cast<_FakeNiNode*>(m_pObjectNode)))->GetAt(0))))->FUN_0043c490()
                          .z -
                      fOldZ;

    reinterpret_cast<::FUN_00493860_shell *>((reinterpret_cast<FUN_00493860_shell*>(this)))->FUN_00493860(true);
}
}  // namespace fnv_004939d0

class FUN_0048f810
{
  public:
    FUN_0048f810();


    unsigned char m_uiObjectFlags;
    TESObjectREFR* m_pAttachedReference;
    NiPointer<NiNode> m_acHeaderData;
    NiNode* m_pObjectNode;
    NiPoint3 m_kNodeTranslation;
    NiPoint3 m_kRootTranslation;
    NiAVObject* m_acNodeName[8];
    float m_fAnimationAmount;
    unsigned short group[8];
    ANIM_GROUP_ACTION action[8];
    int m_acTargetName[8];
    unsigned short usReloadGroup[8];
    int m_acAnimationName[8];
    char m_cState;
    bool m_bIsPlaying;
    float time;
    float m_fTimeOffset;
    NiPointer<NiControllerManager> m_acReservedBytes;
    NiTPointerMap<unsigned short, AnimSequenceBase*>* m_pOwnerReference;
    BSAnimGroupSequence* m_pChildTile[8];
    BSAnimGroupSequence* m_pCurrentSequence;
    BSSimpleList<KFModel*> kfModelList;
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    unsigned short m_usQueuedGroup;
    NiPointer<AnimIdle> LocalInput;
    NiPointer<AnimIdle> LocalStateValue;
    NiPointer<AnimIdle> LocalOutput[2];
    BSSimpleList<IdleReplayDelayEntry*> m_acTrailingData;
};


// @fnv 0x0048f810
FUN_0048f810::FUN_0048f810() : m_acHeaderData(0), m_acReservedBytes(0), LocalInput(0), LocalStateValue(0)
{
    m_acHeaderData = 0;
    m_pObjectNode = 0;
    m_kNodeTranslation = NiPoint3::ZERO;
    m_kRootTranslation = NiPoint3::ZERO;
    m_fAnimationAmount = 0.0f;
    m_cState = -1;
    m_cSkipNextBlend = 0;
    reinterpret_cast<::FUN_0048fb20_Class *>(this)->UpdateFlags(0, 0xff, 0);
    m_pAttachedReference = 0;
    m_pCurrentSequence = 0;
    time = 0.0f;
    m_acReservedBytes = 0;
    LocalInput = 0;
    LocalStateValue = 0;
    LocalOutput[0] = 0;
    LocalOutput[1] = 0;
    m_pOwnerReference = new NiTPointerMap<unsigned short, AnimSequenceBase*>(101);
    memset(m_acNodeName, 0, sizeof(m_acNodeName));
    memset(m_pChildTile, 0, sizeof(m_pChildTile));
    memset(group, 0xff, sizeof(group));
    memset(usReloadGroup, 0xff, sizeof(usReloadGroup));
    memset(action, -1, sizeof(action));
    memset(m_acTargetName, -1, sizeof(m_acTargetName));
    memset(m_acAnimationName, -1, sizeof(m_acAnimationName));
    m_fMovementRate = 1.0f;
    m_fCombatAnimationRate = 1.0f;
    m_fEquipAnimationRate = 1.0f;
    m_fReloadAnimationRate = 1.0f;
    m_fAnimationTimeScale = 1.0f;
    m_usQueuedGroup = 0xff;
    m_bIsPlaying = false;
}

namespace fnv_00496a50 {
template <int N> struct Slots496 : Slots496<N - 1>
{
    virtual void pad(Slots496<N>*);
};
template <> struct Slots496<0>
{
};
struct Process496 : Slots496<250>
{
    virtual void* get();
};
struct Manager496
{
};
struct Anim496
{
};
struct Actor496 : Slots496<121>
{
    virtual Anim496* get();
};
struct Node496 : Slots496<58>
{
    virtual void remove(void*);
};
struct Object496
{
};
struct Ref496
{
    void* value;
    void FUN_0066b0d0(void*);
};
struct Queue496
{
};
struct Shadow496
{
};
struct ModelPart496 : Slots496<5>
{
    virtual const char* get();
};
struct Model496
{
    char pad[24];
    ModelPart496 part;
};
struct Data496
{
    char pad[8];
    int count;
    char pad2[12];
    Ref496 root;
    Model496* models[2];
    Ref496 objects[2];
    char pad3[8];
    Actor496* actor;
};
struct Loader496
{
};
struct Save496
{
};
struct Target496
{
    static void DetachObjectModels(Data496* data);
};
// @fnv 0x00496a50
void Target496::DetachObjectModels(Data496* data)
{
    if (!data)
        return;
    for (int i = 0; i < 2; ++i)
    {
        if (((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->objects[i])))))
        {
            if (data->actor)
            {
                if (::FUN_008c7aa0())
                    reinterpret_cast<::fnv_0087ad00::H0087ad00 *>((((::fnv_00496a50::Queue496 *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087ad00((::fnv_0087ad00::G00559a40 *)(void *)(((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->objects[i]))))), (void *)(0));
                else
                    ::FUN_00b5b1c0((::ShadowSceneNode *)(((::fnv_00496a50::Shadow496 *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))), (std::intptr_t)(((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->objects[i]))))), {});
                void* anim = ((void *)(::fnv_00537bd0::GetStringAtOffset((const char *)(((::fnv_00496a50::Manager496 *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((data->actor->get()))->FUN_00496940()))))));
                void* copy7 = anim;
                ::FUN_00a6e8e0((::S_00a6e8e0_Object *)(void *)(((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->objects[i]))))), (::S_00a6e8e0_Palette *)(copy7));
                Anim496* manager5 = data->actor->get();
                if (manager5)
                    reinterpret_cast<::FUN_0049bd90_shell *>((manager5))->FUN_0049bd90(((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->objects[i])))));
            }
            if (::FUN_008c7aa0())
                reinterpret_cast<::fnv_0087ac60::FUN_0087AC60_Holder *>((((::fnv_00496a50::Queue496 *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087ac60((::fnv_0087ac60::G00559a40 *)(void *)(((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->objects[i]))))));
            else
            {
                Node496* nodeB = ((::fnv_00496a50::Node496 *)(reinterpret_cast<::FUN_009611e0_shell *>((((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->objects[i]))))))->FUN_009611e0()));
                nodeB->remove(((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->objects[i])))));
            }
            reinterpret_cast<::FUN_0045a5e0_shell *>(((*(Loader496**)&(*reinterpret_cast<char *>(&::g_modelLoader)))))->FUN_0045a5e0((char *)(data->models[i]->part.get()));
            data->objects[i].FUN_0066b0d0(0);
            if (((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->root)))))
                reinterpret_cast<::FUN_004eecb0_Class *>((((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->root))))))->FUN_004eecb0();
        }
    }
    if (!data->count)
        reinterpret_cast<::SaveOwner_b9539 *>(((*(Loader496**)&(*reinterpret_cast<char *>(&::g_modelLoader)))))->FUN_004454d0((std::intptr_t)(data));
    if (!reinterpret_cast<::FUN_0047c850 *>(((*(Save496**)&DAT_011de45c)))->EvaluateCondition() && data->actor && reinterpret_cast<::FUN_008a7570_shell *>((data->actor))->FUN_008a7570() == 13)
    {
        Process496* process = ((::fnv_00496a50::Process496 *)(reinterpret_cast<::BSShaderNoLightingProperty *>((data->actor))->GetBaseTexture()));
        if (process->get() == ((::fnv_00496a50::Object496 *)(::FUN_00559450((int *)&(data->root)))))
            reinterpret_cast<::fnv_008a73e0::FUN_008a73e0_shell *>((data->actor))->FUN_008a73e0(-1, (::fnv_008a73e0::BSAnimGroupSequence *)(0));
    }
    data->actor = 0;
}
}  // namespace fnv_00496a50

using AutoMemContextX = ::AutoMemContext;
class NiControllerManagerX
{
  public:
};
class AnimationX
{
  public:
};
class SeqBase0
{
  public:
    int a0, a4, a8, aC, a10, a14;
};
class SeqBase18
{
  public:
    int b0;
};
class SeqX : public SeqBase0, public SeqBase18
{
};
class SeqPtr
{
  public:
    SeqX* m_p;
    SeqPtr& FUN_0066b0d0(SeqX*);
};
class StrX
{
  public:
    void* m_p;
};
class KFModelX
{
  public:
};
class KFPtr
{
  public:
    KFModelX* m_p;
};
class ActorX
{
  public:
    virtual void v000(), v004(), v008(), v00C(), v010(), v014(), v018(), v01C(), v020(), v024(), v028(), v02C(), v030(),
        v034(), v038(), v03C(), v040(), v044(), v048(), v04C(), v050(), v054(), v058(), v05C(), v060(), v064(), v068(),
        v06C(), v070(), v074(), v078(), v07C(), v080(), v084(), v088(), v08C(), v090(), v094(), v098(), v09C(), v0A0(),
        v0A4(), v0A8(), v0AC(), v0B0(), v0B4(), v0B8(), v0BC(), v0C0(), v0C4(), v0C8(), v0CC(), v0D0(), v0D4(), v0D8(),
        v0DC(), v0E0(), v0E4(), v0E8(), v0EC(), v0F0(), v0F4(), v0F8(), v0FC(), v100(), v104(), v108(), v10C(), v110(),
        v114(), v118(), v11C(), v120(), v124(), v128(), v12C(), v130(), v134(), v138(), v13C(), v140(), v144(), v148(),
        v14C(), v150(), v154(), v158(), v15C(), v160(), v164(), v168(), v16C(), v170(), v174(), v178(), v17C(), v180(),
        v184(), v188(), v18C(), v190(), v194(), v198(), v19C(), v1A0(), v1A4(), v1A8(), v1AC(), v1B0(), v1B4(), v1B8(),
        v1BC(), v1C0(), v1C4(), v1C8(), v1CC(), v1D0(), v1D4(), v1D8(), v1DC(), v1E0();
    virtual AnimationX* GetAnimation();
};
class FUN_00496cd0_cls
{
  public:
    virtual ~FUN_00496cd0_cls();
    int unk04;
    int m_uiImageSpaceModifierCount;
    int iType;
    KFPtr m_pRenderedNodeEntry;
    int unk14;
    StrX kName;
    SeqX* apSeq[2];
    SeqPtr aspSeq[2];
    int unk2C;
    AnimationX* pAnim;
    ActorX* pActor;
    void InitFromModel(KFModelX* m_kModelObjectsItem);
};
// @fnv 0x00496cd0
void FUN_00496cd0_cls::InitFromModel(KFModelX* m_kModelObjectsItem)
{
    AutoMemContextX kContext(0x33, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp",
                             0x1101);
    reinterpret_cast<::NiPointer_KFModel *>(&(m_pRenderedNodeEntry))->FUN_0044b070((::KFModel *)(m_kModelObjectsItem));
    if (m_kModelObjectsItem)
    {
        for (int i = 0; i < 2; i++)
        {
            if (apSeq[i] && pActor)
            {
                aspSeq[i].FUN_0066b0d0(((::SeqX *)(::FUN_004aeed0((::TESForm *)(apSeq[i]), (::TESModel *)(apSeq[i]), -1, (::TESObjectREFR *)(pActor), (::NiAVObject *)(0)))));
                void* pMgr = ((void *)(::fnv_00537bd0::GetStringAtOffset((const char *)(((::NiControllerManagerX *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>((pActor->GetAnimation()))->FUN_00496940()))))));
                void* pAnimMgrCopy = pMgr;
                ::AddObjectToPalette((::NiAVObject *)(::SeqX *)(((::SeqX *)(::FUN_00559450((int *)&(aspSeq[i]))))), (::NiDefaultAVObjectPalette *)(pAnimMgrCopy));
                reinterpret_cast<::FUN_00496960_shell *>((pActor))->SetByteAt14E(true);
            }
        }
        ::FUN_0043be10((char *)(m_kModelObjectsItem));
        m_uiImageSpaceModifierCount = 1;
        if (pActor && (iType == 2 || iType == 3))
        {
            AnimationX* pkAnim = pAnim;
            if (!pkAnim)
                pkAnim = pActor->GetAnimation();
            if (!pkAnim)
            {
                delete this;
                return;
            }
            if (reinterpret_cast<::AnimationAccess *>((pkAnim))->FUN_00498290())
            {
                if (iType == 3)
                    reinterpret_cast<::fnv_008a73e0::FUN_008a73e0_shell *>((pActor))->FUN_008a73e0(0xd, (::fnv_008a73e0::BSAnimGroupSequence *)(((const char *)(::FUN_00559450((int *)&(kName))))));
            }
            else
            {
                reinterpret_cast<::Animation *>((pkAnim))->SpecialIdleFree(true, false);
            }
        }
        else if (pActor && iType == 0)
        {
            AnimationX* pkAnim = pAnim;
            if (!pkAnim)
                pkAnim = pActor->GetAnimation();
            if (!pkAnim)
            {
                delete this;
                return;
            }
            if (reinterpret_cast<::fnv_00498170::FUN_00498170_shell *>((pkAnim))->FUN_00498170())
                return;
        }
    }
    else
    {
        m_uiImageSpaceModifierCount = 0;
    }
}

struct Node
{
};
struct Ref
{
    void* p;
    Ref(int);
    ~Ref();
    void FUN_0066b0d0(void*);
};
struct Item
{
    virtual ~Item();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(int);
};
struct Map
{
};
struct Target
{
    char pad[0xcd];
    unsigned char flag;
    char pad2[10];
    Ref ref;
    Map* map;
    void* values[8];
    void* current;
    void RemoveItemFromMap(Ref* arg);
};
// @fnv 0x00498910
void Animation::SpecialIdleFree(bool freeQueued, bool immediate)
{
    if (LocalInput)
    {
        int section = LocalInput->GetSection();
        switch (section)
        {
        case 21:
            section = 4;
            break;
        case 20:
            section = 1;
            break;
        }
        if (LocalInput->GetControllerSequence() && m_pChildTile[section] == LocalInput->GetControllerSequence())
        {
            if (immediate)
                m_pChildTile[section] = 0;
            else
            {
                switch (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((LocalInput->GetControllerSequence()))->GetActiveCombatTarget())))
                {
                case 2:
                case 5:
                    Warning("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                            (const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(LocalInput->GetControllerSequence()))->GetLinkToList())));
                    return;
                }
                BlendOut(LocalInput->GetSection(), false);
            }
        }
        if (!immediate && !LocalOutput[0])
        {
            LocalOutput[0] = LocalInput;
            LocalInput = 0;
        }
        else if (!immediate && !LocalOutput[1])
        {
            LocalOutput[1] = LocalInput;
            LocalInput = 0;
        }
        else
            reinterpret_cast<::Target *>(this)->RemoveItemFromMap((::Ref *)&(LocalInput));
    }
    if (freeQueued && LocalStateValue)
    {
        int queuedSection = LocalStateValue->GetSection();
        switch (queuedSection)
        {
        case 21:
            queuedSection = 4;
            break;
        case 20:
            queuedSection = 1;
            break;
        }
        if (LocalStateValue->GetControllerSequence() &&
            m_pChildTile[queuedSection] == LocalStateValue->GetControllerSequence())
        {
            if (immediate)
                m_pChildTile[queuedSection] = 0;
            else
            {
                switch (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((LocalStateValue->GetControllerSequence()))->GetActiveCombatTarget())))
                {
                case 2:
                case 5:
                    Warning("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                            (const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(LocalStateValue->GetControllerSequence()))->GetLinkToList())));
                    return;
                }
                BlendOut(queuedSection, false);
            }
        }
        if (!immediate && !LocalOutput[0])
        {
            LocalOutput[0] = LocalStateValue;
            LocalStateValue = 0;
        }
        else if (!immediate && !LocalOutput[1])
        {
            LocalOutput[1] = LocalStateValue;
            LocalStateValue = 0;
        }
        else
            reinterpret_cast<::Target *>(this)->RemoveItemFromMap((::Ref *)&(LocalStateValue));
    }
    else
    {
        LocalInput = LocalStateValue;
        LocalStateValue = 0;
    }
}
// @fnv 0x00498910
void FUN_00498910_shell::FUN_00498910(bool abFreeQueued, bool abForceDelete)
{
    if (LocalInput)
    {
        int esection = LocalInput->GetSection();
        switch (esection)
        {
        case 0x15:
            esection = 4;
            break;
        case 0x14:
            esection = 1;
            break;
        }
        if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalInput).operator->()))->FUN_00490e40() && m_pChildTile[esection] == reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalInput).operator->()))->FUN_00490e40())
        {
            if (abForceDelete)
            {
                m_pChildTile[esection] = 0;
            }
            else
            {
                switch (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalInput).operator->()))->FUN_00490e40()))->GetActiveCombatTarget())))
                {
                case 2:
                case 5:
                    Warning("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                            (const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalInput).operator->()))->FUN_00490e40()))->GetLinkToList())));
                    return;
                }
                BlendOut(LocalInput->GetSection(), false);
            }
        }
        if (!abForceDelete && !LocalOutput[0])
        {
            LocalOutput[0] = LocalInput;
            LocalInput = 0;
        }
        else if (!abForceDelete && !LocalOutput[1])
        {
            LocalOutput[1] = LocalInput;
            LocalInput = 0;
        }
        else
        {
            reinterpret_cast<::Target *>(this)->RemoveItemFromMap((::Ref *)&(LocalInput));
        }
    }
    if (abFreeQueued && LocalStateValue)
    {
        int esection = LocalStateValue->GetSection();
        switch (esection)
        {
        case 0x15:
            esection = 4;
            break;
        case 0x14:
            esection = 1;
            break;
        }
        if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalStateValue).operator->()))->FUN_00490e40() &&
            m_pChildTile[esection] == reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalStateValue).operator->()))->FUN_00490e40())
        {
            if (abForceDelete)
            {
                m_pChildTile[esection] = 0;
            }
            else
            {
                switch (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalStateValue).operator->()))->FUN_00490e40()))->GetActiveCombatTarget())))
                {
                case 2:
                case 5:
                    Warning("ANIMATION: Trying to SpecialIdleFree an animation '%s' that just started.",
                            (const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalStateValue).operator->()))->FUN_00490e40()))->GetLinkToList())));
                    return;
                }
                BlendOut(esection, false);
            }
        }
        if (!abForceDelete && !LocalOutput[0])
        {
            LocalOutput[0] = LocalStateValue;
            LocalStateValue = 0;
        }
        else if (!abForceDelete && !LocalOutput[1])
        {
            LocalOutput[1] = LocalStateValue;
            LocalStateValue = 0;
        }
        else
        {
            reinterpret_cast<::Target *>(this)->RemoveItemFromMap((::Ref *)&(LocalStateValue));
        }
    }
    else
    {
        LocalInput = LocalStateValue;
        LocalStateValue = 0;
    }
}
// Advances animation sequences, handles queued groups, reload actions, idle cleanup, movement accumulation and sound updates for the reference.
// @fnv 0x00491180
void FUN_00491180_shell::FUN_00491180(TESObjectREFR* apRef, float afDelta, float afTime)
{
    float fTimeMultiplier = ::fnv::timer::Seconds() * m_fEquipAnimationRate;
    if (reinterpret_cast<::FUN_00493830_shell *>(this)->FUN_00493830())
    {
        for (; (*reinterpret_cast<unsigned int *>(&::DAT_011c56e8)) < *((unsigned int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSettingStub *>(&::g_011c5778)))))); (*reinterpret_cast<unsigned int *>(&::DAT_011c56e8))++)
        {
            KFModel* m_kModelObjectsItem = (kfModelList.m_item);
            reinterpret_cast<::Anim490 *>(this)->AddModel((::Model490 *)(m_kModelObjectsItem), false);
            FinishScriptRunLockIfActive(m_kModelObjectsItem);
            kfModelList.RemoveHead();
            if (!reinterpret_cast<::FUN_00493830_shell *>(this)->FUN_00493830())
                break;
        }
    }
    else if (m_usQueuedGroup != 0xff)
    {
        BSAnimGroupSequence* pWeaponSeq = m_pChildTile[4];
        switch (action[4])
        {
        case 1:
        case 2:
            if (pWeaponSeq && !reinterpret_cast<::fnv_004937c0::TESAnimGroup *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(((SeqStub*)pWeaponSeq)))->GetAnimGroup()))))->FUN_004937c0() &&
                reinterpret_cast<::fnv_004937e0::TESAnimGroup *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(((SeqStub*)pWeaponSeq)))->GetAnimGroup()))))->FUN_004937e0())
                break;
        case 3:
            if (reinterpret_cast<::FUN_008a16d0_shell *>((((ActorStub*)m_pAttachedReference)))->FUN_008a16d0())
            {
                PlayGroupEx(m_usQueuedGroup, 1, -1, -1);
                if (apRef == ::_g_thePlayer)
                    ((PlayerStub*)::_g_thePlayer)->QueueReloadGroup(m_usQueuedGroup, true);
                ActorStub* pReloader = (ActorStub*)apRef;
                bool bSpecial = false;
                if (((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pReloader))->GetBaseTexture())))
                {
                    int iWeaponType =
                        ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pReloader))->GetBaseTexture()))->GetActiveWeapon()
                            ? ((std::intptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((WeaponStub*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pReloader))->GetBaseTexture()))->GetActiveWeapon())))->GetName()))
                            : 0;
                    if (((bool)(reinterpret_cast<::FUN_004938c0_class *>((iWeaponType))->GetByteAt384())))
                        bSpecial = true;
                }
                if (bSpecial)
                    reinterpret_cast<::fnv_008a73e0::FUN_008a73e0_shell *>((pReloader))->FUN_008a73e0(0x11, (::fnv_008a73e0::BSAnimGroupSequence *)(m_pChildTile[4]));
                else
                    reinterpret_cast<::fnv_008a73e0::FUN_008a73e0_shell *>((pReloader))->FUN_008a73e0(9, (::fnv_008a73e0::BSAnimGroupSequence *)(m_pChildTile[4]));
            }
        default:
            m_usQueuedGroup = 0xff;
        }
    }

    if (!m_acTrailingData.IsEmpty())
    {
        BSSimpleList<IdleReplayDelayEntry*>* pNode = &m_acTrailingData;
        while (pNode)
        {
            IdleReplayDelayEntry* pDelay = (pNode->m_item);
            pDelay->m_fDelay = pDelay->m_fDelay - afDelta;
            if (pDelay->m_fDelay <= 0.0)
            {
                if (pNode == &m_acTrailingData)
                    pNode = 0;
                else
                    pNode = ((::BSSimpleList< ::IdleReplayDelayEntry *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
                reinterpret_cast<::ItemChangeListNode *>(&(m_acTrailingData))->FUN_00905330((::InventoryStackRecord *const &)(pDelay));
                delete pDelay;
                if (!pNode && !m_acTrailingData.IsEmpty())
                    pNode = &m_acTrailingData;
            }
            else
            {
                pNode = ((::BSSimpleList< ::IdleReplayDelayEntry *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
            }
        }
    }

    ActorStub* pRefActor = 0;
    if (apRef && apRef->IsActor())
        pRefActor = (ActorStub*)apRef;

    for (int iIdle = 0; iIdle < 2; iIdle++)
    {
        if (LocalOutput[iIdle])
        {
            if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((IdleStub*)(AnimIdle*)LocalOutput[iIdle])))->FUN_00490e40())
            {
                if (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((IdleStub*)(AnimIdle*)LocalOutput[iIdle])))->FUN_00490e40()))->GetActiveCombatTarget())) == 1)
                {
                    Warning("'%s' is trying to free a special idle '%s' sequence '%s' that is animating.",
                            m_pAttachedReference->GetName(),
                            ((::TESForm *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((((IdleStub*)(AnimIdle*)LocalOutput[iIdle])))->GetIconFormID()))->GetName(),
                            (const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((IdleStub*)(AnimIdle*)LocalOutput[iIdle])))->FUN_00490e40()))->GetLinkToList())));
                    LocalOutput[iIdle] = 0;
                }
                else if (((std::intptr_t)(reinterpret_cast<::LowProcess *>((reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((IdleStub*)(AnimIdle*)LocalOutput[iIdle])))->FUN_00490e40()))->GetActiveCombatTarget())) == 0)
                {
                    reinterpret_cast<::Target *>(this)->RemoveItemFromMap((::Ref *)&(LocalOutput[iIdle]));
                }
            }
            else if (((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((IdleStub*)(AnimIdle*)LocalOutput[iIdle])))->GetName())))
            {
                reinterpret_cast<::Target *>(this)->RemoveItemFromMap((::Ref *)&(LocalOutput[iIdle]));
            }
        }
    }

    if (!m_acHeaderData)
        return;

    reinterpret_cast<::FUN_00493860_shell *>(this)->FUN_00493860(false);
    m_kNodeTranslation.x = 0.0f;
    m_kNodeTranslation.y = 0.0f;

    if (m_cState == 0x14)
    {
        float fTime = (afTime == -1.0) ? time : afTime;
        NiUpdateData kUpdData(fTime, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((NiNode*)m_acHeaderData)))->FUN_00a59c60((std::intptr_t)&(kUpdData));
        return;
    }

    float fTimeStep = afDelta;
    int iGroup = 0xff;
    int iNextGroupType;
    BSAnimGroupSequence* apSequences[8];
    bool bTalks;
    float afPrevTimes[8];
    int i;
    for (i = 0; i < 8; i++)
    {
        iGroup = GetType(group[i]);
        iNextGroupType = GetType(usReloadGroup[i]);
        if (iGroup == 0xff && iNextGroupType != 0xff)
        {
            m_acTargetName[i] = m_acAnimationName[i];
            reinterpret_cast<::FUN_004948c0_shell *>(this)->GetSequenceForGroup(usReloadGroup[i], -1);
            usReloadGroup[i] = iNextGroupType = 0xff;
            iGroup = GetType(group[i]);
        }
        BSAnimGroupSequence* pForwardSequence = reinterpret_cast<::FUN_00491040_shell *>(this)->FUN_00491040(i);
        apSequences[i] = pForwardSequence;
        afPrevTimes[i] = 0.0f;
        if (iGroup == 0xff || !pForwardSequence)
            continue;
        afPrevTimes[i] = reinterpret_cast<::FUN_004eec60_shell *>((((SeqStub*)pForwardSequence)))->FUN_004eec60(time);
    }

    if (afTime != -1.0)
    {
        time = afTime;
        NiUpdateData kUpdateData(time, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((NiNode*)m_acHeaderData)))->FUN_00a59c60((std::intptr_t)&(kUpdateData));
        return;
    }

    fTimeStep = fTimeStep * m_fEquipAnimationRate;
    time = time + fTimeStep;

    for (i = 0; i < 8; i++)
    {
        SeqStub* pSequence = (SeqStub*)reinterpret_cast<::FUN_00491040_shell *>(this)->FUN_00491040(i);
        bool bUpdate = true;
        iGroup = GetType(group[i]);
        iNextGroupType = GetType(usReloadGroup[i]);
        if (iGroup == 0xff || !pSequence)
            continue;
        if (i == 3)
            bUpdate = false;
        switch (m_cState)
        {
        case 0x17:
            if (i != 7 && i != 0)
                bUpdate = false;
            break;
        case 0x14:
            bUpdate = false;
            break;
        case 0x15:
            switch (i)
            {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                bUpdate = false;
            }
            break;
        case 4:
            switch (i)
            {
            case 4:
            case 5:
            case 6:
                bUpdate = false;
            }
            break;
        default:
            if (i == m_cState)
                bUpdate = false;
        }

        if (!bUpdate)
        {
            reinterpret_cast<::fnv_00a328b0::SeqExt *>((pSequence))->FUN_00a328b0(reinterpret_cast<::FUN_00493770_shell *>((pSequence))->FUN_00493770() - fTimeStep, {});
        }
        else if (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((pSequence))->GetActiveCombatTarget())) == 1)
        {
            if (iGroup >= 3 && iGroup <= 0x10)
                reinterpret_cast<::fnv_00a328b0::SeqExt *>((pSequence))->FUN_00a328b0(reinterpret_cast<::FUN_00493770_shell *>((pSequence))->FUN_00493770() + (fTimeStep * m_fMovementRate - fTimeStep), {});
            else if (iGroup == 0x18 || iGroup == 0x19)
                reinterpret_cast<::fnv_00a328b0::SeqExt *>((pSequence))->FUN_00a328b0(reinterpret_cast<::FUN_00493770_shell *>((pSequence))->FUN_00493770() + (fTimeStep * m_fAnimationTimeScale - fTimeStep), {});
            else if (iGroup >= 0x18 && iGroup <= 0xa8)
                reinterpret_cast<::fnv_00a328b0::SeqExt *>((pSequence))->FUN_00a328b0(reinterpret_cast<::FUN_00493770_shell *>((pSequence))->FUN_00493770() + (fTimeStep * m_fCombatAnimationRate - fTimeStep), {});
            else if (iGroup >= 0xb1 && iGroup <= 0xc7)
                reinterpret_cast<::fnv_00a328b0::SeqExt *>((pSequence))->FUN_00a328b0(reinterpret_cast<::FUN_00493770_shell *>((pSequence))->FUN_00493770() + (fTimeStep * m_fReloadAnimationRate - fTimeStep), {});
        }

        if (bUpdate && ((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((pSequence))->GetActiveCombatTarget())) == 1)
        {
            switch (DAT_011977e4[iGroup].iSequenceType)
            {
            case 5:
                if (action[i] < 4 &&
                    reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) > reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 4 && reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(4))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        reinterpret_cast<::FUN_004948c0_shell *>(this)->GetSequenceForGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            case 3:
            case 4:
            case 6:
            case 10:
                if (action[i] < 2 &&
                    reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) > reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 2 && reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(2))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        reinterpret_cast<::FUN_004948c0_shell *>(this)->GetSequenceForGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                        if (pRefActor &&
                            (DAT_011977e4[iGroup].iSequenceType == 3 || DAT_011977e4[iGroup].iSequenceType == 4))
                        {
                            BaseProcess* pProcess = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pRefActor))->GetBaseTexture()));
                            if (pProcess)
                            {
                                if ((Actor*)pRefActor != (Actor*)::_g_thePlayer)
                                    pProcess->AddPostAnimAction(0x4000);
                                else
                                    reinterpret_cast<::HX *>((pRefActor))->GetWeaponObject();
                            }
                        }
                    }
                }
                break;
            case 7:
                if (action[i] < 4 &&
                    reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) > reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 4 && reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(4))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        reinterpret_cast<::FUN_004948c0_shell *>(this)->GetSequenceForGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            case 8:
                if (action[i] < 3 &&
                    reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) > reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 3 && reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(3))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        reinterpret_cast<::FUN_004948c0_shell *>(this)->GetSequenceForGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            case 9:
                if (action[i] < 3 &&
                    reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) > reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(action[i] + 1))
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                if (action[i] == 2 && pRefActor && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pRefActor))->GetBaseTexture())) &&
                    ((((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pRefActor))->GetBaseTexture()))->IsHoldingWeapon() && reinterpret_cast<::FUN_008a7570_shell *>((pRefActor))->FUN_008a7570() == 2) ||
                     (m_pAttachedReference == ::_g_thePlayer && ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::ArrSI *>(&::g_011f2250))))->GetName())) == 4 &&
                      reinterpret_cast<::ListHolder *>((((VATSStub*)&(*reinterpret_cast<::ArrSI *>(&::g_011f2250)))))->FUN_009c71c0())) &&
                    reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(2) >= afPrevTimes[i])
                {
                    float fLoopTime =
                        reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(2) - reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(1);
                    while (reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) > reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(action[i]))
                    {
                        reinterpret_cast<::fnv_00a328b0::SeqExt *>((pSequence))->FUN_00a328b0(reinterpret_cast<::FUN_00493770_shell *>((pSequence))->FUN_00493770() - fLoopTime, {});
                        afPrevTimes[i] = afPrevTimes[i] - fLoopTime;
                    }
                    action[i] = (ANIM_GROUP_ACTION)(action[i] - 1);
                }
                if (DAT_011e0783 && action[i] == 1 && reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(2) >= afPrevTimes[i])
                {
                    float fLoopTime =
                        reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(2) - reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(1);
                    reinterpret_cast<::fnv_00a328b0::SeqExt *>((pSequence))->FUN_00a328b0(reinterpret_cast<::FUN_00493770_shell *>((pSequence))->FUN_00493770() + fLoopTime, {});
                    afPrevTimes[i] = afPrevTimes[i] + fLoopTime;
                    action[i] = (ANIM_GROUP_ACTION)(action[i] + 1);
                }
                if (action[i] == 3 && reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(3))
                {
                    if (iNextGroupType != 0xff)
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        reinterpret_cast<::FUN_004948c0_shell *>(this)->GetSequenceForGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                    else
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            case 2:
                while (action[i] < 3 &&
                       reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) > reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(action[i]))
                {
                    switch (action[i])
                    {
                    case 0:
                        action[i] = (ANIM_GROUP_ACTION)1;
                        break;
                    case 1:
                        action[i] = (ANIM_GROUP_ACTION)2;
                        break;
                    case 2:
                        action[i] = (ANIM_GROUP_ACTION)3;
                        break;
                    }
                }
                if (iNextGroupType != 0xff)
                {
                    if (reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(3))
                    {
                        m_acTargetName[i] = m_acAnimationName[i];
                        reinterpret_cast<::FUN_004948c0_shell *>(this)->GetSequenceForGroup(usReloadGroup[i], -1);
                        usReloadGroup[i] = iNextGroupType = 0xff;
                    }
                }
                else if (reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(2) && m_acTargetName[i])
                {
                    reinterpret_cast<::FUN_00496280_shell *>(this)->FUN_00496280();
                    action[i] = (ANIM_GROUP_ACTION)1;
                    float fLoopTime =
                        reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(2) - reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(1);
                    reinterpret_cast<::fnv_00a328b0::SeqExt *>((pSequence))->FUN_00a328b0(reinterpret_cast<::FUN_00493770_shell *>((pSequence))->FUN_00493770() - fLoopTime, {});
                    afPrevTimes[i] = afPrevTimes[i] - fLoopTime;
                    if (m_acTargetName[i] != -1 && m_acTargetName[i] < 0xff)
                        m_acTargetName[i] = m_acTargetName[i] - 1;
                }
                else if (reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(3))
                {
                    if (reinterpret_cast<::FUN_0084e3a0_Class *>((((IdleStub*)(AnimIdle*)LocalInput)))->FUN_0084e3a0() == 1)
                        reinterpret_cast<::TESRegionGrassObject *>((((IdleStub*)(AnimIdle*)LocalInput)))->AssignLandTexture((::TESLandTexture *)(3));
                    else
                        BlendOut(i, false);
                }
                break;
            case 0:
            case 1:
                if (!((void *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((pSequence))->GetCurrentMoveModeType())))
                {
                    while (action[i] < 1 &&
                           reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) > reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(action[i]))
                    {
                        switch (action[i])
                        {
                        case 0:
                            action[i] = (ANIM_GROUP_ACTION)1;
                            break;
                        case 1:
                            action[i] = (ANIM_GROUP_ACTION)1;
                            break;
                        }
                    }
                    if (iNextGroupType != 0xff)
                    {
                        if (reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(1))
                        {
                            m_acTargetName[i] = m_acAnimationName[i];
                            reinterpret_cast<::FUN_004948c0_shell *>(this)->GetSequenceForGroup(usReloadGroup[i], -1);
                            usReloadGroup[i] = iNextGroupType = 0xff;
                        }
                    }
                    else if (reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(1) && m_acTargetName[i])
                    {
                        action[i] = (ANIM_GROUP_ACTION)0;
                        float fLoopTime = reinterpret_cast<::FUN_00508100_shell *>((pSequence))->FUN_00508100() - reinterpret_cast<::FUN_00759450_shell *>((pSequence))->FUN_00759450();
                        reinterpret_cast<::fnv_00a328b0::SeqExt *>((pSequence))->FUN_00a328b0(reinterpret_cast<::FUN_00493770_shell *>((pSequence))->FUN_00493770() - fLoopTime, {});
                        if (m_acTargetName[i] != -1)
                            m_acTargetName[i] = m_acTargetName[i] - 1;
                    }
                    else if (reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(1))
                    {
                        BlendOut(i, false);
                    }
                }
                else
                {
                    if (action[i] == 0 &&
                        reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) > reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(action[i]))
                        action[i] = (ANIM_GROUP_ACTION)1;
                    if (iNextGroupType != 0xff)
                    {
                        if (reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(1))
                        {
                            if (i != 1 || (reinterpret_cast<::FUN_008846e0_shell *>((pRefActor))->GetVtbl20Result() & 0xf))
                            {
                                m_acTargetName[i] = m_acAnimationName[i];
                                reinterpret_cast<::FUN_004948c0_shell *>(this)->GetSequenceForGroup(usReloadGroup[i], -1);
                            }
                            else
                            {
                                BlendOut(i, false);
                            }
                            usReloadGroup[i] = iNextGroupType = 0xff;
                        }
                    }
                    else if (reinterpret_cast<::fnv_00493800::FUN_00493800_impl *>(this)->FUN_00493800((::fnv_00493800::BGSCameraShot *)(pSequence)) >= reinterpret_cast<::FUN_005f3780_shell *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pSequence))->GetAnimGroup()))))->FUN_005f3780(1))
                    {
                        BlendOut(i, false);
                    }
                }
                break;
            }
        }
    }

    if (m_pObjectNode)
    {
        AnimPoint3 kOld = (AnimPoint3&)m_kRootTranslation;
        bool bUseMoveData = false;
        AnimPoint3 kMoveDelta = (const AnimPoint3&)NiPoint3::ZERO;
        if (reinterpret_cast<::FUN_004938e0_shell *>((pRefActor))->FUN_004938e0())
        {
            unsigned short usMoveFlags = (unsigned short)reinterpret_cast<::FUN_008846e0_shell *>((pRefActor))->GetVtbl20Result();
            if (m_pChildTile[1] && (usMoveFlags & 0xf))
            {
                int iType = 0;
                if (reinterpret_cast<::TESAnimGroup *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(((SeqStub*)m_pChildTile[1])))->GetAnimGroup()))))->IsJumpAnimation())
                    bUseMoveData = true;
                switch (((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(((SeqStub*)m_pChildTile[1])))->GetAnimGroup()))->GetGroupType())
                {
                case 0xe3:
                    bUseMoveData = true;
                    break;
                default:
                    switch (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((m_pChildTile[1]))->GetActiveCombatTarget())))
                    {
                    case 2:
                    case 5:
                        bUseMoveData = true;
                    }
                }
                ControllerStub* pController = ((::ControllerStub *)(reinterpret_cast<::MyHost *>((((AccumRootStub*)m_pObjectNode)))->FUN_00a5c570((const ::MyRTTI *)(const ::NiRTTI *)(&(*reinterpret_cast<const ::NiRTTI *>(&::g_011f36ec))))));
                ControllerStub* pMgr = pController;
                BlendStub* pBlendInterpolator = pMgr->GetInterpolator(0);
                if (pBlendInterpolator)
                {
                    BlendStub* pBlend = pBlendInterpolator;
                    if (pBlend)
                    {
                        int iHighPriority = ::FUN_00493750((const ::FUN_00493750_Helper *)(pBlend));
                        void* pSeqInterp = ((void *)(reinterpret_cast<::fnv_004937a0::FUN_004937a0_shell *>((((SeqStub*)m_pChildTile[1])))->FUN_004937a0(0)));
                        pBlend = (BlendStub*)FUN_00653270((const NiRTTI*)&g_011f36fc, (NiObject*)pSeqInterp);
                        if (reinterpret_cast<::BSAnimGroupSequence *>((((SeqStub*)m_pChildTile[1])))->GetPriority((*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(((AccumRootStub*)m_pObjectNode)))->GetLinkToList())), 0) <
                            iHighPriority)
                            bUseMoveData = false;
                    }
                }
                if (bUseMoveData)
                {
                    if (usMoveFlags & 0x200)
                    {
                        if (usMoveFlags & 1)
                            iType = 7;
                        else if (usMoveFlags & 2)
                            iType = 8;
                        else if (usMoveFlags & 4)
                            iType = 9;
                        else if (usMoveFlags & 8)
                            iType = 10;
                    }
                    else if (usMoveFlags & 0xff00)
                    {
                        if (usMoveFlags & 1)
                            iType = 3;
                        else if (usMoveFlags & 2)
                            iType = 4;
                        else if (usMoveFlags & 4)
                            iType = 5;
                        else if (usMoveFlags & 8)
                            iType = 6;
                    }
                    if (iType == ((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(((SeqStub*)m_pChildTile[1])))->GetAnimGroup()))->GetGroupType())
                    {
                        kMoveDelta = (*(::FNV_NiPoint3_Canonical *)(reinterpret_cast<::Holder *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(((SeqStub*)m_pChildTile[1])))->GetAnimGroup()))))->GetVec({}))) *
                                     fTimeMultiplier * *((float *)&(::FUN_00403e20((float *)&(g_011c5724)))) * m_fMovementRate;
                    }
                    else
                    {
                        unsigned short usMoveGroup = reinterpret_cast<::fnv_00897910::AnimOwner *>((pRefActor))->FUN_00897910(iType, (::fnv_00897910::Equipped *)(0), 0, (::fnv_00897910::AnimData *)(0));
                        iType = GetType(usMoveGroup);
                        if (iType)
                        {
                            AnimSequenceBase* pSeqBase;
                            if (reinterpret_cast<::NiTMapBase *>((void *)(m_pOwnerReference))->Lookup(usMoveGroup, pSeqBase))
                            {
                                SeqStub* pMoveSeq = (SeqStub*)pSeqBase->GetSequenceAtIndex(-1);
                                if (pMoveSeq)
                                    kMoveDelta = (*(::FNV_NiPoint3_Canonical *)(reinterpret_cast<::Holder *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pMoveSeq))->GetAnimGroup()))))->GetVec({}))) * fTimeMultiplier *
                                                 *((float *)&(::FUN_00403e20((float *)&(g_011c5724)))) * m_fMovementRate;
                            }
                        }
                    }
                }
            }
        }
        reinterpret_cast<::fnv_0049bca0::FUN_0049bca0_shell *>(this)->FUN_0049bca0(time, &m_kRootTranslation, true);
        if (bUseMoveData)
        {
            m_kNodeTranslation.x = kMoveDelta.x;
            m_kNodeTranslation.y = kMoveDelta.y;
        }
        else
        {
            AnimPoint3 kTranslateDelta = (AnimPoint3&)m_kRootTranslation - kOld;
            m_kNodeTranslation.x = kTranslateDelta.x;
            m_kNodeTranslation.y = kTranslateDelta.y;
        }
        m_kNodeTranslation.x = reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((ActorStub*)apRef)))->FUN_00567400() * m_kNodeTranslation.x;
        m_kNodeTranslation.y = reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((ActorStub*)apRef)))->FUN_00567400() * m_kNodeTranslation.y;
        if (!bUseMoveData && !m_pChildTile[1] && m_pCurrentSequence && ((std::intptr_t)(reinterpret_cast<::LowProcess *>((m_pCurrentSequence))->GetActiveCombatTarget())))
        {
            m_kNodeTranslation.y = 0.0f;
            m_kNodeTranslation.x = 0.0f;
        }
        if (m_pCurrentSequence && !((std::intptr_t)(reinterpret_cast<::LowProcess *>((m_pCurrentSequence))->GetActiveCombatTarget())))
            m_pCurrentSequence = 0;
    }

    bTalks = false;
    if (pRefActor && ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pRefActor))->GetBaseTexture())))
        bTalks = ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(pRefActor))->GetBaseTexture()))->IsDetectionEnabled();
    if (!bTalks)
    {
        if (!reinterpret_cast<::FUN_00456630_helper *>((((AccumRootStub*)(NiNode*)m_acHeaderData)))->FUN_00456610() ||
            (this == reinterpret_cast<::PlayerCharacter *>((((PlayerStub*)::_g_thePlayer)))->GetAnimation(true) && IsVATSCameraActive()))
        {
            for (i = 0; i < 8; i++)
            {
                switch (m_cState)
                {
                case 0x17:
                    if (i != 7 && i != 0)
                        continue;
                    break;
                case 0x14:
                    continue;
                    break;
                case 0x15:
                    switch (i)
                    {
                    case 2:
                    case 3:
                    case 4:
                        continue;
                    }
                    break;
                default:
                    if (i == m_cState)
                        continue;
                }
                SeqStub* pForwardSequence = (SeqStub*)reinterpret_cast<::FUN_00491040_shell *>(this)->FUN_00491040(i);
                if (pForwardSequence && apSequences[i] == pForwardSequence &&
                    (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((pForwardSequence))->GetActiveCombatTarget())) == 1 || ((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((pForwardSequence))->GetActiveCombatTarget())) == 2 || ((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((pForwardSequence))->GetActiveCombatTarget())) == 5))
                {
                    bool bPlaySounds = true;
                    if (DAT_01199bcc[i])
                    {
                        if (m_acNodeName[i])
                        {
                            BSAnimGroupSequence* pBest = 0;
                            unsigned char ucMaxPriority = 0;
                            for (int iSection = 0; iSection < 8; iSection++)
                            {
                                if (m_pChildTile[iSection] && m_acNodeName[i] &&
                                    (const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(((BoneStub*)m_acNodeName[i])))->GetLinkToList())))
                                {
                                    unsigned char ucPriority =
                                        reinterpret_cast<::_Stub_FUN_00508d90 *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(((SeqStub*)m_pChildTile[iSection])))->GetAnimGroup()))))->method(i);
                                    if (ucPriority > ucMaxPriority)
                                    {
                                        pBest = m_pChildTile[iSection];
                                        ucMaxPriority = ucPriority;
                                    }
                                }
                            }
                            if (!pBest || pBest != pForwardSequence)
                                bPlaySounds = false;
                        }
                    }
                    else
                    {
                        bPlaySounds = false;
                    }
                    if (bPlaySounds)
                    {
                        float fNewTime = reinterpret_cast<::FUN_004eec60_shell *>((pForwardSequence))->FUN_004eec60(time);
                        if (-DAT_0101d890 != fNewTime && -DAT_0101d890 != afPrevTimes[i] && fNewTime != afPrevTimes[i])
                            reinterpret_cast<::FUN_005f2b60_cls *>((((::AnimGroupInfoStub *)(reinterpret_cast<::BSAnimGroupSequence *>((void *)(pForwardSequence))->GetAnimGroup()))))->ProcessSoundEntries((::Ref *)(apRef), afPrevTimes[i], fNewTime, (::Script *)(pForwardSequence));
                    }
                }
            }
        }
    }

    if (LocalInput)
        reinterpret_cast<::FUN_00497040_shell *>((((IdleStub*)(AnimIdle*)LocalInput)))->FUN_00497040(this);
    if (m_cSkipNextBlend)
        m_cSkipNextBlend = 0;
    m_cState = -1;
}
// @fnv 0x00497ca0
void FUN_00497ca0_shell::FUN_00497ca0(TESIdleForm* a1, int a2)
{
    AutoMemContext ctx(MEM_CONTEXT_MEM_CONTEXT_ANIMATION, true, DAT_0101d930, 4701);
    if (LocalInput)
    {
        int section = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((LocalInput).operator->()))->FUN_00825c00()));
        switch (section)
        {
        case 21:
            section = 4;
            break;
        case 20:
            section = 1;
            break;
        }
        if (reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalInput).operator->()))->FUN_00490e40())
        {
            if (m_pChildTile[section] == reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalInput).operator->()))->FUN_00490e40())
            {
                switch (((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalInput).operator->()))->FUN_00490e40()))->GetActiveCombatTarget())))
                {
                case 2:
                case 5:
                    Warning(DAT_0101dd28, (const char*)(*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>(((LocalInput).operator->()))->FUN_00490e40()))->GetLinkToList())));
                    return;
                default:
                    break;
                }
                BlendOut(((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((LocalInput).operator->()))->FUN_00825c00())), false);
            }
        }
        if (!LocalOutput[0])
        {
            LocalOutput[0] = LocalInput;
            LocalInput = 0;
        }
        else if (!LocalOutput[1])
        {
            LocalOutput[1] = LocalInput;
            LocalInput = 0;
        }
        else
        {
            reinterpret_cast<::Target *>(this)->RemoveItemFromMap((::Ref *)&(LocalInput));
        }
    }
    LocalInput = (AnimIdle*)new AnimIdleStub(a1, a2, 1, (Actor*)m_pAttachedReference, 0, 0);
}
// Looks up the map entry for the node's key, clears the matching value slot, updates current and the ref, then removes and deletes the item.
// @fnv 0x00498670
void Target::RemoveItemFromMap(Ref* apRef)
{
    Node* world = ((::Node *)(::fnv_006fa820::FUN_006fa820((const char *)(((::Node *)(::FUN_00559450((int *)(apRef))))))));
    Item* item5 = 0;
    unsigned short key5 = 255;
    Ref hold3(0);
    if (world && ((::Node *)(reinterpret_cast<::TESRegionDataMap *>((world))->GetRegionMapName())))
    {
        key5 = reinterpret_cast<::FUN_0047d3b0_shell *>((((::Node *)(reinterpret_cast<::TESRegionDataMap *>((world))->GetRegionMapName()))))->FUN_0047d3b0();
        reinterpret_cast<::NiTMapBase *>((map))->Lookup(key5, (::AnimSequenceBase *&)(item5));
        if (item5 && item5->v4(-1) != ((void *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((::Node *)(::FUN_00559450((int *)(apRef))))))->FUN_00490e40())))
        {
            item5 = 0;
        }
        else
        {
            if (values[reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((::Node *)(::FUN_00559450((int *)(apRef))))))->FUN_00825c00()] == ((void *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((::Node *)(::FUN_00559450((int *)(apRef))))))->FUN_00490e40())))
                reinterpret_cast<::fnv_00496080::FUN_00496080_shell *>(this)->FUN_00496080(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((::Node *)(::FUN_00559450((int *)(apRef))))))->FUN_00825c00(), 0.0f);
        }
    }
    if (!item5)
        hold3.FUN_0066b0d0(((void *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((::Node *)(::FUN_00559450((int *)(apRef))))))->FUN_00490e40())));
    if (!flag)
    {
        if (item5)
        {
            if (item5->v4(-1) == current)
                current = 0;
            reinterpret_cast<::CtrlSeqOwner *>((((::Node *)(::FUN_00559450((int *)&(ref))))))->ReleaseObject((::NiRefObject *)(void *)(item5->v4(-1)));
        }
        else if (((::Node *)(::FUN_00559450((int *)&(hold3)))))
        {
            if (reinterpret_cast<::_FUN_00822510_Class *>(&(hold3))->operator==((std::intptr_t)(current)))
                current = 0;
            reinterpret_cast<::CtrlSeqOwner *>((((::Node *)(::FUN_00559450((int *)&(ref))))))->ReleaseObject((::NiRefObject *)(void *)(((::Node *)(::FUN_00559450((int *)&(hold3))))));
        }
    }
    ::fnv_00496a50::Target496::DetachObjectModels((::fnv_00496a50::Data496 *)(::Node *)(((::Node *)(::FUN_00559450((int *)(apRef))))));
    apRef->FUN_0066b0d0(0);
    if (item5)
    {
        reinterpret_cast<::FUN_0049c250_shell *>((map))->FUN_0049c250(key5);
        delete item5;
        item5 = 0;
    }
    if (!((::Node *)(::FUN_00559450((int *)&(hold3)))) && !item5)
        reinterpret_cast<::FUN_0049c250_shell *>((map))->FUN_0049c250(key5);
}

namespace fnv_00494390 {
struct MotionPoint
{
    float x, y, z;
};
struct MotionMatrix
{
    float m[3][3];
};
struct MotionRoot
{
};
struct RootHandle
{
    MotionRoot* value;
};
struct MotionGroup
{
    int FUN_005f2420();
};
struct MotionSequence
{
};
struct TimeGlobal
{
};
struct MotionActor
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
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
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual int getType();
    virtual void slot134();
    virtual bool disabled();
};
struct MovementAnimation
{
    unsigned int flags;
    MotionActor* owner;
    RootHandle root;
    void* accumRoot;
    MotionPoint movement, accumTranslation;
    void* soundBones[8];
    float looking;
    unsigned short groups[8];
    int actions[8], loops[8];
    unsigned short nextGroups[8];
    int m_acAnimationName[8];
    char skip, shutdown, unkce, unkcf;
    float time, lipTime;
    void* manager;
    void* sequenceMap;
    MotionSequence* sequences[8];
    MotionSequence* lastMovement;
    BSSimpleList<KFModel*> models;
    float moveSpeed, attackSpeed, globalTimeMultiplier;
    bool GetMovement(MotionPoint*, MotionActor*, bool, bool);
};
// Builds a movement vector, limits its components under a sequence condition, optionally removes Z, and rotates it.
// @fnv 0x00494390
bool MovementAnimation::GetMovement(MotionPoint* apMovement, MotionActor* actor, bool rotate, bool removeZ)
{
    float alternate, speed2, limitVal, scale4;
    if (!((::fnv_00494390::MotionRoot *)(::FUN_00559450((int *)&(root)))))
        return false;
    float deltaTime7 = ::fnv::timer::Seconds() * globalTimeMultiplier;
    const MotionPoint zero3 = (*reinterpret_cast<const ::fnv_00494390::MotionPoint *>((void *)&::NiPoint3::ZERO));
    MotionPoint origin3 = zero3;
    MotionPoint delta3 = movement;
    MotionMatrix rotation5 = (*(const ::fnv_00494390::MotionMatrix *)(::FUN_006a9540((char *)(((::fnv_00494390::MotionRoot *)(::FUN_00559450((int *)&(root))))))));
    if (!actor->disabled() && reinterpret_cast<::FUN_004938e0_shell *>((actor))->FUN_004938e0() && sequences[1] &&
        ((::fnv_00494390::MotionGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((sequences[1]))->GetAnimGroup()))->FUN_005f2420() >= 3 && ((::fnv_00494390::MotionGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((sequences[1]))->GetAnimGroup()))->FUN_005f2420() <= 16)
    {
        speed2 = reinterpret_cast<::TESAnimGroup *>((((::fnv_00494390::MotionGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((sequences[1]))->GetAnimGroup()))))->GetAnimationSpeed() * moveSpeed * deltaTime7 * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((owner))->FUN_00567400();
        if (sequences[4] && ((int)(std::uintptr_t)(reinterpret_cast<::LowProcess *>((sequences[4]))->GetActiveCombatTarget())) == 1)
        {
            alternate = reinterpret_cast<::TESAnimGroup *>((((::fnv_00494390::MotionGroup *)(reinterpret_cast<::BSAnimGroupSequence *>((sequences[4]))->GetAnimGroup()))))->GetAnimationSpeed() * attackSpeed * deltaTime7 * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((owner))->FUN_00567400();
            if (alternate > speed2)
                speed2 = alternate;
        }
        limitVal = speed2 * 4.0;
        if (speed2 > 0.0)
        {
            if (delta3.x > limitVal)
                delta3.x = speed2;
            if (delta3.y > limitVal)
                delta3.y = speed2;
            if (delta3.z > limitVal)
                delta3.z = speed2;
            if (delta3.x < -limitVal)
                delta3.x = -speed2;
            if (delta3.y < -limitVal)
                delta3.y = -speed2;
            if (delta3.z < -limitVal)
                delta3.z = -speed2;
        }
    }
    if (actor)
    {
        switch (actor->getType())
        {
        case 3:
        case 5:
        case 8:
        case 10: {
            scale4 = reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((actor))->FUN_00567400();
            delta3.x /= scale4;
            delta3.y /= scale4;
            break;
        }
        default:
            break;
        }
    }
    if (removeZ)
        delta3.z = 0.0f;
    if (rotate)
        ::FUN_00a582f0((const float *)(const ::fnv_00494390::MotionMatrix *)(&rotation5), (const float *)(const ::fnv_00494390::MotionPoint *)(&origin3), 1, (const ::Point314 *)(const ::fnv_00494390::MotionPoint *)(&delta3), (::Point314 *)(apMovement));
    else
        *apMovement = delta3;
    return true;
}
}  // namespace fnv_00494390

namespace fnv_00494740 {
struct TESAnimGroup
{
    static int GetType(unsigned short);
};
struct AnimGroupInfo
{
    const char* pName;
    bool bVariants;
    int m_iSectionIndex;
    int eKeyType;
    int iFlags;
    int iBlend;
    int iBlendIn;
    int iBlendOut;
    int iSoundPriority;
};
struct SeqIface;
struct FUN_004948c0_shell
{
};
struct FUN_0049bca0_t
{
};
struct FUN_00494740_t : public Animation
{
    BSAnimGroupSequence* FUN_00494740(unsigned short asNewGroup, int aeFlags, int aiLoops, int aeSection);
};

// Resolves the group type and section, then updates stored group data or retrieves a sequence according to key type and flags.
// @fnv 0x00494740
BSAnimGroupSequence* FUN_00494740_t::FUN_00494740(unsigned short asNewGroup, int aeFlags, int aiLoops, int aeSection)
{
    int iGroupType = TESAnimGroup::GetType(asNewGroup);
    int esection = aeSection == -1 ? (*reinterpret_cast<fnv_00494740::AnimGroupInfo (*)[]>(&::DAT_011977d8))[iGroupType].m_iSectionIndex : aeSection;
    BSAnimGroupSequence* pretSeq = 0;
    switch (esection)
    {
    case 0x14:
        esection = 1;
        break;
    case 0x15:
        esection = 4;
        break;
    }
    if (iGroupType == 0xff)
        return pretSeq;
    switch ((*reinterpret_cast<fnv_00494740::AnimGroupInfo (*)[]>(&::DAT_011977d8))[iGroupType].eKeyType)
    {
    case 0:
    case 1:
    case 2:
        switch (aeFlags)
        {
        case 0:
            usReloadGroup[esection] = asNewGroup;
            m_acAnimationName[esection] = aiLoops;
            break;
        case 1:
            usReloadGroup[esection] = 0xff;
            m_acTargetName[esection] = aiLoops;
            pretSeq = (BSAnimGroupSequence*)((::fnv_00494740::SeqIface *)(reinterpret_cast<::FUN_004948c0_shell *>((((FUN_004948c0_shell*)this)))->GetSequenceForGroup(asNewGroup, aeSection)));
            reinterpret_cast<::fnv_0049bca0::FUN_0049bca0_shell *>((((FUN_0049bca0_t*)this)))->FUN_0049bca0(time, (::NiPoint3 *)(false), true);
            break;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        pretSeq = (BSAnimGroupSequence*)((::fnv_00494740::SeqIface *)(reinterpret_cast<::FUN_004948c0_shell *>((((FUN_004948c0_shell*)this)))->GetSequenceForGroup(asNewGroup, aeSection)));
        reinterpret_cast<::fnv_0049bca0::FUN_0049bca0_shell *>((((FUN_0049bca0_t*)this)))->FUN_0049bca0(time, (::NiPoint3 *)(false), true);
        break;
    }
    return pretSeq;
}
}  // namespace fnv_00494740

namespace fnv_00495be0 {
struct BoneStub
{
    const NiFixedString& GetName() const;
};

struct SeqStub : public BSAnimGroupSequence
{
};

int __cdecl GetType(unsigned short asGroup);

struct PriorityAnimation : public Animation
{
    bool IsHighestPriority();
};

// Returns true if the sequence in slot 1 has the highest priority among all active sequences for the given bone name.
// @fnv 0x00495be0
bool PriorityAnimation::IsHighestPriority()
{
    if (!m_pChildTile[1])
        return false;
    if (!m_acNodeName[1])
        return false;
    const char* name = (*(const ::NiFixedString *)(reinterpret_cast<::TESTopicInfoData *>((void *)(((BoneStub*)m_acNodeName[1])))->GetLinkToList()));
    switch (GetType(group[1]))
    {
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14: {
        BSAnimGroupSequence* best = 0;
        unsigned char maxPriority = 0;
        for (int section = 0; section < 8; section++)
        {
            if (m_pChildTile[section])
            {
                unsigned char priority = reinterpret_cast<::BSAnimGroupSequence *>((((SeqStub*)m_pChildTile[section])))->GetPriority(name, 0);
                if (priority > maxPriority)
                {
                    best = m_pChildTile[section];
                    maxPriority = priority;
                }
                else if (priority == maxPriority && section == 1)
                {
                    best = m_pChildTile[section];
                    maxPriority = priority;
                }
            }
        }
        if (best == m_pChildTile[1])
            return true;
        break;
    }
    }
    return false;
}
}  // namespace fnv_00495be0

namespace fnv_00497180 {
namespace save497 {
struct S49Obj
{
};
struct S49Checker
{
    virtual void z_000();
    virtual void z_001();
    virtual void z_002();
    virtual void z_003();
    virtual void z_004();
    virtual void z_005();
    virtual char Check18(S49Obj* obj);
};
struct S49Result
{
};
struct S49Key
{
    int FUN_005f2420();
};
struct S49Base
{
};
struct S49Map
{
};
template <class T> struct S49Ptr
{
    T* p;
    T* FUN_00559450();
};
struct S49Save
{
};
struct S49Entry
{
    int unk00;
    int unk04;
    int iA;
    int iB;
    S49Ptr<S49Base> kBase;
    int iC;
    S49Ptr<S49Obj> kObj;
    void FUN_00497180(float value, S49Map* map);
};
}
using namespace save497;
extern S49Save* DAT_011de45c;

// Writes iA, iB, iC, and an object flag; if an object exists, writes a checker result or -1, then calls kObj's FUN_004efb20.
// @fnv 0x00497180
void S49Entry::FUN_00497180(float value, S49Map* map)
{
    bool bHasObj;
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00497180::save497::S49Save * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&iA, 4);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00497180::save497::S49Save * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&iB, 4);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00497180::save497::S49Save * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&iC, 4);
    bHasObj = false;
    if (((::fnv_00497180::save497::S49Obj *)(::FUN_00559450((int *)&(kObj)))))
    {
        bHasObj = true;
    }
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00497180::save497::S49Save * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&bHasObj, 1);
    if (bHasObj)
    {
        char cCheckResult = -1;
        S49Checker* pChecker;
        if (reinterpret_cast<::NiTMapBase *>((((::fnv_00497180::save497::S49Result *)(reinterpret_cast<::FUN_00497280_shell *>((map))->GetFieldAt124()))))->Lookup({}, *(::AnimSequenceBase * *)nullptr))
        {
            cCheckResult = pChecker->Check18(((::fnv_00497180::save497::S49Obj *)(::FUN_00559450((int *)&(kObj)))));
        }
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_00497180::save497::S49Save * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&cCheckResult, 1);
        reinterpret_cast<::fnv_004efb20::FUN_004efb20_shell *>((((::fnv_00497180::save497::S49Obj *)(::FUN_00559450((int *)&(kObj))))))->FUN_004efb20(value);
    }
}
}  // namespace fnv_00497180

// Calls the virtual destructor of the object and frees its memory when the low bit of flags is set, returning the original pointer.
// @fnv 0x0048ef60
void* FUN_0048ef60(void* apThis, unsigned int flags)
{
    struct FUN_0048ef40_shell
    {
        virtual ~FUN_0048ef40_shell()
        {}
    };
    FUN_0048ef40_shell* self = static_cast<FUN_0048ef40_shell*>(apThis);
    self->~FUN_0048ef40_shell();
    if (flags & 1)
        ::FUN_00401030(apThis);
    return apThis;
}

namespace fnv_004965d0 {
extern "C" char DAT_0101dcd8;

struct ItemPad4965
{
    virtual void p0();
    char pad[20];
};
struct ItemBase4965
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* v5();
};
struct Item4965 : ItemPad4965, ItemBase4965
{
};
struct Container4965
{
};
struct Loader4965
{
};
struct Manager4965
{
};
struct Anim4965
{
};
struct Actor4965
{
    void** vtable;
};
struct StrMem
{
    void* data;
    unsigned length;
    StrMem();
    ~StrMem();
};

struct Base4965
{
    virtual void bvfn();
    Base4965();
    ~Base4965();
};
struct RefKF4965
{
    void* p;
    RefKF4965(void*);
    ~RefKF4965();
};
struct RefSol4965
{
    void* p;
    RefSol4965();
    RefSol4965(void*);
    ~RefSol4965();
    void Reset(void*);
};

struct FUN_004965d0 : Base4965
{
    FUN_004965d0(Item4965*, void*, void*, Actor4965*, bool, int);
    virtual void vfn();
    char pad4[4];
    int ready;
    void* fieldc;
    RefKF4965 model;
    void* field14;
    RefSol4965 solution;
    Item4965* items[2];
    RefSol4965 sols[2];
    Item4965* source;
    int field30;
    Actor4965* actor;
};

// Initializes item model and solution refs, loads KF model via idle or direct load, and adds objects to palette if model is valid.
// @fnv 0x004965d0
FUN_004965d0::FUN_004965d0(Item4965* apItem, void* apField14, void* apFieldC, Actor4965* apActor, bool abLoadDirect,
                           int aiField30)
    : model(0), solution(0), sols()
{
    solution.Reset(0);
    field14 = apField14;
    fieldc = apFieldC;
    source = apItem;
    for (int i = 0; i < 2; ++i)
    {
        items[i] = (Item4965*)((void *)(reinterpret_cast<::TESDataHandler *>(((*(Container4965**)&::fnv_004994f0::DAT_011c3f2c)))->FindNthMatchingItem(apItem, i)));
        sols[i].Reset(0);
    }
    field30 = aiField30;
    actor = apActor;
    StrMem strModelPath;
    ::FUN_00406f60((::FUN_00406f90_this *)(void *)(&strModelPath), &DAT_0101dcc4, &(*reinterpret_cast<char *>((void *)&::kMeshesFolder)), static_cast<fnv_004965d0::ItemBase4965 *>(apItem)->v5());
    if (!abLoadDirect)
    {
        reinterpret_cast<::NiPointer_KFModel *>(&(model))->FUN_0044b070((::KFModel *)(void *)(reinterpret_cast<::FUN_00445200_holder *>(((*(Loader4965**)&(*reinterpret_cast<char *>(&::g_modelLoader)))))->InsertIdle(((void *)(::FUN_00559450((int *)&(strModelPath)))), this, 0, apActor)));
    }
    else
    {
        reinterpret_cast<::NiPointer_KFModel *>(&(model))->FUN_0044b070((::KFModel *)(void *)(((void *)(reinterpret_cast<::fnv_004471c0::FUN_004471c0_shell *>(((*(Loader4965**)&(*reinterpret_cast<char *>(&::g_modelLoader)))))->LoadKFModel((char *)(void *)(((void *)(::FUN_00559450((int *)&(strModelPath))))))))));
    }
    if (((void *)(::FUN_00559450((int *)&(model)))))
    {
        for (int j = 0; j < 2; ++j)
        {
            if (items[j] && apActor)
            {
                sols[j].Reset(((void *)(::FUN_004aeed0((::TESForm *)(items[j]), (::TESModel *)(void *)((ItemBase4965*)items[j]), -1, (::TESObjectREFR *)(apActor), (::NiAVObject *)(0)))));
                void* manager = ((void *)(::fnv_00537bd0::GetStringAtOffset((const char *)(((::fnv_004965d0::Manager4965 *)(reinterpret_cast<::fnv_00496940::FUN_00496940_shell *>(((((Anim4965 * (*)(Actor4965*)) apActor->vtable[121])(apActor))))->FUN_00496940()))))));
                void* pointer = manager;
                ::AddObjectToPalette((::NiAVObject *)(void *)(((void *)(::FUN_00559450((int *)&(sols[j]))))), (::NiDefaultAVObjectPalette *)(pointer));
                reinterpret_cast<::FUN_00496960_shell *>((apActor))->SetByteAt14E(true);
            }
        }
        if (!abLoadDirect)
            ::FUN_0043be10((char *)(void *)(((void *)(::FUN_00559450((int *)&(model))))));
        ready = 1;
    }
    else
    {
        ready = 0;
    }
}
}  // namespace fnv_004965d0

namespace fnv_004975e0 {
class TESForm;

struct SaveFormInfo
{
    unsigned int refID;
};

struct SaveLoadGame
{
};

struct BoolSetting
{
    unsigned char* Bool();
};

struct SaveRef
{
};

struct SaveForm
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
    virtual const char* GetDescription();
};

struct SavedAnim
{
    SaveRef* GetTarget();
};

void LogWarning(const char* apFormat, ...);

// Writes the animation save block to the save buffer, including the target refID, save group, and animation state, then patches the block size.
// @fnv 0x004975e0
void FUN_004975e0(void* apUnused, SavedAnim* apAnim, std::intptr_t aiState, float afTime)
{
    unsigned short usBlockSize4 = 0;
    char* pSizePos8 = 0;
    char* pStart4 = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
    if (*(*reinterpret_cast<::fnv_004975e0::BoolSetting *>(&::g_011de4e8)).Bool())
        pStart4 = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        int iTag5 = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&iTag5, 4);
        pSizePos8 = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&usBlockSize4, 2);
    }
    unsigned int uiRefID4 = 0;
    if (apAnim && ((::fnv_004975e0::SaveRef *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((apAnim))->GetIconFormID())))
        uiRefID4 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::fnv_004975e0::SaveRef *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((apAnim))->GetIconFormID()))))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(void *)(&uiRefID4), 4);
    if (uiRefID4)
    {
        unsigned short usGroup = reinterpret_cast<::fnv_00497100::FUN_00497100_shell *>((apAnim))->FUN_00497100();
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&usGroup, 2);
        reinterpret_cast<::fnv_00497180::save497::S49Entry *>((apAnim))->FUN_00497180(afTime, (::fnv_00497180::save497::S49Map *)(aiState));
    }
    if (*(*reinterpret_cast<::fnv_004975e0::BoolSetting *>(&::g_011de4e8)).Bool())
    {
        char* pEnd6 = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
        SaveFormInfo* pInfo2 = ((::fnv_004975e0::SaveFormInfo *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (pInfo2)
        {
            SaveForm* pForm = ((::fnv_004975e0::SaveForm *)(::FUN_004839c0(pInfo2->refID)));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        char* pCur5 = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::fnv_004975e0::SaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_00825c00()));
        {
            char* pSize4 = pSizePos8;
            if (pCur5 > pSize4 + 0xffff)
                LogWarning("SAVELOAD: Save Game Block in file %s on line %i is greater than maximum short size",
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Animation.cpp", 0x120e);
            *(unsigned short*)pSizePos8 = pCur5 - pSize4;
        }
    }
}
}  // namespace fnv_004975e0

// May free an idle, add a model, obtain a sequence, and pass it to an idle method.
// @fnv 0x00498290
bool AnimationAccess::FUN_00498290()
{
    if ((AnimIdle*)LocalStateValue)
    {
        if (((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalStateValue)))->GetName())) == 1)
            SpecialIdleFree(false, true);
        else
            return false;
    }
    if ((AnimIdle*)LocalInput && ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->GetName())) == 1)
    {
        IdleModelAccess* pkModel = ((::IdleModelAccess *)(::fnv_006fa820::FUN_006fa820((const char *)(static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))));
        if (pkModel && reinterpret_cast<::Anim490 *>(this)->AddModel((::Model490 *)(pkModel), false) && ((::IdleAnimGroupAccess498 *)(reinterpret_cast<::TESRegionDataMap *>((pkModel))->GetRegionMapName())))
        {
            BSAnimGroupSequence* pkSequence = 0;
            if (!((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->FUN_00825c00())) &&
                ((::IdleAnimGroupAccess498 *)(reinterpret_cast<::TESRegionDataMap *>((((::IdleModelAccess *)(::fnv_006fa820::FUN_006fa820((const char *)(static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))))))->GetRegionMapName()))->FUN_005f2420() ==
                    1)
            {
                pkSequence = reinterpret_cast<::fnv_00494740::FUN_00494740_t *>(this)->FUN_00494740(((::IdleAnimGroupAccess498 *)(reinterpret_cast<::TESRegionDataMap *>((pkModel))->GetRegionMapName()))->FUN_005f2420(), 1, -1,
                                          ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->FUN_00825c00())));
            }
            else
            {
                pkSequence =
                    reinterpret_cast<::fnv_00494740::FUN_00494740_t *>(this)->FUN_00494740(((::IdleAnimGroupAccess498 *)(reinterpret_cast<::TESRegionDataMap *>((pkModel))->GetRegionMapName()))->FUN_005f2420(), 1,
                                 ((unsigned char)(reinterpret_cast<::FUN_005ff770_shell *>((((::TESIdleForm *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->GetIconFormID()))))->GetRandomValue())),
                                 ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->FUN_00825c00())));
            }
            if (pkSequence)
            {
                if (reinterpret_cast<::FUN_004d8a00_Class *>((((::TESIdleForm *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->GetIconFormID()))))->GetField3C() > 0.0)
                {
                    IdleReplayDelayAccess498* pDelay = new IdleReplayDelayAccess498;
                    pDelay->idle = ((::TESIdleForm *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->GetIconFormID()));
                    pDelay->delay = reinterpret_cast<::FUN_004d8a00_Class *>((((::TESIdleForm *)(std::uintptr_t)(reinterpret_cast<::BGSMessageInitAccess *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->GetIconFormID()))))->GetField3C();
                    reinterpret_cast<::Callees *>(&(m_acTrailingData))->FUN_00905820((void *)&(reinterpret_cast<IdleReplayDelayEntry*&>(pDelay)));
                }
                reinterpret_cast<::fnv_00496fe0::FUN_00496fe0_cls *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->FUN_00496fe0((::NiNode *)(pkSequence));
                return true;
            }
            else
            {
                reinterpret_cast<::TESRegionGrassObject *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->AssignLandTexture((::TESLandTexture *)(3));
                if (reinterpret_cast<::FUN_0084e3a0_Class *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->FUN_0084e3a0() == 2 ||
                    reinterpret_cast<::FUN_0084e3a0_Class *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->FUN_0084e3a0() == 3)
                    SpecialIdleFree(true, false);
            }
        }
        else
        {
            reinterpret_cast<::TESRegionGrassObject *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->AssignLandTexture((::TESLandTexture *)(3));
            if (reinterpret_cast<::FUN_0084e3a0_Class *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->FUN_0084e3a0() == 2 ||
                reinterpret_cast<::FUN_0084e3a0_Class *>((static_cast<AnimIdleAccess*>((AnimIdle*)LocalInput)))->FUN_0084e3a0() == 3)
                SpecialIdleFree(true, false);
        }
    }
    return false;
}

// Iterates m_pSingleSequence's list and returns the first BSAnimGroupSequence whose group matches apAnimGroup, or null.
// @fnv 0x0048f790
BSAnimGroupSequence* AnimSequenceMultiple::FUN_0048f790(TESAnimGroup* apAnimGroup)
{
    void* listIt;
    listIt = (void*)((std::uintptr_t)(::FUN_00559450((int *)(m_pSingleSequence))));
    while (listIt != 0)
    {
        BSAnimGroupSequence* pseq;
        pseq = *(BSAnimGroupSequence**)((FUN_006317a0_struct*)m_pSingleSequence)->AddEight((std::intptr_t)listIt);
        if (reinterpret_cast<::BSAnimGroupSequence *>((void *)(pseq))->GetAnimGroup() == apAnimGroup)
            return pseq;
        listIt = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((void *)(((NiTPointerList_SV<TESObjectREFR*>*)m_pSingleSequence)))->DereferenceIfNotNull((int **)(listIt))));
    }
    return 0;
}

#include "generated/data/fallout_shared/animation.inc"
