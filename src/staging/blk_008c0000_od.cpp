
// src/staging/blk_008c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include "runtime/crt.h"
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/B_008b3630.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Character.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0040e500_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0044fb00_Shim.h"
#include "fnv/decl/FUN_0045a5e0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0046a010_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004ae6a0_shell.h"
#include "fnv/decl/FUN_004b6190_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_006205a0_Class.h"
#include "fnv/decl/FUN_00622570_Class.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_00810f90_shell.h"
#include "fnv/decl/FUN_0085f810_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_0087f660_cls.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_008c9fb0_shell.h"
#include "fnv/decl/FUN_008ce390_shell.h"
#include "fnv/decl/FUN_0096bbc0_cls.h"
#include "fnv/decl/FUN_009cdae0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a6d220.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiTimeControllerCM.h"
#include "fnv/decl/Owner5615.h"
#include "fnv/decl/Projectile8CD.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/decl/S_0087cea0.h"
#include "fnv/decl/SceneProjectile.h"
#include "fnv/decl/ShadowSceneNode.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_0080f7d0.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00571530__FUN_00571530_shell.h"
#include "fnv/decl/fnv_00573ed0___dummy_4d9fa0.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008b3880__FUN_008b3880_target.h"
#include "fnv/decl/fnv_008d55b0__FUN_008d55b0_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/decl/fnv_00c705c0__FUN_00c705c0.h"
#include "fnv/decl/fnv_00c741e0__FUN_00c741e0.h"
#include "fnv/decl/hkpPositionTrackerCBB1.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0044f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004ae000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00571000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005db000.h"
#include "fnv/symbols_00624000.h"
#include "fnv/symbols_0062b000.h"
#include "fnv/symbols_00631000.h"
#include "fnv/symbols_006a9000.h"
#include "fnv/symbols_006fa000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_008cd000.h"
#include "fnv/symbols_008d1000.h"
#include "fnv/symbols_008d5000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00a29000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_00c6a000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01084000.h"
#include "fnv/symbols_01085000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_01203000.h"
#include "../../include/layout_support.h"

struct FUN_008c1be0_Class
{
    unsigned int FUN_008c1be0(unsigned int mask);
};

// @fnv 0x008c1be0
unsigned int FUN_008c1be0_Class::FUN_008c1be0(unsigned int mask)
{
    return *reinterpret_cast<unsigned int*>(this) & mask;
}

struct AX
{
    void FUN_006b3eb0(unsigned int, unsigned int);
};
struct PAVActor
{
    AX* FUN_008c1c00();
};
// @fnv 0x008c1c00
AX* PAVActor::FUN_008c1c00()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_01084fec;
    ((AX*)this)->FUN_006b3eb0(0, 0);
    return (AX*)this;
}

struct BooleanFloatQuery
{
    void DecRefCount();
};
struct S_008c1c60
{
    void FUN_008c1c60();
};
// @fnv 0x008c1c60
void S_008c1c60::FUN_008c1c60()
{
    if (*reinterpret_cast<BooleanFloatQuery**>(this))
        reinterpret_cast<::S_0087cea0 *>((reinterpret_cast<BooleanFloatQuery**>(this)[0]))->ReleaseScriptRunLock();
}

struct FlaggedData
{
    int ContainsAnyFlag(unsigned int);
    int FUN_008c2e30();
};

int FlaggedData::ContainsAnyFlag(unsigned int)
{
    return 0;
}

// @fnv 0x008c2e30
int FlaggedData::FUN_008c2e30()
{
    return ContainsAnyFlag(4);
}

struct FUN_008c5000_shell
{
    int FUN_008c5000(int);
    int IsNonZero(int arg);
};

// @fnv 0x008c4fe0
int FUN_008c5000_shell::IsNonZero(int arg)
{
    return FUN_008c5000(arg) != 0;
}

struct ActorPackageContext
{
    void Clear();
};

void ActorPackageContext::Clear()
{}

struct FUN_008c6c80_Class
{
    void FUN_008c6c80(int a);
};

// @fnv 0x008c6c80
void FUN_008c6c80_Class::FUN_008c6c80(int a)
{
    reinterpret_cast<ActorPackageContext*>(this)->Clear();
}

extern int DAT_01085864;
struct FUN_008ca740_class
{
    FUN_008ca740_class* FUN_008ca740();
};

struct FUN_008ca7a0_cls
{
    void* vtbl;
    void* InitializeVtbl();
};
// @fnv 0x008ca740
FUN_008ca740_class* FUN_008ca740_class::FUN_008ca740()
{
    reinterpret_cast<::FUN_008ca7a0_cls *>(this)->InitializeVtbl();
    *reinterpret_cast<void**>(this) = &DAT_01085864;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 4) = 0;
    return this;
}

// @fnv 0x008ca7a0
void* FUN_008ca7a0_cls::InitializeVtbl()
{
    vtbl = &DAT_01085884;
    return this;
}

struct GlobalObject_0044fae0
{
};

struct FUN_008caab0 : GlobalObject_0044fae0
{
    int m_40;
    int m_44;
    void* Init();
};

// @fnv 0x008caab0
void* FUN_008caab0::Init()
{
    ::FUN_0044fae0((void *)this);
    *(int*)((char*)this + 0x44) = 0;
    *(int*)((char*)this + 0x40) = 0;
    return this;
}

struct FUN_008cc6d0_class
{
    void FUN_008cc6d0(int value);
};

// @fnv 0x008cc6d0
void FUN_008cc6d0_class::FUN_008cc6d0(int value)
{
    *(int*)((char*)this + 0x8c) = value;
}

struct T_
{
};

struct FUN_008cd6a0_Class
{
    void FUN_008cd6a0(void* a, void* b);
};

// Calls FUN_00cb2d90 on a, then calls FUN_004a3f10 on b through the object at this+0x30.
// @fnv 0x008cd6a0
void FUN_008cd6a0_Class::FUN_008cd6a0(void* apFirst, void* apSecond)
{
    reinterpret_cast<::RotationRows *>(this)->FUN_00cb2d90(apFirst);
    reinterpret_cast<::AlignedVector *>((((T_*)((char*)this + 0x30))))->FUN_004a3f10((*(const ::AlignedVector *)(apSecond)));
}

extern int DAT_011dfc9c;

// @fnv 0x008cddb0
unsigned int __cdecl GetCachedValue()
{
    if (!DAT_011dfc9c)
        DAT_011dfc9c = FUN_005dbe10();
    return DAT_011dfc9c;
}

struct FUN_008ce370_cls
{
    unsigned char GetByteAtOffsetC1();
};

// @fnv 0x008ce370
unsigned char FUN_008ce370_cls::GetByteAtOffsetC1()
{
    return reinterpret_cast<unsigned char*>(this)[0xc1];
}

struct CalleeObj
{
};

struct FUN_008cfff0_Class
{
    int m_iWordAt00;
    int m_cByteAtOffset1;
    int m_cByteAtOffset2;
    CalleeObj* FUN_008cfff0(CalleeObj* arg);
};

// @fnv 0x008cfff0
CalleeObj* FUN_008cfff0_Class::FUN_008cfff0(CalleeObj* arg)
{
    reinterpret_cast<::FUN_00622570_Class *>((arg))->FUN_00622570(m_cByteAtOffset2 != 0);
    return arg;
}

struct FUN_008d01e0_Class
{
    float FUN_008d01e0() const;
};

// @fnv 0x008d01e0
float FUN_008d01e0_Class::FUN_008d01e0() const
{
    return *(const float*)((const char*)this + 0x98);
}

struct FUN_008d0200_Class
{
    char GetByteAtOffsetC3();
};

// @fnv 0x008d0200
char FUN_008d0200_Class::GetByteAtOffsetC3()
{
    return ((char*)this)[0xc3];
}

struct FUN_008d0220_class
{
    void SetByteAtOffsetC3(char arg);
};

// @fnv 0x008d0220
void FUN_008d0220_class::SetByteAtOffsetC3(char acValue)
{
    *(char*)((char*)this + 0xc3) = acValue;
}

struct FUN_008d0240_Class
{
    void FUN_008d0240();
};
// If the pointer at offset 0x88 is set, zeroes the int at offset 0x28 of the object it points to.
// @fnv 0x008d0240
void FUN_008d0240_Class::FUN_008d0240()
{
    if (*(int*)((char*)this + 0x88))
        *(int*)((char*)*(int*)((char*)this + 0x88) + 0x28) = 0;
}

struct FUN_008d1160_Class
{
    void FUN_008d1160();
};

// @fnv 0x008d1160
void FUN_008d1160_Class::FUN_008d1160()
{
    reinterpret_cast<::fnv_00c705c0::FUN_00c705c0 *>((this))->fnv_00c705c0::FUN_00c705c0::~FUN_00c705c0();
}

struct GlobalObject2_0096a2d0
{
};

// @fnv 0x008d15b0
void __cdecl FUN_008d15b0(const void* p)
{
    if (p)
        reinterpret_cast<::ItemChangeListNode *>(&(::g_011dfe14))->FUN_00905330((*(::InventoryStackRecord *const *)(&p)));
}

extern float DAT_011dfed4;
extern float DAT_011dfed8;

// @fnv 0x008d1d10
void __cdecl FUN_008d1d10(float afValue1, float afValue2)
{
    DAT_011dfed4 = afValue1;
    DAT_011dfed8 = afValue2;
}

struct FUN_008d5020_class
{
    void FUN_008d5020();
};

void FUN_008d5020_class::FUN_008d5020()
{}

struct FUN_008d4360_class
{
    FUN_008d4360_class* FUN_008d4360();
};

// @fnv 0x008d4360
FUN_008d4360_class* FUN_008d4360_class::FUN_008d4360()
{
    ((FUN_008d5020_class*)this)->FUN_008d5020();
    return this;
}

extern "C" void __cdecl FreeAndClear();

struct FUN_008d4380_class
{
    void FreeAndClear();
    void FUN_008d4380();
};

struct FUN_008d5590_shell
{
};
struct FUN_008d50e0_shell
{
    FUN_008d5590_shell* m_p;
    void FUN_008d50e0();
};
// @fnv 0x008d50e0
void FUN_008d50e0_shell::FUN_008d50e0()
{
    if (m_p)
        reinterpret_cast<::fnv_008d55b0::FUN_008d55b0_shell *>((m_p))->FUN_008d55b0();
}

struct FUN_008d5660_class
{
    void ForwardToInner(int a);
};
struct ActorValueUtility
{
    static int __cdecl ConvertActorValue(int);
};

struct FUN_008d5720
{
    char bFlag;
    int nValue;
    void Init(int);
};

// @fnv 0x008d5720
void FUN_008d5720::Init(int)
{
    bFlag = 0;
    nValue = ActorValueUtility::ConvertActorValue(2);
}

struct TaskQueueInterface
{
    void SetTaskFlag_008d6f10(bool enabled);
};

// @fnv 0x008d6f10
void TaskQueueInterface::SetTaskFlag_008d6f10(bool enabled)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(enabled, 0x100000);
}

struct FUN_008da180_Class
{
    float GetField2B4();
};

// @fnv 0x008da180
float FUN_008da180_Class::GetField2B4()
{
    return *(float*)((char*)this + 0x2b4);
}

struct FUN_006d2c00_shell
{
    void FUN_006d2c00();
};

struct FUN_008df000_shell
{
    void FUN_008df000();
};

// @fnv 0x008df000
void FUN_008df000_shell::FUN_008df000()
{
    ((FUN_006d2c00_shell*)((char*)this + 0x34))->FUN_006d2c00();
}

struct FUN_008df020_class
{
    unsigned char GetByteAt94();
};

// @fnv 0x008df020
unsigned char FUN_008df020_class::GetByteAt94()
{
    return *(unsigned char*)((char*)this + 0x94);
}

struct FUN_008df1c0_Class
{
    void SetByteAtA1(int a);
};

// @fnv 0x008df1c0
void FUN_008df1c0_Class::SetByteAtA1(int aiValue)
{
    ((unsigned char*)this)[0xa1] = (unsigned char)aiValue;
}

extern int DAT_0108583c;

struct FUN_008ca800_Class
{
    int a;
    int b;
    int c;
    FUN_008ca800_Class* FUN_008ca800();
};

// Sets a to the address of DAT_0108583c and clears b and c, then returns this.
// @fnv 0x008ca800
FUN_008ca800_Class* FUN_008ca800_Class::FUN_008ca800()
{
    a = (int)&DAT_0108583c;
    b = 0;
    c = 0;
    return this;
}

struct FUN_008c1c80_Class
{
    void* FUN_008c1c80(unsigned int flags);
};
struct FUN_008c4f90_Class
{
    void FUN_008c4f90(int arg);
};
// @fnv 0x008c4f90
void FUN_008c4f90_Class::FUN_008c4f90(int arg)
{
    FUN_008c5000_shell* result = (FUN_008c5000_shell*)((FUN_008c5000_shell*)this)->FUN_008c5000(arg);
    if (result)
    {
        reinterpret_cast<::ItemChangeListNode *>((((GlobalObject2_0096a2d0*)((char*)this + 0xf4))))->FUN_00905330((*(::InventoryStackRecord *const *)((const void**)&result)));
        FUN_008c5000_shell* tmp = result;
        ::FUN_00401030(tmp);
    }
}

struct ScriptLocalsX
{
};
struct hkpMouseSpringAction
{
};
struct FUN_008c5df0_Class
{
    void FUN_008c5df0(void* arg);
};
// @fnv 0x008c5df0
void FUN_008c5df0_Class::FUN_008c5df0(void* arg)
{
    void* p = ((void *)(::FUN_004ae750((void *)(((ScriptLocalsX*)this)))));
    if (p)
        reinterpret_cast<::hkpPositionTrackerCBB1 *>((((hkpMouseSpringAction*)p)))->FUN_00cbb150((*(const ::hkVector4CBB1 *)(arg)));
}

struct FUN_008c5e20_Class
{
    int a;
    int b;
    int c;
    int d;
    float e;
    int f;
    void* FUN_008c5e20();
};
// Initialises the object's fields: zeroes a, b, c and f, sets e to -1.0f and d to -1, then returns this.
// @fnv 0x008c5e20
void* FUN_008c5e20_Class::FUN_008c5e20()
{
    a = 0;
    b = 0;
    c = 0;
    e = -1.0f;
    d = -1;
    f = 0;
    return this;
}

struct FUN_008c7790_Class
{
    void* DestroyIfFlagged(unsigned int flags);
};

struct GlobalObject_0078d3b0
{
    ~GlobalObject_0078d3b0();
};
struct FUN_00aa63c0_base
{
    ~FUN_00aa63c0_base();
};
struct FUN_008c77c0_Class : FUN_00aa63c0_base
{
    ~FUN_008c77c0_Class();
    unsigned char m_00[0x30];
    GlobalObject_0078d3b0 m_008c77f0;
    unsigned char m_18[0x0b];
    GlobalObject_0078d3b0 m_008c77e4;
};
// Calls FUN_008c77c0, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x008c7790
void* FUN_008c7790_Class::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_008c77c0_Class *>(this)->FUN_008c77c0_Class::~FUN_008c77c0_Class();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor for the class; the body is empty and the compiler-generated member destructors run implicitly.
// @fnv 0x008c77c0
FUN_008c77c0_Class::~FUN_008c77c0_Class()
{}

extern unsigned char DAT_011dfa19;
struct FUN_008c7990_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void FUN_008c7990();
};
// @fnv 0x008c7990
void FUN_008c7990_Class::FUN_008c7990()
{
    for (unsigned int i = 0; i < 2; ++i)
    {
        if (*(void**)((char*)this + i * 4))
        {
            ::FUN_008c7490((::FUN_008c7490_this *)(*(void**)((char*)this + i * 4)));
        }
    }
    DAT_011dfa19 = 0;
}

struct FUN_008ca7c0_shell
{
    void Reinitialize(int b);
    bool FUN_008ca7c0(int a, int b);
};
struct FUN_008_Struct
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void* FUN_008caa70(FUN_008_Struct* source);
};
// Copies the three pointer members from source into this object and returns this.
// @fnv 0x008caa70
void* FUN_008_Struct::FUN_008caa70(FUN_008_Struct* source)
{
    m_iWordAt00 = source->m_iWordAt00;
    m_iWordAt04 = source->m_iWordAt04;
    m_8 = source->m_8;
    return this;
}

struct BMobile_S
{
    BMobile_S();
    ~BMobile_S();
    char pad[0xc0];
    char unkc0;
    char unkc1;
    char padc2[0x1];
    char unkc3;
    char padc4[0xc];
};
struct B006815c0
{
    B006815c0();
};
class NiNode;
struct TESObjectREFR
{
public:
    void Get3D(::NiNode *, bool);
};
struct HighProcess
{
    HighProcess();
    char pad[0x46c];
};
extern int DAT_01085948;
extern int DAT_01085954;
extern int DAT_011dfc98;
struct FUN_008cab20 : BMobile_S
{
    FUN_008cab20();
};

extern int DAT_01085e2c;
void __cdecl FUN_008c5e20();
struct FUN_008d0270_Class
{
    void* vtbl;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    FUN_008d0270_Class* FUN_008d0270();
};
// Sets the vtable pointer, calls FUN_008c5e20 on the object at offset 4, zeroes m_2c, and returns this.
// @fnv 0x008d0270
FUN_008d0270_Class* FUN_008d0270_Class::FUN_008d0270()
{
    vtbl = &DAT_01085e2c;
    ((void(*)(void*))FUN_008c5e20)((char*)&this->m_iWordAt04);
    m_2c = 0;
    return this;
}

void __cdecl CallWithParam(int);

struct FUN_008d1130_Class : FUN_008d1160_Class
{
    FUN_008d1130_Class* FUN_008d1130(unsigned int flags);
};

// Calls the base constructor, then if bit 0 of flags is set calls CallWithParam on this, and returns this.
// @fnv 0x008d1130
FUN_008d1130_Class* FUN_008d1130_Class::FUN_008d1130(unsigned int flags)
{
    FUN_008d1160();
    if (flags & 1)
        CallWithParam((int)this);
    return this;
}

extern int DAT_010867fc;
struct FUN_008d15d0_Class
{
    void* FUN_008d15d0();
};
// Calls FUN_00a6d220 on this, sets the vtable to DAT_010867fc, zeroes the float at +0x34 and the int at +0x38, and returns this.
// @fnv 0x008d15d0
void* FUN_008d15d0_Class::FUN_008d15d0()
{
    new ((void *)(this)) class ::FUN_00a6d220();
    *(int*)this = (int)&DAT_010867fc;
    *(float*)((char*)this + 0x34) = 0.0f;
    *(int*)((char*)this + 0x38) = 0;
    return this;
}

struct FUN_0087d4a0
{
    FUN_0087d4a0(bool ab);
    ~FUN_0087d4a0();
};
struct SFTX
{
};
extern int DAT_0108695c;
extern int DAT_010869a4;
extern int DAT_010869d4;
extern int DAT_01086a0c;
extern int DAT_01086a60;
extern int DAT_01086a6c;
struct FUN_008d1d30 : FUN_0087d4a0
{
    FUN_008d1d30();
};
// @fnv 0x008d1d30
FUN_008d1d30::FUN_008d1d30() : FUN_0087d4a0(true)
{
    *(int**)this = &DAT_01086a6c;
    *(int**)(this + 0x18) = &DAT_01086a60;
    *(int**)(this + 0x88) = &DAT_01086a0c;
    *(int**)(this + 0x94) = &DAT_010869d4;
    *(int**)(this + 0xa4) = &DAT_010869a4;
    *(int**)(this + 0xa8) = &DAT_0108695c;
    reinterpret_cast<::FUN_004f15a0_shell *>((((SFTX*)this)))->FUN_004f15a0(0x3b);
    *(int*)(this + 0x1b4) = 0;
    reinterpret_cast<::Character *>(this)->FUN_008d4e80();
    *(char*)(this + 0x1c1) = 0;
    *(float*)(this + 0x1c4) = -1.0f;
    *(char*)(this + 0x1c0) = 0;
    *(char*)(this + 0x134) = 0;
    *(int*)(this + 0x138) = 0;
    *(int*)(this + 0x13c) = 0;
    *(int*)(this + 0x140) = 0;
    *(char*)(this + 0x144) = 0;
}

struct BGSSaveFormBuffer
{
};
struct FUN_008d56c0_class
{
    void SaveToBuffer(int a);
};
// @fnv 0x008d5660
void FUN_008d5660_class::ForwardToInner(int aiValue)
{
    reinterpret_cast<::FUN_008d56c0_class *>((((FUN_008d5660_class*)*(void**)this)))->SaveToBuffer(aiValue);
}
// Writes this object's first byte and the 4 bytes at offset 4 into the BGSSaveFormBuffer passed in.
// @fnv 0x008d56c0
void FUN_008d56c0_class::SaveToBuffer(int pBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((((BGSSaveFormBuffer*)pBuffer)))->FUN_00865e50(this, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((((BGSSaveFormBuffer*)pBuffer)))->FUN_00865e50((char*)this + 4, 4, 0);
}

struct BGSLoadFormBuffer
{
};
struct FUN_008d56f0_Class
{
    void FUN_008d56f0(BGSLoadFormBuffer* buffer);
};
// Reads 1 byte into this and 4 bytes at offset 4 from the load buffer.
// @fnv 0x008d56f0
void FUN_008d56f0_Class::FUN_008d56f0(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(this), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 4), 4);
}

struct FUN_008d6000_Class
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    void InitTiming(unsigned int a, unsigned int b);
};
// @fnv 0x008d6000
void FUN_008d6000_Class::InitTiming(unsigned int a, unsigned int b)
{
    m_iWordAt04 = b;
    m_iWordAt00 = a;
    m_8 = ((unsigned int)(::FUN_00457fe0())) + ((unsigned int)(::s8d5830::FUN_008d5830(b)));
    m_iThirdValue = ((unsigned int)(::FUN_00457fe0())) + 0x708;
}

struct NiNode
{
    int x;
};
struct NiFrustum
{
    int x;
};
struct NiCamera
{
    const NiFrustum& GetViewFrustum() const;
};
struct MagicCaster
{
    void SetSelectedMagicItem(int);
};
struct S694a0
{
    void FUN_00a694a0(void*);
};
struct FUN_008d6bb0_shell
{
};
struct ProcessLists
{
};

struct FUN_008d6f50_Class
{
    void FUN_008d6f50(int arg);
};


struct FUN_008df980_Class
{
    void FUN_008df9b0();
    void* FUN_008df980(unsigned int flags);
};

struct NiFixedStr
{
    operator const char*();
};
struct SeqObj
{
};
struct ModelLoader
{
};
struct Loader_S
{
    ModelLoader* m_p;
};
// @fnv 0x008d68d0
void __cdecl FUN_008d68d0()
{
    for (int i = 0; i < 12; ++i)
    {
        if (DAT_011e0110[i])
        {
            reinterpret_cast<::FUN_0045a5e0_shell *>(((*reinterpret_cast<::Loader_S *>(&::g_modelLoader)).m_p))->FUN_0045a5e0((char *)((*(::NiFixedStr *)(reinterpret_cast<::TESTopicInfoData *>((((SeqObj**)DAT_011e0110)[i]))->GetLinkToList()))));
            DAT_011e0110[i] = 0;
        }
        if (DAT_011e00e0[i])
        {
            void* p = (void*)DAT_011e00e0[i];
            ::FUN_00401030(p);
            DAT_011e00e0[i] = 0;
        }
    }
}

struct NiTimeController
{
};
struct Model
{
    NiTimeController* GetObject3D();
};
struct GlobalObject_00a7b610
{
};
struct FUN_00571550_shell
{
};
struct FUN_008da1a0_Class
{
    void FUN_008da1a0(FUN_00571550_shell* actor);
};
// Clears the field at offset 0x2e4, then scans the actor's model controllers and stores the first one accepted by g_012031b8.
// @fnv 0x008da1a0
void FUN_008da1a0_Class::FUN_008da1a0(FUN_00571550_shell* actor)
{
    *(int*)((char*)this + 0x2e4) = 0;
    int id = ((int)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((actor))->FUN_0043fcd0()));
    if (!id)
        return;
    Model* model = ((::Model *)(reinterpret_cast<::fnv_00571530::FUN_00571530_shell *>((actor))->FUN_00571530((::fnv_00571530::NiAVObject *)(id), (::fnv_00571530::NiFixedString *)(((int)(::FUN_00571550()))))));
    if (!model)
        return;
    NiTimeController* controller = model->GetObject3D();
    while (controller)
    {
        if (::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)&(::g_012031b8), (const ::fnv_0045bad0::NiObject *)(controller)))
        {
            *(int*)((char*)this + 0x2e4) = (int)controller;
            return;
        }
        controller = ((::NiTimeController *)(::fnv_004a8a90::FUN_004a8a90((char *)(controller))));
    }
}

struct FUN_0052d240_obj
{
    ~FUN_0052d240_obj();
};
struct FUN_008c7860_Class : FUN_008c77c0_Class
{
    unsigned char m_00[0x13];
    FUN_0052d240_obj m_008c78b0;
    ~FUN_008c7860_Class();
};
// @fnv 0x008c7860
FUN_008c7860_Class::~FUN_008c7860_Class()
{}

struct Call741e0
{
};
extern int DAT_01086658;
extern int DAT_01086674;
extern int DAT_01086684;
struct FUN_008d10e0_Class : Call741e0
{
    void* FUN_008d10e0(int a, int b);
};
// @fnv 0x008d10e0
void* FUN_008d10e0_Class::FUN_008d10e0(int aiArg, int aiValue)
{
    new ((void *)this) ::fnv_00c741e0::FUN_00c741e0((::fnv_00c741e0::T741_Src *)(aiArg));
    *reinterpret_cast<int**>(this) = &DAT_01086684;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x3e0) = &DAT_01086674;
    *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 0x410) = &DAT_01086658;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x650) = aiValue;
    return this;
}

struct TESTopicInfo
{
};
struct BGSAcousticSpace
{
};
struct BSFaceGenMorphData
{
    float FUN_00508120();
};
struct FUN_00929240_Class
{
    void FUN_00929240(float);
};
struct CloneableObj
{
};
struct FUN_008d17d0_Class
{
    void FUN_008d17d0(BGSAcousticSpace* dst, void* arg);
};
// @fnv 0x008d17d0
void FUN_008d17d0_Class::FUN_008d17d0(BGSAcousticSpace* dst, void* arg)
{
    reinterpret_cast<::FUN_0040e500_shell *>((dst))->SetValue((int)(((::TESSound *)(::GetField38((char *)(reinterpret_cast<TESTopicInfo*>(this)))))));
    reinterpret_cast<FUN_00929240_Class*>(dst)->FUN_00929240(
        reinterpret_cast<BSFaceGenMorphData*>(this)->FUN_00508120());
    reinterpret_cast<::NiTimeControllerCM *>((reinterpret_cast<CloneableObj*>(this)))->FUN_00a6cfe0((::NiTimeController *)(::CloneableObj *)(reinterpret_cast<CloneableObj*>(dst)), (*(::CloningProcess *)(arg)));
}

struct FUN_0087adf0_shell
{
    int InitScriptRunLockForSelf();
};
struct FUN_008c1c30_Class
{
    FUN_0087adf0_shell* m_iWordAt00;
    FUN_008c1c30_Class* FUN_008c1c30(FUN_0087adf0_shell* a);
};
// @fnv 0x008c1c30
FUN_008c1c30_Class* FUN_008c1c30_Class::FUN_008c1c30(FUN_0087adf0_shell* pObject)
{
    m_iWordAt00 = pObject;
    if (m_iWordAt00)
        m_iWordAt00->InitScriptRunLockForSelf();
    return this;
}

struct BSSimpleArrayActor
{
    void Clear(bool);
};
struct FUN_008c1cb0_Class
{
    void* m_iWordAt00;
    void FUN_008c1cb0();
};
// Calls FUN_008c1cb0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x008c1c80
void* FUN_008c1c80_Class::FUN_008c1c80(unsigned int flags)
{
    reinterpret_cast<::FUN_008c1cb0_Class *>(this)->FUN_008c1cb0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x008c1cb0
void FUN_008c1cb0_Class::FUN_008c1cb0()
{
    m_iWordAt00 = &DAT_01084fec;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((BSSimpleArrayActor*)this)))->Clear(true);
}

struct FUN_008c45a0_Result
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
    virtual void v64();
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
    virtual void FUN_008c45a0(unsigned char arg);
};

struct TES
{
    void FUN_008c45a0(unsigned char arg);
};

// If GetLogDate() returns non-null, forwards arg to the virtual FUN_008c45a0 method on that object.
// @fnv 0x008c45a0
void TES::FUN_008c45a0(unsigned char aucValue)
{
    if (((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))
    {
        reinterpret_cast<FUN_008c45a0_Result*>(((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))->FUN_008c45a0(aucValue);
    }
}

struct CountingSemaphore
{
    CountingSemaphore(int, int);
};

struct FUN_008c7250_Class
{
    FUN_008c7250_Class* FUN_008c7250();
};

// @fnv 0x008c7250
FUN_008c7250_Class* FUN_008c7250_Class::FUN_008c7250()
{
    ((CountingSemaphore*)this)->CountingSemaphore::CountingSemaphore(0, 0x14);
    return this;
}

struct FUN_008c7270 : GlobalObject_0078d3b0
{
    ~FUN_008c7270();
};
// @fnv 0x008c7270
FUN_008c7270::~FUN_008c7270()
{}

struct FUN_008c7270_Class
{
    void FUN_008c7270();
};
struct FUN_008c8110_Class
{
    void FUN_008c8110();
    unsigned char m_00[0x18];
    FUN_008c7270_Class m_18;
};
void __cdecl FUN_008c7270_Cb(void);
// Calls FUN_0065ee50_Helper on m_18 with size 0xc, count 3 and callback FUN_008c7270_Cb.
// @fnv 0x008c8110
void FUN_008c8110_Class::FUN_008c8110()
{
    fnv::crt::vector_destructor(&m_18, 0xc, 3, (void (*)(void *))(FUN_008c7270_Cb));
}

struct Date
{
    ~Date();
};
struct FUN_008ca770_Class
{
    void FUN_008ca770(Date**);
};
int __cdecl FUN_0043b460(long volatile*, long, long);

struct Interface
{
};

struct FUN_008ca8d0_Class
{
    int m_iWordAt00;
    long volatile m_iWordAt04;
    int m_8;
    void FUN_008ca8d0(int* arg);
};

// @fnv 0x008ca8d0
void FUN_008ca8d0_Class::FUN_008ca8d0(int* arg)
{
    while (true)
    {
        if (FUN_0043b460(&m_iWordAt04, 0, 1) == 0)
        {
            ::FUN_0040fbe0();
            *reinterpret_cast<int*>(*arg + 0xc) = m_8;
            m_8 = *arg;
            *arg = 0;
            ::FUN_0040fbe0();
            FUN_0043b460(&m_iWordAt04, 1, 0);
            break;
        }
    }
}

struct FUN_008caae0_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    void* FUN_008caae0();
};

// @fnv 0x008caae0
void* FUN_008caae0_Class::FUN_008caae0()
{
    m_iThirdValue = 0;
    return this;
}

struct FUN_008cc6f0_Class
{
    void* FUN_008cc6f0();
};

struct GO
{
    operator unsigned int() const;
};

struct FUN_008d3f40_Class
{
    void GetEntryAt(int arg);
};

struct FUN_008d3f10_Class
{
    unsigned char pad[0x38];
    GO m_38;

    void FUN_008d3f10(int arg);
};

// Calls GetEntryAt on the object obtained by converting m_38 to an unsigned int, passing arg through.
// @fnv 0x008d3f10
void FUN_008d3f10_Class::FUN_008d3f10(int arg)
{
    reinterpret_cast<FUN_008d3f40_Class*>(m_38.operator unsigned int())->GetEntryAt(arg);
}

namespace fnv_008d3f40 {
struct FUN_008d3f40_Class
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    unsigned int m_8;
    void* m_iThirdValue;
    void* m_10;
    void* GetEntryAt(unsigned int index);
};

// Returns a pointer to the entry at the given index within m_10 if index is below m_8, otherwise returns null.
// @fnv 0x008d3f40
void* FUN_008d3f40_Class::GetEntryAt(unsigned int index)
{
    if (index < m_8)
    {
        return (char*)m_10 + (index << 4);
    }
    else
    {
        return 0;
    }
}
}  // namespace fnv_008d3f40

struct FUN_008d50a0_Class
{
    void* m_p;
    void FreeAndClear();
};
// @fnv 0x008d4380
void FUN_008d4380_class::FUN_008d4380()
{
    reinterpret_cast<::FUN_008d50a0_Class *>(this)->FreeAndClear();
}

// If m_p is set, deallocates it and resets m_p to null.
// @fnv 0x008d50a0
void FUN_008d50a0_Class::FreeAndClear()
{
    if (m_p)
    {
        void* p = m_p;
        ::FUN_00401030(p);
        m_p = 0;
    }
}

struct FUN_008d5680_Class
{
    FUN_008d56f0_Class* m_p;
    void FUN_008d5680(BGSLoadFormBuffer* arg);
};
// @fnv 0x008d5680
void FUN_008d5680_Class::FUN_008d5680(BGSLoadFormBuffer* apBuffer)
{
    m_p->FUN_008d56f0(apBuffer);
}

struct FUN_008d56a0_Class
{
    void FUN_008d56a0(int value);
};
// @fnv 0x008d56a0
void FUN_008d56a0_Class::FUN_008d56a0(int value)
{
    ((FUN_008d5720*)*(void**)this)->Init(value);
}

class BaseProcess8C4
{
  public:
    virtual void unkv000();
    virtual void unkv004();
    virtual void unkv008();
    virtual void unkv00C();
    virtual void unkv010();
    virtual void unkv014();
    virtual void unkv018();
    virtual void unkv01C();
    virtual void unkv020();
    virtual void unkv024();
    virtual void unkv028();
    virtual void unkv02C();
    virtual void unkv030();
    virtual void unkv034();
    virtual void unkv038();
    virtual void unkv03C();
    virtual void unkv040();
    virtual void unkv044();
    virtual void unkv048();
    virtual void unkv04C();
    virtual void unkv050();
    virtual void unkv054();
    virtual void unkv058();
    virtual void unkv05C();
    virtual void unkv060();
    virtual void unkv064();
    virtual void unkv068();
    virtual void unkv06C();
    virtual void unkv070();
    virtual void unkv074();
    virtual void unkv078();
    virtual void unkv07C();
    virtual void unkv080();
    virtual void unkv084();
    virtual void unkv088();
    virtual void unkv08C();
    virtual void unkv090();
    virtual void unkv094();
    virtual void unkv098();
    virtual void unkv09C();
    virtual void unkv0A0();
    virtual void unkv0A4();
    virtual void unkv0A8();
    virtual void unkv0AC();
    virtual void unkv0B0();
    virtual void unkv0B4();
    virtual void unkv0B8();
    virtual void unkv0BC();
    virtual void unkv0C0();
    virtual void unkv0C4();
    virtual void unkv0C8();
    virtual void unkv0CC();
    virtual void unkv0D0();
    virtual void unkv0D4();
    virtual void unkv0D8();
    virtual void unkv0DC();
    virtual void unkv0E0();
    virtual void unkv0E4();
    virtual void unkv0E8();
    virtual void unkv0EC();
    virtual void unkv0F0();
    virtual void unkv0F4();
    virtual void unkv0F8();
    virtual void unkv0FC();
    virtual void unkv100();
    virtual void unkv104();
    virtual void unkv108();
    virtual void unkv10C();
    virtual void unkv110();
    virtual void unkv114();
    virtual void unkv118();
    virtual void unkv11C();
    virtual void unkv120();
    virtual void unkv124();
    virtual void unkv128();
    virtual void unkv12C();
    virtual void unkv130();
    virtual void unkv134();
    virtual void unkv138();
    virtual void unkv13C();
    virtual void unkv140();
    virtual void unkv144();
    virtual void unkv148();
    virtual void unkv14C();
    virtual void unkv150();
    virtual void unkv154();
    virtual void unkv158();
    virtual void unkv15C();
    virtual void unkv160();
    virtual void unkv164();
    virtual void unkv168();
    virtual void unkv16C();
    virtual void unkv170();
    virtual void unkv174();
    virtual void unkv178();
    virtual void unkv17C();
    virtual void unkv180();
    virtual void unkv184();
    virtual void unkv188();
    virtual void unkv18C();
    virtual void unkv190();
    virtual void unkv194();
    virtual void unkv198();
    virtual void unkv19C();
    virtual void unkv1A0();
    virtual void unkv1A4();
    virtual void unkv1A8();
    virtual void unkv1AC();
    virtual void unkv1B0();
    virtual void unkv1B4();
    virtual void unkv1B8();
    virtual void unkv1BC();
    virtual void unkv1C0();
    virtual void unkv1C4();
    virtual void unkv1C8();
    virtual void unkv1CC();
    virtual void unkv1D0();
    virtual void unkv1D4();
    virtual void unkv1D8();
    virtual void unkv1DC();
    virtual void unkv1E0();
    virtual void unkv1E4();
    virtual void unkv1E8();
    virtual void unkv1EC();
    virtual void unkv1F0();
    virtual void unkv1F4();
    virtual void unkv1F8();
    virtual void unkv1FC();
    virtual void unkv200();
    virtual void unkv204();
    virtual void unkv208();
    virtual void unkv20C();
    virtual void unkv210();
    virtual void unkv214();
    virtual void unkv218();
    virtual void unkv21C();
    virtual void unkv220();
    virtual void unkv224();
    virtual void unkv228();
    virtual void unkv22C();
    virtual void unkv230();
    virtual void unkv234();
    virtual void unkv238();
    virtual void unkv23C();
    virtual void unkv240();
    virtual void unkv244();
    virtual void unkv248();
    virtual void unkv24C();
    virtual void unkv250();
    virtual void unkv254();
    virtual void unkv258();
    virtual void unkv25C();
    virtual void unkv260();
    virtual void unkv264();
    virtual void unkv268();
    virtual void unkv26C();
    virtual void unkv270();
    virtual void unkv274();
    virtual void unkv278();
    virtual void unkv27C();
    virtual void unkv280();
    virtual void unkv284();
    virtual void unkv288();
    virtual void unkv28C();
    virtual void unkv290();
    virtual void unkv294();
    virtual void unkv298();
    virtual void unkv29C();
    virtual void unkv2A0();
    virtual void unkv2A4();
    virtual void unkv2A8();
    virtual void unkv2AC();
    virtual void unkv2B0();
    virtual void unkv2B4();
    virtual void unkv2B8();
    virtual void unkv2BC();
    virtual void unkv2C0();
    virtual void unkv2C4();
    virtual void unkv2C8();
    virtual void unkv2CC();
    virtual void unkv2D0();
    virtual void unkv2D4();
    virtual void unkv2D8();
    virtual void unkv2DC();
    virtual void unkv2E0();
    virtual void unkv2E4();
    virtual void unkv2E8();
    virtual void unkv2EC();
    virtual void unkv2F0();
    virtual void unkv2F4();
    virtual void unkv2F8();
    virtual void unkv2FC();
    virtual void unkv300();
    virtual void unkv304();
    virtual void unkv308();
    virtual void unkv30C();
    virtual void unkv310();
    virtual void unkv314();
    virtual void unkv318();
    virtual void unkv31C();
    virtual void unkv320();
    virtual void unkv324();
    virtual void unkv328();
    virtual void unkv32C();
    virtual void unkv330();
    virtual void unkv334();
    virtual void unkv338();
    virtual void unkv33C();
    virtual void unkv340();
    virtual void unkv344();
    virtual void unkv348();
    virtual void unkv34C();
    virtual void unkv350();
    virtual void unkv354();
    virtual void unkv358();
    virtual void unkv35C();
    virtual void unkv360();
    virtual void unkv364();
    virtual void unkv368();
    virtual void unkv36C();
    virtual void unkv370();
    virtual void unkv374();
    virtual void unkv378();
    virtual void unkv37C();
    virtual void unkv380();
    virtual void unkv384();
    virtual void unkv388();
    virtual void unkv38C();
    virtual void unkv390();
    virtual void unkv394();
    virtual void unkv398();
    virtual void unkv39C();
    virtual void unkv3A0();
    virtual void unkv3A4();
    virtual void unkv3A8();
    virtual void unkv3AC();
    virtual void unkv3B0();
    virtual void unkv3B4();
    virtual void unkv3B8();
    virtual void unkv3BC();
    virtual void unkv3C0();
    virtual void unkv3C4();
    virtual void unkv3C8();
    virtual void unkv3CC();
    virtual void unkv3D0();
    virtual void SetValue(int iValue);
};

class TESObjectREFR8C4
{
  public:
    virtual ~TESObjectREFR8C4();

    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    int unk84;
};

class ActorValueOwner8C4
{
  public:
    virtual void unkv00();
    virtual void FUN_008c4510(int iValue);
};

class Actor8C4 : public TESObjectREFR8C4, public ActorValueOwner8C4
{
  public:
    virtual void FUN_008c4510(int iValue);
};

// Forwards iValue to the actor's process via SetValue when GetProcess() returns a process.
// @fnv 0x008c4510
void Actor8C4::FUN_008c4510(int iValue)
{
    if (((::BaseProcess8C4 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))
        ((::BaseProcess8C4 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->SetValue(iValue);
}


// @fnv 0x008c4f00
int __cdecl FUN_008c4f00()
{
    return DAT_011c3580;
}

struct S_8c4f10_Item
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
    virtual void v14(int a);
};
struct S_8c4f10_Node
{
    int FUN_005ae380();
};
struct S_8c4f10_List
{
    virtual void v00();
    virtual void v01();
    virtual S_8c4f10_Node* v02();
};
struct S_8c4f10_Cls
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
    S_8c4f10_List list;
    void FUN_008c4f10(int a);
};

struct SpawnedElemB
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
};


void SpawnedElemB_Ctor(void* p)
{}

void SpawnedElemB_Dtor(void* p)
{}

struct FUN_008c71d0_cls
{
    unsigned int m_00[3];
    unsigned int m_0c[3];
    SpawnedElemB m_18[3];
    unsigned int m_3c[12];
    unsigned int m_6c[8];
    unsigned int* m_8c;
    unsigned int* m_90;
    FUN_008c71d0_cls* FUN_008c71d0();
};

// Constructs the three m_18 elements, zeroes m_00 and m_0c, points m_8c at m_3c and m_90 at m_6c, and returns this.
// @fnv 0x008c71d0
FUN_008c71d0_cls* FUN_008c71d0_cls::FUN_008c71d0()
{
    fnv::crt::vector_constructor(m_18, 12, 3, SpawnedElemB_Ctor, SpawnedElemB_Dtor);
    for (int i = 0; i < 3; i++)
    {
        m_00[i] = 0;
        m_0c[i] = 0;
    }
    m_8c = m_3c;
    m_90 = m_6c;
    return this;
}

// Stand-in for the game's class (the pack's own unit file does not declare it):
//   +0x00  two element pointers          +0x0c  two ints
//   +0x3c  twelve ints                   +0x6c  eight ints
struct FNV_008c9fb0_Element
{
};

struct FUN_008c78c0_Class
{
    FNV_008c9fb0_Element* unk00[2];
    int unk08;
    int unk0c[2];
    int unk14[10];
    int unk3c[12];
    int unk6c[8];
    void FUN_008c78c0();
};

// Callback slot in the game's global handler table: one int argument, and the
// callee pops it (stdcall), so the call site has no stack cleanup.
extern void(* g_FNV_008c78c0_hook)(int);

// Calls the hook on each entry of unk3c and unk6c, clears unk0c, sets DAT_011dfa19 to 1, then invokes SignalAtOffset30 on each non-null unk00 element.
// @fnv 0x008c78c0
void FUN_008c78c0_Class::FUN_008c78c0()
{
    // twelve handler slots
    for (int i = 0; i <= 11; i++)
    {
        g_FNV_008c78c0_hook(unk3c[i]);
    }
    // eight handler slots
    for (int i = 0; i <= 7; i++)
    {
        g_FNV_008c78c0_hook(unk6c[i]);
    }
    // clear the two pending entries
    for (unsigned int i = 0; i < 2; i++)
    {
        unk0c[i] = 0;
    }
    DAT_011dfa19 = 1;
    // dispose both elements
    for (unsigned int i = 0; i < 2; i++)
    {
        if (unk00[i] != 0)
        {
            reinterpret_cast<::FUN_008c9fb0_shell *>((unk00[i]))->SignalAtOffset30();
        }
    }
}

int __cdecl FUN_0043b460(long volatile*, long, long);

struct FreeNode16
{
    int unk00;
    int unk04;
    int unk08;
    FreeNode16* next;
};

struct FUN_008ca830_cls
{
    int unk00;
    long unk04;
    FreeNode16* m_08;
    FreeNode16* m_0c;
    void InitFreeList(unsigned int count, FreeNode16* base);
};

// Links count FreeNode16 entries starting at base into a singly linked list, guarding the update with FUN_0043b460 and FUN_0040fbe0.
// @fnv 0x008ca830
void FUN_008ca830_cls::InitFreeList(unsigned int count, FreeNode16* base)
{
    m_08 = base;
    while (1)
    {
        if (FUN_0043b460(&unk04, 0, 1) == 0)
        {
            FUN_0040fbe0();
            unsigned int i;
            FreeNode16* cur;
            for (i = 0, cur = base; i < count - 1; i++, cur++)
            {
                cur->next = cur + 1;
            }
            cur->next = 0;
            FUN_0040fbe0();
            FUN_0043b460(&unk04, 1, 0);
            break;
        }
    }
}

struct FUN_008ca940_node
{
    int m_00;
    int m_04;
    int m_08;
    FUN_008ca940_node* m_0c;
};


class FUN_008ca940_cls
{
  public:
    int m_00;
    long m_04;
    FUN_008ca940_node* m_08;

    bool PopNode(FUN_008ca940_node** out);
};
// @fnv 0x008ca7c0
bool FUN_008ca7c0_shell::FUN_008ca7c0(int a, int b)
{
    if (reinterpret_cast<::FUN_008ca940_cls *>(this)->PopNode((::FUN_008ca940_node **)(a)))
    {
        ((FUN_008ca7c0_shell**)(void*)a)[0]->Reinitialize(b);
        return true;
    }
    else
        return false;
}

// @fnv 0x008ca940
bool FUN_008ca940_cls::PopNode(FUN_008ca940_node** apNode)
{
    bool result;

    while (1)
    {
        if (FUN_0043b460((long volatile*)&m_04, 0, 1) == 0)
        {
            FUN_0040fbe0();
            if (m_08 != 0)
            {
                *apNode = m_08;
                m_08 = (*apNode)->m_0c;
                (*apNode)->m_0c = 0;
                result = true;
            }
            else
            {
                result = false;
                *apNode = 0;
            }
            FUN_0040fbe0();
            FUN_0043b460((long volatile*)&m_04, 1, 0);
            break;
        }
    }
    return result;
}

class FUN_008cab00_cls
{
  public:
    void FUN_008cab00();
};

// @fnv 0x008cab00
void FUN_008cab00_cls::FUN_008cab00()
{
    reinterpret_cast<::FUN_0044fb00_Shim *>((this))->FUN_0044fb00();
}

extern int DAT_01085c90;
struct Renderer
{
};
struct GameContext
{
};
struct Player;
struct Callback
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual void v116() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void v168() = 0;
    virtual void v169() = 0;
    virtual void v170() = 0;
    virtual void v171() = 0;
    virtual void v172() = 0;
    virtual void v173() = 0;
    virtual void v174() = 0;
    virtual void v175() = 0;
    virtual void v176() = 0;
    virtual void v177() = 0;
    virtual void v178() = 0;
    virtual void v179() = 0;
    virtual void v180() = 0;
    virtual void v181() = 0;
    virtual void v182() = 0;
    virtual void v183() = 0;
    virtual void v184() = 0;
    virtual void v185() = 0;
    virtual void v186() = 0;
    virtual void v187() = 0;
    virtual void v188() = 0;
    virtual void v189() = 0;
    virtual void v190() = 0;
    virtual void v191() = 0;
    virtual void v192() = 0;
    virtual void v193() = 0;
    virtual void v194() = 0;
    virtual void v195() = 0;
    virtual void v196() = 0;
    virtual void v197() = 0;
    virtual void v198() = 0;
    virtual void v199() = 0;
    virtual void v200() = 0;
    virtual void v201() = 0;
    virtual void v202() = 0;
    virtual void v203() = 0;
    virtual void v204() = 0;
    virtual void v205() = 0;
    virtual void v206() = 0;
    virtual void v207() = 0;
    virtual void v208() = 0;
    virtual void v209() = 0;
    virtual void v210() = 0;
    virtual void v211() = 0;
    virtual void v212() = 0;
    virtual void v213() = 0;
    virtual void v214() = 0;
    virtual void v215() = 0;
    virtual void v216() = 0;
    virtual void v217() = 0;
    virtual void v218() = 0;
    virtual void v219() = 0;
    virtual void v220() = 0;
    virtual void v221() = 0;
    virtual void v222() = 0;
    virtual void v223() = 0;
    virtual void v224() = 0;
    virtual void v225() = 0;
    virtual void v226() = 0;
    virtual void v227() = 0;
    virtual void v228() = 0;
    virtual void v229() = 0;
    virtual void v230() = 0;
    virtual void v231() = 0;
    virtual void v232() = 0;
    virtual void v233() = 0;
    virtual void v234() = 0;
    virtual void v235() = 0;
    virtual void v236() = 0;
    virtual void v237() = 0;
    virtual void v238() = 0;
    virtual void v239() = 0;
    virtual void v240() = 0;
    virtual void v241() = 0;
    virtual void v242() = 0;
    virtual void v243() = 0;
    virtual void v244() = 0;
    virtual void v245() = 0;
    virtual void v246() = 0;
    virtual void v247() = 0;
    virtual void v248() = 0;
    virtual void v249() = 0;
    virtual void v250() = 0;
    virtual void v251() = 0;
    virtual void v252() = 0;
    virtual void v253() = 0;
    virtual void v254() = 0;
    virtual void v255() = 0;
    virtual void v256() = 0;
    virtual void v257() = 0;
    virtual void v258() = 0;
    virtual void v259() = 0;
    virtual void v260() = 0;
    virtual void v261() = 0;
    virtual void v262() = 0;
    virtual void v263() = 0;
    virtual void v264() = 0;
    virtual void v265() = 0;
    virtual void v266() = 0;
    virtual void v267() = 0;
    virtual void v268() = 0;
    virtual void v269() = 0;
    virtual void v270() = 0;
    virtual void v271() = 0;
    virtual void v272() = 0;
    virtual void v273() = 0;
    virtual void v274() = 0;
    virtual void v275() = 0;
    virtual void v276() = 0;
    virtual void v277() = 0;
    virtual void v278() = 0;
    virtual void v279() = 0;
    virtual void v280() = 0;
    virtual void v281() = 0;
    virtual void v282() = 0;
    virtual void v283() = 0;
    virtual void v284() = 0;
    virtual void v285() = 0;
    virtual void v286() = 0;
    virtual void v287() = 0;
    virtual void v288() = 0;
    virtual void v289() = 0;
    virtual void v290() = 0;
    virtual void v291() = 0;
    virtual void v292() = 0;
    virtual void v293() = 0;
    virtual void v294() = 0;
    virtual void v295() = 0;
    virtual void v296() = 0;
    virtual void v297() = 0;
    virtual void v298() = 0;
    virtual void v299() = 0;
    virtual void v300() = 0;
    virtual void v301() = 0;
    virtual void v302() = 0;
    virtual void v303() = 0;
    virtual void v304() = 0;
    virtual void v305() = 0;
    virtual void v306() = 0;
    virtual void v307() = 0;
    virtual void v308() = 0;
    virtual void v309() = 0;
    virtual void v310() = 0;
    virtual void v311() = 0;
    virtual void v312() = 0;
    virtual void v313() = 0;
    virtual void v314() = 0;
    virtual void v315() = 0;
    virtual void v316() = 0;
    virtual void v317() = 0;
    virtual void v318() = 0;
    virtual void v319() = 0;
    virtual void v320() = 0;
    virtual void v321() = 0;
    virtual void v322() = 0;
    virtual void v323() = 0;
    virtual void v324() = 0;
    virtual void v325() = 0;
    virtual void v326() = 0;
    virtual void v327() = 0;
    virtual void v328() = 0;
    virtual void v329() = 0;
    virtual void v330() = 0;
    virtual void v331() = 0;
    virtual void v332() = 0;
    virtual void v333() = 0;
    virtual void v334() = 0;
    virtual void v335() = 0;
    virtual void v336() = 0;
    virtual void v337() = 0;
    virtual void v338() = 0;
    virtual void v339() = 0;
    virtual void v340() = 0;
    virtual void v341() = 0;
    virtual void v342() = 0;
    virtual void v343() = 0;
    virtual void v344() = 0;
    virtual void v345() = 0;
    virtual void v346() = 0;
    virtual void v347() = 0;
    virtual void v348() = 0;
    virtual void v349() = 0;
    virtual void v350() = 0;
    virtual void v351() = 0;
    virtual void v352() = 0;
    virtual void v353() = 0;
    virtual void v354() = 0;
    virtual void v355() = 0;
    virtual void v356() = 0;
    virtual void v357() = 0;
    virtual void v358() = 0;
    virtual void v359() = 0;
    virtual void v360() = 0;
    virtual void v361() = 0;
    virtual void v362() = 0;
    virtual void v363() = 0;
    virtual void v364() = 0;
    virtual void v365() = 0;
    virtual void v366() = 0;
    virtual void v367() = 0;
    virtual void v368() = 0;
    virtual void v369() = 0;
    virtual void v370() = 0;
    virtual void v371() = 0;
    virtual void v372() = 0;
    virtual void v373() = 0;
    virtual void v374() = 0;
    virtual void v375() = 0;
    virtual void v376() = 0;
    virtual void v377() = 0;
    virtual void v378() = 0;
    virtual void v379() = 0;
    virtual void v380() = 0;
    virtual void v381() = 0;
    virtual void v382() = 0;
    virtual void v383() = 0;
    virtual void v384() = 0;
    virtual void v385() = 0;
    virtual void v386() = 0;
    virtual void v387() = 0;
    virtual void v388() = 0;
    virtual void v389() = 0;
    virtual void v390() = 0;
    virtual void v391() = 0;
    virtual void v392() = 0;
    virtual void v393() = 0;
    virtual void v394() = 0;
    virtual void v395() = 0;
    virtual void v396() = 0;
    virtual void v397() = 0;
    virtual void v398() = 0;
    virtual void v399() = 0;
    virtual void v400() = 0;
    virtual void v401() = 0;
    virtual void v402() = 0;
    virtual void v403() = 0;
    virtual void v404() = 0;
    virtual void v405() = 0;
    virtual void v406() = 0;
    virtual void v407() = 0;
    virtual void v408() = 0;
    virtual void v409() = 0;
    virtual void v410() = 0;
    virtual void v411() = 0;
    virtual void v412() = 0;
    virtual void v413() = 0;
    virtual void v414() = 0;
    virtual void v415() = 0;
    virtual void v416() = 0;
    virtual void v417() = 0;
    virtual void v418() = 0;
    virtual void v419() = 0;
    virtual void v420() = 0;
    virtual void v421() = 0;
    virtual void v422() = 0;
    virtual void v423() = 0;
    virtual void v424() = 0;
    virtual void execute(Player*) = 0;
};
struct ActiveItem
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual unsigned char isReady() = 0;
};
struct Action
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void apply(Renderer*, int) = 0;
};
struct State
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    ActiveItem* active;
    Action* action;
    unsigned int configuration30;
};
struct Player
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void v30() = 0;
    virtual void v31() = 0;
    virtual void v32() = 0;
    virtual void v33() = 0;
    virtual void v34() = 0;
    virtual void v35() = 0;
    virtual void v36() = 0;
    virtual void v37() = 0;
    virtual void v38() = 0;
    virtual void v39() = 0;
    virtual void v40() = 0;
    virtual void v41() = 0;
    virtual void v42() = 0;
    virtual void v43() = 0;
    virtual void v44() = 0;
    virtual void v45() = 0;
    virtual void v46() = 0;
    virtual void v47() = 0;
    virtual void v48() = 0;
    virtual void v49() = 0;
    virtual void v50() = 0;
    virtual void v51() = 0;
    virtual void v52() = 0;
    virtual void v53() = 0;
    virtual void v54() = 0;
    virtual void v55() = 0;
    virtual void v56() = 0;
    virtual void v57() = 0;
    virtual void v58() = 0;
    virtual void v59() = 0;
    virtual void v60() = 0;
    virtual void v61() = 0;
    virtual void v62() = 0;
    virtual void v63() = 0;
    virtual void v64() = 0;
    virtual void v65() = 0;
    virtual void v66() = 0;
    virtual void v67() = 0;
    virtual void v68() = 0;
    virtual void v69() = 0;
    virtual void v70() = 0;
    virtual void v71() = 0;
    virtual void v72() = 0;
    virtual void v73() = 0;
    virtual void v74() = 0;
    virtual void v75() = 0;
    virtual void v76() = 0;
    virtual void v77() = 0;
    virtual void v78() = 0;
    virtual void v79() = 0;
    virtual void v80() = 0;
    virtual void v81() = 0;
    virtual void v82() = 0;
    virtual void v83() = 0;
    virtual void v84() = 0;
    virtual void v85() = 0;
    virtual void v86() = 0;
    virtual void v87() = 0;
    virtual void v88() = 0;
    virtual void v89() = 0;
    virtual void v90() = 0;
    virtual void v91() = 0;
    virtual void v92() = 0;
    virtual void v93() = 0;
    virtual void v94() = 0;
    virtual void v95() = 0;
    virtual void v96() = 0;
    virtual void v97() = 0;
    virtual void v98() = 0;
    virtual void v99() = 0;
    virtual void v100() = 0;
    virtual void v101() = 0;
    virtual void v102() = 0;
    virtual void v103() = 0;
    virtual void v104() = 0;
    virtual void v105() = 0;
    virtual void v106() = 0;
    virtual void v107() = 0;
    virtual void v108() = 0;
    virtual void v109() = 0;
    virtual void v110() = 0;
    virtual void v111() = 0;
    virtual void v112() = 0;
    virtual void v113() = 0;
    virtual void v114() = 0;
    virtual void v115() = 0;
    virtual Renderer* currentRenderer() = 0;
    virtual void v117() = 0;
    virtual void v118() = 0;
    virtual void v119() = 0;
    virtual void v120() = 0;
    virtual void v121() = 0;
    virtual void v122() = 0;
    virtual void v123() = 0;
    virtual void v124() = 0;
    virtual void v125() = 0;
    virtual void v126() = 0;
    virtual void v127() = 0;
    virtual void v128() = 0;
    virtual void v129() = 0;
    virtual void v130() = 0;
    virtual void v131() = 0;
    virtual void v132() = 0;
    virtual void v133() = 0;
    virtual void v134() = 0;
    virtual void v135() = 0;
    virtual void v136() = 0;
    virtual void v137() = 0;
    virtual void v138() = 0;
    virtual void v139() = 0;
    virtual void v140() = 0;
    virtual void v141() = 0;
    virtual void v142() = 0;
    virtual void v143() = 0;
    virtual void v144() = 0;
    virtual void v145() = 0;
    virtual void v146() = 0;
    virtual void v147() = 0;
    virtual void v148() = 0;
    virtual void v149() = 0;
    virtual void v150() = 0;
    virtual void v151() = 0;
    virtual void v152() = 0;
    virtual void v153() = 0;
    virtual void v154() = 0;
    virtual void v155() = 0;
    virtual void v156() = 0;
    virtual void v157() = 0;
    virtual void v158() = 0;
    virtual void v159() = 0;
    virtual void v160() = 0;
    virtual void v161() = 0;
    virtual void v162() = 0;
    virtual void v163() = 0;
    virtual void v164() = 0;
    virtual void v165() = 0;
    virtual void v166() = 0;
    virtual void v167() = 0;
    virtual void resetRenderer() = 0;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    State* state;
    unsigned char RenderActiveAction(int unused);
};
// @fnv 0x008cd390
unsigned char Player::RenderActiveAction(int unused)
{
    Renderer* renderer = currentRenderer();
    resetRenderer();
    if (state->active != 0 && state->active->isReady())
    {
        Action* pAction = state->action;
        if (pAction == 0)
            return 0;
        ::FUN_00c69ee0((::NiAVObject *)(renderer), 1, 0);
        ::FUN_0062bc10((::FUN_0062bc10_obj *)(renderer));
        reinterpret_cast<::FUN_00440460_S *>((renderer))->FUN_00440460((const ::V3 *)(void *)(&state->unknown04));
        reinterpret_cast<::FUN_0043fa80_s *>((renderer))->FUN_0043fa80((*(const ::ThreeByThreeMatrix *)(&state->configuration30)));
        reinterpret_cast<::FUN_00440490_shell *>((renderer))->FUN_00440490((float)(((double)(reinterpret_cast<::FUN_009cdae0_shell *>((renderer))->GetFloatAt64())) / reinterpret_cast<::FUN_008d01e0_Class *>((void *)(pAction))->FUN_008d01e0()));
        GameContext* ctx = ((::GameContext *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)));
        ::FUN_00b5b1c0((::ShadowSceneNode *)(ctx), (int)(renderer), {});
        pAction->apply(renderer, 1);
        reinterpret_cast<::ShadowSceneNode *>((ctx))->AddObject((::NiAVObject *)(renderer));
        ActiveItem* active = state->active;
        if (active)
        {
            if (((struct ::Callback *)(reinterpret_cast<::BSShaderNoLightingProperty *>((active))->GetBaseTexture())) != 0)
            {
                ((struct ::Callback *)(reinterpret_cast<::BSShaderNoLightingProperty *>((active))->GetBaseTexture()))->execute(this);
            }
        }
    }
    else
    {
        ::FUN_005b5e40();
        return 0;
    }
    return 1;
}

struct EventTarget;
struct ResourceInfo
{
};
struct EventProperty
{
};
struct EventTarget
{
};
struct EventRecord
{
    int param1;
    int param2;
    int param3;
    float weight;
    float defaultWeight;
    unsigned char resourceType;
    unsigned char enabled;
    unsigned short attributes;
    void* eventPointer;
    EventTarget* target;
    int cursorOffset;
};
struct Object
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
    virtual void v64();
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
    virtual int GetSource();
    void FUN_008cfad0(float weight, int a, int b, int c, int offset, unsigned char enabled);
};
// If the object's source resolves to a resource with metadata, builds an EventRecord from the arguments and passes it to FUN_00837550.
// @fnv 0x008cfad0
void Object::FUN_008cfad0(float weight, int aiParam1, int aiParam2, int aiParam3, int offset, unsigned char enabled)
{
    int source = GetSource();
    if (source != 0 && *reinterpret_cast<int**>(reinterpret_cast<unsigned char*>(this) + 0x88) != 0 &&
        **reinterpret_cast<int**>(reinterpret_cast<unsigned char*>(this) + 0x88) == 1)
    {
        ResourceInfo* target = ((::ResourceInfo *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(source))));
        EventTarget* metadata = target ? ((::EventTarget *)(::fnv_006fa820::FUN_006fa820((const char *)(target)))) : 0;
        if (metadata != 0)
        {
            EventRecord record;
            ::FUN_006240d0((void *)&(record));
            record.defaultWeight = ::fnv_00c88020::DAT_01016248;
            record.target = metadata;
            record.cursorOffset = offset;
            record.resourceType = ((unsigned char)(reinterpret_cast<::FUN_006205a0_Class *>((((::EventProperty *)(reinterpret_cast<::FUN_004ae6a0_shell *>((metadata))->FUN_004ae6a0()))))->FUN_006205a0()));
            record.enabled = enabled;
            record.param1 = aiParam1;
            record.param2 = aiParam2;
            record.param3 = aiParam3;
            record.weight = weight;
            record.eventPointer = reinterpret_cast<unsigned char*>(this) + offset;
            ::ImpactSound::FUN_00837550((::ImpactSound::ImpactData *)(::EventRecord *)(&record));
        }
    }
}

struct FUN_00620b80_shell
{
    unsigned int GetReferenceFlags();
};
struct FUN_005609f0_shell
{
    bool FUN_005609f0();
};
struct FUN_00a29680_Obj
{
};
struct Holder_cffa0
{
    bool FUN_008cffa0();
};

// Gets the object from this, calls FUN_00a29680 around a FUN_008cfff0 call on it, and returns the resulting bool, or false if the object is null.
// @fnv 0x008cffa0
bool Holder_cffa0::FUN_008cffa0()
{
    FUN_008cfff0_Class* obj =
        reinterpret_cast<FUN_008cfff0_Class*>(reinterpret_cast<FUN_00620b80_shell*>(this)->GetReferenceFlags());
    bool result = false;
    if (obj != 0)
    {
        ::FUN_00a29680();
        unsigned char tmp;
        result = reinterpret_cast<FUN_005609f0_shell*>(obj->FUN_008cfff0(reinterpret_cast<CalleeObj*>(&tmp)))
                     ->FUN_005609f0();
        ::FUN_00a29680();
    }
    return result;
}

struct Target_cls
{
};
struct Arg_cls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
};
struct FUN_008d14e0_cls
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    Target_cls* m_650;
    void FUN_008d14e0(Arg_cls* a1);
};
extern float DAT_011dfed4;

// @fnv 0x008d1cf0
float __cdecl FUN_008d1cf0()
{
    return DAT_011dfed4;
}

extern float DAT_011dfed8;

// @fnv 0x008d1d00
float __cdecl FUN_008d1d00()
{
    return DAT_011dfed8;
}

class ThreeByThreeMatrix
{
  public:
    float m00;
    float m01;
    float m02;
    float m10;
    float m11;
    float m12;
    float m20;
    float m21;
    float m22;
    ThreeByThreeMatrix operator*(const ThreeByThreeMatrix& rhs) const;
public:
    ::ThreeByThreeMatrix operator+(const ::ThreeByThreeMatrix &) const;
public:
    ::ThreeByThreeMatrix *FUN_004b45b0(::ThreeByThreeMatrix *);
public:
    bool Inverse(::ThreeByThreeMatrix &);
};

struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    bool unk06;
    bool unk07;
    bool unk08;
    NiUpdateData(float time, bool updateControllers, bool multiThreaded);
};

struct AnimTimeSource
{
};

struct NiAVObject
{
    AnimTimeSource* GetObject3D();
};


// @fnv 0x008d6970
int ComputeRelativeRotation(int index, float time, ThreeByThreeMatrix* pOutRotate)
{
    if (!DAT_011e0110[index] || !DAT_011e00e0[index])
    {
        *pOutRotate = DAT_011a9448;
        return 0;
    }
    AnimTimeSource* source7 = ((NiAVObject*)DAT_011e0110[index])->GetObject3D();
    if (index != 0)
    {
        float sourceTime = reinterpret_cast<::TESActorBaseData *>((source7))->GetHealthRegeneration();
        NiUpdateData data3(sourceTime, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((NiAVObject*)DAT_011e0110[index])))->FUN_00a59c60((int)&(data3));
    }
    ThreeByThreeMatrix rotate5 = (*(const ::ThreeByThreeMatrix *)(::FUN_006a9540((char *)(((NiAVObject*)DAT_011e0110[index])))));
    NiUpdateData update2(time, true, false);
    reinterpret_cast<::FUN_00a59c60_cls *>((((NiAVObject*)DAT_011e0110[index])))->FUN_00a59c60((int)&(update2));
    *pOutRotate = reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(const ::ThreeByThreeMatrix &)((*(::ThreeByThreeMatrix *)(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(rotate5))->FUN_004b45b0({})))))->operator+((*(const ::ThreeByThreeMatrix *)(::FUN_006a9540((char *)(((NiAVObject*)DAT_011e0110[index]))))));
    return DAT_011e00e0[index];
}

struct Small_b7397
{
    int unk00;
    void Reset(int v);
    ~Small_b7397();
};

struct Sub08_b7397
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
    ~Sub08_b7397();
};

class FUN_008d6af0_cls
{
  public:
    int unk04;
    Sub08_b7397 m_08;
    Small_b7397 m_98;
    Small_b7397 m_9c;
    Small_b7397 m_a0;
    virtual ~FUN_008d6af0_cls();
};

// Destructor that resets the three Small_b7397 members m_a0, m_9c and m_98 to zero before the object is destroyed.
// @fnv 0x008d6af0
FUN_008d6af0_cls::~FUN_008d6af0_cls()
{
    m_a0.Reset(0);
    m_9c.Reset(0);
    m_98.Reset(0);
}

struct PathPoint
{
    float x, y, z;
};
class PathingRequest
{
  public:
    PathingRequest();
    virtual ~PathingRequest();
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

    void SetSmoothingRandomness(float);
};
struct PathActor
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
    virtual PathPoint* Position();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual int state();
    void UpdatePathing(PathActor* actor);
};
// @fnv 0x008df060
void PathActor::UpdatePathing(PathActor* actor)
{
    if (actor)
    {
        if (!reinterpret_cast<::FUN_0087f660_cls *>((actor))->IsWithinProcThreshold())
        {
            if (((bool)(reinterpret_cast<::TeleportableReference *>((actor))->GetTeleportDestinationForm())))
            {
                float smoothing = ::g_011d8aa4_arg1;
                PathPoint position4 = *actor->Position();
                position4.z = reinterpret_cast<::FUN_0057b0a0_shell *>((actor))->FUN_0057b0a0() + smoothing;
                PathingRequest request;
                reinterpret_cast<::fnv_008b3880::FUN_008b3880_target *>((actor))->PathToLocation((::fnv_008b3880::PathingRequest *)(::PathingRequest *)(&request), &position4, ((void *)(reinterpret_cast<::LowProcess *>((actor))->GetTarget())), ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((actor))->FUN_00575d70())), smoothing, (::fnv_008b3880::PathingAvoidNodeArray *)(0));
                request.SetSmoothingRandomness(smoothing);
                reinterpret_cast<::FUN_008df1c0_Class *>(&(request))->SetByteAtA1(1);
                reinterpret_cast<::B_008b3630 *>((actor))->SetPathingRequestAvoidNodes((::PathingRequest_b *)(::PathingRequest *)(&request));
            }
        }
        else
        {
            state();
            reinterpret_cast<::FUN_008b3ab0_shell *>((actor))->FUN_008b3ab0();
        }
    }
}

struct B8DF9B0Queue
{
    void* m_pHead;

    ~B8DF9B0Queue();
};

class B8DF9B0Base
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;

    ~B8DF9B0Base();
};

class FUN_008df9b0 : public B8DF9B0Base
{
  public:
    B8DF9B0Queue m_kQueue;

    ~FUN_008df9b0();
};
// Calls FUN_008df9b0, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x008df980
void* FUN_008df980_Class::FUN_008df980(unsigned int flags)
{
    reinterpret_cast<::FUN_008df9b0 *>(this)->FUN_008df9b0::~FUN_008df9b0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x1c);
    return this;
}

// Destructor for FUN_008df9b0; the body is empty, so member destructors run implicitly.
// @fnv 0x008df9b0
FUN_008df9b0::~FUN_008df9b0()
{}

// Forward a reference's base form and its owner value (if it has extra data) to this handler.

class C1CD0Owner
{
  public:
};

class C1CD0Ref
{
  public:
};

class C1CD0Handler
{
  public:
    void Handle(void* pvBaseForm, int iValue);
    void HandleRef(C1CD0Ref* pkRef);
};

// Secondary-interface override: return the current process's value, or null when the actor has no process.

class C44C0Process
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
    virtual void* GetCurrentPackage();
};

class C44C0Primary
{
  public:
    virtual ~C44C0Primary();
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
};

class C44C0Interface
{
  public:
    virtual void* FUN_008c44c0();
};

class C44C0Actor : public C44C0Primary, public C44C0Interface
{
  public:
    virtual void* FUN_008c44c0();
};

// Returns the current package from the actor's process, or null if the actor has no process.
// @fnv 0x008c44c0
void* C44C0Actor::FUN_008c44c0()
{
    return ((::C44C0Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())) ? ((::C44C0Process *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->GetCurrentPackage() : 0;
}

struct ArrowWorldObj;
struct ArrowCollision
{
};
struct ArrowRenderer;
struct ArrowImpact
{
    int type;
};
struct ArrowProjectile
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
    virtual void v64();
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
    virtual ArrowRenderer* GetRenderer();
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
    ArrowImpact* impact;
    int unk8c;
    bool ProcessImpact();
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3& operator+=(const NiPoint3&);
};
struct RotationMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    NiPoint3 FUN_004b4500(const NiPoint3&);
};
struct SceneNode
{
    RotationMatrix& FUN_00461130();
};
struct LoadingState
{
};
struct FloatSetting
{
};
struct AnimationOutput
{
    void FUN_00626cb0(unsigned int);
};
struct UpdateToken
{
    unsigned int value;
    UpdateToken(int, unsigned int, int);
};
struct ResourceUpdate
{
};
NiPoint3 FUN_004a3760(float, const NiPoint3&);
struct MovementState
{
    unsigned int unknown00;
    NiPoint3 position;
    NiPoint3 direction;
};
struct MovementController
{
    virtual void virtual0() = 0;
    virtual void virtual1() = 0;
    virtual void virtual2() = 0;
    virtual void virtual3() = 0;
    virtual void virtual4() = 0;
    virtual void virtual5() = 0;
    virtual void virtual6() = 0;
    virtual void virtual7() = 0;
    virtual void virtual8() = 0;
    virtual void virtual9() = 0;
    virtual void virtual10() = 0;
    virtual void virtual11() = 0;
    virtual void virtual12() = 0;
    virtual void virtual13() = 0;
    virtual void virtual14() = 0;
    virtual void virtual15() = 0;
    virtual void virtual16() = 0;
    virtual void virtual17() = 0;
    virtual void virtual18() = 0;
    virtual void virtual19() = 0;
    virtual void virtual20() = 0;
    virtual void virtual21() = 0;
    virtual void virtual22() = 0;
    virtual void virtual23() = 0;
    virtual void virtual24() = 0;
    virtual void virtual25() = 0;
    virtual void virtual26() = 0;
    virtual void virtual27() = 0;
    virtual void virtual28() = 0;
    virtual void virtual29() = 0;
    virtual void virtual30() = 0;
    virtual void virtual31() = 0;
    virtual void virtual32() = 0;
    virtual void virtual33() = 0;
    virtual void virtual34() = 0;
    virtual void virtual35() = 0;
    virtual void virtual36() = 0;
    virtual void virtual37() = 0;
    virtual void virtual38() = 0;
    virtual void virtual39() = 0;
    virtual void virtual40() = 0;
    virtual void virtual41() = 0;
    virtual void virtual42() = 0;
    virtual void virtual43() = 0;
    virtual void virtual44() = 0;
    virtual void virtual45() = 0;
    virtual void virtual46() = 0;
    virtual void virtual47() = 0;
    virtual void virtual48() = 0;
    virtual void virtual49() = 0;
    virtual void virtual50() = 0;
    virtual void virtual51() = 0;
    virtual void virtual52() = 0;
    virtual void virtual53() = 0;
    virtual void virtual54() = 0;
    virtual void virtual55() = 0;
    virtual void virtual56() = 0;
    virtual void virtual57() = 0;
    virtual void virtual58() = 0;
    virtual void virtual59() = 0;
    virtual void virtual60() = 0;
    virtual void virtual61() = 0;
    virtual void virtual62() = 0;
    virtual void virtual63() = 0;
    virtual void virtual64() = 0;
    virtual void virtual65() = 0;
    virtual void virtual66() = 0;
    virtual void virtual67() = 0;
    virtual void virtual68() = 0;
    virtual void virtual69() = 0;
    virtual void virtual70() = 0;
    virtual void virtual71() = 0;
    virtual void virtual72() = 0;
    virtual void virtual73() = 0;
    virtual void virtual74() = 0;
    virtual void virtual75() = 0;
    virtual void virtual76() = 0;
    virtual void virtual77() = 0;
    virtual void virtual78() = 0;
    virtual void virtual79() = 0;
    virtual void virtual80() = 0;
    virtual void virtual81() = 0;
    virtual void virtual82() = 0;
    virtual void virtual83() = 0;
    virtual void virtual84() = 0;
    virtual void virtual85() = 0;
    virtual void virtual86() = 0;
    virtual void virtual87() = 0;
    virtual void virtual88() = 0;
    virtual void virtual89() = 0;
    virtual void virtual90() = 0;
    virtual void virtual91() = 0;
    virtual void virtual92() = 0;
    virtual void virtual93() = 0;
    virtual void virtual94() = 0;
    virtual void virtual95() = 0;
    virtual void virtual96() = 0;
    virtual void virtual97() = 0;
    virtual void virtual98() = 0;
    virtual void virtual99() = 0;
    virtual void virtual100() = 0;
    virtual void virtual101() = 0;
    virtual void virtual102() = 0;
    virtual void virtual103() = 0;
    virtual void virtual104() = 0;
    virtual void virtual105() = 0;
    virtual void virtual106() = 0;
    virtual void virtual107() = 0;
    virtual void virtual108() = 0;
    virtual void virtual109() = 0;
    virtual void virtual110() = 0;
    virtual void virtual111() = 0;
    virtual void virtual112() = 0;
    virtual void virtual113() = 0;
    virtual void virtual114() = 0;
    virtual void virtual115() = 0;
    virtual SceneNode* getNode() = 0;
    virtual void virtual117() = 0;
    virtual void virtual118() = 0;
    virtual void virtual119() = 0;
    virtual void virtual120() = 0;
    virtual void virtual121() = 0;
    virtual void virtual122() = 0;
    virtual void virtual123() = 0;
    virtual void virtual124() = 0;
    virtual void virtual125() = 0;
    virtual void virtual126() = 0;
    virtual void virtual127() = 0;
    virtual void virtual128() = 0;
    virtual void virtual129() = 0;
    virtual void virtual130() = 0;
    virtual void virtual131() = 0;
    virtual void virtual132() = 0;
    virtual void virtual133() = 0;
    virtual void virtual134() = 0;
    virtual void virtual135() = 0;
    virtual void virtual136() = 0;
    virtual void virtual137() = 0;
    virtual void virtual138() = 0;
    virtual void virtual139() = 0;
    virtual void virtual140() = 0;
    virtual void virtual141() = 0;
    virtual void virtual142() = 0;
    virtual void virtual143() = 0;
    virtual void virtual144() = 0;
    virtual void virtual145() = 0;
    virtual void virtual146() = 0;
    virtual void virtual147() = 0;
    virtual void virtual148() = 0;
    virtual void virtual149() = 0;
    virtual void virtual150() = 0;
    virtual void virtual151() = 0;
    virtual void virtual152() = 0;
    virtual void virtual153() = 0;
    virtual void virtual154() = 0;
    virtual void virtual155() = 0;
    virtual void virtual156() = 0;
    virtual void virtual157() = 0;
    virtual void virtual158() = 0;
    virtual void virtual159() = 0;
    virtual void virtual160() = 0;
    virtual void virtual161() = 0;
    virtual void virtual162() = 0;
    virtual void virtual163() = 0;
    virtual void virtual164() = 0;
    virtual void virtual165() = 0;
    virtual void virtual166() = 0;
    virtual void virtual167() = 0;
    virtual void resetNode() = 0;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    unsigned int unknown30;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    MovementState* state;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    float speed;
    unsigned int unknown9c;
    unsigned int unknowna0;
    unsigned int unknowna4;
    unsigned int unknowna8;
    unsigned int unknownac;
    unsigned int unknownb0;
    NiPoint3 velocity;
    bool UpdateAnimation(AnimationOutput* output);
};
struct NiRefObjectStub
{
    void IncRefCount();
    void DecRefCount();
    static void* operator new(unsigned int size);
};

struct BSMultiBoundShape : NiRefObjectStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    BSMultiBoundShape();
};

struct BSMultiBound : NiRefObjectStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BSMultiBound();
    void SetShape(BSMultiBoundShape* shape);
};

struct BSMultiBoundNode : NiRefObjectStub
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
    BSMultiBoundNode();
};

struct SceneArg
{
    void* GetData();
};

struct SceneHolder
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
};

struct FUN_008d6bb0_owner
{
    int unk00;
    int unk04;
    SceneHolder holder;
    NiPointer<BSMultiBoundNode> m_pController;
    NiPointer<BSMultiBound> pMultiBound;
    NiPointer<BSMultiBoundShape> pShape;
    void CreateMultiBoundNode(SceneArg* arg);
};
// @fnv 0x008d6f50
void FUN_008d6f50_Class::FUN_008d6f50(int pCamera)
{
    if (reinterpret_cast<::_FUN_00822510_Class *>((void *)(((NiPointer<NiNode>*)((char*)this + 0xa0))))->operator====((int)(0)))
    {
        reinterpret_cast<::FUN_008d6bb0_owner *>((((FUN_008d6bb0_shell*)this)))->CreateMultiBoundNode((::SceneArg *)(pCamera));
    }
    else
    {
        reinterpret_cast<::FUN_0041fd00_shell *>((((MagicCaster*)((char*)this + 8))))->FUN_0041fd00(pCamera);
        ((S694a0*)((char*)this + 8))->FUN_00a694a0((void*)&((NiCamera*)pCamera)->GetViewFrustum());
    }
    reinterpret_cast<::FUN_0096bbc0_cls *>(&((*reinterpret_cast<::ProcessLists *>(&::g_011e0e80))))->ProcessMobileObjects((::FUN_0096bbc0_list *)(void *)(this));
}

// Stores the scene arg and data in holder, then allocates a shape, a multi bound and a multi bound node and links them together.
// @fnv 0x008d6bb0
void FUN_008d6bb0_owner::CreateMultiBoundNode(SceneArg* arg)
{
    reinterpret_cast<::FUN_0041fd00_shell *>(&(holder))->FUN_0041fd00((int)(arg));
    reinterpret_cast<::S694a0 *>(&(holder))->FUN_00a694a0(arg->GetData());
    pShape = new BSMultiBoundShape;
    pMultiBound = new BSMultiBound;
    m_pController = new BSMultiBoundNode;
    pMultiBound->SetShape(pShape);
    reinterpret_cast<::BSFaceGenNiNode *>(((m_pController).operator->()))->SetAnimationData((::BSFaceGenAnimationData *)(::BSMultiBound *)(pMultiBound));
}

struct FUN_00559450_shell
{
    int FUN_00559450();
};

int FUN_00559450_shell::FUN_00559450()
{
    return 0;
}

struct FUN_008c7a30_class
{
    int unk00;
    int unk04;
    int unk08;
    volatile int values[2]; /* volatile: the original reloads the element instead of folding it into the add */
    int unk14;

    struct Item
    {
        int unk00;
        int unk04;
        int unk08;
    };

    Item items[2];

    int GetValueWithItemResult(int index);
};

// If index is below 2, returns values[index] plus the result of FUN_00559450 called on items[index]; otherwise returns 0.
// @fnv 0x008c7a30
int FUN_008c7a30_class::GetValueWithItemResult(int index)
{
    int result = 0;

    if (index < 2)
    {
        result = values[index] + ::FUN_00559450((int *)(reinterpret_cast<FUN_00559450_shell*>(&items[index])));
    }

    return result;
}

struct CollisionFilterD6
{
    unsigned int value;
    CollisionFilterD6(unsigned int v);
};
struct AnimationOutputD6
{
    CollisionFilterD6 FUN_0043b4f0();
    void FUN_00626cb0(unsigned int);
};
struct MovementControllerD6 : MovementController
{
    bool FUN_008cd6d0(AnimationOutputD6* output);
};
// @fnv 0x008cd210
bool ArrowProjectile::ProcessImpact()
{
    bool bResult = false;
    if (impact == 0)
        return bResult;
    ArrowCollision* info = GetRenderer() ? ((::ArrowCollision *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::ArrowRenderer *)(GetRenderer())))) : 0;
    if (info == 0)
    {
        ::FUN_005b5e40();
        delete impact;
        impact = 0;
        return bResult;
    }
    ArrowWorldObj* obj = ((::ArrowWorldObj *)(::fnv_006fa820::FUN_006fa820((const char *)(info))));
    switch (impact->type)
    {
    case 0:
        bResult = ((bool)(reinterpret_cast<::Player *>(this)->RenderActiveAction((int)(obj))));
        break;
    case 1:
        bResult = reinterpret_cast<::Projectile8CD *>(this)->FUN_008cd520((::Caster8CD *)(obj));
        break;
    case 2:
        bResult = reinterpret_cast<::MovementControllerD6 *>(this)->FUN_008cd6d0((::AnimationOutputD6 *)(obj));
        break;
    case 3:
        bResult = reinterpret_cast<::MovementController *>(this)->UpdateAnimation((::AnimationOutput *)(obj));
        break;
    case 4:
        bResult = reinterpret_cast<::SceneProjectile *>(this)->FUN_008cdaf0((::SceneOutput *)(obj));
        break;
    }
    if (!bResult)
    {
        if (impact)
        {
            delete impact;
            impact = 0;
        }
        unk8c = 0;
    }
    return bResult;
}
// Resets the node, applies the state position, then writes a collision filter and an update token into the animation output and returns true.
// @fnv 0x008cd6d0
bool MovementControllerD6::FUN_008cd6d0(AnimationOutputD6* output)
{
    resetNode();
    reinterpret_cast<::FUN_00440460_S *>((getNode()))->FUN_00440460((const ::V3 *)&(state->position));
    reinterpret_cast<::Reference *>(this)->FUN_00575830((::Position *)&(state->position));
    CollisionFilterD6 filter = output->FUN_0043b4f0();
    reinterpret_cast<::FUN_004a39f0_shell *>(&(filter))->FUN_004a39f0(0xf);
    reinterpret_cast<::FUN_00810f90_shell *>(&(filter))->SetFlag4000(false);
    output->FUN_00626cb0(filter.value);
    output->FUN_00626cb0(UpdateToken(0xf, GetCachedValue(), 0).value);
    return true;
}

// Returns a value from 100 down to 0 based on the iLevel input, with specific mappings for levels 0 through 13.
// @fnv 0x008d5750
int GetLevelValue(int iLevel)
{
    switch (iLevel)
    {
    case 3:
        return 100;
        break;
    case 11:
        return 90;
        break;
    case 0:
        return 80;
        break;
    case 1:
        return 80;
        break;
    case 7:
        return 70;
        break;
    case 8:
        return 70;
        break;
    case 5:
        return 60;
        break;
    case 4:
        return 50;
        break;
    case 2:
        return 40;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 20;
        break;
    case 12:
        return 15;
        break;
    case 6:
        return 10;
        break;
    case 13:
        return 5;
    }
    return 0;
}

void* operator new(unsigned int, void*);
void operator delete(void*, void*);
struct HandleBase
{
    ~HandleBase();
};
struct FUN_008caa70
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    FUN_008caa70(void* src);
};
namespace ca9 {
struct Handle
{
    void* m_iWordAt00;
    void* m_iWordAt04;
    void* m_8;
    void Reinitialize(int b);
};
// Destroys the current HandleBase state and reconstructs the object in place as a FUN_008caa70 from the given value.
// @fnv 0x008ca9e0
void Handle::Reinitialize(int b)
{
    ((HandleBase*)this)->HandleBase::~HandleBase();
    new (this) FUN_008caa70((void*)b);
}
}

namespace s8d5830 {

// Maps uiType 0-13 to fixed values between 500 and 180000, returning 500 for any other type.
// @fnv 0x008d5830
int FUN_008d5830(unsigned int uiType)
{
    switch (uiType)
    {
    case 3:
        return 500;
        break;
    case 11:
        return 500;
        break;
    case 0:
        return 1500;
        break;
    case 1:
        return 1500;
        break;
    case 7:
        return 1000;
        break;
    case 8:
        return 1000;
        break;
    case 5:
        return 120000;
        break;
    case 4:
        return 180000;
        break;
    case 2:
        return 500;
        break;
    case 9:
        return 60000;
        break;
    case 10:
        return 1000;
        break;
    case 6:
        return 180000;
        break;
    case 12:
        return 20000;
        break;
    case 13:
        return 3000;
    }
    return 500;
}

}

class RefrBase5e30
{
  public:
    virtual ~RefrBase5e30();
    int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int unk24, unk28, unk2C, unk30, unk34, unk38, unk3C, unk40;
    int unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60;
    int unk64, unk68, unk6C, unk70, unk74, unk78, unk7C, unk80;
    int unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0;
};
class AVOwner5e30
{
  public:
    virtual void v00();
    virtual float GetBaseActorValue(int av);
    virtual void v08();
    virtual float GetActorValue(int av);
};
class Actor5e30 : public RefrBase5e30, public AVOwner5e30
{
};
struct HealthCond5e30
{
    Actor5e30* pActor;
    int iType;
    bool IsHealthConditionMet();
};
// Checks whether the actor's health ratio or a set of actor values satisfies the condition type stored in iType.
// @fnv 0x008d5e30
bool HealthCond5e30::IsHealthConditionMet()
{
    if (!pActor)
        return false;
    switch (iType)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return false;
        break;
    case 5: {
        float fCurrentValue = pActor->GetActorValue(16);
        float fBaseValue = pActor->GetBaseActorValue(16);
        float fHealthRatio = 1.0f;
        if (fBaseValue != 0.0)
            fHealthRatio = fCurrentValue / fBaseValue;
        if (fHealthRatio <= 0.25)
            return true;
        return false;
    }
    break;
    case 4: {
        float fCurrentValue = pActor->GetActorValue(16);
        float fBaseValue = pActor->GetBaseActorValue(16);
        float fHealthRatio = 1.0f;
        if (fBaseValue != 0.0)
            fHealthRatio = fCurrentValue / fBaseValue;
        if (fHealthRatio > 0.25 && fHealthRatio <= 0.5)
            return true;
        return false;
    }
    break;
    case 6:
        for (int i = 25; i < 31; i++)
        {
            if (pActor->GetActorValue(i) == 0.0)
                return true;
        }
        return false;
        break;
    }
    return false;
}

extern float DAT_01087820;

struct Vec3
{
    float x, y, z;
public:
    Vec3();
};
// @fnv 0x008cab20
FUN_008cab20::FUN_008cab20()
{
    *(void**)this = &DAT_01085954;
    *(void**)((char*)this + 0x18) = &DAT_01085948;
    new ((void *)(((B006815c0*)((char*)this + 0xb4)))) ::Vec3();
    reinterpret_cast<::FUN_0046a010_shell *>((((TESObjectREFR*)this)))->FUN_0046a010(1);
    *(HighProcess**)((char*)this + 0x68) = new HighProcess;
    *(int*)((char*)this + 0x88) = 0;
    this->unkc0 = 0;
    *(int*)((char*)this + 0xc4) = 0;
    this->unkc1 = 0;
    this->unkc3 = 0;
    DAT_011dfc98++;
}
// Calls GetItem on four BSSimpleList<BGSPerk*> members at offsets 4, 0x10, 0x1c and 0x30, then returns this.
// @fnv 0x008cc6f0
void* FUN_008cc6f0_Class::FUN_008cc6f0()
{
    new ((void *)(((BSSimpleList<BGSPerk*>*)((char*)this + 4)))) ::Vec3();
    new ((void *)(((BSSimpleList<BGSPerk*>*)((char*)this + 0x10)))) ::Vec3();
    new ((void *)(((BSSimpleList<BGSPerk*>*)((char*)this + 0x1c)))) ::Vec3();
    new ((void *)(((BSSimpleList<BGSPerk*>*)((char*)this + 0x30)))) ::Vec3();
    return this;
}
// If a is nonzero, walks the list nodes while FUN_005ae380 is true and calls v14(a) on the first item of each node.
// @fnv 0x008c4f10
void S_8c4f10_Cls::FUN_008c4f10(int a)
{
    S_8c4f10_Node* pNode;
    if (a)
    {
        pNode = list.v02();
        while (pNode && pNode->FUN_005ae380())
        {
            if (*((::S_8c4f10_Item **)(new ((void *)(pNode)) ::Vec3())))
            {
                (*((::S_8c4f10_Item **)(new ((void *)(pNode)) ::Vec3())))->v14(a);
            }
            pNode = ((::S_8c4f10_Node *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
    }
}
// If m_650 is non-null and its two checks both return zero, calls FUN_008d12e0 with m_650 and values from a1.
// @fnv 0x008d14e0
void FUN_008d14e0_cls::FUN_008d14e0(Arg_cls* apArg)
{
    Target_cls* p = m_650;
    if (p == 0 || ((int)(reinterpret_cast<::FUN_008ce390_shell *>((p))->FUN_008ce390())) != 0 || ((unsigned char)(reinterpret_cast<::FUN_00440d80_shell *>((p))->FUN_00440d80())) != 0)
    {
    }
    else
    {
        ::FUN_008d12e0((::TargetOwner *)(p), (::SourceData *)(apArg->unk0048), ((int)(new ((void *)(apArg)) ::Vec3())), ::FUN_00460140((int)(apArg)));
    }
}
// Calls Handle with the ref's base form and the owner's value, or 0 when there is no owner.
// @fnv 0x008c1cd0
void C1CD0Handler::HandleRef(C1CD0Ref* pkRef)
{
    reinterpret_cast<::Twin_0080f7d0 *>(this)->IsPointInside((float)(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((pkRef))->GetName()))), ((::C1CD0Owner *)(::FUN_00559450((int *)(pkRef)))) ? *((int *)(new ((void *)(((::C1CD0Owner *)(::FUN_00559450((int *)(pkRef)))))) ::Vec3())) : 0);
}
// Resets the node, updates its transform and rotation from the movement state, and pushes rotation and angle data to the animation output.
// @fnv 0x008cd780
bool MovementController::UpdateAnimation(AnimationOutput* output)
{
    resetNode();
    if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::LoadingState * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
    {
        reinterpret_cast<::FUN_00440460_S *>((getNode()))->FUN_00440460((const ::V3 *)&(state->position));
        NiUpdateData update(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((getNode()))->FUN_00a59c60((int)&(update));
    }
    ::FUN_00c6a350((::NiAVObject *)(::SceneNode *)(getNode()), 1, true, false, true);
    output->FUN_00626cb0(UpdateToken(4, GetCachedValue(), 0).value);
    if (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::LoadingState * *>(&::g_TESSaveLoadGame))))->EvaluateCondition())
    {
        NiPoint3 aRotation = FUN_004a3760(-1.0f, velocity);
        ::FUN_00525340((float *)&(aRotation));
        ::FUN_00525340((float *)&(state->direction));
        float scale = reinterpret_cast<::FUN_004b6190_shell *>(&(state->direction))->DotProduct((void *)&(aRotation));
        NiPoint3 normal7 = FUN_004a3760(2.0f, FUN_004a3760(scale, state->direction) - aRotation);
        reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NiPoint3 &)(aRotation))->FUN_0063c8a0((void *)&(normal7));
        reinterpret_cast<::Owner5615 *>((output))->FUN_005615d0((int)&(const ::NiPoint3 &)(FUN_004a3760(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting650)))))) * speed, aRotation)));
        RotationMatrix matrix9;
        new ((void *)&(matrix9)) ::Vec3();
        reinterpret_cast<::ThreeByThreeMatrix *>(&(getNode()->FUN_00461130()))->Inverse((::ThreeByThreeMatrix &)(matrix9));
        NiPoint3 normal = matrix9.FUN_004b4500(state->direction);
        if (FUN_00408820(normal.y) > FUN_00408820(normal.z))
            normal.z = FUN_00408820(normal.y) * SignOfFloat(normal.z);
        normal.y = 0.0f;
        ::FUN_00525340((float *)&(normal));
        NiPoint3 angle(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting649)))))) * normal.z, 0.0f, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::FloatSetting *>(&::originalRuntimeFloatSetting649)))))) * -normal.x);
        reinterpret_cast<::bhkCharacterController *>((output))->FUN_00561630(getNode()->FUN_00461130().FUN_004b4500(angle));
    }
    ResourceUpdate* resource = ((::ResourceUpdate *)(::fnv_004b5260::FUN_004b5260((::NiAVObject *)(::SceneNode *)(getNode()))));
    if (resource)
        reinterpret_cast<::fnv_00573ed0::_dummy_4d9fa0 *>((resource))->FUN_00573ed0(true);
    return true;
}

struct FloatHolder
{
    float val;
};

struct FUN_008d6fc0_cls
{
    int f00;
    int f04;
    int f08;
    Vec3 f0c;
    FloatHolder f18;
    char f1c;
    char f1d;
    char f1e;
    char f1f;
    int f20;
    void FUN_008d6fc0(const FUN_008d6fc0_cls& rhs);
};

// Copies all fields from rhs, copying f0c and f18 only when rhs.f18.FUN_006a7f50() exceeds -DAT_01087820.
// @fnv 0x008d6fc0
void FUN_008d6fc0_cls::FUN_008d6fc0(const FUN_008d6fc0_cls& rhs)
{
    f00 = rhs.f00;
    f04 = rhs.f04;
    f1e = rhs.f1e;
    f08 = rhs.f08;
    f1c = rhs.f1c;
    f1d = rhs.f1d;
    f20 = rhs.f20;
    f1f = rhs.f1f;
    if (reinterpret_cast<::CombatTargetTimestamp *>((void *)&(rhs.f18))->FUN_006a7f50() > -DAT_01087820)
    {
        f0c = rhs.f0c;
        f18 = rhs.f18;
    }
}

class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
class TESForm : public BaseFormComponent
{
  public:
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
public:
    void ClearData();
};
// Destroys the Date object pointed to by pp, then calls FUN_008ca8d0 on pp.
// @fnv 0x008ca770
void FUN_008ca770_Class::FUN_008ca770(Date** ppDate)
{
    reinterpret_cast<::TESForm *>(((*ppDate)))->ClearData();
    reinterpret_cast<::FUN_008ca8d0_Class *>(this)->FUN_008ca8d0((int *)(ppDate));
}
class TESChildCell
{
  public:
    virtual ~TESChildCell();
};
class CreatureRefr : public TESForm, public TESChildCell
{
  public:
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
};
class MobileObject : public CreatureRefr
{
  public:
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
};
class CreatureCaster
{
  public:
    virtual ~CreatureCaster();
    unsigned int unk04, unk08;
    void SetSelectedMagicItem(int);
};
class MagicTarget
{
  public:
    virtual ~MagicTarget();
    unsigned int unk04, unk08, unk0c;
};
class ActorValueOwner
{
  public:
    virtual ~ActorValueOwner();
};
class CachedValuesOwner
{
  public:
    virtual ~CachedValuesOwner();
};
class Actor : public MobileObject,
              public CreatureCaster,
              public MagicTarget,
              public ActorValueOwner,
              public CachedValuesOwner
{
  public:
    virtual ~Actor();
};
class FUN_008d45f0 : public Actor
{
  public:
    virtual ~FUN_008d45f0();
};
// Destructor that calls FUN_008d47d0(0, 0) when FUN_004077c0() returns false.
// @fnv 0x008d45f0
FUN_008d45f0::~FUN_008d45f0()
{
    if (!reinterpret_cast<::FUN_004077c0_shell *>(this)->FUN_004077c0())
        reinterpret_cast<::TESObjectREFR *>(this)->Get3D((::NiNode *)(0), 0);
}

struct RefObj
{
};
class AttachedArrowView
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~AttachedArrowView();
};
struct AttachedArrowFilter
{
};
struct AttachedArrowTimer;
class AttachedArrowProcesses
{
  public:
};
class TopicInfoArray
{
  public:
};
// Removes up to maximum ArrowProjectiles matching owner, target and filter: the first pass deletes or calls FUN_008cc6d0(3), the second pass always deletes.
// @fnv 0x008ce180
void FUN_008ce180(void* target, int maximum, int owner, bool destroy, bool filter)
{
    int list = 0;
    TopicInfoArray* count = (TopicInfoArray*)((::AttachedArrowTimer *)(reinterpret_cast<::BaseProcess *>((((AttachedArrowProcesses*)&(*reinterpret_cast<::ProcessLists *>(&::g_011e0e80)))))->GetCurrentProcessData()));
    for (unsigned index = 0; list < maximum && index < reinterpret_cast<::FUN_005be5c0_shell *>((count))->FUN_005be5c0(0); index++)
    {
        bool arrow = false;
        MobileObject* removed = (MobileObject*)((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((count))->FUN_00968670(index)));
        ArrowProjectile* item = dynamic_cast<ArrowProjectile*>(removed);
        if (item && ((int)(reinterpret_cast<::FUN_0085f810_shell *>((((AttachedArrowView*)item)))->FUN_0085f810())) == owner &&
            ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((RefObj*)item)))->FUN_007af430())) == target &&
            (!filter || reinterpret_cast<::FUN_008ce370_cls *>((((AttachedArrowFilter*)item)))->GetByteAtOffsetC1()))
        {
            if (destroy)
            {
                delete (AttachedArrowView*)item;
                arrow = true;
            }
            else
                ((FUN_008cc6d0_class*)item)->FUN_008cc6d0(3);
            list++;
        }
    }
    for (unsigned second = reinterpret_cast<::FUN_005be5c0_shell *>((count))->FUN_005be5c0(1); list < maximum && second < reinterpret_cast<::FUN_005be5c0_shell *>((count))->FUN_005be5c0(1); second++)
    {
        bool item2 = false;
        MobileObject* arrow2 = (MobileObject*)((::Actor *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>((count))->FUN_00968670(second)));
        ArrowProjectile* removed2 = dynamic_cast<ArrowProjectile*>(arrow2);
        if (removed2 && ((int)(reinterpret_cast<::FUN_0085f810_shell *>((((AttachedArrowView*)removed2)))->FUN_0085f810())) == owner &&
            ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((RefObj*)removed2)))->FUN_007af430())) == target &&
            (!filter || reinterpret_cast<::FUN_008ce370_cls *>((((AttachedArrowFilter*)removed2)))->GetByteAtOffsetC1()))
        {
            delete (AttachedArrowView*)removed2;
            list++;
        }
    }
}

struct FUN_008c2630_Obj;

class TESBoundObject
{
  public:
    virtual void v0();
    int FUN_00401170();
};

class TESHealthForm : public TESBoundObject
{
  public:
    virtual void h0();
};

class TESEnchantableForm : public TESHealthForm
{
  public:
    virtual void w0();
};

struct FUN_008c2630_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(void* p, TESBoundObject* a, int b);
};

class FUN_008c2630_Owner
{
  public:
    char unk00[0x88];
    FUN_008c2630_Obj m_88;
    void FUN_008c2630(TESBoundObject* a1, int a2);
};

// If a1 is form type 0x18 or 0x1a, dynamic_cast it to TESEnchantableForm, read its FUN_00726070() value, and call m_88.v5 with that value's offset 0x18.
// @fnv 0x008c2630
void FUN_008c2630_Owner::FUN_008c2630(TESBoundObject* apForm, int a2)
{
    if (!(apForm->FUN_00401170() == 0x18 || apForm->FUN_00401170() == 0x1a))
    {
        return;
    }
    TESEnchantableForm* r6 = dynamic_cast<TESEnchantableForm*>(apForm);
    FUN_008c2630_Obj* p2 = r6 ? (FUN_008c2630_Obj*)((unsigned int)(reinterpret_cast<::Callees *>((r6))->FUN_00726070())) : 0;
    if (p2)
    {
        m_88.v5(p2 ? (char*)p2 + 0x18 : 0, apForm, 0);
    }
}

namespace fnv_008d5020 {
void* __cdecl operator new(unsigned int);

struct FUN_008d5590_shell_helper
{
    int unk00;
    int unk04;
    int unk08;
    FUN_008d5590_shell_helper();
};

struct FUN_008d5020_class
{
    void FUN_008d5020();
};

// @fnv 0x008d5020
void FUN_008d5020_class::FUN_008d5020()
{
    *reinterpret_cast<void**>(this) = new FUN_008d5590_shell_helper;
}
}  // namespace fnv_008d5020

#include "generated/data/staging/blk_008c0000_od.inc"
