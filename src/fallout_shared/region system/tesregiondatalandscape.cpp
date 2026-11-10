// fallout_shared/region system/tesregiondatalandscape.cpp: TESRegionDataLandscape, ThisT (15 functions)

#include <new>
#include "NiFixedString.h"
#include <cmath>
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048e2e0.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f15c0_shell.h"
#include "fnv/decl/FUN_004f32e0_class.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/NiGlobalStringTable.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/RegionSource.h"
#include "fnv/decl/S_0064dac0.h"
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00476000.h"
#include "fnv/symbols_004f3000.h"
#include "fnv/symbols_01023000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011c7000.h"
#include "tesregiondatalandscape_decls.h"
// @fnv 0x004f2a20
bool TESRegionDataLandscape::ReadLandscapeData(TESFile* file)
{
    if (!file)
        return false;
    unsigned int chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()));
    switch (chunk)
    {
    case 0x4e4f4349:
        TESTexture::ReadTextureData(m_pLandscapeTexture, file);
        break;
    }
    return true;
}

// @fnv 0x004f2790
TESRegionDataLandscape::TESRegionDataLandscape()
{
    m_pLandscapeTexture = new TESTexture;
    reinterpret_cast<::TESFullName *>((m_pLandscapeTexture))->SetFullName("Trees\\CanopyShadow.dds");
}

// Writes 6, 3 and 2 into the first three int slots of pThis and returns pThis.
// @fnv 0x004f31d0
int* InitIntArray(int* pIntArray)
{
    pIntArray[0] = 6;
    pIntArray[1] = 3;
    pIntArray[2] = 2;
    return pIntArray;
}

struct FUN_004f32b0_This
{
};

struct FUN_004f32b0_Arg
{
    unsigned short val;
};

// Calls SetMaskedBits with the argument's val, 0x3000 and 0xc.
// @fnv 0x004f32b0
void FUN_004f32b0(FUN_004f32b0_This* this_ptr, FUN_004f32b0_Arg aValue)
{
    reinterpret_cast<::FUN_004f32e0_class *>((this_ptr))->SetMaskedBits(aValue.val, 0x3000, 0xc);
}


struct FUN_004f2840_shell
{
    void* FUN_004f2840(unsigned int flags);
};

struct FUN_004f29c0_This : TESTexture
{
    void* FUN_004f29c0(unsigned int flags);
};

// Destroys the TESTexture base and, when flags has bit 0 set, frees the object, returning this.
// @fnv 0x004f29c0
void* FUN_004f29c0_This::FUN_004f29c0(unsigned int flags)
{
    reinterpret_cast<::FUN_0048e2e0 *>(this)->FUN_0048e2e0::~FUN_0048e2e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct TESModel
{
    unsigned int GetModelLength() const;
};

struct FUN_004f2eb0_shell
{
    int _0;
    int _4;
    TESModel* m_pLandscapeTexture;
    bool HasModel();
};

// Returns true if the TESModel pointer is set and its model length is non-zero, otherwise false.
// @fnv 0x004f2eb0
bool FUN_004f2eb0_shell::HasModel()
{
    if (!this->m_pLandscapeTexture || !this->m_pLandscapeTexture->GetModelLength())
        return false;
    return true;
}

struct BSStr
{
};

struct FNStub
{
};

extern const char $SG5889[];

struct FUN_004f2a70_shell
{
    void* _0;
    void* _4;
    FNStub* _8;
    void SetFullName(BSStr& aDest);
};

// @fnv 0x004f2a70
void FUN_004f2a70_shell::SetFullName(BSStr& aDest)
{
    if (!_8)
        reinterpret_cast<::TextString *>(&(aDest))->FUN_004037f0($SG5889, 0);
    else
        reinterpret_cast<::TextString *>(&(aDest))->FUN_004037f0(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(_8))->FUN_00408da0())), 0);
}

struct FUN_0048e370_obj
{
};
struct FUN_004f29f0_shell
{
    char _0[8];
    FUN_0048e370_obj* _8;
    void FUN_004f29f0();
};
// @fnv 0x004f29f0
void FUN_004f29f0_shell::FUN_004f29f0()
{
    reinterpret_cast<::RegionSource *>((this))->WriteSaveData();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((_8))->FUN_0048e370(0x4E4F4349);
}

struct Flt
{
    operator std::uintptr_t() const;
};
struct FUN_004f2ab0_shell : public FUN_004f2eb0_shell
{
    bool FUN_004f2ab0(const Flt& aName);
};
// @fnv 0x004f2ab0
bool FUN_004f2ab0_shell::FUN_004f2ab0(const Flt& aName)
{
    if (m_pLandscapeTexture)
    {
        if (!m_pLandscapeTexture->GetModelLength() ||
            ::FUN_00404dc0(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(((FNStub*)m_pLandscapeTexture)))->FUN_00408da0())), (const char*)aName.operator std::uintptr_t()) != 0)
        {
            reinterpret_cast<::TESFullName *>((((TESTexture*)m_pLandscapeTexture)))->SetFullName((const char*)aName.operator std::uintptr_t());
            return true;
        }
    }
    return false;
}

struct NiPixelFormat;
struct NiPixelData
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
    NiPixelData(unsigned int, unsigned int, const NiPixelFormat&, unsigned int, unsigned int);
};
struct TextureFormatPreferences
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
};
struct NiTexturingProperty
{
    void SetBaseMapClampMode(int);
};
struct FUN_00a6abb0
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
    FUN_00a6abb0(NiPixelData*, const NiFixedString&, TextureFormatPreferences&);
};
struct GO
{
    operator NiTexturingProperty*() const;
    void operator=(void*);
};
// Creates a 64x64 random RGBA NiPixelData, wraps it in a texturing property named DefaultFullMaskTextureProp, caches it in g_011c7f0c and returns it.
// @fnv 0x004f2ee0
NiTexturingProperty* GetDefaultFullMaskTextureProperty()
{
    NiPixelData* ppixeldata;
    unsigned char* ppixels;
    unsigned int iy;
    TextureFormatPreferences myPrefs;
    unsigned int ix;
    if ((*reinterpret_cast<::GO *>(&::g_011c7f0c)))
        return (*reinterpret_cast<::GO *>(&::g_011c7f0c));
    ppixeldata = new NiPixelData(64, 64, (*reinterpret_cast<const ::NiPixelFormat *>(&::gNiPoint3StartupSrc)), 1, 1);
    ppixels = ((unsigned char *)(reinterpret_cast<::S_0064dac0 *>((ppixeldata))->FUN_0064dac0(0, 0)));
    for (iy = 0; iy < 64; iy++)
    {
        for (ix = 0; ix < 64; ix++)
        {
            ppixels[(iy * 64 + ix) * 4 + 0] = (unsigned char)RandomFloat(0, 255.0f);
            ppixels[(iy * 64 + ix) * 4 + 1] = (unsigned char)RandomFloat(0, 255.0f);
            ppixels[(iy * 64 + ix) * 4 + 2] = (unsigned char)RandomFloat(0, 255.0f);
            ppixels[(iy * 64 + ix) * 4 + 3] = (unsigned char)RandomFloat(0, 255.0f);
        }
    }
    reinterpret_cast<::NiGlobalStringTable *>((ppixeldata))->AddString();
    InitIntArray((int*)&myPrefs);
    (*reinterpret_cast<::GO *>(&::g_011c7f0c)) = new FUN_00a6abb0(ppixeldata, NiFixedString("DefaultFullMaskTextureProp"), myPrefs);
    ((NiTexturingProperty*)(*reinterpret_cast<::GO *>(&::g_011c7f0c)))->SetBaseMapClampMode(0);
    return (*reinterpret_cast<::GO *>(&::g_011c7f0c));
}

struct FUN_004f2870
{
    char _0[12];
    FUN_004f2870(const void*);
    ~FUN_004f2870();
};
struct FUN_004f2b10_shell
{
    FUN_004f2870* FUN_004f2b10();
};
// Allocates a new FUN_004f2870 constructed from this object and returns the pointer.
// @fnv 0x004f2b10
FUN_004f2870* FUN_004f2b10_shell::FUN_004f2b10()
{
    FUN_004f2870* pdata = new FUN_004f2870(this);
    return pdata;
}

struct FUN_004f2930_tex
{
};

struct FUN_004f2930_base
{
    virtual ~FUN_004f2930_base();
    int unk04;
};

struct FUN_004f2930_cls : FUN_004f2930_base
{
    FUN_004f2930_tex* m_08;
    virtual ~FUN_004f2930_cls();
};
// Calls FUN_004f2930 on this, deletes this when flags has bit 0 set, and returns this.
// @fnv 0x004f2840
void* FUN_004f2840_shell::FUN_004f2840(unsigned int flags)
{
    reinterpret_cast<::FUN_004f2930_cls *>((this))->FUN_004f2930_cls::~FUN_004f2930_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004f2930
FUN_004f2930_cls::~FUN_004f2930_cls()
{
    FUN_004f2930_tex* copy;
    FUN_004f2930_tex* tmp;
    if (m_08 != 0)
    {
        copy = m_08;
        tmp = copy;
        tmp != 0 ? reinterpret_cast<::FUN_004f29c0_This *>((tmp))->FUN_004f29c0(1) : 0;
    }
}

template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
};

struct ThisT
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual int Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10(BSStringT<char>* s);
    virtual void Slot11(BSStringT<char>* s);
    unsigned char m_04;
    unsigned char m_05;
    unsigned char m_06;
    void UpdateFromSource(ThisT* a1, int a2);
};

// @fnv 0x004f2b90
void ThisT::UpdateFromSource(ThisT* a1, int a2)
{
    ThisT* a1p = a1;
    BSStringT<char> str3;
    float f;
    if (!a1 || a1->Slot04() != 5 || !a2)
        return;
    if (m_05)
    {
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((a1p))->IsPatrolling())));
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a1p))->FUN_005bb4d0())));
        a1p->Slot10(&str3);
        Slot11(&str3);
    }
    else
    {
        if (a1p->m_05)
        {
            return;
        }
        else
        {
            if (m_04)
            {
                if (((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((a1p))->IsPatrolling())))
                {
                    if (((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a1p))->FUN_005bb4d0())) > ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())))
                    {
                        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((a1p))->IsPatrolling())));
                        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a1p))->FUN_005bb4d0())));
                        a1p->Slot10(&str3);
                        Slot11(&str3);
                    }
                }
                return;
            }
            else
            {
                if (((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((a1p))->IsPatrolling())))
                {
                    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((a1p))->IsPatrolling())));
                    reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a1p))->FUN_005bb4d0())));
                    a1p->Slot10(&str3);
                    Slot11(&str3);
                }
                else
                {
                    if (((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a1p))->FUN_005bb4d0())) > ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())))
                    {
                        a1p->Slot10(&str3);
                        Slot11(&str3);
                    }
                    f = (float)(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) + (100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a1p))->FUN_005bb4d0())));
                    f += (float)((100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a1p))->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) +
                                 ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a1p))->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((a1p))->FUN_005bb4d0())));
                    f *= DAT_01023b88;
                    reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0((unsigned char)floor(f));
                }
            }
        }
    }
}

// TESRegionDataLandscape copy constructor: copy the base region data and clone the texture.


class F2870Texture
{
  public:
    F2870Texture();
    virtual ~F2870Texture();

    char* m_pcPath;
    unsigned short m_usLen;
    unsigned short m_usMax;
};

class F2870RegionData
{
  public:
    F2870RegionData(const F2870RegionData& kOther);
    virtual ~F2870RegionData();
    int unk04;
};

class FUN_004f2870_Landscape : public F2870RegionData
{
  public:
    FUN_004f2870_Landscape(const FUN_004f2870_Landscape& kOther);
    virtual ~FUN_004f2870_Landscape();

    F2870Texture* m_pkTexture;
};

// Copy-constructs a landscape region, allocating a new texture and copying the source texture's path into it.
// @fnv 0x004f2870
FUN_004f2870_Landscape::FUN_004f2870_Landscape(const FUN_004f2870_Landscape& kOther) : F2870RegionData(kOther)
{
    m_pkTexture = new F2870Texture;
    reinterpret_cast<::TESFullName *>((m_pkTexture))->SetFullName(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(kOther.m_pkTexture))->FUN_00408da0())));
}

#include "generated/data/fallout_shared/region system/tesregiondatalandscape.inc"
