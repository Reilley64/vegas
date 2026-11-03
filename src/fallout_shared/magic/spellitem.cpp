// fallout_shared/magic/spellitem.cpp: SpellItem, MagicItem (15 functions)

#include "fnv/decl/ActorValueOwner.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S_004063e0.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_01183000.h"
#include "spellitem_decls.h"

// Resets spellType, cost, level and flags to 0, -1, 0 and 0.
// @fnv 0x0040e330
void SpellItem::ResetFormData()
{
    spellType = 0;
    cost = -1;
    level = 0;
    flags = 0;
}

// @fnv 0x0040e280
int FUN_0040e280(int thisPtr)
{
    return 0x54495053;
}

struct FUN_0040e500_shell
{
    void SetValue(std::intptr_t value);
};

// @fnv 0x0040e500
void FUN_0040e500_shell::SetValue(std::intptr_t value)
{
    *reinterpret_cast<int*>(this + 0x38) = value;
}


struct FUN_0040e290_shell
{
    void FUN_0040e2c0();
    void* DestroyIfFlagged(unsigned int flags);
};

struct FlaggedData
{
    int ContainsAnyFlag(unsigned int);
};

struct FUN_0040e670_shell
{
    void FUN_0040e670();
};

// @fnv 0x0040e670
void FUN_0040e670_shell::FUN_0040e670()
{
    ((FlaggedData*)((char*)this - 0x18))->ContainsAnyFlag(0x40);
}

struct Base5a
{
    virtual ~Base5a();
    char _pad[20];
};
struct IngredientItem
{
    virtual ~IngredientItem();
};
struct FUN_00409210
{
    Base5a _a;
    IngredientItem _b;
    ~FUN_00409210();
};
// Destructor for the object holding a Base5a and an IngredientItem; the body is empty.
// @fnv 0x00409210
FUN_00409210::~FUN_00409210()
{}

struct FUN_0040e1e0_shell
{
    bool FUN_0040e1e0();
};
// Returns true when the object at this-0x18 reports false for the argument 1.
// @fnv 0x0040e1e0
bool FUN_0040e1e0_shell::FUN_0040e1e0()
{
    return !(unsigned char)((FlaggedData*)((char*)this - 0x18))->ContainsAnyFlag(1);
}

struct FUN_0040e650_shell : FlaggedData
{
    void FUN_0040e650();
};
// @fnv 0x0040e650
void FUN_0040e650_shell::FUN_0040e650()
{
    ((FlaggedData*)((char*)this - 0x18))->ContainsAnyFlag(0x20);
}

class TESForm40E
{
  public:
    virtual ~TESForm40E();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class TESFullName40E
{
  public:
    virtual ~TESFullName40E();

    int unk04;
    int unk08;
};

class MagicItem40E
{
  public:
    virtual ~MagicItem40E();

    int unk04;
    int unk08;
};

class MagicItemForm40E : public TESForm40E, public TESFullName40E, public MagicItem40E
{
  public:
    MagicItemForm40E();
    virtual ~MagicItemForm40E();
};

class FUN_0040e160 : public MagicItemForm40E
{
  public:
    FUN_0040e160();
    virtual ~FUN_0040e160();

};

// Sets the form type to 0x14 and calls InitItem to initialize the magic item form.
// @fnv 0x0040e160
FUN_0040e160::FUN_0040e160()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x14);
    reinterpret_cast<::SpellItem *>(this)->ResetFormData();
}

// Secondary-interface override: the speaker sound when the info is flagged, otherwise a sound picked
// from the interface's own value.

class E600Sound;


class E600Info
{
  public:
    virtual ~E600Info();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

class E600SoundSource
{
  public:
    virtual void Unk_00();
    virtual E600Sound* FUN_0040e600();
    virtual float GetValue(int iIndex);
};

class E600TopicInfo : public E600Info, public E600SoundSource
{
  public:
    virtual E600Sound* FUN_0040e600();
};

// Returns the speaker sound if flag 1 is set, otherwise picks a sound from the value at index 0.
// @fnv 0x0040e600
E600Sound* E600TopicInfo::FUN_0040e600()
{
    if (((bool)(reinterpret_cast<::FlaggedData *>(this)->ContainsAnyFlag(1))))
        return ((::E600Sound *)(reinterpret_cast<::Twin_00639b40 *>(this)->GetEntryPoint()));
    else
        return ((::E600Sound *)(std::uintptr_t)(::GetBandIndex(GetValue(0))));
}

class FormPart40E
{
  public:
    virtual ~FormPart40E();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class NamePart40E
{
  public:
    virtual void GetName();

    int unk04;
    int unk08;
};

class EffectPart40E
{
  public:
    virtual void GetEffects();

    int unk04;
};

class MagicItemObject40E : public FormPart40E, public NamePart40E, public EffectPart40E
{
  public:
    virtual ~MagicItemObject40E();

};

class FUN_0040e2c0 : public MagicItemObject40E
{
  public:
    virtual ~FUN_0040e2c0();
};
// Calls FUN_0040e2c0, frees this via _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0040e290
void* FUN_0040e290_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0040e2c0 *>(this)->FUN_0040e2c0::~FUN_0040e2c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0040e2c0
FUN_0040e2c0::~FUN_0040e2c0()
{
    reinterpret_cast<::SpellItem *>(this)->ClearData();
}

struct TESForm
{
    virtual ~TESForm();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct MagicBase
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual std::intptr_t s6();
    virtual bool FUN_0040e3c0(class MagicItem* p);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

class MagicItem : public TESForm, public MagicBase
{
  public:
    unsigned char m_40;
    bool FUN_0040e3c0(MagicItem* p);
};

// Casts p to SpellItem and returns true if it is null or differs from this item in s6, GetA, GetB or m_40; otherwise false.
// @fnv 0x0040e3c0
bool MagicItem::FUN_0040e3c0(MagicItem* apItem)
{
    MagicItem* a = reinterpret_cast<MagicItem*>(dynamic_cast<SpellItem*>(apItem));
    if (a == 0)
    {
        return true;
    }
    if (a->s6() != s6() || ::GetField38((char *)(a)) != ::GetField38((char *)this) || ((std::intptr_t)(reinterpret_cast<::Twin_00639b40 *>((a))->GetEntryPoint())) != ((int)(std::uintptr_t)(reinterpret_cast<::Twin_00639b40 *>(this)->GetEntryPoint())) || a->m_40 != m_40)
    {
        return true;
    }
    return false;
}

struct SubE360
{
};
struct PadE360
{
    virtual void f00();
};
struct IfaceE360
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
    virtual int GetValue();
    virtual void FUN_0040e360();
};
struct ObjE360 : PadE360, IfaceE360
{
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SubE360 m_sub;
    virtual void FUN_0040e360();
};
// @fnv 0x0040e360
void ObjE360::FUN_0040e360()
{
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::Class005a6b10 *>(&(m_sub))->FUN_005a6b10();
    ::AppendChunk(GetValue(), &m_sub, 0x10);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::Class005a6b10 *>(&(m_sub))->FUN_005a6b10();
}

struct Actor;
struct MagicEffectKind
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int GetType();
};
struct SpellData
{
};
struct ActorValues
{
};
struct FUN_0040e520_shell
{
    float FUN_0040e520(Actor* caster);
};
// @fnv 0x0040e520
float FUN_0040e520_shell::FUN_0040e520(Actor* caster)
{
    float cost = 0.0f;
    Actor* effectiveCaster = (((MagicEffectKind*)((char*)this - 12))->GetType() == 2 ||
                              ((MagicEffectKind*)((char*)this - 12))->GetType() == 3)
                                 ? 0
                                 : caster;
    if (((bool)(reinterpret_cast<::FlaggedData *>((((SpellData*)((char*)this - 36))))->ContainsAnyFlag(1))))
    {
        cost = (float)::GetField38((char *)(((SpellData*)((char*)this - 36))));
        if (effectiveCaster)
        {
            cost =
                ::ScaleBySettingBlend(cost, reinterpret_cast<::ActorValueOwner *>((((ActorValues*)((char*)effectiveCaster + 0xa4))))->GetActorValueAsInteger((::ActorValue::Index)(::FUN_004065e0((::EffectItemList_shell *)this))));
        }
    }
    else
    {
        cost = reinterpret_cast<::S_004063e0 *>(this)->GetTotalCost(effectiveCaster);
    }
    return cost;
}

extern "C" void* __cdecl _FNV_DynamicCast(void*, int, void*, void*, int);
class TESActorBase;
class TESTopicInfo
{
  public:
};
struct SpeakerSink40E
{
};

struct CopySource40E : TESForm, MagicBase
{
    unsigned char flags;
};
struct CopyOwner40E;
struct CopyPart40E
{
    virtual void slot0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    unsigned char flags;
    virtual void FUN_0040e470(MagicItem* input);
};
struct CopyOwner40E : TESForm, CopyPart40E
{
    virtual void FUN_0040e470(MagicItem* input);
};
// Passes source values to setters, assigns the value returned by GetSpeaker, and copies the source flags.
// @fnv 0x0040e470
void CopyOwner40E::FUN_0040e470(MagicItem* apSource)
{
    CopySource40E* source = static_cast<CopySource40E*>(_FNV_DynamicCast(apSource, 0, &(*reinterpret_cast<char *>(&::DAT_01183140)), &(*reinterpret_cast<char *>(&::DAT_01183060)), 0));
    if (source == 0)
        return;
    reinterpret_cast<::LowProcess *>(this)->SetCurrentBoundObject((::TESBoundObject *)(source->s6()));
    reinterpret_cast<FUN_0040e500_shell*>(this)->SetValue(::GetField38((char *)(source)));
    reinterpret_cast<::FUN_00409480_shell *>((reinterpret_cast<SpeakerSink40E*>(this)))->FUN_00409480(((::TESActorBase *)(reinterpret_cast<::Twin_00639b40 *>((reinterpret_cast<TESTopicInfo*>(source)))->GetEntryPoint())));
    flags = source->flags;
}
