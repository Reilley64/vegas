// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/actorpackagedata.h
//
// Unit-local declarations for ActorPackageData::CreatePackageData.
// ActorPackageData, EscortActorPackageData, PatrolActorPackageData and PTYPE are
// CodeView layout, PC equivalence unproven). GuardActorPackageData,
// SandBoxActorPackageData and UseWeaponActorPackageData are rendered from their
// the constructor disassembly (SandBox ctor zeroes m_ucProcedureFlags[6] at
// +0x5c; UseWeapon ctor stores only m_pUseTarget at +0x4).
// The PTYPE enumerator names follow the accepted guardpackage.h; the values
// USEWEAPON=16).
#ifndef FNV_TASK_ACTORPACKAGEDATA_UNIT_H
#define FNV_TASK_ACTORPACKAGEDATA_UNIT_H


#include "layout_support.h"

class Actor;
class TESPackage;
class TESObjectREFR;
class TESPatrolPackageData;
class TESEscortPackageData;
class SandboxProcedureData;

typedef enum
{
    PTYPE_NONE = -1,
    PTYPE_EXPLORE = 0,
    PTYPE_FOLLOW,
    PTYPE_ESCORT,
    PTYPE_EAT,
    PTYPE_SLEEP,
    PTYPE_WANDER,
    PTYPE_TRAVEL,
    PTYPE_ACCOMPANY,
    PTYPE_USEITEMAT,
    PTYPE_AMBUSH,
    PTYPE_FLEE_NON_COMBAT,
    PTYPE_CAST_MAGIC,
    PTYPE_SANDBOX,
    PTYPE_PATROL,
    PTYPE_GUARD,
    PTYPE_DIALOGUE,
    PTYPE_USEWEAPON,
    PTYPE_FIND,
    PTYPE_COMBAT,
    PTYPE_COMBAT_LOW,
    PTYPE_ACTIVATE,
    PTYPE_ALARM,
    PTYPE_FLEE,
    PTYPE_TRESPASS,
    PTYPE_SPECTATOR,
    PTYPE_GREET,
    PTYPE_GET_UP,
    PTYPE_DO_NOTHING,
    PTYPE_IN_GAME_DIALOGUE,
    PTYPE_SURFACE,
    PTYPE_SEARCH_FOR_ATTACKER,
    PTYPE_AVOID_RADIATION,
    PTYPE_EXPLOSION_REACTION,
    PTYPE_GRENDADE_MINE_REACTION,
    PTYPE_STEAL_WARNING,
    PTYPE_PICKPOCKET_WARNING,
    PTYPE_MOVEMENT_BLOCKED,
    PTYPE_SANDMAN,
    PTYPE_CANNIBAL,
    PTYPE_BACK_UP,
    PTYPE_COUNT
} PTYPE;

class ActorPackageData
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
    static ActorPackageData* CreatePackageData(PTYPE aeType);
};

// above; constructor declaration added for the out-of-line ctor 0x009f0900).
class EscortActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    Actor* pActor;                                     // +0x4, 4 bytes
    TESPackage* pPackage;                              // +0x8, 4 bytes
    const TESEscortPackageData* m_pEscortPackageData;  // +0xC, 4 bytes
    BSSimpleList<Actor*> m_kActorList;                 // +0x10, 8 bytes
    EscortActorPackageData();
};

// above; forward declarations replace the header includes; constructor
// declaration added for the out-of-line ctor 0x009f29a0).
class PatrolActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    enum PATROL_STATE
    {
        PATROL_STATE_INIT = 0,
        PATROL_STATE_TRAVELING_TO_NEXT_REF = 1,
        PATROL_STATE_AT_REF = 2,
        PATROL_STATE_DEBUG_ACTOR_DELETED = 3,
        PATROL_STATE_DEBUG_DESTRUCTED = 4
    };
    PATROL_STATE eState;       // +0x4, 4 bytes
    float m_fElapsedWaitTime;  // +0x8, 4 bytes
    bool m_bPatrolFlag;        // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    Actor* pActor;                                     // +0x10, 4 bytes
    TESPackage* pPackage;                              // +0x14, 4 bytes
    const TESPatrolPackageData* m_pEscortPackageData;  // +0x18, 4 bytes
    BSSimpleArray<TESObjectREFR*, 1024> References;    // +0x1C, 16 bytes
    bool m_bReferenceFlag;                             // +0x2C, 1 bytes
    unsigned char layoutPadding2D[3];
    unsigned int m_uiValueAfterReferenceFlag;        // +0x30, 4 bytes
    unsigned int m_uiSecondValueAfterReferenceFlag;  // +0x34, 4 bytes
    PatrolActorPackageData();
};

class GuardActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    enum GUARD_STATE
    {
        GUARD_STATE_INIT = 0,
        GUARD_STATE_IDLE = 1,
        GUARD_STATE_WAIT_TO_ATTACK = 2
    };
    GuardActorPackageData();
    GUARD_STATE eState;     // +0x4, 4 bytes
    Actor* pWarningTarget;  // +0x8, 4 bytes
    int iWarningCount;      // +0xC, 4 bytes
    float m_fWarningTimer;  // +0x10, 4 bytes
};

class SandBoxActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    enum SANDBOX_STATE
    {
        SANDBOX_STATE_INIT = 0,
        SANDBOX_STATE_GETTING_UP = 1,
        SANDBOX_STATE_MOVING = 2,
        SANDBOX_STATE_DOINGSTUFF = 3,
        NUM_SANDBOX_STATES = 4
    };
    enum SANDBOX_PROCEDURE
    {
        SANDBOX_PROCEDURE_NONE = -1,
        SANDBOX_PROCEDURE_SIT = 0,
        SANDBOX_PROCEDURE_SLEEP = 1,
        SANDBOX_PROCEDURE_EAT = 2,
        SANDBOX_PROCEDURE_WANDER = 3,
        SANDBOX_PROCEDURE_USE_IDLE_MARKER = 4,
        SANDBOX_PROCEDURE_DIALOGUE = 5,
        NUM_SANDBOX_PROCEDURES = 6
    };
    enum SANDBOX_ACTIVITY
    {
        SANDBOX_ACTIVITY_NONE = -1,
        SANDBOX_ACTIVITY_SLEEP = 0,
        SANDBOX_ACTIVITY_BREAKFAST = 1,
        SANDBOX_ACTIVITY_LUNCH = 2,
        SANDBOX_ACTIVITY_DINNER = 3,
        NUM_SANDBOX_ACTIVITIES = 4
    };
    SandBoxActorPackageData();
    SANDBOX_STATE eState;                                        // +0x4, 4 bytes
    SANDBOX_PROCEDURE eProcedure;                                // +0x8, 4 bytes
    float m_fProcedureTime;                                      // +0xC, 4 bytes
    TESObjectREFR* pLocation;                                    // +0x10, 4 bytes
    float m_fLastProcedureCheckHour;                             // +0x14, 4 bytes
    float m_fNextProcedureCheckHour;                             // +0x18, 4 bytes
    unsigned int m_uiLastProcedureCheckDay;                      // +0x1C, 4 bytes
    BSSimpleArray<SandboxProcedureData, 1024> m_kProcedureList;  // +0x20, 16 bytes
    unsigned int m_uiProcedureIndex;                             // +0x30, 4 bytes
    bool m_bNeedsSandboxUpdate;                                  // +0x34, 1 bytes
    bool m_bHasFoodMarker;                                       // +0x35, 1 bytes
    bool m_bHasChairMarker;                                      // +0x36, 1 bytes
    bool m_bHasBedMarker;                                        // +0x37, 1 bytes
    int m_iSerializedValue;                                      // +0x38, 4 bytes
    TESObjectREFR* m_pCurrentTarget;                             // +0x3C, 4 bytes
    unsigned char m_ucProcedureIndex;                            // +0x40, 1 bytes
    TESObjectREFR* m_pCurrentFurniture;                          // +0x44, 4 bytes
    unsigned int m_uiActivityStartDay;                           // +0x48, 4 bytes
    unsigned int m_uiActivityEndDay;                             // +0x4C, 4 bytes
    float m_fActivityStartHour;                                  // +0x50, 4 bytes
    float m_fActivityEndHour;                                    // +0x54, 4 bytes
    SANDBOX_ACTIVITY m_eSandboxActivity;                         // +0x58, 4 bytes
    unsigned char m_ucProcedureFlags[NUM_SANDBOX_PROCEDURES];    // +0x5C, 6 bytes
};

class UseWeaponActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    UseWeaponActorPackageData();
    TESObjectREFR* m_pUseTarget;  // +0x4, 4 bytes
};

#endif
