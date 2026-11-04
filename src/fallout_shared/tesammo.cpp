// fallout_shared/tesammo.cpp: TESAmmo, AmmoMethods, AmmoSave (18 functions)

#include <new>
#include "fnv/decl/AmmoEffectDesc.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_0047a240_shell.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_0048ea80_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00501c90_shell.h"
#include "fnv/decl/FUN_00503650_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_0048cca0.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047b560__FUN_0047b560_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_0048e9b0__TESValueForm.h"
#include "fnv/decl/fnv_0048e9e0__TESValueForm.h"
#include "fnv/decl/fnv_0048ea10__TESValueForm.h"
#include "fnv/decl/fnv_0048ea40__TESValueForm.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_0097a000.h"
#include "fnv/symbols_00984000.h"
#include "tesammo_load.h"
#include <malloc.h>
#include <string.h>
#include "fnv/symbols_00472000.h"

// @fnv 0x005026b0
TESAmmo::TESAmmo()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_AMMO_ID)));
    ResetFormData();
}

// @fnv 0x005029f0
void TESAmmo::ResetFormData()
{
    memset(&data, 0, sizeof(data));
    memset(&m_kProjectileData, 0, sizeof(m_kProjectileData));
    reinterpret_cast<::TextString *>(&(m_kPrimaryString))->FUN_004037f0(0, 0);
    reinterpret_cast<::TextString *>(&(m_kSecondaryString))->FUN_004037f0(0, 0);
}

struct FUN_00502cb0_shell : public TESAmmo
{
    void FUN_00502cb0(TESForm*);
};
// Initializes the ammo's scriptable, destructible, model, pickup sound and projectile/effect forms, resolving each form ID and warning on failure.
// @fnv 0x00502a50
void TESAmmo::InitItem()
{
    struct InitItemLocals
    {
        unsigned int formID;
        void* resolved;
        BSSimpleList<TESAmmoEffect*>* node;
    } locals;

    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;

    static_cast<TESScriptableForm *>(this)->InitItem((TESForm*)this);
    static_cast<BGSDestructibleObjectForm *>(this)->InitItem((TESForm*)this);
    static_cast<TESModelTextureSwap *>(this)->InitItem((TESForm*)this);
    static_cast<BGSPickupPutdownSounds *>(this)->InitItem((TESForm*)this);

    locals.formID = ((MiddleLowProcess*)this)->GetProcessInteger();
    if (locals.formID)
    {
        ::ResolveFormID((unsigned int *)&(locals.formID), GetFile(-1));
        ((MiddleLowProcess*)this)
            ->SetProcessInteger((std::intptr_t)dynamic_cast<BGSProjectile*>(::FUN_004839c0(locals.formID)));
        if (!((MiddleLowProcess*)this)->GetProcessInteger())
        {
            ::FUN_005b5e40();
        }
    }

    locals.formID = ((unsigned int)(::GetFieldBC((::FUN_0097ae90_Class *)(((TESAmmoInitCalls*)this)))));
    if (locals.formID)
    {
        ::ResolveFormID((unsigned int *)&(locals.formID), GetFile(-1));
        reinterpret_cast<::FUN_00502cb0_shell *>((((TESAmmoInitCalls*)this)))->FUN_00502cb0((::TESForm *)(void *)(::FUN_004839c0(locals.formID)));
        if (!((unsigned int)(::GetFieldBC((::FUN_0097ae90_Class *)(((TESAmmoInitCalls*)this))))))
        {
            ::FUN_005b5e40();
        }
    }

    locals.node = (BSSimpleList<TESAmmoEffect*>*)((TESAmmoInitCalls*)this)->FUN_00923000();
    locals.resolved = 0;
    while (locals.node && (locals.node->m_item))
    {
        locals.formID = (unsigned int)(std::uintptr_t)(locals.node->m_item);
        if (locals.formID)
        {
            ::ResolveFormID((unsigned int *)&(locals.formID), GetFile(-1));
            locals.resolved = dynamic_cast<TESAmmoEffect*>(::FUN_004839c0(locals.formID));
            if (!locals.resolved)
            {
                ::FUN_005b5e40();
            }
            (locals.node->m_item) = (TESAmmoEffect*)locals.resolved;
        }
        locals.node = ((::BSSimpleList< ::TESAmmoEffect *> *)(reinterpret_cast<::Callees *>((locals.node))->FUN_00726070()));
    }

    SetInitializationState(true);
}

// @fnv 0x00502cb0
void FUN_00502cb0_shell::FUN_00502cb0(TESForm* apAmmoConsumed)
{
    this->m_kProjectileData.m_pShellCasing = apAmmoConsumed;
}

template <int N> struct EndianSizeTag
{
};


struct FUN_00503240_shell
{
    void SwapEndianFields();
};
// @fnv 0x00502cd0
bool TESAmmo::Load(TESFile* file)
{
    unsigned char type = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (type != 41)
        return false;
    reinterpret_cast<::FileMatchList *>((((BSSimpleList<ActorCause*>*)((TESAmmoInitCalls*)this)->FUN_00923000())))->RemoveAll();
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunk;
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* pEditorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEditorID), 512);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            struct SwapLocals
            {
                unsigned int size;
                void* swap;
            } TextureChunk;
            TextureChunk.size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            TextureChunk.swap = _alloca(TextureChunk.size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(TextureChunk.swap), TextureChunk.size);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(TextureChunk.swap, TextureChunk.size, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((((TESFileFormVersion*)file)))->FUN_00403570());
            break;
        }
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(this, file);
            break;
        case 0x4f43494d:
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this), file);
            break;
        case 0x49524353: {
            unsigned int script = 0;
            file->GetChunkData(&script);
            ((CombatProcedure*)static_cast<TESScriptableForm *>(this))->Initialize((CombatController*)(std::uintptr_t)script);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            ::FUN_004781e0(this, file);
            break;
        case 0x4d414e59: {
            unsigned int pickup = 0;
            file->GetChunkData(&pickup);
            ((CombatProcedure*)static_cast<BGSPickupPutdownSounds *>(this))->Initialize((CombatController*)(std::uintptr_t)pickup);
            break;
        }
        case 0x4d414e5a: {
            unsigned int putdown = 0;
            file->GetChunkData(&putdown);
            ((TESRegionGrassObject*)static_cast<BGSPickupPutdownSounds *>(this))->AssignLandTexture((TESLandTexture*)(std::uintptr_t)putdown);
            break;
        }
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((BGSImpactData*)this)))->FUN_004861f0(file, &data, 8);
            break;
        case 0x32544144:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&m_kProjectileData), 20);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00503240_shell *>((((TESAmmoNVEndian*)&m_kProjectileData)))->SwapEndianFields();
            break;
        case 0x4d414e4f: {
            char* pDescription = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pDescription), 0);
            reinterpret_cast<::TextString *>(&(m_kPrimaryString))->FUN_004037f0(pDescription, 0);
            break;
        }
        case 0x4d414e51: {
            char* pAbbreviation = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pAbbreviation), 0);
            reinterpret_cast<::TextString *>(&(m_kSecondaryString))->FUN_004037f0(pAbbreviation, 0);
            break;
        }
        case 0x4c494352: {
            unsigned int effect = 0;
            file->GetChunkData(&effect);
            reinterpret_cast<::Callees *>((((BSSimpleList<ScriptVariableInfo*>*)((TESAmmoInitCalls*)this)->FUN_00923000())))->FUN_00905820((void *)&(const ::ScriptVariableInfo *const &)((ScriptVariableInfo*)(std::uintptr_t)effect));
            break;
        }
        }
        if (chunk == 0x41544144 && file->IsEndianConversionRequired())
            ((EncounterZoneData*)&data)->Endian();
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Byte-swaps the 4-byte values at offsets 8 and 0x10 of this object via BSEndian.
// @fnv 0x00503240
void FUN_00503240_shell::SwapEndianFields()
{
    ::FUN_00401080(reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 8));
    ::FUN_00401080(reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x10));
}

struct FUN_00504420_shell
{
    void FUN_00504420(unsigned int aiFlags, unsigned int aiCurrentFlags);
};

// Calls FUN_00484c50 on this and FUN_0048ea10 on the object at this+0x78, passing the same two flags.
// @fnv 0x00504420
void FUN_00504420_shell::FUN_00504420(unsigned int aiFlags, unsigned int aiCurrentFlags)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>(this)->FUN_00484c50(aiFlags, aiCurrentFlags);
    reinterpret_cast<::fnv_0048ea10::TESValueForm *>((((FUN_00504420_shell*)((char*)this + 0x78))))->FUN_0048ea10(aiFlags, aiCurrentFlags);
}

struct FUN_00504450_shell
{
    void FUN_00504450(std::uintptr_t);
};

struct FUN_00484d60_holder
{
};

struct FUN_0048ea40_holder
{
};

// Forwards aiFlags to the method at offset 0 and to the method at offset 0x78 of this object.
// @fnv 0x00504450
void FUN_00504450_shell::FUN_00504450(std::uintptr_t aiFlags)
{
    reinterpret_cast<::FakeForm *>((reinterpret_cast<FUN_00484d60_holder*>(this)))->SaveIfChanged((::BGSSaveFormBuffer *)(aiFlags));
    reinterpret_cast<::fnv_0048ea40::TESValueForm *>((reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x78)))->FUN_0048ea40((::fnv_0048ea40::BGSSaveFormBuffer *)(aiFlags));
}

struct BGSLoadFormBuffer;
struct TESValueFormLoadGame
{
};

struct FUN_00503a40_shell : TESForm
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

// @fnv 0x00503a40
void FUN_00503a40_shell::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    reinterpret_cast<::FUN_0048ea80_Class *>((((TESValueFormLoadGame*)(this) + 0x78)))->FUN_0048ea80(buffer);
}

namespace fnv_00503210 {
template <int N> struct EndianSizeTag
{
};
struct Unk
{
    void FUN_00503210();
};
// Calls BSEndian on this object to byte-swap it as a 2-byte value.
// @fnv 0x00503210
void Unk::FUN_00503210()
{
    ::FUN_00401080((int*)this);
}
}  // namespace fnv_00503210

struct FUN_00484bf0
{
    unsigned short GetSaveSize(unsigned int);
};
struct FUN_0048e9b0
{
    unsigned short GetSaveSize(unsigned int);
};
struct FUN_005039f0_class
{
    char _pad[0x78];
    FUN_0048e9b0 _o78;
    unsigned short FUN_005039f0(unsigned int);
};
// @fnv 0x005039f0
unsigned short FUN_005039f0_class::FUN_005039f0(unsigned int aiFlags)
{
    unsigned short isize;
    isize = 0;
    isize += reinterpret_cast<::FUN_00484bf0_shell *>((((FUN_00484bf0*)this)))->FUN_00484bf0(aiFlags);
    isize += reinterpret_cast<::fnv_0048e9b0::TESValueForm *>(&(_o78))->FUN_0048e9b0(aiFlags);
    return isize;
}

struct FUN_0051b070_shell
{
};
struct FUN_0059b850_shell
{
    FUN_0051b070_shell m0;
    char _pad[0x77];
    FUN_0051b070_shell m78;
    void FUN_0059b850(unsigned int);
};
// Forwards aiFlags to FUN_00484c20 on m0 and to FUN_0048e9e0 on m78.
// @fnv 0x0059b850
void FUN_0059b850_shell::FUN_0059b850(unsigned int aiFlags)
{
    reinterpret_cast<::PC7d *>(&(m0))->FUN_00484c20(aiFlags);
    reinterpret_cast<::fnv_0048e9e0::TESValueForm *>(&(m78))->FUN_0048e9e0(aiFlags);
}

// Stand-ins for TESAmmo's base components and members (destructor of TESAmmo).
struct AmmoBoundObjectPart
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
    virtual void Unk00();
    ~AmmoBoundObjectPart();
};
struct AmmoFullNamePart
{
    int unk04;
    int unk08;
    virtual void Unk00();
    ~AmmoFullNamePart();
};
struct AmmoModelTextureSwapPart
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    virtual void Unk00();
    ~AmmoModelTextureSwapPart();
};
struct AmmoIconPart
{
    int unk04;
    int unk08;
    virtual void Unk00();
    ~AmmoIconPart();
};
struct AmmoMessageIconPart
{
    int unk04;
    int unk08;
    int unk0C;
    virtual void Unk00();
    ~AmmoMessageIconPart();
};
struct AmmoValueFormPart
{
    int iValue;
    virtual void Unk00();
    ~AmmoValueFormPart();
};
struct AmmoClipRoundsPart
{
    unsigned char m_ucClipRounds;
    virtual void Unk00();
    ~AmmoClipRoundsPart();
};
struct AmmoDestructiblePart
{
    void* pData;
    virtual void Unk00();
    ~AmmoDestructiblePart();
};
struct AmmoPickupPutdownPart
{
    void* m_pPickupSound;
    void* m_pPutdownSound;
    virtual void Unk00();
    ~AmmoPickupPutdownPart();
};
struct AmmoScriptablePart
{
    void* m_pFormScript;
    bool m_bHasScript;
    virtual void Unk00();
};
struct AmmoString
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    ~AmmoString();
};
struct AmmoEffectList
{
    void* m_item;
    AmmoEffectList* m_pkNext;
    ~AmmoEffectList();
};

struct AmmoData
{
    float fSpeed;
    unsigned char cFlags;
};
struct AmmoDataNV
{
    unsigned char m_ucFlags;
    void* m_pProjectile;
    float m_fProjectileSpeed;
    void* m_pShellCasing;
    float m_fDamageMultiplier;
};

struct FUN_00502880 : AmmoBoundObjectPart,
                      AmmoFullNamePart,
                      AmmoModelTextureSwapPart,
                      AmmoIconPart,
                      AmmoMessageIconPart,
                      AmmoValueFormPart,
                      AmmoClipRoundsPart,
                      AmmoDestructiblePart,
                      AmmoPickupPutdownPart,
                      AmmoScriptablePart
{
    AmmoData data;
    AmmoDataNV m_kProjectileData;
    AmmoString m_kPrimaryString;
    AmmoString m_kSecondaryString;
    AmmoEffectList m_kEffects;
    ~FUN_00502880();
};

// Destructor for the ammo object; the body is empty and member destructors run implicitly.
// @fnv 0x00502880
FUN_00502880::~FUN_00502880()
{}

namespace fnv_00503670 {
struct AmmoEffectList : BSSimpleList<TESAmmoEffect*>
{
    unsigned int FUN_005ae380();
};
struct AmmoMethods : TESAmmo
{
    bool FUN_00503670(TESForm* form);
};
struct AmmoString
{
};
// @fnv 0x00503670
bool AmmoMethods::FUN_00503670(TESForm* form)
{
    TESAmmo* i;
    BSSimpleList<TESAmmoEffect*>* a;
    BSSimpleList<TESAmmoEffect*>* p;
    TESAmmoEffect* f;
    TESAmmoEffect* s;
    i = dynamic_cast<TESAmmo*>(form);
    if (!i)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(i)))
        return true;
    if (memcmp(&data, ((::AmmoCharacteristics *)(reinterpret_cast<::FUN_00503650_shell *>((static_cast<AmmoMethods*>(i)))->FUN_00503650())), 8))
        return true;
    if (memcmp(&m_kProjectileData, ((::AmmoProjectileData *)(::FUN_00984230((char *)(static_cast<AmmoMethods*>(i))))), 20))
        return true;
    if (reinterpret_cast<::FUN_00501c90_shell *>((reinterpret_cast<AmmoString*>(&m_kSecondaryString)))->CompareString(&i->m_kSecondaryString, true))
        return true;
    if (reinterpret_cast<::FUN_00501c90_shell *>((reinterpret_cast<AmmoString*>(&m_kPrimaryString)))->CompareString(&i->m_kPrimaryString, true))
        return true;
    if (((::fnv_00503670::AmmoEffectList *)(reinterpret_cast<::TESAmmoInitCalls *>(this)->FUN_00923000()))->FUN_005ae380() != ((::fnv_00503670::AmmoEffectList *)(reinterpret_cast<::TESAmmoInitCalls *>((static_cast<AmmoMethods*>(i)))->FUN_00923000()))->FUN_005ae380())
        return true;
    a = ((::fnv_00503670::AmmoEffectList *)(reinterpret_cast<::TESAmmoInitCalls *>(this)->FUN_00923000()));
    p = ((::fnv_00503670::AmmoEffectList *)(reinterpret_cast<::TESAmmoInitCalls *>((static_cast<AmmoMethods*>(i)))->FUN_00923000()));
    while (p && !p->IsEmpty())
    {
        if (!a || a->IsEmpty())
            return true;
        f = (a->m_item);
        s = (p->m_item);
        if (f->Compare(s))
            return true;
        p = ((::BSSimpleList< ::TESAmmoEffect *> *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
        a = ((::BSSimpleList< ::TESAmmoEffect *> *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
    }
    return false;
}
}  // namespace fnv_00503670

struct AmmoSaveCalls
{
};
struct AmmoSave
{
    TESBoundObject bound;
    TESFullName fullName;
    TESModelTextureSwap model;
    TESIcon icon;
    BGSMessageIcon messageIcon;
    TESValueForm value;
    BGSClipRoundsForm clipRounds;
    BGSDestructibleObjectForm destructible;
    BGSPickupPutdownSounds sounds;
    TESScriptableForm script;
    AmmoCharacteristics data;
    AmmoProjectileData m_kProjectileData;
    BSStringT<char> m_kPrimaryString;
    BSStringT<char> m_kSecondaryString;
    BSSimpleList<TESAmmoEffect*> m_kEffects;
    void Save();
};
// @fnv 0x00503280
void AmmoSave::Save()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<AmmoSaveCalls*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(&(reinterpret_cast<AmmoSaveCalls&>(fullName)))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>(&(reinterpret_cast<AmmoSaveCalls&>(model)))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>(&(reinterpret_cast<AmmoSaveCalls&>(icon)))->FUN_0048e370(0x4e4f4349);
    reinterpret_cast<::FUN_0047a240_shell *>(&(reinterpret_cast<AmmoSaveCalls&>(messageIcon)))->FUN_0047a240(0x4f43494d);
    reinterpret_cast<::S_0048cca0 *>(&(reinterpret_cast<AmmoSaveCalls&>(script)))->FUN_0048cca0();
    reinterpret_cast<::FUN_00477f20_shell *>(&(reinterpret_cast<AmmoSaveCalls&>(destructible)))->FUN_00477f20();
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>(&(reinterpret_cast<AmmoSaveCalls&>(sounds)))->LogFormIDs();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>(&(reinterpret_cast<AmmoSaveCalls&>(data)))->FUN_00503210();
    reinterpret_cast<::SDSaveForm *>((reinterpret_cast<AmmoSaveCalls*>(this)))->FUN_00485e20(&data, 8);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>(&(reinterpret_cast<AmmoSaveCalls&>(data)))->FUN_00503210();
    BGSProjectile* node = m_kProjectileData.m_pProjectile;
    TESForm* projectile = m_kProjectileData.m_pShellCasing;
    m_kProjectileData.m_pProjectile =
        m_kProjectileData.m_pProjectile ? reinterpret_cast<BGSProjectile*>(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_kProjectileData.m_pProjectile))->FUN_0084e3a0())))
                                        : 0;
    m_kProjectileData.m_pShellCasing = m_kProjectileData.m_pShellCasing
                                           ? reinterpret_cast<TESForm*>(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_kProjectileData.m_pShellCasing))->FUN_0084e3a0())))
                                           : 0;
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00503240_shell *>(&(reinterpret_cast<TESAmmoNVEndian&>(m_kProjectileData)))->SwapEndianFields();
    ::AppendChunk(0x32544144, &m_kProjectileData, 20);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::FUN_00503240_shell *>(&(reinterpret_cast<TESAmmoNVEndian&>(m_kProjectileData)))->SwapEndianFields();
    m_kProjectileData.m_pProjectile = node;
    m_kProjectileData.m_pShellCasing = projectile;
    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(reinterpret_cast<AmmoSaveCalls&>(m_kPrimaryString)))->FUN_004048e0())))
        ::FUN_004856f0((void *)(0x4d414e4f), (void *)(((const char *)(::FUN_00559450((int *)&(m_kPrimaryString))))),
                     (void *)(std::uintptr_t)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(reinterpret_cast<AmmoSaveCalls&>(m_kPrimaryString)))->FUN_004048e0())) + 1));
    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(reinterpret_cast<AmmoSaveCalls&>(m_kSecondaryString)))->FUN_004048e0())))
        ::FUN_004856f0((void *)(0x4d414e51), (void *)(((const char *)(::FUN_00559450((int *)&(m_kSecondaryString))))),
                     (void *)(std::uintptr_t)(((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&(reinterpret_cast<AmmoSaveCalls&>(m_kSecondaryString)))->FUN_004048e0())) + 1));
    BSSimpleList<TESAmmoEffect*>* effect =
        reinterpret_cast<BSSimpleList<TESAmmoEffect*>*>(reinterpret_cast<TESAmmoInitCalls*>(this)->FUN_00923000());
    TESAmmoEffect* consumed = 0;
    while (effect && (effect->m_item))
    {
        consumed = (effect->m_item);
        effect = ((::BSSimpleList< ::TESAmmoEffect *> *)(reinterpret_cast<::Callees *>((effect))->FUN_00726070()));
        unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((consumed))->FUN_0084e3a0()));
        ::FUN_00485910(0x4c494352, formID);
    }
    reinterpret_cast<::Holder *>((reinterpret_cast<AmmoSaveCalls*>(this)))->FUN_00485680();
}

int FNV_GetFormType(TESForm* pkForm);

struct AmmoEffectNode503
{
    TESAmmoEffect* m_item;
    AmmoEffectNode503* m_pkNext;

    void FUN_0063f7b0();
};

bool FUN_008256d0(AmmoEffectNode503* pkNode);

struct AmmoString503
{
};

struct FUN_00503510_shell : public TESAmmo
{
    void CopyFromAmmo(TESForm* pkForm);
};

// @fnv 0x00503510
void FUN_00503510_shell::CopyFromAmmo(TESForm* pkForm)
{
    FUN_00503510_shell* pSourceAmmo = (FUN_00503510_shell*)dynamic_cast<TESAmmo*>(pkForm);
    if (!pSourceAmmo)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(pkForm);
    __memcpy(&data, ((void *)(reinterpret_cast<::FUN_00503650_shell *>((pSourceAmmo))->FUN_00503650())), 8);
    __memcpy(&m_kProjectileData, FUN_00984230((char*)pSourceAmmo), 0x14);
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(FNV_GetFormType(pSourceAmmo));
    reinterpret_cast<::TextString *>(&(m_kPrimaryString))->FUN_004037f0(((const char *)(::FUN_00559450((int *)(((AmmoString503*)&pSourceAmmo->m_kPrimaryString))))), 0);
    reinterpret_cast<::TextString *>(&(m_kSecondaryString))->FUN_004037f0(((const char *)(::FUN_00559450((int *)(((AmmoString503*)&pSourceAmmo->m_kSecondaryString))))), 0);
    while (!FUN_008256d0(((::AmmoEffectNode503 *)(reinterpret_cast<::TESAmmoInitCalls *>(this)->FUN_00923000()))))
        ((::AmmoEffectNode503 *)(reinterpret_cast<::TESAmmoInitCalls *>(this)->FUN_00923000()))->FUN_0063f7b0();
    AmmoEffectNode503* pkNodeCur = ((::AmmoEffectNode503 *)(reinterpret_cast<::TESAmmoInitCalls *>((pSourceAmmo))->FUN_00923000()));
    while (pkNodeCur && !FUN_008256d0(pkNodeCur))
    {
        TESAmmoEffect* pkEffect = ((::TESAmmoEffect *)((void *)(pkNodeCur)));
        reinterpret_cast<::Callees *>((((::AmmoEffectNode503 *)(reinterpret_cast<::TESAmmoInitCalls *>(this)->FUN_00923000()))))->FUN_00905820((void *)&(pkEffect));
        pkNodeCur = ((::AmmoEffectNode503 *)(reinterpret_cast<::Callees *>((pkNodeCur))->FUN_00726070()));
    }
}

namespace fnv_00503a70 {
template <class T> unsigned int BSStringLength(const T* pString);
int __cdecl FUN_00406d50(char* pcDest, unsigned int uiSize, const char* pcSrc);

struct AmmoEffect503
{
};

struct AmmoEffectNode503
{
};

struct AmmoEffectList503 : public TESAmmoInitCalls
{
    void FUN_00503a70(char* pcBuffer, unsigned int uiSize);
};

// @fnv 0x00503a70
void AmmoEffectList503::FUN_00503a70(char* pcOutBuffer, unsigned int uiBufferSize)
{
    bool bAppended = false;
    pcOutBuffer[0] = 0;
    char acName[256];
    acName[0] = 0;

    AmmoEffectNode503* pkNode = (AmmoEffectNode503*)FUN_00923000();
    while (pkNode && *((::fnv_00503a70::AmmoEffect503 **)((void *)(pkNode))))
    {
        reinterpret_cast<::AmmoEffectDesc *>(((*((::fnv_00503a70::AmmoEffect503 **)((void *)(pkNode))))))->FormatDescription(acName, 0x100);
        AmmoEffect503* pkEffect = *((::fnv_00503a70::AmmoEffect503 **)((void *)(pkNode)));
        pkNode = ((::fnv_00503a70::AmmoEffectNode503 *)(reinterpret_cast<::Callees *>((pkNode))->FUN_00726070()));
        reinterpret_cast<::AmmoEffectDesc *>((pkEffect))->FormatDescription(acName, 0x100);
        if (::FUN_0044a670(acName) > 0)
        {
            if (bAppended)
            {
                FUN_00406d50(pcOutBuffer, uiBufferSize, "\n");
                FUN_00406d50(pcOutBuffer, uiBufferSize, acName);
            }
            else
            {
                FUN_00406d50(pcOutBuffer, uiBufferSize, acName);
                bAppended = true;
            }
        }
    }
}
}  // namespace fnv_00503a70

struct FUN_00502850
{
    virtual ~FUN_00502850();
};
// @fnv 0x00502850
FUN_00502850::~FUN_00502850()
{}

// The claimed function is a compiler-generated this-adjusting thunk:
//     sub ecx, 0x3c
//     jmp  <the most derived class' implementation of the virtual>
// MSVC emits it for the second copy of a duplicated common base: the most
// derived class inherits the same common base twice, so the vtable slot of
// the second copy has to move `this` back onto the first copy.
class ThunkCommonBase
{
  public:
    virtual void FUN_00503bb0();
};

class ThunkPrimaryBase : public ThunkCommonBase
{
  public:
    int m_pad01[14];
};

class ThunkSecondaryBase : public ThunkCommonBase
{
  public:
};

class ThunkDerived : public ThunkPrimaryBase, public ThunkSecondaryBase
{
  public:
// @fnv 0x00503bb0
    virtual void FUN_00503bb0();
    ThunkDerived();
};

ThunkDerived::ThunkDerived()
{}

ThunkDerived g_thunkDerived;
