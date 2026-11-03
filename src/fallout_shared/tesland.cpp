// fallout_shared/tesland.cpp: TESPackage (7 functions)

#include "fnv/decl/fnv_0041bb10__FUN_0041bb10_Class.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00538000.h"
#include "fnv/symbols_00540000.h"
#include "fnv/symbols_0102e000.h"
#include "tesland_decls.h"
#include <windows.h>
#include "fnv/decl/A54440Hash.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_00bd8f90.h"
#include "fnv/decl/IndexBufferManager.h"
#include "fnv/decl/Owner_bd8670.h"
#include "fnv/decl/Owner_e8bff0.h"
#include "fnv/decl/PackingRenderer.h"
#include "fnv/decl/Renderer.h"
#include "fnv/decl/Renderer108.h"
#include "fnv/decl/S_00b601a0_Map.h"
#include "fnv/decl/Tbl00b57f20.h"
#include "fnv/decl/VertexRenderer.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00b61000.h"
#include "fnv/symbols_00e6f000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_0126f000.h"
#include "fnv/symbols_01272000.h"
#include "fnv/tls.h"
#include <xmmintrin.h>
#include <cstdint>
#include <cstddef>
#include <new>
#include <cstdlib>
#include <cstring>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/AlchemyItem.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BGSTerrainChunk.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSFaceGenNiNode.h"
#include "fnv/decl/BSShaderManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderPPLightingProperty.h"
#include "fnv/decl/Bound88.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439410_cls.h"
#include "fnv/decl/FUN_00439680_class.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_004410d0_Class.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_00456630_helper.h"
#include "fnv/decl/FUN_00456650_shell.h"
#include "fnv/decl/FUN_0045cb90_cls.h"
#include "fnv/decl/FUN_00485b60.h"
#include "fnv/decl/FUN_0049db00_Class.h"
#include "fnv/decl/FUN_0049ec60.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a8030_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0050a550_shell.h"
#include "fnv/decl/FUN_00510130_shell.h"
#include "fnv/decl/FUN_00528790_shell.h"
#include "fnv/decl/FUN_00537b50_shell.h"
#include "fnv/decl/FUN_00539f20_Class.h"
#include "fnv/decl/FUN_00540750_Class.h"
#include "fnv/decl/FUN_005407b0_Class.h"
#include "fnv/decl/FUN_00544210_shell.h"
#include "fnv/decl/FUN_00544590_cls.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00589850_Class.h"
#include "fnv/decl/FUN_00600ab0_shell.h"
#include "fnv/decl/FUN_00621e60.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_006f74f0_cls.h"
#include "fnv/decl/FUN_006fce30_shell.h"
#include "fnv/decl/FUN_006fce70_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009a1260_Class.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00a673d0_shell.h"
#include "fnv/decl/FUN_00a67660_cls.h"
#include "fnv/decl/FUN_00b600e0_cls.h"
#include "fnv/decl/FUN_00baa000_shell.h"
#include "fnv/decl/GeometryOwner.h"
#include "fnv/decl/GuardedSubHolder.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Holder00592cc0.h"
#include "fnv/decl/Interface.h"
#include "fnv/decl/LandOwner535d.h"
#include "fnv/decl/LandscapeSpecularView.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/Mgr_e74120.h"
#include "fnv/decl/NiGeometryData.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/NiUpdateData.h"
#include "fnv/decl/Owner_b9713.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/RenderOwner.h"
#include "fnv/decl/S.h"
#include "fnv/decl/S00546fb0_Cell.h"
#include "fnv/decl/S_00538f40.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/ShaderOwner.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TESWorldSpace.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TexSet_b68660.h"
#include "fnv/decl/This_004a8050.h"
#include "fnv/decl/_FUN_0052aa80_shell.h"
#include "fnv/decl/fnv_00484730__FUN_00484730_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e4f0__FUN_0048e4f0_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_00540570__FUN_00540570_Owner.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_00a66a60__GeometryDataA66A.h"
#include "fnv/decl/fnv_00a73080__S.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/decl/xMgr_2.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b1000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00533000.h"
#include "fnv/symbols_00534000.h"
#include "fnv/symbols_00535000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00539000.h"
#include "fnv/symbols_00549000.h"
#include "fnv/symbols_00554000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00a5b000.h"
#include "fnv/symbols_00a7e000.h"
#include "fnv/symbols_00b54000.h"
#include "fnv/symbols_00b5b000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101e000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_0102d000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01184000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_0118a000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c8000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
#include <string.h>
#include "fnv/decl/fnv_00534010__FUN_00534010.h"
#include "fnv/decl/fnv_00535b30__FUN_00535b30_class.h"
#include "fnv/decl/fnv_00538fb0__FUN_00538fb0.h"
#include "fnv/decl/fnv_0053a550__DoorH.h"
#include "fnv/decl/fnv_0053fa40__HostMesh53.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00471d60_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00c90510_class.h"
#include "fnv/decl/Land5371.h"
#include "fnv/decl/LandLD.h"
#include "fnv/decl/Region53.h"
#include "fnv/decl/S00485110.h"

// Layout of the TESObjectLAND fields the land accessors use: the land flags after TESForm and
// TESChildCell, the parent cell, and the loaded land data with its cell grid position.
struct LoadedLandDataView
{
    char pad[8];
    void* unk08;
    char padc[0x10 - 0xc];
    unsigned char** ppaucUnk10;
    char pad14[0x98 - 0x14];
    int iCellX;
    int iCellY;
};
struct LandFormView
{
    char formAndChildCell[0x1c];
    unsigned int uiLandFlags;
    void* pParentCell;
    void* unk24;
    LoadedLandDataView* pLoadedData;
};
// TESObjectLAND as its TESForm part and the TESChildCell base its thunks receive as this.
struct LandFormPart
{
    char form[0x18];
};
struct LandChildCellPart
{
    const void* pChildCellVtable;
};
struct LandChildCellView : LandFormPart, LandChildCellPart
{
};
// An object whose first component follows a TESBoundObject part.
struct BoundObjectPart
{
    char boundObject[0x30];
};
struct FirstComponentPart
{
    char unk;
};
#include "fnv/decl/TESFile.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00551000.h"
#include <cmath>
#include "fnv/decl/FUN_004734d0_shell.h"
#include "fnv/decl/FUN_00585ee0_shell.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/FUN_004867a0_cls.h"
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
void* FUN_00534550(PathingActorData* pThis)
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
    virtual ~TESForm();
};

// Reads a BSStringT at thisPtr+0xb8, treats it as a TESForm and returns that form's source file list.
// @fnv 0x00537b10
BSSimpleList<TESFile*>* GetSourceFilesFromForm(char* thisPtr)
{
    return ((::BSSimpleList< ::TESFile *> *)(::FUN_00460140((std::intptr_t)(((TESForm*)(const char*)(*(BSStringT<char>*)(thisPtr + 0xb8)))))));
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
CellMopp* GetCellMopp(char* pThis)
{
    return ((::CellMopp *)(std::uintptr_t)(reinterpret_cast<::fnv_0041bb10::FUN_0041bb10_Class *>((pThis + 0x28))->FUN_0041bb10()));
}


struct FUN_00538e30_class
{
    int vtable;
};

// @fnv 0x00538e30
void SetVtable(FUN_00538e30_class* this_ptr)
{
    this_ptr->vtable = (std::intptr_t)&(*reinterpret_cast<int *>(&::DAT_0102e388));
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

struct CacheLookup
{
};

struct CacheEntry
{
    int unk00;
    const char* name;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    CacheLookup lookup;
};

// @fnv 0x00b61940
bool FUN_00b61940(void* entry, const char* key)
{
    const char* groupName = static_cast<CacheEntry*>(entry)->name;
    entry = 0;
    if (!reinterpret_cast<::A54440Hash *>((((::CacheLookup *)(::fnv_00b61170::GetArrayHolder()))))->FUN_00a53c30((::A54440Manager *)(groupName), (::A54440Manager **)&(entry)))
        return false;
    return reinterpret_cast<::A54440Hash *>(&(static_cast<CacheEntry*>(entry)->lookup))->FUN_00a53c30((::A54440Manager *)(key), (::A54440Manager **)&(entry));
}

struct LandscapeSpecularView_iso
{
    unsigned int unk00, unk04, unk08, unk0c;
    unsigned int unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c;
    unsigned int unk40, unk44, unk48, unk4c;
    unsigned int unk50, unk54, unk58, unk5c;
    unsigned int unk60, unk64, unk68, unk6c;
    unsigned int unk70, unk74, unk78, unk7c;
    unsigned int unk80, unk84, unk88, unk8c;
    unsigned int unk90, unk94, unk98, unk9c;
    unsigned int unka0;
    void* textureSet;
    unsigned short textureCount;
    unsigned short unkaa;
    void* textureAc;
    void* textureB0;
    void* textureB4;
    void* textureB8;
    void* textureBc;
    void* textureC0;
    unsigned char* specularExponents;
    void FUN_00b66640(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e,
                      unsigned char f, unsigned char g, unsigned char h, unsigned char i, unsigned char j);
};

// @fnv 0x00b66640
void LandscapeSpecularView_iso::FUN_00b66640(unsigned char a, unsigned char b, unsigned char c, unsigned char d,
                                         unsigned char e, unsigned char f, unsigned char g, unsigned char h,
                                         unsigned char i, unsigned char j)
{
    if (textureCount == 9)
    {
        specularExponents[0] = a;
        specularExponents[1] = b;
        specularExponents[2] = c;
        specularExponents[3] = d;
        specularExponents[4] = e;
        specularExponents[5] = f;
        specularExponents[6] = g;
        specularExponents[7] = h;
        specularExponents[8] = i;
    }
}

struct UploadBatchHeader
{
    enum
    {
        KindMask = 0x7000,
        OwnedKind = 0x4000,
        RetainedFlags = 0xf000
    };
    int unk00;
    int unk04;
    int unk08;
    short unk0c;
    unsigned short flags;

    __forceinline void ClearOwnership()
    {
        flags &= RetainedFlags;
    }

    __forceinline bool OwnsHeader(unsigned int partIndex) const
    {
        return (short)(flags & KindMask) == (short)OwnedKind && partIndex == 0;
    }
};

struct UploadBatchPart
{
    int unk00;
    int unk04;
    void* buffer;
    unsigned int firstByte;
    int allocationFlags;
    unsigned int byteCount;
};

struct UploadBatchArray
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    bool unk14;
    char unk15;
    short unk16;
    int unk18;
    int unk1c;
    unsigned int m_iElementCount;
    int unk24;
    UploadBatchPart** m_data;
    int unk2c;
    int unk30;
    unsigned int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    unsigned short* unk4c;
    void* unk50;

    __forceinline UploadBatchPart* GetPart(unsigned int index) const
    {
        return index < m_iElementCount ? m_data[index] : 0;
    }
};

class UploadBatchDispatch
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();
    virtual void unk20();
    virtual void unk24();
    virtual void unk28();
    virtual void unk2c();
    virtual void unk30();
    virtual void unk34();
    virtual void unk38();
    virtual void unk3c();
    virtual void unk40();
    virtual void unk44();
    virtual void unk48();
    virtual void unk4c();
    virtual void unk50();
    virtual void unk54();
    virtual void unk58();
    virtual void unk5c();
    virtual void unk60();
    virtual void unk64();
    virtual void unk68();
    virtual void unk6c();
    virtual void unk70();
    virtual void unk74();
    virtual void unk78();
    virtual void unk7c();
    virtual void unk80();
    virtual void unk84();
    virtual void unk88();
    virtual void unk8c();
    virtual void unk90();
    virtual void unk94();
    virtual void unk98();
    virtual void unk9c();
    virtual void unka0();
    virtual void unka4();
    virtual void unka8();
    virtual int FUN_00e74288(void* p1, void* p2, void* p3, int p4, UploadBatchPart* p5, unsigned int p6,
                             unsigned int p7, int p8, int p9);
};

struct UploadBatchItem
{
    UploadBatchHeader* unk00;
    void* unk04;
    void* unk08;
    UploadBatchDispatch* unk0c;
    int unk10;
    int unk14;
    UploadBatchArray* unk18;
    unsigned int unk1c;
    UploadBatchItem* next;
};

struct Mgr_e74120_MapItem
{
    Mgr_e74120_MapItem* m_pkNext;
    void* m_key;
    UploadBatchItem* m_val;
};

class Mgr_e74120_Map
{
  public:
    virtual void dummy_vfunc0();
    virtual unsigned int KeyToHashIndex(void* key) const;

    unsigned int m_uiHashSize;
    Mgr_e74120_MapItem** m_ppkHashTable;
    unsigned int m_uiCount;


    __forceinline void* GetFirstPos() const
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            if (m_ppkHashTable[i])
                return m_ppkHashTable[i];
        }
        return 0;
    }

    __forceinline void GetNext(void*& pos, void*& key, UploadBatchItem*& val) const
    {
        Mgr_e74120_MapItem* pkItem = (Mgr_e74120_MapItem*)pos;
        key = pkItem->m_key;
        val = pkItem->m_val;
        if (pkItem->m_pkNext)
        {
            pos = pkItem->m_pkNext;
            return;
        }
        unsigned int i = KeyToHashIndex(key);
        for (++i; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                pos = pkItem;
                return;
            }
        }
        pos = 0;
    }
};

class S_00e8c0d0
{
  public:
public:
    bool CopyAndRelease(void *);
};

class Helper_00e8f200
{
  public:
};

class Mgr_e74120_iso
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    CRITICAL_SECTION cs80;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    CRITICAL_SECTION cs100;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int unk5b8;
    int unk5bc;
    int unk5c0;
    int unk5c4;
    int unk5c8;
    int unk5cc;
    int unk5d0;
    int unk5d4;
    int unk5d8;
    int unk5dc;
    int unk5e0;
    int unk5e4;
    int unk5e8;
    int unk5ec;
    int unk5f0;
    int unk5f4;
    int unk5f8;
    int unk5fc;
    int unk600;
    int unk604;
    int unk608;
    int unk60c;
    Mgr_e74120_Map map;
    int unk620;
    int unk624;
    int unk628;
    int unk62c;
    int unk630;
    int unk634;
    int unk638;
    int unk63c;
    int unk640;
    int unk644;
    int unk648;
    int unk64c;
    int unk650;
    int unk654;
    int unk658;
    int unk65c;
    int unk660;
    int unk664;
    int unk668;
    int unk66c;
    int unk670;
    int unk674;
    int unk678;
    int unk67c;
    int unk680;
    int unk684;
    int unk688;
    int unk68c;
    int unk690;
    int unk694;
    int unk698;
    int unk69c;
    int unk6a0;
    int unk6a4;
    int unk6a8;
    int unk6ac;
    int unk6b0;
    int unk6b4;
    int unk6b8;
    int unk6bc;
    int unk6c0;
    int unk6c4;
    int unk6c8;
    int unk6cc;
    int unk6d0;
    int unk6d4;
    int unk6d8;
    int unk6dc;
    int unk6e0;
    int unk6e4;
    int unk6e8;
    int unk6ec;
    int unk6f0;
    int unk6f4;
    int unk6f8;
    int unk6fc;
    int unk700;
    int unk704;
    int unk708;
    int unk70c;
    int unk710;
    int unk714;
    int unk718;
    int unk71c;
    int unk720;
    int unk724;
    int unk728;
    int unk72c;
    int unk730;
    int unk734;
    int unk738;
    int unk73c;
    int unk740;
    int unk744;
    int unk748;
    int unk74c;
    int unk750;
    int unk754;
    int unk758;
    int unk75c;
    int unk760;
    int unk764;
    int unk768;
    int unk76c;
    int unk770;
    int unk774;
    int unk778;
    int unk77c;
    int unk780;
    int unk784;
    int unk788;
    int unk78c;
    int unk790;
    int unk794;
    int unk798;
    int unk79c;
    int unk7a0;
    int unk7a4;
    int unk7a8;
    int unk7ac;
    int unk7b0;
    int unk7b4;
    int unk7b8;
    int unk7bc;
    int unk7c0;
    int unk7c4;
    int unk7c8;
    int unk7cc;
    int unk7d0;
    int unk7d4;
    int unk7d8;
    int unk7dc;
    int unk7e0;
    int unk7e4;
    int unk7e8;
    int unk7ec;
    int unk7f0;
    int unk7f4;
    int unk7f8;
    int unk7fc;
    int unk800;
    int unk804;
    int unk808;
    int unk80c;
    int unk810;
    int unk814;
    int unk818;
    int unk81c;
    int unk820;
    int unk824;
    int unk828;
    int unk82c;
    int unk830;
    int unk834;
    int unk838;
    int unk83c;
    int unk840;
    int unk844;
    int unk848;
    int unk84c;
    int unk850;
    int unk854;
    int unk858;
    int unk85c;
    int unk860;
    int unk864;
    int unk868;
    int unk86c;
    int unk870;
    int unk874;
    int unk878;
    int unk87c;
    int unk880;
    int unk884;
    int unk888;
    int unk88c;
    int unk890;
    int unk894;
    int unk898;
    int unk89c;
    int unk8a0;
    int unk8a4;
    int unk8a8;
    int unk8ac;
    int unk8b0;
    int unk8b4;
    int unk8b8;
    S_00e8c0d0* helper8bc;
    Helper_00e8f200* helper8c0;


    void FUN_00e74120();
};

// @fnv 0x00e74120
void Mgr_e74120_iso::FUN_00e74120()
{
    EnterCriticalSection(&cs80);
    EnterCriticalSection(&cs100);

    void* pos = map.GetFirstPos();
    UploadBatchItem* delList = 0;
    while (pos)
    {
        void* key;
        UploadBatchItem* val;
        map.GetNext(pos, key, val);
        if (!val)
            continue;
        if (key)
        {
            unsigned int lo = 0xffffffff;
            unsigned int hi = 0;
            UploadBatchPart* sub;
            UploadBatchItem* cur = val;
            do
            {
                unsigned int index = cur->unk1c;
                UploadBatchItem* nx = cur->next;
                UploadBatchArray* arr = cur->unk18;
                sub = arr->GetPart(index);
                if (sub->firstByte < lo)
                    lo = sub->firstByte;
                if (sub->firstByte + sub->byteCount > hi)
                    hi = sub->firstByte + sub->byteCount;
                cur = nx;
            } while (cur);

            if (hi > lo)
            {
                unsigned int fl = sub->allocationFlags;
                void* vb = sub->buffer;
                std::uintptr_t base = ((std::uintptr_t)(reinterpret_cast<::Owner_e8bff0 *>((helper8bc))->FUN_00e8bff0((::Holder_e8bff0 *)(vb), lo, hi - lo, fl)));
                UploadBatchItem* it = val;
                do
                {
                    UploadBatchArray* arr = it->unk18;
                    unsigned int index = it->unk1c;
                    UploadBatchItem* nx = it->next;
                    sub = arr->GetPart(index);
                    std::uintptr_t offset = sub->firstByte + base;
                    if (!it->unk0c ||
                        !it->unk0c->FUN_00e74288(it->unk00, it->unk04, it->unk08, 0xfff, sub, index, offset, 0, 0))
                    {
                        if (it->unk08)
                            reinterpret_cast<::VertexRenderer *>((helper8bc))->FUN_00e8c820((::VertexSource *)(it->unk00), (std::uintptr_t)(it->unk04), (::VertexData *)(it->unk08), 0xfff, (::VertexBufferLockInfo *)(sub), (char *)(offset));
                        else
                            reinterpret_cast<::Renderer *>((helper8bc))->FUN_00e8c1e0((::NiGeometryData *)(it->unk00), (::Class87d40 *)(it->unk04), 0xfff, (::VertexRecord *)(sub), (char *)(offset));
                    }
                    if (it->unk1c == 0)
                    {
                        void* data = arr->unk50;
                        if (data)
                        {
                            unsigned short* lens = arr->unk4c;
                            int a = 0;
                            int b = 0;
                            if (lens)
                            {
                                int n = arr->unk48;
                                while (n)
                                {
                                    n--;
                                    a += lens[n];
                                }
                                b = a;
                            }
                            else if (arr->unk3c == 4)
                            {
                                a = arr->unk40 * 3;
                                b = arr->unk44 * 3;
                            }
                            else if (arr->unk3c == 5)
                            {
                                a = arr->unk40 + 2;
                                b = arr->unk44 + 2;
                            }
                            int tmp = arr->unk30;
                            bool fl2 = arr->unk14;
                            std::uintptr_t prev = arr->unk34;
                            arr->unk34 =
                                ((std::uintptr_t)(reinterpret_cast<::IndexBufferManager *>((helper8c0))->PackBuffer((const unsigned short *)(data), a, b, (::COMBaseInterface *)(prev), (*(unsigned int *)(&tmp)), DAT_0126f0d0 == 0, fl2 ? 0x10 : 0)));
                            arr->unk2c = a;
                            arr->unk30 = tmp;
                        }
                    }
                    it->next = delList;
                    delList = it;
                    it = nx;
                } while (it);
                helper8bc->CopyAndRelease(sub->buffer);
            }
        }
        else
        {
            UploadBatchItem* cur = val;
            do
            {
                UploadBatchItem* nx = cur->next;
                if (cur->unk1c == 0)
                {
                    if (cur->unk08)
                        reinterpret_cast<::PackingRenderer *>(this)->UpdatePackingPacket((::PackingPacket *)(cur->unk18), (::Model_e6da60 *)(cur->unk00), cur->unk04, (::PackingData *)(cur->unk08), (::PackingGeometry *)(cur->unk0c), 1);
                    else
                        reinterpret_cast<::Renderer108 *>(this)->PrepareGeometryPacket((::Packet108 *)(cur->unk18), (::NiAVObject *)(cur->unk00), (::Geo108 *)(cur->unk04), (::NiAVObject *)(cur->unk0c), 1);
                }
                cur->next = delList;
                delList = cur;
                cur = nx;
            } while (cur);
        }
    }

    reinterpret_cast<::S_00b601a0_Map *>(&(map))->FUN_00b601a0();

    while (delList)
    {
        UploadBatchItem* nx = delList->next;
        UploadBatchHeader* h = delList->unk00;
        if (h->OwnsHeader(delList->unk1c))
        {
            UploadBatchHeader* h2 = delList->unk00;
            h2->ClearOwnership();
            ::ApplyPacketUpdate((::PacketObj *)this, (::PacketTarget *)(h), (std::intptr_t)(delList->unk04));
        }
        FUN_00aa1460(delList, sizeof(UploadBatchItem));
        delList = nx;
    }

    LeaveCriticalSection(&cs100);
    LeaveCriticalSection(&cs80);
}

namespace fnv_00b61370 {
struct CacheAllocationScope
{
    int savedTag;
    CacheAllocationScope(int tag) : savedTag(g_tlsBlock.memoryContext)
    {
        g_tlsBlock.memoryContext = tag;
    }
    ~CacheAllocationScope()
    {
        g_tlsBlock.memoryContext = savedTag;
    }
};
struct CacheItem
{
};
struct CacheListNode
{
    CacheListNode* next;
    CacheListNode* previous;
    CacheItem* item;
};
struct CacheLock
{
    int state;
    unsigned int live;
};
struct CacheMemory
{
};
struct CacheList
{
    CacheListNode* head;
    CacheListNode* tail;
    unsigned int count;
    CacheItem* FUN_00b602d0();
    CacheItem* FUN_00e7d5b0();
    CacheItem*& GetNext(CacheListNode*& position)
    {
        CacheItem*& ref = position->item;
        position = position->next;
        return ref;
    }
    __forceinline CacheItem* Remove(CacheListNode* node, CacheItem*& slot)
    {
        if (node == head)
        {
            return FUN_00b602d0();
        }
        else if (node == tail)
        {
            return FUN_00e7d5b0();
        }
        else
        {
            CacheItem* item = slot;
            CacheListNode* previous = node->previous;
            CacheListNode* next = node->next;
            if (previous)
                previous->next = next;
            if (next)
                next->previous = previous;
            slot = 0;
            reinterpret_cast<::FUN_0040fbf0_shell *>(&((*reinterpret_cast<::fnv_00b61370::CacheLock *>(&::g_011c5f80))))->FUN_0040fbf0((char *)(0));
            node->previous = 0;
            node->next = (*reinterpret_cast<::fnv_00b61370::CacheListNode * *>(&::DAT_011c5f58));
            (*reinterpret_cast<::fnv_00b61370::CacheLock *>(&::g_011c5f80)).live--;
            (*reinterpret_cast<::fnv_00b61370::CacheListNode * *>(&::DAT_011c5f58)) = node;
            if (!(*reinterpret_cast<::fnv_00b61370::CacheLock *>(&::g_011c5f80)).live)
                (*reinterpret_cast<::fnv_00b61370::CacheLock *>(&::g_011c5f80)).state = 0;
            count--;
            return item;
        }
    }
};
struct CacheLookup
{
    bool FUN_00e91fd0(const char*);
};
struct CacheBucket
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    CacheList entries;
    int unk2c;
    CacheLookup lookup;
};
struct CacheMapNode
{
    CacheMapNode* next;
    unsigned key;
    CacheBucket* value;
};
struct CacheMap
{
    virtual ~CacheMap();
    virtual unsigned Hash(unsigned key);
    unsigned int size;
    CacheMapNode** buckets;
    unsigned int count;
    void* First()
    {
        for (unsigned int index = 0; index < size; index++)
        {
            if (buckets[index])
                return buckets[index];
        }
        return 0;
    }
    void FUN_00b57f20(void*&, unsigned int&, CacheBucket*&);
};
// @fnv 0x00b61370
void FUN_00b61370(const char* key)
{
    CacheAllocationScope scope(0x1c);
    void* position = ((::fnv_00b61370::CacheMap *)(::fnv_00b61170::GetArrayHolder()))->First();
    CacheBucket* removed = 0;
    if (((::fnv_00b61370::CacheMap *)(::fnv_00b61170::GetArrayHolder()))->count > 0 && position)
    {
        do
        {
            struct
            {
                unsigned int key;
                void* value;
            } kv;
            reinterpret_cast<::Tbl00b57f20 *>((((::fnv_00b61370::CacheMap *)(::fnv_00b61170::GetArrayHolder()))))->AdvanceToNextEntry((::Ent00b57f20 **)&(position), (int *)&(kv.key), (int *)&(removed));
            CacheLookup* lookup = removed ? &removed->lookup : 0;
            if (removed && reinterpret_cast<::A54440Hash *>((lookup))->FUN_00a53c30((::A54440Manager *)(key), (::A54440Manager **)&(kv.value)))
            {
                CacheList* entries;
                entries = &removed->entries;
                CacheListNode* node = entries->head;
                while (node)
                {
                    CacheListNode* bucket = node;
                    CacheItem*& slot = entries->GetNext(node);
                    CacheItem* item = slot;
                    if (item && !reinterpret_cast<::Owner_bd8670 *>((item))->FUN_00bd8670((std::uintptr_t)(key)))
                    {
                        entries->Remove(bucket, slot);
                        reinterpret_cast<::FUN_00bd8f90 *>((item))->FUN_00bd8f90::~FUN_00bd8f90();
                        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00b61370::CacheMemory *>(&::g_memoryManager))))->FUN_00aa4060(item);
                        ::DAT_011f9ef4--;
                    }
                }
                lookup->FUN_00e91fd0(key);
            }
        } while (position);
    }
}

void CacheMap::FUN_00b57f20(void*& position, unsigned& key, CacheBucket*& value)
{
    CacheMapNode* node = (CacheMapNode*)position;
    key = node->key;
    value = node->value;
    if (node->next)
    {
        position = node->next;
        return;
    }
    unsigned index = Hash(node->key) + 1;
    for (; index < size; ++index)
    {
        if (buckets[index])
        {
            position = buckets[index];
            return;
        }
    }
    position = 0;
}
}

struct S_00538f40_od_oy_noo2
{
    __m128 m;
    void FUN_00538f40();
};

// @fnv 0x00538f40
void S_00538f40_od_oy_noo2::FUN_00538f40()
{
    m = _mm_setzero_ps();
}

#pragma optimize("",off)

struct FUN_00533260_holder {
    void FUN_00533260();
};

struct FUN_00533210_class {
    void* FUN_00533210(unsigned int flags);
};

struct CellH {
};

struct FUN_00533fd0_Class : LandFormView {
    int FUN_00533fd0();
};

// @fnv 0x00533fd0
int FUN_00533fd0_Class::FUN_00533fd0()
{
    if (pLoadedData)
        return pLoadedData->iCellX;
    if (pParentCell)
        return reinterpret_cast<::TESObjectCELL *>(pParentCell)->GetCellGridX();
    return 0;
}

namespace fnv_00534010 {
struct CellH {  };
struct FUN_00534010_od : ::LandFormView {
    int GetY();
};
// @fnv 0x00534010
int FUN_00534010_od::GetY()
{
    if (pLoadedData)
        return pLoadedData->iCellY;
    if (pParentCell)
        return reinterpret_cast<::TESObjectCELL *>(pParentCell)->GetCellGridY();
    return 0;
}
}

// namespace fnv_00534010

struct FUN_00534050_Class {
    float FUN_00534050();
};

// @fnv 0x00534050
float FUN_00534050_Class::FUN_00534050()
{
    int result = reinterpret_cast<::FUN_00533fd0_Class *>(this)->FUN_00533fd0();
    return static_cast<float>(result << 12);
}

struct FUN_00534080_Class {
    int FUN_00534010_od();
    double FUN_00534080();
};

// @fnv 0x00534080
double FUN_00534080_Class::FUN_00534080()
{
    int result = reinterpret_cast<::fnv_00534010::FUN_00534010_od *>(this)->GetY();
    return static_cast<double>(result << 0xc);
}

struct DoorH_od {  };

struct FUN_005340b0_Class {
    int m_auiShapeKeys[8];
    DoorH_od* m_pDoor;
    TESWorldSpace* FUN_005340b0();
};

// @fnv 0x005340b0
TESWorldSpace* FUN_005340b0_Class::FUN_005340b0()
{
    if (m_pDoor)
    {
        return reinterpret_cast<::TESObjectCELL *>((m_pDoor))->GetParentWorldSpace();
    }
    return 0;
}

namespace fnv_005340e0 {
struct DoorH_od {  };
struct TESObjectCELL {};
struct TESWorldSpace {
	enum PARENT_USE_FLAG { PARENT_USE_FLAG_0 = 0 };
	TESWorldSpace* GetParentWorld(PARENT_USE_FLAG);
};
struct TESObjectLAND : ::LandFormView {
	void FUN_00534160(int);
	void FUN_005340e0(TESObjectCELL* apCell);
};
// @fnv 0x005340e0
void TESObjectLAND::FUN_005340e0(TESObjectCELL* apCell)
{
	TESWorldSpace* pworld;
	pParentCell = apCell;
	if (pParentCell != 0) {
		pworld = (TESWorldSpace*)((void *)(reinterpret_cast<::TESObjectCELL *>(pParentCell)->GetParentWorldSpace()));
		if (pworld != 0 && pworld->GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)0) != 0)
			FUN_00534160(1);
		else
			FUN_00534160(0);
	}
}
}

// namespace fnv_005340e0

struct FUN_00534140_Class : LandFormView {
    bool FUN_00534140();
};

// @fnv 0x00534140
bool FUN_00534140_Class::FUN_00534140()
{
    if (uiLandFlags & 0x400)
        return true;
    return false;
}

struct FUN_00534160_Class : LandFormView {
    void FUN_00534160(bool set);
};

// @fnv 0x00534160
void FUN_00534160_Class::FUN_00534160(bool set)
{
    if (set)
        uiLandFlags |= 0x400;
    else
        uiLandFlags &= ~0x400;
}

struct FUN_005341a0_Class : LandFormView {
    void FUN_005341a0(bool set);
};

// @fnv 0x005341a0
void FUN_005341a0_Class::FUN_005341a0(bool set)
{
    if (set)
        uiLandFlags |= 0x800;
    else
        uiLandFlags &= ~0x800;
}

struct FUN_005341e0_Class : LandFormView {
    bool FUN_005341e0();
};

// @fnv 0x005341e0
bool FUN_005341e0_Class::FUN_005341e0()
{
    if (uiLandFlags & 0x10)
        return true;
    return false;
}

struct FUN_00534200_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_00534200(bool value);
};

// @fnv 0x00534200
void FUN_00534200_Class::FUN_00534200(bool value)
{
    if (value)
        m_1c |= 0x10;
    else
        m_1c &= ~0x10;
}

struct NiPoint3_od { float x; float y; float z; public:
    static const ::NiPoint3_od ZERO;
};

class TESFile;

struct TESForm_od {  public:
    void ClearData();
public:
    ::TESFile *GetFile(int);
};

struct FUN_00534570_shell { char* m_pkDeltas; unsigned int stride; void FUN_00534570(unsigned int index, NiPoint3_od& vertex); };

// @fnv 0x00534570
void FUN_00534570_shell::FUN_00534570(unsigned int index, NiPoint3_od& vertex)
{
    reinterpret_cast<::FUN_004534f0_shell *>((((TESForm_od*)this)))->FUN_004534f0(index);
    char* pVertex = m_pkDeltas + index * stride;
    NiPoint3_od& result = *(NiPoint3_od*)pVertex;
    vertex = result;
}

template<int> struct EndianSizeTag {};

struct FUN_00535a60_Class {
    char pad[6];
    unsigned short usUnk06;
    void FUN_00535a60();
};

// @fnv 0x00535a60
void FUN_00535a60_Class::FUN_00535a60()
{
    ::FUN_00401080(reinterpret_cast<int*>(this));
    ::FUN_00407a90((short *)(unsigned short *)(&usUnk06));
}

// @fnv 0x00535ae0
std::intptr_t FUN_00535ae0()
{
    return DAT_011c9f04;
}

namespace fnv_00535b30 {
struct NiPoint3_od { float x, y, z; NiPoint3_od(); };
struct FUN_00535b30_class_od {
    NiPoint3_od FUN_00535b30(int block);
};
// @fnv 0x00535b30
NiPoint3_od FUN_00535b30_class_od::FUN_00535b30(int block)
{
    NiPoint3_od result;
    result.x = reinterpret_cast<::FUN_00534050_Class *>(this)->FUN_00534050() + ::DAT_01016968;
    result.y = ((float)(reinterpret_cast<::FUN_00534080_Class *>(this)->FUN_00534080())) + ::DAT_01016968;
    result.z = reinterpret_cast<::FUN_0049db00_Class *>(this)->FUN_0049db00();
    return result;
}
}

// namespace fnv_00535b30


struct FUN_00537100_Class {
    void FUN_00537130();
    void* FUN_00537100(unsigned int flags);
};

struct FUN_00537ca0_class
{
    const char* const* FUN_00537ca0();
};

// @fnv 0x00537ca0
const char* const* FUN_00537ca0_class::FUN_00537ca0()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f4a30));
}

struct FUN_00a73080_holder {  };

class ShadowSceneNode;

struct NiAdditionalGeometryData {
    void* FUN_00537cb0(unsigned int flags);
public:
    static ::ShadowSceneNode *GetShadowSceneNodeForIndex(int);
};

// @fnv 0x00537cb0
void* NiAdditionalGeometryData::FUN_00537cb0(unsigned int flags)
{
    reinterpret_cast<::fnv_00a73080::S *>((reinterpret_cast<FUN_00a73080_holder*>(this)))->FUN_00a73080();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x2c);
    return this;
}

struct FUN_00540800_Class {
    void FUN_00540800();
    void FUN_00537ce0();
};

// @fnv 0x00537ce0
void FUN_00540800_Class::FUN_00537ce0()
{
    FUN_00540800();
}

struct FUN_00537d00_Class {
    void* FUN_00537d00();
};

// @fnv 0x00537d00
void* FUN_00537d00_Class::FUN_00537d00()
{
    return &(*reinterpret_cast<void * *>(&::g_011f4aac));
}

struct FUN_00537d10_Class {
    void FUN_00537d40();
    void* FUN_00537d10(unsigned int flags);
};

struct QuantityData {  };

struct TESRaceForm {  };

struct TESObjectREFR {  };

struct MagicCaster {  };

struct TESConditionItem {  };

struct TESQuest;

struct BGSQuestObjective { void SetOwner(TESQuest*); };

struct FUN_00537e30_cls { char _pad[24]; int _m18; int _m1c; FUN_00537e30_cls* FUN_00537e30(); };

struct FUN_00537e90 {
    uintptr_t quantity;
    void SetQuantity(uintptr_t value);
};

// @fnv 0x00537e30
FUN_00537e30_cls* FUN_00537e30_cls::FUN_00537e30()
{
    reinterpret_cast<::FUN_00537e90 *>((((QuantityData*)this)))->SetQuantity(0);
    reinterpret_cast<::CombatProcedure *>((((TESRaceForm*)this)))->Initialize((::CombatController *)(0));
    reinterpret_cast<::TESRegionGrassObject *>((((TESObjectREFR*)this)))->AssignLandTexture((::TESLandTexture *)(0));
    reinterpret_cast<::FUN_0041fd00_shell *>((((MagicCaster*)this)))->FUN_0041fd00(0);
    reinterpret_cast<::FUN_00600ab0_shell *>((((TESConditionItem*)this)))->FUN_00600ab0(0);
    ((BGSQuestObjective*)this)->SetOwner(0);
    _m18 = 0;
    _m1c = 0;
    return this;
}

// @fnv 0x00537e90
void FUN_00537e90::SetQuantity(uintptr_t value)
{
    quantity = value;
}

struct FUN_00538e30_class_od {
};

extern int DAT_0102e378;

struct FUN_00538e10_class {
    int* m_vtbl;
    void FUN_00538e10();
};

// @fnv 0x00538e10
void FUN_00538e10_class::FUN_00538e10()
{
    m_vtbl = &DAT_0102e378;
    ::SetVtable((::FUN_00538e30_class *)this);
}

namespace fnv_00538e50 {
struct FUN_00538e30_class_od {
    void* FUN_00538e50(unsigned int flags);
};
// @fnv 0x00538e50
void* FUN_00538e30_class_od::FUN_00538e50(unsigned int flags)
{
    ::SetVtable((::FUN_00538e30_class *)this);
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

// namespace fnv_00538e50

struct B1 { virtual ~B1(); void* FUN_00538e80(unsigned int); };

// @fnv 0x00538e80
void* B1::FUN_00538e80(unsigned int flags)
{
    reinterpret_cast<::FUN_00538e10_class *>((this))->FUN_00538e10();
    if (flags & 1)
        ::FUN_00538eb0((::Prm *)(void *)(this));
    return this;
}

extern int DAT_0102e378;

struct FUN_00538ef0_class {
    void* m_ppVirtualMethodTable;
    unsigned short usUnk04;
    unsigned short usUnk06;
    int m_kPointB;
    void FUN_00538f20();
    void* FUN_00538ef0();
};

struct FUN_00538f20 {
    int* p;
    FUN_00538f20();
};

// @fnv 0x00538ef0
void* FUN_00538ef0_class::FUN_00538ef0()
{
    new ((void *)this) ::FUN_00538f20();
    m_ppVirtualMethodTable = &DAT_0102e378;
    usUnk06 = 1;
    return this;
}

// @fnv 0x00538f20
FUN_00538f20::FUN_00538f20()
{
    p = &(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct FUN_00538f80 {
    void FUN_00538fb0_od();
    void* DeleteThis(unsigned int flags);
};

// @fnv 0x00538f80
void* FUN_00538f80::DeleteThis(unsigned int flags)
{
    FUN_00538fb0_od();
    if (flags & 1)
        ::FUN_00538eb0((::Prm *)(void *)(this));
    return this;
}

namespace fnv_00538fb0 {
struct B1 { virtual ~B1(); };
struct FUN_005408e0 { ~FUN_005408e0(); };
struct FUN_00538fb0_od : B1 { char _pad[28]; FUN_005408e0 m; ~FUN_00538fb0_od(); };
// @fnv 0x00538fb0
FUN_00538fb0_od::~FUN_00538fb0_od() {}
}

// namespace fnv_00538fb0

struct FUN_00539460_Class {
    char m_00[0x1c];
    int m_1c;
    bool FUN_00539460();
};

// @fnv 0x00539460
bool FUN_00539460_Class::FUN_00539460()
{
    if (m_1c & 1)
        return true;
    if (m_1c & 4)
        return true;
    if (m_1c & 2)
        return true;
    return false;
}

struct FUN_005394c0_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void FUN_005394c0(bool value);
};

// @fnv 0x005394c0
void FUN_005394c0_Class::FUN_005394c0(bool value)
{
    if (value)
        m_1c |= 8;
    else
        m_1c &= ~8;
}

struct GlobalObjectO2_00a7b610;

struct FUN_00539fc0_Class
{
    GlobalObjectO2_00a7b610* FUN_00539fc0();
};

// @fnv 0x00539fc0
GlobalObjectO2_00a7b610* FUN_00539fc0_Class::FUN_00539fc0()
{
    return &::g_011f4ab8;
}

struct FUN_0053a000 {
};

struct FUN_00539fd0 : public FUN_0053a000 {
    void* ScalarDeletingDestructor(unsigned int flags);
};

struct FUN_0053a070_Class {
    char pad[0xc];
    int iUnk0c;
    int iUnk10;
    void FUN_0053a070(int a, int b);
};

// @fnv 0x0053a070
void FUN_0053a070_Class::FUN_0053a070(int a, int b)
{
    iUnk10 = a;
    iUnk0c = b;
}

struct B006815c0 { B006815c0(); };

struct FUN_0053a510 {
    B006815c0 m0;
    char _p1[7];
    B006815c0 m1;
    char _p2[19];
    B006815c0 m2;
    char _p3[19];
    B006815c0 m3;
    FUN_0053a510();
};

// @fnv 0x0053a510
FUN_0053a510::FUN_0053a510()
{
}

namespace fnv_0053a550 {
struct TESWorldSpace;
struct TESObjectCELL;
struct TESWorldSpace {
};
struct DoorH_od {
    float FUN_0053a550();
};
// @fnv 0x0053a550
float DoorH_od::FUN_0053a550()
{
    float fretval = ::DAT_0102dcc4;
    TESObjectCELL* pcell = (TESObjectCELL*)((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()));
    if (pcell) {
        TESWorldSpace* pworld = (TESWorldSpace*)((void *)(reinterpret_cast<::TESObjectCELL *>((((DoorH_od*)pcell)))->GetParentWorldSpace()));
        if (pworld)
            fretval = reinterpret_cast<::FUN_009a1260_Class *>((pworld))->GetFloatAt0xC8();
    }
    return fretval;
}
}

// namespace fnv_0053a550

struct FUN_0053a760_Class {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30[6];
    void FUN_0053a760(unsigned char a, unsigned short b, int c);
};

struct LandLayerView
{
    char pad[0x30];
    int* apiLayers[4];
};
// @fnv 0x0053a760
void FUN_0053a760_Class::FUN_0053a760(unsigned char a, unsigned short b, int c)
{
    if (a < 4 && b < 6 && m_28)
        reinterpret_cast<LandLayerView*>(m_28)->apiLayers[a][b] = c;
}

struct FUN_0053ae30_class {
    float FUN_0053ae30(unsigned char type, unsigned short id);
};

struct GlobalObject_0044f440 {
};

// @fnv 0x0053ca40
float FUN_0053ca40()
{
    return *((float *)&(::FUN_00403e20((float *)&(::g_011c8dcc))));
}

struct FUN_0053ca60 {
    FUN_0053ca60* Init();
};

// @fnv 0x0053ca60
FUN_0053ca60* FUN_0053ca60::Init()
{
    new ((void *)this) ::FUN_00b600e0_cls();
    return this;
}

struct Buf50
{
    int m00; int m04; int m08; int m0C; int m10; int m14; int m18; int m1C;
    int m20; int m24; int m28; int m2C; int m30; int m34; int m38; int m3C;
    int m40; int m44; int m48; int m4C;
    void FUN_0053a510();
};

struct Owner
{
    bool FUN_0053d2e0(std::intptr_t, std::intptr_t, std::intptr_t);
};

struct FUN_0053df00_Class : LandFormView {
    std::intptr_t FUN_0053df00();
};

// @fnv 0x0053df00
std::intptr_t FUN_0053df00_Class::FUN_0053df00()
{
    return pLoadedData ? reinterpret_cast<std::intptr_t>(pLoadedData->unk08) : 0;
}

struct Tmp53e210 {
    int m00;
    int m04;
    int m08;
    int m0C;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
    int m48;
    int m4C;
    void FUN_0053a510();
};

struct Host53e210 {
    bool FUN_0053e210(std::intptr_t a);
};

struct FUN_0053e260_Class {
    void* m_p; // +0x00
    void* m_q; // +0x04
    void* m_r; // +0x08
    void* m_s; // +0x0c
    void* m_t; // +0x10
    void* m_u; // +0x14
    void* m_v; // +0x18
    void* m_w; // +0x1c
    void* m_uiX; // +0x20
    void* m_uiY; // +0x24
    void* m_uiZ; // +0x28
    unsigned char FUN_0053e260(int index, int offset);
};

// @fnv 0x0053e260
unsigned char FUN_0053e260_Class::FUN_0053e260(int index, int offset)
{
    return static_cast<::LoadedLandDataView*>(m_uiZ)->ppaucUnk10[index][offset];
}

namespace fnv_0053f0e0 {
struct NiPoint3_od { float x; float y; float z; };
struct NiGeometry { int _0; };
struct LandscapeColorData {
 int m00; int m04; int m08; int m0C; int m10; int m14; int m18; int m1C;
 int m20; int m24; int m28; int m2C; int m30; int m34; int m38; int m3C;
 int m40; int m44; int m48; int m4C;
 void FUN_0053a510();
};
struct TESObjectLAND {
 bool FUN_0053b550(LandscapeColorData*, const NiPoint3_od*, int);
 NiGeometry* FUN_0053f120(LandscapeColorData*);
 NiGeometry* FUN_0053f0e0(const NiPoint3_od&);
};
// @fnv 0x0053f0e0
NiGeometry* TESObjectLAND::FUN_0053f0e0(const NiPoint3_od& coord)
{
 LandscapeColorData cdata;
 new ((void *)&(cdata)) ::FUN_0053a510();
 if (!FUN_0053b550(&cdata, &coord, 0))
  return 0;
 return FUN_0053f120(&cdata);
}
}

class NiAVObject;

struct NiNode {  public:
    ::NiAVObject *GetAt(unsigned int);
};

struct FUN_0053f120_Param { unsigned char _pad[0x18]; unsigned int idx; };

struct FUN_0053f120_Holder { unsigned char _pad[0x28]; NiNode*** fld28; NiAVObject* FUN_0053f120(FUN_0053f120_Param*); };

// @fnv 0x0053f120
NiAVObject* FUN_0053f120_Holder::FUN_0053f120(FUN_0053f120_Param* a)
{
    if (fld28 == 0 || *fld28 == 0 || (*fld28)[a->idx] == 0)
        return 0;
    return ((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>(((*fld28)[a->idx]))->FUN_0045bc00(0)));
}

struct LandscapeColorData
{
    int m00,m04,m08,m0C,m10,m14,m18,m1C,m20,m24,m28,m2C,m30,m34,m38,m3C,m40,m44,m48,m4C;
    void FUN_0053a510();
};

struct TESObjectLAND
{
    bool FUN_0053f180(const LandscapeColorData&, float&);
};

namespace fnv_0053fa10 {
struct RgbaColor { float r, g, b, a; };
struct LandscapeColorData { char _00[0x18]; int m_iGridX; char _1C[0x20]; int m_iGridY; };
struct TESObjectLAND {
    void FUN_005345c0(int m_iGridX, int m_iGridY, RgbaColor* color);
    bool FUN_0053fa10(const LandscapeColorData* cdata, RgbaColor* color);
};
// @fnv 0x0053fa10
bool TESObjectLAND::FUN_0053fa10(const LandscapeColorData* cdata, RgbaColor* color)
{
    FUN_005345c0(cdata->m_iGridX, cdata->m_iGridY, color);
    return true;
}
}

// namespace fnv_0053fa10

struct QueuedFile;

struct BGSTextureSet {
    void LoadTextures(int, QueuedFile*, bool);
};

struct FUN_00541540_Class {
    char pad[0x18];
    BGSTextureSet* pTextureSet;
    void FUN_00541540(int a, QueuedFile* b);
};

// @fnv 0x00541540
void FUN_00541540_Class::FUN_00541540(int a, QueuedFile* b)
{
    if (pTextureSet)
        pTextureSet->LoadTextures(a, b, true);
}

struct FUN_00541590_Class {
    char pad[0x1f];
    char cUnk1f;
    char FUN_00541590();
};

// @fnv 0x00541590
char FUN_00541590_Class::FUN_00541590()
{
    return cUnk1f;
}

struct S_00592cf0 : ::BoundObjectPart, ::FirstComponentPart { void* FUN_00592cf0(); };

// @fnv 0x00592cf0
void* S_00592cf0::FUN_00592cf0()
{
    return this ? static_cast<::FirstComponentPart*>(this) : 0;
}

struct Param5380d0 {
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
	virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
	virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
	virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
	virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
	virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
	virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual bool v40();
};

struct This5380d0 {
	bool FUN_005380d0(Param5380d0* p);
};

// @fnv 0x005380d0
bool This5380d0::FUN_005380d0(Param5380d0* p)
{
	return p ? p->v40() : 0;
}

struct BSAudio {  };

BSAudio* _FUN_00c85750();

struct Topic
{
    virtual void f0() {}
    virtual void f1() {}
    virtual void Method(void* a, unsigned int b) {}
};

struct Prm
{
    char pad[4];
    unsigned short val;
};

// @fnv 0x00538eb0
void FUN_00538eb0(Prm* p)
{
    Prm* q = p;
    {
        Topic* t = (Topic*)((void *)(reinterpret_cast<::MagicCaster_shell *>((_FUN_00c85750()))->FUN_0044edb0()));
        t->Method(p, q->val);
    }
}

namespace fnv_00539010 {
struct TESForm_od {  };
struct TESObjectREFR {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void SetTargetingState(int);
};
struct TESObjectLAND : TESForm_od {
    void FUN_00539010(bool altered);
};
// @fnv 0x00539010
void TESObjectLAND::FUN_00539010(bool altered)
{
    reinterpret_cast<::fnv_00484730::FUN_00484730_shell *>(this)->FUN_00484730(altered);
    if (altered && reinterpret_cast<::LandFormView*>(this)->pParentCell)
        reinterpret_cast<TESObjectREFR*>(reinterpret_cast<::LandFormView*>(this)->pParentCell)->SetTargetingState(1);
}
}

// namespace fnv_00539010

struct FUN_0053a5a0_Inner
{
    char pad[32];
    void* arr[4];
};

struct FUN_0053a5a0_Outer
{
    char pad[40];
    FUN_0053a5a0_Inner* ptr;
    void* FUN_0053a5a0(unsigned char index);
};

// @fnv 0x0053a5a0
void* FUN_0053a5a0_Outer::FUN_0053a5a0(unsigned char index)
{
    void* result = 0;
    if (index < 4 && ptr != 0)
        result = ptr->arr[index];
    return result;
}

struct FUN_0053a700_Mid {
    unsigned char pad[0x30];
    int* arr[4];
};

struct FUN_0053a700_Holder {
    unsigned char pad[0x28];
    FUN_0053a700_Mid* p;
    std::intptr_t FUN_0053a700(unsigned char, unsigned short);
};

// @fnv 0x0053a700
std::intptr_t FUN_0053a700_Holder::FUN_0053a700(unsigned char a1, unsigned short a2)
{
    int result = 0;
    if (a1 < 4 && a2 < 6 && p && p->arr[a1]) {
        result = p->arr[a1][a2];
    }
    return result;
}

struct FUN_0053a630_Class : public FUN_0053ae30_class {
    intptr_t FUN_0053a630(unsigned char type, unsigned short id);
};

struct A51BF0Base {
    
};

struct FUN_00537d60 : A51BF0Base {
    char _pad[0x18];
    int _m18;
    int _m1c;
    FUN_00537e30_cls* FUN_00537e30();
    void SetOwner(TESQuest*);
    FUN_00537d60();
};

// @fnv 0x00537d60
void* FUN_00537d60_Create(std::uintptr_t a, uintptr_t b, unsigned int c, int d, int e)
{
    FUN_00537d60* obj = new FUN_00537d60;
    if (obj) {
        reinterpret_cast<::FUN_00537e90 *>((obj))->SetQuantity(e);
        reinterpret_cast<::CombatProcedure *>((obj))->Initialize((::CombatController *)(a));
        reinterpret_cast<::TESRegionGrassObject *>((obj))->AssignLandTexture((::TESLandTexture *)(b));
        reinterpret_cast<::FUN_0041fd00_shell *>((obj))->FUN_0041fd00(c);
        reinterpret_cast<::FUN_00600ab0_shell *>((obj))->FUN_00600ab0(d);
        obj->SetOwner(0);
    }
    return obj;
}

struct FUN_005330d8_class
{
};

struct FUN_005331f0_class : ::LandChildCellPart
{
    void FUN_005331f0();
};

// @fnv 0x005331f0
void FUN_005331f0_class::FUN_005331f0()
{
    reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<FUN_005330d8_class*>(
        static_cast<::LandChildCellView*>(static_cast<::LandChildCellPart*>(this)))))->FUN_007af430();
}

extern int DAT_0102dcd4;

extern int DAT_0102dccc;

struct FUN_00483370 {
    void* m_vt;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    FUN_00483370();
    ~FUN_00483370();
};

struct FUN_00533240_cls {
    void* m_vt;
    FUN_00533240_cls();
};

struct FUN_00528cb0_cls {
    int m_00;
    FUN_00528cb0_cls(int value);
    ~FUN_00528cb0_cls();
};

struct FUN_00533120_cls : FUN_00483370 {
    FUN_00533240_cls m_18;
    int m_1c;
    int m_20;
    FUN_00528cb0_cls m_24;
    int m_28;

    FUN_00533120_cls();
};

// @fnv 0x00533120
FUN_00533120_cls::FUN_00533120_cls() : m_18(), m_24((this->m_vt = &DAT_0102dcd4, this->m_18.m_vt = &DAT_0102dccc, 0))
{
    if ((*reinterpret_cast<unsigned char *>(&::g_landBuffersReady)) == 0) {
        ::TESLandInit::FUN_00533420();
    }
    FUN_00403d30(&this->m_1c, 0, 4);
    this->m_20 = 0;
    reinterpret_cast<::FUN_004f15a0_shell *>((this))->FUN_004f15a0(0x42);
    this->m_28 = 0;
    DAT_011c9f00++;
}

struct AutoMemContext {
    int ctx;
    AutoMemContext(int memContext, bool push, const char* file, int line);
    ~AutoMemContext();
};

struct LandData {
    int unk00;
};

struct LandForm : TESPackage {
    int unk20;
    int unk24;
    LandData* unk28;

    bool FUN_00535b90(bool bFlag);
};

struct FUN_0045cec0 {
    int unk00;
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    ~FUN_0045cec0();
};

struct FUN_005409b0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    ~FUN_005409b0();
};

struct FUN_00537130 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    FUN_0045cec0 m_14;
    FUN_005409b0 m_54[4];
    FUN_0045cec0 m_94;

    ~FUN_00537130();
};

// @fnv 0x00537100
void* FUN_00537100_Class::FUN_00537100(unsigned int flags)
{
    reinterpret_cast<::FUN_00537130 *>(this)->FUN_00537130::~FUN_00537130();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00537130
FUN_00537130::~FUN_00537130() {
}

class D40NiObject {
public:
    virtual ~D40NiObject();

    int m_uiRefCount;
};

class FUN_00537d40 : public D40NiObject {
public:
    virtual ~FUN_00537d40();
};

// @fnv 0x00537d10
void* FUN_00537d10_Class::FUN_00537d10(unsigned int flags)
{
    reinterpret_cast<::FUN_00537d40 *>((this))->FUN_00537d40::~FUN_00537d40();
    if (flags & 1)
        ::FUN_00aa1460(this, 52);
    return this;
}

// @fnv 0x00537d40
FUN_00537d40::~FUN_00537d40()
{
}

void __cdecl CompressSaveLoadRecord();

std::intptr_t FUN_00535ae0();

struct FUN_0084e3a0_Class { int FUN_0084e3a0(); };

struct FUN_00535aa0_Class { void FUN_00535aa0(); };

struct FUN_004855a0_shell {  };

struct FUN_00485680_shell {  };

extern double DAT_0102dfe0;

struct Elem16 { float x; float y; float z; float w; };

struct FUN_004a0c10_Class { float x; float y; float z;  };

struct Data538110 {
    void* m_00;
    NiPoint3_od** m_04;
    NiPoint3_od** m_08;
    Elem16** m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void* m_20arr[4];
    int* m_30arr[4];
    int m_40arr[4];
};

struct BigBuf538110 {
    float m_00;
    char m_04[1092];
};

struct X538110 {
    int m_00;
    unsigned char m_04;
    unsigned char m_05;
    unsigned short m_06;
};

struct Entry538110 {
    unsigned short m_00;
    unsigned short m_02;
    float m_04;
};

struct FUN_0053db20_Class {  };

struct FUN_0053a940_Class {  };

struct This538110 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    Data538110* m_28;
    void FUN_00538110();
};

struct Base8ef0 { virtual void v0(); int a; int b; int c; Base8ef0(); ~Base8ef0(); };

struct MA { int x[4]; MA();  };

struct MB { int x[3]; MB(); ~MB(); };

struct MC { int x[4]; MC();  };

struct FUN_00538d70_cls : Base8ef0 {
    MA a; MB b; MC c;
    FUN_00538d70_cls();
    virtual void v0();
};

// @fnv 0x00538d70
FUN_00538d70_cls::FUN_00538d70_cls() {
    reinterpret_cast<::S_00538f40 *>(&(a))->FUN_00538f40();
    reinterpret_cast<::FUN_005407b0_Class *>(&(c))->FUN_005407b0(2);
}

struct S_00539280_Arg {
    void* unk00;
    int unk04;
    int unk08;
    unsigned int unk0c;
};

struct S_00539280_Obj {
    virtual void vfn00();
    virtual void vfn01();
    virtual void vfn02();
    virtual void vfn03();
    virtual void vfn04();
    virtual void vfn05();
    virtual void vfn06();
    virtual void vfn07();
    virtual void vfn08();
    virtual void vfn09();
    virtual void vfn0a();
    virtual void vfn0b();
    virtual void vfn0c();
    virtual void vfn0d();
    virtual void vfn0e();
    virtual void vfn0f();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn1a();
    virtual void vfn1b();
    virtual void vfn1c();
    virtual void vfn1d();
    virtual void vfn1e();
    virtual void vfn1f();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn2a();
    virtual void vfn2b();
    virtual void vfn2c();
    virtual void vfn2d();
    virtual void vfn2e();
    virtual void vfn2f();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn3a();
    virtual void vfn3b();
    virtual void vfn3c();
    virtual void vfn3d();
    virtual void vfn3e();
    virtual void vfn3f();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual bool vfn44(S_00539280_Arg* a, bool b, bool c);
};

struct S_00539280_Owner {
    bool FUN_00539280(S_00539280_Arg* a, bool b, bool c);
};

// @fnv 0x00539280
bool S_00539280_Owner::FUN_00539280(S_00539280_Arg* a, bool b, bool c)
{
    bool result = false;
    if (a && a->unk00 == (*reinterpret_cast<void * *>(&::fnv_00543df0::kGroupFormType))) {
        S_00539280_Obj* o = ((::S_00539280_Obj *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()));
        switch (a->unk0c) {
        case 6:
            if (!b) {
                result = false;
                break;
            }
        case 8:
        case 9:
        {
            bool found = false;
            if (reinterpret_cast<::FUN_00485b60 *>((o))->FUN_00485be0(a->unk08))
                found = true;
            if (found) {
                switch (a->unk0c) {
                case 8:
                    result = false;
                    break;
                default:
                    result = true;
                    break;
                }
            }
            break;
        }
        default:
            if (b)
                result = o->vfn44(a, b, c);
            break;
        }
    }
    return result;
}

namespace fnv_00539360 {

struct Out539 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};

struct In539 {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};


struct FUN_00539360_cls {
    void FUN_00539360(Out539* a, In539* b);
};

// @fnv 0x00539360
void FUN_00539360_cls::FUN_00539360(Out539* a, In539* b) {
    void* p1;
    int t2;
    if (a != 0) {
        a->m_00 = 0;
        if (b != 0) {
            p1 = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((this))->FUN_007af430()));
            t2 = reinterpret_cast<::FUN_0084e3a0_Class *>((((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((this))->FUN_007af430()))))->FUN_0084e3a0();
            switch (b->m_0c) {
            case 3:
            case 5:
                if (b->m_08 == ((int)(reinterpret_cast<::FUN_00544210_shell *>((p1))->FUN_00544210()))) {
                    a->m_00 = (*reinterpret_cast<int *>(&::fnv_00543df0::kGroupFormType));
                    a->m_0c = 6;
                    a->m_08 = t2;
                    a->m_04 = 0;
                    a->m_10 = 0;
                }
                break;
            case 6:
                if (b->m_08 == t2) {
                    a->m_00 = (*reinterpret_cast<int *>(&::fnv_00543df0::kGroupFormType));
                    a->m_0c = 9;
                    a->m_08 = reinterpret_cast<::FUN_0084e3a0_Class *>((((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((this))->FUN_007af430()))))->FUN_0084e3a0();
                    a->m_04 = 0;
                    a->m_10 = 0;
                }
                break;
            }
        }
    }
}
}

// namespace fnv_00539360

struct Mem960 {int value;Mem960(int,bool,const char*,int);~Mem960();};

struct Color960 {float r,g,b,a;Color960(float,float,float,float);};

struct Texture960 {};

struct Property960 {virtual void v000();virtual void v004();virtual void v008();virtual void v00c();virtual void v010();virtual void v014();virtual void v018();virtual void v01c();virtual void v020();virtual void v024();virtual void v028();virtual void v02c();virtual void v030();virtual void v034();virtual void v038();virtual void v03c();virtual void v040();virtual void v044();virtual void v048();virtual void v04c();virtual void v050();virtual void v054();virtual void v058();virtual void v05c();virtual void v060();virtual void v064();virtual void v068();virtual void v06c();virtual void v070();virtual void v074();virtual void v078();virtual void v07c();virtual void v080();virtual void v084();virtual void v088();virtual void v08c();virtual void v090();virtual void v094();virtual void v098();virtual void v09c();virtual void v0a0();virtual void v0a4();virtual void v0a8();virtual void v0ac();virtual void v0b0();virtual void v0b4();virtual void v0b8();virtual void v0bc();virtual void v0c0();virtual void v0c4();virtual void v0c8();virtual void v0cc();virtual void v0d0();virtual void* vd4(void*);unsigned unk004;unsigned unk008;unsigned unk00c;unsigned unk010;unsigned unk014;unsigned unk018;unsigned unk01c;unsigned unk020;unsigned unk024;unsigned unk028;unsigned unk02c;unsigned unk030;unsigned unk034;unsigned unk038;unsigned unk03c;unsigned unk040;unsigned unk044;unsigned unk048;unsigned unk04c;unsigned unk050;unsigned unk054;unsigned unk058;unsigned unk05c;unsigned unk060;unsigned unk064;unsigned unk068;unsigned unk06c;unsigned unk070;unsigned unk074;unsigned unk078;unsigned unk07c;unsigned unk080;unsigned unk084;unsigned unk088;unsigned unk08c;unsigned unk090;unsigned unk094;unsigned unk098;unsigned unk09c;unsigned unk0a0;unsigned unk0a4;unsigned unk0a8;unsigned unk0ac;unsigned unk0b0;unsigned unk0b4;unsigned unk0b8;unsigned unk0bc;unsigned unk0c0;unsigned unk0c4;unsigned unk0c8;unsigned unk0cc;unsigned unk0d0;unsigned unk0d4;unsigned unk0d8;unsigned unk0dc;unsigned unk0e0;unsigned unk0e4;unsigned unk0e8;unsigned unk0ec;unsigned unk0f0;unsigned unk0f4;unsigned unk0f8;unsigned unk0fc;unsigned unk100;Property960();};

struct Binary960 {unsigned unk00,unk04,unk08,unk0c,unk10;Binary960(unsigned,unsigned char*);};

struct Geometry960 {};

struct Node960 {};

struct Data960 {Node960** nodes;unsigned unk04,unk08;Color960** colors;unsigned unk10,unk14,unk18,unk1c;Texture960* base[4];Texture960** layers[4];unsigned char** binary[4];};

struct Host960 {unsigned unk00,unk04,unk08,unk0c,unk10,unk14,unk18,flags,unk20,unk24;Data960* data;bool FUN_00539960();};

// @fnv 0x00539960
bool Host960::FUN_00539960() {
 Mem960 f(27,true,"D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESLand.cpp",0xca4);
 if(!data || !data->nodes || !*data->nodes) return false;
 Color960 s(1,1,1,0);
 int a,p,h,i;
 if(!(flags & 2)) {
  for(a=0;a<4;a++) {
   i=0;
   for(p=0;p<17;p++) {
    for(h=0;h<17;h++) {
     int index=p*17+h;
     data->colors[a][index]=s;
    }
   }
  }
 }
 reinterpret_cast<::FUN_005394c0_Class *>(this)->FUN_005394c0(true);
 for(a=0;a<4;a++) {
  unsigned char*** binary=data->binary;
  if(binary) {
   Binary960* extra=new Binary960(9248,*data->binary[a]);
   reinterpret_cast<::Holder *>((data->nodes[a]))->FUN_00a5bc40((*(const ::NiFixedString *)(((const char *)(::FUN_00539f40())))),(::NiTexture *)(extra));
  }
  Property960* property=new Property960;
  reinterpret_cast<::LowProcess *>((property))->SetPackageObjectType(1);
  if(property) {
   Texture960* texture=data->base[a];
   if(texture && ((::Texture960 *)(reinterpret_cast<::FUN_009611e0_shell *>((texture))->FUN_009611e0()))) reinterpret_cast<::TexSet_b68660 *>((property))->FUN_00b68660(0,(::TexSource_b68660 *)(void *)(reinterpret_cast<::S_00592cf0 *>((((::Texture960 *)(reinterpret_cast<::FUN_009611e0_shell *>((texture))->FUN_009611e0()))))->FUN_00592cf0()));
   else reinterpret_cast<::TexSet_b68660 *>((property))->FUN_00b68660(0,(::TexSource_b68660 *)(void *)(reinterpret_cast<::S_00592cf0 *>((((::Texture960 *)(reinterpret_cast<::FUN_009611e0_shell *>((((Texture960*)FUN_00535ae0())))->FUN_009611e0()))))->FUN_00592cf0()));
   for(int layer=1;layer<7;layer++) {
    texture=data->layers[a][layer-1];
    if(texture && ((::Texture960 *)(reinterpret_cast<::FUN_009611e0_shell *>((texture))->FUN_009611e0()))) reinterpret_cast<::TexSet_b68660 *>((property))->FUN_00b68660(layer,(::TexSource_b68660 *)(void *)(reinterpret_cast<::S_00592cf0 *>((((::Texture960 *)(reinterpret_cast<::FUN_009611e0_shell *>((texture))->FUN_009611e0()))))->FUN_00592cf0()));
    else reinterpret_cast<::TexSet_b68660 *>((property))->FUN_00b68660(layer,(::TexSource_b68660 *)(void *)(0));
   }
   reinterpret_cast<::LandscapeSpecularView *>((property))->FUN_00b66640(data->base[a]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((data->base[a]))->FUN_00541590())):0,
    data->layers[a][0]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((data->layers[a][0]))->FUN_00541590())):0,
    data->layers[a][1]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((data->layers[a][1]))->FUN_00541590())):0,
    data->layers[a][2]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((data->layers[a][2]))->FUN_00541590())):0,
    data->layers[a][3]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((data->layers[a][3]))->FUN_00541590())):0,
    data->layers[a][4]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((data->layers[a][4]))->FUN_00541590())):0,
    data->layers[a][5]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((data->layers[a][5]))->FUN_00541590())):0,0,0,0);
   Geometry960* value=((::Geometry960 *)(reinterpret_cast<::S_FUN_0045bc00 *>((data->nodes[a]))->FUN_0045bc00(0)));
   void* geometry=((void *)(::FUN_00b54b60((::NiGeometry *)(value))));
   reinterpret_cast<::FUN_00539f20_Class *>((property))->FUN_00539f20(geometry);
   void* shader=property->vd4(value);
   reinterpret_cast<::ShaderOwner *>((value))->FUN_00539ef0((::NiGPUProgram *)(shader));
   reinterpret_cast<::FUN_00439410_cls *>((value))->FUN_00439410((::ArgObject *)(property));
   ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(data->nodes[a]),0,0);
  }
 }
 return true;
}

class B53A000ExtraData {
public:
    virtual ~B53A000ExtraData();

    int m_iRefCount;
    const char* m_kName;
};

class FUN_0053a000_cls : public B53A000ExtraData {
public:
    virtual ~FUN_0053a000_cls();

    void* m_pResource;
};

// @fnv 0x00539fd0
void* FUN_00539fd0::ScalarDeletingDestructor(unsigned int flags)
{
    reinterpret_cast<::FUN_0053a000_cls *>((reinterpret_cast<FUN_0053a000*>(this)))->FUN_0053a000_cls::~FUN_0053a000_cls();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x14);
    return this;
}

// @fnv 0x0053a000
FUN_0053a000_cls::~FUN_0053a000_cls()
{
    ::FUN_00aa10f0(m_pResource);
    m_pResource = 0;
}

struct LocalObj53a5e0 {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    unsigned char m18;
    unsigned char unk19;
    unsigned char unk1a;
    unsigned char unk1b;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    unsigned short m3c;
    unsigned short unk3e;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    void FUN_0053a510();
};

struct FUN_0053a5e0_cls {
    int FUN_0053a5e0(std::intptr_t arg);
};

struct FUN_0053a7a0_Tbl {
    char pad[0x40];
    float** arr[4];
};

struct FUN_0053a7a0_cls {
    char pad[0x28];
    FUN_0053a7a0_Tbl* m_28;
    float FUN_0053a7a0(unsigned char a, unsigned short b);
};

// @fnv 0x0053a7a0
float FUN_0053a7a0_cls::FUN_0053a7a0(unsigned char a, unsigned short b) {
    float sum5 = 0.0f;
    int i;
    if ((int)a < 4 && (int)b < 0x121 && m_28 != 0 && m_28->arr[a] != 0) {
        for (i = 0; i < 6; ++i) {
            sum5 += m_28->arr[a][b][i];
        }
    }
    return 1.0f - sum5;
}

struct FUN_0053a830_Row {
    float* cells[0x121];
};

struct FUN_0053a830_Mid {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    float** tables[4];
};

struct FUN_0053a830_cls {
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    FUN_0053a830_Mid* m_28;
    float FUN_0053a830(unsigned char type, unsigned short id, unsigned short idx);
};

// @fnv 0x0053ae30
float FUN_0053ae30_class::FUN_0053ae30(unsigned char type, unsigned short id)
{
    float result = 0.0f;
    if (type < 4 && id < 6) {
        if (reinterpret_cast<::FUN_0053a700_Holder *>(this)->FUN_0053a700(type, id)) {
            for (int i = 0; i < 289; ++i) {
                result += reinterpret_cast<::FUN_0053a830_cls *>(this)->FUN_0053a830(type, (unsigned short)i, id);
            }
        }
    }
    return result;
}

// @fnv 0x0053a630
intptr_t FUN_0053a630_Class::FUN_0053a630(unsigned char type, unsigned short id)
{
    std::intptr_t result = 0;
    if (type < 4 && id < 0x121) {
        float best = DAT_01015f5c;
        int index = 0;
        for (unsigned int i = 0; i < 6; ++i) {
            float value = reinterpret_cast<::FUN_0053a830_cls *>(this)->FUN_0053a830(type, id, i);
            if (value > best) {
                best = value;
                index = i;
            }
        }
        if (index == 0) {
            result = (std::intptr_t)((FUN_0053a5a0_Outer*)this)->FUN_0053a5a0(type);
        } else {
            result = reinterpret_cast<::FUN_0053a700_Holder *>(this)->FUN_0053a700(type, index - 1);
        }
    }
    return result;
}

// @fnv 0x0053a830
float FUN_0053a830_cls::FUN_0053a830(unsigned char type, unsigned short id, unsigned short idx) {
    float result = 0.0f;
    if (type < 4 && id < 0x121 && idx < 6) {
        if (m_28 != 0 && m_28->tables[type] != 0) {
            result = m_28->tables[type][id][idx];
        }
    }
    return result;
}

struct C53A8A0Data {
    int unk00;
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    float** m_appfTables[4];
};

class C53A8A0Owner {
public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    C53A8A0Data* m_pUserData;

    void FUN_0053a8a0(unsigned char ucTable, unsigned short usRow, unsigned short usColumn, float fValue);
};

// @fnv 0x0053a8a0
void C53A8A0Owner::FUN_0053a8a0(unsigned char ucTable, unsigned short usRow, unsigned short usColumn, float fValue)
{
    if (ucTable < 4 && usRow < 0x121 && usColumn < 6 && m_pUserData) {
        if (fValue > ::_DAT_01012060)
            m_pUserData->m_appfTables[ucTable][usRow][usColumn] = fValue;
        else if (m_pUserData->m_appfTables[ucTable])
            m_pUserData->m_appfTables[ucTable][usRow][usColumn] = 0.0f;
    }
}

struct WeightTables53ace0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int current[4];
    int* choices[4];
    float** weights[4];
};

struct Owner53ace0 : public FUN_0053ae30_class {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    WeightTables53ace0* tables;
    void FUN_0053ace0(unsigned char type, unsigned short id);
};

// @fnv 0x0053ace0
void Owner53ace0::FUN_0053ace0(unsigned char type, unsigned short id)
{
    if (type < 4 && id < 6 && tables) {
        int newValue = tables->choices[type][id];
        int oldValue3 = tables->current[type];
        tables->current[type] = newValue;
        tables->choices[type][id] = oldValue3;
        if (tables->weights[type]) {
            for (int i = 0; i < 0x121; i++) {
                unsigned int count4 = 6;
                float sum4 = 0.0f;
                for (unsigned int j = 0; j < count4; j++) {
                    sum4 += reinterpret_cast<::FUN_0053a830_cls *>(this)->FUN_0053a830(type, (unsigned short)i, (unsigned short)j);
                }
                float rest = 1.0f - sum4;
                if (rest < 0.0) {
                    rest = 0.0f;
                }
                tables->weights[type][i][id] = rest;
            }
        }
    }
}

struct FNv53b450_Point {
    float x;
    float y;
    float z;
};

struct FNv53b450_Source {
    int FUN_00534010_od();
    FNv53b450_Point* FUN_0053b450(FNv53b450_Point* output, unsigned char flags, unsigned short cellIndex, const int* x, const int* y);
};

class B3CA80Map {
public:

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct B3CA80Data {
    int unk00;
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
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    B3CA80Map m_akMaps[4];
};

class B3CA80Owner {
public:
    unsigned int FUN_0053ca80(int iQuad, int iIndex);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    B3CA80Data* m_pUserData;
};

// @fnv 0x0053ca80
unsigned int B3CA80Owner::FUN_0053ca80(int iQuad, int iIndex)
{
    if (!m_pUserData || iQuad >= 4 || iIndex + 0x12 >= 0x121 || iIndex - 0x12 < 0)
        return 0;
    unsigned int uiValue;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&(m_pUserData->m_akMaps[iQuad]))->FUN_00853130(iIndex, (::fnv_00853130::CombatThreatRecord *&)(uiValue)))
        return uiValue;
    else
        return 0;
}

struct Obj53 {
};

struct Cell53 {
};

struct FUN_00461c20_Holder {
    Cell53* GetOrCreateCell(int a, int b, TESWorldSpace* ws, bool f);
};

struct This53 {
    void FUN_0053d330(Obj53** out, bool flag, unsigned char* outFlags);
};

// @fnv 0x0053d330
void This53::FUN_0053d330(Obj53** out, bool flag, unsigned char* outFlags)
{
    Cell53* temp;
    if (out == 0)
        return;
    temp = (*reinterpret_cast<::FUN_00461c20_Holder * *>(&::g_dataHandler))->GetOrCreateCell(reinterpret_cast<::FUN_00533fd0_Class *>((((FUN_00534050_Class*)this)))->FUN_00533fd0() - 1, reinterpret_cast<::fnv_00534010::FUN_00534010_od *>((((FUN_00534080_Class*)this)))->GetY() + 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90()) {
        out[0] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
    } else if (temp != 0 && !reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90() && flag && outFlags != 0) {
        out[0] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
        reinterpret_cast<::LandForm *>((out[0]))->FUN_00535b90(0);
        outFlags[0] = 1;
    } else {
        out[0] = 0;
    }
    temp = (*reinterpret_cast<::FUN_00461c20_Holder * *>(&::g_dataHandler))->GetOrCreateCell(reinterpret_cast<::FUN_00533fd0_Class *>((((FUN_00534050_Class*)this)))->FUN_00533fd0(), reinterpret_cast<::fnv_00534010::FUN_00534010_od *>((((FUN_00534080_Class*)this)))->GetY() + 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90()) {
        out[1] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
    } else if (temp != 0 && !reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90() && flag && outFlags != 0) {
        out[1] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
        reinterpret_cast<::LandForm *>((out[1]))->FUN_00535b90(0);
        outFlags[1] = 1;
    } else {
        out[1] = 0;
    }
    temp = (*reinterpret_cast<::FUN_00461c20_Holder * *>(&::g_dataHandler))->GetOrCreateCell(reinterpret_cast<::FUN_00533fd0_Class *>((((FUN_00534050_Class*)this)))->FUN_00533fd0() + 1, reinterpret_cast<::fnv_00534010::FUN_00534010_od *>((((FUN_00534080_Class*)this)))->GetY() + 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90()) {
        out[2] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
    } else if (temp != 0 && !reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90() && flag && outFlags != 0) {
        out[2] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
        reinterpret_cast<::LandForm *>((out[2]))->FUN_00535b90(0);
        outFlags[2] = 1;
    } else {
        out[2] = 0;
    }
    temp = (*reinterpret_cast<::FUN_00461c20_Holder * *>(&::g_dataHandler))->GetOrCreateCell(reinterpret_cast<::FUN_00533fd0_Class *>((((FUN_00534050_Class*)this)))->FUN_00533fd0() - 1, reinterpret_cast<::fnv_00534010::FUN_00534010_od *>((((FUN_00534080_Class*)this)))->GetY(), ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90()) {
        out[3] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
    } else if (temp != 0 && !reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90() && flag && outFlags != 0) {
        out[3] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
        reinterpret_cast<::LandForm *>((out[3]))->FUN_00535b90(0);
        outFlags[3] = 1;
    } else {
        out[3] = 0;
    }
    temp = (*reinterpret_cast<::FUN_00461c20_Holder * *>(&::g_dataHandler))->GetOrCreateCell(reinterpret_cast<::FUN_00533fd0_Class *>((((FUN_00534050_Class*)this)))->FUN_00533fd0() + 1, reinterpret_cast<::fnv_00534010::FUN_00534010_od *>((((FUN_00534080_Class*)this)))->GetY(), ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90()) {
        out[4] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
    } else if (temp != 0 && !reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90() && flag && outFlags != 0) {
        out[4] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
        reinterpret_cast<::LandForm *>((out[4]))->FUN_00535b90(0);
        outFlags[4] = 1;
    } else {
        out[4] = 0;
    }
    temp = (*reinterpret_cast<::FUN_00461c20_Holder * *>(&::g_dataHandler))->GetOrCreateCell(reinterpret_cast<::FUN_00533fd0_Class *>((((FUN_00534050_Class*)this)))->FUN_00533fd0() - 1, reinterpret_cast<::fnv_00534010::FUN_00534010_od *>((((FUN_00534080_Class*)this)))->GetY() - 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90()) {
        out[5] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
    } else if (temp != 0 && !reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90() && flag && outFlags != 0) {
        out[5] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
        reinterpret_cast<::LandForm *>((out[5]))->FUN_00535b90(0);
        outFlags[5] = 1;
    } else {
        out[5] = 0;
    }
    temp = (*reinterpret_cast<::FUN_00461c20_Holder * *>(&::g_dataHandler))->GetOrCreateCell(reinterpret_cast<::FUN_00533fd0_Class *>((((FUN_00534050_Class*)this)))->FUN_00533fd0(), reinterpret_cast<::fnv_00534010::FUN_00534010_od *>((((FUN_00534080_Class*)this)))->GetY() - 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90()) {
        out[6] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
    } else if (temp != 0 && !reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90() && flag && outFlags != 0) {
        out[6] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
        reinterpret_cast<::LandForm *>((out[6]))->FUN_00535b90(0);
        outFlags[6] = 1;
    } else {
        out[6] = 0;
    }
    temp = (*reinterpret_cast<::FUN_00461c20_Holder * *>(&::g_dataHandler))->GetOrCreateCell(reinterpret_cast<::FUN_00533fd0_Class *>((((FUN_00534050_Class*)this)))->FUN_00533fd0() + 1, reinterpret_cast<::fnv_00534010::FUN_00534010_od *>((((FUN_00534080_Class*)this)))->GetY() - 1, ((FUN_005340b0_Class*)this)->FUN_005340b0(), false);
    if (temp != 0 && reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90()) {
        out[7] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
    } else if (temp != 0 && !reinterpret_cast<::FUN_0045cb90_cls *>((((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()))))->FUN_0045cb90() && flag && outFlags != 0) {
        out[7] = ((::Obj53 *)(reinterpret_cast<::S00546fb0_Cell *>((temp))->FUN_00546fb0()));
        reinterpret_cast<::LandForm *>((out[7]))->FUN_00535b90(0);
        outFlags[7] = 1;
    } else {
        out[7] = 0;
    }
}

class B3DA60Point3 {
public:
    B3DA60Point3(float fX, float fY, float fZ);


    float x;
    float y;
    float z;
};

struct B3DA60Rect {
    int m_iLeft;
    int m_iBottom;
    int m_iRight;
    int m_iTop;
};

class B3DA60Object {
public:
    bool FUN_0053da60(B3DA60Rect* pkRect, void* pvMatrix);
};

// @fnv 0x0053da60
bool B3DA60Object::FUN_0053da60(B3DA60Rect* pkRect, void* pvMatrix)
{
    if (pkRect) {
        B3DA60Point3 kPoint(reinterpret_cast<::FUN_00534050_Class *>(this)->FUN_00534050() + DAT_01016968, reinterpret_cast<::FUN_00534080_Class *>(this)->FUN_00534080() + DAT_01016968, 0.0f);
        reinterpret_cast<::FUN_0063c8a0_shell *>(&(kPoint))->FUN_0063c8a0(pvMatrix);
        if (kPoint.x > pkRect->m_iRight || kPoint.y > pkRect->m_iBottom)
            return false;
        if (kPoint.x < pkRect->m_iLeft || kPoint.y < pkRect->m_iTop)
            return false;
    }
    return true;
}

struct FUN_0053f390_v2 {
    float x;
    float y;
};

struct FUN_0053f390_v3 {
    float x;
    float y;
    float z;
};

struct FUN_0053f390_cls {
    FUN_0053f390_v2* FUN_0053f390(FUN_0053f390_v2* out, int n);
};

class NiPoint2 { public: float x,y; NiPoint2(float,float); };

struct UVBounds { float x,y,z,w; };

struct TextureSample {    };

struct TexturePointer {  };

struct TextureManager {    };

struct WorldManager {  };

struct TESView {  };

struct ShaderProperty {
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
 virtual void v28();
 virtual void v2c();
 virtual void v30();
 virtual void v34();
 virtual void v38();
 virtual void v3c();
 virtual void v40();
 virtual void v44();
 virtual void v48();
 virtual void v4c();
 virtual void v50();
 virtual void v54();
 virtual void v58();
 virtual void v5c();
 virtual void v60();
 virtual void v64();
 virtual void v68();
 virtual void v6c();
 virtual void v70();
 virtual void v74();
 virtual void v78();
 virtual void v7c();
 virtual void v80();
 virtual void v84();
 virtual void v88();
 virtual void v8c();
 virtual void v90();
 virtual void v94();
 virtual void v98();
 virtual void v9c();
 virtual void va0();
 virtual void va4();
 virtual void va8();
 virtual void vac();
 virtual void vb0();
 virtual void vb4();
 virtual void vb8();
 virtual void vbc();
 virtual void vc0();
 virtual void vc4();
 virtual void vc8();
 virtual void vcc();
 virtual void vd0();
 virtual void vd4();
 virtual void vd8();
 virtual void vdc();
 virtual void ve0();
 virtual void ve4();
 virtual void ve8();
 virtual void vec();
 virtual void vf0();
 virtual void vf4();
 virtual void vf8();
 virtual void setFirst(int,void*);
 virtual void setSecond(int,void*);
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 UVBounds bounds;
   
};

struct QuadNode {   };

struct TESFileRecordLoader {
 QuadNode** nodes;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 int unk28;
 int unk2c;
 int unk30;
 int unk34;
 int unk38;
 int unk3c;
 int unk40;
 int unk44;
 int unk48;
 int unk4c;
 int unk50;
 int unk54;
 int unk58;
 int unk5c;
 int unk60;
 int unk64;
 int unk68;
 int unk6c;
 int unk70;
 int unk74;
 int unk78;
 int unk7c;
 int unk80;
 int unk84;
 int unk88;
 int unk8c;
 int unk90;
 int unk94;
 int x,y;
};

struct Surface {
 int unk00;
 int unk04;
 int unk08;
 int unk0c;
 int unk10;
 int unk14;
 int unk18;
 int unk1c;
 int unk20;
 int unk24;
 TESFileRecordLoader* data;
 void FUN_005400e0();
};

// @fnv 0x005400e0
void Surface::FUN_005400e0()
{
 void* e=0;
 void* l=0;
 TextureManager* ba=((::WorldManager *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TESView * *>(&::g_TES))))->GetHitSound())) ? ((::TextureManager *)(reinterpret_cast<::TESWorldSpace *>((((::WorldManager *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::TESView * *>(&::g_TES))))->GetHitSound()))))->GetWorldTerrainManager())) : 0;
 NiPoint3_od c=::NiPoint3_od::ZERO;
 c.x=(data->x+0.5)*4096.0;
 c.y=(data->y+0.5)*4096.0;
 NiPoint2 k=DAT_011f4980;
 for(int j=0;j<4;j++) {
  if(data->nodes && ba) {
   ShaderProperty* q=((::ShaderProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((::QuadNode *)(reinterpret_cast<::S_FUN_0045bc00 *>((data->nodes[j]))->FUN_0045bc00(0)))))->FUN_00a59d30(3)));
   ShaderProperty* b=(!q ? 0 : (((int)(reinterpret_cast<::BGSTerrainManager *>((q))->GetMinLevel()))>=8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((q))->GetMinLevel()))<=12)) ? q : 0;
   if(b && (!((void *)(reinterpret_cast<::S *>((b))->GetElement(9))) || !((void *)(reinterpret_cast<::fnv_00540570::FUN_00540570_Owner *>((b))->GetFltValue(9))))) {
    e=((void *)(reinterpret_cast<::FUN_006fce30_shell *>((ba))->FUN_006fce30((std::intptr_t)&(c))));
    l=((void *)(reinterpret_cast<::FUN_006fce70_shell *>((ba))->FUN_006fce70((std::intptr_t)&(c))));
    b->setFirst(9,e);
    b->setSecond(9,l);
    UVBounds cf=DAT_011a9bd0;
    switch(j) {
     case 0:k=NiPoint2(0.0f,0.0f);break;
     case 1:k=NiPoint2(0.5f,0.0f);break;
     case 2:k=NiPoint2(0.0f,0.5f);break;
     case 3:k=NiPoint2(0.5f,0.5f);break;
    }
    TexturePointer* eb=((::TexturePointer *)(reinterpret_cast<::BGSTerrainChunk *>((ba))->FUN_006fceb0((std::intptr_t)&(c))));
    if(eb) {
     short i=((short)(reinterpret_cast<::TESActorBaseData *>((((::TextureSample *)(::FUN_00559450((int *)(eb))))))->GetFatigue()));
     short a=((short)(reinterpret_cast<::BSShaderPPLightingProperty *>((((::TextureSample *)(::FUN_00559450((int *)(eb))))))->GetDiffuseTextureIndex()));
     std::uintptr_t h=((std::uintptr_t)(reinterpret_cast<::Callees *>((((::TextureSample *)(::FUN_00559450((int *)(eb))))))->FUN_00726070()));
     float f=(float)data->x-i;
     float s=(float)data->y-a;
     cf.x=(f+k.x)/((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((::TextureSample *)(::FUN_00559450((int *)(eb))))))->FUN_00726070()));
     cf.y=(s+k.y)/((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((::TextureSample *)(::FUN_00559450((int *)(eb))))))->FUN_00726070()));
     while(cf.x>1.0)cf.x-=1.0;
     while(cf.x<0.0)cf.x+=1.0;
     while(cf.y>1.0)cf.y-=1.0;
     while(cf.y<0.0)cf.y+=1.0;
     b->bounds=cf;
    }
   }
  }
 }
}

struct FUN_00538ef0 {
    virtual void VirtualMethod();
    ~FUN_00538ef0();
    int m_kPointA;
    int m_kPointB;
    FUN_00538ef0();
};

struct FUN_0056d640 : FUN_00538ef0 {
    B006815c0 m_quantity;
    FUN_0056d640(unsigned int quantity);
};

// @fnv 0x0056d640
FUN_0056d640::FUN_0056d640(unsigned int quantity)
    : FUN_00538ef0(), m_quantity()
{
    m_kPointB = 0;
    reinterpret_cast<FUN_00537e90*>(&m_quantity)->SetQuantity(quantity);
}

struct LandFormBase {
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    virtual ~LandFormBase();
};

struct LandChildCell {
    virtual void* GetPersistentCell() = 0;
};

struct LandMember24 {
    int unk00;
    ~LandMember24();
};

struct LandSharedObject {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual ~LandSharedObject();
};

struct LandNiPointer {
    LandNiPointer& operator=(void* p);
};

struct LandBuffer {
    int unk00;
};

struct FUN_00533260 : LandFormBase, LandChildCell {
    int unk1C;
    int unk20;
    LandMember24 unk24;
    virtual void* GetPersistentCell();
    virtual ~FUN_00533260();
};

// @fnv 0x00533210
void* FUN_00533210_class::FUN_00533210(unsigned int flags)
{
    reinterpret_cast<::FUN_00533260 *>((((FUN_00533260_holder*)this)))->FUN_00533260::~FUN_00533260();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct LandPoint3 {
    float x;
    float y;
    float z;
    LandPoint3(float fx, float fy, float afDepth);
};

struct LandGeomData {
};

struct LandNode {
};

struct LandLoadedData {
    LandNode** m_ppLandNodes;
    LandPoint3** m_ppLandPoints;
    int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C;
    int unk80; int unk84; int unk88; int unk8C; int unk90; int unk94; int unk98; int unk9C;
    float m_fTrailingValue;
};

struct LandObject : TESObjectLAND {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24;
    LandLoadedData* m_pRenderData;
    void FUN_00534240(int quadrant, int index, LandPoint3* vertex);
};

// @fnv 0x00534240
void LandObject::FUN_00534240(int quadrant, int index, LandPoint3* vertex)
{
    if (!reinterpret_cast<::FUN_0045cb90_cls *>(this)->FUN_0045cb90()) {
        *vertex = LandPoint3(0.0f, 0.0f, reinterpret_cast<::fnv_0053a550::DoorH_od *>(this)->FUN_0053a550());
        return;
    }
    if (m_pRenderData->m_ppLandPoints && m_pRenderData->m_ppLandPoints[quadrant]) {
        *vertex = m_pRenderData->m_ppLandPoints[quadrant][index];
    } else if (m_pRenderData->m_ppLandNodes && m_pRenderData->m_ppLandNodes[quadrant]) {
        LandGeomData* pGeom = ((::LandGeomData *)(reinterpret_cast<::NiNode *>((m_pRenderData->m_ppLandNodes[quadrant]))->GetAt(0)));
        *vertex = ((::LandPoint3 *)(reinterpret_cast<::FUN_0049ec60 *>((pGeom))->GetNext()))[index];
    } else {
        *vertex = LandPoint3(0.0f, 0.0f, reinterpret_cast<::fnv_0053a550::DoorH_od *>(this)->FUN_0053a550());
    }
    vertex->z += m_pRenderData->m_fTrailingValue;
}

struct VertPt {
    float x; float y; float z;
    VertPt(float fx, float fy, float afDepth);
};

struct VertCtl {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80(); virtual void v84(); virtual void v88();
    virtual bool IsSkinned();
};

struct VertLock : FUN_00534570_shell {
    int unk08;
    VertLock();
};

struct VertGeomData {
};

struct VertGeom {
};

struct VertNode {
};

struct VertTables {
    VertNode** nodes;
    int unk04;
    VertPt** points;
};

struct VertOwner {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int unk14; int unk18; int unk1c; int unk20; int unk24;
    VertTables* tables;
    void FUN_00534390(unsigned int index, unsigned int vert, VertPt& out);
};

// @fnv 0x00534390
void VertOwner::FUN_00534390(unsigned int index, unsigned int vert, VertPt& out)
{
    if (!reinterpret_cast<::FUN_0045cb90_cls *>(this)->FUN_0045cb90()) {
        out = VertPt(0.0f, 0.0f, 1.0f);
        return;
    }
    bool found = false;
    if (tables->points && tables->points[index]) {
        out = tables->points[index][vert];
        found = true;
    } else if (tables->nodes && tables->nodes[index]) {
        VertGeom* geom = ((::VertGeom *)(reinterpret_cast<::NiNode *>((tables->nodes[index]))->GetAt(0)));
        if (((::VertPt *)(std::uintptr_t)(reinterpret_cast<::FUN_004a8030_shell *>((geom))->FUN_004a8030()))) {
            out = ((::VertPt *)(std::uintptr_t)(reinterpret_cast<::FUN_004a8030_shell *>((geom))->FUN_004a8030()))[vert];
            found = true;
        } else {
            VertGeomData* data = ((::VertGeomData *)(::fnv_005495f0::FUN_005495f0((const char *)(geom))));
            VertLock lock_;
            VertCtl* aCtl = ((::VertCtl *)(::fnv_004a8a90::FUN_004a8a90((char *)(data))));
            if (aCtl && aCtl->IsSkinned() && reinterpret_cast<::NiGeometryData *>((data))->IsGeometryDataStreamable(1)) {
                reinterpret_cast<::RenderOwner *>((data))->GetBounds((::BoundOut *)(::VertLock *)(&lock_));
                lock_.FUN_00534570(vert, (NiPoint3_od&)out);
                reinterpret_cast<::FUN_00a673d0_shell *>((data))->FUN_00a673d0();
                found = true;
            }
        }
    }
    if (!found)
        out = VertPt(0.0f, 0.0f, 1.0f);
}

struct Color_5345c0 { float r, g, b, a; };

struct Buffer_5345c0 {
    void* data;
    unsigned int stride;
    unsigned int unk08;
};

struct Format_5345c0 {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual bool HasColor();
};

struct Data_5345c0 {
};

struct Geometry_5345c0 {
};

struct Node_5345c0 {  };

struct Store_5345c0 {
    Node_5345c0** nodes;
    int unk04;
    int unk08;
    Color_5345c0** colors;
};

struct FUN_005345c0_shell {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Store_5345c0* store;
    void FUN_005345c0(unsigned int group, unsigned int index, Color_5345c0& out);
};

struct RgbaColor {
    float r;
    float g;
    float b;
    float a;
};

struct FUN_00534780_Class {
    char* m_00;
    int m_04;
    unsigned char m_08;
    void FUN_00534780(int index, RgbaColor* out);
};

// @fnv 0x005345c0
void FUN_005345c0_shell::FUN_005345c0(unsigned int group, unsigned int index, Color_5345c0& out) {
    if (!reinterpret_cast<::FUN_0045cb90_cls *>(this)->FUN_0045cb90()) { out = DAT_011a9be0; return; }
    bool found = false;
    if (store->colors && store->colors[group]) {
        out = store->colors[group][index];
        found = true;
    } else if (store->nodes && store->nodes[group]) {
        Geometry_5345c0* geometry = ((::Geometry_5345c0 *)(reinterpret_cast<::NiNode *>((store->nodes[group]))->GetAt(0)));
        if (reinterpret_cast<::FUN_004a8030_shell *>((geometry))->FUN_004a8030()) {
            out = ((::Color_5345c0 *)(reinterpret_cast<::This_004a8050 *>((geometry))->GetNextProc()))[index];
            found = true;
        } else {
            Data_5345c0* data = ((::Data_5345c0 *)(::fnv_005495f0::FUN_005495f0((const char *)(geometry))));
            Buffer_5345c0 format;
            ::FUN_00534550((::PathingActorData *)&(format));
            Format_5345c0* buffer = ((::Format_5345c0 *)(::fnv_004a8a90::FUN_004a8a90((char *)(data))));
            if (buffer && buffer->HasColor() && reinterpret_cast<::NiGeometryData *>((data))->IsGeometryDataStreamable(1)) {
                reinterpret_cast<::FUN_00a67660_cls *>((data))->FUN_00a67660((::StreamOut_a676 *)(::Buffer_5345c0 *)(&format));
                reinterpret_cast<::FUN_00534780_Class *>(&(format))->FUN_00534780(index, (::RgbaColor *)&(out));
                reinterpret_cast<::FUN_00a673d0_shell *>((data))->FUN_00a673d0();
                found = true;
            }
        }
    }
    if (!found) out = DAT_011a9be0;
}

// @fnv 0x00534780
void FUN_00534780_Class::FUN_00534780(int index, RgbaColor* out)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(index);
    unsigned int* entry7 = (unsigned int*)(m_00 + index * m_04);
    if (m_08) {
        unsigned int* pX = entry7;
        unsigned char red = (unsigned char)((*pX >> 16) & 0xff);
        unsigned char aGreen = (unsigned char)((*pX >> 8) & 0xff);
        unsigned char blue = (unsigned char)(*pX & 0xff);
        unsigned char alpha2 = (unsigned char)((*pX >> 24) & 0xff);
        out->r = (int)red / 255.0;
        out->g = (int)aGreen / 255.0;
        out->b = (int)blue / 255.0;
        out->a = (int)alpha2 / 255.0;
    } else {
        RgbaColor* src = (RgbaColor*)entry7;
        *out = *src;
    }
}

extern int FNV_RTTI_TESObjectLAND;

extern "C" void* __cdecl FNV_DynamicCast(void*, int, const void*, const void*, int);

struct LandCopyData {
    void* nodes;
    NiPoint3_od** vertices;
    NiPoint3_od** normals;
    Elem16** colors;
    unsigned char** textureIndices;
    int unk14;
    int cellX;
    int cellY;
    int baseTextures[4];
    int* textureLayers[4];
    void** weights[4];
};

struct LandCopy : TESPackage {
    void* cell;
    int unk24;
    LandCopyData* data;
    void FUN_005348c0(TESForm_od* form);
};

struct CleanupMap {
    int unk00, unk04, unk08, unk0c;
};

struct RefCleanup {  };

struct CleanupData {
    int unk00;
    int** vertices;
    int** normals;
    int** colors;
    int** extra;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int* choices[4];
    int** weights[4];
    RefCleanup* reference;
    CleanupMap maps[4];
    ~CleanupData();
};

struct CleanupOwner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    CleanupData* data;
    bool FUN_00536d80();
};

struct Point { float x,y,z; Point(float,float,float); };

struct Range {float x,y;};

struct UpdateData {float time; bool a,b; int c; UpdateData(float,bool,bool);};

struct Shape;

struct GeomData { void FUN_00a67050(int);  };

struct Bound {};

struct Property { };

struct Model {};

struct Scene {
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
virtual void v28();
virtual void v2c();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3c();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4c();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5c();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6c();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7c();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8c();
virtual void v90();
virtual void v94();
virtual void v98();
virtual void v9c();
virtual void va0();
virtual void va4();
virtual void va8();
virtual void vac();
virtual void vb0();
virtual void vb4();
virtual void SetPosition(const NiPoint3_od&);
virtual void vbc();
virtual void vc0();
virtual void vc4();
virtual void vc8();
virtual void vcc();
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void vdc();
virtual void ve0();
virtual void ve4();
virtual void ve8();
virtual void vec();
virtual void vf0();
virtual void vf4();
virtual void Attach(int,Shape*);
  
 
 
};

struct Shape {    };

struct PropPointer {};

struct Renderer_od {virtual void v00();
virtual void v04();
virtual void v08();
virtual void v0c();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1c();
virtual void v20();
virtual void v24();
virtual void v28();
virtual void v2c();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3c();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4c();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5c();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6c();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7c();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8c();
virtual void v90();
virtual void v94();
virtual void v98();
virtual void v9c();
virtual void va0();
virtual void va4();
virtual void va8();
virtual void vac();
virtual void vb0();
virtual void vb4();
virtual void vb8();
virtual void vbc();
virtual void vc0();
virtual void vc4();
virtual void vc8();
virtual void vcc();
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void vdc();
virtual void ve0();
virtual void ve4();
virtual void ve8();
virtual void Render(Shape*,int,int,void*);
};

struct Cell {};

struct Mopp { };

struct Scratch {int a,b,c,d; Scratch();};

struct Other { };

struct Data {Scene** nodes; int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
int unk40;
int unk44;
int unk48;
int unk4c;
int unk50;
int unk54;
int unk58;
int unk5c;
int unk60;
int unk64;
int unk68;
int unk6c;
int unk70;
int unk74;
int unk78;
int unk7c;
int unk80;
int unk84;
int unk88;
int unk8c;
int unk90;
int unk94;
int unk98;
int unk9c; float scale;};

struct Land {int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c; Cell* cell; int unk24; Data* data;
 
  
 void FUN_0053aeb0(); 
  void FUN_005374f0();};

struct SceneObject {
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void Unknown34();
    virtual void Unknown35();
    virtual void Unknown36();
    virtual void Unknown37();
    virtual void Unknown38();
    virtual void Unknown39();
    virtual void Unknown40();
    virtual void Unknown41();
    virtual void Unknown42();
    virtual void Unknown43();
    virtual void Unknown44();
    virtual void Unknown45();
    virtual void Unknown46();
    virtual void Unknown47();
    virtual void Unknown48();
    virtual void Unknown49();
    virtual void Unknown50();
    virtual void Unknown51();
    virtual void Unknown52();
    virtual void Unknown53();
    virtual void Unknown54();
    virtual void Unknown55();
    virtual void Unknown56();
    virtual void Unknown57();
    virtual void InsertChild(SceneObject* child);
    virtual void Unknown59();
    virtual void SetState(int state);
};

struct ScenePointer {
    SceneObject* value;
    void FUN_0066b0d0(SceneObject* value);
};

struct QueuePointer {
    void* value;
};

struct SceneController {
};

struct SceneSource {
};

struct BoneTransformData {
    SceneObject** objects;
    int* states;
    void** buffers;
    int* counts;
    int unknown10;
    ScenePointer node;
    int unknown18;
    int unknown1c;
    int unknown20;
    int unknown24;
    int unknown28;
    int unknown2c;
    int unknown30;
    int unknown34;
    int unknown38;
    int unknown3c;
    int unknown40;
    int unknown44;
    int unknown48;
    int unknown4c;
    int unknown50;
    int unknown54;
    int unknown58;
    int unknown5c;
    int unknown60;
    int unknown64;
    int unknown68;
    int unknown6c;
    int unknown70;
    int unknown74;
    int unknown78;
    int unknown7c;
    int unknown80;
    int unknown84;
    int unknown88;
    int unknown8c;
    int unknown90;
    ScenePointer extraNode;
};

struct SceneCleanup {
    int unknown00;
    int unknown04;
    int unknown08;
    int unknown0c;
    int unknown10;
    int unknown14;
    int unknown18;
    int unknown1c;
    SceneSource* source;
    QueuePointer queued;
    BoneTransformData* data;
    void FUN_00537eb0();
};

// @fnv 0x00533260
FUN_00533260::~FUN_00533260()
{
    reinterpret_cast<::CleanupOwner *>(this)->FUN_00536d80();
    if (--::DAT_011c9f00 == 0) {
        delete g_landBuf0;
        delete g_landBuf1;
        delete g_landBuf2;
        delete g_landBuf3;
        delete g_landBuf4;
        for (int i = 0; i < 4; i++) {
            delete g_landBufArray[i];
        }
        g_landBuffersReady = false;
        (*reinterpret_cast<::LandNiPointer *>(&::g_011ca000)) = 0;
        delete (*reinterpret_cast<::LandSharedObject * *>(&::DAT_011c9f04));
        (*reinterpret_cast<::LandSharedObject * *>(&::DAT_011c9f04)) = 0;
        delete g_landShared1;
        g_landShared1 = 0;
    }
    reinterpret_cast<::TESForm_od *>(this)->ClearData();
}

// @fnv 0x005348c0
void LandCopy::FUN_005348c0(TESForm_od* form) {
    LandCopy* source = static_cast<LandCopy*>(FNV_DynamicCast(form, 0, &::DAT_01183028, &FNV_RTTI_TESObjectLAND, 0));
    if (source) {
        bool loaded = source->FUN_005394a0();
        if (!loaded)
            reinterpret_cast<::LandForm *>((source))->FUN_00535b90(0);
        cell = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((source))->FUN_007af430()));
        reinterpret_cast<::GeometryOwner *>(this)->FUN_00539500((::GeometryOwner *)(source));
        for (int i = 0; i < 4; ++i) {
            ::__memcpy(data->vertices[i], source->data->vertices[i], 0xd8c);
            ::__memcpy(data->normals[i], source->data->normals[i], 0xd8c);
            ::__memcpy(data->colors[i], source->data->colors[i], 0x1210);
            ::__memcpy(data->textureIndices[i], source->data->textureIndices[i], 0x121);
            ::__memcpy(data->weights[i][0], source->data->weights[i][0], 0x2420);
            ::__memcpy(data->textureLayers[i], source->data->textureLayers[i], 0x18);
            data->baseTextures[i] = source->data->baseTextures[i];
        }
        ::__memcpy(&flags, &source->flags, 4);
        ::__memcpy(&data->cellX, &source->data->cellX, 8);
        if (!loaded)
            reinterpret_cast<::CleanupOwner *>((source))->FUN_00536d80();
        reinterpret_cast<::FUN_005394c0_Class *>(this)->FUN_005394c0(true);
    }
}

// @fnv 0x00536d80
bool CleanupOwner::FUN_00536d80() {
    reinterpret_cast<::FUN_005394c0_Class *>(this)->FUN_005394c0(false);
    reinterpret_cast<::SceneCleanup *>(this)->FUN_00537eb0();
    if (data) {
        int** value = 0;
        void* position;
        unsigned int key;
        int quad;
        int entry;
        for (quad = 0; quad < 4; quad++) {
            if (data->weights[quad]) {
                delete *data->weights[quad];
                delete data->weights[quad];
                data->weights[quad] = 0;
            }
            if (data->choices[quad]) {
                delete data->choices[quad];
                data->choices[quad] = 0;
            }
            if (data->vertices) {
                delete data->vertices[quad];
                data->vertices[quad] = 0;
            }
            if (data->normals) {
                delete data->normals[quad];
                data->normals[quad] = 0;
            }
            if (data->colors) {
                delete data->colors[quad];
                data->colors[quad] = 0;
            }
            if (data->extra) {
                delete data->extra[quad];
                data->extra[quad] = 0;
            }
            if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(&(data->maps[quad]))->FUN_0084e3a0())) > 0) {
                position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(data->maps[quad]))->GetFirstPos();
                while (position) {
                    reinterpret_cast<::C6b7f20_Map *>(&(data->maps[quad]))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(key), (void **)&(value));
                    if (value) {
                        for (entry = 0; entry < 16; entry++) {
                            if (value[entry]) {
                                *value[entry] = 0;
                                delete value[entry];
                            }
                        }
                        delete value;
                    }
                }
            }
            reinterpret_cast<::FUN_00438af0_Class *>(&(data->maps[quad]))->FUN_00438af0();
        }
        delete data->extra;
        delete data->vertices;
        delete data->colors;
        delete data->normals;
        if (data->reference) {
            reinterpret_cast<::hkReferencedObjectC905 *>((data->reference))->FUN_00c905b0();
            data->reference = 0;
        }
    }
    delete data;
    data = 0;
    return true;
}

struct ShadowSceneNode {
};

// @fnv 0x00537eb0
void SceneCleanup::FUN_00537eb0()
{
    SceneController* controller;
    reinterpret_cast<::FUN_006f74f0_cls *>(&(queued))->FUN_006f74f0((::ObjA *)(void *)(0));
    if (!data)
        return;
    {
    int index;
    SceneObject* parent;
    if (data->objects) {
        controller = source ? ((::SceneController *)(reinterpret_cast<::FUN_004543c0_cls *>((source))->FUN_004543c0())) : 0;
        if (controller && reinterpret_cast<::_FUN_0052aa80_shell *>((void *)&(data->extraNode))->operator!=(0))
            reinterpret_cast<::This5380d0 *>((controller))->FUN_005380d0((::Param5380d0 *)(::SceneObject *)(((::SceneObject *)(::FUN_00559450((int *)&(data->extraNode))))));
        data->extraNode.FUN_0066b0d0(0);
        for (index = 0; index < 4; ++index) {
            if (data->objects[index]) {
                data->states[index] = 0;
                data->counts[index] = 0;
                void* buffer = data->buffers[index];
                ::FUN_00401030(buffer);
                data->buffers[index] = 0;
                ::FUN_00b5b1c0((::ShadowSceneNode *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0)), 0, (::NiAVObject *)(data->objects[index]));
                data->objects[index]->SetState(0);
            }
            data->objects[index] = 0;
        }
        {
        SceneObject** objects = data->objects;
        ::FUN_00401030(objects);
        }
        data->objects = 0;
    }
    if (((::SceneObject *)(::FUN_00559450((int *)&(data->node))))) {
        parent = ((::SceneObject *)(reinterpret_cast<::FUN_009611e0_shell *>((((::SceneObject *)(::FUN_00559450((int *)&(data->node))))))->FUN_009611e0()));
        if (parent)
            parent->InsertChild(((::SceneObject *)(::FUN_00559450((int *)&(data->node)))));
        data->node.FUN_0066b0d0(0);
    }
}
}

void* __cdecl FUN_0056d280(unsigned int size);

struct Buffer538c00

{

    unsigned int m00;

    unsigned int m04;



};

struct Output538c00

{

    virtual ~Output538c00();

    unsigned int m04;

    unsigned int m08;

    unsigned int m0c;

    unsigned int m10;

    unsigned int m14;

    unsigned int m18;

    unsigned int m1c;

    Buffer538c00 buffer;

    unsigned int m28;

    unsigned int m2c;

    Output538c00();
    static void* operator new(std::size_t bytes) { return FUN_0056d280(bytes); } static void operator delete(void*);

};

struct FUN_00538c00_Class

{

    char FUN_00538c00(const void* source, unsigned int size, Output538c00** result);

};

// @fnv 0x00538c00
char FUN_00538c00_Class::FUN_00538c00(
    const void* source, unsigned int size, Output538c00** result)
{
    unsigned char success = 0;
    if (source && size && result)
    {
        Output538c00* object = new Output538c00;
        *result = object;

        const char* remainingSize = static_cast<const char*>(source);
        unsigned int readPosition = size;
        unsigned int fixedHeaderSize = 0x10;
        if (readPosition > fixedHeaderSize)
        {
            ::__memcpy(&object->m10, remainingSize, fixedHeaderSize);
            readPosition = readPosition - fixedHeaderSize;
            remainingSize = remainingSize + fixedHeaderSize;
            if (readPosition > 0)
            {
                reinterpret_cast<::FUN_00540750_Class *>(&(object->buffer))->FUN_00540750(readPosition);
                void* bufferData = ((void *)(::FUN_00559450((int *)&(object->buffer))));
                ::__memcpy(bufferData, remainingSize, readPosition);
                success = 1;
            }
        }
        if (!success)
        {
            delete object;
            *result = 0;
        }
    }
    return success;
}

struct Mesh53;

struct Buffer53 {  };

struct Texture53Data {  };

struct Texture53 {   };

struct GeoData53 {    };

struct NiTimeController {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void slot19();
 virtual void slot20();
 virtual void slot21();
 virtual void slot22();
 virtual void slot23();
 virtual void slot24();
 virtual void slot25();
 virtual void slot26();
 virtual void slot27();
 virtual void slot28();
 virtual void slot29();
 virtual void slot30();
 virtual void slot31();
 virtual void slot32();
 virtual void slot33();
 virtual void slot34();
 virtual void slot35();
 virtual void slot36();
 virtual void slot37();
 virtual void slot38();
 virtual void SetGeometry(Mesh53*);
};

struct Mesh53 {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual Mesh53* AsMesh();
};

struct Update53 { float time; bool update; bool flags; int unk08;  };

struct Node53 {    };

struct Config53 {
 int enabled; int unk04; void** sources; int unk0c; int unk10; int unk14; int unk18; int unk1c;
 Texture53* primary[4]; Texture53** textures[4];
};

struct TES53 {  };

struct Worker53 {
 int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24;
 Config53* config;
 void FUN_0053fa40(char);  
 void FUN_0053a090(bool update, int unused);
};

// @fnv 0x0053a090
void Worker53::FUN_0053a090(bool update, int unused) {
 if (config->enabled) {
 for (int i=0; i<4; ++i) {
 Node53* node=((::Node53 *)(std::uintptr_t)(reinterpret_cast<::GuardedSubHolder *>(this)->FUN_00535af0(i)));
 if (node) {
 if (update) {
 Mesh53* mesh=((::Mesh53 *)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0)));
 Mesh53* object=mesh ? mesh->AsMesh() : 0;
 if(object) {
 unsigned short prop=reinterpret_cast<::FUN_00456650_shell *>((object))->FUN_00456650();
 void* shader=((void *)(reinterpret_cast<::FUN_0049ec60 *>((object))->GetNext()));
 reinterpret_cast<::Bound88 *>((((::Buffer53 *)(::GetSourceFilesFromForm((char *)(object))))))->ComputeBoundingSphere({}, {});
 reinterpret_cast<::NiGeometryData *>((((::GeoData53 *)(::fnv_005495f0::FUN_005495f0((const char *)(object))))))->SetDirtyFlags(15);
 NiTimeController* count=((::NiTimeController *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(3)));
 NiTimeController* vertices=(count == 0 ? false : (((int)(reinterpret_cast<::BGSTerrainManager *>((count))->GetMinLevel()))>=8 && ((int)(reinterpret_cast<::BGSTerrainManager *>((count))->GetMinLevel()))<=12)) ? count : 0;
 if(vertices) {
 void* dest=((void *)(std::uintptr_t)(reinterpret_cast<::ActorMover *>((((::GeoData53 *)(::fnv_005495f0::FUN_005495f0((const char *)(object))))))->GetCurrentMoveModeType()));
 ::__memcpy(dest,config->sources[i],0xd8c);
 reinterpret_cast<::fnv_00a66a60::GeometryDataA66A *>((((::GeoData53 *)(::fnv_005495f0::FUN_005495f0((const char *)(object))))))->FUN_00a66a60(0);
 vertices->SetGeometry(object);
 Texture53* texture=config->primary[i];
 if(texture && ((::Texture53Data *)(reinterpret_cast<::FUN_009611e0_shell *>((texture))->FUN_009611e0()))) reinterpret_cast<::TexSet_b68660 *>((vertices))->FUN_00b68660(0,(::TexSource_b68660 *)(void *)(reinterpret_cast<::S_00592cf0 *>((((::Texture53Data *)(reinterpret_cast<::FUN_009611e0_shell *>((texture))->FUN_009611e0()))))->FUN_00592cf0()));
 else reinterpret_cast<::TexSet_b68660 *>((vertices))->FUN_00b68660(0,(::TexSource_b68660 *)(void *)(reinterpret_cast<::S_00592cf0 *>((((::Texture53Data *)(reinterpret_cast<::FUN_009611e0_shell *>((((Texture53*)FUN_00535ae0())))->FUN_009611e0()))))->FUN_00592cf0()));
 for(int j=1;j<7;++j) {
 texture=config->textures[i][j-1];
 if(texture && ((::Texture53Data *)(reinterpret_cast<::FUN_009611e0_shell *>((texture))->FUN_009611e0()))) reinterpret_cast<::TexSet_b68660 *>((vertices))->FUN_00b68660(j,(::TexSource_b68660 *)(void *)(reinterpret_cast<::S_00592cf0 *>((((::Texture53Data *)(reinterpret_cast<::FUN_009611e0_shell *>((texture))->FUN_009611e0()))))->FUN_00592cf0()));
 else reinterpret_cast<::TexSet_b68660 *>((vertices))->FUN_00b68660(j,(::TexSource_b68660 *)(void *)(0));
 }
 reinterpret_cast<::LandscapeSpecularView *>((vertices))->FUN_00b66640(config->primary[i]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((config->primary[i]))->FUN_00541590())):0,
 config->textures[i][0]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((config->textures[i][0]))->FUN_00541590())):0,
 config->textures[i][1]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((config->textures[i][1]))->FUN_00541590())):0,
 config->textures[i][2]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((config->textures[i][2]))->FUN_00541590())):0,
 config->textures[i][3]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((config->textures[i][3]))->FUN_00541590())):0,
 config->textures[i][4]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((config->textures[i][4]))->FUN_00541590())):0,
 config->textures[i][5]?((unsigned char)(reinterpret_cast<::FUN_00541590_Class *>((config->textures[i][5]))->FUN_00541590())):0,0,0,0);
 reinterpret_cast<::FUN_00baa000_shell *>((vertices))->FUN_00baa000();
 }
 }
 }
 Update53 data; new ((void *)&(data)) ::NiUpdateData(0.0f,false,false);
 reinterpret_cast<::FUN_00a59c60_cls *>((node))->FUN_00a59c60((std::intptr_t)&(data));
 if(update) reinterpret_cast<::FUN_00a5a040_Class *>((node))->FUN_00a5a040();
 }
 }
 if(update) FUN_0053fa40(reinterpret_cast<::FUN_00528790_shell *>(((*reinterpret_cast<::TES53 * *>(&::g_TES))))->GetUnk60Byte());
 } else { reinterpret_cast<::GeometryOwner *>(this)->FUN_00539500((::GeometryOwner *)(0)); reinterpret_cast<::Land *>(this)->FUN_005374f0(); }
}

struct LayerOwner53a940 : Owner53ace0 {
    void FUN_0053a940();
};

struct ShiftTableData {
    int unk00[12];
    int* m_apiEntries[4];          // +0x30, each int[6]
    float** m_appfRows[4];         // +0x40, each float*[0x121] of float[6]
};

class ShiftTableOwner {
public:
    int unk00[10];
    ShiftTableData* m_pUserData;      // +0x28

    void FUN_0053abb0(unsigned char ucSlot, unsigned short usIndex);
};

// @fnv 0x0053a940
void LayerOwner53a940::FUN_0053a940()
{
    if (!tables)
        return;
    for (int quadrant = 0; quadrant < 4; quadrant++) {
        for (unsigned int layer = 0; layer < 6; layer++) {
            int entry = tables->choices[quadrant][layer];
            if (entry) {
                float average = FUN_0053ae30((unsigned char)quadrant, (unsigned short)layer);
                average /= 289.0;
                if (average < 0.0010000000474974513)
                    tables->choices[quadrant][layer] = 0;
            }
        }
        unsigned int count = 6;
        for (unsigned int slot = 0; slot < count; slot++) {
            while (!tables->choices[quadrant][slot] && slot < count) {
                reinterpret_cast<::ShiftTableOwner *>(this)->FUN_0053abb0((unsigned char)quadrant, (unsigned short)slot);
                count--;
            }
        }
        float* result = (float*)FUN_00401000((count + 1) * sizeof(float));
        FUN_00403d30(result, 0, (count + 1) * sizeof(float));
        for (int vertex = 0; vertex < 289; vertex++) {
            float sum = 0.0f;
            for (unsigned int index = 0; index < count; index++) {
                float weight = reinterpret_cast<::FUN_0053a830_cls *>(this)->FUN_0053a830((unsigned char)quadrant, (unsigned short)vertex, (unsigned short)index);
                result[index] += weight;
                sum += weight;
            }
            if (sum < 1.0)
                result[count] += 1.0f - sum;
        }
        int indexVal = -1;
        float maximum = result[count];
        for (unsigned int candidate = 0; candidate < count; candidate++) {
            if (result[candidate] > maximum) {
                maximum = result[candidate];
                indexVal = candidate;
            }
        }
        if (indexVal != -1)
            FUN_0053ace0((unsigned char)quadrant, (unsigned short)indexVal);
        FUN_00401030(result);
        result = 0;
    }
}

// @fnv 0x0053abb0
void ShiftTableOwner::FUN_0053abb0(unsigned char ucSlot, unsigned short usIndex)
{
    if (ucSlot < 4 && usIndex < 6 && m_pUserData) {
        int i = usIndex;
        while (i < 5) {
            m_pUserData->m_apiEntries[ucSlot][i] = m_pUserData->m_apiEntries[ucSlot][i + 1];
            i++;
        }
        m_pUserData->m_apiEntries[ucSlot][5] = 0;
        if (m_pUserData->m_appfRows[ucSlot]) {
            for (int j = 0; j < 0x121; j++) {
                int k = usIndex;
                while (k < 5) {
                    m_pUserData->m_appfRows[ucSlot][j][k] = m_pUserData->m_appfRows[ucSlot][j][k + 1];
                    k++;
                }
                m_pUserData->m_appfRows[ucSlot][j][5] = 0.0f;
            }
        }
    }
}

struct xPoint3 {
    float x, y, z;
    xPoint3();
    xPoint3(float qpqRa, float qsSDDgz, float fZ);
    xPoint3 operator+(const xPoint3& kOther) const;
};

struct xPoint2 {
    float x, y;
    xPoint2(float qpqRa, float qsSDDgz);
    xPoint2 operator-(const xPoint2& kOther) const;
};

struct xCoordData {
    float fX;
    float fY;
    float fCellX;
    float fCellY;
    int m_iGridPositionX;
    int m_iGridCoordinateY;
    int iCell;
    float fQuadX;
    float fQuadY;
    int iQuadX;
    int iQuadY;
    int iQuad;
    xPoint3 kPos;
    int iVertex;
    int aiVerts[3];
    bool bFlip;
    bool bUpper;
};

struct xLandData {
    int m_iWordAt00;
    int m_iWordAt04;
};

struct xLand {
    char _pad0[0x28];
    xLandData* m_pData;
    bool FUN_0053b550(xCoordData& kData, const xPoint3& kPos, bool bRecurse);
};

// @fnv 0x0053e210
bool Host53e210::FUN_0053e210(std::intptr_t a) {
    Tmp53e210 tmp;
    new ((void *)&(tmp)) ::FUN_0053a510();
    if (!reinterpret_cast<::xLand *>((this))->FUN_0053b550((*(::xCoordData *)(&tmp)), (*(const ::xPoint3 *)(a)), 0))
        return 0;
    return ((bool)(reinterpret_cast<::FUN_0053e260_Class *>((this))->FUN_0053e260(tmp.m18, tmp.m3C)));
}

// @fnv 0x0053a5e0
int FUN_0053a5e0_cls::FUN_0053a5e0(std::intptr_t arg) {
    LocalObj53a5e0 local;
    local.m54 = 0;
    new ((void *)&(local)) ::FUN_0053a510();
    if (reinterpret_cast<::xLand *>(this)->FUN_0053b550((*(::xCoordData *)(&local)), (*(const ::xPoint3 *)(arg)), 1)) {
        local.m54 = reinterpret_cast<::FUN_0053a630_Class *>(this)->FUN_0053a630(local.m18, local.m3c);
    }
    return local.m54;
}

// @fnv 0x0053b550
bool xLand::FUN_0053b550(xCoordData& kData, const xPoint3& kPos, bool bRecurse)
{
    float qpqRa = reinterpret_cast<::FUN_00533fd0_Class *>(this)->FUN_00533fd0() * 4096.0;
    float qsSDDgz = reinterpret_cast<::fnv_00534010::FUN_00534010_od *>(this)->GetY() * 4096.0;
    if (!m_pData || (!m_pData->m_iWordAt04 && !m_pData->m_iWordAt00))
        return false;
    if (kPos.x < qpqRa || (float)(qpqRa + 4096.0) < kPos.x || kPos.y < qsSDDgz || (float)(qsSDDgz + 4096.0) < kPos.y)
        return false;
    kData.fX = kPos.x - qpqRa;
    kData.fY = kPos.y - qsSDDgz;
    kData.m_iGridPositionX = (int)(kData.fX / 2048.0);
    if ((int)kData.fX % 2048 == 0 && (int)kData.fX)
        kData.m_iGridPositionX--;
    kData.m_iGridCoordinateY = (int)(kData.fY / 2048.0);
    if ((int)kData.fY % 2048 == 0 && (int)kData.fY)
        kData.m_iGridCoordinateY--;
    kData.iCell = kData.m_iGridCoordinateY * 2 + kData.m_iGridPositionX;
    float qSVM = kData.m_iGridPositionX * 16 * 128 + qpqRa;
    float qrEZrs = kData.m_iGridCoordinateY * 16 * 128 + qsSDDgz;
    kData.fCellX = kPos.x - qSVM;
    kData.fCellY = kPos.y - qrEZrs;
    xPoint3 qpTd;
    qpTd = xPoint3(reinterpret_cast<::FUN_00534050_Class *>(this)->FUN_00534050() + 2048.0, reinterpret_cast<::FUN_00534080_Class *>(this)->FUN_00534080() + 2048.0, 0.0f);
    kData.iQuadX = (int)(kData.fCellX / 128.0);
    if ((int)kData.fCellX % 128 == 0 && (int)kData.fCellX)
        kData.iQuadX--;
    kData.iQuadY = (int)(kData.fCellY / 128.0);
    if ((int)kData.fCellY % 128 == 0 && (int)kData.fCellY)
        kData.iQuadY--;
    float qdqWL = kData.iQuadX * 128 + qSVM;
    float qvyWyw = kData.iQuadY * 128 + qrEZrs;
    kData.fQuadX = kPos.x - qdqWL;
    kData.fQuadY = kPos.y - qvyWyw;
    kData.iQuad = kData.iCell;
    if ((kData.iQuadX + kData.iQuadY) % 2 == 0) {
        kData.bFlip = false;
        kData.aiVerts[1] = kData.iQuadY * 17 + kData.iQuadX;
        kData.aiVerts[2] = (kData.iQuadY + 1) * 17 + kData.iQuadX + 1;
        if (kData.fQuadX > kData.fQuadY) {
            kData.aiVerts[0] = kData.iQuadY * 17 + kData.iQuadX + 1;
            kData.bUpper = false;
        } else {
            kData.aiVerts[0] = (kData.iQuadY + 1) * 17 + kData.iQuadX;
            kData.bUpper = true;
        }
    } else {
        kData.bFlip = true;
        kData.aiVerts[1] = kData.iQuadY * 17 + kData.iQuadX + 1;
        kData.aiVerts[2] = (kData.iQuadY + 1) * 17 + kData.iQuadX;
        if (kData.fQuadX + kData.fQuadY > 128.0) {
            kData.aiVerts[0] = (kData.iQuadY + 1) * 17 + kData.iQuadX + 1;
            kData.bUpper = true;
        } else {
            kData.aiVerts[0] = kData.iQuadY * 17 + kData.iQuadX;
            kData.bUpper = false;
        }
    }
    if ((int)kPos.x % 128 == 0 && (int)kPos.y % 128 == 0) {
        kData.iVertex = ::FUN_00406d90(((int)kData.fCellY / 128) * 17 + (int)kData.fCellX / 128);
    } else {
        float qArxcFu = 0.0f;
        int qAhbO = 0;
        xPoint2 qxQHW(kPos.x, kPos.y);
        for (int qJDuOZ = 0; qJDuOZ < 3; qJDuOZ++) {
            xPoint3 qpia;
            reinterpret_cast<::LandObject *>(this)->FUN_00534240(kData.iCell, kData.aiVerts[qJDuOZ], (::LandPoint3 *)&(qpia));
            xPoint2 qZWI(qpTd.x + qpia.x, qpTd.y + qpia.y);
            xPoint2 qQGWBE = qZWI - qxQHW;
            float qkJsUdT = reinterpret_cast<::FUN_00589850_Class *>((void *)&(qQGWBE))->FUN_00589850();
            if (qJDuOZ == 0 || qkJsUdT < qArxcFu) {
                qArxcFu = qkJsUdT;
                qAhbO = qJDuOZ;
            }
        }
        kData.iVertex = kData.aiVerts[qAhbO];
    }
    xPoint3 qfTOqo;
    reinterpret_cast<::LandObject *>(this)->FUN_00534240(kData.iCell, kData.iVertex, (::LandPoint3 *)&(qfTOqo));
    kData.kPos = qpTd + qfTOqo;
    if (bRecurse) {
        bool bResult = FUN_0053b550(kData, kData.kPos, false);
        return bResult;
    }
    else
        return true;
}

struct Grass;

struct GrassNode {   };

struct TextureGrass {  };

struct Grass {
 virtual void v000();
 virtual void v004();
 virtual void v008();
 virtual void v00c();
 virtual void v010();
 virtual void v014();
 virtual void v018();
 virtual void v01c();
 virtual void v020();
 virtual void v024();
 virtual void v028();
 virtual void v02c();
 virtual void v030();
 virtual void v034();
 virtual void v038();
 virtual void v03c();
 virtual void v040();
 virtual void v044();
 virtual void v048();
 virtual void v04c();
 virtual void v050();
 virtual void v054();
 virtual void v058();
 virtual void v05c();
 virtual void v060();
 virtual void v064();
 virtual void v068();
 virtual void v06c();
 virtual void v070();
 virtual void v074();
 virtual void v078();
 virtual void v07c();
 virtual void v080();
 virtual void v084();
 virtual void v088();
 virtual void v08c();
 virtual void v090();
 virtual void v094();
 virtual void v098();
 virtual void v09c();
 virtual void v0a0();
 virtual void v0a4();
 virtual void v0a8();
 virtual void v0ac();
 virtual void v0b0();
 virtual void v0b4();
 virtual void v0b8();
 virtual void v0bc();
 virtual void v0c0();
 virtual void v0c4();
 virtual void v0c8();
 virtual void v0cc();
 virtual void v0d0();
 virtual void v0d4();
 virtual void v0d8();
 virtual void v0dc();
 virtual void v0e0();
 virtual void v0e4();
 virtual void v0e8();
 virtual void v0ec();
 virtual void v0f0();
 virtual void v0f4();
 virtual void v0f8();
 virtual void v0fc();
 virtual void v100();
 virtual void v104();
 virtual void v108();
 virtual void v10c();
 virtual void v110();
 virtual void v114();
 virtual void v118();
 virtual void v11c();
 virtual void v120();
 virtual void v124();
 virtual void v128();
 virtual void v12c();
 virtual void v130();
 virtual void v134();
 virtual void v138();
 virtual void v13c();
 virtual void v140();
 virtual void v144();
 virtual void v148();
 virtual void v14c();
 virtual void v150();
 virtual void v154();
 virtual void v158();
 virtual void v15c();
 virtual void v160();
 virtual void v164();
 virtual void v168();
 virtual void v16c();
 virtual void v170();
 virtual void v174();
 virtual void v178();
 virtual void v17c();
 virtual unsigned char v180();
 virtual void v184();
 virtual void v188();
 virtual void v18c();
 virtual void v190();
 virtual void v194();
 virtual void v198();
 virtual void v19c();
 virtual void v1a0();
 virtual void v1a4();
 virtual void v1a8();
 virtual void v1ac();
 virtual float v1b0();
 virtual void v1b4();
 virtual float v1b8();
 virtual void v1bc();
 virtual float v1c0();
 virtual void v1c4();
 virtual float v1c8();
 virtual void v1cc();
 virtual unsigned char v1d0();
 virtual void v1d4();
 virtual unsigned char v1d8();
 virtual void v1dc();
 virtual unsigned char v1e0();
  
};

struct Sample {
 const char* model; unsigned int id; float f08,f0c,f10,f14,f18;
 unsigned char b1c,b1d,b1e,b1f;
 float weights[9];
 Sample();
};

struct SampleMap { int u00,u04,u08,u0c;  };

struct TerrainData {
 int u00,u04,u08,u0c,u10,u14,u18,u1c;
 TextureGrass* base[4]; TextureGrass** layers[4]; float** weights[4];
 int u50; SampleMap maps[4];
};

struct SampleSetting {  };

struct IntSetting {  };

extern unsigned long DAT_011c9f6c;

class NiPoint3_od;

struct TerrainInput;

struct TerrainOwner {
 int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24; TerrainData* data;
 bool FUN_0053bc10();
public:
    bool ComputeTerrainNormalAndTangent(::TerrainInput *, ::NiPoint3_od *, ::NiPoint3_od *);
};

struct Pt53d8f0 {
    float x;
    float y;
    float z;
    Pt53d8f0();
};

struct Edges53d8f0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct LandData53d8f0 {
    int unk00;
    Pt53d8f0** normals;
    Pt53d8f0** vertices;
};

struct Land53d8f0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    LandData53d8f0* data;

    void FUN_0053d8f0(Edges53d8f0* edges, void* other);
};

struct NormalPoint {
 float x,y,z;
 NormalPoint operator-(const NormalPoint&) const;
 NormalPoint Cross(const NormalPoint&) const;
 NormalPoint& operator+=(const NormalPoint&);
};

struct NormalData {
 int unk00;
 NormalPoint** vertices;
 NormalPoint** normals;
 int unk0c;
 unsigned char** flags;
};

struct NormalLand : TESPackage {
 int unk20;
 int unk24;
 NormalData* data;
 void FUN_0053df30(void* region);
};

// @fnv 0x0053df30
void NormalLand::FUN_0053df30(void* region) {
 if (!FUN_005394a0()) return;
 for (int quad4=0; quad4<4; ++quad4) {
  int vertex;
  for (vertex=0; vertex<289; ++vertex) {
   if (!region || reinterpret_cast<::B3DA60Object *>(this)->FUN_0053da60((::B3DA60Rect *)(region), (void *)(&data->vertices[quad4][vertex]))) {
    data->normals[quad4][vertex] = (*reinterpret_cast<::NormalPoint *>((void *)&::NiPoint3_od::ZERO));
    data->flags[quad4][vertex] = 0;
   }
  }
  unsigned short* indices5 = (*reinterpret_cast<unsigned short * *>(&::g_landBuf0));
  for (unsigned short triangle9=0; triangle9<512; ++triangle9) {
   unsigned short first2 = *indices5; ++indices5;
   unsigned short second3 = *indices5; ++indices5;
   unsigned short third4 = *indices5; ++indices5;
   NormalPoint edge1 = data->vertices[quad4][second3] - data->vertices[quad4][first2];
   NormalPoint edge8 = data->vertices[quad4][third4] - data->vertices[quad4][second3];
   NormalPoint normal = edge1.Cross(edge8);
   ::FUN_00525340((float *)(::NormalPoint *)(&normal));
   if (!region || reinterpret_cast<::B3DA60Object *>(this)->FUN_0053da60((::B3DA60Rect *)(region), (void *)(&data->vertices[quad4][first2]))) reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NormalPoint &)(data->normals[quad4][first2]))->FUN_0063c8a0((void *)&(normal));
   if (!region || reinterpret_cast<::B3DA60Object *>(this)->FUN_0053da60((::B3DA60Rect *)(region), (void *)(&data->vertices[quad4][second3]))) reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NormalPoint &)(data->normals[quad4][second3]))->FUN_0063c8a0((void *)&(normal));
   if (!region || reinterpret_cast<::B3DA60Object *>(this)->FUN_0053da60((::B3DA60Rect *)(region), (void *)(&data->vertices[quad4][third4]))) reinterpret_cast<::FUN_0063c8a0_shell *>((void *)&(const ::NormalPoint &)(data->normals[quad4][third4]))->FUN_0063c8a0((void *)&(normal));
  }
  ::NormalizePoints((::NiPoint3 *)(data->normals[quad4]),289,12);
 }
}

struct LandVertex {
    float x;
    float y;
    float z;
    LandVertex();
};

struct LandCoord {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int cellIndex;
    float fracX;
    float fracY;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int vertex0;
    int vertex1;
    int vertex2;
    bool upperTriangle;
    bool swapAxes;
};

struct LandHeights {
    float z0;
    float z1;
    float z2;
};

struct LandStandIn {
    bool FUN_0053f1e0(LandCoord& coord, float& height);
};

// @fnv 0x0053f180
bool TESObjectLAND::FUN_0053f180(const LandscapeColorData& a, float& b)
{
    LandscapeColorData tmp;
    new ((void *)&(tmp)) ::FUN_0053a510();
    if (!reinterpret_cast<::xLand *>(this)->FUN_0053b550((::xCoordData &)(tmp), (const ::xPoint3 &)(a), 0)) {
        b = reinterpret_cast<::fnv_0053a550::DoorH_od *>(this)->FUN_0053a550();
        return 0;
    }
    return reinterpret_cast<::LandStandIn *>(this)->FUN_0053f1e0((::LandCoord &)(tmp), b);
}

// @fnv 0x0053f1e0
bool LandStandIn::FUN_0053f1e0(LandCoord& coord, float& height)
{
    LandVertex v0;
    LandVertex v1;
    LandVertex v2;
    reinterpret_cast<::LandObject *>(this)->FUN_00534240(coord.cellIndex, coord.vertex0, (::LandPoint3 *)(::LandVertex *)(&v0));
    reinterpret_cast<::LandObject *>(this)->FUN_00534240(coord.cellIndex, coord.vertex1, (::LandPoint3 *)(::LandVertex *)(&v1));
    reinterpret_cast<::LandObject *>(this)->FUN_00534240(coord.cellIndex, coord.vertex2, (::LandPoint3 *)(::LandVertex *)(&v2));
    LandHeights h;
    h.z0 = v0.z;
    h.z1 = v1.z;
    h.z2 = v2.z;
    float dx;
    float dy3;
    if (!coord.upperTriangle) {
        dx = (h.z0 - h.z1) / 128.0;
        dy3 = (h.z2 - h.z0) / 128.0;
        if (!coord.swapAxes)
            height = dx * coord.fracX + h.z1 + dy3 * coord.fracY;
        else
            height = dx * coord.fracY + h.z1 + dy3 * coord.fracX;
    } else {
        dx = (h.z1 - h.z0) / 128.0;
        dy3 = (h.z2 - h.z0) / 128.0;
        if (coord.swapAxes) {
            dx = (h.z0 - h.z2) / 128.0;
            dy3 = (h.z0 - h.z1) / 128.0;
            height = h.z0 - ((128.0f - coord.fracX) * dx + (128.0f - coord.fracY) * dy3) ;
        } else {
            dx = (h.z1 - h.z0) / 128.0;
            dy3 = (h.z2 - h.z0) / 128.0;
            height = dx * coord.fracX + h.z0 + dy3 * coord.fracY;
        }
    }
    return true;
}

struct LandData53f
{
    char pad00[0x18];
    NiPoint2 kHeight;
};

struct FUN_0053f440_shell
{
    char pad00[0x1c];
    unsigned int uiFlags;
    char pad20[8];
    LandData53f* pkData;

    NiPoint2 FUN_0053f440();
};

// @fnv 0x0053f440
NiPoint2 FUN_0053f440_shell::FUN_0053f440()
{
    if (!pkData)
        return NiPoint2(DAT_01016970, DAT_01015f5c);
    if (pkData->kHeight.x == ::_DAT_010231b0 || pkData->kHeight.y == ::DAT_010241b0)
    {
        if (uiFlags & 1)
        {
            for (int i = 0; i < 4; i++)
            {
                ::FUN_0053f390_v2 kQuadResult;
                NiPoint2 kQuad = (*(::NiPoint2 *)(reinterpret_cast<::FUN_0053f390_cls *>(this)->FUN_0053f390(&kQuadResult, i)));
                if (kQuad.x < pkData->kHeight.x)
                    pkData->kHeight.x = kQuad.x;
                if (kQuad.y > pkData->kHeight.y)
                    pkData->kHeight.y = kQuad.y;
            }
        }
        else
        {
            pkData->kHeight = NiPoint2(reinterpret_cast<::fnv_0053a550::DoorH_od *>(this)->FUN_0053a550(), reinterpret_cast<::fnv_0053a550::DoorH_od *>(this)->FUN_0053a550());
        }
    }
    return pkData->kHeight;
}

namespace fnv_0053f570 {
struct RgbaColor {
    float r, g, b, a;
    RgbaColor(float r, float g, float b, float a);
    RgbaColor operator+(const RgbaColor& other) const;
    RgbaColor operator*(float scalar) const;
};
RgbaColor __cdecl operator*(float scalar, const RgbaColor& value);



struct OwnerInterp : Owner {
  bool FUN_0053f570(const float* xy, RgbaColor* out);
};

// @fnv 0x0053f570
bool OwnerInterp::FUN_0053f570(const float* xy, RgbaColor* out)
{
    Buf50 data;
    new ((void *)&(data)) ::FUN_0053a510();
    if (!reinterpret_cast<::xLand *>(this)->FUN_0053b550((*(::xCoordData *)(&data)), (*(const ::xPoint3 *)(xy)), 0))
        return false;

    RgbaColor aVal(0.0f, 0.0f, 0.0f, 0.0f);
    RgbaColor b(0.0f, 0.0f, 0.0f, 0.0f);
    RgbaColor thirdColor(0.0f, 0.0f, 0.0f, 0.0f);
    float x3 = (float)(::FUN_004b1520(xy[0], ::DAT_0101e704) / ::DAT_0102e430);
    float y = (float)(::FUN_004b1520(xy[1], ::DAT_0101e704) / ::DAT_0102e430);
    reinterpret_cast<::FUN_005345c0_shell *>(this)->FUN_005345c0(data.m18, data.m40, (*(::Color_5345c0 *)(&aVal)));
    reinterpret_cast<::FUN_005345c0_shell *>(this)->FUN_005345c0(data.m18, data.m44, (*(::Color_5345c0 *)(&b)));
    reinterpret_cast<::FUN_005345c0_shell *>(this)->FUN_005345c0(data.m18, data.m48, (*(::Color_5345c0 *)(&thirdColor)));

    if (!(*(unsigned char*)&data.m4C) && !(*((unsigned char*)&data.m4C+1))) {
        *out = (((1.0f-x3)*b + x3*aVal) * (1.0f-y)) + y*thirdColor;
    }
    if (!(*(unsigned char*)&data.m4C) && (*((unsigned char*)&data.m4C+1))) {
        *out = (((1.0f-x3)*aVal + x3*thirdColor) * y) + (1.0f-y)*b;
    }
    if ((*(unsigned char*)&data.m4C) && !(*((unsigned char*)&data.m4C+1))) {
        *out = (((1.0f-x3)*aVal + x3*b) * (1.0f-y)) + y*thirdColor;
    }
    if ((*(unsigned char*)&data.m4C) && (*((unsigned char*)&data.m4C+1))) {
        *out = (((1.0f-x3)*thirdColor + x3*aVal) * y) + (1.0f-y)*b;
    }
    return true;
}
}

// namespace fnv_0053f570

namespace fnv_0053fa40 {
struct P53 { float x,y,z; P53(); P53(float,float,float); P53 operator+(const P53&) const; P53 operator-(const P53&) const; };
struct C53 { float r,g,b,a; C53(); C53(float,float,float,float); };
struct G53 {  };
struct U53 { float t; bool a,b; int c; U53(float,bool,bool); };
struct N53 {
virtual void v000();
virtual void v004();
virtual void v008();
virtual void v00c();
virtual void v010();
virtual void v014();
virtual void v018();
virtual void v01c();
virtual void v020();
virtual void v024();
virtual void v028();
virtual void v02c();
virtual void v030();
virtual void v034();
virtual void v038();
virtual void v03c();
virtual void v040();
virtual void v044();
virtual void v048();
virtual void v04c();
virtual void v050();
virtual void v054();
virtual void v058();
virtual void v05c();
virtual void v060();
virtual void v064();
virtual void v068();
virtual void v06c();
virtual void v070();
virtual void v074();
virtual void v078();
virtual void v07c();
virtual void v080();
virtual void v084();
virtual void v088();
virtual void v08c();
virtual void v090();
virtual void v094();
virtual void v098();
virtual void v09c();
virtual void v0a0();
virtual void v0a4();
virtual void v0a8();
virtual void v0ac();
virtual void v0b0();
virtual void v0b4();
virtual void v0b8();
virtual void v0bc();
virtual void v0c0();
virtual void v0c4();
virtual void v0c8();
virtual void v0cc();
virtual void v0d0();
virtual void v0d4();
virtual void v0d8();
virtual void Attach(N53*,bool);
virtual void v0e0();
virtual void v0e4();
virtual void Detach(N53*);
   
};
struct Ptr53 {  Ptr53& Assign(N53*); };
struct CellMesh53 {  };
struct DataMesh53 { int u00,u04,u08,u0c,u10; Ptr53 mesh; };
struct Alloc53 { };
struct Mesh53 : N53, Alloc53 {
int u04; int u08; int u0c; int u10; int u14; int u18; int u1c; int u20; int u24; int u28; int u2c; int u30; int u34; int u38; int u3c; int u40; int u44; int u48; int u4c; int u50; int u54; int u58; int u5c; int u60; int u64; int u68; int u6c; int u70; int u74; int u78; int u7c; int u80; int u84; int u88; int u8c; int u90; int u94; int u98; int u9c; int ua0; int ua4; int ua8; int uac; int ub0; int ub4; int ub8; int ubc; int uc0;Mesh53(unsigned short,P53*,C53*,void*,void*,void*,unsigned char*);
};
struct Tex53 : Alloc53 {
int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c; int u20; int u24; int u28; int u2c;Tex53();  void FUN_00a6a150(int,int);
};
struct Light53 : Alloc53 {
int u00; int u04; int u08; int u0c; int u10; int u14; int u18; int u1c; int u20; int u24; int u28; int u2c; int u30; int u34; int u38; int u3c; int u40; int u44; int u48; int u4c; int u50; int u54; int u58; int u5c; int u60; int u64; int u68; int u6c; int u70; int u74; int u78; int u7c;Light53(); 
};
struct HostMesh53_od {
 int u00,u04,u08,u0c,u10,u14,u18,u1c; CellMesh53* cell; int u24; DataMesh53* data;
    
 void FUN_0053fa40(bool);
};
// @fnv 0x0053fa40
void HostMesh53_od::FUN_0053fa40(bool show) {
 const int edge7=32;
 const int aCount=128;
 int index2=0;
 if(!reinterpret_cast<::FUN_0045cb90_cls *>(this)->FUN_0045cb90()) return;
 N53* root_=((::fnv_0053fa40::N53 *)(reinterpret_cast<::FUN_00545cb0_shell *>((cell))->FUN_00545cb0()));
 if(!root_) return;
 if(((::fnv_0053fa40::N53 *)(::FUN_00559450((int *)&(data->mesh))))) { root_->Detach(((::fnv_0053fa40::N53 *)(::FUN_00559450((int *)&(data->mesh))))); data->mesh.Assign(0); }
 if(!show) return;
 P53* vertices5=new P53[aCount];
 C53* colors3=new C53[aCount];
 unsigned char* flags=new unsigned char[aCount];
 P53 origin(reinterpret_cast<::FUN_00534050_Class *>(this)->FUN_00534050(),((float)(reinterpret_cast<::FUN_00534080_Class *>(this)->FUN_00534080())),0.0f);
 int row3,col2;
 for(row3=0;row3<33;row3++) {
 for(col2=0;col2<33;col2++) {
 if(row3==0 || col2==0 || row3==32 || col2==32) {
 if(col2==0) index2=row3;
 else if(row3==32) index2=32+col2;
 else if(col2==32) index2=64+(32-row3);
 else if(row3==0) index2=96+(32-col2);
 if(index2%2) colors3[index2]=C53(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0053fa40::G53 *>(&::g_011c9f20))))))/255.0,*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0053fa40::G53 *>(&::g_011c9f9c))))))/255.0,*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0053fa40::G53 *>(&::g_011c9fc8))))))/255.0,1.0f);
 else colors3[index2]=C53(*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0053fa40::G53 *>(&::g_011c9ff4))))))/255.0,*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0053fa40::G53 *>(&::g_011ca024))))))/255.0,*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::fnv_0053fa40::G53 *>(&::g_011c9fac))))))/255.0,1.0f);
 flags[index2]=1;
 P53 point4=origin+P53(row3*128.0,col2*128.0,0.0f);
 float height3;
 reinterpret_cast<::TESObjectLAND *>(this)->FUN_0053f180((const ::LandscapeColorData &)(point4),height3);
 point4.z=height3+5.0;
 vertices5[index2]=point4-origin;
 }
 }
 }
 data->mesh.Assign(new Mesh53(aCount,vertices5,colors3,0,0,0,flags));
 reinterpret_cast<::FUN_00440460_S *>((((::fnv_0053fa40::N53 *)(::FUN_00559450((int *)&(data->mesh))))))->FUN_00440460((const ::V3 *)&(origin));
 Tex53* tex4=new Tex53;
 reinterpret_cast<::Owner_b9713 *>((tex4))->FUN_00533f40((::ObjectBase *)(0));
 tex4->FUN_00a6a150(0,0);
 reinterpret_cast<::FUN_00439410_cls *>((((::fnv_0053fa40::N53 *)(::FUN_00559450((int *)&(data->mesh))))))->FUN_00439410((::ArgObject *)(tex4));
 Light53* light8=new Light53;
 reinterpret_cast<::LowProcess *>((light8))->SetPackageObjectType(33);
 reinterpret_cast<::FUN_00439410_cls *>((((::fnv_0053fa40::N53 *)(::FUN_00559450((int *)&(data->mesh))))))->FUN_00439410((::ArgObject *)(light8));
 ::BSShaderManager::UpdateObjectTypeRecurse((::NiAVObject *)(::fnv_0053fa40::N53 *)(((::fnv_0053fa40::N53 *)(::FUN_00559450((int *)&(data->mesh))))),0,0);
 root_->Attach(((::fnv_0053fa40::N53 *)(::FUN_00559450((int *)&(data->mesh)))),true);
 reinterpret_cast<::FUN_00a5a040_Class *>((((::fnv_0053fa40::N53 *)(::FUN_00559450((int *)&(data->mesh))))))->FUN_00a5a040();
 U53 update5(0.0f,false,false);
 reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_0053fa40::N53 *)(::FUN_00559450((int *)&(data->mesh))))))->FUN_00a59c60((std::intptr_t)&(update5));
}
}

// @fnv 0x00406d90
int __cdecl FUN_00406d90(float fValue)
{
    return fnv_FloatToInt(fValue);
}

namespace TESLandInit {

struct LandMemContext {
    int iOldContext;
    LandMemContext(int aiContext, bool abPush, const char* apFile, int aiLine);
    ~LandMemContext();
};

struct LandMemObject {
};

struct LandTexturePtr {
    void* pObject;
    LandTexturePtr(void* apObject);
    ~LandTexturePtr();
};

struct LandShaderSlot {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e(); virtual void v0f(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1a(); virtual void v1b(); virtual void v1c(); virtual void v1d();
    virtual void v1e(); virtual void v1f(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void FUN_vt90(int aiIndex, LandTexturePtr* apOut);
};

struct LandTexturing : LandMemObject {
    LandTexturing();
    char pad00[0x30];
    LandShaderSlot kShader;
    char pad34[0x6c];
};

struct LandShaderData {
    LandShaderData();
    char pad[0x18];
    void* pTexturing;
    char data[0x0c];
};

struct LandTextureData {
    LandTextureData(void* apTexture, int a2, int a3, int a4, int a5);
    char data[0x10];
};

struct LandProperty : LandMemObject {
    LandProperty();
    char data[0x30];
};

struct LandPropertyList {
};

struct LandPropertyHolder {
    void FUN_0066b0d0(LandProperty* apProperty);
};

struct LandShaderList {
};

struct LandShaderManager {
};

struct LandStringSetting {
};

struct LandFloatSetting {
};

struct LandColor {
    float r, g, b, a;
    LandColor();
    LandColor(float afR, float afG, float afB, float afA);
};

struct LandPoint3 {
    float x, y, z;
    LandPoint3();
    LandPoint3(float afX, float afY, float afZ);
};

struct LandPoint2 {
    float x, y;
    LandPoint2();
    LandPoint2(float afX, float afY);
};



static const char s_szSourceFile[] = "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESLand.cpp";
static const char s_szLandscapeFormat[] = "Landscape\\%s";
static const char s_szTilingWarning[] = "DEFAULT: INI setting fLandTextureTilingMult cannot be 0.";

// @fnv 0x00533420
void __cdecl FUN_00533420() {
    LandMemContext kMemContext(0x1b, true, s_szSourceFile, 0xc6);
    (*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1)) = new LandTexturing();
    char acPath[260];
    ::FUN_00406d00(acPath, 260, s_szLandscapeFormat, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::TESLandInit::LandStringSetting *>(&::g_011ca004))))->GetMenuTitle())));
    reinterpret_cast<::Holder00592cc0 *>(((*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1))))->SetFullNameByType(0, acPath);
    ::FUN_00406d00(acPath, 260, s_szLandscapeFormat, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::TESLandInit::LandStringSetting *>(&::g_011c9f8c))))->GetMenuTitle())));
    reinterpret_cast<::Holder00592cc0 *>(((*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1))))->SetFullNameByType(1, acPath);
    reinterpret_cast<::FUN_00510130_shell *>((((::TESLandInit::LandShaderList *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::TESLandInit::LandShaderManager * *>(&::g_dataHandler))))->FUN_00726070()))))->RemoveNode((::NiNode *)((*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1))));
    (*reinterpret_cast<::TESLandInit::LandShaderData * *>(&::DAT_011c9f04)) = new LandShaderData();
    (*reinterpret_cast<LandShaderData * *>(&::DAT_011c9f04))->pTexturing = (*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1));
    LandTexturePtr kTexture(0);
    (*reinterpret_cast<::TESLandInit::LandTexturing * *>(&::g_landShared1))->kShader.FUN_vt90(0, &kTexture);
    LandTextureData* pTextureDataValue = new LandTextureData(((void *)(::FUN_00559450((int *)&(kTexture)))), 0, 3, 5, 0);
    (*reinterpret_cast<::TESLandInit::LandPropertyHolder *>(&::g_011ca000)).FUN_0066b0d0(new LandProperty());
    reinterpret_cast<::NiObjectNET *>((((::TESLandInit::LandPropertyList *)(::FUN_00559450((int *)&((*reinterpret_cast<::TESLandInit::LandPropertyHolder *>(&::g_011ca000))))))))->FUN_00533fb0(2);
    reinterpret_cast<::Owner_b9713 *>((((::TESLandInit::LandPropertyList *)(::FUN_00559450((int *)&((*reinterpret_cast<::TESLandInit::LandPropertyHolder *>(&::g_011ca000))))))))->FUN_00533f40((::ObjectBase *)(pTextureDataValue));

    (*reinterpret_cast<unsigned short * *>(&::g_landBuf0)) = new unsigned short[0x600];
    int iIndex = 0;
    int iVal;
    int jPtr;
    for (iVal = 0; iVal < 16; iVal++) {
        for (jPtr = 0; jPtr < 16; jPtr++) {
            if ((iVal % 2) ^ (jPtr % 2)) {
                unsigned short m_usVertexId;
                m_usVertexId = (iVal + 1) * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = iVal * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = iVal * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = iVal * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = (iVal + 1) * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
                m_usVertexId = (iVal + 1) * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = m_usVertexId;
                iIndex++;
            } else {
                unsigned short usCorner;
                usCorner = (iVal + 1) * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = (iVal + 1) * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = iVal * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = iVal * 17 + jPtr;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = iVal * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
                usCorner = (iVal + 1) * 17 + jPtr + 1;
                (*reinterpret_cast<unsigned short * *>(&::g_landBuf0))[iIndex] = usCorner;
                iIndex++;
            }
        }
    }

    float fTiling = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::TESLandInit::LandFloatSetting *>(&::g_011c9f2c))))));
    if (fTiling == 0.0) {
        ::FUN_005b5e40();
        fTiling = 16.0f;
    }
    fTiling = 4.0 / fTiling;
    (*reinterpret_cast<::TESLandInit::LandColor * *>(&::g_landBuf1)) = new LandColor[0x121];
    (*reinterpret_cast<::TESLandInit::LandPoint3 * *>(&::g_landBuf2)) = new LandPoint3[0x121];
    (*reinterpret_cast<unsigned char * *>(&::g_landBuf4)) = new unsigned char[0x121];
    (*reinterpret_cast<::TESLandInit::LandPoint2 * *>(&::g_landBuf3)) = new LandPoint2[0x121];
    iIndex = 0;
    for (iVal = 0; iVal < 17; iVal++) {
        for (jPtr = 0; jPtr < 17; jPtr++) {
            (*reinterpret_cast<::TESLandInit::LandColor * *>(&::g_landBuf1))[iIndex] = LandColor(1.0f, 1.0f, 1.0f, 0.0f);
            (*reinterpret_cast<::TESLandInit::LandPoint3 * *>(&::g_landBuf2))[iIndex] = LandPoint3(0.0f, 0.0f, 1.0f);
            (*reinterpret_cast<unsigned char * *>(&::g_landBuf4))[iIndex] = 1;
            (*reinterpret_cast<::TESLandInit::LandPoint2 * *>(&::g_landBuf3))[iIndex] = LandPoint2(jPtr / fTiling, iVal / fTiling);
            iIndex++;
        }
    }
    int kLocal;
    for (kLocal = 0; kLocal < 4; kLocal++) {
        DAT_011c9ec4[kLocal] = (kLocal % 2) * 2048 - 2048;
        DAT_011c9eb4[kLocal] = (kLocal / 2) * 2048 - 2048;
    }
    for (kLocal = 0; kLocal < 4; kLocal++) {
        iIndex = 0;
        (*reinterpret_cast<TESLandInit::LandPoint3 * (*)[4]>(&::g_landBufArray))[kLocal] = new LandPoint3[0x121];
        for (iVal = 0; iVal < 17; iVal++) {
            for (jPtr = 0; jPtr < 17; jPtr++) {
                (*reinterpret_cast<TESLandInit::LandPoint3 * (*)[4]>(&::g_landBufArray))[kLocal][iIndex] = LandPoint3(jPtr * 128 + DAT_011c9ec4[kLocal], iVal * 128 + DAT_011c9eb4[kLocal], -2048.0f);
                iIndex++;
            }
        }
    }
    (*reinterpret_cast<unsigned char *>(&::g_landBuffersReady)) = 1;
}

}

struct Vec3_od {
    float x, y, z;
    Vec3_od();
    Vec3_od(float afX, float afY, float afZ);
    Vec3_od FUN_0053d280(float afDivisor);
};

// @fnv 0x0053b450
FNv53b450_Point* FNv53b450_Source::FUN_0053b450(FNv53b450_Point* output, unsigned char flags, unsigned short cellIndex, const int* x, const int* y) {
    FNv53b450_Point result;
    new ((void *)&(result)) ::Vec3_od();
    result.x = DAT_01017a3c;
    result.y = DAT_01017a3c;
    result.x = float(x ? *x : reinterpret_cast<::FUN_00533fd0_Class *>(this)->FUN_00533fd0()) * result.x;
    result.y = float(y ? *y : reinterpret_cast<::fnv_00534010::FUN_00534010_od *>(this)->GetY()) * result.y;
    result.x = float(((flags & 1) ? 2048 : 0)) + result.x;
    result.y = float(((flags & 2) ? 2048 : 0)) + result.y;
    result.x = float((cellIndex % 17) << 7) + result.x;
    result.y = float((cellIndex / 17) << 7) + result.y;
    result.z = 0.0f;
    *output = result;
    return output;
}

// @fnv 0x0053f390
FUN_0053f390_v2* FUN_0053f390_cls::FUN_0053f390(FUN_0053f390_v2* out, int n)
{
    FUN_0053f390_v3 tmp;
    FUN_0053f390_v2 best;
    new ((void *)&(best)) ::NiPoint2(DAT_01016970, DAT_01015f5c);
    new ((void *)&(tmp)) ::Vec3_od();
    if (n < 16) {
        for (int i = 0; i < 0x121; i++) {
            reinterpret_cast<::LandObject *>(this)->FUN_00534240(n, i, (::LandPoint3 *)(::FUN_0053f390_v3 *)(&tmp));
            if (tmp.z < best.x) {
                best.x = tmp.z;
            }
            if (tmp.z > best.y) {
                best.y = tmp.z;
            }
        }
    }
    *out = best;
    return out;
}

// @fnv 0x0053d2e0
bool Owner::FUN_0053d2e0(std::intptr_t a1, std::intptr_t a2, std::intptr_t a3)
{
    Buf50 buf;
    new ((void *)&(buf)) ::FUN_0053a510();
    if (!reinterpret_cast<::xLand *>(this)->FUN_0053b550((*(::xCoordData *)(&buf)), (*(const ::xPoint3 *)(a1)), 0))
        return false;
    return reinterpret_cast<::TerrainOwner *>(this)->ComputeTerrainNormalAndTangent((::TerrainInput *)(::Buf50 *)(&buf), (::NiPoint3_od *)(a2), (::NiPoint3_od *)(a3));
}

// @fnv 0x0053bc10
bool TerrainOwner::FUN_0053bc10() {
 if (!data) return false;
 float threshold2=*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SampleSetting *>(&::g_011c9f38))))));
 threshold2=threshold2 < 0.0 ? 0.0 : threshold2;
 threshold2=threshold2 > 1.0 ? 0.9 : threshold2;
 GrassNode* nodeBTmp=0; Grass* _activeProcess=0; float density5=0.0f; int count1=0; int _actors=0;
 int limitVal=*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSetting *>(&::g_011c9f74)))))); int indexValue4=0; int capacity8=16; float sumHigh_2=0.0f; Sample** samples4;
 DAT_011c9f6c=*((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::IntSetting *>(&::g_011c9fb8))))));
 if (DAT_011c9f6c!=1 && DAT_011c9f6c!=2 && DAT_011c9f6c!=4 && DAT_011c9f6c!=8) DAT_011c9f6c=2;
 for (int quad=0;quad<4;quad++) {
 count1=0;
 for (int x=DAT_011c9f6c;x<16;x+=2*DAT_011c9f6c) {
 for (int y=DAT_011c9f6c;y<16;y+=2*DAT_011c9f6c) {
 samples4=new Sample*[capacity8];
 FUN_00403d30(samples4,0,capacity8*4);
 indexValue4=y*17+x;
 if(data->base[quad]) {
 nodeBTmp=((::GrassNode *)(reinterpret_cast<::BGSCameraPath *>((data->base[quad]))->GetShotList())); _actors=0;
 while(nodeBTmp && count1<capacity8 && _actors<=limitVal) {
 _activeProcess=*((::Grass **)(new ((void *)(nodeBTmp)) ::Vec3_od()));
 if(_activeProcess) {
 _actors++;
 samples4[count1]=new Sample;
 FUN_00403d30(samples4[count1],0,0x44);
 samples4[count1]->model=reinterpret_cast<::FUN_0050a550_shell *>((_activeProcess))->FUN_0050a550();
 samples4[count1]->id=((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((_activeProcess))->FUN_0084e3a0()));
 samples4[count1]->f14=FUN_0053ca40();
 samples4[count1]->f18=_activeProcess->v1c8();
 samples4[count1]->f10=_activeProcess->v1c0();
 samples4[count1]->f08=_activeProcess->v1b0();
 samples4[count1]->f0c=_activeProcess->v1b8();
 samples4[count1]->b1c=_activeProcess->v1d0();
 samples4[count1]->b1e=_activeProcess->v1e0();
 samples4[count1]->b1d=_activeProcess->v1d8();
 density5=_activeProcess->v180()/100.0;
 samples4[count1]->weights[0]=reinterpret_cast<::FUN_0053a7a0_cls *>(this)->FUN_0053a7a0((unsigned char)quad,indexValue4-18)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[1]=reinterpret_cast<::FUN_0053a7a0_cls *>(this)->FUN_0053a7a0((unsigned char)quad,indexValue4-17)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[2]=reinterpret_cast<::FUN_0053a7a0_cls *>(this)->FUN_0053a7a0((unsigned char)quad,indexValue4-16)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[3]=reinterpret_cast<::FUN_0053a7a0_cls *>(this)->FUN_0053a7a0((unsigned char)quad,indexValue4-1)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[4]=reinterpret_cast<::FUN_0053a7a0_cls *>(this)->FUN_0053a7a0((unsigned char)quad,indexValue4)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[5]=reinterpret_cast<::FUN_0053a7a0_cls *>(this)->FUN_0053a7a0((unsigned char)quad,indexValue4+1)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[6]=reinterpret_cast<::FUN_0053a7a0_cls *>(this)->FUN_0053a7a0((unsigned char)quad,indexValue4+16)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[7]=reinterpret_cast<::FUN_0053a7a0_cls *>(this)->FUN_0053a7a0((unsigned char)quad,indexValue4+17)>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[8]=reinterpret_cast<::FUN_0053a7a0_cls *>(this)->FUN_0053a7a0((unsigned char)quad,indexValue4+18)>threshold2 ? density5 : 0.0f;
 sumHigh_2=0.0f;
 for(int a=0;a<9;a++) sumHigh_2=sumHigh_2+samples4[count1]->weights[a];
 if(sumHigh_2/9.0<threshold2) {
 for(int b=0;b<9;b++) samples4[count1]->weights[b]=0.0f;
 }
 count1++;
 }
 nodeBTmp=((::GrassNode *)(reinterpret_cast<::Callees *>((nodeBTmp))->FUN_00726070()));
 }
 }
 for(int layer=0;layer<6;layer++) {
 if(!data->layers[quad][layer]) { continue; } else {
 if(data->weights[quad] && (
data->weights[quad][indexValue4-18][layer]>0.1f ||
data->weights[quad][indexValue4-17][layer]>0.1f ||
data->weights[quad][indexValue4-16][layer]>0.1f ||
data->weights[quad][indexValue4-1][layer]>0.1f ||
data->weights[quad][indexValue4+0][layer]>0.1f ||
data->weights[quad][indexValue4+1][layer]>0.1f ||
data->weights[quad][indexValue4+16][layer]>0.1f ||
data->weights[quad][indexValue4+17][layer]>0.1f ||
data->weights[quad][indexValue4+18][layer]>0.1f)) {
 _actors=0; nodeBTmp=((::GrassNode *)(reinterpret_cast<::BGSCameraPath *>((data->layers[quad][layer]))->GetShotList()));
 while(nodeBTmp && count1<capacity8 && _actors<=limitVal) {
 _activeProcess=*((::Grass **)(new ((void *)(nodeBTmp)) ::Vec3_od()));
 if(_activeProcess) {
 samples4[count1]=new Sample;
 _actors++;
 FUN_00403d30(samples4[count1],0,0x44);
 FUN_00403d30(samples4[count1]->weights,0,0x24);
 samples4[count1]->model=reinterpret_cast<::FUN_0050a550_shell *>((_activeProcess))->FUN_0050a550();
 samples4[count1]->id=((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((_activeProcess))->FUN_0084e3a0()));
 samples4[count1]->f14=FUN_0053ca40();
 samples4[count1]->f18=_activeProcess->v1c8();
 samples4[count1]->f10=_activeProcess->v1c0();
 samples4[count1]->f08=_activeProcess->v1b0();
 samples4[count1]->f0c=_activeProcess->v1b8();
 samples4[count1]->b1c=_activeProcess->v1d0();
 samples4[count1]->b1e=_activeProcess->v1e0();
 samples4[count1]->b1d=_activeProcess->v1d8();
 density5=_activeProcess->v180()/100.0;
 samples4[count1]->weights[2]=data->weights[quad][indexValue4-16][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[1]=data->weights[quad][indexValue4-17][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[0]=data->weights[quad][indexValue4-18][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[5]=data->weights[quad][indexValue4+1][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[4]=data->weights[quad][indexValue4][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[3]=data->weights[quad][indexValue4-1][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[8]=data->weights[quad][indexValue4+18][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[7]=data->weights[quad][indexValue4+17][layer]>threshold2 ? density5 : 0.0f;
 samples4[count1]->weights[6]=data->weights[quad][indexValue4+16][layer]>threshold2 ? density5 : 0.0f;
 sumHigh_2=0.0f;
 for(int c=0;c<9;c++) sumHigh_2=sumHigh_2+samples4[count1]->weights[c];
 if(sumHigh_2/9.0<threshold2) {
 for(int d=0;d<9;d++) samples4[count1]->weights[d]=0.0f;
 }
 count1++;
 }
 nodeBTmp=((::GrassNode *)(reinterpret_cast<::Callees *>((nodeBTmp))->FUN_00726070()));
 }
 }
 }
 }
 if(samples4[0]) reinterpret_cast<::FUN_00844700_Class *>(&(data->maps[quad]))->FUN_00844700(indexValue4,(std::uintptr_t)(samples4));
 else delete[] samples4;
 count1=0;
 }
 }
 }
 return true;
}

struct CoordProcessor { int x, y, z;  };

struct Grid53 { int count; CoordProcessor** processors; Vec3_od** positions; int unknown0c; unsigned char** evaluated; };

struct FNV53WorkerProxy {   };

struct WorkerTable53 { FNV53WorkerProxy* southwest; FNV53WorkerProxy* northwest; FNV53WorkerProxy* southeast; FNV53WorkerProxy* northCount; FNV53WorkerProxy* east; FNV53WorkerProxy* west; FNV53WorkerProxy* upper; FNV53WorkerProxy* northeast; };

struct Region53_od { int m00,m04,m08,m0c,m10,m14,m18,m1c,m20,m24; Grid53* grid;   void FUN_0053e290(int,int,Vec3_od*,WorkerTable53*); };

// @fnv 0x0053d8f0
void Land53d8f0::FUN_0053d8f0(Edges53d8f0* edges, void* other)
{
    if (!reinterpret_cast<::TESPackage *>(this)->FUN_005394a0())
        return;
    Edges53d8f0 local;
    if (edges == 0) {
        edges = &local;
        reinterpret_cast<::This53 *>(this)->FUN_0053d330((::Obj53 **)(edges), 0, (unsigned char *)(0));
    }
    Pt53d8f0 pt3;
    int i;
    for (i = 0; i < 4; i++) {
        int j;
        for (j = 0; j < 0x121; j++) {
            if (j < 0x11 || j > 0x110 || j % 0x11 == 0 || (j + 1) % 0x11 == 0) {
                if (other == 0 || reinterpret_cast<::B3DA60Object *>(this)->FUN_0053da60((::B3DA60Rect *)(other), data->normals[i] + j)) {
                    reinterpret_cast<::Region53_od *>(this)->FUN_0053e290(i, j, (::Vec3_od *)(::Pt53d8f0 *)(data->vertices[i] + j), (::WorkerTable53 *)(edges));
                }
            }
        }
    }
    if (edges->unk08 && edges->unk04 && edges->unk00 && edges->unk1C && edges->unk18 && edges->unk14 && edges->unk10 && edges->unk0C)
        reinterpret_cast<::FUN_00534200_Class *>(this)->FUN_00534200(true);
}

// @fnv 0x0053e290
void Region53_od::FUN_0053e290(int row, int col, Vec3_od* result, WorkerTable53* workers) {
    if (grid->evaluated[row][col] != 0 || workers == 0)
        return;
    Vec3_od originStep;
    originStep = Vec3_od(reinterpret_cast<::FUN_00534050_Class *>(this)->FUN_00534050() + 2048.0, ((float)(reinterpret_cast<::FUN_00534080_Class *>(this)->FUN_00534080())) + 2048.0, 0.0f);
    Vec3_od coordOut = (*(::Vec3_od *)(reinterpret_cast<::Point3Offset *>(&(grid->processors[row][col]))->ProjectileLaunched((::NiPoint3 *)&(originStep), {})));
    bool northCount = false, lowerNeighborIn = false, westNeighborCur = false, eastNeighbor = false, higherData = false, isBottomRes = false, leftData = false, rightVal = false;
    Vec3_od axis;
    Vec3_od blend;
    float amount = 1.0f;
    blend = grid->positions[row][col];
    FNV53WorkerProxy* worker;
    if(row<2 && col<17) {


    higherData=true;


    worker=workers->upper;


    Vec3_od auxA;


    if (!worker || !reinterpret_cast<::Owner *>((worker))->FUN_0053d2e0((std::intptr_t)(&coordOut), (std::intptr_t)(&axis), (std::intptr_t)(&auxA))) {


      axis = Vec3_od(0.0f, 0.0f, 1.0f);


    }


    if (worker && reinterpret_cast<::Host53e210 *>((worker))->FUN_0053e210((std::intptr_t)(&coordOut))) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount = amount + 1.0;


    } else if(row>=2 && col>=0x110) {


    isBottomRes=true;


    worker=workers->northwest;


    Vec3_od auxB;


    if (!worker || !reinterpret_cast<::Owner *>((worker))->FUN_0053d2e0((std::intptr_t)(&coordOut), (std::intptr_t)(&axis), (std::intptr_t)(&auxB))) {


      axis = Vec3_od(0.0f, 0.0f, 1.0f);


    }


    if (worker && reinterpret_cast<::Host53e210 *>((worker))->FUN_0053e210((std::intptr_t)(&coordOut))) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount = amount + 1.0;


    }


    if((row%2)==0 && col%17==0) {


    leftData=true;


    worker=workers->northCount;


    Vec3_od auxC;


    if (!worker || !reinterpret_cast<::Owner *>((worker))->FUN_0053d2e0((std::intptr_t)(&coordOut), (std::intptr_t)(&axis), (std::intptr_t)(&auxC))) {


      axis = Vec3_od(0.0f, 0.0f, 1.0f);


    }


    if (worker && reinterpret_cast<::Host53e210 *>((worker))->FUN_0053e210((std::intptr_t)(&coordOut))) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount = amount + 1.0;


    } else if((row+1)%2==0 && (col+1)%17==0) {


    rightVal=true;


    worker=workers->east;


    Vec3_od auxD;


    if (!worker || !reinterpret_cast<::Owner *>((worker))->FUN_0053d2e0((std::intptr_t)(&coordOut), (std::intptr_t)(&axis), (std::intptr_t)(&auxD))) {


      axis = Vec3_od(0.0f, 0.0f, 1.0f);


    }


    if (worker && reinterpret_cast<::Host53e210 *>((worker))->FUN_0053e210((std::intptr_t)(&coordOut))) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount = amount + 1.0;


    }


    if(leftData && higherData) {


    


    worker=workers->west;


    Vec3_od auxE;


    if (!worker || !reinterpret_cast<::Owner *>((worker))->FUN_0053d2e0((std::intptr_t)(&coordOut), (std::intptr_t)(&axis), (std::intptr_t)(&auxE))) {


      axis = Vec3_od(0.0f, 0.0f, 1.0f);


    }


    if (worker && reinterpret_cast<::Host53e210 *>((worker))->FUN_0053e210((std::intptr_t)(&coordOut))) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount = amount + 1.0;


    } else if(rightVal && higherData) {


    


    worker=workers->northeast;


    Vec3_od auxF;


    if (!worker || !reinterpret_cast<::Owner *>((worker))->FUN_0053d2e0((std::intptr_t)(&coordOut), (std::intptr_t)(&axis), (std::intptr_t)(&auxF))) {


      axis = Vec3_od(0.0f, 0.0f, 1.0f);


    }


    if (worker && reinterpret_cast<::Host53e210 *>((worker))->FUN_0053e210((std::intptr_t)(&coordOut))) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount = amount + 1.0;


    } else if(leftData && isBottomRes) {


    


    worker=workers->southwest;


    Vec3_od auxG;


    if (!worker || !reinterpret_cast<::Owner *>((worker))->FUN_0053d2e0((std::intptr_t)(&coordOut), (std::intptr_t)(&axis), (std::intptr_t)(&auxG))) {


      axis = Vec3_od(0.0f, 0.0f, 1.0f);


    }


    if (worker && reinterpret_cast<::Host53e210 *>((worker))->FUN_0053e210((std::intptr_t)(&coordOut))) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount = amount + 1.0;


    } else if(rightVal && isBottomRes) {


    


    worker=workers->southeast;


    Vec3_od auxH;


    if (!worker || !reinterpret_cast<::Owner *>((worker))->FUN_0053d2e0((std::intptr_t)(&coordOut), (std::intptr_t)(&axis), (std::intptr_t)(&auxH))) {


      axis = Vec3_od(0.0f, 0.0f, 1.0f);


    }


    if (worker && reinterpret_cast<::Host53e210 *>((worker))->FUN_0053e210((std::intptr_t)(&coordOut))) {


      *result=axis; grid->evaluated[row][col]=1; return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount = amount + 1.0;


    }


    if(col<17 && !higherData) {


    northCount=true;


    axis = grid->positions[row-2][col+0x110];


    if(grid->evaluated[row-2][col+0x110]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount=amount+1.0;


    } else if(col>=0x110 && !isBottomRes) {


    lowerNeighborIn=true;


    axis = grid->positions[row+2][col-0x110];


    if(grid->evaluated[row+2][col-0x110]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount=amount+1.0;


    }


    if(col%17==0 && !leftData) {


    westNeighborCur=true;


    axis = grid->positions[row-1][col+16];


    if(grid->evaluated[row-1][col+16]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount=amount+1.0;


    } else if((col+1)%17==0 && !rightVal) {


    eastNeighbor=true;


    axis = grid->positions[row+1][col-16];


    if(grid->evaluated[row+1][col-16]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount=amount+1.0;


    }


    if(westNeighborCur && northCount) {


    


    axis = grid->positions[row-3][0x120];


    if(grid->evaluated[row-3][0x120]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount=amount+1.0;


    } else if(westNeighborCur && lowerNeighborIn) {


    


    axis = grid->positions[row+1][16];


    if(grid->evaluated[row+1][16]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount=amount+1.0;


    } else if(eastNeighbor && northCount) {


    


    axis = grid->positions[row-1][0x110];


    if(grid->evaluated[row-1][0x110]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount=amount+1.0;


    } else if(eastNeighbor && lowerNeighborIn) {


    


    axis = grid->positions[row+3][0];


    if(grid->evaluated[row+3][0]) {


       *result=axis;grid->evaluated[row][col]=1;return;


    }


    reinterpret_cast<::FUN_0063c8a0_shell *>(&(blend))->FUN_0063c8a0((void *)(&axis));


    amount=amount+1.0;


    }


    *result = blend.FUN_0053d280(amount);
    grid->evaluated[row][col] = 1;
}

struct NiP2 { float x, y; NiP2(); };

struct NiPoint3_ext { float x, y, z; NiPoint3_ext(); };

class NiFixedString {
public:
    const char* value;
    NiFixedString(const char*);
    ~NiFixedString();
};

struct Geometry5371 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    
    Geometry5371(unsigned short, NiPoint3_od*, NiPoint3_ext*, void*, NiP2*, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short*, unsigned short*);
};

struct MeshData5371 {
    void* unk00;
    NiPoint3_od** vertices;
    NiPoint3_ext** normals;
    NiP2** texcoords;
};

struct Land5371_od {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int unk14; int unk18; int unk1c; int unk20; int unk24;
    MeshData5371* data;
    Geometry5371* FUN_005371b0(unsigned char index);
};

// @fnv 0x00535b90
bool LandForm::FUN_00535b90(bool bFlag) {
    AutoMemContext memContext(0x1b, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESLand.cpp", 0x455);
    if (::Interface::IsGamePaused())
        bFlag = false;
    if (FUN_005394a0()) {
        if (unk28->unk00 == 0 && bFlag)
            reinterpret_cast<::Land *>(this)->FUN_005374f0();
        return true;
    }
    if (!reinterpret_cast<::FUN_00534140_Class *>(this)->FUN_00534140() && (!((flags & 1) || (flags & 2) || (flags & 4)) || !reinterpret_cast<::TESForm_od *>(this)->GetFile(-1))) {
        reinterpret_cast<::GeometryOwner *>(this)->FUN_00539500((::GeometryOwner *)(false));
        if (bFlag)
            reinterpret_cast<::Land *>(this)->FUN_005374f0();
        return true;
    }
    reinterpret_cast<::GeometryOwner *>(this)->FUN_00539500((::GeometryOwner *)(false));
    bool bResult2 = reinterpret_cast<::LandOwner535d *>(this)->FUN_00535d00();
    reinterpret_cast<::FUN_005394c0_Class *>(this)->FUN_005394c0(true);
    if (bFlag)
        reinterpret_cast<::Land *>(this)->FUN_005374f0();
    return bResult2;
}

// @fnv 0x005374f0
void Land::FUN_005374f0() {
if (!cell || !((::Scene *)(reinterpret_cast<::FUN_00545cb0_shell *>((cell))->FUN_00545cb0()))) return;
if (!data->nodes) {
 data->nodes = new Scene*[4];
 bool savedA[4]; FUN_00403d30(savedA,0,4);
 Shape* shapesB[4]; FUN_00403d30(shapesB,0,16);
 NiPoint2 total(DAT_01016970,DAT_01015f5c);
 for(int quad=0;quad<4;quad++) {
  data->nodes[quad]=((::Scene *)(std::uintptr_t)(reinterpret_cast<::GuardedSubHolder *>(this)->FUN_00535af0(quad)));
  if(data->nodes[quad]) {
   savedA[quad]=reinterpret_cast<::FUN_00456630_helper *>((data->nodes[quad]))->FUN_00456610();
   reinterpret_cast<::TaskQueueInterface *>((data->nodes[quad]))->QueueActorDisarm(true);
   reinterpret_cast<::FUN_00439410_cls *>((data->nodes[quad]))->FUN_00439410((::ArgObject *)(void *)(((void *)(::FUN_00559450((int *)&((*reinterpret_cast<::PropPointer *>(&::g_011ca000))))))));
   Shape* shape=((::Shape *)(reinterpret_cast<::Land5371_od *>(this)->FUN_005371b0((unsigned char)quad)));
   shapesB[quad]=shape;
   data->nodes[quad]->Attach(0,shape);
   unsigned short countB3=reinterpret_cast<::FUN_00456650_shell *>((shape))->FUN_00456650();
   void* vertices9=((void *)(reinterpret_cast<::FUN_0049ec60 *>((shape))->GetNext()));
   reinterpret_cast<::Bound88 *>((((::Bound *)(::GetSourceFilesFromForm((char *)(shape))))))->ComputeBoundingSphere(countB3,(const ::Vec88 *)(vertices9));
   reinterpret_cast<::NiGeometryData *>((((::GeomData *)(::fnv_005495f0::FUN_005495f0((const char *)(shape))))))->SetDirtyFlags(15);
   Scene* node6=data->nodes[quad];
   Scene* childIndex8=((::Scene *)(::fnv_0043b230::FUN_0043b230((const char *)(((::Model *)(reinterpret_cast<::BSFaceGenNiNode *>((node6))->GetAnimationData()))))));
   Range range4; reinterpret_cast<::FUN_0053f390_cls *>(this)->FUN_0053f390((::FUN_0053f390_v2 *)(::Range *)(&range4),quad);
   reinterpret_cast<::FUN_00439680_class *>((childIndex8))->FUN_00439680((const ::NiPoint3 &)((const ::Point &)(Point(DAT_010236e0,DAT_010236e0,(range4.y-range4.x)/2.0))));
   NiPoint3_od pos23=::NiPoint3_od::ZERO;
   pos23.x=reinterpret_cast<::FUN_00534050_Class *>(this)->FUN_00534050()+1024.0+(float)((quad%2)<<7<<4);
   pos23.y=reinterpret_cast<::FUN_00534080_Class *>(this)->FUN_00534080()+1024.0+(float)((quad/2)<<7<<4);
   pos23.z=(range4.x+range4.y)/2.0;
   childIndex8->SetPosition(pos23);
   if(total.x>range4.x) total.x=range4.x;
   if(total.y<range4.y) total.y=range4.y;
  }
 }
 Mopp* mopp2=((::Mopp *)(::GetCellMopp((char *)(cell))));
 reinterpret_cast<::FUN_00621e60 *>((mopp2))->Clear();
 Scratch scratch;
 scratch.c=data->unk50;
 reinterpret_cast<::xMgr *>((mopp2))->FUN_00621f60((::xRef **)(shapesB),4,data->scale);
 reinterpret_cast<::TerrainOwner *>(this)->FUN_0053bc10(); FUN_0053aeb0(); reinterpret_cast<::Host960 *>(this)->FUN_00539960();
 for(int index=0;index<4;index++) {
  if(shapesB[index]) {
   GeomData* geometryB=((::GeomData *)(::fnv_005495f0::FUN_005495f0((const char *)(shapesB[index]))));
   geometryB->FUN_00a67050(0x4000); reinterpret_cast<::NiGeometryData *>((geometryB))->SetCompressFlags(true);
   int flags5=17; flags5|=6; reinterpret_cast<::FUN_004410d0_Class *>((geometryB))->SetByteAtOffset38(flags5);
   Property* property3=((::Property *)(reinterpret_cast<::AlchemyItem *>((shapesB[index]))->FUN_004030b0()));
   Property* shader6=property3==0 ? 0 : ((((int)(std::intptr_t)(reinterpret_cast<::BSShaderNoLightingProperty *>((property3))->GetBaseTexture()))>=1 && ((int)(std::intptr_t)(reinterpret_cast<::BSShaderNoLightingProperty *>((property3))->GetBaseTexture()))<=5) ? property3 : 0);
   if(shader6) {
    Renderer_od* renderer=((::Renderer_od *)(::FUN_0043c4b0()));
    renderer->Render(shapesB[index],0,0,((void *)(::fnv_00537bd0::GetStringAtOffset((const char *)(shader6)))));
    reinterpret_cast<::Mgr_e74120 *>((renderer))->FUN_00e74120();
   }
  }
  if(data->nodes[index]) {
   reinterpret_cast<::TaskQueueInterface *>((data->nodes[index]))->QueueActorDisarm(savedA[index]);
   UpdateData update(0.0f,false,false);
   reinterpret_cast<::FUN_00a59c60_cls *>((data->nodes[index]))->FUN_00a59c60((std::intptr_t)&(update));
   reinterpret_cast<::FUN_00a5a040_Class *>((data->nodes[index]))->FUN_00a5a040();
  }
 }
}
if(data->nodes && ((::Other *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))) {
 bool hidden=false;
 hidden=reinterpret_cast<::FUN_00534140_Class *>(this)->FUN_00534140() && !reinterpret_cast<::FUN_00537b50_shell *>((((::Other *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))))->FUN_00537b50();
 for(int index2=0;index2<4;index2++)
  reinterpret_cast<::TaskQueueInterface *>((data->nodes[index2]))->QueueActorDisarm(hidden || reinterpret_cast<::FUN_00544590_cls *>((((::Other *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()))))->FUN_00544590(index2));
}
}

extern unsigned short DAT_0118ae90[];

// @fnv 0x005371b0
Geometry5371* Land5371_od::FUN_005371b0(unsigned char index)
{
    Geometry5371* p = 0;
    if (index < 4 && data != 0) {
        NiP2* a = new NiP2[289];
        ::__memcpy(a, (*reinterpret_cast<::NiP2 * *>(&::g_landBuf3)), 2312);
        unsigned short* f = (unsigned short*)FUN_00aa1070(2);
        unsigned short* s = (unsigned short*)FUN_00aa1070(2042);
        *f = 1021;
        ::__memcpy(s, DAT_0118ae90, 2042);
        NiPoint3_ext* eb = new NiPoint3_ext[289];
        ::__memcpy(eb, data->normals[index], 3468);
        p = new Geometry5371(289, data->vertices[index], eb,
                                 data->texcoords[index], a, 1, 0,
                                 *f - 2, 1, f, s);
        NiPoint3_od h;
        reinterpret_cast<::fnv_00535b30::FUN_00535b30_class_od *>(this)->FUN_00535b30((std::intptr_t)(&h));
        reinterpret_cast<::FUN_00440460_S *>((p))->FUN_00440460((const ::V3 *)&(h));
        char i[260];
        FUN_00406d00(i, 260, "Block (%i, %i)", index % 4, index / 4);
        ::AssignFixedString((char *)(p), (std::intptr_t)&(const ::NiFixedString &)(NiFixedString(i)), {});
    }
    return p;
}

class NiPoint3LD {
public:
    NiPoint3LD();
    float x;
    float y;
    float z;
};

struct LandDataLD {
    unsigned int unk00;
    unsigned int unk04;
    NiPoint3LD** m_apkNormals;
};

class LandLD_od {
public:
    bool FUN_0053db20();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    LandDataLD* m_pUserData;
};

// @fnv 0x00538110
void This538110::FUN_00538110()
{
    int i;
    int p0;
    bool wVal;
    BigBuf538110 B;
    int w_;
    if (!((FUN_00539460_Class*)this)->FUN_00539460() || (!(m_1c & 8) && !(m_28 && m_28->m_04 && m_28->m_08 && m_28->m_0c))) {
    } else {
    if (!((FUN_005341e0_Class*)this)->FUN_005341e0())
        reinterpret_cast<::LandLD_od *>((((FUN_0053db20_Class*)this)))->FUN_0053db20();
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_shell*)this)))->FUN_004855a0();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>((&m_1c))->FUN_00503210();
    ::AppendChunk(0x41544144, &m_1c, 4);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>((&m_1c))->FUN_00503210();
    if (m_1c & 1) {
        unsigned char v6[3267];
        int a1[1089];
        int base;
        int pX;
        int skip;
        int v2;
        for (i = 0; i < 4; i++) {
            base = ((i / 2) << 4) * 33 + ((i % 2) << 4);
            for (pX = 0; pX < 0x121; pX++) {
                v2 = (pX / 17) * 33 + base + (pX % 17);
                skip = 0;
                if (pX / 17 == 16) {
                    skip = 1;
                    if (i / 2 == 1)
                        skip = 0;
                }
                if (pX % 17 == 16) {
                    skip = 1;
                    if (i % 2 == 1)
                        skip = 0;
                }
                if (!skip) {
                    a1[v2] = ::FUN_00406d90(m_28->m_04[i][pX].z) >> 3;
                    reinterpret_cast<::FUN_004a0c10_s *>((((FUN_004a0c10_Class*)&m_28->m_08[i][pX])))->FUN_004a0c10();
                    v6[v2 * 3 + 0] = (unsigned char)(int)(m_28->m_08[i][pX].x * DAT_0102dfe0);
                    v6[v2 * 3 + 1] = (unsigned char)(int)(m_28->m_08[i][pX].y * DAT_0102dfe0);
                    v6[v2 * 3 + 2] = (unsigned char)(int)(m_28->m_08[i][pX].z * DAT_0102dfe0);
                }
            }
        }
        ::FUN_004856f0((void *)(0x4c4d4e56), v6, (void *)(0xcc3));
        B.m_00 = (float)a1[0];
        w_ = a1[0];
        wVal = 0;
        for (i = 0; i < 0x441; i++) {
            if (std::abs(a1[i] - w_) >= 0x80) {
                wVal = 1;
                if (a1[i] > w_)
                    B.m_04[i] = (char)0x7f;
                else
                    B.m_04[i] = (char)0x81;
            } else {
                B.m_04[i] = (char)(a1[i] - w_);
            }
            if ((i + 1) % 33 == 0) {
                w_ = a1[i - 32];
            } else if (!wVal) {
                w_ = a1[i];
            } else {
                w_ = (signed char)B.m_04[i] + w_;
            }
        }
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::fnv_00503210::Unk *>((&B))->FUN_00503210();
        ::AppendChunk(0x54474856, &B, 0x448);
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::fnv_00503210::Unk *>((&B))->FUN_00503210();
        if (wVal)
            ::FUN_005b5e40();
    }
    if (m_1c & 2) {
        unsigned char v3[3267];
        int w8;
        int v1;
        int idx2;
        for (i = 0; i < 4; i++) {
            w8 = ((i / 2) << 4) * 33 + ((i % 2) << 4);
            for (p0 = 0; p0 < 0x121; p0++) {
                idx2 = (p0 / 17) * 33 + w8 + (p0 % 17);
                v1 = 0;
                if (p0 / 17 == 16) {
                    v1 = 1;
                    if (i / 2 == 1)
                        v1 = 0;
                }
                if (p0 % 17 == 16) {
                    v1 = 1;
                    if (i % 2 == 1)
                        v1 = 0;
                }
                if (!v1) {
                    v3[idx2 * 3 + 0] = (unsigned char)(m_28->m_0c[i][p0].x * DAT_0101e568);
                    v3[idx2 * 3 + 1] = (unsigned char)(m_28->m_0c[i][p0].y * DAT_0101e568);
                    v3[idx2 * 3 + 2] = (unsigned char)(m_28->m_0c[i][p0].z * DAT_0101e568);
                }
            }
        }
        ::FUN_004856f0((void *)(0x524c4356), v3, (void *)(0xcc3));
    }
    if (m_1c & 4) {
        int w;
        reinterpret_cast<::LayerOwner53a940 *>((((FUN_0053a940_Class*)this)))->FUN_0053a940();
        for (w = 0; w < 4; w++) {
            if (m_28->m_20arr[w] != 0 && m_28->m_20arr[w] != (void*)FUN_00535ae0()) {
                X538110 v;
                v.m_04 = (unsigned char)w;
                v.m_06 = 0xffff;
                v.m_00 = ((FUN_0084e3a0_Class*)m_28->m_20arr[w])->FUN_0084e3a0();
                if (((bool)(::FUN_00401500())))
                    ((FUN_00535a60_Class*)&v)->FUN_00535a60();
                ::AppendChunk(0x54585442, &v, 8);
                if (((bool)(::FUN_00401500())))
                    ((FUN_00535a60_Class*)&v)->FUN_00535a60();
            }
            if (m_28->m_30arr[w] != 0) {
                int u3;
                int u6;
                std::intptr_t w1;
                u3 = 6;
                for (u6 = 0; u6 < u3; u6++) {
                    w1 = m_28->m_30arr[w][u6];
                    if (w1 != 0) {
                    {
                        X538110 pTmp;
                        pTmp.m_04 = (unsigned char)w;
                        pTmp.m_06 = (unsigned short)u6;
                        pTmp.m_00 = (w1 != FUN_00535ae0()) ? ((FUN_0084e3a0_Class*)w1)->FUN_0084e3a0() : 0;
                        if (((bool)(::FUN_00401500())))
                            ((FUN_00535a60_Class*)&pTmp)->FUN_00535a60();
                        ::AppendChunk(0x54585441, &pTmp, 8);
                        if (((bool)(::FUN_00401500())))
                            ((FUN_00535a60_Class*)&pTmp)->FUN_00535a60();
                    }
                    {
                        Entry538110 t7[289];
                        int v4;
                        int uA;
                        float v9;
                        unsigned int w7;
                        unsigned int v5;
                        v4 = 0;
                        for (uA = 0; uA < 0x121; uA++) {
                            if (m_28->m_40arr[w] != 0) {
                                v9 = reinterpret_cast<::FUN_0053a830_cls *>((((FUN_0053ae30_class*)this)))->FUN_0053a830((unsigned char)w, (unsigned short)uA, (unsigned short)u6);
                                if (v9 > ::_DAT_01012060) {
                                    t7[v4].m_04 = v9;
                                    t7[v4].m_00 = (unsigned short)uA;
                                    v4++;
                                }
                            }
                        }
                        if (v4 != 0) {
                            if (((bool)(::FUN_00401500()))) {
                                for (w7 = 0; w7 < (unsigned int)v4; w7++)
                                    ((FUN_00535aa0_Class*)&t7[w7])->FUN_00535aa0();
                            }
                            ::AppendChunk(0x54585456, t7, v4 * 8);
                            if (((bool)(::FUN_00401500()))) {
                                for (v5 = 0; v5 < (unsigned int)v4; v5++)
                                    ((FUN_00535aa0_Class*)&t7[v5])->FUN_00535aa0();
                            }
                        }
                    }
                    }
                }
            }
        }
    }
    reinterpret_cast<::Holder *>((((FUN_00485680_shell*)this)))->FUN_00485680();
    CompressSaveLoadRecord();
    }
}

// @fnv 0x0053db20
bool LandLD_od::FUN_0053db20()
{
    int i;
    if (!reinterpret_cast<::TESPackage *>(this)->FUN_005394a0() || reinterpret_cast<::FUN_00534140_Class *>(this)->FUN_00534140())
        return false;
    bool abChanged[8];
    FUN_00403d30(abChanged, 0, 8);
    LandLD_od* apkNeighbors[8];
    reinterpret_cast<::This53 *>(this)->FUN_0053d330((::Obj53 **)(apkNeighbors), 1, (unsigned char *)(abChanged));
    LandLD_od** ppkNeighbors = apkNeighbors;
    {
    NiPoint3LD akNormals[8][4][289];
    for (i = 0; i < 8; i++) {
        if (ppkNeighbors[i]) {
            for (int j = 0; j < 4; j++)
                ::__memcpy(akNormals[i][j], ((::NiPoint3LD **)(reinterpret_cast<::FUN_0053df00_Class *>((ppkNeighbors[i]))->FUN_0053df00()))[j], 0xd8c);
            reinterpret_cast<::NormalLand *>((ppkNeighbors[i]))->FUN_0053df30((void *)(0));
        }
    }
    reinterpret_cast<::NormalLand *>(this)->FUN_0053df30((void *)(0));
    reinterpret_cast<::Land53d8f0 *>(this)->FUN_0053d8f0((::Edges53d8f0 *)(apkNeighbors), (void *)(0));
    for (i = 0; i < 4; i++) {
        for (int k = 0; k < 289; k++) {
            reinterpret_cast<::FUN_004a0c10_s *>(&(m_pUserData->m_apkNormals[i][k]))->FUN_004a0c10();
            char cX = (char)(m_pUserData->m_apkNormals[i][k].x * 127.0);
            char cY = (char)(m_pUserData->m_apkNormals[i][k].y * 127.0);
            char cZ = (char)(m_pUserData->m_apkNormals[i][k].z * 127.0);
            m_pUserData->m_apkNormals[i][k].x = cX / 127.0f;
            m_pUserData->m_apkNormals[i][k].y = cY / 127.0f;
            m_pUserData->m_apkNormals[i][k].z = cZ / 127.0f;
            reinterpret_cast<::FUN_004a0c10_s *>(&(m_pUserData->m_apkNormals[i][k]))->FUN_004a0c10();
        }
    }
    for (i = 0; i < 8; i++) {
        if (ppkNeighbors[i]) {
            for (int j = 0; j < 4; j++)
                ::__memcpy(((::NiPoint3LD **)(reinterpret_cast<::FUN_0053df00_Class *>((ppkNeighbors[i]))->FUN_0053df00()))[j], akNormals[i][j], 0xd8c);
            if (abChanged[i])
                reinterpret_cast<::CleanupOwner *>((ppkNeighbors[i]))->FUN_00536d80();
        }
    }
    }
    return true;
}

class TESLandTexture {
public:
    virtual void v00();
};

class TESTexture : public TESLandTexture {
public:
};

// @fnv 0x0053aeb0
void Land::FUN_0053aeb0()
{
    for (int quadB = 0; quadB < 4; quadB++) {
        TESLandTexture* baseForm3 =
            (TESLandTexture*)((FUN_0053a5a0_Outer*)this)->FUN_0053a5a0(quadB);
        TESTexture* base5 = dynamic_cast<TESTexture*>(baseForm3);
        float sums_[289];
        memset(sums_, 0, sizeof(sums_));

        for (int a = 0; a < 6; a++) {
            TESLandTexture* texAB =
                (TESLandTexture*)((FUN_0053a700_Holder*)this)->FUN_0053a700(quadB, a);
            TESTexture* kFormA = dynamic_cast<TESTexture*>(texAB);

            if (kFormA != 0) {
                for (int b2 = 0; b2 < 6; b2++) {
                    if (a != b2) {
                        TESLandTexture* texB =
                            (TESLandTexture*)((FUN_0053a700_Holder*)this)->FUN_0053a700(quadB, b2);
                        TESTexture* formB = dynamic_cast<TESTexture*>(texB);

                        if (formB != 0 && !reinterpret_cast<::fnv_0048e4f0::FUN_0048e4f0_shell *>((kFormA))->FUN_0048e4f0((::BaseFormComponent *)(formB))) {
                            for (int k = 0; k < 289; k++) {
                                ((ShiftTableData*)data)->m_appfRows[quadB][k][a] +=
                                    ((ShiftTableData*)data)->m_appfRows[quadB][k][b2];
                                ((ShiftTableData*)data)->m_appfRows[quadB][k][b2] = 0.0f;
                            }
                            ((FUN_0053a760_Class*)this)->FUN_0053a760(quadB, b2, 0);
                        }
                    }
                }

                if (base5 != 0 && !reinterpret_cast<::fnv_0048e4f0::FUN_0048e4f0_shell *>((kFormA))->FUN_0048e4f0((::BaseFormComponent *)(base5))) {
                    for (int k = 0; k < 289; k++) {
                        ((ShiftTableData*)data)->m_appfRows[quadB][k][a] = 0.0f;
                    }
                    ((FUN_0053a760_Class*)this)->FUN_0053a760(quadB, a, 0);
                }
            }

            for (int k = 0; k < 289; k++) {
                sums_[k] += ((ShiftTableData*)data)->m_appfRows[quadB][k][a];
            }
        }

        unsigned int count = 6;
        for (unsigned int j6 = 0; j6 < count; j6++) {
            while (((ShiftTableData*)data)->m_apiEntries[quadB][j6] == 0 && j6 < count) {
                ((ShiftTableOwner*)this)->FUN_0053abb0(quadB, j6);
                count--;
            }
        }

        for (int k = 0; k < 289; k++) {
            float total3 = 0.0f;
            for (unsigned int n = 6; n > 0; n--) {
                ((ShiftTableData*)data)->m_appfRows[quadB][k][n] =
                    ((ShiftTableData*)data)->m_appfRows[quadB][k][n - 1];
                total3 += ((ShiftTableData*)data)->m_appfRows[quadB][k][n];
            }

            ((ShiftTableData*)data)->m_appfRows[quadB][k][0] =
                ::FUN_0040ebd0(1.0f, ::FUN_00404010(0.0f, 1.0f - total3));

            if (sums_[k] > ::g_01012070) {
                for (unsigned int n = 6; n > 0; n--) {
                    ((ShiftTableData*)data)->m_appfRows[quadB][k][n] =
                        ((ShiftTableData*)data)->m_appfRows[quadB][k][n] / total3;
                }
            }
        }
    }
}

int _FNV_GetFormType(TESForm_od*);

struct RefPersistsH {  };

struct CellS {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v0a(); virtual void v0b();
    virtual void v0c(); virtual void v0d(); virtual void v0e();
    virtual bool CopyTopicData(void* apForm);
};

struct ChildCellS { virtual CellS* GetSaveParentCell(); };

struct LandS {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    ChildCellS child;
    bool FUN_00539060(TESForm_od* apGroupFORM);
};

// @fnv 0x00539060
bool LandS::FUN_00539060(TESForm_od* apGroupFORM)
{
    bool bretval = false;
    if (::FUN_005548a0(_FNV_GetFormType(apGroupFORM)))
    {
        ChildCellS* pchild = (ChildCellS*)FNV_DynamicCast(apGroupFORM, 0, &::DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_0118ac2c)), 0);
        CellS* pcell = pchild->GetSaveParentCell();
        if (pcell == child.GetSaveParentCell())
        {
            switch (_FNV_GetFormType(apGroupFORM))
            {
            case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: case 0x40: case 0x69:
                {
                    RefPersistsH* pref = (RefPersistsH*)FNV_DynamicCast(apGroupFORM, 0, &::DAT_01183028, &(*reinterpret_cast<int *>(&::DAT_011841cc)), 0);
                    if (pref && !reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((pref))->FUN_005653d0())
                        bretval = true;
                    else
                        bretval = false;
                }
                break;
            case 0x43:
                bretval = true;
                break;
            }
        }
        else
        {
            bretval = child.GetSaveParentCell()->CopyTopicData(pcell);
        }
    }
    else
    {
        bretval = child.GetSaveParentCell()->CopyTopicData(apGroupFORM);
    }
    return bretval;
}

struct FUN_00534080_Class_od_ctx {
    double FUN_00534080();
};

struct DoorH {  };

struct FUN_005340b0_Class_od_ctx {
    int m_auiShapeKeys[8];
    DoorH* m_pDoor;
    TESWorldSpace* FUN_005340b0();
};

struct NiPoint3_od_ctx { float x; float y; float z; public:
    ::NiPoint3_od_ctx Cross(const ::NiPoint3_od_ctx &) const;
public:
    static const ::NiPoint3_od_ctx ZERO;
};

struct TESForm_od_ctx {  public:
    void ClearData();
public:
    ::TESFile *GetFile(int);
};

struct FUN_00534570_shell_od_ctx { char* m_pkDeltas; unsigned int stride; void FUN_00534570(unsigned int index, NiPoint3_od_ctx& vertex); };

struct BGSQuestObjective_od_ctx {  };

struct FUN_00538e30_class_od_ctx {
};

struct FUN_00538f80_od_ctx {
    void* DeleteThis(unsigned int flags);
};

float FUN_0053ca40();

struct BGSTextureSet_od_ctx {
};

struct FUN_00537d60_od_ctx : A51BF0Base {
    char _pad[0x18];
    int _m18;
    int _m1c;
    FUN_00537e30_cls* FUN_00537e30();
    FUN_00537d60_od_ctx();
};

int __cdecl FUN_00ec7d40(int v);

struct Data538110_od_ctx {
    void* m_00;
    NiPoint3_od_ctx** m_04;
    NiPoint3_od_ctx** m_08;
    Elem16** m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void* m_20arr[4];
    int* m_30arr[4];
    int m_40arr[4];
};

struct This538110_od_ctx {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    Data538110_od_ctx* m_28;
    void FUN_00538110();
};

struct FNv53b450_Point_od_ctx {
    float x;
    float y;
    float z;
    void FUN_006815c0();
};

struct FNv53b450_Source_od_ctx {
    FNv53b450_Point_od_ctx* FUN_0053b450(FNv53b450_Point_od_ctx* output, unsigned char flags, unsigned short cellIndex, const int* x, const int* y);
};

struct FUN_00461c20_Holder_od_ctx {
};

struct FUN_0053f390_v3_od_ctx {
    float x;
    float y;
    float z;
    void FUN_006815c0();
};

struct VertLock_od_ctx : FUN_00534570_shell_od_ctx {
    int unk08;
    VertLock_od_ctx();
};

struct LandCopyData_od_ctx {
    void* nodes;
    NiPoint3_od_ctx** vertices;
    NiPoint3_od_ctx** normals;
    Elem16** colors;
    unsigned char** textureIndices;
    int unk14;
    int cellX;
    int cellY;
    int baseTextures[4];
    int* textureLayers[4];
    void** weights[4];
};

struct LandCopy_od_ctx : TESPackage {
    void* cell;
    int unk24;
    LandCopyData_od_ctx* data;
    void FUN_005348c0(TESForm_od_ctx* form);
};

struct Scene_od_ctx {
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
virtual void v28();
virtual void v2c();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3c();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4c();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5c();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6c();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7c();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8c();
virtual void v90();
virtual void v94();
virtual void v98();
virtual void v9c();
virtual void va0();
virtual void va4();
virtual void va8();
virtual void vac();
virtual void vb0();
virtual void vb4();
virtual void SetPosition(const NiPoint3_od_ctx&);
virtual void vbc();
virtual void vc0();
virtual void vc4();
virtual void vc8();
virtual void vcc();
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void vdc();
virtual void ve0();
virtual void ve4();
virtual void ve8();
virtual void vec();
virtual void vf0();
virtual void vf4();
virtual void Attach(int,Shape*);
  
 
 
};

struct Renderer_od_ctx {virtual void v00();
virtual void v04();
virtual void v08();
virtual void v0c();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1c();
virtual void v20();
virtual void v24();
virtual void v28();
virtual void v2c();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3c();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4c();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5c();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6c();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7c();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8c();
virtual void v90();
virtual void v94();
virtual void v98();
virtual void v9c();
virtual void va0();
virtual void va4();
virtual void va8();
virtual void vac();
virtual void vb0();
virtual void vb4();
virtual void vb8();
virtual void vbc();
virtual void vc0();
virtual void vc4();
virtual void vc8();
virtual void vcc();
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void vdc();
virtual void ve0();
virtual void ve4();
virtual void ve8();
virtual void Render(Shape*,int,int,void*);
};

struct Data_od_ctx {Scene_od_ctx** nodes; int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
int unk40;
int unk44;
int unk48;
int unk4c;
int unk50;
int unk54;
int unk58;
int unk5c;
int unk60;
int unk64;
int unk68;
int unk6c;
int unk70;
int unk74;
int unk78;
int unk7c;
int unk80;
int unk84;
int unk88;
int unk8c;
int unk90;
int unk94;
int unk98;
int unk9c; float scale;};

struct Land_od_ctx {int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c; Cell* cell; int unk24; Data_od_ctx* data;
 
  
 void FUN_0053aeb0(); 
  void FUN_005374f0();};

struct Worker53_od_ctx {
 int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24;
 Config53* config;
   
 void FUN_0053a090(bool update, int unused);
};

class NiPoint3_od_ctx;

struct TerrainOwner_od_ctx {
 int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24; TerrainData* data;
 bool FUN_0053bc10();
public:
    bool ComputeTerrainNormalAndTangent(::TerrainInput *, ::NiPoint3_od_ctx *, ::NiPoint3_od_ctx *);
};

struct NormalPoint_od_ctx {
 float x,y,z;
 NormalPoint_od_ctx operator-(const NormalPoint_od_ctx&) const;
 NormalPoint_od_ctx& operator+=(const NormalPoint_od_ctx&);
};

struct NormalData_od_ctx {
 int unk00;
 NormalPoint_od_ctx** vertices;
 NormalPoint_od_ctx** normals;
 int unk0c;
 unsigned char** flags;
};

struct NormalLand_od_ctx : TESPackage {
 int unk20;
 int unk24;
 NormalData_od_ctx* data;
 void FUN_0053df30(void* region);
};

struct Vec3_od_ctx {
    float x, y, z;
    Vec3_od_ctx();
    Vec3_od_ctx(float afX, float afY, float afZ);
};

struct Grid53_od_ctx { int count; CoordProcessor** processors; Vec3_od_ctx** positions; int unknown0c; unsigned char** evaluated; };

struct Region53_od_ctx { int m00,m04,m08,m0c,m10,m14,m18,m1c,m20,m24; Grid53_od_ctx* grid;   void FUN_0053e290(int,int,Vec3_od_ctx*,WorkerTable53*); };

struct Geometry5371_od_ctx {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    
    Geometry5371_od_ctx(unsigned short, NiPoint3_od_ctx*, NiPoint3_ext*, void*, NiP2*, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short*, unsigned short*);
};

struct MeshData5371_od_ctx {
    void* unk00;
    NiPoint3_od_ctx** vertices;
    NiPoint3_ext** normals;
    NiP2** texcoords;
};

struct Land5371_od_ctx {
    int unk00; int unk04; int unk08; int unk0c; int unk10;
    int unk14; int unk18; int unk1c; int unk20; int unk24;
    MeshData5371_od_ctx* data;
    Geometry5371_od_ctx* FUN_005371b0(unsigned char index);
};

class LandLD_od_ctx {
public:
    bool FUN_0053db20();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    LandDataLD* m_pUserData;
};

struct FUN_006815c0 {
    float x, y, z;
    FUN_006815c0();
};

struct FUN_004a7800 {
    float x, y, z, w;
    FUN_004a7800();
};

struct Resource {
};

struct FUN_005405a0 {
    void* unknown00;
    FUN_006815c0** positions;
    FUN_006815c0** normals;
    FUN_004a7800** transforms;
    unsigned char** tags;
    int unknown14;
    int unknown18;
    int unknown1c;
    void* resources[4];
    void* metadata[4];
    float** vertexRows[4];
    int unknown50, unknown54, unknown58, unknown5c;
    int unknown60, unknown64, unknown68, unknown6c;
    int unknown70, unknown74, unknown78, unknown7c;
    int unknown80, unknown84, unknown88, unknown8c;
    int unknown90, unknown94;
    void* initialValue98;
    void* initialValue9c;
    int unknownA0;
    FUN_005405a0();
};

struct GeometryOwner_od_ctx {
    int unknown00, unknown04, unknown08, unknown0c;
    int unknown10, unknown14, unknown18, unknown1c;
    Resource* resource;
    int unknown24;
    FUN_005405a0* geometry;
    bool FUN_00539500(GeometryOwner_od_ctx* source);
};

// @fnv 0x00539500
bool GeometryOwner_od_ctx::FUN_00539500(GeometryOwner_od_ctx* source)
{
    if (geometry != 0 && geometry->positions != 0)
        return false;

    geometry = new FUN_005405a0;
    geometry->initialValue98 = ((void *)(std::uintptr_t)(reinterpret_cast<::TESObjectCELL *>((resource))->GetCellGridX()));
    geometry->initialValue9c = ((void *)(std::uintptr_t)(reinterpret_cast<::TESObjectCELL *>((resource))->GetCellGridY()));

    geometry->positions = new FUN_006815c0*[4];
    geometry->transforms = new FUN_004a7800*[4];
    geometry->normals = new FUN_006815c0*[4];
    geometry->tags = new unsigned char*[4];

    float height = reinterpret_cast<::fnv_0053a550::DoorH *>(this)->FUN_0053a550();
    for (int i = 0; i < 4; ++i) {
        geometry->positions[i] = new FUN_006815c0[0x121];
        geometry->transforms[i] = new FUN_004a7800[0x121];
        geometry->normals[i] = new FUN_006815c0[0x121];
        geometry->tags[i] = new unsigned char[0x121];
        geometry->vertexRows[i] = new float*[0x121];
        geometry->resources[i] = (void*)FUN_00535ae0();
        geometry->metadata[i] = new unsigned char[0x18];

        if (!source || !source->geometry) {
            memcpy(geometry->positions[i], (*reinterpret_cast<void * (*)[4]>(&::g_landBufArray))[i], 0xd8c);
            memcpy(geometry->transforms[i], (*reinterpret_cast<void * *>(&::g_landBuf1)), 0x1210);
            memcpy(geometry->normals[i], (*reinterpret_cast<void * *>(&::g_landBuf2)), 0xd8c);
            memcpy(geometry->tags[i], (*reinterpret_cast<void * *>(&::g_landBuf4)), 0x121);

            if (height != DAT_0102dcc4) {
                for (int j = 0; j < 0x121; ++j)
                    geometry->positions[i][j].z = height;
            }

            float* vertexData = new float[0x121 * 8];
            memset(vertexData, 0, 0x2420);
            for (int k = 0; k < 0x121; ++k)
                geometry->vertexRows[i][k] = vertexData + k * 8;
            memset(geometry->metadata[i], 0, 0x18);
        }
    }
    return true;
}

struct FUN_00534080_Class_od_decl {
    double FUN_00534080();
};

struct FUN_005340b0_Class_od_decl {
    int m_auiShapeKeys[8];
    DoorH* m_pDoor;
    TESWorldSpace* FUN_005340b0();
};

struct NiPoint3_od_decl { float x; float y; float z; public:
    ::NiPoint3_od_decl Cross(const ::NiPoint3_od_decl &) const;
public:
    static const ::NiPoint3_od_decl ZERO;
};

struct TESForm_od_decl { virtual ~TESForm_od_decl();  public:
    void ClearData();
public:
    ::TESFile *GetFile(int);
};

struct FUN_00534570_shell_od_decl { char* m_pkDeltas; unsigned int stride; void FUN_00534570(unsigned int index, NiPoint3_od_decl& vertex); };

struct BGSQuestObjective_od_decl {  };

struct FUN_00538e30_class_od_decl {
};

struct FUN_00538f80_od_decl {
    void* DeleteThis(unsigned int flags);
};

struct BGSTextureSet_od_decl {
};

struct FUN_00537d60_od_decl : A51BF0Base {
    char _pad[0x18];
    int _m18;
    int _m1c;
    FUN_00537e30_cls* FUN_00537e30();
    FUN_00537d60_od_decl();
};

struct Data538110_od_decl {
    void* m_00;
    NiPoint3_od_decl** m_04;
    NiPoint3_od_decl** m_08;
    Elem16** m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void* m_20arr[4];
    int* m_30arr[4];
    int m_40arr[4];
};

struct This538110_od_decl {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    Data538110_od_decl* m_28;
    void FUN_00538110();
};

struct FNv53b450_Source_od_decl {
    FNv53b450_Point* FUN_0053b450(FNv53b450_Point* output, unsigned char flags, unsigned short cellIndex, const int* x, const int* y);
};

struct FUN_00461c20_Holder_od_decl {
};

struct VertLock_od_decl : FUN_00534570_shell_od_decl {
    int unk08;
    VertLock_od_decl();
};

struct LandCopyData_od_decl {
    void* nodes;
    NiPoint3_od_decl** vertices;
    NiPoint3_od_decl** normals;
    Elem16** colors;
    unsigned char** textureIndices;
    int unk14;
    int cellX;
    int cellY;
    int baseTextures[4];
    int* textureLayers[4];
    void** weights[4];
};

struct LandCopy_od_decl : TESPackage {
    void* cell;
    int unk24;
    LandCopyData_od_decl* data;
    void FUN_005348c0(TESForm_od_decl* form);
};

struct Scene_od_decl {
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
virtual void v28();
virtual void v2c();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3c();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4c();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5c();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6c();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7c();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8c();
virtual void v90();
virtual void v94();
virtual void v98();
virtual void v9c();
virtual void va0();
virtual void va4();
virtual void va8();
virtual void vac();
virtual void vb0();
virtual void vb4();
virtual void SetPosition(const NiPoint3_od_decl&);
virtual void vbc();
virtual void vc0();
virtual void vc4();
virtual void vc8();
virtual void vcc();
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void vdc();
virtual void ve0();
virtual void ve4();
virtual void ve8();
virtual void vec();
virtual void vf0();
virtual void vf4();
virtual void Attach(int,Shape*);
  
 
 
};

struct Renderer_od_decl {virtual void v00();
virtual void v04();
virtual void v08();
virtual void v0c();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1c();
virtual void v20();
virtual void v24();
virtual void v28();
virtual void v2c();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3c();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4c();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5c();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6c();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7c();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8c();
virtual void v90();
virtual void v94();
virtual void v98();
virtual void v9c();
virtual void va0();
virtual void va4();
virtual void va8();
virtual void vac();
virtual void vb0();
virtual void vb4();
virtual void vb8();
virtual void vbc();
virtual void vc0();
virtual void vc4();
virtual void vc8();
virtual void vcc();
virtual void vd0();
virtual void vd4();
virtual void vd8();
virtual void vdc();
virtual void ve0();
virtual void ve4();
virtual void ve8();
virtual void Render(Shape*,int,int,void*);
};

struct Data_od_decl {Scene_od_decl** nodes; int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c;
int unk20;
int unk24;
int unk28;
int unk2c;
int unk30;
int unk34;
int unk38;
int unk3c;
int unk40;
int unk44;
int unk48;
int unk4c;
int unk50;
int unk54;
int unk58;
int unk5c;
int unk60;
int unk64;
int unk68;
int unk6c;
int unk70;
int unk74;
int unk78;
int unk7c;
int unk80;
int unk84;
int unk88;
int unk8c;
int unk90;
int unk94;
int unk98;
int unk9c; float scale;};

struct Land_od_decl {int unk00;
int unk04;
int unk08;
int unk0c;
int unk10;
int unk14;
int unk18;
int unk1c; Cell* cell; int unk24; Data_od_decl* data;
 
  
 void FUN_0053aeb0(); 
  void FUN_005374f0();};

struct Output538c00_od_decl

{

    virtual ~Output538c00_od_decl();

    unsigned int m04;

    unsigned int m08;

    unsigned int m0c;

    unsigned int m10;

    unsigned int m14;

    unsigned int m18;

    unsigned int m1c;

    Buffer538c00 buffer;

    unsigned int m28;

    unsigned int m2c;

    Output538c00_od_decl();
    static void* operator new(std::size_t bytes) { return FUN_0056d280(bytes); }

};

struct FUN_00538c00_Class_od_decl

{

    char FUN_00538c00(const void* source, unsigned int size, Output538c00_od_decl** result);

};

struct Worker53_od_decl {
 int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24;
 Config53* config;
   
 void FUN_0053a090(bool update, int unused);
};

class NiPoint3_od_decl;

struct TerrainOwner_od_decl {
 int u00,u04,u08,u0c,u10,u14,u18,u1c,u20,u24; TerrainData* data;
 bool FUN_0053bc10();
public:
    bool ComputeTerrainNormalAndTangent(::TerrainInput *, ::NiPoint3_od_decl *, ::NiPoint3_od_decl *);
};

struct NormalPoint_od_decl {
 float x,y,z;
 NormalPoint_od_decl operator-(const NormalPoint_od_decl&) const;
 NormalPoint_od_decl& operator+=(const NormalPoint_od_decl&);
};

struct NormalData_od_decl {
 int unk00;
 NormalPoint_od_decl** vertices;
 NormalPoint_od_decl** normals;
 int unk0c;
 unsigned char** flags;
};

struct NormalLand_od_decl : TESPackage {
 int unk20;
 int unk24;
 NormalData_od_decl* data;
 void FUN_0053df30(void* region);
};

class TESFileL53 {
public:
};

void* __cdecl MemAllocL53(unsigned int uiSize);

void __cdecl MemFreeL53(void* pvMem);

class TESLandTexture_od_decl;

class TESLandTexture_od_decl : public TESForm_od_decl {
public:
};

struct NiPoint2L53 {
    NiPoint2L53(float fX, float fY);
    float x;
    float y;
};

struct NiPoint3L53 {
    float x;
    float y;
    float z;
};

struct NiColorAL53 {
    NiColorAL53(float fR, float fG, float fB, float fA);
    float r;
    float g;
    float b;
    float a;
};

struct SwapFloatL53 {
};

struct LandRefObjectL53 {
};

struct LandDataL53 {
    unsigned int unk00;
    NiPoint3L53** m_ppVertices;
    NiPoint3L53** m_ppNormals;
    NiColorAL53** m_ppColors;
    unsigned int unk10;
    unsigned int unk14;
    NiPoint2L53 m_kHeightExtents;
    TESLandTexture_od_decl* m_apBaseTextures[4];
    TESLandTexture_od_decl** m_appTextures[4];
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    LandRefObjectL53* m_pkMPCD;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    float m_fHeightOffset;
};

struct LandTextureListL53 {
    LandTextureListL53(int iSize);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
};

struct LandListHolderL53 {
};

struct LandBTXTL53 {
    unsigned int auiFormId;
    unsigned char ucQuadrant;
    unsigned char ucPad;
    unsigned short usLayer;
};

struct LandVTXTL53 {
    unsigned short usPosition;
    unsigned short usPad;
    float fOpacity;
};

struct LandVHGTL53 {
    float fProjectionAlongAim;
    signed char acHeights[0x441];
};

class TESLandL53 {
public:
    bool FUN_00534ad0(TESFileL53* pkFile);

    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int m_uiValue1;
    unsigned int unk20;
    LandListHolderL53 m_kList;
    LandDataL53* m_pUserData;
};

// @fnv 0x00534ad0
bool TESLandL53::FUN_00534ad0(TESFileL53* pkFile)
{
    AutoMemContext kContext(0x1b, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\TESLand.cpp", 0x2c2);
    unsigned char ucFormType3 = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((pkFile))->FUN_00472660()));
    if (ucFormType3 != 0x42)
        return false;

    unsigned int auiFormId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()));
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(pkFile));
    int i11;
    int j;
    int iLastLayer3 = -1;
    int iLastQuadrant3 = -1;
    bool bLoadData5 = false;
    if (reinterpret_cast<::FUN_00471d60_shell *>((pkFile))->IsFlag8Set() || ((bool)(::FUN_00551680()))) {
        if (!reinterpret_cast<::FUN_00534140_Class *>(this)->FUN_00534140())
            bLoadData5 = true;
    }
    if (bLoadData5)
        reinterpret_cast<::GeometryOwner *>(this)->FUN_00539500((::GeometryOwner *)(0));

    bool bError5 = false;
    do {
        switch (reinterpret_cast<::FUN_004726b0_class *>((pkFile))->FUN_004726b0()) {
        case 'ATAD': {
            bool bWasLoaded = reinterpret_cast<::FUN_00534140_Class *>(this)->FUN_00534140();
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(void *)(&m_uiValue1), 4);
            if (reinterpret_cast<::TESFile *>((pkFile))->IsEndianConversionRequired())
                reinterpret_cast<::fnv_00503210::Unk *>((reinterpret_cast<SwapFloatL53*>(&m_uiValue1)))->FUN_00503210();
            reinterpret_cast<::FUN_005394c0_Class *>(this)->FUN_005394c0(false);
            reinterpret_cast<::FUN_00534160_Class *>(this)->FUN_00534160(bWasLoaded);
            break;
        }
        case 'DCPM': {
            if (!bLoadData5)
                break;
            unsigned int uiSize = reinterpret_cast<::FUN_00401660_Class *>((pkFile))->GetField25C();
            char* pcData = new char[uiSize];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(pcData), uiSize);
            if (m_pUserData->m_pkMPCD) {
                reinterpret_cast<::hkReferencedObjectC905 *>((m_pUserData->m_pkMPCD))->FUN_00c905b0();
                m_pUserData->m_pkMPCD = 0;
            }
            reinterpret_cast<::FUN_00538c00_Class_od_decl *>(this)->FUN_00538c00(pcData, uiSize, (::Output538c00_od_decl **)(::LandRefObjectL53 **)(&m_pUserData->m_pkMPCD));
            if (m_pUserData->m_pkMPCD) {
                reinterpret_cast<::FUN_00c90510_class *>((m_pUserData->m_pkMPCD))->FUN_00c90510();
                reinterpret_cast<::FUN_005341a0_Class *>(this)->FUN_005341a0(true);
            }
            delete[] pcData;
            break;
        }
        case 'TGHV': {
            if (!bLoadData5)
                break;
            LandVHGTL53 kHeights;
            if (m_uiValue1 & 1) {
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(void *)(&kHeights.fProjectionAlongAim), 0);
                if (reinterpret_cast<::TESFile *>((pkFile))->IsEndianConversionRequired())
                    reinterpret_cast<::fnv_00503210::Unk *>((reinterpret_cast<SwapFloatL53*>(&kHeights.fProjectionAlongAim)))->FUN_00503210();
                m_pUserData->m_kHeightExtents = NiPoint2L53(DAT_01016970, DAT_01015f5c);
                float fRowStart2 = kHeights.fProjectionAlongAim;
                float afHeights[0x441];
                for (i11 = 0; i11 < 0x441; i11++) {
                    afHeights[i11] = kHeights.acHeights[i11] + fRowStart2;
                    if ((i11 + 1) % 33 == 0)
                        fRowStart2 = afHeights[i11 - 32];
                    else
                        fRowStart2 = afHeights[i11];
                }
                for (i11 = 0; i11 < 4; i11++) {
                    int iBase = (i11 / 2) * 16 * 33 + (i11 % 2) * 16;
                    for (j = 0; j < 0x121; j++) {
                        int iCol = j % 17;
                        int iRow2 = j / 17;
                        int iIndex = iRow2 * 33 + iBase + iCol;
                        float fZ = (float)(::FUN_00406d90(afHeights[iIndex]) << 3);
                        m_pUserData->m_ppVertices[i11][j].x = (float)(iCol << 7) + ::TESLandInit::DAT_011c9ec4[i11];
                        m_pUserData->m_ppVertices[i11][j].y = (float)(iRow2 << 7) + ::TESLandInit::DAT_011c9eb4[i11];
                        m_pUserData->m_ppVertices[i11][j].z = fZ;
                        if (fZ < m_pUserData->m_kHeightExtents.x)
                            m_pUserData->m_kHeightExtents.x = fZ;
                        else if (fZ > m_pUserData->m_kHeightExtents.y)
                            m_pUserData->m_kHeightExtents.y = fZ;
                    }
                }
                m_pUserData->m_fHeightOffset = (m_pUserData->m_kHeightExtents.x + m_pUserData->m_kHeightExtents.y) * 0.5f;
                for (i11 = 0; i11 < 4; i11++) {
                    for (j = 0; j < 0x121; j++)
                        m_pUserData->m_ppVertices[i11][j].z = m_pUserData->m_ppVertices[i11][j].z - m_pUserData->m_fHeightOffset;
                }
            }
            break;
        }
        case 'LMNV': {
            if (!bLoadData5)
                break;
            if (m_uiValue1 & 1) {
                signed char acNormals[0x441 * 3];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(acNormals), 0);
                for (i11 = 0; i11 < 4; i11++) {
                    int iBase = (i11 / 2) * 16 * 33 + (i11 % 2) * 16;
                    for (j = 0; j < 0x121; j++) {
                        int iIndex = j / 17 * 33 + iBase + j % 17;
                        m_pUserData->m_ppNormals[i11][j].x = (float)acNormals[iIndex * 3] / 127.0f;
                        m_pUserData->m_ppNormals[i11][j].y = (float)acNormals[iIndex * 3 + 1] / 127.0f;
                        m_pUserData->m_ppNormals[i11][j].z = (float)acNormals[iIndex * 3 + 2] / 127.0f;
                        reinterpret_cast<::FUN_004a0c10_s *>(&(m_pUserData->m_ppNormals[i11][j]))->FUN_004a0c10();
                    }
                }
            }
            break;
        }
        case 'RLCV': {
            if (!bLoadData5)
                break;
            if (m_uiValue1 & 2) {
                unsigned char aucColors[0x441 * 3];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(aucColors), 0);
                for (i11 = 0; i11 < 4; i11++) {
                    int iBase = (i11 / 2) * 16 * 33 + (i11 % 2) * 16;
                    for (j = 0; j < 0x121; j++) {
                        int iIndex = j / 17 * 33 + iBase + j % 17;
                        m_pUserData->m_ppColors[i11][j] = NiColorAL53((float)(aucColors[iIndex * 3] / 255.0),
                            (float)(aucColors[iIndex * 3 + 1] / 255.0), (float)(aucColors[iIndex * 3 + 2] / 255.0), 1.0f);
                    }
                }
            }
            break;
        }
        case 'TXTB': {
            if (!bLoadData5)
                break;
            LandBTXTL53 kBTXT;
            ::FUN_00403d30(&kBTXT, 0, 8);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(void *)(&kBTXT), 8);
            if (reinterpret_cast<::TESFile *>((pkFile))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00535a60_Class *>(&(kBTXT))->FUN_00535a60();
            ::ResolveFormID(&kBTXT.auiFormId, (::TESFile *)(pkFile));
            m_pUserData->m_apBaseTextures[kBTXT.ucQuadrant] = dynamic_cast<TESLandTexture_od_decl*>(::FUN_004839c0(kBTXT.auiFormId));
            if (!m_pUserData->m_apBaseTextures[kBTXT.ucQuadrant]) {
                ::FUN_005b5e40();
                bError5 = true;
            } else {
                if (!((void *)(::FUN_00559450((int *)&(m_kList)))))
                    reinterpret_cast<::FUN_006f74f0_cls *>(&(m_kList))->FUN_006f74f0((::ObjA *)(::LandTextureListL53 *)(new LandTextureListL53(5)));
                TESLandTexture_od_decl* pkTexture = m_pUserData->m_apBaseTextures[kBTXT.ucQuadrant];
                reinterpret_cast<::FUN_00541540_Class *>((pkTexture))->FUN_00541540(5, (::QueuedFile *)(void *)(((void *)(::FUN_00559450((int *)&(m_kList))))));
            }
            break;
        }
        case 'TXTA': {
            if (!bLoadData5)
                break;
            else {
            LandBTXTL53 kATXT;
            ::FUN_00403d30(&kATXT, 0, 8);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(void *)(&kATXT), 8);
            if (reinterpret_cast<::TESFile *>((pkFile))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00535a60_Class *>(&(kATXT))->FUN_00535a60();
            if (kATXT.usLayer > 5) {
                ::FUN_005b5e40();
                kATXT.usLayer = 5;
                bError5 = true;
            }
            TESLandTexture_od_decl* pkTexture = 0;
            if (kATXT.auiFormId) {
                ::ResolveFormID(&kATXT.auiFormId, (::TESFile *)(pkFile));
                pkTexture = dynamic_cast<TESLandTexture_od_decl*>(::FUN_004839c0(kATXT.auiFormId));
                if (!pkTexture) {
                    ::FUN_005b5e40();
                    bError5 = true;
                }
            } else {
                pkTexture = ((::TESLandTexture_od_decl *)(::FUN_00535ae0()));
            }
            m_pUserData->m_appTextures[kATXT.ucQuadrant][kATXT.usLayer] = pkTexture;
            if (pkTexture) {
                if (!((void *)(::FUN_00559450((int *)&(m_kList)))))
                    reinterpret_cast<::FUN_006f74f0_cls *>(&(m_kList))->FUN_006f74f0((::ObjA *)(::LandTextureListL53 *)(new LandTextureListL53(5)));
                reinterpret_cast<::FUN_00541540_Class *>((pkTexture))->FUN_00541540(5, (::QueuedFile *)(void *)(((void *)(::FUN_00559450((int *)&(m_kList))))));
            }
            iLastQuadrant3 = kATXT.ucQuadrant;
            iLastLayer3 = kATXT.usLayer;
            }
            break;
        }
        case 'TXTV': {
            if (!bLoadData5)
                break;
            if (iLastQuadrant3 >= 0 && iLastLayer3 >= 0) {
                unsigned int uiSize = reinterpret_cast<::FUN_00401660_Class *>((pkFile))->GetField25C();
                if (uiSize % 8 == 0) {
                    LandVTXTL53* pkVTXT = static_cast<LandVTXTL53*>(::FUN_00401000(uiSize));
                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(pkVTXT), uiSize);
                    unsigned int ItemUpdateArray = uiSize >> 3;
                    for (unsigned int k = 0; k < ItemUpdateArray; k++) {
                        if (reinterpret_cast<::TESFile *>((pkFile))->IsEndianConversionRequired())
                            reinterpret_cast<::FUN_00535aa0_Class *>(&(pkVTXT[k]))->FUN_00535aa0();
                        if (pkVTXT[k].fOpacity > 1.0)
                            pkVTXT[k].fOpacity = pkVTXT[k].fOpacity / 100.0;
                        reinterpret_cast<::C53A8A0Owner *>(this)->FUN_0053a8a0(iLastQuadrant3, pkVTXT[k].usPosition, iLastLayer3, pkVTXT[k].fOpacity);
                    }
                    ::FUN_00401030(pkVTXT);
                    pkVTXT = 0;
                } else {
                    ::FUN_005b5e40();
                    bError5 = true;
                }
            }
            iLastQuadrant3 = -1;
            iLastLayer3 = -1;
            break;
        }
        }
    } while (reinterpret_cast<::TESFile *>((pkFile))->NextChunk());

    if (bError5)
        reinterpret_cast<::LayerOwner53a940 *>(this)->FUN_0053a940();
    reinterpret_cast<::FUN_005394c0_Class *>(this)->FUN_005394c0(bLoadData5);
    return true;
}

struct FUN_00534080_Class_od_rtti
{
    double FUN_00534080();
};

struct FUN_005340b0_Class_od_rtti
{
    int m_auiShapeKeys[8];
    DoorH* m_pDoor;
    TESWorldSpace* FUN_005340b0();
};

struct NiPoint3_od_rtti
{
    float x;
    float y;
    float z;
public:
    ::NiPoint3_od_rtti Cross(const ::NiPoint3_od_rtti &) const;
public:
    static const ::NiPoint3_od_rtti ZERO;
};

struct TESForm_od_rtti
{
    virtual ~TESForm_od_rtti();  // the original class is polymorphic (rtti_variants.py)
public:
    void ClearData();
public:
    ::TESFile *GetFile(int);
};

struct FUN_00534570_shell_od_rtti
{
    char* m_pkDeltas;
    unsigned int stride;
    void FUN_00534570(unsigned int index, NiPoint3_od_rtti& vertex);
};

template <int> struct EndianSizeTag_od_rtti
{
};

struct BGSQuestObjective_od_rtti
{
};

struct FUN_00538e30_class_od_rtti
{
};

struct FUN_00538f80_od_rtti
{
    void* DeleteThis(unsigned int flags);
};

struct LandscapeColorData_od_rtti
{
    int m00, m04, m08, m0C, m10, m14, m18, m1C, m20, m24, m28, m2C, m30, m34, m38, m3C, m40, m44, m48, m4C;
    void FUN_0053a510();
};

struct TESObjectLAND_od_rtti
{
    bool FUN_0053f180(const LandscapeColorData_od_rtti&, float&);
};

struct BGSTextureSet_od_rtti
{
};

struct FUN_00537d60_od_rtti : A51BF0Base
{
    char _pad[0x18];
    int _m18;
    int _m1c;
    FUN_00537e30_cls* FUN_00537e30();
    FUN_00537d60_od_rtti();
};

struct Data538110_od_rtti
{
    void* m_00;
    NiPoint3_od_rtti** m_04;
    NiPoint3_od_rtti** m_08;
    Elem16** m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    void* m_20arr[4];
    int* m_30arr[4];
    int m_40arr[4];
};

struct This538110_od_rtti
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    Data538110_od_rtti* m_28;
    void FUN_00538110();
};

struct Mem960_od_rtti
{
    int value;
    Mem960_od_rtti(int, bool, const char*, int);
    ~Mem960_od_rtti();
};

struct Color960_od_rtti
{
    float r, g, b, a;
    Color960_od_rtti(float, float, float, float);
};

struct Texture960_od_rtti
{
};

struct Property960_od_rtti
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void* vd4(void*);
    unsigned unk004;
    unsigned unk008;
    unsigned unk00c;
    unsigned unk010;
    unsigned unk014;
    unsigned unk018;
    unsigned unk01c;
    unsigned unk020;
    unsigned unk024;
    unsigned unk028;
    unsigned unk02c;
    unsigned unk030;
    unsigned unk034;
    unsigned unk038;
    unsigned unk03c;
    unsigned unk040;
    unsigned unk044;
    unsigned unk048;
    unsigned unk04c;
    unsigned unk050;
    unsigned unk054;
    unsigned unk058;
    unsigned unk05c;
    unsigned unk060;
    unsigned unk064;
    unsigned unk068;
    unsigned unk06c;
    unsigned unk070;
    unsigned unk074;
    unsigned unk078;
    unsigned unk07c;
    unsigned unk080;
    unsigned unk084;
    unsigned unk088;
    unsigned unk08c;
    unsigned unk090;
    unsigned unk094;
    unsigned unk098;
    unsigned unk09c;
    unsigned unk0a0;
    unsigned unk0a4;
    unsigned unk0a8;
    unsigned unk0ac;
    unsigned unk0b0;
    unsigned unk0b4;
    unsigned unk0b8;
    unsigned unk0bc;
    unsigned unk0c0;
    unsigned unk0c4;
    unsigned unk0c8;
    unsigned unk0cc;
    unsigned unk0d0;
    unsigned unk0d4;
    unsigned unk0d8;
    unsigned unk0dc;
    unsigned unk0e0;
    unsigned unk0e4;
    unsigned unk0e8;
    unsigned unk0ec;
    unsigned unk0f0;
    unsigned unk0f4;
    unsigned unk0f8;
    unsigned unk0fc;
    unsigned unk100;
    Property960_od_rtti();
};

struct Binary960_od_rtti
{
    unsigned unk00, unk04, unk08, unk0c, unk10;
    Binary960_od_rtti(unsigned, unsigned char*);
};

struct Geometry960_od_rtti
{
};

struct Node960_od_rtti
{
};

struct Data960_od_rtti
{
    Node960_od_rtti** nodes;
    unsigned unk04, unk08;
    Color960_od_rtti** colors;
    unsigned unk10, unk14, unk18, unk1c;
    Texture960_od_rtti* base[4];
    Texture960_od_rtti** layers[4];
    unsigned char** binary[4];
};

struct Host960_od_rtti
{
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, flags, unk20, unk24;
    Data960_od_rtti* data;
    bool FUN_00539960();
};

struct FNv53b450_Source_od_rtti
{
    FNv53b450_Point* FUN_0053b450(FNv53b450_Point* output, unsigned char flags, unsigned short cellIndex, const int* x,
                                  const int* y);
};

struct FUN_00461c20_Holder_od_rtti
{
};

class NiPoint2_od_rtti
{
  public:
    float x, y;
    NiPoint2_od_rtti(float, float);
};

struct UVBounds_od_rtti
{
    float x, y, z, w;
};

struct ShaderProperty_od_rtti
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void setFirst(int, void*);
    virtual void setSecond(int, void*);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    UVBounds_od_rtti bounds;
};

struct TESFileRecordLoader_od_rtti
{
    QuadNode** nodes;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int x, y;
};

struct Surface_od_rtti
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    TESFileRecordLoader_od_rtti* data;
    void FUN_005400e0();
};

struct LandObject_od_rtti : TESObjectLAND_od_rtti
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    LandLoadedData* m_pRenderData;
    void FUN_00534240(int quadrant, int index, LandPoint3* vertex);
};

struct VertLock_od_rtti : FUN_00534570_shell_od_rtti
{
    int unk08;
    VertLock_od_rtti();
};

struct LandCopyData_od_rtti
{
    void* nodes;
    NiPoint3_od_rtti** vertices;
    NiPoint3_od_rtti** normals;
    Elem16** colors;
    unsigned char** textureIndices;
    int unk14;
    int cellX;
    int cellY;
    int baseTextures[4];
    int* textureLayers[4];
    void** weights[4];
};

struct LandCopy_od_rtti : TESPackage
{
    void* cell;
    int unk24;
    LandCopyData_od_rtti* data;
    void FUN_005348c0(TESForm_od_rtti* form);
};

struct Point_od_rtti
{
    float x, y, z;
    Point_od_rtti(float, float, float);
};

struct Range_od_rtti
{
    float x, y;
};

struct UpdateData_od_rtti
{
    float time;
    bool a, b;
    int c;
    UpdateData_od_rtti(float, bool, bool);
};

struct Bound_od_rtti
{
};

struct Model_od_rtti
{
};

struct Scene_od_rtti
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void SetPosition(const NiPoint3_od_rtti&);
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void Attach(int, Shape*);
};

struct PropPointer_od_rtti
{
};

struct Renderer_od_rtti
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
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void Render(Shape*, int, int, void*);
};

struct Cell_od_rtti
{
};

struct Scratch_od_rtti
{
    int a, b, c, d;
    Scratch_od_rtti();
};

struct Data_od_rtti
{
    Scene_od_rtti** nodes;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    float scale;
};

struct Land_od_rtti
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Cell_od_rtti* cell;
    int unk24;
    Data_od_rtti* data;
    void FUN_0053aeb0();
    void FUN_005374f0();
};

struct Output538c00_od_rtti

{

    virtual ~Output538c00_od_rtti();

    unsigned int m04;

    unsigned int m08;

    unsigned int m0c;

    unsigned int m10;

    unsigned int m14;

    unsigned int m18;

    unsigned int m1c;

    Buffer538c00 buffer;

    unsigned int m28;

    unsigned int m2c;

    Output538c00_od_rtti();
    static void* operator new(std::size_t bytes)
    {
        return FUN_0056d280(bytes);
    }
};

struct FUN_00538c00_Class_od_rtti

{

    char FUN_00538c00(const void* source, unsigned int size, Output538c00_od_rtti** result);
};

struct Worker53_od_rtti
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Config53* config;
    void FUN_0053a090(bool update, int unused);
};

struct Sample_od_rtti
{
    const char* model;
    unsigned int id;
    float f08, f0c, f10, f14, f18;
    unsigned char b1c, b1d, b1e, b1f;
    float weights[9];
    Sample_od_rtti();
};

struct SampleMap_od_rtti
{
    int u00, u04, u08, u0c;
};

struct TerrainData_od_rtti
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c;
    TextureGrass* base[4];
    TextureGrass** layers[4];
    float** weights[4];
    int u50;
    SampleMap_od_rtti maps[4];
};

class NiPoint3_od_rtti;

struct TerrainOwner_od_rtti
{
    int u00, u04, u08, u0c, u10, u14, u18, u1c, u20, u24;
    TerrainData_od_rtti* data;
    bool FUN_0053bc10();
public:
    bool ComputeTerrainNormalAndTangent(::TerrainInput *, ::NiPoint3_od_rtti *, ::NiPoint3_od_rtti *);
};

struct NormalPoint_od_rtti
{
    float x, y, z;
    NormalPoint_od_rtti operator-(const NormalPoint_od_rtti&) const;
    NormalPoint_od_rtti& operator+=(const NormalPoint_od_rtti&);
};

struct NormalData_od_rtti
{
    int unk00;
    NormalPoint_od_rtti** vertices;
    NormalPoint_od_rtti** normals;
    int unk0c;
    unsigned char** flags;
};

struct NormalLand_od_rtti : TESPackage
{
    int unk20;
    int unk24;
    NormalData_od_rtti* data;
    void FUN_0053df30(void* region);
};

struct LandData53f_od_rtti
{
    char pad00[0x18];
    NiPoint2_od_rtti kHeight;
};

struct FUN_0053f440_shell_od_rtti
{
    char pad00[0x1c];
    unsigned int uiFlags;
    char pad20[8];
    LandData53f_od_rtti* pkData;

    NiPoint2_od_rtti FUN_0053f440();
};

struct LandFile535d
{
};

struct LandWorld535d
{
};

struct QueuedFile
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    QueuedFile(int);
};

template <class T> struct NiPointer
{
    T* value;
    operator T*() const;
    NiPointer& operator=(T*);
};

class TESLandTexture_od_rtti : public TESForm_od_rtti
{
  public:
    virtual ~TESLandTexture_od_rtti();
};

struct LandTextureRecord535d
{
    unsigned int formID;
    unsigned char quad7;
    unsigned char unused05;
    unsigned short bPlayerPlayerDead;
};

struct LandNormal535d
{
    signed char x, y, z;
};

struct LandColor535d
{
    unsigned char r, g, b;
};

struct LandHeight535d
{
    float base;
    signed char delta[1089];
    unsigned char unused445, unused446, unused447;
};

struct LandWeight535d
{
    unsigned short vertex, unused02;
    float weight;
};

struct LandVector535d
{
    float x, y, z;
};

struct ImageSpaceEffectParam
{
    float r, g, b, a;
    ImageSpaceEffectParam(float, float, float, float);
};

struct LandReference535d
{
};

struct LandData535d
{
    int unk00;
    NiPoint3_od_rtti** vertices;
    LandVector535d** _cNormal;
    ImageSpaceEffectParam** colors;
    int unk10;
    int unk14;
    NiPoint2_od_rtti heightRange;
    TESLandTexture_od_rtti* baseTextures[4];
    TESLandTexture_od_rtti** textures[4];
    void* oldWeightsB[4];
    LandReference535d* reference;
    int unk54, unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    float centerHeight;
};

struct LandCell535d
{
};

extern const char DAT_0102e170[], DAT_0102e120[], DAT_0102e0dc[], DAT_0102e088[], DAT_0102e038[], DAT_0102dfe8[];

struct LandOwner535d_od_rtti : public TESPackage
{
    int unk20;
    NiPointer<QueuedFile> queued;
    LandData535d* data;
    bool FUN_00535d00();
};

// @fnv 0x00535d00
bool LandOwner535d_od_rtti::FUN_00535d00()
{
    if (FUN_005394a0())
        return true;
    int quad7 = -1;
    int bPlayerPlayerDead = -1;
    bool failedActor_2 = false;
    LandFile535d* _fileIndex = 0;
    unsigned int _uBlockOffset = 0;
    if (!reinterpret_cast<::FUN_00534140_Class *>(this)->FUN_00534140())
    {
        if (!(flags & 1) && !(flags & 2) && !(flags & 4))
            return true;
        _fileIndex = ((::LandFile535d *)(reinterpret_cast<::TESFile *>((((::LandFile535d *)(reinterpret_cast<::TESForm_od_rtti *>(this)->GetFile(-1)))))->GetParentTESFile()));
        if (!reinterpret_cast<::FUN_004734d0_shell *>((_fileIndex))->FUN_004734d0((::TESForm *)(void *)(this)))
            failedActor_2 = true;
        if (!failedActor_2)
        {
            unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((_fileIndex))->FUN_00472660()));
            if (formType != 0x42)
                failedActor_2 = true;
        }
        if (!failedActor_2)
            _uBlockOffset = reinterpret_cast<::TESFile *>((_fileIndex))->GetOffset();
    }
    else
    {
        LandWorld535d* world = ((::LandWorld535d *)(reinterpret_cast<::FUN_005340b0_Class_od_rtti *>(this)->FUN_005340b0()));
        if (!world || !reinterpret_cast<::FUN_00585ee0_shell *>((world))->FindParentFile(reinterpret_cast<::FUN_00533fd0_Class *>(this)->FUN_00533fd0(), reinterpret_cast<::fnv_00534010::FUN_00534010 *>(this)->GetY(), (void **)(::LandFile535d **)(&_fileIndex), &_uBlockOffset))
            return true;
    }
    if (failedActor_2)
    {
        FUN_0043b2b0(false);
        ::FUN_005b5e40();
        FUN_0043b2b0(true);
        return false;
    }
    LandFile535d* _streamSize = _fileIndex;
    if (!reinterpret_cast<::TESOffsetWorker *>((_streamSize))->FUN_004723a0(_uBlockOffset))
        return false;
    bool _tilesHeight = false;
    bool _cNormal = false;
    bool loc1ac = false;
    int Diff6, ProjectedLoc8;
    do
    {
        switch (reinterpret_cast<::FUN_004726b0_class *>((_streamSize))->FUN_004726b0())
        {
        case 0x41544144:
            if (reinterpret_cast<::FUN_00534140_Class *>(this)->FUN_00534140())
            {
                unsigned int loadedFlags;
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((_streamSize))->FUN_00472890((char *)(void *)(&loadedFlags), 4);
                if (reinterpret_cast<::TESFile *>((_streamSize))->IsEndianConversionRequired())
                    reinterpret_cast<::fnv_00503210::Unk *>((&loadedFlags))->FUN_00503210();
                loadedFlags &= 7;
                flags &= ~7;
                flags |= loadedFlags;
            }
            break;
        case 0x4443504d: {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((_streamSize))->GetField25C();
            unsigned char* buffer = new unsigned char[size];
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((_streamSize))->FUN_00472890((char *)(buffer), size);
            if (data->reference)
            {
                reinterpret_cast<::hkReferencedObjectC905 *>((data->reference))->FUN_00c905b0();
                data->reference = 0;
            }
            reinterpret_cast<::FUN_00538c00_Class_od_rtti *>(this)->FUN_00538c00(buffer, size, (::Output538c00_od_rtti **)(::LandReference535d **)(&data->reference));
            if (data->reference)
            {
                reinterpret_cast<::FUN_00c90510_class *>((data->reference))->FUN_00c90510();
                reinterpret_cast<::FUN_005341a0_Class *>(this)->FUN_005341a0(true);
            }
            delete[] buffer;
        }
        break;
        case 0x54474856:
            if (flags & 1)
            {
                LandHeight535d record;
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((_streamSize))->FUN_00472890((char *)(void *)(&record), sizeof(record));
                if (reinterpret_cast<::TESFile *>((_streamSize))->IsEndianConversionRequired())
                    reinterpret_cast<::fnv_00503210::Unk *>(&(record))->FUN_00503210();
                data->heightRange = NiPoint2_od_rtti(DAT_01016970, DAT_01015f5c);
                float _pMPrev = record.base;
                float height[1089];
                for (Diff6 = 0; Diff6 < 1089; Diff6++)
                {
                    height[Diff6] = record.delta[Diff6] + _pMPrev;
                    if ((Diff6 + 1) % 33 == 0)
                        _pMPrev = height[Diff6 - 32];
                    else
                        _pMPrev = height[Diff6];
                }
                for (Diff6 = 0; Diff6 < 4; Diff6++)
                {
                    int start = (Diff6 / 2 * 16) * 33 + (Diff6 % 2 * 16);
                    for (ProjectedLoc8 = 0; ProjectedLoc8 < 289; ProjectedLoc8++)
                    {
                        int x = ProjectedLoc8 % 17;
                        int y = ProjectedLoc8 / 17;
                        int index = start + y * 33 + x;
                        float z = float(::FUN_00406d90(height[index]) * 8);
                        data->vertices[Diff6][ProjectedLoc8].x = (x * 128) + ::TESLandInit::DAT_011c9ec4[Diff6];
                        data->vertices[Diff6][ProjectedLoc8].y = (y * 128) + ::TESLandInit::DAT_011c9eb4[Diff6];
                        data->vertices[Diff6][ProjectedLoc8].z = z;
                        if (z < data->heightRange.x)
                            data->heightRange.x = z;
                        else if (z > data->heightRange.y)
                            data->heightRange.y = z;
                    }
                }
                data->centerHeight = (data->heightRange.x + data->heightRange.y) * 0.5f;
                for (Diff6 = 0; Diff6 < 4; Diff6++)
                    for (ProjectedLoc8 = 0; ProjectedLoc8 < 289; ProjectedLoc8++)
                        data->vertices[Diff6][ProjectedLoc8].z =
                            data->vertices[Diff6][ProjectedLoc8].z - data->centerHeight;
                _tilesHeight = true;
            }
            break;
        case 0x4c4d4e56:
            if (flags & 1)
            {
                LandNormal535d record[1089];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((_streamSize))->FUN_00472890((char *)(record), sizeof(record));
                for (Diff6 = 0; Diff6 < 4; Diff6++)
                {
                    int start = (Diff6 / 2 * 16) * 33 + (Diff6 % 2 * 16);
                    for (ProjectedLoc8 = 0; ProjectedLoc8 < 289; ProjectedLoc8++)
                    {
                        int index = start + (ProjectedLoc8 / 17) * 33 + ProjectedLoc8 % 17;
                        data->_cNormal[Diff6][ProjectedLoc8].x = record[index].x / 127.0f;
                        data->_cNormal[Diff6][ProjectedLoc8].y = record[index].y / 127.0f;
                        data->_cNormal[Diff6][ProjectedLoc8].z = record[index].z / 127.0f;
                        reinterpret_cast<::FUN_004a0c10_s *>(&(data->_cNormal[Diff6][ProjectedLoc8]))->FUN_004a0c10();
                    }
                }
                _cNormal = true;
            }
            break;
        case 0x524c4356:
            if (flags & 2)
            {
                LandColor535d record[1089];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((_streamSize))->FUN_00472890((char *)(record), sizeof(record));
                for (Diff6 = 0; Diff6 < 4; Diff6++)
                {
                    int start = (Diff6 / 2 * 16) * 33 + (Diff6 % 2 * 16);
                    for (ProjectedLoc8 = 0; ProjectedLoc8 < 289; ProjectedLoc8++)
                    {
                        int index = start + (ProjectedLoc8 / 17) * 33 + ProjectedLoc8 % 17;
                        data->colors[Diff6][ProjectedLoc8] = ImageSpaceEffectParam(
                            record[index].r / 255.0, record[index].g / 255.0, record[index].b / 255.0, 1.0f);
                    }
                }
            }
            break;
        case 0x54585442:
            if (flags & 4)
            {
                LandTextureRecord535d record;
                FUN_00403d30(&record, 0, sizeof(record));
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((_streamSize))->FUN_00472890((char *)(void *)(&record), sizeof(record));
                if (reinterpret_cast<::TESFile *>((_streamSize))->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_00535a60_Class *>(&(record))->FUN_00535a60();
                ::ResolveFormID(&record.formID, (::TESFile *)(_streamSize));
                data->baseTextures[record.quad7] = dynamic_cast<TESLandTexture_od_rtti*>(::FUN_004839c0(record.formID));
                if (!data->baseTextures[record.quad7])
                {
                    ::FUN_005b5e40();
                    loc1ac = true;
                }
                else
                {
                    TESLandTexture_od_rtti* _strEyeTexture = data->baseTextures[record.quad7];
                    if (!queued)
                        reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::NiPointer< ::QueuedFile> &)(queued))->FUN_006f74f0((::ObjA *)(::QueuedFile *)(new QueuedFile(5)));
                    reinterpret_cast<::FUN_00541540_Class *>((_strEyeTexture))->FUN_00541540(5, queued);
                }
            }
            break;
        case 0x54585441:
            if (flags & 4)
            {
                LandTextureRecord535d record;
                FUN_00403d30(&record, 0, sizeof(record));
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((_streamSize))->FUN_00472890((char *)(void *)(&record), sizeof(record));
                if (reinterpret_cast<::TESFile *>((_streamSize))->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_00535a60_Class *>(&(record))->FUN_00535a60();
                if (record.bPlayerPlayerDead > 5)
                {
                    ::FUN_005b5e40();
                    record.bPlayerPlayerDead = 5;
                    loc1ac = true;
                }
                TESLandTexture_od_rtti* _strEyeTexture = 0;
                if (record.formID)
                {
                    ::ResolveFormID(&record.formID, (::TESFile *)(_streamSize));
                    _strEyeTexture = dynamic_cast<TESLandTexture_od_rtti*>(::FUN_004839c0(record.formID));
                    if (!_strEyeTexture)
                    {
                        ::FUN_005b5e40();
                        loc1ac = true;
                    }
                }
                else
                    _strEyeTexture = (TESLandTexture_od_rtti*)FUN_00535ae0();
                data->textures[record.quad7][record.bPlayerPlayerDead] = _strEyeTexture;
                if (_strEyeTexture)
                {
                    if (!queued)
                        reinterpret_cast<::FUN_006f74f0_cls *>((void *)&(const ::NiPointer< ::QueuedFile> &)(queued))->FUN_006f74f0((::ObjA *)(::QueuedFile *)(new QueuedFile(5)));
                    reinterpret_cast<::FUN_00541540_Class *>((_strEyeTexture))->FUN_00541540(5, queued);
                }
                quad7 = record.quad7;
                bPlayerPlayerDead = record.bPlayerPlayerDead;
            }
            break;
        case 0x54585456:
            if (flags & 4)
            {
                if (quad7 >= 0 && bPlayerPlayerDead >= 0)
                {
                    unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((_streamSize))->GetField25C();
                    if (size % 8 == 0)
                    {
                        LandWeight535d* oldWeightsB = (LandWeight535d*)::FUN_00401000(size);
                        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((_streamSize))->FUN_00472890((char *)(oldWeightsB), size);
                        unsigned int count = size >> 3;
                        for (unsigned int k = 0; k < count; k++)
                        {
                            if (reinterpret_cast<::TESFile *>((_streamSize))->IsEndianConversionRequired())
                                reinterpret_cast<::FUN_00535aa0_Class *>(&(oldWeightsB[k]))->FUN_00535aa0();
                            reinterpret_cast<::C53A8A0Owner *>(this)->FUN_0053a8a0((unsigned char)quad7, oldWeightsB[k].vertex, (unsigned short)bPlayerPlayerDead,
                                         oldWeightsB[k].weight);
                        }
                        ::FUN_00401030(oldWeightsB);
                        oldWeightsB = 0;
                    }
                    else
                    {
                        ::FUN_005b5e40();
                        loc1ac = true;
                    }
                }
                quad7 = -1;
                bPlayerPlayerDead = -1;
            }
            break;
        }
    } while (reinterpret_cast<::TESFile *>((_streamSize))->NextChunk());
    if (loc1ac)
        reinterpret_cast<::LayerOwner53a940 *>(this)->FUN_0053a940();
    if (_tilesHeight && !_cNormal)
        ::FUN_005b5e40();
    return true;
}

struct TESForm_rtti2
{
    virtual ~TESForm_rtti2();
    void Revert(unsigned int);
};

struct TESObjectLAND_rtti2 : ::TESForm_rtti2
{
};

struct LandDuplicateCalls
{
};

struct LandDuplicateEntry : LandDuplicateCalls
{
    ::TESForm_rtti2* FUN_00534880(bool createEditorID, void* copyMap);
};

// @fnv 0x00534880
::TESForm_rtti2* LandDuplicateEntry::FUN_00534880(bool createEditorID, void* copyMap)
{
    ::TESObjectLAND_rtti2* duplicate;
    duplicate = dynamic_cast< ::TESObjectLAND_rtti2*>(((::TESForm_rtti2 *)(reinterpret_cast<::FUN_004867a0_cls *>(this)->FUN_004867a0((void *)(false), copyMap))));
    return duplicate;
}

struct TESObjectCELL_rtti2 : ::TESForm_rtti2
{
};

struct LandSaveGroup5391
{
    void* typeTag;
    unsigned int unk04;
    unsigned int formID;
    unsigned int groupType;
};

struct LandSaveCell5391
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual bool ContainsGroup(LandSaveGroup5391* group);
};

struct FUN_005391d0_class
{
    bool FUN_005391d0(LandSaveGroup5391* apGroupFORM);
};

// @fnv 0x005391d0
bool FUN_005391d0_class::FUN_005391d0(LandSaveGroup5391* apGroupFORM)
{
    bool bretval = false;
    if (apGroupFORM && apGroupFORM->typeTag == (*reinterpret_cast<void * *>(&::fnv_00543df0::kGroupFormType)))
    {
        switch (apGroupFORM->groupType)
        {
        case 8:
        case 9: {
            void* found = dynamic_cast< ::TESObjectCELL_rtti2*>(::FUN_004839c0(apGroupFORM->formID));
            if (found && ((::LandSaveCell5391 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430())) == found)
                bretval = false;
            break;
        }
        default: {
            LandSaveCell5391* pCell = ((::LandSaveCell5391 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(this)->FUN_007af430()));
            bretval = pCell->ContainsGroup(apGroupFORM);
            break;
        }
        }
    }
    return bretval;
}

#include "generated/data/fallout_shared/tesland_od_variant.inc"
