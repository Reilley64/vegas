
// src/fallout_shared/havok/testraplistener.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/testraplistener.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/ContOwner_620.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045c650_shell.h"
#include "fnv/decl/FUN_004a4960_class.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_00576830_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00620810_List.h"
#include "fnv/decl/FUN_00621c90_Class.h"
#include "fnv/decl/FUN_00622570_Class.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_0062d8a0.h"
#include "fnv/decl/FUN_0066db70_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Holder0057c400.h"
#include "fnv/decl/ImpactManager620.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00565870__FUN_00565870_shell.h"
#include "fnv/decl/fnv_0062a100__FUN_0062a100_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/s572e10__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_0069b000.h"
#include "fnv/symbols_0104e000.h"
#include "fnv/symbols_011dd000.h"
struct FUN_0062d2f0_shell
{
    void* GetOffset160();
};

// @fnv 0x0062d2f0
void* FUN_0062d2f0_shell::GetOffset160()
{
    return reinterpret_cast<char*>(this) + 0x160;
}

extern int DAT_0104e328;

struct hkpCdBodyPairCollector
{
    void FUN_0062d420();
};

// @fnv 0x0062d420
void hkpCdBodyPairCollector::FUN_0062d420()
{
    *(int*)this = (int)&DAT_0104e328;
}

struct bhkTrapListener
{
    void FUN_0062d760();
    void* DestroyIfFlagged(unsigned int);
};

void bhkTrapListener::FUN_0062d760()
{}

// Calls FUN_0062d760, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0062d6c0
void* bhkTrapListener::DestroyIfFlagged(unsigned int flags)
{
    FUN_0062d760();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_0062d740_shell
{
    int m_field;
    void FUN_0062d740();
};

// @fnv 0x0062d740
void FUN_0062d740_shell::FUN_0062d740()
{
    m_field = (int)&(*reinterpret_cast<int *>(&::DAT_0104e3d0));
}

struct CombatWorldStateListNode
{
    CombatWorldStateListNode* GetNext();
};

struct FUN_0062dee0_shell
{
    CombatWorldStateListNode* m_kNode;
    bool FUN_0062dee0(int arg);
};

// Walks the linked list at this+0x20 and returns true if any node's _ref_0084e3a0() equals arg.
// @fnv 0x0062dee0
bool FUN_0062dee0_shell::FUN_0062dee0(int arg)
{
    CombatWorldStateListNode* p = *(CombatWorldStateListNode**)((char*)this + 0x20);
    while (p)
    {
        if (reinterpret_cast<::FUN_0084e3a0_Class *>((p))->FUN_0084e3a0() == arg)
            return true;
        p = p->GetNext();
    }
    return false;
}

extern int DAT_0104e3f4;

struct FUN_0062e040_shell
{
    void FUN_0062e040();
};

// @fnv 0x0062e040
void FUN_0062e040_shell::FUN_0062e040()
{
    *(int*)this = (int)&DAT_0104e3f4;
}

struct FUN_0062c700_shell
{
    void FUN_0062c700();
};

struct FUN_0062dfe0_shell
{
    void FUN_0062dfe0();
};

struct FUN_0062d710_shell : FUN_0062d740_shell
{
    void* FUN_0062d710(unsigned int flags);
};

// Calls FUN_0062d740, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0062d710
void* FUN_0062d710_shell::FUN_0062d710(unsigned int flags)
{
    this->FUN_0062d740();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct TESTrapListener
{
    void* FUN_0062d870(unsigned int flags);
};

// Calls FUN_0062d8a0, frees this when flags has bit 0 set, and returns this.
// @fnv 0x0062d870
void* TESTrapListener::FUN_0062d870(unsigned int flags)
{
    reinterpret_cast<::FUN_0062d8a0 *>(this)->FUN_0062d8a0::~FUN_0062d8a0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0062e200_shell
{
    void* FUN_0062e200(unsigned int);
};

// @fnv 0x0062e200
void* FUN_0062e200_shell::FUN_0062e200(unsigned int flags)
{
    ((FUN_0062e040_shell*)this)->FUN_0062e040();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_0062e230_shell
{
    void* FUN_0062e230(unsigned int a, unsigned int b, unsigned int c);
};
// Calls FUN_004a4960 with the three arguments and returns this.
// @fnv 0x0062e230
void* FUN_0062e230_shell::FUN_0062e230(unsigned int a, unsigned int b, unsigned int c)
{
    reinterpret_cast<::FUN_004a4960_class *>(this)->FUN_004a4960((void *)(a), (void *)(b), c);
    return this;
}

struct BSSimpleList
{
    BSSimpleList* FUN_006207a0(BSSimpleList* target);
};
struct TESRaceForm
{
};
// @fnv 0x006207a0
BSSimpleList* BSSimpleList::FUN_006207a0(BSSimpleList* pHead)
{
    if (this == pHead)
        pHead = ((::BSSimpleList *)(reinterpret_cast<::Callees *>((this))->FUN_00726070()));
    else
    {
        BSSimpleList* current = pHead;
        while (current)
        {
            BSSimpleList* item = ((::BSSimpleList *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
            if (this == item)
            {
                reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)current)))->Initialize((::CombatController *)((unsigned int)((::BSSimpleList *)(reinterpret_cast<::Callees *>((item))->FUN_00726070()))));
                break;
            }
            current = item;
        }
    }
    return pHead;
}

struct FUN_0062c720_shell : FUN_0062c700_shell
{
    void* FUN_0062c720(unsigned int flags);
};
// @fnv 0x0062c720
void* FUN_0062c720_shell::FUN_0062c720(unsigned int flags)
{
    FUN_0062c700();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern int DAT_0104e308;
struct FUN_0062dfa0_shell
{
    void FUN_0062dfa0();
};
struct FUN_0062c750_shell : FUN_0062dfa0_shell
{
    void* vtbl;
    FUN_0062c750_shell();
};
// @fnv 0x0062c750
FUN_0062c750_shell::FUN_0062c750_shell()
{
    FUN_0062dfa0();
    vtbl = (void*)&DAT_0104e308;
}

struct FUN_0062c770_shell : FUN_0062dfe0_shell
{
    void* FUN_0062c770(unsigned int flags);
};
struct NiTPointerMap
{
};
struct Target062c980
{
    int field0;
    int field4;
    int field8;
    NiTPointerMap map;
    void ClearMap();
};
namespace fnv_0062cb60 {
struct NiTPointerMap
{
    void* RemoveFirstNode();
};
struct FUN_0062cb60_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    NiTPointerMap m_map;
    void* FUN_0062cb60();
};
// Returns null if m_map is empty, otherwise returns the result of m_map.RemoveFirstNode().
// @fnv 0x0062cb60
void* FUN_0062cb60_shell::FUN_0062cb60()
{
    if (::IsFieldCZero((::Dummy_0069b080 *)&(m_map)))
        return 0;
    return m_map.RemoveFirstNode();
}
}  // namespace fnv_0062cb60

struct InnerMember
{
};
struct MyCollector
{
    void* __vftable;
    InnerMember m_04;
    void FUN_0062d330();
    void* FUN_0062d3c0();
};
// Sets the vtable pointer, calls m_04._ref_006815c0(), then FUN_0062d330(), and returns this.
// @fnv 0x0062d3c0
void* MyCollector::FUN_0062d3c0()
{
    __vftable = (void*)&DAT_0104e328;
    FUN_0062d330();
    return this;
}

void __cdecl FUN_006210d0(void*);
struct FUN_0062d3f0_Standin : hkpCdBodyPairCollector
{
    void* FUN_0062d3f0(unsigned int);
};
// Calls FUN_0062d420, then if bit 0 of flags is set calls FUN_006210d0 on this, and returns this.
// @fnv 0x0062d3f0
void* FUN_0062d3f0_Standin::FUN_0062d3f0(unsigned int flags)
{
    FUN_0062d420();
    if (flags & 1)
        FUN_006210d0(this);
    return this;
}

struct S_62d4b0
{
    void FUN_0062d4b0();
};
void __cdecl FUN_0062d470(void*);
struct hkpAllCdBodyPairCollector : hkpCdBodyPairCollector
{
    void* FUN_0062d440(unsigned int);
};
struct TrigEntry
{
    int a;
    int b;
};
struct TrapHolder
{
    TrigEntry* arr;
    int cnt;
    bool FUN_0062d570(CombatWorldStateListNode* p);
};
// Returns true if the trigger id from p matches any entry's a field in arr, otherwise false.
// @fnv 0x0062d570
bool TrapHolder::FUN_0062d570(CombatWorldStateListNode* p)
{
    int ptriggers = reinterpret_cast<::FUN_0084e3a0_Class *>((p))->FUN_0084e3a0();
    {
        int i;
        for (i = 0; i < cnt; ++i)
        {
            if (ptriggers == arr[i].a)
                return true;
        }
    }
    return false;
}

struct FUN_0062d6f0_shell
{
    void* FUN_0062d6f0();
};

// @fnv 0x0062d6f0
void* FUN_0062d6f0_shell::FUN_0062d6f0()
{
    *reinterpret_cast<void**>(this) = &(*reinterpret_cast<int *>(&::DAT_0104e3d0));
    return this;
}

struct FUN_0062d550_shell
{
    bool ForwardToMember(int);
};
struct FUN_0062df60_shell
{
    FUN_0062d550_shell* FUN_0062df60(int);
};
struct FUN_0062df20_shell
{
    char _pad[32];
    FUN_0062df60_shell* m_32;
    bool FUN_0062df20(int a1, int a2);
};
// Looks up the entry for a2 via m_32 and returns whether it satisfies the check for a1, or false if not found.
// @fnv 0x0062df20
bool FUN_0062df20_shell::FUN_0062df20(int a1, int a2)
{
    FUN_0062d550_shell* t = m_32->FUN_0062df60(a2);
    if (!t)
        return false;
    return t->ForwardToMember(a1);
}

namespace fnv_0062df60 {
struct FUN_0057c400_shell
{
};
struct FUN_0062df60_shell
{
    void FUN_0062df60(unsigned int a);
};
// @fnv 0x0062df60
void FUN_0062df60_shell::FUN_0062df60(unsigned int a)
{
    reinterpret_cast<::Holder0057c400 *>((((FUN_0057c400_shell*)this)))->FUN_0057c400(a);
}
}  // namespace fnv_0062df60

struct FUN_0062df80_shell
{
    void FUN_0062df80();
};

struct FUN_0062e170_shell
{
    void FUN_0062e170();
};

struct Data62
{
    int a;
    int b;
    int c;
};
struct C62
{
    virtual void f0();
    virtual Data62* f1();
    void SetC(int* p);
};
struct CalleeObj
{
};
struct FUN_0062e120_shell
{
    int _pad;
    int _flag;
    void* FUN_0062e120(void*);
};
// Calls FUN_00622570 on the passed object with true when _flag is zero, then returns the object.
// @fnv 0x0062e120
void* FUN_0062e120_shell::FUN_0062e120(void* pObject)
{
    reinterpret_cast<::FUN_00622570_Class *>((((CalleeObj*)pObject)))->FUN_00622570(_flag == 0);
    return pObject;
}

struct Date
{
    ~Date();
};
struct FUN_0062e170 : Date
{
    void InitHelper();
    ~FUN_0062e170();
};
// @fnv 0x0062df80
void FUN_0062df80_shell::FUN_0062df80()
{
    reinterpret_cast<::FUN_0062e170 *>((reinterpret_cast<FUN_0062e170_shell*>(this)))->FUN_0062e170::~FUN_0062e170();
}
// Destructor that calls InitHelper before the base Date destructor runs.
// @fnv 0x0062e170
FUN_0062e170::~FUN_0062e170()
{
    InitHelper();
}

struct FUN_0062e1d0_shell : FUN_0062e230_shell
{
    void* FUN_0062e1d0(unsigned int a);
};
// Calls FUN_0062e230 on the object at offset 0xc with the given value and size 0x10, then returns this.
// @fnv 0x0062e1d0
void* FUN_0062e1d0_shell::FUN_0062e1d0(unsigned int auiValue)
{
    FUN_0062e230((unsigned int)(this + 0xc), auiValue, 0x10);
    return this;
}

struct FUN_0062e290_Node
{
    FUN_0062e290_Node* m_next;
};
struct FUN_0062e290_shell
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(FUN_0062e290_Node* p);
    FUN_0062e290_Node* m_iWordAt04;
    int m_8;
    int m_12;
    void ClearList();
};
// @fnv 0x0062e290
void FUN_0062e290_shell::ClearList()
{
    FUN_0062e290_Node* pNode = m_iWordAt04;
    while (pNode)
    {
        FUN_0062e290_Node* tmp = pNode;
        pNode = pNode->m_next;
        vf2(tmp);
    }
    m_12 = 0;
    m_iWordAt04 = 0;
    m_8 = 0;
}

struct FUN_0062e2f0_shell
{
    int m_auiShapeKeys;
    void* m_pFirstNode;
    void* m_pTail;
    int m_uiItemCount;
    void FUN_0062e2f0(void* block);
};
// Gets a Data62 via f1(), stores the int pointed to by p into its c field, then passes it to FUN_0062e2f0.
// @fnv 0x0062e060
void C62::SetC(int* piValue)
{
    Data62* iVar1 = f1();
    iVar1->c = *piValue;
    reinterpret_cast<::FUN_0062e2f0_shell *>(this)->FUN_0062e2f0(iVar1);
}

// @fnv 0x0062e2f0
void FUN_0062e2f0_shell::FUN_0062e2f0(void* block)
{
    ((int*)block)[0] = 0;
    ((int*)block)[1] = (int)m_pTail;
    if (m_pTail)
        ((int*)m_pTail)[0] = (int)block;
    else
        m_pFirstNode = block;
    m_pTail = block;
    ++m_uiItemCount;
}

struct H_A100
{
};
struct H_6db70
{
};
struct S_0062e350
{
    void* f0;
    int f4;
    unsigned int f8;
    void FUN_0062e350(void*);
};
// @fnv 0x0062e350
void S_0062e350::FUN_0062e350(void* a)
{
    reinterpret_cast<::FUN_00621c90_Class *>((this))->FUN_00626870();
    if (!(f8 & 0x80000000))
    {
        reinterpret_cast<::FUN_0066db70_Class *>((((H_6db70*)a)))->FUN_0066db70((int)(f0), (int)(((void *)(reinterpret_cast<::fnv_0062a100::FUN_0062a100_shell *>((((H_A100*)this)))->GetSizeMasked()))));
    }
    f0 = 0;
    f8 = 0x80000000;
}

struct ZoneEntry;
struct TrapTargetEntry;
struct Caller
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void target(ZoneEntry* a, TrapTargetEntry* b);
};
struct TrapTargetEntry
{
    char _pad[16];
    CombatWorldStateListNode _list;
    void FUN_0062c600(ZoneEntry* apTrap);
};
// Calls target on the object returned by _list._ref_0084e3a0(), passing apTrap and this.
// @fnv 0x0062c600
void TrapTargetEntry::FUN_0062c600(ZoneEntry* apTrap)
{
    ((Caller*)reinterpret_cast<::FUN_0084e3a0_Class *>(&(_list))->FUN_0084e3a0())->target(apTrap, this);
}

struct FUN_0062c6e0_shell
{
    FUN_0062c6e0_shell();
};

struct Base
{
};

extern void* DAT_0104e2f8;

// @fnv 0x0062c6e0
FUN_0062c6e0_shell::FUN_0062c6e0_shell()
{
    new ((void *)(((Base*)this))) ::FUN_0062c750_shell();
    *(void**)this = &DAT_0104e2f8;
}

// @fnv 0x0062d330
void MyCollector::FUN_0062d330()
{
    reinterpret_cast<::FUN_00622570_Class *>((((CalleeObj*)&this->m_04)))->FUN_00622570(false);
}

namespace fnv_0062d550 {
struct FUN_0062d570
{
};

struct FUN_0062d550_shell
{
    char pad1[0x10];
    FUN_0062d570 m_0x10;
    void ForwardToMember(int param);
};

// @fnv 0x0062d550
void FUN_0062d550_shell::ForwardToMember(int aiValue)
{
    reinterpret_cast<::TrapHolder *>(&(m_0x10))->FUN_0062d570((::CombatWorldStateListNode *)(aiValue));
}
}  // namespace fnv_0062d550

struct FUN_0062c7a0_shell
{
};

struct FUN_0062d9e0_shell
{
    char pad[0x10];
    FUN_0062c7a0_shell* p;
    void CallMemberAtOffset();
};

struct FUN_00620810_shell
{
};
struct FUN_0062db40_shell
{
    void FUN_0062db40(int a);
};
// @fnv 0x0062db40
void FUN_0062db40_shell::FUN_0062db40(int aiValue)
{
    reinterpret_cast<::FUN_00620810_List *>((((FUN_00620810_shell*)this)))->FindByFlags(aiValue);
}

namespace fnv_0062dfa0 {
struct FUN_0062dfa0_shell
{
    void* FUN_0062dfa0();
};

// Sets the vtable pointer and clears the three pointer fields at offsets 4, 8 and 12, then returns this.
// @fnv 0x0062dfa0
void* FUN_0062dfa0_shell::FUN_0062dfa0()
{
    *(void**)this = &DAT_0104e3f4;
    *(int**)((char*)this + 0xc) = 0;
    *(int**)((char*)this + 4) = 0;
    *(int**)((char*)this + 8) = 0;
    return this;
}
}  // namespace fnv_0062dfa0

struct bhkWorld;
struct TESObjectCELL;
struct ExtraDataList
{
};
struct BSOcclusionPlane
{
};
struct TESObject
{
};
// Returns the TESObject obtained from the plane's cull result extra data world, or null if any step is missing.
// @fnv 0x0062ddb0
TESObject* __cdecl GetOcclusionPlaneObject(BSOcclusionPlane* pOcclusionPlane)
{
    TESObject* pResult = 0;
    if (pOcclusionPlane)
    {
        ExtraDataList* pData = ((::ExtraDataList *)(reinterpret_cast<::LowProcess *>((void *)(pOcclusionPlane))->GetTarget()));
        if (pData)
        {
            bhkWorld* pWorld = ((::bhkWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((pData))->FUN_004543c0()));
            if (pWorld)
            {
                TESObject* pObj = ((::TESObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((TESObject*)pWorld)))->FUN_007af430()));
                pResult = pObj ? (TESObject*)((char*)pObj - 8) : 0;
            }
        }
    }
    return pResult;
}

struct FUN_0062d510_shell
{
    void FUN_0062d510();
};
struct FUN_0062de90_shell
{
    char _pad[0x20];
    CombatWorldStateListNode* m_20;
    void FUN_0062de90(CombatWorldStateListNode* target);
};
// Walks the linked list from m_20 and, when a node's _ref_0084e3a0() equals target, calls FUN_0062d510 on it and stops.
// @fnv 0x0062de90
void FUN_0062de90_shell::FUN_0062de90(CombatWorldStateListNode* target)
{
    CombatWorldStateListNode* node = m_20;
    while (node)
    {
        if (reinterpret_cast<::FUN_0084e3a0_Class *>((node))->FUN_0084e3a0() == (int)target)
        {
            ((FUN_0062d510_shell*)node)->FUN_0062d510();
            break;
        }
        else
        {
            node = node->GetNext();
        }
    }
}

struct FUN_0062d840_shell
{
    char _pad[24];
    FUN_0062d840_shell(unsigned int, unsigned int);
};
struct FUN_0062d7c0_shell
{
    FUN_0062d840_shell* FUN_0062d7c0(unsigned int a, unsigned int b);
};
// Allocates and constructs a FUN_0062d840_shell with the two given unsigned int arguments and returns the new object.
// @fnv 0x0062d7c0
FUN_0062d840_shell* FUN_0062d7c0_shell::FUN_0062d7c0(unsigned int a, unsigned int b)
{
    return new FUN_0062d840_shell(a, b);
}

struct TESObjectREFR;
struct RootContactPoint
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pc;
    void* m_p10;
    void* m_p14;
    void* m_p18;
    void* m_p1c;
    void* m_p20;
    void* m_p24;
    void* m_p28;
    void* m_p2c;
    void* m_p30;
    void* m_p34;
    void* m_p38;
    void* m_p3c;
    void* m_p40;
    void* m_p44;
    void* m_p48;
};
struct FUN_00620340_shell
{
};
struct FUN_0062dc80_shell
{
    bool FUN_0062dc80(RootContactPoint* arPoint);
};
// @fnv 0x0062dc80
bool FUN_0062dc80_shell::FUN_0062dc80(RootContactPoint* arPoint)
{
    bool bres = false;
    TESObjectREFR* ptrapRef = 0;
    TESObjectREFR* m_pReference = 0;
    ptrapRef = FUN_0062b4e0(arPoint->m_p48);
    m_pReference = FUN_0062b4e0(arPoint->m_p20);
    if (ptrapRef && m_pReference && ((bool(*)(void*))(*(void***)m_pReference)[0x40])(m_pReference))
    {
        ZoneEntry* ptrap =
            (ZoneEntry*)((void *)(reinterpret_cast<::ImpactManager620 *>((((FUN_00620340_shell*)((char*)this - 8))))->FUN_00620340((::CollisionInfo620 *)(arPoint), ptrapRef, m_pReference, (void *)(0), 1)));
        bres = ptrap != 0;
    }
    return bres;
}

struct FUN_0062e0a0_shell : NiTPointerMap
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void*);
    void* m_pFirstNode;
    void* m_pTail;
    int m_uiItemCount;
    void* RemoveFirstNode();
};
// Resets field4 to 0, then repeatedly takes an item from map and deallocates it until the map is empty.
// @fnv 0x0062c980
void Target062c980::ClearMap()
{
    void* pDelete;
    void* pItem;
    field4 = 0;
    while (!::IsFieldCZero((::Dummy_0069b080 *)&(map)))
    {
        pItem = reinterpret_cast<::FUN_0062e0a0_shell *>(&(map))->RemoveFirstNode();
        pDelete = pItem;
        ::FUN_00401030(pDelete);
    }
}

// @fnv 0x0062e0a0
void* FUN_0062e0a0_shell::RemoveFirstNode()
{
    void* node = m_pFirstNode;
    m_pFirstNode = *(void**)m_pFirstNode;
    if (m_pFirstNode)
        ((void**)m_pFirstNode)[1] = 0;
    else
        m_pTail = 0;
    void* pValue = ((void**)node)[2];
    v2(node);
    --m_uiItemCount;
    return pValue;
}


struct FUN_0062cb90_Entry
{
    int value;
    unsigned char flag;
};

struct FUN_0062cb90_Allocated
{
    int value;
    int state;
};

struct FUN_0062cb90_shell
{
    FUN_0062cb90_Entry* entries;
    int count;
    int m_08;
    C62 m_c62;
    void CompactEntries();
};

// Scans entries, allocating an 8-byte record for each unflagged entry and passing it to m_c62, then removes that entry from the array and decrements count.
// @fnv 0x0062cb90
void FUN_0062cb90_shell::CompactEntries()
{
    int allocated = 0;
    FUN_0062cb90_Allocated* index;
    void* j;
    int entry;

    while (allocated < count)
    {
        if (entries[allocated].flag == 0)
        {
            j = ::FUN_00401000(8);
            index = static_cast<FUN_0062cb90_Allocated*>(j);
            index->state = 2;
            index->value = entries[allocated].value;

            m_c62.SetC(reinterpret_cast<int*>(&index));

            for (entry = allocated; entry < count - 1; ++entry)
            {
                entries[entry].value = entries[entry + 1].value;
                entries[entry].flag = entries[entry + 1].flag;
            }

            count = count - 1;
        }
        else
        {
            entries[allocated].flag = 0;
            ++allocated;
        }
    }
}

struct FUN_0062d310_shell : MyCollector
{
    void FUN_0062d310();
};

// @fnv 0x0062d310
void FUN_0062d310_shell::FUN_0062d310()
{
    reinterpret_cast<::FUN_00621c90_Class *>(((char*)this + 8))->FUN_00626870();
    FUN_0062d330();
}

struct BSAudio
{
};
struct MemoryManager
{
    int _ref_00885750();
};
MemoryManager* __cdecl _D1A0E0GetMemoryRouter();
struct Vt62d470
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void*, unsigned int);
};
// @fnv 0x0062d470
void __cdecl FUN_0062d470(void* ap)
{
    if (ap)
    {
        Vt62d470* apTopic = (Vt62d470*)((int)(reinterpret_cast<::MagicCaster_shell *>((((BSAudio*)_D1A0E0GetMemoryRouter())))->FUN_0044edb0()));
        apTopic->vf2(ap, 0x114);
    }
}

struct BGSSaveLoadGame
{
};


struct FUN_0062c860_shell
{
};


struct FUN_00620720_shell
{
public:
    ::FUN_00620720_shell *FUN_00620720(void *, void *);
};
struct FUN_0062c640_shell
{
    void FUN_0062c640();
};
struct FUN_0062dc50_shell
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* m_iThirdValue;
    void* FUN_0062dc50(unsigned int a, unsigned int b);
};
struct AnimIdle;
struct FUN_00620680_Class
{
public:
    ::AnimIdle *FUN_00620680(int, int);
};

struct FUN_0062dd20_vtable
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual void f21()
    {}
    virtual void f22()
    {}
    virtual void f23()
    {}
    virtual void f24()
    {}
    virtual void f25()
    {}
    virtual void f26()
    {}
    virtual void f27()
    {}
    virtual void f28()
    {}
    virtual void f29()
    {}
    virtual void f30()
    {}
    virtual void f31()
    {}
    virtual void f32()
    {}
    virtual void f33()
    {}
    virtual void f34()
    {}
    virtual void f35()
    {}
    virtual void f36()
    {}
    virtual void f37()
    {}
    virtual void f38()
    {}
    virtual void f39()
    {}
    virtual void f40()
    {}
    virtual void f41()
    {}
    virtual void f42()
    {}
    virtual void f43()
    {}
    virtual void f44()
    {}
    virtual void f45()
    {}
    virtual void f46()
    {}
    virtual void f47()
    {}
    virtual void f48()
    {}
    virtual void f49()
    {}
    virtual void f50()
    {}
    virtual void f51()
    {}
    virtual void f52()
    {}
    virtual void f53()
    {}
    virtual void f54()
    {}
    virtual void f55()
    {}
    virtual void f56()
    {}
    virtual void f57()
    {}
    virtual void f58()
    {}
    virtual void f59()
    {}
    virtual void f60()
    {}
    virtual void f61()
    {}
    virtual void f62()
    {}
    virtual void f63()
    {}
    virtual bool f64()
    {
        return false;
    }
};

struct FUN_0062dd20_shell
{
    bool FUN_0062dd20(RootContactPoint& arPoint);
};

// Looks up two TESObjectREFRs from arPoint, and if both exist and the second passes a vtable check, resolves a ZoneEntry via FUN_00620680 and returns true.
// @fnv 0x0062dd20
bool FUN_0062dd20_shell::FUN_0062dd20(RootContactPoint& arPoint)
{
    bool bres = false;
    TESObjectREFR* ptrapRef = 0;
    TESObjectREFR* m_pReference = 0;

    ptrapRef = FUN_0062b4e0(arPoint.m_p48);
    m_pReference = FUN_0062b4e0(arPoint.m_p20);

    if (ptrapRef && m_pReference && reinterpret_cast<FUN_0062dd20_vtable*>(m_pReference)->f64())
    {
        {
            ZoneEntry* ptrap;
            ptrap = reinterpret_cast<ZoneEntry*>(
                ((void *)(reinterpret_cast<FUN_00620680_Class*>(reinterpret_cast<char*>(this) - 8)->FUN_00620680((int)(arPoint.m_p48), (int)(m_pReference)))));
        }
        bres = true;
    }

    return bres;
}

struct FX62c640_Member : FUN_0062c6e0_shell
{
    ~FX62c640_Member();
};

struct FUN_0062c640
{
    TrigEntry* m_aiIndexedValues;
    int unk4;
    int m_uiItemCount;
    FX62c640_Member m_kMemberDescriptor;
    FUN_0062c640();
};
// Calls FUN_00620720 with a and b, then FUN_0062c640 on the object at offset 0x10, and returns this.
// @fnv 0x0062dc50
void* FUN_0062dc50_shell::FUN_0062dc50(unsigned int auiArg1, unsigned int auiArg2)
{
    ((FUN_00620720_shell*)this)->FUN_00620720((void *)(auiArg1), (void *)(auiArg2));
    new ((void *)(((FUN_0062c640_shell*)((char*)this + 0x10)))) ::FUN_0062c640();
    return this;
}

// @fnv 0x0062c640
FUN_0062c640::FUN_0062c640()
{
    m_uiItemCount = 20;
    unk4 = 0;
    m_aiIndexedValues = new TrigEntry[m_uiItemCount];
}

struct Form62C
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual bool isRef();
};
struct Extra62C
{
};
struct Ref62C : Form62C
{
};
struct Entry62C
{
    unsigned int id;
    int unknown;
};
struct Shell62C
{
    Entry62C* entries;
    int count;
    void ApplyEntriesToRef(Ref62C*);
};
// If the save/load game check fails, calls ApplyEntriesToRef with _ref_0084e3a0(this) on the object at offset 0x10, then calls ClearMap on it.
// @fnv 0x0062d510
void FUN_0062d510_shell::FUN_0062d510()
{
    if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((g_BGSSaveLoadGame))->FUN_0042ce10())
    {
        reinterpret_cast<::Shell62C *>((reinterpret_cast<FUN_0062c860_shell*>(reinterpret_cast<char*>(this) + 0x10)))->ApplyEntriesToRef((::Ref62C *)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0()));
    }

    reinterpret_cast<Target062c980*>(reinterpret_cast<char*>(this) + 0x10)->ClearMap();
}
// @fnv 0x0062c860
void Shell62C::ApplyEntriesToRef(Ref62C* ref)
{
    if (!count)
        return;
    unsigned int* copy = new unsigned int[count];
    unsigned int size = count;
    for (int i = 0; i < count; i++)
        copy[i] = entries[i].id;
    Extra62C* extra = ((::Extra62C *)(reinterpret_cast<::FUN_005d43c0_ *>((ref))->FUN_005d43c0()));
    for (unsigned int j = 0; j < size; j++)
    {
        Form62C* form = ((::Form62C *)(::FUN_004839c0(copy[j])));
        if (form && form->isRef())
        {
            Ref62C* target = (Ref62C*)form;
            ::FUN_005ac750((::TESForm *)(target), (::ExtraDataList *)(extra), 0x40000000);
            reinterpret_cast<::s572e10::Owner *>((ref))->FUN_00572e10((int)(target));
            reinterpret_cast<::fnv_00565870::FUN_00565870_shell *>((ref))->FUN_00565870();
        }
    }
    delete[] copy;
}

struct CollisionKeyEntry
{
    int key;
    bool active;
};
struct CollisionState
{
    int key;
    int state;
};
struct CollisionQueue
{
};
struct CollisionRegistry
{
    CollisionKeyEntry* entries;
    int count;
    int capacity;
    CollisionQueue queue;
    bool RegisterCollision(void* object);
};
// @fnv 0x0062c9d0
bool CollisionRegistry::RegisterCollision(void* object)
{
    int key = reinterpret_cast<::FUN_0084e3a0_Class *>((object))->FUN_0084e3a0();
    for (int i = 0; i < count; ++i)
    {
        if (key == entries[i].key)
        {
            if (!entries[i].active)
            {
                entries[i].active = true;
                return true;
            }
            return false;
        }
    }
    if (count == capacity)
    {
        int newCapacity = capacity * 2;
        CollisionKeyEntry* newEntries = new CollisionKeyEntry[newCapacity];
        for (int j = 0; j < capacity; ++j)
        {
            newEntries[j].key = entries[j].key;
            newEntries[j].active = entries[j].active;
        }
        capacity = newCapacity;
        delete[] entries;
        entries = newEntries;
    }
    entries[count].key = key;
    entries[count].active = true;
    ++count;
    CollisionState* state = new CollisionState;
    state->state = 1;
    state->key = key;
    reinterpret_cast<::C62 *>(&(queue))->SetC((int *)(::CollisionState **)(&state));
    return false;
}

struct S_0062d350_Member
{
    S_0062d350_Member(int a);
    ~S_0062d350_Member();
};

struct S_0062d350_Base
{
    int unk4;
    S_0062d350_Base();
    ~S_0062d350_Base();
    virtual void v00();
};

struct FUN_0062d350 : S_0062d350_Base
{
    S_0062d350_Member m8;
    FUN_0062d350();
    virtual void v00();
};

// Constructs the object: initializes member m8 with 0 and calls FUN_0062d310 on the base.
// @fnv 0x0062d350
FUN_0062d350::FUN_0062d350() : m8(0)
{
    reinterpret_cast<::FUN_0062d310_shell *>(this)->FUN_0062d310();
}

class FUN_0062e040_base
{
  public:
    virtual ~FUN_0062e040_base();
    int unk04;
};

class FUN_0062dfe0 : public FUN_0062e040_base
{
  public:
    virtual ~FUN_0062dfe0();
};
// @fnv 0x0062c700
void FUN_0062c700_shell::FUN_0062c700()
{
    reinterpret_cast<::FUN_0062dfe0 *>((((FUN_0062dfe0_shell*)this)))->FUN_0062dfe0::~FUN_0062dfe0();
}
// Calls FUN_0062dfe0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0062c770
void* FUN_0062c770_shell::FUN_0062c770(unsigned int flags)
{
    reinterpret_cast<::FUN_0062dfe0 *>(this)->FUN_0062dfe0::~FUN_0062dfe0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that forwards to ClearList on this object.
// @fnv 0x0062dfe0
FUN_0062dfe0::~FUN_0062dfe0()
{
    ((FUN_0062e290_shell*)this)->ClearList();
}

// FUN_0062e150 : thiscall, one stack argument (index), returns a pointer.
struct FUN_0062e150_cls
{
    void* m_pBase;
    void* FUN_0062e150(int index);
};

// @fnv 0x0062e150
void* FUN_0062e150_cls::FUN_0062e150(int index)
{
    return (void*)((char*)m_pBase + index * 16);
}

struct SmallHelper
{
    bool m_flag;
    void* Init(FUN_0062e170* owner);
};

// Creates a SmallHelper, initializes it with this as owner, and passes the result to FUN_0062e350 on this.
// @fnv 0x0062e260
void FUN_0062e170::InitHelper()
{
    reinterpret_cast<S_0062e350*>(this)->FUN_0062e350(SmallHelper().Init(this));
}

struct CacheEntry62C
{
    int m_iKey;
    int m_iValue;
};

class EntryList62C
{
  public:
    ~EntryList62C();


    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};

class FUN_0062c7a0_Cache
{
  public:
    ~FUN_0062c7a0_Cache();

    CacheEntry62C* m_pCacheEntry;
    int m_iBufferSize;
    int unk08;
    EntryList62C m_kEntries;
};
// @fnv 0x0062d9e0
void FUN_0062d9e0_shell::CallMemberAtOffset()
{
    reinterpret_cast<::FUN_0062c7a0_Cache *>((((FUN_0062c7a0_shell*)((char*)this + 0x10))))->FUN_0062c7a0_Cache::~FUN_0062c7a0_Cache();
}

// Resets the buffer size, deletes the stored entry, and removes and deletes every entry in the list until it is empty.
// @fnv 0x0062c7a0
FUN_0062c7a0_Cache::~FUN_0062c7a0_Cache()
{
    m_iBufferSize = 0;
    if (m_pCacheEntry)
        delete m_pCacheEntry;
    m_pCacheEntry = 0;
    while (!::IsFieldCZero((::Dummy_0069b080 *)&(m_kEntries)))
    {
        CacheEntry62C* pkEntry = ((::CacheEntry62C *)(reinterpret_cast<::FUN_0062e0a0_shell *>(&(m_kEntries))->RemoveFirstNode()));
        delete pkEntry;
    }
}

struct TESObjectREFR : Ref62C
{
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual int Active();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool FlagA(int);
    virtual bool FlagB();
};
struct Check62
{
};
struct ArrayEntry62
{
    void* bodyA;
    void* bodyB;
    void* bodyC;
    void* bodyD;
};
struct Array62
{
    void* data;
    int size;
    int capacity;
};
struct World62
{
};
struct CollisionObject62;
struct Broad62
{
};
struct CollisionObject62
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int Kind();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void Collect(void*, int);
};
struct FUN_0062d350_Collector
{
    void* vtable;
    float earlyOut;
    void* data;
    int size;
    int capacity;
    ArrayEntry62 pairs[16];
    int capacityFlags;
    FUN_0062d350_Collector();
    ~FUN_0062d350_Collector();
    Array62* FUN_00413f40();
};
struct Registry62 : CollisionRegistry
{
};
struct Subject62
{
    int field0;
    int field4;
    int field8;
    int fieldC;
    Registry62 registry;
    bool ProcessCollisionPairs(int);
};
// @fnv 0x0062cc90
bool Subject62::ProcessCollisionPairs(int arg)
{
    bool world = false;
    TESObjectREFR* owner = ((::TESObjectREFR *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
    if (!owner || reinterpret_cast<::TESForm *>((owner))->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((owner))->FUN_00440d80() || !owner->Active())
        return world;
    Broad62* pending = ((::Broad62 *)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
    CollisionObject62* kind = ((::CollisionObject62 *)(::FUN_004b59d0((const char *)(pending))));
    World62* broad = ((::World62 *)(reinterpret_cast<::Twin_0044ddc0 *>((kind))->GetName()));
    if (broad)
        reinterpret_cast<::TESForm *>((broad))->ClearData();
    int changed = kind->Kind();
    if (broad)
        reinterpret_cast<::TESForm *>((broad))->ClearData();
    if (changed == 1)
    {
        CollisionObject62* shape = kind;
        if (!reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::Check62 &)((*(::Check62 *)(reinterpret_cast<::FUN_0062e120_shell *>((((::Array62 *)(reinterpret_cast<::FUN_0062d2f0_shell *>((shape))->GetOffset160()))))->FUN_0062e120({})))))->FUN_005609f0())
        {
            FUN_0062d350_Collector collector;
            reinterpret_cast<::FUN_0062d310_shell *>(&(collector))->FUN_0062d310();
            if (broad)
                reinterpret_cast<::TESForm *>((broad))->ClearData();
            shape->Collect(&collector, 0);
            if (broad)
                reinterpret_cast<::TESForm *>((broad))->ClearData();
            Array62* array = collector.FUN_00413f40();
            if (!reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::Check62 &)((*(::Check62 *)(reinterpret_cast<::FUN_0062e120_shell *>((array))->FUN_0062e120({})))))->FUN_005609f0())
            {
                int count = ((int)(reinterpret_cast<::Callees *>((array))->FUN_00726070()));
                for (int i = 0; i < count; i++)
                {
                    void* body = ((::ArrayEntry62 *)(reinterpret_cast<::FUN_0062e150_cls *>((array))->FUN_0062e150(i)))->bodyC;
                    if (body)
                    {
                        TESObjectREFR* ref = FUN_0062b4e0(body);
                        if (ref)
                        {
                            bool flag = ref->IsActor() && ::FUN_004b59f0(body);
                            bool actor = ref->FlagA(0) || ref->FlagB();
                            if (!flag || actor)
                            {
                                bool found = registry.RegisterCollision(ref);
                                if (found)
                                {
                                    Extra62C* extra = ((::Extra62C *)(reinterpret_cast<::FUN_005d43c0_ *>((((::TESObjectREFR *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->FUN_005d43c0()));
                                    world |= ::FUN_005ac750((::TESForm *)(ref), (::ExtraDataList *)(extra), 0x10000000);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if (kind->Kind() == 0)
    {
        CollisionObject62* shape = kind;
        Array62* array = ((::Array62 *)(reinterpret_cast<::FUN_0045c650_shell *>((shape))->FUN_0045c650()));
        if (!reinterpret_cast<::FUN_005609f0_shell *>((void *)&(const ::Check62 &)((*(::Check62 *)(reinterpret_cast<::FUN_0062e120_shell *>((array))->FUN_0062e120({})))))->FUN_005609f0())
        {
            int count = ((int)(reinterpret_cast<::Callees *>((array))->FUN_00726070()));
            for (int i = 0; i < count; i++)
            {
                void* body = ((::ArrayEntry62 *)&(reinterpret_cast<::FUN_00629ab0_shell *>((array))->FUN_00629ab0(i)))->bodyA;
                if (body)
                {
                    TESObjectREFR* ref = FUN_0062b4e0(body);
                    if (ref)
                    {
                        bool flag = ref->IsActor() && ::FUN_004b59f0(body);
                        bool actor = ref->FlagA(0) || ref->FlagB();
                        if (!flag || actor)
                        {
                            bool found = registry.RegisterCollision(ref);
                            if (found)
                            {
                                Extra62C* extra = ((::Extra62C *)(reinterpret_cast<::FUN_005d43c0_ *>((((::TESObjectREFR *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->FUN_005d43c0()));
                                world |= ::FUN_005ac750((::TESForm *)(ref), (::ExtraDataList *)(extra), 0x10000000);
                            }
                        }
                    }
                }
            }
        }
    }
    reinterpret_cast<::FUN_0062cb90_shell *>(&(registry))->CompactEntries();
    CollisionState* object = ((::CollisionState *)(reinterpret_cast<::fnv_0062cb60::FUN_0062cb60_shell *>(&(registry))->FUN_0062cb60()));
    if (object)
    {
        unsigned int ref;
        if (object->state == 1)
            ref = 0x20000000;
        else
            ref = 0x40000000;
        unsigned int id = object->key;
        Ref62C* flags = (Ref62C*)((::Form62C *)(::FUN_004839c0(id)));
        delete object;
        if (flags)
        {
            Extra62C* extra = ((::Extra62C *)(reinterpret_cast<::FUN_005d43c0_ *>((((::TESObjectREFR *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->FUN_005d43c0()));
            world |= ::FUN_005ac750((::TESForm *)(flags), (::ExtraDataList *)(extra), ref);
            reinterpret_cast<::s572e10::Owner *>((((::TESObjectREFR *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->FUN_00572e10((int)(flags));
        }
    }
    return world;
}

struct TESObjectREFR;
struct EventContext
{
};
struct InputBody
{
};
struct EventCode
{
    int value;
};
struct TrapEventHandler
{
    void FUN_00620130(TESObjectREFR* reference);
};
struct FUN_0062da00_Class
{
    void HandleTrapEvent(InputBody* source);
};
struct LocalClass
{
};

struct ArgClass
{
};

struct FUN_0043b4d0_shell
{
    int FUN_0043b4d0();
};

struct GlobalObject_008c71b0 : FUN_0043b4d0_shell
{
    int unk00;
    GlobalObject_008c71b0(int);
};
// Resolves the event code from the input body and, for codes 14, 16 or 30, dispatches the referenced object to the trap handler.
// @fnv 0x0062da00
void FUN_0062da00_Class::HandleTrapEvent(InputBody* pInputBody)
{
    EventContext* resolvedBody = ((::EventContext *)(::FUN_00460140((int)(pInputBody))));
    EventCode notification;
    new ((void *)&(notification)) ::GlobalObject_008c71b0((int)(((void *)(::FUN_0043b540((char *)(resolvedBody))))));
    int category = reinterpret_cast<::FUN_0043b4d0_shell *>(&(notification))->FUN_0043b4d0();
    if (category == 14 || category == 16 || category == 30)
    {
        TESObjectREFR* reference = FUN_0062b4e0(resolvedBody);
        if (reference != 0)
        {
            if (category == 14 || category == 16)
            {
                reinterpret_cast<::FUN_00576830_shell *>((reinterpret_cast<TrapEventHandler*>(reinterpret_cast<char*>(this) - 8)))->FUN_00576800((::BSOcclusionPlane *)(reference));
            }
            else
            {
                reinterpret_cast<TrapEventHandler*>(reinterpret_cast<char*>(this) - 8)->FUN_00620130(reference);
            }
        }
    }
}

struct FUN_0062d9b0_Class : BSSimpleList
{
    ~FUN_0062d9b0_Class();
};

struct ListHead : BSSimpleList
{
    FUN_0062d9b0_Class* FUN_0062db40(int);
};

struct TargetClass
{
    int unk00;
    ListHead* unk04;

    void RemoveMatchingListEntry(ArgClass* arg);
};

// Gets a value from arg, and if unk04 is set and that value is 12, 22 or 24, finds and removes the matching entry from the unk04 list.
// @fnv 0x0062da90
void TargetClass::RemoveMatchingListEntry(ArgClass* arg)
{
    LocalClass* v8 = ((::LocalClass *)(::FUN_00460140((int)(arg))));
    GlobalObject_008c71b0 v4(((int)(::FUN_0043b540((char *)(v8)))));

    if (unk04)
    {
        int vc = v4.FUN_0043b4d0();
        if (vc == 12 || vc == 22 || vc == 24)
        {
            FUN_0062d9b0_Class* v10 = unk04->FUN_0062db40((int)v8);
            if (v10)
            {
                unk04 = (ListHead*)v10->FUN_006207a0(unk04);
                delete v10;
            }
        }
    }
}

class FUN_0062df80
{
  public:
    ~FUN_0062df80();
    int unk00;
};

class FUN_0062d420
{
  public:
    virtual ~FUN_0062d420();
    int unk04;
};

class FUN_0062d4b0 : public FUN_0062d420
{
  public:
    FUN_0062df80 m_08;

    virtual ~FUN_0062d4b0();
};
// Calls FUN_0062d4b0 on this, then FUN_0062d470(this) if bit 0 of flags is set, and returns this.
// @fnv 0x0062d440
void* hkpAllCdBodyPairCollector::FUN_0062d440(unsigned int flags)
{
    reinterpret_cast<class ::FUN_0062d4b0 *>((((S_62d4b0*)this)))->FUN_0062d4b0::~FUN_0062d4b0();
    if (flags & 1)
        FUN_0062d470(this);
    return this;
}

// @fnv 0x0062d4b0
FUN_0062d4b0::~FUN_0062d4b0()
{}

struct CollisionBody;
struct CollisionArgument
{
};
struct CollisionBody
{
};
struct FilterWord
{
    unsigned int filter;
    FilterWord(unsigned int);
};
struct ListenerNode
{
    unsigned int unk00;
    ListenerNode* next;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    ListenerNode(TESObjectREFR*, CollisionBody*);
};
struct TrapListener
{
    unsigned int unk00;
    ListenerNode* head;
    void AddListener(CollisionArgument*);
};
// Adds a new ListenerNode to the head of the list when the collision body's filter layer is 12, 22, or 24 and a reference is found.
// @fnv 0x0062db60
void TrapListener::AddListener(CollisionArgument* apCollisionArgument)
{
    CollisionBody* body = ((::CollisionBody *)(::FUN_00460140((int)(apCollisionArgument))));
    FilterWord filter(::FUN_0043b540((char *)(body)));
    int layer = reinterpret_cast<::FUN_0043b4d0_shell *>(&(filter))->FUN_0043b4d0();
    if (layer == 12 || layer == 22 || layer == 24)
    {
        TESObjectREFR* reference = FUN_0062b4e0(body);
        if (reference)
        {
            ListenerNode* node = new ListenerNode(reference, body);
            reinterpret_cast<::CombatProcedure *>((node))->Initialize((::CombatController *)(head));
            head = node;
        }
    }
}

struct BSSimpleList;

struct Item62DE
{
    virtual void vfn_00();
    virtual void vfn_04();
};

struct Child62DE
{
    Child62DE* FUN_0062d990();
};

struct Owner62DE
{
    Item62DE* m_items;
};

struct Updater62DE
{
    int unk00[6];
    Child62DE* m_children;

    void FUN_0062de20(float f);
};

// Iterates m_children calling ProcessCollisionPairs, then iterates the owner's m_items list calling vfn_04 on each.
// @fnv 0x0062de20
void Updater62DE::FUN_0062de20(float f)
{
    {
        Child62DE* child = m_children;
        while (child)
        {
            reinterpret_cast<::Subject62 *>((child))->ProcessCollisionPairs(f);
            child = child->FUN_0062d990();
        }
    }
    Item62DE* item = ((Owner62DE*)((char*)this - 4))->m_items;
    while (item)
    {
        item->vfn_04();
        item = ((::Item62DE *)(reinterpret_cast<::ContOwner_620 *>((item))->FUN_00620180()));
    }
}

struct EmptyBase_b4781
{
    ~EmptyBase_b4781();
};

struct SubObj_b4781
{
    ~SubObj_b4781();
};

struct FUN_0062d760_cls : EmptyBase_b4781
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    SubObj_b4781 m_14;
    ~FUN_0062d760_cls();
};

// The destructor body is empty.
// @fnv 0x0062d760
FUN_0062d760_cls::~FUN_0062d760_cls()
{}

struct EventCaller_62c5a0
{
    virtual void Invoke(void* context);
    int unk04;
    int unk08;
    int unk0c;
};

struct EventLink_62c5a0
{
};

struct EventNode_62c5a0 : EventCaller_62c5a0, EventLink_62c5a0
{
};

struct EventCollection_62c5a0
{
    void FUN_0062c5a0();
};

// Iterates through the linked list of event nodes and invokes each one with the collection as context.
// @fnv 0x0062c5a0
void EventCollection_62c5a0::FUN_0062c5a0()
{
    EventNode_62c5a0* node = ((::EventNode_62c5a0 *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(this)->FUN_00825c00()));
    while (node != 0)
    {
        node->Invoke(this);
        node = static_cast<EventNode_62c5a0*>(((::EventLink_62c5a0 *)(reinterpret_cast<::Callees *>((node))->FUN_00726070())));
    }
}

struct CombatWorldStateListNode_o2
{
};

struct FUN_0062dee0_shell_o2
{
    CombatWorldStateListNode_o2* m_kNode;
    bool FUN_0062dee0(int arg);
};

struct FUN_0062dfe0_shell_o2
{
};

// Adjustor (this-adjusting) thunk for FUN_0062e3a0: "sub ecx, 0x1c; jmp FUN_0062d870".
// PrimaryBase is the first base (vptr + six int fields = 0x1c bytes); SecondaryBase
// declares the same virtual; Derived derives from both, redeclares the virtual and
// defines only its constructor, so the compiler emits the adjusting thunk.
struct PrimaryBase
{
    virtual void* FUN_0062e3a0(unsigned int flags);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct SecondaryBase
{
    virtual void* FUN_0062e3a0(unsigned int flags);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0062e3a0
    virtual void* FUN_0062e3a0(unsigned int flags);
};

Derived::Derived()
{}

namespace fnv_0062e3b0 {
// Adjustor thunk for FUN_0062e3b0: "sub ecx, 8; jmp FUN_0062d870".
//
// MSVC emits a "this adjusting thunk" in the vtable of a class that inherits
// the same virtual from two bases: the thunk converts the secondary base
// sub-object pointer back to the derived object pointer (sub ecx, 8) and then
// tail jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus one int member (4 + 4 = 8 bytes). Both
// bases declare the same virtual function; the derived class redeclares it and
// defines only its constructor, which is what makes the compiler emit the
// vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0062e3b0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_0062e3b0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0062e3b0
    virtual void FUN_0062e3b0();
};

Derived::Derived()
{}
}

// namespace fnv_0062e3b0

namespace fnv_0062e3c0 {
// sub ecx,0x14; jmp FUN_00dffb00
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (0x14 = vptr + four int fields).
struct PrimaryBase
{
    virtual void FUN_0062e3c0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

struct SecondaryBase
{
    virtual void FUN_0062e3c0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0062e3c0
    virtual void FUN_0062e3c0();
};

Derived::Derived()
{}
}
