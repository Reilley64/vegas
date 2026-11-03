
// src/fallout/magic/lighteffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/lighteffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/active_effect_fields.h"
#include "fnv/simple_list_node_view.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/B5Owner.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/fnv_004bc2e0__NiDynamicEffect.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00572750__XActor.h"
#include "fnv/decl/fnv_00572770__XActor.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00b5c940__SSNode.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00495000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006d2000.h"
#include "fnv/symbols_0080e000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011de000.h"
#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_0050d000.h"
#include "fnv/symbols_00572000.h"
struct FUN_0080ed20_shell
{
    float f0;
    float f1;
    float f2;
    FUN_0080ed20_shell* DivideByScalar(float divisor);
};

// Divides the three float components f0, f1 and f2 by divisor in place and returns this.
// @fnv 0x0080ed20
FUN_0080ed20_shell* FUN_0080ed20_shell::DivideByScalar(float divisor)
{
    f0 /= divisor;
    f1 /= divisor;
    f2 /= divisor;
    return this;
}

struct Actor
{
};
struct TESForm
{
};
struct LightEffect : TESForm
{
    void FUN_0080f030(Actor* apActor);
    void FUN_0080ed60();
};

// @fnv 0x0080f030
void LightEffect::FUN_0080f030(Actor* apActor)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0((uintptr_t)(apActor));
    FUN_0080ed60();
}

struct FUN_0080e6d0_shell
{
    void FUN_0080e6d0();
};
struct FUN_0080e6a0_shell : LightEffect
{
    void* DestroyLightEffect(unsigned int flags);
};
struct GO
{
    ~GO();
};
struct FUN_00803ed0
{
    char _pad[0x48];
    ~FUN_00803ed0();
};
struct FUN_0080e6d0
{
    FUN_00803ed0 _m0;
    GO _m1;
    ~FUN_0080e6d0();
};
// @fnv 0x0080e6a0
void* FUN_0080e6a0_shell::DestroyLightEffect(unsigned int flags)
{
    reinterpret_cast<::FUN_0080e6d0 *>((((FUN_0080e6d0_shell*)this)))->FUN_0080e6d0::~FUN_0080e6d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor for FUN_0080e6d0; destroys its FUN_00803ed0 member and GO member.
// @fnv 0x0080e6d0
FUN_0080e6d0::~FUN_0080e6d0()
{}

struct Flt
{
    operator unsigned int();
};
struct NiLight;
struct ShadowSceneLight;
struct ShadowSceneNode
{
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* __cdecl GetShadowSceneNodeForIndex(int);
};
struct FUN_00b5b4a0_holder
{
};
struct FUN_0080e8a0_holder
{
    void FUN_0080e8a0(float afSecondsElapsed);
};
// @fnv 0x0080e8a0
void FUN_0080e8a0_holder::FUN_0080e8a0(float afSecondsElapsed)
{
    ShadowSceneNode* pnode;
    if ((unsigned int)(*(Flt*)((char*)this + 0x48)))
    {
        pnode = NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0);
        if (pnode)
        {
            if (!((::FUN_00b5b4a0((::FUN_00b5b4a0_self *)(((FUN_00b5b4a0_holder*)pnode)), (unsigned int)(*(Flt*)((char*)this + 0x48)), {}))))
            {
                reinterpret_cast<::fnv_00b5c940::SSNode *>((pnode))->FUN_00b5c940((::fnv_00b5c940::NiLightObj *)(::NiLight *)((NiLight*)(uintptr_t)(*(Flt*)((char*)this + 0x48))), true);
            }
        }
    }
}

struct FUN_00805760_shell
{
    void FUN_00805760(Actor*);
};
struct FUN_0080efd0_shell
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
    void FUN_0080efd0(Actor* apActor);
};
// Calls FUN_00805760 on apActor, then calls v20().
// @fnv 0x0080efd0
void FUN_0080efd0_shell::FUN_0080efd0(Actor* apActor)
{
    ((FUN_00805760_shell*)this)->FUN_00805760(apActor);
    v20();
}

class BGSLoadFormBuffer;
class EffectSetting;
struct ActiveEffect
{
    virtual void ApplyLoadBuffer(BGSLoadFormBuffer*);
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
public:
    ::EffectSetting *GetEffectSetting() const;
public:
    void CopyData(::ActiveEffect *);
public:
    bool IsDone() const;
};
struct LightEffectStandIn : ActiveEffect
{
    void FUN_0080f000(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x0080f000
void LightEffectStandIn::FUN_0080f000(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ActiveEffect::ApplyLoadBuffer(apLoadGameBuffer);
    vf20();
}

struct FUN_0080e610 : ActiveEffect
{
    char _pad[0x48];
    FUN_0080e610(void*, void*, void*);
};

struct FUN_0080e730_shell
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(ActiveEffect*);

    ActiveEffect* CreateActiveEffect();
};

// Allocates a new FUN_0080e610 ActiveEffect from three fields of this object, passes it to v17, and returns it.
// @fnv 0x0080e730
ActiveEffect* FUN_0080e730_shell::CreateActiveEffect()
{
    ActiveEffect* presult =
        new FUN_0080e610(*(void**)((char*)this + 0x28), *(void**)((char*)this + 0x8), *(void**)((char*)this + 0xc));

    this->v17(presult);
    return presult;
}

namespace fnv_0080ef50 {

struct FUN_0080e610
{
    char _pad[0x4c];
    FUN_0080e610(int, int, int);
};

// Allocates a FUN_0080e610 object with operator new and constructs it from the three arguments, returning the new object.
// @fnv 0x0080ef50
FUN_0080e610* CreateFUN_0080e610(int a, int b, int c)
{
    return new FUN_0080e610(a, b, c);
}
}  // namespace fnv_0080ef50

struct CopiedState
{
    void FUN_006e5cc0(CopiedState* other);
};
struct FUN_0080e7e0_Class : ActiveEffect
{
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    void* unk40;
    void* unk44;
    CopiedState state48;
    void FUN_0080e7e0(ActiveEffect* other);
};
// @fnv 0x0080e7e0
void FUN_0080e7e0_Class::FUN_0080e7e0(ActiveEffect* other)
{
    reinterpret_cast<::ActiveEffect *>(this)->CopyData(other);
    LightEffect* effect = dynamic_cast<LightEffect*>(other);
    if (effect)
    {
        reinterpret_cast<FUN_0080e7e0_Class*>(effect)->state48.FUN_006e5cc0(&state48);
    }
}

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
    int field94;
};
struct Source
{
};
struct Host
{
    void FUN_0080e830();
public:
    Source* FUN_0059bb30();
};
struct FUN_0080e900_inner
{
};

struct FUN_0080e900_cls
{
    void FUN_0080e900();
public:
    FUN_0080e900_inner* FUN_0059bb30();
};


extern int DAT_011dc304;

struct EdCallee
{
    void FUN_00572a50(int aiArg);
    void FUN_0066b0d0(int aiArg);
public:
    void* FUN_0059bb30();
};

void* __cdecl FUN_00450b80(int aiArg);

typedef void(* EdVirtual)(void* self, void* apArg);

struct NiPointLight;
class NiNode;
class PlayerCharacter;

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* p = 0);
    ~NiPointer();
    NiPointer& operator=(T* p);
    operator T*() const;
    T* operator->() const;
    T* get() const;
};

struct FUN_004bc1f0_S
{
    void FUN_004bc1f0(float x, float y, float z);
};

struct NiPoint3_POD : FUN_0080ed20_shell
{
};

class NiPoint3 : public NiPoint3_POD
{
  public:
    NiPoint3();
    NiPoint3(float x, float y, float z);
};

class NiPointLight : public FUN_004bc1f0_S
{
  public:
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    NiPointLight();
    void FUN_0050dd50(const NiPoint3&);
    void FUN_0050dd20(float);
};

class NiNode
{
  public:
    virtual void vf_00();
    virtual void vf_01();
    virtual void vf_02();
    virtual void vf_03();
    virtual void vf_04();
    virtual void vf_05();
    virtual void vf_06();
    virtual void vf_07();
    virtual void vf_08();
    virtual void vf_09();
    virtual void vf_0a();
    virtual void vf_0b();
    virtual void vf_0c();
    virtual void vf_0d();
    virtual void vf_0e();
    virtual void vf_0f();
    virtual void vf_10();
    virtual void vf_11();
    virtual void vf_12();
    virtual void vf_13();
    virtual void vf_14();
    virtual void vf_15();
    virtual void vf_16();
    virtual void vf_17();
    virtual void vf_18();
    virtual void vf_19();
    virtual void vf_1a();
    virtual void vf_1b();
    virtual void vf_1c();
    virtual void vf_1d();
    virtual void vf_1e();
    virtual void vf_1f();
    virtual void vf_20();
    virtual void vf_21();
    virtual void vf_22();
    virtual void vf_23();
    virtual void vf_24();
    virtual void vf_25();
    virtual void vf_26();
    virtual void vf_27();
    virtual void vf_28();
    virtual void vf_29();
    virtual void vf_2a();
    virtual void vf_2b();
    virtual void vf_2c();
    virtual void vf_2d();
    virtual void vf_2e();
    virtual void vf_2f();
    virtual void vf_30();
    virtual void vf_31();
    virtual void vf_32();
    virtual void vf_33();
    virtual void vf_34();
    virtual void vf_35();
    virtual void vf_36();
    virtual void AttachChildInAvailableSlot(NiPointLight*, bool);
};

struct ActorStandIn
{
    virtual void vf_00();
    virtual void vf_01();
    virtual void vf_02();
    virtual void vf_03();
    virtual void vf_04();
    virtual void vf_05();
    virtual void vf_06();
    virtual void vf_07();
    virtual void vf_08();
    virtual void vf_09();
    virtual void vf_0a();
    virtual void vf_0b();
    virtual void vf_0c();
    virtual void vf_0d();
    virtual void vf_0e();
    virtual void vf_0f();
    virtual void vf_10();
    virtual void vf_11();
    virtual void vf_12();
    virtual void vf_13();
    virtual void vf_14();
    virtual void vf_15();
    virtual void vf_16();
    virtual void vf_17();
    virtual void vf_18();
    virtual void vf_19();
    virtual void vf_1a();
    virtual void vf_1b();
    virtual void vf_1c();
    virtual void vf_1d();
    virtual void vf_1e();
    virtual void vf_1f();
    virtual void vf_20();
    virtual void vf_21();
    virtual void vf_22();
    virtual void vf_23();
    virtual void vf_24();
    virtual void vf_25();
    virtual void vf_26();
    virtual void vf_27();
    virtual void vf_28();
    virtual void vf_29();
    virtual void vf_2a();
    virtual void vf_2b();
    virtual void vf_2c();
    virtual void vf_2d();
    virtual void vf_2e();
    virtual void vf_2f();
    virtual void vf_30();
    virtual void vf_31();
    virtual void vf_32();
    virtual void vf_33();
    virtual void vf_34();
    virtual void vf_35();
    virtual void vf_36();
    virtual void vf_37();
    virtual void vf_38();
    virtual void vf_39();
    virtual void vf_3a();
    virtual void vf_3b();
    virtual void vf_3c();
    virtual void vf_3d();
    virtual void vf_3e();
    virtual void vf_3f();
    virtual void vf_40();
    virtual void vf_41();
    virtual void vf_42();
    virtual void vf_43();
    virtual void vf_44();
    virtual void vf_45();
    virtual void vf_46();
    virtual void vf_47();
    virtual void vf_48();
    virtual void vf_49();
    virtual void vf_4a();
    virtual void vf_4b();
    virtual void vf_4c();
    virtual void vf_4d();
    virtual void vf_4e();
    virtual void vf_4f();
    virtual void vf_50();
    virtual void vf_51();
    virtual void vf_52();
    virtual void vf_53();
    virtual void vf_54();
    virtual void vf_55();
    virtual void vf_56();
    virtual void vf_57();
    virtual void vf_58();
    virtual void vf_59();
    virtual void vf_5a();
    virtual void vf_5b();
    virtual void vf_5c();
    virtual void vf_5d();
    virtual void vf_5e();
    virtual void vf_5f();
    virtual void vf_60();
    virtual void vf_61();
    virtual void vf_62();
    virtual void vf_63();
    virtual void vf_64();
    virtual void vf_65();
    virtual void vf_66();
    virtual void vf_67();
    virtual void vf_68();
    virtual void vf_69();
    virtual void vf_6a();
    virtual void vf_6b();
    virtual void vf_6c();
    virtual void vf_6d();
    virtual void vf_6e();
    virtual void vf_6f();
    virtual void vf_70();
    virtual void vf_71();
    virtual void vf_72();
    virtual void vf_73();
    virtual NiNode* Get3D();
    virtual void vf_1d4();
    virtual void vf_1d8();
    virtual NiPoint3 GetPos();
};

struct ActorV_S
{
};

struct ActorCalls
{
};

class PlayerCharacter
{
  public:
};


class GlobalObject2_0040c150
{
  public:
};
extern GlobalObject2_0040c150 g_011d1d18;

class GlobalObject_0040e0b0
{
  public:
public:
    float* Float();
};
extern GlobalObject_0040e0b0 g_011d1980;
extern GlobalObject_0040e0b0 g_011d1a30;

union SETTING_VALUE
{
    float f;
};
class GameSettingCollection
{
};
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1166;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting1167;


class TESObjectLIGH
{
};

struct FUN_005e3fc0_shell
{
    unsigned int Get();
};

struct PathingRequest
{
};

struct EffectSetting
{
public:
    int GetArchetype();
};

struct FUN_0082ccb0_Cls
{
};

class Actor;
class TESObjectREFR;
class ActiveEffect;
template <class> class BSSimpleList;
struct MagicTarget
{
public:
    ::Actor *GetOwnerActor() const;
public:
    virtual ~MagicTarget();
    virtual TESObjectREFR* GetMagicTargetReference();
    virtual BSSimpleList<ActiveEffect*>* GetActiveEffectList();
};
// Gets an Effect via FUN_0059bb30()->FUN_00822b40() and, if non-null, passes its field94 to FUN_0080ee50.
// @fnv 0x0080e830
void Host::FUN_0080e830()
{
    Effect* effect = ((::Source *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::Effect *)(reinterpret_cast<::MagicTarget *>((((::Source *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (effect)
        ::FUN_0080ee50((::MagicTarget *)(int *)(effect ? &effect->field94 : 0));
}
// @fnv 0x0080e900
void FUN_0080e900_cls::FUN_0080e900()
{
    reinterpret_cast<::LightEffect *>(this)->FUN_0080ed60();
    char* a = ((::FUN_0080e900_inner *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) != 0 ? (char*)((void *)(reinterpret_cast<::MagicTarget *>((((::FUN_0080e900_inner *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))))->GetOwnerActor())) : 0;
    if (a != 0)
    {
        ::FUN_0080ee50((::MagicTarget *)(char *)(a != 0 ? a + 0x94 : 0));
    }
}
// @fnv 0x0080ed60
void LightEffect::FUN_0080ed60()
{
    void* pActor2;
    void* pTmp;
    void* pObj;
    pActor2 = ((void *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((void *)(reinterpret_cast<::MagicTarget *>((((EdCallee*)((void *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)))))->GetOwnerActor())) : 0;

    if (((void *)(::FUN_00559450((int *)(((EdCallee*)((char*)this + 0x48)))))) != 0)
    {
        pTmp = FUN_00450b80(0);
        if (pTmp != 0)
        {
            reinterpret_cast<::B5Owner *>((((EdCallee*)pTmp)))->FUN_00b5eed0((uintptr_t)(((void *)(::FUN_00559450((int *)(((EdCallee*)((char*)this + 0x48))))))));
        }
        pObj = ((void *)(reinterpret_cast<::FUN_009611e0_shell *>((((EdCallee*)((void *)(::FUN_00559450((int *)(((EdCallee*)((char*)this + 0x48)))))))))->FUN_009611e0()));
        if (pObj != 0)
        {
            ((EdVirtual)(*(void***)pObj)[58])(pObj, ((void *)(::FUN_00559450((int *)(((EdCallee*)((char*)this + 0x48)))))));
        }
        if (pActor2 != 0)
        {
            ((EdCallee*)pActor2)->FUN_00572a50(1);
        }
        ((EdCallee*)((char*)this + 0x48))->FUN_0066b0d0(0);
        DAT_011dc304 = DAT_011dc304 - 1;
        if (DAT_011dc304 < 0)
        {
            DAT_011dc304 = 0;
        }
    }
}

struct LightEffectDerived : ActiveEffect
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
    NiPointer<NiPointLight> m_spLight;  // offset 0x48


    void AttachLightEffect();
public:
    MagicTarget* FUN_0059bb30();
};

// @fnv 0x0080e970
void LightEffectDerived::AttachLightEffect()
{
    Actor* pTarget3 = ((::MagicTarget *)(reinterpret_cast<::ActiveEffectFields *>(this)->target)) ? ((::MagicTarget *)(reinterpret_cast<::ActiveEffectFields *>(this)->target))->GetOwnerActor() : 0;
    if (!this->m_spLight && pTarget3 && !((reinterpret_cast<::fnv_00572750::XActor *>((((ActorCalls*)pTarget3)))->FUN_00572750())) && DAT_011dc304 <= *((int *)&(::FUN_0043d4d0((int *)&(g_011d1d18)))))
    {
        TESObjectLIGH* pLightTmp = ((::TESObjectLIGH *)(reinterpret_cast<::FUN_004fd380_shell *>((reinterpret_cast<::ActiveEffect *>((((FUN_0082ccb0_Cls*)this)))->GetEffectSetting()))->FUN_004fd380()));
        if (!pLightTmp)
        {
            ::FUN_005b5e40(
                );
            return;
        }

        this->m_spLight = new NiPointLight();

        unsigned int color4 = ((FUN_005e3fc0_shell*)pLightTmp)->Get();
        NiPoint3 colorPoint4((float)(unsigned char)(color4 & 0xff),
                             (float)(unsigned char)(((unsigned short)color4 >> 8) & 0xff),
                             (float)(unsigned char)((color4 >> 16) & 0xff));
        colorPoint4.DivideByScalar(255.0f);
        reinterpret_cast<::fnv_004bc2e0::NiDynamicEffect *>(((this->m_spLight).operator->()))->SetEffectColor((const ::fnv_004bc2e0::NiColor &)(colorPoint4));

        float fValX = (*((float *)&(::FUN_00403e20((float *)&(g_011d1980)))) + ::GetFloatAtOffset1C((char *)(this))) * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1112))))->f;
        NiPoint3 offsetPoint5(fValX, 0.0f, 0.0f);
        this->m_spLight->FUN_0050dd50(offsetPoint5);

        this->m_spLight->FUN_0050dd20(::GetFieldB4Float((char *)(((PathingRequest*)pLightTmp))));

        ShadowSceneNode* aPScene = (ShadowSceneNode*)FUN_00450b80(0);
        if (aPScene)
        {
            reinterpret_cast<::fnv_00b5c940::SSNode *>((aPScene))->FUN_00b5c940((::fnv_00b5c940::NiLightObj *)(::NiLight *)((NiLight*)((::NiPointLight *)(::FUN_00559450((int *)&(this->m_spLight))))), true);
        }

        float fX = *((float *)&(::FUN_00403e20((float *)&(g_011d1a30)))) * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((ActorV_S*)pTarget3)))->FUN_00567400();

        float fY = (((ActorStandIn*)pTarget3)->GetPos().f1 + ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1166))))->f) *
                   reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((ActorV_S*)pTarget3)))->FUN_00567400();
        float fZ = reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>((void *)(((ActorV_S*)pTarget3)))->GetActorHeight() +
                   ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting1167))))->f * reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((((ActorV_S*)pTarget3)))->FUN_00567400();

        ((FUN_004bc1f0_S*)((::NiPointLight *)(::FUN_00559450((int *)&(this->m_spLight)))))->FUN_004bc1f0(fX, fY, fZ);

        NiPointer<NiNode> spNode3((pTarget3 == (Actor*)_g_thePlayer) ? ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((_g_thePlayer))->FUN_00950bb0(false)))
                                                                     : ((ActorStandIn*)pTarget3)->Get3D());
        spNode3->AttachChildInAvailableSlot(this->m_spLight, true);
        reinterpret_cast<::fnv_00572770::XActor *>((((ActorCalls*)pTarget3)))->FUN_00572770(this->m_spLight);
        ++DAT_011dc304;
    }
}

namespace fnv_0080e610 {
struct NiPointLight;

struct LightEffectBase : ActiveEffect
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
    LightEffectBase(void* caster, void* item, void* effect);
    virtual ~LightEffectBase();
};

struct FUN_00633c90
{
    NiPointLight* object;
    FUN_00633c90(NiPointLight* value);
    ~FUN_00633c90();
    void FUN_0066b0d0(NiPointLight* value);
};

struct FUN_0080e610 : LightEffectBase
{
    FUN_00633c90 light;
    FUN_0080e610(void* caster, void* item, void* effect);
    virtual ~FUN_0080e610();
};

// Constructs a light effect, initializing the light object to null via FUN_0066b0d0.
// @fnv 0x0080e610
FUN_0080e610::FUN_0080e610(void* caster, void* item, void* effect) : LightEffectBase(caster, item, effect), light(0)
{
    light.FUN_0066b0d0(0);
}

}  // namespace fnv_0080e610

struct EffectSetting;
struct MagicTarget;

template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    bool IsEmpty();
    T& GetItem();
    BSSimpleList* GetNext();
};
class TESObjectREFR;
// @fnv 0x0080ee50
void FUN_0080ee50(MagicTarget* target)
{
    if (!target)
        return;
    LightEffect* strongest = 0;
    BSSimpleList<ActiveEffect*>* node = target->GetActiveEffectList();
    while (node && !node->IsEmpty())
    {
        ActiveEffect* effect = (*((::ActiveEffect * *)(&reinterpret_cast<::SimpleListNodeView*>(node)->m_item)));
        if (effect && effect->GetEffectSetting()->GetArchetype() == 13 && !effect->IsDone())
        {
            LightEffect* light = dynamic_cast<LightEffect*>(effect);
            if (!strongest || ::GetFloatAtOffset1C((char *)(strongest)) < ::GetFloatAtOffset1C((char *)(light)))
            {
                if (strongest)
                    strongest->FUN_0080ed60();
                strongest = light;
            }
            else
            {
                light->FUN_0080ed60();
            }
        }
        node = ((::BSSimpleList< ::ActiveEffect *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    if (strongest)
        reinterpret_cast<::LightEffectDerived *>((strongest))->AttachLightEffect();
}
#include "generated/data/fallout/magic/lighteffect.inc"
