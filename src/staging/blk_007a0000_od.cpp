
// src/staging/blk_007a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include <new>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSStringTChar.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004ede90_Class.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_007a3ac0_ListBox.h"
#include "fnv/decl/FUN_007a7700_Menu.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/Flt.h"
#include "fnv/decl/GO.h"
#include "fnv/decl/HighlightList.h"
#include "fnv/decl/ItemCounter.h"
#include "fnv/decl/ListScrollHost.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/ScriptPool.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/Target007a4780.h"
#include "fnv/decl/Tile.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/VLList.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_007a54d0__ClearListBox.h"
#include "fnv/decl/fnv_007a6a50__FUN_007a6a50_shell.h"
#include "fnv/decl/fnv_007a71b0__FUN_007a71b0_cls.h"
#include "fnv/decl/fnv_007a73e0__HighlightList.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/xEntryMenu.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00721000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01075000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "../../include/layout_support.h"

struct FUN_007a1400_class
{
    void FUN_007a1400(int flags);
};

// @fnv 0x007a1400
void FUN_007a1400_class::FUN_007a1400(int flags)
{
    if (*(int*)((char*)this + 0x30) & flags)
        *(int*)((char*)this + 0x30) ^= flags;
}

struct FUN_007a1430_Class
{
    unsigned char m_data[0x92];
    unsigned char m_flag;
    void SetFlag(unsigned char value);
};

// @fnv 0x007a1430
void FUN_007a1430_Class::SetFlag(unsigned char value)
{
    m_flag = value;
}

struct Unk65
{
    void FUN_0065de30(int);
};

struct Unk65a
{
    Unk65* FUN_007ab230(Unk65* other);
};

// @fnv 0x007ab230
Unk65* Unk65a::FUN_007ab230(Unk65* other)
{
    other->FUN_0065de30((int)this);
    return other;
}

extern "C" void* __cdecl DAT_01075794;

struct NavMeshInfo;

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};

struct FUN_007ab590 : BSSimpleArray<NavMeshInfo*, 1024>
{
    FUN_007ab590* DeserializeFromFile();
};

// Sets the object's vtable pointer to DAT_01075794, calls FUN_006b3eb0(0, 0), and returns this.
// @fnv 0x007ab590
FUN_007ab590* FUN_007ab590::DeserializeFromFile()
{
    *reinterpret_cast<void**>(this) = &DAT_01075794;
    reinterpret_cast<AX*>(this)->FUN_006b3eb0(0, 0);
    return this;
}

namespace fnv_007ab610 {
struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
    AX* FUN_007ab610();
};
// @fnv 0x007ab610
AX* AX::FUN_007ab610()
{
    *(int*)this = (int)&::DAT_010757a8;
    FUN_006b3eb0(0, 0);
    return this;
}
}  // namespace fnv_007ab610


struct GlobalObject_00869f00
{
    void Clear(bool);
    void FUN_007ab670();
};

void GlobalObject_00869f00::Clear(bool)
{}

// @fnv 0x007ab670
void GlobalObject_00869f00::FUN_007ab670()
{
    *(int*)this = (int)&DAT_010757a8;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct FUN_007adcc0_class
{
    void SetAllow(bool abAllow);
};

// @fnv 0x007adcc0
void FUN_007adcc0_class::SetAllow(bool abAllow)
{
    ((unsigned char*)this)[0x75d] = abAllow;
}

struct FUN_007b8f10_Class
{
    unsigned int GetField630();
};

// @fnv 0x007b8f10
unsigned int FUN_007b8f10_Class::GetField630()
{
    return *(unsigned int*)((char*)this + 0x630);
}

struct GlobalObject_007ab590
{
    ~GlobalObject_007ab590();
    void* FUN_007ab5c0(unsigned int flags);
};

void __cdecl FUN_00730490(char*, int);

struct FUN_007b52a0_class
{
    char* m_ptr;
    unsigned short m_uiItemCount;
    void FUN_007b52a0();
};

// @fnv 0x007b52a0
void FUN_007b52a0_class::FUN_007b52a0()
{
    if (m_ptr)
        FUN_00730490(m_ptr, m_uiItemCount + 1);
}

struct EffectSetting
{
};
struct MapMenu_007a1880
{
    unsigned char m_data[0x10c];
    EffectSetting* pEffect;
    bool bEffectChanged;
};
// @fnv 0x007a1880
void __cdecl FUN_007a1880(EffectSetting* effect)
{
    if ((*reinterpret_cast<::MapMenu_007a1880 * *>(&::DAT_011da368)))
    {
        EffectSetting* previous = (*reinterpret_cast<::MapMenu_007a1880 * *>(&::DAT_011da368))->pEffect;
        (*reinterpret_cast<::MapMenu_007a1880 * *>(&::DAT_011da368))->pEffect = effect;
        while ((*reinterpret_cast<::MapMenu_007a1880 * *>(&::DAT_011da368))->pEffect && ((::EffectSetting *)(reinterpret_cast<::FUN_004fd380_shell *>(((*reinterpret_cast<::MapMenu_007a1880 * *>(&::DAT_011da368))->pEffect))->FUN_004fd380())))
            (*reinterpret_cast<::MapMenu_007a1880 * *>(&::DAT_011da368))->pEffect = ((::EffectSetting *)(reinterpret_cast<::FUN_004fd380_shell *>(((*reinterpret_cast<::MapMenu_007a1880 * *>(&::DAT_011da368))->pEffect))->FUN_004fd380()));
        (*reinterpret_cast<::MapMenu_007a1880 * *>(&::DAT_011da368))->bEffectChanged = previous != (*reinterpret_cast<::MapMenu_007a1880 * *>(&::DAT_011da368))->pEffect;
    }
}

struct NavMeshInfo;
struct NavMeshInfo4
{
    NavMeshInfo* m_pObjectInfo;
    unsigned int m_uiSize;
    unsigned int m_uiCount;
    unsigned int m_uiValue1;
};
struct FUN_007a1450_Class
{
    unsigned char m_data[0x68];
    NavMeshInfo4 m_pMesh;
    void SetNavMeshInfo(NavMeshInfo4& source);
};
// @fnv 0x007a1450
void FUN_007a1450_Class::SetNavMeshInfo(NavMeshInfo4& source)
{
    m_pMesh = source;
}

struct FUN_007a8030_Class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void FUN_007a8030_v5(int);
};

struct FUN_007a62b0_Class : FUN_007a8030_Class
{
    void FUN_007a62b0();
};

// Calls FUN_007a8030 with 0, subtracts 1 from the result, and passes it to FUN_007a8030_v5.
// @fnv 0x007a62b0
void FUN_007a62b0_Class::FUN_007a62b0()
{
    FUN_007a8030_v5(reinterpret_cast<::ItemCounter *>(this)->FUN_007a8030() - 1);
}

struct BSS
{
    ~BSS();
    BSS* FUN_007a86b0(unsigned int flags);
};
// Destructs the object and, if bit 0 of flags is set, frees its memory, then returns the pointer.
// @fnv 0x007a86b0
BSS* BSS::FUN_007a86b0(unsigned int flags)
{
    reinterpret_cast<::BSStringTChar *>((this))->BSStringTChar::~BSStringTChar();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BSSimpleArrayActor
{
    void Clear(bool);
};
void* __cdecl DAT_01075794;

struct FUN_007ab5f0_class : BSSimpleArrayActor
{
    void* m_data;
    void FUN_007ab5f0();
};
// Runs the destructor and, if flags has bit 0 set, frees the object with operator delete, then returns this.
// @fnv 0x007ab5c0
void* GlobalObject_007ab590::FUN_007ab5c0(unsigned int flags)
{
    reinterpret_cast<::FUN_007ab5f0_class *>(this)->FUN_007ab5f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x007ab5f0
void FUN_007ab5f0_class::FUN_007ab5f0()
{
    m_data = &DAT_01075794;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct GlobalObject_007ab610
{
    ~GlobalObject_007ab610();
    void* FUN_007ab640(unsigned int flags);
};
// Destroys the object, optionally frees its memory when flags has bit 0 set, and returns the object pointer.
// @fnv 0x007ab640
void* GlobalObject_007ab610::FUN_007ab640(unsigned int flags)
{
    reinterpret_cast<::GlobalObject_00869f00 *>((this))->FUN_007ab670();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


// @fnv 0x007a1480
int __cdecl FUN_007a1480()
{
    return DAT_011dea14;
}

struct NavMeshPayload
{
};
struct NavMeshListNode
{
    void* m_payload;
    unsigned int m_uiEdgeIndex;
    unsigned int m_uiContentCount;
    NavMeshListNode* m_next;
    NavMeshListNode(NavMeshPayload* payload);
    void FUN_007a19a0(NavMeshPayload* payload);
};
// @fnv 0x007a19a0
void NavMeshListNode::FUN_007a19a0(NavMeshPayload* payload)
{
    if (reinterpret_cast<::Flt *>((payload))->Equals(0))
        return;
    NavMeshListNode* current = this;
    while (current->m_next)
        current = current->m_next;
    if (reinterpret_cast<::GO *>((current))->IsNotEqual(0))
        current->m_next = new NavMeshListNode(payload);
    else
        reinterpret_cast<::SoundPlaybackHandle *>((current))->operator=((*(const ::SoundPlaybackHandle *)(payload)));
}

struct FUN_0046ffb0
{
    ~FUN_0046ffb0();
};

struct FUN_007a28c0
{
    virtual ~FUN_007a28c0();
    FUN_0046ffb0 member;
};


// Calls ClearEntries, then passes this to FUN_007211c0 as part of destruction.
// @fnv 0x007a28c0
FUN_007a28c0::~FUN_007a28c0()
{
    reinterpret_cast<::xEntryMenu *>(this)->ClearEntries();
    ::fnv_007211c0::FUN_007211c0((int *)(::FUN_007a28c0 *)(this));
}

class SubObj
{
  public:
    int unk00;
    ~SubObj();
};

class FUN_007a37b0
{
  public:
    virtual void unk00();
    SubObj m_sub;
    ~FUN_007a37b0();
};


// @fnv 0x007a37b0
FUN_007a37b0::~FUN_007a37b0()
{
    reinterpret_cast<::FUN_007a3ac0_ListBox *>(this)->FUN_007a3ac0();
    ::fnv_007211c0::FUN_007211c0((int *)(::FUN_007a37b0 *)(this));
}

class FUN_007a4470_sub
{
  public:
    ~FUN_007a4470_sub();
    int m_00;
};

class FUN_007a4470_cls
{
  public:
    virtual ~FUN_007a4470_cls();
    FUN_007a4470_sub m_04;
};


// Calls Step, then passes this to FUN_007211c0 during destruction.
// @fnv 0x007a4470
FUN_007a4470_cls::~FUN_007a4470_cls()
{
    reinterpret_cast<::Target007a4780 *>(this)->FUN_007a4780();
    ::fnv_007211c0::FUN_007211c0((int *)(::FUN_007a4470_cls *)(this));
}

struct FUN_007a51c0_m4
{
    int m_00;
    ~FUN_007a51c0_m4();
};


struct FUN_007a51c0_cls
{
    virtual ~FUN_007a51c0_cls();
    FUN_007a51c0_m4 m_04;

};

// @fnv 0x007a51c0
FUN_007a51c0_cls::~FUN_007a51c0_cls()
{
    reinterpret_cast<::fnv_007a54d0::ClearListBox *>(this)->FUN_007a54d0();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}

struct FUN_007a6220_class
{
    virtual void FUN_007a6220_v1();
    virtual void FUN_007a6220_v2();
    virtual void FUN_007a6220_v3();
    virtual void FUN_007a6220_v4();
    virtual void FUN_007a6220_v5();
    virtual void FUN_007a6220_v6(int value);


    void FUN_007a6220();
};

// Calls GetUnfilteredCount with 0, subtracts 1 from the result, and passes it to FUN_007a6220_v6.
// @fnv 0x007a6220
void FUN_007a6220_class::FUN_007a6220()
{
    FUN_007a6220_v6(((int)(reinterpret_cast<::fnv_007a6a50::FUN_007a6a50_shell *>(this)->GetUnfilteredCount())) - 1);
}

// FUN_007a6250 : thiscall member, no stack args.
// this->FUN_007a71b0(0) returns a count; the count-1 is passed to the
// virtual function living in vtable slot 5 (offset 0x14).
struct SpawnedObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05(int value);


    void FUN_007a6250();
};

// Calls FUN_007a71b0 with 0, subtracts 1 from the result, and passes it to v05.
// @fnv 0x007a6250
void SpawnedObject::FUN_007a6250()
{
    this->v05(reinterpret_cast<::fnv_007a71b0::FUN_007a71b0_cls *>((this))->FUN_007a71b0() - 1);
}

struct SceneThing
{
};

struct SceneInner
{
    SceneThing* m_00;
    unsigned int unk04;
    unsigned char m_flag08;
};

struct SceneHolder
{
    SceneInner* m_00;
};

struct SceneNodeRef
{
};

struct FUN_007a80e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    unsigned short unk1e;
    float m_20;

    void InitSceneNodes();
};

// @fnv 0x007a80e0
void FUN_007a80e0_cls::InitSceneNodes()
{
    this->m_1c = 0;
    this->m_20 = 0.0f;
    for (SceneNodeRef* pNodeRef = this ? (SceneNodeRef*)&this->unk04 : 0;
         pNodeRef != 0 && ((::SceneHolder *)(new ((void *)(pNodeRef)) ::Vec3()))->m_00 != 0; pNodeRef = ((::SceneNodeRef *)(reinterpret_cast<::Callees *>((pNodeRef))->FUN_00726070())))
    {
        if (((::SceneHolder *)(new ((void *)(pNodeRef)) ::Vec3()))->m_00->m_flag08 == 0)
        {
            reinterpret_cast<::Tile *>((((::SceneHolder *)(new ((void *)(pNodeRef)) ::Vec3()))->m_00->m_00))->Set(0xfac, this->m_1c++);
            reinterpret_cast<::VLList *>((this))->AccumulateTileHeight((::VLTile *)(((::SceneHolder *)(new ((void *)(pNodeRef)) ::Vec3()))->m_00->m_00));
        }
    }
    reinterpret_cast<::ListScrollHost *>((this))->FUN_007a8580();
    reinterpret_cast<::HighlightList *>((this))->UpdateHighlight_007a8260();
}

// Sub-object with an out-of-line destructor (shared by every member below).
class ManagedSubObject
{
  public:
    int unk00;
    ~ManagedSubObject();
};


class FUN_007a8960_cls : public ManagedSubObject
{
  public:
    int unk04;
    void* m_08;
    ManagedSubObject m_0c;
    int unk10;
    ManagedSubObject m_14;
    int unk18;
    int unk1c;
    ManagedSubObject m_20;
    int unk24;
    int unk28;
    int unk2c;
    ManagedSubObject m_30;
    ~FUN_007a8960_cls();
};

// @fnv 0x007a8960
FUN_007a8960_cls::~FUN_007a8960_cls()
{
    void* p = m_08;
    ::FUN_00401030(p);
    m_08 = 0;
}

// FUN_007abda0: returns constant 0x3f8
// @fnv 0x007abda0
int __cdecl FUN_007abda0()
{
    return 0x3f8;
}

struct RefObj7ac9f0
{
    void IncRefCount();
    void DecRefCount();
};

struct Vec3_7ac9f0
{
    float x;
    float y;
    float z;
    Vec3_7ac9f0()
    {}
};

struct Base7ac9f0
{
    Base7ac9f0();
    virtual ~Base7ac9f0();
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
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
};

struct FUN_007ac9f0 : Base7ac9f0
{
    NiPointer<RefObj7ac9f0> pFirst[4];
    NiPointer<RefObj7ac9f0> pSecond[4];
    NiPointer<RefObj7ac9f0> spObj0;
    NiPointer<RefObj7ac9f0> spObj1;
    NiPointer<RefObj7ac9f0> spObj2;
    NiPointer<RefObj7ac9f0> spObj3;
    NiPointer<RefObj7ac9f0> spObj4;
    NiPointer<RefObj7ac9f0> spObj5;
    Vec3_7ac9f0 kPos0;
    Vec3_7ac9f0 kPos1;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    Vec3_7ac9f0 kPos2;
    FUN_007ac9f0();
    virtual ~FUN_007ac9f0();
};

// @fnv 0x007ac9f0
FUN_007ac9f0::FUN_007ac9f0()
{}

struct ActiveEffectEntry
{
};
struct ActiveEffectCollection
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    float rate;
    void FUN_007b4530(int amount);
};
// @fnv 0x007b4530
void ActiveEffectCollection::FUN_007b4530(int amount)
{
    if (rate <= ::_DAT_01012060)
        return;
    int it = ::FUN_00559450((int *)this);
    while (it)
    {
        ActiveEffectEntry* pEffect = **((::ActiveEffectEntry ***)(reinterpret_cast<::ListStandIn *>(this)->FUN_0057cbe0((int **)(int *)(&it))));
        float fAmount = reinterpret_cast<::TileListBoxCalls *>((pEffect))->GetFloat(4002);
        fAmount = (float)amount * rate + fAmount;
        reinterpret_cast<::FUN_00a012d0_t *>((pEffect))->FUN_00a012d0(4002, fAmount, true);
    }
}

struct FUN_007b52d0_cls
{
    int* DereferenceIfNotNull(int** pParam);
};

// Returns the pointer stored at pParam when pParam is non-null, otherwise returns null.
// @fnv 0x007b52d0
int* FUN_007b52d0_cls::DereferenceIfNotNull(int** pParam)
{
    return pParam != 0 ? *pParam : (int*)0;
}

struct FUN_0049fa80_Result
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_007b5330_Class
{
    void FUN_007b5330(intptr_t arg1, int* arg2);
};

// Gets a result object, stores the int pointed to by arg2 into its unk08 field, then passes it with arg1 to InsertBefore.
// @fnv 0x007b5330
void FUN_007b5330_Class::FUN_007b5330(intptr_t arg1, int* arg2)
{
    FUN_0049fa80_Result* result = ((::FUN_0049fa80_Result *)(reinterpret_cast<::ScriptPool *>((this))->FUN_0049fa80()));
    result->unk08 = *arg2;
    reinterpret_cast<::FUN_004ede90_Class *>((this))->InsertBefore((void *)(arg1), (void **)(result));
}

namespace q72 {
struct Target
{
};
struct Item
{
    Target* m_pFlagTarget;
    int u4;
    bool m_bSkip;
};
struct SL
{
    Item* item;
    SL* next;
};
struct Head
{
    int m_iWordAt00;
};
struct Menu : Head, SL
{
    char pad0c[0x10];
    unsigned short m_usElementCount;
    float m_fValue;
    void FUN_007a7260();
};
// @fnv 0x007a7260
void Menu::FUN_007a7260()
{
    m_usElementCount = 0;
    m_fValue = 0.0f;
    for (SL* it = this; it && ((::q72::Item *)(new ((void *)(it)) ::Vec3())); it = ((::q72::SL *)(reinterpret_cast<::Callees *>((it))->FUN_00726070())))
    {
        if (!((::q72::Item *)(new ((void *)(it)) ::Vec3()))->m_bSkip)
        {
            reinterpret_cast<::Tile *>((((::q72::Item *)(new ((void *)(it)) ::Vec3()))->m_pFlagTarget))->Set(0xfac, m_usElementCount++);
            reinterpret_cast<::VLList *>(this)->AccumulateTileHeight((::VLTile *)(((::q72::Item *)(new ((void *)(it)) ::Vec3()))->m_pFlagTarget));
        }
    }
    reinterpret_cast<::FUN_007a7700_Menu *>(this)->FUN_007a7700();
    reinterpret_cast<::fnv_007a73e0::HighlightList *>(this)->FUN_007a73e0();
}
}
