// fallout_shared/pathfinding/navmeshinfo.cpp: NavMeshInfo, NavMeshInfoSaveShell, NavInfo (15 functions)

#include "fnv/decl/ActorMover.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004941c0_shell.h"
#include "fnv/decl/FUN_0063c8a0_shell.h"
#include "fnv/decl/FUN_0068f0a0_shell.h"
#include "fnv/decl/FUN_0068f1d0_shell.h"
#include "fnv/decl/FUN_0068f2c0_shell.h"
#include "fnv/decl/FUN_0068f6b0_shell.h"
#include "fnv/decl/FUN_00690e10_shell.h"
#include "fnv/decl/FUN_00693b70_shell.h"
#include "fnv/decl/FUN_00693d30_shell.h"
#include "fnv/decl/FUN_00693d50_shell.h"
#include "fnv/decl/FUN_0069bda0_cls.h"
#include "fnv/decl/FUN_0069e090_class.h"
#include "fnv/decl/FUN_006bf8f0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/LDMesh.h"
#include "fnv/decl/NavMesh.h"
#include "fnv/decl/NavMeshProxy.h"
#include "fnv/decl/Owner45A.h"
#include "fnv/decl/Owner69c4c0.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_006f2290__BSSimpleArrayActor.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_00990a60__FUN_00990a60_shell.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00558000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_011de000.h"
class NavMeshInfo;
class TESObjectREFR;
class TESForm;
class TESFile;
class Pathing;
class TES;
class TESObjectWEAP;
class SandboxProcedureData;
class InventoryStackRecord;


class TESForm
{
  public:
public:
    bool GetDisabled() const;
public:
    void SetCollisionDisabled(bool);
};

class TESFile
{
  public:
    bool IsEndianConversionRequired();
};

template <int N> struct EndianSizeTag
{
};
extern "C" void* __cdecl memcpy(void* destination, const void* source, unsigned int size);

class TESObjectREFR;
class Pathing
{
  public:
public:
    ::TESObjectREFR *FindReferenceByFormId(unsigned int);
};
class TES
{
  public:
};
class TESObjectWEAP;

template <class T> class NiTNewInterface
{
};
template <class T, class I> class NiTArray
{
  public:
    T& GetAt(unsigned int index);
};

template <class T, unsigned int N> class BSSimpleArray
{
  public:
    void** vtable;
    T* buffer;
    unsigned int size;
    unsigned int reservedSize;
    BSSimpleArray();
    ~BSSimpleArray();
    void Clear(bool freeBuffer);
    void FUN_006b3eb0(unsigned int size, bool freeBuffer);
    unsigned int GetSize();
    void SetSize(unsigned int newSize, bool freeBuffer);
    void Remove(unsigned int index, bool freeBuffer);
    void CopyTo(BSSimpleArray<T, N>* other);
    T& operator[](unsigned int index);
};

struct NavMeshInfoPoint
{
    float x, y, z;
};
class NavMeshBounds
{
  public:
    unsigned char data[56];
    ~NavMeshBounds();
    NavMeshBounds();  // unnamed constructor at 0x0069bcf0
    void CopyTo(NavMeshBounds* other);
};
void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

class NavMeshPtr;
class NavMeshInfo
{
  public:
    unsigned int m_uiNavMeshID;
    unsigned int m_uiParentSpaceID;
    unsigned int uiFlags;
    int m_uiPathingFlags;
    NavMeshInfoPoint m_kNavMeshPosition;
    TESForm* m_pParentSpace;
    float m_fStoredValue;
    BSSimpleArray<NavMeshInfo*, 1024> m_kConnectedNavMeshInfos;
    BSSimpleArray<NavMeshInfo*, 1024> m_kPreferredConnections;
    BSSimpleArray<TESObjectREFR*, 1024> m_kDoorReferences;
    void* m_pLocationNavMesh;
    NavMeshBounds* pBounds;

    ~NavMeshInfo();  // external cleanup routine at 0x006b4790; needed by the native deleting destructor
    void CopyTo(NavMeshInfo* other);
    inline void Delete();
    void ReleaseNavMesh();
    void LoadSerializedData(char* data, TESFile* file, int version);
public:
    bool AcquireNavMesh(::NavMeshPtr &);
};

// @fnv 0x0069af10
template <> BSSimpleArray<NavMeshInfo*, 1024>::~BSSimpleArray()
{
    vtable = (void**)0x0106b1a4;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((((BSSimpleArray<SandboxProcedureData, 1024>*)this)))->Clear(true);
}

// @fnv 0x006b5490
void NavMeshInfo::ReleaseNavMesh()
{
    unsigned int ItemUpdateArray = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kDoorReferences)))->GetName()));
    for (unsigned int i = 0; i < ItemUpdateArray; ++i)
    {
        TESObjectREFR* door =
            ((NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*)&m_kDoorReferences)->GetAt(i);
        ((NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*)&m_kDoorReferences)->GetAt(i) =
            (TESObjectREFR*)::FUN_004839c0((unsigned int)door);
        if (!((NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> >*)&m_kDoorReferences)->GetAt(i))
        {
            ::FUN_005b5e40();
            reinterpret_cast<::FUN_006bf8f0_Class *>((((BSSimpleArray<InventoryStackRecord*, 1024>*)&m_kDoorReferences)))->FUN_006bf8f0(i, true);
            --ItemUpdateArray;
            --i;
        }
    }
}

// @fnv 0x006b51a0
void NavMeshInfo::LoadSerializedData(char* data, TESFile* file, int version)
{
    unsigned int count = 0;
    memcpy(&count, data, 4);
    if (file->IsEndianConversionRequired())
        ::FUN_00401080((int *)(unsigned int *)(&count));
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((((BSSimpleArray<TESObjectWEAP*, 1024>*)&m_kConnectedNavMeshInfos)))->FUN_006f2290(count, true);
    data += 4;
    for (unsigned int adjacentIndex = 0; adjacentIndex < count; ++adjacentIndex)
    {
        unsigned int adjacentID = *(unsigned int*)data;
        if (file->IsEndianConversionRequired())
            ::FUN_00401080((int *)(unsigned int *)(&adjacentID));
        ::ResolveFormID((unsigned int *)&(adjacentID), file);
        if (adjacentID)
        {
            ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kConnectedNavMeshInfos)->operator[](adjacentIndex) =
                ((::NavMeshInfo *)(((::Pathing *)(reinterpret_cast<::Owner45A *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_0045af00()))->FindReferenceByFormId({})));
        }
        else
        {
            ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kConnectedNavMeshInfos)->operator[](adjacentIndex) = 0;
        }
        data += 4;
    }

    if (version >= 11)
    {
        count = 0;
        memcpy(&count, data, 4);
        if (file->IsEndianConversionRequired())
            ::FUN_00401080((int *)(unsigned int *)(&count));
        reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((((BSSimpleArray<TESObjectWEAP*, 1024>*)&m_kPreferredConnections)))->FUN_006f2290(count, true);
        data += 4;
        for (unsigned int preferredIndex = 0; preferredIndex < count; ++preferredIndex)
        {
            unsigned int preferredID = *(unsigned int*)data;
            if (file->IsEndianConversionRequired())
                ::FUN_00401080((int *)(unsigned int *)(&preferredID));
            ::ResolveFormID((unsigned int *)&(preferredID), file);
            if (preferredID)
            {
                ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kPreferredConnections)->operator[](preferredIndex) =
                    ((::NavMeshInfo *)(((::Pathing *)(reinterpret_cast<::Owner45A *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_0045af00()))->FindReferenceByFormId({})));
            }
            else
            {
                ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kPreferredConnections)->operator[](preferredIndex) = 0;
            }
            data += 4;
        }
    }

    memcpy(&count, data, 4);
    if (file->IsEndianConversionRequired())
        ::FUN_00401080((int *)(unsigned int *)(&count));
    reinterpret_cast<::fnv_006f2290::BSSimpleArrayActor *>((((BSSimpleArray<TESObjectWEAP*, 1024>*)&m_kDoorReferences)))->FUN_006f2290(count, true);
    data += 4;
    for (unsigned int doorIndex = 0; doorIndex < count; ++doorIndex)
    {
        unsigned int doorID = *(unsigned int*)data;
        if (file->IsEndianConversionRequired())
            ::FUN_00401080((int *)(unsigned int *)(&doorID));
        ::ResolveFormID((unsigned int *)&(doorID), file);
        ((BSSimpleArray<NavMeshInfo*, 1024>*)&m_kDoorReferences)->operator[](doorIndex) = (NavMeshInfo*)doorID;
        data += 4;
    }
}

// @fnv 0x006b5ab0
void NavMeshInfo::CopyTo(NavMeshInfo* other)
{
    other->m_uiNavMeshID = m_uiNavMeshID;
    other->m_uiParentSpaceID = m_uiParentSpaceID;
    other->uiFlags = uiFlags;
    other->m_uiPathingFlags = m_uiPathingFlags;
    other->m_kNavMeshPosition = m_kNavMeshPosition;
    other->m_pParentSpace = m_pParentSpace;
    other->m_pLocationNavMesh = m_pLocationNavMesh;
    ((BSSimpleArray<unsigned int, 1024>*)&m_kConnectedNavMeshInfos)
        ->CopyTo((BSSimpleArray<unsigned int, 1024>*)&other->m_kConnectedNavMeshInfos);
    ((BSSimpleArray<unsigned int, 1024>*)&m_kPreferredConnections)
        ->CopyTo((BSSimpleArray<unsigned int, 1024>*)&other->m_kPreferredConnections);
    ((BSSimpleArray<unsigned int, 1024>*)&m_kDoorReferences)
        ->CopyTo((BSSimpleArray<unsigned int, 1024>*)&other->m_kDoorReferences);
    if (pBounds)
    {
        if (!other->pBounds)
            other->pBounds = new NavMeshBounds;
        pBounds->CopyTo(other->pBounds);
    }
    else
    {
        if (other->pBounds)
        {
            delete other->pBounds;
        }
        other->pBounds = 0;
    }
}

// Initializes the array's vtable and calls FUN_006b3eb0 with 0 and false.
// Default constructor for BSSimpleArray<NavMeshInfo*, 1024> that sets the vtable and calls FUN_006b3eb0 with 0 and false.
// @fnv 0x0069aee0
template <> BSSimpleArray<NavMeshInfo*, 1024>::BSSimpleArray()
{
    vtable = (void**)0x0106b1a4;
    FUN_006b3eb0(0, false);
}

// Deletes this NavMeshInfo object by calling delete on itself.
// @fnv 0x006b6390
inline void NavMeshInfo::Delete()
{
    delete this;
}

// Instantiate the compiler's deleting destructor through the native deletion member.
void (NavMeshInfo::*navmeshinfo_delete)() = &NavMeshInfo::Delete;

struct ArrSI
{
};

struct FUN_0069c460_shell
{
    int FUN_0069c460();
};

// Computes a size by summing fixed offsets with flag counts from the ArrSI objects at offsets 0x28 and 0x18 scaled by 0xc and 6.
// @fnv 0x0069c460
int FUN_0069c460_shell::FUN_0069c460()
{
    int result = 0;
    result += 0x18;
    result += 2;
    result += 2;
    result += ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x28))))->GetName())) * 0xc;
    result += ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x18))))->GetName())) * 6;
    return result;
}

namespace fnv_006b4e10 {
struct ArrSI
{
};

class FUN_006b4e10_shell
{
  public:
    unsigned int FUN_006b4e10();
};

// @fnv 0x006b4e10
unsigned int FUN_006b4e10_shell::FUN_006b4e10()
{
    unsigned int v = 0;
    v += 4;
    v += ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x24))))->GetName())) * 4;
    v += 4;
    v += ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x34))))->GetName())) * 4;
    v += 4;
    v += ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x44))))->GetName())) * 4;
    return v;
}
}  // namespace fnv_006b4e10

namespace fnv_006b5a90 {
struct ArrSI
{
};

struct FUN_006b5a90_shell
{
    unsigned int FUN_006b5a90();
};

// @fnv 0x006b5a90
unsigned int FUN_006b5a90_shell::FUN_006b5a90()
{
    return ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)((char*)this + 0x58))))->GetName()));
}
}  // namespace fnv_006b5a90

struct FUN_006b4850_t : public NavMeshBounds
{
    void* FUN_006b4850(unsigned int flags);
};
// Calls FUN_0069bda0, then deallocates this if flags has bit 1 set, and returns this.
// @fnv 0x006b4850
void* FUN_006b4850_t::FUN_006b4850(unsigned int flags)
{
    reinterpret_cast<::FUN_0069bda0_cls *>(this)->FUN_0069bda0_cls::~FUN_0069bda0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FormIDStub
{
};
struct Flt
{
    operator unsigned int();
};
struct NavMeshPtr
{
    void* m_pObject;
    NavMeshPtr();
    ~NavMeshPtr();
};
struct NavMeshInfoHelper
{
};
struct Arr
{
    unsigned int* GetAt(int index);
};

struct NavMeshInfoSaveShell : NavMeshInfo
{
    void SaveToBuffer(char* apData);
};

// @fnv 0x006b4e80
void NavMeshInfoSaveShell::SaveToBuffer(char* apData)
{
    TESObjectREFR* pRefr;
    {
        NavMeshInfo* pInfo;
        {
            unsigned int ItemUpdateArray;
            {
                unsigned int uiTemp;

                uiTemp = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&m_kConnectedNavMeshInfos)))->GetName()));
                if (((bool)(::FUN_00401500())))
                    ::FUN_00401080((int *)(unsigned int *)(&uiTemp));
                *(unsigned int*)apData = uiTemp;
                apData += 4;
                ItemUpdateArray = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&m_kConnectedNavMeshInfos)))->GetName()));
                pInfo = 0;
                for (unsigned int i = 0; i < ItemUpdateArray; i++)
                {
                    pInfo = (NavMeshInfo*)*((Arr*)&m_kConnectedNavMeshInfos)->GetAt(i);
                    NavMeshPtr navMeshPtr;
                    if (reinterpret_cast<::NavMeshInfo *>((((NavMeshInfoHelper*)pInfo)))->AcquireNavMesh(navMeshPtr))
                    {
                        uiTemp = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((FormIDStub*)(unsigned int)*(Flt*)&navMeshPtr)))->FUN_0084e3a0()));
                        if (((bool)(::FUN_00401500())))
                            ::FUN_00401080((int *)(unsigned int *)(&uiTemp));
                        *(unsigned int*)apData = uiTemp;
                    }
                    apData += 4;
                }

                uiTemp = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&m_kPreferredConnections)))->GetName()));
                if (((bool)(::FUN_00401500())))
                    ::FUN_00401080((int *)(unsigned int *)(&uiTemp));
                *(unsigned int*)apData = uiTemp;
                apData += 4;
                ItemUpdateArray = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&m_kPreferredConnections)))->GetName()));
                pInfo = 0;
                for (unsigned int j = 0; j < ItemUpdateArray; j++)
                {
                    pInfo = (NavMeshInfo*)*((Arr*)&m_kPreferredConnections)->GetAt(j);
                    NavMeshPtr navMeshPtr;
                    if (reinterpret_cast<::NavMeshInfo *>((((NavMeshInfoHelper*)pInfo)))->AcquireNavMesh(navMeshPtr))
                    {
                        uiTemp = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((FormIDStub*)(unsigned int)*(Flt*)&navMeshPtr)))->FUN_0084e3a0()));
                        if (((bool)(::FUN_00401500())))
                            ::FUN_00401080((int *)(unsigned int *)(&uiTemp));
                        *(unsigned int*)apData = uiTemp;
                    }
                    apData += 4;
                }

                uiTemp = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&m_kDoorReferences)))->GetName()));
                if (((bool)(::FUN_00401500())))
                    ::FUN_00401080((int *)(unsigned int *)(&uiTemp));
                *(unsigned int*)apData = uiTemp;
                apData += 4;
                ItemUpdateArray = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((ArrSI*)&m_kDoorReferences)))->GetName()));
                pRefr = 0;
                for (unsigned int k = 0; k < ItemUpdateArray; k++)
                {
                    pRefr = (TESObjectREFR*)*((Arr*)&m_kDoorReferences)->GetAt(k);
                    if (pRefr)
                    {
                        uiTemp = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((FormIDStub*)pRefr)))->FUN_0084e3a0()));
                        if (((bool)(::FUN_00401500())))
                            ::FUN_00401080((int *)(unsigned int *)(&uiTemp));
                        *(unsigned int*)apData = uiTemp;
                    }
                    else
                    {
                        *(unsigned int*)apData = 0;
                    }
                    apData += 4;
                }
            }
        }
    }
}

struct NiPoint3
{
    float x;
    float y;
    float z;
public:
    static const ::NiPoint3 ZERO;
};

struct FUN_0069c4c0_shell
{
};


struct FUN_006b48f0_shell : public NavMeshInfo
{
    void WriteToChunkBuffer(char* apChunkBuffer);
};

// Serializes uiFlags, form IDs, a NiPoint3, optional bounds data and a float into apChunkBuffer, byte-swapping each value when FUN_00401500 is true.
// @fnv 0x006b48f0
void FUN_006b48f0_shell::WriteToChunkBuffer(char* apChunkBuffer)
{
    unsigned int itempint;
    float ftempFloat;
    NiPoint3 temppoint;

    itempint = this->uiFlags;
    if (((bool)(::FUN_00401500())))
        ::FUN_00401080((int *)(unsigned int *)(&itempint));
    __memcpy(apChunkBuffer, &itempint, 4);
    apChunkBuffer += 4;

    if (this->m_pLocationNavMesh)
    {
        if (((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<FormIDStub*>(this->m_pLocationNavMesh)))->FUN_0084e3a0())) != this->m_uiNavMeshID)
            this->m_uiNavMeshID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<FormIDStub*>(this->m_pLocationNavMesh)))->FUN_0084e3a0()));
    }

    itempint = this->m_uiNavMeshID;
    if (((bool)(::FUN_00401500())))
        ::FUN_00401080((int *)(unsigned int *)(&itempint));
    __memcpy(apChunkBuffer, &itempint, 4);
    apChunkBuffer += 4;

    this->m_uiParentSpaceID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<FormIDStub*>(this->m_pParentSpace)))->FUN_0084e3a0()));
    itempint = this->m_uiParentSpaceID;
    if (((bool)(::FUN_00401500())))
        ::FUN_00401080((int *)(unsigned int *)(&itempint));
    __memcpy(apChunkBuffer, &itempint, 4);
    apChunkBuffer += 4;

    itempint = this->m_uiPathingFlags;
    if (((bool)(::FUN_00401500())))
        ::FUN_00401080((int *)(unsigned int *)(&itempint));
    __memcpy(apChunkBuffer, &itempint, 4);
    apChunkBuffer += 4;

    temppoint = *reinterpret_cast<const NiPoint3*>(&this->m_kNavMeshPosition);
    if (((bool)(::FUN_00401500())))
    {
        ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&temppoint.x)));
        ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&temppoint.y)));
        ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&temppoint.z)));
    }
    __memcpy(apChunkBuffer, &temppoint, 12);
    apChunkBuffer += 12;

    if (this->pBounds)
    {
        reinterpret_cast<::Owner69c4c0 *>((reinterpret_cast<FUN_0069c4c0_shell*>(this->pBounds)))->WriteToBuffer(apChunkBuffer);
        apChunkBuffer += reinterpret_cast<FUN_0069c460_shell*>(this->pBounds)->FUN_0069c460();
    }

    ftempFloat = this->m_fStoredValue;
    if (((bool)(::FUN_00401500())))
        ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&ftempFloat)));
    __memcpy(apChunkBuffer, &ftempFloat, 4);
    apChunkBuffer += 4;
}

struct FUN_006b4b50_shell : public NavMeshInfo
{
    void LoadNavMeshInfo(char*, TESFile*, int);
};


struct TESFileAccessor
{
};

struct FUN_0069c8f0_shell
{
};

// @fnv 0x006b4b50
void FUN_006b4b50_shell::LoadNavMeshInfo(char* apChunkBuffer, TESFile* apFile, int aiFileVersionNumber)
{
    __memcpy(&this->uiFlags, apChunkBuffer, 4);
    if (reinterpret_cast<::TESFile *>((((TESFileAccessor*)apFile)))->IsEndianConversionRequired())
    {
        ::FUN_00401080((int *)(unsigned int *)(&this->uiFlags));
    }
    apChunkBuffer += 4;

    __memcpy(&this->m_uiNavMeshID, apChunkBuffer, 4);
    if (reinterpret_cast<::TESFile *>((((TESFileAccessor*)apFile)))->IsEndianConversionRequired())
    {
        ::FUN_00401080((int *)(unsigned int *)(&this->m_uiNavMeshID));
    }
    apChunkBuffer += 4;

    ::ResolveFormID(&this->m_uiNavMeshID, apFile);

    __memcpy(&this->m_uiParentSpaceID, apChunkBuffer, 4);
    if (reinterpret_cast<::TESFile *>((((TESFileAccessor*)apFile)))->IsEndianConversionRequired())
    {
        ::FUN_00401080((int *)(unsigned int *)(&this->m_uiParentSpaceID));
    }
    apChunkBuffer += 4;

    ::ResolveFormID(&this->m_uiParentSpaceID, apFile);

    __memcpy(reinterpret_cast<unsigned int*>(&this->m_uiPathingFlags), apChunkBuffer, 4);
    if (reinterpret_cast<::TESFile *>((((TESFileAccessor*)apFile)))->IsEndianConversionRequired())
    {
        ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&this->m_uiPathingFlags)));
    }
    apChunkBuffer += 4;

    __memcpy(&this->m_kNavMeshPosition, apChunkBuffer, 12);
    if (reinterpret_cast<::TESFile *>((((TESFileAccessor*)apFile)))->IsEndianConversionRequired())
    {
        ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&this->m_kNavMeshPosition.x)));
        ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&this->m_kNavMeshPosition.y)));
        ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&this->m_kNavMeshPosition.z)));
    }
    apChunkBuffer += 12;

    if ((this->uiFlags & 0x20) != 0)
    {
        if (!this->pBounds)
            this->pBounds = new NavMeshBounds;

        reinterpret_cast<::LDMesh *>((((FUN_0069c8f0_shell*)this->pBounds)))->ReadFromBuffer(apChunkBuffer, (::LDFile *)(apFile), aiFileVersionNumber);
        apChunkBuffer += ((FUN_0069c460_shell*)this->pBounds)->FUN_0069c460();
    }

    if (aiFileVersionNumber >= 10)
    {
        __memcpy(reinterpret_cast<unsigned int*>(&this->m_fStoredValue), apChunkBuffer, 4);
        if (reinterpret_cast<::TESFile *>((((TESFileAccessor*)apFile)))->IsEndianConversionRequired())
        {
            ::FUN_00401080((int *)(unsigned int *)(reinterpret_cast<unsigned int*>(&this->m_fStoredValue)));
        }
        apChunkBuffer += 4;
    }
}

// FUN_0069bcf0 - default constructor of a non-polymorphic class.
// Disassembly facts:
//   - , no stack args, returns this (mov eax,[ebp-0x10] epilogue)
//   - no vtable store -> non-polymorphic
//   - ctor-call on this+0x00 and this+0x0C with 3 float args each
//     (globals D_01015f5c x3 then D_01016970 x3)
//   - ctor-call on this+0x18 (0x69cd10), no args
//   - EH scope state 0 set right after, covering only the call on
//     this+0x28 (0x49f1c0) -> member at +0x18 has a non-trivial dtor
//     (unwind funclet destroys it), member at +0x28 ctor is last.


struct FUN_00416870
{
    float unk00;
    float unk04;
    float unk08;
    FUN_00416870(float, float, float);
};

struct FUN_0069cd10
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    FUN_0069cd10();
    ~FUN_0069cd10();
};

struct FUN_0049f1c0
{
    void* unk00;
    FUN_0049f1c0();
};

class FUN_0069bcf0
{
  public:
    FUN_00416870 unk00;
    FUN_00416870 unk0C;
    FUN_0069cd10 unk18;
    FUN_0049f1c0 unk28;

    FUN_0069bcf0();
};

// @fnv 0x0069bcf0
FUN_0069bcf0::FUN_0069bcf0() : unk00(::DAT_01015f5c, ::DAT_01015f5c, ::DAT_01015f5c), unk0C(::DAT_01016970, ::DAT_01016970, ::DAT_01016970)
{}

struct MeshParent
{
};
struct MeshCell
{
};
struct MeshPoint
{
    float x, y, z;
};
struct MeshTriangle
{
};
struct NavInfo;
struct NavInfoPointer
{
    NavInfo* pointer;
};
struct MeshLink
{
    int unk00;
    NavInfoPointer info;
};
struct MeshSource
{
};
struct NavMeshReference
{
    int unk00;
    NavMeshReference();
    ~NavMeshReference();
};
struct MeshArray
{
    int unk00;
    NavInfo** buffer;
    unsigned int size, capacity;
    NavInfo*& FUN_00877a30(unsigned int);
};
struct NavInfo
{
    unsigned int id, parentId, flags;
    int cellKey;
    MeshPoint point;
    MeshParent* parent;
    float preferred;
    MeshArray adjacent, preferredAdjacent, doors;
    void* mesh;
    NavMeshBounds* bounds;
    void InitializeFromMeshSource(MeshSource*);
};
// Resets this NavInfo and rebuilds its id, parent, adjacency, doors, cell key, point and preferred ratio from the given mesh source.
// @fnv 0x006b5560
void NavInfo::InitializeFromMeshSource(MeshSource* source)
{
    id = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((source))->FUN_0084e3a0()));
    parent = ((::MeshParent *)(reinterpret_cast<::NavMeshProxy *>((source))->GetDoorForm()));
    parentId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::MeshParent *)(reinterpret_cast<::NavMeshProxy *>((source))->GetDoorForm()))))->FUN_0084e3a0()));
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(adjacent))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(preferredAdjacent))->Clear(true);
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>(&(doors))->Clear(true);
    flags = 0;
    if (bounds)
    {
        delete bounds;
        bounds = 0;
    }
    if (reinterpret_cast<::TESForm *>((source))->GetDisabled())
        reinterpret_cast<::TESForm *>(this)->SetCollisionDisabled(true);
    {
        unsigned int count = ::FUN_00558200((char *)(source));
        for (unsigned int i = 0; i < count; ++i)
        {
            MeshTriangle* triangle = ((::MeshTriangle *)(reinterpret_cast<::NavMesh *>((source))->GetTriangle((unsigned short)i)));
            if (!reinterpret_cast<::FUN_00690e10_shell *>((triangle))->FUN_00690e10())
                continue;
            bool isPreferred = reinterpret_cast<::FUN_00693b70_shell *>((triangle))->HasFlag40();
            for (int edge = 0; edge < 3; ++edge)
            {
                if (!reinterpret_cast<::FUN_0068f1d0_shell *>((triangle))->IsEdgeFlagSet(edge))
                    continue;
                MeshLink* link = ((::MeshLink *)(reinterpret_cast<::FUN_00693d30_shell *>((source))->GetEdge(reinterpret_cast<::FUN_0068f2c0_shell *>((triangle))->FUN_0068f2c0(edge))));
                if (reinterpret_cast<::FUN_0069e090_class *>(&(link->info))->FUN_0069e090())
                {
                    bool add3 = true;
                    NavMeshReference reference;
                    if (reinterpret_cast<::NavMeshInfo *>((link->info.pointer))->AcquireNavMesh((::NavMeshPtr &)(reference)))
                    {
                        if (reinterpret_cast<::FUN_00440d80_shell *>((((::MeshSource *)(::FUN_00559450((int *)&(reference))))))->FUN_00440d80())
                            add3 = false;
                        else if (isPreferred)
                        {
                            unsigned int size = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(adjacent))->GetName()));
                            for (unsigned int j = 0; j < size; ++j)
                                if (adjacent.FUN_00877a30(j) == link->info.pointer)
                                {
                                    reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(&(adjacent))->FUN_009a4320(j, true);
                                    break;
                                }
                            size = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(preferredAdjacent))->GetName()));
                            for (unsigned int k = 0; k < size; ++k)
                                if (preferredAdjacent.FUN_00877a30(k) == link->info.pointer)
                                {
                                    add3 = false;
                                    break;
                                }
                        }
                        else
                        {
                            unsigned int sizeOther = ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(adjacent))->GetName()));
                            for (unsigned int m = 0; m < sizeOther; ++m)
                                if (adjacent.FUN_00877a30(m) == link->info.pointer)
                                {
                                    add3 = false;
                                    break;
                                }
                        }
                    }
                    else
                        add3 = false;
                    if (add3)
                    {
                        if (isPreferred)
                            reinterpret_cast<::FUN_00438690 *>(&(preferredAdjacent))->FUN_007cb2e0((unsigned int *)&(link->info.pointer));
                        else
                            reinterpret_cast<::FUN_00438690 *>(&(adjacent))->FUN_007cb2e0((unsigned int *)&(link->info.pointer));
                    }
                }
            }
        }
        if (count == 0)
            flags |= 8;
        else
            flags &= ~8;
        count = reinterpret_cast<::fnv_006b5a90::FUN_006b5a90_shell *>((source))->FUN_006b5a90();
        for (unsigned int d = 0; d < count; ++d)
            reinterpret_cast<::FUN_00438690 *>(&(doors))->FUN_007cb2e0((unsigned int *)&((*(::NavInfo *const *)(reinterpret_cast<::FUN_0068f6b0_shell *>((source))->FUN_0068f6b0((unsigned short)d)))));
    }
    if (((int)(reinterpret_cast<::TESObjectCELL *>((((::MeshCell *)(reinterpret_cast<::ActorMover *>((source))->GetCurrentMoveModeType()))))->GetParentWorldSpace())))
        cellKey = ::PackShortPair(reinterpret_cast<::TESObjectCELL *>((((::MeshCell *)(reinterpret_cast<::ActorMover *>((source))->GetCurrentMoveModeType()))))->GetCellGridX(), reinterpret_cast<::TESObjectCELL *>((((::MeshCell *)(reinterpret_cast<::ActorMover *>((source))->GetCurrentMoveModeType()))))->GetCellGridY());
    else
        cellKey = 0;
    point = (*reinterpret_cast<::MeshPoint *>((void *)&::NiPoint3::ZERO));
    unsigned int vertices = reinterpret_cast<::fnv_00990a60::FUN_00990a60_shell *>((source))->GetArrFlags();
    if (vertices > 0)
    {
        for (unsigned int v = 0; v < vertices; ++v)
            reinterpret_cast<::FUN_0063c8a0_shell *>(&(point))->FUN_0063c8a0((void *)&((*(const ::MeshPoint *)(reinterpret_cast<::FUN_0068f0a0_shell *>((source))->FUN_0068f0a0((unsigned short)v)))));
        reinterpret_cast<::FUN_004941c0_shell *>(&(point))->ScaleByInverse((float)vertices);
    }
    unsigned int triangles = ::FUN_00558200((char *)(source));
    if (triangles)
    {
        unsigned int preferredCount = 0;
        for (unsigned int t = 0; t < triangles; ++t)
        {
            MeshTriangle* triangle2 = ((::MeshTriangle *)(reinterpret_cast<::NavMesh *>((source))->GetTriangle((unsigned short)t)));
            if (reinterpret_cast<::FUN_00693b70_shell *>((triangle2))->HasFlag40())
                ++preferredCount;
        }
        reinterpret_cast<::FUN_00693d50_shell *>(this)->FUN_00693d50((float)preferredCount / (float)triangles);
    }
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(true);
}
