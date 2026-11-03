// fallout_shared/tesdescription.cpp: TESDescription, TESDataHandler, TermHack (14 functions)

#include "fnv/decl/B408A80String.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_00482f40_t.h"
#include "fnv/decl/FUN_004ffba0.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/PlayerCharShell.h"
#include "fnv/decl/TextString.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c5000.h"
#include "fnv/symbols_011c8000.h"
#include "fnv/symbols_011de000.h"
#include "tesdescription_decls.h"
// @fnv 0x00482f20
bool TESDataHandler::LoadDescriptionForForm()
{
    return loadDescription;
}
// If both description and file are non-null, calls Initialize on the description with the file's offset as a CombatController.
// @fnv 0x00482d50
void TESDescription::ReadDescriptionFromFile(TESDescription* description, TESFile* file)
{
    if (description && file)
        reinterpret_cast<CombatProcedure*>(description)
            ->Initialize(reinterpret_cast<CombatController*>(file->GetOffset()));
}
// @fnv 0x00482e90
const char* TESDescription::GetDescription(TESForm* form, CHUNK_ID chunk)
{
    if (!(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->LoadDescriptionForForm())
    {
        TESForm* owner = form;
        if (!owner)
            owner = dynamic_cast<TESForm*>(this);
        reinterpret_cast<::FUN_00482f40_t *>((reinterpret_cast<TESFile*>(this)))->FUN_00482f40(owner, (*(unsigned int *)&(chunk)));
    }
    return reinterpret_cast<NiPointer<NiNode>*>(&(*reinterpret_cast<::BSStringT<char> *>(&::g_011c5498)))->operator->()
               ? reinterpret_cast<const char*>(reinterpret_cast<NiPointer<NiNode>*>(&(*reinterpret_cast<::BSStringT<char> *>(&::g_011c5498)))->operator->())
               : ::DAT_01011584;
}

extern "C" unsigned char DAT_011c54ba;

// @fnv 0x00401500
unsigned char FUN_00401500()
{
    return DAT_011c54ba;
}

struct TESObjectREFR;
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
struct TESIcon : public TESTexture
{
    virtual char* GetTextureResourcePath();
    void* __vecDelDtor(unsigned int);
};
struct FUN_00482c80_shell : public TESDescription
{
    void ClearParsedXML();
};
// @fnv 0x00482c50
TESDescription::TESDescription()
{
    InitializeComponent();
}

extern "C" unsigned char DAT_011c54ba;
unsigned char FUN_00401500();

struct BSStr
{
};

extern int DAT_011c5490;

// Resets the parsed XML string, clears DAT_011c5490, and zeroes the second dword of this object.
// @fnv 0x00482c80
void FUN_00482c80_shell::ClearParsedXML()
{
    reinterpret_cast<::TextString *>((((BSStr*)&(*reinterpret_cast<::BSStringT<char> *>(&::g_011c5498)))))->FUN_004037f0(0, 0);
    DAT_011c5490 = 0;
    this->m_uiDescriptionFileOffset = 0;
}

void __cdecl WriteDescChunk(void*, int);

struct FUN_00482cb0_shell
{
    void FUN_00482cb0();
};

// @fnv 0x00482cb0
void FUN_00482cb0_shell::FUN_00482cb0()
{
    WriteDescChunk(this, 0x43534544);
}

struct DescStandIn
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* vf4(int, int);
};
struct S7010
{
};
struct FUN_00482d30_shell
{
    unsigned int GetMenuParsedXmlLength();
};
// @fnv 0x00482cd0
void __cdecl WriteDescChunk(void* apDesc, int aiChunk)
{
    char empty;
    if (apDesc)
    {
        if (((int)(reinterpret_cast<::FUN_00482d30_shell *>((((DescStandIn*)apDesc)))->GetMenuParsedXmlLength())))
        {
            ::FUN_004856f0((void *)(aiChunk), ((DescStandIn*)apDesc)->vf4(0, 0x43534544),
                         (void *)(((int)(reinterpret_cast<::FUN_00482d30_shell *>((((DescStandIn*)apDesc)))->GetMenuParsedXmlLength())) + 1));
        }
        else
        {
            empty = 0;
            ::FUN_004856f0((void *)(aiChunk), &empty, (void *)(1));
        }
    }
}
// @fnv 0x00482d30
unsigned int FUN_00482d30_shell::GetMenuParsedXmlLength()
{
    return ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((((S7010*)&(*reinterpret_cast<::BSStringT<char> *>(&::g_011c5498)))))->FUN_004048e0()));
}

struct ClassFFB70
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_004ffba0 on this, frees this with _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x004ffb70
void* ClassFFB70::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_004ffba0 *>((this))->FUN_004ffba0::~FUN_004ffba0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct Flt
{
    const char* operator*() const;
};

struct FUN_005a6e10_shell
{
    unsigned int _pad[5];
    const char* m_str;
    const char* GetStringOrDefault(int a, int b);
};

// Returns the string held by m_str if it is non-null, otherwise returns g_011c72c0_arg1.
// @fnv 0x005a6e10
const char* FUN_005a6e10_shell::GetStringOrDefault(int aiUnusedA, int aiUnusedB)
{
    (void)aiUnusedA;
    (void)aiUnusedB;
    return m_str ? m_str : ::DAT_01011584;
}

struct StrCmpHelper
{
};

struct FUN_00482df0_shell
{
    bool FUN_00482df0(BaseFormComponent* apComponent);
};

// @fnv 0x00482df0
bool FUN_00482df0_shell::FUN_00482df0(BaseFormComponent* apComponent)
{
    TESDescription* pDesc = dynamic_cast<TESDescription*>(apComponent);
    if (!pDesc)
        return true;
    if (((int)(reinterpret_cast<::FUN_00482d30_shell *>((((DescStandIn*)this)))->GetMenuParsedXmlLength())) || ((int)(reinterpret_cast<::FUN_00482d30_shell *>((((DescStandIn*)pDesc)))->GetMenuParsedXmlLength())))
    {
        if (((int)(reinterpret_cast<::FUN_00482d30_shell *>((((DescStandIn*)this)))->GetMenuParsedXmlLength())) != ((int)(reinterpret_cast<::FUN_00482d30_shell *>((((DescStandIn*)pDesc)))->GetMenuParsedXmlLength())))
            return true;
        else if (reinterpret_cast<::B408A80String *>((void *)(((StrCmpHelper*)&(*reinterpret_cast<::BSStringT<char> *>(&::g_011c5498)))))->FUN_00408a80((char const*)((DescStandIn*)pDesc)->vf4(0, 0x43534544), 0))
            return true;
    }
    return false;
}

struct TESObjectREFR;

struct PlayerCharacter
{
};

struct BSStringT_char
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;
    BSStringT_char();
    ~BSStringT_char();
    operator const char*() const;
};

struct SettingString
{
};

namespace ActorValue {
enum Index
{
    kAV_0 = 0
};
}


struct TermHackBase0
{
    virtual void vf00();
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
};

struct TermHackBase70
{
    virtual void FUN_005015f0(TESObjectREFR* apRef, PlayerCharacter* apActor);
};

struct TermHack : TermHackBase0, TermHackBase70
{
    float FUN_005017a0(TESObjectREFR* apRef);
    virtual void FUN_005015f0(TESObjectREFR* apRef, PlayerCharacter* apActor);
};

// @fnv 0x005015f0
void TermHack::FUN_005015f0(TESObjectREFR* apRef, PlayerCharacter* apActor)
{
    if (apRef && apActor == ::_g_thePlayer)
    {
        switch (reinterpret_cast<::PlayerCharShell *>((::_g_thePlayer))->GetTerminalAccessResult(apRef))
        {
        case 0:
        case 1:
            ::FUN_00709470(3, (int)(apRef), 0, 0, 1);
            break;
        case 2:
        case 3:
            ::FUN_00709470(2, (int)(apRef), 0, 0, 1);
            break;
        case 4: {
            BSStringT_char kMsg;
            ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT_char *)(&kMsg), ((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::SettingString *>(&::g_011c8394))))->IsDLCAvailable())), ActorValue::GetActorValueName((ActorValue::Index)0x28),
                         (int)::InventoryStackRecord::RoundToNearestStep(FUN_005017a0(apRef), 1.0f));
            ::DispatchMessageToSink((const char *)(kMsg.pString), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds"), (const char *)(0), 2.0f, false);
        }
        break;
        }
        ::FUN_0047a560(apRef, (::TESObjectREFR *)(apActor), (::BGSOpenCloseForm *)(0));
    }
}

class GlobalObject_004037b0
{
  public:
};
struct Off482d
{
};

struct Desc482d : public TESDescription
{
    void FUN_00482d80(BaseFormComponent* apComponent);
};

// @fnv 0x00482d80
void Desc482d::FUN_00482d80(BaseFormComponent* apComponent)
{
    TESDescription* pDesc = dynamic_cast<TESDescription*>(apComponent);
    if (!pDesc)
        return;
    reinterpret_cast<::TextString *>(&(g_011c5498))->FUN_004037f0((const char*)((DescStandIn*)pDesc)->vf4(0, 'CSED'), 0);
    m_uiDescriptionFileOffset = ((unsigned long)(reinterpret_cast<::Callees *>((((Off482d*)pDesc)))->FUN_00726070()));
}

// Adjustor thunk: the secondary-base (+0x3c) vtable entry for an override defined on the derived class.

class D1CC0Primary
{
  public:
    virtual void FUN_00501cc0(unsigned int uiValue);
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
};

class D1CC0Secondary
{
  public:
    virtual void FUN_00501cc0(unsigned int uiValue);
};

class D1CC0Derived : public D1CC0Primary, public D1CC0Secondary
{
  public:
    D1CC0Derived();
// @fnv 0x00501cc0
    virtual void FUN_00501cc0(unsigned int uiValue);
};

D1CC0Derived::D1CC0Derived()
{}

// [thunk] this-adjustor (-0x84) for the secondary-base vtable slot of the TESObjectBOOK
// GetSaveSize override at 0x515220. The override replaces the same virtual in both bases, so the
// compiler emits this thunk with the vtable that the out-of-line constructor below instantiates;
// the override body itself lives elsewhere.
struct BookPrimaryBase
{
    virtual void Slot0();
    virtual unsigned short FUN_00515430(unsigned int auiChangeFlags);
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
    BookPrimaryBase() throw();
};

struct BookSaveSizeBase
{
    virtual unsigned short FUN_00515430(unsigned int auiChangeFlags);
    BookSaveSizeBase() throw();
};

struct TESObjectBOOKStandIn : BookPrimaryBase, BookSaveSizeBase
{
// @fnv 0x00515430
    virtual unsigned short FUN_00515430(unsigned int auiChangeFlags);
    TESObjectBOOKStandIn() throw();
};

TESObjectBOOKStandIn::TESObjectBOOKStandIn() throw()
{}

#include "generated/data/fallout_shared/tesdescription.inc"
