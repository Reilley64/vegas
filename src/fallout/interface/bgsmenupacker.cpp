
// src/fallout/interface/bgsmenupacker.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/bgsmenupacker.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fallout/interface/tile_fields.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
struct FNVVector
{
    float x;
    float y;
    float z;
};
struct FNVAccessor
{
};
struct FNVNested;
struct FNVNestedProxy
{
    int FUN_00700300();
};
struct FNVNested
{
    int FUN_00700300();
};
struct FNVEntry
{
    float value00;
    float value04;
    float value08;
    float value0c;
    float value10;
    float value14;
    FNVNested* member18;
};
extern const char UNK_0106e8ac[];
extern const char UNK_0106e87c[];
extern const char UNK_0106e84c[];
extern const char UNK_0106e820[];
extern const char UNK_0106e800[];
int __cdecl FUN_00703c00(const char*, ...);
struct FNVCollection
{
    FNVEntry** FUN_00877a30(int);
    void FUN_00700350();
};
// @fnv 0x00700350
void FNVCollection::FUN_00700350()
{
    FUN_00703c00(UNK_0106e8ac);
    for (int index = 0; index < ((int)(reinterpret_cast<::FUN_00658930_class *>(this)->GetShortAtOffsetA())); ++index)
    {
        FNVEntry* entry = *FUN_00877a30(index);
        FUN_00703c00(UNK_0106e87c, entry->member18->FUN_00700300(), ((::FNVNestedProxy *)(reinterpret_cast<::FUN_0045cd60_shell *>((entry->member18))->FUN_0045cd60()))->FUN_00700300());
        FUN_00703c00(UNK_0106e84c, entry->value00, entry->value04, entry->value10, entry->value14);
        FUN_00703c00(UNK_0106e820, entry->value08, entry->value0c, ((::FNVVector *)&(reinterpret_cast<::NiAVObject *>((((::FNVAccessor *)(reinterpret_cast<::TileFields *>((entry->member18))->renderedNode))))->FUN_0043c490()))->x,
                     ((::FNVVector *)&(reinterpret_cast<::NiAVObject *>((((::FNVAccessor *)(reinterpret_cast<::TileFields *>((entry->member18))->renderedNode))))->FUN_0043c490()))->z);
    }
    FUN_00703c00(UNK_0106e800);
}

#include "generated/data/fallout/interface/bgsmenupacker.inc"
