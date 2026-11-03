
// src/fallout_shared/region system/tesregionobject.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/region system/tesregionobject.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_004536e0_Class.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/symbols_01015000.h"
class TESWorldSpace;
struct TESObjectCELL
{
public:
    bool IsCellInterior() const;
public:
    ::TESWorldSpace *GetParentWorldSpace();
};
struct MobileObjectCellAccess
{
};
struct Sky
{
};
struct DoorH
{
};
float DAT_01015f5c;
double _DAT_010231b0;

struct FUN_005471e0_shell
{
    float FUN_005471e0();
};

// @fnv 0x005471e0
float FUN_005471e0_shell::FUN_005471e0()
{
    if (!reinterpret_cast<::fnv_004518e0::TESObjectCELL *>((void *)(((MobileObjectCellAccess*)this)))->FUN_004518e0() || ((TESObjectCELL*)this)->IsCellInterior())
    {
        return DAT_01015f5c;
    }
    if (*(float*)((char*)this + 0x50) != 3.4028234663852886e+38f)
    {
        return *(float*)((char*)this + 0x50);
    }
    void* m_pContainingWorldspace = ((void *)(reinterpret_cast<::TESObjectCELL *>((((DoorH*)this)))->GetParentWorldSpace()));
    if (m_pContainingWorldspace)
    {
        return reinterpret_cast<::FUN_004536e0_Class *>((((Sky*)m_pContainingWorldspace)))->GetFieldCC();
    }
    return 0.0f;
}
