// fallout_shared/pathfinding/pathmanager.cpp: PathManager, PathingTaskData, Pathing, DelStandIn and more (65 functions)

#include <new>
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/B00C20Pool.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_0040f6e0_class.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00633c90.h"
#include "fnv/decl/FUN_006cb410_cls.h"
#include "fnv/decl/FUN_006cf8a0_cls.h"
#include "fnv/decl/FUN_006cf940_cls.h"
#include "fnv/decl/FUN_006deeb0_cls.h"
#include "fnv/decl/FUN_006eb6b0_cls.h"
#include "fnv/decl/FUN_006ebfb0_Class.h"
#include "fnv/decl/FUN_006ec390_Class.h"
#include "fnv/decl/Lock00aa62c0.h"
#include "fnv/decl/PathingLocation.h"
#include "fnv/decl/PlayerQuestData.h"
#include "fnv/decl/Queue44c640.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TSHashTable.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/WaitableObject.h"
#include "fnv/decl/fnv_006cb4a0__FUN_006cb4a0_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00aa6120__Lock00aa6120.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005dc000.h"
#include "fnv/symbols_006c5000.h"
#include "fnv/symbols_00aa6000.h"
#include "fnv/symbols_00b00000.h"
#include "fnv/symbols_0106d000.h"
#include "pathmanager_decls.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include <cstdint>
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00aa62e0_shell.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_006c5ec0__S6c5ec0.h"
#include "fnv/decl/fnv_0087ac00__Owner0087ac00.h"
#include "fnv/decl/fnv_0087ac60__FUN_0087AC60_Holder.h"
#include "fnv/decl/fnv_0087ad50__Host.h"
#include "fnv/decl/fnv_00aa6220__Lock00aa6220.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_011d6000.h"

// Copies the two fields of source into this object and returns a reference to this object.
// @fnv 0x006e9c60
QueuedMessage& QueuedMessage::operator=(const QueuedMessage& source)
{
    m_eMessageType = source.m_eMessageType;
    m_pPathingSolution = source.m_pPathingSolution;
    return *this;
}

// Locks the object at offset 0x20, checks that every entry in the array at offset 0x50 has state != 0, unlocks, and returns whether all are ready.
// @fnv 0x006ea490
bool PathingTaskData::HasPendingMessages()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)((char*)this + 0x20))))->FUN_0040fbf0((char *)(0));
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((BSSimpleArray<ParentSpaceNode, 1024>*)((char*)this + 0x50))))->GetName())); ++i)
    {
        if (((NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*)((char*)this + 0x50))->GetAt(i)->state == 0)
        {
            ((RecursiveSpinLock*)((char*)this + 0x20))->FUN_0040fba0();
            return false;
        }
    }
    ((RecursiveSpinLock*)((char*)this + 0x20))->FUN_0040fba0();
    return true;
}

// @fnv 0x006eb820
PathManager::PathManager()
{
    m_kPerformanceTimerManager.Register(DAT_0103a1bc, DAT_0106d624, false, true);
    m_pPathManagerImpl = 0;
}

// @fnv 0x006eb9d0
bool PathManager::BuildPath(NiPointer<PathingRequest> m_pPathingRequest, NiPointer<ActorPathingMessageQueue> spQueue,
                            bool bAsync)
{
    if (g_011d77cc.Bool()->b && bAsync)
    {
        return m_pPathManagerImpl->BuildPath(m_pPathingRequest, spQueue);
    }
    else
    {
        NiPointer<PathingSolution> m_pPathingSolution = new PathingSolution();
        if (Pathing::BuildPath(m_pPathingRequest, m_pPathingSolution))
        {
            ((ActorPathingMessageQueue*)spQueue)->Push(QueuedMessage(PATHING_MESSAGE_TYPE_PMT_OK, m_pPathingSolution));
        }
        else
        {
            ((ActorPathingMessageQueue*)spQueue)
                ->Push(QueuedMessage(PATHING_MESSAGE_TYPE_PMT_ERROR, m_pPathingSolution));
        }

        return true;
    }
}

struct G00559a40
{
};
struct S00559a40
{
    G00559a40* p;
    S00559a40* FUN_00559a40(S00559a40* o);
};
// Copies the pointer from o into this object's p and, if non-null, calls FUN_0040f6e0 on it, then returns this.
// @fnv 0x00559a40
S00559a40* S00559a40::FUN_00559a40(S00559a40* apOther)
{
    p = apOther->p;
    if (p)
        reinterpret_cast<::FUN_0040f6e0_class *>((p))->FUN_0040f6e0();
    return this;
}

struct G006e9bd0
{
    int v;
};
struct S006e9bd0
{
    int a;
    G006e9bd0 g;
    S006e9bd0* FUN_006e9bd0();
};
// Sets a to -1, constructs g with 0, and returns this.
// @fnv 0x006e9bd0
S006e9bd0* S006e9bd0::FUN_006e9bd0()
{
    a = -1;
    new ((void *)&(g)) ::FUN_00633c90((::G00559a40 *)(0));
    return this;
}

struct N006e9c00
{
    int v;
};
struct S006e9c00
{
    int type;
    N006e9c00 sp;
    S006e9c00* FUN_006e9c00(int t, N006e9c00* s);
};
// @fnv 0x006e9c00
S006e9c00* S006e9c00::FUN_006e9c00(int aiType, N006e9c00* apSource)
{
    type = aiType;
    reinterpret_cast<::S00559a40 *>(&(sp))->FUN_00559a40((::S00559a40 *)&(*apSource));
    return this;
}

struct Elem1_006e9e20
{
    ~Elem1_006e9e20();
};

struct Elem2_006e9e20
{
    ~Elem2_006e9e20();
};

struct Base_006e9e20
{
    int pad[5];
    virtual ~Base_006e9e20();
};

struct Ptr1_006e9e20
{
    int p;
    ~Ptr1_006e9e20();
};

struct Arr1_006e9e20
{
    int pad[4];
    ~Arr1_006e9e20();
    Elem1_006e9e20*& GetAt(unsigned int);
};

struct Arr2_006e9e20
{
    int pad[4];
    ~Arr2_006e9e20();
    Elem2_006e9e20*& GetAt(unsigned int);
};

struct Ptr2_006e9e20
{
    int p;
    ~Ptr2_006e9e20();
};

struct FUN_006e9e20 : public Base_006e9e20
{
    Ptr1_006e9e20 m18;
    Ptr1_006e9e20 m1c;
    char pad20[0x20];
    Arr1_006e9e20 m40;
    Arr2_006e9e20 m50;
    Ptr2_006e9e20 m60;

    virtual ~FUN_006e9e20();
};

// Destructor that iterates over the size of m40 and deletes each element from both m40 and m50.
// @fnv 0x006e9e20
FUN_006e9e20::~FUN_006e9e20()
{
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m40))->GetName())); ++i)
    {
        delete m40.GetAt(i);
        delete m50.GetAt(i);
    }
}

struct FormChangeMask
{
    int v;
    FormChangeMask();
    ~FormChangeMask();
};
struct PM1
{
    char pad[0xc0c];
    PM1();
    ~PM1();
};
struct PM2
{
    char pad[0x14];
    PM2(PM1*);
    ~PM2();
};
struct PMX
{
    char pad[8];
    char c;
    char pad2[3];
    PMX();
};
struct GlobalObject_0044fae0
{
    char pad[0x18];
    GlobalObject_0044fae0();
    ~GlobalObject_0044fae0();
public:
    void FUN_004538a0(std::intptr_t);
};
struct PM4
{
    char pad[0x414];
    PM4();
    ~PM4();
};
struct PM5
{
    char pad[0x41c];
    PM5();
    ~PM5();
};
struct PMA
{
    char pad[0x1c];
    PMA(int, int, int);
};
struct FUN_006eaa30 : public FormChangeMask
{
    PM1 m1;
    PM2 m2;
    int i1;
    int i2;
    PMX x;
    GlobalObject_0044fae0 g;
    PM4 m4;
    PM5 m5;
    PMA a;
    FUN_006eaa30();
};
// Initializes the object's members: sets i1 and i2 to 0, x.c to 0, and constructs m2 from m1 and a with (0xc, 0x25, 0xc).
// @fnv 0x006eaa30
FUN_006eaa30::FUN_006eaa30() : m2(&m1), a(0xc, 0x25, 0xc)
{
    i1 = 0;
    i2 = 0;
    x.c = 0;
}

struct FUN_006eabe0_shell : public PathManagerImpl
{
    bool FUN_006eabe0();
};
// Creates a new PathManagerImpl and returns the result of its Initialize call.
// @fnv 0x006eb8c0
bool PathManager::Initialize()
{
    AutoMemContext context(static_cast<MEM_CONTEXT>(0x2d), true, DAT_0106d560, 1386);
    m_pPathManagerImpl = new PathManagerImpl;
    return reinterpret_cast<::FUN_006eabe0_shell *>((m_pPathManagerImpl))->FUN_006eabe0();
}

struct BSWin32TaskletManager
{
    bool GetTaskletValue(void*);
};
bool FUN_006c08e0(void*);

// @fnv 0x006eabe0
bool FUN_006eabe0_shell::FUN_006eabe0()
{
    if (!::GetTaskletManager().GetTaskletValue(this))
        return false;
    if (!FUN_006c08e0(this))
        return false;
    *(int*)((char*)this + 0xc24) = 0;
    *(int*)((char*)this + 0xc28) = 0;
    this->unkc34 = false;
    return true;
}

struct FUN_006eb790_shell : public PathManagerImpl
{
    bool FUN_006eb790();
};


// @fnv 0x006eb790
bool FUN_006eb790_shell::FUN_006eb790()
{
    return reinterpret_cast<::fnv_00aa6120::Lock00aa6120 *>(((char*)this + 0xc2c))->FUN_00aa6120();
}

struct FUN_006eb7b0_shell : public PathManagerImpl
{
    void FUN_006eb7b0();
};


// @fnv 0x006eb7b0
void FUN_006eb7b0_shell::FUN_006eb7b0()
{
    reinterpret_cast<::Lock00aa62c0 *>(((char*)this + 0xc2c))->FUN_00aa62c0();
}

struct PathingTaskMessage
{
    void* __vecDelDtor(unsigned int);
    int m_eMessageType;
    PathingTaskData* m_pPathingTaskData;
};
struct FUN_006eb7f0_shell : public PathManagerImpl
{
    void DispatchPathingMessage(void*);
};

struct _Vtbl_006eb7f0
{
    virtual void v0();
    virtual void v1(void*);
};

// Forwards aMsg to the virtual function at offset 0xc10 of this object.
// @fnv 0x006eb7f0
void FUN_006eb7f0_shell::DispatchPathingMessage(void* aMsg)
{
    reinterpret_cast<_Vtbl_006eb7f0*>(reinterpret_cast<char*>(this) + 0xc10)->v1(aMsg);
}

struct FUN_006ebc70_shell : public PathManager
{
    void FUN_006ebc70();
};


struct FUN_006ebc90_shell : public PathManager
{
    bool FUN_006ebc90();
};


struct FUN_006ebcd0_shell : public PathManager
{
    void FUN_006ebcd0();
};


struct T006ebd10
{
};
struct S006ebd10
{
    T006ebd10* p;
    void FUN_006ebd10(std::intptr_t a);
};
// @fnv 0x006ebd10
void S006ebd10::FUN_006ebd10(std::intptr_t a)
{
    reinterpret_cast<::FUN_006eb6b0_cls *>((p))->FUN_006eb6b0(a);
}

struct G006ebf30
{
    char pad[0x14];
    char r;
};
struct S006ebf30
{
    G006ebf30* p;
    S006ebf30* FUN_006ebf30(S006ebf30* o);
};
// Copies the pointer from o into this object and, if it is non-null, calls FUN_0040f6e0 on the sub-object at offset 0x14; returns this.
// @fnv 0x006ebf30
S006ebf30* S006ebf30::FUN_006ebf30(S006ebf30* apSource)
{
    p = apSource->p;
    if (p)
        reinterpret_cast<::FUN_0040f6e0_class *>((((G006ebf30*)((char*)p + 0x14))))->FUN_0040f6e0();
    return this;
}

class NiAVObject
{
  public:
};

// If the stored pointer is non-null, calls FUN_00401970 on the NiAVObject at offset 0x14 of it.
// @fnv 0x006ebf90
void FUN_006ebf90(char** apObjectPtr)
{
    if (*apObjectPtr)
        reinterpret_cast<::WaitableObject *>((((NiAVObject*)(*apObjectPtr + 0x14))))->FUN_00401970();
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* DestroyAndFree(unsigned int flags);
};
// Runs the destructor on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x006e9c90
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    reinterpret_cast<::FUN_006e9e20 *>((((DtorStandIn*)this)))->::FUN_006e9e20::~FUN_006e9e20();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct FUN_006e9f60_shell
{
    void* FUN_006e9f60(unsigned int flags);
};

// Calls FUN_006cb410, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x006e9f60
void* FUN_006e9f60_shell::FUN_006e9f60(unsigned int flags)
{
    reinterpret_cast<::FUN_006cb410_cls *>(this)->::FUN_006cb410_cls::~FUN_006cb410_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006ea330_shell
{
    void FUN_006ea330();
};

// @fnv 0x006ea330
void FUN_006ea330_shell::FUN_006ea330()
{
    *(unsigned char*)(((unsigned char*)this) + 4) = 1;
}

struct FUN_006eb390_shell
{
    bool FUN_006eb390();
};
// @fnv 0x006ebc90
bool FUN_006ebc90_shell::FUN_006ebc90()
{
    return reinterpret_cast<::FUN_006eb390_shell *>((*reinterpret_cast<void**>(this)))->FUN_006eb390();
}

// @fnv 0x006eb390
bool FUN_006eb390_shell::FUN_006eb390()
{
    return ((int*)this)[0xc24 / 4] == 2;
}

struct FUN_006eb420_shell
{
    bool IsFieldZero();
};

// @fnv 0x006eb420
bool FUN_006eb420_shell::IsFieldZero()
{
    return *(int*)((char*)this + 0xc24) == 0;
}

struct FUN_006eb7d0_shell
{
    char GetByteAtOffsetC34();
};
// @fnv 0x006e9fc0
void PathingTaskData::Process()
{
    AutoMemContext context(static_cast<MEM_CONTEXT>(0x2d), true, DAT_0106d560, 355);
    reinterpret_cast<::TESForm *>((((::DummyTimer *)(reinterpret_cast<::BaseProcess *>((::GetPathManager()))->GetCurrentProcessData()))))->ClearData();

    if (reinterpret_cast<::FUN_006eb790_shell *>((((::PathManagerImpl *)(::FUN_00559450((int *)(::GetPathManager()))))))->FUN_006eb790())
    {
        if (!HasPendingMessages())
        {
            reinterpret_cast<::FUN_006ea330_shell *>(this)->FUN_006ea330();
        }
        else
        {
            m_pPathingSolution = new PathingSolution();
            bool bSuccess = Pathing::BuildPath(m_pPathingRequest, m_pPathingSolution);
            if (((bool)(::FUN_005dc980((const char *)this))))
            {
                int unk18 = 0;
            }
            else
            {
                if (bSuccess)
                {
                    if (bFlag04)
                    {
                        bFlag04 = false;
                    }
                    ((ActorPathingMessageQueue*)spQueue)
                        ->Push(QueuedMessage(PATHING_MESSAGE_TYPE_PMT_OK, m_pPathingSolution));
                    reinterpret_cast<::FUN_006eb7f0_shell *>((((::PathManagerImpl *)(::FUN_00559450((int *)(::GetPathManager()))))))->DispatchPathingMessage((void *)&(const ::Struct_004b0680 &)(Struct_004b0680(0, this)));
                }
                else
                {
                    ((ActorPathingMessageQueue*)spQueue)
                        ->Push(QueuedMessage(PATHING_MESSAGE_TYPE_PMT_ERROR, m_pPathingSolution));
                    reinterpret_cast<::FUN_006eb7f0_shell *>((((::PathManagerImpl *)(::FUN_00559450((int *)(::GetPathManager()))))))->DispatchPathingMessage((void *)&(const ::Struct_004b0680 &)(Struct_004b0680(1, this)));
                }
            }
        }
        reinterpret_cast<::FUN_006eb7b0_shell *>((((::PathManagerImpl *)(::FUN_00559450((int *)(::GetPathManager()))))))->FUN_006eb7b0();
    }
    else
    {
        if (((bool)(reinterpret_cast<::FUN_006eb7d0_shell *>((((::PathManagerImpl *)(::FUN_00559450((int *)(::GetPathManager()))))))->GetByteAtOffsetC34())))
        {
            ((ActorPathingMessageQueue*)spQueue)
                ->Push(QueuedMessage(PATHING_MESSAGE_TYPE_PMT_ERROR, m_pPathingSolution));
            reinterpret_cast<::FUN_006eb7f0_shell *>((((::PathManagerImpl *)(::FUN_00559450((int *)(::GetPathManager()))))))->DispatchPathingMessage((void *)&(const ::Struct_004b0680 &)(Struct_004b0680(1, this)));
        }
        else
        {
            reinterpret_cast<::FUN_006ea330_shell *>(this)->FUN_006ea330();
        }
    }

    reinterpret_cast<::TESForm *>((((::DummyTimer *)(reinterpret_cast<::BaseProcess *>((::GetPathManager()))->GetCurrentProcessData()))))->ClearData();
}

// @fnv 0x006eb7d0
char FUN_006eb7d0_shell::GetByteAtOffsetC34()
{
    return reinterpret_cast<char*>(this)[0xc34];
}

struct FUN_006eb420_t
{
};

struct FUN_006ebcb0_shell
{
    FUN_006eb420_t* m0;
    void CallMemberFunction();
};

// @fnv 0x006ebcb0
void FUN_006ebcb0_shell::CallMemberFunction()
{
    reinterpret_cast<::FUN_006eb420_shell *>((m0))->IsFieldZero();
}


struct FUN_006ebdc0_shell
{
    void SetVtable();
};

// @fnv 0x006ebdc0
void FUN_006ebdc0_shell::SetVtable()
{
    *(void**)this = (void*)&DAT_0106d644;
}

struct FUN_006ebde0_shell
{
    unsigned char c0c;
    bool FUN_006ebde0();
};

// @fnv 0x006ebde0
bool FUN_006ebde0_shell::FUN_006ebde0()
{
    return ((unsigned char*)this)[0xc] & 2;
}

struct GlobalObject_00869f00
{
};

extern void* DAT_0106d650;

struct FUN_006ebec0_shell
{
    void* m_data;
    void FUN_006ebec0();
};

// @fnv 0x006ebec0
void FUN_006ebec0_shell::FUN_006ebec0()
{
    m_data = &DAT_0106d650;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(this)))->Clear(true);
}

struct AX
{
    void* vtable;
    void FUN_006b3eb0(unsigned int, unsigned int);
};


struct FUN_006ebee0_shell : AX
{
    AX* FUN_006ebee0();
};

// Sets the vtable to DAT_0106d664, calls FUN_006b3eb0 with 0, 0, and returns this.
// @fnv 0x006ebee0
AX* FUN_006ebee0_shell::FUN_006ebee0()
{
    vtable = &DAT_0106d664;
    FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_006ebf10 {
struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_006ebf10();
};


void GlobalObject_00869f00::Clear(bool)
{}

// @fnv 0x006ebf10
void GlobalObject_00869f00::FUN_006ebf10()
{
    *(void**)this = (void*)&::DAT_0106d664;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}
}  // namespace fnv_006ebf10

namespace fnv_006ec970 {

struct FUN_006ec970_shell
{
    void* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    char m_iFourthElementInteger;
    FUN_006ec970_shell();
};

// @fnv 0x006ec970
FUN_006ec970_shell::FUN_006ec970_shell()
{
    m_kPointA = &(*reinterpret_cast<void * *>(&::DAT_0106d644));
    m_kPointB = 0;
    m_iThirdValue = 0;
    m_iFourthElementInteger = 0;
}
}  // namespace fnv_006ec970

namespace fnv_006ebe60 {
struct FUN_006ebdc0_shell
{
};


struct FUN_006ebe60_shell
{
    void* FUN_006ebe60(unsigned int flags);
};

// Calls SetVtable on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006ebe60
void* FUN_006ebe60_shell::FUN_006ebe60(unsigned int flags)
{
    reinterpret_cast<::FUN_006ebdc0_shell *>((((FUN_006ebdc0_shell*)this)))->SetVtable();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_006ebe60

extern "C" void __cdecl FUN_006b3eb0(unsigned int, unsigned int);
extern void* DAT_0106d650;

struct FUN_006ebe90_shell
{
    void* vtable;
    void FUN_006b3eb0(unsigned int, unsigned int);
    FUN_006ebe90_shell* FUN_006ebe90();
};

// Sets the vtable to DAT_0106d650, calls FUN_006b3eb0 with 0 and false, and returns this.
// @fnv 0x006ebe90
FUN_006ebe90_shell* FUN_006ebe90_shell::FUN_006ebe90()
{
    vtable = &DAT_0106d650;
    FUN_006b3eb0(0, false);
    return this;
}

struct SpObst
{
    SpObst(unsigned int*);
};
struct FUN_006e9c30
{
    unsigned int m0;
    SpObst m1;
    FUN_006e9c30(const FUN_006e9c30&);
};
// Copy constructor: copies m0 from a and constructs m1 from the address of a.m1.
// @fnv 0x006e9c30
FUN_006e9c30::FUN_006e9c30(const FUN_006e9c30& aOther) : m0(aOther.m0), m1((unsigned int*)&aOther.m1)
{}

struct Holder006e9f90
{
    void* ReleaseIfFlagged(unsigned int);
};
// Calls ClearLOSArray, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006e9f90
void* Holder006e9f90::ReleaseIfFlagged(unsigned int flags)
{
    reinterpret_cast<::fnv_006cb4a0::FUN_006cb4a0_shell *>(this)->ClearLOSArray();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_006ea9d0_shell
{
    int f0;
    int f4;
    FUN_006ea9d0_shell* FUN_006ea9d0();
};
// Sets f0 to -1 and f4 to 0, then returns this.
// @fnv 0x006ea9d0
FUN_006ea9d0_shell* FUN_006ea9d0_shell::FUN_006ea9d0()
{
    f0 = -1;
    f4 = 0;
    return this;
}

struct S_006eaa00
{
    int m0;
    int m4;
    S_006eaa00* FUN_006eaa00(S_006eaa00* p);
};
// Copies m0 and m4 from p into this object and returns this.
// @fnv 0x006eaa00
S_006eaa00* S_006eaa00::FUN_006eaa00(S_006eaa00* apSource)
{
    m0 = apSource->m0;
    m4 = apSource->m4;
    return this;
}

namespace fnv_006eac40 {
void FUN_006c09d0(void*);
struct BSWin32TaskletManager
{
};
struct FUN_006eac40_Holder
{
    void FUN_006eac40();
};
// Calls FUN_006c09d0 on this, then passes this to the tasklet manager's ReleaseItem.
// @fnv 0x006eac40
void FUN_006eac40_Holder::FUN_006eac40()
{
    FUN_006c09d0(this);
    reinterpret_cast<::B00C20Pool *>(&((*(::fnv_006eac40::BSWin32TaskletManager *)&(::GetTaskletManager()))))->ReleaseItem((*(::B00C20Item * *)(this)));
}
}  // namespace fnv_006eac40

struct InnerA
{
    virtual void f0();
    virtual void f1(int);
};
struct HostA
{
    char _p0[0xC50];
    InnerA _a;
    char _p1[0x410];
    InnerA _b;
    bool DispatchToInner(int a, bool b);
};
// Calls f1(a) on _a when b is true, otherwise on _b, and returns true.
// @fnv 0x006eb200
bool HostA::DispatchToInner(int aiValue, bool abUseFirst)
{
    if (abUseFirst)
        _a.f1(aiValue);
    else
        _b.f1(aiValue);
    return true;
}

struct PatrolActorPackageData
{
    virtual void vf0();
    virtual void vf1(bool);
    bool IsPatrolling();
};
struct FUN_006eb670_Holder
{
    PatrolActorPackageData* field0;
    void FUN_006eb670(bool);
};
// @fnv 0x006eb670
void FUN_006eb670_Holder::FUN_006eb670(bool a1)
{
    if (field0 != 0)
    {
        if (!field0->IsPatrolling())
        {
            field0->vf1(a1);
        }
    }
}

struct Obj_6eb890
{
};
struct Holder_6eb850
{
    Obj_6eb890* ptr;
    void FUN_006eb850();
};
struct Tmp_006eb890
{
    void* FUN_006eb890(unsigned int);
};
// If ptr is non-null, calls FUN_006eb890(1) on it.
// @fnv 0x006eb850
void Holder_6eb850::FUN_006eb850()
{
    Obj_6eb890* b;
    {
        Obj_6eb890* a;
        a = ptr;
        b = a;
        if (b)
            reinterpret_cast<::Tmp_006eb890 *>((b))->FUN_006eb890(1);
    }
}
extern int DAT_0106d63c;

struct FUN_006ebda0_shell
{
    void FUN_006ebda0();
};

// @fnv 0x006ebda0
void FUN_006ebda0_shell::FUN_006ebda0()
{
    *reinterpret_cast<void**>(this) = &DAT_0106d63c;
}

struct S006ebe00
{
    void FUN_006ebd30();
    void* FUN_006ebe00(unsigned int);
};
struct Class_006ebe30
{
    void* FUN_006ebe30(unsigned int);
};
// @fnv 0x006ebe30
void* Class_006ebe30::FUN_006ebe30(unsigned int flags)
{
    reinterpret_cast<::FUN_006ebda0_shell *>(this)->FUN_006ebda0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_006ebf60 {
struct G00559a40
{
};
struct S006ebf60
{
    char* f;
    S006ebf60* FUN_006ebf60(char*);
};
// Stores a into f and, when a is non-zero, calls FUN_0040f6e0 on the object at a+0x14; returns this.
// @fnv 0x006ebf60
S006ebf60* S006ebf60::FUN_006ebf60(char* apValue)
{
    f = apValue;
    if (f != 0)
        reinterpret_cast<::FUN_0040f6e0_class *>((((G00559a40*)(f + 0x14))))->FUN_0040f6e0();
    return this;
}
}  // namespace fnv_006ebf60

namespace fnv_006eac70 {
struct FUN_006ebf30
{
    FUN_006ebf30(const FUN_006ebf30&);
    ~FUN_006ebf30();
    void* m_pObject;
};
struct GO
{
    ~GO();
    void* m_pObject;
};
struct Ptr2_006e9e20 : FUN_006ebf30
{
    ~Ptr2_006e9e20();
};
struct BSTaskletData
{
    virtual ~BSTaskletData();
};
struct FUN_006e9cc0 : BSTaskletData
{
    FUN_006e9cc0(const GO&, FUN_006ebf30);
    char pad[0x7c];
};
struct FUN_006c5e70
{
    ~FUN_006c5e70();
    int a, b;
};
struct TESRaceForm
{
};
struct Queue_006eac70
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void Add(int, BSTaskletData**, int);
    virtual void Remove(int);
};

struct PathManagerImpl_t
{
    char pad[0x1480];
    Queue_006eac70 kQueue;
    bool FUN_006c5ec0(FUN_006c5e70*, int);
    bool QueueTaskletRequest(GO aspRequest, Ptr2_006e9e20 aspMessageQueue);
};

// Creates a tasklet from the request and message queue, adds it to kQueue, and removes and deletes it if FUN_006c5ec0 fails.
// @fnv 0x006eac70
bool PathManagerImpl_t::QueueTaskletRequest(GO aspRequest, Ptr2_006e9e20 aspMessageQueue)
{
    BSTaskletData* ptaskData = new FUN_006e9cc0(aspRequest, aspMessageQueue);
    FUN_006c5e70 task = (*(::fnv_006eac70::FUN_006c5e70 *)(::FUN_006c5e40({})));
    reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)&task)))->Initialize((::CombatController *)(ptaskData));
    kQueue.Add(::FUN_00559450((int*)&aspRequest), &ptaskData, 1);
    if (!FUN_006c5ec0(&task, 0))
    {
        kQueue.Remove(::FUN_00559450((int*)&aspRequest));
        delete ptaskData;
        return false;
    }
    else
    {
        return true;
    }
}
}  // namespace fnv_006eac70

struct RequestAssigner
{
    void FUN_006e5cc0(PathingRequest*);
};
struct QueueAssigner
{
};
struct PathingTaskShell : PathingTaskData
{
    void AssignRequestAndQueue(PathingRequest* request, NiPointer<ActorPathingMessageQueue> queue);
};
// @fnv 0x006e9db0
void PathingTaskShell::AssignRequestAndQueue(PathingRequest* request, NiPointer<ActorPathingMessageQueue> queue)
{
    reinterpret_cast<RequestAssigner*>(&m_pPathingRequest)->FUN_006e5cc0(request);
    reinterpret_cast<::FUN_006ebfb0_Class *>((reinterpret_cast<QueueAssigner*>(&spQueue)))->AssignPointer((int **)&(queue));
}

struct SearchItem
{
    int unk00;
    int flags;
};
struct PathingSolutionExt;
struct RayCastParam;
struct PathingSearchRayCast
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
    PathingSearchRayCast();
    ~PathingSearchRayCast();
public:
    unsigned int ProcessRayCast(::RayCastParam *, ::PathingSolutionExt *);
};
struct SearchArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    SearchItem*& FUN_00877a30(unsigned int);
};
struct SearchLock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct ManagerView
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SearchLock lock;
    SearchArray first;
    SearchArray second;
    int FUN_006ea350();
};
// @fnv 0x006ea350
int ManagerView::FUN_006ea350()
{
    int total = 0;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(first))->GetName())); i++)
    {
        if (second.FUN_00877a30(i)->flags == 0)
        {
            PathingSearchRayCast rayCast;
            reinterpret_cast<::PathingSearchRayCast *>(&(rayCast))->ProcessRayCast((::RayCastParam *)(first.FUN_00877a30(i)), (::PathingSolutionExt *)(second.FUN_00877a30(i)));
            total += ((int)(std::uintptr_t)(reinterpret_cast<::EffectSetting *>(&(rayCast))->GetHitSound()));
            if (total > 10)
                break;
        }
    }
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return total;
}

struct BGSChangeFlags_6eab30
{
    int unk00;
    ~BGSChangeFlags_6eab30();
};

struct PM1_6eab30
{
    int unk000;
    int unk001;
    int unk002;
    int unk003;
    int unk004;
    int unk005;
    int unk006;
    int unk007;
    int unk008;
    int unk009;
    int unk00a;
    int unk00b;
    int unk00c;
    int unk00d;
    int unk00e;
    int unk00f;
    int unk010;
    int unk011;
    int unk012;
    int unk013;
    int unk014;
    int unk015;
    int unk016;
    int unk017;
    int unk018;
    int unk019;
    int unk01a;
    int unk01b;
    int unk01c;
    int unk01d;
    int unk01e;
    int unk01f;
    int unk020;
    int unk021;
    int unk022;
    int unk023;
    int unk024;
    int unk025;
    int unk026;
    int unk027;
    int unk028;
    int unk029;
    int unk02a;
    int unk02b;
    int unk02c;
    int unk02d;
    int unk02e;
    int unk02f;
    int unk030;
    int unk031;
    int unk032;
    int unk033;
    int unk034;
    int unk035;
    int unk036;
    int unk037;
    int unk038;
    int unk039;
    int unk03a;
    int unk03b;
    int unk03c;
    int unk03d;
    int unk03e;
    int unk03f;
    int unk040;
    int unk041;
    int unk042;
    int unk043;
    int unk044;
    int unk045;
    int unk046;
    int unk047;
    int unk048;
    int unk049;
    int unk04a;
    int unk04b;
    int unk04c;
    int unk04d;
    int unk04e;
    int unk04f;
    int unk050;
    int unk051;
    int unk052;
    int unk053;
    int unk054;
    int unk055;
    int unk056;
    int unk057;
    int unk058;
    int unk059;
    int unk05a;
    int unk05b;
    int unk05c;
    int unk05d;
    int unk05e;
    int unk05f;
    int unk060;
    int unk061;
    int unk062;
    int unk063;
    int unk064;
    int unk065;
    int unk066;
    int unk067;
    int unk068;
    int unk069;
    int unk06a;
    int unk06b;
    int unk06c;
    int unk06d;
    int unk06e;
    int unk06f;
    int unk070;
    int unk071;
    int unk072;
    int unk073;
    int unk074;
    int unk075;
    int unk076;
    int unk077;
    int unk078;
    int unk079;
    int unk07a;
    int unk07b;
    int unk07c;
    int unk07d;
    int unk07e;
    int unk07f;
    int unk080;
    int unk081;
    int unk082;
    int unk083;
    int unk084;
    int unk085;
    int unk086;
    int unk087;
    int unk088;
    int unk089;
    int unk08a;
    int unk08b;
    int unk08c;
    int unk08d;
    int unk08e;
    int unk08f;
    int unk090;
    int unk091;
    int unk092;
    int unk093;
    int unk094;
    int unk095;
    int unk096;
    int unk097;
    int unk098;
    int unk099;
    int unk09a;
    int unk09b;
    int unk09c;
    int unk09d;
    int unk09e;
    int unk09f;
    int unk0a0;
    int unk0a1;
    int unk0a2;
    int unk0a3;
    int unk0a4;
    int unk0a5;
    int unk0a6;
    int unk0a7;
    int unk0a8;
    int unk0a9;
    int unk0aa;
    int unk0ab;
    int unk0ac;
    int unk0ad;
    int unk0ae;
    int unk0af;
    int unk0b0;
    int unk0b1;
    int unk0b2;
    int unk0b3;
    int unk0b4;
    int unk0b5;
    int unk0b6;
    int unk0b7;
    int unk0b8;
    int unk0b9;
    int unk0ba;
    int unk0bb;
    int unk0bc;
    int unk0bd;
    int unk0be;
    int unk0bf;
    int unk0c0;
    int unk0c1;
    int unk0c2;
    int unk0c3;
    int unk0c4;
    int unk0c5;
    int unk0c6;
    int unk0c7;
    int unk0c8;
    int unk0c9;
    int unk0ca;
    int unk0cb;
    int unk0cc;
    int unk0cd;
    int unk0ce;
    int unk0cf;
    int unk0d0;
    int unk0d1;
    int unk0d2;
    int unk0d3;
    int unk0d4;
    int unk0d5;
    int unk0d6;
    int unk0d7;
    int unk0d8;
    int unk0d9;
    int unk0da;
    int unk0db;
    int unk0dc;
    int unk0dd;
    int unk0de;
    int unk0df;
    int unk0e0;
    int unk0e1;
    int unk0e2;
    int unk0e3;
    int unk0e4;
    int unk0e5;
    int unk0e6;
    int unk0e7;
    int unk0e8;
    int unk0e9;
    int unk0ea;
    int unk0eb;
    int unk0ec;
    int unk0ed;
    int unk0ee;
    int unk0ef;
    int unk0f0;
    int unk0f1;
    int unk0f2;
    int unk0f3;
    int unk0f4;
    int unk0f5;
    int unk0f6;
    int unk0f7;
    int unk0f8;
    int unk0f9;
    int unk0fa;
    int unk0fb;
    int unk0fc;
    int unk0fd;
    int unk0fe;
    int unk0ff;
    int unk100;
    int unk101;
    int unk102;
    int unk103;
    int unk104;
    int unk105;
    int unk106;
    int unk107;
    int unk108;
    int unk109;
    int unk10a;
    int unk10b;
    int unk10c;
    int unk10d;
    int unk10e;
    int unk10f;
    int unk110;
    int unk111;
    int unk112;
    int unk113;
    int unk114;
    int unk115;
    int unk116;
    int unk117;
    int unk118;
    int unk119;
    int unk11a;
    int unk11b;
    int unk11c;
    int unk11d;
    int unk11e;
    int unk11f;
    int unk120;
    int unk121;
    int unk122;
    int unk123;
    int unk124;
    int unk125;
    int unk126;
    int unk127;
    int unk128;
    int unk129;
    int unk12a;
    int unk12b;
    int unk12c;
    int unk12d;
    int unk12e;
    int unk12f;
    int unk130;
    int unk131;
    int unk132;
    int unk133;
    int unk134;
    int unk135;
    int unk136;
    int unk137;
    int unk138;
    int unk139;
    int unk13a;
    int unk13b;
    int unk13c;
    int unk13d;
    int unk13e;
    int unk13f;
    int unk140;
    int unk141;
    int unk142;
    int unk143;
    int unk144;
    int unk145;
    int unk146;
    int unk147;
    int unk148;
    int unk149;
    int unk14a;
    int unk14b;
    int unk14c;
    int unk14d;
    int unk14e;
    int unk14f;
    int unk150;
    int unk151;
    int unk152;
    int unk153;
    int unk154;
    int unk155;
    int unk156;
    int unk157;
    int unk158;
    int unk159;
    int unk15a;
    int unk15b;
    int unk15c;
    int unk15d;
    int unk15e;
    int unk15f;
    int unk160;
    int unk161;
    int unk162;
    int unk163;
    int unk164;
    int unk165;
    int unk166;
    int unk167;
    int unk168;
    int unk169;
    int unk16a;
    int unk16b;
    int unk16c;
    int unk16d;
    int unk16e;
    int unk16f;
    int unk170;
    int unk171;
    int unk172;
    int unk173;
    int unk174;
    int unk175;
    int unk176;
    int unk177;
    int unk178;
    int unk179;
    int unk17a;
    int unk17b;
    int unk17c;
    int unk17d;
    int unk17e;
    int unk17f;
    int unk180;
    int unk181;
    int unk182;
    int unk183;
    int unk184;
    int unk185;
    int unk186;
    int unk187;
    int unk188;
    int unk189;
    int unk18a;
    int unk18b;
    int unk18c;
    int unk18d;
    int unk18e;
    int unk18f;
    int unk190;
    int unk191;
    int unk192;
    int unk193;
    int unk194;
    int unk195;
    int unk196;
    int unk197;
    int unk198;
    int unk199;
    int unk19a;
    int unk19b;
    int unk19c;
    int unk19d;
    int unk19e;
    int unk19f;
    int unk1a0;
    int unk1a1;
    int unk1a2;
    int unk1a3;
    int unk1a4;
    int unk1a5;
    int unk1a6;
    int unk1a7;
    int unk1a8;
    int unk1a9;
    int unk1aa;
    int unk1ab;
    int unk1ac;
    int unk1ad;
    int unk1ae;
    int unk1af;
    int unk1b0;
    int unk1b1;
    int unk1b2;
    int unk1b3;
    int unk1b4;
    int unk1b5;
    int unk1b6;
    int unk1b7;
    int unk1b8;
    int unk1b9;
    int unk1ba;
    int unk1bb;
    int unk1bc;
    int unk1bd;
    int unk1be;
    int unk1bf;
    int unk1c0;
    int unk1c1;
    int unk1c2;
    int unk1c3;
    int unk1c4;
    int unk1c5;
    int unk1c6;
    int unk1c7;
    int unk1c8;
    int unk1c9;
    int unk1ca;
    int unk1cb;
    int unk1cc;
    int unk1cd;
    int unk1ce;
    int unk1cf;
    int unk1d0;
    int unk1d1;
    int unk1d2;
    int unk1d3;
    int unk1d4;
    int unk1d5;
    int unk1d6;
    int unk1d7;
    int unk1d8;
    int unk1d9;
    int unk1da;
    int unk1db;
    int unk1dc;
    int unk1dd;
    int unk1de;
    int unk1df;
    int unk1e0;
    int unk1e1;
    int unk1e2;
    int unk1e3;
    int unk1e4;
    int unk1e5;
    int unk1e6;
    int unk1e7;
    int unk1e8;
    int unk1e9;
    int unk1ea;
    int unk1eb;
    int unk1ec;
    int unk1ed;
    int unk1ee;
    int unk1ef;
    int unk1f0;
    int unk1f1;
    int unk1f2;
    int unk1f3;
    int unk1f4;
    int unk1f5;
    int unk1f6;
    int unk1f7;
    int unk1f8;
    int unk1f9;
    int unk1fa;
    int unk1fb;
    int unk1fc;
    int unk1fd;
    int unk1fe;
    int unk1ff;
    int unk200;
    int unk201;
    int unk202;
    int unk203;
    int unk204;
    int unk205;
    int unk206;
    int unk207;
    int unk208;
    int unk209;
    int unk20a;
    int unk20b;
    int unk20c;
    int unk20d;
    int unk20e;
    int unk20f;
    int unk210;
    int unk211;
    int unk212;
    int unk213;
    int unk214;
    int unk215;
    int unk216;
    int unk217;
    int unk218;
    int unk219;
    int unk21a;
    int unk21b;
    int unk21c;
    int unk21d;
    int unk21e;
    int unk21f;
    int unk220;
    int unk221;
    int unk222;
    int unk223;
    int unk224;
    int unk225;
    int unk226;
    int unk227;
    int unk228;
    int unk229;
    int unk22a;
    int unk22b;
    int unk22c;
    int unk22d;
    int unk22e;
    int unk22f;
    int unk230;
    int unk231;
    int unk232;
    int unk233;
    int unk234;
    int unk235;
    int unk236;
    int unk237;
    int unk238;
    int unk239;
    int unk23a;
    int unk23b;
    int unk23c;
    int unk23d;
    int unk23e;
    int unk23f;
    int unk240;
    int unk241;
    int unk242;
    int unk243;
    int unk244;
    int unk245;
    int unk246;
    int unk247;
    int unk248;
    int unk249;
    int unk24a;
    int unk24b;
    int unk24c;
    int unk24d;
    int unk24e;
    int unk24f;
    int unk250;
    int unk251;
    int unk252;
    int unk253;
    int unk254;
    int unk255;
    int unk256;
    int unk257;
    int unk258;
    int unk259;
    int unk25a;
    int unk25b;
    int unk25c;
    int unk25d;
    int unk25e;
    int unk25f;
    int unk260;
    int unk261;
    int unk262;
    int unk263;
    int unk264;
    int unk265;
    int unk266;
    int unk267;
    int unk268;
    int unk269;
    int unk26a;
    int unk26b;
    int unk26c;
    int unk26d;
    int unk26e;
    int unk26f;
    int unk270;
    int unk271;
    int unk272;
    int unk273;
    int unk274;
    int unk275;
    int unk276;
    int unk277;
    int unk278;
    int unk279;
    int unk27a;
    int unk27b;
    int unk27c;
    int unk27d;
    int unk27e;
    int unk27f;
    int unk280;
    int unk281;
    int unk282;
    int unk283;
    int unk284;
    int unk285;
    int unk286;
    int unk287;
    int unk288;
    int unk289;
    int unk28a;
    int unk28b;
    int unk28c;
    int unk28d;
    int unk28e;
    int unk28f;
    int unk290;
    int unk291;
    int unk292;
    int unk293;
    int unk294;
    int unk295;
    int unk296;
    int unk297;
    int unk298;
    int unk299;
    int unk29a;
    int unk29b;
    int unk29c;
    int unk29d;
    int unk29e;
    int unk29f;
    int unk2a0;
    int unk2a1;
    int unk2a2;
    int unk2a3;
    int unk2a4;
    int unk2a5;
    int unk2a6;
    int unk2a7;
    int unk2a8;
    int unk2a9;
    int unk2aa;
    int unk2ab;
    int unk2ac;
    int unk2ad;
    int unk2ae;
    int unk2af;
    int unk2b0;
    int unk2b1;
    int unk2b2;
    int unk2b3;
    int unk2b4;
    int unk2b5;
    int unk2b6;
    int unk2b7;
    int unk2b8;
    int unk2b9;
    int unk2ba;
    int unk2bb;
    int unk2bc;
    int unk2bd;
    int unk2be;
    int unk2bf;
    int unk2c0;
    int unk2c1;
    int unk2c2;
    int unk2c3;
    int unk2c4;
    int unk2c5;
    int unk2c6;
    int unk2c7;
    int unk2c8;
    int unk2c9;
    int unk2ca;
    int unk2cb;
    int unk2cc;
    int unk2cd;
    int unk2ce;
    int unk2cf;
    int unk2d0;
    int unk2d1;
    int unk2d2;
    int unk2d3;
    int unk2d4;
    int unk2d5;
    int unk2d6;
    int unk2d7;
    int unk2d8;
    int unk2d9;
    int unk2da;
    int unk2db;
    int unk2dc;
    int unk2dd;
    int unk2de;
    int unk2df;
    int unk2e0;
    int unk2e1;
    int unk2e2;
    int unk2e3;
    int unk2e4;
    int unk2e5;
    int unk2e6;
    int unk2e7;
    int unk2e8;
    int unk2e9;
    int unk2ea;
    int unk2eb;
    int unk2ec;
    int unk2ed;
    int unk2ee;
    int unk2ef;
    int unk2f0;
    int unk2f1;
    int unk2f2;
    int unk2f3;
    int unk2f4;
    int unk2f5;
    int unk2f6;
    int unk2f7;
    int unk2f8;
    int unk2f9;
    int unk2fa;
    int unk2fb;
    int unk2fc;
    int unk2fd;
    int unk2fe;
    int unk2ff;
    int unk300;
    int unk301;
    int unk302;
    ~PM1_6eab30();
};

struct PM2_6eab30
{
    int unk000;
    int unk001;
    int unk002;
    int unk003;
    int unk004;
    ~PM2_6eab30();
};

struct GOG_6eab30
{
    int unk000;
    int unk001;
    int unk002;
    int unk003;
    int unk004;
    int unk005;
    ~GOG_6eab30();
};

struct PM4_6eab30
{
    int unk000;
    int unk001;
    int unk002;
    int unk003;
    int unk004;
    int unk005;
    int unk006;
    int unk007;
    int unk008;
    int unk009;
    int unk00a;
    int unk00b;
    int unk00c;
    int unk00d;
    int unk00e;
    int unk00f;
    int unk010;
    int unk011;
    int unk012;
    int unk013;
    int unk014;
    int unk015;
    int unk016;
    int unk017;
    int unk018;
    int unk019;
    int unk01a;
    int unk01b;
    int unk01c;
    int unk01d;
    int unk01e;
    int unk01f;
    int unk020;
    int unk021;
    int unk022;
    int unk023;
    int unk024;
    int unk025;
    int unk026;
    int unk027;
    int unk028;
    int unk029;
    int unk02a;
    int unk02b;
    int unk02c;
    int unk02d;
    int unk02e;
    int unk02f;
    int unk030;
    int unk031;
    int unk032;
    int unk033;
    int unk034;
    int unk035;
    int unk036;
    int unk037;
    int unk038;
    int unk039;
    int unk03a;
    int unk03b;
    int unk03c;
    int unk03d;
    int unk03e;
    int unk03f;
    int unk040;
    int unk041;
    int unk042;
    int unk043;
    int unk044;
    int unk045;
    int unk046;
    int unk047;
    int unk048;
    int unk049;
    int unk04a;
    int unk04b;
    int unk04c;
    int unk04d;
    int unk04e;
    int unk04f;
    int unk050;
    int unk051;
    int unk052;
    int unk053;
    int unk054;
    int unk055;
    int unk056;
    int unk057;
    int unk058;
    int unk059;
    int unk05a;
    int unk05b;
    int unk05c;
    int unk05d;
    int unk05e;
    int unk05f;
    int unk060;
    int unk061;
    int unk062;
    int unk063;
    int unk064;
    int unk065;
    int unk066;
    int unk067;
    int unk068;
    int unk069;
    int unk06a;
    int unk06b;
    int unk06c;
    int unk06d;
    int unk06e;
    int unk06f;
    int unk070;
    int unk071;
    int unk072;
    int unk073;
    int unk074;
    int unk075;
    int unk076;
    int unk077;
    int unk078;
    int unk079;
    int unk07a;
    int unk07b;
    int unk07c;
    int unk07d;
    int unk07e;
    int unk07f;
    int unk080;
    int unk081;
    int unk082;
    int unk083;
    int unk084;
    int unk085;
    int unk086;
    int unk087;
    int unk088;
    int unk089;
    int unk08a;
    int unk08b;
    int unk08c;
    int unk08d;
    int unk08e;
    int unk08f;
    int unk090;
    int unk091;
    int unk092;
    int unk093;
    int unk094;
    int unk095;
    int unk096;
    int unk097;
    int unk098;
    int unk099;
    int unk09a;
    int unk09b;
    int unk09c;
    int unk09d;
    int unk09e;
    int unk09f;
    int unk0a0;
    int unk0a1;
    int unk0a2;
    int unk0a3;
    int unk0a4;
    int unk0a5;
    int unk0a6;
    int unk0a7;
    int unk0a8;
    int unk0a9;
    int unk0aa;
    int unk0ab;
    int unk0ac;
    int unk0ad;
    int unk0ae;
    int unk0af;
    int unk0b0;
    int unk0b1;
    int unk0b2;
    int unk0b3;
    int unk0b4;
    int unk0b5;
    int unk0b6;
    int unk0b7;
    int unk0b8;
    int unk0b9;
    int unk0ba;
    int unk0bb;
    int unk0bc;
    int unk0bd;
    int unk0be;
    int unk0bf;
    int unk0c0;
    int unk0c1;
    int unk0c2;
    int unk0c3;
    int unk0c4;
    int unk0c5;
    int unk0c6;
    int unk0c7;
    int unk0c8;
    int unk0c9;
    int unk0ca;
    int unk0cb;
    int unk0cc;
    int unk0cd;
    int unk0ce;
    int unk0cf;
    int unk0d0;
    int unk0d1;
    int unk0d2;
    int unk0d3;
    int unk0d4;
    int unk0d5;
    int unk0d6;
    int unk0d7;
    int unk0d8;
    int unk0d9;
    int unk0da;
    int unk0db;
    int unk0dc;
    int unk0dd;
    int unk0de;
    int unk0df;
    int unk0e0;
    int unk0e1;
    int unk0e2;
    int unk0e3;
    int unk0e4;
    int unk0e5;
    int unk0e6;
    int unk0e7;
    int unk0e8;
    int unk0e9;
    int unk0ea;
    int unk0eb;
    int unk0ec;
    int unk0ed;
    int unk0ee;
    int unk0ef;
    int unk0f0;
    int unk0f1;
    int unk0f2;
    int unk0f3;
    int unk0f4;
    int unk0f5;
    int unk0f6;
    int unk0f7;
    int unk0f8;
    int unk0f9;
    int unk0fa;
    int unk0fb;
    int unk0fc;
    int unk0fd;
    int unk0fe;
    int unk0ff;
    int unk100;
    int unk101;
    int unk102;
    int unk103;
    int unk104;
    ~PM4_6eab30();
};

struct PM5_6eab30
{
    int unk000;
    int unk001;
    int unk002;
    int unk003;
    int unk004;
    int unk005;
    int unk006;
    int unk007;
    int unk008;
    int unk009;
    int unk00a;
    int unk00b;
    int unk00c;
    int unk00d;
    int unk00e;
    int unk00f;
    int unk010;
    int unk011;
    int unk012;
    int unk013;
    int unk014;
    int unk015;
    int unk016;
    int unk017;
    int unk018;
    int unk019;
    int unk01a;
    int unk01b;
    int unk01c;
    int unk01d;
    int unk01e;
    int unk01f;
    int unk020;
    int unk021;
    int unk022;
    int unk023;
    int unk024;
    int unk025;
    int unk026;
    int unk027;
    int unk028;
    int unk029;
    int unk02a;
    int unk02b;
    int unk02c;
    int unk02d;
    int unk02e;
    int unk02f;
    int unk030;
    int unk031;
    int unk032;
    int unk033;
    int unk034;
    int unk035;
    int unk036;
    int unk037;
    int unk038;
    int unk039;
    int unk03a;
    int unk03b;
    int unk03c;
    int unk03d;
    int unk03e;
    int unk03f;
    int unk040;
    int unk041;
    int unk042;
    int unk043;
    int unk044;
    int unk045;
    int unk046;
    int unk047;
    int unk048;
    int unk049;
    int unk04a;
    int unk04b;
    int unk04c;
    int unk04d;
    int unk04e;
    int unk04f;
    int unk050;
    int unk051;
    int unk052;
    int unk053;
    int unk054;
    int unk055;
    int unk056;
    int unk057;
    int unk058;
    int unk059;
    int unk05a;
    int unk05b;
    int unk05c;
    int unk05d;
    int unk05e;
    int unk05f;
    int unk060;
    int unk061;
    int unk062;
    int unk063;
    int unk064;
    int unk065;
    int unk066;
    int unk067;
    int unk068;
    int unk069;
    int unk06a;
    int unk06b;
    int unk06c;
    int unk06d;
    int unk06e;
    int unk06f;
    int unk070;
    int unk071;
    int unk072;
    int unk073;
    int unk074;
    int unk075;
    int unk076;
    int unk077;
    int unk078;
    int unk079;
    int unk07a;
    int unk07b;
    int unk07c;
    int unk07d;
    int unk07e;
    int unk07f;
    int unk080;
    int unk081;
    int unk082;
    int unk083;
    int unk084;
    int unk085;
    int unk086;
    int unk087;
    int unk088;
    int unk089;
    int unk08a;
    int unk08b;
    int unk08c;
    int unk08d;
    int unk08e;
    int unk08f;
    int unk090;
    int unk091;
    int unk092;
    int unk093;
    int unk094;
    int unk095;
    int unk096;
    int unk097;
    int unk098;
    int unk099;
    int unk09a;
    int unk09b;
    int unk09c;
    int unk09d;
    int unk09e;
    int unk09f;
    int unk0a0;
    int unk0a1;
    int unk0a2;
    int unk0a3;
    int unk0a4;
    int unk0a5;
    int unk0a6;
    int unk0a7;
    int unk0a8;
    int unk0a9;
    int unk0aa;
    int unk0ab;
    int unk0ac;
    int unk0ad;
    int unk0ae;
    int unk0af;
    int unk0b0;
    int unk0b1;
    int unk0b2;
    int unk0b3;
    int unk0b4;
    int unk0b5;
    int unk0b6;
    int unk0b7;
    int unk0b8;
    int unk0b9;
    int unk0ba;
    int unk0bb;
    int unk0bc;
    int unk0bd;
    int unk0be;
    int unk0bf;
    int unk0c0;
    int unk0c1;
    int unk0c2;
    int unk0c3;
    int unk0c4;
    int unk0c5;
    int unk0c6;
    int unk0c7;
    int unk0c8;
    int unk0c9;
    int unk0ca;
    int unk0cb;
    int unk0cc;
    int unk0cd;
    int unk0ce;
    int unk0cf;
    int unk0d0;
    int unk0d1;
    int unk0d2;
    int unk0d3;
    int unk0d4;
    int unk0d5;
    int unk0d6;
    int unk0d7;
    int unk0d8;
    int unk0d9;
    int unk0da;
    int unk0db;
    int unk0dc;
    int unk0dd;
    int unk0de;
    int unk0df;
    int unk0e0;
    int unk0e1;
    int unk0e2;
    int unk0e3;
    int unk0e4;
    int unk0e5;
    int unk0e6;
    int unk0e7;
    int unk0e8;
    int unk0e9;
    int unk0ea;
    int unk0eb;
    int unk0ec;
    int unk0ed;
    int unk0ee;
    int unk0ef;
    int unk0f0;
    int unk0f1;
    int unk0f2;
    int unk0f3;
    int unk0f4;
    int unk0f5;
    int unk0f6;
    int unk0f7;
    int unk0f8;
    int unk0f9;
    int unk0fa;
    int unk0fb;
    int unk0fc;
    int unk0fd;
    int unk0fe;
    int unk0ff;
    int unk100;
    int unk101;
    int unk102;
    int unk103;
    int unk104;
    int unk105;
    int unk106;
    ~PM5_6eab30();
};

struct PMA_6eab30
{
    int unk000;
    int unk001;
    int unk002;
    int unk003;
    int unk004;
    int unk005;
    int unk006;
    ~PMA_6eab30();
};

struct FUN_006eab30_cls : public BGSChangeFlags_6eab30
{
    PM1_6eab30 m_04;
    PM2_6eab30 m_c10;
    int m_i1;
    int m_i2;
    int m_c2c;
    int m_c30;
    int m_c34;
    GOG_6eab30 m_c38;
    PM4_6eab30 m_c50;
    PM5_6eab30 m_1064;
    PMA_6eab30 m_1480;
    ~FUN_006eab30_cls();
};
// Calls FUN_006eab30, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x006eb890
void* Tmp_006eb890::FUN_006eb890(unsigned int flags)
{
    reinterpret_cast<::FUN_006eab30_cls *>(this)->::FUN_006eab30_cls::~FUN_006eab30_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor of the change-flags object; the body is empty, so member destructors run implicitly.
// @fnv 0x006eab30
FUN_006eab30_cls::~FUN_006eab30_cls()
{}

struct FUN_006eb250_VirtualObject
{
    virtual void vf0();
    virtual void vf1();
    virtual bool vf2(int value, int* result);
};

struct FUN_006ea780_Obj
{
    unsigned int RequestLocationStatus(std::intptr_t a1, int a2, std::intptr_t a3, int a4);
};

struct FUN_006eb250_Class
{
    unsigned int CallVirtualObjectMethod(int arg1, int arg2, int arg3, int arg4, bool arg5);
};

// Calls vf2 on the object at this+0x1480; if it succeeds, forwards arg2-arg5 to RequestLocationStatus on the returned object, otherwise returns 2.
// @fnv 0x006eb250
unsigned int FUN_006eb250_Class::CallVirtualObjectMethod(int aiValue, int arg2, int arg3, int arg4,
                                                                    bool arg5)
{
    int resultObject = 0;

    if (reinterpret_cast<FUN_006eb250_VirtualObject*>(reinterpret_cast<char*>(this) + 0x1480)
            ->vf2(aiValue, &resultObject))
    {
        return reinterpret_cast<FUN_006ea780_Obj*>(resultObject)->RequestLocationStatus(arg2, arg3, arg4, arg5);
    }
    else
    {
        return 2;
    }
}

class EB2B0Item
{
  public:
};

class EB2B0Map
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual bool GetAt(unsigned int uiKey, EB2B0Item*& pkItem);
};

class EB2B0Owner
{
  public:
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    int unk08B8;
    int unk08BC;
    int unk08C0;
    int unk08C4;
    int unk08C8;
    int unk08CC;
    int unk08D0;
    int unk08D4;
    int unk08D8;
    int unk08DC;
    int unk08E0;
    int unk08E4;
    int unk08E8;
    int unk08EC;
    int unk08F0;
    int unk08F4;
    int unk08F8;
    int unk08FC;
    int unk0900;
    int unk0904;
    int unk0908;
    int unk090C;
    int unk0910;
    int unk0914;
    int unk0918;
    int unk091C;
    int unk0920;
    int unk0924;
    int unk0928;
    int unk092C;
    int unk0930;
    int unk0934;
    int unk0938;
    int unk093C;
    int unk0940;
    int unk0944;
    int unk0948;
    int unk094C;
    int unk0950;
    int unk0954;
    int unk0958;
    int unk095C;
    int unk0960;
    int unk0964;
    int unk0968;
    int unk096C;
    int unk0970;
    int unk0974;
    int unk0978;
    int unk097C;
    int unk0980;
    int unk0984;
    int unk0988;
    int unk098C;
    int unk0990;
    int unk0994;
    int unk0998;
    int unk099C;
    int unk09A0;
    int unk09A4;
    int unk09A8;
    int unk09AC;
    int unk09B0;
    int unk09B4;
    int unk09B8;
    int unk09BC;
    int unk09C0;
    int unk09C4;
    int unk09C8;
    int unk09CC;
    int unk09D0;
    int unk09D4;
    int unk09D8;
    int unk09DC;
    int unk09E0;
    int unk09E4;
    int unk09E8;
    int unk09EC;
    int unk09F0;
    int unk09F4;
    int unk09F8;
    int unk09FC;
    int unk0A00;
    int unk0A04;
    int unk0A08;
    int unk0A0C;
    int unk0A10;
    int unk0A14;
    int unk0A18;
    int unk0A1C;
    int unk0A20;
    int unk0A24;
    int unk0A28;
    int unk0A2C;
    int unk0A30;
    int unk0A34;
    int unk0A38;
    int unk0A3C;
    int unk0A40;
    int unk0A44;
    int unk0A48;
    int unk0A4C;
    int unk0A50;
    int unk0A54;
    int unk0A58;
    int unk0A5C;
    int unk0A60;
    int unk0A64;
    int unk0A68;
    int unk0A6C;
    int unk0A70;
    int unk0A74;
    int unk0A78;
    int unk0A7C;
    int unk0A80;
    int unk0A84;
    int unk0A88;
    int unk0A8C;
    int unk0A90;
    int unk0A94;
    int unk0A98;
    int unk0A9C;
    int unk0AA0;
    int unk0AA4;
    int unk0AA8;
    int unk0AAC;
    int unk0AB0;
    int unk0AB4;
    int unk0AB8;
    int unk0ABC;
    int unk0AC0;
    int unk0AC4;
    int unk0AC8;
    int unk0ACC;
    int unk0AD0;
    int unk0AD4;
    int unk0AD8;
    int unk0ADC;
    int unk0AE0;
    int unk0AE4;
    int unk0AE8;
    int unk0AEC;
    int unk0AF0;
    int unk0AF4;
    int unk0AF8;
    int unk0AFC;
    int unk0B00;
    int unk0B04;
    int unk0B08;
    int unk0B0C;
    int unk0B10;
    int unk0B14;
    int unk0B18;
    int unk0B1C;
    int unk0B20;
    int unk0B24;
    int unk0B28;
    int unk0B2C;
    int unk0B30;
    int unk0B34;
    int unk0B38;
    int unk0B3C;
    int unk0B40;
    int unk0B44;
    int unk0B48;
    int unk0B4C;
    int unk0B50;
    int unk0B54;
    int unk0B58;
    int unk0B5C;
    int unk0B60;
    int unk0B64;
    int unk0B68;
    int unk0B6C;
    int unk0B70;
    int unk0B74;
    int unk0B78;
    int unk0B7C;
    int unk0B80;
    int unk0B84;
    int unk0B88;
    int unk0B8C;
    int unk0B90;
    int unk0B94;
    int unk0B98;
    int unk0B9C;
    int unk0BA0;
    int unk0BA4;
    int unk0BA8;
    int unk0BAC;
    int unk0BB0;
    int unk0BB4;
    int unk0BB8;
    int unk0BBC;
    int unk0BC0;
    int unk0BC4;
    int unk0BC8;
    int unk0BCC;
    int unk0BD0;
    int unk0BD4;
    int unk0BD8;
    int unk0BDC;
    int unk0BE0;
    int unk0BE4;
    int unk0BE8;
    int unk0BEC;
    int unk0BF0;
    int unk0BF4;
    int unk0BF8;
    int unk0BFC;
    int unk0C00;
    int unk0C04;
    int unk0C08;
    int unk0C0C;
    int unk0C10;
    int unk0C14;
    int unk0C18;
    int unk0C1C;
    int unk0C20;
    int unk0C24;
    int unk0C28;
    int unk0C2C;
    int unk0C30;
    int unk0C34;
    int unk0C38;
    int unk0C3C;
    int unk0C40;
    int unk0C44;
    int unk0C48;
    int unk0C4C;
    int unk0C50;
    int unk0C54;
    int unk0C58;
    int unk0C5C;
    int unk0C60;
    int unk0C64;
    int unk0C68;
    int unk0C6C;
    int unk0C70;
    int unk0C74;
    int unk0C78;
    int unk0C7C;
    int unk0C80;
    int unk0C84;
    int unk0C88;
    int unk0C8C;
    int unk0C90;
    int unk0C94;
    int unk0C98;
    int unk0C9C;
    int unk0CA0;
    int unk0CA4;
    int unk0CA8;
    int unk0CAC;
    int unk0CB0;
    int unk0CB4;
    int unk0CB8;
    int unk0CBC;
    int unk0CC0;
    int unk0CC4;
    int unk0CC8;
    int unk0CCC;
    int unk0CD0;
    int unk0CD4;
    int unk0CD8;
    int unk0CDC;
    int unk0CE0;
    int unk0CE4;
    int unk0CE8;
    int unk0CEC;
    int unk0CF0;
    int unk0CF4;
    int unk0CF8;
    int unk0CFC;
    int unk0D00;
    int unk0D04;
    int unk0D08;
    int unk0D0C;
    int unk0D10;
    int unk0D14;
    int unk0D18;
    int unk0D1C;
    int unk0D20;
    int unk0D24;
    int unk0D28;
    int unk0D2C;
    int unk0D30;
    int unk0D34;
    int unk0D38;
    int unk0D3C;
    int unk0D40;
    int unk0D44;
    int unk0D48;
    int unk0D4C;
    int unk0D50;
    int unk0D54;
    int unk0D58;
    int unk0D5C;
    int unk0D60;
    int unk0D64;
    int unk0D68;
    int unk0D6C;
    int unk0D70;
    int unk0D74;
    int unk0D78;
    int unk0D7C;
    int unk0D80;
    int unk0D84;
    int unk0D88;
    int unk0D8C;
    int unk0D90;
    int unk0D94;
    int unk0D98;
    int unk0D9C;
    int unk0DA0;
    int unk0DA4;
    int unk0DA8;
    int unk0DAC;
    int unk0DB0;
    int unk0DB4;
    int unk0DB8;
    int unk0DBC;
    int unk0DC0;
    int unk0DC4;
    int unk0DC8;
    int unk0DCC;
    int unk0DD0;
    int unk0DD4;
    int unk0DD8;
    int unk0DDC;
    int unk0DE0;
    int unk0DE4;
    int unk0DE8;
    int unk0DEC;
    int unk0DF0;
    int unk0DF4;
    int unk0DF8;
    int unk0DFC;
    int unk0E00;
    int unk0E04;
    int unk0E08;
    int unk0E0C;
    int unk0E10;
    int unk0E14;
    int unk0E18;
    int unk0E1C;
    int unk0E20;
    int unk0E24;
    int unk0E28;
    int unk0E2C;
    int unk0E30;
    int unk0E34;
    int unk0E38;
    int unk0E3C;
    int unk0E40;
    int unk0E44;
    int unk0E48;
    int unk0E4C;
    int unk0E50;
    int unk0E54;
    int unk0E58;
    int unk0E5C;
    int unk0E60;
    int unk0E64;
    int unk0E68;
    int unk0E6C;
    int unk0E70;
    int unk0E74;
    int unk0E78;
    int unk0E7C;
    int unk0E80;
    int unk0E84;
    int unk0E88;
    int unk0E8C;
    int unk0E90;
    int unk0E94;
    int unk0E98;
    int unk0E9C;
    int unk0EA0;
    int unk0EA4;
    int unk0EA8;
    int unk0EAC;
    int unk0EB0;
    int unk0EB4;
    int unk0EB8;
    int unk0EBC;
    int unk0EC0;
    int unk0EC4;
    int unk0EC8;
    int unk0ECC;
    int unk0ED0;
    int unk0ED4;
    int unk0ED8;
    int unk0EDC;
    int unk0EE0;
    int unk0EE4;
    int unk0EE8;
    int unk0EEC;
    int unk0EF0;
    int unk0EF4;
    int unk0EF8;
    int unk0EFC;
    int unk0F00;
    int unk0F04;
    int unk0F08;
    int unk0F0C;
    int unk0F10;
    int unk0F14;
    int unk0F18;
    int unk0F1C;
    int unk0F20;
    int unk0F24;
    int unk0F28;
    int unk0F2C;
    int unk0F30;
    int unk0F34;
    int unk0F38;
    int unk0F3C;
    int unk0F40;
    int unk0F44;
    int unk0F48;
    int unk0F4C;
    int unk0F50;
    int unk0F54;
    int unk0F58;
    int unk0F5C;
    int unk0F60;
    int unk0F64;
    int unk0F68;
    int unk0F6C;
    int unk0F70;
    int unk0F74;
    int unk0F78;
    int unk0F7C;
    int unk0F80;
    int unk0F84;
    int unk0F88;
    int unk0F8C;
    int unk0F90;
    int unk0F94;
    int unk0F98;
    int unk0F9C;
    int unk0FA0;
    int unk0FA4;
    int unk0FA8;
    int unk0FAC;
    int unk0FB0;
    int unk0FB4;
    int unk0FB8;
    int unk0FBC;
    int unk0FC0;
    int unk0FC4;
    int unk0FC8;
    int unk0FCC;
    int unk0FD0;
    int unk0FD4;
    int unk0FD8;
    int unk0FDC;
    int unk0FE0;
    int unk0FE4;
    int unk0FE8;
    int unk0FEC;
    int unk0FF0;
    int unk0FF4;
    int unk0FF8;
    int unk0FFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    EB2B0Map m_kFormatEntries;

    int ProcessKeyedItem(unsigned int uiKey, std::intptr_t a, std::intptr_t b, int c);
};

extern const char g_acB6EB310Name[];

class B6EB310Lock
{
  public:
};

class B6EB310Manager
{
  public:
    void FUN_006eb310();

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
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    unsigned int m_eAnimationState;
    unsigned int m_uiTimer;
    int unkC2C;
    int unkC30;
    int unkC34;
    B6EB310Lock m_kLock;
};
// @fnv 0x006ebc70
void FUN_006ebc70_shell::FUN_006ebc70()
{
    reinterpret_cast<::B6EB310Manager *>((*reinterpret_cast<void**>(this)))->FUN_006eb310();
}

// @fnv 0x006eb310
void B6EB310Manager::FUN_006eb310()
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&(m_kLock))->FUN_004538a0((std::intptr_t)(g_acB6EB310Name));
    switch (m_eAnimationState)
    {
    case 0:
        m_eAnimationState = 1;
        m_uiTimer = 0;
        break;
        break;
    case 3:
        m_eAnimationState = 2;
        break;
    }
    reinterpret_cast<::ActorTaskManager *>(&(m_kLock))->WaitForTasksDuringRendering();
}

extern const char g_acB6EB3B0Name[];

class B6EB3B0Lock
{
  public:
};

class B6EB3B0Manager
{
  public:
    void FUN_006eb3b0();

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
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    unsigned int m_eAnimationState;
    int unkC28;
    int unkC2C;
    int unkC30;
    int unkC34;
    B6EB3B0Lock m_kLock;
};
// @fnv 0x006ebcd0
void FUN_006ebcd0_shell::FUN_006ebcd0()
{
    reinterpret_cast<::B6EB3B0Manager *>((*reinterpret_cast<void**>(this)))->FUN_006eb3b0();
}

// @fnv 0x006eb3b0
void B6EB3B0Manager::FUN_006eb3b0()
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&(m_kLock))->FUN_004538a0((std::intptr_t)(g_acB6EB3B0Name));
    switch (m_eAnimationState)
    {
        break;
    case 1:
        m_eAnimationState = 0;
        break;
    case 2:
        m_eAnimationState = 3;
        break;
    }
    reinterpret_cast<::ActorTaskManager *>(&(m_kLock))->WaitForTasksDuringRendering();
}

struct Obj_006eb980_obj
{
};

struct Shell_006eb980
{
    Obj_006eb980_obj* m0;
    void FUN_006eb980();
};

// Calls FUN_006eac40 on m0, then FUN_006eb890(1) on m0 if non-null, and clears m0.
// @fnv 0x006eb980
void Shell_006eb980::FUN_006eb980()
{
    reinterpret_cast<::fnv_006eac40::FUN_006eac40_Holder *>((m0))->FUN_006eac40();
    Obj_006eb980_obj* QQ = m0;
    Obj_006eb980_obj* PP2 = QQ;
    if (PP2 != 0)
        reinterpret_cast<::Tmp_006eb890 *>((PP2))->FUN_006eb890(1);
    m0 = 0;
}

struct Inner006eb440
{
};

struct FUN_006ebcf0_cls
{
    Inner006eb440* m0;
    void CallInner();
};

struct ArrayElement_006ebd30
{
    int first;
    int second;
    int third;
    ~ArrayElement_006ebd30();
};

struct Base_006ebd30
{
    virtual ~Base_006ebd30();
    int state;
    int flags;
};

struct FUN_006ebd30 : Base_006ebd30
{
    ArrayElement_006ebd30 elements[256];
    virtual ~FUN_006ebd30();
};
// @fnv 0x006ebe00
void* S006ebe00::FUN_006ebe00(unsigned int flags)
{
    reinterpret_cast<::FUN_006ebd30 *>(this)->::FUN_006ebd30::~FUN_006ebd30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x006ebd30
FUN_006ebd30::~FUN_006ebd30()
{}

struct PathingLocation17
{
    int v[10];
    PathingLocation17& operator=(const PathingLocation17& other);
};
struct Sub17
{
    int v[4];
};
struct Big17
{
    int type0;
    PathingRequest* req4;
    PathingLocation17 loc8;
    PathingLocation17 loc30;
    int tail58[4];
    Big17();
};
struct Small17
{
    int type0;
    int code4;
    Sub17 sub8;
    Small17();
};
struct Spin17
{
    int v[8];
};
struct Arr40_17
{
    int v[4];
    Big17*& GetAt(unsigned int idx);
    unsigned int Add(Big17*& elem);
};
struct Arr50_17
{
    int v[4];
    Small17*& GetAt(unsigned int idx);
    unsigned int Add(Small17*& elem);
};
struct Host17
{
    int u00;
    int u04;
    int u08;
    int u0c;
    int u10;
    int u14;
    NiPointer<PathingRequest> spReq;
    int u1c;
    Spin17 spin;
    Arr40_17 arr40;
    Arr50_17 arr50;
    int FindOrAddPathingEntry(PathingLocation17& a1, PathingLocation17& a2, int a3);
};
// Looks up the item for uiKey in the map and forwards a, b, c to its Process; returns 2 if the key is not found.
// @fnv 0x006eb2b0
int EB2B0Owner::ProcessKeyedItem(unsigned int uiKey, std::intptr_t aiArg1, std::intptr_t aiArg2, int aiArg3)
{
    EB2B0Item* pkItem = 0;
    if (m_kFormatEntries.GetAt(uiKey, pkItem))
        return reinterpret_cast<::Host17 *>((pkItem))->FindOrAddPathingEntry((*(::PathingLocation17 *)(aiArg1)), (*(::PathingLocation17 *)(aiArg2)), aiArg3);
    else
        return 2;
}

// Locks the spin, scans arr50 for a type 2 entry whose loc8/loc30 match a1/a2 within 0.1, acts on its code4, or appends new Big17/Small17 entries and notifies.
// @fnv 0x006ea510
int Host17::FindOrAddPathingEntry(PathingLocation17& a1, PathingLocation17& a2, int iActivateArg)
{
    int result = 0;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(spin))->FUN_0040fbf0(0);
    int i2 = 0;
    for (; i2 < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr50))->GetName())); ++i2)
    {
        if (arr50.GetAt(i2)->type0 == 2)
        {
            if (reinterpret_cast<::FUN_006deeb0_cls *>(&(arr40.GetAt(i2)->loc8))->IsWithinDistanceOfSameLocation((const ::PathingLocation *)&(a1), 0.1f))
            {
                if (reinterpret_cast<::FUN_006deeb0_cls *>(&(arr40.GetAt(i2)->loc30))->IsWithinDistanceOfSameLocation((const ::PathingLocation *)&(a2), 0.1f))
                {
                    result = arr50.GetAt(i2)->code4;
                    switch (result)
                    {
                    case 2:
                        break;
                    case 1:
                        reinterpret_cast<::FUN_006cf940_cls *>(&(arr50.GetAt(i2)->sub8))->FUN_006cf940((::FUN_006cf940_Owner *)(iActivateArg));
                        break;
                    case 0:
                        reinterpret_cast<::FUN_006ea330_shell *>(this)->FUN_006ea330();
                        break;
                    default:
                        result = 2;
                        break;
                    }
                    reinterpret_cast<::RecursiveSpinLock *>(&(spin))->FUN_0040fba0();
                    return result;
                }
            }
        }
    }
    Big17* pBigEntry = new Big17;
    pBigEntry->req4 = (PathingRequest*)spReq;
    reinterpret_cast<::PathingLocation *>((void *)&(const ::PathingLocation17 &)(pBigEntry->loc8))->operator=((const ::PathingLocation &)(a1));
    reinterpret_cast<::PathingLocation *>((void *)&(const ::PathingLocation17 &)(pBigEntry->loc30))->operator=((const ::PathingLocation &)(a2));
    pBigEntry->type0 = 2;
    Small17* pSmallEntry = new Small17;
    pSmallEntry->type0 = pBigEntry->type0;
    pSmallEntry->code4 = 0;
    reinterpret_cast<::FUN_00438690 *>(&(arr40))->FUN_007cb2e0((unsigned int *)&(pBigEntry));
    reinterpret_cast<::FUN_00438690 *>(&(arr50))->FUN_007cb2e0((unsigned int *)&(pSmallEntry));
    reinterpret_cast<::RecursiveSpinLock *>(&(spin))->FUN_0040fba0();
    reinterpret_cast<::PlayerQuestData *>(this)->SetIndex(1);
    return result;
}


struct RequestLocation
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};
struct RequestShape
{
    int unk00, unk04, unk08, unk0c;
};
struct FUN_006cb3a0
{
    unsigned int type;
    PathManagerImpl* owner;
    int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    RequestLocation location;
    RequestShape shape;
    FUN_006cb3a0();
};
struct FUN_006cb480
{
    unsigned int type, status;
    RequestShape shape;
    FUN_006cb480();
};
template <class T> struct RequestArray
{
    int unk00, unk04, unk08, unk0c;
    unsigned int FUN_0044ddc0();
    T*& FUN_00877a30(unsigned int index);
    unsigned int FUN_007cb2e0(T*& value);
};
struct RequestManager
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    PathManager owner;
    SearchLock lock;
    RequestArray<FUN_006cb3a0> requests;
    RequestArray<FUN_006cb480> statuses;
};
// Locks the manager, searches statuses for a matching type and location, updates or creates the request/status entries, unlocks, and returns the status.
// @fnv 0x006ea780
unsigned int FUN_006ea780_Obj::RequestLocationStatus(std::intptr_t pShape, int iLocation, std::intptr_t a3, int bTypeFlag)
{
    unsigned int status = 0;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(((RequestManager*)this)->lock))->FUN_0040fbf0((char *)(0));
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(((RequestManager*)this)->statuses))->GetName())); i++)
    {
        if (((RequestManager*)this)->statuses.FUN_00877a30(i)->type == !(unsigned char)bTypeFlag &&
            reinterpret_cast<::FUN_006deeb0_cls *>(&(((RequestManager*)this)->requests.FUN_00877a30(i)->location))->IsWithinDistanceOfSameLocation((const ::PathingLocation *)(iLocation), 0.1f))
        {
            status = ((RequestManager*)this)->statuses.FUN_00877a30(i)->status;
            switch (status)
            {
            case 2:
                break;
            case 1:
                reinterpret_cast<::FUN_006cf940_cls *>(&(((RequestManager*)this)->statuses.FUN_00877a30(i)->shape))->FUN_006cf940((::FUN_006cf940_Owner *)(a3));
                break;
            case 0:
                reinterpret_cast<::FUN_006ea330_shell *>((((RequestManager*)this)))->FUN_006ea330();
                break;
            default:
                status = 2;
            }
            reinterpret_cast<::RecursiveSpinLock *>(&(((RequestManager*)this)->lock))->FUN_0040fba0();
            return status;
        }
    }
    FUN_006cb3a0* entry = new FUN_006cb3a0;
    entry->owner = ((::PathManagerImpl *)(::FUN_00559450((int *)&(((RequestManager*)this)->owner))));
    reinterpret_cast<::PathingLocation *>(&(entry->location))->operator=((*(const ::PathingLocation *)(iLocation)));
    reinterpret_cast<::FUN_006cf8a0_cls *>((((RequestShape*)pShape)))->ProcessItems((::ParamHost *)(::RequestShape *)(&entry->shape));
    entry->type = !(unsigned char)bTypeFlag;
    FUN_006cb480* request = new FUN_006cb480;
    request->type = entry->type;
    request->status = 0;
    reinterpret_cast<::FUN_00438690 *>(&(((RequestManager*)this)->requests))->FUN_007cb2e0((unsigned int *)&(entry));
    reinterpret_cast<::FUN_00438690 *>(&(((RequestManager*)this)->statuses))->FUN_007cb2e0((unsigned int *)&(request));
    reinterpret_cast<::RecursiveSpinLock *>(&(((RequestManager*)this)->lock))->FUN_0040fba0();
    reinterpret_cast<::PlayerQuestData *>((((RequestManager*)this)))->SetIndex(1);
    return status;
}

struct QueueTarget;
struct RefView
{
};
struct TaskView
{
    virtual ~TaskView();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    RefView request;
    int solution;
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
    RefView queue;
};
struct MessageView
{
    int type;
    TaskView* task;
    MessageView();
    ~MessageView();
};
struct IteratorView
{
    int a;
    int b;
    int c;
    int d;
    IteratorView();
    ~IteratorView();
};
struct ReplyView
{
    int type;
    int ptr;
    ReplyView(int, int*);
    ~ReplyView();
};
struct QueueTarget
{
    virtual void Destroy();
    virtual bool Push(const ReplyView&);
};
struct QueueView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool Pop(MessageView&);
    virtual void Remove(QueueTarget*);
};
struct TimerView
{
    int a;
};
struct LockView
{
    int a;
};
extern const char taskName[];
void EnterTasks(void*);
// Existing pack declaration supplies the exit helper.
struct DrainManager
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
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
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    int unk610;
    int unk614;
    int unk618;
    int unk61c;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    int unk8bc;
    int unk8c0;
    int unk8c4;
    int unk8c8;
    int unk8cc;
    int unk8d0;
    int unk8d4;
    int unk8d8;
    int unk8dc;
    int unk8e0;
    int unk8e4;
    int unk8e8;
    int unk8ec;
    int unk8f0;
    int unk8f4;
    int unk8f8;
    int unk8fc;
    int unk900;
    int unk904;
    int unk908;
    int unk90c;
    int unk910;
    int unk914;
    int unk918;
    int unk91c;
    int unk920;
    int unk924;
    int unk928;
    int unk92c;
    int unk930;
    int unk934;
    int unk938;
    int unk93c;
    int unk940;
    int unk944;
    int unk948;
    int unk94c;
    int unk950;
    int unk954;
    int unk958;
    int unk95c;
    int unk960;
    int unk964;
    int unk968;
    int unk96c;
    int unk970;
    int unk974;
    int unk978;
    int unk97c;
    int unk980;
    int unk984;
    int unk988;
    int unk98c;
    int unk990;
    int unk994;
    int unk998;
    int unk99c;
    int unk9a0;
    int unk9a4;
    int unk9a8;
    int unk9ac;
    int unk9b0;
    int unk9b4;
    int unk9b8;
    int unk9bc;
    int unk9c0;
    int unk9c4;
    int unk9c8;
    int unk9cc;
    int unk9d0;
    int unk9d4;
    int unk9d8;
    int unk9dc;
    int unk9e0;
    int unk9e4;
    int unk9e8;
    int unk9ec;
    int unk9f0;
    int unk9f4;
    int unk9f8;
    int unk9fc;
    int unka00;
    int unka04;
    int unka08;
    int unka0c;
    int unka10;
    int unka14;
    int unka18;
    int unka1c;
    int unka20;
    int unka24;
    int unka28;
    int unka2c;
    int unka30;
    int unka34;
    int unka38;
    int unka3c;
    int unka40;
    int unka44;
    int unka48;
    int unka4c;
    int unka50;
    int unka54;
    int unka58;
    int unka5c;
    int unka60;
    int unka64;
    int unka68;
    int unka6c;
    int unka70;
    int unka74;
    int unka78;
    int unka7c;
    int unka80;
    int unka84;
    int unka88;
    int unka8c;
    int unka90;
    int unka94;
    int unka98;
    int unka9c;
    int unkaa0;
    int unkaa4;
    int unkaa8;
    int unkaac;
    int unkab0;
    int unkab4;
    int unkab8;
    int unkabc;
    int unkac0;
    int unkac4;
    int unkac8;
    int unkacc;
    int unkad0;
    int unkad4;
    int unkad8;
    int unkadc;
    int unkae0;
    int unkae4;
    int unkae8;
    int unkaec;
    int unkaf0;
    int unkaf4;
    int unkaf8;
    int unkafc;
    int unkb00;
    int unkb04;
    int unkb08;
    int unkb0c;
    int unkb10;
    int unkb14;
    int unkb18;
    int unkb1c;
    int unkb20;
    int unkb24;
    int unkb28;
    int unkb2c;
    int unkb30;
    int unkb34;
    int unkb38;
    int unkb3c;
    int unkb40;
    int unkb44;
    int unkb48;
    int unkb4c;
    int unkb50;
    int unkb54;
    int unkb58;
    int unkb5c;
    int unkb60;
    int unkb64;
    int unkb68;
    int unkb6c;
    int unkb70;
    int unkb74;
    int unkb78;
    int unkb7c;
    int unkb80;
    int unkb84;
    int unkb88;
    int unkb8c;
    int unkb90;
    int unkb94;
    int unkb98;
    int unkb9c;
    int unkba0;
    int unkba4;
    int unkba8;
    int unkbac;
    int unkbb0;
    int unkbb4;
    int unkbb8;
    int unkbbc;
    int unkbc0;
    int unkbc4;
    int unkbc8;
    int unkbcc;
    int unkbd0;
    int unkbd4;
    int unkbd8;
    int unkbdc;
    int unkbe0;
    int unkbe4;
    int unkbe8;
    int unkbec;
    int unkbf0;
    int unkbf4;
    int unkbf8;
    int unkbfc;
    int unkc00;
    int unkc04;
    int unkc08;
    int unkc0c;
    QueueView incoming;
    int unkc14;
    int unkc18;
    int unkc1c;
    int unkc20;
    int state;
    int unkc28;
    LockView lock;
    int unkc30;
    bool active;
    TimerView timer;
    int unkc3c;
    int unkc40;
    int unkc44;
    int unkc48;
    int unkc4c;
    int unkc50;
    int unkc54;
    int unkc58;
    int unkc5c;
    int unkc60;
    int unkc64;
    int unkc68;
    int unkc6c;
    int unkc70;
    int unkc74;
    int unkc78;
    int unkc7c;
    int unkc80;
    int unkc84;
    int unkc88;
    int unkc8c;
    int unkc90;
    int unkc94;
    int unkc98;
    int unkc9c;
    int unkca0;
    int unkca4;
    int unkca8;
    int unkcac;
    int unkcb0;
    int unkcb4;
    int unkcb8;
    int unkcbc;
    int unkcc0;
    int unkcc4;
    int unkcc8;
    int unkccc;
    int unkcd0;
    int unkcd4;
    int unkcd8;
    int unkcdc;
    int unkce0;
    int unkce4;
    int unkce8;
    int unkcec;
    int unkcf0;
    int unkcf4;
    int unkcf8;
    int unkcfc;
    int unkd00;
    int unkd04;
    int unkd08;
    int unkd0c;
    int unkd10;
    int unkd14;
    int unkd18;
    int unkd1c;
    int unkd20;
    int unkd24;
    int unkd28;
    int unkd2c;
    int unkd30;
    int unkd34;
    int unkd38;
    int unkd3c;
    int unkd40;
    int unkd44;
    int unkd48;
    int unkd4c;
    int unkd50;
    int unkd54;
    int unkd58;
    int unkd5c;
    int unkd60;
    int unkd64;
    int unkd68;
    int unkd6c;
    int unkd70;
    int unkd74;
    int unkd78;
    int unkd7c;
    int unkd80;
    int unkd84;
    int unkd88;
    int unkd8c;
    int unkd90;
    int unkd94;
    int unkd98;
    int unkd9c;
    int unkda0;
    int unkda4;
    int unkda8;
    int unkdac;
    int unkdb0;
    int unkdb4;
    int unkdb8;
    int unkdbc;
    int unkdc0;
    int unkdc4;
    int unkdc8;
    int unkdcc;
    int unkdd0;
    int unkdd4;
    int unkdd8;
    int unkddc;
    int unkde0;
    int unkde4;
    int unkde8;
    int unkdec;
    int unkdf0;
    int unkdf4;
    int unkdf8;
    int unkdfc;
    int unke00;
    int unke04;
    int unke08;
    int unke0c;
    int unke10;
    int unke14;
    int unke18;
    int unke1c;
    int unke20;
    int unke24;
    int unke28;
    int unke2c;
    int unke30;
    int unke34;
    int unke38;
    int unke3c;
    int unke40;
    int unke44;
    int unke48;
    int unke4c;
    int unke50;
    int unke54;
    int unke58;
    int unke5c;
    int unke60;
    int unke64;
    int unke68;
    int unke6c;
    int unke70;
    int unke74;
    int unke78;
    int unke7c;
    int unke80;
    int unke84;
    int unke88;
    int unke8c;
    int unke90;
    int unke94;
    int unke98;
    int unke9c;
    int unkea0;
    int unkea4;
    int unkea8;
    int unkeac;
    int unkeb0;
    int unkeb4;
    int unkeb8;
    int unkebc;
    int unkec0;
    int unkec4;
    int unkec8;
    int unkecc;
    int unked0;
    int unked4;
    int unked8;
    int unkedc;
    int unkee0;
    int unkee4;
    int unkee8;
    int unkeec;
    int unkef0;
    int unkef4;
    int unkef8;
    int unkefc;
    int unkf00;
    int unkf04;
    int unkf08;
    int unkf0c;
    int unkf10;
    int unkf14;
    int unkf18;
    int unkf1c;
    int unkf20;
    int unkf24;
    int unkf28;
    int unkf2c;
    int unkf30;
    int unkf34;
    int unkf38;
    int unkf3c;
    int unkf40;
    int unkf44;
    int unkf48;
    int unkf4c;
    int unkf50;
    int unkf54;
    int unkf58;
    int unkf5c;
    int unkf60;
    int unkf64;
    int unkf68;
    int unkf6c;
    int unkf70;
    int unkf74;
    int unkf78;
    int unkf7c;
    int unkf80;
    int unkf84;
    int unkf88;
    int unkf8c;
    int unkf90;
    int unkf94;
    int unkf98;
    int unkf9c;
    int unkfa0;
    int unkfa4;
    int unkfa8;
    int unkfac;
    int unkfb0;
    int unkfb4;
    int unkfb8;
    int unkfbc;
    int unkfc0;
    int unkfc4;
    int unkfc8;
    int unkfcc;
    int unkfd0;
    int unkfd4;
    int unkfd8;
    int unkfdc;
    int unkfe0;
    int unkfe4;
    int unkfe8;
    int unkfec;
    int unkff0;
    int unkff4;
    int unkff8;
    int unkffc;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100c;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101c;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102c;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103c;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104c;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105c;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106c;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107c;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108c;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109c;
    int unk10a0;
    int unk10a4;
    int unk10a8;
    int unk10ac;
    int unk10b0;
    int unk10b4;
    int unk10b8;
    int unk10bc;
    int unk10c0;
    int unk10c4;
    int unk10c8;
    int unk10cc;
    int unk10d0;
    int unk10d4;
    int unk10d8;
    int unk10dc;
    int unk10e0;
    int unk10e4;
    int unk10e8;
    int unk10ec;
    int unk10f0;
    int unk10f4;
    int unk10f8;
    int unk10fc;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110c;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111c;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112c;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113c;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114c;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115c;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116c;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117c;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118c;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119c;
    int unk11a0;
    int unk11a4;
    int unk11a8;
    int unk11ac;
    int unk11b0;
    int unk11b4;
    int unk11b8;
    int unk11bc;
    int unk11c0;
    int unk11c4;
    int unk11c8;
    int unk11cc;
    int unk11d0;
    int unk11d4;
    int unk11d8;
    int unk11dc;
    int unk11e0;
    int unk11e4;
    int unk11e8;
    int unk11ec;
    int unk11f0;
    int unk11f4;
    int unk11f8;
    int unk11fc;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120c;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121c;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122c;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123c;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124c;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125c;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126c;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127c;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128c;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129c;
    int unk12a0;
    int unk12a4;
    int unk12a8;
    int unk12ac;
    int unk12b0;
    int unk12b4;
    int unk12b8;
    int unk12bc;
    int unk12c0;
    int unk12c4;
    int unk12c8;
    int unk12cc;
    int unk12d0;
    int unk12d4;
    int unk12d8;
    int unk12dc;
    int unk12e0;
    int unk12e4;
    int unk12e8;
    int unk12ec;
    int unk12f0;
    int unk12f4;
    int unk12f8;
    int unk12fc;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130c;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131c;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132c;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133c;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134c;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135c;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136c;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137c;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138c;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139c;
    int unk13a0;
    int unk13a4;
    int unk13a8;
    int unk13ac;
    int unk13b0;
    int unk13b4;
    int unk13b8;
    int unk13bc;
    int unk13c0;
    int unk13c4;
    int unk13c8;
    int unk13cc;
    int unk13d0;
    int unk13d4;
    int unk13d8;
    int unk13dc;
    int unk13e0;
    int unk13e4;
    int unk13e8;
    int unk13ec;
    int unk13f0;
    int unk13f4;
    int unk13f8;
    int unk13fc;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140c;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141c;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142c;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143c;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144c;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145c;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146c;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147c;
    QueueView outgoing;
    void Drain();
};
// @fnv 0x006ebcf0
void FUN_006ebcf0_cls::CallInner()
{
    reinterpret_cast<::DrainManager *>((m0))->Drain();
}
// Starts the timer, enters tasks, drains incoming messages, replies to outgoing tasks, clears the queue, releases the lock and resets state.
// @fnv 0x006eb440
void DrainManager::Drain()
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&(timer))->FUN_004538a0((std::intptr_t)(taskName));
    EnterTasks(this);
    active = true;
    ((FUN_006eb670_Holder*)this)->FUN_006eb670(false);
    MessageView message;
    while (incoming.Pop(message))
    {
        switch (message.type)
        {
        case 0:
        case 1:
            outgoing.Remove(((::QueueTarget *)(::FUN_00559450((int *)&(message.task->request)))));
            delete message.task;
            break;
        }
    }
    IteratorView iter;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(iter))->FUN_006ebde0())
    {
        int key;
        TaskView* pTask;
        if (reinterpret_cast<::Queue44c640 *>(&(outgoing))->TryGetNextEntry((::QueueIter44c640 *)&(iter), (void **)(int *)(&key), (std::intptr_t)(&pTask), true))
        {
            ((::QueueTarget *)(::FUN_00559450((int *)&(pTask->queue))))->Push(ReplyView(1, &pTask->solution));
            delete pTask;
        }
    }
    reinterpret_cast<::TSHashTable *>(&(outgoing))->FUN_0044c480(0);
    ::fnv_00aa6060::AcquireLock((::ReadWriteLock *)&(lock));
    state = 2;
    active = false;
    FUN_006c08e0(this);
    reinterpret_cast<::ActorTaskManager *>(&(timer))->WaitForTasksDuringRendering();
}

// Destructor: pop and discard every queued item before the base queue is destroyed.

class F55C0Item
{
  public:
    F55C0Item();
    ~F55C0Item();

    int unk00;
    int unk04;
};

class F55C0Queue
{
  public:
    virtual ~F55C0Queue();
    bool Pop(F55C0Item& rkItem);
};

class FUN_009055c0 : public F55C0Queue
{
  public:
    virtual ~FUN_009055c0();
};

// Destructor that repeatedly pops items from the queue until Pop returns false.
// @fnv 0x009055c0
FUN_009055c0::~FUN_009055c0()
{
    F55C0Item kItem;
    while (reinterpret_cast<::FUN_006ec390_Class *>(this)->FUN_006ec390((std::intptr_t)&(kItem)))
    {
    }
}

struct PathTaskBase
{
    virtual ~PathTaskBase();
    int unk04, unk08, unk0c, unk10, unk14;
    PathTaskBase();
};
struct PathObjectPtr
{
    void* object;
    PathObjectPtr(int);
    ~PathObjectPtr();
};
struct PathState
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    PathState();
};
struct PathListA
{
    int unk00, unk04, unk08, unk0c;
    PathListA();
    ~PathListA();
};
struct PathListB
{
    int unk00, unk04, unk08, unk0c;
    PathListB();
    ~PathListB();
};
struct PathHandle
{
    void* object;
    PathHandle(int);
    PathHandle(const PathHandle&);
    ~PathHandle();
};
struct FUN_006e9cc0 : PathTaskBase
{
    PathObjectPtr first, second;
    PathState state;
    PathListA listA;
    PathListB listB;
    PathHandle handle;
    bool enabled;
    FUN_006e9cc0(std::intptr_t, PathHandle);
    virtual ~FUN_006e9cc0();
};
// Constructs a path task, default-initializes its members, then calls Initialize with the given mode and handle.
// @fnv 0x006e9cc0
FUN_006e9cc0::FUN_006e9cc0(std::intptr_t mode, PathHandle value) : first(0), second(0), handle(0), enabled(false)
{
    reinterpret_cast<::PathingTaskShell *>(this)->AssignRequestAndQueue((::PathingRequest *)(mode), (*(::NiPointer< ::ActorPathingMessageQueue> *)&(const ::PathHandle &)(value)));
}

class BSSpinLock_r006eb6b0
{
  public:
};

class PathingActorData;

struct PathSlot
{
    int unk00;
    int unk04;
};

struct PathingRequest
{
};

struct PathWorkList
{
    int unk00[4];
    PathWorkList();
    ~PathWorkList();
};

struct PathIndex
{
};

struct FUN_006eb6b0_cls_ctxr2 : public PathManagerImpl
{
    void FUN_006eb6b0(int id);
};

// @fnv 0x006eb6b0
void FUN_006eb6b0_cls_ctxr2::FUN_006eb6b0(int id)
{
    reinterpret_cast<::GlobalObject_0044fae0 *>((reinterpret_cast<BSSpinLock_r006eb6b0*>(reinterpret_cast<char*>(this) + 0xc38)))->FUN_004538a0((std::intptr_t)("PathManagerImpl::CancelCurrentPathsAndPause"));
    PathingRequest* ref;
    int outA2;
    PathWorkList list3;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(list3))->FUN_006ebde0())
    {
        if (reinterpret_cast<::Queue44c640 *>((reinterpret_cast<PathIndex*>(reinterpret_cast<char*>(this) + 0x1480)))->TryGetNextEntry((::QueueIter44c640 *)(::PathWorkList *)(&list3), (void **)(::PathingRequest **)(&ref), (std::intptr_t)(&outA2), true))
        {
            if (reinterpret_cast<PathSlot*>(reinterpret_cast<::FUN_006c9900_shell *>((ref))->FUN_006c9900())->unk04 == id)
            {
                reinterpret_cast<PathSlot*>(reinterpret_cast<::FUN_006c9900_shell *>((ref))->FUN_006c9900())->unk04 = 0;
                reinterpret_cast<PathSlot*>(reinterpret_cast<::FUN_006c9900_shell *>((ref))->FUN_006c9900())->unk00 = 0;
            }
        }
    }
    reinterpret_cast<::ActorTaskManager *>((reinterpret_cast<BSSpinLock_r006eb6b0*>(reinterpret_cast<char*>(this) + 0xc38)))->WaitForTasksDuringRendering();
}

class BSSpinLock_r006eae40
{
  public:
};

namespace fnv_006eae40 {
// Stand-in declarations for FUN_006eae40

struct ObjA
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    ObjA();
    ~ObjA();
};

struct PathingTaskData_Ext : public PathingTaskData
{
};

struct ObjC
{
    void* vtable;
    int unk04;
    ObjC();
    ~ObjC();
};

struct Item_006eae40
{
    int m_val;
    void* m_ptr;
    Item_006eae40();
    ~Item_006eae40();
};

struct SubC2C
{
    int unk0;
    int unk4;
    int unk8;
};

struct NameGetter
{
};

struct VObj
{
    virtual ~VObj();
};

struct CollBase
{
    virtual ~CollBase();
    virtual void FillA();
    virtual void FillB();
    virtual void FillC();
    virtual bool ContainsItem(void* pItem);
};

struct Coll1480 : public CollBase
{
    virtual void Notify(void* p);
};

struct TaskQueueInterface
{
};

struct GlobalTargetObj
{
    virtual void Fill00();
    virtual void Fill01();
    virtual void Fill02();
    virtual void Fill03();
    virtual void Fill04();
    virtual void Fill05();
    virtual void Fill06();
    virtual void Fill07();
    virtual void Fill08();
    virtual void Fill09();
    virtual void Fill10();
    virtual void Fill11();
    virtual void Fill12();
    virtual void Fill13();
    virtual void Fill14();
    virtual void Fill15();
    virtual void Fill16();
    virtual void Fill17();
    virtual void Fill18();
    virtual void Fill19();
    virtual void Fill20();
    virtual void Fill21();
    virtual void Fill22();
    virtual void Fill23();
    virtual void Fill24();
    virtual void Fill25();
    virtual void Fill26();
    virtual void Fill27();
    virtual void Fill28();
    virtual void Fill29();
    virtual void Fill30();
    virtual void Fill31();
    virtual void Fill32();
    virtual void Fill33();
    virtual void Fill34();
    virtual void Fill35();
    virtual void Fill36();
    virtual void Fill37();
    virtual void Fill38();
    virtual void Fill39();
    virtual void Fill40();
    virtual void Fill41();
    virtual void Fill42();
    virtual void Fill43();
    virtual void Fill44();
    virtual void Fill45();
    virtual void Fill46();
    virtual void Fill47();
    virtual void Fill48();
    virtual void Fill49();
    virtual void Fill50();
    virtual void Fill51();
    virtual void Fill52();
    virtual void Fill53();
    virtual void Fill54();
    virtual void NotifyDC(void* p, int a);
    virtual void Fill56();
    virtual void Fill57();
    virtual void NotifyE8(void* p);
};

class NiNode;
class GlobalObject_00633c90
{
  public:
    GlobalTargetObj* operator->() const;
    operator void*() const;
    operator NiNode*() const;
};


struct NiUpdateData
{
    float m_uiCommandId;
    bool m_kPointA;
    bool m_kPointB;
    short m_iThirdValue;
    int m_iFourthElementInteger;
    NiUpdateData(float f, bool a, bool b);
};

class NiNode
{
  public:
};
}  // namespace fnv_006eae40

template <> class NiPointer<fnv_006eae40::NiNode>
{
  public:
    fnv_006eae40::NiNode* m_pObject;
    NiPointer(fnv_006eae40::NiNode* p = 0);
    ~NiPointer();
    operator fnv_006eae40::NiNode*() const;
};

namespace fnv_006eae40 {

struct FUN_006eae40_shell
{
    int unk_0000;
    int unk_0004;
    int unk_0008;
    int unk_000c;
    int unk_0010;
    int unk_0014;
    int unk_0018;
    int unk_001c;
    int unk_0020;
    int unk_0024;
    int unk_0028;
    int unk_002c;
    int unk_0030;
    int unk_0034;
    int unk_0038;
    int unk_003c;
    int unk_0040;
    int unk_0044;
    int unk_0048;
    int unk_004c;
    int unk_0050;
    int unk_0054;
    int unk_0058;
    int unk_005c;
    int unk_0060;
    int unk_0064;
    int unk_0068;
    int unk_006c;
    int unk_0070;
    int unk_0074;
    int unk_0078;
    int unk_007c;
    int unk_0080;
    int unk_0084;
    int unk_0088;
    int unk_008c;
    int unk_0090;
    int unk_0094;
    int unk_0098;
    int unk_009c;
    int unk_00a0;
    int unk_00a4;
    int unk_00a8;
    int unk_00ac;
    int unk_00b0;
    int unk_00b4;
    int unk_00b8;
    int unk_00bc;
    int unk_00c0;
    int unk_00c4;
    int unk_00c8;
    int unk_00cc;
    int unk_00d0;
    int unk_00d4;
    int unk_00d8;
    int unk_00dc;
    int unk_00e0;
    int unk_00e4;
    int unk_00e8;
    int unk_00ec;
    int unk_00f0;
    int unk_00f4;
    int unk_00f8;
    int unk_00fc;
    int unk_0100;
    int unk_0104;
    int unk_0108;
    int unk_010c;
    int unk_0110;
    int unk_0114;
    int unk_0118;
    int unk_011c;
    int unk_0120;
    int unk_0124;
    int unk_0128;
    int unk_012c;
    int unk_0130;
    int unk_0134;
    int unk_0138;
    int unk_013c;
    int unk_0140;
    int unk_0144;
    int unk_0148;
    int unk_014c;
    int unk_0150;
    int unk_0154;
    int unk_0158;
    int unk_015c;
    int unk_0160;
    int unk_0164;
    int unk_0168;
    int unk_016c;
    int unk_0170;
    int unk_0174;
    int unk_0178;
    int unk_017c;
    int unk_0180;
    int unk_0184;
    int unk_0188;
    int unk_018c;
    int unk_0190;
    int unk_0194;
    int unk_0198;
    int unk_019c;
    int unk_01a0;
    int unk_01a4;
    int unk_01a8;
    int unk_01ac;
    int unk_01b0;
    int unk_01b4;
    int unk_01b8;
    int unk_01bc;
    int unk_01c0;
    int unk_01c4;
    int unk_01c8;
    int unk_01cc;
    int unk_01d0;
    int unk_01d4;
    int unk_01d8;
    int unk_01dc;
    int unk_01e0;
    int unk_01e4;
    int unk_01e8;
    int unk_01ec;
    int unk_01f0;
    int unk_01f4;
    int unk_01f8;
    int unk_01fc;
    int unk_0200;
    int unk_0204;
    int unk_0208;
    int unk_020c;
    int unk_0210;
    int unk_0214;
    int unk_0218;
    int unk_021c;
    int unk_0220;
    int unk_0224;
    int unk_0228;
    int unk_022c;
    int unk_0230;
    int unk_0234;
    int unk_0238;
    int unk_023c;
    int unk_0240;
    int unk_0244;
    int unk_0248;
    int unk_024c;
    int unk_0250;
    int unk_0254;
    int unk_0258;
    int unk_025c;
    int unk_0260;
    int unk_0264;
    int unk_0268;
    int unk_026c;
    int unk_0270;
    int unk_0274;
    int unk_0278;
    int unk_027c;
    int unk_0280;
    int unk_0284;
    int unk_0288;
    int unk_028c;
    int unk_0290;
    int unk_0294;
    int unk_0298;
    int unk_029c;
    int unk_02a0;
    int unk_02a4;
    int unk_02a8;
    int unk_02ac;
    int unk_02b0;
    int unk_02b4;
    int unk_02b8;
    int unk_02bc;
    int unk_02c0;
    int unk_02c4;
    int unk_02c8;
    int unk_02cc;
    int unk_02d0;
    int unk_02d4;
    int unk_02d8;
    int unk_02dc;
    int unk_02e0;
    int unk_02e4;
    int unk_02e8;
    int unk_02ec;
    int unk_02f0;
    int unk_02f4;
    int unk_02f8;
    int unk_02fc;
    int unk_0300;
    int unk_0304;
    int unk_0308;
    int unk_030c;
    int unk_0310;
    int unk_0314;
    int unk_0318;
    int unk_031c;
    int unk_0320;
    int unk_0324;
    int unk_0328;
    int unk_032c;
    int unk_0330;
    int unk_0334;
    int unk_0338;
    int unk_033c;
    int unk_0340;
    int unk_0344;
    int unk_0348;
    int unk_034c;
    int unk_0350;
    int unk_0354;
    int unk_0358;
    int unk_035c;
    int unk_0360;
    int unk_0364;
    int unk_0368;
    int unk_036c;
    int unk_0370;
    int unk_0374;
    int unk_0378;
    int unk_037c;
    int unk_0380;
    int unk_0384;
    int unk_0388;
    int unk_038c;
    int unk_0390;
    int unk_0394;
    int unk_0398;
    int unk_039c;
    int unk_03a0;
    int unk_03a4;
    int unk_03a8;
    int unk_03ac;
    int unk_03b0;
    int unk_03b4;
    int unk_03b8;
    int unk_03bc;
    int unk_03c0;
    int unk_03c4;
    int unk_03c8;
    int unk_03cc;
    int unk_03d0;
    int unk_03d4;
    int unk_03d8;
    int unk_03dc;
    int unk_03e0;
    int unk_03e4;
    int unk_03e8;
    int unk_03ec;
    int unk_03f0;
    int unk_03f4;
    int unk_03f8;
    int unk_03fc;
    int unk_0400;
    int unk_0404;
    int unk_0408;
    int unk_040c;
    int unk_0410;
    int unk_0414;
    int unk_0418;
    int unk_041c;
    int unk_0420;
    int unk_0424;
    int unk_0428;
    int unk_042c;
    int unk_0430;
    int unk_0434;
    int unk_0438;
    int unk_043c;
    int unk_0440;
    int unk_0444;
    int unk_0448;
    int unk_044c;
    int unk_0450;
    int unk_0454;
    int unk_0458;
    int unk_045c;
    int unk_0460;
    int unk_0464;
    int unk_0468;
    int unk_046c;
    int unk_0470;
    int unk_0474;
    int unk_0478;
    int unk_047c;
    int unk_0480;
    int unk_0484;
    int unk_0488;
    int unk_048c;
    int unk_0490;
    int unk_0494;
    int unk_0498;
    int unk_049c;
    int unk_04a0;
    int unk_04a4;
    int unk_04a8;
    int unk_04ac;
    int unk_04b0;
    int unk_04b4;
    int unk_04b8;
    int unk_04bc;
    int unk_04c0;
    int unk_04c4;
    int unk_04c8;
    int unk_04cc;
    int unk_04d0;
    int unk_04d4;
    int unk_04d8;
    int unk_04dc;
    int unk_04e0;
    int unk_04e4;
    int unk_04e8;
    int unk_04ec;
    int unk_04f0;
    int unk_04f4;
    int unk_04f8;
    int unk_04fc;
    int unk_0500;
    int unk_0504;
    int unk_0508;
    int unk_050c;
    int unk_0510;
    int unk_0514;
    int unk_0518;
    int unk_051c;
    int unk_0520;
    int unk_0524;
    int unk_0528;
    int unk_052c;
    int unk_0530;
    int unk_0534;
    int unk_0538;
    int unk_053c;
    int unk_0540;
    int unk_0544;
    int unk_0548;
    int unk_054c;
    int unk_0550;
    int unk_0554;
    int unk_0558;
    int unk_055c;
    int unk_0560;
    int unk_0564;
    int unk_0568;
    int unk_056c;
    int unk_0570;
    int unk_0574;
    int unk_0578;
    int unk_057c;
    int unk_0580;
    int unk_0584;
    int unk_0588;
    int unk_058c;
    int unk_0590;
    int unk_0594;
    int unk_0598;
    int unk_059c;
    int unk_05a0;
    int unk_05a4;
    int unk_05a8;
    int unk_05ac;
    int unk_05b0;
    int unk_05b4;
    int unk_05b8;
    int unk_05bc;
    int unk_05c0;
    int unk_05c4;
    int unk_05c8;
    int unk_05cc;
    int unk_05d0;
    int unk_05d4;
    int unk_05d8;
    int unk_05dc;
    int unk_05e0;
    int unk_05e4;
    int unk_05e8;
    int unk_05ec;
    int unk_05f0;
    int unk_05f4;
    int unk_05f8;
    int unk_05fc;
    int unk_0600;
    int unk_0604;
    int unk_0608;
    int unk_060c;
    int unk_0610;
    int unk_0614;
    int unk_0618;
    int unk_061c;
    int unk_0620;
    int unk_0624;
    int unk_0628;
    int unk_062c;
    int unk_0630;
    int unk_0634;
    int unk_0638;
    int unk_063c;
    int unk_0640;
    int unk_0644;
    int unk_0648;
    int unk_064c;
    int unk_0650;
    int unk_0654;
    int unk_0658;
    int unk_065c;
    int unk_0660;
    int unk_0664;
    int unk_0668;
    int unk_066c;
    int unk_0670;
    int unk_0674;
    int unk_0678;
    int unk_067c;
    int unk_0680;
    int unk_0684;
    int unk_0688;
    int unk_068c;
    int unk_0690;
    int unk_0694;
    int unk_0698;
    int unk_069c;
    int unk_06a0;
    int unk_06a4;
    int unk_06a8;
    int unk_06ac;
    int unk_06b0;
    int unk_06b4;
    int unk_06b8;
    int unk_06bc;
    int unk_06c0;
    int unk_06c4;
    int unk_06c8;
    int unk_06cc;
    int unk_06d0;
    int unk_06d4;
    int unk_06d8;
    int unk_06dc;
    int unk_06e0;
    int unk_06e4;
    int unk_06e8;
    int unk_06ec;
    int unk_06f0;
    int unk_06f4;
    int unk_06f8;
    int unk_06fc;
    int unk_0700;
    int unk_0704;
    int unk_0708;
    int unk_070c;
    int unk_0710;
    int unk_0714;
    int unk_0718;
    int unk_071c;
    int unk_0720;
    int unk_0724;
    int unk_0728;
    int unk_072c;
    int unk_0730;
    int unk_0734;
    int unk_0738;
    int unk_073c;
    int unk_0740;
    int unk_0744;
    int unk_0748;
    int unk_074c;
    int unk_0750;
    int unk_0754;
    int unk_0758;
    int unk_075c;
    int unk_0760;
    int unk_0764;
    int unk_0768;
    int unk_076c;
    int unk_0770;
    int unk_0774;
    int unk_0778;
    int unk_077c;
    int unk_0780;
    int unk_0784;
    int unk_0788;
    int unk_078c;
    int unk_0790;
    int unk_0794;
    int unk_0798;
    int unk_079c;
    int unk_07a0;
    int unk_07a4;
    int unk_07a8;
    int unk_07ac;
    int unk_07b0;
    int unk_07b4;
    int unk_07b8;
    int unk_07bc;
    int unk_07c0;
    int unk_07c4;
    int unk_07c8;
    int unk_07cc;
    int unk_07d0;
    int unk_07d4;
    int unk_07d8;
    int unk_07dc;
    int unk_07e0;
    int unk_07e4;
    int unk_07e8;
    int unk_07ec;
    int unk_07f0;
    int unk_07f4;
    int unk_07f8;
    int unk_07fc;
    int unk_0800;
    int unk_0804;
    int unk_0808;
    int unk_080c;
    int unk_0810;
    int unk_0814;
    int unk_0818;
    int unk_081c;
    int unk_0820;
    int unk_0824;
    int unk_0828;
    int unk_082c;
    int unk_0830;
    int unk_0834;
    int unk_0838;
    int unk_083c;
    int unk_0840;
    int unk_0844;
    int unk_0848;
    int unk_084c;
    int unk_0850;
    int unk_0854;
    int unk_0858;
    int unk_085c;
    int unk_0860;
    int unk_0864;
    int unk_0868;
    int unk_086c;
    int unk_0870;
    int unk_0874;
    int unk_0878;
    int unk_087c;
    int unk_0880;
    int unk_0884;
    int unk_0888;
    int unk_088c;
    int unk_0890;
    int unk_0894;
    int unk_0898;
    int unk_089c;
    int unk_08a0;
    int unk_08a4;
    int unk_08a8;
    int unk_08ac;
    int unk_08b0;
    int unk_08b4;
    int unk_08b8;
    int unk_08bc;
    int unk_08c0;
    int unk_08c4;
    int unk_08c8;
    int unk_08cc;
    int unk_08d0;
    int unk_08d4;
    int unk_08d8;
    int unk_08dc;
    int unk_08e0;
    int unk_08e4;
    int unk_08e8;
    int unk_08ec;
    int unk_08f0;
    int unk_08f4;
    int unk_08f8;
    int unk_08fc;
    int unk_0900;
    int unk_0904;
    int unk_0908;
    int unk_090c;
    int unk_0910;
    int unk_0914;
    int unk_0918;
    int unk_091c;
    int unk_0920;
    int unk_0924;
    int unk_0928;
    int unk_092c;
    int unk_0930;
    int unk_0934;
    int unk_0938;
    int unk_093c;
    int unk_0940;
    int unk_0944;
    int unk_0948;
    int unk_094c;
    int unk_0950;
    int unk_0954;
    int unk_0958;
    int unk_095c;
    int unk_0960;
    int unk_0964;
    int unk_0968;
    int unk_096c;
    int unk_0970;
    int unk_0974;
    int unk_0978;
    int unk_097c;
    int unk_0980;
    int unk_0984;
    int unk_0988;
    int unk_098c;
    int unk_0990;
    int unk_0994;
    int unk_0998;
    int unk_099c;
    int unk_09a0;
    int unk_09a4;
    int unk_09a8;
    int unk_09ac;
    int unk_09b0;
    int unk_09b4;
    int unk_09b8;
    int unk_09bc;
    int unk_09c0;
    int unk_09c4;
    int unk_09c8;
    int unk_09cc;
    int unk_09d0;
    int unk_09d4;
    int unk_09d8;
    int unk_09dc;
    int unk_09e0;
    int unk_09e4;
    int unk_09e8;
    int unk_09ec;
    int unk_09f0;
    int unk_09f4;
    int unk_09f8;
    int unk_09fc;
    int unk_0a00;
    int unk_0a04;
    int unk_0a08;
    int unk_0a0c;
    int unk_0a10;
    int unk_0a14;
    int unk_0a18;
    int unk_0a1c;
    int unk_0a20;
    int unk_0a24;
    int unk_0a28;
    int unk_0a2c;
    int unk_0a30;
    int unk_0a34;
    int unk_0a38;
    int unk_0a3c;
    int unk_0a40;
    int unk_0a44;
    int unk_0a48;
    int unk_0a4c;
    int unk_0a50;
    int unk_0a54;
    int unk_0a58;
    int unk_0a5c;
    int unk_0a60;
    int unk_0a64;
    int unk_0a68;
    int unk_0a6c;
    int unk_0a70;
    int unk_0a74;
    int unk_0a78;
    int unk_0a7c;
    int unk_0a80;
    int unk_0a84;
    int unk_0a88;
    int unk_0a8c;
    int unk_0a90;
    int unk_0a94;
    int unk_0a98;
    int unk_0a9c;
    int unk_0aa0;
    int unk_0aa4;
    int unk_0aa8;
    int unk_0aac;
    int unk_0ab0;
    int unk_0ab4;
    int unk_0ab8;
    int unk_0abc;
    int unk_0ac0;
    int unk_0ac4;
    int unk_0ac8;
    int unk_0acc;
    int unk_0ad0;
    int unk_0ad4;
    int unk_0ad8;
    int unk_0adc;
    int unk_0ae0;
    int unk_0ae4;
    int unk_0ae8;
    int unk_0aec;
    int unk_0af0;
    int unk_0af4;
    int unk_0af8;
    int unk_0afc;
    int unk_0b00;
    int unk_0b04;
    int unk_0b08;
    int unk_0b0c;
    int unk_0b10;
    int unk_0b14;
    int unk_0b18;
    int unk_0b1c;
    int unk_0b20;
    int unk_0b24;
    int unk_0b28;
    int unk_0b2c;
    int unk_0b30;
    int unk_0b34;
    int unk_0b38;
    int unk_0b3c;
    int unk_0b40;
    int unk_0b44;
    int unk_0b48;
    int unk_0b4c;
    int unk_0b50;
    int unk_0b54;
    int unk_0b58;
    int unk_0b5c;
    int unk_0b60;
    int unk_0b64;
    int unk_0b68;
    int unk_0b6c;
    int unk_0b70;
    int unk_0b74;
    int unk_0b78;
    int unk_0b7c;
    int unk_0b80;
    int unk_0b84;
    int unk_0b88;
    int unk_0b8c;
    int unk_0b90;
    int unk_0b94;
    int unk_0b98;
    int unk_0b9c;
    int unk_0ba0;
    int unk_0ba4;
    int unk_0ba8;
    int unk_0bac;
    int unk_0bb0;
    int unk_0bb4;
    int unk_0bb8;
    int unk_0bbc;
    int unk_0bc0;
    int unk_0bc4;
    int unk_0bc8;
    int unk_0bcc;
    int unk_0bd0;
    int unk_0bd4;
    int unk_0bd8;
    int unk_0bdc;
    int unk_0be0;
    int unk_0be4;
    int unk_0be8;
    int unk_0bec;
    int unk_0bf0;
    int unk_0bf4;
    int unk_0bf8;
    int unk_0bfc;
    int unk_0c00;
    int unk_0c04;
    int unk_0c08;
    int unk_0c0c;
    CollBase m_collC10;
    int unk_0c14;
    int unk_0c18;
    int unk_0c1c;
    int unk_0c20;
    int m_stateC24;
    int m_countC28;
    SubC2C m_subC2C;
    BSSpinLock_r006eae40 m_lockC38;
    int unk_0c3c;
    int unk_0c40;
    int unk_0c44;
    int unk_0c48;
    int unk_0c4c;
    CollBase m_collC50;
    int unk_0c54;
    int unk_0c58;
    int unk_0c5c;
    int unk_0c60;
    int unk_0c64;
    int unk_0c68;
    int unk_0c6c;
    int unk_0c70;
    int unk_0c74;
    int unk_0c78;
    int unk_0c7c;
    int unk_0c80;
    int unk_0c84;
    int unk_0c88;
    int unk_0c8c;
    int unk_0c90;
    int unk_0c94;
    int unk_0c98;
    int unk_0c9c;
    int unk_0ca0;
    int unk_0ca4;
    int unk_0ca8;
    int unk_0cac;
    int unk_0cb0;
    int unk_0cb4;
    int unk_0cb8;
    int unk_0cbc;
    int unk_0cc0;
    int unk_0cc4;
    int unk_0cc8;
    int unk_0ccc;
    int unk_0cd0;
    int unk_0cd4;
    int unk_0cd8;
    int unk_0cdc;
    int unk_0ce0;
    int unk_0ce4;
    int unk_0ce8;
    int unk_0cec;
    int unk_0cf0;
    int unk_0cf4;
    int unk_0cf8;
    int unk_0cfc;
    int unk_0d00;
    int unk_0d04;
    int unk_0d08;
    int unk_0d0c;
    int unk_0d10;
    int unk_0d14;
    int unk_0d18;
    int unk_0d1c;
    int unk_0d20;
    int unk_0d24;
    int unk_0d28;
    int unk_0d2c;
    int unk_0d30;
    int unk_0d34;
    int unk_0d38;
    int unk_0d3c;
    int unk_0d40;
    int unk_0d44;
    int unk_0d48;
    int unk_0d4c;
    int unk_0d50;
    int unk_0d54;
    int unk_0d58;
    int unk_0d5c;
    int unk_0d60;
    int unk_0d64;
    int unk_0d68;
    int unk_0d6c;
    int unk_0d70;
    int unk_0d74;
    int unk_0d78;
    int unk_0d7c;
    int unk_0d80;
    int unk_0d84;
    int unk_0d88;
    int unk_0d8c;
    int unk_0d90;
    int unk_0d94;
    int unk_0d98;
    int unk_0d9c;
    int unk_0da0;
    int unk_0da4;
    int unk_0da8;
    int unk_0dac;
    int unk_0db0;
    int unk_0db4;
    int unk_0db8;
    int unk_0dbc;
    int unk_0dc0;
    int unk_0dc4;
    int unk_0dc8;
    int unk_0dcc;
    int unk_0dd0;
    int unk_0dd4;
    int unk_0dd8;
    int unk_0ddc;
    int unk_0de0;
    int unk_0de4;
    int unk_0de8;
    int unk_0dec;
    int unk_0df0;
    int unk_0df4;
    int unk_0df8;
    int unk_0dfc;
    int unk_0e00;
    int unk_0e04;
    int unk_0e08;
    int unk_0e0c;
    int unk_0e10;
    int unk_0e14;
    int unk_0e18;
    int unk_0e1c;
    int unk_0e20;
    int unk_0e24;
    int unk_0e28;
    int unk_0e2c;
    int unk_0e30;
    int unk_0e34;
    int unk_0e38;
    int unk_0e3c;
    int unk_0e40;
    int unk_0e44;
    int unk_0e48;
    int unk_0e4c;
    int unk_0e50;
    int unk_0e54;
    int unk_0e58;
    int unk_0e5c;
    int unk_0e60;
    int unk_0e64;
    int unk_0e68;
    int unk_0e6c;
    int unk_0e70;
    int unk_0e74;
    int unk_0e78;
    int unk_0e7c;
    int unk_0e80;
    int unk_0e84;
    int unk_0e88;
    int unk_0e8c;
    int unk_0e90;
    int unk_0e94;
    int unk_0e98;
    int unk_0e9c;
    int unk_0ea0;
    int unk_0ea4;
    int unk_0ea8;
    int unk_0eac;
    int unk_0eb0;
    int unk_0eb4;
    int unk_0eb8;
    int unk_0ebc;
    int unk_0ec0;
    int unk_0ec4;
    int unk_0ec8;
    int unk_0ecc;
    int unk_0ed0;
    int unk_0ed4;
    int unk_0ed8;
    int unk_0edc;
    int unk_0ee0;
    int unk_0ee4;
    int unk_0ee8;
    int unk_0eec;
    int unk_0ef0;
    int unk_0ef4;
    int unk_0ef8;
    int unk_0efc;
    int unk_0f00;
    int unk_0f04;
    int unk_0f08;
    int unk_0f0c;
    int unk_0f10;
    int unk_0f14;
    int unk_0f18;
    int unk_0f1c;
    int unk_0f20;
    int unk_0f24;
    int unk_0f28;
    int unk_0f2c;
    int unk_0f30;
    int unk_0f34;
    int unk_0f38;
    int unk_0f3c;
    int unk_0f40;
    int unk_0f44;
    int unk_0f48;
    int unk_0f4c;
    int unk_0f50;
    int unk_0f54;
    int unk_0f58;
    int unk_0f5c;
    int unk_0f60;
    int unk_0f64;
    int unk_0f68;
    int unk_0f6c;
    int unk_0f70;
    int unk_0f74;
    int unk_0f78;
    int unk_0f7c;
    int unk_0f80;
    int unk_0f84;
    int unk_0f88;
    int unk_0f8c;
    int unk_0f90;
    int unk_0f94;
    int unk_0f98;
    int unk_0f9c;
    int unk_0fa0;
    int unk_0fa4;
    int unk_0fa8;
    int unk_0fac;
    int unk_0fb0;
    int unk_0fb4;
    int unk_0fb8;
    int unk_0fbc;
    int unk_0fc0;
    int unk_0fc4;
    int unk_0fc8;
    int unk_0fcc;
    int unk_0fd0;
    int unk_0fd4;
    int unk_0fd8;
    int unk_0fdc;
    int unk_0fe0;
    int unk_0fe4;
    int unk_0fe8;
    int unk_0fec;
    int unk_0ff0;
    int unk_0ff4;
    int unk_0ff8;
    int unk_0ffc;
    int unk_1000;
    int unk_1004;
    int unk_1008;
    int unk_100c;
    int unk_1010;
    int unk_1014;
    int unk_1018;
    int unk_101c;
    int unk_1020;
    int unk_1024;
    int unk_1028;
    int unk_102c;
    int unk_1030;
    int unk_1034;
    int unk_1038;
    int unk_103c;
    int unk_1040;
    int unk_1044;
    int unk_1048;
    int unk_104c;
    int unk_1050;
    int unk_1054;
    int unk_1058;
    int unk_105c;
    int unk_1060;
    CollBase m_coll1064;
    int unk_1068;
    int unk_106c;
    int unk_1070;
    int unk_1074;
    int unk_1078;
    int unk_107c;
    int unk_1080;
    int unk_1084;
    int unk_1088;
    int unk_108c;
    int unk_1090;
    int unk_1094;
    int unk_1098;
    int unk_109c;
    int unk_10a0;
    int unk_10a4;
    int unk_10a8;
    int unk_10ac;
    int unk_10b0;
    int unk_10b4;
    int unk_10b8;
    int unk_10bc;
    int unk_10c0;
    int unk_10c4;
    int unk_10c8;
    int unk_10cc;
    int unk_10d0;
    int unk_10d4;
    int unk_10d8;
    int unk_10dc;
    int unk_10e0;
    int unk_10e4;
    int unk_10e8;
    int unk_10ec;
    int unk_10f0;
    int unk_10f4;
    int unk_10f8;
    int unk_10fc;
    int unk_1100;
    int unk_1104;
    int unk_1108;
    int unk_110c;
    int unk_1110;
    int unk_1114;
    int unk_1118;
    int unk_111c;
    int unk_1120;
    int unk_1124;
    int unk_1128;
    int unk_112c;
    int unk_1130;
    int unk_1134;
    int unk_1138;
    int unk_113c;
    int unk_1140;
    int unk_1144;
    int unk_1148;
    int unk_114c;
    int unk_1150;
    int unk_1154;
    int unk_1158;
    int unk_115c;
    int unk_1160;
    int unk_1164;
    int unk_1168;
    int unk_116c;
    int unk_1170;
    int unk_1174;
    int unk_1178;
    int unk_117c;
    int unk_1180;
    int unk_1184;
    int unk_1188;
    int unk_118c;
    int unk_1190;
    int unk_1194;
    int unk_1198;
    int unk_119c;
    int unk_11a0;
    int unk_11a4;
    int unk_11a8;
    int unk_11ac;
    int unk_11b0;
    int unk_11b4;
    int unk_11b8;
    int unk_11bc;
    int unk_11c0;
    int unk_11c4;
    int unk_11c8;
    int unk_11cc;
    int unk_11d0;
    int unk_11d4;
    int unk_11d8;
    int unk_11dc;
    int unk_11e0;
    int unk_11e4;
    int unk_11e8;
    int unk_11ec;
    int unk_11f0;
    int unk_11f4;
    int unk_11f8;
    int unk_11fc;
    int unk_1200;
    int unk_1204;
    int unk_1208;
    int unk_120c;
    int unk_1210;
    int unk_1214;
    int unk_1218;
    int unk_121c;
    int unk_1220;
    int unk_1224;
    int unk_1228;
    int unk_122c;
    int unk_1230;
    int unk_1234;
    int unk_1238;
    int unk_123c;
    int unk_1240;
    int unk_1244;
    int unk_1248;
    int unk_124c;
    int unk_1250;
    int unk_1254;
    int unk_1258;
    int unk_125c;
    int unk_1260;
    int unk_1264;
    int unk_1268;
    int unk_126c;
    int unk_1270;
    int unk_1274;
    int unk_1278;
    int unk_127c;
    int unk_1280;
    int unk_1284;
    int unk_1288;
    int unk_128c;
    int unk_1290;
    int unk_1294;
    int unk_1298;
    int unk_129c;
    int unk_12a0;
    int unk_12a4;
    int unk_12a8;
    int unk_12ac;
    int unk_12b0;
    int unk_12b4;
    int unk_12b8;
    int unk_12bc;
    int unk_12c0;
    int unk_12c4;
    int unk_12c8;
    int unk_12cc;
    int unk_12d0;
    int unk_12d4;
    int unk_12d8;
    int unk_12dc;
    int unk_12e0;
    int unk_12e4;
    int unk_12e8;
    int unk_12ec;
    int unk_12f0;
    int unk_12f4;
    int unk_12f8;
    int unk_12fc;
    int unk_1300;
    int unk_1304;
    int unk_1308;
    int unk_130c;
    int unk_1310;
    int unk_1314;
    int unk_1318;
    int unk_131c;
    int unk_1320;
    int unk_1324;
    int unk_1328;
    int unk_132c;
    int unk_1330;
    int unk_1334;
    int unk_1338;
    int unk_133c;
    int unk_1340;
    int unk_1344;
    int unk_1348;
    int unk_134c;
    int unk_1350;
    int unk_1354;
    int unk_1358;
    int unk_135c;
    int unk_1360;
    int unk_1364;
    int unk_1368;
    int unk_136c;
    int unk_1370;
    int unk_1374;
    int unk_1378;
    int unk_137c;
    int unk_1380;
    int unk_1384;
    int unk_1388;
    int unk_138c;
    int unk_1390;
    int unk_1394;
    int unk_1398;
    int unk_139c;
    int unk_13a0;
    int unk_13a4;
    int unk_13a8;
    int unk_13ac;
    int unk_13b0;
    int unk_13b4;
    int unk_13b8;
    int unk_13bc;
    int unk_13c0;
    int unk_13c4;
    int unk_13c8;
    int unk_13cc;
    int unk_13d0;
    int unk_13d4;
    int unk_13d8;
    int unk_13dc;
    int unk_13e0;
    int unk_13e4;
    int unk_13e8;
    int unk_13ec;
    int unk_13f0;
    int unk_13f4;
    int unk_13f8;
    int unk_13fc;
    int unk_1400;
    int unk_1404;
    int unk_1408;
    int unk_140c;
    int unk_1410;
    int unk_1414;
    int unk_1418;
    int unk_141c;
    int unk_1420;
    int unk_1424;
    int unk_1428;
    int unk_142c;
    int unk_1430;
    int unk_1434;
    int unk_1438;
    int unk_143c;
    int unk_1440;
    int unk_1444;
    int unk_1448;
    int unk_144c;
    int unk_1450;
    int unk_1454;
    int unk_1458;
    int unk_145c;
    int unk_1460;
    int unk_1464;
    int unk_1468;
    int unk_146c;
    int unk_1470;
    int unk_1474;
    int unk_1478;
    int unk_147c;
    Coll1480 m_sub1480;
    void FUN_006eae40();
};

// @fnv 0x006eae40
void FUN_006eae40_shell::FUN_006eae40()
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&(m_lockC38))->FUN_004538a0((std::intptr_t)("PathManagerImpl::Update"));
    switch (m_stateC24)
    {
    case 1:
        if (reinterpret_cast<::fnv_00aa6220::Lock00aa6220 *>(&(m_subC2C))->FUN_00aa6220())
        {
            m_stateC24 = 2;
        }
        else
        {
            m_countC28 = m_countC28 + 1;
        }
        break;
        break;
    case 3:
        reinterpret_cast<::FUN_00aa62e0_shell *>(&(m_subC2C))->FUN_00aa62e0();
        m_stateC24 = 0;
        m_countC28 = 0;
        break;
    }
    int count_iagb = 0;
    ObjA objA6;
    PathingTaskData_Ext* pFound_vv;
    void* pOut_b;
    while (!reinterpret_cast<::FUN_006ebde0_shell *>(&(objA6))->FUN_006ebde0())
    {
        if (reinterpret_cast<::Queue44c640 *>(&(m_sub1480))->TryGetNextEntry((::QueueIter44c640 *)(::fnv_006eae40::ObjA *)(&objA6), &pOut_b, (std::intptr_t)(&pFound_vv), 1) && ((bool)(::FUN_005dc980((const char *)(pFound_vv)))))
        {
            count_iagb += reinterpret_cast<::ManagerView *>((pFound_vv))->FUN_006ea350();
            if ((unsigned int)count_iagb > 10)
                break;
            if (reinterpret_cast<::PathingTaskData *>((pFound_vv))->HasPendingMessages())
            {
                reinterpret_cast<::PlayerQuestData *>((pFound_vv))->SetIndex(0);
                ObjC objC_oqluk;
                reinterpret_cast<::CombatProcedure *>(&(objC_oqluk))->Initialize((::CombatController *)(pFound_vv));
                reinterpret_cast<::fnv_006c5ec0::S6c5ec0 *>(this)->FUN_006c5ec0(&objC_oqluk, 0);
            }
        }
    }
    Item_006eae40 item_omdso;
    while (m_collC10.ContainsItem(&item_omdso))
    {
        switch (item_omdso.m_val)
        {
        case 0:
        case 1:
            m_sub1480.Notify(((void *)(::FUN_00559450((int *)(((NameGetter*)((char*)item_omdso.m_ptr + 0x18)))))));
            delete (VObj*)item_omdso.m_ptr;
            break;
        }
    }
    bool bFlag_ad = false;
    NiPointer<NiNode> spObj2(0);
    while (m_coll1064.ContainsItem(&spObj2))
    {
        if (::FUN_008c7aa0())
        {
            reinterpret_cast<::fnv_0087ac60::FUN_0087AC60_Holder *>((((::fnv_006eae40::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087ac60((::fnv_0087ac60::G00559a40 *)(void *)(spObj2));
        }
        else
        {
            (*reinterpret_cast<::fnv_006eae40::GlobalObject_00633c90 *>(&::g_011d6e5c))->NotifyE8(spObj2);
        }
        bFlag_ad = true;
    }
    while (m_collC50.ContainsItem(&spObj2))
    {
        if (::FUN_008c7aa0())
        {
            reinterpret_cast<::fnv_0087ac00::Owner0087ac00 *>((((::fnv_006eae40::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton()))))->QueueTaskWithTwoObjects((::fnv_0087ac00::G00559a40 *)(void *)(spObj2), (::fnv_0087ac00::G00559a40 *)(void *)((*reinterpret_cast<::fnv_006eae40::GlobalObject_00633c90 *>(&::g_011d6e5c))), true, false);
        }
        else
        {
            (*reinterpret_cast<::fnv_006eae40::GlobalObject_00633c90 *>(&::g_011d6e5c))->NotifyDC(spObj2, 1);
        }
        bFlag_ad = true;
    }
    if (bFlag_ad)
    {
        if (::FUN_008c7aa0())
        {
            reinterpret_cast<::fnv_0087ad50::Host *>((((::fnv_006eae40::TaskQueueInterface *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087ad50((::fnv_0087ad50::G00559a40 *)(void *)((*reinterpret_cast<::fnv_006eae40::GlobalObject_00633c90 *>(&::g_011d6e5c))));
        }
        else
        {
            NiUpdateData ud(0.0f, false, false);
            reinterpret_cast<::FUN_00a59c60_cls *>((((NiNode*)(*reinterpret_cast<::fnv_006eae40::GlobalObject_00633c90 *>(&::g_011d6e5c)))))->FUN_00a59c60((std::intptr_t)&(ud));
        }
    }
    reinterpret_cast<::ActorTaskManager *>(&(m_lockC38))->WaitForTasksDuringRendering();
}
}

#include "generated/data/fallout_shared/pathfinding/pathmanager.inc"
