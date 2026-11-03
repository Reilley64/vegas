// fallout_shared/tescaravan.cpp: TESCaravanCard, TESCaravanMoney, TESCaravanDeck, Holder and more (32 functions)

#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BSMultiBoundRoom.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047b560__FUN_0047b560_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "fnv/symbols_0118c000.h"
#include "tescaravan_decls.h"
class RegionDataEntry
{
  public:
};

class BGSImpactData
{
  public:
};

extern "C" void* memset(void* dst, int val, unsigned int size);

// @fnv 0x0059a370
TESCaravanCard::TESCaravanCard()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(0x73))));
    ResetFormData();
}

// @fnv 0x0059a670
void TESCaravanCard::ResetFormData()
{
    m_kFrontTexture.Init();
    m_kBackTexture.Init();
    memset(&data, 0, sizeof(data));
}

// @fnv 0x0059a6c0
void TESCaravanCard::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;
    TESModelTextureSwap::InitItem(this);
    TESScriptableForm::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// Initializes both entries of the array by calling Init on each.
// @fnv 0x0059b120
void TESCaravanMoney::ResetFormData()
{
    m_kModelTextureSwaps[0].Init();
    m_kModelTextureSwaps[1].Init();
}

// @fnv 0x0059b160
void TESCaravanMoney::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;
    TESModelTextureSwap::InitItem(this);
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}

// @fnv 0x0059b880
TESCaravanDeck::TESCaravanDeck()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(static_cast<ENUM_FORM_ID>(0x75))));
    ResetFormData();
}

// @fnv 0x0059b9f0
void TESCaravanDeck::ResetFormData()
{
    m_pCardListHeadCur = new BSSimpleList<TESCaravanCard*>();
    data.m_iValue = 0;
}

// Reads a TESCaravanDeck record from file: validates form type 0x75, loads header, then processes EDID, OBND, FULL, DATA and CARD chunks.
// @fnv 0x0059bb50
bool TESCaravanDeck::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x75)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(static_cast<TESFullName*>(this), file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(file, &data, 4);
            break;
        case 0x44524143: {
            unsigned int formID;
            file->GetChunkData(&formID);
            ::ResolveFormID((unsigned int *)&(formID), file);
            TESForm* form = ::FUN_004839c0(formID);
            TESCaravanCard* card = static_cast<TESCaravanCard*>(form);
            if (!m_pCardListHeadCur || m_pCardListHeadCur->IsEmpty())
                m_pCardListHeadCur->SetItem(card);
            else
                m_pCardListHeadCur->AddHead(card);
            break;
        }
        }
        if (chunkID == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<::fnv_00503210::Unk *>((reinterpret_cast<RegionDataEntry*>(&data)))->FUN_00503210();
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0059b290
bool TESCaravanMoney::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x74)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x4c444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            char* textureSwapData;
            unsigned int chunkSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            textureSwapData = static_cast<char*>(_alloca(chunkSize));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureSwapData), chunkSize);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(textureSwapData, chunkSize,
                                 reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((reinterpret_cast<TESFileFormVersion*>(file)))->FUN_00403570());
            break;
        }
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(static_cast<TESIcon*>(this), file);
            break;
        case 0x4f43494d:
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this), file);
            break;
        case 0x4d414e59: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::TESSound *)(reinterpret_cast<TESSound*>(id)));
            break;
        }
        case 0x4d414e5a: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            reinterpret_cast<::TESRegionGrassObject *>(this)->AssignLandTexture((::TESLandTexture *)(::TESSound *)(reinterpret_cast<TESSound*>(id)));
            break;
        }
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(file, 0, 0);
            break;
        case 0x32444f4d: {
            char* model = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(model), 0);
            m_kModelTextureSwaps[0].SetModelFilePath(model);
            ::FUN_004893e0(&m_kModelTextureSwaps[0], file);
            break;
        }
        case 0x33444f4d: {
            char* model = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(model), 0);
            m_kModelTextureSwaps[1].SetModelFilePath(model);
            ::FUN_004893e0(&m_kModelTextureSwaps[1], file);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x0059a800
bool TESCaravanCard::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    bool m_bHeaderParsed = false;
    if (formType != 0x73)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x4c444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            char* textureSwapData;
            unsigned int chunkSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            textureSwapData = static_cast<char*>(_alloca(chunkSize));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureSwapData), chunkSize);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(textureSwapData, chunkSize,
                                 reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((reinterpret_cast<TESFileFormVersion*>(file)))->FUN_00403570());
            break;
        }
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(static_cast<TESIcon*>(this), file);
            break;
        case 0x4f43494d:
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this), file);
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::Script *)(reinterpret_cast<Script*>(scriptID)));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x4d414e59: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::TESSound *)(reinterpret_cast<TESSound*>(id)));
            break;
        }
        case 0x4d414e5a: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            reinterpret_cast<::TESRegionGrassObject *>(this)->AssignLandTexture((::TESLandTexture *)(::TESSound *)(reinterpret_cast<TESSound*>(id)));
            break;
        }
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(file, 0, 0);
            break;
        case 0x30305854:
            ::TESTexture::ReadTextureData(&m_kFrontTexture, file);
            break;
        case 0x31305854:
            ::TESTexture::ReadTextureData(&m_kBackTexture, file);
            break;
        case 0x56544e49:
            if (!m_bHeaderParsed)
            {
                file->GetChunkData(&data.m_uiSecondValue);
                m_bHeaderParsed = true;
            }
            else
            {
                file->GetChunkData(&data.m_uiFirstValue);
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_00503650_shell : public TESCaravanCard
{
    TESTexture* FUN_00503650();
};

// @fnv 0x00503650
TESTexture* FUN_00503650_shell::FUN_00503650()
{
    return &this->m_kBackTexture;
}

struct FUN_0059adf0 : public TESForm
{
    void LoadGame(void* arg);
};

// @fnv 0x0059adf0
void FUN_0059adf0::LoadGame(void* arg)
{
    TESForm::LoadGame(arg);
}

struct FUN_0059b270_shell
{
    char* FUN_0059b270(int index);
};

// @fnv 0x0059b270
char* FUN_0059b270_shell::FUN_0059b270(int index)
{
    return &((char*)this)[index * 32 + 140];
}

struct List_009e03e0
{
};

struct FUN_0059b9c0_shell
{
    char pad1[0x24];
    List_009e03e0* m_pCardListHeadCur;
    unsigned int data;
    void ClearListAndData();
};

// Calls RemoveAll on the list and zeroes the 4-byte data field.
// @fnv 0x0059b9c0
void FUN_0059b9c0_shell::ClearListAndData()
{
    reinterpret_cast<::FileMatchList *>((m_pCardListHeadCur))->RemoveAll();
    memset(&data, 0, 4);
}

namespace fnv_0059b1b0 {
struct FUN_0048e370_shell
{
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(int);
};
struct FUN_0047b560_shell
{
};
struct FUN_004855a0
{
    void M();
};
struct FUN_00485680
{
    void M();
};
struct S_00487010
{
};
struct S_0048a520
{
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct FUN_0059b270_shell
{
};
struct FUN_0059b1b0_shell
{
    void FUN_0059b1b0();
};

// @fnv 0x0059b1b0
void FUN_0059b1b0_shell::FUN_0059b1b0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)((char*)this + 0x30))))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)((char*)this + 0x3c))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_shell*)((char*)this + 0x5c))))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x68))->FUN_0047a240(0x4f43494d);
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>((((FUN_0047b560_shell*)((char*)this + 0x80))))->LogFormIDs();
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)reinterpret_cast<::FUN_0059b270_shell *>((((FUN_0059b270_shell*)this)))->FUN_0059b270(0))))->ProcessAndFreeData(0x32444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)reinterpret_cast<::FUN_0059b270_shell *>((((FUN_0059b270_shell*)this)))->FUN_0059b270(1))))->ProcessAndFreeData(0x33444f4d, 0x54444f4d, 0x53444f4d);
    ((FUN_00485680*)this)->M();
}
}  // namespace fnv_0059b1b0

struct Holder
{
    void FUN_0059a4f0();
    void* Release(unsigned int flags);
public:
    void FUN_00485680();
};
struct FUN_004855a0
{
    void M();
};
struct S_00487010
{
};
struct S_0048a520
{
};
struct FUN_0048e370_obj
{
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_0047b560_holder
{
};
struct FUN_0050d100_shell
{
    void* FUN_0050d100();
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct FUN_00485680
{
    void M();
};

class TESDataHandler
{
  public:
};

class FUN_0059a720_shell
{
  public:
    void Initialize();
};

// @fnv 0x0059a720
void FUN_0059a720_shell::Initialize()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)((char*)this + 0x30))))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)((char*)this + 0x3c))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_obj*)((char*)this + 0x5c))))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x68))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x80))->FUN_0048cca0();
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>((((FUN_0047b560_holder*)((char*)this + 0x8c))))->LogFormIDs();
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_obj*)((FUN_0050d100_shell*)this)->FUN_0050d100())))->FUN_0048e370(0x30305854);
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_obj*)((void *)(reinterpret_cast<::FUN_00503650_shell *>((((TESDataHandler*)this)))->FUN_00503650())))))->FUN_0048e370(0x31305854);
    ::FUN_00485910(0x56544e49, *(unsigned int*)((char*)this + 0xb8));
    ::FUN_00485910(0x56544e49, *(unsigned int*)((char*)this + 0xb4));
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct FUN_00484d60_holder
{
};
struct FUN_0059add0_shell : public FUN_00484d60_holder
{
    void ForwardToBase(unsigned int a);
};
// @fnv 0x0059add0
void FUN_0059add0_shell::ForwardToBase(unsigned int a)
{
    reinterpret_cast<::FakeForm *>(this)->SaveIfChanged((::BGSSaveFormBuffer *)(a));
}

struct Place_0059af90
{
    void FUN_0059afc0();
    void* FUN_0059af90(unsigned int);
};
struct FakeVTable_59b0e0
{
    virtual void F0();
    virtual void F1();
};
struct FUN_0059b0e0_shell : TESCaravanMoney
{
    void FUN_0059b0e0();
};
// @fnv 0x0059b0e0
void FUN_0059b0e0_shell::FUN_0059b0e0()
{
    reinterpret_cast<FakeVTable_59b0e0*>(&m_kModelTextureSwaps[0])->F1();
    reinterpret_cast<FakeVTable_59b0e0*>(&m_kModelTextureSwaps[1])->F1();
}

struct FUN_0059b910_shell
{
    void FUN_0059b940();
    void* FUN_0059b910(unsigned int);
};
namespace fnv_0059ba80 {
struct FUN_004855a0
{
    void M();
};
struct S_00487010
{
};
struct BSThread
{
};
struct BipedModelForm
{
};
struct FUN_00485e00_shell
{
    void FUN_00485e20(int, int);
};
struct FUN_00485680
{
    void M();
};

struct FUN_0059ba80_shell : public FUN_004855a0
{
    BSSimpleList<TESCaravanCard*>* m_pCardListHeadCur;
    BipedModelForm data;
    void FUN_00485e20(int, int);
    void M();
    void FUN_0059ba80();
};

// @fnv 0x0059ba80
void FUN_0059ba80_shell::FUN_0059ba80()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)((char*)this + 0x18))))->FUN_00487010();
    BSSimpleList<TESCaravanCard*>* current = (BSSimpleList<TESCaravanCard*>*)reinterpret_cast<::ActorMover *>((((BSThread*)this)))->GetCurrentMoveModeType();
    while (current && ((::TESCaravanCard *)(new ((void *)(current)) ::Vec3())))
    {
        ::FUN_00485910(0x44524143, ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::TESCaravanCard *)(new ((void *)(current)) ::Vec3()))))->FUN_0084e3a0())));
        current = ((::BSSimpleList< ::TESCaravanCard *> *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
    }
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>((((BipedModelForm*)((char*)this + 0x28))))->FUN_00503210();
    reinterpret_cast<::SDSaveForm *>(this)->FUN_00485e20((const void *)((int)((char*)this + 0x28)), 4);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::fnv_00503210::Unk *>((((BipedModelForm*)((char*)this + 0x28))))->FUN_00503210();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}
}  // namespace fnv_0059ba80

struct FakeTexture0059
{
    virtual void Unk0();
    virtual void Unk1();
    int field4;
    int field8;
};
struct CardOwner0059
{
    char _pad[0x9c];
    FakeTexture0059 m_kFrontTexture;
    FakeTexture0059 m_kBackTexture;
    char data[8];
    void FUN_0059a620();
};
// Calls Unk1 on both FakeTexture0059 members and clears the 8-byte data buffer.
// @fnv 0x0059a620
void CardOwner0059::FUN_0059a620()
{
    m_kFrontTexture.Unk1();
    m_kBackTexture.Unk1();
    memset(data, 0, 8);
}

struct CMBoundObject
{
    virtual ~CMBoundObject();
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
};
struct CMFullName
{
    virtual ~CMFullName();
    int unk04;
    int unk08;
};
struct CMModelTextureSwap
{
    virtual ~CMModelTextureSwap();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct CMIcon
{
    virtual ~CMIcon();
    int unk04;
    int unk08;
};
struct CMMessageIcon
{
    virtual ~CMMessageIcon();
    int unk04;
    int unk08;
    int unk0c;
};
struct CMValueForm
{
    virtual ~CMValueForm();
    int unk04;
};
struct CMPickupPutdownSounds
{
    virtual ~CMPickupPutdownSounds();
    int unk04;
    int unk08;
};

struct FUN_0059afc0 : public CMBoundObject,
                      public CMFullName,
                      public CMModelTextureSwap,
                      public CMIcon,
                      public CMMessageIcon,
                      public CMValueForm,
                      public CMPickupPutdownSounds
{
    CMModelTextureSwap m_kModelTextureSwaps[2];
    virtual ~FUN_0059afc0();
};
// Calls FUN_0059afc0, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0059af90
void* Place_0059af90::FUN_0059af90(unsigned int flags)
{
    reinterpret_cast<::FUN_0059afc0 *>(this)->FUN_0059afc0::~FUN_0059afc0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0059afc0
FUN_0059afc0::~FUN_0059afc0()
{
    reinterpret_cast<::FUN_0059b0e0_shell *>(this)->FUN_0059b0e0();
}

namespace fnv_0059b680 {
extern "C"
{
    extern char DAT_0118c5e4[];
    extern char DAT_01183028[];
}

void* __cdecl FUN_00ec43fb(unsigned int, unsigned int, unsigned int, unsigned int, int);

struct FUN_0059b680_sub
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
    virtual void V6(void* arg);
};

struct FUN_0059b270_shell
{
};

struct FUN_00401170_shell
{
    void* FUN_00401170();
};

struct FUN_0059b680_base
{
};

class FUN_0059b680_cls : public FUN_0059b680_base
{
  public:
    char unk00[0x8c];
    FUN_0059b680_sub m_8c;
    char unk90[0x1c];
    FUN_0059b680_sub m_ac;

    void FUN_0059b680(int a1);
};

// @fnv 0x0059b680
void FUN_0059b680_cls::FUN_0059b680(int a1)
{
    void* p = FUN_00ec43fb(a1, 0, (unsigned int)DAT_01183028, (unsigned int)DAT_0118c5e4, 0);
    if (p == 0)
    {
    }
    else
    {
        reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(p);
        m_8c.V6(((FUN_0059b680_sub*)reinterpret_cast<::FUN_0059b270_shell *>((((FUN_0059b270_shell*)p)))->FUN_0059b270(0))->V5());
        m_ac.V6(((FUN_0059b680_sub*)reinterpret_cast<::FUN_0059b270_shell *>((((FUN_0059b270_shell*)p)))->FUN_0059b270(1))->V5());
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((int)(((FUN_00401170_shell*)a1)->FUN_00401170()));
    }
}
}  // namespace fnv_0059b680

struct BaseDtor_b5117
{
    virtual void unk00();
    ~BaseDtor_b5117();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct SecondDtor_b5117
{
    virtual void unk00();
    ~SecondDtor_b5117();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct FUN_0059b940 : BaseDtor_b5117, SecondDtor_b5117
{
    virtual void unk08();
    void unk0C();
    ~FUN_0059b940();
};
// Calls FUN_0059b940, then frees this object with _Deallocate when bit 0 of flags is set, and returns this.
// @fnv 0x0059b910
void* FUN_0059b910_shell::FUN_0059b910(unsigned int flags)
{
    reinterpret_cast<::FUN_0059b940 *>(this)->FUN_0059b940::~FUN_0059b940();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0059b940
FUN_0059b940::~FUN_0059b940()
{
    reinterpret_cast<::FUN_0059b9c0_shell *>(this)->ClearListAndData();
}

extern const char DAT_01183028[];
extern const char DAT_0118643c[];

struct Itc
{
};

struct DeckData
{
    int x;
};

struct L1c
{
    unsigned int FUN_00401170();
};

struct P24c
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
    void FUN_00726c60(void*& v);
    void FUN_005ae3d0(void*& v);
};

struct FUN_0059bd50_cls
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
    P24c* p24;
    DeckData f28;
    void LoadDeckData(void* arg);
};

L1c* __cdecl FUN_00ec43fb(void* arg, int a2, const char* a3, const char* a4, int a5);

// @fnv 0x0059bd50
void FUN_0059bd50_cls::LoadDeckData(void* arg)
{
    L1c* rec = FUN_00ec43fb(arg, 0, DAT_01183028, DAT_0118643c, 0);
    if (rec == 0)
    {
    }
    else
    {
        reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(rec);
        while (p24 != 0 && !p24->FUN_008256d0())
            p24->FUN_0063f7b0();
        Itc* it = ((::Itc *)(reinterpret_cast<::ActorMover *>((rec))->GetCurrentMoveModeType()));
        while (it != 0 && *((void **)(new ((void *)(it)) ::Vec3())) != 0)
        {
            void* v = *((void **)(new ((void *)(it)) ::Vec3()));
            if (p24 == 0 || p24->FUN_008256d0())
                p24->FUN_00726c60(v);
            else
                p24->FUN_005ae3d0(v);
            it = ((::Itc *)(reinterpret_cast<::Callees *>((it))->FUN_00726070()));
        }
        f28 = *((::DeckData *)(reinterpret_cast<::FUN_004610d0_shell *>((rec))->GetExtraDataList()));
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(rec->FUN_00401170());
    }
}

struct FUN_0059a4f0 : TESBoundObject,
                      TESFullName,
                      TESModelTextureSwap,
                      TESIcon,
                      BGSMessageIcon,
                      TESValueForm,
                      TESScriptableForm,
                      BGSPickupPutdownSounds
{
    bool bIsActive;
    TESTexture m_kFrontTexture;
    TESTexture m_kBackTexture;
    UnsignedValuePair data;
    virtual ~FUN_0059a4f0();
};
// Calls FUN_0059a4f0, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x0059a4c0
void* Holder::Release(unsigned int flags)
{
    reinterpret_cast<::FUN_0059a4f0 *>((this))->FUN_0059a4f0::~FUN_0059a4f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0059a4f0
FUN_0059a4f0::~FUN_0059a4f0()
{
    static_cast<CardOwner0059*>(static_cast<void*>(this))->FUN_0059a620();
}

namespace fnv_0059ac20 {
extern char DAT_01183028;
void* FUN_00ec43fb(void*, int, void*, void*, int);
class StrB
{
  public:
};
class StrSet
{
  public:
};
struct Pair8
{
    int a, b;
};
class SrcF
{
  public:
};
class FormA
{
  public:
    int FUN_00401170();
};
class DstF
{
  public:
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
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    StrSet s9c;
    int unka0;
    int unka4;
    StrSet sa8;
    int unkac;
    int unkb0;
    Pair8 kb4;
    void CopyFrom(FormA* pForm);
};
// @fnv 0x0059ac20
void DstF::CopyFrom(FormA* pForm)
{
    SrcF* pSrc = (SrcF*)FUN_00ec43fb(pForm, 0, &DAT_01183028, &(*reinterpret_cast<char *>(&::fnv_0059acd0::DAT_0118c5c4)), 0);
    if (!pSrc)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(pSrc);
    reinterpret_cast<::TESFullName *>(&(s9c))->SetFullName(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::fnv_0059ac20::StrB *)(reinterpret_cast<::FUN_0050d100_shell *>((pSrc))->FUN_0050d100()))))->FUN_00408da0())));
    reinterpret_cast<::TESFullName *>(&(sa8))->SetFullName(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::fnv_0059ac20::StrB *)(reinterpret_cast<::FUN_00503650_shell *>((pSrc))->FUN_00503650()))))->FUN_00408da0())));
    kb4 = *((::fnv_0059ac20::Pair8 *)(reinterpret_cast<::BSMultiBoundRoom *>((pSrc))->FUN_006ab360()));
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(pForm->FUN_00401170());
}
}  // namespace fnv_0059ac20

namespace fnv_0059acd0 {
extern "C" void* __cdecl FNV_DynamicCast(void* pObj, int vfDelta, void* pSrcType, void* pTargetType, int isRef);
extern "C" void* DAT_01183028;
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

struct StrHelper_00408da0
{
};


struct CardType_0059acd0
{
};

struct Class_0059acd0
{
    char pad00[0x9c];
    StrHelper_00408da0 unk9c;
    char padA0[0xa8 - 0x9c - sizeof(StrHelper_00408da0)];
    StrHelper_00408da0 unka8;
    char padAC[0xb4 - 0xa8 - sizeof(StrHelper_00408da0)];
    char unkb4[8];

    bool IsDifferentFromCard(void* param1);
};

// Returns true if the cast fails or either compared string or the 8-byte data differs.
// @fnv 0x0059acd0
bool Class_0059acd0::IsDifferentFromCard(void* apCard)
{
    CardType_0059acd0* card = (CardType_0059acd0*)FNV_DynamicCast(apCard, 0, &DAT_01183028, &DAT_0118c5c4, 0);
    if (!card)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((this))->FUN_00485270((::TESForm *)(card)))
        return true;
    if (::FUN_00408b20(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(this->unk9c))->FUN_00408da0())), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::fnv_0059acd0::StrHelper_00408da0 *)(reinterpret_cast<::FUN_0050d100_shell *>((card))->FUN_0050d100()))))->FUN_00408da0()))))
        return true;
    if (::FUN_00408b20(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(this->unka8))->FUN_00408da0())), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::fnv_0059acd0::StrHelper_00408da0 *)(reinterpret_cast<::FUN_00503650_shell *>((card))->FUN_00503650()))))->FUN_00408da0()))))
        return true;
    if (memcmp(this->unkb4, reinterpret_cast<::BSMultiBoundRoom *>((card))->FUN_006ab360(), 8))
        return true;
    return false;
}
}  // namespace fnv_0059acd0

#include <string.h>
struct CardListNode
{
    int FUN_005ae380();
};

struct FormCmpX
{
};

// FUN_0059bb30 / FUN_004610d0 / FUN_0059be50 are not declared on TESCaravanDeck in
// today's tree; reach them through a derived stand-in with an identical layout.
struct TESCaravanDeckX : TESCaravanDeck
{
    bool FUN_0059be50(TESForm* form);
};

// Returns true if the cast fails, FUN_00485270 returns true, card counts differ, a card from the other deck is absent here, or CaravanDeckData differs.
// @fnv 0x0059be50
bool TESCaravanDeckX::FUN_0059be50(TESForm* form)
{
    TESCaravanDeck* pDeck2 = dynamic_cast<TESCaravanDeck*>(form);
    if (!pDeck2)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FormCmpX*)this)))->FUN_00485270(pDeck2))
        return true;
    if (((::CardListNode *)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))->FUN_005ae380() != ((::CardListNode *)(reinterpret_cast<::ActorMover *>((((TESCaravanDeckX*)pDeck2)))->GetCurrentMoveModeType()))->FUN_005ae380())
        return true;
    CardListNode* pNode = ((::CardListNode *)(reinterpret_cast<::ActorMover *>((((TESCaravanDeckX*)pDeck2)))->GetCurrentMoveModeType()));
    while (pNode && ((::TESCaravanCard *)(new ((void *)(pNode)) ::Vec3())))
    {
        if (!reinterpret_cast<::RefList *>((((::CardListNode *)(reinterpret_cast<::ActorMover *>(this)->GetCurrentMoveModeType()))))->FUN_005f65d0((void **)&(((::TESCaravanCard *)(new ((void *)(pNode)) ::Vec3())))))
            return true;
        pNode = ((::CardListNode *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    if (memcmp(&data, ((::CaravanDeckData *)(reinterpret_cast<::FUN_004610d0_shell *>((((TESCaravanDeckX*)pDeck2)))->GetExtraDataList())), sizeof(CaravanDeckData)))
        return true;
    return false;
}

struct CaravanModelPathView
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual const char* GetPath();
};

struct CaravanMoneyCompare : public TESCaravanMoney
{
    bool FUN_0059b740(TESForm*);
};


// @fnv 0x0059b740
bool CaravanMoneyCompare::FUN_0059b740(TESForm* other)
{
    CaravanMoneyCompare* compared = static_cast<CaravanMoneyCompare*>(dynamic_cast<TESCaravanMoney*>(other));

    if (!compared)
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(compared))
        return true;

    if (FUN_00408b20(reinterpret_cast<CaravanModelPathView*>(&m_kModelTextureSwaps[0])->GetPath(),
                     ((::CaravanModelPathView *)(reinterpret_cast<::FUN_0059b270_shell *>((compared))->FUN_0059b270(0)))->GetPath()))
        return true;

    if (FUN_00408b20(reinterpret_cast<CaravanModelPathView*>(&m_kModelTextureSwaps[1])->GetPath(),
                     ((::CaravanModelPathView *)(reinterpret_cast<::FUN_0059b270_shell *>((compared))->FUN_0059b270(1)))->GetPath()))
        return true;

    return false;
}
