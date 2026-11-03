
// Shared classes come from the canonical include/ headers: TESForm/TESObjectREFR/MobileObject/Actor (PC virtual
// slots), SETTING_VALUE. Explicit ../../../include/ paths (src/fallout_shared shadows layout_support.h, TESForm.h...).
// Unit-local templates (navmeshobstaclemanager_local_types.h) keep the API matched code calls out of line and the
// canonical headers lack (BSSimpleArray Add/Clear/Remove/Find, BSSimpleList Remove/IsInList/AddTail(const T&),
// NiTPointerMap::RemoveAll, NiTArray::GetAt, NiPointer copy ctor); the canonical ones are renamed away.
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "navmeshobstaclemanager_local_types.h"
#define NiPointer FNV_NiPointer_Canonical
#define BSSimpleList FNV_BSSimpleList_Canonical
#define BSSimpleArray FNV_BSSimpleArray_Canonical
#define NiTPointerMap FNV_NiTPointerMap_Canonical
#define NiTArray FNV_NiTArray_Canonical
#include "../../../include/layout_support.h"
#include "../../../include/TESObjectREFR.h"
#include "../../../include/Actor.h"
#undef NiTArray
#undef NiTPointerMap
#undef BSSimpleArray
#undef BSSimpleList
#undef NiPointer
#include "../../../include/SETTING_VALUE.h"
class TESObjectREFR;
class AnimIdle;
class ObstacleData;
class ObstacleTaskData;
class NavMeshInfo;
class RecursiveSpinLock
{
  public:
    volatile unsigned int m_uiOwningThreadID;
    unsigned int m_uiRecursionCount;
public:
    void FUN_0040fba0();
};
class NavMeshObstacleManager
{
  public:
    unsigned char layoutPadding0[0x1C];
    NiTPointerMap<void*, NiPointer<ObstacleData> > m_kObstacleMap;     // +0x1C
    unsigned char layoutPadding2C[0x8];
    BSSimpleList<void*> m_kPendingList;                                 // +0x34
    BSSimpleList<NiPointer<ObstacleData> > m_kActivatedObstacles;      // +0x3C
    unsigned char layoutPadding44[0xE8];
    NiTPointerMap<unsigned int, ObstacleTaskData*> m_kTaskMap;          // +0x12C
    BSSimpleArray<ObstacleTaskData*, 1024> m_kBackgroundTasks;         // +0x13C
    BSSimpleArray<ObstacleTaskData*, 1024> m_kProcessedTasks;          // +0x14C
    FNV_ALIGN(32) RecursiveSpinLock m_kTaskLock;                       // +0x160
    void AddProcessedTask(ObstacleTaskData*);
    void ClearObstacles();
    void RemoveObstaclesForReference(unsigned int);
    bool ProcessObstacleTask(ObstacleTaskData*);
public:
    unsigned int GetProcessedTaskCount();
public:
    unsigned int GetBackgroundTaskCount();
public:
    void ProcessActivatedObstacles();
};
class SandboxProcedureData;
class TESObjectREFR;
template <class T> class NiTNewInterface;
class ObstacleData;
enum OBSTACLE_TASK_TYPE;
template <class> class NiPointer;
class ObstacleTaskData
{
  public:
    virtual ~ObstacleTaskData();
    virtual void vfn_04();
    virtual void Run();
public:
    bool AddOperation(const ::NiPointer< ::ObstacleData> &, ::OBSTACLE_TASK_TYPE);
};
class TESFile;
class BGSReconstructFormsInFileMap;
class BGSReconstructFormsInAllFilesMap
{
  public:
    void* GetFirstPos();
    void GetNext(void*&, TESFile*&, BGSReconstructFormsInFileMap*&);
};
class INISettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
class GlobalObject_0045cf30
{
};
extern GlobalObject_0045cf30 g_011d71a0;
class BGSPerkEntry;
class ActorCause;
class BGSCameraShot;
class bhkRigidBody;
class ObstacleData;
class AnimIdle;
template <class K, class V> class NiTMapItem;
template <class T> class DFALL;
template <class A, class K, class V> class NiTMapBase
{
  public:
    bool GetAt(K, V&) const;
    bool RemoveAt(K);
    void SetAt(K, V);
};
