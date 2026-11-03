// fallout/ai/combat/combattimer.cpp: free functions (4 functions)

#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00435000.h"
#include "combattimer_decls.h"
// Reads a 4-byte timestamp from the load buffer and, if it is within the relative range, offsets it by the current game time.
// @fnv 0x009a5ff0
void CombatTargetTimestamp::LoadGame(BGSLoadGameBuffer* pLoadBuffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pLoadBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&fTimeStamp), 4);
    if (fTimeStamp < DAT_0108e360 && fTimeStamp > -DAT_0108e360)
        fTimeStamp = ::FUN_00435dd0() + fTimeStamp;
}
// @fnv 0x009a5f20
void TimeoutTimer::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fStartTime), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_fTimeout), 4);
    if (m_fStartTime < DAT_0108e360 && m_fStartTime > -DAT_0108e360)
        m_fStartTime = m_fStartTime + DAT_011f1bf0;
}

struct BGSSaveFormBuffer
{
};

struct FUN_009a5eb0_shell
{
    float m_fStartTime;
    float field_4;
    void __thiscall FUN_009a5eb0(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009a5eb0
void FUN_009a5eb0_shell::FUN_009a5eb0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    float foffsetStartTime = this->m_fStartTime;
    if (this->m_fStartTime < DAT_0108e360 && -DAT_0108e360 < this->m_fStartTime)
        foffsetStartTime -= DAT_011f1bf0;
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&foffsetStartTime, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&this->field_4, 4, 0);
}

namespace fnv_009a5f90 {
struct BGSSaveFormBuffer
{
};

struct FUN_009a5f90_shell
{
    float fTimeStamp;
    void SaveTimeStamp(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009a5f90
void FUN_009a5f90_shell::SaveTimeStamp(BGSSaveFormBuffer* apSaveGameBuffer)
{
    float fSavedTimeStamp = fTimeStamp;
    if (fTimeStamp < DAT_0108e360 && fTimeStamp > -DAT_0108e360)
    {
        fSavedTimeStamp -= ::FUN_00435dd0();
    }
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&fSavedTimeStamp, 4, 0);
}
}  // namespace fnv_009a5f90
