
// src/fallout/magic/disintegratearmoreffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/disintegratearmoreffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/active_effect_fields.h"
#include "fnv/decl/ActiveEffect.h"
#include "fnv/decl/ActiveEffectLoader.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/EffectSaveShell.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/FUN_004be2d0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00804f80_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FakeActor.h"
#include "fnv/decl/MagicTarget.h"
#include "fnv/decl/TESBipedModelForm.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_005b6000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_011de000.h"
struct DisintegrateArmorEffect
{
    void FUN_0080d210();
    void* Destroy(unsigned int flags);
};

namespace fnv_0080d4f0 {
struct Actor;
struct ActiveEffect
{
};
struct TESSaveLoadGame
{
};

struct DisintegrateArmorEffect : ActiveEffect
{
    unsigned short FUN_0080d4f0(Actor* actor);
};

// Returns the save size: the base ActiveEffect size plus 4 when the save version is at least 0x37.
// @fnv 0x0080d4f0
unsigned short DisintegrateArmorEffect::FUN_0080d4f0(Actor* actor)
{
    unsigned short size = 0;
    size += reinterpret_cast<::FUN_00804f80_shell *>(this)->FUN_00804f80((::Actor *)(actor));
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_0080d4f0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x37)
        size += 4;
    return size;
}
}  // namespace fnv_0080d4f0

struct Temp
{
    void* vtable;
    float value;
    unsigned int unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44, unk48;
    Temp(unsigned int, unsigned int, unsigned int);
};
struct Owner
{
    unsigned int unk00, unk04, arg08, arg0c, unk10, unk14, unk18, unk1c, unk20, unk24, arg28;
    Temp* CreateTemp();
};
// Allocates a Temp from arg28, arg08 and arg0c, passes it to FUN_00804090, and returns it.
// @fnv 0x0080d2a0
Temp* Owner::CreateTemp()
{
    Temp* p = new Temp(arg28, arg08, arg0c);
    reinterpret_cast<::ActiveEffect *>(this)->CopyData((::ActiveEffect *)(p));
    return p;
}

class Data80D
{
  public:
    ~Data80D();
};

class Base80D
{
  public:
    virtual ~Base80D();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44;
};

class FUN_0080d210 : public Base80D
{
  public:
    virtual ~FUN_0080d210();

    Data80D* m_pUserData;
};
// Calls FUN_0080d210, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x0080d1e0
void* DisintegrateArmorEffect::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_0080d210 *>(this)->FUN_0080d210::~FUN_0080d210();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that deletes the owned Data80D object if the pointer is non-null.
// @fnv 0x0080d210
FUN_0080d210::~FUN_0080d210()
{
    if (m_pUserData)
        delete m_pUserData;
}

struct TESBoundObject
{
    virtual void v0();
};
struct TESObjectARMO : TESBoundObject
{
    virtual void v1();
};
extern char DAT_01183108[];
extern char DAT_01183a34[];

struct GlobalMgr
{
};

struct Holder48
{
};

struct Sub70
{
};

struct FUN_0080d540_cls
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    unsigned int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    Holder48* m_48;

    void FUN_0080d540(uintptr_t arg);
};

// @fnv 0x0080d540
void FUN_0080d540_cls::FUN_0080d540(uintptr_t arg)
{
    unsigned int i2;
    TESObjectARMO* obj;
    int result;

    reinterpret_cast<::EffectSaveShell *>(this)->FUN_008050d0((::Actor *)(arg));
    if (reinterpret_cast<::FUN_008df040_shell *>((((GlobalMgr*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008df040() >= 0x37)
    {
        result = -1;
        if (m_48 != 0 && ((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((m_48))->GetName())) != 0)
        {
            obj = dynamic_cast<TESObjectARMO*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((m_48))->GetName())));
            if (obj != 0)
            {
                for (i2 = 0; i2 < 0x14; i2++)
                {
                    if (reinterpret_cast<::TESBipedModelForm *>((((Sub70*)((char*)obj + 0x70))))->HasBipedModel((::BIPED_OBJECT)(i2), 0, (::BGSBipedModelList *)(0)))
                    {
                        result = i2;
                        break;
                    }
                }
            }
        }
        reinterpret_cast<::FUN_008579b0_shell *>((((GlobalMgr*)(*reinterpret_cast<void * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0(&result, 4);
    }
}

namespace fnv_0080d610 {
struct Node;
struct Hub;
struct Effect;
struct Other;
struct Ctl
{
};
struct SysMgr
{
};
struct Node
{
};
struct Hub
{
};
struct Effect
{
};
struct Other
{
    void* Make(int one);
};


struct FUN_0080d610_cls
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44;
    void* unk48;
    void FUN_0080d610(Node* arg);
};

// @fnv 0x0080d610
void FUN_0080d610_cls::FUN_0080d610(Node* pNode)
{
    reinterpret_cast<::ActiveEffectLoader *>((reinterpret_cast<Ctl*>(this)))->FUN_00805330((::Actor *)(pNode));
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_0080d610::SysMgr * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x37)
    {
        int handle;
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0080d610::SysMgr * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&handle, 4);
        if (handle != -1)
        {
            Effect* fx = ((::fnv_0080d610::Effect *)(reinterpret_cast<::ExtraDataList *>((((::fnv_0080d610::Hub *)(reinterpret_cast<::FUN_005d43c0_ *>((pNode))->FUN_005d43c0()))))->GetContainerChangeData()));
            if (fx != 0)
            {
                unk48 = ((void *)(reinterpret_cast<::Target *>((fx))->FUN_004c8c10(handle, 1)));
            }
            void* obj;
            {
                void* cur = unk48;
                obj = cur;
            }
            obj != 0 ? reinterpret_cast<Other*>(obj)->Make(1) : 0;
        }
    }
}
}  // namespace fnv_0080d610

struct Sub
{
    int FUN_004459e0(int a);
};
struct Result
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void FUN_slot242(void* a, float b);
};
struct Node
{
};
struct FUN_0080d340_cls
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34,
        unk38, unk3c, unk40, unk44;
    Sub* m_48;
    void FUN_0080d340();
};

// @fnv 0x0080d340
void FUN_0080d340_cls::FUN_0080d340()
{
    Result* p;
    Sub* t;
    Sub* u;
    p = ((::Node *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::Result *)(reinterpret_cast<::MagicTarget *>((((::Node *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (p == 0)
        return;
    {
        this->m_48 = (Sub*)((::Sub *)(reinterpret_cast<::FakeActor *>((p))->FUN_0089d8b0(0)));
        if (this->m_48 != 0)
        {
            p->FUN_slot242((void*)this->m_48, ::GetFloatAtOffset1C((char *)(this)));
            if (((bool)(::FUN_005b6f70())))
            {
                ::FUN_00703c00("%s's %s takes %0.2f disintegrate armor damage!", (const char *)(reinterpret_cast<::FUN_0055d520_shell *>((p))->FUN_0055d520()));
            }
            t = this->m_48;
            u = t;
            (void)((u != 0) ? u->FUN_004459e0(1) : 0);
        }
    }
}
