// fallout_shared/tesobjectcont.cpp: TESObjectCONT (9 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSExplosion.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008cc6d0_class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/S_0048cca0.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004817f0__FUN_004817f0_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "tesobjectcont_decls.h"
#include "tesobjectcont_types_TESObjectCONT.h"
#include "tesobjectcont_match_decls.h"
#include <new>
#include <string.h>
#include "fnv/symbols_00472000.h"

// @fnv 0x00516330
void TESObjectCONT::ResetFormData()
{
    Data.m_cValue = 0;
    m_pOpenSound = 0;
    m_pSecondarySound = 0;
    pLoopingSound = 0;
}

// @fnv 0x005160f0
TESObjectCONT::TESObjectCONT()
{
    *reinterpret_cast<void**>(this) = &kVtbl_TESObjectCONT;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x30) = &DAT_0102ae9c;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x3C) = &DAT_0102ae88;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x48) = &DAT_0102ae64;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x68) = &DAT_0102ae50;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x74) = &DAT_0102ae3c;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x7C) = &DAT_0102ae28;
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(this) + 0x84) = &DAT_0102ae18;
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x1B)));
    ResetFormData();
}

// @fnv 0x00516370
void TESObjectCONT::InitItem()
{
    unsigned int soundFormID;

    if (TESForm::GetInitialized())
        return;

    reinterpret_cast<::TESScriptableForm *>((reinterpret_cast<TESObjectCONT_TESScriptableInitCall*>(static_cast<TESScriptableForm *>(this))))->InitItem(this);
    static_cast<TESContainer *>(this)->InitItem(this);
    static_cast<BGSDestructibleObjectForm *>(this)->InitItem(this);
    static_cast<TESModelTextureSwap *>(this)->InitItem(this);

    soundFormID = (unsigned int)m_pOpenSound;
    if (soundFormID != 0)
    {
        ::ResolveFormID((unsigned int *)&(soundFormID), GetFile(-1));
        m_pOpenSound = dynamic_cast<TESSound*>(::FUN_004839c0(soundFormID));
        if (!m_pOpenSound)
            ::FUN_005b5e40();
    }

    soundFormID = (unsigned int)m_pSecondarySound;
    if (soundFormID != 0)
    {
        ::ResolveFormID((unsigned int *)&(soundFormID), GetFile(-1));
        m_pSecondarySound = dynamic_cast<TESSound*>(::FUN_004839c0(soundFormID));
        if (!m_pSecondarySound)
            ::FUN_005b5e40();
    }

    soundFormID = (unsigned int)pLoopingSound;
    if (soundFormID != 0)
    {
        ::ResolveFormID((unsigned int *)&(soundFormID), GetFile(-1));
        pLoopingSound = dynamic_cast<TESSound*>(::FUN_004839c0(soundFormID));
        if (!pLoopingSound)
            ::FUN_005b5e40();
    }

    SetInitializationState(true);
}

// Reads a TESObjectCONT record: checks the form type, loads the record header, then dispatches each chunk to its loader until the chunk list ends.
// @fnv 0x00516580
bool TESObjectCONT::Load(TESFile* file)
{
    unsigned char formType;
    int chunkID;

    formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x1B)
        return false;

    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);

    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorIDData = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorIDData), 0x200);
            SetEditorID_AtRuntime(editorIDData);
            break;
        }

        case 0x444E424F:
            readOBNDSubRecord(file);
            break;

        case 0x4C4C5546:
            ::ReadFullName(
                this ? static_cast<TESFullName *>(this) : 0, file);
            break;

        case 0x4C444F4D:
        case 0x44444F4D:
        case 0x44534F4D:
        case 0x54444F4D:
            TESModel::LoadModelData(
                this ? static_cast<TESModel *>(this) : 0, file);
            break;

        case 0x53444F4D: {
            unsigned int textureSwapSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            char* textureSwapData = (char*)_alloca(textureSwapSize);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureSwapData), textureSwapSize);
            reinterpret_cast<::FUN_0048a7b0_shell *>((static_cast<TESModelTextureSwap *>(this)))->LoadTextureSwapList(textureSwapData, textureSwapSize,
                                       reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((reinterpret_cast<TESFileFormVersion*>(file)))->FUN_00403570());
            break;
        }

        case 0x49524353: {
            unsigned int scriptFormID = 0;
            file->GetChunkData(&scriptFormID);
            reinterpret_cast<CombatProcedure*>(static_cast<TESScriptableForm *>(this))
                ->Initialize(reinterpret_cast<CombatController*>(scriptFormID));
            reinterpret_cast<::TESScriptableForm *>((reinterpret_cast<TESObjectCONT_TESScriptableInitCall*>(static_cast<TESScriptableForm *>(this))))->InitItem(this);
            break;
        }

        case 0x44454F43:
        case 0x4F544E43: {
            switch (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
            {
            case 0x4F544E43: {
                CNTOChunkData cntoItem;
                memset(&cntoItem, 0, 8);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&cntoItem), 8);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::S_00462230 *>(&(cntoItem))->FUN_00462230();
                DAT_011c9348 = reinterpret_cast<ContainerItemExtraOwner*>(
                    ((void *)(reinterpret_cast<::fnv_004817f0::FUN_004817f0_shell *>((static_cast<TESContainer *>(this)))->AddContainerObject((::fnv_004817f0::ContainerChanges *)(void *)(&cntoItem)))));
                break;
            }
            case 0x44454F43:
                if (DAT_011c9348)
                {
                    DAT_011c9348->item = new ContainerItemExtra;
                    DAT_011c9348->item->Load(file);
                    DAT_011c9348 = 0;
                }
                break;
            }
            break;
        }

        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &Data, 1);
            break;

        case 0x44545344:
        case 0x54534544:
            ::FUN_004781e0(
                this ? static_cast<BGSDestructibleObjectForm *>(this) : 0,
                file);
            break;

        case 0x4D414E53: {
            unsigned int snamFormID = 0;
            file->GetChunkData(&snamFormID);
            reinterpret_cast<::FUN_008cc6d0_class *>((reinterpret_cast<EffectSetting*>(this)))->FUN_008cc6d0((std::intptr_t)(reinterpret_cast<TESSound*>(snamFormID)));
            break;
        }

        case 0x4D414E51: {
            unsigned int qnamFormID = 0;
            file->GetChunkData(&qnamFormID);
            reinterpret_cast<::BGSExplosion *>(this)->FUN_004fb0b0((::BGSImpactDataSet *)(qnamFormID));
            break;
        }

        case 0x4D414E52: {
            unsigned int rnamFormID = 0;
            file->GetChunkData(&rnamFormID);
            reinterpret_cast<BGSTalkingActivator*>(this)->SetVoiceType(reinterpret_cast<BGSVoiceType*>(rnamFormID));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }

    return true;
}

struct S1
{
    void FUN_00516240();
};
struct S2
{
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_00516b60_shell
{
    void CopyFromContainer(TESForm* apCopy);
};
struct FUN_005e79a0_t
{
};
struct PlayerMover
{
    unsigned int GetActorStateFlags();
};
class Actor;
struct FUN_00516bf0_shell
{
public:
    ::Actor *FUN_00516bf0();
};
class TESSound;
struct FUN_008ce390_shell
{
public:
    ::TESSound *FUN_008ce390();
};
struct FUN_00461150_shell
{
public:
    void *FUN_00461150();
};
// @fnv 0x00516b60
void FUN_00516b60_shell::CopyFromContainer(TESForm* apCopy)
{
    TESObjectCONT* cont = dynamic_cast<TESObjectCONT*>(apCopy);
    if (!cont)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_00516b60_shell*)this)))->FUN_004851b0(apCopy);
    *(unsigned char*)((char*)this + 0x98) = *((unsigned char *)(reinterpret_cast<::FUN_00461150_shell *>((((FUN_00516b60_shell*)cont)))->FUN_00461150()));
    reinterpret_cast<::FUN_008cc6d0_class *>((((FUN_00516b60_shell*)this)))->FUN_008cc6d0((std::intptr_t)(reinterpret_cast<::FUN_008ce390_shell *>((((FUN_00516b60_shell*)cont)))->FUN_008ce390()));
    reinterpret_cast<::BGSExplosion *>((((FUN_00516b60_shell*)this)))->FUN_004fb0b0((::BGSImpactDataSet *)(::TESObjectREFR *)(((::TESObjectREFR *)(reinterpret_cast<::FUN_00516bf0_shell *>((((FUN_00516b60_shell*)cont)))->FUN_00516bf0()))));
    reinterpret_cast<::BGSTalkingActivator *>((((FUN_00516b60_shell*)this)))->SetVoiceType(((::BGSVoiceType *)(reinterpret_cast<::PlayerMover *>((((FUN_00516b60_shell*)cont)))->GetActorStateFlags())));
}
struct FUN_00516c10_shell
{
    signed char c98;
    bool IsNotMatchingContainer(TESForm* apCompare);
};
// @fnv 0x00516c10
bool FUN_00516c10_shell::IsNotMatchingContainer(TESForm* apCompare)
{
    TESObjectCONT* pComp = dynamic_cast<TESObjectCONT*>(apCompare);
    if (!pComp)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pComp))
        return true;
    if (*(signed char*)((char*)this + 0x98) != *(signed char*)((::BSSimpleList< ::TESObjectREFR *> *)(((FUN_00461150_shell*)pComp)->FUN_00461150())))
        return true;
    if (((FUN_008ce390_shell*)this)->FUN_008ce390() != ((FUN_008ce390_shell*)pComp)->FUN_008ce390())
        return true;
    if (((::TESObjectREFR *)(((FUN_00516bf0_shell*)this)->FUN_00516bf0())) != ((::TESObjectREFR *)(((FUN_00516bf0_shell*)pComp)->FUN_00516bf0())))
        return true;
    if (((PlayerMover*)this)->GetActorStateFlags() != ((PlayerMover*)pComp)->GetActorStateFlags())
        return true;
    return false;
}

struct FUN_00516a20_shell
{
    void FUN_00516a20();
};

struct FUN_00481b40_shell
{
    void FUN_00481b40();
};

struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct DoorPart30
{
};

struct DoorPart3c
{
};

struct DoorPart5c
{
};

struct DoorPart68
{
};

struct FUN_00485e00_shell
{
};


// @fnv 0x00516a20
void FUN_00516a20_shell::FUN_00516a20()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<DoorPart30*>(reinterpret_cast<char*>(this) + 0x3c)))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<DoorPart3c*>(reinterpret_cast<char*>(this) + 0x48)))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::S_0048cca0 *>((reinterpret_cast<DoorPart5c*>(reinterpret_cast<char*>(this) + 0x68)))->FUN_0048cca0();
    reinterpret_cast<FUN_00481b40_shell*>(reinterpret_cast<char*>(this) + 0x30)->FUN_00481b40();
    reinterpret_cast<::FUN_00477f20_shell *>((reinterpret_cast<DoorPart68*>(reinterpret_cast<char*>(this) + 0x7c)))->FUN_00477f20();

    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<TESForm*>(reinterpret_cast<char*>(this) + 0x98)->TESForm::ClearData();
    }

    reinterpret_cast<::SDSaveForm *>((reinterpret_cast<FUN_00485e00_shell*>(this)))->FUN_00485e20(
        reinterpret_cast<TESForm*>(reinterpret_cast<char*>(this) + 0x98), 1);

    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<TESForm*>(reinterpret_cast<char*>(this) + 0x98)->TESForm::ClearData();
    }

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x8c))
    {
        {
            unsigned int itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x8c))))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e53, itempint);
        }
    }

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x90))
    {
        {
            unsigned int itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x90))))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e51, itempint);
        }
    }

    if (*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x94))
    {
        {
            unsigned int itempint = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(((*reinterpret_cast<TESSound**>(reinterpret_cast<char*>(this) + 0x94))))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e52, itempint);
        }
    }

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

struct PrimaryBase_b4857
{
    virtual ~PrimaryBase_b4857();
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
};

struct SecondaryA_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    ~SecondaryA_b4857();
};

struct SecondaryB_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    ~SecondaryB_b4857();
};

struct SecondaryC_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    ~SecondaryC_b4857();
};

struct SecondaryD_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    unsigned int unk08;
};

struct SecondaryE_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    ~SecondaryE_b4857();
};

struct SecondaryF_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
    ~SecondaryF_b4857();
};

struct SecondaryG_b4857
{
    virtual void Vslot00()
    {}
    unsigned int unk04;
};

class FUN_00516240 : public PrimaryBase_b4857,
                     public SecondaryA_b4857,
                     public SecondaryB_b4857,
                     public SecondaryC_b4857,
                     public SecondaryD_b4857,
                     public SecondaryE_b4857,
                     public SecondaryF_b4857,
                     public SecondaryG_b4857
{
  public:
    virtual ~FUN_00516240();
};
// @fnv 0x00516210
void* S2::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00516240 *>((((S1*)this)))->FUN_00516240::~FUN_00516240();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Empty destructor for a class inheriting from multiple base classes.
// @fnv 0x00516240
FUN_00516240::~FUN_00516240()
{}

// FUN_005173d0 : 8-byte MSVC this-adjusting (adjustor) thunk.
//     sub ecx, 0x48 ; jmp <final overrider>
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot from two bases: the slot of the secondary base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, sizeof of
// the primary base) and tail-jumps to the final overrider.
//
// The subtracted offset is the size of the primary base, so the primary base
// is laid out as a vtable pointer plus 17 int members (4 + 68 = 0x48 bytes).
// Both bases declare the same virtual function; the derived class redeclares
// it and defines only its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct ContainerPrimaryBase
{
    virtual void FUN_005173d0();
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
};

struct ContainerSecondaryBase
{
    virtual void FUN_005173d0();
};

struct ContainerDerived : ContainerPrimaryBase, ContainerSecondaryBase
{
    ContainerDerived();
// @fnv 0x005173d0
    virtual void FUN_005173d0();
};

ContainerDerived::ContainerDerived()
{}

#include "generated/data/fallout_shared/tesobjectcont.inc"
