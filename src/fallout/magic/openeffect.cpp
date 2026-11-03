
// src/fallout/magic/openeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/openeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/active_effect_fields.h"
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/LockExtraData.h"
#include "fnv/decl/fnv_005691b0__P01RefA.h"
#include "fnv/decl/fnv_005692a0__FUN_005692a0_shell.h"
#include "fnv/symbols_00495000.h"
struct FUN_008260b0
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
    virtual void Install(FUN_008260b0*);
    float value04;
    void* object08;
    void* object0c;
    bool flag10, flag11, flag12, flag13;
    int unk14, unk18;
    float value1c, value20;
    int unk24;
    void* object28;
    int unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44;
    FUN_008260b0(void*, void*, void*);
    FUN_008260b0* CloneAndInstall();
};
// Allocates a new FUN_008260b0 from object28, object08 and object0c, installs it, and returns it.
// @fnv 0x008260e0
FUN_008260b0* FUN_008260b0::CloneAndInstall()
{
    FUN_008260b0* result = new FUN_008260b0(object28, object08, object0c);
    Install(result);
    return result;
}

class MagicTarget
{
  public:
    virtual ~MagicTarget();
    int unk4;
    int unk8;
};

struct S_00826190_Ref
{
};

struct S_00826190_RefHolder
{
    virtual void vf0();
    virtual S_00826190_Ref* GetRef();
};

class NonActorMagicTarget : public MagicTarget, public S_00826190_RefHolder
{
};


struct S_00826190_Effect
{
    void FUN_00826190();
};

// @fnv 0x00826190
void S_00826190_Effect::FUN_00826190()
{
    NonActorMagicTarget* target = dynamic_cast<NonActorMagicTarget*>(((::MagicTarget *)(reinterpret_cast<::ActiveEffectFields *>(this)->caster)));
    if (!target || !target->GetRef())
    {
        return;
    }
    void* pLock = ((void *)(reinterpret_cast<::FUN_00569160_shell *>((target->GetRef()))->FUN_00569160()));
    int a = ::LockExtraData::ConvertLockLevel((int)::GetFloatAtOffset1C((char *)this));
    int lockLevel = ::LockExtraData::ConvertLockLevel(reinterpret_cast<::fnv_005691b0::P01RefA *>((target->GetRef()))->FUN_005691b0());
    if (pLock && a >= lockLevel)
    {
        reinterpret_cast<::fnv_005692a0::FUN_005692a0_shell *>((target->GetRef()))->FUN_005692a0();
    }
}
