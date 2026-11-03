
// src/fallout/magic/summoncreatureeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/summoncreatureeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/active_effect_fields.h"
#include "fnv/simple_list_node_view.h"
#include <new>
#include <cstdlib>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AssociatedItemCopyEntry.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004046b0_cls.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00689920_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_008feab0_cls.h"
#include "fnv/decl/HandlerView.h"
#include "fnv/decl/KillActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicItem.h"
#include "fnv/decl/MagicTarget.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/ThreeByThreeMatrix.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/UnloadMagic.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00490e40__FUN_00490e40_shell.h"
#include "fnv/decl/fnv_00564930__FUN_00564930_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00804210__ActiveEffectUpdateShell.h"
#include "fnv/decl/fnv_00806de0__AssociatedItemEffect.h"
#include "fnv/decl/fnv_00806e70__AssociatedItemEffect.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_005c5000.h"
#include "fnv/symbols_0080b000.h"
#include "fnv/symbols_00828000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0101b000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/decl/CalleeObj.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00458420_cls.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_005609f0_shell.h"
#include "fnv/decl/FUN_0056e120_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_00c9f420_Class.h"
#include "fnv/decl/Hld621210.h"
#include "fnv/decl/Obj.h"
#include "fnv/decl/ScriptX.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_0050ebf0__FUN_0050ebf0_shell.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004ae000.h"
struct SummonCreatureEffect
{
    virtual ~SummonCreatureEffect();
    void FUN_00828590();
    void* FUN_00828560(unsigned int flags);
};


struct FUN_00828da0_shell
{
    int GetZero(int a, int b, int c);
};

// Returns 0; the local variables are initialized to 0 and never used.
// @fnv 0x00828da0
int FUN_00828da0_shell::GetZero(int a, int b, int c)
{
    int v1 = 0;
    int v2 = 0;
    return v1;
}

struct Actor;
struct FUN_00806da0_shell
{
    unsigned short FUN_00806da0(Actor*);
};
struct FUN_00829720_shell : public SummonCreatureEffect
{
    unsigned short FUN_00829720(Actor* actor);
};
// @fnv 0x00829720
unsigned short FUN_00829720_shell::FUN_00829720(Actor* actor)
{
    unsigned short isize = 0;
    isize += ((FUN_00806da0_shell*)this)->FUN_00806da0(actor);
    isize += 4;
    isize += 1;
    if (!*(Actor**)((char*)this + 0x4c))
    {
        isize += 4;
        isize += 0xc;
        isize += 0xc;
    }
    return isize;
}

struct Actor;
struct AssociatedItemEffect
{
    void FUN_00806e30(Actor* actor);
};
struct TESSaveLoadGame
{
};
struct FUN_00829850_shell : AssociatedItemEffect
{
    Actor* m_pActor;
    bool m_bAssociatedItemLoaded;
    void LoadAssociatedItemEffect(Actor* actor);
};
// Calls the base loader, reads a 4-byte id and a byte from the save stream, stores them, and reads further fields when the id is zero and not forced.
// @fnv 0x00829850
void FUN_00829850_shell::LoadAssociatedItemEffect(Actor* actor)
{
    unsigned int id;
    unsigned char bforcedToZero;
    FUN_00806e30(actor);
    bforcedToZero = ((unsigned char)(reinterpret_cast<::FUN_00857aa0 *>((g_TESSaveLoadGame))->ValidateFormIDArray(&id, 4)));
    *(Actor**)((char*)this + 0x4c) = (Actor*)id;
    reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((char*)this + 0x50, 1);
    if (!id && !bforcedToZero)
    {
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((char*)this + 0x54, 4);
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((char*)this + 0x58, 0xc);
        reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((char*)this + 0x64, 0xc);
        *(char*)((char*)this + 0x70) = 0;
    }
    else
    {
        *(char*)((char*)this + 0x70) = 1;
    }
}

struct FUN_0040b800_shell
{
};
struct FUN_0080d930
{
    virtual void placeholder();
    ~FUN_0080d930();
};
struct FUN_00828590 : FUN_0080d930
{
    virtual ~FUN_00828590();
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
    unsigned char unk70;
    unsigned char unk71;
};
// Calls FUN_00828590, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00828560
void* SummonCreatureEffect::FUN_00828560(unsigned int flags)
{
    reinterpret_cast<::FUN_00828590 *>(this)->FUN_00828590::~FUN_00828590();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor: if unk71 is set and FUN_0044ddc0() returns non-null, calls FUN_0040b800(true) on the returned shell object.
// @fnv 0x00828590
FUN_00828590::~FUN_00828590()
{
    if (unk71 && ((::FUN_0040b800_shell *)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())))
        reinterpret_cast<::UnloadMagic *>((((::FUN_0040b800_shell *)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()))))->FUN_0040b800(true);
}

struct SelectedRecord
{
    int x;
    int y;
    int z;
};
struct SelectionPredicate
{
};
struct RecordSelector
{
    bool SelectRecord(void* context, int flags, SelectedRecord* output);
};
struct SummonCreatureEffectHelper : SummonCreatureEffect
{
    TESForm* GetBaseForm();
    bool FUN_00828f00(int iUnused, NiPoint3* pkPos);
};
// Collects records via GetZero, sorts them with FUN_00ec6f20, finds the first matching FUN_00828f00, copies it to output and frees the array.
// @fnv 0x00828cb0
bool RecordSelector::SelectRecord(void* context, int flags, SelectedRecord* output)
{
    SelectedRecord* entries = 0;
    int count = ((FUN_00828da0_shell*)this)->GetZero((int)&entries, (int)context, flags);
    if (count <= 0 || entries == 0)
        return false;
    int index = 0;
    (*reinterpret_cast<void * *>(&::g_011dcc58)) = context;
    std::qsort((void *)((int)entries), count, sizeof(SelectedRecord), (int (*)(const void *, const void *))((int)&((int (&)(const void *, const void *))::FUN_00828b20)));
    index = 0;
    while (index < count && !reinterpret_cast<::SummonCreatureEffectHelper *>((((SelectionPredicate*)this)))->FUN_00828f00(flags, (::NiPoint3 *)(::SelectedRecord *)(&entries[index])))
    {
        ++index;
    }
    if (index < count)
    {
        *output = entries[index];
        SelectedRecord* selected = entries;
        ::FUN_00401030(selected);
        return true;
    }
    else
    {
        SelectedRecord* discarded = entries;
        ::FUN_00401030(discarded);
        return false;
    }
}

struct Actor;
struct ListNode
{
    void* value;
    bool _ref_008256d0() const;
};
struct PlayerEffects
{
    virtual void slot0();
    virtual void slot1();
    virtual ListNode* GetFirst();
};
struct Actor
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
    PlayerEffects effects;
};
struct ActiveEffect;
struct EffectSetting
{
};
class EffectSetting;
struct ActiveEffect
{
public:
    ::EffectSetting *GetEffectSetting() const;
};
struct GlobalObject2_0040c150
{
};

struct FUN_00829970_Class
{
    void DispelOldestQualifyingEffect();
};
// @fnv 0x00829970
void FUN_00829970_Class::DispelOldestQualifyingEffect()
{
    ListNode* node = (*reinterpret_cast<::Actor * *>(&::_g_thePlayer))->effects.GetFirst();
    int bestAge;
    ActiveEffect* bestEffect;
    float validCount;
    bestEffect = 0;
    validCount = DAT_01015f5c;
    bestAge = 0;
    while (node && !node->_ref_008256d0())
    {
        ActiveEffect* effect = *((::ActiveEffect **)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item));
        EffectSetting* setting = effect->GetEffectSetting();
        if (::IsArchetypeFlagSet((::EffectSetting *)(setting)) && reinterpret_cast<::S3e60 *>((setting))->FUN_00403e60(0x40000))
        {
            ++bestAge;
            if (reinterpret_cast<::TimeoutTimer *>((effect))->FUN_006b9130() > validCount)
            {
                bestEffect = effect;
                validCount = reinterpret_cast<::TimeoutTimer *>((effect))->FUN_006b9130();
            }
        }
        node = ((::ListNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    if (bestEffect && bestAge > *((int *)&(::FUN_0043d4d0((int *)&(::g_011d171c)))))
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>((bestEffect))->FUN_00804210(false);
}

struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3();
    NiPoint3(float fX, float fY, float fZ);
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
public:
    NiPoint3 operator+(const NiPoint3& kPt) const;
};

NiPoint3 operator*(float fScalar, const NiPoint3& kPt);

void* FUN_006890b0(void* pCell, float fScale, const char* m_kModelObjectsItem, NiPoint3 point, NiPoint3 vel, float fScale2,
                   int iFlags, int iUnk);

struct S_008287e0_Cell;

struct S_008287e0_Actor
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0A();
    virtual void vfn0B();
    virtual void vfn0C();
    virtual void vfn0D();
    virtual void vfn0E();
    virtual void vfn0F();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn1A();
    virtual void vfn1B();
    virtual void vfn1C();
    virtual void vfn1D();
    virtual void vfn1E();
    virtual void vfn1F();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn2A();
    virtual void vfn2B();
    virtual void vfn2C();
    virtual void vfn2D();
    virtual void vfn2E();
    virtual void vfn2F();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn3A();
    virtual void vfn3B();
    virtual void vfn3C();
    virtual void vfn3D();
    virtual void vfn3E();
    virtual void vfn3F();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn4A();
    virtual void vfn4B();
    virtual void vfn4C();
    virtual void vfn4D();
    virtual void vfn4E();
    virtual void vfn4F();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn5A();
    virtual void vfn5B();
    virtual void vfn5C();
    virtual void vfn5D();
    virtual void vfn5E();
    virtual void vfn5F();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn6A();
    virtual void vfn6B();
    virtual void vfn6C();
    virtual void vfn6D();
    virtual void vfn6E();
    virtual void vfn6F();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn7A();
    virtual void vfn7B();
    virtual void vfn7C();
    virtual const NiPoint3& vfn7D();
};

struct S_008287e0_Caster
{
};

struct S_008287e0_Model
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual const char* vfn05();
};

struct S_008287e0_Base
{
    virtual void vfn00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct S_008287e0_Setting : S_008287e0_Base, S_008287e0_Model
{
};

struct S_008287e0_Item
{
};

struct S_008287e0_Temp
{
};

struct S_008287e0_Magic
{
};

struct S_008287e0
{
    void* vtbl;
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
    float unk54;
    NiPoint3 unk58;
    NiPoint3 unk64;
    char unk70;
    bool unk71;

    void FUN_008287e0();
};

// @fnv 0x008287e0
void S_008287e0::FUN_008287e0()
{
    S_008287e0_Actor* ref = ((::S_008287e0_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::S_008287e0_Actor *)(reinterpret_cast<::MagicTarget *>((((::S_008287e0_Caster *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (!ref)
        return;

    unk64 = (*(const ::NiPoint3 *)(reinterpret_cast<::TESRecipe *>((ref))->GetData()));
    unk58 = ref->vfn7D();
    NiPoint3 point;
    if (reinterpret_cast<::RecordSelector *>(this)->SelectRecord(ref, unk4C, (::SelectedRecord *)(::NiPoint3 *)(&point)))
        unk58 = point;

    const char* m_pIdleForm = "SpecialIdle_SummonEffect";
    NiPoint3 vel = 64.0f * NiPoint3(-FUN_005c53d0(-unk64.z), FUN_005b9e80(-unk64.z), 0.0f);
    void* m_kModelObjectsItem =
        FUN_006890b0(((::S_008287e0_Cell *)(reinterpret_cast<::LowProcess *>((ref))->GetTarget())), 1.0f, ((::S_008287e0_Setting *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((((::S_008287e0_Item *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->FUN_00825c00()))->vfn05(), vel, unk58, 1.0f, 7, 0);
    reinterpret_cast<::FUN_00689920_shell *>((((S_008287e0_Temp*)m_kModelObjectsItem)))->FUN_00689920(m_pIdleForm);
    void* pAVObject = ((void *)(reinterpret_cast<::fnv_00490e40::FUN_00490e40_shell *>((((S_008287e0_Temp*)m_kModelObjectsItem)))->FUN_00490e40()));
    unk54 = ::GetAnimValueByPrefix((::NiObj6220 *)(pAVObject), m_pIdleForm, "Hit");

    if (!unk71 && ((::S_008287e0_Magic *)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())))
    {
        reinterpret_cast<::MagicItem *>((((::S_008287e0_Magic *)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()))))->Preload(false);
        unk71 = true;
    }
}

extern char DAT_0107c2ac;

struct FUN_00828470_helper1
{
    void* unk00;
};

struct FUN_00828470_base
{
    FUN_00828470_base(void* a1, void* a2, FUN_00828470_helper1* a3);
    ~FUN_00828470_base();
};

struct FUN_00828470_sub
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00828470_cls : FUN_00828470_base
{
    void* m_vptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
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
    int m_4c;
    unsigned char m_50;
    float m_54;
    FUN_00828470_sub m_58;
    FUN_00828470_sub m_64;
    unsigned char m_70;
    unsigned char m_71;
    FUN_00828470_cls(void* a1, void* a2, FUN_00828470_helper1* a3);
};

// Constructor: sets the vtable, initialises the two sub-objects, and zeroes m_4c, m_50, m_54, m_70 and m_71.
// @fnv 0x00828470
FUN_00828470_cls::FUN_00828470_cls(void* a1, void* a2, FUN_00828470_helper1* a3) : FUN_00828470_base(a1, a2, a3)
{
    m_vptr = &DAT_0107c2ac;
    m_4c = 0;
    m_50 = 0;
    m_54 = 0.0f;
    m_58 = *(FUN_00828470_sub*)&(*reinterpret_cast<unsigned int *>((void *)&::NiPoint3::ZERO));
    m_64 = *(FUN_00828470_sub*)&(*reinterpret_cast<unsigned int *>((void *)&::NiPoint3::ZERO));
    m_70 = 0;
    m_71 = 0;
}

namespace fnv_00828610 {
struct FUN_00828610_sub
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

struct FUN_00828470_cls
{
    FUN_00828470_cls(void* a1, void* a2, void* a3);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
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
    int m_4c;
    unsigned char m_50;
    float m_54;
    FUN_00828610_sub m_58;
    FUN_00828610_sub m_64;
    unsigned char m_70;
    unsigned char m_71;
};

struct FUN_0044ddc0_ret
{
};

struct FUN_00828610_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int m_28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    int m_4c;
    unsigned char m_50;
    float m_54;
    FUN_00828610_sub m_58;
    FUN_00828610_sub m_64;
    unsigned char m_70;
    unsigned char m_71;

    FUN_00828470_cls* CloneObject();
};

// @fnv 0x00828610
FUN_00828470_cls* FUN_00828610_cls::CloneObject()
{
    FUN_00828470_cls* obj = new FUN_00828470_cls((void*)m_28, (void*)m_08, (void*)m_0c);
    reinterpret_cast<::AssociatedItemCopyEntry *>(this)->FUN_00806d50((::ActiveEffect *)(obj));
    obj->m_4c = m_4c;
    obj->m_50 = m_50;
    obj->m_54 = m_54;
    obj->m_58 = m_58;
    obj->m_64 = m_64;
    obj->m_70 = m_70;
    if (m_71 != 0 && obj->m_71 == 0 && ((::fnv_00828610::FUN_0044ddc0_ret *)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())))
    {
        reinterpret_cast<::MagicItem *>((((::fnv_00828610::FUN_0044ddc0_ret *)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()))))->Preload(0);
    }
    obj->m_71 = m_71;
    return obj;
}
}  // namespace fnv_00828610

class B828760Task
{
  public:
    B828760Task(void* pvOwner, void* pvTarget, int iType);

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
};

// Allocates and constructs a B828760Task from an owner, a target and a type, returning the new task.
// @fnv 0x00828760
B828760Task* __cdecl FUN_00828760(void* pvOwner, void* pvTarget, int iType)
{
    return new B828760Task(pvOwner, pvTarget, iType);
}

struct FxnNode;

struct FxnObj
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
    virtual void v49(int a);
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
    virtual void v116();
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
    virtual bool v139(int a);
};

struct FxnNode
{
};


struct FUN_008289e0_cls : public SummonCreatureEffect
{
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
    FxnObj* m_4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    unsigned char unk70;
    unsigned char m_71;
    void CleanupSummonedCreature();
};

// @fnv 0x008289e0
void FUN_008289e0_cls::CleanupSummonedCreature()
{
    FxnNode* a = (((::FxnNode *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) != 0) ? ((::FxnNode *)(reinterpret_cast<::MagicTarget *>((((::FxnNode *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (this->m_4c != 0 && a != 0)
    {
        if (((::FxnNode *)(reinterpret_cast<::BSShaderNoLightingProperty *>((this->m_4c))->GetBaseTexture())) != 0 && ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::FxnNode *)(reinterpret_cast<::BSShaderNoLightingProperty *>((this->m_4c))->GetBaseTexture()))))->FUN_0045cd60())) == 0)
        {
            if (!this->m_4c->v139(0))
            {
                reinterpret_cast<::KillActor *>((this->m_4c))->FUN_0089d900((::Actor *)(0), 0.0f);
            }
            reinterpret_cast<::FUN_008feab0_cls *>((((::FxnNode *)(reinterpret_cast<::BSShaderNoLightingProperty *>((this->m_4c))->GetBaseTexture()))))->FUN_008feab0((::Actor *)(this->m_4c));
            ::FUN_0080b9e0(this->m_4c, (int)(a), 1);
        }
        else
        {
            ::FUN_0080b9e0(this->m_4c, (int)(a), 1);
            this->m_4c->v49(1);
        }
        this->m_4c = 0;
    }
    if (this->m_71 != 0 && ((::FxnNode *)(reinterpret_cast<::Twin_0044ddc0 *>((this))->GetName())) != 0)
    {
        reinterpret_cast<::UnloadMagic *>((((::FxnNode *)(reinterpret_cast<::Twin_0044ddc0 *>((this))->GetName()))))->FUN_0040b800(0);
        this->m_71 = 0;
    }
}


// Looks up two float values by id from g_011dcc58 and returns 0 if equal, 1 if the first is smaller, -1 otherwise.
// @fnv 0x00828b20
int __cdecl FUN_00828b20(int aiIdA, int aiIdB)
{
    int idA = aiIdA;
    int idB = aiIdB;
    float valueA = ::ComputeDirectionalFalloff((::S_00828dc0_Actor *)(g_011dcc58), (::S_00828dc0_Obj *)(idA));
    float valueB = ::ComputeDirectionalFalloff((::S_00828dc0_Actor *)(g_011dcc58), (::S_00828dc0_Obj *)(idB));
    if (valueA == valueB)
    {
        return 0;
    }
    else if (valueA < valueB)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

struct S_00828ba0_Actor;
struct S_00828ba0_Target
{
    virtual ~S_00828ba0_Target();
    virtual int vfn00();
    virtual int vfn01();
    virtual int vfn02();
    virtual int vfn03();
    virtual int vfn04();
    virtual int vfn05();
    virtual int vfn06();
    virtual int vfn07();
    virtual int vfn08();
    virtual int vfn09();
    virtual int vfn0a();
    virtual int vfn0b();
    virtual int vfn0c();
    virtual int vfn0d();
    virtual int vfn0e();
    virtual int vfn0f();
    virtual int vfn10();
    virtual int vfn11();
    virtual int vfn12();
    virtual int vfn13();
    virtual int vfn14();
    virtual int vfn15();
    virtual int vfn16();
    virtual int vfn17();
    virtual int vfn18();
    virtual int vfn19();
    virtual int vfn1a();
    virtual int vfn1b();
    virtual int vfn1c();
    virtual int vfn1d();
    virtual int vfn1e();
    virtual int vfn1f();
    virtual int vfn20();
    virtual int vfn21();
    virtual int vfn22();
    virtual int vfn23();
    virtual int vfn24();
    virtual int vfn25();
    virtual int vfn26();
    virtual int vfn27();
    virtual int vfn28();
    virtual int vfn29();
    virtual int vfn2a();
    virtual int vfn2b();
    virtual int vfn2c();
    virtual int vfn2d();
    virtual int vfn2e();
    virtual int vfn2f();
    virtual int vfn30();
    virtual int vfn31();
    virtual int vfn32();
    virtual int vfn33();
    virtual int vfn34();
    virtual int vfn35();
    virtual int vfn36();
    virtual int vfn37();
    virtual int vfn38();
    virtual int vfn39();
    virtual int vfn3a();
    virtual int vfn3b();
    virtual int vfn3c();
    virtual int vfn3d();
    virtual int vfn3e();
    virtual int vfn3f();
    virtual int vfn40();
    virtual int vfn41();
    virtual int vfn42();
    virtual int vfn43();
    virtual int vfn44();
    virtual int vfn45();
    virtual int vfn46();
    virtual int vfn47();
    virtual int vfn48();
    virtual int vfn49();
    virtual int vfn4a();
    virtual int vfn4b();
    virtual int vfn4c();
    virtual int vfn4d();
    virtual int vfn4e();
    virtual int vfn4f();
    virtual int vfn50();
    virtual int vfn51();
    virtual int vfn52();
    virtual int vfn53();
    virtual int vfn54();
    virtual int vfn55();
    virtual int vfn56();
    virtual int vfn57();
    virtual int vfn58();
    virtual int vfn59();
    virtual int vfn5a();
    virtual int vfn5b();
    virtual int vfn5c();
    virtual int vfn5d();
    virtual int vfn5e();
    virtual int vfn5f();
    virtual int vfn60();
    virtual int vfn61();
    virtual int vfn62();
    virtual int vfn63();
    virtual int vfn64();
    virtual int vfn65();
    virtual int vfn66();
    virtual int vfn67();
    virtual int vfn68();
    virtual int vfn69();
    virtual int vfn6a();
    virtual int vfn6b();
    virtual int vfn6c();
    virtual int vfn6d();
    virtual int vfn6e();
    virtual int vfn6f();
    virtual int vfn70();
    virtual int vfn71();
    virtual int vfn72();
    virtual int vfn73();
    virtual int vfn74();
    virtual int vfn75();
    virtual int vfn76();
    virtual int vfn77();
    virtual int vfn78();
    virtual int vfn79();
    virtual int vfn7a();
    virtual int vfn7b();
    virtual int vfn7c();
    virtual int vfn7d();
    virtual int vfn7e();
    virtual int vfn7f();
    virtual int vfn80();
    virtual int vfn81();
    virtual int vfn82();
    virtual int vfn83();
    virtual int vfn84();
    virtual int vfn85();
    virtual int vfn86();
    virtual int vfn87();
    virtual int vfn88();
    virtual int vfn89();
    virtual bool vfn8b(int a);
};

struct S_00828ba0_Owner
{
};

struct S_00828ba0 : SummonCreatureEffect
{
    float m_04;
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
    S_00828ba0_Target* m_4c;
    int unk50;
    float m_54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    unsigned char m_70;
    void FUN_00828ba0(int unused);
};


struct S_00828dc0_Vec3
{
    float x, y, z;
};

struct S_00828dc0_Mat;
struct S_00828dc0_Mat
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
};


struct S_00828dc0_Obj
{
};

struct S_00828dc0_Actor
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual int vf1f4();
};


// @fnv 0x00828dc0
float ComputeDirectionalFalloff(S_00828dc0_Actor* actor, S_00828dc0_Obj* obj)
{
    float low = DAT_0101b2d0;
    float high = DAT_01013d84;
    S_00828dc0_Vec3 delta;
    reinterpret_cast<::FUN_00439ef0_class *>((obj))->FUN_00439ef0((::NiPoint3 *)(::S_00828dc0_Vec3 *)(&delta), (*(const ::NiPoint3 *)(actor->vf1f4())));
    float dist = reinterpret_cast<::NiPoint3 *>(&(delta))->ComputeMagnitude();
    float scale = 1.0f;
    if (dist < low)
        scale = dist / low;
    else if (dist < high)
        scale = (high - dist) / (high - low);
    else
        scale = 0.0f;
    S_00828dc0_Vec3 rot = *((::S_00828dc0_Vec3 *)(reinterpret_cast<::TESRecipe *>((actor))->GetData()));
    S_00828dc0_Mat matrix = (*reinterpret_cast<::S_00828dc0_Mat *>(&::DAT_011a9448));
    reinterpret_cast<::FUN_004a0c90_shell *>(&(matrix))->FUN_004a0c90(rot.z);
    S_00828dc0_Mat mInv;
    reinterpret_cast<::ThreeByThreeMatrix *>(&(matrix))->FUN_004b45b0((::ThreeByThreeMatrix *)(::S_00828dc0_Mat *)(&mInv));
    S_00828dc0_Vec3 localDir;
    ::FUN_004b3ae0((::NiPoint3 *)(::S_00828dc0_Vec3 *)(&localDir), (*(const ::NiPoint3 *)(&delta)), (const float *)(const ::S_00828dc0_Mat *)(&matrix));
    reinterpret_cast<::FUN_004a0c10_s *>(&(localDir))->FUN_004a0c10();
    float x = 1.0f - ((float)(::FUN_00408820(localDir.x)));
    x = x * x;
    float fy = (1.0f + localDir.y) * DAT_01011588;
    return scale * x * fy;
}

struct RegistrationManager
{
};

struct OptionalState
{
};

struct FUN_008297a0_shell : public SummonCreatureEffect
{
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
    OptionalState* unk4c;
    char unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;

    void FUN_008297a0(int);
};

// @fnv 0x008297a0
void FUN_008297a0_shell::FUN_008297a0(int value)
{
    reinterpret_cast<::fnv_00806de0::AssociatedItemEffect *>(this)->FUN_00806de0((::Actor *)(value));
    int id = 0;
    if (unk4c != 0)
        id = reinterpret_cast<::FUN_0084e3a0_Class *>((unk4c))->FUN_0084e3a0();
    reinterpret_cast<::C857A10Buffer *>(((*reinterpret_cast<::RegistrationManager * *>(&::g_TESSaveLoadGame))))->FUN_00857a10((const unsigned int *)(const void *)(&id), 4);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::RegistrationManager * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unk50, 1);
    if (unk4c == 0)
    {
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::RegistrationManager * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unk54, 4);
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::RegistrationManager * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unk58, 12);
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::RegistrationManager * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(&unk64, 12);
    }
}

struct S_008294e0_Point
{
    float x, y, z;
};

struct S_008294e0_Str
{
    char* m_data;
    unsigned short m_len;
    unsigned short m_kMaximumCorner;
    ~S_008294e0_Str();
};

struct S_008294e0_Named
{
};

struct TESForm
{
    virtual ~TESForm();
};
struct TESBoundObject : TESForm
{
};

struct S_008294e0_Proc
{
    virtual void vp_000();
    virtual void vp_004();
    virtual void vp_008();
    virtual void vp_00C();
    virtual void vp_010();
    virtual void vp_014();
    virtual void vp_018();
    virtual void vp_01C();
    virtual void vp_020();
    virtual void vp_024();
    virtual void vp_028();
    virtual void vp_02C();
    virtual void vp_030();
    virtual void vp_034();
    virtual void vp_038();
    virtual void vp_03C();
    virtual void vp_040();
    virtual void vp_044();
    virtual void vp_048();
    virtual void vp_04C();
    virtual void vp_050();
    virtual void vp_054();
    virtual void vp_058();
    virtual void vp_05C();
    virtual void vp_060();
    virtual void vp_064();
    virtual void vp_068();
    virtual void vp_06C();
    virtual void vp_070();
    virtual void vp_074();
    virtual void vp_078();
    virtual void vp_07C();
    virtual void vp_080();
    virtual void vp_084();
    virtual void vp_088();
    virtual void vp_08C();
    virtual void vp_090();
    virtual void vp_094();
    virtual void vp_098();
    virtual void vp_09C();
    virtual void vp_0A0();
    virtual void vp_0A4();
    virtual void vp_0A8();
    virtual void vp_0AC();
    virtual void vp_0B0();
    virtual void vp_0B4();
    virtual void vp_0B8();
    virtual void vp_0BC();
    virtual void vp_0C0();
    virtual void vp_0C4();
    virtual void vp_0C8();
    virtual void vp_0CC();
    virtual void vp_0D0();
    virtual void vp_0D4();
    virtual void vp_0D8();
    virtual void vp_0DC();
    virtual void vp_0E0();
    virtual void vp_0E4();
    virtual void vp_0E8();
    virtual void vp_0EC();
    virtual void vp_0F0();
    virtual void vp_0F4();
    virtual void vp_0F8();
    virtual void vp_0FC();
    virtual void vp_100();
    virtual void vp_104();
    virtual void vp_108();
    virtual void vp_10C();
    virtual void vp_110();
    virtual void vp_114();
    virtual void vp_118();
    virtual void vp_11C();
    virtual void vp_120();
    virtual void vp_124();
    virtual void vp_128();
    virtual void vp_12C();
    virtual void vp_130();
    virtual void vp_134();
    virtual void vp_138();
    virtual void vp_13C();
    virtual void vp_140();
    virtual void vp_144();
    virtual void vp_148();
    virtual void vp_14C();
    virtual void vp_150();
    virtual void vp_154();
    virtual void vp_158();
    virtual void vp_15C();
    virtual void vp_160();
    virtual void vp_164();
    virtual void vp_168();
    virtual void vp_16C();
    virtual void vp_170();
    virtual void vp_174();
    virtual void vp_178();
    virtual void vp_17C();
    virtual void vp_180();
    virtual void vp_184();
    virtual void vp_188();
    virtual void vp_18C();
    virtual void vp_190();
    virtual void vp_194();
    virtual void vp_198();
    virtual void vp_19C();
    virtual void vp_1A0();
    virtual void vp_1A4();
    virtual void vp_1A8();
    virtual void vp_1AC();
    virtual void vp_1B0();
    virtual void vp_1B4();
    virtual void vp_1B8();
    virtual void vp_1BC();
    virtual void vp_1C0();
    virtual void vp_1C4();
    virtual void vp_1C8();
    virtual void vp_1CC();
    virtual void vp_1D0();
    virtual void vp_1D4();
    virtual void vp_1D8();
    virtual void vp_1DC();
    virtual void vp_1E0();
    virtual void vp_1E4();
    virtual void vp_1E8();
    virtual void vp_1EC();
    virtual void vp_1F0();
    virtual void vp_1F4();
    virtual void vp_1F8();
    virtual void vp_1FC();
    virtual void vp_200();
    virtual void vp_204();
    virtual void vp_208();
    virtual void vp_20C();
    virtual void vp_210();
    virtual void vp_214();
    virtual void vp_218();
    virtual void vp_21C();
    virtual void vp_220();
    virtual void vp_224();
    virtual void vp_228();
    virtual void vp_22C();
    virtual void vp_230();
    virtual void vp_234();
    virtual void vp_238();
    virtual void vp_23C();
    virtual void vp_240();
    virtual void vp_244();
    virtual void vp_248();
    virtual void vp_24C();
    virtual void vp_250();
    virtual void vp_254();
    virtual void vp_258();
    virtual void vp_25C();
    virtual void vp_260();
    virtual void vp_264();
    virtual void vp_268();
    virtual void vp_26C();
    virtual void vp_270();
    virtual void vp_274();
    virtual void vp_278();
    virtual void vp_27C();
    virtual void vp_280();
    virtual void vp_284();
    virtual void vp_288();
    virtual void vp_28C();
    virtual void vp_290();
    virtual void vp_294();
    virtual void vp_298();
    virtual void vp_29C();
    virtual void vp_2A0();
    virtual void vp_2A4();
    virtual void vp_2A8();
    virtual void vp_2AC();
    virtual void vp_2B0();
    virtual void vp_2B4();
    virtual void vp_2B8();
    virtual void vp_2BC();
    virtual void vp_2C0();
    virtual void vp_2C4();
    virtual void vp_2C8();
    virtual void vp_2CC();
    virtual void vp_2D0();
    virtual void vp_2D4();
    virtual void vp_2D8();
    virtual void vp_2DC();
    virtual void vp_2E0();
    virtual void vp_2E4();
    virtual void vp_2E8();
    virtual void vp_2EC();
    virtual void vp_2F0();
    virtual void vp_2F4();
    virtual void vp_2F8();
    virtual void vp_2FC();
    virtual void vp_300();
    virtual void vp_304();
    virtual void vp_308();
    virtual void vp_30C();
    virtual void vp_310();
    virtual void vp_314();
    virtual void vp_318();
    virtual void vp_31C();
    virtual void vp_320();
    virtual void vp_324();
    virtual void vp_328();
    virtual void vp_32C();
    virtual void vp_330();
    virtual void vp_334();
    virtual void vp_338();
    virtual void vp_33C();
    virtual void vp_340();
    virtual void vp_344();
    virtual void vp_348();
    virtual void vp_34C();
    virtual void vp_350();
    virtual void vp_354();
    virtual void vp_358();
    virtual void vp_35C();
    virtual void vp_360();
    virtual void vp_364();
    virtual void vp_368();
    virtual void vp_36C();
    virtual void vp_370();
    virtual void vp_374();
    virtual void vp_378();
    virtual void vp_37C();
    virtual void vp_380();
    virtual void vp_384();
    virtual void vp_388();
    virtual void vp_38C();
    virtual void vp_390();
    virtual void vp_394();
    virtual void vp_398();
    virtual void vp_39C();
    virtual void vp_3A0();
    virtual void vp_3A4();
    virtual void vp_3A8();
    virtual void vp_3AC();
    virtual void vp_3B0();
    virtual void vp_3B4();
    virtual void vp_3B8();
    virtual void vp_3BC();
    virtual void vp_3C0();
    virtual void vp_3C4();
    virtual void vp_3C8();
    virtual void vp_3CC();
    virtual void vp_3D0();
    virtual void vp_3D4();
    virtual void vp_3D8();
    virtual void vp_3DC();
    virtual void vp_3E0();
    virtual void vp_3E4();
    virtual void vp_3E8();
    virtual void vp_3EC();
    virtual void vp_3F0();
    virtual void vp_3F4();
    virtual void vp_3F8();
    virtual void vp_3FC();
    virtual void vp_400();
    virtual void vp_404();
    virtual void vp_408();
    virtual void vp_40C();
    virtual void vp_410();
    virtual void vp_414();
    virtual void vp_418();
    virtual void vp_41C();
    virtual void vp_420();
    virtual void vp_424();
    virtual void vp_428();
    virtual void vp_42C();
    virtual void vp_430();
    virtual void vp_434();
    virtual void vp_438();
    virtual void vp_43C();
    virtual void vp_440();
    virtual void vp_444();
    virtual void vp_448();
    virtual void vp_44C();
    virtual void vp_450();
    virtual void vp_454();
    virtual void vp_458();
    virtual void vp_45C();
    virtual void vp_460();
    virtual void vp_464();
    virtual void vp_468();
    virtual void vp_46C();
    virtual void vp_470();
    virtual void vp_474();
    virtual void vp_478();
    virtual void vp_47C();
    virtual void vp_480();
    virtual void vp_484();
    virtual void vp_488();
    virtual void vp_48C();
    virtual void vp_490();
    virtual void vp_494();
    virtual void vp_498();
    virtual void vp_49C();
    virtual void vp_4A0();
    virtual void vp_4A4();
    virtual void vp_4A8();
    virtual void vp_4AC();
    virtual void vp_4B0();
    virtual void vp_4B4();
    virtual void vp_4B8();
    virtual void vp_4BC();
    virtual void vp_4C0();
    virtual void vp_4C4();
    virtual void vp_4C8();
    virtual void vp_4CC();
    virtual void vp_4D0();
    virtual void vp_4D4();
    virtual void vp_4D8();
    virtual void vp_4DC();
    virtual void vp_4E0();
    virtual void vp_4E4();
    virtual void vp_4E8();
    virtual void vp_4EC();
    virtual void vp_4F0();
    virtual void vp_4F4();
    virtual void vp_4F8();
    virtual void vp_4FC();
    virtual void vp_500();
    virtual void vp_504();
    virtual void vp_508();
    virtual void vp_50C();
    virtual void vp_510();
    virtual void vp_514();
    virtual void vp_518();
    virtual void vp_51C();
    virtual void vp_520();
    virtual void vp_524();
    virtual void vp_528();
    virtual void vp_52C();
    virtual void vp_530();
    virtual void vp_534();
    virtual void vp_538();
    virtual void vp_53C();
    virtual void vp_540();
    virtual void vp_544();
    virtual void vp_548();
    virtual void vp_54C();
    virtual void vp_550();
    virtual void vp_554();
    virtual void vp_558();
    virtual void vp_55C();
    virtual void vp_560();
    virtual void vp_564();
    virtual void vp_568();
    virtual void vp_56C();
    virtual void vp_570();
    virtual void vp_574();
    virtual void vp_578();
    virtual void vp_57C();
    virtual void vp_580();
    virtual void vp_584();
    virtual void vp_588();
    virtual void vp_58C();
    virtual void vp_590();
    virtual void vp_594();
    virtual void vp_598();
    virtual void vp_59C();
    virtual void vp_5A0();
    virtual void vp_5A4();
    virtual void vp_5A8();
    virtual void vp_5AC();
    virtual void vp_5B0();
    virtual void vp_5B4();
    virtual void vp_5B8();
    virtual void vp_5BC();
    virtual void vp_5C0();
    virtual void vp_5C4();
    virtual void vp_5C8();
    virtual void vp_5CC();
    virtual void vp_5D0();
    virtual void vp_5D4();
    virtual void vp_5D8();
    virtual void vp_5DC();
    virtual void vp_5E0();
    virtual void vp_5E4();
    virtual void vp_5E8();
    virtual void vp_5EC();
    virtual void vp_5F0();
    virtual void vp_5F4();
    virtual void vp_5F8();
    virtual void vp_5FC();
    virtual void vp_600();
    virtual void vp_604();
    virtual void vp_608();
    virtual void vp_60C();
    virtual void vp_610();
    virtual void vp_614();
    virtual void vp_618();
    virtual void vp_61C();
    virtual void vp_620();
    virtual void vp_624();
    virtual void vp_628();
    virtual void vp_62C();
    virtual void vp_630();
    virtual void vp_634();
    virtual void vp_638();
    virtual void vp_63C();
    virtual void vp_640();
    virtual void vp_644();
    virtual void vp_648();
    virtual void vp_64C();
    virtual void vp_650();
    virtual void vp_654();
    virtual void vp_658();
    virtual void vp_65C();
    virtual void vp_660();
    virtual void vp_664();
    virtual void vp_668();
    virtual void vp_66C();
    virtual void vp_670();
    virtual void vp_674();
    virtual void vp_678();
    virtual void vp_67C();
    virtual void vp_680();
    virtual void vp_684();
    virtual void vp_688();
    virtual void vp_68C();
    virtual void vp_690();
    virtual void SetSomething(int a);
};

struct S_008294e0_Actor;
struct S_008294e0_Ref
{
    virtual void vr_000();
    virtual void vr_004();
    virtual void vr_008();
    virtual void vr_00C();
    virtual void vr_010();
    virtual void vr_014();
    virtual void vr_018();
    virtual void vr_01C();
    virtual void vr_020();
    virtual void vr_024();
    virtual void vr_028();
    virtual void vr_02C();
    virtual void vr_030();
    virtual void vr_034();
    virtual void vr_038();
    virtual void vr_03C();
    virtual void vr_040();
    virtual void vr_044();
    virtual void vr_048();
    virtual void vr_04C();
    virtual void vr_050();
    virtual void vr_054();
    virtual void vr_058();
    virtual void vr_05C();
    virtual void vr_060();
    virtual void vr_064();
    virtual void vr_068();
    virtual void vr_06C();
    virtual void vr_070();
    virtual void vr_074();
    virtual void vr_078();
    virtual void vr_07C();
    virtual void vr_080();
    virtual void vr_084();
    virtual void vr_088();
    virtual void vr_08C();
    virtual void vr_090();
    virtual void vr_094();
    virtual void vr_098();
    virtual void vr_09C();
    virtual void vr_0A0();
    virtual void vr_0A4();
    virtual void vr_0A8();
    virtual void vr_0AC();
    virtual void vr_0B0();
    virtual void vr_0B4();
    virtual void vr_0B8();
    virtual void vr_0BC();
    virtual void vr_0C0();
    virtual void vr_0C4();
    virtual void vr_0C8();
    virtual void vr_0CC();
    virtual void vr_0D0();
    virtual void vr_0D4();
    virtual void vr_0D8();
    virtual void vr_0DC();
    virtual void vr_0E0();
    virtual void vr_0E4();
    virtual void vr_0E8();
    virtual void vr_0EC();
    virtual void vr_0F0();
    virtual void vr_0F4();
    virtual void vr_0F8();
    virtual void vr_0FC();
    virtual bool IsActor();
    virtual void vr_104();
    virtual void vr_108();
    virtual void vr_10C();
    virtual void vr_110();
    virtual void vr_114();
    virtual void vr_118();
    virtual void vr_11C();
    virtual void vr_120();
    virtual void vr_124();
    virtual void vr_128();
    virtual void vr_12C();
    virtual void vr_130();
    virtual void vr_134();
    virtual void vr_138();
    virtual void vr_13C();
    virtual void vr_140();
    virtual void vr_144();
    virtual void vr_148();
    virtual void vr_14C();
    virtual void vr_150();
    virtual void vr_154();
    virtual void vr_158();
    virtual void vr_15C();
    virtual void vr_160();
    virtual void vr_164();
    virtual void vr_168();
    virtual void vr_16C();
    virtual void vr_170();
    virtual void vr_174();
    virtual void vr_178();
    virtual void vr_17C();
    virtual void vr_180();
    virtual void vr_184();
    virtual void vr_188();
    virtual void vr_18C();
    virtual void vr_190();
    virtual void vr_194();
    virtual void vr_198();
    virtual void vr_19C();
    virtual void vr_1A0();
    virtual void vr_1A4();
    virtual void vr_1A8();
    virtual void vr_1AC();
    virtual void vr_1B0();
    virtual void vr_1B4();
    virtual void vr_1B8();
    virtual void vr_1BC();
    virtual void vr_1C0();
    virtual void vr_1C4();
    virtual void vr_1C8();
    virtual void vr_1CC();
    virtual void vr_1D0();
    virtual void vr_1D4();
    virtual void vr_1D8();
    virtual void vr_1DC();
    virtual void vr_1E0();
    virtual void vr_1E4();
    virtual void vr_1E8();
    virtual void vr_1EC();
    virtual void vr_1F0();
    virtual void vr_1F4();
    virtual void vr_1F8();
    virtual void vr_1FC(int a);
    virtual void vr_200();
    virtual void vr_204();
    virtual void vr_208();
    virtual void vr_20C();
    virtual void vr_210();
    virtual void vr_214();
    virtual void vr_218();
    virtual void vr_21C();
    virtual void vr_220();
    virtual void vr_224();
    virtual void vr_228();
    virtual void vr_22C();
    virtual void vr_230();
    virtual void vr_234();
    virtual void vr_238();
    virtual void vr_23C();
    virtual void vr_240();
    virtual void vr_244();
    virtual void vr_248();
    virtual void vr_24C();
    virtual void vr_250();
    virtual void vr_254();
    virtual void vr_258();
    virtual void vr_25C();
    virtual void vr_260();
};

struct S_008294e0_Actor
{
};

struct S_008294e0_Target
{
};

struct S_008294e0_Handler
{
};


struct S_008294e0_Effect
{
    TESForm* FUN_006733e0();
};

struct S_008294e0_Summon : S_008294e0_Effect
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    int unk30, unk34, unk38, unk3C, unk40, unk44, unk48;
    S_008294e0_Ref* unk4C;
    int unk50, unk54;
    S_008294e0_Point unk58;
    S_008294e0_Point unk64;
    void SpawnSummonedActor(int unused);
};
// @fnv 0x00828ba0
void S_00828ba0::FUN_00828ba0(int unused)
{
    S_00828ba0_Actor* actor = ((::S_00828ba0_Owner *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::S_00828ba0_Actor *)(reinterpret_cast<::MagicTarget *>((((::S_00828ba0_Owner *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (!actor || (m_70 && (!m_4c || m_4c->vfn8b(0))))
    {
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(0);
        return;
    }
    if (m_04 >= m_54 && !m_70)
    {
        reinterpret_cast<::S_008294e0_Summon *>(this)->SpawnSummonedActor((int)(actor));
        if (actor == (*reinterpret_cast<::S_00828ba0_Actor * *>(&::_g_thePlayer)))
            reinterpret_cast<::FUN_00829970_Class *>(this)->DispelOldestQualifyingEffect();
        m_70 = 1;
    }
    if (m_4c && !m_4c->vfn8b(0))
        ::FUN_0080b8f0(m_4c, actor);
}

// @fnv 0x008294e0
void S_008294e0_Summon::SpawnSummonedActor(int unused)
{
    S_008294e0_Actor* actor = ((::S_008294e0_Target *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::S_008294e0_Actor *)(reinterpret_cast<::MagicTarget *>((((::S_008294e0_Target *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (!actor)
        return;
    S_008294e0_Ref* ref;
    TESBoundObject* pCreatureForm = dynamic_cast<TESBoundObject*>(FUN_006733e0());
    if (!pCreatureForm)
    {
        ::FUN_005b5e40();
    }
    else
    {
        ref = ((::S_008294e0_Ref *)(reinterpret_cast<::HandlerView *>(((*reinterpret_cast<::S_008294e0_Handler * *>(&::g_dataHandler))))->PlaceObjectReference(pCreatureForm, (::NiPoint3 *)(::S_008294e0_Point *)(&unk58), (::NiPoint3 *)(::S_008294e0_Point *)(&unk64),
                                                 (::TESObjectCELL *)(((int)(reinterpret_cast<::LowProcess *>((actor))->GetTarget()))), (::TESWorldSpace *)(0), (::TESObjectREFR *)(0), (const char *)(0), {})));
        if (ref)
        {
            if (ref->IsActor())
            {
                unk4C = ref;
                reinterpret_cast<::Reference *>((unk4C))->FUN_00575830((::Position *)(::S_008294e0_Point *)(&unk58));
                unk4C->vr_1FC(0);
                unk4C->vr_260();
                ::StartHostilityAndCombat((::B850Actor *)(unk4C), (::B850Actor *)(actor));
                ((::S_008294e0_Proc *)(reinterpret_cast<::BSShaderNoLightingProperty *>((unk4C))->GetBaseTexture()))->SetSomething(1);
            }
            else
            {
                ::FUN_005b5e40();
                reinterpret_cast<::fnv_00564930::FUN_00564930_shell *>((ref))->FUN_00564930(1);
            }
        }
        else if (!pCreatureForm)
        {
            ::FUN_005b5e40();
        }
    }
}

struct DbeffectBaseCall
{
};

struct Dbeffect : SummonCreatureEffect
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
    int formId;
    void FUN_00829900(void* arg);
};
// Calls the base handler, resolves formId to an Actor via FUN_004839c0, and dispels the effect if the lookup fails.
// @fnv 0x00829900
void Dbeffect::FUN_00829900(void* arg)
{
    reinterpret_cast<::fnv_00806e70::AssociatedItemEffect *>((((DbeffectBaseCall*)this)))->FUN_00806e70((::fnv_00806e70::Actor *)(arg));
    int iFormId = formId;
    if (iFormId)
    {
        formId = (int)dynamic_cast<Actor*>(::FUN_004839c0((unsigned int)iFormId));
        if (!formId)
            reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>((((ActiveEffect*)this)))->FUN_00804210(true);
    }
}



struct __declspec(align(16)) hkVector4
{
    float x;
    float y;
    float z;
    float w;

    hkVector4();
};


struct hkBool
{
    char m_cBooleanValue;

    hkBool() {}
    operator bool() const;
};

struct TESObjectCELL;
struct bhkWorld;


struct MobileObject
{
    virtual void Vfn000();
    virtual void Vfn001();
    virtual void Vfn002();
    virtual void Vfn003();
    virtual void Vfn004();
    virtual void Vfn005();
    virtual void Vfn006();
    virtual void Vfn007();
    virtual void Vfn008();
    virtual void Vfn009();
    virtual void Vfn00a();
    virtual void Vfn00b();
    virtual void Vfn00c();
    virtual void Vfn00d();
    virtual void Vfn00e();
    virtual void Vfn00f();
    virtual void Vfn010();
    virtual void Vfn011();
    virtual void Vfn012();
    virtual void Vfn013();
    virtual void Vfn014();
    virtual void Vfn015();
    virtual void Vfn016();
    virtual void Vfn017();
    virtual void Vfn018();
    virtual void Vfn019();
    virtual void Vfn01a();
    virtual void Vfn01b();
    virtual void Vfn01c();
    virtual void Vfn01d();
    virtual void Vfn01e();
    virtual void Vfn01f();
    virtual void Vfn020();
    virtual void Vfn021();
    virtual void Vfn022();
    virtual void Vfn023();
    virtual void Vfn024();
    virtual void Vfn025();
    virtual void Vfn026();
    virtual void Vfn027();
    virtual void Vfn028();
    virtual void Vfn029();
    virtual void Vfn02a();
    virtual void Vfn02b();
    virtual void Vfn02c();
    virtual void Vfn02d();
    virtual void Vfn02e();
    virtual void Vfn02f();
    virtual void Vfn030();
    virtual void Vfn031();
    virtual void Vfn032();
    virtual void Vfn033();
    virtual void Vfn034();
    virtual void Vfn035();
    virtual void Vfn036();
    virtual void Vfn037();
    virtual void Vfn038();
    virtual void Vfn039();
    virtual void Vfn03a();
    virtual void Vfn03b();
    virtual void Vfn03c();
    virtual void Vfn03d();
    virtual void Vfn03e();
    virtual void Vfn03f();
    virtual void Vfn040();
    virtual void Vfn041();
    virtual void Vfn042();
    virtual void Vfn043();
    virtual void Vfn044();
    virtual void Vfn045();
    virtual void Vfn046();
    virtual void Vfn047();
    virtual void Vfn048();
    virtual void Vfn049();
    virtual void Vfn04a();
    virtual void Vfn04b();
    virtual void Vfn04c();
    virtual void Vfn04d();
    virtual void Vfn04e();
    virtual void Vfn04f();
    virtual void Vfn050();
    virtual void Vfn051();
    virtual void Vfn052();
    virtual void Vfn053();
    virtual void Vfn054();
    virtual void Vfn055();
    virtual void Vfn056();
    virtual void Vfn057();
    virtual void Vfn058();
    virtual void Vfn059();
    virtual void Vfn05a();
    virtual void Vfn05b();
    virtual void Vfn05c();
    virtual void Vfn05d();
    virtual void Vfn05e();
    virtual void Vfn05f();
    virtual void Vfn060();
    virtual void Vfn061();
    virtual void Vfn062();
    virtual void Vfn063();
    virtual void Vfn064();
    virtual void Vfn065();
    virtual void Vfn066();
    virtual void Vfn067();
    virtual void Vfn068();
    virtual void Vfn069();
    virtual void Vfn06a();
    virtual void Vfn06b();
    virtual void Vfn06c();
    virtual void Vfn06d();
    virtual void Vfn06e();
    virtual void Vfn06f();
    virtual void Vfn070();
    virtual void Vfn071();
    virtual void Vfn072();
    virtual void Vfn073();
    virtual void Vfn074();
    virtual void Vfn075();
    virtual void Vfn076();
    virtual void Vfn077();
    virtual void Vfn078();
    virtual void Vfn079();
    virtual void Vfn07a();
    virtual void Vfn07b();
    virtual void Vfn07c();
    virtual NiPoint3* GetPos();

};

struct EffectTarget
{
};

struct bhkSphereShape
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;


    bhkSphereShape(float fRadius, bool bFlag);
    virtual ~bhkSphereShape();
};

struct CollisionFilterInfo
{
    unsigned int m_uiFilterInfo;

    CollisionFilterInfo(int iLayer, int iSystemGroup, int iPart);
    operator unsigned int() const;
};

struct BoundingVolumeData
{
    unsigned int m_kMinimumCorner[3];
    unsigned char m_ucExpansionMin[3];
    unsigned char m_ucExpansionShift;
    unsigned int m_kMaximumCorner[3];
    unsigned char m_ucExpansionMax[3];
    unsigned char m_reserved;
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    void* m_pChildShapeAabbs;
    void* m_pChildShapeKeys;

};

struct __declspec(align(16)) Collidable
{
    unsigned int m_uiFilterInfo;
    void* m_pShape;
    void* m_pMotionState;
    void* m_parent;
    char m_iOwnerOffset;
    char m_uiForceCollideOntoPpu;
    short m_uiShapeSizeOnSpu;
    unsigned int m_broadPhaseId;
    char m_cBroadPhaseType;
    char m_broadPhaseOwnerOffset;
    char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
    BoundingVolumeData m_kBoundingVolumeData;
    float m_fAllowedPenetrationDepth;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;

    Collidable();
    ~Collidable();
};

struct ShapePhantom
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;

    ShapePhantom(const void* pkCollidable);
    ~ShapePhantom();
};

struct __declspec(align(16)) CdPointCollector
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

    CdPointCollector();
    ~CdPointCollector();
};

struct __declspec(align(16)) LinearCastInput
{
    hkVector4 m_vTo;
    float m_fMaxExtraPenetration;
    float m_fStartPointTolerance;
    int unk18;
    int unk1c;

    LinearCastInput();
};

struct PickFilter
{
    unsigned int m_uiFilter;

    PickFilter(int iValue);
};

struct RayCastOutput
{
    hkVector4 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    void* m_pRootCollidable;
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

};

struct __declspec(align(16)) PickData
{
    hkVector4 m_kFrom;
    hkVector4 m_kTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    RayCastOutput m_kOutput;

    PickData();
    void SetFilter(PickFilter kFilter);
};

struct TES
{
};



// @fnv 0x00828f00
bool SummonCreatureEffectHelper::FUN_00828f00(int iUnused, NiPoint3* pkPos)
{
    MobileObject* pkActor = ((::EffectTarget *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::MobileObject *)(reinterpret_cast<::MagicTarget *>((((::EffectTarget *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    TESBoundObject* pkBound = dynamic_cast<TESBoundObject*>(GetBaseForm());
    float fRadius = reinterpret_cast<::fnv_0050ebf0::FUN_0050ebf0_shell *>((pkBound))->FUN_0050ebf0();
    if (64.0 > fRadius)
        fRadius = 64.0f;

    bhkSphereShape* pkShape = new bhkSphereShape(fRadius * 0.5, true);
    CollisionFilterInfo kFilter(0x26, 0, 0);
    Collidable kCollidable;
    kCollidable.m_uiFilterInfo = kFilter;
    kCollidable.m_pShape = ((void *)(::FUN_004ae750((void *)(pkShape))));
    reinterpret_cast<::FUN_0056e120_shell *>(&(kCollidable.m_kBoundingVolumeData))->FUN_0056e120();
    ShapePhantom kPhantom(&kCollidable);
    if (((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pkActor))->GetTarget())))
        reinterpret_cast<::Obj *>(&(kPhantom))->FUN_00c85810((::Obj *)(::bhkWorld *)(((::bhkWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pkActor))->GetTarget()))))->FUN_004543c0()))));

    hkVector4 kFrom;
    CdPointCollector kStartCollector;
    CdPointCollector kCastCollector;
    LinearCastInput kInput;
    ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(kFrom), (const ::fnv_004a3e00::NiPoint3 &)((const ::NiPoint3 &)(*pkPos + NiPoint3(0.0f, 0.0f, fRadius * 0.5 + 10.0))));
    ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(kInput.m_vTo), (const ::fnv_004a3e00::NiPoint3 &)((const ::NiPoint3 &)(*pkPos + NiPoint3(0.0f, 0.0f, fRadius * 0.5 + 10.0))));
    reinterpret_cast<::ScriptX *>(&(kPhantom))->InvokeInterfaceCall((int)&(kFrom), (int)(&kInput), (int)(&kCastCollector), (int)(&kStartCollector));
    ::hkBool startHit;
    reinterpret_cast<::Hld621210 *>(&(kStartCollector))->FUN_00621210((::Rcv621210 *)&startHit);
    if (reinterpret_cast<::FUN_005609f0_shell *>(&startHit)->FUN_005609f0())
    {
        reinterpret_cast<::FUN_00c9f420_Class *>(&(kPhantom))->FUN_00c9f420();
        delete pkShape;
        return false;
    }

    reinterpret_cast<::FUN_00c9f420_Class *>(&(kPhantom))->FUN_00c9f420();
    delete pkShape;
    if (reinterpret_cast<::FUN_0057b0a0_shell *>((pkActor))->FUN_0057b0a0() > pkActor->GetPos()->z)
        return false;

    PickData kPick;
    PickFilter kPickFilter(0);
    reinterpret_cast<::FUN_004a39f0_shell *>(&(kPickFilter))->FUN_004a39f0(0x26);
    kPick.SetFilter(kPickFilter);
    NiPoint3 kStart = *pkActor->GetPos();
    kStart.z += 64.0;
    NiPoint3 kEnd = *pkPos;
    kEnd.z += 64.0;
    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(kPick))->FUN_004a3da0((void *)&(kStart));
    reinterpret_cast<::FUN_004a3eb0_shell *>(&(kPick))->FUN_004a3eb0((void *)&(kEnd));
    reinterpret_cast<::FUN_00458420_cls *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00458420((int)&(kPick));
    ::hkBool pickHit;
    reinterpret_cast<::CalleeObj *>(&(kPick.m_kOutput))->FUN_005c53f0((::CalleeObj *)&pickHit);
    if (reinterpret_cast<::FUN_005609f0_shell *>(&pickHit)->FUN_005609f0())
        return false;

    return true;
}
#include "generated/data/fallout/magic/summoncreatureeffect.inc"
