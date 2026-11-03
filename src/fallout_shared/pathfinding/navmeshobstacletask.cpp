// fallout_shared/pathfinding/navmeshobstacletask.cpp: ObstacleTaskData, BSTaskletData, DelStandIn, ObstacleTaskShell (15 functions)

#include "fnv/decl/ActorMover.h"
#include "fnv/decl/FUN_004b0460_class.h"
#include "fnv/decl/FUN_00558dd0_class.h"
#include "fnv/decl/FUN_005a8040_class.h"
#include "fnv/decl/FUN_006c78f0_Class.h"
#include "fnv/decl/FUN_006c8980_stand.h"
#include "fnv/decl/FUN_006c8a30_Class.h"
#include "fnv/decl/FUN_006c8a90_Class.h"
#include "fnv/decl/FUN_006c8b90_Class.h"
#include "fnv/decl/FUN_006c8bd0_Class.h"
#include "fnv/decl/FUN_006c8c70_Class.h"
#include "fnv/decl/FUN_006f3170_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00869600_Class.h"
#include "fnv/decl/FUN_00b00ec0.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/NavShell2.h"
#include "fnv/decl/Struct6c89e0.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_006995c0__FUN_006995c0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_006c7000.h"
#include "fnv/symbols_006f3000.h"
#include "fnv/symbols_0070e000.h"
#include "navmeshobstacletask_decls.h"
struct BaseT
{
    virtual ~BaseT();
    int b[6];
};
struct M34
{
    int x[4];
    ~M34();
};
struct M24
{
    int x[2];
    ~M24();
};
struct FUN_006c79a0 : public BaseT
{
    NavMeshPtr a;
    NavMeshPtr b2;
    M24 c;
    int pad[2];
    M34 d;
    virtual ~FUN_006c79a0();
};
// Destructor for a structure holding two NavMeshPtr members and two small sub-objects; the body is empty.
// @fnv 0x006c79a0
FUN_006c79a0::~FUN_006c79a0()
{}

struct NiNodeHolder
{
    NiNode* p;
    ~NiNodeHolder();
};
struct FUN_006c7e00
{
    NiNodeHolder node;
    int pad[2];
    NavMeshPtr mesh;
    ~FUN_006c7e00();
};
// @fnv 0x006c7e00
FUN_006c7e00::~FUN_006c7e00()
{}

struct FUN_006c8150_shell : public ObstacleTaskData
{
    void FUN_006c8150();
};


struct Helper_006c8980
{
};

// @fnv 0x006c8150
void FUN_006c8150_shell::FUN_006c8150()
{
    reinterpret_cast<::FUN_006c8980_stand *>((((Helper_006c8980*)((char*)this + 0x24))))->FUN_006c8980((std::intptr_t)(((void (&)())::CompareObstacleEntries)));
}

struct Elem16
{
    int a[4];
};
struct Arr16
{
    int pad;
    Elem16* data;
    unsigned int AppendValue(std::intptr_t value);
};
// Appends a new element at the end of the array, initializes it with the given value, and returns its index.
// @fnv 0x006c8810
unsigned int Arr16::AppendValue(std::intptr_t value)
{
    unsigned int index = ::FUN_006f31f0((::S5460 *)this);
    reinterpret_cast<::FUN_006c8a90_Class *>(this)->InitializeArray((char *)(::Elem16 *)(&data[index]), 1);
    reinterpret_cast<::Struct6c89e0 *>(&(data[index]))->AssignFrom((const ::Struct6c89e0 *)(value));
    return index;
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_006c7970(unsigned int flags);
};
// Runs the destructor on this object, then frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x006c7970
void* DelStandIn::FUN_006c7970(unsigned int flags)
{
    reinterpret_cast<::FUN_006c79a0 *>((((DtorStandIn*)this)))->::FUN_006c79a0::~FUN_006c79a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}


struct BSTaskletData
{
    virtual ~BSTaskletData();
    void* DestroyIfFlagged(unsigned int);
    void FUN_006c78f0();
};

void BSTaskletData::FUN_006c78f0()
{}

// Calls FUN_006c78f0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x006c7910
void* BSTaskletData::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_006c78f0_Class *>(this)->FUN_006c78f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_006c7940 {
struct BaseT
{
    virtual ~BaseT();
};
struct FUN_006c7940_shell : BaseT
{
    void* FUN_006c7940(unsigned int flags);
};
// Runs the base destructor, frees this when bit 0 of flags is set, and returns this.
// @fnv 0x006c7940
void* FUN_006c7940_shell::FUN_006c7940(unsigned int flags)
{
    reinterpret_cast<::FUN_00b00ec0 *>(this)->::FUN_00b00ec0::~FUN_00b00ec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_006c7940

struct FUN_006c85c0_shell
{
    char* GetCharPtrAtOffset();
};
// @fnv 0x006c8170
void ObstacleTaskData::Process()
{
    AutoMemContext context(MEM_CONTEXT_NAVMESH, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\NavMeshObstacleTask.c",
                           357);
    reinterpret_cast<::TESForm *>((((::LockPrimitive *)(reinterpret_cast<::FUN_006c85c0_shell *>((((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->GetCharPtrAtOffset()))))->ClearData();
    if (pInfo->ResolveNavMesh(m_spSourceNavMesh))
    {
        m_spWorkingNavMesh = reinterpret_cast<NavMeshPtr(__cdecl*)(NavMesh*)>(&MakeNavMeshPointer)(new NavMesh);
        NAVMESH_FROM(m_spSourceNavMesh)->CopyNavMeshDataTo(m_spWorkingNavMesh);
        reinterpret_cast<::FUN_006c8150_shell *>(this)->FUN_006c8150();
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(Operations))->GetName())); ++i)
        {
            switch (OPERATION_AT(Operations, i).eType)
            {
            case ADD:
            case ADD_UPDATE:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->Search(OPERATION_AT(Operations, i).m_spRegisteredObstacle, m_kParentChildLinks))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            case REMOVE:
            case REMOVE_UPDATE:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->RemoveObstacleAndUpdateLinks(OPERATION_AT(Operations, i).m_spRegisteredObstacle, m_kParentChildLinks))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            case REMOVE_DOOR:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->RemoveDoorObstacle(OBSTACLE_FROM(OPERATION_AT(Operations, i).m_spRegisteredObstacle)->source->id))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            case ADD_DOOR:
                if (NAVMESH_FROM(m_spWorkingNavMesh)
                        ->AddDoorObstacle(OBSTACLE_FROM(OPERATION_AT(Operations, i).m_spRegisteredObstacle)->source->id,
                                          OBSTACLE_FROM(OPERATION_AT(Operations, i).m_spRegisteredObstacle)))
                    OPERATION_AT(Operations, i).m_kResult = 0;
                else
                    OPERATION_AT(Operations, i).m_kResult = 1;
                break;
            }
        }
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kParentChildLinks.parents))->GetName())); ++i)
            EDGE_AT(m_kParentChildLinks.parents, i).pInfo = pInfo;
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kParentChildLinks.children))->GetName())); ++i)
            EDGE_AT(m_kParentChildLinks.children, i).pInfo = pInfo;
    }
    else
    {
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(Operations))->GetName())); ++i)
            OPERATION_AT(Operations, i).m_kResult = 1;
    }
    ((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))->AddProcessedTask(this);
    reinterpret_cast<::TESForm *>((((::LockPrimitive *)(reinterpret_cast<::FUN_006c85c0_shell *>((((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->GetCharPtrAtOffset()))))->ClearData();
}

// @fnv 0x006c85c0
char* FUN_006c85c0_shell::GetCharPtrAtOffset()
{
    return reinterpret_cast<char*>(this) + 0x1A1;
}

extern int DAT_0106c8d4;
struct S_006c87c0
{
    S_006c87c0* FUN_006c87c0();
};
// Sets the object's vtable pointer to DAT_0106c8d4, calls FUN_006c8c70(0, 0), and returns this.
// @fnv 0x006c87c0
S_006c87c0* S_006c87c0::FUN_006c87c0()
{
    *(int*)this = (int)&DAT_0106c8d4;
    reinterpret_cast<::FUN_006c8c70_Class *>(this)->FUN_006c8c70(0, 0);
    return this;
}

extern int DAT_0106c8d4;
struct FUN_006c87f0_shell
{
    void* vftable;
    void FUN_006c87f0();
};
// @fnv 0x006c87f0
void FUN_006c87f0_shell::FUN_006c87f0()
{
    vftable = &DAT_0106c8d4;
    reinterpret_cast<::FUN_006c8a30_Class *>(this)->FUN_006c8a30(1);
}

struct ObstacleMeshView
{
};

struct ObstacleMeshRef
{
    ObstacleMeshView* ptr;
    ObstacleMeshRef(const NavMeshPtr& other);
    ~ObstacleMeshRef();
    ObstacleMeshView* Get();
    ObstacleMeshView* operator->() const;
};

// @fnv 0x006c7e60
int __cdecl CompareObstacleEntries(const void* apEntryA, const void* apEntryB)
{
    const ObstacleTask* a = (const ObstacleTask*)apEntryA;
    const ObstacleTask* b = (const ObstacleTask*)apEntryB;
    switch (a->eType)
    {
    case REMOVE_DOOR:
        if (b->eType == REMOVE_DOOR)
            return 0;
        else
            return -1;
        break;
    case ADD_DOOR:
        if (b->eType == ADD_DOOR)
            return 0;
        else
            return 1;
        break;
    case ADD:
    case ADD_UPDATE:
        switch (b->eType)
        {
        case REMOVE_DOOR:
            return 1;
            break;
        case ADD_DOOR:
            return -1;
            break;
        case ADD:
        case ADD_UPDATE:
            return a->m_spRegisteredObstacle->source->id - b->m_spRegisteredObstacle->source->id;
            break;
        case REMOVE:
        case REMOVE_UPDATE:
            return 1;
            break;
        }
        break;
    case REMOVE:
    case REMOVE_UPDATE:
        switch (b->eType)
        {
        case REMOVE_DOOR:
            return 1;
            break;
        case ADD_DOOR:
            return -1;
            break;
        case ADD:
        case ADD_UPDATE:
            return -1;
            break;
        case REMOVE:
        case REMOVE_UPDATE: {
            ObstacleMeshRef mesh(a->apSearchNavMesh);
            if (mesh.Get())
            {
                int ia = reinterpret_cast<::fnv_006995c0::FUN_006995c0_shell *>(((mesh).operator->()))->FindEntryIndex((void *)(a));
                int ib = reinterpret_cast<::fnv_006995c0::FUN_006995c0_shell *>(((mesh).operator->()))->FindEntryIndex((void *)(b));
                return ib - ia;
            }
            else
            {
                return 0;
            }
        }
        }
        break;
    }
    return 0;
}

struct Element16
{
    int a;
    int b;
    int c;
    int d;
};
class FUN_006c8860_Class
{
  public:
    virtual void v0();
    virtual Element16* Allocate(unsigned int);
    Element16* data;
    unsigned int size;
    unsigned int capacity;
    void RemoveAt(unsigned int index, bool shrink);
};
// Validates the operation against existing entries by type, then appends it to Operations if the navmesh is available.
// @fnv 0x006c7a30
bool ObstacleTaskData::AddOperation(const NiPointer<ObstacleData>& obstacle, OBSTACLE_TASK_TYPE type)
{
    switch (type)
    {
    case REMOVE:
    case REMOVE_UPDATE: {
        bool bCanAdd = true;
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(Operations))->GetName())); ++i)
        {
            if (reinterpret_cast<::FUN_004b0460_class *>((void *)&(const ::NiPointer< ::NiAVObject> &)(reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle)))->FUN_004b0460((const void **)&(reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))))
            {
                if ((OPERATION_AT(Operations, i).eType & 0x30) == ADD)
                {
                    reinterpret_cast<void(__cdecl*)(const char*, ...)>(&((void (&)(BGSLoadGameBuffer *))::FUN_0040fbe0))(
                        "Removing previous operation ADD for Task on Navmesh 0x%08x (srcptr = 0x%08x)", pInfo->id,
                        m_spSourceNavMesh.ptr);
                    reinterpret_cast<::FUN_006c8860_Class *>(&(Operations))->RemoveAt(i, true);
                    --i;
                }
                else
                    bCanAdd = false;
            }
        }
        if (!bCanAdd)
            return false;
        break;
    }
    case ADD:
    case ADD_UPDATE: {
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(Operations))->GetName())); ++i)
        {
            if (reinterpret_cast<::FUN_004b0460_class *>((void *)&(const ::NiPointer< ::NiAVObject> &)(reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle)))->FUN_004b0460((const void **)&(reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))))
            {
                if ((OPERATION_AT(Operations, i).eType & 0x30) == ADD)
                    return false;
            }
        }
        break;
    }
    case ADD_DOOR: {
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(Operations))->GetName())); ++i)
        {
            if (reinterpret_cast<::FUN_004b0460_class *>((void *)&(const ::NiPointer< ::NiAVObject> &)(reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle)))->FUN_004b0460((const void **)&(reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))))
            {
                if (OPERATION_AT(Operations, i).eType == ADD_DOOR)
                    return false;
            }
        }
        break;
    }
    case REMOVE_DOOR: {
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(Operations))->GetName())); ++i)
        {
            if (reinterpret_cast<::FUN_004b0460_class *>((void *)&(const ::NiPointer< ::NiAVObject> &)(reinterpret_cast<const NiPointer<NiAVObject>&>(OPERATION_AT(Operations, i).m_spRegisteredObstacle)))->FUN_004b0460((const void **)&(reinterpret_cast<const NiPointer<NiAVObject>&>(obstacle))))
            {
                if (OPERATION_AT(Operations, i).eType == REMOVE_DOOR)
                    return false;
            }
        }
        break;
    }
    default:
        return false;
    }
    NavMeshPtr navMesh;
    if (pInfo->ResolveNavMesh(navMesh))
    {
        reinterpret_cast<::Arr16 *>(&(Operations))->AppendValue((std::intptr_t)&(const ::ObstacleTask &)(ObstacleTask(obstacle, type, navMesh)));
        return true;
    }
    else
    {
        return false;
    }
}
// Removes the element at index, optionally reallocating a smaller buffer first, then shifts the remaining elements down and decrements size.
// @fnv 0x006c8860
void FUN_006c8860_Class::RemoveAt(unsigned int index, bool shrink)
{
    if (shrink && reinterpret_cast<::FUN_006f3170_Class *>(this)->FUN_006f3170())
    {
        unsigned int uiNewCapacity = reinterpret_cast<::FUN_00869600_Class *>(this)->FUN_00869600();
        Element16* pNewData = Allocate(uiNewCapacity);
        reinterpret_cast<::FUN_006c8bd0_Class *>(this)->FUN_006c8bd0((const char *)(pNewData), (const char *)(data), index);
        reinterpret_cast<::FUN_006c8b90_Class *>(this)->FUN_006c8b90((::S16_6c8d00 *)(::Element16 *)(data + index), 1);
        reinterpret_cast<::FUN_006c8bd0_Class *>(this)->FUN_006c8bd0((const char *)(::Element16 *)(pNewData + index), (const char *)(const ::Element16 *)(data + index + 1), size - 1);
        ::FUN_006a8500((::DummyClass_006a8500 *)this);
        data = pNewData;
        capacity = uiNewCapacity;
    }
    else
    {
        reinterpret_cast<::FUN_006c8b90_Class *>(this)->FUN_006c8b90((::S16_6c8d00 *)(::Element16 *)(data + index), 1);
        reinterpret_cast<::FUN_006c8bd0_Class *>(this)->FUN_006c8bd0((const char *)(::Element16 *)(data + index), (const char *)(const ::Element16 *)(data + index + 1), size - index - 1);
    }
    size = size - 1;
}

struct ObstacleMesh;
struct ObstacleMeshHandle
{
    ObstacleMesh* ptr;
    ObstacleMeshHandle(const ObstacleMeshHandle&);
    ~ObstacleMeshHandle();
    operator ObstacleMesh*() const;
    ObstacleMesh* Get();
};
struct ObstacleCellChild
{
    void FUN_0069bb00(ObstacleMeshHandle);
};
struct ObstacleCell
{
};
struct ObstacleMesh
{
};
struct ObstacleOperation
{
    int unk00;
    int unk04;
    unsigned int m_kResult;
};
struct ObstacleOperationArray
{
};
struct ObstacleInfo
{
};
struct ObstacleTaskShell
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ObstacleInfo* pInfo;
    ObstacleMeshHandle m_spSourceNavMesh;
    ObstacleMeshHandle m_spWorkingNavMesh;
    ObstacleOperationArray Operations;
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
    bool bForce;
    bool FUN_006c85e0();
};

// @fnv 0x006c85e0
bool ObstacleTaskShell::FUN_006c85e0()
{
    if (!(ObstacleMesh*)m_spSourceNavMesh)
        return false;
    if (!(ObstacleMesh*)m_spWorkingNavMesh)
        return false;
    bool bFound = false;
    if (!bForce)
    {
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(Operations))->GetName())); i++)
        {
            if (((::ObstacleOperation *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>(&(Operations))->FUN_00558dd0(i)))->m_kResult == 0)
            {
                bFound = true;
                break;
            }
        }
    }
    else
    {
        bFound = true;
    }
    if (bFound)
    {
        unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ObstacleMesh*)m_spSourceNavMesh)))->FUN_0084e3a0()));
        ObstacleCell* pCell = ((::ObstacleCell *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((((ObstacleMesh*)m_spSourceNavMesh)))->GetCurrentMoveModeType()));
        if (pCell)
        {
            reinterpret_cast<::NavShell2 *>((((::ObstacleCellChild *)(::FUN_0070ec90((char *)(pCell))))))->FUN_00469500((*(::NavMeshPtr *)&(const ::ObstacleMeshHandle &)(m_spWorkingNavMesh)));
            ((::ObstacleCellChild *)(::FUN_0070ec90((char *)(pCell))))->FUN_0069bb00(m_spSourceNavMesh);
        }
        reinterpret_cast<::NavMesh *>((((ObstacleMesh*)m_spSourceNavMesh)))->ForceSetFormID(0);
        reinterpret_cast<::HX *>((((ObstacleMesh*)m_spSourceNavMesh)))->FUN_006d3100((::CombatCoverPointData *)(::NavMeshInfo *)(0));
        reinterpret_cast<::NavMesh *>((((ObstacleMesh*)m_spWorkingNavMesh)))->ForceSetFormID(formID);
        reinterpret_cast<::HX *>((((ObstacleMesh*)m_spWorkingNavMesh)))->FUN_006d3100((::CombatCoverPointData *)(::NavMeshInfo *)((NavMeshInfo*)pInfo));
        reinterpret_cast<::FUN_005a8040_class *>((pInfo))->SetField54((std::intptr_t)(m_spWorkingNavMesh.Get()));
        return true;
    }
    else
    {
        return false;
    }
}
