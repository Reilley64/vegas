// fallout/ai/movement/detailedactorpathhandler.cpp: std, DetailedActorPathHandler, DetailedActorPathHandlerEx, DelStandIn and more (73 functions)

#include <new>
#include "fnv/decl/ActorMoverBuildPath14.h"
#include "fnv/decl/ActorMoverLocation14.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CpuObject.h"
#include "fnv/decl/DoorAccessData.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004938e0_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_00494710_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00505c00_shell.h"
#include "fnv/decl/FUN_00507e10_shell.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f0c80_shell.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00632ce0_Class.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_00692480.h"
#include "fnv/decl/FUN_006a9520_Class.h"
#include "fnv/decl/FUN_006b05d0_shell.h"
#include "fnv/decl/FUN_006cd650_shell.h"
#include "fnv/decl/FUN_006d3ac0_Class.h"
#include "fnv/decl/FUN_006deeb0_cls.h"
#include "fnv/decl/FUN_006e2330_shell.h"
#include "fnv/decl/FUN_006e2bb0_shell.h"
#include "fnv/decl/FUN_006e78b0_shell.h"
#include "fnv/decl/FUN_006e7970_shell.h"
#include "fnv/decl/FUN_0072ba80_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_007ff8e0_shell.h"
#include "fnv/decl/FUN_00810660_Class.h"
#include "fnv/decl/FUN_00819a50_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_0087eeb0_shell.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_008846e0_shell.h"
#include "fnv/decl/FUN_0088b0f0_Class.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_00897b50_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008b3c50_Class.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_008e7c50_cls.h"
#include "fnv/decl/FUN_00905450_StandIn.h"
#include "fnv/decl/FUN_00931d90_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009dd130_shell.h"
#include "fnv/decl/FUN_009e16c0_Class.h"
#include "fnv/decl/FUN_009e99a0_cls.h"
#include "fnv/decl/FUN_009e9b20_Class.h"
#include "fnv/decl/FUN_00c6fd60_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/FnvCpu_FUN_00c89720_CpuInterface.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/Mover.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NavMeshOps.h"
#include "fnv/decl/PathingLocationProxy.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/ProcessLists.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S006950d0.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_FUN_006b05a0.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/bhkCharacterController_shell.h"
#include "fnv/decl/bhkCharacterListener.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00495be0__PriorityAnimation.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00587550__FUN_00587550_shell.h"
#include "fnv/decl/fnv_006e78d0__FUN_006e78d0_shell.h"
#include "fnv/decl/fnv_006e7a10__FUN_006e7a10_shell.h"
#include "fnv/decl/fnv_006e7e70__FUN_006e7e70_shell.h"
#include "fnv/decl/fnv_006e84b0__FUN_006e84b0_shell.h"
#include "fnv/decl/fnv_006e8680__FUN_006e7990_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_00884dc0__FUN_00884dc0_shell.h"
#include "fnv/decl/fnv_00884eb0__FUN_00884eb0_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_008a0b10__FUN_008a0b10_shell.h"
#include "fnv/decl/fnv_008ad1c0__MoveSelf454.h"
#include "fnv/decl/fnv_008b7100__LookActor.h"
#include "fnv/decl/fnv_008be420__Dd.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004f6000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c0000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00600000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006ba000.h"
#include "fnv/symbols_006d5000.h"
#include "fnv/symbols_006d9000.h"
#include "fnv/symbols_00804000.h"
#include "fnv/symbols_008b6000.h"
#include "fnv/symbols_0097f000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_009e5000.h"
#include "fnv/symbols_009e6000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01026000.h"
#include "fnv/symbols_01031000.h"
#include "fnv/symbols_01035000.h"
#include "fnv/symbols_01064000.h"
#include "fnv/symbols_0106b000.h"
#include "fnv/symbols_0107d000.h"
#include "fnv/symbols_0108b000.h"
#include "fnv/symbols_01092000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011a5000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "detailedactorpathhandler_decls.h"

// @fnv 0x009e39c0
void DetailedActorPathHandler::SetInitialPathState()
{
    m_kPathVector1 = NiPoint3::ZERO;
    ByteAndFlagState = reinterpret_cast<::FUN_009dd130_shell *>((m_pActorMover))->FUN_009dd130();
    m_fPathValue16 = 0.0f;
    pCurrentPathingSolution = (PathingSolution*)0;
    m_pPathingRequest = (PathingRequest*)0;
    m_bPathFlag5 = false;
    m_iPathValue2 = 0;
    m_pPathTargetReference = 0;
    m_iPathParameter2 = 1;
    reinterpret_cast<::FileMatchList *>(&(ActorAvoidEntryList))->RemoveAll();
    eState = 5;
}

// Copies path state fields from a previous DetailedActorPathHandler when it can transition, remapping state 3 to 4 and moving its list items.
// @fnv 0x009e3380
void DetailedActorPathHandler::TransitionFrom(ActorPathHandler* previous)
{
    if (!previous || !previous->CanTransition())
        return;

    DetailedActorPathHandler* oldPath = (DetailedActorPathHandler*)previous;
    ByteAndFlagState = oldPath->ByteAndFlagState;
    m_iPathParameter1 = oldPath->m_iPathParameter1;
    m_fPathValue10 = oldPath->m_fPathValue10;
    m_fPathValue9 = oldPath->m_fPathValue9;
    m_fPathValue5 = oldPath->m_fPathValue5;

    if (oldPath->m_iPathParameter2 == 2)
    {
        m_iPathParameter2 = 2;
        m_fPathValue4 = oldPath->m_fPathValue4;
        m_fPathValue12 = oldPath->m_fPathValue12;
    }
    else if (oldPath->m_iPathParameter2 == 3)
    {
        m_iPathParameter2 = 4;
        m_fPathValue4 = oldPath->m_fPathValue4;
        m_fPathValue12 = 0.0f;
        while (((::TESTopicInfo *)(new ((void *)&(oldPath->ActorAvoidEntryList)) ::Vec3())))
        {
            ActorAvoidEntryList.AddHead(((::TESTopicInfo *)(new ((void *)&(oldPath->ActorAvoidEntryList)) ::Vec3())));
            oldPath->ActorAvoidEntryList.RemoveHead();
        }
    }

    m_bPathFlag6 = oldPath->m_bPathFlag6;
    m_fPathValue17 = oldPath->m_fPathValue17;
    if (oldPath->m_bPathFlag5)
    {
        m_bPathFlag5 = true;
        m_kPathVector4 = oldPath->m_kPathVector4;
        m_kPathVector3 = oldPath->m_kPathVector3;
    }
}

struct NP_009e03e0
{
    void* p;
    NP_009e03e0& operator=(void*);
};
struct Base_009e03e0
{
    char pad[8];
    virtual ~Base_009e03e0();
};
struct List_009e03e0
{
    char pad[8];
    ~List_009e03e0();
};
struct FUN_009e03e0 : Base_009e03e0
{
    NP_009e03e0 spA;
    NP_009e03e0 spB;
    char pad2[0x44];
    List_009e03e0 list;
    ~FUN_009e03e0();
};
// @fnv 0x009e03e0
FUN_009e03e0::~FUN_009e03e0()
{
    spA = 0;
    spB = 0;
    reinterpret_cast<::FileMatchList *>(&(list))->RemoveAll();
}

struct FUN_009e1640_shell : public DetailedActorPathHandler
{
    void SetRotationMatrix(float);
};

void __cdecl FUN_00639730(float, float*, float*);

// Computes sin/cos of the angle and writes a 3x3 rotation matrix into the object's first nine floats.
// @fnv 0x009e1640
void FUN_009e1640_shell::SetRotationMatrix(float afAngle)
{
    float fSin;
    float fCos;
    FUN_00639730(afAngle, &fSin, &fCos);

    ((float*)this)[0] = fCos;
    ((float*)this)[1] = fSin;
    ((float*)this)[2] = 0.0f;
    ((float*)this)[3] = -fSin;
    ((float*)this)[4] = fCos;
    this->unk14 = 0.0f;
    this->unk18 = 0.0f;
    this->m_kPathVector1.x = 0.0f;
    this->m_kPathVector1.y = 1.0f;
}

namespace fnv_009e27e0 {
struct FUN_009e27e0_shell : public DetailedActorPathHandler
{
    bool FUN_009e27e0();
};

template <typename T> struct BSStringT
{
    operator const T*() const;
};

struct PathingRequest
{
};


// @fnv 0x009e27e0
bool FUN_009e27e0_shell::FUN_009e27e0()
{
    this->unk14 = 10.0f;
    this->unk18 = 20.0f;
    this->unk18 =
        ::GetFloatAtOffset68((const char *)(((PathingRequest*)(const char*)(*(BSStringT<char>*)((char*)this + 0x10)))));
    this->unk14 = this->unk18 * ::DAT_01011588;
    return false;
}
}  // namespace fnv_009e27e0

// @fnv 0x009e32d0
int GetField38(char* this_ptr)
{
    return *(int*)(this_ptr + 0x38);
}

struct FUN_009e32f0_shell : public DetailedActorPathHandler
{
    bool ConsumePendingDelta(NiPoint3*);
};

// If the flag at offset 0xe2 is set, clears it, writes the vector at offset 0x1c to aDelta and returns true; otherwise writes NiPoint3::ZERO and returns false.
// @fnv 0x009e32f0
bool FUN_009e32f0_shell::ConsumePendingDelta(NiPoint3* aDelta)
{
    if (this->m_bPathFlag7)
    {
        this->m_bPathFlag7 = false;
        *aDelta = this->m_kPathVector1;
        return true;
    }
    else
    {
        *aDelta = NiPoint3::ZERO;
        return false;
    }
}

struct Act_009e3520
{
};
struct S_009e3520
{
    int pad0;
    Act_009e3520* pActor;
    char pad1[0x14];
    float a;
    float speed;
    void UpdateSpeed(float scale);
};
// @fnv 0x009e3520
void S_009e3520::UpdateSpeed(float scale)
{
    if (!reinterpret_cast<::fnv_008b7100::LookActor *>((pActor))->GetLookAtPosition((::fnv_008b7100::LookPoint *)(void *)(&a)))
        speed = reinterpret_cast<::fnv_008a0b10::FUN_008a0b10_shell *>((pActor))->FUN_008a0b10() * scale;
}

struct FUN_009e5480_shell : public DetailedActorPathHandler
{
    void ResetPathState();
};

// Clears the flag at offset 0xde and sets the float at offset 0x88 to 0.0f.
// @fnv 0x009e5480
void FUN_009e5480_shell::ResetPathState()
{
    this->m_bPathFlag3 = false;
    this->m_fPathValue8 = 0.0f;
}

struct ActiveEffect;
struct Actor;
struct ActorCause;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;


struct Sky;
struct TES
{
};
struct Calendar
{
public:
    float GetGameTimeScale();
};

struct FakeProcess
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
    virtual TESObjectREFR* GetActorTargetReference();  // 74 * 4 = 0x128
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
    virtual Calendar* GetCurrentPackage();  // 159 * 4 = 0x27c
    virtual int GetPackageState();          // 160 * 4 = 0x280
};

struct FakeREFR
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
    virtual bool IsActor();  // 64 * 4 = 0x100
};

// Resolves the current process's package; if its type is 6 and the target reference is an actor, returns that actor as the follow leader, otherwise null.
// @fnv 0x009e55e0
Actor* __cdecl FUN_009e55e0(TES* apActor)
{
    FakeProcess* pprocess;
    Actor* pfollowLeader = 0;
    pprocess = (FakeProcess*)((::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture()));
    if (pprocess)
    {
        Calendar* ppack = pprocess->GetCurrentPackage();
        if (ppack)
        {
            int iPackageType = DAT_011a3ff0[((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((ppack))->FUN_009611e0()))][pprocess->GetPackageState()];
            if (iPackageType == 6)
            {
                FakeREFR* ptarget = (FakeREFR*)pprocess->GetActorTargetReference();
                if (ptarget && ptarget->IsActor())
                {
                    pfollowLeader = (Actor*)ptarget;
                }
            }
        }
    }
    return pfollowLeader;
}

struct FUN_009e7610_shell : public DetailedActorPathHandler
{
    bool TurnTowardGoalAngle(float, bool, bool);
};
// @fnv 0x009e0930
bool DetailedActorPathHandler::TurnToAngle(float angle, bool keepActorHeading)
{
    m_bPathFlag5 = false;
    eState = 5;
    m_iPathParameter1 = 3;
    m_iPathParameter2 = 1;
    m_fPathValue5 = 0.0f;
    m_fPathValue16 = 0.0f;
    m_fPathValue2 = 0.0f;
    pCurrentPathingSolution = (PathingSolution*)0;
    m_pPathingRequest = (PathingRequest*)0;
    m_bHasPathingSolution = false;
    m_bPathingRequestPending = false;
    m_fElapsedTime = 0.0f;

    if (reinterpret_cast<::FUN_009e7610_shell *>(this)->TurnTowardGoalAngle(angle, keepActorHeading, false))
    {
        eState = 6;
        return true;
    }

    eState = 5;
    return false;
}

void __cdecl WrapValueToRange(float&, float, float);

namespace std {
float __cdecl abs(float);
}

class Date
{
  public:
    ~Date();
};

union SETTING_VALUE;
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};

extern float DAT_010923e0;
extern float DAT_010923e4;

struct VCallHelper_2bc
{
    virtual void d00();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual void d64();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void d133();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void d141();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual void d159();
    virtual void d160();
    virtual void d161();
    virtual void d162();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual float v175(int);
};

// @fnv 0x009e7610
bool FUN_009e7610_shell::TurnTowardGoalAngle(float afGoalAngle, bool abForceTurn, bool abPathTransition)
{
    float fdir;
    float fabsoluteDelta;
    float fangledelta;
    float fepsilon;

    if (this->m_bHasPathingSolution)
        return false;

    if (afGoalAngle < ::_DAT_01012060)
        afGoalAngle = ::FUN_004b1500(float(afGoalAngle + 6.2831854820251465), 6.2831854820251465f);
    else if (afGoalAngle >= 6.2831854820251465)
        afGoalAngle = ::FUN_004b1500(afGoalAngle, 6.2831854820251465f);

    fangledelta = FUN_004b15e0((*reinterpret_cast<VCallHelper_2bc**>(&this->pActor))->v175(0),
                               afGoalAngle, &fdir);
    fabsoluteDelta = std::abs(fangledelta);
    fepsilon = DAT_010923dc;

    if (abForceTurn)
    {
        fepsilon = DAT_010923e4;
    }
    else if (abPathTransition &&
             (reinterpret_cast<::FUN_009dd130_shell *>(((this->m_pActorMover)))->FUN_009dd130() & 0x200))
    {
        fepsilon = DAT_010923e0;
    }

    if (fabsoluteDelta > fepsilon)
    {
        if (fdir > ::_DAT_01012060)
            this->m_bPathFlag2 = true;
        else
            this->m_bPathFlag2 = false;

        this->m_bPathFlag1 = true;
        this->m_fPathValue1 = afGoalAngle;
        WrapValueToRange(this->m_fPathValue1, -3.1415927410125732f,
                         3.1415927410125732f);

        if (!reinterpret_cast<::FUN_0087eeb0_shell *>((*reinterpret_cast<void**>(&this->pActor)))->FUN_0087eeb0())
            this->m_fPathValue11 =
                *reinterpret_cast<float*>(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting220)))));

        reinterpret_cast<::TESForm *>(((*reinterpret_cast<Date**>(&this->m_pActorMover))))->ClearData();
        return true;
    }

    return false;
}

struct FUN_009e8790_shell : public DetailedActorPathHandler
{
    void ResetMoveState();
};

// Stores the mover's preferred move mode type at offset 0x60 and resets the vectors at 0x1c and 0xa0 and the float at 0x9c to zero.
// @fnv 0x009e8790
void FUN_009e8790_shell::ResetMoveState()
{
    this->ByteAndFlagState = reinterpret_cast<::FUN_009dd130_shell *>(((this->m_pActorMover)))->FUN_009dd130();
    this->m_kPathVector1 = NiPoint3::ZERO;
    this->m_fPathValue13 = 0.0f;
    this->m_kPathVector5 = NiPoint3::ZERO;
}

namespace fnv_009e9390 {
struct ActiveEffect;
struct Actor;
struct ActorCause;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct SaveLoadFile;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct NiQuaternion;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct hkVector4;
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
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
struct FUN_009e9390_shell : public DetailedActorPathHandler
{
    void FUN_009e9390(BGSLoadFormBuffer*);
};

struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
};

// @fnv 0x009e9390
void FUN_009e9390_shell::FUN_009e9390(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_kPathVector1), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_kPathVector2), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_kPathVector3), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_kActorPosition), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_kPathVector4), 0xc);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->ByteAndFlagState), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_uiPathPointIndex), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue1), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue2), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fSplineParameter), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue5), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_iPathValue1), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue6), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue7), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue8), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue9), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue10), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue11), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue12), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue13), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue14), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue15), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue16), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue17), 4);
    if (apLoadGameBuffer->GetVersion() >= 4)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->unk14), 4);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->unk18), 4);
    }
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->eState), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_iPathParameter1), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_iPathParameter2), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_iPathValue2), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bPathFlag1), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bPathFlag2), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bPathFlag3), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bPathFlag4), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bPathFlag5), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bPathFlag7), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bPathFlag6), 1);
    if (apLoadGameBuffer->GetVersion() >= 0xc)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bHasPathingSolution), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_bPathingRequestPending), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fElapsedTime), 4);
    }
    if (apLoadGameBuffer->GetVersion() >= 0x12)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_kPathVector5), 0xc);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)&this->m_fPathValue18), 4);
    }
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)((char*)&this->m_pPathTargetReference));
    unsigned int uiFormCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
    for (unsigned int uiIndex = 0; uiIndex < uiFormCount; ++uiIndex)
    {
        const char* pForm = 0;
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&pForm));
        ((BSSimpleList<const char*>*)((char*)this + 0x58))->AddHead(pForm);
    }
}
}  // namespace fnv_009e9390

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_009e0160(unsigned int flags);
};
// Runs the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x009e0160
void* DelStandIn::FUN_009e0160(unsigned int flags)
{
    reinterpret_cast<::FUN_009e03e0 *>((((DtorStandIn*)this)))->FUN_009e03e0::~FUN_009e03e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

namespace fnv_009e0470 {
extern float DAT_01092470;

namespace std {
float __cdecl abs(float);
}

class PathingGraphNode
{
  public:
    bool IsTransitionNode();
};

class PathingSolution
{
  public:
};

class PathingRequest
{
  public:
};

template <class T> class NiPointerAccess
{
  public:
    T* operator->() const;
};

class ActorMoverEx
{
  public:
};

class NiPoint3Ex : public NiPoint3
{
  public:
    NiPoint3Ex();
    float Length() const;
};

class Actor
{
  public:
    virtual void Vfn000();
    virtual void Vfn001();
    virtual void Vfn002();
    virtual void Vfn003();
    virtual void Vfn004();
    virtual void Vfn005();
    virtual void Vfn006();
    virtual void Vfn007();
    virtual void Vfn008();
    virtual void Vfn009();
    virtual void Vfn010();
    virtual void Vfn011();
    virtual void Vfn012();
    virtual void Vfn013();
    virtual void Vfn014();
    virtual void Vfn015();
    virtual void Vfn016();
    virtual void Vfn017();
    virtual void Vfn018();
    virtual void Vfn019();
    virtual void Vfn020();
    virtual void Vfn021();
    virtual void Vfn022();
    virtual void Vfn023();
    virtual void Vfn024();
    virtual void Vfn025();
    virtual void Vfn026();
    virtual void Vfn027();
    virtual void Vfn028();
    virtual void Vfn029();
    virtual void Vfn030();
    virtual void Vfn031();
    virtual void Vfn032();
    virtual void Vfn033();
    virtual void Vfn034();
    virtual void Vfn035();
    virtual void Vfn036();
    virtual void Vfn037();
    virtual void Vfn038();
    virtual void Vfn039();
    virtual void Vfn040();
    virtual void Vfn041();
    virtual void Vfn042();
    virtual void Vfn043();
    virtual void Vfn044();
    virtual void Vfn045();
    virtual void Vfn046();
    virtual void Vfn047();
    virtual void Vfn048();
    virtual void Vfn049();
    virtual void Vfn050();
    virtual void Vfn051();
    virtual void Vfn052();
    virtual void Vfn053();
    virtual void Vfn054();
    virtual void Vfn055();
    virtual void Vfn056();
    virtual void Vfn057();
    virtual void Vfn058();
    virtual void Vfn059();
    virtual void Vfn060();
    virtual void Vfn061();
    virtual void Vfn062();
    virtual void Vfn063();
    virtual void Vfn064();
    virtual void Vfn065();
    virtual void Vfn066();
    virtual void Vfn067();
    virtual void Vfn068();
    virtual void Vfn069();
    virtual void Vfn070();
    virtual void Vfn071();
    virtual void Vfn072();
    virtual void Vfn073();
    virtual void Vfn074();
    virtual void Vfn075();
    virtual void Vfn076();
    virtual void Vfn077();
    virtual void Vfn078();
    virtual void Vfn079();
    virtual void Vfn080();
    virtual void Vfn081();
    virtual void Vfn082();
    virtual void Vfn083();
    virtual void Vfn084();
    virtual void Vfn085();
    virtual void Vfn086();
    virtual void Vfn087();
    virtual void Vfn088();
    virtual void Vfn089();
    virtual void Vfn090();
    virtual void Vfn091();
    virtual void Vfn092();
    virtual void Vfn093();
    virtual void Vfn094();
    virtual void Vfn095();
    virtual void Vfn096();
    virtual void Vfn097();
    virtual void Vfn098();
    virtual void Vfn099();
    virtual void Vfn100();
    virtual void Vfn101();
    virtual void Vfn102();
    virtual void Vfn103();
    virtual void Vfn104();
    virtual void Vfn105();
    virtual void Vfn106();
    virtual void Vfn107();
    virtual void Vfn108();
    virtual void Vfn109();
    virtual void Vfn110();
    virtual void Vfn111();
    virtual void Vfn112();
    virtual void Vfn113();
    virtual void Vfn114();
    virtual void Vfn115();
    virtual void Vfn116();
    virtual void Vfn117();
    virtual void Vfn118();
    virtual void Vfn119();
    virtual void Vfn120();
    virtual void Vfn121();
    virtual void Vfn122();
    virtual void Vfn123();
    virtual void Vfn124();
    virtual const NiPoint3* GetPos();
    virtual void Vfn126();
    virtual void Vfn127();
    virtual void Vfn128();
    virtual void Vfn129();
    virtual void Vfn130();
    virtual void Vfn131();
    virtual void Vfn132();
    virtual void Vfn133();
    virtual void Vfn134();
    virtual void Vfn135();
    virtual void Vfn136();
    virtual void Vfn137();
    virtual void Vfn138();
    virtual void Vfn139();
    virtual void Vfn140();
    virtual void Vfn141();
    virtual void Vfn142();
    virtual void Vfn143();
    virtual void Vfn144();
    virtual void Vfn145();
    virtual void Vfn146();
    virtual void Vfn147();
    virtual void Vfn148();
    virtual void Vfn149();
    virtual void Vfn150();
    virtual void Vfn151();
    virtual void Vfn152();
    virtual void Vfn153();
    virtual void Vfn154();
    virtual void Vfn155();
    virtual void Vfn156();
    virtual void Vfn157();
    virtual void Vfn158();
    virtual void Vfn159();
    virtual void Vfn160();
    virtual void Vfn161();
    virtual void Vfn162();
    virtual void Vfn163();
    virtual void Vfn164();
    virtual void Vfn165();
    virtual void Vfn166();
    virtual void Vfn167();
    virtual void Vfn168();
    virtual void Vfn169();
    virtual void Vfn170();
    virtual void Vfn171();
    virtual void Vfn172();
    virtual void Vfn173();
    virtual void Vfn174();
    virtual float GetCurrentTargetDistance(bool abInterp);
    virtual void Vfn176();
    virtual void SetFurnitureHeading(float afHeading);
};

class PathHandlerEx
{
  public:
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual int Update(float afDeltaT);
    Actor* pActor;
};

struct DetailedActorPathHandlerEx : public DetailedActorPathHandler
{
    void UpdatePathTether(float afPercentTraveled);
    int UpdatePathingGoal();
    int UpdatePathTravel(float afPercentTraveled, float afDeltaT);
};

// Resets path-travel state, computes the goal angle from the actor's position and pathing solution, and updates the handler when afDeltaT is positive.
// @fnv 0x009e0470
int DetailedActorPathHandlerEx::UpdatePathTravel(float afPercentTraveled, float afDeltaT)
{
    eState = 1;
    if (m_iPathParameter1 == 0)
        m_iPathParameter1 = 3;
    switch (m_iPathParameter2)
    {
    case 2:
    case 4:
        break;
    default:
        m_iPathParameter2 = 1;
        m_fPathValue4 = 0.0f;
        m_fPathValue12 = 0.0f;
    }
    m_kPathVector1 = NiPoint3::ZERO;
    m_bPathFlag1 = false;
    m_bPathFlag7 = false;
    m_bPathFlag3 = false;
    m_fPathValue8 = 0.0f;
    m_iPathValue1 = 0;
    m_fPathValue6 = 0.0f;
    m_fPathValue7 = 0.0f;
    m_fPathValue13 = 0.0f;
    m_kPathVector5 = NiPoint3::ZERO;
    m_kActorPosition = *((PathHandlerEx*)this)->pActor->GetPos();
    m_fPathValue15 = 0.0f;
    m_fPathValue11 = -1.0f;

    if (::GetObjectFlags((char *)((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->())) < 2)
    {
        reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
        m_bPathFlag5 = false;
        m_kPathVector3 = *((PathHandlerEx*)this)->pActor->GetPos();
        m_kPathVector4 = m_kPathVector3;
        eState = 5;
        return 5;
    }

    if (reinterpret_cast<::FUN_006b05d0_shell *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->()))->FUN_006b05d0())
    {
        m_fPathValue14 = ::g_011e0994_arg1;
    }
    else
    {
        m_fPathValue14 = ::FUN_00404010(reinterpret_cast<::PathingRequest *>(((((NiPointerAccess<PathingRequest>&)m_pPathingRequest)).operator->()))->GetCenterRadius() *
                                          reinterpret_cast<::PathingRequest *>(((((NiPointerAccess<PathingRequest>&)m_pPathingRequest)).operator->()))->GetCenterRadius(),
                                      0.1f);
        if (reinterpret_cast<::FUN_006e2330_shell *>((((::fnv_009e0470::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->()))->FUN_006b05a0()))))->FUN_006e2330())
            m_fPathValue14 = DAT_01092470;
    }
    if (((::fnv_009e0470::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->()))->FUN_006b05a0()))->IsTransitionNode())
        m_bPathFlag4 = true;

    reinterpret_cast<::fnv_009e27e0::FUN_009e27e0_shell *>(this)->FUN_009e27e0();
    bool bpathTransition = m_bPathFlag5;
    UpdatePathTether(afPercentTraveled);
    m_bHasPathingSolution = false;
    m_bPathingRequestPending = false;
    m_fElapsedTime = 0.0f;
    if (!((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((((PathHandlerEx*)this)->pActor))->FUN_00493bb0())) &&
        reinterpret_cast<::fnv_006e78d0::FUN_006e78d0_shell *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->()))->GetTotalPathLength() <
            this->unk18 &&
        !reinterpret_cast<::ActorMover *>((((ActorMoverEx*)m_pActorMover)))->HasLookAtTarget())
    {
        m_bHasPathingSolution = true;
        m_bPathingRequestPending = true;
        m_fElapsedTime = (float)::GetObjectFlags((char *)((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->()));
    }

    if (!UpdatePathingGoal())
    {
        float fgoalAngle;
        NiPoint3Ex dirVec;
        if (m_bPathFlag6 || !reinterpret_cast<::ActorMover *>((((ActorMoverEx*)m_pActorMover)))->GetLookAtTargetPosition(dirVec))
            (NiPoint3&)dirVec = m_kPathVector3;
        reinterpret_cast<::NiPoint3 *>(&(dirVec))->Subtract(*((PathHandlerEx*)this)->pActor->GetPos());
        if (reinterpret_cast<::NiPoint3 *>((void *)&(dirVec))->ComputeMagnitude() * ::DAT_0107d1b8 <= std::abs(dirVec.z))
            fgoalAngle = ((PathHandlerEx*)this)->pActor->GetCurrentTargetDistance(false);
        else
            fgoalAngle = ::GetDirectionAngle((const ::NiPoint3 *)&(dirVec));
        if (!bpathTransition)
        {
            if (afPercentTraveled == ::_DAT_01012060)
                reinterpret_cast<::FUN_009e7610_shell *>(this)->TurnTowardGoalAngle(fgoalAngle, false, bpathTransition);
            else
                ((PathHandlerEx*)this)->pActor->SetFurnitureHeading(fgoalAngle);
        }
    }

    eState = 2;
    if (afDeltaT > ::_DAT_01012060)
        return ((PathHandlerEx*)this)->Update(afDeltaT);
    return 0;
}
}  // namespace fnv_009e0470

namespace fnv_009e16e0 {
struct FUN_009e16e0_shell : public DetailedActorPathHandler
{
    int FUN_009e16e0(float);
};

struct Setting_S
{
};
struct XActor
{
};
struct PCH
{
};
struct CombatState
{
    float ProcessCoverLOSResult();
};
struct MobileObject
{
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct GlobalObject_0041a250
{
    ~GlobalObject_0041a250();
};
namespace p07 {
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3&) const;
};
}
struct FUN_00595c80_shell
{
};
struct B006815c0 : public p07::NiPoint3
{
    B006815c0();
};
struct ActorMoverLook
{
};
struct FUN_009e8790_shell
{
};
struct FUN_009e4c60_shell
{
    void UpdateLookingAngle(float, float);
};
struct FUN_009e7d70_shell
{
    float FUN_009e7d70(float);
};
struct PathHandlerStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Update(float);
};
struct ActorStub
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
    virtual const p07::NiPoint3* GetPos();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool IsPlayerRef();
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
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float GetCurrentTargetDistance(int);
    virtual void v176();
    virtual void SetFurnitureHeading(float);
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual float GetTurnSpeed();
};
namespace std {
float __cdecl abs(float);
}
struct FUN_005f0c80_shell
{
};
p07::NiPoint3 __cdecl FUN_009a8050(ActorStub*);
p07::NiPoint3 __cdecl FUN_009a88e0(ActorStub*, B006815c0);
extern double DAT_01092478;

// Runs the actor path handler's state machine, turning the actor toward its look-at target and updating move mode and timers.
// @fnv 0x009e16e0
int FUN_009e16e0_shell::FUN_009e16e0(float afDeltaT)
{
    int eresult = -1;
    bool bimmobile = reinterpret_cast<::FUN_005f0c80_shell *>((((FUN_005f0c80_shell*)((void *)(reinterpret_cast<::Actor *>((((XActor*)*(ActorStub**)&this->pActor)))->GetActorBase())))))->FUN_005f0c80();
    if (!reinterpret_cast<::FUN_0087eeb0_shell *>((*(ActorStub**)&this->pActor))->FUN_0087eeb0() && !((bool)(::GetByteAtOffset70((char *)(*(void**)&this->m_pActorMover)))) &&
        !::FUN_0097fb20((::CombatState *)(*(CombatState**)&this->m_pActorMover)))
    {
        switch (*(unsigned int*)&this->eState)
        {
        case 3:
            ((PathHandlerStub*)this)->Update(afDeltaT);
            eresult = 0;
            break;
        case 7:
            reinterpret_cast<::FUN_009e8790_shell *>((((FUN_009e8790_shell*)this)))->ResetMoveState();
            *(unsigned int*)&this->eState = 5;
            eresult = 5;
            break;
        case 6:
            (*(ActorStub**)&this->pActor)->SetFurnitureHeading(((FUN_009e7d70_shell*)this)->FUN_009e7d70(afDeltaT));
            this->m_kPathVector1 = NiPoint3::ZERO;
            this->m_fPathValue13 = 0.0f;
            this->m_kPathVector5 = NiPoint3::ZERO;
            *((char*)&this->m_bPathFlag7) = 1;
            reinterpret_cast<::TESForm *>(((*(GlobalObject_0041a250**)&this->m_pActorMover)))->ClearData();
            if (!this->m_bPathFlag1)
                *(unsigned int*)&this->eState = 7;
            eresult = 0;
            break;
        case 5:
            *(NP_0081c630*)((char*)this + 0xc) = 0;
            *(NP_0081c630*)((char*)this + 0x10) = 0;
        case 0:
        case 4:
            if (!reinterpret_cast<::ActorMover *>(((*(ActorMoverLook**)&this->m_pActorMover)))->HasLookAtTarget())
            {
                this->ByteAndFlagState = reinterpret_cast<::FUN_009dd130_shell *>(((this->m_pActorMover)))->FUN_009dd130();
                eresult = 5;
            }
            break;
        }
    }
    float flookingAngle = 0.0f;
    if (eresult == -1)
    {
        if (this->m_bPathFlag6)
        {
            this->m_fPathValue17 -= afDeltaT;
            if (this->m_fPathValue17 < ::_DAT_01012060)
            {
                this->m_bPathFlag6 = false;
                eresult = 0;
            }
        }
        if (eresult == -1)
        {
            B006815c0 lookatPoint;
            if (reinterpret_cast<::ActorMover *>(((*(ActorMoverLook**)&this->m_pActorMover)))->GetLookAtTargetPosition((::NiPoint3 &)(lookatPoint)) &&
                !reinterpret_cast<::MobileObject *>((void *)(((MobileObject*)*(ActorStub**)&this->pActor)))->IsInDialogueWithPlayer())
            {
                float fCurrentAngle = ::WrapAngle((*(ActorStub**)&this->pActor)->GetCurrentTargetDistance(0));
                p07::NiPoint3 firingLocation = FUN_009a8050(*(ActorStub**)&this->pActor);
                if (reinterpret_cast<::FUN_00595c80_shell *>((void *)(((FUN_00595c80_shell*)&(firingLocation - lookatPoint))))->GetSquaredXYLength() <
                    ((CombatState*)*(ActorStub**)&this->pActor)->ProcessCoverLOSResult() *
                        ((CombatState*)*(ActorStub**)&this->pActor)->ProcessCoverLOSResult() * 0.25)
                    eresult = 0;
                if (eresult == -1)
                {
                    float fdir;
                    p07::NiPoint3 rot = FUN_009a88e0(*(ActorStub**)&this->pActor, lookatPoint);
                    float fgoalAngle = ::WrapAngle(rot.z);
                    float fgoalLookAngle = rot.x;
                    float fangleDelta;
                    if (((CombatState*)*(ActorStub**)&this->pActor)->ProcessCoverLOSResult() >= ::g_d100)
                    {
                        p07::NiPoint3 delta = lookatPoint - *(*(ActorStub**)&this->pActor)->GetPos();
                        delta.z = 0.0f;
                        fangleDelta = std::abs(::FUN_004b15e0(fCurrentAngle, ::GetDirectionAngle((const ::NiPoint3 *)&(delta)), &fdir));
                    }
                    else
                    {
                        fangleDelta = std::abs(::FUN_004b15e0(fCurrentAngle, fgoalAngle, &fdir));
                    }
                    float frotateMax = (*(ActorStub**)&this->pActor)->GetTurnSpeed() * ::DAT_01023128 * afDeltaT;
                    if (!(*(ActorStub**)&this->pActor)->IsPlayerRef())
                        frotateMax *= ((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((((PCH*)*(ActorStub**)&this->pActor)))->FUN_00493bb0())) ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e16e0::Setting_S *>(&::g_011f2ac4))))))
                                                                                                : *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e16e0::Setting_S *>(&::g_011f2ad8))))));
                    else
                        frotateMax *= ((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((((PCH*)*(ActorStub**)&this->pActor)))->FUN_00493bb0())) ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e16e0::Setting_S *>(&::g_011f2b10))))))
                                                                                                : *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e16e0::Setting_S *>(&::g_011f2c10))))));
                    float fclampedAngleDelta = fangleDelta;
                    if (fclampedAngleDelta > frotateMax)
                        fclampedAngleDelta = frotateMax;
                    unsigned int inewMoveMode = this->ByteAndFlagState;
                    if (!bimmobile && this->m_fPathValue11 > ::_DAT_01012060)
                    {
                        this->m_fPathValue11 -= afDeltaT;
                        fCurrentAngle += fclampedAngleDelta * fdir;
                    }
                    else if (fangleDelta > ::DAT_010923dc)
                    {
                        if (!bimmobile)
                            this->m_fPathValue11 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e16e0::Setting_S *>(&::originalRuntimeFloatSetting220)))))) - afDeltaT;
                        if (fdir == 1.0)
                        {
                            inewMoveMode = reinterpret_cast<::FUN_009dd130_shell *>(((this->m_pActorMover)))->FUN_009dd130() | 0x20;
                            fCurrentAngle += fclampedAngleDelta;
                        }
                        else if (fdir == -1.0)
                        {
                            inewMoveMode = reinterpret_cast<::FUN_009dd130_shell *>(((this->m_pActorMover)))->FUN_009dd130() | 0x10;
                            fCurrentAngle -= fclampedAngleDelta;
                        }
                    }
                    else
                    {
                        inewMoveMode = reinterpret_cast<::FUN_009dd130_shell *>(((this->m_pActorMover)))->FUN_009dd130();
                        fCurrentAngle += fclampedAngleDelta * fdir;
                    }
                    if (!::FUN_0097fb20((::CombatState *)(*(CombatState**)&this->m_pActorMover)))
                        this->ByteAndFlagState = inewMoveMode;
                    if (!bimmobile || std::abs(fgoalLookAngle) <= DAT_01092478)
                        (*(ActorStub**)&this->pActor)->SetFurnitureHeading(fCurrentAngle);
                    flookingAngle = fgoalLookAngle;
                    if (bimmobile)
                        ((FUN_009e4c60_shell*)this)->UpdateLookingAngle(afDeltaT, flookingAngle);
                    reinterpret_cast<::TESForm *>(((*(GlobalObject_0041a250**)&this->m_pActorMover)))->ClearData();
                }
            }
        }
        eresult = 0;
    }
    if (!bimmobile)
        ((FUN_009e4c60_shell*)this)->UpdateLookingAngle(afDeltaT, flookingAngle);
    return eresult;
}
}  // namespace fnv_009e16e0

namespace fnv_009e2aa0 {
class Animation
{
  public:
};

class MobileObject
{
  public:
    virtual void Vfn000();
    virtual void Vfn001();
    virtual void Vfn002();
    virtual void Vfn003();
    virtual void Vfn004();
    virtual void Vfn005();
    virtual void Vfn006();
    virtual void Vfn007();
    virtual void Vfn008();
    virtual void Vfn009();
    virtual void Vfn010();
    virtual void Vfn011();
    virtual void Vfn012();
    virtual void Vfn013();
    virtual void Vfn014();
    virtual void Vfn015();
    virtual void Vfn016();
    virtual void Vfn017();
    virtual void Vfn018();
    virtual void Vfn019();
    virtual void Vfn020();
    virtual void Vfn021();
    virtual void Vfn022();
    virtual void Vfn023();
    virtual void Vfn024();
    virtual void Vfn025();
    virtual void Vfn026();
    virtual void Vfn027();
    virtual void Vfn028();
    virtual void Vfn029();
    virtual void Vfn030();
    virtual void Vfn031();
    virtual void Vfn032();
    virtual void Vfn033();
    virtual void Vfn034();
    virtual void Vfn035();
    virtual void Vfn036();
    virtual void Vfn037();
    virtual void Vfn038();
    virtual void Vfn039();
    virtual void Vfn040();
    virtual void Vfn041();
    virtual void Vfn042();
    virtual void Vfn043();
    virtual void Vfn044();
    virtual void Vfn045();
    virtual void Vfn046();
    virtual void Vfn047();
    virtual void Vfn048();
    virtual void Vfn049();
    virtual void Vfn050();
    virtual void Vfn051();
    virtual void Vfn052();
    virtual void Vfn053();
    virtual void Vfn054();
    virtual void Vfn055();
    virtual void Vfn056();
    virtual void Vfn057();
    virtual void Vfn058();
    virtual void Vfn059();
    virtual void Vfn060();
    virtual void Vfn061();
    virtual void Vfn062();
    virtual void Vfn063();
    virtual void Vfn064();
    virtual void Vfn065();
    virtual void Vfn066();
    virtual void Vfn067();
    virtual void Vfn068();
    virtual void Vfn069();
    virtual void Vfn070();
    virtual void Vfn071();
    virtual void Vfn072();
    virtual void Vfn073();
    virtual void Vfn074();
    virtual void Vfn075();
    virtual void Vfn076();
    virtual void Vfn077();
    virtual void Vfn078();
    virtual void Vfn079();
    virtual void Vfn080();
    virtual void Vfn081();
    virtual void Vfn082();
    virtual void Vfn083();
    virtual void Vfn084();
    virtual void Vfn085();
    virtual void Vfn086();
    virtual void Vfn087();
    virtual void Vfn088();
    virtual void Vfn089();
    virtual void Vfn090();
    virtual void Vfn091();
    virtual void Vfn092();
    virtual void Vfn093();
    virtual void Vfn094();
    virtual void Vfn095();
    virtual void Vfn096();
    virtual void Vfn097();
    virtual void Vfn098();
    virtual void Vfn099();
    virtual void Vfn100();
    virtual void Vfn101();
    virtual void Vfn102();
    virtual void Vfn103();
    virtual void Vfn104();
    virtual void Vfn105();
    virtual void Vfn106();
    virtual void Vfn107();
    virtual void Vfn108();
    virtual void Vfn109();
    virtual void Vfn110();
    virtual void Vfn111();
    virtual void Vfn112();
    virtual void Vfn113();
    virtual void Vfn114();
    virtual void Vfn115();
    virtual void Vfn116();
    virtual void Vfn117();
    virtual void Vfn118();
    virtual void Vfn119();
    virtual void Vfn120();
    virtual Animation* GetAnimation();
    virtual void Vfn122();
    virtual void Vfn123();
    virtual void Vfn124();
    virtual NiPoint3* GetPos();
    virtual void Vfn126();
    virtual void Vfn127();
    virtual void Vfn128();
    virtual void Vfn129();
    virtual void Vfn130();
    virtual void Vfn131();
    virtual void Vfn132();
    virtual void Vfn133();
    virtual void Vfn134();
    virtual bool IsAnimationDriven();
    virtual void Vfn136();
    virtual void Vfn137();
    virtual void Vfn138();
    virtual void Vfn139();
    virtual void Vfn140();
    virtual void Vfn141();
    virtual void Vfn142();
    virtual void Vfn143();
    virtual void Vfn144();
    virtual void Vfn145();
    virtual void Vfn146();
    virtual void Vfn147();
    virtual void Vfn148();
    virtual void Vfn149();
    virtual void Vfn150();
    virtual void Vfn151();
    virtual void Vfn152();
    virtual void Vfn153();
    virtual void Vfn154();
    virtual void Vfn155();
    virtual void Vfn156();
    virtual void Vfn157();
    virtual void Vfn158();
    virtual void Vfn159();
    virtual void Vfn160();
    virtual void Vfn161();
    virtual void Vfn162();
    virtual void Vfn163();
    virtual void Vfn164();
    virtual void Vfn165();
    virtual void Vfn166();
    virtual void Vfn167();
    virtual void Vfn168();
    virtual void Vfn169();
    virtual void Vfn170();
    virtual void Vfn171();
    virtual void Vfn172();
    virtual void Vfn173();
    virtual void Vfn174();
    virtual float GetCurrentTargetDistance(bool bForce);
};

class Actor : public MobileObject
{
  public:
};

class DetailedActorMover
{
  public:
    virtual void Vfn000();
    virtual void Vfn001();
    virtual void Vfn002();
    virtual void Vfn003();
    virtual void Vfn004();
    virtual void Vfn005();
    virtual void Vfn006();
    virtual unsigned int GetMovementFlags();
};

class PathingRequestPath
{
  public:
};

class PathingRequestPtr
{
  public:
    operator PathingRequestPath*() const;
};

class NiPoint3Ex : public NiPoint3
{
  public:
    NiPoint3Ex();
};

namespace std {
float abs(float f);
}
double _fabs(double d);
NiPoint3Ex __cdecl GetPitchYaw(NiPoint3 kFrom, NiPoint3 kTo);

struct FUN_009e2aa0_shell
{
    bool FUN_009e2aa0(float fTimeDelta);
};

// Updates the actor's movement flags from look-at/pathing heading, animation state and a timed state machine, writing them to offset 0x60 and returning true.
// @fnv 0x009e2aa0
bool FUN_009e2aa0_shell::FUN_009e2aa0(float fTimeDelta)
{
    unsigned int uiMoveMode3;
    unsigned int uiMoveFlags3;
    unsigned int uiOldFlagsVal;

    if (reinterpret_cast<::FUN_00437bf0_shell *>(((*(Actor**)((char*)this + 4))))->FUN_00437bf0() || ((bool)(reinterpret_cast<::FUN_00437bd0_stub *>(((*(Actor**)((char*)this + 4))))->FUN_00437bd0())))
    {
        *(unsigned int*)((char*)this + 0x60) = 0;
        return true;
    }
    uiOldFlagsVal = *(unsigned int*)((char*)this + 0x60);
    if (*(bool*)((char*)this + 0xe1))
    {
        *(float*)((char*)this + 0xb8) -= fTimeDelta;
        if (*(float*)((char*)this + 0xb8) < 0.0)
        {
            *(bool*)((char*)this + 0xe1) = false;
            *(float*)((char*)this + 0x8c) = 1.0f;
        }
    }
    uiMoveMode3 = reinterpret_cast<::FUN_009dd130_shell *>(((*(ActorMover**)((char*)this + 8))))->FUN_009dd130();
    uiMoveFlags3 = *(unsigned int*)((char*)this + 0x60) & 0x3f;
    if (reinterpret_cast<::FUN_005a2030_shell *>((void *)((*(Actor**)((char*)this + 4))))->FUN_005a2030() && (*(Actor**)((char*)this + 4))->IsAnimationDriven())
    {
        *(unsigned int*)((char*)this + 0x60) = uiMoveMode3 | 1;
        return true;
    }
    if (!*(bool*)((char*)this + 0xe1) &&
        (reinterpret_cast<::ActorMover *>(((*(DetailedActorMover**)((char*)this + 8))))->HasLookAtTarget() || *(bool*)((char*)this + 0xc0)))
    {
        NiPoint3Ex kPoint;
        float fDesiredHeading;
        float fDesiredHeading_2;
        float fDesiredHeadingAngle;
        float fDirection;
        if (reinterpret_cast<::ActorMover *>(((*(DetailedActorMover**)((char*)this + 8))))->HasLookAtTarget())
        {
            reinterpret_cast<::ActorMover *>(((*(DetailedActorMover**)((char*)this + 8))))->GetLookAtTargetPosition(kPoint);
            reinterpret_cast<::NiPoint3 *>(&(kPoint))->Subtract(*(*(Actor**)((char*)this + 4))->GetPos());
            fDesiredHeading_2 = ::GetDirectionAngle((const ::NiPoint3 *)&(kPoint));
        }
        else if (*(bool*)((char*)this + 0xc1))
        {
            static_cast<NiPoint3&>(kPoint) = NiPoint3::ZERO;
            fDesiredHeading_2 = (*(Actor**)((char*)this + 4))->GetCurrentTargetDistance(false);
        }
        else if (*(PathingRequestPtr*)((char*)this + 0xc))
        {
            reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>((((PathingRequestPath*)*(PathingRequestPtr*)((char*)this + 0xc))))->GetLocationAtSplineParameter(*(float*)((char*)this + 0xc4), (::NiPoint3 *)&(kPoint));
            reinterpret_cast<::NiPoint3 *>(&(kPoint))->Subtract(*(*(Actor**)((char*)this + 4))->GetPos());
            fDesiredHeading_2 = ::GetDirectionAngle((const ::NiPoint3 *)&(kPoint));
        }
        else
        {
            static_cast<NiPoint3&>(kPoint) = NiPoint3::ZERO;
            fDesiredHeading_2 = (*(Actor**)((char*)this + 4))->GetCurrentTargetDistance(false);
        }
        NiPoint3Ex kAngles = GetPitchYaw(*(*(Actor**)((char*)this + 4))->GetPos(), *(NiPoint3*)((char*)this + 0x34));
        if (reinterpret_cast<::FUN_005a2030_shell *>((void *)((*(Actor**)((char*)this + 4))))->FUN_005a2030() &&
            _fabs(std::abs(kAngles.x) - 1.5707963267948966) < 0.2617993950843811)
            fDesiredHeadingAngle = fDesiredHeading_2;
        else
            fDesiredHeadingAngle = kAngles.z;
        fDirection = 1.0f;
        fDesiredHeadingAngle = ::WrapAngle(fDesiredHeadingAngle);
        fDesiredHeading = ::FUN_004b15e0(fDesiredHeadingAngle, fDesiredHeading_2, &fDirection);
        if (*(float*)((char*)this + 0x8c) > 0.25)
        {
            if (std::abs(fDesiredHeading) > 0.01745329238474369)
            {
                float fDegrees2 = fDesiredHeading * 57.2957763671875;
                if (std::abs(fDegrees2) > 135.0 && reinterpret_cast<::FUN_00494710_shell *>(((*(Actor**)((char*)this + 4))->GetAnimation()))->FUN_00494710(4) &&
                    (_fabs(std::abs(kAngles.x) - 1.5707963267948966) >= 0.2617993950843811 ||
                     !reinterpret_cast<::FUN_005a2030_shell *>((void *)((*(Actor**)((char*)this + 4))))->FUN_005a2030()))
                {
                    uiMoveFlags3 = 2;
                }
                else if (std::abs(fDegrees2) > 45.0)
                {
                    if (fDirection > 0.0)
                    {
                        if ((*(Actor**)((char*)this + 4))->IsAnimationDriven() &&
                            !reinterpret_cast<::FUN_00494710_shell *>(((*(Actor**)((char*)this + 4))->GetAnimation()))->FUN_00494710(5))
                        {
                            uiMoveFlags3 = 1;
                            *(bool*)((char*)this + 0xe1) = true;
                            *(float*)((char*)this + 0xb8) = 1.0f;
                        }
                        else
                            uiMoveFlags3 = 4;
                    }
                    else
                    {
                        if ((*(Actor**)((char*)this + 4))->IsAnimationDriven() &&
                            !reinterpret_cast<::FUN_00494710_shell *>(((*(Actor**)((char*)this + 4))->GetAnimation()))->FUN_00494710(6))
                        {
                            uiMoveFlags3 = 1;
                            *(bool*)((char*)this + 0xe1) = true;
                            *(float*)((char*)this + 0xb8) = 1.0f;
                        }
                        else
                            uiMoveFlags3 = 8;
                    }
                }
                else
                    uiMoveFlags3 = 1;
            }
            else
                uiMoveFlags3 = (*(DetailedActorMover**)((char*)this + 8))->GetMovementFlags() & 0x3f;
        }
        else
            *(float*)((char*)this + 0x8c) += fTimeDelta;
    }
    else
        uiMoveFlags3 = (*(DetailedActorMover**)((char*)this + 8))->GetMovementFlags() & 0x3f;

    switch (*(int*)((char*)this + 0xcc))
    {
    case 3:
        if ((uiMoveMode3 & 0x200) && (!(uiOldFlagsVal & 0x200) || ((uiOldFlagsVal & 0x30) && !(uiMoveFlags3 & 0x30))))
        {
            *(int*)((char*)this + 0xcc) = 1;
            *(float*)((char*)this + 0x90) = reinterpret_cast<::FUN_00897b50_shell *>(((*(Actor**)((char*)this + 4))))->FUN_00897b50((::ANIM_GROUP_ENUM)(3)) * 0.5;
        }
        else
            break;
    case 1:
        uiMoveMode3 &= ~0x200;
        uiMoveMode3 |= 0x100;
        *(float*)((char*)this + 0x90) -= fTimeDelta;
        if (*(float*)((char*)this + 0x90) < 0.0)
        {
            *(int*)((char*)this + 0xcc) = 2;
            *(float*)((char*)this + 0x90) = 0.0f;
        }
        break;
    case 2:
        *(int*)((char*)this + 0xcc) = 3;
        break;
    }
    *(unsigned int*)((char*)this + 0x60) = uiMoveFlags3 | uiMoveMode3;
    return true;
}
}  // namespace fnv_009e2aa0

namespace fnv_009e3560 {
struct NiStream;
struct PhysicsSimulationContext;
struct hkStatisticsCollector;
struct hkVector4;
struct CharacterProxyConfiguration;
struct Vector4Data;
struct hkpCharacterProxy;
struct CharacterPhysicsController;
struct blob1
{
    char b[1];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
struct NiMemObject
{
    char _pad_0[1];
};
struct FUN_009e3560_shell : public DetailedActorPathHandler
{
    void UpdatePathRotation(float);
};

class bhkCharacterController
{
  public:
    float GetValue();
};

struct TopicH
{
};

struct MobileObject
{
    virtual void vfn_000();
    virtual void vfn_001();
    virtual void vfn_002();
    virtual void vfn_003();
    virtual void vfn_004();
    virtual void vfn_005();
    virtual void vfn_006();
    virtual void vfn_007();
    virtual void vfn_008();
    virtual void vfn_009();
    virtual void vfn_010();
    virtual void vfn_011();
    virtual void vfn_012();
    virtual void vfn_013();
    virtual void vfn_014();
    virtual void vfn_015();
    virtual void vfn_016();
    virtual void vfn_017();
    virtual void vfn_018();
    virtual void vfn_019();
    virtual void vfn_020();
    virtual void vfn_021();
    virtual void vfn_022();
    virtual void vfn_023();
    virtual void vfn_024();
    virtual void vfn_025();
    virtual void vfn_026();
    virtual void vfn_027();
    virtual void vfn_028();
    virtual void vfn_029();
    virtual void vfn_030();
    virtual void vfn_031();
    virtual void vfn_032();
    virtual void vfn_033();
    virtual void vfn_034();
    virtual void vfn_035();
    virtual void vfn_036();
    virtual void vfn_037();
    virtual void vfn_038();
    virtual void vfn_039();
    virtual void vfn_040();
    virtual void vfn_041();
    virtual void vfn_042();
    virtual void vfn_043();
    virtual void vfn_044();
    virtual void vfn_045();
    virtual void vfn_046();
    virtual void vfn_047();
    virtual void vfn_048();
    virtual void vfn_049();
    virtual void vfn_050();
    virtual void vfn_051();
    virtual void vfn_052();
    virtual void vfn_053();
    virtual void vfn_054();
    virtual void vfn_055();
    virtual void vfn_056();
    virtual void vfn_057();
    virtual void vfn_058();
    virtual void vfn_059();
    virtual void vfn_060();
    virtual void vfn_061();
    virtual void vfn_062();
    virtual void vfn_063();
    virtual void vfn_064();
    virtual void vfn_065();
    virtual void vfn_066();
    virtual void vfn_067();
    virtual void vfn_068();
    virtual void vfn_069();
    virtual void vfn_070();
    virtual void vfn_071();
    virtual void vfn_072();
    virtual void vfn_073();
    virtual void vfn_074();
    virtual void vfn_075();
    virtual void vfn_076();
    virtual void vfn_077();
    virtual void vfn_078();
    virtual void vfn_079();
    virtual void vfn_080();
    virtual void vfn_081();
    virtual void vfn_082();
    virtual void vfn_083();
    virtual void vfn_084();
    virtual void vfn_085();
    virtual void vfn_086();
    virtual void vfn_087();
    virtual void vfn_088();
    virtual void vfn_089();
    virtual void vfn_090();
    virtual void vfn_091();
    virtual void vfn_092();
    virtual void vfn_093();
    virtual void vfn_094();
    virtual void vfn_095();
    virtual void vfn_096();
    virtual void vfn_097();
    virtual void vfn_098();
    virtual void vfn_099();
    virtual void vfn_100();
    virtual void vfn_101();
    virtual void vfn_102();
    virtual void vfn_103();
    virtual void vfn_104();
    virtual void vfn_105();
    virtual void vfn_106();
    virtual void vfn_107();
    virtual void vfn_108();
    virtual void vfn_109();
    virtual void vfn_110();
    virtual void vfn_111();
    virtual void vfn_112();
    virtual void vfn_113();
    virtual void vfn_114();
    virtual void vfn_115();
    virtual void vfn_116();
    virtual void vfn_117();
    virtual void vfn_118();
    virtual void vfn_119();
    virtual void vfn_120();
    virtual void vfn_121();
    virtual void vfn_122();
    virtual void vfn_123();
    virtual void vfn_124();
    virtual NiPoint3* vfn_125();
    virtual void vfn_126();
    virtual void vfn_127();
    virtual void vfn_128();
    virtual void vfn_129();
    virtual void vfn_130();
    virtual void vfn_131();
    virtual void vfn_132();
    virtual void vfn_133();
    virtual void vfn_134();
    virtual void vfn_135();
    virtual void vfn_136();
    virtual void vfn_137();
    virtual void vfn_138();
    virtual void vfn_139();
    virtual void vfn_140();
    virtual void vfn_141();
    virtual void vfn_142();
    virtual void vfn_143();
    virtual void vfn_144();
    virtual void vfn_145();
    virtual void vfn_146();
    virtual void vfn_147();
    virtual void vfn_148();
    virtual void vfn_149();
    virtual void vfn_150();
    virtual void vfn_151();
    virtual void vfn_152();
    virtual void vfn_153();
    virtual void vfn_154();
    virtual void vfn_155();
    virtual void vfn_156();
    virtual void vfn_157();
    virtual void vfn_158();
    virtual void vfn_159();
    virtual void vfn_160();
    virtual void vfn_161();
    virtual void vfn_162();
    virtual void vfn_163();
    virtual void vfn_164();
    virtual void vfn_165();
    virtual void vfn_166();
    virtual void vfn_167();
    virtual void vfn_168();
    virtual void vfn_169();
    virtual void vfn_170();
    virtual void vfn_171();
    virtual void vfn_172();
    virtual void vfn_173();
    virtual void vfn_174();
    virtual float vfn_175(bool);

    bhkCharacterController* GetPhysicsCharacterController();
};

struct DetailedActorPathHandler_Layout
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
    virtual unsigned int vfn_18();
    MobileObject* pActor;
    char pad_08[0x14];
    NiPoint3 m_kPathVector1;
    NiPoint3 m_kPathVector2;
    NiPoint3 m_kPathVector3;
    char pad_40[0x20];
    unsigned int ByteAndFlagState;
    char pad_64[0x7a];
    bool bAtDE;
};

struct B006815c0
{
    float pad[9];
    B006815c0();
};

struct HighProcessVector
{
};

struct FUN_00524ac0_shell
{
};

struct FUN_009e1640_shell
{
};

struct NiPoint3b
{
    float x, y, z;
    NiPoint3b();
};

struct M_004b4500
{
    NiPoint3b FUN_004b4500(const NiPoint3*);
};

void __cdecl FUN_005330e0(float&, float, float);


// Updates the handler's rotation toward the target point, adjusting for water height, controller offset and move-mode angle.
// @fnv 0x009e3560
void FUN_009e3560_shell::UpdatePathRotation(float afDeltaT)
{
    if (reinterpret_cast<::FUN_005a2030_shell *>((void *)(((DetailedActorPathHandler_Layout*)this)->pActor))->FUN_005a2030())
    {
        NiPoint3 deltaToTargetPoint = ((DetailedActorPathHandler_Layout*)this)->m_kPathVector3;
        float fwaterHeight = reinterpret_cast<::FUN_0057b0a0_shell *>((void *)(((DetailedActorPathHandler_Layout*)this)->pActor))->FUN_0057b0a0();
        if (fwaterHeight != ::DAT_010241b0 && ((DetailedActorPathHandler_Layout*)this)->m_kPathVector3.z > fwaterHeight)
        {
            ((DetailedActorPathHandler_Layout*)this)->m_kPathVector3.z =
                reinterpret_cast<::FUN_0057b0a0_shell *>((void *)(((DetailedActorPathHandler_Layout*)this)->pActor))->FUN_0057b0a0() - ::DAT_01020998;
        }
        bhkCharacterController* pcon =
            ((::fnv_009e3560::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((((DetailedActorPathHandler_Layout*)this)->pActor))->FUN_009306d0()));
        NiPoint3 actorLoc = *(((::NiPoint3 *)(reinterpret_cast<::TESTopicInfo *>((((TopicH*)((DetailedActorPathHandler_Layout*)this)->pActor)))->GetAddTopicList())));
        if (pcon)
        {
            actorLoc.z +=
                reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((void *)(((DetailedActorPathHandler_Layout*)this)->pActor))->GetActorHeight() * ::DAT_01011588 * pcon->GetValue();
            reinterpret_cast<::NiPoint3 *>((((HighProcessVector*)&deltaToTargetPoint)))->Subtract((*(const ::NiPoint3 *)(&actorLoc)));
        }
        else
        {
            reinterpret_cast<::NiPoint3 *>((((HighProcessVector*)&deltaToTargetPoint)))->Subtract((*(const ::NiPoint3 *)(((DetailedActorPathHandler_Layout*)this)->pActor->vfn_125())));
        }
        if (((DetailedActorPathHandler_Layout*)this)->m_kPathVector3.z >=
                actorLoc.z - reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((void *)(((DetailedActorPathHandler_Layout*)this)->pActor))->GetActorHeight() &&
            ((DetailedActorPathHandler_Layout*)this)->m_kPathVector3.z < actorLoc.z)
        {
            deltaToTargetPoint.z = 0.0f;
        }
        B006815c0 rot;
        reinterpret_cast<::FUN_004a0c10_s *>((((HighProcessVector*)&deltaToTargetPoint)))->FUN_004a0c10();
        FUN_005330e0(deltaToTargetPoint.z, -1.0f, 1.0f);
        float fangle;
        if (deltaToTargetPoint.z >= ::_DAT_01012060)
        {
            fangle = ::FUN_004f6e40(deltaToTargetPoint.z);
            fangle = ::DAT_01064f50 - fangle;
        }
        else
        {
            fangle = ::FUN_004f6e40(-deltaToTargetPoint.z);
            fangle = fangle - ::DAT_01064f50;
        }
        if (((DetailedActorPathHandler_Layout*)this)->m_kPathVector1.y < ::_DAT_01012060 &&
            (((DetailedActorPathHandler_Layout*)this)->ByteAndFlagState & 2))
        {
            reinterpret_cast<::FUN_00524ac0_shell *>((((FUN_00524ac0_shell*)&rot)))->FUN_00524ac0(-fangle);
        }
        else
        {
            reinterpret_cast<::FUN_00524ac0_shell *>((((FUN_00524ac0_shell*)&rot)))->FUN_00524ac0(fangle);
        }
        *(NiPoint3b*)&((DetailedActorPathHandler_Layout*)this)->m_kPathVector1 =
            (*(::fnv_009e3560::NiPoint3b *)(::FUN_004b3ae0((::NiPoint3 *)&(((DetailedActorPathHandler_Layout*)this)->m_kPathVector1), (*(const ::NiPoint3 *)((const float*)&rot)), {})));
        return;
    }
    NiPoint3 deltaToTargetPoint = ((DetailedActorPathHandler_Layout*)this)->bAtDE
                                      ? ((DetailedActorPathHandler_Layout*)this)->m_kPathVector2
                                      : ((DetailedActorPathHandler_Layout*)this)->m_kPathVector3;
    reinterpret_cast<::NiPoint3 *>((((HighProcessVector*)&deltaToTargetPoint)))->Subtract((*(const ::NiPoint3 *)(((DetailedActorPathHandler_Layout*)this)->pActor->vfn_125())));
    deltaToTargetPoint.z = 0.0f;
    float fangleToTarget = ::GetDirectionAngle((const ::NiPoint3 *)&(deltaToTargetPoint));
    float fmoveModeAngle;
    switch (((DetailedActorPathHandler_Layout*)this)->vfn_18() & 0xf)
    {
    case 0:
    case 1:
        fmoveModeAngle = 0.0f;
        break;
    case 2:
        fmoveModeAngle = 3.1415927f;
        break;
    case 4:
        fmoveModeAngle = -1.5707964f;
        break;
    case 8:
        fmoveModeAngle = 1.5707964f;
        break;
    default:
        fmoveModeAngle = 0.0f;
        break;
    }
    float fworldSpaceMoveModeAngle = ((DetailedActorPathHandler_Layout*)this)->pActor->vfn_175(false) + fmoveModeAngle;
    float fdeltaAngle = fangleToTarget - fworldSpaceMoveModeAngle;
    B006815c0 MoveModeRot;
    reinterpret_cast<::FUN_009e1640_shell *>((((FUN_009e1640_shell*)&MoveModeRot)))->SetRotationMatrix(fdeltaAngle);
    *(NiPoint3b*)&((DetailedActorPathHandler_Layout*)this)->m_kPathVector1 =
        ((M_004b4500*)&MoveModeRot)->FUN_004b4500(&((DetailedActorPathHandler_Layout*)this)->m_kPathVector1);
}
}  // namespace fnv_009e3560

namespace fnv_009e3d50 {

class NiPoint3Ex : public NiPoint3
{
  public:
    NiPoint3Ex();
    NiPoint3Ex operator-(const NiPoint3& arPt) const;
    float Dot(const NiPoint3& arPt) const;
    float Length() const;
};

class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];
    ThreeByThreeMatrix();
    NiPoint3Ex operator*(const NiPoint3& arPt) const;
};

class PathingLocation
{
  public:
};

class PathingGraphNode
{
  public:
    PathingLocation& GetLocation();
};

class PathingSolution
{
  public:
};

template <class T> class NiPointerAccess
{
  public:
    T* operator->() const;
};

class ActorMoverEx
{
  public:
};

class Actor
{
  public:
    virtual void Vfn000();
    virtual void Vfn001();
    virtual void Vfn002();
    virtual void Vfn003();
    virtual void Vfn004();
    virtual void Vfn005();
    virtual void Vfn006();
    virtual void Vfn007();
    virtual void Vfn008();
    virtual void Vfn009();
    virtual void Vfn010();
    virtual void Vfn011();
    virtual void Vfn012();
    virtual void Vfn013();
    virtual void Vfn014();
    virtual void Vfn015();
    virtual void Vfn016();
    virtual void Vfn017();
    virtual void Vfn018();
    virtual void Vfn019();
    virtual void Vfn020();
    virtual void Vfn021();
    virtual void Vfn022();
    virtual void Vfn023();
    virtual void Vfn024();
    virtual void Vfn025();
    virtual void Vfn026();
    virtual void Vfn027();
    virtual void Vfn028();
    virtual void Vfn029();
    virtual void Vfn030();
    virtual void Vfn031();
    virtual void Vfn032();
    virtual void Vfn033();
    virtual void Vfn034();
    virtual void Vfn035();
    virtual void Vfn036();
    virtual void Vfn037();
    virtual void Vfn038();
    virtual void Vfn039();
    virtual void Vfn040();
    virtual void Vfn041();
    virtual void Vfn042();
    virtual void Vfn043();
    virtual void Vfn044();
    virtual void Vfn045();
    virtual void Vfn046();
    virtual void Vfn047();
    virtual void Vfn048();
    virtual void Vfn049();
    virtual void Vfn050();
    virtual void Vfn051();
    virtual void Vfn052();
    virtual void Vfn053();
    virtual void Vfn054();
    virtual void Vfn055();
    virtual void Vfn056();
    virtual void Vfn057();
    virtual void Vfn058();
    virtual void Vfn059();
    virtual void Vfn060();
    virtual void Vfn061();
    virtual void Vfn062();
    virtual void Vfn063();
    virtual void Vfn064();
    virtual void Vfn065();
    virtual void Vfn066();
    virtual void Vfn067();
    virtual void Vfn068();
    virtual void Vfn069();
    virtual void Vfn070();
    virtual void Vfn071();
    virtual void Vfn072();
    virtual void Vfn073();
    virtual void Vfn074();
    virtual void Vfn075();
    virtual void Vfn076();
    virtual void Vfn077();
    virtual void Vfn078();
    virtual void Vfn079();
    virtual void Vfn080();
    virtual void Vfn081();
    virtual void Vfn082();
    virtual void Vfn083();
    virtual void Vfn084();
    virtual void Vfn085();
    virtual void Vfn086();
    virtual void Vfn087();
    virtual void Vfn088();
    virtual void Vfn089();
    virtual void Vfn090();
    virtual void Vfn091();
    virtual void Vfn092();
    virtual void Vfn093();
    virtual void Vfn094();
    virtual void Vfn095();
    virtual void Vfn096();
    virtual void Vfn097();
    virtual void Vfn098();
    virtual void Vfn099();
    virtual void Vfn100();
    virtual void Vfn101();
    virtual void Vfn102();
    virtual void Vfn103();
    virtual void Vfn104();
    virtual void Vfn105();
    virtual void Vfn106();
    virtual void Vfn107();
    virtual void Vfn108();
    virtual void Vfn109();
    virtual void Vfn110();
    virtual void Vfn111();
    virtual void Vfn112();
    virtual void Vfn113();
    virtual void Vfn114();
    virtual void Vfn115();
    virtual void Vfn116();
    virtual void Vfn117();
    virtual void Vfn118();
    virtual void Vfn119();
    virtual void Vfn120();
    virtual void Vfn121();
    virtual void Vfn122();
    virtual void Vfn123();
    virtual void Vfn124();
    virtual const NiPoint3* GetPos();
    virtual void Vfn126();
    virtual void Vfn127();
    virtual void Vfn128();
    virtual void Vfn129();
    virtual void Vfn130();
    virtual void Vfn131();
    virtual void Vfn132();
    virtual void Vfn133();
    virtual void Vfn134();
    virtual void Vfn135();
    virtual void Vfn136();
    virtual void Vfn137();
    virtual void Vfn138();
    virtual void Vfn139();
    virtual void Vfn140();
    virtual void Vfn141();
    virtual void Vfn142();
    virtual void Vfn143();
    virtual void Vfn144();
    virtual void Vfn145();
    virtual void Vfn146();
    virtual void Vfn147();
    virtual void Vfn148();
    virtual void Vfn149();
    virtual void Vfn150();
    virtual void Vfn151();
    virtual void Vfn152();
    virtual void Vfn153();
    virtual void Vfn154();
    virtual void Vfn155();
    virtual void Vfn156();
    virtual void Vfn157();
    virtual void Vfn158();
    virtual void Vfn159();
    virtual void Vfn160();
    virtual void Vfn161();
    virtual void Vfn162();
    virtual void Vfn163();
    virtual void Vfn164();
    virtual void Vfn165();
    virtual void Vfn166();
    virtual void Vfn167();
    virtual void Vfn168();
    virtual void Vfn169();
    virtual void Vfn170();
    virtual void Vfn171();
    virtual void Vfn172();
    virtual void Vfn173();
    virtual void Vfn174();
    virtual float GetCurrentTargetDistance(bool abInterp);
};

class PathHandlerEx
{
  public:
    virtual void V00();
    Actor* pActor;
};

struct DetailedActorPathHandlerEx : public DetailedActorPathHandler
{
    void UpdatePathing(float afDeltaT);
};

// Advances the pathing solution parameter along the path, checking direction and distance against the actor's position, and updates the cached point and index.
// @fnv 0x009e3d50
void DetailedActorPathHandlerEx::UpdatePathing(float afDeltaT)
{
    if (::GetObjectFlags((char *)((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->())) == 0)
        return;
    if (::GetObjectFlags((char *)((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->())) > 0 &&
        m_uiPathPointIndex + 1 >= ::GetObjectFlags((char *)((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->())))
    {
        m_kPathVector3 =
            reinterpret_cast<::TaskQueueInterface *>((void *)&(((::fnv_009e3d50::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->()))->FUN_006b05a0()))->GetLocation()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
        return;
    }
    if ((ByteAndFlagState & 1) && m_kPathVector1.y < ::_DAT_01012060)
        return;
    if ((ByteAndFlagState & 2) && m_kPathVector1.y > ::_DAT_01012060)
        return;
    if ((ByteAndFlagState & 4) && m_kPathVector1.x > ::_DAT_01012060)
        return;
    if ((ByteAndFlagState & 8) && m_kPathVector1.x < ::_DAT_01012060)
        return;

    ThreeByThreeMatrix kRotationBasis;
    reinterpret_cast<::FUN_009e1640_shell *>(&(kRotationBasis))->SetRotationMatrix(((PathHandlerEx*)this)->pActor->GetCurrentTargetDistance(false));
    NiPoint3Ex kForward = kRotationBasis * m_kPathVector1;
    float fDot;
    NiPoint3Ex kToTarget = ((const NiPoint3Ex&)m_kPathVector3) - *((PathHandlerEx*)this)->pActor->GetPos();
    NiPoint3Ex kAhead;
    reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)
        ).operator->()))->GetLocationAtSplineParameter(m_fSplineParameter + 0.10000000149011612, (::NiPoint3 *)&(kAhead));
    reinterpret_cast<::NiPoint3 *>(&(kAhead))->Subtract(m_kPathVector3);
    kToTarget.z = 0.0f;
    fDot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kForward))->DotProduct((void *)&(kToTarget));
    float fAheadDot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kAhead))->DotProduct((void *)&(kToTarget));
    float fSqDist = reinterpret_cast<::FUN_00595c80_shell *>((void *)&(kToTarget))->GetSquaredXYLength();
    float fTargetDistSqr = reinterpret_cast<::TESCombatStyle *>((void *)&(((NiPoint3Ex&)m_kPathVector1)))->UpdateCombatStyle() * 4.0;
    fTargetDistSqr = ::FUN_00404010(fTargetDistSqr, this->unk14 * this->unk14);

    if (fDot < ::_DAT_01012060 || fAheadDot < ::_DAT_01012060 || fSqDist < fTargetDistSqr)
    {
        m_fPathValue16 = reinterpret_cast<::fnv_006e84b0::FUN_006e84b0_shell *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)
                             ).operator->()))->GetSplineLengthAtParameter(m_fSplineParameter);
        m_kPathVector4 = m_kPathVector3;
        if (::GetObjectFlags((char *)((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->())) - 1 <= m_fSplineParameter)
        {
            m_fSplineParameter =
                (float)(::GetObjectFlags((char *)((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->())) - 1);
            m_uiPathPointIndex = (int)m_fSplineParameter;
            m_kPathVector3 =
                reinterpret_cast<::TaskQueueInterface *>((void *)&(((::fnv_009e3d50::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->()))->FUN_006b05a0()))->GetLocation()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
            return;
        }
        float fLastDot = fDot;
        m_fSplineParameter += 0.10000000149011612;
        reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)
            ).operator->()))->GetLocationAtSplineParameter(m_fSplineParameter, (::NiPoint3 *)&(m_kPathVector3));
        reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)
            ).operator->()))->GetLocationAtSplineParameter(m_fSplineParameter + 0.10000000149011612, (::NiPoint3 *)&(kAhead));
        reinterpret_cast<::NiPoint3 *>(&(kAhead))->Subtract(m_kPathVector3);
        kToTarget = ((const NiPoint3Ex&)m_kPathVector3) - *((PathHandlerEx*)this)->pActor->GetPos();
        kToTarget.z = 0.0f;
        fDot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kForward))->DotProduct((void *)&(kToTarget));
        fAheadDot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kAhead))->DotProduct((void *)&(kToTarget));
        fSqDist = reinterpret_cast<::FUN_00595c80_shell *>((void *)&(kToTarget))->GetSquaredXYLength();
        while (1)
        {
            if (::GetObjectFlags((char *)((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->())) - 1 <=
                m_fSplineParameter)
            {
                m_fSplineParameter =
                    (float)(::GetObjectFlags((char *)((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)).operator->())) - 1);
                break;
            }
            if (fDot < ::_DAT_01012060 || fAheadDot < ::_DAT_01012060)
            {
                if (fDot < fLastDot)
                    break;
            }
            else
            {
                if (fSqDist >= fTargetDistSqr)
                    break;
            }
            fLastDot = fDot;
            m_fSplineParameter += 0.10000000149011612;
            reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)
                ).operator->()))->GetLocationAtSplineParameter(m_fSplineParameter, (::NiPoint3 *)&(m_kPathVector3));
            reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>(((((NiPointerAccess<PathingSolution>&)pCurrentPathingSolution)
                ).operator->()))->GetLocationAtSplineParameter(m_fSplineParameter + 0.10000000149011612, (::NiPoint3 *)&(kAhead));
            reinterpret_cast<::NiPoint3 *>(&(kAhead))->Subtract(m_kPathVector3);
            kToTarget = ((const NiPoint3Ex&)m_kPathVector3) - *((PathHandlerEx*)this)->pActor->GetPos();
            kToTarget.z = 0.0f;
            fDot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kForward))->DotProduct((void *)&(kToTarget));
            fAheadDot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kAhead))->DotProduct((void *)&(kToTarget));
            fSqDist = reinterpret_cast<::FUN_00595c80_shell *>((void *)&(kToTarget))->GetSquaredXYLength();
        }
        m_uiPathPointIndex = (int)m_fSplineParameter;
        reinterpret_cast<::TESForm *>((((ActorMoverEx*)m_pActorMover)))->ClearData();
    }
}
}  // namespace fnv_009e3d50

namespace std {
float __cdecl abs(float);
}

void __cdecl WrapValueToRange(float&, float, float);
void __cdecl FUN_005330e0(float&, float, float);

extern const double DAT_0106efa0;
extern const double DAT_01092498;

namespace fnv_009e4800 {
struct NiPoint3_sub : public NiPoint3
{
    NiPoint3_sub operator-(const NiPoint3&) const;
    float Length() const;
};

struct Actor
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual NiPoint3_sub* GetPos();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual float GetCurrentTargetDistance(int);
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210();
    virtual void V211();
    virtual void V212();
    virtual float GetMaxRotationSpeed();
    float FUN_008be1b0();
};

struct PathingLocation
{
};

class PathingGraphNode
{
  public:
    PathingLocation& FUN_00717e50();
};

class PathingSolution
{
  public:
};

struct Flt
{
    operator unsigned int() const;
};

struct DetailedActorPathHandlerRot : public DetailedActorPathHandler
{
    void GetPathAngles(float*, float*);
    void UpdateLookingAngle(float, float);
    float FUN_009e4800(float, float*);
};

// @fnv 0x009e4800
float DetailedActorPathHandlerRot::FUN_009e4800(float afDeltaT, float* pfRotateMult)
{
    float fPathHeading = 0.0f;
    float fSpeed = 0.0f;
    GetPathAngles(&fPathHeading, &fSpeed);
    float fCurrentHeading = (*(Actor**)&this->pActor)->GetCurrentTargetDistance(0);
    WrapValueToRange(fCurrentHeading, -3.1415927f, 3.1415927f);
    WrapValueToRange(fPathHeading, -3.1415927f, 3.1415927f);
    float fTimeSinceScaleStart = fPathHeading - fCurrentHeading;
    WrapValueToRange(fTimeSinceScaleStart, -3.1415927f, 3.1415927f);
    if (std::abs(fTimeSinceScaleStart) >= DAT_01023128)
    {
        float fScale = 1.0f;
        if ((unsigned int)*(Flt*)&pCurrentPathingSolution &&
            (*(Actor**)&this->pActor)->GetMaxRotationSpeed() > DAT_010357e8)
        {
            float fDist;
            float fLookAheadDist;
            float fMinRadius;
            float fAngleToTarget;
            float fTargetAngle;
            float fFacingAngle;
            NiPoint3 kGoal;
            fDist = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_009e4800::NiPoint3_sub &)((((const NiPoint3_sub&)m_kPathVector3) - *(*(Actor**)&this->pActor)->GetPos())))->ComputeMagnitude();
            fMinRadius = (ByteAndFlagState & 0x200) ? reinterpret_cast<::fnv_00884eb0::FUN_00884eb0_shell *>(((*(Actor**)&this->pActor)))->FUN_00884eb0()
                                            : reinterpret_cast<::fnv_00884dc0::FUN_00884dc0_shell *>(((*(Actor**)&this->pActor)))->FUN_00884dc0();
            fLookAheadDist = fMinRadius;
            kGoal = m_kPathVector3;
            if (fDist < fLookAheadDist)
            {
                int iNode;
                reinterpret_cast<::fnv_006e7e70::FUN_006e7e70_shell *>((((PathingSolution*)(unsigned int)*(Flt*)&pCurrentPathingSolution)))->FUN_006e7e70(m_fSplineParameter, fLookAheadDist - fDist, 1, (float *)(int *)(&iNode), &kGoal);
            }
            fFacingAngle = (*(Actor**)&this->pActor)->GetCurrentTargetDistance(0);
            NiPoint3_sub toTarget = ((const NiPoint3_sub&)kGoal) - *(*(Actor**)&this->pActor)->GetPos();
            fTargetAngle = ::GetDirectionAngle((const ::NiPoint3 *)&(toTarget));
            fAngleToTarget = fTargetAngle - fFacingAngle;
            WrapValueToRange(fAngleToTarget, -3.1415927f, 3.1415927f);
            fScale = std::abs(fAngleToTarget) / DAT_01064f50;
            FUN_005330e0(fScale, DAT_010313d4, 1.0f);
        }
        float fMaxTurn = (*(Actor**)&this->pActor)->GetMaxRotationSpeed() * DAT_01023128 * afDeltaT * 3.0 * fScale;
        if (std::abs(fTimeSinceScaleStart) > fMaxTurn)
        {
            if (std::abs(fTimeSinceScaleStart) > DAT_01092498)
                *pfRotateMult = 0.05f;
            else if (std::abs(fTimeSinceScaleStart) > 2.0)
                *pfRotateMult = 0.1f;
            else if (std::abs(fTimeSinceScaleStart) > DAT_0106efa0)
                *pfRotateMult = 0.2f;
            else if ((unsigned int)*(Flt*)&pCurrentPathingSolution && (unsigned int)*(Flt*)&m_pPathingRequest)
            {
                if (reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::fnv_009e4800::NiPoint3_sub &)((*(*(Actor**)&this->pActor)->GetPos() -
                     reinterpret_cast<::TaskQueueInterface *>((void *)&((*(::fnv_009e4800::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>((((PathingSolution*)(unsigned int)*(Flt*)&pCurrentPathingSolution)))->FUN_006b05a0()))
                         .FUN_00717e50()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))))->GetSquaredXYLength() <
                    (*(Actor**)&this->pActor)->FUN_008be1b0() * (*(Actor**)&this->pActor)->FUN_008be1b0())
                    *pfRotateMult = 0.5f;
            }
        }
        FUN_005330e0(fTimeSinceScaleStart, -fMaxTurn, fMaxTurn);
        fPathHeading = fCurrentHeading + fTimeSinceScaleStart;
    }
    m_fPathValue18 = std::abs(fTimeSinceScaleStart);
    UpdateLookingAngle(afDeltaT, fSpeed);
    return fPathHeading;
}
}  // namespace fnv_009e4800

namespace fnv_009e5690 {
struct NiPoint3_ext : public NiPoint3
{
    float GetLengthSquared();
    float Dot(const NiPoint3_ext& arPt) const;
};

class ThreeByThreeMatrix
{
  public:
    float m_afEntries[3][3];
    ThreeByThreeMatrix();
    NiPoint3_ext operator*(const NiPoint3_ext& arPt) const;
};

class Actor
{
  public:
    virtual void Vfn000();
    virtual void Vfn001();
    virtual void Vfn002();
    virtual void Vfn003();
    virtual void Vfn004();
    virtual void Vfn005();
    virtual void Vfn006();
    virtual void Vfn007();
    virtual void Vfn008();
    virtual void Vfn009();
    virtual void Vfn010();
    virtual void Vfn011();
    virtual void Vfn012();
    virtual void Vfn013();
    virtual void Vfn014();
    virtual void Vfn015();
    virtual void Vfn016();
    virtual void Vfn017();
    virtual void Vfn018();
    virtual void Vfn019();
    virtual void Vfn020();
    virtual void Vfn021();
    virtual void Vfn022();
    virtual void Vfn023();
    virtual void Vfn024();
    virtual void Vfn025();
    virtual void Vfn026();
    virtual void Vfn027();
    virtual void Vfn028();
    virtual void Vfn029();
    virtual void Vfn030();
    virtual void Vfn031();
    virtual void Vfn032();
    virtual void Vfn033();
    virtual void Vfn034();
    virtual void Vfn035();
    virtual void Vfn036();
    virtual void Vfn037();
    virtual void Vfn038();
    virtual void Vfn039();
    virtual void Vfn040();
    virtual void Vfn041();
    virtual void Vfn042();
    virtual void Vfn043();
    virtual void Vfn044();
    virtual void Vfn045();
    virtual void Vfn046();
    virtual void Vfn047();
    virtual void Vfn048();
    virtual void Vfn049();
    virtual void Vfn050();
    virtual void Vfn051();
    virtual void Vfn052();
    virtual void Vfn053();
    virtual void Vfn054();
    virtual void Vfn055();
    virtual void Vfn056();
    virtual void Vfn057();
    virtual void Vfn058();
    virtual void Vfn059();
    virtual void Vfn060();
    virtual void Vfn061();
    virtual void Vfn062();
    virtual void Vfn063();
    virtual void Vfn064();
    virtual void Vfn065();
    virtual void Vfn066();
    virtual void Vfn067();
    virtual void Vfn068();
    virtual void Vfn069();
    virtual void Vfn070();
    virtual void Vfn071();
    virtual void Vfn072();
    virtual void Vfn073();
    virtual void Vfn074();
    virtual void Vfn075();
    virtual void Vfn076();
    virtual void Vfn077();
    virtual void Vfn078();
    virtual void Vfn079();
    virtual void Vfn080();
    virtual void Vfn081();
    virtual void Vfn082();
    virtual void Vfn083();
    virtual void Vfn084();
    virtual void Vfn085();
    virtual void Vfn086();
    virtual void Vfn087();
    virtual void Vfn088();
    virtual void Vfn089();
    virtual void Vfn090();
    virtual void Vfn091();
    virtual void Vfn092();
    virtual void Vfn093();
    virtual void Vfn094();
    virtual void Vfn095();
    virtual void Vfn096();
    virtual void Vfn097();
    virtual void Vfn098();
    virtual void Vfn099();
    virtual void Vfn100();
    virtual void Vfn101();
    virtual void Vfn102();
    virtual void Vfn103();
    virtual void Vfn104();
    virtual void Vfn105();
    virtual void Vfn106();
    virtual void Vfn107();
    virtual void Vfn108();
    virtual void Vfn109();
    virtual void Vfn110();
    virtual void Vfn111();
    virtual void Vfn112();
    virtual void Vfn113();
    virtual void Vfn114();
    virtual void Vfn115();
    virtual void Vfn116();
    virtual void Vfn117();
    virtual void Vfn118();
    virtual void Vfn119();
    virtual void Vfn120();
    virtual void Vfn121();
    virtual void Vfn122();
    virtual void Vfn123();
    virtual void Vfn124();
    virtual const NiPoint3_ext* GetPos();
    virtual void Vfn126();
    virtual void Vfn127();
    virtual void Vfn128();
    virtual void Vfn129();
    virtual void Vfn130();
    virtual void Vfn131();
    virtual void Vfn132();
    virtual void Vfn133();
    virtual void Vfn134();
    virtual void Vfn135();
    virtual void Vfn136();
    virtual void Vfn137();
    virtual void Vfn138();
    virtual void Vfn139();
    virtual void Vfn140();
    virtual void Vfn141();
    virtual void Vfn142();
    virtual void Vfn143();
    virtual void Vfn144();
    virtual void Vfn145();
    virtual void Vfn146();
    virtual void Vfn147();
    virtual void Vfn148();
    virtual void Vfn149();
    virtual void Vfn150();
    virtual void Vfn151();
    virtual void Vfn152();
    virtual void Vfn153();
    virtual void Vfn154();
    virtual void Vfn155();
    virtual void Vfn156();
    virtual void Vfn157();
    virtual void Vfn158();
    virtual void Vfn159();
    virtual void Vfn160();
    virtual void Vfn161();
    virtual void Vfn162();
    virtual void Vfn163();
    virtual void Vfn164();
    virtual void Vfn165();
    virtual void Vfn166();
    virtual void Vfn167();
    virtual void Vfn168();
    virtual void Vfn169();
    virtual void Vfn170();
    virtual void Vfn171();
    virtual void Vfn172();
    virtual void Vfn173();
    virtual void Vfn174();
    virtual float GetCurrentTargetDistance(bool abFlag);
    const NiPoint3_ext& FUN_008b3d50();
    float ProcessCoverLOSResult();
};

struct PC7d : public Actor
{
};

class PathingRequest
{
  public:
};

struct Setting_S
{
};
struct GlobalObject_0044f440 : public Setting_S
{
};

struct Twin_0084d030
{
};
struct AnimIdle : public Twin_0084d030
{
};

struct Arr
{
    Actor** GetAt(int aiIndex);
};
struct GlobalObject_009e9bb0 : public Arr
{
};

struct ActorAvoidEntry
{
    Actor* pActor;
    float fValue;
    ActorAvoidEntry(Actor* apActor, float afValue);
};

struct ActorAvoidEntryList
{
};


extern PC7d* g_thePlayer;

// @fnv 0x009e5690
void EvaluateAvoidance(Actor* apActor, PathingRequest* apRequest, unsigned int auiFlags, const NiPoint3_ext* apDir,
                       void* apData, ActorAvoidEntryList* apList)
{
    float fTime;
    float fSpeed;
    float fScaleMultiplier;
    float fCosThreshold;
    float afValueAfterThirdFloat;
    float fDistance;
    Actor* pTargetActor;
    ThreeByThreeMatrix kRot;
    reinterpret_cast<::FUN_009e1640_shell *>(&(kRot))->SetRotationMatrix(apActor->GetCurrentTargetDistance(false));
    NiPoint3_ext kIntersectionOffset = kRot * *apDir;
    float fTravelTime;
    NiPoint3_ext kNormDir = kIntersectionOffset;
    NiPoint3_ext akStart;
    float fRadius;
    float fAheadDist;

    fTime = reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::fnv_009e5690::AnimIdle *>(&::g_timeGlobal))))->GetStoredFloatValue();
    fSpeed = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5690::GlobalObject_0044f440 *>(&::g_011f2b98))))));
    fScaleMultiplier = reinterpret_cast<::NiPoint3 *>(&(kNormDir))->GetLengthSquared();
    fTravelTime = fScaleMultiplier / fTime;
    fAheadDist = fSpeed * fTravelTime;
    akStart = *apActor->GetPos();
    fRadius = ::GetFloatAtOffset68((const char *)(apRequest));
    fDistance = 0.0f;
    fCosThreshold = ::DAT_011a5cf4;
    afValueAfterThirdFloat = fRadius + fAheadDist;
    pTargetActor = ((::fnv_009e5690::Actor *)(::FUN_009e55e0((::TES *)(apActor))));
    if (auiFlags & 0x200)
        fCosThreshold = ::DAT_011a5cfc;

    ::fnv_009e54a0::UpdateAliveActorList();
    for (unsigned int i = 0; i < ::DAT_011f2aa0; i++)
    {
        float fDistSq;
        NiPoint3_ext kDelta;
        float fLOS;
        Actor* pAvoidActor;
        pAvoidActor = *(*reinterpret_cast<::fnv_009e5690::GlobalObject_009e9bb0 *>(&::g_011f2bf8)).GetAt(i);
        if (pAvoidActor != apActor)
        {
            kDelta = *pAvoidActor->GetPos();
            reinterpret_cast<::NiPoint3 *>(&(kDelta))->Subtract((const ::NiPoint3 &)(akStart));
            fDistSq = reinterpret_cast<::FUN_00595c80_shell *>((void *)&(kDelta))->GetSquaredXYLength();
            if (fDistSq > ::CombatWeapons::DAT_0106b798)
                continue;
            fLOS = pAvoidActor->ProcessCoverLOSResult();
            if (fRadius * ::DAT_01026998 <= fLOS)
            {
                NiPoint3_ext kRelOffset;
                float fOffsetLength;
                float fAvoidDist;
                float fTimeToTarget;
                float fOtherDist;
                kRelOffset = kIntersectionOffset;
                if (reinterpret_cast<::FUN_004938e0_shell *>((pAvoidActor))->FUN_004938e0())
                {
                    ThreeByThreeMatrix kOtherRot;
                    reinterpret_cast<::FUN_009e1640_shell *>(&(kOtherRot))->SetRotationMatrix(pAvoidActor->GetCurrentTargetDistance(false));
                    NiPoint3_ext kOtherOffset = kOtherRot * pAvoidActor->FUN_008b3d50();
                    reinterpret_cast<::NiPoint3 *>(&(kRelOffset))->Subtract((const ::NiPoint3 &)(kOtherOffset));
                }
                fOffsetLength = reinterpret_cast<::NiPoint3 *>(&(kRelOffset))->GetLengthSquared();
                if (fDistSq > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5690::GlobalObject_0044f440 *>(&::g_011f2b8c)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5690::GlobalObject_0044f440 *>(&::g_011f2b8c)))))))
                {
                    NiPoint3_ext kToOther = *pAvoidActor->GetPos();
                    reinterpret_cast<::NiPoint3 *>(&(kToOther))->Subtract((const ::NiPoint3 &)(akStart));
                    NiPoint3_ext kToOtherDir = kToOther;
                    reinterpret_cast<::FUN_004a0c10_s *>(&(kToOtherDir))->FUN_004a0c10();
                    if (reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kToOtherDir))->DotProduct((void *)&(kNormDir)) < ::_DAT_01012060)
                        continue;
                }
                fTimeToTarget = fOffsetLength / fTime;
                fOtherDist = fSpeed * fTimeToTarget;
                fAvoidDist = fRadius + fOtherDist;
                if (fAvoidDist < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5690::GlobalObject_0044f440 *>(&::g_011f2b8c)))))))
                    fAvoidDist = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5690::GlobalObject_0044f440 *>(&::g_011f2b8c))))));
                if (::fnv_009e6900::FUN_009e6900((::fnv_009e6900::Ref *)(apActor), (::fnv_009e6900::Group *)(apData), (::fnv_009e6900::Ref *)(pAvoidActor), (*(const ::fnv_009e6900::Pt3 *)(&akStart)), (*(const ::fnv_009e6900::Pt3 *)(&kRelOffset)), fAvoidDist, fCosThreshold,
                                 &fDistance, false))
                    reinterpret_cast<::FUN_009e99a0_cls *>((apList))->FUN_009e99a0((unsigned int)&(const ::fnv_009e5690::ActorAvoidEntry &)(ActorAvoidEntry(pAvoidActor, fDistance)));
            }
        }
    }

    if (::fnv_009e6900::FUN_009e6900((::fnv_009e6900::Ref *)(apActor), (::fnv_009e6900::Group *)(apData), (::fnv_009e6900::Ref *)(g_thePlayer), (*(const ::fnv_009e6900::Pt3 *)(&akStart)), (*(const ::fnv_009e6900::Pt3 *)(&kIntersectionOffset)), fAheadDist, fCosThreshold,
                     &fDistance, false))
        reinterpret_cast<::FUN_009e99a0_cls *>((apList))->FUN_009e99a0((unsigned int)&(const ::fnv_009e5690::ActorAvoidEntry &)(ActorAvoidEntry(g_thePlayer, fDistance)));
}
}  // namespace fnv_009e5690

namespace fnv_009e77d0 {
class PathingGraphNode;
class NiPoint3_ext : public NiPoint3
{
  public:
    NiPoint3_ext();
    NiPoint3_ext operator-(const NiPoint3&) const;
    float Dot(const NiPoint3&) const;
};
struct TESObjectREFR
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual const NiPoint3& GetPos() const;
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual float GetCurrentTargetDistance(int);
};
class PathingLocationEx
{
  public:
    PathingLocationEx(const NiPoint3&, TESObjectREFR*);
    ~PathingLocationEx();
    virtual void SaveGame(BGSSaveGameBuffer*);
    NiPoint3 Location;
    void* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    unsigned char ucPad;
};
class PathingGraphNode
{
  public:
    PathingLocationEx& FUN_00717e50();
};
class PathingSolution
{
  public:
};
struct Flt
{
    operator PathingSolution*() const;
};
struct FUN_009e3c00_cls
{
    void AdvanceAlongPath(float);
};
struct FUN_009e77d0_cls : public DetailedActorPathHandler
{
    void UpdatePathTether(float);
};

// @fnv 0x009e77d0
void FUN_009e77d0_cls::UpdatePathTether(float afPercentTraveled)
{
    m_fPathValue2 = reinterpret_cast<::fnv_006e78d0::FUN_006e78d0_shell *>((((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)))->GetTotalPathLength();
    m_fSplineParameter = reinterpret_cast<::fnv_006e8680::FUN_006e7990_shell *>((((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)))->FindSegmentAtFraction(afPercentTraveled, m_fPathValue2, &m_uiPathPointIndex);
    if (m_bPathFlag5)
    {
        m_bPathFlag5 = false;
        if (m_fPathValue2 == ::_DAT_01012060)
        {
            m_uiPathPointIndex = ::GetObjectFlags((char *)(((PathingSolution*)*(const Flt*)&pCurrentPathingSolution))) - 1;
            m_fSplineParameter = (float)m_uiPathPointIndex;
            m_kPathVector3 =
                reinterpret_cast<::TaskQueueInterface *>((void *)&((*(::fnv_009e77d0::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>((((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)))->FUN_006b05a0())).FUN_00717e50()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
            m_kPathVector4 = (*(TESObjectREFR**)&this->pActor)->GetPos();
            m_bPathFlag5 = false;
            return;
        }
        NiPoint3_ext oldDirVec = static_cast<const NiPoint3_ext&>(m_kPathVector3) - m_kPathVector4;
        oldDirVec.z = 0;
        NiPoint3 actorLoc = (*(TESObjectREFR**)&this->pActor)->GetPos();
        NiPoint3_ext actorDirVec = static_cast<const NiPoint3_ext&>(m_kPathVector3) - actorLoc;
        float factDotCheck = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(actorDirVec))->DotProduct((void *)&(oldDirVec));
        bool bpastGoal = factDotCheck < ::_DAT_01012060;
        float fcheck5 = ::DAT_01020998 / m_fPathValue2;
        float fcheck20 = fcheck5 * 4.0;
        float fdot;
        float fbestSqrTetherDist = 3.402823466e+38f;
        float fbestSplineT = 0;
        unsigned int ibestNode = 0;
        NiPoint3_ext actorToTetherDir;
        NiPoint3_ext newTetherLoc;
        bool botherSide = false;
        unsigned int itempNode;
        float ftempSplineT;
        float fsqrDist;
        for (int i = 0; i < 4; i++)
        {
            ftempSplineT =
                reinterpret_cast<::fnv_006e8680::FUN_006e7990_shell *>((((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)))->FindSegmentAtFraction(afPercentTraveled + fcheck5 + i * fcheck20, m_fPathValue2, &itempNode);
            reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>((((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)))->GetLocationAtSplineParameter(ftempSplineT, &newTetherLoc);
            actorToTetherDir = newTetherLoc - actorLoc;
            actorToTetherDir.z = 0;
            fdot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(actorToTetherDir))->DotProduct((void *)&(oldDirVec));
            fsqrDist = reinterpret_cast<::FUN_00595c80_shell *>((void *)&(actorToTetherDir))->GetSquaredXYLength();
            if ((!bpastGoal && fdot < ::_DAT_01012060) || (bpastGoal && fdot > ::_DAT_01012060))
            {
                if (botherSide)
                {
                    if (fsqrDist < fbestSqrTetherDist)
                    {
                        fbestSqrTetherDist = fsqrDist;
                        ibestNode = itempNode;
                        fbestSplineT = ftempSplineT;
                        fbestSqrTetherDist = fsqrDist;
                    }
                }
                else
                {
                    botherSide = true;
                    ibestNode = itempNode;
                    fbestSplineT = ftempSplineT;
                    fbestSqrTetherDist = fsqrDist;
                }
            }
            else if (fsqrDist < fbestSqrTetherDist)
            {
                ibestNode = itempNode;
                fbestSplineT = ftempSplineT;
                fbestSqrTetherDist = fsqrDist;
            }
        }
        reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>((((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)))->GetLocationAtSplineParameter(fbestSplineT, &m_kPathVector3);
        m_uiPathPointIndex = ibestNode;
        m_fSplineParameter = fbestSplineT;
        m_kPathVector4 = actorLoc;
    }
    else
    {
        reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>((((PathingSolution*)*(const Flt*)&pCurrentPathingSolution)))->GetLocationAtSplineParameter(m_fSplineParameter, &m_kPathVector3);
        m_kPathVector4 = m_kPathVector3;
        if (afPercentTraveled > ::_DAT_01012060)
        {
            PathingLocationEx tetherNavMeshLoc(m_kPathVector3, *(TESObjectREFR**)&this->pActor);
            NiPoint3 snapLocation = m_kPathVector3;
            ::GetNavMeshHeight((::PathingLocation *)(::fnv_009e77d0::PathingLocationEx *)(&tetherNavMeshLoc), &snapLocation.z);
            float fheading = (*(TESObjectREFR**)&this->pActor)->GetCurrentTargetDistance(0);
            reinterpret_cast<::fnv_008ad1c0::MoveSelf454 *>(((*(TESObjectREFR**)&this->pActor)))->FUN_008ad1c0((int)&(snapLocation), fheading, ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>(((*(TESObjectREFR**)&this->pActor)))->GetTarget())),
                               ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((*(TESObjectREFR**)&this->pActor)))->FUN_00575d70())), 1, 1);
        }
        ((FUN_009e3c00_cls*)this)->AdvanceAlongPath(0.0f);
    }
}
}  // namespace fnv_009e77d0

namespace fnv_009e8000 {
struct FUN_009e8000_shell : public DetailedActorPathHandler
{
    int UpdatePathingGoal();
};

struct Flt
{
    operator unsigned int() const;
};
namespace std {
float abs(float);
}
bool FUN_009e8670(unsigned int);
extern double DAT_01092508;
extern float DAT_011a5d00;

struct FUN_00595c80_shell : public NiPoint3
{
};
struct NiPoint3_sub : public FUN_00595c80_shell
{
    NiPoint3 operator-(const NiPoint3&) const;
};
struct NiPoint3_ext : public NiPoint3_sub
{
    float Dot(const NiPoint3&) const;
};
struct NP3S : public NiPoint3_ext
{
};
struct BaseS : public NiPoint3_ext
{
    BaseS();
};
struct LocS
{
};
struct TeleportableReference
{
    const NiPoint3& GetPosition();
};
class PathingGraphNode
{
  public:
    bool IsTransitionNode();
};
class PacketNodeRecord;
struct PathingSolution
{
};
struct FUN_006e7970_shell
{
};
struct BGSTerrainManager
{
};
struct BGSCameraPath
{
};
struct ActorV_S
{
};
struct PathingRequest_S
{
};
struct MobileObject
{
    virtual void Vfunc000();
    virtual void Vfunc001();
    virtual void Vfunc002();
    virtual void Vfunc003();
    virtual void Vfunc004();
    virtual void Vfunc005();
    virtual void Vfunc006();
    virtual void Vfunc007();
    virtual void Vfunc008();
    virtual void Vfunc009();
    virtual void Vfunc010();
    virtual void Vfunc011();
    virtual void Vfunc012();
    virtual void Vfunc013();
    virtual void Vfunc014();
    virtual void Vfunc015();
    virtual void Vfunc016();
    virtual void Vfunc017();
    virtual void Vfunc018();
    virtual void Vfunc019();
    virtual void Vfunc020();
    virtual void Vfunc021();
    virtual void Vfunc022();
    virtual void Vfunc023();
    virtual void Vfunc024();
    virtual void Vfunc025();
    virtual void Vfunc026();
    virtual void Vfunc027();
    virtual void Vfunc028();
    virtual void Vfunc029();
    virtual void Vfunc030();
    virtual void Vfunc031();
    virtual void Vfunc032();
    virtual void Vfunc033();
    virtual void Vfunc034();
    virtual void Vfunc035();
    virtual void Vfunc036();
    virtual void Vfunc037();
    virtual void Vfunc038();
    virtual void Vfunc039();
    virtual void Vfunc040();
    virtual void Vfunc041();
    virtual void Vfunc042();
    virtual void Vfunc043();
    virtual void Vfunc044();
    virtual void Vfunc045();
    virtual void Vfunc046();
    virtual void Vfunc047();
    virtual void Vfunc048();
    virtual void Vfunc049();
    virtual void Vfunc050();
    virtual void Vfunc051();
    virtual void Vfunc052();
    virtual void Vfunc053();
    virtual void Vfunc054();
    virtual void Vfunc055();
    virtual void Vfunc056();
    virtual void Vfunc057();
    virtual void Vfunc058();
    virtual void Vfunc059();
    virtual void Vfunc060();
    virtual void Vfunc061();
    virtual void Vfunc062();
    virtual void Vfunc063();
    virtual void Vfunc064();
    virtual void Vfunc065();
    virtual void Vfunc066();
    virtual void Vfunc067();
    virtual void Vfunc068();
    virtual void Vfunc069();
    virtual void Vfunc070();
    virtual void Vfunc071();
    virtual void Vfunc072();
    virtual void Vfunc073();
    virtual void Vfunc074();
    virtual void Vfunc075();
    virtual const char* GetEditorID();
    virtual void Vfunc077();
    virtual void Vfunc078();
    virtual void Vfunc079();
    virtual void Vfunc080();
    virtual void Vfunc081();
    virtual void Vfunc082();
    virtual void Vfunc083();
    virtual void Vfunc084();
    virtual void Vfunc085();
    virtual void Vfunc086();
    virtual void Vfunc087();
    virtual void Vfunc088();
    virtual void Vfunc089();
    virtual void Vfunc090();
    virtual void Vfunc091();
    virtual void Vfunc092();
    virtual void Vfunc093();
    virtual void Vfunc094();
    virtual void Vfunc095();
    virtual void Vfunc096();
    virtual void Vfunc097();
    virtual void Vfunc098();
    virtual void Vfunc099();
    virtual void Vfunc100();
    virtual void Vfunc101();
    virtual void Vfunc102();
    virtual void Vfunc103();
    virtual void Vfunc104();
    virtual void Vfunc105();
    virtual void Vfunc106();
    virtual void Vfunc107();
    virtual void Vfunc108();
    virtual void Vfunc109();
    virtual void Vfunc110();
    virtual void Vfunc111();
    virtual void Vfunc112();
    virtual void Vfunc113();
    virtual void Vfunc114();
    virtual void Vfunc115();
    virtual void Vfunc116();
    virtual void Vfunc117();
    virtual void Vfunc118();
    virtual void Vfunc119();
    virtual void Vfunc120();
    virtual void Vfunc121();
    virtual void Vfunc122();
    virtual void Vfunc123();
    virtual void Vfunc124();
    virtual const NiPoint3& GetPos();
};

// Checks the actor's distance to its pathing goal or transition node and returns a pathing status code (0, 2 or 5).
// @fnv 0x009e8000
int FUN_009e8000_shell::UpdatePathingGoal()
{
    if (this->m_bPathFlag4)
    {
        if (this->m_uiPathPointIndex + 2 >= ::GetObjectFlags((char*)(unsigned int)*(Flt*)((char*)this + 0xc)))
        {
            BaseS diff;
            bool bPast = false;
            if (this->m_uiPathPointIndex + 2 ==
                ::GetObjectFlags((char*)(unsigned int)*(Flt*)((char*)this + 0xc)))
                (NiPoint3&)diff =
                    (*(::fnv_009e8000::NP3S *)&(reinterpret_cast<::TaskQueueInterface *>((((LocS*)&((TeleportableReference*)reinterpret_cast<::FUN_006e7970_shell *>((((FUN_006e7970_shell*)(unsigned int)*(Flt*)((char*)this + 0xc))))->FUN_006e7970(this->m_uiPathPointIndex))
                         ->GetPosition())))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))) -
                    (*(MobileObject**)&this->pActor)->GetPos();
            else
                bPast = true;
            if (bPast || reinterpret_cast<::FUN_00595c80_shell *>(&(diff))->GetSquaredXYLength() <= DAT_01092508)
            {
                unsigned int icurrentSize = ::GetObjectFlags((char*)(unsigned int)*(Flt*)((char*)this + 0xc));
                unsigned int iupdateNode = *(unsigned short*)(*(char**)&this->m_pActorMover + 0x42) > 0
                                               ? *(unsigned short*)(*(char**)&this->m_pActorMover + 0x42) - 1
                                               : *(unsigned short*)(*(char**)&this->m_pActorMover + 0x42);
                switch (::ConstructAndCallMethod((unsigned int)*(Flt*)((char*)this + 0x10),
                                               (unsigned int)*(Flt*)((char*)this + 0xc), iupdateNode,
                                               (int)&((*(MobileObject**)&this->pActor)->GetPos())))
                {
                case 2:
                case 3:
                    this->m_bPathFlag4 =
                        (*(::fnv_009e8000::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>((((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))))->FUN_006b05a0())).IsTransitionNode();
                    *(unsigned short*)(*(char**)&this->m_pActorMover + 0x42) =
                        reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)(unsigned int)*(Flt*)((char*)this + 0xc))))->GetMinLevel();
                    return 0;
                    break;
                case 0:
                    break;
                case 4:
                    break;
                case 1:
                    return 5;
                }
                this->m_bPathFlag4 = false;
            }
        }
    }
    else
    {
        bool bgoalReached = false;
        BaseS goal;
        BaseS diff;
        float fdistanceSqr = 3.402823466e+38f;
        float fgoalRadiusTestSqr;
        if (!reinterpret_cast<::FUN_006b05d0_shell *>((((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))))->FUN_006b05d0() &&
            reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)(unsigned int)*(Flt*)((char*)this + 0xc))))->GetMinLevel() ==
                ::FUN_005a4320((char *)(((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc)))) - 1)
            (NiPoint3&)goal =
                (*(::fnv_009e8000::NP3S *)&(reinterpret_cast<::TaskQueueInterface *>((((LocS*)&((TeleportableReference*)((::fnv_009e8000::PacketNodeRecord *)(reinterpret_cast<::FUN_006e78b0_shell *>((((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))))->FUN_006e78b0(
                                  reinterpret_cast<::BGSTerrainManager *>((((BGSTerrainManager*)(unsigned int)*(Flt*)((char*)this + 0xc))))->GetMinLevel()))))
                     ->GetPosition())))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
        else
            (NiPoint3&)goal =
                (*(::fnv_009e8000::NP3S *)&(reinterpret_cast<::TaskQueueInterface *>((((LocS*)&(
                     (TeleportableReference*)&(*(::fnv_009e8000::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>((((PathingSolution*)(unsigned int)*(Flt*)((char*)this + 0xc))))->FUN_006b05a0())))
                     ->GetPosition())))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
        (NiPoint3&)diff = goal - (*(MobileObject**)&this->pActor)->GetPos();
        fdistanceSqr = reinterpret_cast<::FUN_00595c80_shell *>(&(diff))->GetSquaredXYLength();
        fgoalRadiusTestSqr = this->m_fPathValue14;
        bgoalReached = fdistanceSqr <= this->m_fPathValue14;
        if (bgoalReached)
        {
            bool bvalidCheck = true;
            if (FUN_009e8670((unsigned int)*(Flt*)((char*)this + 0x10)) &&
                this->m_fPathValue14 > DAT_011a5d00 && fdistanceSqr > DAT_011a5d00)
            {
                NiPoint3 tetherDir = *(NiPoint3_sub*)((char*)this + 0x34) - this->m_kPathVector4;
                tetherDir.z = 0.0f;
                NiPoint3 actorToTetherDir =
                    *(NiPoint3_sub*)((char*)this + 0x34) - (*(MobileObject**)&this->pActor)->GetPos();
                actorToTetherDir.z = 0.0f;
                float fdot = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(((NiPoint3_ext&)tetherDir)))->DotProduct((void *)&(actorToTetherDir));
                if (fdot >= ::_DAT_01012060 && this->m_fPathValue5 == ::_DAT_01012060 &&
                    this->m_fPathValue8 == ::_DAT_01012060)
                    bvalidCheck = false;
            }
            if (bvalidCheck)
            {
                if (!reinterpret_cast<::FUN_005a2030_shell *>((void *)((*(MobileObject**)&this->pActor)))->FUN_005a2030())
                {
                    if (std::abs(diff.z) <=
                        reinterpret_cast<::PathingRequest *>((((PathingRequest_S*)(unsigned int)*(Flt*)((char*)this + 0x10))))->GetSmoothingRandomness())
                    {
                        return 5;
                    }
                    else if (this->m_uiPathPointIndex + 1 >=
                                 ::GetObjectFlags((char*)(unsigned int)*(Flt*)((char*)this + 0xc)) &&
                             !reinterpret_cast<::FUN_005a2030_shell *>((void *)((*(MobileObject**)&this->pActor)))->FUN_005a2030())
                    {
                        ::FUN_005b5e40();
                        return 2;
                    }
                }
                else
                {
                    float fzdeltaThresold = ::FUN_0040ebd0(
                        reinterpret_cast<::PathingRequest *>((((PathingRequest_S*)(unsigned int)*(Flt*)((char*)this + 0x10))))->GetSmoothingRandomness(),
                        reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((void *)(((ActorV_S*)*(MobileObject**)&this->pActor)))->GetActorHeight());
                    if (std::abs(diff.z) <= fzdeltaThresold)
                        return 5;
                }
            }
        }
    }
    return 0;
}
}  // namespace fnv_009e8000


// @fnv 0x00709d40
bool __cdecl FUN_00709d40()
{
    return ::FUN_004b71d0();
}

struct Actor;

struct ActorAvoidanceEntry
{
    Actor* pActor;
    float m_fPackageValue;
};

struct ActorAvoidanceDataArray
{
    ActorAvoidanceEntry* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;

    virtual ~ActorAvoidanceDataArray();
    void FUN_00983720(unsigned int auiIndex, unsigned int auiCount);
};

// @fnv 0x00983720
void ActorAvoidanceDataArray::FUN_00983720(unsigned int auiIndex, unsigned int auiCount)
{
    unsigned int uiMoveCount;

    uiMoveCount = FUN_0042f5a0(uiSize - auiIndex - auiCount, auiCount);
    reinterpret_cast<::FUN_0072ba80_shell *>(this)->FUN_0072ba80(pBuffer + auiIndex, auiCount);
    reinterpret_cast<::FUN_00692480 *>(this)->Method((char *)(::ActorAvoidanceEntry *)(pBuffer + auiIndex), (char *)(::ActorAvoidanceEntry *)(pBuffer + uiSize - uiMoveCount), uiMoveCount);
    uiSize -= auiCount;
}

namespace fnv_009a86e0 {
class TESObjectREFR
{
  public:
};

struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex(float afX, float afY, float afZ);
    NiPoint3Ex operator-(const NiPoint3&) const;
};


NiPoint3Ex FUN_009a8050(TESObjectREFR* apAttacker);
NiPoint3Ex FUN_009a87f0(NiPoint3Ex aFiringLocation, TESObjectREFR* apTarget, float afParam1, float afParam2,
                        int aiParam3);

// @fnv 0x009a86e0
NiPoint3Ex ComputeRelativeFiringAngle(TESObjectREFR* apAttacker, TESObjectREFR* apTarget, float afParam1,
                                      float afParam2, int aiParam3)
{
    NiPoint3Ex firingPos = FUN_009a8050(apAttacker);
    NiPoint3Ex kResult = FUN_009a87f0(firingPos, apTarget, afParam1, afParam2, aiParam3);
    kResult = kResult - (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((void *)(apAttacker))->GetData()));
    kResult.y = 0;
    if (kResult.x <= ::DAT_0101ff58)
        kResult.x += (double)6.2831855f;
    else if (kResult.x > (double)3.1415927f)
        kResult.x -= (double)6.2831855f;
    if (kResult.z <= ::DAT_0101ff58)
        kResult.z += (double)6.2831855f;
    else if (kResult.z > (double)3.1415927f)
        kResult.z -= (double)6.2831855f;
    return kResult;
}
}  // namespace fnv_009a86e0

struct TESObjectREFR;

struct NavMeshClosedDoorInfo
{
    TESObjectREFR* m_pDoorRef;
};
class NavMeshTriangle
{
  public:
};
class NavMesh
{
  public:
    NavMeshTriangle* GetTriangle(unsigned short);
    NavMeshClosedDoorInfo* GetClosedDoorInfo(unsigned short);
};

struct ClosedDoorPathFilter
{
    TESObjectREFR* pPathNodeDoor;
    bool bEnteredDoor;
    bool bExitedDoor;
    bool bStayedInDoor;

    virtual ~ClosedDoorPathFilter();
    bool CheckDoorTransition(NavMesh* apNavMesh1, unsigned short aTriangle1, unsigned int aEdge1, NavMesh* apNavMesh2,
                             unsigned short aTriangle2, unsigned int aEdge2);
};

// @fnv 0x009e26d0
bool ClosedDoorPathFilter::CheckDoorTransition(NavMesh* apNavMesh1, unsigned short aTriangle1, unsigned int aEdge1,
                                               NavMesh* apNavMesh2, unsigned short aTriangle2, unsigned int aEdge2)
{
    bool bInDoor1 = false;
    if (reinterpret_cast<::FUN_00691140_shell *>((apNavMesh1->GetTriangle(aTriangle1)))->FUN_00691140(0x1000))
    {
        NavMeshClosedDoorInfo* pDoorInfo1 = apNavMesh1->GetClosedDoorInfo(aTriangle1);
        if (pDoorInfo1 && (pDoorInfo1->m_pDoorRef == pPathNodeDoor || pPathNodeDoor == 0))
            bInDoor1 = true;
    }
    bool bInDoor2 = false;
    if (reinterpret_cast<::FUN_00691140_shell *>((apNavMesh2->GetTriangle(aTriangle2)))->FUN_00691140(0x1000))
    {
        NavMeshClosedDoorInfo* pDoorInfo2 = apNavMesh2->GetClosedDoorInfo(aTriangle2);
        if (pDoorInfo2 && (pDoorInfo2->m_pDoorRef == pPathNodeDoor || pPathNodeDoor == 0))
            bInDoor2 = true;
    }
    if (!bInDoor1)
        bStayedInDoor = false;
    if (!bInDoor2)
        bStayedInDoor = false;
    if (bInDoor1 && !bInDoor2)
        bExitedDoor = true;
    if (!bInDoor1 && bInDoor2)
        bEnteredDoor = true;
    return true;
}

namespace fnv_009e3110 {
struct TESWorldSpace;
struct TESObjectCELL;
struct TeleportableReference;

struct Flt
{
    operator unsigned int() const;
};

class TESObjectREFR
{
  public:
};
struct TeleportableReference
{
    TESObjectREFR* m_pLinkedDoorReference;
};
struct PathingLocation
{
    TESObjectCELL* FUN_006dd4f0() const;
};
class PathingGraphNode
{
  public:
    const PathingLocation& FUN_00717e50() const;
};
class PathingSolution
{
  public:
};
struct TESHelper
{
};
extern TESHelper* g_TES;
class PlayerCharacter : public TESObjectREFR
{
};
extern PlayerCharacter* g_thePlayer;

struct FUN_009e3110_t : public DetailedActorPathHandler
{
    bool IsPathReachableToPlayer() const;
};

// Scans pathing nodes from the current index onward, returning true if any node or its linked door lies in the player's cell or world space.
// @fnv 0x009e3110
bool FUN_009e3110_t::IsPathReachableToPlayer() const
{
    unsigned int iscanNodes;
    bool bcompareCells;
    unsigned int inumNodes;
    TESWorldSpace* pplayerWorld;
    TESObjectCELL* pplayerCell;

    if (!(unsigned int)*(const Flt*)&pCurrentPathingSolution ||
        !reinterpret_cast<::Mover *>((((PathingSolution*)(unsigned int)*(const Flt*)&pCurrentPathingSolution)))->FUN_009dc530())
        return false;

    inumNodes = ::GetObjectFlags((char *)(((PathingSolution*)(unsigned int)*(const Flt*)&pCurrentPathingSolution)));
    iscanNodes = m_uiPathPointIndex + 1;
    bcompareCells = true;
    pplayerCell = ((::fnv_009e3110::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((g_thePlayer))->GetTarget()));
    pplayerWorld = ((::fnv_009e3110::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((g_thePlayer))->FUN_00575d70()));
    if (!pplayerCell)
    {
        pplayerCell = ((::fnv_009e3110::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((g_TES))->GetPrevPath()));
        if (!pplayerCell)
            bcompareCells = false;
    }
    if (!bcompareCells && !pplayerWorld)
    {
        pplayerWorld = ((::fnv_009e3110::TESWorldSpace *)(reinterpret_cast<::EffectSetting *>((g_TES))->GetHitSound()));
        if (!pplayerWorld)
            return false;
    }

    for (; iscanNodes < inumNodes; ++iscanNodes)
    {
        const PathingGraphNode* pnode;
        const PathingLocation* ploc;

        pnode = ((const ::fnv_009e3110::PathingGraphNode *)(reinterpret_cast<::FUN_006e7970_shell *>((((PathingSolution*)(unsigned int)*(const Flt*)&pCurrentPathingSolution)))->FUN_006e7970(iscanNodes)));
        if (!pnode)
            continue;
        ploc = &pnode->FUN_00717e50();
        if (bcompareCells)
        {
            if (pplayerCell == ploc->FUN_006dd4f0())
                return true;
        }
        else if (pplayerWorld == ((::fnv_009e3110::TESWorldSpace *)(reinterpret_cast<::BGSTerrainManager *>((void *)(ploc))->GetMinLevel())))
        {
            return true;
        }
        if (reinterpret_cast<::FUN_006e2330_shell *>((void *)(pnode))->FUN_006e2330())
        {
            TeleportableReference* ptel;
            TESObjectREFR* plinkedDoor;
            TESObjectREFR* pdoor;

            pdoor = ((::fnv_009e3110::TESObjectREFR *)(::GetField38((char *)(pnode))));
            if (!pdoor)
                continue;
            ptel = ((::fnv_009e3110::TeleportableReference *)(reinterpret_cast<::TESObjectREFR *>((pdoor))->GetExtraRadioData()));
            if (!ptel)
                continue;
            plinkedDoor = ((::fnv_009e3110::TESObjectREFR *)(::FUN_00559450((int *)(ptel))));
            if (!plinkedDoor)
                continue;
            if (bcompareCells)
            {
                if (pplayerCell == ((::fnv_009e3110::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((plinkedDoor))->GetTarget())))
                    return true;
            }
            else if (pplayerWorld == ((::fnv_009e3110::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((plinkedDoor))->FUN_00575d70())))
            {
                return true;
            }
        }
    }
    return false;
}
}  // namespace fnv_009e3110

struct FUN_009e3970Class
{
    float GetValue();
};

// @fnv 0x009e3970
float FUN_009e3970Class::GetValue()
{
    return *(float*)((char*)this + 0x560);
}

class NavMeshPtr;
class TESObjectCELL;
class PathingLocation
{
  public:
public:
    ::TESObjectCELL *GetContainingCell();
public:
    bool FindNavMeshTriangle(::NavMeshPtr &, unsigned short &);
};
class PathingGraphNode
{
  public:
    PathingLocation& GetLocation();
};
class PathingSolution
{
  public:
};
struct FUN_009e3a70_shell : public DetailedActorPathHandler
{
    NiPoint3 GetNextPathPoint();
};
// Returns the point of the next path node after the current index, the last node if none remain, or the actor's position when there is no path.
// @fnv 0x009e3a70
NiPoint3 FUN_009e3a70_shell::GetNextPathPoint()
{
    if (pCurrentPathingSolution && ::GetObjectFlags((char *)((pCurrentPathingSolution).operator->())) > 0)
    {
        if (m_uiPathPointIndex + 1 < ::GetObjectFlags((char *)((pCurrentPathingSolution).operator->())))
            return reinterpret_cast<::TaskQueueInterface *>((void *)&(((::PathingGraphNode *)(reinterpret_cast<::FUN_006e7970_shell *>(((pCurrentPathingSolution).operator->()))->FUN_006e7970(m_uiPathPointIndex + 1)))->GetLocation()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
        else
            return reinterpret_cast<::TaskQueueInterface *>((void *)&((*(::PathingGraphNode *)(reinterpret_cast<::S_FUN_006b05a0 *>(((pCurrentPathingSolution).operator->()))->FUN_006b05a0())).GetLocation()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
    }
    else
    {
        return *pActor->GetPos();
    }
}

namespace std {
float __cdecl abs(float);
}

extern double DAT_010924a0;

struct MobileObjectLookingHelper
{
};
struct ST_00931e50
{
};

struct FUN_009e4c60_t : public DetailedActorPathHandler
{
    void UpdateLookingAngle(float afDeltaT, float afLookingAngle);
};

// @fnv 0x009e4c60
void FUN_009e4c60_t::UpdateLookingAngle(float afDeltaT, float afLookingAngle)
{
    float frotateMax;
    float fcurrentLooking;
    float fdir;
    float fclampedAngleDelta;
    float fangleDelta;

    fcurrentLooking = reinterpret_cast<::MobileObject *>((void *)((*(MobileObjectLookingHelper**)&this->pActor)))->GetLooking();
    frotateMax = afDeltaT * DAT_010924a0;
    fdir = 0;
    fangleDelta = std::abs(FUN_004b15e0(fcurrentLooking, afLookingAngle, &fdir));
    fclampedAngleDelta = fangleDelta;
    if (fclampedAngleDelta > frotateMax)
        fclampedAngleDelta = frotateMax;
    fcurrentLooking = fclampedAngleDelta * fdir + fcurrentLooking;
    reinterpret_cast<::FUN_00931d90_shell *>(((*(ST_00931e50**)&this->pActor)))->ClampLookAngle(fcurrentLooking);
}

struct FUN_009e5ab0_Class
{
    int m_iWordAt00;
    float m_iWordAt04;
    FUN_009e5ab0_Class* Init(int arg1, float arg2);
};

// @fnv 0x009e5ab0
FUN_009e5ab0_Class* FUN_009e5ab0_Class::Init(int aiValue, float afValue)
{
    m_iWordAt00 = aiValue;
    m_iWordAt04 = afValue;
    return this;
}

class BGSCameraPath;
template <class T> class NiTMallocInterface;

template <> class NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >
{
  public:
};

struct LH
{
    bool _ref_008256d0();
};

struct Arr
{
    TESObjectREFR** GetAt(int);
};

struct GlobalObject_00869b10
{
};

struct GlobalObject_009e9bb0
{
};


struct FUN_009e8690_shell : DetailedActorPathHandler
{
    void FUN_009e68c0();
    void RemoveRefFromPathHandler(TESObjectREFR* apRef);
};

struct FUN_009e20a0_Class
{
    unsigned char* m_data;
    unsigned char GetByteAtOffset9F();
};

// @fnv 0x009e20a0
unsigned char FUN_009e20a0_Class::GetByteAtOffset9F()
{
    return *(reinterpret_cast<unsigned char*>(this) + 0x9f);
}

struct LS3de0
{
    unsigned int Find(unsigned int& a, unsigned int b, bool(__cdecl* cmp)(int const*, int const*));
};


struct FUN_009e2660_Class
{
    bool Contains(unsigned int arg);
};

// Returns whether the container at offset 0x30 finds the given value, comparing against -1 to indicate presence.
// @fnv 0x009e2660
bool FUN_009e2660_Class::Contains(unsigned int auiValue)
{
    return ((LS3de0*)((char*)this + 0x30))->Find(auiValue, 0, (bool(__cdecl*)(int const*, int const*))((unsigned int (&)(unsigned int, unsigned int))::FUN_009a3830)) !=
           -1;
}

struct Flt
{
    operator unsigned int() const;
};

struct FUN_009e2830_This
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    Flt m_flt;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4c;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5c;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6c;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7c;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8c;
    unsigned int m_90;
    unsigned int m_94;
    unsigned int m_98;
    unsigned int m_9c;
    unsigned int m_a0;
    unsigned int m_a4;
    unsigned int m_a8;
    unsigned int m_ac;
    unsigned int m_b0;
    float m_fPathValue16;
    float GetFloatValue();
};

// @fnv 0x009e2830
float FUN_009e2830_This::GetFloatValue()
{
    if (!m_flt)
        return 0.0f;
    return m_fPathValue16;
}

struct FUN_009e3990;

struct FUN_009e3990
{
    bool IsPointValid(NiPoint3& arPoint);
};

// Copies the NiPoint3 stored at offset 0x34 of this object into arPoint and returns true.
// @fnv 0x009e3990
bool FUN_009e3990::IsPointValid(NiPoint3& arPoint)
{
    arPoint = *reinterpret_cast<const NiPoint3*>(reinterpret_cast<char*>(this) + 0x34);
    return true;
}

namespace fnv_009e68c0 {
struct List_009e03e0
{
};

struct FUN_009e68c0
{
    void Reset();
};

// Sets the flag at offset 0xd0 to 1, clears the list at 0x58, and zeroes the floats at 0x78 and 0x74.
// @fnv 0x009e68c0
void FUN_009e68c0::Reset()
{
    *(int*)((char*)this + 0xd0) = 1;
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)((char*)this + 0x58))))->RemoveAll();
    *(float*)((char*)this + 0x78) = 0.0f;
    *(float*)((char*)this + 0x74) = 0.0f;
}
}  // namespace fnv_009e68c0

struct FUN_009e8670
{
    char GetMethod();
};

// @fnv 0x009e8670
char FUN_009e8670::GetMethod()
{
    return ((char*)this)[0x9c];
}

struct NiRTTI;
struct NiObject
{
    virtual NiRTTI const* GetStreamableRTTI();
    void* FUN_00621a40();
};
struct FUN_00cac910_shell
{
};
// Calls GetReferenceFlags on this, then FUN_00458b20; if the returned code is nonzero, invokes FUN_00cac910 on it and returns that result.
// @fnv 0x00621a40
void* NiObject::FUN_00621a40()
{
    int code;
    void* result;
    code = ((int)(reinterpret_cast<::FUN_00620b80_shell *>((this))->GetReferenceFlags()));
    result = FUN_00458b20();
    if (code != 0)
    {
        reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>(this)->FUN_00c89720();
        result = ((void *)(reinterpret_cast<::CpuObject *>((((FUN_00cac910_shell*)code)))->FUN_00cac910()));
        reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>(this)->FUN_00c89720();
    }
    return result;
}

struct FUN_008b3d50_This
{
    char pad[0x190];
    TESForm* form;
    BSSimpleList<TESFile*>* FUN_008b3d50();
};

// @fnv 0x008b3d50
BSSimpleList<TESFile*>* FUN_008b3d50_This::FUN_008b3d50()
{
    return ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)(form))));
}

extern int DAT_01092484;
struct FUN_009e2690
{
    void* f0;
    int f4;
    unsigned char f8;
    unsigned char f9;
    unsigned char f10;
    FUN_009e2690(int);
};
// Initializes the object: calls SetVtable, sets f0 to &DAT_01092484, stores a in f4, and sets f8, f9 to 0 and f10 to 1.
// @fnv 0x009e2690
FUN_009e2690::FUN_009e2690(int aiValue)
{
    reinterpret_cast<::FUN_006cd650_shell *>((this))->SetVtable();
    f0 = &DAT_01092484;
    f4 = aiValue;
    f8 = 0;
    f9 = 0;
    f10 = 1;
}

struct S009e2860
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual float vf6();
    char _pad[0x68];
    float m_fPathValue2;
    float FUN_009e2860();
};
// @fnv 0x009e2860
float S009e2860::FUN_009e2860()
{
    float flength;
    flength = m_fPathValue2 - vf6();
    flength = FUN_00404010(flength, 0.0f);
    return flength;
}

void __cdecl FUN_005330e0(float&, float, float);
struct FakePathHandler
{
    virtual void vm0()
    {}
    virtual void vm1()
    {}
    virtual void vm2()
    {}
    virtual void vm3()
    {}
    virtual void vm4()
    {}
    virtual void vm5()
    {}
    virtual float vm6()
    {
        return 0.0f;
    }
    char _pad[0x68];
    float m_fPathValue2;
    float FUN_009e28a0();
};
// @fnv 0x009e28a0
float FakePathHandler::FUN_009e28a0()
{
    float fRatio;
    if (m_fPathValue2 <= ::_DAT_01012060)
        return 1.0f;
    fRatio = vm6() / m_fPathValue2;
    FUN_005330e0(fRatio, 0.0f, 1.0f);
    return fRatio;
}

struct FUN_009e2a80_Class
{
    int _pad[0x34];
    int m_iPathParameter2;
    bool FUN_009e2a80();
};

// @fnv 0x009e2a80
bool FUN_009e2a80_Class::FUN_009e2a80()
{
    return m_iPathParameter2 == 2;
}

struct FUN_009e3360_Class
{
    void SetMode(unsigned int mode);
};

// @fnv 0x009e3360
void FUN_009e3360_Class::SetMode(unsigned int mode)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x60) = mode;
}

struct FUN_009e3be0_class
{
    bool FUN_009e3be0();
};

// @fnv 0x009e3be0
bool FUN_009e3be0_class::FUN_009e3be0()
{
    return *(bool*)((char*)this + 0xde);
}

struct B006815c0
{
    int a;
    int b;
    int c;
    B006815c0();
};
struct POD12
{
    int a;
    int b;
    int c;
};
struct FUN_009e6870
{
    POD12 f0;
    B006815c0 fC;
    float f18;
    float f1C;
    int f20;
    FUN_009e6870(const POD12&, float, float, int);
};
// Initializes the object from a POD12 value and stores the two floats and the int into f18, f1C and f20.
// @fnv 0x009e6870
FUN_009e6870::FUN_009e6870(const POD12& aPOD12, float afValue1, float afValue2, int aiValue) : f0(aPOD12)
{
    f18 = afValue1;
    f1C = afValue2;
    f20 = aiValue;
}

struct Holder_9e9950
{
    void* vtable;
    Holder_9e9950* Initialize();
};
// Sets the vtable to DAT_01092640, calls InitBuffer with 0 and 0, and returns this.
// @fnv 0x009e9950
Holder_9e9950* Holder_9e9950::Initialize()
{
    vtable = (void*)&(*reinterpret_cast<int *>(&::fnv_009e9980::DAT_01092640));
    reinterpret_cast<::FUN_009e9b20_Class *>(this)->InitBuffer(0, 0);
    return this;
}

namespace fnv_009e9980 {
struct GlobalObject_00869f00
{
    void* m_p;
    void Clear(bool b);
};
struct FUN_009e9980_Class
{
    void* m_p;
    void FUN_009e9980();
};
// @fnv 0x009e9980
void FUN_009e9980_Class::FUN_009e9980()
{
    m_p = &DAT_01092640;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_009e9980

namespace fnv_009e2900 {
struct PathingSolution
{
    NiPoint3 GetPointAtDistance(float, float);
};
struct GO
{
    ~GO();
    void* m_pObject;
};
struct Flt : GO
{
    operator unsigned int();
};
struct SpObst : Flt
{
    SpObst(unsigned int*);
};
struct Actor_009e2900
{
};
struct Ref_009e2900
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual unsigned int GetFlags();
};

struct FUN_009e2900_t
{
    void* vtbl;
    TESObjectREFR* pActor;
    char* pRef;
    unsigned int pCurrentPathingSolution;
    char pad[0x70 - 0x10];
    float m_fSplineParameter;
    NiPoint3 GetPathingPosition(float afDeltaT) const;
};

// @fnv 0x009e2900
NiPoint3 FUN_009e2900_t::GetPathingPosition(float afDeltaT) const
{
    if (!(unsigned char)::GetByteAtOffset70(pRef))
    {
        SpObst pPathingSolution((unsigned int*)&pCurrentPathingSolution);
        if (pPathingSolution && ::GetObjectFlags((char *)(((PathingSolution*)(unsigned int)pPathingSolution))))
        {
            float fdistance;
            float fspeed;
            if (((Ref_009e2900*)pRef)->GetFlags() & 0x200)
                fspeed = reinterpret_cast<::fnv_00884eb0::FUN_00884eb0_shell *>((((Actor_009e2900*)pActor)))->FUN_00884eb0();
            else
                fspeed = reinterpret_cast<::fnv_00884dc0::FUN_00884dc0_shell *>((((Actor_009e2900*)pActor)))->FUN_00884dc0();
            fdistance = fspeed * afDeltaT;
            return ((PathingSolution*)(unsigned int)pPathingSolution)
                ->GetPointAtDistance(m_fSplineParameter, fdistance);
        }
        else
        {
            return *pActor->GetPos();
        }
    }
    else
    {
        return *pActor->GetPos();
    }
}
}  // namespace fnv_009e2900

namespace fnv_009e3c00 {
struct FUN_009e3c00_shell : public DetailedActorPathHandler
{
    void AdvanceAlongPath(float);
};

struct B006815c0
{
    float x, y, z;
    B006815c0();
};
struct PathingSolution
{
};
struct FUN_006e84b0_shell
{
};
struct BSSoundHandleEx
{
    ~BSSoundHandleEx();
};
struct Flt
{
    operator unsigned int();
};
struct FUN_009e5480_shell
{
};
struct DAPHView_009e3c00
{
    char pad0[8];
    BSSoundHandleEx* pForm;
    Flt m_pPathingSolution;
    char pad10[0x34 - 0x10];
    B006815c0 m_kPathVector3;
    char pad40[0x4c - 0x40];
    B006815c0 m_kPathVector4;
    char pad58[0x64 - 0x58];
    unsigned int m_uiPathPointIndex;
    char pad68[0x70 - 0x68];
    float m_fSplineParameter;
    char pad74[0xb4 - 0x74];
    float m_fPathValue16;
};

// @fnv 0x009e3c00
void FUN_009e3c00_shell::AdvanceAlongPath(float afDist)
{
    if (!::GetObjectFlags((char *)(((PathingSolution*)(unsigned int)((DAPHView_009e3c00*)this)->m_pPathingSolution))))
        return;
    if (((DAPHView_009e3c00*)this)->m_uiPathPointIndex + 1 >=
        ::GetObjectFlags((char *)(((PathingSolution*)(unsigned int)((DAPHView_009e3c00*)this)->m_pPathingSolution))))
        return;
    ((DAPHView_009e3c00*)this)->m_fPathValue16 =
        reinterpret_cast<::fnv_006e84b0::FUN_006e84b0_shell *>((((FUN_006e84b0_shell*)(unsigned int)((DAPHView_009e3c00*)this)->m_pPathingSolution)))->GetSplineLengthAtParameter(((DAPHView_009e3c00*)this)->m_fSplineParameter);
    ((DAPHView_009e3c00*)this)->m_kPathVector4 = ((DAPHView_009e3c00*)this)->m_kPathVector3;
    reinterpret_cast<::FUN_009e5480_shell *>((((FUN_009e5480_shell*)this)))->ResetPathState();
    B006815c0 newPoint;
    float fnewSplineT;
    if (afDist >= ::_DAT_01012060)
        reinterpret_cast<::fnv_006e7e70::FUN_006e7e70_shell *>((((PathingSolution*)(unsigned int)((DAPHView_009e3c00*)this)->m_pPathingSolution)))->FUN_006e7e70(((DAPHView_009e3c00*)this)->m_fSplineParameter, afDist, 1, (float *)(int *)((int*)&fnewSplineT),
                           (NiPoint3*)&newPoint);
    else
        reinterpret_cast<::fnv_006e7e70::FUN_006e7e70_shell *>((((PathingSolution*)(unsigned int)((DAPHView_009e3c00*)this)->m_pPathingSolution)))->FUN_006e7e70(((DAPHView_009e3c00*)this)->m_fSplineParameter, -afDist, 0, (float *)(int *)((int*)&fnewSplineT),
                           (NiPoint3*)&newPoint);
    ((DAPHView_009e3c00*)this)->m_fSplineParameter = fnewSplineT;
    ((DAPHView_009e3c00*)this)->m_kPathVector3 = newPoint;
    ((DAPHView_009e3c00*)this)->m_uiPathPointIndex = (int)((DAPHView_009e3c00*)this)->m_fSplineParameter;
    reinterpret_cast<::TESForm *>((((DAPHView_009e3c00*)this)->pForm))->ClearData();
}
}  // namespace fnv_009e3c00

namespace fnv_009e54a0 {
struct Setting_S
{
};
struct BSFadeNode
{
    bool FUN_00552470() const;
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
};
struct GlobalObject_00869b10
{
};
struct FUN_007ff8e0_shell
{
};
struct AnimIdle
{
};
struct bhkCharacterController_shell
{
};
struct NiTPrimitiveArray_unsigned_int_
{
};
struct StrArr
{
};
struct ProcessLists
{
};
struct FUN_009e54a0_ref
{
};
struct GlobalObject_0044f440;
struct GlobalObject_009e9bb0;
struct GameTimerRecord;
extern int DAT_011f2a9c;
extern int DAT_011f2aa4;

// Rebuilds the actor list when the idle section changes: clears it, sizes it to the alive actor count, and adds qualifying actors.
// @fnv 0x009e54a0
bool UpdateAliveActorList()
{
    int section = ((int)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((AnimIdle*)&(*reinterpret_cast<::fnv_009e54a0::GameTimerRecord *>(&::g_timeGlobal)))))->FUN_00825c00()));
    if (DAT_011f2aa4 != section)
    {
        BSSimpleList<Actor*>* pActorList = reinterpret_cast<::ProcessLists *>((((ProcessLists*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->GetAliveActorList();
        DAT_011f2aa4 = section;
        ::FUN_005e03d0((::NiTArray_Layout *)(((GlobalObject_00869b10*)&(*reinterpret_cast<::fnv_009e54a0::GlobalObject_009e9bb0 *>(&::g_011f2bf8)))));
        DAT_011f2a9c = ((BSSimpleListTESRaceSize*)pActorList)->GetSize();
        reinterpret_cast<::ViewerStrings *>((((StrArr*)&(*reinterpret_cast<::fnv_009e54a0::GlobalObject_009e9bb0 *>(&::g_011f2bf8)))))->SetSize(DAT_011f2a9c);
        ::DAT_011f2aa0 = 0;
        for (; pActorList; pActorList = ((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::Callees *>((pActorList))->FUN_00726070())))
        {
            Actor* actor = *((::Actor **)(new ((void *)(((FUN_009e54a0_ref*)pActorList))) ::Vec3()));
            if (!actor)
                continue;
            NiNode* node = actor->GetNiNode();
            if (!node)
                continue;
            if (!reinterpret_cast<::FUN_007ff8e0_shell *>((((FUN_007ff8e0_shell*)node)))->FUN_007ff8e0())
                continue;
            if (((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((actor))->FUN_009306d0())) && ((BSFadeNode*)node)->FUN_00552470() &&
                reinterpret_cast<::bhkCharacterController_shell *>((void *)(((bhkCharacterController_shell*)((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((actor))->FUN_009306d0())))))->FUN_008a3b50() >
                    *((float *)&(::FUN_00403e20((float *)(((Setting_S*)&(*reinterpret_cast<::fnv_009e54a0::GlobalObject_0044f440 *>(&::g_011f2bd0))))))))
                continue;
            ::DAT_011f2aa0++;
            reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)&(*reinterpret_cast<::fnv_009e54a0::GlobalObject_009e9bb0 *>(&::g_011f2bf8)))))->FUN_0096a610((int)&(*(unsigned int*)&actor));
        }
        return true;
    }
    else
    {
        return false;
    }
}
}  // namespace fnv_009e54a0

namespace fnv_009e6ba0 {
struct ActiveEffect;
struct Actor;
struct ActorCause;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct GameFormRecord;
struct DialogueResponse;
struct DetectionParameters;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WaterZone;
struct WeaponObject;
struct bhkCharacterController;
struct bhkNiCollisionObject;
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
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct NiMemObject
{
    char _pad_0[1];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
struct FUN_009e6ba0_shell : public DetailedActorPathHandler
{
    void UpdatePathingOrigin(PathingRequest*);
};

struct NiPoint3Ops : public NiPoint3
{
    NiPoint3Ops();
    NiPoint3Ops operator-(const NiPoint3& pt) const;
    NiPoint3Ops& operator-=(const NiPoint3& pt);
    float Length() const;
};

struct CellOps_9e6ba0
{
};

struct WorldOps_9e6ba0
{
};

struct RefrOps_9e6ba0
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual NiPoint3* GetPos();
};

struct ActorOps_9e6ba0 : public RefrOps_9e6ba0
{
    float GetRadius();
};

struct PlayerOps_9e6ba0
{
};

struct Setting_S
{
};

struct PathingLocation
{
    PathingLocation(RefrOps_9e6ba0* ref);
    PathingLocation(const NiPoint3& pt, RefrOps_9e6ba0* ref);
    ~PathingLocation();
    unsigned char data[0x28];
};

struct PathingRequestOps
{
};

class PathingSolution
{
  public:
};

template <class T> struct NiPointerOps
{
    T* m_pObject;
    operator T*() const;
};

template <class T> struct BSSimpleListOps
{
    T m_item;
    BSSimpleListOps<T>* m_pkNext;
    T& GetItem();
    BSSimpleListOps<T>* GetNext();
    bool IsEmpty();
};

struct PathHandlerOps : public ActorPathHandler
{
    virtual void V14();
    virtual bool IsFollowingDoorPath();
};


extern PlayerOps_9e6ba0* g_thePlayer;

// Validates the pathing solution and player state, then updates the tether and sets the request origin based on actor position, cell interior, and avoided actors.
// @fnv 0x009e6ba0
void FUN_009e6ba0_shell::UpdatePathingOrigin(PathingRequest* apRequest)
{
    if (!(PathingSolution*)(NiPointerOps<PathingSolution>&)((DetailedActorPathHandler*)this)->pCurrentPathingSolution ||
        !::GetObjectFlags((char *)(((PathingSolution*)(NiPointerOps<PathingSolution>&)((DetailedActorPathHandler*)this)->pCurrentPathingSolution))) ||
        reinterpret_cast<::PlayerCharacter *>((g_thePlayer))->IsSleepingOrResting())
    {
        ((DetailedActorPathHandler*)this)->eState = 0;
        return;
    }

    ((DetailedActorPathHandler*)this)->m_fPathValue16 = 0.0f;
    if (((DetailedActorPathHandler*)this)->m_bPathFlag5)
    {
        reinterpret_cast<::FUN_006d3ac0_Class *>((((PathingRequestOps*)apRequest)))->AssignPathingLocation((const ::PathingLocation &)((const ::fnv_009e6ba0::PathingLocation &)(PathingLocation(((DetailedActorPathHandler*)this)->m_kPathVector3,
                                        *(RefrOps_9e6ba0**)&this->pActor))));
        return;
    }

    if (((DetailedActorPathHandler*)this)->eState != 2)
        return;

    ((DetailedActorPathHandler*)this)->m_bPathFlag5 = true;
    NiPoint3 actorCurrent = *(*(RefrOps_9e6ba0**)&this->pActor)->GetPos();
    if (((DetailedActorPathHandler*)this)->m_bPathFlag3 || ((PathHandlerOps*)this)->IsFollowingDoorPath() ||
        ((DetailedActorPathHandler*)this)->m_bPathFlag1)
    {
        ((DetailedActorPathHandler*)this)->m_kPathVector3 = actorCurrent;
        ((DetailedActorPathHandler*)this)->m_kPathVector4 = actorCurrent;
        ((DetailedActorPathHandler*)this)->eState = 4;
        reinterpret_cast<::FUN_006d3ac0_Class *>((((PathingRequestOps*)apRequest)))->AssignPathingLocation((const ::PathingLocation &)((const ::fnv_009e6ba0::PathingLocation &)(PathingLocation(*(RefrOps_9e6ba0**)&this->pActor))));
        return;
    }
    else
    {
        float fnewLen = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::fnv_009e6ba0::NiPoint3Ops &)(((*(::fnv_009e6ba0::NiPoint3Ops *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((::fnv_009e6ba0::PathingLocation *)(::GetOffsetC((int)(((PathingRequestOps*)apRequest)))))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))) -
                         (*(::fnv_009e6ba0::NiPoint3Ops *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((::fnv_009e6ba0::PathingLocation *)(::FUN_006a9540((char *)(((PathingRequestOps*)apRequest)))))))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))))))->FUN_00589850();
        float fwaitDist = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e6ba0::Setting_S *>(&::g_011f2b68))))));
        if (((DetailedActorPathHandler*)this)->ByteAndFlagState & 0x200)
            fwaitDist += *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e6ba0::Setting_S *>(&::g_011f2b68))))));
        fwaitDist *= 2.0f;
        if (fnewLen < fwaitDist)
            fwaitDist = fnewLen * ::DAT_01011588;
        float fdiff =
            reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::fnv_009e6ba0::NiPoint3Ops &)((static_cast<NiPoint3Ops&>(actorCurrent) - ((DetailedActorPathHandler*)this)->m_kPathVector3)))->FUN_00589850();
        if (fdiff < fwaitDist)
        {
            float fupdateLen = fwaitDist - fdiff;
            reinterpret_cast<::fnv_009e3c00::FUN_009e3c00_shell *>((((PathHandlerOps*)this)))->AdvanceAlongPath(fupdateLen);
        }
        else
        {
            float fupdateLen = fdiff - fwaitDist;
            reinterpret_cast<::fnv_009e3c00::FUN_009e3c00_shell *>((((PathHandlerOps*)this)))->AdvanceAlongPath(-fupdateLen);
        }
    }

    bool bfixupTether = true;
    if (((::fnv_009e6ba0::CellOps_9e6ba0 *)(reinterpret_cast<::LowProcess *>(((*(RefrOps_9e6ba0**)&this->pActor)))->GetTarget())) &&
        reinterpret_cast<::TESObjectCELL *>((((::fnv_009e6ba0::CellOps_9e6ba0 *)(reinterpret_cast<::LowProcess *>(((*(RefrOps_9e6ba0**)&this->pActor)))->GetTarget()))))->IsCellInterior())
        bfixupTether = false;
    else if (((::fnv_009e6ba0::WorldOps_9e6ba0 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((*(RefrOps_9e6ba0**)&this->pActor)))->FUN_00575d70())) &&
             ((::fnv_009e6ba0::CellOps_9e6ba0 *)(reinterpret_cast<::fnv_00587550::FUN_00587550_shell *>((((::fnv_009e6ba0::WorldOps_9e6ba0 *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((*(RefrOps_9e6ba0**)&this->pActor)))->FUN_00575d70()))))->FUN_00587550((const ::fnv_00587550::NiPoint3 &)(((DetailedActorPathHandler*)this)->m_kPathVector3)))))
        bfixupTether = false;

    if (bfixupTether)
    {
        ((DetailedActorPathHandler*)this)->m_kPathVector3 = actorCurrent;
        ((DetailedActorPathHandler*)this)->m_kPathVector4 = actorCurrent;
        ((DetailedActorPathHandler*)this)->eState = 4;
    }
    else
    {
        ((DetailedActorPathHandler*)this)->m_kPathVector4 = actorCurrent;
        ((DetailedActorPathHandler*)this)->eState = 3;
        NiPoint3 newPathOrigin = ((DetailedActorPathHandler*)this)->m_kPathVector3;
        bool bSetInitialTangent = true;
        float finitialAngle;
        NiPoint3Ops tetherTangent;
        reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>((((PathingSolution*)(NiPointerOps<PathingSolution>&)((DetailedActorPathHandler*)this)->pCurrentPathingSolution)))->GetLocationAtSplineParameter(((DetailedActorPathHandler*)this)->m_fSplineParameter + 0.10000000149011612, (::NiPoint3 *)&(tetherTangent));
        reinterpret_cast<::NiPoint3 *>((void *)&(const ::fnv_009e6ba0::NiPoint3Ops &)(tetherTangent))->Subtract(((DetailedActorPathHandler*)this)->m_kPathVector3);
        finitialAngle = (::GetDirectionAngle)((const ::NiPoint3 *)&(tetherTangent));

        if (!((BSSimpleListOps<ActorOps_9e6ba0*>*)&((DetailedActorPathHandler*)this)->ActorAvoidEntryList)->IsEmpty())
        {
            BSSimpleListOps<ActorOps_9e6ba0*>* pCurrentElementNext =
                (BSSimpleListOps<ActorOps_9e6ba0*>*)&((DetailedActorPathHandler*)this)->ActorAvoidEntryList;
            while (pCurrentElementNext)
            {
                ActorOps_9e6ba0* pavoidActor = ((::fnv_009e6ba0::ActorOps_9e6ba0 *)(new ((void *)(pCurrentElementNext)) ::Vec3()));
                pCurrentElementNext = ((::fnv_009e6ba0::BSSimpleListOps< ::fnv_009e6ba0::ActorOps_9e6ba0 *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
                if (::FUN_006ba9e0((*(const ::Pt3 *)((*(RefrOps_9e6ba0**)&this->pActor)->GetPos())),
                                 (*(const ::Pt3 *)(&((DetailedActorPathHandler*)this)->m_kPathVector3)), (*(const ::Pt3 *)(pavoidActor->GetPos())),
                                 pavoidActor->GetRadius()))
                {
                    newPathOrigin = *(*(RefrOps_9e6ba0**)&this->pActor)->GetPos();
                    bSetInitialTangent = false;
                    break;
                }
            }
        }

        reinterpret_cast<::FUN_006d3ac0_Class *>((((PathingRequestOps*)apRequest)))->AssignPathingLocation((const ::PathingLocation &)((const ::fnv_009e6ba0::PathingLocation &)(PathingLocation(newPathOrigin, *(RefrOps_9e6ba0**)&this->pActor))));
        if (bSetInitialTangent)
            reinterpret_cast<::FUN_006e2bb0_shell *>((((PathingRequestOps*)(NiPointerOps<PathingRequestOps>&)((DetailedActorPathHandler*)this)->m_pPathingRequest)))->SetInitialPathHeading(finitialAngle);
        else
            reinterpret_cast<::FUN_009e16c0_Class *>((((PathingRequestOps*)(NiPointerOps<PathingRequestOps>&)((DetailedActorPathHandler*)this)->m_pPathingRequest)))->FUN_009e16c0();
    }
}
}  // namespace fnv_009e6ba0

namespace fnv_009e9760 {
struct ActiveEffect;
struct Actor;
struct ActorCause;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct SaveLoadFile;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct DialogueResponse;
struct TeleportableReference;
struct EffectItem;
struct ExtraDataList;
struct ExtraLock;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanIntegerAccessor;
struct InventoryChanges;
struct InventoryStackRecord;
struct CellDataNode;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MapMarkerData;
struct MobileObject;
struct Point3Offset;
struct NiAVObject;
struct AnimationInterpolator;
struct NiColor;
struct NiControllerManager;
struct NiControllerSequence;
struct NiFixedString;
struct NiGeometry;
struct NiLight;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPointLight;
struct NiQuaternion;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkCharacterController;
struct bhkNiCollisionObject;
struct hkVector4;
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
struct blob16
{
    char b[16];
};
struct blob48
{
    char b[48];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
struct FUN_009e9760_shell : public DetailedActorPathHandler
{
    void FUN_009e9760(BGSLoadFormBuffer*);
};

struct TESObjectREFRHelper
{
};

struct AvoidActorListNode
{
    ::Actor* m_item;
    AvoidActorListNode* m_pkNext;
    bool _ref_008256d0();
    void _ref_00726c60(::Actor* const&);
    void _ref_0063f7b0();
};


// @fnv 0x009e9760
void FUN_009e9760_shell::FUN_009e9760(BGSLoadFormBuffer* apLoadGameBuffer)
{
    AvoidActorListNode* pCurrentElementNext;
    AvoidActorListNode* plastList;

    m_pPathTargetReference = m_pPathTargetReference
                                 ? dynamic_cast< ::TESObjectREFR*>(::FUN_004839c0((unsigned int)m_pPathTargetReference))
                                 : 0;
    pCurrentElementNext = (AvoidActorListNode*)&ActorAvoidEntryList;
    plastList = 0;
    while (pCurrentElementNext && !pCurrentElementNext->_ref_008256d0())
    {
        ::Actor* pForm;
        bool bremove;

        pForm = *((::Actor **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        bremove = false;
        if (pForm)
        {
            pForm = pForm ? dynamic_cast< ::Actor*>(::FUN_004839c0((unsigned int)pForm)) : 0;
            if (pForm)
                pCurrentElementNext->_ref_00726c60(pForm);
            else
                bremove = true;
        }
        else
        {
            bremove = true;
        }
        if (bremove)
        {
            if (plastList)
            {
                reinterpret_cast<::ItemChangeListNode *>((plastList))->FUN_00905330((::InventoryStackRecord *const &)(*((::Actor **)(new ((void *)(pCurrentElementNext)) ::Vec3()))));
                pCurrentElementNext = ((::fnv_009e9760::AvoidActorListNode *)(reinterpret_cast<::Callees *>((plastList))->FUN_00726070()));
            }
            else
            {
                pCurrentElementNext->_ref_0063f7b0();
            }
        }
        else
        {
            plastList = pCurrentElementNext;
            pCurrentElementNext = ((::fnv_009e9760::AvoidActorListNode *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        }
    }
    if (m_pPathTargetReference)
        reinterpret_cast<::fnv_00564db0::FUN_00564db0_cls *>((((TESObjectREFRHelper*)m_pPathTargetReference)))->FUN_00564db0(true);
}
}  // namespace fnv_009e9760

struct Pair3
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct Pair3Pool
{
};

struct Mid
{
    Pair3Pool* Step();
};

struct Node
{
};

struct Ctx
{
    Node* Get();
};

struct FUN_009e3b60_cls
{
    int unk00;
    int unk04;
    int unk08;
    Ctx m_0c;

    bool GetPairByIndex(int a1, Pair3* a2);
};

// Looks up the entry for index a1 in the context node and copies its Pair3 into a2, returning true if found.
// @fnv 0x009e3b60
bool FUN_009e3b60_cls::GetPairByIndex(int aiIndex, Pair3* apPair)
{
    unsigned int out;
    unsigned int pad;
    unsigned int pad2;
    if (((::Node *)(::FUN_00559450((int *)&(m_0c)))) != 0 && (unsigned int)aiIndex < ::GetObjectFlags((char *)(((::Node *)(::FUN_00559450((int *)&(m_0c)))))))
    {
        *apPair = *((::Pair3 *)&(reinterpret_cast<::TaskQueueInterface *>((((::Mid *)(reinterpret_cast<::FUN_006e7970_shell *>((((::Node *)(::FUN_00559450((int *)&(m_0c))))))->FUN_006e7970(aiIndex)))->Step()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)));
        return true;
    }
    return false;
}

struct Point3
{
    float x, y, z;
};
struct ActorAvoidNode
{
    void* item;
    ActorAvoidNode* next;
    void** FUN_006815c0();
};
struct PathArchive
{
};
struct PathSerializationData
{
    unsigned int unk00;
    void* pActor;
    void* m_pActorMover;
    void* pCurrentPathingSolution;
    void* m_pPathingRequest;
    unsigned int unk14;
    unsigned int unk18;
    Point3 m_kPathVector1;
    Point3 m_kPathVector2;
    Point3 m_kPathVector3;
    Point3 m_kActorPosition;
    Point3 m_kPathVector4;
    ActorAvoidNode ActorAvoidEntryList;
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
    Point3 m_kPathVector5;
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
    void* m_pPathTargetReference;
    bool m_bPathFlag1;
    bool m_bPathFlag2;
    bool m_bPathFlag3;
    bool m_bPathFlag4;
    bool m_bPathFlag5;
    bool m_bPathFlag6;
    bool m_bPathFlag7;
    void Serialize(PathArchive* archive);
};
// @fnv 0x009e8f80
void PathSerializationData::Serialize(PathArchive* archive)
{
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_kPathVector1, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_kPathVector2, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_kPathVector3, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_kActorPosition, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_kPathVector4, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&ByteAndFlagState, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_uiPathPointIndex, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue1, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue2, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fSplineParameter, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue4, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue5, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_iPathValue1, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue6, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue7, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue8, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue9, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue10, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue11, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue12, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue13, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue14, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue15, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue16, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue17, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&unk14, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&unk18, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&eState, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_iPathParameter1, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_iPathParameter2, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_iPathValue2, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_bPathFlag1, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_bPathFlag2, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_bPathFlag3, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_bPathFlag4, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_bPathFlag5, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_bPathFlag7, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_bPathFlag6, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_bHasPathingSolution, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_bPathingRequestPending, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fElapsedTime, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_kPathVector5, 12, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((archive))->FUN_00865e50(&m_fPathValue18, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((archive))->FUN_00865df0((::fnv_00865df0::TESForm *)(m_pPathTargetReference), 0);
    unsigned int count = 0;
    unsigned int token = reinterpret_cast<::FUN_00865f20_shell *>((archive))->FUN_00865f20();
    ActorAvoidNode* node = &ActorAvoidEntryList;
    while (node != 0)
    {
        void* item = *((void **)(new ((void *)(node)) ::Vec3()));
        if (item != 0)
        {
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((archive))->FUN_00865df0((::fnv_00865df0::TESForm *)(item), 0);
            count = count + 1;
        }
        node = ((::ActorAvoidNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((archive))->FUN_00865ff0(count, token);
}

struct PtrArrayView
{
    unsigned int m_unk00;
    void** m_pData;
    unsigned short m_unk08;
    unsigned short m_usSize;
    unsigned short m_usElementCount;

    void* FUN_009e98d0(unsigned int index);
};
// @fnv 0x009e8690
void FUN_009e8690_shell::RemoveRefFromPathHandler(TESObjectREFR* apRef)
{
    if (apRef == m_pPathTargetReference)
    {
        m_iPathValue2 = 0;
        m_pPathTargetReference = 0;
    }

    if (apRef->IsActor())
    {
        for (unsigned int i = 0; i < DAT_011f2aa0; ++i)
        {
            if (*((Arr*)&::g_011f2bf8)->GetAt(i) == apRef)
            {
                reinterpret_cast<::PtrArrayView *>((((GlobalObject_00869b10*)&::g_011f2bf8)))->FUN_009e98d0(i);
                ::CompactArray((::NiTArray_CombatGroup *)(((NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >*)&::g_011f2bf8)));
                DAT_011f2aa0--;
            }
        }

        if (reinterpret_cast<::RefList *>((((LH*)((char*)this + 0x58))))->FUN_005f65d0((void **)&(const ::Actor *const &)((Actor*)apRef)))
        {
            reinterpret_cast<::ItemChangeListNode *>((((LH*)((char*)this + 0x58))))->FUN_00905330((::InventoryStackRecord *const &)((const ::Actor *const &)((Actor*)apRef)));
            if (((LH*)((char*)this + 0x58))->_ref_008256d0())
                FUN_009e68c0();
        }
    }
}

// @fnv 0x009e98d0
void* PtrArrayView::FUN_009e98d0(unsigned int index)
{
    if (index >= m_usSize)
    {
        return 0;
    }
    void* item = m_pData[index];
    m_pData[index] = 0;
    if (item != 0)
    {
        m_usElementCount--;
    }
    if (index == (unsigned short)(m_usSize - 1))
    {
        m_usSize--;
    }
    return item;
}

struct PathBase
{
    virtual ~PathBase();
    int actor, mover, path, request;
    float initialAngle, initialRadius;
    PathBase(void*, void*, void*, void*);
};
struct PathPoint
{
    float x, y, z;
    PathPoint();
    PathPoint(float, float, float);
};
struct PathList
{
    void* item;
    void* next;
    PathList();
    ~PathList();
};
struct PathPtr
{
    bool operator==(void*) const;
};
struct FUN_009e0190 : PathBase
{
    PathPoint moveDelta, blockedTarget, tetherTarget, lastLocation, lastTether;
    PathList avoidList;
    int f60;
    int f64;
    float f68;
    float f6c;
    float f70;
    float f74;
    float f78;
    float f7c;
    float f80;
    float f84;
    float f88;
    float f8c;
    float f90;
    float f94;
    float f98;
    float f9c;
    PathPoint lastFrameDelta;
    float fac;
    float fb0;
    float fb4;
    float fb8;
    float fbc;
    unsigned char fc0;
    unsigned char fc1;
    unsigned char fc2;
    unsigned char fc3;
    float fc4;
    int fc8;
    int fcc;
    int fd0;
    int fd4;
    int fd8;
    unsigned char fdc;
    unsigned char fdd;
    unsigned char fde;
    unsigned char fdf;
    unsigned char fe0;
    unsigned char fe1;
    unsigned char fe2;
    unsigned char fe3;
    FUN_009e0190(void*, void*, PathPtr*, void*);
    virtual ~FUN_009e0190();
};
// @fnv 0x009e0190
FUN_009e0190::FUN_009e0190(void* apActor, void* apMover, PathPtr* apPathPtr, void* apRequest)
    : PathBase(apActor, apMover, apPathPtr, apRequest), moveDelta((*reinterpret_cast<const ::PathPoint *>((void *)&::NiPoint3::ZERO))), tetherTarget((*reinterpret_cast<const ::PathPoint *>((void *)&::NiPoint3::ZERO))),
      lastLocation(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F), lastTether((*reinterpret_cast<const ::PathPoint *>((void *)&::NiPoint3::ZERO)))
{
    f60 = 0;
    f8c = 1.0f;
    f94 = -1.0f;
    f78 = 0.0f;
    fb8 = 0.0f;
    fdf = 0;
    fe0 = 0;
    fe2 = 0;
    fe1 = 0;
    if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::PathPtr &)(*apPathPtr))->operator==((int)(0)) && apRequest == 0)
        fc8 = 5;
    else
        fc8 = 0;
    fcc = 0;
    f90 = 0.0f;
    fd0 = 0;
    f64 = 0;
    fac = 0.0f;
    fb4 = 0.0f;
    f6c = 0.0f;
    f70 = 0.0f;
    initialAngle = 10.0f;
    initialRadius = 20.0f;
    fd8 = 0;
    fc0 = 0;
    fc1 = 0;
    fc4 = 0.0f;
    fbc = 0.0f;
}

struct P3Update
{
    float x, y, z;
    static const P3Update ZERO;
    P3Update operator-(const P3Update&) const;
    float Length() const;
    float Dot(const P3Update&) const;
    P3Update& operator*=(float);
};
struct PointLocation
{
};
struct UpdateNode
{
    PointLocation* Location();
};
struct UpdateNodeList
{
    UpdateNode* Last();
};
struct UpdateRequest
{
    int unk00;
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
    int unkac;
    UpdateRequest();
    static void* operator new(unsigned);
};
struct UpdatePtr
{
    UpdateRequest* ptr;
    UpdatePtr(UpdateRequest*);
    ~UpdatePtr();
    operator UpdateRequest*() const;
};
struct SolutionPtr
{
    UpdateNodeList* ptr;
    operator UpdateNodeList*() const;
    SolutionPtr& operator=(UpdateNodeList*);
};
struct RequestPtr
{
    UpdateRequest* ptr;
    operator UpdateRequest*() const;
};
struct UpdateController
{
};
struct UpdateActor
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
    virtual P3Update& Position();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual void slot141();
    virtual void slot142();
    virtual void slot143();
    virtual void slot144();
    virtual void slot145();
    virtual void slot146();
    virtual void slot147();
    virtual void slot148();
    virtual void slot149();
    virtual void slot150();
    virtual void slot151();
    virtual void slot152();
    virtual void slot153();
    virtual void slot154();
    virtual void slot155();
    virtual void slot156();
    virtual void slot157();
    virtual void slot158();
    virtual void slot159();
    virtual void slot160();
    virtual void slot161();
    virtual void slot162();
    virtual void slot163();
    virtual void slot164();
    virtual void slot165();
    virtual void slot166();
    virtual void slot167();
    virtual void slot168();
    virtual void slot169();
    virtual void slot170();
    virtual void slot171();
    virtual void slot172();
    virtual void slot173();
    virtual void slot174();
    virtual float Heading(bool);
    virtual void slot176();
    virtual void SetFurnitureHeading(float);
};
struct UpdateMover
{
    int unk00;
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
    void Clear();
};
struct UpdatePlayer
{
};
extern UpdatePlayer* _g_thePlayer;
struct UpdateFloatSetting
{
};
struct UpdateBoolSetting
{
    bool* Bool();
};
struct UpdateMatrix
{
    float m0;
    float m1;
    float m2;
    float m3;
    float m4;
    float m5;
    float m6;
    float m7;
    float m8;
    UpdateMatrix();
    P3Update Transform(const P3Update*);
};
struct UpdateHandler
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual int SleepingUpdate(float);
    UpdateActor* actor;
    UpdateMover* mover;
    SolutionPtr path;
    RequestPtr request;
    int unk14;
    int unk18;
    P3Update delta, blocked, tether, last, lastTether;
    int avoidList0, avoidList1;
    unsigned moveMode, nodeIndex;
    float rotateGoal, pathLength, splineT, avoidanceTimer, detection;
    int unblock;
    float facing, blockedAngle, blockTime, timeAnim, runWalkTime, minRotate, waitTime, lastMinDelta;
    P3Update lastDelta;
    float goalRadius, fallTime, distance, ignoreTimer, rotation;
    bool ignoreInitial, keepHeading;
    float ignoreTether;
    int state, blend, avoidState, doorState;
    void* door;
    bool rotateMode, rotateCCW, movementBlocked, endUpdate, waiting, ignoreLook, computed;
    int UpdateMovementState(float dt);
    void Clear();
    int Detect(float);
    int CheckState();
};
namespace fnv_009e20c0 {
struct DoorRef : TESForm
{
    bool Activate(Actor*, bool, void*, int);
};
struct RequestView
{
};
struct RequestPtr
{
    RequestView* ptr;
    operator RequestView*() const;
};
struct MoverView
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
    unsigned int doorID;
};
int OpenState(DoorRef*);
struct DoorHandler
{
    int unk00;
    Actor* actor;
    MoverView* mover;
    int unk0c;
    RequestPtr request;
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
    int state;
    DoorRef* current;
    bool CanOpen(unsigned int);
    int UpdateDoorState();
};
// @fnv 0x009e20c0
int DoorHandler::UpdateDoorState()
{
    switch (state)
    {
    case 0:
        if (mover->doorID)
        {
            TESForm* form = ((::fnv_009e20c0::DoorRef *)(::FUN_004839c0(mover->doorID)));
            if (form && form->GetIsReference())
            {
                DoorRef* door = (DoorRef*)form;
                int status = OpenState(door);
                switch (status)
                {
                case 3:
                    if (!reinterpret_cast<::DoorAccessData *>((void *)(((RequestView*)request)))->ReadState98() && CanOpen(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((door))->FUN_0084e3a0()))))
                    {
                        if (!door->Activate(actor, false, 0, 1))
                            state = 2;
                        else
                        {
                            current = door;
                            reinterpret_cast<::fnv_00564db0::FUN_00564db0_cls *>((current))->FUN_00564db0(true);
                            state = 1;
                        }
                    }
                    return state;
                    break;
                default:
                    return 0;
                }
            }
        }
        break;
    case 1:
        if (!current)
        {
            state = 2;
            return state;
        }
        {
            int nextStatus = OpenState(current);
            switch (nextStatus)
            {
            case 2:
                return 1;
                break;
            case 1:
                current = 0;
                state = 0;
                return state;
            default:
                return 0;
            }
        }
        break;
    case 2:
        return 2;
        break;
    default:
        state = 0;
        return state;
    }
    state = 0;
    return state;
}
}  // namespace fnv_009e20c0

template <> class NiPointer<NavMesh>
{
  public:
    NavMesh* m_pObject;
    NiPointer();
    ~NiPointer();
    operator NavMesh*() const;
};

struct FUN_006dcd70
{
    int aiData[10];
    FUN_006dcd70(TESObjectREFR* apRef);
    FUN_006dcd70(const B006815c0& arPoint, TESObjectREFR* apRef);
    ~FUN_006dcd70();
};

void __cdecl FUN_006d7490(FUN_006dcd70* apLocation, void* apPoint, int a3, FUN_009e2690* apFilter);

struct FUN_006e7a10_Class
{
};

struct FUN_009e22d0_shell : public DetailedActorPathHandler
{
    bool FUN_009e22d0(unsigned int auiFlags);
};

// @fnv 0x009e22d0
bool FUN_009e22d0_shell::FUN_009e22d0(unsigned int auiFlags)
{
    if (!(PathingSolution*)pCurrentPathingSolution)
    {
        FUN_009e2690 kFilterTmp(auiFlags);
        FUN_006dcd70 _kLocation((TESObjectREFR*)pActor);
        reinterpret_cast<::PathingLocationProxy *>(&(_kLocation))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0));
        NiPointer<NavMesh> spNavMeshCur;
        unsigned short uTmpsTriangle;
        if (reinterpret_cast<::PathingLocation *>(&(_kLocation))->FindNavMeshTriangle((::NavMeshPtr &)(spNavMeshCur), uTmpsTriangle))
        {
            NavMeshTriangle* pTriangle = ((NavMesh*)spNavMeshCur)->GetTriangle(uTmpsTriangle);
            if (!pTriangle)
            {
            }
            else
            {
                kFilterTmp.f10 = reinterpret_cast<::FUN_00691140_shell *>((pTriangle))->FUN_00691140(0x1000);
            }
        }
        FUN_006d7490(&_kLocation, &m_kPathVector3, 0, &kFilterTmp);
        if (kFilterTmp.f8 || kFilterTmp.f9 || kFilterTmp.f10)
            return true;
        else
            return false;
    }
    else
    {
        if (!((FUN_009e2660_Class*)(PathingSolution*)pCurrentPathingSolution)->Contains(auiFlags))
        {
            for (float aFT = 0.0f; GetObjectFlags((char*)(PathingSolution*)pCurrentPathingSolution) - 1.0 > aFT;
                 aFT += 0.5)
            {
                float fNextTCur = aFT + 0.5;
                B006815c0 kStart4;
                B006815c0 kEnd2;
                reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>((((FUN_006e7a10_Class*)(PathingSolution*)pCurrentPathingSolution)))->GetLocationAtSplineParameter(aFT, (::NiPoint3 *)&(kStart4));
                reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>((((FUN_006e7a10_Class*)(PathingSolution*)pCurrentPathingSolution)))->GetLocationAtSplineParameter(fNextTCur, (::NiPoint3 *)&(kEnd2));
                FUN_009e2690 kSegFilterCur(auiFlags);
                FUN_006dcd70 kSegLocation3(kStart4, (TESObjectREFR*)pActor);
                reinterpret_cast<::PathingLocationProxy *>(&(kSegLocation3))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0));
                NiPointer<NavMesh> spSegNavMeshCur;
                unsigned short usSegTriangle3;
                if (reinterpret_cast<::PathingLocation *>(&(kSegLocation3))->FindNavMeshTriangle((::NavMeshPtr &)(spSegNavMeshCur), usSegTriangle3))
                {
                    NavMeshTriangle* pSegTriangle = ((NavMesh*)spSegNavMeshCur)->GetTriangle(usSegTriangle3);
                    if (!pSegTriangle)
                    {
                    }
                    else
                    {
                        kSegFilterCur.f10 = reinterpret_cast<::FUN_00691140_shell *>((pSegTriangle))->FUN_00691140(0x1000);
                    }
                }
                FUN_006d7490(&kSegLocation3, &kEnd2, 0, &kSegFilterCur);
                if (kSegFilterCur.f8 || kSegFilterCur.f9 || kSegFilterCur.f10)
                    return true;
            }
            return false;
        }
        else
            return true;
    }
}

class NiPoint3_ext : public NiPoint3
{
  public:
    NiPoint3_ext();
};
struct PathAngleSolution : PathingSolution
{
};
struct PathAngleMover : ActorMover
{
};
struct PathAngleActor : Actor
{
    float FUN_008be1b0();
};
NiPoint3_ext __cdecl FUN_009a8050(Actor*);
NiPoint3_ext __cdecl FUN_009a88e0(Actor*, NiPoint3_ext);
struct PathAngles : DetailedActorPathHandler
{
    void GetPathAngles(float&, float&);
};
// Computes a heading angle and a looking angle from the actor's pathing solution or mover and writes them to headingOut and lookingOut.
// @fnv 0x009e4450
void PathAngles::GetPathAngles(float& headingOut, float& lookingOut)
{
    float angle = 0.0f;
    float looking = 0.0f;
    if (m_bPathFlag3)
    {
        angle = m_fPathValue6;
    }
    else if (m_bHasPathingSolution)
    {
        if (m_bPathingRequestPending)
        {
            angle = pActor->GetCurrentTargetDistance(false);
        }
        else if (pCurrentPathingSolution)
        {
            NiPoint3_ext target;
            reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>((((PathAngleSolution*)(PathingSolution*)pCurrentPathingSolution)))->GetLocationAtSplineParameter(m_fElapsedTime, (::NiPoint3 *)&(target));
            NiPoint3_ext delta = (*(::NiPoint3_ext *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(target))->FUN_00439ef0((::NiPoint3 *)&(*pActor->GetPos()), *(const ::NiPoint3 *)nullptr)));
            delta.z = 0.0f;
            angle = ::GetDirectionAngle((const ::NiPoint3 *)&(delta));
        }
        else
        {
            angle = pActor->GetCurrentTargetDistance(false);
        }
    }
    else if (!m_bPathFlag6 && reinterpret_cast<::ActorMover *>((((PathAngleMover*)m_pActorMover)))->HasLookAtTarget())
    {
        NiPoint3_ext target;
        reinterpret_cast<::ActorMover *>((((PathAngleMover*)m_pActorMover)))->GetLookAtTargetPosition(target);
        NiPoint3_ext position = FUN_009a8050(pActor);
        if (reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::NiPoint3_ext &)((*(::NiPoint3_ext *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(position))->FUN_00439ef0((::NiPoint3 *)&(target), *(const ::NiPoint3 *)nullptr)))))->GetSquaredXYLength() <
            ((PathAngleActor*)pActor)->FUN_008be1b0() * ((PathAngleActor*)pActor)->FUN_008be1b0() * 0.25)
        {
            angle = pActor->GetCurrentTargetDistance(false);
        }
        else
        {
            NiPoint3_ext angles = FUN_009a88e0(pActor, target);
            if (!reinterpret_cast<::FUN_005a2030_shell *>((void *)(((PathAngleActor*)pActor)))->FUN_005a2030())
                looking = angles.x;
            if (((PathAngleActor*)pActor)->FUN_008be1b0() >= 100.0)
            {
                NiPoint3_ext delta = (*(::NiPoint3_ext *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(target))->FUN_00439ef0((::NiPoint3 *)&(*pActor->GetPos()), *(const ::NiPoint3 *)nullptr)));
                delta.z = 0.0f;
                angle = ::GetDirectionAngle((const ::NiPoint3 *)&(delta));
            }
            else
            {
                angle = angles.z;
            }
        }
    }
    else
    {
        NiPoint3_ext destination;
        if (pCurrentPathingSolution && ::GetObjectFlags((char *)(((PathingSolution*)pCurrentPathingSolution))) > 0)
        {
            reinterpret_cast<::fnv_006e7a10::FUN_006e7a10_shell *>((((PathAngleSolution*)(PathingSolution*)pCurrentPathingSolution)))->GetLocationAtSplineParameter(float(m_fSplineParameter + 0.10000000149011612), (::NiPoint3 *)&(destination));
        }
        else
        {
            (NiPoint3&)destination = m_kPathVector3;
        }
        NiPoint3_ext direction = (*(::NiPoint3_ext *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(destination))->FUN_00439ef0((::NiPoint3 *)&(*pActor->GetPos()), *(const ::NiPoint3 *)nullptr)));
        if (reinterpret_cast<::FUN_005a2030_shell *>((void *)(((PathAngleActor*)pActor)))->FUN_005a2030() &&
            reinterpret_cast<::NiPoint3 *>((void *)&(direction))->ComputeMagnitude() * 0.949999988079071 <= std::abs(direction.z))
        {
            angle = pActor->GetCurrentTargetDistance(false);
        }
        else
        {
            angle = ::GetDirectionAngle((const ::NiPoint3 *)&(direction));
        }
        if (reinterpret_cast<::FUN_005a2030_shell *>((void *)(((PathAngleActor*)pActor)))->FUN_005a2030())
            looking = 0.0f;
    }
    headingOut = angle;
    lookingOut = looking;
}

struct MotionVec
{
    float x, y, z;
    MotionVec operator-(const MotionVec&) const;
    float Length();
    double Dot(const MotionVec&);
};
struct AnimationView
{
};
struct CollisionObjectView
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
    virtual bool IsObstacle();
};
struct CollidableView
{
};
struct ControllerView
{
};
struct MotionActor
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
    virtual AnimationView* GetAnimation();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const MotionVec& GetPosition();
};
struct MoverView
{
};
struct RequestView
{
};
struct RequestPtrView
{
    RequestView* operator->();
};
struct AvoidSphereView
{
    MotionVec& FUN_006815c0();
};
struct AvoidArrayView
{
    unsigned unk00, unk04, unk08, unk0c;
    AvoidArrayView();
    ~AvoidArrayView();
    AvoidSphereView*& FUN_00877a30(unsigned);
};
struct MeshView
{
    void FUN_00691660(unsigned short, AvoidArrayView&);
};
struct MeshPtrView
{
    MeshView* pointer;
    MeshPtrView();
    ~MeshPtrView();
    MeshView* operator->();
};
struct LocationView
{
    MotionVec point;
    unsigned unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    LocationView(const MotionVec&, TESObjectCELL*, TESWorldSpace*);
    ~LocationView();
};
struct MotionTarget
{
    unsigned unk00;
    MotionActor* actor;
    MoverView* mover;
    unsigned unk0c;
    RequestPtrView request;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    MotionVec target;
    MotionVec lastPosition;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    unsigned unk80;
    unsigned unk84;
    float timer;
    unsigned unk8c;
    unsigned unk90;
    unsigned unk94;
    unsigned unk98;
    float radius;
    MotionVec lastDelta;
    unsigned unkac;
    unsigned unkb0;
    unsigned unkb4;
    unsigned unkb8;
    unsigned unkbc;
    unsigned unkc0;
    unsigned unkc4;
    int state;
    unsigned unkcc;
    int mode;
    unsigned unkd4;
    unsigned unkd8;
    unsigned short unkdc;
    bool movementBlocked;
    bool unkdf;
    unsigned unke0;
    bool UpdateMotion(float);
};
// Updates the motion target's timer and blocked state from the actor's movement, and when blocked adjusts avoidance spheres and calls the mover.
// @fnv 0x009e4cf0
bool MotionTarget::UpdateMotion(float afDeltaTime)
{
    bool p = false;
    if (mode == 3 || mode == 4)
        return true;
    MotionVec eb = actor->GetPosition();
    MotionVec i = target - lastPosition;
    MotionVec h = target - eb;
    MotionVec f = eb - lastPosition;
    bool a = false;
    bool s = false;
    if (!reinterpret_cast<::FUN_005a2030_shell *>((actor))->FUN_005a2030())
    {
        float cf = 20.0f;
        float q = reinterpret_cast<::FUN_00595c80_shell *>(&(i))->GetSquaredXYLength();
        float b = reinterpret_cast<::FUN_00589850_Class *>(&(i))->FUN_00589850();
        b += cf;
        b *= b;
        float ba = reinterpret_cast<::FUN_00595c80_shell *>(&(h))->GetSquaredXYLength();
        if (((double)(reinterpret_cast<::FUN_004b6190_shell *>(&(f))->DotProduct((void *)&(f)))) < radius * radius * 0.125)
        {
            ControllerView* k = ((::ControllerView *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((actor))->FUN_009306d0()));
            if (k)
            {
                CollisionObjectView* j = 0;
                CollidableView* c = ((::CollidableView *)(reinterpret_cast<::FUN_00c6fd60_Class *>((k))->FUN_00c6fd60()));
                void* e = c ? ((void *)(reinterpret_cast<::FUN_00810660_Class *>((c))->FUN_00810660())) : 0;
                CollisionObjectView* l = ((::CollisionObjectView *)(::FUN_0056f930((::NiAVObject *)(e))));
                j = l && l->IsObstacle() ? l : 0;
                if (j)
                    s = true;
            }
            a = true;
        }
    }
    else
    {
        float cf = 20.0f;
        float b = reinterpret_cast<::TESCombatStyle *>(&(i))->UpdateCombatStyle();
        float q = reinterpret_cast<::NiPoint3 *>(&(i))->ComputeMagnitude();
        q += cf;
        q *= q;
        float ba = reinterpret_cast<::TESCombatStyle *>(&(h))->UpdateCombatStyle();
        if (((double)(reinterpret_cast<::FUN_004b6190_shell *>(&(f))->DotProduct((void *)&(f)))) < ((double)(reinterpret_cast<::FUN_004b6190_shell *>(&(lastDelta))->DotProduct((void *)&(lastDelta)))) * 0.125)
        {
            ControllerView* k = ((::ControllerView *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((actor))->FUN_009306d0()));
            if (k)
            {
                CollisionObjectView* j = 0;
                CollidableView* c = ((::CollidableView *)(reinterpret_cast<::FUN_00c6fd60_Class *>((k))->FUN_00c6fd60()));
                void* e = c ? ((void *)(reinterpret_cast<::FUN_00810660_Class *>((c))->FUN_00810660())) : 0;
                CollisionObjectView* l = ((::CollisionObjectView *)(::FUN_0056f930((::NiAVObject *)(e))));
                j = l && l->IsObstacle() ? l : 0;
                if (j)
                    s = true;
            }
            a = true;
        }
    }
    lastPosition = eb;
    if (a)
    {
        if (s)
            timer += afDeltaTime * 0.20000000298023224;
        else
            timer += afDeltaTime;
        if (state == 3)
        {
            state = 4;
            return false;
        }
    }
    else if (!movementBlocked)
    {
        timer = 0.0f;
        return true;
    }
    if (timer > 1.5 && actor->GetAnimation() && reinterpret_cast<::fnv_00495be0::PriorityAnimation *>((actor->GetAnimation()))->IsHighestPriority())
        movementBlocked = true;
    if (movementBlocked)
    {
        p = true;
        if (mode == 0 || mode == 1 || mode == 5)
        {
            LocationView location(target, ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget())), ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actor))->FUN_00575d70())));
            if (reinterpret_cast<::PathingLocationProxy *>(&(location))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
            {
                MeshPtrView h;
                unsigned short p;
                if (reinterpret_cast<::PathingLocation *>(&(location))->FindNavMeshTriangle((::NavMeshPtr &)(h), p))
                {
                    AvoidArrayView f;
                    h->FUN_00691660(p, f);
                    bool eb = true;
                    if (!reinterpret_cast<::FUN_0076b610_Class *>(&(f))->FUN_0076b610())
                    {
                        for (unsigned a = 0; a < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(f))->GetName())); ++a)
                        {
                            AvoidSphereView* i = f.FUN_00877a30(a);
                            if (reinterpret_cast<::TESCombatStyle *>((void *)&(const ::MotionVec &)(((*(::MotionVec *)(new ((void *)(i)) ::Vec3())) - target)))->UpdateCombatStyle() < reinterpret_cast<::BSMultiBoundSphere *>((i))->GetRadius() * reinterpret_cast<::BSMultiBoundSphere *>((i))->GetRadius())
                            {
                                if (reinterpret_cast<::BSMultiBoundSphere *>((i))->GetRadius() < 128.0)
                                    reinterpret_cast<::FUN_00819a50_shell *>((i))->FUN_00819a50(reinterpret_cast<::BSMultiBoundSphere *>((i))->GetRadius() * 2.0f);
                                else
                                    ::FUN_00804cb0((void *)(i), ::GetFloatAtOffset1C((char *)(i)) * 10.0);
                                eb = false;
                            }
                        }
                    }
                    if (eb)
                        reinterpret_cast<::NavMeshOps *>(((h).operator->()))->AddAvoidNode((void *)&(target), p, ::GetFloatAtOffset68((const char *)((request).operator->())), {});
                }
            }
        }
    }
    if (p)
        reinterpret_cast<::TESForm *>((mover))->ClearData();
    return !p;
}

namespace fnv_009e5ae0 {
struct AvoidPoint
{
    float x, y, z;
    AvoidPoint();
    AvoidPoint(float, float, float);
    AvoidPoint operator-(const AvoidPoint&) const;
    AvoidPoint operator+(const AvoidPoint&) const;
    AvoidPoint FUN_0053d280(float) const;
    float Length() const;
};
struct AvoidLocation
{
    AvoidPoint point;
    void* cell;
    void* world;
    unsigned int triangle;
    void* mesh;
    float radius;
    unsigned int flags;
    unsigned int state;
    AvoidLocation();
    AvoidLocation(void*);
    AvoidLocation(void*, float);
    AvoidLocation(const AvoidLocation&);
    ~AvoidLocation();
};
struct AvoidanceVectorData
{
    AvoidLocation* FUN_00717e50();
};
struct AvoidPath
{
};
struct AvoidArray;
struct AvoidRequest
{
};
struct AvoidFlags
{
    unsigned int value;
};
struct AvoidController
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    AvoidFlags flags;
};
struct AvoidActor
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
    virtual AvoidActor* v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const AvoidPoint& v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual int v133();
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
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual float v175(int);
    bool FUN_00552470() const;
    float FUN_008be1b0();
    bool FUN_008b3860(AvoidLocation*);
    bool FUN_008bc7d0(AvoidActor*);
};
struct AvoidRefPath
{
    AvoidPath* p;
    operator AvoidPath*() const;
};
struct AvoidRefRequest
{
    AvoidRequest* p;
    operator AvoidRequest*() const;
};
struct AvoidEntry
{
    AvoidActor* actor;
    float weight;
};
struct AvoidContacts
{
    void* data;
    unsigned int size, capacity;
    unsigned int flags;
    AvoidContacts();
    ~AvoidContacts();
};
struct AvoidActors
{
    void* vtable;
    void* data;
    unsigned int size, capacity;
    AvoidActors();
    ~AvoidActors();
    AvoidActor*& FUN_00877a30(unsigned int);
};
struct AvoidList
{
    AvoidActor* actor;
    AvoidList* next;
    void FUN_005ae3d0(AvoidActor* const&);
    AvoidActor** FUN_006815c0();
};
struct AvoidElement
{
    AvoidPoint point;
    B006815c0 velocity;
    float distance;
    float timer;
    int mode;
    AvoidElement(const AvoidPoint&, float, float, int);
};
struct AvoidArray
{
    void* vtable;
    void* data;
    unsigned int size, capacity, grow, flags;
    static void* operator new(unsigned int);
    AvoidArray();
};
struct AvoidSetting
{
};
struct AvoidPlayer : AvoidActor
{
};
extern AvoidPlayer* g_thePlayer;
struct AvoidTime
{
};
struct __declspec(align(16)) AvoidQuaternion
{
    unsigned char components[16];
};
struct AvoidRotation
{
    float matrix[3][3];
    AvoidRotation();
    AvoidPoint FUN_004b4500(const AvoidPoint*);
};
struct AvoidMover
{
};
struct AvoidHandler
{
    void* vtable;
    AvoidActor* actor;
    AvoidMover* mover;
    AvoidRefPath path;
    AvoidRefRequest request;
    unsigned int unk14, unk18;
    AvoidPoint moveDelta, blockedTarget, tetherTarget, lastLocation, lastTether;
    AvoidList actors;
    unsigned int moveMode, node;
    float rotateGoal, pathLength, splineT, avoidTimer, detectionValue;
    int unblockDirection;
    float alternateFacing, blockedStartAngle, blockTime, timeInAnim, runWalkTime, minRotateTime, waitTime,
        lastFrameMinDelta;
    AvoidPoint lastFrameDelta;
    float goalRadiusSqr, fallTime, distanceTraveled, ignoreLookAtTimer, lastRotation;
    bool ignoreInitialRotation, keepHeading;
    float tetherParam;
    int state, blendRunning, avoidState;
    int UpdateAvoidance(float deltaTime);
};
// Evaluates nearby actors and obstacles to update detectionValue and avoidTimer, builds avoid nodes, and returns an avoidance state code (0-3).
// @fnv 0x009e5ae0
int AvoidHandler::UpdateAvoidance(float deltaTime)
{
    AvoidActor* target = actor->v116();
    if (!target || !reinterpret_cast<::FUN_007ff8e0_shell *>((target))->FUN_007ff8e0() ||
        (target->FUN_00552470() && reinterpret_cast<::bhkCharacterController_shell *>((void *)(((::fnv_009e5ae0::AvoidController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((actor))->FUN_009306d0()))))->FUN_008a3b50() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5ae0::AvoidSetting *>(&::g_011f2bd0))))))))
        return 0;
    if (avoidState != 2 && reinterpret_cast<::FUN_00595c80_shell *>((void *)&(moveDelta))->GetSquaredXYLength() < 0.25)
        return 0;
    if (avoidState != 4 && avoidState != 3)
        reinterpret_cast<::FileMatchList *>(&(actors))->RemoveAll();
    AvoidActor* destination = (AvoidActor*)FUN_009e55e0((TES*)actor);
    AvoidContacts contacts;
    AvoidPoint direction = moveDelta;
    if (avoidState == 2)
        direction = AvoidPoint(0.0f, 1.0f, 0.0f);
    ::fnv_009e5690::EvaluateAvoidance((::fnv_009e5690::Actor *)(actor), (::fnv_009e5690::PathingRequest *)(::fnv_009e5ae0::AvoidRequest *)(request), moveMode, (const ::fnv_009e5690::NiPoint3_ext *)(const ::fnv_009e5ae0::AvoidPoint *)(&direction), this, (::fnv_009e5690::ActorAvoidEntryList *)(::fnv_009e5ae0::AvoidContacts *)(&contacts));
    AvoidActors nearbyActors;
    bool blocked = false;
    bool includesPlayer = false;
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(contacts))->GetName())); ++i)
    {
        AvoidActor* obstacle = ((::fnv_009e5ae0::AvoidEntry *)(reinterpret_cast<::S006950d0 *>(&(contacts))->GetElement(i)))->actor;
        float weight = ((::fnv_009e5ae0::AvoidEntry *)(reinterpret_cast<::S006950d0 *>(&(contacts))->GetElement(i)))->weight;
        if (obstacle == g_thePlayer)
        {
            if (g_thePlayer != destination)
            {
                if ((AvoidPath*)path)
                {
                    AvoidLocation end(*((::fnv_009e5ae0::AvoidanceVectorData *)(reinterpret_cast<::S_FUN_006b05a0 *>((((AvoidPath*)path)))->FUN_006b05a0()))->FUN_00717e50());
                    if (reinterpret_cast<::FUN_006deeb0_cls *>(&(end))->IsWithinDistanceOfSameLocation((const ::PathingLocation *)(const ::fnv_009e5ae0::AvoidLocation *)(&AvoidLocation(g_thePlayer, g_thePlayer->FUN_008be1b0())), {}))
                    {
                        if (((bool)(reinterpret_cast<::FUN_00632ce0_Class *>((((AvoidRequest*)request)))->FUN_00632ce0())))
                            return 3;
                        else
                            reinterpret_cast<::FUN_008e7c50_cls *>((((AvoidRequest*)request)))->SetUseSoft(false);
                    }
                }
                detectionValue += weight * deltaTime;
                reinterpret_cast<::FUN_00438690 *>(&(nearbyActors))->FUN_007cb2e0((unsigned int *)&(g_thePlayer));
                includesPlayer = true;
            }
        }
        else
        {
            bool moving = false;
            if (reinterpret_cast<::FUN_004938e0_shell *>((obstacle))->FUN_004938e0() && !((bool)(reinterpret_cast<::FUN_008b3c50_Class *>((obstacle))->DispatchToReceiver())))
                moving = true;
            AvoidLocation location;
            if (obstacle->FUN_008b3860(&location))
            {
                if (reinterpret_cast<::FUN_006deeb0_cls *>(&(location))->IsWithinDistanceOfSameLocation(
                        (const ::PathingLocation *)(const ::fnv_009e5ae0::AvoidLocation *)(&AvoidLocation(actor, ::GetFloatAtOffset68((const char *)(((AvoidRequest*)request))))), {}))
                    moving = false;
            }
            if (moving)
            {
                if (avoidState == 2)
                    return 1;
                detectionValue += weight * deltaTime;
                if (moveMode & 0x200)
                {
                    if (reinterpret_cast<::FUN_008846e0_shell *>((obstacle))->GetVtbl20Result() & 0x200)
                        blocked = true;
                    else
                        reinterpret_cast<::FUN_00438690 *>(&(nearbyActors))->FUN_007cb2e0((unsigned int *)&(obstacle));
                }
                else if (!actor->FUN_008bc7d0(obstacle))
                {
                    blocked = true;
                    if (detectionValue >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5ae0::AvoidSetting *>(&::g_011f2b1c)))))))
                        break;
                }
            }
            else
            {
                if (avoidState == 2)
                    continue;
                detectionValue += 2.0 * weight * deltaTime;
                if (destination && obstacle == destination)
                    blocked = true;
                if ((AvoidPath*)path)
                {
                    AvoidLocation end(*((::fnv_009e5ae0::AvoidanceVectorData *)(reinterpret_cast<::S_FUN_006b05a0 *>((((AvoidPath*)path)))->FUN_006b05a0()))->FUN_00717e50());
                    if (reinterpret_cast<::FUN_006deeb0_cls *>(&(end))->IsWithinDistanceOfSameLocation((const ::PathingLocation *)(const ::fnv_009e5ae0::AvoidLocation *)(&AvoidLocation(obstacle, obstacle->FUN_008be1b0())), {}))
                    {
                        if (((bool)(reinterpret_cast<::FUN_00632ce0_Class *>((((AvoidRequest*)request)))->FUN_00632ce0())))
                            return 3;
                        else
                            reinterpret_cast<::FUN_008e7c50_cls *>((((AvoidRequest*)request)))->SetUseSoft(false);
                    }
                }
                reinterpret_cast<::FUN_00438690 *>(&(nearbyActors))->FUN_007cb2e0((unsigned int *)&(obstacle));
            }
        }
    }
    if (avoidState == 2)
        return 0;
    if (detectionValue == 0.0)
        return 0;
    if (detectionValue >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5ae0::AvoidSetting *>(&::g_011f2b1c)))))))
    {
        if (blocked)
        {
            waitTime = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5ae0::AvoidSetting *>(&::g_011f2b74))))));
            avoidTimer = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5ae0::AvoidSetting *>(&::g_011f2b2c))))));
            reinterpret_cast<::TESForm *>((mover))->ClearData();
            return 1;
        }
        if (!reinterpret_cast<::FUN_0076b610_Class *>(&(nearbyActors))->FUN_0076b610())
        {
            if (avoidState != 4 && !includesPlayer && !(moveMode & 0x200))
                avoidTimer = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5ae0::AvoidSetting *>(&::g_011f2b3c))))));
            else
                avoidTimer = FUN_00404010(avoidTimer, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5ae0::AvoidSetting *>(&::g_011f2bc4)))))));
            AvoidArray* avoidNodes = new AvoidArray;
            unsigned int count = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(nearbyActors))->GetName()));
            for (unsigned int j = 0; j < count; ++j)
                actors.FUN_005ae3d0(nearbyActors.FUN_00877a30(j));
            float factor = (moveMode & 0x200) ? 1.75f : 1.5f;
            AvoidActor* current = 0;
            AvoidList* list = &actors;
            float radius = ::GetFloatAtOffset68((const char *)(((AvoidRequest*)request)));
            while (list)
            {
                current = *((::fnv_009e5ae0::AvoidActor **)(new ((void *)(list)) ::Vec3()));
                list = ((::fnv_009e5ae0::AvoidList *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
                float distanceFactor = 1.0f;
                float distance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::fnv_009e5ae0::AvoidPoint &)((current->v125() - actor->v125())))->ComputeMagnitude();
                if (distance < current->FUN_008be1b0() + radius)
                    distanceFactor = 1.5f;
                float avoidRadius;
                int mode;
                if (current->v133() == 4 || current->v133() == 9)
                {
                    avoidRadius = current->FUN_008be1b0() * 0.5 * factor;
                    mode = 0;
                }
                else
                {
                    avoidRadius = current->FUN_008be1b0() * factor * distanceFactor;
                    mode = 2;
                }
                AvoidRotation rotation;
                reinterpret_cast<::FUN_009e1640_shell *>(&(rotation))->SetRotationMatrix(current->v175(0));
                AvoidPoint velocity = rotation.FUN_004b4500(((const ::fnv_009e5ae0::AvoidPoint *)(reinterpret_cast<::FUN_008b3d50_This *>((current))->FUN_008b3d50())));
                AvoidPoint delta = velocity.FUN_0053d280(reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::fnv_009e5ae0::AvoidTime *>(&::g_timeGlobal))))->GetStoredFloatValue());
                if (reinterpret_cast<::TESCombatStyle *>((void *)&(delta))->UpdateCombatStyle() > current->FUN_008be1b0())
                    reinterpret_cast<::FUN_00905450_StandIn *>((avoidNodes))->AppendNode((::PathingAvoidanceNode *)(&AvoidElement(current->v125() + delta, avoidRadius, 2.0f, mode)));
                AvoidPoint position = current->v125();
                AvoidController* controller = ((::fnv_009e5ae0::AvoidController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((current))->FUN_009306d0()));
                if (controller && !reinterpret_cast<::bhkCharacterListener *>(&(controller->flags))->FUN_00621270(0x8000000))
                {
                    AvoidQuaternion rotationValue;
                    new ((void *)&(rotationValue)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(reinterpret_cast<::NiObject *>((controller))->FUN_00621a40())));
                    AvoidPoint offset;
                    ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&offset)), (*(const ::hkVector4 *)(&rotationValue)));
                    position.x = offset.x;
                    position.y = offset.y;
                }
                reinterpret_cast<::FUN_00905450_StandIn *>((avoidNodes))->AppendNode((::PathingAvoidanceNode *)(&AvoidElement(position, avoidRadius, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e5ae0::AvoidSetting *>(&::g_011f2b5c)))))), mode)));
            }
            reinterpret_cast<::FUN_006d3ac0_Class *>((((AvoidRequest*)request)))->AssignPathingLocation((*(const ::PathingLocation *)(&AvoidLocation(actor))));
            reinterpret_cast<::PathingRequest *>((((AvoidRequest*)request)))->SetAvoidNodeArray((::BSSimpleArray<void *, 1024> *)(avoidNodes));
            reinterpret_cast<::TESForm *>((mover))->ClearData();
            return 2;
        }
    }
    if (!blocked && reinterpret_cast<::FUN_0076b610_Class *>(&(nearbyActors))->FUN_0076b610())
    {
        detectionValue -= deltaTime;
        if (detectionValue < 0.0)
            detectionValue = 0.0f;
    }
    return 0;
}
}  // namespace fnv_009e5ae0


class GlobalObject_0044f440
{
  public:
};

struct FUN_008843a0_shell
{
    bool FUN_008843a0();
};

struct FUN_00493bb0_shell
{
};

struct ActorMover_Helper : public ActorMover
{
};

struct VCallHelper_354 : public VCallHelper_2bc
{
    virtual void e176();
    virtual void e177();
    virtual void e178();
    virtual void e179();
    virtual void e180();
    virtual void e181();
    virtual void e182();
    virtual void e183();
    virtual void e184();
    virtual void e185();
    virtual void e186();
    virtual void e187();
    virtual void e188();
    virtual void e189();
    virtual void e190();
    virtual void e191();
    virtual void e192();
    virtual void e193();
    virtual void e194();
    virtual void e195();
    virtual void e196();
    virtual void e197();
    virtual void e198();
    virtual void e199();
    virtual void e200();
    virtual void e201();
    virtual void e202();
    virtual void e203();
    virtual void e204();
    virtual void e205();
    virtual void e206();
    virtual void e207();
    virtual void e208();
    virtual void e209();
    virtual void e210();
    virtual void e211();
    virtual void e212();
    virtual float v213();
};

struct FUN_009e7d70_shell : public DetailedActorPathHandler
{
    float FUN_009e7d70(float a2);
};

// @fnv 0x009e7d70
float FUN_009e7d70_shell::FUN_009e7d70(float afDeltaTime)
{
    float var_8 = ((VCallHelper_2bc*)this->pActor)->v175(0);
    if (!((FUN_008843a0_shell*)this->pActor)->FUN_008843a0())
    {
        this->ByteAndFlagState = reinterpret_cast<::FUN_009dd130_shell *>((this->m_pActorMover))->FUN_009dd130();
        return var_8;
    }
    WrapValueToRange(var_8, -3.1415927f, 3.1415927f);
    float var4 = this->m_fPathValue1 - var_8;
    WrapValueToRange(var4, -3.1415927f, 3.1415927f);
    bool var2 = var4 > ::_DAT_01012060;
    if (std::abs(var4) > DAT_01023128)
    {
        float var_10 = ((VCallHelper_354*)this->pActor)->v213() * DAT_01023128 * afDeltaTime;
        if (!this->pActor->Unk_87())
        {
            var_10 *= ((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((((FUN_00493bb0_shell*)this->pActor)))->FUN_00493bb0())) ? *((float *)&(::FUN_00403e20((float *)&(g_011f2ac4)))) : *((float *)&(::FUN_00403e20((float *)&(g_011f2ad8))));
        }
        else
        {
            var_10 *= ((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((((FUN_00493bb0_shell*)this->pActor)))->FUN_00493bb0())) ? *((float *)&(::FUN_00403e20((float *)&(g_011f2b10)))) : *((float *)&(::FUN_00403e20((float *)&(g_011f2c10))));
        }
        if (var_10 > std::abs(var4))
        {
            var_8 = this->m_fPathValue1;
            if (this->m_fPathValue11 <= ::_DAT_01012060)
            {
                this->m_bPathFlag1 = false;
                reinterpret_cast<::TESForm *>((((ActorMover_Helper*)this->m_pActorMover)))->ClearData();
            }
        }
        else
        {
            if (this->m_bPathFlag2)
            {
                this->ByteAndFlagState = reinterpret_cast<::FUN_009dd130_shell *>((this->m_pActorMover))->FUN_009dd130() | 0x20;
                var_8 += var_10;
            }
            else
            {
                this->ByteAndFlagState = reinterpret_cast<::FUN_009dd130_shell *>((this->m_pActorMover))->FUN_009dd130() | 0x10;
                var_8 -= var_10;
            }
        }
    }
    else
    {
        var_8 = this->m_fPathValue1;
        if (this->m_fPathValue11 <= ::_DAT_01012060)
        {
            this->m_bPathFlag1 = false;
            reinterpret_cast<::TESForm *>((((ActorMover_Helper*)this->m_pActorMover)))->ClearData();
        }
    }
    this->m_fPathValue11 -= afDeltaTime;
    return var_8;
}

struct PosX
{
    float x, y, z;
};
struct ActorX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(),
        v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc(), v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(),
        v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc(), v100(), v104(), v108(), v10c(), v110(),
        v114(), v118(), v11c(), v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c(), v140(), v144(), v148(),
        v14c(), v150(), v154(), v158(), v15c(), v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c(), v180(),
        v184(), v188(), v18c(), v190(), v194(), v198(), v19c(), v1a0(), v1a4(), v1a8(), v1ac(), v1b0(), v1b4(), v1b8(),
        v1bc(), v1c0(), v1c4(), v1c8(), v1cc(), v1d0(), v1d4(), v1d8(), v1dc(), v1e0(), v1e4(), v1e8(), v1ec(), v1f0();
    virtual PosX* v1f4();
    double FUN_008be350();
};
struct LocX
{
};
struct CellX
{
    LocX* FUN_00717e50();
};
struct ProcX
{
};
struct ProcPtr
{
    ProcX* p;
};
struct TgtX
{
};
struct TgtPtr
{
    TgtX* p;
};
struct DoorX
{
};
struct NodeX
{
};
struct NodePtr
{
    NodeX* p;
    NodePtr();
    ~NodePtr();
};
struct ResultX
{
    int a, b;
    bool b8, b9, ba;
    char pad;
    ResultX(int i);
};
struct WalkX
{
    int pad[10];
    WalkX(ActorX* p);
    ~WalkX();
};
void __cdecl FUN_006d7490(WalkX* w, PosX* p, int i, ResultX* r);
struct PlanX
{
};
struct PkgX
{
    int m0;
    ActorX* m4;
    PlanX* m8;
    ProcPtr mc;
    TgtPtr m10;
    int pad14[8];
    PosX m34;
    bool IsPathClear();
};
// Checks if the actor can advance to the target by verifying distance, cell proximity, and path walkability, updating the plan if clear.
// @fnv 0x009e8800
bool PkgX::IsPathClear()
{
    if (((::TgtX *)(::FUN_00559450((int *)&(m10)))) && ::GetFloatAtOffset68((const char *)(((::TgtX *)(::FUN_00559450((int *)&(m10)))))) > 100.0)
        return false;
    float fNear_u = 64.0f;
    float fNearSq_chdcf = fNear_u * fNear_u;
    float fFar_nezo = 128.0f;
    float fFarSq_abpnoy = fFar_nezo * fFar_nezo;
    float fDistTmp = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::PosX &)((*(::PosX *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(m34))->FUN_00439ef0((::NiPoint3 *)&(*m4->v1f4()), *(const ::NiPoint3 *)nullptr)))))->FUN_00589850();
    float fMin_knckj = 0.0f;
    if (reinterpret_cast<::FUN_006b05d0_shell *>((((::ProcX *)(::FUN_00559450((int *)&(mc))))))->FUN_006b05d0())
        fMin_knckj = m4->FUN_008be350() * 0.6f;
    if (::GetObjectFlags((char *)(((::ProcX *)(::FUN_00559450((int *)&(mc)))))) > 0)
    {
        if (fDistTmp < fFar_nezo)
            reinterpret_cast<::fnv_009e3c00::FUN_009e3c00_shell *>(this)->AdvanceAlongPath(fFar_nezo - fDistTmp);
        fDistTmp = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::PosX &)((*(::PosX *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(m34))->FUN_00439ef0((::NiPoint3 *)&(*m4->v1f4()), *(const ::NiPoint3 *)nullptr)))))->FUN_00589850();
        float fCell_kdfu =
            reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::PosX &)((*(::PosX *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::PosX &)((*(::PosX *)&(reinterpret_cast<::TaskQueueInterface *>((((::CellX *)(reinterpret_cast<::S_FUN_006b05a0 *>((((::ProcX *)(::FUN_00559450((int *)&(mc))))))->FUN_006b05a0()))->FUN_00717e50()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr)))))->FUN_00439ef0((::NiPoint3 *)&(m34), *(const ::NiPoint3 *)nullptr)))))->FUN_00589850();
        if (fDistTmp < fNear_u || fCell_kdfu < fMin_knckj)
        {
            return false;
        }
        else
        {
            ResultX kResult4(0);
            WalkX kWalk(m4);
            reinterpret_cast<::PathingLocationProxy *>(&(kWalk))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0));
            NodePtr aSpNode;
            unsigned short usIdx;
            if (reinterpret_cast<::PathingLocation *>(&(kWalk))->FindNavMeshTriangle((*(::NavMeshPtr *)(&aSpNode)), (*(unsigned short *)(&usIdx))))
            {
                DoorX* pkDoor3 = ((::DoorX *)(reinterpret_cast<::NavMesh *>((((::NodeX *)(::FUN_00559450((int *)&(aSpNode))))))->GetTriangle(usIdx)));
                if (!pkDoor3)
                {
                }
                else
                {
                    kResult4.ba = reinterpret_cast<::FUN_00691140_shell *>((pkDoor3))->FUN_00691140(0x1000);
                }
            }
            FUN_006d7490(&kWalk, &m34, 0, &kResult4);
            if (kResult4.b8 || kResult4.b9 || kResult4.ba)
            {
                return false;
            }
            else
            {
                reinterpret_cast<::ActorMoverLocation14 *>((m8))->FUN_009df010((*(const ::NiPoint3 *)(&m34)));
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}

namespace fnv_009e8b50 {
struct Vec3
{
    float x;
    float y;
    float z;
};
struct Obj4
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
    virtual Vec3* v125();
};
struct Ctx
{
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void v5(int a, int b, const char* s, ...);
};
void __cdecl FUN_00406d50(char* d, int n, const char* s);
struct PFThis
{
    int f00;
    Obj4* f04;
    int f008, f00c, f010, f014, f018, f01c, f020, f024, f028, f02c, f030, f034, f038, f03c, f040, f044, f048, f04c,
        f050, f054, f058, f05c, f060, f064, f068, f06c, f070, f074;
    float f78;
    int f07c, f080, f084, f088, f08c, f090, f094, f098, f09c, f0a0, f0a4, f0a8, f0ac, f0b0, f0b4, f0b8, f0bc, f0c0,
        f0c4;
    int fC8;
    int fCC;
    int fD0;
    int fD4;
    int fD8;
    bool bDC;
    bool bDD;
    bool bDE;
    bool bDF;
    void FUN_009e8b50(Ctx* pOutput, int a2, int a3);
};
// Writes the actor's position, pathing state, and avoidance state to pOutput using formatted strings.
// @fnv 0x009e8b50
void PFThis::FUN_009e8b50(Ctx* pOutput, int a2, int a3)
{
    char acDetailText[0x104];
    char acStateText[0x104];
    {
        Vec3 vPos = *f04->v125();
        pOutput->v5(a2, a3, "DetailedPathHandler: Actor's Position %1.f %1.f %1.f", (double)vPos.x, (double)vPos.y,
                    (double)vPos.z);
    }
    ::TaskQueueInterface::CopyStringToBuffer(acStateText, 0x104, "Pathing State: ");
    switch (fC8)
    {
    case 1:
        FUN_00406d50(acStateText, 0x104, "Initializing");
        break;
    case 2:
        if (bDC)
        {
            FUN_00406d50(acStateText, 0x104, "Rotating");
        }
        else if (bDE)
        {
            FUN_00406d50(acStateText, 0x104, "Static Avoidance");
        }
        else
        {
            FUN_00406d50(acStateText, 0x104, "Moving");
        }
        break;
    case 3:
        FUN_00406d50(acStateText, 0x104, "Moving While Waiting");
        break;
    case 4:
        FUN_00406d50(acStateText, 0x104, "Waiting For Updated Path");
        break;
    case 5:
        FUN_00406d50(acStateText, 0x104, "Goal Reached");
        break;
    case 6:
    case 7:
        FUN_00406d50(acStateText, 0x104, "Rotating without path");
        break;
    default:
        FUN_00406d50(acStateText, 0x104, "Invalid");
        break;
    }
    pOutput->v5(a2, a3, acStateText);
    ::TaskQueueInterface::CopyStringToBuffer(acStateText, 0x104, "Actor Avoid State: ");
    switch (fD0)
    {
    case 1:
        FUN_00406d50(acStateText, 0x104, "OK");
        if (f78 > 0.0)
        {
            ::FUN_00406d00(acDetailText, 0x104, " :detect %f", (double)f78);
            FUN_00406d50(acStateText, 0x104, acDetailText);
        }
        break;
    case 2:
        FUN_00406d50(acStateText, 0x104, "Waiting");
        break;
    case 3:
        FUN_00406d50(acStateText, 0x104, "Repathing (building)");
        break;
    case 4:
        FUN_00406d50(acStateText, 0x104, "Repath ignore");
        if (f78 > 0.0)
        {
            ::FUN_00406d00(acDetailText, 0x104, " :detect %f", (double)f78);
            FUN_00406d50(acStateText, 0x104, acDetailText);
        }
        break;
    case 5:
        FUN_00406d50(acStateText, 0x104, "Failed");
        break;
    default:
        FUN_00406d50(acStateText, 0x104, "Invalid");
        break;
    }
    pOutput->v5(a2, a3, acStateText);
}
}  // namespace fnv_009e8b50

class Vec3f
{
  public:
    float x;
    float y;
    float z;
};


class FUN_009dfd70
{
  public:
    int b04;
    int b08;
    int b0c;
    int b10;
    float f14;
    float f18;
    FUN_009dfd70(int a1, int a2);
    virtual ~FUN_009dfd70();
};

class FUN_006815c0
{
  public:
    float m00;
    float m04;
    float m08;
    FUN_006815c0();
};

class FUN_00416870
{
  public:
    float m00;
    float m04;
    float m08;
    FUN_00416870(float a1, float a2, float a3);
};

class FUN_0096a2d0
{
  public:
    int m00;
    int m04;
    FUN_0096a2d0();
    ~FUN_0096a2d0();
};

class FUN_009dff40 : public FUN_009dfd70
{
  public:
    Vec3f v1c;
    FUN_006815c0 m28;
    Vec3f v34;
    FUN_00416870 m40;
    Vec3f v4c;
    FUN_0096a2d0 m58;
    int i60;
    int i64;
    int i68;
    float f6c;
    float f70;
    int i74;
    float f78;
    int i7c;
    int i80;
    int i84;
    int i88;
    float f8c;
    float f90;
    float f94;
    int i98;
    int i9c;
    FUN_006815c0 mA0;
    float fac;
    int ib0;
    float fb4;
    float fb8;
    float fbc;
    char cc0;
    char cc1;
    char cc2;
    char cc3;
    float fc4;
    int ic8;
    int icc;
    int id0;
    int id4;
    int id8;
    char cdc;
    char cdd;
    char cde;
    char cdf;
    char ce0;
    char ce1;
    char ce2;
    char ce3;
    FUN_009dff40(int a1, int a2);
    virtual ~FUN_009dff40();
};

// @fnv 0x009dff40
FUN_009dff40::FUN_009dff40(int a1, int a2)
    : FUN_009dfd70(a1, a2), v1c((*reinterpret_cast<::Vec3f *>((void *)&::NiPoint3::ZERO))), v34((*reinterpret_cast<::Vec3f *>((void *)&::NiPoint3::ZERO))), m40(DAT_01016970, DAT_01016970, DAT_01016970),
      v4c((*reinterpret_cast<::Vec3f *>((void *)&::NiPoint3::ZERO)))
{
    i60 = 0;
    f8c = 1.0f;
    f94 = ::DAT_01012054;
    f78 = 0.0f;
    fb8 = 0.0f;
    cdf = 0;
    ce0 = 0;
    ce2 = 0;
    ce1 = 0;
    ic8 = 5;
    icc = 0;
    f90 = 0.0f;
    id0 = 0;
    i64 = 0;
    fac = 0.0f;
    fb4 = 0.0f;
    f6c = 0.0f;
    f70 = 0.0f;
    f14 = DAT_01017b78;
    f18 = ::DAT_01017868;
    id8 = 0;
    cc0 = 0;
    cc1 = 0;
    fc4 = 0.0f;
    fbc = 0.0f;
}

namespace fnv_009e6900 {
struct Pt3
{
    float x;
    float y;
    float z;
    Pt3();
    Pt3 operator-(const Pt3& point) const;
    float Dot(const Pt3& point) const;
};

namespace std {
float __cdecl abs(float);
}

void __cdecl FUN_005330e0(float&, float, float);

struct SettingVal
{
};

struct Pkg
{
};
struct PkgPtr
{
    Pkg* Get();
};

struct Ref;

struct Target
{
    int unk00;
    int unk04;
};

struct Proc
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
    virtual Target* GetTarget();
};

struct Ref
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
    virtual Pt3* GetPos();
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
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual Ref* GetCombatTarget();
    float FUN_008be1b0();
};

struct RefList
{
};

struct Group
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
    RefList list;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int state;
};

// Checks target range, vertical separation, package and direction conditions, and may write a computed value to apResult.
// @fnv 0x009e6900
bool __cdecl FUN_009e6900(Ref* apActor, Group* apGroup, Ref* apTarget, const Pt3& arPos, const Pt3& arDir,
                          float afExtra, float afMinDot, float* apResult, bool abCheckOnly)
{
    Pt3 kDelta;
    *apResult = 0.0f;
    if (apGroup && (apGroup->state == 4 || apGroup->state == 3) && reinterpret_cast<::RefList *>(&(apGroup->list))->FUN_005f65d0((void **)&(apTarget)))
        return false;

    kDelta = *apTarget->GetPos() - arPos;
    float fRadius3 = reinterpret_cast<::fnv_008be420::Dd *>((apActor))->FUN_008be420();
    float fRange5 = apTarget->FUN_008be1b0() + afExtra + fRadius3;
    float fRangeSqr6 = fRange5 * fRange5;
    if (reinterpret_cast<::FUN_00595c80_shell *>((void *)&(kDelta))->GetSquaredXYLength() < fRangeSqr6)
    {
        if (std::abs(kDelta.z) < 180.0)
        {
            if (!((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((apActor))->FUN_00493bb0())) || apTarget != apActor->GetCombatTarget())
            {
                Target* pTarget = ((::fnv_009e6900::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture())) ? ((::fnv_009e6900::Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((apActor))->GetBaseTexture()))->GetTarget() : 0;
                if (pTarget && ((::fnv_009e6900::Ref *)(reinterpret_cast<::Twin_0044ddc0 *>((pTarget))->GetName())) == apTarget)
                {
                    bool bOkVal = false;
                    switch (reinterpret_cast<struct ::FUN_0041ca90 *>((((::fnv_009e6900::Pkg *)(::FUN_00559450((int *)(pTarget))))))->get())
                    {
                    case 1:
                        bOkVal = true;
                    }
                    if (!bOkVal)
                        return false;
                }
                kDelta.z = 0.0f;
                float fDist = reinterpret_cast<::NiPoint3 *>((void *)&(kDelta))->GetLengthSquared();
                bool bClose4 = false;
                if (fDist < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_009e6900::SettingVal *>(&::g_011f2b8c)))))))
                    bClose4 = true;
                fDist = fDist - fRadius3;
                fDist = ::FUN_00404010(fDist, 0.0f);
                float fDot_ = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(kDelta))->DotProduct((void *)&(arDir));
                if (fDot_ >= afMinDot || bClose4)
                {
                    if (abCheckOnly)
                        return true;
                    float fRatio5 = fDist / fRange5;
                    FUN_005330e0(fRatio5, 0.0f, 1.0f);
                    int iPower5 = (int)(fRatio5 * 4.0);
                    float fValue3 = fDot_;
                    switch (iPower5)
                    {
                    case 3:
                    case 4:
                        fValue3 = fValue3 * fValue3;
                    case 2:
                        fValue3 = fValue3 * fValue3;
                    case 1:
                        fValue3 = fValue3 * fValue3;
                    }
                    *apResult = fValue3;
                    return true;
                }
            }
        }
    }
    return false;
}
}  // namespace fnv_009e6900

struct FUN_004f2770_Class;
__if_not_exists(_g_thePlayer)
{
    extern FUN_004f2770_Class* _g_thePlayer;
}

class Calendar_1d50
{
  public:
};
extern Calendar_1d50 g_calendar;


class PathingRequest_1d50
{
  public:
};

class PathingLocation_1d50
{
  public:
};

class ContNode_1d50
{
  public:
    PathingLocation_1d50* FUN_00717e50();
};

class PathingSolution_1d50
{
  public:
};

class B006815c0_1d50
{
  public:
    B006815c0_1d50();
    float x, y, z;
};

class PointW_1d50 : public NiPoint3
{
  public:
};

class ActorS_1d50
{
  public:
    virtual void Vf000();
    virtual void Vf004();
    virtual void Vf008();
    virtual void Vf00c();
    virtual void Vf010();
    virtual void Vf014();
    virtual void Vf018();
    virtual void Vf01c();
    virtual void Vf020();
    virtual void Vf024();
    virtual void Vf028();
    virtual void Vf02c();
    virtual void Vf030();
    virtual void Vf034();
    virtual void Vf038();
    virtual void Vf03c();
    virtual void Vf040();
    virtual void Vf044();
    virtual void Vf048();
    virtual void Vf04c();
    virtual void Vf050();
    virtual void Vf054();
    virtual void Vf058();
    virtual void Vf05c();
    virtual void Vf060();
    virtual void Vf064();
    virtual void Vf068();
    virtual void Vf06c();
    virtual void Vf070();
    virtual void Vf074();
    virtual void Vf078();
    virtual void Vf07c();
    virtual void Vf080();
    virtual void Vf084();
    virtual void Vf088();
    virtual void Vf08c();
    virtual void Vf090();
    virtual void Vf094();
    virtual void Vf098();
    virtual void Vf09c();
    virtual void Vf0a0();
    virtual void Vf0a4();
    virtual void Vf0a8();
    virtual void Vf0ac();
    virtual void Vf0b0();
    virtual void Vf0b4();
    virtual void Vf0b8();
    virtual void Vf0bc();
    virtual void Vf0c0();
    virtual void Vf0c4();
    virtual void Vf0c8();
    virtual void Vf0cc();
    virtual void Vf0d0();
    virtual void Vf0d4();
    virtual void Vf0d8();
    virtual void Vf0dc();
    virtual void Vf0e0();
    virtual void Vf0e4();
    virtual void Vf0e8();
    virtual void Vf0ec();
    virtual void Vf0f0();
    virtual void Vf0f4();
    virtual void Vf0f8();
    virtual void Vf0fc();
    virtual void Vf100();
    virtual void Vf104();
    virtual void Vf108();
    virtual void Vf10c();
    virtual void Vf110();
    virtual void Vf114();
    virtual void Vf118();
    virtual void Vf11c();
    virtual void Vf120();
    virtual void Vf124();
    virtual void Vf128();
    virtual void Vf12c();
    virtual void Vf130();
    virtual void Vf134();
    virtual void Vf138();
    virtual void Vf13c();
    virtual void Vf140();
    virtual void Vf144();
    virtual void Vf148();
    virtual void Vf14c();
    virtual void Vf150();
    virtual void Vf154();
    virtual void Vf158();
    virtual void Vf15c();
    virtual void Vf160();
    virtual void Vf164();
    virtual void Vf168();
    virtual void Vf16c();
    virtual void Vf170();
    virtual void Vf174();
    virtual void Vf178();
    virtual void Vf17c();
    virtual void Vf180();
    virtual void Vf184();
    virtual void Vf188();
    virtual void Vf18c();
    virtual void Vf190();
    virtual void Vf194();
    virtual void Vf198();
    virtual void Vf19c();
    virtual void Vf1a0();
    virtual void Vf1a4();
    virtual void Vf1a8();
    virtual void Vf1ac();
    virtual void Vf1b0();
    virtual void Vf1b4();
    virtual void Vf1b8();
    virtual void Vf1bc();
    virtual void Vf1c0();
    virtual void Vf1c4();
    virtual void Vf1c8();
    virtual void Vf1cc();
    virtual void Vf1d0();
    virtual void Vf1d4();
    virtual void Vf1d8();
    virtual void Vf1dc();
    virtual void Vf1e0();
    virtual void Vf1e4();
    virtual void Vf1e8();
    virtual void Vf1ec();
    virtual void Vf1f0();
    virtual void Vf1f4();
    virtual void Vf1f8();
    virtual void Vf1fc();
    virtual void Vf200();
    virtual void Vf204();
    virtual void Vf208();
    virtual void Vf20c();
    virtual void Vf210();
    virtual int GetSitSleepState();
    virtual void Vf218();
    virtual void Vf21c();
    virtual void Vf220();
    virtual void Vf224();
    virtual void Vf228();
    virtual void Vf22c();
    virtual void Vf230();
    virtual void Vf234();
    virtual void Vf238();
    virtual void Vf23c();
    virtual void Vf240();
    virtual void Vf244();
    virtual void Vf248();
    virtual void Vf24c();
    virtual void Vf250();
    virtual void Vf254();
    virtual void Vf258();
    virtual void Vf25c();
    virtual void Vf260();
    virtual void Vf264();
    virtual void Vf268();
    virtual void Vf26c();
    virtual void Vf270();
    virtual void Vf274();
    virtual void Vf278();
    virtual void Vf27c();
    virtual void Vf280();
    virtual void Vf284();
    virtual void Vf288();
    virtual void Vf28c();
    virtual void Vf290();
    virtual void Vf294();
    virtual void Vf298();
    virtual void Vf29c();
    virtual void Vf2a0();
    virtual void Vf2a4();
    virtual void Vf2a8();
    virtual void Vf2ac();
    virtual void Vf2b0();
    virtual void Vf2b4();
    virtual void Vf2b8();
    virtual float GetCurrentTargetDistance(int iUnused);
    virtual void SetTarget(FUN_004f2770_Class* pkTarget);
};

class MoverW_1d50
{
  public:
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2c;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3c;
    unsigned short m_unk40;
    unsigned short m_usPathCount;
};

B006815c0_1d50 FUN_009a88e0(ActorS_1d50* pkActor, B006815c0_1d50 kTarget);

class PackageProcW_1d50
{
  public:
    virtual void Vf00();
    virtual void Vf04();
    virtual void Vf08();
    virtual void Vf0c();
    virtual void Vf10();
    virtual void Vf14();
    virtual float GetElapsed();

    void FUN_009e68c0();
    int FUN_009e1d50(int iUnused);

    ActorS_1d50* m_pkActor;
    MoverW_1d50* m_pkMover;
    NiPointer<PathingSolution_1d50> pCurrentPathingSolution;
    NiPointer<PathingRequest_1d50> m_pPathingRequest;
    int m_unk14;
    int m_unk18;
    NiPoint3 m_kMoveDelta;
    NiPoint3 m_kBlockedTarget;
    NiPoint3 m_kTetherTarget;
    NiPoint3 m_kLastLoc;
    NiPoint3 m_kLastTether;
    int m_unkAvoid0;
    int m_unkAvoid1;
    int m_iMoveMode;
    int m_iNodeIndex;
    float m_fRotateGoal;
    float m_fPathLength;
    float m_fCurrentSplineT;
    float m_fActorAvoidTimer;
    float m_fAvoidDetectionVal;
    int m_iUnblockDir;
    float m_fAltFacingAngle;
    float m_fBlockedStartAngle;
    float m_fBlockTime;
    float m_fTimeInAnim;
    float m_fRunWalkTime;
    float m_fMinRotateTime;
    float m_fWaitTime;
    float m_fLastFrameMinMoveDelta;
    NiPoint3 m_kLastFrameMinMoveDelta;
    float m_fGoalRadiusSqr;
    float m_fFallTime;
    float m_fDistanceTraveled;
    float m_fIgnoreLookAtTimer;
    float m_fLastRotApplied;
    bool m_bIgnoreInitialRotation;
    bool m_bIgnoreInitialRotationKeepHeading;
    unsigned short m_usUnkC2;
    float m_fIgnoreInitialRotationTetherParam;
    int m_iFadeIndex;
    int m_iNextState;
    int m_iAvoidState;
    int m_iDoorState;
    void* m_pCurrentDoor;
    bool m_bRotateMode;
    bool m_bRotateCCW;
    bool m_bMovementBlocked;
    bool m_bEndUpdatePath;
    bool m_bWaitingForUpdate;
    bool m_bIgnoreLookAtPoint;
    bool m_bDeltaComputedThisFrame;
    char m_cUnkE3;
};

// Computes the actor's next move position and heading from the pathing solution, applies it, and returns the next state index.
// @fnv 0x009e1d50
int PackageProcW_1d50::FUN_009e1d50(int iUnused)
{
    bool bAtEnd;
    unsigned int uiCell6;
    ContNode_1d50* pvRef4;
    int iResultY2;
    float fHeading9;
    float fRateVal;
    PathingLocation_1d50* pkLocation8;
    float fSpeedB;
    unsigned int uiWorld3;
    float fElapsed9;

    reinterpret_cast<::FUN_009e5480_shell *>(this)->ResetPathState();
    reinterpret_cast<::fnv_009e68c0::FUN_009e68c0 *>(this)->Reset();
    m_bRotateMode = false;
    m_iFadeIndex = 2;
    m_iNextState = 3;
    m_fFallTime = 0.0f;
    if (m_pPathingRequest && reinterpret_cast<::FUN_009e20a0_Class *>((((PathingRequest_1d50*)m_pPathingRequest)))->GetByteAtOffset9F())
    {
        m_pkActor->SetTarget((FUN_004f2770_Class*)_g_thePlayer);
        return 0;
    }
    fElapsed9 = m_fPathLength - GetElapsed();
    pvRef4 = ((::ContNode_1d50 *)(reinterpret_cast<::S_FUN_006b05a0 *>((((PathingSolution_1d50*)pCurrentPathingSolution)))->FUN_006b05a0()));
    pkLocation8 = pvRef4->FUN_00717e50();
    NiPoint3 kPos2 = reinterpret_cast<::TaskQueueInterface *>((void *)(pkLocation8))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
    fHeading9 = (::GetDirectionAngle)((const ::NiPoint3 *)&(*((::NiPoint3 *)(reinterpret_cast<::TESRegion *>((pvRef4))->GetDiffuseColor()))));
    uiCell6 = (unsigned int)reinterpret_cast<::PathingLocation *>((void *)(pkLocation8))->GetContainingCell();
    uiWorld3 = (unsigned int)((::TESWorldSpace *)(reinterpret_cast<::BGSTerrainManager *>((void *)(pkLocation8))->GetMinLevel()));
    fRateVal = ::DAT_01012640 / reinterpret_cast<::Calendar *>(&(g_calendar))->GetGameTimeScale();
    fSpeedB = reinterpret_cast<::fnv_008a0b10::FUN_008a0b10_shell *>((m_pkActor))->FUN_008a0b10() * fRateVal;
    bAtEnd = (m_pkMover->m_usPathCount + 1) == ::FUN_005a4320((char *)(((PathingSolution_1d50*)pCurrentPathingSolution)));
    if (m_pkActor->GetSitSleepState() == 4 && m_pkActor->GetSitSleepState() == 9)
    {
    }
    else
    {
        if (m_pPathingRequest && reinterpret_cast<::FUN_00505c00_shell *>((((PathingRequest_1d50*)m_pPathingRequest)))->FUN_00505c00() && bAtEnd)
        {
            fHeading9 = reinterpret_cast<::FUN_00507e10_shell *>((((PathingRequest_1d50*)m_pPathingRequest)))->FUN_00507e10();
        }
        else if (reinterpret_cast<::ActorMover *>((m_pkMover))->HasLookAtTarget())
        {
            B006815c0_1d50 kTarget;
            reinterpret_cast<::ActorMover *>((m_pkMover))->GetLookAtTargetPosition((*(::NiPoint3 *)(&kTarget)));
            B006815c0_1d50 kTargetPt = FUN_009a88e0(m_pkActor, kTarget);
            fHeading9 = WrapAngle(kTargetPt.z);
        }
        else
        {
            unsigned int ItemUpdateArray = ::GetObjectFlags((char *)(((PathingSolution_1d50*)pCurrentPathingSolution)));
            if (ItemUpdateArray > 1)
            {
                NiPoint3 kPrevTmp = reinterpret_cast<::TaskQueueInterface *>((void *)(((::ContNode_1d50 *)(reinterpret_cast<::FUN_006e7970_shell *>((((PathingSolution_1d50*)pCurrentPathingSolution)))->FUN_006e7970(ItemUpdateArray - 2)))
                                        ->FUN_00717e50()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
                NiPoint3 kLastX = reinterpret_cast<::TaskQueueInterface *>((void *)(((::ContNode_1d50 *)(reinterpret_cast<::FUN_006e7970_shell *>((((PathingSolution_1d50*)pCurrentPathingSolution)))->FUN_006e7970(ItemUpdateArray - 1)))
                                      ->FUN_00717e50()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr);
                NiPoint3 kDiff = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(((PointW_1d50&)kLastX)))->FUN_00439ef0((::NiPoint3 *)&(kPrevTmp), *(const ::NiPoint3 *)nullptr)));
                fHeading9 = (::GetDirectionAngle)((const ::NiPoint3 *)&(kDiff));
            }
            else
            {
                fHeading9 = m_pkActor->GetCurrentTargetDistance(0);
            }
        }
    }
    reinterpret_cast<::fnv_008ad1c0::MoveSelf454 *>((m_pkActor))->FUN_008ad1c0((int)&(kPos2), fHeading9, (TESObjectCELL*)uiCell6, (TESWorldSpace*)uiWorld3, 1, 0);
    iResultY2 = 5;
    reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
    m_iFadeIndex = 5;
    if (!bAtEnd)
        iResultY2 = 6;
    return iResultY2;
}

struct EndRotateHandler : DetailedActorPathHandler
{
    bool FUN_009e7550();
};
// Runs the actor's per-frame movement update: checks state, controller, path and avoidance, then updates delta, rotation and movement.
// @fnv 0x009e0a00
int UpdateHandler::UpdateMovementState(float afDeltaTime)
{
    if (state == 5 || state == 6)
        return 5;

    if (!reinterpret_cast<::FUN_008843a0_shell *>((actor))->FUN_008843a0())
    {
        if ((UpdateNodeList*)path)
        {
            int result = reinterpret_cast<::fnv_009e8000::FUN_009e8000_shell *>(this)->UpdatePathingGoal();

            if (result == 5)
            {
                reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
                state = 5;
                return result;
            }
        }
        return 0;
    }
    computed = true;

    UpdateController* e = ((::UpdateController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((actor))->FUN_009306d0()));

    if (afDeltaTime == 0.0 || e == 0)
    {
        reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
        return 0;
    }
    if (reinterpret_cast<::PlayerCharacter *>((_g_thePlayer))->IsSleepingOrResting())
        return SleepingUpdate(afDeltaTime);

    if (::FUN_005c0880((char *)(e)) == 2)
    {
        fallTime = reinterpret_cast<::FUN_0088b0f0_Class *>((e))->GetField548();

        if (fallTime > 0.40000000596046448)
        {
            reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
            return 0;
        }
    }
    else
    {
        if (fallTime > 0.64999997615814209)
        {
            reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
            return 4;
        }
        fallTime = 0.0f;
    }
    if (!rotateMode && !waiting)
    {
        int result = reinterpret_cast<::fnv_009e8000::FUN_009e8000_shell *>(this)->UpdatePathingGoal();

        if (result != 0 && (result != 5 || !reinterpret_cast<::EndRotateHandler *>(this)->FUN_009e7550()))
        {
            reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
            state = 5;
            return result;
        }
    }
    if (!waiting)
        reinterpret_cast<::fnv_009e3d50::DetailedActorPathHandlerEx *>(this)->UpdatePathing(afDeltaTime);

    if (ignoreInitial && splineT >= ignoreTether)
    {
        ignoreInitial = false;
        keepHeading = false;
        ignoreTether = 0.0f;
    }
    if (rotateMode)
    {
        float c = reinterpret_cast<::FUN_009e7d70_shell *>(this)->FUN_009e7d70(afDeltaTime);
        actor->SetFurnitureHeading(c);

        float j = 0.0f;
        float e = 0.0f;

        reinterpret_cast<::PathAngles *>(this)->GetPathAngles((*(float *)(&j)), (*(float *)(&e)));
        reinterpret_cast<::FUN_009e4c60_t *>(this)->UpdateLookingAngle(afDeltaTime, e);

        delta = (*reinterpret_cast<const ::P3Update *>((void *)&::NiPoint3::ZERO));
        lastMinDelta = 0.0f;
        lastDelta = (*reinterpret_cast<const ::P3Update *>((void *)&::NiPoint3::ZERO));

        reinterpret_cast<::TESForm *>((mover))->ClearData();
        return 0;
    }
    if (state == 4)
    {
        reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
        return 0;
    }
    if (avoidState == 2)
    {
        waitTime -= afDeltaTime;

        if (waitTime > 0.0)
        {
            int result = Detect(afDeltaTime);

            if (result == 0)
            {
                avoidanceTimer -= afDeltaTime;

                if (avoidanceTimer <= 0.0)
                {
                    waitTime = 0.0f;
                    avoidState = 1;
                }
            }
            else if (result == 3)
            {
                reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
                return 1;
            }
            else
                avoidanceTimer = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::UpdateFloatSetting *>(&::g_011f2b2c))))));
        }
        else
        {
            waitTime = 0.0f;
            avoidState = 1;
        }
        reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
        return 0;
    }
    switch (CheckState())
    {
    case 1:
        reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
        return 0;
        break;

    case 2:
        reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
        return 3;
    }
    reinterpret_cast<::fnv_009e2aa0::FUN_009e2aa0_shell *>(this)->FUN_009e2aa0(afDeltaTime);

    if (!reinterpret_cast<::MotionTarget *>(this)->UpdateMotion(afDeltaTime))
    {
        if (state == 4)
        {
            reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
            return 0;
        }
        avoidState = 5;
        return 1;
    }
    reinterpret_cast<::S_009e3520 *>(this)->UpdateSpeed(afDeltaTime);

    if (*(*reinterpret_cast<::UpdateBoolSetting *>(&::g_011f2bb8)).Bool())
    {
        if (!movementBlocked)
        {
            int result = Detect(afDeltaTime);

            if (result != 0)
            {
                detection = 0.0f;

                switch (result)
                {
                case 3:
                    reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
                    return 1;
                    break;

                case 1:
                    avoidState = 2;
                    reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
                    return 0;
                    break;

                case 2: {
                    UpdatePtr newRequest = new UpdateRequest;

                    reinterpret_cast<::PathingRequest *>((((UpdateRequest*)request)))->CopyTo((::PathingRequest *)(::UpdateRequest *)(newRequest));

                    if (!(UpdateNodeList*)path)
                    {
                        avoidState = 2;
                        reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
                        return 0;
                    }
                    else
                    {
                        if (!reinterpret_cast<::FUN_006b05d0_shell *>((((UpdateNodeList*)path)))->FUN_006b05d0())
                            reinterpret_cast<::PathingRequest *>((((UpdateRequest*)newRequest)))->SetDestination((::PathingLocation *)(::PointLocation *)(((UpdateNodeList*)path)->Last()->Location()));

                        else
                        {
                            if (!reinterpret_cast<::FUN_006a9520_Class *>((((::PointLocation *)(::FUN_006a9540((char *)(((UpdateRequest*)request)))))))->FUN_006a9520())
                                reinterpret_cast<::PathingRequest *>((((UpdateRequest*)newRequest)))->SetDestination((::PathingLocation *)(::PointLocation *)(((::PointLocation *)(::FUN_006a9540((char *)(((UpdateRequest*)request)))))));

                            else
                                reinterpret_cast<::PathingRequest *>((((UpdateRequest*)newRequest)))->SetDestination((::PathingLocation *)(::PointLocation *)(((UpdateNodeList*)path)->Last()->Location()));
                        }
                    }
                    reinterpret_cast<::FUN_009e16c0_Class *>((((UpdateRequest*)newRequest)))->FUN_009e16c0();
                    avoidState = 3;

                    reinterpret_cast<::ActorMoverBuildPath14 *>((mover))->FUN_009db090((const ::PathingRequest *)(const ::UpdateRequest *)(newRequest));

                    if (mover->unk6c == 6)
                    {
                        reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
                        waiting = false;
                        state = 5;
                    }
                    if (waiting)
                    {
                        path = 0;

                        if (state == 4)
                        {
                            reinterpret_cast<::FUN_009e8790_shell *>(this)->ResetMoveState();
                            return 0;
                        }
                    }
                    else
                        avoidState = 1;
                }
                break;
                }
            }
        }
        if (avoidState == 4)
        {
            avoidanceTimer -= afDeltaTime;

            if (avoidanceTimer < 0.0)
            {
                avoidanceTimer = 0.0f;
                avoidState = 1;
            }
        }
    }
    float j = 0.0f;

    float c = reinterpret_cast<::fnv_009e4800::DetailedActorPathHandlerRot *>(this)->FUN_009e4800(afDeltaTime, &j);
    actor->SetFurnitureHeading(c);

    reinterpret_cast<::TESForm *>((mover))->ClearData();

    if (j > 0.0)
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::P3Update &)(delta))->FUN_00439180(j);

    reinterpret_cast<::fnv_009e3560::FUN_009e3560_shell *>(this)->UpdatePathRotation(afDeltaTime);

    lastMinDelta = reinterpret_cast<::FUN_00589850_Class *>((void *)&(delta))->FUN_00589850();

    UpdateMatrix l;

    reinterpret_cast<::FUN_009e1640_shell *>(&(l))->SetRotationMatrix(actor->Heading(false));

    lastDelta = l.Transform(&delta);

    if (state == 3)
    {
        P3Update c = tether - lastTether;

        c.z = 0.0f;

        P3Update j = tether - actor->Position();

        j.z = 0.0f;

        float e = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(c))->DotProduct((void *)&(j));

        if (e <= 0.0)
            state = 4;

        return 0;
    }
    if ((UpdateNodeList*)path && nodeIndex + 1 >= ::GetObjectFlags((char *)(((UpdateNodeList*)path))))
    {
        float remaining = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::P3Update &)((actor->Position() - (*(::P3Update *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((::UpdateNode *)(reinterpret_cast<::S_FUN_006b05a0 *>((((UpdateNodeList*)path)))->FUN_006b05a0()))->Location()))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))))))->FUN_00589850();

        if (lastMinDelta > remaining)
        {
            float savedZ = delta.z;

            reinterpret_cast<::FUN_004a0c10_s *>(&(delta))->FUN_004a0c10();
            delta.x *= remaining;
            delta.y *= remaining;
            delta.z = savedZ;

            lastMinDelta = reinterpret_cast<::FUN_00589850_Class *>((void *)&(delta))->FUN_00589850();
            lastDelta = delta;
        }
    }
    return 0;
}

// @fnv 0x009e7550
bool EndRotateHandler::FUN_009e7550()
{
    if (reinterpret_cast<::FUN_00505c00_shell *>((((PathingRequest_1d50*)m_pPathingRequest.operator->())))->FUN_00505c00() &&
        ((MoverW_1d50*)m_pActorMover)->m_usPathCount + 1 ==
            ::FUN_005a4320((char *)(((PathingSolution_1d50*)pCurrentPathingSolution.operator->()))) &&
        pActor->Unk_85() != 4 && pActor->Unk_85() != 9)
    {
        reinterpret_cast<::FUN_009e7610_shell *>(this)->TurnTowardGoalAngle(reinterpret_cast<::FUN_00507e10_shell *>((((PathingRequest_1d50*)m_pPathingRequest.operator->())))->FUN_00507e10(), false, false);
        return m_bPathFlag1;
    }

    return false;
}

#include "generated/data/fallout/ai/movement/detailedactorpathhandler.inc"
