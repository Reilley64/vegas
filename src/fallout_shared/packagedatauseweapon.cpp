// fallout_shared/packagedatauseweapon.cpp: TESUseWeaponPackageData, UseWeaponActorPackageData, DelStandIn, UseWeaponLoader and more (16 functions)

#include <cstdint>
#include "fnv/decl/C80720Target.h"
#include "fnv/decl/DurationData.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00421b40_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0067ca10_cls.h"
#include "fnv/decl/FUN_0067d970_Class.h"
#include "fnv/decl/FUN_0067fb60_shell.h"
#include "fnv/decl/FUN_0067fbe0_cls.h"
#include "fnv/decl/FUN_0067fc50_shell.h"
#include "fnv/decl/FUN_006801a0_shell.h"
#include "fnv/decl/FUN_00680830_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_006807b0_Target.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0067f600__FUN_0067f600_shell.h"
#include "fnv/decl/fnv_0067f6c0__FUN_0067f6c0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_01068000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011ca000.h"
#include "packagedatauseweapon_decls.h"
#include "packagelocation_package.h"

// @fnv 0x0067d1c0
void TESUseWeaponPackageData::InitItem(TESForm* item)
{
    LocationDescriptor* package = reinterpret_cast<LocationDescriptor*>(item);
    bool initializeTarget;
    {
        LocationDescriptor* location = reinterpret_cast<::TESPackage*>(item)->pPackageLocation;
        initializeTarget = true;
        if (!m_pUseTarget && location && reinterpret_cast<::DurationData *>((reinterpret_cast<TESObjectREFR*>(location)))->FUN_00678ca0() == 0)
        {
            TESObjectREFR* reference = location->GetLocationReference();
            if (reference)
            {
                TESBoundObject* object = ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reference))->FUN_007af430()));
                if (object == DAT_011ca244 || object == DAT_011ca248)
                {
                    ExtraDataList* extra = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()));
                    if (extra)
                    {
                        TESObjectREFR* target = reinterpret_cast<::FUN_00421b40_shell *>((extra))->FUN_00421b40();
                        if (target)
                        {
                            m_pUseTarget = new PackageTargetRecord;
                            m_pUseTarget->SetTargetKind(PACK_TARG_REFERENCE);
                            m_pUseTarget->SetTargetObjectReference(target);
                            initializeTarget = false;
                        }
                    }
                }
            }
        }
        if (m_pUseTarget && initializeTarget)
            m_pUseTarget->InitItem(item);
        unsigned int weaponID = (unsigned int)reinterpret_cast<std::uintptr_t>(pWeapon);
        pWeapon = dynamic_cast<TESObjectWEAP*>(::FUN_004839c0(weaponID));
    }
}

// Clears the stored reference if it equals the passed reference.
// @fnv 0x0067d9e0
void UseWeaponActorPackageData::SetReferenceTarget(TESObjectREFR* reference)
{
    m_pUseTarget = m_pUseTarget == reference ? 0 : m_pUseTarget;
}

struct FUN_00670b30
{
    void* __vecDelDtor(unsigned int);
};

struct Date
{
    void* __vecDelDtor(unsigned int);
};

struct FUN_0067ad70_cls
{
    virtual ~FUN_0067ad70_cls();
};

struct FUN_0067ccd0_cls : FUN_0067ad70_cls
{
    Date* date;
    FUN_00670b30* data;
    virtual ~FUN_0067ccd0_cls();
};

// Destructor that deletes the date and data members via their vector deleting destructors and nulls both pointers.
// @fnv 0x0067ccd0
FUN_0067ccd0_cls::~FUN_0067ccd0_cls()
{
    Date* b = date;
    Date* a = b;
    a ? a->__vecDelDtor(1) : 0;
    date = 0;
    FUN_00670b30* d = data;
    FUN_00670b30* c = d;
    c ? c->__vecDelDtor(1) : 0;
    data = 0;
}

namespace fnv_0067cb40 {
namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* DestroyIfFlagged(unsigned int flags);
};
// Runs the destructor on this, then frees this via Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x0067cb40
void* DelStandIn::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0067ccd0_cls *>((((DtorStandIn*)this)))->FUN_0067ccd0_cls::~FUN_0067ccd0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}
}  // namespace fnv_0067cb40

struct BGSLoadFormBuffer;

struct FUN_00680830_impl
{
};
struct FUN_0067fc50_impl
{
};

struct FUN_0067d8b0_shell
{
    void* m00;
    void* m04;
    void* m08;
    void LoadForm(BGSLoadFormBuffer*);
};

// Calls the load routine on m04 and then on m08, each with the load game buffer, when the pointer is non-null.
// @fnv 0x0067d8b0
void FUN_0067d8b0_shell::LoadForm(BGSLoadFormBuffer* apLoadGameBuffer)
{
    if (m04)
        reinterpret_cast<::FUN_00680830_shell *>((((FUN_00680830_impl*)m04)))->FUN_00680830(apLoadGameBuffer);
    if (m08)
        reinterpret_cast<::FUN_0067fc50_shell *>((((FUN_0067fc50_impl*)m08)))->ResolveObject((std::intptr_t)(apLoadGameBuffer));
}

struct FUN_0067da20_shell
{
    const void* pVtable;
    int iValue;
    void ResetValue(int arg);
};

// @fnv 0x0067da20
void FUN_0067da20_shell::ResetValue(int arg)
{
    iValue = 0;
}

struct FUN_0067d990_shell
{
    void* FUN_0067d990(unsigned int);
};
struct FUN_0067cfc0_shell : TESUseWeaponPackageData
{
    bool FUN_0067cfc0(TESPackageData* apCompare);
};

struct FUN_00680220_shell
{
    bool Compare(PackageTargetRecord* target);
};

struct FUN_0067f600_shell
{
};

void* FUN_00ec43fb(void* object, unsigned int flags, char* typeInfo1, char* typeInfo2, int reserved);

extern char DAT_0119bf00;

// Compares this use-weapon package data against apCompare field by field, returning true when any field differs or the cast fails.
// @fnv 0x0067cfc0
bool FUN_0067cfc0_shell::FUN_0067cfc0(TESPackageData* apCompare)
{
    TESUseWeaponPackageData* pOtherData =
        static_cast<TESUseWeaponPackageData*>(FUN_00ec43fb(apCompare, 0, &(*reinterpret_cast<char *>(&::DAT_0119bdec)), &DAT_0119bf00, 0));

    if (!pOtherData)
        return true;

    if (this->pWeapon != pOtherData->pWeapon)
        return true;

    if (this->m_pUseTarget)
    {
        if (reinterpret_cast<FUN_00680220_shell*>(this->m_pUseTarget)->Compare(pOtherData->m_pUseTarget))
            return true;
    }
    else if (pOtherData->m_pUseTarget)
    {
        return true;
    }

    if (this->m_pTargetLocation)
    {
        if (reinterpret_cast<::fnv_0067f600::FUN_0067f600_shell *>((reinterpret_cast<FUN_0067f600_shell*>(this->m_pTargetLocation)))->IsDifferentFrom((::LocationDescriptor *)(void *)(static_cast<void*>(pOtherData->m_pTargetLocation))))
            return true;
    }
    else if (pOtherData->m_pTargetLocation)
    {
        return true;
    }

    if (this->m_bFlag1 != pOtherData->m_bFlag1)
        return true;

    if (this->m_bFlag2 != pOtherData->m_bFlag2)
        return true;

    if (this->m_bFlag3 != pOtherData->m_bFlag3)
        return true;

    if (this->m_bFlag4 != pOtherData->m_bFlag4)
        return true;

    if (this->m_bFlag5 != pOtherData->m_bFlag5)
        return true;

    if (this->m_bFlag6 != pOtherData->m_bFlag6)
        return true;

    if (this->m_usValue1 != pOtherData->m_usValue1)
        return true;

    if (this->m_usValue2 != pOtherData->m_usValue2)
        return true;

    if (this->m_usValue3 != pOtherData->m_usValue3)
        return true;

    if (FUN_00408860(this->m_fValue1 - pOtherData->m_fValue1) > 0.01)
        return true;

    if (FUN_00408860(this->m_fValue2 - pOtherData->m_fValue2) > 0.01)
        return true;

    return false;
}


struct FUN_006802f0_shell
{
    void FUN_006802f0(int);
};

struct PackageLocationSave
{
};

struct FlaggedValueData
{
    bool m_bFlag1;
    bool m_bFlag2;
    bool m_bFlag3;
    bool m_bFlag4;
    bool m_bFlag5;
    bool m_bFlag6;
    unsigned short m_usValue1;
    unsigned short m_usValue2;
    unsigned short m_usValue3;
    float m_fValue1;
    float m_fValue2;
    unsigned int m_uiIntegerValue;

};

struct FUN_0067d350_shell
{
    unsigned int base;
    void* m_pUseTarget;
    LocationDescriptor* m_pTargetLocation;
    bool m_bFlag1;
    bool m_bFlag2;
    bool m_bFlag3;
    bool m_bFlag4;
    bool m_bFlag5;
    bool m_bFlag6;
    unsigned short m_usValue1;
    unsigned short m_usValue2;
    unsigned short m_usValue3;
    float m_fValue1;
    float m_fValue2;
    TESObjectWEAP* pWeapon;

    void FUN_0067d350();
};

// @fnv 0x0067d350
void FUN_0067d350_shell::FUN_0067d350()
{
    FlaggedValueData saveData;

    ::FUN_00403d30(&saveData, 0, 0x18);

    saveData.m_bFlag1 = this->m_bFlag1;
    saveData.m_bFlag2 = this->m_bFlag2;
    saveData.m_bFlag3 = this->m_bFlag3;
    saveData.m_bFlag4 = this->m_bFlag4;
    saveData.m_bFlag5 = this->m_bFlag5;
    saveData.m_bFlag6 = this->m_bFlag6;
    saveData.m_usValue1 = this->m_usValue1;
    saveData.m_usValue2 = this->m_usValue2;
    saveData.m_usValue3 = this->m_usValue3;
    saveData.m_fValue1 = this->m_fValue1;
    saveData.m_fValue2 = this->m_fValue2;

    saveData.m_uiIntegerValue = this->pWeapon ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->pWeapon))->FUN_0084e3a0())) : 0;

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_0067ca10_cls *>(&(saveData))->FUN_0067ca10();

    ::AppendChunk(0x33574b50, &saveData, 0x18);

    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_0067ca10_cls *>(&(saveData))->FUN_0067ca10();

    if (this->m_pUseTarget)
        reinterpret_cast<FUN_006802f0_shell*>(this->m_pUseTarget)->FUN_006802f0(0x32445450);

    if (this->m_pTargetLocation)
        reinterpret_cast<::fnv_0067f6c0::FUN_0067f6c0_shell *>((reinterpret_cast<PackageLocationSave*>(this->m_pTargetLocation)))->FUN_0067f6c0(0x32444c50);
}

struct B67CC20Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

struct B67CC20Info
{
    unsigned char m_ucType;
    unsigned char m_ucPad;
    unsigned short m_usElementCount;
};

struct B67CC20Range
{
    unsigned short m_usMin;
    unsigned short m_usMax;
};

class B67CC20Base
{
  public:
    B67CC20Base();
    virtual ~B67CC20Base();
};

class FUN_0067cc20 : public B67CC20Base
{
  public:
    int m_iA;
    int m_iB;
    unsigned char m_ucR;
    unsigned char m_ucG;
    unsigned char m_ucB;
    unsigned char m_ucA;
    unsigned char m_ucType;
    bool m_bUnknownFlag;
    unsigned short m_usElementCount;
    unsigned short m_usMin;
    unsigned short m_usMax;
    float m_fStartValue;
    float m_fEnd;
    int m_iC;

    FUN_0067cc20(B67CC20Color kColor, B67CC20Info kInfo, B67CC20Range kRange, float fStart, float m_fEndValue);
    virtual ~FUN_0067cc20();
};

// Initializes the color, type, range and start/end fields from the constructor arguments and zeroes the three int counters.
// @fnv 0x0067cc20
FUN_0067cc20::FUN_0067cc20(B67CC20Color kColor, B67CC20Info kInfo, B67CC20Range kRange, float fStart, float m_fEndValue)
{
    m_iA = 0;
    m_iB = 0;
    m_iC = 0;
    m_ucR = kColor.r;
    m_ucG = kColor.g;
    m_ucB = kColor.b;
    m_ucA = kColor.a;
    m_ucType = kInfo.m_ucType;
    m_bUnknownFlag = kInfo.m_usElementCount <= 0;
    m_usElementCount = kInfo.m_usElementCount;
    m_usMin = kRange.m_usMin;
    m_usMax = kRange.m_usMax;
    m_fStartValue = fStart;
    m_fEnd = m_fEndValue;
}

// Copy the optional extra data from another object: create ours on demand, or drop it when the source is null.


class D470Source;

class D470ExtraData
{
  public:
    D470ExtraData();
    ~D470ExtraData();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class D470Owner
{
  public:
    int unk00;
    D470ExtraData* m_pExtraData;

    void SetExtraData(D470Source* pkSource);
};

// @fnv 0x0067d470
void D470Owner::SetExtraData(D470Source* pkSource)
{
    if (pkSource)
    {
        if (!m_pExtraData)
            m_pExtraData = new D470ExtraData;
        reinterpret_cast<::FUN_006801a0_shell *>((m_pExtraData))->FUN_006801a0((::PackageTargetRecord *)(pkSource));
    }
    else
    {
        delete m_pExtraData;
        m_pExtraData = 0;
    }
}

struct BGSLoadFormBuffer
{
};
struct PackageTargetObj : PackageTargetRecord
{
    PackageTargetObj();
};
struct PackageLocationObj
{
    unsigned int type;
    unsigned int location;
    unsigned int radius;
    PackageLocationObj();
};
struct UseWeaponLoader : TESUseWeaponPackageData
{
    void LoadUseWeaponData(BGSLoadFormBuffer* buffer);
};
// Reads the use-weapon package data from the buffer: fixed-size fields, a weapon form, and optional target and location objects.
// @fnv 0x0067d6b0
void UseWeaponLoader::LoadUseWeaponData(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFlag1), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFlag2), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFlag3), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFlag4), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFlag5), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_bFlag6), 1);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_usValue1), 2);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_usValue2), 2);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_usValue3), 2);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fValue1), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fValue2), 4);
    pWeapon = dynamic_cast<TESObjectWEAP*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
    bool hasTarget;
    bool hasLocation = false;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&hasLocation), 1);
    if (hasLocation)
    {
        m_pUseTarget = new PackageTargetObj;
        reinterpret_cast<::S_006807b0_Target *>((static_cast<PackageTargetObj*>(m_pUseTarget)))->FUN_006807b0((::S_006807b0_Stream *)(buffer));
    }
    hasTarget = false;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&hasTarget), 1);
    if (hasTarget)
    {
        m_pTargetLocation = reinterpret_cast<LocationDescriptor*>(new PackageLocationObj);
        reinterpret_cast<::FUN_0067fbe0_cls *>((reinterpret_cast<PackageLocationObj*>(m_pTargetLocation)))->FUN_0067fbe0((::PackageLoadStream *)(buffer));
    }
}


struct FUN_0067d9c0_cls
{
    void* m_vptr;
    void InitVTableAndInit();
};
// Calls InitVTableAndInit, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0067d990
void* FUN_0067d990_shell::FUN_0067d990(unsigned int flags)
{
    reinterpret_cast<::FUN_0067d9c0_cls *>(this)->InitVTableAndInit();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0067d9c0
void FUN_0067d9c0_cls::InitVTableAndInit()
{
    m_vptr = &DAT_01068a88;
    reinterpret_cast<::FUN_0067d970_Class *>(this)->FUN_0067d970();
}

void* FUN_00ec43fb(void* object, unsigned int flags, char* typeInfo1, char* typeInfo2, int reserved);
extern char DAT_0119bf00;

struct Target_Stub : PackageTargetRecord
{
    Target_Stub();
    ~Target_Stub();
};

struct TargetLocation_Stub
{
    int unk00;
    int unk04;
    int unk08;
    TargetLocation_Stub();
    ~TargetLocation_Stub();
};

struct UseWeaponPackageData_Shell : TESUseWeaponPackageData
{
    void FUN_0067cd90(TESPackageData* apSource);
};

// Copies a TESUseWeaponPackageData obtained from apSource into this, deep-copying its two sub-objects and copying the remaining fields.
// @fnv 0x0067cd90
void UseWeaponPackageData_Shell::FUN_0067cd90(TESPackageData* apSource)
{
    TESUseWeaponPackageData* target =
        (TESUseWeaponPackageData*)FUN_00ec43fb(apSource, 0, &(*reinterpret_cast<char *>(&::DAT_0119bdec)), &DAT_0119bf00, 0);
    if (!target)
    {
        return;
    }

    delete (Target_Stub*)this->m_pUseTarget;
    this->m_pUseTarget = 0;

    if (target->m_pUseTarget)
    {
        this->m_pUseTarget = new Target_Stub();
        reinterpret_cast<::FUN_006801a0_shell *>((((Target_Stub*)this->m_pUseTarget)))->FUN_006801a0(target->m_pUseTarget);
    }

    this->pWeapon = target->pWeapon;

    delete (TargetLocation_Stub*)this->m_pTargetLocation;
    this->m_pTargetLocation = 0;

    if (target->m_pTargetLocation)
    {
        this->m_pTargetLocation = (LocationDescriptor*)new TargetLocation_Stub();
        reinterpret_cast<::LocationDescriptor *>((((TargetLocation_Stub*)this->m_pTargetLocation)))->Copy(target->m_pTargetLocation, false);
    }

    this->m_bFlag1 = target->m_bFlag1;
    this->m_bFlag2 = target->m_bFlag2;
    this->m_bFlag3 = target->m_bFlag3;
    this->m_bFlag4 = target->m_bFlag4;
    this->m_bFlag5 = target->m_bFlag5;
    this->m_bFlag6 = target->m_bFlag6;
    this->m_usValue1 = target->m_usValue1;
    this->m_usValue2 = target->m_usValue2;
    this->m_usValue3 = target->m_usValue3;
    this->m_fValue1 = target->m_fValue1;
    this->m_fValue2 = target->m_fValue2;
}

struct BGSSaveFormBuffer
{
  public:
};
struct TargetSave
{
};
struct LocationSave
{
};
struct WorkerWeapon : TESUseWeaponPackageData
{
    void FUN_0067d550(BGSSaveFormBuffer*);
};
// @fnv 0x0067d550
void WorkerWeapon::FUN_0067d550(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_bFlag1, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_bFlag2, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_bFlag3, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_bFlag4, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_bFlag5, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_bFlag6, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_usValue1, 2, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_usValue2, 2, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_usValue3, 2, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_fValue1, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&m_fValue2, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pWeapon), 0);
    bool p = m_pUseTarget;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&p, 1, 0);
    if (p)
        reinterpret_cast<::C80720Target *>((((TargetSave*)m_pUseTarget)))->SaveToBuffer((::C80720SaveBuffer *)(buffer));
    bool bHasLocation = m_pTargetLocation;
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&bHasLocation, 1, 0);
    if (bHasLocation)
        reinterpret_cast<::FUN_0067fb60_shell *>((((LocationSave*)m_pTargetLocation)))->FUN_0067fb60((::LocationInputStream *)(buffer));
}

class FUN_0067ad20_Class
{
  public:
    FUN_0067ad20_Class();
    virtual ~FUN_0067ad20_Class();
};

struct Data67CB
{
    char m_c00;
    char m_c01;
    char m_c02;
    char m_c03;
    char m_c04;
    char m_c05;
    short m_s06;
    short m_s08;
    short m_s0A;
    float m_f0C;
    float m_f10;
};

class FUN_0067cb70 : public FUN_0067ad20_Class
{
  public:
    int m_unk04;
    int m_unk08;
    Data67CB m_kData;
    int m_unk20;

    FUN_0067cb70(Data67CB kData, int iParam);
    virtual ~FUN_0067cb70();
};

// Constructor that initializes m_unk04 and m_unk08 to zero, copies kData into m_kData, and stores iParam in m_unk20.
// @fnv 0x0067cb70
FUN_0067cb70::FUN_0067cb70(Data67CB kData, int iParam)
{
    m_unk04 = 0;
    m_unk08 = 0;
    m_unk20 = iParam;
    m_kData.m_c00 = kData.m_c00;
    m_kData.m_c01 = kData.m_c01;
    m_kData.m_c02 = kData.m_c02;
    m_kData.m_c03 = kData.m_c03;
    m_kData.m_c04 = kData.m_c04;
    m_kData.m_c05 = kData.m_c05;
    m_kData.m_s06 = kData.m_s06;
    m_kData.m_s08 = kData.m_s08;
    m_kData.m_s0A = kData.m_s0A;
    m_kData.m_f0C = kData.m_f0C;
    m_kData.m_f10 = kData.m_f10;
}

#include "generated/data/fallout_shared/packagedatauseweapon.inc"
