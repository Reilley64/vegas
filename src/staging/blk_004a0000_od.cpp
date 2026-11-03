
// src/staging/blk_004a0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstdint>
#include <windows.h>
#include <new>
#include <cmath>
#include <cstring>
#include <xmmintrin.h>
#include <cstdio>
#include <cstring>
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSMultiBoundSphere.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BipedAnim.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/DecalListManager.h"
#include "fnv/decl/DummyStruct_00631820.h"
#include "fnv/decl/ExtraDataList.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00410020_t.h"
#include "fnv/decl/FUN_00413f90_cls.h"
#include "fnv/decl/FUN_00418600_cls.h"
#include "fnv/decl/FUN_00418720_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_004381b0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00476be0_Class.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_004b0910_cls.h"
#include "fnv/decl/FUN_0057c850_cls.h"
#include "fnv/decl/FUN_00621c90_Class.h"
#include "fnv/decl/FUN_00622570_Class.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/FUN_006b3fd0_cls.h"
#include "fnv/decl/FUN_006b8310_class.h"
#include "fnv/decl/FUN_0084d310_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5be90_shell.h"
#include "fnv/decl/FUN_00c4ed40_cls.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/ObsList.h"
#include "fnv/decl/Ref664.h"
#include "fnv/decl/S_004b0aa0_Self.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/decl/S_00c4edf0_cls.h"
#include "fnv/decl/StandIn.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/_FUN_00822510_Class.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/decl/fnv_0062a100__FUN_0062a100_shell.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0043f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004a4000.h"
#include "fnv/symbols_004a5000.h"
#include "fnv/symbols_004ab000.h"
#include "fnv/symbols_004b0000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_004b6000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005e0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_00c69000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011f9000.h"
#include "../../include/layout_support.h"


// @fnv 0x004a0010
void __cdecl FUN_004a0010()
{
    ::DAT_011c57e4 = 0;
    DAT_011c57e8 = 0;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    static const ::NiPoint3 ZERO;
};

struct FUN_004a0d60_Class
{
    char pad[0x40];
    NiPoint3 m_kPoint;
    NiPoint3& FUN_004a0d60(NiPoint3& arDest);
};

// Copies the stored point into arDest and returns arDest.
// @fnv 0x004a0d60
NiPoint3& FUN_004a0d60_Class::FUN_004a0d60(NiPoint3& arDest)
{
    arDest = m_kPoint;
    return arDest;
}

struct FUN_004a0d90_Class
{
    float GetField11C();
};

// @fnv 0x004a0d90
float FUN_004a0d90_Class::GetField11C()
{
    return *(float*)((char*)this + 0x11c);
}

struct FUN_004a0db0_class
{
    float GetFloatAt120();
};
// @fnv 0x004a0db0
float FUN_004a0db0_class::GetFloatAt120()
{
    return *(float*)((char*)this + 0x120);
}


// Calls FUN_004a3d20 on self, sets the int at offset 0x50 to 0, and returns self.
// @fnv 0x004a3d00
void* FUN_004a3d00(void* self)
{
    FUN_004a3d20(self);
    *(int*)((char*)self + 0x50) = 0;
    return self;
}

struct FUN_004a3d40_class
{
    FUN_004a3d40_class* FUN_004a3d40();
};
struct FUN_004a3d60_class
{
    void FUN_004a3d60();
};
// @fnv 0x004a3d40
FUN_004a3d40_class* FUN_004a3d40_class::FUN_004a3d40()
{
    new ((void *)this) ::Vec3();
    reinterpret_cast<::FUN_004a3d60_class *>(this)->FUN_004a3d60();
    return this;
}

// @fnv 0x004a3d60
void FUN_004a3d60_class::FUN_004a3d60()
{
    *(float*)((char*)this + 0x10) = 1.0f;
    *(int*)((char*)this + 0x14) = -1;
}

struct FUN_004a3d80_Class
{
    void FUN_004a3d80();
};

// @fnv 0x004a3d80
void FUN_004a3d80_Class::FUN_004a3d80()
{
    *(int*)((char*)this + 0x40) = 0;
    *(int*)((char*)this + 0x20) = -1;
}

extern float runtimeInitializationFloat2123;

// @fnv 0x004a3e90
float FUN_004a3e90(float value)
{
    return runtimeInitializationFloat2123 * value;
}

struct RegionPoint
{
};

struct FUN_004a40a0_Class
{
    float FUN_004a40a0();
};

// @fnv 0x004a40a0
float FUN_004a40a0_Class::FUN_004a40a0()
{
    return reinterpret_cast<::CombatTargetTimestamp *>((((RegionPoint*)((char*)this + 0x54))))->FUN_006a7f50();
}

struct Modifier
{
};
struct FUN_004a40c0_Class
{
    float GetModifierValue();
};
// @fnv 0x004a40c0
float FUN_004a40c0_Class::GetModifierValue()
{
    return reinterpret_cast<::TimeoutTimer *>((((Modifier*)((char*)this + 0x54))))->FUN_006b9130();
}

struct FUN_004a4120_class
{
    char FUN_004a4120();
};

// @fnv 0x004a4120
char FUN_004a4120_class::FUN_004a4120()
{
    return (((const unsigned char*)this)[0x1d] & 1) != 0;
}

struct FUN_004a4160_Class
{
    bool FUN_004a4160();
};

// @fnv 0x004a4160
bool FUN_004a4160_Class::FUN_004a4160()
{
    return reinterpret_cast<unsigned char*>(this)[0x1d] & 2;
}

struct FUN_004a41a0_Class
{
    bool FUN_004a41a0();
};
// @fnv 0x004a41a0
bool FUN_004a41a0_Class::FUN_004a41a0()
{
    return ((unsigned char*)this)[0x1d] & 4;
}

struct FUN_004a4200_class
{
    unsigned short FUN_004a4200();
};

// @fnv 0x004a4200
unsigned short FUN_004a4200_class::FUN_004a4200()
{
    return ((unsigned char*)this)[0x1c];
}

struct BSRandomHelper
{
    float FUN_004a4260();
};
struct MersenneTwister
{
    static MersenneTwister* GetRandomGenerator();
};

// @fnv 0x004a4240
float FUN_004a4240()
{
    return reinterpret_cast<BSRandomHelper*>(MersenneTwister::GetRandomGenerator())->FUN_004a4260();
}

struct FUN_004a4440_Class
{
    void FUN_004a46d0();
    void FUN_004a4440();
};

struct BSAudio
{
};
extern "C" BSAudio* __cdecl FUN_00c85750();
struct FUN_004a4840_class
{
    void FUN_004a4840(intptr_t unused);
};
// @fnv 0x004a4840
void FUN_004a4840_class::FUN_004a4840(intptr_t unused)
{
    reinterpret_cast<::MagicCaster_shell *>((FUN_00c85750()))->FUN_0044edb0();
}

struct FUN_004a49e0_shell
{
    void FUN_004a49e0(void* item);
};

// Clears the int at offset 8 of item, then calls Deallocate on the object at this+8 to free it.
// @fnv 0x004a49e0
void FUN_004a49e0_shell::FUN_004a49e0(void* item)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(item) + 8) = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>((reinterpret_cast<FUN_004a49e0_shell*>(reinterpret_cast<char*>(this) + 8)))->FUN_0045cee0(item);
}

struct FUN_004a5250_shell
{
    void* AssignFromBound(void*);
};
struct FUN_004a5230_class
{
    void ForwardToMember(void* arg);
};
// @fnv 0x004a5230
void FUN_004a5230_class::ForwardToMember(void* arg)
{
    ((FUN_004a5250_shell*)((char*)this + 0x10))->AssignFromBound(arg);
}

struct Flt
{
    operator unsigned int();
};
struct TESActorBaseData
{
    unsigned short GetFatigue() const;
};
struct FUN_004a8ab0_shell
{
    unsigned short GetActorBaseFatigue();
};
// Reads a float at offset 0xb8, converts it to an unsigned int, and returns GetFatigue() from the TESActorBaseData at that address.
// @fnv 0x004a8ab0
unsigned short FUN_004a8ab0_shell::GetActorBaseFatigue()
{
    unsigned int u = ((Flt*)((char*)this + 0xb8))->operator unsigned int();
    return ((TESActorBaseData*)(uintptr_t)u)->GetFatigue();
}

struct FUN_004a9950_Class
{
    void SetValue(intptr_t a, int b, char c);
};
// @fnv 0x004a9950
void FUN_004a9950_Class::SetValue(intptr_t a, int iValue, char c)
{
    *(int*)((char*)a + 4) = iValue;
    *(char*)((char*)a + 8) = c;
}

extern int DAT_0101ed6c;
struct FUN_004a9bf0_class
{
    void* FUN_004a9bf0(int);
};

struct FUN_004a9d80_class
{
    void* vtable;
    FUN_004a9d80_class* FUN_004a9d80();
};

namespace fnv_004a9de0 {
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_004a9de0_class
{
    int* p;
    void FUN_004a9de0();
};
// @fnv 0x004a9de0
void FUN_004a9de0_class::FUN_004a9de0()
{
    p = (int*)&(*reinterpret_cast<int *>(&::DAT_0101edac));
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((GlobalObject_00869f00*)this)))->Clear(true);
}
}  // namespace fnv_004a9de0

extern int DAT_0101edc0;
struct FUN_004a9e90_cls
{
    void* m_p;
    FUN_004a9e90_cls* FUN_004a9e90(int a);
};
extern int DAT_0101ee00;
struct FUN_004aa020_class
{
    int* m_p;
    FUN_004aa020_class* FUN_004aa020(int a);
};
extern int DAT_0101ee40;
void __cdecl FUN_004aa210(int);

struct FUN_004aa1b0_class
{
    void FUN_004aa210(int);
    int* p;
    FUN_004aa1b0_class* FUN_004aa1b0(int a);
};

// Calls FUN_004aa210 with a, sets p to point at DAT_0101ee40, and returns this.
// @fnv 0x004aa1b0
FUN_004aa1b0_class* FUN_004aa1b0_class::FUN_004aa1b0(int a)
{
    FUN_004aa210(a);
    p = &DAT_0101ee40;
    return this;
}

extern int DAT_0101fb8c;
struct FUN_004afb20_class
{
    int* m_p;
    FUN_004afb20_class* FUN_004afb20(int a);
};
extern int DAT_0101fbac;

struct FUN_004afb50_class
{
    int* p;
    FUN_004afb50_class* InitializeWithGlobal(int a);
};

struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};
struct FUN_004afb80_shell
{
    void LockAtOffset();
};
// @fnv 0x004afb80
void FUN_004afb80_shell::LockAtOffset()
{
    reinterpret_cast<::FUN_0040fbf0_shell *>((((RecursiveSpinLock*)((char*)this + 0x20))))->FUN_0040fbf0((char *)(0));
}

namespace fnv_004afba0 {
struct RecursiveSpinLock
{
};

struct FUN_004afba0_class
{
    void UnlockAtOffset();
};

// @fnv 0x004afba0
void FUN_004afba0_class::UnlockAtOffset()
{
    reinterpret_cast<::RecursiveSpinLock *>((((RecursiveSpinLock*)((char*)this + 0x20))))->FUN_0040fba0();
}
}  // namespace fnv_004afba0

void __cdecl FUN_004b0220(intptr_t);
struct FUN_004afc20
{
    void* vtbl;
    int data;
    void Init();
};
// Sets the object's vtbl to DAT_0101fbcc and calls FUN_004b0220 with data.
// @fnv 0x004afc20
void FUN_004afc20::Init()
{
    vtbl = &(*reinterpret_cast<void * *>(&::DAT_0101fbcc));
    FUN_004b0220(data);
}

struct FUN_004b0130_shell
{
    unsigned int vfn_00;
    unsigned int vfn_04;
    unsigned int vfn_08;
    unsigned int vfn_0c;
    unsigned int vfn_10;
    void ClearAndDeallocate(void* p);
};
// Clears the byte at offset 8 of p, then calls Deallocate on the object at this+0xc with p.
// @fnv 0x004b0130
void FUN_004b0130_shell::ClearAndDeallocate(void* p)
{
    *(char*)((char*)p + 8) = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>((((FUN_004b0130_shell*)((char*)this + 0xc))))->FUN_0045cee0(p);
}

struct FUN_004b0460_class
{
    void* m_p;
    bool FUN_004b0460(const void** other);
};

// @fnv 0x004b0460
bool FUN_004b0460_class::FUN_004b0460(const void** other)
{
    return m_p == *other;
}

extern int DAT_0101fc80;

struct FUN_004b0530_Class
{
    void FUN_004b0530();
};

// @fnv 0x004b0530
void FUN_004b0530_Class::FUN_004b0530()
{
    *(void**)this = &DAT_0101fc80;
}

struct FUN_004b1030_Class
{
    unsigned short FUN_004b1030();
};

// @fnv 0x004b1030
unsigned short FUN_004b1030_Class::FUN_004b1030()
{
    return *(unsigned short*)this;
}

extern "C" const short DAT_01188ecc[];

// @fnv 0x004b10d0
short __cdecl GetShortFromTable(int index)
{
    if (index >= 0xc)
        return 0;
    return DAT_01188ecc[index];
}


// @fnv 0x004b1500
float __cdecl FUN_004b1500(float a, float b)
{
    return FUN_004b1520(a, b);
}


// @fnv 0x004b4a10
int __cdecl FUN_004b4a10(unsigned short a1, int a2, intptr_t a3, int a4)
{
    return (*reinterpret_cast<int(__cdecl**)(unsigned short, int, int, int)>(&::DAT_011aa050))(a1, a2, a3, a4);
}

struct FUN_004b4cf0_shell;
struct FUN_004b4ab0_Class
{
    void FUN_004b4ab0(FUN_004b4cf0_shell* a, __m128* b);
    void FUN_004b4ad0(FUN_004b4cf0_shell* matrix, __m128* vector);
};

// @fnv 0x004b4ab0
void FUN_004b4ab0_Class::FUN_004b4ab0(FUN_004b4cf0_shell* a, __m128* b)
{
    FUN_004b4ad0(a, b);
}

// Returns the atan2 of a and b, computed in double precision and cast back to float.
// @fnv 0x004b5590
float FUN_004b5590(float afY, float afX)
{
    return (float)atan2((double)afY, (double)afX);
}

struct TESSound
{
};

// If p is non-null, calls p->Deallocate() and returns its result; otherwise returns 0.
// @fnv 0x004b5aa0
unsigned int DeallocateIfPresent(TESSound* apSound)
{
    unsigned int result;
    if (apSound)
    {
        result = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apSound))->FUN_0084e3a0()));
    }
    else
    {
        result = 0;
    }
    return result;
}

extern int DAT_010205b4;
struct FUN_004b9950_class
{
    int* p;
    FUN_004b9950_class* FUN_004b9950(int arg);
};
struct FUN_004b9de0_class
{
    void FUN_004b9de0();
};

struct FUN_004b9d60_class
{
    void FUN_004b9d60();
};

struct Unk65
{
    void FUN_0065de30(const void*);
};
struct Unk6b
{
};

struct FUN_004b9d80_Class
{
    void FUN_004b9d80(void* param);
};

// Calls FUN_0065de30(0) on the object at param+8, then FreeMemory(param) on the object at this+0xc.
// @fnv 0x004b9d80
void FUN_004b9d80_Class::FUN_004b9d80(void* pObject)
{
    ((Unk65*)((char*)pObject + 8))->FUN_0065de30(0);
    reinterpret_cast<::FUN_006b8310_class *>((((Unk6b*)((char*)this + 0xc))))->FreeMemory(pObject);
}


struct FUN_004b9de0
{
    void* Alloc();
};
// @fnv 0x004b9d60
void FUN_004b9d60_class::FUN_004b9d60()
{
    reinterpret_cast<::FUN_004b9de0 *>((((FUN_004b9de0_class*)((char*)this + 0xc))))->Alloc();
}

// @fnv 0x004b9de0
void* FUN_004b9de0::Alloc()
{
    void* p = ::FUN_00401000(0x14);
    return p;
}

extern "C" void* DAT_01020634;

struct FUN_004b9e00_cls
{
    void* m_vftable;
    void* FUN_004b9e00();
};

// @fnv 0x004b9e00
void* FUN_004b9e00_cls::FUN_004b9e00()
{
    m_vftable = &DAT_01020634;
    return this;
}


struct FUN_004be080_Class
{
    float FUN_004be080();
};

// Returns the unsigned short at offset 0x178 divided by g_d100, cast to float.
// @fnv 0x004be080
float FUN_004be080_Class::FUN_004be080()
{
    return (float)((double)*(unsigned short*)((char*)this + 0x178) / g_d100);
}

struct FUN_004be580_class
{
    unsigned char GetByteAt240();
};

// @fnv 0x004be580
unsigned char FUN_004be580_class::GetByteAt240()
{
    return ((unsigned char*)this)[0x240];
}

extern void* DAT_0101ed2c;

struct FUN_004a98b0_Class
{
    void* m_vtbl;
    int m_auiShapeKeys;
    void* m_p;
    void FUN_004a98b0();
};

// Resets the vtable pointer, clears the pointer map contents, and frees m_p.
// @fnv 0x004a98b0
void FUN_004a98b0_Class::FUN_004a98b0()
{
    m_vtbl = &DAT_0101ed2c;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(m_p);
}

extern int DAT_0101ed8c;

struct FUN_004a9d20_Class
{
    void FUN_004a9d20();
};

// Resets the vtable pointer, clears the pointer map, and frees the pointer stored at offset 8.
// @fnv 0x004a9d20
void FUN_004a9d20_Class::FUN_004a9d20()
{
    *(void**)this = &DAT_0101ed8c;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)((char*)this + 8));
}

namespace fnv_004aa150 {

struct FUN_004aa150_class
{
    void* vtable;
    void* m_iWordAt04;
    void* m_8;
    void FUN_004aa150();
};

// @fnv 0x004aa150
void FUN_004aa150_class::FUN_004aa150()
{
    *reinterpret_cast<void**>(this) = &::DAT_0101ee20;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(m_8);
}
}  // namespace fnv_004aa150

extern int DAT_0101ee60;
struct FUN_004aa2e0_Class
{
    void FUN_004aa2e0();
};
// Sets the vtable pointer, clears the pointer map, and frees the pointer stored at offset 8.
// @fnv 0x004aa2e0
void FUN_004aa2e0_Class::FUN_004aa2e0()
{
    *reinterpret_cast<int**>(this) = &DAT_0101ee60;
    reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<NiTPointerMap<int, int>*>(this)))->FUN_00438af0();
    ::FUN_00aa10f0(reinterpret_cast<void**>(this)[2]);
}

extern int DAT_0101fbdc;
struct FUN_004b0000_class
{
    void* vtable;
    char pad[4];
    void* m_ptr;
    void FUN_004b0000();
};
// Sets the vtable, clears the pointer map contents, and frees m_ptr.
// @fnv 0x004b0000
void FUN_004b0000_class::FUN_004b0000()
{
    vtable = (void*)&DAT_0101fbdc;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<int, int>*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(m_ptr);
}

namespace fnv_004b0100 {
struct FUN_004b0100_Class
{
    void* vtbl;
    void* p;
    void* q;
    void FUN_004b0100();
};
// Sets the vtable pointer, calls RemoveAll, then frees the q pointer via NiFreeAlias.
// @fnv 0x004b0100
void FUN_004b0100_Class::FUN_004b0100()
{
    vtbl = &(*reinterpret_cast<void * *>(&::DAT_0101fbfc));
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(q);
}
}  // namespace fnv_004b0100

extern int DAT_010205d4;

struct FUN_004b9d30 : NiTPointerMap<int, int>
{
    void Init();
};

// Sets the vtable pointer, clears all entries with RemoveAll, then frees the pointer stored at offset 8 via _NiFreeAlias.
// @fnv 0x004b9d30
void FUN_004b9d30::Init()
{
    *(int**)((char*)this + 0) = &DAT_010205d4;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0(*(void**)&this->m_ppkHashTable);
}

struct FUN_004a4410_Class
{
    void* FUN_004a4410(unsigned int flags);
};
// @fnv 0x004a4410
void* FUN_004a4410_Class::FUN_004a4410(unsigned int flags)
{
    reinterpret_cast<::FUN_00c4ed40_cls *>((this))->FUN_00c4ed40();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004a4bd0_shell
{
    void FUN_004a4bd0();
    void* FUN_004a4ba0(unsigned int flags);
};
struct FUN_004a99d0_Class
{
    void* FUN_004a9a30(unsigned int flags);
};
namespace fnv_004a9c20 {
struct GlobalObject_004a9bf0
{
    void dtor();
    GlobalObject_004a9bf0* FUN_004a9c20(unsigned int flags);
};
// Calls the object's destructor, frees the object with Deallocate when bit 0 of flags is set, and returns the object pointer.
// @fnv 0x004a9c20
GlobalObject_004a9bf0* GlobalObject_004a9bf0::FUN_004a9c20(unsigned int flags)
{
    this->dtor();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_004a9c20

void __cdecl FUN_004a9fc0();
struct FUN_004a9ff0_Class
{
    void FUN_004a9fc0();
    void* FUN_004a9ff0(unsigned int flags);
};
struct FUN_004aa150_Class
{
    void* FUN_004aa180(unsigned int flags);
};

// Calls FUN_004aa150, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x004aa180
void* FUN_004aa150_Class::FUN_004aa180(unsigned int flags)
{
    reinterpret_cast<::fnv_004aa150::FUN_004aa150_class *>(this)->FUN_004aa150();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_004aa310_Class : FUN_004aa2e0_Class
{
    FUN_004aa310_Class* FUN_004aa310(unsigned int flags);
};
// @fnv 0x004aa310
FUN_004aa310_Class* FUN_004aa310_Class::FUN_004aa310(unsigned int flags)
{
    FUN_004aa2e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void __cdecl FUN_004affa0();
struct FUN_004afbc0_Class
{
    void* FUN_004afbc0(unsigned int flags);
};
// Calls FUN_004affa0 on this, frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004afbc0
void* FUN_004afbc0_Class::FUN_004afbc0(unsigned int flags)
{
    ((void(*)(void*))FUN_004affa0)(this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void FUN_004afc20(void*);
struct FUN_004b0160_class
{
    void FUN_004afc20();
    void* FUN_004b0160(unsigned int flags);
};
// Calls FUN_004afc20, then deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004b0160
void* FUN_004b0160_class::FUN_004b0160(unsigned int flags)
{
    reinterpret_cast<struct ::FUN_004afc20 *>(this)->Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_004b01f0_Class
{
    void* FUN_004b01f0(unsigned int flags);
};

// Calls FUN_004b0100, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004b01f0
void* FUN_004b01f0_Class::FUN_004b01f0(unsigned int flags)
{
    reinterpret_cast<::fnv_004b0100::FUN_004b0100_Class *>(this)->FUN_004b0100();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004b0850_Class
{
    FUN_004b0850_Class* FUN_004b0850(unsigned int flags);
};
struct FUN_004b08e0_Class
{
    void FUN_004b0cf0();
    void* FUN_004b08e0(unsigned int flags);
};
struct NiFixedString
{
    ~NiFixedString();
    void* FUN_004b9900(unsigned int flags);
};
// Destroys the NiFixedString and, if the flags bit 0 is set, frees the object's memory, returning this.
// @fnv 0x004b9900
void* NiFixedString::FUN_004b9900(unsigned int flags)
{
    reinterpret_cast<::FUN_004381b0_shell *>(this)->FUN_004381b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004b9980_Class
{
    void FUN_004b9cd0();
    void* FUN_004b9980(unsigned int flags);
};

struct FUN_004a0e50_Class
{
    bool FUN_004a0e50();
};
// Returns true when the int at offset 0x200 of this object equals 1 or 2.
// @fnv 0x004a0e50
bool FUN_004a0e50_Class::FUN_004a0e50()
{
    return *(int*)((char*)this + 0x200) == 1 || *(int*)((char*)this + 0x200) == 2;
}

struct NiRenderer;

// @fnv 0x004a0e90
unsigned int FUN_004a0e90()
{
    return *(Flt*)&::DAT_011f9508;
}

struct CalleeObj
{
    int _m;
};
struct Sub6815
{
    char pad[0x10];
};
struct FUN_004a3cc0_Class
{
    Sub6815 a;
    Sub6815 b;
    CalleeObj c;
    int d;
    FUN_004a3cc0_Class* FUN_004a3cc0();
};
// @fnv 0x004a3cc0
FUN_004a3cc0_Class* FUN_004a3cc0_Class::FUN_004a3cc0()
{
    new ((void *)&(a)) ::Vec3();
    new ((void *)&(b)) ::Vec3();
    reinterpret_cast<::FUN_00622570_Class *>(&(c))->FUN_00622570(false);
    d = 0;
    return this;
}

struct UnsignedIntHelper
{
};
// @fnv 0x004a4260
float BSRandomHelper::FUN_004a4260()
{
    unsigned int val = reinterpret_cast<::FUN_00476be0_Class *>((((UnsignedIntHelper*)this)))->FUN_00476be0();
    return (float)((double)val * DAT_0101e5a0);
}

struct ObstacleData;
template <class T> struct NiPointer;
struct FUN_004a4650_ListBase
{
    NiTListItem<NiPointer<ObstacleData> >* m_pItemHead;
    NiTListItem<NiPointer<ObstacleData> >* m_pItemPrev;
    NiTListItem<NiPointer<ObstacleData> >* m_pItemTail;
    void DeleteItem(NiTListItem<NiPointer<ObstacleData> >* item);
};
// Iterates the linked list from m_pItemHead, deleting each item via DeleteItem, then clears the head, prev and tail pointers.
// @fnv 0x004a4650
void FUN_004a4650(FUN_004a4650_ListBase* self)
{
    NiTListItem<NiPointer<ObstacleData> >* item = self->m_pItemHead;
    while (item)
    {
        NiTListItem<NiPointer<ObstacleData> >* next = item;
        item = item->m_pkNext;
        self->DeleteItem(next);
    }
    self->m_pItemTail = 0;
    self->m_pItemHead = 0;
    self->m_pItemPrev = 0;
}

struct GO
{
    void operator=(void*);
};
struct FUN_004a4930_class
{
    char _pad[8];
    FUN_004a49e0_shell _m;
    void FUN_004a4930(void*);
};
// Clears the object at p+8 via assignment of 0, then calls _m.Deallocate(p).
// @fnv 0x004a4930
void FUN_004a4930_class::FUN_004a4930(void* apObject)
{
    ((GO*)((char*)apObject + 8))->operator=(0);
    reinterpret_cast<::FUN_0045cee0_shell *>(&(_m))->FUN_0045cee0(apObject);
}

struct FUN_004a4960_class
{
    void* FUN_004a4960(void* a, void* b, unsigned int c);
};
// Stores a, b and c (with the high bit set) into the object's first three fields and returns this.
// @fnv 0x004a4960
void* FUN_004a4960_class::FUN_004a4960(void* pFirst, void* pSecond, unsigned int c)
{
    *(void**)((char*)this) = pFirst;
    *(void**)((char*)this + 4) = pSecond;
    *(unsigned int*)((char*)this + 8) = c | 0x80000000;
    return this;
}

struct H_A100
{
};
struct H_004a4a10
{
};
struct FUN_004a4990_s
{
    void* p;
    int a;
    int b;
    void FUN_004a4990(intptr_t arg);
};
struct FUN_004a4a10_Holder
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vf10(int, int);
    void FUN_004a4a10(intptr_t, intptr_t);
};
// @fnv 0x004a4990
void FUN_004a4990_s::FUN_004a4990(intptr_t pTarget)
{
    reinterpret_cast<::FUN_00621c90_Class *>(this)->FUN_00626870();
    if (!(b & 0x80000000))
        reinterpret_cast<::FUN_004a4a10_Holder *>((((H_004a4a10*)pTarget)))->FUN_004a4a10((intptr_t)(p), (intptr_t)(reinterpret_cast<::fnv_0062a100::FUN_0062a100_shell *>((((H_A100*)this)))->GetSizeMasked()));
    p = 0;
    b = 0x80000000;
}
// Calls vf10 with a1 and a2 multiplied by 0x60.
// @fnv 0x004a4a10
void FUN_004a4a10_Holder::FUN_004a4a10(intptr_t aiArg1, intptr_t aiArg2)
{
    int v = 0x60;
    vf10(aiArg1, aiArg2 * 0x60);
}

namespace fnv_004a4c50 {
struct GO
{
    void operator=(void*);
};
struct FUN_004a4c50_Class
{
    char pad[0x24];
    GO m0;
    GO m1;
    GO m2;
    void ClearSlots();
};
// Sets the three pointer slots at offsets 0x24, 0x28 and 0x2c of this object to null.
// @fnv 0x004a4c50
void FUN_004a4c50_Class::ClearSlots()
{
    this->m0.operator=(0);
    ((GO*)((char*)this + 0x28))->operator=(0);
    ((GO*)((char*)this + 0x2c))->operator=(0);
}
}  // namespace fnv_004a4c50

struct BGSBodyPart
{
};
struct Mid
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
    virtual unsigned int v14();
};
// @fnv 0x004a8b00
unsigned int FUN_004a8b00(BGSBodyPart* apObject)
{
    const char* pc = ((const char *)(reinterpret_cast<::fnv_006838b0::FUN_006838b0_shell *>((apObject))->FUN_006838b0()));
    return pc ? ((Mid*)pc)->v14() : 0;
}

struct FUN_004a97e0_Class
{
    void* m_vtbl;
    unsigned int m_uiItemCount;
    void* m_p;
    unsigned int m_auiShapeKeys;
    void* FUN_004a97e0(unsigned int a);
};
// Sets the vtable, stores a count, allocates count*4 bytes, zeroes them and stores the pointer in m_p.
// @fnv 0x004a97e0
void* FUN_004a97e0_Class::FUN_004a97e0(unsigned int a)
{
    m_vtbl = &DAT_0101ed2c;
    m_uiItemCount = a;
    m_auiShapeKeys = 0;
    unsigned int size = m_uiItemCount * 4;
    m_p = ::FUN_00aa1070(size);
    ::FUN_00403d30(m_p, 0, m_uiItemCount * 4);
    return this;
}

extern int DAT_0101ed4c;
struct FUN_004a98e0_class
{
    void* FUN_004a98e0(int count);
};
// @fnv 0x004a98e0
void* FUN_004a98e0_class::FUN_004a98e0(int count)
{
    *(void**)this = &DAT_0101ed4c;
    *(int*)((char*)this + 4) = count;
    *(int*)((char*)this + 12) = 0;
    unsigned int size = *(int*)((char*)this + 4) * 4;
    *(void**)((char*)this + 8) = ::FUN_00aa1070(size);
    ::FUN_00403d30(*(void**)((char*)this + 8), 0, *(int*)((char*)this + 4) * 4);
    return this;
}

struct FUN_004a9a00_Class
{
    void* FUN_004a9a00(unsigned int);
};
// Calls FUN_004a98b0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x004a9a00
void* FUN_004a9a00_Class::FUN_004a9a00(unsigned int flags)
{
    ((FUN_004a98b0_Class*)this)->FUN_004a98b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004a9c50_class
{
    void* vtbl;
    unsigned int count;
    void* data;
    unsigned int extra;
    FUN_004a9c50_class* FUN_004a9c50(unsigned int a);
};
// Calls FUN_004a9c50 with a, stores the address of DAT_0101ed6c at this, and returns this.
// @fnv 0x004a9bf0
void* FUN_004a9bf0_class::FUN_004a9bf0(int a)
{
    reinterpret_cast<::FUN_004a9c50_class *>(this)->FUN_004a9c50(a);
    *reinterpret_cast<void**>(this) = &DAT_0101ed6c;
    return this;
}
// Sets the vtable, stores the count, allocates count*4 bytes for data, zeroes it, and returns this.
// @fnv 0x004a9c50
FUN_004a9c50_class* FUN_004a9c50_class::FUN_004a9c50(unsigned int a)
{
    vtbl = (void*)&DAT_0101ed8c;
    count = a;
    extra = 0;
    unsigned int size = count << 2;
    data = ::FUN_00aa1070(size);
    ::FUN_00403d30(data, 0, count << 2);
    return this;
}

struct FUN_004a9d50_Self
{
    void* FUN_004a9d50(unsigned int);
};
// @fnv 0x004a9d50
void* FUN_004a9d50_Self::FUN_004a9d50(unsigned int flags)
{
    ((FUN_004a9d20_Class*)this)->FUN_004a9d20();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct GlobalObject_004a9d80
{
    ~GlobalObject_004a9d80();
    void* FUN_004a9db0(unsigned int);
};
// Runs the destructor and, when bit 0 of flags is set, frees the object with operator delete; returns the object pointer.
// @fnv 0x004a9db0
void* GlobalObject_004a9d80::FUN_004a9db0(unsigned int flags)
{
    reinterpret_cast<::fnv_004a9de0::FUN_004a9de0_class *>((((GlobalObject_004a9d80*)this)))->FUN_004a9de0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00519c50_class
{
};
struct FUN_004a9fc0_Class
{
    void* _00;
    int _04;
    void* _08;
    void FUN_004a9fc0();
};
// Calls FUN_004a9fc0, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004a9ff0
void* FUN_004a9ff0_Class::FUN_004a9ff0(unsigned int flags)
{
    reinterpret_cast<::FUN_004a9fc0_Class *>(this)->FUN_004a9fc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
extern int DAT_0101ede0;
// @fnv 0x004a9fc0
void FUN_004a9fc0_Class::FUN_004a9fc0()
{
    *(void**)this = (void*)&DAT_0101ede0;
    reinterpret_cast<::FUN_00438af0_Class *>((((FUN_00519c50_class*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(_08);
}

namespace fnv_004aa210 {
struct FUN_004aa210_class
{
    int* vtbl;
    int count;
    void* data;
    int pad;
    FUN_004aa210_class* FUN_004aa210(int n);
};
// Sets the vtable, stores n as count, allocates count*4 bytes with NiMalloc, zeroes them with memset, and returns this.
// @fnv 0x004aa210
FUN_004aa210_class* FUN_004aa210_class::FUN_004aa210(int aiCount)
{
    vtbl = &DAT_0101ee60;
    count = aiCount;
    pad = 0;
    unsigned int size = count * 4;
    data = ::FUN_00aa1070(size);
    memset(data, 0, count * 4);
    return this;
}
}  // namespace fnv_004aa210

struct FUN_004afbf0_class
{
    void* FUN_004afbf0(unsigned int);
};
struct FUN_004b0030_Class
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_004b0030_Class* FUN_004b0030(int n);
};
// Calls FUN_004b0030 with the argument, sets p to point at DAT_0101fbac, and returns this.
// @fnv 0x004afb50
FUN_004afb50_class* FUN_004afb50_class::InitializeWithGlobal(int a)
{
    reinterpret_cast<::FUN_004b0030_Class *>((this))->FUN_004b0030(a);
    p = &DAT_0101fbac;
    return this;
}

// Sets the vtable, stores n as count, allocates count*4 zeroed bytes into data and returns this.
// @fnv 0x004b0030
FUN_004b0030_Class* FUN_004b0030_Class::FUN_004b0030(int aiCount)
{
    vtbl = &DAT_0101fbfc;
    count = aiCount;
    pad = 0;
    unsigned int size = count * 4;
    data = ::FUN_00aa1070(size);
    ::FUN_00403d30(data, 0, count * 4);
    return this;
}

struct StandIn004b01c0
{
    void* FUN_004b01c0(unsigned int);
};
// @fnv 0x004b01c0
void* StandIn004b01c0::FUN_004b01c0(unsigned int flags)
{
    ((FUN_004b0000_class*)this)->FUN_004b0000();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct S004b0220
{
};
// If param_1 is non-null, calls FUN_00667120 with 3 on it.
// @fnv 0x004b0220
void __cdecl FUN_004b0220(intptr_t pObject)
{
    S004b0220* q;
    S004b0220* p;
    q = (S004b0220*)pObject;
    p = q;
    p ? reinterpret_cast<::Ref664 *>((p))->FUN_00667120(3) : 0;
}

extern int DAT_0101fc8c;
template <> struct NiTMallocInterface<void*>
{
};
struct FUN_004b07b0_Struct
{
    void* vtbl;
    void** ptr;
    void FUN_004b07b0();
};
// Calls FUN_004b07b0, then frees this when flags has bit 0 set, and returns this.
// @fnv 0x004b0850
FUN_004b0850_Class* FUN_004b0850_Class::FUN_004b0850(unsigned int flags)
{
    reinterpret_cast<::FUN_004b07b0_Struct *>(this)->FUN_004b07b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Sets the object's vtbl to DAT_0101fc8c and deallocates the pointer member through NiTMallocInterface<void*>::Deallocate.
// @fnv 0x004b07b0
void FUN_004b07b0_Struct::FUN_004b07b0()
{
    vtbl = (void*)&DAT_0101fc8c;
    ::FUN_004ede70(ptr);
}

struct FUN_004b0da0_Class
{
    void* a;
    void* b;
    int c;
    void FUN_004b0eb0();
    FUN_004b0da0_Class* FUN_004b0da0(void* a, void* b);
};
// Stores the two given pointers into the object, resets the counter to zero, calls FUN_004b0eb0, and returns this.
// @fnv 0x004b0da0
FUN_004b0da0_Class* FUN_004b0da0_Class::FUN_004b0da0(void* pFirst, void* pSecond)
{
    this->a = pFirst;
    this->b = pSecond;
    this->c = 0;
    FUN_004b0eb0();
    return this;
}

struct Ret_004b0de0
{
};
struct Holder_004b0de0
{
    int m0;
    int m1;
    void FUN_004b0de0();
};
// If both m0 and m1 are non-zero, calls ProcessKeyedEntry on the object returned by GetOrCreateInstance(1) with m0 and m1.
// @fnv 0x004b0de0
void Holder_004b0de0::FUN_004b0de0()
{
    if (m0 && m1)
        reinterpret_cast<::S_004b0aa0_Self *>((((::Ret_004b0de0 *)(::GetOrCreateInstance(1)))))->ProcessKeyedEntry(m0, m1);
}

struct FUN_004b0880
{
    FUN_004b0880();
    ~FUN_004b0880();
    int a;
    int b;
};
extern FUN_004b0880* DAT_011c5f40;

// Returns the global instance, allocating a new one first if it is null and create is true.
// @fnv 0x004b0e20
FUN_004b0880* GetOrCreateInstance(bool create)
{
    if (!DAT_011c5f40 && create)
        DAT_011c5f40 = new FUN_004b0880;
    return DAT_011c5f40;
}

namespace fnv_004b0eb0 {
struct FUN_004b0910_This
{
};
struct FUN_004b0eb0_class
{
    void* f0;
    unsigned int f4;
    void FUN_004b0eb0();
};
// If both f0 and f4 are set, obtains an object via GetOrCreateInstance(1) and calls AddKeyedItems with f0 and f4.
// @fnv 0x004b0eb0
void FUN_004b0eb0_class::FUN_004b0eb0()
{
    if (f0 && f4)
        reinterpret_cast<::FUN_004b0910_cls *>((((FUN_004b0910_This*)((::GetOrCreateInstance(1))))))->AddKeyedItems((::Key4b0910 *)(f0), f4);
}
}  // namespace fnv_004b0eb0

struct FUN_004b0de0_Holder
{
};
struct FUN_004b0f40_Holder
{
    void* vtbl;
    void* FUN_004b0f40(unsigned int flags);
};
// Calls FUN_004b0de0 on this, frees this when flags has bit 0 set, and returns this.
// @fnv 0x004b0f40
void* FUN_004b0f40_Holder::FUN_004b0f40(unsigned int flags)
{
    reinterpret_cast<::Holder_004b0de0 *>((((FUN_004b0de0_Holder*)this)))->FUN_004b0de0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Helper62d0
{
    void* operator=(void const*);
    void AssignNodePointer(const NiPointer<NiNode>&);
};
// If other is non-null, assigns it to this object via operator=; otherwise returns without change.
// @fnv 0x004b0f70
void Helper62d0::AssignNodePointer(const NiPointer<NiNode>& other)
{
    if (reinterpret_cast<::_FUN_00822510_Class *>((void *)&(const ::NiPointer< ::NiNode> &)(other))->operator==((int)(0)))
        return;
    operator=(reinterpret_cast<void const*>(&other));
}

unsigned short __cdecl FUN_004b10f0(unsigned short, unsigned short);
struct FUN_004b0fc0_Struct
{
    unsigned short m0;
    unsigned short m1;
    FUN_004b0fc0_Struct* FUN_004b0fc0(unsigned short a, unsigned short b, unsigned short c);
};
// Sets m0 to the result of FUN_004b10f0(a, b) and m1 to c, then returns this.
// @fnv 0x004b0fc0
FUN_004b0fc0_Struct* FUN_004b0fc0_Struct::FUN_004b0fc0(unsigned short ausValue, unsigned short ausValue2,
                                                                  unsigned short c)
{
    m0 = FUN_004b10f0(ausValue, ausValue2);
    m1 = c;
    return this;
}

// @fnv 0x004b12d0
int __cdecl FUN_004b12d0(char* pcString)
{
    char bDotSeen = 0;
    char c = *pcString;
    pcString++;
    if (c)
    {
        if ((c >= '0' && c <= '9') || c == '-' || c == '.')
        {
            if (pcString[0] == 0 && (c == '-' || c == '.'))
                return 0;
            if (c == '.')
                bDotSeen = 1;
            c = pcString[0];
            pcString++;
            while (c)
            {
                if ((c < '0' || c > '9') && (c != '.' || bDotSeen))
                    return 0;
                if (c == '.')
                    bDotSeen = 1;
                c = pcString[0];
                pcString++;
            }
            return 1;
        }
    }
    return 0;
}

struct ThreeByThreeMatrix
{
    float m[9];
    bool Inverse(ThreeByThreeMatrix&);
    ThreeByThreeMatrix* FUN_004b45b0(ThreeByThreeMatrix*);
};
struct M3_
{
    void FUN_004b4660(unsigned int, float, float, float);
};
struct FUN_004b4600_Class
{
    void FUN_004b4600();
};
// @fnv 0x004b45b0
ThreeByThreeMatrix* ThreeByThreeMatrix::FUN_004b45b0(ThreeByThreeMatrix* apDest)
{
    ThreeByThreeMatrix tmp;
    new ((void *)&(tmp)) ::Vec3();
    if (!Inverse(tmp))
        reinterpret_cast<::FUN_004b4600_Class *>(&(tmp))->FUN_004b4600();
    *apDest = tmp;
    return apDest;
}
// @fnv 0x004b4600
void FUN_004b4600_Class::FUN_004b4600()
{
    ((M3_*)this)->FUN_004b4660(0, 0.0f, 0.0f, 0.0f);
    ((M3_*)this)->FUN_004b4660(1, 0.0f, 0.0f, 0.0f);
    ((M3_*)this)->FUN_004b4660(2, 0.0f, 0.0f, 0.0f);
}

extern const char* DAT_01188f84[];
// @fnv 0x004b7650
const char* __cdecl FUN_004b7650(int a1)
{
    return DAT_01188f84[a1];
}

struct Inner12
{
    int a;
    int b;
    int c;
};
struct Outer8
{
    int pad;
    int v;
    Inner12 inner;
};
struct Holder004b9ca0
{
    void SetOuterValues(Outer8* p, int b, Inner12 v);
};
// Stores b into p->v and copies the Inner12 value v into p->inner.
// @fnv 0x004b9ca0
void Holder004b9ca0::SetOuterValues(Outer8* pOuter, int iValue, Inner12 innerValue)
{
    pOuter->v = iValue;
    pOuter->inner = innerValue;
}

struct Holder_004b9db0
{
    void* FUN_004b9db0(unsigned int flags);
};
// Initializes the object via Init, then deallocates it if the flags bit 0 is set, and returns the object pointer.
// @fnv 0x004b9db0
void* Holder_004b9db0::FUN_004b9db0(unsigned int flags)
{
    ((FUN_004b9d30*)this)->Init();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00418630_Class
{
    void* FUN_00418630();
};
struct FUN_00418600_Class
{
};
struct FUN_004bcbd0_Node
{
};
struct FUN_004bcbd0_Class
{
    FUN_004bcbd0_Node* m_pFirstNode;
    void ProcessNodes();
};
// @fnv 0x004bcbd0
void FUN_004bcbd0_Class::ProcessNodes()
{
    FUN_004bcbd0_Node* node = m_pFirstNode;
    while (node && *((int *)(new ((void *)(node)) ::Vec3())))
    {
        FUN_004bcbd0_Node* item = *((FUN_004bcbd0_Node **)(new ((void *)(node)) ::Vec3()));
        if (item && ((FUN_00418630_Class*)item)->FUN_00418630())
            reinterpret_cast<::FUN_00418600_cls *>((((FUN_00418600_Class*)item)))->FUN_00418600();
        node = ((::FUN_004bcbd0_Node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
}

struct TESForm
{
    unsigned int FNV_GetFormType();
};

struct FUN_004be1a0_Class
{
    unsigned int GetFormTypeCategory();
};

// Reads the TESForm at offset 8, switches on its form type, and returns 3 for 0x28, 4 for 0x18/0x1a, otherwise 5.
// @fnv 0x004be1a0
unsigned int FUN_004be1a0_Class::GetFormTypeCategory()
{
    unsigned int result = 0;
    switch (((TESForm**)((char*)this + 8))[0]->FNV_GetFormType())
    {
    case 0x28:
        result = 3;
        break;
    case 0x18:
    case 0x1a:
        result = 4;
        break;
    default:
        result = 5;
        break;
    }
    return result;
}

struct FUN_004a5280
{
    virtual ~FUN_004a5280();
    virtual void vfn_04();
    virtual void vfn_08(unsigned int);
    unsigned int type;
    char pad[0x10];
    float fValue;
    float fMult;
    float fAdd;
    char pad2[0x10];
    FUN_004a5280();
};

// Allocates a FUN_004a5280, applies ui via vfn_08, sets fValue and fAdd to half of af[0] and af[1], fMult to 1.0 and type to 3, then returns it.
// @fnv 0x004a4f80
FUN_004a5280* FUN_004a4f80(const float* afValues, uintptr_t ui)
{
    FUN_004a5280* p = new FUN_004a5280;
    p->vfn_08(ui);
    p->fValue = afValues[0] * 0.5;
    p->fMult = 1.0;
    p->fAdd = afValues[1] * 0.5;
    p->type = 3;
    return p;
}


struct FUN_004a9b50_Class
{
    void CopyBlocks(char* dst, char* src, unsigned int count);
};

// @fnv 0x004a9b50
void FUN_004a9b50_Class::CopyBlocks(char* apDest, char* apSource, unsigned int count)
{
    if (count <= 0)
        return;
    if (apDest < apSource)
    {
        for (unsigned int i = 0; i < count; ++i)
            std::memmove(apDest + i * 64, apSource + i * 64, 64);
    }
    else if (apDest > apSource)
    {
        for (long i = (long)count - 1; i >= 0; --i)
            std::memmove(apDest + i * 64, apSource + i * 64, 64);
    }
}

struct FUN_004b0260_shell
{
    void* m_vtbl;
    char** m_p;
    unsigned short m_8;
    unsigned short m_kPointA;
    unsigned short m_iThirdValue;
    unsigned short m_usTrailingValue;
    FUN_004b0260_shell(unsigned short a, unsigned short b);
};
// @fnv 0x004b0260
FUN_004b0260_shell::FUN_004b0260_shell(unsigned short ausSize, unsigned short b)
{
    m_vtbl = &(*reinterpret_cast<void * *>(&::DAT_0101fbcc));
    m_8 = ausSize;
    m_usTrailingValue = b;
    m_kPointA = 0;
    m_iThirdValue = 0;
    if (m_8 > 0)
        m_p = FUN_005e0ba0(m_8);
    else
        m_p = 0;
}

extern int _data_011c16bc;
struct Struct_004b0680
{
    float* p;
    float* q;
    Struct_004b0680(float* a, float* b);
    ~Struct_004b0680();
};
struct NiTPrimitiveArray_unsigned_int_
{
};
struct FUN_004b05d0_Class
{
    char AddPairIfMissing(float* a, float* b);
};
struct GOHelper
{
    void* m_pObject;
    unsigned char m_bIsOwned;
    int m_iRefCount;
    GOHelper(int);
    ~GOHelper();
    GOHelper& operator=(void*);
};
struct FUN_004a2c70
{
    void* m_pObject;
    unsigned char m_bIsOwned;
    int m_iRefCount;
    GOHelper m_helper;
    FUN_004a2c70(void* apObject, int aiRefCount, void* apObject2);
    ~FUN_004a2c70();
};
// Initialises the helper from apObject, stores aiRefCount and apObject2, and clears the owned flag.
// @fnv 0x004a2c70
FUN_004a2c70::FUN_004a2c70(void* apObject, int aiRefCount, void* apObject2) : m_helper(0)
{
    m_helper.operator=(apObject);
    m_iRefCount = aiRefCount;
    m_pObject = apObject2;
    m_bIsOwned = 0;
}

struct Date
{
    ~Date();
};
struct FUN_004a46d0 : Date
{
    ~FUN_004a46d0();
};
struct FUN_004a9e00_Class
{
    virtual void v0();
    virtual int Write(unsigned int);
    void FUN_004a9e00(unsigned int requested, unsigned int savedSize);
};
extern int DAT_0101ede0;
struct FUN_004a9ef0_Class
{
    void* m_vtbl;
    int m_iElementCount;
    void* m_p;
    int m_auiShapeKeys;
    FUN_004a9ef0_Class* FUN_004a9ef0(int a);
};
// Calls FUN_004a9ef0 with a, sets m_p to DAT_0101edc0, and returns this.
// @fnv 0x004a9e90
FUN_004a9e90_cls* FUN_004a9e90_cls::FUN_004a9e90(int a)
{
    reinterpret_cast<::FUN_004a9ef0_Class *>(this)->FUN_004a9ef0(a);
    m_p = &DAT_0101edc0;
    return this;
}
// @fnv 0x004a9ef0
FUN_004a9ef0_Class* FUN_004a9ef0_Class::FUN_004a9ef0(int aiCount)
{
    unsigned int uiSize;
    m_vtbl = (void*)&DAT_0101ede0;
    m_iElementCount = aiCount;
    m_auiShapeKeys = 0;
    uiSize = m_iElementCount << 2;
    m_p = ::FUN_00aa1070(uiSize);
    ::FUN_00403d30(m_p, 0, m_iElementCount << 2);
    return this;
}

struct FUN_004aa080_t
{
    void* FUN_004aa080(int a);
    void* m_vtbl;
    int m_i;
    void* m_p;
    int m_iUnknownValue;
};
// Calls FUN_004aa080 with a, sets m_p to point at DAT_0101ee00, and returns this.
// @fnv 0x004aa020
FUN_004aa020_class* FUN_004aa020_class::FUN_004aa020(int a)
{
    reinterpret_cast<::FUN_004aa080_t *>(this)->FUN_004aa080(a);
    m_p = &DAT_0101ee00;
    return this;
}
// Sets the vtable, stores the count, allocates count*4 bytes, zeroes them, and returns this.
// @fnv 0x004aa080
void* FUN_004aa080_t::FUN_004aa080(int aiCount)
{
    m_vtbl = &DAT_0101ee20;
    m_i = aiCount;
    m_iUnknownValue = 0;
    unsigned int sz = m_i << 2;
    m_p = ::FUN_00aa1070(sz);
    ::FUN_00403d30(m_p, 0, m_i << 2);
    return this;
}

struct FUN_004aff30_Class
{
    void* m_vtbl;
    unsigned int m_iElementCount;
    void* m_data;
    unsigned int m_auiShapeKeys;
    FUN_004aff30_Class* FUN_004aff30(unsigned int aSize);
};
// Calls FUN_004aff30 with a, sets m_p to point at DAT_0101fb8c, and returns this.
// @fnv 0x004afb20
FUN_004afb20_class* FUN_004afb20_class::FUN_004afb20(int a)
{
    reinterpret_cast<::FUN_004aff30_Class *>(this)->FUN_004aff30(a);
    m_p = &DAT_0101fb8c;
    return this;
}
// Sets the vtable, stores aSize and allocates a zeroed array of aSize 4-byte elements into m_data.
// @fnv 0x004aff30
FUN_004aff30_Class* FUN_004aff30_Class::FUN_004aff30(unsigned int aSize)
{
    unsigned int uiByteCount;
    m_vtbl = &DAT_0101fbdc;
    m_iElementCount = aSize;
    m_auiShapeKeys = 0;
    uiByteCount = m_iElementCount * 4;
    m_data = ::FUN_00aa1070(uiByteCount);
    ::FUN_00403d30(m_data, 0, m_iElementCount * 4);
    return this;
}

struct Arr
{
    unsigned int GetSize();
    unsigned int* GetAt(int);
};
struct FUN_004b06b0_Class
{
    char pad[8];
    Arr arr;
    int FindPairIndex(intptr_t a, intptr_t b);
};
// @fnv 0x004b05d0
char FUN_004b05d0_Class::AddPairIfMissing(float* pfFirst, float* pfSecond)
{
    char r = 0;
    if (reinterpret_cast<::FUN_004b06b0_Class *>(this)->FindPairIndex((intptr_t)(pfFirst), (intptr_t)(pfSecond)) == -1)
    {
        reinterpret_cast<::S_0060ba10 *>((((NiTPrimitiveArray_unsigned_int_*)((char*)this + 8))))->FUN_0096a610((intptr_t)&(const unsigned int &)((unsigned int)(uintptr_t)new Struct_004b0680(pfFirst, pfSecond)));
    }
    return r;
}
// Scans arr for the last entry whose two leading ints equal a and b, returning its index or -1 if none match.
// @fnv 0x004b06b0
int FUN_004b06b0_Class::FindPairIndex(intptr_t aiFirst, intptr_t aiSecond)
{
    int result = -1;
    for (unsigned int i = 0; i < reinterpret_cast<::FUN_00658930_class *>(&(arr))->GetShortAtOffsetA(); ++i)
    {
        if ((intptr_t)((Struct_004b0680*)(uintptr_t)*arr.GetAt(i))->p == aiFirst && (intptr_t)((Struct_004b0680*)(uintptr_t)*arr.GetAt(i))->q == aiSecond)
            result = i;
    }
    return result;
}

struct FUN_004b07e0_Class
{
    void* vtbl;
    void** m_pElements;
    unsigned short m_uiSize;
    unsigned short m_uiCount;
    void* PopElement();
};

// @fnv 0x004b07e0
void* FUN_004b07e0_Class::PopElement()
{
    if (!this->m_uiCount)
        return 0;
    --this->m_uiCount;
    void* pElement = m_pElements[this->m_uiCount];
    m_pElements[this->m_uiCount] = 0;
    if (pElement)
        --*((unsigned short*)(this) + 6);
    return pElement;
}

extern "C" const short DAT_01188ecc[];
// @fnv 0x004b10f0
unsigned short FUN_004b10f0(unsigned short start, unsigned short count)
{
    unsigned short value = 0;
    unsigned short firstB = start;
    unsigned short last8 = count;
    if (last8 > 12)
        last8 = 11;
    if (firstB >= (unsigned short)DAT_01188ecc[last8])
        firstB = (unsigned short)DAT_01188ecc[last8] - 1;
    value = firstB;
    for (int i = 0; i < last8; i++)
        value += (unsigned short)DAT_01188ecc[i];
    return value;
}

struct GlobalObject_0045cfe0
{
};
struct S0042fa20
{
    void FUN_0045ce80(int);
};
// @fnv 0x004bc4c0
void FUN_004bc4c0()
{
    bool flag = false;
    if (flag && *((unsigned int *)&(::FUN_0043d4d0((int *)(reinterpret_cast<GlobalObject_0045cfe0*>(&::g_011c63cc))))) < 3)
        reinterpret_cast<S0042fa20*>(&::g_011c63cc)->FUN_0045ce80(3);
    else if (!flag && *((unsigned int *)&(::FUN_0043d4d0((int *)(reinterpret_cast<GlobalObject_0045cfe0*>(&::g_011c63cc))))) < 5)
        reinterpret_cast<S0042fa20*>(&::g_011c63cc)->FUN_0045ce80(5);
    else if ((*((unsigned int *)&(::FUN_0043d4d0((int *)(reinterpret_cast<GlobalObject_0045cfe0*>(&::g_011c63cc))))) & 1) == 0)
        reinterpret_cast<S0042fa20*>(&::g_011c63cc)
            ->FUN_0045ce80(*((unsigned int *)&(::FUN_0043d4d0((int *)(reinterpret_cast<GlobalObject_0045cfe0*>(&::g_011c63cc))))) + 1);
}

struct FUN_004a46b0_class
{
    char* m_p;
    char* GetEntryAt(int i);
};

// @fnv 0x004a46b0
char* FUN_004a46b0_class::GetEntryAt(int aiIndex)
{
    return m_p + aiIndex * 0x60;
}

struct Point3
{
    float x;
    float y;
    float z;
    Point3 operator*(float value) const;
};

struct BGSPrimitiveBox
{
    virtual ~BGSPrimitiveBox();
    virtual void FUN_004a5040_dummy();
    virtual void SetSize(int value);
    virtual void SetPosition(Point3& position);

    int m_enabled;
    char m_auiShapeKeys[0x44];

    BGSPrimitiveBox();
};

// Allocates a BGSPrimitiveBox, sets its size and position to half of point, enables it, and returns it.
// @fnv 0x004a5040
BGSPrimitiveBox* __cdecl CreatePrimitiveBox(Point3* point, intptr_t iSize)
{
    BGSPrimitiveBox* box = new BGSPrimitiveBox;
    box->SetSize(iSize);

    Point3 position = point->operator*(0.5f);
    box->SetPosition(position);

    box->m_enabled = 1;
    return box;
}

struct FUN_004b05b0_Struct
{
    void FUN_004b05b0();
};

// @fnv 0x004b05b0
void FUN_004b05b0_Struct::FUN_004b05b0()
{
    reinterpret_cast<::FUN_004b07b0_Struct *>(this)->FUN_004b07b0();
}

struct FUN_004b55c0_class
{
    float GetFloatAt(int a1, int a2);
};

// @fnv 0x004b55c0
float FUN_004b55c0_class::GetFloatAt(int aiElement, int aiIndex)
{
    return ((float*)(this + aiElement * 0xc))[aiIndex];
}

struct FUN_004b9b20_result
{
    int a;
    int b;
    int c;
};

struct FUN_004b9b20_entry
{
    FUN_004b9b20_entry* next;
    int id;
    FUN_004b9b20_result value;
};

struct FUN_004b9b20_class
{
    // Empty virtual function stub that does nothing.
// @fnv 0x004b9b20
    virtual void FUN_004b9b20_unused()
    {}
    virtual int FUN_004b9b20_GetIndex(int arg);
    virtual bool FUN_004b9b20_Check(int arg, int id);

    int m_auiShapeKeys;
    FUN_004b9b20_entry** m_entries;

    bool FUN_004b9b20(int arg, FUN_004b9b20_result* result);
};

bool FUN_004b9b20_class::FUN_004b9b20(int arg, FUN_004b9b20_result* result)
{
    int index = this->FUN_004b9b20_GetIndex(arg);
    FUN_004b9b20_entry* entry = this->m_entries[index];

    while (entry)
    {
        if (this->FUN_004b9b20_Check(arg, entry->id))
        {
            *result = entry->value;
            return true;
        }
        entry = entry->next;
    }

    return false;
}

// @fnv 0x004a0ea0
int __cdecl FUN_004a0ea0()
{
    return (*reinterpret_cast<int *>(&::DAT_011f91a8));
}


// @fnv 0x004a2c60
int __cdecl FUN_004a2c60()
{
    return (*reinterpret_cast<int *>(&::DAT_011c61d0));
}

struct FUN_004a2cf0_M
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void FUN_0066b0d0(int v);
    ~FUN_004a2cf0_M();
};
struct FUN_004a2cf0
{
    int pad[3];
    FUN_004a2cf0_M m_iThirdValue;
    ~FUN_004a2cf0();
};
// @fnv 0x004a2cf0
FUN_004a2cf0::~FUN_004a2cf0()
{
    m_iThirdValue.FUN_0066b0d0(0);
}

extern int DAT_011c57ec;

void* __cdecl FUN_0049fef0();

struct FUN_00559450_cls
{
};
struct FUN_0057cbe0_cls
{
};
struct FUN_004a0490_cls
{
};
struct FUN_004ed900_cls
{
};

// @fnv 0x004a42a0
void __cdecl FUN_004a42a0()
{
    ::DAT_011c57e4 = 0;
    DAT_011c57e8 = 0;
    DAT_011c57ec = 0;
    DAT_011c57f0 = 0;

    FUN_004a4650((FUN_004a4650_ListBase*)((char*)FUN_0049fef0() + 8));
    char* kObj = (char*)FUN_0049fef0() + 0x14;

    intptr_t cur_2 = ::FUN_00559450((int *)(((FUN_00559450_cls*)kObj)));
    while (cur_2 != 0)
    {
        void* a = *(void **)reinterpret_cast<::ListStandIn *>((((FUN_0057cbe0_cls*)kObj)))->FUN_0057cbe0((int **)(&cur_2));
        void* b = a;
        void* c2 = b;
        intptr_t r;
        if (c2 != 0)
        {
            r = ((intptr_t)(reinterpret_cast<::StandIn *>((((FUN_004a0490_cls*)c2)))->FUN_004a0490(1)));
        }
        else
        {
            r = 0;
        }
    }
    reinterpret_cast<::NiTPointerListBase<::NiTPointerAllocator<unsigned int>, void*> *>((((FUN_004ed900_cls*)kObj)))->RemoveAll();
}

struct FUN_004a4650_ListBase;
void FUN_004a4650(FUN_004a4650_ListBase* self);
struct ObstacleBase
{
    ~ObstacleBase();
};
struct FUN_004a44a0 : ObstacleBase
{
    ~FUN_004a44a0();
};
// Destructor that forwards to FUN_004a4650, passing this as a list base.
// @fnv 0x004a44a0
FUN_004a44a0::~FUN_004a44a0()
{
    FUN_004a4650(reinterpret_cast<FUN_004a4650_ListBase*>(this));
}

struct S_004a4730_Elem
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
    S_004a4730_Elem();
};

struct S_004a4730_Base
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_004a4730_Base(void* buf, int a, int count);
    ~S_004a4730_Base();
};

struct FUN_004a4730 : S_004a4730_Base
{
    S_004a4730_Elem unk10[8];
    FUN_004a4730(int a);
};

// Constructs the object by initializing its base with the inline array of 8 elements and the given count.
// @fnv 0x004a4730
FUN_004a4730::FUN_004a4730(int a) : S_004a4730_Base(unk10, a, 8)
{}

// A tiny flag holder: one byte of state plus the query that asks the audio
// subsystem for a stream owned by the caller.
struct AudioSource
{
    bool m_bEnableState;
    void* FUN_004a4840(void* pOwner);
};

// The object that owns the audio source.  The handle produced by the query is
// handed to the manager, which is called on this very object.
struct AudioOwner
{
    void* m_pObject;
    int m_iValue;
    int m_iFlags;
    void FUN_004a4810();
};
// @fnv 0x004a4440
void FUN_004a4440_Class::FUN_004a4440()
{
    reinterpret_cast<::FUN_004a46d0 *>(this)->FUN_004a46d0::~FUN_004a46d0();
}
// Destructor that calls FUN_004a4810 before the base Date destructor runs.
// @fnv 0x004a46d0
FUN_004a46d0::~FUN_004a46d0()
{
    reinterpret_cast<::AudioOwner *>(this)->FUN_004a4810();
}

// Creates an empty AudioSource, obtains a source via FUN_004a4840 from this owner, and passes it to FUN_004a4990.
// @fnv 0x004a4810
void AudioOwner::FUN_004a4810()
{
    AudioSource source = {};
    reinterpret_cast<::FUN_004a4990_s *>(this)->FUN_004a4990((intptr_t)(source.FUN_004a4840(this)));
}

class TESObjectREFR;

class RefBoolMap4A8
{
  public:
    bool GetAt(TESObjectREFR* pkRef, bool& bValue);
};


// If the reference's bool in g_kRefBoolMap4A8 is unset or false, adds iAmount to **ppiCount and sets the reference's bool to true.
// @fnv 0x004a8b40
void AddToRefCountIfNotFlagged(TESObjectREFR* pkRef, int iAmount, int** ppiCount)
{
    int** ppiTarget = ppiCount;
    bool bFlagged = false;
    if (!reinterpret_cast<::FUN_0057c850_cls *>(&((*reinterpret_cast<::RefBoolMap4A8 *>(&::g_011c5c40))))->FUN_0057c850(pkRef, (bool *)&(bFlagged)) || !bFlagged)
    {
        bool bSkipA = false;
        bool bSkipB = false;
        if (!bSkipB || !bSkipA)
        {
            **ppiTarget += iAmount;
            reinterpret_cast<::FUN_0084d310_class *>(&((*reinterpret_cast<::RefBoolMap4A8 *>(&::g_011c5c40))))->FUN_0084d310((int)(intptr_t)(pkRef), true);
        }
    }
}

class FUN_004a9850_base
{
  public:
    virtual void unk00();
    ~FUN_004a9850_base();
    int unk04;
};

class FUN_004a9850 : public FUN_004a9850_base
{
  public:
    virtual ~FUN_004a9850();
    void unk08();
};

// Calls unk08() during destruction of the object.
// @fnv 0x004a9850
FUN_004a9850::~FUN_004a9850()
{
    reinterpret_cast<::FUN_00438af0_Class *>((this))->FUN_00438af0();
}

struct C4A9A60Entry
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
};

class C4A9A60Array
{
  public:
    int unk00;
    C4A9A60Entry* m_pUserData;

    int AddEntry(const C4A9A60Entry& kEntry);
};

struct ScanItem64
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
    ScanItem64();
    int ClearToZero();
};


struct FUN_004a9ab0_cls
{
    int unk00;

    void ConstructScanItems(intptr_t base, unsigned int count);
};
// Sets the vtable to DAT_0101edac, calls FUN_004a9e00 with 0, 0, and returns this.
// @fnv 0x004a9d80
FUN_004a9d80_class* FUN_004a9d80_class::FUN_004a9d80()
{
    vtable = &DAT_0101edac;
    reinterpret_cast<::FUN_004a9e00_Class *>(this)->FUN_004a9e00(0, 0);
    return this;
}
// @fnv 0x004a9e00
void FUN_004a9e00_Class::FUN_004a9e00(unsigned int requested, unsigned int savedSize)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0xc) = 0;
    if (savedSize > requested)
        requested = savedSize;
    if (requested > 0)
    {
        *(int*)((char*)this + 4) = Write(requested);
        *(int*)((char*)this + 0xc) = requested;
    }
    if (savedSize > 0)
    {
        reinterpret_cast<::FUN_004a9ab0_cls *>(this)->ConstructScanItems(*(int*)((char*)this + 4), savedSize);
        *(int*)((char*)this + 8) = savedSize;
    }
}
// Allocates a slot in the entry array, constructs it, copies the given entry into it, and returns the slot index.
// @fnv 0x004a9a60
int C4A9A60Array::AddEntry(const C4A9A60Entry& kEntry)
{
    int iIndex = ((int)(reinterpret_cast<::FUN_006b3fd0_cls *>(this)->FUN_006b3fd0()));
    reinterpret_cast<::FUN_004a9ab0_cls *>(this)->ConstructScanItems((intptr_t)(&m_pUserData[iIndex]), 1);
    m_pUserData[iIndex] = kEntry;
    return iIndex;
}

// Placement-constructs count ScanItem64 objects at base, each 64 bytes apart.
// @fnv 0x004a9ab0
void FUN_004a9ab0_cls::ConstructScanItems(intptr_t base, unsigned int count)
{

    for (unsigned int i = 0; i < count; ++i)
    {
        new ((char*)base + (i << 6)) ScanItem64();
    }
}

struct Base
{
    int a;
    virtual ~Base();
};
struct FUN_004a9cc0_cls : Base
{
    virtual ~FUN_004a9cc0_cls();
};
// @fnv 0x004a9cc0
FUN_004a9cc0_cls::~FUN_004a9cc0_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_004a9fc0
{
    virtual ~FUN_004a9fc0();
};

struct FUN_004a9f60 : FUN_004a9fc0
{
    virtual ~FUN_004a9f60();
};

// Destructor that calls FUN_00438af0 before the object is destroyed.
// @fnv 0x004a9f60
FUN_004a9f60::~FUN_004a9f60()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

class Ref_cls;
class Vt_cls
{
  public:
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
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
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
    virtual void v3a(Ref_cls* a);
};
class Ref_cls
{
  public:
};
class Obj2_cls
{
  public:
};

// @fnv 0x004ab0c0
void __cdecl FUN_004ab0c0(Ref_cls* apRef)
{
    Vt_cls* v;
    if (apRef == 0)
        return;
    ::FUN_004b6ce0((::FUN_004b6ce0_cls *)(apRef));
    ::FUN_00b5b1c0((::ShadowSceneNode *)(((::Obj2_cls *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)))), 0, (::NiAVObject *)(apRef));
    if (((::Vt_cls *)(reinterpret_cast<::FUN_009611e0_shell *>((apRef))->FUN_009611e0())) != 0)
    {
        ::FUN_00c69ee0((::NiAVObject *)(apRef), 1, 0);
        v = (Vt_cls*)((::Vt_cls *)(reinterpret_cast<::FUN_009611e0_shell *>((apRef))->FUN_009611e0()));
        v->v3a(apRef);
    }
}

class NiExtraData;
class NiFixedString;
struct NiAVObject
{
    void IncRefCount();
    void DecRefCount();
public:
    ::NiExtraData *GetExtraData(const ::NiFixedString &);
};

struct Pn4afe
{
    int unk00;
    NiPointer<NiAVObject>* unk04;
    unsigned short unk08;
    unsigned short unk0A;
    void TrimTrailingNullPointers();
};

// Decrements unk0A while the last entry of the unk04 pointer array is null, stopping at the first non-null entry or zero.
// @fnv 0x004afe50
void Pn4afe::TrimTrailingNullPointers()
{
    while (unk0A > 0)
    {
        if (reinterpret_cast<::DummyStruct_00631820 *>((void *)&(const ::NiPointer< ::NiAVObject> &)(unk04[unk0A - 1]))->IsNotEqual((const ::DummyStruct_00631820 &)((const ::NiPointer< ::NiAVObject> &)(NiPointer<NiAVObject>(0)))))
        {
            break;
        }
        unk0A--;
    }
}

struct Unk438Helper
{
};

struct Unk438Base
{
    virtual void v00();
    ~Unk438Base();
};

struct FUN_004affa0 : Unk438Base
{
    virtual ~FUN_004affa0();
};

// Destructor that calls FUN_00438af0 on this object.
// @fnv 0x004affa0
FUN_004affa0::~FUN_004affa0()
{
    reinterpret_cast<::FUN_00438af0_Class *>((((Unk438Helper*)this)))->FUN_00438af0();
}

struct FUN_00658930_cls
{
};


struct Guard_b9135
{
    ~Guard_b9135();
};

struct Base_b9135
{
    virtual ~Base_b9135();
};

class FUN_004b0480_cls : public Base_b9135
{
  public:
    virtual ~FUN_004b0480_cls();
    virtual void FUN_004b0480_vslot();

    char unk04[4];
    Guard_b9135 m_08;
};

// @fnv 0x004b0480
FUN_004b0480_cls::~FUN_004b0480_cls()
{
    unsigned int count = reinterpret_cast<::FUN_00658930_class *>((((FUN_00658930_cls*)&this->m_08)))->GetShortAtOffsetA();
    for (unsigned int i = 0; i < count; ++i)
    {
        void* p = ((FUN_004b07e0_Class*)&this->m_08)->PopElement();
        void* q = p;
        FUN_00401030(q);
    }
}

struct S_004b0cf0_Obj
{
    void IncRefCount();
    void DecRefCount();
};
struct S_004b0cf0_Queue
{
    ~S_004b0cf0_Queue();
};
struct FUN_004b0cf0
{
    int unk00;
    S_004b0cf0_Queue q;
    ~FUN_004b0cf0();
};
// Calls FUN_004b0cf0, then deletes this if bit 0 of flags is set, and returns this.
// @fnv 0x004b08e0
void* FUN_004b08e0_Class::FUN_004b08e0(unsigned int flags)
{
    reinterpret_cast<::FUN_004b0cf0 *>(this)->FUN_004b0cf0::~FUN_004b0cf0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Resets unk00 to 0, then repeatedly pushes a null NiPointer and pops until the queue q is empty.
// @fnv 0x004b0cf0
FUN_004b0cf0::~FUN_004b0cf0()
{
    unk00 = 0;
    while (!reinterpret_cast<::ObsList *>(&(q))->FUN_004a4460())
    {
        {
            NiPointer<S_004b0cf0_Obj> node(0);
            reinterpret_cast<::Helper62d0 *>(&(q))->AssignNodePointer((const ::NiPointer< ::NiNode> &)(node));
        }
        reinterpret_cast<::DecalListManager *>(&(q))->PopHead();
    }
}


struct FUN_004b0ef0_cls
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_004b0ef0();
};

// Calls FUN_004019a0 on unk08; if it returns 0, calls FUN_004b0f40(1) on this as a FUN_004b0f40_Holder.
// @fnv 0x004b0ef0
void FUN_004b0ef0_cls::FUN_004b0ef0()
{
    if (((int)(::WaitForSingleObjectEx((long *)(void *)(&unk08)))) == 0)
    {
        void* cur = this;
        FUN_004b0f40_Holder* holder = (FUN_004b0f40_Holder*)cur;
        (holder != 0) ? holder->FUN_004b0f40(1) : 0;
    }
}

namespace fnv_004b3570 {

struct NiPoint3V
{
    float x;
    float y;
    float z;
    NiPoint3V();
};

struct RgbaColor
{
    float r;
    float g;
    float b;
    float a;
    RgbaColor();
};

struct NiPoint2
{
    float x;
    float y;
};

struct NiObject
{
};

struct NiAVObject : NiObject
{
};

struct NiTriShape : NiAVObject
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
    int unkC0;
    NiTriShape(unsigned short usVertices, NiPoint3V* pkVertex, NiPoint3V* pkNormal, RgbaColor* pkColor,
               NiPoint2* pkTexture, unsigned short usNumTextureSets, unsigned int eNBTMethod,
               unsigned short usTriangles, unsigned short* pusTriList);
};

struct BSShaderLightingProperty : NiObject
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
    BSShaderLightingProperty();
};


// Builds a three-vertex NiTriShape from three points and a color, optionally attaching a lighting property and initializing the geometry shader.
// @fnv 0x004b3570
NiTriShape* __cdecl FUN_004b3570(NiPoint3V kP0, NiPoint3V kP1, NiPoint3V kP2, const RgbaColor& kColor,
                                 bool bEnableLighting)
{
    NiPoint3V* aPVerts = new NiPoint3V[3];
    aPVerts[0] = kP0;
    aPVerts[1] = kP1;
    aPVerts[2] = kP2;
    RgbaColor* pColors2 = new RgbaColor[3];
    pColors2[0] = kColor;
    pColors2[1] = kColor;
    pColors2[2] = kColor;
    unsigned short* pTris = (unsigned short*)::FUN_00aa1070(12);
    pTris[0] = 0;
    pTris[1] = 2;
    pTris[2] = 1;
    pTris[3] = 0;
    pTris[4] = 1;
    pTris[5] = 2;
    NiTriShape* pShape_ = new NiTriShape(3, aPVerts, 0, pColors2, 0, 0, 0, 2, pTris);
    if (bEnableLighting)
    {
        BSShaderLightingProperty* pProp2 = new BSShaderLightingProperty;
        reinterpret_cast<::FUN_00439410_cls *>((pShape_))->FUN_00439410((::ArgObject *)(pProp2));
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(pShape_), 0, 0);
    }
    return pShape_;
}
}  // namespace fnv_004b3570

struct FUN_006815c0
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FUN_006815c0();
};

struct FUN_004b4910_Source
{
};

int __cdecl FUN_004b4a10(unsigned short a1, int a2, int a3, int a4);

// Allocates an array of FUN_006815c0 sized by source->FUN_00456650() and fills it via FUN_004b4a10, returning null if source is null or its count is zero.
// @fnv 0x004b4910
FUN_006815c0* __cdecl CreateElementArray(FUN_004b4910_Source* source)
{
    FUN_006815c0* elements = 0;
    if (!source || !reinterpret_cast<::FUN_00456650_shell *>((source))->FUN_00456650())
    {
        return 0;
    }
    elements = new FUN_006815c0[reinterpret_cast<::FUN_00456650_shell *>((source))->FUN_00456650()];
    FUN_004b4a10(reinterpret_cast<::FUN_00456650_shell *>((source))->FUN_00456650(), ((int)(reinterpret_cast<::FUN_0049ec60 *>((source))->GetNext())), (intptr_t)elements, ::FUN_00461130((intptr_t)(source)));
    return elements;
}

// Log a heading and the machine's computer name.



// Retrieves the computer name, logs the heading, then logs a formatted "Computer Name: %s" line using the prepared script message.
// @fnv 0x004b4a30
void __cdecl FUN_004b4a30(const char* pcHeading)
{
    char acLine[264];
    unsigned long ulSize = 260;
    if (GetUserNameA(::xg_PlayerName, &ulSize))
    {
        ::FUN_0040fbe0();
        sprintf(acLine, "Computer Name: %s", ((const char *)(::FUN_00464f30((intptr_t)(::xg_PlayerName)))));
        ::FUN_0040fbe0();
    }
}

struct FNVForm
{
};


struct FNVNode
{
    virtual void R00();
    virtual void R04();
    virtual void R08();
    virtual int IsBranch();
    virtual void R10();
    virtual void R14();
    virtual int IsTerminalNode();

    unsigned int FUN_0043b480();
    FNVNode* FUN_0043b4a0(unsigned int index);
};

// Recursively walks child nodes; for leaf nodes with a form whose FUN_00441110 value is 8-12, returns that form pointer as an unsigned int.
// @fnv 0x004b55e0
unsigned int __cdecl FindAcceptedForm(FNVNode* root)
{
    unsigned int found = 0;
    if (root->FUN_0043b480() == 0)
        return 0;

    unsigned int count = root->FUN_0043b480();
    for (unsigned int index = 0; index < count; ++index)
    {
        if (found != 0)
            return found;

        FNVNode* node = root->FUN_0043b4a0(index);
        if (node == 0)
            continue;

        if (node->IsBranch())
        {
            FNVNode* branch = node;
            found = FindAcceptedForm(branch);
        }
        else if (node->IsTerminalNode())
        {
            FNVNode* leaf = node;
            FNVForm* form = ((::FNVForm *)(reinterpret_cast<::FUN_00a59d30_C *>((leaf))->FUN_00a59d30(::FUN_00438220())));
            if (form != 0)
            {
                unsigned int accepted =
                    (unsigned int)(uintptr_t)form &
                    ((form == 0 ? 0 : (((int)(reinterpret_cast<::BGSTerrainManager *>((form))->GetMinLevel())) >= 8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((form))->GetMinLevel())) <= 12)) ? ~0u : 0u);
                if (accepted)
                    return accepted;
            }
        }
    }

    return found;
}

extern int DAT_010205d4;

struct FUN_004b99b0_cls
{
    void* m_00;
    int m_04;
    void* m_08;
    unsigned int m_0C;
    FUN_004b99b0_cls* FUN_004b99b0(int count);
};
// Calls FUN_004b99b0 with arg, sets p to point at DAT_010205b4, and returns this.
// @fnv 0x004b9950
FUN_004b9950_class* FUN_004b9950_class::FUN_004b9950(int arg)
{
    reinterpret_cast<::FUN_004b99b0_cls *>(this)->FUN_004b99b0(arg);
    p = &DAT_010205b4;
    return this;
}

// Initialises the object: stores a global pointer and count, allocates count*4 bytes, zero-fills them and stores the pointer.
// @fnv 0x004b99b0
FUN_004b99b0_cls* FUN_004b99b0_cls::FUN_004b99b0(int count)
{
    m_00 = &DAT_010205d4;
    m_04 = count;
    m_0C = 0;
    unsigned int size = m_04 << 2;
    m_08 = FUN_00aa1070(size);
    FUN_00403d30(m_08, 0, m_04 << 2);
    return this;
}

struct S_004b9a20_Val
{
    int a;
    int b;
    int c;
};

struct S_004b9a20_Item;

struct S_004b9a20_cls
{
    virtual void vfn_00()
    {}
    virtual unsigned int vfn_04(unsigned int key)
    {
        return 0;
    }
    virtual bool vfn_08(unsigned int key, unsigned int itemKey)
    {
        return false;
    }
    virtual void vfn_0c(S_004b9a20_Item* item, unsigned int key, S_004b9a20_Val value)
    {}
    virtual void vfn_10()
    {}
    virtual S_004b9a20_Item* vfn_14()
    {
        return 0;
    }
    unsigned int m_uiHashSize;
    S_004b9a20_Item** m_ppkHashTable;
    unsigned int m_uiCount;
    void SetOrInsert(unsigned int key, S_004b9a20_Val value);
};

struct S_004b9a20_Item
{
    S_004b9a20_Item* m_pkNext;
    unsigned int m_key;
    S_004b9a20_Val m_val;
};

// @fnv 0x004b9a20
void S_004b9a20_cls::SetOrInsert(unsigned int key, S_004b9a20_Val value)
{
    unsigned int hash2 = this->vfn_04(key);
    S_004b9a20_Item* p2 = this->m_ppkHashTable[hash2];
    int i = 0;
    while (p2)
    {
        i = i + 1;
        if (this->vfn_08(key, p2->m_key))
        {
            p2->m_val = value;
            return;
        }
        p2 = p2->m_pkNext;
    }
    p2 = this->vfn_14();
    this->vfn_0c(p2, key, value);
    p2->m_pkNext = this->m_ppkHashTable[hash2];
    this->m_ppkHashTable[hash2] = p2;
    this->m_uiCount = this->m_uiCount + 1;
}

struct TableValue
{
    int first;
    int second;
    int third;
};
struct DataBufferInfo
{
    DataBufferInfo* next;
    int key;
    TableValue value;
};
struct HashTableBase
{
    virtual void Reserved();
    virtual unsigned int FindBucket(int key);
    unsigned int bucketCount;
    DataBufferInfo** buckets;
    void GetNextEntry(DataBufferInfo** iterator, int* keyOut, TableValue* valueOut);
};
// Reads the current node's key and value into the outputs, then advances the iterator to the next node or the next non-empty bucket.
// @fnv 0x004b9bf0
void HashTableBase::GetNextEntry(DataBufferInfo** iterator, int* keyOut, TableValue* valueOut)
{
    unsigned int bucketIndex;
    DataBufferInfo* node = *iterator;
    *keyOut = node->key;
    *valueOut = node->value;
    if (node->next != 0)
    {
        *iterator = node->next;
    }
    else
    {
        bucketIndex = FindBucket(node->key);
        ++bucketIndex;
        for (; bucketIndex < bucketCount; ++bucketIndex)
        {
            node = buckets[bucketIndex];
            if (node != 0)
            {
                *iterator = node;
                return;
            }
        }
        *iterator = 0;
    }
}

struct Base_b9225
{
    virtual ~Base_b9225();
    int unk04;
    int unk08;
    int unk0C;
};

struct FUN_004b9cd0 : Base_b9225
{
    virtual ~FUN_004b9cd0();
};
// @fnv 0x004b9980
void* FUN_004b9980_Class::FUN_004b9980(unsigned int flags)
{
    reinterpret_cast<::FUN_004b9cd0 *>(this)->FUN_004b9cd0::~FUN_004b9cd0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls FUN_00438af0 before destroying the base object.
// @fnv 0x004b9cd0
FUN_004b9cd0::~FUN_004b9cd0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct Pt3_4ba280
{
    float x;
    float y;
    float z;
    Pt3_4ba280();
    Pt3_4ba280(float ax, float ay, float az);
};

struct NodePtr_4ba280
{
    void* m_pObject;
    NodePtr_4ba280(void* object);
    ~NodePtr_4ba280();
    NodePtr_4ba280& operator=(void* object);
};

struct Base_4ba280
{
    void* unk04;
    void* unk08;
    void* unk0C;
    Base_4ba280();
    virtual ~Base_4ba280();
};

void FUN_004bc4c0();
extern char DAT_01189184;

struct FUN_004ba280 : Base_4ba280
{
    int* grid;
    Pt3_4ba280 origin;
    bool bFlag;
    NodePtr_4ba280 m_pController;
    FUN_004ba280();
    virtual ~FUN_004ba280();
};

// @fnv 0x004ba280
FUN_004ba280::FUN_004ba280() : m_pController(0)
{
    FUN_004bc4c0();
    reinterpret_cast<::FUN_0041fd00_shell *>(this)->FUN_0041fd00(*((unsigned int *)&(::FUN_0043d4d0((int *)&(::g_011c63cc)))));
    grid = new int[((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) * ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))];
    ::FUN_00403d30(grid, 0, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) * 4 * ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())));
    origin = Pt3_4ba280(0.0f, 0.0f, 0.0f);
    DAT_01189184 = 1;
    m_pController = 0;
    bFlag = false;
}

struct Pt3
{
    float x;
    float y;
    float z;
    Pt3();
    Pt3(float ax, float ay, float az);
};


struct FUN_004a37b0
{
    Pt3 pos0;
    Pt3 pos1;
    Pt3 pos2;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    int unk48;
    float unk4C;
    int unk50;
    float unk54;
    float unk58;
    float unk5C;
    Pt3 scale;
    int unk6C;
    bool unk70;
    bool unk71;
    bool unk72;
    bool unk73;
    bool unk74;
    bool unk75;
    bool unk76;
    bool unk77;
    bool unk78;
    bool unk79;
    FUN_004a37b0();
};

// Initialises the object's positions to zero, sets default flags, numeric fields and a unit scale.
// @fnv 0x004a37b0
FUN_004a37b0::FUN_004a37b0() : scale(0.0f, 0.0f, 0.0f)
{
    pos0 = (*reinterpret_cast<const ::Pt3 *>((void *)&::NiPoint3::ZERO));
    pos1 = (*reinterpret_cast<const ::Pt3 *>((void *)&::NiPoint3::ZERO));
    pos2 = (*reinterpret_cast<const ::Pt3 *>((void *)&::NiPoint3::ZERO));
    unk24 = 0;
    unk28 = 0;
    unk2C = 0;
    unk30 = 0;
    unk34 = -1;
    unk38 = 0.0f;
    unk3C = 0.0f;
    unk40 = 0.0f;
    unk44 = 0.0f;
    unk70 = false;
    unk71 = false;
    unk72 = true;
    unk48 = 0;
    unk73 = false;
    unk4C = 0.0f;
    unk76 = false;
    unk50 = 0;
    unk74 = true;
    unk75 = false;
    unk54 = 4.0f;
    unk58 = 15.0f;
    unk5C = 16.0f;
    scale = Pt3(1.0f, 1.0f, 1.0f);
    unk77 = false;
    unk78 = false;
    unk79 = false;
    unk6C = 0;
}

class NiAVObject;
class NiNode
{
  public:
    void IncRefCount();
    void DecRefCount();
public:
    ::NiAVObject *GetAt(unsigned int);
};

struct FUN_004a4860_node
{
    FUN_004a4860_node* m_pNext;
    FUN_004a4860_node* m_pListObject;
    NiPointer<NiNode> m_08;
};

class FUN_004a4860_cls
{
  public:
    FUN_004a4860_node* m_pHead;
    FUN_004a4860_node* m_pTail;
    unsigned int m_uiCount;

    NiPointer<NiNode> PopFront();
};

// @fnv 0x004a4860
NiPointer<NiNode> FUN_004a4860_cls::PopFront()
{
    FUN_004a4860_node* node = m_pHead;
    m_pHead = m_pHead->m_pNext;
    if (m_pHead != 0)
    {
        m_pHead->m_pListObject = 0;
    }
    else
    {
        m_pTail = 0;
    }
    NiPointer<NiNode> item(node->m_08);
    reinterpret_cast<::FUN_004a4930_class *>(this)->FUN_004a4930(node);
    m_uiCount--;
    return item;
}

class B4B00A0MapBase
{
  public:
    virtual ~B4B00A0MapBase();


    unsigned int m_uiHashSize;
    void** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_004b00a0_cls : public B4B00A0MapBase
{
  public:
    FUN_004b00a0_cls();
    virtual ~FUN_004b00a0_cls();
};
// Calls FUN_004b00a0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x004afbf0
void* FUN_004afbf0_class::FUN_004afbf0(unsigned int flags)
{
    reinterpret_cast<::FUN_004b00a0_cls *>(this)->FUN_004b00a0_cls::~FUN_004b00a0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls RemoveAll to clear the hash table entries.
// @fnv 0x004b00a0
FUN_004b00a0_cls::~FUN_004b00a0_cls()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct NiPoint3_ext
{
    float x, y, z;
    NiPoint3_ext();
};
struct NiPoint3Ex : NiPoint3_ext
{
    NiPoint3Ex(float x, float y, float z);
};
struct FUN_004a7800
{
    float r, g, b, a;
    FUN_004a7800();
};
struct NiMemObjectAllocation
{
};
struct NiObject
{
};
struct BSShaderLightingProperty : NiMemObjectAllocation
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    BSShaderLightingProperty();
};
struct NiPoint2;
struct NiTriShape : NiMemObjectAllocation
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    NiTriShape(unsigned short, NiPoint3*, NiPoint3*, void*, NiPoint2*, unsigned short, unsigned int, unsigned short,
               unsigned short*);
};
// Builds an octahedron NiTriShape from six vertices and 24 indices around a given size and color, optionally attaching a lighting property.
// @fnv 0x004b29b0
NiTriShape* __cdecl CreateOctahedron(float size, const FUN_004a7800* color, bool lighting)
{
    NiPoint3_ext* indices = new NiPoint3_ext[6];
    indices[0] = NiPoint3Ex(0.0f, 0.0f, float(size * 1.4142135381698608));
    indices[1] = NiPoint3Ex(-size, size, 0.0f);
    indices[2] = NiPoint3Ex(size, size, 0.0f);
    indices[3] = NiPoint3Ex(size, -size, 0.0f);
    indices[4] = NiPoint3Ex(-size, -size, 0.0f);
    indices[5] = NiPoint3Ex(0.0f, 0.0f, float(-size * 1.4142135381698608));
    FUN_004a7800* colors = new FUN_004a7800[6];
    colors[0] = *color;
    colors[1] = *color;
    colors[2] = *color;
    colors[3] = *color;
    colors[4] = *color;
    colors[5] = *color;
    unsigned short* shape = (unsigned short*)::FUN_00aa1070(48);
    shape[0] = 0;
    shape[1] = 2;
    shape[2] = 1;
    shape[3] = 0;
    shape[4] = 3;
    shape[5] = 2;
    shape[6] = 0;
    shape[7] = 4;
    shape[8] = 3;
    shape[9] = 0;
    shape[10] = 1;
    shape[11] = 4;
    shape[12] = 1;
    shape[13] = 2;
    shape[14] = 5;
    shape[15] = 2;
    shape[16] = 3;
    shape[17] = 5;
    shape[18] = 3;
    shape[19] = 4;
    shape[20] = 5;
    shape[21] = 4;
    shape[22] = 1;
    shape[23] = 5;
    NiTriShape* vertices = new NiTriShape(6, (NiPoint3*)indices, 0, colors, 0, 0, 0, 8, shape);
    if (lighting)
    {
        BSShaderLightingProperty* property = new BSShaderLightingProperty;
        reinterpret_cast<::FUN_00439410_cls *>((vertices))->FUN_00439410((::ArgObject *)(::NiObject *)((NiObject*)property));
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(vertices), 0, 0);
    }
    return vertices;
}

struct Vec87
{
    float x, y, z;
    Vec87();
};
struct Color87
{
    float r, g, b, a;
    Color87();
};
struct Extra87
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
    Extra87();
};
struct Mesh87
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
    Mesh87(int, Vec87*, void*, Color87*, void*, int, int, int, unsigned short*);
};
// Builds an 8-vertex box mesh from eight corner positions and a color, with 72 triangle indices, and optionally attaches extra data.
// @fnv 0x004b2eb0
Mesh87* CreateBoxMesh(const Vec87& aCorner0, const Vec87& aCorner1, const Vec87& aCorner2, const Vec87& aCorner3,
                      const Vec87& aCorner4, const Vec87& aCorner5, const Vec87& aCorner6, const Vec87& aCorner7,
                      const Color87& color, bool extra)
{
    Vec87* vertices2 = new Vec87[8];
    vertices2[0] = aCorner0;
    vertices2[1] = aCorner1;
    vertices2[2] = aCorner2;
    vertices2[3] = aCorner3;
    vertices2[4] = aCorner4;
    vertices2[5] = aCorner5;
    vertices2[6] = aCorner6;
    vertices2[7] = aCorner7;
    Color87* colors73 = new Color87[8];
    colors73[0] = color;
    colors73[1] = color;
    colors73[2] = color;
    colors73[3] = color;
    colors73[4] = color;
    colors73[5] = color;
    colors73[6] = color;
    colors73[7] = color;
    unsigned short* indices21 = (unsigned short*)FUN_00aa1070(144);
    indices21[0] = 0;
    indices21[1] = 2;
    indices21[2] = 1;
    indices21[3] = 0;
    indices21[4] = 3;
    indices21[5] = 2;
    indices21[6] = 0;
    indices21[7] = 7;
    indices21[8] = 3;
    indices21[9] = 0;
    indices21[10] = 4;
    indices21[11] = 7;
    indices21[12] = 1;
    indices21[13] = 4;
    indices21[14] = 0;
    indices21[15] = 1;
    indices21[16] = 5;
    indices21[17] = 4;
    indices21[18] = 2;
    indices21[19] = 5;
    indices21[20] = 1;
    indices21[21] = 2;
    indices21[22] = 6;
    indices21[23] = 5;
    indices21[24] = 3;
    indices21[25] = 6;
    indices21[26] = 2;
    indices21[27] = 3;
    indices21[28] = 7;
    indices21[29] = 6;
    indices21[30] = 4;
    indices21[31] = 7;
    indices21[32] = 6;
    indices21[33] = 4;
    indices21[34] = 6;
    indices21[35] = 5;
    indices21[36] = 0;
    indices21[37] = 1;
    indices21[38] = 2;
    indices21[39] = 0;
    indices21[40] = 2;
    indices21[41] = 3;
    indices21[42] = 0;
    indices21[43] = 3;
    indices21[44] = 7;
    indices21[45] = 0;
    indices21[46] = 7;
    indices21[47] = 4;
    indices21[48] = 1;
    indices21[49] = 0;
    indices21[50] = 4;
    indices21[51] = 1;
    indices21[52] = 4;
    indices21[53] = 5;
    indices21[54] = 2;
    indices21[55] = 1;
    indices21[56] = 5;
    indices21[57] = 2;
    indices21[58] = 5;
    indices21[59] = 6;
    indices21[60] = 3;
    indices21[61] = 2;
    indices21[62] = 6;
    indices21[63] = 3;
    indices21[64] = 6;
    indices21[65] = 7;
    indices21[66] = 4;
    indices21[67] = 6;
    indices21[68] = 7;
    indices21[69] = 4;
    indices21[70] = 5;
    indices21[71] = 6;
    Mesh87* mesh1 = new Mesh87(8, vertices2, 0, colors73, 0, 0, 0, 24, indices21);
    if (extra)
    {
        Extra87* data = new Extra87;
        reinterpret_cast<::FUN_00439410_cls *>((mesh1))->FUN_00439410((::ArgObject *)(data));
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(mesh1), 0, 0);
    }
    return mesh1;
}

namespace fnv_004b3890 {
struct FUN_004a7800
{
    float red, green, blue, alpha;
    FUN_004a7800();
};
class NiMemObject
{
  public:
};
struct BSShaderLightingProperty : NiMemObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    BSShaderLightingProperty();
};
struct FUN_00a746e0 : NiMemObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    FUN_00a746e0(unsigned short, FUN_006815c0*, FUN_004a7800*, void*, unsigned int, unsigned int, bool*);
};

// @fnv 0x004b3890
FUN_00a746e0* __cdecl FUN_004b3890(const FUN_006815c0& aStartVertex, const FUN_004a7800& startColor,
                                   const FUN_006815c0& aEndVertex, const FUN_004a7800& endColor, bool addShader)
{
    FUN_006815c0* vertices = new FUN_006815c0[2];
    vertices[0] = aStartVertex;
    vertices[1] = aEndVertex;
    FUN_004a7800* colors = new FUN_004a7800[2];
    colors[0] = startColor;
    colors[1] = endColor;
    // Each flag enables the outgoing segment from the corresponding vertex.
    bool* lines = new bool[2];
    lines[0] = true;
    lines[1] = false;
    // The geometry owns the vertex, color and segment buffers.
    FUN_00a746e0* connections = new FUN_00a746e0(2, vertices, colors, 0, 0, 0, lines);
    if (addShader)
    {
        BSShaderLightingProperty* shader = new BSShaderLightingProperty;
        reinterpret_cast<::FUN_00439410_cls *>((connections))->FUN_00439410((::ArgObject *)(shader));
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(connections), 0, 0);
    }
    return connections;
}
}  // namespace fnv_004b3890

struct Query4a4
{
    ~Query4a4();
};
struct Entry4a4
{
    char pad[0x1c];
    Query4a4* m_pQuery;
};
struct EntryPtr4a4
{
};
struct List4a4
{
};
struct Renderer4a4;
struct Owner4a4
{
    void* pad[2];
    List4a4 m_kNode;
    void FUN_004a4340();
};

// @fnv 0x004a4340
void Owner4a4::FUN_004a4340()
{
    if (((unsigned int)(uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_kNode))->GetName())) > 0)
    {
        ::FUN_004a0370((char *)(::Renderer4a4 *)(((::Renderer4a4 *)(::FUN_0043c4b0()))));
        void* pos = ((void *)(::FUN_00559450((int *)&(m_kNode))));
        while (pos)
        {
            void* pPrev = pos;
            Entry4a4* pkEntry = ((::Entry4a4 *)(::FUN_00559450((int *)(((::EntryPtr4a4 *)(reinterpret_cast<::ListStandIn *>(&(m_kNode))->FUN_0057cbe0((int **)(void **)(&pos))))))));
            if (pkEntry && pkEntry->m_pQuery)
            {
                unsigned int uiOut = 0;
                reinterpret_cast<::S_00c4edf0_cls *>((pkEntry->m_pQuery))->FUN_00c4edf0((std::intptr_t)(&uiOut), 1);
                delete pkEntry->m_pQuery;
                pkEntry->m_pQuery = 0;
            }
        }
        reinterpret_cast<::fnv_004a03c0::DD *>((((::Renderer4a4 *)(::FUN_0043c4b0()))))->FUN_004a03c0();
    }
}

struct NiColorA004a4d40
{
    float r;
    float g;
    float b;
    float a;
};

struct NiPoint2_004a4d40
{
    float x;
    float y;
    NiPoint2_004a4d40(float x, float y);
};

struct Target004a4d40
{
    Point3 FUN_00413fc0() const;
};


// @fnv 0x004a4d40
void* __cdecl FUN_004a4d40(Target004a4d40* pTarget)
{
    {
        void* bResult = 0;

        if (3 == ((int)(uintptr_t)(reinterpret_cast<::Callees *>((pTarget))->FUN_00726070())))
        {
            NiColorA004a4d40 colorA;
            {
                Point3 w = pTarget->FUN_00413fc0() * 2.0f;
            }
            reinterpret_cast<::FUN_00413f90_cls *>((pTarget))->FUN_00413f90((::FUN_00413f90_vec *)(::NiColorA004a4d40 *)(&colorA));

            NiColorA004a4d40 kIter;
            {
                NiPoint2_004a4d40 point(pTarget->FUN_00413fc0().x * 2.0, pTarget->FUN_00413fc0().z * 2.0f);
                reinterpret_cast<::FUN_00413f90_cls *>((pTarget))->FUN_00413f90((::FUN_00413f90_vec *)(::NiColorA004a4d40 *)(&kIter));
                bResult = FUN_004a4f80((const float*)&point, (uintptr_t)&kIter);
            }
        }

        if (((int)(uintptr_t)(reinterpret_cast<::Callees *>((pTarget))->FUN_00726070())) == 1)
        {
            NiColorA004a4d40 colorA;
            {
                Point3 point = pTarget->FUN_00413fc0() * 2.0f;
                reinterpret_cast<::FUN_00413f90_cls *>((pTarget))->FUN_00413f90((::FUN_00413f90_vec *)(::NiColorA004a4d40 *)(&colorA));
                bResult = CreatePrimitiveBox(&point, (intptr_t)&colorA);
            }
        }

        if (((int)(uintptr_t)(reinterpret_cast<::Callees *>((pTarget))->FUN_00726070())) == 2)
        {
            NiColorA004a4d40 cnt;
            reinterpret_cast<::FUN_00413f90_cls *>((pTarget))->FUN_00413f90((::FUN_00413f90_vec *)(::NiColorA004a4d40 *)(&cnt));
            bResult = ((void *)(::fnv_004a5100::FUN_004a5100_create(reinterpret_cast<::BSMultiBoundSphere *>((void *)(pTarget))->GetRadius(), (intptr_t)(&cnt))));
        }

        return bResult;
    }
}


struct NodeAB;
struct ExtraAB;

struct AVObjAB
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual NodeAB* GetAsNode();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void* GetAsTriBasedGeom();
};

struct NodeAB : AVObjAB
{
    unsigned int FUN_0043b480();
};

struct GeomAB : AVObjAB
{
};

struct ListAB
{
    void* Find(AVObjAB* const& rkKey, void* pvPos);
};

struct ExtraAB
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    ListAB m_kList;
};

struct BipedAB
{
    void FUN_004ab130(AVObjAB* pkObject);
};

// @fnv 0x004ab130
void BipedAB::FUN_004ab130(AVObjAB* pkObject)
{
    if (!pkObject)
        return;
    AVObjAB* pkRootNode = ((::AVObjAB *)(reinterpret_cast<::BipedAnim *>(this)->GetBoneNode((::BIPED_BONE)(1))));
    ExtraAB* pkExtra = ((::ExtraAB *)(reinterpret_cast<::NiAVObject *>((pkRootNode))->GetExtraData(::FUN_004ab220())));
    if (!pkExtra)
        return;
    if (pkObject->GetAsTriBasedGeom())
    {
        GeomAB* pkGeom = (GeomAB*)pkObject;
        ExtraAB* pkList = pkExtra;
        if (((void *)(::fnv_0043fad0::FUN_0043fad0((const char *)(pkGeom)))))
        {
            if (pkList->m_kList.Find(pkGeom, 0))
                reinterpret_cast<::FUN_00a5be90_shell *>((pkRootNode))->DeleteExtraDataByKey(::FUN_004ab220());
        }
    }
    else
    {
        NodeAB* pkNode = pkObject->GetAsNode();
        if (pkNode)
        {
            for (unsigned int i = 0; i < pkNode->FUN_0043b480(); i++)
                FUN_004ab130(((::AVObjAB *)(reinterpret_cast<::NiNode *>((pkNode))->GetAt(i))));
        }
    }
}

struct AGItem
{
};
struct AGNode
{
};
struct AGList : AGNode
{
};
struct AGOwner
{
    AGList* m_pEntries;
    void* FUN_004bcd10();
};

// @fnv 0x004bcd10
void* AGOwner::FUN_004bcd10()
{
    AGNode* pNode = m_pEntries;
    void* pResult = 0;
    while (pNode && *((::AGItem **)(new ((void *)(pNode)) ::Vec3())))
    {
        AGItem* pItem = *((::AGItem **)(new ((void *)(pNode)) ::Vec3()));
        if (pItem && ((void *)(reinterpret_cast<::FUN_00418720_shell *>((pItem))->GetExtraLeveledItem())))
        {
            pResult = ((void *)(reinterpret_cast<::FUN_00418720_shell *>((pItem))->GetExtraLeveledItem()));
            reinterpret_cast<::FUN_00410020_t *>((pItem))->FUN_00410020((::BSExtraData *)(pResult), 0);
            if (reinterpret_cast<::ExtraDataList *>((pItem))->IsEmpty())
                reinterpret_cast<::ItemChangeListNode *>((m_pEntries))->FUN_00905330((*(::InventoryStackRecord *const *)(&pItem)));
            pNode = m_pEntries;
        }
        pNode = ((::AGNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return pResult;
}

class ListBase4A47B0
{
  public:
    ~ListBase4A47B0();
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};
class FUN_004a47b0 : public ListBase4A47B0
{
  public:
    ~FUN_004a47b0();
};

// Destructor that calls RemoveAll to clear the list before the object is destroyed.
// @fnv 0x004a47b0
FUN_004a47b0::~FUN_004a47b0()
{
    reinterpret_cast<::NiTPointerListBase<::NiTPointerAllocator<unsigned int>, void*> *>(this)->RemoveAll();
}

struct PointerMapBase4aa0f0
{
    virtual void Slot00();
    ~PointerMapBase4aa0f0();
};

struct FUN_004aa0f0 : PointerMapBase4aa0f0
{
    ~FUN_004aa0f0();
};

// Destructor that calls FUN_00438af0; the base destructor then runs implicitly.
// @fnv 0x004aa0f0
FUN_004aa0f0::~FUN_004aa0f0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

class FUN_004aa2e0
{
  public:
    virtual ~FUN_004aa2e0();

};

class FUN_004aa280 : public FUN_004aa2e0
{
  public:
    virtual ~FUN_004aa280();
};

// @fnv 0x004aa280
FUN_004aa280::~FUN_004aa280()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct FUN_0045cec0
{
    unsigned int value;
    ~FUN_0045cec0();
};
struct FUN_004a4bd0
{
    virtual ~FUN_004a4bd0();
    int m_0004, m_0008, m_000c, m_0010;
    int m_0014, m_0018, m_001c, m_0020;
    FUN_0045cec0 m_0024;
    FUN_0045cec0 m_0028;
    FUN_0045cec0 m_002c;
};
// Calls FUN_004a4bd0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004a4ba0
void* FUN_004a4bd0_shell::FUN_004a4ba0(unsigned int flags)
{
    reinterpret_cast<::FUN_004a4bd0 *>(this)->FUN_004a4bd0::~FUN_004a4bd0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that calls ClearSlots.
// @fnv 0x004a4bd0
FUN_004a4bd0::~FUN_004a4bd0()
{
    reinterpret_cast<::fnv_004a4c50::FUN_004a4c50_Class *>(this)->ClearSlots();
}

extern int DAT_0101ed4c;
struct S_004a99d0
{
    void* vtbl;
    int f04;
    void* p08;
    void FUN_004a99d0();
};
// @fnv 0x004a9a30
void* FUN_004a99d0_Class::FUN_004a9a30(unsigned int flags)
{
    reinterpret_cast<::S_004a99d0 *>(this)->FUN_004a99d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Stores &DAT_0101ed4c in the first member, calls RemoveAll treating this as an NiTPointerMap, then calls a function on p08.
// @fnv 0x004a99d0
void S_004a99d0::FUN_004a99d0()
{
    *(void**)this = (void*)&DAT_0101ed4c;
    reinterpret_cast<::FUN_00438af0_Class *>((((NiTPointerMap<void*, void*>*)(void*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(p08);
}

struct GlobalObject_004a9e90
{
    virtual ~GlobalObject_004a9e90();
};
struct FUN_004a9ec0 : GlobalObject_004a9e90
{
    virtual ~FUN_004a9ec0();
};
// @fnv 0x004a9ec0
FUN_004a9ec0::~FUN_004a9ec0()
{}

struct FUN_004aa050
{
    virtual ~FUN_004aa050();
};
// @fnv 0x004aa050
FUN_004aa050::~FUN_004aa050()
{}

struct FUN_004aa1e0
{
    virtual ~FUN_004aa1e0();
};
// @fnv 0x004aa1e0
FUN_004aa1e0::~FUN_004aa1e0()
{}

struct GlobalObject_004aff00
{
    ~GlobalObject_004aff00();
};
struct FUN_004b0190 : GlobalObject_004aff00
{
    virtual ~FUN_004b0190();
};
// Destructor with an empty body; the base class destructor runs implicitly.
// @fnv 0x004b0190
FUN_004b0190::~FUN_004b0190()
{}

#include "generated/data/staging/blk_004a0000_od.inc"
