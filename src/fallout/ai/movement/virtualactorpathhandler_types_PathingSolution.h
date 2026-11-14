// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PATHINGSOLUTION_H
#define FNV_PATHINGSOLUTION_H

#include "fnv/symbols_005a4000.h"
#include "layout_support.h"
#include "NiPoint3.h"
#include "NiRefObject.h"
#include "PathingLocation.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class SineCosine;
class CircularArc;
class CompactNavMeshEdgeReference;
class NavMesh;
class NavMeshInfoSearchNode;
class NavMeshTrianglePathEntry;
class ParentSpaceNode;
class PathSmootherPOVDebugArcRecord;
class PathSmootherPOVDebugTests;
class PathSmootherPOVDebugSphereTest;
class PathSmootherPOVDebugRay;
class PathingInfo;
class PathingInfoEntry;
class PathingInfoParams;
class PathingGraphNode;
class PathingSolution;
struct LocationDescriptor;
class BaseProcess;
class Sphere;
class TeleportLink;
class PathingPath;
class PacketNodeRecord;
enum PATHING_INFO_TYPE
{
    PATHING_INFO_TYPE_PATHING_INFO_TYPE_NONE = 0,
    PATHING_INFO_TYPE_PATHING_INFO_TYPE_MESSAGE = 1,
    PATHING_INFO_TYPE_PATHING_INFO_TYPE_WARNING = 2,
    PATHING_INFO_TYPE_PATHING_INFO_TYPE_FAILLURE = 3
};
enum PATHING_MESSAGE_ID
{
    PATHING_MESSAGE_ID_PMSG_INVALID_INDEX = -1,
    PATHING_MESSAGE_ID_PMSG_BUILDING_NEW_PATH = 0,
    PATHING_MESSAGE_ID_PMSG_ORIGIN = 1,
    PATHING_MESSAGE_ID_PMSG_DESTINATION = 2,
    PATHING_MESSAGE_ID_PMSG_RESOLVING_NAVMESH_INFO = 3,
    PATHING_MESSAGE_ID_PMSG_START_GOAL_SAME_NAVMESH = 4,
    PATHING_MESSAGE_ID_PMSG_START_GOAL_DIFFERENT_NAVMESH = 5,
    PATHING_MESSAGE_ID_PMSG_NAVMESH_INFO_SEARCH_SUCCESS = 6,
    PATHING_MESSAGE_ID_PMSG_USING_TELEPORT_DOORS = 7,
    PATHING_MESSAGE_ID_PMSG_TELEPORT_SEARCH_SUCCESS = 8,
    PATHING_MESSAGE_ID_PMSG_BUILDING_DETAILED_PATH = 9,
    PATHING_MESSAGE_ID_PMSG_PATH_BUILT_OK = 10,
    PATHING_MESSAGE_ID_PMSG_UPDATING_PATH = 11,
    PATHING_MESSAGE_ID_PMSG_REBUILT_DETAILED_PATH_OK = 12,
    PATHING_MESSAGE_ID_PMSG_USING_NAVMESH = 13,
    PATHING_MESSAGE_ID_PMSG_NAVMESH_SEARCH_SUCCESS = 14,
    PATHING_MESSAGE_ID_PMSG_NAVMESH_SEARCH_START = 15,
    PATHING_MESSAGE_ID_PMSG_NAVMESH_SEARCH_GOAL = 16,
    PATHING_MESSAGE_ID_PMSG_STRAIGHT_LINE_CHECK_RUNNING = 17,
    PATHING_MESSAGE_ID_PMSG_STRAIGHT_LINE_CHECK_SUCCESS = 18,
    PATHING_MESSAGE_ID_PMSG_STRAIGHT_LINE_CHECK_FAIL = 19,
    PATHING_MESSAGE_ID_PMSG_TRIANGLE_ASTAR_RUNNING_PASS = 20,
    PATHING_MESSAGE_ID_PMSG_TRIANGLE_ASTAR_RUNNING = 21,
    PATHING_MESSAGE_ID_PMSG_TRIANGLE_ASTAR_START = 22,
    PATHING_MESSAGE_ID_PMSG_TRIANGLE_ASTAR_GOAL = 23,
    PATHING_MESSAGE_ID_PMSG_TRIANGLE_ASTAR_SUCCESS = 24,
    PATHING_MESSAGE_ID_PMSG_FINDING_CLOSEST_OPEN_EDGE = 25,
    PATHING_MESSAGE_ID_PMSG_FOUND_CLOSEST_OPEN_EDGE = 26,
    PATHING_MESSAGE_ID_PMSG_VIRTUALNODE_NO_LOCATION_FIND_ENTRY = 27,
    PATHING_MESSAGE_ID_PMSG_VIRTUALNODE_NO_LOCATION_FIND_EXIT = 28,
    PATHING_MESSAGE_ID_PMSG_VIRTUALNODE_NO_LOCATION_FIND_OPEN_EDGE = 29,
    PATHING_MESSAGE_ID_PMSG_VIRTUALNODE_HAS_LOCATION_FIND_OPEN_EDGE = 30,
    PATHING_MESSAGE_ID_PMSG_SEARCHING_PORTALS = 31,
    PATHING_MESSAGE_ID_PMSG_FOUND_PORTAL = 32,
    PATHING_MESSAGE_ID_PMSG_START_GOAL_NOT_ON_NAVMESH = 33,
    PATHING_MESSAGE_ID_PMSG_START_NOT_ON_NAVMESH = 34,
    PATHING_MESSAGE_ID_PMSG_GOAL_NOT_ON_NAVMESH = 35,
    PATHING_MESSAGE_ID_PMSG_VIRTUAL_NODES_NO_INFO = 36,
    PATHING_MESSAGE_ID_PMSG_START_NOT_ON_TRIANGLE = 37,
    PATHING_MESSAGE_ID_PMSG_GOAL_NOT_ON_TRIANGLE = 38,
    PATHING_MESSAGE_ID_PMSG_PATHSMOOTHER_FAIL_AVOID = 39,
    PATHING_MESSAGE_ID_PMSG_HIGH_PATH_FAIL = 40,
    PATHING_MESSAGE_ID_PMSG_NAVMESH_INFO_SEARCH_FAIL = 41,
    PATHING_MESSAGE_ID_PMSG_TELEPORT_SEARCH_FAIL = 42,
    PATHING_MESSAGE_ID_PMSG_DETAILED_PATH_FAIL = 43,
    PATHING_MESSAGE_ID_PMSG_DETAILED_PATH_FAIL_VIRTUALNODES = 44,
    PATHING_MESSAGE_ID_PMSG_NAVMESH_SEARCH_FAIL_VIRTUALNODES = 45,
    PATHING_MESSAGE_ID_PMSG_BAD_FIRST_SEARCH_NODE = 46,
    PATHING_MESSAGE_ID_PMSG_BAD_LAST_SEARCH_NODE = 47,
    PATHING_MESSAGE_ID_PMSG_NO_START_TRIANGLE = 48,
    PATHING_MESSAGE_ID_PMSG_NO_GOAL_TRIANGLE = 49,
    PATHING_MESSAGE_ID_PMSG_PATHSMOOTHER_FAIL = 50,
    PATHING_MESSAGE_ID_PMSG_TRIANGLE_ASTAR_FAIL = 51,
    PATHING_MESSAGE_ID_PMSG_START_NAVMESH_NOT_LOADED = 52,
    PATHING_MESSAGE_ID_PMSG_GOAL_NAVMESH_NOT_LOADED = 53,
    PATHING_MESSAGE_ID_PMSG_NO_OPEN_EDGE = 54,
    PATHING_MESSAGE_ID_PMSG_RUNNING_TRIANGLE_ASTAR = 55,
    PATHING_MESSAGE_ID_PMSG_TRIANGLE_ASTAR_RETURNED_NODES = 56,
    PATHING_MESSAGE_ID_PMSG_GOAL_TOO_FAR = 57,
    PATHING_MESSAGE_ID_PMSG_NO_INCOMPLETE_PATH_ALLOWED = 58,
    PATHING_MESSAGE_ID_PMSG_USING_INCOMPLETE_PATH = 59,
    PATHING_MESSAGE_ID_PMSG_RUNNIN_PATHSMOOTHER = 60,
    PATHING_MESSAGE_ID_PMSG_PATHSMOOTHER_FAIL_TOO_FAR = 61,
    PATHING_MESSAGE_ID_PMSG_TRY_RAYCAST = 62,
    PATHING_MESSAGE_ID_PMSG_RAYCAST_SUCCESS = 63,
    PATHING_MESSAGE_ID_PMSG_RAYCAST_FAILURE = 64,
    PATHING_MESSAGE_ID_PMSG_NUM_MESSAGE_IDS = 65
};
enum PATHING_PARAMETER_ID
{
    PATHING_PARAMETER_ID_PPAR_NONE = 0,
    PATHING_PARAMETER_ID_PPAR_INT = 1,
    PATHING_PARAMETER_ID_PPAR_INT_INT = 2,
    PATHING_PARAMETER_ID_PPAR_INT_INT_INT = 3,
    PATHING_PARAMETER_ID_PPAR_PATHING_LOCATION = 4
};
enum PathSmootherPOVDebugRayTest__Result
{
    PathSmootherPOVDebugRayTest__Result_RESULT_PASS = 0,
    PathSmootherPOVDebugRayTest__Result_RESULT_FAIL = 1,
    PathSmootherPOVDebugRayTest__Result_RESULT_INFINITE_LOOP = 2
};
enum ANGLE_DIRECTION
{
    ANGLE_DIRECTION_AD_NONE = -1,
    ANGLE_DIRECTION_AD_CCW = 0,
    ANGLE_DIRECTION_AD_CW = 1,
    ANGLE_DIRECTION_AD_COUNT = 2
};
enum PathSmootherPOVDebugArcTest__Result
{
    PathSmootherPOVDebugArcTest__Result_RESULT_PASS = 0,
    PathSmootherPOVDebugArcTest__Result_RESULT_FAIL = 1,
    PathSmootherPOVDebugArcTest__Result_RESULT_INFINITE_LOOP = 2
};
class PathingInfoParams
{
  public:
    int ints[3];               // +0x0, 12 bytes
    PathingLocation location;  // +0xC, 40 bytes
    // PathingInfoParams
    // const PathingInfoParams& __cdecl PathingInfoParams::*(const PathingInfoParams&)
    // void __cdecl PathingInfoParams::*()
    // void __cdecl PathingInfoParams::*()
    // void* __cdecl PathingInfoParams::*(unsigned int)
};
class PathingInfoEntry
{
  public:
    PATHING_INFO_TYPE InfoType;    // +0x0, 4 bytes
    PATHING_MESSAGE_ID MessageID;  // +0x4, 4 bytes
    PATHING_PARAMETER_ID ParamID;  // +0x8, 4 bytes
    PathingInfoParams Params;      // +0xC, 52 bytes
    // PathingInfoEntry
    // PathingInfoEntry& __cdecl PathingInfoEntry::*(const PathingInfoEntry&)
    // void __cdecl PathingInfoEntry::*(IDebugText*)
    // void __cdecl PathingInfoEntry::*(char*, int)
    // void __cdecl PathingInfoEntry::*()
    // void* __cdecl PathingInfoEntry::*(unsigned int)
};
class ParentSpaceNode
{
  public:
    bool m_bIsWorldspace;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    TESWorldSpace* m_pContainingWorldspace;  // +0x4, 4 bytes
    TESObjectCELL* m_pReferenceCell;         // +0x8, 4 bytes
};
class TeleportLink
{
  public:
    TESObjectREFR* pPathNodeDoor;             // +0x0, 4 bytes
    NiPoint3 m_kDestinationPosition;  // +0x4, 12 bytes
    // void __cdecl TeleportLink::*()
};
class PathingPath
{
  public:
    BSSimpleArray<ParentSpaceNode, 1024> Spaces;  // +0x0, 16 bytes
    BSSimpleArray<TeleportLink, 1024> Doors;      // +0x10, 16 bytes
    NiPoint3 Start;                               // +0x20, 12 bytes
    NiPoint3 End;                                 // +0x2C, 12 bytes
    // PathingPath
    // void __cdecl PathingPath::*()
    // PathingPath& __cdecl PathingPath::*(const PathingPath&)
    // void __cdecl PathingPath::*()
    // float __cdecl PathingPath::*()
    // void* __cdecl PathingPath::*(unsigned int)
};
class PathingInfo
{
  public:
    BSSimpleArray<PathingInfoEntry, 1024> Items;                      // +0x0, 16 bytes
    unsigned int m_uiNavMeshInfoCount;                                // +0x10, 4 bytes
    BSSimpleArray<const NavMeshInfo*, 1024> NavMeshInfoPointerArray;  // +0x14, 16 bytes
    BSSimpleArray<TESObjectREFR*, 1024> TESObjectReferenceArray;      // +0x24, 16 bytes
    PathingPath NavMeshReferenceCollection;                           // +0x34, 56 bytes
};
class NavMeshInfoSearchNode
{
  public:
    const NavMeshInfo* pInfo;  // +0x0, 4 bytes
    float m_fPathingCostCur;               // +0x4, 4 bytes
    float m_fCost;             // +0x8, 4 bytes
};
class CompactNavMeshEdgeReference
{
  public:
    NavMesh* m_pLocationNavMesh;    // +0x0, 4 bytes
    unsigned short m_usTriangleID;  // +0x4, 2 bytes
    unsigned char layoutPadding6[2];
    // CompactNavMeshEdgeReference
    // CompactNavMeshEdgeReference& __cdecl CompactNavMeshEdgeReference::*(const CompactNavMeshEdgeReference&)
    // bool __cdecl CompactNavMeshEdgeReference::*(const CompactNavMeshEdgeReference&)
    // bool __cdecl CompactNavMeshEdgeReference::*(const CompactNavMeshEdgeReference&)
    // unsigned __int64 __cdecl CompactNavMeshEdgeReference::*()
    // void __cdecl CompactNavMeshEdgeReference::*(char*, unsigned int)
};
class NavMeshTrianglePathEntry
{
  public:
    CompactNavMeshEdgeReference Triangle;  // +0x0, 8 bytes
    float m_fPathingCostCur;                           // +0x8, 4 bytes
    float m_fCost;                         // +0xC, 4 bytes
    float NavMeshTrianglePathCostData;     // +0x10, 4 bytes
    int NavMeshPathCostData;               // +0x14, 4 bytes
    // NavMeshTrianglePathEntry
    // NavMeshTrianglePathEntry& __cdecl NavMeshTrianglePathEntry::*(const NavMeshTrianglePathEntry&)
};
class PathSmootherPOVDebugSphereTest
{
  public:
    NiPoint3 Center;            // +0x0, 12 bytes
    float fRadius;              // +0xC, 4 bytes
    unsigned short m_usResult;  // +0x10, 2 bytes
    unsigned char layoutPadding12[2];
    // void __cdecl PathSmootherPOVDebugSphereTest::*()
};
class PathSmootherPOVDebugRay
{
  public:
    NiPoint3 Start;                                 // +0x0, 12 bytes
    NiPoint3 End;                                   // +0xC, 12 bytes
    PathSmootherPOVDebugRayTest__Result m_kResult;  // +0x18, 4 bytes
    float m_fPathingCostCur;                                    // +0x1C, 4 bytes
    // void __cdecl PathSmootherPOVDebugRay::*()
};
class SineCosine
{
  public:
    float fCos;  // +0x0, 4 bytes
    float fSin;  // +0x4, 4 bytes
    // SineCosine
    // SineCosine& __cdecl SineCosine::*(const SineCosine&)
    // SineCosine __cdecl SineCosine::*(const SineCosine&)
    // SineCosine __cdecl SineCosine::*(const SineCosine&)
    // SineCosine& __cdecl SineCosine::*(const SineCosine&)
    // SineCosine& __cdecl SineCosine::*(const SineCosine&)
    // bool __cdecl SineCosine::*()
    // void __cdecl SineCosine::*(float)
    // float __cdecl SineCosine::*()
    // NiPoint2 __cdecl SineCosine::*(float)
    // NiPoint3 __cdecl SineCosine::*(float)
    // bool __cdecl SineCosine::*(const SineCosine&, const SineCosine&, float)
    // ANGLE_DIRECTION __cdecl SineCosine::*(const SineCosine&, const SineCosine&)
    // int __cdecl SineCosine::*()
    // bool __cdecl SineCosine::*(const SineCosine&)
    // bool __cdecl SineCosine::*(const SineCosine&)
    // bool __cdecl SineCosine::*(const SineCosine&)
    // bool __cdecl SineCosine::*(const SineCosine&)
};
class CircularArc
{
  public:
    SineCosine Start;     // +0x0, 8 bytes
    SineCosine End;       // +0x8, 8 bytes
    ANGLE_DIRECTION Dir;  // +0x10, 4 bytes
    // CircularArc
    // bool __cdecl CircularArc::*()
    // bool __cdecl CircularArc::*(const SineCosine&)
    // float __cdecl CircularArc::*(float)
    // CircularArc& __cdecl CircularArc::*(const CircularArc&)
};
class Sphere
{
  public:
    NiPoint3 Center;  // +0x0, 12 bytes
    float fRadius;    // +0xC, 4 bytes
    // Sphere
    // Sphere& __cdecl Sphere::*(const Sphere&)
    // void __cdecl Sphere::*(const NiPoint3&)
};
class PathSmootherPOVDebugArcRecord
{
  public:
    CircularArc Arc;                                // +0x0, 20 bytes
    Sphere m_kTestSphere;                           // +0x14, 16 bytes
    PathSmootherPOVDebugArcTest__Result m_kResult;  // +0x24, 4 bytes
    // PathSmootherPOVDebugArcRecord
    // PathSmootherPOVDebugArcRecord& __cdecl PathSmootherPOVDebugArcRecord::*(const PathSmootherPOVDebugArcRecord&)
};
class PathSmootherPOVDebugTests
{
  public:
    BSSimpleArray<PathSmootherPOVDebugSphereTest, 1024> POVPointerArray;  // +0x0, 16 bytes
    BSSimpleArray<PathSmootherPOVDebugRay, 1024> Rays;                    // +0x10, 16 bytes
    BSSimpleArray<PathSmootherPOVDebugArcRecord, 1024> m_kThirdArray;     // +0x20, 16 bytes
    // void __cdecl PathSmootherPOVDebugTests::*(PathSmootherPOVDebugTests*)
    // PathSmootherPOVDebugTests
    // void __cdecl PathSmootherPOVDebugTests::*()
    // PathSmootherPOVDebugTests& __cdecl PathSmootherPOVDebugTests::*(const PathSmootherPOVDebugTests&)
    // void* __cdecl PathSmootherPOVDebugTests::*(unsigned int)
};
class PacketNodeRecord
{
  public:
    unsigned int iFlags;       // +0x0, 4 bytes
    PathingLocation Location;  // +0x4, 40 bytes
    TESObjectREFR* m_pDoorRef;   // +0x2C, 4 bytes
    // PacketNodeRecord
    // void __cdecl PacketNodeRecord::*()
    // PacketNodeRecord* __cdecl PacketNodeRecord::*()
    // void __cdecl PacketNodeRecord::*(NiPointer<NiNode>&)
    // GetLocation
    // void __cdecl PacketNodeRecord::*(PathingLocation&)
    // void __cdecl PacketNodeRecord::*()
    // TESObjectREFR* __cdecl PacketNodeRecord::*()
    // bool __cdecl PacketNodeRecord::*()
    // bool __cdecl PacketNodeRecord::*()
    // bool __cdecl PacketNodeRecord::*()
    // void __cdecl PacketNodeRecord::*(IDebugText*)
    // void __cdecl PacketNodeRecord::*(BGSSaveFormBuffer*)
    // void __cdecl PacketNodeRecord::*(BGSLoadFormBuffer*)
    // PacketNodeRecord& __cdecl PacketNodeRecord::*(const PacketNodeRecord&)
    // void* __cdecl PacketNodeRecord::*(unsigned int)
};
class PathingGraphNode
{
  public:
    unsigned int iFlags;       // +0x0, 4 bytes
    PathingLocation Location;  // +0x4, 40 bytes
    NiPoint3 Tangent;          // +0x2C, 12 bytes
    TESObjectREFR* m_pDoorRef;   // +0x38, 4 bytes
    // PathingGraphNode
    // void __cdecl PathingGraphNode::*()
    // PathingGraphNode* __cdecl PathingGraphNode::*()
    // const PathingLocation& __cdecl PathingGraphNode::*()
    // const NiPoint3& __cdecl PathingGraphNode::*()
    // void __cdecl PathingGraphNode::*(NiPointer<NiNode>&)
    // TESObjectCELL* __cdecl PathingGraphNode::*()
    // void __cdecl PathingGraphNode::*(const NiPoint3&)
    // bool __cdecl PathingGraphNode::*()
    // void __cdecl PathingGraphNode::*(TESObjectREFR*)
    // void __cdecl PathingGraphNode::*(bool)
    // bool __cdecl PathingGraphNode::*()
    // bool __cdecl PathingGraphNode::*(Actor*)
    // TESObjectREFR* __cdecl PathingGraphNode::*()
    // void __cdecl PathingGraphNode::*(IDebugText*)
    // void __cdecl PathingGraphNode::*(BGSSaveFormBuffer*)
    // void __cdecl PathingGraphNode::*(BGSLoadFormBuffer*)
    // PathingGraphNode& __cdecl PathingGraphNode::*(const PathingGraphNode&)
    // void* __cdecl PathingGraphNode::*(unsigned int)
public:
    bool IsTransitionNode();
};
class PathingSolution : public NiRefObject
{
  public:
    LocationDescriptor* FUN_006e78b0(unsigned int);
    BaseProcess* FUN_006e78b0(unsigned int, NiPoint3&);
    float CalculatePathLength();
    // base NiRefObject at +0x0, size 8
    PathingInfo Info;                                               // +0x8, 108 bytes
    BSSimpleArray<NavMeshInfoSearchNode, 1024> m_kFirstArray;       // +0x74, 16 bytes
    BSSimpleArray<NavMeshTrianglePathEntry, 1024> m_kElementArray;  // +0x84, 16 bytes
    PathSmootherPOVDebugTests ArrayContainerData;                   // +0x94, 48 bytes
    BSSimpleArray<PacketNodeRecord, 1024> m_kPathingDoorRefArray;   // +0xC4, 16 bytes
    int PathingRecordCollection;                                    // +0xD4, 4 bytes
    int m_iValueBeforeRecordArray;                                  // +0xD8, 4 bytes
    BSSimpleArray<PathingGraphNode, 1024> m_kRecordArray;           // +0xDC, 16 bytes
    BSSimpleArray<unsigned int, 1024> UnsignedIntArray;             // +0xEC, 16 bytes
    bool m_bHasValidPath;                                           // +0xFC, 1 bytes
    unsigned char layoutPaddingFD[3];
    // PathingSolution
    // void __cdecl PathingSolution::*()
    // void __cdecl PathingSolution::*()
    // bool __cdecl PathingSolution::*()
    // bool __cdecl PathingSolution::*()
    // unsigned int __cdecl PathingSolution::*()
    // GetVirtualNode
    // GetFirstVirtualNode
    // GetLastVirtualNode
    // unsigned int __cdecl PathingSolution::*()
    // GetNode
    // GetFirstNode
    // GetLastNode
    // int __cdecl PathingSolution::*()
    // int __cdecl PathingSolution::*()
    // void __cdecl PathingSolution::*()
    // float __cdecl PathingSolution::*()
    // float __cdecl PathingSolution::*()
    // float __cdecl PathingSolution::*(int)
    // float __cdecl PathingSolution::*(unsigned int)
    // float __cdecl PathingSolution::*(float)
    // void __cdecl PathingSolution::*(float, NiPoint3&)
    // bool __cdecl PathingSolution::*(float, float, bool, float*, NiPoint3*)
    // float __cdecl PathingSolution::*(float, float, unsigned int&)
    // NiPoint3 __cdecl PathingSolution::*(float, float)
    // void __cdecl PathingSolution::*(PathingSolution*)
    // bool __cdecl PathingSolution::*(unsigned int)
    // void __cdecl PathingSolution::*(IDebugText*)
    // void __cdecl PathingSolution::*(BGSSaveFormBuffer*)
    // void __cdecl PathingSolution::*(BGSLoadFormBuffer*)
    // AddVirtualPathingNode
    // AddPathingNode
    // void __cdecl PathingSolution::*(unsigned int)
    // void __cdecl PathingSolution::*()
    // void __cdecl PathingSolution::*()
    // unsigned int __cdecl PathingSolution::*(const PacketNodeRecord*)
    // unsigned int __cdecl PathingSolution::*(const PathingGraphNode*)
    // void __cdecl PathingSolution::*(bool)
    // PathingSolution& __cdecl PathingSolution::*(const PathingSolution&)
    // void __cdecl PathingSolution::*()
};
#endif
