// fallout_shared/tesscript.cpp: Script, ScriptLocals, DelStandIn, ScriptInitOwner and more (82 functions)

#include <new>
#include <cstring>
#include "fnv/decl/ActList.h"
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSMessageInitAccess.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_0041c8d0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00456630_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00501c10_cls.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_005e2730_shell.h"
#include "fnv/decl/FUN_005e29a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00857ba0_shell.h"
#include "fnv/decl/FUN_00862110_cls.h"
#include "fnv/decl/FUN_00865db0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ItemChangeShell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Ref.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/W004702f0.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00484730__FUN_00484730_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00573f40__R.h"
#include "fnv/decl/fnv_00576260__FUN_00576260_shell.h"
#include "fnv/decl/fnv_005aedb0__ScriptCompiler.h"
#include "fnv/decl/fnv_006eae40__FUN_006eae40_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00469000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_005a8000.h"
#include "fnv/symbols_005aa000.h"
#include "fnv/symbols_005ab000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b1000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_007d9000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0118c000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01272000.h"
#include "tesscript_decls.h"
// @fnv 0x005ac740
bool Script::IsConsolePlatform()
{
    return DAT_0118c685;
}

// @fnv 0x006ebc50
void ScriptLocals::ProcessPendingTasks()
{
    reinterpret_cast<::fnv_006eae40::FUN_006eae40_shell *>((m_pOwnerScript))->FUN_006eae40();
}

// @fnv 0x005acc70
void Script::CopyIdentifierBitsToValue(const unsigned int& id, double& value)
{
    memcpy(&value, &id, sizeof(unsigned int));
}

// @fnv 0x00541cb0
TESBoundObject* ScriptLocals::GetActionEntry()
{
    return reinterpret_cast<ScriptActionView*>(this)->vfn_94();
}

// @fnv 0x005533c0
void Script::GetLocalData()
{
    TESBoundObject* object = reinterpret_cast<ScriptLocals*>(this)->GetLocalData();
    if (object)
        reinterpret_cast<::TESForm *>((object))->ClearData();
}

// Returns the bound object from this ScriptLocals instance, or null when the instance pointer is null.
// @fnv 0x00541c80
TESBoundObject* ScriptLocals::GetLocalData()
{
    return this ? GetActionEntry() : 0;
}

// Runs this script on the given reference with the given locals and time via the singleton instance.
// @fnv 0x005ac3c0
void Script::AdvanceScript(TESObjectREFR* ref, ScriptLocals* locals, float time)
{
    ScriptExecutor::Instance()->Run(this, ref, locals, 0, false, false, false, time);
}

// @fnv 0x005aa2a0
void Script::ClearData()
{
    ::operator delete(m_data);
    ::operator delete(m_pText);
    FUN_005aa2e0();
    InitializeActionList();
}

// Deletes this ScriptLocals object.
// @fnv 0x0041af70
void ScriptLocals::Destroy()
{
    delete this;
}

// Zeroes the 0x14-byte object at pThis, clears the int at offset 0 and offset 0x10, and returns pThis.
// @fnv 0x005a8b80
void* FUN_005a8b80(void* apObject)
{
    memset(apObject, 0, 0x14);
    *reinterpret_cast<int*>(apObject) = 0;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(apObject) + 0x10) = 0;
    return apObject;
}

struct FUN_005a8bc0_shell : public ScriptLocals
{
    void FUN_005a8bc0();
};

void FUN_005a8c00(void* pThis);

struct FUN_005a8c90_shell : public ScriptLocals
{
    void FUN_005a8c90();
};
// Calls two cleanup helpers, then deallocates the pointer stored at offset 0x10 if it is non-null.
// @fnv 0x005a8bc0
void FUN_005a8bc0_shell::FUN_005a8bc0()
{
    FUN_005a8c00(this);
    reinterpret_cast<::FUN_005a8c90_shell *>((this))->FUN_005a8c90();
    if (*(void**)&this->m_pExtendedLocals != 0)
    {
        void* p = *(void**)&this->m_pExtendedLocals;
        ::FUN_00401030(p);
    }
}

// Deletes every item in the list at offset 0xc, then deletes the list itself and nulls the pointer.
// @fnv 0x005a8c90
void FUN_005a8c90_shell::FUN_005a8c90()
{
    if (this->m_pVariableList)
    {
        while (((::ScriptLocalVariable *)(new ((void *)((this->m_pVariableList))) ::Vec3())))
        {
            ScriptLocalVariable* local = ((::ScriptLocalVariable *)(new ((void *)((this->m_pVariableList))) ::Vec3()));
            (this->m_pVariableList)->RemoveHead();
            delete local;
        }
        delete this->m_pVariableList;
        this->m_pVariableList = 0;
    }
}

struct Act5a
{
    int a;
    unsigned int flags;
};
struct FUN_005a8e20_cls
{
    int pad[2];
    int* actionList;
    Act5a* FUN_005a90b0(void* form, bool create);
    bool FUN_005a8e20(void* form, unsigned int flag);
public:
    char FUN_005a8ef0(int, int);
};
// @fnv 0x005a8e20
bool FUN_005a8e20_cls::FUN_005a8e20(void* form, unsigned int flag)
{
    bool result = false;
    if (!actionList)
        return false;
    Act5a* obj = ((::Act5a *)(reinterpret_cast<::ActList *>(this)->FUN_005a90b0((::TESForm *)(form), true)));
    if (obj)
    {
        obj->flags |= flag;
        result = true;
    }
    obj = ((::Act5a *)(reinterpret_cast<::ActList *>(this)->FUN_005a90b0((::TESForm *)(void *)(0), true)));
    if (obj)
    {
        obj->flags |= flag;
        result = true;
    }
    return result;
}

struct FUN_005a8ea0_shell : public ScriptLocals
{
    void FUN_005a8ea0();
};


// Walks the list at this+8 and sets the second int of each entry returned by _ref_006815c0 to 0 until the list or entry is null.
// @fnv 0x005a8ea0
void FUN_005a8ea0_shell::FUN_005a8ea0()
{
    void* pList = *(void**)&this->m_pLocalVariableList;
    while (pList && *((int *)(new ((void *)(pList)) ::Vec3())))
    {
        int* used = (int*)*((int *)(new ((void *)(pList)) ::Vec3()));
        pList = reinterpret_cast<::Callees *>((pList))->FUN_00726070();
        used[1] = 0;
    }
}

struct FUN_005a9140_shell : public ScriptLocals
{
    double FUN_005a9140(unsigned int, Script*);
};

extern int DAT_011cae50;

bool _ref_008256d0(unsigned int);

struct TLS_Data_005a9140
{
    char pad[0x270];
    ScriptLocalVariable* pLastLocal;
    unsigned int uiLastID;
    void* pLastLocals;
};

__declspec(thread) TLS_Data_005a9140 tls_005a9140;

// Looks up a script local variable by ID (using a TLS cache), returns its double value, or warns and returns 0.0 if not found.
// @fnv 0x005a9140
double FUN_005a9140_shell::FUN_005a9140(unsigned int auiID, Script* apScript)
{
    ScriptLocalVariable* plocalvar = 0;
    if ((*reinterpret_cast<::TLS_Data_005a9140 *>(&::g_tlsBlock)).pLastLocals == this && (*reinterpret_cast<::TLS_Data_005a9140 *>(&::g_tlsBlock)).uiLastID == auiID)
    {
        plocalvar = (*reinterpret_cast<::TLS_Data_005a9140 *>(&::g_tlsBlock)).pLastLocal;
    }
    if (plocalvar == 0)
    {
        unsigned int pCurrentElementNext = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)this)))->FUN_0084e3a0()));
        while (pCurrentElementNext != 0 && !_ref_008256d0(pCurrentElementNext))
        {
            ScriptLocalVariable* pCandidate = *((::ScriptLocalVariable **)(new ((void *)(pCurrentElementNext)) ::Vec3()));
            if (*(unsigned int*)pCandidate == auiID)
            {
                plocalvar = pCandidate;
                break;
            }
            pCurrentElementNext = ((unsigned int)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        }
    }
    (*reinterpret_cast<::TLS_Data_005a9140 *>(&::g_tlsBlock)).pLastLocals = this;
    (*reinterpret_cast<::TLS_Data_005a9140 *>(&::g_tlsBlock)).uiLastID = auiID;
    (*reinterpret_cast<::TLS_Data_005a9140 *>(&::g_tlsBlock)).pLastLocal = plocalvar;
    if (plocalvar != 0)
    {
        return plocalvar->fValue;
    }
    ::FUN_005b5e40(
        );
    return 0.0;
}

struct ListX
{
    int a[2];
    ~ListX();
};
struct Base5a
{
    virtual ~Base5a();
    char pad[0x44 - 4];
};
struct FUN_005aa1a0 : public Base5a
{
    ListX l1;
    ListX l2;
    virtual void ClearData();
    virtual ~FUN_005aa1a0();
};
// @fnv 0x005aa1a0
FUN_005aa1a0::~FUN_005aa1a0()
{
    ClearData();
}

struct FUN_005aa220_shell : public Script
{
    void ResetScriptData();
};
// @fnv 0x005aa0f0
Script::Script()
{
    InitializeComponent();
}

__declspec(thread) extern char tls_pad[0x268];

// Clears the script's data fields and TLS state, then sets the form type to 0x11.
// @fnv 0x005aa220
void FUN_005aa220_shell::ResetScriptData()
{
    memset(&m_kHeader, 0, sizeof(m_kHeader));
    m_data = 0;
    m_pText = 0;
    ::bConditionFunctionDebug = false;
    m_pOwnerQuest = 0;
    m_fValueAtOffset34 = 0.0f;
    fValueAtOffset38 = 0.0f;
    m_fValueAtOffset3C = 0.0f;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x11)));
}

// Deletes every item in the variable list and removes each head until the list is empty.
// @fnv 0x005aa2e0
void Script::FUN_005aa2e0()
{
    BSSimpleList<ScriptVariableInfo*>* pList = ((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (pList && !pList->IsEmpty())
    {
        delete ((::ScriptVariableInfo *)(new ((void *)(pList)) ::Vec3()));
        pList->RemoveHead();
    }
}

struct FUN_005aa420_shell : public Script
{
    void CopyFromScript(Script*);
};

struct G2
{
    void AddHead(int* p);
};
struct ATM
{
};
// Queries the performance counter, and if value is non-zero references it and adds it to a list unless FUN_005aa680 accepts it, then waits for rendering tasks.
// @fnv 0x005aa580
void FUN_005aa580(int value)
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::ATM *>(&::g_011cacf8))))->FUN_004538a0(0);
    if (value)
    {
        reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::G2 *>(&::g_011cac98))))->FUN_00905330((*(::InventoryStackRecord *const *)(&value)));
        if (!::fnv_005aa680::FUN_005aa680((::Actor *)(value)))
            (*reinterpret_cast<::G2 *>(&::g_011caca8)).AddHead(&value);
    }
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::ATM *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
}

namespace fnv_005aa5d0 {
struct G2
{
};
struct ATM
{
};
// If value is nonzero, queries the performance counter, passes value to four objects' _ref_00905330, then waits for tasks during rendering.
// @fnv 0x005aa5d0
void FUN_005aa5d0(int value)
{
    if (value)
    {
        reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_005aa5d0::ATM *>(&::g_011cacf8))))->FUN_004538a0(0);
        reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::fnv_005aa5d0::G2 *>(&::g_011caca8))))->FUN_00905330((*(::InventoryStackRecord *const *)(&value)));
        reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::fnv_005aa5d0::G2 *>(&::g_011cac98))))->FUN_00905330((*(::InventoryStackRecord *const *)(&value)));
        reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::fnv_005aa5d0::G2 *>(&::g_011cace8))))->FUN_00905330((*(::InventoryStackRecord *const *)(&value)));
        reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::fnv_005aa5d0::G2 *>(&::g_011cacb8))))->FUN_00905330((*(::InventoryStackRecord *const *)(&value)));
        reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_005aa5d0::ATM *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
    }
}
}  // namespace fnv_005aa5d0

namespace fnv_005aa630 {
class ActorTaskManager
{
  public:
};


// Checks whether apRef is non-null and present in g_011cac98, bracketing the check with calls on g_011cacf8, and returns the result.
// @fnv 0x005aa630
bool __cdecl FUN_005aa630(Actor* apRef)
{
    bool bretval = false;
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_005aa630::ActorTaskManager *>(&::g_011cacf8))))->FUN_004538a0(0);
    if (apRef && reinterpret_cast<::RefList *>(&((*reinterpret_cast<::BSSimpleList< ::Actor *> *>(&::g_011cac98))))->FUN_005f65d0((void **)&(apRef)))
        bretval = true;
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_005aa630::ActorTaskManager *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
    return bretval;
}
}  // namespace fnv_005aa630

namespace fnv_005aa680 {
struct ActorTaskManager
{
};


// Checks whether apRef is non-null and present in g_011caca8, calling QueryPerformanceCounter and WaitForTasksDuringRendering around the check.
// @fnv 0x005aa680
bool __cdecl FUN_005aa680(Actor* apRef)
{
    bool bretval = false;
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_005aa680::ActorTaskManager *>(&::g_011cacf8))))->FUN_004538a0(0);
    if (apRef && reinterpret_cast<::RefList *>(&((*reinterpret_cast<::BSSimpleList< ::Actor *> *>(&::g_011caca8))))->FUN_005f65d0((void **)&(apRef)))
        bretval = true;
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_005aa680::ActorTaskManager *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
    return bretval;
}
}  // namespace fnv_005aa680

namespace fnv_005aa720 {
class ActorTaskManager
{
  public:
};


bool FUN_005aa8c0(BSFadeNode* fadeNode);


// @fnv 0x005aa720
void FUN_005aa720()
{
    BSSimpleList<TESObjectREFR*>* pCurrentElementNext;
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_005aa720::ActorTaskManager *>(&::g_011cacf8))))->FUN_004538a0(0);
    while (!(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011caca8)).IsEmpty())
    {
        TESObjectREFR* pref = ((::TESObjectREFR *)(new ((void *)&((*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011caca8)))) ::Vec3()));
        (*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011caca8)).RemoveHead();
        reinterpret_cast<::fnv_00573f40::R *>((pref))->FUN_00573f40();
    }
    while (!(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cac98)).IsEmpty())
    {
        TESObjectREFR* pref = ((::TESObjectREFR *)(new ((void *)&((*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cac98)))) ::Vec3()));
        (*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cac98)).RemoveHead();
        reinterpret_cast<::Ref *>((pref))->FUN_00574400();
    }
    pCurrentElementNext = &(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cace8));
    while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
    {
        TESObjectREFR* pref;
        NiNode* pav;
        BSSimpleList<TESObjectREFR*>* m_pActionSuccessor = ((::BSSimpleList< ::TESObjectREFR *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        pref = ((::TESObjectREFR *)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        pav = pref->GetNiNode_v();
        BSFadeNode* pfade = pav ? pav->GetFadeNode() : 0;
        if (!pfade || !FUN_005aa8c0(pfade))
        {
            reinterpret_cast<::Ref *>((pref))->FUN_00574400();
            reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cace8))))->FUN_00905330((::InventoryStackRecord *const &)(pref));
            if (pCurrentElementNext == &(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cace8)))
                m_pActionSuccessor = &(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cace8));
        }
        pCurrentElementNext = m_pActionSuccessor;
    }
    while (!(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cacb8)).IsEmpty())
    {
        TESObjectREFR* pref = ((::TESObjectREFR *)(new ((void *)&((*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cacb8)))) ::Vec3()));
        (*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cacb8)).RemoveHead();
        delete pref;
    }
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_005aa720::ActorTaskManager *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_005aa720

struct FUN_005aae70_shell : public Script
{
    void FUN_005aae70(unsigned int, char*);
};

char* __cdecl AllocateZeroed(unsigned int, unsigned int);

// Frees m_data, stores auiDataSize at offset 0x20, and if nonzero allocates that many bytes and copies apCompileData into m_data.
// @fnv 0x005aae70
void FUN_005aae70_shell::FUN_005aae70(unsigned int auiDataSize, char* apCompileData)
{
    ::FUN_00401030(m_data);
    m_data = 0;
    this->m_kHeader.dataSize = auiDataSize;
    if (this->m_kHeader.dataSize)
    {
        m_data = AllocateZeroed(1, this->m_kHeader.dataSize);
        memcpy(m_data, apCompileData, this->m_kHeader.dataSize);
    }
}

class MemoryManager
{
  public:
};


// Multiplies aSize by aNum, allocates that many bytes from the memory manager, zeroes them with memset, and returns the pointer.
// @fnv 0x005aaee0
char* __cdecl AllocateZeroed(unsigned int aNum, unsigned int aSize)
{
    aSize = aSize * aNum;
    void* pBuffer = reinterpret_cast<::MemoryManagerStandIn *>((FUN_00401020()))->FUN_00aa3e40(aSize);
    memset(pBuffer, 0, aSize);
    return (char*)pBuffer;
}

void* __cdecl operator new(unsigned int);
bool _ref_008256d0(void*);

class SoundListEntry;
class SoundListView
{
  public:
};

struct FUN_005ab8b0
{
    int pad[4];
    FUN_005ab8b0(int);
};

// Copies each element of pCopyFromList into a new FUN_005ab8b0 and appends it to pCopyToList until the source list is exhausted or _ref_008256d0 returns true.
// @fnv 0x005ab7f0
void __cdecl CopyListToTail(void* pSourceList, SoundListView* pCopyToList)
{
    if (!pCopyToList || !pSourceList)
        return;

    while (pSourceList && !_ref_008256d0(pSourceList))
    {
        SoundListEntry* pNewRefObject = (SoundListEntry*)new FUN_005ab8b0(*((int *)(new ((void *)(pSourceList)) ::Vec3())));
        reinterpret_cast<::Callees *>((pCopyToList))->FUN_00905820((void *)&(pNewRefObject));
        pSourceList = reinterpret_cast<::Callees *>((pSourceList))->FUN_00726070();
    }
}

struct FUN_005abe50_shell : public Script
{
    void FUN_005abe50(char*);
};
// Copies the header, data, referenced objects, variables and text from another Script into this one, resetting the variable count.
// @fnv 0x005aa420
void FUN_005aa420_shell::CopyFromScript(Script* apScriptToCopy)
{
    if (!apScriptToCopy)
        return;

    memcpy(&m_kHeader, ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>((apScriptToCopy))->GetConditions())), sizeof(ScriptHeaderData));
    m_kHeader.variableCount = 0;

    reinterpret_cast<::FUN_005aae70_shell *>(this)->FUN_005aae70(m_kHeader.dataSize, apScriptToCopy->GetData());

    InitializeActionList();
    ::CopyListToTail(((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apScriptToCopy))->FUN_005d43c0())), (::SoundListView *)(::BSSimpleList< ::ScriptReferencedObject *> *)(((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))));

    FUN_005aa2e0();
    ::fnv_005ab930::CopyListToView((::fnv_005ab930::FUN_008256d0 *)(::BSSimpleList< ::ScriptVariableInfo *> *)(((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>((apScriptToCopy))->FUN_005d43e0()))), (::fnv_005ab930::SoundListView *)(::BSSimpleList< ::ScriptVariableInfo *> *)(((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()))));

    if (((char *)(reinterpret_cast<::BGSMessageInitAccess *>((apScriptToCopy))->GetIconFormID())))
        reinterpret_cast<::FUN_005abe50_shell *>(this)->FUN_005abe50((char *)(((char *)(reinterpret_cast<::BGSMessageInitAccess *>((apScriptToCopy))->GetIconFormID()))));
    else
        reinterpret_cast<::FUN_005abe50_shell *>(this)->FUN_005abe50((char *)(0));

    SetInitializationState(reinterpret_cast<::TESForm *>((void *)(apScriptToCopy))->GetInitialized());
}

// Frees the stored string, then copies newText into a newly allocated buffer (or clears it when newText is null).
// @fnv 0x005abe50
void FUN_005abe50_shell::FUN_005abe50(char* newText)
{
    if (m_pText)
    {
        ::FUN_00401030(m_pText);
    }
    if (newText)
    {
        int iSize = strlen(newText);
        m_pText = ::AllocateZeroed(1, iSize + 1);
        memcpy(m_pText, newText, iSize);
    }
    else
    {
        m_pText = 0;
    }
}

struct FUN_005abf60_shell : public Script
{
    ScriptLocals* FUN_005abf60();
};

void* __cdecl operator new(unsigned int);
void* CopyVariableList(Script*);

// Allocates a ScriptLocals, stores the result of CopyVariableList(this) at offset 0xc and this at offset 0, then returns it.
// @fnv 0x005abf60
ScriptLocals* FUN_005abf60_shell::FUN_005abf60()
{
    AutoMemContext tempMemContext(static_cast<MEM_CONTEXT>(0x15), true,
                                  "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp", 0xcde);
    ScriptLocals* sl = new ScriptLocals;
    *reinterpret_cast<void**>(&sl->m_pVariableList) = CopyVariableList(this);
    *reinterpret_cast<Script**>(sl) = this;
    return sl;
}

// @fnv 0x005ac190
void __cdecl FUN_005ac190(TESObjectREFR* ownerObject, ExtraDataList* apExtra)
{
    if (apExtra && reinterpret_cast<::FUN_00418830_shell *>((apExtra))->FUN_00418830())
    {
        ScriptLocals* locals = reinterpret_cast<::FUN_00418830_shell *>((apExtra))->FUN_00418830();
        if (!locals->m_pLocalVariableList)
        {
            reinterpret_cast<::FUN_005e2730_shell *>((ScriptExecutor::Instance()))->FUN_005e2730(locals->m_pOwnerScript, ownerObject, locals);
        }
    }
}

struct FUN_005ac1e0_shell : public Script
{
    bool FUN_005ac1e0(TESObjectREFR*, ScriptLocals*, TESObjectREFR*, bool);
};


namespace fnv_005ac4f0 {
struct FUN_005ac4f0_shell : public Script
{
    ScriptReferencedObject* GetNthRefByIndex(unsigned int, ScriptLocals*);
};

struct ScriptLocals_shell : public ScriptLocals
{
};

bool _ref_008256d0(void* pList);

struct TLSData
{
    char padding[0x27c];
    ScriptReferencedObject* lastRefObj;
    unsigned int lastIndex;
    ScriptLocals* lastLocals;
    Script* lastScript;
};

__declspec(thread) TLSData g_tlsData;

// Returns the reference at aiIndex in this object's extra-data list, resolving its form ID via the script locals and caching the last result in TLS.
// @fnv 0x005ac4f0
ScriptReferencedObject* FUN_005ac4f0_shell::GetNthRefByIndex(unsigned int aiIndex, ScriptLocals* apScriptLocals)
{
    if (aiIndex == 0)
        return 0;
    if (aiIndex > this->m_kHeader.m_uiReferenceID)
        return 0;

    if ((*reinterpret_cast<::fnv_005ac4f0::TLSData *>(&::g_tlsBlock)).lastScript == this && (*reinterpret_cast<::fnv_005ac4f0::TLSData *>(&::g_tlsBlock)).lastIndex == aiIndex && (*reinterpret_cast<::fnv_005ac4f0::TLSData *>(&::g_tlsBlock)).lastLocals == apScriptLocals)
        return (*reinterpret_cast<::fnv_005ac4f0::TLSData *>(&::g_tlsBlock)).lastRefObj;

    void* pList;
    ScriptReferencedObject* pExtraDataEntry;
    unsigned int iCount = 1;
    pList = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((((TESObjectREFR*)this)))->FUN_005d43c0()));

    while (pList && !_ref_008256d0(pList) && iCount < aiIndex)
    {
        iCount++;
        pList = reinterpret_cast<::Callees *>((pList))->FUN_00726070();
    }

    if (!pList)
        return 0;

    pExtraDataEntry = *((::ScriptReferencedObject **)(new ((void *)(pList)) ::Vec3()));
    if (pExtraDataEntry->m_uiFormID != 0 && apScriptLocals != 0)
    {
        double dtemp =
            reinterpret_cast<::FUN_005a9140_shell *>((((ScriptLocals_shell*)apScriptLocals)))->FUN_005a9140(pExtraDataEntry->m_uiFormID, this);
        unsigned int formID = 0;
        ::FUN_005acc90(&formID, &dtemp);
        if (formID != 0)
        {
            pExtraDataEntry->pForm = ::FUN_004839c0(formID);
        }
    }

    (*reinterpret_cast<::fnv_005ac4f0::TLSData *>(&::g_tlsBlock)).lastScript = this;
    (*reinterpret_cast<::fnv_005ac4f0::TLSData *>(&::g_tlsBlock)).lastLocals = apScriptLocals;
    (*reinterpret_cast<::fnv_005ac4f0::TLSData *>(&::g_tlsBlock)).lastIndex = aiIndex;
    (*reinterpret_cast<::fnv_005ac4f0::TLSData *>(&::g_tlsBlock)).lastRefObj = pExtraDataEntry;
    return pExtraDataEntry;
}
}  // namespace fnv_005ac4f0

// If apExtra has script locals, forwards apActionForm and aiFlag to the locals' FUN_005a8e20 and returns its result; otherwise returns false.
// @fnv 0x005ac750
bool __cdecl FUN_005ac750(TESForm* apActionForm, ExtraDataList* apExtra, unsigned int aiFlag)
{
    bool bres = false;
    if (apExtra && reinterpret_cast<::FUN_00418830_shell *>((apExtra))->FUN_00418830())
    {
        ScriptLocals* locals = reinterpret_cast<::FUN_00418830_shell *>((apExtra))->FUN_00418830();
        bres = reinterpret_cast<::FUN_005a8e20_cls *>((locals))->FUN_005a8e20(apActionForm, aiFlag);
    }
    return bres;
}

// @fnv 0x005acc90
void __cdecl FUN_005acc90(unsigned int* aiID, const double* adVal)
{
    memcpy(aiID, adVal, sizeof(unsigned int));
}

struct FUN_00792760_shell : public TESQuest
{
    float FUN_00792760();
};

// @fnv 0x00792760
float FUN_00792760_shell::FUN_00792760()
{
    return *(float*)((char*)this + 0x40);
}

namespace fnv_005a8d20 {
struct FUN_005a8d20_shell : public ScriptLocals
{
    void AttachScriptLocals(ScriptLocals*);
};

struct Act5a
{
    void* obj;
    int next;
};
struct FUN_005a8e20_cls
{
    Act5a* FUN_005a90b0(void*, bool);
};
struct G2
{
    void AddHead(int*);
};
struct SL
{
    char b[8];
    SL();
};
// @fnv 0x005a8d20
void FUN_005a8d20_shell::AttachScriptLocals(ScriptLocals* apLocals)
{
    AutoMemContext ctx((MEM_CONTEXT)0x15, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp",
                       300);
    if (!*(void**)&this->m_pLocalVariableList)
        *(SL**)&this->m_pLocalVariableList = new SL();
    Act5a* used = ((::fnv_005a8d20::Act5a *)(reinterpret_cast<::ActList *>((((FUN_005a8e20_cls*)this)))->FUN_005a90b0((::TESForm *)(apLocals), false)));
    if (!used)
    {
        used = new Act5a;
        used->obj = apLocals;
        used->next = 0;
        (*(G2**)&this->m_pLocalVariableList)->AddHead((int*)&used);
    }
}
}  // namespace fnv_005a8d20

struct FUN_005abed0_shell : public Script
{
    char* FUN_005abed0(unsigned int);
};

struct Flt
{
    operator unsigned int() const;
};
struct VarX
{
    unsigned int id;
    char pad[0x14];
    Flt flt;
};
typedef char*(* NameFn)(void*);
// @fnv 0x005abed0
char* FUN_005abed0_shell::FUN_005abed0(unsigned int auiID)
{
    void* pList = ((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (pList && *((int *)(new ((void *)(pList)) ::Vec3())))
    {
        VarX* pVar = (VarX*)*((int *)(new ((void *)(pList)) ::Vec3()));
        pList = reinterpret_cast<::Callees *>((pList))->FUN_00726070();
        if (pVar->id == auiID)
            return (char*)(unsigned int)pVar->flt;
    }
    ::FUN_005b5e40();
    return 0;
}

struct FUN_005ae2e0_shell : public Script
{
    void FUN_005ae2e0();
};
// Runs the script via the script runner, decrementing a timer and resetting it from the game setting or a referenced value when the header flag is set.
// @fnv 0x005ac1e0
bool FUN_005ac1e0_shell::FUN_005ac1e0(TESObjectREFR* ownerObject, ScriptLocals* ownerVars,
                                      TESObjectREFR* ownerContainer, bool abIsPartialScript)
{
    if (!abIsPartialScript && ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()))->dataSize <= 4)
        return false;

    if (((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()))->m_bQuest && fValueAtOffset38 > 0.0)
    {
        fValueAtOffset38 -= reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue();
        m_fValueAtOffset3C += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue();
        if (fValueAtOffset38 > 0.0)
            return false;
    }

    bool bretVal = ScriptExecutor::Instance()->Run(this, ownerObject, ownerVars, ownerContainer, abIsPartialScript,
                                                   false, false, 0.0f);

    if (((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()))->m_bQuest && ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cac68))))))->f > 0.0)
    {
        if (m_pOwnerQuest && reinterpret_cast<::FUN_00792760_shell *>((m_pOwnerQuest))->FUN_00792760() > 0.0)
        {
            fValueAtOffset38 += reinterpret_cast<::FUN_00792760_shell *>((m_pOwnerQuest))->FUN_00792760();
        }
        else
        {
            fValueAtOffset38 += ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cac68))))))->f;
        }
        m_fValueAtOffset3C = 0.0f;
    }

    reinterpret_cast<::FUN_005ae2e0_shell *>(this)->FUN_005ae2e0();
    return bretVal;
}

bool _ref_008256d0(unsigned int);
__declspec(thread) void* g_tlsSlot;
struct RefObj
{
    char pad[8];
    int f8;
    int fc;
};
// Clears the thread-local slot if it holds this object, then walks the extra-data list and zeroes f8 on each referenced object that has a nonzero fc.
// @fnv 0x005ae2e0
void FUN_005ae2e0_shell::FUN_005ae2e0()
{
    if (g_tlsSlot == (void*)this)
        g_tlsSlot = 0;
    void* pCurrentElementNext = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((((TESObjectREFR*)this)))->FUN_005d43c0()));
    while (pCurrentElementNext && !_ref_008256d0((unsigned int)pCurrentElementNext))
    {
        RefObj* prefObject = (RefObj*)*((int *)(new ((void *)(pCurrentElementNext)) ::Vec3()));
        if (prefObject && prefObject->fc)
            prefObject->f8 = 0;
        pCurrentElementNext = reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070();
    }
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* DestroyAndFree(unsigned int flags);
};
// Runs the destructor on this, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x005aa170
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    reinterpret_cast<::FUN_005aa1a0 *>((((DtorStandIn*)this)))->FUN_005aa1a0::~FUN_005aa1a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

namespace fnv_005aa3f0 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* FUN_005aa3f0(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x005aa3f0
void* DelStandIn::FUN_005aa3f0(unsigned int flags)
{
    ::FUN_007d9ec0((::BSStringT<char> *)(((DtorStandIn*)this)));
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_005aa3f0

struct FUN_005a9460_This
{
    unsigned int field_1c4;
    unsigned int FUN_005a9460();
};

// @fnv 0x005a9460
unsigned int FUN_005a9460_This::FUN_005a9460()
{
    return reinterpret_cast<unsigned int*>(this)[0x1c4 / 4];
}

namespace fnv_005aae20 {
struct ATM
{
};

struct G2
{
};

struct GlobalObject2_0096a2d0
{
};


// @fnv 0x005aae20
void __cdecl FUN_005aae20()
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_005aae20::ATM *>(&::g_011cacf8))))->FUN_004538a0(0);
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::fnv_005aae20::G2 *>(&::g_011caca8))))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::fnv_005aae20::G2 *>(&::g_011cac98))))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::fnv_005aae20::GlobalObject2_0096a2d0 *>(&::g_011cacb8))))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::fnv_005aae20::GlobalObject2_0096a2d0 *>(&::g_011cace8))))->RemoveAll();
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_005aae20::ATM *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_005aae20


struct FUN_005abe00
{
    unsigned char m_0x00[0x18];
    ScriptHeaderData m_kHeader;  // +0x18
    void ProcessHeader();
};

// @fnv 0x005abe00
void FUN_005abe00::ProcessHeader()
{
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00414220_shell *>(&(m_kHeader))->FUN_00414220();
    ::AppendChunk(0x52484353, &m_kHeader, 0x14);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00414220_shell *>(&(m_kHeader))->FUN_00414220();
}

// @fnv 0x005ac730
void FUN_005ac730(bool abProcessScripts)
{
    DAT_0118c685 = abProcessScripts;
}

__declspec(thread) int DAT_tls;

// @fnv 0x005ae270
void FUN_005ae270()
{
    *(int*)((char*)&(*reinterpret_cast<int *>(&::g_tlsBlock)) + 0x288) = 0;
    *(int*)((char*)&(*reinterpret_cast<int *>(&::g_tlsBlock)) + 0x284) = 0;
    *(int*)((char*)&(*reinterpret_cast<int *>(&::g_tlsBlock)) + 0x280) = 0xffffffff;
    *(int*)((char*)&(*reinterpret_cast<int *>(&::g_tlsBlock)) + 0x27c) = 0;
}

struct FUN_00857bd0
{
    int m_0x00;
    int m_0x04;
    int m_0x08;
    int m_0x0c;
    int m_0x10;
    unsigned int m_0x14;
    void Init(unsigned int value);
};

// @fnv 0x00857bd0
void FUN_00857bd0::Init(unsigned int value)
{
    m_0x14 += value;
}

__declspec(thread) int tlsVar1;
__declspec(thread) int tlsVar2 = -1;
__declspec(thread) int tlsVar3;

// Resets the three thread-local variables to 0, -1 and 0.
// @fnv 0x005a9d60
void FUN_005a9d60()
{
    tlsVar1 = 0;
    tlsVar2 = -1;
    tlsVar3 = 0;
}

namespace fnv_005aa6d0 {
struct ATM
{
};

struct LH
{
};


// Queries the performance counter, checks whether arg is in the list, waits for tasks during rendering, and returns whether arg was found.
// @fnv 0x005aa6d0
char __cdecl FUN_005aa6d0(int* pItem)
{
    char result = 0;
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_005aa6d0::ATM *>(&::g_011cacf8))))->FUN_004538a0(0);
    if (pItem && reinterpret_cast<::RefList *>(&((*reinterpret_cast<::fnv_005aa6d0::LH *>(&::g_011cace8))))->FUN_005f65d0((void **)&(pItem)))
        result = 1;
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_005aa6d0::ATM *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
    return result;
}
}  // namespace fnv_005aa6d0

struct FUN_00456630_helper
{
    bool HasFlag8000();
};

// @fnv 0x005aa910
bool FUN_00456630_helper::HasFlag8000()
{
    return ((bool)(reinterpret_cast<::FUN_00456630_Class *>((this))->FUN_00456630(0x8000)));
}

struct FUN_00483d20_shell
{
    unsigned char SaveIfNotTemporary(TESFile*);
};

struct FUN_005abd70_shell : FUN_00483d20_shell
{
    unsigned char FUN_005abd70(TESFile*);
};

// @fnv 0x005abd70
unsigned char FUN_005abd70_shell::FUN_005abd70(TESFile* apFile)
{
    return SaveIfNotTemporary(apFile);
}

struct FUN_00857ba0_class
{
    void ReadFromStream(int a, int b, int c);
};

void FUN_00857ba0_class::ReadFromStream(int a, int b, int c)
{}

struct FUN_008586d0_class
{
    void FUN_008586d0(int a, int b, int c);
};

// @fnv 0x008586d0
void FUN_008586d0_class::FUN_008586d0(int a, int b, int c)
{
    reinterpret_cast<::FUN_00857ba0_shell *>((reinterpret_cast<FUN_00857ba0_class*>(this)))->ReadFromStream((::NiBinaryStream *)(a), (void *)(b), c);
}

struct FUN_005a9290_shell : public ScriptLocals
{
    void SetScriptVariable(unsigned int, double);
};

struct SCRIPT_LOCAL_s
{
    unsigned int uiID;
    unsigned int pad;
    double fValue;
};
struct LocalListStub
{
};
struct EffectSettingStub
{
};
struct MobileObject
{
};

// Searches the script local list for the given variable ID and assigns the value, warning if the variable is not found.
// @fnv 0x005a9290
void FUN_005a9290_shell::SetScriptVariable(unsigned int auiID, double value)
{
    BSSimpleList<SCRIPT_LOCAL_s*>* pList = (BSSimpleList<SCRIPT_LOCAL_s*>*)((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)this)))->FUN_0084e3a0()));
    while (pList && *((::SCRIPT_LOCAL_s **)(new ((void *)(((LocalListStub*)pList))) ::Vec3())))
    {
        SCRIPT_LOCAL_s* pLocal = *((::SCRIPT_LOCAL_s **)(new ((void *)(((LocalListStub*)pList))) ::Vec3()));
        pList = ((::BSSimpleList< ::SCRIPT_LOCAL_s *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        if (pLocal->uiID == auiID)
        {
            pLocal->fValue = value;
            return;
        }
    }
    bool bshowGenericWarning = true;
    if (*(TESForm**)this)
    {
        ::FUN_005b5e40();
        bshowGenericWarning = false;
    }
    else if (reinterpret_cast<::FUN_0047c850 *>((::g_TESSaveLoadGame))->EvaluateCondition())
    {
        FormRecordMetadata* ploadHeader = ((::FormRecordMetadata *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((EffectSettingStub*)::g_TESSaveLoadGame)))));
        TESForm* pform = 0;
        if (ploadHeader)
        {
            pform = ::FUN_004839c0(ploadHeader->iFormID);
            TESObjectREFR* pref = dynamic_cast<TESObjectREFR*>(pform);
            const char* pfullname;
            if (pref)
                pfullname = reinterpret_cast<::FUN_0055d520_shell *>((((MobileObject*)pref)))->FUN_0055d520();
            else
                pfullname = ::FUN_00482720(pform);
            if (pform && pfullname)
            {
                if (pref)
                    ::FUN_005b5e40(
                        );
                else
                    ::FUN_005b5e40(
                        );
            }
            else
            {
                ::FUN_005b5e40(
                    );
            }
            bshowGenericWarning = false;
        }
    }
    if (bshowGenericWarning)
        ::FUN_005b5e40();
}

namespace fnv_005a9f20 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
struct FUN_005a9f20_shell : public ScriptLocals
{
    void FUN_005a9f20(BGSLoadFormBuffer*);
};

struct FUN_005a8ea0_shell
{
};

// @fnv 0x005a9f20
void FUN_005a9f20_shell::FUN_005a9f20(BGSLoadFormBuffer* apLoadGameBuffer)
{
    bool bhasScriptEffectData;
    bool bonLoadFlagSet;
    {
        unsigned int iVariableCount = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apLoadGameBuffer))->FUN_00864a60();
        for (unsigned int iIndex = 0; iIndex < iVariableCount; iIndex++)
        {
            double fvalue = 0.0;
            unsigned int ivarID = 0;
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)&ivarID), 4);
            if (ivarID & 0x80000000)
            {
                ivarID &= 0x7fffffff;
                unsigned int irefID = 0;
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0(&irefID);
                Script::CopyIdentifierBitsToValue(irefID, fvalue);
            }
            else
            {
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)&fvalue), 8);
            }
            reinterpret_cast<::FUN_005a9290_shell *>(this)->SetScriptVariable(ivarID, fvalue);
        }
    }
    bhasScriptEffectData = false;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)&bhasScriptEffectData), 1);
    if (bhasScriptEffectData)
    {
        *(double**)&this->m_pExtendedLocals = new double;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)*(double**)&this->m_pExtendedLocals), 8);
    }
    bonLoadFlagSet = false;
    if (apLoadGameBuffer->GetVersion() >= 0x15)
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)&bonLoadFlagSet), 1);
    if (*(void**)&this->m_pLocalVariableList == 0)
        reinterpret_cast<::FUN_005e2730_shell *>((ScriptExecutor::Instance()))->FUN_005e2730(*(Script**)this, apLoadGameBuffer->GetReference(), this);
    else
        reinterpret_cast<::FUN_005a8ea0_shell *>((((FUN_005a8ea0_shell*)this)))->FUN_005a8ea0();
    if (bonLoadFlagSet)
        reinterpret_cast<::FUN_005a8e20_cls *>(this)->FUN_005a8e20(0, 0x1000);
}
}  // namespace fnv_005a9f20

namespace fnv_005ac020 {
struct FUN_005ac020_shell : public Script
{
    void* CopyVariableList();
};

struct AutoMemHelper
{
    int aiMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct SL
{
    int a;
    int b;
    SL();
};
struct SoundListView
{
};
struct S006815c0
{
};
struct FUN_005ac150
{
    char data[0x18];
    FUN_005ac150(ScriptVariableInfo*);
};

// @fnv 0x005ac020
void* FUN_005ac020_shell::CopyVariableList()
{
    AutoMemHelper tempMemContext(0x15, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp",
                                 0xceb);
    S006815c0* pList;
    SoundListView* pNewList;

    pNewList = (SoundListView*)new SL;
    pList = (S006815c0*)((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (pList && *((::ScriptVariableInfo **)(new ((void *)(pList)) ::Vec3())))
    {
        char* pLocal;
        ScriptVariableInfo* pVar;
        pVar = *((::ScriptVariableInfo **)(new ((void *)(pList)) ::Vec3()));
        pList = ((::fnv_005ac020::S006815c0 *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        pLocal = (char*)new FUN_005ac150(pVar);
        reinterpret_cast<::Callees *>((pNewList))->FUN_00905820((void *)&(pLocal));
    }
    return pNewList;
}
}  // namespace fnv_005ac020

namespace fnv_005ab930 {
struct FUN_005e2910
{
    char* m_pInventoryEntryData;
    char m_bIsDeleted;
    FUN_005e2910(char*);
    ~FUN_005e2910();
};

struct FUN_008256d0
{
    char* m_pInventoryEntryData;
    unsigned char FUN_008256d1() const;
};

struct SoundListView
{
};

struct FUN_005e2910Big
{
    char* m_pInventoryEntryData;
    char m_bIsDeleted;
    FUN_005e2910Big(char*);
    ~FUN_005e2910Big();
    char m_bFiller[0x18];
};

// @fnv 0x005ab930
void CopyListToView(FUN_008256d0* pSourceList, SoundListView* pTargetView)
{
    if (!pTargetView || !pSourceList)
        return;

    while (pSourceList && !pSourceList->FUN_008256d1())
    {
        FUN_005e2910* const pNewItem =
            (FUN_005e2910*)new FUN_005e2910Big(((::fnv_005ab930::FUN_005e2910 *)(new ((void *)(pSourceList)) ::Vec3()))->m_pInventoryEntryData);
        reinterpret_cast<::Callees *>((pTargetView))->FUN_00905820((void *)&(pNewItem));
        pSourceList = ((::fnv_005ab930::FUN_008256d0 *)(reinterpret_cast<::Callees *>((pSourceList))->FUN_00726070()));
    }
}
}  // namespace fnv_005ab930

namespace fnv_005aa090 {

struct Script;
struct FUN_005a8ea0_shell
{
};

struct FUN_005aa090
{
    Script* pScript;
    int pad0;
    int pad1;
    void* pData;
    void* pAlloc;
    void Method(int dummy);
};

// Calls FUN_005a8c90 and FUN_005a8ea0, refreshes pData from pScript, frees pAlloc and clears it.
// @fnv 0x005aa090
void FUN_005aa090::Method(int dummy)
{
    reinterpret_cast<::FUN_005a8c90_shell *>(this)->FUN_005a8c90();
    reinterpret_cast<::FUN_005a8ea0_shell *>((((FUN_005a8ea0_shell*)this)))->FUN_005a8ea0();
    if (pScript)
        pData = reinterpret_cast<::fnv_005ac020::FUN_005ac020_shell *>((pScript))->CopyVariableList();
    if (pAlloc)
    {
        void* tmp = pAlloc;
        ::FUN_00401030(tmp);
    }
    pAlloc = 0;
}
}  // namespace fnv_005aa090

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_005abd90 : TESForm
{
    void Save();
};
// @fnv 0x005abd90
void FUN_005abd90::Save()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    TESForm::ClearData();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00414220_shell *>((reinterpret_cast<ScriptHeaderData*>(reinterpret_cast<char*>(this) + 0x18)))->FUN_00414220();
    ::AppendChunk(0x52484353, reinterpret_cast<char*>(this) + 0x18, 0x14);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00414220_shell *>((reinterpret_cast<ScriptHeaderData*>(reinterpret_cast<char*>(this) + 0x18)))->FUN_00414220();
    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

namespace fnv_005ac6a0 {
struct Flt
{
    operator unsigned int() const;
};
struct FUN_005ac6a0 : Script
{
    char Method_005ac6a0(const char* name, unsigned int* id);
};
// @fnv 0x005ac6a0
char FUN_005ac6a0::Method_005ac6a0(const char* pcName, unsigned int* puiID)
{
    BSSimpleList<ScriptVariableInfo*>* node = ((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    while (node && ((::ScriptVariableInfo *)(new ((void *)(node)) ::Vec3())))
    {
        ScriptVariableInfo* variable = ((::ScriptVariableInfo *)(new ((void *)(node)) ::Vec3()));
        node = ((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        if (::FUN_00404dc0((const char*)(unsigned int)*(Flt*)((char*)variable + 0x18), pcName) == 0)
        {
            *puiID = variable->data.uiID;
            if (variable->data.m_bIsString)
                return 's';
            else
                return 'f';
        }
    }
    *puiID = 0;
    return 0;
}
}  // namespace fnv_005ac6a0

namespace fnv_005aa500 {
struct ATM
{
};

struct ContNode
{
};

struct G2 : public ContNode
{
    void AddHead(int*);
};

struct GlobalObject2_0096a2d0 : public G2
{
};



// @fnv 0x005aa500
void __cdecl FUN_005aa500(int aiTask, unsigned char abAlternate)
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_005aa500::ATM *>(&::g_011cacf8))))->FUN_004538a0(0);

    if (aiTask != 0)
    {
        reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::fnv_005aa500::G2 *>(&::g_011caca8))))->FUN_00905330((*(::InventoryStackRecord *const *)(&aiTask)));

        if (abAlternate == 0)
        {
            if (!::fnv_005aa630::FUN_005aa630((::Actor *)(aiTask)))
                (*reinterpret_cast<::fnv_005aa500::G2 *>(&::g_011cac98)).AddHead(&aiTask);
        }
        else
        {
            if (!((bool)(::fnv_005aa6d0::FUN_005aa6d0((int *)(aiTask)))))
                (*reinterpret_cast<::fnv_005aa500::GlobalObject2_0096a2d0 *>(&::g_011cace8)).AddHead(&aiTask);
        }
    }

    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_005aa500::ATM *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_005aa500

namespace fnv_005aaaf0 {
struct G2;

struct List_009e03e0
{
};

struct G2 : public List_009e03e0
{
    void AddHead(int* value);
};

struct GlobalObject2_0096a2d0 : public G2
{
};

class ATM
{
  public:
};

class BGSLoadFormBuffer
{
  public:
    unsigned int ReadFormIdentifier();
};

struct ExpandedTESObjectREFR : public TESObjectREFR
{
    unsigned char padding[0x50];

    __forceinline ExpandedTESObjectREFR() : TESObjectREFR()
    {}
};


G2 g_011cac98;
G2 g_011caca8;
GlobalObject2_0096a2d0 g_011cacb8;
GlobalObject2_0096a2d0 g_011cace8;
ATM g_011cacf8;

// @fnv 0x005aaaf0
void __cdecl LoadReferenceLists(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_005aaaf0::ATM *>(&::g_011cacf8))))->FUN_004538a0(0);
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::fnv_005aaaf0::G2 *>(&::g_011caca8))))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::fnv_005aaaf0::G2 *>(&::g_011cac98))))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::fnv_005aaaf0::GlobalObject2_0096a2d0 *>(&::g_011cacb8))))->RemoveAll();
    reinterpret_cast<::FileMatchList *>(&((*reinterpret_cast<::fnv_005aaaf0::GlobalObject2_0096a2d0 *>(&::g_011cace8))))->RemoveAll();

    {
        unsigned int count = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new ExpandedTESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                (*reinterpret_cast<::fnv_005aaaf0::G2 *>(&::g_011caca8)).AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    {
        unsigned int count = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new ExpandedTESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                (*reinterpret_cast<::fnv_005aaaf0::G2 *>(&::g_011cac98)).AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    {
        unsigned int count = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new ExpandedTESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                (*reinterpret_cast<::fnv_005aaaf0::GlobalObject2_0096a2d0 *>(&::g_011cacb8)).AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    {
        unsigned int count = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
        if (count)
        {
            for (unsigned int index = 0; index < count; ++index)
            {
                TESObjectREFR* reference = new ExpandedTESObjectREFR;
                reference = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                (*reinterpret_cast<::fnv_005aaaf0::GlobalObject2_0096a2d0 *>(&::g_011cace8)).AddHead(reinterpret_cast<int*>(&reference));
            }
        }
    }

    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_005aaaf0::ATM *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_005aaaf0

struct CStringArgument
{
    const char* input;
};

struct S7010
{
};

struct GO
{
    operator unsigned int() const;
};

struct TESFaction_RankDataView
{
};


struct ScriptInitOwner : public Script
{
    void InitFromCompileData(CStringArgument* apCompileData);
};

struct FUN_005ac340_t
{
    void RunScriptOnTarget(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals);
};

// Runs the script on the target reference with the given effect locals via the script runner singleton.
// @fnv 0x005ac340
void FUN_005ac340_t::RunScriptOnTarget(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals)
{
    ScriptExecutor::Instance()->Run((Script*)this, apTargetRef, apEffectLocals, 0, 0, 1, 0, 0.0f);
}

struct FUN_005ac380
{
    void ExecuteEffectOnTarget(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals);
};

// @fnv 0x005ac380
void FUN_005ac380::ExecuteEffectOnTarget(TESObjectREFR* apTargetRef, ScriptLocals* apEffectLocals)
{
    ScriptExecutor::Instance()->Run((Script*)this, apTargetRef, apEffectLocals, 0, 0, 0, 1, 0.0f);
}

enum COMPILER_NAME
{
    COMPILER_NAME_DEFAULT = 0,
    COMPILER_NAME_SCRIPT = 1
};

class ScriptCompiler
{
  public:
};

class AutoMemHelper
{
  public:
    AutoMemHelper(int size, bool flag, const char* fileName, int line);
    ~AutoMemHelper();

  private:
    void* m_pBuffer;
};

extern int __tls_index;
__declspec(thread) unsigned char FUN_005ac400_tls[0x269];

struct ScriptCompileAndRun
{
    void FUN_005ac400(ScriptCompiler* compiler, COMPILER_NAME compilerIndex, TESObjectREFR* ownerObject);
};

// Compiles the script with the given compiler index and owner object, and if compilation succeeds and the script has data, runs it with the owner's locals.
// @fnv 0x005ac400
void ScriptCompileAndRun::FUN_005ac400(ScriptCompiler* compiler, COMPILER_NAME compilerIndex,
                                       TESObjectREFR* ownerObject)
{
    AutoMemHelper tempMemContext(0x15, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp",
                                 0xd53);

    if (reinterpret_cast<::fnv_005aedb0::ScriptCompiler *>((compiler))->FUN_005aedb0((::fnv_005aedb0::Script *)(::Script *)((Script*)this), (::fnv_005aedb0::TESObjectREFR *)(ownerObject), (*(::fnv_005aedb0::COMPILER_NAME *)&(compilerIndex)), false) &&
        ((Script*)this)->m_kHeader.dataSize != 0)
    {
        if (compilerIndex == 1)
            (*reinterpret_cast<unsigned char (*)[617]>(&::g_tlsBlock))[0x268] = 1;

        ScriptLocals* ownerVars = 0;
        if (ownerObject != 0)
            ownerVars = reinterpret_cast<::FUN_005673e0_shell *>((ownerObject))->FUN_005673e0();

        reinterpret_cast<::FUN_005ac1e0_shell *>((((Script*)this)))->FUN_005ac1e0(ownerObject, ownerVars, 0, true);

        (*reinterpret_cast<unsigned char (*)[617]>(&::g_tlsBlock))[0x268] = 0;
    }
}

struct FUN_005a9480_ItemRef
{
    unsigned int pad0;
    unsigned int pad4;
    unsigned int pad8;
    unsigned int formID;
};


struct FUN_005a9480_holder
{
    void* pHead;
    bool FUN_005a9480(unsigned int formID);
};

// Walks the linked list from pHead and returns true if any node's item has a formID matching formID.
// @fnv 0x005a9480
bool FUN_005a9480_holder::FUN_005a9480(unsigned int formID)
{
    if (pHead == 0)
    {
        return false;
    }
    void* node = reinterpret_cast<::FUN_005d43c0_ *>((pHead))->FUN_005d43c0();
    while (node != 0 && *((int *)(new ((void *)(node)) ::Vec3())) != 0)
    {
        FUN_005a9480_ItemRef* item = (FUN_005a9480_ItemRef*)*((int *)(new ((void *)(node)) ::Vec3()));
        if (item->formID == formID)
        {
            return true;
        }
        node = reinterpret_cast<::Callees *>((node))->FUN_00726070();
    }
    return false;
}

struct ScriptVariableValue
{
    unsigned int id;
    unsigned int unknown04;
    double value;
    bool isInteger;
};
struct ScriptLocalList
{
};
struct GlobalGameState
{
};
struct FlagManager
{
    unsigned char* FUN_00408d60();
};
struct MessageProducer
{
    void* unk00;
};
struct Formatter
{
    unsigned int getItem(int item, unsigned int line, const char* text)
    {
        typedef unsigned int(* Callback)(Formatter*, int, unsigned int, const char*);
        Callback fn = *(Callback*)(*(char**)this + 0x130);
        return fn(this, item, line, text);
    }
};
extern const char DAT_01036d58;
struct ScriptLocalsExt : ScriptLocals
{
};
// @fnv 0x005a94f0
unsigned short GetScriptLocalsSerializedSize(ScriptLocals* pLocals)
{
    unsigned short bytes = 0;
    unsigned short original = bytes;
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        bytes += 4;
        bytes += 2;
    }
    bytes += 2;
    ScriptLocalList* entry = (ScriptLocalList*)pLocals->m_pVariableList;
    while (entry)
    {
        ScriptVariableValue* value = *((::ScriptVariableValue **)(new ((void *)(entry)) ::Vec3()));
        if (value && value->value != 0.0)
        {
            if (reinterpret_cast<::FUN_005a9480_holder *>((((ScriptLocalsExt*)pLocals)))->FUN_005a9480(value->id))
                bytes += 8;
            else
                bytes += 12;
        }
        entry = ((::ScriptLocalList *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070()));
    }
    bytes += 1;
    if (pLocals->m_pExtendedLocals)
        bytes += 8;
    if (*(*reinterpret_cast<::FlagManager *>(&::g_011de4e8)).FUN_00408d60())
    {
        void* info = ((void *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (info)
        {
            Formatter* formatter = ((::Formatter *)(::FUN_004839c0((unsigned int)(*(void**)info))));
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    return bytes;
}

void* CopyVariableList(Script*);

struct FUN_005a9d00_shell : public ScriptLocals
{
    void FUN_005a9d00();
};

// @fnv 0x005a9d00
void FUN_005a9d00_shell::FUN_005a9d00()
{
    reinterpret_cast<::FUN_005a8c90_shell *>(this)->FUN_005a8c90();
    reinterpret_cast<::FUN_005a8ea0_shell *>(this)->FUN_005a8ea0();
    if (m_pOwnerScript)
        m_pVariableList = (BSSimpleList<ScriptLocalVariable*>*)reinterpret_cast<::fnv_005ac020::FUN_005ac020_shell *>((m_pOwnerScript))->CopyVariableList();
    if (m_pExtendedLocals)
        delete (void*)m_pExtendedLocals;
    m_pExtendedLocals = 0;
}

class BGSSaveFormBuffer
{
  public:
};

void __cdecl FUN_005acc90(unsigned int* aiID, const double* adVal);

struct SaveLocals9db0 : public ScriptLocals
{
    void FUN_005a9db0(BGSSaveFormBuffer* buffer);
};

// @fnv 0x005a9db0
void SaveLocals9db0::FUN_005a9db0(BGSSaveFormBuffer* buffer)
{
    int count3 = 0;
    unsigned int offset = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();
    BSSimpleList<ScriptLocalVariable*>* node3 = m_pVariableList;
    while (node3)
    {
        ScriptLocalVariable* local_ = ((::ScriptLocalVariable *)(new ((void *)(node3)) ::Vec3()));
        if (local_ && local_->fValue != 0.0)
        {
            if (reinterpret_cast<::FUN_005a9480_holder *>(this)->FUN_005a9480(local_->uiID))
            {
                unsigned int value7 = 0;
                FUN_005acc90(&value7, &local_->fValue);
                unsigned int id3 = local_->uiID | 0x80000000;
                reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&id3, 4, 0);
                reinterpret_cast<::FUN_00865db0_shell *>((buffer))->FUN_00865db0(value7, 0);
            }
            else
            {
                reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(local_, 4, 0);
                reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&local_->fValue, 8, 0);
            }
            count3++;
        }
        node3 = ((::BSSimpleList< ::ScriptLocalVariable *> *)(reinterpret_cast<::Callees *>((node3))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count3, offset);
    unsigned char hasEffect = m_pExtendedLocals != 0;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&hasEffect, 1, 0);
    if (hasEffect)
    {
        reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(m_pExtendedLocals, 8, 0);
    }
    char result2 = reinterpret_cast<::FUN_005a8e20_cls *>(this)->FUN_005a8ef0(0, 0x1000);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&result2, 1, 0);
}


class FUN_005aa8c0_cls
{
  public:
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
    float m_fB8;
    bool FUN_005aa8c0();
};

// Returns true if HasFlag8000() is true, DAT_011ad7b4 is zero, or m_fB8 exceeds DAT_01012060.
// @fnv 0x005aa8c0
bool FUN_005aa8c0_cls::FUN_005aa8c0()
{
    return (reinterpret_cast<::FUN_00456630_helper *>(this)->HasFlag8000() || DAT_011ad7b4 == 0 || m_fB8 > ::_DAT_01012060) ? 1 : 0;
}


struct ScrVarStub
{
};

struct RefObjStub
{
    int unk00;
    int unk04;
    TESForm* form;
};

struct VarListStub
{
    int Count();
};

struct RefListStub
{
    int Count();
};

struct NameStr
{
    int unk00;
    int unk04;
    operator const char*() const;
};

struct CompileDataStub
{
    int unk00;
    int unk04;
    int unk08;
    NameStr name;
    int unk14;
    int unk18;
    int unk1C;
    char* data;
    int unk24;
    ScriptHeaderData header;
};

struct ScriptCmpOwner : public Script
{
    bool IsDifferentFromCompileData(CompileDataStub* apData);
};
// @fnv 0x005aaf20
void ScriptInitOwner::InitFromCompileData(CStringArgument* apCompileData)
{
    this->InitItem();

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((S7010*)((char*)apCompileData + 0x0C))))->FUN_004048e0())) == 0)
    {
        this->MarkForDeletion(true);
    }
    else if (reinterpret_cast<::ScriptCmpOwner *>((this))->IsDifferentFromCompileData((::CompileDataStub *)(apCompileData)))
    {
        this->SetEditorID_AtRuntime((const char*)(((GO*)((char*)apCompileData + 0x0C))->operator unsigned int()));

        ::__memcpy((char*)&this->m_kHeader, (char*)apCompileData + 0x28, 0x14);

        reinterpret_cast<::FUN_005aae70_shell *>((this))->FUN_005aae70(this->m_kHeader.dataSize, *(char**)((char*)apCompileData + 0x20));

        this->InitializeActionList();
        this->FUN_005aa2e0();

        if (this->m_kHeader.dataSize != 0)
        {
            ::CopyListToTail(
                (BSSimpleList<ScriptReferencedObject*>*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((((TESObjectREFR*)apCompileData)))->FUN_005d43c0())),
                (::SoundListView *)(::BSSimpleList< ::ScriptReferencedObject *> *)((BSSimpleList<ScriptReferencedObject*>*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((((TESObjectREFR*)this)))->FUN_005d43c0()))));

            ::fnv_005ab930::CopyListToView(
                (::fnv_005ab930::FUN_008256d0 *)(::BSSimpleList< ::ScriptVariableInfo *> *)((BSSimpleList<ScriptVariableInfo*>*)(unsigned char*)((unsigned char *)(reinterpret_cast<struct ::FUN_005a8080 *>((((TESFaction_RankDataView*)apCompileData)))->GetField()))),
                (::fnv_005ab930::SoundListView *)(::BSSimpleList< ::ScriptVariableInfo *> *)(((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>((this))->FUN_005d43e0()))));
        }

        this->MarkForDeletion(false);
        this->SetAltered(true);
    }
}

// @fnv 0x005ab040
bool ScriptCmpOwner::IsDifferentFromCompileData(CompileDataStub* apData)
{
    unsigned int i8;
    ScriptHeaderData* headerTmp;
    char* dataB;
    VarListStub* newVars;
    VarListStub* oldVars;
    ScrVarStub* newVar4;
    ScrVarStub* oldVar4;
    RefListStub* newRefs3;
    RefListStub* oldRefs4;
    RefObjStub* newRef;
    RefObjStub* oldRef;

    if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning() && ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(apData->name))->FUN_004048e0())))
    {
        if (::FUN_00404dc0(GetName(), apData->name))
            return true;
    }

    headerTmp = &apData->header;
    if (m_kHeader.dataSize != headerTmp->dataSize)
        return true;
    if (m_kHeader.m_uiReferenceID != headerTmp->m_uiReferenceID)
        return true;

    dataB = apData->data;
    for (i8 = 0; i8 < m_kHeader.dataSize; i8++)
    {
        if (m_data[i8] != dataB[i8])
            return true;
    }

    newVars = ((::VarListStub *)(reinterpret_cast<struct ::FUN_005a8080 *>((apData))->GetField()));
    oldVars = ((::VarListStub *)(reinterpret_cast<::FUN_005d43e0_shell *>(this)->FUN_005d43e0()));
    if (newVars->Count() != oldVars->Count())
        return true;
    while (newVars && oldVars)
    {
        oldVar4 = *((::ScrVarStub **)(new ((void *)(oldVars)) ::Vec3()));
        newVar4 = *((::ScrVarStub **)(new ((void *)(newVars)) ::Vec3()));
        if (newVar4 && oldVar4 && reinterpret_cast<::FUN_005e29a0_shell *>((newVar4))->FUN_005e29a0((::FUN_005e29a0_shell *)(oldVar4)))
            return true;
        newVars = ((::VarListStub *)(reinterpret_cast<::Callees *>((newVars))->FUN_00726070()));
        oldVars = ((::VarListStub *)(reinterpret_cast<::Callees *>((oldVars))->FUN_00726070()));
    }

    newRefs3 = ((::RefListStub *)(reinterpret_cast<::FUN_005d43c0_ *>((apData))->FUN_005d43c0()));
    oldRefs4 = ((::RefListStub *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    if (newRefs3->Count() != oldRefs4->Count())
        return true;
    while (newRefs3 && oldRefs4)
    {
        oldRef = *((::RefObjStub **)(new ((void *)(oldRefs4)) ::Vec3()));
        newRef = *((::RefObjStub **)(new ((void *)(newRefs3)) ::Vec3()));
        if (newRef && oldRef && newRef->form != oldRef->form)
            return true;
        newRefs3 = ((::RefListStub *)(reinterpret_cast<::Callees *>((newRefs3))->FUN_00726070()));
        oldRefs4 = ((::RefListStub *)(reinterpret_cast<::Callees *>((oldRefs4))->FUN_00726070()));
    }
    return false;
}

struct FUN_005a8c00_cls
{
    int unk00;
    int unk04;
    void* m_08;
};

struct FUN_005a8c00_list
{
    void _ref_0063f7b0();
};

// @fnv 0x005a8c00
void FUN_005a8c00(void* pThis)
{
    unsigned int v;
    void* arg;
    void* t;
    void* l;
    if (((FUN_005a8c00_cls*)pThis)->m_08 != 0)
    {
        while (*((int *)(new ((void *)(((FUN_005a8c00_cls*)pThis)->m_08)) ::Vec3())) != 0)
        {
            v = *(unsigned int*)((int *)(new ((void *)(((FUN_005a8c00_cls*)pThis)->m_08)) ::Vec3()));
            ((FUN_005a8c00_list*)((FUN_005a8c00_cls*)pThis)->m_08)->_ref_0063f7b0();
            arg = (void*)v;
            ::FUN_00401030(arg);
        }
        t = ((FUN_005a8c00_cls*)pThis)->m_08;
        l = t;
        l != 0 ? ((int)(reinterpret_cast<::W004702f0 *>((((FUN_005a8c00_list*)l)))->FUN_004702f0(1))) : 0;
        ((FUN_005a8c00_cls*)pThis)->m_08 = 0;
    }
}

struct StateX
{
};

struct ThisX
{
    int m_00;
    int m_04;
    int m_08;
    ScriptLocalList* m_0c;
    void* m_10;
    void WriteScriptLocals();
};

// Serializes the script local variable list to the save stream, writing a BLOCK chunk header, count, tagged values and an optional tail, with debug logging.
// @fnv 0x005a9670
void ThisX::WriteScriptLocals()
{
    char* posTmp;
    char* endPos;
    Formatter* pFmt;
    char* curPos;
    void* formPtr;
    unsigned int converted;
    unsigned int tagged;
    ScriptVariableValue* pCur;
    unsigned int chunkTag;
    unsigned short written;
    ScriptLocalList* pList;
    char* fromPos;
    unsigned short numHdr;
    char* posNum;
    bool hasTail;
    char* posB;
    numHdr = 0;
    posB = 0;
    fromPos = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if (*(*reinterpret_cast<::FlagManager *>(&::g_011de4e8)).FUN_00408d60())
        fromPos = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        chunkTag = 0x424c4f4b;
        reinterpret_cast<::FUN_008579b0_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&chunkTag), 4);
        posB = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        reinterpret_cast<::FUN_008579b0_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&numHdr), 2);
    }
    written = 0;
    posNum = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
    reinterpret_cast<::FUN_008579b0_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&written), 2);
    pList = m_0c;
    while (pList)
    {
        pCur = *((::ScriptVariableValue **)(new ((void *)(pList)) ::Vec3()));
        if (pCur && pCur->value != 0.0)
        {
            if (reinterpret_cast<::FUN_005a9480_holder *>(this)->FUN_005a9480(pCur->id))
            {
                converted = 0;
                FUN_005acc90(&converted, &pCur->value);
                tagged = pCur->id | 0x80000000;
                reinterpret_cast<::FUN_008579b0_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&tagged), 4);
                reinterpret_cast<::C857A10Buffer *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_00857a10((const unsigned int *)(const void *)(&converted), 4);
            }
            else
            {
                reinterpret_cast<::FUN_008579b0_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(pCur), 4);
                reinterpret_cast<::FUN_008579b0_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&pCur->value), 8);
            }
            written++;
        }
        pList = ((::ScriptLocalList *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
    }
    *(unsigned short*)posNum = written;
    hasTail = false;
    if (m_10)
        hasTail = true;
    reinterpret_cast<::FUN_008579b0_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(&hasTail), 1);
    if (hasTail)
        reinterpret_cast<::FUN_008579b0_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((void *)(m_10), 8);
    if (*(*reinterpret_cast<::FlagManager *>(&::g_011de4e8)).FUN_00408d60())
    {
        curPos = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        formPtr = ((void *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame))))->GetHitSound()));
        if (formPtr)
        {
            pFmt = ((::Formatter *)(::FUN_004839c0((unsigned int)(*(void**)formPtr))));
            typedef unsigned int(* GetItemFn)(Formatter*);
            ::FUN_0040fbe0();
        }
        else
        {
            ::FUN_0040fbe0();
        }
    }
    if (reinterpret_cast<::FUN_00862110_cls *>(((*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame))))->FUN_00862110())
    {
        endPos = ((char *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((StateX*)(*reinterpret_cast<::GlobalGameState * *>(&::g_TESSaveLoadGame)))))->FUN_00825c00()));
        posTmp = posB;
        if (endPos > posTmp + 0xffff)
            ::FUN_005b5e40();
        *(unsigned short*)posB = (unsigned short)(endPos - posTmp);
    }
}

class BGSSaveFormBuffer_Write : public BGSSaveFormBuffer
{

  public:
};

// Writes each of four global TESObjectREFR lists to the save buffer, counting non-null entries and patching each count at its recorded offset.
// @fnv 0x005aa930
void __cdecl WriteReferenceLists(BGSSaveFormBuffer* buffer)

{

    int count1;

    unsigned int offset1;

    BSSimpleList<TESObjectREFR*>* list1;

    {

        TESObjectREFR* item9;

        int count2;

        unsigned int offset6;

        BSSimpleList<TESObjectREFR*>* listVal;

        TESObjectREFR* aItem2;

        int count7;

        unsigned int offsetVal;

        BSSimpleList<TESObjectREFR*>* list9;

        TESObjectREFR* item8;

        int count9;

        {

            unsigned int offset4;

            BSSimpleList<TESObjectREFR*>* list4;

            TESObjectREFR* item6;

            reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011cacf8))))->FUN_004538a0(0);

            count1 = 0;

            offset1 = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();

            list1 = &(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011caca8));

            while (list1 != 0)
            {

                item9 = (TESObjectREFR*)*((int *)(new ((void *)(list1)) ::Vec3()));

                if (item9 != 0)
                {

                    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((BGSSaveFormBuffer_Write*)buffer)))->FUN_00865df0((::fnv_00865df0::TESForm *)(item9), 0);

                    count1 = count1 + 1;
                }

                list1 = (BSSimpleList<TESObjectREFR*>*)reinterpret_cast<::Callees *>((list1))->FUN_00726070();
            }

            reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count1, offset1);

            count2 = 0;

            offset6 = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();

            listVal = &(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cac98));

            while (listVal != 0)
            {

                aItem2 = (TESObjectREFR*)*((int *)(new ((void *)(listVal)) ::Vec3()));

                if (aItem2 != 0)
                {

                    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((BGSSaveFormBuffer_Write*)buffer)))->FUN_00865df0((::fnv_00865df0::TESForm *)(aItem2), 0);

                    count2 = count2 + 1;
                }

                listVal = (BSSimpleList<TESObjectREFR*>*)reinterpret_cast<::Callees *>((listVal))->FUN_00726070();
            }

            reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count2, offset6);

            count7 = 0;

            offsetVal = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();

            list9 = &(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cacb8));

            while (list9 != 0)
            {

                item8 = (TESObjectREFR*)*((int *)(new ((void *)(list9)) ::Vec3()));

                if (item8 != 0)
                {

                    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((BGSSaveFormBuffer_Write*)buffer)))->FUN_00865df0((::fnv_00865df0::TESForm *)(item8), 0);

                    count7 = count7 + 1;
                }

                list9 = (BSSimpleList<TESObjectREFR*>*)reinterpret_cast<::Callees *>((list9))->FUN_00726070();
            }

            reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count7, offsetVal);

            count9 = 0;

            offset4 = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();

            list4 = &(*reinterpret_cast<::BSSimpleList< ::TESObjectREFR *> *>(&::g_011cace8));

            while (list4 != 0)
            {

                item6 = (TESObjectREFR*)*((int *)(new ((void *)(list4)) ::Vec3()));

                if (item6 != 0)
                {

                    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((BGSSaveFormBuffer_Write*)buffer)))->FUN_00865df0((::fnv_00865df0::TESForm *)(item6), 0);

                    count9 = count9 + 1;
                }

                list4 = (BSSimpleList<TESObjectREFR*>*)reinterpret_cast<::Callees *>((list4))->FUN_00726070();
            }

            reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(count9, offset4);
        }
    }

    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::RecursiveSpinLock *>(&::g_011cacf8))))->WaitForTasksDuringRendering();
}

struct ScriptCompareOwner : public Script
{
    bool IsDifferentFrom(Script* apOther);
};

// @fnv 0x005ab240
bool ScriptCompareOwner::IsDifferentFrom(Script* apOther)
{
    unsigned int i8;
    BSSimpleList<ScriptReferencedObject*>* pOtherIter7;
    ScriptHeaderData* pHeader;
    char* pData6;
    BSSimpleList<ScriptReferencedObject*>* kPIter;
    ScriptReferencedObject* pOtherRef8;
    ScriptReferencedObject* pRef;
    if (!apOther)
        return true;
    pHeader = ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>((apOther))->GetConditions()));
    if (m_kHeader.dataSize != pHeader->dataSize)
        return true;
    if (m_kHeader.m_uiReferenceID != pHeader->m_uiReferenceID)
        return true;
    if (m_kHeader.m_bCompiled != pHeader->m_bCompiled)
        return true;
    pData6 = apOther->GetData();
    for (i8 = 0; i8 < m_kHeader.dataSize; i8++)
    {
        if (m_data[i8] != pData6[i8])
            return true;
    }
    if (((char *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())) && ((char *)(reinterpret_cast<::BGSMessageInitAccess *>((apOther))->GetIconFormID())))
    {
        if (strlen(((char *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))) != strlen(((char *)(reinterpret_cast<::BGSMessageInitAccess *>((apOther))->GetIconFormID()))))
            return true;
        else if (::FUN_00469880((void *)((const unsigned char*)((char *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID()))), (void *)((const unsigned char*)((char *)(reinterpret_cast<::BGSMessageInitAccess *>((apOther))->GetIconFormID())))))
            return true;
    }
    else if (((char *)(reinterpret_cast<::BGSMessageInitAccess *>(this)->GetIconFormID())) || ((char *)(reinterpret_cast<::BGSMessageInitAccess *>((apOther))->GetIconFormID())))
        return true;
    pOtherIter7 = ((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apOther))->FUN_005d43c0()));
    kPIter = ((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (pOtherIter7 && kPIter)
    {
        pRef = ((::ScriptReferencedObject *)(new ((void *)(kPIter)) ::Vec3()));
        pOtherRef8 = ((::ScriptReferencedObject *)(new ((void *)(pOtherIter7)) ::Vec3()));
        if (pOtherRef8 && pRef && pOtherRef8->pForm != pRef->pForm)
            return true;
        pOtherIter7 = ((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::Callees *>((pOtherIter7))->FUN_00726070()));
        kPIter = ((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::Callees *>((kPIter))->FUN_00726070()));
    }
    return false;
}

struct FUN_00501c10_s
{
};

namespace ns5a {
struct FUN_005ab8b0
{
    BSStringT<char> name;
    int unk;
    int unk0C;
    FUN_005ab8b0(const FUN_005ab8b0& src);
};
}

// @fnv 0x005ab8b0
ns5a::FUN_005ab8b0::FUN_005ab8b0(const FUN_005ab8b0& src)
{
    reinterpret_cast<::FUN_00501c10_cls *>((((FUN_00501c10_s*)this)))->CallAndReturnSelf((int)(&src));
    unk = src.unk;
    unk0C = src.unk0C;
}

struct ScriptResolve : Script
{
};
struct RefRead : TESObjectREFR
{
};
struct ExtraRead : ExtraDataList
{
};
struct InventoryRead : TESObjectREFR
{
};
// @fnv 0x005ac7a0
bool ReadScriptValue(double* value, const char* data, unsigned int* offset, TESObjectREFR* reference,
                     TESObjectREFR* container, Script* script, ScriptLocals* locals, bool skip)
{
    ScriptLocals* a;
    ScriptReferencedObject* p;
    char h;
    short i;
    TESQuest* s;
    RefRead* f;
    TESObjectREFR* eb;
    InventoryStackRecord* cf;
    ScriptFunctionInfo* q;
    int b;
    RefRead* ba;
    ScriptParameter* k;
    FNVScriptExecuteFunction l;
    short c;
    unsigned int e;
    a = locals;
    if (!a)
        return false;
    p = 0;
    if (skip && reinterpret_cast<::TESForm *>((void *)(script))->GetInitialized())
        skip = false;
    h = data[*offset];
    *offset += 1;
    switch (h)
    {
    case 'G':
    case 'Z':
    case 'r': {
        i = *(short*)(data + *offset);
        *offset += 2;
        p = reinterpret_cast<::fnv_005ac4f0::FUN_005ac4f0_shell *>((((ScriptResolve*)script)))->GetNthRefByIndex(i, locals);
        if (p)
        {
            if (p->pForm || skip)
            {
                if (h == 'G')
                {
                    *value = reinterpret_cast<::FUN_00526ac0_shell *>((((TESGlobalValueReader*)p->pForm)))->FUN_00526ac0();
                    return true;
                }
                else if (h == 'Z')
                {
                    e = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((p->pForm))->FUN_0084e3a0()));
                    ::Script::CopyIdentifierBitsToValue((*(const unsigned int *)(&e)), (*(double *)(value)));
                    return true;
                }
                else
                {
                    h = data[*offset];
                    *offset += 1;
                    if (h != 'X')
                    {
                        s = 0;
                        if (p->pForm && p->pForm->GetFormType() == 0x47)
                            s = (TESQuest*)p->pForm;
                        if (s)
                            a = s->GetScriptLocalData();
                        else
                        {
                            f = 0;
                            if (p->pForm)
                            {
                                switch (p->pForm->GetFormType())
                                {
                                case 0x3a:
                                case 0x3b:
                                case 0x3c:
                                case 0x3d:
                                case 0x3e:
                                case 0x3f:
                                case 0x40:
                                case 0x69:
                                    f = (RefRead*)p->pForm;
                                    break;
                                }
                            }
                            if (f)
                            {
                                if (reinterpret_cast<::FUN_0041c8d0_shell *>((((ExtraRead*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((f))->FUN_005d43c0())))))->FUN_0041c8d0())
                                {
                                    eb = reinterpret_cast<::FUN_0041c8d0_shell *>((((ExtraRead*)((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((f))->FUN_005d43c0())))))->FUN_0041c8d0();
                                    cf = ((::InventoryStackRecord *)(reinterpret_cast<::fnv_00576260::FUN_00576260_shell *>((((InventoryRead*)eb)))->FUN_00576260((::fnv_00576260::TESBoundObject *)(::TESBoundObject *)(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((f))->FUN_007af430()))), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((f))->FUN_0084e3a0())))));
                                    if (cf)
                                        a = reinterpret_cast<::ItemChangeShell *>((cf))->FUN_004bdea0();
                                    delete cf;
                                }
                                else
                                    a = reinterpret_cast<::FUN_005673e0_shell *>((f))->FUN_005673e0();
                            }
                        }
                        if (!a)
                            return false;
                    }
                }
            }
            else
            {
                if (p->m_uiFormID)
                {
                    *value = 0.0;
                    return true;
                }
                else
                    return false;
            }
        }
        else
            return false;
        break;
    }
    case 'n':
        *value = *(int*)(data + *offset);
        *offset += 4;
        return true;
    case 'z':
        ::__memcpy(value, data + *offset, 8);
        *offset += 8;
        return true;
    }
    if (h == 'X')
    {
        b = *(short*)(data + *offset);
        *offset += 2;
        *offset += 2;
        q = ::GetFunctionByOpcode((::SCRIPT_OUTPUT)(b));
        if (!q)
            return false;
        else
        {
            ba = (RefRead*)reference;
            if (p && p->pForm)
            {
                ba = 0;
                if (p->pForm)
                {
                    switch (p->pForm->GetFormType())
                    {
                    case 0x3a:
                    case 0x3b:
                    case 0x3c:
                    case 0x3d:
                    case 0x3e:
                    case 0x3f:
                    case 0x40:
                    case 0x69:
                        ba = (RefRead*)p->pForm;
                        break;
                    }
                }
            }
            k = q->pParameters;
            if (skip)
            {
                if (k)
                    ::FUN_005accb0((const ::ExtractParameter *)(k), data, offset, ba, container, (::ExtractScript *)(script), locals);
            }
            else
            {
                if (!q->m_bRequiresReference || (q->m_bRequiresReference && ba))
                {
                    l = q->m_pfnExecute;
                    if (l && l(k, data, ba, container, script, locals, *value, *offset))
                        return true;
                    else
                        return false;
                }
            }
        }
    }
    else
    {
        c = *(short*)(data + *offset);
        *offset += 2;
        switch (h)
        {
        case 'f':
        case 'l':
        case 's':
            *value = reinterpret_cast<::FUN_005a9140_shell *>((a))->FUN_005a9140(c, script);
            return true;
        default:
            return false;
        }
    }
    return false;
}

struct ExtractParameter
{
    const char* name;
    unsigned int type;
    bool optional;
};
struct ExtractScript
{
};
struct ExtractForm
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual bool IsReference();
    int FUN_00401170();
};
extern const char extractUnimplemented[];
// @fnv 0x005accb0
bool __cdecl FUN_005accb0(const ExtractParameter* parameters, const char* data, unsigned int* offset,
                          TESObjectREFR* reference, TESObjectREFR* container, ExtractScript* script,
                          ScriptLocals* locals, ...)
{
    if (!parameters)
        return false;
    va_list args2;
    va_start(args2, locals);
    short count = *reinterpret_cast<const short*>(data + *offset);
    *offset += 2;
    short index;
    for (index = 0; index < count; ++index)
    {
        if (DAT_0118cdd0[parameters[index].type].isReference)
        {
            if (data[(*offset)++] != 'r')
                return false;
            short refIndex3 = *reinterpret_cast<const short*>(data + *offset);
            *offset += 2;
            ScriptReferencedObject* ref = reinterpret_cast<::fnv_005ac4f0::FUN_005ac4f0_shell *>((script))->GetNthRefByIndex(refIndex3, locals);
            if (reinterpret_cast<::TESForm *>((script))->GetInitialized() && ref && ref->pForm)
            {
                bool valid = false;
                switch (parameters[index].type)
                {
                case 3: {
                    if (::TESContainer::IsValidContainerType(reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170()))
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = 0;
                        if (ref->pForm && reinterpret_cast<ExtractForm*>(ref->pForm)->IsReference())
                            *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 50: {
                    if (::TESContainer::IsValidContainerType(reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170()) ||
                        reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 85)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 53: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm && (reinterpret_cast<ExtractForm*>(ref->pForm)->IsReference() ||
                                       reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 85))
                        *formOutput = ref->pForm;
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 4:
                case 24:
                case 26: {
                    switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                    {
                    case 58:
                    case 59:
                    case 60:
                    case 61:
                    case 62:
                    case 63:
                    case 64:
                    case 105: {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = 0;
                        if (ref->pForm)
                        {
                            switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                            {
                            case 58:
                            case 59:
                            case 60:
                            case 61:
                            case 62:
                            case 63:
                            case 64:
                            case 105:
                                *formOutput = ref->pForm;
                                break;
                            }
                        }
                        if (*formOutput)
                            valid = true;
                    }
                    break;
                    }
                }
                break;
                case 6: {
                    switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                    {
                    case 59:
                    case 60: {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                    break;
                    }
                }
                break;
                case 9: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 57)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 27: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 65)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 7: {
                    SpellItem** spellOutput = va_arg(args2, SpellItem**);
                    *spellOutput = dynamic_cast<SpellItem*>(ref->pForm);
                    if (*spellOutput)
                        valid = true;
                    else
                    {
                        TESObjectBOOK* book = 0;
                        if (ref->pForm && reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 25)
                            book = reinterpret_cast<TESObjectBOOK*>(ref->pForm);
                        *spellOutput = reinterpret_cast<SpellItem*>(book);
                        if (book && ((::EnchantmentItem *)(reinterpret_cast<::Callees *>(&(book->enchantable))->FUN_00726070())))
                            valid = true;
                    }
                }
                break;
                case 11: {
                    MagicItem** formOutput = va_arg(args2, MagicItem**);
                    *formOutput = dynamic_cast<MagicItem*>(ref->pForm);
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 31: {
                    EffectSetting** formOutput = va_arg(args2, EffectSetting**);
                    *formOutput = dynamic_cast<EffectSetting*>(ref->pForm);
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 12: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 13)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 54: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 102)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 13: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 69)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 14: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 71)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 15: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 12)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 47: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 97)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 16: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 7)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 17: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 8)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 62: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 104)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 65: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 113)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 63: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 109)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 64: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 108)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 66: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 116)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 67: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 115)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 68: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 117)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 69: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 55)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 19: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 6)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 20: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 39 ||
                        reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 85)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 21: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm && reinterpret_cast<ExtractForm*>(ref->pForm)->IsReference())
                        *formOutput = ref->pForm;
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 25: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                        {
                        case 42:
                        case 43:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 29: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 73)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 30: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 74)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 33: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 53)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 42: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 84)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 43: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 83)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 34: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 42)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 35: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                        {
                        case 42:
                            *formOutput = ref->pForm;
                            break;
                        case 8:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 36: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 79)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 37: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 85)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 38: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 5)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 39: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 86)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 40: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 49)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 49: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 98)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 56: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                        {
                        case 42:
                            *formOutput = ref->pForm;
                            break;
                        case 45:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 57: {
                    TESForm** formOutput = va_arg(args2, TESForm**);
                    *formOutput = 0;
                    if (ref->pForm)
                    {
                        switch (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170())
                        {
                        case 43:
                            *formOutput = ref->pForm;
                            break;
                        case 44:
                            *formOutput = ref->pForm;
                            break;
                        }
                    }
                    if (*formOutput)
                        valid = true;
                }
                break;
                case 58: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 45)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 59: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 44)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 60: {
                    if (reinterpret_cast<ExtractForm*>(ref->pForm)->FUN_00401170() == 52)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                case 61: {
                    if (ref->pForm)
                    {
                        TESForm** formOutput = va_arg(args2, TESForm**);
                        *formOutput = ref->pForm;
                        if (*formOutput)
                            valid = true;
                    }
                }
                break;
                default:
                    ::FUN_005b5e40();
                    return false;
                }
                if (!valid)
                    return false;
            }
            else
                return false;
        }
        else
        {
            switch (parameters[index].type)
            {
            case 0: {
                short length = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (reinterpret_cast<::TESForm *>((script))->GetInitialized())
                {
                    char* textOutput = va_arg(args2, char*);
                    memcpy(textOutput, data + *offset, length);
                    textOutput[length] = 0;
                }
                *offset += length;
            }
            break;
            case 1:
            case 23: {
                double value = 0.0;
                if (::ReadScriptValue(&value, data, offset, reference, container, (::Script *)(script), locals, true))
                {
                    if (reinterpret_cast<::TESForm *>((script))->GetInitialized())
                    {
                        int* intOutput = va_arg(args2, int*);
                        *intOutput = (int)value;
                    }
                }
                else
                    return false;
            }
            break;
            case 2: {
                double value = 0.0;
                if (::ReadScriptValue(&value, data, offset, reference, container, (::Script *)(script), locals, true))
                {
                    if (reinterpret_cast<::TESForm *>((script))->GetInitialized())
                    {
                        float* floatOutput = va_arg(args2, float*);
                        *floatOutput = (float)value;
                    }
                }
                else
                    return false;
            }
            break;
            case 8: {
                if (reinterpret_cast<::TESForm *>((script))->GetInitialized())
                {
                    char* byteOutput = va_arg(args2, char*);
                    *byteOutput = data[*offset];
                }
                *offset += 1;
            }
            break;
            case 5:
            case 41:
            case 51:
            case 52:
            case 55: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (reinterpret_cast<::TESForm *>((script))->GetInitialized())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            case 28: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (reinterpret_cast<::TESForm *>((script))->GetInitialized())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            case 10: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (reinterpret_cast<::TESForm *>((script))->GetInitialized())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            case 32: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (reinterpret_cast<::TESForm *>((script))->GetInitialized())
                {
                    char* byteOutput = va_arg(args2, char*);
                    *byteOutput = (char)value;
                }
            }
            break;
            case 18: {
                short value = *reinterpret_cast<const short*>(data + *offset);
                *offset += 2;
                if (reinterpret_cast<::TESForm *>((script))->GetInitialized())
                {
                    int* intOutput = va_arg(args2, int*);
                    *intOutput = value;
                }
            }
            break;
            default:
                return false;
            }
        }
    }
    va_end(args2);
    return true;
}

extern int DAT_011cad40;
extern float DAT_011cad20[8];

struct S4eb0_flag
{
    unsigned char pad[0x10];
    bool b10;
};

struct S4eb0_list
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};


struct Scr : TESForm
{
    char pad18[4];
    unsigned int m_uiReferenceID;
    unsigned int dataSize;
    char pad24[0xc];
    char* m_data;
    float m_fValueAtOffset34;
    float fValueAtOffset38;
    float fQuestScriptBuffer;
    TESQuest* m_pOwnerQuest;

    void FUN_00484ab0(bool initialized);
    void FUN_005ab400(TESForm* form);
};
// @fnv 0x005ab7d0
void Script::InitItem()
{
    reinterpret_cast<::Scr *>(this)->FUN_005ab400(this);
}

// @fnv 0x005ab400
void Scr::FUN_005ab400(TESForm* form)
{
    if (reinterpret_cast<::TESForm *>(this)->GetInitialized() || form == 0)
        return;
    AutoMemContext saveCtx((MEM_CONTEXT)21, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESScript.cpp", 0xab5);
    if (form != this && reinterpret_cast<::FUN_004077c0_shell *>((void *)this)->FUN_004077c0())
    {
        SetFile(form->GetFile(-1));
    }
    int num = 0;
    S4eb0_list* iter = ((::S4eb0_list *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    S4eb0_list* pPrev = 0;
    TESFile* pTemp = form ? form->GetFile(-1) : 0;
    while (iter && !iter->FUN_008256d0())
    {
        ScriptReferencedObject* refTmp = *((::ScriptReferencedObject **)(new ((void *)(iter)) ::Vec3()));
        TESForm* form7 = refTmp->pForm;
        unsigned int idB = refTmp->m_uiFormID;
        bool ok3 = false;
        if (form7)
        {
            ::ResolveFormID((unsigned int *)(::TESForm **)(&form7), pTemp);
            refTmp->pForm = ::FUN_004839c0((unsigned int)(form7));
            if (refTmp->pForm)
                ok3 = true;
        }
        else if (idB)
        {
            ok3 = true;
        }
        if (ok3)
        {
            pPrev = iter;
            iter = ((::S4eb0_list *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        }
        else
        {
            if (pPrev)
            {
                reinterpret_cast<::ItemChangeListNode *>((pPrev))->FUN_00905330((*(::InventoryStackRecord *const *)(((::ScriptReferencedObject **)(new ((void *)(iter)) ::Vec3())))));
                iter = ((::S4eb0_list *)(reinterpret_cast<::Callees *>((pPrev))->FUN_00726070()));
            }
            else
            {
                iter->FUN_0063f7b0();
            }
            if (form7)
            {
                ::FUN_005b5e40(
                    );
            }
            else
            {
                ::FUN_005b5e40(
                    );
            }
            dataSize = 0;
        }
        num++;
    }
    if (num != m_uiReferenceID && dataSize != 0)
    {
        ::FUN_005b5e40(
            );
        dataSize = 0;
    }
    if (m_data)
        reinterpret_cast<::TESForm *>(this)->ClearData();
    if (((::S4eb0_flag *)(reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()))->b10)
    {
        if (((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cac68))))))->f > 0.0)
        {
            float t = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cac68))))))->f;
            if (DAT_011cad40 == 0)
            {
                for (int j = 0; j < 8; j++)
                {
                    t = t / 2.0;
                    DAT_011cad20[j] = t;
                }
            }
            int mask3 = DAT_011cad40 & 0xff;
            int k = 0;
            if (m_pOwnerQuest != 0 && reinterpret_cast<::FUN_00792760_shell *>((m_pOwnerQuest))->FUN_00792760() > 0.0)
            {
                fValueAtOffset38 = 0.0f;
            }
            else if (mask3 == 0)
            {
                fValueAtOffset38 = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011cac68))))))->f;
            }
            else
            {
                while (mask3)
                {
                    if (mask3 & 1)
                        fValueAtOffset38 += DAT_011cad20[k];
                    k++;
                    mask3 >>= 1;
                }
            }
            DAT_011cad40++;
        }
    }
    if (form->GetFormType() == 0x47)
        m_pOwnerQuest = (TESQuest*)form;
    SetInitializationState(true);
}

struct SavedFormHeader
{
    unsigned int formID;
    unsigned char formType;
    unsigned char flagsLow, flagsByte1, flagsByte2, flagsByte3;
    unsigned char version;
};
struct ScriptSaveReader : TESSaveLoadGame
{
};
struct LoadScriptLocals : ScriptLocals
{
    void FUN_005a9950();
};
// Reads script locals from the save stream, handling version 117+ reference encoding and optional extended locals, then verifies the block size.
// @fnv 0x005a9950
void LoadScriptLocals::FUN_005a9950()
{
    unsigned short a = 0;
    unsigned int i = 0;
    unsigned short s;
    unsigned char h;
    int p;
    if (reinterpret_cast<::FUN_00862110_cls *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_00862110())
    {
        unsigned int blockTag;
        reinterpret_cast<::FUN_008579e0_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008579e0(&blockTag, 4);
        if (blockTag != 0x424c4f4b)
        {
            SavedFormHeader* header = ((::SavedFormHeader *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((ScriptSaveReader*)::g_TESSaveLoadGame)))));
            if (header)
            {
                TESForm* form = ::FUN_004839c0(header->formID);
                ::FUN_005b5e40(
                    );
            }
            else
            {
                ::FUN_005b5e40(
                    );
            }
        }
        i = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_00825c00();
        reinterpret_cast<::FUN_008579e0_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008579e0(&a, 2);
    }
    reinterpret_cast<::FUN_008579e0_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008579e0(&s, 2);
    for (p = 0; p < s; p++)
    {
        unsigned int i = 0;
        double p = 0.0;
        if (reinterpret_cast<::FUN_008df040_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008df040() >= 117)
        {
            reinterpret_cast<::FUN_008579e0_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008579e0(&i, 4);
            if (i & 0x80000000)
            {
                i &= 0x7fffffff;
                unsigned int refID;
                reinterpret_cast<::FUN_00857aa0 *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->ValidateFormIDArray(&refID, 4);
                ::Script::CopyIdentifierBitsToValue(refID, p);
            }
            else
            {
                reinterpret_cast<::FUN_008579e0_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008579e0(&p, 8);
            }
        }
        if (reinterpret_cast<::FUN_008df040_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008df040() < 117)
        {
            reinterpret_cast<::FUN_008579e0_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008579e0(&i, 4);
            reinterpret_cast<::FUN_008579e0_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008579e0(&p, 8);
        }
        reinterpret_cast<::FUN_005a9290_shell *>(this)->SetScriptVariable(i, p);
    }
    reinterpret_cast<::FUN_008579e0_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008579e0(&h, 1);
    if (h)
    {
        m_pExtendedLocals = (ScriptDefinition*)new double;
        reinterpret_cast<::FUN_008579e0_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_008579e0(m_pExtendedLocals, 8);
    }
    if (reinterpret_cast<::FUN_00862110_cls *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_00862110())
    {
        unsigned int s = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((ScriptSaveReader*)::g_TESSaveLoadGame)))->FUN_00825c00();
        SavedFormHeader* h = ((::SavedFormHeader *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((ScriptSaveReader*)::g_TESSaveLoadGame)))));
        if (h)
        {
            TESForm* form = ::FUN_004839c0(h->formID);
            if (s > i + a)
                ::FUN_005b5e40(
                    );
            else if (s < i + a)
                ::FUN_005b5e40(
                    );
        }
        else
        {
            if (s > i + a)
                ::FUN_005b5e40();
            else if (s < i + a)
                ::FUN_005b5e40();
        }
    }
}

namespace fnv_005aa350 {
struct TlsSlot
{
    char pad[0x24F0];
    void* pCached;
};

struct ItemX
{
};
struct ListX
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};
struct ClsX
{
    void FUN_005aa350();
};


// Clears the TLS cached pointer if it points to this object, then iterates the list from FUN_005d43c0 and calls FUN_005aa3f0(1) on each item.
// @fnv 0x005aa350
void ClsX::FUN_005aa350()
{
    if ((*reinterpret_cast<::fnv_005aa350::TlsSlot *>(&::DAT_0126fd98)).pCached == this)
        (*reinterpret_cast<::fnv_005aa350::TlsSlot *>(&::DAT_0126fd98)).pCached = 0;
    ListX* pList = ((::fnv_005aa350::ListX *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    while (pList != 0 && !pList->FUN_008256d0())
    {
        ItemX* b = *((::fnv_005aa350::ItemX **)(new ((void *)(pList)) ::Vec3()));
        ItemX* pItem = b;
        // the result is discarded but stays in an implicit temp (VM /Od slot layout)
        (void)(pItem ? reinterpret_cast<::fnv_005aa3f0::p07::DelStandIn *>((pItem))->FUN_005aa3f0(1) : 0);
        pList->FUN_0063f7b0();
    }
}
}  // namespace fnv_005aa350
