
#include <cstdint>
#include <new>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/B00C20Pool.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DecalStub.h"
#include "fnv/decl/FNVOwner.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_0042f9c0_Class.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004769c0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a3c90.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_004ee840_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00518080_shell.h"
#include "fnv/decl/FUN_00554650_Class.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00633c90.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_0068f230_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_00691c90_shell.h"
#include "fnv/decl/FUN_006969e0_shell.h"
#include "fnv/decl/FUN_006993c0_cls.h"
#include "fnv/decl/FUN_006ad180_Cls.h"
#include "fnv/decl/FUN_006bf8f0_Class.h"
#include "fnv/decl/FUN_006c6200_cls.h"
#include "fnv/decl/FUN_006c6260_Class.h"
#include "fnv/decl/FUN_006c68b0_Class.h"
#include "fnv/decl/FUN_006c6b10_Class.h"
#include "fnv/decl/FUN_006ebc70_shell.h"
#include "fnv/decl/FUN_006ebc90_shell.h"
#include "fnv/decl/FUN_006ebcd0_shell.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_008078b0_Class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00b00ae0_class.h"
#include "fnv/decl/FUN_00b00b40_cls.h"
#include "fnv/decl/FUN_00c9c700_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/HostC9C6.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ListReader.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/ListX.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/Map6920.h"
#include "fnv/decl/MemoryManager.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NavMesh.h"
#include "fnv/decl/NavMeshInfo.h"
#include "fnv/decl/NavMeshPortalMgr68F3.h"
#include "fnv/decl/NavMeshPtr.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/ObsList.h"
#include "fnv/decl/ObsMgr.h"
#include "fnv/decl/ObstacleTaskShell.h"
#include "fnv/decl/P3.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Queue6c67.h"
#include "fnv/decl/QueueConsumer.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S006911c0.h"
#include "fnv/decl/S2f850.h"
#include "fnv/decl/S_00a592c0_Matrix3.h"
#include "fnv/decl/ScriptLocals.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Unk00690e30.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WorldObject_c8d3.h"
#include "fnv/decl/bhkCollisionObject.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00457070__FUN_00457070_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004bc450__FUN_004bc450_S.h"
#include "fnv/decl/fnv_005609b0__bhkRigidBody.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_006a5ca0__PaddedBooleanState.h"
#include "fnv/decl/fnv_006c6e60__TSQueueHandle.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_0084b5c0__FUN_0084b5c0_Array.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00c9c0f0__hkpWorldC9C0.h"
#include "fnv/decl/fnv_anon_tile__NiPoint2_Sub.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b2000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b4000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00552000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_00694000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_006c2000.h"
#include "fnv/symbols_006c4000.h"
#include "fnv/symbols_006c5000.h"
#include "fnv/symbols_006d9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b00000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0106c000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011d7000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "navmeshobstaclemanager_decls.h"
// Locks the manager's lock, appends task to the array at offset 0x14c, then unlocks.
// @fnv 0x006c4f70
void NavMeshObstacleManager::AddProcessedTask(ObstacleTaskData* task)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)((char*)this + 0x160))))->FUN_0040fbf0((char *)("NavMeshObstacleManager::AddProcessedTask()"));
    reinterpret_cast<::FUN_00438690 *>((((BSSimpleArray<NavMeshInfo*, 1024>*)((char*)this + 0x14c))))->FUN_007cb2e0((unsigned int *)&((NavMeshInfo*&)task));
    ((RecursiveSpinLock*)((char*)this + 0x160))->FUN_0040fba0();
}
// @fnv 0x006c4540
bool NavMeshObstacleManager::ClearBackgroundTasks()
{
    unsigned int size = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 0x14c))))->GetName()));
    for (unsigned int i = 0; i < size; i++)
    {
        delete (ObstacleTaskData*)((NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*)((char*)this + 0x14c))
            ->GetAt(i);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 0x14c))))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)this + 0x13c))))->Clear(true);
    return true;
}
// @fnv 0x006c4ec0
void NavMeshObstacleManager::QueueObstacleTasks()
{
    struct
    {
        TESFile* key;
        ObstacleTaskData* task;
        TESFile* iterator;
    } locals;
    locals.iterator = (TESFile*)((BGSReconstructFormsInAllFilesMap*)((char*)this + 0x12c))->GetFirstPos();
    while (locals.iterator)
    {
        reinterpret_cast<::C6b7f20_Map *>((((BGSReconstructFormsInAllFilesMap*)((char*)this + 0x12c))))->FUN_006b7f20((::C6b7f20_Node **)&((void*&)locals.iterator), (unsigned int *)&(locals.key), (void **)&((BGSReconstructFormsInFileMap*&)locals.task));
        if (((SettingT<INISettingCollection>*)&g_011d71a0)->Bool()->b)
            ProcessObstacleTask(locals.task);
        else
        {
            reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)((char*)this + 0x160))))->FUN_0040fbf0((char *)(0));
            reinterpret_cast<::FUN_00438690 *>((((BSSimpleArray<NavMeshInfo*, 1024>*)((char*)this + 0x13c))))->FUN_007cb2e0((unsigned int *)&((NavMeshInfo*&)locals.task));
            ((RecursiveSpinLock*)((char*)this + 0x160))->FUN_0040fba0();
            locals.task->Run();
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<unsigned int, unsigned int>*)((char*)this + 0x12c))))->FUN_00438af0();
}
// @fnv 0x006c47e0
void NavMeshObstacleManager::ClearObstacles()
{
    BSSimpleList<BGSPerkEntry*>* item = (BSSimpleList<BGSPerkEntry*>*)((char*)this + 0x34);
    while (item && !((BSSimpleList<BGSCameraShot*>*)item)->IsEmpty())
    {
        unsigned int auiFormId = (unsigned int)(std::uintptr_t)(item->m_item);
        item = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((item))->FUN_00726070()));
        NiPointer<AnimIdle> spReference((AnimIdle*)0);
        if (((NiTMapBase<DFALL<NiTMapItem<bhkRigidBody*, NiPointer<ObstacleData> > >, bhkRigidBody*,
                         NiPointer<ObstacleData> >*)((char*)this + 0x1c))
                ->GetAt((bhkRigidBody*)auiFormId, (NiPointer<ObstacleData>&)spReference))
        {
            for (unsigned int i = 0;
                 i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((BSSimpleArray<SandboxProcedureData, 1024>*)((char*)(AnimIdle*)spReference + 0xc))))->GetName()));
                 i++)
            {
                reinterpret_cast<::ListReader *>((((BSSimpleList<NiPointer<ObstacleData> >*)((char*)this + 0x3c))))->FUN_00631620((const ::NodeValue &)((const NiPointer<
                              ObstacleData>&)((NiTArray<TESObjectREFR*,
                                                        NiTNewInterface<TESObjectREFR*> >*)((char*)(AnimIdle*)
                                                                                                spReference +
                                                                                            0xc))
                                 ->GetAt(i)));
            }
        }
        RemoveObstaclesForReference(auiFormId);
    }
    reinterpret_cast<::FileMatchList *>((((BSSimpleList<ActorCause*>*)((char*)this + 0x34))))->RemoveAll();
}

struct S4ee810
{
    int base;
    int x;
    void GlobalObject_00633c90(int);
    S4ee810* FUN_004ee810();
};
// Calls GlobalObject_00633c90 with 0, sets x to 0, and returns this.
// @fnv 0x004ee810
S4ee810* S4ee810::FUN_004ee810()
{
    new ((void *)this) ::FUN_00633c90((::G00559a40 *)(0));
    x = 0;
    return this;
}

struct DummyStruct_00631820
{
    void* m_pObject;
    bool IsNotEqual(const DummyStruct_00631820& ptr) const;
};

// @fnv 0x00631820
bool DummyStruct_00631820::IsNotEqual(const DummyStruct_00631820& aOther) const
{
    return m_pObject != aOther.m_pObject;
}

struct FUN_006c07d0_shell : public NavMeshObstacleManager
{
    bool FUN_006c07d0();
};


struct BSWin32TaskletManager
{
    bool GetTaskletValue(void*);
};


struct Struct_128
{
    bool FUN_006c08e0();
};

struct Struct_120
{
    int dummy;
    Struct_120()
    {
        FUN_006c00b0();
    }
    void FUN_006c00b0();
};

struct Struct_124
{
    int dummy;
    Struct_124()
    {
        FUN_006c0210();
    }
    void FUN_006c0210();
};

// Checks the tasklet manager and the object at offset 0x128, then allocates two objects stored at offsets 0x120 and 0x124; returns false on either check failing.
// @fnv 0x006c07d0
bool FUN_006c07d0_shell::FUN_006c07d0()
{
    if (!::GetTaskletManager().GetTaskletValue((char*)this + 0x128))
        return false;
    if (!((Struct_128*)((char*)this + 0x128))->FUN_006c08e0())
        return false;
    *(Struct_120**)((char*)this + 0x120) = new Struct_120;
    *(Struct_124**)((char*)this + 0x124) = new Struct_124;
    return true;
}

class BSWin32TaskletManager;

struct FUN_00b00ae0_shell
{
};

// @fnv 0x006c08e0
void FUN_006c08e0(void* pThis)
{
    reinterpret_cast<::FUN_00b00ae0_class *>(&(reinterpret_cast<FUN_00b00ae0_shell&>(::GetTaskletManager())))->FUN_00b00ae0((void **)(pThis));
}

class BSWin32TaskletManager;
void FUN_00b00bc0(BSWin32TaskletManager*, int, void*);

struct Dummy006c09d0
{
    void f();
};
typedef void (Dummy006c09d0::*MemFn)(void*);

// @fnv 0x006c09d0
void FUN_006c09d0(void* pThis)
{
    ((void(*)(BSWin32TaskletManager*, void*)) & FUN_00b00bc0)(&::GetTaskletManager(), pThis);
}

struct Actor;
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTextureSet;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct TeleportableReference;
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
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESGlobal;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESSound;
struct FileEntryList;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct DistantTreeTextureInfo;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkNiCollisionObject;
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
struct FUN_006c0f10_shell : public NavMeshObstacleManager
{
    void UpdateDoorObstacle(TESObjectREFR*);
};

struct TESObjectDOOR;
unsigned int _FNV_GetFormType(TESBoundObject*);

struct Call_006c0c80
{
    void FUN_006c0c80(TESObjectREFR*);
};
struct Call_00905330
{
};
class GlobalObject_0044fae0
{
  public:
    GlobalObject_0044fae0();
    ~GlobalObject_0044fae0();
    char m_acData[0x18];
public:
    void FUN_004538a0(int);
};
class FUN_006c5fc0
{
  public:
    FUN_006c5fc0(unsigned int uiSize);
    ~FUN_006c5fc0();
    int m_kNextStreamField[4];
};
class GlobalObject2_0096a2d0
{
  public:
    GlobalObject2_0096a2d0();
    ~GlobalObject2_0096a2d0();
    void* m_pkItem;
    void* m_pkNext;
};
class GlobalObject_004ee810
{
  public:
    GlobalObject_004ee810();
    ~GlobalObject_004ee810();
    int m_kNextStreamField[9];
};
template <class T> class LockFreeQueue
{
  public:
    LockFreeQueue(unsigned int uiSize, unsigned int uiGrow);
    ~LockFreeQueue();
    int m_kNextStreamField[16];
};
class FUN_006c6070
{
  public:
    FUN_006c6070(unsigned int uiSize);
    ~FUN_006c6070();
    int m_kNextStreamField[4];
};
class GlobalObject_0044dee0
{
  public:
    GlobalObject_0044dee0();
    ~GlobalObject_0044dee0();
    int m_iData;
};
class FUN_006c60a0
{
  public:
    FUN_006c60a0(unsigned int uiSize);
    ~FUN_006c60a0();
    int m_kNextStreamField[4];
};
class FUN_006c6c10
{
  public:
    FUN_006c6c10();
    ~FUN_006c6c10();
    int m_kNextStreamField[4];
};
class StrList
{
  public:
    StrList();
    void* m_pkItem;
    void* m_pkNext;
};
class GlobalObject_00633c90
{
  public:
    GlobalObject_00633c90(int iValue);
    ~GlobalObject_00633c90();
    void* m_pPointer;
};
class GlobalObject_0045d260
{
  public:
    GlobalObject_0045d260(const char* pcCategory, const char* pcName, int iEnabled, int iVisible);
    bool m_bValue;
};
class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pcFile, int iLine);
    ~AutoMemContext();
    int m_iContext;
};
struct GlobalObject_0044dee0_d00483710 : GlobalObject_0044dee0
{
    ~GlobalObject_0044dee0_d00483710();
};
class FUN_006c02c0 : public GlobalObject_0044fae0
{
  public:
    FUN_006c02c0();
    bool m_bModifierActive;
    FUN_006c5fc0 m_kTasks;
    GlobalObject2_0096a2d0 m_kAdded;
    GlobalObject2_0096a2d0 m_kRemoved;
    GlobalObject_004ee810 m_kLock;
    LockFreeQueue<bhkRigidBody*> m_kAddQueue;
    LockFreeQueue<bhkRigidBody*> m_kRemoveQueue;
    FUN_006c6070 m_kObstacles;
    GlobalObject2_0096a2d0 m_kPending;
    GlobalObject2_0096a2d0 m_kProcessed;
    FUN_006c5fc0 m_kTasksB;
    FUN_006c5fc0 m_kTasksC;
    int m_iCount120;
    int m_iCount124;
    GlobalObject_0044dee0_d00483710 m_kTimer;
    FUN_006c60a0 m_kRefMap;
    FUN_006c6c10 m_kQueueA;
    FUN_006c6c10 m_kQueueB;
    int m_iPad15C;
    StrList m_kRefs;
    int m_aiPad168[6];
    GlobalObject2_0096a2d0 m_kCurrent;
    GlobalObject2_0096a2d0 m_kDone;
    int m_iTask190;
    float m_fInterval;
    bool m_bPaused;
    char m_acPad199[3];
    GlobalObject_00633c90 m_spTask;
    GlobalObject_0045d260 m_kUpdateTimer;
    GlobalObject_0045d260 m_kBackgroundTimer;
};

// @fnv 0x006c1170
void FUN_006c1170(char* pThis)
{
    pThis[0x18] = 1;
}

namespace fnv_006c34f0 {
template <typename T> class BSStringT
{
  public:
    operator char const*() const;
};

void __cdecl ClearStringAndCheck(void* param1, BSStringT<char>* param2);

// Stores the result of _ref_0084e3a0(param1) at offset 8 of param2's string, then calls ClearStringAndCheck(param1, param2).
// @fnv 0x006c34f0
void __cdecl FUN_006c34f0(void* param1, BSStringT<char>* pString)
{
    *(void**)(const_cast<char*>(pString->operator char const*()) + 8) = ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((param1))->FUN_0084e3a0()));
    ClearStringAndCheck(param1, pString);
}
}  // namespace fnv_006c34f0

struct BSStringT_char
{
    operator const char*() const;
};
struct Arr3520
{
    void RemoveAll(bool);
};
struct Obj3520
{
    void** vt;
};
typedef void*(* Fn3520)(Obj3520*);
// @fnv 0x006c3520
bool ClearStringAndCheck(Obj3520* pObj, BSStringT_char* pString)
{
    reinterpret_cast<::FUN_006c6200_cls *>((((Arr3520*)((const char*)*pString + 0xc))))->FUN_006c6200(true);
    if (((Fn3520)pObj->vt[116])(pObj))
        return ::fnv_006c2210::RegisterCollisionObstacles((::fnv_006c2210::NiAVObject *)(void *)(((Fn3520)pObj->vt[116])(pObj)), (::fnv_006c2210::Flt *)(pString));
    else
        return false;
}

struct S6c4350
{
    int a;
    short b;
    int c;
    S6c4350* FUN_006c4350(const S6c4350& o);
};
// Calls _ref_006815c0, then copies fields a, b and c from o into this and returns this.
// @fnv 0x006c4350
S6c4350* S6c4350::FUN_006c4350(const S6c4350& aOther)
{
    a = aOther.a;
    b = aOther.b;
    c = aOther.c;
    return this;
}

namespace fnv_006c44d0 {
struct FUN_006c44d0_shell : public NavMeshObstacleManager
{
    bool FUN_006c44d0();
};


struct TESObjectREFR
{
    unsigned int GetFlags(void);
};

}  // namespace fnv_006c44d0
template <> class BSSimpleArray<unsigned int, 1024>
{
  public:
    unsigned int& GetAt(unsigned int);
};
namespace fnv_006c44d0 {

// Iterates the task array at this+0x14c, calls FUN_006c85e0 on each task, and returns whether any call succeeded.
// @fnv 0x006c44d0
bool FUN_006c44d0_shell::FUN_006c44d0()
{
    bool bNavmeshesUpdated = false;
    unsigned int icount = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR*)((char*)this + 0x14c))))->GetName()));
    for (unsigned int t = 0; t < icount; ++t)
    {
        unsigned int ptask = ((BSSimpleArray<unsigned int, 1024>*)((char*)this + 0x14c))->GetAt(t);
        if (reinterpret_cast<::ObstacleTaskShell *>((ptask))->FUN_006c85e0())
        {
            bNavmeshesUpdated = true;
        }
    }
    return bNavmeshesUpdated;
}
}  // namespace fnv_006c44d0

struct FUN_006c4900_shell : public NavMeshObstacleManager
{
    bool FUN_006c4900();
};

bool _ref_008256d0(void* pThis);

// Iterates the list at this+0x180, calls FUN_00694500 on each entry's value, then removes all entries and returns true.
// @fnv 0x006c4900
bool FUN_006c4900_shell::FUN_006c4900()
{
    BSSimpleList<int>* pCurrentElementNext = reinterpret_cast<BSSimpleList<int>*>(reinterpret_cast<char*>(this) + 0x180);
    while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
    {
        int meshID = pCurrentElementNext->m_item;
        ::FUN_00694500(meshID, 0);
        pCurrentElementNext = ((::BSSimpleList<int> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>((reinterpret_cast<BSSimpleList<int>*>(reinterpret_cast<char*>(this) + 0x180)))->RemoveAll();
    return true;
}

extern int DAT_0106c5d8;

// Sets pThis[0] to the address of DAT_0106c5d8 and pThis[1] to 0, then returns pThis.
// @fnv 0x006c5e40
int* FUN_006c5e40(int* pObject)
{
    pObject[0] = (int)&DAT_0106c5d8;
    pObject[1] = 0;
    return pObject;
}

extern int DAT_0106c5d8;

// @fnv 0x006c5e70
void FUN_006c5e70(int** ppObject)
{
    *ppObject = &DAT_0106c5d8;
}

namespace fnv_006c5ec0 {
struct TM6c5ec0
{
};
struct S6c5ec0
{
    void FUN_006c5ec0(void* task, bool last);
};
// Forwards this object, task and last to the tasklet manager's TryProcessPair.
// @fnv 0x006c5ec0
void S6c5ec0::FUN_006c5ec0(void* task, bool last)
{
    reinterpret_cast<::FUN_00b00b40_cls *>(&((*(::fnv_006c5ec0::TM6c5ec0 *)&(::GetTaskletManager()))))->TryProcessPair((void **)(void *)(this), (void **)(task), last);
}
}  // namespace fnv_006c5ec0

extern int DAT_0106c5e0;

struct FUN_006c5fc0_shell
{
    void* vftable;
    FUN_006c5fc0_shell* FUN_006c5fc0(unsigned int uiHashSize);
};

// Calls FUN_006c6260 with uiHashSize, sets the vftable to DAT_0106c5e0, and returns this.
// @fnv 0x006c5fc0
FUN_006c5fc0_shell* FUN_006c5fc0_shell::FUN_006c5fc0(unsigned int uiHashSize)
{
    new ((void *)this) ::FUN_006c6260_Class(uiHashSize);
    vftable = &DAT_0106c5e0;
    return this;
}

extern int DAT_0106c600;

struct FUN_006c6070_Class
{
    void* vftable;
    void* FUN_006c6070(unsigned int uiHashSize);
};

// Calls FUN_006c68b0 with uiHashSize, sets the vftable to DAT_0106c600, and returns this.
// @fnv 0x006c6070
void* FUN_006c6070_Class::FUN_006c6070(unsigned int uiHashSize)
{
    reinterpret_cast<::FUN_006c68b0_Class *>(this)->FUN_006c68b0(uiHashSize);
    vftable = &DAT_0106c600;
    return this;
}

extern int DAT_01031fac;

struct FUN_006c60a0_arg
{
    unsigned int val;
};


// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x006c60a0
int* FUN_006c60a0(int* self, FUN_006c60a0_arg aArg)
{
    reinterpret_cast<::FUN_006c6b10_Class *>((self))->FUN_006c6b10((*(unsigned int *)&(const ::FUN_006c60a0_arg &)(aArg)));
    *self = (int)&DAT_01031fac;
    return self;
}

struct Item62d0
{
    Item62d0* next;
    unsigned int key;
    void* val;
};
struct Helper62d0;
struct MapItem62d0;
struct Map62d0
{
    virtual ~Map62d0();
    virtual unsigned int HashFunction(unsigned int);
    virtual bool IsKeysEqual(unsigned int, unsigned int);
    int pad;
    Item62d0** buckets;
    bool FUN_006c62d0(std::uintptr_t key, void** out);
public:
    void FUN_00559120(::MapItem62d0 *&, void *&, ::Helper62d0 &);
};
// @fnv 0x006c0f10
void FUN_006c0f10_shell::UpdateDoorObstacle(TESObjectREFR* apDoorRef)
{
    typedef NiTMapBase<DFALL<NiTMapItem<bhkRigidBody*, NiPointer<ObstacleData> > >, bhkRigidBody*,
                       NiPointer<ObstacleData> >
        DoorMapType;

    TESBoundObject* pbaseObject = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apDoorRef))->FUN_007af430()));
    if (_FNV_GetFormType(pbaseObject) == 0x1c)
    {
        TESObjectDOOR* pdoor = (TESObjectDOOR*)pbaseObject;
        if (!reinterpret_cast<::FUN_00518080_shell *>((pdoor))->FUN_00518080())
        {
            ((Call_006c0c80*)this)->FUN_006c0c80(apDoorRef);
        }
    }

    GlobalObject_00633c90 spdummy(0);
    if (!reinterpret_cast<::Map62d0 *>((void *)(((DoorMapType*)((char*)this + 0x100))))->FUN_006c62d0((std::uintptr_t)(((::bhkRigidBody *)(reinterpret_cast<::FUN_0084e3a0_Class *>((apDoorRef))->FUN_0084e3a0()))), (void **)&(*(NiPointer<ObstacleData>*)&spdummy)))
    {
        Actor* id1 = (Actor*)((::bhkRigidBody *)(reinterpret_cast<::FUN_0084e3a0_Class *>((apDoorRef))->FUN_0084e3a0()));
        if (reinterpret_cast<::RefList *>((((BSSimpleList<Actor*>*)((char*)this + 0xf8))))->FUN_005f65d0((void **)&(id1)))
        {
            bhkRigidBody* id2 = ((::bhkRigidBody *)(reinterpret_cast<::FUN_0084e3a0_Class *>((apDoorRef))->FUN_0084e3a0()));
            reinterpret_cast<::ItemChangeListNode *>((((Call_00905330*)((char*)this + 0xf8))))->FUN_00905330((*(::InventoryStackRecord *const *)(&id2)));
        }
    }

    if (!reinterpret_cast<::Map62d0 *>((void *)(((DoorMapType*)((char*)this + 0x110))))->FUN_006c62d0((std::uintptr_t)(((::bhkRigidBody *)(reinterpret_cast<::FUN_0084e3a0_Class *>((apDoorRef))->FUN_0084e3a0()))), (void **)&(*(NiPointer<ObstacleData>*)&spdummy)))
    {
        if (!reinterpret_cast<::RefList *>((((BSSimpleList<Actor*>*)((char*)this + 0xf0))))->FUN_005f65d0((void **)&(*(Actor**)&apDoorRef)))
        {
            ((BSSimpleList<char const*>*)((char*)this + 0xf0))->AddHead(*(char const**)&apDoorRef);
        }
    }
}
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
// Hashes the key, scans that bucket's chain for a matching key, and if found writes its value to out and returns true.
// @fnv 0x006c62d0
bool Map62d0::FUN_006c62d0(std::uintptr_t key, void** out)
{
    unsigned int uiBucketIndex = HashFunction(key);
    {
        Item62d0* it = buckets[uiBucketIndex];
        while (it)
        {
            if (IsKeysEqual(key, it->key))
            {
                *(Helper62d0*)out = it->val;
                return true;
            }
            it = it->next;
        }
    }
    return false;
}

namespace fnv_006c6c10 {
class NavMeshInfo;
}  // namespace fnv_006c6c10
template <> class BSSimpleArray<fnv_006c6c10::NavMeshInfo*, 1024>
{
  public:
    void FUN_006b3eb0(unsigned int, bool);
};
namespace fnv_006c6c10 {

// Sets the object's first field to the string "0rl" and calls FUN_006b3eb0(0, false) on the array, returning pThis.
// @fnv 0x006c6c10
void* FUN_006c6c10(void* pThis)
{
    *reinterpret_cast<const char**>(pThis) = "0rl";
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(pThis)->FUN_006b3eb0(0, false);
    return pThis;
}
}  // namespace fnv_006c6c10


struct GlobalObject_00869f00
{
    void Clear(bool);
};

// @fnv 0x006c6de0
void FUN_006c6de0(GlobalObject_00869f00* pThis)
{
    *(int**)pThis = &(*reinterpret_cast<int *>((void *)&::s6c7530::DAT_0106c708));
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((pThis))->Clear(true);
}

struct PathingInfo
{
    PathingInfo();
    ~PathingInfo();
    virtual void v0();
    char pad[4];
};
struct FUN_006c6160_cls
{
    FUN_006c6160_cls();
    char pad[4];
};
struct FUN_006c1480_holder : public PathingInfo
{
    int f8;
    FUN_006c6160_cls m;
    FUN_006c1480_holder();
    virtual void v0();
};
// Initializes the holder by setting its f8 field to 0.
// @fnv 0x006c1480
FUN_006c1480_holder::FUN_006c1480_holder()
{
    f8 = 0;
}

namespace fnv_006c3570 {
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3 operator-(const NiPoint3&) const;
};
struct Flt
{
    operator unsigned int() const;
};
// @fnv 0x006c3570
bool FUN_006c3570(NiPoint3* pPoint, Flt* b, float c, float fMaxZ)
{
    NiPoint3 r;
    ::FUN_004b3ae0((::NiPoint3 *)(::fnv_006c3570::NiPoint3 *)(&r), (const ::NiPoint3 &)((const ::fnv_006c3570::NiPoint3 &)(*pPoint - *(NiPoint3*)((unsigned int)*b + 0x10))), (const float*)((unsigned int)*b + 0x1c));
    if (r.z < -c || r.z > fMaxZ)
        return false;
    if (r.x < *(float*)((unsigned int)*b + 0x40) || r.x > *(float*)((unsigned int)*b + 0x4c))
        return false;
    if (r.y < *(float*)((unsigned int)*b + 0x44) || r.y > *(float*)((unsigned int)*b + 0x50))
        return false;
    return true;
}
}  // namespace fnv_006c3570

struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_006c4540_obj
{
    virtual ~FUN_006c4540_obj();
};
// Deletes every object stored in the array at this+0x14c, then clears the containers at this+0x14c and this+0x13c, returning true.
// @fnv 0x006c4540
bool ClearOwnedObjects(char* this_ptr)
{
    unsigned int icount = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)(this_ptr + 0x14c))))->GetName()));
    for (unsigned int t = 0; t < icount; t++)
    {
        delete (FUN_006c4540_obj*)*((Arr*)(this_ptr + 0x14c))->GetAt(t);
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)(this_ptr + 0x14c))))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)(this_ptr + 0x13c))))->Clear(true);
    return true;
}

struct ProcessLists
{
    unsigned char* GetLifeStateControlFlag();
};
struct FUN_006c4ec0_vt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
// @fnv 0x006c4ec0
void ProcessObstacleTasks(NavMeshObstacleManager* pObstacleManager)
{
    void* taskIt;
    taskIt = ((BGSReconstructFormsInAllFilesMap*)((char*)pObstacleManager + 0x12c))->GetFirstPos();
    while (taskIt)
    {
        ObstacleTaskData* ptaskData;
        TESFile* formID;
        reinterpret_cast<::C6b7f20_Map *>((((BGSReconstructFormsInAllFilesMap*)((char*)pObstacleManager + 0x12c))))->FUN_006b7f20((::C6b7f20_Node **)&(taskIt), (unsigned int *)&(formID), (void **)&((BGSReconstructFormsInFileMap*&)ptaskData));
        if (*((ProcessLists*)&g_011d71a0)->GetLifeStateControlFlag())
        {
            pObstacleManager->ProcessObstacleTask(ptaskData);
        }
        else
        {
            reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)((char*)pObstacleManager + 0x160))))->FUN_0040fbf0((char *)(0));
            reinterpret_cast<::FUN_00438690 *>((((BSSimpleArray<void*, 1024>*)((char*)pObstacleManager + 0x13c))))->FUN_007cb2e0((unsigned int *)&((void*&)ptaskData));
            ((RecursiveSpinLock*)((char*)pObstacleManager + 0x160))->FUN_0040fba0();
            ((FUN_006c4ec0_vt*)ptaskData)->v2();
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<unsigned int, unsigned int>*)((char*)pObstacleManager + 0x12c))))->FUN_00438af0();
}

namespace fnv_006c5ef0 {
struct Flt
{
    operator unsigned int() const;
};
struct DummyPointerMap
{
    void SetAt(unsigned int, unsigned int);
    bool GetAt(unsigned int, unsigned int&) const;
};
struct FUN_006c77a0_cls
{
    FUN_006c77a0_cls(Flt*);
    char pad[0x58];
};
struct FUN_006c5ef0_arg
{
    Flt* nav;
};
// @fnv 0x006c5ef0
FUN_006c77a0_cls* FUN_006c5ef0(char* this_ptr, FUN_006c5ef0_arg aNavArg)
{
    FUN_006c77a0_cls* ptask = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)(this_ptr + 0x12c))))->FUN_00853130(*aNavArg.nav, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)ptask)))
    {
        ptask = new FUN_006c77a0_cls(aNavArg.nav);
        reinterpret_cast<::FUN_00844700_Class *>((((DummyPointerMap*)(this_ptr + 0x12c))))->FUN_00844700(*aNavArg.nav, (std::uintptr_t)ptask);
    }
    return ptask;
}
}  // namespace fnv_006c5ef0

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_004ee360(unsigned int flags);
};
// @fnv 0x004ee360
void* DelStandIn::FUN_004ee360(unsigned int flags)
{
    reinterpret_cast<::FUN_004ee840_cls *>((((DtorStandIn*)this)))->::FUN_004ee840_cls::~FUN_004ee840_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct FUN_0042f830_struct
{
};
struct NavMeshArr
{
    virtual void Unused0();
    ~NavMeshArr();
};
namespace FUN_006c6ce0 {
struct FUN_006c6c60 : public NavMeshArr
{
    ~FUN_006c6c60();
};
}

// Destructor that calls FUN_0042f9c0 with argument 1 on this object.
// @fnv 0x006c6ce0
FUN_006c6ce0::FUN_006c6c60::~FUN_006c6c60()
{
    reinterpret_cast<::FUN_0042f9c0_Class *>((((FUN_0042f830_struct*)this)))->FUN_0042f9c0(1);
}

struct GO
{
    int v;
    GO(int);
    ~GO();
};

struct GO2
{
    int v;
    GO2(int);
};

struct B006815c0
{
    int a, b, c;
    B006815c0();
};

struct SA0
{
    int a, b, c, d;
    SA0();
    ~SA0();
};

struct PathingInfoX
{
    virtual ~PathingInfoX();
    int a, b;
    PathingInfoX();
};

struct FUN_006c23c0 : PathingInfoX
{
    GO go1;
    B006815c0 b0;
    B006815c0 b1;
    int pad1[6];
    B006815c0 b2;
    B006815c0 b3;
    B006815c0 b4;
    B006815c0 b5;
    int pad2;
    bool flag;
    SA0 arr;
    GO2 go2;
    FUN_006c23c0();
    virtual ~FUN_006c23c0();
};

// Constructs the object, initialising go1 and go2 to 0 and setting flag to true.
// @fnv 0x006c23c0
FUN_006c23c0::FUN_006c23c0() : go1(0), flag(true), go2(0)
{}

struct FUN_006c4c30_shell : public NavMeshObstacleManager
{
    void FUN_006c4c30();
};

struct ArrBox
{
    unsigned int GetFlags();
    unsigned int* GetAt(int);
};

struct ObstArr
{
    char pad[0xc];
    ArrBox arr;
};

struct SpArr
{
    ObstArr* p;
    SpArr(int);
    ~SpArr();
    operator ObstArr*() const;
};

struct SpObst
{
    void* p;
    SpObst(unsigned int*);
    ~SpObst();
};

struct MapX
{
};

struct MgrX
{
};

extern void* DAT_011d6e2c;

// @fnv 0x00552ba0
void* __cdecl FUN_00552ba0()
{
    return DAT_011d6e2c;
}

extern int DAT_0106c3c4;

struct FUN_006c0150_shell
{
    void FUN_006c0150();
};

// @fnv 0x006c0150
void FUN_006c0150_shell::FUN_006c0150()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_0106c3c4;
}

struct G2
{
    void AddHead(int**);
};

struct FUN_006c1150_shell
{
    void FUN_006c1150(int* apParam);
};

// @fnv 0x006c1150
void FUN_006c1150_shell::FUN_006c1150(int* apParam)
{
    ((G2*)((char*)this + 0x188))->AddHead(&apParam);
}

struct FUN_006c5ff0_cls
{
};

struct FUN_006c1c70_shell
{
    char pad[0x60];
    void FUN_006c1c70(std::intptr_t arg);
};

struct FUN_006c5ff0_shell
{
    void FUN_006c5ff0(void* apArg);
};
// @fnv 0x006c1c70
void FUN_006c1c70_shell::FUN_006c1c70(std::intptr_t arg)
{
    reinterpret_cast<::FUN_006c5ff0_shell *>((((FUN_006c5ff0_cls*)((char*)this + 0x60))))->FUN_006c5ff0(&arg);
}

void FUN_006c5ff0_shell::FUN_006c5ff0(void* apArg)
{}

struct FUN_006c1c90_shell
{
    void ForwardToSubObject(void* apArg);
};

// @fnv 0x006c1c90
void FUN_006c1c90_shell::ForwardToSubObject(void* apArg)
{
    ((FUN_006c5ff0_shell*)((char*)this + 0xa0))->FUN_006c5ff0(&apArg);
}

struct ScriptLocalsX
{
    void FUN_006c1dd0(void* arg);
};

struct FUN_00c9c700_target
{
};

// @fnv 0x006c1dd0
void ScriptLocalsX::FUN_006c1dd0(void* arg)
{
    void* result = ((void *)(::FUN_004ae750((void *)this)));
    if (result)
        reinterpret_cast<::FUN_00c9c700_Class *>((((FUN_00c9c700_target*)result)))->FUN_00c9c700((std::intptr_t)(arg));
}

namespace fnv_006c1e40 {
struct ScriptLocalsX
{
};

struct hkpEntity
{
};

struct FUN_006c1e40_shell
{
    void FUN_006c1e40(void* arg1);
};

// @fnv 0x006c1e40
void FUN_006c1e40_shell::FUN_006c1e40(void* arg1)
{
    void* result = ((void *)(::FUN_004ae750((void *)(((ScriptLocalsX*)this)))));
    if (result)
    {
        reinterpret_cast<::HostC9C6 *>((((hkpEntity*)result)))->FUN_00c9c670(arg1);
    }
}
}  // namespace fnv_006c1e40

namespace fnv_006c1e70 {
struct ScriptLocalsX
{
};

struct FUN_00c9c0f0_shell
{
};

struct FUN_006c1e70_shell
{
    void FUN_006c1e70(std::intptr_t a1);
};

// @fnv 0x006c1e70
void FUN_006c1e70_shell::FUN_006c1e70(std::intptr_t a1)
{
    std::intptr_t result = ::FUN_004ae750((void *)(((ScriptLocalsX*)this)));
    if (result)
    {
        reinterpret_cast<::fnv_00c9c0f0::hkpWorldC9C0 *>((((FUN_00c9c0f0_shell*)result)))->RemoveListener((::fnv_00c9c0f0::hkpListenerC9C0 *)(a1));
    }
}
}  // namespace fnv_006c1e70


struct ObstacleData_shell
{
    void* FUN_006c2490(unsigned int flags);
};

void FUN_006c5e70(int**);

struct FUN_006c5e90_shell
{
    void* FUN_006c5e90(unsigned int flags);
};

// Calls FUN_006c5e70 on this object, deletes it when flags has bit 0 set, and returns this.
// @fnv 0x006c5e90
void* FUN_006c5e90_shell::FUN_006c5e90(unsigned int flags)
{
    FUN_006c5e70((int**)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_006c0120 {
struct FUN_006c0150_shell
{
};


struct FUN_006c0120_shell : FUN_006c0150_shell
{
    void* FUN_006c0120(unsigned int flags);
};

// Calls FUN_006c0150, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x006c0120
void* FUN_006c0120_shell::FUN_006c0120(unsigned int flags)
{
    reinterpret_cast<::FUN_006c0150_shell *>(this)->FUN_006c0150();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_006c0120

namespace fnv_006c0170 {
struct FUN_006c0150_shell
{
    void FUN_006c0170();
};

// @fnv 0x006c0170
void FUN_006c0150_shell::FUN_006c0170()
{
    reinterpret_cast<::FUN_006c0150_shell *>(this)->FUN_006c0150();
}
}  // namespace fnv_006c0170

namespace fnv_006c1d60 {
struct ScriptLocalsX
{
    void FUN_006c1da0(void*);
};

struct FUN_006c1d60_shell
{
    void FUN_006c1d60(ScriptLocalsX* arg);
};

// Calls two methods on arg, passing the pointers stored at this+0x120 and this+0x124.
// @fnv 0x006c1d60
void FUN_006c1d60_shell::FUN_006c1d60(ScriptLocalsX* arg)
{
    reinterpret_cast<::ScriptLocalsX *>((arg))->FUN_006c1dd0(*(void**)(this + 0x120));
    arg->FUN_006c1da0(*(void**)(this + 0x124));
}
}  // namespace fnv_006c1d60

struct hkpEntity;
struct FUN_0061f580_shell
{
    const char* m_p;
    hkpEntity* FUN_0061f580();
};
// @fnv 0x0061f580
hkpEntity* FUN_0061f580_shell::FUN_0061f580()
{
    m_p = "pFU";
    return (hkpEntity*)this;
}

struct NavMeshClosedDoorInfo
{
    NavMeshClosedDoorInfo();
};
struct FUN_006923c0
{
    int f0;
    NavMeshClosedDoorInfo f4;
    FUN_006923c0();
};
// Initializes the object by setting f0 to -1.
// @fnv 0x006923c0
FUN_006923c0::FUN_006923c0()
{
    f0 = -1;
}

struct Dummy
{
    void* FUN_006c00d0(unsigned int);
};
// Calls FUN_006c0170, then if the low bit of flags is set calls _Deallocate on this, and returns this.
// @fnv 0x006c00d0
void* Dummy::FUN_006c00d0(unsigned int flags)
{
    reinterpret_cast<::fnv_006c0170::FUN_006c0150_shell *>(this)->FUN_006c0170();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_006c01d0 {
struct hkpEntity
{
};
struct bhkRigidBody
{
};
struct FUN_006c1c70_shell
{
};
struct bhkObstacleDeactivationListener
{
    void OnEntityDeactivated(hkpEntity*);
};
// @fnv 0x006c01d0
void bhkObstacleDeactivationListener::OnEntityDeactivated(hkpEntity* entity)
{
    bhkRigidBody* pb;
    pb = (bhkRigidBody*)::FUN_004b5a80(entity);
    if (pb)
    {
        reinterpret_cast<::FUN_006c1c70_shell *>((((FUN_006c1c70_shell*)((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager())))))->FUN_006c1c70((std::intptr_t)pb);
    }
}
}  // namespace fnv_006c01d0

struct FUN_006c0210_shell
{
    int* vtbl;
    FUN_006c0210_shell();
    void FUN_0061f580();
};


// @fnv 0x006c0210
FUN_006c0210_shell::FUN_006c0210_shell()
{
    reinterpret_cast<::FUN_0061f580_shell *>(this)->FUN_0061f580();
    vtbl = &DAT_0106c3d4;
}

void FUN_006c0260(void*);
struct FUN_006c0230_shell
{
    void* FUN_006c0230(unsigned int);
};
// @fnv 0x006c0230
void* FUN_006c0230_shell::FUN_006c0230(unsigned int flags)
{
    FUN_006c0260(this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_006c0c30 {
union TSETTING_VALUE;
struct SettingT_GameSettingCollection_
{
    TSETTING_VALUE* Bool();
};
struct Actor;
struct LH
{
    bool IsInList(Actor*&);
};
struct G2
{
    void AddHead(int*);
};
struct Mgr006c0c30
{
    void FUN_006c0c30(Actor*);
};
// If the game setting is enabled and apRef is not already in the list at this+0x2c, adds apRef to the head of that list.
// @fnv 0x006c0c30
void Mgr006c0c30::FUN_006c0c30(Actor* apRef)
{
    if (!*(unsigned char*)(((SettingT_GameSettingCollection_*)&::g_011d73e4)->Bool()))
        return;
    if (!reinterpret_cast<::RefList *>((((LH*)((char*)this + 0x2c))))->FUN_005f65d0((void **)&(apRef)))
        ((G2*)((char*)this + 0x2c))->AddHead((int*)&apRef);
}
}  // namespace fnv_006c0c30

namespace fnv_006c1130 {
struct G2
{
    void AddHead(int**);
};
struct FUN_006c1130_shell
{
    G2 m;
    void FUN_006c1130(int* p);
};
// @fnv 0x006c1130
void FUN_006c1130_shell::FUN_006c1130(int* pItem)
{
    ((G2*)((char*)this + 0x180))->AddHead(&pItem);
}
}  // namespace fnv_006c1130

struct ReferenceObstacleArray
{
    void* DestroyIfFlagged(unsigned int);
};
namespace fnv_006c1da0 {
struct ScriptLocalsX
{
    void FUN_006c1da0(std::intptr_t);
};
struct S_00c9c5b0
{
};
// @fnv 0x006c1da0
void ScriptLocalsX::FUN_006c1da0(std::intptr_t a)
{
    void* p = ((void *)(::FUN_004ae750((void *)this)));
    if (p)
        reinterpret_cast<::FNVOwner *>((((S_00c9c5b0*)p)))->FUN_00c9c5b0(a);
}
}  // namespace fnv_006c1da0

struct S_param
{
};
struct S_this
{
    char _pad[0x120];
    int f120;
    int f124;
    void FUN_006c1e00(S_param*);
};
// @fnv 0x006c1e00
void S_this::FUN_006c1e00(S_param* apParam)
{
    reinterpret_cast<::fnv_006c1e70::FUN_006c1e70_shell *>((apParam))->FUN_006c1e70(f120);
    reinterpret_cast<::fnv_006c1e40::FUN_006c1e40_shell *>((apParam))->FUN_006c1e40((void *)(f124));
}

struct C006c6fe0
{
};
struct C00449f80
{
    C006c6fe0* FUN_00449f80(void*);
};
struct C006c6030
{
    bool FUN_006c6030(void*);
};
// Locks the object at offset 0x20, calls FUN_00449f80 on a1 and FUN_006c6fe0 on the result, unlocks, and returns that bool.
// @fnv 0x006c6030
bool C006c6030::FUN_006c6030(void* apArg)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)((char*)this + 0x20))))->FUN_0040fbf0((char *)(0));
    bool b = reinterpret_cast<::QueueConsumer *>((((C00449f80*)this)->FUN_00449f80(apArg)))->FUN_006c6fe0({});
    ((RecursiveSpinLock*)((char*)this + 0x20))->FUN_0040fba0();
    return b;
}

namespace fnv_006c0260 {
struct FUN_00554650_shell
{
};
struct FUN_006c0260_shell
{
    void FUN_006c0260();
};
// @fnv 0x006c0260
void FUN_006c0260_shell::FUN_006c0260()
{
    *(void**)this = &(*reinterpret_cast<void * *>(&::DAT_0106c3d4));
    reinterpret_cast<::FUN_00554650_Class *>((((FUN_00554650_shell*)this)))->FUN_00554650();
}
}  // namespace fnv_006c0260

namespace fnv_006c1ea0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct TES
{
};
class TESWorldSpace
{
  public:
};
class DoorCell
{
  public:
};
struct Flt
{
    operator unsigned int();
};
struct NiPoint3Ex
{
    float x;
    float y;
    float z;
    NiPoint3Ex(float, float, float);
};

// @fnv 0x006c1ea0
bool __cdecl CollectCellsNearObstacle(Flt& kObstacle, BSSimpleArray<void*, 1024>* pCells)
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)pCells)))->Clear(false);
    TESObjectCELL* pCell = ((::TESObjectCELL *)(reinterpret_cast<::fnv_00457070::FUN_00457070_shell *>((((::fnv_006c1ea0::TES *)::g_TES)))->FUN_00457070()));
    if (!pCell)
        return false;
    if (reinterpret_cast<::TESObjectCELL *>((pCell))->IsCellInterior())
    {
        reinterpret_cast<::FUN_00438690 *>((pCells))->FUN_007cb2e0((unsigned int *)&(reinterpret_cast<void*&>(pCell)));
    }
    else
    {
        int m_iGridPositionX = (int)*(float*)((unsigned int)kObstacle + 0x10) >> 12;
        int m_iGridCoordinateY = (int)*(float*)((unsigned int)kObstacle + 0x14) >> 12;
        for (int x = m_iGridPositionX - 1; x <= m_iGridPositionX + 1; x++)
        {
            for (int y = m_iGridCoordinateY - 1; y <= m_iGridCoordinateY + 1; y++)
            {
                TESObjectCELL* pAdjCell = reinterpret_cast<::TESWorldSpace *>((((::fnv_006c1ea0::TESWorldSpace *)(reinterpret_cast<::TESObjectCELL *>((((DoorCell*)pCell)))->GetParentWorldSpace()))))->GetCellAtGridPosition(x, y);
                if (pAdjCell && ::FUN_00450ff0((void *)(pAdjCell)))
                {
                    NiPoint3Ex kMinBoundsCur((float)(x << 12), (float)(y << 12), ::DAT_01015f5c);
                    NiPoint3Ex kMaxPoint((float)(kMinBoundsCur.x + 4096.0), (float)(kMinBoundsCur.y + 4096.0), 3.402823466e+38F);
                    if (::DoBoundsOverlap((const ::NiPoint3 *)&(*(NiPoint3*)&kMinBoundsCur), (const ::NiPoint3 *)&(*(NiPoint3*)&kMaxPoint),
                                        (const ::NiPoint3 *)&(*(NiPoint3*)((unsigned int)kObstacle + 0x58)),
                                        (const ::NiPoint3 *)&(*(NiPoint3*)((unsigned int)kObstacle + 0x64))))
                        reinterpret_cast<::FUN_00438690 *>((pCells))->FUN_007cb2e0((unsigned int *)&(reinterpret_cast<void*&>(pAdjCell)));
                }
            }
        }
    }
    return true;
}
}  // namespace fnv_006c1ea0

namespace fnv_006c2050 {
struct Flt
{
    void* p;
    operator unsigned int();
};
struct NavMeshPtr : Flt
{
    ~NavMeshPtr();
};
struct S2f850
{
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct EffectSetting
{
};
struct FUN_006969e0_shell
{
};
struct NMA
{
    NavMeshPtr GetNavMeshAt(unsigned int);
};
struct P3Ctor
{
};
struct CellArr
{
    CellArr(unsigned int, unsigned int, unsigned int);
    ~CellArr();
    void* a;
    void* b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
};
bool __cdecl CollectCellsNearObstacle(const Flt*, CellArr*);

// @fnv 0x006c2050
bool FUN_006c2050(const Flt* apData, S2f850* apReturnNavMeshArray)
{
    NiPoint3 navmeshMin;
    (void *)(((P3Ctor*)&navmeshMin));
    NiPoint3 navmeshMax;
    (void *)(((P3Ctor*)&navmeshMax));
    CellArr cells(0x20, 0, 0);
    if (CollectCellsNearObstacle(apData, &cells))
    {
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&cells)))->GetName())); i++)
        {
            NMA* parray = (NMA*)((int)(::FUN_0070ec90((char *)(((EffectSetting*)*((Arr*)&cells)->GetAt(i))))));
            if (parray)
            {
                for (unsigned int j = 0; j < (unsigned int)((int)(reinterpret_cast<::FUN_00620b80_shell *>((parray))->GetReferenceFlags())); j++)
                {
                    if (reinterpret_cast<::FUN_006969e0_shell *>((((FUN_006969e0_shell*)(unsigned int)parray->GetNavMeshAt(j))))->FUN_006969e0(&navmeshMin, &navmeshMax))
                    {
                        navmeshMax.z += 128.0;
                        if (::DoBoundsOverlap((const ::NiPoint3 *)&(navmeshMin), (const ::NiPoint3 *)&(navmeshMax), (const ::NiPoint3 *)&(*(NiPoint3*)((unsigned int)*(Flt*)apData + 0x58)),
                                            (const ::NiPoint3 *)&(*(NiPoint3*)((unsigned int)*(Flt*)apData + 0x64))))
                        {
                            reinterpret_cast<::S2f850 *>((apReturnNavMeshArray))->AppendValue((const ::NavMeshPtr &)((const ::fnv_006c2050::NavMeshPtr &)(parray->GetNavMeshAt(j))));
                        }
                    }
                }
            }
        }
    }
    return true;
}
}  // namespace fnv_006c2050

namespace fnv_006c2210 {
class NiAVObject;
struct NavMeshPtr
{
    void* m_pObject;
};
struct Flt : NavMeshPtr
{
    operator unsigned int();
};
struct GO : Flt
{
    GO(int);
    ~GO();
    void operator=(void*);
};
struct bhkFilter
{
    bhkFilter();
    unsigned int uiFilterInfo;
};
struct bhkWorldObject
{
    bhkFilter FUN_0043b4f0();
};
struct bhkCollisionObject
{
};
struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int);
};
struct Obj_006c2210
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NiNode* IsSceneNode();
};
struct BSFadeNode
{
};
struct FUN_006c23c0 : BSFadeNode
{
    FUN_006c23c0();
    char pad[0x8c];
};
struct Obstacle_006c2210
{
    char pad[8];
    unsigned int uiOwner;
    GO m_pGameObject;
};
struct S2f850
{
};
struct Owner_006c2210
{
    char pad[0xc];
    S2f850 kArray;
};

// @fnv 0x006c2210
bool __cdecl RegisterCollisionObstacles(NiAVObject* apObject, Flt* apOwner)
{
    NiNode* pkNode;
    {
        bhkCollisionObject* pCollision = ((::fnv_006c2210::bhkCollisionObject *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(apObject))));
        if (pCollision)
        {
            bhkWorldObject* pWorldObject = ((::fnv_006c2210::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(pCollision))));
            if (pWorldObject)
            {
                int iLayer = reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::fnv_006c2210::bhkFilter &)(pWorldObject->FUN_0043b4f0()))->FUN_0043b4d0();
                if (iLayer == 2 || iLayer == 4 || iLayer == 10 || iLayer == 0x14 || iLayer == 0x1c)
                {
                    GO m_spRegisteredObstacle((int)new FUN_006c23c0);
                    ((Obstacle_006c2210*)(unsigned int)m_spRegisteredObstacle)->uiOwner = (unsigned int)*apOwner;
                    ((Obstacle_006c2210*)(unsigned int)m_spRegisteredObstacle)->m_pGameObject = pWorldObject;
                    ::ObstacleBounds::UpdateObstacleBounds((::ObstacleBounds::Obstacle *)((unsigned int)m_spRegisteredObstacle));
                    reinterpret_cast<::S2f850 *>(&(((Owner_006c2210*)(unsigned int)*apOwner)->kArray))->FUN_006c61b0((const ::NavMeshPtr &)(m_spRegisteredObstacle));
                }
            }
        }
    }
    pkNode = ((Obj_006c2210*)apObject)->IsSceneNode();
    if (pkNode)
    {
        for (unsigned int i = 0; i < pkNode->GetNumChildren(); i++)
        {
            if (((::fnv_006c2210::NiAVObject *)(reinterpret_cast<::NiNode *>((pkNode))->GetAt(i))))
                RegisterCollisionObstacles(((::fnv_006c2210::NiAVObject *)(reinterpret_cast<::NiNode *>((pkNode))->GetAt(i))), apOwner);
        }
    }
    return true;
}
}  // namespace fnv_006c2210

namespace fnv_006c47e0 {
struct FUN_006c47e0_shell : public NavMeshObstacleManager
{
    void FUN_006c47e0();
};

class BSTempEffect;
struct UList;
bool _ref_008256d0(UList*);
struct GridArray
{
};
struct GO
{
    void* p;
    GO(int);
    ~GO();
};
struct FGModelMap
{
    bool GetAt(void*, GO&);
};
struct Flt
{
    operator unsigned int();
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct List_009e03e0
{
    void RemoveAll();
};
// @fnv 0x006c47e0
void FUN_006c47e0_shell::FUN_006c47e0()
{
    UList* pNode = (UList*)((char*)this + 0x34);
    while (pNode && !_ref_008256d0(pNode))
    {
        unsigned int prefID = *((unsigned int *)((void *)(pNode)));
        pNode = (UList*)((reinterpret_cast<::Callees *>((void *)(((GridArray*)pNode)))->FUN_00726070()));
        GO spArray(0);
        if (reinterpret_cast<::Map62d0 *>((((FGModelMap*)((char*)this + 0x1c))))->FUN_006c62d0((std::uintptr_t)((void*)prefID), (void **)&(spArray)))
        {
            for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((unsigned int)*(Flt*)&spArray + 0xc))))->GetName())); i++)
                reinterpret_cast<::ListReader *>((((BSSimpleList<NiPointer<BSTempEffect> >*)((char*)this + 0x3c))))->FUN_00631620((const ::NodeValue &)(*(NiPointer<BSTempEffect>*)((Arr*)((unsigned int)*(Flt*)&spArray + 0xc))->GetAt(i)));
        }
        RemoveObstaclesForReference(prefID);
    }
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)((char*)this + 0x34))))->RemoveAll();
}
}  // namespace fnv_006c47e0

namespace fnv_006c4fb0 {
struct FUN_006c4fb0_shell : public NavMeshObstacleManager
{
    bool ProcessDoorObstacles();
};

struct UNode;
bool _ref_008256d0(void*);
struct GO
{
    GO(int);
    ~GO();
    void* p;
};
struct Flt
{
    operator unsigned int();
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct FGModelMap
{
    bool GetAt(void*, GO&);
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
struct SpObst
{
    SpObst(unsigned int*);
    SpObst(const SpObst&);
    ~SpObst();
    void* p;
};
struct Map6920
{
};
struct List_009e03e0
{
    void RemoveAll();
};
struct ObstacleTaskData_Op : ObstacleTaskData
{
};
struct FUN_006c5ef0_shell
{
};

// Iterates the node list at this+0xf8, adds operations for each door found in the map at this+0x110, removes those entries, then clears the list and returns true.
// @fnv 0x006c4fb0
bool FUN_006c4fb0_shell::ProcessDoorObstacles()
{
    UNode* pCurrentElementNext;
    if (_ref_008256d0((char*)this + 0xf8))
        return false;
    pCurrentElementNext = (UNode*)((char*)this + 0xf8);
    while (pCurrentElementNext)
    {
        unsigned int doorId = *((unsigned int *)((void *)(pCurrentElementNext)));
        pCurrentElementNext = ((::fnv_006c4fb0::UNode *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        GO spArray(0);
        if (reinterpret_cast<::Map62d0 *>((((FGModelMap*)((char*)this + 0x110))))->FUN_006c62d0((std::uintptr_t)((void*)doorId), (void **)&(spArray)))
        {
            unsigned int i;
            for (i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((unsigned int)*(Flt*)&spArray + 0xc))))->GetName())); i++)
            {
                unsigned int j;
                for (j = 0;
                     j < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((unsigned int)*(Flt*)((Arr*)((unsigned int)*(Flt*)&spArray + 0xc))->GetAt(i) + 0x78))))->GetName()));
                     j++)
                {
                    reinterpret_cast<::ObstacleTaskData *>((((::fnv_006c4fb0::ObstacleTaskData_Op *)(::fnv_006c5ef0::FUN_006c5ef0((char *)(((FUN_006c5ef0_shell*)this)), 
                            ::fnv_006c5ef0::FUN_006c5ef0_arg{(::fnv_006c5ef0::Flt *)(*((Arr*)((unsigned int)*(Flt*)((Arr*)((unsigned int)*(Flt*)&spArray + 0xc))->GetAt(i) +
                                     0x78))
                                 ->GetAt(j))})))))->AddOperation((const ::NiPointer< ::ObstacleData> &)(*((Arr*)((unsigned int)*(Flt*)&spArray + 0xc))->GetAt(i)), (::OBSTACLE_TASK_TYPE)(0x40));
                }
            }
            reinterpret_cast<::NiTMap_S *>((((MapH*)((char*)this + 0x110))))->RemoveKey(doorId);
            reinterpret_cast<::Map6920 *>((((Map6920*)((char*)this + 0x100))))->FUN_006c6920(doorId, (*(::NiPointer< ::NiAVObject> *)&(const ::fnv_006c4fb0::SpObst &)((unsigned int*)&spArray)));
        }
    }
    reinterpret_cast<::FileMatchList *>((((List_009e03e0*)((char*)this + 0xf8))))->RemoveAll();
    return true;
}
}  // namespace fnv_006c4fb0

namespace fnv_006c5ce0 {
struct BSTaskletData;
struct FUN_006c5ce0_shell : public NavMeshObstacleManager
{
    bool FUN_006c5ce0(ObstacleTaskData*);
};

namespace FUN_006c5e40 {
struct FUN_006c5e70
{
    unsigned int data[2];
    FUN_006c5e70();
    ~FUN_006c5e70();
};
}
struct TESRaceForm
{
};
struct LS3de0
{
    unsigned int Find(unsigned int&, unsigned int, bool (*)(const int*, const int*));
};
struct GlobalObject_00869f00
{
    void Remove(unsigned int, bool);
};
struct FUN_006c5ec0_s
{
    bool FUN_006c5ec0(FUN_006c5e40::FUN_006c5e70&, int);
};
// @fnv 0x006c5ce0
bool FUN_006c5ce0_shell::FUN_006c5ce0(ObstacleTaskData* apTaskData)
{
    FUN_006c5e40::FUN_006c5e70 task;
    reinterpret_cast<::CombatProcedure *>((reinterpret_cast<TESRaceForm*>(&task)))->Initialize((::CombatController *)(apTaskData));
    reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)((char*)this + 0x160))))->FUN_0040fbf0((char *)(0));
    reinterpret_cast<::FUN_00438690 *>((((BSSimpleArray<void*, 1024>*)((char*)this + 0x13c))))->FUN_007cb2e0((unsigned int *)&((void*&)apTaskData));
    ((RecursiveSpinLock*)((char*)this + 0x160))->FUN_0040fba0();
    const unsigned int iMaxAttachTaskAttempts = 100;
    unsigned int itryCount = 0;
    while (!((FUN_006c5ec0_s*)((char*)this + 0x128))->FUN_006c5ec0(task, 0))
    {
        itryCount++;
        if (itryCount >= iMaxAttachTaskAttempts)
        {
            reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)((char*)this + 0x160))))->FUN_0040fbf0((char *)(0));
            unsigned int iremoveIndex =
                ((LS3de0*)((char*)this + 0x13c))->Find((unsigned int&)apTaskData, 0, ::FUN_009a3830);
            if (iremoveIndex != -1)
                reinterpret_cast<::FUN_006bf8f0_Class *>((((GlobalObject_00869f00*)((char*)this + 0x13c))))->FUN_006bf8f0(iremoveIndex, true);
            ((RecursiveSpinLock*)((char*)this + 0x160))->FUN_0040fba0();
            return false;
        }
        ::FUN_0040fca0(0);
    }
    return true;
}
}  // namespace fnv_006c5ce0

namespace fnv_006c39c0 {
struct FUN_006c39c0_shell : public NavMeshObstacleManager
{
    void FUN_006c39c0();
};

struct ATM
{
};
struct PathManager
{
};
struct FUN_006ebc70_shell
{
};
struct FUN_006ebc90_shell
{
};
struct ScriptLocals
{
};
struct CellX
{
};
struct NMOM
{
    void MatchPortalEdges();
    void ProcessAddedRefs();
    void FUN_006c4d30();
    void FUN_006c5190();
};
struct FUN_006c4c30_shell
{
};

// Waits for processed and background task counts to match, runs path manager and navmesh update steps, resets offset 0x190/0x194, and waits for rendering tasks.
// @fnv 0x006c39c0
void FUN_006c39c0_shell::FUN_006c39c0()
{
    unsigned int iProcessedTaskCount;
    unsigned int iBackgroundTaskCount;
    reinterpret_cast<::GlobalObject_0044fae0 *>((((ATM*)this)))->FUN_004538a0((int)("NavMeshObstacleManager::ForceUpdate()"));
    iProcessedTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetProcessedTaskCount();
    iBackgroundTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetBackgroundTaskCount();
    while (iProcessedTaskCount != iBackgroundTaskCount)
    {
        ::FUN_0040fca0(0);
        iProcessedTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetProcessedTaskCount();
        iBackgroundTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetBackgroundTaskCount();
    }
    reinterpret_cast<::FUN_006ebc70_shell *>((((FUN_006ebc70_shell*)((::fnv_006c39c0::PathManager *)(::GetPathManager())))))->FUN_006ebc70();
    while (!reinterpret_cast<::FUN_006ebc90_shell *>((((FUN_006ebc90_shell*)((::fnv_006c39c0::PathManager *)(::GetPathManager())))))->FUN_006ebc90())
        reinterpret_cast<::ScriptLocals *>((((ScriptLocals*)((::fnv_006c39c0::PathManager *)(::GetPathManager())))))->ProcessPendingTasks();
    ((NMOM*)this)->MatchPortalEdges();
    reinterpret_cast<::fnv_006c44d0::FUN_006c44d0_shell *>((((NMOM*)this)))->FUN_006c44d0();
    ::ClearOwnedObjects((char*)this);
    ::ProcessObstacleTasks((::NavMeshObstacleManager *)(((NMOM*)this)));
    iProcessedTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetProcessedTaskCount();
    iBackgroundTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetBackgroundTaskCount();
    while (iProcessedTaskCount != iBackgroundTaskCount)
    {
        ::FUN_0040fca0(0);
        iProcessedTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetProcessedTaskCount();
        iBackgroundTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetBackgroundTaskCount();
    }
    ((NMOM*)this)->MatchPortalEdges();
    reinterpret_cast<::fnv_006c44d0::FUN_006c44d0_shell *>((((NMOM*)this)))->FUN_006c44d0();
    ::ClearOwnedObjects((char*)this);
    reinterpret_cast<::fnv_006c47e0::FUN_006c47e0_shell *>((((NMOM*)this)))->FUN_006c47e0();
    ((NMOM*)this)->ProcessAddedRefs();
    reinterpret_cast<::FUN_006c4c30_shell *>((((FUN_006c4c30_shell*)this)))->FUN_006c4c30();
    ((NMOM*)this)->FUN_006c4d30();
    reinterpret_cast<::fnv_006c4fb0::FUN_006c4fb0_shell *>((((NMOM*)this)))->ProcessDoorObstacles();
    ((NMOM*)this)->FUN_006c5190();
    ::ProcessObstacleTasks((::NavMeshObstacleManager *)(((NMOM*)this)));
    iProcessedTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetProcessedTaskCount();
    iBackgroundTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetBackgroundTaskCount();
    while (iProcessedTaskCount != iBackgroundTaskCount)
    {
        ::FUN_0040fca0(0);
        iProcessedTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetProcessedTaskCount();
        iBackgroundTaskCount = reinterpret_cast<::NavMeshObstacleManager *>((((NMOM*)this)))->GetBackgroundTaskCount();
    }
    ((NMOM*)this)->MatchPortalEdges();
    reinterpret_cast<::fnv_006c44d0::FUN_006c44d0_shell *>((((NMOM*)this)))->FUN_006c44d0();
    ::ClearOwnedObjects((char*)this);
    *(int*)((char*)this + 0x190) = 0;
    *(float*)((char*)this + 0x194) = (*reinterpret_cast<float *>(&::fnv_006c3640::DAT_0106c398));
    if (reinterpret_cast<::TESObjectCELL *>((((::fnv_006c39c0::CellX *)(::FUN_00552ba0()))))->FUN_00552bb0())
        reinterpret_cast<::fnv_006a5ca0::PaddedBooleanState *>((((::fnv_006c39c0::CellX *)(::FUN_00552ba0()))))->FUN_006a5ca0();
    reinterpret_cast<::FUN_006ebcd0_shell *>((((::fnv_006c39c0::PathManager *)(::GetPathManager()))))->FUN_006ebcd0();
    reinterpret_cast<::ActorTaskManager *>((((ATM*)this)))->WaitForTasksDuringRendering();
}
}  // namespace fnv_006c39c0

namespace fnv_006c45e0 {
struct Actor;
struct ActorCause;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSEncounterZone;
struct ExplosionForm;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct SoundPlaybackHandle;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct GameFormRecord;
struct TeleportableReference;
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
struct NiPoint3;
struct NiPointLight;
struct PlacedObjectInfo;
struct IndexedPointerCollection;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceIntersectionData;
struct RagDollData;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESModel;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectLIGH;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESSound;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct WaterZone;
struct bhkNiCollisionObject;
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
struct FUN_006c45e0_shell : public NavMeshObstacleManager
{
    void ProcessAddedRefs();
};

namespace FUN_005e04c0 {
struct FUN_005e04f0
{
    unsigned int unk00;
    void* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    FUN_005e04f0();
    ~FUN_005e04f0();
};
}
struct GO
{
    void* p;
    GO(int);
    ~GO();
};
struct Flt
{
    operator unsigned int();
};
namespace FUN_006c23c0 {
struct FUN_006c24d0
{
    unsigned int unk00, unk04, unk08;
    Flt form;
    unsigned int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44,
        unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80, unk84,
        unk88;
    FUN_006c24d0();
    ~FUN_006c24d0();
};
}
struct FUN_008256d0_s
{
    bool FUN_008256d0();
};
struct FUN_006815c0_s
{
};
struct Map62d0
{
};
struct FUN_006c1920_s
{
    void RebuildRefObstacles(unsigned int, TESObjectREFR*);
};
struct FUN_006c1190_s
{
    void RegisterKey(TESObjectREFR*);
};
struct FUN_00905330_s
{
};
struct ListStand
{
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct RefStand
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
    virtual void* GetData();
};
struct FormStand
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
    virtual int IsQuestItem();
};
struct FormIDView_006c45e0
{
};
// @fnv 0x006c45e0
void FUN_006c45e0_shell::ProcessAddedRefs()
{
    FUN_005e04c0::FUN_005e04f0 addedRefs;
    ListStand* pCurrentElementNext = (ListStand*)((char*)this + 0x2c);
    while (pCurrentElementNext && !((FUN_008256d0_s*)pCurrentElementNext)->FUN_008256d0())
    {
        TESObjectREFR* pref = *((::fnv_006c45e0::TESObjectREFR **)((void *)(((FUN_006815c0_s*)pCurrentElementNext))));
        pCurrentElementNext = ((::fnv_006c45e0::ListStand *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        GO spArray(0);
        if (reinterpret_cast<::Map62d0 *>((((Map62d0*)((char*)this + 0x1c))))->FUN_006c62d0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((FormIDView_006c45e0*)pref)))->FUN_0084e3a0())), (void **)&(spArray)))
        {
            ((FUN_006c1920_s*)this)->RebuildRefObstacles(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((FormIDView_006c45e0*)pref)))->FUN_0084e3a0())), pref);
            reinterpret_cast<::FUN_00438690 *>((((BSSimpleArray<void*, 1024>*)&addedRefs)))->FUN_007cb2e0((unsigned int *)&((void*&)pref));
        }
        else if (((RefStand*)pref)->GetData())
        {
            FUN_006c23c0::FUN_006c24d0 refData;
            if (::FindNodeData((::FNVNode *)(void *)(((RefStand*)pref)->GetData()), (::FNVResult *)(::fnv_006c45e0::FUN_006c23c0::FUN_006c24d0 *)(&refData)))
            {
                if (((FormStand*)(unsigned int)refData.form)->IsQuestItem())
                {
                    ((FUN_006c1190_s*)this)->RegisterKey(pref);
                    reinterpret_cast<::FUN_00438690 *>((((BSSimpleArray<void*, 1024>*)&addedRefs)))->FUN_007cb2e0((unsigned int *)&((void*&)pref));
                }
            }
        }
    }
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&addedRefs)))->GetName())); i++)
        reinterpret_cast<::ItemChangeListNode *>((((FUN_00905330_s*)((char*)this + 0x2c))))->FUN_00905330((*(::InventoryStackRecord *const *)(((Arr*)&addedRefs)->GetAt(i))));
}
}  // namespace fnv_006c45e0

class Tile;
class Flt
{
  public:
    operator unsigned int();
};
class TL : public Flt
{
  public:
    Tile*& GetNext(void*& pos);
};
class Tile
{
  public:
    int m_iWordAt00;
    TL m_kList;
    void Set(int id, int value);
    const char* FUN_00700300();
};
struct NiPoint2
{
    float x, y;
    NiPoint2(float fx, float fy);
};
class SoundPlaybackHandle
{
  public:
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    ~SoundPlaybackHandle();
};
class BSAudio
{
  public:
    SoundPlaybackHandle GetSoundHandleByEditorID(const char* name, unsigned int flags);
};
extern const double DAT_01074f60;

struct FUN_00799dc0_class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    Tile* m_pTile40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    Tile* m_pTile54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    Tile* m_pMapTile;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    Tile* m_pHighlighted;
    void UpdateMapHighlight();
};

// Finds the nearest map marker tile to the cursor within range, marks it highlighted, plays a sound and updates the title and highlight state.
// @fnv 0x00799dc0
void FUN_00799dc0_class::UpdateMapHighlight()
{
    if (!m_pMapTile)
        return;
    NiPoint2 kCursor(reinterpret_cast<::TileListBoxCalls *>((m_pTile40))->GetFloat(0xfa1) + reinterpret_cast<::TileListBoxCalls *>((m_pTile40))->GetFloat(0xfb1) / 2.0,
                     reinterpret_cast<::TileListBoxCalls *>((m_pTile40))->GetFloat(0xfa2) + reinterpret_cast<::TileListBoxCalls *>((m_pTile40))->GetFloat(0xfb0) / 2.0);
    Tile* pBest;
    {
        void* pos = (void*)(unsigned int)m_pMapTile->m_kList;
        float fClosest = 3.402823466e+38F;
        pBest = 0;
        kCursor.x -= reinterpret_cast<::TileListBoxCalls *>((m_pMapTile))->GetFloat(0xfa1);
        kCursor.y -= reinterpret_cast<::TileListBoxCalls *>((m_pMapTile))->GetFloat(0xfa2);
        while (pos)
        {
            Tile* pTile = ((::Tile *)(reinterpret_cast<::ListStandIn *>(&(m_pMapTile->m_kList))->FUN_0057cbe0((int **)&(pos))));
            if (reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfaa) == DAT_01074f60 && !((const char *)(std::strstr((char *)(pTile->FUN_00700300()), " Marker"))))
            {
                NiPoint2 kPos(reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(DAT_011da350), reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(DAT_011da34c));
                float fDist = 0.0f;
                reinterpret_cast<::FUN_006ad180_Cls *>(&(kPos))->Scale(reinterpret_cast<::TileListBoxCalls *>((m_pMapTile))->GetFloat(0xfb1));
                fDist = reinterpret_cast<::FUN_00589850_Class *>((void *)(void *)&(const ::NiPoint2 &)((*(::NiPoint2 *)(reinterpret_cast<::fnv_anon_tile::NiPoint2_Sub *>((void *)&(kCursor))->Subtract((::NiPoint2 *)&(kPos), *(const ::NiPoint2 *)nullptr)))))->FUN_00589850();
                if (fDist < fClosest && reinterpret_cast<::TileListBoxCalls *>((m_pTile40))->GetFloat(0xfb0) / 2.0 > fDist)
                {
                    fClosest = fDist;
                    pBest = pTile;
                }
                pTile->Set(DAT_011da348, 0);
            }
        }
    }
    if (pBest)
    {
        pBest->Set(DAT_011da348, 1);
        if (pBest != m_pHighlighted)
        {
            reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SoundPlaybackHandle &)(::FUN_00453a70()->GetSoundHandleByEditorID("UIPipBoyHighlight", 0x121)))->FUN_00ad8830(false);
            if (fnv::crt::stricmp(reinterpret_cast<::FUN_00a011f0_shell *>((pBest))->FUN_00a011f0(::FUN_00a00940("_LocationName", -1)), "Companion"))
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTile40))->FUN_00a01350(::FUN_00a00940("_Title", -1), (char *)(reinterpret_cast<::FUN_00a011f0_shell *>((pBest))->FUN_00a011f0(::FUN_00a00940("_LocationName", -1))),
                               true);
            m_pHighlighted = pBest;
            m_pTile54->Set(0xfaf, reinterpret_cast<::FUN_00a01230_shell *>((pBest))->IsTraitNonZero(0x1004));
        }
    }
    else
    {
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTile40))->FUN_00a01350(::FUN_00a00940("_Title", -1), (char *)(""), true);
        m_pHighlighted = 0;
        m_pTile54->Set(0xfaf, 0);
    }
}

namespace fnv_00807790 {
struct FUN_006234b0
{
    FUN_006234b0();
    ~FUN_006234b0();
    virtual void v0();
};
struct FUN_0061f580
{
    FUN_0061f580();
    ~FUN_0061f580();
    virtual void v0();
};
struct FUN_006c0100
{
    FUN_006c0100();
    ~FUN_006c0100();
    virtual void v0();
};
struct CF845
{
    unsigned int uiFlags;
    CF845(int i);
};
struct ScriptLocalsX
{
};
struct FUN_00807790 : public FUN_006234b0, public FUN_0061f580, public FUN_006c0100
{
    int m_0c;
    ScriptLocalsX* m_10;
    CF845 m_kFlags;
    bool m_18;
    FUN_00807790(int a1, ScriptLocalsX* a2, unsigned int a3);
};

// @fnv 0x00807790
FUN_00807790::FUN_00807790(int a1, ScriptLocalsX* a2, unsigned int auiFlags) : m_kFlags(0)
{
    m_0c = a1;
    m_10 = a2;
    m_kFlags.uiFlags = auiFlags;
    m_18 = false;
    reinterpret_cast<::FUN_008078b0_Class *>((m_10))->FUN_008078b0(this);
    reinterpret_cast<::fnv_006c1da0::ScriptLocalsX *>((m_10))->FUN_006c1da0((std::intptr_t)(static_cast<FUN_0061f580*>(this)));
    reinterpret_cast<::ScriptLocalsX *>((m_10))->FUN_006c1dd0(static_cast<FUN_006c0100*>(this));
}
}  // namespace fnv_00807790

namespace fnv_006c1cb0 {
struct bhkRigidBody;
struct TESObjectREFR;

struct GO
{
    unsigned int value;

    GO(int);
    ~GO();
    operator unsigned int() const;
};

struct FGModelMap
{
    bool GetAt(void*, GO&);
};

struct ReferenceObstacleArray
{
    unsigned int pad0;
    unsigned int pad1;
    unsigned int formID;
};

struct ObstacleData
{
    unsigned int pad0;
    unsigned int pad1;
    ReferenceObstacleArray* m_pReferenceObstacleArray;
};

struct Call_006c0c80
{
    void FUN_006c0c80(TESObjectREFR*);
    void HandleRigidBodyObstacle(bhkRigidBody*);
};

extern unsigned int _data_011c16bc;


GO::GO(int)
{}

GO::~GO()
{}

GO::operator unsigned int() const
{
    return 0;
}

bool FGModelMap::GetAt(void*, GO&)
{
    return false;
}

void Call_006c0c80::FUN_006c0c80(TESObjectREFR*)
{}

// Looks up the rigid body in the model map at offset 0xe0, resolves the referenced form by its formID and passes it to FUN_006c0c80 if found.
// @fnv 0x006c1cb0
void Call_006c0c80::HandleRigidBodyObstacle(bhkRigidBody* apRigidBody)
{
    TESObjectREFR* pref;
    GO go(0);

    if (reinterpret_cast<::Map62d0 *>((reinterpret_cast<FGModelMap*>(reinterpret_cast<char*>(this) + 0xe0)))->FUN_006c62d0((std::uintptr_t)(apRigidBody), (void **)&(go)))
    {
        pref = ((::fnv_006c1cb0::TESObjectREFR *)(::FUN_004839c0(
            reinterpret_cast<ObstacleData*>(static_cast<unsigned int>(go))->m_pReferenceObstacleArray->formID)));

        if (pref)
            this->FUN_006c0c80(pref);
    }
}
}  // namespace fnv_006c1cb0

extern int DAT_0106c3c4;

struct FUN_006c0100_t
{
    int v;
    void* FUN_006c0100();
};

// @fnv 0x006c0100
void* FUN_006c0100_t::FUN_006c0100()
{
    v = (int)&DAT_0106c3c4;
    return this;
}

class TargetObj
{
  public:
};


class FUN_006c0280_cls
{
  public:
    void CallResolvedObject(std::intptr_t id);
};

// Looks up an object by id; if found, resolves it and calls UnkCall on the result.
// @fnv 0x006c0280
void FUN_006c0280_cls::CallResolvedObject(std::intptr_t id)
{
    void* obj = ::FUN_004b5a80((const void *)(id));
    if (obj != 0)
    {
        reinterpret_cast<::fnv_006c1cb0::Call_006c0c80 *>((((::TargetObj *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->HandleRigidBodyObstacle({});
    }
}

struct S_006c0900_release
{
    virtual int Release(bool);
};

struct S_006c0900
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    S_006c0900_release* unk120;
    S_006c0900_release* unk124;
    int unk128;

    void FUN_006c0900();
};

void FUN_006c09f0(void* pThis);
void FUN_006c09d0(void* pThis);

// @fnv 0x006c0900
void S_006c0900::FUN_006c0900()
{
    FUN_006c09f0(this);

    if (this->unk120)
    {
        S_006c0900_release* a = this->unk120;
        S_006c0900_release* p = a;
        p ? p->Release(true) : 0;
        this->unk120 = 0;
    }

    if (this->unk124)
    {
        S_006c0900_release* b = this->unk124;
        S_006c0900_release* q = b;
        q ? q->Release(true) : 0;
        this->unk124 = 0;
    }

    FUN_006c09d0(&this->unk128);
    reinterpret_cast<::B00C20Pool *>((((void *)&(::GetTaskletManager()))))->ReleaseItem(*(::B00C20Item * *)nullptr);
}

// FUN_006c1520 - ReferenceObstacleArray::~ReferenceObstacleArray
//
// The original is the scalar destructor of ReferenceObstacleArray
// (RTTI .?AVReferenceObstacleArray@@, vftable 0x0106c484), whose base is
// NiRefObject (vftable 0x0101dce4, destructor 0x00496910) and whose member at
// +0x0c is a BSSimpleArray<NiPointer<ObstacleData> > (vftable 0x0106c640,
// destructor 0x006c6190).  The object is 0x1c bytes long.
//
// The stand-in classes below reproduce only what the destructor touches:
//   +0x00  vptr (shared with the base)
//   +0x04  base member
//   +0x08  int member that is cleared
//   +0x0c  member object with its own destructor
//
// The destructor itself is named after the tag so that the checker can find it.

struct FNV_NiRefObjectStandIn
{
    virtual ~FNV_NiRefObjectStandIn();
    int m_iObjectReferenceCount;
};

struct FNV_RobArrayStandIn
{
    virtual ~FNV_RobArrayStandIn();
    void* m_pData;
    int m_iElementCount;
    int m_pRayCursor;
};

struct FUN_006c1520_Class : public FNV_NiRefObjectStandIn
{
    virtual ~FUN_006c1520_Class();
    int m_08;
    FNV_RobArrayStandIn m_0c;
};
// @fnv 0x006c14f0
void* ReferenceObstacleArray::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_006c1520_Class *>((this))->::FUN_006c1520_Class::~FUN_006c1520_Class();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x1c);
    return this;
}

// Destructor that resets the m_08 field to zero.
// @fnv 0x006c1520
FUN_006c1520_Class::~FUN_006c1520_Class()
{
    m_08 = 0;
}

struct NavMeshInfoX;
struct NavMeshX
{
};
struct NavMeshPtrX
{
    NavMeshX* m_pObject;
};
struct InfoArrX
{
    void* vt;
    NavMeshInfoX** data;
    unsigned int cap;
    unsigned int count;
    unsigned int GetSize();
    NavMeshInfoX*& GetAt(unsigned int i);
    void Clear(bool b);
    unsigned int Add(NavMeshInfoX*& item);
};
struct ObstacleDataX
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
    int unk68;
    int unk6C;
    int unk70;
    bool bFlag74;
    InfoArrX kNavMeshInfos;
};
struct ObstPtrX
{
    ObstacleDataX* m_pObject;
};
struct NavMeshPtrArrX
{
    void* vt;
    NavMeshPtrX* data;
    unsigned int cap;
    unsigned int count;
    char unk10;
    NavMeshPtrArrX();
    ~NavMeshPtrArrX();
    unsigned int GetSize();
    NavMeshPtrX& GetAt(unsigned int i);
};
struct TaskDataX
{
};
void __cdecl FUN_006c3440(const ObstPtrX& obst);

struct ObstacleMgrX
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    bool bFlag198;
    void FUN_006c1760(const ObstPtrX& obst);
};
// @fnv 0x006c4c30
void FUN_006c4c30_shell::FUN_006c4c30()
{
    void* it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)((char*)this + 0x1c))))->GetFirstPos();
    while (it)
    {
        unsigned int formID;
        SpArr spArray(0);
        reinterpret_cast<::Map62d0 *>((((MapX*)((char*)this + 0x1c))))->FUN_00559120((::MapItem62d0 *&)(it), (void *&)(formID), (::Helper62d0 &)(spArray));
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(static_cast<ObstArr*>(spArray)->arr))->GetName())); ++i)
        {
            SpObst m_spRegisteredObstacle(static_cast<ObstArr*>(spArray)->arr.GetAt(i));
            reinterpret_cast<::ObstacleMgrX *>((((MgrX*)this)))->FUN_006c1760((const ::ObstPtrX &)(m_spRegisteredObstacle));
        }
    }
}

struct FUN_00496910_Base
{
    ~FUN_00496910_Base();
};

struct Member_45cec0
{
    ~Member_45cec0();
};

struct Member_69af10
{
    ~Member_69af10();
};

struct FUN_006c24d0 : FUN_00496910_Base
{
    char pad00[0x0c];
    Member_45cec0 m1;
    char pad0c[0x78 - 0x0c - sizeof(Member_45cec0)];
    Member_69af10 m2;
    char pad78[0x88 - 0x78 - sizeof(Member_69af10)];
    Member_45cec0 m3;

    ~FUN_006c24d0();
};
// @fnv 0x006c2490
void* ObstacleData_shell::FUN_006c2490(unsigned int flags)
{
    reinterpret_cast<::FUN_006c24d0 *>((this))->::FUN_006c24d0::~FUN_006c24d0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x8c);
    return this;
}

// @fnv 0x006c24d0
FUN_006c24d0::~FUN_006c24d0()
{}

struct FNVNode;
struct FNVNodeList
{
};
struct FNVNode
{
    virtual void Unknown0();
    virtual void Unknown1();
    virtual void Unknown2();
    virtual FNVNodeList* GetChildren();
};
struct FNVType
{
};
struct FNVData
{
    FNVType* func_0x0043b4f0(int* value);
};
struct FNVObject
{
};
struct FNVResultMember
{
    void func_0x0066b0d0(FNVData* data);
};
struct FNVResult
{
    int unk00;
    int unk04;
    int unk08;
    FNVResultMember record;
};
// Looks up a node's data; if its type is one of 2,1,4,10,20,28, stores it in result and returns true, otherwise recurses over children.
// @fnv 0x006c2550
bool __cdecl FindNodeData(FNVNode* node, FNVResult* result)
{
    FNVNodeList* children5;
    FNVObject* object5 = ((::FNVObject *)(::bhkCollisionObject::GetFromNiAVObject((::NiAVObject *)(node))));
    FNVData* data;
    int type_2;
    unsigned int indexVal;
    int value7;
    if (object5)
    {
        data = ((::FNVData *)(::fnv_006fa820::FUN_006fa820((const char *)(object5))));
        if (data)
        {
            type_2 = reinterpret_cast<::FUN_0043b4d0_shell *>((data->func_0x0043b4f0(&value7)))->FUN_0043b4d0();
            if (type_2 == 2 || type_2 == 1 || type_2 == 4 || type_2 == 10 || type_2 == 20 || type_2 == 28)
            {
                result->unk08 = 0;
                result->record.func_0x0066b0d0(data);
                ::ObstacleBounds::UpdateObstacleBounds((::ObstacleBounds::Obstacle *)(result));
                return true;
            }
        }
    }
    children5 = node->GetChildren();
    if (children5)
    {
        for (indexVal = 0; indexVal < ((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((children5))->FUN_00453470())); ++indexVal)
        {
            if (((::FNVNode *)(reinterpret_cast<::NiNode *>((children5))->GetAt(indexVal))))
            {
                if (FindNodeData(((::FNVNode *)(reinterpret_cast<::NiNode *>((children5))->GetAt(indexVal))), result))
                    return true;
            }
        }
    }
    return false;
}

struct KeyX
{
    KeyX();
    int a;
    int b;
    short c;
};

struct ObjB
{
    short GetWord();
    void Run();
};

struct ObjA
{
    ObjB* Find(KeyX* key);
    ObjB* Add(short w, int d, short t);
};

struct SrcB
{
    int u0;
    short w4;
    short pad6;
    int d8;
};

struct SrcC
{
    int d0;
    short w4;
};

struct FUN_006c4460_cls
{
    bool AddAndRunFromSources(ObjA* p1, SrcB* p2, SrcC* p3);
};

// Builds a key from p3, finds a word via p1, then adds p2's fields and runs the next entry.
// @fnv 0x006c4460
bool FUN_006c4460_cls::AddAndRunFromSources(ObjA* apObjA, SrcB* apSrcB, SrcC* apSrcC)
{
    KeyX key4;
    key4.b = apSrcC->d0;
    key4.c = apSrcC->w4;
    short tmp = ((::ObjB *)(::FUN_00559450((int *)(apObjA))))->GetWord();
    reinterpret_cast<::Unk00690e30 *>((((::ObjB *)(reinterpret_cast<::NavMesh *>((((::ObjB *)(::FUN_00559450((int *)(apObjA))))))->GetTriangle({})))))->SetSlotValue({}, {});
    return true;
}

struct FUN_006c6d40_base
{
  public:
    virtual void unk00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_006c6d40_base();
    ~FUN_006c6d40_base();
};
struct FUN_006c6d40_helper
{
  public:
};
struct FUN_006c6d40_cls : public FUN_006c6d40_base
{
  public:
    virtual void unk00();
    void* m_10;
    void FUN_006b3eb0(unsigned int a, unsigned int b);
    FUN_006c6d40_cls(unsigned int a, unsigned int b, void* p);
};
// Sets m_10 to p or a default from FUN_00401020, then calls FUN_006b3eb0 with a and b.
// @fnv 0x006c6d40
FUN_006c6d40_cls::FUN_006c6d40_cls(unsigned int auiParam1, unsigned int auiParam2, void* p)
{
    m_10 = p ? p : ((void *)(reinterpret_cast<::MemoryManager *>((((FUN_006c6d40_helper*)((void *)(::FUN_00401020())))))->GetGeneralAllocator()));
    FUN_006b3eb0(auiParam1, auiParam2);
}

// FUN_006c0190
//
// A member function that takes one 4-byte parameter, resolves it through a
// cdecl lookup helper, and, when the lookup succeeds, hands the resolved
// pointer to a singleton object's member routine.

struct FUN_006c0190_cls
{
    void FUN_006c0190(void* apParam);
};

// Lookup helper: cdecl, one argument, returns the resolved pointer.

// Singleton accessor: cdecl, no arguments, returns the global manager.

// @fnv 0x006c0190
void FUN_006c0190_cls::FUN_006c0190(void* apParam)
{
    void* pResolved = ::FUN_004b5a80(apParam);
    if (pResolved != 0)
    {
        ((FUN_006c1c90_shell*)((void *)(::fnv_006c0720::GetNavMeshObstacleManager())))->ForwardToSubObject(pResolved);
    }
}

struct ObstacleManagerBase
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    ~ObstacleManagerBase();
};
struct ObstaclePointerMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~ObstaclePointerMap();
};
struct ObstacleList
{
    unsigned int unk00;
    unsigned int unk04;
    ~ObstacleList();
};
struct ObstacleArrayState
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    ~ObstacleArrayState();
};
struct ObstacleTaskMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    ~ObstacleTaskMap();
};
struct ObstacleReferenceMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~ObstacleReferenceMap();
};
struct ObstacleTimer
{
    unsigned int unk00;
    ~ObstacleTimer();
};
struct ObstacleInfoMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~ObstacleInfoMap();
};
struct ObstacleTaskArray
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ~ObstacleTaskArray();
};
struct ObstacleOwner
{
    unsigned int unk00;
    ~ObstacleOwner();
};
struct ObstacleOwnedObject
{
    virtual ~ObstacleOwnedObject();
};
struct FUN_006c0510 : ObstacleManagerBase
{
    ObstaclePointerMap obstacles;        // 0x1C
    ObstacleList pending;                // 0x2C
    ObstacleList processed;              // 0x34
    ObstacleArrayState arrayState;       // 0x3C
    ObstacleTaskMap tasks;               // 0x60
    ObstacleTaskMap removedTasks;        // 0xA0
    ObstacleReferenceMap references;     // 0xE0
    ObstacleList removed;                // 0xF0
    ObstacleList added;                  // 0xF8
    ObstaclePointerMap active;           // 0x100
    ObstaclePointerMap queued;           // 0x110
    ObstacleOwnedObject* currentTasks;   // 0x120
    ObstacleOwnedObject* finishedTasks;  // 0x124
    ObstacleTimer timer;                 // 0x128
    ObstacleInfoMap info;                // 0x12C
    ObstacleTaskArray taskArray;         // 0x13C
    ObstacleTaskArray processedArray;    // 0x14C
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    ObstacleList waiting;    // 0x180
    ObstacleList completed;  // 0x188
    unsigned int unk190;
    float unk194;
    bool unk198;
    ObstacleOwner owner;  // 0x19C
    void FUN_006c09f0();
    ~FUN_006c0510();
};
// Runs cleanup via FUN_006c09f0, then deletes currentTasks and finishedTasks if they are set.
// @fnv 0x006c0510
FUN_006c0510::~FUN_006c0510()
{
    FUN_006c09f0();
    if (currentTasks)
        delete currentTasks;
    if (finishedTasks)
        delete finishedTasks;
}

namespace fnv_006c09f0 {
class NavMesh
{
  public:
};
struct NavMeshPtr
{
    NavMesh* object;
    NavMeshPtr();
    ~NavMeshPtr();
};
struct MeshInfoView
{
    bool FUN_00690860(NavMeshPtr& mesh);
};
struct MeshInfoArray
{
    unsigned int GetFlags();
    MeshInfoView*& GetAt(unsigned int index);
};
class ObstacleData
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    SpArr reference;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    MeshInfoArray meshes;
};
}  // namespace fnv_006c09f0
template <> class NiPointer<fnv_006c09f0::ObstacleData>
{
  public:
    fnv_006c09f0::ObstacleData* m_pObject;
    NiPointer(const NiPointer& other);
    ~NiPointer();
    fnv_006c09f0::ObstacleData* operator->() const;
};
namespace fnv_006c09f0 {
struct ClearMapView
{
    unsigned int vtable;
    unsigned int hashSize;
    unsigned int buckets;
    unsigned int count;
    void RemoveAll();
};
struct RefListView
{
    unsigned int item;
    unsigned int next;
    bool IsInList(unsigned int& value);
    void RemoveAll();
};
struct ClearArrayView
{
};
struct ObstacleTreeView
{
};
struct ManagerView
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    MapX obstacles;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    RefListView pending;
    RefListView removed;
    ClearArrayView processed;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    ObstacleTreeView treeA;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    ObstacleTreeView treeB;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    ClearMapView mapE0;
    RefListView listF0;
    RefListView listF8;
    ClearMapView map100;
    ClearMapView map110;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    bool active;
    void FUN_006c09f0();
    void SetEnabled(bool value);
};
// @fnv 0x006c09f0
void ManagerView::FUN_006c09f0()
{
    SpArr records(0);
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(obstacles))->GetFirstPos();
    unsigned int key;
    while (position)
    {
        reinterpret_cast<::Map62d0 *>(&(obstacles))->FUN_00559120((::MapItem62d0 *&)(position), (void *&)(key), (::Helper62d0 &)(records));
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(static_cast<ObstArr*>(records)->arr))->GetName())); ++i)
        {
            NiPointer<ObstacleData> obstacle(
                *reinterpret_cast<NiPointer<ObstacleData>*>(static_cast<ObstArr*>(records)->arr.GetAt(i)));
            if (!reinterpret_cast<::RefList *>(&(removed))->FUN_005f65d0((void **)&(key)))
            {
                reinterpret_cast<::S_this *>(this)->FUN_006c1e00((::S_param *)(::ObstArr *)(static_cast<ObstArr*>(obstacle->reference)));
            }
            for (unsigned int j = 0; j < obstacle->meshes.GetFlags(); ++j)
            {
                NavMeshPtr mesh;
                if (obstacle->meshes.GetAt(j)->FUN_00690860(mesh))
                {
                    reinterpret_cast<::FUN_006993c0_cls *>((((::fnv_006c09f0::NavMesh *)(::FUN_00559450((int *)&(mesh))))))->FUN_006993c0();
                }
            }
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<ClearMapView*>(&obstacles)))->FUN_00438af0();
    reinterpret_cast<::FUN_00438af0_Class *>(&(map100))->FUN_00438af0();
    reinterpret_cast<::FUN_00438af0_Class *>(&(map110))->FUN_00438af0();
    reinterpret_cast<::FUN_00438af0_Class *>(&(mapE0))->FUN_00438af0();
    reinterpret_cast<::FileMatchList *>(&(listF0))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(listF8))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(pending))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&(removed))->RemoveAll();
    reinterpret_cast<::ListX *>(&(processed))->FUN_004ee920();
    reinterpret_cast<::Queue6c67 *>(&(treeA))->ClearQueue(false);
    reinterpret_cast<::Queue6c67 *>(&(treeB))->ClearQueue(false);
    if (active)
        SetEnabled(false);
}
}  // namespace fnv_006c09f0

struct TESObjectREFR;
struct TESBoundObject;
struct TESObjectDOOR;

struct RefSP0dc0
{
    void* m_pObject;
    RefSP0dc0(int);
    ~RefSP0dc0();
};

struct RefList0dc0
{
    void* m_item;
    RefList0dc0* m_pkNext;
    bool IsInList(TESObjectREFR*& item);
    void Remove(TESObjectREFR* const& item);
};

struct IdList0dc0
{
    unsigned int m_item;
    IdList0dc0* m_pkNext;
    bool IsInList(const unsigned int& item);
    void AddHead(const unsigned int& item);
};

struct Map0dc0
{
    void* vtbl;
    int unk04;
    int unk08;
    int unk0C;
    bool GetAt(unsigned int key, RefSP0dc0& val);
};

unsigned int GetFormType0dc0(TESBoundObject* form);

struct ObstMgr0dc0
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    RefList0dc0 kRemovedRefs;
    IdList0dc0 kPendingIDs;
    Map0dc0 kMap100;
    Map0dc0 kMap110;
    void FUN_006c0dc0(TESObjectREFR* ref);
};

// @fnv 0x006c0dc0
void ObstMgr0dc0::FUN_006c0dc0(TESObjectREFR* ref)
{
    TESBoundObject* pBase6 = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
    if (GetFormType0dc0(pBase6) == 0x1c)
    {
        TESObjectDOOR* pPathNodeDoor = (TESObjectDOOR*)pBase6;
        if (!reinterpret_cast<::FUN_00518080_shell *>((pPathNodeDoor))->FUN_00518080())
            reinterpret_cast<::fnv_006c0c30::Mgr006c0c30 *>(this)->FUN_006c0c30((::fnv_006c0c30::Actor *)(ref));
    }
    RefSP0dc0 spScreenData(0);
    if (!reinterpret_cast<::Map62d0 *>(&(kMap110))->FUN_006c62d0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((ref))->FUN_0084e3a0())), (void **)&(spScreenData)))
    {
        if (reinterpret_cast<::RefList *>(&(kRemovedRefs))->FUN_005f65d0((void **)&(ref)))
            reinterpret_cast<::ItemChangeListNode *>(&(kRemovedRefs))->FUN_00905330((::InventoryStackRecord *const &)(ref));
    }
    if (!reinterpret_cast<::Map62d0 *>(&(kMap100))->FUN_006c62d0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((ref))->FUN_0084e3a0())), (void **)&(spScreenData)))
    {
        if (!reinterpret_cast<::RefList *>(&(kPendingIDs))->FUN_005f65d0((void **)&(const unsigned int &)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((ref))->FUN_0084e3a0())))))
            kPendingIDs.AddHead(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((ref))->FUN_0084e3a0())));
    }
}

template <class T> struct Ptr_c1190
{
    T* m_pObject;
    Ptr_c1190(T* p);
    Ptr_c1190(const Ptr_c1190& other);
    ~Ptr_c1190();
    Ptr_c1190& operator=(T* p);
    operator T*() const;
    T* operator->() const;
};
struct Mesh_c1190;
struct Info_c1190;
struct Mesh_c1190
{
};
struct MeshArr_c1190
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    MeshArr_c1190();
    ~MeshArr_c1190();
    Ptr_c1190<Mesh_c1190>& FUN_00877a30(unsigned int i);
};
struct InfoArr_c1190
{
    int unk00;
};
struct Kind_c1190
{
};
struct ObsArr_c1190;
struct Obs_c1190
{
    int unk00;
    int unk04;
    int unk08;
    Ptr_c1190<Kind_c1190> m_spKind;
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
    int unk68;
    int unk6C;
    int unk70;
    bool bFlag74;
    InfoArr_c1190 kInfos;
};
struct ObsArr_c1190
{
    Ptr_c1190<Obs_c1190>& FUN_00877a30(unsigned int i);
};
struct Holder_c1190
{
    int unk00;
    int unk04;
    int unk08;
    ObsArr_c1190 kObstacles;
    int unk10;
    int unk14;
    int unk18;
    Holder_c1190();
};
struct Task_c1190
{
};
struct Key_c1190
{
};
struct HolderMap_c1190
{
};
struct ObsMap_c1190
{
};
void __cdecl FUN_006c34f0(Key_c1190* key, Ptr_c1190<Holder_c1190>& holder);
void __cdecl FUN_006c3440(const Ptr_c1190<Obs_c1190>& obst);
struct Mgr_c1190
{
    void RegisterKey(Key_c1190* key);
};
struct InnerPtr
{
};
struct InnerArr
{
    unsigned int* FUN_00877a30(unsigned int);
};
struct ObView
{
    int unk000;
    int unk004;
    int unk008;
    InnerPtr inner;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    InnerArr arr;
};
struct ObPointerView
{
};
struct TaskView
{
};
struct MapView
{
};
struct PtrMapView
{
};
struct ListView
{
};
struct HostA
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    MapView map;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    ListView list;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    PtrMapView ptrMap;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    bool flag;
    void RemoveEntry(unsigned int);
};
struct RigidBodyPtr1920
{
    void* m_pObject;
};

struct ObstData1920
{
    int unk00;
    int unk04;
    int unk08;
    RigidBodyPtr1920 m_pRigidBody;
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
    int unk68;
    int unk6C;
    int unk70;
    bool bFlag74;
    InfoArrX kNavMeshInfos;
};

struct ObstPtr1920
{
    ObstData1920* m_pObject;
    ObstPtr1920(const ObstPtr1920& other);
    ~ObstPtr1920();
};

struct ObstArr1920
{
    unsigned int GetSize();
    ObstPtr1920& GetAt(unsigned int i);
};

struct RefObstData1920
{
    int unk00;
    int unk04;
    int unk08;
    ObstArr1920 kObstacles;
};

struct RefObstPtr1920
{
    RefObstData1920* m_pObject;
    RefObstPtr1920(int p);
    ~RefObstPtr1920();
};

struct Map1C_1920
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    bool GetAt(unsigned int key, RefObstPtr1920& out);
};

struct List3C_1920
{
    int unk00;
    int unk04;
    void Remove(const ObstPtr1920& item);
};

struct MapE0_1920
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    bool RemoveAt(void* key);
};

struct TaskData1920
{
};

void __cdecl BuildRefObstacles1920(void* pRef, RefObstPtr1920& spArr);
void __cdecl UpdateObstacle1920(const ObstPtr1920& obst);

struct ObstMgr1920
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    Map1C_1920 map1C;
    List3C_1920 list3C;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    MapE0_1920 mapE0;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    bool bFlag198;

    void RebuildRefObstacles(unsigned int formID, void* pRef);
};

namespace ObstacleBounds {
struct Vec
{
    float x, y, z;
    Vec();
    Vec(float, float, float);
    Vec FUN_0053d1a0(const Vec&);
    Vec FUN_004b3800(const Vec&);
};
struct PlainVec
{
    float x, y, z;
};
struct Mat
{
    float entries[3][3];
    Mat();
    Mat FUN_004768c0();
    Mat FUN_0043f8d0(const Mat&);
    Vec FUN_004b4500(const Vec&);
};
struct Transform
{
    Mat rotation;
    PlainVec position;
    float scale;
};
union __declspec(align(16)) HkVec
{
    float lanes[4];
    unsigned char bytes[16];
};
struct __declspec(align(16)) HkTransform
{
    HkVec col0, col1, col2, translation;
    HkTransform(const void*);
};
struct __declspec(align(16)) Bounds
{
    HkVec minimum, maximum;
    Bounds();
};
struct Body
{
};
struct Collision
{
};
struct Pointer
{
    Collision* value;
};
struct Obstacle
{
    unsigned int unk0, unk4, unk8;
    Pointer collision;
    Vec position;
    Mat rotation;
    Vec localMin, localMax, worldMin, worldMax;
    unsigned int generation;
};
float FUN_00408840(float);
struct Manager
{
};
extern float DAT_0106c3ac;
// Rebuilds an obstacle's position, rotation, local and world bounds from its collision body's transform and bounds, then bumps the generation counter.
// @fnv 0x006c2650
bool UpdateObstacleBounds(Obstacle* obstacle)
{
    Collision* collision = ((::ObstacleBounds::Collision *)(::FUN_00559450((int *)&(obstacle->collision))));
    if (!collision)
        return false;
    Body* body = ((::ObstacleBounds::Body *)(std::uintptr_t)(reinterpret_cast<::FUN_00620b80_shell *>((collision))->GetReferenceFlags()));
    if (!body)
        return false;
    HkTransform hkTransform(((const void *)(::FUN_004b4f00((::TESDataHandler *)(body)))));
    Transform transform;
    transform.scale = 1.0f;
    ::FUN_00624ad0((::NiTransform *)&(transform), (::TopicH *)&(hkTransform));
    Bounds bounds;
    reinterpret_cast<::WorldObject_c8d3 *>((collision))->GetAabb((::Aabb_c8d3 &)(bounds));
    float angleX, angleY, angleZ;
    reinterpret_cast<::S_00a592c0_Matrix3 *>(&(transform.rotation))->DecomposeToEulerAngles(angleX, angleY, angleZ);
    Vec minimum, maximum;
    ::SetNiPoint3FromHkVector4((::NiPoint3 &)(minimum), (const ::hkVector4 &)(bounds.minimum));
    ::SetNiPoint3FromHkVector4((::NiPoint3 &)(maximum), (const ::hkVector4 &)(bounds.maximum));
    obstacle->position = reinterpret_cast<const Vec&>(transform.position);
    Vec axisVectors[3];
    for (unsigned int axis = 0; axis < 3; axis++)
        reinterpret_cast<::FUN_00439f50_class *>(&(transform.rotation))->FUN_00439f50(axis, (::NiPoint3 *)&(axisVectors[axis]));
    Vec upAxis, sideAxis, forwardAxis;
    if (FUN_00408840(axisVectors[0].z) > FUN_00408840(axisVectors[1].z))
    {
        if (FUN_00408840(axisVectors[0].z) > FUN_00408840(axisVectors[2].z))
        {
            upAxis = axisVectors[0];
            forwardAxis = axisVectors[1];
            sideAxis = axisVectors[2];
        }
        else
        {
            upAxis = axisVectors[2];
            forwardAxis = axisVectors[0];
            sideAxis = axisVectors[1];
        }
    }
    else
    {
        if (FUN_00408840(axisVectors[1].z) > FUN_00408840(axisVectors[2].z))
        {
            upAxis = axisVectors[1];
            forwardAxis = axisVectors[2];
            sideAxis = axisVectors[0];
        }
        else
        {
            upAxis = axisVectors[2];
            forwardAxis = axisVectors[0];
            sideAxis = axisVectors[1];
        }
    }
    if (upAxis.z < ::_DAT_01012060)
    {
        upAxis = (*(::ObstacleBounds::Vec *)(reinterpret_cast<::P3 *>(&(upAxis))->FUN_004a0bd0({})));
        forwardAxis = (*(::ObstacleBounds::Vec *)(reinterpret_cast<::P3 *>(&(forwardAxis))->FUN_004a0bd0({})));
    }
    upAxis = (*reinterpret_cast<::ObstacleBounds::Vec *>((void *)&::DAT_011a9484));
    sideAxis = upAxis.FUN_0053d1a0(forwardAxis);
    forwardAxis = (*(::ObstacleBounds::Vec *)(reinterpret_cast<::P3 *>((void *)&(const ::ObstacleBounds::Vec &)(sideAxis.FUN_004b3800(upAxis)))->FUN_004a0bd0({})));
    reinterpret_cast<::FUN_004769c0_shell *>(&(obstacle->rotation))->FUN_004769c0(0, (float *)&(forwardAxis));
    reinterpret_cast<::FUN_004769c0_shell *>(&(obstacle->rotation))->FUN_004769c0(1, (float *)&(sideAxis));
    reinterpret_cast<::FUN_004769c0_shell *>(&(obstacle->rotation))->FUN_004769c0(2, (float *)&(upAxis));
    Mat toLocalMat = obstacle->rotation.FUN_004768c0().FUN_0043f8d0(transform.rotation);
    Vec localCorners[8];
    localCorners[0] = toLocalMat.FUN_004b4500(Vec(minimum.x, minimum.y, minimum.z));
    localCorners[1] = toLocalMat.FUN_004b4500(Vec(maximum.x, minimum.y, minimum.z));
    localCorners[2] = toLocalMat.FUN_004b4500(Vec(minimum.x, maximum.y, minimum.z));
    localCorners[3] = toLocalMat.FUN_004b4500(Vec(maximum.x, maximum.y, minimum.z));
    localCorners[4] = toLocalMat.FUN_004b4500(Vec(minimum.x, minimum.y, maximum.z));
    localCorners[5] = toLocalMat.FUN_004b4500(Vec(maximum.x, minimum.y, maximum.z));
    localCorners[6] = toLocalMat.FUN_004b4500(Vec(minimum.x, maximum.y, maximum.z));
    localCorners[7] = toLocalMat.FUN_004b4500(Vec(maximum.x, maximum.y, maximum.z));
    Vec worldCorners[8];
    for (unsigned int worldIndex = 0; worldIndex < 8; worldIndex++)
        worldCorners[worldIndex] =
            (*(::ObstacleBounds::Vec *)(reinterpret_cast<::Point3Offset *>((void *)&(const ::ObstacleBounds::Vec &)(obstacle->rotation.FUN_004b4500(localCorners[worldIndex])))->ProjectileLaunched((::NiPoint3 *)&(obstacle->position), {})));
    Mat fromWorldMat = obstacle->rotation.FUN_004768c0();
    for (unsigned int snap = 0; snap < 8; snap++)
    {
        if (FUN_00408840(::FUN_004b1500(worldCorners[snap].x, ::DAT_01017a3c)) < DAT_0106c3ac)
        {
            worldCorners[snap].x += DAT_0106c3ac * 2.0f;
            localCorners[snap] = fromWorldMat.FUN_004b4500((*(::ObstacleBounds::Vec *)(reinterpret_cast<::FUN_00439ef0_class *>(&(worldCorners[snap]))->FUN_00439ef0((::NiPoint3 *)&(obstacle->position), *(const ::NiPoint3 *)nullptr))));
        }
        if (FUN_00408840(::FUN_004b1500(worldCorners[snap].y, ::DAT_01017a3c)) < DAT_0106c3ac)
        {
            worldCorners[snap].y += DAT_0106c3ac * 2.0f;
            localCorners[snap] = fromWorldMat.FUN_004b4500((*(::ObstacleBounds::Vec *)(reinterpret_cast<::FUN_00439ef0_class *>(&(worldCorners[snap]))->FUN_00439ef0((::NiPoint3 *)&(obstacle->position), *(const ::NiPoint3 *)nullptr))));
        }
    }
    obstacle->localMin = Vec(::DAT_01016970, ::DAT_01016970, ::DAT_01016970);
    obstacle->localMax = Vec(::DAT_01015f5c, ::DAT_01015f5c, ::DAT_01015f5c);
    for (unsigned int localIndex = 0; localIndex < 8; localIndex++)
    {
        obstacle->localMin.x = ::FUN_0040ebd0(obstacle->localMin.x, localCorners[localIndex].x);
        obstacle->localMin.y = ::FUN_0040ebd0(obstacle->localMin.y, localCorners[localIndex].y);
        obstacle->localMin.z = ::FUN_0040ebd0(obstacle->localMin.z, localCorners[localIndex].z);
        obstacle->localMax.x = ::FUN_00404010(obstacle->localMax.x, localCorners[localIndex].x);
        obstacle->localMax.y = ::FUN_00404010(obstacle->localMax.y, localCorners[localIndex].y);
        obstacle->localMax.z = ::FUN_00404010(obstacle->localMax.z, localCorners[localIndex].z);
    }
    obstacle->worldMin = Vec(::DAT_01016970, ::DAT_01016970, ::DAT_01016970);
    obstacle->worldMax = Vec(::DAT_01015f5c, ::DAT_01015f5c, ::DAT_01015f5c);
    for (unsigned int boundIndex = 0; boundIndex < 8; boundIndex++)
    {
        obstacle->worldMin.x = ::FUN_0040ebd0(obstacle->worldMin.x, worldCorners[boundIndex].x);
        obstacle->worldMin.y = ::FUN_0040ebd0(obstacle->worldMin.y, worldCorners[boundIndex].y);
        obstacle->worldMin.z = ::FUN_0040ebd0(obstacle->worldMin.z, worldCorners[boundIndex].z);
        obstacle->worldMax.x = ::FUN_00404010(obstacle->worldMax.x, worldCorners[boundIndex].x);
        obstacle->worldMax.y = ::FUN_00404010(obstacle->worldMax.y, worldCorners[boundIndex].y);
        obstacle->worldMax.z = ::FUN_00404010(obstacle->worldMax.z, worldCorners[boundIndex].z);
    }
    obstacle->generation = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::ObstacleBounds::Manager *>(&::g_timeGlobal))))->FUN_00825c00();
    return true;
}
}

struct DebugUpdateData
{
    float time;
    bool updateControllers;
    bool isMultithreaded;
    bool flag06;
    bool flag07;
    bool flag08;
    DebugUpdateData(float, bool, bool);
};
struct DebugColor
{
    float red, green, blue;
    DebugColor(float, float, float);
};
struct DebugSceneObject;
template <class T> struct DebugPointer
{
    T* object;
    DebugPointer(T*);
    DebugPointer(const DebugPointer&);
    ~DebugPointer();
    T* operator->() const;
    operator T*() const;
    DebugPointer& operator=(T*);
};
struct DebugSceneObject
{
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Unknown47();
    virtual void Unknown48();
    virtual void Unknown49();
    virtual void Unknown50();
    virtual void Unknown51();
    virtual void Unknown52();
    virtual void Unknown53();
    virtual void Unknown54();
    virtual void AttachChildInAvailableSlot(DebugSceneObject*, bool);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    DebugSceneObject(unsigned short);
};
struct DebugAlphaProperty
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    DebugAlphaProperty();
};
struct DebugMaterialProperty
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    DebugMaterialProperty();
};
struct DebugObjectArray
{
    unsigned int GetSize();
    DebugPointer<DebugSceneObject>& GetAt(unsigned int);
};
struct DebugObstacleArray
{
    unsigned int unk00, unk04, unk08;
    DebugObjectArray objects;
};
struct DebugObstacleMap
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct DebugTES
{
};
struct DebugObstacleManager
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    DebugObstacleMap obstacles;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    bool enabled;
    DebugPointer<DebugSceneObject> scene;
    void CreateObstacleBox(const DebugPointer<DebugSceneObject>&, DebugPointer<DebugSceneObject>&);
    void SetEnabled(bool show);
};
// @fnv 0x006c5460
void DebugObstacleManager::SetEnabled(bool show)
{
    if (show)
    {
        if (scene)
        {
            reinterpret_cast<::FUN_004def90_Class *>(((scene).operator->()))->FUN_004def90();
        }
        else
        {
            scene = new DebugSceneObject(0);
            DebugPointer<DebugAlphaProperty> h = new DebugAlphaProperty;
            reinterpret_cast<::FUN_0049ed90_shell *>(((h).operator->()))->FUN_0049ed90(true);
            DebugPointer<DebugMaterialProperty> p = new DebugMaterialProperty;
            DebugColor kMagenta(1.0f, 0.0f, 1.0f);
            reinterpret_cast<::fnv_004bc450::FUN_004bc450_S *>(((p).operator->()))->FUN_004bc450((const ::fnv_004bc450::C3 *)(const ::DebugColor *)(&kMagenta));
            reinterpret_cast<::DecalStub *>(((p).operator->()))->FUN_0068c9f0(::DAT_0101622c);
            reinterpret_cast<::FUN_00439410_cls *>(((scene).operator->()))->FUN_00439410((::ArgObject *)(void *)(h));
            reinterpret_cast<::FUN_00439410_cls *>(((scene).operator->()))->FUN_00439410((::ArgObject *)(void *)(p));
            ((::DebugSceneObject *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::DebugTES *)::g_TES)))->FUN_0084e3a0()))->AttachChildInAvailableSlot(scene, true);
            DebugUpdateData a(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((::DebugSceneObject *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::DebugTES *)::g_TES)))->FUN_0084e3a0()))))->FUN_00a59c60((std::intptr_t)&(a));
        }
        void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(obstacles))->GetFirstPos();
        while (position)
        {
            unsigned int l;
            DebugPointer<DebugObstacleArray> k(0);
            reinterpret_cast<::Map62d0 *>(&(obstacles))->FUN_00559120((::MapItem62d0 *&)(position), (void *&)(l), (::Helper62d0 &)(k));
            for (unsigned int c = 0; c < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(k->objects))->GetName())); ++c)
            {
                DebugPointer<DebugSceneObject> e(k->objects.GetAt(c));
                DebugPointer<DebugSceneObject> j(0);
                CreateObstacleBox(e, j);
                scene->AttachChildInAvailableSlot(j, true);
            }
        }
        reinterpret_cast<::FUN_00a5a040_Class *>(((scene).operator->()))->FUN_00a5a040();
        DebugUpdateData update(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>(((scene).operator->()))->FUN_00a59c60((std::intptr_t)&(update));
        enabled = true;
    }
    else
    {
        if (scene)
        {
            reinterpret_cast<::FUN_004def90_Class *>(((scene).operator->()))->FUN_004def90();
        }
        enabled = false;
    }
}

namespace fnv_006c5840 {
class ImageSpaceEffectParam
{
  public:
    float afValues[4];
    ImageSpaceEffectParam(float a, float b, float c, float d);
};

namespace _ {
struct FakePoint3
{
    float x, y, z;
    FakePoint3(float fX, float fY, float fZ);
};
}

class AnimIdle
{
  public:
    void FUN_00440460(const NiPoint3& kTranslate);
    void FUN_0043fa80(const void* pvRotate);
};

}  // namespace fnv_006c5840
template <> class NiPointer<fnv_006c5840::AnimIdle>
{
  public:
    fnv_006c5840::AnimIdle* p[1];
    NiPointer(fnv_006c5840::AnimIdle*);
    ~NiPointer();
    operator fnv_006c5840::AnimIdle*() const;
    NiPointer<fnv_006c5840::AnimIdle>& operator=(const NiPointer<fnv_006c5840::AnimIdle>&);
};
namespace fnv_006c5840 {

class ObstacleData
{
  public:
    char pad00[0x10];
    NiPoint3 kTranslate;
    char acRotate[0x24];
    NiPoint3 kMinBoundsCur;
    NiPoint3 kMaxPoint;
    char pad58[0x30];
    NiPointer<AnimIdle> m_kGeometry;
};


class FUN_006c5840_Class
{
  public:
    void CreateObstacleBox(NiPointer<ObstacleData>& aspObstacleData, NiPointer<AnimIdle>& spResult);
};

// Builds a box geometry from the obstacle's two corner points, applies its translate and rotate, stores it in the obstacle and returns it.
// @fnv 0x006c5840
void FUN_006c5840_Class::CreateObstacleBox(NiPointer<ObstacleData>& aspObstacleData, NiPointer<AnimIdle>& spResult)
{
    NiPoint3 kSize = ((ObstacleData*)aspObstacleData)->kMaxPoint - ((ObstacleData*)aspObstacleData)->kMinBoundsCur;
    ImageSpaceEffectParam kBoxColor(1.0f, 0.0f, 1.0f, 0.5f);
    _::FakePoint3 kCorner6(((ObstacleData*)aspObstacleData)->kMinBoundsCur.x, ((ObstacleData*)aspObstacleData)->kMinBoundsCur.y,
                           ((ObstacleData*)aspObstacleData)->kMinBoundsCur.z);
    _::FakePoint3 kVert0(((ObstacleData*)aspObstacleData)->kMaxPoint.x, ((ObstacleData*)aspObstacleData)->kMinBoundsCur.y,
                         ((ObstacleData*)aspObstacleData)->kMinBoundsCur.z);
    _::FakePoint3 kCorner5(((ObstacleData*)aspObstacleData)->kMaxPoint.x, ((ObstacleData*)aspObstacleData)->kMinBoundsCur.y,
                           ((ObstacleData*)aspObstacleData)->kMaxPoint.z);
    _::FakePoint3 kCorner2(((ObstacleData*)aspObstacleData)->kMinBoundsCur.x, ((ObstacleData*)aspObstacleData)->kMinBoundsCur.y,
                           ((ObstacleData*)aspObstacleData)->kMaxPoint.z);
    _::FakePoint3 kPt2(((ObstacleData*)aspObstacleData)->kMinBoundsCur.x, ((ObstacleData*)aspObstacleData)->kMaxPoint.y,
                       ((ObstacleData*)aspObstacleData)->kMinBoundsCur.z);
    _::FakePoint3 kPoint5(((ObstacleData*)aspObstacleData)->kMaxPoint.x, ((ObstacleData*)aspObstacleData)->kMaxPoint.y,
                          ((ObstacleData*)aspObstacleData)->kMinBoundsCur.z);
    _::FakePoint3 kCorner1(((ObstacleData*)aspObstacleData)->kMaxPoint.x, ((ObstacleData*)aspObstacleData)->kMaxPoint.y,
                           ((ObstacleData*)aspObstacleData)->kMaxPoint.z);
    _::FakePoint3 kVert4(((ObstacleData*)aspObstacleData)->kMinBoundsCur.x, ((ObstacleData*)aspObstacleData)->kMaxPoint.y,
                         ((ObstacleData*)aspObstacleData)->kMaxPoint.z);
    NiPointer<AnimIdle> spBoxGeom(
        ((::fnv_006c5840::AnimIdle *)(::CreateBoxMesh((const ::Vec87 &)(kVert4), (const ::Vec87 &)(kCorner1), (const ::Vec87 &)(kCorner5), (const ::Vec87 &)(kCorner2), (const ::Vec87 &)(kPt2), (const ::Vec87 &)(kPoint5), (const ::Vec87 &)(kVert0), (const ::Vec87 &)(kCorner6), (const ::Color87 &)(kBoxColor), true))));
    ((AnimIdle*)spBoxGeom)->FUN_00440460(((ObstacleData*)aspObstacleData)->kTranslate);
    ((AnimIdle*)spBoxGeom)->FUN_0043fa80(((ObstacleData*)aspObstacleData)->acRotate);
    ((ObstacleData*)aspObstacleData)->m_kGeometry = spBoxGeom;
    spResult = spBoxGeom;
}
}  // namespace fnv_006c5840

template <class T> class SPtr
{
  public:
    T* m_pObject;
    SPtr(T* p);
    ~SPtr();
    operator T*() const;
    T* operator->() const;
};
struct AVObj;
struct UpdData
{
    float fTime;
    bool bA;
    bool bB;
    int unk08;
    UpdData(float t, bool a, bool b);
};
struct NodeX
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
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void AttachChildX(AVObj* child, bool firstAvail);
    virtual void vfe0();
    virtual void vfe4();
    virtual void DetachChildX(AVObj* child);
    virtual void vfec();
};
struct Owner88
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
    SPtr<AVObj> pSceneObject;
};
struct ObstMgr6c5b20
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    SPtr<NodeX> m_pController;
    void FUN_006c5b20(SPtr<Owner88>& owner);
};
// @fnv 0x006c1760
void ObstacleMgrX::FUN_006c1760(const ObstPtrX& apObstacle)
{
    if (((::ObstacleDataX *)(::FUN_00559450((int *)&(apObstacle))))->bFlag74)
    {
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((::ObstacleDataX *)(::FUN_00559450((int *)&(apObstacle))))->kNavMeshInfos))->GetName())); i++)
        {
            reinterpret_cast<::ObstacleTaskData *>((((::TaskDataX *)(::fnv_006c5ef0::FUN_006c5ef0((char *)this, ::fnv_006c5ef0::FUN_006c5ef0_arg{(::fnv_006c5ef0::Flt *)(((::ObstacleDataX *)(::FUN_00559450((int *)&(apObstacle))))->kNavMeshInfos.GetAt(i))})))))->AddOperation((const ::NiPointer< ::ObstacleData> &)(apObstacle), (::OBSTACLE_TASK_TYPE)(0x21));
        }
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(((::ObstacleDataX *)(::FUN_00559450((int *)&(apObstacle))))->kNavMeshInfos))->Clear(true);
    }
    ::ObstacleBounds::UpdateObstacleBounds((::ObstacleBounds::Obstacle *)(::ObstacleDataX *)(((::ObstacleDataX *)(::FUN_00559450((int *)&(apObstacle))))));
    FUN_006c3440(apObstacle);
    if (bFlag198)
    {
        reinterpret_cast<::ObstMgr6c5b20 *>(this)->FUN_006c5b20((::SPtr< ::Owner88> &)(apObstacle));
    }
    if (((::ObstacleDataX *)(::FUN_00559450((int *)&(apObstacle))))->bFlag74)
    {
        NavMeshPtrArrX kArr;
        if (::fnv_006c2050::FUN_006c2050((const ::fnv_006c2050::Flt *)&(apObstacle), (::fnv_006c2050::S2f850 *)&(kArr)))
        {
            for (unsigned int j = 0; j < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(kArr))->GetName())); j++)
            {
                reinterpret_cast<::ObstacleTaskData *>((((::TaskDataX *)(::fnv_006c5ef0::FUN_006c5ef0((char *)this, ::fnv_006c5ef0::FUN_006c5ef0_arg{(::fnv_006c5ef0::Flt *)(((::NavMeshInfoX *)(reinterpret_cast<::FUN_0068efb0_shell *>((((::NavMeshX *)(::FUN_00559450((int *)&(kArr.GetAt(j)))))))->FUN_0068efb0())))})))))->AddOperation((const ::NiPointer< ::ObstacleData> &)(apObstacle), (::OBSTACLE_TASK_TYPE)(0x11));
                NavMeshInfoX* pInfo = ((::NavMeshInfoX *)(reinterpret_cast<::FUN_0068efb0_shell *>((((::NavMeshX *)(::FUN_00559450((int *)&(kArr.GetAt(j)))))))->FUN_0068efb0()));
                reinterpret_cast<::FUN_00438690 *>(&(((::ObstacleDataX *)(::FUN_00559450((int *)&(apObstacle))))->kNavMeshInfos))->FUN_007cb2e0((unsigned int *)&(pInfo));
            }
        }
    }
}
// @fnv 0x006c1190
void Mgr_c1190::RegisterKey(Key_c1190* key)
{
    Ptr_c1190<Holder_c1190> spHolder(0);
    if (!reinterpret_cast<::Map62d0 *>((((HolderMap_c1190*)((char*)this + 0x1c))))->FUN_006c62d0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((key))->FUN_0084e3a0())), (void **)(::Ptr_c1190< ::Holder_c1190> *)(&spHolder)))
    {
        spHolder = new Holder_c1190;
        FUN_006c34f0(key, spHolder);
        reinterpret_cast<::Map6920 *>((((HolderMap_c1190*)((char*)this + 0x1c))))->FUN_006c6920(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((key))->FUN_0084e3a0())), (*(::NiPointer< ::NiAVObject> *)&(const ::Ptr_c1190< ::Holder_c1190> &)(spHolder)));
    }
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(spHolder->kObstacles))->GetName())); i++)
    {
        Ptr_c1190<Obs_c1190> spObst(spHolder->kObstacles.FUN_00877a30(i));
        reinterpret_cast<::Map6920 *>((((ObsMap_c1190*)((char*)this + 0xe0))))->FUN_006c6920((std::uintptr_t)(::Kind_c1190 *)(spObst->m_spKind), (*(::NiPointer< ::NiAVObject> *)&(const ::Ptr_c1190< ::Obs_c1190> &)(spObst)));
        reinterpret_cast<::fnv_006c1d60::FUN_006c1d60_shell *>(this)->FUN_006c1d60((::fnv_006c1d60::ScriptLocalsX *)(::Kind_c1190 *)(spObst->m_spKind));
        if (reinterpret_cast<::fnv_005609b0::bhkRigidBody *>(((spObst->m_spKind).operator->()))->FUN_005609b0())
        {
            reinterpret_cast<::FUN_006c1c70_shell *>(this)->FUN_006c1c70((std::intptr_t)(::Kind_c1190 *)(spObst->m_spKind));
        }
        FUN_006c3440(spObst);
        if (*((bool*)this + 0x198))
        {
            reinterpret_cast<::ObstMgr6c5b20 *>(this)->FUN_006c5b20((::SPtr< ::Owner88> &)(spObst));
        }
        if (spObst->bFlag74)
        {
            MeshArr_c1190 kMeshes;
            if (::fnv_006c2050::FUN_006c2050((const ::fnv_006c2050::Flt *)&(spObst), (::fnv_006c2050::S2f850 *)&(kMeshes)))
            {
                for (unsigned int j = 0; j < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(kMeshes))->GetName())); j++)
                {
                    reinterpret_cast<::ObstacleTaskData *>((((::Task_c1190 *)(::fnv_006c5ef0::FUN_006c5ef0((char *)this, ::fnv_006c5ef0::FUN_006c5ef0_arg{(::fnv_006c5ef0::Flt *)(((::Info_c1190 *)(reinterpret_cast<::FUN_0068efb0_shell *>(((kMeshes.FUN_00877a30(j)).operator->()))->FUN_0068efb0())))})))))->AddOperation((const ::NiPointer< ::ObstacleData> &)(spObst), (::OBSTACLE_TASK_TYPE)(0x10));
                    reinterpret_cast<::FUN_00438690 *>(&(spObst->kInfos))->FUN_007cb2e0((unsigned int *)&(const ::Info_c1190 *const &)(((::Info_c1190 *)(reinterpret_cast<::FUN_0068efb0_shell *>(((kMeshes.FUN_00877a30(j)).operator->()))->FUN_0068efb0()))));
                }
            }
        }
    }
}

// @fnv 0x006c5b20
void ObstMgr6c5b20::FUN_006c5b20(SPtr<Owner88>& owner)
{
    if (owner->pSceneObject)
    {
        m_pController->DetachChildX(owner->pSceneObject);
    }
    SPtr<AVObj> spChild(0);
    reinterpret_cast<::fnv_006c5840::FUN_006c5840_Class *>(this)->CreateObstacleBox((::NiPointer< ::fnv_006c5840::ObstacleData> &)(owner), (::NiPointer< ::fnv_006c5840::AnimIdle> &)(spChild));
    m_pController->AttachChildX(spChild, true);
    reinterpret_cast<::FUN_00a5a040_Class *>(((m_pController).operator->()))->FUN_00a5a040();
    UpdData kData(0.0f, false, false);
    reinterpret_cast<::FUN_00a59c60_cls *>(((m_pController).operator->()))->FUN_00a59c60((std::intptr_t)&(kData));
}

class Obj6C5;

class Handle6C5
{
  public:
    void Reset(Obj6C5* pkObject);

    Obj6C5* m_pPointer;
};

class Obj6C5
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1C();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2C();
    virtual void vfn30();
    virtual void vfn34();
    virtual void vfn38();
    virtual void vfn3C();
    virtual void vfn40();
    virtual void vfn44();
    virtual void vfn48();
    virtual void vfn4C();
    virtual void vfn50();
    virtual void vfn54();
    virtual void vfn58();
    virtual void vfn5C();
    virtual void vfn60();
    virtual void vfn64();
    virtual void vfn68();
    virtual void vfn6C();
    virtual void vfn70();
    virtual void vfn74();
    virtual void vfn78();
    virtual void vfn7C();
    virtual void vfn80();
    virtual void vfn84();
    virtual void vfn88();
    virtual void vfn8C();
    virtual void vfn90();
    virtual void vfn94();
    virtual void vfn98();
    virtual void vfn9C();
    virtual void vfnA0();
    virtual void vfnA4();
    virtual void vfnA8();
    virtual void vfnAC();
    virtual void vfnB0();
    virtual void vfnB4();
    virtual void vfnB8();
    virtual void vfnBC();
    virtual void vfnC0();
    virtual void vfnC4();
    virtual void vfnC8();
    virtual void vfnCC();
    virtual void vfnD0();
    virtual void vfnD4();
    virtual void vfnD8();
    virtual void vfnDC();
    virtual void vfnE0();
    virtual void vfnE4();
    virtual void Attach(Obj6C5* pkChild);

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
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    Handle6C5 m_kChild;
};

class Owner6C5
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    Handle6C5 m_kRoomNode;

    void AttachChildFromSource(Handle6C5& kSource);
};
// @fnv 0x006c1590
void HostA::RemoveEntry(unsigned int key)
{
    SpArr array(0);
    if (!reinterpret_cast<::Map62d0 *>(&(map))->FUN_006c62d0(key, (void **)&(array)))
        return;
    reinterpret_cast<::NiTMap_S *>(&(map))->RemoveKey(key);
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((ObstArr*)array)->arr))->GetName())); i++)
    {
        SpObst item(((ObstArr*)array)->arr.GetAt(i));
        reinterpret_cast<::NiTMap_S *>(&(ptrMap))->RemoveKey((std::uintptr_t)(((void *)(::FUN_00559450((int *)&(((::ObView *)(::FUN_00559450((int *)(((ObPointerView*)&item)))))->inner))))));
        reinterpret_cast<::ListReader *>(&(list))->FUN_00631620((const ::NodeValue &)(item));
        if (flag)
            reinterpret_cast<::Owner6C5 *>(this)->AttachChildFromSource((::Handle6C5 &)(item));
        if (!reinterpret_cast<::FUN_0076b610_Class *>(&(((::ObView *)(::FUN_00559450((int *)(((ObPointerView*)&item)))))->arr))->FUN_0076b610())
        {
            for (unsigned int j = 0; j < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((::ObView *)(::FUN_00559450((int *)(((ObPointerView*)&item)))))->arr))->GetName())); j++)
                reinterpret_cast<::ObstacleTaskData *>((((::TaskView *)(::fnv_006c5ef0::FUN_006c5ef0((char *)this, ::fnv_006c5ef0::FUN_006c5ef0_arg{(::fnv_006c5ef0::Flt *)(*((::ObView *)(::FUN_00559450((int *)(((ObPointerView*)&item)))))->arr.FUN_00877a30(j))})))))->AddOperation((const ::NiPointer< ::ObstacleData> &)(item), (::OBSTACLE_TASK_TYPE)(0x20));
            reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(((::ObView *)(::FUN_00559450((int *)(((ObPointerView*)&item)))))->arr))->Clear(true);
        }
    }
}
// @fnv 0x006c1920
void ObstMgr1920::RebuildRefObstacles(unsigned int formID, void* pRef)
{
    RefObstPtr1920 spArr(0);
    if (!reinterpret_cast<::Map62d0 *>(&(this->map1C))->FUN_006c62d0(formID, (void **)&(spArr)))
    {
        return;
    }
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((::RefObstData1920 *)(::FUN_00559450((int *)&(spArr))))->kObstacles))->GetName())); i++)
    {
        ObstPtr1920 spObst = ((::RefObstData1920 *)(::FUN_00559450((int *)&(spArr))))->kObstacles.GetAt(i);
        if (((::ObstData1920 *)(::FUN_00559450((int *)&(spObst))))->bFlag74)
        {
            for (unsigned int j = 0; j < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((::ObstData1920 *)(::FUN_00559450((int *)&(spObst))))->kNavMeshInfos))->GetName())); j++)
            {
                reinterpret_cast<::ObstacleTaskData *>((((::TaskData1920 *)(::fnv_006c5ef0::FUN_006c5ef0((char *)(this), ::fnv_006c5ef0::FUN_006c5ef0_arg{(::fnv_006c5ef0::Flt *)(((::ObstData1920 *)(::FUN_00559450((int *)&(spObst))))->kNavMeshInfos.GetAt(j))})))))->AddOperation((const ::NiPointer< ::ObstacleData> &)(spObst), (::OBSTACLE_TASK_TYPE)(0x21));
            }
            reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(((::ObstData1920 *)(::FUN_00559450((int *)&(spObst))))->kNavMeshInfos))->Clear(true);
        }
        if (this->bFlag198)
        {
            reinterpret_cast<::Owner6C5 *>((this))->AttachChildFromSource((::Handle6C5 &)(spObst));
        }
        reinterpret_cast<::S_this *>((this))->FUN_006c1e00((::S_param *)(void *)(((void *)(::FUN_00559450((int *)&(((::ObstData1920 *)(::FUN_00559450((int *)&(spObst))))->m_pRigidBody))))));
        reinterpret_cast<::NiTMap_S *>(&(this->mapE0))->RemoveKey((std::uintptr_t)(((void *)(::FUN_00559450((int *)&(((::ObstData1920 *)(::FUN_00559450((int *)&(spObst))))->m_pRigidBody))))));
        reinterpret_cast<::ListReader *>(&(this->list3C))->FUN_00631620((const ::NodeValue &)(spObst));
    }
    BuildRefObstacles1920(pRef, spArr);
    for (unsigned int k = 0; k < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((::RefObstData1920 *)(::FUN_00559450((int *)&(spArr))))->kObstacles))->GetName())); k++)
    {
        ObstPtr1920 spObst2 = ((::RefObstData1920 *)(::FUN_00559450((int *)&(spArr))))->kObstacles.GetAt(k);
        UpdateObstacle1920(spObst2);
        if (((::ObstData1920 *)(::FUN_00559450((int *)&(spObst2))))->bFlag74)
        {
            NavMeshPtrArrX kNavMeshes;
            if (::fnv_006c2050::FUN_006c2050((const ::fnv_006c2050::Flt *)&(spObst2), (::fnv_006c2050::S2f850 *)&(kNavMeshes)))
            {
                for (unsigned int m = 0; m < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(kNavMeshes))->GetName())); m++)
                {
                    reinterpret_cast<::ObstacleTaskData *>((((::TaskData1920 *)(::fnv_006c5ef0::FUN_006c5ef0((char *)(this), ::fnv_006c5ef0::FUN_006c5ef0_arg{(::fnv_006c5ef0::Flt *)(((::NavMeshInfoX *)(reinterpret_cast<::FUN_0068efb0_shell *>((((::NavMeshX *)(::FUN_00559450((int *)&(kNavMeshes.GetAt(m)))))))->FUN_0068efb0())))})))))->AddOperation((const ::NiPointer< ::ObstacleData> &)(spObst2), (::OBSTACLE_TASK_TYPE)(0x11));
                    NavMeshInfoX* pInfo = ((::NavMeshInfoX *)(reinterpret_cast<::FUN_0068efb0_shell *>((((::NavMeshX *)(::FUN_00559450((int *)&(kNavMeshes.GetAt(m)))))))->FUN_0068efb0()));
                    reinterpret_cast<::FUN_00438690 *>(&(((::ObstData1920 *)(::FUN_00559450((int *)&(spObst2))))->kNavMeshInfos))->FUN_007cb2e0((unsigned int *)&(pInfo));
                }
            }
        }
        if (this->bFlag198)
        {
            reinterpret_cast<::ObstMgr6c5b20 *>((this))->FUN_006c5b20((::SPtr< ::Owner88> &)(spObst2));
        }
        reinterpret_cast<::fnv_006c1d60::FUN_006c1d60_shell *>((this))->FUN_006c1d60((::fnv_006c1d60::ScriptLocalsX *)(void *)(((void *)(::FUN_00559450((int *)&(((::ObstData1920 *)(::FUN_00559450((int *)&(spObst2))))->m_pRigidBody))))));
    }
}

// If both this object and the source hold a child, attaches the source's child to this object and clears the source's child handle.
// @fnv 0x006c5c50
void Owner6C5::AttachChildFromSource(Handle6C5& kSource)
{
    if (((::Obj6C5 *)(::FUN_00559450((int *)&(m_kRoomNode)))) && ((::Obj6C5 *)(::FUN_00559450((int *)&(((::Obj6C5 *)(::FUN_00559450((int *)&(kSource))))->m_kChild)))))
    {
        ((::Obj6C5 *)(::FUN_00559450((int *)&(m_kRoomNode))))->Attach(((::Obj6C5 *)(::FUN_00559450((int *)&(((::Obj6C5 *)(::FUN_00559450((int *)&(kSource))))->m_kChild)))));
        ((::Obj6C5 *)(::FUN_00559450((int *)&(kSource))))->m_kChild.Reset(0);
    }
}

struct NavMeshInfoY;
struct NavMeshY
{
};
struct NavMeshPtrY
{
    NavMeshY* m_pObject;
    NavMeshY* operator->() const;
};
struct InfoEntryY
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    InfoEntryY(NavMeshInfoY* info, unsigned int index);
};
struct InfoEntryArrY
{
    void* vt;
    InfoEntryY** data;
    unsigned int cap;
    unsigned int count;
    NavMeshInfoY* m_pNavigationMesh;
    unsigned int GetSize();
    void Clear(bool bFree);
    unsigned int Add(InfoEntryY*& item);
    void RebuildFromNavMesh(const NavMeshPtrY& apSearchNavMesh);
};

// @fnv 0x006dfba0
void InfoEntryArrY::RebuildFromNavMesh(const NavMeshPtrY& apNavMesh)
{
    unsigned int ItemUpdateArray = reinterpret_cast<::S006911c0 *>(((apNavMesh).operator->()))->FUN_006911c0();
    if (!m_pNavigationMesh || ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())) != ItemUpdateArray)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(false);
        reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>(this)->FUN_0084b5c0(ItemUpdateArray);
        for (unsigned int i = 0; i < ItemUpdateArray; i++)
        {
            InfoEntryY* pEntry = new InfoEntryY(((::NavMeshInfoY *)(reinterpret_cast<::FUN_0068efb0_shell *>(((apNavMesh).operator->()))->FUN_0068efb0())), i);
            reinterpret_cast<::FUN_00438690 *>(this)->FUN_007cb2e0((unsigned int *)&(pEntry));
        }
        m_pNavigationMesh = ((::NavMeshInfoY *)(reinterpret_cast<::FUN_0068efb0_shell *>(((apNavMesh).operator->()))->FUN_0068efb0()));
    }
}

struct FUN_00963d60_shell
{

    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;

    BSSimpleList<int>* unk60c;
    void FUN_00963d60(std::intptr_t param_2);
};
// Walks the list at unk60c and deletes each entry whose stored value at offset 8 equals param_2, restarting from the head after each removal.
// @fnv 0x00963d60
void FUN_00963d60_shell::FUN_00963d60(std::intptr_t param_2)
{
    BSSimpleList<int>* pNode;
    std::intptr_t pEntry;
    std::intptr_t pEntryCopy;

    if (unk60c == 0 || param_2 == 0)
        return;
    pNode = unk60c;
    pEntry = 0;
    while (pNode != 0 && pNode->m_item != 0)
    {
        pEntry = pNode->m_item;
        if (pEntry != 0 && param_2 == *(int*)((char*)pEntry + 8))
        {
            reinterpret_cast<::ItemChangeListNode *>((((Call_00905330*)pNode)))->FUN_00905330((*(::InventoryStackRecord *const *)((bhkRigidBody**)&pEntry)));
            pEntryCopy = pEntry;
            ::FUN_00401030((void*)pEntryCopy);
            pNode = unk60c;
        }
        else
        {
            pNode = ((::BSSimpleList<int> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
    }
}

namespace s60 {
struct Form;
struct Door;
int FUN_00401170(Form* f);
struct Ref
{
};
struct L1
{
    void* a;
    void* b;
};
struct L2
{
    void* a;
    void* b;
    void FUN_005ae3d0(const unsigned int& r);
};
}
using namespace s60;
class Own60
{
  public:
    char pad[0x2c];
    L1 m_2c;
    char padCur[0xf0 - 0x34];
    L1 m_f0;
    L2 m_f8;
    void FUN_006c1060(Ref* ref);
};
// @fnv 0x006c1060
void Own60::FUN_006c1060(Ref* ref)
{
    Form* pForm = ((::s60::Form *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()));
    if (FUN_00401170(pForm) == 0x1c)
    {
        Door* door = (Door*)pForm;
        if (!reinterpret_cast<::FUN_00518080_shell *>((door))->FUN_00518080())
            reinterpret_cast<::fnv_006c1cb0::Call_006c0c80 *>(this)->FUN_006c0c80((::fnv_006c1cb0::TESObjectREFR *)(ref));
    }
    reinterpret_cast<::ItemChangeListNode *>(&(m_2c))->FUN_00905330((::InventoryStackRecord *const &)(ref));
    if (reinterpret_cast<::RefList *>(&(m_f0))->FUN_005f65d0((void **)&(ref)))
    {
        reinterpret_cast<::ItemChangeListNode *>(&(m_f0))->FUN_00905330((::InventoryStackRecord *const &)(ref));
    }
    else if (!reinterpret_cast<::RefList *>(&(m_f8))->FUN_005f65d0((void **)&(const unsigned int &)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((ref))->FUN_0084e3a0())))))
    {
        m_f8.FUN_005ae3d0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((ref))->FUN_0084e3a0())));
    }
}

struct Vector3
{
    float x;
    float y;
    float z;
};

struct RotationMatrix
{
};

struct WorldObject;

struct Reference
{
};

extern float g_0106c3a4;
extern float g_0106c3a8;

// @fnv 0x006c3440
void __cdecl FUN_006c3440(Reference* reference)
{
    Vector3 transformed;
    reinterpret_cast<::FUN_00439ef0_class *>((reinterpret_cast<RotationMatrix*>(reinterpret_cast<char*>(((::WorldObject *)(::FUN_00559450((int *)(reference))))) + 0x64)))->FUN_00439ef0((::NiPoint3 *)(::Vector3 *)(&transformed),
                       (*(const ::NiPoint3 *)(reinterpret_cast<const Vector3*>(reinterpret_cast<char*>(((::WorldObject *)(::FUN_00559450((int *)(reference))))) + 0x58))));

    if (transformed.z < g_0106c3a4)
    {
        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(((::WorldObject *)(::FUN_00559450((int *)(reference))))) + 0x74) = 0;
    }
    else
    {
        float zLimit = g_0106c3a4 * 2.0;
        if (zLimit > transformed.z && transformed.x < g_0106c3a8 && transformed.y < g_0106c3a8)
        {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(((::WorldObject *)(::FUN_00559450((int *)(reference))))) + 0x74) = 0;
        }
        else
        {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(((::WorldObject *)(::FUN_00559450((int *)(reference))))) + 0x74) = 1;
        }
    }
}

namespace fnv_006c3640 {
struct AutoMemHelper
{
    int old;
    AutoMemHelper(int, bool, char*, int);
    ~AutoMemHelper();
};
extern "C" char DAT_0106c3f0;
extern "C" char DAT_0106c498;
struct SettingShell
{
    bool* FUN_00408d60();
};
struct TimeShell
{
};
struct TimerShell
{
};
struct ArrayShell
{
};
struct PathShell
{
};
struct CellShell
{
};
struct C006c3640
{
    char pad0[0x18];
    bool flag;
    char pad19[0x190 - 0x19];
    int state;
    float time;
    char pad198[8];
    TimerShell timer;
    void FUN_006c5190();
    void FUN_006c4d30();
    void MatchPortalEdges();
    void FUN_006c3640();
};
// @fnv 0x006c3640
void C006c3640::FUN_006c3640()
{
    AutoMemHelper mem(0x2e, true, &DAT_0106c3f0, 0x508);
    if (!*((SettingShell*)&(*reinterpret_cast<char *>(&::g_011d73e4)))->FUN_00408d60())
        return;
    reinterpret_cast<::GlobalObject_0044fae0 *>(this)->FUN_004538a0((int)(&DAT_0106c498));
    reinterpret_cast<::TESForm *>(&(timer))->ClearData();
    bool changed = false;
    time -= reinterpret_cast<::Twin_0084d030 *>((((TimeShell*)&(*reinterpret_cast<char *>(&::g_timeGlobal)))))->GetStoredFloatValue();
    switch (state)
    {
    case 0: {
        reinterpret_cast<::fnv_006c47e0::FUN_006c47e0_shell *>(this)->FUN_006c47e0();
        reinterpret_cast<::fnv_006c45e0::FUN_006c45e0_shell *>(this)->ProcessAddedRefs();
        reinterpret_cast<::fnv_006c4fb0::FUN_006c4fb0_shell *>(this)->ProcessDoorObstacles();
        FUN_006c5190();
        reinterpret_cast<::Thing *>(this)->FUN_006c4970();
        reinterpret_cast<::FUN_006c4900_shell *>(this)->FUN_006c4900();
        if (flag)
        {
            reinterpret_cast<::FUN_006c4c30_shell *>(this)->FUN_006c4c30();
            flag = false;
        }
        else
        {
            reinterpret_cast<::ObsMgr *>(this)->FUN_006c4ad0();
            reinterpret_cast<::NavMeshObstacleManager *>(this)->ProcessActivatedObstacles();
        }
        FUN_006c4d30();
        unsigned c = reinterpret_cast<::NavMeshObstacleManager *>(this)->GetProcessedTaskCount();
        unsigned l = reinterpret_cast<::NavMeshObstacleManager *>(this)->GetBackgroundTaskCount();
        bool e = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ArrayShell*)((char*)this + 0x12c))))->FUN_0084e3a0())) > 0;
        bool j = false;
        if (e)
        {
            if (l > 0)
            {
                if (l == c && time <= 0.0)
                    j = true;
            }
            else if (time <= 0.0)
                j = true;
        }
        else if (l > 0 && l == c && time <= 0.0)
            j = true;
        if (j)
        {
            reinterpret_cast<::FUN_006ebc70_shell *>((((::fnv_006c3640::PathShell *)(::GetPathManager()))))->FUN_006ebc70();
            state = 1;
        }
        break;
    }
    case 1:
        if (reinterpret_cast<::FUN_006ebc90_shell *>((((::fnv_006c3640::PathShell *)(::GetPathManager()))))->FUN_006ebc90())
        {
            unsigned processed = reinterpret_cast<::NavMeshObstacleManager *>(this)->GetProcessedTaskCount();
            unsigned background = reinterpret_cast<::NavMeshObstacleManager *>(this)->GetBackgroundTaskCount();
            if (background > 0)
            {
                MatchPortalEdges();
                changed = reinterpret_cast<::fnv_006c44d0::FUN_006c44d0_shell *>(this)->FUN_006c44d0();
                ::ClearOwnedObjects((char *)this);
            }
            ::ProcessObstacleTasks((::NavMeshObstacleManager *)this);
            reinterpret_cast<::FUN_006ebcd0_shell *>((((::fnv_006c3640::PathShell *)(::GetPathManager()))))->FUN_006ebcd0();
            state = 0;
            time = *(float*)&DAT_0106c398;
            if (changed && reinterpret_cast<::TESObjectCELL *>((((::fnv_006c3640::CellShell *)(::FUN_00552ba0()))))->FUN_00552bb0())
                reinterpret_cast<::fnv_006a5ca0::PaddedBooleanState *>((((::fnv_006c3640::CellShell *)(::FUN_00552ba0()))))->FUN_006a5ca0();
        }
        break;
    }
    reinterpret_cast<::TESForm *>(&(timer))->ClearData();
    reinterpret_cast<::ActorTaskManager *>(this)->WaitForTasksDuringRendering();
}
}  // namespace fnv_006c3640

namespace fnv_006c5190 {
struct ObjX
{
    virtual void v0(), v1(), v2(), v3(), v4(), v5(), v6(), v7(), v8(), v9(), v10(), v11(), v12(), v13(), v14(), v15(),
        v16(), v17(), v18(), v19(), v20(), v21(), v22(), v23(), v24(), v25(), v26(), v27(), v28(), v29(), v30(), v31(),
        v32(), v33(), v34(), v35(), v36(), v37(), v38(), v39(), v40(), v41(), v42(), v43(), v44(), v45(), v46(), v47(),
        v48(), v49(), v50(), v51(), v52(), v53(), v54(), v55(), v56(), v57(), v58(), v59(), v60(), v61(), v62(), v63(),
        v64(), v65(), v66(), v67(), v68(), v69(), v70(), v71(), v72(), v73(), v74(), v75(), v76(), v77(), v78(), v79(),
        v80(), v81(), v82(), v83(), v84(), v85(), v86(), v87(), v88(), v89(), v90(), v91(), v92(), v93(), v94(), v95(),
        v96(), v97(), v98(), v99(), v100(), v101(), v102(), v103(), v104(), v105(), v106(), v107(), v108(), v109(),
        v110(), v111(), v112(), v113(), v114(), v115();
    virtual int F1d0();
};
struct ElemX
{
    char pad[0x78];
    struct SetX
    {
    } m78;
};
struct PtrX
{
    void* m_p;
    PtrX(void* p);
    PtrX(const PtrX& o);
    ~PtrX();
};
void* FUN_00aa13e0(unsigned n);
struct NewX
{
    char pad[0x1c];
    NewX();
};
struct ArrX
{
    PtrX& FUN_00877a30(unsigned i);
};
struct HolderX
{
    char pad[0xc];
    ArrX arr;
};
struct QArrX : ArrX
{
    int a, b, c, d, e;
    QArrX();
    ~QArrX();
};
bool FUN_006c34f0(ObjX* o, PtrX* p);
struct NodeX
{
    bool FUN_008256d0();
};
struct TblX
{
};
struct M100
{
};
struct M110
{
};
class SelfX
{
  public:
    char pad[0xf0];
    NodeX m_kList;
    char pad2[0x100 - 0xf0 - 1];
    M100 m100;
    char pad3[0xf];
    M110 m110;
    bool FUN_006c5190();
};
// For each object passing F1d0, builds data, updates entries through FUN_006c5ef0, removes its key from m100, and passes the data to m110.
// @fnv 0x006c5190
bool SelfX::FUN_006c5190()
{
    if (m_kList.FUN_008256d0())
        return false;
    bool bChanged = false;
    NodeX* pkNode = &m_kList;
    while (pkNode && !pkNode->FUN_008256d0())
    {
        ObjX* pkObj = *((::fnv_006c5190::ObjX **)((void *)(pkNode)));
        if (pkObj->F1d0())
        {
            PtrX spScreenData(new NewX);
            if (FUN_006c34f0(pkObj, &spScreenData))
            {
                for (unsigned i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((HolderX*)((::fnv_006c5190::ElemX *)(::FUN_00559450((int *)&(spScreenData)))))->arr))->GetName())); i++)
                {
                    QArrX kArr;
                    if (::fnv_006c2050::FUN_006c2050((const ::fnv_006c2050::Flt *)&(((HolderX*)((::fnv_006c5190::ElemX *)(::FUN_00559450((int *)&(spScreenData)))))->arr.FUN_00877a30(i)), (::fnv_006c2050::S2f850 *)(::fnv_006c5190::QArrX *)(&kArr)))
                    {
                        for (unsigned j = 0; j < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(kArr))->GetName())); j++)
                        {
                            reinterpret_cast<::ObstacleTaskData *>((((::fnv_006c5190::TblX *)(::fnv_006c5ef0::FUN_006c5ef0((char *)this, ::fnv_006c5ef0::FUN_006c5ef0_arg{(::fnv_006c5ef0::Flt *)(((reinterpret_cast<::FUN_0068efb0_shell *>((((::fnv_006c5190::ElemX *)(::FUN_00559450((int *)&(kArr.FUN_00877a30(j)))))))->FUN_0068efb0())))})))))->AddOperation((const ::NiPointer< ::ObstacleData> &)(((HolderX*)((::fnv_006c5190::ElemX *)(::FUN_00559450((int *)&(spScreenData)))))->arr.FUN_00877a30(i)), (::OBSTACLE_TASK_TYPE)(0x30));
                            reinterpret_cast<::FUN_00438690 *>(&(((::fnv_006c5190::ElemX *)(::FUN_00559450((int *)&(((HolderX*)((::fnv_006c5190::ElemX *)(::FUN_00559450((int *)&(spScreenData)))))
                                ->arr.FUN_00877a30(i)))))
                                ->m78))->FUN_007cb2e0((unsigned int *)&(const int &)(((int)(reinterpret_cast<::FUN_0068efb0_shell *>((((::fnv_006c5190::ElemX *)(::FUN_00559450((int *)&(kArr.FUN_00877a30(j)))))))->FUN_0068efb0()))));
                        }
                    }
                }
                reinterpret_cast<::NiTMap_S *>(&(m100))->RemoveKey(reinterpret_cast<::FUN_0084e3a0_Class *>((pkObj))->FUN_0084e3a0());
                reinterpret_cast<::Map6920 *>(&(m110))->FUN_006c6920(reinterpret_cast<::FUN_0084e3a0_Class *>((pkObj))->FUN_0084e3a0(), (*(::NiPointer< ::NiAVObject> *)&(const ::fnv_006c5190::PtrX &)(spScreenData)));
                bChanged = true;
            }
            reinterpret_cast<::ItemChangeListNode *>(&(m_kList))->FUN_00905330((*(::InventoryStackRecord *const *)(&pkObj)));
            pkNode = &m_kList;
        }
        else
        {
            pkNode = ((::fnv_006c5190::NodeX *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        }
    }
    return bChanged;
}
}  // namespace fnv_006c5190

namespace s6c3ba0 {

extern const float DAT_0106c3a0;


static const char s_szBadTriangle[] =
    "PATHFINDING: (NavMesh Obstacle Manager) Bad triangle index while trying to reconnect portals";

struct NiPoint3
{
    float x;
    float y;
    float z;

};

struct EdgeVertices
{
    NiPoint3* m_pkStart;
    NiPoint3* m_pkEnd;

    EdgeVertices();
};

struct Triangle
{
};

struct NavMesh
{
    EdgeVertices FUN_0068f040(unsigned short m_usTriangleID, int m_iEdgeNumber);
};

template <class T> class NiPointer
{
  public:
    NiPointer();
    ~NiPointer();

    NiPointer& FUN_0042f4c0(const NiPointer& kOther);
    T* FUN_00458b50() const;
    operator T*() const;

    T* m_pObject;
};

struct NavMeshInfo;

struct Portal
{
    int unk00;
    int unk04;
    int unk08;
};

struct PortalInfo
{
    NavMeshInfo* m_pkInfo;
    unsigned short m_usTriangle;
    int m_iEdge;

    PortalInfo();
    PortalInfo(const Portal* pkPortal);
};

struct EdgeLink
{
    int unk00;
    int m_iID;
    unsigned short m_usTriangle;
};

struct PortalLink
{
    int m_iID;
    unsigned short m_usTriangle;

    PortalLink(int m_uiSoundID, unsigned short m_usTriangleID);
};

struct NavMeshInfo
{
};

struct PortalArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;

    Portal* FUN_006a1440(unsigned int uiIndex);
};

struct PortalSet
{
    PortalArray m_kPortals;
    PortalArray m_kOpenPortals;
};

struct Obstacle
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    NavMeshInfo* m_pkInfo;
    NiPointer<NavMeshInfo> m_spInfo;
    NiPointer<NavMesh> m_spNavMesh;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    PortalSet m_kPortalSet;
    bool m_bValueAt0C;
};

struct ObstacleArray
{
    Obstacle*& FUN_00877a30(unsigned int uiIndex);
};

struct ObstacleManager
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    ObstacleArray m_kObstacles;

    void ConnectEdges(NiPointer<NavMesh>& spMeshA, PortalInfo& kPortalA, NiPointer<NavMesh>& spMeshB,
                      PortalInfo& kPortalB);
    bool MatchPortalEdges();
};

// Checks portal edges across obstacles and open portals, calling connection routines when endpoints are within the squared-distance threshold.
// @fnv 0x006c3ba0
bool ObstacleManager::MatchPortalEdges()
{
    unsigned int ItemUpdateArray = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kObstacles))->GetName()));
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        Obstacle* pkOwner = m_kObstacles.FUN_00877a30(i);
        if (!pkOwner->m_spNavMesh.FUN_00458b50())
            continue;
        PortalSet* pkSet = &pkOwner->m_kPortalSet;
        for (unsigned int j = 0; j < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkSet->m_kPortals))->GetName())); j++)
        {
            PortalInfo kFirstPortal(pkSet->m_kPortals.FUN_006a1440(j));
            if (kFirstPortal.m_usTriangle >= ::FUN_00558200((char *)(((NavMesh*)pkOwner->m_spNavMesh))))
            {
                ::FUN_005b5e40();
                continue;
            }
            NiPoint3 kEdgeStart = *((NavMesh*)pkOwner->m_spNavMesh)
                                       ->FUN_0068f040(kFirstPortal.m_usTriangle, kFirstPortal.m_iEdge)
                                       .m_pkStart;
            NiPoint3 kCornerB = *((NavMesh*)pkOwner->m_spNavMesh)
                                     ->FUN_0068f040(kFirstPortal.m_usTriangle, kFirstPortal.m_iEdge)
                                     .m_pkEnd;
            bool bPortalEdgeMatched = false;
            for (unsigned int k = 0; k < ItemUpdateArray; k++)
            {
                if (k == i)
                    continue;
                Obstacle* pkOtherObstacle = m_kObstacles.FUN_00877a30(k);
                if (!pkOtherObstacle->m_spNavMesh.FUN_00458b50())
                    continue;
                PortalSet* pkOtherPortals = &pkOtherObstacle->m_kPortalSet;
                for (unsigned int l = 0; l < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkOtherPortals->m_kPortals))->GetName())); l++)
                {
                    PortalInfo kOther(pkOtherPortals->m_kPortals.FUN_006a1440(l));
                    if (kOther.m_usTriangle >= ::FUN_00558200((char *)(((NavMesh*)pkOtherObstacle->m_spNavMesh))))
                    {
                        ::FUN_005b5e40();
                        continue;
                    }
                    NiPoint3 kStartA = *((NavMesh*)pkOtherObstacle->m_spNavMesh)
                                            ->FUN_0068f040(kOther.m_usTriangle, kOther.m_iEdge)
                                            .m_pkStart;
                    NiPoint3 kB2 = *((NavMesh*)pkOtherObstacle->m_spNavMesh)
                                        ->FUN_0068f040(kOther.m_usTriangle, kOther.m_iEdge)
                                        .m_pkEnd;
                    if (reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::s6c3ba0::NiPoint3 &)((*(::s6c3ba0::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCornerB))->FUN_00439ef0((::NiPoint3 *)&(kStartA), *(const ::NiPoint3 *)nullptr)))))->GetSquaredXYLength() < DAT_0106c3a0 &&
                        reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::s6c3ba0::NiPoint3 &)((*(::s6c3ba0::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kEdgeStart))->FUN_00439ef0((::NiPoint3 *)&(kB2), *(const ::NiPoint3 *)nullptr)))))->GetSquaredXYLength() < DAT_0106c3a0)
                    {
                        ConnectEdges(pkOwner->m_spNavMesh, kFirstPortal, pkOtherObstacle->m_spNavMesh, kOther);
                        if (1)
                        {
                        }
                        pkOwner->m_bValueAt0C = true;
                        pkOtherObstacle->m_bValueAt0C = true;
                        reinterpret_cast<::FUN_00691c90_shell *>(&(pkSet->m_kPortals))->FUN_00691c90(j, true);
                        j--;
                        reinterpret_cast<::FUN_00691c90_shell *>(&(pkOtherPortals->m_kPortals))->FUN_00691c90(l, true);
                        l--;
                        bPortalEdgeMatched = true;
                        break;
                    }
                }
                if (bPortalEdgeMatched)
                    break;
                if (bPortalEdgeMatched)
                    break;
            }
            if (!bPortalEdgeMatched)
            {
                for (unsigned int m = 0; m < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(pkSet->m_kOpenPortals))->GetName())); m++)
                {
                    PortalInfo kOpenInfo(pkSet->m_kOpenPortals.FUN_006a1440(m));
                    PortalInfo kLinked;
                    if (reinterpret_cast<::NavMeshPortalMgr68F3 *>((((NavMeshInfo*)pkOwner->m_spInfo)))->FUN_0068f340((const ::NavMeshEdgeRef68F3 *)&(kOpenInfo), (::NavMeshEdgeOut68F3 *)&(kLinked)))
                    {
                        if (kOpenInfo.m_pkInfo == kLinked.m_pkInfo)
                            continue;
                        NiPointer<NavMesh> apSearchNavMesh;
                        Obstacle* pkMatched = 0;
                        for (unsigned int n = 0; n < ItemUpdateArray; n++)
                        {
                            if (m_kObstacles.FUN_00877a30(n)->m_pkInfo == kLinked.m_pkInfo)
                            {
                                reinterpret_cast<::NavMeshPtr *>(&(apSearchNavMesh))->operator=((const ::NavMeshPtr &)(m_kObstacles.FUN_00877a30(n)->m_spNavMesh));
                                pkMatched = m_kObstacles.FUN_00877a30(n);
                                break;
                            }
                        }
                        if (!(NavMesh*)apSearchNavMesh)
                        {
                            reinterpret_cast<::NavMeshInfo *>((kLinked.m_pkInfo))->ResolveNavMesh((::NavMeshPtr &)(apSearchNavMesh));
                            pkMatched = 0;
                        }
                        if (!(NavMesh*)apSearchNavMesh)
                        {
                            PortalInfo kInfo2(pkSet->m_kOpenPortals.FUN_006a1440(m));
                            EdgeLink* pkEdge =
                                ((::s6c3ba0::EdgeLink *)(reinterpret_cast<::FUN_0068f230_shell *>((((NavMeshInfo*)pkOwner->m_spInfo)))->FUN_0068f230(kInfo2.m_usTriangle, kInfo2.m_iEdge)));
                            if (pkEdge)
                            {
                                PortalLink kLink(pkEdge->m_iID, pkEdge->m_usTriangle);
                                reinterpret_cast<::FUN_006c4460_cls *>(this)->AddAndRunFromSources((::ObjA *)&(pkOwner->m_spNavMesh), (::SrcB *)&(kFirstPortal), (::SrcC *)&(kLink));
                                if (1)
                                {
                                }
                                reinterpret_cast<::FUN_00691c90_shell *>(&(pkSet->m_kPortals))->FUN_00691c90(j, true);
                                j--;
                                bPortalEdgeMatched = true;
                                break;
                            }
                        }
                        else
                        {
                            if (kLinked.m_usTriangle >= ::FUN_00558200((char *)(((NavMesh*)apSearchNavMesh))))
                                continue;
                            if (reinterpret_cast<::FUN_00691140_shell *>((((::s6c3ba0::Triangle *)(reinterpret_cast<::NavMesh *>((((NavMesh*)apSearchNavMesh)))->GetTriangle(kLinked.m_usTriangle)))))->FUN_00691140(0x20))
                                continue;
                            NiPoint3 kA3 = *((NavMesh*)apSearchNavMesh)
                                                ->FUN_0068f040(kLinked.m_usTriangle, kLinked.m_iEdge)
                                                .m_pkStart;
                            NiPoint3 kB3 = *((NavMesh*)apSearchNavMesh)
                                                ->FUN_0068f040(kLinked.m_usTriangle, kLinked.m_iEdge)
                                                .m_pkEnd;
                            if (reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::s6c3ba0::NiPoint3 &)((*(::s6c3ba0::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCornerB))->FUN_00439ef0((::NiPoint3 *)&(kA3), *(const ::NiPoint3 *)nullptr)))))->GetSquaredXYLength() < DAT_0106c3a0 &&
                                reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::s6c3ba0::NiPoint3 &)((*(::s6c3ba0::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kEdgeStart))->FUN_00439ef0((::NiPoint3 *)&(kB3), *(const ::NiPoint3 *)nullptr)))))->GetSquaredXYLength() < DAT_0106c3a0)
                            {
                                ConnectEdges(pkOwner->m_spNavMesh, kFirstPortal, apSearchNavMesh, kLinked);
                                if (1)
                                {
                                }
                                pkOwner->m_bValueAt0C = true;
                                if (pkMatched)
                                    pkMatched->m_bValueAt0C = true;
                                reinterpret_cast<::FUN_00691c90_shell *>(&(pkSet->m_kPortals))->FUN_00691c90(j, true);
                                j--;
                                bPortalEdgeMatched = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

}

struct LocalLink
{
    unsigned int id;
    unsigned short triangle;
};
struct LocalEdge
{
    LocalLink link;
    int edge;
};
struct LocalConnection
{
    unsigned int unk00;
    LocalLink link;
    LocalConnection();
};
struct LocalTriangle
{
};
struct LocalMesh
{
    unsigned short AddConnection(const LocalConnection&);
};
struct LocalMeshPtr
{
};
struct LocalConnector
{
    bool ConnectEdges(LocalMeshPtr&, const LocalEdge&, LocalMeshPtr&, const LocalEdge&);
};
// Adds cross-referencing connections between two mesh triangles via their edges and returns true.
// @fnv 0x006c4390
bool LocalConnector::ConnectEdges(LocalMeshPtr& first, const LocalEdge& firstEdge, LocalMeshPtr& second,
                                  const LocalEdge& secondEdge)
{
    LocalConnection firstConnection4;
    firstConnection4.link.id = secondEdge.link.id;
    firstConnection4.link.triangle = secondEdge.link.triangle;
    unsigned short firstIndex = ((::LocalMesh *)(::FUN_00559450((int *)&(first))))->AddConnection(firstConnection4);
    reinterpret_cast<::Unk00690e30 *>((((::LocalTriangle *)(reinterpret_cast<::NavMesh *>((((::LocalMesh *)(::FUN_00559450((int *)&(first))))))->GetTriangle(firstEdge.link.triangle)))))->SetSlotValue(firstEdge.edge, firstIndex);
    LocalConnection secondConnection5;
    secondConnection5.link.id = firstEdge.link.id;
    secondConnection5.link.triangle = firstEdge.link.triangle;
    unsigned short secondIndex3 = ((::LocalMesh *)(::FUN_00559450((int *)&(second))))->AddConnection(secondConnection5);
    reinterpret_cast<::Unk00690e30 *>((((::LocalTriangle *)(reinterpret_cast<::NavMesh *>((((::LocalMesh *)(::FUN_00559450((int *)&(second))))))->GetTriangle(secondEdge.link.triangle)))))->SetSlotValue(secondEdge.edge, secondIndex3);
    return true;
}

#include <xmmintrin.h>
namespace fnv_006c4d30 {
struct V3
{
    float x, y, z;
};
struct BodyRef
{
    void* FUN_004b4ec0();
};
struct RigidBody
{
};
struct RigidBodyPtr1920
{
    RigidBody* m_pObject;
};
struct ObstData1920
{
    int unk00;
    int unk04;
    int unk08;
    RigidBodyPtr1920 m_pRigidBody;
    V3 pos;
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
    int unk68;
    int unk6C;
    unsigned int lastUpdate;
};
struct ObstPtr1920
{
    ObstData1920* m_pObject;
    ObstPtr1920(const ObstPtr1920& other);
    ~ObstPtr1920();
};
struct ObstList
{
};
__declspec(align(16)) struct Holder3
{
    __m128 q;
};
struct GlobalObject_0044f440
{
};
struct TimeGlobal
{
};
struct ObsMgr
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
    ObstList list3C;
    void FUN_006c4d30();
};

// For each obstacle, compares a converted vector with its position and calls a method when distance and elapsed-time thresholds are met.
// @fnv 0x006c4d30
void ObsMgr::FUN_006c4d30()
{
    unsigned int uiTimeLimitMs = (unsigned int)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_006c4d30::GlobalObject_0044f440 *>(&::g_011d71b0)))))) * 1000.0);
    for (ObstList* node = &list3C; node && !reinterpret_cast<::ObsList *>((node))->FUN_004a4460();)
    {
        ObstPtr1920 item((*(::fnv_006c4d30::ObstPtr1920 *)((void *)(node))));
        node = ((::fnv_006c4d30::ObstList *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        Holder3 h;
        new ((void *)&(h)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(((::fnv_006c4d30::BodyRef *)(std::uintptr_t)(reinterpret_cast<::FUN_00620b80_shell *>((((::fnv_006c4d30::RigidBody *)(::FUN_00559450((int *)&(((::fnv_006c4d30::ObstData1920 *)(::FUN_00559450((int *)&(item))))->m_pRigidBody))))))->GetReferenceFlags()))->FUN_004b4ec0())));
        V3 v;
        ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&v)), (*(const ::hkVector4 *)(&h)));
        V3 tmp;
        if (reinterpret_cast<::TESCombatStyle *>((((::fnv_006c4d30::V3 *)(reinterpret_cast<::FUN_00439ef0_class *>(&(v))->FUN_00439ef0((::NiPoint3 *)(::fnv_006c4d30::V3 *)(&tmp), (*(const ::NiPoint3 *)(&((::fnv_006c4d30::ObstData1920 *)(::FUN_00559450((int *)&(item))))->pos)))))))->UpdateCombatStyle() > kObsDist &&
            reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::fnv_006c4d30::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() - ((::fnv_006c4d30::ObstData1920 *)(::FUN_00559450((int *)&(item))))->lastUpdate >= uiTimeLimitMs)
            reinterpret_cast<::ObstacleMgrX *>(this)->FUN_006c1760((*(const ::ObstPtrX *)(&item)));
    }
}
}  // namespace fnv_006c4d30

static const float s_fDefaultInterval = 0.5f;

// Initializes the NavMeshObstacleManager, setting up task queues, timers, and default update interval.
// @fnv 0x006c02c0
FUN_006c02c0::FUN_006c02c0()
    : m_kTasks(0x25), m_kAddQueue(7, 8), m_kRemoveQueue(7, 8), m_kObstacles(0x25), m_kTasksB(0x25), m_kTasksC(0x25),
      m_kRefMap(0x25), m_spTask(0), m_kUpdateTimer("Pathing", "Obstacle Manager Update", 1, 1),
      m_kBackgroundTimer("Pathing", "Navmesh Background Update", 0, 1)
{
    AutoMemContext kMemContext(
        MEM_CONTEXT_MEM_CONTEXT_NAVMESH, true,
        "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshObstacleManager.cpp", 0xb8);
    m_iCount120 = 0;
    m_iCount124 = 0;
    m_bPaused = false;
    m_iTask190 = 0;
    m_fInterval = s_fDefaultInterval;
    m_bModifierActive = false;
}

namespace fnv_006c0720 {
struct AutoMemContextScope
{
    int m_eMemoryContext;
    AutoMemContextScope(int, bool, const char*, int);
    ~AutoMemContextScope();
};
struct NavMeshObstacleManagerObj
{
    unsigned char data[0x1c0];
    NavMeshObstacleManagerObj();
    ~NavMeshObstacleManagerObj();
};
// Returns the address of a function-local static NavMeshObstacleManagerObj after creating an AutoMemContextScope.
// @fnv 0x006c0720
NavMeshObstacleManagerObj* GetNavMeshObstacleManager()
{
    AutoMemContextScope tempMemContext(
        0x2e, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshObstacleManager.cpp",
        0xd2);
    static NavMeshObstacleManagerObj kInstance;
    return &kInstance;
}
}  // namespace fnv_006c0720

namespace fnv_006c5ff0 {
struct FUN_006c6e60_shell
{
};
struct FUN_006c5ff0_shell
{
    char _pad0[32];
    RecursiveSpinLock _lock20;
    FUN_006c6e60_shell* FUN_00449f80(int*);
    void FUN_006c5ff0(int*);
};
// Locks _lock20, calls Push on the object returned by FUN_00449f80(a1), then unlocks _lock20.
// @fnv 0x006c5ff0
void FUN_006c5ff0_shell::FUN_006c5ff0(int* a1)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(_lock20))->FUN_0040fbf0((char *)(0));
    reinterpret_cast<::fnv_006c6e60::TSQueueHandle *>((FUN_00449f80(a1)))->Push(*(const int *)nullptr);
    reinterpret_cast<::RecursiveSpinLock *>(&(_lock20))->FUN_0040fba0();
}
}  // namespace fnv_006c5ff0

struct PendingRefs0c80
{
    ::TESObjectREFR* item;
    PendingRefs0c80* next;
};

struct RemovedIDs0c80
{
    unsigned int item;
    RemovedIDs0c80* next;
    bool IsInList(const unsigned int& item);
    void AddTail(const unsigned int& item);
};

struct ReferenceMap0c80
{
    void* vtable;
    unsigned int bucketCount;
    void* buckets;
    unsigned int count;
};

struct RemoveObstacleManagerView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    ReferenceMap0c80 references;
    PendingRefs0c80 pending;
    RemovedIDs0c80 removed;
    void FUN_006c0c80(::TESObjectREFR* ref);
};

// Adds ref to pending; if its FormID is not removed and has a map entry, processes each obstacle and records the FormID.
// @fnv 0x006c0c80
void RemoveObstacleManagerView::FUN_006c0c80(::TESObjectREFR* ref)
{
    if (!reinterpret_cast< ::SettingT< ::INISettingCollection>*>(&::g_011d73e4)->Bool()->b)
        return;
    reinterpret_cast<::ItemChangeListNode *>(&(pending))->FUN_00905330((*(::InventoryStackRecord *const *)(&ref)));
    if (!reinterpret_cast<::RefList *>(&(removed))->FUN_005f65d0((void **)&(const unsigned int &)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast< ::TESForm*>(ref)))->FUN_0084e3a0())))))
    {
        ::RefObstPtr1920 spArray(0);
        unsigned int i;
        if (reinterpret_cast<::Map62d0 *>(&(references))->FUN_006c62d0(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast< ::TESForm*>(ref)))->FUN_0084e3a0())), (void **)&(spArray)))
        {
            for (i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((::RefObstData1920 *)(::FUN_00559450((int *)&(spArray))))->kObstacles))->GetName())); i++)
                reinterpret_cast< ::S_this*>(this)->FUN_006c1e00(
                    static_cast< ::S_param*>(((void *)(::FUN_00559450((int *)&(((::ObstData1920 *)(::FUN_00559450((int *)&(((::RefObstData1920 *)(::FUN_00559450((int *)&(spArray))))->kObstacles.GetAt(i)))))->m_pRigidBody))))));
            reinterpret_cast<::Callees *>(&(removed))->FUN_00905820((void *)&(const unsigned int &)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast< ::TESForm*>(ref)))->FUN_0084e3a0()))));
        }
    }
}

struct V3
{
    float x, y, z;
};

struct S006c4ad0_Obs
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    V3 pos;
};

struct S006c4ad0_Ptr
{
    S006c4ad0_Obs* p;
    S006c4ad0_Ptr(S006c4ad0_Obs* q);
    void FUN_0045cec0();
    ~S006c4ad0_Ptr();
};

struct S006c4ad0_Body;

struct S006c4ad0_Ref2
{
    void* FUN_004b4ec0();
};

struct S006c4ad0_Queue
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual unsigned int Count();
};

struct S006c4ad0_Body
{
};

struct S006c4ad0_Map
{
};

struct S006c4ad0_List
{
};

__declspec(align(16)) struct S006c4ad0_Holder3
{
    __m128 q;
};

struct ObsMgr_nogf
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
    S006c4ad0_List list3C;
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
    S006c4ad0_Queue queueA0;
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    S006c4ad0_Map mapE0;
    void FUN_006c4ad0();
};

// @fnv 0x006c4ad0
void ObsMgr_nogf::FUN_006c4ad0()
{
    unsigned int count = queueA0.Count();
    for (unsigned int i = 0; i < count; i++)
    {
        S006c4ad0_Body* body;
        reinterpret_cast<::C006c6030 *>(&(queueA0))->FUN_006c6030(&body);
        S006c4ad0_Ptr sp(0);
        if (reinterpret_cast<::Map62d0 *>(&(mapE0))->FUN_006c62d0((std::uintptr_t)(body), (void **)(::S006c4ad0_Ptr *)(&sp)))
        {
            S006c4ad0_Holder3 h;
            new ((void *)&(h)) ::FUN_004a3c90((*(const ::FUN_004a3c90 *)(((::S006c4ad0_Ref2 *)(std::uintptr_t)(reinterpret_cast<::FUN_00620b80_shell *>((body))->GetReferenceFlags()))->FUN_004b4ec0())));
            V3 v;
            ::SetNiPoint3FromHkVector4((*(::NiPoint3 *)(&v)), (*(const ::hkVector4 *)(&h)));
            V3 tmp;
            if (reinterpret_cast<::TESCombatStyle *>((((::V3 *)(reinterpret_cast<::FUN_00439ef0_class *>(&(v))->FUN_00439ef0((::NiPoint3 *)(::V3 *)(&tmp), (*(const ::NiPoint3 *)(&((::S006c4ad0_Obs *)(::FUN_00559450((int *)&(sp))))->pos)))))))->UpdateCombatStyle() > ::fnv_006c4d30::kObsDist)
                reinterpret_cast<::ObstacleMgrX *>(this)->FUN_006c1760((*(const ::ObstPtrX *)(&sp)));
            reinterpret_cast<::ListReader *>(&(list3C))->FUN_00631620((*(const ::NodeValue *)(&sp)));
        }
    }
}

int __cdecl FUN_00ec658f(void(__cdecl* fn)());

struct ArrayHolderBase
{
    virtual void Unk_00();
    int m_04;
    void* m_08;
    unsigned int m_0C;
    bool m_10;
    ArrayHolderBase()
    {
        m_04 = 0x25;
        m_0C = 0;
        m_08 = FUN_00aa1070(m_04 * 4);
        std::memset(m_08, 0, m_04 * 4);
        m_10 = true;
    }
};

struct ArrayHolder : ArrayHolderBase
{
    virtual ~ArrayHolder()
    {
        m_10 = false;
    }
};

// @fnv 0x00b61890
ArrayHolder* __cdecl FUN_00b61890()
{
    static ArrayHolder obj;
    return &obj;
}

#include "generated/data/fallout_shared/pathfinding/navmeshobstaclemanager.inc"
