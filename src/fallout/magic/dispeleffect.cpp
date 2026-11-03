
// src/fallout/magic/dispeleffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/dispeleffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/MagicCaster.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00804210__ActiveEffectUpdateShell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_011d1000.h"
struct ActiveEffect
{
    void CopyData(ActiveEffect*);
};

struct DispelEffect : ActiveEffect
{
    void FUN_00829b90(ActiveEffect*);
};

// @fnv 0x00829b90
void DispelEffect::FUN_00829b90(ActiveEffect* apDestination)
{
    ActiveEffect::CopyData(apDestination);
}

struct MagicTarget
{
    virtual ~MagicTarget()
    {}
};
struct Character : MagicTarget
{
};
struct FUN_0082d060_shell
{
    bool IsCharacter(MagicTarget* apTarget);
};
// Returns true if apTarget is a Character, using a dynamic_cast.
// @fnv 0x0082d060
bool FUN_0082d060_shell::IsCharacter(MagicTarget* apTarget)
{
    return dynamic_cast<Character*>(apTarget) != 0;
}


struct SpawnedEffect
{
    unsigned int unk00[18];
    SpawnedEffect(int a, int b, int c);
};

struct FUN_0080d950_cls
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
    virtual ActiveEffect* HookEffect(ActiveEffect* e);

    int unk04;
    int m_08;
    int m_0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_28;

    ActiveEffect* CreateAndHookEffect();
};

// Allocates a SpawnedEffect from m_28, m_08 and m_0C, hooks it via HookEffect, and returns it as an ActiveEffect.
// @fnv 0x0080d950
ActiveEffect* FUN_0080d950_cls::CreateAndHookEffect()
{
    ActiveEffect* e = (ActiveEffect*)new SpawnedEffect(m_28, m_08, m_0C);
    HookEffect(e);
    return e;
}

struct FUN_0080da00_cls;
struct ItemObj;

struct SubObj
{
    virtual void s0();
    virtual void s1();
    virtual float s2(void* p);
};

struct HolderObj
{
    virtual void h0();
    virtual void h1();
    virtual ItemObj* h2();
};

struct ItemObj
{
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual void i3();
    virtual void i4();
    virtual void i5();
    virtual int i6();
    int m_04;
    int m_08;
    SubObj m_0c;

    bool FUN_008256d0();
};

struct DatObj
{
};

struct FUN_0080da00_cls
{

    void UpdateItems();
};

// @fnv 0x0080da00
void FUN_0080da00_cls::UpdateItems()
{
    ItemObj* cur = ((::HolderObj *)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))->h2();
    bool b9 = ((::FUN_0080da00_cls *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::FUN_0080da00_cls *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->FUN_0084e3a0())) == 0;
    ItemObj* x = ((::ItemObj *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())) ? ((::ItemObj *)(reinterpret_cast<::MagicCaster *>((((::ItemObj *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60()))))->GetCasterActor())) : 0;
    while (cur != 0 && !cur->FUN_008256d0())
    {
        ItemObj* t5 = *((::ItemObj **)(&reinterpret_cast<::SimpleListNodeView*>(cur)->m_item));
        ItemObj* nextItem = ((::ItemObj *)(reinterpret_cast<::Callees *>((cur))->FUN_00726070()));
        if (t5 != 0 && (void*)t5 != (void*)this)
        {
            ItemObj* u2 = ((::ItemObj *)(reinterpret_cast<::Twin_0044ddc0 *>((t5))->GetName()));
            if (u2->i6() == 0)
            {
                if (u2->m_0c.s2(b9 ? x : 0) <= ::GetFloatAtOffset1C((char *)this) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::DatObj *>(&::originalRuntimeFloatSetting1184)))))))
                    reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>((t5))->FUN_00804210(0);
            }
        }
        cur = nextItem;
    }
}
