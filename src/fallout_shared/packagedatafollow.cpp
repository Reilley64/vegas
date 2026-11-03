
// src/fallout_shared/packagedatafollow.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/packagedatafollow.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include <new>
#include "fnv/decl/FUN_0067ad20_Class.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_0067f600__FUN_0067f600_shell.h"
#include "fnv/decl/fnv_0067f6c0__FUN_0067f6c0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00485000.h"
struct FUN_0067c080_shell
{
    void __thiscall FUN_0067c080();
};

void __cdecl FUN_0067c080_stub();

struct FUN_0067c010_shell
{
    void __thiscall FUN_0067c080();
    void* __thiscall DestroyIfFlagged(unsigned int flags);
};

extern int DAT_01068988;
struct FUN_0067c040_shell
{
    void* vtbl;
    int m1;
    float m2;
    FUN_0067c040_shell* Construct(float a);
};
// Calls FUN_0067ad20, sets vtbl to &DAT_01068988, stores a in m2, zeroes m1, and returns this.
// @fnv 0x0067c040
FUN_0067c040_shell* FUN_0067c040_shell::Construct(float afValue)
{
    new ((void *)this) ::FUN_0067ad20_Class();
    vtbl = &DAT_01068988;
    m2 = afValue;
    m1 = 0;
    return this;
}

extern "C" void* __cdecl memset(void*, int, unsigned int);
struct BipedModelForm
{
};
struct LocationDescriptor
{
public:
    void Copy(::LocationDescriptor *, bool);
};
struct FUN_0067c2b0_shell
{
    void* pBase;
    void* m_pSaveTarget;
    float m_fSavedValue;
    void SaveFloatRecord();
};
// @fnv 0x0067c2b0
void FUN_0067c2b0_shell::SaveFloatRecord()
{
    float fValue;
    memset(&fValue, 0, 4);
    fValue = m_fSavedValue;
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>((((BipedModelForm*)&fValue)))->FUN_00503210();
    ::AppendChunk(0x44464b50, &fValue, 4);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>((((BipedModelForm*)&fValue)))->FUN_00503210();
    if (m_pSaveTarget)
        reinterpret_cast<::fnv_0067f6c0::FUN_0067f6c0_shell *>((((LocationDescriptor*)m_pSaveTarget)))->FUN_0067f6c0(0x32444c50);
}

struct FUN_00670b30_Object
{
    ~FUN_00670b30_Object();
};
struct FUN_0067ad70_Base
{
    virtual void v0();
    ~FUN_0067ad70_Base();
};
struct FUN_0067c080 : FUN_0067ad70_Base
{
    FUN_00670b30_Object* ownedObject;
    ~FUN_0067c080();
};
// @fnv 0x0067c010
void* __thiscall FUN_0067c010_shell::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0067c080 *>(this)->FUN_0067c080::~FUN_0067c080();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Destructor that deletes the ownedObject pointer.
// @fnv 0x0067c080
FUN_0067c080::~FUN_0067c080()
{
    delete ownedObject;
}

class TESPackageData
{
  public:
    virtual void unk00()
    {}
};
class FollowPackageField
{
  public:
    int unk00;
};
class TESFollowPackageData : public TESPackageData
{
  public:
    FollowPackageField* m_04;
    float m_08;
    bool FUN_0067c220(TESPackageData* arg);
};
// @fnv 0x0067c220
bool TESFollowPackageData::FUN_0067c220(TESPackageData* apData)
{
    TESFollowPackageData* other = dynamic_cast<TESFollowPackageData*>(apData);
    if (other == 0)
    {
        return true;
    }
    if (m_08 != other->m_08)
    {
        return true;
    }
    if (m_04 != 0)
    {
        if (reinterpret_cast<::fnv_0067f600::FUN_0067f600_shell *>((m_04))->IsDifferentFrom((::LocationDescriptor *)(other->m_04)))
        {
            return true;
        }
    }
    else
    {
        if (other->m_04 != 0)
        {
            return true;
        }
    }
    return false;
}

struct FUN_0067c110_shell : TESPackageData
{
    FollowPackageField* m_04;
    float m_08;
    void __thiscall FUN_0067c110(TESPackageData* other);
};

struct FUN_0067f030
{
    void* vtbl;
    int unk04;
    int unk08;
    FUN_0067f030();
};

// For a compatible source, copies m_08, deletes the old m_04, and allocates and initializes m_04 when the source has one.
// @fnv 0x0067c110
void __thiscall FUN_0067c110_shell::FUN_0067c110(TESPackageData* other)
{
    TESFollowPackageData* source = dynamic_cast<TESFollowPackageData*>(other);
    if (source)
    {
        m_08 = source->m_08;
        if (m_04)
        {
            delete reinterpret_cast<FUN_00670b30_Object*>(m_04);
            m_04 = 0;
        }
        if (source->m_04)
        {
            m_04 = reinterpret_cast<FollowPackageField*>(new FUN_0067f030);
            reinterpret_cast<::LocationDescriptor *>((reinterpret_cast<FUN_0067f030*>(m_04)))->Copy((::LocationDescriptor *)(source->m_04), false);
        }
    }
}
