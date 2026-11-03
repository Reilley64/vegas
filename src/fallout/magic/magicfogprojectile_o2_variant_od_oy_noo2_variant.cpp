
// src/fallout/magic/magicfogprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/magicfogprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/magicfogprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/magicfogprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/magicfogprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicfogprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/CellView.h"
#include "fnv/decl/FUN_00404420_shell.h"
#include "fnv/decl/FUN_004044d0_shell.h"
#include "fnv/decl/FUN_0081c470_shell.h"
#include "fnv/decl/FUN_0081c4a0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FogProjectileInit.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/PlayerMover.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/XRef.h"
#include "fnv/decl/fnv_00570f70__Obj570.h"
#include "fnv/decl/fnv_0080fb00__FUN_0080fb00_Class.h"
#include "fnv/decl/fnv_00819ca0__Actor.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/xActor_2.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_0080f000.h"
#include "fnv/symbols_0107a000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
struct xP3
{
    float x, y, z;
};
union __declspec(align(16)) xM128
{
    float m128_f32[4];
    char m128_i8[16];
};
struct __declspec(align(16)) xVec4
{
    xM128 m_vComponents;
    xVec4(float, float, float, float);
};
struct xSound
{
    xSound();
    ~xSound();
    xSound& operator=(const xSound&);
    int m_iWordAt00, m_iWordAt04, m_8;
};
struct xFltSetting
{
};
extern xFltSetting xg_11d1c28;
struct xItem
{
};
struct xRadius
{
};
struct xSndForm
{
};
struct xEffect
{
};
struct xCtl
{
};
struct xCell
{
};
struct xOwner
{
};
struct xA
{
    virtual void a0();
    virtual void FUN_00484b60(unsigned int);
    int m_iWordAt04, m_8, m_iThirdValue, m_10, m_14;
};
struct xB
{
    virtual void b0();
};
struct xBase : xA, xB
{
    xBase(int, int, int, int, xP3, xP3);
    ~xBase();
};
struct xActorV
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
    virtual void* FUN_2c();
};

struct xProj : xBase
{
    int m_pad1c[27];
    float m_88;
    int m_pad8c[7];
    float m_a8;
    float m_ac;
    float m_b0;
    int m_b4;
    float m_b8;
    xSound m_bc;
    int m_c8;
    xOwner* m_cc;
    xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner);
    xSound PlaySoundByFormID(void*, int, unsigned int, int);
};
// @fnv 0x00819360
xProj::xProj(int a, int b, int c, int d, xP3 kP1, xP3 kP2, void* apE, xOwner* apOwner) : xBase(a, b, c, d, kP1, kP2)
{
    m_ac = ::FUN_00404010((float)reinterpret_cast<::FUN_004044d0_shell *>((((::xItem *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()))))->FUN_004044d0(), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1147)))))));
    m_b0 = ::FUN_00404010((float)reinterpret_cast<::FUN_00404420_shell *>((((::xItem *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()))))->FUN_00404420(), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011d15c8)))))));
    m_88 = reinterpret_cast<::PathingRequest *>((((xRadius*)((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))->GetCenterRadius() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1140))))));
    m_b4 = 0;
    m_a8 = 0.0f;
    m_b8 = 1.0f;
    m_cc = 0;
    m_c8 = 0;
    if (apE)
        reinterpret_cast<::fnv_00570f70::Obj570 *>(this)->FUN_00570f70((int)(apE));
    else
        reinterpret_cast<::XRef *>(this)->FUN_0081e570(0);
    reinterpret_cast<::FogProjectileInit *>(this)->InitProjectileEffect();
    reinterpret_cast<::fnv_00819ca0::Actor *>(this)->FUN_00819ca0();
    xVec4 V(-::g_fInfinity_0107ad40, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::fnv_0080fb00::FUN_0080fb00_Class *>((((::xCtl *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_0080fb00((int)(&V));
    reinterpret_cast<::CellView *>((((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00548230((::RefView *)(void *)(this), false);
    if (((::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))))
    {
        void* NAME = ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))))))->FUN_0084e3a0()));
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(m_bc))->IsValid())
            reinterpret_cast<::SoundPlaybackHandle *>(&(m_bc))->Release();
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::xSound &)(m_bc))->operator=((const ::SoundPlaybackHandle &)((const ::xSound &)(PlaySoundByFormID(NAME, 1, 0x40000102, 1))));
        reinterpret_cast<::FUN_00ad89e0_shell *>(&(m_bc))->FUN_00ad89e0(1.0f);
    }
    if (apOwner)
    {
        reinterpret_cast<::FUN_0081c4a0_cls *>((apOwner))->FUN_0081c4a0((::VTableTarget116 *)(void *)(this));
        m_cc = apOwner;
        reinterpret_cast<::FUN_0081c470_shell *>((m_cc))->FUN_0081c470(false, m_ac);
    }
    reinterpret_cast<::xActor *>(this)->FUN_0081eba0();
    void* SHOOTER = ((::xActorV *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())) ? ((::xActorV *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags()))->FUN_2c() : 0;
    if (SHOOTER != (*reinterpret_cast<void * *>(&::_g_thePlayer)))
        ::FUN_0080fae0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::g_011d15f8)))))));
}
