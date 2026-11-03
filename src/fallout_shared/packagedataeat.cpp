
// src/fallout_shared/packagedataeat.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataeat.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/FUN_0067fbe0_cls.h"
#include "fnv/decl/FUN_0067fc50_shell.h"
#include "fnv/decl/fnv_0067f600__FUN_0067f600_shell.h"
#include "fnv/decl/fnv_0067f6c0__FUN_0067f6c0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/p07__DelStandIn.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0119b000.h"
struct TESEatPackageData
{
    unsigned char base[4];
    void* m_pPackageTarget;
    void FUN_0067bbb0();
};

struct LocationDescriptor
{
};

// @fnv 0x0067bbb0
void TESEatPackageData::FUN_0067bbb0()
{
    ::FUN_004856d0(0x44454b50);
    if (this->m_pPackageTarget != 0)
    {
        reinterpret_cast<::fnv_0067f6c0::FUN_0067f6c0_shell *>((((LocationDescriptor*)this->m_pPackageTarget)))->FUN_0067f6c0(0x32444c50);
    }
}

namespace fnv_0067bfa0 {
struct BGSLoadFormBuffer;
struct LocationDescriptor
{
};
struct TESEatPackageData
{
    void* m_Base;
    LocationDescriptor* m_pPackageTarget;
    void FUN_0067bfa0(BGSLoadFormBuffer*);
};

// @fnv 0x0067bfa0
void TESEatPackageData::FUN_0067bfa0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (m_pPackageTarget != 0)
    {
        reinterpret_cast<::FUN_0067fc50_shell *>((m_pPackageTarget))->ResolveObject((std::intptr_t)(apLoadGameBuffer));
    }
}
}  // namespace fnv_0067bfa0

struct FakeCls
{
    void* DestroyIfFlagged(unsigned int);
};
struct BGSLoadFormBuffer
{
};
struct PackageLocation_
{
    PackageLocation_();
    char pad[12];
};
struct TESEatPackageData_
{
    unsigned char base[4];
    void* m_pPackageTarget;
    void Load(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x0067b050
void TESEatPackageData_::Load(BGSLoadFormBuffer* apLoadGameBuffer)
{
    bool bhasLocation = false;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&bhasLocation), 1);
    if (bhasLocation)
    {
        m_pPackageTarget = new PackageLocation_;
        reinterpret_cast<::FUN_0067fbe0_cls *>((((TESEatPackageData_*)m_pPackageTarget)))->FUN_0067fbe0((::PackageLoadStream *)(apLoadGameBuffer));
    }
}

struct PkgLoc_b9420
{
};

struct Base_b9420
{
    virtual ~Base_b9420();
};

struct FUN_0067b9b0_cls : public Base_b9420
{
    PkgLoc_b9420* m_04;
    virtual ~FUN_0067b9b0_cls();
};
// @fnv 0x0067b980
void* FakeCls::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0067b9b0_cls *>(this)->FUN_0067b9b0_cls::~FUN_0067b9b0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0067b9b0
FUN_0067b9b0_cls::~FUN_0067b9b0_cls()
{
    PkgLoc_b9420* a = m_04;
    PkgLoc_b9420* p = a;
    (p != 0) ? reinterpret_cast<::p07::DelStandIn *>((p))->FUN_00670b30(1) : 0;
}

extern "C" int __cdecl FUN_00ec43fb(int a1, int a2, int* a3, int* a4, int a5);

extern int DAT_0119be3c;

struct FUN_0067f600_Obj
{
};

struct FUN_0067bb40_Result
{
    int unk00;
    int unk04;
};

struct TESEatPackageData_StandIn
{
    unsigned char base[4];
    FUN_0067f600_Obj* m_pPackageTarget;

    unsigned char FUN_0067bb40(int arg);
};

// @fnv 0x0067bb40
unsigned char TESEatPackageData_StandIn::FUN_0067bb40(int arg)
{
    FUN_0067bb40_Result* result = (FUN_0067bb40_Result*)FUN_00ec43fb(arg, 0, &DAT_0119bdec, &DAT_0119be3c, 0);

    if (result == 0)
    {
        return 1;
    }

    if (m_pPackageTarget != 0)
    {
        if (((unsigned char)(reinterpret_cast<::fnv_0067f600::FUN_0067f600_shell *>((m_pPackageTarget))->IsDifferentFrom((::LocationDescriptor *)(result->unk04)))) != 0)
        {
            return 1;
        }
    }
    else if (result->unk04 != 0)
    {
        return 1;
    }

    return 0;
}

struct TESEatPackageData_rtti
{
    virtual ~TESEatPackageData_rtti();  // the original class is polymorphic (rtti_variants.py)
    void* m_pPackageTarget;
    void FUN_0067bbb0();
};

struct LocationDescriptor_rtti
{
public:
    void Copy(::LocationDescriptor_rtti *, bool);
};

extern "C" int __cdecl FUN_00ec43fb(int, int, int*, int*, int);

struct FUN_0067f030
{
    int unk00;
    int unk04;
    int unk08;
    FUN_0067f030();
    ~FUN_0067f030();
};

struct FUN_0067ba40_Result
{
    int unk00;
    void* location;
};

struct TESEatPackageData_Copy
{
    int unk00;
    FUN_0067f030* m_pPackageTarget;
    void FUN_0067ba40(int flags);
};

// @fnv 0x0067ba40
void TESEatPackageData_Copy::FUN_0067ba40(int flags)
{
    FUN_0067ba40_Result* result = (FUN_0067ba40_Result*)FUN_00ec43fb(flags, 0, &DAT_0119bdec, &DAT_0119be3c, 0);
    if (result)
    {
        if (m_pPackageTarget)
        {
            delete m_pPackageTarget;
            m_pPackageTarget = 0;
        }
        if (result->location)
        {
            m_pPackageTarget = new FUN_0067f030;
            reinterpret_cast<::LocationDescriptor_rtti *>((m_pPackageTarget))->Copy((::LocationDescriptor_rtti *)(result->location), 0);
        }
    }
}

#include "generated/data/fallout_shared/packagedataeat.inc"
