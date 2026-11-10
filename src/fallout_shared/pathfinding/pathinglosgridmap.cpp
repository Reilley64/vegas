
// src/fallout_shared/pathfinding/pathinglosgridmap.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathinglosgridmap.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00600ab0_shell.h"
#include "fnv/decl/FUN_0068efb0_shell.h"
#include "fnv/decl/FUN_0069dec0_class.h"
#include "fnv/decl/FUN_006d8990_shell.h"
#include "fnv/decl/FUN_006dfd70_Class.h"
#include "fnv/decl/FUN_006dfdc0_Class.h"
#include "fnv/decl/FUN_006dfe90_S.h"
#include "fnv/decl/FUN_006dffc0_Class.h"
#include "fnv/decl/FUN_006e1280_Class.h"
#include "fnv/decl/FUN_006e12c0_Class.h"
#include "fnv/decl/FUN_006e1500_class.h"
#include "fnv/decl/FUN_0072ba80_shell.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865db0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_00aa5ff0_Class.h"
#include "fnv/decl/InfoEntryArrY.h"
#include "fnv/decl/List6DFD.h"
#include "fnv/decl/Lock00aa62c0.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/PathingLocation.h"
#include "fnv/decl/S006911c0.h"
#include "fnv/decl/S2f850.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_006dfb00__Owner_006dfb00.h"
#include "fnv/decl/fnv_006e10a0__FUN_006e10a0_Class.h"
#include "fnv/decl/fnv_006e1610__PathingLOSMap.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/pathing/los_map_array.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa6000.h"
#include "fnv/symbols_011de000.h"
struct PathingLOSGridMap
{
    void* pUnk00;
    void* pUnk04;
    void* kNavMeshGridMap[4];  // +0x08, a NiTPointerMap of nav mesh id to grid
    float fCellSize;           // +0x18
    int kLocation[10];         // +0x1C, a PathingLocation
    float fRadius;             // +0x44
    float fUnk48;              // +0x48
    int kLock[2];              // +0x4C, a ReadWriteLock
    void* FUN_006e0270(unsigned int);
};
struct FUN_006e0590_shell : public PathingLOSGridMap
{
    void FUN_006e0590();
};

struct FUN_006e10a0_shell
{
};

// @fnv 0x006e0590
void FUN_006e0590_shell::FUN_006e0590()
{
    reinterpret_cast<::fnv_006e10a0::FUN_006e10a0_Class *>((((FUN_006e10a0_shell*)((char*)&this->pUnk04))))->FUN_006e10a0();
}

struct FUN_006a62f0_shell
{
    void AddOffset(void*);
};

void FUN_006a62f0_shell::AddOffset(void* arg)
{}

struct FUN_006e0ed0_shell
{
    void FUN_006e0ed0(void*);
};

// @fnv 0x006e0ed0
void FUN_006e0ed0_shell::FUN_006e0ed0(void* arg)
{
    reinterpret_cast<FUN_006a62f0_shell*>(this)->AddOffset(arg);
}


class NavMeshInfo
{
public:
    bool ResolveNavMesh(::NavMeshPtr &);
};

struct FUN_006e08f0_shell
{
    void* kEntries[4];  // +0x00, a BSSimpleArray
    NavMeshInfo* m_pNavMeshInfo;
    bool FUN_006e08f0(NavMeshPtr& aArg);
};

// Checks whether the object at offset 16 is non-null and, if so, delegates to its NavMeshInfo method with aArg.
// @fnv 0x006e08f0
bool FUN_006e08f0_shell::FUN_006e08f0(NavMeshPtr& aArg)
{
    if (m_pNavMeshInfo == 0)
        return false;
    return m_pNavMeshInfo->ResolveNavMesh((::NavMeshPtr &)(aArg));
}

namespace fnv_006e0480 {
struct PathingLOSGridMap
{
    void FUN_006e04b0();
    void* FUN_006e0480(unsigned int flags);
};
// Calls FUN_006e04b0, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006e0480
void* PathingLOSGridMap::FUN_006e0480(unsigned int flags)
{
    FUN_006e04b0();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_006e0480

struct FUN_006e0560_shell : FUN_006e0590_shell
{
    void* DestroyIfFlagged(unsigned int);
};
// @fnv 0x006e0560
void* FUN_006e0560_shell::DestroyIfFlagged(unsigned int flags)
{
    FUN_006e0590();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct BSAudio
{
};
struct Flt
{
    operator unsigned int();
};
struct DummyPointerMap
{
};
struct FUN_006df760_shell
{
    unsigned short GetShortValueAtOffset24();
};
struct FUN_006dfe90_shell
{
};
struct FUN_006e0bc0_shell : public PathingLOSGridMap
{
    bool FUN_006e0bc0(BSAudio* aArg, bool aFlag);
};
// @fnv 0x006e0bc0
bool FUN_006e0bc0_shell::FUN_006e0bc0(BSAudio* aArg, bool aFlag)
{
    void* pTopic = ((void *)(reinterpret_cast<::MagicCaster_shell *>((aArg))->FUN_0044edb0()));
    if (!pTopic || ((FUN_006df760_shell*)aArg)->GetShortValueAtOffset24() == 0xFFFF)
        return false;
    std::uintptr_t key = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((((DummyPointerMap*)((char*)&this->kNavMeshGridMap))))->FUN_00853130(*(Flt*)pTopic, (::fnv_00853130::CombatThreatRecord *&)(key)))
        return reinterpret_cast<::FUN_006dfe90_S *>((((FUN_006dfe90_shell*)key)))->FUN_006dfe90((::PathingLocation *)(aArg), aFlag);
    return false;
}

extern "C"
{
    void __declspec(dllimport) vprintf(const char*, void*);
}
namespace fnv_006e05b0 {
struct PathingLOSGridMap
{
    unsigned char _pad0[0x18];
    float m_fCellSize;
    int m_1C;
    unsigned char _pad1[0x24];
    float fRadius;
    void ClearMap();
    void FUN_006e0320(void* p, float f);
    void Reset();
};
// @fnv 0x006e05b0
void PathingLOSGridMap::Reset()
{
    m_fCellSize = 0.0f;
    ClearMap();
    FUN_006e0320(&m_1C, fRadius);
}
}  // namespace fnv_006e05b0

struct SetAtHelper
{
};
struct LocX
{
    virtual void v0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};

struct FUN_006e0d20_t : public PathingLOSGridMap
{
    void FUN_006e0d20(BGSLoadFormBuffer* apLoadGameBuffer);
};

// Hands the loaded records to the map in load order. 00844700 has no failure
// result: it links a node or faults. Nothing may leave here with only part of
// a load in the map.
static void PublishLOSRecords(FUN_00844700_Class* apMap, fnv::pathing::LOSMapLoad& aLoad) noexcept
{
    for (std::uint32_t iloop = 0; iloop < aLoad.KeptCount(); iloop++)
    {
        apMap->FUN_00844700(aLoad.KeptID(iloop), (std::uintptr_t)aLoad.KeptRecord(iloop));
        aLoad.Release(iloop);
    }
}

// Loads every record and the trailing values, then publishes the records, stores
// the values and loads the location, in the source's order. The source has no
// failure result here. Where it would read past the buffer's extent, or storage
// is exhausted, this returns instead: the records loaded so far are deleted, the
// map, the three values and the location are as they were before the call, and
// the buffer's cursor rests after the last complete read. No failure return
// follows the third trailing read.
// @fnv 0x006e0d20
void FUN_006e0d20_t::FUN_006e0d20(BGSLoadFormBuffer* apLoadGameBuffer)
{
    fnv::pathing::LOSSaveReader reader(*apLoadGameBuffer);
    fnv::pathing::LOSMapLoad load;
    if (!load.Begin(reader))
        return;
    for (std::uint32_t iloop = 0; iloop < load.Count(); iloop++)
    {
        FUN_006e0480* ppathingLOSGrid = load.NewRecord();
        unsigned int inavmeshID = 0;
        // The packed form ID is three bytes and a separator.
        if (!ppathingLOSGrid || !reader.CanReadRaw(3))
            return;
        reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&inavmeshID));
        if (!ppathingLOSGrid->TryLoadGame(apLoadGameBuffer))
            return;
        load.Keep(inavmeshID);
    }
    float fLoadedCellSize;
    float fLoadedRadius;
    float fLoadedUnk48;
    if (!reader.TryReadRaw(&fLoadedCellSize, 4) || !reader.TryReadRaw(&fLoadedRadius, 4) || !reader.TryReadRaw(&fLoadedUnk48, 4))
        return;
    PublishLOSRecords(reinterpret_cast<::FUN_00844700_Class *>((((SetAtHelper*)((char*)&this->kNavMeshGridMap)))), load);
    this->fCellSize = fLoadedCellSize;
    this->fRadius = fLoadedRadius;
    this->fUnk48 = fLoadedUnk48;
    ((LocX*)((char*)&this->kLocation))->LoadGame(apLoadGameBuffer);
}

struct FUN_00aa6060_shell
{
};
struct MapX
{
};
struct NiTMap
{
};
struct MyMap
{
};
struct FUN_00aa62e0_shell
{
    void FUN_00aa62e0();
};
struct FUN_006e03e0_shell : public PathingLOSGridMap
{
    void ClearMap();
};
// Calls AcquireLock on the object at offset 0x4c, deletes every value in the map at offset 8, then calls RemoveAll and FUN_00aa62e0.
// @fnv 0x006e03e0
void FUN_006e03e0_shell::ClearMap()
{
    ::fnv_00aa6060::AcquireLock((::ReadWriteLock *)(((FUN_00aa6060_shell*)((char*)&this->kLock))));
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>((((MapX*)((char*)&this->kNavMeshGridMap))))->GetFirstPos();
    while (position)
    {
        unsigned int key = 0;
        FUN_006e0480* value = 0;
        reinterpret_cast<::C6b7f20_Map *>((((NiTMap*)((char*)&this->kNavMeshGridMap))))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(key), (void **)&((void*&)value));
        delete value;
    }
    reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)((char*)&this->kNavMeshGridMap))))->FUN_00438af0();
    ((FUN_00aa62e0_shell*)((char*)&this->kLock))->FUN_00aa62e0();
}

struct ArrSI
{
    void* kEntries[4];  // a BSSimpleArray
    void* FUN_006e0ed0(unsigned int);
};

struct BGSSaveFormBuffer
{
};

struct BGSSaveGameBuffer : BGSSaveFormBuffer
{
    void FUN_00865f60(unsigned int);
};

struct FUN_006df9c0_shell
{
    unsigned char m_byte;
    unsigned char pad[3];
    ArrSI m_aiIndexedValues;
    unsigned int uiUnk14;
    unsigned int uiUnk18;

    void FUN_006df9c0(BGSSaveGameBuffer*);
};

// Saves the byte, a 4-byte value at offset 0x18, and, when m_byte is zero, the count and each element returned by FUN_006e0ed0.
// @fnv 0x006df9c0
void FUN_006df9c0_shell::FUN_006df9c0(BGSSaveGameBuffer* buffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(this, 1, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50((void*)&uiUnk18, 4, 0);

    if (!m_byte)
    {
        unsigned int count;

        count = (&m_aiIndexedValues) ? ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_aiIndexedValues))->GetName())) : 0;
        buffer->FUN_00865f60(count);

        for (unsigned int i = 0; i < count; ++i)
        {
            void* data = m_aiIndexedValues.FUN_006e0ed0(i);
            reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(data, 1, 0);
        }
    }
}

namespace fnv_006e10c0 {
struct BSSimpleArrayActor
{
    virtual void v0();
    virtual void* v1(unsigned int);

};

struct FUN_006e12c0_shell
{
};

struct FUN_006e1280_Class
{
};

struct FUN_0072ba80_shell
{
};

struct FUN_006e10c0_shell : BSSimpleArrayActor
{
    void* data;
    unsigned int size;
    unsigned int capacity;

    void FUN_006e10c0(unsigned int, bool);
};

// @fnv 0x006e10c0
void FUN_006e10c0_shell::FUN_006e10c0(unsigned int uiNewSize, bool abShrinkCapacity)
{
    if (uiNewSize == 0)
    {
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(this)->Clear(abShrinkCapacity);
    }
    else if (uiNewSize > capacity)
    {
        if (capacity == 0)
        {
            data = v1(uiNewSize);
            capacity = uiNewSize;
        }
        else
        {
            reinterpret_cast<::FUN_006e12c0_Class *>((reinterpret_cast<FUN_006e12c0_shell*>(this)))->SetData(uiNewSize, size);
            capacity = uiNewSize;
        }

        reinterpret_cast<::FUN_006e1280_Class *>((reinterpret_cast<FUN_006e1280_Class*>(this)))->FUN_006e1280(reinterpret_cast<char*>(data) + size,
                                                                  uiNewSize - size);
        size = uiNewSize;
    }
    else if (uiNewSize < size)
    {
        reinterpret_cast<::FUN_0072ba80_shell *>((reinterpret_cast<FUN_0072ba80_shell*>(this)))->FUN_0072ba80(reinterpret_cast<char*>(data) + uiNewSize,
                                                                  size - uiNewSize);
        size = uiNewSize;

        if (abShrinkCapacity && uiNewSize <= (capacity >> 2))
        {
            reinterpret_cast<::FUN_006e12c0_Class *>((reinterpret_cast<FUN_006e12c0_shell*>(this)))->SetData(uiNewSize, uiNewSize);
            capacity = uiNewSize;
        }
    }
    else
    {
        reinterpret_cast<::FUN_006e1280_Class *>((reinterpret_cast<FUN_006e1280_Class*>(this)))->FUN_006e1280(reinterpret_cast<char*>(data) + size,
                                                                  uiNewSize - size);
        size = uiNewSize;
    }
}
}  // namespace fnv_006e10c0

struct GO
{
    operator unsigned int();
};

class NavMesh
{
};

template <class T> class NiPointer : public GO
{
  public:
    T* ptr;
    NiPointer(T*);
    ~NiPointer();
};

struct Arr
{
    unsigned int* GetAt(int);
};

struct Lock
{
};

struct FUN_006e05f0_shell : public PathingLOSGridMap
{
    bool AddNavMeshes(ArrSI*);
};

// @fnv 0x006e05f0
bool FUN_006e05f0_shell::AddNavMeshes(ArrSI* aArg)
{
    ::fnv_00aa6060::AcquireLock((::ReadWriteLock *)(reinterpret_cast<Lock*>((unsigned char*)&this->kLock)));

    for (unsigned int index = 0; index < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((aArg))->GetName())); ++index)
    {
        NiPointer<NavMesh> ptrNavMesh2(reinterpret_cast<NavMesh*>(reinterpret_cast<Arr*>(aArg)->GetAt(index)));
        // The nav mesh and the map's value keep their native width.
        NavMesh* pnavMesh = ptrNavMesh2.ptr;
        FUN_006e0480* precord = 0;
        // What 006dfba0 reads from the nav mesh.
        unsigned int ientryCount = reinterpret_cast<::S006911c0 *>((pnavMesh))->FUN_006911c0();
        NavMeshInfo* pnavMeshInfo = reinterpret_cast<::FUN_0068efb0_shell *>((pnavMesh))->FUN_0068efb0();

        if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((reinterpret_cast<DummyPointerMap*>((unsigned char*)&this->kNavMeshGridMap)))->FUN_00853130(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pnavMesh))->FUN_0084e3a0())),
                         (::fnv_00853130::CombatThreatRecord *&)(precord)))
        {
            // 006e0730. With storage exhausted no record is made and the nav
            // mesh is left out of the map.
            precord = fnv::pathing::NewLOSRecord(pnavMeshInfo, ientryCount);

            if (precord)
                reinterpret_cast<::FUN_00844700_Class *>((reinterpret_cast<SetAtHelper*>((unsigned char*)&this->kNavMeshGridMap)))->FUN_00844700(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pnavMesh))->FUN_0084e3a0())), (std::uintptr_t)precord);
        }
        else
        {
            precord->Rebuild(pnavMeshInfo, ientryCount);
        }
    }

    reinterpret_cast<::FUN_00aa62e0_shell *>((reinterpret_cast<Lock*>((unsigned char*)&this->kLock)))->FUN_00aa62e0();
    return true;
}

struct IndexList
{
};

struct NavMeshKey;

struct NavMeshLookup
{
    IndexList* FUN_006911f0(unsigned int identifier);
};

struct NavMeshKey
{
    NavMeshLookup* pointer;
    NavMeshKey();
    ~NavMeshKey();
};

struct NavMeshResults
{
    unsigned char* data;
    unsigned int size;
    unsigned int capacity;
    unsigned int flags;
    signed char* AddOffset(unsigned int index);
};

struct FUN_006df440_owner
{
    union
    {
        bool valid;
        unsigned int state;
    };
    NavMeshResults results;
    NavMeshLookup* lookup;
    unsigned int identifier;
    bool InitFromLookup(NavMeshLookup* value);
};

// Copies bytes indexed by the lookup's index list into results, clears valid if any byte is <=0 or 0x7f, and returns false on missing data.
// @fnv 0x006df440
bool FUN_006df440_owner::InitFromLookup(NavMeshLookup* apLookup)
{
    unsigned char* const bytes = ((unsigned char *)(reinterpret_cast<::fnv_006e1610::PathingLOSMap *>((((::NavMeshLookup *)(::FUN_00559450((int *)(apLookup))))))->GetTriangleScore((std::uintptr_t)(((::NavMeshLookup *)(::FUN_00559450((int *)(lookup))))))));
    if (!bytes)
        return false;

    NavMeshKey key;
    if (!reinterpret_cast<::NavMeshInfo *>((lookup))->ResolveNavMesh((*(::NavMeshPtr *)(&key))))
        return false;

    IndexList* const indices = ((::NavMeshLookup *)(::FUN_00559450((int *)&(key))))->FUN_006911f0(identifier);
    if (!indices)
        return false;

    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(results))->Clear(0);
    reinterpret_cast<::fnv_006e10c0::FUN_006e10c0_shell *>(&(results))->FUN_006e10c0(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((indices))->GetName())), 1);
    valid = true;

    for (unsigned int index = 0; index < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((indices))->GetName())); ++index)
    {
        *results.AddOffset(index) = bytes[*((unsigned short *)&(reinterpret_cast<::FUN_0069dec0_class *>((indices))->FUN_0069dec0(index)))];
        if (*results.AddOffset(index) <= 0 || *results.AddOffset(index) == 0x7f)
            valid = false;
    }

    if (valid)
        reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(results))->Clear(1);

    return true;
}

class B6E01D0SolutionBase
{
  public:
    B6E01D0SolutionBase();
    virtual ~B6E01D0SolutionBase();

    int unk04;
};

class B6E01D0Array
{
  public:
    B6E01D0Array(int iGrowBy);
    ~B6E01D0Array();

    void* m_pData;
    int m_uiLogicalSize;
    int m_iCapacity;
    int m_iGrowBy;
};

class B6E01D0Location
{
  public:
    B6E01D0Location();
    ~B6E01D0Location();

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
};

class B6E01D0Matrix
{
  public:
    B6E01D0Matrix();

    float m_afEntry0;
    float m_afEntry1;
    float m_afEntry2;
};

class FUN_006e01d0_cls : public B6E01D0SolutionBase
{
  public:
    FUN_006e01d0_cls();
    virtual ~FUN_006e01d0_cls();

    B6E01D0Array m_kNodeArray;
    float m_fCost;
    B6E01D0Location m_kGoal;
    float m_fHitDistance;
    float m_fTime;
    B6E01D0Matrix m_kTransform;
};

// Constructs the solution object, initializing its array with grow-by 0x25 and zeroing cost, time and related floats.
// @fnv 0x006e01d0
FUN_006e01d0_cls::FUN_006e01d0_cls() : m_kNodeArray(0x25), m_fCost(0.0f), m_fHitDistance(0.0f), m_fTime(0.0f)
{}

struct Loc14
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Loc14();
    ~Loc14();
};

struct Sub1c
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
};

struct Sub4c
{
    int unk00;
};

unsigned char __cdecl FUN_006d8a20(void* aP, float aF, Loc14* aOut);

struct FUN_006e0320_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    Sub1c m_1c;
    float m_44;
    int unk48;
    Sub4c m_4c;
    void FUN_006e0320(std::uintptr_t aArg, float aF);
};

// @fnv 0x006e0320
void FUN_006e0320_cls::FUN_006e0320(std::uintptr_t aArg, float aF)
{
    ::fnv_00aa6060::AcquireLock((::ReadWriteLock *)&(m_4c));
    reinterpret_cast<::PathingLocation *>(&(m_1c))->operator=((*(const ::PathingLocation *)(aArg)));
    m_44 = aF;
    Loc14 locResult;
    if (FUN_006d8a20(&m_1c, aF, &locResult) != 0)
    {
        reinterpret_cast<::FUN_006e05f0_shell *>(this)->AddNavMeshes((::ArrSI *)(::Loc14 *)(&locResult));
    }
    else
    {
        m_44 = 0.0f;
    }
    reinterpret_cast<::FUN_00aa62e0_shell *>(&(m_4c))->FUN_00aa62e0();
}

struct NavMeshRef
{
    void* m_pObject;
    NavMeshRef();
    ~NavMeshRef();
};

struct NavMeshRefArray
{
    void* m_pBuffer;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
    unsigned int m_uiGrowBy;
    NavMeshRefArray();
    ~NavMeshRefArray();
};

struct LOSTarget;

struct LOSTargetPtr
{
    LOSTarget* m_pObject;
    operator LOSTarget*() const;
};

struct LOSTarget
{
};

struct LOSNavMeshInfo
{
};

struct LOSInfoMap
{
};

struct LOSLock
{
    void Lock();
};

struct LOSGridOwner
{
    int unk00;
    int unk04;
    LOSInfoMap kMap;
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
    LOSLock kLock;

    bool UpdateNavMeshes(LOSTargetPtr& arTarget);
};

// @fnv 0x006e07a0
bool LOSGridOwner::UpdateNavMeshes(LOSTargetPtr& arTarget)
{
    reinterpret_cast<::FUN_00aa5ff0_Class *>(&(kLock))->FUN_00aa5ff0();
    NavMeshRefArray kArray2;
    void* pPos3;
    for (pPos3 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(kMap))->GetFirstPos(); pPos3;)
    {
        LOSNavMeshInfo* pInfo;
        unsigned int uiKey;
        reinterpret_cast<::C6b7f20_Map *>(&(kMap))->FUN_006b7f20((::C6b7f20_Node **)&(pPos3), (unsigned int *)&(uiKey), (void **)&(pInfo));
        NavMeshRef kRef9;
        if (reinterpret_cast<::FUN_006e08f0_shell *>((pInfo))->FUN_006e08f0((::NavMeshPtr &)(kRef9)))
            reinterpret_cast<::S2f850 *>(&(kArray2))->AppendValue((const ::NavMeshPtr &)(kRef9));
    }
    reinterpret_cast<::FUN_006e1500_class *>((((LOSTarget*)arTarget)))->BuildNavMeshMap((::NavMeshCollection *)&(kArray2));
    for (pPos3 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(kMap))->GetFirstPos(); pPos3;)
    {
        LOSNavMeshInfo* pInfo2;
        unsigned int uiKey2;
        reinterpret_cast<::C6b7f20_Map *>(&(kMap))->FUN_006b7f20((::C6b7f20_Node **)&(pPos3), (unsigned int *)&(uiKey2), (void **)&(pInfo2));
        NavMeshRef kRefX;
        if (reinterpret_cast<::FUN_006e08f0_shell *>((pInfo2))->FUN_006e08f0((::NavMeshPtr &)(kRefX)))
            reinterpret_cast<::List6DFD *>((pInfo2))->ApplyAllTriFlags((std::intptr_t)&(arTarget));
    }
    reinterpret_cast<::Lock00aa62c0 *>(&(kLock))->FUN_00aa62c0();
    return true;
}

struct NavMeshX
{
};

template <class T> struct NiPtr
{
    T* m_pObject;
    NiPtr(T* apObject);
    ~NiPtr();
    T* operator->() const;
};

struct NavMeshArrayX
{
    NavMeshX* GetAt(unsigned int auiIndex);
};

struct EntryMapX
{
};

struct LockX
{
    void Lock();
};


struct PathingLOSGridMapX
{
    int unk00;
    int unk04;
    EntryMapX kMap;
    int unk0C;
    int unk10;
    int unk14;
    float fValue;
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
    LockX kLock;

    bool UpdateFromNavMeshArray(const NiPtr<NavMeshArrayX>& arArray);
};

class C6E0A90List
{
  public:
    C6E0A90List();
    ~C6E0A90List();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_006e0a90 : public C6E0A90List
{
  public:
    FUN_006e0a90(const FUN_006e0a90& kOther);


    int m_iArrayLength;
};

// @fnv 0x006e0a90
FUN_006e0a90::FUN_006e0a90(const FUN_006e0a90& kOther)
{
    m_iArrayLength = 0;
    reinterpret_cast<::fnv_006dfb00::Owner_006dfb00 *>(this)->SetInput((::fnv_006dfb00::Input_006dfb00 *)&(kOther));
}

struct FUN_006e0b00_cls
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
    unsigned int m_i30;
    unsigned int m_i34;
    float GetRatio();
};
// 006dfb00 on the map record: stores the info, resolves its nav mesh and
// rebuilds the record from it; an info with no nav mesh is cleared again.
static void SetLOSRecordInfo(FUN_006e0480* apRecord, NavMeshInfo* apInfo)
{
    apRecord->pNavMeshInfo = apInfo;
    NavMeshKey key;
    if (!apInfo->ResolveNavMesh((*(::NavMeshPtr *)(&key))))
    {
        apRecord->pNavMeshInfo = 0;
        return;
    }
    void* pnavMesh = ((void *)(::FUN_00559450((int *)&(key))));
    unsigned int ientryCount = reinterpret_cast<::S006911c0 *>((pnavMesh))->FUN_006911c0();
    apRecord->Rebuild(reinterpret_cast<::FUN_0068efb0_shell *>((pnavMesh))->FUN_0068efb0(), ientryCount);
}

// Locks the map, creates or finds a record per nav mesh and updates it, then stores the array value in fValue and unlocks.
// @fnv 0x006e0920
bool PathingLOSGridMapX::UpdateFromNavMeshArray(const NiPtr<NavMeshArrayX>& arNavMeshArray)
{
    ::fnv_00aa6060::AcquireLock((::ReadWriteLock *)&(kLock));
    for (unsigned int i6 = 0; i6 < reinterpret_cast<::FUN_006d8990_shell *>(((arNavMeshArray).operator->()))->GetFlags(); i6++)
    {
        NiPtr<NavMeshX> spNavMesh2(arNavMeshArray->GetAt(i6));
        FUN_006e0480* pEntry = 0;
        if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&(kMap))->FUN_00853130(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((spNavMesh2).operator->()))->FUN_0084e3a0())), (::fnv_00853130::CombatThreatRecord *&)(pEntry)))
        {
            // 006e0a90: an empty record, then 006dfb00. With storage exhausted
            // no record is made and the nav mesh is left out of the map.
            pEntry = fnv::pathing::NewLOSRecord();
            if (!pEntry)
                continue;
            SetLOSRecordInfo(pEntry, reinterpret_cast<::FUN_0068efb0_shell *>(((spNavMesh2).operator->()))->FUN_0068efb0());
            reinterpret_cast<::FUN_00844700_Class *>(&(kMap))->FUN_00844700(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((spNavMesh2).operator->()))->FUN_0084e3a0())), (std::uintptr_t)(pEntry));
        }
        reinterpret_cast<::FUN_006dfd70_Class *>((pEntry))->FUN_006dfd70((std::uintptr_t)&(arNavMeshArray));
    }
    fValue = reinterpret_cast<::FUN_006e0b00_cls *>(((arNavMeshArray).operator->()))->GetRatio();
    reinterpret_cast<::FUN_00aa62e0_shell *>(&(kLock))->FUN_00aa62e0();
    return true;
}

// Returns m_i30 divided by the sum of m_i30 and m_i34, or 1.0 when that sum is zero.
// @fnv 0x006e0b00
float FUN_006e0b00_cls::GetRatio()
{
    unsigned int total = m_i30 + m_i34;
    if (total != 0)
    {
        return (float)((double)m_i30 / (double)total);
    }
    else
    {
        return 1.0f;
    }
}

struct FUN_0044edb0_shell
{
};
struct FUN_00559450_shell
{
};
struct FUN_00853130_shell
{
};
struct FUN_006dfdc0_shell
{
};

struct FUN_006e0b50_cls
{
    unsigned char m_00[8];
    unsigned char m_08[0x10];

    bool FUN_006e0b50(void* aArg);
};

// @fnv 0x006e0b50
bool FUN_006e0b50_cls::FUN_006e0b50(void* aArg)
{
    ::fnv_00853130::CombatThreatRecord* value;
    void* pHolder = ((void *)(reinterpret_cast<::MagicCaster_shell *>((((FUN_0044edb0_shell*)aArg)))->FUN_0044edb0()));
    if (pHolder == 0 || ((FUN_006df760_shell*)aArg)->GetShortValueAtOffset24() == 0xffff)
    {
        return false;
    }
    value = 0;
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((((FUN_00853130_shell*)&this->m_08[0])))->FUN_00853130((std::uintptr_t)(((void *)(::FUN_00559450((int *)(((FUN_00559450_shell*)pHolder)))))), value))
    {
        return reinterpret_cast<::FUN_006dfdc0_Class *>((((FUN_006dfdc0_shell*)value)))->FUN_006dfdc0((::PathingLocation *)(aArg));
    }
    return false;
}

struct LoadBufferEx
{
};
struct PathingCell
{
};
struct CellMap
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct CellData
{
    virtual void LoadGame(LoadBufferEx* buffer);
    unsigned int unk04, unk08, unk0c, unk10, unk14;
    unsigned int unk18, unk1c, unk20, unk24;
};
struct PathingGrid
{
    unsigned int unk00;
    unsigned int unk04;
    CellMap cells;
    unsigned int unk18;
    CellData metadata;
    unsigned int unk44;
    unsigned int unk48;

    void SaveGame(LoadBufferEx* buffer);
};
// @fnv 0x006e0c40
void PathingGrid::SaveGame(LoadBufferEx* buffer)
{
    unsigned int writtenCount = 0;
    unsigned int startOffset = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();
    void* position = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(cells))->GetFirstPos();
    while (position != 0)
    {
        PathingCell* cell = 0;
        unsigned int key;
        reinterpret_cast<::C6b7f20_Map *>(&(cells))->FUN_006b7f20((::C6b7f20_Node **)&(position), (unsigned int *)&(key), (void **)&(cell));
        if (cell != 0)
        {
            reinterpret_cast<::FUN_00865db0_shell *>((buffer))->FUN_00865db0(key, 0);
            reinterpret_cast<::FUN_006dffc0_Class *>((cell))->WriteToBuffer((::FUN_00865db0_shell *)(buffer));
            writtenCount++;
        }
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(writtenCount, startOffset);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk18, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk44, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&unk48, 4, 0);
    metadata.LoadGame(buffer);
}

struct Owner6df780
{
    bool valid;
    NavMeshResults results;
    NavMeshLookup* lookup;
    unsigned int identifier;
    bool UpdateNavMeshResults(FUN_006df760_shell* a1, unsigned char a2);
};
// @fnv 0x006df780
bool Owner6df780::UpdateNavMeshResults(FUN_006df760_shell* a1, unsigned char a2)
{
    NavMeshKey key;
    if (!reinterpret_cast<::NavMeshInfo *>((lookup))->ResolveNavMesh((*(::NavMeshPtr *)(&key))))
        return false;
    IndexList* list3 = ((::NavMeshLookup *)(::FUN_00559450((int *)&(key))))->FUN_006911f0(identifier);
    if (valid)
    {
        if (a2)
            return true;
        else
        {
            valid = false;
            reinterpret_cast<::fnv_006e10c0::FUN_006e10c0_shell *>(&(results))->FUN_006e10c0(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((list3))->GetName())), 1);
            for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((list3))->GetName())); ++i)
            {
                unsigned short w = *((unsigned short *)&(reinterpret_cast<::FUN_0069dec0_class *>((list3))->FUN_0069dec0(i)));
                if (w == a1->GetShortValueAtOffset24())
                    *results.AddOffset(i) = -1;
                else
                    *results.AddOffset(i) = 1;
            }
            return true;
        }
    }
    else
    {
        if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((list3))->GetName())) != ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((((IndexList*)&results)))->GetName())))
            return false;
        for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>((list3))->GetName())); ++i)
        {
            unsigned short w = *((unsigned short *)&(reinterpret_cast<::FUN_0069dec0_class *>((list3))->FUN_0069dec0(i)));
            if (w == a1->GetShortValueAtOffset24())
            {
                *results.AddOffset(i) = a2 ? 1 : -1;
                return true;
            }
        }
    }
    return false;
}

// Destructor of an owning array: delete every element, then the base array frees its storage.

class E04B0Element
{
  public:
    ~E04B0Element();

    int unk00;
};

class E04B0Array
{
  public:
    ~E04B0Array();
    E04B0Element*& GetAt(unsigned int uiIndex) const;

    void* m_pBuffer;
    unsigned int m_uiCapacity;
    unsigned int m_uiSize;
};

class FUN_006e04b0 : public E04B0Array
{
  public:
    ~FUN_006e04b0();
};

// Destructor that iterates over the array and deletes each element pointer returned by GetAt.
// @fnv 0x006e04b0
FUN_006e04b0::~FUN_006e04b0()
{
    for (unsigned int i = 0; i < ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(this)->GetName())); i++)
        delete GetAt(i);
}

namespace fnv_006e0730 {
class C6E0730List
{
  public:
    C6E0730List();
    ~C6E0730List();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_006e0730 : public C6E0730List
{
  public:
    FUN_006e0730(const FUN_006e0730& kOther);


    int m_iArrayLength;
};

// @fnv 0x006e0730
FUN_006e0730::FUN_006e0730(const FUN_006e0730& kOther)
{
    m_iArrayLength = 0;
    reinterpret_cast<::InfoEntryArrY *>(this)->RebuildFromNavMesh((const ::NavMeshPtrY &)(kOther));
}
}  // namespace fnv_006e0730

struct FUN_006a62f0_Class
{
    int m_00;
    int m_iOffset;
    std::intptr_t AddOffset(void*);
};

// @fnv 0x006a62f0
std::intptr_t FUN_006a62f0_Class::AddOffset(void* arg)
{
    return m_iOffset + reinterpret_cast<std::intptr_t>(arg);
}

struct Pathing;
struct TESConditionItem;
struct TES;

class TESObjectREFR;
struct Pathing
{
public:
    ::TESObjectREFR *FindReferenceByFormId(unsigned int);
};

struct TES
{
};

struct TESConditionItem
{
};

extern unsigned int _data_011c16bc;

// 006e0070 has no failure result. When its data ends early the record is left
// as it was; 006e0d20 reads the outcome through TryLoadGame.
// @fnv 0x006e0070
void FUN_006e0480::FUN_006e0070(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TryLoadGame(apLoadGameBuffer);
}

bool FUN_006e0480::TryLoadGame(BGSLoadFormBuffer* apLoadGameBuffer)
{
    fnv::pathing::LOSSaveReader reader(*apLoadGameBuffer);
    unsigned int inavmeshID;

    inavmeshID = 0;
    // The packed form ID is three bytes and a separator.
    if (!reader.CanReadRaw(3))
        return false;
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)(&inavmeshID));

    NavMeshInfo* ppreviousInfo = pNavMeshInfo;
    pNavMeshInfo =
        ((::NavMeshInfo *)(((Pathing*)((::Pathing *)(reinterpret_cast<::Owner45A *>((((TES*)g_TES)))->FUN_0045af00())))->FindReferenceByFormId(inavmeshID)));

    if (!TryLoadEntries(reader))
    {
        pNavMeshInfo = ppreviousInfo;
        return false;
    }
    return true;
}

struct LOSGridBase
{
    virtual ~LOSGridBase();
    int unk04;
};
struct LOSGridMap08
{
    ~LOSGridMap08();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct LOSGridLock1C
{
    ~LOSGridLock1C();
    int unk00;
};
struct LOSGridMapReal : LOSGridBase
{
    LOSGridMap08 kMap;
    LOSGridLock1C kLock;
    virtual ~LOSGridMapReal();
};
// Calls FUN_006e02a0, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x006e0270
void* PathingLOSGridMap::FUN_006e0270(unsigned int flags)
{
    reinterpret_cast<::LOSGridMapReal *>((this))->::LOSGridMapReal::~LOSGridMapReal();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x54);
    return this;
}
// @fnv 0x006e02a0
LOSGridMapReal::~LOSGridMapReal()
{
    reinterpret_cast<::FUN_006e03e0_shell *>(this)->ClearMap();
}
