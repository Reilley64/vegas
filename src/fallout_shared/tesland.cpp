// fallout_shared/tesland.cpp: TESPackage (7 functions)

#include "fnv/decl/fnv_0041bb10__FUN_0041bb10_Class.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00538000.h"
#include "fnv/symbols_00540000.h"
#include "fnv/symbols_0102e000.h"
#include "tesland_decls.h"
#pragma optimize("", off)
// @fnv 0x005394a0
bool TESPackage::FUN_005394a0()
{
    if (flags & 8)
        return true;
    else
        return false;
}

extern int DAT_0102de10;

struct FUN_00533240_helper
{
    int* vtable;
    FUN_00533240_helper* InitVtable();
};

// @fnv 0x00533240
FUN_00533240_helper* FUN_00533240_helper::InitVtable()
{
    this->vtable = &DAT_0102de10;
    return this;
}

class PathingActorData
{
  public:
    PathingActorData();
};

// @fnv 0x00534550
void* __fastcall FUN_00534550(PathingActorData* pThis)
{
    ::FUN_00540720((::ExteriorData *)(pThis));
    return pThis;
}

template <typename T> struct BSStringT
{
    operator const char*() const;
};

struct TESFile;
template <typename T> struct BSSimpleList;

struct TESForm
{
};

// Reads a BSStringT at thisPtr+0xb8, treats it as a TESForm and returns that form's source file list.
// @fnv 0x00537b10
BSSimpleList<TESFile*>* __fastcall GetSourceFilesFromForm(char* thisPtr)
{
    return ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((int)(((TESForm*)(const char*)(*(BSStringT<char>*)(thisPtr + 0xb8)))))));
}

struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct BaseFormComponent;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectREFR;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};


// @fnv 0x00537b30
CellMopp* __fastcall GetCellMopp(char* pThis)
{
    return ((::CellMopp *)(reinterpret_cast<::fnv_0041bb10::FUN_0041bb10_Class *>((pThis + 0x28))->FUN_0041bb10()));
}


struct FUN_00538e30_class
{
    int vtable;
};

// @fnv 0x00538e30
void __fastcall SetVtable(FUN_00538e30_class* this_ptr)
{
    this_ptr->vtable = (int)&(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3(float fx, float fy, float afDepth);
};

struct Point3_0053d280
{
    float x, y, z;
    NiPoint3 FUN_0053d280(float denom) const;
};

// Returns a new NiPoint3 with each component divided by denom.
// @fnv 0x0053d280
NiPoint3 Point3_0053d280::FUN_0053d280(float denom) const
{
    float inv = 1.0f / denom;
    return NiPoint3(inv * this->x, inv * this->y, inv * this->z);
}
