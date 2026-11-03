
// src/staging/blk_00900000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include <cstddef>
#include <new>
#include <cstring>
#include "fnv/symbols_0043b000.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00438b90_class.h"
#include "fnv/decl/FUN_0044de20_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00529000_cls.h"
#include "fnv/decl/FUN_006b8310_class.h"
#include "fnv/decl/FUN_006e3c90_cls.h"
#include "fnv/decl/FUN_006e3d30_cls.h"
#include "fnv/decl/FUN_006ebde0_shell.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_009055c0.h"
#include "fnv/decl/FUN_009060f0_shell.h"
#include "fnv/decl/FUN_009a3910_cls.h"
#include "fnv/decl/MapMarkerData.h"
#include "fnv/decl/NP_0092c820.h"
#include "fnv/decl/QueuedMap.h"
#include "fnv/decl/SearchWorker.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TSMap.h"
#include "fnv/decl/TaskProcessor.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00906af0__QueueWalker.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0044c000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_006e6000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01202000.h"
#include "../../include/layout_support.h"

extern int DAT_01088438;

struct FUN_00905670_Class
{
    void SetVTable();
};

// @fnv 0x00905670
void FUN_00905670_Class::SetVTable()
{
    *(const void**)this = &DAT_01088438;
}

extern int DAT_010159d4;

struct GlobalObject_00869f00
{
    int* m_p;
    void Clear(bool);
    void InitFromGlobal_00905910();
};

void GlobalObject_00869f00::Clear(bool)
{}

// @fnv 0x00905910
void GlobalObject_00869f00::InitFromGlobal_00905910()
{
    m_p = &DAT_010159d4;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

extern "C" void __cdecl FUN_009059f0();
extern void* DAT_01088418;

struct FUN_00905990_Class
{
    void** vtbl;
    int field_4;
    void FUN_009059f0();
    FUN_00905990_Class();
};

extern int DAT_01088438;

struct FUN_009059f0_Class
{
    int* pVftable;
    FUN_009059f0_Class();
};
// Calls FUN_009059f0, sets the vtable pointer to DAT_01088418 and initializes field_4 to 0.
// @fnv 0x00905990
FUN_00905990_Class::FUN_00905990_Class()
{
    new ((void *)this) ::FUN_009059f0_Class();
    vtbl = &DAT_01088418;
    field_4 = 0;
}

// @fnv 0x009059f0
FUN_009059f0_Class::FUN_009059f0_Class()
{
    pVftable = (int*)&DAT_01088438;
}

namespace p07 {
struct DelStandIn
{
    void* Destroy(unsigned int);
    void* FUN_00905ae0();
};
}

// @fnv 0x00905ae0
void* p07::DelStandIn::FUN_00905ae0()
{
    return Destroy(0);
}

extern "C" void __cdecl DAT_01088640();

struct FUN_00906110_Class
{
    void FUN_00906110();
};

// @fnv 0x00906110
void FUN_00906110_Class::FUN_00906110()
{
    *reinterpret_cast<void**>(this) = &DAT_01088640;
}

extern int DAT_01088fd4;
struct FUN_00913810_t
{
    void FUN_00913810(int a);
};
struct FUN_009137b0_t
{
    int* m;
    FUN_009137b0_t* Construct(int a);
};
struct FUN_00913980_StandIn
{
    void* FUN_00913980(unsigned int flags);
};

struct QHeadPtr
{
};
struct FUN_009157c0
{
    QHeadPtr m;
    void Method();
};
// @fnv 0x009157c0
void FUN_009157c0::Method()
{
    ::FUN_0044cbf0((void **)(((QHeadPtr*)((char*)this + 0x14))));
}

struct PathingAvoidanceNode
{
    int a, b, c, d, e, f, g, h, i;
};
struct FUN_00905a10_StandIn
{
    unsigned int GetNextIndex();
};
struct BSSimpleArray_PathingAvoidNode_1024
{
};
struct FUN_00905450_StandIn
{
    int m_iArrayLength;
    PathingAvoidanceNode* m_pData;
    unsigned int GetNextIndex();
    unsigned int AppendNode(PathingAvoidanceNode* pSrc);
};
struct Interface
{
};
struct FUN_00905510_Class
{
    void** vtbl;
    char LockAndCall(int a);
};
// Spins until the lock at this+1 is acquired, calls the virtual method at vtbl[6] with a, then releases the lock and returns its result.
// @fnv 0x00905510
char FUN_00905510_Class::LockAndCall(int aiArg)
{
    char r;
    while (true)
    {
        if (FUN_0043b460((long volatile*)(this + 1), 0, 1) == 0)
        {
            ::FUN_0040fbe0();
            r = ((char(*)(void*, int))vtbl[6])(this, aiArg);
            ::FUN_0040fbe0();
            FUN_0043b460((long volatile*)(this + 1), 1, 0);
            break;
        }
    }
    return r;
}

struct FUN_00905690_Class
{
    void FUN_00905650();
    void* FUN_00905690(unsigned int flags);
};

// @fnv 0x00905690
void* FUN_00905690_Class::FUN_00905690(unsigned int flags)
{
    FUN_00905650();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_009056c0_Class
{
    void* FUN_009056c0(unsigned int flags);
};

// @fnv 0x009056c0
void* FUN_009056c0_Class::FUN_009056c0(unsigned int flags)
{
    reinterpret_cast<::FUN_00905670_Class *>(this)->SetVTable();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_009055c0_Class
{
    void* FUN_00905930(unsigned int flags);
};
// @fnv 0x00905930
void* FUN_009055c0_Class::FUN_00905930(unsigned int flags)
{
    reinterpret_cast<::FUN_009055c0 *>(this)->FUN_009055c0::~FUN_009055c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00905960_Class
{
    void* FUN_00905960(unsigned int flags);
};
// @fnv 0x00905960
void* FUN_00905960_Class::FUN_00905960(unsigned int flags)
{
    ((GlobalObject_00869f00*)this)->InitFromGlobal_00905910();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00906130_Class
{
    void* FUN_00906130(unsigned int flags);
};
// Calls FUN_00906110 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00906130
void* FUN_00906130_Class::FUN_00906130(unsigned int flags)
{
    reinterpret_cast<FUN_00906110_Class*>(this)->FUN_00906110();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};
struct FUN_00449f80_Class
{
    void* FUN_00449f80(void* a, void* b, void* c, bool d);
};
struct FUN_0044d070_Class
{
};
struct FUN_009063b0_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    RecursiveSpinLock m_20;
    bool LockedCall(void* a, void* b, void* c, bool d);
};
// Locks m_20, calls FUN_00449f80 with the arguments, calls InsertOrReplace on the result, unlocks m_20 and returns its bool.
// @fnv 0x009063b0
bool FUN_009063b0_Class::LockedCall(void* apArg1, void* apArg2, void* apArg3, bool d)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_20))->FUN_0040fbf0((char *)(0));
    bool r = reinterpret_cast<::TSMap *>((reinterpret_cast<FUN_0044d070_Class*>(
                 reinterpret_cast<FUN_00449f80_Class*>(this)->FUN_00449f80(apArg1, apArg2, apArg3, d))))->InsertOrReplace({}, {}, *(const ::QHeadPtr *)nullptr, {});
    reinterpret_cast<::RecursiveSpinLock *>(&(m_20))->FUN_0040fba0();
    return r;
}

struct S5460
{
    virtual void v0();
    virtual void* v1(unsigned int);
    virtual void* v2(unsigned int);
    virtual void v3();
    virtual void v4();
    void* m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    unsigned int GetNextIndex();
};
// Appends a copy of the given node to the array and returns the index it was stored at.
// @fnv 0x00905450
unsigned int FUN_00905450_StandIn::AppendNode(PathingAvoidanceNode* apNode)
{
    unsigned int count = reinterpret_cast<::S5460 *>(this)->GetNextIndex();
    reinterpret_cast<::FUN_006e3c90_cls *>((((BSSimpleArray_PathingAvoidNode_1024*)this)))->ConstructSpawnedObjects((char *)(::PathingAvoidanceNode *)(&m_pData[count]), 1);
    *(PathingAvoidanceNode*)&m_pData[count] = *apNode;
    return count;
}
// @fnv 0x00905a10
unsigned int S5460::GetNextIndex()
{
    if (((bool)(reinterpret_cast<::FUN_00438b90_class *>(this)->FUN_00438b90())))
    {
        if (m_iThirdValue == 0)
        {
            unsigned int count = 4;
            m_iWordAt04 = v1(count);
            m_iThirdValue = count;
        }
        else
        {
            unsigned int idx = ((unsigned int)(reinterpret_cast<::FUN_009a3910_cls *>(this)->FUN_009a3910()));
            reinterpret_cast<::FUN_006e3d30_cls *>(this)->FUN_006e3d30(idx, m_8);
            m_iThirdValue = idx;
        }
    }
    ++m_8;
    return m_8 - 1;
}

struct _Base_00441d20
{
    ~_Base_00441d20();
};
struct FUN_00905c30 : _Base_00441d20
{
    ~FUN_00905c30();
};
// @fnv 0x00905c30
FUN_00905c30::~FUN_00905c30()
{}

struct FUN_00906690_t
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    char m_iThirdValue;
    FUN_00906690_t();
};
// @fnv 0x00906690
FUN_00906690_t::FUN_00906690_t()
{
    m_iWordAt00 = (void*)&DAT_01088640;
    m_iWordAt04 = 0;
    m_8 = 0;
    m_iThirdValue = 0;
}

struct FUN_009064e0_Class
{
    void FUN_009064e0();
    void* FUN_009067f0(unsigned int flags);
};

struct GlobalObject_009137b0
{
    ~GlobalObject_009137b0();
    void* FUN_009137e0(unsigned int flags);
};
extern int DAT_01088ff4;
struct FUN_009138e0_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void FUN_009138e0();
};
// Calls FUN_009138e0, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x00913980
void* FUN_00913980_StandIn::FUN_00913980(unsigned int flags)
{
    reinterpret_cast<::FUN_009138e0_Class *>(this)->FUN_009138e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x009138e0
void FUN_009138e0_Class::FUN_009138e0()
{
    m_iWordAt00 = (void*)&DAT_01088ff4;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(m_8);
}

struct FUN_00913950_Class
{
    void* FUN_00913950(int a);
};

// @fnv 0x00913950
void* FUN_00913950_Class::FUN_00913950(int a)
{
    ((int*)this)[0] = 0;
    ((int*)this)[1] = 0;
    return this;
}

extern void* DAT_01088418;

// @fnv 0x00905650
void FUN_00905690_Class::FUN_00905650()
{
    *reinterpret_cast<void**>(this) = &DAT_01088418;
    reinterpret_cast<FUN_00905670_Class*>(this)->SetVTable();
}


struct SpawnedObject_b9530
{
    char m00[8];
    SpawnedObject_b9530(int a);
    static void* operator new(std::size_t size, void* heap)
    {
        return FUN_006e6da0(size, heap);
    }
    static void operator delete(void* p, void* heap)
    {}
};

struct FUN_00905b00_cls
{
    char m00[0x14];
    void ConstructSpawnedObject(intptr_t a);
};

// Calls FUN_00483710, then placement-constructs a SpawnedObject_b9530 at this from a.
// @fnv 0x00905b00
void FUN_00905b00_cls::ConstructSpawnedObject(intptr_t a)
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
    new (this) SpawnedObject_b9530(a);
}

struct FUN_00906400_Guard
{
    int m_iWordAt00;
    FUN_00906400_Guard(int a, int b, const char* file, int line);
    ~FUN_00906400_Guard();
};

struct FUN_00906400_Sub
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    FUN_00906400_Sub(void* owner, int* p0, int* p1, int* p2);
};

struct FUN_00906400_Owner
{
    int m_iWordAt00;
    int* m_iWordAt04;
    FUN_00906400_Sub* FUN_00906400(int a);
};

// @fnv 0x00906400
FUN_00906400_Sub* FUN_00906400_Owner::FUN_00906400(int aiIndex)
{
    FUN_00906400_Guard guard(6, 1, "d:\\_fallout3\\platforms\\common\\code\\bsmain\\ThreadSafeStructures.h", 0x18e);
    return new FUN_00906400_Sub(this, &m_iWordAt04[aiIndex * 3], &m_iWordAt04[aiIndex * 3 + 1],
                                &m_iWordAt04[aiIndex * 3 + 2]);
}

struct Request9065
{
    int unk00;
    unsigned int index;
    void* element;
};
struct Iterator9065
{
};
struct FUN_00906570_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    RecursiveSpinLock lock;
    Iterator9065* FUN_00449f80(unsigned int, void**, void*);
    bool AdvanceRequest(Request9065*, void**, void*, bool);
};
class NiTMapItem913;

class FUN_00913810
{
  public:
    FUN_00913810(unsigned int uiHashSize);
    virtual ~FUN_00913810();

    unsigned int m_uiHashSize;
    NiTMapItem913** m_ppkHashTable;
    unsigned int m_uiCount;
};
// Calls FUN_00913810 with a, sets m to point at DAT_01088fd4, and returns this.
// @fnv 0x009137b0
FUN_009137b0_t* FUN_009137b0_t::Construct(int a)
{
    new ((void *)(((FUN_00913810_t*)this))) ::FUN_00913810(a);
    m = &DAT_01088fd4;
    return this;
}

// Initializes the hash table: stores the hash size, zeroes the count, allocates the bucket array and clears it.
// @fnv 0x00913810
FUN_00913810::FUN_00913810(unsigned int uiHashSize)
{
    m_uiHashSize = uiHashSize;
    m_uiCount = 0;

    unsigned int uiSize = sizeof(NiTMapItem913*) * m_uiHashSize;
    m_ppkHashTable = (NiTMapItem913**)::FUN_00aa1070(uiSize);
    memset(m_ppkHashTable, 0, m_uiHashSize * sizeof(NiTMapItem913*));
}

// FUN_00913910 : thiscall, 1 stack argument (a pointer to an out-record).
// Builds a small two-dword local with an external constructor, copies it into
// the record and then hands the record to a helper that lives in the
// sub-object at offset 0x0c of this.

struct LocalPair
{
    int m_kPointA;
    int m_kPointB;
};

struct OutRecord
{
    int unk00;
    int unk04;
    LocalPair m_pair;
};

struct SubObject
{
};

class FUN_00913910_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    SubObject m_sub;
    void FUN_00913910(OutRecord* pOut);
};

// Initializes a LocalPair with 0, copies it into pOut->m_pair, then calls m_sub.FreeMemory(pOut).
// @fnv 0x00913910
void FUN_00913910_cls::FUN_00913910(OutRecord* pOut)
{
    LocalPair local;
    reinterpret_cast<::FUN_00913950_Class *>(&(local))->FUN_00913950(0);
    pOut->m_pair = local;
    reinterpret_cast<::FUN_006b8310_class *>(&(m_sub))->FreeMemory(pOut);
}

struct QHeadPtrDest
{
};

struct SubItem
{
    void* unk0;
    QHeadPtr headPtr;
    bool FUN_0044df20();
};

struct Member14_18
{
    int unk;
    SubItem* FUN_0044df00();
};

struct OwnerClass
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(void*, void**);
};


struct TargetClass
{
    OwnerClass* field_0;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Member14_18 m_14;
    Member14_18 m_18;


    bool FUN_00906c10(int a, void** b, QHeadPtrDest* c);
};
// @fnv 0x00906570
bool FUN_00906570_Class::AdvanceRequest(Request9065* request, void** ppOut, void* context, bool repeat)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool success = false;
    if (reinterpret_cast<::FUN_006ebde0_shell *>((request))->FUN_006ebde0())
    {
        success = false;
    }
    else
    {
        while (true)
        {
            if (!reinterpret_cast<::FUN_0044de20_cls *>((request))->IsFlagSet())
            {
                success = reinterpret_cast<::fnv_00906af0::QueueWalker *>((FUN_00449f80(request->index, &request->element, context)))->ProcessEntry({}, {}, {});
                reinterpret_cast<::MapMarkerData *>((request))->SetVisible(true);
            }
            else
            {
                success = reinterpret_cast<::TargetClass *>((FUN_00449f80(request->index, &request->element, context)))->FUN_00906c10({}, {}, {});
            }
            if (!success)
            {
                request->index = request->index + 1;
                if (request->index >= ((uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())))
                    reinterpret_cast<::MapMarkerData *>((request))->SetTravelLocation(true);
                else if (repeat)
                {
                    reinterpret_cast<::MapMarkerData *>((request))->SetVisible(false);
                    continue;
                }
            }
            else
            {
                *ppOut = request->element;
            }
            break;
        }
    }
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return success;
}

// @fnv 0x00906c10
bool TargetClass::FUN_00906c10(int a, void** b, QHeadPtrDest* apHeadDest)
{
    bool bResult = false;
    while (true)
    {
        bResult = reinterpret_cast<::SearchWorker *>((this))->ProcessNode(a, (int)(std::uintptr_t)(*b));
        if (bResult)
        {
            if (::ClearLowBit((int *)&(this->m_18)))
            {
                if (this->m_18.FUN_0044df00()->FUN_0044df20())
                {
                    continue;
                }
                this->field_0->v12(this->m_18.FUN_0044df00()->unk0, b);
                reinterpret_cast<::NP_0092c820 *>((apHeadDest))->FUN_0092c820((const ::NP_0092c820 &)(this->m_18.FUN_0044df00()->headPtr));
                bResult = true;
                FUN_0040fbe0();
                if (this->m_18.FUN_0044df00()->FUN_0044df20())
                {
                    reinterpret_cast<::FUN_006f74f0_cls *>((apHeadDest))->FUN_006f74f0((::ObjA *)(void *)(0));
                    continue;
                }
                break;
            }
            else
            {
                bResult = false;
                break;
            }
        }
        else
        {
            if (::ClearLowBit((int *)&(this->m_14)))
            {
                if (this->m_14.FUN_0044df00()->FUN_0044df20())
                {
                    continue;
                }
                this->field_0->v12(this->m_14.FUN_0044df00()->unk0, b);
                reinterpret_cast<::NP_0092c820 *>((apHeadDest))->FUN_0092c820((const ::NP_0092c820 &)(this->m_14.FUN_0044df00()->headPtr));
                bResult = true;
                FUN_0040fbe0();
                if (this->m_14.FUN_0044df00()->FUN_0044df20())
                {
                    reinterpret_cast<::FUN_006f74f0_cls *>((apHeadDest))->FUN_006f74f0((::ObjA *)(void *)(0));
                    continue;
                }
                break;
            }
            else
            {
                bResult = false;
                break;
            }
        }
    }
    reinterpret_cast<::FUN_00529000_cls *>((this))->FUN_00529000();
    return bResult;
}

struct BSSpinLockUnlock
{
};

struct FUN_00528bb0_Class
{
    bool FUN_00528bb0();
};

struct FUN_009062e0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BSSpinLockUnlock lock;
    void* FUN_00449f80(void*);
    bool FUN_009062e0(void* a);
};

// Locks the spin lock, calls FUN_00528bb0 on the object returned by FUN_00449f80(a), unlocks, and returns the result.
// @fnv 0x009062e0
bool FUN_009062e0_Class::FUN_009062e0(void* a)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool r = ((FUN_00528bb0_Class*)FUN_00449f80(a))->FUN_00528bb0();
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return r;
}

struct FUN_00528cb0_Guard
{
    int value;
    FUN_00528cb0_Guard(int value);
    ~FUN_00528cb0_Guard();
};
struct FUN_0044ac40_Service
{
};
struct FUN_00906050_Class
{
    virtual void v0();
    virtual void v1();
    virtual unsigned char v2(int value, FUN_00528cb0_Guard* guard);
    void FUN_00906050(intptr_t value);
};
// Creates a guard, calls v2 with the value and guard; if it succeeds, calls CallVirtual5 and passes the guard's flag result to DAT_01202d98.
// @fnv 0x00906050
void FUN_00906050_Class::FUN_00906050(intptr_t value)
{
    FUN_00528cb0_Guard guard(0);
    if (v2(value, &guard))
    {
        reinterpret_cast<::FUN_009060f0_shell *>(this)->CallVirtual5(value);
        reinterpret_cast<::TaskProcessor *>(((*reinterpret_cast<::FUN_0044ac40_Service * *>(&::DAT_01202d98))))->FUN_0044ac40((::QueuedTask *)(::FUN_00559450((int *)&(guard))), {});
    }
}

class MapBase913880
{
  public:
    virtual ~MapBase913880();
    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
    void RemoveAll();
};
class FUN_00913880 : public MapBase913880
{
  public:
    virtual ~FUN_00913880();
};
// Runs the destructor, then frees the object with _Deallocate when flags has bit 0 set, and returns the object pointer.
// @fnv 0x009137e0
void* GlobalObject_009137b0::FUN_009137e0(unsigned int flags)
{
    reinterpret_cast<::FUN_00913880 *>((this))->FUN_00913880::~FUN_00913880();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Removes all entries from the hash table before the object is destroyed.
// @fnv 0x00913880
FUN_00913880::~FUN_00913880()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}


struct _Base_009064e0
{
    virtual void unk00();
    ~_Base_009064e0();
};

struct FUN_009064e0 : _Base_009064e0
{
    void unk04(int flag);
    void* m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    ~FUN_009064e0();
};
// @fnv 0x009067f0
void* FUN_009064e0_Class::FUN_009067f0(unsigned int flags)
{
    reinterpret_cast<::FUN_009064e0 *>(this)->FUN_009064e0::~FUN_009064e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x009064e0
FUN_009064e0::~FUN_009064e0()
{
    reinterpret_cast<::QueuedMap *>(this)->FUN_00528e40(1);
    void* a = m_iThirdValue;
    FUN_00401030(a);
    void* b = m_iWordAt04;
    FUN_00401030(b);
}
