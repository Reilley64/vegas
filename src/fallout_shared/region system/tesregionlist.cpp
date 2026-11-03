
// src/fallout_shared/region system/tesregionlist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/region system/tesregionlist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_004f6640_cls.h"
#include "fnv/decl/FUN_004f70b0_Class.h"
#include "fnv/decl/RefList.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_011c7000.h"
struct TESRegion;
struct G2
{
    void AddHead(TESRegion* const&);
};
struct LH
{
};

struct TESRegionList
{
    bool AddRegion(TESRegion* apRegion);
};

// Returns false if apRegion is null; otherwise adds it to the list at offset 4 if not already present and returns true.
// @fnv 0x004f6600
bool TESRegionList::AddRegion(TESRegion* apRegion)
{
    if (!apRegion)
        return false;
    if (!(reinterpret_cast<::RefList *>((void *)(((LH*)((char*)this + 4))))->FUN_005f65d0((void **)&(apRegion))))
        ((G2*)((char*)this + 4))->AddHead(apRegion);
    return true;
}

void __cdecl operator delete(void*);
struct FUN_004f6480_shell
{
    void FUN_004f64b0();
    void* DestroyIfFlagged(unsigned int flags);
};
struct IntList
{
    void* first;
    void* last;
    ~IntList();
};
struct Cache
{
    virtual ~Cache();
};
struct CachePair
{
    Cache* first;
    Cache* second;
};
struct FUN_004f64b0
{
    virtual ~FUN_004f64b0();
    IntList regions;
    bool ownsCache;
};
// Calls FUN_004f64b0, then deletes this object if bit 0 of flags is set, and returns this.
// @fnv 0x004f6480
void* FUN_004f6480_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004f64b0 *>(this)->FUN_004f64b0::~FUN_004f64b0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Calls FUN_004f6640, then if ownsCache and the instance count drops to zero, deletes both caches in each of the 9 slots.
// @fnv 0x004f64b0
FUN_004f64b0::~FUN_004f64b0()
{
    reinterpret_cast<::FUN_004f6640_cls *>(this)->FUN_004f6640();
    if (ownsCache && --(*reinterpret_cast<unsigned int *>(&::g_poolInitCount_4f6320)) == 0)
    {
        Cache* second = 0;
        Cache* first = 0;
        for (unsigned int uiIndex = 0; uiIndex < 9; ++uiIndex)
        {
            first = caches[uiIndex].first;
            if (first)
            {
                caches[uiIndex].first = 0;
                delete first;
            }
            second = caches[uiIndex].second;
            if (second)
            {
                caches[uiIndex].second = 0;
                delete second;
            }
        }
    }
}

struct PointObject;
struct RegionNode
{
};
struct PointObject
{
    int unk00, unk04;
    float position;
    bool IsInRegion(RegionNode* region, float value);
};
// @fnv 0x004f7620
bool PointObject::IsInRegion(RegionNode* region, float value)
{
    if (region == 0)
        return false;
    if (FUN_0040eb10(value, position, ::AngularDashpotApplyD4DCB0::DAT_01017d00))
    {
        if (reinterpret_cast<::FUN_004f70b0_Class *>((region))->FUN_004f70b0((::RegionPoint *)(::PointObject *)(this)))
            return true;
    }
    return false;
}
