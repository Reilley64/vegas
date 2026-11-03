// tesobjectarmo.cpp: TESObjectARMO, ArmorSerializer, ArmorCopy, TESObjectARMOFoley and more (15 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_0047a380_shell.h"
#include "fnv/decl/FUN_00480610_shell.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00485e00_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00512810_holder.h"
#include "fnv/decl/FUN_00535aa0_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047b560__FUN_0047b560_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e9b0__TESValueForm.h"
#include "fnv/decl/fnv_0048e9e0__TESValueForm.h"
#include "fnv/decl/fnv_0048ea10__TESValueForm.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_005b5000.h"
#include "tesobjectarmo_decls.h"
#include "tesobjectarmo_load.h"
extern "C" void* __cdecl memset(void*, int, unsigned int);

// @fnv 0x00512e10
void TESObjectARMO::ResetFormData()
{
    memset(&data, 0, sizeof(data));
    m_bUsesSoundList = false;
    m_pSoundSourceArmor = 0;
    reinterpret_cast<::FUN_0041fd00_shell *>(this)->FUN_0041fd00((*(int *)&(const ::MagicSystem__CastingType &)(MagicSystem__CastingType_CONSTANT_EFFECT)));
}

// @fnv 0x00512e60
void TESObjectARMO::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    if (!m_kBipedModelForm.m_uiBipedModelFlags)
        ::FUN_005b5e40();
    TESScriptableForm::InitItem(this);
    TESEnchantableForm::InitItem(this);
    BGSDestructibleObjectForm::InitItem(this);
    TESBipedModelForm::InitItem(this);
    BGSRepairItemList::InitItem(this);
    BGSBipedModelList::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    if (!m_bUsesSoundList && m_pSoundSourceArmor)
    {
        m_pSoundSourceArmor = static_cast<TESObjectARMO*>(::FUN_004839c0((unsigned int)m_pSoundSourceArmor));
    }
    else if (m_bUsesSoundList && m_pPickupPutdownSoundList)
    {
        BSSimpleList<SoundDescriptor*>* soundList = m_pPickupPutdownSoundList;
        while (soundList && ((::SoundDescriptor *)(new ((void *)(soundList)) ::Vec3())))
        {
            SoundDescriptor* sound = ((::SoundDescriptor *)(new ((void *)(soundList)) ::Vec3()));
            soundList = ((::BSSimpleList< ::SoundDescriptor *> *)(reinterpret_cast<::Callees *>((soundList))->FUN_00726070()));
            if (sound->SoundAssetTmp)
                sound->SoundAssetTmp = (TESSound*)::FUN_004839c0((unsigned int)sound->SoundAssetTmp);
        }
    }
    SetInitializationState(true);
}

// Reads an ARMO record from the TESFile: checks form type 24, loads the record header, then dispatches each chunk to the matching sub-record loader.
// @fnv 0x00512fd0
bool TESObjectARMO::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 24)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunk;
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 'DIDE': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 512);
            SetEditorID_AtRuntime(name);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            ::ReadFullName(this, file);
            break;
        case 'IRCS': {
            unsigned int uiScriptFormID = 0;
            file->GetChunkData(&uiScriptFormID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::Script *)((Script*)uiScriptFormID));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 'MANE':
        case 'MTIE': {
            unsigned int uiEnchantmentFormID = 0;
            file->GetChunkData(&uiEnchantmentFormID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::EnchantmentItem *)((EnchantmentItem*)uiEnchantmentFormID));
            break;
        }
        case 'MANA':
        case 'TMAE': {
            unsigned short usEnchantmentAmount = 0;
            reinterpret_cast<::FUN_00472840_impl *>((((TESFileChunkData16*)file)))->ReadChunkData(&usEnchantmentAmount);
            SetFormEnchantmentAmount(usEnchantmentAmount);
            break;
        }
        case 'TDMB': {
            if (reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570() < 11)
            {
                TESObjectARMOOldBipedModel oldBipedModel;
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&oldBipedModel), sizeof(oldBipedModel));
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_00512810_holder *>(&(oldBipedModel))->FUN_00512810();
                m_kBipedModelForm.m_ucBipedModelData = oldBipedModel.flags;
                m_kBipedModelForm.m_uiBipedModelFlags = oldBipedModel.slots;
            }
            else
            {
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_kBipedModelForm), sizeof(m_kBipedModelForm));
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::fnv_00503210::Unk *>(&(m_kBipedModelForm))->FUN_00503210();
            }
            m_kBipedModelForm.m_ucBipedModelData &= ~16;
            break;
        }
        case 'TCMB': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0);
            m_kFaceGenModel.SetModelFilePath(name);
            break;
        }
        case 'LDOM': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0);
            bipedModel[0].SetModelFilePath(name);
            break;
        }
        case 'TDOM':
            ::FUN_004893e0(&bipedModel[0], file);
            break;
        case 'SDOM':
            TESModelTextureSwap::ReadTextureSwapChunk(&bipedModel[0], file);
            break;
        case 'DDOM':
            TESModel::LoadModelData(&bipedModel[0], file);
            break;
        case 'DSOM':
            TESModel::LoadModelData(&bipedModel[1], file);
            break;
        case '2DOM': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0);
            worldModel[0].SetModelFilePath(name);
            break;
        }
        case 'T2OM':
            ::FUN_004893e0(&worldModel[0], file);
            break;
        case 'S2OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&worldModel[0], file);
            break;
        case 'NOCI': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0);
            reinterpret_cast<::TESFullName *>((((TESTexture1024*)&m_kIcon[0])))->SetFullName(name);
            break;
        }
        case 'OCIM': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0);
            reinterpret_cast<::FUN_0047a380_shell *>(&(messageIcon[0]))->FUN_0047a380((char *)(name));
            break;
        }
        case '2CIM': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0);
            reinterpret_cast<::FUN_0047a380_shell *>(&(messageIcon[1]))->FUN_0047a380((char *)(name));
            break;
        }
        case '3DOM': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0);
            bipedModel[1].SetModelFilePath(name);
            break;
        }
        case 'T3OM':
            ::FUN_004893e0(&bipedModel[1], file);
            break;
        case 'S3OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&bipedModel[1], file);
            break;
        case '4DOM': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0);
            worldModel[1].SetModelFilePath(name);
            break;
        }
        case 'T4OM':
            ::FUN_004893e0(&worldModel[1], file);
            break;
        case 'S4OM':
            TESModelTextureSwap::ReadTextureSwapChunk(&worldModel[1], file);
            break;
        case '2OCI': {
            char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 0);
            reinterpret_cast<::TESFullName *>((((TESTexture1024*)&m_kIcon[1])))->SetFullName(name);
            break;
        }
        case 'TSED':
        case 'DTSD':
            ::FUN_004781e0(this, file);
            break;
        case 'LPER': {
            unsigned int uiListFormID = 0;
            file->GetChunkData(&uiListFormID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::BGSListForm *)((BGSListForm*)uiListFormID));
            break;
        }
        case 'LPIB': {
            unsigned int uiListFormID = 0;
            file->GetChunkData(&uiListFormID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::BGSListForm *)((BGSListForm*)uiListFormID));
            break;
        }
        case 'PYTE': {
            unsigned int uiEquipType = 0;
            file->GetChunkData(&uiEquipType);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((*(::CombatController * *)&(const ::BGSEquipType__EQUIP_TYPE &)((BGSEquipType__EQUIP_TYPE)uiEquipType)));
            break;
        }
        case 'MANY': {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::TESSound *)((TESSound*)sound));
            break;
        }
        case 'MANZ': {
            unsigned int sound = 0;
            file->GetChunkData(&sound);
            reinterpret_cast<::TESRegionGrassObject *>(this)->AssignLandTexture((::TESLandTexture *)(::TESSound *)((TESSound*)sound));
            break;
        }
        case 'MANB': {
            unsigned int isBase = 0;
            file->GetChunkData(&isBase);
            if (isBase)
                m_bUsesSoundList = true;
            else
                m_bUsesSoundList = false;
            break;
        }
        case 'MANT': {
            if (!m_bUsesSoundList)
            {
                unsigned int formID = 0;
                file->GetChunkData(&formID);
                m_pSoundSourceArmor = (TESObjectARMO*)formID;
            }
            break;
        }
        case 'MANS': {
            if (m_bUsesSoundList)
            {
                if (!m_pPickupPutdownSoundList)
                    m_pPickupPutdownSoundList = new BSSimpleList<SoundDescriptor*>;
                SoundDescriptor* sound = new SoundDescriptor;
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, sound, sizeof(SoundDescriptor));
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::TESForm *>((sound))->ClearData();
                m_pPickupPutdownSoundList->AddHead(sound);
            }
            break;
        }
        case 'ATAD': {
            unsigned int added = reinterpret_cast<::FUN_00486620_shell *>(this)->FUN_00486620();
            if (reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C() - added == 2)
            {
                TESObjectARMOOldData oldArmoData;
                memset(&oldArmoData, 0, sizeof(oldArmoData));
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &oldArmoData, sizeof(oldArmoData));
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::FUN_00512810_holder *>(&(oldArmoData))->FUN_00512810();
                memcpy(&data, &oldArmoData, sizeof(oldArmoData));
                data.cFlags = 0;
            }
            else
            {
                reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, 0, 0);
            }
            break;
        }
        case 'MAND': {
            memset(&data, 0, sizeof(data));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&data), sizeof(data));
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00535aa0_Class *>(&(data))->FUN_00535aa0();
            break;
        }
        }
        if (chunk == 'ATAD' && file->IsEndianConversionRequired())
            reinterpret_cast<::FUN_00535aa0_Class *>(&(data))->FUN_00535aa0();
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_00514450_shell : public TESBipedModelForm
{
    bool FUN_00514450();
};
// Returns 1 for heavy armor, 2 for medium armor, otherwise 0.
// @fnv 0x00514410
unsigned char TESObjectARMO::GetArmorType()
{
    if (GetIsHeavyArmor())
        return 1;
    if (reinterpret_cast<::FUN_00514450_shell *>((void *)this)->FUN_00514450())
        return 2;
    return 0;
}

// @fnv 0x00514450
bool FUN_00514450_shell::FUN_00514450()
{
    return *((unsigned char*)this + 8) & 8;
}

struct FUN_00484bf0
{
    unsigned short GetSaveSize(unsigned int);
};

struct FUN_0048e9b0
{
    unsigned short GetSaveSize(unsigned int);
};

struct FUN_00514470
{
    FUN_00484bf0 m_00;
    unsigned char m_58[0x58];
    unsigned short GetSaveSize(unsigned int);
};

// Returns the sum of the save sizes reported by the sub-object at offset 0 and the one at offset 0x58, both queried with aiFlags.
// @fnv 0x00514470
unsigned short FUN_00514470::GetSaveSize(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_00484bf0_shell *>(&(m_00))->FUN_00484bf0(aiFlags);
    isize += reinterpret_cast<::fnv_0048e9b0::TESValueForm *>((((FUN_0048e9b0*)((char*)this + 0x58))))->FUN_0048e9b0(aiFlags);
    return isize;
}

struct FUN_0051b070_shell
{
};
struct FUN_00516040_shell
{
    FUN_0051b070_shell m0;
    char _pad[0x58 - sizeof(FUN_0051b070_shell)];
    FUN_0051b070_shell m58;
    void FUN_00516040(unsigned int);
};
// Calls FUN_00484c20 on m0 and FUN_0048e9e0 on m58, passing aiFlags to each.
// @fnv 0x00516040
void FUN_00516040_shell::FUN_00516040(unsigned int aiFlags)
{
    reinterpret_cast<::PC7d *>(&(m0))->FUN_00484c20(aiFlags);
    reinterpret_cast<::fnv_0048e9e0::TESValueForm *>(&(m58))->FUN_0048e9e0(aiFlags);
}

struct TESFormStub
{
};

struct TESValueFormStub
{
};

struct FUN_00516070_shell
{
    char _pad[0x58];
    TESValueFormStub m_valueStub;
    void __thiscall FUN_00516070(unsigned int, unsigned int);
};

// Forwards both arguments to TESFormStub::FUN_00484c50 on this object, then to m_valueStub.FUN_0048ea10.
// @fnv 0x00516070
void __thiscall FUN_00516070_shell::FUN_00516070(unsigned int a1, unsigned int a2)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>((reinterpret_cast<TESFormStub*>(this)))->FUN_00484c50(a1, a2);
    reinterpret_cast<::fnv_0048ea10::TESValueForm *>(&(m_valueStub))->FUN_0048ea10(a1, a2);
}

struct B1_4fe
{
    virtual ~B1_4fe();
    B1_4fe();
    char pad[0x2c];
};
namespace stand {
struct TESFullName
{
    virtual void f0();
    TESFullName();
    ~TESFullName();
    char pad[0x8];
};
struct TESScriptableForm
{
    virtual void f0();
    TESScriptableForm();
    char pad[0x8];
};
struct TESEnchantableForm
{
    virtual void f0();
    TESEnchantableForm();
    char pad[0xc];
};
struct TESValueForm
{
    virtual void f0();
    TESValueForm();
    ~TESValueForm();
    char pad[0x4];
};
struct TESWeightForm
{
    virtual void f0();
    TESWeightForm();
    ~TESWeightForm();
    char pad[0x4];
};
struct TESHealthForm
{
    virtual void f0();
    TESHealthForm();
    ~TESHealthForm();
    char pad[0x4];
};
struct TESBipedModelForm
{
    virtual void f0();
    TESBipedModelForm();
    ~TESBipedModelForm();
    char pad[0xd8];
};
struct BGSDestructibleObjectForm
{
    virtual void f0();
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();
    char pad[0x4];
};
struct BGSEquipType
{
    virtual void f0();
    BGSEquipType();
    char pad[0x4];
};
struct BGSRepairItemList
{
    virtual void f0();
    BGSRepairItemList();
    ~BGSRepairItemList();
    char pad[0x4];
};
struct BGSBipedModelList
{
    virtual void f0();
    BGSBipedModelList();
    ~BGSBipedModelList();
    char pad[0x4];
};
struct BGSPickupPutdownSounds
{
    virtual void f0();
    BGSPickupPutdownSounds();
    ~BGSPickupPutdownSounds();
    char pad[0x8];
};
}
struct SoundPlaybackHandle
{
};
struct FUN_005129f0_ARMO
{
};
struct FUN_005129f0 : public B1_4fe,
                      public stand::TESFullName,
                      public stand::TESScriptableForm,
                      public stand::TESEnchantableForm,
                      public stand::TESValueForm,
                      public stand::TESWeightForm,
                      public stand::TESHealthForm,
                      public stand::TESBipedModelForm,
                      public stand::BGSDestructibleObjectForm,
                      public stand::BGSEquipType,
                      public stand::BGSRepairItemList,
                      public stand::BGSBipedModelList,
                      public stand::BGSPickupPutdownSounds
{
    unsigned char data[0xc];
    unsigned int flags;
    void* m_pPickupPutdownSoundList;
    bool m_bUsesSoundList;
    FUN_005129f0();
    virtual ~FUN_005129f0();
};
// Sets the form type to 0x18 and then runs the ARMO-specific initialization on this object.
// @fnv 0x005129f0
FUN_005129f0::FUN_005129f0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>((((SoundPlaybackHandle*)this)))->FUN_004f15a0(0x18);
    reinterpret_cast<::TESObjectARMO *>((((FUN_005129f0_ARMO*)this)))->ResetFormData();
}

struct FUN_0050e9f0 : public TESBoundObject
{
    ~FUN_0050e9f0();
};
struct FUN_00591300 : public TESFullName
{
    ~FUN_00591300();
};
struct FUN_0048e7d0 : public TESValueForm
{
    ~FUN_0048e7d0();
};
struct FUN_0048eaf0 : public TESWeightForm
{
    ~FUN_0048eaf0();
};
struct FUN_00487200 : public TESHealthForm
{
    ~FUN_00487200();
};
struct FUN_00480400 : public TESBipedModelForm
{
    ~FUN_00480400();
};
struct FUN_00475380 : public BGSDestructibleObjectForm
{
    ~FUN_00475380();
};
struct FUN_0047b880 : public BGSRepairItemList
{
    ~FUN_0047b880();
};
struct FUN_00474d40 : public BGSBipedModelList
{
    ~FUN_00474d40();
};
struct FUN_0047b520 : public BGSPickupPutdownSounds
{
    ~FUN_0047b520();
};
class FUN_00512bd0 : public FUN_0050e9f0,
                     public FUN_00591300,
                     public TESScriptableForm,
                     public TESEnchantableForm,
                     public FUN_0048e7d0,
                     public FUN_0048eaf0,
                     public FUN_00487200,
                     public FUN_00480400,
                     public FUN_00475380,
                     public BGSEquipType,
                     public FUN_0047b880,
                     public FUN_00474d40,
                     public FUN_0047b520
{
  public:
    virtual ~FUN_00512bd0();
};
// @fnv 0x00512bd0
FUN_00512bd0::~FUN_00512bd0()
{}

struct FUN_004855a0_shell
{
};
struct FUN_00487010_shell
{
    void FUN_00487010();
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_0047bd70_shell
{
    void FUN_0047bd70();
};
struct S_00480610
{
};
struct S_00477f20
{
};
struct S0047b8a0
{
    void FUN_0047b8a0();
};
struct FUN_00474d60_shell
{
    void FUN_00474d60();
};
struct FUN_00479350_shell
{
    void FUN_00479350();
};
struct FUN_0047b560_holder
{
};
struct RefObj
{
};
struct FoleyNode : BSSimpleList<SoundDescriptor*>
{
};
struct FUN_00513d60
{
    unsigned int formID;
    unsigned char soundType;
    int value;
    FUN_00513d60();
};
struct ArmorSerializer
{
    TESBoundObject bound;
    TESFullName fullName;
    TESScriptableForm scriptable;
    TESEnchantableForm enchantable;
    TESValueForm valueForm;
    TESWeightForm weightForm;
    TESHealthForm healthForm;
    TESBipedModelForm biped;
    BGSDestructibleObjectForm destructible;
    BGSEquipType equipType;
    BGSRepairItemList repairList;
    BGSBipedModelList modelList;
    BGSPickupPutdownSounds pickupSounds;
    ArmorData data;
    unsigned int flags;
    union
    {
        BSSimpleList<SoundDescriptor*>* m_pPickupPutdownSoundList;
        TESObjectARMO* m_pSoundSourceArmor;
    };
    bool m_bUsesSoundList;
    void Save();
};

// @fnv 0x00513d90
void ArmorSerializer::Save()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_shell*)this)))->FUN_004855a0();
    ((FUN_00487010_shell*)&fullName)->FUN_00487010();
    ((S_0048cca0*)&scriptable)->FUN_0048cca0();
    ((FUN_0047bd70_shell*)&enchantable)->FUN_0047bd70();
    reinterpret_cast<::FUN_00480610_shell *>((((S_00480610*)&biped)))->InitBipedModel();
    reinterpret_cast<::FUN_00477f20_shell *>((((S_00477f20*)&destructible)))->FUN_00477f20();
    ((S0047b8a0*)&repairList)->FUN_0047b8a0();
    ((FUN_00474d60_shell*)&modelList)->FUN_00474d60();
    ((FUN_00479350_shell*)&equipType)->FUN_00479350();
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>((((FUN_0047b560_holder*)&pickupSounds)))->LogFormIDs();
    reinterpret_cast<::FUN_00485e00_shell *>((((FUN_004855a0_shell*)this)))->FUN_00485e00();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00535aa0_Class *>(&(data))->FUN_00535aa0();
    ::AppendChunk(0x4d414e44, &data, sizeof(data));
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00535aa0_Class *>(&(data))->FUN_00535aa0();
    ::FUN_00485910(0x4d414e42, m_bUsesSoundList ? 1 : 0);
    if (!m_bUsesSoundList)
    {
        if (m_pSoundSourceArmor)
        {
            unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((RefObj*)m_pSoundSourceArmor)))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e54, formID);
        }
    }
    else if (m_pPickupPutdownSoundList)
    {
        FoleyNode* node = (FoleyNode*)m_pPickupPutdownSoundList;
        while (node && ((::SoundDescriptor *)(new ((void *)(node)) ::Vec3())))
        {
            SoundDescriptor* sound = ((::SoundDescriptor *)(new ((void *)(node)) ::Vec3()));
            node = ((::FoleyNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            if (sound && sound->SoundAssetTmp)
            {
                FUN_00513d60 saved;
                saved.formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((RefObj*)sound->SoundAssetTmp)))->FUN_0084e3a0()));
                saved.soundType = sound->layoutPadding4[0];
                saved.value = sound->eType;
                if (((bool)(::FUN_00401500())))
                    reinterpret_cast<::TESForm *>(&(saved))->ClearData();
                ::AppendChunk(0x4d414e53, &saved, sizeof(saved));
                if (((bool)(::FUN_00401500())))
                    reinterpret_cast<::TESForm *>(&(saved))->ClearData();
            }
        }
    }
    reinterpret_cast<::Holder *>((((FUN_004855a0_shell*)this)))->FUN_00485680();
}

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct ArmorCopy : TESObjectARMO
{
    void CopyArmorData(TESForm* form);
};
// @fnv 0x00513fa0
void ArmorCopy::CopyArmorData(TESForm* form)
{
    TESObjectARMO* source3 = dynamic_cast<TESObjectARMO*>(form);
    BSSimpleList<SoundDescriptor*>* node_;
    BSSimpleList<SoundDescriptor*>* iter;
    SoundDescriptor* original9;
    SoundDescriptor* copy7;
    SoundDescriptor* sound;
    if (!source3)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(form);
    data = source3->data;
    if (m_bUsesSoundList && m_pPickupPutdownSoundList)
    {
        node_ = m_pPickupPutdownSoundList;
        while (node_ && ((::SoundDescriptor *)(new ((void *)(node_)) ::Vec3())))
        {
            sound = ((::SoundDescriptor *)(new ((void *)(node_)) ::Vec3()));
            ::FUN_00401030(sound);
            node_ = ((::BSSimpleList< ::SoundDescriptor *> *)(reinterpret_cast<::Callees *>((node_))->FUN_00726070()));
        }
        reinterpret_cast<::FileMatchList *>((m_pPickupPutdownSoundList))->RemoveAll();
        delete m_pPickupPutdownSoundList;
    }
    m_bUsesSoundList = source3->m_bUsesSoundList;
    if (!m_bUsesSoundList)
        m_pPickupPutdownSoundList = source3->m_pPickupPutdownSoundList;
    else
    {
        m_pPickupPutdownSoundList = new BSSimpleList<SoundDescriptor*>;
        if (source3->m_pPickupPutdownSoundList)
        {
            iter = source3->m_pPickupPutdownSoundList;
            while (iter && ((::SoundDescriptor *)(new ((void *)(iter)) ::Vec3())))
            {
                original9 = ((::SoundDescriptor *)(new ((void *)(iter)) ::Vec3()));
                iter = ((::BSSimpleList< ::SoundDescriptor *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
                if (original9 && original9->SoundAssetTmp)
                {
                    copy7 = new SoundDescriptor;
                    *copy7 = *original9;
                    m_pPickupPutdownSoundList->AddHead(copy7);
                }
            }
        }
    }
}


class TESObjectARMOFoley : public TESObjectARMO
{
  public:
    TESSound* GetFoleySound(int eType);
};

// Scans the armor's foley list for an entry matching eType whose random chance roll succeeds, returning its sound or null.
// @fnv 0x00512d40
TESSound* TESObjectARMOFoley::GetFoleySound(int eType)
{
    BSSimpleList<SoundDescriptor*>* pFoleyList;
    TESSound* pkSound = 0;
    SoundDescriptor* pkFoley;

    pFoleyList = m_bUsesSoundList ? m_pPickupPutdownSoundList
                                  : (m_pSoundSourceArmor ? m_pSoundSourceArmor->m_pPickupPutdownSoundList : 0);
    while (pFoleyList && !pFoleyList->IsEmpty() && !pkSound)
    {
        pkFoley = ((::SoundDescriptor *)(new ((void *)(pFoleyList)) ::Vec3()));
        pFoleyList = ((::BSSimpleList< ::SoundDescriptor *> *)(reinterpret_cast<::Callees *>((pFoleyList))->FUN_00726070()));
        if (pkFoley->SoundAssetTmp && pkFoley->eType == eType && (int)(DialogueRandom() & 0x63) < pkFoley->layoutPadding4[0])
            pkSound = pkFoley->SoundAssetTmp;
    }
    return pkSound;
}

struct FUN_00512ba0 : TESObjectARMO
{
    virtual ~FUN_00512ba0();
};
// @fnv 0x00512ba0
FUN_00512ba0::~FUN_00512ba0()
{}

#include <string.h>
struct ArmorCompare : TESObjectARMO
{
    bool IsDifferentFrom(TESForm* form);
};
// Returns true if form is not an armor or differs in base compare, data, sound source armor, or pickup/putdown sound list entries.
// @fnv 0x00514220
bool ArmorCompare::IsDifferentFrom(TESForm* form)
{
    TESObjectARMO* pOther = dynamic_cast<TESObjectARMO*>(form);
    if (!pOther)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(pOther)))
        return true;
    if (memcmp(&data, &pOther->data, 12))
        return true;
    if (m_bUsesSoundList != pOther->m_bUsesSoundList)
        return true;
    if (!m_bUsesSoundList)
    {
        if (m_pSoundSourceArmor != pOther->m_pSoundSourceArmor)
            return true;
    }
    else
    {
        if (pOther->m_pPickupPutdownSoundList && m_pPickupPutdownSoundList &&
            ((::SoundDescriptor *)(new ((void *)(pOther->m_pPickupPutdownSoundList)) ::Vec3())) == ((::SoundDescriptor *)(new ((void *)(m_pPickupPutdownSoundList)) ::Vec3())))
        {
            BSSimpleList<SoundDescriptor*>* pCurrent = m_pPickupPutdownSoundList;
            while (pCurrent && ((::SoundDescriptor *)(new ((void *)(pCurrent)) ::Vec3())))
            {
                bool bFound = false;
                BSSimpleList<SoundDescriptor*>* search = pOther->m_pPickupPutdownSoundList;
                while (search && ((::SoundDescriptor *)(new ((void *)(search)) ::Vec3())))
                {
                    if (((::SoundDescriptor *)(new ((void *)(pCurrent)) ::Vec3()))->SoundAssetTmp == ((::SoundDescriptor *)(new ((void *)(search)) ::Vec3()))->SoundAssetTmp &&
                        ((::SoundDescriptor *)(new ((void *)(pCurrent)) ::Vec3()))->layoutPadding4[0] == ((::SoundDescriptor *)(new ((void *)(search)) ::Vec3()))->layoutPadding4[0] &&
                        ((::SoundDescriptor *)(new ((void *)(pCurrent)) ::Vec3()))->eType == ((::SoundDescriptor *)(new ((void *)(search)) ::Vec3()))->eType)
                    {
                        bFound = true;
                        break;
                    }
                    search = ((::BSSimpleList< ::SoundDescriptor *> *)(reinterpret_cast<::Callees *>((search))->FUN_00726070()));
                }
                if (!bFound)
                    return true;
                pCurrent = ((::BSSimpleList< ::SoundDescriptor *> *)(reinterpret_cast<::Callees *>((pCurrent))->FUN_00726070()));
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}
