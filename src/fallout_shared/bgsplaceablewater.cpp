// fallout_shared/bgsplaceablewater.cpp: BGSPlaceableWater (21 functions)

#include <new>
#include <cstring>
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/FUN_00624700_shell.h"
#include "fnv/decl/FUN_00843170_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/HungerStageData.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_011ca000.h"
#include "bgsplaceablewater_decls.h"
#include "bgsplaceablewater_types_BGSPlaceableWater.h"
#include <malloc.h>

// @fnv 0x004fc1b0
BGSPlaceableWater::BGSPlaceableWater() : TESBoundObject(), TESModel()
{
    new ((void *)&(Data)) ::HungerStageData();
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(0x23))));
    ResetFormData();
}

// @fnv 0x004fc4b0
void BGSPlaceableWater::InitItem()
{
    if (GetInitialized())
        return;

    unsigned int formID = (unsigned int)(std::uintptr_t)(Data.m_pOwningWater);
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        Data.m_pOwningWater = dynamic_cast<TESWaterForm*>(::FUN_004839c0(formID));
    }

    if (!Data.m_pOwningWater)
        Data.m_pOwningWater = DAT_011ca53c;
    SetInitializationState(true);
}

struct FUN_004fc380_shell : public BGSPlaceableWater
{
    void FUN_004fc380(bool);
};

struct FUN_004fc990_t
{
    void FUN_004fc990(int, bool);
};

// @fnv 0x004fc380
void FUN_004fc380_shell::FUN_004fc380(bool abValue)
{
    reinterpret_cast<FUN_004fc990_t*>(this)->FUN_004fc990(4, abValue);
}

namespace fnv_004fc450 {
struct FUN_004fc450_shell : public BGSPlaceableWater
{
    void FUN_004fc450(bool);
};

struct FUN_004fc990_t
{
};

// @fnv 0x004fc450
void FUN_004fc450_shell::FUN_004fc450(bool abValue)
{
    reinterpret_cast<::FUN_004fc990_t *>((((FUN_004fc990_t*)this)))->FUN_004fc990(0x40000000, abValue);
}
}  // namespace fnv_004fc450

struct FUN_004fc790_shell
{
    unsigned short m0;
    unsigned int m4;
    FUN_004fc790_shell* Reset();
};

// Sets m0 and m4 to zero and returns this.
// @fnv 0x004fc790
FUN_004fc790_shell* FUN_004fc790_shell::Reset()
{
    m0 = 0;
    m4 = 0;
    return this;
}

struct FUN_004fc420_shell : public BGSPlaceableWater
{
    void FUN_004fc420(bool);
};

// @fnv 0x004fc420
void FUN_004fc420_shell::FUN_004fc420(bool abValue)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(0x80000000, abValue == 0);
}

struct FUN_005e78f0_t
{
};
struct FUN_004fc860_shell : public BGSPlaceableWater
{
    void FUN_004fc860(TESForm* apCopy);
};
// @fnv 0x004fc860
void FUN_004fc860_shell::FUN_004fc860(TESForm* apCopy)
{
    BGSPlaceableWater* pcopy;
    pcopy = dynamic_cast<BGSPlaceableWater*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pcopy);
    __memcpy(((::PlaceableWaterData *)(reinterpret_cast<::FUN_00624700_shell *>(this)->FUN_00624700())), ((::PlaceableWaterData *)(reinterpret_cast<::FUN_00624700_shell *>((pcopy))->FUN_00624700())), 8);
}

// Sets or clears aiFlag in the ulFlags of the object returned by FUN_00624700, depending on abSet.
// @fnv 0x004fc990
void FUN_004fc990_t::FUN_004fc990(int aiFlag, bool abSet)
{
    if (abSet)
        ((::PlaceableWaterData *)(reinterpret_cast<::FUN_00624700_shell *>((((BGSPlaceableWater*)this)))->FUN_00624700()))->ulFlags |= aiFlag;
    else
        ((::PlaceableWaterData *)(reinterpret_cast<::FUN_00624700_shell *>((((BGSPlaceableWater*)this)))->FUN_00624700()))->ulFlags &= ~aiFlag;
}

struct FUN_004fc360_shell : public BGSPlaceableWater
{
    void FUN_004fc360(bool);
};

// @fnv 0x004fc360
void FUN_004fc360_shell::FUN_004fc360(bool abValue)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(1, abValue);
}

struct FUN_004fc3a0_shell : public BGSPlaceableWater
{
    void FUN_004fc3a0(bool);
};

// @fnv 0x004fc3a0
void FUN_004fc3a0_shell::FUN_004fc3a0(bool abValue)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(8, abValue);
}

struct FUN_004fc3c0_shell : public BGSPlaceableWater
{
    void FUN_004fc3c0(bool);
};

// @fnv 0x004fc3c0
void FUN_004fc3c0_shell::FUN_004fc3c0(bool abValue)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(0x40, abValue);
}

struct FUN_004fc3e0_shell : public BGSPlaceableWater
{
    void FUN_004fc3e0(bool);
};

// @fnv 0x004fc3e0
void FUN_004fc3e0_shell::FUN_004fc3e0(bool abValue)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(0x200, abValue);
}

struct FUN_004fc400_shell : public BGSPlaceableWater
{
    void SetFlag800(bool);
};
// Loads a BGSPlaceableWater record from a TESFile: validates form type 0x23, clears data, reads EDID/OBND/MODL/MODT/DATA/DNAM chunks, and returns true on success.
// @fnv 0x004fc540
bool BGSPlaceableWater::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x23)
        return false;

    ClearData();
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);

    int chunkID;
    char* editorID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this ? static_cast<TESModel *>(this) : 0, file);
            break;
        case 0x41544144: {
            PlaceableWaterData data;
            reinterpret_cast<::FUN_004fc790_shell *>(&(data))->Reset();
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(file, &data, 8);
            if (reinterpret_cast<::TESFile *>((reinterpret_cast<TESFileGetChunkData*>(file)))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00535aa0_Class *>(&(data))->FUN_00535aa0();
            Data.m_pOwningWater = data.m_pOwningWater;
            Data.ulFlags = 0;
            reinterpret_cast<::FUN_004fc360_shell *>(this)->FUN_004fc360(true);
            reinterpret_cast<::FUN_004fc380_shell *>(this)->FUN_004fc380(true);
            reinterpret_cast<::FUN_004fc3a0_shell *>(this)->FUN_004fc3a0(true);
            reinterpret_cast<::FUN_004fc3c0_shell *>(this)->FUN_004fc3c0(true);
            reinterpret_cast<::FUN_004fc3e0_shell *>(this)->FUN_004fc3e0(true);
            reinterpret_cast<::FUN_004fc400_shell *>(this)->SetFlag800(true);
            FUN_004fc450(false);
            break;
        }
        case 0x4d414e44: {
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), 8);
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((reinterpret_cast<TESFileFormVersion*>(file)))->FUN_00403570() < 9)
                FUN_004fc450(false);
            if (reinterpret_cast<::TESFile *>((reinterpret_cast<TESFileGetChunkData*>(file)))->IsEndianConversionRequired())
                reinterpret_cast<::S_00462230 *>(&(Data))->FUN_00462230();
            break;
        }
        }

        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x004fc400
void FUN_004fc400_shell::SetFlag800(bool abValue)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(0x800, abValue);
}

struct FUN_004fc470_shell : public BGSPlaceableWater
{
    void FUN_004fc470(bool);
};

// @fnv 0x004fc470
void FUN_004fc470_shell::FUN_004fc470(bool abValue)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(0x20000000, abValue);
}

struct FUN_004fc490_shell : public BGSPlaceableWater
{
    void FUN_004fc490(bool);
};
// Reinitializes the object returned by FUN_00624700 and calls the FUN_004fc360..FUN_004fc490 helpers with true/false flags.
// @fnv 0x004fc2e0
void BGSPlaceableWater::ResetFormData()
{
    reinterpret_cast<::FUN_00843170_shell *>((((::PlaceableWaterData *)(reinterpret_cast<::FUN_00624700_shell *>(this)->FUN_00624700()))))->ClearFields();
    reinterpret_cast<::FUN_004fc360_shell *>(this)->FUN_004fc360(true);
    reinterpret_cast<::FUN_004fc380_shell *>(this)->FUN_004fc380(true);
    reinterpret_cast<::FUN_004fc3a0_shell *>(this)->FUN_004fc3a0(true);
    reinterpret_cast<::FUN_004fc3c0_shell *>(this)->FUN_004fc3c0(true);
    reinterpret_cast<::FUN_004fc3e0_shell *>(this)->FUN_004fc3e0(true);
    reinterpret_cast<::FUN_004fc400_shell *>(this)->SetFlag800(true);
    FUN_004fc450(false);
    reinterpret_cast<::FUN_004fc470_shell *>(this)->FUN_004fc470(false);
    reinterpret_cast<::FUN_004fc490_shell *>(this)->FUN_004fc490(true);
    reinterpret_cast<::FUN_004fc420_shell *>(this)->FUN_004fc420(true);
}

// @fnv 0x004fc490
void FUN_004fc490_shell::FUN_004fc490(bool abValue)
{
    ((FUN_004fc990_t*)this)->FUN_004fc990(0x10000000, abValue);
}

struct FUN_005e79a0_t
{
};
extern char DAT_01183028;
struct FUN_004fc8c0_shell : public BGSPlaceableWater
{
    bool FUN_004fc8c0(TESForm* apCompare);
};
// @fnv 0x004fc8c0
bool FUN_004fc8c0_shell::FUN_004fc8c0(TESForm* apCompare)
{
    BGSPlaceableWater* pcomp = dynamic_cast<BGSPlaceableWater*>(apCompare);
    if (!pcomp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pcomp))
        return true;
    if (memcmp((char*)&this->Data, ((::PlaceableWaterData *)(reinterpret_cast<::FUN_00624700_shell *>((pcomp))->FUN_00624700())), 8))
        return true;
    return false;
}

struct FUN_005802d0_shell : public FUN_004fc990_t
{
    void FUN_005802d0(bool flag);
};

// @fnv 0x005802d0
void FUN_005802d0_shell::FUN_005802d0(bool flag)
{
    FUN_004fc990(0x10, flag);
}

class ModelCallees
{
  public:
};

class WaterFormCallees
{
  public:
};

class FUN_004fc7b0_cls : public BGSPlaceableWater
{
  public:
    void FUN_004fc7b0();
};


// @fnv 0x004fc7b0
void FUN_004fc7b0_cls::FUN_004fc7b0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_004891d0_cls *>((((ModelCallees*)static_cast<TESModel *>(this))))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
    PlaceableWaterData waterFormData;
    new ((void *)&(waterFormData)) ::HungerStageData();
    ::__memcpy(&waterFormData, &Data, 8);
    waterFormData.m_pOwningWater =
        (TESWaterForm*)((Data.m_pOwningWater != 0) ? ((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((WaterFormCallees*)Data.m_pOwningWater)))->FUN_0084e3a0())) : 0);
    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::S_00462230 *>(&(waterFormData))->FUN_00462230();
    }
    ::AppendChunk(0x4d414e44, &waterFormData, 8);
    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::S_00462230 *>(&(waterFormData))->FUN_00462230();
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

// @fnv 0x004fc240
struct FUN_004fc240 : public BGSPlaceableWater
{
    virtual ~FUN_004fc240();
};
FUN_004fc240::~FUN_004fc240()
{}

// sub ecx,0x30; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x30).
struct PrimaryBase
{
    virtual void FUN_004fcbf0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct SecondaryBase
{
    virtual void FUN_004fcbf0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004fcbf0
    virtual void FUN_004fcbf0();
};

Derived::Derived()
{}
