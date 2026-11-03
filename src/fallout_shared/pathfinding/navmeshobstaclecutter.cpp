
// src/fallout_shared/pathfinding/navmeshobstaclecutter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshobstaclecutter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_006bc330.h"
#include "fnv/symbols_00aa1000.h"
struct ObstacleUndoData
{
    virtual ~ObstacleUndoData();
    void* Destroy(unsigned int flags);
};

// Runs the destructor and, when flags has bit 0 set, frees this with _delete using size 0x70; returns this.
// @fnv 0x006bc300
void* ObstacleUndoData::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_006bc330 *>(this)->::FUN_006bc330::~FUN_006bc330();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x70);
    return this;
}
