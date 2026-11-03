// fallout_shared/mapmarkerdata.cpp: MapMarkerData, MapMarkerCompare, StringHolder (7 functions)

#include "fnv/decl/ChunkOffsetFile.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00487000.h"
#include "layout_support.h"
#include "TESFullName.h"
#include "TESFile.h"

class TESReputation;

// Chunk tags of the MAP marker data record, kept as numeric enum values so the
// comparisons compile to the original immediates.
enum
{
    kMapMarkerDataChunk = 0x4B524D58,        // 'XMRK'
    kMapMarkerTypeChunk = 0x4D414E46,        // 'FNAM'
    kMapMarkerNameChunk = 0x4C4C5546,        // 'FULL'
    kMapMarkerTravelChunk = 0x4D414E54,      // 'TNAM'
    kMapMarkerReputationChunk = 0x31494D57,  // 'WMI1'
};

// member functions matched in this unit added.
class MapMarkerData
{
  public:
    TESFullName LocationName;           // +0x0, 12 bytes
    unsigned char cFlags;               // +0xC, 1 bytes
    unsigned char m_ucAdditionalFlags;  // +0xD, 1 bytes
    unsigned short sType;               // +0xE, 2 bytes
    TESReputation* pReputationData;     // +0x10, 4 bytes

    bool Load(TESFile* file);
    bool GetVisible();
    void SetVisible(bool visible);
    bool IsTravelLocation();
    void SetTravelLocation(bool travelLoc);
};

// TESFile::GetChunkData(unsigned short*) and the offset-chunk accessors are not
// declared in the bundled TESFile.h; declared here on shims following the same
// precedent.
struct TESFileChunkData16 : public TESFile
{
};

struct TESFileOffsetChunk : public TESFile
{
};

// @fnv 0x00438ca0
bool MapMarkerData::Load(TESFile* file)
{
    if (!file)
        return false;
    if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) != kMapMarkerDataChunk)
        return false;
    if (!file->NextChunk())
        return false;
    if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == kMapMarkerTypeChunk)
    {
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&cFlags), 1);
        m_ucAdditionalFlags = cFlags;
        if (!file->NextChunk())
            return false;
    }
    if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == kMapMarkerNameChunk)
    {
        ::ReadFullName(&LocationName, file);
    }
    else
    {
        return false;
    }
    if (!file->NextChunk())
        return false;
    if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == kMapMarkerTravelChunk)
    {
        reinterpret_cast<::FUN_00472840_impl *>((((TESFileChunkData16*)file)))->ReadChunkData(&sType);
    }
    else
    {
        return false;
    }
    unsigned int chunkOffset = reinterpret_cast<::TESFile *>((((TESFileOffsetChunk*)file)))->GetOffsetChunk();
    if (!file->NextChunk())
        return false;
    if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == kMapMarkerReputationChunk)
    {
        unsigned int reputationID = 0;
        file->GetChunkData(&reputationID);
        if (reputationID)
            pReputationData = (TESReputation*)reputationID;
    }
    else
    {
        reinterpret_cast<::ChunkOffsetFile *>((((TESFileOffsetChunk*)file)))->FUN_004724f0(chunkOffset);
    }
    return true;
}

// @fnv 0x00438ed0
bool MapMarkerData::GetVisible()
{
    if (cFlags & 0x1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Sets or clears bit 0x1 in cFlags according to the visible argument.
// @fnv 0x0044de40
void MapMarkerData::SetVisible(bool visible)
{
    if (visible)
    {
        cFlags |= 0x1;
    }
    else
    {
        cFlags &= ~0x1;
    }
}

// @fnv 0x00438ef0
bool MapMarkerData::IsTravelLocation()
{
    if (cFlags & 0x2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Sets or clears bit 0x2 in cFlags according to travelLoc.
// @fnv 0x0044de80
void MapMarkerData::SetTravelLocation(bool travelLoc)
{
    if (travelLoc)
    {
        cFlags |= 0x2;
    }
    else
    {
        cFlags &= ~0x2;
    }
}

class MapMarkerCompare : public MapMarkerData
{
  public:
    bool FUN_00438e40(MapMarkerData* other);
};

// Returns true if any of LocationName, cFlags, sType, or pReputationData differs from the other MapMarkerData.
// @fnv 0x00438e40
bool MapMarkerCompare::FUN_00438e40(MapMarkerData* other)
{
    if (LocationName.CompareWithBase(reinterpret_cast<BaseFormComponent*>(other)))
        return true;
    if (cFlags != other->cFlags)
        return true;
    if (sType != other->sType)
        return true;
    if (pReputationData != other->pReputationData)
        return true;
    return false;
}

struct StringHolder
{
    const char* FUN_00438eb0();
};
// @fnv 0x00438eb0
const char* StringHolder::FUN_00438eb0()
{
    return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(this)->FUN_00408da0()));
}
