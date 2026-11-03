// fallout_shared/tesworldspace.cpp: TESWorldSpace, TESObjectCELL, TESRegion, InterfaceManager and more (90 functions)

#include <cstdint>
#include <new>
#include <cmath>
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSProjectile.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellView.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0040f2a0.h"
#include "fnv/decl/FUN_00416870_t.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00439f90_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00454b30_class.h"
#include "fnv/decl/FUN_00461bc0_cls.h"
#include "fnv/decl/FUN_00472000_class.h"
#include "fnv/decl/FUN_00472150_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_004734d0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f5d90_shell.h"
#include "fnv/decl/FUN_004f6850_Class.h"
#include "fnv/decl/FUN_0050a550_shell.h"
#include "fnv/decl/FUN_0052ce20_shell.h"
#include "fnv/decl/FUN_00544300_Class.h"
#include "fnv/decl/FUN_00544c90_shell.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/FUN_0054b830_cls.h"
#include "fnv/decl/FUN_0054de10_shell.h"
#include "fnv/decl/FUN_00551420_shell.h"
#include "fnv/decl/FUN_005516c0.h"
#include "fnv/decl/FUN_005516f0_Class.h"
#include "fnv/decl/FUN_005890c0.h"
#include "fnv/decl/FUN_0058f080.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_006fc980.h"
#include "fnv/decl/FUN_006fca70_Class.h"
#include "fnv/decl/FUN_00740940_shell.h"
#include "fnv/decl/FUN_00810570_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008d01e0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/GList.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ImpactSwapMaps.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/MoveCell.h"
#include "fnv/decl/MyPoint439180.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/Own61.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/Polygon.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S00551440.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/S_00587f40.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/ThisC.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_0054ca90__Cell.h"
#include "fnv/decl/fnv_0054db50__FUN_0054db50_cls.h"
#include "fnv/decl/fnv_00550200__FUN_00550200.h"
#include "fnv/decl/fnv_00550500__Cell.h"
#include "fnv/decl/fnv_00569880__FUN_00569880_cls.h"
#include "fnv/decl/fnv_0058f180__FUN_0058f180.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_00b5ddf0__LocalTarget.h"
#include "fnv/decl/s54da20__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00439000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00540000.h"
#include "fnv/symbols_00544000.h"
#include "fnv/symbols_00550000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00586000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_006ca000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_01187000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c4000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011de000.h"
#include "tesworldspace_packet.h"
#include <cstring>
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0058f5c0_shell.h"
#include "fnv/decl/CPMap00993a80.h"
#include "fnv/decl/CombatThreatMap.h"
#include "fnv/decl/FUN_00484150_shell.h"
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/SomeClass.h"
#include "fnv/decl/TESFormSortProxy.h"
#include "fnv/decl/UpdateOwner.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_0118a000.h"
#include "fnv/decl/FNV_BucketMap.h"
#include "fnv/decl/FUN_004867a0_cls.h"
#include "fnv/decl/fnv_00484730__FUN_00484730_shell.h"
// @fnv 0x00425fd0
bool TESObjectCELL::IsCellInterior() const
{
    return (flags & 1) ? true : false;
}
// Sets the world space's map name from the given string and returns true.
// @fnv 0x00583330
bool TESWorldSpace::SetDateTimeText(const char* name)
{
    reinterpret_cast<::TextString *>(&(mapName))->FUN_004037f0(name, 0);
    return true;
}
// Returns the terrain manager of the parent world space if one exists, otherwise this world space's own terrain.
// @fnv 0x00586170
BGSTerrainManager* TESWorldSpace::GetWorldTerrainManager()
{
    if (GetParentWorld(USE_LAND))
        return GetParentWorld(USE_LAND)->GetWorldTerrainManager();
    return terrain;
}
// Looks up key in cellMap and returns the stored reference cast to TESObjectCELL, or null if not found.
// @fnv 0x00587630
TESObjectCELL* TESWorldSpace::GetCellByKey(unsigned int key)
{
    TESObjectREFR* cell = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(cellMap))->FUN_00853130(key, (::fnv_00853130::CombatThreatRecord *&)(cell)))
        return (TESObjectCELL*)cell;
    return 0;
}
// @fnv 0x00473ff0
bool TESWorldSpace::IsFormIDOwnedByFile(unsigned int key, TESFile* file)
{
    bool result = true;
    if (DAT_011c40b0 && key)
    {
        TESObjectREFR* value = 0;
        if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(DAT_011c40b0))->FUN_00853130(key, (::fnv_00853130::CombatThreatRecord *&)(value)) && value)
        {
            TESFile* parent = file->GetThreadSafeRootFile();
            if (!parent)
                parent = file;
            if (value != (TESObjectREFR*)parent)
                result = false;
        }
    }
    return result;
}
// Clears night and looping sounds, effect shader, calls three helpers, resets the full name and zeroes 16 bytes at offset 0x80.
// @fnv 0x00586480
void TESWorldSpace::ClearWorldSpaceReferences()
{
    reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>((((BGSAcousticSpace*)this)))->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(::TESSound *)(0));
    ((TESObjectACTI*)this)->SetLoopingSound(0);
    reinterpret_cast<::TESObjectACTI *>((((EffectSetting*)this)))->SetActivateSound((::TESSound *)(::TESEffectShader *)(0));
    FUN_00584150(0.0f);
    FUN_00586110(DAT_01031920);
    FUN_00586130(0.0f);
    ((TESFullName*)((char*)this + 0x24))->SetFullName(0);
    memset((char*)this + 0x80, 0, 16);
}
// Validates x and y are within -32768..32767, builds a key from them, and looks up the cell in cellMap, returning it or null.
// @fnv 0x005875a0
TESObjectCELL* TESWorldSpace::GetCellAtGridPosition(int x, int y)
{
    if (x > 32767 || y > 32767 || x < -32768 || y < -32768)
    {
        ::FUN_005b5e40();
        return 0;
    }
    TESObjectREFR* pCell;
    int iKey = ::PackShortPair((unsigned short)x, (unsigned short)y);
    pCell = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(cellMap))->FUN_00853130(iKey, (::fnv_00853130::CombatThreatRecord *&)(pCell)))
        return (TESObjectCELL*)pCell;
    return 0;
}
// @fnv 0x00586150
Tile* InterfaceManager::FUN_00586150()
{
    return pTile;
}
// @fnv 0x00584bc0
void TESWorldSpace::SetFieldD0(std::uintptr_t value)
{
    fieldD0 = value;
}
// @fnv 0x00586110
void TESWorldSpace::FUN_00586110(float value)
{
    fC8 = value;
}
// @fnv 0x00586130
void TESWorldSpace::FUN_00586130(float value)
{
    fCC = value;
}
// @fnv 0x005861b0
bool TESWorldSpace::GetSmallWorld()
{
    if (flags4C & 1)
        return true;
    return false;
}
// @fnv 0x005862e0
bool TESWorldSpace::IsFlag4C20Set()
{
    if (flags4C & 0x20)
        return true;
    return false;
}
// Sets parent to world and clears field4E when world is null.
// @fnv 0x005863d0
void TESWorldSpace::SetParent(TESWorldSpace* world)
{
    parent = world;
    if (!world)
        field4E = 0;
}
// @fnv 0x00588270
void TESWorldSpace::FUN_00588270(BSSimpleArray<TESObjectREFR*, 1024>& doors)
{
    TESObjectCELL* cell = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    if (cell)
        reinterpret_cast<::fnv_0054db50::FUN_0054db50_cls *>((cell))->FUN_0054db50((::fnv_0054db50::ListArg *)&(doors));
}

struct FUN_005861d0_shell : public TESWorldSpace
{
    void SetFlagBit0(bool);
};

// Sets or clears bit 0 of the byte at offset 0x4c on this TESWorldSpace based on abVal.
// @fnv 0x005861d0
void FUN_005861d0_shell::SetFlagBit0(bool abVal)
{
    if (abVal)
        this->flags4C |= 1;
    else
        this->flags4C &= ~1;
}

// Packs two shorts into one int: asX shifted left 16 bits, OR'd with the low 16 bits of asY.
// @fnv 0x00587410
int __cdecl PackShortPair(short asHigh, short asLow)
{
    int key = asHigh;
    key <<= 16;
    key |= (unsigned short)(asLow & 0xFFFF);
    return key;
}

struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
public:
    bool FUN_004390c0(const ::NiPoint3 &);
public:
    float ComputeMagnitude() const;
};


// @fnv 0x00587440
int __cdecl FUN_00587440(const NiPoint3* aCoord)
{
    int icellx;
    int icelly;

    if (!std::isfinite(aCoord->x) || !std::isfinite(aCoord->y) || !std::isfinite(aCoord->z) || std::isnan(aCoord->x) ||
        std::isnan(aCoord->y) || std::isnan(aCoord->z))
    {
        return 0x7fff7fff;
    }

    icellx = ::FUN_00406d90(aCoord->x) >> 12;
    icelly = ::FUN_00406d90(aCoord->y) >> 12;
    return ::PackShortPair((short)icellx, (short)icelly);
}

int _FNV_GetFormType(void*);

// Returns true if apRef is non-null and its object reference's form type is one of the listed types.
// @fnv 0x00587c80
bool __cdecl FUN_00587c80(void* apRef)
{
    bool bretval = false;
    if (apRef && ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430())))
    {
        switch (_FNV_GetFormType(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apRef))->FUN_007af430()))))
        {
        case 0x0d:
        case 0x15:
        case 0x1b:
        case 0x1c:
        case 0x20:
        case 0x21:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x2c:
        case 0x2d:
            bretval = true;
            break;
        }
    }
    return bretval;
}

struct FUN_00588030_shell : public TESWorldSpace
{
    void FUN_00588030(TESObjectREFR*);
};

struct TESObjectCELL_RemoveReference_Helper : public TESObjectCELL
{
};

// If apRef is non-null, gets the interior cell and calls RemoveReference on it with apRef.
// @fnv 0x00588030
void FUN_00588030_shell::FUN_00588030(TESObjectREFR* apRef)
{
    if (apRef)
    {
        TESObjectCELL* poldcell = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
        if (poldcell)
        {
            reinterpret_cast<::fnv_0054ca90::Cell *>((reinterpret_cast<TESObjectCELL_RemoveReference_Helper*>(poldcell)))->FUN_0054ca90((::fnv_0054ca90::Ref *)(apRef));
        }
    }
}

struct FUN_00588b00_shell : public TESWorldSpace
{
    void* GetOrCreateCellOffsetData(TESFile*);
};


class NiPoint2
{
  public:
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float, float);
};

struct OFFSET_DATA_24
{
    unsigned int pCellOffsets;
    NiPoint2 m_kFirstPoint;
    NiPoint2 m_kEndPoint;
    unsigned int uiFileOffset;

    OFFSET_DATA_24();
};

struct DummyPointerMap
{
};

// @fnv 0x00588b00
void* FUN_00588b00_shell::GetOrCreateCellOffsetData(TESFile* apFile)
{
    OFFSET_DATA_24* pdata = 0;
    TESFile* pmainfile = apFile;
    while (pmainfile && pmainfile->GetThreadSafeRootFile())
    {
        pmainfile = pmainfile->GetThreadSafeRootFile();
    }
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)((char*)this + 0xb0))))->FUN_00853130((std::uintptr_t)pmainfile, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)pdata)) || !pdata)
    {
        pdata = new OFFSET_DATA_24;
        pdata->pCellOffsets = 0;
        pdata->uiFileOffset = 0;
        pdata->m_kFirstPoint = NiPoint2(3.4028234663852886e+38f, 3.4028234663852886e+38f);
        pdata->m_kEndPoint = NiPoint2(::DAT_01015f5c, ::DAT_01015f5c);
        reinterpret_cast<::FUN_00844700_Class *>((((DummyPointerMap*)((char*)this + 0xb0))))->FUN_00844700((std::uintptr_t)pmainfile, (unsigned int)pdata);
    }
    return pdata;
}


// Calls _ref_006815c0 on the two sub-objects at offsets 4 and 0xC of pThis and returns pThis.
// @fnv 0x00588c50
char* FUN_00588c50(char* pThis)
{
    (void *)(pThis + 4);
    (void *)(pThis + 0xC);
    return pThis;
}

extern int DAT_01031fac;

struct FUN_00588fa0_arg
{
    unsigned int val;
};


// Calls FUN_005890c0 on self, then stores the address of DAT_01031fac into *self and returns self.
// @fnv 0x00588fa0
int* FUN_00588fa0(int* self, FUN_00588fa0_arg a)
{
    new ((void *)(self)) struct ::FUN_005890c0((*(unsigned int *)&(const ::FUN_00588fa0_arg &)(a)));
    *self = (int)&DAT_01031fac;
    return self;
}


// @fnv 0x006698d0
void FUN_006698d0(char* pThis)
{
    ::FUN_00559450((int *)(void *)(pThis + 0x6c));
}

struct FUN_005832f0_shell : public TESForm
{
    char* FUN_005832f0();
};

struct Flt
{
    operator unsigned int() const;
};
// Returns the unsigned int at offset 0xc0 as a char pointer, or an empty string when that value is zero.
// @fnv 0x005832f0
char* FUN_005832f0_shell::FUN_005832f0()
{
    return ((Flt*)((char*)this + 0xc0))->operator unsigned int()
               ? (char*)((Flt*)((char*)this + 0xc0))->operator unsigned int()
               : (char*)"";
}

struct FUN_00587670_shell : public TESWorldSpace
{
    bool FUN_00587670(TESObjectCELL*);
};

struct CellH
{
};
struct S54de10
{
};
// @fnv 0x00587670
bool FUN_00587670_shell::FUN_00587670(TESObjectCELL* apCell)
{
    int key;
    TESObjectCELL* ignore;
    if (!apCell || apCell->IsCellInterior())
        return false;
    if (reinterpret_cast<::FUN_005516c0 *>((((CellH*)apCell)))->IsCellPersistent())
    {
        if (*(TESObjectCELL**)&this->m_pCell)
            return false;
        *(TESObjectCELL**)&this->m_pCell = apCell;
    }
    else
    {
        key = ::PackShortPair(reinterpret_cast<::TESObjectCELL *>((((CellH*)apCell)))->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>((((CellH*)apCell)))->GetCellGridY());
        if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)((*(DummyPointerMap**)&this->cellMap)))->FUN_00853130(key, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)ignore)))
        {
            ::FUN_005b5e40();
            return false;
        }
        reinterpret_cast<::FUN_00844700_Class *>(((*(DummyPointerMap**)&this->cellMap)))->FUN_00844700(key, (std::uintptr_t)apCell);
    }
    reinterpret_cast<::FUN_0054de10_shell *>((((S54de10*)apCell)))->FUN_0054de10(this);
    return true;
}

struct FUN_00587e40_shell : public TESWorldSpace
{
    void FUN_00587e40(TESObjectREFR*);
};

template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList<T>* next;
    ~BSSimpleList();
};
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct WsH
{
};
struct ListH
{
    bool _ref_008256d0();
};
struct MapH
{
};
bool __cdecl FUN_00587c80(void*);
// @fnv 0x00587e40
void FUN_00587e40_shell::FUN_00587e40(TESObjectREFR* apRef)
{
    unsigned int ikey;
    BSSimpleList<const char*>* preflist;
    if (apRef && !reinterpret_cast<::FUN_004077c0_shell *>((void *)(apRef))->FUN_004077c0())
    {
        reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::ATM *>(&::g_011ca60c))))->FUN_004538a0(0);
        if (!FUN_00587c80(apRef))
        {
            reinterpret_cast<::ItemChangeListNode *>((((ListH*)((char*)this + 0x60))))->FUN_00905330((*(::InventoryStackRecord *const *)(&apRef)));
        }
        else
        {
            ikey = ::FUN_00587440(
                (const ::NiPoint3 *)&(*((NiPoint3 * (*)(TESObjectREFR*))(*(void***)apRef)[0x1f4 / 4])(apRef)));
            preflist = 0;
            reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)((char*)this + 0x50))))->FUN_00853130(ikey, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)preflist));
            if (preflist)
            {
                reinterpret_cast<::ItemChangeListNode *>((((ListH*)preflist)))->FUN_00905330((*(::InventoryStackRecord *const *)(&apRef)));
                if (((ListH*)preflist)->_ref_008256d0())
                {
                    delete preflist;
                    reinterpret_cast<::NiTMap_S *>((((MapH*)((char*)this + 0x50))))->RemoveKey(ikey);
                }
            }
        }
        reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::ATM *>(&::g_011ca60c))))->WaitForTasksDuringRendering();
    }
}

struct FUN_00588070_shell : public TESWorldSpace
{
    TESObjectCELL* GetOrCreateCell();
};
// If ref is non-null and not temporary, creates a persistent cell and adds ref to it.
// @fnv 0x00587ff0
void TESWorldSpace::AddPersistentReference(TESObjectREFR* ref)
{
    if (ref && !reinterpret_cast<::FUN_004077c0_shell *>((void *)(ref))->FUN_004077c0())
    {
        TESObjectCELL* cell = reinterpret_cast<::FUN_00588070_shell *>(this)->GetOrCreateCell();
        reinterpret_cast<::CellView *>((cell))->FUN_00548230((::RefView *)(ref), false);
    }
}

namespace stub {
struct TESObjectCELL
{
    TESObjectCELL();
    char pad[0xe0];
};
}
struct FUN_005516f0_s
{
};
struct FUN_00544630_shell
{
    void ResetCellData();
};

// Returns the TESObjectCELL stored at offset 0x34, creating and initializing it first if it is null.
// @fnv 0x00588070
TESObjectCELL* FUN_00588070_shell::GetOrCreateCell()
{
    if (!*(stub::TESObjectCELL**)&this->m_pCell)
    {
        *(stub::TESObjectCELL**)&this->m_pCell = new stub::TESObjectCELL;
        reinterpret_cast<::FUN_005516f0_Class *>(((*(FUN_005516f0_s**)&this->m_pCell)))->SetFlag400(1);
        (*(FUN_00544630_shell**)&this->m_pCell)->ResetCellData();
    }
    return *(TESObjectCELL**)&this->m_pCell;
}

struct FileH
{
};

struct FormIDData
{
    unsigned int pad0[5];
    unsigned int formID;
};

extern unsigned char DAT_0118730c;

struct FUN_005858b0_shell
{
    FormIDData* FUN_00588a90(FileH* apFile);
    bool IsFileFormIDMatching(FileH* apFile);
};

// @fnv 0x005858b0
bool FUN_005858b0_shell::IsFileFormIDMatching(FileH* apFile)
{
    FormIDData* pdata = FUN_00588a90(apFile);
    if (apFile && reinterpret_cast<::TESFile *>((apFile))->IsMasterFile() && pdata && pdata->formID)
    {
        if (reinterpret_cast<::TESOffsetWorker *>((apFile))->FUN_004723a0(pdata->formID))
        {
            if (((unsigned int)(reinterpret_cast<::FUN_00472660_shell *>((apFile))->FUN_00472660())) == DAT_0118730c)
            {
                if (((unsigned int)(reinterpret_cast<::MiddleHighProcess *>((apFile))->GetFaceGenHeadNode())) == ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this))->FUN_0084e3a0())))
                    return true;
            }
        }
    }
    return false;
}

struct TESClimate
{
    virtual ~TESClimate();  // polymorphic: its RTTI is used (rtti_fix.py)
};

class FUN_00585fe0_shell : public TESWorldSpace
{
  public:
    TESClimate* FUN_00585fe0();
};

// Returns the climate of the parent world if one exists, otherwise the climate stored at offset 0x40 of this world space.
// @fnv 0x00585fe0
TESClimate* FUN_00585fe0_shell::FUN_00585fe0()
{
    if (GetParentWorld(PARENT_USE_FLAG(4)))
        return ((FUN_00585fe0_shell*)GetParentWorld(PARENT_USE_FLAG(4)))->FUN_00585fe0();
    return *reinterpret_cast<TESClimate**>(&this->unk40);
}

struct FUN_00586020_shell
{
    char pad[0x44];
    TESWorldSpace* field44;
    TESWorldSpace* GetParentWorld(TESWorldSpace::PARENT_USE_FLAG);
    TESWorldSpace* GetWorldSpaceOrParentWorld();
};

// Returns field44 if set, otherwise recurses into the parent world space obtained via GetParentWorld with flag 5, or returns null.
// @fnv 0x00586020
TESWorldSpace* FUN_00586020_shell::GetWorldSpaceOrParentWorld()
{
    TESWorldSpace* result = field44;
    if (!result)
    {
        if (GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(5)))
        {
            result =
                reinterpret_cast<FUN_00586020_shell*>(GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(5)))
                    ->GetWorldSpaceOrParentWorld();
        }
    }
    return result;
}

struct FUN_00586210_shell
{
    unsigned char cFlags;
    bool HasFlag2();
};

// @fnv 0x00586210
bool FUN_00586210_shell::HasFlag2()
{
    if (((unsigned char)(*((unsigned char*)this + 0x4c)) & 2))
        return true;
    return false;
}

struct ArrSI
{
    char HasFlag80000();
};

// @fnv 0x00586230
char ArrSI::HasFlag80000()
{
    unsigned int flags = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName()));
    if (flags & 0x80000)
        return 1;
    return 0;
}

struct FUN_00586260_shell
{
    bool IsFlag8Set();
};

// @fnv 0x00586260
bool FUN_00586260_shell::IsFlag8Set()
{
    if (((unsigned char*)this)[0x4c] & 8)
        return 1;
    return 0;
}

struct FUN_00586280_shell
{
    unsigned char bFlags;  // +0x4c
    void SetFlag8(bool bFlag);
};
// @fnv 0x004f1260
void TESRegion::AssignWorldSpace(TESWorldSpace* apWorldSpace)
{
    world = apWorldSpace;
    if (world && reinterpret_cast<::FUN_00549580_shell *>(this)->FUN_00549580() && !(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->LoadDescriptionForForm())
        reinterpret_cast<::FUN_00586280_shell *>((world))->SetFlag8(true);
}

// Sets or clears bit 3 (0x8) of the byte at offset 0x4c on this object based on bFlag.
// @fnv 0x00586280
void FUN_00586280_shell::SetFlag8(bool bFlag)
{
    if (bFlag)
        ((unsigned char*)this)[0x4c] |= 8;
    else
        ((unsigned char*)this)[0x4c] &= ~8;
}

struct FUN_005862c0_shell
{
    unsigned char cFlags;  // +0x4c
    bool IsFlagSet();
};

// @fnv 0x005862c0
bool FUN_005862c0_shell::IsFlagSet()
{
    if (((unsigned char*)((char*)this + 0x4c))[0] & 0x10)
        return 1;
    return 0;
}

struct FUN_00586300_shell
{
    char IsFlag80Set();
};

// Returns 1 if the byte at offset 0x4c has bit 0x80 set, otherwise 0.
// @fnv 0x00586300
char FUN_00586300_shell::IsFlag80Set()
{
    if ((*(unsigned char*)(this + 0x4c) & 0x80) != 0)
        return 1;
    return 0;
}

struct FUN_00586320_shell
{
    bool FUN_00586320();
};

// @fnv 0x00586320
bool FUN_00586320_shell::FUN_00586320()
{
    if ((*(unsigned char*)((char*)this + 0x4c) & 0x40) != 0)
        return false;
    return true;
}

struct FNStub
{
};

struct FUN_00586440_shell : TESWorldSpace
{
    const char* FUN_00586440();
};

// Returns the full name of the parent worldspace if one exists, otherwise the full name of this worldspace.
// @fnv 0x00586440
const char* FUN_00586440_shell::FUN_00586440()
{
    if (this->GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(2)))
    {
        return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(((reinterpret_cast<FNStub*>(
                    reinterpret_cast<char*>(this->GetParentWorld(static_cast<TESWorldSpace::PARENT_USE_FLAG>(2))) +
                    0x24))))->FUN_00408da0()));
    }
    return ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(((reinterpret_cast<FNStub*>(reinterpret_cast<char*>(this) + 0x24))))->FUN_00408da0()));
}

struct StartMenu
{
    char const* GetMenuTitle();
};


// @fnv 0x00586980
char const* FUN_00586980()
{
    return (*reinterpret_cast<::StartMenu *>(&::g_011ca130)).GetMenuTitle();
}

// Splits a 32-bit value into its high and low 16-bit halves, storing the high half in *b and the low half in *c.
// @fnv 0x00587520
void SplitUInt32(unsigned int auiValue, unsigned short* b, unsigned short* c)
{
    *b = (unsigned short)((auiValue >> 0x10) & 0xffff);
    *c = (unsigned short)(auiValue & 0xffff);
}

namespace fnv_00587550 {
extern "C"
{
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct FUN_00587550_shell : TESWorldSpace
{
    TESObjectCELL* FUN_00587550(const NiPoint3& aCoord);
};

// @fnv 0x00587550
TESObjectCELL* FUN_00587550_shell::FUN_00587550(const NiPoint3& aCoord)
{
    int icellx = ::FUN_00406d90(aCoord.x) >> 12;
    int icelly = ::FUN_00406d90(aCoord.y) >> 12;
    return GetCellAtGridPosition(icellx, icelly);
}
}  // namespace fnv_00587550

extern "C"
{
    struct TESWaterForm;
}


// @fnv 0x00586070
TESWaterForm* FUN_00586070(TESWorldSpace* apWorldSpace)
{
    if (apWorldSpace->GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)3))
        return FUN_00586070(apWorldSpace->GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)3));
    if (*(TESWorldSpace**)&apWorldSpace->unk74)
        return (TESWaterForm*)*(TESWorldSpace**)&apWorldSpace->unk74;
    return ::DAT_011ca53c;
}

template <class T> class BSSimpleList;

struct FUN_0054b8c0_shell
{
    void AddStaticRefsToList(BSSimpleList<const char*>*);
};

struct FUN_00588520_shell
{
    void FUN_00588520(BSSimpleList<const char*>*);
};

// If list is non-null, gets the interior cell from this world space and forwards the list to the cell's method.
// @fnv 0x00588520
void FUN_00588520_shell::FUN_00588520(BSSimpleList<const char*>* list)
{
    if (list)
    {
        TESObjectCELL* cell = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((((TESWorldSpace*)this)))->GetPrevPath()));
        if (cell)
        {
            ((FUN_0054b8c0_shell*)cell)->AddStaticRefsToList(list);
        }
    }
}

template <int N> struct EndianSizeTag
{
};


struct FUN_005840b0_shell
{
    void FUN_005840b0();
};

// Byte-swaps the two ints and four shorts stored in this object via BSEndian.
// @fnv 0x005840b0
void FUN_005840b0_shell::FUN_005840b0()
{
    ::FUN_00401080((int*)this);
    ::FUN_00401080((int*)(this + 4));
    ::FUN_00407a90((short *)(unsigned short *)((unsigned short*)(this + 8)));
    ::FUN_00407a90((short *)(unsigned short *)((unsigned short*)(this + 0xa)));
    ::FUN_00407a90((short *)(unsigned short *)((unsigned short*)(this + 0xc)));
    ::FUN_00407a90((short *)(unsigned short *)((unsigned short*)(this + 0xe)));
}

struct Modifier
{
};
struct AlphaColor
{
};
struct FUN_004f6fc0_shell
{
    int _a;
    int _b;
    void FUN_004f6fc0();
};
struct FUN_004f6850_shell
{
};
struct FUN_004f6800_shell
{
    void FUN_004f6800(void*, float*, void*);
};
// @fnv 0x004f6800
void FUN_004f6800_shell::FUN_004f6800(void* a1, float* a2, void* a3)
{
    FUN_004f6fc0_shell tmp;
    tmp.FUN_004f6fc0();
    reinterpret_cast<::FUN_0052ce20_shell *>((((AlphaColor*)&tmp)))->FUN_0052ce20(a2[0]);
    reinterpret_cast<::FUN_004f5d90_shell *>((((Modifier*)&tmp)))->FUN_004f5d90(a2[1]);
    reinterpret_cast<::FUN_004f6850_Class *>((((FUN_004f6850_shell*)this)))->FUN_004f6850((std::intptr_t)(a1), (int)(&tmp), (int)(a3));
}

struct FUN_00528560_Host
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual TESObjectCELL* v5(unsigned int) = 0;
    TESObjectCELL* GetCellAtGridCoord(unsigned short, unsigned short);
};
// Computes a grid key from the X and Y coordinates and returns the cell obtained from v5 for that key.
// @fnv 0x00528560
TESObjectCELL* FUN_00528560_Host::GetCellAtGridCoord(unsigned short ausGridX, unsigned short ausGridY)
{
    int key;
    key = ::PackShortPair(ausGridX, ausGridY);
    return v5(key);
}

struct FUN_00582e00_host
{
    void FUN_00582e30();
    void* FUN_00582e00(unsigned int);
};
struct S_00583040
{
    void* FUN_00583040(unsigned int);
};
// Calls FUN_006fc980, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00583040
void* S_00583040::FUN_00583040(unsigned int flags)
{
    reinterpret_cast<::FUN_006fc980 *>(this)->::FUN_006fc980::~FUN_006fc980();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_00584530 {
struct FileH;

struct FormIDData
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
};

struct FUN_005858b0_shell
{
    FormIDData* FUN_00588a90(FileH*);
    int FUN_00584530(FileH* file, int x, int y);
};

// @fnv 0x00584530
int FUN_005858b0_shell::FUN_00584530(FileH* file, int x, int y)
{
    FormIDData* pdata = FUN_00588a90(file);
    if (!pdata)
        return -1;
    int iminX = (int)pdata->f4 >> 12;
    int iminY = (int)pdata->f8 >> 12;
    int imaxX = (int)pdata->fc >> 12;
    int imaxY = (int)pdata->f10 >> 12;
    if (x > imaxX || x < iminX || y > imaxY || y < iminY)
        return -1;
    return (imaxX - iminX + 1) * (y - iminY) + x - iminX;
}
}  // namespace fnv_00584530

class TESWaterForm;
struct FUN_005860c0_shell : TESWorldSpace
{
    TESWaterForm* FUN_005860c0();
};
// @fnv 0x005860c0
TESWaterForm* FUN_005860c0_shell::FUN_005860c0()
{
    if (GetParentWorld(TESWorldSpace::USE_LAND))
        return ((FUN_005860c0_shell*)GetParentWorld(TESWorldSpace::USE_LAND))->FUN_005860c0();
    if (*(TESWaterForm**)&this->unk78)
        return *(TESWaterForm**)&this->unk78;
    return ::DAT_011ca53c;
}

struct Unk00586340
{
    bool FUN_00586340(int);
};
// Returns parent if it exists and GetParentUseFlag(flag) is set, otherwise returns null.
// @fnv 0x00586390
TESWorldSpace* TESWorldSpace::GetParentWorld(PARENT_USE_FLAG aeParentUseFlag)
{
    if (parent && !reinterpret_cast<::Unk00586340 *>(this)->FUN_00586340((*(int *)&(aeParentUseFlag))))
        return 0;
    return parent;
}
// Returns true if a is outside 0..5 or if the bit for a is set in the 16-bit mask at offset 0x4E of this.
// @fnv 0x00586340
bool Unk00586340::FUN_00586340(int aiIndex)
{
    if (aiIndex >= 0 && aiIndex < 6)
    {
        unsigned char mask = 1 << aiIndex;
        if (*(unsigned short*)((char*)this + 0x4E) & mask)
            return true;
        return false;
    }
    return true;
}

struct PointerPairData;
struct FUN_00586400_shell : TESWorldSpace
{
    PointerPairData* FUN_00586400();
};
// Returns the parent world's result if GetParentWorld(2) is set, otherwise returns this object offset by 0x80.
// @fnv 0x00586400
PointerPairData* FUN_00586400_shell::FUN_00586400()
{
    if (GetParentWorld((PARENT_USE_FLAG)2))
        return ((FUN_00586400_shell*)GetParentWorld((PARENT_USE_FLAG)2))->FUN_00586400();
    return (PointerPairData*)((char*)this + 0x80);
}

namespace fnv_00587760 {
struct CellH
{
};
struct MapH
{
};
struct DummyPointerMap
{
};
struct S54de10
{
};

struct FUN_00587760_shell : TESWorldSpace
{
    void RemoveCellFromMap(TESObjectCELL* cell);
};

// @fnv 0x00587760
void FUN_00587760_shell::RemoveCellFromMap(TESObjectCELL* cell)
{
    if (!cell || cell->IsCellInterior())
        return;

    unsigned int entry7;
    unsigned int key = ::PackShortPair((short)reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(cell)))->GetCellGridX(),
                                                   (short)reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(cell)))->GetCellGridY());

    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(reinterpret_cast<DummyPointerMap*>(cellMap)))->FUN_00853130(key, (::fnv_00853130::CombatThreatRecord *&)(entry7)) &&
        cell == reinterpret_cast<TESObjectCELL*>(entry7))
    {
        reinterpret_cast<::NiTMap_S *>((reinterpret_cast<MapH*>(cellMap)))->RemoveKey(key);
        reinterpret_cast<::FUN_0054de10_shell *>((reinterpret_cast<S54de10*>(cell)))->FUN_0054de10(0);
    }
}
}  // namespace fnv_00587760

namespace fnv_00587870 {
struct CellH
{
};
struct DummyPointerMap
{
};
template <class T> struct BSSimpleList
{
};
struct OverlapHolder
{
    char pad[0x68];
    DummyPointerMap* map68;
    BSSimpleList<TESObjectREFR*>* FUN_00587870(CellH* apCell);
};
// Looks up the cell's key in map68 and returns the stored TESObjectREFR list, or null if map68 is unset.
// @fnv 0x00587870
BSSimpleList<TESObjectREFR*>* OverlapHolder::FUN_00587870(CellH* apCell)
{
    BSSimpleList<TESObjectREFR*>* preflist = 0;
    unsigned int ikey;
    if (map68)
    {
        ikey = ::PackShortPair(reinterpret_cast<::TESObjectCELL *>((apCell))->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>((apCell))->GetCellGridY());
        reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(map68))->FUN_00853130(ikey, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)preflist));
    }
    return preflist;
}
}  // namespace fnv_00587870

struct CellCaller
{
};
struct FUN_00588120_host
{
    void FUN_00588120();
};
// Gets the interior cell from this worldspace and, if one exists, calls MoveReferencesToWorldCells on it with this worldspace.
// @fnv 0x00588120
void FUN_00588120_host::FUN_00588120()
{
    TESObjectCELL* cell = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>((((TESWorldSpace*)this)))->GetPrevPath()));
    if (cell)
        reinterpret_cast<::MoveCell *>((((CellCaller*)cell)))->MoveReferencesToWorldCells((::MoveWorld *)(::TESWorldSpace *)((TESWorldSpace*)this));
}

struct FUN_005884e0_owner : TESWorldSpace
{
    void FUN_005884e0(TESObjectREFR*);
};
struct CellProxy
{
};
// If a1 is non-null and the world space has an interior cell, forwards a1 to that cell's FUN_0054b830.
// @fnv 0x005884e0
void FUN_005884e0_owner::FUN_005884e0(TESObjectREFR* apRef)
{
    TESObjectCELL* cell;
    if (apRef != 0)
    {
        cell = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
        if (cell != 0)
        {
            reinterpret_cast<::FUN_0054b830_cls *>((reinterpret_cast<CellProxy*>(cell)))->FUN_0054b830((::ListArg *)(apRef));
        }
    }
}

namespace fnv_00588a90 {
struct DummyPointerMap
{
};
struct FormIDData
{
    int dummy;
};
struct TESWorldSpace_shell
{
    FormIDData* FUN_00588a90(TESFile* file);
};
// @fnv 0x00588a90
FormIDData* TESWorldSpace_shell::FUN_00588a90(TESFile* file)
{
    FormIDData* result = 0;
    TESFile* current = file;
    while (current && current->GetThreadSafeRootFile())
        current = current->GetThreadSafeRootFile();
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(((DummyPointerMap*)((char*)this + 0xb0))))->FUN_00853130((std::uintptr_t)current, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)result)))
        result = 0;
    return result;
}
}  // namespace fnv_00588a90

struct BGSCameraPath;
struct BGSCameraShot;
struct NiFormArray;
struct PerkEntryConditionSet;
struct CameraPathManager
{
    void InitializeCameraPaths();
    static BGSCameraPath* GetTextureResourcePath();
    void AddCameraPath(BGSCameraPath*);
    void UpdateCameraPaths();
    void ClearCameraPaths();
    NiFormArray* GetRootPathArray();
    BGSCameraPath* SetCameraPathEnabled(TESObjectREFR*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char m_kCameraPathArray[24];
    char m_kCameraPathList[16];
};
struct FUN_0095f530_shell : public CameraPathManager
{
    BGSCameraPath* FUN_0095f530(TESObjectREFR*, TESObjectREFR*);
};

struct Caller_0095f590
{
    BGSCameraPath* FUN_0095f590(unsigned int);
};
// @fnv 0x0095f530
BGSCameraPath* FUN_0095f530_shell::FUN_0095f530(TESObjectREFR* apActionRef, TESObjectREFR* apTargetRef)
{
    unsigned char nv;
    if ((unsigned char)apActionRef)
    {
        nv = *(unsigned char*)((char*)this + 0x680) | (unsigned int)apTargetRef;
    }
    else
    {
        nv = (unsigned char)~(unsigned char)apTargetRef;
        nv = *(unsigned char*)((char*)this + 0x680) & nv;
    }
    return ((Caller_0095f590*)this)->FUN_0095f590(nv);
}

namespace fnv_00582c20 {
struct TESFormBase
{
    TESFormBase();
    ~TESFormBase();
    virtual void V();
    int x[5];
};
namespace stand {
struct TESFullName
{
    TESFullName();
    ~TESFullName();
    virtual void V();
    int x[2];
};
}
struct TESTexture
{
    TESTexture();
    ~TESTexture();
    virtual void V();
    int x[2];
};
struct FUN_0057cd10
{
    FUN_0057cd10();
    ~FUN_0057cd10();
    int x;
};
struct FUN_00588fa0
{
    FUN_00588fa0(unsigned int);
    ~FUN_00588fa0();
    int x[4];
};
struct SL
{
    SL();
    ~SL();
    int x[2];
};
struct GO
{
    GO(int);
    ~GO();
    int x;
};
struct FUN_006815c0
{
    float x, y;
    FUN_006815c0();
};
struct FUN_00588fd0
{
    FUN_00588fd0(int);
    ~FUN_00588fd0();
    int x[4];
};
struct StrMem
{
    StrMem();
    ~StrMem();
    int x[2];
};
struct FUN_00589000
{
    FUN_00589000(unsigned int);
    int x[4];
};
struct SFTX
{
};
struct FUN_00582c20 : public TESFormBase, public stand::TESFullName, public TESTexture
{
    FUN_00589000* pCellNavMeshInfoMap;
    void* m_pCell;
    FUN_0057cd10 m_kFirstTreeComponent;
    void* m_pThirdTreePointer;
    int pad40[4];
    FUN_00588fa0 m_kSecondTreeComponent;
    SL m_kThirdTreeComponent;
    void* m_pFourthTreePointer;
    GO m_kFourthTreeComponent;
    int pad70[12];
    FUN_006815c0 m_kFirstPoint;
    FUN_006815c0 m_kEndPoint;
    FUN_00588fd0 OffsetDataMap;
    StrMem name;
    int padc8[3];
    TESTexture CanopyShadowTexture;
    TESTexture m_kLeafShadowTexture;
    FUN_00582c20();
    void FUN_00583070();
};

// @fnv 0x00582c20
FUN_00582c20::FUN_00582c20() : m_kSecondTreeComponent(0x25), m_kFourthTreeComponent(0), OffsetDataMap(0x25)
{
    reinterpret_cast<::FUN_004f15a0_shell *>((((SFTX*)this)))->FUN_004f15a0(0x41);
    m_pThirdTreePointer = 0;
    pCellNavMeshInfoMap = new FUN_00589000(0x25);
    m_pFourthTreePointer = 0;
    m_pCell = 0;
    m_kFirstPoint.y = 3.4028234663852886e+38f;
    m_kFirstPoint.x = 3.4028234663852886e+38f;
    m_kEndPoint.y = ::DAT_01015f5c;
    m_kEndPoint.x = ::DAT_01015f5c;
    FUN_00583070();
}
}  // namespace fnv_00582c20

namespace fnv_005857b0 {
struct FileH
{
    int m_uiData;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};
struct FUN_005858b0_shell
{
};
struct FUN_005857b0_shell : FUN_005858b0_shell
{
    void FUN_005857b0(int a, int b);
};
// @fnv 0x005857b0
void FUN_005857b0_shell::FUN_005857b0(int a, int aiDelta)
{
    FileH* p = ((::fnv_005857b0::FileH *)(reinterpret_cast<::fnv_00588a90::TESWorldSpace_shell *>(this)->FUN_00588a90((::TESFile *)(a))));
    if (p && p->m_uiData && aiDelta)
    {
        int i2 = (int)p->m_fVectorY >> 12;
        int i3 = (int)p->m_fVectorZ >> 12;
        int i1 = (int)p->m_fScalarPart >> 12;
        int i0 = (int)p->m_fVectorX >> 12;
        for (int i = i2; i <= i1; i++)
        {
            for (int j = i3; j <= i0; j++)
            {
                int k = reinterpret_cast<::fnv_00584530::FUN_005858b0_shell *>(this)->FUN_00584530((::fnv_00584530::FileH *)(a), i, j);
                if (k >= 0 && ((int*)p->m_uiData)[k])
                    ((int*)p->m_uiData)[k] += aiDelta;
            }
        }
    }
}
}  // namespace fnv_005857b0

struct MapX
{
};
struct List_009e03e0
{
    ~List_009e03e0();
};
struct MyMap
{
    virtual ~MyMap();
};
struct NiTMap
{
};
struct FUN_00587bb0_shell
{
    void DestroyMapEntries();
};
// Iterates the map at this+0x68, deletes each non-null value list, then clears and deletes the map and nulls the pointer.
// @fnv 0x00587bb0
void FUN_00587bb0_shell::DestroyMapEntries()
{
    if (*(MapX**)((char*)this + 0x68))
    {
        void* pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)*(MapX**)((char*)this + 0x68))))->GetFirstPos();
        while (pos)
        {
            void* key = 0;
            void* val = 0;
            reinterpret_cast<::C6b7f20_Map *>((((NiTMap*)*(MapX**)((char*)this + 0x68))))->FUN_006b7f20((::C6b7f20_Node **)&(pos), (unsigned int *)&((unsigned int&)key), (void **)&(val));
            if (val)
            {
                reinterpret_cast<::FileMatchList *>((((List_009e03e0*)val)))->RemoveAll();
                delete (List_009e03e0*)val;
            }
        }
        reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)*(MapX**)((char*)this + 0x68))))->FUN_00438af0();
        delete (MyMap*)*(MapX**)((char*)this + 0x68);
        *(MapX**)((char*)this + 0x68) = 0;
    }
}

namespace fnv_00588c80 {
struct MapX
{
};
struct MyMap
{
};
struct NiTMap
{
};
struct FUN_00588c80
{
    void PerformNoArgumentOperation();
};
// Iterates the map at offset 0xb0, deallocating each entry's referenced object and the entry itself, then clears the map.
// @fnv 0x00588c80
void FUN_00588c80::PerformNoArgumentOperation()
{
    void* iterA = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)((char*)this + 0xb0))))->GetFirstPos();
    while (iterA)
    {
        void* preflist9 = 0;
        unsigned int iignore5 = 0;
        reinterpret_cast<::C6b7f20_Map *>((((NiTMap*)((char*)this + 0xb0))))->FUN_006b7f20((::C6b7f20_Node **)&(iterA), (unsigned int *)&(iignore5), (void **)&(preflist9));
        void* ref = *(void**)preflist9;
        ::FUN_00401030(ref);
        void* p2 = preflist9;
        ::FUN_00401030(p2);
    }
    reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)((char*)this + 0xb0))))->FUN_00438af0();
}
}  // namespace fnv_00588c80

namespace fnv_00583070 {
struct FUN_00583070_shell : public TESWorldSpace
{
    void FUN_00583070();
};

struct FUN_005861d0_shell
{
};

struct GO
{
    void operator=(void*);
};

struct FormProxy : TESForm
{
};

struct WorldSpaceVirtual
{
    virtual void Call();
};

// @fnv 0x00583070
void FUN_00583070_shell::FUN_00583070()
{
    *reinterpret_cast<void**>(&this->parent) = 0;
    *reinterpret_cast<void**>(reinterpret_cast<char*>(this) + 0xd0) = 0;
    this->flags4C = 0;
    this->field4E = 0;

    if (!reinterpret_cast<::TESForm *>((reinterpret_cast<FormProxy*>(this)))->IsReservedFormID())
        reinterpret_cast<::FUN_005861d0_shell *>((reinterpret_cast<FUN_005861d0_shell*>(this)))->SetFlagBit0(true);

    this->unk40 = 0;
    this->unk44 = 0;
    this->unk74 = 0;
    this->unk78 = 0;
    this->unk7c = 0.0f;
    this->unk90 = 1.0f;
    this->unk94 = 0.0f;
    this->unk98 = 0.0f;

    ClearWorldSpaceReferences();

    this->unk9c = 0;
    this->unk48 = 0;
    this->fC8 = DAT_01031920;
    this->fCC = 0.0f;

    reinterpret_cast<GO*>(reinterpret_cast<char*>(this) + 0x6c)->operator=(0);

    reinterpret_cast<WorldSpaceVirtual*>(reinterpret_cast<char*>(this) + 0xd4)->Call();
    reinterpret_cast<WorldSpaceVirtual*>(reinterpret_cast<char*>(this) + 0xe0)->Call();
}
}  // namespace fnv_00583070

struct GO
{
    operator unsigned int() const;
    void operator=(void*);
};

struct A51BF0Base
{
};

struct FUN_00c5a9d0 : A51BF0Base
{
    unsigned char padding[0x78];
    FUN_00c5a9d0();
};

extern unsigned int _data_011c16bc;

struct FUN_005831d0_shell
{
    unsigned char padding[0x6c];
    GO go;

    unsigned int GetOrCreateObject();
};

// Returns the stored object pointer, allocating and storing a new FUN_00c5a9d0 first if it is null.
// @fnv 0x005831d0
unsigned int FUN_005831d0_shell::GetOrCreateObject()
{
    if (!static_cast<unsigned int>(this->go))
    {
        this->go.operator=(new FUN_00c5a9d0());
    }

    return static_cast<unsigned int>(this->go);
}

namespace fnv_00588150 {
struct CellH
{
};

struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};


struct DummyPointerMap
{
};

struct BSSimpleList
{
    bool _ref_008256d0();
};

struct BSOcclusionPlane
{

    virtual void V0() = 0;
    virtual void V1() = 0;
    virtual void V2() = 0;
    virtual void V3() = 0;
    virtual void V4() = 0;
    virtual void V5() = 0;
    virtual void V6() = 0;
    virtual void V7() = 0;
    virtual void V8() = 0;
    virtual void V9() = 0;
    virtual void V10() = 0;
    virtual void V11() = 0;
    virtual void V12() = 0;
    virtual void V13() = 0;
    virtual void V14() = 0;
    virtual void V15() = 0;
    virtual void V16() = 0;
    virtual void V17() = 0;
    virtual void V18() = 0;
    virtual void V19() = 0;
    virtual void V20() = 0;
    virtual void V21() = 0;
    virtual void V22() = 0;
    virtual void V23() = 0;
    virtual void V24() = 0;
    virtual void V25() = 0;
    virtual void V26() = 0;
    virtual void V27() = 0;
    virtual void V28() = 0;
    virtual void V29() = 0;
    virtual void V30() = 0;
    virtual void V31() = 0;
    virtual void V32() = 0;
    virtual void V33() = 0;
    virtual void V34() = 0;
    virtual void V35() = 0;
    virtual void V36() = 0;
    virtual void V37() = 0;
    virtual void V38() = 0;
    virtual void V39() = 0;
    virtual void V40() = 0;
    virtual void V41() = 0;
    virtual void V42() = 0;
    virtual void V43() = 0;
    virtual void V44() = 0;
    virtual void V45() = 0;
    virtual void V46() = 0;
    virtual void V47() = 0;
    virtual void V48() = 0;
    virtual void V49() = 0;
    virtual void V50() = 0;
    virtual void V51() = 0;
    virtual void V52() = 0;
    virtual void V53() = 0;
    virtual void V54() = 0;
    virtual void V55() = 0;
    virtual void V56() = 0;
    virtual void V57() = 0;
    virtual void V58() = 0;
    virtual void V59() = 0;
    virtual void V60() = 0;
    virtual void V61() = 0;
    virtual void V62() = 0;
    virtual void V63() = 0;
    virtual void V64() = 0;
    virtual void V65() = 0;
    virtual void V66() = 0;
    virtual void V67() = 0;
    virtual void V68() = 0;
    virtual void V69() = 0;
    virtual void V70() = 0;
    virtual void V71() = 0;
    virtual void V72() = 0;
    virtual void V73() = 0;
    virtual void V74() = 0;
    virtual void V75() = 0;
    virtual void V76() = 0;
    virtual void V77() = 0;
    virtual void V78() = 0;
    virtual void V79() = 0;
    virtual void V80() = 0;
    virtual void V81() = 0;
    virtual void V82() = 0;
    virtual void V83() = 0;
    virtual void V84() = 0;
    virtual void V85() = 0;
    virtual void V86() = 0;
    virtual void V87() = 0;
    virtual void V88() = 0;
    virtual void V89() = 0;
    virtual void V90() = 0;
    virtual void V91() = 0;
    virtual void V92() = 0;
    virtual void V93() = 0;
    virtual void V94() = 0;
    virtual void V95() = 0;
    virtual void V96() = 0;
    virtual void V97() = 0;
    virtual void V98() = 0;
    virtual void V99() = 0;
    virtual void V100() = 0;
    virtual void V101() = 0;
    virtual void V102() = 0;
    virtual void V103() = 0;
    virtual void V104() = 0;
    virtual void V105() = 0;
    virtual void V106() = 0;
    virtual void V107() = 0;
    virtual void V108() = 0;
    virtual void V109() = 0;
    virtual void V110() = 0;
    virtual void V111() = 0;
    virtual void V112() = 0;
    virtual void V113() = 0;
    virtual void V114() = 0;
    virtual void V115() = 0;
    virtual void V116() = 0;
    virtual void V117() = 0;
    virtual void V118() = 0;
    virtual void V119() = 0;
    virtual void V120() = 0;
    virtual void V121() = 0;
    virtual void V122() = 0;
    virtual void V123() = 0;
    virtual void V124() = 0;

    virtual TESObjectREFR* FUN_0125() = 0;
};

struct FUN_00550200_shell : public TESObjectCELL
{
};

struct FUN_00588150_shell : public TESWorldSpace
{
    void AddCellReferences(TESObjectCELL*);
};

// Looks up the cell's reference list by key and adds each reference to the cell, filtering the second list by cull result and a cell check.
// @fnv 0x00588150
void FUN_00588150_shell::AddCellReferences(TESObjectCELL* cell)
{
    BSSimpleList* pCurrentElementNext;
    unsigned int ikey;

    if (cell != 0)
    {
        reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_00588150::ATM *>(&::g_011ca60c))))->FUN_004538a0(0);
        ikey = ::PackShortPair(reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(cell)))->GetCellGridX(),
                                           reinterpret_cast<::TESObjectCELL *>((reinterpret_cast<CellH*>(cell)))->GetCellGridY());

        {
            TESObjectREFR* pref;
            pCurrentElementNext = 0;
            reinterpret_cast<::fnv_00853130::NiTMapBase *>((reinterpret_cast<DummyPointerMap*>(reinterpret_cast<char*>(this) + 0x50)))->FUN_00853130(ikey, (::fnv_00853130::CombatThreatRecord *&)(reinterpret_cast<unsigned int&>(pCurrentElementNext)));

            while (pCurrentElementNext != 0 && !pCurrentElementNext->_ref_008256d0())
            {
                pref = *((::TESObjectREFR **)((void *)(pCurrentElementNext)));
                reinterpret_cast<::CellView *>((cell))->FUN_00548230((::RefView *)(pref), false);
                pCurrentElementNext = ((::fnv_00588150::BSSimpleList *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
            }
        }

        {
            TESObjectREFR* pref;
            pCurrentElementNext = reinterpret_cast<BSSimpleList*>(reinterpret_cast<char*>(this) + 0x60);

            while (pCurrentElementNext != 0 && !pCurrentElementNext->_ref_008256d0())
            {
                pref = *((::TESObjectREFR **)((void *)(pCurrentElementNext)));

                if (((int)(reinterpret_cast<::LowProcess *>((void *)(reinterpret_cast<BSOcclusionPlane*>(pref)))->GetTarget())) != reinterpret_cast<int>(cell))
                {
                    if (reinterpret_cast<::fnv_00550200::FUN_00550200 *>((reinterpret_cast<FUN_00550200_shell*>(cell)))->IsPointInCell(
                            (*(const ::fnv_00550200::NiPoint3 *)(reinterpret_cast<BSOcclusionPlane*>(pref)->FUN_0125()))))
                    {
                        reinterpret_cast<::CellView *>((cell))->FUN_00548230((::RefView *)(pref), false);
                    }
                }

                pCurrentElementNext = ((::fnv_00588150::BSSimpleList *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
            }
        }

        reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_00588150::ATM *>(&::g_011ca60c))))->WaitForTasksDuringRendering();
    }
}
}  // namespace fnv_00588150

namespace fnv_00588560 {
class NiTMap
{
  public:
};

class MapX : public NiTMap
{
  public:
};


class FUN_00588560_entry
{
  public:
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
    virtual const char* f76() = 0;
};

struct FUN_00588560_shell
{
    unsigned char pad[0x30];
    MapX* map;

    void* FindEntryByName(const char* name);
};

// Iterates the map's entries and returns the first whose f76() string matches name case-insensitively, or null.
// @fnv 0x00588560
void* FUN_00588560_shell::FindEntryByName(const char* name)
{
    void* result2 = 0;
    void* position;

    if (name)
    {
        position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((this->map))->GetFirstPos();

        while (position && !result2)
        {
            void* value3 = 0;
            unsigned int key;
            reinterpret_cast<::C6b7f20_Map *>((this->map))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(key), (void **)&(value3));

            if (value3)
            {
                if (::FUN_00404dc0(static_cast<FUN_00588560_entry*>(value3)->f76(), name) == 0)
                {
                    result2 = value3;
                }
            }
        }
    }

    return result2;
}
}  // namespace fnv_00588560

struct HelperAt6c
{
    void FUN_0066b0d0(int mode);
};
struct RefAt48
{
};
struct FUN_00583180_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44;
    RefAt48* m_ref;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    HelperAt6c m_container;
    void FUN_00583180();
};
// @fnv 0x00583180
void FUN_00583180_Class::FUN_00583180()
{
    m_container.FUN_0066b0d0(0);
    RefAt48* node = m_ref;
    RefAt48* doomed = node;
    doomed ? reinterpret_cast<::FUN_0040f2a0 *>((doomed))->DeleteThis(1) : 0;
    m_ref = 0;
}

struct FUN_00583270_sub_cls
{
    void FUN_0066b0d0(int);
};
struct FUN_00583270_mid_cls
{
};
struct FUN_00583270_tgt_cls
{
};

struct FUN_00583270_cls
{
    char pad[0x6c];
    FUN_00583270_sub_cls sub;
    void FUN_00583270();
};

// @fnv 0x00583270
void FUN_00583270_cls::FUN_00583270()
{
    if (((void *)(::FUN_00559450((int *)&(sub)))))
    {
        if (((int)(std::uintptr_t)(reinterpret_cast<::Callees *>((((void *)(::FUN_00559450((int *)&(sub))))))->FUN_00726070())) == 1)
        {
            if (((int)(reinterpret_cast<::FUN_00454b30_class *>((reinterpret_cast<FUN_00583270_mid_cls*>(((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))))))->FUN_00454b30())) == (int)((void *)(::FUN_00559450((int *)&(sub)))))
            {
                reinterpret_cast<::fnv_00b5ddf0::LocalTarget *>((reinterpret_cast<FUN_00583270_tgt_cls*>(((void *)(::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(0))))))->FUN_00b5ddf0((::fnv_00b5ddf0::LocalContext *)(0));
            }
            sub.FUN_0066b0d0(0);
        }
    }
}

struct TypeGroupInfo
{
    unsigned int type;
    unsigned int unk04;
    unsigned int label;
    unsigned int groupType;
};
struct FileReader
{
};
struct Offsets
{
    unsigned int* offsets;
    unsigned int unk04, unk08, unk0c, unk10;
    unsigned int base;
};
struct CellCoordinates
{
    int x, y, flags;
};
int GetCellCoordKey(int, int);
extern unsigned int DAT_01187338;
struct WorldReader
{
    bool SeekToCellInWorld(FileReader*, int, int);
};
// Seeks the file to the world block/sub-block for cell (x,y), scanning group headers and cell chunks until the matching cell is found.
// @fnv 0x005854f0
bool WorldReader::SeekToCellInWorld(FileReader* file, int x, int y)
{
    if (file && reinterpret_cast<::TESFile *>((file))->IsMasterFile())
    {
        Offsets* offsets = ((::Offsets *)(reinterpret_cast<::fnv_00588a90::TESWorldSpace_shell *>(this)->FUN_00588a90((::TESFile *)(file))));
        if (offsets && offsets->offsets)
        {
            int index = reinterpret_cast<::fnv_00584530::FUN_005858b0_shell *>(this)->FUN_00584530((::fnv_00584530::FileH *)(file), x, y);
            if (index != -1)
            {
                unsigned int offset = offsets->offsets[index];
                if (offset)
                {
                    reinterpret_cast<::TESOffsetWorker *>((file))->FUN_004723a0(offset + offsets->base);
                    return true;
                }
            }
            return false;
        }
    }
    int subBlock;
    bool found = false;
    int block = GetCellCoordKey(x, y);
    subBlock = FUN_005442c0(x, y);
    if (file && reinterpret_cast<::FUN_004734d0_shell *>((file))->FUN_004734d0((::TESForm *)(void *)(this)))
    {
        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
        bool done = false;
        TypeGroupInfo* header = ((::TypeGroupInfo *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()));
        while (header && !done)
        {
            if (header->type == ::fnv_00543df0::kGroupFormType)
            {
                bool skip = true;
                done = true;
                switch (header->groupType)
                {
                case 1:
                    skip = false;
                case 4:
                    if (block == header->label)
                        skip = false;
                case 5:
                    if (subBlock == header->label)
                        skip = false;
                case 6:
                case 8:
                case 9:
                    done = false;
                }
                if (!done)
                {
                    if (skip)
                        reinterpret_cast<::TESFile *>((file))->IsGroupOpen();
                    else
                        reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
                }
            }
            else if (header->type == DAT_011872b4)
            {
                CellCoordinates cellCoords;
                ::FUN_00540720((::ExteriorData *)&(cellCoords));
                memset(&cellCoords, 0, 12);
                if (header->label & 0x400)
                    cellCoords.x = 0x7fffffff;
                else
                {
                    bool read = false;
                    int chunk = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0();
                    while (chunk && !read)
                    {
                        if (chunk == 0x434c4358)
                        {
                            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&cellCoords), 12);
                            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                                reinterpret_cast<::S_00462230 *>(&(cellCoords))->FUN_00462230();
                            read = true;
                        }
                        if (reinterpret_cast<::TESFile *>((file))->NextChunk())
                            chunk = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0();
                        else
                            chunk = 0;
                    }
                }
                if (cellCoords.x == x && cellCoords.y == y)
                {
                    found = true;
                    done = true;
                    reinterpret_cast<::FUN_00472000_class *>((file))->SkipCurrentForm();
                }
                else
                    reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
            }
            else if (header->type == DAT_01187338)
            {
                reinterpret_cast<::FUN_00472150_shell *>((file))->FUN_00472150(true);
            }
            else
                done = true;
        }
    }
    return found;
}

struct FUN_005877e0_shell : public TESWorldSpace
{
    void FUN_005877e0();
};

struct FUN_005877e0_Val5
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int v4(int);
};

struct FUN_005877e0_Map
{
};

// If Probe fails, iterates cellMap calling v4(1) on each entry, then always calls Done on cellMap.
// @fnv 0x005877e0
void FUN_005877e0_shell::FUN_005877e0()
{
    if (!reinterpret_cast<::FUN_004077c0_shell *>(this)->FUN_004077c0())
    {
        void* it = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((reinterpret_cast<FUN_005877e0_Map*>(cellMap)))->GetFirstPos();
        while (it != 0)
        {
            FUN_005877e0_Val5* item;
            unsigned int key;
            FUN_005877e0_Val5* out4 = 0;
            reinterpret_cast<::C6b7f20_Map *>((reinterpret_cast<FUN_005877e0_Map*>(cellMap)))->FUN_006b7f20((::C6b7f20_Node **)(void **)(&it), &key, (void **)(::FUN_005877e0_Val5 **)(&out4));
            FUN_005877e0_Val5* tmp4 = out4;
            item = tmp4;
            (item != 0) ? item->v4(1) : 0;
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<FUN_005877e0_Map*>(cellMap)))->FUN_00438af0();
}

struct Pt3
{
    float x;
    float y;
    float z;
    Pt3();
    Pt3& operator*=(float);
    Pt3 operator-(const Pt3&) const;
    Pt3 operator+(const Pt3&) const;
};


struct WorldOffsetHost
{
    int unk00;
};


struct FUN_00588e40_shell : WorldOffsetHost
{
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
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    float m_fGridOriginX;
    float afWorldOriginY;
    float kPointArrayBench;
    float m_fWorldTransformCoefficient4;
    void TransformWorldPoint(Pt3* apPoint, bool abInverse);
};

// @fnv 0x00588e40
void FUN_00588e40_shell::TransformWorldPoint(Pt3* apPoint, bool abInverse)
{
    if (abInverse)
    {
        apPoint->x -= reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930();
        apPoint->y -= reinterpret_cast<::FUN_008d01e0_Class *>(this)->FUN_008d01e0();
    }
    if (::GetField90Float((char *)(void *)(this)) != 1.0 && ::GetField90Float((char *)(void *)(this)) != 0.0)
    {
        Pt3 kCenter4;
        kCenter4.x = m_fGridOriginX + kPointArrayBench;
        kCenter4.y = afWorldOriginY + m_fWorldTransformCoefficient4;
        kCenter4.z = 0.0f;
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::Pt3 &)(kCenter4))->FUN_00439180(::fnv_00c88020::DAT_01016248);
        Pt3 kDelta = *apPoint - kCenter4;
        reinterpret_cast<::MyPoint439180 *>((void *)&(const ::Pt3 &)(kDelta))->FUN_00439180(abInverse ? 1.0 / ::GetField90Float((char *)(void *)(this)) : ::GetField90Float((char *)(void *)(this)));
        *apPoint = kCenter4 + kDelta;
    }
    if (!abInverse)
    {
        apPoint->x += reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930();
        apPoint->y += reinterpret_cast<::FUN_008d01e0_Class *>(this)->FUN_008d01e0();
    }
}

struct FUN_00483630_holder
{
    virtual ~FUN_00483630_holder();
    unsigned int flags, formID, fileData, changedFlags, recordData;
};
struct FUN_00591300
{
    virtual ~FUN_00591300();
    unsigned int nameData, nameLength;
};
class TESFile;
struct TESTexture
{
    virtual ~TESTexture();
    unsigned int textureData, textureLength;
public:
    static void ReadTextureData(::TESTexture *, ::TESFile *);
};
struct FUN_0048e2e0
{
    unsigned int type, data, length;
    ~FUN_0048e2e0();
};
struct FUN_0057ce90_shell
{
    unsigned int head;
    ~FUN_0057ce90_shell();
};
struct FUN_00589130
{
    unsigned int table, count, allocator, entries;
    ~FUN_00589130();
};
struct FUN_00589230
{
    unsigned int entries, size, capacity, allocator;
    ~FUN_00589230();
};
struct BSStringTChar
{
    unsigned int data, length;
    ~BSStringTChar();
};
struct GO633
{
    void* node;
    ~GO633();
};
struct WorldTerrain
{
    ~WorldTerrain();
};
struct WorldCellMap
{
    virtual ~WorldCellMap();
};
struct WorldLandMap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~WorldLandMap();
};
struct FUN_00582e30 : FUN_00483630_holder, FUN_00591300, TESTexture
{
    WorldCellMap* cellMap;
    WorldLandMap* landMap;
    FUN_0057ce90_shell cellList;
    WorldTerrain* terrain;
    unsigned int water, parentUseFlags, climate, worldFlags;
    FUN_00589130 offsetMap;
    BSSimpleList<int> regionList;
    unsigned int worldspaceID;
    GO633 node;
    unsigned int parent, music, encounterZone, location, mapScale, mapX, mapY;
    unsigned int minX, minY, maxX, maxY, landHeight, waterHeight, lodWater;
    unsigned int lodWaterType, impactData;
    FUN_00589230 offsetArray;
    BSStringTChar mapName;
    float usableX, usableY;
    unsigned int mapDimensions;
    FUN_0048e2e0 m_kCloudLayerTextures;
    FUN_0048e2e0 waterTexture;
    virtual ~FUN_00582e30();
    void FUN_00588c80();
};
// Calls FUN_00582e30, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00582e00
void* FUN_00582e00_host::FUN_00582e00(unsigned int flags)
{
    reinterpret_cast<::FUN_00582e30 *>(this)->::FUN_00582e30::~FUN_00582e30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
extern FUN_00582e30* DAT_011c3f44;
// Clears the global worldspace pointer if it is this object, then releases terrain, cell and land maps and other owned resources.
// @fnv 0x00582e30
FUN_00582e30::~FUN_00582e30()
{
    if (DAT_011c3f44 == this)
        DAT_011c3f44 = 0;
    reinterpret_cast<::S_00587f40 *>(this)->ClearAllLists();
    reinterpret_cast<::FUN_00587bb0_shell *>(this)->DestroyMapEntries();
    if (terrain)
    {
        reinterpret_cast<::FUN_006fca70_Class *>((terrain))->FUN_006fca70();
        delete terrain;
        terrain = 0;
    }
    reinterpret_cast<::FUN_00583180_Class *>(this)->FUN_00583180();
    reinterpret_cast<::FUN_005877e0_shell *>(this)->FUN_005877e0();
    delete cellMap;
    cellMap = 0;
    delete landMap;
    landMap = 0;
    reinterpret_cast<::fnv_00588c80::FUN_00588c80 *>(this)->PerformNoArgumentOperation();
}

struct WorldRecordFile : TESFile
{
};
struct BoundsPoint
{
    float x, y;
    BoundsPoint();
};
struct BoundsOffsetData
{
    unsigned int cellOffsets;
    BoundsPoint minimum, maximum;
    unsigned int fileOffset;
};
struct WorldBounds
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    float minX, minY, maxX, maxY;
    bool FUN_00583360(WorldRecordFile*);
};
// @fnv 0x00583360
bool WorldBounds::FUN_00583360(WorldRecordFile* file)
{
    unsigned int type = 0;
    while (type = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (type)
        {
        case 0x304d414e: {
            BoundsPoint minimum;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&minimum), 8);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
            {
                ::FUN_00401080((int *)(float *)(&minimum.x));
                ::FUN_00401080((int *)(float *)(&minimum.y));
            }
            minX = FUN_0040ebd0(minX, minimum.x);
            minY = FUN_0040ebd0(minY, minimum.y);
            if (reinterpret_cast<::TESFile *>((file))->IsMasterFile())
            {
                BoundsOffsetData* data = ((::BoundsOffsetData *)(reinterpret_cast<::FUN_00588b00_shell *>(this)->GetOrCreateCellOffsetData((::TESFile *)(file))));
                data->minimum = minimum;
            }
            break;
        }
        case 0x394d414e: {
            BoundsPoint maximum;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&maximum), 8);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
            {
                ::FUN_00401080((int *)(float *)(&maximum.x));
                ::FUN_00401080((int *)(float *)(&maximum.y));
            }
            maxX = FUN_00404010(maxX, maximum.x);
            maxY = FUN_00404010(maxY, maximum.y);
            if (reinterpret_cast<::TESFile *>((file))->IsMasterFile())
            {
                BoundsOffsetData* data = ((::BoundsOffsetData *)(reinterpret_cast<::FUN_00588b00_shell *>(this)->GetOrCreateCellOffsetData((::TESFile *)(file))));
                data->maximum = maximum;
            }
            break;
        }
        }
        if (!reinterpret_cast<::TESFile *>((file))->NextChunk())
            break;
    }
    return true;
}

struct SaveForm
{
};
struct SaveFullName
{
    unsigned int unk00, unk04, unk08;
};
struct SaveTexture
{
    unsigned int unk00, unk04, unk08;
};
struct SaveMap
{
    unsigned int unk00, unk04, unk08, unk0c;
};
struct SaveOffset
{
    unsigned int unk00, unk04, unk08;
};
struct SaveGameString
{
    unsigned int unk00, unk04, unk08;
    int FUN_0048cee0();
};
struct SavePair
{
    float land, water;
};
struct SaveWorld
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    SaveFullName fullName;
    SaveTexture texture;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44;
    SaveForm* extra;
    unsigned char flags, unk4d;
    unsigned short parentFlags;
    unsigned int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    SaveForm* parent;
    unsigned int unk74, unk78, unk7c;
    SaveMap map;
    SaveOffset offset;
    unsigned int unk9c;
    unsigned int minimumX, minimumY, maximumX, maximumY;
    unsigned int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4;
    float landHeight, waterHeight;
    SaveForm* encounterZone;
    SaveGameString canopy, waterNoise;
    void FUN_00584170();
};
// Writes the world record's encounter zone, parent, canopy, water noise, heights, map, offset, bounds and flags to the save stream.
// @fnv 0x00584170
void SaveWorld::FUN_00584170()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(&(fullName))->FUN_00487010();
    unsigned int formID = 0;
    if (encounterZone)
    {
        formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((encounterZone))->FUN_0084e3a0()));
        ::FUN_00485910(0x4e5a4558, formID);
    }
    if (parent)
    {
        formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((parent))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e57, formID);
        ::FUN_00485950((void *)(0x4d414e50), parentFlags);
    }
    if (!reinterpret_cast<::Unk00586340 *>(this)->FUN_00586340(4) && ((::SaveForm *)(reinterpret_cast<::FUN_00585fe0_shell *>(this)->FUN_00585fe0())))
    {
        formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveForm *)(reinterpret_cast<::FUN_00585fe0_shell *>(this)->FUN_00585fe0()))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e43, formID);
    }
    if (!reinterpret_cast<::Unk00586340 *>(this)->FUN_00586340(3) && ((::SaveForm *)(::FUN_00586070((::TESWorldSpace *)this))))
    {
        formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveForm *)(::FUN_00586070((::TESWorldSpace *)this)))))->FUN_0084e3a0()));
        ::FUN_00485910(0x324d414e, formID);
    }
    if (!reinterpret_cast<::Unk00586340 *>(this)->FUN_00586340(1) && ((::SaveForm *)(reinterpret_cast<::FUN_005860c0_shell *>(this)->FUN_005860c0())))
    {
        formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveForm *)(reinterpret_cast<::FUN_005860c0_shell *>(this)->FUN_005860c0()))))->FUN_0084e3a0()));
        ::FUN_00485910(0x334d414e, formID);
        ::FUN_00485910(0x344d414e, reinterpret_cast<::BGSProjectile *>(this)->GetExplosionProximity());
    }
    if (!reinterpret_cast<::Unk00586340 *>(this)->FUN_00586340(0))
    {
        SavePair pairHeights;
        pairHeights.land = landHeight;
        pairHeights.water = waterHeight;
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::S_00462230 *>(&(pairHeights))->FUN_00462230();
        ::AppendChunk(0x4d414e44, &pairHeights, 8);
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::S_00462230 *>(&(pairHeights))->FUN_00462230();
    }
    if (!reinterpret_cast<::Unk00586340 *>(this)->FUN_00586340(2))
    {
        reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>(&(texture))->FUN_0048e370(0x4e4f4349);
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::FUN_005840b0_shell *>(&(map))->FUN_005840b0();
        ::AppendChunk(0x4d414e4d, &map, 16);
        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::FUN_005840b0_shell *>(&(map))->FUN_005840b0();
    }
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::Class005a6b10 *>(&(offset))->FUN_005a6b10();
    ::AppendChunk(0x4d414e4f, &offset, 12);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::Class005a6b10 *>(&(offset))->FUN_005a6b10();
    if (!reinterpret_cast<::Unk00586340 *>(this)->FUN_00586340(5) && ((::SaveForm *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget())))
    {
        formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveForm *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget()))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e49, formID);
    }
    FUN_004858f0(0x41544144, flags);
    ::FUN_00485710((void *)(0x304d414e), &minimumX, (void *)(2));
    ::FUN_00485710((void *)(0x394d414e), &maximumX, (void *)(2));
    if (((::SaveForm *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150())))
    {
        formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::SaveForm *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150()))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e5a, formID);
    }
    ::FUN_004856f0((void *)(0x4d414e4e), reinterpret_cast<::FUN_00408da0_Class *>(&(canopy))->FUN_00408da0(), (void *)(canopy.FUN_0048cee0() + 1));
    ::FUN_004856f0((void *)(0x4d414e58), reinterpret_cast<::FUN_00408da0_Class *>(&(waterNoise))->FUN_00408da0(), (void *)(waterNoise.FUN_0048cee0() + 1));
    if (extra)
        reinterpret_cast<::FUN_0058f080 *>((extra))->Save();
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

extern "C" void* _FNV_DynamicCast(void*, int, const void*, const void*, int);
struct FUN_0058efd0
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    FUN_0058efd0();
    ~FUN_0058efd0();
    void CopyFrom(FUN_0058efd0*);
};
struct CopyMap
{
};
struct CopyArray
{
    virtual void Destroy();
    virtual void Clear();
    virtual void CopyFrom(const CopyArray&);
    unsigned int count, capacity;
};
struct WorldCopy
{
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
    CopyMap* cells;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    TESClimate* climate;
    void* imageSpace;
    FUN_0058efd0* data;
    unsigned char flags;
    unsigned char unk4d;
    unsigned short parentFlags;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    TESWorldSpace* parent;
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
    unsigned int unkc4;
    float landHeight;
    float waterHeight;
    unsigned int unkd0;
    CopyArray arrayD4;
    CopyArray arrayE0;

    void FUN_00584fa0(TESForm*);
};
// @fnv 0x00584fa0
void WorldCopy::FUN_00584fa0(TESForm* form)
{
    WorldCopy* source = (WorldCopy*)_FNV_DynamicCast(form, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &(*reinterpret_cast<char *>(&::DAT_01183fd0)), 0);
    if (!source)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0((TESForm*)source);
    flags = source->flags;
    parentFlags = source->parentFlags;
    parent = source->parent;
    unkd0 = source->unkd0;
    climate = reinterpret_cast<::FUN_00585fe0_shell *>((source))->FUN_00585fe0();
    imageSpace = ((void *)(reinterpret_cast<::LowProcess *>((source))->GetActiveCombatTarget()));
    if (source->data)
    {
        if (!data)
            data = new FUN_0058efd0;
        reinterpret_cast<::ImpactSwapMaps *>((data))->FUN_0058f4c0((::ImpactSwapMaps *)(source->data));
    }
    else if (data)
    {
        delete data;
        data = 0;
    }
    reinterpret_cast<::TESObjectACTI *>(this)->SetLoopingSound((::TESSound *)(::TESWaterForm *)(::FUN_00586070((::TESWorldSpace *)(source))));
    reinterpret_cast<::TESObjectACTI *>(this)->SetActivateSound((::TESSound *)(::TESWaterForm *)(reinterpret_cast<::FUN_005860c0_shell *>((source))->FUN_005860c0()));
    reinterpret_cast<::TESWorldSpace *>(this)->FUN_00584150(reinterpret_cast<::BGSProjectile *>((source))->GetExplosionProximity());
    landHeight = source->landHeight;
    waterHeight = source->waterHeight;
    ::__memcpy(&unk80, &source->unk80, 16);
    ::__memcpy(&unk90, &source->unk90, 12);
    reinterpret_cast<::FUN_00810570_shell *>(this)->SetAssociatedActorValue(((int)(reinterpret_cast<::InterfaceManager *>((source))->FUN_00586150())));
    reinterpret_cast<::FUN_00438af0_Class *>((cells))->FUN_00438af0();
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((source->cells))->GetFirstPos();
    while (position)
    {
        unsigned int value = 0;
        unsigned int key;
        reinterpret_cast<::C6b7f20_Map *>((source->cells))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(key), (void **)&(value));
        reinterpret_cast<::FUN_00844700_Class *>((cells))->FUN_00844700(key, value);
    }
    arrayD4.CopyFrom(source->arrayD4);
    arrayE0.CopyFrom(source->arrayE0);
}

struct DataFile
{
};
struct CellOffsetData
{
    unsigned int* offsets;
    float minX, minY, maxX, maxY;
    unsigned int baseOffset;
};
struct WorldData
{
    bool FindCellByEditorID(const char*, int*, int*);
};
// Scans every loaded worldspace cell grid for a cell whose EDID chunk matches editorID, writing its grid coordinates to outX/outY and returning true when found.
// @fnv 0x00585940
bool WorldData::FindCellByEditorID(const char* editorID, int* outX, int* outY)
{
    unsigned int count = ((unsigned int)(::GetSourceFileCount((::FormS *)this)));
    for (unsigned int i = 0; i < count; i++)
    {
        DataFile* data = ((::DataFile *)(reinterpret_cast<::TESFile *>((((::DataFile *)(reinterpret_cast<::TESForm *>(this)->GetFile(i)))))->GetParentTESFile()));
        CellOffsetData* file = ((::CellOffsetData *)(reinterpret_cast<::fnv_00588a90::TESWorldSpace_shell *>(this)->FUN_00588a90((::TESFile *)(data))));
        if (file)
        {
            int minX = ((int)file->minX) >> 12;
            int maxY = ((int)file->minY) >> 12;
            int minY = ((int)file->maxX) >> 12;
            int maxX = ((int)file->maxY) >> 12;
            for (int x = minX; x <= minY; x++)
            {
                for (int y = maxY; y <= maxX; y++)
                {
                    int index = reinterpret_cast<::fnv_00584530::FUN_005858b0_shell *>(this)->FUN_00584530((::fnv_00584530::FileH *)(data), x, y);
                    if (index != -1)
                    {
                        unsigned int offset = file->offsets[index];
                        if (offset)
                        {
                            reinterpret_cast<::TESOffsetWorker *>((data))->FUN_004723a0(offset + file->baseOffset);
                            if (((unsigned int)(reinterpret_cast<::FUN_00472660_shell *>((data))->FUN_00472660())) == 0x39)
                            {
                                unsigned int chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((data))->FUN_004726b0()));
                                if (chunkID == 0x44494445)
                                {
                                    unsigned int uiBufferSize = reinterpret_cast<::FUN_00401660_Class *>((data))->GetField25C() + 1;
                                    char* size = (char*)FUN_00401000(uiBufferSize);
                                    FUN_00403d30(size, 0, uiBufferSize);
                                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((data))->FUN_00472890((char *)(size), 0);
                                    if (!FUN_00404dc0(size, editorID))
                                    {
                                        *outX = x;
                                        *outY = y;
                                        FUN_00401030(size);
                                        return true;
                                    }
                                    FUN_00401030(size);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

struct AutoMemHelper
{
    int previousContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
extern const char DAT_01031f18[];
extern const char DAT_01031ec0[];
struct CellOperations
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual void virtual5();
    virtual void virtual6();
    virtual void virtual7();
    virtual void virtual8();
    virtual void virtual9();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void FinishLoad();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();
    virtual void virtual43();
    virtual void virtual44();
    virtual void virtual45();
    virtual void virtual46();
    virtual void virtual47();
    virtual void virtual48();
    virtual void virtual49();
    virtual void virtual50();
    virtual void virtual51();
    virtual void virtual52();
    virtual void virtual53();
    virtual void virtual54();
    virtual void virtual55();
    virtual void virtual56();
    virtual void virtual57();
    virtual void virtual58();
    virtual void virtual59();
    virtual void virtual60();
    virtual void virtual61();
    virtual void virtual62();
    virtual void virtual63();
    virtual void virtual64();
    virtual void virtual65();
    virtual void virtual66();
    virtual void virtual67();
    virtual void virtual68();
    virtual void virtual69();
    virtual void virtual70();
    virtual void virtual71();
    virtual void virtual72();
    virtual void virtual73();
    virtual void SetWorldData(void*, bool);
};
struct SaveLoadOperations
{
};
struct WorldCellLoader
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual void virtual5();
    virtual void virtual6();
    virtual void virtual7();
    virtual void virtual8();
    virtual void virtual9();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void virtual34();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();
    virtual void virtual43();
    virtual void virtual44();
    virtual void virtual45();
    virtual void virtual46();
    virtual void virtual47();
    virtual void virtual48();
    virtual void virtual49();
    virtual void virtual50();
    virtual void virtual51();
    virtual void virtual52();
    virtual void virtual53();
    virtual void virtual54();
    virtual void virtual55();
    virtual void virtual56();
    virtual void virtual57();
    virtual void virtual58();
    virtual void virtual59();
    virtual void virtual60();
    virtual void virtual61();
    virtual void virtual62();
    virtual void virtual63();
    virtual void virtual64();
    virtual void virtual65();
    virtual void virtual66();
    virtual void virtual67();
    virtual void virtual68();
    virtual void virtual69();
    virtual void virtual70();
    virtual void virtual71();
    virtual void virtual72();
    virtual void virtual73();
    virtual void virtual74();
    virtual void virtual75();
    virtual const char* GetWorldName();
    CellOperations* FUN_00585b30(int x, int y);
};
struct ThreadFile
{
};
// @fnv 0x00585b30
CellOperations* WorldCellLoader::FUN_00585b30(int x, int y)
{
    AutoMemHelper j(26, true, DAT_01031f18, 1942);
    bool i = true;
    CellOperations* p = ((::CellOperations *)(reinterpret_cast<::TESWorldSpace *>(this)->GetCellAtGridPosition(x, y)));
    DAT_011c3f34 = reinterpret_cast<TESWorldSpace*>(this);
    if (!p || !reinterpret_cast<::FUN_00551420_shell *>((p))->FUN_00551420())
    {
        unsigned int fileCount = ((unsigned int)(::GetSourceFileCount((::FormS *)this)));
        for (unsigned int fileIndex = 0; fileIndex < fileCount; ++fileIndex)
        {
            FileReader* file = ((::FileReader *)(reinterpret_cast<::TESFile *>((reinterpret_cast<ThreadFile*>(((::FileReader *)(reinterpret_cast<::TESForm *>(this)->GetFile(fileIndex))))))->GetParentTESFile()));
            bool loaded = file && reinterpret_cast<::WorldReader *>(this)->SeekToCellInWorld(file, x, y);
            if (loaded)
            {
                if (!p)
                {
                    p = reinterpret_cast<CellOperations*>(new stub::TESObjectCELL);
                    reinterpret_cast<::FUN_00544300_Class *>((p))->FUN_00544300(false);
                    reinterpret_cast<::FUN_00544630_shell *>((p))->ResetCellData();
                    reinterpret_cast<::FUN_00544c90_shell *>((p))->SetExteriorCellCoordinates(x, y);
                    reinterpret_cast<::FUN_00587670_shell *>(this)->FUN_00587670((::TESObjectCELL *)(p));
                    void* worldData = 0;
                    worldData = reinterpret_cast<::Own61 *>(((*reinterpret_cast<::SaveLoadOperations * *>(&::g_TESSaveLoadGame))))->RemoveCommand((const char *)(std::uintptr_t)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))), x, y);
                    if (worldData)
                        p->SetWorldData(worldData, true);
                    i = ::TESDataHandler::LoadForm((::TESForm *)(p), (::TESFile *)(file));
                }
                else if (!(((::TypeGroupInfo *)(reinterpret_cast<::TESFile *>((file))->GetRecordHeader()))->label & 0x4000))
                {
                    ::TESDataHandler::LoadForm((::TESForm *)(p), (::TESFile *)(file));
                }
                if (!reinterpret_cast<::fnv_00550500::Cell *>((p))->FUN_00550500((::fnv_00550500::File *)(file)))
                    i = false;
            }
        }
        if (p)
        {
            reinterpret_cast<::S00551440 *>((p))->FUN_00551440(true);
            bool loading = reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::SaveLoadOperations * *>(&::g_TESSaveLoadGame))))->EvaluateCondition();
            reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::SaveLoadOperations * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(!loading);
            p->FinishLoad();
            reinterpret_cast<::FUN_004534f0_shell *>(((*reinterpret_cast<::SaveLoadOperations * *>(&::g_TESSaveLoadGame))))->FUN_004534f0(loading);
            reinterpret_cast<::fnv_00588150::FUN_00588150_shell *>(this)->AddCellReferences((::TESObjectCELL *)(p));
        }
    }
    if (!i)
        ::FUN_005b5e40();
    return p;
}

struct FUN_00585ee0_shell : public TESWorldSpace
{
    bool FindParentFile(int a1, int a2, unsigned int* a3, unsigned int* a4);
};

struct FileX
{
};

struct WorldX
{
};


// @fnv 0x00585ee0
bool FUN_00585ee0_shell::FindParentFile(int a1, int a2, unsigned int* apuiFileOut, unsigned int* apuiOffsetOut)
{
    bool bFound = false;
    *apuiFileOut = 0;
    *apuiOffsetOut = 0;
    if (!GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)0))
    {
        int iFileCount = ::GetSourceFileCount((::FormS *)this);
        if (iFileCount)
        {
            for (int iFileIndex = iFileCount - 1; iFileIndex >= 0; iFileIndex--)
            {
                TESFile* pParentFile = reinterpret_cast<::TESFile *>((((FileX*)reinterpret_cast<::TESForm *>(this)->GetFile(iFileIndex))))->GetParentTESFile();
                if (pParentFile && reinterpret_cast<::WorldReader *>((((WorldX*)this)))->SeekToCellInWorld((::FileReader *)(pParentFile), a1, a2) && ::FUN_00550f60(pParentFile))
                {
                    *apuiFileOut = (unsigned int)pParentFile;
                    *apuiOffsetOut = reinterpret_cast<::TESFile *>((((FileX*)pParentFile)))->GetOffset();
                    bFound = true;
                    break;
                }
            }
        }
    }
    else
    {
        bFound = ((FUN_00585ee0_shell*)GetParentWorld((TESWorldSpace::PARENT_USE_FLAG)0))
                     ->FindParentFile(a1, a2, apuiFileOut, apuiOffsetOut);
    }
    return bFound;
}

struct GlobalObject_006815c0
{
    GlobalObject_006815c0();
    float x, y, z;
};
typedef GlobalObject_006815c0 Point;
struct RegionForm
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual unsigned char Weight();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual float Value108();
    virtual void v109();
    virtual float Value110();
    virtual void v111();
    virtual float Value112();
    virtual void v113();
    virtual float Value114();
    virtual void v115();
    virtual unsigned char Value116();
    virtual void v117();
    virtual unsigned char Value118();
    virtual void v119();
    virtual unsigned char Value120();
};
struct Region
{
    virtual void v0();
    virtual RegionForm* Form();
    virtual void v2();
    virtual int Priority();
    virtual void v4();
    virtual void v5();
    virtual float Weight(Point const&, TESWorldSpace*, bool);
};
struct Entry
{
    Region* region;
    float weight;
};
struct RegionNode
{
    Region* item;
    RegionNode* next;
    Region** FUN_006815c0();
};
struct Head
{
    int unk00;
};
struct RegionData : Head, RegionNode
{
};
struct Selection
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Selection* Select(void*);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual RegionData* GetList();
};
struct CellRegions
{
    void* FUN_004f6800(int, Point const&, TESWorldSpace*);
};
struct CellProxyNew
{
};
struct Handler
{
};
struct GlobalObject_0096a2d0
{
    GlobalObject_0096a2d0();
    Entry* item;
    GlobalObject_0096a2d0* next;
    Entry** FUN_006815c0();
    bool FUN_008256d0();
    void FUN_005ae3d0(Entry*&);
};
struct RegionResult
{
    char* name;
    unsigned int formID;
    float a, b, c, time, d;
    unsigned char e, f, g, unk1f;
    float samples[9];
};
float __cdecl FUN_0053ca40();
struct World : TESWorldSpace
{
    void BuildRegionResults(float, float, float, float, RegionResult*, unsigned);
};
// Selects regions around the center of the given bounds, fills each result with region data and samples region weights at a 3x3 grid of points.
// @fnv 0x00586990
void World::BuildRegionResults(float minX, float minY, float maxX, float maxY, RegionResult* results, unsigned count)
{
    Entry* l = 0;
    Region** k = 0;
    Region* b = 0;
    RegionForm* a = 0;
    Point s[9];
    Point h;
    if (!(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)) || !count)
        return;
    h.x = (minX + maxX) / 2.0;
    h.y = (minY + maxY) / 2.0;
    h.z = 0;
    float q = (maxX - minX) / 2.0;
    float c = (maxY - minY) / 2.0;
    CellProxyNew* e = ((::CellProxyNew *)(reinterpret_cast<::FUN_00461bc0_cls *>((((Handler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->FUN_00461bc0(h.x, h.y, this, false)));
    if (!e || !((::CellRegions *)(reinterpret_cast<::TESObjectCELL *>((e))->GetRegionList(true))))
        return;
    unsigned i;
    for (i = 0; i < 9; i++)
    {
        s[i].x = minX + (i % 3) * q;
        s[i].y = minY + (i / 3) * c;
        s[i].z = 0;
    }
    Selection* eb =
        ((::Selection *)(reinterpret_cast<::FUN_00740940_shell *>((((Handler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetRegionDataManager()))->Select(((::CellRegions *)(reinterpret_cast<::TESObjectCELL *>((e))->GetRegionList(true)))->FUN_004f6800(6, h, this));
    if (!eb)
        return;
    GlobalObject_0096a2d0* cf = new GlobalObject_0096a2d0;
    RegionNode* f = eb->GetList();
    while (f)
    {
        b = *((::Region **)((void *)(f)));
        a = b ? b->Form() : 0;
        if (b && b->Priority() && a && a->Weight() && b->Weight(h, this, false) != 0.0)
        {
            l = new Entry;
            l->region = b;
            l->weight = a->Weight() / 100.0;
            cf->FUN_005ae3d0(l);
        }
        f = ((::RegionNode *)(reinterpret_cast<::Callees *>((f))->FUN_00726070()));
    }
    f = eb->GetList();
    while (f)
    {
        b = *((::Region **)((void *)(f)));
        a = b ? b->Form() : 0;
        if (b && !b->Priority() && a && a->Weight() && b->Weight(h, this, false) != 0.0)
        {
            l = new Entry;
            l->region = b;
            l->weight = a->Weight() / 100.0;
            cf->FUN_005ae3d0(l);
        }
        f = ((::RegionNode *)(reinterpret_cast<::Callees *>((f))->FUN_00726070()));
    }
    if (!cf || cf->FUN_008256d0())
    {
        delete (List_009e03e0*)cf;
        return;
    }
    k = new Region*[count];
    memset(k, 0, count * sizeof(Region*));
    GlobalObject_0096a2d0* ba = cf;
    unsigned p;
    for (p = 0; p < count; p++)
    {
        memset(results[p].samples, 0, sizeof(results[p].samples));
        if (results[p].name)
            delete[] results[p].name;
        results[p].name = 0;
        if (!ba)
            continue;
        l = *((::Entry **)((void *)(ba)));
        while (!l)
        {
            ba = ((::GlobalObject_0096a2d0 *)(reinterpret_cast<::Callees *>((ba))->FUN_00726070()));
            if (!ba)
                break;
            l = *((::Entry **)((void *)(ba)));
        }
        if (!l)
            continue;
        b = l->region;
        a = b->Form();
        k[p] = b;
        if (results[p].name)
            delete[] results[p].name;
        char* name = new char[260];
        FUN_00406d00(name, 260, "data/meshes/%s", reinterpret_cast<::FUN_0050a550_shell *>((a))->FUN_0050a550());
        results[p].name = name;
        results[p].formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((a))->FUN_0084e3a0()));
        results[p].a = a->Value108();
        results[p].b = a->Value110();
        results[p].c = a->Value112();
        results[p].d = a->Value114();
        results[p].e = a->Value116();
        results[p].f = a->Value118();
        results[p].g = a->Value120();
        results[p].time = FUN_0053ca40();
        ba = ((::GlobalObject_0096a2d0 *)(reinterpret_cast<::Callees *>((ba))->FUN_00726070()));
    }
    for (i = 0; i < 9; i++)
    {
        for (p = 0; p < count; p++)
        {
            if (!k[p] || !results[p].formID)
                continue;
            results[p].samples[i] = k[p]->Weight(s[i], this, true);
        }
    }
    delete[] k;
    {
        GlobalObject_0096a2d0* cleanup = cf;
        Entry* dead = 0;
        while (cleanup && *((::Entry **)((void *)(cleanup))))
        {
            dead = *((::Entry **)((void *)(cleanup)));
            cleanup = ((::GlobalObject_0096a2d0 *)(reinterpret_cast<::Callees *>((cleanup))->FUN_00726070()));
            delete dead;
        }
        reinterpret_cast<::FileMatchList *>((cf))->RemoveAll();
        delete (List_009e03e0*)cf;
    }
}

struct WsNameList
{
    const char* item;
    WsNameList* next;
    WsNameList();
};

struct WsListNode
{
};

struct WsDataHandler
{
};

struct FUN_005883c0_shell : public TESWorldSpace
{
    WsNameList* BuildMapNameList(bool abNoChildren);
};

// Builds a WsNameList from the parent world's list or a new list with this world's map names plus those of child worlds unless abNoChildren.
// @fnv 0x005883c0
WsNameList* FUN_005883c0_shell::BuildMapNameList(bool abNoChildren)
{
    WsNameList* pNameList = 0;
    if (GetParentWorld((PARENT_USE_FLAG)2) && !abNoChildren)
    {
        pNameList = ((FUN_005883c0_shell*)GetParentWorld((PARENT_USE_FLAG)2))->BuildMapNameList(false);
    }
    else
    {
        pNameList = new WsNameList;
        reinterpret_cast<::FUN_00588520_shell *>(this)->FUN_00588520((::BSSimpleList<const char *> *)(pNameList));
        if (!abNoChildren)
        {
            WsListNode* pNode = ((::WsListNode *)(::FUN_00460140((std::intptr_t)(((WsDataHandler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))));
            while (pNode)
            {
                TESWorldSpace* pWorld = *((::TESWorldSpace **)((void *)(pNode)));
                if (pWorld && pWorld->GetParentWorld((PARENT_USE_FLAG)2) == this)
                {
                    reinterpret_cast<::FUN_00588520_shell *>((((FUN_005883c0_shell*)pWorld)))->FUN_00588520((::BSSimpleList<const char *> *)(pNameList));
                }
                pNode = ((::WsListNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
            }
        }
    }
    return pNameList;
}

struct CELL_SHELL : public TESObjectCELL
{
};
struct WORLD_SHELL : public TESWorldSpace
{
    void ProcessCellsInRadius(const NiPoint3* point, float distance, const NiPoint3* otherPoint, float otherDistance, std::intptr_t options, unsigned int context);
};
// @fnv 0x005885f0
void WORLD_SHELL::ProcessCellsInRadius(const NiPoint3* point, float distance, const NiPoint3* otherPoint, float otherDistance, std::intptr_t options, unsigned int context)
{
    if (options == 0)
        return;
    {
        int found = 1;
        int j = 0;
        int width = (int)point->x >> 12;
        int i;
        int x;
        {
            CELL_SHELL* cell;
            {
                int y = (int)point->y >> 12;
                cell = ((::CELL_SHELL *)(reinterpret_cast<::TESWorldSpace *>(this)->GetCellAtGridPosition(width, y)));
                if (cell != 0)
                {
                    if (!reinterpret_cast<::s54da20::Owner *>((cell))->FUN_0054da20((::s54da20::Position *)(point), distance, (::s54da20::Position *)(otherPoint), otherDistance, (bool (*)(s54da20::Actor *, void *))(options), (void *)(context)))
                        return;
                }
                {
                    while (found != 0)
                    {
                        width -= 1;
                        y -= 1;
                        j += 2;
                        found = 0;
                        for (i = 0; i < j; i++)
                        {
                            cell = ((::CELL_SHELL *)(reinterpret_cast<::TESWorldSpace *>(this)->GetCellAtGridPosition(width, y)));
                            if (cell != 0 && (distance == ::_DAT_010231b0 || reinterpret_cast<::ThisC *>((cell))->FUN_0054fb70((::Pt2 *)(point)) < distance) &&
                                (otherDistance == ::_DAT_010231b0 || reinterpret_cast<::ThisC *>((cell))->FUN_0054fb70((::Pt2 *)(otherPoint)) < otherDistance))
                            {
                                found += 1;
                                if (!reinterpret_cast<::s54da20::Owner *>((cell))->FUN_0054da20((::s54da20::Position *)(point), distance, (::s54da20::Position *)(otherPoint), otherDistance, (bool (*)(s54da20::Actor *, void *))(options), (void *)(context)))
                                    return;
                            }
                            width += 1;
                        }
                        for (x = 0; x < j; x++)
                        {
                            cell = ((::CELL_SHELL *)(reinterpret_cast<::TESWorldSpace *>(this)->GetCellAtGridPosition(width, y)));
                            if (cell != 0 && (distance == ::_DAT_010231b0 || reinterpret_cast<::ThisC *>((cell))->FUN_0054fb70((::Pt2 *)(point)) < distance) &&
                                (otherDistance == ::_DAT_010231b0 || reinterpret_cast<::ThisC *>((cell))->FUN_0054fb70((::Pt2 *)(otherPoint)) < otherDistance))
                            {
                                found += 1;
                                if (!reinterpret_cast<::s54da20::Owner *>((cell))->FUN_0054da20((::s54da20::Position *)(point), distance, (::s54da20::Position *)(otherPoint), otherDistance, (bool (*)(s54da20::Actor *, void *))(options), (void *)(context)))
                                    return;
                            }
                            y += 1;
                        }
                        for (i = 0; i < j; i++)
                        {
                            cell = ((::CELL_SHELL *)(reinterpret_cast<::TESWorldSpace *>(this)->GetCellAtGridPosition(width, y)));
                            if (cell != 0 && (distance == ::_DAT_010231b0 || reinterpret_cast<::ThisC *>((cell))->FUN_0054fb70((::Pt2 *)(point)) < distance) &&
                                (otherDistance == ::_DAT_010231b0 || reinterpret_cast<::ThisC *>((cell))->FUN_0054fb70((::Pt2 *)(otherPoint)) < otherDistance))
                            {
                                found += 1;
                                if (!reinterpret_cast<::s54da20::Owner *>((cell))->FUN_0054da20((::s54da20::Position *)(point), distance, (::s54da20::Position *)(otherPoint), otherDistance, (bool (*)(s54da20::Actor *, void *))(options), (void *)(context)))
                                    return;
                            }
                            width -= 1;
                        }
                        for (x = 0; x < j; x++)
                        {
                            cell = ((::CELL_SHELL *)(reinterpret_cast<::TESWorldSpace *>(this)->GetCellAtGridPosition(width, y)));
                            if (cell != 0 && (distance == ::_DAT_010231b0 || reinterpret_cast<::ThisC *>((cell))->FUN_0054fb70((::Pt2 *)(point)) < distance) &&
                                (otherDistance == ::_DAT_010231b0 || reinterpret_cast<::ThisC *>((cell))->FUN_0054fb70((::Pt2 *)(otherPoint)) < otherDistance))
                            {
                                found += 1;
                                if (!reinterpret_cast<::s54da20::Owner *>((cell))->FUN_0054da20((::s54da20::Position *)(point), distance, (::s54da20::Position *)(otherPoint), otherDistance, (bool (*)(s54da20::Actor *, void *))(options), (void *)(context)))
                                    return;
                            }
                            y -= 1;
                        }
                    }
                    cell = (CELL_SHELL*)((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
                    if (cell != 0)
                        reinterpret_cast<::s54da20::Owner *>((cell))->FUN_0054da20((::s54da20::Position *)(point), distance, (::s54da20::Position *)(otherPoint), otherDistance, (bool (*)(s54da20::Actor *, void *))(options), (void *)(context));
                }
            }
        }
    }
}

struct QueryPoint2
{
    float x, y;
    QueryPoint2(float x, float y);
};
struct WorldQuery;
struct AreaQuery
{
};
struct CellQuery;
template <class T> struct QueryLink
{
    T* item;
    QueryLink* next;
    T** FUN_006815c0();
    QueryLink* FUN_00726070();
};
struct QueryNodeHeader
{
    unsigned int unk00;
};
struct CellQueryNode : QueryNodeHeader, QueryLink<CellQuery>
{
};
struct QueryData
{
};
struct CellQuery
{
};
struct WorldQuery
{
    bool ContainsPoint(const NiPoint3* position);
};

// @fnv 0x00588d10
bool WorldQuery::ContainsPoint(const NiPoint3* position)
{
    if (!reinterpret_cast<::FUN_00586260_shell *>(this)->IsFlag8Set())
        return true;
    QueryPoint2 point3(position->x, position->y);
    bool found = false;
    CellQueryNode* node2 = ((::CellQueryNode *)(std::uintptr_t)(reinterpret_cast<::FUN_004169d0_shell *>(((*reinterpret_cast<::QueryData * *>(&::g_dataHandler))))->FUN_004169d0()));
    while (node2 && *((::CellQuery **)((void *)(node2))))
    {
        CellQuery* cell2 = *((::CellQuery **)((void *)(node2)));
        if (reinterpret_cast<::FUN_00549580_shell *>((cell2))->FUN_00549580() && !reinterpret_cast<::FUN_00440d80_shell *>((cell2))->FUN_00440d80() && ((::WorldQuery *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((cell2))->FUN_007af430())) == this)
        {
            QueryLink<AreaQuery>* link = ((::QueryLink< ::AreaQuery> *)(reinterpret_cast<::BGSTerrainManager *>((cell2))->GetMinLevel()));
            while (link && *((::AreaQuery **)((void *)(link))))
            {
                AreaQuery* area = *((::AreaQuery **)((void *)(link)));
                if (reinterpret_cast<::Polygon *>((area))->FUN_004f8360((::PolygonPoint *)(&point3)))
                    found = true;
                link = ((::QueryLink< ::AreaQuery> *)(reinterpret_cast<::Callees *>((link))->FUN_00726070()));
            }
        }
        node2 = static_cast<CellQueryNode*>(((::QueryLink< ::CellQuery> *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070())));
    }
    return found;
}

namespace fnv_00583560 {
class File583
{
  public:
    bool ReadChunkInt(void*);
};
struct B006815c0
{
    float x, y;
    B006815c0();
};
struct OffsetData583
{
    unsigned int* offsets;
    B006815c0 minimum, maximum;
    unsigned int offset;
};
struct Pair583
{
    float x, y;
};
struct MapData583
{
    float x, y, z, w;
};
struct Extra583
{
    unsigned int x, y, z;
};
struct Full583
{
    unsigned int a, b, c;
};
struct Icon583
{
    unsigned int a, b, c;
};
class FUN_0058efd0
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    FUN_0058efd0();
};
class FUN_00589000
{
  public:
    virtual ~FUN_00589000();
    unsigned int a, b, c;
    FUN_00589000(unsigned int);
};
class Name583
{
  public:
    unsigned int a, b, c;
};
class Base583
{
  public:
    virtual void virtual000();
    virtual void virtual004();
    virtual void virtual008();
    virtual void virtual00C();
    virtual void virtual010();
    virtual void virtual014();
    virtual void virtual018();
    virtual void virtual01C();
    virtual void virtual020();
    virtual void virtual024();
    virtual void virtual028();
    virtual void virtual02C();
    virtual void virtual030();
    virtual void virtual034();
    virtual void virtual038();
    virtual void virtual03C();
    virtual void virtual040();
    virtual void virtual044();
    virtual void virtual048();
    virtual void virtual04C();
    virtual void virtual050();
    virtual void virtual054();
    virtual void virtual058();
    virtual void virtual05C();
    virtual void virtual060();
    virtual void virtual064();
    virtual void virtual068();
    virtual void virtual06C();
    virtual void virtual070();
    virtual void virtual074();
    virtual void virtual078();
    virtual void virtual07C();
    virtual void virtual080();
    virtual void virtual084();
    virtual void virtual088();
    virtual void virtual08C();
    virtual void virtual090();
    virtual void virtual094();
    virtual void virtual098();
    virtual void virtual09C();
    virtual void virtual0A0();
    virtual void virtual0A4();
    virtual void virtual0A8();
    virtual void virtual0AC();
    virtual void virtual0B0();
    virtual void virtual0B4();
    virtual void virtual0B8();
    virtual void virtual0BC();
    virtual void virtual0C0();
    virtual void virtual0C4();
    virtual void virtual0C8();
    virtual void virtual0CC();
    virtual void virtual0D0();
    virtual void virtual0D4();
    virtual void virtual0D8();
    virtual void virtual0DC();
    virtual void LoadBounds(File583*);
    virtual void virtual0E4();
    virtual void virtual0E8();
    virtual void virtual0EC();
    virtual void virtual0F0();
    virtual void virtual0F4();
    virtual void virtual0F8();
    virtual void virtual0FC();
    virtual void virtual100();
    virtual void virtual104();
    virtual void virtual108();
    virtual void virtual10C();
    virtual void virtual110();
    virtual void virtual114();
    virtual void virtual118();
    virtual void virtual11C();
    virtual void virtual120();
    virtual void virtual124();
    virtual void virtual128();
    virtual void virtual12C();
    virtual void virtual130();
    virtual void SetEditorID(char*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};
class World583 : public Base583, public Full583, public Icon583
{
  public:
    FUN_00589000* cellMap;
    unsigned int unk34, unk38, unk3C, unk40, unk44;
    FUN_0058efd0* imageSpace;
    unsigned char flags4C, unk4D;
    unsigned short field4E;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    MapData583 mapData;
    Extra583 extra;
    unsigned int unk9C;
    float minX, minY, maxX, maxY;
    unsigned int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    float fC8, fCC;
    unsigned int fieldD0;
    Name583 nameD4, nameE0;
    bool FUN_00583560(File583*);
};

struct EndianFlag583
{
    bool value;
};
// @fnv 0x00583560
bool World583::FUN_00583560(File583* file)
{
    int chunk;
    unsigned char type = reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660();
    if (type != 0x41)
        return false;
    if (reinterpret_cast<::TESFile *>((file))->IsMasterFile())
    {
        OffsetData583* data = ((::fnv_00583560::OffsetData583 *)(reinterpret_cast<::FUN_00588b00_shell *>(this)->GetOrCreateCellOffsetData((::TESFile *)(file))));
        data->offset = reinterpret_cast<::TESFile *>((file))->GetOffset();
    }
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(0);
    while ((chunk = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID(editorID);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData((::TESTexture *)(::fnv_00583560::Icon583 *)(this), (::TESFile *)(file));
            break;
        case 0x4c4c5546:
            ::ReadFullName((::TESFullName *)(::fnv_00583560::Full583 *)(this), (::TESFile *)(file));
            break;
        case 0x41544144: {
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() == 4)
            {
                unsigned int flags = 0;
                file->ReadChunkInt(&flags);
                flags4C = (unsigned char)flags;
            }
            else
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&flags4C), 1);
            break;
        }
        case 0x5453464f: {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            if (size)
            {
                OffsetData583* data;
                {
                    unsigned int count = size >> 2;
                    data = ((::fnv_00583560::OffsetData583 *)(reinterpret_cast<::FUN_00588b00_shell *>(this)->GetOrCreateCellOffsetData((::TESFile *)(file))));
                    if (data->offsets)
                        delete data->offsets;
                    data->offsets = new unsigned int[count];
                    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(data->offsets), 0);
                    if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                    {
                        for (unsigned int i = 0; i < count; i++)
                            ::FUN_00401080((int *)(void *)(&data->offsets[i]));
                    }
                }
            }
            break;
        }
        case 0x4e5a4558: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            fieldD0 = value;
            break;
        }
        case 0x4d414e43: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(value));
            break;
        }
        case 0x4d414e49: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((::TESObjectREFR *)(value));
            break;
        }
        case 0x324d414e: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            reinterpret_cast<::TESObjectACTI *>(this)->SetLoopingSound((::TESSound *)(value));
            break;
        }
        case 0x334d414e: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            reinterpret_cast<::TESObjectACTI *>(this)->SetActivateSound((::TESSound *)(value));
            break;
        }
        case 0x344d414e: {
            float value = 0;
            file->ReadChunkInt(&value);
            reinterpret_cast<::TESWorldSpace *>(this)->FUN_00584150(value);
            break;
        }
        case 0x4d414e57: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            reinterpret_cast<::TESWorldSpace *>(this)->SetParent((::TESWorldSpace *)(value));
            field4E = 0xffff;
            break;
        }
        case 0x4d414e50:
            reinterpret_cast<::FUN_00472840_impl *>((file))->ReadChunkData(&field4E);
            break;
        case 0x4d414e44: {
            Pair583 value;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&value), 8);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::S_00462230 *>(&(value))->FUN_00462230();
            fC8 = value.x;
            fCC = value.y;
            break;
        }
        case 0x4d414e4d:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&mapData), 16);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::FUN_005840b0_shell *>(&(mapData))->FUN_005840b0();
            break;
        case 0x4d414e4f:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&extra), 12);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
                reinterpret_cast<::Class005a6b10 *>(&(extra))->FUN_005a6b10();
            break;
        case 0x4d414e53: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            break;
        }
        case 0x4d414e5a: {
            unsigned int value = 0;
            file->ReadChunkInt(&value);
            reinterpret_cast<::FUN_00810570_shell *>(this)->SetAssociatedActorValue(value);
            break;
        }
        case 0x46504d49:
        case 0x53504d49:
            if (!imageSpace)
                imageSpace = new FUN_0058efd0;
            reinterpret_cast<::fnv_0058f180::FUN_0058f180 *>((imageSpace))->Load((::TESFile *)(file));
            break;
        case 0x4d414e4e: {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            if (size)
            {
                char* text = (char*)_alloca(size);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(text), size);
                reinterpret_cast<::TESFullName *>(&(nameD4))->SetFullName(text);
            }
            break;
        }
        case 0x4d414e58: {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            if (size)
            {
                char* text = (char*)_alloca(size);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(text), size);
                reinterpret_cast<::TESFullName *>(&(nameE0))->SetFullName(text);
            }
            break;
        }
        case 0x304d414e: {
            B006815c0 value;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&value), 8);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
            {
                ::FUN_00401080((int *)(void *)(&value.x));
                ::FUN_00401080((int *)(void *)(&value.y));
            }
            minX = ::FUN_0040ebd0(minX, value.x);
            minY = ::FUN_0040ebd0(minY, value.y);
            if (reinterpret_cast<::TESFile *>((file))->IsMasterFile())
            {
                OffsetData583* data = ((::fnv_00583560::OffsetData583 *)(reinterpret_cast<::FUN_00588b00_shell *>(this)->GetOrCreateCellOffsetData((::TESFile *)(file))));
                data->minimum = value;
            }
            break;
        }
        case 0x394d414e: {
            B006815c0 value;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&value), 8);
            if (reinterpret_cast<::TESFile *>((file))->IsEndianConversionRequired())
            {
                ::FUN_00401080((int *)(void *)(&value.x));
                ::FUN_00401080((int *)(void *)(&value.y));
            }
            maxX = ::FUN_00404010(maxX, value.x);
            maxY = ::FUN_00404010(maxY, value.y);
            if (reinterpret_cast<::TESFile *>((file))->IsMasterFile())
            {
                OffsetData583* data = ((::fnv_00583560::OffsetData583 *)(reinterpret_cast<::FUN_00588b00_shell *>(this)->GetOrCreateCellOffsetData((::TESFile *)(file))));
                data->maximum = value;
            }
            break;
        }
        }
        if (!reinterpret_cast<::TESFile *>((file))->NextChunk())
            break;
    }
    if (!((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((cellMap))->FUN_0084e3a0())) && !reinterpret_cast<::TESWorldSpace *>(this)->GetSmallWorld())
    {
        delete cellMap;
        if (reinterpret_cast<::TESForm *>(this)->IsReservedFormID())
            cellMap = new FUN_00589000(7001);
        else
            cellMap = new FUN_00589000(701);
    }
    return true;
}
}  // namespace fnv_00583560

namespace fnv_005878d0 {
class Pt
{
  public:
    float x;
    float y;
    float z;
    float Length() const;
};
class StrList
{
  public:
    int a;
    int b;
    StrList();
};
class DummyPointerMap
{
  public:
    int a;
    int b;
    int c;
    int d;
    DummyPointerMap(int);
};
class SetAtHelper
{
  public:
    void FUN_005ae3d0(void**);
};
class RefObj
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Pt* v125();
};
class WorldObj
{
  public:
    char pad68[0x68];
    DummyPointerMap* map;
    void FUN_005878d0(RefObj*);
};

// @fnv 0x005878d0
void WorldObj::FUN_005878d0(RefObj* pRef)
{
    if (pRef)
    {
        if (reinterpret_cast<::FUN_00439f90_shell *>((pRef))->FUN_00439f90())
        {
            Pt ptPos3 = *((::fnv_005878d0::Pt *)(reinterpret_cast<::fnv_00569880::FUN_00569880_cls *>((pRef))->FUN_00569880()));
            float fLen7 = reinterpret_cast<::NiPoint3 *>((void *)&(ptPos3))->ComputeMagnitude();
            int iXMin5 = ::FUN_00406d90(pRef->v125()->x - fLen7) >> 12;
            int iYMin8 = ::FUN_00406d90(pRef->v125()->y - fLen7) >> 12;
            int iXMax9 = ::FUN_00406d90(pRef->v125()->x + fLen7) >> 12;
            int iYMaxA = ::FUN_00406d90(pRef->v125()->y + fLen7) >> 12;
            int iCX3 = ::FUN_00406d90(pRef->v125()->x) >> 12;
            int iCY = ::FUN_00406d90(pRef->v125()->y) >> 12;
            for (int i_ = iXMin5; i_ <= iXMax9; ++i_)
            {
                for (int j2 = iYMin8; j2 <= iYMaxA; ++j2)
                {
                    if (i_ != iCX3 || j2 != iCY)
                    {
                        if (::BoundIntersectsCell((::BoundRef *)(pRef), i_, j2))
                        {
                            if (!map)
                                map = new DummyPointerMap(0x25);
                            unsigned int key3 = ::PackShortPair((short)i_, (short)j2);
                            int val = 0;
                            reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)(map))->FUN_00853130(key3, (::fnv_00853130::CombatThreatRecord *&)(val));
                            if (!val)
                            {
                                val = (int)new StrList();
                                reinterpret_cast<::FUN_00844700_Class *>((map))->FUN_00844700(key3, val);
                            }
                            ((SetAtHelper*)val)->FUN_005ae3d0((void**)&pRef);
                        }
                    }
                }
            }
        }
    }
}
}  // namespace fnv_005878d0

struct String65
{
    char* text;
    unsigned short length, capacity;
    String65();
    ~String65();
    bool Set(const char*, unsigned = 0);
    operator const char*() const;
    unsigned Length();
    int StrCmp(const char*, bool = true) const;
};
struct Pos65
{
    float x, y, z;
    Pos65();
};
struct Point65
{
    float x, y;
    Point65(const Pos65&);
};
struct Area65
{
};
struct AreaList65
{
    Area65** FUN_006815c0();
    bool FUN_008256d0();
    void* FUN_004f6800(int, const Pos65&, void*);
};
struct Data65
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
    virtual void v28(String65*);
};
struct Manager65
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual Data65* v10(void*);
};
struct Region65
{
};
struct RegionNode65
{
    Region65** FUN_006815c0();
};
struct RegionPrefix65
{
    int unk00;
};
struct RegionHead65 : RegionPrefix65, RegionNode65
{
};
struct Type65
{
};
struct Cell65
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FNStub fullName;
};
struct Handler65
{
};
struct World65
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FNStub fullName;
    bool FUN_00586500(String65*, Pos65);
};
// Selects a name for pos from its cell or matching regions, falls back to this world's full name or FUN_00586980, and reports whether output changed.
// @fnv 0x00586500
bool World65::FUN_00586500(String65* output, Pos65 pos)
{
    static String65 lastName;
    static Pos65 lastPos;
    static World65* lastWorld;
    Data65* data7 = 0;
    if (!(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))
        return false;
    if (lastWorld == this && reinterpret_cast<::NiPoint3 *>(&(lastPos))->FUN_004390c0((const ::NiPoint3 &)(pos)))
    {
        output->Set(lastName);
        return false;
    }
    if (lastWorld != this)
        lastName.Set("");
    lastWorld = this;
    lastPos = pos;
    output->Set("");
    Cell65* cellVal = ((::Cell65 *)(reinterpret_cast<::FUN_00461bc0_cls *>((((Handler65*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->FUN_00461bc0(pos.x, pos.y, (::TESWorldSpace *)(void *)(this), false)));
    if (cellVal)
    {
        data7 = ((::AreaList65 *)(reinterpret_cast<::TESObjectCELL *>((cellVal))->GetRegionList(true))) ? ((::Manager65 *)(reinterpret_cast<::FUN_00740940_shell *>((((Handler65*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetRegionDataManager()))
                                                  ->v10(((::AreaList65 *)(reinterpret_cast<::TESObjectCELL *>((cellVal))->GetRegionList(true)))->FUN_004f6800(4, pos, this))
                                            : 0;
        if (data7)
            data7->v28(output);
        else
            output->Set(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(cellVal->fullName))->FUN_00408da0())));
    }
    else
    {
        Region65* region4;
        Area65* area;
        RegionNode65* node5 = ((::RegionHead65 *)(std::uintptr_t)(reinterpret_cast<::FUN_004169d0_shell *>((((Handler65*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->FUN_004169d0()));
        AreaList65* areas = 0;
        Point65 point2(pos);
        int priority6 = -1;
        bool contains3 = false;
        bool aOverrideFlag = false;
        while (node5 && *((::Region65 **)((void *)(node5))))
        {
            contains3 = false;
            region4 = *((::Region65 **)((void *)(node5)));
            if (reinterpret_cast<::FUN_00440d80_shell *>((region4))->FUN_00440d80() || ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((region4))->FUN_007af430())) != this || !((::AreaList65 *)(std::uintptr_t)(reinterpret_cast<::BGSTerrainManager *>((region4))->GetMinLevel())) ||
                ((::AreaList65 *)(std::uintptr_t)(reinterpret_cast<::BGSTerrainManager *>((region4))->GetMinLevel()))->FUN_008256d0())
            {
                node5 = ((::RegionNode65 *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
                continue;
            }
            data7 = ((::Manager65 *)(reinterpret_cast<::FUN_00740940_shell *>((((Handler65*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetRegionDataManager()))
                        ->v10(((void *)(reinterpret_cast<::GList *>((((Type65*)((void *)(reinterpret_cast<::FUN_009611e0_shell *>((region4))->FUN_009611e0())))))->FUN_004f35b0(4))));
            if (!data7)
            {
                node5 = ((::RegionNode65 *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
                continue;
            }
            areas = ((::AreaList65 *)(std::uintptr_t)(reinterpret_cast<::BGSTerrainManager *>((region4))->GetMinLevel()));
            while (areas && *((::Area65 **)((void *)(areas))))
            {
                area = *((::Area65 **)((void *)(areas)));
                if (reinterpret_cast<::Polygon *>((area))->FUN_004f8360((::PolygonPoint *)&(point2)))
                {
                    contains3 = true;
                    break;
                }
                areas = ((::AreaList65 *)(reinterpret_cast<::Callees *>((areas))->FUN_00726070()));
            }
            if (!contains3)
            {
                node5 = ((::RegionNode65 *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
                continue;
            }
            if (reinterpret_cast<::PatrolActorPackageData *>((data7))->IsPatrolling())
            {
                if (aOverrideFlag && ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((data7))->FUN_005bb4d0())) <= priority6)
                {
                    node5 = ((::RegionNode65 *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
                    continue;
                }
            }
            else if (aOverrideFlag || ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((data7))->FUN_005bb4d0())) <= priority6)
            {
                node5 = ((::RegionNode65 *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
                continue;
            }
            aOverrideFlag = reinterpret_cast<::PatrolActorPackageData *>((data7))->IsPatrolling();
            priority6 = ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((data7))->FUN_005bb4d0()));
            data7->v28(output);
            node5 = ((::RegionNode65 *)(reinterpret_cast<::Callees *>((node5))->FUN_00726070()));
        }
    }
    if (!((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((output))->FUN_004048e0())))
        output->Set(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(fullName))->FUN_00408da0())));
    if (!((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((output))->FUN_004048e0())))
        output->Set(FUN_00586980());
    if (output->StrCmp(lastName))
    {
        lastName.Set(*output);
        return true;
    }
    return false;
}

struct WorldSpaceRefShell : public TESWorldSpace
{
    void FUN_00587d10(TESObjectREFR*);
};

struct ATM_587D10
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct Pt3_587D10
{
    float x, y, z;
};
struct RefV_587D10
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
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Pt3_587D10* GetPos();
};
namespace WsH_587D10 {
}
bool __cdecl FUN_00587c80(void*);
struct RefList_587D10
{
    int a;
    int b;
    void AddHead(int*);
};
struct RefListNode_587D10 : RefList_587D10
{
    RefListNode_587D10();
};
struct SetAt_587D10
{
};
struct PtrMap_587D10
{
};

// Adds apRef to a list directly or to a coordinate-keyed list, skipping null and temporary references.
// @fnv 0x00587d10
void WorldSpaceRefShell::FUN_00587d10(TESObjectREFR* apRef)
{
    if (apRef && !reinterpret_cast<::FUN_004077c0_shell *>((void *)(apRef))->FUN_004077c0())
    {
        reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::ATM *>(&::g_011ca60c))))->FUN_004538a0(0);
        if (!FUN_00587c80(apRef))
        {
            ((RefList_587D10*)((char*)this + 0x60))->AddHead((int*)&apRef);
        }
        else
        {
            unsigned int ikey = ::FUN_00587440((const ::NiPoint3 *)&(*((RefV_587D10*)apRef)->GetPos()));
            RefListNode_587D10* preflist = 0;
            reinterpret_cast<::fnv_00853130::NiTMapBase *>((((PtrMap_587D10*)((char*)this + 0x50))))->FUN_00853130(ikey, (::fnv_00853130::CombatThreatRecord *&)((unsigned int&)preflist));
            if (!preflist)
            {
                preflist = new RefListNode_587D10;
                reinterpret_cast<::FUN_00844700_Class *>((((SetAt_587D10*)((char*)this + 0x50))))->FUN_00844700(ikey, (std::uintptr_t)preflist);
            }
            preflist->AddHead((int*)&apRef);
        }
        reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::ATM *>(&::g_011ca60c))))->WaitForTasksDuringRendering();
    }
}

struct S00585250_WorldData
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Different(S00585250_WorldData*);
    int unk04, unk08;
};

struct S00585250_WorldReference
{
    bool Different(S00585250_WorldReference*);
};

struct WorldCompareView
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    S00585250_WorldReference* reference;
    unsigned char flags;
    unsigned char unk4D;
    unsigned short field4E;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    float fC8;
    float fCC;
    unsigned int unkD0;
    S00585250_WorldData dataD4;
    S00585250_WorldData dataE0;
    bool FUN_00585250(TESForm*);
};

// @fnv 0x00585250
bool WorldCompareView::FUN_00585250(TESForm* form)
{
    WorldCompareView* other = (WorldCompareView*)dynamic_cast< ::TESWorldSpace*>(form);
    if (!other)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(other)))
        return true;
    if (flags != other->flags)
        return true;
    if (field4E != other->field4E)
        return true;
    if (unk70 != other->unk70)
        return true;
    if (unkD0 != other->unkD0)
        return true;
    if (((void *)(reinterpret_cast<::FUN_00585fe0_shell *>(this)->FUN_00585fe0())) != ((void *)(reinterpret_cast<::FUN_00585fe0_shell *>((other))->FUN_00585fe0())))
        return true;
    if (((void *)(reinterpret_cast<::LowProcess *>(this)->GetActiveCombatTarget())) != ((void *)(reinterpret_cast<::LowProcess *>((other))->GetActiveCombatTarget())))
        return true;
    if (reference && other->reference)
    {
        if (reinterpret_cast<::FUN_0058f5c0_shell *>((reference))->IsImpactSwapDifferent((::ImpactSwap *)(other->reference)))
            return true;
    }
    else if (reference || other->reference)
        return true;
    if (((void *)(::FUN_00586070((::TESWorldSpace *)this))) != ((void *)(::FUN_00586070((::TESWorldSpace *)(other)))))
        return true;
    if (((void *)(reinterpret_cast<::FUN_005860c0_shell *>(this)->FUN_005860c0())) != ((void *)(reinterpret_cast<::FUN_005860c0_shell *>((other))->FUN_005860c0())))
        return true;
    if (reinterpret_cast<::BGSProjectile *>(this)->GetExplosionProximity() != reinterpret_cast<::BGSProjectile *>((other))->GetExplosionProximity())
        return true;
    if (fC8 != other->fC8 || fCC != other->fCC)
        return true;
    if (memcmp(&unk80, &other->unk80, 16))
        return true;
    if (memcmp(&unk90, &other->unk90, 12))
        return true;
    if (((void *)(reinterpret_cast<::InterfaceManager *>(this)->FUN_00586150())) != ((void *)(reinterpret_cast<::InterfaceManager *>((other))->FUN_00586150())))
        return true;
    if (dataD4.Different(&other->dataD4))
        return true;
    if (dataE0.Different(&other->dataE0))
        return true;
    return false;
}

struct GROUP_HEADER
{
    unsigned int uiType;
    unsigned int uiSize;
    unsigned int uiLabel;
    int iGroupType;
};

class FormGroupOwner
{
  public:
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
    virtual bool IsParentForm(TESForm* pkForm);
    bool FUN_00584d40(GROUP_HEADER* pkGroup);
};

// @fnv 0x00584d40
bool FormGroupOwner::FUN_00584d40(GROUP_HEADER* pkGroup)
{
    bool bResult = false;
    if (pkGroup && pkGroup->uiType == ::fnv_00543df0::kGroupFormType)
    {
        switch (pkGroup->iGroupType)
        {
        case 0:
            bResult = reinterpret_cast<::FUN_00484150_shell *>(this)->IsFormTypeBelowThreshold((::FormRecordHeader *)(pkGroup));
            break;
        case 2:
        case 3:
            bResult = false;
            break;
        case 6: {
            TESObjectCELL* pkCell = dynamic_cast<TESObjectCELL*>(FUN_004839c0(pkGroup->uiLabel));
            if (pkCell)
                bResult = IsParentForm((TESForm*)pkCell);
        }
        break;
        case 4:
        case 5:
            break;
        case 1: {
            TESWorldSpace* pkWorld = dynamic_cast<TESWorldSpace*>(FUN_004839c0(pkGroup->uiLabel));
            if (pkWorld)
                bResult = IsParentForm((TESForm*)pkWorld);
        }
        break;
        case 7:
            bResult = true;
            break;
        }
    }
    return bResult;
}

class MobileObject : public TESObjectREFR
{
};

class Actor : public MobileObject
{
};

struct MapPosition532;

struct FUN_00993820
{
    virtual ~FUN_00993820();
    unsigned int bucketCount;
    MapPosition532** buckets;
    unsigned int size;
    FUN_00993820(int);
    void SetValue(Actor*, unsigned __int64);
};

struct Child532
{
};

struct Tail532
{
};

struct ReferenceArray532
{
    virtual ~ReferenceArray532();
    Child532** data;
    unsigned short capacity, size, effectiveSize, grow;
    Child532*& FUN_00877a30(unsigned int);
};

struct CombatGroup532 : ReferenceArray532
{
    FUN_00993820* map;
    Tail532* tail;
    void FUN_00993600(void* stream);
};

// @fnv 0x00993600
void CombatGroup532::FUN_00993600(void* stream)
{
    FUN_00993820* oldMapX = map;
    map = new FUN_00993820(0x25);
    MapPosition532* position = ((::MapPosition532 *)(reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((oldMapX))->GetFirstPos()));
    Actor* actor_;
    unsigned __int64 valueTmp;
    unsigned int index;
    Child532* child2;
    while (position)
    {
        reinterpret_cast<::CPMap00993a80 *>((oldMapX))->GetNextEntry((::CPMapItem00993a80 *&)(position), (unsigned int *)&(actor_), (unsigned long long *)&(valueTmp));
        // Persisted pointer-map keys hold a 32-bit form identifier until fixup.
        actor_ = actor_ ? dynamic_cast<Actor*>(FUN_004839c0((unsigned int)(std::uintptr_t)actor_)) : 0;
        if (actor_)
            map->SetValue(actor_, valueTmp);
    }
    reinterpret_cast<::FUN_00438af0_Class *>((oldMapX))->FUN_00438af0();
    delete oldMapX;
    for (index = 0; index < reinterpret_cast<::FUN_00658930_class *>(this)->GetShortAtOffsetA(); ++index)
    {
        child2 = FUN_00877a30(index);
        if (child2)
            reinterpret_cast<::UpdateOwner *>((child2))->UpdateElements((std::uintptr_t)(stream));
    }
    reinterpret_cast<::CombatThreatMap *>((tail))->ApplyLoadBuffer((::BGSLoadGameBuffer *)(stream));
}

class TESClimate_rtti : public TESForm
{
};

class TESImageSpace : public TESForm
{
};

class BGSEncounterZone : public TESForm
{
};

class TESWaterForm : public TESForm
{
};

class BGSMusicType : public TESForm
{
};

class TESObjectCELL5845
{
  public:
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
    virtual void LinkPersistent();
};

class CellMap5845
{
  public:
};

class WorldSpaceOwner5845;

class WorldSpaceLOD5845
{
  public:
    WorldSpaceLOD5845(WorldSpaceOwner5845* pkWorld);
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
};

class WorldSpaceRegion5845
{
  public:
};

class WorldSpaceOwner5845
{
  public:
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
    virtual const char* GetEditorID() const;

    void FUN_005845e0();

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
    CellMap5845* m_pkCellMap;
    unsigned int unk34;
    unsigned int unk38;
    WorldSpaceLOD5845* m_pkLOD;
    unsigned int m_uiClimate;
    unsigned int m_uiImageSpace;
    WorldSpaceRegion5845* m_pkRegion;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int m_uiParentWorld;
    unsigned int m_uiWater;
    unsigned int m_uiLODWater;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int m_uiMusicType;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int m_uiEncounterZone;
};

// @fnv 0x005845e0
void WorldSpaceOwner5845::FUN_005845e0()
{
    if (!reinterpret_cast<::TESForm *>(this)->GetInitialized())
    {
        unsigned int uiFormIDA;
        uiFormIDA = m_uiClimate;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESClimate_rtti* pkClimate = dynamic_cast<TESClimate_rtti*>(FUN_004839c0(uiFormIDA));
            if (!pkClimate)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::fnv_0087ce80::FUN_0087ce80_shell *>(this)->FUN_0087ce80((::fnv_0087ce80::TESObjectCELL *)(pkClimate));
        }
        uiFormIDA = m_uiImageSpace;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESImageSpace* pkImageSpace2 = dynamic_cast<TESImageSpace*>(FUN_004839c0(uiFormIDA));
            if (!pkImageSpace2)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::LowProcess *>(this)->SetCurrentCombatTarget((::TESObjectREFR *)(pkImageSpace2));
        }
        uiFormIDA = m_uiEncounterZone;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            BGSEncounterZone* pkEncounterZone = dynamic_cast<BGSEncounterZone*>(FUN_004839c0(uiFormIDA));
            if (!pkEncounterZone)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::TESWorldSpace *>(this)->SetFieldD0((std::uintptr_t)(pkEncounterZone));
        }
        uiFormIDA = m_uiWater;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESWaterForm* pkWaterType4 = dynamic_cast<TESWaterForm*>(FUN_004839c0(uiFormIDA));
            if (!pkWaterType4)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::TESObjectACTI *>(this)->SetLoopingSound((::TESSound *)(pkWaterType4));
        }
        uiFormIDA = m_uiLODWater;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESWaterForm* pkLODWaterType3 = dynamic_cast<TESWaterForm*>(FUN_004839c0(uiFormIDA));
            if (!pkLODWaterType3)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::TESObjectACTI *>(this)->SetActivateSound((::TESSound *)(pkLODWaterType3));
        }
        uiFormIDA = m_uiMusicType;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            BGSMusicType* kPkMusicType = dynamic_cast<BGSMusicType*>(FUN_004839c0(uiFormIDA));
            if (!kPkMusicType)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::FUN_00810570_shell *>(this)->SetAssociatedActorValue((std::intptr_t)(kPkMusicType));
        }
        uiFormIDA = m_uiParentWorld;
        if (uiFormIDA)
        {
            ::ResolveFormID(&uiFormIDA, reinterpret_cast<::TESForm *>(this)->GetFile(-1));
            TESWorldSpace* pkParentWorldVal = dynamic_cast<TESWorldSpace*>(FUN_004839c0(uiFormIDA));
            if (!pkParentWorldVal)
            {
                if (reinterpret_cast<::BGSCameraPath *>(this)->HasNameForWarning())
                    ::FUN_005b5e40();
                else
                    ::FUN_005b5e40();
            }
            reinterpret_cast<::TESWorldSpace *>(this)->SetParent(pkParentWorldVal);
        }
        if (m_pkRegion)
            reinterpret_cast<::SomeClass *>((m_pkRegion))->RemapImpactData((::TESForm *)(::WorldSpaceOwner5845 *)(this));
        reinterpret_cast<::TESForm *>(this)->SetInitializationState(1);
    }
    TESObjectCELL5845* pkPersistent4;
    void* pos2 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((m_pkCellMap))->GetFirstPos();
    while (pos2)
    {
        unsigned int uiKey3;
        TESObjectCELL5845* pkCell = 0;
        reinterpret_cast<::C6b7f20_Map *>((m_pkCellMap))->FUN_006b7f20((::C6b7f20_Node **)&(pos2), (unsigned int *)&(uiKey3), (void **)&(pkCell));
        if (pkCell)
            pkCell->LinkPersistent();
    }
    pkPersistent4 = ((::TESObjectCELL5845 *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    if (pkPersistent4)
        pkPersistent4->LinkPersistent();
    m_pkLOD = new WorldSpaceLOD5845(this);
}

extern "C" void* __cdecl FUN_00ec43fb(void* p, long off, void* src, void* dst, int isRef);

struct FormX
{
    int FUN_00401170();
    bool IsLessThan(FormX* pkForm);
};

struct WorldX_rtti;

struct ChildX
{
    virtual WorldX_rtti* GetParentWorld();
};

struct WorldX_rtti;

struct CellX
{
};

struct WorldX_rtti
{
    bool IsLessThan(FormX* pkForm);
    virtual void v00(), v04(), v08(), v0c(), v10(), v14(), v18(), v1c(), v20(), v24(), v28(), v2c(), v30(), v34(),
        v38();
    virtual bool IsChildOf(WorldX_rtti* pkWorld);
    bool FUN_00584be0(FormX* pkForm);
};

// @fnv 0x00584be0
bool WorldX_rtti::FUN_00584be0(FormX* pkForm)
{
    bool bResult = false;
    switch (pkForm->FUN_00401170())
    {
    case 0x39: {
        CellX* pkCell = (CellX*)dynamic_cast<::TESObjectCELL *>(reinterpret_cast<::TESForm *>(pkForm));
        WorldX_rtti* pkWorld = pkCell ? ((::WorldX_rtti *)(reinterpret_cast<::TESObjectCELL *>((pkCell))->GetParentWorldSpace())) : 0;
        if (pkWorld == this)
            bResult = true;
        else if (pkWorld)
            bResult = IsChildOf(pkWorld);
        break;
    }
    case 0x41:
        if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) < ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkForm))->FUN_0084e3a0())))
            bResult = true;
        break;
    case 0x3a:
    case 0x3b:
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x42:
    case 0x43:
    case 0x69: {
        ChildX* pkChild = (ChildX*)FUN_00ec43fb(pkForm, 0, &(*reinterpret_cast<char *>(&::DAT_01183028)), &DAT_0118ac2c, 0);
        bResult = IsChildOf(pkChild->GetParentWorld());
        break;
    }
    default:
        bResult = reinterpret_cast<::TESFormSortProxy *>(this)->IsLessThan((::TESForm *)(pkForm));
        break;
    }
    return bResult;
}

struct FUN_00993820_rtti_decl
{
    virtual ~FUN_00993820_rtti_decl();
    unsigned int bucketCount;
    MapPosition532** buckets;
    unsigned int size;
    FUN_00993820_rtti_decl(int);
};

struct CombatGroup532_rtti_decl : ReferenceArray532
{
    FUN_00993820_rtti_decl* map;
    Tail532* tail;
    void FUN_00993600(void* stream);
};

// The native map enumerates form pointers while cloning each cell into the new world.
struct CellMapAccess545 : NiTPointerMap<unsigned int, TESObjectREFR*>
{
};

struct WorldClone545 : TESWorldSpace
{
    TESWorldSpace* FUN_00584e60(bool temporary, TESFile* file);
};

// @fnv 0x00584e60
TESWorldSpace* WorldClone545::FUN_00584e60(bool temporary, TESFile* file)
{
    TESWorldSpace* world = dynamic_cast<TESWorldSpace*>(((::TESForm *)(reinterpret_cast<::FUN_004867a0_cls *>(this)->FUN_004867a0((void *)(temporary), file))));
    reinterpret_cast<::FUN_00438af0_Class *>((static_cast<CellMapAccess545*>(world->cellMap)))->FUN_00438af0();
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((static_cast<CellMapAccess545*>(cellMap)))->GetFirstPos();
    while (position)
    {
        TESForm* form2 = 0;
        unsigned int key;
        reinterpret_cast<::C6b7f20_Map *>((static_cast<CellMapAccess545*>(cellMap)))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(key), (void **)&(form2));
        if (form2)
        {
            TESObjectCELL* cell3 = dynamic_cast<TESObjectCELL*>(form2->CloneForm(false, file));
            if (cell3)
            {
                cell3->SetAltered(true);
                reinterpret_cast<::FUN_00587670_shell *>((static_cast<WorldClone545*>(world)))->FUN_00587670(cell3);
            }
        }
    }
    TESObjectCELL* persistent3 = ((::TESObjectCELL *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()));
    if (persistent3)
    {
        TESObjectCELL* copy = dynamic_cast<TESObjectCELL*>(persistent3->CloneForm(false, file));
        if (copy)
        {
            world->m_pCell = copy;
            copy->SetAltered(true);
        }
    }
    reinterpret_cast<::FUN_00588120_host *>((static_cast<WorldClone545*>(world)))->FUN_00588120();
    return world;
}

#include "generated/data/fallout_shared/tesworldspace.inc"
