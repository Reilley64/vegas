// fallout_shared/tesobjectmisc.cpp: TESObjectMISC, TESCaravanMoney, TargetHolder (13 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00484bf0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_0048ea80_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0051a840.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/PC7d.h"
#include "fnv/decl/S00485110.h"
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
#include "fnv/decl/fnv_008cdd90__FUN_008cdd90_shell.h"
#include "fnv/decl/form_load_legacy__TESFormLoadProxy.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "tesobjectmisc_decls.h"
#include <malloc.h>
#include "fnv/symbols_00472000.h"
extern const char DAT_0102b038[];

// @fnv 0x0051a980
void TESObjectMISC::ResetFormData()
{
    pLoopingSound = 0;
}

// Initializes the scriptable, destructible, model, and pickup sound sub-forms, resolves pLoopingSound by form ID, and marks the object initialized.
// @fnv 0x0051a9a0
void TESObjectMISC::InitItem()
{
    if (GetInitialized())
        return;

    static_cast<TESScriptableForm *>(this)->InitItem(this);
    static_cast<BGSDestructibleObjectForm *>(this)->InitItem(this);
    static_cast<TESModelTextureSwap *>(this)->InitItem(this);
    static_cast<BGSPickupPutdownSounds *>(this)->InitItem(this);

    unsigned int formID = (unsigned int)(std::uintptr_t)pLoopingSound;
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pLoopingSound = dynamic_cast<TESSound*>(::FUN_004839c0(formID));
        if (!pLoopingSound)
            ::FUN_005b5e40();
    }

    SetInitializationState(true);
}

// @fnv 0x0059ae60
TESCaravanMoney::TESCaravanMoney()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(kFormIDCaravanMoney)));
    ResetFormData();
}

// @fnv 0x0051aaa0
bool TESObjectMISC::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    while (int chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID(editorID);
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
            char* swaps;
            {
                unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
                swaps = (char*)_alloca(size);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(swaps), size);
                reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(swaps, size, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570());
            }
            break;
        }
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(this, file);
            break;
        case 0x4f43494d:
            ::FUN_0047a290((::TeleportableReference *)(::BGSMessageIcon *)(this), file);
            break;
        case 0x49524353: {
            unsigned int scriptID = 0;
            file->GetChunkData(&scriptID);
            ((CombatProcedure*)static_cast<TESScriptableForm *>(this))->Initialize((CombatController*)scriptID);
            TESScriptableForm::InitItem(this);
            break;
        }
        case 0x54534544:
        case 0x44545344:
            ::FUN_004781e0(this, file);
            break;
        case 0x4d414e59: {
            unsigned int pickupID = 0;
            file->GetChunkData(&pickupID);
            ((CombatProcedure*)static_cast<BGSPickupPutdownSounds *>(this))->Initialize((CombatController*)pickupID);
            break;
        }
        case 0x4d414e5a: {
            unsigned int putdownID = 0;
            file->GetChunkData(&putdownID);
            ((TESRegionGrassObject*)static_cast<BGSPickupPutdownSounds *>(this))->AssignLandTexture((TESLandTexture*)putdownID);
            break;
        }
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((BGSImpactData*)this)))->FUN_004861f0(file, 0, 0);
            break;
        case 0x4d414e52: {
            unsigned int loopingID = 0;
            file->GetChunkData(&loopingID);
            reinterpret_cast<::TESObjectMISC *>(this)->SetLoopingSound((::TESSound *)(loopingID));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_0051b070_shell
{
    void FUN_0051b070(unsigned int aiFlags);
};

// Calls FUN_00484c20 with aiFlags, then calls FUN_0048e9e0 with aiFlags on the object at this+0x74.
// @fnv 0x0051b070
void FUN_0051b070_shell::FUN_0051b070(unsigned int aiFlags)
{
    reinterpret_cast<::PC7d *>(this)->FUN_00484c20(aiFlags);
    reinterpret_cast<::fnv_0048e9e0::TESValueForm *>((reinterpret_cast<FUN_0051b070_shell*>(reinterpret_cast<char*>(this) + 0x74)))->FUN_0048e9e0(aiFlags);
}

struct FUN_00484bf0
{
};
struct FUN_0048e9b0
{
};

struct FUN_0051b020_shell
{
    unsigned short FUN_0051b020(unsigned int aiFlags);
};

// Returns the sum of GetSaveSize(aiFlags) for this object and the sub-object at offset 0x74.
// @fnv 0x0051b020
unsigned short FUN_0051b020_shell::FUN_0051b020(unsigned int aiFlags)
{
    unsigned short isize = 0;
    isize += reinterpret_cast<::FUN_00484bf0_shell *>((((FUN_00484bf0*)this)))->FUN_00484bf0(aiFlags);
    isize += reinterpret_cast<::fnv_0048e9b0::TESValueForm *>((((FUN_0048e9b0*)((char*)this + 0x74))))->FUN_0048e9b0(aiFlags);
    return isize;
}

struct TESFormStub
{
};

struct TESValueFormStub
{
};

struct BGSLoadFormBuffer;

struct FUN_0051b0a0_shell
{
    void LoadForm(unsigned int aiFlags, BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x0051b0a0
void FUN_0051b0a0_shell::LoadForm(unsigned int aiFlags, BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::form_load_legacy::TESFormLoadProxy *>((reinterpret_cast<TESFormStub*>(this)))->FUN_00484c50(aiFlags,
                                                                    reinterpret_cast<unsigned int>(apLoadGameBuffer));
    reinterpret_cast<::fnv_0048ea10::TESValueForm *>((reinterpret_cast<TESValueFormStub*>(reinterpret_cast<char*>(this) + 0x74)))->FUN_0048ea10(aiFlags, reinterpret_cast<unsigned int>(apLoadGameBuffer));
}

struct CallHelper
{
};
struct TargetHolder
{
    void* ReleaseIfFlagged(unsigned int);
};
// @fnv 0x0051a810
void* TargetHolder::ReleaseIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0051a840 *>((((CallHelper*)this)))->FUN_0051a840::~FUN_0051a840();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct S_00477f20
{
};
struct S_00487010
{
};
struct S_0048a520
{
};
struct S_0048cca0
{
    void FUN_0048cca0();
};
struct FUN_0047a240_shell
{
    void FUN_0047a240(unsigned int);
};
struct FUN_0047b560_holder
{
};
struct FUN_0048e370_obj
{
};
struct FUN_00485e00_shell
{
    void FUN_00485e00();
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_0051ae80_shell
{
    void FUN_0051ae80();
};
// @fnv 0x0051ae80
void FUN_0051ae80_shell::FUN_0051ae80()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)((char*)this + 0x30))))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((((S_0048a520*)((char*)this + 0x3c))))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((((FUN_0048e370_obj*)((char*)this + 0x5c))))->FUN_0048e370(0x4e4f4349);
    ((FUN_0047a240_shell*)((char*)this + 0x8c))->FUN_0047a240(0x4f43494d);
    ((S_0048cca0*)((char*)this + 0x68))->FUN_0048cca0();
    reinterpret_cast<::FUN_00477f20_shell *>((((S_00477f20*)((char*)this + 0x84))))->FUN_00477f20();
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>((((FUN_0047b560_holder*)((char*)this + 0x9c))))->LogFormIDs();
    ((FUN_00485e00_shell*)this)->FUN_00485e00();
    if (*(unsigned int*)((char*)this + 0xa8))
    {
        unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm**)((char*)this + 0xa8))[0]))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e52, formID);
    }
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct FUN_005e78f0_t
{
};
struct FUN_008cdd90_shell
{
};
struct FUN_0051af50_shell
{
    void FUN_0051af50(TESForm* apCopy);
};
// @fnv 0x0051af50
void FUN_0051af50_shell::FUN_0051af50(TESForm* apCopy)
{
    TESObjectMISC* pmisc = dynamic_cast<TESObjectMISC*>(apCopy);
    if (!pmisc)
        return;
    ((TESObjectMISC*)this)->SetLoopingSound((::TESSound *)(((unsigned int)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>((((FUN_008cdd90_shell*)pmisc)))->FUN_008cdd90()))));
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
}

struct BGSSaveFormBuffer;
struct FUN_00484d60_holder
{
};
struct FUN_0048ea40_holder
{
};
struct FUN_0051b0d0_holder
{
    void SaveToBuffer(BGSSaveFormBuffer*);
};
// Saves this object to the buffer by calling the save routine at offset 0 and the one at offset 0x74.
// @fnv 0x0051b0d0
void FUN_0051b0d0_holder::SaveToBuffer(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::FakeForm *>((reinterpret_cast<FUN_00484d60_holder*>(this)))->SaveIfChanged(buffer);
    reinterpret_cast<::fnv_0048ea40::TESValueForm *>((reinterpret_cast<FUN_0048ea40_holder*>(reinterpret_cast<char*>(this) + 0x74)))->FUN_0048ea40((::fnv_0048ea40::BGSSaveFormBuffer *)(buffer));
}

struct TESFormBufferAccess
{
};
struct TESValueFormLoadGame
{
};
struct FUN_0051b100_owner
{
    void FUN_0051b100(BGSLoadFormBuffer* apLoadGameBuffer);
};
// Loads the form from the buffer, then loads the value form at offset 0x74 from the same buffer.
// @fnv 0x0051b100
void FUN_0051b100_owner::FUN_0051b100(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::TESForm *>((reinterpret_cast<TESFormBufferAccess*>(this)))->LoadGame(apLoadGameBuffer);
    reinterpret_cast<::FUN_0048ea80_Class *>((reinterpret_cast<TESValueFormLoadGame*>((char*)this + 0x74)))->FUN_0048ea80(apLoadGameBuffer);
}

struct FUN_005e79a0_t
{
};
struct FUN_0051afb0_shell : public FUN_008cdd90_shell
{
    bool FUN_0051afb0(TESForm* apCompare);
};
// @fnv 0x0051afb0
bool FUN_0051afb0_shell::FUN_0051afb0(TESForm* apCompare)
{
    TESObjectMISC* pcomp = dynamic_cast<TESObjectMISC*>(apCompare);
    if (!pcomp)
        return true;
    if (((unsigned int)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>(this)->FUN_008cdd90())) != ((unsigned int)(reinterpret_cast<::fnv_008cdd90::FUN_008cdd90_shell *>((((FUN_008cdd90_shell*)pcomp)))->FUN_008cdd90())))
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270((TESForm*)pcomp))
        return true;
    return false;
}

// MSVC adjustor thunk: the primary base occupies 0x3c bytes; both bases declare the virtual,
// the derived class defines only its constructor, so the compiler emits the this-adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0051b130();
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

struct SecondaryBase
{
    virtual void FUN_0051b130();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0051b130
    virtual void FUN_0051b130();
};

Derived::Derived()
{}
