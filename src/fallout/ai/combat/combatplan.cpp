
// src/fallout/ai/combat/combatplan.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatplan.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/FUN_00993fd0_class.h"
#include "fnv/decl/SearchList.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00982000.h"
#include "fnv/symbols_00994000.h"
struct FUN_00994860_obj
{
};

struct CombatPlan
{
    bool FUN_00981940(int aiAction);
    unsigned int pad00[0x28];
    void* unka0;
};

// Returns the result of ContainsValue(aiAction) on the object at offset 0xa0, or false if that pointer is null.
// @fnv 0x00981940
bool CombatPlan::FUN_00981940(int aiAction)
{
    if (*reinterpret_cast<FUN_00994860_obj**>(&this->unka0))
        return reinterpret_cast<::SearchList *>(((*reinterpret_cast<FUN_00994860_obj**>(&this->unka0))))->ContainsValue(aiAction);
    return false;
}

struct Entry
{
    int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct StreamReader
{
};


class FUN_009949a0_cls
{
  public:
    Entry** m_entries;
    unsigned int m_uiItemCount;
    unsigned int unk08;
    intptr_t unk0C;

    void ReadFromStream(StreamReader* reader);
};

// Reads a count, allocates entries and fills each from the stream, then reads a trailing value and flag into unk08 and unk0C.
// @fnv 0x009949a0
void FUN_009949a0_cls::ReadFromStream(StreamReader* reader)
{
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&m_uiItemCount), 4);
    reinterpret_cast<::FUN_00993fd0_class *>(this)->AllocateItemArray(m_uiItemCount);

    for (unsigned int uiIndex = 0; uiIndex < m_uiItemCount; ++uiIndex)
    {
        Entry* entry = m_entries[uiIndex];
        bool flag = false;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&flag), 1);
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&entry->unk0C), 4);
        entry->unk00 = ::FUN_00982070(flag);
        entry->unk04 = 0;
        entry->unk08 = 0;
    }

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&unk08), 4);
    bool last = false;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((reader))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&last), 1);
    unk0C = ((intptr_t)(::FUN_00994a80(last)));
}
