// fallout_shared/pathfinding/pathfind.cpp: Pathing, ActorDeletionQueue, PathBuilder, ArrHelper and more (87 functions)

#include "fnv_result_slot.h"
#include <cstddef>
#include <new>
#include <cstring>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/Array6daf.h"
#include "fnv/decl/AvoidNodeList.h"
#include "fnv/decl/B690770Object.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Cell54D.h"
#include "fnv/decl/DoorSearchInit.h"
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00438b90_class.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_004410d0_Class.h"
#include "fnv/decl/FUN_00453980_shell.h"
#include "fnv/decl/FUN_00459470_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00476be0_Class.h"
#include "fnv/decl/FUN_0048ee50_Class.h"
#include "fnv/decl/FUN_0049f3c0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00508050_Class.h"
#include "fnv/decl/FUN_00557d30_class.h"
#include "fnv/decl/FUN_00558dd0_class.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_005eeda0_this.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00639aa0_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00644a50_shell.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_0068f200_shell.h"
#include "fnv/decl/FUN_0068f230_shell.h"
#include "fnv/decl/FUN_00691040_shell.h"
#include "fnv/decl/FUN_00691140_shell.h"
#include "fnv/decl/FUN_006969e0_shell.h"
#include "fnv/decl/FUN_00697670_StandIn.h"
#include "fnv/decl/FUN_0069b940_class.h"
#include "fnv/decl/FUN_0069dec0_class.h"
#include "fnv/decl/FUN_006a9520_Class.h"
#include "fnv/decl/FUN_006aabf0_shell.h"
#include "fnv/decl/FUN_006ab4a0_shell.h"
#include "fnv/decl/FUN_006abb90_shell.h"
#include "fnv/decl/FUN_006ac340_shell.h"
#include "fnv/decl/FUN_006b0570_shell.h"
#include "fnv/decl/FUN_006b3160_shell.h"
#include "fnv/decl/FUN_006b3f40_Class.h"
#include "fnv/decl/FUN_006c93f0_Object.h"
#include "fnv/decl/FUN_006c9fa0_shell.h"
#include "fnv/decl/FUN_006cee30_Class.h"
#include "fnv/decl/FUN_006cef10_shell.h"
#include "fnv/decl/FUN_006d1be0_Class.h"
#include "fnv/decl/FUN_006d1c00_Class.h"
#include "fnv/decl/FUN_006d1c20_Class.h"
#include "fnv/decl/FUN_006d1c40_Class.h"
#include "fnv/decl/FUN_006d2c20_Class.h"
#include "fnv/decl/FUN_006d2c60_Class.h"
#include "fnv/decl/FUN_006d3ac0_Class.h"
#include "fnv/decl/FUN_006d61b0_Class.h"
#include "fnv/decl/FUN_006dad40_Class.h"
#include "fnv/decl/FUN_006daeb0_Class.h"
#include "fnv/decl/FUN_006db140_Class.h"
#include "fnv/decl/FUN_006dba30_Class.h"
#include "fnv/decl/FUN_006dbcf0_Class.h"
#include "fnv/decl/FUN_006dc070_Class.h"
#include "fnv/decl/FUN_006dc440_Class.h"
#include "fnv/decl/FUN_006dc590.h"
#include "fnv/decl/FUN_006dd3e0_shell.h"
#include "fnv/decl/FUN_006dd460.h"
#include "fnv/decl/FUN_006dd4d0_shell.h"
#include "fnv/decl/FUN_006e12c0_Class.h"
#include "fnv/decl/FUN_006e1770_shell.h"
#include "fnv/decl/FUN_006e22d0_Class.h"
#include "fnv/decl/FUN_006e4500_class.h"
#include "fnv/decl/FUN_006e78b0_shell.h"
#include "fnv/decl/FUN_006e7970_shell.h"
#include "fnv/decl/FUN_006e8f40_shell.h"
#include "fnv/decl/FUN_006ed530_cls.h"
#include "fnv/decl/FUN_00761540_cls.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_0096aaf0_shell.h"
#include "fnv/decl/FUN_009a3910_cls.h"
#include "fnv/decl/FUN_009a3d00_class.h"
#include "fnv/decl/FUN_009acce0_shell.h"
#include "fnv/decl/FUN_009d9f40_Class.h"
#include "fnv/decl/FakeCell.h"
#include "fnv/decl/FleeSearch.h"
#include "fnv/decl/FloatArray6db5.h"
#include "fnv/decl/GetCenterX_006a6eb0.h"
#include "fnv/decl/HideSearchX.h"
#include "fnv/decl/LOSGridOwner.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MeshX.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NLLocation.h"
#include "fnv/decl/NavFinder697.h"
#include "fnv/decl/NavMeshEdgeQuery.h"
#include "fnv/decl/NavMeshInfo.h"
#include "fnv/decl/NavMeshSearch.h"
#include "fnv/decl/NavMeshSearchLOSArray.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/Obj00696c00.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/PathBuilderCore.h"
#include "fnv/decl/PathBuilderUpdate.h"
#include "fnv/decl/PathSmootherPOVSearch.h"
#include "fnv/decl/PathingLocationArray.h"
#include "fnv/decl/S006950d0.h"
#include "fnv/decl/S2f850.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/SHStub.h"
#include "fnv/decl/TESAmmoInitCalls.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/This152.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/_Dummy_0069e390.h"
#include "fnv/decl/fnv_0068f0c0__FUN_0068f0c0_shell.h"
#include "fnv/decl/fnv_00696cf0__Host696.h"
#include "fnv/decl/fnv_006aa780__FUN_006aa780_Class.h"
#include "fnv/decl/fnv_006ab380__FUN_006ab380_shell.h"
#include "fnv/decl/fnv_006b77e0__FUN_006b77e0_shell.h"
#include "fnv/decl/fnv_006b7850__FUN_006b7850_shell.h"
#include "fnv/decl/fnv_006c99c0__FUN_006c99c0_shell.h"
#include "fnv/decl/fnv_006ceea0__FUN_006ceea0_Class.h"
#include "fnv/decl/fnv_006db0d0__FUN_006db0d0_Class.h"
#include "fnv/decl/fnv_006db840__BSSimpleArray.h"
#include "fnv/decl/fnv_006e2000__FUN_006e2000_shell.h"
#include "fnv/decl/fnv_006f2290__CtorHelper.h"
#include "fnv/decl/fnv_006f49c0__FUN_006f49c0_shell.h"
#include "fnv/decl/fnv_006f5060__FUN_006f5060_Class.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_0084b5c0__FUN_0084b5c0_Array.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_anon_tile__NiPoint2_Sub.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00416000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_0069e000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006ad000.h"
#include "fnv/symbols_006b9000.h"
#include "fnv/symbols_006ba000.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_006d0000.h"
#include "fnv/symbols_006d1000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_006d4000.h"
#include "fnv/symbols_006d6000.h"
#include "fnv/symbols_006d7000.h"
#include "fnv/symbols_006d8000.h"
#include "fnv/symbols_006e6000.h"
#include "fnv/symbols_006e7000.h"
#include "fnv/symbols_006f3000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_007a9000.h"
#include "fnv/symbols_008b6000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_0106b000.h"
#include "fnv/symbols_0106c000.h"
#include "fnv/symbols_011a5000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "pathfind_decls.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/decl/FUN_005582d0_shell.h"
#include "fnv/decl/FUN_0068f0a0_shell.h"
// @fnv 0x0096d470
void ActorDeletionQueue::FUN_0096d470(MobileObject* object, int value)
{
    reinterpret_cast<::FUN_0096aaf0_shell *>(&(storage))->FUN_0096aaf0((std::intptr_t)(object), value);
}
// Calls the pathing query with the given location, point, result and filter, using default flags 0 and mask 0xffff.
// @fnv 0x006d7490
bool Pathing::FindPathingLocation(PathingLocation& location, const NiPoint3& point, PathingLocation* result,
                                  CheckLineOfSightFilter* filter)
{
    return ::fnv_006d74c0::FUN_006d74c0(location, point, 0, 0xffff, result, (::fnv_006d74c0::EdgeFilter *)(filter));
}
// Looks up key in map and returns the stored TESObjectREFR pointer, or 0 if not found.
// @fnv 0x00693d70
TESObjectREFR* Pathing::FindReferenceByFormId(unsigned int key)
{
    TESObjectREFR* result;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&(map))->FUN_00853130(key, (::fnv_00853130::CombatThreatRecord *&)(result)))
        return result;
    else
        return 0;
}
// Computes a path between two PathingLocations under a limit and returns its cost, or FLT_MAX if no path is found.
// @fnv 0x006d4eb0
float Pathing::FindPathDistance(const PathingLocation& from, const PathingLocation& to, float limit,
                                PathingActorData* locks, DOOR_LOCK_DISPOSITION disposition)
{
    PathingPath path;
    if (::FUN_006d4d20((::LocS *)&(from), (::LocS *)&(to), &path, (*(int *)&(const ::Pathing::TELEPORT_DOOR_PATH_RESTRICTION &)(RestrictionNone)), limit, locks, (*(int *)&(disposition))))
        return reinterpret_cast<::fnv_006f49c0::FUN_006f49c0_shell *>(&(path))->GetPathLength();
    else
        return 3.402823466e+38F;
}
// @fnv 0x006d6f80
bool Pathing::FindClosestPathingPoint(TESWorldSpace* world, TESObjectCELL* cell, const NiPoint3& point,
                                      NiPoint3* output)
{
    AutoMemContext memContext(MEM_CONTEXT_MEM_CONTEXT_PATHING, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\Pathfind.cpp",
                              2310);
    PathingLocation pathingLocation(point, cell, world);
    if (((PathingLocationProxy&)pathingLocation).FindContainingTriangle(0) && pathingLocation.HasValidTriangle_006dd6a0())
    {
        *output = point;
        return true;
    }
    if (reinterpret_cast<::NLLocation *>(&(pathingLocation))->UpdateMeshLocation())
    {
        NavMeshPtr mesh;
        unsigned short triangle;
        if (pathingLocation.FindNavMeshTriangle(mesh, triangle))
        {
            *output = ((::NavMesh *)(::FUN_00559450((int *)&(mesh))))->GetNavMeshData(triangle);
            return true;
        }
    }
    return false;
}
// Dispatches a pathing request to the handler matching its type and returns the handler's result, or false for an unrecognized type.
// @fnv 0x006d0900
bool Pathing::BuildPath(PathingRequest* request, PathingSolution* solution)
{
    AutoMemContext memContext(MEM_CONTEXT_MEM_CONTEXT_PATHING, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\Pathfind.cpp", 106);
    switch (request->GetType())
    {
    case RequestLocation:
        return FUN_006d0b10(request, solution);
        break;
    case RequestClosePoint: {
        PathingRequestClosePoint* closeRequest = (PathingRequestClosePoint*)request;
        return FUN_006d0be0(closeRequest, solution);
    }
    break;
    case RequestHide: {
        PathingRequestHide* hideRequest = (PathingRequestHide*)request;
        return ::FUN_006d1c60((::P048Request *)(hideRequest), (::P048Solution *)(solution));
    }
    break;
    case RequestFlee: {
        PathingRequestFlee* fleeRequest = (PathingRequestFlee*)request;
        return ::FUN_006d1660((::RequestView *)(fleeRequest), (::SolutionView *)(solution));
    }
    break;
    case RequestLOS: {
        PathingRequestLOS* losRequest = (PathingRequestLOS*)request;
        return ::fnv_006d1f80::BuildPathBetweenLocations((::fnv_006d1f80::RequestOps *)(losRequest), (::fnv_006d1f80::SolutionOps *)(solution));
    }
    break;
    case RequestOptimal: {
        PathingRequestOptimalLocation* optimalRequest = (PathingRequestOptimalLocation*)request;
        return ::fnv_006d23d0::BuildOptimalPathSolution(optimalRequest, solution);
    }
    break;
    case RequestUnknown: {
        PathingRequestUnknown* unknownRequest = (PathingRequestUnknown*)request;
        return ::FUN_006d2c80((::NavMeshContext *)(unknownRequest), (::NavMeshRoute *)(solution));
    }
    break;
    }
    return false;
}
// Appends pathing locations for the virtual node at index, handling transitions from the previous node and validating the node's location via CollectNearbyEdges.
// @fnv 0x006caa40
int PathBuilder::AppendPathNodeLocations(int index, BSSimpleArray<PathingLocation, 1024>* output, TESObjectREFR* actor)
{
    PacketNodeRecord* node = ((::PacketNodeRecord *)(reinterpret_cast<::FUN_006e78b0_shell *>((solution))->FUN_006e78b0(index)));
    if (index != 0 && !skipTransitions)
    {
        PacketNodeRecord* previous = ((::PacketNodeRecord *)(reinterpret_cast<::FUN_006e78b0_shell *>((solution))->FUN_006e78b0(index - 1)));
        if (index > reinterpret_cast<::FUN_009611e0_shell *>((((TESPackage*)solution)))->FUN_009611e0())
        {
            if (::FUN_006cac70((const int *)(previous)))
            {
                PathingLocation entry;
                if (reinterpret_cast<::This152 *>(this)->FindNavMeshLocation((::ArgObj *)(previous), (::ArgObj *)(node), (::Out152 *)&(entry)))
                {
                    reinterpret_cast<::PathingLocationArray *>((output))->FUN_006cf1b0(entry);
                    return 1;
                }
            }
        }
        else if (!::FUN_006cac70((const int *)(node)))
        {
            PathingLocation entry;
            if (reinterpret_cast<::This152 *>(this)->FindNavMeshLocation((::ArgObj *)(previous), (::ArgObj *)(node), (::Out152 *)&(entry)))
            {
                reinterpret_cast<::PathingLocationArray *>((output))->FUN_006cf1b0(entry);
                return 1;
            }
        }
    }
    if (::FUN_006cac70((const int *)(node)))
    {
        PathingLocation* location = &(*(::PathingLocation *)(reinterpret_cast<::BaseProcess *>((node))->GetCurrentProcessData()));
        if (!((PathingLocationProxy*)location)->FindContainingTriangle(0))
            return 2;
        if (location->HasValidTriangle_006dd6a0())
            reinterpret_cast<::PathingLocationArray *>((output))->FUN_006cf1b0(*location);
        else
        {
            switch (::CollectNearbyEdges((::PathActor *)(location), 10, (::EdgeHandleList *)(actor)))
            {
            case 1:
                reinterpret_cast<::PathingLocationArray *>((output))->FUN_006cf1b0(*location);
                return 1;
            case 2:
                return reinterpret_cast<::PathBuilderCore *>(this)->FUN_006cb050((::PathLoc *)(location), (::PathLocArray *)(output), 1, (::DoorEntryList *)(actor));
            default:
                return 2;
            }
        }
    }
    else
        return 2;
    return 1;
}

struct ScrapHeapBuffer
{
    void* Allocate(unsigned int, char*, int, unsigned int);
    void* Allocate(unsigned int, unsigned int);
    unsigned int Size(void*);
    void Clean(bool);
    void CheckForLeaks();
    bool IsHeapOf(void*);
    unsigned int QAllocatedMemory();
    unsigned int GetAllocationCount();
    void Init(unsigned int);
    void* __vecDelDtor(unsigned int);
    char* m_pHeapBase;
    char* m_pCurrentPosition;
    char* m_pBufferLimit;
    void* m_pBufferHeader;
    unsigned int m_uiBufferSize;
};

struct MemoryManager
{
    ScrapHeapBuffer* GetGeneralAllocator();
};
struct PathBuilderDetailedPathMeshes
{
    PathBuilderDetailedPathMeshes();
    virtual ~PathBuilderDetailedPathMeshes();
    char pad[0xc];
};
struct HZ
{
};
struct FUN_006c6c60 : public PathBuilderDetailedPathMeshes
{
    ScrapHeapBuffer* heap;
    FUN_006c6c60();
    ~FUN_006c6c60();
};
// Initializes heap from the memory manager and calls FUN_0042fcb0 with zero arguments.
// @fnv 0x006c6c60
FUN_006c6c60::FUN_006c6c60()
{
    heap = ::FUN_00401020()->GetGeneralAllocator();
    reinterpret_cast<::S2f850 *>((((HZ*)this)))->FUN_0042fcb0(0, 0);
}

struct TESObjectCELL;
struct TESWorldSpace;
struct ParentSpaceNode
{
    bool m_bIsWorldspace;
    char _pad_1[3];
    TESWorldSpace* m_pContainingWorldspace;
    TESObjectCELL* m_pReferenceCell;
};

struct ArrHelper
{
    void ConstructParentSpaceNodes(ParentSpaceNode* first, unsigned int count);
};
// Default-constructs count ParentSpaceNode objects in place starting at first.
// @fnv 0x006d03d0
void ArrHelper::ConstructParentSpaceNodes(ParentSpaceNode* apNodes, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        new (apNodes + i) ParentSpaceNode;
    }
}

struct SV
{
    float f;
};
struct SettingT_GameSettingCollection_
{
};
extern float DAT_011a5cf8;
// @fnv 0x006d0870
bool FUN_006d0870()
{
    DAT_011a5cf4 = FUN_005b9e80(((::SV *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f2ba8))))))->f * DAT_01023128);
    DAT_011a5cf8 = FUN_005b9e80(((::SV *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f2af8))))))->f * DAT_01023128);
    DAT_011a5cfc = FUN_005b9e80(((::SV *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f2b04))))))->f * DAT_01023128);
    return true;
}

extern unsigned int _data_011c16bc;
struct NavMeshArr
{
    char b[16];
    ~NavMeshArr();
};
struct PathBuilderDetailedPathInfos
{
    char b[16];
    ~PathBuilderDetailedPathInfos();
};
struct FUN_006d0b80
{
    char pad[0x14];
    PathBuilderDetailedPathInfos infos;
    NavMeshArr arr;
    ~FUN_006d0b80();
};
// @fnv 0x006d0b80
FUN_006d0b80::~FUN_006d0b80()
{}

struct FUN_006d2c00_shell : public PathingLocation
{
    void FUN_006d2c00();
};

// @fnv 0x006d2c00
void FUN_006d2c00_shell::FUN_006d2c00()
{
    this->uiFlags |= 2;
}

struct CombatCoverPointData;
class EdgeExtraInfo;
class NavMeshTriangleReference;
struct PNode;
template <class, unsigned int> class BSSimpleArray;
struct HX
{
    char pad[0x104];
    CombatCoverPointData* loc;
    void FUN_006d3100(CombatCoverPointData*);
public:
    bool FUN_006a8290(::PNode *, ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *, ::BSSimpleArray< ::EdgeExtraInfo, 1024> *);
};
// @fnv 0x006d3100
void HX::FUN_006d3100(CombatCoverPointData* apCoverLocation)
{
    loc = apCoverLocation;
}

struct PathStub
{
};
struct TES
{
};
// @fnv 0x006d6f40
void __cdecl FUN_006d6f40(void* apArg)
{
    reinterpret_cast<::fnv_006b77e0::FUN_006b77e0_shell *>((((PathStub*)((::Pathing *)(reinterpret_cast<::Owner45A *>((((::TES *)::g_TES)))->FUN_0045af00())))))->FUN_006b77e0((::fnv_006b77e0::TESObjectCELL *)(apArg));
}

namespace fnv_006d6f60 {
struct PathStub
{
};
struct TES
{
};
// @fnv 0x006d6f60
void __cdecl ForwardToPathing(void* apArg1, void* apArg2)
{
    reinterpret_cast<::fnv_006b7850::FUN_006b7850_shell *>((((PathStub*)((::Pathing *)(reinterpret_cast<::Owner45A *>((((::fnv_006d6f60::TES *)::g_TES)))->FUN_0045af00())))))->FUN_006b7850((::TESWorldSpace *)(apArg1), (std::intptr_t)(apArg2));
}
}  // namespace fnv_006d6f60

class NiAVObject;

template <> class NiPointer<NiAVObject>
{
  public:
    bool operator!=(NiPointer<NiAVObject> const&) const;
};

struct FUN_006d7a20_shell
{
    bool IsNotEqual(NiPointer<NiAVObject> const& a1);
};

// @fnv 0x006d7a20
bool FUN_006d7a20_shell::IsNotEqual(NiPointer<NiAVObject> const& a1)
{
    return reinterpret_cast<::DummyStruct_00631820 *>((void *)(reinterpret_cast<NiPointer<NiAVObject>*>(this)))->IsNotEqual((const ::DummyStruct_00631820 &)(a1));
}

// @fnv 0x006d93d0
bool __cdecl DoBoundsOverlap(const NiPoint3* bound1Min, const NiPoint3* bound1Max, const NiPoint3* bound2Min,
                             const NiPoint3* bound2Max)
{
    if (bound2Min->x >= bound1Max->x)
        return false;
    else if (bound2Max->x <= bound1Min->x)
        return false;
    else if (bound2Min->y >= bound1Max->y)
        return false;
    else if (bound2Max->y <= bound1Min->y)
        return false;
    else if (bound2Min->z >= bound1Max->z)
        return false;
    else if (bound2Max->z <= bound1Min->z)
        return false;

    return true;
}

struct NiAVObject
{
};
struct WaitableObject
{
public:
    void FUN_00401970();
};
struct NiPtr
{
    char* p;
    NiPtr* Assign(char* o);
};
// @fnv 0x006dadb0
NiPtr* NiPtr::Assign(char* pObject)
{
    if (p != pObject)
    {
        if (p)
            reinterpret_cast<::WaitableObject *>((((NiAVObject*)(p + 0x10))))->FUN_00401970();
        p = pObject;
        if (p)
            reinterpret_cast<::FUN_0040f6e0_class *>((((WaitableObject*)(p + 0x10))))->FUN_0040f6e0();
    }
    return this;
}

struct NavMeshInfo;
struct BSSimpleArrayPacketReserve
{
};
struct CtorHelper
{
};
struct FloatArr : BSSimpleArrayPacketReserve
{
    int pad;
    NavMeshInfo** data;
    unsigned int AppendFloat(float* v);
};
// Reserves one slot at the end of the array, constructs it, stores the float value there and returns the slot index.
// @fnv 0x006dc320
unsigned int FloatArr::AppendFloat(float* afValue)
{
    unsigned int i = reinterpret_cast<::FUN_00761540_cls *>(this)->FUN_00761540();
    reinterpret_cast<::fnv_006f2290::CtorHelper *>((((CtorHelper*)this)))->InitializeItems((::fnv_006f2290::NavMeshInfo **)(::NavMeshInfo **)(data + i), 1);
    ((float*)data)[i] = *afValue;
    return i;
}

struct FUN_006df760_shell : public PathingLocation
{
    unsigned short GetShortValueAtOffset24();
};

// @fnv 0x006df760
unsigned short FUN_006df760_shell::GetShortValueAtOffset24()
{
    return this->m_usTriangleID;
}

struct S5460
{
    virtual void v0();
    virtual void* v1(unsigned int);
    void* data;
    unsigned int count;
    unsigned int cap;
    unsigned int FUN_00978bc0();
};
// @fnv 0x00978bc0
unsigned int S5460::FUN_00978bc0()
{
    if (((bool)(reinterpret_cast<::FUN_00438b90_class *>(this)->FUN_00438b90())))
    {
        if (cap == 0)
        {
            unsigned int uiNewCapacity = 4;
            data = v1(uiNewCapacity);
            cap = uiNewCapacity;
        }
        else
        {
            unsigned int uiNewCapacity = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>(this)->FUN_009a3910()));
            reinterpret_cast<::FUN_006dc590 *>(this)->FUN_006dc590_(uiNewCapacity, count);
            cap = uiNewCapacity;
        }
    }
    count++;
    return count - 1;
}

struct FUN_0099e040_shell : public PathingRequestOptimalLocation
{
    float FUN_0099e040();
};

// @fnv 0x0099e040
float FUN_0099e040_shell::FUN_0099e040()
{
    return fUnkBC;
}

extern int DAT_0106c9e0;
struct FUN_006dc440_class
{
};

struct FUN_006d04e0_shell
{
    void* FUN_006d04e0();
};

// Sets the object's vtable pointer to DAT_0106c9e0, calls FUN_006dc440(0, 0) on it, and returns this.
// @fnv 0x006d04e0
void* FUN_006d04e0_shell::FUN_006d04e0()
{
    *(void**)this = (void*)&DAT_0106c9e0;
    reinterpret_cast<::FUN_006dc440_Class *>((reinterpret_cast<FUN_006dc440_class*>(this)))->FUN_006dc440(0, 0);
    return this;
}


struct FUN_006d0730_shell
{
    void FUN_006d0730(void* dst, void const* src, unsigned int count);
};

// @fnv 0x006d0730
void FUN_006d0730_shell::FUN_006d0730(void* pDest, void const* pSource, unsigned int count)
{
    if (!(count > 0))
        return;
    if (pDest < pSource)
    {
        unsigned int i = 0;
        for (; i < count; ++i)
        {
            std::memmove((char*)pDest + i * 0x18, (char const*)pSource + i * 0x18, 0x18);
        }
    }
    else if (pDest > pSource)
    {
        int i = (int)count - 1;
        for (; i >= 0; --i)
        {
            std::memmove((char*)pDest + i * 0x18, (char const*)pSource + i * 0x18, 0x18);
        }
    }
}

struct MersenneTwister
{
    static MersenneTwister* __cdecl GetRandomGenerator();
    void FUN_006d1620();
};

// @fnv 0x006d1600
void __cdecl FUN_006d1600()
{
    MersenneTwister::GetRandomGenerator()->FUN_006d1620();
}

struct FUN_006d6d60_shell : public PathingRequestOptimalLocation
{
    NiPoint3& FUN_006d6d60(NiPoint3& akDest);
};

// Copies the NiPoint3 stored at offset 0xb0 of this object into akDest and returns it.
// @fnv 0x006d6d60
NiPoint3& FUN_006d6d60_shell::FUN_006d6d60(NiPoint3& akDest)
{
    akDest = *reinterpret_cast<const NiPoint3*>(afTargetPoint);
    return akDest;
}

struct FUN_006d6d90_shell : public PathingRequestOptimalLocation
{
    float FUN_006d6d90();
};

// @fnv 0x006d6d90
float FUN_006d6d90_shell::FUN_006d6d90()
{
    return fUnkC0;
}

struct FUN_006d6db0_shell : public PathingRequestOptimalLocation
{
    unsigned char GetByteAtOffsetCC();
};

// @fnv 0x006d6db0
unsigned char FUN_006d6db0_shell::GetByteAtOffsetCC()
{
    return ucUnkCC;
}

struct FUN_006d6dd0_shell : public PathingRequestOptimalLocation
{
    unsigned char GetByteAtOffsetCD();
};

// @fnv 0x006d6dd0
unsigned char FUN_006d6dd0_shell::GetByteAtOffsetCD()
{
    return ucUnkCD;
}

struct FUN_006d6df0_shell : public PathingRequestOptimalLocation
{
    unsigned char FUN_006d6df0();
};

// @fnv 0x006d6df0
unsigned char FUN_006d6df0_shell::FUN_006d6df0()
{
    return ucUnkCE;
}

struct FUN_006d6e10_shell : public PathingRequestOptimalLocation
{
    char GetByteAtOffsetCF();
};

// @fnv 0x006d6e10
char FUN_006d6e10_shell::GetByteAtOffsetCF()
{
    return (char)ucUnkCF;
}

struct FUN_006d6e30_shell : public PathingRequestOptimalLocation
{
    unsigned char GetByteAtOffsetD1();
};

// @fnv 0x006d6e30
unsigned char FUN_006d6e30_shell::GetByteAtOffsetD1()
{
    return ucUnkD1;
}

struct FUN_006d8970_shell
{
    int m0;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    char* m6;
    void SetByteAt(int b, int a);
};

// @fnv 0x006d8970
void FUN_006d8970_shell::SetByteAt(int aiIndex, int aiValue)
{
    ((char*)(this->m6))[aiIndex] = aiValue;
}

struct Arr
{
    unsigned int* GetAt(int index);
};

struct FUN_006d89b0_shell
{
    void FUN_006d89b0(int index);
};

// @fnv 0x006d89b0
void FUN_006d89b0_shell::FUN_006d89b0(int index)
{
    ((Arr*)(this + 0x1c))->GetAt(index);
}

// @fnv 0x006d8a20
void __cdecl FUN_006d8a20(void* p, float f, SearchOutput* apOutput)
{
    FUN_006d8a40((SearchObject*)p, f, apOutput, true);
}


struct FUN_006dae60_shell
{
    void* FUN_006dae60();
};

// Sets the object's vtable pointer to DAT_0106cbec, calls FUN_006dc070(0, 0), and returns this.
// @fnv 0x006dae60
void* FUN_006dae60_shell::FUN_006dae60()
{
    *(void**)this = &DAT_0106cbec;
    reinterpret_cast<::FUN_006dc070_Class *>(this)->FUN_006dc070(0, 0);
    return this;
}

namespace fnv_006dae90 {
struct FUN_006dbde0_shell
{
};


struct FUN_006dae90_shell
{
    void* m;
    void FUN_006dae90();
};

// @fnv 0x006dae90
void FUN_006dae90_shell::FUN_006dae90()
{
    m = &(*reinterpret_cast<int *>(&::DAT_0106cbec));
    reinterpret_cast<::NavMeshSearchLOSArray *>((((FUN_006dbde0_shell*)this)))->FUN_006dbde0(1);
}
}  // namespace fnv_006dae90

namespace fnv_006d8a00 {
// @fnv 0x006d8a00
void __cdecl FUN_006d8a00(SearchObject* apSearch, float f, SearchOutput* apOutput)
{
    ::FUN_006d8a40(apSearch, f, apOutput, false);
}
}  // namespace fnv_006d8a00

struct FUN_006d0540_shell
{
    void FUN_006d0540(void* dst, void* src, unsigned int count);
};

// Copies count 0x30-byte elements from src to dst, iterating forward or backward depending on the relative addresses.
// @fnv 0x006d0540
void FUN_006d0540_shell::FUN_006d0540(void* dst, void* src, unsigned int count)
{

    if (count <= 0)
        return;

    if (dst < src)
    {
        for (unsigned int i = 0; i < count; ++i)
            std::memmove((char*)dst + i * 0x30, (char*)src + i * 0x30, 0x30);
    }
    else if (dst > src)
    {
        for (int i = (int)count - 1; i >= 0; --i)
            std::memmove((char*)dst + i * 0x30, (char*)src + i * 0x30, 0x30);
    }
}

struct S006d0420
{
    S006d0420* FUN_006d0420();
};
// Sets the object's vtable pointer to DAT_0106b1cc, calls FUN_0069b940 with 0, 0, and returns this.
// @fnv 0x006d0420
S006d0420* S006d0420::FUN_006d0420()
{
    *(void**)this = (void*)&DAT_0106b1cc;
    reinterpret_cast<::FUN_0069b940_class *>(this)->FUN_0069b940(0, 0);
    return this;
}

struct S006d0510
{
    void* FUN_006d0510(unsigned int);
};
// Calls FUN_006e22d0, then deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x006d0510
void* S006d0510::FUN_006d0510(unsigned int flags)
{
    reinterpret_cast<::FUN_006e22d0_Class *>(this)->FUN_006e22d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_006d07d0_shell
{
    void FUN_006d07d0(void* a, void* b, unsigned int c);
};

// @fnv 0x006d07d0
void FUN_006d07d0_shell::FUN_006d07d0(void* a, void* b, unsigned int c)
{
    if (c <= 0)
        return;
    if (a < b)
    {
        for (unsigned int i = 0; i < c; ++i)
            std::memmove((char*)a + i, (char*)b + i, 1);
    }
    else if (a > b)
    {
        for (int i = c - 1; i >= 0; --i)
            std::memmove((char*)a + i, (char*)b + i, 1);
    }
}

namespace fnv_006d1620 {
struct MersenneTwister
{
    float FUN_006d1620();
};
// @fnv 0x006d1620
float MersenneTwister::FUN_006d1620()
{
    unsigned int v = reinterpret_cast<::FUN_00476be0_Class *>(this)->FUN_00476be0();
    return (float)((double)v * ::DAT_0101e5a0 - (double)3.1415927f);
}
}  // namespace fnv_006d1620

struct FUN_006d7ee0_shell
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    char GetByteAt(int idx);
};

// @fnv 0x006d7ee0
char FUN_006d7ee0_shell::GetByteAt(int idx)
{
    return ((const unsigned char*)m_18)[idx];
}

struct S0068f200
{
};
struct S006949d0
{
    S0068f200* GetAt(unsigned short, int);
};
struct Outer006d8910
{
    unsigned char _pad[0x38];
    S006949d0 _arr;
    unsigned char FUN_006d8910(unsigned short);
};
// Counts how many of the three entries at index a return nonzero from FUN_0068f200 and returns that count.
// @fnv 0x006d8910
unsigned char Outer006d8910::FUN_006d8910(unsigned short ausIndex)
{
    unsigned char ucCount = 0;
    for (char i = 0; i < 3; ++i)
    {
        if (((unsigned char)(reinterpret_cast<::FUN_0068f200_shell *>((((::S0068f200 *)(std::uintptr_t)(reinterpret_cast<::FUN_00558dd0_class *>(&(_arr))->FUN_00558dd0(ausIndex)))))->FUN_0068f200({}))))
            ++ucCount;
    }
    return ucCount;
}

struct Unk
{
    int f0;
    char f4;
    Unk* FUN_006d89d0(int a, char b);
};
// Stores the two arguments into f0 and f4 and returns this.
// @fnv 0x006d89d0
Unk* Unk::FUN_006d89d0(int aiValue, char b)
{
    f0 = aiValue;
    f4 = b;
    return this;
}

struct NavMeshNormalAccessor
{
};

// Gets the navmesh triangle for the location and writes its normal into normal, returning false if the location or triangle lookup fails.
// @fnv 0x006d9100
bool GetPathingLocationNormal(PathingLocation& location, NiPoint3& normal)
{
    if (!reinterpret_cast<PathingLocationProxy*>(&location)->FindContainingTriangle(0))
        return false;
    {
        NavMeshPtr mesh2;
        unsigned short triangle;
        if (!location.FindNavMeshTriangle(mesh2, triangle))
            return false;
        normal = reinterpret_cast<::NavMesh *>((reinterpret_cast<NavMeshNormalAccessor*>(((::NavMesh *)(::FUN_00559450((int *)&(mesh2)))))))->GetPlaneNormal(triangle);
        return true;
    }
}

struct Entry16
{
    int f0;
    int f1;
    int f2;
    int f3;
};
struct Arr16
{
    int m0;
    Entry16* m4;
    unsigned int FUN_006dae00(Entry16*);
};
// @fnv 0x006dae00
unsigned int Arr16::FUN_006dae00(Entry16* apEntry)
{
    unsigned int idx = ::FUN_006f31f0((::S5460 *)this);
    reinterpret_cast<::FUN_006dbcf0_Class *>(this)->FUN_006dbcf0((struct ::FUN_006d5320 *)(::Entry16 *)(&m4[idx]), 1);
    m4[idx] = *apEntry;
    return idx;
}

struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_006db330
{
    virtual ~FUN_006db330();
};
struct FUN_006db350 : FUN_006db330
{
    virtual ~FUN_006db350();
};
// Destructor that calls Clear(true) on the object at this address.
// @fnv 0x006db350
FUN_006db350::~FUN_006db350()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}

struct Vec12
{
    int x;
    int y;
    int z;
};
struct Dummy
{
    char _pad[0x28];
    Vec12 m0;
    Vec12 m1;
    Vec12 m2;
    void SetVectors(Vec12 const* a, Vec12 const* b, Vec12 const* c);
};
// Copies the three Vec12 arguments into the m0, m1 and m2 members.
// @fnv 0x006d6ee0
void Dummy::SetVectors(Vec12 const* apVec0, Vec12 const* apVec1, Vec12 const* apVec2)
{
    m0 = *apVec0;
    m1 = *apVec1;
    m2 = *apVec2;
}

struct FUN_006d7f00_shell
{
    char _pad0x44[0x44];
    float _m44;
    bool IsModifierPositive();
};
// Returns true when the float at offset 0x44 is greater than _gModifierZero, otherwise false.
// @fnv 0x006d7f00
bool FUN_006d7f00_shell::IsModifierPositive()
{
    return _m44 > ::_DAT_01012060 ? 1 : 0;
}

struct ArrSI
{
};

struct FUN_006d8990_shell
{
    char pad[0x1c];
    ArrSI m_arrsi;
    unsigned int GetFlags();
};

// @fnv 0x006d8990
unsigned int FUN_006d8990_shell::GetFlags()
{
    return ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((void *)&(m_arrsi))->GetName()));
}

struct NP3S
{
    float x, y, z;
};
struct LocS
{
};
struct AutoMemHelper
{
    int aiMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct FUN_006f33b0
{
    int data[0x20b8 / 4];
    FUN_006f33b0();
    ~FUN_006f33b0();
};
struct FUN_006f4990_shell
{
    void ClearTeleportPath();
};
struct Arr_006cee30
{
};
struct Arr_006ceea0
{
};
// Runs a path search from aOrigin to aDestination, and on success stores both locations into apRetPath and returns true.
// @fnv 0x006d4d20
bool __cdecl FUN_006d4d20(LocS* aOrigin, LocS* aDestination, void* apRetPath, int aRestrictions, float afMaxDist,
                          PathingActorData* apActorLockData, int aeDoorLockDisp)
{
    AutoMemHelper tempMemContext(
        0x2d, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\Pathfind.cpp", 0x582);
    FUN_006f33b0 search;
    ((FUN_006f4990_shell*)apRetPath)->ClearTeleportPath();
    reinterpret_cast<::FUN_006cee30_Class *>((((Arr_006cee30*)apRetPath)))->FUN_006cee30(10);
    reinterpret_cast<::fnv_006ceea0::FUN_006ceea0_Class *>((((Arr_006ceea0*)((char*)apRetPath + 0x10))))->FUN_006ceea0(10);
    if (reinterpret_cast<::DoorSearchInit *>(&(search))->InitDoorSearch((::SearchLocation *)(aOrigin), (::SearchLocation *)(aDestination), (::SearchResult *)(apRetPath), aRestrictions, afMaxDist, apActorLockData,
                              aeDoorLockDisp))
    {
        *(NP3S*)((char*)apRetPath + 0x20) = (*(::NP3S *)&(reinterpret_cast<::TaskQueueInterface *>((aOrigin))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
        *(NP3S*)((char*)apRetPath + 0x2c) = (*(::NP3S *)&(reinterpret_cast<::TaskQueueInterface *>((aDestination))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
        return true;
    }
    else
    {
        return false;
    }
}

// @fnv 0x006d7350
bool FUN_006d7350(PathingLocation& aStartLocation, PathingLocation& aGoalLocation,
                  PathingLocation* apReturnIntersectionLocation, Pathing::CheckLineOfSightFilter* apFilter)
{
    if (apReturnIntersectionLocation)
        *apReturnIntersectionLocation = aStartLocation;
    if (!((PathingLocationProxy*)&aGoalLocation)->FindContainingTriangle(0))
    {
        if (!((PathingLocationProxy*)&aStartLocation)->FindContainingTriangle(0))
            return true;
        return false;
    }
    NavMeshPtr spgoalMesh;
    unsigned short usgoalTri;
    if (!aGoalLocation.FindNavMeshTriangle(spgoalMesh, usgoalTri))
    {
        return ::fnv_006d74c0::FUN_006d74c0(aStartLocation, reinterpret_cast<::TaskQueueInterface *>((void *)&(aGoalLocation))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()), 0, 0xffff,
                                                     apReturnIntersectionLocation, (::fnv_006d74c0::EdgeFilter *)(apFilter));
    }
    else
    {
        return ::fnv_006d74c0::FUN_006d74c0(aStartLocation, reinterpret_cast<::TaskQueueInterface *>((void *)&(aGoalLocation))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()), spgoalMesh, usgoalTri,
                                                     apReturnIntersectionLocation, (::fnv_006d74c0::EdgeFilter *)(apFilter));
    }
}

namespace fnv_006d0450 {
struct FUN_006e12c0_s
{
};
struct S5460
{
    virtual void v0();
    virtual unsigned int v1(unsigned int);
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int GetNextIndex();
};
// If FUN_00438b90 succeeds, initializes m_08/m_10 via v1 or SetData, then increments m_0c and returns the previous value.
// @fnv 0x006d0450
unsigned int S5460::GetNextIndex()
{
    if (((bool)(reinterpret_cast<::FUN_00438b90_class *>(this)->FUN_00438b90())))
    {
        if (m_10 == 0)
        {
            unsigned int v = 4;
            m_08 = v1(v);
            m_10 = v;
        }
        else
        {
            unsigned int v = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>(this)->FUN_009a3910()));
            reinterpret_cast<::FUN_006e12c0_Class *>((((FUN_006e12c0_s*)this)))->SetData(v, m_0c);
            m_10 = v;
        }
    }
    m_0c = m_0c + 1;
    return m_0c - 1;
}
}  // namespace fnv_006d0450

struct HArr
{
};

struct TESSound : public HArr
{
};

struct TESForm
{
    unsigned int _FNV_GetFormType();
};

struct CP_008c48d0
{
};

// @fnv 0x006d9350
int __cdecl FUN_006d9350(void* form, std::intptr_t value, float distance, TESSound* sound)
{
    if (form == 0 || sound == 0)
        return 0;

    if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((sound))->FUN_0084e3a0())) < 0x20)
        reinterpret_cast<::fnv_0084b5c0::FUN_0084b5c0_Array *>((sound))->FUN_0084b5c0(0x20);

    CP_008c48d0* path = 0;

    if (reinterpret_cast<TESForm*>(form)->_FNV_GetFormType() == 0x41)
    {
        CP_008c48d0* current = reinterpret_cast<CP_008c48d0*>(form);
        path = ((::CP_008c48d0 *)(reinterpret_cast<::BGSCameraPath *>((current))->GetPrevPath()));
    }
    else
    {
        path = reinterpret_cast<CP_008c48d0*>(form);
    }

    if (path == 0)
        return 0;

    return ((int)(reinterpret_cast<::Cell54D *>((path))->FUN_0054dc00((*(const ::Point54D *)(value)), distance, (::RefArray54D *)(sound))));
}

struct _Mem_2064
{
    ~_Mem_2064();
};

extern bool __cdecl GetNavMeshHeight(PathingLocation*, void*);

// Builds a PathingLocation from pos, cell and world, then returns the result of GetNavMeshHeight on it with arg.
// @fnv 0x006d97b0
bool FUN_006d97b0(NiPoint3 const& pos, TESObjectCELL* cell, TESWorldSpace* world, void* arg)
{
    PathingLocation loc(pos, cell, world);
    return GetNavMeshHeight(&loc, arg);
}

struct GO
{
    operator unsigned int() const
    {
        return 0;
    }
};

struct FUN_00697980_t
{
    bool GetTriangleHeightAtPoint(unsigned short, const NiPoint3&, float, float, float&);
};

// @fnv 0x006d9830
bool GetNavMeshHeight(PathingLocation* pathingLocation, float* pfOutZ)
{
    if (!reinterpret_cast<PathingLocationProxy*>(pathingLocation)->FindContainingTriangle(0))
    {
        *pfOutZ = reinterpret_cast<::TaskQueueInterface *>((void *)(pathingLocation))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()).z;
        return false;
    }

    if (!pathingLocation->HasValidTriangle_006dd6a0())
    {
        *pfOutZ = reinterpret_cast<::TaskQueueInterface *>((void *)(pathingLocation))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()).z;
        return false;
    }

    NavMeshPtr navMeshPtr;
    unsigned short m_usTriangleID;

    if (!pathingLocation->FindNavMeshTriangle(navMeshPtr, m_usTriangleID))
    {
        *pfOutZ = reinterpret_cast<::TaskQueueInterface *>((void *)(pathingLocation))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()).z;
        return false;
    }

    if (!reinterpret_cast<FUN_00697980_t*>(reinterpret_cast<GO&>(navMeshPtr).operator unsigned int())
             ->GetTriangleHeightAtPoint(m_usTriangleID, reinterpret_cast<::TaskQueueInterface *>((void *)(pathingLocation))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()), 180.0f, 180.0f, *pfOutZ))
    {
        *pfOutZ = reinterpret_cast<::TaskQueueInterface *>((void *)(pathingLocation))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()).z;
        return false;
    }

    return true;
}

namespace fnv_006d91d0 {
struct S2f850
{
    unsigned int AppendValue(NavMeshPtr const&);
};

struct CP_008c48d0
{
};

struct FUN_00453980_shell
{
};

struct FUN_00459470_Class
{
};

struct EffectSetting
{
};

struct NavMeshCollection
{
    NavMeshPtr GetNavMeshAt(unsigned int);
};



// Appends nav meshes from the previous path, or from every cell's nav mesh array when no previous path exists, to apRetNavMeshes and returns true.
// @fnv 0x006d91d0
bool FUN_006d91d0(BSSimpleArray<NavMeshPtr, 1024>* apRetNavMeshes)
{
    NavMeshCollection* parray;
    unsigned int i;

    if (((std::uintptr_t)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(::g_TES)))->GetPrevPath())))
    {
        parray = reinterpret_cast<NavMeshCollection*>(
            (std::uintptr_t)(::FUN_0070ec90((char *)(reinterpret_cast<EffectSetting*>(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<CP_008c48d0*>(::g_TES)))->GetPrevPath())))));

        if (parray)
        {
            for (i = 0; i < ((int)(reinterpret_cast<::FUN_00620b80_shell *>((parray))->GetReferenceFlags())); ++i)
            {
                reinterpret_cast<::S2f850 *>((reinterpret_cast<S2f850*>(apRetNavMeshes)))->AppendValue(parray->GetNavMeshAt(i));
            }
        }
    }
    else
    {
        int isize;

        isize = reinterpret_cast<::FUN_00453980_shell *>((reinterpret_cast<FUN_00453980_shell*>(::g_TES)))->GetGlobalInt();

        {
            unsigned int i;

            for (i = 0; i < isize; ++i)
            {
                TESObjectCELL* pcell;

                pcell = reinterpret_cast<TESObjectCELL*>(reinterpret_cast<::FUN_00459470_Class *>((reinterpret_cast<FUN_00459470_Class*>(::g_TES)))->FUN_00459470(i));

                if (pcell)
                {
                    NavMeshCollection* parray;

                    parray =
                        reinterpret_cast<NavMeshCollection*>(((int)(::FUN_0070ec90((char *)(reinterpret_cast<EffectSetting*>(pcell))))));

                    if (parray)
                    {
                        unsigned int i;

                        for (i = 0; i < ((int)(reinterpret_cast<::FUN_00620b80_shell *>((parray))->GetReferenceFlags())); ++i)
                        {
                            reinterpret_cast<::S2f850 *>((reinterpret_cast<S2f850*>(apRetNavMeshes)))->AppendValue(parray->GetNavMeshAt(i));
                        }
                    }
                }
            }
        }
    }

    return true;
}
}  // namespace fnv_006d91d0

namespace fnv_006ad1b0 {
struct ScrapHeapBuffer;
struct MemoryManager
{
    ScrapHeapBuffer* GetGeneralAllocator();
};

class D1B0Base
{
  public:
    D1B0Base();
    virtual ~D1B0Base();


    int unk04;
    int unk08;
    int unk0C;
};

class FUN_006ad1b0 : public D1B0Base
{
  public:
    FUN_006ad1b0(unsigned int uiSize, unsigned int ItemUpdateArray, ScrapHeapBuffer* pkHeap);
    virtual ~FUN_006ad1b0();

    ScrapHeapBuffer* m_pkHeap;
};

// @fnv 0x006ad1b0
FUN_006ad1b0::FUN_006ad1b0(unsigned int uiSize, unsigned int ItemUpdateArray, ScrapHeapBuffer* pkHeap)
{
    m_pkHeap = pkHeap ? pkHeap : ((::fnv_006ad1b0::MemoryManager *)(::FUN_00401020()))->GetGeneralAllocator();
    reinterpret_cast<::FUN_009a3d00_class *>(this)->FUN_009a3d00(uiSize, ItemUpdateArray);
}
}  // namespace fnv_006ad1b0

class B6AD250Allocator;

class B6AD250MemoryManager
{
  public:
    B6AD250Allocator* GetDefaultAllocator();
};


class B6AD250Base
{
  public:
    B6AD250Base();
    virtual ~B6AD250Base();


    int unk04;
    int unk08;
    int unk0C;
    B6AD250Allocator* m_pHeapAllocator;
};

class FUN_006ad250_cls : public B6AD250Base
{
  public:
    FUN_006ad250_cls(int iSize, int iGrowBy, B6AD250Allocator* pkAllocator);
    virtual ~FUN_006ad250_cls();
};

// Stores the given allocator, or the memory manager's default allocator when none is given, then calls Init with the size and grow-by values.
// @fnv 0x006ad250
FUN_006ad250_cls::FUN_006ad250_cls(int iSize, int iGrowBy, B6AD250Allocator* pkAllocator)
{
    m_pHeapAllocator = pkAllocator ? pkAllocator : ((::B6AD250MemoryManager *)(::FUN_00401020()))->GetDefaultAllocator();
    reinterpret_cast<::FUN_006b3f40_Class *>(this)->FUN_006b3f40(iSize, iGrowBy);
}

// Two-segment side test: returns true when segment (a,b) and (c,d) straddle each other.
// Tests whether segments a-b and c-d intersect by checking the signs of cross products of their endpoints.
// @fnv 0x006ba010
bool FUN_006ba010(const NiPoint3* apSeg1Start, const NiPoint3* apSeg1End, const NiPoint3* apSeg2Start,
                  const NiPoint3* apSeg2End)
{
    float t_ = (apSeg1Start->x - apSeg2End->x) * (apSeg1End->y - apSeg2End->y) -
               (apSeg1Start->y - apSeg2End->y) * (apSeg1End->x - apSeg2End->x);
    float t2 = (apSeg1Start->x - apSeg2Start->x) * (apSeg1End->y - apSeg2Start->y) -
               (apSeg1Start->y - apSeg2Start->y) * (apSeg1End->x - apSeg2Start->x);
    float tTmp;
    float t4;
    if (t_ * t2 <= 0.0 && ((tTmp = (apSeg2Start->x - apSeg1Start->x) * (apSeg2End->y - apSeg1Start->y) -
                                   (apSeg2Start->y - apSeg1Start->y) * (apSeg2End->x - apSeg1Start->x)),
                           (t4 = tTmp + t2 - t_), (tTmp * t4 < 0.0)))
    {
        return true;
    }
    return false;
}

struct TwoComponentVector
{
    float x;
    float y;
    TwoComponentVector();
    TwoComponentVector FUN_004dfe30(const TwoComponentVector& rhs) const;
};
extern "C" TwoComponentVector __cdecl FUN_00532fd0(float scale, const TwoComponentVector& value);

// Computes a point from four 2D points using cross products and returns a or b when crossB*total exceeds DAT_01012060, otherwise the interpolated point.
// @fnv 0x006ba3d0
TwoComponentVector* __cdecl FUN_006ba3d0(TwoComponentVector* result, TwoComponentVector* apPointA,
                                         TwoComponentVector* apPointB, TwoComponentVector* apPointC,
                                         TwoComponentVector* apPointD)
{
    float intersection;
    float crossB = (apPointC->x - apPointB->x) * (apPointD->y - apPointB->y) -
                   (apPointC->y - apPointB->y) * (apPointD->x - apPointB->x);
    float total = (apPointC->x - apPointA->x) * (apPointD->y - apPointA->y) -
                  (apPointC->y - apPointA->y) * (apPointD->x - apPointA->x);
    float crossA = (apPointA->x - apPointC->x) * (apPointB->y - apPointC->y) -
                   (apPointA->y - apPointC->y) * (apPointB->x - apPointC->x);
    intersection = (crossA + total) - crossB;
    float fraction = crossA / (crossA - intersection);

    TwoComponentVector crossC = apPointC->FUN_004dfe30(FUN_00532fd0(fraction, (*(::TwoComponentVector *)(reinterpret_cast<::fnv_anon_tile::NiPoint2_Sub *>((void *)(apPointD))->Subtract((::NiPoint2 *)(apPointC), *(const ::NiPoint2 *)nullptr)))));
    if (crossB * total > ::_DAT_01012060)
    {
        if (((double)(reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::TwoComponentVector &)((*(::TwoComponentVector *)(reinterpret_cast<::fnv_anon_tile::NiPoint2_Sub *>((void *)&(crossC))->Subtract((::NiPoint2 *)(apPointA), *(const ::NiPoint2 *)nullptr)))))->GetSquaredXYLength())) < ((double)(reinterpret_cast<::FUN_00595c80_shell *>((void *)(void *)&(const ::TwoComponentVector &)((*(::TwoComponentVector *)(reinterpret_cast<::fnv_anon_tile::NiPoint2_Sub *>((void *)&(crossC))->Subtract((::NiPoint2 *)(apPointB), *(const ::NiPoint2 *)nullptr)))))->GetSquaredXYLength())))
        {
            *result = *apPointA;
            return result;
        }
        else
        {
            *result = *apPointB;
            return result;
        }
    }
    else
    {
        *result = crossC;
        return result;
    }
}

class FUN_006d0680_cls
{
  public:
    virtual void v00();
    virtual void* v04(int a);
    virtual void v08();
    virtual void* v0c(void* a, int b);
    void* m_04;
    int unk08;
    int m_0c;
    void FUN_006d0680(int a1, int a2);
};

// Updates m_04 from a1 via v04/v0c, rebuilding through FUN_006d0730 and FUN_006a8500 when a2 differs from m_0c, and records a1 in m_0c on first use.
// @fnv 0x006d0680
void FUN_006d0680_cls::FUN_006d0680(int a1, int a2)
{
    if (m_04 != 0)
    {
        if (a2 == m_0c)
        {
            m_04 = v0c(m_04, a1);
        }
        else
        {
            void* tmp = v04(a1);
            reinterpret_cast<::FUN_006d0730_shell *>(this)->FUN_006d0730(tmp, m_04, a2);
            ::FUN_006a8500((::DummyClass_006a8500 *)this);
            m_04 = tmp;
        }
    }
    else
    {
        m_04 = v04(a1);
        m_0c = a1;
    }
}

struct S006d1520_Container
{
};
struct S006d1520_LocationOps
{
};
struct FUN_006f4d00
{
    unsigned int m00, m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c;
    FUN_006f4d00(const PathingLocation& location);
    static __forceinline void* operator new(std::size_t bytes, void* heap)
    {
        return FUN_006e6da0(bytes, heap);
    }
    static void operator delete(void* pointer, void* heap);
};
struct FUN_006d1520_shell
{
    unsigned int unk00;
    unsigned int unk04;
    S006d1520_Container m_container;
    unsigned int AddPathingLocation(const NiPoint3& pos, TESObjectCELL* cell, TESWorldSpace* world);
};
// @fnv 0x006d1520
unsigned int FUN_006d1520_shell::AddPathingLocation(const NiPoint3& pos, TESObjectCELL* cell, TESWorldSpace* world)
{
    void* heap;
    unsigned int index;
    {
        PathingLocation location(pos, cell, world);
        reinterpret_cast<::PathingLocationProxy *>((reinterpret_cast<S006d1520_LocationOps*>(&location)))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0));
        index = reinterpret_cast<::FUN_006cef10_shell *>(&(m_container))->AdvanceCounter();
        heap = ((void *)(reinterpret_cast<::FUN_006e8f40_shell *>(&(m_container))->FUN_006e8f40(index)));
        new (heap) FUN_006f4d00(location);
        return index;
    }
}

class S_006d5340_Obj
{
  public:
    S_006d5340_Obj(int a, int b);
    ~S_006d5340_Obj();
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
};

// Constructs an S_006d5340_Obj from a1 and a2, then returns the result of calling its Method with a3 and a4.
// @fnv 0x006d5340
int __cdecl ConstructAndCallMethod(int aiFirst, int aiSecond, int aiThird, std::intptr_t aiFourth)
{
    S_006d5340_Obj obj(aiFirst, aiSecond);
    return reinterpret_cast<::PathBuilderUpdate *>(&(obj))->UpdatePathFromIndex(aiThird, (const ::NiPoint3 *)(aiFourth));
}

struct DecompPathScope
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    DecompPathScope(void* start, void* goal);
    ~DecompPathScope();
};

// Constructs a DecompPathScope from a and b, calls Query with c, and returns its result.
// @fnv 0x006d5420
int __cdecl QueryPathScope(void* pStart, void* b, void* pQueryArg)
{
    DecompPathScope scope(pStart, b);
    return reinterpret_cast<::FUN_006c93f0_Object *>(&(scope))->ProcessIndexRange((std::intptr_t)(pQueryArg));
}

struct BaseInitHelper
{
    void FUN_006dd010(const NiPoint3& location, const NavMeshInfo* navMeshInfo, unsigned short m_usTriangleID);
};

struct Member3
{
    char _pad[0x0c];
    Member3();
};

struct BasePathingLocation
{
    char _pad[0x24];
    virtual ~BasePathingLocation()
    {}
    virtual void _b()
    {}
    BasePathingLocation(const NiPoint3& location, const NavMeshInfo* navMeshInfo, unsigned short m_usTriangleID);
};

BasePathingLocation::BasePathingLocation(const NiPoint3& location, const NavMeshInfo* navMeshInfo,
                                         unsigned short m_usTriangleID)
{
    ((BaseInitHelper*)this)->FUN_006dd010(location, navMeshInfo, m_usTriangleID);
}

struct FUN_006d6e50 : public BasePathingLocation
{
    Member3 m_28;
    Member3 m_34;
    Member3 m_40;
    virtual void _v();
    virtual ~FUN_006d6e50();
    FUN_006d6e50(const NiPoint3& location, const NavMeshInfo* navMeshInfo, unsigned short m_usTriangleID);
};

// Constructs a BasePathingLocation by forwarding location, navMeshInfo and the unsigned short to the base init helper.
// @fnv 0x006d6e50
FUN_006d6e50::FUN_006d6e50(const NiPoint3& location, const NavMeshInfo* navMeshInfo, unsigned short m_usTriangleID)
    : BasePathingLocation(location, navMeshInfo, m_usTriangleID)
{}

struct SearchVector
{
    float x, y, z;
    SearchVector();
};
struct SearchPool
{
    unsigned int unk00, unk04, unk08, unk0C;
    SearchPool();
    ~SearchPool();
    void* FUN_006815c0();
};
struct SearchHeapA
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    SearchHeapA(int, int, void*);
    ~SearchHeapA();
};
struct SearchHeapB
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    SearchHeapB(int, int, void*);
    ~SearchHeapB();
};
struct SearchHeapC
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    SearchHeapC(int, int, void*);
    ~SearchHeapC();
};
struct SearchFinal
{
    SearchFinal();
};
struct FUN_006ed100
{
    unsigned int unk00, unk04;
    SearchVector start, end;
    unsigned int unk20, unk24, unk28;
    float gridSize;
    SearchPool pool;
    SearchHeapA open, closed;
    SearchHeapB incoming, outgoing;
    SearchHeapC links;
    SearchFinal finalState;
    FUN_006ed100();
};
struct CloseRequestAccess : PathingRequestClosePoint
{
    PathingLocation& GetOffsetC();
};
struct CloseLocationAccess : PathingLocation
{
};
struct CloseMeshAccess : NavMesh
{
    const NavMeshInfo* FUN_0068efb0();
    NiPoint3 FUN_00558220(unsigned short);
};
struct CloseMeshPointerAccess : NavMeshPtr
{
    NavMesh* FUN_00458b50();
};
struct ClosePointAccess : NiPoint3
{
};
struct CloseNodeAccess : PacketNodeRecord
{
};
struct CloseSolutionAccess : PathingSolution
{
    void* table;
    void* nodes;
    unsigned int nodeCount;
    unsigned int capacity;
    void* virtualNodes;
    unsigned int virtualNodeCount;
    unsigned int currentNode;
    unsigned int nextNode;
};
struct CloseTriangle
{
    CloseMeshAccess* mesh;
    unsigned short triangle;
    unsigned short flags;
    float cost;
    unsigned int parent;
    unsigned int state;
};
template <class T> struct CloseArray
{
    void* table;
    T* buffer;
    unsigned int size;
    unsigned int capacity;
};
struct CloseTriangleArray : CloseArray<CloseTriangle>
{
    void* allocator;
    CloseTriangleArray(int, int, void*);
    ~CloseTriangleArray();
};
struct CloseLinkArray : CloseArray<unsigned int>
{
    void* allocator;
    CloseLinkArray(int, int, void*);
    ~CloseLinkArray();
};
struct ClosePointArray : CloseArray<NiPoint3>
{
    void* allocator;
    ClosePointArray(int, int, void*);
    ~ClosePointArray();
};
struct CloseSearchBase
{
    void* table;
    void* poolBegin;
    void* poolEnd;
    void* poolCursor;
    unsigned int poolCapacity;
    void* buckets[2039];
    unsigned int bucketCount;
    float heapScale;
    void* heapBuckets[20];
    void* current;
    void* goal;
    unsigned int iterations;
    bool completed;
};
struct ClosePointSearch : CloseSearchBase
{
    PathingRequestClosePoint* request;
    NiPoint3 target;
    float radius;
    unsigned int flags;
    NiPoint3 origin;
    float bestDistance;
    bool found;
    NiPoint3 nearest;
    ClosePointSearch();
    ~ClosePointSearch();
};
struct ClosePathSmoother : CloseSearchBase
{
    PathingRequestClosePoint* request;
    PathingSolution* solution;
    NiPoint3 origin;
    NiPoint3 goalPoint;
    bool hasGoal;
    unsigned int segment;
    unsigned int node;
    CloseArray<NiPoint3> points;
    CloseArray<NiPoint3> normals;
    CloseArray<NiPoint3> edges;
    CloseArray<NiPoint3> corners;
    unsigned int startIndex;
    unsigned int endIndex;
    CloseArray<unsigned int> links;
    CloseArray<float> costs;
    CloseArray<void*> incoming;
    CloseArray<void*> outgoing;
    unsigned int result;
    ClosePathSmoother();
    ~ClosePathSmoother();
};
struct CloseEndLocation : FNV_PathingLocation_Canonical
{
    CloseEndLocation(const NiPoint3&, const NavMeshInfo*);
    ~CloseEndLocation();
};
struct ClosePointPair
{
    NiPoint3 first;
    NiPoint3 second;
    ClosePointPair();
};
void FUN_006d99a0(NiPoint3*, float, PathingLocation*, PathingLocation*, float);

// Builds a path from the request's start location to its target, smooths it into the solution, and optionally adjusts the first node.
// @fnv 0x006d0be0
bool FUN_006d0be0(PathingRequestClosePoint* request, PathingSolution* solution)
{
    AutoMemHelper eb(45, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\Pathfind.cpp",
                     179);
    if (!reinterpret_cast<::NLLocation *>((((CloseLocationAccess*)&((CloseRequestAccess*)request)->GetOffsetC())))->UpdateMeshLocation())
        return ::InitSolutionEndpoints((::PFRequest *)(request), (::PFSolution *)(solution));
    NavMeshPtr h;
    unsigned short q = 0xffff;
    if (!((CloseRequestAccess*)request)->GetOffsetC().FindNavMeshTriangle(h, q))
        return ::InitSolutionEndpoints((::PFRequest *)(request), (::PFSolution *)(solution));
    if (!reinterpret_cast<::FUN_006a9520_Class *>((((CloseLocationAccess*)((::PathingLocation *)(::FUN_006a9540((char *)(((CloseRequestAccess*)request))))))))->FUN_006a9520())
    {
        if (!reinterpret_cast<::PathingLocationProxy *>((((CloseLocationAccess*)((::PathingLocation *)(::FUN_006a9540((char *)(((CloseRequestAccess*)request))))))))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
            return ::InitSolutionEndpoints((::PFRequest *)(request), (::PFSolution *)(solution));
        NavMeshPtr targetMesh;
        unsigned short targetTriangle = 0xffff;
        if (!((::PathingLocation *)(::FUN_006a9540((char *)(((CloseRequestAccess*)request)))))->FindNavMeshTriangle(targetMesh, targetTriangle))
            return ::InitSolutionEndpoints((::PFRequest *)(request), (::PFSolution *)(solution));
    }
    CloseTriangle f;
    f.mesh = (CloseMeshAccess*)((CloseMeshPointerAccess*)&h)->FUN_00458b50();
    f.triangle = q;
    NiPoint3 a = reinterpret_cast<::TaskQueueInterface *>((void *)&(((CloseRequestAccess*)request)->GetOffsetC()))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    ClosePointSearch p;
    CloseTriangleArray ba(32, 0, 0);
    CloseLinkArray s(32, 0, 0);
    if (!reinterpret_cast<::FleeSearch *>(&(p))->StartFleeSearch((::FleeRequest *)(request), (const ::FleeStartNode *)(::CloseTriangle *)(&f), (::FleePath *)(::CloseTriangleArray *)(&ba), (std::uintptr_t)(&s)))
        return false;
    CloseTriangle i = (*(::CloseTriangle *)(reinterpret_cast<::FUN_006b3160_shell *>(&(ba))->FUN_006b3160(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(ba))->GetName())) - 1)));
    NiPoint3 e = reinterpret_cast<::NavMesh *>((i.mesh))->GetNavMeshData(i.triangle);
    CloseEndLocation b(e, reinterpret_cast<::FUN_0068efb0_shell *>((i.mesh))->FUN_0068efb0());
    ClosePointPair k;
    if (::FUN_006d4570((::LocationView *)(::PathingLocation *)((PathingLocation*)&b), ::GetFloatAtOffset68((const char *)(((CloseRequestAccess*)request))), (::LocationView *)(::ClosePointPair *)(&k)))
    {
        NiPoint3 j = e - k.second;
        float p = reinterpret_cast<::NiPoint3 *>((((ClosePointAccess*)&j)))->GetLengthSquared();
        if (p < ::GetFloatAtOffset68((const char *)(((CloseRequestAccess*)request))))
            e = k.second + j * ::GetFloatAtOffset68((const char *)(((CloseRequestAccess*)request)));
    }
    reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((((CloseSolutionAccess*)solution)))->AddPathingItem((void *)&(a), (::TESObjectREFR *)(reinterpret_cast<::FUN_0068efb0_shell *>((f.mesh))->FUN_0068efb0()));
    reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((((CloseSolutionAccess*)solution)))->AddPathingItem((void *)&(e), (::TESObjectREFR *)(reinterpret_cast<::FUN_0068efb0_shell *>((i.mesh))->FUN_0068efb0()));
    ((CloseSolutionAccess*)solution)->currentNode = 0;
    ((CloseSolutionAccess*)solution)->nextNode = 1;
    ClosePathSmoother l;
    ClosePointArray c(32, 0, 0);
    bool cf = reinterpret_cast<::PathSmootherPOVSearch *>(&(l))->SearchForPath((::PathingRequest *)(request), (*(const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(&ba)), (*(const ::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *)(&s)), a, e, solution, (::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *)(0), (::BSSimpleArray<const ::NavMeshInfo *, 1024> *)(0));
    if (cf)
    {
        if (((bool)(::FUN_006ca4c0((char *)(((CloseRequestAccess*)request))))) && ::GetObjectFlags((char *)(((CloseSolutionAccess*)solution))) > 2)
        {
            CloseNodeAccess* j = ((::CloseNodeAccess *)(reinterpret_cast<::FUN_006e7970_shell *>((((CloseSolutionAccess*)solution)))->FUN_006e7970(0)));
            CloseNodeAccess* h = ((::CloseNodeAccess *)(reinterpret_cast<::FUN_006e7970_shell *>((((CloseSolutionAccess*)solution)))->FUN_006e7970(1)));
            if (j && h)
            {
                PathingLocation e((*(::PathingLocation *)(reinterpret_cast<::BaseProcess *>((j))->GetCurrentProcessData())));
                PathingLocation p((*(::PathingLocation *)(reinterpret_cast<::BaseProcess *>((h))->GetCurrentProcessData())));
                NiPoint3 i;
                FUN_006d99a0(&i, ::GetField90Float((char *)(((CloseRequestAccess*)request))), &e, &p,
                             ::GetFloatAtOffset68((const char *)(((CloseRequestAccess*)request))));
                reinterpret_cast<::FUN_006b0570_shell *>((j))->FUN_006b0570((::NiColor *)(&i));
            }
        }
    }
    else
    {
        reinterpret_cast<::FUN_006c9fa0_shell *>((((CloseSolutionAccess*)solution)))->SetByteAtOffset40(1);
    }
    return cf;
}

class PFPoint3
{
  public:
    float x;
    float y;
    float z;

    PFPoint3();
    PFPoint3 operator+(const PFPoint3& arOther) const;
    PFPoint3 operator-(const PFPoint3& arOther) const;
    PFPoint3& operator+=(const PFPoint3& arOther);
    PFPoint3& operator*=(float afScale);
};

PFPoint3 __cdecl operator*(float afScale, const PFPoint3& arPoint);

float __cdecl PFCos(float afAngle);
float __cdecl PFRandomAngle();


struct PFCell
{
};

struct PFLocation
{
};

struct PFAvoidNodes
{
};

struct PFRequest
{
};

struct PFSolution
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int iState;
    int iResult;

};

// Computes a goal point from the start location and avoid direction or a random angle, snaps its height, and adds start and goal points to the solution.
// @fnv 0x006d12a0
bool __cdecl InitSolutionEndpoints(PFRequest* apRequest, PFSolution* apSolution)
{
    AutoMemContext kMemContext5((MEM_CONTEXT)0x2d, true,
                                "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\Pathfind.cpp",
                                0x12f);
    PFPoint3 kStart2 = (*(::PFPoint3 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((::PFLocation *)(::GetOffsetC((std::intptr_t)(apRequest))))))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
    const PFPoint3& rkStart5 = kStart2;
    PFCell* pCellA = ((::PFCell *)(reinterpret_cast<::PathingLocation *>((void *)(((::PFLocation *)(::GetOffsetC((std::intptr_t)(apRequest))))))->GetContainingCell()));
    std::uintptr_t uiSpace2 = (std::uintptr_t)reinterpret_cast<::BGSTerrainManager *>((((::PFLocation *)(::GetOffsetC((std::intptr_t)(apRequest))))))->GetMinLevel();
    PFPoint3 kDir3;
    PFPoint3 kGoal9;

    if (((::PFAvoidNodes *)(reinterpret_cast<::_Dummy_0069e390 *>((void *)(apRequest))->GetString())) && !reinterpret_cast<::FUN_0076b610_Class *>((void *)(((::PFAvoidNodes *)(reinterpret_cast<::_Dummy_0069e390 *>((void *)(apRequest))->GetString()))))->FUN_0076b610())
    {
        reinterpret_cast<::AvoidNodeList *>((((::PFAvoidNodes *)(reinterpret_cast<::_Dummy_0069e390 *>((void *)(apRequest))->GetString()))))->FUN_006dc9f0((const ::NiPoint3 &)(rkStart5), (::NiPoint3 &)(kDir3));
        kGoal9 = rkStart5 - kDir3;
        reinterpret_cast<::FUN_004a0c10_s *>(&(kGoal9))->FUN_004a0c10();
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::PFPoint3 &)(kGoal9))->FUN_00439180(reinterpret_cast<::FUN_006d2c20_Class *>((void *)(apRequest))->GetFloatAtOffsetB0());
        reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::PFPoint3 &)(kGoal9))->FUN_0063c8a0((void *)&(rkStart5));
    }
    else
    {
        kDir3 = rkStart5;
        float fAngle9 = PFRandomAngle();
        kGoal9 = kDir3 + PFCos(fAngle9) * reinterpret_cast<::FUN_006d2c20_Class *>((void *)(apRequest))->GetFloatAtOffsetB0() * (*reinterpret_cast<const ::PFPoint3 *>(&::DAT_011a946c)) +
                 ::FUN_004e44b0(fAngle9) * reinterpret_cast<::FUN_006d2c20_Class *>((void *)(apRequest))->GetFloatAtOffsetB0() * (*reinterpret_cast<const ::PFPoint3 *>(&::DAT_011a9478));
    }
    {

        float m_fGlyphExtent;
        if (pCellA && reinterpret_cast<::FakeCell *>((pCellA))->FUN_005547c0((const ::NiPoint3 &)(kGoal9), m_fGlyphExtent))
            kGoal9.z = m_fGlyphExtent;
    }

    reinterpret_cast<::FUN_006d1520_shell *>((apSolution))->AddPathingLocation((const ::NiPoint3 &)(rkStart5), (::TESObjectCELL *)(pCellA), (::TESWorldSpace *)(uiSpace2));
    reinterpret_cast<::FUN_006d1520_shell *>((apSolution))->AddPathingLocation((const ::NiPoint3 &)(kGoal9), (::TESObjectCELL *)(pCellA), (::TESWorldSpace *)(uiSpace2));
    apSolution->iState = 0;
    apSolution->iResult = 1;
    return true;
}

struct MeshView
{
    NiPoint3 FUN_00558220(unsigned short);
    const NavMeshInfo* FUN_0068efb0();
};
struct MeshPointerView
{
    MeshView* mesh;
    MeshView* FUN_00458b50();
};
struct LocationView
{
};
struct RequestView;
struct SolutionView;
struct RequestView
{
    void* vtable;
    unsigned int refCount;
    unsigned int requestFlags;
    PathingLocation origin;
    PathingLocation destination;
    unsigned int flags5c, flags60, flags64, flags68, flags6c, flags70, flags74, flags78;
    NiPoint3 position, direction;
    void* filter;
    unsigned int flags98, flags9c, flagsa0, flagsa4, flagsa8;
    RequestView(RequestView*);
    ~RequestView();
    void FUN_006d1bc0(PathingLocation*);
};
struct NodeView
{
};
struct SolutionView
{
    void* table;
    unsigned int refCount;
    void* nodes;
    unsigned int nodeCount;
    unsigned int reserved, flags14, flags18, field1c;
};
struct MeshTriangle
{
    MeshView* mesh;
    unsigned short triangle;
    unsigned short flags;
    NiPoint3 location;
};
struct TriangleArray
{
    void* table;
    MeshTriangle* data;
    unsigned int size, capacity;
    void* heap;
    TriangleArray(unsigned int, unsigned int, void*);
    ~TriangleArray();
};
struct MeshArray
{
    void* table;
    void* data;
    unsigned int size, capacity;
    void* heap;
    MeshArray(unsigned int, unsigned int, void*);
    ~MeshArray();
};
struct SearchResult
{
};
struct DetailedBuilder
{
    void* table;
    void* allocation;
    unsigned int allocationSize;
    void* allocationEnd;
    void* nextAllocation;
    void* hashBuckets[2039];
    unsigned int hashCount;
    float cost;
    void* costBuckets[20];
    void* current;
    void* goal;
    void* partial;
    unsigned int state;
    void* field2058;
    void* field205c;
    void* field2060;
    void* field2064;
    void* field2068;
    void* field206c;
    NavMeshPtr bestMesh;
    unsigned int flags2074;
    unsigned int field2078, field207c, field2080, field2084, field2088, field208c;
    void* firstFallback;
    void* secondFallback;
    void* thirdFallback;
    float maxCost;
    DetailedBuilder();
    ~DetailedBuilder();
};
struct DestinationLocation : PathingLocation
{
    DestinationLocation(NiPoint3 const&, const NavMeshInfo*, unsigned short);
    ~DestinationLocation();
};
// @fnv 0x006d1660
bool __cdecl FUN_006d1660(RequestView* request, SolutionView* solution)
{
    AutoMemHelper cf(45, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\Pathfind.cpp",
                     378);
    if (!reinterpret_cast<::NLLocation *>((((::LocationView *)(::GetOffsetC((std::intptr_t)(request))))))->UpdateMeshLocation())
        return false;
    NavMeshPtr h;
    unsigned short b = 65535;
    if (!reinterpret_cast<::PathingLocation *>((((::LocationView *)(::GetOffsetC((std::intptr_t)(request))))))->FindNavMeshTriangle((*(::NavMeshPtr *)(&h)), (*(unsigned short *)(&b))))
        return false;
    MeshTriangle eb;
    eb.mesh = ((MeshPointerView*)&h)->FUN_00458b50();
    eb.triangle = b;
    NiPoint3 i = reinterpret_cast<::TaskQueueInterface *>((((::LocationView *)(::GetOffsetC((std::intptr_t)(request))))))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    bool a = false;
    bool f = false;
    DetailedBuilder p;
    TriangleArray ba(32, 0, 0);
    MeshArray s(32, 0, 0);
    bool q = true;
    if (!reinterpret_cast<::fnv_006aa780::FUN_006aa780_Class *>(&(p))->FUN_006aa780((::fnv_006aa780::World *)(request), (const ::fnv_006aa780::Location *)(::MeshTriangle *)(&eb), (std::intptr_t)(&ba), (std::intptr_t)(&s)))
    {
        if (((void *)(reinterpret_cast<::FUN_006d1be0_Class *>(&(p))->GetField2090())))
            a = reinterpret_cast<::HX *>(&(p))->FUN_006a8290((::PNode *)(void *)(((void *)(reinterpret_cast<::FUN_006d1be0_Class *>(&(p))->GetField2090()))), (::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(::TriangleArray *)(&ba), (::BSSimpleArray< ::EdgeExtraInfo, 1024> *)(::MeshArray *)(&s));
        if (!a && ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_006d1c00_Class *>(&(p))->GetField2094())))
            f = reinterpret_cast<::HX *>(&(p))->FUN_006a8290((::PNode *)(void *)(((void *)(std::uintptr_t)(reinterpret_cast<::FUN_006d1c00_Class *>(&(p))->GetField2094()))), (::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(::TriangleArray *)(&ba), (::BSSimpleArray< ::EdgeExtraInfo, 1024> *)(::MeshArray *)(&s));
        if (!a && !f && ((void *)(std::uintptr_t)(reinterpret_cast<::FUN_006d1c20_Class *>(&(p))->GetField2098())))
            f = reinterpret_cast<::HX *>(&(p))->FUN_006a8290((::PNode *)(void *)(((void *)(std::uintptr_t)(reinterpret_cast<::FUN_006d1c20_Class *>(&(p))->GetField2098()))), (::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(::TriangleArray *)(&ba), (::BSSimpleArray< ::EdgeExtraInfo, 1024> *)(::MeshArray *)(&s));
        if (!a && !f)
        {
            q = false;
            f = true;
        }
    }
    if (q)
    {
        MeshTriangle p = (*(::MeshTriangle *)(reinterpret_cast<::FUN_006b3160_shell *>(&(ba))->FUN_006b3160(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(ba))->GetName())) - 1)));
        NiPoint3 j = reinterpret_cast<::NavMesh *>((p.mesh))->GetNavMeshData(p.triangle);
        ::ResetPathingSolution((::PathingSolution *)(solution));
        RequestView a(request);
        DestinationLocation h(j, reinterpret_cast<::FUN_0068efb0_shell *>((p.mesh))->FUN_0068efb0(), p.triangle);
        reinterpret_cast<::PathingRequest *>(&(a))->SetDestination(&h);
        q = ::Pathing::BuildPath((::PathingRequest *)(::RequestView *)(&a), (::PathingSolution *)(solution));
    }
    if (!q && (a || f))
    {
        NavMeshPtr endMesh;
        unsigned short endTriangle = 0;
        if (reinterpret_cast<::FUN_006e1770_shell *>((((::SearchResult *)(std::uintptr_t)(reinterpret_cast<::FUN_006d1c40_Class *>(&(p))->FUN_006d1c40()))))->FUN_006e1770((std::uintptr_t)(&endMesh), (std::uintptr_t)(&endTriangle)))
        {
            unsigned int p = ((int)(reinterpret_cast<::BGSTerrainManager *>((solution))->GetMinLevel()));
            if (p == 0xffffffff || !::FUN_005a4320((char *)(solution)))
            {
                reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((solution))->AddPathingItem((void *)&(i), (::TESObjectREFR *)(reinterpret_cast<::FUN_0068efb0_shell *>((eb.mesh))->FUN_0068efb0()));
                solution->field1c = 0;
            }
            NodeView* a = ((::NodeView *)(reinterpret_cast<::FUN_006e78b0_shell *>((solution))->FUN_006e78b0(p)));
            if (a)
            {
                NiPoint3 endCenter = reinterpret_cast<::NavMesh *>((((::MeshView *)(::FUN_00559450((int *)(((MeshPointerView*)&endMesh)))))))->GetNavMeshData(endTriangle);
                DestinationLocation j(endCenter, reinterpret_cast<::FUN_0068efb0_shell *>((((::MeshView *)(::FUN_00559450((int *)(((MeshPointerView*)&endMesh)))))))->FUN_0068efb0(),
                                      endTriangle);
                reinterpret_cast<::fnv_006f5060::FUN_006f5060_Class *>((a))->SetLocation((*(const ::fnv_006f5060::PathingLocation *)(&j)));
            }
        }
    }
    return q;
}

namespace fnv_006d1f80 {
struct MeshTriangle
{
    NavMesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    unsigned int a, b, c;
};
struct PathRecord
{
    NavMesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    unsigned int a, b, c;
};
struct MeshRoute
{
    void* table;
    PathRecord* data;
    unsigned int size, capacity;
    ScrapHeapBuffer* heap;
    MeshRoute(unsigned int, unsigned int, ScrapHeapBuffer*);
    ~MeshRoute();
};
struct TransitionRoute
{
    void* table;
    void* data;
    unsigned int size, capacity;
    ScrapHeapBuffer* heap;
    TransitionRoute(unsigned int, unsigned int, ScrapHeapBuffer*);
    ~TransitionRoute();
};
struct SmoothRoute
{
    void* table;
    void* data;
    unsigned int size, capacity;
    ScrapHeapBuffer* heap;
    SmoothRoute(unsigned int, unsigned int, ScrapHeapBuffer*);
    ~SmoothRoute();
};
struct SearchNode;
struct SearchState
{
    void* table;
    void* openData;
    unsigned int openSize, openCapacity;
    void* openAllocator;
    SearchNode* buckets[2039];
    unsigned int bucketCount;
    float priority;
    SearchNode* priorityBuckets[20];
    unsigned int unk2048;
    unsigned int unk204c;
    unsigned int unk2050;
    unsigned int unk2054;
    unsigned int unk2058;
    unsigned int unk205c;
    unsigned int unk2060;
    unsigned int unk2064;
    unsigned int unk2068;
    unsigned int unk206c;
    unsigned int unk2070;
    unsigned int unk2074;
    unsigned int unk2078;
    unsigned int unk207c;
    unsigned int unk2080;
    unsigned int unk2084;
    unsigned int unk2088;
    unsigned int unk208c;
    unsigned int unk2090;
    unsigned int unk2094;
    unsigned int unk2098;
    unsigned int unk209c;
    unsigned int unk20a0;
    unsigned int unk20a4;
    unsigned int unk20a8;
    unsigned int unk20ac;
    unsigned int unk20b0;
    unsigned int unk20b4;
    unsigned int unk20b8;
    unsigned int unk20bc;
    unsigned int unk20c0;
    unsigned int unk20c4;
    unsigned int unk20c8;
    unsigned int unk20cc;
    unsigned int unk20d0;
    unsigned int unk20d4;
    unsigned int unk20d8;
    unsigned int unk20dc;
    unsigned int unk20e0;
    unsigned int unk20e4;
    unsigned int unk20e8;
    unsigned int unk20ec;
    unsigned int unk20f0;
    unsigned int unk20f4;
    unsigned int unk20f8;
    unsigned int unk20fc;
    unsigned int unk2100;
    unsigned int unk2104;
    SearchState();
    ~SearchState();
};
struct DetailedBuilder
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
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    DetailedBuilder();
    ~DetailedBuilder();
};
struct LocationOps
{
};
struct RequestOps
{
};
struct MeshOps
{
    void FUN_00558220(NiPoint3*, unsigned short);
    const NavMeshInfo* FUN_0068efb0();
};
struct SolutionOps
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int beginIndex, endIndex;
};
struct NavPointerOps
{
    NavMesh* FUN_00458b50();
};
// Validates both request locations, runs a search between their navmesh triangles, and fills result with the start and end points of the found path.
// @fnv 0x006d1f80
bool BuildPathBetweenLocations(RequestOps* request, SolutionOps* result)
{
    AutoMemContext cf((MEM_CONTEXT)45, true,
                      "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\Pathfind.cpp", 575);
    if (!reinterpret_cast<::NLLocation *>((((::fnv_006d1f80::LocationOps *)(::GetOffsetC((std::intptr_t)(request))))))->UpdateMeshLocation())
        return false;
    NavMeshPtr f;
    unsigned short k = 0xffff;
    if (!reinterpret_cast<::PathingLocation *>((((::fnv_006d1f80::LocationOps *)(::GetOffsetC((std::intptr_t)(request))))))->FindNavMeshTriangle(f, k))
        return false;
    MeshTriangle s;
    s.mesh = ((NavPointerOps*)&f)->FUN_00458b50();
    s.triangle = k;
    NiPoint3 p = reinterpret_cast<::TaskQueueInterface *>((void *)(((::fnv_006d1f80::LocationOps *)(::GetOffsetC((std::intptr_t)(request))))))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    if (!reinterpret_cast<::NLLocation *>((((::fnv_006d1f80::LocationOps *)(::FUN_006a9540((char *)(request))))))->UpdateMeshLocation())
        return false;
    NavMeshPtr ba;
    unsigned short a = 0xffff;
    if (!reinterpret_cast<::PathingLocation *>((((::fnv_006d1f80::LocationOps *)(::FUN_006a9540((char *)(request))))))->FindNavMeshTriangle(ba, a))
        return false;
    MeshTriangle b;
    b.mesh = ((NavPointerOps*)&ba)->FUN_00458b50();
    b.triangle = a;
    SearchState eb;
    MeshRoute q(32, 0, 0);
    TransitionRoute i(32, 0, 0);
    if (!reinterpret_cast<::FUN_006ac340_shell *>(&(eb))->BuildPathingLocationAndSearch((::PathingRequest *)(request), (const ::NavMeshTriangleReference &)(s), (const ::NavMeshTriangleReference &)(b), (::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)&(q), (::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *)&(i)))
        return false;
    PathRecord h = (*(::fnv_006d1f80::PathRecord *)(reinterpret_cast<::FUN_006b3160_shell *>(&(q))->FUN_006b3160(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(q))->GetName())) - 1)));
    NiPoint3 e;
    e = reinterpret_cast<::NavMesh *>((((MeshOps*)h.mesh)))->GetNavMeshData(h.triangle);
    reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((result))->AddPathingItem((void *)&(p), (::TESObjectREFR *)(reinterpret_cast<::FUN_0068efb0_shell *>((((MeshOps*)s.mesh)))->FUN_0068efb0()));
    reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((result))->AddPathingItem((void *)&(e), (::TESObjectREFR *)(reinterpret_cast<::FUN_0068efb0_shell *>((((MeshOps*)h.mesh)))->FUN_0068efb0()));
    result->beginIndex = 0;
    result->endIndex = 1;
    DetailedBuilder l;
    SmoothRoute c(32, 0, 0);
    reinterpret_cast<::FUN_006ed530_cls *>(&(l))->FUN_006ed530((::NodeA *)(request), (::ArgObj *)&(q), (::ArgObj *)&(i), (::Triple *)&(p), (::Triple *)&(e), (std::intptr_t)(result), (::Gate *)(0), true);
    result->beginIndex = 0;
    result->endIndex = ::FUN_005a4320((char *)(result)) - 1;
    return true;
}
}  // namespace fnv_006d1f80

struct FUN_006815c0
{
    float x, y, z;
    FUN_006815c0();
};
struct RouteMesh
{
    void* FUN_0068efb0();
};
struct FUN_0042fb00
{
    RouteMesh* value;
    FUN_0042fb00();
    ~FUN_0042fb00();
    RouteMesh* FUN_00458b50();
};
struct RouteLocation
{
};
struct RouteNode
{
    RouteMesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    int unk08, unk0c, unk10;
};
struct RoutePoint
{
};
struct FUN_0042f800
{
    void* vtable;
    FUN_0042fb00* data;
    unsigned int size, capacity;
    FUN_0042f800();
    ~FUN_0042f800();
    FUN_0042fb00* FUN_00877a30(unsigned int);
};
struct FUN_005e0510
{
    void* vtable;
    void** data;
    unsigned int size, capacity;
    FUN_005e0510();
    ~FUN_005e0510();
    void FUN_007cb2e0(void* const&);
};
struct FUN_006abbb0
{
    void* vtable;
    RoutePoint* data;
    unsigned int size, capacity;
    void* allocator;
    FUN_006abbb0();
    ~FUN_006abbb0();
    RoutePoint* FUN_006dad90(unsigned int);
};
struct RouteEdge
{
    RouteMesh* mesh;
    unsigned short triangle, flags;
    int index;
};
struct FUN_006ad250
{
    void* vtable;
    RouteEdge* data;
    unsigned int size, capacity;
    void* allocator;
    FUN_006ad250(unsigned int, int, int);
    ~FUN_006ad250();
    RouteEdge* FUN_006a7af0(unsigned int);
};
struct FUN_006e2420
{
    void* vtable;
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
    FUN_006e2420();
    ~FUN_006e2420();
};
struct FUN_006a6a40
{
    void* vtable;
    void* nodeData;
    unsigned int nodeSize, nodeCapacity;
    void* allocator;
    float priority;
    void* openBuckets[2038];
    int openCount;
    float closedPriority;
    void* closedBuckets[20];
    int unk2048;
    int unk204c;
    int unk2050;
    int unk2054;
    int unk2058;
    int unk205c;
    int unk2060;
    int unk2064;
    int unk2068;
    int unk206c;
    int unk2070;
    int unk2074;
    int unk2078;
    int unk207c;
    int unk2080;
    int unk2084;
    int unk2088;
    int unk208c;
    int unk2090;
    int unk2094;
    int unk2098;
    int unk209c;
    int unk20a0;
    FUN_006a6a40();
    ~FUN_006a6a40();
};
void __cdecl FUN_006d91d0(FUN_0042f800*);
bool __cdecl FUN_00696540(FUN_006815c0*, FUN_006815c0*, FUN_006815c0*, FUN_006815c0*);
extern bool DAT_011d74ec;
// Builds mesh info, runs the path finder between start and end locations, trims and adjusts the resulting path points, and returns whether a path was found.
// @fnv 0x006d5490
bool __cdecl FUN_006d5490(RouteLocation* start, RouteLocation* end, void* options, float* length, FUN_006abbb0* output)
{
    FUN_0042f800 meshes2;
    FUN_006d91d0(&meshes2);
    FUN_005e0510 infos61;
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshes2))->GetName())); ++i)
        reinterpret_cast<::FUN_00438690 *>(&(infos61))->FUN_007cb2e0((unsigned int *)&(const void *const &)(((void *)(reinterpret_cast<::FUN_0068efb0_shell *>((((::RouteMesh *)(::FUN_00559450((int *)(meshes2.FUN_00877a30(i)))))))->FUN_0068efb0()))));
    if (!reinterpret_cast<::NLLocation *>((start))->UpdateMeshLocation())
    {
        if (length)
            *length = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(end))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))))))->ComputeMagnitude();
        if (!reinterpret_cast<::NLLocation *>((end))->UpdateMeshLocation())
            return true;
        return false;
    }
    if (!reinterpret_cast<::NLLocation *>((end))->UpdateMeshLocation())
    {
        if (length)
            *length = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(end))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))))))->ComputeMagnitude();
        return false;
    }
    FUN_0042fb00 startMesh70;
    unsigned short startTriangle13 = 0xffff;
    if (!reinterpret_cast<::PathingLocation *>((start))->FindNavMeshTriangle((*(::NavMeshPtr *)(&startMesh70)), (*(unsigned short *)(&startTriangle13))))
    {
        if (length)
            *length = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(end))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))))))->ComputeMagnitude();
        return false;
    }
    RouteNode startNode7;
    startNode7.mesh = startMesh70.FUN_00458b50();
    startNode7.triangle = startTriangle13;
    FUN_006815c0 startPosition24 = (*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
    FUN_0042fb00 endMesh3;
    unsigned short endTriangle1 = 0xffff;
    if (!reinterpret_cast<::PathingLocation *>((end))->FindNavMeshTriangle((*(::NavMeshPtr *)(&endMesh3)), (*(unsigned short *)(&endTriangle1))))
    {
        if (length)
            *length = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(end))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))))))->ComputeMagnitude();
        return false;
    }
    RouteNode endNode1;
    endNode1.mesh = endMesh3.FUN_00458b50();
    endNode1.triangle = endTriangle1;
    FUN_006815c0 endPosition1 = (*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(end))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
    FUN_006a6a40 finder20;
    FUN_006abbb0 localPath23;
    FUN_006abbb0* path8 = output ? output : &localPath23;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((path8))->Clear(0);
    if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((path8))->FUN_0084e3a0())) < 32)
        reinterpret_cast<::fnv_006db0d0::FUN_006db0d0_Class *>((path8))->SetPosition(32);
    FUN_006ad250 edges33(32, 0, 0);
    FUN_006e2420 filter1;
    reinterpret_cast<::PathingRequest *>(&(filter1))->SetAvoidNodeArray((::BSSimpleArray<void *, 1024> *)(options));
    if (!reinterpret_cast<::NavMeshSearch *>(&(finder20))->ComputePath((const ::PathingRequest *)(::FUN_006e2420 *)(&filter1), (*(const ::NavMeshTriangleReference *)(&startNode7)), (*(const ::NavMeshTriangleReference *)(&endNode1)), (::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(path8), (::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *)(::FUN_006ad250 *)(&edges33), (::BSSimpleArray< ::NavMeshInfo *, 1024> *)(::FUN_005e0510 *)(&infos61)))
    {
        if (length)
            *length = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(end))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))))))->ComputeMagnitude();
        return false;
    }
    RoutePoint* first4 = path8->FUN_006dad90(0);
    reinterpret_cast<::FUN_006d61b0_Class *>((first4))->SetFromFloat3((const float *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))));
    if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((path8))->GetName())) > 1)
    {
        RoutePoint* last = path8->FUN_006dad90(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((path8))->GetName())) - 1);
        reinterpret_cast<::FUN_006d61b0_Class *>((last))->SetFromFloat3((const float *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(end))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))));
    }
    if (DAT_011d74ec)
        ::FUN_0040fbe0();
    if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((path8))->GetName())) > 2 && (length || output))
    {
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((path8))->GetName())) - 2; ++i)
        {
            RoutePoint* current692 = path8->FUN_006dad90(i);
            FUN_006815c0 origin520 = (*(class ::FUN_006815c0 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>((current692))->FUN_006a6eb0({})));
            RouteEdge* edge96 = edges33.FUN_006a7af0(i);
            FUN_006815c0 left938, right314;
            reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>((edge96->mesh))->FUN_0068f0c0(edge96->triangle, edge96->index, (::NiPoint3 *)(class ::FUN_006815c0 *)(&left938), (::NiPoint3 *)(class ::FUN_006815c0 *)(&right314));
            unsigned int j752 = i + 2;
            for (j752 = i + 2; j752 < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((path8))->GetName())); ++j752)
            {
                RoutePoint* next25 = path8->FUN_006dad90(j752);
                FUN_006815c0 nextPos12 = (*(class ::FUN_006815c0 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>((next25))->FUN_006a6eb0({})));
                unsigned int edgeIndex47 = j752 - 1;
                RouteEdge* nextEdge20 = edges33.FUN_006a7af0(edgeIndex47);
                FUN_006815c0 newLeft12, newRight5;
                reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>((nextEdge20->mesh))->FUN_0068f0c0(nextEdge20->triangle, nextEdge20->index, (::NiPoint3 *)(class ::FUN_006815c0 *)(&newLeft12), (::NiPoint3 *)(class ::FUN_006815c0 *)(&newRight5));
                FUN_006815c0 intersection30;
                if (::FUN_006ba7e0((std::uintptr_t)(&newLeft12), (::FUN_006ba7e0_cls *)(class ::FUN_006815c0 *)(&newRight5), (std::uintptr_t)(&origin520), (::FUN_006ba7e0_cls *)(class ::FUN_006815c0 *)(&left938), (::NiPoint3 *)(class ::FUN_006815c0 *)(&intersection30)))
                    left938 = intersection30;
                else
                    left938 = newLeft12;
                if (::FUN_006ba7e0((std::uintptr_t)(&newLeft12), (::FUN_006ba7e0_cls *)(class ::FUN_006815c0 *)(&newRight5), (std::uintptr_t)(&origin520), (::FUN_006ba7e0_cls *)(class ::FUN_006815c0 *)(&right314), (::NiPoint3 *)(class ::FUN_006815c0 *)(&intersection30)))
                    right314 = intersection30;
                else
                    right314 = newRight5;
                if (DAT_011d74ec)
                    ::FUN_0040fbe0();
                if (!FUN_00696540(&origin520, &nextPos12, &left938, &right314))
                    break;
            }
            if (j752 > i + 2)
            {
                unsigned int remove = j752 - i - 2;
                reinterpret_cast<::FUN_006db140_Class *>((path8))->FUN_006db140(i + 1, remove, 0);
                reinterpret_cast<::FUN_0049f3c0_Class *>(&(edges33))->FUN_0049f3c0(i, remove, 0);
            }
        }
        if (DAT_011d74ec)
            ::FUN_0040fbe0();
        for (unsigned int i = 1; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((path8))->GetName())) - 1; ++i)
        {
            RoutePoint* nodeB5 = path8->FUN_006dad90(i);
            RoutePoint* previousB9 = path8->FUN_006dad90(i - 1);
            RouteEdge* edgeB6 = edges33.FUN_006a7af0(i - 1);
            FUN_006815c0 previousPosB26 = (*(class ::FUN_006815c0 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>((previousB9))->FUN_006a6eb0({})));
            FUN_006815c0 leftB4, rightB31;
            reinterpret_cast<::fnv_0068f0c0::FUN_0068f0c0_shell *>((edgeB6->mesh))->FUN_0068f0c0(edgeB6->triangle, edgeB6->index, (::NiPoint3 *)(class ::FUN_006815c0 *)(&leftB4), (::NiPoint3 *)(class ::FUN_006815c0 *)(&rightB31));
            FUN_006815c0 aB4 = (*(class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(previousPosB26))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(leftB4)))), bB61 = (*(class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(previousPosB26))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(rightB31))));
            if (reinterpret_cast<::TESCombatStyle *>((void *)&(aB4))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)&(bB61))->UpdateCombatStyle())
                reinterpret_cast<::FUN_006d61b0_Class *>((nodeB5))->SetFromFloat3((const float *)&(leftB4));
            else
                reinterpret_cast<::FUN_006d61b0_Class *>((nodeB5))->SetFromFloat3((const float *)&(rightB31));
        }
    }
    if (length)
    {
        *length = 0.0f;
        if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((path8))->GetName())) > 1)
        {
            FUN_006815c0 previous = (*(class ::FUN_006815c0 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>((path8->FUN_006dad90(0)))->FUN_006a6eb0({})));
            for (unsigned int i = 1; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((path8))->GetName())); ++i)
            {
                FUN_006815c0 current692 = (*(class ::FUN_006815c0 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>((path8->FUN_006dad90(i)))->FUN_006a6eb0({})));
                *length += reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const class ::FUN_006815c0 &)((*(class ::FUN_006815c0 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(current692))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(previous))))))->ComputeMagnitude();
                previous = current692;
            }
        }
    }
    if (DAT_011d74ec)
        ::FUN_0040fbe0();
    DAT_011d74ec = false;
    return true;
}

struct SpatialNode;

struct Vec3
{
    float x, y, z;
    void FUN_006815c0();
    Vec3 operator-(const Vec3& other) const;
    Vec3 operator+(const Vec3& other) const;
    Vec3 operator*(float amount) const;
    Vec3 Cross(const Vec3& other) const;
public:
    Vec3();
};
// Constructs the search grid: sets gridSize to 32.0 and initialises the open, closed, incoming, outgoing and links heaps from the pool.
// @fnv 0x006ed100
FUN_006ed100::FUN_006ed100()
    : gridSize(32.0f), open(0, 0, ((void *)((void *)&(pool)))), closed(0, 0, ((void *)((void *)&(pool)))),
      incoming(0, 0, ((void *)((void *)&(pool)))), outgoing(0, 0, ((void *)((void *)&(pool)))), links(0, 0, ((void *)((void *)&(pool))))
{}
struct Vec2
{
    float x, y;
    Vec2();
    Vec2(float x, float y);
};
struct GeometrySource
{
};
struct OutputList
{
};
struct SpatialNode
{
};
struct Triangle
{
    bool HasFlags();
    unsigned short* FUN_0069dec0(unsigned int);
    Vec3 FUN_00558220(unsigned short);
    Vec3 FUN_006971e0(unsigned short);
    void* FUN_005582f0();
};
struct TriangleRef
{
    bool HasFlags();
};
struct NodeCollection
{
    unsigned short* FUN_0069dec0(unsigned int);
};
struct CandidateSource;
struct ParentNode
{
    Triangle* FUN_005582f0(unsigned short);
    Vec3 FUN_00558220(unsigned short);
    Vec3 FUN_006971e0(unsigned short);
    void FUN_0068f040(Vec3**, unsigned short, unsigned short);
    void* FUN_0068efb0();
};
struct CandidateSource
{
    unsigned int pointer;
    CandidateSource();
    ~CandidateSource();
    void FUN_0042fb00();
    void FUN_0042fa40();
    Triangle* FUN_0068efb0();
    void FUN_0068f040(Vec3**, unsigned short, unsigned short);
    Triangle* FUN_005582f0(unsigned short);
    Vec3 FUN_00558220(unsigned short);
    Vec3 FUN_006971e0(unsigned short);
};
struct SearchCollection
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    SearchCollection(unsigned int, int, int);
    ~SearchCollection();
    void* FUN_00877a30(unsigned int);
};
struct MeshCollection
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    MeshCollection(unsigned int, int, int);
    ~MeshCollection();
    void* FUN_00877a30(unsigned int);
};
struct ResultPath
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    unsigned int unk28, unk2c;
    Vec3 position;
    Vec3 movement;
    Vec3 direction;
    ResultPath(const Vec3* start, void* node, unsigned short triangle);
    void FUN_006d32c0();
    ~ResultPath();
};
extern double __cdecl FUN_00408840(float value);

// Collects triangles near a source point, scores them by distance and edge type, and inserts matching result paths into the output list in sorted order.
// @fnv 0x006d62e0
unsigned int __cdecl FindNearbyTriangles(GeometrySource* geometry, OutputList* output)
{
    unsigned short linkedIndexVal;
    float dot;
    float distanceSquared4;
    Triangle* triangle16;
    unsigned short triangleCountTmp;
    unsigned short triangleIndexB;
    unsigned int nodeIndex7;
    unsigned short edgeType4;
    bool specialEdge5;
    bool boundary8;
    unsigned int insertAt13;
    unsigned int foundCount8 = 0;
    reinterpret_cast<::FUN_006daeb0_Class *>((output))->FUN_006daeb0(reinterpret_cast<::FUN_009acce0_shell *>((geometry))->GetFieldC8());
    SearchCollection candidatesVal(32, 0, 0);
    Vec3 sourcePoint33 = *((::Vec3 *)(reinterpret_cast<::FUN_009d9f40_Class *>((geometry))->FUN_009d9f40()));
    Vec3 alternativePoint20 = (*(::Vec3 *)&(reinterpret_cast<::TaskQueueInterface *>((((::SpatialNode *)(::GetOffsetC((std::intptr_t)(geometry))))))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
    bool useSourcePoint23 = true;
    if (reinterpret_cast<::NiPoint3 *>(&(sourcePoint33))->FUN_004390c0((*(const ::NiPoint3 *)(&(*reinterpret_cast<const ::Vec3 *>((void *)&::NiPoint3::ZERO))))))
    {
        sourcePoint33 = alternativePoint20;
        useSourcePoint23 = false;
    }
    Vec3 centerB;
    reinterpret_cast<::FUN_006d6d60_shell *>((geometry))->FUN_006d6d60((*(::NiPoint3 *)(&centerB)));
    Vec2 center2D4(centerB.x, centerB.y);
    Vec2 sourceDelta_2(sourcePoint33.x - center2D4.x, sourcePoint33.y - center2D4.y);
    unsigned short maxFirstEdge9 = ((unsigned short)(::FUN_006ad3b0((float)reinterpret_cast<::FUN_006d6d90_shell *>((geometry))->FUN_006d6d90(), 0, 1)));
    unsigned short maxSecondEdgeVal = ((unsigned short)(::FUN_006ad3b0((float)reinterpret_cast<::PathingRequest *>((geometry))->GetActorRadius(), 0, 1)));
    float maxDistanceSquared23 = float(reinterpret_cast<::FUN_0099e040_shell *>((geometry))->FUN_0099e040() * reinterpret_cast<::FUN_0099e040_shell *>((geometry))->FUN_0099e040());
    MeshCollection meshesVal(8, 0, 0);
    FUN_006d8a20((Vec3*)((::SpatialNode *)(::GetOffsetC((std::intptr_t)(geometry)))), (float)reinterpret_cast<::FUN_0099e040_shell *>((geometry))->FUN_0099e040(), (SearchOutput*)&meshesVal);
    Vec3 triangleCenter, projected6, endPoint7, transformed11, boundaryPoint6, movement_, finalPosition4;
    Vec2 final2D21, start2D2, end2D17;
    CandidateSource kNodes;
    const bool kInvertEdges = ((bool)(reinterpret_cast<::FUN_006d6db0_shell *>((geometry))->GetByteAtOffsetCC()));
    const bool allowNearEdges22 = ((bool)(reinterpret_cast<::FUN_006d6e30_shell *>((geometry))->GetByteAtOffsetD1()));
    for (nodeIndex7 = 0; nodeIndex7 < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshesVal))->GetName())); ++nodeIndex7)
    {
        reinterpret_cast<::NavMeshPtr *>(&(kNodes))->operator=((*(const ::NavMeshPtr *)(meshesVal.FUN_00877a30(nodeIndex7))));
        triangleCountTmp = (unsigned short)((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((::NodeCollection *)(::FUN_00461110((std::intptr_t)(((::ParentNode *)(::FUN_00559450((int *)&(kNodes))))))))))->GetName()));
        for (triangleIndexB = 0; triangleIndexB < triangleCountTmp; ++triangleIndexB)
        {
            linkedIndexVal = *((unsigned short *)&(reinterpret_cast<::FUN_0069dec0_class *>((((::NodeCollection *)(::FUN_00461110((std::intptr_t)(((::ParentNode *)(::FUN_00559450((int *)&(kNodes))))))))))->FUN_0069dec0(triangleIndexB)));
            triangle16 = ((::Triangle *)(reinterpret_cast<::NavMesh *>((((::ParentNode *)(::FUN_00559450((int *)&(kNodes))))))->GetTriangle(linkedIndexVal)));
            if (!reinterpret_cast<::B690770Object *>((triangle16))->HasFlags())
                continue;
            triangleCenter = ((::ParentNode *)(::FUN_00559450((int *)&(kNodes))))->FUN_00558220(linkedIndexVal);
            projected6 = sourcePoint33 - triangleCenter;
            distanceSquared4 = reinterpret_cast<::TESCombatStyle *>((void *)&(projected6))->UpdateCombatStyle();
            if (useSourcePoint23)
            {
                Vec3 alternativeDelta = alternativePoint20 - triangleCenter;
                if (reinterpret_cast<::TESCombatStyle *>((void *)&(alternativeDelta))->UpdateCombatStyle() > maxDistanceSquared23)
                    continue;
            }
            else
            {
                if (distanceSquared4 > maxDistanceSquared23)
                    continue;
            }
            Vec3 goal = *((::Vec3 *)(reinterpret_cast<::TESAmmoInitCalls *>((geometry))->FUN_00923000()));
            if (((bool)(reinterpret_cast<::FUN_00557d30_class *>((geometry))->FUN_00557d30())))
            {
                {
                    Vec3 delta = centerB - triangleCenter;
                    distanceSquared4 = reinterpret_cast<::TESCombatStyle *>((void *)&(delta))->UpdateCombatStyle();
                    if (reinterpret_cast<::NiPlane *>(&(goal))->operator==((*(const ::NiPlane *)(&(*reinterpret_cast<const ::Vec3 *>((void *)&::NiPoint3::ZERO))))))
                    {
                        float distanceToGoal = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(delta))->DotProduct((void *)(&goal));
                        distanceSquared4 += (distanceToGoal * distanceToGoal / distanceSquared4) * 2;
                    }
                }
            }
            else if (reinterpret_cast<::NiPlane *>(&(goal))->operator==((*(const ::NiPlane *)(&(*reinterpret_cast<const ::Vec3 *>((void *)&::NiPoint3::ZERO))))))
            {
                float distanceToGoal = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(projected6))->DotProduct((void *)(&goal));
                distanceSquared4 += (distanceToGoal * distanceToGoal / distanceSquared4) * 2;
            }
            if (FUN_00408840(projected6.z) > ((double)(reinterpret_cast<::FUN_00644a50_shell *>((geometry))->FUN_00644a50())))
                continue;
            dot =
                (triangleCenter.x - center2D4.x) * sourceDelta_2.x + (triangleCenter.y - center2D4.y) * sourceDelta_2.y;
            if (((bool)(reinterpret_cast<::FUN_006d6df0_shell *>((geometry))->FUN_006d6df0())))
                dot = -dot;
            if (((bool)(reinterpret_cast<::FUN_006d6dd0_shell *>((geometry))->GetByteAtOffsetCD())) || dot > ::_DAT_01012060)
            {
                endPoint7 = ((::ParentNode *)(::FUN_00559450((int *)&(kNodes))))->FUN_006971e0(linkedIndexVal);
                for (unsigned short side = 0; side < 2; ++side)
                {

                    reinterpret_cast<::FUN_00691040_shell *>((triangle16))->GetPackedFlags(side, &edgeType4, &specialEdge5, &boundary8);
                    if (edgeType4 < 4u)
                    {
                        switch (edgeType4)
                        {
                        case 2:
                            if (allowNearEdges22)
                                continue;
                            break;
                        default:
                            continue;
                        }
                    }
                    else
                    {
                        unsigned short minimum = kInvertEdges ? maxFirstEdge9 : maxSecondEdgeVal;
                        if (edgeType4 < minimum)
                            continue;
                    }
                    if (!specialEdge5 && !boundary8 && edgeType4 > maxFirstEdge9 && !allowNearEdges22)
                        continue;
                    Vec3* endpoints[2];
                    ((::ParentNode *)(::FUN_00559450((int *)&(kNodes))))->FUN_0068f040(endpoints, linkedIndexVal, side);
                    transformed11 = *endpoints[1] - *endpoints[0];
                    boundaryPoint6 = *endpoints[0] + transformed11 * ::fnv_00c88020::DAT_01016248;
                    movement_ = transformed11.Cross(endPoint7);
                    movement_.z = 0;
                    reinterpret_cast<::FUN_004a0c10_s *>(&(movement_))->FUN_004a0c10();
                    finalPosition4 = boundaryPoint6 - movement_ * (float)::GetFloatAtOffset68((const char *)(geometry));
                    final2D21.x = finalPosition4.x;
                    final2D21.y = finalPosition4.y;
                    start2D2.x = endpoints[0]->x;
                    start2D2.y = endpoints[0]->y;
                    end2D17.x = endpoints[1]->x;
                    end2D17.y = endpoints[1]->y;
                    if (::FUN_006ba010((const ::NiPoint3 *)(::Vec2 *)(&final2D21), (const ::NiPoint3 *)(::Vec2 *)(&center2D4), (const ::NiPoint3 *)(::Vec2 *)(&start2D2), (const ::NiPoint3 *)(::Vec2 *)(&end2D17)))
                    {
                        ResultPath result(&finalPosition4, ((void *)(reinterpret_cast<::FUN_0068efb0_shell *>((((::ParentNode *)(::FUN_00559450((int *)&(kNodes))))))->FUN_0068efb0())), linkedIndexVal);
                        reinterpret_cast<::Dummy *>(&(result))->SetVectors((const ::Vec12 *)(endpoints[1]), (const ::Vec12 *)(endpoints[0]), (const ::Vec12 *)(const ::Vec3 *)(&movement_));
                        reinterpret_cast<::FUN_006e4500_class *>(&(result))->FUN_006e4500(edgeType4, maxSecondEdgeVal, maxFirstEdge9, specialEdge5, boundary8,
                                            (unsigned char)side);
                        insertAt13 = 0;
                        for (; insertAt13 < foundCount8; ++insertAt13)
                        {
                            if (((bool)(reinterpret_cast<::FUN_006d6e10_shell *>((geometry))->GetByteAtOffsetCF()))
                                    ? distanceSquared4 > *(float*)candidatesVal.FUN_00877a30(insertAt13)
                                    : distanceSquared4 < *(float*)candidatesVal.FUN_00877a30(insertAt13))
                                break;
                        }
                        reinterpret_cast<::FloatArray6db5 *>(&(candidatesVal))->FUN_006db540(insertAt13, (*(const float *)(&distanceSquared4)));
                        reinterpret_cast<::Array6daf *>((output))->FUN_006daf20(insertAt13, (*(const ::Elem6daf *)(&result)));
                        ++foundCount8;
                        if (foundCount8 >= reinterpret_cast<::FUN_009acce0_shell *>((geometry))->GetFieldC8())
                            return foundCount8;
                    }
                }
            }
        }
    }
    return foundCount8;
}

struct NiPoint3Ex : NiPoint3
{
    NiPoint3Ex(float x, float y, float z);
};
struct LocationQuery
{
};
struct MeshQuery
{
};
// @fnv 0x006d7110
bool __cdecl FUN_006d7110(TESWorldSpace* world, TESObjectCELL* cell, const NiPoint3& origin, float radius,
                          NiPoint3& result)
{
    PathingLocation location(origin, cell, world);
    bool point = true;
    if (!reinterpret_cast<::PathingLocationProxy *>((((LocationQuery*)&location)))->FindContainingTriangle(0))
        point = false;
    NavMeshPtr c;
    if (!reinterpret_cast<::PathingLocation *>((((LocationQuery*)&location)))->ResolveNavMesh(c))
        point = false;
    if (!point)
    {
        float value = RandomFloat(-radius, radius);
        float y = FUN_004019b0(radius * radius - value * value);
        y = RandomFloat(-y, y);
        result = origin + NiPoint3Ex(value, y, 0.0f);
        return true;
    }
    if (!reinterpret_cast<::NavFinder697 *>((((MeshQuery*)((::NavMesh *)(::FUN_00559450((int *)&(c)))))))->FUN_00697c10(origin, radius, (::NiPoint3 *)&(result)) ||
        !reinterpret_cast<::FUN_00697670_StandIn *>((((MeshQuery*)((::NavMesh *)(::FUN_00559450((int *)&(c)))))))->IsLocationOnNavMesh(result, 0))
    {
        unsigned short triangle = 0xffff;
        bool flag = false;
        if (!reinterpret_cast<::fnv_00696cf0::Host696 *>((((MeshQuery*)((::NavMesh *)(::FUN_00559450((int *)&(c)))))))->FUN_00696cf0(origin, (unsigned short *)&(triangle), (bool *)&(flag)))
            return false;
        result = ((::NavMesh *)(::FUN_00559450((int *)&(c))))->GetNavMeshData(triangle);
    }
    return true;
}

namespace fnv_006d7a40 {
struct Point
{
    float x, y, z;
};
struct Mesh;
struct MeshRef
{
    Mesh* pointer;
    MeshRef();
    ~MeshRef();
    operator Mesh*() const;
};
struct Triangle
{
    Mesh* mesh;
    unsigned short index;
    Point center;
};
struct Location
{
    unsigned int vtable;
    Point position;
    unsigned int mesh, meshes, cell, world, key;
    unsigned short triangle;
    unsigned char flags, padding;
    Location(const Location&);
    ~Location();
};
struct Search
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int unk02b4;
    unsigned int unk02b8;
    unsigned int unk02bc;
    unsigned int unk02c0;
    unsigned int unk02c4;
    unsigned int unk02c8;
    unsigned int unk02cc;
    unsigned int unk02d0;
    unsigned int unk02d4;
    unsigned int unk02d8;
    unsigned int unk02dc;
    unsigned int unk02e0;
    unsigned int unk02e4;
    unsigned int unk02e8;
    unsigned int unk02ec;
    unsigned int unk02f0;
    unsigned int unk02f4;
    unsigned int unk02f8;
    unsigned int unk02fc;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030c;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031c;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032c;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033c;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034c;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035c;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036c;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037c;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038c;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039c;
    unsigned int unk03a0;
    unsigned int unk03a4;
    unsigned int unk03a8;
    unsigned int unk03ac;
    unsigned int unk03b0;
    unsigned int unk03b4;
    unsigned int unk03b8;
    unsigned int unk03bc;
    unsigned int unk03c0;
    unsigned int unk03c4;
    unsigned int unk03c8;
    unsigned int unk03cc;
    unsigned int unk03d0;
    unsigned int unk03d4;
    unsigned int unk03d8;
    unsigned int unk03dc;
    unsigned int unk03e0;
    unsigned int unk03e4;
    unsigned int unk03e8;
    unsigned int unk03ec;
    unsigned int unk03f0;
    unsigned int unk03f4;
    unsigned int unk03f8;
    unsigned int unk03fc;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040c;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041c;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042c;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043c;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044c;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045c;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046c;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047c;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048c;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049c;
    unsigned int unk04a0;
    unsigned int unk04a4;
    unsigned int unk04a8;
    unsigned int unk04ac;
    unsigned int unk04b0;
    unsigned int unk04b4;
    unsigned int unk04b8;
    unsigned int unk04bc;
    unsigned int unk04c0;
    unsigned int unk04c4;
    unsigned int unk04c8;
    unsigned int unk04cc;
    unsigned int unk04d0;
    unsigned int unk04d4;
    unsigned int unk04d8;
    unsigned int unk04dc;
    unsigned int unk04e0;
    unsigned int unk04e4;
    unsigned int unk04e8;
    unsigned int unk04ec;
    unsigned int unk04f0;
    unsigned int unk04f4;
    unsigned int unk04f8;
    unsigned int unk04fc;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050c;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051c;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052c;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053c;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054c;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055c;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056c;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057c;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058c;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059c;
    unsigned int unk05a0;
    unsigned int unk05a4;
    unsigned int unk05a8;
    unsigned int unk05ac;
    unsigned int unk05b0;
    unsigned int unk05b4;
    unsigned int unk05b8;
    unsigned int unk05bc;
    unsigned int unk05c0;
    unsigned int unk05c4;
    unsigned int unk05c8;
    unsigned int unk05cc;
    unsigned int unk05d0;
    unsigned int unk05d4;
    unsigned int unk05d8;
    unsigned int unk05dc;
    unsigned int unk05e0;
    unsigned int unk05e4;
    unsigned int unk05e8;
    unsigned int unk05ec;
    unsigned int unk05f0;
    unsigned int unk05f4;
    unsigned int unk05f8;
    unsigned int unk05fc;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060c;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061c;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062c;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063c;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064c;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065c;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066c;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067c;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068c;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069c;
    unsigned int unk06a0;
    unsigned int unk06a4;
    unsigned int unk06a8;
    unsigned int unk06ac;
    unsigned int unk06b0;
    unsigned int unk06b4;
    unsigned int unk06b8;
    unsigned int unk06bc;
    unsigned int unk06c0;
    unsigned int unk06c4;
    unsigned int unk06c8;
    unsigned int unk06cc;
    unsigned int unk06d0;
    unsigned int unk06d4;
    unsigned int unk06d8;
    unsigned int unk06dc;
    unsigned int unk06e0;
    unsigned int unk06e4;
    unsigned int unk06e8;
    unsigned int unk06ec;
    unsigned int unk06f0;
    unsigned int unk06f4;
    unsigned int unk06f8;
    unsigned int unk06fc;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070c;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071c;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072c;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073c;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074c;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075c;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076c;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077c;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078c;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079c;
    unsigned int unk07a0;
    unsigned int unk07a4;
    unsigned int unk07a8;
    unsigned int unk07ac;
    unsigned int unk07b0;
    unsigned int unk07b4;
    unsigned int unk07b8;
    unsigned int unk07bc;
    unsigned int unk07c0;
    unsigned int unk07c4;
    unsigned int unk07c8;
    unsigned int unk07cc;
    unsigned int unk07d0;
    unsigned int unk07d4;
    unsigned int unk07d8;
    unsigned int unk07dc;
    unsigned int unk07e0;
    unsigned int unk07e4;
    unsigned int unk07e8;
    unsigned int unk07ec;
    unsigned int unk07f0;
    unsigned int unk07f4;
    unsigned int unk07f8;
    unsigned int unk07fc;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080c;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081c;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082c;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083c;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084c;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085c;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086c;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087c;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088c;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089c;
    unsigned int unk08a0;
    unsigned int unk08a4;
    unsigned int unk08a8;
    unsigned int unk08ac;
    unsigned int unk08b0;
    unsigned int unk08b4;
    unsigned int unk08b8;
    unsigned int unk08bc;
    unsigned int unk08c0;
    unsigned int unk08c4;
    unsigned int unk08c8;
    unsigned int unk08cc;
    unsigned int unk08d0;
    unsigned int unk08d4;
    unsigned int unk08d8;
    unsigned int unk08dc;
    unsigned int unk08e0;
    unsigned int unk08e4;
    unsigned int unk08e8;
    unsigned int unk08ec;
    unsigned int unk08f0;
    unsigned int unk08f4;
    unsigned int unk08f8;
    unsigned int unk08fc;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090c;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091c;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092c;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093c;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094c;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095c;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096c;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097c;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098c;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099c;
    unsigned int unk09a0;
    unsigned int unk09a4;
    unsigned int unk09a8;
    unsigned int unk09ac;
    unsigned int unk09b0;
    unsigned int unk09b4;
    unsigned int unk09b8;
    unsigned int unk09bc;
    unsigned int unk09c0;
    unsigned int unk09c4;
    unsigned int unk09c8;
    unsigned int unk09cc;
    unsigned int unk09d0;
    unsigned int unk09d4;
    unsigned int unk09d8;
    unsigned int unk09dc;
    unsigned int unk09e0;
    unsigned int unk09e4;
    unsigned int unk09e8;
    unsigned int unk09ec;
    unsigned int unk09f0;
    unsigned int unk09f4;
    unsigned int unk09f8;
    unsigned int unk09fc;
    unsigned int unk0a00;
    unsigned int unk0a04;
    unsigned int unk0a08;
    unsigned int unk0a0c;
    unsigned int unk0a10;
    unsigned int unk0a14;
    unsigned int unk0a18;
    unsigned int unk0a1c;
    unsigned int unk0a20;
    unsigned int unk0a24;
    unsigned int unk0a28;
    unsigned int unk0a2c;
    unsigned int unk0a30;
    unsigned int unk0a34;
    unsigned int unk0a38;
    unsigned int unk0a3c;
    unsigned int unk0a40;
    unsigned int unk0a44;
    unsigned int unk0a48;
    unsigned int unk0a4c;
    unsigned int unk0a50;
    unsigned int unk0a54;
    unsigned int unk0a58;
    unsigned int unk0a5c;
    unsigned int unk0a60;
    unsigned int unk0a64;
    unsigned int unk0a68;
    unsigned int unk0a6c;
    unsigned int unk0a70;
    unsigned int unk0a74;
    unsigned int unk0a78;
    unsigned int unk0a7c;
    unsigned int unk0a80;
    unsigned int unk0a84;
    unsigned int unk0a88;
    unsigned int unk0a8c;
    unsigned int unk0a90;
    unsigned int unk0a94;
    unsigned int unk0a98;
    unsigned int unk0a9c;
    unsigned int unk0aa0;
    unsigned int unk0aa4;
    unsigned int unk0aa8;
    unsigned int unk0aac;
    unsigned int unk0ab0;
    unsigned int unk0ab4;
    unsigned int unk0ab8;
    unsigned int unk0abc;
    unsigned int unk0ac0;
    unsigned int unk0ac4;
    unsigned int unk0ac8;
    unsigned int unk0acc;
    unsigned int unk0ad0;
    unsigned int unk0ad4;
    unsigned int unk0ad8;
    unsigned int unk0adc;
    unsigned int unk0ae0;
    unsigned int unk0ae4;
    unsigned int unk0ae8;
    unsigned int unk0aec;
    unsigned int unk0af0;
    unsigned int unk0af4;
    unsigned int unk0af8;
    unsigned int unk0afc;
    unsigned int unk0b00;
    unsigned int unk0b04;
    unsigned int unk0b08;
    unsigned int unk0b0c;
    unsigned int unk0b10;
    unsigned int unk0b14;
    unsigned int unk0b18;
    unsigned int unk0b1c;
    unsigned int unk0b20;
    unsigned int unk0b24;
    unsigned int unk0b28;
    unsigned int unk0b2c;
    unsigned int unk0b30;
    unsigned int unk0b34;
    unsigned int unk0b38;
    unsigned int unk0b3c;
    unsigned int unk0b40;
    unsigned int unk0b44;
    unsigned int unk0b48;
    unsigned int unk0b4c;
    unsigned int unk0b50;
    unsigned int unk0b54;
    unsigned int unk0b58;
    unsigned int unk0b5c;
    unsigned int unk0b60;
    unsigned int unk0b64;
    unsigned int unk0b68;
    unsigned int unk0b6c;
    unsigned int unk0b70;
    unsigned int unk0b74;
    unsigned int unk0b78;
    unsigned int unk0b7c;
    unsigned int unk0b80;
    unsigned int unk0b84;
    unsigned int unk0b88;
    unsigned int unk0b8c;
    unsigned int unk0b90;
    unsigned int unk0b94;
    unsigned int unk0b98;
    unsigned int unk0b9c;
    unsigned int unk0ba0;
    unsigned int unk0ba4;
    unsigned int unk0ba8;
    unsigned int unk0bac;
    unsigned int unk0bb0;
    unsigned int unk0bb4;
    unsigned int unk0bb8;
    unsigned int unk0bbc;
    unsigned int unk0bc0;
    unsigned int unk0bc4;
    unsigned int unk0bc8;
    unsigned int unk0bcc;
    unsigned int unk0bd0;
    unsigned int unk0bd4;
    unsigned int unk0bd8;
    unsigned int unk0bdc;
    unsigned int unk0be0;
    unsigned int unk0be4;
    unsigned int unk0be8;
    unsigned int unk0bec;
    unsigned int unk0bf0;
    unsigned int unk0bf4;
    unsigned int unk0bf8;
    unsigned int unk0bfc;
    unsigned int unk0c00;
    unsigned int unk0c04;
    unsigned int unk0c08;
    unsigned int unk0c0c;
    unsigned int unk0c10;
    unsigned int unk0c14;
    unsigned int unk0c18;
    unsigned int unk0c1c;
    unsigned int unk0c20;
    unsigned int unk0c24;
    unsigned int unk0c28;
    unsigned int unk0c2c;
    unsigned int unk0c30;
    unsigned int unk0c34;
    unsigned int unk0c38;
    unsigned int unk0c3c;
    unsigned int unk0c40;
    unsigned int unk0c44;
    unsigned int unk0c48;
    unsigned int unk0c4c;
    unsigned int unk0c50;
    unsigned int unk0c54;
    unsigned int unk0c58;
    unsigned int unk0c5c;
    unsigned int unk0c60;
    unsigned int unk0c64;
    unsigned int unk0c68;
    unsigned int unk0c6c;
    unsigned int unk0c70;
    unsigned int unk0c74;
    unsigned int unk0c78;
    unsigned int unk0c7c;
    unsigned int unk0c80;
    unsigned int unk0c84;
    unsigned int unk0c88;
    unsigned int unk0c8c;
    unsigned int unk0c90;
    unsigned int unk0c94;
    unsigned int unk0c98;
    unsigned int unk0c9c;
    unsigned int unk0ca0;
    unsigned int unk0ca4;
    unsigned int unk0ca8;
    unsigned int unk0cac;
    unsigned int unk0cb0;
    unsigned int unk0cb4;
    unsigned int unk0cb8;
    unsigned int unk0cbc;
    unsigned int unk0cc0;
    unsigned int unk0cc4;
    unsigned int unk0cc8;
    unsigned int unk0ccc;
    unsigned int unk0cd0;
    unsigned int unk0cd4;
    unsigned int unk0cd8;
    unsigned int unk0cdc;
    unsigned int unk0ce0;
    unsigned int unk0ce4;
    unsigned int unk0ce8;
    unsigned int unk0cec;
    unsigned int unk0cf0;
    unsigned int unk0cf4;
    unsigned int unk0cf8;
    unsigned int unk0cfc;
    unsigned int unk0d00;
    unsigned int unk0d04;
    unsigned int unk0d08;
    unsigned int unk0d0c;
    unsigned int unk0d10;
    unsigned int unk0d14;
    unsigned int unk0d18;
    unsigned int unk0d1c;
    unsigned int unk0d20;
    unsigned int unk0d24;
    unsigned int unk0d28;
    unsigned int unk0d2c;
    unsigned int unk0d30;
    unsigned int unk0d34;
    unsigned int unk0d38;
    unsigned int unk0d3c;
    unsigned int unk0d40;
    unsigned int unk0d44;
    unsigned int unk0d48;
    unsigned int unk0d4c;
    unsigned int unk0d50;
    unsigned int unk0d54;
    unsigned int unk0d58;
    unsigned int unk0d5c;
    unsigned int unk0d60;
    unsigned int unk0d64;
    unsigned int unk0d68;
    unsigned int unk0d6c;
    unsigned int unk0d70;
    unsigned int unk0d74;
    unsigned int unk0d78;
    unsigned int unk0d7c;
    unsigned int unk0d80;
    unsigned int unk0d84;
    unsigned int unk0d88;
    unsigned int unk0d8c;
    unsigned int unk0d90;
    unsigned int unk0d94;
    unsigned int unk0d98;
    unsigned int unk0d9c;
    unsigned int unk0da0;
    unsigned int unk0da4;
    unsigned int unk0da8;
    unsigned int unk0dac;
    unsigned int unk0db0;
    unsigned int unk0db4;
    unsigned int unk0db8;
    unsigned int unk0dbc;
    unsigned int unk0dc0;
    unsigned int unk0dc4;
    unsigned int unk0dc8;
    unsigned int unk0dcc;
    unsigned int unk0dd0;
    unsigned int unk0dd4;
    unsigned int unk0dd8;
    unsigned int unk0ddc;
    unsigned int unk0de0;
    unsigned int unk0de4;
    unsigned int unk0de8;
    unsigned int unk0dec;
    unsigned int unk0df0;
    unsigned int unk0df4;
    unsigned int unk0df8;
    unsigned int unk0dfc;
    unsigned int unk0e00;
    unsigned int unk0e04;
    unsigned int unk0e08;
    unsigned int unk0e0c;
    unsigned int unk0e10;
    unsigned int unk0e14;
    unsigned int unk0e18;
    unsigned int unk0e1c;
    unsigned int unk0e20;
    unsigned int unk0e24;
    unsigned int unk0e28;
    unsigned int unk0e2c;
    unsigned int unk0e30;
    unsigned int unk0e34;
    unsigned int unk0e38;
    unsigned int unk0e3c;
    unsigned int unk0e40;
    unsigned int unk0e44;
    unsigned int unk0e48;
    unsigned int unk0e4c;
    unsigned int unk0e50;
    unsigned int unk0e54;
    unsigned int unk0e58;
    unsigned int unk0e5c;
    unsigned int unk0e60;
    unsigned int unk0e64;
    unsigned int unk0e68;
    unsigned int unk0e6c;
    unsigned int unk0e70;
    unsigned int unk0e74;
    unsigned int unk0e78;
    unsigned int unk0e7c;
    unsigned int unk0e80;
    unsigned int unk0e84;
    unsigned int unk0e88;
    unsigned int unk0e8c;
    unsigned int unk0e90;
    unsigned int unk0e94;
    unsigned int unk0e98;
    unsigned int unk0e9c;
    unsigned int unk0ea0;
    unsigned int unk0ea4;
    unsigned int unk0ea8;
    unsigned int unk0eac;
    unsigned int unk0eb0;
    unsigned int unk0eb4;
    unsigned int unk0eb8;
    unsigned int unk0ebc;
    unsigned int unk0ec0;
    unsigned int unk0ec4;
    unsigned int unk0ec8;
    unsigned int unk0ecc;
    unsigned int unk0ed0;
    unsigned int unk0ed4;
    unsigned int unk0ed8;
    unsigned int unk0edc;
    unsigned int unk0ee0;
    unsigned int unk0ee4;
    unsigned int unk0ee8;
    unsigned int unk0eec;
    unsigned int unk0ef0;
    unsigned int unk0ef4;
    unsigned int unk0ef8;
    unsigned int unk0efc;
    unsigned int unk0f00;
    unsigned int unk0f04;
    unsigned int unk0f08;
    unsigned int unk0f0c;
    unsigned int unk0f10;
    unsigned int unk0f14;
    unsigned int unk0f18;
    unsigned int unk0f1c;
    unsigned int unk0f20;
    unsigned int unk0f24;
    unsigned int unk0f28;
    unsigned int unk0f2c;
    unsigned int unk0f30;
    unsigned int unk0f34;
    unsigned int unk0f38;
    unsigned int unk0f3c;
    unsigned int unk0f40;
    unsigned int unk0f44;
    unsigned int unk0f48;
    unsigned int unk0f4c;
    unsigned int unk0f50;
    unsigned int unk0f54;
    unsigned int unk0f58;
    unsigned int unk0f5c;
    unsigned int unk0f60;
    unsigned int unk0f64;
    unsigned int unk0f68;
    unsigned int unk0f6c;
    unsigned int unk0f70;
    unsigned int unk0f74;
    unsigned int unk0f78;
    unsigned int unk0f7c;
    unsigned int unk0f80;
    unsigned int unk0f84;
    unsigned int unk0f88;
    unsigned int unk0f8c;
    unsigned int unk0f90;
    unsigned int unk0f94;
    unsigned int unk0f98;
    unsigned int unk0f9c;
    unsigned int unk0fa0;
    unsigned int unk0fa4;
    unsigned int unk0fa8;
    unsigned int unk0fac;
    unsigned int unk0fb0;
    unsigned int unk0fb4;
    unsigned int unk0fb8;
    unsigned int unk0fbc;
    unsigned int unk0fc0;
    unsigned int unk0fc4;
    unsigned int unk0fc8;
    unsigned int unk0fcc;
    unsigned int unk0fd0;
    unsigned int unk0fd4;
    unsigned int unk0fd8;
    unsigned int unk0fdc;
    unsigned int unk0fe0;
    unsigned int unk0fe4;
    unsigned int unk0fe8;
    unsigned int unk0fec;
    unsigned int unk0ff0;
    unsigned int unk0ff4;
    unsigned int unk0ff8;
    unsigned int unk0ffc;
    unsigned int unk1000;
    unsigned int unk1004;
    unsigned int unk1008;
    unsigned int unk100c;
    unsigned int unk1010;
    unsigned int unk1014;
    unsigned int unk1018;
    unsigned int unk101c;
    unsigned int unk1020;
    unsigned int unk1024;
    unsigned int unk1028;
    unsigned int unk102c;
    unsigned int unk1030;
    unsigned int unk1034;
    unsigned int unk1038;
    unsigned int unk103c;
    unsigned int unk1040;
    unsigned int unk1044;
    unsigned int unk1048;
    unsigned int unk104c;
    unsigned int unk1050;
    unsigned int unk1054;
    unsigned int unk1058;
    unsigned int unk105c;
    unsigned int unk1060;
    unsigned int unk1064;
    unsigned int unk1068;
    unsigned int unk106c;
    unsigned int unk1070;
    unsigned int unk1074;
    unsigned int unk1078;
    unsigned int unk107c;
    unsigned int unk1080;
    unsigned int unk1084;
    unsigned int unk1088;
    unsigned int unk108c;
    unsigned int unk1090;
    unsigned int unk1094;
    unsigned int unk1098;
    unsigned int unk109c;
    unsigned int unk10a0;
    unsigned int unk10a4;
    unsigned int unk10a8;
    unsigned int unk10ac;
    unsigned int unk10b0;
    unsigned int unk10b4;
    unsigned int unk10b8;
    unsigned int unk10bc;
    unsigned int unk10c0;
    unsigned int unk10c4;
    unsigned int unk10c8;
    unsigned int unk10cc;
    unsigned int unk10d0;
    unsigned int unk10d4;
    unsigned int unk10d8;
    unsigned int unk10dc;
    unsigned int unk10e0;
    unsigned int unk10e4;
    unsigned int unk10e8;
    unsigned int unk10ec;
    unsigned int unk10f0;
    unsigned int unk10f4;
    unsigned int unk10f8;
    unsigned int unk10fc;
    unsigned int unk1100;
    unsigned int unk1104;
    unsigned int unk1108;
    unsigned int unk110c;
    unsigned int unk1110;
    unsigned int unk1114;
    unsigned int unk1118;
    unsigned int unk111c;
    unsigned int unk1120;
    unsigned int unk1124;
    unsigned int unk1128;
    unsigned int unk112c;
    unsigned int unk1130;
    unsigned int unk1134;
    unsigned int unk1138;
    unsigned int unk113c;
    unsigned int unk1140;
    unsigned int unk1144;
    unsigned int unk1148;
    unsigned int unk114c;
    unsigned int unk1150;
    unsigned int unk1154;
    unsigned int unk1158;
    unsigned int unk115c;
    unsigned int unk1160;
    unsigned int unk1164;
    unsigned int unk1168;
    unsigned int unk116c;
    unsigned int unk1170;
    unsigned int unk1174;
    unsigned int unk1178;
    unsigned int unk117c;
    unsigned int unk1180;
    unsigned int unk1184;
    unsigned int unk1188;
    unsigned int unk118c;
    unsigned int unk1190;
    unsigned int unk1194;
    unsigned int unk1198;
    unsigned int unk119c;
    unsigned int unk11a0;
    unsigned int unk11a4;
    unsigned int unk11a8;
    unsigned int unk11ac;
    unsigned int unk11b0;
    unsigned int unk11b4;
    unsigned int unk11b8;
    unsigned int unk11bc;
    unsigned int unk11c0;
    unsigned int unk11c4;
    unsigned int unk11c8;
    unsigned int unk11cc;
    unsigned int unk11d0;
    unsigned int unk11d4;
    unsigned int unk11d8;
    unsigned int unk11dc;
    unsigned int unk11e0;
    unsigned int unk11e4;
    unsigned int unk11e8;
    unsigned int unk11ec;
    unsigned int unk11f0;
    unsigned int unk11f4;
    unsigned int unk11f8;
    unsigned int unk11fc;
    unsigned int unk1200;
    unsigned int unk1204;
    unsigned int unk1208;
    unsigned int unk120c;
    unsigned int unk1210;
    unsigned int unk1214;
    unsigned int unk1218;
    unsigned int unk121c;
    unsigned int unk1220;
    unsigned int unk1224;
    unsigned int unk1228;
    unsigned int unk122c;
    unsigned int unk1230;
    unsigned int unk1234;
    unsigned int unk1238;
    unsigned int unk123c;
    unsigned int unk1240;
    unsigned int unk1244;
    unsigned int unk1248;
    unsigned int unk124c;
    unsigned int unk1250;
    unsigned int unk1254;
    unsigned int unk1258;
    unsigned int unk125c;
    unsigned int unk1260;
    unsigned int unk1264;
    unsigned int unk1268;
    unsigned int unk126c;
    unsigned int unk1270;
    unsigned int unk1274;
    unsigned int unk1278;
    unsigned int unk127c;
    unsigned int unk1280;
    unsigned int unk1284;
    unsigned int unk1288;
    unsigned int unk128c;
    unsigned int unk1290;
    unsigned int unk1294;
    unsigned int unk1298;
    unsigned int unk129c;
    unsigned int unk12a0;
    unsigned int unk12a4;
    unsigned int unk12a8;
    unsigned int unk12ac;
    unsigned int unk12b0;
    unsigned int unk12b4;
    unsigned int unk12b8;
    unsigned int unk12bc;
    unsigned int unk12c0;
    unsigned int unk12c4;
    unsigned int unk12c8;
    unsigned int unk12cc;
    unsigned int unk12d0;
    unsigned int unk12d4;
    unsigned int unk12d8;
    unsigned int unk12dc;
    unsigned int unk12e0;
    unsigned int unk12e4;
    unsigned int unk12e8;
    unsigned int unk12ec;
    unsigned int unk12f0;
    unsigned int unk12f4;
    unsigned int unk12f8;
    unsigned int unk12fc;
    unsigned int unk1300;
    unsigned int unk1304;
    unsigned int unk1308;
    unsigned int unk130c;
    unsigned int unk1310;
    unsigned int unk1314;
    unsigned int unk1318;
    unsigned int unk131c;
    unsigned int unk1320;
    unsigned int unk1324;
    unsigned int unk1328;
    unsigned int unk132c;
    unsigned int unk1330;
    unsigned int unk1334;
    unsigned int unk1338;
    unsigned int unk133c;
    unsigned int unk1340;
    unsigned int unk1344;
    unsigned int unk1348;
    unsigned int unk134c;
    unsigned int unk1350;
    unsigned int unk1354;
    unsigned int unk1358;
    unsigned int unk135c;
    unsigned int unk1360;
    unsigned int unk1364;
    unsigned int unk1368;
    unsigned int unk136c;
    unsigned int unk1370;
    unsigned int unk1374;
    unsigned int unk1378;
    unsigned int unk137c;
    unsigned int unk1380;
    unsigned int unk1384;
    unsigned int unk1388;
    unsigned int unk138c;
    unsigned int unk1390;
    unsigned int unk1394;
    unsigned int unk1398;
    unsigned int unk139c;
    unsigned int unk13a0;
    unsigned int unk13a4;
    unsigned int unk13a8;
    unsigned int unk13ac;
    unsigned int unk13b0;
    unsigned int unk13b4;
    unsigned int unk13b8;
    unsigned int unk13bc;
    unsigned int unk13c0;
    unsigned int unk13c4;
    unsigned int unk13c8;
    unsigned int unk13cc;
    unsigned int unk13d0;
    unsigned int unk13d4;
    unsigned int unk13d8;
    unsigned int unk13dc;
    unsigned int unk13e0;
    unsigned int unk13e4;
    unsigned int unk13e8;
    unsigned int unk13ec;
    unsigned int unk13f0;
    unsigned int unk13f4;
    unsigned int unk13f8;
    unsigned int unk13fc;
    unsigned int unk1400;
    unsigned int unk1404;
    unsigned int unk1408;
    unsigned int unk140c;
    unsigned int unk1410;
    unsigned int unk1414;
    unsigned int unk1418;
    unsigned int unk141c;
    unsigned int unk1420;
    unsigned int unk1424;
    unsigned int unk1428;
    unsigned int unk142c;
    unsigned int unk1430;
    unsigned int unk1434;
    unsigned int unk1438;
    unsigned int unk143c;
    unsigned int unk1440;
    unsigned int unk1444;
    unsigned int unk1448;
    unsigned int unk144c;
    unsigned int unk1450;
    unsigned int unk1454;
    unsigned int unk1458;
    unsigned int unk145c;
    unsigned int unk1460;
    unsigned int unk1464;
    unsigned int unk1468;
    unsigned int unk146c;
    unsigned int unk1470;
    unsigned int unk1474;
    unsigned int unk1478;
    unsigned int unk147c;
    unsigned int unk1480;
    unsigned int unk1484;
    unsigned int unk1488;
    unsigned int unk148c;
    unsigned int unk1490;
    unsigned int unk1494;
    unsigned int unk1498;
    unsigned int unk149c;
    unsigned int unk14a0;
    unsigned int unk14a4;
    unsigned int unk14a8;
    unsigned int unk14ac;
    unsigned int unk14b0;
    unsigned int unk14b4;
    unsigned int unk14b8;
    unsigned int unk14bc;
    unsigned int unk14c0;
    unsigned int unk14c4;
    unsigned int unk14c8;
    unsigned int unk14cc;
    unsigned int unk14d0;
    unsigned int unk14d4;
    unsigned int unk14d8;
    unsigned int unk14dc;
    unsigned int unk14e0;
    unsigned int unk14e4;
    unsigned int unk14e8;
    unsigned int unk14ec;
    unsigned int unk14f0;
    unsigned int unk14f4;
    unsigned int unk14f8;
    unsigned int unk14fc;
    unsigned int unk1500;
    unsigned int unk1504;
    unsigned int unk1508;
    unsigned int unk150c;
    unsigned int unk1510;
    unsigned int unk1514;
    unsigned int unk1518;
    unsigned int unk151c;
    unsigned int unk1520;
    unsigned int unk1524;
    unsigned int unk1528;
    unsigned int unk152c;
    unsigned int unk1530;
    unsigned int unk1534;
    unsigned int unk1538;
    unsigned int unk153c;
    unsigned int unk1540;
    unsigned int unk1544;
    unsigned int unk1548;
    unsigned int unk154c;
    unsigned int unk1550;
    unsigned int unk1554;
    unsigned int unk1558;
    unsigned int unk155c;
    unsigned int unk1560;
    unsigned int unk1564;
    unsigned int unk1568;
    unsigned int unk156c;
    unsigned int unk1570;
    unsigned int unk1574;
    unsigned int unk1578;
    unsigned int unk157c;
    unsigned int unk1580;
    unsigned int unk1584;
    unsigned int unk1588;
    unsigned int unk158c;
    unsigned int unk1590;
    unsigned int unk1594;
    unsigned int unk1598;
    unsigned int unk159c;
    unsigned int unk15a0;
    unsigned int unk15a4;
    unsigned int unk15a8;
    unsigned int unk15ac;
    unsigned int unk15b0;
    unsigned int unk15b4;
    unsigned int unk15b8;
    unsigned int unk15bc;
    unsigned int unk15c0;
    unsigned int unk15c4;
    unsigned int unk15c8;
    unsigned int unk15cc;
    unsigned int unk15d0;
    unsigned int unk15d4;
    unsigned int unk15d8;
    unsigned int unk15dc;
    unsigned int unk15e0;
    unsigned int unk15e4;
    unsigned int unk15e8;
    unsigned int unk15ec;
    unsigned int unk15f0;
    unsigned int unk15f4;
    unsigned int unk15f8;
    unsigned int unk15fc;
    unsigned int unk1600;
    unsigned int unk1604;
    unsigned int unk1608;
    unsigned int unk160c;
    unsigned int unk1610;
    unsigned int unk1614;
    unsigned int unk1618;
    unsigned int unk161c;
    unsigned int unk1620;
    unsigned int unk1624;
    unsigned int unk1628;
    unsigned int unk162c;
    unsigned int unk1630;
    unsigned int unk1634;
    unsigned int unk1638;
    unsigned int unk163c;
    unsigned int unk1640;
    unsigned int unk1644;
    unsigned int unk1648;
    unsigned int unk164c;
    unsigned int unk1650;
    unsigned int unk1654;
    unsigned int unk1658;
    unsigned int unk165c;
    unsigned int unk1660;
    unsigned int unk1664;
    unsigned int unk1668;
    unsigned int unk166c;
    unsigned int unk1670;
    unsigned int unk1674;
    unsigned int unk1678;
    unsigned int unk167c;
    unsigned int unk1680;
    unsigned int unk1684;
    unsigned int unk1688;
    unsigned int unk168c;
    unsigned int unk1690;
    unsigned int unk1694;
    unsigned int unk1698;
    unsigned int unk169c;
    unsigned int unk16a0;
    unsigned int unk16a4;
    unsigned int unk16a8;
    unsigned int unk16ac;
    unsigned int unk16b0;
    unsigned int unk16b4;
    unsigned int unk16b8;
    unsigned int unk16bc;
    unsigned int unk16c0;
    unsigned int unk16c4;
    unsigned int unk16c8;
    unsigned int unk16cc;
    unsigned int unk16d0;
    unsigned int unk16d4;
    unsigned int unk16d8;
    unsigned int unk16dc;
    unsigned int unk16e0;
    unsigned int unk16e4;
    unsigned int unk16e8;
    unsigned int unk16ec;
    unsigned int unk16f0;
    unsigned int unk16f4;
    unsigned int unk16f8;
    unsigned int unk16fc;
    unsigned int unk1700;
    unsigned int unk1704;
    unsigned int unk1708;
    unsigned int unk170c;
    unsigned int unk1710;
    unsigned int unk1714;
    unsigned int unk1718;
    unsigned int unk171c;
    unsigned int unk1720;
    unsigned int unk1724;
    unsigned int unk1728;
    unsigned int unk172c;
    unsigned int unk1730;
    unsigned int unk1734;
    unsigned int unk1738;
    unsigned int unk173c;
    unsigned int unk1740;
    unsigned int unk1744;
    unsigned int unk1748;
    unsigned int unk174c;
    unsigned int unk1750;
    unsigned int unk1754;
    unsigned int unk1758;
    unsigned int unk175c;
    unsigned int unk1760;
    unsigned int unk1764;
    unsigned int unk1768;
    unsigned int unk176c;
    unsigned int unk1770;
    unsigned int unk1774;
    unsigned int unk1778;
    unsigned int unk177c;
    unsigned int unk1780;
    unsigned int unk1784;
    unsigned int unk1788;
    unsigned int unk178c;
    unsigned int unk1790;
    unsigned int unk1794;
    unsigned int unk1798;
    unsigned int unk179c;
    unsigned int unk17a0;
    unsigned int unk17a4;
    unsigned int unk17a8;
    unsigned int unk17ac;
    unsigned int unk17b0;
    unsigned int unk17b4;
    unsigned int unk17b8;
    unsigned int unk17bc;
    unsigned int unk17c0;
    unsigned int unk17c4;
    unsigned int unk17c8;
    unsigned int unk17cc;
    unsigned int unk17d0;
    unsigned int unk17d4;
    unsigned int unk17d8;
    unsigned int unk17dc;
    unsigned int unk17e0;
    unsigned int unk17e4;
    unsigned int unk17e8;
    unsigned int unk17ec;
    unsigned int unk17f0;
    unsigned int unk17f4;
    unsigned int unk17f8;
    unsigned int unk17fc;
    unsigned int unk1800;
    unsigned int unk1804;
    unsigned int unk1808;
    unsigned int unk180c;
    unsigned int unk1810;
    unsigned int unk1814;
    unsigned int unk1818;
    unsigned int unk181c;
    unsigned int unk1820;
    unsigned int unk1824;
    unsigned int unk1828;
    unsigned int unk182c;
    unsigned int unk1830;
    unsigned int unk1834;
    unsigned int unk1838;
    unsigned int unk183c;
    unsigned int unk1840;
    unsigned int unk1844;
    unsigned int unk1848;
    unsigned int unk184c;
    unsigned int unk1850;
    unsigned int unk1854;
    unsigned int unk1858;
    unsigned int unk185c;
    unsigned int unk1860;
    unsigned int unk1864;
    unsigned int unk1868;
    unsigned int unk186c;
    unsigned int unk1870;
    unsigned int unk1874;
    unsigned int unk1878;
    unsigned int unk187c;
    unsigned int unk1880;
    unsigned int unk1884;
    unsigned int unk1888;
    unsigned int unk188c;
    unsigned int unk1890;
    unsigned int unk1894;
    unsigned int unk1898;
    unsigned int unk189c;
    unsigned int unk18a0;
    unsigned int unk18a4;
    unsigned int unk18a8;
    unsigned int unk18ac;
    unsigned int unk18b0;
    unsigned int unk18b4;
    unsigned int unk18b8;
    unsigned int unk18bc;
    unsigned int unk18c0;
    unsigned int unk18c4;
    unsigned int unk18c8;
    unsigned int unk18cc;
    unsigned int unk18d0;
    unsigned int unk18d4;
    unsigned int unk18d8;
    unsigned int unk18dc;
    unsigned int unk18e0;
    unsigned int unk18e4;
    unsigned int unk18e8;
    unsigned int unk18ec;
    unsigned int unk18f0;
    unsigned int unk18f4;
    unsigned int unk18f8;
    unsigned int unk18fc;
    unsigned int unk1900;
    unsigned int unk1904;
    unsigned int unk1908;
    unsigned int unk190c;
    unsigned int unk1910;
    unsigned int unk1914;
    unsigned int unk1918;
    unsigned int unk191c;
    unsigned int unk1920;
    unsigned int unk1924;
    unsigned int unk1928;
    unsigned int unk192c;
    unsigned int unk1930;
    unsigned int unk1934;
    unsigned int unk1938;
    unsigned int unk193c;
    unsigned int unk1940;
    unsigned int unk1944;
    unsigned int unk1948;
    unsigned int unk194c;
    unsigned int unk1950;
    unsigned int unk1954;
    unsigned int unk1958;
    unsigned int unk195c;
    unsigned int unk1960;
    unsigned int unk1964;
    unsigned int unk1968;
    unsigned int unk196c;
    unsigned int unk1970;
    unsigned int unk1974;
    unsigned int unk1978;
    unsigned int unk197c;
    unsigned int unk1980;
    unsigned int unk1984;
    unsigned int unk1988;
    unsigned int unk198c;
    unsigned int unk1990;
    unsigned int unk1994;
    unsigned int unk1998;
    unsigned int unk199c;
    unsigned int unk19a0;
    unsigned int unk19a4;
    unsigned int unk19a8;
    unsigned int unk19ac;
    unsigned int unk19b0;
    unsigned int unk19b4;
    unsigned int unk19b8;
    unsigned int unk19bc;
    unsigned int unk19c0;
    unsigned int unk19c4;
    unsigned int unk19c8;
    unsigned int unk19cc;
    unsigned int unk19d0;
    unsigned int unk19d4;
    unsigned int unk19d8;
    unsigned int unk19dc;
    unsigned int unk19e0;
    unsigned int unk19e4;
    unsigned int unk19e8;
    unsigned int unk19ec;
    unsigned int unk19f0;
    unsigned int unk19f4;
    unsigned int unk19f8;
    unsigned int unk19fc;
    unsigned int unk1a00;
    unsigned int unk1a04;
    unsigned int unk1a08;
    unsigned int unk1a0c;
    unsigned int unk1a10;
    unsigned int unk1a14;
    unsigned int unk1a18;
    unsigned int unk1a1c;
    unsigned int unk1a20;
    unsigned int unk1a24;
    unsigned int unk1a28;
    unsigned int unk1a2c;
    unsigned int unk1a30;
    unsigned int unk1a34;
    unsigned int unk1a38;
    unsigned int unk1a3c;
    unsigned int unk1a40;
    unsigned int unk1a44;
    unsigned int unk1a48;
    unsigned int unk1a4c;
    unsigned int unk1a50;
    unsigned int unk1a54;
    unsigned int unk1a58;
    unsigned int unk1a5c;
    unsigned int unk1a60;
    unsigned int unk1a64;
    unsigned int unk1a68;
    unsigned int unk1a6c;
    unsigned int unk1a70;
    unsigned int unk1a74;
    unsigned int unk1a78;
    unsigned int unk1a7c;
    unsigned int unk1a80;
    unsigned int unk1a84;
    unsigned int unk1a88;
    unsigned int unk1a8c;
    unsigned int unk1a90;
    unsigned int unk1a94;
    unsigned int unk1a98;
    unsigned int unk1a9c;
    unsigned int unk1aa0;
    unsigned int unk1aa4;
    unsigned int unk1aa8;
    unsigned int unk1aac;
    unsigned int unk1ab0;
    unsigned int unk1ab4;
    unsigned int unk1ab8;
    unsigned int unk1abc;
    unsigned int unk1ac0;
    unsigned int unk1ac4;
    unsigned int unk1ac8;
    unsigned int unk1acc;
    unsigned int unk1ad0;
    unsigned int unk1ad4;
    unsigned int unk1ad8;
    unsigned int unk1adc;
    unsigned int unk1ae0;
    unsigned int unk1ae4;
    unsigned int unk1ae8;
    unsigned int unk1aec;
    unsigned int unk1af0;
    unsigned int unk1af4;
    unsigned int unk1af8;
    unsigned int unk1afc;
    unsigned int unk1b00;
    unsigned int unk1b04;
    unsigned int unk1b08;
    unsigned int unk1b0c;
    unsigned int unk1b10;
    unsigned int unk1b14;
    unsigned int unk1b18;
    unsigned int unk1b1c;
    unsigned int unk1b20;
    unsigned int unk1b24;
    unsigned int unk1b28;
    unsigned int unk1b2c;
    unsigned int unk1b30;
    unsigned int unk1b34;
    unsigned int unk1b38;
    unsigned int unk1b3c;
    unsigned int unk1b40;
    unsigned int unk1b44;
    unsigned int unk1b48;
    unsigned int unk1b4c;
    unsigned int unk1b50;
    unsigned int unk1b54;
    unsigned int unk1b58;
    unsigned int unk1b5c;
    unsigned int unk1b60;
    unsigned int unk1b64;
    unsigned int unk1b68;
    unsigned int unk1b6c;
    unsigned int unk1b70;
    unsigned int unk1b74;
    unsigned int unk1b78;
    unsigned int unk1b7c;
    unsigned int unk1b80;
    unsigned int unk1b84;
    unsigned int unk1b88;
    unsigned int unk1b8c;
    unsigned int unk1b90;
    unsigned int unk1b94;
    unsigned int unk1b98;
    unsigned int unk1b9c;
    unsigned int unk1ba0;
    unsigned int unk1ba4;
    unsigned int unk1ba8;
    unsigned int unk1bac;
    unsigned int unk1bb0;
    unsigned int unk1bb4;
    unsigned int unk1bb8;
    unsigned int unk1bbc;
    unsigned int unk1bc0;
    unsigned int unk1bc4;
    unsigned int unk1bc8;
    unsigned int unk1bcc;
    unsigned int unk1bd0;
    unsigned int unk1bd4;
    unsigned int unk1bd8;
    unsigned int unk1bdc;
    unsigned int unk1be0;
    unsigned int unk1be4;
    unsigned int unk1be8;
    unsigned int unk1bec;
    unsigned int unk1bf0;
    unsigned int unk1bf4;
    unsigned int unk1bf8;
    unsigned int unk1bfc;
    unsigned int unk1c00;
    unsigned int unk1c04;
    unsigned int unk1c08;
    unsigned int unk1c0c;
    unsigned int unk1c10;
    unsigned int unk1c14;
    unsigned int unk1c18;
    unsigned int unk1c1c;
    unsigned int unk1c20;
    unsigned int unk1c24;
    unsigned int unk1c28;
    unsigned int unk1c2c;
    unsigned int unk1c30;
    unsigned int unk1c34;
    unsigned int unk1c38;
    unsigned int unk1c3c;
    unsigned int unk1c40;
    unsigned int unk1c44;
    unsigned int unk1c48;
    unsigned int unk1c4c;
    unsigned int unk1c50;
    unsigned int unk1c54;
    unsigned int unk1c58;
    unsigned int unk1c5c;
    unsigned int unk1c60;
    unsigned int unk1c64;
    unsigned int unk1c68;
    unsigned int unk1c6c;
    unsigned int unk1c70;
    unsigned int unk1c74;
    unsigned int unk1c78;
    unsigned int unk1c7c;
    unsigned int unk1c80;
    unsigned int unk1c84;
    unsigned int unk1c88;
    unsigned int unk1c8c;
    unsigned int unk1c90;
    unsigned int unk1c94;
    unsigned int unk1c98;
    unsigned int unk1c9c;
    unsigned int unk1ca0;
    unsigned int unk1ca4;
    unsigned int unk1ca8;
    unsigned int unk1cac;
    unsigned int unk1cb0;
    unsigned int unk1cb4;
    unsigned int unk1cb8;
    unsigned int unk1cbc;
    unsigned int unk1cc0;
    unsigned int unk1cc4;
    unsigned int unk1cc8;
    unsigned int unk1ccc;
    unsigned int unk1cd0;
    unsigned int unk1cd4;
    unsigned int unk1cd8;
    unsigned int unk1cdc;
    unsigned int unk1ce0;
    unsigned int unk1ce4;
    unsigned int unk1ce8;
    unsigned int unk1cec;
    unsigned int unk1cf0;
    unsigned int unk1cf4;
    unsigned int unk1cf8;
    unsigned int unk1cfc;
    unsigned int unk1d00;
    unsigned int unk1d04;
    unsigned int unk1d08;
    unsigned int unk1d0c;
    unsigned int unk1d10;
    unsigned int unk1d14;
    unsigned int unk1d18;
    unsigned int unk1d1c;
    unsigned int unk1d20;
    unsigned int unk1d24;
    unsigned int unk1d28;
    unsigned int unk1d2c;
    unsigned int unk1d30;
    unsigned int unk1d34;
    unsigned int unk1d38;
    unsigned int unk1d3c;
    unsigned int unk1d40;
    unsigned int unk1d44;
    unsigned int unk1d48;
    unsigned int unk1d4c;
    unsigned int unk1d50;
    unsigned int unk1d54;
    unsigned int unk1d58;
    unsigned int unk1d5c;
    unsigned int unk1d60;
    unsigned int unk1d64;
    unsigned int unk1d68;
    unsigned int unk1d6c;
    unsigned int unk1d70;
    unsigned int unk1d74;
    unsigned int unk1d78;
    unsigned int unk1d7c;
    unsigned int unk1d80;
    unsigned int unk1d84;
    unsigned int unk1d88;
    unsigned int unk1d8c;
    unsigned int unk1d90;
    unsigned int unk1d94;
    unsigned int unk1d98;
    unsigned int unk1d9c;
    unsigned int unk1da0;
    unsigned int unk1da4;
    unsigned int unk1da8;
    unsigned int unk1dac;
    unsigned int unk1db0;
    unsigned int unk1db4;
    unsigned int unk1db8;
    unsigned int unk1dbc;
    unsigned int unk1dc0;
    unsigned int unk1dc4;
    unsigned int unk1dc8;
    unsigned int unk1dcc;
    unsigned int unk1dd0;
    unsigned int unk1dd4;
    unsigned int unk1dd8;
    unsigned int unk1ddc;
    unsigned int unk1de0;
    unsigned int unk1de4;
    unsigned int unk1de8;
    unsigned int unk1dec;
    unsigned int unk1df0;
    unsigned int unk1df4;
    unsigned int unk1df8;
    unsigned int unk1dfc;
    unsigned int unk1e00;
    unsigned int unk1e04;
    unsigned int unk1e08;
    unsigned int unk1e0c;
    unsigned int unk1e10;
    unsigned int unk1e14;
    unsigned int unk1e18;
    unsigned int unk1e1c;
    unsigned int unk1e20;
    unsigned int unk1e24;
    unsigned int unk1e28;
    unsigned int unk1e2c;
    unsigned int unk1e30;
    unsigned int unk1e34;
    unsigned int unk1e38;
    unsigned int unk1e3c;
    unsigned int unk1e40;
    unsigned int unk1e44;
    unsigned int unk1e48;
    unsigned int unk1e4c;
    unsigned int unk1e50;
    unsigned int unk1e54;
    unsigned int unk1e58;
    unsigned int unk1e5c;
    unsigned int unk1e60;
    unsigned int unk1e64;
    unsigned int unk1e68;
    unsigned int unk1e6c;
    unsigned int unk1e70;
    unsigned int unk1e74;
    unsigned int unk1e78;
    unsigned int unk1e7c;
    unsigned int unk1e80;
    unsigned int unk1e84;
    unsigned int unk1e88;
    unsigned int unk1e8c;
    unsigned int unk1e90;
    unsigned int unk1e94;
    unsigned int unk1e98;
    unsigned int unk1e9c;
    unsigned int unk1ea0;
    unsigned int unk1ea4;
    unsigned int unk1ea8;
    unsigned int unk1eac;
    unsigned int unk1eb0;
    unsigned int unk1eb4;
    unsigned int unk1eb8;
    unsigned int unk1ebc;
    unsigned int unk1ec0;
    unsigned int unk1ec4;
    unsigned int unk1ec8;
    unsigned int unk1ecc;
    unsigned int unk1ed0;
    unsigned int unk1ed4;
    unsigned int unk1ed8;
    unsigned int unk1edc;
    unsigned int unk1ee0;
    unsigned int unk1ee4;
    unsigned int unk1ee8;
    unsigned int unk1eec;
    unsigned int unk1ef0;
    unsigned int unk1ef4;
    unsigned int unk1ef8;
    unsigned int unk1efc;
    unsigned int unk1f00;
    unsigned int unk1f04;
    unsigned int unk1f08;
    unsigned int unk1f0c;
    unsigned int unk1f10;
    unsigned int unk1f14;
    unsigned int unk1f18;
    unsigned int unk1f1c;
    unsigned int unk1f20;
    unsigned int unk1f24;
    unsigned int unk1f28;
    unsigned int unk1f2c;
    unsigned int unk1f30;
    unsigned int unk1f34;
    unsigned int unk1f38;
    unsigned int unk1f3c;
    unsigned int unk1f40;
    unsigned int unk1f44;
    unsigned int unk1f48;
    unsigned int unk1f4c;
    unsigned int unk1f50;
    unsigned int unk1f54;
    unsigned int unk1f58;
    unsigned int unk1f5c;
    unsigned int unk1f60;
    unsigned int unk1f64;
    unsigned int unk1f68;
    unsigned int unk1f6c;
    unsigned int unk1f70;
    unsigned int unk1f74;
    unsigned int unk1f78;
    unsigned int unk1f7c;
    unsigned int unk1f80;
    unsigned int unk1f84;
    unsigned int unk1f88;
    unsigned int unk1f8c;
    unsigned int unk1f90;
    unsigned int unk1f94;
    unsigned int unk1f98;
    unsigned int unk1f9c;
    unsigned int unk1fa0;
    unsigned int unk1fa4;
    unsigned int unk1fa8;
    unsigned int unk1fac;
    unsigned int unk1fb0;
    unsigned int unk1fb4;
    unsigned int unk1fb8;
    unsigned int unk1fbc;
    unsigned int unk1fc0;
    unsigned int unk1fc4;
    unsigned int unk1fc8;
    unsigned int unk1fcc;
    unsigned int unk1fd0;
    unsigned int unk1fd4;
    unsigned int unk1fd8;
    unsigned int unk1fdc;
    unsigned int unk1fe0;
    unsigned int unk1fe4;
    unsigned int unk1fe8;
    unsigned int unk1fec;
    unsigned int unk1ff0;
    unsigned int unk1ff4;
    unsigned int unk1ff8;
    unsigned int unk1ffc;
    unsigned int unk2000;
    unsigned int unk2004;
    unsigned int unk2008;
    unsigned int unk200c;
    unsigned int unk2010;
    unsigned int unk2014;
    unsigned int unk2018;
    unsigned int unk201c;
    unsigned int unk2020;
    unsigned int unk2024;
    unsigned int unk2028;
    unsigned int unk202c;
    unsigned int unk2030;
    unsigned int unk2034;
    unsigned int unk2038;
    unsigned int unk203c;
    unsigned int unk2040;
    unsigned int unk2044;
    unsigned int unk2048;
    unsigned int unk204c;
    unsigned int unk2050;
    unsigned int unk2054;
    unsigned int unk2058;
    unsigned int unk205c;
    unsigned int unk2060;
    unsigned int unk2064;
    unsigned int unk2068;
    unsigned int unk206c;
    unsigned int unk2070;
    unsigned int unk2074;
    unsigned int unk2078;
    unsigned int unk207c;
    unsigned int unk2080;
    unsigned int unk2084;
    unsigned int unk2088;
    unsigned int unk208c;
    unsigned int unk2090;
    unsigned int unk2094;
    unsigned int unk2098;
    unsigned int unk209c;
    unsigned int unk20a0;
    unsigned int unk20a4;
    unsigned int unk20a8;
    Search();
    ~Search();
    void FindPath(Point&, const Point&, const Triangle&, const Point&, const Triangle&, float);
};
// Builds start/end triangles from the two locations, runs a path search between their positions, and returns a copy of start moved to the resulting position.
// @fnv 0x006d7a40
Location __cdecl FUN_006d7a40(Location& start, Location& end, float cost)
{
    Triangle fromVal;
    if (reinterpret_cast<::PathingLocationProxy *>(&(start))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
    {
        unsigned short triangleIndex;
        MeshRef meshHandle;
        if (reinterpret_cast<::PathingLocation *>(&(start))->FindNavMeshTriangle((::NavMeshPtr &)(meshHandle), triangleIndex))
        {
            fromVal.mesh = meshHandle;
            fromVal.index = triangleIndex;
        }
        else
            return start;
    }
    else
        return start;
    Triangle to;
    to.mesh = 0;
    to.index = 0xffff;
    if (reinterpret_cast<::PathingLocationProxy *>(&(end))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
    {
        unsigned short triangleIndex;
        MeshRef meshHandle;
        if (reinterpret_cast<::PathingLocation *>(&(end))->FindNavMeshTriangle((::NavMeshPtr &)(meshHandle), triangleIndex))
        {
            to.mesh = meshHandle;
            to.index = triangleIndex;
        }
    }
    Search aSearch;
    Point position;
    aSearch.FindPath(position, (*(::fnv_006d7a40::Point *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()))), fromVal, (*(::fnv_006d7a40::Point *)&(reinterpret_cast<::TaskQueueInterface *>((void *)&(end))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()))), to, cost);
    Location result(start);
    reinterpret_cast<::FUN_006dd460 *>(&(result))->FUN_006dd460_1((const ::NiPoint3 &)(position));
    return result;
}
}  // namespace fnv_006d7a40

struct PathNode;

struct PathNodeHolder
{
    void IncRefCount();
    void DecRefCount();
    PathNodeHolder(NiPoint3 pos, float radius);
    char data[0x50];
};

struct PathSource
{
    void IncRefCount();
    void DecRefCount();
    NiPoint3 GetPosition();
    void Finish(NiPointer<PathNodeHolder>& holder);
};

struct PathEntry;
struct EntryListNode
{
    PathEntry* GetAt(int i);
};
struct WeightList
{
    float& GetAt(int i);
};


// Validates the source, creates and attaches a PathNodeHolder, fills it from entries with weights, counts positive/negative values, then finishes it.
// @fnv 0x006d7ca0
bool __cdecl BuildPathNodeHolder(NiPointer<PathSource>& pSource, EntryListNode* entries, WeightList* weights)
{
    if (!reinterpret_cast<::FUN_006d7f00_shell *>((((PathSource*)pSource)))->IsModifierPositive())
        return false;
    NiPointer<PathNodeHolder> holder =
        new PathNodeHolder(((PathSource*)pSource)->GetPosition(), reinterpret_cast<::FUN_00508050_Class *>((((PathSource*)pSource)))->FUN_00508050());
    reinterpret_cast<::LOSGridOwner *>((((PathSource*)pSource)))->UpdateNavMeshes((::LOSTargetPtr &)(holder));
    int count = ((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((entries))->GetName()));
    for (int iA = 0; iA < count; iA++)
    {
        PathEntry* entryB = entries->GetAt(iA);
        float weight4 = weights ? ((float)(reinterpret_cast<::S3e60 *>((weights))->FUN_006a7ad0(iA))) : DAT_01012054;
        ::MarkReachableTriangles((::P110Location *)(entryB), (::P110DataPtr *)&(holder), 1, reinterpret_cast<::FUN_00639aa0_shell *>((((PathSource*)pSource)))->FUN_00639aa0(), weight4);
    }
    std::intptr_t pos2 = 0;
    std::intptr_t neg2 = 0;
    for (unsigned int j2 = 0; j2 < reinterpret_cast<::BGSMessageInitAccess *>((((PathNodeHolder*)holder)))->GetIconFormID(); j2++)
    {
        char v5 = reinterpret_cast<::FUN_006d7ee0_shell *>((((PathNodeHolder*)holder)))->GetByteAt(j2);
        if (v5 != 0x7f)
        {
            if (v5 > 0)
                pos2++;
            else
                neg2++;
        }
    }
    reinterpret_cast<::BGSCameraPath *>((((PathNodeHolder*)holder)))->AssignParentPath((::BGSCameraPath *)(pos2));
    reinterpret_cast<::LowProcess *>((((PathNodeHolder*)holder)))->SetCurrentBoundObject((::TESBoundObject *)(neg2));
    ((PathSource*)pSource)->Finish(holder);
    return true;
}

class NiPoint2
{
  public:
    float x, y;
    NiPoint2();
    NiPoint2(float, float);
};
class P110Point : public NiPoint3
{
  public:
};
class P110EdgeInfo
{
  public:
    int kind;
};
class P110Triangle
{
  public:
};
struct P110VertexPair
{
    NiPoint3* first;
    NiPoint3* second;
};
class P110Mesh
{
  public:
    P110Triangle* FUN_005582f0(unsigned short);
    NiPoint3 FUN_00558220(unsigned short);
    int FindTriangleEdge(unsigned short, int, const NiPoint2&, const NiPoint2&, NiPoint2&);
    P110VertexPair FUN_0068f040(unsigned short, int);
};
class P110Data
{
  public:
    const NiPointer<NavMesh>& FUN_006d89b0(unsigned int);
    bool GetMapValue(unsigned int, unsigned int&);
};
class P110DataPtr
{
  public:
};
class P110Location
{
  public:
};
class FUN_006d89d0
{
  public:
    int index;
    unsigned char value;
    FUN_006d89d0(int, char);
};
class P110Visited
{
  public:
    void* table;
    FUN_006d89d0* buffer;
    unsigned int count, reserved;
    ScrapHeapBuffer* heap;
    P110Visited(unsigned int, unsigned int, unsigned int);
    ~P110Visited();
};

// @fnv 0x006d7f40
bool __cdecl MarkReachableTriangles(P110Location* location, P110DataPtr* data, bool reset, float maxDistance,
                                    float angle)
{
    if (!reinterpret_cast<::FUN_006d8990_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->GetFlags())
        return false;
    float originTriangle;
    unsigned int direction = 0;
    unsigned int examined = 0;
    if (!reinterpret_cast<::PathingLocationProxy *>((location))->FindContainingTriangle((::FindTriangleForLocationFilter *)(void *)(0)))
        return false;
    NavMeshPtr examinedCount;
    unsigned short intersections = 0xffff;
    if (!reinterpret_cast<::PathingLocation *>((location))->FindNavMeshTriangle(examinedCount, intersections))
        return false;
    if (reset)
        reinterpret_cast<::fnv_006e2000::FUN_006e2000_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->ClampNonPositiveTextChars();
    NiPoint3 center = reinterpret_cast<::TaskQueueInterface *>((void *)(location))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    NiPoint3 radius = (*(::NiPoint3 *)&(reinterpret_cast<::fnv_006ab380::FUN_006ab380_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->GetDest(*(::fnv_006ab380::NiPoint3 *)nullptr)));
    float originMesh = reinterpret_cast<::FUN_00639aa0_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->FUN_00639aa0();
    originTriangle = originMesh * originMesh;
    NiPoint3 origin = NiPoint3::ZERO;
    if (angle >= 0.0)
        FUN_004169a0(angle, origin.x, origin.y);
    for (unsigned int meshIndex = 0; meshIndex < reinterpret_cast<::FUN_006d8990_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->GetFlags(); ++meshIndex)
    {
        NiPointer<NavMesh> mesh = ((::P110Data *)(::FUN_00559450((int *)(data))))->FUN_006d89b0(meshIndex);
        unsigned int triangle = 0;
        if (!((::P110Data *)(::FUN_00559450((int *)(data))))->GetMapValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((P110Mesh*)(NavMesh*)mesh)))->FUN_0084e3a0())), triangle))
            continue;
        unsigned int offset = 0;
        while (offset < ::FUN_00558200((char *)(((P110Mesh*)(NavMesh*)mesh))))
        {
            while (reinterpret_cast<::FUN_006d7ee0_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->GetByteAt(offset + triangle) != 127 ||
                   reinterpret_cast<::FUN_00691140_shell *>((((::P110Triangle *)(reinterpret_cast<::NavMesh *>((((P110Mesh*)(NavMesh*)mesh)))->GetTriangle((unsigned short)offset)))))->FUN_00691140(0x20))
            {
                ++offset;
                if (offset >= ::FUN_00558200((char *)(((P110Mesh*)(NavMesh*)mesh))))
                    break;
            }
            if (offset >= ::FUN_00558200((char *)(((P110Mesh*)(NavMesh*)mesh))))
                break;
            ++examined;
            P110Mesh* point;
            NiPoint3 current = reinterpret_cast<::NavMesh *>((((P110Mesh*)(NavMesh*)mesh)))->GetNavMeshData((unsigned short)offset);
            if (originMesh != 0.0)
            {
                NiPoint3 delta = current - radius;
                delta.z *= 3.0;
                if (reinterpret_cast<::TESCombatStyle *>((void *)(((P110Point*)&delta)))->UpdateCombatStyle() > originTriangle)
                {
                    ++offset;
                    continue;
                }
            }
            if (maxDistance > 0.0 || angle >= 0.0)
            {
                bool delta = false;
                NiPoint3 reject = current - reinterpret_cast<::TaskQueueInterface *>((void *)(location))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
                if (maxDistance > 0.0 && reinterpret_cast<::TESCombatStyle *>((void *)(((P110Point*)&reject)))->UpdateCombatStyle() > maxDistance * maxDistance)
                    delta = true;
                if (!delta && angle >= 0.0 && reinterpret_cast<::FUN_004b6190_shell *>((void *)(((P110Point*)&origin)))->DotProduct((void *)&(reject)) < 0.0)
                    delta = true;
                if (delta)
                {
                    if (reinterpret_cast<::FUN_006d7ee0_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->GetByteAt(offset + triangle) == 127)
                        reinterpret_cast<::FUN_006d8970_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->SetByteAt(
                            offset + triangle,
                            -(char)reinterpret_cast<::Outer006d8910 *>((((P110Mesh*)(NavMesh*)mesh)))->FUN_006d8910((unsigned short)offset));
                    ++offset;
                    continue;
                }
            }
            NiPoint2 start(current.x, current.y);
            NiPoint2 end(center.x, center.y);
            NiPoint2 reached;
            unsigned short currentTriangle = (unsigned short)offset;
            point = (P110Mesh*)(NavMesh*)mesh;
            unsigned int currentMesh = triangle;
            bool visited = false;
            P110Visited currentOffset(64, 0, 0);
            reinterpret_cast<::fnv_006db840::BSSimpleArray *>(&(currentOffset))->InsertAtEnd(
                (const ::NiPoint2 &)((const ::FUN_006d89d0 &)(FUN_006d89d0(currentTriangle + currentMesh, reinterpret_cast<::Outer006d8910 *>((point))->FUN_006d8910(currentTriangle)))));
            if (currentTriangle == intersections && point == (P110Mesh*)(NavMesh*)examinedCount)
                visited = true;
            else
            {
                int edge = point->FindTriangleEdge(currentTriangle, -1, start, end, reached);
                ++direction;
                while (edge != -1)
                {
                    P110Mesh* nextEdge;
                    unsigned short nextMesh;
                    int nextTriangle;
                    if (reinterpret_cast<::MeshX *>((point))->FindAdjacentEdge(currentTriangle, edge, (::MeshX **)&(nextEdge), (unsigned short *)&(nextMesh), (int *)&(nextTriangle)))
                    {
                        P110EdgeInfo* info = ((::P110EdgeInfo *)(reinterpret_cast<::FUN_0068f230_shell *>((point))->FUN_0068f230(currentTriangle, edge)));
                        if (info && info->kind == 1)
                            break;
                        if (nextEdge != point)
                        {
                            if (!((::P110Data *)(::FUN_00559450((int *)(data))))->GetMapValue(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((nextEdge))->FUN_0084e3a0())), currentMesh))
                                break;
                            P110VertexPair vertices = nextEdge->FUN_0068f040(nextMesh, nextTriangle);
                            NiPoint2 second(vertices.first->x, vertices.first->y);
                            NiPoint2 first(vertices.second->x, vertices.second->y);
                            reached = (*(::NiPoint2 *)(::FUN_006ba3d0((::TwoComponentVector *)&(second), (::TwoComponentVector *)&(first), (::TwoComponentVector *)&(reached), (::TwoComponentVector *)&(end), {})));
                        }
                        point = nextEdge;
                        currentTriangle = nextMesh;
                        reinterpret_cast<::fnv_006db840::BSSimpleArray *>(&(currentOffset))->InsertAtEnd(
                            (const ::NiPoint2 &)((const ::FUN_006d89d0 &)(FUN_006d89d0(currentTriangle + currentMesh, reinterpret_cast<::Outer006d8910 *>((point))->FUN_006d8910(currentTriangle)))));
                        NiPoint2 next;
                        edge = nextEdge->FindTriangleEdge(nextMesh, nextTriangle, reached, end, next);
                        reached = next;
                        ++direction;
                        if (currentTriangle == intersections && point == (P110Mesh*)(NavMesh*)examinedCount)
                        {
                            visited = true;
                            break;
                        }
                    }
                    else
                        break;
                }
            }
            if (visited)
            {
                for (unsigned int a = 0; a < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(currentOffset))->GetName())); ++a)
                    reinterpret_cast<::FUN_006d8970_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->SetByteAt((*(::FUN_006d89d0 *)(reinterpret_cast<::S006950d0 *>(&(currentOffset))->GetElement(a))).index,
                                                    (*(::FUN_006d89d0 *)(reinterpret_cast<::S006950d0 *>(&(currentOffset))->GetElement(a))).value);
                for (unsigned int b = 0; b < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(currentOffset))->GetName())); ++b)
                {
                    if (::GetByteAtOffset56((char *)(((::P110Data *)(::FUN_00559450((int *)(data)))))) == 3)
                        break;
                    if ((char)(*(::FUN_006d89d0 *)(reinterpret_cast<::S006950d0 *>(&(currentOffset))->GetElement(b))).value > ::GetByteAtOffset56((char *)(((::P110Data *)(::FUN_00559450((int *)(data)))))))
                        reinterpret_cast<::FUN_004410d0_Class *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->SetByteAtOffset38((*(::FUN_006d89d0 *)(reinterpret_cast<::S006950d0 *>(&(currentOffset))->GetElement(b))).value);
                }
            }
            else
            {
                for (unsigned int c = 0; c < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(currentOffset))->GetName())); ++c)
                    if (reinterpret_cast<::FUN_006d7ee0_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->GetByteAt((*(::FUN_006d89d0 *)(reinterpret_cast<::S006950d0 *>(&(currentOffset))->GetElement(c))).index) == 127)
                        reinterpret_cast<::FUN_006d8970_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->SetByteAt((*(::FUN_006d89d0 *)(reinterpret_cast<::S006950d0 *>(&(currentOffset))->GetElement(c))).index,
                                                        -(char)(*(::FUN_006d89d0 *)(reinterpret_cast<::S006950d0 *>(&(currentOffset))->GetElement(c))).value);
                for (unsigned int d = 0; d < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(currentOffset))->GetName())); ++d)
                {
                    if (((char)(reinterpret_cast<::FUN_006aabf0_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->GetByteAt39())) == -3)
                        break;
                    if (-(char)(*(::FUN_006d89d0 *)(reinterpret_cast<::S006950d0 *>(&(currentOffset))->GetElement(d))).value < ((char)(reinterpret_cast<::FUN_006aabf0_shell *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->GetByteAt39())))
                        reinterpret_cast<::NiGeometryData *>((((::P110Data *)(::FUN_00559450((int *)(data))))))->SetCompressFlags(-(char)(*(::FUN_006d89d0 *)(reinterpret_cast<::S006950d0 *>(&(currentOffset))->GetElement(d))).value);
                }
            }
            ++offset;
        }
    }
    return true;
}

struct Coordinate3
{
    float x, y, z;
};
struct SearchPoint
{

    float x, y, z;

    SearchPoint();

    SearchPoint(float a, float b, float c);

    void FUN_006815c0();
};

struct SearchBounds
{

    SearchPoint lower;

    SearchPoint upper;
};

struct SearchCell;

struct LocationBlock;

struct SearchObject
{




};

struct GridCellMesh
{
    void* FUN_005875a0();
};
struct SearchCell
{





};

struct CellResult
{


    bool FUN_0069ad00(LocationBlock*);

    int FUN_0068efb0();
};

struct SearchList
{

    void* unk00;

    void* unk04;

    unsigned int unk08;

    unsigned int unk0c;

    SearchList();

    ~SearchList();

    void Initialize();

    void FUN_006c6de0();

    void FUN_007cb2e0(void* const& target);



    void** FUN_00877a30(unsigned int);
};

struct LocationBlock
{
    void* value;

    LocationBlock();
    LocationBlock(void*);

    ~LocationBlock();

    void FUN_0042fb00();

    void FUN_0042fa40();

    void FUN_0042fa20(void*);

    void AppendValue(LocationBlock const&);


    bool FUN_0069ad00(LocationBlock* out);
};

struct SearchOutput
{




    void AppendValue(LocationBlock const&);

    int FUN_00719b20(void*, int, bool(__cdecl*)(void*, void*));
};

struct NavMeshLinks
{


    LocationBlock FUN_00464f60(unsigned int);
};

struct SearchNavCell
{

};

struct NodeVectors
{

    unsigned int flags, id, parent, boundsMinX, boundsMinY, boundsMinZ, boundsMaxX, boundsMaxY, boundsMaxZ;
    SearchList nearNeighbors;

    SearchList farNeighbors;
};

struct SearchNode
{

    NodeVectors* FUN_0068efb0();
};

extern bool __cdecl FUN_0042ff10(void*, void*);


extern bool __cdecl DoBoundsOverlap(const SearchPoint*, const SearchPoint*, const SearchPoint*, const SearchPoint*);

extern void __cdecl FUN_006dd93d0(int);

extern int __cdecl FUN_005875a0(void*);

extern void __cdecl FUN_007cb2e0(SearchList*, void*);

extern void __cdecl Initialize(SearchList*);

extern void __cdecl FUN_006c6de0(SearchList*);

extern void __cdecl FUN_0042fb00(LocationBlock*);

extern void __cdecl FUN_0042fa40(LocationBlock*);

extern void __cdecl FUN_0042fa20(LocationBlock*, void*);

// @fnv 0x006d8a40
unsigned char __cdecl FUN_006d8a40(SearchObject* search, float radius, SearchOutput* result, bool existingOnly)

{

    Coordinate3 coordinates;

    reinterpret_cast<::TaskQueueInterface *>((search))->QueueActorAnimationTask((*(::NiPoint3 *)(&coordinates)));

    SearchCell* centralCell = ((::SearchCell *)(reinterpret_cast<::PathingLocation *>((search))->GetContainingCell()));

    if (!centralCell)
        return false;

    SearchPoint boxMin(coordinates.x - radius, coordinates.y - radius, DAT_01015f5c);

    SearchPoint boxMax(coordinates.x + radius, coordinates.y + radius, DAT_01016970);

    if (!existingOnly)
    {

        SearchList located;

        if (!reinterpret_cast<::TESObjectCELL *>((centralCell))->IsCellInterior())
        {

            for (int x = reinterpret_cast<::TESObjectCELL *>((centralCell))->GetCellGridX() - 1; x < reinterpret_cast<::TESObjectCELL *>((centralCell))->GetCellGridX() + 2; ++x)
            {

                for (int y = reinterpret_cast<::TESObjectCELL *>((centralCell))->GetCellGridY() - 1; y < reinterpret_cast<::TESObjectCELL *>((centralCell))->GetCellGridY() + 2; ++y)
                {

                    SearchPoint candidateMin(static_cast<float>(x << 12), static_cast<float>(y << 12), DAT_01015f5c);

                    SearchPoint candidateMax(static_cast<float>(x << 12) + ::DAT_01017a10,

                                             static_cast<float>(y << 12) + ::DAT_01017a10,

                                             DAT_01016970);

                    if (DoBoundsOverlap(&candidateMin, &candidateMax, &boxMin, &boxMax))
                    {

                        void* mesh = ((void *)(reinterpret_cast<::TESWorldSpace *>((((GridCellMesh*)((void *)(reinterpret_cast<::TESObjectCELL *>((centralCell))->GetParentWorldSpace())))))->GetCellAtGridPosition({}, {})));

                        reinterpret_cast<::FUN_00438690 *>(&(located))->FUN_007cb2e0((unsigned int *)&(mesh));
                    }
                }
            }
        }
        else
        {

            reinterpret_cast<::FUN_00438690 *>(&(located))->FUN_007cb2e0((unsigned int *)&(const void *const &)(((::SearchCell *)(reinterpret_cast<::PathingLocation *>((search))->GetContainingCell()))));
        }

        if (reinterpret_cast<::FUN_0076b610_Class *>(&(located))->FUN_0076b610())
        {

            return false;
        }

        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(located))->GetName())); ++i)
        {

            SearchNavCell* cell = reinterpret_cast<SearchNavCell*>(*located.FUN_00877a30(i));

            if (cell && ((::NavMeshLinks *)(std::uintptr_t)(::FUN_0070ec90((char *)(cell)))))
            {

                for (unsigned int k = 0; k < reinterpret_cast<::FUN_00620b80_shell *>((((::NavMeshLinks *)(std::uintptr_t)(::FUN_0070ec90((char *)(cell))))))->GetReferenceFlags(); ++k)
                {

                    reinterpret_cast<::S2f850 *>((result))->AppendValue((const ::NavMeshPtr &)((const ::LocationBlock &)(((::NavMeshLinks *)(std::uintptr_t)(::FUN_0070ec90((char *)(cell))))->FUN_00464f60(k))));
                }
            }
        }
    }
    else
    {

        if (reinterpret_cast<::PathingLocationProxy *>((search))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
        {
            LocationBlock location;
            if (!reinterpret_cast<::PathingLocation *>((search))->ResolveNavMesh((*(::NavMeshPtr *)(&location))))
                return false;
            reinterpret_cast<::S2f850 *>((result))->AppendValue((const ::NavMeshPtr &)(location));
        }
        else
        {
            return false;
        }
    }

    if (reinterpret_cast<::FUN_0076b610_Class *>((result))->FUN_0076b610())
        return false;

    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((result))->GetName())); ++i)
    {

        LocationBlock rootRef(((void *)(reinterpret_cast<::S3e60 *>((result))->FUN_006a7ad0(i))));

        unsigned int countNear =
            ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((::NodeVectors *)(reinterpret_cast<::FUN_0068efb0_shell *>((reinterpret_cast<SearchNode*>(((::CellResult *)(::FUN_00559450((int *)&(rootRef)))))))->FUN_0068efb0()))->nearNeighbors))->GetName()));

        unsigned int countFar =
            ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((::NodeVectors *)(reinterpret_cast<::FUN_0068efb0_shell *>((reinterpret_cast<SearchNode*>(((::CellResult *)(::FUN_00559450((int *)&(rootRef)))))))->FUN_0068efb0()))->farNeighbors))->GetName()));

        for (unsigned int j = 0; j < countNear + countFar; ++j)
        {

            void* candidate;
            if (j < countNear)
            {
                candidate = *((::NodeVectors *)(reinterpret_cast<::FUN_0068efb0_shell *>((reinterpret_cast<SearchNode*>(((::CellResult *)(::FUN_00559450((int *)&(rootRef)))))))->FUN_0068efb0()))
                                 ->nearNeighbors.FUN_00877a30(j);
            }
            else
            {
                candidate = *((::NodeVectors *)(reinterpret_cast<::FUN_0068efb0_shell *>((reinterpret_cast<SearchNode*>(((::CellResult *)(::FUN_00559450((int *)&(rootRef)))))))->FUN_0068efb0()))
                                 ->farNeighbors.FUN_00877a30(j - countNear);
            }
            if (candidate)
            {

                LocationBlock location;

                if (reinterpret_cast<::NavMeshInfo *>((reinterpret_cast<LocationBlock*>(candidate)))->ResolveNavMesh((*(::NavMeshPtr *)(&location))))
                {

                    if (result->FUN_00719b20(&location, 0, FUN_0042ff10) != -1)
                    {

                        continue;
                    }

                    SearchCell* cell2 = ((::SearchCell *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((((::CellResult *)(::FUN_00559450((int *)&(location))))))->GetCurrentMoveModeType()));

                    if (!cell2)
                    {

                        continue;
                    }

                    if (reinterpret_cast<::TESObjectCELL *>((centralCell))->IsCellInterior())
                    {

                        if (cell2 != centralCell)
                        {

                            continue;
                        }
                    }
                    else if (((std::uintptr_t)(reinterpret_cast<::TESObjectCELL *>((centralCell))->GetParentWorldSpace())) != ((std::uintptr_t)(reinterpret_cast<::TESObjectCELL *>((cell2))->GetParentWorldSpace())))
                    {

                        continue;
                    }

                    SearchPoint minimum;

                    SearchPoint kMaximum;

                    if (reinterpret_cast<::FUN_006969e0_shell *>((((::CellResult *)(::FUN_00559450((int *)&(location))))))->FUN_006969e0((::NiPoint3 *)(::SearchPoint *)(&minimum), (::NiPoint3 *)(::SearchPoint *)(&kMaximum)) &&

                        DoBoundsOverlap(&minimum, &kMaximum, &boxMin, &boxMax))
                    {

                        reinterpret_cast<::S2f850 *>((result))->AppendValue((const ::NavMeshPtr &)(location));
                    }
                }
            }
        }
    }

    return true;
}

struct TriangleReference
{
    const NavMeshInfo* mesh;
    unsigned short triangle;
    TriangleReference(const NavMeshInfo*, unsigned short);
};
struct TriangleReferences
{
    void* table;
    TriangleReference* data;
    unsigned int size;
    unsigned int capacity;
    TriangleReferences();
    ~TriangleReferences();
};
struct NearbyMeshes
{
    void* table;
    NiPointer<NavMesh>* data;
    unsigned int size;
    unsigned int capacity;
    NearbyMeshes();
    ~NearbyMeshes();
    NiPointer<NavMesh>& FUN_00877a30(unsigned int);
};
struct TriangleIndices
{
    void* table;
    unsigned short* data;
    unsigned int size;
    unsigned int capacity;
    TriangleIndices();
    ~TriangleIndices();
};
struct TriangleScratch
{
    void* table;
    void* data;
    unsigned int size;
    unsigned int capacity;
    TriangleScratch();
    ~TriangleScratch();
};
struct RadiusPoint : NiPoint3
{
    RadiusPoint(float, float, float);
};
struct MeshInfoAccessor
{
    bool FUN_0069ad00(NavMeshPtr&);
};
struct TriangleAccessor
{
};
struct EdgeVertices
{
    const NiPoint3* first;
    const NiPoint3* second;
};
struct MeshAccessor
{
    const NavMeshInfo* FUN_0068efb0();
    TriangleAccessor* FUN_005582f0(unsigned short);
    EdgeVertices FUN_0068f040(unsigned short, int);
};

// @fnv 0x006d9480
bool __cdecl IsPathingLocationClear(PathingLocation* location, float radius)
{
    TriangleReferences scratch;
    NearbyMeshes meshes;
    FUN_006d8a20(location, radius, (SearchOutput*)&meshes);
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(meshes))->GetName())); ++i)
    {
        TriangleIndices indices;
        reinterpret_cast<::Obj00696c00 *>((((MeshAccessor*)((::NavMesh *)(::FUN_00559450((int *)&(meshes.FUN_00877a30(i))))))))->ForwardToSub((std::intptr_t)&(const ::NiPoint3 &)(reinterpret_cast<::TaskQueueInterface *>((void *)(location))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()) - RadiusPoint(radius, radius, 0.0f)),
                           (std::intptr_t)&(const ::NiPoint3 &)(reinterpret_cast<::TaskQueueInterface *>((void *)(location))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()) + RadiusPoint(radius, radius, 0.0f)), (std::intptr_t)&(indices));
        for (unsigned int j = 0; j < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(indices))->GetName())); ++j)
        {
            reinterpret_cast<::FUN_006dba30_Class *>(&(scratch))->FUN_006dba30((const ::S0069a690 *)&(const ::TriangleReference &)(TriangleReference(reinterpret_cast<::FUN_0068efb0_shell *>((((MeshAccessor*)((::NavMesh *)(::FUN_00559450((int *)&(meshes.FUN_00877a30(i))))))))->FUN_0068efb0(),
                                                   reinterpret_cast<::FUN_005eeda0_this *>(&(indices))->GetBufferEntry(j))));
        }
    }
    TriangleScratch triangles;
    for (unsigned int k = 0; k < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(scratch))->GetName())); ++k)
    {
        NavMeshPtr mesh;
        if (reinterpret_cast<::NavMeshInfo *>((((MeshInfoAccessor*)(*(::TriangleReference *)(reinterpret_cast<::S006950d0 *>(&(scratch))->GetElement(k))).mesh)))->ResolveNavMesh(mesh))
        {
            for (int edge = 0; edge < 3; ++edge)
            {
                if (!((unsigned char)(reinterpret_cast<::FUN_0068f200_shell *>((((::TriangleAccessor *)(reinterpret_cast<::NavMesh *>((((MeshAccessor*)((::NavMesh *)(::FUN_00559450((int *)&(mesh)))))))->GetTriangle((*(::TriangleReference *)(reinterpret_cast<::S006950d0 *>(&(scratch))->GetElement(k))).triangle)))))->FUN_0068f200(edge))))
                {
                    EdgeVertices vertices =
                        ((MeshAccessor*)((::NavMesh *)(::FUN_00559450((int *)&(mesh)))))->FUN_0068f040((*(::TriangleReference *)(reinterpret_cast<::S006950d0 *>(&(scratch))->GetElement(k))).triangle, edge);
                    if (::FUN_006ba9e0((*(const ::Pt3 *)(vertices.first)), (*(const ::Pt3 *)(vertices.second)), (const ::Pt3 &)((const ::NiPoint3 &)(reinterpret_cast<::TaskQueueInterface *>((void *)(location))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()))), radius))
                        return false;
                }
            }
        }
    }
    return true;
}

namespace fnv_006da7c0 {
struct CellOps
{
};
struct LocationBench
{
    void* table;
    NiPoint3 point;
    const NavMeshInfo* m_fGridOriginX;
    const void* meshes;
    TESObjectCELL* cell;
    TESWorldSpace* world;
    unsigned int key;
    unsigned short triangle;
    unsigned char flags, padding;
    LocationBench(const NiPoint3&, CellOps*);
    LocationBench(const NiPoint3&, void*);
    ~LocationBench();
};
struct PointArrayBench
{
    void* table;
    NiPoint3* data;
    unsigned int size, capacity;
    PointArrayBench(unsigned int);
    ~PointArrayBench();
    NiPoint3& FUN_006a1440(unsigned int);
};
struct Point2Bench
{
    float x, y;
    Point2Bench();
    Point2Bench(float, float);
};
struct CloseRequestBench
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
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    CloseRequestBench();
    ~CloseRequestBench();
    void FUN_006dad40(const NiPoint3&);
    void FUN_006d1bc0(const LocationBench&);
};
struct CloseSolutionBench
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CloseSolutionBench();
    ~CloseSolutionBench();
};
struct RequestBench
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
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    RequestBench();
    ~RequestBench();
    void FUN_006dad40(const NiPoint3&);
    void FUN_006d1bc0(const LocationBench&);
};
struct SolutionBench
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
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    SolutionBench();
    ~SolutionBench();
};
// @fnv 0x006da7c0
float __cdecl FUN_006da7c0(CellOps* cell, const NiPoint3& pos, int mode, unsigned int count)
{
    float eType;
    int kPosition;
    NiPoint3 kCellSearchPosition;
    NavMeshPtr m_fGridOriginX;
    kCellSearchPosition = ::NiPoint3::ZERO;
    float kRange = 500.0f;
    kPosition = mode;
    bool m_fWorldTransformCoefficient4 = reinterpret_cast<::TESObjectCELL *>((cell))->IsCellInterior();
    float kPoints, kNavMesh, kTargetPoint;
    if (m_fWorldTransformCoefficient4)
    {
        kPoints = -kRange;
        eType = -kRange;
        kNavMesh = kRange;
        kTargetPoint = kRange;
    }
    else
    {
        kPoints = float(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridX() << 12);
        eType = float(reinterpret_cast<::TESObjectCELL *>((cell))->GetCellGridY() << 12);
        kNavMesh = kPoints + 4096.0;
        kTargetPoint = eType + 4096.0;
    }
    LocationBench afWorldOriginY(pos, cell);
    if (!reinterpret_cast<::PathingLocationProxy *>(&(afWorldOriginY))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
        return 0.0f;
    reinterpret_cast<::PathingLocation *>(&(afWorldOriginY))->ResolveNavMesh(m_fGridOriginX);
    PointArrayBench kPointArrayBench(count);
    if (kPosition == 2)
    {
        for (unsigned int i = 0; i < count; i++)
        {
            if (!::FUN_006d7110((::TESWorldSpace *)(void *)(((void *)(std::uintptr_t)(reinterpret_cast<::BGSTerrainManager *>(&(afWorldOriginY))->GetMinLevel()))), (::TESObjectCELL *)(0), pos, 2000.0f, kPointArrayBench.FUN_006a1440(i)))
                i--;
        }
    }
    else
    {
        for (unsigned int j = 0; j < count; j++)
        {
            kPointArrayBench.FUN_006a1440(j).x = ::RandomFloat(kPoints, kNavMesh);
            kPointArrayBench.FUN_006a1440(j).y = ::RandomFloat(eType, kTargetPoint);
            kPointArrayBench.FUN_006a1440(j).z = pos.z;
        }
    }
    for (unsigned int k = 0; k < count; k++)
    {
        switch (kPosition)
        {
        case 0: {
            bool kPoint3;
            Point2Bench bFirst;
            Point2Bench kPoint1(kPointArrayBench.FUN_006a1440(k).x, kPointArrayBench.FUN_006a1440(k).y);
            Point2Bench bSecond(kPointArrayBench.FUN_006a1440((k + 1) % count).x,
                                kPointArrayBench.FUN_006a1440((k + 1) % count).y);
            Point2Bench kPoint2(kPointArrayBench.FUN_006a1440((k + 2) % count).x,
                                kPointArrayBench.FUN_006a1440((k + 2) % count).y);
            Point2Bench kPoint0(kPointArrayBench.FUN_006a1440((k + 3) % count).x,
                                kPointArrayBench.FUN_006a1440((k + 3) % count).y);
            kPoint3 = ::FUN_006b9e90((const ::NiPoint2 &)(kPoint1), (const ::NiPoint2 &)(bSecond), (const ::NiPoint2 &)(kPoint2), (const ::NiPoint2 &)(kPoint0), (::NiPoint2 &)(bFirst));
            bool testResult = ::FUN_006ba010((const ::NiPoint3 *)&(kPoint1), (const ::NiPoint3 *)&(bSecond), (const ::NiPoint3 *)&(kPoint2), (const ::NiPoint3 *)&(kPoint0));
            if (kPoint3 != testResult)
                ::FUN_005b5e40();
            break;
        }
        case 1: {
            CloseRequestBench request;
            reinterpret_cast<::FUN_006d3ac0_Class *>(&(request))->AssignPathingLocation((const ::PathingLocation &)(afWorldOriginY));
            reinterpret_cast<::FUN_006dad40_Class *>(&(request))->FUN_006dad40(kPointArrayBench.FUN_006a1440(k));
            CloseSolutionBench solution;
            ::FindNearbyTriangles((::GeometrySource *)(::fnv_006da7c0::CloseRequestBench *)(&request), (::OutputList *)(::fnv_006da7c0::CloseSolutionBench *)(&solution));
            break;
        }
        case 2: {
            LocationBench goal(kPointArrayBench.FUN_006a1440(k), ((void *)(std::uintptr_t)(reinterpret_cast<::BGSTerrainManager *>(&(afWorldOriginY))->GetMinLevel())));
            RequestBench request;
            reinterpret_cast<::FUN_006d3ac0_Class *>(&(request))->AssignPathingLocation((const ::PathingLocation &)(afWorldOriginY));
            reinterpret_cast<::PathingRequest *>(&(request))->SetDestination((::PathingLocation *)&(goal));
            SolutionBench solution;
            ::FUN_006d0b10((::PathingRequest *)(::fnv_006da7c0::RequestBench *)(&request), (::PathingSolution *)(::fnv_006da7c0::SolutionBench *)(&solution));
            break;
        }
        }
    }
    return 0.0f;
}
}  // namespace fnv_006da7c0

struct FUN_006db290_base
{
    FUN_006db290_base();
    virtual ~FUN_006db290_base();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct FUN_006db290_mm
{
    void* FUN_00aa42e0();
};

struct FUN_006db290_cls : public FUN_006db290_base
{
    FUN_006db290_cls(unsigned int a1, unsigned int a2, void* navMesh);
    virtual ~FUN_006db290_cls();
    void FUN_006b3eb0(unsigned int a1, unsigned int a2);
    void* m_pNavMesh;
};

// Stores navMesh, or a default nav mesh obtained from FUN_00401020, then calls FUN_006b3eb0 with a1 and a2.
// @fnv 0x006db290
FUN_006db290_cls::FUN_006db290_cls(unsigned int a1, unsigned int a2, void* navMesh)
{
    m_pNavMesh = navMesh != 0 ? navMesh : ((FUN_006db290_mm*)::FUN_00401020())->FUN_00aa42e0();
    FUN_006b3eb0(a1, a2);
}

struct P048Location
{
};
struct P048Request
{
};
struct P048Mesh
{
    void FUN_00558220(NiPoint3*, unsigned short);
    const NavMeshInfo* FUN_0068efb0();
};
struct P048MeshPtr
{
    P048Mesh* Get();
};
struct P048Node
{
    P048Mesh* mesh;
    unsigned short triangle;
    unsigned short flags;
    unsigned int unk08, unk0c, unk10;
};
struct P048Open
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    P048Open(int, int, void*);
    ~P048Open();
    unsigned int GetSize();
};
struct P048Closed
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    P048Closed(int, int, void*);
    ~P048Closed();
};
struct P048Hide
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000c;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001c;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002c;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003c;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004c;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005c;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006c;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007c;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008c;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009c;
    unsigned int unk00a0;
    unsigned int unk00a4;
    unsigned int unk00a8;
    unsigned int unk00ac;
    unsigned int unk00b0;
    unsigned int unk00b4;
    unsigned int unk00b8;
    unsigned int unk00bc;
    unsigned int unk00c0;
    unsigned int unk00c4;
    unsigned int unk00c8;
    unsigned int unk00cc;
    unsigned int unk00d0;
    unsigned int unk00d4;
    unsigned int unk00d8;
    unsigned int unk00dc;
    unsigned int unk00e0;
    unsigned int unk00e4;
    unsigned int unk00e8;
    unsigned int unk00ec;
    unsigned int unk00f0;
    unsigned int unk00f4;
    unsigned int unk00f8;
    unsigned int unk00fc;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010c;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011c;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012c;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013c;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014c;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015c;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016c;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017c;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018c;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019c;
    unsigned int unk01a0;
    unsigned int unk01a4;
    unsigned int unk01a8;
    unsigned int unk01ac;
    unsigned int unk01b0;
    unsigned int unk01b4;
    unsigned int unk01b8;
    unsigned int unk01bc;
    unsigned int unk01c0;
    unsigned int unk01c4;
    unsigned int unk01c8;
    unsigned int unk01cc;
    unsigned int unk01d0;
    unsigned int unk01d4;
    unsigned int unk01d8;
    unsigned int unk01dc;
    unsigned int unk01e0;
    unsigned int unk01e4;
    unsigned int unk01e8;
    unsigned int unk01ec;
    unsigned int unk01f0;
    unsigned int unk01f4;
    unsigned int unk01f8;
    unsigned int unk01fc;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020c;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021c;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022c;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023c;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024c;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025c;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026c;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027c;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028c;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029c;
    unsigned int unk02a0;
    unsigned int unk02a4;
    unsigned int unk02a8;
    unsigned int unk02ac;
    unsigned int unk02b0;
    unsigned int unk02b4;
    unsigned int unk02b8;
    unsigned int unk02bc;
    unsigned int unk02c0;
    unsigned int unk02c4;
    unsigned int unk02c8;
    unsigned int unk02cc;
    unsigned int unk02d0;
    unsigned int unk02d4;
    unsigned int unk02d8;
    unsigned int unk02dc;
    unsigned int unk02e0;
    unsigned int unk02e4;
    unsigned int unk02e8;
    unsigned int unk02ec;
    unsigned int unk02f0;
    unsigned int unk02f4;
    unsigned int unk02f8;
    unsigned int unk02fc;
    unsigned int unk0300;
    unsigned int unk0304;
    unsigned int unk0308;
    unsigned int unk030c;
    unsigned int unk0310;
    unsigned int unk0314;
    unsigned int unk0318;
    unsigned int unk031c;
    unsigned int unk0320;
    unsigned int unk0324;
    unsigned int unk0328;
    unsigned int unk032c;
    unsigned int unk0330;
    unsigned int unk0334;
    unsigned int unk0338;
    unsigned int unk033c;
    unsigned int unk0340;
    unsigned int unk0344;
    unsigned int unk0348;
    unsigned int unk034c;
    unsigned int unk0350;
    unsigned int unk0354;
    unsigned int unk0358;
    unsigned int unk035c;
    unsigned int unk0360;
    unsigned int unk0364;
    unsigned int unk0368;
    unsigned int unk036c;
    unsigned int unk0370;
    unsigned int unk0374;
    unsigned int unk0378;
    unsigned int unk037c;
    unsigned int unk0380;
    unsigned int unk0384;
    unsigned int unk0388;
    unsigned int unk038c;
    unsigned int unk0390;
    unsigned int unk0394;
    unsigned int unk0398;
    unsigned int unk039c;
    unsigned int unk03a0;
    unsigned int unk03a4;
    unsigned int unk03a8;
    unsigned int unk03ac;
    unsigned int unk03b0;
    unsigned int unk03b4;
    unsigned int unk03b8;
    unsigned int unk03bc;
    unsigned int unk03c0;
    unsigned int unk03c4;
    unsigned int unk03c8;
    unsigned int unk03cc;
    unsigned int unk03d0;
    unsigned int unk03d4;
    unsigned int unk03d8;
    unsigned int unk03dc;
    unsigned int unk03e0;
    unsigned int unk03e4;
    unsigned int unk03e8;
    unsigned int unk03ec;
    unsigned int unk03f0;
    unsigned int unk03f4;
    unsigned int unk03f8;
    unsigned int unk03fc;
    unsigned int unk0400;
    unsigned int unk0404;
    unsigned int unk0408;
    unsigned int unk040c;
    unsigned int unk0410;
    unsigned int unk0414;
    unsigned int unk0418;
    unsigned int unk041c;
    unsigned int unk0420;
    unsigned int unk0424;
    unsigned int unk0428;
    unsigned int unk042c;
    unsigned int unk0430;
    unsigned int unk0434;
    unsigned int unk0438;
    unsigned int unk043c;
    unsigned int unk0440;
    unsigned int unk0444;
    unsigned int unk0448;
    unsigned int unk044c;
    unsigned int unk0450;
    unsigned int unk0454;
    unsigned int unk0458;
    unsigned int unk045c;
    unsigned int unk0460;
    unsigned int unk0464;
    unsigned int unk0468;
    unsigned int unk046c;
    unsigned int unk0470;
    unsigned int unk0474;
    unsigned int unk0478;
    unsigned int unk047c;
    unsigned int unk0480;
    unsigned int unk0484;
    unsigned int unk0488;
    unsigned int unk048c;
    unsigned int unk0490;
    unsigned int unk0494;
    unsigned int unk0498;
    unsigned int unk049c;
    unsigned int unk04a0;
    unsigned int unk04a4;
    unsigned int unk04a8;
    unsigned int unk04ac;
    unsigned int unk04b0;
    unsigned int unk04b4;
    unsigned int unk04b8;
    unsigned int unk04bc;
    unsigned int unk04c0;
    unsigned int unk04c4;
    unsigned int unk04c8;
    unsigned int unk04cc;
    unsigned int unk04d0;
    unsigned int unk04d4;
    unsigned int unk04d8;
    unsigned int unk04dc;
    unsigned int unk04e0;
    unsigned int unk04e4;
    unsigned int unk04e8;
    unsigned int unk04ec;
    unsigned int unk04f0;
    unsigned int unk04f4;
    unsigned int unk04f8;
    unsigned int unk04fc;
    unsigned int unk0500;
    unsigned int unk0504;
    unsigned int unk0508;
    unsigned int unk050c;
    unsigned int unk0510;
    unsigned int unk0514;
    unsigned int unk0518;
    unsigned int unk051c;
    unsigned int unk0520;
    unsigned int unk0524;
    unsigned int unk0528;
    unsigned int unk052c;
    unsigned int unk0530;
    unsigned int unk0534;
    unsigned int unk0538;
    unsigned int unk053c;
    unsigned int unk0540;
    unsigned int unk0544;
    unsigned int unk0548;
    unsigned int unk054c;
    unsigned int unk0550;
    unsigned int unk0554;
    unsigned int unk0558;
    unsigned int unk055c;
    unsigned int unk0560;
    unsigned int unk0564;
    unsigned int unk0568;
    unsigned int unk056c;
    unsigned int unk0570;
    unsigned int unk0574;
    unsigned int unk0578;
    unsigned int unk057c;
    unsigned int unk0580;
    unsigned int unk0584;
    unsigned int unk0588;
    unsigned int unk058c;
    unsigned int unk0590;
    unsigned int unk0594;
    unsigned int unk0598;
    unsigned int unk059c;
    unsigned int unk05a0;
    unsigned int unk05a4;
    unsigned int unk05a8;
    unsigned int unk05ac;
    unsigned int unk05b0;
    unsigned int unk05b4;
    unsigned int unk05b8;
    unsigned int unk05bc;
    unsigned int unk05c0;
    unsigned int unk05c4;
    unsigned int unk05c8;
    unsigned int unk05cc;
    unsigned int unk05d0;
    unsigned int unk05d4;
    unsigned int unk05d8;
    unsigned int unk05dc;
    unsigned int unk05e0;
    unsigned int unk05e4;
    unsigned int unk05e8;
    unsigned int unk05ec;
    unsigned int unk05f0;
    unsigned int unk05f4;
    unsigned int unk05f8;
    unsigned int unk05fc;
    unsigned int unk0600;
    unsigned int unk0604;
    unsigned int unk0608;
    unsigned int unk060c;
    unsigned int unk0610;
    unsigned int unk0614;
    unsigned int unk0618;
    unsigned int unk061c;
    unsigned int unk0620;
    unsigned int unk0624;
    unsigned int unk0628;
    unsigned int unk062c;
    unsigned int unk0630;
    unsigned int unk0634;
    unsigned int unk0638;
    unsigned int unk063c;
    unsigned int unk0640;
    unsigned int unk0644;
    unsigned int unk0648;
    unsigned int unk064c;
    unsigned int unk0650;
    unsigned int unk0654;
    unsigned int unk0658;
    unsigned int unk065c;
    unsigned int unk0660;
    unsigned int unk0664;
    unsigned int unk0668;
    unsigned int unk066c;
    unsigned int unk0670;
    unsigned int unk0674;
    unsigned int unk0678;
    unsigned int unk067c;
    unsigned int unk0680;
    unsigned int unk0684;
    unsigned int unk0688;
    unsigned int unk068c;
    unsigned int unk0690;
    unsigned int unk0694;
    unsigned int unk0698;
    unsigned int unk069c;
    unsigned int unk06a0;
    unsigned int unk06a4;
    unsigned int unk06a8;
    unsigned int unk06ac;
    unsigned int unk06b0;
    unsigned int unk06b4;
    unsigned int unk06b8;
    unsigned int unk06bc;
    unsigned int unk06c0;
    unsigned int unk06c4;
    unsigned int unk06c8;
    unsigned int unk06cc;
    unsigned int unk06d0;
    unsigned int unk06d4;
    unsigned int unk06d8;
    unsigned int unk06dc;
    unsigned int unk06e0;
    unsigned int unk06e4;
    unsigned int unk06e8;
    unsigned int unk06ec;
    unsigned int unk06f0;
    unsigned int unk06f4;
    unsigned int unk06f8;
    unsigned int unk06fc;
    unsigned int unk0700;
    unsigned int unk0704;
    unsigned int unk0708;
    unsigned int unk070c;
    unsigned int unk0710;
    unsigned int unk0714;
    unsigned int unk0718;
    unsigned int unk071c;
    unsigned int unk0720;
    unsigned int unk0724;
    unsigned int unk0728;
    unsigned int unk072c;
    unsigned int unk0730;
    unsigned int unk0734;
    unsigned int unk0738;
    unsigned int unk073c;
    unsigned int unk0740;
    unsigned int unk0744;
    unsigned int unk0748;
    unsigned int unk074c;
    unsigned int unk0750;
    unsigned int unk0754;
    unsigned int unk0758;
    unsigned int unk075c;
    unsigned int unk0760;
    unsigned int unk0764;
    unsigned int unk0768;
    unsigned int unk076c;
    unsigned int unk0770;
    unsigned int unk0774;
    unsigned int unk0778;
    unsigned int unk077c;
    unsigned int unk0780;
    unsigned int unk0784;
    unsigned int unk0788;
    unsigned int unk078c;
    unsigned int unk0790;
    unsigned int unk0794;
    unsigned int unk0798;
    unsigned int unk079c;
    unsigned int unk07a0;
    unsigned int unk07a4;
    unsigned int unk07a8;
    unsigned int unk07ac;
    unsigned int unk07b0;
    unsigned int unk07b4;
    unsigned int unk07b8;
    unsigned int unk07bc;
    unsigned int unk07c0;
    unsigned int unk07c4;
    unsigned int unk07c8;
    unsigned int unk07cc;
    unsigned int unk07d0;
    unsigned int unk07d4;
    unsigned int unk07d8;
    unsigned int unk07dc;
    unsigned int unk07e0;
    unsigned int unk07e4;
    unsigned int unk07e8;
    unsigned int unk07ec;
    unsigned int unk07f0;
    unsigned int unk07f4;
    unsigned int unk07f8;
    unsigned int unk07fc;
    unsigned int unk0800;
    unsigned int unk0804;
    unsigned int unk0808;
    unsigned int unk080c;
    unsigned int unk0810;
    unsigned int unk0814;
    unsigned int unk0818;
    unsigned int unk081c;
    unsigned int unk0820;
    unsigned int unk0824;
    unsigned int unk0828;
    unsigned int unk082c;
    unsigned int unk0830;
    unsigned int unk0834;
    unsigned int unk0838;
    unsigned int unk083c;
    unsigned int unk0840;
    unsigned int unk0844;
    unsigned int unk0848;
    unsigned int unk084c;
    unsigned int unk0850;
    unsigned int unk0854;
    unsigned int unk0858;
    unsigned int unk085c;
    unsigned int unk0860;
    unsigned int unk0864;
    unsigned int unk0868;
    unsigned int unk086c;
    unsigned int unk0870;
    unsigned int unk0874;
    unsigned int unk0878;
    unsigned int unk087c;
    unsigned int unk0880;
    unsigned int unk0884;
    unsigned int unk0888;
    unsigned int unk088c;
    unsigned int unk0890;
    unsigned int unk0894;
    unsigned int unk0898;
    unsigned int unk089c;
    unsigned int unk08a0;
    unsigned int unk08a4;
    unsigned int unk08a8;
    unsigned int unk08ac;
    unsigned int unk08b0;
    unsigned int unk08b4;
    unsigned int unk08b8;
    unsigned int unk08bc;
    unsigned int unk08c0;
    unsigned int unk08c4;
    unsigned int unk08c8;
    unsigned int unk08cc;
    unsigned int unk08d0;
    unsigned int unk08d4;
    unsigned int unk08d8;
    unsigned int unk08dc;
    unsigned int unk08e0;
    unsigned int unk08e4;
    unsigned int unk08e8;
    unsigned int unk08ec;
    unsigned int unk08f0;
    unsigned int unk08f4;
    unsigned int unk08f8;
    unsigned int unk08fc;
    unsigned int unk0900;
    unsigned int unk0904;
    unsigned int unk0908;
    unsigned int unk090c;
    unsigned int unk0910;
    unsigned int unk0914;
    unsigned int unk0918;
    unsigned int unk091c;
    unsigned int unk0920;
    unsigned int unk0924;
    unsigned int unk0928;
    unsigned int unk092c;
    unsigned int unk0930;
    unsigned int unk0934;
    unsigned int unk0938;
    unsigned int unk093c;
    unsigned int unk0940;
    unsigned int unk0944;
    unsigned int unk0948;
    unsigned int unk094c;
    unsigned int unk0950;
    unsigned int unk0954;
    unsigned int unk0958;
    unsigned int unk095c;
    unsigned int unk0960;
    unsigned int unk0964;
    unsigned int unk0968;
    unsigned int unk096c;
    unsigned int unk0970;
    unsigned int unk0974;
    unsigned int unk0978;
    unsigned int unk097c;
    unsigned int unk0980;
    unsigned int unk0984;
    unsigned int unk0988;
    unsigned int unk098c;
    unsigned int unk0990;
    unsigned int unk0994;
    unsigned int unk0998;
    unsigned int unk099c;
    unsigned int unk09a0;
    unsigned int unk09a4;
    unsigned int unk09a8;
    unsigned int unk09ac;
    unsigned int unk09b0;
    unsigned int unk09b4;
    unsigned int unk09b8;
    unsigned int unk09bc;
    unsigned int unk09c0;
    unsigned int unk09c4;
    unsigned int unk09c8;
    unsigned int unk09cc;
    unsigned int unk09d0;
    unsigned int unk09d4;
    unsigned int unk09d8;
    unsigned int unk09dc;
    unsigned int unk09e0;
    unsigned int unk09e4;
    unsigned int unk09e8;
    unsigned int unk09ec;
    unsigned int unk09f0;
    unsigned int unk09f4;
    unsigned int unk09f8;
    unsigned int unk09fc;
    unsigned int unk0a00;
    unsigned int unk0a04;
    unsigned int unk0a08;
    unsigned int unk0a0c;
    unsigned int unk0a10;
    unsigned int unk0a14;
    unsigned int unk0a18;
    unsigned int unk0a1c;
    unsigned int unk0a20;
    unsigned int unk0a24;
    unsigned int unk0a28;
    unsigned int unk0a2c;
    unsigned int unk0a30;
    unsigned int unk0a34;
    unsigned int unk0a38;
    unsigned int unk0a3c;
    unsigned int unk0a40;
    unsigned int unk0a44;
    unsigned int unk0a48;
    unsigned int unk0a4c;
    unsigned int unk0a50;
    unsigned int unk0a54;
    unsigned int unk0a58;
    unsigned int unk0a5c;
    unsigned int unk0a60;
    unsigned int unk0a64;
    unsigned int unk0a68;
    unsigned int unk0a6c;
    unsigned int unk0a70;
    unsigned int unk0a74;
    unsigned int unk0a78;
    unsigned int unk0a7c;
    unsigned int unk0a80;
    unsigned int unk0a84;
    unsigned int unk0a88;
    unsigned int unk0a8c;
    unsigned int unk0a90;
    unsigned int unk0a94;
    unsigned int unk0a98;
    unsigned int unk0a9c;
    unsigned int unk0aa0;
    unsigned int unk0aa4;
    unsigned int unk0aa8;
    unsigned int unk0aac;
    unsigned int unk0ab0;
    unsigned int unk0ab4;
    unsigned int unk0ab8;
    unsigned int unk0abc;
    unsigned int unk0ac0;
    unsigned int unk0ac4;
    unsigned int unk0ac8;
    unsigned int unk0acc;
    unsigned int unk0ad0;
    unsigned int unk0ad4;
    unsigned int unk0ad8;
    unsigned int unk0adc;
    unsigned int unk0ae0;
    unsigned int unk0ae4;
    unsigned int unk0ae8;
    unsigned int unk0aec;
    unsigned int unk0af0;
    unsigned int unk0af4;
    unsigned int unk0af8;
    unsigned int unk0afc;
    unsigned int unk0b00;
    unsigned int unk0b04;
    unsigned int unk0b08;
    unsigned int unk0b0c;
    unsigned int unk0b10;
    unsigned int unk0b14;
    unsigned int unk0b18;
    unsigned int unk0b1c;
    unsigned int unk0b20;
    unsigned int unk0b24;
    unsigned int unk0b28;
    unsigned int unk0b2c;
    unsigned int unk0b30;
    unsigned int unk0b34;
    unsigned int unk0b38;
    unsigned int unk0b3c;
    unsigned int unk0b40;
    unsigned int unk0b44;
    unsigned int unk0b48;
    unsigned int unk0b4c;
    unsigned int unk0b50;
    unsigned int unk0b54;
    unsigned int unk0b58;
    unsigned int unk0b5c;
    unsigned int unk0b60;
    unsigned int unk0b64;
    unsigned int unk0b68;
    unsigned int unk0b6c;
    unsigned int unk0b70;
    unsigned int unk0b74;
    unsigned int unk0b78;
    unsigned int unk0b7c;
    unsigned int unk0b80;
    unsigned int unk0b84;
    unsigned int unk0b88;
    unsigned int unk0b8c;
    unsigned int unk0b90;
    unsigned int unk0b94;
    unsigned int unk0b98;
    unsigned int unk0b9c;
    unsigned int unk0ba0;
    unsigned int unk0ba4;
    unsigned int unk0ba8;
    unsigned int unk0bac;
    unsigned int unk0bb0;
    unsigned int unk0bb4;
    unsigned int unk0bb8;
    unsigned int unk0bbc;
    unsigned int unk0bc0;
    unsigned int unk0bc4;
    unsigned int unk0bc8;
    unsigned int unk0bcc;
    unsigned int unk0bd0;
    unsigned int unk0bd4;
    unsigned int unk0bd8;
    unsigned int unk0bdc;
    unsigned int unk0be0;
    unsigned int unk0be4;
    unsigned int unk0be8;
    unsigned int unk0bec;
    unsigned int unk0bf0;
    unsigned int unk0bf4;
    unsigned int unk0bf8;
    unsigned int unk0bfc;
    unsigned int unk0c00;
    unsigned int unk0c04;
    unsigned int unk0c08;
    unsigned int unk0c0c;
    unsigned int unk0c10;
    unsigned int unk0c14;
    unsigned int unk0c18;
    unsigned int unk0c1c;
    unsigned int unk0c20;
    unsigned int unk0c24;
    unsigned int unk0c28;
    unsigned int unk0c2c;
    unsigned int unk0c30;
    unsigned int unk0c34;
    unsigned int unk0c38;
    unsigned int unk0c3c;
    unsigned int unk0c40;
    unsigned int unk0c44;
    unsigned int unk0c48;
    unsigned int unk0c4c;
    unsigned int unk0c50;
    unsigned int unk0c54;
    unsigned int unk0c58;
    unsigned int unk0c5c;
    unsigned int unk0c60;
    unsigned int unk0c64;
    unsigned int unk0c68;
    unsigned int unk0c6c;
    unsigned int unk0c70;
    unsigned int unk0c74;
    unsigned int unk0c78;
    unsigned int unk0c7c;
    unsigned int unk0c80;
    unsigned int unk0c84;
    unsigned int unk0c88;
    unsigned int unk0c8c;
    unsigned int unk0c90;
    unsigned int unk0c94;
    unsigned int unk0c98;
    unsigned int unk0c9c;
    unsigned int unk0ca0;
    unsigned int unk0ca4;
    unsigned int unk0ca8;
    unsigned int unk0cac;
    unsigned int unk0cb0;
    unsigned int unk0cb4;
    unsigned int unk0cb8;
    unsigned int unk0cbc;
    unsigned int unk0cc0;
    unsigned int unk0cc4;
    unsigned int unk0cc8;
    unsigned int unk0ccc;
    unsigned int unk0cd0;
    unsigned int unk0cd4;
    unsigned int unk0cd8;
    unsigned int unk0cdc;
    unsigned int unk0ce0;
    unsigned int unk0ce4;
    unsigned int unk0ce8;
    unsigned int unk0cec;
    unsigned int unk0cf0;
    unsigned int unk0cf4;
    unsigned int unk0cf8;
    unsigned int unk0cfc;
    unsigned int unk0d00;
    unsigned int unk0d04;
    unsigned int unk0d08;
    unsigned int unk0d0c;
    unsigned int unk0d10;
    unsigned int unk0d14;
    unsigned int unk0d18;
    unsigned int unk0d1c;
    unsigned int unk0d20;
    unsigned int unk0d24;
    unsigned int unk0d28;
    unsigned int unk0d2c;
    unsigned int unk0d30;
    unsigned int unk0d34;
    unsigned int unk0d38;
    unsigned int unk0d3c;
    unsigned int unk0d40;
    unsigned int unk0d44;
    unsigned int unk0d48;
    unsigned int unk0d4c;
    unsigned int unk0d50;
    unsigned int unk0d54;
    unsigned int unk0d58;
    unsigned int unk0d5c;
    unsigned int unk0d60;
    unsigned int unk0d64;
    unsigned int unk0d68;
    unsigned int unk0d6c;
    unsigned int unk0d70;
    unsigned int unk0d74;
    unsigned int unk0d78;
    unsigned int unk0d7c;
    unsigned int unk0d80;
    unsigned int unk0d84;
    unsigned int unk0d88;
    unsigned int unk0d8c;
    unsigned int unk0d90;
    unsigned int unk0d94;
    unsigned int unk0d98;
    unsigned int unk0d9c;
    unsigned int unk0da0;
    unsigned int unk0da4;
    unsigned int unk0da8;
    unsigned int unk0dac;
    unsigned int unk0db0;
    unsigned int unk0db4;
    unsigned int unk0db8;
    unsigned int unk0dbc;
    unsigned int unk0dc0;
    unsigned int unk0dc4;
    unsigned int unk0dc8;
    unsigned int unk0dcc;
    unsigned int unk0dd0;
    unsigned int unk0dd4;
    unsigned int unk0dd8;
    unsigned int unk0ddc;
    unsigned int unk0de0;
    unsigned int unk0de4;
    unsigned int unk0de8;
    unsigned int unk0dec;
    unsigned int unk0df0;
    unsigned int unk0df4;
    unsigned int unk0df8;
    unsigned int unk0dfc;
    unsigned int unk0e00;
    unsigned int unk0e04;
    unsigned int unk0e08;
    unsigned int unk0e0c;
    unsigned int unk0e10;
    unsigned int unk0e14;
    unsigned int unk0e18;
    unsigned int unk0e1c;
    unsigned int unk0e20;
    unsigned int unk0e24;
    unsigned int unk0e28;
    unsigned int unk0e2c;
    unsigned int unk0e30;
    unsigned int unk0e34;
    unsigned int unk0e38;
    unsigned int unk0e3c;
    unsigned int unk0e40;
    unsigned int unk0e44;
    unsigned int unk0e48;
    unsigned int unk0e4c;
    unsigned int unk0e50;
    unsigned int unk0e54;
    unsigned int unk0e58;
    unsigned int unk0e5c;
    unsigned int unk0e60;
    unsigned int unk0e64;
    unsigned int unk0e68;
    unsigned int unk0e6c;
    unsigned int unk0e70;
    unsigned int unk0e74;
    unsigned int unk0e78;
    unsigned int unk0e7c;
    unsigned int unk0e80;
    unsigned int unk0e84;
    unsigned int unk0e88;
    unsigned int unk0e8c;
    unsigned int unk0e90;
    unsigned int unk0e94;
    unsigned int unk0e98;
    unsigned int unk0e9c;
    unsigned int unk0ea0;
    unsigned int unk0ea4;
    unsigned int unk0ea8;
    unsigned int unk0eac;
    unsigned int unk0eb0;
    unsigned int unk0eb4;
    unsigned int unk0eb8;
    unsigned int unk0ebc;
    unsigned int unk0ec0;
    unsigned int unk0ec4;
    unsigned int unk0ec8;
    unsigned int unk0ecc;
    unsigned int unk0ed0;
    unsigned int unk0ed4;
    unsigned int unk0ed8;
    unsigned int unk0edc;
    unsigned int unk0ee0;
    unsigned int unk0ee4;
    unsigned int unk0ee8;
    unsigned int unk0eec;
    unsigned int unk0ef0;
    unsigned int unk0ef4;
    unsigned int unk0ef8;
    unsigned int unk0efc;
    unsigned int unk0f00;
    unsigned int unk0f04;
    unsigned int unk0f08;
    unsigned int unk0f0c;
    unsigned int unk0f10;
    unsigned int unk0f14;
    unsigned int unk0f18;
    unsigned int unk0f1c;
    unsigned int unk0f20;
    unsigned int unk0f24;
    unsigned int unk0f28;
    unsigned int unk0f2c;
    unsigned int unk0f30;
    unsigned int unk0f34;
    unsigned int unk0f38;
    unsigned int unk0f3c;
    unsigned int unk0f40;
    unsigned int unk0f44;
    unsigned int unk0f48;
    unsigned int unk0f4c;
    unsigned int unk0f50;
    unsigned int unk0f54;
    unsigned int unk0f58;
    unsigned int unk0f5c;
    unsigned int unk0f60;
    unsigned int unk0f64;
    unsigned int unk0f68;
    unsigned int unk0f6c;
    unsigned int unk0f70;
    unsigned int unk0f74;
    unsigned int unk0f78;
    unsigned int unk0f7c;
    unsigned int unk0f80;
    unsigned int unk0f84;
    unsigned int unk0f88;
    unsigned int unk0f8c;
    unsigned int unk0f90;
    unsigned int unk0f94;
    unsigned int unk0f98;
    unsigned int unk0f9c;
    unsigned int unk0fa0;
    unsigned int unk0fa4;
    unsigned int unk0fa8;
    unsigned int unk0fac;
    unsigned int unk0fb0;
    unsigned int unk0fb4;
    unsigned int unk0fb8;
    unsigned int unk0fbc;
    unsigned int unk0fc0;
    unsigned int unk0fc4;
    unsigned int unk0fc8;
    unsigned int unk0fcc;
    unsigned int unk0fd0;
    unsigned int unk0fd4;
    unsigned int unk0fd8;
    unsigned int unk0fdc;
    unsigned int unk0fe0;
    unsigned int unk0fe4;
    unsigned int unk0fe8;
    unsigned int unk0fec;
    unsigned int unk0ff0;
    unsigned int unk0ff4;
    unsigned int unk0ff8;
    unsigned int unk0ffc;
    unsigned int unk1000;
    unsigned int unk1004;
    unsigned int unk1008;
    unsigned int unk100c;
    unsigned int unk1010;
    unsigned int unk1014;
    unsigned int unk1018;
    unsigned int unk101c;
    unsigned int unk1020;
    unsigned int unk1024;
    unsigned int unk1028;
    unsigned int unk102c;
    unsigned int unk1030;
    unsigned int unk1034;
    unsigned int unk1038;
    unsigned int unk103c;
    unsigned int unk1040;
    unsigned int unk1044;
    unsigned int unk1048;
    unsigned int unk104c;
    unsigned int unk1050;
    unsigned int unk1054;
    unsigned int unk1058;
    unsigned int unk105c;
    unsigned int unk1060;
    unsigned int unk1064;
    unsigned int unk1068;
    unsigned int unk106c;
    unsigned int unk1070;
    unsigned int unk1074;
    unsigned int unk1078;
    unsigned int unk107c;
    unsigned int unk1080;
    unsigned int unk1084;
    unsigned int unk1088;
    unsigned int unk108c;
    unsigned int unk1090;
    unsigned int unk1094;
    unsigned int unk1098;
    unsigned int unk109c;
    unsigned int unk10a0;
    unsigned int unk10a4;
    unsigned int unk10a8;
    unsigned int unk10ac;
    unsigned int unk10b0;
    unsigned int unk10b4;
    unsigned int unk10b8;
    unsigned int unk10bc;
    unsigned int unk10c0;
    unsigned int unk10c4;
    unsigned int unk10c8;
    unsigned int unk10cc;
    unsigned int unk10d0;
    unsigned int unk10d4;
    unsigned int unk10d8;
    unsigned int unk10dc;
    unsigned int unk10e0;
    unsigned int unk10e4;
    unsigned int unk10e8;
    unsigned int unk10ec;
    unsigned int unk10f0;
    unsigned int unk10f4;
    unsigned int unk10f8;
    unsigned int unk10fc;
    unsigned int unk1100;
    unsigned int unk1104;
    unsigned int unk1108;
    unsigned int unk110c;
    unsigned int unk1110;
    unsigned int unk1114;
    unsigned int unk1118;
    unsigned int unk111c;
    unsigned int unk1120;
    unsigned int unk1124;
    unsigned int unk1128;
    unsigned int unk112c;
    unsigned int unk1130;
    unsigned int unk1134;
    unsigned int unk1138;
    unsigned int unk113c;
    unsigned int unk1140;
    unsigned int unk1144;
    unsigned int unk1148;
    unsigned int unk114c;
    unsigned int unk1150;
    unsigned int unk1154;
    unsigned int unk1158;
    unsigned int unk115c;
    unsigned int unk1160;
    unsigned int unk1164;
    unsigned int unk1168;
    unsigned int unk116c;
    unsigned int unk1170;
    unsigned int unk1174;
    unsigned int unk1178;
    unsigned int unk117c;
    unsigned int unk1180;
    unsigned int unk1184;
    unsigned int unk1188;
    unsigned int unk118c;
    unsigned int unk1190;
    unsigned int unk1194;
    unsigned int unk1198;
    unsigned int unk119c;
    unsigned int unk11a0;
    unsigned int unk11a4;
    unsigned int unk11a8;
    unsigned int unk11ac;
    unsigned int unk11b0;
    unsigned int unk11b4;
    unsigned int unk11b8;
    unsigned int unk11bc;
    unsigned int unk11c0;
    unsigned int unk11c4;
    unsigned int unk11c8;
    unsigned int unk11cc;
    unsigned int unk11d0;
    unsigned int unk11d4;
    unsigned int unk11d8;
    unsigned int unk11dc;
    unsigned int unk11e0;
    unsigned int unk11e4;
    unsigned int unk11e8;
    unsigned int unk11ec;
    unsigned int unk11f0;
    unsigned int unk11f4;
    unsigned int unk11f8;
    unsigned int unk11fc;
    unsigned int unk1200;
    unsigned int unk1204;
    unsigned int unk1208;
    unsigned int unk120c;
    unsigned int unk1210;
    unsigned int unk1214;
    unsigned int unk1218;
    unsigned int unk121c;
    unsigned int unk1220;
    unsigned int unk1224;
    unsigned int unk1228;
    unsigned int unk122c;
    unsigned int unk1230;
    unsigned int unk1234;
    unsigned int unk1238;
    unsigned int unk123c;
    unsigned int unk1240;
    unsigned int unk1244;
    unsigned int unk1248;
    unsigned int unk124c;
    unsigned int unk1250;
    unsigned int unk1254;
    unsigned int unk1258;
    unsigned int unk125c;
    unsigned int unk1260;
    unsigned int unk1264;
    unsigned int unk1268;
    unsigned int unk126c;
    unsigned int unk1270;
    unsigned int unk1274;
    unsigned int unk1278;
    unsigned int unk127c;
    unsigned int unk1280;
    unsigned int unk1284;
    unsigned int unk1288;
    unsigned int unk128c;
    unsigned int unk1290;
    unsigned int unk1294;
    unsigned int unk1298;
    unsigned int unk129c;
    unsigned int unk12a0;
    unsigned int unk12a4;
    unsigned int unk12a8;
    unsigned int unk12ac;
    unsigned int unk12b0;
    unsigned int unk12b4;
    unsigned int unk12b8;
    unsigned int unk12bc;
    unsigned int unk12c0;
    unsigned int unk12c4;
    unsigned int unk12c8;
    unsigned int unk12cc;
    unsigned int unk12d0;
    unsigned int unk12d4;
    unsigned int unk12d8;
    unsigned int unk12dc;
    unsigned int unk12e0;
    unsigned int unk12e4;
    unsigned int unk12e8;
    unsigned int unk12ec;
    unsigned int unk12f0;
    unsigned int unk12f4;
    unsigned int unk12f8;
    unsigned int unk12fc;
    unsigned int unk1300;
    unsigned int unk1304;
    unsigned int unk1308;
    unsigned int unk130c;
    unsigned int unk1310;
    unsigned int unk1314;
    unsigned int unk1318;
    unsigned int unk131c;
    unsigned int unk1320;
    unsigned int unk1324;
    unsigned int unk1328;
    unsigned int unk132c;
    unsigned int unk1330;
    unsigned int unk1334;
    unsigned int unk1338;
    unsigned int unk133c;
    unsigned int unk1340;
    unsigned int unk1344;
    unsigned int unk1348;
    unsigned int unk134c;
    unsigned int unk1350;
    unsigned int unk1354;
    unsigned int unk1358;
    unsigned int unk135c;
    unsigned int unk1360;
    unsigned int unk1364;
    unsigned int unk1368;
    unsigned int unk136c;
    unsigned int unk1370;
    unsigned int unk1374;
    unsigned int unk1378;
    unsigned int unk137c;
    unsigned int unk1380;
    unsigned int unk1384;
    unsigned int unk1388;
    unsigned int unk138c;
    unsigned int unk1390;
    unsigned int unk1394;
    unsigned int unk1398;
    unsigned int unk139c;
    unsigned int unk13a0;
    unsigned int unk13a4;
    unsigned int unk13a8;
    unsigned int unk13ac;
    unsigned int unk13b0;
    unsigned int unk13b4;
    unsigned int unk13b8;
    unsigned int unk13bc;
    unsigned int unk13c0;
    unsigned int unk13c4;
    unsigned int unk13c8;
    unsigned int unk13cc;
    unsigned int unk13d0;
    unsigned int unk13d4;
    unsigned int unk13d8;
    unsigned int unk13dc;
    unsigned int unk13e0;
    unsigned int unk13e4;
    unsigned int unk13e8;
    unsigned int unk13ec;
    unsigned int unk13f0;
    unsigned int unk13f4;
    unsigned int unk13f8;
    unsigned int unk13fc;
    unsigned int unk1400;
    unsigned int unk1404;
    unsigned int unk1408;
    unsigned int unk140c;
    unsigned int unk1410;
    unsigned int unk1414;
    unsigned int unk1418;
    unsigned int unk141c;
    unsigned int unk1420;
    unsigned int unk1424;
    unsigned int unk1428;
    unsigned int unk142c;
    unsigned int unk1430;
    unsigned int unk1434;
    unsigned int unk1438;
    unsigned int unk143c;
    unsigned int unk1440;
    unsigned int unk1444;
    unsigned int unk1448;
    unsigned int unk144c;
    unsigned int unk1450;
    unsigned int unk1454;
    unsigned int unk1458;
    unsigned int unk145c;
    unsigned int unk1460;
    unsigned int unk1464;
    unsigned int unk1468;
    unsigned int unk146c;
    unsigned int unk1470;
    unsigned int unk1474;
    unsigned int unk1478;
    unsigned int unk147c;
    unsigned int unk1480;
    unsigned int unk1484;
    unsigned int unk1488;
    unsigned int unk148c;
    unsigned int unk1490;
    unsigned int unk1494;
    unsigned int unk1498;
    unsigned int unk149c;
    unsigned int unk14a0;
    unsigned int unk14a4;
    unsigned int unk14a8;
    unsigned int unk14ac;
    unsigned int unk14b0;
    unsigned int unk14b4;
    unsigned int unk14b8;
    unsigned int unk14bc;
    unsigned int unk14c0;
    unsigned int unk14c4;
    unsigned int unk14c8;
    unsigned int unk14cc;
    unsigned int unk14d0;
    unsigned int unk14d4;
    unsigned int unk14d8;
    unsigned int unk14dc;
    unsigned int unk14e0;
    unsigned int unk14e4;
    unsigned int unk14e8;
    unsigned int unk14ec;
    unsigned int unk14f0;
    unsigned int unk14f4;
    unsigned int unk14f8;
    unsigned int unk14fc;
    unsigned int unk1500;
    unsigned int unk1504;
    unsigned int unk1508;
    unsigned int unk150c;
    unsigned int unk1510;
    unsigned int unk1514;
    unsigned int unk1518;
    unsigned int unk151c;
    unsigned int unk1520;
    unsigned int unk1524;
    unsigned int unk1528;
    unsigned int unk152c;
    unsigned int unk1530;
    unsigned int unk1534;
    unsigned int unk1538;
    unsigned int unk153c;
    unsigned int unk1540;
    unsigned int unk1544;
    unsigned int unk1548;
    unsigned int unk154c;
    unsigned int unk1550;
    unsigned int unk1554;
    unsigned int unk1558;
    unsigned int unk155c;
    unsigned int unk1560;
    unsigned int unk1564;
    unsigned int unk1568;
    unsigned int unk156c;
    unsigned int unk1570;
    unsigned int unk1574;
    unsigned int unk1578;
    unsigned int unk157c;
    unsigned int unk1580;
    unsigned int unk1584;
    unsigned int unk1588;
    unsigned int unk158c;
    unsigned int unk1590;
    unsigned int unk1594;
    unsigned int unk1598;
    unsigned int unk159c;
    unsigned int unk15a0;
    unsigned int unk15a4;
    unsigned int unk15a8;
    unsigned int unk15ac;
    unsigned int unk15b0;
    unsigned int unk15b4;
    unsigned int unk15b8;
    unsigned int unk15bc;
    unsigned int unk15c0;
    unsigned int unk15c4;
    unsigned int unk15c8;
    unsigned int unk15cc;
    unsigned int unk15d0;
    unsigned int unk15d4;
    unsigned int unk15d8;
    unsigned int unk15dc;
    unsigned int unk15e0;
    unsigned int unk15e4;
    unsigned int unk15e8;
    unsigned int unk15ec;
    unsigned int unk15f0;
    unsigned int unk15f4;
    unsigned int unk15f8;
    unsigned int unk15fc;
    unsigned int unk1600;
    unsigned int unk1604;
    unsigned int unk1608;
    unsigned int unk160c;
    unsigned int unk1610;
    unsigned int unk1614;
    unsigned int unk1618;
    unsigned int unk161c;
    unsigned int unk1620;
    unsigned int unk1624;
    unsigned int unk1628;
    unsigned int unk162c;
    unsigned int unk1630;
    unsigned int unk1634;
    unsigned int unk1638;
    unsigned int unk163c;
    unsigned int unk1640;
    unsigned int unk1644;
    unsigned int unk1648;
    unsigned int unk164c;
    unsigned int unk1650;
    unsigned int unk1654;
    unsigned int unk1658;
    unsigned int unk165c;
    unsigned int unk1660;
    unsigned int unk1664;
    unsigned int unk1668;
    unsigned int unk166c;
    unsigned int unk1670;
    unsigned int unk1674;
    unsigned int unk1678;
    unsigned int unk167c;
    unsigned int unk1680;
    unsigned int unk1684;
    unsigned int unk1688;
    unsigned int unk168c;
    unsigned int unk1690;
    unsigned int unk1694;
    unsigned int unk1698;
    unsigned int unk169c;
    unsigned int unk16a0;
    unsigned int unk16a4;
    unsigned int unk16a8;
    unsigned int unk16ac;
    unsigned int unk16b0;
    unsigned int unk16b4;
    unsigned int unk16b8;
    unsigned int unk16bc;
    unsigned int unk16c0;
    unsigned int unk16c4;
    unsigned int unk16c8;
    unsigned int unk16cc;
    unsigned int unk16d0;
    unsigned int unk16d4;
    unsigned int unk16d8;
    unsigned int unk16dc;
    unsigned int unk16e0;
    unsigned int unk16e4;
    unsigned int unk16e8;
    unsigned int unk16ec;
    unsigned int unk16f0;
    unsigned int unk16f4;
    unsigned int unk16f8;
    unsigned int unk16fc;
    unsigned int unk1700;
    unsigned int unk1704;
    unsigned int unk1708;
    unsigned int unk170c;
    unsigned int unk1710;
    unsigned int unk1714;
    unsigned int unk1718;
    unsigned int unk171c;
    unsigned int unk1720;
    unsigned int unk1724;
    unsigned int unk1728;
    unsigned int unk172c;
    unsigned int unk1730;
    unsigned int unk1734;
    unsigned int unk1738;
    unsigned int unk173c;
    unsigned int unk1740;
    unsigned int unk1744;
    unsigned int unk1748;
    unsigned int unk174c;
    unsigned int unk1750;
    unsigned int unk1754;
    unsigned int unk1758;
    unsigned int unk175c;
    unsigned int unk1760;
    unsigned int unk1764;
    unsigned int unk1768;
    unsigned int unk176c;
    unsigned int unk1770;
    unsigned int unk1774;
    unsigned int unk1778;
    unsigned int unk177c;
    unsigned int unk1780;
    unsigned int unk1784;
    unsigned int unk1788;
    unsigned int unk178c;
    unsigned int unk1790;
    unsigned int unk1794;
    unsigned int unk1798;
    unsigned int unk179c;
    unsigned int unk17a0;
    unsigned int unk17a4;
    unsigned int unk17a8;
    unsigned int unk17ac;
    unsigned int unk17b0;
    unsigned int unk17b4;
    unsigned int unk17b8;
    unsigned int unk17bc;
    unsigned int unk17c0;
    unsigned int unk17c4;
    unsigned int unk17c8;
    unsigned int unk17cc;
    unsigned int unk17d0;
    unsigned int unk17d4;
    unsigned int unk17d8;
    unsigned int unk17dc;
    unsigned int unk17e0;
    unsigned int unk17e4;
    unsigned int unk17e8;
    unsigned int unk17ec;
    unsigned int unk17f0;
    unsigned int unk17f4;
    unsigned int unk17f8;
    unsigned int unk17fc;
    unsigned int unk1800;
    unsigned int unk1804;
    unsigned int unk1808;
    unsigned int unk180c;
    unsigned int unk1810;
    unsigned int unk1814;
    unsigned int unk1818;
    unsigned int unk181c;
    unsigned int unk1820;
    unsigned int unk1824;
    unsigned int unk1828;
    unsigned int unk182c;
    unsigned int unk1830;
    unsigned int unk1834;
    unsigned int unk1838;
    unsigned int unk183c;
    unsigned int unk1840;
    unsigned int unk1844;
    unsigned int unk1848;
    unsigned int unk184c;
    unsigned int unk1850;
    unsigned int unk1854;
    unsigned int unk1858;
    unsigned int unk185c;
    unsigned int unk1860;
    unsigned int unk1864;
    unsigned int unk1868;
    unsigned int unk186c;
    unsigned int unk1870;
    unsigned int unk1874;
    unsigned int unk1878;
    unsigned int unk187c;
    unsigned int unk1880;
    unsigned int unk1884;
    unsigned int unk1888;
    unsigned int unk188c;
    unsigned int unk1890;
    unsigned int unk1894;
    unsigned int unk1898;
    unsigned int unk189c;
    unsigned int unk18a0;
    unsigned int unk18a4;
    unsigned int unk18a8;
    unsigned int unk18ac;
    unsigned int unk18b0;
    unsigned int unk18b4;
    unsigned int unk18b8;
    unsigned int unk18bc;
    unsigned int unk18c0;
    unsigned int unk18c4;
    unsigned int unk18c8;
    unsigned int unk18cc;
    unsigned int unk18d0;
    unsigned int unk18d4;
    unsigned int unk18d8;
    unsigned int unk18dc;
    unsigned int unk18e0;
    unsigned int unk18e4;
    unsigned int unk18e8;
    unsigned int unk18ec;
    unsigned int unk18f0;
    unsigned int unk18f4;
    unsigned int unk18f8;
    unsigned int unk18fc;
    unsigned int unk1900;
    unsigned int unk1904;
    unsigned int unk1908;
    unsigned int unk190c;
    unsigned int unk1910;
    unsigned int unk1914;
    unsigned int unk1918;
    unsigned int unk191c;
    unsigned int unk1920;
    unsigned int unk1924;
    unsigned int unk1928;
    unsigned int unk192c;
    unsigned int unk1930;
    unsigned int unk1934;
    unsigned int unk1938;
    unsigned int unk193c;
    unsigned int unk1940;
    unsigned int unk1944;
    unsigned int unk1948;
    unsigned int unk194c;
    unsigned int unk1950;
    unsigned int unk1954;
    unsigned int unk1958;
    unsigned int unk195c;
    unsigned int unk1960;
    unsigned int unk1964;
    unsigned int unk1968;
    unsigned int unk196c;
    unsigned int unk1970;
    unsigned int unk1974;
    unsigned int unk1978;
    unsigned int unk197c;
    unsigned int unk1980;
    unsigned int unk1984;
    unsigned int unk1988;
    unsigned int unk198c;
    unsigned int unk1990;
    unsigned int unk1994;
    unsigned int unk1998;
    unsigned int unk199c;
    unsigned int unk19a0;
    unsigned int unk19a4;
    unsigned int unk19a8;
    unsigned int unk19ac;
    unsigned int unk19b0;
    unsigned int unk19b4;
    unsigned int unk19b8;
    unsigned int unk19bc;
    unsigned int unk19c0;
    unsigned int unk19c4;
    unsigned int unk19c8;
    unsigned int unk19cc;
    unsigned int unk19d0;
    unsigned int unk19d4;
    unsigned int unk19d8;
    unsigned int unk19dc;
    unsigned int unk19e0;
    unsigned int unk19e4;
    unsigned int unk19e8;
    unsigned int unk19ec;
    unsigned int unk19f0;
    unsigned int unk19f4;
    unsigned int unk19f8;
    unsigned int unk19fc;
    unsigned int unk1a00;
    unsigned int unk1a04;
    unsigned int unk1a08;
    unsigned int unk1a0c;
    unsigned int unk1a10;
    unsigned int unk1a14;
    unsigned int unk1a18;
    unsigned int unk1a1c;
    unsigned int unk1a20;
    unsigned int unk1a24;
    unsigned int unk1a28;
    unsigned int unk1a2c;
    unsigned int unk1a30;
    unsigned int unk1a34;
    unsigned int unk1a38;
    unsigned int unk1a3c;
    unsigned int unk1a40;
    unsigned int unk1a44;
    unsigned int unk1a48;
    unsigned int unk1a4c;
    unsigned int unk1a50;
    unsigned int unk1a54;
    unsigned int unk1a58;
    unsigned int unk1a5c;
    unsigned int unk1a60;
    unsigned int unk1a64;
    unsigned int unk1a68;
    unsigned int unk1a6c;
    unsigned int unk1a70;
    unsigned int unk1a74;
    unsigned int unk1a78;
    unsigned int unk1a7c;
    unsigned int unk1a80;
    unsigned int unk1a84;
    unsigned int unk1a88;
    unsigned int unk1a8c;
    unsigned int unk1a90;
    unsigned int unk1a94;
    unsigned int unk1a98;
    unsigned int unk1a9c;
    unsigned int unk1aa0;
    unsigned int unk1aa4;
    unsigned int unk1aa8;
    unsigned int unk1aac;
    unsigned int unk1ab0;
    unsigned int unk1ab4;
    unsigned int unk1ab8;
    unsigned int unk1abc;
    unsigned int unk1ac0;
    unsigned int unk1ac4;
    unsigned int unk1ac8;
    unsigned int unk1acc;
    unsigned int unk1ad0;
    unsigned int unk1ad4;
    unsigned int unk1ad8;
    unsigned int unk1adc;
    unsigned int unk1ae0;
    unsigned int unk1ae4;
    unsigned int unk1ae8;
    unsigned int unk1aec;
    unsigned int unk1af0;
    unsigned int unk1af4;
    unsigned int unk1af8;
    unsigned int unk1afc;
    unsigned int unk1b00;
    unsigned int unk1b04;
    unsigned int unk1b08;
    unsigned int unk1b0c;
    unsigned int unk1b10;
    unsigned int unk1b14;
    unsigned int unk1b18;
    unsigned int unk1b1c;
    unsigned int unk1b20;
    unsigned int unk1b24;
    unsigned int unk1b28;
    unsigned int unk1b2c;
    unsigned int unk1b30;
    unsigned int unk1b34;
    unsigned int unk1b38;
    unsigned int unk1b3c;
    unsigned int unk1b40;
    unsigned int unk1b44;
    unsigned int unk1b48;
    unsigned int unk1b4c;
    unsigned int unk1b50;
    unsigned int unk1b54;
    unsigned int unk1b58;
    unsigned int unk1b5c;
    unsigned int unk1b60;
    unsigned int unk1b64;
    unsigned int unk1b68;
    unsigned int unk1b6c;
    unsigned int unk1b70;
    unsigned int unk1b74;
    unsigned int unk1b78;
    unsigned int unk1b7c;
    unsigned int unk1b80;
    unsigned int unk1b84;
    unsigned int unk1b88;
    unsigned int unk1b8c;
    unsigned int unk1b90;
    unsigned int unk1b94;
    unsigned int unk1b98;
    unsigned int unk1b9c;
    unsigned int unk1ba0;
    unsigned int unk1ba4;
    unsigned int unk1ba8;
    unsigned int unk1bac;
    unsigned int unk1bb0;
    unsigned int unk1bb4;
    unsigned int unk1bb8;
    unsigned int unk1bbc;
    unsigned int unk1bc0;
    unsigned int unk1bc4;
    unsigned int unk1bc8;
    unsigned int unk1bcc;
    unsigned int unk1bd0;
    unsigned int unk1bd4;
    unsigned int unk1bd8;
    unsigned int unk1bdc;
    unsigned int unk1be0;
    unsigned int unk1be4;
    unsigned int unk1be8;
    unsigned int unk1bec;
    unsigned int unk1bf0;
    unsigned int unk1bf4;
    unsigned int unk1bf8;
    unsigned int unk1bfc;
    unsigned int unk1c00;
    unsigned int unk1c04;
    unsigned int unk1c08;
    unsigned int unk1c0c;
    unsigned int unk1c10;
    unsigned int unk1c14;
    unsigned int unk1c18;
    unsigned int unk1c1c;
    unsigned int unk1c20;
    unsigned int unk1c24;
    unsigned int unk1c28;
    unsigned int unk1c2c;
    unsigned int unk1c30;
    unsigned int unk1c34;
    unsigned int unk1c38;
    unsigned int unk1c3c;
    unsigned int unk1c40;
    unsigned int unk1c44;
    unsigned int unk1c48;
    unsigned int unk1c4c;
    unsigned int unk1c50;
    unsigned int unk1c54;
    unsigned int unk1c58;
    unsigned int unk1c5c;
    unsigned int unk1c60;
    unsigned int unk1c64;
    unsigned int unk1c68;
    unsigned int unk1c6c;
    unsigned int unk1c70;
    unsigned int unk1c74;
    unsigned int unk1c78;
    unsigned int unk1c7c;
    unsigned int unk1c80;
    unsigned int unk1c84;
    unsigned int unk1c88;
    unsigned int unk1c8c;
    unsigned int unk1c90;
    unsigned int unk1c94;
    unsigned int unk1c98;
    unsigned int unk1c9c;
    unsigned int unk1ca0;
    unsigned int unk1ca4;
    unsigned int unk1ca8;
    unsigned int unk1cac;
    unsigned int unk1cb0;
    unsigned int unk1cb4;
    unsigned int unk1cb8;
    unsigned int unk1cbc;
    unsigned int unk1cc0;
    unsigned int unk1cc4;
    unsigned int unk1cc8;
    unsigned int unk1ccc;
    unsigned int unk1cd0;
    unsigned int unk1cd4;
    unsigned int unk1cd8;
    unsigned int unk1cdc;
    unsigned int unk1ce0;
    unsigned int unk1ce4;
    unsigned int unk1ce8;
    unsigned int unk1cec;
    unsigned int unk1cf0;
    unsigned int unk1cf4;
    unsigned int unk1cf8;
    unsigned int unk1cfc;
    unsigned int unk1d00;
    unsigned int unk1d04;
    unsigned int unk1d08;
    unsigned int unk1d0c;
    unsigned int unk1d10;
    unsigned int unk1d14;
    unsigned int unk1d18;
    unsigned int unk1d1c;
    unsigned int unk1d20;
    unsigned int unk1d24;
    unsigned int unk1d28;
    unsigned int unk1d2c;
    unsigned int unk1d30;
    unsigned int unk1d34;
    unsigned int unk1d38;
    unsigned int unk1d3c;
    unsigned int unk1d40;
    unsigned int unk1d44;
    unsigned int unk1d48;
    unsigned int unk1d4c;
    unsigned int unk1d50;
    unsigned int unk1d54;
    unsigned int unk1d58;
    unsigned int unk1d5c;
    unsigned int unk1d60;
    unsigned int unk1d64;
    unsigned int unk1d68;
    unsigned int unk1d6c;
    unsigned int unk1d70;
    unsigned int unk1d74;
    unsigned int unk1d78;
    unsigned int unk1d7c;
    unsigned int unk1d80;
    unsigned int unk1d84;
    unsigned int unk1d88;
    unsigned int unk1d8c;
    unsigned int unk1d90;
    unsigned int unk1d94;
    unsigned int unk1d98;
    unsigned int unk1d9c;
    unsigned int unk1da0;
    unsigned int unk1da4;
    unsigned int unk1da8;
    unsigned int unk1dac;
    unsigned int unk1db0;
    unsigned int unk1db4;
    unsigned int unk1db8;
    unsigned int unk1dbc;
    unsigned int unk1dc0;
    unsigned int unk1dc4;
    unsigned int unk1dc8;
    unsigned int unk1dcc;
    unsigned int unk1dd0;
    unsigned int unk1dd4;
    unsigned int unk1dd8;
    unsigned int unk1ddc;
    unsigned int unk1de0;
    unsigned int unk1de4;
    unsigned int unk1de8;
    unsigned int unk1dec;
    unsigned int unk1df0;
    unsigned int unk1df4;
    unsigned int unk1df8;
    unsigned int unk1dfc;
    unsigned int unk1e00;
    unsigned int unk1e04;
    unsigned int unk1e08;
    unsigned int unk1e0c;
    unsigned int unk1e10;
    unsigned int unk1e14;
    unsigned int unk1e18;
    unsigned int unk1e1c;
    unsigned int unk1e20;
    unsigned int unk1e24;
    unsigned int unk1e28;
    unsigned int unk1e2c;
    unsigned int unk1e30;
    unsigned int unk1e34;
    unsigned int unk1e38;
    unsigned int unk1e3c;
    unsigned int unk1e40;
    unsigned int unk1e44;
    unsigned int unk1e48;
    unsigned int unk1e4c;
    unsigned int unk1e50;
    unsigned int unk1e54;
    unsigned int unk1e58;
    unsigned int unk1e5c;
    unsigned int unk1e60;
    unsigned int unk1e64;
    unsigned int unk1e68;
    unsigned int unk1e6c;
    unsigned int unk1e70;
    unsigned int unk1e74;
    unsigned int unk1e78;
    unsigned int unk1e7c;
    unsigned int unk1e80;
    unsigned int unk1e84;
    unsigned int unk1e88;
    unsigned int unk1e8c;
    unsigned int unk1e90;
    unsigned int unk1e94;
    unsigned int unk1e98;
    unsigned int unk1e9c;
    unsigned int unk1ea0;
    unsigned int unk1ea4;
    unsigned int unk1ea8;
    unsigned int unk1eac;
    unsigned int unk1eb0;
    unsigned int unk1eb4;
    unsigned int unk1eb8;
    unsigned int unk1ebc;
    unsigned int unk1ec0;
    unsigned int unk1ec4;
    unsigned int unk1ec8;
    unsigned int unk1ecc;
    unsigned int unk1ed0;
    unsigned int unk1ed4;
    unsigned int unk1ed8;
    unsigned int unk1edc;
    unsigned int unk1ee0;
    unsigned int unk1ee4;
    unsigned int unk1ee8;
    unsigned int unk1eec;
    unsigned int unk1ef0;
    unsigned int unk1ef4;
    unsigned int unk1ef8;
    unsigned int unk1efc;
    unsigned int unk1f00;
    unsigned int unk1f04;
    unsigned int unk1f08;
    unsigned int unk1f0c;
    unsigned int unk1f10;
    unsigned int unk1f14;
    unsigned int unk1f18;
    unsigned int unk1f1c;
    unsigned int unk1f20;
    unsigned int unk1f24;
    unsigned int unk1f28;
    unsigned int unk1f2c;
    unsigned int unk1f30;
    unsigned int unk1f34;
    unsigned int unk1f38;
    unsigned int unk1f3c;
    unsigned int unk1f40;
    unsigned int unk1f44;
    unsigned int unk1f48;
    unsigned int unk1f4c;
    unsigned int unk1f50;
    unsigned int unk1f54;
    unsigned int unk1f58;
    unsigned int unk1f5c;
    unsigned int unk1f60;
    unsigned int unk1f64;
    unsigned int unk1f68;
    unsigned int unk1f6c;
    unsigned int unk1f70;
    unsigned int unk1f74;
    unsigned int unk1f78;
    unsigned int unk1f7c;
    unsigned int unk1f80;
    unsigned int unk1f84;
    unsigned int unk1f88;
    unsigned int unk1f8c;
    unsigned int unk1f90;
    unsigned int unk1f94;
    unsigned int unk1f98;
    unsigned int unk1f9c;
    unsigned int unk1fa0;
    unsigned int unk1fa4;
    unsigned int unk1fa8;
    unsigned int unk1fac;
    unsigned int unk1fb0;
    unsigned int unk1fb4;
    unsigned int unk1fb8;
    unsigned int unk1fbc;
    unsigned int unk1fc0;
    unsigned int unk1fc4;
    unsigned int unk1fc8;
    unsigned int unk1fcc;
    unsigned int unk1fd0;
    unsigned int unk1fd4;
    unsigned int unk1fd8;
    unsigned int unk1fdc;
    unsigned int unk1fe0;
    unsigned int unk1fe4;
    unsigned int unk1fe8;
    unsigned int unk1fec;
    unsigned int unk1ff0;
    unsigned int unk1ff4;
    unsigned int unk1ff8;
    unsigned int unk1ffc;
    unsigned int unk2000;
    unsigned int unk2004;
    unsigned int unk2008;
    unsigned int unk200c;
    unsigned int unk2010;
    unsigned int unk2014;
    unsigned int unk2018;
    unsigned int unk201c;
    unsigned int unk2020;
    unsigned int unk2024;
    unsigned int unk2028;
    unsigned int unk202c;
    unsigned int unk2030;
    unsigned int unk2034;
    unsigned int unk2038;
    unsigned int unk203c;
    unsigned int unk2040;
    unsigned int unk2044;
    unsigned int unk2048;
    unsigned int unk204c;
    unsigned int unk2050;
    unsigned int unk2054;
    unsigned int unk2058;
    unsigned int unk205c;
    unsigned int unk2060;
    unsigned int unk2064;
    unsigned int unk2068;
    unsigned int unk206c;
    unsigned int unk2070;
    unsigned int unk2074;
    unsigned int unk2078;
    unsigned int unk207c;
    unsigned int unk2080;
    unsigned int unk2084;
    unsigned int unk2088;
    unsigned int unk208c;
    unsigned int unk2090;
    unsigned int unk2094;
    unsigned int unk2098;
    unsigned int unk209c;
    unsigned int unk20a0;
    unsigned int unk20a4;
    unsigned int unk20a8;
    unsigned int unk20ac;
    unsigned int unk20b0;
    unsigned int unk20b4;
    unsigned int unk20b8;
    unsigned int unk20bc;
    unsigned int unk20c0;
    unsigned int unk20c4;
    unsigned int unk20c8;
    unsigned int unk20cc;
    unsigned int unk20d0;
    unsigned int unk20d4;
    P048Hide();
    ~P048Hide();
};
struct P048Solution
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int current, last;
};
struct P048Final
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
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    P048Final();
    ~P048Final();
};
struct P048Unused
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    P048Unused(int, int, void*);
    ~P048Unused();
};
// Validates the request's path data, builds start/end nodes, seeds the solution with origin and goal points, and runs the path builder.
// @fnv 0x006d1c60
bool __cdecl FUN_006d1c60(P048Request* request, P048Solution* solution)
{
    AutoMemContext context4((MEM_CONTEXT)45, true,
                            "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\Pathfinding\\Pathfind.cpp", 501);
    if (!reinterpret_cast<::PathingLocationProxy *>((((::P048Location *)(::GetOffsetC((std::intptr_t)(request))))))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
        return false;
    NavMeshPtr mesh2;
    unsigned short triangle2 = 0xffff;
    if (!reinterpret_cast<::PathingLocation *>((((::P048Location *)(::GetOffsetC((std::intptr_t)(request))))))->FindNavMeshTriangle(mesh2, triangle2))
        return false;
    P048Node startTmp;
    startTmp.mesh = ((P048MeshPtr*)&mesh2)->Get();
    startTmp.triangle = triangle2;
    NiPoint3 origin6 = reinterpret_cast<::TaskQueueInterface *>((void *)(((::P048Location *)(::GetOffsetC((std::intptr_t)(request))))))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    P048Hide hide;
    P048Open open2(32, 0, 0);
    P048Closed closedB(32, 0, 0);
    if (!((bool)(reinterpret_cast<::HideSearchX *>(&(hide))->SetupActorTarget((::ActorX *)(request), (::TriRef20 *)(::P048Node *)(&startTmp), (::ParamX *)(::P048Open *)(&open2), (std::intptr_t)(&closedB)))))
        return false;
    P048Node end3 = *((::P048Node *)(reinterpret_cast<::FUN_006b3160_shell *>(&(open2))->FUN_006b3160(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(open2))->GetName())) - 1)));
    NiPoint3 goal_2;
    goal_2 = reinterpret_cast<::NavMesh *>((end3.mesh))->GetNavMeshData(end3.triangle);
    reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((solution))->AddPathingItem((void *)&(origin6), (::TESObjectREFR *)(reinterpret_cast<::FUN_0068efb0_shell *>((startTmp.mesh))->FUN_0068efb0()));
    reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((solution))->AddPathingItem((void *)&(goal_2), (::TESObjectREFR *)(reinterpret_cast<::FUN_0068efb0_shell *>((end3.mesh))->FUN_0068efb0()));
    solution->current = 0;
    solution->last = 1;
    P048Final builder;
    P048Unused scratch_2(32, 0, 0);
    reinterpret_cast<::FUN_006ed530_cls *>(&(builder))->FUN_006ed530((::NodeA *)(request), (::ArgObj *)(::P048Open *)(&open2), (::ArgObj *)(::P048Closed *)(&closedB), (::Triple *)(::NiPoint3 *)(&origin6), (::Triple *)(::NiPoint3 *)(&goal_2), (std::intptr_t)(solution), (::Gate *)(0), 1);
    solution->current = 0;
    solution->last = ::FUN_005a4320((char *)(solution)) - 1;
    return true;
}

namespace fnv_006d23d0 {
// Search containers reconstructed from their constructors and hash-table accesses.
struct SearchNode;
struct SearchAllocator
{
    void* vtable;
    void* heap;
    void* blocks;
    unsigned int blockSize;
};
struct ClosedSearchTable
{
    int unk0000, unk0001, unk0002, unk0003, unk0004, unk0005, unk0006, unk0007;
    int unk0008, unk0009, unk000a, unk000b, unk000c, unk000d, unk000e, unk000f;
    int unk0010, unk0011, unk0012, unk0013, unk0014, unk0015, unk0016, unk0017;
    int unk0018, unk0019, unk001a, unk001b, unk001c, unk001d, unk001e, unk001f;
    int unk0020, unk0021, unk0022, unk0023, unk0024, unk0025, unk0026, unk0027;
    int unk0028, unk0029, unk002a, unk002b, unk002c, unk002d, unk002e, unk002f;
    int unk0030, unk0031, unk0032, unk0033, unk0034, unk0035, unk0036, unk0037;
    int unk0038, unk0039, unk003a, unk003b, unk003c, unk003d, unk003e, unk003f;
    int unk0040, unk0041, unk0042, unk0043, unk0044, unk0045, unk0046, unk0047;
    int unk0048, unk0049, unk004a, unk004b, unk004c, unk004d, unk004e, unk004f;
    int unk0050, unk0051, unk0052, unk0053, unk0054, unk0055, unk0056, unk0057;
    int unk0058, unk0059, unk005a, unk005b, unk005c, unk005d, unk005e, unk005f;
    int unk0060, unk0061, unk0062, unk0063, unk0064, unk0065, unk0066, unk0067;
    int unk0068, unk0069, unk006a, unk006b, unk006c, unk006d, unk006e, unk006f;
    int unk0070, unk0071, unk0072, unk0073, unk0074, unk0075, unk0076, unk0077;
    int unk0078, unk0079, unk007a, unk007b, unk007c, unk007d, unk007e, unk007f;
    int unk0080, unk0081, unk0082, unk0083, unk0084, unk0085, unk0086, unk0087;
    int unk0088, unk0089, unk008a, unk008b, unk008c, unk008d, unk008e, unk008f;
    int unk0090, unk0091, unk0092, unk0093, unk0094, unk0095, unk0096, unk0097;
    int unk0098, unk0099, unk009a, unk009b, unk009c, unk009d, unk009e, unk009f;
    int unk00a0, unk00a1, unk00a2, unk00a3, unk00a4, unk00a5, unk00a6, unk00a7;
    int unk00a8, unk00a9, unk00aa, unk00ab, unk00ac, unk00ad, unk00ae, unk00af;
    int unk00b0, unk00b1, unk00b2, unk00b3, unk00b4, unk00b5, unk00b6, unk00b7;
    int unk00b8, unk00b9, unk00ba, unk00bb, unk00bc, unk00bd, unk00be, unk00bf;
    int unk00c0, unk00c1, unk00c2, unk00c3, unk00c4, unk00c5, unk00c6, unk00c7;
    int unk00c8, unk00c9, unk00ca, unk00cb, unk00cc, unk00cd, unk00ce, unk00cf;
    int unk00d0, unk00d1, unk00d2, unk00d3, unk00d4, unk00d5, unk00d6, unk00d7;
    int unk00d8, unk00d9, unk00da, unk00db, unk00dc, unk00dd, unk00de, unk00df;
    int unk00e0, unk00e1, unk00e2, unk00e3, unk00e4, unk00e5, unk00e6, unk00e7;
    int unk00e8, unk00e9, unk00ea, unk00eb, unk00ec, unk00ed, unk00ee, unk00ef;
    int unk00f0, unk00f1, unk00f2, unk00f3, unk00f4, unk00f5, unk00f6, unk00f7;
    int unk00f8, unk00f9, unk00fa, unk00fb, unk00fc, unk00fd, unk00fe, unk00ff;
    int unk0100, unk0101, unk0102, unk0103, unk0104, unk0105, unk0106, unk0107;
    int unk0108, unk0109, unk010a, unk010b, unk010c, unk010d, unk010e, unk010f;
    int unk0110, unk0111, unk0112, unk0113, unk0114, unk0115, unk0116, unk0117;
    int unk0118, unk0119, unk011a, unk011b, unk011c, unk011d, unk011e, unk011f;
    int unk0120, unk0121, unk0122, unk0123, unk0124, unk0125, unk0126, unk0127;
    int unk0128, unk0129, unk012a, unk012b, unk012c, unk012d, unk012e, unk012f;
    int unk0130, unk0131, unk0132, unk0133, unk0134, unk0135, unk0136, unk0137;
    int unk0138, unk0139, unk013a, unk013b, unk013c, unk013d, unk013e, unk013f;
    int unk0140, unk0141, unk0142, unk0143, unk0144, unk0145, unk0146, unk0147;
    int unk0148, unk0149, unk014a, unk014b, unk014c, unk014d, unk014e, unk014f;
    int unk0150, unk0151, unk0152, unk0153, unk0154, unk0155, unk0156, unk0157;
    int unk0158, unk0159, unk015a, unk015b, unk015c, unk015d, unk015e, unk015f;
    int unk0160, unk0161, unk0162, unk0163, unk0164, unk0165, unk0166, unk0167;
    int unk0168, unk0169, unk016a, unk016b, unk016c, unk016d, unk016e, unk016f;
    int unk0170, unk0171, unk0172, unk0173, unk0174, unk0175, unk0176, unk0177;
    int unk0178, unk0179, unk017a, unk017b, unk017c, unk017d, unk017e, unk017f;
    int unk0180, unk0181, unk0182, unk0183, unk0184, unk0185, unk0186, unk0187;
    int unk0188, unk0189, unk018a, unk018b, unk018c, unk018d, unk018e, unk018f;
    int unk0190, unk0191, unk0192, unk0193, unk0194, unk0195, unk0196, unk0197;
    int unk0198, unk0199, unk019a, unk019b, unk019c, unk019d, unk019e, unk019f;
    int unk01a0, unk01a1, unk01a2, unk01a3, unk01a4, unk01a5, unk01a6, unk01a7;
    int unk01a8, unk01a9, unk01aa, unk01ab, unk01ac, unk01ad, unk01ae, unk01af;
    int unk01b0, unk01b1, unk01b2, unk01b3, unk01b4, unk01b5, unk01b6, unk01b7;
    int unk01b8, unk01b9, unk01ba, unk01bb, unk01bc, unk01bd, unk01be, unk01bf;
    int unk01c0, unk01c1, unk01c2, unk01c3, unk01c4, unk01c5, unk01c6, unk01c7;
    int unk01c8, unk01c9, unk01ca, unk01cb, unk01cc, unk01cd, unk01ce, unk01cf;
    int unk01d0, unk01d1, unk01d2, unk01d3, unk01d4, unk01d5, unk01d6, unk01d7;
    int unk01d8, unk01d9, unk01da, unk01db, unk01dc, unk01dd, unk01de, unk01df;
    int unk01e0, unk01e1, unk01e2, unk01e3, unk01e4, unk01e5, unk01e6, unk01e7;
    int unk01e8, unk01e9, unk01ea, unk01eb, unk01ec, unk01ed, unk01ee, unk01ef;
    int unk01f0, unk01f1, unk01f2, unk01f3, unk01f4, unk01f5, unk01f6, unk01f7;
    int unk01f8, unk01f9, unk01fa, unk01fb, unk01fc, unk01fd, unk01fe, unk01ff;
    int unk0200, unk0201, unk0202, unk0203, unk0204, unk0205, unk0206, unk0207;
    int unk0208, unk0209, unk020a, unk020b, unk020c, unk020d, unk020e, unk020f;
    int unk0210, unk0211, unk0212, unk0213, unk0214, unk0215, unk0216, unk0217;
    int unk0218, unk0219, unk021a, unk021b, unk021c, unk021d, unk021e, unk021f;
    int unk0220, unk0221, unk0222, unk0223, unk0224, unk0225, unk0226, unk0227;
    int unk0228, unk0229, unk022a, unk022b, unk022c, unk022d, unk022e, unk022f;
    int unk0230, unk0231, unk0232, unk0233, unk0234, unk0235, unk0236, unk0237;
    int unk0238, unk0239, unk023a, unk023b, unk023c, unk023d, unk023e, unk023f;
    int unk0240, unk0241, unk0242, unk0243, unk0244, unk0245, unk0246, unk0247;
    int unk0248, unk0249, unk024a, unk024b, unk024c, unk024d, unk024e, unk024f;
    int unk0250, unk0251, unk0252, unk0253, unk0254, unk0255, unk0256, unk0257;
    int unk0258, unk0259, unk025a, unk025b, unk025c, unk025d, unk025e, unk025f;
    int unk0260, unk0261, unk0262, unk0263, unk0264, unk0265, unk0266, unk0267;
    int unk0268, unk0269, unk026a, unk026b, unk026c, unk026d, unk026e, unk026f;
    int unk0270, unk0271, unk0272, unk0273, unk0274, unk0275, unk0276, unk0277;
    int unk0278, unk0279, unk027a, unk027b, unk027c, unk027d, unk027e, unk027f;
    int unk0280, unk0281, unk0282, unk0283, unk0284, unk0285, unk0286, unk0287;
    int unk0288, unk0289, unk028a, unk028b, unk028c, unk028d, unk028e, unk028f;
    int unk0290, unk0291, unk0292, unk0293, unk0294, unk0295, unk0296, unk0297;
    int unk0298, unk0299, unk029a, unk029b, unk029c, unk029d, unk029e, unk029f;
    int unk02a0, unk02a1, unk02a2, unk02a3, unk02a4, unk02a5, unk02a6, unk02a7;
    int unk02a8, unk02a9, unk02aa, unk02ab, unk02ac, unk02ad, unk02ae, unk02af;
    int unk02b0, unk02b1, unk02b2, unk02b3, unk02b4, unk02b5, unk02b6, unk02b7;
    int unk02b8, unk02b9, unk02ba, unk02bb, unk02bc, unk02bd, unk02be, unk02bf;
    int unk02c0, unk02c1, unk02c2, unk02c3, unk02c4, unk02c5, unk02c6, unk02c7;
    int unk02c8, unk02c9, unk02ca, unk02cb, unk02cc, unk02cd, unk02ce, unk02cf;
    int unk02d0, unk02d1, unk02d2, unk02d3, unk02d4, unk02d5, unk02d6, unk02d7;
    int unk02d8, unk02d9, unk02da, unk02db, unk02dc, unk02dd, unk02de, unk02df;
    int unk02e0, unk02e1, unk02e2, unk02e3, unk02e4, unk02e5, unk02e6, unk02e7;
    int unk02e8, unk02e9, unk02ea, unk02eb, unk02ec, unk02ed, unk02ee, unk02ef;
    int unk02f0, unk02f1, unk02f2, unk02f3, unk02f4, unk02f5, unk02f6, unk02f7;
    int unk02f8, unk02f9, unk02fa, unk02fb, unk02fc, unk02fd, unk02fe, unk02ff;
    int unk0300, unk0301, unk0302, unk0303, unk0304, unk0305, unk0306, unk0307;
    int unk0308, unk0309, unk030a, unk030b, unk030c, unk030d, unk030e, unk030f;
    int unk0310, unk0311, unk0312, unk0313, unk0314, unk0315, unk0316, unk0317;
    int unk0318, unk0319, unk031a, unk031b, unk031c, unk031d, unk031e, unk031f;
    int unk0320, unk0321, unk0322, unk0323, unk0324, unk0325, unk0326, unk0327;
    int unk0328, unk0329, unk032a, unk032b, unk032c, unk032d, unk032e, unk032f;
    int unk0330, unk0331, unk0332, unk0333, unk0334, unk0335, unk0336, unk0337;
    int unk0338, unk0339, unk033a, unk033b, unk033c, unk033d, unk033e, unk033f;
    int unk0340, unk0341, unk0342, unk0343, unk0344, unk0345, unk0346, unk0347;
    int unk0348, unk0349, unk034a, unk034b, unk034c, unk034d, unk034e, unk034f;
    int unk0350, unk0351, unk0352, unk0353, unk0354, unk0355, unk0356, unk0357;
    int unk0358, unk0359, unk035a, unk035b, unk035c, unk035d, unk035e, unk035f;
    int unk0360, unk0361, unk0362, unk0363, unk0364, unk0365, unk0366, unk0367;
    int unk0368, unk0369, unk036a, unk036b, unk036c, unk036d, unk036e, unk036f;
    int unk0370, unk0371, unk0372, unk0373, unk0374, unk0375, unk0376, unk0377;
    int unk0378, unk0379, unk037a, unk037b, unk037c, unk037d, unk037e, unk037f;
    int unk0380, unk0381, unk0382, unk0383, unk0384, unk0385, unk0386, unk0387;
    int unk0388, unk0389, unk038a, unk038b, unk038c, unk038d, unk038e, unk038f;
    int unk0390, unk0391, unk0392, unk0393, unk0394, unk0395, unk0396, unk0397;
    int unk0398, unk0399, unk039a, unk039b, unk039c, unk039d, unk039e, unk039f;
    int unk03a0, unk03a1, unk03a2, unk03a3, unk03a4, unk03a5, unk03a6, unk03a7;
    int unk03a8, unk03a9, unk03aa, unk03ab, unk03ac, unk03ad, unk03ae, unk03af;
    int unk03b0, unk03b1, unk03b2, unk03b3, unk03b4, unk03b5, unk03b6, unk03b7;
    int unk03b8, unk03b9, unk03ba, unk03bb, unk03bc, unk03bd, unk03be, unk03bf;
    int unk03c0, unk03c1, unk03c2, unk03c3, unk03c4, unk03c5, unk03c6, unk03c7;
    int unk03c8, unk03c9, unk03ca, unk03cb, unk03cc, unk03cd, unk03ce, unk03cf;
    int unk03d0, unk03d1, unk03d2, unk03d3, unk03d4, unk03d5, unk03d6, unk03d7;
    int unk03d8, unk03d9, unk03da, unk03db, unk03dc, unk03dd, unk03de, unk03df;
    int unk03e0, unk03e1, unk03e2, unk03e3, unk03e4, unk03e5, unk03e6, unk03e7;
    int unk03e8, unk03e9, unk03ea, unk03eb, unk03ec, unk03ed, unk03ee, unk03ef;
    int unk03f0, unk03f1, unk03f2, unk03f3, unk03f4, unk03f5, unk03f6, unk03f7;
    int unk03f8, unk03f9, unk03fa, unk03fb, unk03fc, unk03fd, unk03fe, unk03ff;
    int unk0400, unk0401, unk0402, unk0403, unk0404, unk0405, unk0406, unk0407;
    int unk0408, unk0409, unk040a, unk040b, unk040c, unk040d, unk040e, unk040f;
    int unk0410, unk0411, unk0412, unk0413, unk0414, unk0415, unk0416, unk0417;
    int unk0418, unk0419, unk041a, unk041b, unk041c, unk041d, unk041e, unk041f;
    int unk0420, unk0421, unk0422, unk0423, unk0424, unk0425, unk0426, unk0427;
    int unk0428, unk0429, unk042a, unk042b, unk042c, unk042d, unk042e, unk042f;
    int unk0430, unk0431, unk0432, unk0433, unk0434, unk0435, unk0436, unk0437;
    int unk0438, unk0439, unk043a, unk043b, unk043c, unk043d, unk043e, unk043f;
    int unk0440, unk0441, unk0442, unk0443, unk0444, unk0445, unk0446, unk0447;
    int unk0448, unk0449, unk044a, unk044b, unk044c, unk044d, unk044e, unk044f;
    int unk0450, unk0451, unk0452, unk0453, unk0454, unk0455, unk0456, unk0457;
    int unk0458, unk0459, unk045a, unk045b, unk045c, unk045d, unk045e, unk045f;
    int unk0460, unk0461, unk0462, unk0463, unk0464, unk0465, unk0466, unk0467;
    int unk0468, unk0469, unk046a, unk046b, unk046c, unk046d, unk046e, unk046f;
    int unk0470, unk0471, unk0472, unk0473, unk0474, unk0475, unk0476, unk0477;
    int unk0478, unk0479, unk047a, unk047b, unk047c, unk047d, unk047e, unk047f;
    int unk0480, unk0481, unk0482, unk0483, unk0484, unk0485, unk0486, unk0487;
    int unk0488, unk0489, unk048a, unk048b, unk048c, unk048d, unk048e, unk048f;
    int unk0490, unk0491, unk0492, unk0493, unk0494, unk0495, unk0496, unk0497;
    int unk0498, unk0499, unk049a, unk049b, unk049c, unk049d, unk049e, unk049f;
    int unk04a0, unk04a1, unk04a2, unk04a3, unk04a4, unk04a5, unk04a6, unk04a7;
    int unk04a8, unk04a9, unk04aa, unk04ab, unk04ac, unk04ad, unk04ae, unk04af;
    int unk04b0, unk04b1, unk04b2, unk04b3, unk04b4, unk04b5, unk04b6, unk04b7;
    int unk04b8, unk04b9, unk04ba, unk04bb, unk04bc, unk04bd, unk04be, unk04bf;
    int unk04c0, unk04c1, unk04c2, unk04c3, unk04c4, unk04c5, unk04c6, unk04c7;
    int unk04c8, unk04c9, unk04ca, unk04cb, unk04cc, unk04cd, unk04ce, unk04cf;
    int unk04d0, unk04d1, unk04d2, unk04d3, unk04d4, unk04d5, unk04d6, unk04d7;
    int unk04d8, unk04d9, unk04da, unk04db, unk04dc, unk04dd, unk04de, unk04df;
    int unk04e0, unk04e1, unk04e2, unk04e3, unk04e4, unk04e5, unk04e6, unk04e7;
    int unk04e8, unk04e9, unk04ea, unk04eb, unk04ec, unk04ed, unk04ee, unk04ef;
    int unk04f0, unk04f1, unk04f2, unk04f3, unk04f4, unk04f5, unk04f6, unk04f7;
    int unk04f8, unk04f9, unk04fa, unk04fb, unk04fc, unk04fd, unk04fe, unk04ff;
    int unk0500, unk0501, unk0502, unk0503, unk0504, unk0505, unk0506, unk0507;
    int unk0508, unk0509, unk050a, unk050b, unk050c, unk050d, unk050e, unk050f;
    int unk0510, unk0511, unk0512, unk0513, unk0514, unk0515, unk0516, unk0517;
    int unk0518, unk0519, unk051a, unk051b, unk051c, unk051d, unk051e, unk051f;
    int unk0520, unk0521, unk0522, unk0523, unk0524, unk0525, unk0526, unk0527;
    int unk0528, unk0529, unk052a, unk052b, unk052c, unk052d, unk052e, unk052f;
    int unk0530, unk0531, unk0532, unk0533, unk0534, unk0535, unk0536, unk0537;
    int unk0538, unk0539, unk053a, unk053b, unk053c, unk053d, unk053e, unk053f;
    int unk0540, unk0541, unk0542, unk0543, unk0544, unk0545, unk0546, unk0547;
    int unk0548, unk0549, unk054a, unk054b, unk054c, unk054d, unk054e, unk054f;
    int unk0550, unk0551, unk0552, unk0553, unk0554, unk0555, unk0556, unk0557;
    int unk0558, unk0559, unk055a, unk055b, unk055c, unk055d, unk055e, unk055f;
    int unk0560, unk0561, unk0562, unk0563, unk0564, unk0565, unk0566, unk0567;
    int unk0568, unk0569, unk056a, unk056b, unk056c, unk056d, unk056e, unk056f;
    int unk0570, unk0571, unk0572, unk0573, unk0574, unk0575, unk0576, unk0577;
    int unk0578, unk0579, unk057a, unk057b, unk057c, unk057d, unk057e, unk057f;
    int unk0580, unk0581, unk0582, unk0583, unk0584, unk0585, unk0586, unk0587;
    int unk0588, unk0589, unk058a, unk058b, unk058c, unk058d, unk058e, unk058f;
    int unk0590, unk0591, unk0592, unk0593, unk0594, unk0595, unk0596, unk0597;
    int unk0598, unk0599, unk059a, unk059b, unk059c, unk059d, unk059e, unk059f;
    int unk05a0, unk05a1, unk05a2, unk05a3, unk05a4, unk05a5, unk05a6, unk05a7;
    int unk05a8, unk05a9, unk05aa, unk05ab, unk05ac, unk05ad, unk05ae, unk05af;
    int unk05b0, unk05b1, unk05b2, unk05b3, unk05b4, unk05b5, unk05b6, unk05b7;
    int unk05b8, unk05b9, unk05ba, unk05bb, unk05bc, unk05bd, unk05be, unk05bf;
    int unk05c0, unk05c1, unk05c2, unk05c3, unk05c4, unk05c5, unk05c6, unk05c7;
    int unk05c8, unk05c9, unk05ca, unk05cb, unk05cc, unk05cd, unk05ce, unk05cf;
    int unk05d0, unk05d1, unk05d2, unk05d3, unk05d4, unk05d5, unk05d6, unk05d7;
    int unk05d8, unk05d9, unk05da, unk05db, unk05dc, unk05dd, unk05de, unk05df;
    int unk05e0, unk05e1, unk05e2, unk05e3, unk05e4, unk05e5, unk05e6, unk05e7;
    int unk05e8, unk05e9, unk05ea, unk05eb, unk05ec, unk05ed, unk05ee, unk05ef;
    int unk05f0, unk05f1, unk05f2, unk05f3, unk05f4, unk05f5, unk05f6, unk05f7;
    int unk05f8, unk05f9, unk05fa, unk05fb, unk05fc, unk05fd, unk05fe, unk05ff;
    int unk0600, unk0601, unk0602, unk0603, unk0604, unk0605, unk0606, unk0607;
    int unk0608, unk0609, unk060a, unk060b, unk060c, unk060d, unk060e, unk060f;
    int unk0610, unk0611, unk0612, unk0613, unk0614, unk0615, unk0616, unk0617;
    int unk0618, unk0619, unk061a, unk061b, unk061c, unk061d, unk061e, unk061f;
    int unk0620, unk0621, unk0622, unk0623, unk0624, unk0625, unk0626, unk0627;
    int unk0628, unk0629, unk062a, unk062b, unk062c, unk062d, unk062e, unk062f;
    int unk0630, unk0631, unk0632, unk0633, unk0634, unk0635, unk0636, unk0637;
    int unk0638, unk0639, unk063a, unk063b, unk063c, unk063d, unk063e, unk063f;
    int unk0640, unk0641, unk0642, unk0643, unk0644, unk0645, unk0646, unk0647;
    int unk0648, unk0649, unk064a, unk064b, unk064c, unk064d, unk064e, unk064f;
    int unk0650, unk0651, unk0652, unk0653, unk0654, unk0655, unk0656, unk0657;
    int unk0658, unk0659, unk065a, unk065b, unk065c, unk065d, unk065e, unk065f;
    int unk0660, unk0661, unk0662, unk0663, unk0664, unk0665, unk0666, unk0667;
    int unk0668, unk0669, unk066a, unk066b, unk066c, unk066d, unk066e, unk066f;
    int unk0670, unk0671, unk0672, unk0673, unk0674, unk0675, unk0676, unk0677;
    int unk0678, unk0679, unk067a, unk067b, unk067c, unk067d, unk067e, unk067f;
    int unk0680, unk0681, unk0682, unk0683, unk0684, unk0685, unk0686, unk0687;
    int unk0688, unk0689, unk068a, unk068b, unk068c, unk068d, unk068e, unk068f;
    int unk0690, unk0691, unk0692, unk0693, unk0694, unk0695, unk0696, unk0697;
    int unk0698, unk0699, unk069a, unk069b, unk069c, unk069d, unk069e, unk069f;
    int unk06a0, unk06a1, unk06a2, unk06a3, unk06a4, unk06a5, unk06a6, unk06a7;
    int unk06a8, unk06a9, unk06aa, unk06ab, unk06ac, unk06ad, unk06ae, unk06af;
    int unk06b0, unk06b1, unk06b2, unk06b3, unk06b4, unk06b5, unk06b6, unk06b7;
    int unk06b8, unk06b9, unk06ba, unk06bb, unk06bc, unk06bd, unk06be, unk06bf;
    int unk06c0, unk06c1, unk06c2, unk06c3, unk06c4, unk06c5, unk06c6, unk06c7;
    int unk06c8, unk06c9, unk06ca, unk06cb, unk06cc, unk06cd, unk06ce, unk06cf;
    int unk06d0, unk06d1, unk06d2, unk06d3, unk06d4, unk06d5, unk06d6, unk06d7;
    int unk06d8, unk06d9, unk06da, unk06db, unk06dc, unk06dd, unk06de, unk06df;
    int unk06e0, unk06e1, unk06e2, unk06e3, unk06e4, unk06e5, unk06e6, unk06e7;
    int unk06e8, unk06e9, unk06ea, unk06eb, unk06ec, unk06ed, unk06ee, unk06ef;
    int unk06f0, unk06f1, unk06f2, unk06f3, unk06f4, unk06f5, unk06f6, unk06f7;
    int unk06f8, unk06f9, unk06fa, unk06fb, unk06fc, unk06fd, unk06fe, unk06ff;
    int unk0700, unk0701, unk0702, unk0703, unk0704, unk0705, unk0706, unk0707;
    int unk0708, unk0709, unk070a, unk070b, unk070c, unk070d, unk070e, unk070f;
    int unk0710, unk0711, unk0712, unk0713, unk0714, unk0715, unk0716, unk0717;
    int unk0718, unk0719, unk071a, unk071b, unk071c, unk071d, unk071e, unk071f;
    int unk0720, unk0721, unk0722, unk0723, unk0724, unk0725, unk0726, unk0727;
    int unk0728, unk0729, unk072a, unk072b, unk072c, unk072d, unk072e, unk072f;
    int unk0730, unk0731, unk0732, unk0733, unk0734, unk0735, unk0736, unk0737;
    int unk0738, unk0739, unk073a, unk073b, unk073c, unk073d, unk073e, unk073f;
    int unk0740, unk0741, unk0742, unk0743, unk0744, unk0745, unk0746, unk0747;
    int unk0748, unk0749, unk074a, unk074b, unk074c, unk074d, unk074e, unk074f;
    int unk0750, unk0751, unk0752, unk0753, unk0754, unk0755, unk0756, unk0757;
    int unk0758, unk0759, unk075a, unk075b, unk075c, unk075d, unk075e, unk075f;
    int unk0760, unk0761, unk0762, unk0763, unk0764, unk0765, unk0766, unk0767;
    int unk0768, unk0769, unk076a, unk076b, unk076c, unk076d, unk076e, unk076f;
    int unk0770, unk0771, unk0772, unk0773, unk0774, unk0775, unk0776, unk0777;
    int unk0778, unk0779, unk077a, unk077b, unk077c, unk077d, unk077e, unk077f;
    int unk0780, unk0781, unk0782, unk0783, unk0784, unk0785, unk0786, unk0787;
    int unk0788, unk0789, unk078a, unk078b, unk078c, unk078d, unk078e, unk078f;
    int unk0790, unk0791, unk0792, unk0793, unk0794, unk0795, unk0796, unk0797;
    int unk0798, unk0799, unk079a, unk079b, unk079c, unk079d, unk079e, unk079f;
    int unk07a0, unk07a1, unk07a2, unk07a3, unk07a4, unk07a5, unk07a6, unk07a7;
    int unk07a8, unk07a9, unk07aa, unk07ab, unk07ac, unk07ad, unk07ae, unk07af;
    int unk07b0, unk07b1, unk07b2, unk07b3, unk07b4, unk07b5, unk07b6, unk07b7;
    int unk07b8, unk07b9, unk07ba, unk07bb, unk07bc, unk07bd, unk07be, unk07bf;
    int unk07c0, unk07c1, unk07c2, unk07c3, unk07c4, unk07c5, unk07c6, unk07c7;
    int unk07c8, unk07c9, unk07ca, unk07cb, unk07cc, unk07cd, unk07ce, unk07cf;
    int unk07d0, unk07d1, unk07d2, unk07d3, unk07d4, unk07d5, unk07d6, unk07d7;
    int unk07d8, unk07d9, unk07da, unk07db, unk07dc, unk07dd, unk07de, unk07df;
    int unk07e0, unk07e1, unk07e2, unk07e3, unk07e4, unk07e5, unk07e6, unk07e7;
    int unk07e8, unk07e9, unk07ea, unk07eb, unk07ec, unk07ed, unk07ee, unk07ef;
    int unk07f0, unk07f1, unk07f2, unk07f3, unk07f4, unk07f5, unk07f6, count;
};
struct OpenSearchTable
{
    float minimumCost;
    int unk00, unk01, unk02, unk03, unk04, unk05, unk06, unk07;
    int unk08, unk09, unk0a, unk0b, unk0c, unk0d, unk0e, unk0f;
    int unk10, unk11, unk12, unk13;
};
struct SearchStorage
{
    void* vtable;
    SearchAllocator allocator;
    ClosedSearchTable closed;
    OpenSearchTable open;
    SearchNode* best;
    SearchNode* current;
    SearchNode* last;
    bool stopped;
};
struct MeshAccess
{
    NiPoint3 FUN_00558220(unsigned short);
    unsigned int FUN_0068efb0();
};
struct TriangleCandidate
{
    MeshAccess* mesh;
    unsigned short triangle;
    unsigned short flags;
    NiPoint3 center;
};
struct SearchNode
{
    float totalCost;
    float pathCost;
    TriangleCandidate candidate;
};
struct SearchArrayFields
{
    void* vtable;
    void* data;
    unsigned int size;
    unsigned int capacity;
};
struct CandidateArray : SearchArrayFields
{
    void* allocator;
    CandidateArray(int, int, void*);
    ~CandidateArray();
};
struct DestinationArray : SearchArrayFields
{
    void* allocator;
    DestinationArray(int, int, void*);
    ~DestinationArray();
};
struct PathMeshArray : SearchArrayFields
{
    PathMeshArray();
    ~PathMeshArray();
};
struct SearchPoint : NiPoint3
{
    SearchPoint();
};
struct PointOperations
{
};
struct RequestOperations
{
};
struct LocationOperations
{
};
struct CandidateSearch : SearchStorage
{
    PathingRequestOptimalLocation* request;
    TriangleCandidate start;
    TriangleCandidate goal;
    void* unk2084;
    void* unk2088;
    unsigned int unk208c, unk2090, unk2094, unk2098, unk209c, unk20a0;
    float radius;
    bool enabled;
    CandidateSearch();
    ~CandidateSearch();
};
struct RouteFinalizer : SearchStorage
{
    unsigned int unk2058, unk205c;
    NiPoint3 start;
    NiPoint3 goal;
    unsigned int unk2078, unk207c, unk2080;
    SearchArrayFields unk2084, unk2094, unk20a4, unk20b4;
    unsigned int unk20c4, unk20c8;
    SearchArrayFields unk20cc, unk20dc, unk20ec, unk20fc;
    unsigned int unk210c;
    RouteFinalizer();
    ~RouteFinalizer();
};
struct RouteArray : SearchArrayFields
{
    void* allocator;
    RouteArray(int, int, void*);
    ~RouteArray();
};
struct SolutionFields
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    unsigned int edgeIndex;
    unsigned int initialized;
};
float __cdecl FUN_00408840(float);
void __cdecl FUN_006d91d0(PathMeshArray*);

// Local names below preserve MSVC9 /Od allocation ordering.
// Their source meanings and slot rationale are recorded in reconstruction-notes.md.
// @fnv 0x006d23d0
bool __cdecl BuildOptimalPathSolution(PathingRequestOptimalLocation* request, PathingSolution* solution)
{
    AutoMemContext ba((MEM_CONTEXT)45, true, str_0106cb70, 668);
    if (!reinterpret_cast<::NLLocation *>((((::PathingLocation *)(::GetOffsetC((std::intptr_t)(((RequestOperations*)request)))))))->UpdateMeshLocation())
        return false;
    TriangleCandidate originTriangle;
    float closestPoint;
    NavMeshPtr goal;
    unsigned short tri_ = 0xffff;
    if (!((::PathingLocation *)(::GetOffsetC((std::intptr_t)(((RequestOperations*)request)))))->FindNavMeshTriangle(goal, tri_))
        return false;
    float s = reinterpret_cast<::FUN_006d2c20_Class *>((((RequestOperations*)request)))->GetFloatAtOffsetB0();
    float startTriangle = ::GetFieldB4Float((char *)(((RequestOperations*)request)));
    float i = (s + startTriangle) / ::DAT_01011590;
    NiPoint3 displacement = reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathingLocation *)(::GetOffsetC((std::intptr_t)(((RequestOperations*)request)))))))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    NiPoint3 q = reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathingLocation *)(::FUN_006a9540((char *)(((RequestOperations*)request)))))))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    NiPoint3 vDir = q - displacement;
    float p = reinterpret_cast<::NiPoint3 *>((((PointOperations*)&vDir)))->GetLengthSquared();
    NiPoint3 loc = q - vDir * i;
    float cf = FUN_00408840(i - p);
    SearchPoint a;
    if (!::Pathing::FindClosestPathingPoint((::TESWorldSpace *)(void *)(((void *)(std::uintptr_t)(reinterpret_cast<::BGSTerrainManager *>((((LocationOperations*)((::PathingLocation *)(::GetOffsetC((std::intptr_t)(((RequestOperations*)request))))))))->GetMinLevel()))),
                      (::TESObjectCELL *)(((reinterpret_cast<::PathingLocation *>((void *)(((LocationOperations*)((::PathingLocation *)(::GetOffsetC((std::intptr_t)(((RequestOperations*)request))))))))->GetContainingCell()))), (*(const ::NiPoint3 *)(&loc)), &a))
        return false;
    NiPoint3 candidatePoints = a - loc;
    if (reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&candidatePoints)))->UpdateCombatStyle() > cf * cf)
        return false;
    PathingLocation tolerance(a, *((::PathingLocation *)(::GetOffsetC((std::intptr_t)(((RequestOperations*)request))))));
    TriangleCandidate b;
    b.mesh = (MeshAccess*)goal.operator->();
    b.triangle = tri_;
    NiPoint3 pathMeshes = reinterpret_cast<::NavMesh *>((b.mesh))->GetNavMeshData(b.triangle);
    b.center.x = pathMeshes.x;
    b.center.y = pathMeshes.y;
    b.center.z = pathMeshes.z;
    NiPoint3 h = reinterpret_cast<::TaskQueueInterface *>((void *)(((::PathingLocation *)(::GetOffsetC((std::intptr_t)(((RequestOperations*)request)))))))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    if (!reinterpret_cast<::PathingLocationProxy *>((((LocationOperations*)&tolerance)))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
        reinterpret_cast<::FUN_006d2c00_shell *>((((LocationOperations*)&tolerance)))->FUN_006d2c00();
    CandidateSearch eb;
    CandidateArray memory(32, 0, 0);
    DestinationArray f(32, 0, 0);
    reinterpret_cast<::FUN_006d2c60_Class *>(&(eb))->FUN_006d2c60(cf * 2.0f);
    PathMeshArray c;
    FUN_006d91d0(&c);
    SearchPoint triangleFilter;
    if (reinterpret_cast<::FUN_006ab4a0_shell *>(&(eb))->StartSearch((std::intptr_t)(request), (::NavMeshSearchLocation *)(::fnv_006d23d0::TriangleCandidate *)(&b), &tolerance, (::PathBuilderDetailedPathInfos *)(::fnv_006d23d0::CandidateArray *)(&memory), (::PathBuilderDetailedPathInfos *)(::fnv_006d23d0::DestinationArray *)(&f)))
    {
        originTriangle = (*(::fnv_006d23d0::TriangleCandidate *)(reinterpret_cast<::FUN_006b3160_shell *>(&(memory))->FUN_006b3160(((int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(memory))->GetName())) - 1)));
        if (!reinterpret_cast<::FUN_006a9520_Class *>((((LocationOperations*)&tolerance)))->FUN_006a9520())
            (NiPoint3&)triangleFilter = a;
        else
            (NiPoint3&)triangleFilter = (*(::NiPoint3 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>(&(originTriangle))->FUN_006a6eb0({})));
    }
    else
    {
        if (!reinterpret_cast<::FUN_0076b610_Class *>(&(memory))->FUN_0076b610())
        {
            originTriangle = ((::fnv_006d23d0::SearchNode *)(std::uintptr_t)(reinterpret_cast<::FUN_006abb90_shell *>(&(eb))->GetField2048()))->candidate;
            (NiPoint3&)triangleFilter = (*(::NiPoint3 *)(reinterpret_cast<::GetCenterX_006a6eb0 *>(&(originTriangle))->FUN_006a6eb0({})));
        }
        else
        {
            if (p > reinterpret_cast<::FUN_0099e040_shell *>((((RequestOperations*)request)))->FUN_0099e040())
                return FUN_006d0b10(request, solution);
            return false;
        }
    }
    float route = reinterpret_cast<::FUN_0099e040_shell *>((((RequestOperations*)request)))->FUN_0099e040();
    float remaining = reinterpret_cast<::FUN_0048ee50_Class *>((((RequestOperations*)request)))->GetFieldB8Float();
    vDir = triangleFilter - q;
    closestPoint = reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&vDir)))->UpdateCombatStyle();
    if (closestPoint < remaining * remaining || closestPoint > route * route)
        return false;
    reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((((SolutionFields*)solution)))->AddPathingItem((void *)(&h), (::TESObjectREFR *)(((reinterpret_cast<::FUN_0068efb0_shell *>((b.mesh))->FUN_0068efb0()))));
    reinterpret_cast<::fnv_006c99c0::FUN_006c99c0_shell *>((((SolutionFields*)solution)))->AddPathingItem((void *)(&triangleFilter), (::TESObjectREFR *)(((reinterpret_cast<::FUN_0068efb0_shell *>((originTriangle.mesh))->FUN_0068efb0()))));
    ((SolutionFields*)solution)->edgeIndex = 0;
    ((SolutionFields*)solution)->initialized = 1;
    RouteFinalizer e;
    RouteArray j(32, 0, 0);
    bool k = reinterpret_cast<::PathSmootherPOVSearch *>(&(e))->SearchForPath((::PathingRequest *)(request), (*(const ::BSSimpleArray< ::NavMeshTriangleReference, 1024> *)(&memory)), (*(const ::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *)(&f)), (*(const ::NiPoint3 *)(&h)), (*(const ::NiPoint3 *)(&triangleFilter)), solution, (::BSSimpleArray< ::NavMeshTriangleEdgeReference, 1024> *)(0), (::BSSimpleArray<const ::NavMeshInfo *, 1024> *)(0));
    return k;
}
}  // namespace fnv_006d23d0


struct FUN_006a0480
{
    FUN_006a0480();
    char m_acData[0x18];
};

struct Array6d0
{
    void FUN_006d05e0(FUN_006a0480* pkItems, unsigned int ItemUpdateArray);
};

// @fnv 0x006d05e0
void Array6d0::FUN_006d05e0(FUN_006a0480* pkItems, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkItems[i]) FUN_006a0480;
}

namespace fnv_006d74c0 {
struct Vec2
{
    float x, y;
    Vec2();
    Vec2(float, float);
};
struct Point3
{
    float x, y, z;
    Point3(float, float, float);
};
struct EdgeInfo
{
    unsigned int type;
};
struct MeshOps
{
    int FindTriangleEdge(unsigned short, int, const Vec2&, const Vec2&, Vec2&);
    void FUN_0068f040(NiPoint3**, unsigned short, int);
    const NavMeshInfo* FUN_0068efb0();
    NiPoint3 FUN_00558220(unsigned short);
};
struct PointerOps
{
    bool IsNotEqual(const NiPointer<NavMesh>&);
};
struct LocationOps
{
};
struct Location
{
    unsigned int vtable;
    NiPoint3 position;
    unsigned int mesh, meshes, cell, world, key;
    unsigned short triangle;
    unsigned char flags, padding;
    Location(const NiPoint3&, const NavMeshInfo*, unsigned short);
    ~Location();
};
struct EdgeRef
{
    NavMesh* mesh;
    unsigned short triangle;
    int edges3;
    EdgeRef(NavMesh*, unsigned short, int);
    EdgeRef(const EdgeRef&);
};
struct EdgeFilter
{
    virtual bool Test(EdgeRef, EdgeRef);
};

// Traces a 2D ray from start to end across navmesh triangles, applying an edge filter, and writes the resulting location to output.
// @fnv 0x006d74c0
bool __cdecl FUN_006d74c0(PathingLocation& start, const NiPoint3& end, NavMesh* desiredMesh,
                          unsigned short desiredTriangle, PathingLocation* output, EdgeFilter* filter)
{
    if (output)
        *output = start;
    if (!reinterpret_cast<::PathingLocationProxy *>((((LocationOps*)&start)))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
    {
        if (!desiredMesh)
            return true;
        return false;
    }
    NavMeshPtr initialMesh;
    unsigned short initialTriangle;
    if (!reinterpret_cast<::PathingLocation *>((((LocationOps*)&start)))->FindNavMeshTriangle(initialMesh, initialTriangle))
        return false;
    Vec2 origin3(reinterpret_cast<::TaskQueueInterface *>((void *)&(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()).x, reinterpret_cast<::TaskQueueInterface *>((void *)&(start))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()).y);
    Vec2 destination2(end.x, end.y);
    Vec2 crossing3;
    NiPointer<NavMesh> currentMesh5(initialMesh);
    unsigned short triangle6 = initialTriangle;
    int edges3 = ((MeshOps*)(NavMesh*)initialMesh)->FindTriangleEdge(triangle6, -1, origin3, destination2, crossing3);
    while (edges3 != -1)
    {
        NavMeshPtr nextMesh5;
        unsigned short triangleX;
        int nextEdge4;
        bool canCrossA =
            reinterpret_cast<::NavMeshEdgeQuery *>((((MeshOps*)(NavMesh*)currentMesh5)))->FUN_0068f3b0(triangle6, edges3, (::NiPointer< ::NavMesh> &)(nextMesh5), (std::intptr_t)&(triangleX), nextEdge4);
        if (canCrossA && filter)
        {
            EdgeRef fromEdge((NavMesh*)currentMesh5, triangle6, edges3);
            EdgeRef toEdge((NavMesh*)nextMesh5, triangleX, nextEdge4);
            canCrossA = filter->Test(fromEdge, toEdge);
        }
        if (canCrossA)
        {
            EdgeInfo* edgeInfo = ((::fnv_006d74c0::EdgeInfo *)(reinterpret_cast<::FUN_0068f230_shell *>((((MeshOps*)(NavMesh*)currentMesh5)))->FUN_0068f230(triangle6, edges3)));
            if (edgeInfo && edgeInfo->type == 1)
                canCrossA = false;
        }
        if (canCrossA)
        {
            if (((PointerOps*)&nextMesh5)->IsNotEqual(currentMesh5))
            {
                NiPoint3* endpoints[2];
                ((MeshOps*)(NavMesh*)nextMesh5)->FUN_0068f040(endpoints, triangleX, nextEdge4);
                Vec2 edgeStart(endpoints[0]->x, endpoints[0]->y);
                Vec2 edgeEnd(endpoints[1]->x, endpoints[1]->y);
                crossing3 = (*(::fnv_006d74c0::Vec2 *)(::FUN_006ba3d0((::TwoComponentVector *)&(edgeStart), (::TwoComponentVector *)&(edgeEnd), (::TwoComponentVector *)&(crossing3), (::TwoComponentVector *)&(destination2), {})));
            }
            triangle6 = triangleX;
            reinterpret_cast<::NavMeshPtr *>((void *)&(const ::NiPointer< ::NavMesh> &)(currentMesh5))->operator=((const ::NavMeshPtr &)(nextMesh5));
            Vec2 nextCrossing;
            edges3 = ((MeshOps*)(NavMesh*)nextMesh5)
                         ->FindTriangleEdge(triangleX, nextEdge4, crossing3, destination2, nextCrossing);
            crossing3 = nextCrossing;
        }
        else
        {
            if (output)
            {
                reinterpret_cast<::FUN_006dd3e0_shell *>((((LocationOps*)output)))->FUN_006dd3e0(reinterpret_cast<::FUN_0068efb0_shell *>((((MeshOps*)(NavMesh*)currentMesh5)))->FUN_0068efb0());
                reinterpret_cast<::FUN_006dd4d0_shell *>((((LocationOps*)output)))->SetField(triangle6);
                reinterpret_cast<::FUN_006dd460 *>((((LocationOps*)output)))->FUN_006dd460_1((const ::NiPoint3 &)((const ::fnv_006d74c0::Point3 &)(Point3(crossing3.x, crossing3.y,
                                          reinterpret_cast<::NavMesh *>((((MeshOps*)(NavMesh*)currentMesh5)))->GetNavMeshData(triangle6).z))));
            }
            return false;
        }
    }
    if (desiredMesh && desiredTriangle != 0xffff)
    {
        if ((NavMesh*)currentMesh5 == desiredMesh && triangle6 == desiredTriangle)
        {
            if (output)
            {
                Location kLocation(end, reinterpret_cast<::FUN_0068efb0_shell *>((((MeshOps*)desiredMesh)))->FUN_0068efb0(), desiredTriangle);
                *output = *(PathingLocation*)&kLocation;
            }
            return true;
        }
        else
            return false;
    }
    else
    {
        if (output)
        {
            reinterpret_cast<::FUN_006dd3e0_shell *>((((LocationOps*)output)))->FUN_006dd3e0(reinterpret_cast<::FUN_0068efb0_shell *>((((MeshOps*)(NavMesh*)currentMesh5)))->FUN_0068efb0());
            reinterpret_cast<::FUN_006dd4d0_shell *>((((LocationOps*)output)))->SetField(triangle6);
            reinterpret_cast<::FUN_006dd460 *>((((LocationOps*)output)))->FUN_006dd460_1((const ::NiPoint3 &)((const Point3&)end));
        }
        return true;
    }
}
}  // namespace fnv_006d74c0

struct Vec3_ctx : NiPoint3
{
    Vec3_ctx();
    Vec3_ctx ApplyScaled(float) const;
};

struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
    Vec3_ctx FUN_004b4500(const Vec3_ctx*);
};

struct PointOperations
{
    Vec3_ctx FUN_0053d1a0(const Vec3_ctx&) const;
};

struct PathingLocationOperations
{
};

extern const double DAT_0106cbc8;


// @fnv 0x006d99a0
Vec3_ctx __cdecl FUN_006d99a0(float angle, PathingLocation* startRef, PathingLocation* endRef, float radius)
{
    Matrix rotation6;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(rotation6))->FUN_004a0c90(angle);
    Vec3_ctx forwardAxis = rotation6.FUN_004b4500(&(*reinterpret_cast<::Vec3_ctx *>(&::DAT_011a9478)));
    PathingLocation start0(*startRef);
    Vec3_ctx origin20 = (*(::Vec3_ctx *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&start0)))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
    Vec3_ctx goalId_ = (*(::Vec3_ctx *)(reinterpret_cast<::Point3Offset *>((void *)&(origin20))->ProjectileLaunched(&ResultSlot<::NiPoint3>(), (::NiPoint3 *)&(const ::Vec3_ctx &)(forwardAxis.ApplyScaled(DAT_01032adc)))));
    PathingLocation first2;
    if (!Pathing::FindPathingLocation(start0, goalId_, &first2, 0))
        goalId_ = (*(::Vec3_ctx *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
    Vec3_ctx initial = (*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(origin20))));
    Vec3_ctx sideShape7 = ((PointOperations*)&initial)->FUN_0053d1a0((*reinterpret_cast<const ::Vec3_ctx *>((void *)&::DAT_011a9484))).ApplyScaled(radius);
    PathingLocation leftStartB((*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(origin20))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(sideShape7)))), start0);
    PathingLocation leftEnd5((*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(sideShape7)))), start0);
    if (!FUN_006d7350(leftStartB, leftEnd5, &first2, 0))
    {
        if (reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&(
                 const Vec3_ctx&)((*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::Vec3_ctx &)((*(::Vec3_ctx *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(const ::Vec3_ctx &)((*(::Vec3_ctx *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&leftStartB)))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))))))))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&initial)))->UpdateCombatStyle())
            goalId_ = (*(::Vec3_ctx *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
    }
    PathingLocation rightStart2((*(::Vec3_ctx *)(reinterpret_cast<::Point3Offset *>((void *)&(origin20))->ProjectileLaunched(&ResultSlot<::NiPoint3>(), (::NiPoint3 *)&(sideShape7)))), start0);
    PathingLocation rightEnd2((*(::Vec3_ctx *)(reinterpret_cast<::Point3Offset *>((void *)&(goalId_))->ProjectileLaunched(&ResultSlot<::NiPoint3>(), (::NiPoint3 *)&(sideShape7)))), start0);
    if (!FUN_006d7350(rightStart2, rightEnd2, &first2, 0))
    {
        if (reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&(
                 const Vec3_ctx&)((*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(void *)&(const ::Vec3_ctx &)((*(::Vec3_ctx *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(const ::Vec3_ctx &)((*(::Vec3_ctx *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&rightStart2)))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))))))))))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)(((PointOperations*)&initial)))->UpdateCombatStyle())
            goalId_ = (*(::Vec3_ctx *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&first2)))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
    }
    reinterpret_cast<::NiPoint3 *>((((PointOperations*)&goalId_)))->Subtract((const ::NiPoint3 &)((const ::Vec3_ctx &)(forwardAxis.ApplyScaled(radius).ApplyScaled(DAT_01018204))));
    PathingLocation end19(*endRef);
    Vec3_ctx endOriginVal = (*(::Vec3_ctx *)&(reinterpret_cast<::TaskQueueInterface *>((void *)(((PathingLocationOperations*)&end19)))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())));
    PathingLocation endHitX;
    if (!Pathing::FindPathingLocation(end19, goalId_, &endHitX, 0))
        return (*reinterpret_cast<const ::Vec3_ctx *>((void *)&::NiPoint3::ZERO));
    Vec3_ctx endDelta = (*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(endOriginVal))));
    Vec3_ctx endSide = ((PointOperations*)&endDelta)->FUN_0053d1a0((*reinterpret_cast<const ::Vec3_ctx *>((void *)&::DAT_011a9484))).ApplyScaled(radius);
    PathingLocation endLeftEndA((*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(endOriginVal))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(sideShape7)))), end19);
    PathingLocation endLeftStart6((*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(sideShape7)))), end19);
    if (!FUN_006d7350(endLeftEndA, endLeftStart6, &endHitX, 0))
        return (*reinterpret_cast<const ::Vec3_ctx *>((void *)&::NiPoint3::ZERO));
    PathingLocation endRightStart4((*(::Vec3_ctx *)(reinterpret_cast<::Point3Offset *>((void *)&(endOriginVal))->ProjectileLaunched(&ResultSlot<::NiPoint3>(), (::NiPoint3 *)&(sideShape7)))), end19);
    PathingLocation endRightEnd2((*(::Vec3_ctx *)(reinterpret_cast<::Point3Offset *>((void *)&(goalId_))->ProjectileLaunched(&ResultSlot<::NiPoint3>(), (::NiPoint3 *)&(sideShape7)))), end19);
    if (!FUN_006d7350(endRightStart4, endRightEnd2, &endHitX, 0))
        return (*reinterpret_cast<const ::Vec3_ctx *>((void *)&::NiPoint3::ZERO));
    Vec3_ctx directionX = (*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(endOriginVal))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(origin20))));
    float distance29 = reinterpret_cast<::NiPoint3 *>((((PointOperations*)&directionX)))->GetLengthSquared();
    float i = reinterpret_cast<::FUN_004b6190_shell *>((void *)(((PointOperations*)&directionX)))->DotProduct((void *)&(forwardAxis));
    if (i < DAT_0106cbc8)
    {
        return (*reinterpret_cast<const ::Vec3_ctx *>((void *)&::NiPoint3::ZERO));
    }
    else if (i < ::_DAT_01012060 && distance29 < DAT_010240c0)
    {
        return (*reinterpret_cast<const ::Vec3_ctx *>((void *)&::NiPoint3::ZERO));
    }
    return (*(::Vec3_ctx *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(goalId_))->FUN_00439ef0(&ResultSlot<::NiPoint3>(), *(const ::NiPoint3 *)&(origin20))));
}

class PathingLocation_r006d34d0
{
  public:
    void** m_ppVirtualMethodTable;                         // +0x0
    NiPoint3 Location;                       // +0x4
    const NavMeshInfo* m_pLocationNavMesh;   // +0x10
    const void* pNavMeshInfoArray;           // +0x14 (BSSimpleArray<const NavMeshInfo*,1024>*)
    TESObjectCELL* pCell;                    // +0x18
    TESWorldSpace* m_pContainingWorldspace;  // +0x1C
    unsigned int m_uiPathingFlags;           // +0x20
    unsigned short m_usTriangleID;           // +0x24
    unsigned char uiFlags;                   // +0x26
    unsigned char
        layoutPadding27;  // scalar, not [1]: a char array member makes /GS protect PathingLocation_r006d34d0 locals
    PathingLocation_r006d34d0();
    PathingLocation_r006d34d0(const NiPoint3&, TESObjectCELL*, TESWorldSpace*);
    ~PathingLocation_r006d34d0();
    bool HasValidTriangle();
    bool IsPathingLocationValid();
    void ResetLocation();
    PathingLocation_r006d34d0(const PathingLocation_r006d34d0&);  // 0x006dcc40 (called out of line by unmatched code)
    PathingLocation_r006d34d0(const NiPoint3&, const PathingLocation_r006d34d0&);  // 0x006dd0d0
    PathingLocation_r006d34d0& operator=(
        const PathingLocation_r006d34d0&);  // out of line in the original (no rep movsd)
    NiPoint3 GetLocation() const;           // 0x005c3420
};

struct ReqX
{
};

struct NavPtrX
{
    void* m_pObject;
    void* FUN_00458b50();
};

struct Info
{
    NavMesh* mesh;
    unsigned short tri;
    unsigned int f8;
    unsigned int fC;
    unsigned int f10;
};

struct Elem20
{
    NavMesh* mesh;
    unsigned short tri;
    unsigned short f6;
    unsigned int f8;
    unsigned int fC;
    unsigned int f10;
};

struct TriX
{
};

struct MeshX_ctxr
{
};

struct ArrD
{
    void** vt;
    void* buf;
    unsigned int sz;
    unsigned int res;
    void* alloc;
    ArrD(int a, int b, void* c);
    ~ArrD();
};

struct ArrE
{
    void** vt;
    void* buf;
    unsigned int sz;
    unsigned int res;
    void* alloc;
    ArrE(int a, int b, void* c);
    ~ArrE();
};

struct BigSearch
{
    unsigned int unk0000, unk0004, unk0008, unk000c;
    unsigned int unk0010, unk0014, unk0018, unk001c;
    unsigned int unk0020, unk0024, unk0028, unk002c;
    unsigned int unk0030, unk0034, unk0038, unk003c;
    unsigned int unk0040, unk0044, unk0048, unk004c;
    unsigned int unk0050, unk0054, unk0058, unk005c;
    unsigned int unk0060, unk0064, unk0068, unk006c;
    unsigned int unk0070, unk0074, unk0078, unk007c;
    unsigned int unk0080, unk0084, unk0088, unk008c;
    unsigned int unk0090, unk0094, unk0098, unk009c;
    unsigned int unk00a0, unk00a4, unk00a8, unk00ac;
    unsigned int unk00b0, unk00b4, unk00b8, unk00bc;
    unsigned int unk00c0, unk00c4, unk00c8, unk00cc;
    unsigned int unk00d0, unk00d4, unk00d8, unk00dc;
    unsigned int unk00e0, unk00e4, unk00e8, unk00ec;
    unsigned int unk00f0, unk00f4, unk00f8, unk00fc;
    unsigned int unk0100, unk0104, unk0108, unk010c;
    unsigned int unk0110, unk0114, unk0118, unk011c;
    unsigned int unk0120, unk0124, unk0128, unk012c;
    unsigned int unk0130, unk0134, unk0138, unk013c;
    unsigned int unk0140, unk0144, unk0148, unk014c;
    unsigned int unk0150, unk0154, unk0158, unk015c;
    unsigned int unk0160, unk0164, unk0168, unk016c;
    unsigned int unk0170, unk0174, unk0178, unk017c;
    unsigned int unk0180, unk0184, unk0188, unk018c;
    unsigned int unk0190, unk0194, unk0198, unk019c;
    unsigned int unk01a0, unk01a4, unk01a8, unk01ac;
    unsigned int unk01b0, unk01b4, unk01b8, unk01bc;
    unsigned int unk01c0, unk01c4, unk01c8, unk01cc;
    unsigned int unk01d0, unk01d4, unk01d8, unk01dc;
    unsigned int unk01e0, unk01e4, unk01e8, unk01ec;
    unsigned int unk01f0, unk01f4, unk01f8, unk01fc;
    unsigned int unk0200, unk0204, unk0208, unk020c;
    unsigned int unk0210, unk0214, unk0218, unk021c;
    unsigned int unk0220, unk0224, unk0228, unk022c;
    unsigned int unk0230, unk0234, unk0238, unk023c;
    unsigned int unk0240, unk0244, unk0248, unk024c;
    unsigned int unk0250, unk0254, unk0258, unk025c;
    unsigned int unk0260, unk0264, unk0268, unk026c;
    unsigned int unk0270, unk0274, unk0278, unk027c;
    unsigned int unk0280, unk0284, unk0288, unk028c;
    unsigned int unk0290, unk0294, unk0298, unk029c;
    unsigned int unk02a0, unk02a4, unk02a8, unk02ac;
    unsigned int unk02b0, unk02b4, unk02b8, unk02bc;
    unsigned int unk02c0, unk02c4, unk02c8, unk02cc;
    unsigned int unk02d0, unk02d4, unk02d8, unk02dc;
    unsigned int unk02e0, unk02e4, unk02e8, unk02ec;
    unsigned int unk02f0, unk02f4, unk02f8, unk02fc;
    unsigned int unk0300, unk0304, unk0308, unk030c;
    unsigned int unk0310, unk0314, unk0318, unk031c;
    unsigned int unk0320, unk0324, unk0328, unk032c;
    unsigned int unk0330, unk0334, unk0338, unk033c;
    unsigned int unk0340, unk0344, unk0348, unk034c;
    unsigned int unk0350, unk0354, unk0358, unk035c;
    unsigned int unk0360, unk0364, unk0368, unk036c;
    unsigned int unk0370, unk0374, unk0378, unk037c;
    unsigned int unk0380, unk0384, unk0388, unk038c;
    unsigned int unk0390, unk0394, unk0398, unk039c;
    unsigned int unk03a0, unk03a4, unk03a8, unk03ac;
    unsigned int unk03b0, unk03b4, unk03b8, unk03bc;
    unsigned int unk03c0, unk03c4, unk03c8, unk03cc;
    unsigned int unk03d0, unk03d4, unk03d8, unk03dc;
    unsigned int unk03e0, unk03e4, unk03e8, unk03ec;
    unsigned int unk03f0, unk03f4, unk03f8, unk03fc;
    unsigned int unk0400, unk0404, unk0408, unk040c;
    unsigned int unk0410, unk0414, unk0418, unk041c;
    unsigned int unk0420, unk0424, unk0428, unk042c;
    unsigned int unk0430, unk0434, unk0438, unk043c;
    unsigned int unk0440, unk0444, unk0448, unk044c;
    unsigned int unk0450, unk0454, unk0458, unk045c;
    unsigned int unk0460, unk0464, unk0468, unk046c;
    unsigned int unk0470, unk0474, unk0478, unk047c;
    unsigned int unk0480, unk0484, unk0488, unk048c;
    unsigned int unk0490, unk0494, unk0498, unk049c;
    unsigned int unk04a0, unk04a4, unk04a8, unk04ac;
    unsigned int unk04b0, unk04b4, unk04b8, unk04bc;
    unsigned int unk04c0, unk04c4, unk04c8, unk04cc;
    unsigned int unk04d0, unk04d4, unk04d8, unk04dc;
    unsigned int unk04e0, unk04e4, unk04e8, unk04ec;
    unsigned int unk04f0, unk04f4, unk04f8, unk04fc;
    unsigned int unk0500, unk0504, unk0508, unk050c;
    unsigned int unk0510, unk0514, unk0518, unk051c;
    unsigned int unk0520, unk0524, unk0528, unk052c;
    unsigned int unk0530, unk0534, unk0538, unk053c;
    unsigned int unk0540, unk0544, unk0548, unk054c;
    unsigned int unk0550, unk0554, unk0558, unk055c;
    unsigned int unk0560, unk0564, unk0568, unk056c;
    unsigned int unk0570, unk0574, unk0578, unk057c;
    unsigned int unk0580, unk0584, unk0588, unk058c;
    unsigned int unk0590, unk0594, unk0598, unk059c;
    unsigned int unk05a0, unk05a4, unk05a8, unk05ac;
    unsigned int unk05b0, unk05b4, unk05b8, unk05bc;
    unsigned int unk05c0, unk05c4, unk05c8, unk05cc;
    unsigned int unk05d0, unk05d4, unk05d8, unk05dc;
    unsigned int unk05e0, unk05e4, unk05e8, unk05ec;
    unsigned int unk05f0, unk05f4, unk05f8, unk05fc;
    unsigned int unk0600, unk0604, unk0608, unk060c;
    unsigned int unk0610, unk0614, unk0618, unk061c;
    unsigned int unk0620, unk0624, unk0628, unk062c;
    unsigned int unk0630, unk0634, unk0638, unk063c;
    unsigned int unk0640, unk0644, unk0648, unk064c;
    unsigned int unk0650, unk0654, unk0658, unk065c;
    unsigned int unk0660, unk0664, unk0668, unk066c;
    unsigned int unk0670, unk0674, unk0678, unk067c;
    unsigned int unk0680, unk0684, unk0688, unk068c;
    unsigned int unk0690, unk0694, unk0698, unk069c;
    unsigned int unk06a0, unk06a4, unk06a8, unk06ac;
    unsigned int unk06b0, unk06b4, unk06b8, unk06bc;
    unsigned int unk06c0, unk06c4, unk06c8, unk06cc;
    unsigned int unk06d0, unk06d4, unk06d8, unk06dc;
    unsigned int unk06e0, unk06e4, unk06e8, unk06ec;
    unsigned int unk06f0, unk06f4, unk06f8, unk06fc;
    unsigned int unk0700, unk0704, unk0708, unk070c;
    unsigned int unk0710, unk0714, unk0718, unk071c;
    unsigned int unk0720, unk0724, unk0728, unk072c;
    unsigned int unk0730, unk0734, unk0738, unk073c;
    unsigned int unk0740, unk0744, unk0748, unk074c;
    unsigned int unk0750, unk0754, unk0758, unk075c;
    unsigned int unk0760, unk0764, unk0768, unk076c;
    unsigned int unk0770, unk0774, unk0778, unk077c;
    unsigned int unk0780, unk0784, unk0788, unk078c;
    unsigned int unk0790, unk0794, unk0798, unk079c;
    unsigned int unk07a0, unk07a4, unk07a8, unk07ac;
    unsigned int unk07b0, unk07b4, unk07b8, unk07bc;
    unsigned int unk07c0, unk07c4, unk07c8, unk07cc;
    unsigned int unk07d0, unk07d4, unk07d8, unk07dc;
    unsigned int unk07e0, unk07e4, unk07e8, unk07ec;
    unsigned int unk07f0, unk07f4, unk07f8, unk07fc;
    unsigned int unk0800, unk0804, unk0808, unk080c;
    unsigned int unk0810, unk0814, unk0818, unk081c;
    unsigned int unk0820, unk0824, unk0828, unk082c;
    unsigned int unk0830, unk0834, unk0838, unk083c;
    unsigned int unk0840, unk0844, unk0848, unk084c;
    unsigned int unk0850, unk0854, unk0858, unk085c;
    unsigned int unk0860, unk0864, unk0868, unk086c;
    unsigned int unk0870, unk0874, unk0878, unk087c;
    unsigned int unk0880, unk0884, unk0888, unk088c;
    unsigned int unk0890, unk0894, unk0898, unk089c;
    unsigned int unk08a0, unk08a4, unk08a8, unk08ac;
    unsigned int unk08b0, unk08b4, unk08b8, unk08bc;
    unsigned int unk08c0, unk08c4, unk08c8, unk08cc;
    unsigned int unk08d0, unk08d4, unk08d8, unk08dc;
    unsigned int unk08e0, unk08e4, unk08e8, unk08ec;
    unsigned int unk08f0, unk08f4, unk08f8, unk08fc;
    unsigned int unk0900, unk0904, unk0908, unk090c;
    unsigned int unk0910, unk0914, unk0918, unk091c;
    unsigned int unk0920, unk0924, unk0928, unk092c;
    unsigned int unk0930, unk0934, unk0938, unk093c;
    unsigned int unk0940, unk0944, unk0948, unk094c;
    unsigned int unk0950, unk0954, unk0958, unk095c;
    unsigned int unk0960, unk0964, unk0968, unk096c;
    unsigned int unk0970, unk0974, unk0978, unk097c;
    unsigned int unk0980, unk0984, unk0988, unk098c;
    unsigned int unk0990, unk0994, unk0998, unk099c;
    unsigned int unk09a0, unk09a4, unk09a8, unk09ac;
    unsigned int unk09b0, unk09b4, unk09b8, unk09bc;
    unsigned int unk09c0, unk09c4, unk09c8, unk09cc;
    unsigned int unk09d0, unk09d4, unk09d8, unk09dc;
    unsigned int unk09e0, unk09e4, unk09e8, unk09ec;
    unsigned int unk09f0, unk09f4, unk09f8, unk09fc;
    unsigned int unk0a00, unk0a04, unk0a08, unk0a0c;
    unsigned int unk0a10, unk0a14, unk0a18, unk0a1c;
    unsigned int unk0a20, unk0a24, unk0a28, unk0a2c;
    unsigned int unk0a30, unk0a34, unk0a38, unk0a3c;
    unsigned int unk0a40, unk0a44, unk0a48, unk0a4c;
    unsigned int unk0a50, unk0a54, unk0a58, unk0a5c;
    unsigned int unk0a60, unk0a64, unk0a68, unk0a6c;
    unsigned int unk0a70, unk0a74, unk0a78, unk0a7c;
    unsigned int unk0a80, unk0a84, unk0a88, unk0a8c;
    unsigned int unk0a90, unk0a94, unk0a98, unk0a9c;
    unsigned int unk0aa0, unk0aa4, unk0aa8, unk0aac;
    unsigned int unk0ab0, unk0ab4, unk0ab8, unk0abc;
    unsigned int unk0ac0, unk0ac4, unk0ac8, unk0acc;
    unsigned int unk0ad0, unk0ad4, unk0ad8, unk0adc;
    unsigned int unk0ae0, unk0ae4, unk0ae8, unk0aec;
    unsigned int unk0af0, unk0af4, unk0af8, unk0afc;
    unsigned int unk0b00, unk0b04, unk0b08, unk0b0c;
    unsigned int unk0b10, unk0b14, unk0b18, unk0b1c;
    unsigned int unk0b20, unk0b24, unk0b28, unk0b2c;
    unsigned int unk0b30, unk0b34, unk0b38, unk0b3c;
    unsigned int unk0b40, unk0b44, unk0b48, unk0b4c;
    unsigned int unk0b50, unk0b54, unk0b58, unk0b5c;
    unsigned int unk0b60, unk0b64, unk0b68, unk0b6c;
    unsigned int unk0b70, unk0b74, unk0b78, unk0b7c;
    unsigned int unk0b80, unk0b84, unk0b88, unk0b8c;
    unsigned int unk0b90, unk0b94, unk0b98, unk0b9c;
    unsigned int unk0ba0, unk0ba4, unk0ba8, unk0bac;
    unsigned int unk0bb0, unk0bb4, unk0bb8, unk0bbc;
    unsigned int unk0bc0, unk0bc4, unk0bc8, unk0bcc;
    unsigned int unk0bd0, unk0bd4, unk0bd8, unk0bdc;
    unsigned int unk0be0, unk0be4, unk0be8, unk0bec;
    unsigned int unk0bf0, unk0bf4, unk0bf8, unk0bfc;
    unsigned int unk0c00, unk0c04, unk0c08, unk0c0c;
    unsigned int unk0c10, unk0c14, unk0c18, unk0c1c;
    unsigned int unk0c20, unk0c24, unk0c28, unk0c2c;
    unsigned int unk0c30, unk0c34, unk0c38, unk0c3c;
    unsigned int unk0c40, unk0c44, unk0c48, unk0c4c;
    unsigned int unk0c50, unk0c54, unk0c58, unk0c5c;
    unsigned int unk0c60, unk0c64, unk0c68, unk0c6c;
    unsigned int unk0c70, unk0c74, unk0c78, unk0c7c;
    unsigned int unk0c80, unk0c84, unk0c88, unk0c8c;
    unsigned int unk0c90, unk0c94, unk0c98, unk0c9c;
    unsigned int unk0ca0, unk0ca4, unk0ca8, unk0cac;
    unsigned int unk0cb0, unk0cb4, unk0cb8, unk0cbc;
    unsigned int unk0cc0, unk0cc4, unk0cc8, unk0ccc;
    unsigned int unk0cd0, unk0cd4, unk0cd8, unk0cdc;
    unsigned int unk0ce0, unk0ce4, unk0ce8, unk0cec;
    unsigned int unk0cf0, unk0cf4, unk0cf8, unk0cfc;
    unsigned int unk0d00, unk0d04, unk0d08, unk0d0c;
    unsigned int unk0d10, unk0d14, unk0d18, unk0d1c;
    unsigned int unk0d20, unk0d24, unk0d28, unk0d2c;
    unsigned int unk0d30, unk0d34, unk0d38, unk0d3c;
    unsigned int unk0d40, unk0d44, unk0d48, unk0d4c;
    unsigned int unk0d50, unk0d54, unk0d58, unk0d5c;
    unsigned int unk0d60, unk0d64, unk0d68, unk0d6c;
    unsigned int unk0d70, unk0d74, unk0d78, unk0d7c;
    unsigned int unk0d80, unk0d84, unk0d88, unk0d8c;
    unsigned int unk0d90, unk0d94, unk0d98, unk0d9c;
    unsigned int unk0da0, unk0da4, unk0da8, unk0dac;
    unsigned int unk0db0, unk0db4, unk0db8, unk0dbc;
    unsigned int unk0dc0, unk0dc4, unk0dc8, unk0dcc;
    unsigned int unk0dd0, unk0dd4, unk0dd8, unk0ddc;
    unsigned int unk0de0, unk0de4, unk0de8, unk0dec;
    unsigned int unk0df0, unk0df4, unk0df8, unk0dfc;
    unsigned int unk0e00, unk0e04, unk0e08, unk0e0c;
    unsigned int unk0e10, unk0e14, unk0e18, unk0e1c;
    unsigned int unk0e20, unk0e24, unk0e28, unk0e2c;
    unsigned int unk0e30, unk0e34, unk0e38, unk0e3c;
    unsigned int unk0e40, unk0e44, unk0e48, unk0e4c;
    unsigned int unk0e50, unk0e54, unk0e58, unk0e5c;
    unsigned int unk0e60, unk0e64, unk0e68, unk0e6c;
    unsigned int unk0e70, unk0e74, unk0e78, unk0e7c;
    unsigned int unk0e80, unk0e84, unk0e88, unk0e8c;
    unsigned int unk0e90, unk0e94, unk0e98, unk0e9c;
    unsigned int unk0ea0, unk0ea4, unk0ea8, unk0eac;
    unsigned int unk0eb0, unk0eb4, unk0eb8, unk0ebc;
    unsigned int unk0ec0, unk0ec4, unk0ec8, unk0ecc;
    unsigned int unk0ed0, unk0ed4, unk0ed8, unk0edc;
    unsigned int unk0ee0, unk0ee4, unk0ee8, unk0eec;
    unsigned int unk0ef0, unk0ef4, unk0ef8, unk0efc;
    unsigned int unk0f00, unk0f04, unk0f08, unk0f0c;
    unsigned int unk0f10, unk0f14, unk0f18, unk0f1c;
    unsigned int unk0f20, unk0f24, unk0f28, unk0f2c;
    unsigned int unk0f30, unk0f34, unk0f38, unk0f3c;
    unsigned int unk0f40, unk0f44, unk0f48, unk0f4c;
    unsigned int unk0f50, unk0f54, unk0f58, unk0f5c;
    unsigned int unk0f60, unk0f64, unk0f68, unk0f6c;
    unsigned int unk0f70, unk0f74, unk0f78, unk0f7c;
    unsigned int unk0f80, unk0f84, unk0f88, unk0f8c;
    unsigned int unk0f90, unk0f94, unk0f98, unk0f9c;
    unsigned int unk0fa0, unk0fa4, unk0fa8, unk0fac;
    unsigned int unk0fb0, unk0fb4, unk0fb8, unk0fbc;
    unsigned int unk0fc0, unk0fc4, unk0fc8, unk0fcc;
    unsigned int unk0fd0, unk0fd4, unk0fd8, unk0fdc;
    unsigned int unk0fe0, unk0fe4, unk0fe8, unk0fec;
    unsigned int unk0ff0, unk0ff4, unk0ff8, unk0ffc;
    unsigned int unk1000, unk1004, unk1008, unk100c;
    unsigned int unk1010, unk1014, unk1018, unk101c;
    unsigned int unk1020, unk1024, unk1028, unk102c;
    unsigned int unk1030, unk1034, unk1038, unk103c;
    unsigned int unk1040, unk1044, unk1048, unk104c;
    unsigned int unk1050, unk1054, unk1058, unk105c;
    unsigned int unk1060, unk1064, unk1068, unk106c;
    unsigned int unk1070, unk1074, unk1078, unk107c;
    unsigned int unk1080, unk1084, unk1088, unk108c;
    unsigned int unk1090, unk1094, unk1098, unk109c;
    unsigned int unk10a0, unk10a4, unk10a8, unk10ac;
    unsigned int unk10b0, unk10b4, unk10b8, unk10bc;
    unsigned int unk10c0, unk10c4, unk10c8, unk10cc;
    unsigned int unk10d0, unk10d4, unk10d8, unk10dc;
    unsigned int unk10e0, unk10e4, unk10e8, unk10ec;
    unsigned int unk10f0, unk10f4, unk10f8, unk10fc;
    unsigned int unk1100, unk1104, unk1108, unk110c;
    unsigned int unk1110, unk1114, unk1118, unk111c;
    unsigned int unk1120, unk1124, unk1128, unk112c;
    unsigned int unk1130, unk1134, unk1138, unk113c;
    unsigned int unk1140, unk1144, unk1148, unk114c;
    unsigned int unk1150, unk1154, unk1158, unk115c;
    unsigned int unk1160, unk1164, unk1168, unk116c;
    unsigned int unk1170, unk1174, unk1178, unk117c;
    unsigned int unk1180, unk1184, unk1188, unk118c;
    unsigned int unk1190, unk1194, unk1198, unk119c;
    unsigned int unk11a0, unk11a4, unk11a8, unk11ac;
    unsigned int unk11b0, unk11b4, unk11b8, unk11bc;
    unsigned int unk11c0, unk11c4, unk11c8, unk11cc;
    unsigned int unk11d0, unk11d4, unk11d8, unk11dc;
    unsigned int unk11e0, unk11e4, unk11e8, unk11ec;
    unsigned int unk11f0, unk11f4, unk11f8, unk11fc;
    unsigned int unk1200, unk1204, unk1208, unk120c;
    unsigned int unk1210, unk1214, unk1218, unk121c;
    unsigned int unk1220, unk1224, unk1228, unk122c;
    unsigned int unk1230, unk1234, unk1238, unk123c;
    unsigned int unk1240, unk1244, unk1248, unk124c;
    unsigned int unk1250, unk1254, unk1258, unk125c;
    unsigned int unk1260, unk1264, unk1268, unk126c;
    unsigned int unk1270, unk1274, unk1278, unk127c;
    unsigned int unk1280, unk1284, unk1288, unk128c;
    unsigned int unk1290, unk1294, unk1298, unk129c;
    unsigned int unk12a0, unk12a4, unk12a8, unk12ac;
    unsigned int unk12b0, unk12b4, unk12b8, unk12bc;
    unsigned int unk12c0, unk12c4, unk12c8, unk12cc;
    unsigned int unk12d0, unk12d4, unk12d8, unk12dc;
    unsigned int unk12e0, unk12e4, unk12e8, unk12ec;
    unsigned int unk12f0, unk12f4, unk12f8, unk12fc;
    unsigned int unk1300, unk1304, unk1308, unk130c;
    unsigned int unk1310, unk1314, unk1318, unk131c;
    unsigned int unk1320, unk1324, unk1328, unk132c;
    unsigned int unk1330, unk1334, unk1338, unk133c;
    unsigned int unk1340, unk1344, unk1348, unk134c;
    unsigned int unk1350, unk1354, unk1358, unk135c;
    unsigned int unk1360, unk1364, unk1368, unk136c;
    unsigned int unk1370, unk1374, unk1378, unk137c;
    unsigned int unk1380, unk1384, unk1388, unk138c;
    unsigned int unk1390, unk1394, unk1398, unk139c;
    unsigned int unk13a0, unk13a4, unk13a8, unk13ac;
    unsigned int unk13b0, unk13b4, unk13b8, unk13bc;
    unsigned int unk13c0, unk13c4, unk13c8, unk13cc;
    unsigned int unk13d0, unk13d4, unk13d8, unk13dc;
    unsigned int unk13e0, unk13e4, unk13e8, unk13ec;
    unsigned int unk13f0, unk13f4, unk13f8, unk13fc;
    unsigned int unk1400, unk1404, unk1408, unk140c;
    unsigned int unk1410, unk1414, unk1418, unk141c;
    unsigned int unk1420, unk1424, unk1428, unk142c;
    unsigned int unk1430, unk1434, unk1438, unk143c;
    unsigned int unk1440, unk1444, unk1448, unk144c;
    unsigned int unk1450, unk1454, unk1458, unk145c;
    unsigned int unk1460, unk1464, unk1468, unk146c;
    unsigned int unk1470, unk1474, unk1478, unk147c;
    unsigned int unk1480, unk1484, unk1488, unk148c;
    unsigned int unk1490, unk1494, unk1498, unk149c;
    unsigned int unk14a0, unk14a4, unk14a8, unk14ac;
    unsigned int unk14b0, unk14b4, unk14b8, unk14bc;
    unsigned int unk14c0, unk14c4, unk14c8, unk14cc;
    unsigned int unk14d0, unk14d4, unk14d8, unk14dc;
    unsigned int unk14e0, unk14e4, unk14e8, unk14ec;
    unsigned int unk14f0, unk14f4, unk14f8, unk14fc;
    unsigned int unk1500, unk1504, unk1508, unk150c;
    unsigned int unk1510, unk1514, unk1518, unk151c;
    unsigned int unk1520, unk1524, unk1528, unk152c;
    unsigned int unk1530, unk1534, unk1538, unk153c;
    unsigned int unk1540, unk1544, unk1548, unk154c;
    unsigned int unk1550, unk1554, unk1558, unk155c;
    unsigned int unk1560, unk1564, unk1568, unk156c;
    unsigned int unk1570, unk1574, unk1578, unk157c;
    unsigned int unk1580, unk1584, unk1588, unk158c;
    unsigned int unk1590, unk1594, unk1598, unk159c;
    unsigned int unk15a0, unk15a4, unk15a8, unk15ac;
    unsigned int unk15b0, unk15b4, unk15b8, unk15bc;
    unsigned int unk15c0, unk15c4, unk15c8, unk15cc;
    unsigned int unk15d0, unk15d4, unk15d8, unk15dc;
    unsigned int unk15e0, unk15e4, unk15e8, unk15ec;
    unsigned int unk15f0, unk15f4, unk15f8, unk15fc;
    unsigned int unk1600, unk1604, unk1608, unk160c;
    unsigned int unk1610, unk1614, unk1618, unk161c;
    unsigned int unk1620, unk1624, unk1628, unk162c;
    unsigned int unk1630, unk1634, unk1638, unk163c;
    unsigned int unk1640, unk1644, unk1648, unk164c;
    unsigned int unk1650, unk1654, unk1658, unk165c;
    unsigned int unk1660, unk1664, unk1668, unk166c;
    unsigned int unk1670, unk1674, unk1678, unk167c;
    unsigned int unk1680, unk1684, unk1688, unk168c;
    unsigned int unk1690, unk1694, unk1698, unk169c;
    unsigned int unk16a0, unk16a4, unk16a8, unk16ac;
    unsigned int unk16b0, unk16b4, unk16b8, unk16bc;
    unsigned int unk16c0, unk16c4, unk16c8, unk16cc;
    unsigned int unk16d0, unk16d4, unk16d8, unk16dc;
    unsigned int unk16e0, unk16e4, unk16e8, unk16ec;
    unsigned int unk16f0, unk16f4, unk16f8, unk16fc;
    unsigned int unk1700, unk1704, unk1708, unk170c;
    unsigned int unk1710, unk1714, unk1718, unk171c;
    unsigned int unk1720, unk1724, unk1728, unk172c;
    unsigned int unk1730, unk1734, unk1738, unk173c;
    unsigned int unk1740, unk1744, unk1748, unk174c;
    unsigned int unk1750, unk1754, unk1758, unk175c;
    unsigned int unk1760, unk1764, unk1768, unk176c;
    unsigned int unk1770, unk1774, unk1778, unk177c;
    unsigned int unk1780, unk1784, unk1788, unk178c;
    unsigned int unk1790, unk1794, unk1798, unk179c;
    unsigned int unk17a0, unk17a4, unk17a8, unk17ac;
    unsigned int unk17b0, unk17b4, unk17b8, unk17bc;
    unsigned int unk17c0, unk17c4, unk17c8, unk17cc;
    unsigned int unk17d0, unk17d4, unk17d8, unk17dc;
    unsigned int unk17e0, unk17e4, unk17e8, unk17ec;
    unsigned int unk17f0, unk17f4, unk17f8, unk17fc;
    unsigned int unk1800, unk1804, unk1808, unk180c;
    unsigned int unk1810, unk1814, unk1818, unk181c;
    unsigned int unk1820, unk1824, unk1828, unk182c;
    unsigned int unk1830, unk1834, unk1838, unk183c;
    unsigned int unk1840, unk1844, unk1848, unk184c;
    unsigned int unk1850, unk1854, unk1858, unk185c;
    unsigned int unk1860, unk1864, unk1868, unk186c;
    unsigned int unk1870, unk1874, unk1878, unk187c;
    unsigned int unk1880, unk1884, unk1888, unk188c;
    unsigned int unk1890, unk1894, unk1898, unk189c;
    unsigned int unk18a0, unk18a4, unk18a8, unk18ac;
    unsigned int unk18b0, unk18b4, unk18b8, unk18bc;
    unsigned int unk18c0, unk18c4, unk18c8, unk18cc;
    unsigned int unk18d0, unk18d4, unk18d8, unk18dc;
    unsigned int unk18e0, unk18e4, unk18e8, unk18ec;
    unsigned int unk18f0, unk18f4, unk18f8, unk18fc;
    unsigned int unk1900, unk1904, unk1908, unk190c;
    unsigned int unk1910, unk1914, unk1918, unk191c;
    unsigned int unk1920, unk1924, unk1928, unk192c;
    unsigned int unk1930, unk1934, unk1938, unk193c;
    unsigned int unk1940, unk1944, unk1948, unk194c;
    unsigned int unk1950, unk1954, unk1958, unk195c;
    unsigned int unk1960, unk1964, unk1968, unk196c;
    unsigned int unk1970, unk1974, unk1978, unk197c;
    unsigned int unk1980, unk1984, unk1988, unk198c;
    unsigned int unk1990, unk1994, unk1998, unk199c;
    unsigned int unk19a0, unk19a4, unk19a8, unk19ac;
    unsigned int unk19b0, unk19b4, unk19b8, unk19bc;
    unsigned int unk19c0, unk19c4, unk19c8, unk19cc;
    unsigned int unk19d0, unk19d4, unk19d8, unk19dc;
    unsigned int unk19e0, unk19e4, unk19e8, unk19ec;
    unsigned int unk19f0, unk19f4, unk19f8, unk19fc;
    unsigned int unk1a00, unk1a04, unk1a08, unk1a0c;
    unsigned int unk1a10, unk1a14, unk1a18, unk1a1c;
    unsigned int unk1a20, unk1a24, unk1a28, unk1a2c;
    unsigned int unk1a30, unk1a34, unk1a38, unk1a3c;
    unsigned int unk1a40, unk1a44, unk1a48, unk1a4c;
    unsigned int unk1a50, unk1a54, unk1a58, unk1a5c;
    unsigned int unk1a60, unk1a64, unk1a68, unk1a6c;
    unsigned int unk1a70, unk1a74, unk1a78, unk1a7c;
    unsigned int unk1a80, unk1a84, unk1a88, unk1a8c;
    unsigned int unk1a90, unk1a94, unk1a98, unk1a9c;
    unsigned int unk1aa0, unk1aa4, unk1aa8, unk1aac;
    unsigned int unk1ab0, unk1ab4, unk1ab8, unk1abc;
    unsigned int unk1ac0, unk1ac4, unk1ac8, unk1acc;
    unsigned int unk1ad0, unk1ad4, unk1ad8, unk1adc;
    unsigned int unk1ae0, unk1ae4, unk1ae8, unk1aec;
    unsigned int unk1af0, unk1af4, unk1af8, unk1afc;
    unsigned int unk1b00, unk1b04, unk1b08, unk1b0c;
    unsigned int unk1b10, unk1b14, unk1b18, unk1b1c;
    unsigned int unk1b20, unk1b24, unk1b28, unk1b2c;
    unsigned int unk1b30, unk1b34, unk1b38, unk1b3c;
    unsigned int unk1b40, unk1b44, unk1b48, unk1b4c;
    unsigned int unk1b50, unk1b54, unk1b58, unk1b5c;
    unsigned int unk1b60, unk1b64, unk1b68, unk1b6c;
    unsigned int unk1b70, unk1b74, unk1b78, unk1b7c;
    unsigned int unk1b80, unk1b84, unk1b88, unk1b8c;
    unsigned int unk1b90, unk1b94, unk1b98, unk1b9c;
    unsigned int unk1ba0, unk1ba4, unk1ba8, unk1bac;
    unsigned int unk1bb0, unk1bb4, unk1bb8, unk1bbc;
    unsigned int unk1bc0, unk1bc4, unk1bc8, unk1bcc;
    unsigned int unk1bd0, unk1bd4, unk1bd8, unk1bdc;
    unsigned int unk1be0, unk1be4, unk1be8, unk1bec;
    unsigned int unk1bf0, unk1bf4, unk1bf8, unk1bfc;
    unsigned int unk1c00, unk1c04, unk1c08, unk1c0c;
    unsigned int unk1c10, unk1c14, unk1c18, unk1c1c;
    unsigned int unk1c20, unk1c24, unk1c28, unk1c2c;
    unsigned int unk1c30, unk1c34, unk1c38, unk1c3c;
    unsigned int unk1c40, unk1c44, unk1c48, unk1c4c;
    unsigned int unk1c50, unk1c54, unk1c58, unk1c5c;
    unsigned int unk1c60, unk1c64, unk1c68, unk1c6c;
    unsigned int unk1c70, unk1c74, unk1c78, unk1c7c;
    unsigned int unk1c80, unk1c84, unk1c88, unk1c8c;
    unsigned int unk1c90, unk1c94, unk1c98, unk1c9c;
    unsigned int unk1ca0, unk1ca4, unk1ca8, unk1cac;
    unsigned int unk1cb0, unk1cb4, unk1cb8, unk1cbc;
    unsigned int unk1cc0, unk1cc4, unk1cc8, unk1ccc;
    unsigned int unk1cd0, unk1cd4, unk1cd8, unk1cdc;
    unsigned int unk1ce0, unk1ce4, unk1ce8, unk1cec;
    unsigned int unk1cf0, unk1cf4, unk1cf8, unk1cfc;
    unsigned int unk1d00, unk1d04, unk1d08, unk1d0c;
    unsigned int unk1d10, unk1d14, unk1d18, unk1d1c;
    unsigned int unk1d20, unk1d24, unk1d28, unk1d2c;
    unsigned int unk1d30, unk1d34, unk1d38, unk1d3c;
    unsigned int unk1d40, unk1d44, unk1d48, unk1d4c;
    unsigned int unk1d50, unk1d54, unk1d58, unk1d5c;
    unsigned int unk1d60, unk1d64, unk1d68, unk1d6c;
    unsigned int unk1d70, unk1d74, unk1d78, unk1d7c;
    unsigned int unk1d80, unk1d84, unk1d88, unk1d8c;
    unsigned int unk1d90, unk1d94, unk1d98, unk1d9c;
    unsigned int unk1da0, unk1da4, unk1da8, unk1dac;
    unsigned int unk1db0, unk1db4, unk1db8, unk1dbc;
    unsigned int unk1dc0, unk1dc4, unk1dc8, unk1dcc;
    unsigned int unk1dd0, unk1dd4, unk1dd8, unk1ddc;
    unsigned int unk1de0, unk1de4, unk1de8, unk1dec;
    unsigned int unk1df0, unk1df4, unk1df8, unk1dfc;
    unsigned int unk1e00, unk1e04, unk1e08, unk1e0c;
    unsigned int unk1e10, unk1e14, unk1e18, unk1e1c;
    unsigned int unk1e20, unk1e24, unk1e28, unk1e2c;
    unsigned int unk1e30, unk1e34, unk1e38, unk1e3c;
    unsigned int unk1e40, unk1e44, unk1e48, unk1e4c;
    unsigned int unk1e50, unk1e54, unk1e58, unk1e5c;
    unsigned int unk1e60, unk1e64, unk1e68, unk1e6c;
    unsigned int unk1e70, unk1e74, unk1e78, unk1e7c;
    unsigned int unk1e80, unk1e84, unk1e88, unk1e8c;
    unsigned int unk1e90, unk1e94, unk1e98, unk1e9c;
    unsigned int unk1ea0, unk1ea4, unk1ea8, unk1eac;
    unsigned int unk1eb0, unk1eb4, unk1eb8, unk1ebc;
    unsigned int unk1ec0, unk1ec4, unk1ec8, unk1ecc;
    unsigned int unk1ed0, unk1ed4, unk1ed8, unk1edc;
    unsigned int unk1ee0, unk1ee4, unk1ee8, unk1eec;
    unsigned int unk1ef0, unk1ef4, unk1ef8, unk1efc;
    unsigned int unk1f00, unk1f04, unk1f08, unk1f0c;
    unsigned int unk1f10, unk1f14, unk1f18, unk1f1c;
    unsigned int unk1f20, unk1f24, unk1f28, unk1f2c;
    unsigned int unk1f30, unk1f34, unk1f38, unk1f3c;
    unsigned int unk1f40, unk1f44, unk1f48, unk1f4c;
    unsigned int unk1f50, unk1f54, unk1f58, unk1f5c;
    unsigned int unk1f60, unk1f64, unk1f68, unk1f6c;
    unsigned int unk1f70, unk1f74, unk1f78, unk1f7c;
    unsigned int unk1f80, unk1f84, unk1f88, unk1f8c;
    unsigned int unk1f90, unk1f94, unk1f98, unk1f9c;
    unsigned int unk1fa0, unk1fa4, unk1fa8, unk1fac;
    unsigned int unk1fb0, unk1fb4, unk1fb8, unk1fbc;
    unsigned int unk1fc0, unk1fc4, unk1fc8, unk1fcc;
    unsigned int unk1fd0, unk1fd4, unk1fd8, unk1fdc;
    unsigned int unk1fe0, unk1fe4, unk1fe8, unk1fec;
    unsigned int unk1ff0, unk1ff4, unk1ff8, unk1ffc;
    unsigned int unk2000, unk2004, unk2008, unk200c;
    unsigned int unk2010, unk2014, unk2018, unk201c;
    unsigned int unk2020, unk2024, unk2028, unk202c;
    unsigned int unk2030, unk2034, unk2038, unk203c;
    unsigned int unk2040, unk2044, unk2048, unk204c;
    unsigned int unk2050, unk2054, unk2058, unk205c;
    unsigned int unk2060, unk2064, unk2068, unk206c;
    unsigned int unk2070, unk2074, unk2078, unk207c;
    unsigned int unk2080, unk2084, unk2088, unk208c;
    unsigned int unk2090, unk2094, unk2098, unk209c;
    BigSearch();
    ~BigSearch();
};

struct Ctx12
{
    float x;
    float y;
    float z;
    float w;
};

struct Pt3
{
    float x;
    float y;
    float z;
    Pt3();
};

Pt3 __cdecl FUN_006bbad0(NiPoint3* a, NiPoint3* b, NiPoint3* c);

// @fnv 0x006d34d0
bool __cdecl FUN_006d34d0(void* req, NiPoint3* out)
{
    if (!reinterpret_cast<::NLLocation *>((((::PathingLocation_r006d34d0 *)(::GetOffsetC((std::intptr_t)(((ReqX*)req)))))))->UpdateMeshLocation())
        return false;
    NavMeshPtr navPtr;
    unsigned short tri3 = 0xffff;
    if (!reinterpret_cast<::PathingLocation *>((((::PathingLocation_r006d34d0 *)(::GetOffsetC((std::intptr_t)(((ReqX*)req)))))))->FindNavMeshTriangle(navPtr, tri3))
        return false;
    Info info2;
    info2.mesh = (NavMesh*)((NavPtrX*)&navPtr)->FUN_00458b50();
    info2.tri = tri3;
    BigSearch big3;
    ArrD arrD3(0x20, 0, 0);
    ArrE arrE3(0x20, 0, 0);
    if (!reinterpret_cast<::NavMeshSearch *>(&(big3))->Search((::PathingRequest *)(req), (::NavMeshNodeInfo *)(::Info *)(&info2), (::PathingSolution *)(::ArrD *)(&arrD3), &arrE3))
        return false;
    Elem20 elem = *((::Elem20 *)(reinterpret_cast<::FUN_006b3160_shell *>(&(arrD3))->FUN_006b3160(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(arrD3))->GetName())) - 1)));
    Pt3 pts[3];
    TriX* triPtr7 = ((::TriX *)(reinterpret_cast<::NavMesh *>((((MeshX_ctxr*)elem.mesh)))->GetTriangle(elem.tri)));
    *(NiPoint3*)&pts[0] = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((((MeshX_ctxr*)elem.mesh)))->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triPtr7))->FUN_005582d0(0))));
    *(NiPoint3*)&pts[1] = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((((MeshX_ctxr*)elem.mesh)))->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triPtr7))->FUN_005582d0(1))));
    *(NiPoint3*)&pts[2] = (*(const ::NiPoint3 *)(reinterpret_cast<::FUN_0068f0a0_shell *>((((MeshX_ctxr*)elem.mesh)))->FUN_0068f0a0(reinterpret_cast<::FUN_005582d0_shell *>((triPtr7))->FUN_005582d0(2))));
    Pt3 kCentroid = FUN_006bbad0((NiPoint3*)&pts[0], (NiPoint3*)&pts[1], (NiPoint3*)&pts[2]);
    *out = (const NiPoint3&)kCentroid;
    return true;
}



struct RotationMatrix
{
    float entry[3][3];
    RotationMatrix();
    NiPoint3 FUN_004b4500(const NiPoint3* axis);
};

// A native const Point3 member consumes only its receiver in ECX.

bool __cdecl FUN_006d7350(PathingLocation&, PathingLocation&, PathingLocation*, Pathing::CheckLineOfSightFilter*);

// @fnv 0x006da420
NiPoint3 __cdecl FUN_006da420(float angle, const PathingLocation& sourceLocation, float width)
{
    RotationMatrix seed_2;
    reinterpret_cast<::FUN_004a0c90_shell *>(&(seed_2))->FUN_004a0c90(angle);
    NiPoint3 base8 = seed_2.FUN_004b4500(&DAT_011a9478);
    PathingLocation mainLocation(sourceLocation);
    NiPoint3 mainPoint4 = reinterpret_cast<::TaskQueueInterface *>((void *)&(mainLocation))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    NiPoint3 endPoint6 = mainPoint4 - base8 * DAT_01032adc;
    PathingLocation hit;
    if (!Pathing::FindPathingLocation(mainLocation, endPoint6, &hit, 0))
        endPoint6 = reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    NiPoint3 difference5 = endPoint6 - mainPoint4;
    NiPoint3 offset_2 = difference5.CrossProduct(DAT_011a9484) * width;
    PathingLocation leftStart4(mainPoint4 - offset_2, mainLocation);
    PathingLocation leftEnd(endPoint6 - offset_2, mainLocation);
    if (!FUN_006d7350(leftStart4, leftEnd, &hit, 0))
    {
        if (reinterpret_cast<::TESCombatStyle *>((void *)&ResultSlot<::NiPoint3>(reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()) - reinterpret_cast<::TaskQueueInterface *>((void *)&(leftStart4))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)&(difference5))->UpdateCombatStyle())
            endPoint6 = reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    }
    PathingLocation rightStartX(mainPoint4 + offset_2, mainLocation);
    PathingLocation rightEnd(endPoint6 + offset_2, mainLocation);
    if (!FUN_006d7350(rightStartX, rightEnd, &hit, 0))
    {
        if (reinterpret_cast<::TESCombatStyle *>((void *)&ResultSlot<::NiPoint3>(reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(ResultSlot<::NiPoint3>()) - reinterpret_cast<::TaskQueueInterface *>((void *)&(rightStartX))->QueueActorAnimationTask(ResultSlot<::NiPoint3>())))->UpdateCombatStyle() < reinterpret_cast<::TESCombatStyle *>((void *)&(difference5))->UpdateCombatStyle())
            endPoint6 = reinterpret_cast<::TaskQueueInterface *>((void *)&(hit))->QueueActorAnimationTask(ResultSlot<::NiPoint3>());
    }
    return mainPoint4 - endPoint6;
}

#include "generated/data/fallout_shared/pathfinding/pathfind.inc"
#include "generated/data/fallout_shared/pathfinding/pathfind_ctx_variant.inc"
