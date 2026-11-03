
// src/gamebryo2.2/corelibs/niparticle/nipsysinitialrotspeedvarctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysinitialrotspeedvarctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00c29e90
#include <new>
#include "fnv/decl/CtlrStandin.h"
#include "fnv/decl/NiPSysAirFieldAirFrictionCtlr.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00c32000.h"
#include "fnv/symbols_01202000.h"
void* __cdecl FUN_00c29e90()
{
    return &(*reinterpret_cast<void * *>(&::g_012026d8));
}

extern int DAT_010c0e44;

struct FUN_00c32d80
{
    FUN_00c32d80();
};

// @fnv 0x00c32d80
FUN_00c32d80::FUN_00c32d80()
{
    static_cast<::CtlrStandin *>(nullptr)->FUN_00c31260();
    *(int*)this = (int)&DAT_010c0e44;
}


struct FUN_00c29f00_Array
{
    void* unk00;
    void* unk04;
    unsigned short unk08;
    unsigned short unk0A;
    unsigned short unk0C;
    unsigned short unk0E;
};

// Grows the array if its count has reached capacity, then stores the item obtained from g_012026d8 at the current count.
// @fnv 0x00c29f00
void FUN_00c29f00(FUN_00c29f00_Array* arr)
{
    ::FUN_00c32f60((::StrArr *)(arr));
    void* item = ((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_012026d8))))));
    unsigned int count = arr->unk0A;
    if (count >= arr->unk08)
        reinterpret_cast<::ViewerStrings *>((arr))->SetSize(count + arr->unk0E);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((arr))->SetAt(count, (*(char * *)(&item)));
}

extern "C" char DAT_010becbc;
extern "C" void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedCtlr
{
    void FUN_00c32d80();
    virtual void v00();
};

struct SpawnedHost
{
    SpawnedCtlr* CreateSpawnedCtlr(void* a1);
};

// Allocates a 0x40-byte SpawnedCtlr, initialises it and its vtable, passes it to FUN_00c32de0 with a1, and returns it.
// @fnv 0x00c29eb0
SpawnedCtlr* SpawnedHost::CreateSpawnedCtlr(void* a1)
{
    SpawnedCtlr* obj = (SpawnedCtlr*)FUN_00aa13e0(0x40);
    if (obj != 0)
    {
        new ((void *)(obj)) ::FUN_00c32d80();
        *(void* volatile*)obj = &DAT_010becbc;
    }
    else
    {
        obj = 0;
    }
    reinterpret_cast<::NiPSysAirFieldAirFrictionCtlr *>((this))->CopyMemberData((::NiPSysAirFieldAirFrictionCtlr *)(obj), (*(::CloningProcess *)(a1)));
    return obj;
}

void* __cdecl FUN_00aa13e0(unsigned int size);

struct SpawnedFloat
{
    unsigned int unk00[6];

    SpawnedFloat(float value) throw();
};

struct FUN_00c32da0_cls
{
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0A();
    virtual void vfn0B();
    virtual void vfn0C();
    virtual void vfn0D();
    virtual void vfn0E();
    virtual void vfn0F();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn1A();
    virtual void vfn1B();
    virtual void vfn1C();
    virtual void vfn1D();
    virtual void vfn1E();
    virtual void vfn1F();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn2A();
    virtual void vfn2B();
    virtual void vfn2C();
    virtual void vfn2D();
    virtual void vfn2E();
    virtual void vfn2F();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn3A();
    virtual void vfn3B();
    virtual void FetchValue(float* out);

    void* CreateSpawnedFloat(float unused);
};

// Fetches a float via FetchValue and allocates a SpawnedFloat initialized with that value, returning it.
// @fnv 0x00c32da0
void* FUN_00c32da0_cls::CreateSpawnedFloat(float unused)
{
    float value;
    this->FetchValue(&value);
    SpawnedFloat* obj = 0;
    obj = new SpawnedFloat(value);
    return obj;
}
