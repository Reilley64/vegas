
// src/fallout/magic/valueandconditionseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/valueandconditionseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/active_effect_fields.h"
#include "fnv/decl/ActiveEffectLoader.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
struct ActiveEffect
{
};

struct TESSaveLoadGame
{
};


struct FUN_0082b780_shell : ActiveEffect
{
    void FUN_0082b780(void* buffer);
    char pad01[0x48];
    unsigned char unk48;
    char pad49[0x2];
};

// @fnv 0x0082b780
void FUN_0082b780_shell::FUN_0082b780(void* buffer)
{
    reinterpret_cast<::ActiveEffectLoader *>(this)->FUN_00805330((::Actor *)(buffer));
    reinterpret_cast<::FUN_008579e0_shell *>((g_TESSaveLoadGame))->FUN_008579e0((void*)(&this->unk48), 1);
}

class ActiveEffect;
class Actor;
namespace ActorValue { enum Index; }
struct ValueModifierEffect
{
    ValueModifierEffect(void*, void*, void*);
public:
    void CopyData(::ActiveEffect *);
public:
    void ApplyActorValueModifier(::Actor *, float, ::ActorValue::Index);
};
extern int DAT_0107c5dc;
struct ValueAndConditionsEffectFields : ValueModifierEffectFields
{
    int unk4c;
};

struct FUN_0082b7b0 : ValueModifierEffect
{
    FUN_0082b7b0(void*, void*, void*);
};
// Initialises a ValueModifierEffect via its base constructor, sets the vtable pointer to DAT_0107c5dc and sets the int after the ValueModifierEffect members to -1.
// @fnv 0x0082b7b0
FUN_0082b7b0::FUN_0082b7b0(void* a, void* b, void* c) : ValueModifierEffect(a, b, c)
{
    *(void**)this = (void*)&DAT_0107c5dc;
    reinterpret_cast<ValueAndConditionsEffectFields*>(this)->unk4c = -1;
}

struct Actor;
namespace ActorValue {
enum Index
{
    kActorValueNone = -1,
    kActorValueHealth = 25,
    kActorValueMaxHealth = 24
};
}
struct Setting_S
{
};
struct ValueModifierEffectHelper
{
};
struct FUN_0082b970_shell : ValueModifierEffect
{
    ActorValue::Index m_eModifiedActorValue;
    void ApplyValueModifier(Actor* actor, float modifier, ActorValue::Index index);
    unsigned int pad04[0x12];
    int unk4c;
};
// Applies the modifier to the stored actor value (or none) and, scaled by a runtime setting, to kActorValueNone or actor values 25-31.
// @fnv 0x0082b970
void FUN_0082b970_shell::ApplyValueModifier(Actor* actor, float modifier, ActorValue::Index index)
{
    if (*reinterpret_cast<ActorValue::Index*>(&this->unk4c) != ActorValue::kActorValueNone)
    {
        float fScaledMagnitude = modifier * ((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1213))))))[0];
        reinterpret_cast<::ValueModifierEffect *>((reinterpret_cast<ValueModifierEffectHelper*>(this)))->ApplyActorValueModifier(
            actor, modifier, *reinterpret_cast<ActorValue::Index*>(&this->unk4c));
        reinterpret_cast<::ValueModifierEffect *>((reinterpret_cast<ValueModifierEffectHelper*>(this)))->ApplyActorValueModifier(actor, fScaledMagnitude,
                                                                                    ActorValue::kActorValueNone);
    }
    else
    {
        reinterpret_cast<::ValueModifierEffect *>((reinterpret_cast<ValueModifierEffectHelper*>(this)))->ApplyActorValueModifier(actor, modifier,
                                                                                    ActorValue::kActorValueNone);
        float fScaledMagnitude = modifier * ((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting1214))))))[0];
        for (int i = 25; i < 32; ++i)
            reinterpret_cast<::ValueModifierEffect *>((reinterpret_cast<ValueModifierEffectHelper*>(this)))->ApplyActorValueModifier(actor, fScaledMagnitude,
                                                                                        (ActorValue::Index)i);
    }
}

struct FUN_0082b8a0_cls
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
    int m_4c;
    void CopyToSpawnedRecord(void* p);
};

extern int DAT_011a13d0;
void* __cdecl CreateSpawnedRecord(void* p, int a2, void* a3, void* a4, int a5);

// Calls FUN_0082bbe0 on p, creates a spawned record via CreateSpawnedRecord, and copies m_4c into its m_4c field if non-null.
// @fnv 0x0082b8a0
void FUN_0082b8a0_cls::CopyToSpawnedRecord(void* p)
{
    reinterpret_cast<::ValueModifierEffect *>(this)->CopyData((::ActiveEffect *)(p));
    FUN_0082b8a0_cls* r = (FUN_0082b8a0_cls*)CreateSpawnedRecord(p, 0, &(*reinterpret_cast<int *>(&::DAT_011a0d1c)), &DAT_011a13d0, 0);
    if (r != 0)
    {
        r->m_4c = m_4c;
    }
}


struct ValueModifier_b9743
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
    ValueModifier_b9743(void* a, void* b, void* c);
};

// Allocates and constructs a ValueModifier_b9743 from the three given arguments, returning the new object.
// @fnv 0x0082b8f0
ValueModifier_b9743* CreateValueModifier(void* a, void* b, void* c)
{
    return new ValueModifier_b9743(a, b, c);
}

struct SizedEffect : FUN_0082b7b0
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
    __forceinline SizedEffect(void* target, void* value, void* other) : FUN_0082b7b0(target, value, other)
    {}
};
class FUN_0082b7f0_Owner
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44(void* value);
    void* field04;
    void* field08;
    void* field0c;
    void* field10;
    void* field14;
    void* field18;
    void* field1c;
    void* field20;
    void* field24;
    void* field28;
    FUN_0082b7b0* CreateEffect();
};
// Allocates a SizedEffect from field28, field08 and field0c, passes it to v44, and returns it.
// @fnv 0x0082b7f0
FUN_0082b7b0* FUN_0082b7f0_Owner::CreateEffect()
{
    FUN_0082b7b0* effect = new SizedEffect(field28, field08, field0c);
    v44(effect);
    return effect;
}
