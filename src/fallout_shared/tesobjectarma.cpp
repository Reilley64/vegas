// fallout_shared/tesobjectarma.cpp: TESObjectARMA, ArmaCompare (12 functions)

#include <cstring>
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0047a380_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048ea80_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00512bd0.h"
#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESFullName.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048ea40__TESValueForm.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_005b5000.h"
#include "tesobjectarma_load.h"
#include "fnv/symbols_00472000.h"
class TESForm;

class TESFormInitFlag
{
  public:
};

class TESForm
{
  public:
    virtual ~TESForm();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot40();
    virtual void Slot41();
    virtual void Slot42();
    virtual void Slot43();
    virtual void Slot44();
    virtual void Slot45();
    virtual void Slot46();
    virtual void Slot47();
    virtual void Slot48();
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void Slot53();
    virtual void Slot54();
    virtual void Slot55();
    virtual void readOBNDSubRecord(TESFile*);
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void Slot62();
    virtual void Slot63();
    virtual void Slot64();
    virtual void Slot65();
    virtual void Slot66();
    virtual void Slot67();
    virtual void Slot68();
    virtual void Slot69();
    virtual void Slot70();
    virtual void Slot71();
    virtual void Slot72();
    virtual void Slot73();
    virtual void Slot74();
    virtual void Slot75();
    virtual const char* GetEditorID();
    virtual bool SetEditorID(const char*);
    void SetInitializationState(bool initialized);
public:
    bool GetInitialized() const;
public:
    void LoadGame(void *);
};

class TESBipedModelForm
{
  public:
    unsigned char prefix[4];
    unsigned int bipedFlags;
    unsigned char m_ucBipedModelData;
    unsigned char padding[3];
    TESModelTextureSwap bipedModel[2];
    TESModelTextureSwap worldModel[2];
    TESTexture1024 m_kIcon[2];
    BGSMessageIcon messageIcon[2];
    TESModel m_kFaceGenModel;
    void InitItem(TESForm* form);
};

class BGSDestructibleObjectForm
{
  public:
    unsigned char bytes[8];
    void InitItem(TESForm* form);
};

class TESObjectARMA : public TESForm
{
  public:
    unsigned char padToBiped[0x2c];
    void* unk30;
    unsigned char pad34[0x8];
    void* unk3c;
    unsigned char pad40[0x8];
    void* unk48;
    unsigned char pad4c[0xc];
    void* unk58;
    unsigned char pad5c[0x4];
    void* unk60;
    unsigned char pad64[0x4];
    void* unk68;
    unsigned char pad6c[0x4];
    TESBipedModelForm biped;
    BGSDestructibleObjectForm destructible;
    BGSEquipType equipType;
    void* unk15c;
    unsigned char pad160[0x4];
    void* unk164;
    unsigned char pad168[0x4];
    void* unk16c;
    unsigned char pad170[0x8];
    ArmorData data;
    bool Load(TESFile* file);
    void ResetFormData();
    void InitItem();
};

// Zeroes the ARMA's data block with memset.
// @fnv 0x00512010
void TESObjectARMA::ResetFormData()
{
    memset(&data, 0, sizeof(data));
}

// Initializes the armor form: warns if no biped slots are set, then initializes destructible and biped data and marks the form initialized.
// @fnv 0x00512030
void TESObjectARMA::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(((TESFormInitFlag*)this)))->GetInitialized())
        return;
    if (biped.bipedFlags == 0)
        ::FUN_005b5e40();
    destructible.InitItem((TESForm*)this);
    biped.InitItem((TESForm*)this);
    SetInitializationState(true);
}

class TESObjectARMO
{
  public:
    TESObjectARMO();
    ~TESObjectARMO();
};
struct SFTX
{
};
extern int DAT_0102a214;
extern int DAT_0102a228;
extern int DAT_0102a23c;
extern int DAT_0102a250;
extern int DAT_0102a264;
extern int DAT_0102a278;
extern int DAT_0102a2a4;
extern int DAT_0102a2b8;
extern int DAT_0102a2d8;
extern int DAT_0102a2f0;
extern int DAT_0102a304;
extern int DAT_0102a31c;
struct FUN_00511e40
{
    TESObjectARMO armo;
    FUN_00511e40();
};
// @fnv 0x00511e40
FUN_00511e40::FUN_00511e40()
{
    *(std::intptr_t*)((char*)this + 0x0) = (std::intptr_t)&DAT_0102a31c;
    *(std::intptr_t*)((char*)this + 0x30) = (std::intptr_t)&DAT_0102a304;
    *(std::intptr_t*)((char*)this + 0x3c) = (std::intptr_t)&DAT_0102a2f0;
    *(std::intptr_t*)((char*)this + 0x48) = (std::intptr_t)&DAT_0102a2d8;
    *(std::intptr_t*)((char*)this + 0x58) = (std::intptr_t)&DAT_0102a2b8;
    *(std::intptr_t*)((char*)this + 0x60) = (std::intptr_t)&DAT_0102a2a4;
    *(const char**)((char*)this + 0x68) = " rH";
    *(std::intptr_t*)((char*)this + 0x70) = (std::intptr_t)&DAT_0102a278;
    *(std::intptr_t*)((char*)this + 0x14c) = (std::intptr_t)&DAT_0102a264;
    *(std::intptr_t*)((char*)this + 0x154) = (std::intptr_t)&DAT_0102a250;
    *(std::intptr_t*)((char*)this + 0x15c) = (std::intptr_t)&DAT_0102a23c;
    *(std::intptr_t*)((char*)this + 0x164) = (std::intptr_t)&DAT_0102a228;
    *(std::intptr_t*)((char*)this + 0x16c) = (std::intptr_t)&DAT_0102a214;
    reinterpret_cast<::FUN_004f15a0_shell *>((((SFTX*)this)))->FUN_004f15a0(0x60);
    ((TESObjectARMA*)this)->ResetFormData();
}

struct FUN_00484d60_holder
{
};
struct FUN_0048ea40_holder
{
};

struct FUN_005144c0_shell : ::TESObjectARMA
{
    void FUN_005144c0(std::uintptr_t flags);
};

// @fnv 0x005144c0
void FUN_005144c0_shell::FUN_005144c0(std::uintptr_t flags)
{
    reinterpret_cast<::FakeForm *>((reinterpret_cast<FUN_00484d60_holder*>(this)))->SaveIfChanged((::BGSSaveFormBuffer *)(flags));
    reinterpret_cast<::fnv_0048ea40::TESValueForm *>((reinterpret_cast<FUN_0048ea40_holder*>(&this->unk58)))->FUN_0048ea40((::fnv_0048ea40::BGSSaveFormBuffer *)(flags));
}

struct BGSLoadFormBuffer;

struct TESValueFormLoadGame
{
};

struct TESFormBufferAccess
{
};

struct FUN_005160a0_shell : TESObjectARMO
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// Loads the form buffer via TESFormBufferAccess::LoadGame, then loads the value form at offset 0x58 via TESValueFormLoadGame::LoadGame.
// @fnv 0x005160a0
void FUN_005160a0_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    reinterpret_cast<::TESForm *>((reinterpret_cast<TESFormBufferAccess*>(this)))->LoadGame(buffer);
    reinterpret_cast<::FUN_0048ea80_Class *>((reinterpret_cast<TESValueFormLoadGame*>(static_cast<TESObjectARMO*>(this) + 0x58)))->FUN_0048ea80(buffer);
}

struct FUN_00511f30_holder
{
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_00511f60_shell : ::TESObjectARMA
{
    void FUN_00511f60();
};
// Calls FUN_00511f60, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00511f30
void* FUN_00511f30_holder::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00511f60_shell *>(this)->FUN_00511f60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00511f60
void FUN_00511f60_shell::FUN_00511f60()
{
    *(void**)this = (void*)&DAT_0102a31c;
    this->unk30 = (void*)&DAT_0102a304;
    this->unk3c = (void*)&DAT_0102a2f0;
    this->unk48 = (void*)&DAT_0102a2d8;
    this->unk58 = (void*)&DAT_0102a2b8;
    this->unk60 = (void*)&DAT_0102a2a4;
    this->unk68 = (void*)" rH";
    *(void**)((char*)this + 0x70) = (void*)&DAT_0102a278;
    *(void**)((char*)this + 0x14c) = (void*)&DAT_0102a264;
    *(void**)((char*)this + 0x154) = (void*)&DAT_0102a250;
    this->unk15c = (void*)&DAT_0102a23c;
    this->unk164 = (void*)&DAT_0102a228;
    this->unk16c = (void*)&DAT_0102a214;
    reinterpret_cast<::FUN_00512bd0 *>(this)->FUN_00512bd0::~FUN_00512bd0();
}

template <int N> struct EndianSizeTag
{
};
struct FUN_00512810_holder
{
    void FUN_00512810();
};
// @fnv 0x005120a0
bool TESObjectARMA::Load(TESFile* file)
{
    unsigned char form = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (form != 0x60)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    while (int chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            ::ReadFullName(this ? (TESFullName*)&this->unk30 : 0, file);
            break;
        case 'TDMB':
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570() < 11)
            {
                BIPED_MODEL_OLD oldData;
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&oldData), 4);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_00512810_holder *>(&(oldData))->FUN_00512810();
                biped.m_ucBipedModelData = oldData.m_ucBipedModelData;
                biped.bipedFlags = oldData.m_uiBipedModelFlags;
            }
            else
            {
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&biped.bipedFlags), 8);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::fnv_00503210::Unk *>((((RegionDataEntry*)&biped.bipedFlags)))->FUN_00503210();
            }
            biped.m_ucBipedModelData &= ~0x10;
            break;
        case 'TCMB': {
            char* constraint = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(constraint), 0);
            biped.m_kFaceGenModel.SetModelFilePath(constraint);
            break;
        }
        case 'LDOM': {
            char* maleBiped = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(maleBiped), 0);
            biped.bipedModel[0].SetModelFilePath(maleBiped);
            break;
        }
        case 'TDOM':
            ::FUN_004893e0(&biped.bipedModel[0], file);
            break;
        case 'SDOM':
            TESModelTextureSwap::ReadTextureSwapChunk(&biped.bipedModel[0], file);
            break;
        case 'DDOM':
            TESModel::LoadModelData(&biped.bipedModel[0], file);
            break;
        case 'DSOM':
            TESModel::LoadModelData(&biped.bipedModel[1], file);
            break;
        case '2DOM': {
            char* maleWorld = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(maleWorld), 0);
            biped.worldModel[0].SetModelFilePath(maleWorld);
            break;
        }
        case 'T2OM':
            ::FUN_004893e0(&biped.worldModel[0], file);
            break;
        case 'S2OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&biped.worldModel[0], file);
            break;
        case 'NOCI': {
            char* maleIcon = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(maleIcon), 0);
            reinterpret_cast<::TESFullName *>(&(biped.m_kIcon[0]))->SetFullName(maleIcon);
            break;
        }
        case 'OCIM': {
            char* maleMessage = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(maleMessage), 0);
            reinterpret_cast<::FUN_0047a380_shell *>(&(biped.messageIcon[0]))->FUN_0047a380((char *)(maleMessage));
            break;
        }
        case '2CIM': {
            char* femaleMessage = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(femaleMessage), 0);
            reinterpret_cast<::FUN_0047a380_shell *>(&(biped.messageIcon[1]))->FUN_0047a380((char *)(femaleMessage));
            break;
        }
        case '3DOM': {
            char* femaleBiped = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(femaleBiped), 0);
            biped.bipedModel[1].SetModelFilePath(femaleBiped);
            break;
        }
        case 'T3OM':
            ::FUN_004893e0(&biped.bipedModel[1], file);
            break;
        case 'S3OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&biped.bipedModel[1], file);
            break;
        case '4DOM': {
            char* femaleWorld = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(femaleWorld), 0);
            biped.worldModel[1].SetModelFilePath(femaleWorld);
            break;
        }
        case 'T4OM':
            ::FUN_004893e0(&biped.worldModel[1], file);
            break;
        case 'S4OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&biped.worldModel[1], file);
            break;
        case '2OCI': {
            char* femaleIcon = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(femaleIcon), 0);
            reinterpret_cast<::TESFullName *>(&(biped.m_kIcon[1]))->SetFullName(femaleIcon);
            break;
        }
        case 'TSED':
        case 'DTSD':
            ::FUN_004781e0(this ? &destructible : 0, file);
            break;
        case 'PYTE': {
            unsigned int type = 0;
            file->GetChunkData(&type);
            // Reuse the canonical identity of the folded scalar setter.
            reinterpret_cast<::CombatProcedure *>((((TESResponse*)&equipType)))->Initialize((::CombatController *)(std::uintptr_t)(type));
            break;
        }
        case 'MAND':
            memset(&data, 0, sizeof(data));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data), sizeof(data));
            if (file->IsEndianConversionRequired())
            {
                FUN_00535aa0_Class converter{};
                std::memcpy(&converter.unk00, data.bytes, sizeof(converter.unk00));
                std::memcpy(&converter.unk04, data.bytes + 4, sizeof(converter.unk04));
                converter.FUN_00535aa0();
                std::memcpy(data.bytes, &converter.unk00, sizeof(converter.unk00));
                std::memcpy(data.bytes + 4, &converter.unk04, sizeof(converter.unk04));
            }
            break;
        }
        if (chunk == 'ATAD' && file->IsEndianConversionRequired())
        {
            FUN_00535aa0_Class converter{};
            std::memcpy(&converter.unk00, data.bytes, sizeof(converter.unk00));
            std::memcpy(&converter.unk04, data.bytes + 4, sizeof(converter.unk04));
            converter.FUN_00535aa0();
            std::memcpy(data.bytes, &converter.unk00, sizeof(converter.unk00));
            std::memcpy(data.bytes + 4, &converter.unk04, sizeof(converter.unk04));
        }
        if (!file->NextChunk())
            break;
    }
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(FORM_ARMO)));
    return true;
}
// Byte-swaps the 16-bit value at the start of this object by calling BSEndian.
// @fnv 0x00512810
void FUN_00512810_holder::FUN_00512810()
{
    ::FUN_00407a90((short *)(unsigned short *)((unsigned short*)this));
}

struct FUN_005e78f0_t
{
};
struct FUN_005128e0_obj : ::TESObjectARMA
{
    void FUN_005128e0(TESForm* apCopy);
};
// If apCopy is a TESObjectARMO, copies 0xc bytes at offset 0x178 from apCopy into this and calls FUN_004851b0(apCopy).
// @fnv 0x005128e0
void FUN_005128e0_obj::FUN_005128e0(TESForm* apCopy)
{
    TESObjectARMO* parmo = dynamic_cast<TESObjectARMO*>(apCopy);
    if (parmo == 0)
        return;
    __memcpy((char*)&this->data, (char*)apCopy + 0x178, 0xc);
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
}

struct FUN_004855a0_shell
{
};
struct S_00487010
{
};
struct FUN_00480610_shell
{
    void InitBipedModel();
};
struct FUN_00479350_shell
{
    void FUN_00479350();
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct FUN_00485680_shell
{
};
struct FUN_00512840_shell : ::TESObjectARMA
{
    void FUN_00512840();
};
// @fnv 0x00512840
void FUN_00512840_shell::FUN_00512840()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_shell*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)&this->unk30)))->FUN_00487010();
    ((FUN_00480610_shell*)&this->biped.prefix[0])->InitBipedModel();
    ((FUN_00479350_shell*)&this->equipType.storage[0])->FUN_00479350();
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00535aa0_Class *>(((&this->data)))->FUN_00535aa0();
    ::AppendChunk(0x4d414e44, (char*)&this->data, 0xc);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00535aa0_Class *>(((&this->data)))->FUN_00535aa0();
    reinterpret_cast<::Holder *>((((FUN_00485680_shell*)this)))->FUN_00485680();
}

struct FUN_005e79a0_t
{
};
struct ArmaCompare : TESObjectARMA
{
    bool FUN_00512940(TESForm* apCompare);
};
// @fnv 0x00512940
bool ArmaCompare::FUN_00512940(TESForm* apCompare)
{
    TESObjectARMA* pcomp = dynamic_cast<TESObjectARMA*>(apCompare);
    if (!pcomp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pcomp))
        return true;
    if (std::memcmp(&data, &pcomp->data, sizeof(data)))
        return true;
    return false;
}

// MSVC adjustor thunk: the primary base occupies 0x58 bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase_005129c0
{
    virtual void FUN_005129c0();
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
};

struct SecondaryBase_005129c0
{
    virtual void FUN_005129c0();
};

struct Derived_005129c0 : PrimaryBase_005129c0, SecondaryBase_005129c0
{
    Derived_005129c0();
// @fnv 0x005129c0
    virtual void FUN_005129c0();
};

Derived_005129c0::Derived_005129c0()
{}

// FUN_005129d0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x58 ; jmp <final overrider>
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is therefore the size of the primary base: a vtable
// pointer plus 21 int members (4 + 84 = 0x58 bytes). Both bases declare the
// same virtual function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the
// adjusting thunk.
struct ArmaPrimaryBase
{
    virtual void FUN_005129d0();
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
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
};

struct ArmaSecondaryBase
{
    virtual void FUN_005129d0();
};

struct ArmaDerived : ArmaPrimaryBase, ArmaSecondaryBase
{
    ArmaDerived();
// @fnv 0x005129d0
    virtual void FUN_005129d0();
};

ArmaDerived::ArmaDerived()
{}

namespace fnv_005129e0 {
// FUN_005129e0 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x58 ; jmp <final overrider>
//
// MSVC emits such a thunk in the vtable of a class that inherits the same
// virtual slot from two bases: the slot of the second base holds a small
// stub that moves `this` back onto the complete object (sub ecx, sizeof of
// the primary base)) and tail-jumps to the implementation.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 21 int members (4 + 84 = 0x58 bytes).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct ArmaPrimaryBase
{
    virtual void FUN_005129e0();
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
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
};

struct ArmaSecondaryBase
{
    virtual void FUN_005129e0();
};

struct ArmaDerived : ArmaPrimaryBase, ArmaSecondaryBase
{
    ArmaDerived();
// @fnv 0x005129e0
    virtual void FUN_005129e0();
};

ArmaDerived::ArmaDerived()
{}
}
