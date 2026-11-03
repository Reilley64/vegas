// src/fallout_shared/packagedatauseitem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatauseitem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/fnv_0067f600__FUN_0067f600_shell.h"
#include "fnv/decl/fnv_0067f6c0__FUN_0067f6c0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0119b000.h"
struct LocationDescriptor
{
    void Save(int);
};
struct TESPackageData
{
    void Save(int);
};
struct TESUseItemPackageData
{
    TESPackageData base;
    LocationDescriptor* m_pPackageTarget;
    void FUN_0067c9d0();
};

// @fnv 0x0067c9d0
void TESUseItemPackageData::FUN_0067c9d0()
{
    ::FUN_004856d0(0x44495550);
    if (this->m_pPackageTarget != 0)
        reinterpret_cast<::fnv_0067f6c0::FUN_0067f6c0_shell *>((this->m_pPackageTarget))->FUN_0067f6c0(0x32444c50);
}

struct FUN_0067c7a0_shell : TESUseItemPackageData
{
    void FUN_0067c7d0();
    void* FUN_0067c7a0(unsigned int flags);
};
struct FUN_0067ad70
{
    virtual ~FUN_0067ad70();
};
struct LocationShell
{
    ~LocationShell();
};
struct FUN_0067c7d0 : FUN_0067ad70
{
    LocationShell* m_pPackageTarget;
    virtual ~FUN_0067c7d0();
};
// @fnv 0x0067c7a0
void* FUN_0067c7a0_shell::FUN_0067c7a0(unsigned int flags)
{
    reinterpret_cast<::FUN_0067c7d0 *>(this)->FUN_0067c7d0::~FUN_0067c7d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x0067c7d0
FUN_0067c7d0::~FUN_0067c7d0()
{
    delete m_pPackageTarget;
}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long vf, void* src, void* tgt, int isRef);
extern int DAT_0119bed8;
struct FUN_0067f600_shell
{
};
struct FUN_0067c960_shell : TESUseItemPackageData
{
    bool FUN_0067c960(TESPackageData* apCompare);
};
// Returns true if the cast fails, the target comparison returns true, or only the other target is non-null.
// @fnv 0x0067c960
bool FUN_0067c960_shell::FUN_0067c960(TESPackageData* apCompare)
{
    TESUseItemPackageData* pUseItemData =
        (TESUseItemPackageData*)FUN_00ec43fb(apCompare, 0, &DAT_0119bdec, &DAT_0119bed8, 0);
    if (!pUseItemData)
        return true;
    if (m_pPackageTarget)
    {
        if (reinterpret_cast<::fnv_0067f600::FUN_0067f600_shell *>((((FUN_0067f600_shell*)m_pPackageTarget)))->IsDifferentFrom((::LocationDescriptor *)(::FUN_0067f600_shell *)((FUN_0067f600_shell*)pUseItemData->m_pPackageTarget)))
            return true;
    }
    else if (pUseItemData->m_pPackageTarget)
        return true;
    return false;
}

// src/fallout_shared/packagedatauseitem_rtti_variant.cpp - RTTI variant unit created 2026-10-24 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESPackageData_rtti, TESUseItemPackageData_rtti). The skeleton of src/fallout_shared/packagedatauseitem.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

// src/fallout_shared/packagedatauseitem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatauseitem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl FUN_004856d0(int);

struct TESPackageData_rtti
{
    virtual ~TESPackageData_rtti();  // the original class is polymorphic (rtti_variants.py)
    void Save(int);
};

struct TESUseItemPackageData_rtti
{
    virtual ~TESUseItemPackageData_rtti();  // the original class is polymorphic (rtti_variants.py)
    TESPackageData_rtti base;
    LocationDescriptor* m_pPackageTarget;
    void FUN_0067c9d0();
};

struct FUN_0067c7a0_shell_rtti : TESUseItemPackageData_rtti
{
    void FUN_0067c7d0();
    void* FUN_0067c7a0(unsigned int flags);
};

struct LocationDescriptor_rtti_decl
{
    void Save(int);
    unsigned int u0, u4, u8;
    LocationDescriptor_rtti_decl();
    ~LocationDescriptor_rtti_decl();
public:
    void Copy(::LocationDescriptor_rtti_decl *, bool);
};

struct TESPackageData_rtti_decl
{
    virtual ~TESPackageData_rtti_decl();  // the original class is polymorphic (rtti_variants.py)
    void Save(int);
};

struct TESUseItemPackageData_rtti_decl : TESPackageData_rtti_decl
{
    virtual ~TESUseItemPackageData_rtti_decl();  // the original class is polymorphic (rtti_variants.py)
    LocationDescriptor_rtti_decl* m_pPackageTarget;
    void FUN_0067c9d0();
    void FUN_0067c860(TESPackageData_rtti_decl* source);
};

struct FUN_0067c7a0_shell_rtti_decl : TESUseItemPackageData_rtti_decl
{
    void FUN_0067c7d0();
    void* FUN_0067c7a0(unsigned int flags);
};

// @fnv 0x0067c860
void TESUseItemPackageData_rtti_decl::FUN_0067c860(TESPackageData_rtti_decl* source)
{
    TESUseItemPackageData_rtti_decl* copy = dynamic_cast<TESUseItemPackageData_rtti_decl*>(source);
    if (copy)
    {
        if (m_pPackageTarget)
        {
            delete m_pPackageTarget;
            m_pPackageTarget = 0;
        }
        if (copy->m_pPackageTarget)
        {
            m_pPackageTarget = new LocationDescriptor_rtti_decl;
            m_pPackageTarget->Copy(copy->m_pPackageTarget, false);
        }
    }
}
