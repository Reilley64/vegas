// fallout_shared/region system/tesregiondataweather.cpp: TESRegionDataWeather, RegionWeather (8 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f15c0_shell.h"
#include "fnv/decl/FUN_004f50e0_cls.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_00582380_shell.h"
#include "fnv/decl/FUN_005825a0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/RegionSource.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "tesregiondataweather_decls.h"
// @fnv 0x004f51f0
void TESRegionDataWeather::LoadWeatherData(TESFile* file, TESRegion* region)
{
    int warnings = ::FUN_0046e8a0();
    ::FUN_0043b2b0(true);
    TESWeatherList::LoadWeatherEntries(&weatherList, file, region);
    ::FUN_0043b2b0(false);
    if (::FUN_0046e8a0() > warnings && region)
        ::FUN_005b5e40();
}

extern unsigned int _data_011c16bc;
struct B004f1400
{
    virtual ~B004f1400();
    char p[4];
    B004f1400();
};
struct W004f5040
{
    char p[0xc];
    W004f5040();
    ~W004f5040();
};
struct FUN_004f5040 : public B004f1400
{
    W004f5040 list;
    FUN_004f5040();
    virtual ~FUN_004f5040();
};
// Constructs a FUN_004f5040, initializing its base B004f1400 and its W004f5040 list member.
// @fnv 0x004f5040
FUN_004f5040::FUN_004f5040()
{}

struct S004f50b0
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004f50e0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004f50b0
void* S004f50b0::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004f50e0_cls *>(this)->FUN_004f50e0_cls::~FUN_004f50e0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct A004f14c0
{
};
struct A00582380
{
};
struct S004f51c0
{
    char pad[8];
    A00582380 lst;
    void FUN_004f51c0();
};
// @fnv 0x004f51c0
void S004f51c0::FUN_004f51c0()
{
    reinterpret_cast<::RegionSource *>((((A004f14c0*)this)))->WriteSaveData();
    reinterpret_cast<::FUN_00582380_shell *>(&(lst))->WriteWeatherList((void *)(0x54574452));
}

void* __cdecl operator new(unsigned int);
struct FUN_004f5140_shell
{
    char p[0x10];
    FUN_004f5140_shell(const void* a);
};
struct FUN_004f5260_shell
{
    void* __thiscall FUN_004f5260();
};
// @fnv 0x004f5260
void* FUN_004f5260_shell::FUN_004f5260()
{
    FUN_004f5140_shell* pdata = new FUN_004f5140_shell(this);
    return pdata;
}

struct C004f52e0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual C004f52e0* v5();
    virtual void v6();
    virtual void v7(const C004f52e0*, int);
    C004f52e0* FUN_004f52e0(const C004f52e0* apRegionData);
};
// @fnv 0x004f52e0
C004f52e0* C004f52e0::FUN_004f52e0(const C004f52e0* apRegionData)
{
    C004f52e0* pdata = v5();
    pdata->v7(apRegionData, 2);
    return pdata;
}

struct H008256d0
{
    bool FUN_008256d0();
};
struct S004f5570
{
    char _pad[8];
    H008256d0 _lst;
    bool FUN_004f5570();
};
// Returns true when the contained list object's check returns false.
// @fnv 0x004f5570
bool S004f5570::FUN_004f5570()
{
    return !_lst.FUN_008256d0();
}

struct RegionWeatherList
{
};
struct RegionWeather
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    unsigned char overrideFlag;
    unsigned char disabled;
    unsigned char priority;
    unsigned char unknown07;
    RegionWeatherList list;
    void MergeWeather(RegionWeather*, int);
};
double _floor(float);
// @fnv 0x004f5320
void RegionWeather::MergeWeather(RegionWeather* apOther, int enabled)
{
    RegionWeather* other = apOther;
    if (!apOther || apOther->v4() != 3 || !enabled)
        return;
    if (disabled)
    {
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling());
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())));
        reinterpret_cast<::FUN_005825a0_shell *>(&(list))->CopyWeatherList((const ::TESWeatherList *)(::RegionWeatherList *)(&other->list), 0);
    }
    else if (other->disabled)
    {
        return;
    }
    else if (overrideFlag)
    {
        if (reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling() && ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())) > ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())))
        {
            reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling());
            reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())));
            reinterpret_cast<::FUN_005825a0_shell *>(&(list))->CopyWeatherList((const ::TESWeatherList *)(::RegionWeatherList *)(&other->list), 0);
        }
        return;
    }
    else if (reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling())
    {
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling());
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())));
        reinterpret_cast<::FUN_005825a0_shell *>(&(list))->CopyWeatherList((const ::TESWeatherList *)(::RegionWeatherList *)(&other->list), 0);
    }
    else
    {
        reinterpret_cast<::FUN_005825a0_shell *>(&(list))->CopyWeatherList((const ::TESWeatherList *)(::RegionWeatherList *)(&other->list), 1);
        float weight = ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) + (100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0()));
        weight += (100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) + ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0()));
        weight *= 0.004999999888241291;
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0((unsigned char)_floor(weight));
    }
}
