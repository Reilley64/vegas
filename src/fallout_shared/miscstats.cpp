// fallout_shared/miscstats.cpp: MiscStatManager (5 functions)

#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/TESReputation.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01189000.h"
#include "fnv/symbols_011c6000.h"
#include "miscstats_decls.h"

// @fnv 0x004d5e10
void MiscStatManager::AddMiscStat(MiscStat eStat, int delta)
{
    if (delta == 0)
        return;
    if (eStat < MS_COUNT && (*reinterpret_cast<MiscStatEntry * (*)[43]>(&::DAT_011c6d50))[eStat])
    {
        (*reinterpret_cast<MiscStatEntry * (*)[43]>(&::DAT_011c6d50))[eStat]->value += delta;
        ChallengeManager::UpdateChallengeProgress(CHALLENGE_MISCSTAT, delta, 0, 0, (unsigned short)eStat, 0, 0);
        StatsMenu* menu = (StatsMenu*)reinterpret_cast<::FUN_00a03c90_shell *>((((::Tile *)(::FUN_00a09030(FUN_004d5e00())))))->FUN_00a03c90();
        if (menu)
            menu->RefreshMiscStat((*(::MiscStatManager__MiscStatID *)&(eStat)));
    }
    else
    {
        ::FUN_005b5e40();
    }
}

// Copies each of the 0x2B ints from a1 into the second int field of the object pointed to by DAT_011c6d50[i].
// @fnv 0x004d5f20
void CopyIntArrayToObjects(int* aiValues)
{
    for (int i = 0; i < 0x2B; ++i)
        (*reinterpret_cast<MiscStatEntry * (*)[43]>(&::DAT_011c6d50))[i]->value = aiValues[i];
}

// Copies the second int of each of 43 entries from DAT_011c6d50 into the array pointed to by a1.
// @fnv 0x004d5f60
void CopyEntrySecondFields(int* paiOut)
{
    for (int i = 0; i < 43; ++i)
        paiOut[i] = (*reinterpret_cast<MiscStatEntry * (*)[43]>(&::DAT_011c6d50))[i]->value;
}

struct BGSSaveGameBuffer
{
    void* m_pBuffer;
};


// Writes the misc stat count (43) and each stat's value from DAT_011c6d50 to the save buffer, using 0 for null entries.
// @fnv 0x004d5fa0
void SaveMiscStats(BGSSaveGameBuffer* pSave)
{
    int nCount = 43;
    reinterpret_cast<::FUN_00865e50_shell *>((pSave))->FUN_00865e50(&nCount, 4, 0);
    unsigned int i = 0;
    for (; i < (unsigned int)nCount; ++i)
    {
        int nVal;
        if ((*reinterpret_cast<MiscStatEntry * (*)[43]>(&::DAT_011c6d50))[i])
            nVal = (*reinterpret_cast<MiscStatEntry * (*)[43]>(&::DAT_011c6d50))[i]->value;
        else
            nVal = 0;
        int iSaveValue = nVal;
        reinterpret_cast<::FUN_00865e50_shell *>((pSave))->FUN_00865e50(&iSaveValue, 4, 0);
    }
}



// Searches the 0x2b-entry misc stat name table for a1 and returns its index, or warns and returns 0x2b if not found.
// @fnv 0x004d5eb0
int FindMiscStatIndex(const char* pcStatName)
{
    int i;

    for (i = 0; i < 0x2b; ::TESReputation::GetUnsignedIntegerPointer((unsigned int *)(int *)(&i)))
    {
        if (DAT_01189280[i] != 0 && FUN_00404dc0(DAT_01189280[i], pcStatName) == 0)
        {
            return i;
        }
    }
    ::FUN_005b5e40();
    return 0x2b;
}

#include "generated/data/fallout_shared/miscstats.inc"
