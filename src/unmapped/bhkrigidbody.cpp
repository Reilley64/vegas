
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <cstddef>
#include <windows.h>
#include "fnv/decl/ActionOwnerC9d590.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_004ee840_cls.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00c87a40_obj.h"
#include "fnv/decl/FUN_00c9d4f0_cls.h"
#include "fnv/decl/FUN_00ca8420_Class.h"
#include "fnv/decl/ListX.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiObject.h"
#include "fnv/decl/Obj577.h"
#include "fnv/decl/RefOwner.h"
#include "fnv/decl/S00c859e0_cls.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_00a64670_Foo.h"
#include "fnv/decl/ScaleOwner.h"
#include "fnv/decl/SwapBlock_c8ce70.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/WorldObjectView.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c87000.h"
#include "fnv/symbols_00c8e000.h"
#include "fnv/symbols_00c8f000.h"
#include "fnv/symbols_00cc8000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0104f000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01204000.h"
#include "fnv/symbols_01267000.h"
#include "fnv/symbols_01268000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01272000.h"
struct NiObject;
struct NiStream
{
    NiObject* GetLoadedObject();
};
struct bhkRigidBody
{
    void FUN_00c8f3c0(NiStream*);
public:
    float GetBodyMass();
};
struct NiTPrimitiveArray_unsigned_int_
{
};
struct StrArr
{
    void* vtbl;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void Add(char*& e)
    {
        unsigned int i = m_usSize;
        if (i >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(i + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(i, e);
    }
};

// Appends the MOTION type name string matching type (DYNAMIC, SPHERE, BOX, KEYFRAMED, FIXED, THIN BOX, else INVALID) to arr.
// @fnv 0x00c8ee20
void __cdecl AddMotionTypeName(StrArr* arr, int type)
{
    char* s;
    switch (type)
    {
    case 1:
        s = ::fnv_00a7d5e0::FUN_00a7d5e0("MOTION", "DYNAMIC");
        reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)arr)))->FUN_0096a610(reinterpret_cast<std::intptr_t>(&s));
        break;
    case 2:
        s = ::fnv_00a7d5e0::FUN_00a7d5e0("MOTION", "SPHERE");
        reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)arr)))->FUN_0096a610(reinterpret_cast<std::intptr_t>(&s));
        break;
    case 3:
        s = ::fnv_00a7d5e0::FUN_00a7d5e0("MOTION", "BOX");
        reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)arr)))->FUN_0096a610(reinterpret_cast<std::intptr_t>(&s));
        break;
    case 4:
        s = ::fnv_00a7d5e0::FUN_00a7d5e0("MOTION", "KEYFRAMED");
        reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)arr)))->FUN_0096a610(reinterpret_cast<std::intptr_t>(&s));
        break;
    case 5:
        s = ::fnv_00a7d5e0::FUN_00a7d5e0("MOTION", "FIXED");
        reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)arr)))->FUN_0096a610(reinterpret_cast<std::intptr_t>(&s));
        break;
    case 6:
        s = ::fnv_00a7d5e0::FUN_00a7d5e0("MOTION", "THIN BOX");
        reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)arr)))->FUN_0096a610(reinterpret_cast<std::intptr_t>(&s));
        break;
    default:
        s = ::fnv_00a7d5e0::FUN_00a7d5e0("MOTION", "INVALID");
        arr->Add(s);
        break;
    }
}

struct FUN_00c8eb00_s
{
    void FUN_00c8eb00();
};
struct LinkedRecord
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct RigidLinkSource
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual LinkedRecord* GetLinkedRecord();

    unsigned int unk04;
    LinkedRecord* unk08;

    unsigned int GetLinkedRecordValue();
};

// Returns unk08 of the record from GetLinkedRecord when unk08 and its unk08 are set, otherwise 0.
// @fnv 0x00c89a00
unsigned int RigidLinkSource::GetLinkedRecordValue()
{
    unsigned int result = 0;
    if (unk08 && unk08->unk08)
    {
        LinkedRecord* record = GetLinkedRecord();
        if (record)
            result = record->unk08;
    }
    return result;
}

struct S_00c8d440_Arg
{
    bool unk00;
    S_00c8d440_Arg(bool b)
    {
        unk00 = b;
    }
    S_00c8d440_Arg(const S_00c8d440_Arg& o)
    {
        unk00 = o.unk00;
    }
};

struct S_00c8d440_Target
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(unsigned int id, S_00c8d440_Arg arg);
};


// @fnv 0x00c8d440
void FUN_00c8d440(bool flag)
{
    S_00c8d440_Target* t = (*reinterpret_cast<::S_00c8d440_Target * *>(&::DAT_01268360));
    t->v4(0xf043d534, S_00c8d440_Arg(flag));
    t->v4(0xf02e32e1, S_00c8d440_Arg(flag));
    t->v4(0xf02e32e2, S_00c8d440_Arg(flag));
    t->v4(0xf02132df, S_00c8d440_Arg(flag));
}

struct NativeData
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    float factor18, factor1c;
    unsigned int unk20;
    void* lastUpdate;
    int count;
};
struct NativeThing
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual NativeData* GetData();
    unsigned int unk04;
    void* world;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned char motionType;
};
struct NiRTTI
{
};
struct NativeLink
{
    NativeThing* object;
    unsigned int category;
};
NativeLink* FUN_00c85ef0(NativeLink*, NativeThing*, const NiRTTI*);
extern unsigned char DAT_011afe59;
struct BodyUpdate
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void Reset();
    unsigned int unk04;
    NativeThing* native;
    unsigned int unk0c;
    unsigned int flags;
    unsigned char IsDisabled() const
    {
        return (flags >> 6) & 1;
    }
    bool InWorld()
    {
        NativeThing* body = native;
        if (!body)
            return false;
        ::FUN_00a29680();
        bool inWorld = body->world != 0;
        ::FUN_00a29680();
        return inWorld;
    }
    int MotionType() const
    {
        return native ? native->motionType : 0;
    }
    bool IsMoving() const
    {
        int motion = MotionType();
        return motion > 0 && (motion <= 3 || motion == 6);
    }
    bool UpdateBody(void*);
};
namespace fnv_00c8dcb0 {
struct S_c8dcb0_Res
{
    struct S_c8dcb0_Obj* p;
    int hi;
};
struct S_c8dcb0_Obj
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
    virtual S_c8dcb0_Obj* v15();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24;
};
S_c8dcb0_Res* __cdecl FUN_00c85ef0(S_c8dcb0_Res*, int, int*);
struct S_c8dcb0_Base
{
    int unk00;
    int unk04;
    int unk08;
    bool FUN_00c85810(int a);
    void UpdateMatchingNodes(int a);
    bool FUN_00c8dcb0(int a);
};
// Calls FUN_00c85810(a); if true calls UpdateMatchingNodes(a), then looks up an object by unk08 and sets its unk24 to a via v15().
// @fnv 0x00c8dcb0
bool S_c8dcb0_Base::FUN_00c8dcb0(int aiValue)
{
    bool r = FUN_00c85810(aiValue);
    if (r)
        UpdateMatchingNodes(aiValue);
    int key = this ? unk08 : 0;
    S_c8dcb0_Res res;
    S_c8dcb0_Obj* o = FUN_00c85ef0(&res, key, &(*reinterpret_cast<int *>(&::g_01267b70)))->p;
    if (o)
    {
        S_c8dcb0_Obj* t = o->v15();
        if (t)
            t->unk24 = aiValue;
    }
    return r;
}
}  // namespace fnv_00c8dcb0

bool __cdecl FUN_00c8cce0(int* type)
{
    bool result = false;
    if (*type > 0 && (*type <= 3 || *type == 6))
        result = true;
    return result;
}

union C8Flags
{
    unsigned int raw;
    struct
    {
        unsigned int type : 7;
        unsigned int rest : 25;
    };
};

struct C8Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C8Flags flags;
};

struct C8Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    C8Base base;
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
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    unsigned char state;
};

struct C8Owner
{
    int unk00;
    int unk04;
    C8Obj* obj;
    void Apply(C8Flags);
    bool SetState(int state);
};

static inline bool IsSpecial(unsigned int t)
{
    return t == 8 || t == 0x1d;
}

// @fnv 0x00c8dd10
bool C8Owner::SetState(int state)
{
    bool result = false;
    C8Obj* o = obj;
    if (o)
    {
        C8Base* b = &o->base;
        C8Flags flags;
        flags.raw = b ? b->flags.raw : 0;
        int iCurrent = o->state;
        if (IsSpecial(flags.type))
        {
            C8Flags newFlags = flags;
            bool hit = FUN_00c8cce0(&state);
            newFlags.type = hit ? 0x1d : 8;
            if (state != iCurrent)
            {
                ::FUN_00a29680();
                o->base.flags = newFlags;
                reinterpret_cast<::FUN_00ca8420_Class *>((o))->FUN_00ca8420(state, true, 0);
                ::FUN_00a29680();
            }
            else
            {
                Apply(newFlags);
            }
            result = true;
        }
        else if (iCurrent != state)
        {
            bool skip = false;
            switch (iCurrent)
            {
            case 4:
            case 5:
                if (FUN_00c8cce0(&state) && reinterpret_cast<::bhkRigidBody *>(this)->GetBodyMass() == 0.0f)
                    skip = true;
                break;
            }
            if (!skip)
            {
                ::FUN_00a29680();
                reinterpret_cast<::FUN_00ca8420_Class *>((o))->FUN_00ca8420(state, true, 0);
                ::FUN_00a29680();
                result = true;
            }
        }
    }
    return result;
}

struct ListNode;

struct ObjBase
{
    virtual void v00();
    virtual void v04();
    virtual ListNode* v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
};

struct ListNode
{
    ObjBase* m_00;
    ListNode* m_04;
};

struct FUN_00c8e770_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    ListNode m_14;
    void ProcessListNodes();
};
// @fnv 0x00c8eb00
void FUN_00c8eb00_s::FUN_00c8eb00()
{
    *(unsigned int*)(this + 0x10) &= 0xffffff77;
    reinterpret_cast<::FUN_00c8e770_cls *>(this)->ProcessListNodes();
    reinterpret_cast<::ActionOwnerC9d590 *>(this)->FUN_00c9d590();
}


// Walks the m_14 list; for each node with an ObjBase, checks its v08 list for DAT_0126818c/DAT_01268158 and calls Helper1/Helper2, invoking vA0 if nonzero.
// @fnv 0x00c8e770
void FUN_00c8e770_cls::ProcessListNodes()
{
    ListNode* n = &m_14;
    while (n)
    {
        if (n->m_04 == 0 && n->m_00 == 0)
            return;
        ObjBase* o = n->m_00;
        if (o)
        {
            int r = 0;
            ListNode* p = o->v08();
            if (p)
            {
                for (; p; p = p->m_04)
                {
                    if (p == (ListNode*)&(*reinterpret_cast<char *>(&::g_0126818c)))
                    {
                        r = ((int)(reinterpret_cast<::RigidLinkSource *>((o))->GetLinkedRecordValue()));
                        goto L_070;
                    }
                }
            }
            p = o->v08();
            if (p)
            {
                for (; p; p = p->m_04)
                {
                    if (p == (ListNode*)&(*reinterpret_cast<char *>(&::g_01268158)))
                    {
                        r = reinterpret_cast<::FUN_00c87a40_obj *>((o))->FUN_00c87a40() != 0;
                        goto L_070;
                    }
                }
            }
            goto L_080;
        L_070:
            if (r)
                o->vA0();
        }
    L_080:
        n = n->m_04;
    }
}

struct C8EC60RTTI
{
    const char* m_pcName;
    const C8EC60RTTI* m_pBaseRTTI;
};

class C8EC60Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual const C8EC60RTTI* GetRTTI() const;
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void ResetWorldObject();

    bool IsKindOfType(const C8EC60RTTI& kRTTI) const
    {
        for (const C8EC60RTTI* pkRTTI = GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
        {
            if (pkRTTI == &kRTTI)
                return true;
        }
        return false;
    }
};

class C8EC60Constraint : public C8EC60Object
{
  public:

};

class C8EC60RefObject : public C8EC60Object
{
  public:

};

class C8EC60Iterator
{
  public:
    C8EC60Object* m_pkCurrent;

};

class C8EC60World
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    C8EC60Iterator m_kIterator;

    C8EC60Iterator* GetIterator()
    {
        return &m_kIterator;
    }
    void FUN_00c8ec60();
};


void* __cdecl FUN_00aa13e0(unsigned int size);

struct OwnerBase
{
    OwnerBase();
    virtual void unkB0();
    ~OwnerBase();
    unsigned int m_04;
    unsigned int m_08;

};

struct Pair8
{
    unsigned int a;
    unsigned int b;
    Pair8()
    {
        a = 0;
        b = 0;
    }
};

struct ChainA_cls : public OwnerBase
{
    virtual void unkA0();
    Pair8 m_0c;
    ChainA_cls()
    {
        DAT_0126810c += 1;
    }
};

struct ChainB_cls : public ChainA_cls
{
    virtual void unkB1();
    ChainB_cls()
    {
        DAT_012681fc += 1;
    }
};

struct SpawnedObject : public ChainB_cls
{
    virtual void unkD2();
    unsigned int m_14;
    unsigned int m_18;
    SpawnedObject()
    {
        m_14 = 0;
        m_18 = 0;
        DAT_012681bc += 1;
    }
};

// Allocates and constructs a new SpawnedObject, incrementing the three global counters in its constructors, and returns it.
// @fnv 0x00c8ed70
SpawnedObject* __cdecl FUN_00c8ed70()
{
    return new SpawnedObject();
}

struct NiNode;
struct HavokShape
{
    void FUN_00c8f080();
    void FUN_00c8eb20(void* context);
};
struct HavokLookup
{
    void* ReportDiagnostic;
    void* unused4;
    void* unused8;
    void* unusedC;
    HavokShape* shape;
};
struct HavokProperty
{
};
struct HavokObject
{
    virtual void Virt0();
    virtual void Virt1();
    virtual void Virt2();
    virtual NiNode* GetCellChildAt();

    unsigned int referenceCount;
    void* extraData;
    void* userData;
    void* collisionData;
    void* owner;
    void* source;
    HavokProperty* property;

};
struct NiTransform
{
    float rotation[3][3];
    float translation[3];
    float scale;
};
struct NiBound
{
    float center[3];
    float radius;
};
struct NiNode
{
    void* vtbl;
    unsigned int referenceCount;
    const char* name;
    void* controller;
    void* extraData;
    unsigned short extraDataCount;
    unsigned short extraDataCapacity;
    void* parent;
    NiBound worldBound;
    NiTransform local;
    NiTransform world;
    void* collisionObject;
    unsigned int flags;
    unsigned int unknown9C;
    HavokObject** children;
    unsigned short maxChildren;
    unsigned short childCount;
};
// @fnv 0x00c8f210
void __cdecl ApplyHavokOperation(HavokObject* object, int operation, void* context)
{
    if (object != 0)
    {
        reinterpret_cast<::NiAVObject *>((object))->UpdateWorldLoc();
        HavokProperty* property = object->property;
        if (property != 0)
        {
            HavokLookup* lookup = ((::HavokLookup *)(reinterpret_cast<::NiObject *>((property))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012043f8))))));
            if (lookup != 0 && lookup->shape != 0)
            {
                if ((char)operation)
                    lookup->shape->FUN_00c8f080();
                else
                    lookup->shape->FUN_00c8eb20(context);
            }
        }
        NiNode* node = object->GetCellChildAt();
        if (node)
        {
            for (unsigned int index = 0; index < node->childCount; ++index)
                ApplyHavokOperation(node->children[index], operation, context);
        }
    }
}

struct NiObject;
struct CloningProcess
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float scale;
};

struct NiCloneable
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3C();
    virtual void V40();
    virtual void V44();
    virtual NiObject* CreateCloneStub(CloningProcess* c);
};

struct CloneNode
{
    NiCloneable* data;
    CloneNode* next;
};

struct hkWorldObjSub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned int flags;
};

struct hkWorldObjStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkWorldObjSub sub;
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
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
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
    hkWorldObjSub* GetSub()
    {
        return this ? &sub : 0;
    }
};
static inline unsigned int GetWFlags(hkWorldObjStub* w)
{
    hkWorldObjSub* s = w ? &w->sub : 0;
    return s ? s->flags : 0;
}
static inline bool WFlag13(hkWorldObjStub* w)
{
    return (GetWFlags(w) >> 13) & 1;
}

struct ScaledBody
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
    float m70[12];
    float vA0[4];
    float fB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    char unkD4;
    void Scale(float s);
};

__declspec(noinline) void ScaledBody::Scale(float s)
{
    float s2 = s * s;
    this->vA0[0] *= s;
    this->vA0[1] *= s;
    this->vA0[2] *= s;
    this->vA0[3] *= s;
    float* p = m70;
    for (int i = 0; i < 3; i++)
    {
        p[0] *= s2;
        p[4] *= s2;
        p[8] *= s2;
        p++;
    }
    this->fB0 *= s;
}

struct RigidBodyS
{
    virtual void V00();
    virtual void V04();
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18();
    virtual void V1C();
    virtual void V20();
    virtual void V24();
    virtual void V28();
    virtual void V2C();
    virtual void V30();
    virtual void V34();
    virtual void V38();
    virtual void V3C();
    virtual void V40();
    virtual void V44();
    virtual void V48();
    virtual void V4C();
    virtual void V50();
    virtual void V54();
    virtual void V58();
    virtual void V5C();
    virtual void V60();
    virtual void V64();
    virtual void V68();
    virtual void V6C();
    virtual void V70();
    virtual void V74();
    virtual void V78();
    virtual void V7C();
    virtual void V80();
    virtual void V84();
    virtual void V88();
    virtual void V8C();
    virtual void V90();
    virtual void V94();
    virtual void V98();
    virtual void V9C();
    virtual void VA0();
    virtual void VA4();
    virtual void VA8();
    virtual void VAC();
    virtual void VB0();
    virtual ScaledBody* GetBodyStub(bool* out);
    virtual void VB8();
    virtual void VBC();
    virtual void VC0();
    virtual void UpdateStub();
    int unk04;
    hkWorldObjStub* unk08;
    int unk0C;
    unsigned int unk10;
    CloneNode list;

    unsigned int GetFlagsW()
    {
        return GetWFlags(unk08);
    }
    unsigned int GetFlagsWith(unsigned int bit)
    {
        unsigned int f = GetFlagsW() | bit;
        return f;
    }
    void SetFlagsW(unsigned int f)
    {
        hkWorldObjStub* w = unk08;
        if (!w)
            return;
        ::FUN_00a29680();
        hkWorldObjSub* s = w->GetSub();
        ::FUN_00a29680();
        if (s)
            s->flags = f;
    }
    bool Flag9() const
    {
        return (unk10 >> 9) & 1;
    }
    void AddClonedStub(NiObject*);
    void CopyBodyToClone(RigidBodyS* dest, CloningProcess* c);
};


struct ThreadFlagsGuard
{
    unsigned int saved;
    ThreadFlagsGuard()
    {
        saved = ::currentAllocationContext;
        ::currentAllocationContext = 0x10;
    }
    ~ThreadFlagsGuard()
    {
        ::currentAllocationContext = saved;
    }
};



struct bhkRefObjectBase
{
    virtual ~bhkRefObjectBase();
    int refCount;
    int unk08;
    bhkRefObjectBase();
};

struct bhkRefObjectLvl : bhkRefObjectBase
{
    struct LinkPair
    {
        void* unk0C;
        void* unk10;
        LinkPair() : unk0C(0), unk10(0)
        {}
    } links;
    bhkRefObjectLvl()
    {
        ++(*reinterpret_cast<unsigned int *>(&::DAT_0126810c));
    }
};

struct bhkSerializableLvl : bhkRefObjectLvl
{
    bhkSerializableLvl()
    {
        ++::DAT_012681fc;
    }
};

struct bhkLiquidAction : bhkSerializableLvl
{
    int unk14;
    int unk18;
    bhkLiquidAction()
    {
        unk14 = 0;
        unk18 = 0;
        ++::DAT_012681bc;
    }
};

struct bhkRigidBodyX
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void SetLockedStub(bool locked);
    bhkLiquidAction* CreateAndAddLiquidAction(::CloningProcess* apCloning);
};

// Creates a new bhkLiquidAction, adds it to the rigid body with param, and returns it while locking and unlocking the world.
// @fnv 0x00c8f400
bhkLiquidAction* bhkRigidBodyX::CreateAndAddLiquidAction(::CloningProcess* apCloning)
{
    ThreadFlagsGuard guard;
    ::FUN_00c876f0();
    SetLockedStub(false);
    bhkLiquidAction* action = new bhkLiquidAction;
    reinterpret_cast<::RigidBodyS *>(this)->CopyBodyToClone((::RigidBodyS *)(action), apCloning);
    SetLockedStub(true);
    ::FUN_00c87700();
    return action;
}


struct ScopedMemoryContext
{
    int iOldContext;
    ScopedMemoryContext(int aiContext)
    {
        iOldContext = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiContext;
    }
    ~ScopedMemoryContext()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = iOldContext;
    }
};

struct GlobalObject_004ee810
{
};

struct FUN_00c9d4c0_holder
{
    void FUN_00c9d4c0();
};

struct Shell_c8da40 : public FUN_00c9d4c0_holder
{
    int unk;
    int unkCur;
    int unkValue;
    int unk0c;
    int uNewnk;
    GlobalObject_004ee810 uTmpnk;

    void FUN_00c8da40();
};

// Switches to memory context 0x10, calls FUN_004ee920 on uTmpnk, then calls FUN_00c9d4c0.
// @fnv 0x00c8da40
void Shell_c8da40::FUN_00c8da40()
{
    ScopedMemoryContext kContext(0x10);
    reinterpret_cast<::ListX *>(&(uTmpnk))->FUN_004ee920();
    FUN_00c9d4c0();
}

struct C8DAC0RTTI
{
    const char* m_pcName;
    const C8DAC0RTTI* m_pBaseRTTI;
};
class C8DAC0Object
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual const C8DAC0RTTI* GetRTTI() const;
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void Update(void* pvContext);
};
inline bool C8DAC0IsKindOf(const C8DAC0RTTI& kRTTI, const C8DAC0Object* pkObject)
{
    if (!pkObject)
        return false;
    for (const C8DAC0RTTI* pkRTTI = pkObject->GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
    {
        if (pkRTTI == &kRTTI)
            return true;
    }
    return false;
}
struct C8DAC0Node
{
    C8DAC0Object* m_pPointer;
    C8DAC0Node* m_pkNext;
};
class C8DAC0Owner
{
  public:
    virtual ~C8DAC0Owner();

    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int m_uiValue1;
    C8DAC0Node m_kHead;

    unsigned int GetField(unsigned int uiMask, unsigned int uiPos) const
    {
        return (m_uiValue1 & uiMask) >> uiPos;
    }

    void UpdateMatchingNodes(void* pvContext);
};
// @fnv 0x00c8dac0
void C8DAC0Owner::UpdateMatchingNodes(void* pvContext)
{
    bool bFilterByKind = (bool)(GetField(4, 2) & 1);
    for (C8DAC0Node* pkNode = &m_kHead; pkNode; pkNode = pkNode->m_pkNext)
    {
        if (!pkNode->m_pPointer)
            break;
        bool bMatch = bFilterByKind &&
                      C8DAC0IsKindOf(reinterpret_cast<const C8DAC0RTTI&>((*reinterpret_cast<char *>(&::g_0126818c))), pkNode->m_pPointer) &&
                      C8DAC0IsKindOf(reinterpret_cast<const C8DAC0RTTI&>((*reinterpret_cast<char *>(&::g_01268628))), pkNode->m_pPointer);
        if (!bFilterByKind || bMatch)
            pkNode->m_pPointer->Update(pvContext);
    }
}

// Define the known helper from the preserved surrounding source.
struct LiquidBase
{
    virtual ~LiquidBase();
    unsigned int refCount, unk08, unk0c, unk10;
};
struct LiquidLink
{
    ~LiquidLink();
};
struct FUN_00c8e9c0 : LiquidBase
{
    LiquidLink link;
    virtual ~FUN_00c8e9c0();
};
// Destructor that calls FUN_00c8da40 and decrements g_iLiquidActionCount.
// @fnv 0x00c8e9c0
FUN_00c8e9c0::~FUN_00c8e9c0()
{
    reinterpret_cast<::Shell_c8da40 *>(this)->FUN_00c8da40();
    --::DAT_012681bc;
}

struct AllocTagScopeC8E
{
    int m_iSaved;

    AllocTagScopeC8E(int aiAllocationTag)
    {
        m_iSaved = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiAllocationTag;
    }
    ~AllocTagScopeC8E()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iSaved;
    }
};
class NiRTTIC8E
{
  public:
    const char* m_pcName;
    const NiRTTIC8E* m_pBaseRTTI;

    const NiRTTIC8E* GetBaseRTTI() const
    {
        return m_pBaseRTTI;
    }
};
class NiObjectC8E
{
  public:
    virtual ~NiObjectC8E();
    virtual void DeleteThis();
    virtual const NiRTTIC8E* GetRTTI() const;

    bool IsKindOfType(const NiRTTIC8E& kRTTI) const
    {
        for (const NiRTTIC8E* pkRTTI = GetRTTI(); pkRTTI; pkRTTI = pkRTTI->GetBaseRTTI())
        {
            if (pkRTTI == &kRTTI)
                return true;
        }
        return false;
    }

    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }

    unsigned int m_uiRefCount;
};
template <class T> class NiPointerC8E
{
  public:
    NiPointerC8E(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~NiPointerC8E()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }

    T* m_pObject;
};
struct ListItemC8E
{
    ListItemC8E* m_pkNext;
    ListItemC8E* m_pkPrev;
    NiObjectC8E* m_pkElement;
};
ListItemC8E* __cdecl NewListItemC8E(NiObjectC8E* pkObject);
class ObjectListC8E
{
  public:
    __declspec(noinline) void AddTail(const NiPointerC8E<NiObjectC8E>& spRetainedObject)
    {
        ListItemC8E* pkItem = NewListItemC8E(spRetainedObject.m_pObject);
        pkItem->m_pkNext = 0;
        pkItem->m_pkPrev = m_pkTail;
        if (m_pkTail)
            m_pkTail->m_pkNext = pkItem;
        else
            m_pkHead = pkItem;
        m_pkTail = pkItem;
        m_uiCount++;
    }

    ListItemC8E* m_pkHead;
    ListItemC8E* m_pkTail;
    unsigned int m_uiCount;
};
class SceneC8E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    ObjectListC8E m_kThirdFollowingStreamField;

    void FUN_00c8ef80(NiObjectC8E* pkObject);
};
// Calls FUN_00c859e0, reads a count from the stream, then reads that many NiObjects and passes each non-null one to FUN_00c8ef80.
// @fnv 0x00c8f3c0
void bhkRigidBody::FUN_00c8f3c0(NiStream* stream)
{
    reinterpret_cast<::S00c859e0_cls *>(this)->FUN_00c859e0(stream);
    unsigned int count = reinterpret_cast<::FUN_00a63460_shell *>((stream))->FUN_00a63460();
    for (unsigned int i = 0; i < count; ++i)
    {
        NiObject* obj = stream->GetLoadedObject();
        if (obj)
            reinterpret_cast<::SceneC8E *>(this)->FUN_00c8ef80((::NiObjectC8E *)(obj));
    }
}
// Copies body members into dest, scales the body stub when c->scale != 1, sets unk28 from unk08->unk210, and clones list nodes into dest.
// @fnv 0x00c8f2a0
void RigidBodyS::CopyBodyToClone(RigidBodyS* dest, CloningProcess* c)
{
    bool b;
    ScaledBody* body = GetBodyStub(&b);
    if (Flag9())
        body->unkD4 = 1;
    float s = c->scale;
    if (s != 1.0f)
        reinterpret_cast<::ScaleOwner *>((body))->FUN_00c8cdf0(s);
    body->unk28 = unk08->unk210;
    reinterpret_cast<::WorldObjectView *>(this)->FUN_00c85900((int)(dest), (int)(c));
    dest->unk10 = (dest->unk10 | unk10) & 0xfffffc07;
    CloneNode* n = &list;
    if (WFlag13(unk08) || c->scale != 1.0f)
    {
        dest->SetFlagsW(dest->GetFlagsWith(0x2000));
        dest->UpdateStub();
    }
    for (; n && n->data; n = n->next)
        reinterpret_cast<::SceneC8E *>((reinterpret_cast<bhkRigidBody*>(dest)))->FUN_00c8ef80((::NiObjectC8E *)(::NiObject *)(n->data->CreateCloneStub(c)));
}
// Adds pkObject to the object list if it is a geometry or node, using an allocation tag scope of 0x10.
// @fnv 0x00c8ef80
void SceneC8E::FUN_00c8ef80(NiObjectC8E* pkObject)
{
    AllocTagScopeC8E kScope(0x10);
    if (pkObject && (pkObject->IsKindOfType((*reinterpret_cast<const ::NiRTTIC8E *>(&::g_0126818c))) || pkObject->IsKindOfType((*reinterpret_cast<const ::NiRTTIC8E *>(&::g_01268158)))))
        reinterpret_cast<::RefOwner *>(&(m_kThirdFollowingStreamField))->FUN_00c80a30((int *)&(const ::NiPointerC8E< ::NiObjectC8E> &)(pkObject));
}

struct RefCountedObj
{
    virtual void v0();
    virtual void Destroy();
    long m_iRef;
};

struct LinkNode
{
    RefCountedObj* m_pEntryObject;
    LinkNode* m_pNext;
};

struct LinkNodePool
{
};

class FUN_00c88990_cls
{
  public:
    RefCountedObj* m_pEntryObject;
    LinkNode* m_pNext;
    void PopAndRelease();
};
// Iterates the world's objects and calls ResetWorldObject on constraints and ref objects that hold a non-null constraint or referenced data.
// @fnv 0x00c8ec60
void C8EC60World::FUN_00c8ec60()
{
    C8EC60Iterator* pkIter = GetIterator();
    while (pkIter && pkIter->m_pkCurrent)
    {
        C8EC60Object* pkObject = pkIter->m_pkCurrent;
        if (pkObject->IsKindOfType((*reinterpret_cast<const ::C8EC60RTTI *>(&::g_0126818c))))
        {
            if (reinterpret_cast<::RigidLinkSource *>((static_cast<C8EC60Constraint*>(pkObject)))->GetLinkedRecordValue() != 0)
                pkObject->ResetWorldObject();
        }
        else if (pkObject->IsKindOfType((*reinterpret_cast<const ::C8EC60RTTI *>(&::g_01268158))))
        {
            if (reinterpret_cast<::FUN_00c87a40_obj *>((static_cast<C8EC60RefObject*>(pkObject)))->FUN_00c87a40())
                pkObject->ResetWorldObject();
        }
        reinterpret_cast<::FUN_00c88990_cls *>((pkIter))->PopAndRelease();
    }
}

// @fnv 0x00c88990
void FUN_00c88990_cls::PopAndRelease()
{
    LinkNode* node = m_pNext;
    if (node != 0)
    {
        m_pNext = node->m_pNext;
        RefCountedObj* pOldObject = m_pEntryObject;
        if (pOldObject != node->m_pEntryObject)
        {
            if (pOldObject != 0)
            {
                if (InterlockedDecrement(&pOldObject->m_iRef) == 0)
                    pOldObject->Destroy();
            }
            m_pEntryObject = node->m_pEntryObject;
            if (m_pEntryObject != 0)
                InterlockedIncrement(&m_pEntryObject->m_iRef);
        }

        node->m_pNext = 0;
        reinterpret_cast<::FUN_004ee840_cls *>((node))->FUN_004ee840_cls::~FUN_004ee840_cls();
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::LinkNodePool *>(&::g_memoryManager))))->FUN_00aa4060(node);
    }
    else
    {
        RefCountedObj* obj = m_pEntryObject;
        if (obj != 0)
        {
            if (InterlockedDecrement(&obj->m_iRef) == 0)
                obj->Destroy();
            m_pEntryObject = 0;
        }
    }
}

// Recursively visits child nodes, calling FUN_00c8ec60 on the linked shape found via FUN_00653290 on each object's property when present.
// @fnv 0x00c8ecf0
void __cdecl FUN_00c8ecf0(HavokObject* object)
{
    if (!object)
        return;

    if (object->property)
    {
        HavokLookup* link = ((::HavokLookup *)(reinterpret_cast<::NiObject *>((object->property))->DynamicCast((const ::NiRTTI *)(const void *)(&(*reinterpret_cast<char *>(&::g_012043f8))))));
        if (link && link->shape)
            reinterpret_cast<C8EC60World*>(link->shape)->FUN_00c8ec60();
    }

    NiNode* node = object->GetCellChildAt();
    if (node)
    {
        for (unsigned int i = 0; i < node->childCount; ++i)
            FUN_00c8ecf0(node->children[i]);
    }
}

#include <xmmintrin.h>
#include "fnv/symbols_simd.h"
#include "fnv/decl/C74C20Quat.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_005610f0_cls.h"
#include "fnv/decl/FUN_005611c0_t.h"
#include "fnv/decl/FUN_005616d0_Owner.h"
#include "fnv/decl/FUN_00561800_Class.h"
#include "fnv/decl/Quat74.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S_00c8cd20_object.h"
#include "fnv/decl/fnv_005617c0__FUN_005617c0_.h"
#include "fnv/decl/fnv_00626cb0__FUN_00626cb0_Class.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_0106b000.h"
#include "fnv/symbols_01095000.h"
#include "fnv/symbols_010c6000.h"
#include "fnv/symbols_011af000.h"
#include <math.h>
struct hkVector
{
    __m128 m_vComponents;
    hkVector()
    {}
    hkVector(const hkVector& v)
    {
        m_vComponents = v.m_vComponents;
    }
};
namespace c8d {
struct Body
{
    char pad[0x170];
    hkVector m_kPos;
};
struct Ent
{
    int unk;
    int unkCur;
    Body* m_pPhysicsBody;
    hkVector FUN_00c8d200();
};
// Returns the physics body's m_kPos, or the global DAT_01267e30 vector when this or the body pointer is null.
// @fnv 0x00c8d200
hkVector Ent::FUN_00c8d200()
{
    const hkVector* p;
    if (this && m_pPhysicsBody)
        p = &m_pPhysicsBody->m_kPos;
    else
        p = &(*reinterpret_cast<::hkVector *>(&::DAT_01267e30));
    return *p;
}
}

struct __declspec(align(16)) hkVector4
{
    __m128 m_vComponents;
    hkVector4()
    {}
    hkVector4(const hkVector4& o) : m_vComponents(o.m_vComponents)
    {}
    hkVector4& operator=(const hkVector4& o)
    {
        m_vComponents = o.m_vComponents;
        return *this;
    }
};


struct Inner
{
    char pad0[0x140];
    hkVector4 m_vec;
};

struct Outer
{
    char pad0[8];
    Inner* m_pChildAtom;
    hkVector4 GetVec() const;
};

// Returns m_pChildAtom->m_vec when m_pChildAtom is non-null, otherwise returns g_zero.
// @fnv 0x00c8d240
hkVector4 Outer::GetVec() const
{
    const hkVector4* p = (this && m_pChildAtom) ? &m_pChildAtom->m_vec : &(*reinterpret_cast<::hkVector4 *>(&::DAT_01267e30));
    return *p;
}

struct Transform_c8d3
{
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_vTranslation;
};

struct Aabb_c8d3
{
    __m128 m_kMinimumCorner;
    __m128 m_kMaximumCorner;
};

class Shape_c8d3
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void getAabb(const Transform_c8d3& kLocalToWorld, float fTolerance, Aabb_c8d3& kOut) const;
};

struct CdBody_c8d3
{
    Shape_c8d3* m_pkShape;
    Shape_c8d3* getShape() const
    {
        return m_pkShape;
    }
};

struct EntityBase_c8d3
{
    int unk00, unk04, unk08, unk0c;
};

struct Entity_c8d3 : public EntityBase_c8d3, public CdBody_c8d3
{
};

class WorldObject_c8d3
{
  public:
    int unk00;
    int unk04;
    Entity_c8d3* m_pkEntity;

    void GetAabb(Aabb_c8d3& kOut);
};

// Fills kOut from the entity shape's getAabb (global transform DAT_01268370, tolerance 0.001), or a +-0.001 box around zero when there is no shape.
// @fnv 0x00c8d390
void WorldObject_c8d3::GetAabb(Aabb_c8d3& kOut)
{
    CdBody_c8d3* pkBody = 0;
    if (this)
    {
        Entity_c8d3* pkEntity = m_pkEntity;
        if (pkEntity)
        {
            ::FUN_00a29680();
            pkBody = static_cast<CdBody_c8d3*>(pkEntity);
            ::FUN_00a29680();
        }
    }
    Shape_c8d3* pkShape = pkBody ? pkBody->getShape() : 0;
    if (pkShape)
    {
        pkShape->getAabb((*reinterpret_cast<::Transform_c8d3 *>(&::DAT_01268370)), 0.001f, kOut);
    }
    else
    {
        kOut.m_kMinimumCorner = _mm_setr_ps(-0.001f, -0.001f, -0.001f, 0.0f);
        kOut.m_kMaximumCorner = _mm_setr_ps(0.001f, 0.001f, 0.001f, 0.0f);
    }
}

namespace fnv_00c8d510 {
struct hkVector4
{
    __m128 m_vComponents;
    hkVector4& operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
        return *this;
    }
};

struct OldCinfo
{
    int m_pCollisionShape;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int m_uiCollisionFilterData;
    char m_eCollisionResponse;
    char unk29;
    unsigned short m_usProcessContactCallbackDelay;
    int unk2C;
    hkVector4 m_vContactPosition;
    hkVector4 m_rotation;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    hkVector4 m_inertiaRow0;
    hkVector4 m_inertiaRow1;
    hkVector4 m_inertiaRow2;
    hkVector4 m_kCenterOfMass1;
    float m_fViscosityFriction;
    float m_fLinearDamping;
    float m_fAngularDamping;
    float m_fSlipAngle;
    float m_fElasticity;
    float m_fSurfaceFriction;
    float m_fRestitution;
    float m_fAllowedPenetrationDepth;
    signed char m_bFlag;
    char m_bEnableDeactivation;
    char m_qualityType2;
    signed char m_iAutoRemoveLevel;
};

struct BhkRigidBody
{
    int m_pCollisionShape;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_shape2;
    int m_uiCollisionFilterData;
    int unk28;
    char m_eCollisionResponse;
    char unk2D;
    unsigned short m_usProcessContactCallbackDelay;
    hkVector4 m_vContactPosition;
    hkVector4 m_rotation;
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    hkVector4 m_inertiaRow0;
    hkVector4 m_inertiaRow1;
    hkVector4 m_inertiaRow2;
    hkVector4 m_kCenterOfMass1;
    float m_fViscosityFriction;
    float m_fLinearDamping;
    float m_fAngularDamping;
    float m_fGravityFactor;
    float m_fSlipAngle;
    float m_fElasticity;
    float m_fSurfaceFriction;
    float m_fRestitution;
    float m_fAllowedPenetrationDepth;
    char m_bFlag;
    char m_bRigidBodyFlag;
    char m_bEnableDeactivation;
    char m_iAutoRemoveLevel;

    BhkRigidBody& FromOldCinfo(const OldCinfo& src);
};

// Copies collision and motion fields from src, remapping motion, deactivation, and quality values into BhkRigidBody fields.
// @fnv 0x00c8d510
BhkRigidBody& BhkRigidBody::FromOldCinfo(const OldCinfo& src)
{
    m_fGravityFactor = 1.0f;
    unk28 = 0;
    m_shape2 = m_pCollisionShape = src.m_pCollisionShape;
    m_uiCollisionFilterData = src.m_uiCollisionFilterData;
    m_eCollisionResponse = src.m_eCollisionResponse;
    m_usProcessContactCallbackDelay = src.m_usProcessContactCallbackDelay;
    m_vContactPosition = src.m_vContactPosition;
    m_rotation = src.m_rotation;
    m_kTranslationalVelocity = src.m_kTranslationalVelocity;
    m_kAngularVelocity = src.m_kAngularVelocity;
    m_inertiaRow0 = src.m_inertiaRow0;
    m_inertiaRow1 = src.m_inertiaRow1;
    m_inertiaRow2 = src.m_inertiaRow2;
    m_kCenterOfMass1 = src.m_kCenterOfMass1;
    m_fViscosityFriction = src.m_fViscosityFriction;
    m_fLinearDamping = src.m_fLinearDamping;
    m_fAngularDamping = src.m_fAngularDamping;
    m_fSlipAngle = src.m_fSlipAngle;
    m_fElasticity = src.m_fElasticity;
    m_fSurfaceFriction = src.m_fSurfaceFriction;
    m_fRestitution = src.m_fRestitution;
    m_fAllowedPenetrationDepth = src.m_fAllowedPenetrationDepth;
    unsigned int motion = src.m_bFlag;
    if (motion >= 5)
        motion -= 2;
    else if (motion >= 3)
        motion--;
    m_bFlag = (char)motion;
    m_bRigidBodyFlag = src.m_bEnableDeactivation == 2;
    m_bEnableDeactivation = src.m_qualityType2;
    int quality = src.m_iAutoRemoveLevel;
    if (quality < 3)
        quality--;
    m_iAutoRemoveLevel = (char)quality;
    return *this;
}
}  // namespace fnv_00c8d510

struct BuildSettings
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    float fB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    float fC4;
    float fC8;
    unsigned int unkCC;
    float fD0;
    signed char motionType, response, quality, solver;
    unsigned char unkD8, unkD9, callback, unkDB;
};
struct FUN_00ca8c90;
struct BodyAllocator
{
    virtual void unused();
    virtual FUN_00ca8c90* Allocate(unsigned int size);
};
struct BodyMemory
{
    unsigned int unk00, unk04, unk08, unk0C;
    BodyAllocator* allocator;
    void* AllocateBody(unsigned int size)
    {
        return allocator->Allocate(size);
    }
};
BodyMemory* FUN_00c85750();
struct FUN_00ca8c90
{
    unsigned int unk00;
    unsigned short allocationSize, references;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    FUN_00ca8c90(void* settings);
    static void* operator new(std::size_t size)
    {
        FUN_00ca8c90* p = (FUN_00ca8c90*)FUN_00c85750()->AllocateBody(size);
        p->allocationSize = (unsigned short)size;
        return p;
    }
    static void operator delete(void* p);
};
struct BodyMotion
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14;
    unsigned char unk18, unk19, quality;
};
struct BodyNative
{
    unsigned int unk00, unk04, unk08, unk0C;
    BodyMotion motion;
};
struct Bounds
{
    __m128 minimum;
    __m128 maximum;
};
extern float DAT_012677bc;
extern float DAT_012677c0;
extern float DAT_011b0c48;
struct BodyBuild
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void SetBody(FUN_00ca8c90* body);
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void FinishBuild(BuildSettings* settings);
    unsigned int unk04;
    BodyNative* native;
    BodyMotion* GetMotion()
    {
        BodyNative* p = native;
        if (!p)
            return 0;
        ::FUN_00a29680();
        BodyMotion* result = p ? &p->motion : 0;
        ::FUN_00a29680();
        return result;
    }
    void ConfigureBody(BuildSettings* settings);
};
// Clamps BuildSettings fields, allocates a body via operator new, sets motion and solver, adjusts quality from bounds, then calls FinishBuild.
// @fnv 0x00c8d650
void BodyBuild::ConfigureBody(BuildSettings* settings)
{
    ThreadFlagsGuard guard;
    int savedMotion = 8;
    if (settings->fD0 <= 1.1920928955078125e-7f || settings->fD0 > 0.20000000298023224)
        settings->fD0 = 0.15f;
    if (settings->fC8 < 1000.0)
        settings->fC8 = 1000.0f;
    if (settings->fC4 >= 1.9900000095367432)
        settings->fC4 = 1.98f;
    if (settings->fB0 != 0.0f)
    {
        int motion = settings->motionType;
        bool special = motion == 4 || motion == 5;
        if (special)
        {
            savedMotion = motion;
            settings->motionType = 1;
            settings->solver = 4;
        }
        else if (settings->solver == -1)
        {
            settings->solver = 4;
        }
    }
    else if (settings->motionType == 5)
    {
        settings->solver = 0;
    }
    if (settings->quality >= 5 || settings->quality <= 0)
        settings->quality = 2;
    settings->callback = 3;
    settings->unk20 = settings->unk00;
    settings->unk24 = settings->unk04;
    FUN_00ca8c90* body = new FUN_00ca8c90(&settings->unk20);
    if (savedMotion != 8)
    {
        settings->motionType = (signed char)savedMotion;
        reinterpret_cast<::FUN_00ca8420_Class *>((body))->FUN_00ca8420(savedMotion, 1, 0);
    }
    SetBody(body);
    reinterpret_cast<::hkReferencedObjectC905 *>((body))->FUN_00c905b0();
    int motion = settings->motionType;
    if (motion > 0 && (motion <= 3 || motion == 6) && settings->motionType > 0)
    {
        BodyMotion* nativeMotion = GetMotion();
        if (nativeMotion)
        {
            Bounds bounds;
            reinterpret_cast<::WorldObject_c8d3 *>(this)->GetAabb((*(::Aabb_c8d3 *)(&bounds)));
            __m128 extent = _mm_sub_ps(bounds.maximum, bounds.minimum);
            int axis;
            if (extent[0] > extent[1])
                axis = extent[1] > extent[2] ? 2 : 1;
            else
                axis = extent[0] > extent[2] ? 2 : 0;
            if (!(extent[axis] > DAT_012677bc))
            {
                float scale = reinterpret_cast<::Obj577 *>(this)->FUN_00577b50();
                scale *= DAT_011b0c48;
                if (!(scale < DAT_012677c0))
                {
                    if (settings->solver == 2)
                    {
                        nativeMotion->quality = 4;
                        settings->solver = 4;
                    }
                }
                else
                {
                    nativeMotion->quality = 2;
                    settings->solver = 2;
                }
            }
            else
            {
                nativeMotion->quality = 2;
                settings->solver = 2;
            }
        }
    }
    FinishBuild(settings);
}

struct Matrix
{
    __m128 columns[4];
};
struct Receiver
{
    void FUN_00c7f640(Matrix*, const __m128*);
};
struct BodySlot
{
    void* body;
    __forceinline void* getBody()
    {
        if (this)
            return body;
        return 0;
    }
};
struct CollisionOwner
{
    void* vtable;
    void* unk04;
    void* node;
    void DispatchCollision(Receiver*);
    __forceinline BodySlot* GetSlot()
    {
        char* base = (char*)node;
        if (base)
        {
            ::FUN_00a29680();
            base += 16;
            ::FUN_00a29680();
            if (base)
                return (BodySlot*)base;
        }
        return 0;
    }
};
// Gets a matrix via virtual slot 61, then passes it to the body slot's virtual 7 if present, otherwise to target and target+16 with fixed vectors.
// @fnv 0x00c8e670
void CollisionOwner::DispatchCollision(Receiver* target)
{
    __m128 second, first;
    __declspec(align(16)) Matrix source;
    typedef void(* GetSource)(CollisionOwner*, Matrix*);
    ((GetSource)((void**)vtable)[61])(this, &source);
    BodySlot* slot = GetSlot();
    void* body = slot ? slot->getBody() : 0;
    if (body)
    {
        typedef void(* Dispatch)(void*, Matrix*, float, Receiver*);
        ((Dispatch)((void**)*(void* volatile*)body)[7])(body, &source, ::AngularDashpotApplyD4DCB0::DAT_01017d00, target);
    }
    else
    {
        first = _mm_setr_ps(DAT_0104ffb8, DAT_0104ffb8, DAT_0104ffb8, ::DAT_01011d78);
        second = _mm_setr_ps(::AngularDashpotApplyD4DCB0::DAT_01017d00, ::AngularDashpotApplyD4DCB0::DAT_01017d00, ::AngularDashpotApplyD4DCB0::DAT_01017d00, ::DAT_01011d78);
        target->FUN_00c7f640(&source, &first);
        ((Receiver*)((char*)target + 16))->FUN_00c7f640(&source, &second);
    }
}

namespace fnv_00c8e800 {
struct RTTI
{
    const char* name;
    const RTTI* parent;
};
struct Node;
struct Collision;
struct Object
{
    virtual void Slot0();
    virtual void Slot1();
    virtual const RTTI* GetRTTI();
    virtual Node* GetAsNode();
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18;
    Collision* collision;
};
struct Vector
{
    __m128 value;
    void Interpolate(const Vector& oldValue, const Vector& newValue, float factor)
    {
        __m128 weight = _mm_set1_ps(factor);
        value = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(::DAT_010ec7f0, weight), oldValue.value),
                           _mm_mul_ps(weight, newValue.value));
    }
};
struct Body
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void GetNavMeshData(Vector* out);
};
struct Collision : Object
{
};
struct CollisionBody : Object
{
};
struct Node : Object
{
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
    Object** children;
    unsigned short capacity;
    unsigned short count;
};
struct CollisionData
{
    virtual void Slot0();
    virtual void Slot1();
    virtual const RTTI* GetRTTI();
    unsigned int unk04, unk08, unk0c;
    Body* body;
};
inline bool IsKindOfType(Collision* object)
{
    const RTTI* type = object->GetRTTI();
    while (type)
    {
        if (type == &(*reinterpret_cast<::fnv_00c8e800::RTTI *>(&::g_012043f8)))
            return true;
        type = type->parent;
    }
    return false;
}
// Recursively walks a node's children, then adds the collision body's mass to total and blends center toward the body's nav-mesh data by the mass ratio.
// @fnv 0x00c8e800
void __cdecl AccumulateCenterOfMass(Object* object, Vector* center, float* total)
{
    if (!object)
        return;
    Node* node = object->GetAsNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->count; ++i)
            AccumulateCenterOfMass(node->children[i], center, total);
    }
    Collision* collision = object->collision;
    if (!collision)
        return;
    CollisionData* data = IsKindOfType(collision) ? reinterpret_cast<CollisionData*>(collision) : 0;
    if (!data)
        return;
    Body* body = data->body;
    if (!body)
        return;
    float mass = reinterpret_cast<::bhkRigidBody *>((body))->GetBodyMass();
    Vector next;
    body->GetNavMeshData(&next);
    *total += mass;
    float factor = mass / *total;
    center->Interpolate(*center, next, factor);
}
}  // namespace fnv_00c8e800



// Calls AccumulateCenterOfMass with a broadcast of g_fConst01011d78, then stores the resulting __m128 into out and the float result into pf.
// @fnv 0x00c8e940
void __cdecl GetScalarAndVector(void* a, __m128* out, float* pf)
{
    float f = 0.0f;
    __m128 v = _mm_setr_ps(::DAT_01011d78, ::DAT_01011d78, ::DAT_01011d78, ::DAT_01011d78);
    ::fnv_00c8e800::AccumulateCenterOfMass((::fnv_00c8e800::Object *)(a), (::fnv_00c8e800::Vector *)(::__m128 *)(&v), &f);
    *out = v;
    *pf = f;
}

struct BinaryStream_c8ea
{
    int unk00;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(BinaryStream_c8ea* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int Read(void* pvBuffer, unsigned int uiBytes)
    {
        unsigned int uiSize = 4;
        unsigned int uiRead = m_pfnRead(this, pvBuffer, uiBytes, &uiSize, 1);
        m_uiStreamFlags += uiRead;
        return uiRead;
    }
};

class RigidBody_c8ea
{
  public:
    unsigned int m_uiValue1;
};

class WorldObject_c8ea
{
  public:
    virtual void v00();
};

struct LoadStream_c8ea
{
};

class Entity_c8ea : public WorldObject_c8ea
{
  public:
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual char* GetRigidBody(int* piIndex);

    int unk04, unk08, unk0c;
    int m_iSlotCount;

    void FUN_00c8ea30(char* pkStream);
};

// Calls FUN_00c9d4f0, swaps the rigid body's endianness unless a stream byte is 1, clamps a float to 1000, may set a type byte, and reads m_iSlotCount.
// @fnv 0x00c8ea30
void Entity_c8ea::FUN_00c8ea30(char* pkStream)
{
    reinterpret_cast<::FUN_00c9d4f0_cls *>(this)->FUN_00c9d4f0((::FUN_00c9d4f0_obj *)(pkStream));
    char* pkBody;
    {
        int iIndex;
        pkBody = GetRigidBody(&iIndex);
    }
    if (*(unsigned char*)(pkStream + 0x1e5) != 1)
        reinterpret_cast<::SwapBlock_c8ce70 *>((((RigidBody_c8ea*)pkBody)))->SwapEndian();
    if (*(float*)(pkBody + 0xc8) > 1000.0)
        *(float*)(pkBody + 0xc8) = 1000.0f;
    if (*(float*)(pkBody + 0xb0) == 0.0f && reinterpret_cast<::bhkRigidBody *>(this)->GetBodyMass() == 0.0f)
    {
        unsigned int uiType = ((RigidBody_c8ea*)pkBody)->m_uiValue1 & 0x7f;
        if (uiType != 2 && uiType != 0x1c)
            *(unsigned char*)(pkBody + 0xd4) = 5;
        if (uiType == 0xe)
            *(unsigned char*)(pkBody + 0xd4) = 4;
    }
    reinterpret_cast<::S_00a64670_Foo *>((((LoadStream_c8ea*)pkStream)))->FUN_00a64670();
    (*(BinaryStream_c8ea**)(pkStream + 0x24c))->Read(&m_iSlotCount, 4);
}

extern "C" void _ReadWriteBarrier(void);

struct RTTI_eb20
{
    const char* m_pcName;
    const RTTI_eb20* m_pBaseRTTI;
};

class Constraint_eb20
{
  public:
    virtual ~Constraint_eb20();
    virtual void DeleteThis();
    virtual const RTTI_eb20* GetRTTI() const;
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void SetWorld(int iWorld);
    virtual void RegisterWithWorld();

    bool IsKindOfType(const RTTI_eb20& kRTTI) const
    {
        for (const RTTI_eb20* pkRTTI = GetRTTI(); pkRTTI; pkRTTI = pkRTTI->m_pBaseRTTI)
        {
            if (pkRTTI == &kRTTI)
                return true;
        }
        return false;
    }

};

struct ConstraintList_eb20
{
    Constraint_eb20* m_pkItem;
    ConstraintList_eb20* m_pkNext;
};

struct WorldData_eb20
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int m_iWorld;
};

struct RefObject_eb20
{
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0c;
    unsigned int m_uiValue1;
    ConstraintList_eb20 m_kConstraints;

    int GetWorld()
    {
        WorldData_eb20* pkData = (WorldData_eb20*)reinterpret_cast<::FUN_00c87a40_obj *>(this)->FUN_00c87a40();
        return pkData ? pkData->m_iWorld : 0;
    }
    unsigned char IsInWorld() const
    {
        return (m_uiValue1 >> 2) & 1;
    }
    void FUN_00c8eb20(bool bSetWorld);
};

struct MemContextGuard_eb20
{
    int m_iOldContext;
    MemContextGuard_eb20(int aiMemoryContext)
    {
        m_iOldContext = (*reinterpret_cast<int *>(&::currentAllocationContext));
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
    }
    ~MemContextGuard_eb20()
    {
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = m_iOldContext;
    }
};


// If in a world, registers linked constraints and pops them, sets the world on the others when bSetWorld is true, then clears the in-world bit.
// @fnv 0x00c8eb20
void RefObject_eb20::FUN_00c8eb20(bool bSetWorld)
{
    MemContextGuard_eb20 kGuard(0x10);
    if (IsInWorld())
    {
        int iWorld = GetWorld();
        _ReadWriteBarrier();
        if (iWorld)
        {
            ConstraintList_eb20* pkNode = &m_kConstraints;
            if (pkNode)
            {
                do
                {
                    Constraint_eb20* pkItem = pkNode->m_pkItem;
                    if (!pkItem)
                        break;
                    Constraint_eb20* pkConstraint =
                        pkItem->IsKindOfType(reinterpret_cast<const RTTI_eb20&>((*reinterpret_cast<char *>(&::g_0126818c)))) ? pkItem : 0;
                    if (pkConstraint)
                    {
                        if (reinterpret_cast<::RigidLinkSource *>((pkConstraint))->GetLinkedRecordValue())
                        {
                            pkConstraint->RegisterWithWorld();
                            reinterpret_cast<::FUN_00c88990_cls *>(&(m_kConstraints))->PopAndRelease();
                        }
                        else
                        {
                            pkNode = pkNode->m_pkNext;
                            if (bSetWorld)
                                pkConstraint->SetWorld(iWorld);
                        }
                    }
                } while (pkNode);
            }
            m_uiValue1 &= ~4u;
        }
    }
}

extern "C" unsigned long __readfsdword(unsigned long);
struct TlsBlock
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
};
struct MemScope
{
    TlsBlock* block;
    int saved;
    MemScope()
    {
        unsigned int index = *(volatile unsigned int*)&DAT_0126fd98;
        block = ((TlsBlock**)__readgsqword(0x58))[index];
        saved = block->unk2b4;
        block->unk2b4 = 16;
    }
    ~MemScope()
    {
        block->unk2b4 = saved;
    }
};
struct RTTI
{
    const char* name;
    RTTI* parent;
};
struct Obj
{
    virtual void v0();
    virtual void v1();
    virtual RTTI* type();
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
    virtual void attach(void*);
    virtual void detach();
    bool isType(const RTTI* p)
    {
        RTTI* r = type();
        while (r)
        {
            if (r == p)
                return true;
            r = r->parent;
        }
        return false;
    }
public:
    bool FUN_00c85810(::Obj *);
};
// @fnv 0x00c8db50
bool BodyUpdate::UpdateBody(void* update)
{
    NativeLink link;
    NativeThing* object = FUN_00c85ef0(&link, this ? native : 0, &(*reinterpret_cast<::NiRTTI *>(&::g_01267b70)))->object;
    NativeData* data = object ? object->GetData() : 0;
    bool bUnitScale = data && data->factor18 == 1.0f && data->factor1c == 1.0f;
    if ((!bUnitScale || data->count > 0 || DAT_011afe59) && !IsDisabled())
    {
        bool result = reinterpret_cast<::Obj *>(this)->FUN_00c85810((::Obj *)(update));
        if (result || (InWorld() && IsMoving()))
        {
            if ((!bUnitScale || data->count > 0) && !IsDisabled())
                reinterpret_cast<::C8DAC0Owner *>(this)->UpdateMatchingNodes(update);
        }
        if (data)
            data->lastUpdate = update;
        return result;
    }
    else
    {
        if (reinterpret_cast<::FUN_00c87a40_obj *>(this)->FUN_00c87a40())
            Reset();
        if (data)
            data->lastUpdate = update;
        return true;
    }
}
struct Node
{
    Obj* object;
    Node* next;
};
struct IntegerTriple
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    void* unk350;
};
struct bhkRefObject
{
};
struct ParentData
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c;
};
struct Parent
{
    int unk00, unk04, unk08, unk0c;
    ParentData data;
    ParentData* GetSub()
    {
        return this ? &data : 0;
    }
};
struct Target
{
    int unk00, unk04;
    Parent* parent;
    int unk0c;
    unsigned int flags;
    Node list;
    void* getOwner()
    {
        IntegerTriple* data = (IntegerTriple*)reinterpret_cast<::FUN_00c87a40_obj *>((((bhkRefObject*)this)))->FUN_00c87a40();
        return data ? data->unk350 : 0;
    }
    unsigned char getFlag()
    {
        return (unsigned char)(flags >> 2);
    }
    __forceinline unsigned int getBits()
    {
        ParentData* s = parent ? parent->GetSub() : 0;
        return s ? s->unk1c : 0;
    }
    void FUN_00c8f080();
};
// Replaces each matching object in the list with the result of FUN_00cc81c0, attached to the owner, then sets flag value 4.
// @fnv 0x00c8f080
void Target::FUN_00c8f080()
{
    MemScope scope;
    if (getFlag() & 1)
        return;
    IntegerTriple* data = (IntegerTriple*)reinterpret_cast<::FUN_00c87a40_obj *>((((bhkRefObject*)this)))->FUN_00c87a40();
    void* owner;
    if (data)
        *(void* volatile*)&owner = data->unk350;
    else
        *(void* volatile*)&owner = 0;
    if (!owner)
        return;
    Node* node = &list;
    while (node)
    {
        Obj* object = node->object;
        if (!object)
            break;
        bool valid = object->isType((const RTTI*)&(*reinterpret_cast<const unsigned char *const *>(&::g_0126818c)));
        node = node->next;
        Obj* body = valid ? object : 0;
        if (body)
        {
            float scale = 1.0f;
            unsigned int bits = getBits();
            unsigned int kind = bits & 0x7f;
            if (kind == 8 || kind == 29)
            {
                unsigned int sub = (bits >> 8) & 31;
                if (sub == 17 || (sub >= 21 && sub <= 22))
                    scale = ::DAT_01017870;
            }
            Obj* replacement = ((::Obj *)(::fnv_00cc81c0::FUN_00cc81c0((::fnv_00cc81c0::ParamStub *)(body), scale)));
            if (replacement)
            {
                reinterpret_cast<::SceneC8E *>((((bhkRigidBody*)this)))->FUN_00c8ef80((::NiObjectC8E *)(::NiObject *)((NiObject*)replacement));
                body->detach();
                replacement->attach(owner);
            }
        }
    }
    flags |= 4;
}

void FUN_00c8d440(bool flag);

typedef __m128 hkQuadReal;

// (-0.5f, -0.5f, -0.5f, -0.5f)
  // sign mask for x,y,z
  // (1, 1, 1, 1)

struct KFSimdReal
{
    hkQuadReal m_vValue;
    KFSimdReal(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
};

struct KFVector4
{
    hkQuadReal m_vComponents;

    void setZero4()
    {
        m_vComponents = (*reinterpret_cast<::hkVector *>(&::DAT_01267e30)).m_vComponents;
    }
    void setAdd4(const KFVector4& a, const KFVector4& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
    void setSub4(const KFVector4& a, const KFVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMul4(const KFVector4& a, const KFVector4& b)
    {
        m_vComponents = _mm_mul_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMul4(const KFSimdReal& s, const KFVector4& b)
    {
        m_vComponents = _mm_mul_ps(b.m_vComponents, _mm_shuffle_ps(s.m_vValue, s.m_vValue, 0));
    }
    void add4(const KFVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    void mul4(const KFSimdReal& s)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), m_vComponents);
    }
    void addMul4(const hkQuadReal& s, const KFVector4& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s, s, 0), a.m_vComponents));
    }
    void addMul4(const KFVector4& a, const KFVector4& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    void setCross(const KFVector4& a, const KFVector4& b)
    {
        hkQuadReal cross0 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)),
                                       _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)));
        hkQuadReal cross1 = _mm_mul_ps(_mm_shuffle_ps(a.m_vComponents, a.m_vComponents, _MM_SHUFFLE(3, 1, 0, 2)),
                                       _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, _MM_SHUFFLE(3, 0, 2, 1)));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    hkQuadReal dot3(const KFVector4& a) const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)),
                          _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2));
    }
    float length3() const
    {
        hkQuadReal x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        float r;
        _mm_store_ss(&r, _mm_sqrt_ss(_mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(2, 2, 2, 2)),
                                                _mm_add_ss(_mm_shuffle_ps(x2, x2, _MM_SHUFFLE(1, 1, 1, 1)), x2))));
        return r;
    }
    float getZ() const
    {
        float r;
        _mm_store_ss(&r, _mm_shuffle_ps(m_vComponents, m_vComponents, _MM_SHUFFLE(2, 2, 2, 2)));
        return r;
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
    void setInterpolate4(const KFVector4& v0, const KFVector4& v1, const KFSimdReal& t)
    {
        hkQuadReal tt = _mm_shuffle_ps(t.m_vValue, t.m_vValue, 0);
        hkQuadReal s = _mm_sub_ps(::DAT_010ec7f0, tt);
        m_vComponents = _mm_add_ps(_mm_mul_ps(s, v0.m_vComponents), _mm_mul_ps(tt, v1.m_vComponents));
    }
};

struct KFQuaternion
{
    KFVector4 m_vec;

    void SetConjugate(const KFQuaternion& q)
    {
        m_vec.m_vComponents = _mm_xor_ps(DAT_010c4c00, q.m_vec.m_vComponents);
    }
                                               // normalize
                                        // getAngle
    __declspec(noalias) void FUN_00c74c90(KFVector4& axis) const;  // getAxis
    void SetInverseProduct(const KFQuaternion& q0, const KFQuaternion& q1)
    {
        KFQuaternion inv;
        inv.SetConjugate(q1);
        ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)this, (void *)&(q0), (const ::fnv_00c66320::__m128 *)&(inv), {});
    }
};

__forceinline void SetRotatedDir(KFVector4& out, const KFQuaternion& quat, const KFVector4& direction)
{
    KFVector4 minusHalf;
    minusHalf.m_vComponents = ::DAT_010c71e0;
    KFVector4 qreal;
    qreal.m_vComponents = _mm_shuffle_ps(quat.m_vec.m_vComponents, quat.m_vec.m_vComponents, _MM_SHUFFLE(3, 3, 3, 3));
    KFVector4 q2minus1;
    q2minus1.setMul4(qreal, qreal);
    q2minus1.add4(minusHalf);

    KFVector4 ret;
    ret.setMul4(direction, q2minus1);

    hkQuadReal imagDotDir = quat.m_vec.dot3(direction);

    ret.addMul4(imagDotDir, quat.m_vec);

    KFVector4 imagCrossDir;
    imagCrossDir.setCross(quat.m_vec, direction);
    ret.addMul4(imagCrossDir, qreal);

    out.setAdd4(ret, ret);
}

inline bool KFGreater(double a, double b)
{
    return a > b;
}

struct KFWorldInfo
{
    int unk00, unk04, unk08, unk0C;
    KFVector4 gravity;
};

struct KFNativeBody : public NativeThing
{
    int unk0ec;
    int unk0f0, unk0f4, unk0f8, unk0fc;
    int unk100, unk104, unk108, unk10c;
    int unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c;
    int unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c;
    int unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c;
    int unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c;
    int unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4, unk1a8, unk1ac;
    KFVector4 linearVelocity;
    KFVector4 angularVelocity;

};

struct KFRigidBody
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual KFQuaternion GetRotation();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual KFVector4& GetCenterOfMassLocal(KFVector4& out);
    virtual KFVector4& GetCenterOfMassInWorld(KFVector4& out);

    unsigned int unk04;
    KFNativeBody* native;

       // max linear velocity
      // max angular velocity
      // lock / unlock

    const KFVector4& GetLinearVelocityVector()
    {
        KFNativeBody* b = native;
        return b ? b->linearVelocity : *(const KFVector4*)&(*reinterpret_cast<::hkVector *>(&::DAT_01267e30));
    }
    const KFVector4& GetAngularVelocity()
    {
        KFNativeBody* b = native;
        return b ? b->angularVelocity : *(const KFVector4*)&(*reinterpret_cast<::hkVector *>(&::DAT_01267e30));
    }
    void SetLinearVelocity(const KFVector4& v)
    {
        KFNativeBody* b = native;
        if (b)
        {
            ::FUN_00a29680();
            reinterpret_cast<::FUN_005616d0_Owner *>((b))->OnTrigger((::TriggerContext *)&(v));
            ::FUN_00a29680();
        }
    }
    void SetAngularVelocity(const KFVector4& v)
    {
        KFNativeBody* b = native;
        if (b)
        {
            ::FUN_00a29680();
            reinterpret_cast<::FUN_00561800_Class *>((b))->FUN_00561800((::FUN_00561730_Obj *)&(v));
            ::FUN_00a29680();
        }
    }

    void FUN_00c8de20(const KFVector4& nextPosition, const KFQuaternion& nextOrientation, float invDeltaTime,
                      float blend);
};

// @fnv 0x00c8de20
void KFRigidBody::FUN_00c8de20(const KFVector4& nextPosition, const KFQuaternion& nextOrientation, float invDeltaTime,
                               float blend)
{
    KFVector4 center;
    KFVector4 newCenterOfMassPosition;
    SetRotatedDir(newCenterOfMassPosition, nextOrientation, GetCenterOfMassLocal(center));
    newCenterOfMassPosition.add4(nextPosition);

    KFVector4 linearVelocity;
    linearVelocity.setSub4(newCenterOfMassPosition, GetCenterOfMassInWorld(center));
    linearVelocity.setMul4(invDeltaTime, linearVelocity);

    float linLen = linearVelocity.length3();
    float maxLin = reinterpret_cast<::Obj577 *>(this)->FUN_00577b50();
    if (linLen > maxLin)
    {
        linearVelocity.mul4(maxLin / linLen);
    }

    KFQuaternion quatDif;
    quatDif.SetInverseProduct(nextOrientation, GetRotation());
    reinterpret_cast<::FUN_005611c0_t *>(&(quatDif))->FUN_005611c0();

    KFVector4 angularVelocity;
    angularVelocity.setZero4();
    float angle = reinterpret_cast<::C74C20Quat *>((void *)&(quatDif))->GetAngle();
    if (0.001f < angle)
    {
        quatDif.FUN_00c74c90(angularVelocity);
        angularVelocity.setMul4(angle * invDeltaTime, angularVelocity);
    }

    float angLen = angularVelocity.length3();
    float maxAng = reinterpret_cast<::S_00c8cd20_object *>(this)->GetFloatValue();
    if (angLen > maxAng)
    {
        angularVelocity.mul4(maxAng / angLen);
    }

    KFWorldInfo* world = ((::KFWorldInfo *)(reinterpret_cast<::FUN_00c87a40_obj *>(this)->FUN_00c87a40()));
    if (world)
    {
        float g = world->gravity.getZ();
        linearVelocity(2) -= g * blend / invDeltaTime;
    }

    KFVector4 newLin;
    newLin.setInterpolate4(GetLinearVelocityVector(), linearVelocity, blend);
    KFVector4 newAng;
    newAng.setInterpolate4(GetAngularVelocity(), angularVelocity, blend);
    SetLinearVelocity(newLin);
    SetAngularVelocity(newAng);
}

namespace fnv_00c8e160 {
extern "C" double fabs(double);
struct V4_160
{
    __m128 v;
    void Set(float x, float y, float z, float w)
    {
        v[0] = x;
        v[1] = y;
        v[2] = z;
        v[3] = w;
    }
    V4_160& operator=(const V4_160& rhs)
    {
        v = rhs.v;
        return *this;
    }
};
extern float DAT_012681c8;
extern const float DAT_010c6090 = 1.0000001111620804e-06f;
extern const float DAT_010959f4 = 9.9999999747524271e-07f;
namespace threshold160 {
extern const float DAT_01017d00 = 0.0010000000474974513f;
}
struct SmartObj160;
struct RotationArg160
{
    float* volatile rotation;
    RotationArg160(float* q) : rotation(q)
    {}
};
struct Inner160
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int m_350;
};
struct Linked160
{
    unsigned int unk00;
    unsigned int unk04;
    Inner160* unk08;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    V4_160 linear;
    V4_160 angular;
};
struct This160
{
    virtual void slot_000();
    virtual void slot_004();
    virtual void slot_008();
    virtual void slot_00c();
    virtual void slot_010();
    virtual void slot_014();
    virtual void slot_018();
    virtual void slot_01c();
    virtual void slot_020();
    virtual void slot_024();
    virtual void slot_028();
    virtual void slot_02c();
    virtual void slot_030();
    virtual void slot_034();
    virtual void slot_038();
    virtual void slot_03c();
    virtual void slot_040();
    virtual void slot_044();
    virtual void slot_048();
    virtual void slot_04c();
    virtual void slot_050();
    virtual void slot_054();
    virtual void slot_058();
    virtual void slot_05c();
    virtual void slot_060();
    virtual void slot_064();
    virtual void slot_068();
    virtual void slot_06c();
    virtual void slot_070();
    virtual void slot_074();
    virtual void slot_078();
    virtual void slot_07c();
    virtual void slot_080();
    virtual void slot_084();
    virtual void slot_088();
    virtual void slot_08c();
    virtual void slot_090();
    virtual void slot_094();
    virtual void slot_098();
    virtual void slot_09c();
    virtual void slot_0a0();
    virtual void slot_0a4();
    virtual void slot_0a8();
    virtual void slot_0ac();
    virtual void slot_0b0();
    virtual void slot_0b4();
    virtual void slot_0b8();
    virtual void slot_0bc();
    virtual void slot_0c0();
    virtual void slot_0c4();
    virtual void slot_0c8();
    virtual void slot_0cc();
    virtual void slot_0d0();
    virtual void GetA160(V4_160* out);
    virtual void GetB160(V4_160* out);
    virtual void slot_0dc();
    virtual void slot_0e0();
    virtual void slot_0e4();
    virtual void V160e8(V4_160* a, V4_160* b);
    virtual V4_160* V160ec(V4_160* out);
    virtual V4_160* V160f0(V4_160* in);
    unsigned int unk04;
    Linked160* m_08;
    void FUN_00c8e160(float* p1, RotationArg160 input, void* p3);
};
struct SmartObj160
{
    int unk00;
    int ref04;
};
struct Vec50Obj
{
    __m128 v;
    void FUN_00c74c90(V4_160* out);
};
extern "C" void _ReadWriteBarrier();
static __forceinline int MaskBits160(__m128 a)
{
    return _mm_movemask_ps(a) & 15;
}
struct DotSpeed160
{
    float vel;
    float dot;
};
struct Ws160
{
    V4_160 v60;
    V4_160 v70;
    V4_160 tmpB;
    V4_160 outB;
    V4_160 outC;
    V4_160 outA;
    V4_160 tmpC0;
};
// @fnv 0x00c8e160
void This160::FUN_00c8e160(float* p1, RotationArg160 input, void* p3)
{
    V4_160 separate_q;
    V4_160 separate_p;
    Vec50Obj separate_v50;
    Ws160 W;
    float inv, s1, len;
    DotSpeed160 pair;
    SmartObj160* a3;
    a3 = static_cast<SmartObj160*>(p3);
    Linked160* linked = this ? m_08 : 0;
    Inner160* inner = linked->unk08;
    if (!inner)
        return;
    if (!inner->m_350)
        return;
    const float x = p1[0];
    separate_p.Set(x * DAT_012681c8, p1[1] * DAT_012681c8, p1[2] * DAT_012681c8, 0.0f);
    float* p2 = input.rotation;
    separate_q.v[0] = p2[1];
    separate_q.v[1] = p2[2];
    separate_q.v[2] = p2[3];
    separate_q.v[3] = p2[0];
    GetA160(&W.outA);
    GetB160(&W.outB);
    __m128 d = _mm_sub_ps(_mm_load_ps((float*)&separate_p), _mm_load_ps((float*)&W.outA));
    d = _mm_mul_ps(d, d);
    __m128 sh = _mm_shuffle_ps(d, d, 0x55);
    __m128 sum1 = _mm_add_ss(sh, d);
    __m128 sh2 = _mm_shuffle_ps(d, d, 0xaa);
    __m128 sum2 = _mm_add_ss(sh2, sum1);
    _mm_store_ss(&s1, sum2);
    if (!(s1 > DAT_010c6090))
    {
        __m128 b = _mm_load_ps((float*)&W.outB);
        __m128 prod = _mm_mul_ps(_mm_load_ps((float*)&separate_q), b);
        __m128 sw = _mm_shuffle_ps(prod, prod, 0x4e);
        __m128 s1 = _mm_add_ps(sw, prod);
        __m128 sw2 = _mm_shuffle_ps(s1, s1, 0xb1);
        __m128 s2 = _mm_add_ps(sw2, s1);
        _mm_store_ss(&pair.dot, s2);
        *(volatile float*)&inv = pair.dot - 1.0f;
        inv = (float)fabs(*(volatile float*)&inv);
        if (!(*(volatile float*)&inv > ::DAT_010959f4))
        {
            Linked160* lk = m_08;
            V4_160* v1p = lk ? &lk->linear : (V4_160*)&(*reinterpret_cast<::hkVector *>(&::DAT_01267e30));
            __m128 eps = _mm_set1_ps(::AngularDashpotApplyD4DCB0::DAT_01017d00);
            if ((MaskBits160(_mm_cmple_ps(
                     _mm_and_ps(_mm_sub_ps(_mm_load_ps((float*)v1p), *(const __m128*)&(*reinterpret_cast<::hkVector *>(&::DAT_01267e30))), ::DAT_01017d10),
                     eps)) != 15))
            {
                _mm_store_ps((float*)&W.v60, eps);
                if (lk)
                {
                    ::FUN_00a29680();
                    reinterpret_cast<::FUN_005616d0_Owner *>((lk))->OnTrigger((::TriggerContext *)(float *)((float*)&(*reinterpret_cast<::hkVector *>(&::DAT_01267e30))));
                    ::FUN_00a29680();
                    eps = W.v60.v;
                }
            }
            else
            {
                _mm_store_ps((float*)&W.v60, eps);
            }
            __m128 eps2 = eps;
            lk = m_08;
            V4_160* v2p = lk ? &lk->angular : (V4_160*)&(*reinterpret_cast<::hkVector *>(&::DAT_01267e30));
            int mask2 =
                _mm_movemask_ps(_mm_cmple_ps(
                    _mm_and_ps(_mm_sub_ps(_mm_load_ps((float*)v2p), *(const __m128*)&(*reinterpret_cast<::hkVector *>(&::DAT_01267e30))), ::DAT_01017d10),
                    eps2)) &
                0xf;
            if (mask2 != 0xf)
            {
                if (lk)
                {
                    ::FUN_00a29680();
                    reinterpret_cast<::FUN_00561800_Class *>((lk))->FUN_00561800((::FUN_00561730_Obj *)(float *)((float*)&(*reinterpret_cast<::hkVector *>(&::DAT_01267e30))));
                    ::FUN_00a29680();
                }
            }
            return;
        }
    }
    inv = ::DAT_011afe64;
    if (inv == 0.0f)
        return;
    inv = 1.0f / inv;
    V4_160* ec = V160ec(&W.outC);
    __m128 b128;
    (void)b128;
    __m128 q128 = _mm_load_ps((float*)&separate_q);
    b128 = _mm_load_ps((float*)ec);
    __m128 w4 = _mm_shuffle_ps(q128, q128, 0xff);
    __m128 prodB = q128;
    prodB = _mm_mul_ps(prodB, b128);
    __m128 tb = _mm_shuffle_ps(prodB, prodB, 0x55);
    tb = _mm_add_ss(tb, prodB);
    __m128 dot4 = _mm_shuffle_ps(prodB, prodB, 0xaa);
    dot4 = _mm_add_ss(dot4, tb);
    tb = _mm_shuffle_ps(b128, b128, 0xd2);
    __m128 cross = _mm_shuffle_ps(q128, q128, 0xc9);
    const __m128& phaseValue = _mm_mul_ps(cross, tb);
    __m128 crossAlias = phaseValue;
    tb = _mm_shuffle_ps(b128, b128, 0xc9);
    __m128 t2 = _mm_shuffle_ps(q128, q128, 0xd2);
    t2 = _mm_mul_ps(t2, tb);
    crossAlias = _mm_sub_ps(crossAlias, t2);
    __m128 u = _mm_mul_ps(w4, w4);
    crossAlias = _mm_mul_ps(crossAlias, w4);
    u = _mm_add_ps(u, ::DAT_010c71e0);
    u = _mm_mul_ps(u, b128);
    __m128 v = _mm_mul_ps(_mm_shuffle_ps(dot4, dot4, 0), separate_q.v);
    u = _mm_add_ps(u, v);
    crossAlias = _mm_add_ps(crossAlias, u);
    _mm_store_ps((float*)&separate_v50, crossAlias);
    V4_160* fr = V160f0(&W.outC);
    __m128 rv = _mm_load_ps((float*)fr);
    _ReadWriteBarrier();
    __m128 t = separate_v50.v;
    t = _mm_add_ps(t, t);
    t = _mm_add_ps(t, separate_p.v);
    t = _mm_sub_ps(t, rv);
    __m128 invScalar = _mm_load_ss(&inv);
    __m128 invVector = _mm_shuffle_ps(invScalar, invScalar, 0);
    t = _mm_mul_ps(t, invVector);
    _mm_store_ps((float*)&W.v60, t);
    __m128 sq = _mm_mul_ps(t, t);
    __m128 sq1 = _mm_shuffle_ps(sq, sq, 0x55);
    __m128 sqs = _mm_add_ss(sq1, sq);
    __m128 sq2 = _mm_shuffle_ps(sq, sq, 0xaa);
    __m128 sqs2 = _mm_add_ss(sq2, sqs);
    _mm_store_ss(&pair.vel, sqs2);
    len = reinterpret_cast<::Obj577 *>(this)->FUN_00577b50();
    if (pair.vel > len * len)
    {
        ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&W.tmpC0)), (*(const ::fnv_004a3e00::NiPoint3 *)(p1)));
        W.tmpB.v[0] = p2[1];
        W.tmpB.v[1] = p2[2];
        W.tmpB.v[2] = p2[3];
        W.tmpB.v[3] = p2[0];
        V160e8(&W.tmpC0, &W.tmpB);
        return;
    }
    __m128 t60 = _mm_load_ps((float*)&W.v60);
    __m128 sqC = _mm_mul_ps(t60, t60);
    __m128 sc1 = _mm_shuffle_ps(sqC, sqC, 0x55);
    __m128 scs1 = _mm_add_ss(sc1, sqC);
    __m128 sc2 = _mm_shuffle_ps(sqC, sqC, 0xaa);
    __m128 scs2 = _mm_add_ss(sc2, scs1);
    _mm_store_ss(&len, _mm_sqrt_ss(scs2));
    if (::CombatWeapons::DAT_0106b798 < len)
    {
        if (a3)
            reinterpret_cast<::FUN_0040fbf0_shell *>((a3))->FUN_0040fbf0((char *)(0));
        reinterpret_cast<::FUN_005610f0_cls *>(this)->FUN_005610f0(reinterpret_cast<std::intptr_t>(p1));
        if (a3)
        {
            if (--a3->ref04 == 0)
                a3->unk00 = 0;
        }
        reinterpret_cast<::S *>(this)->FUN_00561690((std::intptr_t)((float*)&(*reinterpret_cast<::hkVector *>(&::DAT_01267e30))));
    }
    else
    {
        reinterpret_cast<::S *>(this)->FUN_00561690((std::intptr_t)((float*)&W.v60));
    }
    reinterpret_cast<::Quat74 *>(&(separate_v50))->FUN_00c74ac0((*(const ::Quat74 *)((float*)&separate_q)), (*(const ::Quat74 *)(&W.outB)));
    reinterpret_cast<::FUN_005611c0_t *>(&(separate_v50))->FUN_005611c0();
    s1 = reinterpret_cast<::C74C20Quat *>(&(separate_v50))->GetAngle();
    if (s1 < ::AngularDashpotApplyD4DCB0::DAT_01017d00)
    {
        _mm_store_ps((float*)&W.v70, _mm_setzero_ps());
    }
    else
    {
        separate_v50.FUN_00c74c90(&W.v70);
        float sc = *(volatile float*)&s1 * inv;
        __m128 scalar = _mm_load_ss(&sc);
        __m128 factor = _mm_shuffle_ps(scalar, scalar, 0);
        __m128 axis = W.v70.v;
        W.v70.v = _mm_mul_ps(factor, axis);
    }
    reinterpret_cast<::fnv_005617c0::FUN_005617c0_ *>(this)->FUN_005617c0((std::intptr_t)((float*)&W.v70));
}
}

#include "generated/data/unmapped/bhkrigidbody.inc"
#include "generated/data/unmapped/bhkrigidbody_rtm_variant.inc"
