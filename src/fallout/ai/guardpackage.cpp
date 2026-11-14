// fallout/ai/guardpackage.cpp: GuardActorPackageData, std (6 functions)

#include <cstdint>
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00483000.h"
#include "guardpackage_decls.h"
// @fnv 0x00408840
double std::abs(float value)
{
    return ((double)(::FUN_00408860(value)));
}
// Reads eState, a second dword, iWarningCount and a trailing value from the load buffer.
// @fnv 0x009f28b0
void GuardActorPackageData::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&eState), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fWarningTimer), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&iWarningCount), 4);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((buffer))->FUN_008648e0((unsigned int *)(void *)(&pWarningTarget));
}
// Resolves the stored form reference to an Actor and, if found, calls the reference helper with true.
// @fnv 0x009f2900
void GuardActorPackageData::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    pWarningTarget =
        pWarningTarget ? dynamic_cast<Actor*>(::FUN_004839c0((unsigned int)(uintptr_t)pWarningTarget)) : 0;
    if (pWarningTarget)
        reinterpret_cast<::fnv_00564db0::FUN_00564db0_cls *>((((TESObjectREFRHelper*)pWarningTarget)))->FUN_00564db0(true);
}

struct FUN_009f2800Stub
{
    void FUN_009f2830();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_009f2830, frees this when bit 0 of flags is set, and returns this.
// @fnv 0x009f2800
void* FUN_009f2800Stub::DestroyIfFlagged(unsigned int flags)
{
    FUN_009f2830();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BGSSaveFormBuffer
{
};
struct FUN_009f2850_holder
{
    int unk00;
    int unk04;
    void* unk08;
    int unk0C;
    int unk10;
    void SaveToBuffer(BGSSaveFormBuffer*);
};
// @fnv 0x009f2850
void FUN_009f2850_holder::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&unk04, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&unk10, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&unk0C, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(unk08), 0);
}

extern int DAT_010933c8;

struct FUN_0067d970_Class
{
    void FUN_0067d970();
};

// @fnv 0x009f2830
void FUN_009f2800Stub::FUN_009f2830()
{
    *reinterpret_cast<intptr_t*>(this) = reinterpret_cast<intptr_t>(&DAT_010933c8);
    reinterpret_cast<FUN_0067d970_Class*>(this)->FUN_0067d970();
}
