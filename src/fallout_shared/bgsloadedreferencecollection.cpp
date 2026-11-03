// fallout_shared/bgsloadedreferencecollection.cpp: LoadedReferenceMap, BGSLoadedReferenceCollection, TESContainer (4 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005271b0_Class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011f6000.h"
#include "bgsloadedreferencecollection.h"

// Inserts pRef into the map by its form ID if absent, increments iCount and records the current timestamp.
// @fnv 0x00526bd0
bool LoadedReferenceMap::AddReference(TESObjectREFR* pRef)
{
    TESObjectREFR* existing = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)this)->FUN_00853130(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pRef))->FUN_0084e3a0())), (::fnv_00853130::CombatThreatRecord *&)(existing)))
        return false;

    reinterpret_cast<::FUN_00844700_Class *>(this)->FUN_00844700(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pRef))->FUN_0084e3a0())), (unsigned int)(pRef));
    iCount++;
    m_uiLastUpdateTime = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
    return true;
}

struct S_00526b40
{
    void FUN_00526b70();
    void* FUN_00526b40(unsigned int);
};
struct TESSound;
struct ExtraRadioData;
struct TESObjectSTAT;


unsigned int _FNV_GetFormType(TESForm* object);

struct TESContainer
{
    static bool __cdecl IsValidContainerType(unsigned char type);
};

struct FUN_00526c40_Class
{
    bool RemoveSound(TESSound* reference);
};

struct TESObjectREFR_ext
{
};

struct BGSLoadedReferenceCollection
{
    unsigned char pad0[0x18];
    FUN_00526c40_Class member18;
    unsigned char pad1[0x47];
    FUN_00526c40_Class member60;
    unsigned char pad2[0x17];
    FUN_00526c40_Class member78;
    unsigned char pad3[0x17];
    FUN_00526c40_Class member90;
    unsigned char pad4[0x17];
    FUN_00526c40_Class memberA8;

    void FUN_005270b0(TESObjectREFR* apRef);
};

// Gets the form type of apRef's base object and adds apRef to the collection's per-type lists based on that type and extra data.
// @fnv 0x005270b0
void BGSLoadedReferenceCollection::FUN_005270b0(TESObjectREFR* apRef)
{
    unsigned int eformType;

    eformType = _FNV_GetFormType(((::TESObjectREFR *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430())));

    if (TESContainer::IsValidContainerType((unsigned char)eformType))
    {
        LoadedReferenceMap* prefMap;

        member18.RemoveSound(reinterpret_cast<TESSound*>(apRef));
        prefMap = reinterpret_cast<LoadedReferenceMap*>(reinterpret_cast<::FUN_005271b0_Class *>(this)->GetFieldByType(eformType));
        if (prefMap)
            reinterpret_cast<FUN_00526c40_Class*>(prefMap)->RemoveSound(reinterpret_cast<TESSound*>(apRef));
    }

    if (eformType == 0x1B)
        member60.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (eformType == 0x2A || eformType == 0x2B)
        member78.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (((::TESObjectREFR *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430())) == reinterpret_cast<void*>(::DAT_011ca264))
        member90.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (eformType == 0x51)
        member90.RemoveSound(reinterpret_cast<TESSound*>(apRef));

    if (eformType == 0x1C && reinterpret_cast<::TESObjectREFR *>((reinterpret_cast<TESObjectREFR_ext*>(apRef)))->GetExtraRadioData())
        memberA8.RemoveSound(reinterpret_cast<TESSound*>(apRef));
}

struct Base_00527840
{
    virtual ~Base_00527840();
};

struct FUN_00526b70 : Base_00527840
{
    ~FUN_00526b70();
};
// Calls FUN_00526b70, then frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x00526b40
void* S_00526b40::FUN_00526b40(unsigned int flags)
{
    reinterpret_cast<::FUN_00526b70 *>((this))->FUN_00526b70::~FUN_00526b70();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls FUN_00438af0 on the base object.
// @fnv 0x00526b70
FUN_00526b70::~FUN_00526b70()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}
