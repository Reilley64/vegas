
// src/fallout/magic/magicboltprojectile_o2_variant_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy (unit src/fallout/magic/magicboltprojectile_o2_variant.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout/magic/magicboltprojectile_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/magic/magicboltprojectile.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.
// src/fallout/magic/magicboltprojectile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/magicboltprojectile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/Bolt.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_004610f0_Class.h"
#include "fnv/decl/FUN_0081c4a0_cls.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8f20_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/PlayerMover.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/fnv_00570f70__Obj570.h"
#include "fnv/decl/fnv_0080fb00__FUN_0080fb00_Class.h"
#include "fnv/decl/fnv_00813f30__Actor80F.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/decl/xActor_2.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0080f000.h"
#include "fnv/symbols_00811000.h"
#include "fnv/symbols_011ae000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
struct RefH
{
};
struct FUN_00811930_shell : RefH
{
    bool IsNotDeleted() const;
};
struct FUN_008133d0_shell
{
    void FUN_008133d0(int value);
};

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
extern const float xg_107a8b0;
struct xIntSetting
{
};
struct xPtr
{
    xPtr(int);
    ~xPtr();
    void FUN_0066b0d0(void*);
    void* m_p;
};
int xFUN_0081e440(void*);
struct xNodeA
{
};
struct xPC
{
};
struct xAudio
{
    struct xSound FUN_00ad73b0(void*, unsigned int);
};
struct xRefList
{
    void FUN_005ae3d0(void* const&);
};
struct xDH
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
    xPtr m_a8;
    int m_ac;
    int m_b0;
    xPtr m_b4;
    xPtr m_b8;
    xPtr m_bc;
    xPtr m_c0;
    int m_c4;
    xSound m_c8;
    float m_d4;
    xProj(xActorV* apA, int b, int c, int d, xP3 kP1, xP3 kP2);
};
// @fnv 0x00811980
xProj::xProj(xActorV* apA, int b, int c, int d, xP3 kP1, xP3 kP2)
    : xBase((int)apA, b, c, d, kP1, kP2), m_a8(0), m_b4(0), m_b8(0), m_bc(0), m_c0(0)
{
    ::FUN_00811e00(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::xIntSetting *>(&::g_011d16ec)))))));
    reinterpret_cast<::FUN_008133d0_shell *>(this)->FUN_008133d0(0);
    m_88 = reinterpret_cast<::PathingRequest *>((((xRadius*)((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))->GetCenterRadius() * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1140))))));
    m_b0 = 0;
    m_c4 = 0;
    m_d4 = 0.0f;
    if (apA->FUN_2c() == (*reinterpret_cast<void * *>(&::_g_thePlayer)) && ((::xNodeA *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::xPC * *>(&::_g_thePlayer))))->FUN_00950bb0(true))) &&
        !reinterpret_cast<::FUN_00456630_helper *>((((::xNodeA *)(reinterpret_cast<::FUN_00950bb0_shell *>(((*reinterpret_cast<::xPC * *>(&::_g_thePlayer))))->FUN_00950bb0(true)))))->FUN_00456610())
    {
        xP3 POS = *((::xP3 *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList()));
        POS.z = POS.z + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1193))))));
        reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)&(POS));
    }
    xPtr OLD(xFUN_0081e440(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))));
    OLD.FUN_0066b0d0(0);
    reinterpret_cast<::Bolt *>(this)->InitEffect();
    reinterpret_cast<::fnv_00570f70::Obj570 *>(this)->FUN_00570f70((int)(((void *)(::FUN_00559450((int *)&(m_b4))))));
    reinterpret_cast<::fnv_00813f30::Actor80F *>(this)->FUN_00813f30();
    xVec4 V(-xg_107a8b0, 0.0f, 0.0f, 0.0f);
    reinterpret_cast<::fnv_0080fb00::FUN_0080fb00_Class *>((((::xCtl *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>(this)->FUN_009306d0()))))->FUN_0080fb00((int)(&V));
    reinterpret_cast<::CellView *>((((::xCell *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()))))->FUN_00548230((::RefView *)(void *)(this), false);
    reinterpret_cast<::FUN_008133d0_shell *>(this)->FUN_008133d0(0);
    if (((::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))))))
    {
        void* NAME = ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::xSndForm *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((::xEffect *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))))))->FUN_0084e3a0()));
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(m_c8))->IsValid())
            reinterpret_cast<::SoundPlaybackHandle *>(&(m_c8))->Release();
        if (((void *)(::FUN_00559450((int *)&(m_c0)))))
        {
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::xSound &)(m_c8))->operator=((const ::SoundPlaybackHandle &)((const ::xSound &)(((::xAudio *)(::FUN_00453a70()))->FUN_00ad73b0(NAME, 0x102))));
            xP3 POS2 = *((::xP3 *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList()));
            reinterpret_cast<::FUN_00ad8b60_h *>(&(m_c8))->FUN_00ad8b60(POS2.x, POS2.y, POS2.z);
            reinterpret_cast<::FUN_00ad8f20_shell *>(&(m_c8))->FUN_00ad8f20((::NiAVObject *)(void *)(((void *)(::FUN_00559450((int *)&(m_c0))))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&(m_c8))->FUN_00ad8830(true);
        }
    }
    reinterpret_cast<::xActor *>(this)->FUN_0081eba0();
    void* SHOOTER = ((::xActorV *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags())) ? ((::xActorV *)(reinterpret_cast<::PlayerMover *>(this)->GetActorStateFlags()))->FUN_2c() : 0;
    if (SHOOTER != (*reinterpret_cast<void * *>(&::_g_thePlayer)))
        ::FUN_0080fae0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xFltSetting *>(&::originalRuntimeFloatSetting1188)))))));
    else
    {
        xRefList* LIST = ((::xRefList *)(reinterpret_cast<::FUN_004610f0_Class *>(&((*reinterpret_cast<::xDH *>(&::g_011e0e80))))->GetOffset70Ptr()));
        if (LIST)
            LIST->FUN_005ae3d0(this);
    }
}
