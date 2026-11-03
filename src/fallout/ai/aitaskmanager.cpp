// fallout/ai/aitaskmanager.cpp: MovementTaskData, PackageUpdateTaskData, Owner, ActorsScriptTaskData and more (87 functions)

#include "havok/hkMemoryRouter.h"
#include <new>
#include "fnv/decl/ActiveEffect.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/B88B5A0Actor.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00422700_shell.h"
#include "fnv/decl/FUN_00422720_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0059e400_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_006ea330_shell.h"
#include "fnv/decl/FUN_006ec390_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_0088b510_cls.h"
#include "fnv/decl/FUN_00893530_shell.h"
#include "fnv/decl/FUN_008_Struct.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008bc700_shell.h"
#include "fnv/decl/FUN_008bc790_shell.h"
#include "fnv/decl/FUN_008ca770_Class.h"
#include "fnv/decl/FUN_008ca7c0_shell.h"
#include "fnv/decl/FUN_008ca830_cls.h"
#include "fnv/decl/FUN_00931fb0_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00967350_shell.h"
#include "fnv/decl/FUN_009ae580_shell.h"
#include "fnv/decl/FaderManager.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/GameObject.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/PlayerCharacter.h"
#include "fnv/decl/QuantitySet.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_0082f1f0_Lock.h"
#include "fnv/decl/SemaphoreWaitReceiver.h"
#include "fnv/decl/TESFaction_RankDataView.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeammateOwner.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00422690__FUN_00422690_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00565870__FUN_00565870_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_008b0520__FUN_008b0520_shell.h"
#include "fnv/decl/fnv_008bc860__FUN_008bc860_StandIn.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/fnv_009334b0__FUN_009334b0_shell.h"
#include "fnv/decl/fnv_00964260__SelActor.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_0096e3c0__FUN_0096e3c0_shell.h"
#include "fnv/decl/fnv_00977130__FUN_00977130_shell.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_005cb000.h"
#include "fnv/symbols_0076b000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_008c8000.h"
#include "fnv/symbols_008ca000.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_01085000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "fnv/symbols_011f6000.h"
#include "../../../include/layout_support.h"
#include "../../../include/Actor.h"
#include "../../../include/RecursiveLock.h"
// ActorTaskManager task-list serialisation.
//
// The manager guards its task data with a critical section that lives at the
// front of the object, so a guarded helper can hand `this` straight to the
// lock. Releasing the guard is a single forwarded call, which is all this
// translation unit needs to express for the covered method.

class ActorTaskManager
{
  public:
    RecursiveLock m_taskLock;

    void WaitForTasksDuringRendering();
};

// @fnv 0x004538c0
void ActorTaskManager::WaitForTasksDuringRendering()
{
    reinterpret_cast<::S_0082f1f0_Lock *>(&(m_taskLock))->FUN_0082f1f0();
}

struct ST_008c8bb0
{
    char pad[0x5f8];
    bool m_bState;
    void FUN_008c8bb0(bool f);
};
// @fnv 0x008c8bb0
void ST_008c8bb0::FUN_008c8bb0(bool abValue)
{
    m_bState = abValue;
}

struct FUN_008c8fd0_helper
{
    char pad[0x2c7];
    bool bSkippedLastUpdate;
    void Set(bool abVal);
};

// @fnv 0x008c8fd0
void FUN_008c8fd0_helper::Set(bool abVal)
{
    bSkippedLastUpdate = abVal;
}

struct WeatherEntry;
struct SoundListView
{
};
// Appends name to g_011d970c and re-sorts the list using FUN_0076bb00 as the comparison.
// @fnv 0x0076bad0
void FUN_0076bad0(char* name)
{
    reinterpret_cast<::Callees *>(&((*reinterpret_cast<::SoundListView *>(&::g_011d970c))))->FUN_00905820((void *)&(name));
    reinterpret_cast<::ItemChangeList *>((((BSSimpleList<WeatherEntry*>*)&(*reinterpret_cast<::SoundListView *>(&::g_011d970c)))))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(((int (&)(WeatherEntry *, WeatherEntry *))::FUN_0076bb00)));
}

struct FUN_008c8190_shell
{
    int a;
    int b;
    int c;
    FUN_008c8190_shell* FUN_008c8190();
};
// Sets the object's a field to 2 and clears b and c, then returns this.
// @fnv 0x008c8190
FUN_008c8190_shell* FUN_008c8190_shell::FUN_008c8190()
{
    a = 2;
    b = 0;
    c = 0;
    return this;
}

struct FUN_008c8370_shell
{
    void FUN_008c83a0();
    FUN_008c8370_shell* FUN_008c8370(unsigned int flags);
};
struct FUN_008c8400_shell
{
    FUN_008c8400_shell* FUN_008c8400(unsigned int flags);
};
extern int DAT_01085728;
struct FUN_008c8430_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void FUN_008c8430();
};
struct ATM
{
};
struct PC7d;
struct FUN_008c8490_shell
{
    void FUN_008c8490(unsigned int);
};
// Calls FUN_00964260 on g_thePlayer, then waits for rendering tasks on g_011dfc04 and g_011dfbe8.
// @fnv 0x008c8490
void FUN_008c8490_shell::FUN_008c8490(unsigned int)
{
    reinterpret_cast<::fnv_00964260::SelActor *>(((*reinterpret_cast<::PC7d * *>(&::_g_thePlayer))))->FUN_00964260();
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::ATM *>(&::g_011dfc04))))->WaitForTasksDuringRendering();
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::ATM *>(&::g_011dfbe8))))->WaitForTasksDuringRendering();
}

extern int DAT_01085768;
struct FUN_008c8830_shell
{
    int* vtable;
    void FUN_008c82e0(int);
    FUN_008c8830_shell* Construct(int p);
};
// Calls FUN_008c82e0 with p, sets the vtable to DAT_01085768, and returns this.
// @fnv 0x008c8830
FUN_008c8830_shell* FUN_008c8830_shell::Construct(int p)
{
    FUN_008c82e0(p);
    vtable = &DAT_01085768;
    return this;
}

struct FUN_008c8860_shell
{
    void* FUN_008c8860(unsigned int flags);
};
extern int DAT_01085768;
struct FUN_008c8890_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void FUN_008c8890();
};
namespace fnv_008c88b0 {
struct ATM
{
    void QueryPerformanceCounter(int);
};
struct FUN_008c88b0_shell
{
    void QueryPerformanceCounters(int);
};
// Calls QueryPerformanceCounter on g_011dfc38 and g_011dfc04 with argument 0.
// @fnv 0x008c88b0
void FUN_008c88b0_shell::QueryPerformanceCounters(int)
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c88b0::ATM *>(&::g_011dfc38))))->FUN_004538a0(0);
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c88b0::ATM *>(&::g_011dfc04))))->FUN_004538a0(0);
}
}  // namespace fnv_008c88b0

namespace fnv_008c88e0 {
struct ATM
{
};
struct FUN_008c88e0_shell
{
    void FUN_008c88e0(int a);
};
// Calls WaitForTasksDuringRendering on g_011dfc04 and g_011dfc38.
// @fnv 0x008c88e0
void FUN_008c88e0_shell::FUN_008c88e0(int aiUnused)
{
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008c88e0::ATM *>(&::g_011dfc04))))->WaitForTasksDuringRendering();
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008c88e0::ATM *>(&::g_011dfc38))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_008c88e0

struct FUN_008c82e0
{
    int pad[13];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c89a0 : FUN_008c82e0
{
    int field38;
    FUN_008c89a0(int a);
    virtual void Run();
};
// Initializes the base class with a and sets field38 to 0.
// @fnv 0x008c89a0
FUN_008c89a0::FUN_008c89a0(int aiValue) : FUN_008c82e0(aiValue)
{
    field38 = 0;
}

struct FUN_008c89d0_shell
{
    void* Destroy(unsigned int flags);
};
extern int DAT_01085788;
struct FUN_008c8a00_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void FUN_008c8a00();
};
namespace fnv_008c8a20 {
struct ATM
{
    void QueryPerformanceCounter(int);
};
struct FUN_008c8a20_shell
{
    void FUN_008c8a20(int);
};
// Clears the int at offset 0x38 and calls QueryPerformanceCounter on g_011dfc38.
// @fnv 0x008c8a20
void FUN_008c8a20_shell::FUN_008c8a20(int)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x38) = 0;
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c8a20::ATM *>(&::g_011dfc38))))->FUN_004538a0(0);
}
}  // namespace fnv_008c8a20

namespace fnv_008c8a50 {
struct ATM
{
};
struct FUN_008c8a50_shell
{
    void FUN_008c8a50(int a);
};
// @fnv 0x008c8a50
void FUN_008c8a50_shell::FUN_008c8a50(int aiUnused)
{
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008c8a50::ATM *>(&::g_011dfc38))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_008c8a50

struct FUN_008c8b20_shell
{
    void* DestroyOrReturnSelf(unsigned int flags);
};
extern int DAT_010857a8;
struct FUN_008c8b50_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void FUN_008c8b50();
};
extern "C" unsigned char DAT_011e01dd;

// @fnv 0x008c8bd0
void FUN_008c8bd0()
{
    DAT_011e01dd = 0;
}

namespace fnv_008c8ff0 {
struct Twin_0084d030
{
};
struct PkgObj
{
};
struct ATM
{
    void QueryPerformanceCounter(int);
};
struct PackageUpdateTaskData
{
    void RunPackageUpdateTask(unsigned int aiThread);
};
// @fnv 0x008c8ff0
void PackageUpdateTaskData::RunPackageUpdateTask(unsigned int aiThread)
{
    reinterpret_cast<::fnv_00977130::FUN_00977130_shell *>(&((*reinterpret_cast<::fnv_008c8ff0::PkgObj *>(&::g_011e0e80))))->FUN_00977130(reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::fnv_008c8ff0::Twin_0084d030 *>(&::g_timeGlobal))))->GetStoredFloatValue());
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008c8ff0::ATM *>(&::g_011dfbe8))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_008c8ff0

namespace fnv_008c9020 {
struct FUN_008c82e0
{
    int pad[14];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c9020 : FUN_008c82e0
{
    int field;
    FUN_008c9020(int a);
    virtual void Run();
};
// Constructs the object by forwarding a to the base constructor and initializing field to 0.
// @fnv 0x008c9020
FUN_008c9020::FUN_008c9020(int a) : FUN_008c82e0(a)
{
    field = 0;
}
}  // namespace fnv_008c9020

struct FUN_008c9050_shell
{
    void* FUN_008c9050(unsigned int flags);
};
extern int DAT_010857c8;
struct FUN_008c9080_shell
{
    int* vtbl;
    void FUN_008c83a0();
    void FUN_008c9080();
};
namespace fnv_008c90e0 {
struct ATM
{
};
struct FUN_008c90e0_shell
{
    void FUN_008c90e0(unsigned int);
};
// Calls WaitForTasksDuringRendering on three global ATM instances to wait for their tasks during rendering.
// @fnv 0x008c90e0
void FUN_008c90e0_shell::FUN_008c90e0(unsigned int)
{
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008c90e0::ATM *>(&::g_011dfbe8))))->WaitForTasksDuringRendering();
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008c90e0::ATM *>(&::g_011dfc04))))->WaitForTasksDuringRendering();
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008c90e0::ATM *>(&::g_011dfc38))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_008c90e0

namespace fnv_008c9170 {
struct FUN_008c82e0
{
    int pad[13];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c9170 : FUN_008c82e0
{
    int field;
    FUN_008c9170(int a);
    virtual void Run();
};
// Constructs the object by forwarding a to the base constructor and initializing field to 0.
// @fnv 0x008c9170
FUN_008c9170::FUN_008c9170(int a) : FUN_008c82e0(a)
{
    field = 0;
}
}  // namespace fnv_008c9170

struct FUN_008c91a0_shell
{
    void* FUN_008c91a0(unsigned int flags);
};
extern int DAT_010857e8;

struct FUN_008c91d0_shell
{
    void* m_vft;
    void FUN_008c83a0();
    void FUN_008c91d0();
};
// Calls FUN_008c91d0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x008c91a0
void* FUN_008c91a0_shell::FUN_008c91a0(unsigned int flags)
{
    reinterpret_cast<::FUN_008c91d0_shell *>(this)->FUN_008c91d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_008c91f0 {
struct ATM
{
    void QueryPerformanceCounter(int);
};
struct MovementTaskData
{
    int pad[14];
    int field;
    void FUN_008c91f0(unsigned int auiCount);
};
// Clears field and queries the performance counter on both g_011dfc04 and g_011dfbe8.
// @fnv 0x008c91f0
void MovementTaskData::FUN_008c91f0(unsigned int auiCount)
{
    field = 0;
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c91f0::ATM *>(&::g_011dfc04))))->FUN_004538a0(0);
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c91f0::ATM *>(&::g_011dfbe8))))->FUN_004538a0(0);
}
}  // namespace fnv_008c91f0

namespace fnv_008c9300 {
struct ATM
{
};
struct FUN_008c9300_shell
{
    void FUN_008c9300(int a);
};
// Calls WaitForTasksDuringRendering on g_011dfbe8 and g_011dfc04.
// @fnv 0x008c9300
void FUN_008c9300_shell::FUN_008c9300(int aiUnused)
{
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008c9300::ATM *>(&::g_011dfbe8))))->WaitForTasksDuringRendering();
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008c9300::ATM *>(&::g_011dfc04))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_008c9300

struct FUN_008c9a50_shell
{
    int m_uiContentCount;
    int m_auiShapeKeys;
    int m_uiFilterValue;
    FUN_008c9a50_shell* FUN_008c9a50(int value);
};
// Sets the first field to 1 and stores value in the third field, then returns this.
// @fnv 0x008c9a50
FUN_008c9a50_shell* FUN_008c9a50_shell::FUN_008c9a50(int value)
{
    m_uiContentCount = 1;
    m_uiFilterValue = value;
    return this;
}

struct Obj_008c9a80
{
    char pad[0x18];
    int m_items[10];
    int m_40;
    int m_44;
    void PushItem(int a);
};

// Stores a into m_items at a circular index derived from m_44 and m_40, then increments m_40, if m_40 is below 10.
// @fnv 0x008c9a80
void Obj_008c9a80::PushItem(int aiValue)
{
    if (m_40 < 10)
    {
        int iIndex = m_44 + m_40;
        if (iIndex >= 10)
            iIndex -= 10;
        m_items[iIndex] = aiValue;
        m_40 = m_40 + 1;
    }
}

struct FUN_008c9ec0_shell
{
    void FUN_008c9ef0();
    void* FUN_008c9ec0(unsigned int flags);
};
struct GlobalObject_0078d3b0
{
    char d[0xc];
    ~GlobalObject_0078d3b0();
};
struct FUN_0052d240_obj
{
    char d[0x10];
    ~FUN_0052d240_obj();
};
struct FUN_00aa63c0_base
{
    char d[0x30];
    ~FUN_00aa63c0_base();
};
extern int _data_011c16bc;
struct FUN_008c9ef0 : FUN_00aa63c0_base
{
    GlobalObject_0078d3b0 a;
    GlobalObject_0078d3b0 b;
    char pad[8];
    FUN_0052d240_obj c;
    ~FUN_008c9ef0();
};
// @fnv 0x008c9ec0
void* FUN_008c9ec0_shell::FUN_008c9ec0(unsigned int flags)
{
    reinterpret_cast<::FUN_008c9ef0 *>(this)->FUN_008c9ef0::~FUN_008c9ef0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor for FUN_008c9ef0; the body is empty.
// @fnv 0x008c9ef0
FUN_008c9ef0::~FUN_008c9ef0()
{}

struct CountingSemaphore
{
};
struct FUN_008c9fb0_shell
{
    void SignalAtOffset30();
};
// @fnv 0x008c9fb0
void FUN_008c9fb0_shell::SignalAtOffset30()
{
    reinterpret_cast<::FUN_00442550_shell *>((((CountingSemaphore*)((char*)this + 0x30))))->ReleaseAndInitScriptRunLock();
}

namespace fnv_008ca2e0 {
struct FUN_008c9fb0_shell
{
};
struct FUN_008ca2e0_shell
{
    void CallAt(int a);
};
// @fnv 0x008ca2e0
void FUN_008ca2e0_shell::CallAt(int iIndex)
{
    reinterpret_cast<::FUN_008c9fb0_shell *>((((FUN_008c9fb0_shell**)this)[iIndex]))->SignalAtOffset30();
}
}  // namespace fnv_008ca2e0

struct GlobalObject_008caae0
{
};

struct FUN_008ca300_shell
{
    void FUN_008ca300();
};

struct FUN_008ca330_shell
{
    void FUN_008ca330(int a);
};
// @fnv 0x008ca300
void FUN_008ca300_shell::FUN_008ca300()
{
    if (*(unsigned char*)((char*)this + 0x10180))
    {
        reinterpret_cast<::FUN_008ca330_shell *>(&(::g_011dfc24))->FUN_008ca330(2);
        *(unsigned char*)((char*)this + 0x10180) = 0;
    }
}
// @fnv 0x008ca330
void FUN_008ca330_shell::FUN_008ca330(int aiIndex)
{
    ::FUN_008c7490((::FUN_008c7490_this *)(((void**)this)[aiIndex]));
}

extern int DAT_0108583c;

// @fnv 0x008ca3c0
void FUN_008ca3c0(void* thisPtr)
{
    *static_cast<void**>(thisPtr) = &DAT_0108583c;
}

struct FUN_008ca3e0_shell
{
    void FUN_008ca3c0();
    void* FUN_008ca3e0(unsigned int flags);
};
// Calls FUN_008ca3c0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008ca3e0
void* FUN_008ca3e0_shell::FUN_008ca3e0(unsigned int flags)
{
    ::FUN_008ca3c0((void *)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_008ca410_shell
{
    void FUN_008ca350();
    void* FUN_008ca410(unsigned int flags);
};
struct FUN_008ca740
{
    int m_pad4;
    FUN_008ca740();
    virtual void vfn0();
};

struct FUN_008ca440 : FUN_008ca740
{
    int m_08;
    int m_0c;
    int* m_10;
    FUN_008ca440(int a);
    virtual void vfn0();
};

// Stores the constructor argument in m_08, zeroes m_0c, and points m_10 at m_0c.
// @fnv 0x008ca440
FUN_008ca440::FUN_008ca440(int aiValue)
{
    m_08 = aiValue;
    m_0c = 0;
    m_10 = &m_0c;
}

struct FUN_008ca520_shell
{
    void InitVtbl();
};
extern int DAT_01085864;

// @fnv 0x008ca500
void FUN_008ca500(void* this_ptr)
{
    *(void**)this_ptr = &DAT_01085864;
    ((FUN_008ca520_shell*)this_ptr)->InitVtbl();
}

namespace fnv_008ca520 {
struct FUN_008ca520_shell
{
    int* vtbl;
    void InitVtbl();
};
// @fnv 0x008ca520
void FUN_008ca520_shell::InitVtbl()
{
    vtbl = &::DAT_01085884;
}
}  // namespace fnv_008ca520

struct FUN_008ca540_shell
{
    void FUN_008ca500();
    void* FUN_008ca540(unsigned int flags);
};
// Calls FUN_008ca500, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008ca540
void* FUN_008ca540_shell::FUN_008ca540(unsigned int flags)
{
    ::FUN_008ca500((void *)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_008ca570_shell
{
    void* FUN_008ca570(unsigned int flags);
};
// Calls InitVtbl, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008ca570
void* FUN_008ca570_shell::FUN_008ca570(unsigned int flags)
{
    reinterpret_cast<::fnv_008ca520::FUN_008ca520_shell *>(this)->InitVtbl();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_008ca5a0_node
{
    int a;
    int b;
    int c;
    FUN_008ca5a0_node* next;
};
struct FUN_008ca5a0_pool
{
};
struct FUN_008ca5a0_mgr
{
    int f0;
    int f4;
    FUN_008ca5a0_pool* pool;
    FUN_008ca5a0_node* head;
    FUN_008ca5a0_node** tail;
    bool AppendNode(unsigned int arg);
};
// @fnv 0x008ca5a0
bool FUN_008ca5a0_mgr::AppendNode(unsigned int arg)
{
    bool result;
    FUN_008ca5a0_node* node;
    if (pool && reinterpret_cast<::FUN_008ca7c0_shell *>((pool))->FUN_008ca7c0((int)(&node), arg))
    {
        if (!head)
            tail = &head;
        *tail = node;
        node->next = 0;
        tail = &node->next;
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}

struct List_009e03e0
{
    void RemoveAll();
};

struct Obj_009529d0
{
    char pad[0x6b8];
    int m_6b8;
    char pad2[0x6c4 - 0x6bc];
    List_009e03e0 m_6c4;
    void FUN_009529d0(int a);
};

// If the new value differs from m_6b8, stores it and, when it becomes zero, clears the m_6c4 list.
// @fnv 0x009529d0
void Obj_009529d0::FUN_009529d0(int a)
{
    if (a != m_6b8)
    {
        m_6b8 = a;
        if (m_6b8)
        {
        }
        else
        {
            reinterpret_cast<::FileMatchList *>(&(m_6c4))->RemoveAll();
        }
    }
}

struct BaseT
{
    int m_auiShapeKeys[7];
    ~BaseT();
};

struct FUN_008ca480
{
    int m_v;
    ~FUN_008ca480();
};

struct FUN_008c83a0 : BaseT
{
    FUN_008ca480 m_1c;
    ~FUN_008c83a0();
};
// Calls FUN_008c83a0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x008c8370
FUN_008c8370_shell* FUN_008c8370_shell::FUN_008c8370(unsigned int flags)
{
    reinterpret_cast<::FUN_008c83a0 *>(this)->FUN_008c83a0::~FUN_008c83a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Calls FUN_008c8430, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008c8400
FUN_008c8400_shell* FUN_008c8400_shell::FUN_008c8400(unsigned int flags)
{
    reinterpret_cast<::FUN_008c8430_shell *>(this)->FUN_008c8430();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x008c8430
void FUN_008c8430_shell::FUN_008c8430()
{
    vtbl = &DAT_01085728;
    reinterpret_cast<::FUN_008c83a0 *>(this)->FUN_008c83a0::~FUN_008c83a0();
}
// Calls FUN_008c8890, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008c8860
void* FUN_008c8860_shell::FUN_008c8860(unsigned int flags)
{
    reinterpret_cast<::FUN_008c8890_shell *>(this)->FUN_008c8890();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x008c8890
void FUN_008c8890_shell::FUN_008c8890()
{
    vtbl = &DAT_01085768;
    reinterpret_cast<::FUN_008c83a0 *>(this)->FUN_008c83a0::~FUN_008c83a0();
}
// @fnv 0x008c89d0
void* FUN_008c89d0_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_008c8a00_shell *>(this)->FUN_008c8a00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x008c8a00
void FUN_008c8a00_shell::FUN_008c8a00()
{
    vtbl = &DAT_01085788;
    reinterpret_cast<::FUN_008c83a0 *>(this)->FUN_008c83a0::~FUN_008c83a0();
}
// @fnv 0x008c8b20
void* FUN_008c8b20_shell::DestroyOrReturnSelf(unsigned int flags)
{
    reinterpret_cast<::FUN_008c8b50_shell *>(this)->FUN_008c8b50();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x008c8b50
void FUN_008c8b50_shell::FUN_008c8b50()
{
    vtbl = &DAT_010857a8;
    reinterpret_cast<::FUN_008c83a0 *>(this)->FUN_008c83a0::~FUN_008c83a0();
}
// Calls FUN_008c9080, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008c9050
void* FUN_008c9050_shell::FUN_008c9050(unsigned int flags)
{
    reinterpret_cast<::FUN_008c9080_shell *>(this)->FUN_008c9080();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x008c9080
void FUN_008c9080_shell::FUN_008c9080()
{
    vtbl = &DAT_010857c8;
    reinterpret_cast<::FUN_008c83a0 *>(this)->FUN_008c83a0::~FUN_008c83a0();
}
// @fnv 0x008c91d0
void FUN_008c91d0_shell::FUN_008c91d0()
{
    m_vft = &DAT_010857e8;
    reinterpret_cast<::FUN_008c83a0 *>(this)->FUN_008c83a0::~FUN_008c83a0();
}

// Destructor for FUN_008c83a0; the body is empty and the base and member destructors run implicitly.
// @fnv 0x008c83a0
FUN_008c83a0::~FUN_008c83a0()
{}

struct FUN_008c8430_base
{
    char d[0x40];
    ~FUN_008c8430_base();
};
struct FUN_008c8890_m
{
    char d[0x38];
    ~FUN_008c8890_m();
};
struct FUN_008c8b50_m
{
    char d[0x44];
    ~FUN_008c8b50_m();
};
struct FUN_008c8a00_m
{
    char d[0x3c];
    ~FUN_008c8a00_m();
};
struct FUN_008c9080_m
{
    char d[0x40];
    ~FUN_008c9080_m();
};
struct FUN_008c91d0_m
{
    char d[0x3c];
    ~FUN_008c91d0_m();
};
struct FUN_008ca350_m
{
    char d[0x20];
    ~FUN_008ca350_m();
};
struct FUN_008c9430 : FUN_008c8430_base
{
    FUN_008c8890_m a;
    FUN_008c8b50_m b;
    FUN_008c8a00_m c;
    FUN_008c9080_m d;
    FUN_008c91d0_m e;
    FUN_008ca350_m f;
    ~FUN_008c9430();
};
// @fnv 0x008c9430
FUN_008c9430::~FUN_008c9430()
{}

struct FUN_008c9a20_shell
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    FUN_008c9a20_shell* FUN_008c9a20(unsigned int v);
};
// Initialises the object's fields: sets a and c to 0 and stores v in b, then returns this.
// @fnv 0x008c9a20
FUN_008c9a20_shell* FUN_008c9a20_shell::FUN_008c9a20(unsigned int v)
{
    a = 0;
    b = v;
    c = 0;
    return this;
}

struct BSThread
{
    char d[0x30];
    void Initialize(int stackSize, const char* name, bool b);
    void SetSchedulingPriority(unsigned int);
    void SetName(const char*);
};
struct FUN_008c9bd0 : BSThread
{
    char e[0x48];
    FUN_008c9bd0(unsigned int aiThread);
};
struct FUN_008c9ae0_mgr
{
    FUN_008c9bd0* threads[3];
    int count;
    void CreateThread(unsigned int aiThread);
};
// @fnv 0x008c9ae0
void FUN_008c9ae0_mgr::CreateThread(unsigned int aiThread)
{
    if (count < 3)
    {
        threads[count] = new FUN_008c9bd0(aiThread);
        threads[count]->Initialize(0x10000, 0, false);
        threads[count]->SetSchedulingPriority(aiThread);
        threads[count]->SetName("AI Task Thread");
        count = count + 1;
    }
}

namespace fnv_008c9bd0 {
struct BSThread
{
    virtual void v0();
    char d[0x2c];
    BSThread();
    ~BSThread();
};
struct CountingSemaphore
{
    char d[0xc];
    CountingSemaphore(int, int);
    ~CountingSemaphore();
};
struct NineIntegerRecord
{
    char d[0x100];
    NineIntegerRecord();
};
struct FUN_008c9bd0 : BSThread
{
    CountingSemaphore start;
    CountingSemaphore finish;
    unsigned char quit;
    unsigned int arg;
    NineIntegerRecord router;
    FUN_008c9bd0(unsigned int aiThread);
    virtual void v0();
};
// Initializes the thread's start and finish objects, stores the thread argument in arg, and clears quit.
// @fnv 0x008c9bd0
FUN_008c9bd0::FUN_008c9bd0(unsigned int aiThread) : start(0, 10), finish(0, 10)
{
    arg = aiThread;
    quit = 0;
}
}  // namespace fnv_008c9bd0

struct FUN_008c8190
{
    char data[12];
    FUN_008c8190();
};
struct Mid
{
    virtual void _a();
    virtual void _b(const FUN_008c8190&);
};
struct Owner
{
    void CallMidVirtualB();
};
// Constructs a FUN_008c8190 temporary and invokes the virtual _b on the Mid subobject at offset 0x1c of this.
// @fnv 0x008ca040
void Owner::CallMidVirtualB()
{
    reinterpret_cast<Mid*>(reinterpret_cast<char*>(this) + 0x1c)->_b(FUN_008c8190());
}

struct Date
{
    int m_v[4];
    ~Date();
};
struct FUN_008ca3c0
{
    int m_auiShapeKeys[2];
    virtual ~FUN_008ca3c0();
};
struct FUN_008ca350 : FUN_008ca3c0
{
    Date m_items[0x1000];
    virtual ~FUN_008ca350();
};
// @fnv 0x008ca410
void* FUN_008ca410_shell::FUN_008ca410(unsigned int flags)
{
    reinterpret_cast<::FUN_008ca350 *>(this)->FUN_008ca350::~FUN_008ca350();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructs the array of Date elements held by the object.
// @fnv 0x008ca350
FUN_008ca350::~FUN_008ca350()
{}

namespace fnv_008ca480 {
struct Tmp_008ca480
{
    int a, b, c;
    Tmp_008ca480();
};
struct FUN_008ca500
{
    int m_auiShapeKeys;
    virtual ~FUN_008ca500();
};
struct FUN_008ca480 : FUN_008ca500
{
    virtual ~FUN_008ca480();
};
// Destructor that repeatedly calls FUN_006ec390 with a temporary Tmp_008ca480 until it returns false.
// @fnv 0x008ca480
FUN_008ca480::~FUN_008ca480()
{
    Tmp_008ca480 t;
    while (reinterpret_cast<::FUN_006ec390_Class *>(this)->FUN_006ec390((int)(&t)))
    {
    }
}
}  // namespace fnv_008ca480

struct Node_008ca620;
struct Arg_008ca620
{
};
struct List_008ca620
{
};
struct Node_008ca620
{
    int m_auiShapeKeys[3];
    Node_008ca620* m_0c;
};
struct Obj_008ca620
{
    int m_auiShapeKeys[2];
    List_008ca620* m_08;
    Node_008ca620* m_0c;
    bool PopNode(Arg_008ca620* a);
};

// @fnv 0x008ca620
bool Obj_008ca620::PopNode(Arg_008ca620* a)
{
    bool bPopped;
    Node_008ca620* node = m_0c;
    if (node)
    {
        reinterpret_cast<::FUN_008_Struct *>((a))->FUN_008caa70((::FUN_008_Struct *)(void *)(((void *)(((::Vec3 *)(void *)(node))))));
        m_0c = node->m_0c;
        reinterpret_cast<::FUN_008ca770_Class *>((m_08))->FUN_008ca770((::Date **)(::Node_008ca620 **)(&node));
        bPopped = true;
    }
    else
    {
        bPopped = false;
    }
    return bPopped;
}

namespace fnv_008ca680 {
struct GlobalObject_008caae0
{
    char d[0x10];
    GlobalObject_008caae0();
    ~GlobalObject_008caae0();
};
struct FUN_008ca800_base
{
    virtual void v0();
    char d[8];
    FUN_008ca800_base();
    ~FUN_008ca800_base();
};
struct FUN_008ca680 : FUN_008ca800_base
{
    GlobalObject_008caae0 items[0x1000];
    FUN_008ca680();
    virtual void v0();
};
// Constructs the object and calls InitFreeList with 0x1000 and the items array.
// @fnv 0x008ca680
FUN_008ca680::FUN_008ca680()
{
    reinterpret_cast<::FUN_008ca830_cls *>(this)->InitFreeList(0x1000, (::FreeNode16 *)(items));
}
}  // namespace fnv_008ca680

struct FUN_008ca710_shell
{
    void FUN_008ca480();
    void* FUN_008ca710(unsigned int flags);
};
// @fnv 0x008ca710
void* FUN_008ca710_shell::FUN_008ca710(unsigned int flags)
{
    reinterpret_cast<::fnv_008ca480::FUN_008ca480 *>(this)->fnv_008ca480::FUN_008ca480::~FUN_008ca480();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct AnimationTaskData
{
    void FUN_008c8910(MobileObject* apMob);
};

// If apMob is an actor with a flag at offset 0xbc set, or a talking activator, calls Unk_9A with 0.0f.
// @fnv 0x008c8910
void AnimationTaskData::FUN_008c8910(MobileObject* apMob)
{
    MobileObject* pmob = apMob;
    if (pmob && pmob->IsActor())
    {
        Actor* pact = (Actor*)pmob;
        if (pact->m_bFirstActorFlag)
        {
            pact->Unk_9A(0.0f);
        }
    }
    else if (pmob && ((bool)(::FUN_00574900((const unsigned char *)(pmob)))))
    {
        pmob->Unk_9A(0.0f);
    }
}

namespace fnv_008c8240 {
struct FUN_008c8190
{
    int _00;
    int _04;
    int _08;
    FUN_008c8190();
};
struct MsgQueue
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual bool Pop(FUN_008c8190*)
    {
        return false;
    }
};
struct MessageQueueHandler
{
    char _00[0x1c];
    MsgQueue m_kMessageQueue;
    char _20[0x14];
    int _34;
    bool ProcessMessage(FUN_008c8190*, int);
    void FUN_008c8240(int);
};
// @fnv 0x008c8240
void MessageQueueHandler::FUN_008c8240(int eType)
{
    _34 = eType;
    FUN_008c8190 msg;
    while (m_kMessageQueue.Pop(&msg))
    {
        if (!ProcessMessage(&msg, eType))
            break;
    }
}
}  // namespace fnv_008c8240

struct Script
{
    static bool __cdecl IsConsolePlatform();
};
struct MobileObjectExt
{
};
struct ActorsScriptTaskData
{
    unsigned char _pad[0x3C];
    int m_3C;
    void FUN_008c9110(MobileObject* apMob);
};
// If apMob is an actor and the script check passes, calls FUN_00565870 on it and increments m_3C.
// @fnv 0x008c9110
void ActorsScriptTaskData::FUN_008c9110(MobileObject* apMob)
{
    MobileObject* pmob = apMob;
    if (pmob && pmob->IsActor() && Script::IsConsolePlatform())
    {
        reinterpret_cast<::fnv_00565870::FUN_00565870_shell *>((((MobileObjectExt*)pmob)))->FUN_00565870();
        m_3C++;
    }
}

struct MobileObjectTaskletContext
{
    int m_iFirstValue;
    unsigned int ItemUpdateArray;
    void* pCurrentObject;
};

struct FUN_008c81c0_shell
{
    void* m_vtbl;
    void* m_kNode;
    unsigned int m_uiHighActorCount;
    void SetActorCount(unsigned int);
    void SetMob(void*);
    void SetCount(unsigned int);
    bool ProcessMessage(const MobileObjectTaskletContext* aMessage, unsigned int aThread);
};

typedef void(* SetCountFn)(FUN_008c81c0_shell*, unsigned int);
typedef void(* SetMobFn)(FUN_008c81c0_shell*, void*);

// @fnv 0x008c81c0
bool FUN_008c81c0_shell::ProcessMessage(const MobileObjectTaskletContext* aMessage, unsigned int aThread)
{
    bool bResult = true;
    switch (aMessage->m_iFirstValue)
    {
    case 0:
        *(unsigned int*)((char*)this + 0x30) = aMessage->ItemUpdateArray;
        ((SetCountFn*)m_vtbl)[4](this, aMessage->ItemUpdateArray);
        break;
    case 1:
        ((SetMobFn*)m_vtbl)[5](this, aMessage->pCurrentObject);
        break;
    case 2:
        ((SetCountFn*)m_vtbl)[6](this, aThread);
        bResult = false;
        break;
    }
    return bResult;
}

namespace fnv_008c8130 {
struct FUN_008c8190
{
    int a;
    int b;
    int c;
    FUN_008c8190();
};
typedef FUN_008c8190 MobileObjectTaskletContext;
struct PathingTaskData
{
};
struct MsgQueue
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual bool GetMsg(MobileObjectTaskletContext*);
    int _pad[5];
};
struct MobileObjectTaskletData
{
    int _pad0[7];
    MsgQueue m_kMessageQueue;
    int eType;
    void FUN_008c8130();
};
// Drains messages from the queue, stops if ProcessMessage rejects one, otherwise calls FUN_006ea330 on this as PathingTaskData.
// @fnv 0x008c8130
void MobileObjectTaskletData::FUN_008c8130()
{
    MobileObjectTaskletContext msg;
    while (m_kMessageQueue.GetMsg(&msg))
    {
        if (!reinterpret_cast<::FUN_008c81c0_shell *>(this)->ProcessMessage((const ::MobileObjectTaskletContext *)(void *)(&msg), eType))
            return;
    }
    reinterpret_cast<::FUN_006ea330_shell *>((((PathingTaskData*)this)))->FUN_006ea330();
}
}  // namespace fnv_008c8130

namespace fnv_008c82a0 {
struct FUN_008c82e0
{
    int pad[13];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c82a0 : FUN_008c82e0
{
    float f38;
    int f3c;
    FUN_008c82a0(int a);
    virtual void Run();
};
// Initializes the derived object's f38 to 0.0f and f3c to 0 after constructing the base with a.
// @fnv 0x008c82a0
FUN_008c82a0::FUN_008c82a0(int a) : FUN_008c82e0(a)
{
    f38 = 0.0f;
    f3c = 0;
}
}  // namespace fnv_008c82a0

namespace fnv_008c82e0 {
struct FUN_006c7850_base
{
    virtual void v0();
    char d[0x14];
    FUN_006c7850_base();
    ~FUN_006c7850_base();
};
struct FUN_008ca440_member
{
    char d[0x14];
    FUN_008ca440_member(unsigned int);
};
struct FUN_008c82e0 : FUN_006c7850_base
{
    int f18;
    FUN_008ca440_member list;
    int f30;
    int f34;
    FUN_008c82e0(unsigned int arg);
    virtual void v0();
};
// Constructor: initializes f18, f30 and f34 to 0 and constructs the list member from arg.
// @fnv 0x008c82e0
FUN_008c82e0::FUN_008c82e0(unsigned int arg) : f18(0), list(arg), f30(0), f34(0)
{}
}  // namespace fnv_008c82e0

namespace fnv_008c8450 {
struct ATM
{
    void QueryPerformanceCounter(int);
};
struct MovementTaskData
{
    int pad[14];
    float f38;
    int f3c;
    void FUN_008c8450(unsigned int a);
};
// Clears f38 and f3c, then calls QueryPerformanceCounter on g_011dfc04 and g_011dfbe8.
// @fnv 0x008c8450
void MovementTaskData::FUN_008c8450(unsigned int auUnused)
{
    f38 = 0.0f;
    f3c = 0;
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c8450::ATM *>(&::g_011dfc04))))->FUN_004538a0(0);
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c8450::ATM *>(&::g_011dfbe8))))->FUN_004538a0(0);
}
}  // namespace fnv_008c8450

namespace fnv_008c8ae0 {
struct FUN_008c82e0
{
    int pad[14];
    FUN_008c82e0(int a);
    virtual void Run();
};
struct FUN_008c8ae0 : FUN_008c82e0
{
    int f3c;
    int f40;
    FUN_008c8ae0(int a);
    virtual void Run();
};
// Initializes the two derived-class fields f3c and f40 to zero after constructing the base class.
// @fnv 0x008c8ae0
FUN_008c8ae0::FUN_008c8ae0(int a) : FUN_008c82e0(a)
{
    f3c = 0;
    f40 = 0;
}
}  // namespace fnv_008c8ae0

namespace fnv_008c8b70 {
struct ATM
{
    void QueryPerformanceCounter(int);
};
struct Actor
{
};
struct PackageUpdateTaskData
{
    int pad[15];
    int f3c;
    int f40;
    void FUN_008c8b70(unsigned int a);
};
// @fnv 0x008c8b70
void PackageUpdateTaskData::FUN_008c8b70(unsigned int auiUnused)
{
    f3c = 0;
    f40 = 0;
    ::FUN_008c8bd0();
    reinterpret_cast<::ST_008c8bb0 *>(((*reinterpret_cast<::fnv_008c8b70::Actor * *>(&::_g_thePlayer))))->FUN_008c8bb0(0);
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c8b70::ATM *>(&::g_011dfbe8))))->FUN_004538a0(0);
}
}  // namespace fnv_008c8b70

namespace fnv_008c90a0 {
struct ATM
{
    void QueryPerformanceCounter(int);
};
struct ActorsScriptTaskData
{
    int pad[15];
    int f3c;
    void FUN_008c90a0(unsigned int a);
};
// Clears f3c and queries the three performance counters with argument 0.
// @fnv 0x008c90a0
void ActorsScriptTaskData::FUN_008c90a0(unsigned int a)
{
    f3c = 0;
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c90a0::ATM *>(&::g_011dfc38))))->FUN_004538a0(0);
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c90a0::ATM *>(&::g_011dfc04))))->FUN_004538a0(0);
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008c90a0::ATM *>(&::g_011dfbe8))))->FUN_004538a0(0);
}
}  // namespace fnv_008c90a0

namespace fnv_008c9c70 {
struct CountingSemaphore
{
    char d[0xc];
};
struct MobileObjectTaskletData
{
};
struct GlobalObject_008caab0
{
    MobileObjectTaskletData* FUN_008c9cf0();
};
struct FUN_008c9c70_cls
{
    char pad0[0x30];
    CountingSemaphore start;
    CountingSemaphore finish;
    unsigned char quit;
    char pad1[3];
    int arg;
    void InitMemory();
    void DispatchTask();
    unsigned int RunTaskletLoop();
};
// Waits on start, processes tasklet data via g_011dfb98 until none remain, signals finish, and exits when quit is set.
// @fnv 0x008c9c70
unsigned int FUN_008c9c70_cls::RunTaskletLoop()
{
    MobileObjectTaskletData* pTaskletData;
    InitMemory();
    while (1)
    {
        reinterpret_cast<::SemaphoreWaitReceiver *>(&(start))->FUN_004424e0();
        if (quit)
            break;
        pTaskletData = 0;
        do
        {
            pTaskletData = (*reinterpret_cast<::fnv_008c9c70::GlobalObject_008caab0 *>(&::g_011dfb98)).FUN_008c9cf0();
            if (pTaskletData)
                reinterpret_cast<::fnv_008c8240::MessageQueueHandler *>((pTaskletData))->FUN_008c8240(arg);
        } while (pTaskletData);
        reinterpret_cast<::FUN_00442550_shell *>(&(finish))->ReleaseAndInitScriptRunLock();
    }
    DispatchTask();
    return 0;
}
}  // namespace fnv_008c9c70

struct Elem
{
};
struct FUN_008c9f70_this
{
    int pad[3];
    int count;
    void CallAllElements();
};
// Iterates over count elements and calls SignalAtOffset30 on each one.
// @fnv 0x008c9f70
void FUN_008c9f70_this::CallAllElements()
{
    for (int i = 0; i < count; i++)
        reinterpret_cast<::FUN_008c9fb0_shell *>((((Elem**)this)[i]))->SignalAtOffset30();
}

struct FUN_008c7490_this;
struct FUN_008c9fd0_this
{
    int pad[3];
    int count;
    void FUN_008c9fd0();
};
// Calls FUN_008c7490 on each of the count pointers stored in the array starting at this.
// @fnv 0x008c9fd0
void FUN_008c9fd0_this::FUN_008c9fd0()
{
    for (int i = 0; i < count; i++)
        FUN_008c7490(((FUN_008c7490_this**)this)[i]);
}

struct S008ca010
{
    virtual void f0();
    virtual void f1(int);
};
struct H008ca010
{
    char pad[0x1C];
    S008ca010 inner;
    void ForwardToInner(int);
};
// Calls f1 on the inner object, passing the given int through.
// @fnv 0x008ca010
void H008ca010::ForwardToInner(int aiValue)
{
    inner.f1(aiValue);
}

struct VTMobileObjectBase
{
    virtual void m00();
    virtual void m01();
    virtual void m02();
    virtual void m03();
    virtual void m04();
    virtual void m05();
    virtual void m06();
    virtual void m07();
    virtual void m08();
    virtual void m09();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
};

struct VTMobileObject : VTMobileObjectBase
{
    virtual bool v100();
};

struct VTActorBase
{
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void a019();
    virtual void a020();
    virtual void a021();
    virtual void a022();
    virtual void a023();
    virtual void a024();
    virtual void a025();
    virtual void a026();
    virtual void a027();
    virtual void a028();
    virtual void a029();
    virtual void a030();
    virtual void a031();
    virtual void a032();
    virtual void a033();
    virtual void a034();
    virtual void a035();
    virtual void a036();
    virtual void a037();
    virtual void a038();
    virtual void a039();
    virtual void a040();
    virtual void a041();
    virtual void a042();
    virtual void a043();
    virtual void a044();
    virtual void a045();
    virtual void a046();
    virtual void a047();
    virtual void a048();
    virtual void a049();
    virtual void a050();
    virtual void a051();
    virtual void a052();
    virtual void a053();
    virtual void a054();
    virtual void a055();
    virtual void a056();
    virtual void a057();
    virtual void a058();
    virtual void a059();
    virtual void a060();
    virtual void a061();
    virtual void a062();
    virtual void a063();
    virtual void a064();
    virtual void a065();
    virtual void a066();
    virtual void a067();
    virtual void a068();
    virtual void a069();
    virtual void a070();
    virtual void a071();
    virtual void a072();
    virtual void a073();
    virtual void a074();
    virtual void a075();
    virtual void a076();
    virtual void a077();
    virtual void a078();
    virtual void a079();
    virtual void a080();
    virtual void a081();
    virtual void a082();
    virtual void a083();
    virtual void a084();
    virtual void a085();
    virtual void a086();
    virtual void a087();
    virtual void a088();
    virtual void a089();
    virtual void a090();
    virtual void a091();
    virtual void a092();
    virtual void a093();
    virtual void a094();
    virtual void a095();
    virtual void a096();
    virtual void a097();
    virtual void a098();
    virtual void a099();
    virtual void a100();
    virtual void a101();
    virtual void a102();
    virtual void a103();
    virtual void a104();
    virtual void a105();
    virtual void a106();
    virtual void a107();
    virtual void a108();
    virtual void a109();
    virtual void a110();
    virtual void a111();
    virtual void a112();
    virtual void a113();
    virtual void a114();
    virtual void a115();
    virtual void a116();
    virtual void a117();
    virtual void a118();
    virtual void a119();
    virtual void a120();
    virtual void a121();
    virtual void a122();
    virtual void a123();
    virtual void a124();
    virtual void a125();
    virtual void a126();
    virtual void a127();
    virtual void a128();
    virtual void a129();
    virtual void a130();
    virtual void a131();
    virtual void a132();
    virtual void a133();
    virtual void a134();
    virtual void a135();
    virtual void a136();
    virtual void a137();
    virtual void a138();
    virtual void a139();
    virtual void a140();
    virtual void a141();
    virtual void a142();
    virtual void a143();
    virtual void a144();
    virtual void a145();
    virtual void a146();
    virtual void a147();
    virtual void a148();
    virtual void a149();
    virtual void a150();
    virtual void a151();
    virtual void a152();
    virtual void a153();
    virtual void a154();
    virtual void a155();
    virtual void a156();
    virtual void a157();
    virtual void a158();
    virtual void a159();
    virtual void a160();
    virtual void a161();
    virtual void a162();
    virtual void a163();
    virtual void a164();
    virtual void a165();
    virtual void a166();
    virtual void a167();
    virtual void a168();
    virtual void a169();
    virtual void a170();
    virtual void a171();
    virtual void a172();
    virtual void a173();
    virtual void a174();
    virtual void a175();
    virtual void a176();
    virtual void a177();
    virtual void a178();
    virtual void a179();
    virtual void a180();
    virtual void a181();
    virtual void a182();
    virtual void a183();
    virtual void a184();
    virtual void a185();
    virtual void a186();
    virtual void a187();
    virtual void a188();
    virtual void a189();
};

struct VTActor : VTActorBase
{
    virtual void v2f8(float);
};

struct ActorUpdateTaskData
{
    char m_auiShapeKeys[0x38];
    int m_unk38;
    void UpdateActorTask(MobileObject* apMob);
};

// If apMob is a valid mobile object with v100 set, resets the actor's v2f8 to 0 when byte 0xbc is nonzero and increments m_unk38.
// @fnv 0x008c8a70
void ActorUpdateTaskData::UpdateActorTask(MobileObject* apMob)
{
    MobileObject* pmob = apMob;
    VTActor* pact;
    if (pmob != 0 && ((VTMobileObject*)pmob)->v100())
    {
        pact = (VTActor*)pmob;
        if (*((unsigned char*)pact + 0xbc) != 0)
        {
            pact->v2f8(0.0f);
        }
        m_unk38++;
    }
}

struct M0
{
    char pad[0x40];
    M0(void*);
    ~M0();
};
struct M1
{
    char pad[0x38];
    M1(void*);
    ~M1();
};
struct M2
{
    char pad[0x44];
    M2(void*);
    ~M2();
};
struct M3
{
    char pad[0x3c];
    M3(void*);
    ~M3();
};
struct M4
{
    char pad[0x40];
    M4(void*);
    ~M4();
};
struct M5
{
    char pad[0x3c];
    M5(void*);
    ~M5();
};
struct M6
{
    char pad[0x1000c];
    void FUN_008ca680();
};

struct FUN_008c9330
{
    M0 m0;
    M1 m1;
    M2 m2;
    M3 m3;
    M4 m4;
    M5 m5;
    M6 m6;
    char m_flag;

    FUN_008c9330();
};

// Constructs the object, initializing m0 through m5 with a pointer to m6, calling m6.FUN_008ca680(), and setting m_flag to 0.
// @fnv 0x008c9330
FUN_008c9330::FUN_008c9330() : m0(&m6), m1(&m6), m2(&m6), m3(&m6), m4(&m6), m5(&m6)
{
    new ((void *)&(m6)) ::fnv_008ca680::FUN_008ca680();
    m_flag = 0;
}

namespace fnv_0077a480 {
struct GameTimerRecord
{
};


struct TESQuest
{
};

class ATM
{
  public:
    void QueryPerformanceCounter(int);
};

class GlobalObject_0044fae0 : public ATM
{
};

struct Obj_009529d0
{
};

struct PlayerCharacter : public Obj_009529d0
{
};



struct Task
{
    void* quest;
    int state;
    unsigned char padding[0x31c];
};

// @fnv 0x0077a480
void __cdecl FUN_0077a480(TESQuest* quest)
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_0077a480::GlobalObject_0044fae0 *>(&::g_011d96cc))))->FUN_004538a0(0);

    if (quest == 0 || (*reinterpret_cast<int *>(&::g_pHudMainMenuInstance)) == 0)
        return;

    ::DAT_011d96ac = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((void *)&((*reinterpret_cast<::fnv_0077a480::GameTimerRecord *>(&::g_timeGlobal))))->FUN_00825c00();

    Task* task = new Task;
    task->quest = quest;

    if (reinterpret_cast<::TESFaction_RankDataView *>((quest))->HasFlag40())
    {
        task->state = 2;
        if (((::fnv_0077a480::TESQuest *)(::FUN_005cbb50((char *)((*reinterpret_cast<::fnv_0077a480::PlayerCharacter * *>(&::_g_thePlayer)))))) == quest)
            reinterpret_cast<::Obj_009529d0 *>(((*reinterpret_cast<::fnv_0077a480::PlayerCharacter * *>(&::_g_thePlayer))))->FUN_009529d0(0);
    }
    else if (reinterpret_cast<::FUN_0059e400_shell *>((quest))->FUN_0059e400())
    {
        task->state = 1;
        if (((::fnv_0077a480::TESQuest *)(::FUN_005cbb50((char *)((*reinterpret_cast<::fnv_0077a480::PlayerCharacter * *>(&::_g_thePlayer)))))) == quest)
            reinterpret_cast<::Obj_009529d0 *>(((*reinterpret_cast<::fnv_0077a480::PlayerCharacter * *>(&::_g_thePlayer))))->FUN_009529d0(0);
    }
    else
    {
        task->state = 0;
        if (((::fnv_0077a480::TESQuest *)(::FUN_005cbb50((char *)((*reinterpret_cast<::fnv_0077a480::PlayerCharacter * *>(&::_g_thePlayer)))))) == 0)
            reinterpret_cast<::Obj_009529d0 *>(((*reinterpret_cast<::fnv_0077a480::PlayerCharacter * *>(&::_g_thePlayer))))->FUN_009529d0(reinterpret_cast<int>(quest));
    }

    ::FUN_0076bad0(reinterpret_cast<char*>(task));

    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_0077a480::GlobalObject_0044fae0 *>(&::g_011d96cc))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_0077a480

struct ResourceHandle
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Dispatch(void* object, unsigned int flags);
};
struct Completion
{
};
struct ContextBlock
{
    unsigned int unk00;
};
struct TaskToken
{
    unsigned int value;
    TaskToken(unsigned int initialValue);
    TaskToken(const TaskToken& other);
};
struct DispatchQueue
{
    virtual void Unused0();
    virtual void Unused1();
    virtual void Unused2();
    virtual void AdvanceFade();
    virtual void Queue(ContextBlock* context, TaskToken token);
};
void FUN_00cbb990();
struct TaskOwner
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    ContextBlock context;
    unsigned int unk54, unk58, unk5c, unk60;
    unsigned int unk64, unk68, unk6c, unk70;
    void* payload;
    void DispatchTask();
};
// @fnv 0x008c9e40
void TaskOwner::DispatchTask()
{
    ((::ResourceHandle *)(reinterpret_cast<::MagicCaster_shell *>(&(context))->FUN_0044edb0()))->Dispatch(payload, 0x16800);
    FUN_00cbb990();
    ((::DispatchQueue *)(::FUN_00cbbfc0()))->Queue(&context, TaskToken(1));
    reinterpret_cast<::QuantitySet *>((((::Completion *)(((::Vec3 *)(void *)&(context))))))->FUN_008c70c0({}, {});
}

// Stand-in for the game's PlayerCharacter.  The unit file only
// forward-declares it (as PC7d), so a separate class is needed to
// reach the IsSleepingOrResting() member.
struct PlayerPC
{
};

// Stand-in for the game's HighProcess.  What matters here is the
// virtual layout (the four slots the original calls sit at vtable
// offsets 0x100 / 0x220 / 0x224 / 0x348) and the byte at +0xBC.
struct HighProcess
{
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
    unsigned char unkBC;
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual void Unk_07(void);
    virtual void Unk_08(void);
    virtual void Unk_09(void);
    virtual void Unk_0A(void);
    virtual void Unk_0B(void);
    virtual void Unk_0C(void);
    virtual void Unk_0D(void);
    virtual void Unk_0E(void);
    virtual void Unk_0F(void);
    virtual void Unk_10(void);
    virtual void Unk_11(void);
    virtual void Unk_12(void);
    virtual void Unk_13(void);
    virtual void Unk_14(void);
    virtual void Unk_15(void);
    virtual void Unk_16(void);
    virtual void Unk_17(void);
    virtual void Unk_18(void);
    virtual void Unk_19(void);
    virtual void Unk_1A(void);
    virtual void Unk_1B(void);
    virtual void Unk_1C(void);
    virtual void Unk_1D(void);
    virtual void Unk_1E(void);
    virtual void Unk_1F(void);
    virtual void Unk_20(void);
    virtual void Unk_21(void);
    virtual void Unk_22(void);
    virtual void Unk_23(void);
    virtual void Unk_24(void);
    virtual void Unk_25(void);
    virtual void Unk_26(void);
    virtual void Unk_27(void);
    virtual void Unk_28(void);
    virtual void Unk_29(void);
    virtual void Unk_2A(void);
    virtual void Unk_2B(void);
    virtual void Unk_2C(void);
    virtual void Unk_2D(void);
    virtual void Unk_2E(void);
    virtual void Unk_2F(void);
    virtual void Unk_30(void);
    virtual void Unk_31(void);
    virtual void Unk_32(void);
    virtual void Unk_33(void);
    virtual void Unk_34(void);
    virtual void Unk_35(void);
    virtual void Unk_36(void);
    virtual void Unk_37(void);
    virtual void Unk_38(void);
    virtual void Unk_39(void);
    virtual void Unk_3A(void);
    virtual void Unk_3B(void);
    virtual void Unk_3C(void);
    virtual void Unk_3D(void);
    virtual void Unk_3E(void);
    virtual void Unk_3F(void);
    virtual bool Unk_40(void);
    virtual void Unk_41(void);
    virtual void Unk_42(void);
    virtual void Unk_43(void);
    virtual void Unk_44(void);
    virtual void Unk_45(void);
    virtual void Unk_46(void);
    virtual void Unk_47(void);
    virtual void Unk_48(void);
    virtual void Unk_49(void);
    virtual void Unk_4A(void);
    virtual void Unk_4B(void);
    virtual void Unk_4C(void);
    virtual void Unk_4D(void);
    virtual void Unk_4E(void);
    virtual void Unk_4F(void);
    virtual void Unk_50(void);
    virtual void Unk_51(void);
    virtual void Unk_52(void);
    virtual void Unk_53(void);
    virtual void Unk_54(void);
    virtual void Unk_55(void);
    virtual void Unk_56(void);
    virtual void Unk_57(void);
    virtual void Unk_58(void);
    virtual void Unk_59(void);
    virtual void Unk_5A(void);
    virtual void Unk_5B(void);
    virtual void Unk_5C(void);
    virtual void Unk_5D(void);
    virtual void Unk_5E(void);
    virtual void Unk_5F(void);
    virtual void Unk_60(void);
    virtual void Unk_61(void);
    virtual void Unk_62(void);
    virtual void Unk_63(void);
    virtual void Unk_64(void);
    virtual void Unk_65(void);
    virtual void Unk_66(void);
    virtual void Unk_67(void);
    virtual void Unk_68(void);
    virtual void Unk_69(void);
    virtual void Unk_6A(void);
    virtual void Unk_6B(void);
    virtual void Unk_6C(void);
    virtual void Unk_6D(void);
    virtual void Unk_6E(void);
    virtual void Unk_6F(void);
    virtual void Unk_70(void);
    virtual void Unk_71(void);
    virtual void Unk_72(void);
    virtual void Unk_73(void);
    virtual void Unk_74(void);
    virtual void Unk_75(void);
    virtual void Unk_76(void);
    virtual void Unk_77(void);
    virtual void Unk_78(void);
    virtual void Unk_79(void);
    virtual void Unk_7A(void);
    virtual void Unk_7B(void);
    virtual void Unk_7C(void);
    virtual void Unk_7D(void);
    virtual void Unk_7E(void);
    virtual void Unk_7F(void);
    virtual void Unk_80(void);
    virtual void Unk_81(void);
    virtual void Unk_82(void);
    virtual void Unk_83(void);
    virtual void Unk_84(void);
    virtual void Unk_85(void);
    virtual void Unk_86(void);
    virtual void Unk_87(void);
    virtual bool Unk_88(void);
    virtual bool Unk_89(void);
    virtual void Unk_8A(void);
    virtual void Unk_8B(void);
    virtual void Unk_8C(void);
    virtual void Unk_8D(void);
    virtual void Unk_8E(void);
    virtual void Unk_8F(void);
    virtual void Unk_90(void);
    virtual void Unk_91(void);
    virtual void Unk_92(void);
    virtual void Unk_93(void);
    virtual void Unk_94(void);
    virtual void Unk_95(void);
    virtual void Unk_96(void);
    virtual void Unk_97(void);
    virtual void Unk_98(void);
    virtual void Unk_99(void);
    virtual void Unk_9A(void);
    virtual void Unk_9B(void);
    virtual void Unk_9C(void);
    virtual void Unk_9D(void);
    virtual void Unk_9E(void);
    virtual void Unk_9F(void);
    virtual void Unk_A0(void);
    virtual void Unk_A1(void);
    virtual void Unk_A2(void);
    virtual void Unk_A3(void);
    virtual void Unk_A4(void);
    virtual void Unk_A5(void);
    virtual void Unk_A6(void);
    virtual void Unk_A7(void);
    virtual void Unk_A8(void);
    virtual void Unk_A9(void);
    virtual void Unk_AA(void);
    virtual void Unk_AB(void);
    virtual void Unk_AC(void);
    virtual void Unk_AD(void);
    virtual void Unk_AE(void);
    virtual void Unk_AF(void);
    virtual void Unk_B0(void);
    virtual void Unk_B1(void);
    virtual void Unk_B2(void);
    virtual void Unk_B3(void);
    virtual void Unk_B4(void);
    virtual void Unk_B5(void);
    virtual void Unk_B6(void);
    virtual void Unk_B7(void);
    virtual void Unk_B8(void);
    virtual void Unk_B9(void);
    virtual void Unk_BA(void);
    virtual void Unk_BB(void);
    virtual void Unk_BC(void);
    virtual void Unk_BD(void);
    virtual void Unk_BE(void);
    virtual void Unk_BF(void);
    virtual void Unk_C0(void);
    virtual void Unk_C1(void);
    virtual void Unk_C2(void);
    virtual void Unk_C3(void);
    virtual void Unk_C4(void);
    virtual void Unk_C5(void);
    virtual void Unk_C6(void);
    virtual void Unk_C7(void);
    virtual void Unk_C8(void);
    virtual void Unk_C9(void);
    virtual void Unk_CA(void);
    virtual void Unk_CB(void);
    virtual void Unk_CC(void);
    virtual void Unk_CD(void);
    virtual void Unk_CE(void);
    virtual void Unk_CF(void);
    virtual void Unk_D0(void);
    virtual void Unk_D1(void);
    virtual void Unk_D2(float arg0, bool arg1);
};

// Stand-in for the game's MovementTaskData (the vtable slot that
// holds UpdateMovementTask).  The int at +0x38 is the task counter.
struct MovementTaskData
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
    void UpdateMovementTask(HighProcess* apMob);
};

// Advances the task counter and, depending on the mob's state, calls Unk_D2, FUN_009bec10 or FUN_009ae580 with 0.0f.
// @fnv 0x008c9220
void MovementTaskData::UpdateMovementTask(HighProcess* apMob)
{
    HighProcess* pCurrentObject = apMob;
    if (pCurrentObject && pCurrentObject->Unk_40())
    {
        HighProcess* pActor = pCurrentObject;
        if (pActor->unkBC)
        {
            pActor->Unk_D2(0.0f, reinterpret_cast<::PlayerCharacter *>((((PlayerPC*)(*reinterpret_cast<::PC7d * *>(&::_g_thePlayer)))))->IsSleepingOrResting());
        }
    }
    else
    {
        if (pCurrentObject->Unk_89())
        {
            HighProcess* pObj = pCurrentObject;
            reinterpret_cast<::GameObject *>((pObj))->FUN_009bec10(0.0f);
        }
        else if (pCurrentObject->Unk_88())
        {
            HighProcess* pTarget = pCurrentObject;
            reinterpret_cast<::FUN_009ae580_shell *>((pTarget))->FUN_009ae580(0.0f);
        }
    }
    unk38++;
}

struct CountTask
{
    unsigned state, kind, value;
};
struct ActorTask
{
    unsigned state, kind;
    Actor* value;
};
struct WorkQueue
{
    unsigned state;
};
struct BoolSettingView
{
    bool* Bool();
};
struct IntSettingView
{
};
extern bool DAT_011a34e7;
struct ThreadManagerView
{
};
struct QueueManagerView
{
};
struct ActorListView
{
};
struct ActorManagerView
{
};
struct TaskOwnerTarget
{
    WorkQueue first;
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    WorkQueue second;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    WorkQueue third;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    WorkQueue fourth;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    WorkQueue fifth;
    unsigned unk0fc;
    unsigned unk100;
    unsigned unk104;
    unsigned unk108;
    unsigned unk10c;
    unsigned unk110;
    unsigned unk114;
    unsigned unk118;
    unsigned unk11c;
    unsigned unk120;
    unsigned unk124;
    unsigned unk128;
    unsigned unk12c;
    unsigned unk130;
    unsigned unk134;
    WorkQueue sixth;
    void FUN_008c94e0();
};
// If enabled, queues count and actor tasks into the six work queues, dispatches or clears them, and runs the int-setting callbacks.
// @fnv 0x008c94e0
void TaskOwnerTarget::FUN_008c94e0()
{
    unsigned count, uiActorCount;

    if (DAT_011a34e7)
    {
        if (*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfb68)).Bool())
        {
            reinterpret_cast<::FUN_008c9ae0_mgr *>(&((*reinterpret_cast<::ThreadManagerView *>(&::g_011dfc24))))->CreateThread(1);
            reinterpret_cast<::FUN_008c9ae0_mgr *>(&((*reinterpret_cast<::ThreadManagerView *>(&::g_011dfc24))))->CreateThread(3);
            reinterpret_cast<::FUN_008c9ae0_mgr *>(&((*reinterpret_cast<::ThreadManagerView *>(&::g_011dfc24))))->CreateThread(5);
        }
        DAT_011a34e7 = false;
    }
    if (DAT_011f1220 && reinterpret_cast<::FUN_005be5c0_shell *>((((::ActorListView *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ActorManagerView *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005be5c0({}) > 0)
    {
        uiActorCount = reinterpret_cast<::FUN_005be5c0_shell *>((((::ActorListView *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ActorManagerView *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005be5c0({});
        if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfc70)).Bool())
        {
            CountTask a;
            reinterpret_cast<::H008ca010 *>(&(first))->ForwardToInner((int)&((((::CountTask *)(reinterpret_cast<::FUN_008c9a20_shell *>(&(a))->FUN_008c9a20(uiActorCount))), a)));
        }
        {
            CountTask b;
            reinterpret_cast<::H008ca010 *>(&(third))->ForwardToInner((int)&((((::CountTask *)(reinterpret_cast<::FUN_008c9a20_shell *>(&(b))->FUN_008c9a20(uiActorCount))), b)));
        }
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSettingView *>(&::g_011c3ea4)))))) == 1)
        {
            {
                CountTask c;
                reinterpret_cast<::H008ca010 *>(&(fourth))->ForwardToInner((int)&((((::CountTask *)(reinterpret_cast<::FUN_008c9a20_shell *>(&(c))->FUN_008c9a20(uiActorCount))), c)));
            }
            {
                CountTask d;
                reinterpret_cast<::H008ca010 *>(&(second))->ForwardToInner((int)&((((::CountTask *)(reinterpret_cast<::FUN_008c9a20_shell *>(&(d))->FUN_008c9a20(uiActorCount))), d)));
            }
        }
        {
            CountTask e;
            reinterpret_cast<::H008ca010 *>(&(fifth))->ForwardToInner((int)&((((::CountTask *)(reinterpret_cast<::FUN_008c9a20_shell *>(&(e))->FUN_008c9a20(uiActorCount))), e)));
        }
        if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfb88)).Bool())
        {
            CountTask f;
            reinterpret_cast<::H008ca010 *>(&(sixth))->ForwardToInner((int)&((((::CountTask *)(reinterpret_cast<::FUN_008c9a20_shell *>(&(f))->FUN_008c9a20(uiActorCount))), f)));
        }
        count = 0;
        do
        {
            if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfc70)).Bool())
            {
                ActorTask g;
                reinterpret_cast<::H008ca010 *>(&(first))->ForwardToInner((int)&((((::ActorTask *)(reinterpret_cast<::FUN_008c9a50_shell *>(&(g))->FUN_008c9a50((int)(((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::ActorListView *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ActorManagerView *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({}))))))), g)));
            }
            {
                ActorTask h;
                reinterpret_cast<::H008ca010 *>(&(third))->ForwardToInner((int)&((((::ActorTask *)(reinterpret_cast<::FUN_008c9a50_shell *>(&(h))->FUN_008c9a50((int)(((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::ActorListView *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ActorManagerView *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({}))))))), h)));
            }
            if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSettingView *>(&::g_011c3ea4)))))) == 1)
            {
                {
                    ActorTask j;
                    reinterpret_cast<::H008ca010 *>(&(fourth))->ForwardToInner((int)&((((::ActorTask *)(reinterpret_cast<::FUN_008c9a50_shell *>(&(j))->FUN_008c9a50((int)(((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::ActorListView *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ActorManagerView *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({}))))))), j)));
                }
                {
                    ActorTask k;
                    reinterpret_cast<::H008ca010 *>(&(second))->ForwardToInner((int)&((((::ActorTask *)(reinterpret_cast<::FUN_008c9a50_shell *>(&(k))->FUN_008c9a50((int)(((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::ActorListView *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ActorManagerView *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({}))))))), k)));
                }
            }
            {
                ActorTask l;
                reinterpret_cast<::H008ca010 *>(&(fifth))->ForwardToInner((int)&((((::ActorTask *)(reinterpret_cast<::FUN_008c9a50_shell *>(&(l))->FUN_008c9a50((int)(((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::ActorListView *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ActorManagerView *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({}))))))), l)));
            }
            if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfb88)).Bool())
            {
                ActorTask m;
                reinterpret_cast<::H008ca010 *>(&(sixth))->ForwardToInner((int)&((((::ActorTask *)(reinterpret_cast<::FUN_008c9a50_shell *>(&(m))->FUN_008c9a50((int)(((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::ActorListView *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ActorManagerView *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({}))))))), m)));
            }
            ++count;
        } while (count < reinterpret_cast<::FUN_005be5c0_shell *>((((::ActorListView *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::ActorManagerView *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005be5c0({}));
        if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfc70)).Bool())
            reinterpret_cast<::Owner *>(&(first))->CallMidVirtualB();
        reinterpret_cast<::Owner *>(&(third))->CallMidVirtualB();
        if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSettingView *>(&::g_011c3ea4)))))) == 1)
        {
            reinterpret_cast<::Owner *>(&(second))->CallMidVirtualB();
            reinterpret_cast<::Owner *>(&(fourth))->CallMidVirtualB();
        }
        reinterpret_cast<::Owner *>(&(fifth))->CallMidVirtualB();
        if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfb88)).Bool())
            reinterpret_cast<::Owner *>(&(sixth))->CallMidVirtualB();
        if (*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfb68)).Bool())
        {
            if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSettingView *>(&::g_011c3ea4)))))) == 1)
                reinterpret_cast<::Obj_008c9a80 *>(&((*reinterpret_cast<::QueueManagerView *>(&::g_011dfb98))))->PushItem((int)(&fourth));
            reinterpret_cast<::Obj_008c9a80 *>(&((*reinterpret_cast<::QueueManagerView *>(&::g_011dfb98))))->PushItem((int)(&third));
            reinterpret_cast<::Obj_008c9a80 *>(&((*reinterpret_cast<::QueueManagerView *>(&::g_011dfb98))))->PushItem((int)(&fifth));
            if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfc70)).Bool())
                reinterpret_cast<::Obj_008c9a80 *>(&((*reinterpret_cast<::QueueManagerView *>(&::g_011dfb98))))->PushItem((int)(&first));
            if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfb88)).Bool())
            {
                reinterpret_cast<::Obj_008c9a80 *>(&((*reinterpret_cast<::QueueManagerView *>(&::g_011dfb98))))->PushItem((int)(&sixth));
                reinterpret_cast<::Obj_008c9a80 *>(&((*reinterpret_cast<::QueueManagerView *>(&::g_011dfb98))))->PushItem((int)(&second));
            }
            reinterpret_cast<::FUN_008c9f70_this *>(&((*reinterpret_cast<::ThreadManagerView *>(&::g_011dfc24))))->CallAllElements();
            reinterpret_cast<::FUN_008c9fd0_this *>(&((*reinterpret_cast<::ThreadManagerView *>(&::g_011dfc24))))->FUN_008c9fd0();
        }
        else
        {
            if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfc70)).Bool())
                reinterpret_cast<::fnv_008c8240::MessageQueueHandler *>(&(first))->FUN_008c8240(0);
            reinterpret_cast<::fnv_008c8240::MessageQueueHandler *>(&(third))->FUN_008c8240(0);
            reinterpret_cast<::fnv_008c8240::MessageQueueHandler *>(&(fifth))->FUN_008c8240(0);
            if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSettingView *>(&::g_011c3ea4)))))) == 1)
            {
                reinterpret_cast<::fnv_008c8240::MessageQueueHandler *>(&(second))->FUN_008c8240(0);
                reinterpret_cast<::fnv_008c8240::MessageQueueHandler *>(&(fourth))->FUN_008c8240(0);
            }
            if (!*(*reinterpret_cast<::BoolSettingView *>(&::g_011dfb88)).Bool())
                reinterpret_cast<::fnv_008c8240::MessageQueueHandler *>(&(sixth))->FUN_008c8240(0);
        }
    }
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSettingView *>(&::g_011c3ea4)))))) == 1)
    {
        ::TaskQueueInterface::ThreadProcessInput(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSettingView *>(&::g_011d10d4)))))));
        ::TaskQueueInterface::ThreadProcessSecondaryInput();
    }
}

namespace fnv_008c84c0 {
// ---- shell declarations ----
class R;

class V20SP
{
  public:
    virtual void a00();
    virtual void a04();
    virtual void a08();
    virtual void a0c();
    virtual void a10();
    virtual void a14();
    virtual void a18();
    virtual void a1c();
    virtual unsigned char a20();
};

class ABSP
{
  public:
};

class PROJ
{
  public:
    char pad0[0x30];
    V20SP m30;
    char pad1[0x90 - 0x34];
    ABSP m90;
};

class BP
{
  public:
    virtual void b00();
    virtual void b04();
    virtual void b08();
    virtual void b0c();
    virtual void b10();
    virtual void b14();
    virtual void b18();
    virtual void b1c();
    virtual void b20();
    virtual void b24();
    virtual void b28();
    virtual void b2c();
    virtual void b30();
    virtual void b34();
    virtual void b38();
    virtual void b3c();
    virtual void b40();
    virtual void b44();
    virtual void b48();
    virtual void b4c();
    virtual void b50();
    virtual void b54();
    virtual void b58();
    virtual void b5c();
    virtual void b60();
    virtual void b64();
    virtual void b68();
    virtual void b6c();
    virtual unsigned char b70(R* who);
};

class R
{
  public:
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
    virtual unsigned char s100();
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
    virtual unsigned char s22c(int);
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
    virtual void s2b0(float);
    virtual float s2b4();
    virtual void s2b8();
    char padBC[0xb8];
    unsigned char mBC;
    int FUN_008a0d10(int a, R* b, unsigned char* c, unsigned char d, int e, int f, unsigned char* g);
};

class TG
{
  public:
};

class FS
{
  public:
};

class S3
{
  public:
};

class S4
{
  public:
};


class SL
{
  public:
};


class Owner
{
  public:
    char pad30[0x30];
    unsigned int m30;
    char pad34[8];
    int m3c;

    void UpdateProjectile(R* arg);
};

// @fnv 0x008c84c0
void Owner::UpdateProjectile(R* arg)
{
    float v6 = (double)m30 * reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::fnv_008c84c0::TG *>(&::g_timeGlobal))))->GetStoredFloatValue();
    v6 = ::FUN_0040ebd0(v6, 5.0f);
    v6 = ::RandomFloat(0.0f, v6);
    R* p = NULL;
    if (arg && arg->s100())
    {
        p = arg;
        R* aQ = p;
        if (aQ->mBC && !((::fnv_008c84c0::PROJ *)(reinterpret_cast<::Actor *>((aQ))->GetActorBase()))->m30.a20())
        {
            float v3 = reinterpret_cast<::RefS *>((aQ))->FUN_005723b0((::RefS *)((*reinterpret_cast<::fnv_008c84c0::R * *>(&::_g_thePlayer))), 0, 0);
            if (aQ != (*reinterpret_cast<::fnv_008c84c0::R * *>(&::_g_thePlayer)) && !((unsigned char)(reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::fnv_008c84c0::SL * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())))
            {
                if (p->s2b4() < 0.0 && !((unsigned char)(reinterpret_cast<::FUN_00437bd0_stub *>((aQ))->FUN_00437bd0())) && !p->s22c(0))
                {
                    if (reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::fnv_008c84c0::S3 * *>(&::DAT_011d8804))))->GetFadeValue((::FADER_ENUM)(1)) <= 0.0)
                    {
                        p->s2b0(v6);
                        if (((::fnv_008c84c0::BP *)(reinterpret_cast<::BSShaderNoLightingProperty *>((aQ))->GetBaseTexture()))->b70(aQ))
                        {
                            unsigned char v16 = 0;
                            unsigned char v1e2 = reinterpret_cast<::FUN_00493bb0_Class *>((p))->FUN_00493bb0();
                            unsigned char v1d = 0;
                            int aV14 = (*reinterpret_cast<::fnv_008c84c0::R * *>(&::_g_thePlayer))->FUN_008a0d10(1, p, &v16, v1e2, 0, 0, &v1d);
                            unsigned char v15 = 0;
                            int v1c2 = 0;
                            if (((unsigned char)(reinterpret_cast<::HostActor *>((p))->IsHostileTo((::HostActor *)((*reinterpret_cast<::fnv_008c84c0::R * *>(&::_g_thePlayer))), 0, &v1c2, 0))) || ((unsigned char)(reinterpret_cast<::FUN_008bc700_shell *>((p))->FUN_008bc700((::Actor *)((*reinterpret_cast<::fnv_008c84c0::R * *>(&::_g_thePlayer)))))))
                            {
                                v15 = 1;
                            }
                            else if (v1c2 == 0 || v1c2 == 1)
                            {
                                if (((unsigned char)(reinterpret_cast<::ActiveEffect *>(&(((::fnv_008c84c0::PROJ *)(reinterpret_cast<::Actor *>((p))->GetActorBase()))->m90))->IsDone())) &&
                                    reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(((::fnv_008c84c0::PROJ *)(reinterpret_cast<::Actor *>((p))->GetActorBase()))->m90))->FUN_00825c00() > 0)
                                    v15 = 1;
                            }
                            if (p)
                            {
                                if (v3 < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_008c84c0::FS *>(&::originalRuntimeFloatSetting248)))))))
                                    reinterpret_cast<::fnv_0096e3c0::FUN_0096e3c0_shell *>(&((*reinterpret_cast<::fnv_008c84c0::S4 *>(&::g_011e0e80))))->FUN_0096e3c0((::Actor *)(aQ));
                            }
                            if ((double)aV14 >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_008c84c0::FS *>(&::originalRuntimeFloatSetting1073)))))))
                            {
                                reinterpret_cast<::TeammateOwner *>(((*reinterpret_cast<::fnv_008c84c0::R * *>(&::_g_thePlayer))))->FUN_00966f20((::Actor *)(p), v15, 0);
                            }
                            else if (v1d || v16)
                            {
                                reinterpret_cast<::TeammateOwner *>(((*reinterpret_cast<::fnv_008c84c0::R * *>(&::_g_thePlayer))))->FUN_00966f20((::Actor *)(p), v15, 1);
                            }
                            else
                            {
                                reinterpret_cast<::FUN_00967350_shell *>(((*reinterpret_cast<::fnv_008c84c0::R * *>(&::_g_thePlayer))))->FUN_00967350((int)(p));
                            }
                        }
                    }
                }
                else
                {
                    if (p->s2b4() < 0.0)
                        reinterpret_cast<::FUN_00967350_shell *>(((*reinterpret_cast<::fnv_008c84c0::R * *>(&::_g_thePlayer))))->FUN_00967350((int)(p));
                    p->s2b8();
                }
            }
        }
        m3c++;
    }
}
}  // namespace fnv_008c84c0

namespace fnv_008c8be0 {
class BaseProcess
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void UpdateActor(Actor* actor, int mode);
};
struct ExtraFollower
{
    void* unk00;
    void* unk04;
    void* unk08;
    BSSimpleList<Actor*>* followers;
};
struct FollowerExtra : ExtraDataList
{
};
// This view supplies the float-taking update slot at vtable index 0x97.
class UpdateObject : public TESObjectREFR
{
  public:
    virtual void Unk90();
    virtual void Unk91();
    virtual void Unk92();
    virtual void Unk93();
    virtual void Unk94();
    virtual void Unk95();
    virtual void Unk96();
    virtual void Update(float elapsed);
    void* FUN_00931850();
};
class UpdateActor : public Actor
{
  public:
};
class PlayerCharacter : public UpdateActor
{
  public:
};
class UpdateManager
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    int pending;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    unsigned int updatedObjects;
    unsigned int updatedActors;
    void UpdateMobileObject(MobileObject* object);
};
// @fnv 0x008c8be0
void UpdateManager::UpdateMobileObject(MobileObject* object)
{
    UpdateObject* current = reinterpret_cast<UpdateObject*>(object);
    UpdateActor* actorTmp;
    bool allowedTmp;
    ExtraFollower* otherList3;
    BSSimpleList<Actor*>* list_;
    BSSimpleList<Actor*>* listVal;
    BSSimpleList<Actor*>* otherListA;
    BSSimpleList<Actor*>* nodeVal;
    if (current && !reinterpret_cast<::FUN_00576d30_shell *>((void *)(current))->FUN_00576d30() && !reinterpret_cast<::FUN_00440d80_shell *>((void *)(current))->FUN_00440d80() && !current->GetDisabled() &&
        ((::fnv_008c8be0::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((current))->GetBaseTexture())) && !current->FUN_00931850())
    {
        actorTmp = 0;
        allowedTmp = true;
        if (current && current->IsActor())
            actorTmp = reinterpret_cast<UpdateActor*>(current);
        if (actorTmp && !actorTmp->m_bFirstActorFlag)
            return;
        if (actorTmp && reinterpret_cast<::fnv_008b0520::FUN_008b0520_shell *>((actorTmp))->FUN_008b0520())
        {
            ((::fnv_008c8be0::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actorTmp))->GetBaseTexture()))->UpdateActor(actorTmp, 0);
            allowedTmp = false;
            ++updatedActors;
            reinterpret_cast<::FUN_008c8fd0_helper *>((((::fnv_008c8be0::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actorTmp))->GetBaseTexture()))))->Set(true);
        }
        else
        {
            current->Update(0.0f);
            ++updatedObjects;
        }
        if (actorTmp && reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::fnv_008c8be0::PlayerCharacter * *>(&::_g_thePlayer))))->IsSleepingOrResting())
        {
            reinterpret_cast<::FUN_0088b510_cls *>((actorTmp))->SetScaledValue(2.0f);
            reinterpret_cast<::B88B5A0Actor *>((actorTmp))->ApplyFatigueDamage(2.0f);
        }
        if (current->FUN_00931850())
            pending = 0;
        if (allowedTmp)
        {
            otherList3 =
                ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((current))->FUN_005d43c0())) ? ((::fnv_008c8be0::ExtraFollower *)(reinterpret_cast<::FUN_00422700_shell *>((static_cast<FollowerExtra*>(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((current))->FUN_005d43c0())))))->FUN_00422700())) : 0;
            if (otherList3)
            {
                listVal = new BSSimpleList<Actor*>;
                otherListA = new BSSimpleList<Actor*>;
                nodeVal = otherListA;
                list_ = otherList3->followers;
                while (list_ && (((list_))->m_item))
                {
                    reinterpret_cast<::Callees *>((otherListA))->FUN_00905820((void *)&((((list_))->m_item)));
                    list_ = ((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::Callees *>((list_))->FUN_00726070()));
                }
                while (nodeVal && (((nodeVal))->m_item))
                {
                    Actor* actorA = (((nodeVal))->m_item);
                    if (actorA && actorA != (*reinterpret_cast<::fnv_008c8be0::PlayerCharacter * *>(&::_g_thePlayer)) && !reinterpret_cast<::fnv_008bc860::FUN_008bc860_StandIn *>((static_cast<UpdateActor*>(actorA)))->FUN_008bc860(actorTmp))
                        listVal->AddHead(actorA);
                    nodeVal = ((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::Callees *>((nodeVal))->FUN_00726070()));
                }
                nodeVal = listVal;
                while (nodeVal && (((nodeVal))->m_item))
                {
                    Actor* targetB = (((nodeVal))->m_item);
                    reinterpret_cast<::fnv_00422690::FUN_00422690_shell *>((static_cast<FollowerExtra*>(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((current))->FUN_005d43c0())))))->FUN_00422690((::fnv_00422690::Actor *)(targetB));
                    nodeVal = ((::BSSimpleList< ::Actor *> *)(reinterpret_cast<::Callees *>((nodeVal))->FUN_00726070()));
                }
                reinterpret_cast<::FileMatchList *>((listVal))->RemoveAll();
                delete listVal;
                reinterpret_cast<::FileMatchList *>((otherListA))->RemoveAll();
                delete otherListA;
                if (otherList3->followers->IsEmpty())
                    reinterpret_cast<::FUN_00422720_shell *>((static_cast<FollowerExtra*>(((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((current))->FUN_005d43c0())))))->FUN_00422720();
            }
        }
    }
}
}  // namespace fnv_008c8be0

namespace fnv_008ca070 {
struct IntSetting
{
};
struct BoolSetting
{
    unsigned char* FUN_00408d60();
};
struct Values
{
};
struct Container
{
};
struct Temp
{
    int unk00, unk04, unk08;
};
struct Store
{
};
struct Mode
{
};
struct Obj
{
    void FUN_008ca070();
};
// @fnv 0x008ca070
void Obj::FUN_008ca070()
{
    if (*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_008ca070::IntSetting *>(&::g_011c3ea4)))))) == 1)
    {
        if (!*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfc70)).FUN_00408d60() && !*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfb88)).FUN_00408d60())
            return;
        if ((*reinterpret_cast<unsigned char *>(&::DAT_011f1220)))
        {
            unsigned aVal = reinterpret_cast<::FUN_005be5c0_shell *>((((::fnv_008ca070::Values *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::fnv_008ca070::Container *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005be5c0({});
            if (aVal > 0)
            {
                unsigned b_2 = reinterpret_cast<::FUN_005be5c0_shell *>((((::fnv_008ca070::Values *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::fnv_008ca070::Container *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_005be5c0({});
                unsigned i;
                if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfc70)).FUN_00408d60())
                {
                    Temp t2;
                    reinterpret_cast<::FUN_008c9a20_shell *>(&(t2))->FUN_008c9a20(b_2);
                    reinterpret_cast<::H008ca010 *>(this)->ForwardToInner((int)(&t2));
                }
                if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfb88)).FUN_00408d60())
                {
                    Temp u9;
                    reinterpret_cast<::FUN_008c9a20_shell *>(&(u9))->FUN_008c9a20(b_2);
                    reinterpret_cast<::H008ca010 *>((((Obj*)((char*)this + 0x138))))->ForwardToInner((int)(&u9));
                }
                for (i = 0; i < b_2; ++i)
                {
                    if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfc70)).FUN_00408d60())
                    {
                        Temp v5;
                        reinterpret_cast<::FUN_008c9a50_shell *>(&(v5))->FUN_008c9a50((int)(((void *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::fnv_008ca070::Values *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::fnv_008ca070::Container *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({})))));
                        reinterpret_cast<::H008ca010 *>(this)->ForwardToInner((int)(&v5));
                    }
                    if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfb88)).FUN_00408d60())
                    {
                        Temp w2;
                        reinterpret_cast<::FUN_008c9a50_shell *>(&(w2))->FUN_008c9a50((int)(((void *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((((::fnv_008ca070::Values *)(reinterpret_cast<::BaseProcess *>(&((*reinterpret_cast<::fnv_008ca070::Container *>(&::g_011e0e80))))->GetCurrentProcessData()))))->FUN_00968670({})))));
                        reinterpret_cast<::H008ca010 *>((((Obj*)((char*)this + 0x138))))->ForwardToInner((int)(&w2));
                    }
                }
                if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfc70)).FUN_00408d60())
                    reinterpret_cast<::Owner *>(this)->CallMidVirtualB();
                if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfb88)).FUN_00408d60())
                    reinterpret_cast<::Owner *>((((Obj*)((char*)this + 0x138))))->CallMidVirtualB();
                if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfb68)).FUN_00408d60())
                {
                    if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfc70)).FUN_00408d60())
                        reinterpret_cast<::Obj_008c9a80 *>(&((*reinterpret_cast<::fnv_008ca070::Store *>(&::g_011dfb98))))->PushItem((int)(this));
                    if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfb88)).FUN_00408d60())
                        reinterpret_cast<::Obj_008c9a80 *>(&((*reinterpret_cast<::fnv_008ca070::Store *>(&::g_011dfb98))))->PushItem((int)((char*)this + 0x138));
                    reinterpret_cast<::fnv_008ca2e0::FUN_008ca2e0_shell *>(&((*reinterpret_cast<::fnv_008ca070::Mode *>(&::g_011dfc24))))->CallAt(2);
                    *((bool*)this + 0x10180) = true;
                }
                else
                {
                    if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfc70)).FUN_00408d60())
                        reinterpret_cast<::fnv_008c8240::MessageQueueHandler *>(this)->FUN_008c8240(0);
                    if (*(*reinterpret_cast<::fnv_008ca070::BoolSetting *>(&::g_011dfb88)).FUN_00408d60())
                        reinterpret_cast<::fnv_008c8240::MessageQueueHandler *>((((Obj*)((char*)this + 0x138))))->FUN_008c8240(0);
                }
            }
        }
    }
}
}  // namespace fnv_008ca070

namespace fnv_008c9d70 {
struct FUN_008c71b0
{
    int a;
    FUN_008c71b0(int i);
    FUN_008c71b0(const FUN_008c71b0&);
};
struct MemQ;
struct FacQ
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void Create(MemQ* p, const char* pName, FUN_008c71b0 k);
};
struct HeapQ
{
    virtual void v0();
    virtual int Alloc(int n);
};
struct BufQ
{
};
struct MemQ
{
};
struct GQ
{
};
struct OwnQ
{
    char pad[0x50];
    hkMemoryRouter kMem;
    void* unk74;
    void InitMemory();
};
// Sets up the AI task thread's Havok memory router: temp and solver use the heap, and the stack area is a
// 0x16800-byte heap block.
// @fnv 0x008c9d70
void OwnQ::InitMemory()
{
    ((::fnv_008c9d70::FacQ *)(::FUN_00cbbfc0()))->Create((MemQ *)&kMem, "AITaskThread", FUN_008c71b0(1));
    ::FUN_00cbb930(&kMem);
    kMem.m_temp = kMem.m_heap;
    kMem.m_solver = kMem.m_heap;
    unk74 = kMem.m_heap->blockAlloc(0x16800);
    reinterpret_cast<::QuantitySet *>(&kMem)->FUN_008c70c0((uintptr_t)unk74, 0x16800);
    reinterpret_cast<::TESDataHandler *>(((*reinterpret_cast<::fnv_008c9d70::GQ * *>(&::g_dataHandler))))->BuildCompiledFileList();
}

}  // namespace fnv_008c9d70

struct Obj_008c9cf0
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_items[10];
    int m_uiItemCount;
    int m_next;
    void QueryPerformanceCounter(int a);
    int FUN_008c9cf0();
};

// Pops the next task from a circular buffer of 10 items, wrapping the index, then calls WaitForTasksDuringRendering.
// @fnv 0x008c9cf0
int Obj_008c9cf0::FUN_008c9cf0()
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(this)->FUN_004538a0(0);
    int result = 0;
    if (m_uiItemCount > 0)
    {
        result = m_items[m_next];
        m_uiItemCount = m_uiItemCount - 1;
        m_next = m_next + 1;
        if (m_next >= 10)
            m_next = 0;
    }
    reinterpret_cast<ActorTaskManager*>(this)->WaitForTasksDuringRendering();
    return result;
}

#include "generated/data/fallout/ai/aitaskmanager.inc"
