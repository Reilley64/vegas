// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PATHINGREQUEST_H
#define FNV_PATHINGREQUEST_H

#include "layout_support.h"
#include "Actor.h"
#include "InventoryChanges.h"
#include "NiPoint3.h"
#include "NiRefObject.h"
#include "PathingLocation.h"
#include "layout_support.h"
class PathingActorData;
class PathingAvoidNodeArray;
struct PathingRequest;
class PathingActorData
{
  public:
    TESActorBase* m_pActorBaseFormItem;                    // +0x0, 4 bytes
    InventoryChanges* m_pInventoryChangesValue;  // +0x4, 4 bytes
    bool m_bCanIgnoreLocks;                      // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    // PathingActorData
    // PathingActorData& __cdecl PathingActorData::*(const PathingActorData&)
};
struct PathingRequest : public NiRefObject
{
  public:
    PathingLocation* GetOffsetC();
    // base NiRefObject at +0x0, size 8
    Actor* pActor;                                              // +0x8, 4 bytes
    PathingLocation Origin;                                     // +0xC, 40 bytes
    PathingLocation Destination;                                // +0x34, 40 bytes
    PathingActorData PathingActorState;                         // +0x5C, 12 bytes
    float m_fFirstValueAfterActorData;                          // +0x68, 4 bytes
    float m_fSecondValueAfterActorData;                         // +0x6C, 4 bytes
    float PathingActorSpatialData;                              // +0x70, 4 bytes
    float fWeaponSpread;                                        // +0x74, 4 bytes
    float m_fCenterRadius;                                      // +0x78, 4 bytes
    NiPoint3 Center;                                            // +0x7C, 12 bytes
    float m_fFloatAfterCenter;                                 // +0x88, 4 bytes
    float m_fPathingRadius;                                     // +0x8C, 4 bytes
    float m_fAvoidanceRadius;                                   // +0x90, 4 bytes
    NiPointer<PathingAvoidNodeArray> m_pPathingAvoidNodeArray;  // +0x94, 4 bytes
    bool bCantOpenDoors;                                        // +0x98, 1 bytes
    bool bFaceTargetAtGoal;                                     // +0x99, 1 bytes
    bool PathingOptions;                                        // +0x9A, 1 bytes
    bool bAllowIncompletePath;                                  // +0x9B, 1 bytes
    bool m_bAllowDoorTraversal;                                 // +0x9C, 1 bytes
    bool bCanSwim;                                              // +0x9D, 1 bytes
    bool bCanFly;                                               // +0x9E, 1 bytes
    bool m_bCanWalk;                                            // +0x9F, 1 bytes
    bool m_bCanJump;                                            // +0xA0, 1 bytes
    bool m_bCanClimb;                                           // +0xA1, 1 bytes
    bool m_bCanUseDoors;                                        // +0xA2, 1 bytes
    bool m_bCanRun;                                             // +0xA3, 1 bytes
    bool bIgnoreLocks;                                          // +0xA4, 1 bytes
    unsigned char layoutPaddingA5[3];
    int m_iRequestType;    // +0xA8, 4 bytes
    bool m_bCanOpenDoors;  // +0xAC, 1 bytes
    unsigned char layoutPaddingAD[3];
    // PathingRequest
    // void __cdecl PathingRequest::*()
    // PathingRequest& __cdecl PathingRequest::*(const PathingRequest&)
    // PathingRequest* __cdecl PathingRequest::*(PATHING_REQUEST_TYPE)
    // SetOrigin
    // GetOrigin
    // void __cdecl PathingRequest::*(const PathingLocation&)
    // void __cdecl PathingRequest::*()
    // GetDestination
    // void __cdecl PathingRequest::*(float)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(float)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(float)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(float)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(NiPoint3&, float)
    // float __cdecl PathingRequest::*()
    // NiPoint3 __cdecl PathingRequest::*()
    // SetActorLockData
    // GetActorLockData
    // void __cdecl PathingRequest::*(float)
    // bool __cdecl PathingRequest::*()
    // float __cdecl PathingRequest::*()
    // PathingAvoidNodeArray* __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(PathingAvoidNodeArray*)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(float)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // void __cdecl PathingRequest::*(float)
    // void __cdecl PathingRequest::*()
    // bool __cdecl PathingRequest::*()
    // float __cdecl PathingRequest::*()
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // int __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(int)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // void __cdecl PathingRequest::*(Actor*)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*()
};
#endif
