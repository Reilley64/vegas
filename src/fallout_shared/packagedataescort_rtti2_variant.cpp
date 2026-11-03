// src/fallout_shared/packagedataescort_rtti2_variant.cpp - RTTI variant unit rebuilt 2026-11-01 from TODAY's src/fallout_shared/packagedataescort.cpp (its skeleton, namespace blocks of integrated candidates out)
// with TESPackageData, TESEscortPackageData made polymorphic, so dynamic_cast<TESEscortPackageData*> compiles next to the file's own names.


// src/fallout_shared/packagedataescort.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataescort.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/FUN_0067ad20_Class.h"
#include "fnv/decl/fnv_0067f600__FUN_0067f600_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_01068000.h"
#include "fnv/symbols_0119b000.h"
struct TESEscortPackageData
{
    virtual ~TESEscortPackageData();  // the original class is polymorphic (rtti_variants.py)
    void FUN_0067bca0();
    void* DestroyIfFlagged(unsigned int);
};
struct TESForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct LocationDescriptor;
struct TESPackageData;
struct FUN_0067ad20_shell
{
};
struct FUN_0067bc60_shell
{
    void* m_vtbl;
    int m_flags;
    TESForm* m_form;
    FUN_0067bc60_shell* ConstructFromForm(TESForm** pForm);
};
struct LocationDescriptor
{
    void* m_vtbl;
    int m_flags;
    ~LocationDescriptor();
public:
    void Copy(::LocationDescriptor *, bool);
};
struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
    LocationDescriptor* m_pLoc;
};
struct FUN_0067bca0 : FUN_0067ad70_cls
{
    ~FUN_0067bca0();
};
struct FUN_0067f030 : LocationDescriptor
{
    int unk08;
    FUN_0067f030();
    ~FUN_0067f030();
};
struct TESPackageData
{
    virtual ~TESPackageData();  // the original class is polymorphic (rtti_variants.py)
    void* unk00;
    FUN_0067f030* m_pLoc;
    TESForm* m_form;
};
struct FUN_0067bd30_shell : FUN_0067ad70_cls
{
    TESForm* m_form;
    void LoadPackageData(BGSLoadFormBuffer* pBuffer);
};
extern const int DAT_0119be60;
extern TESPackageData* __cdecl FUN_00ec43fb(BGSLoadFormBuffer* pBuffer, int arg2, const void* arg3, const void* arg4,
                                            int arg5);

struct EscortLocationComparison
{
};

struct EscortComparison
{
    void* m_vtbl;
    LocationDescriptor* m_pPackageTarget;
    int m_iValue;

    bool FUN_0067be40(TESPackageData* compare);
};

// @fnv 0x0067be40
bool EscortComparison::FUN_0067be40(TESPackageData* compare)
{
    EscortComparison* other = reinterpret_cast<EscortComparison*>(dynamic_cast<TESEscortPackageData*>(compare));
    if (!other)
        return true;
    if (m_pPackageTarget)
    {
        if (reinterpret_cast<::fnv_0067f600::FUN_0067f600_shell *>((reinterpret_cast<EscortLocationComparison*>(m_pPackageTarget)))->IsDifferentFrom(other->m_pPackageTarget))
            return true;
    }
    else if (other->m_pPackageTarget)
    {
        return true;
    }
    if (m_iValue != other->m_iValue)
        return true;
    return false;
}
