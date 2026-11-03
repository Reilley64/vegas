
// src/fallout/ai/trespasspackage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/trespasspackage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/A90Cls.h"
#include "fnv/decl/FUN_00678fd0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_008df040_shell.h"
#include "fnv/decl/FUN_009f9450.h"
#include "fnv/decl/Package679120.h"
#include "fnv/decl/Package6798c0.h"
#include "fnv/decl/fnv_00484ce0__TESSaveLoadGameHelper.h"
#include "fnv/decl/fnv_00484d00__FUN_00484d00_shell.h"
#include "fnv/decl/fnv_00679340__Package679.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_011de000.h"
struct BGSLoadFormBuffer
{
};

struct TESPackage
{
};

struct TrespassPackage : TESPackage
{
    void FUN_009f9840(BGSLoadFormBuffer*);
};

// @fnv 0x009f9840
void TrespassPackage::FUN_009f9840(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::Package6798c0 *>(this)->LoadPackage((::LoadBuffer6798c0 *)(apLoadGameBuffer));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x80)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x84)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x90)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x94)), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((void*)((char*)this + 0x98)), 4);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)((void*)((char*)this + 0x88)));
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)((void*)((char*)this + 0x8c)));
}

struct TrespassPackageShell : TrespassPackage
{
    void* FUN_009f9220(unsigned int flags);
};

// Calls FUN_009f9450, then deletes this when flags has bit 1 set, and returns this.
// @fnv 0x009f9220
void* TrespassPackageShell::FUN_009f9220(unsigned int flags)
{
    reinterpret_cast<::FUN_009f9450 *>(this)->FUN_009f9450::~FUN_009f9450();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct TESForm;

struct FUN_00679a90_shell
{
};

struct FUN_009f98e0_shell : public TrespassPackage
{
    void FUN_009f98e0(uintptr_t);
};

// @fnv 0x009f98e0
void FUN_009f98e0_shell::FUN_009f98e0(uintptr_t a)
{
    reinterpret_cast<::A90Cls *>((((FUN_00679a90_shell*)this)))->DispatchToSubobjects((intptr_t)((void*)a));
    *(TESForm**)((char*)this + 0x88) =
        *(TESForm**)((char*)this + 0x88) ? ::FUN_004839c0((unsigned int)(uintptr_t)(*(TESForm**)((char*)this + 0x88))) : 0;
    *(TESForm**)((char*)this + 0x8c) =
        *(TESForm**)((char*)this + 0x8c) ? ::FUN_004839c0((unsigned int)(uintptr_t)(*(TESForm**)((char*)this + 0x8c))) : 0;
}

struct STR00
{
};
struct FUN_00484d40_Host
{
    void FUN_00484d40(unsigned int*, int);
};
struct Base009f8770
{
};
struct TESSaveLoadGame
{
};
struct TrespassPackageInit : Base009f8770
{
    void LoadTrespassPackage();
};
// @fnv 0x009f9660
void TrespassPackageInit::LoadTrespassPackage()
{
    reinterpret_cast<::fnv_00679340::Package679 *>(this)->FUN_00679340();
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00(this + 0x80, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00(this + 0x84, 4);
    reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00(this + 0x90, 4);
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 0x6c)
    {
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00(this + 0x94, 4);
        reinterpret_cast<::fnv_00484d00::FUN_00484d00_shell *>((((STR00*)this)))->FUN_00484d00(this + 0x98, 4);
    }
    unsigned int v1;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&v1, 4);
    *(unsigned int*)(this + 0x88) = v1;
    unsigned int uiValue8c;
    ((FUN_00484d40_Host*)this)->FUN_00484d40(&uiValue8c, 4);
    *(unsigned int*)(this + 0x8c) = uiValue8c;
}

struct FUN_006797c0_arg;
struct FUN_006797c0_shell
{
public:
    void FUN_006797c0(::FUN_006797c0_arg *);
};
struct BGSSaveFormBuffer
{
};
struct FUN_009f9790_shell
{
    void SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer);
};
// Calls the base save routine, then writes five 4-byte fields at offsets 0x80-0x98 and two pointers at 0x88/0x8c to the save buffer.
// @fnv 0x009f9790
void FUN_009f9790_shell::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    ((FUN_006797c0_shell*)this)->FUN_006797c0((::FUN_006797c0_arg *)(apSaveGameBuffer));
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(this + 0x80, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(this + 0x84, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(this + 0x90, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(this + 0x94, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(this + 0x98, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)(this + 0x88)), 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(void**)(this + 0x8c)), 0);
}

struct Saver
{
};
struct FUN_009f9500_shell : public Saver
{
    unsigned short FUN_009f9500();
};
// Computes the save size: adds FUN_00678fd0's result, 12, 8, and two 4-byte blocks when g_TESSaveLoadGame's version is at least 108.
// @fnv 0x009f9500
unsigned short FUN_009f9500_shell::FUN_009f9500()
{
    unsigned short usSize = 0;
    usSize += reinterpret_cast<::FUN_00678fd0_shell *>(this)->FUN_00678fd0();
    usSize += 12;
    if (reinterpret_cast<::FUN_008df040_shell *>((g_TESSaveLoadGame))->FUN_008df040() >= 108)
    {
        usSize += 4;
        usSize += 4;
    }
    usSize += 8;
    return usSize;
}

struct S00679120
{
};

struct PC7d
{
};

struct FUN_00484d20_Class
{
    void ForwardToSaveLoadGame(intptr_t, int);
};

struct SaveManager
{
};



struct FUN_009f9570_shell
{
    unsigned char padding[0x88];
    TESForm* pOwner;
    TESForm* pReferencedForm;

    void SaveFormRefs();
};

// @fnv 0x009f9570
void FUN_009f9570_shell::SaveFormRefs()
{
    unsigned int iobjectOwnedID;
    unsigned int iownerID;

    reinterpret_cast<::Package679120 *>((reinterpret_cast<S00679120*>(this)))->SavePackage();

    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(
        (void *)(reinterpret_cast<uintptr_t>(reinterpret_cast<unsigned char*>(this) + 0x80)), 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(
        (void *)(reinterpret_cast<uintptr_t>(reinterpret_cast<unsigned char*>(this) + 0x84)), 4);
    reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(
        (void *)(reinterpret_cast<uintptr_t>(reinterpret_cast<unsigned char*>(this) + 0x90)), 4);

    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::SaveManager * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x6c)
    {
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(
            (void *)(reinterpret_cast<uintptr_t>(reinterpret_cast<unsigned char*>(this) + 0x94)), 4);
        reinterpret_cast<::fnv_00484ce0::TESSaveLoadGameHelper *>((reinterpret_cast<PC7d*>(this)))->FUN_00484ce0(
            (void *)(reinterpret_cast<uintptr_t>(reinterpret_cast<unsigned char*>(this) + 0x98)), 4);
    }

    iownerID = 0;
    if (pOwner != 0)
        iownerID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pOwner))->FUN_0084e3a0()));

    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<intptr_t>(&iownerID), 4);

    iobjectOwnedID = 0;
    if (pReferencedForm != 0)
        iobjectOwnedID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pReferencedForm))->FUN_0084e3a0()));

    reinterpret_cast<FUN_00484d20_Class*>(this)->ForwardToSaveLoadGame(reinterpret_cast<intptr_t>(&iobjectOwnedID), 4);
}
