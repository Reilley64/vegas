
// src/fallout/magic/telekinesiseffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/telekinesiseffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/C857A10Buffer.h"
#include "fnv/decl/Cls.h"
#include "fnv/decl/FUN_00407820_shell.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_00802d90_shell.h"
#include "fnv/decl/FUN_0082c000_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00857aa0.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_0089f4e0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/FUN_00b4dec0_shell.h"
#include "fnv/decl/GrabHost.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/LoadedValueEffect.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/TurnUndeadEffect.h"
#include "fnv/decl/ValueModifierEffect_LoadGame_Helper.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00804210__ActiveEffectUpdateShell.h"
#include "fnv/decl/fnv_008aff80__ActorStub.h"
#include "fnv/decl/fnv_00960520__Projectile.h"
#include "fnv/decl/fnv_00961280__FUN_00961280_shell.h"
#include "fnv/decl/fnv_00974a50__FUN_00974a50_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00807000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01022000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/decl/B8182D0Object.h"
#include "fnv/decl/FUN_00439f50_class.h"
#include "fnv/decl/FUN_00a59660_cls.h"
#include "fnv/decl/Owner5615.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/symbols_004a3000.h"
#include <xmmintrin.h>
struct FUN_0082a510_shell
{
    void FUN_0082a540();
    void* DestroyIfFlagged(unsigned int flags);
};


struct FUN_0082aab0_shell
{
    void SetField644(float value);
};

// @fnv 0x0082aab0
void FUN_0082aab0_shell::SetField644(float value)
{
    *(float*)((char*)this + 0x644) = value;
}

struct FUN_0082af40_shell
{
    float fTelekinesisStrength;  // +0x644
    float GetTelekinesisStrength();
};

// @fnv 0x0082af40
float FUN_0082af40_shell::GetTelekinesisStrength()
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x644);
}

struct Actor
{
};
struct Actor;
struct ValueModifierEffect
{
public:
    void FUN_00802db0(::Actor *);
public:
    void Update(float);
};
struct TelekinesisEffect : ValueModifierEffect
{
    unsigned short FUN_0082b190(Actor* apActor);
};
struct FUN_008df040_shell
{
    unsigned char FUN_008df040();
};

// Returns the effect's save size: base size from FUN_00802d90 plus 4, plus 8 more when the save version is at least 0x40.
// @fnv 0x0082b190
unsigned short TelekinesisEffect::FUN_0082b190(Actor* apActor)
{
    unsigned short uiSaveSize = 0;
    uiSaveSize += reinterpret_cast<::FUN_00802d90_shell *>(this)->FUN_00802d90(apActor);
    uiSaveSize += 4;
    if ((*reinterpret_cast<::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))->FUN_008df040() >= 0x40)
    {
        uiSaveSize += 4;
        uiSaveSize += 4;
    }
    return uiSaveSize;
}

namespace fnv_0082b290 {
struct Actor;
struct TESSaveLoadGame;

struct ValueModifierEffect
{
};

struct TESSaveLoadGame_shell
{
};


struct TelekinesisEffect : ValueModifierEffect
{
    void LoadFromSave(Actor* apActor);
};

// @fnv 0x0082b290
void TelekinesisEffect::LoadFromSave(Actor* apActor)
{
    reinterpret_cast<::ValueModifierEffect_LoadGame_Helper *>(this)->FUN_00802dd0((::Actor *)(apActor));
    unsigned int irefID;
    reinterpret_cast<::FUN_00857aa0 *>((((TESSaveLoadGame_shell*)(*reinterpret_cast<::fnv_0082b290::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->ValidateFormIDArray(&irefID, 4);
    *(unsigned int*)((char*)this + 0x58) = irefID;
    if (reinterpret_cast<::FUN_008df040_shell *>((((TESSaveLoadGame_shell*)(*reinterpret_cast<::fnv_0082b290::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_008df040() >= 0x40)
    {
        reinterpret_cast<::FUN_008579e0_shell *>((((TESSaveLoadGame_shell*)(*reinterpret_cast<::fnv_0082b290::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0((void*)((char*)this + 0x50), 4);
        reinterpret_cast<::FUN_008579e0_shell *>((((TESSaveLoadGame_shell*)(*reinterpret_cast<::fnv_0082b290::TESSaveLoadGame * *>(&::g_TESSaveLoadGame)))))->FUN_008579e0((void*)((char*)this + 0x54), 4);
    }
}
}  // namespace fnv_0082b290

struct FUN_0082a670_shell
{
    void FUN_0082a670();
};


struct Flt
{
    operator unsigned int();
};

struct FUN_0082aa90_shell
{
    unsigned int GetFloatAsUInt();
};

// @fnv 0x0082aa90
unsigned int FUN_0082aa90_shell::GetFloatAsUInt()
{
    return ((Flt*)((char*)this + 0x634))->operator unsigned int();
}


struct FUN_0082aeb0_shell
{
    void* FUN_0082aeb0();
};

struct GO
{
    ~GO();
};
struct FUN_0080d930
{
    ~FUN_0080d930();
};
struct FUN_0082a540 : FUN_0080d930
{
    char _pad[0x4C];
    GO _go;
    ~FUN_0082a540();
};
// Calls FUN_0082a540, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0082a510
void* FUN_0082a510_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0082a540 *>(this)->FUN_0082a540::~FUN_0082a540();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor for FUN_0082a540; destroys its GO member and the FUN_0080d930 base.
// @fnv 0x0082a540
FUN_0082a540::~FUN_0082a540()
{}

struct ScriptLocalsX
{
};
struct Calendar
{
};
struct FUN_0082aee0_shell
{
    unsigned int FUN_0082aee0();
};
// Calls FUN_0082aee0 and passes its result to FUN_004b5a80, returning that value.
// @fnv 0x0082aeb0
void* FUN_0082aeb0_shell::FUN_0082aeb0()
{
    void* result = ((void *)(reinterpret_cast<::FUN_0082aee0_shell *>(this)->FUN_0082aee0()));
    return FUN_004b5a80(result);
}
// @fnv 0x0082aee0
unsigned int FUN_0082aee0_shell::FUN_0082aee0()
{
    Calendar* calendar = reinterpret_cast<Calendar*>(((void *)(::FUN_004ae750((void *)((reinterpret_cast<ScriptLocalsX*>(this)))))));
    return calendar ? ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((calendar))->FUN_009611e0())) : 0;
}

struct FUN_0082af20_shell
{
    unsigned int GetField63C();
};
// @fnv 0x0082af20
unsigned int FUN_0082af20_shell::GetField63C()
{
    return *(unsigned int*)((char*)this + 0x63c);
}

struct TESChallenge
{
};
class EffectSetting;
struct ActiveEffect
{
public:
    ::EffectSetting *GetEffectSetting() const;
};
struct FUN_0082afa0_shell
{
};
struct FUN_0082c810_shell
{
};
struct FUN_00974a50_shell
{
};
struct FUN_0082af60_shell
{
    void FUN_0082af60();
};
class TelekinesisEffectT
{
  public:
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
    unsigned int unk4c;
    unsigned int unk50;
    float m_fHitDistance;
    unsigned int unk58;
    bool m_bHolding;

    void FUN_0082afa0();
};
// @fnv 0x0082af60
void FUN_0082af60_shell::FUN_0082af60()
{
    reinterpret_cast<::TelekinesisEffectT *>((((FUN_0082afa0_shell*)this)))->FUN_0082afa0();
    reinterpret_cast<::fnv_00974a50::FUN_00974a50_shell *>((((FUN_00974a50_shell*)(&(*reinterpret_cast<int *>(&::g_011e0e80))))))->FUN_00974a50((::TESObjectREFR *)(*(void**)((char*)this + 0x58)), ((void *)(reinterpret_cast<::FUN_00407820_shell *>((((::TESChallenge *)(((ActiveEffect*)this)->GetEffectSetting()))))->FUN_00407820())));
    reinterpret_cast<::Cls *>((((FUN_0082c810_shell*)this)))->ApplyEffect();
}

struct FUN_0082a460
{
    char buf[0x60];
    FUN_0082a460(int, int, int);
};
// Allocates and constructs a FUN_0082a460 object from x, y and z, returning the new instance.
// @fnv 0x0082b110
FUN_0082a460* __cdecl CreateFUN_0082a460(int x, int y, int z)
{
    return new FUN_0082a460(x, y, z);
}

struct FUN_0080dfd0_shell
{
};
struct TESSaveLoadGame
{
};
struct ref_0084e3a0_shell
{
};
struct FUN_0082b200_shell : FUN_0080dfd0_shell
{
    void SaveLoad(Actor* apActor);
};
// @fnv 0x0082b200
void FUN_0082b200_shell::SaveLoad(Actor* apActor)
{
    unsigned int irefID;
    reinterpret_cast<::ValueModifierEffect *>(this)->FUN_00802db0(apActor);
    irefID = 0;
    if (*(unsigned int*)((char*)this + 0x58))
        irefID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((ref_0084e3a0_shell*)*(unsigned int*)((char*)this + 0x58))))->FUN_0084e3a0()));
    reinterpret_cast<::C857A10Buffer *>((((TESSaveLoadGame*)(*reinterpret_cast<::FUN_008df040_shell * *>(&::g_TESSaveLoadGame)))))->FUN_00857a10((const unsigned int *)((int)&irefID), 4);
    if (reinterpret_cast<::FUN_008df040_shell *>((((TESSaveLoadGame*)(*reinterpret_cast<::FUN_008df040_shell * *>(&::g_TESSaveLoadGame)))))->FUN_008df040() >= 0x40)
    {
        reinterpret_cast<::FUN_008579b0_shell *>((((TESSaveLoadGame*)(*reinterpret_cast<::FUN_008df040_shell * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((char*)this + 0x50, 4);
        reinterpret_cast<::FUN_008579b0_shell *>((((TESSaveLoadGame*)(*reinterpret_cast<::FUN_008df040_shell * *>(&::g_TESSaveLoadGame)))))->FUN_008579b0((char*)this + 0x54, 4);
    }
}

struct TESObjectREFR
{
    virtual ~TESObjectREFR();
};
struct TESForm
{
    virtual ~TESForm();
};
struct InvisibilityEffect
{
};
struct FUN_0082b300_shell : InvisibilityEffect
{
    void FUN_0082b300(Actor* apActor);
};

struct FUN_0082a5a0_shell
{
    virtual void v00()
    {}
    virtual void v01()
    {}
    virtual void v02()
    {}
    virtual void v03()
    {}
    virtual void v04()
    {}
    virtual void v05()
    {}
    virtual void v06()
    {}
    virtual void v07()
    {}
    virtual void v08()
    {}
    virtual void v09()
    {}
    virtual void v10()
    {}
    virtual void v11()
    {}
    virtual void v12()
    {}
    virtual void v13()
    {}
    virtual void v14()
    {}
    virtual void v15()
    {}
    virtual void v16()
    {}
    virtual void CopyFrom(ActiveEffect* copy)
    {}
    ActiveEffect* CreateCopy();
};

// @fnv 0x0082a5a0
ActiveEffect* FUN_0082a5a0_shell::CreateCopy()
{
    ActiveEffect* copy = reinterpret_cast<ActiveEffect*>(
        new FUN_0082a460(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x28),
                         *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x08),
                         *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 0x0C)));

    CopyFrom(copy);
    return copy;
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3();
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3& operator*=(float);
public:
    unsigned char ReadFromFile(::FUN_00438fc0_file *);
    bool FUN_004390c0(const ::NiPoint3 &);
    ::NiPoint3 &Subtract(const ::NiPoint3 &);
    float GetLengthSquared();
    float ComputeMagnitude() const;
    ::NiPoint3 Cross(const ::NiPoint3 &) const;
    ::NiPoint3 CrossProduct(const ::NiPoint3 &) const;
    ::NiPoint3 *ScaleTo(::NiPoint3 *, float);
    char *FUN_00a59af0(const char *);
    ::NiPoint3 &FUN_00b2a1c0(const ::NiPoint3 &);
    static const ::NiPoint3 ZERO;
};
struct bhkFilter
{
    unsigned int value;
};
struct bhkWorldObject
{
    bhkFilter FUN_0043b4f0();
};
struct bhkCollisionObject
{
};
struct SceneObject
{
};
struct ReferenceForm
{
    int FUN_00401170();
};
struct TelekinesisReference
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
    virtual SceneObject* GetSceneObject();
};
struct MagicCaster
{
};
struct ShaderDefinition
{
};
struct EffectSettingX
{
};
struct TelekinesisStartEffect
{
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
    unsigned int unk4c;
    float magnitude;
    unsigned int unk54;
    TelekinesisReference* target;
    void StartTelekinesisEffect();
};
// Calls FUN_0082c000, stores the result of FUN_00703390 at offset 0x58, calls StartTelekinesisEffect, and clears the byte at offset 0x5d.
// @fnv 0x0082a670
void FUN_0082a670_shell::FUN_0082a670()
{
    reinterpret_cast<::FUN_0082c000_shell *>(this)->FUN_0082c000();
    *(void**)((char*)this + 0x58) = ::fnv_00703390::FUN_00703390();
    reinterpret_cast<::TelekinesisStartEffect *>(this)->StartTelekinesisEffect();
    *(char*)((char*)this + 0x5d) = 0;
}
// @fnv 0x0082b300
void FUN_0082b300_shell::FUN_0082b300(Actor* apActor)
{
    reinterpret_cast<::LoadedValueEffect *>(this)->FUN_0082cd10(apActor);
    TESObjectREFR* pRef = *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<unsigned char*>(this) + 0x58);
    if (pRef)
        *reinterpret_cast<TESObjectREFR**>(reinterpret_cast<unsigned char*>(this) + 0x58) =
            dynamic_cast<TESObjectREFR*>(::FUN_004839c0(reinterpret_cast<unsigned int>(pRef)));
    if (*reinterpret_cast<TESObjectREFR**>(reinterpret_cast<unsigned char*>(this) + 0x58))
        reinterpret_cast<::TelekinesisStartEffect *>(this)->StartTelekinesisEffect();
    *reinterpret_cast<unsigned char*>(reinterpret_cast<unsigned char*>(this) + 0x5d) = 1;
}
struct TelekinesisConstraint
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    TelekinesisConstraint(TelekinesisReference*, bhkWorldObject*, unsigned int);
};
struct NiRTTI
{
};
struct NiObject
{
};
struct PlayerCharacter
{
};
struct CasterPosition
{
};
struct LoadingState
{
};
struct ShaderEffect
{
    virtual ~ShaderEffect();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
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
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual bool Start();
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
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    ShaderEffect(TelekinesisReference*, ShaderDefinition*, float);
};
struct EffectManager
{
};

// Validates the target's collision object, creates a TelekinesisConstraint, applies the telekinesis effect to the player, and starts the effect shader.
// @fnv 0x0082a6a0
void TelekinesisStartEffect::StartTelekinesisEffect()
{
    if (!target || !reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())
    {
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(false);
        return;
    }
    switch (((::ReferenceForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((target))->FUN_007af430()))->FUN_00401170())
    {
    case 27:
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(false);
        return;
    }
    SceneObject* h = target->GetSceneObject();
    bhkCollisionObject* a = h ? ((::bhkCollisionObject *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(h)))) : 0;
    bhkWorldObject* i = a ? ((::bhkWorldObject *)(::fnv_006fa820::FUN_006fa820((const char *)(a)))) : 0;
    if (i)
        ::FUN_00807ac0(i);
    if (!i || (reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::bhkFilter &)(i->FUN_0043b4f0()))->FUN_0043b4d0() != 4 && reinterpret_cast<::FUN_0043b4d0_shell *>((void *)&(const ::bhkFilter &)(i->FUN_0043b4f0()))->FUN_0043b4d0() != 5))
    {
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(false);
        return;
    }
    void* p = ((void *)(::FUN_004ae750((void *)(i))));
    new TelekinesisConstraint(target, i, i->FUN_0043b4f0().value);
    NiObject* eb = ::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f9140)), (::NiObject *)(h));
    if (eb)
        reinterpret_cast<::FUN_00b4dec0_shell *>((eb))->FUN_00b4dec0(6);
    if (((::MagicCaster *)(reinterpret_cast<::FUN_0082aa90_shell *>((::_g_thePlayer))->GetFloatAsUInt())))
        reinterpret_cast<::fnv_00961280::FUN_00961280_shell *>((::_g_thePlayer))->FUN_00961280();
    if (!reinterpret_cast<::FUN_0047c850 *>((((LoadingState*)(*reinterpret_cast<::FUN_008df040_shell * *>(&::g_TESSaveLoadGame)))))->EvaluateCondition())
        magnitude = DAT_01022958;
    reinterpret_cast<::GrabHost *>((::_g_thePlayer))->FUN_0095f930((::GrabRef *)(target), 3, magnitude);
    NiPoint3 s;
    NiPoint3 f;
    reinterpret_cast<::fnv_008aff80::ActorStub *>((::_g_thePlayer))->GetCameraPosAndDir((::fnv_008aff80::Vec3 *)(::NiPoint3 *)(&s), (::fnv_008aff80::Vec3 *)(::NiPoint3 *)(&f), true);
    if (!reinterpret_cast<::FUN_0047c850 *>((((LoadingState*)(*reinterpret_cast<::FUN_008df040_shell * *>(&::g_TESSaveLoadGame)))))->EvaluateCondition())
    {
        NiPoint3 casterPosition;
        reinterpret_cast<::TurnUndeadEffect *>((((CasterPosition*)((::MagicCaster *)(reinterpret_cast<::FUN_0082aa90_shell *>((::_g_thePlayer))->GetFloatAsUInt())))))->ApplyTurnUndeadEffect((::MagicCaster *)(::NiPoint3 *)(&casterPosition));
        NiPoint3 p = casterPosition - s;
        magnitude = reinterpret_cast<::FUN_004b6190_shell *>((void *)&(f))->DotProduct((void *)&(p));
        reinterpret_cast<::FUN_0082aab0_shell *>((::_g_thePlayer))->SetField644(magnitude);
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::NiPoint3 &)(f))->FUN_00439180(magnitude);
    }
    if (((::ShaderDefinition *)(reinterpret_cast<::FUN_00407820_shell *>((((::EffectSettingX *)(reinterpret_cast<::ActiveEffect *>(this)->GetEffectSetting()))))->FUN_00407820())))
    {
        ShaderEffect* shader = new ShaderEffect(target, ((::ShaderDefinition *)(reinterpret_cast<::FUN_00407820_shell *>((((::EffectSettingX *)(reinterpret_cast<::ActiveEffect *>(this)->GetEffectSetting()))))->FUN_00407820())), DAT_01012054);
        if (shader->Start())
            reinterpret_cast<::FUN_00973fd0_cls *>((((EffectManager*)&(*reinterpret_cast<int *>(&::g_011e0e80)))))->FUN_00973fd0((::FnvArgObj *)(shader));
        else
            delete shader;
    }
}

struct World
{
};
struct Cell
{
};
struct Ref
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual Ref* GetReference();
};
struct Target
{
};
struct Player
{
};
struct Input
{
};
struct OS
{
};
struct Setting
{
};
struct Effect
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
    float strength;
    float velocity;
    Ref* target;
    bool released;
    bool skipCost;
    void UpdateGrabEffect(float delta);
};
// Advances the grab effect: checks the player's grab target and world, updates velocity/strength from input and settings, applies strength and charges cost.
// @fnv 0x0082aad0
void Effect::UpdateGrabEffect(float delta)
{
    reinterpret_cast<::ValueModifierEffect *>(this)->Update(delta);
    Target* grab = ((::Target *)(reinterpret_cast<::FUN_0082aa90_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetFloatAsUInt()));
    if (!reinterpret_cast<::FUN_0082aeb0_shell *>((grab))->FUN_0082aeb0())
    {
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(false);
        return;
    }
    World* casterWorld = ((::Ref *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60())) && ((::Cell *)(reinterpret_cast<::LowProcess *>((((::Ref *)(reinterpret_cast<::FUN_0089f4e0_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_0089f4e0()))))->GetTarget()))
                             ? ((::World *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>((((::Ref *)(reinterpret_cast<::FUN_0045cd60_shell *>(this)->FUN_0045cd60()))->GetReference()))->GetTarget()))))->FUN_004543c0()))
                             : 0;
    World* playerWorld = ((::Ref *)(reinterpret_cast<::FUN_0089f4e0_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_0089f4e0())) && ((::Cell *)(reinterpret_cast<::LowProcess *>((((::Ref *)(reinterpret_cast<::FUN_0089f4e0_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_0089f4e0()))))->GetTarget()))
                             ? ((::World *)(reinterpret_cast<::FUN_004543c0_cls *>((((::Cell *)(reinterpret_cast<::LowProcess *>((((::Ref *)(reinterpret_cast<::FUN_0089f4e0_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_0089f4e0()))))->GetTarget()))))->FUN_004543c0()))
                             : 0;
    if (!grab || target != ((::Ref *)(reinterpret_cast<::FUN_0089f4e0_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_0089f4e0())) || reinterpret_cast<::FUN_0082af20_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetField63C() != 3 ||
        casterWorld != playerWorld)
    {
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(false);
        return;
    }
    if (reinterpret_cast<::HotkeyWheelDisplay *>((((::Input *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OS * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(6, 0) && reinterpret_cast<::HotkeyWheelDisplay *>((((::Input *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OS * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(4, 0))
    {
        if (velocity >
            *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1168)))))) + *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1169)))))) * 0.1f)
            released = true;
        reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>(this)->FUN_00804210(false);
    }
    else if (reinterpret_cast<::HotkeyWheelDisplay *>((((::Input *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OS * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(4, 0))
    {
        if (velocity < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1168)))))))
            velocity = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1168))))));
        velocity += *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1169)))))) * delta;
        if (velocity > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1170)))))))
            velocity = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1170))))));
    }
    else if (reinterpret_cast<::HotkeyWheelDisplay *>((((::Input *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OS * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem(6, 0))
    {
        if (velocity > -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1168)))))))
            velocity = -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1168))))));
        velocity -= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1169)))))) * delta;
        if (velocity < -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1170)))))))
            velocity = -*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1170))))));
    }
    else
        velocity = 0.0f;
    strength = reinterpret_cast<::FUN_0082af40_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetTelekinesisStrength();
    strength += velocity * delta;
    if (strength < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1171)))))))
        strength = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1171))))));
    if (strength > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1112)))))) * ::GetFloatAtOffset1C((char *)this) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::g_011d18fc)))))))
        strength = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting1112)))))) * ::GetFloatAtOffset1C((char *)this) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::g_011d18fc))))));
    reinterpret_cast<::FUN_0082aab0_shell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->SetField644(strength);
    if (!skipCost)
        reinterpret_cast<::fnv_00960520::Projectile *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_00960520(delta);
    skipCost = false;
}

namespace fnv_b4214 {
class FUN_0082a460_base
{
  public:
    virtual ~FUN_0082a460_base();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;

    FUN_0082a460_base(int a, int b, int c);
};

class FUN_0082a460_member
{
  public:
    int m_iWordAt00;

    FUN_0082a460_member(bool flag);
    ~FUN_0082a460_member();
    void Apply(int value);
};

class FUN_0082a460 : public FUN_0082a460_base
{
  public:
    FUN_0082a460_member m_4c;
    float m_50;
    float m_54;
    int m_58;
    unsigned char m_5c;
    unsigned char m_5d;

    FUN_0082a460(int a, int b, int c);
    virtual ~FUN_0082a460();
};
}

// Initializes the base class, sets m_4c to false and applies 0, then zeroes m_50, m_54, m_58, m_5c, and m_5d.
// @fnv 0x0082a460
fnv_b4214::FUN_0082a460::FUN_0082a460(int aiParam1, int aiParam2, int aiParam3)
    : fnv_b4214::FUN_0082a460_base(aiParam1, aiParam2, aiParam3), m_4c(false)
{
    m_4c.Apply(0);
    m_50 = 0.0f;
    m_54 = 0.0f;
    m_58 = 0;
    m_5c = 0;
    m_5d = 0;
}

class NiPoint3T
{
  public:
    float x, y, z;
    NiPoint3T();
    NiPoint3T operator*(float fScalar) const;
};

class NiMatrix3T
{
  public:
    float m_afEntries[3][3];
    NiMatrix3T();
};

class hkVector4T
{
  public:
    __m128 m_vComponents;
    hkVector4T();
};

class hkSimdRealT
{
  public:
    __m128 m_vValue;
    hkSimdRealT(float fValue);
};


class TelekinesisTargetController
{
  public:
};

class TelekinesisTarget
{
  public:
};

class PlayerCameraT
{
  public:
};

class GameSettingTableT
{
  public:
};


// @fnv 0x0082afa0
void TelekinesisEffectT::FUN_0082afa0()
{
    if (((::FUN_0082aeb0_shell *)(reinterpret_cast<::FUN_0082aa90_shell *>(((*reinterpret_cast<::PlayerCameraT * *>(&::_g_thePlayer))))->GetFloatAsUInt())))
    {
        void* pvGrabbed = ((void *)(reinterpret_cast<::FUN_0082aee0_shell *>((((::FUN_0082aeb0_shell *)(reinterpret_cast<::FUN_0082aa90_shell *>(((*reinterpret_cast<::PlayerCameraT * *>(&::_g_thePlayer))))->GetFloatAsUInt()))))->FUN_0082aee0()));
        reinterpret_cast<::fnv_00961280::FUN_00961280_shell *>(((*reinterpret_cast<::PlayerCameraT * *>(&::_g_thePlayer))))->FUN_00961280();
        if (pvGrabbed)
        {
            TelekinesisTarget* pkTarget = (TelekinesisTarget*)FUN_004b5a80(pvGrabbed);
            if (m_bHolding)
            {
                NiPoint3T kForward;
                NiMatrix3T kRotationBasis;
                NiPoint3T kAngles = (*(const ::NiPoint3T *)(reinterpret_cast<::TESRecipe *>(((*reinterpret_cast<::PlayerCameraT * *>(&::_g_thePlayer))))->GetData()));
                reinterpret_cast<::FUN_00a59660_cls *>(&(kRotationBasis))->FUN_00a59660(kAngles.z, kAngles.x, kAngles.y);
                reinterpret_cast<::FUN_00439f50_class *>((void *)&(kRotationBasis))->FUN_00439f50(1, (::NiPoint3 *)&(kForward));
                NiPoint3T kIntersectionOffset = kForward * (::FUN_00403e20((float *)&((*reinterpret_cast<::GameSettingTableT *>(&::originalRuntimeFloatSetting1172)))) + m_fHitDistance);
                hkVector4T kMotionVelocity;
                ::fnv_004a3e00::FUN_004a3e00((*(::fnv_004a3e00::bhkCharacterController *)(&kMotionVelocity)), (*(const ::fnv_004a3e00::NiPoint3 *)(&kIntersectionOffset)));
                hkSimdRealT kMass(::FUN_004b5400((void *)(pkTarget)));
                reinterpret_cast<::S_00627920 *>(&(kMotionVelocity))->FUN_00627920((::S_00561240 *)&(kMass));
                reinterpret_cast<::B8182D0Object *>((((::TelekinesisTargetController *)(::FUN_004ae750((void *)(pkTarget))))))->ApplyToTarget({});
            }
            else
            {
                reinterpret_cast<::Owner5615 *>((pkTarget))->FUN_005615d0((int)&((*reinterpret_cast<const ::NiPoint3T *>((void *)&::NiPoint3::ZERO))));
            }
        }
    }
}
#include "generated/data/fallout/magic/telekinesiseffect.inc"
