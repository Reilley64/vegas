// fallout_shared/region system/tesregiondatamap.cpp: TESRegionDataMap, RegionMapMerge (11 functions)

#include <cmath>
#include "fnv/decl/B408A80String.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BSStringTChar.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f15c0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/RegionSource.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "layout_support.h"
#include "TESFile.h"
#include <malloc.h>

class TESRegionData
{
  public:
    bool bOverride;
    bool m_bHasRegionData;
    unsigned char m_ucRegionPriority;
    unsigned char layoutPadding7[1];
};

class TESRegionDataMap : public TESRegionData
{
  public:
    BSStringT<char> m_kMapName;

    virtual ~TESRegionDataMap();
    virtual bool LoadRegionMapData(TESFile* apFile);
    virtual const char* GetRegionMapName();
};

// Reads the RDMP chunk from apFile into a buffer and stores it in the map string, returning true on success.
// @fnv 0x004f3e90
bool TESRegionDataMap::LoadRegionMapData(TESFile* apFile)
{
    if (!apFile || ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())) != CHUNK_ID_RDMP_ID)
        return false;

    char* pChunkData = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
    reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pChunkData), 0);
    reinterpret_cast<::TextString *>(&(m_kMapName))->FUN_004037f0(pChunkData, 0);
    return true;
}

// @fnv 0x005585e0
const char* TESRegionDataMap::GetRegionMapName()
{
    return ((const char *)(::FUN_00559450((int *)&(m_kMapName))));
}

extern unsigned int _data_011c16bc;
struct B004f1400
{
    virtual ~B004f1400();
    char p[4];
    B004f1400();
};
struct StrMem
{
    char p[8];
    StrMem();
    ~StrMem();
};
struct FUN_004f3ca0 : public B004f1400
{
    StrMem m_kMapName;
    FUN_004f3ca0();
    virtual ~FUN_004f3ca0();
};
// Constructs the object and sets its string member to "Default Region Name".
// @fnv 0x004f3ca0
FUN_004f3ca0::FUN_004f3ca0()
{
    reinterpret_cast<::TextString *>(&(m_kMapName))->FUN_004037f0("Default Region Name", 0);
}

struct Proxy_004f3de0
{
    void FUN_004f3de0();
};
struct Proxy_004f3d20
{
    void* FUN_004f3d20(unsigned int);
};
struct S7010
{
public:
    unsigned int GetLengthPlusOne();
};
struct Flt
{
    operator std::uintptr_t();
};
struct H14c0
{
};
struct H4280
{
};
struct FUN_004f3e40Shell
{
    char _pad[8];
    union U
    {
        S7010 s;
        Flt f;
        H4280 h;
    } u;
    void FUN_004f3e40();
};
// @fnv 0x004f3e40
void FUN_004f3e40Shell::FUN_004f3e40()
{
    reinterpret_cast<::RegionSource *>((((H14c0*)this)))->WriteSaveData();
    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(u.s))->FUN_004048e0())))
        ::FUN_004856f0((void *)(0x504D4452), (void*)(std::uintptr_t)u.f, (void *)(std::uintptr_t)(reinterpret_cast<::S7010 *>(&(u.h))->GetLengthPlusOne()));
}

namespace fnv_004f3f10 {
struct BSStr
{
};
struct Flt
{
    operator std::uintptr_t();
};
struct S004f3f10
{
    char _p[8];
    Flt _f;
    void FUN_004f3f10(BSStr&);
};
// Calls Set on the BSStr with the float value converted to unsigned int as the string pointer and length 0.
// @fnv 0x004f3f10
void S004f3f10::FUN_004f3f10(BSStr& a)
{
    reinterpret_cast<::TextString *>(&(a))->FUN_004037f0((const char*)(std::uintptr_t)_f, 0);
}
}  // namespace fnv_004f3f10

struct BSStr
{
    char _d[8];
};
struct FUN_004f3f40_shell
{
    char _pad[8];
    BSStr str;
    bool FUN_004f3f40(char const*);
};
// @fnv 0x004f3f40
bool FUN_004f3f40_shell::FUN_004f3f40(char const* apMapName)
{
    if (reinterpret_cast<::B408A80String *>((void *)&(str))->FUN_00408a80(apMapName, true))
    {
        reinterpret_cast<::TextString *>(&(str))->FUN_004037f0(apMapName, 0);
        return true;
    }
    return false;
}

struct FUN_004f14a0_shell
{
};
struct FUN_004f3de0 : public FUN_004f3ca0
{
    ~FUN_004f3de0();
};
// Calls FUN_004f3de0 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x004f3d20
void* Proxy_004f3d20::FUN_004f3d20(unsigned int flags)
{
    reinterpret_cast<::FUN_004f3de0 *>((((Proxy_004f3de0*)this)))->FUN_004f3de0::~FUN_004f3de0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that calls FUN_004f14a0 on the subobject at offset 8 of this object.
// @fnv 0x004f3de0
FUN_004f3de0::~FUN_004f3de0()
{
    reinterpret_cast<::BSStringTChar *>((((FUN_004f14a0_shell*)&this->m_kMapName.p[0])))->BSStringTChar::~BSStringTChar();
}


struct FUN_004f3d50 : public TESRegionData
{
    char padding[12];
    FUN_004f3d50(const TESRegionDataMap* source);
};

struct FUN_004f3f80_shell : public TESRegionDataMap
{
    TESRegionData* CreateRegionData() const;
};

// Allocates a new TESRegionData-derived object from this TESRegionDataMap and returns it.
// @fnv 0x004f3f80
TESRegionData* FUN_004f3f80_shell::CreateRegionData() const
{
    TESRegionData* pdata = new FUN_004f3d50(this);
    return pdata;
}

namespace fnv_004f3d50 {
class ThisBase_b5917
{
  public:
    virtual ~ThisBase_b5917();
    unsigned int m_04;
    ThisBase_b5917(class ThisSource_b5917* aValue);
};

class ThisMember_b5917
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    ThisMember_b5917();
    ~ThisMember_b5917();
};

class ThisSource_b5917
{
  public:
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
    virtual void v0a();
    virtual const char* GetName();
};

class FUN_004f3d50 : public ThisBase_b5917
{
  public:
    virtual ~FUN_004f3d50();
    ThisMember_b5917 m_08;

    FUN_004f3d50(ThisSource_b5917* src);
};

// Constructs the object from a source, initializing the base with it and calling Set with the source's name.
// @fnv 0x004f3d50
FUN_004f3d50::FUN_004f3d50(ThisSource_b5917* apSource) : ThisBase_b5917(apSource)
{
    reinterpret_cast<::FUN_004f3f40_shell *>(this)->FUN_004f3f40(apSource->GetName());
}
}  // namespace fnv_004f3d50

struct RegionMapMerge : TESRegionDataMap
{
    virtual void SaveRegionData();
    virtual unsigned int GetRegionDataType();
    virtual void CopyRegionData();
    virtual void CompareRegionData();
    virtual void ClearRegionData();
    virtual void InitializeRegionData();
    virtual void ValidateRegionData();
    virtual void UpdateRegionData();
    virtual const char* ReadMapName();
    virtual void SetRegionMapName(const char* name);
    void MergeMapData(RegionMapMerge* data, void* context);
};

// @fnv 0x004f4000
void RegionMapMerge::MergeMapData(RegionMapMerge* apOther, void* context)
{
    RegionMapMerge* other = apOther;
    if (!apOther || apOther->GetRegionDataType() != 4 || !context)
        return;
    if (m_bHasRegionData)
    {
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling());
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())));
        SetRegionMapName(other->ReadMapName());
    }
    else if (other->m_bHasRegionData)
    {
        return;
    }
    else if (bOverride)
    {
        if (reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling() && ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())) > ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())))
        {
            reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling());
            reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())));
            SetRegionMapName(other->ReadMapName());
        }
        return;
    }
    else if (reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling())
    {
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling());
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())));
        SetRegionMapName(other->ReadMapName());
    }
    else
    {
        if (((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())) > ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())))
            SetRegionMapName(other->ReadMapName());
        float priority = ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) + (100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0()));
        priority += (100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) + ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0()));
        priority *= 0.005f;
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0((unsigned char)floor(priority));
    }
}
