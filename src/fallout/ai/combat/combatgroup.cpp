
// src/fallout/ai/combat/combatgroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatgroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/CPStandIn00992a50.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ClusterWork.h"
#include "fnv/decl/CombatBox.h"
#include "fnv/decl/Container.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_0042fb60_shell.h"
#include "fnv/decl/FUN_00435de0_ctor.h"
#include "fnv/decl/FUN_00435e00_t.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00453700_shell.h"
#include "fnv/decl/FUN_0049ed90_shell.h"
#include "fnv/decl/FUN_004a51b0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_00508050_Class.h"
#include "fnv/decl/FUN_00527990_shell.h"
#include "fnv/decl/FUN_00527b70_shell.h"
#include "fnv/decl/FUN_00527ba0_This.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00639aa0_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_006bf670_Class.h"
#include "fnv/decl/FUN_006e0320_cls.h"
#include "fnv/decl/FUN_006e0d20_t.h"
#include "fnv/decl/FUN_006e4820_class.h"
#include "fnv/decl/FUN_006f3170_Class.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00869600_Class.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008b3bf0_shell.h"
#include "fnv/decl/FUN_008d0600_s.h"
#include "fnv/decl/FUN_00905450_StandIn.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00968630_stub.h"
#include "fnv/decl/FUN_0097ede0_cls.h"
#include "fnv/decl/FUN_0097ef30_shell.h"
#include "fnv/decl/FUN_0097f200_t.h"
#include "fnv/decl/FUN_0097f220_Class.h"
#include "fnv/decl/FUN_0097fb00_cls.h"
#include "fnv/decl/FUN_00980070_shell.h"
#include "fnv/decl/FUN_00982be0_cls.h"
#include "fnv/decl/FUN_0098ad70_Class.h"
#include "fnv/decl/FUN_0098adb0_shell.h"
#include "fnv/decl/FUN_0098bae0_cls.h"
#include "fnv/decl/FUN_0098bfb0_Class.h"
#include "fnv/decl/FUN_0098d1a0_shell.h"
#include "fnv/decl/FUN_0098f1f0_Class.h"
#include "fnv/decl/FUN_0098f580_class.h"
#include "fnv/decl/FUN_0098f7b0_Class.h"
#include "fnv/decl/FUN_0098f960_class.h"
#include "fnv/decl/FUN_0098fa00_cls.h"
#include "fnv/decl/FUN_00990890_shell.h"
#include "fnv/decl/FUN_009a03d0_cls.h"
#include "fnv/decl/FUN_009a3c50_cls.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/GroupReset.h"
#include "fnv/decl/GroupReset_98afb0.h"
#include "fnv/decl/Group_98d030.h"
#include "fnv/decl/H2.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/LOSGridOwner.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/OuterObj.h"
#include "fnv/decl/P029Manager.h"
#include "fnv/decl/Pathing.h"
#include "fnv/decl/PathingLocationArray.h"
#include "fnv/decl/PathingLocationProxy.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/Point3_0053d280.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S5460.h"
#include "fnv/decl/S981990.h"
#include "fnv/decl/ScriptClass.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0049f210__FUN_0049f210_class.h"
#include "fnv/decl/fnv_0066e590__FUN_0066e590.h"
#include "fnv/decl/fnv_006e05b0__PathingLOSGridMap.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_006f4ed0__PathingLocation.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0087ac60__FUN_0087AC60_Holder.h"
#include "fnv/decl/fnv_008acbe0__FUN_008acbe0_shell.h"
#include "fnv/decl/fnv_008b0670__MyActor.h"
#include "fnv/decl/fnv_00979260__Projectile.h"
#include "fnv/decl/fnv_0097ee90__DummyInner.h"
#include "fnv/decl/fnv_00980a30__CombatController.h"
#include "fnv/decl/fnv_009926e0__CombatBox.h"
#include "fnv/decl/fnv_00992700__CombatBox.h"
#include "fnv/decl/fnv_009a02a0__FUN_009a02a0_struct.h"
#include "fnv/decl/fnv_009a0f40__FUN_009a0f40_struct.h"
#include "fnv/decl/fnv_009a5f90__FUN_009a5f90_shell.h"
#include "fnv/decl/s575ca0__Owner.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00430000.h"
#include "fnv/symbols_00435000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_0047e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_00524000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005a4000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005d8000.h"
#include "fnv/symbols_006a8000.h"
#include "fnv/symbols_006d7000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_0098e000.h"
#include "fnv/symbols_009a6000.h"
#include "fnv/symbols_009a9000.h"
#include "fnv/symbols_00c56000.h"
#include "fnv/symbols_00c58000.h"
#include "fnv/symbols_00c5a000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_0106d000.h"
#include "fnv/symbols_0108d000.h"
#include "fnv/symbols_011a4000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f1000.h"
struct FUN_00985980_shell
{
    float f0;
    float f4;
    float f8;
    float fc;
    void* p10;
    void CopyFrom(FUN_00985980_shell* other);
};

// Copies f8, fc and p10 from another instance into this one.
// @fnv 0x00985980
void FUN_00985980_shell::CopyFrom(FUN_00985980_shell* other)
{
    f8 = other->f8;
    fc = other->fc;
    p10 = other->p10;
}

struct ArrHelper
{
};

struct FUN_00986c40_shell
{
    char pad[0x18];
    ArrHelper arr;
    bool FUN_00986c40() const;
};

// @fnv 0x00986c40
bool FUN_00986c40_shell::FUN_00986c40() const
{
    return reinterpret_cast<::FUN_0076b610_Class *>((void *)&(arr))->FUN_0076b610();
}

struct FUN_0096a2b0_stub
{
    void FUN_0096a2b0(int state);
};

void FUN_0096a2b0_stub::FUN_0096a2b0(int state)
{}

struct FUN_009871c0_shell
{
    void FUN_009871c0(int state);
};

// @fnv 0x009871c0
void FUN_009871c0_shell::FUN_009871c0(int state)
{
    ((FUN_0096a2b0_stub*)((char*)this + 8))->FUN_0096a2b0(state);
}


struct FUN_009871e0_shell
{
    bool __thiscall IsModifierZero();
};

// Returns whether the float at offset 0x5c of this object equals _gModifierZero.
// @fnv 0x009871e0
bool __thiscall FUN_009871e0_shell::IsModifierZero()
{
    return (*(float*)((char*)this + 0x5c)) == ::_DAT_01012060;
}

struct ArrSI
{
};

struct FUN_009877c0_shell : ArrSI
{
    unsigned int GetFlagsFromSubobject();
};

// @fnv 0x009877c0
unsigned int FUN_009877c0_shell::GetFlagsFromSubobject()
{
    return ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x138))))->GetName()));
}

struct GlobalObject_00869f00
{
};

struct FUN_009877e0_shell
{
    void ClearGlobalObject();
};

// @fnv 0x009877e0
void FUN_009877e0_shell::ClearGlobalObject()
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)((char*)this + 0x138))))->Clear(true);
}

struct FUN_00987800_shell
{
    char GetByteAtOffset154();
};

// @fnv 0x00987800
char FUN_00987800_shell::GetByteAtOffset154()
{
    return ((char*)this)[0x154];
}

namespace fnv_00988750 {
struct ArrSI
{
};

struct FUN_00988750_shell
{
    unsigned int GetFlags() const;
};

// @fnv 0x00988750
unsigned int FUN_00988750_shell::GetFlags() const
{
    return ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((void *)(((ArrSI*)(this + 0x110))))->GetName()));
}
}  // namespace fnv_00988750

struct FUN_0098ebc0_obj
{
};

struct FUN_00988770_shell
{
    void __thiscall ForwardToMember(int a1);
};

struct BSSimpleArray_NavMeshSearchNode
{
    void FUN_006dad90(unsigned int) const;
};

struct FUN_00988790_shell
{
    char pad[0x18];
    BSSimpleArray_NavMeshSearchNode m_aiIndexedValues;
    void FUN_00988790(unsigned int idx) const;
};

// @fnv 0x00988790
void FUN_00988790_shell::FUN_00988790(unsigned int auiIndex) const
{
    m_aiIndexedValues.FUN_006dad90(auiIndex);
}

struct ActorCombatGroup
{
    void* __thiscall FUN_009865d0(int);
    unsigned char __thiscall GetByteAtOffset100(int);
};

void* __thiscall ActorCombatGroup::FUN_009865d0(int)
{
    return 0;
}

// Calls FUN_009865d0 with arg; if it returns non-null, returns byte at offset 0x64, otherwise 0.
// @fnv 0x009891a0
unsigned char __thiscall ActorCombatGroup::GetByteAtOffset100(int arg)
{
    void* result = FUN_009865d0(arg);
    if (result)
        return ((unsigned char*)result)[0x64];
    return 0;
}

struct FUN_0098a310_shell
{
    int m_field;
    int __thiscall GetFieldOrZero(int param);
};

struct FUN_009865f0_stub
{
    int m_kPointA;
    int m_field;
};

struct FUN_009865f0_shell
{
    int __thiscall FUN_009865f0(int a1);
};
// Calls FUN_009865f0 with param and returns the resulting object's m_field, or 0 if the call returns null.
// @fnv 0x0098a310
int __thiscall FUN_0098a310_shell::GetFieldOrZero(int param)
{
    FUN_009865f0_stub* result = ((::FUN_009865f0_stub *)(reinterpret_cast<::FUN_009865f0_shell *>((reinterpret_cast<FUN_009865f0_stub*>(this)))->FUN_009865f0(param)));
    if (result)
        return result->m_field;
    return 0;
}

int __thiscall FUN_009865f0_shell::FUN_009865f0(int a1)
{
    return 0;
}

struct FUN_0098a360_shell
{
    void __thiscall FUN_0098a360(int a1, int a2);
};

// Calls FUN_009865f0 with a1; if it returns non-null, stores a2 at offset 4 of the result.
// @fnv 0x0098a360
void __thiscall FUN_0098a360_shell::FUN_0098a360(int a1, int a2)
{
    int v1 = ((FUN_009865f0_shell*)this)->FUN_009865f0(a1);
    if (v1 != 0)
        *(int*)(v1 + 4) = a2;
}

struct BSSimpleArray
{
};

struct FUN_0098de60_shell
{
    unsigned char pad[0x138];
    BSSimpleArray arr;  // +0x138
    int GetArrayItem(char index);
};

// Returns 0 if index is negative, otherwise returns the element at index from arr.
// @fnv 0x0098de60
int FUN_0098de60_shell::GetArrayItem(char index)
{
    if (index < 0)
        return 0;
    return ((unsigned int)(reinterpret_cast<::S3e60 *>(&(arr))->FUN_006a7ad0(index)));
}

extern int DAT_0108d6f4;

struct FUN_0098ed30_class
{
    void* vtable;
    void* FUN_0098ed30();
};

struct FUN_0098efa0_shell
{
    void* __thiscall FUN_0098efa0(int count);
};

// Allocates a byte array of count * 0x68 bytes and returns the pointer.
// @fnv 0x0098efa0
void* FUN_0098efa0_shell::FUN_0098efa0(int count)
{
    return new char[count * 0x68];
}


struct FUN_0098efd0_shell
{
    void* __thiscall FUN_0098efd0(void* a, unsigned int b);
};

// @fnv 0x0098efd0
void* __thiscall FUN_0098efd0_shell::FUN_0098efd0(void* a, unsigned int b)
{
    return ::Reallocate(a, b * 0x68);
}

namespace fnv_0098f020 {
struct GlobalObject_00869f00
{
};


struct FUN_0098f020_shell
{
    int m_iWordAt00;
    void ResetGlobalObject();
};

// @fnv 0x0098f020
void FUN_0098f020_shell::ResetGlobalObject()
{
    m_iWordAt00 = (int)&::DAT_0108d708;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_0098f020

struct BGSLoadFormBuffer
{
};

struct FUN_00985a50_shell
{
    float f0;
    float f4;
    float f8;
    float fc;
    void* p10;
    void FUN_00985a50(BGSLoadFormBuffer* buffer, FUN_0098de60_shell* obj);
};

// @fnv 0x00985a50
void FUN_00985a50_shell::FUN_00985a50(BGSLoadFormBuffer* buffer, FUN_0098de60_shell* obj)
{
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(this));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&f4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&f8), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&fc), 4);
    char c = -1;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&c), 1);
    if (c != -1)
        p10 = (void*)obj->GetArrayItem(c);
    else
        p10 = 0;
}

struct BGSSaveFormBuffer
{
};

struct FUN_00985ae0_shell
{
    void __thiscall FUN_00985ae0(BGSSaveFormBuffer* buffer, int a1);
};

// Writes the object's first 0x10 bytes and the 4 bytes at offset 0x10 to the save buffer.
// @fnv 0x00985ae0
void __thiscall FUN_00985ae0_shell::FUN_00985ae0(BGSSaveFormBuffer* buffer, int aiUnused)
{
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(this, 0x10, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 0x10, 4, 0);
}

struct FUN_00985b10_shell
{
    void __thiscall FUN_00985b10(BGSLoadFormBuffer* buffer, int a2);
};
// @fnv 0x00985b10
void __thiscall FUN_00985b10_shell::FUN_00985b10(BGSLoadFormBuffer* buffer, int aiUnused)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(this), 0x10);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x10)), 4);
}

struct CombatTarget
{
    char m_data[0x68];
};

struct BSSimpleArray_CombatTarget_1024
{
    void* __pad;
    void* pBuffer;
    unsigned int __thiscall FUN_0098eec0(const CombatTarget* aValue);
public:
    void FUN_0098fab0(unsigned int, unsigned int);
};
// Sets the vtable to DAT_0108d6f4, calls FUN_0098fab0 with 0 and 0, and returns this.
// @fnv 0x0098ed30
void* FUN_0098ed30_class::FUN_0098ed30()
{
    vtable = &DAT_0108d6f4;
    reinterpret_cast<::BSSimpleArray_CombatTarget_1024 *>(this)->FUN_0098fab0(0, 0);
    return this;
}

struct FUN_0098fbe0_shell
{
};
struct FUN_0098eff0_shell
{
    void* vtable;
    void* __thiscall FUN_0098eff0();
};

struct TESForm
{
    virtual ~TESForm()
    {}
public:
    bool GetInitialized() const;
};
struct Actor : public TESForm
{
    virtual ~Actor()
    {}
};
struct Holder00985930
{
    unsigned int m_data;
    void __thiscall FUN_00985930(int a1, int a2);
};
// @fnv 0x00985930
void __thiscall Holder00985930::FUN_00985930(int a1, int aiUnused)
{
    *(Actor**)&m_data = m_data ? dynamic_cast<Actor*>(::FUN_004839c0(m_data)) : (Actor*)0;
}

struct FUN_0098f560
{
    char data[16];
    ~FUN_0098f560();
};
struct FUN_009863b0
{
    char pad[24];
    FUN_0098f560 m18;
    FUN_0098f560 m28;
    ~FUN_009863b0();
};
// Destructor for a structure holding two 16-byte members, destroying both in turn.
// @fnv 0x009863b0
FUN_009863b0::~FUN_009863b0()
{}

struct FUN_009865b0_shell : ActorCombatGroup
{
    bool FUN_009865b0(int param);
};

// @fnv 0x009865b0
bool FUN_009865b0_shell::FUN_009865b0(int param)
{
    return (FUN_009865d0(param) != 0) ? true : false;
}

namespace fnv_009866d0 {
struct Actor
{
};
struct FUN_00903600_shell
{
};
struct FUN_00990890_shell
{
};
struct FUN_009866d0_shell
{
    bool __thiscall FUN_009866d0(Actor* target);
};
// Iterates the actors in this collection and returns false as soon as one actor fails FUN_008b0670 on target; otherwise returns true.
// @fnv 0x009866d0
bool __thiscall FUN_009866d0_shell::FUN_009866d0(Actor* target)
{
    unsigned int count = reinterpret_cast<::FUN_00990890_shell *>((((FUN_00990890_shell*)this)))->FUN_00990890();
    for (unsigned int i = 0; i < count; ++i)
    {
        Actor* actor = ((::fnv_009866d0::Actor *)(reinterpret_cast<::Target *>((((FUN_00903600_shell*)this)))->GetIntAt(i)));
        if (actor && !reinterpret_cast<::fnv_008b0670::MyActor *>((actor))->FUN_008b0670((::Actor *)(target)))
            return false;
    }
    return true;
}
}  // namespace fnv_009866d0

struct FUN_00986950_shell
{
    void* p0;
    int a4;
    float f8;
    float fc;
    void* p10;
    void* __thiscall FUN_00986950(void* a1);
};
// Stores a1 into p0 and resets a4 to 0, f8 and fc to -1.0, and p10 to null, then returns this.
// @fnv 0x00986950
void* __thiscall FUN_00986950_shell::FUN_00986950(void* a1)
{
    p0 = a1;
    a4 = 0;
    f8 = -1.0f;
    fc = -1.0f;
    p10 = 0;
    return this;
}

struct FUN_00986a80_shell : public FUN_009865f0_shell
{
    char __thiscall FUN_00986a80(int param);
};
// @fnv 0x00986a80
char __thiscall FUN_00986a80_shell::FUN_00986a80(int param)
{
    return (FUN_009865f0(param) != 0);
}

namespace fnv_00986aa0 {
struct PathingSolution
{
};
struct Actor
{
};
struct FUN_005a4320_shell
{
};
struct FUN_008b0670_shell
{
};
struct FUN_00986aa0_shell : PathingSolution
{
    bool __thiscall FUN_00986aa0(Actor* actor);
};
// @fnv 0x00986aa0
bool __thiscall FUN_00986aa0_shell::FUN_00986aa0(Actor* actor)
{
    unsigned int count = ::FUN_005a4320((char *)this);
    for (unsigned int i = 0; i < count; ++i)
    {
        Actor* target = ((::fnv_00986aa0::Actor *)(reinterpret_cast<::FUN_00968630_stub *>((reinterpret_cast<FUN_005a4320_shell*>(this)))->FUN_00968630(i)));
        if (!reinterpret_cast<::fnv_008b0670::MyActor *>((reinterpret_cast<FUN_008b0670_shell*>(actor)))->FUN_008b0670((::Actor *)(target)))
            return false;
    }
    return true;
}
}  // namespace fnv_00986aa0

struct FUN_009874b0_shell : ActorCombatGroup
{
    void __thiscall FUN_009874b0(int a1);
};

// Calls FUN_009865d0 with a1 to get a CombatTarget and, if non-null, increments the ushort at offset 0x4a in its m_data.
// @fnv 0x009874b0
void __thiscall FUN_009874b0_shell::FUN_009874b0(int a1)
{
    CombatTarget* pcombatTarget;
    pcombatTarget = (CombatTarget*)FUN_009865d0(a1);
    if (pcombatTarget)
        ++((unsigned short*)pcombatTarget->m_data)[0x4a / 2];
}

struct S_009874f0
{
    char pad[0x4A];
    short f4A;
};
struct FUN_009874f0_obj
{
    void __thiscall DecrementField4A(int);
};
// Retrieves an object via FUN_009865d0 and, if non-null, decrements its f4A field.
// @fnv 0x009874f0
void __thiscall FUN_009874f0_obj::DecrementField4A(int a1)
{
    S_009874f0* p = (S_009874f0*)reinterpret_cast<ActorCombatGroup*>(this)->FUN_009865d0(a1);
    if (p)
        p->f4A--;
}

struct ThreeInts_00989010
{
    int a;
    int b;
    int c;
};
struct StandIn_00989010
{
    ThreeInts_00989010 t;
    int v;
    void __thiscall SetTripleAndValue(ThreeInts_00989010* src, int val);
};
// Copies the three-int struct pointed to by src into t and stores val in v.
// @fnv 0x00989010
void __thiscall StandIn_00989010::SetTripleAndValue(ThreeInts_00989010* apTriple, int aiValue)
{
    t = *apTriple;
    v = aiValue;
}

class BGSLoadGameBuffer;
struct CombatTargetTimestamp
{
    int v;
public:
    float FUN_006a7f50() const;
public:
    void LoadGame(::BGSLoadGameBuffer *);
};
struct MyClass
{
    int GetResultForArg(int arg);
    void UpdateTargetPerception(int a1, int a2, int* a3, CombatTargetTimestamp* a4, bool* a5, bool* a6);
};
// @fnv 0x00989040
int MyClass::GetResultForArg(int arg)
{
    int result;
    bool b1;
    CombatTargetTimestamp stamp;
    bool b2;
    result = -100;
    FUN_004300a0(&stamp);
    b1 = false;
    b2 = false;
    UpdateTargetPerception(0, arg, &result, &stamp, &b1, &b2);
    return result;
}

namespace fnv_00989090 {
struct Actor
{
};
struct CombatTargetTimestamp
{
    float m;
    CombatTargetTimestamp(float f);
};
struct CombatTargetHack
{
    char pad[0x50];
    CombatTargetTimestamp ts;
};
struct Holder : ActorCombatGroup
{
    CombatTargetTimestamp GetCombatTargetTimestamp(Actor* apTarget);
};
// Looks up the combat target for apTarget and returns its timestamp, or the negated DAT_0108d540 if none is found.
// @fnv 0x00989090
CombatTargetTimestamp Holder::GetCombatTargetTimestamp(Actor* apTarget)
{
    CombatTarget* pcombatTarget;
    pcombatTarget = (CombatTarget*)FUN_009865d0((int)apTarget);
    if (pcombatTarget)
        return ((CombatTargetHack*)pcombatTarget)->ts;
    return CombatTargetTimestamp(-::DAT_0108d540);
}
}  // namespace fnv_00989090

namespace fnv_009890e0 {
struct Actor
{
};
struct TESForm
{
};
struct CoordinateTriple
{
    float _00;
    float _04;
    float _08;
    void* _0c;
};
struct CombatGroupStub
{
    bool __thiscall GetDetectedTargetLocation(Actor* apTarget, CoordinateTriple& arLastDetectedLocation);
};
// @fnv 0x009890e0
bool __thiscall CombatGroupStub::GetDetectedTargetLocation(Actor* apTarget, CoordinateTriple& arLastDetectedLocation)
{
    CombatTarget* pcombatTarget;
    pcombatTarget = (CombatTarget*)((ActorCombatGroup*)this)->FUN_009865d0((int)apTarget);
    if (pcombatTarget != 0)
    {
        if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((CoordinateTriple*)((char*)pcombatTarget + 0x18))))->FUN_0084e3a0())))
        {
            arLastDetectedLocation = *((CoordinateTriple*)((char*)pcombatTarget + 0x18));
            return true;
        }
    }
    return false;
}
}  // namespace fnv_009890e0

struct Calendar
{
};
struct TESAmmoInitCalls
{
};
struct FUN_009891d0_class
{
    char _pad[0x28];
    int m28;
    void __thiscall FUN_009891d0(TESAmmoInitCalls* p1, Calendar* p2);
};
// @fnv 0x009891d0
void __thiscall FUN_009891d0_class::FUN_009891d0(TESAmmoInitCalls* p1, Calendar* pCalendar)
{
    unsigned int v2;
    if (m28 != 0)
    {
        unsigned int v1;
        v1 = ((unsigned int)(::GetFieldBC((::FUN_0097ae90_Class *)(p1))));
        v2 = ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((pCalendar))->FUN_009611e0()));
        if (v2 != 0)
        {
            if (((FUN_0098a310_shell*)this)->GetFieldOrZero(v1) == (int)v2)
            {
                ((FUN_0098a360_shell*)this)->FUN_0098a360(v1, 0);
            }
        }
    }
}

struct Ref_997440
{
};
struct S989970
{
    void __thiscall FUN_00989970(Ref_997440* p, float f);
};
struct B16
{
    int a;
    int b;
    int c;
    int d;
};
struct FUN_0098a340_shell
{
    int __thiscall FUN_0098a340(int a1);
};
struct FUN_0098a410_shell
{
    void* FindByValue(unsigned int value);
};
// @fnv 0x0098a410
void* FUN_0098a410_shell::FindByValue(unsigned int value)
{
    unsigned int count = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    for (unsigned int i = 0; i < count; ++i)
    {
        if (((FUN_0098a340_shell*)this)->FUN_0098a340(i) == value)
            return ((void *)(reinterpret_cast<::Target *>(this)->GetIntAt(i)));
    }
    return 0;
}

extern int DAT_011f18b4[];

// @fnv 0x0098e980
int __cdecl FUN_0098e980(int index)
{
    return DAT_011f18b4[index];
}

struct CombatClusterMember
{
    void* pActor;
    unsigned int m_uiGoalFlags;
    float m_fClusterOffsetX;
    float m_fClusterOffsetY;
    void* pCluster;
};
struct BSSimpleArray_CombatMember_1024
{
    void* __pad;
    CombatClusterMember* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int __thiscall AddCombatMember(const CombatClusterMember* aValue);
public:
    void FUN_0098fbe0(unsigned int, unsigned int);
};
struct CTSHelper
{
    char _pad[8];
};
struct FUN_00985bb0_Class
{
    char _pad[16];
    CTSHelper _ts;
    float _f18;
    float __thiscall FUN_00985bb0();
};
// Returns the difference between the stored _f18 value and the elapsed time from _ts.
// @fnv 0x00985bb0
float __thiscall FUN_00985bb0_Class::FUN_00985bb0()
{
    return _f18 - reinterpret_cast<::FUN_00435e00_t *>(&(_ts))->FUN_00435e00();
}

struct FUN_00986560_shell
{
    char pad[8];
    void __thiscall FUN_00986560(int a1);
};
struct FUN_0098ef10_shell
{
    void* __thiscall FUN_0098ef10(int a1);
};
struct FUN_009926e0_shell
{
};
struct RefObj
{
};
struct SearchNode
{
    RefObj* p;
};
struct MyArr : ArrSI
{
    SearchNode* __thiscall FUN_006dad90(unsigned int) const;
};
struct C00986670
{
    char pad[0x18];
    MyArr arr;
    SearchNode* __thiscall FUN_00986670(unsigned int);
};
// Scans arr for the first SearchNode whose p->_ref_0084e3a0() equals a1 and returns it, or 0 if none match.
// @fnv 0x00986670
SearchNode* __thiscall C00986670::FUN_00986670(unsigned int a1)
{
    unsigned int i;
    for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr))->GetName())); i++)
    {
        SearchNode* n = arr.FUN_006dad90(i);
        if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((n->p))->FUN_0084e3a0())) == a1)
            return n;
    }
    return 0;
}

struct FUN_00986b70_shell : ActorCombatGroup
{
    void __thiscall FUN_00986b70();
};

struct FUN_00986b70_helper : ActorCombatGroup
{
};

struct Actor_vfn
{
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc(bool);
};

// Iterates all entries via GetCount/GetIntAt and calls vfn_3fc(false) on each actor.
// @fnv 0x00986b70
void __thiscall FUN_00986b70_shell::FUN_00986b70()
{
    unsigned int count = reinterpret_cast<::FUN_00990890_shell *>((((FUN_00986b70_helper*)this)))->FUN_00990890();
    for (unsigned int i = 0; i < count; ++i)
    {
        Actor_vfn* actor = (Actor_vfn*)((void *)(reinterpret_cast<::Target *>((((FUN_00986b70_helper*)this)))->GetIntAt(i)));
        actor->vfn_3fc(false);
    }
}

namespace fnv_009897a0 {
struct CTSHelper
{
};
struct Setting_S
{
};
class GameSettingCollection;
template <class T> class SettingT
{
};
struct Host
{
    char pad[0x50];
    CTSHelper stamp;
    bool IsElapsedTimeBelowSetting();
};
// Returns whether stamp.GetElapsedTime() is less than the float value of originalRuntimeFloatSetting412.
// @fnv 0x009897a0
bool Host::IsElapsedTimeBelowSetting()
{
    return (double)reinterpret_cast<::FUN_00435e00_t *>(&(stamp))->FUN_00435e00() < *(((float *)&(::FUN_00403e20((float *)(((Setting_S*)&(*reinterpret_cast<::fnv_009897a0::SettingT< ::fnv_009897a0::GameSettingCollection> *>(&::originalRuntimeFloatSetting412))))))));
}
}  // namespace fnv_009897a0

struct FUN_0098a2e0_shell
{
    char pad[0x14c];
    int m_kPointA;
    int m_kPointB;
    bool __thiscall FUN_0098a2e0();
};

// @fnv 0x0098a2e0
bool __thiscall FUN_0098a2e0_shell::FUN_0098a2e0()
{
    if (!m_kPointB && m_kPointA)
        return true;
    return false;
}

struct CombatGroup_GetCount
{
};
struct MyNode_0098a3c0
{
    int m0;
    int m1;
};
struct MyArr_0098a3c0
{
    MyNode_0098a3c0* __thiscall FUN_006dad90(unsigned int) const;
};
struct FUN_0098a3c0_shell
{
    char pad[0x18];
    MyArr_0098a3c0 arr;
    void __thiscall FUN_0098a3c0();
};
// Iterates over the array's nodes up to GetCount() and sets each node's m1 field to 0.
// @fnv 0x0098a3c0
void __thiscall FUN_0098a3c0_shell::FUN_0098a3c0()
{
    MyNode_0098a3c0* pNode;
    unsigned int idx;
    unsigned int cnt;
    cnt = reinterpret_cast<::FUN_00990890_shell *>((((CombatGroup_GetCount*)this)))->FUN_00990890();
    for (idx = 0; idx < cnt; idx++)
    {
        pNode = arr.FUN_006dad90(idx);
        pNode->m1 = 0;
    }
}

namespace fnv_0098a470 {
struct RegionPoint
{
};
struct CTSHelper
{
};
struct FUN_0098a470_shell
{
    char pad[0x40];
    unsigned int m_kPointA;
    RegionPoint p44;
    CTSHelper p45;
    bool FUN_0098a470(unsigned int a, float b);
};
// @fnv 0x0098a470
bool FUN_0098a470_shell::FUN_0098a470(unsigned int a, float fTime)
{
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(p44))->FUN_006a7f50() == ::_DAT_01012060)
        return true;
    if (m_kPointA != a)
        return true;
    if (reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)this + 0x44))))->FUN_00435e00() > fTime)
        return true;
    return false;
}
}  // namespace fnv_0098a470

struct CombatSearchDoor
{
    char pad[0x0a];
    bool bReserved;
};
struct FUN_0098c590_shell
{
    CombatSearchDoor* FindParentSpaceNode(int param);
};
struct FUN_0098c780_shell
{
    void ClearReservedFlag(int param);
};
// Looks up a CombatSearchDoor by param and clears its bReserved flag when found.
// @fnv 0x0098c780
void FUN_0098c780_shell::ClearReservedFlag(int param)
{
    CombatSearchDoor* psearchDoor = ((FUN_0098c590_shell*)this)->FindParentSpaceNode(param);
    if (psearchDoor)
        psearchDoor->bReserved = false;
}

struct FUN_0098ed60_shell : GlobalObject_00869f00
{
    void __thiscall FUN_0098ed60();
};
// @fnv 0x0098ed60
void __thiscall FUN_0098ed60_shell::FUN_0098ed60()
{
    *(void**)this = &DAT_0108d6f4;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(true);
}

struct S0098a4d0
{
};
struct FUN_00990500_host
{
    S0098a4d0* p0;
    char pad[16];
    float f14;
    float __thiscall GetCachedValue();
};
struct BGSEncounterZone;
struct ActorS
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual bool vfn_22c(int a);
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual bool vfn_2e8();
public:
    ::BGSEncounterZone *FUN_00567d90();
};
struct ActorX
{
};
struct Setting_S
{
};
struct GlobalObject_0045cfe0
{
};
struct AvoidSphere
{
};
struct Flt
{
    operator unsigned int();
};
struct RegionPoint
{
};
struct CombatMemberS
{
    ActorS* pActor;
    char pad04[0x44];
    unsigned short w48;
    unsigned short w4a;
};
struct CombatGroupS
{
    char pad00[0xd0];
    unsigned int ItemUpdateArray;
    Flt spSphere;
    bool FUN_00987220(CombatMemberS* pMember);
    void* FUN_00989880(ActorS* pActor, float fRadius);
};
// @fnv 0x00987220
bool CombatGroupS::FUN_00987220(CombatMemberS* pMember)
{
    if (((FUN_0098a2e0_shell*)this)->FUN_0098a2e0())
    {
        if (reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)pMember + 0x50))))->FUN_00435e00() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting403)))))))
            return true;
        if (reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)pMember + 0x50))))->FUN_00435e00() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting404)))))) &&
            !FUN_00989880(pMember->pActor, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting405))))))))
            return true;
    }
    if (reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)pMember + 0x58))))->FUN_00435e00() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting406)))))))
    {
        if (pMember->w4a == 0)
            return true;
        if (reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)pMember + 0x58))))->FUN_00435e00() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting407)))))))
        {
            bool bnoSphere = false;
            if (ItemUpdateArray == 1 && spSphere && reinterpret_cast<::BSMultiBoundSphere *>((void *)(((AvoidSphere*)(unsigned int)spSphere)))->GetRadius() == 0.0)
                bnoSphere = true;
            if (bnoSphere || !FUN_00989880(pMember->pActor, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting408))))))))
                return true;
        }
    }
    if (ItemUpdateArray != 0)
    {
        if (ItemUpdateArray > pMember->w48 + *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::GlobalObject_0045cfe0 *>(&::g_011cef50)))))))
            return true;
        if (reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)this + 0xe8))))->FUN_00435e00() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting410)))))) &&
            reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)pMember + 0x60))))->FUN_00435e00() >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting410)))))) &&
            reinterpret_cast<::CombatTargetTimestamp *>((((RegionPoint*)((char*)pMember + 0x50))))->FUN_006a7f50() == -DAT_0108d540 &&
            reinterpret_cast<::FUN_00435e00_t *>((((CTSHelper*)((char*)pMember + 0x58))))->FUN_00435e00() > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting409)))))))
            return true;
    }
    if (((bool)(reinterpret_cast<::FUN_00437bd0_stub *>((((ActorX*)pMember->pActor)))->FUN_00437bd0())) || (pMember->pActor->vfn_22c(0) && !pMember->pActor->vfn_2e8()))
        return true;
    return false;
}

struct FUN_0098de30_class
{
    unsigned char FUN_0098de30(unsigned int*);
};
struct FUN_009859c0_shell
{
    void __thiscall FUN_009859c0(BGSSaveFormBuffer* buffer, FUN_0098de30_class* obj);
};
struct SaveFormIDHelper
{
};
// Saves the form ID, three 4-byte fields, and a byte derived from the object at offset 16 (0xFF if null) to the buffer.
// @fnv 0x009859c0
void __thiscall FUN_009859c0_shell::FUN_009859c0(BGSSaveFormBuffer* buffer, FUN_0098de30_class* obj)
{
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((SaveFormIDHelper*)buffer)))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)this), 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 4, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 8, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((char*)this + 12, 4, 0);
    char result = 0xFF;
    if (*(unsigned int*)((char*)this + 16))
        result = obj->FUN_0098de30(*(unsigned int**)((char*)this + 16));
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&result, 1, 0);
}

struct ActorV
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
    virtual const char* V130();
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
    virtual void* V1d0();
};
class PerkEntryConditionSet;
struct BGSCameraPath
{
    int HasNameForWarning();
public:
    ::PerkEntryConditionSet *GetConditions();
};
struct MobileObject
{
};
struct FormIDStandIn
{
};
struct S00986a80
{
};
struct S00986aa0
{
};
struct S00992700
{
};
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
int __cdecl FUN_005d8550(unsigned int);
struct P3
{
    float x, y, z;
};
struct RgbaColor
{
    float r, g, b, a;
};
struct FUN_0097f220_t
{
};
struct CombatGroup_009867d0
{
    unsigned int m_uiActorFormID;
    bool FUN_009867d0(ActorV* apActor);
};

// @fnv 0x009867d0
bool CombatGroup_009867d0::FUN_009867d0(ActorV* apActor)
{
    RgbaColor colorA;
    P3 color;
    if (!apActor)
        return false;
    if (((bool)(reinterpret_cast<::FUN_00986a80_shell *>((((S00986a80*)this)))->FUN_00986a80((int)(apActor)))))
        return true;
    if (!reinterpret_cast<::fnv_00986aa0::FUN_00986aa0_shell *>((((S00986aa0*)this)))->FUN_00986aa0((::fnv_00986aa0::Actor *)(apActor)))
        return false;
    if (((FUN_009865b0_shell*)this)->FUN_009865b0((int)apActor))
    {
        ::FUN_005b5e40();
        return false;
    }
    {
        FUN_00986950_shell member;
        ((BSSimpleArray_CombatMember_1024*)((char*)this + 0x18))
            ->AddCombatMember((const CombatClusterMember*)member.FUN_00986950(apActor));
    }
    reinterpret_cast<::fnv_00992700::CombatBox *>((((S00992700*)(*reinterpret_cast<void * *>(&::BGSSaveLoadGlobalDataWorldspacePtr)))))->FUN_00992700((unsigned int)(this), (unsigned int)(apActor));
    if (*::g_011f1878.Bool() && apActor->V1d0())
    {
        colorA = *(RgbaColor*)FUN_005d8550(m_uiActorFormID);
        reinterpret_cast<::FUN_00416870_t *>(&(color))->FUN_00416870(colorA.r, colorA.g, colorA.b);
        ::FUN_004b6360((::NiAVObject *)(void *)(apActor->V1d0()), (const ::NiPoint3 *)(::P3 *)(&color), (::FUN_00b668b0 *)(0));
    }
    reinterpret_cast<::FUN_0097f220_Class *>((((FUN_0097f220_t*)((char*)this + 0xb0))))->FUN_0097f220();
    return true;
}

struct FUN_0072ba80_shell
{
    void FUN_0072ba80(void*, unsigned int);
};

struct FUN_0098f040_shell
{
    CombatClusterMember* pBuffer;
    unsigned int iSize;
    unsigned int iAllocSize;
    virtual void v0();
    virtual CombatClusterMember* Allocate(unsigned int);
    void FUN_0098f040(unsigned int auiNewSize, bool abFreeMemory);
};

struct FUN_00986500_shell : ActorCombatGroup
{
    void RemoveByTarget(int target);
};
struct FUN_0096a2b0_stub2
{
    CombatTarget* FUN_0096a2b0(int i);
};
// Scans the array at this+8 for a CombatTarget whose first int equals target, then calls FUN_00986560 with that index and returns.
// @fnv 0x00986500
void FUN_00986500_shell::RemoveByTarget(int target)
{
    for (int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 8))))->GetName())); ++i)
    {
        CombatTarget* combatTarget = ((FUN_0096a2b0_stub2*)((char*)this + 8))->FUN_0096a2b0(i);
        if (*(int*)combatTarget == target)
        {
            reinterpret_cast<::FUN_00986560_shell *>(this)->FUN_00986560(i);
            return;
        }
    }
}

struct _ref_0084e3a0_fn
{
};

struct FUN_00986610_shell
{
    char pad[8];
    BSSimpleArray_CombatMember_1024 arr;
    void* FUN_00986610(unsigned int value);
};

// Scans the combat member array for the first member whose actor's FUN_0084e3a0 result equals value, returning it or null.
// @fnv 0x00986610
void* FUN_00986610_shell::FUN_00986610(unsigned int value)
{
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 8))))->GetName())); ++i)
    {
        CombatClusterMember* m = (CombatClusterMember*)((FUN_0098ef10_shell*)((char*)this + 8))->FUN_0098ef10(i);
        if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((_ref_0084e3a0_fn*)m->pActor)))->FUN_0084e3a0())) == value)
            return m;
    }
    return 0;
}

struct XIdle;
struct XArr
{
    void SetAt(unsigned int, XIdle*);
};
struct _Mem_20a4
{
};
struct FUN_00986b00_shell
{
    char pad[0x18];
    ArrSI arr;
    void CopyArrayTo(XArr* dst);
};
// Resizes dst to the source array's count and copies each element from arr into dst by index.
// @fnv 0x00986b00
void FUN_00986b00_shell::CopyArrayTo(XArr* dst)
{
    unsigned int i;
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((((_Mem_20a4*)dst)))->FUN_006f2290(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr))->GetName())), true);
    for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(arr))->GetName())); ++i)
        dst->SetAt(i, (XIdle*)((MyArr*)&arr)->FUN_006dad90(i));
}

struct Sky
{
    int a;
    int b;
};
struct SkyObject
{
};
struct FUN_00986bd0_shell : ActorCombatGroup
{
    void FUN_00986bd0();
};
// Iterates all members, calls SkyObject::Update on each with this and the member, then clears the object at offset 0x18.
// @fnv 0x00986bd0
void FUN_00986bd0_shell::FUN_00986bd0()
{
    unsigned int imemberCount = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    for (unsigned int i = 0; i < imemberCount; ++i)
    {
        Actor* pmember = ((::Actor *)(reinterpret_cast<::Target *>(this)->GetIntAt(i)));
        reinterpret_cast<::FUN_008d0600_s *>((reinterpret_cast<SkyObject*>((*reinterpret_cast<void * *>(&::BGSSaveLoadGlobalDataWorldspacePtr)))))->FUN_008d0600((int)(reinterpret_cast<Sky*>(this)), reinterpret_cast<int>(pmember));
    }
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<GlobalObject_00869f00*>(reinterpret_cast<char*>(this) + 0x18)))->Clear(false);
}

class CoordinateTriple
{
  public:
public:
    bool FUN_00527a00();
};

struct FUN_009a5f90_shell
{
};

struct FUN_009856e0_shell
{
    Actor* pActor;
    int m_field;
    char pad[0x60];

    void __thiscall FUN_009856e0(BGSSaveFormBuffer* pBuffer, ActorCombatGroup* pGroup);
};

// @fnv 0x009856e0
void __thiscall FUN_009856e0_shell::FUN_009856e0(BGSSaveFormBuffer* pBuffer, ActorCombatGroup* pGroup)
{
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((SaveFormIDHelper*)pBuffer)))->FUN_00865df0((::fnv_00865df0::TESForm *)(pActor), 0);

    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 4, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 0x48, 2, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 0x4A, 2, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 0x64, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pBuffer))->FUN_00865e50((char*)this + 0x65, 1, 0);

    reinterpret_cast<::FUN_00527b70_shell *>((((CoordinateTriple*)((char*)this + 8))))->FUN_00527b70((::BGSSaveGameBuffer *)(pBuffer));
    reinterpret_cast<::FUN_00527b70_shell *>((((CoordinateTriple*)((char*)this + 0x18))))->FUN_00527b70((::BGSSaveGameBuffer *)(pBuffer));
    reinterpret_cast<::FUN_00527b70_shell *>((((CoordinateTriple*)((char*)this + 0x28))))->FUN_00527b70((::BGSSaveGameBuffer *)(pBuffer));
    reinterpret_cast<::FUN_00527b70_shell *>((((CoordinateTriple*)((char*)this + 0x38))))->FUN_00527b70((::BGSSaveGameBuffer *)(pBuffer));

    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((((FUN_009a5f90_shell*)((char*)this + 0x50))))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((((FUN_009a5f90_shell*)((char*)this + 0x54))))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((((FUN_009a5f90_shell*)((char*)this + 0x58))))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((((FUN_009a5f90_shell*)((char*)this + 0x4C))))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((((FUN_009a5f90_shell*)((char*)this + 0x5C))))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pBuffer));
    reinterpret_cast<::fnv_009a5f90::FUN_009a5f90_shell *>((((FUN_009a5f90_shell*)((char*)this + 0x60))))->SaveTimeStamp((::fnv_009a5f90::BGSSaveFormBuffer *)(pBuffer));
}

struct FUN_00527ba0_Class
{
    char pad[0x10];
};

struct CombatTimeStampLoadGame
{
};

struct BGSLoadGameBufferVersion
{
    virtual unsigned char GetVersion();
};

struct FUN_00985800_shell
{
    void* pActor;
    int m4;
    FUN_00527ba0_Class m8;
    FUN_00527ba0_Class m18;
    FUN_00527ba0_Class m28;
    FUN_00527ba0_Class m38;
    char m48[2];
    char m4a[2];
    CombatTargetTimestamp m4c;
    CombatTargetTimestamp m50;
    CombatTargetTimestamp m54;
    CombatTargetTimestamp m58;
    CombatTargetTimestamp m5c;
    CombatTargetTimestamp m60;
    char m64;
    char m65;

    void __thiscall FUN_00985800(BGSLoadFormBuffer* pBuffer, ActorCombatGroup* pGroup);
};

// @fnv 0x00985800
void FUN_00985800_shell::FUN_00985800(BGSLoadFormBuffer* pBuffer, ActorCombatGroup* pGroup)
{
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((pBuffer))->FUN_008648e0((unsigned int *)(void *)(this));

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(m48), 2);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(m4a), 2);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m64), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m65), 1);

    reinterpret_cast<::FUN_00527ba0_This *>(&(m8))->FUN_00527ba0((::BGSLoadGameBuffer *)(pBuffer));
    reinterpret_cast<::FUN_00527ba0_This *>(&(m18))->FUN_00527ba0((::BGSLoadGameBuffer *)(pBuffer));
    reinterpret_cast<::FUN_00527ba0_This *>(&(m28))->FUN_00527ba0((::BGSLoadGameBuffer *)(pBuffer));

    if (reinterpret_cast<BGSLoadGameBufferVersion*>(pBuffer)->GetVersion() >= 0x0e)
        reinterpret_cast<::FUN_00527ba0_This *>(&(m38))->FUN_00527ba0((::BGSLoadGameBuffer *)(pBuffer));

    reinterpret_cast<::CombatTargetTimestamp *>((reinterpret_cast<CombatTimeStampLoadGame*>(&m50)))->LoadGame((::BGSLoadGameBuffer *)(pBuffer));
    reinterpret_cast<::CombatTargetTimestamp *>((reinterpret_cast<CombatTimeStampLoadGame*>(&m54)))->LoadGame((::BGSLoadGameBuffer *)(pBuffer));
    reinterpret_cast<::CombatTargetTimestamp *>((reinterpret_cast<CombatTimeStampLoadGame*>(&m58)))->LoadGame((::BGSLoadGameBuffer *)(pBuffer));
    reinterpret_cast<::CombatTargetTimestamp *>((reinterpret_cast<CombatTimeStampLoadGame*>(&m4c)))->LoadGame((::BGSLoadGameBuffer *)(pBuffer));
    reinterpret_cast<::CombatTargetTimestamp *>((reinterpret_cast<CombatTimeStampLoadGame*>(&m5c)))->LoadGame((::BGSLoadGameBuffer *)(pBuffer));

    if (reinterpret_cast<BGSLoadGameBufferVersion*>(pBuffer)->GetVersion() >= 0x0d)
        reinterpret_cast<::CombatTargetTimestamp *>((reinterpret_cast<CombatTimeStampLoadGame*>(&m60)))->LoadGame((::BGSLoadGameBuffer *)(pBuffer));
}

double DAT_0101db88;

struct ImageSpaceEffectParam
{
    float f0;
    float f4;
    float f8;
    float fc;

    ImageSpaceEffectParam(float, float, float, float);
};

struct FUN_00985be0_shell : public FUN_00985bb0_Class
{
    ImageSpaceEffectParam* GetEffectColor(ImageSpaceEffectParam* result);
};

// Reads a value from FUN_00985bb0 and returns a color: magenta above 50, blue above DAT_0101db88, otherwise yellow, all with alpha 0.5.
// @fnv 0x00985be0
ImageSpaceEffectParam* FUN_00985be0_shell::GetEffectColor(ImageSpaceEffectParam* result)
{
    ImageSpaceEffectParam color(0.0f, 0.0f, 0.0f, 0.0f);

    {
        float value = FUN_00985bb0_Class::FUN_00985bb0();

        if (value > 50.0)
        {
            color = ImageSpaceEffectParam(1.0f, 0.0f, 1.0f, 0.5f);
        }
        else if (value > DAT_0101db88)
        {
            color = ImageSpaceEffectParam(0.0f, 0.0f, 1.0f, 0.5f);
        }
        else
        {
            color = ImageSpaceEffectParam(1.0f, 1.0f, 0.0f, 0.5f);
        }

        *result = color;
    }

    return result;
}

struct NiAVObject
{
};


struct ActorDispatchBase
{
    virtual NiAVObject* M001() = 0;
    virtual NiAVObject* M002() = 0;
    virtual NiAVObject* M003() = 0;
    virtual NiAVObject* M004() = 0;
    virtual NiAVObject* M005() = 0;
    virtual NiAVObject* M006() = 0;
    virtual NiAVObject* M007() = 0;
    virtual NiAVObject* M008() = 0;
    virtual NiAVObject* M009() = 0;
    virtual NiAVObject* M010() = 0;
    virtual NiAVObject* M011() = 0;
    virtual NiAVObject* M012() = 0;
    virtual NiAVObject* M013() = 0;
    virtual NiAVObject* M014() = 0;
    virtual NiAVObject* M015() = 0;
    virtual NiAVObject* M016() = 0;
    virtual NiAVObject* M017() = 0;
    virtual NiAVObject* M018() = 0;
    virtual NiAVObject* M019() = 0;
    virtual NiAVObject* M020() = 0;
    virtual NiAVObject* M021() = 0;
    virtual NiAVObject* M022() = 0;
    virtual NiAVObject* M023() = 0;
    virtual NiAVObject* M024() = 0;
    virtual NiAVObject* M025() = 0;
    virtual NiAVObject* M026() = 0;
    virtual NiAVObject* M027() = 0;
    virtual NiAVObject* M028() = 0;
    virtual NiAVObject* M029() = 0;
    virtual NiAVObject* M030() = 0;
    virtual NiAVObject* M031() = 0;
    virtual NiAVObject* M032() = 0;
    virtual NiAVObject* M033() = 0;
    virtual NiAVObject* M034() = 0;
    virtual NiAVObject* M035() = 0;
    virtual NiAVObject* M036() = 0;
    virtual NiAVObject* M037() = 0;
    virtual NiAVObject* M038() = 0;
    virtual NiAVObject* M039() = 0;
    virtual NiAVObject* M040() = 0;
    virtual NiAVObject* M041() = 0;
    virtual NiAVObject* M042() = 0;
    virtual NiAVObject* M043() = 0;
    virtual NiAVObject* M044() = 0;
    virtual NiAVObject* M045() = 0;
    virtual NiAVObject* M046() = 0;
    virtual NiAVObject* M047() = 0;
    virtual NiAVObject* M048() = 0;
    virtual NiAVObject* M049() = 0;
    virtual NiAVObject* M050() = 0;
    virtual NiAVObject* M051() = 0;
    virtual NiAVObject* M052() = 0;
    virtual NiAVObject* M053() = 0;
    virtual NiAVObject* M054() = 0;
    virtual NiAVObject* M055() = 0;
    virtual NiAVObject* M056() = 0;
    virtual NiAVObject* M057() = 0;
    virtual NiAVObject* M058() = 0;
    virtual NiAVObject* M059() = 0;
    virtual NiAVObject* M060() = 0;
    virtual NiAVObject* M061() = 0;
    virtual NiAVObject* M062() = 0;
    virtual NiAVObject* M063() = 0;
    virtual NiAVObject* M064() = 0;
    virtual NiAVObject* M065() = 0;
    virtual NiAVObject* M066() = 0;
    virtual NiAVObject* M067() = 0;
    virtual NiAVObject* M068() = 0;
    virtual NiAVObject* M069() = 0;
    virtual NiAVObject* M070() = 0;
    virtual NiAVObject* M071() = 0;
    virtual NiAVObject* M072() = 0;
    virtual NiAVObject* M073() = 0;
    virtual NiAVObject* M074() = 0;
    virtual NiAVObject* M075() = 0;
    virtual NiAVObject* M076() = 0;
    virtual NiAVObject* M077() = 0;
    virtual NiAVObject* M078() = 0;
    virtual NiAVObject* M079() = 0;
    virtual NiAVObject* M080() = 0;
    virtual NiAVObject* M081() = 0;
    virtual NiAVObject* M082() = 0;
    virtual NiAVObject* M083() = 0;
    virtual NiAVObject* M084() = 0;
    virtual NiAVObject* M085() = 0;
    virtual NiAVObject* M086() = 0;
    virtual NiAVObject* M087() = 0;
    virtual NiAVObject* M088() = 0;
    virtual NiAVObject* M089() = 0;
    virtual NiAVObject* M090() = 0;
    virtual NiAVObject* M091() = 0;
    virtual NiAVObject* M092() = 0;
    virtual NiAVObject* M093() = 0;
    virtual NiAVObject* M094() = 0;
    virtual NiAVObject* M095() = 0;
    virtual NiAVObject* M096() = 0;
    virtual NiAVObject* M097() = 0;
    virtual NiAVObject* M098() = 0;
    virtual NiAVObject* M099() = 0;
    virtual NiAVObject* M100() = 0;
    virtual NiAVObject* M101() = 0;
    virtual NiAVObject* M102() = 0;
    virtual NiAVObject* M103() = 0;
    virtual NiAVObject* M104() = 0;
    virtual NiAVObject* M105() = 0;
    virtual NiAVObject* M106() = 0;
    virtual NiAVObject* M107() = 0;
    virtual NiAVObject* M108() = 0;
    virtual NiAVObject* M109() = 0;
    virtual NiAVObject* M110() = 0;
    virtual NiAVObject* M111() = 0;
    virtual NiAVObject* M112() = 0;
    virtual NiAVObject* M113() = 0;
    virtual NiAVObject* M114() = 0;
    virtual NiAVObject* M115() = 0;
    virtual NiAVObject* M116() = 0;
};

struct ActorDispatch : ActorDispatchBase
{
    virtual NiAVObject* M117() = 0;
};

struct FUN_0098f1f0_caller
{
};

struct FUN_009869a0_shell
{
    unsigned char pad00[0xEC];
    Actor* m_pActor;

    void FUN_009869a0(Actor* apActor);
};

// @fnv 0x009869a0
void FUN_009869a0_shell::FUN_009869a0(Actor* apActor)
{
    unsigned int i;
    CombatClusterMember* combatMember;

    for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<MyArr*>(reinterpret_cast<unsigned char*>(this) + 0x18)))->GetName())); ++i)
    {
        combatMember = reinterpret_cast<CombatClusterMember*>(
            reinterpret_cast<MyArr*>(reinterpret_cast<unsigned char*>(this) + 0x18)->FUN_006dad90(i));

        if (combatMember->pActor == apActor)
        {
            reinterpret_cast<::FUN_008d0600_s *>((reinterpret_cast<SkyObject*>((*reinterpret_cast<void * *>(&::BGSSaveLoadGlobalDataWorldspacePtr)))))->FUN_008d0600((int)(reinterpret_cast<Sky*>(this)), reinterpret_cast<int>(apActor));

            reinterpret_cast<::FUN_0098f1f0_Class *>((reinterpret_cast<FUN_0098f1f0_caller*>(reinterpret_cast<unsigned char*>(this) + 0x18)))->RemoveEntries(i, 1);

            if (*reinterpret_cast<Actor**>(reinterpret_cast<unsigned char*>(this) + 0xEC) == apActor)
                *reinterpret_cast<Actor**>(reinterpret_cast<unsigned char*>(this) + 0xEC) = 0;

            if (*::g_011f1878.Bool())
            {
                if (reinterpret_cast<ActorDispatch*>(apActor)->M117())
                    ::FUN_004b6630(reinterpret_cast<ActorDispatch*>(apActor)->M117());
            }

            break;
        }
    }
}

struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3 operator+(const NiPoint3& other) const;
public:
    bool FUN_004390c0(const ::NiPoint3 &);
public:
    float GetLengthSquared();
public:
    static const ::NiPoint3 ZERO;
};

struct B006815c0 : public NiPoint3
{
    B006815c0();
};

struct TESCombatStyle
{
public:
    float UpdateCombatStyle();
};

struct P3OperatorMinusHelper
{
    P3 operator-(const P3& other) const;
};


struct FUN_00989eb0_shell
{
    void __thiscall UpdateBoundsFromActors(B006815c0* points, int index);
    void __thiscall FUN_00989eb0(NiPoint3* result);
};

// @fnv 0x00989eb0
void FUN_00989eb0_shell::FUN_00989eb0(NiPoint3* result)
{
    B006815c0 points[8];

    this->UpdateBoundsFromActors(points, 0);

    *result = reinterpret_cast<::Point3_0053d280 *>((void *)(void *)&(const ::NiPoint3 &)((points[0] + points[7])))->FUN_0053d280(::DAT_010162c0);

    P3 difference = (*(::P3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((P3OperatorMinusHelper*)&points[0])))->FUN_00439ef0-((::NiPoint3 *)&(*(P3*)&points[7]), *(const ::NiPoint3 *)nullptr)));

    reinterpret_cast<::TESCombatStyle *>((void *)(((TESCombatStyle*)&difference)))->UpdateCombatStyle();
}

struct FUN_0098a390_shell
{
    char pad[0x18];
    MyArr m_aiIndexedValues;
    void __thiscall SetElementValue(unsigned int a1, unsigned int a2);
};

// @fnv 0x0098a390
void FUN_0098a390_shell::SetElementValue(unsigned int uiIndex, unsigned int uiValue)
{
    reinterpret_cast<CombatClusterMember*>(m_aiIndexedValues.FUN_006dad90(uiIndex))->m_uiGoalFlags = uiValue;
}

struct PathingSolution
{
};

namespace identity {
struct ActorCombatGroup
{
};

struct FUN_009871c0_shell
{
    S_009874f0* __thiscall FUN_009871c0(int index);
};
}

struct ActorVirtual
{
    virtual void f000();
    virtual void f001();
    virtual void f002();
    virtual void f003();
    virtual void f004();
    virtual void f005();
    virtual void f006();
    virtual void f007();
    virtual void f008();
    virtual void f009();
    virtual void f010();
    virtual void f011();
    virtual void f012();
    virtual void f013();
    virtual void f014();
    virtual void f015();
    virtual void f016();
    virtual void f017();
    virtual void f018();
    virtual void f019();
    virtual void f020();
    virtual void f021();
    virtual void f022();
    virtual void f023();
    virtual void f024();
    virtual void f025();
    virtual void f026();
    virtual void f027();
    virtual void f028();
    virtual void f029();
    virtual void f030();
    virtual void f031();
    virtual void f032();
    virtual void f033();
    virtual void f034();
    virtual void f035();
    virtual void f036();
    virtual void f037();
    virtual void f038();
    virtual void f039();
    virtual void f040();
    virtual void f041();
    virtual void f042();
    virtual void f043();
    virtual void f044();
    virtual void f045();
    virtual void f046();
    virtual void f047();
    virtual void f048();
    virtual void f049();
    virtual void f050();
    virtual void f051();
    virtual void f052();
    virtual void f053();
    virtual void f054();
    virtual void f055();
    virtual void f056();
    virtual void f057();
    virtual void f058();
    virtual void f059();
    virtual void f060();
    virtual void f061();
    virtual void f062();
    virtual void f063();
    virtual void f064();
    virtual void f065();
    virtual void f066();
    virtual void f067();
    virtual void f068();
    virtual void f069();
    virtual void f070();
    virtual void f071();
    virtual void f072();
    virtual void f073();
    virtual void f074();
    virtual void f075();
    virtual void f076();
    virtual void f077();
    virtual void f078();
    virtual void f079();
    virtual void f080();
    virtual void f081();
    virtual void f082();
    virtual void f083();
    virtual void f084();
    virtual void f085();
    virtual void f086();
    virtual void f087();
    virtual void f088();
    virtual void f089();
    virtual void f090();
    virtual void f091();
    virtual void f092();
    virtual void f093();
    virtual void f094();
    virtual void f095();
    virtual void f096();
    virtual void f097();
    virtual void f098();
    virtual void f099();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
    virtual void f177();
    virtual void f178();
    virtual void f179();
    virtual void f180();
    virtual void f181();
    virtual void f182();
    virtual void f183();
    virtual void f184();
    virtual void f185();
    virtual void f186();
    virtual void f187();
    virtual void f188();
    virtual void f189();
    virtual void f190();
    virtual void f191();
    virtual void f192();
    virtual void f193();
    virtual void f194();
    virtual void f195();
    virtual void f196();
    virtual void f197();
    virtual void f198();
    virtual void f199();
    virtual void f200();
    virtual void f201();
    virtual void f202();
    virtual void f203();
    virtual void f204();
    virtual void f205();
    virtual void f206();
    virtual void f207();
    virtual void f208();
    virtual void f209();
    virtual void f210();
    virtual void f211();
    virtual void f212();
    virtual void f213();
    virtual void f214();
    virtual void f215();
    virtual void f216();
    virtual void f217();
    virtual void f218();
    virtual void f219();
    virtual void f220();
    virtual void f221();
    virtual void f222();
    virtual void f223();
    virtual void f224();
    virtual void f225();
    virtual void f226();
    virtual void f227();
    virtual void f228();
    virtual void f229();
    virtual void f230();
    virtual void f231();
    virtual void f232();
    virtual void f233();
    virtual void f234();
    virtual void f235();
    virtual void f236();
    virtual void f237();
    virtual void f238();
    virtual void f239();
    virtual void f240();
    virtual void f241();
    virtual void f242();
    virtual void f243();
    virtual void f244();
    virtual void f245();
    virtual void f246();
    virtual void f247();
    virtual void f248();
    virtual void f249();
    virtual void f250();
    virtual void f251();
    virtual void f252();
    virtual void f253();
    virtual void f254();
    virtual void f255();
    virtual void f256();
    virtual void f257();
    virtual void f258();
    virtual void f259();
    virtual void f260();
    virtual void f261();
    virtual void f262();
    virtual void f263();
    virtual void f264();
    virtual void f265();
    virtual void f266();
    virtual int GetID();
};


struct FUN_0098cf70_shell
{
    void CountActorsPerNode();
};

// For each virtual node, resets f4A and counts non-player actors whose GetID matches the node's ID.
// @fnv 0x0098cf70
void FUN_0098cf70_shell::CountActorsPerNode()
{
    {
        unsigned int uiNodeCount = ::FUN_005a4320((char *)(reinterpret_cast<PathingSolution*>(this)));
        {
            unsigned int uiActorCount = reinterpret_cast<::FUN_00990890_shell *>((reinterpret_cast<identity::ActorCombatGroup*>(this)))->FUN_00990890();
            {
                unsigned int i = 0;
                for (; i < uiNodeCount; ++i)
                {
                    {
                        S_009874f0* target = reinterpret_cast<identity::FUN_009871c0_shell*>(this)->FUN_009871c0(i);
                        target->f4A = 0;
                        {
                            unsigned int j = 0;
                            for (; j < uiActorCount; ++j)
                            {
                                {
                                    Actor* actor = ((::Actor *)(reinterpret_cast<::Target *>((reinterpret_cast<identity::ActorCombatGroup*>(this)))->GetIntAt(j)));
                                    if (actor == (*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))
                                        continue;

                                    if (reinterpret_cast<ActorVirtual*>(actor)->GetID() ==
                                        *reinterpret_cast<int*>(target))
                                    {
                                        ++target->f4A;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

struct BSSimpleArrayActor
{
public:
    void FUN_0098f2f0(unsigned int, bool);
};

struct FUN_0098fa00_shell
{
};

struct AllocationBase
{
    virtual void Anchor()
    {}
    virtual CombatTarget* Allocate(unsigned int)
    {
        return 0;
    }
};

struct FUN_0098ed80_shell : public AllocationBase
{
    CombatTarget* m_buffer;
    unsigned int m_iElementCount;
    unsigned int m_pRayCursor;

    void __thiscall FUN_0098ed80(unsigned int, bool);
};

struct GlobalObject_0040e0b0
{
};

class BGSLoadFormBuffer;
struct TimeoutTimer
{
    bool CheckTimer();
public:
    void LoadGame(::BGSLoadFormBuffer *);
};

struct FUN_008d7f40_shell
{
    void FUN_008d7f40(float value);
};

struct InnerObj
{
};

struct FUN_0097fa50_Class
{
    bool FUN_0097fa50();
};

struct FUN_00986150_shell
{
    void FUN_00986150();
    void FUN_0098a580();
};


struct Pair8
{
    int a;
    int b;
};

struct Obj8
{
    int m0;
    int m4;
    Obj8();
    void* operator new(unsigned int size, void* where);
    void operator delete(void* p, void* where);
};

struct Walker8
{
    void __thiscall ConstructArray(Pair8* arr, unsigned int count);
};

// Placement-constructs an Obj8 in each of the count elements of arr.
// @fnv 0x00845300
void __thiscall Walker8::ConstructArray(Pair8* apPairs, unsigned int count)
{
    unsigned int i;
    for (i = 0; i < count; i++)
    {
        new (&apPairs[i]) Obj8();
    }
}

struct EventVector
{
    unsigned int x;
    unsigned int y;
    unsigned int z;
    unsigned int w;
};
struct TimeStamp
{
    unsigned int value;
};
struct TimeValue
{
    float value;
};
struct EventSource
{
};
struct EventRecord
{
    EventSource* source;
    unsigned int status;
    EventVector primary;
    EventVector secondary;
    EventVector tertiary;
    EventVector quaternary;
    unsigned short type;
    unsigned short subtype;
    TimeValue initialTime;
    TimeValue previousTime;
    TimeStamp start;
    TimeValue timeNow;
    TimeStamp last;
    TimeValue endTime;
    unsigned char started;
    unsigned char ended;
    EventRecord* Init(EventSource* src, unsigned short eventType);
};
// Initialises the event record from a source and event type: clears vectors and status, sets times, and copies the source's event vector into primary.
// @fnv 0x00985410
EventRecord* EventRecord::Init(EventSource* apSource, unsigned short eventType)
{
    source = apSource;
    status = 0;
    reinterpret_cast<::FUN_0097ede0_cls *>(&(primary))->FUN_0097ede0();
    reinterpret_cast<::FUN_0097ede0_cls *>(&(secondary))->FUN_0097ede0();
    reinterpret_cast<::FUN_0097ede0_cls *>(&(tertiary))->FUN_0097ede0();
    reinterpret_cast<::FUN_0097ede0_cls *>(&(quaternary))->FUN_0097ede0();
    type = eventType;
    subtype = 0;
    reinterpret_cast<::FUN_00435de0_ctor *>(&(initialTime))->FUN_00435de0(-DAT_0108d540);
    reinterpret_cast<::FUN_00435de0_ctor *>(&(previousTime))->FUN_00435de0(-DAT_0108d540);
    ::FUN_004300a0((::CombatTargetTimestamp *)&(start));
    reinterpret_cast<::FUN_00435de0_ctor *>(&(timeNow))->FUN_00435de0(FUN_00435dd0());
    ::FUN_004300a0((::CombatTargetTimestamp *)&(last));
    reinterpret_cast<::FUN_00435de0_ctor *>(&(endTime))->FUN_00435de0(-DAT_0108d540);
    started = 0;
    ended = 0;
    primary = (*(::EventVector *)(reinterpret_cast<::FUN_00575650_Class *>((apSource))->FUN_00575650({})));
    return this;
}

struct CombatStamp_985520
{
    float fTime;
};

struct Block16_985520
{
    int a;
    int b;
    int c;
    int d;
};

struct CombatMemberData_985520
{
    void* pActor;
    int iValue04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Block16_985520 m18;
    Block16_985520 m28;
    Block16_985520 m38;
    unsigned short w48;
    unsigned short w4A;
    CombatStamp_985520 m4C;
    CombatStamp_985520 m50;
    CombatStamp_985520 m54;
    CombatStamp_985520 m58;
    CombatStamp_985520 m5C;
    CombatStamp_985520 m60;
    unsigned char b64;
    unsigned char b65;

    void __thiscall MergeCombatData(CombatMemberData_985520* pOther);
};

// Merges another member's combat data into this one: takes max iValue04, copies newer timestamps with their blocks, and accumulates w4A, b64 and b65.
// @fnv 0x00985520
void CombatMemberData_985520::MergeCombatData(CombatMemberData_985520* pOther)
{
    if (iValue04 < pOther->iValue04)
        iValue04 = pOther->iValue04;
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(m50))->FUN_006a7f50() < reinterpret_cast<::CombatTargetTimestamp *>(&(pOther->m50))->FUN_006a7f50())
    {
        m50 = pOther->m50;
        m18 = pOther->m18;
    }
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(m4C))->FUN_006a7f50() < reinterpret_cast<::CombatTargetTimestamp *>(&(pOther->m4C))->FUN_006a7f50())
    {
        m4C = pOther->m4C;
        m28 = pOther->m28;
    }
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(m54))->FUN_006a7f50() < reinterpret_cast<::CombatTargetTimestamp *>(&(pOther->m54))->FUN_006a7f50())
        m54 = pOther->m54;
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(m58))->FUN_006a7f50() < reinterpret_cast<::CombatTargetTimestamp *>(&(pOther->m58))->FUN_006a7f50())
        m58 = pOther->m58;
    if (reinterpret_cast<::CombatTargetTimestamp *>(&(m60))->FUN_006a7f50() < reinterpret_cast<::CombatTargetTimestamp *>(&(pOther->m60))->FUN_006a7f50())
    {
        m60 = pOther->m60;
        m38 = pOther->m38;
    }
    w4A += pOther->w4A;
    b64 += pOther->b64;
    b65 += pOther->b65;
}

struct TimeInput
{
    float __thiscall FUN_00527a40(FUN_00985bb0_Class* owner);
};
extern float _DAT_0108d5a0;
extern double _DAT_0108d598;

struct CombatClock : FUN_00985bb0_Class
{
    float __thiscall GetAdjustedTime(TimeInput* timeInput);
};
// @fnv 0x00985b40
float CombatClock::GetAdjustedTime(TimeInput* timeInput)
{
    float elapsed;
    {
        float current = FUN_00985bb0();
        elapsed = timeInput->FUN_00527a40(this);
        elapsed = FUN_0040ebd0(elapsed, _DAT_0108d5a0);
        current -= elapsed / _DAT_0108d598;
        if (*reinterpret_cast<int*>(&_ts._pad[4]) != 0)
            current += ::DAT_01020758;
        return current;
    }
}

struct BSSimpleArrayForCall : BSSimpleArray
{
    void __thiscall CopyItemsTo(BSSimpleArrayForCall* other);
};

struct FUN_00986740_shell
{
    void* unk00;
    void* unk04;
    BSSimpleArrayForCall arr;

    void __thiscall FUN_00986740(FUN_00986740_shell* other);
};

void __thiscall BSSimpleArrayForCall::CopyItemsTo(BSSimpleArrayForCall* other)
{}

// @fnv 0x00986740
void __thiscall FUN_00986740_shell::FUN_00986740(FUN_00986740_shell* other)
{
    reinterpret_cast<::FUN_0098f580_class *>(&(other->arr))->CopyItemsTo((::FUN_0096a330_class *)(::BSSimpleArrayForCall *)(&arr));
}

struct FUN_00986760_sub
{
    void* __thiscall FUN_0096a2b0(int i);
};

struct FUN_00986760_arg
{
    void __thiscall FUN_0047a110(int i, void* p);
};

struct FUN_00986760_cls
{
    char pad[8];
    FUN_00986760_sub m_08;
    void __thiscall FUN_00986760(int a1);
};

// Passes the result of FUN_0044ddc0(1) to the argument's FUN_006f2290, then forwards each indexed element from FUN_0096a2b0 to FUN_0047a110.
// @fnv 0x00986760
void FUN_00986760_cls::FUN_00986760(int pTarget)
{
    unsigned int i;
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((((FUN_00986760_arg*)pTarget)))->FUN_006f2290(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_08))->GetName())), {});
    for (i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_08))->GetName())); i++)
    {
        ((FUN_00986760_arg*)pTarget)->FUN_0047a110(i, m_08.FUN_0096a2b0(i));
    }
}

struct Actor_987820;
struct Ctrl_987820
{
};
struct Actor_987820
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual struct Ctrl_987820* v266();
};
struct Group_987820
{
    void FUN_00987820(Actor_987820* apTarget);
};
// Calls FUN_00980a30 on each member's controller with apTarget, then calls RemoveByTarget if apTarget->v64() is nonzero.
// @fnv 0x00987820
void Group_987820::FUN_00987820(Actor_987820* apTarget)
{
    unsigned int p = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    unsigned int h;
    for (h = 0; h < p; ++h)
    {
        Actor_987820* j = ((::Actor_987820 *)(reinterpret_cast<::Target *>(this)->GetIntAt(h)));
        Ctrl_987820* e = j->v266();
        if (e)
        {
            reinterpret_cast<::fnv_00980a30::CombatController *>((e))->FUN_00980a30((int)(apTarget));
        }
    }
    if (apTarget->v64())
    {
        reinterpret_cast<::FUN_00986500_shell *>(this)->RemoveByTarget((int)(apTarget));
    }
}

struct ResultQuad
{
    unsigned int x, y, z, w;
};
struct ResultLookup
{
    void* FUN_009871c0(int);
};
struct ResultTimer
{
};
struct ResultQuery
{
    bool TryGetQuadForState(int state, ResultQuad* output, float threshold);
};
// Looks up a record for state; if found and threshold exceeds its timer value, copies the quad at offset 40 into output and returns true.
// @fnv 0x00989140
bool ResultQuery::TryGetQuadForState(int state, ResultQuad* output, float threshold)
{
    void* result = ((ResultLookup*)this)->FUN_009871c0(state);
    if (result && threshold > reinterpret_cast<::FUN_00435e00_t *>((((ResultTimer*)((char*)result + 76))))->FUN_00435e00())
    {
        *output = *(ResultQuad*)((char*)result + 40);
        return true;
    }
    return false;
}


struct B989230Stamp
{
    B989230Stamp(float fTime);

    unsigned int m_uiEventId;
};

struct B989230Quad
{
    float x;
    float y;
    float z;
    float w;
};

class B989230Ref
{
  public:
};

struct B989230Entry
{
    int unk00;
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
    B989230Quad m_kPathOffset;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    B989230Stamp m_kStamp;
};

class B989230Tracker
{
  public:
    void UpdateEntryFromRef(int iUnused, B989230Ref* pkRef);
};

// Looks up the entry for pkRef and, if found, refreshes its stamp from FUN_00435dd0 and its quad from pkRef->FUN_00575650.
// @fnv 0x00989230
void B989230Tracker::UpdateEntryFromRef(int iUnused, B989230Ref* pkRef)
{
    if (pkRef)
    {
        B989230Entry* pkEntry = ((::B989230Entry *)(reinterpret_cast<::ActorCombatGroup *>(this)->FUN_009865d0((int)(pkRef))));
        if (pkEntry)
        {
            B989230Stamp kStamp(FUN_00435dd0());
            pkEntry->m_kStamp = kStamp;
            pkEntry->m_kPathOffset = (*(::B989230Quad *)(reinterpret_cast<::FUN_00575650_Class *>((pkRef))->FUN_00575650({})));
        }
    }
}

struct AvoidVector
{
    float x, y, z;
};
struct AvoidPosition
{
    AvoidVector point;
    unsigned space;
    float FUN_00527a40(const AvoidPosition&);
};
struct AvoidActor
{
};
struct AvoidanceVectorData
{
    float x, y, z, r0, r1, r2, r3, r4, r5;
    AvoidanceVectorData(const AvoidVector&);
};
struct PathingAvoidNodeArray
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14;
    static void* operator new(unsigned);
    PathingAvoidNodeArray();
};
struct AvoidSetting
{
};
struct AvoidWork
{
    PathingAvoidNodeArray* BuildAvoidNodes(AvoidActor*, PathingAvoidNodeArray*);
};
// @fnv 0x009895a0
PathingAvoidNodeArray* AvoidWork::BuildAvoidNodes(AvoidActor* actor, PathingAvoidNodeArray* apExistingNodes)
{
    PathingAvoidNodeArray* h = apExistingNodes;
    unsigned p = ::FUN_005a4320((char *)this);
    float a = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AvoidSetting *>(&::originalRuntimeFloatSetting441)))))) * *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::AvoidSetting *>(&::originalRuntimeFloatSetting441))))));
    AvoidPosition i = (*(::AvoidPosition *)(reinterpret_cast<::FUN_00575650_Class *>((actor))->FUN_00575650({})));
    for (unsigned uiIndex = 0; uiIndex < p; ++uiIndex)
    {
        AvoidActor* other = ((::AvoidActor *)(reinterpret_cast<::FUN_00968630_stub *>(this)->FUN_00968630(uiIndex)));
        AvoidPosition location = (*(::AvoidPosition *)(reinterpret_cast<::FUN_00575650_Class *>((other))->FUN_00575650({})));
        if (i.FUN_00527a40(location) < a)
        {
            if (!h)
                h = new PathingAvoidNodeArray;
            reinterpret_cast<::FUN_00905450_StandIn *>((h))->AppendNode((::PathingAvoidanceNode *)&(const ::AvoidanceVectorData &)(AvoidanceVectorData((*(::AvoidVector *)(new ((void *)&(location)) ::Vec3())))));
        }
    }
    return h;
}

struct B9897F0Quad
{
    float x;
    float y;
    float z;
    float w;
};

class B9897F0Ref
{
  public:
};

class B9897F0Point
{
  public:
    float GetSquaredDistance(const B9897F0Quad& kOther);
};

class B9897F0List
{
  public:
    B9897F0Ref* FUN_009897f0(B9897F0Point* pkPoint, float fRadius, B9897F0Ref* pkExclude);
};

// Scans the list for the first entry other than pkExclude whose squared distance to pkPoint is less than the squared radius, returning it or 0.
// @fnv 0x009897f0
B9897F0Ref* B9897F0List::FUN_009897f0(B9897F0Point* pkPoint, float afRadius, B9897F0Ref* pkExclude)
{
    float fRadiusSq = afRadius * afRadius;
    unsigned int ItemUpdateArray = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        B9897F0Ref* pkRef = ((::B9897F0Ref *)(reinterpret_cast<::Target *>(this)->GetIntAt(i)));
        if (pkRef != pkExclude)
        {
            B9897F0Quad kPosition = (*(::B9897F0Quad *)(reinterpret_cast<::FUN_00575650_Class *>((pkRef))->FUN_00575650({})));
            if (pkPoint->GetSquaredDistance(kPosition) < fRadiusSq)
                return pkRef;
        }
    }
    return 0;
}

// Builds a 16 byte result block from the actor, then hands it to the group
// helper together with the radius and the actor.

struct LocalResult16
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
};

// Actor side: fills the caller supplied result block and returns its address.
struct ActorRef00989880
{
};

// Group side: takes the result block, the radius and the actor.
struct GroupRef00989880
{
};

// @fnv 0x00989880
void* CombatGroupS::FUN_00989880(ActorS* pActor, float afRadius)
{
    LocalResult16 tResult;
    return ((void *)(reinterpret_cast<::B9897F0List *>((((GroupRef00989880*)this)))->FUN_009897f0((::B9897F0Point *)(((int)(reinterpret_cast<::FUN_00575650_Class *>((((ActorRef00989880*)pActor)))->FUN_00575650((::FUN_00575650_Result *)(void *)(&tResult))))), afRadius, (::B9897F0Ref *)(pActor))));
}

extern "C" void* _alloca(unsigned int size);

class NiPoint3_ext
{
  public:
    float x;
    float y;
    float z;
    NiPoint3_ext& operator+=(const NiPoint3& other);
    NiPoint3 operator-(const NiPoint3& other) const;
};
class NiPoint3_helper
{
  public:
    float x;
    float y;
    float z;
    NiPoint3 operator*(float s) const;
};
struct FUN_004941c0_shell
{
    float x;
    float y;
    float z;
    NiPoint3* ScaleByInverse(float s);
};
struct FUN_00457910_shell
{
    float x;
    float y;
    float z;
};
struct ActorPos
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual NiPoint3* GetPos();
};
struct FUN_005a4320_shell : FUN_00986b70_helper
{
};
struct Grp_Call2 : FUN_005a4320_shell
{
    bool FUN_009899a0();
};

// @fnv 0x009899a0
bool Grp_Call2::FUN_009899a0()
{
    unsigned int a3 = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    unsigned int b = ::FUN_005a4320((char *)this);
    if (a3 == 0 || b == 0 || (a3 == 1 && b == 1))
        return false;
    NiPoint3* arr1 = (NiPoint3*)_alloca(a3 * sizeof(NiPoint3));
    NiPoint3* arr2 = (NiPoint3*)_alloca(b * sizeof(NiPoint3));
    NiPoint3 v29 = ::NiPoint3::ZERO;
    NiPoint3 vTmp = ::NiPoint3::ZERO;
    for (unsigned int i = 0; i < a3; i++)
    {
        ActorPos* obj = (ActorPos*)((void *)(reinterpret_cast<::Target *>(this)->GetIntAt(i)));
        arr1[i] = *obj->GetPos();
        reinterpret_cast<::FUN_0063c8a0_shell *>((((NiPoint3_ext*)&v29)))->FUN_0063c8a0+=((void *)&(arr1[i]));
    }
    for (unsigned int j = 0; j < b; j++)
    {
        ActorPos* obj = ((::ActorPos *)(reinterpret_cast<::FUN_00968630_stub *>(this)->FUN_00968630(j)));
        arr2[j] = *obj->GetPos();
        reinterpret_cast<::FUN_0063c8a0_shell *>((((NiPoint3_ext*)&vTmp)))->FUN_0063c8a0+=((void *)&(arr2[j]));
    }
    NiPoint3 sum23 = v29 + vTmp;
    ((FUN_004941c0_shell*)&v29)->ScaleByInverse((float)a3);
    ((FUN_004941c0_shell*)&vTmp)->ScaleByInverse((float)b);
    ((FUN_004941c0_shell*)&sum23)->ScaleByInverse((float)(a3 + b));
    NiPoint3 d23 = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((NiPoint3_ext*)&vTmp)))->FUN_00439ef0-((::NiPoint3 *)&(v29), *(const ::NiPoint3 *)nullptr)));
    NiPoint3 d5 = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((NiPoint3_ext*)&sum23)))->FUN_00439ef0-((::NiPoint3 *)&(v29), *(const ::NiPoint3 *)nullptr)));
    float f6 = reinterpret_cast<::FUN_004b6190_shell *>((void *)(((NiPoint3_ext*)&d5)))->DotProduct((void *)&(d23));
    float t20 = FUN_004579e0(f6);
    float t4 = reinterpret_cast<::NiPoint3 *>((((FUN_00457910_shell*)&d23)))->GetLengthSquared();
    NiPoint3 base = v29 + ((NiPoint3_helper*)&d23)->operator*(t20);
    NiPoint3 resid8 = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((NiPoint3_ext*)&v29)))->FUN_00439ef0-((::NiPoint3 *)&(base), *(const ::NiPoint3 *)nullptr)));
    unsigned int countA21 = 0;
    unsigned int countB = 0;
    for (unsigned int i = 0; i < a3; i++)
    {
        NiPoint3 diff = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((NiPoint3_ext*)&arr1[i])))->FUN_00439ef0-((::NiPoint3 *)&(base), *(const ::NiPoint3 *)nullptr)));
        if (reinterpret_cast<::FUN_004b6190_shell *>((void *)(((NiPoint3_ext*)&diff)))->DotProduct((void *)&(resid8)) < 0.0)
            countA21++;
    }
    for (unsigned int j = 0; j < b; j++)
    {
        NiPoint3 diff = (*(::NiPoint3 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((NiPoint3_ext*)&arr2[j])))->FUN_00439ef0-((::NiPoint3 *)&(base), *(const ::NiPoint3 *)nullptr)));
        if (reinterpret_cast<::FUN_004b6190_shell *>((void *)(((NiPoint3_ext*)&diff)))->DotProduct((void *)&(resid8)) < 0.0)
            countB++;
    }
    float ratioA22 = (float)countA21 / (float)a3;
    float ratioB7 = (float)countB / (float)b;
    if ((ratioA22 > 0.33f && ratioB7 > 0.33f) || (ratioA22 < 0.67f && ratioB7 < 0.67f))
        return true;
    return false;
}

struct Tag_00989e20_cls
{
    int unk00;
};

struct Helper_00989e20_cls
{
};

struct Vec_00989e20_cls
{
    NiPoint3* FUN_0053d280(float value) const;
};

struct Blk_00989e20_cls
{
    int a0;
    Tag_00989e20_cls t;
    int a8;
    int ac;
};

struct FUN_00989e20_cls
{
    void FUN_00989e20(NiPoint3* out);
};

struct BoundsVector
{
    float x, y, z;
};
struct BoundsActor
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
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
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
    virtual const BoundsVector& GetBoundsPoint();
};
struct BoundsGroup
{
    void ExpandBounds(BoundsVector* points, bool append);
};
// @fnv 0x00989e20
void FUN_00989e20_cls::FUN_00989e20(NiPoint3* out)
{
    NiPoint3 v88;
    NiPoint3 v7c3;
    B006815c0 arr[8];
    Blk_00989e20_cls pa0;

    reinterpret_cast<::BoundsGroup *>((this))->ExpandBounds((::BoundsVector *)(arr), 0);
    *out = *((Vec_00989e20_cls*)reinterpret_cast<::Point3Offset *>((((Helper_00989e20_cls*)arr)))->ProjectileLaunched(&v7c3, (NiPoint3*)&arr[7]))
                ->FUN_0053d280(::DAT_010162c0);
    reinterpret_cast<::FUN_00439ef0_class *>((((Helper_00989e20_cls*)arr)))->FUN_00439ef0((::NiPoint3 *)(::Tag_00989e20_cls *)(&pa0.t), (*(const ::NiPoint3 *)((NiPoint3*)&arr[7])));
    reinterpret_cast<::TESCombatStyle *>(&(pa0.t))->UpdateCombatStyle();
}

// Initializes or expands eight corner points from each actor's bounds point, taking per-axis min/max according to the corner sign table.
// @fnv 0x00989f40
void BoundsGroup::ExpandBounds(BoundsVector* points, bool append)
{
    if (!append)
    {
        for (unsigned int corner = 0; corner < 8; ++corner)
        {
            for (unsigned int axis = 0; axis < 3; ++axis)
            {
                ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[corner]))->FUN_004a51b0(axis))) = DAT_0108d57c[corner][axis] ? -DAT_0108d540 : DAT_0108d540;
            }
        }
    }
    unsigned int count = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    for (unsigned int index = 0; index < count; ++index)
    {
        BoundsActor* actor = ((::BoundsActor *)(reinterpret_cast<::Target *>(this)->GetIntAt(index)));
        BoundsVector position = actor->GetBoundsPoint();
        for (unsigned int corner = 0; corner < 8; ++corner)
        {
            for (unsigned int axis = 0; axis < 3; ++axis)
            {
                float value = ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(position))->FUN_004a51b0(axis)));
                if (DAT_0108d57c[corner][axis])
                {
                    if (value > ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[corner]))->FUN_004a51b0(axis))))
                        ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[corner]))->FUN_004a51b0(axis))) = value;
                }
                else
                {
                    if (value < ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[corner]))->FUN_004a51b0(axis))))
                        ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[corner]))->FUN_004a51b0(axis))) = value;
                }
            }
        }
    }
}

namespace fnv_0098a110 {
struct PointAccess
{
    float x, y, z;
};
struct CombatActorAccess
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const PointAccess& Position();
};
struct CornerAccumulator
{
    void UpdateBoundsFromActors(PointAccess*, bool);
};
// Initializes 8 corner points from DAT_0108d57c signs and DAT_0108d540, then expands each corner per axis with every actor's position.
// @fnv 0x0098a110
void CornerAccumulator::UpdateBoundsFromActors(PointAccess* points, bool initialized)
{
    unsigned int f, eb;
    unsigned int s;
    unsigned int cf;
    CombatActorAccess* q;
    PointAccess b;
    unsigned int ba, k;
    float l;
    if (!initialized)
    {
        for (f = 0; f < 8; ++f)
        {
            for (eb = 0; eb < 3; ++eb)
            {
                ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[f]))->FUN_004a51b0(eb))) = (*reinterpret_cast<unsigned char (*)[8][3]>(&::DAT_0108d57c))[f][eb] ? -::DAT_0108d540 : ::DAT_0108d540;
            }
        }
    }
    s = ::FUN_005a4320((char *)this);
    for (cf = 0; cf < s; ++cf)
    {
        q = ((::fnv_0098a110::CombatActorAccess *)(reinterpret_cast<::FUN_00968630_stub *>(this)->FUN_00968630(cf)));
        b = q->Position();
        for (ba = 0; ba < 8; ++ba)
        {
            for (k = 0; k < 3; ++k)
            {
                l = ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(b))->FUN_004a51b0(k)));
                if ((*reinterpret_cast<unsigned char (*)[8][3]>(&::DAT_0108d57c))[ba][k])
                {
                    if (l > ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[ba]))->FUN_004a51b0(k))))
                        ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[ba]))->FUN_004a51b0(k))) = l;
                }
                else
                {
                    if (l < ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[ba]))->FUN_004a51b0(k))))
                        ((float)(reinterpret_cast<::FUN_004a51b0_shell *>(&(points[ba]))->FUN_004a51b0(k))) = l;
                }
            }
        }
    }
}
}  // namespace fnv_0098a110

struct SearchNodeArrayOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    MyArr_0098a3c0 nodes;
};

// @fnv 0x0098a340
int FUN_0098a340_shell::FUN_0098a340(int index)
{
    return reinterpret_cast<SearchNodeArrayOwner*>(this)->nodes.FUN_006dad90(index)->m1;
}

struct FUN_0098a4d0_sub
{
    virtual int Slot0(int arg);
    virtual void Slot1();
    virtual void Slot2();
    virtual double Slot3(int arg);
};

struct FUN_0098a4d0_item
{
    int unk00;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    FUN_0098a4d0_sub sub;
};

struct FUN_0098a4d0_class : FUN_0098a410_shell
{
    float ComputeAverageRatio();
};
// Returns f14, computing and storing it from p0->ComputeAverageRatio() first when f14 equals _gModifierZero.
// @fnv 0x00990500
float __thiscall FUN_00990500_host::GetCachedValue()
{
    if (f14 == ::_DAT_01012060)
        f14 = reinterpret_cast<::FUN_0098a4d0_class *>((p0))->ComputeAverageRatio();
    return f14;
}

// Averages, over all items from GetCount, the ratio of Slot3(16) to Slot0(16) and returns the mean.
// @fnv 0x0098a4d0
float FUN_0098a4d0_class::ComputeAverageRatio()
{
    float total = 0.0f;
    unsigned int itemCount = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    for (unsigned int i = 0; i < itemCount; i++)
    {
        FUN_0098a4d0_item* item = (FUN_0098a4d0_item*)((void *)(reinterpret_cast<::Target *>(this)->GetIntAt(i)));
        total = item->sub.Slot3(16) / item->sub.Slot0(16) + total;
    }
    total = total / itemCount;
    return total;
}

struct Pt3
{
    float x;
    float y;
    float z;
    float w;
};
struct PosObj
{
};
struct TileObj
{
};
struct MgrObj
{
};
struct ItemObj
{
    unsigned int GetID();
};
struct ActorObj
{
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual void vf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void vf264();
    virtual void vf268();
    virtual void vf26c();
    virtual void vf270();
    virtual void vf274();
    virtual void vf278();
    virtual void vf27c();
    virtual void vf280();
    virtual void vf284();
    virtual void vf288();
    virtual void vf28c();
    virtual void vf290();
    virtual void vf294();
    virtual void vf298();
    virtual void vf29c();
    virtual void vf2a0();
    virtual void vf2a4();
    virtual void vf2a8();
    virtual void vf2ac();
    virtual void vf2b0();
    virtual void vf2b4();
    virtual void vf2b8();
    virtual void vf2bc();
    virtual void vf2c0();
    virtual void vf2c4();
    virtual void vf2c8();
    virtual void vf2cc();
    virtual void vf2d0();
    virtual void vf2d4();
    virtual void vf2d8();
    virtual void vf2dc();
    virtual void vf2e0();
    virtual void vf2e4();
    virtual void vf2e8();
    virtual void vf2ec();
    virtual void vf2f0();
    virtual void vf2f4();
    virtual void vf2f8();
    virtual void vf2fc();
    virtual void vf300();
    virtual void vf304();
    virtual void vf308();
    virtual void vf30c();
    virtual void vf310();
    virtual void vf314();
    virtual void vf318();
    virtual void vf31c();
    virtual void vf320();
    virtual void vf324();
    virtual void vf328();
    virtual void vf32c();
    virtual void vf330();
    virtual void vf334();
    virtual void vf338();
    virtual void vf33c();
    virtual void vf340();
    virtual void vf344();
    virtual void vf348();
    virtual void vf34c();
    virtual void vf350();
    virtual void vf354();
    virtual void vf358();
    virtual void vf35c();
    virtual void vf360();
    virtual void vf364();
    virtual void vf368();
    virtual void vf36c();
    virtual void vf370();
    virtual void vf374();
    virtual void vf378();
    virtual void vf37c();
    virtual void vf380();
    virtual void vf384();
    virtual void vf388();
    virtual void vf38c();
    virtual void vf390();
    virtual void vf394();
    virtual void vf398();
    virtual void vf39c();
    virtual void vf3a0();
    virtual void vf3a4();
    virtual void vf3a8();
    virtual void vf3ac();
    virtual void vf3b0();
    virtual void vf3b4();
    virtual void vf3b8();
    virtual void vf3bc();
    virtual void vf3c0();
    virtual void vf3c4();
    virtual void vf3c8();
    virtual void vf3cc();
    virtual void vf3d0();
    virtual void vf3d4();
    virtual void vf3d8();
    virtual void vf3dc();
    virtual void vf3e0();
    virtual void vf3e4();
    virtual void vf3e8();
    virtual void vf3ec();
    virtual void vf3f0();
    virtual void vf3f4();
    virtual void vf3f8();
    virtual void vf3fc();
    virtual void vf400();
    virtual void vf404();
    virtual void vf408();
    virtual void vf40c();
    virtual void vf410();
    virtual void vf414();
    virtual void vf418();
    virtual void vf41c();
    virtual void vf420();
    virtual void vf424();
    virtual MgrObj* GetMgr();
    Pt3 GetPos();
};
struct ItemList
{
    ItemObj* GetAt(unsigned int i);
    ItemObj* FindBestItem(ActorObj* actor, unsigned char thresh, ItemObj* target);
};

// @fnv 0x0098bc00
ItemObj* ItemList::FindBestItem(ActorObj* actor, unsigned char aucThreshold, ItemObj* target)
{
    MgrObj* mgr_2 = actor->GetMgr();
    Pt3 kPos = (*(::Pt3 *)(reinterpret_cast<::FUN_00575650_Class *>((actor))->FUN_00575650({})));
    int bestIdx3 = -1;
    float best = 0.0f;
    bool found3 = false;
    unsigned int count7 = reinterpret_cast<::fnv_00988750::FUN_00988750_shell *>(this)->GetFlags();
    for (unsigned int i4 = 0; i4 < count7; i4++)
    {
        ItemObj* item = GetAt(i4);
        float score2 = reinterpret_cast<::FUN_00985bb0_Class *>((item))->FUN_00985bb0();
        float bonus2 = 0.0f;
        if (target && ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((item))->FUN_0084e3a0())) == ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((target))->FUN_0084e3a0())) && reinterpret_cast<::NiPoint3 *>((((::PosObj *)(new ((void *)(item)) ::Vec3()))))->FUN_004390c0((*(const ::NiPoint3 *)(((::PosObj *)(new ((void *)(target)) ::Vec3()))))))
            bonus2 += 5.0;
        if (score2 + bonus2 < aucThreshold)
            continue;
        float dist6 = reinterpret_cast<::CombatClock *>((item))->GetAdjustedTime((::TimeInput *)(::Pt3 *)(&kPos)) + bonus2;
        if (score2 < best)
            continue;
        if (mgr_2 && !reinterpret_cast<::fnv_009a02a0::FUN_009a02a0_struct *>((((::TileObj *)(reinterpret_cast<::InterfaceManager *>((mgr_2))->FUN_00586150()))))->FUN_009a02a0((*(const ::fnv_009a02a0::CoordinateTriple *)(item)), 1, 0))
            continue;
        bestIdx3 = i4;
        best = score2;
    }
    if (bestIdx3 != -1)
        return GetAt(bestIdx3);
    return 0;
}

struct CombatEntryObj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4();
    virtual void vfn_2f8();
    virtual void vfn_2fc();
    virtual void vfn_300();
    virtual void vfn_304();
    virtual void vfn_308();
    virtual void vfn_30c();
    virtual void vfn_310();
    virtual void vfn_314();
    virtual void vfn_318();
    virtual void vfn_31c();
    virtual void vfn_320();
    virtual void vfn_324();
    virtual void vfn_328();
    virtual void vfn_32c();
    virtual void vfn_330();
    virtual void vfn_334();
    virtual void vfn_338();
    virtual void vfn_33c();
    virtual void vfn_340();
    virtual void vfn_344();
    virtual void vfn_348();
    virtual void vfn_34c();
    virtual void vfn_350();
    virtual void vfn_354();
    virtual void vfn_358();
    virtual void vfn_35c();
    virtual void vfn_360();
    virtual void vfn_364();
    virtual void vfn_368();
    virtual void vfn_36c();
    virtual void vfn_370();
    virtual void vfn_374();
    virtual void vfn_378();
    virtual void vfn_37c();
    virtual void vfn_380();
    virtual void vfn_384();
    virtual void vfn_388();
    virtual void vfn_38c();
    virtual void vfn_390();
    virtual void vfn_394();
    virtual void vfn_398();
    virtual void vfn_39c();
    virtual void vfn_3a0();
    virtual void vfn_3a4();
    virtual void vfn_3a8();
    virtual void vfn_3ac();
    virtual void vfn_3b0();
    virtual void vfn_3b4();
    virtual void vfn_3b8();
    virtual void vfn_3bc();
    virtual void vfn_3c0();
    virtual void vfn_3c4();
    virtual void vfn_3c8();
    virtual void vfn_3cc();
    virtual void vfn_3d0();
    virtual void vfn_3d4();
    virtual void vfn_3d8();
    virtual void vfn_3dc();
    virtual void vfn_3e0();
    virtual void vfn_3e4();
    virtual void vfn_3e8();
    virtual void vfn_3ec();
    virtual void vfn_3f0();
    virtual void vfn_3f4();
    virtual void vfn_3f8();
    virtual void vfn_3fc();
    virtual void vfn_400();
    virtual void vfn_404();
    virtual void vfn_408();
    virtual void vfn_40c();
    virtual void vfn_410();
    virtual void vfn_414();
    virtual void vfn_418();
    virtual void vfn_41c();
    virtual void vfn_420();
    virtual void vfn_424();
    virtual void* vfn_428();
    bool FUN_008b3840(struct Probe16* p);
};
struct Probe16
{
    int a, b, c;
};
struct RefTarget
{
};
struct CombatGroupTarget
{
};
struct CombatSearchCls
{
    bool CheckOtherEntriesForTarget(CombatEntryObj* a1, CombatGroupTarget* a2);
};
// @fnv 0x0098c7b0
bool CombatSearchCls::CheckOtherEntriesForTarget(CombatEntryObj* pExcludeEntry, CombatGroupTarget* pGroupTarget)
{
    unsigned int count = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    if (count <= 1)
        return false;
    bool bFound = false;
    for (unsigned int i = 0; i < count; ++i)
    {
        CombatEntryObj* p2 = ((::CombatEntryObj *)(reinterpret_cast<::Target *>(this)->GetIntAt(i)));
        if (p2 != pExcludeEntry)
        {
            void* r2 = p2->vfn_428();
            if (r2 != 0)
            {
                if (reinterpret_cast<::OuterObj *>((((RefTarget*)r2)))->FUN_00981420())
                {
                    Probe16 probe;
                    new ((void *)&(probe)) ::Vec3();
                    if (p2->FUN_008b3840(&probe))
                    {
                        reinterpret_cast<::fnv_0049f210::FUN_0049f210_class *>((pGroupTarget))->AddItem((*(const ::fnv_0049f210::NiPoint3 *)(&probe)));
                        bFound = true;
                    }
                }
            }
        }
    }
    return bFound;
}

struct FUN_0098cb30_inner
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
    virtual void v00A();
    virtual void v00B();
    virtual void v00C();
    virtual void v00D();
    virtual void v00E();
    virtual void v00F();
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
    virtual void v01A();
    virtual void v01B();
    virtual void v01C();
    virtual void v01D();
    virtual void v01E();
    virtual void v01F();
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
    virtual void v02A();
    virtual void v02B();
    virtual void v02C();
    virtual void v02D();
    virtual void v02E();
    virtual void v02F();
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
    virtual void v03A();
    virtual void v03B();
    virtual void v03C();
    virtual void v03D();
    virtual void v03E();
    virtual void v03F();
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
    virtual void v04A();
    virtual void v04B();
    virtual void v04C();
    virtual void v04D();
    virtual void v04E();
    virtual void v04F();
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
    virtual void v05A();
    virtual void v05B();
    virtual void v05C();
    virtual void v05D();
    virtual void v05E();
    virtual void v05F();
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
    virtual void v06A();
    virtual void v06B();
    virtual void v06C();
    virtual void v06D();
    virtual void v06E();
    virtual void v06F();
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
    virtual void v07A();
    virtual void v07B();
    virtual void v07C();
    virtual void v07D();
    virtual void v07E();
    virtual void v07F();
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
    virtual void v08A();
    virtual void v08B();
    virtual void v08C();
    virtual void v08D();
    virtual void v08E();
    virtual void v08F();
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
    virtual void v09A();
    virtual void v09B();
    virtual void v09C();
    virtual void v09D();
    virtual void v09E();
    virtual void v09F();
    virtual void v0A0();
    virtual void v0A1();
    virtual void v0A2();
    virtual void v0A3();
    virtual void v0A4();
    virtual void v0A5();
    virtual void v0A6();
    virtual void v0A7();
    virtual void v0A8();
    virtual void v0A9();
    virtual void v0AA();
    virtual void v0AB();
    virtual void v0AC();
    virtual void v0AD();
    virtual void v0AE();
    virtual void v0AF();
    virtual void v0B0();
    virtual void v0B1();
    virtual void v0B2();
    virtual void v0B3();
    virtual void v0B4();
    virtual void v0B5();
    virtual void v0B6();
    virtual void v0B7();
    virtual void v0B8();
    virtual void v0B9();
    virtual void v0BA();
    virtual void v0BB();
    virtual void v0BC();
    virtual void v0BD();
    virtual void v0BE();
    virtual void v0BF();
    virtual void v0C0();
    virtual void v0C1();
    virtual void v0C2();
    virtual void v0C3();
    virtual void v0C4();
    virtual void v0C5();
    virtual void v0C6();
    virtual void v0C7();
    virtual void v0C8();
    virtual void v0C9();
    virtual void v0CA();
    virtual void v0CB();
    virtual void v0CC();
    virtual void v0CD();
    virtual void v0CE();
    virtual void v0CF();
    virtual void v0D0();
    virtual void v0D1();
    virtual void v0D2();
    virtual void v0D3();
    virtual void v0D4();
    virtual void v0D5();
    virtual void v0D6();
    virtual void v0D7();
    virtual void v0D8();
    virtual void v0D9();
    virtual void v0DA();
    virtual void v0DB();
    virtual void v0DC();
    virtual void v0DD();
    virtual void v0DE();
    virtual void v0DF();
    virtual void v0E0();
    virtual void v0E1();
    virtual void v0E2();
    virtual void v0E3();
    virtual void v0E4();
    virtual void v0E5();
    virtual void v0E6();
    virtual void v0E7();
    virtual void v0E8();
    virtual void v0E9();
    virtual void v0EA();
    virtual void v0EB();
    virtual void v0EC();
    virtual void v0ED();
    virtual void v0EE();
    virtual void v0EF();
    virtual void v0F0();
    virtual void v0F1();
    virtual void v0F2();
    virtual void v0F3();
    virtual void v0F4();
    virtual void v0F5();
    virtual void v0F6();
    virtual void v0F7();
    virtual void v0F8();
    virtual void v0F9();
    virtual void v0FA();
    virtual void v0FB();
    virtual void v0FC();
    virtual void v0FD();
    virtual void v0FE();
    virtual void v0FF();
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
    virtual int v10A();
};

struct FUN_0098cb30_obj
{
    FUN_0098cb30_inner* m_pInner;
    int unk04;
    int unk08;
    float m_iThirdValue;
};

struct FUN_0098cb30_res
{
};

struct FUN_0098cb30_cls
{
    int unk00;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    float m_c0;
    FUN_0098cb30_obj* FUN_00988790(unsigned int idx);
    float GetModifierSum(FUN_0098cb30_inner* a1);
};


// Sums per-entry modifier values for entries matching a1 (or all others), skipping non-positive values, and returns m_c0 when a1 is null.
// @fnv 0x0098cb30
float FUN_0098cb30_cls::GetModifierSum(FUN_0098cb30_inner* apInner)
{
    if (apInner == 0)
    {
        return m_c0;
    }
    float fSum = 0.0f;
    unsigned int count = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    for (unsigned int i = 0; i < count; i++)
    {
        int r;
        FUN_0098cb30_obj* pObj = FUN_00988790(i);
        r = pObj->m_pInner->v10A();
        if (apInner == pObj->m_pInner && r != 0)
        {
            float fValue = reinterpret_cast<::FUN_00453700_shell *>((((::FUN_0098cb30_res *)(reinterpret_cast<::InterfaceManager *>((((FUN_0098cb30_res*)r)))->FUN_00586150()))))->FUN_00453700();
            if (fValue > ::_DAT_01012060)
            {
                fSum += fValue;
            }
        }
        else if (r == 0 || !reinterpret_cast<::S981990 *>((((FUN_0098cb30_res*)r)))->FUN_00981990())
        {
            if (pObj->m_iThirdValue > ::_DAT_01012060)
            {
                fSum += pObj->m_iThirdValue;
            }
        }
    }
    return fSum;
}

class B8EB30Group;

class B8EB30GroupInfo
{
  public:
};

class B8EB30Actor
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual void vfn1D0();
    virtual void vfn1D4();
    virtual void vfn1D8();
    virtual void vfn1DC();
    virtual void vfn1E0();
    virtual void vfn1E4();
    virtual void vfn1E8();
    virtual void vfn1EC();
    virtual void vfn1F0();
    virtual void vfn1F4();
    virtual void vfn1F8();
    virtual void vfn1FC();
    virtual void vfn200();
    virtual void vfn204();
    virtual void vfn208();
    virtual void vfn20C();
    virtual void vfn210();
    virtual void vfn214();
    virtual void vfn218();
    virtual void vfn21C();
    virtual void vfn220();
    virtual void vfn224();
    virtual void vfn228();
    virtual void vfn22C();
    virtual void vfn230();
    virtual void vfn234();
    virtual void vfn238();
    virtual void vfn23C();
    virtual void vfn240();
    virtual void vfn244();
    virtual void vfn248();
    virtual void vfn24C();
    virtual void vfn250();
    virtual void vfn254();
    virtual void vfn258();
    virtual void vfn25C();
    virtual void vfn260();
    virtual void vfn264();
    virtual void vfn268();
    virtual void vfn26C();
    virtual void vfn270();
    virtual void vfn274();
    virtual void vfn278();
    virtual void vfn27C();
    virtual void vfn280();
    virtual void vfn284();
    virtual void vfn288();
    virtual void vfn28C();
    virtual void vfn290();
    virtual void vfn294();
    virtual void vfn298();
    virtual void vfn29C();
    virtual void vfn2A0();
    virtual void vfn2A4();
    virtual void vfn2A8();
    virtual void vfn2AC();
    virtual void vfn2B0();
    virtual void vfn2B4();
    virtual void vfn2B8();
    virtual void vfn2BC();
    virtual void vfn2C0();
    virtual void vfn2C4();
    virtual void vfn2C8();
    virtual void vfn2CC();
    virtual void vfn2D0();
    virtual void vfn2D4();
    virtual void vfn2D8();
    virtual void vfn2DC();
    virtual void vfn2E0();
    virtual void vfn2E4();
    virtual void vfn2E8();
    virtual void vfn2EC();
    virtual void vfn2F0();
    virtual void vfn2F4();
    virtual void vfn2F8();
    virtual void vfn2FC();
    virtual void vfn300();
    virtual void vfn304();
    virtual void vfn308();
    virtual void vfn30C();
    virtual void vfn310();
    virtual void vfn314();
    virtual void vfn318();
    virtual void vfn31C();
    virtual void vfn320();
    virtual void vfn324();
    virtual void vfn328();
    virtual void vfn32C();
    virtual void vfn330();
    virtual void vfn334();
    virtual void vfn338();
    virtual void vfn33C();
    virtual void vfn340();
    virtual void vfn344();
    virtual void vfn348();
    virtual void vfn34C();
    virtual void vfn350();
    virtual void vfn354();
    virtual void vfn358();
    virtual void vfn35C();
    virtual void vfn360();
    virtual void vfn364();
    virtual void vfn368();
    virtual void vfn36C();
    virtual void vfn370();
    virtual void vfn374();
    virtual void vfn378();
    virtual void vfn37C();
    virtual void vfn380();
    virtual void vfn384();
    virtual void vfn388();
    virtual void vfn38C();
    virtual void vfn390();
    virtual void vfn394();
    virtual void vfn398();
    virtual void vfn39C();
    virtual void vfn3A0();
    virtual void vfn3A4();
    virtual void vfn3A8();
    virtual void vfn3AC();
    virtual void vfn3B0();
    virtual void vfn3B4();
    virtual void vfn3B8();
    virtual void vfn3BC();
    virtual void vfn3C0();
    virtual void vfn3C4();
    virtual void vfn3C8();
    virtual void vfn3CC();
    virtual void vfn3D0();
    virtual void vfn3D4();
    virtual void vfn3D8();
    virtual void vfn3DC();
    virtual void vfn3E0();
    virtual void vfn3E4();
    virtual void vfn3E8();
    virtual void vfn3EC();
    virtual void vfn3F0();
    virtual void vfn3F4();
    virtual void vfn3F8();
    virtual void vfn3FC();
    virtual void vfn400();
    virtual void vfn404();
    virtual void vfn408();
    virtual void vfn40C();
    virtual void vfn410();
    virtual void vfn414();
    virtual void vfn418();
    virtual void vfn41C();
    virtual void vfn420();
    virtual void vfn424();
    virtual B8EB30GroupInfo* GetGroupInfo();
};


class B8EB30Group
{
  public:
    void RemoveActorsNotInGroup(void* pvUnused);
};

// @fnv 0x0098eb30
void B8EB30Group::RemoveActorsNotInGroup(void* pvUnused)
{
    reinterpret_cast<::FUN_0098cf70_shell *>(this)->CountActorsPerNode();
    for (unsigned int i = 0; i < reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890(); i++)
    {
        B8EB30Actor* pkActor2 = ((::B8EB30Actor *)(reinterpret_cast<::Target *>(this)->GetIntAt(i)));
        if (pkActor2 == (*reinterpret_cast<::B8EB30Actor * *>(&::_g_thePlayer)))
            continue;
        B8EB30GroupInfo* pkInfo = pkActor2->GetGroupInfo();
        if (!pkInfo || ((::B8EB30Group *)(reinterpret_cast<::EffectSetting *>((pkInfo))->GetCastSound())) != this)
        {
            reinterpret_cast<::FUN_009869a0_shell *>(this)->FUN_009869a0((::Actor *)(pkActor2));
            i--;
        }
    }
}

class B98EBC0Array
{
  public:
    int* GetElementAt(int iIndex);
};
// @fnv 0x00988770
void __thiscall FUN_00988770_shell::ForwardToMember(int a1)
{
    reinterpret_cast<::B98EBC0Array *>((((FUN_0098ebc0_obj*)((char*)this + 0x110))))->GetElementAt(a1);
}

// @fnv 0x0098ebc0
int* B98EBC0Array::GetElementAt(int iIndex)
{
    return reinterpret_cast<::FUN_006bf670_Class *>(this)->FUN_006bf670(iIndex);
}

struct SimpleArrayRemove
{
    virtual ~SimpleArrayRemove();
    virtual void* Allocate(unsigned int ItemUpdateArray);

    void** pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;


    void FUN_0098ebe0(unsigned int uiStart, unsigned int ItemUpdateArray, bool bShrink);
};

// @fnv 0x0098ebe0
void SimpleArrayRemove::FUN_0098ebe0(unsigned int uiStart, unsigned int ItemUpdateArray, bool bShrink)
{
    if (ItemUpdateArray >= uiSize)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(bShrink);
        return;
    }
    if (bShrink && reinterpret_cast<::FUN_006f3170_Class *>(this)->FUN_006f3170())
    {
        unsigned int uiNewAlloc = reinterpret_cast<::FUN_00869600_Class *>(this)->FUN_00869600();
        void** pData = (void**)Allocate(uiNewAlloc);
        reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(pData), (char *)(pBuffer), uiStart);
        reinterpret_cast<::FUN_0072ba80_shell *>(this)->FUN_0072ba80(&pBuffer[uiStart], ItemUpdateArray);
        reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(void *)(&pData[uiStart]), (char *)(void *)(&pBuffer[uiStart] + ItemUpdateArray), uiSize - ItemUpdateArray);
        ::FUN_006a8500((::DummyClass_006a8500 *)this);
        pBuffer = pData;
        uiAllocSize = uiNewAlloc;
    }
    else
    {
        reinterpret_cast<::FUN_0072ba80_shell *>(this)->FUN_0072ba80(&pBuffer[uiStart], ItemUpdateArray);
        reinterpret_cast<::FUN_0042fb60_shell *>(this)->FUN_0042fb60((char *)(void *)(&pBuffer[uiStart]), (char *)(void *)(&pBuffer[uiStart] + ItemUpdateArray), uiSize - uiStart - ItemUpdateArray);
    }
    uiSize = uiSize - ItemUpdateArray;
}

struct RemovalOperations
{
};
struct RemovalArray : RemovalOperations
{
    void* unk00;
    char* unk04;
    unsigned int unk08;
    void FUN_0098ef10(unsigned int first, unsigned int count);
};
// @fnv 0x00986560
void __thiscall FUN_00986560_shell::FUN_00986560(int a1)
{
    void* v = reinterpret_cast<FUN_0098ef10_shell*>(reinterpret_cast<char*>(this) + 8)->FUN_0098ef10(a1);
    reinterpret_cast<::fnv_009926e0::CombatBox *>((reinterpret_cast<FUN_009926e0_shell*>((*reinterpret_cast<void * *>(&::BGSSaveLoadGlobalDataWorldspacePtr)))))->SwapAndDispatch((unsigned int)(this), (unsigned int)(*reinterpret_cast<void**>(v)));
    reinterpret_cast<::RemovalArray *>((reinterpret_cast<FUN_0098ef10_shell*>(reinterpret_cast<char*>(this) + 8)))->FUN_0098ef10(a1, 1);
}
// @fnv 0x0098ef10
void RemovalArray::FUN_0098ef10(unsigned int first, unsigned int count)
{
    unsigned int moved = FUN_0042f5a0(unk08 - first - count, count);
    reinterpret_cast<::FUN_0072ba80_shell *>(this)->FUN_0072ba80(unk04 + first * 104, count);
    reinterpret_cast<::FUN_0098f960_class *>(this)->FUN_0098f960((char *)(void *)(unk04 + first * 104), (char *)(void *)(unk04 + unk08 * 104 - moved * 104), moved);
    unk08 -= count;
}

void* operator new(unsigned int uiSize, void* pvWhere);
void operator delete(void* pvMem, void* pvWhere);

class C98F840Element
{
  public:
    C98F840Element();

    int unk00;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
};

class C98F840Allocator
{
  public:
    void FUN_0098f840(C98F840Element* pkElements, unsigned int ItemUpdateArray);
};
// @fnv 0x0098eec0
unsigned int __thiscall BSSimpleArray_CombatTarget_1024::FUN_0098eec0(const CombatTarget* aValue)
{
    unsigned int iElementIndex = reinterpret_cast<::FUN_0098f7b0_Class *>(this)->FUN_0098f7b0();
    reinterpret_cast<::C98F840Allocator *>(this)->FUN_0098f840((::C98F840Element *)(::CombatTarget *)((CombatTarget*)pBuffer + iElementIndex), 1);
    *(CombatTarget*)((CombatTarget*)pBuffer + iElementIndex) = *aValue;
    return iElementIndex;
}
// @fnv 0x0098ed80
void __thiscall FUN_0098ed80_shell::FUN_0098ed80(unsigned int auiCount, bool abShrink)
{
    if (auiCount == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArrayActor*>(this)))->Clear(abShrink);
    }
    else if (auiCount > m_pRayCursor)
    {
        if (m_pRayCursor == 0)
        {
            m_buffer = this->Allocate(auiCount);
            m_pRayCursor = auiCount;
        }
        else
        {
            reinterpret_cast<::FUN_0098fa00_cls *>((reinterpret_cast<FUN_0098fa00_shell*>(this)))->FUN_0098fa00(auiCount, m_iElementCount);
            m_pRayCursor = auiCount;
        }

        reinterpret_cast<::C98F840Allocator *>((reinterpret_cast<BSSimpleArray_CombatTarget_1024*>(this)))->FUN_0098f840((::C98F840Element *)(::CombatTarget *)(m_buffer + m_iElementCount), auiCount - m_iElementCount);
        m_iElementCount = auiCount;
    }
    else if (auiCount < m_iElementCount)
    {
        reinterpret_cast<FUN_0072ba80_shell*>(this)->FUN_0072ba80(reinterpret_cast<char*>(m_buffer + auiCount),
                                                                  m_iElementCount - auiCount);
        m_iElementCount = auiCount;

        if (abShrink && auiCount <= m_pRayCursor / 4)
        {
            reinterpret_cast<::FUN_0098fa00_cls *>((reinterpret_cast<FUN_0098fa00_shell*>(this)))->FUN_0098fa00(auiCount, auiCount);
            m_pRayCursor = auiCount;
        }
    }
    else
    {
        reinterpret_cast<::C98F840Allocator *>((reinterpret_cast<BSSimpleArray_CombatTarget_1024*>(this)))->FUN_0098f840((::C98F840Element *)(::CombatTarget *)(m_buffer + m_iElementCount), auiCount - m_iElementCount);
        m_iElementCount = auiCount;
    }
}

// @fnv 0x0098f840
void C98F840Allocator::FUN_0098f840(C98F840Element* pkElements, unsigned int ItemUpdateArray)
{
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
        new (&pkElements[i]) C98F840Element;
}

struct FUN_009d3390_sub
{
    int unk00;
};

struct FUN_009d3390_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_009d3390_sub m14;
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
    unsigned char m74;

    unsigned char FUN_009d3390();
};

// Returns 1 if the sub-object's CallA or CallB returns nonzero, or if m74 is nonzero; otherwise 0.
// @fnv 0x009d3390
unsigned char FUN_009d3390_cls::FUN_009d3390()
{
    return (reinterpret_cast<::FUN_00982be0_cls *>(&(m14))->FUN_00982be0() != 0 || ((unsigned char)(reinterpret_cast<::FUN_006e4820_class *>(&(m14))->FUN_006e4820())) != 0 || m74 != 0) ? 1 : 0;
}

struct Member08
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member08();
};
struct Member18
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member18();
};
struct SharedList
{
    unsigned int unk00;
    unsigned int unk04;
    ~SharedList();
};
struct Member110
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member110();
};
struct Member120
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member120();
};
struct Member138
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    ~Member138();
};
struct CombatManager
{
};
struct FUN_00985f90
{
    unsigned int unk000;
    unsigned int unk004;
    Member08 member08;
    Member18 member18;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    SharedList memberd4;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    Member110 member110;
    Member120 member120;
    SharedList member130;
    Member138 member138;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    SharedList member158;
    ~FUN_00985f90();
};
struct ActorMergeData;
struct MergeActor : ActorV
{
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void SetCombatGroup(ActorMergeData* group);
};
struct MergeTarget
{
    MergeActor* actor;
};
struct MergeMember
{
    MergeActor* actor;
};
struct MergeTargets : ArrSI
{
    unsigned int unk00, unk04, unk08, unk0c;
    MergeTarget* FUN_0096a2b0(unsigned int index);
};
struct MergeMembers : ArrSI
{
    MergeMember* FUN_006dad90(unsigned int index);
};
struct MergeEntries
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct ActorMergeData
{
    unsigned int unk00, unk04;
    MergeTargets targets;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    MergeEntries entries;
    unsigned int unk148, unk14c, unk150;
    char state;
    bool MergeFrom(ActorMergeData* other);
};

struct DebugPoint
{
    float x, y, z;
};
struct DebugColor
{
    float r, g, b, a;
    DebugColor(float, float, float, float);
};
struct DebugMaterial
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    DebugMaterial();
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct DebugUpdate
{
    float time;
    int flags, unk08;
    DebugUpdate(float, int, int);
};
struct DebugNode
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void Attach(DebugNode*, bool);
    virtual void v56();
    virtual void v57();
    virtual void Detach(DebugNode*);
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
    DebugNode(int);
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct DebugNodePtr
{
    DebugNode* ptr;
    void FUN_0066b0d0(DebugNode*);
};
void* FUN_00aa13e0(unsigned int);
void FUN_00aa13f0(void*);
__forceinline void* DebugNode::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void DebugNode::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
__forceinline void* DebugMaterial::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void DebugMaterial::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
struct DebugDetach
{
};
struct DebugScene
{
};
struct DebugGroup;
struct DebugActor
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const DebugPoint& Position();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual DebugGroup* Group();
    float FUN_008be1b0();
};
struct DebugSetting
{
    bool* FUN_00408d60();
};
extern float DAT_011a4d2c;
struct DebugSearchPoint
{
};
struct DebugMember
{
    DebugActor* actor;
    int unk04, unk08, unk0c;
    DebugSearchPoint* point;
};
struct DebugPair
{
    DebugActor* first;
    DebugActor* second;
    char unk08;
    bool blue, green;
    char unk0b;
};
struct DebugPoints
{
    int unk00, unk04, unk08, unk0c;
};
struct DebugPairs
{
    int unk00, unk04, unk08, unk0c;
    DebugPair* FUN_006a7af0(unsigned int);
};
struct DebugBuilder
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
    DebugBuilder(DebugPoint, float);
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
__forceinline void* DebugBuilder::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
__forceinline void DebugBuilder::operator delete(void* p)
{
    FUN_00aa13f0(p);
}
struct DebugBuilderPtr
{
    DebugBuilder* ptr;
    DebugBuilderPtr(DebugBuilder*);
    ~DebugBuilderPtr();
};
struct DebugSearch
{
    DebugPoint GetLocationAndReturn();
};
struct DebugSearchPtr
{
    DebugSearch* ptr;
};
const DebugColor& FUN_005d8550(int);
struct DebugGroup
{
    unsigned int id;
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
    DebugSearchPtr search;
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
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    DebugPairs pairs;
    DebugNodePtr searchNode;
    bool searchDirty;
    char unk135, unk136, unk137;
    DebugPoints points;
    int unk148, unk14c, unk150, unk154;
    DebugNodePtr debug;
    DebugMember* FUN_00988790(unsigned int);
    DebugSearchPoint* ForwardToMember(unsigned int);
    void RebuildDebugVisuals(bool);
};
// @fnv 0x00985f90
FUN_00985f90::~FUN_00985f90()
{
    unsigned int count = ::FUN_005a4320((char *)this);
    for (unsigned int i = 0; i < count; i++)
    {
        void* actor = ((void *)(reinterpret_cast<::FUN_00968630_stub *>(this)->FUN_00968630(i)));
        reinterpret_cast<::fnv_009926e0::CombatBox *>(((*reinterpret_cast<::CombatManager * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->SwapAndDispatch((unsigned int)(this), (unsigned int)(actor));
    }
    unsigned int targetCount = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    for (unsigned int j = 0; j < targetCount; j++)
    {
        void* target = ((void *)(reinterpret_cast<::Target *>(this)->GetIntAt(j)));
        reinterpret_cast<::FUN_008d0600_s *>(((*reinterpret_cast<::CombatManager * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_008d0600((int)(this), (int)(target));
    }
    for (unsigned int k = 0; k < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(member138))->GetName())); k++)
    {
        char* pEntry = ((char *)(reinterpret_cast<::S3e60 *>(&(member138))->FUN_006a7ad0(k)));
        delete pEntry;
    }
    reinterpret_cast<::DebugGroup *>(this)->RebuildDebugVisuals(true);
}
// @fnv 0x009878b0
void DebugGroup::RebuildDebugVisuals(bool clearOnly)
{
    if (((::DebugNode *)(::FUN_00559450((int *)&(debug)))) && ((::DebugNode *)(reinterpret_cast<::FUN_009611e0_shell *>((((::DebugNode *)(::FUN_00559450((int *)&(debug))))))->FUN_009611e0())))
    {
        if (!FUN_008c7aa0())
            ((::DebugNode *)(reinterpret_cast<::FUN_009611e0_shell *>((((::DebugNode *)(::FUN_00559450((int *)&(debug))))))->FUN_009611e0()))->Detach(((::DebugNode *)(::FUN_00559450((int *)&(debug)))));
        else
            reinterpret_cast<::fnv_0087ac60::FUN_0087AC60_Holder *>((((::DebugDetach *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087ac60({});
    }
    debug.FUN_0066b0d0(0);
    if (clearOnly)
        return;
    if (!((::DebugScene *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::DebugActor * *>(&::_g_thePlayer))))->GetTarget())) || !((::DebugNode *)(::FUN_00524cf0((::TESObjectCELL *)(((::DebugScene *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::DebugActor * *>(&::_g_thePlayer))))->GetTarget())))))))
        return;
    unsigned int space = ((unsigned int)(reinterpret_cast<::s575ca0::Owner *>(((*reinterpret_cast<::DebugActor * *>(&::_g_thePlayer))))->FUN_00575ca0()));
    DebugActor* selected3 = 0;
    if ((*reinterpret_cast<::DebugActor * *>(&::DAT_011dea24)) && (*reinterpret_cast<::DebugActor * *>(&::DAT_011dea24))->IsActor())
    {
        DebugActor* selectedActor = (*reinterpret_cast<::DebugActor * *>(&::DAT_011dea24));
        if (selectedActor->Group() == this)
            selected3 = selectedActor;
    }
    if (*(*reinterpret_cast<::DebugSetting *>(&::g_011f1824)).FUN_00408d60() && !DAT_011a4d34 && selected3)
    {
        for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(points))->GetName())); ++i)
        {
            DebugSearchPoint* spot = ((::DebugSearchPoint *)(reinterpret_cast<::S3e60 *>(&(points))->FUN_006a7ad0(i)));
            if (!((::DebugNode *)(::FUN_00559450((int *)&(debug)))))
                debug.FUN_0066b0d0(new DebugNode(0));
            DebugColor color(0.5f, 0.0f, 0.5f, 0.5f);
            bool found3 = false;
            DebugPoint position = (*(const ::DebugPoint *)(new ((void *)(spot)) ::Vec3()));
            unsigned int count2 = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
            for (unsigned int j = 0; j < count2; ++j)
            {
                DebugMember* member = FUN_00988790(j);
                if (member->point == spot && ((unsigned int)(reinterpret_cast<::s575ca0::Owner *>((member->actor))->FUN_00575ca0())) == space)
                {
                    DebugPoint origin = member->actor->Position();
                    DebugColor start(0.5f, 0.0f, 0.5f, 0.5f);
                    DebugColor end_2(1.0f, 1.0f, 1.0f, 0.5f);
                    DebugNode* arrow = ((::DebugNode *)(::fnv_00c5a0f0::FUN_00c5a0f0((const ::fnv_00c5a0f0::Vec3 &)(origin), (const ::fnv_00c5a0f0::Vec3 &)(position), 4.0f, 4.0f, (const ::fnv_00c5a0f0::Color4 *)(const ::DebugColor *)(&start), (const ::fnv_00c5a0f0::Color4 *)(const ::DebugColor *)(&end_2))));
                    ((::DebugNode *)(::FUN_00559450((int *)&(debug))))->Attach(arrow, true);
                    found3 = true;
                }
            }
            if (found3)
            {
                for (unsigned int k = 0; k < 5; ++k)
                {
                    DebugNode* circle = ((::DebugNode *)(::fnv_00c58f00::FUN_00c58f00(DAT_011a4d2c, 36, (::fnv_00c58f00::Vec4Item *)(&color))));
                    reinterpret_cast<::FUN_004bc1f0_S *>((circle))->FUN_004bc1f0(position.x, position.y, k * 25.0 + position.z);
                    ((::DebugNode *)(::FUN_00559450((int *)&(debug))))->Attach(circle, true);
                }
                DebugNode* marker = ((::DebugNode *)(::FUN_00c58d30(16.0f, 16.0f, 400.0f, 10, 10, (int)(&color))));
                reinterpret_cast<::FUN_00440460_S *>((marker))->FUN_00440460((const ::V3 *)&(position));
                ((::DebugNode *)(::FUN_00559450((int *)&(debug))))->Attach(marker, true);
            }
        }
    }
    if (*(*reinterpret_cast<::DebugSetting *>(&::g_011f1858)).FUN_00408d60())
    {
        if (!((::DebugNode *)(::FUN_00559450((int *)&(debug)))))
            debug.FUN_0066b0d0(new DebugNode(0));
        unsigned int memberCount = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
        for (unsigned int n = 0; n < memberCount; ++n)
        {
            DebugActor* memberActor3 = ((::DebugActor *)(reinterpret_cast<::Target *>(this)->GetIntAt(n)));
            if (((unsigned int)(reinterpret_cast<::s575ca0::Owner *>((memberActor3))->FUN_00575ca0())) != space)
                continue;
            float radius = memberActor3->FUN_008be1b0() * 1.5;
            DebugColor memberColor = FUN_005d8550((int)id);
            memberColor.a = 0.5f;
            DebugNode* cylinder2 = ((::DebugNode *)(::FUN_00c58d30(radius, radius, 16.0f, 10, 10, (int)(&memberColor))));
            reinterpret_cast<::FUN_00440460_S *>((cylinder2))->FUN_00440460((const ::V3 *)&(memberActor3->Position()));
            ((::DebugNode *)(::FUN_00559450((int *)&(debug))))->Attach(cylinder2, true);
        }
    }
    DebugNode* extra = 0;
    if (*(*reinterpret_cast<::DebugSetting *>(&::g_011f1814)).FUN_00408d60() && selected3)
    {
        if (!((::DebugNode *)(::FUN_00559450((int *)&(debug)))))
            debug.FUN_0066b0d0(new DebugNode(0));
        unsigned int pointCount = reinterpret_cast<::fnv_00988750::FUN_00988750_shell *>(this)->GetFlags();
        for (unsigned int p = 0; p < pointCount; ++p)
        {
            DebugSearchPoint* point = ForwardToMember(p);
            if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((point))->FUN_0084e3a0())) != space)
                continue;
            DebugColor pointColor3 = (*(::DebugColor *)(reinterpret_cast<::FUN_00985be0_shell *>((point))->GetEffectColor({})));
            DebugNode* sphere = ((::DebugNode *)(::FUN_00c56680(32.0f, 10, 10, (const ::Color4 *)(const ::DebugColor *)(&pointColor3))));
            reinterpret_cast<::FUN_00440460_S *>((sphere))->FUN_00440460((const ::V3 *)&((*(const ::DebugPoint *)(new ((void *)(point)) ::Vec3()))));
            ((::DebugNode *)(::FUN_00559450((int *)&(debug))))->Attach(sphere, true);
        }
        for (unsigned int q = 0; q < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(pairs))->GetName())); ++q)
        {
            DebugPair* pair = pairs.FUN_006a7af0(q);
            DebugActor* pairActor = 0;
            if (pair->first && ((unsigned int)(reinterpret_cast<::s575ca0::Owner *>((pair->first))->FUN_00575ca0())) == space)
                pairActor = pair->first;
            else if (pair->second && ((unsigned int)(reinterpret_cast<::s575ca0::Owner *>((pair->second))->FUN_00575ca0())) == space)
                pairActor = pair->second;
            if (!pairActor)
                continue;
            DebugColor pairColor_(0.0f, 0.0f, 0.0f, 0.0f);
            if (pair->blue)
                pairColor_ = DebugColor(0.0f, 0.0f, 1.0f, 0.5f);
            else if (pair->green)
                pairColor_ = DebugColor(0.0f, 1.0f, 0.0f, 0.5f);
            else
                pairColor_ = DebugColor(1.0f, 1.0f, 0.0f, 0.5f);
            DebugPoint pairPosition = pairActor->Position();
            DebugNode* pillarX = ((::DebugNode *)(::FUN_00c58d30(32.0f, 32.0f, 256.0f, 10, 10, (int)(&pairColor_))));
            reinterpret_cast<::FUN_00440460_S *>((pillarX))->FUN_00440460((const ::V3 *)&(pairPosition));
            ((::DebugNode *)(::FUN_00559450((int *)&(debug))))->Attach(pillarX, true);
        }
        if (((::DebugSearch *)(::FUN_00559450((int *)&(search)))) && searchDirty && ((unsigned int)(reinterpret_cast<::s575ca0::Owner *>((selected3))->FUN_00575ca0())) == space)
        {
            DebugBuilderPtr builder(
                new DebugBuilder(((::DebugSearch *)(::FUN_00559450((int *)&(search))))->GetLocationAndReturn(), reinterpret_cast<::FUN_00508050_Class *>((((::DebugSearch *)(::FUN_00559450((int *)&(search))))))->FUN_00508050()));
            reinterpret_cast<::LOSGridOwner *>((((::DebugSearch *)(::FUN_00559450((int *)&(search))))))->UpdateNavMeshes((::LOSTargetPtr &)(builder));
            searchNode.FUN_0066b0d0(((::DebugNode *)(reinterpret_cast<::ScriptClass *>((((::DebugBuilder *)(::FUN_00559450((int *)&(builder))))))->CreateSortAdjustNode())));
            searchDirty = false;
        }
        extra = ((::DebugNode *)(::FUN_00559450((int *)&(searchNode))));
    }
    if (((::DebugNode *)(::FUN_00559450((int *)&(debug)))))
    {
        DebugMaterial* material = new DebugMaterial;
        reinterpret_cast<::FUN_0049ed90_shell *>((material))->FUN_0049ed90(true);
        reinterpret_cast<::FUN_00439410_cls *>((((::DebugNode *)(::FUN_00559450((int *)&(debug))))))->FUN_00439410((::ArgObject *)(material));
        ::fnv_004b6e90::AttachLightingPropertyRecursive((::NiAVObject *)(::DebugNode *)(((::DebugNode *)(::FUN_00559450((int *)&(debug))))));
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(::DebugNode *)(((::DebugNode *)(::FUN_00559450((int *)&(debug))))), 0, 0);
        if (extra)
            ((::DebugNode *)(::FUN_00559450((int *)&(debug))))->Attach(extra, true);
        ((::DebugNode *)(::FUN_00524cf0((::TESObjectCELL *)(((::DebugScene *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::DebugActor * *>(&::_g_thePlayer))))->GetTarget()))))))->Attach(((::DebugNode *)(::FUN_00559450((int *)&(debug)))), true);
        reinterpret_cast<::FUN_00a5a040_Class *>((((::DebugNode *)(::FUN_00559450((int *)&(debug))))))->FUN_00a5a040();
        DebugUpdate update(0.0f, 0, 0);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::DebugNode *)(::FUN_00559450((int *)&(debug))))))->FUN_00a59c60((int)&(update));
    }
}

namespace CombatAssessment {
struct Actor;
struct Point;
struct PositionData;
typedef PositionData Position;
struct Target;
struct Group;
struct SenseData;
typedef SenseData Sense;
struct Hit;
struct Setting
{
};
struct Time
{
    int value;
};

struct Point
{
    float x, y, z;
};
struct PositionData
{
    Point point;
    int cell;
    float FUN_00527a40(Position*);
};
typedef PositionData Position;
struct SenseData
{
    int unk00;
    int unk04;
    int score;
    Point point;
    Time time;
    bool detected;
    char unk1d;
    bool visible;
    char unk1f;
    int score20;
};
typedef SenseData Sense;
struct Target
{
    int unk00;
    int score;
    Position lastKnown;
    Position search;
    Position seen;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    short state;
    short unk4a;
    Time seenTime;
    Time activeTime;
    Time updateTime;
    Time alertTime;
    Time hitTime;
    Time cooldown;
    unsigned char visibleCount;
    unsigned char detectedCount;
    short unk66;
};
struct Hit
{
    int unk00;
    Point point;
    Time time;
};
struct Process
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual Hit* vf8(Actor*);
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual Sense* v504(Actor*, int);
};
struct DetectionViewData
{
};
struct CombatState
{
};
struct Actor
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual CombatState* v428();
    virtual void* v42c();
    int FUN_00931850();
};
struct Manager
{
};
struct Group
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
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    short state;
    void UpdateTargetPerception(Actor*, Actor*, int*, Time*, bool*, bool*);
};
// @fnv 0x009887b0
void Group::UpdateTargetPerception(Actor* selected, Actor* subject, int* result, Time* timestamp, bool* visible,
                                   bool* detected)
{
    Time temp4Local2;
    Time temp3Local31;
    Time temp2Local6;
    Time temp1Local7;
    Time temp0Local20;
    Sense* reusedLocal18;
    float strengthLocal6;
    Position impactLocal48;
    Hit* hitLocal9;
    Actor* member2Local23;
    unsigned int index2Local31;
    CombatState* stateLocal7;
    int scoreLocal7;
    Position originLocal30;
    Position destinationLocal23;
    Actor* memberLocal19;
    Sense* senseLocal1;
    Sense fallbackLocal15;
    unsigned int indexLocal5;
    Actor* bestLocal4;
    Position nearestLocal9;
    Position currentLocal8;
    Time newestLocal2;
    unsigned int countLocal20;
    int maximumLocal6;
    bool missingLocal40;
    int highestLocal52;
    int previousLocal5;
    Target* targetLocal40;

    *visible = false;
    *detected = false;
    *result = -100;
    reinterpret_cast<::FUN_00435de0_ctor *>(&(temp0Local20))->FUN_00435de0(-::DAT_0108d540);
    *timestamp = temp0Local20;
    targetLocal40 = ((::CombatAssessment::Target *)(reinterpret_cast<::ActorCombatGroup *>(this)->FUN_009865d0((int)(subject))));
    if (targetLocal40)
    {
        previousLocal5 = targetLocal40->score;
        if (reinterpret_cast<::CombatTargetTimestamp *>(&(targetLocal40->updateTime))->FUN_006a7f50() < ::FUN_00435dd0())
        {
            maximumLocal6 = -100;
            highestLocal52 = -100;
            missingLocal40 = false;
            if (!reinterpret_cast<::FUN_0084e3a0_Class *>(&(targetLocal40->search))->FUN_0084e3a0())
                missingLocal40 = true;
            bestLocal4 = 0;
            targetLocal40->detectedCount = 0;
            targetLocal40->visibleCount = 0;
            reinterpret_cast<::FUN_0097ede0_cls *>(&(nearestLocal9))->FUN_0097ede0();
            reinterpret_cast<::FUN_00435de0_ctor *>(&(newestLocal2))->FUN_00435de0(-::DAT_0108d540);
            countLocal20 = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
            for (indexLocal5 = 0; indexLocal5 < countLocal20; indexLocal5++)
            {
                memberLocal19 = ((::CombatAssessment::Actor *)(reinterpret_cast<::Target *>(this)->GetIntAt(indexLocal5)));
                senseLocal1 = ((::CombatAssessment::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((memberLocal19))->GetBaseTexture()))->v504(subject, 0);
                new ((void *)&(fallbackLocal15)) ::fnv_0066e590::FUN_0066e590();
                if (memberLocal19->FUN_00931850() && subject->FUN_00931850())
                {
                    reinterpret_cast<::FUN_00575650_Class *>((memberLocal19))->FUN_00575650((::FUN_00575650_Result *)(::CombatAssessment::PositionData *)(&originLocal30));
                    reinterpret_cast<::FUN_00575650_Class *>((subject))->FUN_00575650((::FUN_00575650_Result *)(::CombatAssessment::PositionData *)(&destinationLocal23));
                    if (originLocal30.FUN_00527a40(&destinationLocal23) < 67108864.0)
                    {
                        fallbackLocal15.score = 1;
                        senseLocal1 = &fallbackLocal15;
                    }
                }
                if (senseLocal1)
                {
                    if (senseLocal1->visible)
                        targetLocal40->visibleCount++;
                    if (senseLocal1->detected)
                        targetLocal40->detectedCount++;
                    if (memberLocal19 == selected)
                    {
                        *visible = senseLocal1->visible;
                        *detected = senseLocal1->detected;
                    }
                    scoreLocal7 = senseLocal1->score;
                    if (senseLocal1->score20 != 0x7fffffff)
                    {
                        if (highestLocal52 < senseLocal1->score20)
                            highestLocal52 = senseLocal1->score20;
                        if (scoreLocal7 == (int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatAssessment::Setting *>(&::originalRuntimeFloatSetting106)))))) + 1 &&
                            senseLocal1->score20 > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatAssessment::Setting *>(&::originalRuntimeFloatSetting106)))))))
                            scoreLocal7 = (int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatAssessment::Setting *>(&::originalRuntimeFloatSetting106))))));
                    }
                    stateLocal7 = memberLocal19->v428();
                    if (!stateLocal7 || ((::CombatAssessment::Actor *)(reinterpret_cast<::AlchemyItem *>((stateLocal7))->FUN_004030b0())) != subject ||
                        reinterpret_cast<::Container *>((((::CombatAssessment::DetectionViewData *)(reinterpret_cast<::InterfaceManager *>((stateLocal7))->FUN_00586150()))))->FUN_0099a360({}, {}))
                    {
                        if (senseLocal1 && scoreLocal7 > maximumLocal6)
                        {
                            maximumLocal6 = scoreLocal7;
                            bestLocal4 = memberLocal19;
                        }
                    }
                    else
                    {
                        if (previousLocal5 > maximumLocal6)
                        {
                            maximumLocal6 = previousLocal5;
                            bestLocal4 = memberLocal19;
                        }
                    }
                    if (missingLocal40 && reinterpret_cast<::CombatTargetTimestamp *>(&(senseLocal1->time))->FUN_006a7f50() > reinterpret_cast<::CombatTargetTimestamp *>(&(newestLocal2))->FUN_006a7f50())
                    {
                        reinterpret_cast<::StandIn_00989010 *>(&(nearestLocal9))->SetTripleAndValue((::ThreeInts_00989010 *)(::CombatAssessment::Point *)(&senseLocal1->point), (int)(((void *)(reinterpret_cast<::s575ca0::Owner *>((memberLocal19))->FUN_00575ca0()))));
                        newestLocal2 = senseLocal1->time;
                    }
                }
            }
            if (maximumLocal6 <= (int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatAssessment::Setting *>(&::originalRuntimeFloatSetting106)))))) && reinterpret_cast<::FUN_00435e00_t *>(&(targetLocal40->cooldown))->FUN_00435e00() < 1.0)
                maximumLocal6 = (int)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatAssessment::Setting *>(&::originalRuntimeFloatSetting106)))))) + 1.0);
            if (reinterpret_cast<::FUN_0097ef30_shell *>(this)->FUN_0097ef30() && previousLocal5 <= 0 && maximumLocal6 > 0)
            {
                if (reinterpret_cast<::CombatTargetTimestamp *>(&(targetLocal40->activeTime))->FUN_006a7f50() != -::DAT_0108d540)
                    reinterpret_cast<::P029Manager *>((DAT_011f1708))->TryStartDialogue((::P029Actor *)(bestLocal4), subject, 4, 9, 1, (::P029Input *)(0));
                else
                {
                    for (index2Local31 = 0; index2Local31 < countLocal20; index2Local31++)
                    {
                        member2Local23 = ((::CombatAssessment::Actor *)(reinterpret_cast<::Target *>(this)->GetIntAt(index2Local31)));
                        if (member2Local23 != (*reinterpret_cast<::CombatAssessment::Actor * *>(&::_g_thePlayer)))
                            ::FUN_005ac750((::TESForm *)(void *)(member2Local23->v42c()), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((member2Local23))->FUN_005d43c0()), 0x8000);
                    }
                    reinterpret_cast<::P029Manager *>((DAT_011f1708))->TryStartDialogue((::P029Actor *)(bestLocal4), subject, 4, 3, 1, (::P029Input *)(0));
                }
            }
            targetLocal40->score = maximumLocal6;
            {
                reinterpret_cast<::FUN_00435de0_ctor *>(&(temp1Local7))->FUN_00435de0(::FUN_00435dd0());
                targetLocal40->updateTime = temp1Local7;
            }
            reinterpret_cast<::FUN_00575650_Class *>((subject))->FUN_00575650((::FUN_00575650_Result *)(::CombatAssessment::PositionData *)(&currentLocal8));
            if (maximumLocal6 > 0)
            {
                reinterpret_cast<::FUN_00435de0_ctor *>(&(temp2Local6))->FUN_00435de0(::FUN_00435dd0());
                targetLocal40->activeTime = temp2Local6;
            }
            if (reinterpret_cast<::FUN_00435e00_t *>(&(targetLocal40->activeTime))->FUN_00435e00() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatAssessment::Setting *>(&::originalRuntimeFloatSetting412)))))))
                targetLocal40->search = currentLocal8;
            else if (missingLocal40)
                targetLocal40->search = nearestLocal9;
            if (maximumLocal6 > (int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatAssessment::Setting *>(&::originalRuntimeFloatSetting106)))))))
            {
                {
                    reinterpret_cast<::FUN_00435de0_ctor *>(&(temp3Local31))->FUN_00435de0(::FUN_00435dd0());
                    targetLocal40->alertTime = temp3Local31;
                }
                targetLocal40->lastKnown = currentLocal8;
                targetLocal40->state = this->state;
            }
            if (targetLocal40->detectedCount)
            {
                targetLocal40->seen = currentLocal8;
                {
                    reinterpret_cast<::FUN_00435de0_ctor *>(&(temp4Local2))->FUN_00435de0(::FUN_00435dd0());
                    targetLocal40->seenTime = temp4Local2;
                }
            }
            if (highestLocal52 > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatAssessment::Setting *>(&::originalRuntimeFloatSetting106)))))) && reinterpret_cast<::FUN_0097ef30_shell *>(this)->FUN_0097ef30())
            {
                hitLocal9 = ((::CombatAssessment::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((subject))->GetBaseTexture()))->vf8(subject);
                if (hitLocal9 && reinterpret_cast<::FUN_00435e00_t *>(&(hitLocal9->time))->FUN_00435e00() < 5.0 &&
                    reinterpret_cast<::CombatTargetTimestamp *>(&(hitLocal9->time))->FUN_006a7f50() > reinterpret_cast<::CombatTargetTimestamp *>(&(targetLocal40->hitTime))->FUN_006a7f50())
                {
                    strengthLocal6 = 0;
                    if (highestLocal52 > 0)
                        strengthLocal6 = ::FUN_0040ebd0((float)(highestLocal52 / 20.0), 5.0f) + 55.0;
                    else
                        strengthLocal6 = (highestLocal52 - (int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatAssessment::Setting *>(&::originalRuntimeFloatSetting106))))))) / 2.0 + 40.0;
                    reinterpret_cast<::FUN_0097ede0_cls *>(&(impactLocal48))->FUN_0097ede0();
                    reinterpret_cast<::StandIn_00989010 *>(&(impactLocal48))->SetTripleAndValue((::ThreeInts_00989010 *)(::CombatAssessment::Point *)(&hitLocal9->point), (int)(((void *)(reinterpret_cast<::s575ca0::Owner *>((subject))->FUN_00575ca0()))));
                    reinterpret_cast<::FUN_0098bfb0_Class *>(this)->StoreRecord(&impactLocal48, strengthLocal6, 0);
                    targetLocal40->hitTime = hitLocal9->time;
                }
            }
        }
        else
        {
            reusedLocal18 = selected ? ((::CombatAssessment::Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>((selected))->GetBaseTexture()))->v504(subject, 0) : 0;
            if (reusedLocal18)
            {
                *visible = reusedLocal18->visible;
                *detected = reusedLocal18->detected;
            }
        }
        *result = targetLocal40->score;
        *timestamp = targetLocal40->activeTime;
    }
}
}

template <class T> class SettingT;
class GameSettingCollection;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting382;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting383;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting384;

struct Pos9892
{
    float x;
    float y;
    float z;

    Pos9892 FUN_0053d280(float fScale) const;
};

struct FUN_006915d0
{
    float m_af[9];

    FUN_006915d0(const Pos9892& kPos);
};

struct AvoidArray9892 : PathingAvoidNodeArray
{
};

struct AvoidMember9892
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Pos9892* GetPos();
};

struct FUN_009892a0_shell
{
    PathingAvoidNodeArray* FUN_009892a0(AvoidMember9892* pActor, const Pos9892* pTarget, float fRadius,
                                        PathingAvoidNodeArray* pAvoidArray, AvoidMember9892* pIgnore);
};

// @fnv 0x009892a0
PathingAvoidNodeArray* FUN_009892a0_shell::FUN_009892a0(AvoidMember9892* pActor, const Pos9892* pTarget, float fRadius,
                                                        PathingAvoidNodeArray* pAvoidArray, AvoidMember9892* pIgnore)
{
    PathingAvoidNodeArray* pResult_2 = pAvoidArray;
    Pos9892 kCenterTmp = (*(::Pos9892 *)(reinterpret_cast<::Point3Offset *>((void *)(pActor->GetPos()))->ProjectileLaunched((::NiPoint3 *)&(*pTarget), {}))).FUN_0053d280(DAT_010162c0);
    Pos9892 kOffsetValue = (*(::Pos9892 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(pTarget))->FUN_00439ef0((::NiPoint3 *)&(kCenterTmp), *(const ::NiPoint3 *)nullptr)));
    float afValueAfterThirdFloat = reinterpret_cast<::TESCombatStyle *>((void *)&(kOffsetValue))->UpdateCombatStyle() + fRadius * fRadius;
    afValueAfterThirdFloat = FUN_00403e20((float*)&originalRuntimeFloatSetting382) *
                             FUN_00403e20((float*)&originalRuntimeFloatSetting382) * afValueAfterThirdFloat;
    unsigned int uiCountTmp = ::FUN_005a4320((char *)this);
    for (unsigned int i4 = 0; i4 < uiCountTmp; i4++)
    {
        AvoidMember9892* pMember = ((::AvoidMember9892 *)(reinterpret_cast<::FUN_00968630_stub *>(this)->FUN_00968630(i4)));
        if (pMember != pIgnore)
        {
            Pos9892 kPos3 = *pMember->GetPos();
            Pos9892 kDelta_ = (*(::Pos9892 *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)&(kCenterTmp))->FUN_00439ef0((::NiPoint3 *)&(kPos3), *(const ::NiPoint3 *)nullptr)));
            if (reinterpret_cast<::TESCombatStyle *>((void *)&(kDelta_))->UpdateCombatStyle() < afValueAfterThirdFloat)
            {
                if (!pResult_2)
                    pResult_2 = new PathingAvoidNodeArray;
                reinterpret_cast<::FUN_00905450_StandIn *>((((AvoidArray9892*)pResult_2)))->AppendNode((::PathingAvoidanceNode *)&(const ::FUN_006915d0 &)(FUN_006915d0(kPos3)));
            }
        }
    }
    return pResult_2;
}

namespace CombatRegion {
struct Actor;
struct Group;
struct Vec
{
    float x, y, z;
    Vec();
};
struct Point
{
    float x, y, z;
};
struct Target
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned short unk48, flags;
    unsigned int unk4c;
    Point point;
};
struct Location
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct Timer
{
    unsigned int unk00, unk04;
};
struct Region
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    Region(const Vec&, unsigned int, unsigned int);
    Region(Actor*);
    ~Region();
};
struct RegionArray
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    RegionArray(unsigned int, int, int);
    ~RegionArray();
};
struct FloatArray
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    FloatArray(unsigned int, int, int);
    ~FloatArray();
    void AppendFloat(const float&);
};
struct Shape
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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

    Shape();
    static __forceinline void* operator new(unsigned int);
    static __forceinline void operator delete(void*)
    {}
};
void* FUN_00aa13e0(unsigned int);
__forceinline void* Shape::operator new(unsigned int n)
{
    return FUN_00aa13e0(n);
}
struct ShapePtr
{
    Shape* value;
    void FUN_0066b0d0(Shape*);
};
struct Actor
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2c();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3c();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4c();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5c();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6c();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7c();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8c();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9c();
    virtual void slota0();
    virtual void slota4();
    virtual void slota8();
    virtual void slotac();
    virtual void slotb0();
    virtual void slotb4();
    virtual void slotb8();
    virtual void slotbc();
    virtual void slotc0();
    virtual void slotc4();
    virtual void slotc8();
    virtual void slotcc();
    virtual void slotd0();
    virtual void slotd4();
    virtual void slotd8();
    virtual void slotdc();
    virtual void slote0();
    virtual void slote4();
    virtual void slote8();
    virtual void slotec();
    virtual void slotf0();
    virtual void slotf4();
    virtual void slotf8();
    virtual void slotfc();
    virtual void slot100();
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
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void slot2a0();
    virtual void slot2a4();
    virtual void slot2a8();
    virtual void slot2ac();
    virtual void slot2b0();
    virtual void slot2b4();
    virtual void slot2b8();
    virtual float Heading(int);
    virtual void slot2c0();
    virtual void slot2c4();
    virtual void slot2c8();
    virtual void slot2cc();
    virtual void slot2d0();
    virtual void slot2d4();
    virtual void slot2d8();
    virtual void slot2dc();
    virtual void slot2e0();
    virtual void slot2e4();
    virtual void slot2e8();
    virtual void slot2ec();
    virtual void slot2f0();
    virtual void slot2f4();
    virtual void slot2f8();
    virtual void slot2fc();
    virtual void slot300();
    virtual void slot304();
    virtual void slot308();
    virtual void slot30c();
    virtual void slot310();
    virtual void slot314();
    virtual void slot318();
    virtual void slot31c();
    virtual void slot320();
    virtual void slot324();
    virtual void slot328();
    virtual void slot32c();
    virtual void slot330();
    virtual void slot334();
    virtual void slot338();
    virtual void slot33c();
    virtual void slot340();
    virtual void slot344();
    virtual void slot348();
    virtual void slot34c();
    virtual void slot350();
    virtual void slot354();
    virtual void slot358();
    virtual void slot35c();
    virtual void slot360();
    virtual void slot364();
    virtual void slot368();
    virtual void slot36c();
    virtual void slot370();
    virtual void slot374();
    virtual void slot378();
    virtual void slot37c();
    virtual void slot380();
    virtual void slot384();
    virtual void slot388();
    virtual void slot38c();
    virtual void slot390();
    virtual void slot394();
    virtual void slot398();
    virtual void slot39c();
    virtual void slot3a0();
    virtual void slot3a4();
    virtual void slot3a8();
    virtual void slot3ac();
    virtual void slot3b0();
    virtual void slot3b4();
    virtual void slot3b8();
    virtual void slot3bc();
    virtual void slot3c0();
    virtual void slot3c4();
    virtual void slot3c8();
    virtual void slot3cc();
    virtual void slot3d0();
    virtual void slot3d4();
    virtual void slot3d8();
    virtual void slot3dc();
    virtual void slot3e0();
    virtual void slot3e4();
    virtual void slot3e8();
    virtual void slot3ec();
    virtual void slot3f0();
    virtual void slot3f4();
    virtual void slot3f8();
    virtual void slot3fc();
    virtual void slot400();
    virtual void slot404();
    virtual void slot408();
    virtual void slot40c();
    virtual void slot410();
    virtual void slot414();
    virtual void slot418();
    virtual void slot41c();
    virtual void slot420();
    virtual void slot424();
    virtual void slot428();
    virtual Group* ActorCombatGroup();
};
struct Setting
{
};
struct Manager
{
};
struct Group
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int generation;
    ShapePtr shape;
    Timer updateTimer;
    Timer refreshTimer;
    unsigned int unke8;
    Actor* focus;
    Location location;
    Vec position;
    float radius;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned char changed;
    unsigned char unk135;
    unsigned short unk136;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int capacity;
    unsigned int count;
    Target* FUN_009871c0(unsigned int);
    void FUN_0098a580();
};
// @fnv 0x0098a580
void Group::FUN_0098a580()
{
    if (capacity)
    {
        unsigned int total = ::FUN_005a4320((char *)this);
        bool fullSlot14 = false;
        if (!total || count >= capacity)
            fullSlot14 = true;
        if (reinterpret_cast<::FUN_0097ef30_shell *>(this)->FUN_0097ef30())
        {
            if (fullSlot14)
                reinterpret_cast<::FUN_0098bae0_cls *>(this)->FUN_0098bae0();
            else
            {
                for (unsigned int index = 0; index < total; index++)
                {
                    Target* target = FUN_009871c0(index);
                    if (reinterpret_cast<::FUN_00435e00_t *>(&(target->point))->FUN_00435e00() < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatRegion::Setting *>(&::originalRuntimeFloatSetting412)))))))
                    {
                        reinterpret_cast<::FUN_0098bae0_cls *>(this)->FUN_0098bae0();
                        break;
                    }
                }
            }
        }
        else if (!fullSlot14)
        {
            unsigned int farCountSlot0 = 0;
            unsigned int flaggedSlot0 = 0;
            for (unsigned int index = 0; index < total; index++)
            {
                Target* target = FUN_009871c0(index);
                if (reinterpret_cast<::FUN_00435e00_t *>(&(target->point))->FUN_00435e00() >= *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatRegion::Setting *>(&::originalRuntimeFloatSetting413)))))))
                    farCountSlot0++;
                if (target->flags)
                    flaggedSlot0++;
            }
            if (flaggedSlot0 && farCountSlot0 == total)
                reinterpret_cast<::GroupReset *>(this)->FUN_0098add0();
        }
    }
    if (reinterpret_cast<::FUN_0097ef30_shell *>(this)->FUN_0097ef30())
    {
        if (focus && (reinterpret_cast<::FUN_008b3b90_shell *>((focus))->FUN_008b3b90() || !reinterpret_cast<::FUN_008b3bf0_shell *>((focus))->FUN_008b3bf0()))
            focus = 0;
        if (reinterpret_cast<::TimeoutTimer *>(&(updateTimer))->CheckTimer())
        {
            if (((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape)))) && reinterpret_cast<::BSMultiBoundSphere *>((((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape))))))->GetRadius() > DAT_0106d508)
            {
                reinterpret_cast<::fnv_006e05b0::PathingLOSGridMap *>((((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape))))))->Reset();
                generation++;
                reinterpret_cast<::FUN_0097f220_Class *>(&(refreshTimer))->FUN_0097f220();
            }
            bool refreshSlot1 = false;
            if (reinterpret_cast<::TimeoutTimer *>(&(refreshTimer))->CheckTimer())
            {
                refreshSlot1 = reinterpret_cast<::GroupReset_98afb0 *>(this)->UpdateAndCheckChanged();
                reinterpret_cast<::FUN_008d7f40_shell *>(&(refreshTimer))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatRegion::Setting *>(&::originalRuntimeFloatSetting447)))))));
            }
            if (reinterpret_cast<::CoordinateTriple *>(&(location))->FUN_00527a00())
            {
                if (!((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape)))) || refreshSlot1)
                {
                    unsigned int endSlot0 = 0;
                    unsigned int start = 0;
                    if (reinterpret_cast<::FUN_00527990_shell *>(&(location))->FUN_00527990((int *)(unsigned int *)(&start), (int *)(unsigned int *)(&endSlot0)))
                    {
                        Vec selected;
                        if (::Pathing::FindClosestPathingPoint((::TESWorldSpace *)(endSlot0), (::TESObjectCELL *)(start), (const ::NiPoint3 &)(position), (::NiPoint3 *)&(selected)))
                        {
                            Region region(selected, start, endSlot0);
                            if (reinterpret_cast<::PathingLocationProxy *>(&(region))->FindContainingTriangle((::FindTriangleForLocationFilter *)(0)))
                            {
                                reinterpret_cast<::fnv_006f4ed0::PathingLocation *>(&(region))->FUN_006f4ed0((const ::fnv_006f4ed0::NiPoint3 *)(void *)(((void *)(new ((void *)&(location)) ::Vec3()))));
                                if (!((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape)))))
                                    shape.FUN_0066b0d0(new Shape);
                                reinterpret_cast<::FUN_006e0320_cls *>((((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape))))))->FUN_006e0320((unsigned int)&(region), radius);
                                reinterpret_cast<::FUN_0098adb0_shell *>((((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape))))))->FUN_0098adb0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatRegion::Setting *>(&::originalRuntimeFloatSetting448)))))));
                                changed = 1;
                            }
                        }
                    }
                }
            }
            else if (((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape)))))
                shape.FUN_0066b0d0(0);
            if (((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape)))))
            {
                unsigned int memberCount = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
                RegionArray regionsSlot11(memberCount, 0, 0);
                FloatArray headingsSlot11(memberCount, 0, 0);
                for (unsigned int memberIndex = 0; memberIndex < memberCount; memberIndex++)
                {
                    Actor* member = ((::CombatRegion::Actor *)(reinterpret_cast<::Target *>(this)->GetIntAt(memberIndex)));
                    if (((void *)(reinterpret_cast<::s575ca0::Owner *>((member))->FUN_00575ca0())) != ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(location))->FUN_0084e3a0())))
                        continue;
                    Region memberRegionSlot0(member);
                    if (((bool)(reinterpret_cast<::FUN_0098ad70_Class *>(&(memberRegionSlot0))->FUN_0098ad70())))
                    {
                        reinterpret_cast<::PathingLocationArray *>(&(regionsSlot11))->FUN_006cf1b0((const ::PathingLocation &)(memberRegionSlot0));
                        headingsSlot11.AppendFloat(::WrapAngle(member->Heading(0)));
                    }
                }
                if (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(regionsSlot11))->GetName())))
                {
                    float previous = reinterpret_cast<::BSMultiBoundSphere *>((((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape))))))->GetRadius();
                    ::BuildPathNodeHolder((*(::NiPointer< ::PathSource> *)(&shape)), (::EntryListNode *)(::CombatRegion::RegionArray *)(&regionsSlot11), (::WeightList *)(::CombatRegion::FloatArray *)(&headingsSlot11));
                    if (previous != reinterpret_cast<::BSMultiBoundSphere *>((((::CombatRegion::Shape *)(::FUN_00559450((int *)&(shape))))))->GetRadius())
                        changed = 1;
                }
            }
            reinterpret_cast<::FUN_008d7f40_shell *>(&(updateTimer))->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::CombatRegion::Setting *>(&::g_011ce43c)))))));
            unsigned int actorCountSlot3 = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
            unsigned int chosenSlot40 = ::GetRandomNumberInRange(0, actorCountSlot3);
            Actor* actor = ((::CombatRegion::Actor *)(reinterpret_cast<::Target *>(this)->GetIntAt(chosenSlot40)));
            Group* otherSlot37 = actor->ActorCombatGroup();
            if (actor != (*reinterpret_cast<::CombatRegion::Actor * *>(&::_g_thePlayer)) && otherSlot37)
            {
                Target* target = ((::CombatRegion::Target *)(reinterpret_cast<::ActorCombatGroup *>(this)->FUN_009865d0((int)(otherSlot37))));
                if (target && reinterpret_cast<::CombatTargetTimestamp *>(&(target->point))->FUN_006a7f50() != -::DAT_0108d540)
                    reinterpret_cast<::P029Manager *>(((*reinterpret_cast<::CombatRegion::Manager * *>(&::CombatAssessment::DAT_011f1708))))->TryStartDialogue((::P029Actor *)(actor), otherSlot37, 4, 1, 0, (::P029Input *)(0));
                else
                    reinterpret_cast<::P029Manager *>(((*reinterpret_cast<::CombatRegion::Manager * *>(&::CombatAssessment::DAT_011f1708))))->TryStartDialogue((::P029Actor *)(actor), otherSlot37, 4, 0, 0, (::P029Input *)(0));
            }
        }
    }
}
}

// Recount the group's members: how many are flagged, and how many are alive versus not.

class CE80Process
{
  public:
};

class CE80Actor
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual void Unk130();
    virtual void Unk134();
    virtual void Unk138();
    virtual void Unk13C();
    virtual void Unk140();
    virtual void Unk144();
    virtual void Unk148();
    virtual void Unk14C();
    virtual void Unk150();
    virtual void Unk154();
    virtual void Unk158();
    virtual void Unk15C();
    virtual void Unk160();
    virtual void Unk164();
    virtual void Unk168();
    virtual void Unk16C();
    virtual void Unk170();
    virtual void Unk174();
    virtual void Unk178();
    virtual void Unk17C();
    virtual void Unk180();
    virtual void Unk184();
    virtual void Unk188();
    virtual void Unk18C();
    virtual void Unk190();
    virtual void Unk194();
    virtual void Unk198();
    virtual void Unk19C();
    virtual void Unk1A0();
    virtual void Unk1A4();
    virtual void Unk1A8();
    virtual void Unk1AC();
    virtual void Unk1B0();
    virtual void Unk1B4();
    virtual void Unk1B8();
    virtual void Unk1BC();
    virtual void Unk1C0();
    virtual void Unk1C4();
    virtual void Unk1C8();
    virtual void Unk1CC();
    virtual void Unk1D0();
    virtual void Unk1D4();
    virtual void Unk1D8();
    virtual void Unk1DC();
    virtual void Unk1E0();
    virtual void Unk1E4();
    virtual void Unk1E8();
    virtual void Unk1EC();
    virtual void Unk1F0();
    virtual void Unk1F4();
    virtual void Unk1F8();
    virtual void Unk1FC();
    virtual void Unk200();
    virtual void Unk204();
    virtual void Unk208();
    virtual void Unk20C();
    virtual void Unk210();
    virtual void Unk214();
    virtual void Unk218();
    virtual void Unk21C();
    virtual void Unk220();
    virtual void Unk224();
    virtual void Unk228();
    virtual void Unk22C();
    virtual void Unk230();
    virtual void Unk234();
    virtual void Unk238();
    virtual void Unk23C();
    virtual void Unk240();
    virtual void Unk244();
    virtual void Unk248();
    virtual void Unk24C();
    virtual void Unk250();
    virtual void Unk254();
    virtual void Unk258();
    virtual void Unk25C();
    virtual void Unk260();
    virtual void Unk264();
    virtual void Unk268();
    virtual void Unk26C();
    virtual void Unk270();
    virtual void Unk274();
    virtual void Unk278();
    virtual void Unk27C();
    virtual void Unk280();
    virtual void Unk284();
    virtual void Unk288();
    virtual void Unk28C();
    virtual void Unk290();
    virtual void Unk294();
    virtual void Unk298();
    virtual void Unk29C();
    virtual void Unk2A0();
    virtual void Unk2A4();
    virtual void Unk2A8();
    virtual void Unk2AC();
    virtual void Unk2B0();
    virtual void Unk2B4();
    virtual void Unk2B8();
    virtual void Unk2BC();
    virtual void Unk2C0();
    virtual void Unk2C4();
    virtual void Unk2C8();
    virtual void Unk2CC();
    virtual void Unk2D0();
    virtual void Unk2D4();
    virtual void Unk2D8();
    virtual void Unk2DC();
    virtual void Unk2E0();
    virtual void Unk2E4();
    virtual void Unk2E8();
    virtual void Unk2EC();
    virtual void Unk2F0();
    virtual void Unk2F4();
    virtual void Unk2F8();
    virtual void Unk2FC();
    virtual void Unk300();
    virtual void Unk304();
    virtual void Unk308();
    virtual void Unk30C();
    virtual void Unk310();
    virtual void Unk314();
    virtual void Unk318();
    virtual void Unk31C();
    virtual void Unk320();
    virtual void Unk324();
    virtual void Unk328();
    virtual void Unk32C();
    virtual void Unk330();
    virtual void Unk334();
    virtual void Unk338();
    virtual void Unk33C();
    virtual void Unk340();
    virtual void Unk344();
    virtual void Unk348();
    virtual void Unk34C();
    virtual void Unk350();
    virtual void Unk354();
    virtual void Unk358();
    virtual void Unk35C();
    virtual void Unk360();
    virtual void Unk364();
    virtual void Unk368();
    virtual void Unk36C();
    virtual void Unk370();
    virtual void Unk374();
    virtual void Unk378();
    virtual void Unk37C();
    virtual void Unk380();
    virtual void Unk384();
    virtual void Unk388();
    virtual void Unk38C();
    virtual void Unk390();
    virtual void Unk394();
    virtual void Unk398();
    virtual void Unk39C();
    virtual void Unk3A0();
    virtual void Unk3A4();
    virtual void Unk3A8();
    virtual void Unk3AC();
    virtual void Unk3B0();
    virtual void Unk3B4();
    virtual void Unk3B8();
    virtual void Unk3BC();
    virtual void Unk3C0();
    virtual void Unk3C4();
    virtual void Unk3C8();
    virtual void Unk3CC();
    virtual void Unk3D0();
    virtual void Unk3D4();
    virtual void Unk3D8();
    virtual void Unk3DC();
    virtual void Unk3E0();
    virtual void Unk3E4();
    virtual void Unk3E8();
    virtual void Unk3EC();
    virtual void Unk3F0();
    virtual void Unk3F4();
    virtual void Unk3F8();
    virtual void Unk3FC();
    virtual void Unk400();
    virtual void Unk404();
    virtual void Unk408();
    virtual void Unk40C();
    virtual void Unk410();
    virtual void Unk414();
    virtual void Unk418();
    virtual void Unk41C();
    virtual void Unk420();
    virtual void Unk424();
    virtual CE80Process* GetProcess();
};

class CE80Group
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    unsigned int m_uiFlagged;
    unsigned int m_uiAlive;
    unsigned int m_uiOther;

    void RecountActors();
};

// Resets the flagged, alive and other counters, then tallies each actor's process by IsFlagged and IsAlive.
// @fnv 0x0098ce80
void CE80Group::RecountActors()
{
    m_uiFlagged = 0;
    m_uiAlive = 0;
    m_uiOther = 0;
    unsigned int ItemUpdateArray = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    for (unsigned int i = 0; i < ItemUpdateArray; i++)
    {
        CE80Actor* pkActor = ((::CE80Actor *)(reinterpret_cast<::Target *>(this)->GetIntAt(i)));
        CE80Process* pkAI = pkActor->GetProcess();
        if (pkAI)
        {
            if (reinterpret_cast<::TESForm *>((pkAI))->GetInitialized())
                m_uiFlagged++;
            if (reinterpret_cast<::S981990 *>((pkAI))->FUN_00981990())
                m_uiAlive++;
            else
                m_uiOther++;
        }
    }
}

struct LoadBuf
{
    virtual unsigned char Version();
};
struct LoadPair
{
    int x, y;
};
struct LoadRef
{
    int x;
};
struct LoadItem
{
    int x00, x04, x08, x0c, x10;
    LoadItem();
};
struct LoadNode
{
};
struct MemberNode
{
};
struct LoadExtra
{
    int x00, x04, x08, x0c;
    LoadRef ref;
    int id;
    int value;
};
struct TESObjectREFR : TESForm
{
};
struct ParentNode
{
    TESObjectREFR* a;
    TESObjectREFR* b;
    char c, d, e;
};
struct LoadAnim
{
    int x00;
    int x04;
    int x08;
    int x0c;
    int x10;
    int x14;
    int x18;
    int x1c;
    int x20;
    int x24;
    int x28;
    int x2c;
    int x30;
    int x34;
    int x38;
    int x3c;
    int x40;
    int x44;
    int x48;
    int x4c;
    int x50;
    LoadAnim();
    static void* operator new(unsigned int);
};
struct LoadPtr
{
    LoadAnim* p;
    LoadPtr& operator=(LoadAnim*);
    operator LoadAnim*() const;
};
struct ArrItems
{
    int x0, x4, x8, xc;
};
struct ArrNodes
{
    int x0, x4, x8, xc;
    LoadNode* FUN_0096a2b0(unsigned int);
};
struct ArrMembers
{
    int x0, x4, x8, xc;
    MemberNode* FUN_006dad90(unsigned int) const;
};
struct ArrExtra
{
    int x0, x4, x8, xc;
};
struct ArrParents
{
    int x0, x4, x8, xc;
    ParentNode& GetAt(int);
};
struct LoadHandle
{
    int x0, x4, x8, xc;
};
struct GroupLoad
{
    int unk000;
    int unk004;
    ArrNodes nodes;
    ArrMembers members;
    int strategy;
    char flag;
    char unk02d;
    char unk02e;
    char unk02f;
    LoadPair pair30;
    LoadPair pair38;
    int unk040;
    LoadRef ref44;
    LoadPair pair48;
    LoadPair pair50;
    LoadPair timers[10];
    LoadPair paira8;
    LoadPair pairb0;
    LoadPair pairb8;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    unsigned int active;
    LoadPtr anim;
    LoadPair paird8;
    LoadPair paire0;
    LoadRef refe8;
    int unk0ec;
    LoadHandle handle;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    ArrExtra extras;
    ArrParents parents;
    int unk130;
    char loaded;
    char unk135;
    char unk136;
    char unk137;
    ArrItems items;
    int unk148;
    int unk14c;
    int unk150;
    char flag154;
    void FUN_0098e3d0(LoadBuf* buffer);
};
// Reads item, node and member arrays plus strategy, flags, pairs, timers, active-state extras/parents and optional anim from the buffer.
// @fnv 0x0098e3d0
void GroupLoad::FUN_0098e3d0(LoadBuf* buffer)
{
    {
        unsigned int countItems = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));
        reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>(&(items))->FUN_006f2290(countItems, true);
        for (unsigned int indexItems = 0; indexItems < countItems; indexItems++)
        {
            LoadItem*& item = ((::LoadItem *)(reinterpret_cast<::S3e60 *>(&(items))->FUN_006a7ad0(indexItems)));
            item = new LoadItem;
            reinterpret_cast<::FUN_00985b10_shell *>((item))->FUN_00985b10((::BGSLoadFormBuffer *)(buffer), (int)(this));
        }
    }
    {
        unsigned int countNodes = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));
        reinterpret_cast<::FUN_0098ed80_shell *>(&(nodes))->FUN_0098ed80(countNodes, true);
        for (unsigned int indexNodes = 0; indexNodes < countNodes; indexNodes++)
        {
            LoadNode* node = nodes.FUN_0096a2b0(indexNodes);
            reinterpret_cast<::FUN_00985800_shell *>((node))->FUN_00985800((::BGSLoadFormBuffer *)(buffer), (::ActorCombatGroup *)(void *)(this));
        }
    }
    {
        unsigned int countMembers = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));
        reinterpret_cast<::FUN_0098f040_shell *>(&(members))->FUN_0098f040(countMembers, true);
        for (unsigned int indexMembers = 0; indexMembers < countMembers; indexMembers++)
        {
            MemberNode* member = members.FUN_006dad90(indexMembers);
            reinterpret_cast<::FUN_00985a50_shell *>((member))->FUN_00985a50((::BGSLoadFormBuffer *)(buffer), (::FUN_0098de60_shell *)(void *)(this));
        }
    }
    char strategyIndex = -1;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&strategyIndex), 1);
    if (strategyIndex != -1)
        strategy = FUN_0098e980(strategyIndex);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag), 1);
    reinterpret_cast<::TimeoutTimer *>(&(pair30))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::TimeoutTimer *>(&(pair38))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk040), 4);
    reinterpret_cast<::CombatTargetTimestamp *>(&(ref44))->LoadGame((::BGSLoadGameBuffer *)(buffer));
    reinterpret_cast<::TimeoutTimer *>(&(pair48))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::TimeoutTimer *>(&(pairb0))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::TimeoutTimer *>(&(paira8))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    for (unsigned int indexTimers = 0; indexTimers < 10; indexTimers++)
        reinterpret_cast<::TimeoutTimer *>(&(timers[indexTimers]))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&active), 4);
    if (active > 0)
    {
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&unk0ec));
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk100), 12);
        reinterpret_cast<::TimeoutTimer *>(&(paird8))->LoadGame((::BGSLoadFormBuffer *)(buffer));
        reinterpret_cast<::TimeoutTimer *>(&(paire0))->LoadGame((::BGSLoadFormBuffer *)(buffer));
        if (buffer->Version() >= 5)
            reinterpret_cast<::CombatTargetTimestamp *>(&(refe8))->LoadGame((::BGSLoadGameBuffer *)(buffer));
        reinterpret_cast<::FUN_00527ba0_This *>(&(handle))->FUN_00527ba0((::BGSLoadGameBuffer *)(buffer));
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk10c), 4);
        {
            unsigned int countExtras = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));
            reinterpret_cast<::BSSimpleArrayActor *>(&(extras))->FUN_0098f2f0(countExtras, true);
            for (unsigned int indexExtras = 0; indexExtras < countExtras; indexExtras++)
            {
                LoadExtra* extra = ((::LoadExtra *)(reinterpret_cast<::B98EBC0Array *>(&(extras))->GetElementAt(indexExtras)));
                reinterpret_cast<::FUN_00527ba0_This *>((extra))->FUN_00527ba0((::BGSLoadGameBuffer *)(buffer));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&extra->value), 4);
                reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&extra->id));
                reinterpret_cast<::CombatTargetTimestamp *>(&(extra->ref))->LoadGame((::BGSLoadGameBuffer *)(buffer));
            }
        }
        {
            unsigned int countParents = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60()));
            reinterpret_cast<::H2 *>(&(parents))->FUN_006a8890(countParents, true);
            for (unsigned int indexParents = 0; indexParents < countParents; indexParents++)
            {
                ParentNode& parent = parents.GetAt(indexParents);
                parent.a = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                parent.b = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&parent.c), 1);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&parent.d), 1);
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&parent.e), 1);
            }
        }
        bool hasAnim = false;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&hasAnim), 1);
        if (hasAnim)
        {
            anim = new LoadAnim;
            reinterpret_cast<::FUN_006e0d20_t *>((((LoadAnim*)anim)))->FUN_006e0d20((::BGSLoadFormBuffer *)(buffer));
        }
        loaded = 1;
    }
    reinterpret_cast<::TimeoutTimer *>(&(pair50))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk0c0), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk0c4), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk0c8), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk0cc), 4);
    reinterpret_cast<::TimeoutTimer *>(&(pairb8))->LoadGame((::BGSLoadFormBuffer *)(buffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag154), 1);
}

struct UpdateOwner;
struct UpdateElement
{
    unsigned int data;
};
struct UpdateArray
{
    int unk00, unk04, unk08, unk0c;
    UpdateElement* FUN_0096a2b0(unsigned int);
    UpdateElement* FUN_006dad90(unsigned int);
};
struct UpdateManager
{
};
extern const unsigned int DAT_01183028, DAT_011846d4;
void* FUN_00ec43fb(void*, int, const void*, const void*, int);
struct UpdateOwner
{
    int unk00, unk04;
    UpdateArray first, second;
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
    union
    {
        unsigned int id;
        Actor* actor;
    } reference;
    void UpdateElements(unsigned int);
};
// @fnv 0x0098e990
void UpdateOwner::UpdateElements(unsigned int argument)
{
    unsigned int countFirst = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(first))->GetName()));
    for (unsigned int indexFirst2 = 0; indexFirst2 < countFirst; indexFirst2++)
    {
        bool removeFirst = false;
        UpdateElement* elementFirst = first.FUN_0096a2b0(indexFirst2);
        reinterpret_cast<::Holder00985930 *>((elementFirst))->FUN_00985930(argument, (int)(this));
        if (elementFirst->data)
            reinterpret_cast<::CPStandIn00992a50 *>(((*reinterpret_cast<::UpdateManager * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->FUN_00992a50((::Actor *)(elementFirst->data), (*(::Flt *)(this)));
        else
            removeFirst = true;
        if (removeFirst)
        {
            reinterpret_cast<::RemovalArray *>(&(first))->FUN_0098ef10(indexFirst2, 1);
            indexFirst2--;
            countFirst--;
        }
    }
    {
        unsigned int countSecond4 = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(second))->GetName()));
        for (unsigned int indexSecond = 0; indexSecond < countSecond4; indexSecond++)
        {
            bool removeSecond3 = false;
            UpdateElement* elementSecond3 = second.FUN_006dad90(indexSecond);
            reinterpret_cast<::Holder00985930 *>((elementSecond3))->FUN_00985930(argument, (int)(this));
            if (!elementSecond3->data)
                removeSecond3 = true;
            if (removeSecond3)
            {
                reinterpret_cast<::FUN_0098f1f0_Class *>(&(second))->RemoveEntries(indexSecond, 1);
                indexSecond--;
                countSecond4--;
            }
        }
    }
    if (reinterpret_cast<::FUN_0097ef30_shell *>(this)->FUN_0097ef30())
        reference.actor = reference.id ? dynamic_cast<Actor*>(::FUN_004839c0(reference.id)) : 0;
    reinterpret_cast<::CE80Group *>(this)->RecountActors();
}

namespace fnv_009a1280 {

struct FourFloatVector
{
    float x, y, z, w;
};
struct TimeoutTimer
{
    double __thiscall FUN_00527a40(int result);
};
struct CombatCondition
{
    unsigned char mode;
    unsigned char misc1;
    unsigned char misc2;
    unsigned char misc3;
    unsigned int flags;
    TimeoutTimer timer;
};
struct CombatState
{
    unsigned int id;
    unsigned int type;
};
struct EventEvaluator
{
};
struct CombatController
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    EventEvaluator* evaluator;
};
struct CombatLogic
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    CombatCondition* condition;
    unsigned char miscC8;
    unsigned char phase;
    unsigned short miscCA;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned char needsUpdate;
    unsigned char miscD9;
    unsigned char miscDA;
    unsigned char miscDB;
    unsigned int unk0dc;
    unsigned int unk0e0;
    CombatState* state;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    CombatController* controller;
    void __thiscall FUN_009a1280(bool update);
};
// @fnv 0x009a1280
void CombatLogic::FUN_009a1280(bool update)
{
    if (phase < 4)
    {
        if (((double)(::FUN_0047eeb0(phase))) < ::g_d100)
        {
            ++phase;
        }
        reinterpret_cast<::FUN_0097f200_t *>((controller))->FUN_0097f200();
        if (update && condition && condition->mode == 1)
        {
            FourFloatVector values;
            if (condition->timer.FUN_00527a40(((int)(reinterpret_cast<::FUN_00575650_Class *>((controller->evaluator))->FUN_00575650((::FUN_00575650_Result *)(::fnv_009a1280::FourFloatVector *)(&values))))) < ::DAT_01017a10)
            {
                update = false;
            }
        }
        if (update)
        {
            needsUpdate = false;
        }
        if (state && state->type == 12)
        {
            reinterpret_cast<::FUN_009a03d0_cls *>(this)->FUN_009a03d0(0);
        }
    }
}
}  // namespace fnv_009a1280

struct CFUN98fb40Elem
{
    void* pActor;
    unsigned int m_uiGoalFlags;
    float m_fClusterOffsetX;
    float m_fClusterOffsetY;
    void* pCluster;

    CFUN98fb40Elem();
};

struct CFUN98fb40Owner
{
    void __thiscall FUN_0098fb40(CombatClusterMember* pDest, unsigned int ItemUpdateArray);
};
// Sets the vtable pointer to DAT_0108d708, calls FUN_0098fbe0 with 0, 0, and returns this.
// @fnv 0x0098eff0
void* __thiscall FUN_0098eff0_shell::FUN_0098eff0()
{
    vtable = (void*)&DAT_0108d708;
    reinterpret_cast<::BSSimpleArray_CombatMember_1024 *>((reinterpret_cast<FUN_0098fbe0_shell*>(this)))->FUN_0098fbe0(0, 0);
    return this;
}
// Appends a copy of the given combat member to the array and returns the index it was stored at.
// @fnv 0x0098f180
unsigned int __thiscall BSSimpleArray_CombatMember_1024::AddCombatMember(const CombatClusterMember* aValue)
{
    unsigned int iElementIndex = reinterpret_cast<::S5460 *>(this)->FUN_007881d0();
    reinterpret_cast<::CFUN98fb40Owner *>(this)->FUN_0098fb40(&pBuffer[iElementIndex], 1);
    pBuffer[iElementIndex] = *aValue;
    return iElementIndex;
}
// Resizes the buffer to auiNewSize: clears when zero, reallocates and grows when larger than capacity, shrinks and optionally frees when smaller.
// @fnv 0x0098f040
void FUN_0098f040_shell::FUN_0098f040(unsigned int auiNewSize, bool abFreeMemory)
{
    if (!auiNewSize)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(abFreeMemory);
    }
    else if (auiNewSize > iAllocSize)
    {
        if (!iAllocSize)
        {
            pBuffer = Allocate(auiNewSize);
            iAllocSize = auiNewSize;
        }
        else
        {
            reinterpret_cast<::FUN_009a3c50_cls *>(this)->UpdateThreat(auiNewSize, iSize);
            iAllocSize = auiNewSize;
        }
        reinterpret_cast<::CFUN98fb40Owner *>((((BSSimpleArray_CombatMember_1024*)this)))->FUN_0098fb40(&pBuffer[iSize], auiNewSize - iSize);
        iSize = auiNewSize;
    }
    else if (auiNewSize < iSize)
    {
        ((FUN_0072ba80_shell*)this)->FUN_0072ba80(&pBuffer[auiNewSize], iSize - auiNewSize);
        iSize = auiNewSize;
        if (abFreeMemory && auiNewSize <= iAllocSize >> 2)
        {
            reinterpret_cast<::FUN_009a3c50_cls *>(this)->UpdateThreat(auiNewSize, auiNewSize);
            iAllocSize = auiNewSize;
        }
    }
    else
    {
        reinterpret_cast<::CFUN98fb40Owner *>((((BSSimpleArray_CombatMember_1024*)this)))->FUN_0098fb40(&pBuffer[iSize], auiNewSize - iSize);
        iSize = auiNewSize;
    }
}

// @fnv 0x0098fb40
void CFUN98fb40Owner::FUN_0098fb40(CombatClusterMember* pDest, unsigned int auiCount)
{
    for (unsigned int i = 0; i < auiCount; i++)
    {
        new (&pDest[i]) CFUN98fb40Elem();
    }
}

struct ScoreValue
{
    int value;
    ScoreValue(float x);
    ScoreValue();
};
struct PoseData
{
    float a, b, c;
    int d;
    float FUN_00527a40(const PoseData*);
};
struct MovementPose;
struct OtherState
{
    ScoreValue GetValue98();
};
struct MovementPose
{
    PoseData* GetValue98();
};
struct ConditionFlag
{
};
struct ConfigSwitch
{
    unsigned char* FUN_00408d60();
};
extern float DAT_0101ff50, DAT_0108d660, DAT_011a4d78, DAT_011a4d74;
extern float DAT_011a4d70, DAT_011a4d6c, DAT_011a4d68, DAT_011a4d64, DAT_011a4d60;
extern float DAT_011f18b0, DAT_011a4d5c, DAT_011a4d58, DAT_011a4d54, DAT_011a4d50;
extern double DAT_0108d658, DAT_0101db88;
struct ActorSelect
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual int GetDistanceValue();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool GetFirstCondition(int);
    virtual bool GetSecondCondition();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual ActorSelect* GetTarget();
};
struct CandidateLink
{
    ActorSelect* actor;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    int unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    unsigned short unk48;
    unsigned short threshold;
    int unk4c, unk50, unk54;
    ScoreValue timestamp;
};
struct ActorPicker
{
    int unk00;
    int unk04;
    ConditionFlag condition;
    int unk0c;
    CandidateLink* FUN_009871c0(unsigned int);
    ActorSelect* SelectActor(ActorSelect*);
};
// @fnv 0x00986c60
ActorSelect* ActorPicker::SelectActor(ActorSelect* actor)
{
    if (reinterpret_cast<::FUN_0076b610_Class *>(&(condition))->FUN_0076b610())
        return 0;
    float bestScore7 = -DAT_0108d540;
    ScoreValue reference_2(-DAT_0108d540);
    ActorSelect* bbestActor9 = 0;
    ActorSelect* ffirstActor3 = 0;
    ActorSelect* fallbackTmp = 0;
    PoseData baactorPose_2;
    reinterpret_cast<::FUN_00575650_Class *>((actor))->FUN_00575650((::FUN_00575650_Result *)(::PoseData *)(&baactorPose_2));
    ActorSelect* centerA = actor->GetTarget();
    if (!centerA)
    {
        reinterpret_cast<::FUN_009869a0_shell *>(this)->FUN_009869a0((::Actor *)(actor));
        return 0;
    }
    ActorSelect* firstB8 = (ActorSelect*)((int)(reinterpret_cast<::AlchemyItem *>((centerA))->FUN_004030b0()));
    OtherState* pkState3 = ((::OtherState *)(reinterpret_cast<::InterfaceManager *>((centerA))->FUN_00586150()));
    float thresholdA = reinterpret_cast<::FUN_00639aa0_shell *>((((::MovementPose *)(reinterpret_cast<::FUN_00980070_shell *>((centerA))->FUN_00980070()))))->FUN_00639aa0();
    int factionNum = ((int)(reinterpret_cast<::ActorS *>((actor))->FUN_00567d90()));
    bool hactorTypeTmp = ::FUN_009a9630(actor);
    unsigned int count113 = ((int)(::FUN_005a4320((char *)this)));
    for (unsigned int index = 0; index < count113; ++index)
    {
        CandidateLink* entry36 = FUN_009871c0(index);
        ActorSelect* candidate18 = entry36->actor;
        if (thresholdA > 0.0)
        {
            if (!::IsWithinAimLimits((::S_009a6d70_Actor *)(actor), (::NiPoint3 *)(candidate18->GetDistanceValue()), (float)(thresholdA * ::DAT_01023128),
                                   DAT_0101ff50))
                continue;
        }
        if (*(*reinterpret_cast<::ConfigSwitch *>(&::g_011f1840)).FUN_00408d60())
        {
            int candidateFaction = ((int)(reinterpret_cast<::ActorS *>((candidate18))->FUN_00567d90()));
            if (factionNum != candidateFaction)
                continue;
        }
        if (reinterpret_cast<::MiddleHighProcess *>((actor))->IsActorInCombat())
        {
            int ignored = 0;
            if (!reinterpret_cast<::HostActor *>((actor))->IsHostileTo((::HostActor *)(candidate18), 0, &ignored, 0))
                continue;
        }
        bool lOther = false;
        int pisValid_ = 0;
        bool bshapeChanged_2 = false;
        bool isClose = false;
        ScoreValue value3;
        reinterpret_cast<::CombatAssessment::Group *>(this)->UpdateTargetPerception((::CombatAssessment::Actor *)(actor), (::CombatAssessment::Actor *)(candidate18), &pisValid_, (::CombatAssessment::Time *)(::ScoreValue *)(&value3), &bshapeChanged_2, &isClose);
        if (pisValid_ < 0 && candidate18 == firstB8 && reinterpret_cast<::fnv_0097ee90::DummyInner *>((pkState3))->FUN_0097ee90())
            pisValid_ = 1;
        if (pisValid_ > 0)
        {
            float score = 0.0f;
            if (count113 > 1)
            {
                if (isClose)
                    score += DAT_011a4d78;
                if (bshapeChanged_2)
                    score += DAT_011a4d74;
                if (firstB8 == candidate18)
                {
                    score += DAT_011a4d70;
                    if (!isClose)
                    {
                        if (reinterpret_cast<::FUN_00435e00_t *>((void *)&(const ::ScoreValue &)((*(::ScoreValue *)(reinterpret_cast<::FUN_0097fb00_cls *>((((::OtherState *)(reinterpret_cast<::InterfaceManager *>((centerA))->FUN_00586150()))))->GetValue98({})))))->FUN_00435e00() < DAT_011a4d6c)
                            score += DAT_011a4d78;
                    }
                }
                bool kcandidateType3 = ::FUN_009a9630(candidate18);
                if (hactorTypeTmp == kcandidateType3)
                    score += DAT_011a4d68;
                float pmeasure9 = 0.0f;
                PoseData spose8;
                reinterpret_cast<::FUN_00575650_Class *>((candidate18))->FUN_00575650((::FUN_00575650_Result *)(::PoseData *)(&spose8));
                bool difference3 = reinterpret_cast<::FUN_0084e3a0_Class *>(&(spose8))->FUN_0084e3a0() != reinterpret_cast<::FUN_0084e3a0_Class *>(&(baactorPose_2))->FUN_0084e3a0();
                if (difference3)
                {
                    if (candidate18 == firstB8)
                        pmeasure9 = 0.0f;
                    else
                        pmeasure9 = DAT_011a4d64 * DAT_011a4d64;
                }
                else
                {
                    pmeasure9 = baactorPose_2.FUN_00527a40(&spose8);
                }
                pmeasure9 = FUN_0040ebd0(DAT_0108d660, pmeasure9);
                score += (1.0f - pmeasure9 / DAT_0108d658) * DAT_011a4d60;
                unsigned int cfsameActor = firstB8 == candidate18;
                if (entry36->threshold > cfsameActor)
                    score += DAT_011f18b0;
                if ((reinterpret_cast<::FUN_009871e0_shell *>((pkState3))->IsModifierZero() || difference3) && reinterpret_cast<::fnv_009a0f40::FUN_009a0f40_struct *>((pkState3))->HasItemWithinRadius((const ::fnv_009a0f40::CoordinateTriple *)(const ::PoseData *)(&spose8), ::DAT_01032adc))
                    score -= DAT_011a4d5c;
                if (difference3 && !::FUN_009a96f0((::TESObjectREFR *)(actor), (::CoordinateTriple *)(::PoseData *)(&spose8)))
                    score -= DAT_011a4d58;
                if (candidate18->GetFirstCondition(0) || candidate18->GetSecondCondition())
                    score -= DAT_011a4d54;
                if (reinterpret_cast<::FleeActorEntry *>((candidate18))->FUN_008a6650(0))
                    score -= DAT_011a4d50;
            }
            if (score > bestScore7)
            {
                bestScore7 = score;
                bbestActor9 = candidate18;
            }
        }
        else
        {
            float cutoff = reinterpret_cast<::CombatTargetTimestamp *>(&(entry36->timestamp))->FUN_006a7f50() - DAT_0101db88;
            value3 = FUN_00404010(cutoff, reinterpret_cast<::CombatTargetTimestamp *>(&(value3))->FUN_006a7f50());
            if (reinterpret_cast<::CombatTargetTimestamp *>(&(value3))->FUN_006a7f50() > reinterpret_cast<::CombatTargetTimestamp *>(&(reference_2))->FUN_006a7f50())
            {
                ffirstActor3 = candidate18;
                reference_2 = value3;
            }
        }
        fallbackTmp = candidate18;
    }
    if (!bbestActor9)
        bbestActor9 = ffirstActor3;
    if (!bbestActor9)
        bbestActor9 = fallbackTmp;
    return bbestActor9;
}

struct B989700Entry
{
    B9897F0Ref* m_pkRef;
};
struct B989700List
{
    B989700Entry* FUN_009871c0(unsigned int uiIndex);
    B9897F0Ref* FindRefInRadius(B9897F0Point* pkPoint, float fRadius, bool bCheck);
};
// @fnv 0x00989700
B9897F0Ref* B989700List::FindRefInRadius(B9897F0Point* pkPoint, float afRadius, bool bCheck)
{
    float fRadiusSqr = afRadius * afRadius;
    unsigned int ItemUpdateArray = ::FUN_005a4320((char *)this);
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        B989700Entry* pkEntry = FUN_009871c0(i);
        if (!bCheck || reinterpret_cast<::fnv_009897a0::Host *>((pkEntry))->IsElapsedTimeBelowSetting())
        {
            B9897F0Quad kPos = (*(::B9897F0Quad *)(reinterpret_cast<::FUN_00575650_Class *>((pkEntry->m_pkRef))->FUN_00575650({})));
            if (pkPoint->GetSquaredDistance(kPos) < fRadiusSqr)
                return pkEntry->m_pkRef;
        }
    }
    return 0;
}

struct B9898B0Group
{
    B9897F0Ref* FindClosestRef(B9897F0Point* pkPoint, B9897F0Ref* pkExclude, float fRadius);
};
// @fnv 0x00989970
void __thiscall S989970::FUN_00989970(Ref_997440* apRef, float afValue)
{
    B16 b;
    reinterpret_cast<::B9898B0Group *>(this)->FindClosestRef((::B9897F0Point *)(((int)(reinterpret_cast<::FUN_00575650_Class *>((apRef))->FUN_00575650((::FUN_00575650_Result *)(void *)(&b))))), {}, {});
}
// @fnv 0x009898b0
B9897F0Ref* B9898B0Group::FindClosestRef(B9897F0Point* pkPoint, B9897F0Ref* pkExclude, float afMaxDist)
{
    float fBestDistSqr2 = (afMaxDist == DAT_0108d540) ? DAT_0108d540 : (float)(afMaxDist * afMaxDist);
    B9897F0Ref* pkClosest = 0;
    unsigned int uiCount2 = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    for (unsigned int i = 0; i < uiCount2; ++i)
    {
        B9897F0Ref* pkRef = ((::B9897F0Ref *)(reinterpret_cast<::Target *>(this)->GetIntAt(i)));
        if (pkRef == pkExclude)
            continue;
        B9897F0Quad kPos = (*(::B9897F0Quad *)(reinterpret_cast<::FUN_00575650_Class *>((pkRef))->FUN_00575650({})));
        float fDistSqr2 = pkPoint->GetSquaredDistance(kPos);
        if (fDistSqr2 < fBestDistSqr2)
        {
            fBestDistSqr2 = fDistSqr2;
            pkClosest = pkRef;
        }
    }
    return pkClosest;
}

struct AssessmentSub
{
};

struct AssessmentProcess
{
};

struct AssessmentActor : FUN_0098cb30_inner
{
    float FUN_008be600();
};

struct TargetAssessmentEntry
{
    AssessmentActor* actor;
    int unk04;
    float unk08;
    float unk0C;
};

struct TargetAssessmentGroup
{
    int unk00;
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
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    float unkC0;
    float unkC4;
    float unkC8;
    float unkCC;

    TargetAssessmentEntry* FUN_00988790(unsigned int idx);

    void FUN_0098c870();
};
// @fnv 0x00986150
void FUN_00986150_shell::FUN_00986150()
{
    reinterpret_cast<::CE80Group *>((this))->RecountActors();

    if (reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0xa8)->CheckTimer())
    {
        reinterpret_cast<FUN_0098cf70_shell*>(this)->CountActorsPerNode();
        reinterpret_cast<::Group_98d030 *>((this))->FUN_0098d030();
        reinterpret_cast<FUN_008d7f40_shell*>(reinterpret_cast<char*>(this) + 0xa8)->FUN_008d7f40(::DAT_010162c0);
    }

    reinterpret_cast<::FUN_0098d1a0_shell *>((this))->UpdateChoiceSelection();
    this->FUN_0098a580();

    if (reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0x50)->CheckTimer())
    {
        reinterpret_cast<::TargetAssessmentGroup *>((this))->FUN_0098c870();
        reinterpret_cast<FUN_008d7f40_shell*>(reinterpret_cast<char*>(this) + 0x50)
            ->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting493)))))));
    }

    if (reinterpret_cast<::FUN_00990890_shell *>((this))->FUN_00990890() > 1)
        reinterpret_cast<::ClusterWork *>((this))->UpdateGroups();

    if (*reinterpret_cast<signed char*>(reinterpret_cast<char*>(this) + 0x154) == -1)
    {
        if (!reinterpret_cast<FUN_0097fa50_Class*>(reinterpret_cast<char*>(this) + 0xb8)->FUN_0097fa50())
        {
            if (!reinterpret_cast<::FUN_0097ef30_shell *>((reinterpret_cast<InnerObj*>(this)))->FUN_0097ef30())
            {
                reinterpret_cast<FUN_008d7f40_shell*>(reinterpret_cast<char*>(this) + 0xb8)
                    ->FUN_008d7f40(*((float *)&(::FUN_00403e20((float *)&(::g_011ceb44)))));
            }
        }
        else if (reinterpret_cast<TimeoutTimer*>(reinterpret_cast<char*>(this) + 0xb8)->CheckTimer())
        {
            *reinterpret_cast<signed char*>(reinterpret_cast<char*>(this) + 0x154) = 0;

            if (*reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc8) > _DAT_01012060)
            {
                float ratio = *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc0) /
                              *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xc8);

                if (ratio > *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting487)))))) && ratio < *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting_S *>(&::originalRuntimeFloatSetting488)))))))
                {
                    *reinterpret_cast<signed char*>(reinterpret_cast<char*>(this) + 0x154) = 1;
                }
            }
        }
    }
}

// @fnv 0x0098c870
void TargetAssessmentGroup::FUN_0098c870()
{
    unsigned int _countLocal;
    unsigned int _totalCells;
    unsigned int _modelCount;
    unsigned int _total;
    unsigned int _sampleIndex;
    bool _attackFlag;
    TargetAssessmentEntry* _itemBuffer;
    AssessmentProcess* _pProcess;
    unsigned int _curIdx;
    AssessmentActor* _TargetModeCur;
    float _ValPitch6;
    AssessmentProcess* _process;

    unkC0 = 0.0f;
    unkC4 = 0.0f;

    _modelCount = reinterpret_cast<::FUN_00990890_shell *>(this)->FUN_00990890();
    _total = 0;
    for (_sampleIndex = 0; _sampleIndex < _modelCount; _sampleIndex++)
    {
        _attackFlag = false;
        _itemBuffer = FUN_00988790(_sampleIndex);
        if (_itemBuffer->actor == (AssessmentActor*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))
        {
            _itemBuffer->unk08 = ((AssessmentActor*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))->FUN_008be600();
            _itemBuffer->unk0C = reinterpret_cast<::fnv_008acbe0::FUN_008acbe0_shell *>((((AssessmentActor*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->GetModifiedDamagePerSecond(_itemBuffer->unk08);
        }
        else
        {
            _pProcess = (AssessmentProcess*)_itemBuffer->actor->v10A();
            if (_pProcess)
            {
                _attackFlag = reinterpret_cast<::S981990 *>((_pProcess))->FUN_00981990();
                _itemBuffer->unk08 = reinterpret_cast<::fnv_00979260::Projectile *>((((::AssessmentSub *)(reinterpret_cast<::InterfaceManager *>((_pProcess))->FUN_00586150()))))->GetFirstLightParameter();
                _itemBuffer->unk0C = reinterpret_cast<::FUN_00453700_shell *>((((::AssessmentSub *)(reinterpret_cast<::InterfaceManager *>((_pProcess))->FUN_00586150()))))->FUN_00453700();
            }
        }

        if (!_attackFlag && _itemBuffer->unk0C >= 0.0 && _itemBuffer->unk08 >= 0.0)
        {
            unkC0 += _itemBuffer->unk0C;
            unkC4 += _itemBuffer->unk08;
            _total++;
        }
    }

    if (_total)
    {
        unkC4 = unkC4 / _total;
    }

    unkC8 = 0.0f;
    unkCC = 0.0f;

    _countLocal = ::FUN_005a4320((char *)this);
    _totalCells = 0;
    for (_curIdx = 0; _curIdx < _countLocal; _curIdx++)
    {
        _ValPitch6 = -1.0f;
        _TargetModeCur = ((::AssessmentActor *)(reinterpret_cast<::FUN_00968630_stub *>(this)->FUN_00968630(_curIdx)));
        if (_TargetModeCur == (AssessmentActor*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))
        {
            _ValPitch6 = reinterpret_cast<::fnv_008acbe0::FUN_008acbe0_shell *>((((AssessmentActor*)(*reinterpret_cast<::Actor * *>(&::_g_thePlayer)))))->GetModifiedDamagePerSecond(-1.0f);
        }
        else if (!reinterpret_cast<::FleeActorEntry *>((_TargetModeCur))->FUN_008a6650(0))
        {
            _process = (AssessmentProcess*)_TargetModeCur->v10A();
            if (_process)
            {
                _ValPitch6 = reinterpret_cast<::FUN_00453700_shell *>((((::AssessmentSub *)(reinterpret_cast<::InterfaceManager *>((_process))->FUN_00586150()))))->FUN_00453700();
            }
            else
            {
                _ValPitch6 = reinterpret_cast<::fnv_008acbe0::FUN_008acbe0_shell *>((_TargetModeCur))->GetModifiedDamagePerSecond(-1.0f);
            }
        }

        if (_ValPitch6 >= 0.0)
        {
            unkC8 += _ValPitch6;
            _totalCells++;
        }
    }

    if (_totalCells)
    {
        unkCC = unkC8 / _totalCells;
    }
}

struct ActQ
{
    virtual void v000(), v001(), v002(), v003(), v004(), v005(), v006(), v007(), v008(), v009(), v010(), v011(), v012(),
        v013(), v014(), v015(), v016(), v017(), v018(), v019(), v020(), v021(), v022(), v023(), v024(), v025(), v026(),
        v027(), v028(), v029(), v030(), v031(), v032(), v033(), v034(), v035(), v036(), v037(), v038(), v039(), v040(),
        v041(), v042(), v043(), v044(), v045(), v046(), v047(), v048(), v049(), v050(), v051(), v052(), v053(), v054(),
        v055(), v056(), v057(), v058(), v059(), v060(), v061(), v062(), v063(), v064(), v065(), v066(), v067(), v068(),
        v069(), v070(), v071(), v072(), v073(), v074(), v075();
    virtual const char* GetNameQ();
};
struct TgtQ
{
    int unk[26];
};
struct TgtLstQ
{
    int unk00;
};
struct GrpQ;
struct UpdQ
{
};
struct GrpQ
{
    int unk00, unk04;
    TgtLstQ kTargets;
    char pad[0xc4];
    int unkD0;
    bool FUN_00986410(ActQ* pActor);
};
// Merges another combat group's targets, entries and members into this one, warning on members or targets that cannot be added, and copies its state.
// @fnv 0x00987530
bool ActorMergeData::MergeFrom(ActorMergeData* other)
{
    MergeTargets* otherMembers = ((::MergeTargets *)(reinterpret_cast<::TESTopicInfoData *>((other))->GetLinkToList()));
    for (unsigned int i = 0; i < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((otherMembers))->GetName())); ++i)
    {
        MergeTarget* target = otherMembers->FUN_0096a2b0(i);
        if (!reinterpret_cast<::fnv_009866d0::FUN_009866d0_shell *>(this)->FUN_009866d0((::fnv_009866d0::Actor *)(target->actor)))
            return false;
    }
    for (unsigned int j = 0; j < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(targets))->GetName())); ++j)
    {
        MergeTarget* target = targets.FUN_0096a2b0(j);
        if (!reinterpret_cast<::fnv_009866d0::FUN_009866d0_shell *>((other))->FUN_009866d0((::fnv_009866d0::Actor *)(target->actor)))
            return false;
    }
    for (unsigned int k = 0; k < ((char)(reinterpret_cast<::FUN_009877c0_shell *>((other))->GetFlagsFromSubobject())); ++k)
    {
        int entry = reinterpret_cast<::FUN_0098de60_shell *>((other))->GetArrayItem((unsigned char)k);
        reinterpret_cast<::FUN_00438690 *>(&(entries))->FUN_007cb2e0((unsigned int *)&(entry));
    }
    reinterpret_cast<::FUN_009877e0_shell *>((other))->ClearGlobalObject();
    MergeMembers* otherState = ((::MergeMembers *)(reinterpret_cast<::BGSCameraPath *>((other))->GetConditions()));
    for (unsigned int m = 0; m < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((otherState))->GetName())); ++m)
    {
        MergeMember* member = otherState->FUN_006dad90(m);
        if (reinterpret_cast<::CombatGroup_009867d0 *>(this)->FUN_009867d0((::ActorV *)(member->actor)))
        {
            member->actor->SetCombatGroup(this);
            MergeMember* destination = ((::MergeMember *)(reinterpret_cast<::FUN_009865f0_shell *>(this)->FUN_009865f0((int)(member->actor))));
            if (destination)
                reinterpret_cast<::FUN_00985980_shell *>((destination))->CopyFrom((::FUN_00985980_shell *)(member));
        }
        else
            ::FUN_005b5e40();
    }
    for (unsigned int n = 0; n < ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((otherMembers))->GetName())); ++n)
    {
        MergeTarget* target = otherMembers->FUN_0096a2b0(n);
        if (reinterpret_cast<::GrpQ *>(this)->FUN_00986410((::ActQ *)(target->actor)))
        {
            MergeTarget* destination = ((::MergeTarget *)(reinterpret_cast<::ActorCombatGroup *>(this)->FUN_009865d0((int)(target->actor))));
            if (destination)
                reinterpret_cast<::CombatMemberData_985520 *>((destination))->MergeCombatData((::CombatMemberData_985520 *)(target));
        }
        else
            ::FUN_005b5e40();
    }
    char otherTargets = reinterpret_cast<::FUN_00987800_shell *>((other))->GetByteAtOffset154();
    if (otherTargets != -1)
        state = otherTargets;
    return true;
}
// Returns early based on two actor checks, rejects actors accepted by a third check, otherwise appends a target and updates the group.
// @fnv 0x00986410
bool GrpQ::FUN_00986410(ActQ* pActor)
{
    if (!pActor)
        return false;
    if (reinterpret_cast<::FUN_009865b0_shell *>(this)->FUN_009865b0((int)(pActor)))
        return true;
    if (!reinterpret_cast<::fnv_009866d0::FUN_009866d0_shell *>(this)->FUN_009866d0((::fnv_009866d0::Actor *)(pActor)))
        return false;
    if (((bool)(reinterpret_cast<::FUN_00986a80_shell *>(this)->FUN_00986a80((int)(pActor)))))
    {
        ::FUN_005b5e40();
        return false;
    }
    TgtQ kTarget;
    reinterpret_cast<::BSSimpleArray_CombatTarget_1024 *>(&(kTargets))->FUN_0098eec0((const ::CombatTarget *)(::TgtQ *)(((::TgtQ *)(reinterpret_cast<::EventRecord *>(&(kTarget))->Init((::EventSource *)(pActor), unkD0)))));
    reinterpret_cast<::CombatBox *>((((UpdQ*)(*reinterpret_cast<::UpdateManager * *>(&::BGSSaveLoadGlobalDataWorldspacePtr)))))->FUN_009926c0((unsigned int)(this), (unsigned int)(pActor));
    return true;
}

struct Owner_9862e0;
struct Target_9862e0
{
    virtual void v0();
    virtual void v4(Owner_9862e0* owner, void* ctx);
};
struct CombatCtx
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
    CombatCtx(Owner_9862e0* owner);
    ~CombatCtx();
};
struct Owner_9862e0
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
    Target_9862e0* m28;
    bool m2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int m40;
    TimeValue m44;
    void FUN_009862e0(Target_9862e0* target);
};
// Stores target in m28; when non-null, creates CombatCtx, calls FUN_0098a3c0 and target->v4, updates m40, m44, and m2c; otherwise clears m2c.
// @fnv 0x009862e0
void Owner_9862e0::FUN_009862e0(Target_9862e0* target)
{
    m28 = target;
    if (m28)
    {
        CombatCtx ctx(this);
        reinterpret_cast<::FUN_0098a3c0_shell *>(this)->FUN_0098a3c0();
        m28->v4(this, &ctx);
        m40 = ((int)(reinterpret_cast<::Callees *>((m28))->FUN_00726070()));
        TimeValue t;
        reinterpret_cast<::FUN_00435de0_ctor *>(&(t))->FUN_00435de0(FUN_00435dd0());
        m44 = t;
        m2c = true;
    }
    else
    {
        m2c = false;
    }
}


struct FUN_00906f60
{
    int a;
    int b;
    FUN_00906f60();
};

struct Member08_985d10
{
    int a, b, c, d;
    Member08_985d10();
    ~Member08_985d10();
};

struct Member18_985d10
{
    int a, b, c, d;
    Member18_985d10();
    ~Member18_985d10();
};

struct Member44_985d10
{
    int a;
    Member44_985d10();
};

struct MemberD4_985d10
{
    void* p;
    MemberD4_985d10(void*);
    ~MemberD4_985d10();
};

struct MemberE8_985d10
{
    float f;
    MemberE8_985d10(float);
};

struct MemberF0_985d10
{
    int a, b, c, d;
    MemberF0_985d10();
};

struct Member110_985d10
{
    int a, b, c, d;
    Member110_985d10();
    ~Member110_985d10();
};

struct Member120_985d10
{
    int a, b, c, d;
    Member120_985d10();
    ~Member120_985d10();
};

struct Member138_985d10
{
    int a, b, c, d;
    Member138_985d10();
    ~Member138_985d10();
};

struct FUN_00985d10
{
    int m_00;
    int m_04;
    Member08_985d10 m_08;
    Member18_985d10 m_18;
    int m_28;
    bool m_2c;
    FUN_00906f60 m_30;
    FUN_00906f60 m_38;
    int m_40;
    Member44_985d10 m_44;
    FUN_00906f60 m_48;
    FUN_00906f60 m_50;
    FUN_00906f60 m_58[10];
    FUN_00906f60 m_a8;
    FUN_00906f60 m_b0;
    FUN_00906f60 m_b8;
    float m_c0;
    float m_c4;
    float m_c8;
    float m_cc;
    int m_d0;
    MemberD4_985d10 m_d4;
    FUN_00906f60 m_d8;
    FUN_00906f60 m_e0;
    MemberE8_985d10 m_e8;
    int m_ec;
    MemberF0_985d10 m_f0;
    NiPoint3 m_100;
    float m_10c;
    Member110_985d10 m_110;
    Member120_985d10 m_120;
    MemberD4_985d10 m_130;
    bool m_134;
    Member138_985d10 m_138;
    int m_148;
    int m_14c;
    int m_150;
    char m_154;
    MemberD4_985d10 m_158;

    FUN_00985d10(int a1);
};

// Initializes all members of FUN_00985d10, setting m_04 to a1 and several float fields to DAT_01012054.
// @fnv 0x00985d10
FUN_00985d10::FUN_00985d10(int a1)
    : m_00(0), m_04(a1), m_28(0), m_2c(false), m_40(0), m_c0(DAT_01012054), m_c4(DAT_01012054), m_c8(DAT_01012054),
      m_cc(DAT_01012054), m_d0(0), m_d4(0), m_e8(-DAT_0108d540), m_ec(0), m_100(::NiPoint3::ZERO), m_10c(0.0f), m_130(0),
      m_134(false), m_148(0), m_14c(0), m_150(0), m_154(-1), m_158(0)
{}

struct AvoidNode9894 : AvoidanceVectorData
{
    AvoidNode9894(const NiPoint3& arPos, float afR, float afHeight);
};

struct AvoidArray9894 : PathingAvoidNodeArray
{
};

struct FUN_00989490_shell
{
    float GetBoundsSq(NiPoint3* apCenter);
    PathingAvoidNodeArray* __thiscall FUN_00989490(int a1, int a2, int a3, PathingAvoidNodeArray* apArray);
};

// Adds an avoidance node at the target center with a radius derived from the bounds square to the given pathing avoid node array.
// @fnv 0x00989490
PathingAvoidNodeArray* __thiscall FUN_00989490_shell::FUN_00989490(int aiUnused1, int aiUnused2, int aiUnused3,
                                                                   PathingAvoidNodeArray* apArray)
{
    B006815c0 kTargetCenter;
    float fBoundsSq;
    float fR = 1024.0f;
    fBoundsSq = GetBoundsSq(&kTargetCenter);
    if (fBoundsSq > fR * fR)
        fR = FUN_004579e0(fBoundsSq);
    PathingAvoidNodeArray* pArray = apArray;
    if (!pArray)
        pArray = new PathingAvoidNodeArray;
    reinterpret_cast<::FUN_00905450_StandIn *>((static_cast<AvoidArray9894*>(pArray)))->AppendNode(
        (::PathingAvoidanceNode *)&(const ::AvoidanceVectorData &)(AvoidNode9894(kTargetCenter, fR, FUN_00403e20((float*)&originalRuntimeFloatSetting384) * 4.0)));
    return pArray;
}

struct S009865d0_CombatGroup : ActorCombatGroup
{
    void* FUN_009865d0(int param);
};

// @fnv 0x009865d0
void* S009865d0_CombatGroup::FUN_009865d0(int aiRef)
{
    return reinterpret_cast<FUN_00986610_shell*>(this)->FUN_00986610(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<RefObj*>(aiRef)))->FUN_0084e3a0())));
}
