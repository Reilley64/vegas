
// src/staging/blk_004e0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <new>
#include <cmath>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Cls58a0.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/DecalListManager.h"
#include "fnv/decl/EffectManager975.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0042e060_class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_0043b3b0_class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00456630_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00488ff0_shell.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_004dfdd0_StandIn.h"
#include "fnv/decl/FUN_004dfe80_Class.h"
#include "fnv/decl/FUN_004e45a0_shell.h"
#include "fnv/decl/FUN_004e45c0_shell.h"
#include "fnv/decl/FUN_004e45e0_shell.h"
#include "fnv/decl/FUN_004e4600_shell.h"
#include "fnv/decl/FUN_004e4620_shell.h"
#include "fnv/decl/FUN_004e4640_shell.h"
#include "fnv/decl/FUN_004e4660_shell.h"
#include "fnv/decl/FUN_004e4690_shell.h"
#include "fnv/decl/FUN_004ed960.h"
#include "fnv/decl/FUN_004ed9d0.h"
#include "fnv/decl/FUN_004eda60_t.h"
#include "fnv/decl/FUN_004edb60_t.h"
#include "fnv/decl/FUN_004edbd0.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f33c0_cls.h"
#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/FUN_004f6730_shell.h"
#include "fnv/decl/FUN_004f6de0_shell.h"
#include "fnv/decl/FUN_004f7e80_shell.h"
#include "fnv/decl/FUN_004f7f10_cls.h"
#include "fnv/decl/FUN_004f8030_shell.h"
#include "fnv/decl/FUN_004fd420_shell.h"
#include "fnv/decl/FUN_00527900_shell.h"
#include "fnv/decl/FUN_0052ce20_shell.h"
#include "fnv/decl/FUN_00575650_Class.h"
#include "fnv/decl/FUN_0057c850_cls.h"
#include "fnv/decl/FUN_00580080_shell.h"
#include "fnv/decl/FUN_005800a0_shell.h"
#include "fnv/decl/FUN_005800e0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_006c9900_shell.h"
#include "fnv/decl/FUN_007b52d0_cls.h"
#include "fnv/decl/FUN_008133b0_class.h"
#include "fnv/decl/FUN_00821640_shell.h"
#include "fnv/decl/FUN_00821660_shell.h"
#include "fnv/decl/FUN_00821680_Class.h"
#include "fnv/decl/FUN_0084d310_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00b9b7f0_cls.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Finder.h"
#include "fnv/decl/GList.h"
#include "fnv/decl/ImageSpaceManager.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/ListReader.h"
#include "fnv/decl/Manager.h"
#include "fnv/decl/NiCamera.h"
#include "fnv/decl/NiTPointerListBase.h"
#include "fnv/decl/Obj43c.h"
#include "fnv/decl/ObsList.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/PointObject.h"
#include "fnv/decl/Pool.h"
#include "fnv/decl/S_0043b320.h"
#include "fnv/decl/TESRegionList.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TESTopicInfoData.h"
#include "fnv/decl/TerminalCleanup.h"
#include "fnv/decl/TimeoutTimer.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WaterScanner_004e83e0.h"
#include "fnv/decl/fnv_0042e110__FUN_0042e110.h"
#include "fnv/decl/fnv_004e6620__WaterCleanup.h"
#include "fnv/decl/fnv_004edad0__FUN_004edad0.h"
#include "fnv/decl/fnv_004f7fa0__FUN_004f7fa0_shell.h"
#include "fnv/decl/fnv_004f9570__BGSConstructibleObject.h"
#include "fnv/decl/fnv_00564f40__XActor.h"
#include "fnv/decl/fnv_005f5f80__FUN_005f5f80_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00452000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_004e4000.h"
#include "fnv/symbols_004e7000.h"
#include "fnv/symbols_004f6000.h"
#include "fnv/symbols_004f7000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00567000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00644000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00966000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01189000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011c7000.h"
#include "fnv/symbols_011ce000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d6000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_011ff000.h"
#include "../../include/layout_support.h"

// Returns the smaller of the two arguments: a if a is less than b, otherwise b.
// @fnv 0x004e2050
double FUN_004e2050(float afValue, double b)
{
    double result;
    if (afValue < b)
        result = afValue;
    else
        result = b;
    return result;
}

struct FUN_004e2100_Class
{
    void SetByteAtOffset166(int value);
};

// @fnv 0x004e2100
void FUN_004e2100_Class::SetByteAtOffset166(int value)
{
    ((unsigned char*)this)[0x166] = (unsigned char)value;
}

struct BGSPlaceableWater
{
    bool HasFlags(unsigned int);
};

struct FUN_004e3280_shell
{
    BGSPlaceableWater* p;
    void FUN_004e3280();
};

// @fnv 0x004e3280
void FUN_004e3280_shell::FUN_004e3280()
{
    reinterpret_cast<BGSPlaceableWater*>(this)->HasFlags(0x200);
}

namespace fnv_004e3300 {
struct BGSPlaceableWater
{
};

struct FUN_004e3300_shell : BGSPlaceableWater
{
    void FUN_004e3300();
};

// @fnv 0x004e3300
void FUN_004e3300_shell::FUN_004e3300()
{
    reinterpret_cast<::BGSPlaceableWater *>(this)->HasFlags(0x40000);
}
}  // namespace fnv_004e3300

void ClearField();

struct FUN_004e3c00_Class
{
    void FUN_004e3c00();
};

// @fnv 0x004e3c00
void FUN_004e3c00_Class::FUN_004e3c00()
{
    if (*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3c))
    {
        reinterpret_cast<void(*)(void*)>(ClearField)(
            reinterpret_cast<void*>(*reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x3c)));
    }
}

struct FUN_004e3c20_class
{
    void ClearField();
};

// @fnv 0x004e3c20
void FUN_004e3c20_class::ClearField()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10) = 0;
}

namespace fnv_004e3c50 {
struct BGSPlaceableWater
{
    bool FUN_004e3c50();
};

// @fnv 0x004e3c50
bool BGSPlaceableWater::FUN_004e3c50()
{
    return reinterpret_cast<::BGSPlaceableWater *>(this)->HasFlags(1);
}
}  // namespace fnv_004e3c50

namespace fnv_004e3c70 {
struct BGSPlaceableWater
{
    bool HasFlags(unsigned int a);
};

bool BGSPlaceableWater::HasFlags(unsigned int a)
{
    return a == 0x80000000;
}

struct FUN_004e3c70_shell : BGSPlaceableWater
{
    bool FUN_004e3c70();
};

// @fnv 0x004e3c70
bool FUN_004e3c70_shell::FUN_004e3c70()
{
    return !reinterpret_cast<::BGSPlaceableWater *>(this)->HasFlags(0x80000000);
}
}  // namespace fnv_004e3c70

namespace fnv_004e3ca0 {
struct BGSPlaceableWater
{
    void FUN_004e3ca0();
};
// @fnv 0x004e3ca0
void BGSPlaceableWater::FUN_004e3ca0()
{
    reinterpret_cast<::BGSPlaceableWater *>(this)->HasFlags(0x20000000);
}
}  // namespace fnv_004e3ca0

struct FUN_004e3cc0_Class
{
    float GetFloatAtOffset9C();
};

// @fnv 0x004e3cc0
float FUN_004e3cc0_Class::GetFloatAtOffset9C()
{
    return *(float*)((char*)this + 0x9c);
}

struct FUN_004e3ce0_class
{
    float FUN_004e3ce0() const;
};

// @fnv 0x004e3ce0
float FUN_004e3ce0_class::FUN_004e3ce0() const
{
    return *(const float*)((const char*)this + 0x108);
}

struct FUN_004e3d20_class
{
    float GetFloatAtOffset128();
};

// @fnv 0x004e3d20
float FUN_004e3d20_class::GetFloatAtOffset128()
{
    return *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x128);
}

struct FUN_004e3d40_Class
{
    float GetFloatAtOffset12C();
};

// @fnv 0x004e3d40
float FUN_004e3d40_Class::GetFloatAtOffset12C()
{
    return *(float*)((char*)this + 0x12c);
}

float FUN_004e44d0(float);

// @fnv 0x004e44b0
float FUN_004e44b0(float value)
{
    return FUN_004e44d0(value);
}

struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
// @fnv 0x004e89e0
unsigned char FUN_004e89e0()
{
    return *(*reinterpret_cast<::GlobalObject_0045cf30 *>(&::g_011c7ac4)).Bool();
}

struct Flt
{
    operator unsigned int();
};
struct FUN_004ea9e0_Class
{
    NiNode* FUN_004ea9e0();
};
// @fnv 0x004ea9e0
NiNode* FUN_004ea9e0_Class::FUN_004ea9e0()
{
    return (NiNode*)((Flt*)&(*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d86bc)))->operator unsigned int();
}

extern "C" void* DAT_010231f4;
struct FUN_004ed7a0_class
{
    void* m_ptr;
    void* FUN_004ed7a0(void* a);
};
// Calls FUN_004ed960(a), sets m_ptr to &DAT_010231f4, and returns this.
// @fnv 0x004ed7a0
void* FUN_004ed7a0_class::FUN_004ed7a0(void* apArg)
{
    reinterpret_cast<::FUN_004ed960 *>(this)->Init((unsigned int)(apArg));
    m_ptr = &DAT_010231f4;
    return this;
}

extern int DAT_01023214;

struct FUN_004ed7d0_class
{
    int* p;
    FUN_004ed7d0_class* FUN_004ed7d0(int a);
};

// Calls FUN_004eda60 with a, sets p to point at DAT_01023214, and returns this.
// @fnv 0x004ed7d0
FUN_004ed7d0_class* FUN_004ed7d0_class::FUN_004ed7d0(int a)
{
    reinterpret_cast<::FUN_004eda60_t *>(this)->FUN_004eda60(a);
    p = &DAT_01023214;
    return this;
}

extern "C" void __cdecl FUN_004edb60(int);
extern int DAT_01023234;

struct FUN_004ed800Class
{
    int* p;
    void FUN_004edb60(int arg);
    FUN_004ed800Class* FUN_004ed800(int arg);
};

// Calls FUN_004edb60 with arg, sets p to point at DAT_01023234, and returns this.
// @fnv 0x004ed800
FUN_004ed800Class* FUN_004ed800Class::FUN_004ed800(int aiValue)
{
    reinterpret_cast<::FUN_004edb60_t *>((this))->FUN_004edb60(aiValue);
    p = &DAT_01023234;
    return this;
}

struct FUN_0043ba10_shell
{
    FUN_0043ba10_shell* FUN_0043ba10(FUN_0043ba10_shell*);
};

struct FUN_004eeae0_shell
{
    void FUN_004eeae0(int arg);
};

// @fnv 0x004eeae0
void FUN_004eeae0_shell::FUN_004eeae0(int arg)
{
    ((FUN_0043ba10_shell*)((char*)this + 0x5c))->FUN_0043ba10((FUN_0043ba10_shell*)arg);
}

struct FUN_00456630_helper
{
};

struct FUN_004f0140_class
{
    bool FUN_004f0140();
};

// @fnv 0x004f0140
bool FUN_004f0140_class::FUN_004f0140()
{
    return ((bool)(reinterpret_cast<::FUN_00456630_Class *>((((FUN_00456630_helper*)this)))->FUN_00456630(2)));
}

struct FUN_004f0360_class
{
    bool HasFlag(unsigned short mask);
};
// @fnv 0x004f0360
bool FUN_004f0360_class::HasFlag(unsigned short mask)
{
    return (*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 8) & mask) != 0;
}

struct FUN_004f05a0_Class
{
    void FUN_004f05a0();
};

// @fnv 0x004f05a0
void FUN_004f05a0_Class::FUN_004f05a0()
{
    reinterpret_cast<::FUN_004f0360_class *>(this)->HasFlag(8);
}

struct TaskQueueInterface
{
    void FUN_004f2620(bool enabled);
public:
    static void CopyStringToBuffer(char *, unsigned int, const char *);
public:
    void QueueActorDisarm(bool);
};

// @fnv 0x004f2620
void TaskQueueInterface::FUN_004f2620(bool enabled)
{
    reinterpret_cast<::FUN_0043b370_cls *>(this)->FUN_0043b370(enabled, 0x10000000);
}

struct FUN_004f2770_Class
{
    void* FUN_004f2770();
};

// @fnv 0x004f2770
void* FUN_004f2770_Class::FUN_004f2770()
{
    return reinterpret_cast<char*>(this) + 0x764;
}

struct GlobalObject_00633c90;

struct GO
{
    void operator=(void*);
};

// @fnv 0x004f3310
void __cdecl ClearGlobalObjects()
{
    *(GO*)&::g_011c7f0c = 0;
    *(GO*)&::g_011c7ef8 = 0;
}

struct FUN_004f3660_class
{
    const char* p;
    int v;
    FUN_004f3660_class* FUN_004f3660();
};

// Sets the object's p field to "p`r" and v to 0, then returns this.
// @fnv 0x004f3660
FUN_004f3660_class* FUN_004f3660_class::FUN_004f3660()
{
    p = "p`r";
    v = 0;
    return this;
}

struct S7010
{
    unsigned int GetLengthPlusOne();
};

// @fnv 0x004f4280
unsigned int S7010::GetLengthPlusOne()
{
    return ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(this)->FUN_004048e0())) + 1;
}

struct FUN_004f6fc0_shell
{
    void FUN_004f6fc0();
    FUN_004f6fc0_shell* FUN_004f87e0();
};

// @fnv 0x004f87e0
FUN_004f6fc0_shell* FUN_004f6fc0_shell::FUN_004f87e0()
{
    FUN_004f6fc0();
    return this;
}

struct FUN_004f8a60_class
{
    void FUN_004f8ac0(int);
    void SetField108(int);
};

// Calls FUN_004f8ac0(0) and stores a at offset 0x108 of this object.
// @fnv 0x004f8a60
void FUN_004f8a60_class::SetField108(int aiValue)
{
    FUN_004f8ac0(0);
    *(int*)((char*)this + 0x108) = aiValue;
}

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct FUN_004f8a90_Class
{
    void FUN_004f8a90(unsigned int key, unsigned int& value);
};

// Looks up the value for key in the DummyPointerMap at offset 0x10c of this object and writes it to value.
// @fnv 0x004f8a90
void FUN_004f8a90_Class::FUN_004f8a90(unsigned int key, unsigned int& value)
{
    reinterpret_cast<::fnv_00853130::NiTMapBase *>((((DummyPointerMap*)((char*)this + 0x10c))))->FUN_00853130(key, (::fnv_00853130::CombatThreatRecord *&)(value));
}

struct FileEntryList
{
};

struct FUN_004f9ef0_shell
{
    int m0;
    int m1;
    FileEntryList m2;
    void CallInnerMethod();
};

// @fnv 0x004f9ef0
void FUN_004f9ef0_shell::CallInnerMethod()
{
    reinterpret_cast<::FUN_00488ff0_shell *>(&(m2))->FUN_00488ff0();
}

struct FUN_004fb970_class
{
    unsigned char GetByteAtOffsetD9() const;
};

// @fnv 0x004fb970
unsigned char FUN_004fb970_class::GetByteAtOffsetD9() const
{
    return ((const unsigned char*)this)[0xd9];
}

struct MagicProjectile
{
    EffectSetting* FUN_004fd400();
};

// @fnv 0x004fd400
EffectSetting* MagicProjectile::FUN_004fd400()
{
    return *(EffectSetting**)((char*)this + 0xa0);
}

struct FUN_004fd4f0_Class
{
    int FUN_004fd4f0();
};

// @fnv 0x004fd4f0
int FUN_004fd4f0_Class::FUN_004fd4f0()
{
    return *(int*)((char*)this + 0x60) & 0x1f0000;
}

struct BGSProjectile
{
    bool FUN_004fdf20() const;
};

// @fnv 0x004fdf20
bool BGSProjectile::FUN_004fdf20() const
{
    return reinterpret_cast<::FUN_004fd420_shell *>((void *)this)->FUN_004fd420(0x20);
}

namespace fnv_004fdf40 {
struct BGSProjectile
{
    bool FUN_004fdf40();
};

// @fnv 0x004fdf40
bool BGSProjectile::FUN_004fdf40()
{
    return reinterpret_cast<::FUN_004fd420_shell *>((void *)this)->FUN_004fd420(0x40);
}
}  // namespace fnv_004fdf40

struct FUN_004ffa60_class
{
    float f;
    int i;
    FUN_004ffa60_class* FUN_004ffa60(const FUN_004ffa60_class* src);
};

// Copies the float field from src into this object and resets the int field to zero, then returns this.
// @fnv 0x004ffa60
FUN_004ffa60_class* FUN_004ffa60_class::FUN_004ffa60(const FUN_004ffa60_class* apSource)
{
    f = apSource->f;
    i = 0;
    return this;
}

struct FUN_004ed830_Class
{
    void* FUN_004ed830(unsigned int flags);
};
// Calls FUN_004ed9d0, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x004ed830
void* FUN_004ed830_Class::FUN_004ed830(unsigned int flags)
{
    reinterpret_cast<::FUN_004ed9d0 *>(this)->FUN_004ed9d0::~FUN_004ed9d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004edad0_shell
{
};
struct FUN_004ed860_class
{
    void* FUN_004ed860(unsigned int flags);
};
// Calls FUN_004edad0 on this, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x004ed860
void* FUN_004ed860_class::FUN_004ed860(unsigned int flags)
{
    reinterpret_cast<::fnv_004edad0::FUN_004edad0 *>((((FUN_004edad0_shell*)this)))->fnv_004edad0::FUN_004edad0::~FUN_004edad0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004ed890_Class
{
    void* FUN_004ed890(unsigned int flags);
};
// Calls FUN_004edbd0, frees this via Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x004ed890
void* FUN_004ed890_Class::FUN_004ed890(unsigned int flags)
{
    reinterpret_cast<::FUN_004edbd0 *>(this)->FUN_004edbd0::~FUN_004edbd0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern unsigned int DAT_011c7870;
// If DAT_011c7870 is nonzero, clamps it to 0x14, passes it to FUN_0040fca0, then resets DAT_011c7870 to 0.
// @fnv 0x004e1610
void FUN_004e1610()
{
    if (DAT_011c7870 != 0)
    {
        if (DAT_011c7870 > 0x14)
        {
            DAT_011c7870 = 0x14;
        }
        FUN_0040fca0(DAT_011c7870);
        DAT_011c7870 = 0;
    }
}

// Returns the larger of the two arguments, comparing the float a against the double b.
// @fnv 0x004e2080
double FUN_004e2080(float afValue, double b)
{
    double r;
    if (afValue > b)
        r = afValue;
    else
        r = b;
    return r;
}


// @fnv 0x004e20b0
void FUN_004e20b0(unsigned char value)
{
    DAT_011ad7b4 = value;
}

// @fnv 0x004e20f0
void FUN_004e20f0(unsigned char value)
{
    DAT_011f91c4 = value;
}

struct GlobalObject_00633c90;

// @fnv 0x004e7ff0
unsigned int FUN_004e7ff0()
{
    return ((Flt*)&::g_011c7c28)->operator unsigned int();
}

namespace fnv_004e8000 {
struct NiNode
{
};

// If the global object holds a non-null pointer, calls FUN_004def90 on it, then assigns 0 to the global object.
// @fnv 0x004e8000
void FUN_004e8000()
{
    if (reinterpret_cast<Flt*>(&::g_011c7c28)->operator unsigned int())
        reinterpret_cast<::FUN_004def90_Class *>((reinterpret_cast<NiNode*>(reinterpret_cast<Flt*>(&::g_011c7c28)->operator unsigned int())))->FUN_004def90();
    reinterpret_cast<GO*>(&::g_011c7c28)->operator=(0);
}
}  // namespace fnv_004e8000

struct FUN_004e8910_Class
{
    float f0;
    float f4;
    FUN_004e8910_Class* Subtract(FUN_004e8910_Class* other);
};
// Subtracts the other object's f0 and f4 from this object's f0 and f4 and returns this.
// @fnv 0x004e8910
FUN_004e8910_Class* FUN_004e8910_Class::Subtract(FUN_004e8910_Class* other)
{
    f0 -= other->f0;
    f4 -= other->f4;
    return this;
}

struct FUN_004f0110_Data
{
    int v[9];
};
struct FUN_004f0110_Holder
{
    char pad[0x2c];
    FUN_004f0110_Data d;
    void FUN_004f0110(FUN_004f0110_Data* src);
};
// Copies the nine-int data block pointed to by src into the holder's d field.
// @fnv 0x004f0110
void FUN_004f0110_Holder::FUN_004f0110(FUN_004f0110_Data* pSource)
{
    d = *pSource;
}

struct Modifier
{
};
extern float DAT_01023900;
struct FUN_004f02e0_This
{
    unsigned char _pad[12];
    Modifier mod;
    bool FUN_004f02e0();
};
// Returns true when the modifier's value differs from the negated DAT_01023900 constant.
// @fnv 0x004f02e0
bool FUN_004f02e0_This::FUN_004f02e0()
{
    return reinterpret_cast<::TimeoutTimer *>(&(mod))->FUN_006b9130() != -DAT_01023900;
}

extern "C" float DAT_01023900;
struct FUN_004f0320_class
{
    bool FUN_004f0320();
};
// Returns whether the float at this+0x1c differs from the negation of DAT_01023900.
// @fnv 0x004f0320
bool FUN_004f0320_class::FUN_004f0320()
{
    return *(float*)((char*)this + 0x1c) != -DAT_01023900;
}

struct FUN_004f32e0_class
{
    void SetMaskedBits(unsigned short set, unsigned short clear, unsigned short shift);
};
// Clears the bits in clear and sets the shifted set bits in the 16-bit field at offset 4 of this object.
// @fnv 0x004f32e0
void FUN_004f32e0_class::SetMaskedBits(unsigned short set, unsigned short clear, unsigned short shift)
{
    *(unsigned short*)((char*)this + 4) = (*(unsigned short*)((char*)this + 4) & ~clear) | (set << shift);
}

struct SL
{
    int _0;
    int _4;
    SL();
};
struct FUN_004f3330 : SL
{
    bool m_8;
    FUN_004f3330(bool v);
};
// Constructs the object and stores the given bool into m_8.
// @fnv 0x004f3330
FUN_004f3330::FUN_004f3330(bool abValue)
{
    m_8 = abValue;
}

struct FUN_004f5600_shell
{
    FUN_004f5600_shell();
};
extern int DAT_01023ec4;
struct FUN_004f5590 : FUN_004f5600_shell
{
    int m4;
    int m8;
    FUN_004f5590(int, int);
};
// @fnv 0x004f5590
FUN_004f5590::FUN_004f5590(int aiFirst, int aiSecond)
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_01023ec4);
    this->m8 = aiFirst;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8) = aiSecond;
}

namespace fnv_004f5db0 {
struct SL
{
    int m0;
    int m1;
    SL();
};
struct FUN_004f5db0 : SL
{
    virtual ~FUN_004f5db0();
    unsigned char mC;
    int m10;
    FUN_004f5db0(unsigned char a);
};
// Initializes the object by storing the byte argument in mC and setting m10 to zero.
// @fnv 0x004f5db0
FUN_004f5db0::FUN_004f5db0(unsigned char aucValue)
{
    mC = aucValue;
    m10 = 0;
}
}  // namespace fnv_004f5db0

struct NiPoint3
{
    float GetLengthSquared();
};
struct Vec3i
{
    int x;
    int y;
    int z;
};
// @fnv 0x004f6e00
float FUN_004f6e00(int aiX, int aiY, int aiZ)
{
    Vec3i v;
    float len;
    v.x = aiX;
    v.y = aiY;
    v.z = aiZ;
    len = ((NiPoint3*)&v)->GetLengthSquared();
    return FUN_004f6e40(*(float*)&v.z / len);
}

struct BaseS
{
    int m0;
    int m1;
    BaseS();
};
struct FUN_004f7000 : BaseS
{
    FUN_004f7000(BaseS* p);
};
// @fnv 0x004f7000
FUN_004f7000::FUN_004f7000(BaseS* apSource) : BaseS()
{
    *(BaseS*)this = *apSource;
}

namespace fnv_004f7030 {
struct BaseS
{
    BaseS();
};
struct Modifier
{
};
struct AlphaColor
{
};
struct FUN_004f7030 : BaseS
{
    FUN_004f7030(float* p);
};
// Initializes the object by passing p[0] to FUN_0052ce20 and p[1] to SetValue.
// @fnv 0x004f7030
FUN_004f7030::FUN_004f7030(float* afPair)
{
    reinterpret_cast<::FUN_0052ce20_shell *>((((AlphaColor*)this)))->FUN_0052ce20(afPair[0]);
    reinterpret_cast<::FUN_004f5d90_shell *>((((Modifier*)this)))->FUN_004f5d90(afPair[1]);
}
}  // namespace fnv_004f7030

namespace fnv_004f7070 {
struct Modifier
{
};
struct AlphaColor
{
};
struct BaseS
{
};
struct FUN_004f7070_shell
{
    void* SetValues(float, float);
};
// Calls _ref_006815c0, then FUN_0052ce20 with a and SetValue with b, and returns this.
// @fnv 0x004f7070
void* FUN_004f7070_shell::SetValues(float afFirst, float afSecond)
{
    new ((void *)(((BaseS*)this))) ::Vec3();
    reinterpret_cast<::FUN_0052ce20_shell *>((((AlphaColor*)this)))->FUN_0052ce20(afFirst);
    reinterpret_cast<::FUN_004f5d90_shell *>((((Modifier*)this)))->FUN_004f5d90(afSecond);
    return this;
}
}  // namespace fnv_004f7070

struct FUN_004f71f0_Class
{
    float SquaredDistanceTo(int);
    float FUN_004f71f0(int);
};
// @fnv 0x004f71f0
float FUN_004f71f0_Class::FUN_004f71f0(int a)
{
    if (a == 0)
        return -1.0f;
    return ConvertDoubleResult(SquaredDistanceTo(a));
}

namespace fnv_004f7230 {
struct RegionPoint
{
};
struct Modifier
{
};
struct FUN_004f7230_Class
{
    float SquaredDistanceTo(RegionPoint* other) const;
};
// Returns the squared distance between this object and other using GetValue and GetX, or -1.0f when other is null.
// @fnv 0x004f7230
float FUN_004f7230_Class::SquaredDistanceTo(RegionPoint* other) const
{
    if (!other)
        return -1.0f;
    float fDeltaValue = reinterpret_cast<::CombatTargetTimestamp *>((void *)(((Modifier*)this)))->FUN_006a7f50() - reinterpret_cast<::CombatTargetTimestamp *>((void *)(((Modifier*)other)))->FUN_006a7f50();
    float fDeltaX = reinterpret_cast<::TimeoutTimer *>((void *)(((RegionPoint*)this)))->FUN_006b9130() - reinterpret_cast<::TimeoutTimer *>((void *)(((RegionPoint*)other)))->FUN_006b9130();
    return fDeltaValue * fDeltaValue + fDeltaX * fDeltaX;
}
}  // namespace fnv_004f7230

struct TaskQueueAttachHelper
{
};
// @fnv 0x004f8ac0
void FUN_004f8a60_class::FUN_004f8ac0(int apSource)
{
    if (apSource)
        ::TaskQueueInterface::CopyStringToBuffer((char*)this + 4, 0x104, (const char*)apSource);
    else
        ((char*)this)[4] = 0;
}

struct BGSTalkingActivator
{
    bool IsRadioStation();
};
struct ArrSI
{
    bool HasFlag10000000();
};
struct S_004fee20
{
    bool FUN_004fee20();
};
// Returns true when the talking activator is a radio station and the associated check succeeds.
// @fnv 0x004fee20
bool S_004fee20::FUN_004fee20()
{
    return ((BGSTalkingActivator*)this)->IsRadioStation() && ((ArrSI*)this)->HasFlag10000000();
}

namespace fnv_004fee60 {
struct TESForm
{
    int GetFormType() const;
};
struct BGSTalkingActivator
{
};
struct FUN_004fee20_shell
{
};
// Returns true if form is a talking activator (type 0x16) that is a radio station and passes the FUN_004fee20 check.
// @fnv 0x004fee60
bool IsRadioStationTalkingActivator(TESForm* form)
{
    bool result = false;
    if (form && form->GetFormType() == 0x16)
    {
        BGSTalkingActivator* activator = (BGSTalkingActivator*)form;
        if (reinterpret_cast<::BGSTalkingActivator *>((void *)(activator))->IsRadioStation() && reinterpret_cast<::S_004fee20 *>((void *)(((FUN_004fee20_shell*)activator)))->FUN_004fee20())
            result = true;
    }
    return result;
}
}  // namespace fnv_004fee60

struct FUN_004e83e0_class
{
};
struct NiTPointerList
{
};
struct FUN_006317a0_struct
{
    int AddEight(int);
};
struct FUN_004e8950_class
{
    bool FUN_004e8950();
};
// Iterates the list at offset 0x3c and returns true if IsPlayerNearWaterActor accepts any referenced object, otherwise false.
// @fnv 0x004e8950
bool FUN_004e8950_class::FUN_004e8950()
{
    if (FUN_004e89e0())
    {
        unsigned int count = *reinterpret_cast<Flt*>(reinterpret_cast<unsigned char*>(this) + 0x3c);
        void* next = 0;
        while (count)
        {
            next = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>((reinterpret_cast<NiTPointerList*>(reinterpret_cast<unsigned char*>(this) + 0x3c)))->DereferenceIfNotNull((int **)(void *)(reinterpret_cast<void*>(count)))));
            if (count)
            {
                TESObjectREFR* item = *reinterpret_cast<TESObjectREFR**>(
                    reinterpret_cast<FUN_006317a0_struct*>(reinterpret_cast<unsigned char*>(this) + 0x3c)
                        ->AddEight(count));
                if (reinterpret_cast<::WaterScanner_004e83e0 *>((reinterpret_cast<FUN_004e83e0_class*>(this)))->IsPlayerNearWaterActor(item))
                    return true;
            }
            count = reinterpret_cast<unsigned int>(next);
        }
    }
    return false;
}

struct RDLItem
{
    virtual ~RDLItem();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual RDLItem* Clone();
};
struct RDLNode
{
    RDLItem** FUN_006815c0();
};
struct RDL_004f3330
{
    int list[2];
    bool owns;
    RDL_004f3330(bool owns);
    RDL_004f3330* FUN_004f3470(RDL_004f3330* dest);
};
// Copies each item of the node list into dest (or a new list), cloning items when the list owns them, and returns the destination list.
// @fnv 0x004f3470
RDL_004f3330* RDL_004f3330::FUN_004f3470(RDL_004f3330* dest)
{
    RDLNode* node = (RDLNode*)this;
    {
        RDL_004f3330* result = dest ? dest : new RDL_004f3330(owns);
        {
            RDLItem* copy = 0;
            while (node)
            {
                if (result->owns)
                {
                    copy = (*((::RDLItem **)(new ((void *)(node)) ::Vec3())))->Clone();
                    if (!reinterpret_cast<::FUN_004f33c0_cls *>((result))->FUN_004f33c0((::ProbeBase *)(copy)))
                        delete copy;
                }
                else
                {
                    reinterpret_cast<::FUN_004f33c0_cls *>((result))->FUN_004f33c0((::ProbeBase *)(*((::RDLItem **)(new ((void *)(node)) ::Vec3()))));
                }
                node = ((::RDLNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            }
            return result;
        }
    }
}

struct RegionPoint
{
    float GetZ();
};
struct FUN_004f70b0_Class
{
    bool FUN_004f70b0(RegionPoint* other);
};
// @fnv 0x004f70b0
bool FUN_004f70b0_Class::FUN_004f70b0(RegionPoint* other)
{
    if (FUN_0040eb10(reinterpret_cast<::CombatTargetTimestamp *>((((RegionPoint*)this)))->FUN_006a7f50(), reinterpret_cast<::CombatTargetTimestamp *>((other))->FUN_006a7f50(), 0.001f) &&
        FUN_0040eb10(reinterpret_cast<::TimeoutTimer *>((((RegionPoint*)this)))->FUN_006b9130(), reinterpret_cast<::TimeoutTimer *>((other))->FUN_006b9130(), 0.001f))
        return true;
    return false;
}

extern int DAT_010245a4;
extern int DAT_0102458c;
extern int DAT_01024568;
extern int DAT_01024548;
extern int DAT_01024534;
extern int DAT_01024514;
extern int DAT_01024500;
extern int DAT_010244ec;
extern int DAT_010244d8;
extern int DAT_010244c4;

struct TESObjectMISC
{
    TESObjectMISC();
    ~TESObjectMISC();
};

struct FUN_004f93b0 : public TESObjectMISC
{
    FUN_004f93b0();
};

// @fnv 0x004f93b0
FUN_004f93b0::FUN_004f93b0()
{
    *reinterpret_cast<void**>(this) = &DAT_010245a4;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x30) = &DAT_0102458c;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x3c) = &DAT_01024568;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x5c) = &DAT_01024548;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x68) = &DAT_01024534;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x74) = &DAT_01024514;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x7c) = &DAT_01024500;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x84) = &DAT_010244ec;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x8c) = &DAT_010244d8;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0x9c) = &DAT_010244c4;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x32);
    reinterpret_cast<::fnv_004f9570::BGSConstructibleObject *>(this)->FUN_004f9570();
}

extern int DAT_010232b4;
struct NiTMallocInterface_0096afc0
{
    static void* __cdecl Allocate(unsigned short size);
};
struct FUN_004edf70
{
    int* vtbl;
    void* data;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    FUN_004edf70(unsigned short x, unsigned short y);
};
// Sets the vtable, stores x and y into a and d, zeroes b and c, and allocates a bytes for data when a is greater than zero, otherwise sets data to null.
// @fnv 0x004edf70
FUN_004edf70::FUN_004edf70(unsigned short ausSize, unsigned short y)
{
    vtbl = &DAT_010232b4;
    a = ausSize;
    d = y;
    b = 0;
    c = 0;
    if (a > 0)
        data = NiTMallocInterface_0096afc0::Allocate(a);
    else
        data = 0;
}

namespace fnv_004edfe0 {
struct ActorCombatGroup;
struct NiTMallocInterface_0096afc0
{
    static ActorCombatGroup** __cdecl Allocate(unsigned short);
};
struct FUN_004edfe0
{
    int* p;
    ActorCombatGroup** data;
    unsigned short count;
    unsigned short m0a;
    unsigned short m0c;
    unsigned short m0e;
    FUN_004edfe0(unsigned short a, unsigned short b);
};
// @fnv 0x004edfe0
FUN_004edfe0::FUN_004edfe0(unsigned short ausCount, unsigned short b)
{
    p = &::fnv_004edcc0::DAT_010232c4;
    count = ausCount;
    m0e = b;
    m0a = 0;
    m0c = 0;
    if (count > 0)
        data = NiTMallocInterface_0096afc0::Allocate(count);
    else
        data = 0;
}
}  // namespace fnv_004edfe0

struct NiPointer_004ee2e0
{
    void* m_pObject;
    NiPointer_004ee2e0(void*);
    ~NiPointer_004ee2e0();
};

struct GlobalObject_004ee810
{
};

// Wraps p in a NiPointer, removes it from g_011d6a30, then decrements DAT_011d6a20.
// @fnv 0x004ee2e0
void __cdecl FUN_004ee2e0(void* apObject)
{
    {
        NiPointer_004ee2e0 tmp(apObject);
        reinterpret_cast<::ListReader *>(&(::g_011d6a30))->FUN_00631620((const ::NodeValue &)(tmp));
    }
    DAT_011d6a20 -= 1;
}

struct FUN_004ede90_Class
{
    void* m0;  // +0x0
    int m4;    // +0x4
    int m8;    // +0x8
    void* InsertBefore(void* a, void** b);
};

// Links b into the doubly linked list before a, fixes the head pointer when a has no predecessor, and increments the count.
// @fnv 0x004ede90
void* FUN_004ede90_Class::InsertBefore(void* apNode, void** apNewNode)
{
    void* local = apNode;
    *apNewNode = local;
    *((void**)((char*)apNewNode + 4)) = *((void**)((char*)local + 4));
    if (*((void**)((char*)local + 4)) != 0)
    {
        *((void**)*((void**)((char*)local + 4))) = apNewNode;
    }
    else
    {
        this->m0 = apNewNode;
    }
    *((void**)((char*)local + 4)) = apNewNode;
    this->m8 = this->m8 + 1;
    return apNewNode;
}

namespace fnv_004f0640 {
struct NiAVObject;

struct NiNode
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int index);
};

struct NiAVObject
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual NiNode* GetNode();
};

struct FUN_0043b3b0_class
{
};

struct S_0043b320
{
};

struct NiInterpController
{
    static unsigned short INVALID_INDEX;
    void FUN_004f0640(NiAVObject* object);
};

// @fnv 0x004f0640
void NiInterpController::FUN_004f0640(NiAVObject* object)
{
    if (object)
    {
        unsigned short index;
        index = reinterpret_cast<::FUN_0043b3b0_class *>((reinterpret_cast<FUN_0043b3b0_class*>(this)))->FUN_0043b3b0(reinterpret_cast<unsigned int>(object));

        if (index != NiInterpController::INVALID_INDEX)
        {
            reinterpret_cast<::S_0043b320 *>((reinterpret_cast<S_0043b320*>(this)))->FUN_0043b320(index, 0);
        }
    }

    NiNode* node;
    node = object->GetNode();
    if (node)
    {
        unsigned int i;
        for (i = 0; i < node->GetNumChildren(); ++i)
        {
            this->FUN_004f0640(node->GetAt(i));
        }
    }
}
}  // namespace fnv_004f0640

class NiAVObject;

class NiNode
{
  public:
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int index);
};

class NiUpdateData;
class NiAVObject
{
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual NiNode* GetController();
public:
    void UpdateTimeControllers(::NiUpdateData &, bool);
};

class NiInterpController
{
  public:
    static unsigned short INVALID_INDEX;
};

class FUN_00a35fc0_shell
{
  public:
    void SetSlotValue(unsigned short index, void* data);
};

class FUN_00a35910_shell : public FUN_00a35fc0_shell
{
  public:
    void FUN_004f06d0(NiAVObject* object);
public:
    unsigned short FindIndexByValue(NiAVObject*);
};

// @fnv 0x004f06d0
void FUN_00a35910_shell::FUN_004f06d0(NiAVObject* object)
{
    NiNode* node;
    {
        FUN_00a35910_shell* self = this;

        if (object)
        {
            unsigned short index = self->FindIndexByValue(object);
            if (index != NiInterpController::INVALID_INDEX)
                self->SetSlotValue(index, 0);
        }

        node = object->GetController();
        if (node)
        {
            for (unsigned int i = 0; i < node->GetNumChildren(); ++i)
                this->FUN_004f06d0(node->GetAt(i));
        }
    }
}

struct FUN_00564f00_shell
{
    bool FUN_00564f00();
};

struct FUN_00564f40_shell
{
};

struct LodObject
{
    virtual void v0()
    {}
    virtual void v1()
    {}
    virtual void v2()
    {}
    virtual void v3()
    {}
    virtual TaskQueueInterface* v4();
};

struct TESSound
{
    virtual void v000()
    {}
    virtual void v001()
    {}
    virtual void v002()
    {}
    virtual void v003()
    {}
    virtual void v004()
    {}
    virtual void v005()
    {}
    virtual void v006()
    {}
    virtual void v007()
    {}
    virtual void v008()
    {}
    virtual void v009()
    {}
    virtual void v010()
    {}
    virtual void v011()
    {}
    virtual void v012()
    {}
    virtual void v013()
    {}
    virtual void v014()
    {}
    virtual void v015()
    {}
    virtual void v016()
    {}
    virtual void v017()
    {}
    virtual void v018()
    {}
    virtual void v019()
    {}
    virtual void v020()
    {}
    virtual void v021()
    {}
    virtual void v022()
    {}
    virtual void v023()
    {}
    virtual void v024()
    {}
    virtual void v025()
    {}
    virtual void v026()
    {}
    virtual void v027()
    {}
    virtual void v028()
    {}
    virtual void v029()
    {}
    virtual void v030()
    {}
    virtual void v031()
    {}
    virtual void v032()
    {}
    virtual void v033()
    {}
    virtual void v034()
    {}
    virtual void v035()
    {}
    virtual void v036()
    {}
    virtual void v037()
    {}
    virtual void v038()
    {}
    virtual void v039()
    {}
    virtual void v040()
    {}
    virtual void v041()
    {}
    virtual void v042()
    {}
    virtual void v043()
    {}
    virtual void v044()
    {}
    virtual void v045()
    {}
    virtual void v046()
    {}
    virtual void v047()
    {}
    virtual void v048()
    {}
    virtual void v049()
    {}
    virtual void v050()
    {}
    virtual void v051()
    {}
    virtual void v052()
    {}
    virtual void v053()
    {}
    virtual void v054()
    {}
    virtual void v055()
    {}
    virtual void v056()
    {}
    virtual void v057()
    {}
    virtual void v058()
    {}
    virtual void v059()
    {}
    virtual void v060()
    {}
    virtual void v061()
    {}
    virtual void v062()
    {}
    virtual void v063()
    {}
    virtual void v064()
    {}
    virtual void v065()
    {}
    virtual void v066()
    {}
    virtual void v067()
    {}
    virtual void v068()
    {}
    virtual void v069()
    {}
    virtual void v070()
    {}
    virtual void v071()
    {}
    virtual void v072()
    {}
    virtual void v073()
    {}
    virtual void v074()
    {}
    virtual void v075()
    {}
    virtual const char* v076();
    virtual void v077()
    {}
    virtual void v078()
    {}
    virtual void v079()
    {}
    virtual void v080()
    {}
    virtual void v081()
    {}
    virtual void v082()
    {}
    virtual void v083()
    {}
    virtual void v084()
    {}
    virtual void v085()
    {}
    virtual void v086()
    {}
    virtual void v087()
    {}
    virtual void v088()
    {}
    virtual void v089()
    {}
    virtual void v090()
    {}
    virtual void v091()
    {}
    virtual void v092()
    {}
    virtual void v093()
    {}
    virtual void v094()
    {}
    virtual void v095()
    {}
    virtual void v096()
    {}
    virtual void v097()
    {}
    virtual void v098()
    {}
    virtual void v099()
    {}
    virtual void v100()
    {}
    virtual void v101()
    {}
    virtual void v102()
    {}
    virtual void v103()
    {}
    virtual void v104()
    {}
    virtual void v105()
    {}
    virtual void v106()
    {}
    virtual void v107()
    {}
    virtual void v108()
    {}
    virtual void v109()
    {}
    virtual void v110()
    {}
    virtual void v111()
    {}
    virtual void v112()
    {}
    virtual void v113()
    {}
    virtual void v114()
    {}
    virtual void v115()
    {}
    virtual LodObject* v116();
};


// @fnv 0x004f24e0
void FUN_004f24e0(TESSound* object, bool visible, bool useDefault)
{
    if (object == 0)
        return;

    if (!reinterpret_cast<FUN_00564f00_shell*>(object)->FUN_00564f00())
    {
        reinterpret_cast<::fnv_00564f40::XActor *>((reinterpret_cast<FUN_00564f40_shell*>(object)))->FUN_00564f40(1);
        ::FUN_005b5e40();
    }

    TaskQueueInterface* task = 0;
    if (object->v116())
        task = object->v116()->v4();

    if (task == 0)
        useDefault = true;

    if (useDefault)
    {
        if (object && object->v116())
        {
            reinterpret_cast<::TaskQueueInterface *>((object->v116()))->QueueActorDisarm(!visible);
            reinterpret_cast<TaskQueueInterface*>(object->v116())->FUN_004f2620(visible);
        }
    }
    else if (visible)
    {
        reinterpret_cast<::TaskQueueInterface *>((object->v116()))->QueueActorDisarm(false);
        task->FUN_004f2620(true);
    }
    else
    {
        task->FUN_004f2620(false);
    }
}


// @fnv 0x004e3c40
unsigned char FUN_004e3c40()
{
    return DAT_011c7a58;
}

struct GlobalObject_00633c90 : BSStringT<char>
{
};
struct FUN_004ea9a0_Class
{
    const char* FUN_004ea9a0();
};
// @fnv 0x004ea9a0
const char* FUN_004ea9a0_Class::FUN_004ea9a0()
{
    return ((const char *)(::FUN_00559450((int *)&(::g_011d86a8))));
}

namespace fnv_004ea9c0 {
struct GlobalObject_00633c90
{
    void* operator->() const;
};


struct GlobalNodeAccessor
{
    void* FUN_004ea9c0();
};

// @fnv 0x004ea9c0
void* GlobalNodeAccessor::FUN_004ea9c0()
{
    return (*reinterpret_cast<::fnv_004ea9c0::GlobalObject_00633c90 *>(&::g_011d8690)).operator->();
}
}  // namespace fnv_004ea9c0

struct FUN_00a5e930
{
    virtual void ReservedVirtual();
    ~FUN_00a5e930();
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
};
struct ListCursor
{
};
struct FUN_004ee360
{
    ListCursor* FUN_006815c0();
    ~FUN_004ee360();
};
struct GlobalRemovalList
{
};
void __cdecl FUN_004ee2e0(void* item);

struct FUN_004ee1e0 : FUN_00a5e930
{
    FUN_004ee360* entries;
    virtual ~FUN_004ee1e0();
};
// @fnv 0x004ee1e0
FUN_004ee1e0::~FUN_004ee1e0()
{
    FUN_004ee1e0* self = this;
    reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::GlobalRemovalList *>(&::g_011c7d20))))->FUN_00905330((*(::InventoryStackRecord *const *)((void**)&self)));
    if (entries)
    {
        while (!reinterpret_cast<::ObsList *>((entries))->FUN_004a4460())
        {
            FUN_004ee2e0(((void *)(::FUN_00559450((int *)(((::ListCursor *)(new ((void *)(entries)) ::Vec3())))))));
            reinterpret_cast<::DecalListManager *>((entries))->PopHead();
        }
        delete entries;
        entries = 0;
    }
}


// @fnv 0x004ee440
int __cdecl FUN_004ee440()
{
    return (*reinterpret_cast<int *>(&::DAT_011c61d4));
}

class SubObjectAC
{
  public:
};
class FUN_004ee770_cls
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
    virtual void v60(int index);
    unsigned int FUN_0043b480();
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
    SubObjectAC* m_ac;
    void FUN_004ee770();
};
struct EmptyBase_b4473
{
    ~EmptyBase_b4473();
};

struct SubObj_b4473
{
    ~SubObj_b4473();
};

struct FUN_004ee840_cls : EmptyBase_b4473
{
    SubObj_b4473 m_00;
    ~FUN_004ee840_cls();
};

// Destructor for the class; destroys its embedded sub-object and base.
// @fnv 0x004ee840
FUN_004ee840_cls::~FUN_004ee840_cls()
{}

class B4EFE80UpdateData
{
  public:
    B4EFE80UpdateData(float fTime, bool m_bUpdateEnabled, bool bForceUpdate);

    float m_fTime;
    bool m_bUpdate;
    bool m_bForceUpdate;
    int m_iFlags;
};

struct B4EFE80RTTI
{
    const char* m_pcName;
    const B4EFE80RTTI* m_pBaseRTTI;
};

class B4EFE80Controller
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
    virtual void Update(B4EFE80UpdateData& kData);

};

class B4EFE80Node
{
  public:
};


void __cdecl FUN_004f0020(int iMode);

class B4EFE80Object
{
  public:
    void UpdateControllers(float fTime, B4EFE80Node* pkNode);
};

// @fnv 0x004efe80
void B4EFE80Object::UpdateControllers(float fTime, B4EFE80Node* pkNode)
{
    FUN_004f0020(3);
    for (B4EFE80Controller* pkController = ((::B4EFE80Controller *)(::fnv_0043b230::FUN_0043b230((const char *)this))); pkController; pkController = ((::B4EFE80Controller *)(::fnv_004a8a90::FUN_004a8a90((char *)(pkController)))))
    {
        bool bExcluded = ::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(const ::B4EFE80RTTI *)(&(*reinterpret_cast<::B4EFE80RTTI *>(&::g_011f36bc))), (const ::fnv_0045bad0::NiObject *)(pkController));
        bExcluded = bExcluded | ::fnv_0045bad0::FUN_0045bad0((const ::fnv_0045bad0::NiRTTI *)(const ::B4EFE80RTTI *)(&(*reinterpret_cast<::B4EFE80RTTI *>(&::g_011f36e4))), (const ::fnv_0045bad0::NiObject *)(pkController));
        if (!bExcluded)
        {
            B4EFE80UpdateData kData(fTime, false, false);
            pkController->Update(kData);
            break;
        }
    }
    if (pkNode)
    {
        B4EFE80UpdateData kNodeData(fTime, true, false);
        reinterpret_cast<::NiAVObject *>((pkNode))->UpdateTimeControllers((::NiUpdateData &)(kNodeData), true);
    }
    FUN_004f0020(0);
}

struct FUN_004f1730_obj
{
    virtual int v00(int flags);
};

struct FUN_004f1730_base
{
    virtual ~FUN_004f1730_base();
};

struct FUN_004f1730 : FUN_004f1730_base
{
    int unk04;
    FUN_004f1730_obj* m_08;

    virtual ~FUN_004f1730();
};

// @fnv 0x004f1730
FUN_004f1730::~FUN_004f1730()
{
    if (m_08 != 0)
    {
        FUN_004f1730_obj* pObj = m_08;
        FUN_004f1730_obj* pCur = pObj;
        pCur != 0 ? pCur->v00(1) : 0;
    }
}

struct NodeHeader
{
    unsigned int unk00;
};
struct NodeHolder : NodeHeader, RDLNode
{
};
struct QueryContext
{
    void* unk00;
    void* unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct RegionList
{
};
struct RegionContainer
{
};
struct RegionEntry
{
};
struct InnerRegion
{
};
struct RegionSource
{
};
struct RegionPlayer
{
};

// Walks the player's region node list and returns true if any child list contains target.
// @fnv 0x004f2640
bool __cdecl FUN_004f2640(RDLItem* target)
{
    RDLNode* regionNode = ((::NodeHolder *)(reinterpret_cast<::FUN_004f2770_Class *>((reinterpret_cast<RegionPlayer*>((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)))))->FUN_004f2770()));
    RDLItem* listEntry;
    RegionList* childList;
    RegionList* listReference;
    RDLNode* entryNode;
    QueryContext queryBuffer;
    if (regionNode == 0 || *((::RDLItem **)(new ((void *)(regionNode)) ::Vec3())) == 0)
    {
        regionNode = ((::NodeHolder *)(reinterpret_cast<::TESObjectCELL *>((((::InnerRegion *)(reinterpret_cast<::FUN_00527900_shell *>((((::RegionSource *)(reinterpret_cast<::FUN_00575650_Class *>((reinterpret_cast<RegionPlayer*>((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)))))->FUN_00575650((::FUN_00575650_Result *)(::QueryContext *)(&queryBuffer))))))->FUN_00527900()))))->GetRegionList({})));
    }
    while (regionNode != 0 && *((::RDLItem **)(new ((void *)(regionNode)) ::Vec3())) != 0)
    {
        listEntry = *((::RDLItem **)(new ((void *)(regionNode)) ::Vec3()));
        if (listEntry != 0)
        {
            childList = ((::RegionList *)(reinterpret_cast<::GList *>((((::RegionContainer *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<RegionEntry*>(listEntry)))->FUN_009611e0()))))->FUN_004f35b0({})));
            if (childList != 0)
            {
                listReference = childList;
                entryNode = ((::RDLNode *)(reinterpret_cast<::TESTopicInfoData *>((listReference))->GetLinkToList()));
                while (entryNode != 0)
                {
                    if (*((::RDLItem **)(new ((void *)(entryNode)) ::Vec3())) != 0 && *((::RDLItem **)(new ((void *)(entryNode)) ::Vec3())) == target)
                        return true;
                    entryNode = ((::RDLNode *)(reinterpret_cast<::Callees *>((entryNode))->FUN_00726070()));
                }
            }
        }
        regionNode = ((::RDLNode *)(reinterpret_cast<::Callees *>((regionNode))->FUN_00726070()));
    }
    return false;
}

struct ActionItem
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual bool CheckState();
};
struct ActionIterator
{
    ActionItem** FUN_006815c0();
    bool FUN_004f3610();
};
// Walks the iterator's action items and returns false as soon as one item's CheckState fails, otherwise true.
// @fnv 0x004f3610
bool ActionIterator::FUN_004f3610()
{
    ActionIterator* pIterator = this;
    while (pIterator != 0 && *((::ActionItem **)(new ((void *)(pIterator)) ::Vec3())) != 0)
    {
        if (!(*((::ActionItem **)(new ((void *)(pIterator)) ::Vec3())))->CheckState())
            return false;
    }
    return true;
}

class FUN_004f50e0_sub
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ~FUN_004f50e0_sub();
};

class FUN_004f50e0_base
{
  public:
    virtual void Update();
    unsigned int m_04;
    ~FUN_004f50e0_base();
};

class FUN_004f50e0_cls : public FUN_004f50e0_base
{
  public:
    FUN_004f50e0_sub m_08;
    ~FUN_004f50e0_cls();
};

// Destructor for FUN_004f50e0_cls; empty body, base and member destructors run implicitly.
// @fnv 0x004f50e0
FUN_004f50e0_cls::~FUN_004f50e0_cls()
{}

struct SL_4f6320
{
    int _0;
    int _4;
    SL_4f6320();
    ~SL_4f6320();
};

struct PooledObj_4f6320
{
    virtual ~PooledObj_4f6320();
};

struct PoolEntry_4f6320
{
    PooledObj_4f6320* first;
    PooledObj_4f6320* second;
};


struct FUN_004f6320 : SL_4f6320
{
    bool owns;
    virtual ~FUN_004f6320();
    FUN_004f6320(bool owns);
};

// Stores the ownership flag; if owned and the pool is uninitialised, deletes both objects in each of the 9 pool entries and increments the pool init count.
// @fnv 0x004f6320
FUN_004f6320::FUN_004f6320(bool abOwns)
{
    owns = abOwns;
    if (owns)
    {
        if (g_poolInitCount_4f6320 == 0)
        {
            PooledObj_4f6320* second = 0;
            PooledObj_4f6320* first = 0;
            for (unsigned int i = 0; i < 9; i++)
            {
                first = (*reinterpret_cast<PoolEntry_4f6320 (*)[9]>(&::caches))[i].first;
                if (first)
                {
                    (*reinterpret_cast<PoolEntry_4f6320 (*)[9]>(&::caches))[i].first = 0;
                    delete first;
                }
                second = (*reinterpret_cast<PoolEntry_4f6320 (*)[9]>(&::caches))[i].second;
                if (second)
                {
                    (*reinterpret_cast<PoolEntry_4f6320 (*)[9]>(&::caches))[i].second = 0;
                    delete second;
                }
            }
        }
        g_poolInitCount_4f6320++;
    }
}

struct FUN_004f6640_item
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(int flag);
};

struct FUN_004f6640_node
{
    int m_unk00;
    int m_unk04;
    FUN_004f6640_item** FUN_006815c0();
    void FUN_0063f7b0();
};

struct FUN_004f6640_cls
{
    int m_unk00;
    FUN_004f6640_node m_node;
    unsigned char m_flag0c;
    void FUN_004f6640();
};

// @fnv 0x004f6640
void FUN_004f6640_cls::FUN_004f6640()
{
    FUN_004f6640_item* item = *((::FUN_004f6640_item **)(new ((void *)&(m_node)) ::Vec3()));
    while (item != 0)
    {
        m_node.FUN_0063f7b0();
        if (m_flag0c != 0)
        {
            FUN_004f6640_item* tmp = item;
            FUN_004f6640_item* cur = tmp;
            (cur != 0) ? cur->v4(1) : 0;
        }
        item = *((::FUN_004f6640_item **)(new ((void *)&(m_node)) ::Vec3()));
    }
}

// FUN_004f6850 worker4 v2: v1 + real new-expr for the collection (EH frame + state stores)
struct NiMemObject4f
{
};
struct RDLItemX : RDLItem
{
};
struct MidX
{
};
struct RDLItemV7 : RDLItem
{
    virtual void v6x();
    virtual void FUN_v7(RDLItem* a0, void* a1);
};
struct Sub470
{
    void* FUN_005ae380();
};
struct Coll : NiMemObject4f
{
    virtual ~Coll();
    int m4;
    int m8;
    int mc;
    Coll(int);
};
struct DataBufferInfo
{
    RDLItem* first;
    Coll* second;
};

struct FUN_004f6850_Class
{
    int m0;
    RDLNode m_node;
    RDLItem* FUN_004f6850(int arg0, int arg1, int arg2);
};

class TESForm
{
  public:
    virtual void v0();
};

class TESLandTexture
{
  public:
    virtual void v0();
};

class FUN_004f6f70_cls
{
  public:
    unsigned int unk00;
    TESForm* m_04;

    unsigned char IsLandTexture();
};
// Returns whether m_04 is non-null and casts to TESLandTexture.
// @fnv 0x004f6f70
unsigned char FUN_004f6f70_cls::IsLandTexture()
{
    return m_04 != 0 ? (unsigned char)(dynamic_cast<TESLandTexture*>(m_04) != 0) : (unsigned char)0;
}

class SpawnedObject
{
  public:
    SpawnedObject();
    int unk00;
    int unk04;
};

class FUN_004f7130_cls
{
  public:
    SpawnedObject* FUN_004f7130(SpawnedObject* src);
};

// Creates a SpawnedObject if src is null, sets its two float values from FUN_006a7f50 and FUN_006b9130, and returns it.
// @fnv 0x004f7130
SpawnedObject* FUN_004f7130_cls::FUN_004f7130(SpawnedObject* src)
{
    SpawnedObject* obj = src ? src : new SpawnedObject();
    reinterpret_cast<::FUN_0052ce20_shell *>((obj))->FUN_0052ce20(reinterpret_cast<::CombatTargetTimestamp *>((this))->FUN_006a7f50());
    reinterpret_cast<::FUN_004f5d90_shell *>((obj))->FUN_004f5d90(reinterpret_cast<::TimeoutTimer *>((this))->FUN_006b9130());
    return obj;
}

class FUN_004ff0e0_arg
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048(int);
    virtual void vf04C(int);
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05C();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06C();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07C();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08C();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09C();
    virtual void vf0A0();
    virtual void vf0A4();
    virtual void vf0A8();
    virtual void vf0AC();
    virtual void vf0B0();
    virtual void vf0B4();
    virtual void vf0B8();
    virtual void vf0BC();
    virtual void vf0C0();
    virtual void vf0C4();
    virtual void vf0C8();
    virtual void vf0CC();
    virtual void vf0D0();
    virtual void vf0D4();
    virtual void vf0D8();
    virtual void vf0DC();
    virtual void vf0E0();
    virtual void vf0E4();
    virtual void vf0E8();
    virtual void vf0EC();
    virtual void vf0F0();
    virtual void vf0F4();
    virtual void vf0F8();
    virtual void vf0FC();
    virtual unsigned char vf100();
};
class FUN_004ff0e0_cls
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00C();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01C();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02C();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03C();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048(int);
    virtual void vf04C(int);
    unsigned int m_04;
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
    FUN_004ff0e0_arg* m_090;
    void FUN_004ff0e0(FUN_004ff0e0_arg* a1);
};
// @fnv 0x004ff0e0
void FUN_004ff0e0_cls::FUN_004ff0e0(FUN_004ff0e0_arg* a1)
{
    if (a1 == 0 || a1->vf100() != 0)
    {
        m_090 = a1;
        if (a1 != 0)
        {
            vf048(0x800000);
        }
        else
        {
            vf04C(0x800000);
        }
    }
}

class NiMemObject
{
  public:
};

class AnimIdle : public NiMemObject
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class FUN_00a5ecb0 : public AnimIdle
{
  public:
    char pad00[0xac];
    FUN_00a5ecb0(unsigned int uiValue);
};

class FUN_006815c0
{
  public:
    float x;
    float y;
    FUN_006815c0();
};

class FUN_0048f200
{
  public:
    char pad00[0xc];
    FUN_0048f200();
    ~FUN_0048f200();
};

class FUN_004ed7a0
{
  public:
    char pad00[0x10];
    FUN_004ed7a0(int iSize);
    ~FUN_004ed7a0();
};

class FUN_004ed7d0
{
  public:
    char pad00[0x10];
    FUN_004ed7d0(int iSize);
    ~FUN_004ed7d0();
};

class FUN_004ed800
{
  public:
    char pad00[0x10];
    FUN_004ed800(int iSize);
    ~FUN_004ed800();
};

class FUN_0041a250
{
  public:
    char pad00[0xc];
    FUN_0041a250();
    ~FUN_0041a250();
};

class FUN_00414430
{
  public:
    float r;
    float g;
    float b;
    float a;
    FUN_00414430(float fR, float fG, float fB, float fA);
};

class FUN_00438170
{
  public:
    void* m_pResource;
    FUN_00438170(const char* pcName);
};

struct Setting4e1
{
    bool* FUN_00408d60();
};

struct Value4e1
{
};

struct Renderer4e1
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
    virtual void Precache(AnimIdle* pkObject, bool bFlag);
};

struct TES4e1
{
};

extern bool DAT_011ff100;
extern int DAT_011c7a3c;
extern int DAT_011c7a44;
extern int DAT_011c7a40;

unsigned int __cdecl FUN_004e7ff0();

class FUN_004e1650
{
  public:
    int m00;
    int m04;
    NiPointer<AnimIdle> sp08;
    NiPointer<AnimIdle> sp0c;
    NiPointer<AnimIdle> sp10;
    NiPointer<AnimIdle> sp14;
    NiPointer<AnimIdle> sp18;
    NiPointer<AnimIdle> sp1c;
    NiPointer<AnimIdle> sp20;
    float f24;
    FUN_006815c0 kPoint28;
    int m30;
    bool b34;
    float f38;
    FUN_0048f200 k3c;
    int m48;
    FUN_004ed7a0 k4c;
    FUN_004ed7a0 k5c;
    FUN_004ed7d0 k6c;
    FUN_004ed800 k7c;
    FUN_0041a250 k8c;
    float f98;
    bool b9c;

    FUN_004e1650();
};

// @fnv 0x004e1650
FUN_004e1650::FUN_004e1650()
    : sp08(0), sp0c(0), sp10(0), sp14(0), sp18(0), sp1c(0), sp20(0), k4c(0x25), k5c(0x25), k6c(0x25), k7c(0x25)
{
    f24 = 0.0f;
    DAT_011ff100 = *(*reinterpret_cast<::Setting4e1 *>(&::g_011c7bbc)).FUN_00408d60();
    DAT_011ad86e = 0;
    if (!FUN_004e7ff0())
    {
        *(NiPointer<AnimIdle>*)&::g_011c7c28 = new FUN_00a5ecb0(0);
        ((::Renderer4e1 *)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<::TES4e1 * *>(&::g_TES))))->FUN_0084e3a0()))->Precache(*(NiPointer<AnimIdle>*)&::g_011c7c28, true);
    }
    DAT_011ff3b8 = FUN_00414430(0.0f, ::fnv_00c88020::DAT_01016248, ::fnv_00c88020::DAT_01016248, 1.0f);
    DAT_011ff3c8 = FUN_00414430(0.0f, 0.0f, ::DAT_0101e2bc, 1.0f);
    DAT_011ff3d8 = FUN_00414430(1.0f, 1.0f, 1.0f, 1.0f);
    DAT_011c7a3c = 0;
    m30 = 0;
    f38 = 0.0f;
    b34 = 0;
    sp18 = 0;
    kPoint28 = (*reinterpret_cast<class ::FUN_006815c0 *>(&::DAT_011f4980));
    m00 = 0;
    DAT_011c7a54 = new FUN_00438170("WATER");
    m48 = 0;
    f98 = 0.0f;
    b9c = 0;
    DAT_011c7a44 = ::FUN_0043d4d0((int *)&((*reinterpret_cast<::Value4e1 *>(&::g_011c7bec))));
    DAT_011c7a40 = ::FUN_0043d4d0((int *)&((*reinterpret_cast<::Value4e1 *>(&::g_011c7afc))));
}

namespace fnv_004e19c0 {
struct TexName_4e19c0
{
    TexName_4e19c0& operator=(const char* text);
    operator const char*() const;
};
struct TexList_4e19c0
{
    void RemoveAll();
};
struct BSTextureManager
{
};


struct Owned_4e19c0
{
    int unk00;
    ~Owned_4e19c0();
};

struct Ptr_4e19c0
{
    void* m_pObject;
    ~Ptr_4e19c0();
};
struct ListA_4e19c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~ListA_4e19c0();
};
struct ListB_4e19c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~ListB_4e19c0();
};
struct ListC_4e19c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~ListC_4e19c0();
};
struct ListD_4e19c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    ~ListD_4e19c0();
};
struct ListE_4e19c0
{
    int unk00;
    ~ListE_4e19c0();
};

struct FUN_004e19c0
{
    int unk00;
    int unk04;
    Ptr_4e19c0 m_08;
    Ptr_4e19c0 m_0c;
    Ptr_4e19c0 m_10;
    Ptr_4e19c0 m_14;
    Ptr_4e19c0 m_18;
    Ptr_4e19c0 m_1c;
    Ptr_4e19c0 m_20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    ListA_4e19c0 m_3c;
    ListB_4e19c0 m_4c;
    ListB_4e19c0 m_5c;
    ListC_4e19c0 m_6c;
    ListD_4e19c0 m_7c;
    ListE_4e19c0 m_8c;
    ~FUN_004e19c0();
};

// Shuts down the object, clears texture name globals, releases two textures by name, empties four lists and deletes DAT_011c7a54.
// @fnv 0x004e19c0
FUN_004e19c0::~FUN_004e19c0()
{
    reinterpret_cast<::fnv_004e6620::WaterCleanup *>(this)->ReleaseWaterResources(1, 1);
    (*reinterpret_cast<::fnv_004e19c0::TexName_4e19c0 *>(&::g_011c7be8)) = 0;
    (*reinterpret_cast<::fnv_004e19c0::TexName_4e19c0 *>(&::g_011c7cb8)) = 0;
    if ((*reinterpret_cast<::fnv_004e19c0::TexName_4e19c0 *>(&::g_011c7c2c)))
        reinterpret_cast<::Manager *>((((::fnv_004e19c0::BSTextureManager *)(::FUN_004a0ea0()))))->FUN_00b6da10((::Item *)((*reinterpret_cast<::fnv_004e19c0::TexName_4e19c0 *>(&::g_011c7c2c))));
    (*reinterpret_cast<::fnv_004e19c0::TexName_4e19c0 *>(&::g_011c7c2c)) = 0;
    if ((*reinterpret_cast<::fnv_004e19c0::TexName_4e19c0 *>(&::g_011c7ad4)))
        reinterpret_cast<::Manager *>((((::fnv_004e19c0::BSTextureManager *)(::FUN_004a0ea0()))))->FUN_00b6da10((::Item *)((*reinterpret_cast<::fnv_004e19c0::TexName_4e19c0 *>(&::g_011c7ad4))));
    (*reinterpret_cast<::fnv_004e19c0::TexName_4e19c0 *>(&::g_011c7ad4)) = 0;
    (*reinterpret_cast<::fnv_004e19c0::TexName_4e19c0 *>(&::g_011c7b68)) = 0;
    reinterpret_cast<::NiTPointerListBase *>(&((*reinterpret_cast<::fnv_004e19c0::TexList_4e19c0 *>(&::g_011c7bcc))))->FUN_004ed900();
    reinterpret_cast<::NiTPointerListBase *>(&((*reinterpret_cast<::fnv_004e19c0::TexList_4e19c0 *>(&::g_011c7c30))))->FUN_004ed900();
    reinterpret_cast<::NiTPointerListBase *>(&((*reinterpret_cast<::fnv_004e19c0::TexList_4e19c0 *>(&::g_011c7ce4))))->FUN_004ed900();
    reinterpret_cast<::NiTPointerListBase *>(&((*reinterpret_cast<::fnv_004e19c0::TexList_4e19c0 *>(&::g_011c7b80))))->FUN_004ed900();
    delete (*reinterpret_cast<::fnv_004e19c0::Owned_4e19c0 * *>(&::DAT_011c7a54));
    (*reinterpret_cast<::fnv_004e19c0::Owned_4e19c0 * *>(&::DAT_011c7a54)) = 0;
}
}  // namespace fnv_004e19c0

namespace fnv_004ed3e0 {
struct CleanupObject
{
};
struct NiNodeHolder
{
    CleanupObject* object;
    ~NiNodeHolder();
    void FUN_0066b0d0(CleanupObject* object);
};
struct GlobalObject_0048f200
{
    void* head;
    void* tail;
    unsigned int count;
    ~GlobalObject_0048f200();
};
struct CleanupOwner
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    NiNodeHolder node;
};
struct CleanupRegistry
{
};
struct CleanupManager
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
    virtual void Release(CleanupObject* object);
};
struct FUN_004ed3e0
{
    CleanupOwner* owner;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    GlobalObject_0048f200 list24;
    GlobalObject_0048f200 list30;
    GlobalObject_0048f200 list3c;
    GlobalObject_0048f200 list48;
    NiNodeHolder ptr54;
    NiNodeHolder ptr58;
    unsigned int unk5c, unk60;
    GlobalObject_0048f200 list64;
    GlobalObject_0048f200 list70;
    GlobalObject_0048f200 list7c;
    GlobalObject_0048f200 list88;
    NiNodeHolder ptr94;
    NiNodeHolder ptr98;
    unsigned int unk9c, unka0;
    NiNodeHolder ptra4;
    NiNodeHolder ptra8;
    ~FUN_004ed3e0();
};

// @fnv 0x004ed3e0
FUN_004ed3e0::~FUN_004ed3e0()
{
    ptr94.FUN_0066b0d0(0);
    ptr98.FUN_0066b0d0(0);
    reinterpret_cast<::Cls58a0 *>((((::fnv_004ed3e0::CleanupObject *)(::FUN_0070ec90((char *)((*reinterpret_cast<::fnv_004ed3e0::CleanupRegistry * *>(&::g_TES))))))))->ClearTextureAndShaderTextures({}, {}, {});
    if (owner && ((::fnv_004ed3e0::CleanupObject *)(::FUN_00559450((int *)&(owner->node)))) && ((unsigned int)(reinterpret_cast<::Callees *>((((::fnv_004ed3e0::CleanupObject *)(::FUN_00559450((int *)&(owner->node))))))->FUN_00726070())) == 2)
    {
        reinterpret_cast<::Manager *>((((::fnv_004ed3e0::CleanupObject *)(::FUN_004a0ea0()))))->FUN_00b6da10({});
        owner->node.FUN_0066b0d0(0);
    }
    reinterpret_cast<::NiTPointerListBase *>(&(list30))->FUN_004ed900();
    reinterpret_cast<::NiTPointerListBase *>(&(list3c))->FUN_004ed900();
    if (((::fnv_004ed3e0::CleanupObject *)(::FUN_00559450((int *)&(ptr58)))))
    {
        ((CleanupManager*)FUN_004e7ff0())->Release(((::fnv_004ed3e0::CleanupObject *)(::FUN_00559450((int *)&(ptr58)))));
        ptr58.FUN_0066b0d0(0);
    }
}
}  // namespace fnv_004ed3e0

class Handle4EE
{
  public:
    Handle4EE(int iValue);
    ~Handle4EE();
    void Reset(const void* pvObject);

    void* m_pvObject;
};

class CopyInfo4EE
{
  public:
    CopyInfo4EE(unsigned int uiFlags);
    ~CopyInfo4EE();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class Base4EE;

class Source4EE
{
  public:
    const char* GetName();
};

class Base4EE
{
  public:
    Base4EE(void* pvList, int iFirst, int iSecond);
    virtual ~Base4EE();


    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Handle4EE m_kName;
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
    int m_iInterval;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
};

class FUN_004ee9f0 : public Base4EE
{
  public:
    FUN_004ee9f0(const void* pvTarget, Source4EE* pkSource);
    virtual ~FUN_004ee9f0();

    Handle4EE m_kRoomNode;
};

// Initializes a Base4EE-derived object from a source: stores target and source name handles, copies interval and mode, then registers with the source.
// @fnv 0x004ee9f0
FUN_004ee9f0::FUN_004ee9f0(const void* pvTarget, Source4EE* pkSource)
    : Base4EE(((void *)(reinterpret_cast<::TESTopicInfoData *>((pkSource))->GetLinkToList())), 0, 1), m_kRoomNode(0)
{
    m_kRoomNode.Reset(pvTarget);
    m_kName.Reset(pkSource->GetName());
    m_iInterval = ((int)(reinterpret_cast<::fnv_005f5f80::FUN_005f5f80_shell *>((pkSource))->FUN_005f5f80()));
    reinterpret_cast<::FUN_004eeae0_shell *>(this)->FUN_004eeae0(((int)(reinterpret_cast<::FUN_006c9900_shell *>((pkSource))->FUN_006c9900())));
    CopyInfo4EE kInfo(0x101);
    reinterpret_cast<::Obj43c *>((pkSource))->ClearInterpolatorRefs((::Src43c *)(::Base4EE *)(this), (int)&(kInfo));
}

struct TESRegionData
{
    TESRegionData();
    virtual ~TESRegionData();
    virtual void v0();
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
};

struct FUN_004f5e20
{
    FUN_004f5e20(int flag);
    ~FUN_004f5e20();
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct FUN_004f15f0 : TESRegionData
{
    FUN_004f15f0();
    ~FUN_004f15f0();
    virtual void v0();
    FUN_004f5e20* m_08;
};

// Constructs the object and allocates a new FUN_004f5e20 with flag 1, storing it in m_08.
// @fnv 0x004f15f0
FUN_004f15f0::FUN_004f15f0()
{
    m_08 = new FUN_004f5e20(1);
}

class Base4F4
{
  public:
    Base4F4();
    virtual ~Base4F4();

    int unk04;
};

class Data4F4
{
  public:
    Data4F4();
    ~Data4F4();

    int m_iFirst;
    int unk04;
    int unk08;
    int m_iLast;
};

class List4F4
{
  public:
    void RemoveAll();

    void* m_pkHead;
    void* m_pkNext;
};

class FUN_004f42a0 : public Base4F4
{
  public:
    FUN_004f42a0();
    virtual ~FUN_004f42a0();

    Data4F4 m_kData;
    List4F4 m_kList;
};

// Initializes the data range to zero and clears the list.
// @fnv 0x004f42a0
FUN_004f42a0::FUN_004f42a0()
{
    m_kData.m_iFirst = 0;
    m_kData.m_iLast = 0;
    reinterpret_cast<::FileMatchList *>(&(m_kList))->RemoveAll();
}

class B4F72A0Point
{
  public:
};

// Linearly interpolates between two points' values at fTime using their times, returning 0 if either point is null.
// @fnv 0x004f72a0
float __cdecl FUN_004f72a0(B4F72A0Point* pkCurrentObject, B4F72A0Point* pkSecond, float fTime)
{
    if (!pkCurrentObject || !pkSecond)
        return 0.0f;
    float fSecondValue = reinterpret_cast<::CombatTargetTimestamp *>((pkSecond))->FUN_006a7f50();
    float fSecondTime = reinterpret_cast<::TimeoutTimer *>((pkSecond))->FUN_006b9130();
    return fSecondValue -
           (fSecondTime - fTime) * ((reinterpret_cast<::CombatTargetTimestamp *>((pkCurrentObject))->FUN_006a7f50() - fSecondValue) / (reinterpret_cast<::TimeoutTimer *>((pkCurrentObject))->FUN_006b9130() - fSecondTime));
}

struct Point
{
};
// Returns false if any point is null or the segments' bounding boxes don't overlap, then tests the segment intersection parameters against the denominator.
// @fnv 0x004f7310
bool __cdecl FUN_004f7310(Point* apSeg1Start, Point* apSeg1End, Point* apSeg2Start, Point* apSeg2End)
{
    if (!apSeg1Start || !apSeg1End || !apSeg2Start || !apSeg2End)
        return false;
    float dx3 = reinterpret_cast<::CombatTargetTimestamp *>((apSeg1End))->FUN_006a7f50() - reinterpret_cast<::CombatTargetTimestamp *>((apSeg1Start))->FUN_006a7f50();
    float dx2 = reinterpret_cast<::CombatTargetTimestamp *>((apSeg2Start))->FUN_006a7f50() - reinterpret_cast<::CombatTargetTimestamp *>((apSeg2End))->FUN_006a7f50();
    float minx, maxx2;
    if (dx3 < 0.0)
    {
        minx = reinterpret_cast<::CombatTargetTimestamp *>((apSeg1Start))->FUN_006a7f50();
        maxx2 = reinterpret_cast<::CombatTargetTimestamp *>((apSeg1End))->FUN_006a7f50();
    }
    else
    {
        minx = reinterpret_cast<::CombatTargetTimestamp *>((apSeg1End))->FUN_006a7f50();
        maxx2 = reinterpret_cast<::CombatTargetTimestamp *>((apSeg1Start))->FUN_006a7f50();
    }
    if (dx2 > 0.0)
    {
        if (minx < reinterpret_cast<::CombatTargetTimestamp *>((apSeg2End))->FUN_006a7f50() || maxx2 > reinterpret_cast<::CombatTargetTimestamp *>((apSeg2Start))->FUN_006a7f50())
            return false;
    }
    else
    {
        if (minx < reinterpret_cast<::CombatTargetTimestamp *>((apSeg2Start))->FUN_006a7f50() || maxx2 > reinterpret_cast<::CombatTargetTimestamp *>((apSeg2End))->FUN_006a7f50())
            return false;
    }
    float dy1 = reinterpret_cast<::TimeoutTimer *>((apSeg1End))->FUN_006b9130() - reinterpret_cast<::TimeoutTimer *>((apSeg1Start))->FUN_006b9130();
    float dy2 = reinterpret_cast<::TimeoutTimer *>((apSeg2Start))->FUN_006b9130() - reinterpret_cast<::TimeoutTimer *>((apSeg2End))->FUN_006b9130();
    float miny6, maxy;
    if (dy1 < 0.0)
    {
        miny6 = reinterpret_cast<::TimeoutTimer *>((apSeg1Start))->FUN_006b9130();
        maxy = reinterpret_cast<::TimeoutTimer *>((apSeg1End))->FUN_006b9130();
    }
    else
    {
        miny6 = reinterpret_cast<::TimeoutTimer *>((apSeg1End))->FUN_006b9130();
        maxy = reinterpret_cast<::TimeoutTimer *>((apSeg1Start))->FUN_006b9130();
    }
    if (dy2 > 0.0)
    {
        if (miny6 < reinterpret_cast<::TimeoutTimer *>((apSeg2End))->FUN_006b9130() || maxy > reinterpret_cast<::TimeoutTimer *>((apSeg2Start))->FUN_006b9130())
            return false;
    }
    else
    {
        if (miny6 < reinterpret_cast<::TimeoutTimer *>((apSeg2Start))->FUN_006b9130() || maxy > reinterpret_cast<::TimeoutTimer *>((apSeg2End))->FUN_006b9130())
            return false;
    }
    float rx = reinterpret_cast<::CombatTargetTimestamp *>((apSeg1Start))->FUN_006a7f50() - reinterpret_cast<::CombatTargetTimestamp *>((apSeg2Start))->FUN_006a7f50();
    float ry = reinterpret_cast<::TimeoutTimer *>((apSeg1Start))->FUN_006b9130() - reinterpret_cast<::TimeoutTimer *>((apSeg2Start))->FUN_006b9130();
    float denom8 = dy1 * dx2 - dx3 * dy2;
    float numer9 = dx3 * ry - dy1 * rx;
    float numer3 = dy2 * rx - dx2 * ry;
    if (denom8 == 0.0)
    {
        return true;
    }
    else if (denom8 > 0.0)
    {
        if (numer3 < 0.0 || numer3 > denom8)
            return false;
        if (numer9 < 0.0 || numer9 > denom8)
            return false;
    }
    else
    {
        if (numer3 > 0.0 || numer3 < denom8)
            return false;
        if (numer9 > 0.0 || numer9 < denom8)
            return false;
    }
    return true;
}

struct PolygonPoint
{
};
struct PolygonNode
{
    PolygonPoint** FUN_006815c0();
};
struct Polygon : PolygonNode
{
    bool FUN_004f8360(PolygonPoint*);
};
// @fnv 0x004f6850
RDLItem* FUN_004f6850_Class::FUN_004f6850(int arg0, int arg1, int arg2)
{
    bool foundC = false;
    unsigned short bestPrioB = 0;
    RDLItem* curB = 0;
    RDLItem* bestE = 0;
    RDLItem* itemB = 0;
    RDLItem* resultD = 0;
    RDLNode* nodeB = this ? &this->m_node : 0;
    RDLNode* node2C = 0;
    Coll* collH = new Coll(0);

    while (nodeB != 0 && *((::RDLItem **)(new ((void *)(nodeB)) ::Vec3())) != 0)
    {
        curB = *((::RDLItem **)(new ((void *)(nodeB)) ::Vec3()));
        if (reinterpret_cast<::FUN_00440d80_shell *>((((RDLItemX*)curB)))->FUN_00440d80())
        {
            nodeB = ((::RDLNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
            continue;
        }
        if (arg2 != 0 && arg2 != ((int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((RDLItemX*)curB)))->FUN_007af430())))
        {
            nodeB = ((::RDLNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
            continue;
        }
        itemB = ((::RDLItem *)(reinterpret_cast<::GList *>((((::MidX *)(reinterpret_cast<::FUN_009611e0_shell *>((((RDLItemX*)curB)))->FUN_009611e0()))))->FUN_004f35b0({})));
        if (itemB == 0 || reinterpret_cast<::FUN_004f6de0_shell *>((((RDLItemX*)itemB)))->FUN_004f6de0())
        {
            nodeB = ((::RDLNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
            continue;
        }
        if (arg1 != 0)
        {
            node2C = ((::RDLNode *)(reinterpret_cast<::BGSTerrainManager *>((((RDLItemX*)curB)))->GetMinLevel()));
            while (node2C != 0 && *((::RDLItem **)(new ((void *)(node2C)) ::Vec3())) != 0)
            {
                if (reinterpret_cast<::Polygon *>((((RDLItemX*)*((::RDLItem **)(new ((void *)(node2C)) ::Vec3())))))->FUN_004f8360((::PolygonPoint *)(arg1)))
                {
                    reinterpret_cast<::TESRegionList *>((collH))->AddRegion((::TESRegion *)(curB));
                    break;
                }
                node2C = ((::RDLNode *)(reinterpret_cast<::Callees *>((node2C))->FUN_00726070()));
            }
        }
        else
        {
            reinterpret_cast<::TESRegionList *>((collH))->AddRegion((::TESRegion *)(curB));
        }
        nodeB = ((::RDLNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
    }

    if ((*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].first != 0 && (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].second != 0 &&
        reinterpret_cast<::FUN_004f6730_shell *>(((*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].second))->FUN_004f6730((::FUN_004f6730_shell *)(collH)))
    {
        reinterpret_cast<::FileMatchList *>((((Sub470*)&collH->m4)))->RemoveAll();
        delete collH;
        return (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].first;
    }
    else
    {
        Coll* oldSecondA = 0;
        RDLItem* oldFirstD = 0;
        oldFirstD = (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].first;
        if (oldFirstD != 0)
        {
            (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].first = 0;
            delete oldFirstD;
        }
        oldSecondA = (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].second;
        if (oldSecondA != 0)
        {
            (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].second = 0;
            delete oldSecondA;
        }
    }

    nodeB = collH ? (RDLNode*)&collH->m4 : 0;
    while (nodeB != 0 && *((::RDLItem **)(new ((void *)(nodeB)) ::Vec3())) != 0)
    {
        itemB = ((::RDLItem *)(reinterpret_cast<::GList *>((((::MidX *)(reinterpret_cast<::FUN_009611e0_shell *>((((RDLItemX*)*((::RDLItem **)(new ((void *)(nodeB)) ::Vec3())))))->FUN_009611e0()))))->FUN_004f35b0({})));
        if (itemB == 0)
        {
            nodeB = ((::RDLNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
            continue;
        }
        if (reinterpret_cast<::PatrolActorPackageData *>((((RDLItemX*)itemB)))->IsPatrolling())
        {
            foundC = true;
            if (resultD != 0)
            {
                delete resultD;
                resultD = 0;
            }
            if (((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((((RDLItemX*)itemB)))->FUN_005bb4d0())) > bestPrioB)
            {
                bestE = itemB;
                bestPrioB = (unsigned short)((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((((RDLItemX*)itemB)))->FUN_005bb4d0()));
            }
        }
        else if (!foundC)
        {
            if (resultD != 0)
            {
                ((RDLItemV7*)resultD)->FUN_v7(itemB, ((Sub470*)&collH->m4)->FUN_005ae380());
            }
            else
            {
                resultD = itemB->Clone();
            }
        }
        nodeB = ((::RDLNode *)(reinterpret_cast<::Callees *>((nodeB))->FUN_00726070()));
    }

    if (foundC)
    {
        resultD = bestE->Clone();
    }
    if (resultD != 0)
    {
        if ((*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].first != 0)
        {
            delete (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].first;
        }
        (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].first = resultD;
        if ((*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].second != 0)
        {
            reinterpret_cast<::FileMatchList *>((((Sub470*)&(*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].second->m4)))->RemoveAll();
            delete (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].second;
        }
        (*reinterpret_cast<DataBufferInfo (*)[]>(&::caches))[arg0].second = collH;
        collH = 0;
    }
    if (collH != 0)
    {
        reinterpret_cast<::FileMatchList *>((((Sub470*)&collH->m4)))->RemoveAll();
        delete collH;
    }
    return resultD;
}
// Point-in-polygon test (even-odd crossing rule) after a bounding-box reject.
// @fnv 0x004f8360
bool Polygon::FUN_004f8360(PolygonPoint* pPoint)
{
    PolygonPoint* a2;
    PolygonPoint* b_;
    float bx;
    float ax;
    float yB;
    float ay_;
    int count7 = 0;
    bool _crossing = false;
    if (!pPoint || reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType() < 3)
        return false;
    float x = reinterpret_cast<::CombatTargetTimestamp *>((pPoint))->FUN_006a7f50();
    float by = reinterpret_cast<::TimeoutTimer *>((pPoint))->FUN_006b9130();
    if (x < reinterpret_cast<::FUN_004f7e80_shell *>(this)->FUN_004f7e80() || x > reinterpret_cast<::FUN_004f7f10_cls *>(this)->FUN_004f7f10() || by < reinterpret_cast<::fnv_004f7fa0::FUN_004f7fa0_shell *>(this)->GetMinimumY() || by > reinterpret_cast<::FUN_004f8030_shell *>(this)->GetMaxY())
        return false;
    PolygonNode* node6 = this;
    PolygonNode* nextX = 0;
    do
    {
        nextX = ((::PolygonNode *)(reinterpret_cast<::Callees *>((node6))->FUN_00726070()));
        if (!nextX)
            nextX = this;
        a2 = *((::PolygonPoint **)(new ((void *)(node6)) ::Vec3()));
        b_ = *((::PolygonPoint **)(new ((void *)(nextX)) ::Vec3()));
        bx = reinterpret_cast<::CombatTargetTimestamp *>((a2))->FUN_006a7f50();
        ax = reinterpret_cast<::CombatTargetTimestamp *>((b_))->FUN_006a7f50();
        if (bx > x && ax > x)
            _crossing = true;
        else if (bx > x || ax > x)
        {
            if (x < ::FUN_004f72a0((::B4F72A0Point *)(a2), (::B4F72A0Point *)(b_), by))
                _crossing = true;
            else
                _crossing = false;
        }
        else
            _crossing = false;
        if (_crossing)
        {
            ay_ = reinterpret_cast<::TimeoutTimer *>((a2))->FUN_006b9130();
            yB = reinterpret_cast<::TimeoutTimer *>((b_))->FUN_006b9130();
            if ((ay_ > by && by >= yB) || (ay_ <= by && by < yB))
                count7++;
        }
        node6 = nextX;
    } while (node6 != this);
    if (count7 % 2 == 0)
        return false;
    return true;
}

struct RegionPointMatch
{
};
struct RegionNodeMatch
{
    RegionPointMatch* point;
    RegionNodeMatch* next;
    RegionPointMatch** FUN_006815c0();
};
struct FUN_004f87e0
{
    FUN_004f87e0();
    int x;
    int y;
    float range;
    float value;
};
struct RegionMatch : RegionNodeMatch
{
    FUN_004f87e0* cache;
    float ComputeRegionValue(RegionPointMatch* point, float range);
};
// @fnv 0x004f8560
float RegionMatch::ComputeRegionValue(RegionPointMatch* point, float range)
{
    float j;             // squared distance to the current endpoint
    float a;             // squared distance to the following endpoint
    bool d;              // the final, closing edge has been reached
    float e;             // distance projected along the edge
    bool h;              // point is inside the region
    RegionNodeMatch* l;  // following list node
    float b;             // squared edge length
    float i;             // resulting blend weight
    float f;             // minimum squared distance
    float k;             // squared distance to this edge
    RegionNodeMatch* g;  // current list node
    float c;             // edge length
    d = false;
    if (cache && reinterpret_cast<::PointObject *>((cache))->IsInRegion((::RegionNode *)(point), range))
        return cache->value;
    h = reinterpret_cast<::Polygon *>(this)->FUN_004f8360((::PolygonPoint *)(point));
    if (!point || !h)
        return 0.0f;
    if (range < 1.0 && h)
        return 1.0f;
    f = 3.402823466e+38F;
    g = this;
    do
    {
        l = ((::RegionNodeMatch *)(reinterpret_cast<::Callees *>((g))->FUN_00726070()));
        if (!l)
        {
            l = this;
            d = true;
        }
        j = reinterpret_cast<::fnv_004f7230::FUN_004f7230_Class *>((point))->SquaredDistanceTo((::fnv_004f7230::RegionPoint *)(*((::RegionPointMatch **)(new ((void *)(g)) ::Vec3()))));
        a = reinterpret_cast<::fnv_004f7230::FUN_004f7230_Class *>((point))->SquaredDistanceTo((::fnv_004f7230::RegionPoint *)(*((::RegionPointMatch **)(new ((void *)(l)) ::Vec3()))));
        c = reinterpret_cast<::FUN_004f71f0_Class *>(((*((::RegionPointMatch **)(new ((void *)(g)) ::Vec3())))))->FUN_004f71f0((int)(*((::RegionPointMatch **)(new ((void *)(l)) ::Vec3()))));
        b = reinterpret_cast<::fnv_004f7230::FUN_004f7230_Class *>(((*((::RegionPointMatch **)(new ((void *)(g)) ::Vec3())))))->SquaredDistanceTo((::fnv_004f7230::RegionPoint *)(*((::RegionPointMatch **)(new ((void *)(l)) ::Vec3()))));
        e = b - a + j;
        e /= (2.0 * c);
        if (e >= c)
            k = a;
        else if (e <= 0.0)
            k = j;
        else
            k = j - e * e;
        if (k < f)
            f = k;
        g = l;
    } while (!d);
    f = ConvertDoubleResult(f);
    if (f >= range)
        i = 1.0f;
    else
        i = f / range;
    if (cache)
        delete cache;
    cache = new FUN_004f87e0;
    reinterpret_cast<::FUN_004f7130_cls *>((point))->FUN_004f7130((::SpawnedObject *)(cache));
    cache->range = range;
    cache->value = i;
    return i;
}

class ExtraOwner4FF
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_iValue;
};

class Ref4FF;

class ExtraList4FF
{
  public:
};

class Ref4FF
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1C();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2C();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3C();
    virtual void unk40();
    virtual void unk44();
    virtual void SetFlag(unsigned int uiFlag);

};

class Owner4FF
{
  public:
    int FUN_004ff070(Ref4FF* pkRef);
};

// @fnv 0x004ff070
int Owner4FF::FUN_004ff070(Ref4FF* pkRef)
{
    int iResult = 0;
    reinterpret_cast<::FUN_0042e060_class *>((((::ExtraList4FF *)(reinterpret_cast<::FUN_005d43c0_ *>((pkRef))->FUN_005d43c0()))))->FUN_0042e060((unsigned int)(this), (unsigned int)(pkRef));
    pkRef->SetFlag(0x80000000);
    if (((::ExtraOwner4FF *)(reinterpret_cast<::fnv_0042e110::FUN_0042e110 *>((((::ExtraList4FF *)(reinterpret_cast<::FUN_005d43c0_ *>((pkRef))->FUN_005d43c0()))))->GetExtraData())))
        iResult = ((::ExtraOwner4FF *)(reinterpret_cast<::fnv_0042e110::FUN_0042e110 *>((((::ExtraList4FF *)(reinterpret_cast<::FUN_005d43c0_ *>((pkRef))->FUN_005d43c0()))))->GetExtraData()))->m_iValue;
    return iResult;
}

class BSTempEffect
{
  public:
    void IncRefCount();
    void DecRefCount();
};
struct NodeLinkX
{
    int unk0;
    FUN_004ee360* m_pNext;
};
class ListX
{
  public:
    NiPointer<BSTempEffect> m_spNode;
    FUN_004ee360* m_pHead;
    void FUN_004ee920();
};
// Calls FUN_004ee920 on m_ac if set, then invokes v60 for every index up to FUN_0043b480().
// @fnv 0x004ee770
void FUN_004ee770_cls::FUN_004ee770()
{
    if (m_ac != 0)
    {
        reinterpret_cast<::ListX *>((m_ac))->FUN_004ee920();
    }
    for (unsigned int i = 0; i < FUN_0043b480(); ++i)
    {
        v60((int)i);
    }
}
// Deletes all nodes in the m_pHead linked list and resets m_spNode to null.
// @fnv 0x004ee920
void ListX::FUN_004ee920()
{
    while (m_pHead)
    {
        FUN_004ee360* pNext = ((NodeLinkX*)m_pHead)->m_pNext;
        ((NodeLinkX*)m_pHead)->m_pNext = 0;
        delete m_pHead;
        m_pHead = pNext;
    }
    m_spNode = NiPointer<BSTempEffect>(0);
}

class TESFormBase4FFB
{
  public:
    virtual void vfn_00();
    unsigned int unk04[11];
};

class TESBase304FFB
{
  public:
    virtual void vfn_30();
    unsigned int unk34[2];
};

class TESBase3C4FFB
{
  public:
    virtual void vfn_3C();
    unsigned int unk40[7];
};

class TESBase5C4FFB
{
  public:
    virtual void vfn_5C();
    unsigned int unk60[2];
};

class TESBase684FFB
{
  public:
    virtual void vfn_68();
    unsigned int unk6C;
};

class TESBase704FFB
{
  public:
    virtual void vfn_70();
    unsigned int unk74[7];
};

class TESBase904FFB
{
  public:
    virtual void vfn_90();
    unsigned int unk94;
};

class TESObjectACTI : public TESFormBase4FFB,
                      public TESBase304FFB,
                      public TESBase3C4FFB,
                      public TESBase5C4FFB,
                      public TESBase684FFB,
                      public TESBase704FFB,
                      public TESBase904FFB
{
  public:
    virtual ~TESObjectACTI();
};

class List_009e03e0
{
  public:
    void* m_pHead;
    void* m_pTail;
    ~List_009e03e0();
};

class FUN_004ffba0 : public TESObjectACTI
{
  public:
    List_009e03e0 m_kList;

    virtual ~FUN_004ffba0();
};

// Destructor that calls FUN_004ffc90.
// @fnv 0x004ffba0
FUN_004ffba0::~FUN_004ffba0()
{
    reinterpret_cast<::TerminalCleanup *>(this)->FUN_004ffc90();
}

struct xMemObj
{
};

struct xPt3
{
    float x, y, z;
    xPt3();
    xPt3(float fX, float fY, float fZ);
    xPt3 operator+(const xPt3& kPt) const;
};

struct xPt2
{
    float x, y;
    xPt2();
    xPt2(float fX, float fY);
    xPt2 Scale(const xPt2& kPt) const;
};

struct xMat3
{
    float m[9];
    xMat3();
    xPt3 operator*(const xPt3& kPt) const;
};

struct xProp : public xMemObj
{
    int m_kNextStreamField[0x1c];
    xProp();
};

struct xTriShape : public xMemObj
{
    int m_kNextStreamField[0x31];
    xTriShape(unsigned short usVerts, xPt3* pkVerts, xPt3* pkNormals, void* pkColors, xPt2* pkUVs,
              unsigned short usUVSets, unsigned int uiFlags, unsigned short usTris, unsigned short* pusTris);
};

struct xNode : public xMemObj
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
    virtual void AttachChildInAvailableSlot(xTriShape* pkChild, bool bFirst);
    int m_kNextStreamField[0x2a];
    xNode(unsigned short usChildren);
};

struct xSetting
{
};
struct xTexPtr
{
    operator void*() const;
};


float xRand01();

// Creates a node with one or two triangle shapes of randomly scattered quads using settings and textures.
// @fnv 0x004e08a0
xNode* CreateScatterShapes(unsigned int aiQuadCount)
{
    xNode* qpTd = new xNode(0);
    xPt3* qdqWL = new xPt3[aiQuadCount * 4];
    xPt2* qbGYp = new xPt2[aiQuadCount * 4];
    unsigned short* qSVM = new unsigned short[aiQuadCount * 6];
    xPt3* qfTOqo = 0;
    xPt2* qvyWyw = 0;
    unsigned short* qpqRa = 0;
    if (::DAT_011f941e)
    {
        qfTOqo = new xPt3[aiQuadCount * 4];
        qvyWyw = new xPt2[aiQuadCount * 4];
        qpqRa = new unsigned short[aiQuadCount * 6];
    }
    unsigned int qrEZrs;
    for (qrEZrs = 0; qrEZrs < aiQuadCount; qrEZrs++)
    {
        float qGfbX = xRand01() * ::DAT_01189550;
        float qRqUtp = xRand01() * ::DAT_01189554;
        xPt3 qsTDDg(qGfbX, qRqUtp, 0.0f);
        float qbXcw = ::RandomFloat(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting737)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting738)))))));
        float qZAdkzg = ::RandomFloat(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting739)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::g_011cf980)))))));
        float qyjT = ::RandomFloat(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting740)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::g_011cf920)))))));
        xMat3 qBCzzXA;
        reinterpret_cast<::FUN_004dfdd0_StandIn *>(&(qBCzzXA))->InitIdentity();
        if (::RandomBoolean(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting741))))))))
            qZAdkzg = qyjT;
        float qrzAir = xRand01() > 0.0 ? 0.0 : 0.5;
        float qAhbO = xRand01() > 0.0 ? 0.0 : 0.5;
        xPt2 qrKBG(qrzAir, qAhbO);
        float qArxcFu = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::xSetting *>(&::originalRuntimeFloatSetting743))))));
        unsigned int qYGChgr = qrEZrs * 4;
        qdqWL[qYGChgr] = qBCzzXA * xPt3(-qbXcw, qbXcw, qZAdkzg) + qsTDDg;
        qdqWL[qYGChgr + 1] = qBCzzXA * xPt3(qbXcw, qbXcw, qZAdkzg) + qsTDDg;
        qdqWL[qYGChgr + 2] = qBCzzXA * xPt3(-qbXcw, -qbXcw, qZAdkzg) + qsTDDg;
        qdqWL[qYGChgr + 3] = qBCzzXA * xPt3(qbXcw, -qbXcw, qZAdkzg) + qsTDDg;
        if (::DAT_011f941e)
        {
            qfTOqo[qYGChgr] = qBCzzXA * xPt3(-qArxcFu, qArxcFu, qZAdkzg) + qsTDDg;
            qfTOqo[qYGChgr + 1] = qBCzzXA * xPt3(qArxcFu, qArxcFu, qZAdkzg) + qsTDDg;
            qfTOqo[qYGChgr + 2] = qBCzzXA * xPt3(-qArxcFu, -qArxcFu, qZAdkzg) + qsTDDg;
            qfTOqo[qYGChgr + 3] = qBCzzXA * xPt3(qArxcFu, -qArxcFu, qZAdkzg) + qsTDDg;
        }
        qbGYp[qYGChgr] = xPt2(0.5f, 0.5f).Scale(qrKBG);
        qbGYp[qYGChgr + 1] = xPt2(0.0f, 0.5f).Scale(qrKBG);
        qbGYp[qYGChgr + 2] = xPt2(0.5f, 0.0f).Scale(qrKBG);
        qbGYp[qYGChgr + 3] = xPt2(0.0f, 0.0f).Scale(qrKBG);
        if (::DAT_011f941e)
        {
            qvyWyw[qYGChgr] = xPt2(1.0f, 1.0f);
            qvyWyw[qYGChgr + 1] = xPt2(0.0f, 1.0f);
            qvyWyw[qYGChgr + 2] = xPt2(1.0f, 0.0f);
            qvyWyw[qYGChgr + 3] = xPt2(0.0f, 0.0f);
        }
        int qxQHW = qrEZrs * 6;
        qSVM[qxQHW] = qYGChgr;
        qSVM[qxQHW + 1] = qYGChgr + 2;
        qSVM[qxQHW + 2] = qYGChgr + 1;
        qSVM[qxQHW + 3] = qYGChgr + 1;
        qSVM[qxQHW + 4] = qYGChgr + 2;
        qSVM[qxQHW + 5] = qYGChgr + 3;
        if (::DAT_011f941e)
        {
            qpqRa[qxQHW] = qYGChgr;
            qpqRa[qxQHW + 1] = qYGChgr + 2;
            qpqRa[qxQHW + 2] = qYGChgr + 1;
            qpqRa[qxQHW + 3] = qYGChgr + 1;
            qpqRa[qxQHW + 4] = qYGChgr + 2;
            qpqRa[qxQHW + 5] = qYGChgr + 3;
        }
    }
    xTriShape* qsSDDgz = new xTriShape(aiQuadCount * 4, qdqWL, 0, 0, qbGYp, 1, 0, aiQuadCount * 2, qSVM);
    xProp* qHXYKT = new xProp();
    reinterpret_cast<::FUN_004dfe80_Class *>((qHXYKT))->SetSlotValue(0, (*reinterpret_cast<::xTexPtr *>(&::DAT_011c7864)));
    reinterpret_cast<::FUN_004dfe80_Class *>((qHXYKT))->SetSlotValue(1, (*reinterpret_cast<::xTexPtr *>(&::DAT_011c7860)));
    reinterpret_cast<::FUN_00439410_cls *>((qsSDDgz))->FUN_00439410((::ArgObject *)(qHXYKT));
    ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(qsSDDgz), 0, 0);
    qpTd->AttachChildInAvailableSlot(qsSDDgz, 1);
    if (::DAT_011f941e)
    {
        qsSDDgz = new xTriShape(aiQuadCount * 4, qfTOqo, 0, 0, qvyWyw, 1, 0, aiQuadCount * 2, qpqRa);
        qHXYKT = new xProp();
        reinterpret_cast<::FUN_004dfe80_Class *>((qHXYKT))->SetSlotValue(0, (*reinterpret_cast<::xTexPtr *>(&::DAT_011c7868)));
        reinterpret_cast<::FUN_00439410_cls *>((qsSDDgz))->FUN_00439410((::ArgObject *)(qHXYKT));
        ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(qsSDDgz), 0, 0);
        qpTd->AttachChildInAvailableSlot(qsSDDgz, 1);
    }
    return qpTd;
}

struct FUN_004f09e0
{
    virtual ~FUN_004f09e0();
};
// @fnv 0x004f09e0
FUN_004f09e0::~FUN_004f09e0()
{}

namespace fnv_004f6fc0 {
struct Modifier
{
};
struct AlphaColor
{
};
struct Base006815c0
{
};
struct MyClass004f6fc0
{
    MyClass004f6fc0* FUN_004f6fc0();
};
// Calls _ref_006815c0, then FUN_0052ce20 and SetValue each with 0.0f, and returns this.
// @fnv 0x004f6fc0
MyClass004f6fc0* MyClass004f6fc0::FUN_004f6fc0()
{
    new ((void *)(((Base006815c0*)this))) ::Vec3();
    reinterpret_cast<::FUN_0052ce20_shell *>((((AlphaColor*)this)))->FUN_0052ce20(0.0f);
    reinterpret_cast<::FUN_004f5d90_shell *>((((Modifier*)this)))->FUN_004f5d90(0.0f);
    return this;
}
}  // namespace fnv_004f6fc0

// FUN_004e3d60 v05 - one-pass transcription from the packet alone (/Od /Oy-)
struct Vec4f
{
    float v[4];
};
struct VObj
{
    virtual int reserved0();
    virtual int reserved1();
    virtual int reserved2();
    virtual int reserved3();
    virtual int FunctionAtSlot4();
    virtual int FunctionAtSlot5();
    virtual int FunctionAtSlot6();
    virtual int VirtualFunction7();
    virtual int VirtualFunction8();
    virtual int VirtualFunction9();
    virtual int VirtualFunction10();
    virtual int ReplaceImpactData();
    virtual int reserved12();
    virtual int VirtualFunction13();
    virtual int reserved14();
    virtual int reserved15();
    virtual int reserved16();
    virtual int reserved17();
    virtual int reserved18();
    virtual int reserved19();
    virtual int reserved20();
    virtual int reserved21();
    virtual int VirtualFunction22();
    virtual int VirtualFunction23();
    virtual int VirtualFunction24();
    virtual int VirtualFunction25();
    virtual int VirtualFunction26();
    virtual int VirtualFunction27();
    virtual int VirtualFunction28();
    virtual int VirtualFunction29();
    virtual int reserved30();
    virtual int reserved31();
    virtual int reserved32();
    virtual int reserved33();
    virtual int reserved34();
    virtual int reserved35();
    virtual int reserved36();
    virtual int get37();
    virtual int get38();
};
struct BoundObj
{
    virtual int reserved0();
    virtual int reserved1();
    virtual int reserved2();
    virtual int reserved3();
    virtual int FunctionAtSlot4();
    virtual int FunctionAtSlot5();
    virtual int FunctionAtSlot6();
    virtual int VirtualFunction7();
    virtual int VirtualFunction8();
    virtual int VirtualFunction9();
    virtual int VirtualFunction10();
    virtual int ReplaceImpactData();
    virtual int reserved12();
    virtual int VirtualFunction13();
    virtual int reserved14();
    virtual int reserved15();
    virtual int reserved16();
    virtual int reserved17();
    virtual int reserved18();
    virtual int reserved19();
    virtual int reserved20();
    virtual int reserved21();
    virtual int VirtualFunction22();
    virtual int VirtualFunction23();
    virtual int VirtualFunction24();
    virtual int VirtualFunction25();
    virtual int VirtualFunction26();
    virtual int VirtualFunction27();
    virtual int VirtualFunction28();
    virtual int VirtualFunction29();
    virtual int reserved30();
    virtual int reserved31();
    virtual int reserved32();
    virtual int reserved33();
    virtual int reserved34();
    virtual int reserved35();
    virtual int reserved36();
    virtual int reserved37();
    virtual int reserved38();
    virtual int reserved39();
    virtual int reserved40();
    virtual int reserved41();
    virtual int reserved42();
    virtual int reserved43();
    virtual int reserved44();
    virtual int reserved45();
    virtual int reserved46();
    virtual int reserved47();
    virtual int reserved48();
    virtual int reserved49();
    virtual int reserved50();
    virtual int reserved51();
    virtual int reserved52();
    virtual int reserved53();
    virtual int reserved54();
    virtual int reserved55();
    virtual int reserved56();
    virtual int reserved57();
    virtual int reserved58();
    virtual int reserved59();
    virtual int reserved60();
    virtual int reserved61();
    virtual int reserved62();
    virtual int reserved63();
    virtual int reserved64();
    virtual int reserved65();
    virtual int reserved66();
    virtual int reserved67();
    virtual int reserved68();
    virtual int reserved69();
    virtual int reserved70();
    virtual int reserved71();
    virtual int reserved72();
    virtual int reserved73();
    virtual int reserved74();
    virtual int reserved75();
    virtual int reserved76();
    virtual int reserved77();
    virtual int reserved78();
    virtual int reserved79();
    virtual void* getObj80();
};
struct NavPtr
{
    void* p;
    NavPtr& FUN_006e5cc0(const NavPtr& other);
    void FUN_0066b0d0(void* arg);
};
struct PropPtr
{
    VObj* p;
};
struct Obj20
{
    int f00[12];
    NavPtr m_30;
    Vec4f m_34;
    Vec4f m_44;
    Vec4f m_54;
};
struct PropObj
{
    int f00[71];
    float m_11c;
    int f120[5];
    PropPtr m_134;
    NavPtr m_138;
};
struct Refr
{
};
struct StrList
{
    void* p;
};
struct ParamObj
{
    int f00[9];
    StrList m_24;
};
struct ProcObj
{
};
struct ItemObj
{
};
struct G4680Obj
{
};
struct Map6c
{
};
class NiSourceTexture
{
  public:
    void IncRefCount();
    void DecRefCount();
};
struct TESObj
{
};
struct BSTextureManager
{
};
struct ImgMgr
{
};
int __cdecl FUN_004e4680();
float __cdecl FUN_004e44b0(float value);
struct Self
{
    int f00[27];
    Map6c m_6c;
    void FUN_004e3d60(ParamObj* param);
};
// Iterates param's list; for entries whose ProcObj FUN_008d8520 returns 13, updates texture pointers and vectors and writes DAT_011ffe* globals.
// @fnv 0x004e3d60
void Self::FUN_004e3d60(ParamObj* param)
{
    void* zpos = ((void *)(::FUN_00559450((int *)&(param->m_24))));
    void* next = 0;
    while (zpos != 0)
    {
        next = ((void *)(reinterpret_cast<::FUN_007b52d0_cls *>(&(param->m_24))->DereferenceIfNotNull((int **)(zpos))));
        Refr* rrefr = ((::Refr *)(reinterpret_cast<::FUN_006317a0_struct *>(&(param->m_24))->AddEight((int)(zpos))));
        BoundObj* bound = ((::BoundObj *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((rrefr))->FUN_007af430()));
        Obj20* obj = (Obj20*)bound->getObj80();
        if (obj != 0)
        {
            if (reinterpret_cast<::FUN_00580080_shell *>((obj))->FUN_00580080() != 0)
            {
                if (!reinterpret_cast<::FUN_004e4690_shell *>((((G4680Obj*)FUN_004e4680())))->GetByteAtOffset2B8())
                {
                    reinterpret_cast<::FUN_00b9b7f0_cls *>((((G4680Obj*)FUN_004e4680())))->FUN_00b9b7f0();
                }
                ItemObj* item = ((::ItemObj *)(reinterpret_cast<::Finder *>(this)->FUN_004e8030((::Ref *)(rrefr))));
                if (item != 0)
                {
                    ItemObj* item3 = item;
                    ProcObj* proc = ((::ProcObj *)(reinterpret_cast<::AlchemyItem *>((item3))->FUN_004030b0()));
                    if (proc != 0)
                    {
                        if (((int)(reinterpret_cast<::BSShaderNoLightingProperty *>((proc))->GetBaseTexture())) == 13)
                        {
                            PropObj* propTemp = ((::PropObj *)(reinterpret_cast<::FUN_00a59d30_C *>((item))->FUN_00a59d30(3)));
                            PropObj* pprop = propTemp;
                            if (*::g_011c7b98.Bool())
                            {
                                if (((::VObj *)(::FUN_00559450((int *)&(pprop->m_134)))) == 0)
                                {
                                    reinterpret_cast<::FUN_004e45a0_shell *>(this)->AssignMemberToSource((::Helper62d0 *)(void *)(&pprop->m_134));
                                }
                            }
                            else
                            {
                                if (((::VObj *)(::FUN_00559450((int *)&(pprop->m_134)))) == 0 || ((unsigned char)(reinterpret_cast<::FUN_004e4640_shell *>((obj))->GetByteAtOffset190())))
                                {
                                    NiPointer<NiSourceTexture> localPtr(0);
                                    reinterpret_cast<::FUN_005800e0_shell *>((obj))->FUN_005800e0((::FUN_006e5cc0_Class *)(void *)(&localPtr));
                                    if ((NiSourceTexture*)localPtr != 0)
                                    {
                                        reinterpret_cast<::FUN_005800e0_shell *>((obj))->FUN_005800e0((::FUN_006e5cc0_Class *)(void *)(&pprop->m_134));
                                    }
                                    else
                                    {
                                        reinterpret_cast<::TESTexLoader *>((((TESObj*)(*reinterpret_cast<::TES4e1 * *>(&::g_TES)))))->FUN_004568c0((const char *)(void *)(((void *)(reinterpret_cast<::FUN_005800a0_shell *>((obj))->FUN_005800a0()))), *(::TexPtr< ::NiSourceTexture> *)nullptr, {}, {});
                                    }
                                    reinterpret_cast<::FUN_004e4660_shell *>((obj))->SetByteAtOffset190(0);
                                }
                            }
                            if (((::VObj *)(::FUN_00559450((int *)&(pprop->m_134)))) != 0)
                            {
                                if (((void *)(::FUN_00559450((int *)&(obj->m_30)))) == 0)
                                {
                                    DAT_011ad81c = ((::VObj *)(::FUN_00559450((int *)&(pprop->m_134))))->get37();
                                    DAT_011ad820 = ((::VObj *)(::FUN_00559450((int *)&(pprop->m_134))))->get38();
                                    obj->m_30.FUN_0066b0d0(((void *)(reinterpret_cast<::Pool *>((((::BSTextureManager *)(::FUN_004a0ea0()))))->FUN_00b6e110((unsigned int)(((void *)(::FUN_004a0e90()))), 0x13, 0, 0, 0))));
                                }
                            }
                            pprop->m_138.FUN_006e5cc0(obj->m_30);
                            bool oflag = false;
                            if (!reinterpret_cast<::FUN_0057c850_cls *>(&(m_6c))->FUN_0057c850(obj, (bool *)&(oflag)))
                            {
                                if (((::VObj *)(::FUN_00559450((int *)&(pprop->m_134)))) != 0)
                                {
                                    DAT_011ffe48 = pprop->m_11c;
                                    float f_44 = ::FUN_00452e70(true);
                                    float f_40 = reinterpret_cast<::FUN_004e45e0_shell *>((obj))->GetFieldE8Float();
                                    float zf4c = ::GetFieldEC((const char *)(obj));
                                    float f48 = reinterpret_cast<::FUN_004e4600_shell *>((obj))->FUN_004e4600();
                                    obj->m_34.v[0] += (double)FUN_004e44b0((float)(f_40 * 0.01745329238474369)) *
                                                      (::FUN_006447d0((const char *)(obj)) * f_44);
                                    obj->m_34.v[1] +=
                                        (double)cos((float)(f_40 * 0.01745329238474369)) * (::FUN_006447d0((const char *)(obj)) * f_44);
                                    obj->m_44.v[0] += (double)FUN_004e44b0((float)(zf4c * 0.01745329238474369)) *
                                                      (reinterpret_cast<::FUN_004e4620_shell *>((obj))->FUN_004e4620() * f_44);
                                    obj->m_44.v[1] +=
                                        (double)cos((float)(zf4c * 0.01745329238474369)) * (reinterpret_cast<::FUN_004e4620_shell *>((obj))->FUN_004e4620() * f_44);
                                    obj->m_54.v[0] += (double)FUN_004e44b0((float)(f48 * 0.01745329238474369)) *
                                                      (reinterpret_cast<::NiCamera *>((obj))->GetMaxFarNearRatio() * f_44);
                                    obj->m_54.v[1] +=
                                        (double)cos((float)(f48 * 0.01745329238474369)) * (reinterpret_cast<::NiCamera *>((obj))->GetMaxFarNearRatio() * f_44);
                                    WrapValueToRange(&obj->m_34.v[0], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_34.v[1], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_44.v[0], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_44.v[1], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_54.v[0], 0.0f, 1.0f);
                                    WrapValueToRange(&obj->m_54.v[1], 0.0f, 1.0f);
                                    (*reinterpret_cast<::Vec4f *>(&::fnv_00b9b540::DAT_011ffe4c)) = obj->m_34;
                                    (*reinterpret_cast<::Vec4f *>(&::fnv_00b9b540::DAT_011ffe5c)) = obj->m_44;
                                    (*reinterpret_cast<::Vec4f *>(&::fnv_00b9b540::DAT_011ffe6c)) = obj->m_54;
                                    DAT_011ffe7c = FUN_00404010(1.0f, FUN_004e4430(reinterpret_cast<::FUN_004e45c0_shell *>((obj))->GetField130() / 100.0));
                                    DAT_011ffe80 = FUN_00404010(1.0f, FUN_004e4430(reinterpret_cast<::FUN_00821640_shell *>((obj))->FUN_00821640() / 100.0));
                                    DAT_011ffe84 = FUN_00404010(1.0f, FUN_004e4430(reinterpret_cast<::FUN_00821660_shell *>((obj))->FUN_00821660() / 100.0));
                                    DAT_011ffe8c = ::FUN_00567470((char *)(obj));
                                    DAT_011ffe90 = reinterpret_cast<::FUN_00821680_Class *>((obj))->FUN_00821680();
                                    DAT_011ffe94 = reinterpret_cast<::FUN_008133b0_class *>((obj))->GetFloatAt144();
                                    reinterpret_cast<::EffectManager975 *>((((::ImgMgr *)(::ImageSpaceManager::FUN_004e3270()))))->FUN_00b975f0(0x21, (int)(((void *)(::FUN_004a0e90()))),
                                                                         (int)(((::VObj *)(::FUN_00559450((int *)&(pprop->m_134))))),
                                                                         (int)(((void *)(::FUN_00559450((int *)&(obj->m_30))))), 0, 1);
                                }
                                reinterpret_cast<::FUN_0084d310_class *>(&(m_6c))->FUN_0084d310((int)(obj), true);
                            }
                        }
                    }
                }
            }
        }
        zpos = next;
    }
}

#include "generated/data/staging/blk_004e0000_od.inc"
