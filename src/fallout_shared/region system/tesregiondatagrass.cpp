// fallout_shared/region system/tesregiondatagrass.cpp: TESRegionDataGrass, GrassRegion, RegionSaveShell, GrassMergeRegion (6 functions)

#include <new>
#include <cmath>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Controller.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f15c0_shell.h"
#include "fnv/decl/FUN_004f1730.h"
#include "fnv/decl/FUN_004f5e20.h"
#include "fnv/decl/FUN_004f5ec0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/RangeConsumer.h"
#include "fnv/decl/RegionSource.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "tesregiondatagrass_decls.h"
// Default constructor for TESRegionDataGrass; the body is empty.
// @fnv 0x004f1ed0
TESRegionDataGrass::TESRegionDataGrass()
{}

struct Dummy1690
{
    void* FUN_004f1690(unsigned int);
};
// Calls FUN_004f1730, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x004f1690
void* Dummy1690::FUN_004f1690(unsigned int flags)
{
    reinterpret_cast<::FUN_004f1730 *>(this)->FUN_004f1730::~FUN_004f1730();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}


struct FUN_004f16c0
{
    unsigned int data[3];

    FUN_004f16c0(const void* pSource);
};

struct FUN_004f1b60_shell : TESRegionDataGrass
{
    TESRegionData* FUN_004f1b60();
};

// @fnv 0x004f1b60
TESRegionData* FUN_004f1b60_shell::FUN_004f1b60()
{
    FUN_004f16c0* pdata = new FUN_004f16c0((const void*)this);

    return (TESRegionData*)pdata;
}

FUN_004f16c0::FUN_004f16c0(const void* pSource)
{}


struct GrassRecord
{
    unsigned int formID;
    unsigned int flags;
};
struct FUN_004f5620
{
    virtual void v0();
    virtual int Validate();
    virtual ~FUN_004f5620();
    unsigned int formID;
    unsigned int flags;
    FUN_004f5620(const GrassRecord&);
};
struct FileReader
{
};
struct GrassList
{
};
struct GrassRegion
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual GrassList* GetGrassList();
    bool LoadGrassRecords(FileReader*);
};
// @fnv 0x004f1980
bool GrassRegion::LoadGrassRecords(FileReader* file)
{
    GrassRecord* records = 0;
    FUN_004f5620* objectX = 0;
    if (!file || ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != 0x53474452)
        return false;
    unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
    unsigned int count_ = size / 8;
    if (size % 8)
    {
        ::FUN_005b5e40();
        return false;
    }
    if (count_)
    {
        records = new GrassRecord[count_];
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(records), size);
        for (unsigned int index = 0; index < count_; index++)
        {
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::S_00462230 *>(&(records[index]))->FUN_00462230();
            objectX = new FUN_004f5620(records[index]);
            if (objectX)
            {
                if (objectX->Validate())
                    reinterpret_cast<::FUN_004f5ec0_shell *>((GetGrassList()))->AddGrassObject((::TESRegionGrassObject *)(objectX));
                else
                    delete objectX;
            }
        }
        delete[] records;
    }
    return true;
}

struct SaveObj
{
    virtual void v00();
    virtual void* GetObj();
    virtual void v08();
    virtual void* GetObjC();
};
struct NamedForm
{
};
struct ObjNode
{
};
struct ListHead
{
    int unk00;
};
struct ObjList
{
    int unk00;
};
struct ObjListOwner : ListHead, ObjNode
{
};
struct SavePair
{
    unsigned int form;
    unsigned int extra;
};

struct RegionSaveShell
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual ObjListOwner* GetList();
    void WriteRegionSaveChunk();
};

// @fnv 0x004f17c0
void RegionSaveShell::WriteRegionSaveChunk()
{
    unsigned int count;
    SavePair* pPairs = 0;
    count = ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((GetList()))->FUN_0044edb0()));
    reinterpret_cast<::RegionSource *>(this)->WriteSaveData();
    if (count)
    {
        ObjNode* pNode = GetList();
        unsigned int uiIndex = 0;
        pPairs = new SavePair[count];
        while (pNode)
        {
            SaveObj* pObj = *((::SaveObj **)((void *)(pNode)));
            if (pObj)
            {
                pPairs[uiIndex].form = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((NamedForm*)pObj->GetObj())))->FUN_0084e3a0()));
                pPairs[uiIndex].extra = pObj->GetObjC() ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((NamedForm*)pObj->GetObjC())))->FUN_0084e3a0())) : 0;
                uiIndex++;
            }
            pNode = ((::ObjNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        }
        if (((bool)(::FUN_00401500())))
        {
            for (unsigned int uiSwapIndex = 0; uiSwapIndex < count; uiSwapIndex++)
                reinterpret_cast<::S_00462230 *>(&(pPairs[uiSwapIndex]))->FUN_00462230();
        }
        ::AppendChunk(0x53474452, pPairs, count * 8);
        if (((bool)(::FUN_00401500())))
        {
            for (unsigned int uiRestoreIndex = 0; uiRestoreIndex < count; uiRestoreIndex++)
                reinterpret_cast<::S_00462230 *>(&(pPairs[uiRestoreIndex]))->FUN_00462230();
        }
        delete[] pPairs;
    }
}

struct GrassMergeList
{
};
struct GrassMergeRegion : TESRegionData
{
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int GetType();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual GrassMergeList* GetGrassList();
    void MergeGrassRegion(GrassMergeRegion* data, void* context);
};
// Merges another grass region's data into this one when the source type is 6, choosing between override, priority and weighted blending of the grass lists.
// @fnv 0x004f1be0
void GrassMergeRegion::MergeGrassRegion(GrassMergeRegion* apPriority, void* context)
{
    GrassMergeRegion* priority = apPriority;
    float source;
    if (!apPriority || apPriority->GetType() != 6 || !context)
        return;
    if (m_bHasRegionData)
    {
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(reinterpret_cast<::PatrolActorPackageData *>((priority))->IsPatrolling());
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((priority))->FUN_005bb4d0())));
        reinterpret_cast<::FUN_004f5e20 *>((GetGrassList()))->ClearList();
        reinterpret_cast<::Controller *>((priority->GetGrassList()))->CopyTargetList((::TargetList *)(::GrassMergeList *)(GetGrassList()));
    }
    else if (priority->m_bHasRegionData)
    {
        return;
    }
    else if (bOverride)
    {
        if (reinterpret_cast<::PatrolActorPackageData *>((priority))->IsPatrolling() && ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((priority))->FUN_005bb4d0())) > ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())))
        {
            reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(reinterpret_cast<::PatrolActorPackageData *>((priority))->IsPatrolling());
            reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((priority))->FUN_005bb4d0())));
            reinterpret_cast<::FUN_004f5e20 *>((GetGrassList()))->ClearList();
            reinterpret_cast<::Controller *>((priority->GetGrassList()))->CopyTargetList((::TargetList *)(::GrassMergeList *)(GetGrassList()));
        }
    }
    else if (reinterpret_cast<::PatrolActorPackageData *>((priority))->IsPatrolling())
    {
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(reinterpret_cast<::PatrolActorPackageData *>((priority))->IsPatrolling());
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((priority))->FUN_005bb4d0())));
        reinterpret_cast<::FUN_004f5e20 *>((GetGrassList()))->ClearList();
        reinterpret_cast<::Controller *>((priority->GetGrassList()))->CopyTargetList((::TargetList *)(::GrassMergeList *)(GetGrassList()));
    }
    else
    {
        reinterpret_cast<::RangeConsumer *>((GetGrassList()))->FUN_004f61d0((float)((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())), (::RangeHolder *)(::GrassMergeList *)(priority->GetGrassList()), (float)((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((priority))->FUN_005bb4d0())));
        source = ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) + (100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((priority))->FUN_005bb4d0()));
        source +=
            (100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((priority))->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) + ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((priority))->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((priority))->FUN_005bb4d0()));
        source *= 0.005f;
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0((unsigned char)floor(source));
    }
}
