// Fallout: New Vegas - original source reconstruction.
// Original: platforms/common/code/fallout/ai/sandboxpackage.cpp
//
// Unit-local declarations for SandBoxActorPackageData save/load, location,
// activity-window and procedure-selection helpers. Layouts for
// SandBoxActorPackageData, SandboxProcedureData, Calendar and the
// BSSimpleArray<SandboxProcedureData, 1024> instantiation are copied verbatim
// layout, PC equivalence unproven), with out-of-line method declarations
// appended (non-virtual additions do not affect layout). TimeGlobal mirrors
// the community Timer/TimeGlobal layout (JIP LN NVSE nvse/GameData.h,
// the folded [ecx+0x14] millisecond getter at 0x825C00.
#ifndef FNV_SANDBOXPACKAGE_H
#define FNV_SANDBOXPACKAGE_H


#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FUN_0041e410_shell.h"
#include "fnv/decl/FUN_0041fe90_shell.h"
#include "fnv/decl/FUN_00568260_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009f6200_Class.h"
#include "fnv/decl/Fn9a4f40.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_00567f80__Fn567f80.h"
#include "fnv/decl/fnv_00568150__FUN_00568150_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_009f38b0__FUN_009f38b0_shell.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0092a000.h"
#include "fnv/symbols_011de000.h"
#define TimeGlobal SandboxSharedTimeGlobal
#define g_timeGlobal g_sandboxSharedTimeGlobal
#include "layout_support.h"
#undef g_timeGlobal
#undef TimeGlobal
#include "SandboxProcedureData.h"
#include "Actor.h"
#include "TESForm.h"
#include "TESGlobal.h"
#include "TESObjectREFR.h"

#ifndef NULL
#define NULL 0
#endif

struct BGSLoadFormBuffer;

class SandBoxActorPackageData;
class SandboxProcedureData;
enum SandBoxActorPackageData__SANDBOX_STATE
{
    SandBoxActorPackageData__SANDBOX_STATE_SANDBOX_STATE_INIT = 0,
    SandBoxActorPackageData__SANDBOX_STATE_SANDBOX_STATE_GETTING_UP = 1,
    SandBoxActorPackageData__SANDBOX_STATE_SANDBOX_STATE_MOVING = 2,
    SandBoxActorPackageData__SANDBOX_STATE_SANDBOX_STATE_DOINGSTUFF = 3,
    SandBoxActorPackageData__SANDBOX_STATE_NUM_SANDBOX_STATES = 4
};
enum SANDBOX_ACTIVITY
{
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_NONE = -1,
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_SLEEP = 0,
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_BREAKFAST = 1,
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_LUNCH = 2,
    SANDBOX_ACTIVITY_SANDBOX_ACTIVITY_DINNER = 3,
    SANDBOX_ACTIVITY_NUM_SANDBOX_ACTIVITIES = 4
};
class ActorPackageData
{
  public:
    void** m_ppVirtualMethodTable;  // +0x0, 4 bytes
};
class SandBoxActorPackageData : public ActorPackageData
{
  public:
    // base ActorPackageData at +0x0, size 4
    SandBoxActorPackageData__SANDBOX_STATE eState;               // +0x4, 4 bytes
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
    unsigned char layoutPadding41[3];
    TESObjectREFR* m_pCurrentFurniture;   // +0x44, 4 bytes
    unsigned int m_uiActivityStartDay;    // +0x48, 4 bytes
    unsigned int m_uiActivityEndDay;      // +0x4C, 4 bytes
    float m_fActivityStartHour;           // +0x50, 4 bytes
    float m_fActivityEndHour;             // +0x54, 4 bytes
    SANDBOX_ACTIVITY m_eSandboxActivity;  // +0x58, 4 bytes
    unsigned char m_ucProcedureFlags[6];  // +0x5C, 6 bytes
    unsigned char layoutPadding62[2];
    // Covered functions of this unit.
    bool IsLocationCheckDue();
    bool IsActivityTime();
    void SetReferenceTarget(TESObjectREFR* apDeletedRef);
    bool HasProcessTarget(Actor* apActor);
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    // Other-unit-owned methods called from this unit.
    bool HasActivityEnded(bool* apbEndedToday);
    bool IsActivityProcedure();
    bool IsActorWithinLocationRadius(Actor* apActor, bool abFlag);
};

// BSSimpleArray out-of-line helpers owned by other units. GetSize/GetAt come
// from the shared template; SetSize/RemoveAt need a derived declaration.
class SandboxChoiceArray : public BSSimpleArray<SandboxProcedureData, 1024>
{
  public:
};

class Calendar
{
  public:
    TESGlobal* m_pYearGlobal;            // +0x0, 4 bytes
    TESGlobal* m_pMonthGlobal;           // +0x4, 4 bytes
    TESGlobal* m_pDayGlobal;             // +0x8, 4 bytes
    TESGlobal* m_pHourGlobal;            // +0xC, 4 bytes
    TESGlobal* m_pGameDaysPassedGlobal;  // +0x10, 4 bytes
    TESGlobal* pHourGlobal;              // +0x14, 4 bytes
    unsigned int m_uiDaysPassed;         // +0x18, 4 bytes
    // Unit-local out-of-line declarations.
    float GetGameTime();
};

// Community-evidenced global timer (JIP LN NVSE GameData.h Timer/TimeGlobal,
// millisecond getter at 0x825C00.
class TimeGlobal
{
  public:
    unsigned char disableCounter;  // +0x0
    unsigned char pad01[3];
    float fpsClamp;           // +0x4
    float fpsClampRemainder;  // +0x8
    float secondsPassed;      // +0xC
    float lastSecondsPassed;  // +0x10
    unsigned int msPassed;    // +0x14
    unsigned int tickCount;   // +0x18
};
extern TimeGlobal g_timeGlobal;

// Minimal buffer declaration (same shape as the accepted actorpackagedata.h).
struct BGSLoadFormBuffer
{
  public:
};

// Minimal region-point declaration (GetX binding ?GetX@RegionPoint@@QAEMXZ).
class RegionPoint
{
  public:
};

// Other-unit-owned ExtraDataList/TESObjectREFR out-of-line helpers reached
// through subclass casts (no layout change, no bytes).
class ExtraDataListHelper : public ExtraDataList
{
  public:
};
class TESObjectREFRHelper : public TESObjectREFR
{
  public:
};

class SandboxTargetInfo
{
  public:
};
class ActorTargetSource
{
  public:
};

// Other-unit-owned free helpers.

// Activity -> procedure table at 0x11A5F3C.
extern SANDBOX_PROCEDURE g_procedureForActivity[4];

#endif
