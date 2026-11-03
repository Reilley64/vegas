
// src/fallout_shared/packagedataescort.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedataescort.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_0067ad20_Class.h"
#include "fnv/decl/FUN_0067fb60_shell.h"
#include "fnv/decl/FUN_0067fbe0_cls.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_0067f6c0__FUN_0067f6c0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_01068000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/decl/fnv_0067f600__FUN_0067f600_shell.h"
struct TESEscortPackageData
{
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

// Calls the base constructor, sets the vtable to DAT_01068960, clears m_flags, stores *pForm into m_form and returns this.
// @fnv 0x0067bc60
FUN_0067bc60_shell* FUN_0067bc60_shell::ConstructFromForm(TESForm** pForm)
{
    new ((void *)(((FUN_0067ad20_shell*)this))) ::FUN_0067ad20_Class();
    m_vtbl = &DAT_01068960;
    m_flags = 0;
    m_form = *pForm;
    return this;
}

namespace fnv_0067bec0 {
struct IntegerData
{
    int m_iValue;
};
struct BipedModelForm
{
};
struct LocationDescriptor
{
};
struct TESEscortPackageData
{
    void* base;
    LocationDescriptor* m_pPackageTarget;
    int m_iValue;
    void FUN_0067bec0();
};
// @fnv 0x0067bec0
void TESEscortPackageData::FUN_0067bec0()
{
    IntegerData valueBlock;
    ::FUN_00403d30(&valueBlock, 0, 4);
    valueBlock.m_iValue = m_iValue;
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>((((BipedModelForm*)&valueBlock)))->FUN_00503210();
    ::AppendChunk(0x32454b50, &valueBlock, 4);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>((((BipedModelForm*)&valueBlock)))->FUN_00503210();
    if (m_pPackageTarget)
        reinterpret_cast<::fnv_0067f6c0::FUN_0067f6c0_shell *>((m_pPackageTarget))->FUN_0067f6c0(0x32444c50);
}
}  // namespace fnv_0067bec0

namespace fnv_0067bf40 {
struct BGSSaveFormBuffer
{
};
struct FUN_0067fb60_holder
{
};
struct TESEscortPackageData
{
    void* pBase;
    void* m_pPackageTarget;
    void FUN_0067bf40(BGSSaveFormBuffer* buffer);
};
// @fnv 0x0067bf40
void TESEscortPackageData::FUN_0067bf40(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<char*>(this) + 8, 4, 0);
    bool hasLocation = (m_pPackageTarget != 0) ? true : false;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(reinterpret_cast<char*>(&hasLocation), 1, 0);
    if (hasLocation)
        reinterpret_cast<::FUN_0067fb60_shell *>((reinterpret_cast<FUN_0067fb60_holder*>(m_pPackageTarget)))->FUN_0067fb60((::LocationInputStream *)(buffer));
}
}  // namespace fnv_0067bf40

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
// Calls FUN_0067bca0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0067bc30
void* TESEscortPackageData::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0067bca0 *>(this)->FUN_0067bca0::~FUN_0067bca0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x0067bca0
FUN_0067bca0::~FUN_0067bca0()
{
    delete m_pLoc;
}

namespace fnv_0067c330 {
struct BGSLoadFormBuffer
{
};
struct LocationDescriptor
{
    LocationDescriptor();
    ~LocationDescriptor();
    int pad[3];
};
struct FUN_0067c330_shell
{
    void* m_base;
    LocationDescriptor* m_pPackageTarget;
    void FUN_0067c330(BGSLoadFormBuffer* buffer);
};
// @fnv 0x0067c330
void FUN_0067c330_shell::FUN_0067c330(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 8)), 4);
    unsigned char hasLocation = 0;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(bool *)((bool*)&hasLocation), 1);
    if (hasLocation)
    {
        m_pPackageTarget = new LocationDescriptor;
        reinterpret_cast<::FUN_0067fbe0_cls *>((m_pPackageTarget))->FUN_0067fbe0((::PackageLoadStream *)(buffer));
    }
}
}  // namespace fnv_0067c330

struct FUN_0067f030 : LocationDescriptor
{
    int unk08;
    FUN_0067f030();
    ~FUN_0067f030();
};

struct TESPackageData
{
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

// @fnv 0x0067bd30
void FUN_0067bd30_shell::LoadPackageData(BGSLoadFormBuffer* pBuffer)
{
    TESPackageData* pData = FUN_00ec43fb(pBuffer, 0, &::DAT_0119bdec, &DAT_0119be60, 0);
    if (pData != 0)
    {
        if (m_pLoc != 0)
        {
            delete m_pLoc;
            m_pLoc = 0;
        }
        if (pData->m_pLoc != 0)
        {
            m_pLoc = new FUN_0067f030();
            reinterpret_cast<::LocationDescriptor *>((((FUN_0067f030*)m_pLoc)))->Copy(pData->m_pLoc, 0);
        }
        m_form = pData->m_form;
    }
}

struct TESEscortPackageData_rtti2
{
    virtual ~TESEscortPackageData_rtti2();  // the original class is polymorphic (rtti_variants.py)
    void FUN_0067bca0();
    void* DestroyIfFlagged(unsigned int);
};

struct TESPackageData_rtti2;

struct TESPackageData_rtti2
{
    virtual ~TESPackageData_rtti2();  // the original class is polymorphic (rtti_variants.py)
    void* unk00;
    FUN_0067f030* m_pLoc;
    TESForm* m_form;
};

extern TESPackageData_rtti2* __cdecl FUN_00ec43fb(BGSLoadFormBuffer* pBuffer, int arg2, const void* arg3, const void* arg4,
                                            int arg5);

struct EscortLocationComparison
{
};

struct EscortComparison
{
    void* m_vtbl;
    LocationDescriptor* m_pPackageTarget;
    int m_iValue;

    bool FUN_0067be40(TESPackageData_rtti2* compare);
};

// @fnv 0x0067be40
bool EscortComparison::FUN_0067be40(TESPackageData_rtti2* compare)
{
    EscortComparison* other = reinterpret_cast<EscortComparison*>(dynamic_cast<TESEscortPackageData_rtti2*>(compare));
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
