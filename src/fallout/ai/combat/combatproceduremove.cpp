
// src/fallout/ai/combat/combatproceduremove.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatproceduremove.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/combat_controller_fields.h"
#include <cstdint>
#include <new>
#include "fnv/decl/AA10Menu.h"
#include "fnv/decl/ActorStandIn.h"
#include "fnv/decl/AvoidanceMap.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/CPStandIn009caae0.h"
#include "fnv/decl/CombatDecompClass.h"
#include "fnv/decl/CombatPlan.h"
#include "fnv/decl/CombatProcedureEx.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_00527b70_shell.h"
#include "fnv/decl/FUN_00527ba0_This.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_006e2980_shell.h"
#include "fnv/decl/FUN_00705b10_Dummy.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008b3960_Class.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008b3bf0_shell.h"
#include "fnv/decl/FUN_008d7f40_shell.h"
#include "fnv/decl/FUN_008e7c50_cls.h"
#include "fnv/decl/FUN_00905450_StandIn.h"
#include "fnv/decl/FUN_0097be60_cls.h"
#include "fnv/decl/FUN_0097fa50_Class.h"
#include "fnv/decl/FUN_0097fb60_shell.h"
#include "fnv/decl/FUN_009892a0_shell.h"
#include "fnv/decl/FUN_00989490_shell.h"
#include "fnv/decl/FUN_00996de0_Class.h"
#include "fnv/decl/FUN_00996e00_shell.h"
#include "fnv/decl/FUN_00996ed0_shell.h"
#include "fnv/decl/FUN_00996ef0_shell.h"
#include "fnv/decl/FUN_0099ccd0_shell.h"
#include "fnv/decl/FUN_0099d310_shell.h"
#include "fnv/decl/FUN_009a03d0_cls.h"
#include "fnv/decl/FUN_009a0680_shell.h"
#include "fnv/decl/FUN_009a0b00_s.h"
#include "fnv/decl/FUN_009caac0_shell.h"
#include "fnv/decl/FUN_009cc490_shell.h"
#include "fnv/decl/FUN_009d4f30_shell.h"
#include "fnv/decl/FUN_009d6730_shell.h"
#include "fnv/decl/FUN_009d7c00_Class.h"
#include "fnv/decl/FUN_009d7c20_shell.h"
#include "fnv/decl/FUN_009d7c60_class.h"
#include "fnv/decl/FUN_009d7c80_Class.h"
#include "fnv/decl/HX.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiPlane.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/NiPtr.h"
#include "fnv/decl/PathingLocationCheck.h"
#include "fnv/decl/S008b39a0.h"
#include "fnv/decl/StandIn_00989010.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0097ee90__DummyInner.h"
#include "fnv/decl/fnv_0098ddd0__FUN_0098ddd0_shell.h"
#include "fnv/decl/fnv_00996e20__FUN_00996e20_shell.h"
#include "fnv/decl/fnv_00996e40__FUN_00996e40_shell.h"
#include "fnv/decl/fnv_00996ea0__MyProc.h"
#include "fnv/decl/fnv_009a03a0__FUN_009a03a0_shell.h"
#include "fnv/decl/fnv_009a0470__FUN_009a0470_shell.h"
#include "fnv/decl/fnv_009a0d00__FUN_009a0d00_shell.h"
#include "fnv/decl/fnv_009a0ec0__FUN_009a0ec0_shell.h"
#include "fnv/decl/s575ca0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00637000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_0097b000.h"
#include "fnv/symbols_0097f000.h"
#include "fnv/symbols_009a7000.h"
#include "fnv/symbols_009a8000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0103a000.h"
#include "fnv/symbols_011a5000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011f1000.h"
struct CombatProcedureMove
{
    void FUN_009d6ba0();
    void* DestroyIfFlagged(unsigned int flags);
};

struct FUN_009d7bd0_shell
{
    bool IsFlagSet(unsigned int flags);
};

// Tests whether the bit selected by flags is set in the 32-bit mask at offset 0x90 of this object.
// @fnv 0x009d7bd0
bool FUN_009d7bd0_shell::IsFlagSet(unsigned int flags)
{
    return ((1 << flags) & *(unsigned int*)((char*)this + 0x90)) ? true : false;
}

struct CombatTargetTimestamp
{
    int v;
    CombatTargetTimestamp(float);
public:
    float FUN_006a7f50() const;
};
struct Holder
{
    void SetValue(float);
};
// @fnv 0x009d8410
void Holder::SetValue(float afValue)
{
    CombatTargetTimestamp t(afValue);
    *(int*)((char*)this + 0xC0) = t.v;
}

struct S009d8440
{
    float FUN_009d8440();
};
// @fnv 0x009d8440
float S009d8440::FUN_009d8440()
{
    switch (*(int*)((char*)this + 0x3C))
    {
    case 6:
    case 7:
        return DAT_010162c0;
    case 8:
        return 0.5f;
    default:
        return 1.0f;
    }
}

struct TESObjectREFR;
struct CombatProcedureAttackRanged
{
};
struct MoveHolder
{
    void ClearTargetRef(TESObjectREFR*);
};
// If the reference stored at offset 0x38 matches apRef, clears it to null and logs that the targeted reference pointer was cleared.
// @fnv 0x009d8480
void MoveHolder::ClearTargetRef(TESObjectREFR* apRef)
{
    if (*(TESObjectREFR**)((char*)this + 0x38) == apRef)
    {
        *(TESObjectREFR**)((char*)this + 0x38) = 0;
        reinterpret_cast<::FUN_009caac0_shell *>((((CombatProcedureAttackRanged*)this)))->FUN_009caac0((intptr_t)("Targeted reference pointer was cleared"));
    }
}

struct FUN_009d6c80_shell
{
    void FUN_009d6c80();
};
struct IMH
{
};
struct FUN_009d84b0_shell
{
    void FUN_009d84b0();
};
// If the bool at offset 0x54 is set, calls FUN_009d6c80 through the object at offset 4 and clears the flag.
// @fnv 0x009d84b0
void FUN_009d84b0_shell::FUN_009d84b0()
{
    if (*(bool*)((char*)this + 0x54))
    {
        ((::FUN_009d6c80_shell *)(reinterpret_cast<::InterfaceManager *>((((IMH*)*(IMH**)((char*)this + 4))))->FUN_00586150()))->FUN_009d6c80();
        *(bool*)((char*)this + 0x54) = 0;
    }
}

namespace fnv_009d84e0 {
struct Tile;
struct IMH
{
};
struct FUN_009d7c20_shell
{
};
struct FUN_009d84e0_shell
{
    void FUN_009d84e0();
};
// @fnv 0x009d84e0
void FUN_009d84e0_shell::FUN_009d84e0()
{
    if (reinterpret_cast<int*>(this)[4] == 2 || reinterpret_cast<int*>(this)[4] == 3)
    {
        reinterpret_cast<::FUN_009d7c20_shell *>((reinterpret_cast<FUN_009d7c20_shell*>(((::fnv_009d84e0::Tile *)(reinterpret_cast<::InterfaceManager *>((reinterpret_cast<IMH*>(reinterpret_cast<int*>(this)[1])))->FUN_00586150())))))->FUN_009d7c20();
        *reinterpret_cast<char*>(this + 0x54) = 1;
    }
}
}  // namespace fnv_009d84e0

struct Actor
{
};
struct TESAmmoInitCalls
{
    Actor* GetFieldBC();
};
struct FUN_00666f00_shell
{
    bool FUN_00666f00();
};
struct CombatProcedure
{
};
struct CombatProcedureEngageTarget
{
};
struct FUN_009d6c00_shell : CombatProcedureEngageTarget
{
    Actor* GetFieldBC();
    void UpdateCombatMovement();
};
// @fnv 0x009d6c00
void FUN_009d6c00_shell::UpdateCombatMovement()
{
    Actor* attacker = ((::Actor *)(reinterpret_cast<CombatControllerFields*>(((TESAmmoInitCalls*)*(void**)((char*)this + 4)))->pActor));
    if (*(int*)((char*)this + 0x10) == 1 || *(int*)((char*)this + 0x10) == 2)
    {
        if (!reinterpret_cast<::FUN_00666f00_shell *>(this)->FUN_00666f00())
            reinterpret_cast<::FUN_008b3ab0_shell *>((attacker))->FUN_008b3ab0();
    }
    else if (*(int*)((char*)this + 0x10) == 3)
        reinterpret_cast<::fnv_00996ea0::MyProc *>((((CombatProcedure*)this)))->FUN_00996ea0();
    reinterpret_cast<::fnv_00996e40::FUN_00996e40_shell *>(this)->FUN_00996e40();
    if (*(bool*)((char*)this + 0x54))
        ((::FUN_009d6c80_shell *)(reinterpret_cast<::InterfaceManager *>((((IMH*)*(void**)((char*)this + 4))))->FUN_00586150()))->FUN_009d6c80();
}

struct BGSSaveFormBuffer;
struct BGSSaveFormBufferSaveGameHelper;

struct SaveFormIDHelper
{
};

struct BGSSaveFormBuffer : SaveFormIDHelper
{
};

struct CombatProcedureSaveGameHelper
{
};

struct CoordinateTriple
{
};

struct GO
{
    operator unsigned int() const;
};

struct FUN_009a5eb0_shell
{
    void FUN_009a5eb0(BGSSaveFormBuffer* buffer);
};

struct FUN_009d8880_shell
{
    void FUN_009d8880(BGSSaveFormBuffer* buffer);
};

// @fnv 0x009d8880
void FUN_009d8880_shell::FUN_009d8880(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00996ed0_shell *>((reinterpret_cast<CombatProcedureSaveGameHelper*>(this)))->SaveToBuffer(buffer);

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10), 4, 0);

    reinterpret_cast<::FUN_00527b70_shell *>((reinterpret_cast<CoordinateTriple*>(reinterpret_cast<char*>(this) + 0x14)))->FUN_00527b70((::BGSSaveGameBuffer *)(buffer));
    reinterpret_cast<::FUN_00527b70_shell *>((reinterpret_cast<CoordinateTriple*>(reinterpret_cast<char*>(this) + 0x24)))->FUN_00527b70((::BGSSaveGameBuffer *)(buffer));

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x34), 4, 0);

    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x38)), 0);

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x3C), 4, 0);

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x60), 4, 0);

    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x64)->FUN_009a5eb0(buffer);
    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x40)->FUN_009a5eb0(buffer);
    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x6C)->FUN_009a5eb0(buffer);
    reinterpret_cast<FUN_009a5eb0_shell*>(reinterpret_cast<char*>(this) + 0x74)->FUN_009a5eb0(buffer);

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x48), 0x0C, 0);

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x54), 1, 0);

    *reinterpret_cast<bool*>(reinterpret_cast<char*>(this) + 0x5C) =
        reinterpret_cast<const GO*>(reinterpret_cast<char*>(this) + 0x58)->operator unsigned int();

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x5C), 1, 0);
}

struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
};

struct FUN_00527ba0_Class
{
};

struct TimeoutTimer
{
    void LoadGame(BGSLoadFormBuffer*);
public:
    float FUN_006b9130();
public:
    bool CheckTimer();
};

struct CombatProcedureLoadGameHelper
{
};

struct FUN_009d89a0_shell : CombatProcedureMove
{
    void FUN_009d89a0(BGSLoadFormBuffer*);
};

// @fnv 0x009d89a0
void FUN_009d89a0_shell::FUN_009d89a0(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00996ef0_shell *>((((CombatProcedureLoadGameHelper*)this)))->FUN_00996ef0(buffer);

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x10)), 4);

    reinterpret_cast<::FUN_00527ba0_This *>((reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x14)))->FUN_00527ba0((::BGSLoadGameBuffer *)(buffer));

    reinterpret_cast<::FUN_00527ba0_This *>((reinterpret_cast<FUN_00527ba0_Class*>(reinterpret_cast<char*>(this) + 0x24)))->FUN_00527ba0((::BGSLoadGameBuffer *)(buffer));

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x34)), 4);

    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x38)));

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x3c)), 4);

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x60)), 4);

    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x64)->LoadGame(buffer);

    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x40)->LoadGame(buffer);

    reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x6c)->LoadGame(buffer);

    if (buffer->GetVersion() >= 8)
    {
        reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x74)->LoadGame(buffer);
    }

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x48)), 0xc);

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x54)), 1);

    if (buffer->GetVersion() >= 0xc)
    {
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x5c)), 1);
    }
}

struct FUN_009ca680
{
    virtual ~FUN_009ca680();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    FUN_009ca680();
};
struct FUN_0097ede0
{
    unsigned int x, y, z, w;
    FUN_0097ede0();
};
struct FUN_00906f60
{
    unsigned int x, y;
    FUN_00906f60();
};
struct FUN_006815c0
{
    unsigned int x, y, z;
    FUN_006815c0();
};
struct FUN_00633c90
{
    unsigned int value;
    FUN_00633c90(int);
    ~FUN_00633c90();
};
struct MoveInput
{
    FUN_0097ede0* FUN_006815c0();
};
struct FUN_009d69f0 : FUN_009ca680
{
    unsigned int unk10;
    FUN_0097ede0 startTransform;
    FUN_0097ede0 currentTransform;
    float rate;
    uintptr_t target38;
    unsigned int mode;
    FUN_00906f60 pos40;
    FUN_006815c0 pos48;
    bool active54;
    FUN_00633c90 state58;
    bool active5C;
    int unk60;
    FUN_00906f60 state64;
    FUN_00906f60 state6C;
    FUN_00906f60 state74;
    FUN_009d69f0(MoveInput* input, float speed, unsigned int flags);
    virtual ~FUN_009d69f0();
};
// @fnv 0x009d69f0
FUN_009d69f0::FUN_009d69f0(MoveInput* input, float speed, unsigned int flags)
    : unk10(0), startTransform(), currentTransform(), rate(speed), target38(0), mode(flags), pos40(), pos48(),
      active54(false), state58(0), active5C(false), unk60(-1), state64(), state6C(), state74()
{
    if (input)
    {
        startTransform = *((::FUN_0097ede0 *)(((::Vec3 *)(void *)(input))));
        currentTransform = startTransform;
        target38 = ((uintptr_t)(reinterpret_cast<::MagicCaster_shell *>((input))->FUN_0044edb0()));
        if (((bool)(reinterpret_cast<::FUN_0097be60_cls *>((input))->FUN_0097be60(2))))
            rate = -rate;
    }
}

class C9D6BA0Ptr
{
  public:
    ~C9D6BA0Ptr();

    void* m_pObject;
};

class C9D6BA0Base
{
  public:
    virtual ~C9D6BA0Base();

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
};

class FUN_009d6ba0 : public C9D6BA0Base
{
  public:
    virtual ~FUN_009d6ba0();

    C9D6BA0Ptr m_spReferencedObject;
};
// @fnv 0x009d6b70
void* CombatProcedureMove::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_009d6ba0 *>(this)->FUN_009d6ba0::~FUN_009d6ba0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x009d6ba0
FUN_009d6ba0::~FUN_009d6ba0()
{}

struct TargetActor;
struct ActorVTable
{
    void* unk000;
    void* unk004;
    void* unk008;
    void* unk00c;
    void* unk010;
    void* unk014;
    void* unk018;
    void* unk01c;
    void* unk020;
    void* unk024;
    void* unk028;
    void* unk02c;
    void* unk030;
    void* unk034;
    void* unk038;
    void* unk03c;
    void* unk040;
    void* unk044;
    void* unk048;
    void* unk04c;
    void* unk050;
    void* unk054;
    void* unk058;
    void* unk05c;
    void* unk060;
    void* unk064;
    void* unk068;
    void* unk06c;
    void* unk070;
    void* unk074;
    void* unk078;
    void* unk07c;
    void* unk080;
    void* unk084;
    void* unk088;
    void* unk08c;
    void* unk090;
    void* unk094;
    void* unk098;
    void* unk09c;
    void* unk0a0;
    void* unk0a4;
    void* unk0a8;
    void* unk0ac;
    void* unk0b0;
    void* unk0b4;
    void* unk0b8;
    void* unk0bc;
    void* unk0c0;
    void* unk0c4;
    void* unk0c8;
    void* unk0cc;
    void* unk0d0;
    void* unk0d4;
    void* unk0d8;
    void* unk0dc;
    void* unk0e0;
    void* unk0e4;
    void* unk0e8;
    void* unk0ec;
    void* unk0f0;
    void* unk0f4;
    void* unk0f8;
    void* unk0fc;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10c;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11c;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12c;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13c;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14c;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15c;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16c;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17c;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18c;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19c;
    void* unk1a0;
    void* unk1a4;
    void* unk1a8;
    void* unk1ac;
    void* unk1b0;
    void* unk1b4;
    void* unk1b8;
    void* unk1bc;
    void* unk1c0;
    void* unk1c4;
    void* unk1c8;
    void* unk1cc;
    void* unk1d0;
    void* unk1d4;
    void* unk1d8;
    void* unk1dc;
    void* unk1e0;
    void* unk1e4;
    void* unk1e8;
    void* unk1ec;
    void* unk1f0;
    void*(* get)(TargetActor*, TargetActor*, float);
};
struct TargetActor
{
    ActorVTable* vtable;
};
struct ResultValue
{
};
struct ManagerValue
{
};
struct OutputValue
{
};
struct MemberValue
{
    void* FUN_006815c0(float, void*);
};
struct IMValue
{
};
struct ModeValue
{
    char unk00;
    char unk01;
    char unk02;
    unsigned char enabled;
    int unk04;
};
struct ProcedureValue
{
    int unk00;
    IMValue* unk04;
    int unk08;
    int unk0c;
    int unk10;
    MemberValue unk14;
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
    void UpdateOutput(OutputValue* output);
};
// Calls the vtable getter on the holder, updates the target, and writes values to output depending on unk3c and DAT_011a5650[unk3c].enabled.
// @fnv 0x009d82e0
void ProcedureValue::UpdateOutput(OutputValue* output)
{
    TargetActor* holder = ((::TargetActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    Holder* target = ((::Holder *)(reinterpret_cast<::InterfaceManager *>((unk04))->FUN_00586150()));
    reinterpret_cast<::NiPtr *>((output))->Assign(
        (char *)(void *)(((void *)(reinterpret_cast<::AvoidanceMap *>((((::ResultValue *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(((*reinterpret_cast<::ManagerValue * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00825c00()))))->BuildAvoidanceNodes({}, {}, {})))));
    target->SetValue(FUN_00435dd0());
    void* actor = 0;
    switch (unk3c)
    {
    case 4:
        reinterpret_cast<::NiPtr *>((output))->Assign((char *)(void *)(((void *)(reinterpret_cast<::FUN_00989490_shell *>((((::ResultValue *)(reinterpret_cast<::EffectSetting *>((unk04))->GetCastSound()))))->FUN_00989490({}, {}, {}, {})))));
        break;
    case 0:
    case 1:
        actor = reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00();
        break;
    }
    if ((*reinterpret_cast<ModeValue (*)[]>(&::MoveModes))[unk3c].enabled)
    {
        reinterpret_cast<::NiPtr *>((output))->Assign(
            (char *)(void *)(((void *)(reinterpret_cast<::FUN_009892a0_shell *>((((::ResultValue *)(reinterpret_cast<::EffectSetting *>((unk04))->GetCastSound()))))->FUN_009892a0((::AvoidMember9892 *)(actor), {}, {}, {}, {})))));
    }
}

struct MoveVec
{
    float x, y, z;
    MoveVec();
    MoveVec operator-(const MoveVec&) const;
    MoveVec operator+(const MoveVec&) const;
    MoveVec& operator*=(float);
    bool operator==(const MoveVec&);
};
struct MoveLoc
{
    int x, y, z, w;
    float Distance(const MoveLoc&);
    MoveVec Position();
};
struct MoveTimer
{
    int x, y;
};
struct MoveSetting
{
};
struct MoveRef;
struct MoveRef
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual int Type();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void slot048();
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActor();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void slot1c4();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual void slot1d0();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual MoveVec* Position();

    void* Status();
    int PathIndex();
};
struct MoveRequest
{
    int value;
    MoveRequest(int);
    ~MoveRequest();
};
struct MoveQuery
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
    MoveQuery();
    ~MoveQuery();
};
struct MovePath
{
    int unk00, mode, unk08, unk0c, unk10;
    MoveLoc location;
    int unk24, unk28, unk2c, unk30, unk34, unk38;
    MoveVec start, end;
    int unk54, unk58, unk5c, unk60, unk64;
    intptr_t handle;
};
struct MoveTarget : MoveRef
{
};
struct MoveSmart
{
    MoveTarget* value;
    MoveSmart& operator=(int);
};
struct MoveStamp
{
    int value;
};
struct MoveManager
{
    bool Start();
};
struct MoveOwner
{
};
struct MoveProbe
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
    MoveProbe(const MoveLoc&);
    ~MoveProbe();
};
bool Probe(MoveProbe*, MoveVec*, int, int);
bool InRange(const MoveVec&, const MoveVec&, const MoveVec&, const MoveVec&);
struct ByteAndFlagState
{
    char x, y;
    bool enabled;
    char z;
    int flags;
};
extern bool DAT_011a5bfc;
struct MoveProcedure
{
    int unk00;
    MoveOwner* owner;
    int unk08, unk0c;
    unsigned state;
    MoveLoc destination, current;
    float rate;
    MoveRef* target;
    unsigned mode;
    MoveTimer timer;
    MoveVec position;
    bool active;
    MoveSmart pending;
    bool active5c;
    int index;
    MoveTimer retry, check, probe;
    MoveRef* Actor();
    void FUN_009d6ca0();
};
struct Point052
{
    float x, y, z;
    Point052();
    Point052 operator-(const Point052&) const;
};
extern bool DAT_011a5bfc;
struct Actor052;
struct Table052
{
    void* unk000;
    void* unk004;
    void* unk008;
    void* unk00c;
    void* unk010;
    void* unk014;
    void* unk018;
    void* unk01c;
    void* unk020;
    void* unk024;
    void* unk028;
    void* unk02c;
    void* unk030;
    void* unk034;
    void* unk038;
    void* unk03c;
    void* unk040;
    void* unk044;
    void* unk048;
    void* unk04c;
    void* unk050;
    void* unk054;
    void* unk058;
    void* unk05c;
    void* unk060;
    void* unk064;
    void* unk068;
    void* unk06c;
    void* unk070;
    void* unk074;
    void* unk078;
    void* unk07c;
    void* unk080;
    void* unk084;
    void* unk088;
    void* unk08c;
    void* unk090;
    void* unk094;
    void* unk098;
    void* unk09c;
    void* unk0a0;
    void* unk0a4;
    void* unk0a8;
    void* unk0ac;
    void* unk0b0;
    void* unk0b4;
    void* unk0b8;
    void* unk0bc;
    void* unk0c0;
    void* unk0c4;
    void* unk0c8;
    void* unk0cc;
    void* unk0d0;
    void* unk0d4;
    void* unk0d8;
    void* unk0dc;
    void* unk0e0;
    void* unk0e4;
    void* unk0e8;
    void* unk0ec;
    void* unk0f0;
    void* unk0f4;
    void* unk0f8;
    void* unk0fc;
    void* unk100;
    void* unk104;
    void* unk108;
    void* unk10c;
    void* unk110;
    void* unk114;
    void* unk118;
    void* unk11c;
    void* unk120;
    void* unk124;
    void* unk128;
    void* unk12c;
    void* unk130;
    void* unk134;
    void* unk138;
    void* unk13c;
    void* unk140;
    void* unk144;
    void* unk148;
    void* unk14c;
    void* unk150;
    void* unk154;
    void* unk158;
    void* unk15c;
    void* unk160;
    void* unk164;
    void* unk168;
    void* unk16c;
    void* unk170;
    void* unk174;
    void* unk178;
    void* unk17c;
    void* unk180;
    void* unk184;
    void* unk188;
    void* unk18c;
    void* unk190;
    void* unk194;
    void* unk198;
    void* unk19c;
    void* unk1a0;
    void* unk1a4;
    void* unk1a8;
    void* unk1ac;
    void* unk1b0;
    void* unk1b4;
    void* unk1b8;
    void* unk1bc;
    void* unk1c0;
    void* unk1c4;
    void* unk1c8;
    void* unk1cc;
    void* unk1d0;
    void* unk1d4;
    void* unk1d8;
    void* unk1dc;
    void* unk1e0;
    void* unk1e4;
    void* unk1e8;
    void* unk1ec;
    void* unk1f0;
    Point052&(* position)(Actor052*);
};
struct Request052
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    Request052();
    ~Request052();
};
struct SpecialRequest052
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
    SpecialRequest052();
    ~SpecialRequest052();
};
struct Actor052
{
    virtual void unused000();
    virtual void unused004();
    virtual void unused008();
    virtual void unused00c();
    virtual void unused010();
    virtual void unused014();
    virtual void unused018();
    virtual void unused01c();
    virtual void unused020();
    virtual void unused024();
    virtual void unused028();
    virtual void unused02c();
    virtual void unused030();
    virtual void unused034();
    virtual void unused038();
    virtual void unused03c();
    virtual void unused040();
    virtual void unused044();
    virtual void unused048();
    virtual void unused04c();
    virtual void unused050();
    virtual void unused054();
    virtual void unused058();
    virtual void unused05c();
    virtual void unused060();
    virtual void unused064();
    virtual void unused068();
    virtual void unused06c();
    virtual void unused070();
    virtual void unused074();
    virtual void unused078();
    virtual void unused07c();
    virtual void unused080();
    virtual void unused084();
    virtual void unused088();
    virtual void unused08c();
    virtual void unused090();
    virtual void unused094();
    virtual void unused098();
    virtual void unused09c();
    virtual void unused0a0();
    virtual void unused0a4();
    virtual void unused0a8();
    virtual void unused0ac();
    virtual void unused0b0();
    virtual void unused0b4();
    virtual void unused0b8();
    virtual void unused0bc();
    virtual void unused0c0();
    virtual void unused0c4();
    virtual void unused0c8();
    virtual void unused0cc();
    virtual void unused0d0();
    virtual void unused0d4();
    virtual void unused0d8();
    virtual void unused0dc();
    virtual void unused0e0();
    virtual void unused0e4();
    virtual void unused0e8();
    virtual void unused0ec();
    virtual void unused0f0();
    virtual void unused0f4();
    virtual void unused0f8();
    virtual void unused0fc();
    virtual void unused100();
    virtual void unused104();
    virtual void unused108();
    virtual void unused10c();
    virtual void unused110();
    virtual void unused114();
    virtual void unused118();
    virtual void unused11c();
    virtual void unused120();
    virtual void unused124();
    virtual void unused128();
    virtual void unused12c();
    virtual void unused130();
    virtual void unused134();
    virtual void unused138();
    virtual void unused13c();
    virtual void unused140();
    virtual void unused144();
    virtual void unused148();
    virtual void unused14c();
    virtual void unused150();
    virtual void unused154();
    virtual void unused158();
    virtual void unused15c();
    virtual void unused160();
    virtual void unused164();
    virtual void unused168();
    virtual void unused16c();
    virtual void unused170();
    virtual void unused174();
    virtual void unused178();
    virtual void unused17c();
    virtual void unused180();
    virtual void unused184();
    virtual void unused188();
    virtual void unused18c();
    virtual void unused190();
    virtual void unused194();
    virtual void unused198();
    virtual void unused19c();
    virtual void unused1a0();
    virtual void unused1a4();
    virtual void unused1a8();
    virtual void unused1ac();
    virtual void unused1b0();
    virtual void unused1b4();
    virtual void unused1b8();
    virtual void unused1bc();
    virtual void unused1c0();
    virtual void unused1c4();
    virtual void unused1c8();
    virtual void unused1cc();
    virtual void unused1d0();
    virtual void unused1d4();
    virtual void unused1d8();
    virtual void unused1dc();
    virtual void unused1e0();
    virtual void unused1e4();
    virtual void unused1e8();
    virtual void unused1ec();
    virtual void unused1f0();
    virtual Point052& position();
    float FUN_008be1b0();
    void* FUN_00931850();
    bool SetPathingRequestAvoidNodes(void*);
    void* FUN_008b3820();
};
struct LocationMember052
{
    Point052* FUN_006815c0();
    int unk00, unk04, unk08, unk0c;
};
struct State052
{
    unsigned char type;
    unsigned char unk01, unk02, unk03;
    int unk04;
    LocationMember052 location;
};
struct Holder052
{
    State052* FUN_007058c0();
};
struct Manager052
{
};
struct Location052
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
    Location052(const Point052&, Actor052*);
    ~Location052();
};
struct Bound052;
struct Avoid052
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    Avoid052();
};
struct Bound052
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    Bound052(const Point052&, float, float);
};
struct Output052
{
};
struct Setting052
{
};
struct Ref052
{
    int value;
    void FUN_0066b0d0(void*);
};
struct Procedure052
{
    int unk00;
    Manager052* manager;
    int unk08, unk0c;
    int mode;
    LocationMember052 source;
    LocationMember052 destination;
    float rate;
    Actor052* target;
    int state;
    int unk40, unk44, unk48, unk4c, unk50, unk54;
    Ref052 request;
    int unk5c;
    int unk60;
    bool UpdateMovementRequest(Output052*);
};
Point052 __cdecl FUN_009a68b0(Actor052*, Actor052*, Point052*, float);
extern const char DAT_01091c80[];
// @fnv 0x009d7d00
bool Procedure052::UpdateMovementRequest(Output052* output)
{
    float request;
    bool d;
    float g;
    Actor052* a = ((::Actor052 *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    void* c = reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00();
    Holder052* k = ((::Holder052 *)(reinterpret_cast<::InterfaceManager *>((manager))->FUN_00586150()));
    int b = 3;
    Point052 h = (*reinterpret_cast<::Point052 *>((void *)&::NiPoint3::ZERO));
    g = 0.0f;
    switch (state)
    {
    case 3:
        h = a->position();
        g = ::DAT_0103a1c4;
        break;
    case 0:
        if (reinterpret_cast<::CombatPlan *>((manager))->FUN_00981940(24))
            b = 4;
        break;
    }
    State052* i = k->FUN_007058c0();
    if (i && i->type == 1 && !reinterpret_cast<::TESActorBaseData *>((k))->GetFlag(256) && state != 8 && ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(i->location))->FUN_0084e3a0())) == ((void *)(reinterpret_cast<::s575ca0::Owner *>((a))->FUN_00575ca0())))
    {
        h = *((::Point052 *)(((::Vec3 *)(void *)&(i->location))));
        g = reinterpret_cast<::FUN_009a0b00_s *>((k))->FUN_009a0b00();
        Point052 delta = h - a->position();
        if (reinterpret_cast<::TESCombatStyle *>(&(delta))->UpdateCombatStyle() > g * g)
            g = 0.0f;
    }
    request = 0.0f;
    if (mode == 1)
        request = rate;
    if (state == 1 && mode == 1 && target)
    {
        Point052 position = FUN_009a68b0(a, target, ((::Point052 *)(((::Vec3 *)(void *)&(source)))), DAT_01012054);
        Location052 location(position, a);
        if (reinterpret_cast<::PathingLocationCheck *>(&(location))->FUN_006ded70(a->FUN_008be1b0()) &&
            ::FUN_009a7940((::SightReference *)(a), (::SightReference *)(target), (*(const ::NiPoint3 *)(&position)), (*(const ::NiPoint3 *)(((::Point052 *)(((::Vec3 *)(void *)&(source)))))), 0, -1))
        {
            reinterpret_cast<::fnv_0098ddd0::FUN_0098ddd0_shell *>(&(destination))->FUN_0098ddd0(&position);
            if (!((::Avoid052 *)(::FUN_00559450((int *)(output)))))
                reinterpret_cast<::NiPtr *>((output))->Assign((char *)(::Avoid052 *)(new Avoid052));
            reinterpret_cast<::FUN_00905450_StandIn *>((((::Avoid052 *)(::FUN_00559450((int *)(output))))))->AppendNode(
                (::PathingAvoidanceNode *)&(const ::Bound052 &)(Bound052(target->position(), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting052 *>(&::originalRuntimeFloatSetting385)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting052 *>(&::originalRuntimeFloatSetting386)))))))));
        }
    }
    void* e = 0;
    Request052 j;
    SpecialRequest052 f;
    if (DAT_011a5bfc && (unsigned char)(*reinterpret_cast<ModeValue (*)[]>(&::MoveModes))[state].unk02 && reinterpret_cast<::FUN_009d7bd0_shell *>((k))->IsFlagSet(1) && !a->FUN_00931850())
    {
        reinterpret_cast<::FUN_0099d310_shell *>((k))->FUN_0099d310((::FUN_0099d310_arg *)(::SpecialRequest052 *)(&f));
        reinterpret_cast<::FUN_00705b10_Dummy *>(&(f))->Set(state);
        e = &f;
    }
    else
        e = &j;
    d = false;
    if (request < 0.0)
    {
        request = -request;
        d = true;
    }
    reinterpret_cast<::ActorStandIn *>((a))->BuildPathingRequest((::PathingRequest *)(e), (*(const ::NiPoint3 *)(((::Point052 *)(((::Vec3 *)(void *)&(destination)))))), (::TESObjectREFR *)(void *)(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(destination))->FUN_0084e3a0()))), request, (::PathingAvoidNodeArray *)(void *)(((::Avoid052 *)(::FUN_00559450((int *)(output))))));
    reinterpret_cast<::FUN_006e2980_shell *>((((Request052*)e)))->FUN_006e2980((::NiPoint3 *)&(h), g);
    if (d)
        reinterpret_cast<::FUN_008e7c50_cls *>((((Request052*)e)))->SetUseSoft(0);
    if (!a->SetPathingRequestAvoidNodes(e))
    {
        reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((intptr_t)(DAT_01091c80));
        return false;
    }
    unk60 = -1;
    this->request.FUN_0066b0d0(a->FUN_008b3820());
    reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(b);
    return true;
}

struct DebugPoint
{
    float x, y, z;
};
struct DebugReference
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual const char* GetDebugName();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const DebugPoint& GetDebugPosition();
};
struct DebugOwner
{
    DebugReference* GetFieldBC();
};
struct DebugLocation
{
    DebugPoint& FUN_006815c0();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
struct DebugTimer
{
    float start, duration;
};
struct DebugDisplay
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void __cdecl Print(int, int, const char*, ...);
};
struct MoveDebug
{
    int unk00;
    DebugOwner* owner;
    int unk08, unk0c;
    unsigned int state;
    DebugLocation destination;
    DebugReference* target;
    int unk3c;
    DebugTimer hidingTimer;
    int unk48, unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    DebugTimer coverTimer;
    DebugTimer destinationTimer;
    void PrintDebugInfo(DebugDisplay* display, int x, int y);
};
// Prints the move state, destination cell and position, target info and destination timer to the debug display at the given coordinates.
// @fnv 0x009d8520
void MoveDebug::PrintDebugInfo(DebugDisplay* display, int x, int y)
{
    switch (state)
    {
    case 0:
        display->Print(x, y, "INITIALIZING");
        break;
    case 1:
        display->Print(x, y, "MOVING");
        break;
    case 2:
        display->Print(x, y, "MOVING_USING_COVER");
        display->Print(x, y, "Check Cover Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(coverTimer))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(coverTimer))->FUN_006b9130());
        break;
    case 3:
        display->Print(x, y, "HIDING_BEHIND_COVER");
        display->Print(x, y, "Hiding Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(hidingTimer))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(hidingTimer))->FUN_006b9130());
        display->Print(x, y, "Check Cover Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(coverTimer))->FUN_00435e00(), reinterpret_cast<::TimeoutTimer *>(&(coverTimer))->FUN_006b9130());
        break;
    }
    DebugPoint position = (*(::DebugPoint *)(((::Vec3 *)(void *)&(destination))));
    DebugReference* cell = ((::DebugReference *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(destination))->FUN_0084e3a0()));
    if (cell && cell != ((::DebugReference *)(reinterpret_cast<::s575ca0::Owner *>((((::DebugReference *)(reinterpret_cast<CombatControllerFields*>(owner)->pActor))))->FUN_00575ca0())))
        display->Print(x, y, "Destination: %s (%.02f,%.02f,%.02f)", cell->GetDebugName(), position.x, position.y,
                       position.z);
    else
        display->Print(x, y, "Destination: (%.02f,%.02f,%.02f)", position.x, position.y, position.z);
    if (target)
    {
        DebugPoint targetPosition = target->GetDebugPosition();
        display->Print(x, y, "Target: '%s' (%08X) - Position: (%.02f,%.02f,%.02f)",
                       reinterpret_cast<::BGSCameraPath *>((target))->HasNameForWarning() ? target->GetDebugName() : reinterpret_cast<::FUN_0055d520_shell *>((target))->FUN_0055d520(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((target))->FUN_0084e3a0())),
                       targetPosition.x, targetPosition.y, targetPosition.z);
    }
    if (reinterpret_cast<::FUN_0097fa50_Class *>(&(destinationTimer))->FUN_0097fa50())
        display->Print(x, y, "Check Destination Timer: %.02f/%.02f", reinterpret_cast<::FUN_00435e00_t *>(&(destinationTimer))->FUN_00435e00(),
                       reinterpret_cast<::TimeoutTimer *>(&(destinationTimer))->FUN_006b9130());
}

struct TESForm
{
    virtual ~TESForm();
public:
    bool GetDisabled() const;
};
// @fnv 0x009d6ca0
void MoveProcedure::FUN_009d6ca0()
{
    bool changed3;
    bool stop5;
    MoveRef* actorsB = ((::MoveRef *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    void* actorStatus5 = actorsB->Status();
    MoveRef* other7 = ((::MoveRef *)(reinterpret_cast<::FUN_00996e00_shell *>(this)->FUN_00996e00()));
    MoveManager* manager2 = ((::MoveManager *)(reinterpret_cast<::InterfaceManager *>((owner))->FUN_00586150()));
    switch (state)
    {
    case 0:
        current = destination;
        state = 1;
        if (!reinterpret_cast<::FUN_009d7c80_Class *>(this)->FUN_009d7c80())
            return;
        if (mode == 15)
            reinterpret_cast<::FUN_008d7f40_shell *>(&(probe))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::originalRuntimeFloatSetting461)))))));
        break;
    case 1:
    case 2:
        if (((::MoveTarget *)(::FUN_00559450((int *)&(pending)))) && !reinterpret_cast<::FUN_008b3bf0_shell *>((actorsB))->FUN_008b3bf0())
        {
            MoveRef* ref = ((::MoveTarget *)(::FUN_00559450((int *)&(pending))));
            if (ref->Type() == 8)
            {
                MoveTarget* node = (MoveTarget*)ref;
                if (((bool)(reinterpret_cast<::FUN_009d7c60_class *>((node))->GetByteAtOffsetE1())))
                {
                    reinterpret_cast<::FUN_009d7c00_Class *>((manager2))->ForwardToSub(reinterpret_cast<::FUN_004f8960_shell *>((node))->FUN_004f8960());
                    MoveVec* point = ((::MoveVec *)(reinterpret_cast<::FUN_0068efb0_shell *>((node))->FUN_0068efb0()));
                    reinterpret_cast<::fnv_009a03a0::FUN_009a03a0_shell *>((manager2))->SetFieldE8((intptr_t)(point));
                    reinterpret_cast<::HX *>((node))->FUN_006d3100((::CombatCoverPointData *)(0));
                    if (point)
                    {
                        reinterpret_cast<::StandIn_00989010 *>(&(current))->SetTripleAndValue((::ThreeInts_00989010 *)&(*((::MoveVec *)(::FUN_006377e0((intptr_t)(node))))), ((intptr_t)(reinterpret_cast<::s575ca0::Owner *>((actorsB))->FUN_00575ca0())));
                        if (manager2->Start())
                        {
                            state = 2;
                            active = true;
                            MoveVec pos;
                            ::fnv_009a9370::FUN_009a9370((::fnv_009a9370::CombatController *)(owner), (::fnv_009a9370::CombatCoverPointData *)(::MovePath *)(((::MovePath *)(reinterpret_cast<::FUN_0097fb60_shell *>((manager2))->GetFieldAtE8()))), (::fnv_009a9370::NiPoint3 *)(::MoveVec *)(&pos), (::fnv_009a9370::NiPoint3 *)(::MoveVec *)(&position));
                            position.z += ::FUN_009a8460((::S_009a8460_Actor *)(actorsB), 2, 0);
                            reinterpret_cast<::FUN_008d7f40_shell *>(&(check))->FUN_008d7f40(0.5f);
                        }
                        else
                        {
                            pending = 0;
                            current = destination;
                            state = 1;
                            reinterpret_cast<::FUN_009d7c80_Class *>(this)->FUN_009d7c80();
                            return;
                        }
                    }
                    else
                        current = destination;
                }
            }
            pending = 0;
        }
        if (reinterpret_cast<::FUN_008b3b90_shell *>((actorsB))->FUN_008b3b90())
        {
            if (!reinterpret_cast<::FUN_008b3960_Class *>((actorsB))->FUN_008b3960())
            {
                if (state == 2)
                {
                    MovePath* path = ((::MovePath *)(reinterpret_cast<::FUN_0097fb60_shell *>((manager2))->GetFieldAtE8()));
                    if (path)
                    {
                        reinterpret_cast<::fnv_009a0d00::FUN_009a0d00_shell *>((manager2))->StoreEntry((const void *)(path->handle));
                        reinterpret_cast<::fnv_009a0470::FUN_009a0470_shell *>((manager2))->ReleaseStageHolder(0);
                    }
                }
                else
                {
                    switch (mode)
                    {
                    case 0:
                    case 1:
                    case 7:
                    case 8:
                        reinterpret_cast<::FUN_009cc490_shell *>((manager2))->FUN_009cc490(1 << mode);
                        break;
                    case 3:
                        reinterpret_cast<::FUN_009d4f30_shell *>((manager2))->SetByteAtOffset188ToFF();
                        break;
                    }
                    MovePath* path = ((::MovePath *)(::GetFieldValue((unsigned int *)(manager2))));
                    if (path && path->mode == mode)
                    {
                        reinterpret_cast<::fnv_009a0d00::FUN_009a0d00_shell *>((manager2))->StoreEntry((const void *)(path->handle));
                        reinterpret_cast<::FUN_009a03d0_cls *>((manager2))->FUN_009a03d0(0);
                    }
                }
                reinterpret_cast<::fnv_009a0ec0::FUN_009a0ec0_shell *>((manager2))->SetNodeBlockAndTimestamp((const ::fnv_009a0ec0::FUN_009a0ec0_Block *)&(current));
                reinterpret_cast<::FUN_009a0680_shell *>((manager2))->ClearAndDeletePointer();
                switch (mode)
                {
                case 1:
                    if (state != 2 && reinterpret_cast<::NiPlane *>((void *)&(const ::MoveVec &)(*((::MoveVec *)(((::Vec3 *)(void *)&(current))))))->operator==((const ::NiPlane &)(*((::MoveVec *)(((::Vec3 *)(void *)&(destination)))))))
                        reinterpret_cast<::fnv_009a0ec0::FUN_009a0ec0_shell *>((manager2))->SetNodeBlockAndTimestamp((const ::fnv_009a0ec0::FUN_009a0ec0_Block *)&(destination));
                    break;
                }
            }
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((intptr_t)(reinterpret_cast<::FUN_008b3960_Class *>((actorsB))->FUN_008b3960() ? "Pathing failed while moving to destination"
                                           : "Path Building failed to destination"));
            return;
        }
        if (target && (reinterpret_cast<::TESForm *>((target))->GetDisabled() || reinterpret_cast<::FUN_00440d80_shell *>((target))->FUN_00440d80()))
        {
            static const char disabledReason[] = "Target ref is now disabled or deleted";
            reinterpret_cast<::FUN_009caac0_shell *>(this)->FUN_009caac0((intptr_t)(disabledReason));
            return;
        }
        changed3 = false;
        if (target)
        {
            void* targetStatus8 = 0;
            if (target->IsActor())
            {
                MoveRef* ref = target;
                targetStatus8 = ref->Status();
            }
            MoveLoc locationB = (*(::MoveLoc *)(reinterpret_cast<::FUN_00575650_Class *>((target))->FUN_00575650({})));
            float distance8 = 0.0f;
            if (!actorStatus5 && !targetStatus8)
                distance8 = state == 2
                                ? *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::originalRuntimeFloatSetting390)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::originalRuntimeFloatSetting390))))))
                                : *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::originalRuntimeFloatSetting389)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::originalRuntimeFloatSetting389))))));
            else
                distance8 = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::originalRuntimeFloatSetting391)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::originalRuntimeFloatSetting391))))));
            if (distance8 < locationB.Distance(destination))
            {
                destination = locationB;
                changed3 = true;
            }
        }
        if (state == 2 && reinterpret_cast<::TimeoutTimer *>(&(check))->CheckTimer())
        {
            if (!changed3 && other7 && reinterpret_cast<::fnv_0097ee90::DummyInner *>((manager2))->FUN_0097ee90())
            {
                MovePath* path = ((::MovePath *)(reinterpret_cast<::FUN_0097fb60_shell *>((manager2))->GetFieldAtE8()));
                if (!path)
                    changed3 = true;
                else
                {
                    MoveLoc targetLoc = (*(::MoveLoc *)(reinterpret_cast<::FUN_00575650_Class *>((other7))->FUN_00575650({})));
                    MoveLoc actorLoc = (*(::MoveLoc *)(reinterpret_cast<::FUN_00575650_Class *>((actorsB))->FUN_00575650({})));
                    if (actorLoc.Distance(targetLoc) < 16777216.0)
                    {
                        if (!InRange((*(::MoveVec *)&(reinterpret_cast<::TaskQueueInterface *>(&(path->location))->QueueActorAnimationTask(*(::NiPoint3 *)nullptr))), *other7->Position(), path->start, path->end))
                            changed3 = true;
                        else if (!reinterpret_cast<::FUN_0099ccd0_shell *>((manager2))->FUN_0099ccd0((::Seg99 *)(::MoveLoc *)(&path->location), (::NiPoint3Ex *)(::MoveVec *)(((::MoveVec *)(((::Vec3 *)(void *)&(current))))), (::FUN_0099ccd0_Actor *)(other7), 0))
                            changed3 = true;
                    }
                }
            }
            reinterpret_cast<::FUN_008d7f40_shell *>(&(check))->FUN_008d7f40(0.5f);
        }
        if (changed3)
        {
            if (state == 2)
            {
                reinterpret_cast<::FUN_009d6c80_shell *>((manager2))->FUN_009d6c80();
                reinterpret_cast<::fnv_009a0470::FUN_009a0470_shell *>((manager2))->ReleaseStageHolder(0);
                active = false;
            }
            current = destination;
            state = 1;
            if (!reinterpret_cast<::FUN_009d7c80_Class *>(this)->FUN_009d7c80())
                return;
            return;
        }
        if (!DAT_011a5bfc && state == 1 && !reinterpret_cast<::FUN_008b3bf0_shell *>((actorsB))->FUN_008b3bf0() && !actorStatus5 && MoveModes[mode].enabled &&
            reinterpret_cast<::FUN_009d7bd0_shell *>((manager2))->IsFlagSet(1))
        {
            float radius5 = 256.0f;
            int pathIndex9 = actorsB->PathIndex();
            if (index == -1)
                radius5 = 512.0f;
            if (pathIndex9 != index || reinterpret_cast<::TimeoutTimer *>(&(retry))->CheckTimer())
            {
                index = pathIndex9;
                reinterpret_cast<::FUN_008d7f40_shell *>(&(retry))->FUN_008d7f40(2.0f);
                MoveRequest avoid7(0);
                bool initialized16 = false;
                MoveVec previous6_2 = *actorsB->Position();
                MoveVec point35;
                float lengthVal = 0.0f;
                bool done7 = false;
                while (!done7 && ((bool)(reinterpret_cast<::S008b39a0 *>((actorsB))->ForwardToP190(pathIndex9 + 1, (uintptr_t)(&point35)))))
                {
                    pathIndex9 = pathIndex9 + 1;
                    MoveVec delta8 = point35 - previous6_2;
                    float segment5 = reinterpret_cast<::NiPoint3 *>(&(delta8))->GetLengthSquared();
                    if (lengthVal + segment5 > 1536.0)
                    {
                        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::MoveVec &)(delta8))->FUN_00439180(float(1536.0 - lengthVal));
                        point35 = previous6_2 + delta8;
                        done7 = true;
                    }
                    lengthVal = lengthVal + segment5;
                    previous6_2 = point35;
                    if (!initialized16)
                        reinterpret_cast<::ProcedureValue *>(this)->UpdateOutput((::OutputValue *)(::MoveRequest *)(&avoid7));
                    initialized16 = true;
                    MoveQuery query_2;
                    if (reinterpret_cast<::CombatDecompClass *>((manager2))->InitSubObject((::RetObjParam *)(::MoveQuery *)(&query_2), (intptr_t)(&point35), mode, radius5, (intptr_t)(((void *)(::FUN_00559450((int *)&(avoid7)))))))
                    {
                        active = true;
                        reinterpret_cast<::FUN_009d7c20_shell *>((manager2))->FUN_009d7c20();
                        MoveVec pos;
                        ::fnv_009a9370::FUN_009a9370((::fnv_009a9370::CombatController *)(owner), (::fnv_009a9370::CombatCoverPointData *)(::MovePath *)(((::MovePath *)(reinterpret_cast<::FUN_0097fb60_shell *>((manager2))->GetFieldAtE8()))), (::fnv_009a9370::NiPoint3 *)(::MoveVec *)(&pos), (::fnv_009a9370::NiPoint3 *)(::MoveVec *)(&position));
                        position.z += ::FUN_009a8460((::S_009a8460_Actor *)(actorsB), 2, 0);
                        state = 2;
                        reinterpret_cast<::StandIn_00989010 *>(&(current))->SetTripleAndValue((::ThreeInts_00989010 *)&(pos), ((intptr_t)(reinterpret_cast<::s575ca0::Owner *>((actorsB))->FUN_00575ca0())));
                        if (!reinterpret_cast<::FUN_009d7c80_Class *>(this)->FUN_009d7c80())
                            return;
                        reinterpret_cast<::FUN_008d7f40_shell *>(&(check))->FUN_008d7f40(0.5f);
                        break;
                    }
                }
            }
        }
        stop5 = false;
        if (mode == 15 && reinterpret_cast<::TimeoutTimer *>(&(probe))->CheckTimer())
        {
            MoveLoc loc = (*(::MoveLoc *)(reinterpret_cast<::FUN_00575650_Class *>((actorsB))->FUN_00575650({})));
            if (loc.Distance(destination) <
                *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::originalRuntimeFloatSetting460)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::originalRuntimeFloatSetting460)))))))
            {
                MoveProbe request(destination);
                if (Probe(&request, ((::MoveVec *)(((::Vec3 *)(void *)&(loc)))), 0, 0))
                    stop5 = true;
            }
            reinterpret_cast<::FUN_008d7f40_shell *>(&(probe))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::MoveSetting *>(&::g_011cfad4)))))));
        }
        if (stop5)
            reinterpret_cast<::FUN_008b3ab0_shell *>((actorsB))->FUN_008b3ab0();
        if (stop5 || ((bool)(reinterpret_cast<::TeleportableReference *>((actorsB))->GetTeleportDestinationForm())))
        {
            if (state == 2)
            {
                state = 3;
                reinterpret_cast<::FUN_008d7f40_shell *>(&(timer))->FUN_008d7f40(reinterpret_cast<::S009d8440 *>(this)->FUN_009d8440());
                reinterpret_cast<::FUN_008d7f40_shell *>(&(check))->FUN_008d7f40(0.25f);
                reinterpret_cast<::CombatProcedureEx *>(this)->SetLookAtPoint((const ::NiPoint3 &)(position), 3);
                reinterpret_cast<::fnv_00996e20::FUN_00996e20_shell *>(this)->FUN_00996e20(2);
            }
            else
            {
                reinterpret_cast<::AA10Menu *>((manager2))->HandleMenuEvent((intptr_t)&(destination), mode);
                reinterpret_cast<::CPStandIn009caae0 *>(this)->SetState();
            }
            return;
        }
        break;
    case 3: {
        bool finished6 = false;
        MovePath* path2 = ((::MovePath *)(reinterpret_cast<::FUN_0097fb60_shell *>((manager2))->GetFieldAtE8()));
        if (reinterpret_cast<::TimeoutTimer *>(&(timer))->CheckTimer() || !path2)
            finished6 = true;
        else if (other7)
        {
            float deadline = float(reinterpret_cast<::CombatTargetTimestamp *>(&(timer))->FUN_006a7f50() + 1.0);
            if (deadline < FUN_00435dd0())
            {
                if (((bool)(::GetByteAtOffset70((char *)(manager2)))))
                    finished6 = true;
                else if (deadline < reinterpret_cast<::CombatTargetTimestamp *>((void *)&(const ::MoveStamp &)((*(::MoveStamp *)(reinterpret_cast<::FUN_009d6730_shell *>((manager2))->FUN_009d6730({})))))->FUN_006a7f50())
                    finished6 = true;
            }
            if (!finished6 && reinterpret_cast<::fnv_0097ee90::DummyInner *>((manager2))->FUN_0097ee90() && reinterpret_cast<::TimeoutTimer *>(&(check))->CheckTimer())
            {
                if (!reinterpret_cast<::FUN_0099ccd0_shell *>((manager2))->FUN_0099ccd0((::Seg99 *)(::MoveLoc *)(&path2->location), (::NiPoint3Ex *)(::MoveVec *)(((::MoveVec *)(((::Vec3 *)(void *)&(current))))), (::FUN_0099ccd0_Actor *)(other7), 1))
                    finished6 = true;
                reinterpret_cast<::FUN_008d7f40_shell *>(&(check))->FUN_008d7f40(0.25f);
            }
        }
        if (finished6)
        {
            state = 0;
            reinterpret_cast<::FUN_009d6c80_shell *>((manager2))->FUN_009d6c80();
            active = false;
            reinterpret_cast<::fnv_009a0470::FUN_009a0470_shell *>((manager2))->ReleaseStageHolder(0);
            reinterpret_cast<::fnv_00996ea0::MyProc *>(this)->FUN_00996ea0();
        }
    }
    break;
    default:;
    }
}

struct TESObjectREFR : TESForm
{
};

namespace fnv_009d8ad0 {
using ::TESForm;
using ::TESObjectREFR;


struct MoveContext
{
    void* FUN_008b3820();
};

struct CommandTarget
{
    unsigned int unk00;
    void FUN_0066b0d0(void* target);
};

struct ProcedureController
{

    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34;

    uintptr_t currentForm;

    unsigned int unk3C, unk40, unk44, unk48, unk4C, unk50, unk54;

    CommandTarget command;

    unsigned char refresh;



    void FUN_009d8ad0(unsigned int);
};

// Calls FUN_004534f0, resolves currentForm through FUN_004839c0 and dynamic_cast, then refreshes the command target from context when refresh is set.
// @fnv 0x009d8ad0
void ProcedureController::FUN_009d8ad0(unsigned int value)

{

    MoveContext* context = ((::fnv_009d8ad0::MoveContext *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));

    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(value);

    currentForm = (uintptr_t)(currentForm ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0(currentForm)) : 0);

    if (refresh)

        command.FUN_0066b0d0(context->FUN_008b3820());
}
}

#include "generated/data/fallout/ai/combat/combatproceduremove.inc"
