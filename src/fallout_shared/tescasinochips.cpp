// fallout_shared/tescasinochips.cpp: TESCasinoChips, TESCasino, IntFieldContainer, CasinoAccess and more (24 functions)

#include <cstring>
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00501c90_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047b560__FUN_0047b560_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_00559000.h"
#include "tescasinochips_packet.h"
#include <malloc.h>
#include "fnv/symbols_00472000.h"

// Constructor: sets the form type to ENUM_FORM_ID_CHIP_ID and clears the object's data.
// @fnv 0x00503bd0
TESCasinoChips::TESCasinoChips()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_CHIP_ID)));
    ClearData();
}

// @fnv 0x00503e70
void TESCasinoChips::ClearData()
{
    reinterpret_cast<::TextString *>(&(m_kPrimaryString))->FUN_004037f0(0, 0);
}

// If the form is not already initialized, initializes the destructible object, model texture swap and pickup/putdown sounds components, then marks it initialized.
// @fnv 0x00503e90
void TESCasinoChips::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;
    BGSDestructibleObjectForm::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// Reads a TESFile record: checks form type 108, loads the record header, then dispatches chunk handlers until no more chunks, returning true.
// @fnv 0x00503ef0
bool TESCasinoChips::Load(TESFile* apFile)
{
    unsigned char type = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((apFile))->FUN_00472660()));
    if (type != 108)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(apFile));
    SetInitializationState(false);
    int chunk;
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* b = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(b), 512);
            SetEditorID_AtRuntime(b);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, apFile);
            break;
        case 0x44444f4d:
        case 0x44534f4d:
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, apFile);
            break;
        case 0x53444f4d: {
            char* swapBuffer;
            {
                unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C();
                swapBuffer = (char*)_alloca(size);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(swapBuffer), size);
                reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(swapBuffer, size, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((static_cast<TESFileFormVersion*>(apFile)))->FUN_00403570());
            }
            break;
        }
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(static_cast<TESIcon*>(this), apFile);
            break;
        case 0x4f43494d:
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this), apFile);
            break;
        case 0x44545344:
        case 0x54534544:
            ::FUN_004781e0(this, apFile);
            break;
        case 0x4d414e59: {
            unsigned int id = 0;
            apFile->GetChunkData(&id);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::TESSound *)((TESSound*)(std::uintptr_t)id));
            break;
        }
        case 0x4d414e5a: {
            unsigned int id = 0;
            apFile->GetChunkData(&id);
            reinterpret_cast<::TESRegionGrassObject *>(this)->AssignLandTexture((::TESLandTexture *)(::TESSound *)((TESSound*)(std::uintptr_t)id));
            break;
        }
        case 0x4d414e4f: {
            char* b = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(b), 0);
            reinterpret_cast<::TextString *>(&(m_kPrimaryString))->FUN_004037f0(b, 0);
            break;
        }
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

struct FUN_00504480 : public TESForm, public TESFullName
{
    TESModelTextureSwap unk24[10];
    TESTexture unk164[11];

    FUN_00504480();
    virtual ~FUN_00504480();
};

// Initializes the form by setting its form type to 0x6d.
// @fnv 0x00504480
FUN_00504480::FUN_00504480()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(0x6d))));
}

struct FUN_005046e0_shell : public TESCasino
{
    void FUN_005046e0();
};

// @fnv 0x005046e0
void FUN_005046e0_shell::FUN_005046e0()
{
    ::ResolveFormID((unsigned int *)&(this->data.IntegerEndianRecord), GetFile(-1));
}


struct TESCasinoChips_shell
{
    void* Destroy(unsigned int flags);
};

struct FUN_00504620_shell
{
    void ClearFields();
};

// Zeroes 0x38 bytes starting at offset 0x1e8 of this object via memset.
// @fnv 0x00504620
void FUN_00504620_shell::ClearFields()
{
    memset(this + 0x1e8, 0, 0x38);
}

struct FUN_00504e00_shell
{
    void* FUN_00504e00(int index);
};

// @fnv 0x00504e00
void* FUN_00504e00_shell::FUN_00504e00(int index)
{
    return (void**)((char*)this + 0x24 + index * 32);
}

struct FUN_00504e20_shell
{
    unsigned char _pad[0x164];
    unsigned char m_aiIndexedValues[0x200];
    unsigned char* FUN_00504e20(int idx);
};

// @fnv 0x00504e20
unsigned char* FUN_00504e20_shell::FUN_00504e20(int aiIndex)
{
    return &m_aiIndexedValues[aiIndex * 0xc];
}


struct FUN_00504e40_shell
{
    unsigned int m_0218;
    TESForm* FUN_00504e40();
};

// @fnv 0x00504e40
TESForm* FUN_00504e40_shell::FUN_00504e40()
{
    return ::FUN_004839c0(*(unsigned int*)((char*)this + 0x218));
}

struct FUN_00504e60_shell
{
    char* FUN_00504e60();
};

// @fnv 0x00504e60
char* FUN_00504e60_shell::FUN_00504e60()
{
    return reinterpret_cast<char*>(this) + 0x1E8;
}

struct S504540
{
    void* DestroyIfFlagged(unsigned int);
};
namespace fnv_00504cc0 {
struct ModelSrc_504cc0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual const char* GetModelFilePath();
};
struct ModelElem_504cc0
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void SetModelFilePath(const char*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
};
struct FNStub
{
};
struct FullNameEx
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
struct SoundPlaybackHandle
{
};
struct FUN_005e78f0_t
{
};
struct Data_504cc0
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
};
struct FUN_00504e00_shell
{
};
struct FUN_00504e20_shell
{
};
struct FUN_00504e40_shell
{
};
struct FUN_00504e60_shell
{
};
int FNV_GetFormType(TESForm*);

struct Casino_504cc0
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
    ModelElem_504cc0 m_kModelTextureSwaps[10];
    FullNameEx m_kIconTextures[11];
    Data_504cc0 data;
    void CopyFromCasino(TESForm* apCopy);
};

// Copies model names, full names and data from a TESCasino into this object, then sets the form type.
// @fnv 0x00504cc0
void Casino_504cc0::CopyFromCasino(TESForm* apCopy)
{
    TESCasino* pSourceCasino = dynamic_cast<TESCasino*>(apCopy);
    if (!pSourceCasino)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pSourceCasino);
    for (int i = 0; i < 10; i++)
    {
        m_kModelTextureSwaps[i].SetModelFilePath(
            ((ModelSrc_504cc0*)reinterpret_cast<::FUN_00504e00_shell *>((((FUN_00504e00_shell*)pSourceCasino)))->FUN_00504e00(i))->GetModelFilePath());
    }
    for (int i = 0; i < 11; i++)
    {
        reinterpret_cast<::TESFullName *>(&(m_kIconTextures[i]))->SetFullName(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((FNStub*)reinterpret_cast<::FUN_00504e20_shell *>((((FUN_00504e20_shell*)pSourceCasino)))->FUN_00504e20(i))))->FUN_00408da0())));
    }
    if (reinterpret_cast<::FUN_00504e40_shell *>((((FUN_00504e40_shell*)pSourceCasino)))->FUN_00504e40())
        data.unk30 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<::FUN_00504e40_shell *>((((FUN_00504e40_shell*)pSourceCasino)))->FUN_00504e40()))->FUN_0084e3a0()));
    else
        data.unk30 = 0;
    data = *(Data_504cc0*)reinterpret_cast<::FUN_00504e60_shell *>((((FUN_00504e60_shell*)pSourceCasino)))->FUN_00504e60();
    reinterpret_cast<::FUN_004f15a0_shell *>((((SoundPlaybackHandle*)this)))->FUN_004f15a0(FNV_GetFormType(pSourceCasino));
}
}  // namespace fnv_00504cc0

extern void* vftable_TESCasinoChips;

struct FUN_00503d40_shell : public TESBoundObject,
                            public TESFullName,
                            public TESModelTextureSwap,
                            public TESIcon,
                            public BGSMessageIcon,
                            public TESValueForm,
                            public BGSDestructibleObjectForm,
                            public BGSPickupPutdownSounds
{
    BSStringT<char> m_kPrimaryString;

    ~FUN_00503d40_shell();
};
// Calls FUN_00503d40, then frees this with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00503d10
void* TESCasinoChips_shell::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00503d40_shell *>(this)->FUN_00503d40_shell::~FUN_00503d40_shell();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor that calls TESCasinoChips::ClearData on this object to release its data.
// @fnv 0x00503d40
FUN_00503d40_shell::~FUN_00503d40_shell()
{
    reinterpret_cast<TESCasinoChips*>(this)->TESCasinoChips::ClearData();
}

struct FUN_004855a0
{
};

struct DoorPart30
{
};

struct DoorPart3c
{
};

struct FUN_0048e370_obj
{
};

struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};

struct DoorPart68
{
};

struct FUN_0047b560_holder
{
};

struct S7010
{
};

struct GO
{
    operator unsigned int() const;
};

struct FUN_00485680
{
};

struct FUN_00504280_shell : ::TESCasinoChips
{
    void FUN_00504280();
};


// @fnv 0x00504280
void FUN_00504280_shell::FUN_00504280()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<DoorPart30*>(static_cast<TESFullName *>(this))))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<DoorPart3c*>(static_cast<TESModelTextureSwap *>(this))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_obj*>(static_cast<TESIcon *>(this))))->FUN_0048e370(0x4e4f4349);
    reinterpret_cast<FUN_0047a240_shell*>(static_cast<BGSMessageIcon *>(this))->FUN_0047a240(0x4f43494d);
    reinterpret_cast<::FUN_00477f20_shell *>((reinterpret_cast<DoorPart68*>(static_cast<BGSDestructibleObjectForm *>(this))))->FUN_00477f20();
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>((reinterpret_cast<FUN_0047b560_holder*>(static_cast<BGSPickupPutdownSounds *>(this))))->LogFormIDs();

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(&this->m_kPrimaryString)))->FUN_004048e0())))
    {
        ::FUN_004856f0((void *)(0x4d414e4f),
                     reinterpret_cast<void*>(
                         reinterpret_cast<GO*>(&this->m_kPrimaryString)->operator unsigned int()),
                     (void *)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>((reinterpret_cast<S7010*>(&this->m_kPrimaryString)))->FUN_004048e0())) + 1));
    }

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

struct FUN_00504640_shell
{
    struct Model
    {
        virtual void Init()
        {}
        char padding[28];
    };

    struct Texture
    {
        virtual void Init()
        {}
        char padding[8];
    };

    char base[0x24];
    Model m_kModelTextureSwaps[10];
    Texture m_kIconTextures[11];
    char data[0x38];

    void FUN_00504640();
};

// Zeroes the data block, then calls Init on all 10 Model entries and all 11 Texture entries.
// @fnv 0x00504640
void FUN_00504640_shell::FUN_00504640()
{
    memset(this->data, 0, sizeof(this->data));

    int i;
    for (i = 0; i < 10; i++)
        this->m_kModelTextureSwaps[i].Init();

    {
        int i;
        for (i = 0; i < 11; i++)
            this->m_kIconTextures[i].Init();
    }
}

namespace fnv_00504710 {
struct FUN_004855a0
{
};

struct DoorPart30
{
};

struct FUN_00485e00_shell
{
};

struct DoorPart3c
{
};

struct BGSTESTexture
{
    unsigned int GetModelLength() const;
};

struct FUN_0048e370_obj
{
};

struct FUN_00485680
{
};


struct FUN_00504710_shell : public TESCasino
{
    void FUN_00504710();
};

// @fnv 0x00504710
void FUN_00504710_shell::FUN_00504710()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<DoorPart30*>(static_cast<TESFullName *>(this))))->FUN_00487010();

    if (((bool)(::FUN_00401500())))
    {
        this->data.Endian();
    }

    reinterpret_cast<::SDSaveForm *>((reinterpret_cast<FUN_00485e00_shell*>(this)))->FUN_00485e20(
        (const void *)(reinterpret_cast<std::intptr_t>(&this->data)),
        0x38);

    if (((bool)(::FUN_00401500())))
    {
        this->data.Endian();
    }

    {
        int i;
        for (i = 0; i < 8; ++i)
        {
            if (reinterpret_cast<BGSTESTexture*>(reinterpret_cast<unsigned char*>(&this->m_kModelTextureSwaps) + i * 0x20)
                    ->GetModelLength())
            {
                reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<DoorPart3c*>(reinterpret_cast<unsigned char*>(&this->m_kModelTextureSwaps) + i * 0x20)))->ProcessAndFreeData(0x4C444F4D, 0x54444F4D, 0x53444F4D);
            }
        }
    }

    if (reinterpret_cast<BGSTESTexture*>(&this->m_kModelTextureSwaps[7])->GetModelLength())
    {
        reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<DoorPart3c*>(&this->m_kModelTextureSwaps[7])))->ProcessAndFreeData(0x32444F4D, 0x54444F4D, 0x53444F4D);
    }

    if (reinterpret_cast<BGSTESTexture*>(&this->m_kModelTextureSwaps[8])->GetModelLength())
    {
        reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<DoorPart3c*>(&this->m_kModelTextureSwaps[8])))->ProcessAndFreeData(0x33444F4D, 0x54444F4D, 0x53444F4D);
    }

    if (reinterpret_cast<BGSTESTexture*>(&this->m_kModelTextureSwaps[9])->GetModelLength())
    {
        reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<DoorPart3c*>(&this->m_kModelTextureSwaps[9])))->ProcessAndFreeData(0x34444F4D, 0x54444F4D, 0x53444F4D);
    }

    {
        int i;
        for (i = 0; i < 7; ++i)
        {
            reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<unsigned char*>(&this->m_kIconTextures) + i * 0x0C)))->FUN_0048e370(0x4E4F4349);
        }
    }

    {
        int i;
        for (i = 7; i < 0x0B; ++i)
        {
            reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<unsigned char*>(&this->m_kIconTextures) + i * 0x0C)))->FUN_0048e370(0x324F4349);
        }
    }

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}
}  // namespace fnv_00504710

struct FUN_00504340_shell : public TESCasinoChips
{
    unsigned int GetChipsFormType();
    void CopyFromChipsForm(TESForm* pkForm);
};

// @fnv 0x00504340
void FUN_00504340_shell::CopyFromChipsForm(TESForm* pkForm)
{
    TESCasinoChips* pkChips = dynamic_cast<TESCasinoChips*>(pkForm);
    if (!pkChips)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(pkChips);
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(static_cast<FUN_00504340_shell*>(pkChips)->GetChipsFormType());
    reinterpret_cast<::TextString *>(&(m_kPrimaryString))->FUN_004037f0(((const char *)(::FUN_00559450((int *)&(pkChips->m_kPrimaryString)))), 0);
}

struct EndianFlag
{
    bool b;
};

void __cdecl SwapDword(int*, EndianFlag = EndianFlag());

struct IntFieldContainer
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
    int unk28;
    int unk2c;
    int unk30;

    void SwapAllFields();
};
// @fnv 0x005048d0
bool TESCasino::Load(TESFile* apFile)
{
    unsigned char type = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((apFile))->FUN_00472660()));
    if (type != 109)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(apFile));
    SetInitializationState(false);
    int unused2 = 0;
    int model = 7;
    int icon2 = 0;
    int chunk = 0;
    int unused1 = 0;
    int icon;
    while (icon = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0())))
    {
        switch (icon)
        {
        case 0x44494445: {
            char* b = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(b), 512);
            SetEditorID_AtRuntime(b);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(apFile);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, apFile);
            break;
        case 0x4c444f4d: {
            char* b = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(b), 0);
            m_kModelTextureSwaps[unused2].SetModelFilePath(b);
            ::FUN_004893e0(&m_kModelTextureSwaps[unused2], apFile);
            ++unused2;
            break;
        }
        case 0x32444f4d: {
            char* b = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(b), 0);
            m_kModelTextureSwaps[7].SetModelFilePath(b);
            ::FUN_004893e0(&m_kModelTextureSwaps[7], apFile);
            break;
        }
        case 0x33444f4d: {
            char* b = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(b), 0);
            m_kModelTextureSwaps[8].SetModelFilePath(b);
            ::FUN_004893e0(&m_kModelTextureSwaps[8], apFile);
            break;
        }
        case 0x34444f4d: {
            char* b = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(b), 0);
            m_kModelTextureSwaps[9].SetModelFilePath(b);
            ::FUN_004893e0(&m_kModelTextureSwaps[9], apFile);
            break;
        }
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(&m_kIconTextures[icon2], apFile);
            ++icon2;
            break;
        case 0x324f4349:
            ::TESTexture::ReadTextureData(&m_kIconTextures[model], apFile);
            ++model;
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(apFile, &data, 56);
            if (apFile->IsEndianConversionRequired())
                reinterpret_cast<::IntFieldContainer *>(&(data))->SwapAllFields();
            break;
        }
        if (!apFile->NextChunk())
            break;
    }
    return true;
}

// Byte-swaps each of the 13 int fields from unk00 through unk30 by calling SwapDword on each.
// @fnv 0x004faaa0
void IntFieldContainer::SwapAllFields()
{
    SwapDword(&unk00);
    SwapDword(&unk04);
    SwapDword(&unk08);
    SwapDword(&unk0c);
    SwapDword(&unk10);
    SwapDword(&unk14);
    SwapDword(&unk18);
    SwapDword(&unk1c);
    SwapDword(&unk20);
    SwapDword(&unk24);
    SwapDword(&unk28);
    SwapDword(&unk2c);
    SwapDword(&unk30);
}

// Structural layout informed by a prior contributor's unverified October 22, 2026 attempt.
// This destructor reconstruction and exact-match check are independently verified.
struct Primary_504570
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    unsigned int a04, a08, a0c, a10, a14;
    void FUN_00483630();
    ~Primary_504570()
    {
        FUN_00483630();
    }
};
struct Secondary_504570
{
    virtual void v00();
    unsigned int b04;
    void FUN_00591300();
    ~Secondary_504570()
    {
        FUN_00591300();
    }
};
struct Elem32_504570
{
    int a0, a4, a8, ac, a10, a14, a18, a1c;
    void FUN_0048a490();
    ~Elem32_504570()
    {
        FUN_0048a490();
    }
};
struct Elem12_504570
{
    int a0, a4, a8;
    void FUN_0048e2e0();
    ~Elem12_504570()
    {
        FUN_0048e2e0();
    }
};
struct FUN_00504570_cls : Primary_504570, Secondary_504570
{
    unsigned int unk20;
    Elem32_504570 models[10];
    Elem12_504570 textures[11];
    ~FUN_00504570_cls();
};
// @fnv 0x00504540
void* S504540::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00504570_cls *>(this)->FUN_00504570_cls::~FUN_00504570_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00504570
FUN_00504570_cls::~FUN_00504570_cls()
{
    reinterpret_cast<::FUN_00504620_shell *>(this)->ClearFields();
}

#include <string.h>
struct TextureAccess : TESTexture
{
};
struct CasinoAccess : TESCasino
{
    bool FUN_00504e80(TESForm* form);
};
// Returns true when the cast fails or any subsequent comparison check returns nonzero.
// @fnv 0x00504e80
bool CasinoAccess::FUN_00504e80(TESForm* form)
{
    TESCasino* other = dynamic_cast<TESCasino*>(form);
    if (!other)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(other))
        return true;
    for (int i = 0; i < 11; i++)
    {
        if (FUN_00408b20(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<TextureAccess*>(&m_kIconTextures[i])))->FUN_00408da0())),
                         ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((reinterpret_cast<TextureAccess*>(((::TESTexture *)(reinterpret_cast<::FUN_00504e20_shell *>((reinterpret_cast<CasinoAccess*>(other)))->FUN_00504e20(i))))))->FUN_00408da0()))))
            return true;
    }
    for (int j = 0; j < 10; j++)
    {
        if (FUN_00408b20(m_kModelTextureSwaps[j].GetModelFilePath(),
                         ((::TESModelTextureSwap *)(reinterpret_cast<::FUN_00504e00_shell *>((reinterpret_cast<CasinoAccess*>(other)))->FUN_00504e00(j)))->GetModelFilePath()))
            return true;
    }
    if (::FUN_004839c0(data.uiChunkType) != reinterpret_cast<::FUN_00504e40_shell *>((reinterpret_cast<CasinoAccess*>(other)))->FUN_00504e40())
        return true;
    if (memcmp(&data, ((void *)(reinterpret_cast<::FUN_00504e60_shell *>((reinterpret_cast<CasinoAccess*>(other)))->FUN_00504e60())), 0x38))
        return true;
    return false;
}

struct CasinoChipFormCompareCall
{
};
struct CasinoChipStringCompareCall
{
};

struct CasinoChipCompareView : public ::TESCasinoChips
{
    bool FUN_005043b0(::TESForm* form);
};

// @fnv 0x005043b0
bool CasinoChipCompareView::FUN_005043b0(::TESForm* form)
{
    ::TESCasinoChips* chip = dynamic_cast< ::TESCasinoChips*>(form);
    if (!chip)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<CasinoChipFormCompareCall*>(this)))->FUN_00485270(chip))
        return true;
    if (reinterpret_cast<::FUN_00501c90_shell *>((reinterpret_cast<CasinoChipStringCompareCall*>(&m_kPrimaryString)))->CompareString(&chip->m_kPrimaryString, true))
        return true;
    return false;
}

struct S_00504ff0_Base1
{
    virtual void FUN_00504ff0();
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
};

struct S_00504ff0_Base2
{
    virtual void FUN_00504ff0();
};

struct S_00504ff0_Derived : S_00504ff0_Base1, S_00504ff0_Base2
{
    S_00504ff0_Derived();
// @fnv 0x00504ff0
    virtual void FUN_00504ff0();
};

S_00504ff0_Derived::S_00504ff0_Derived()
{}
