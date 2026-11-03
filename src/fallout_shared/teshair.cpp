// fallout_shared/teshair.cpp: TESHair, HairComparisonEntry (10 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_005fdb90.h"
#include "fnv/decl/FUN_005fdc30_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0045b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "teshair_types_TESHair.h"
#include "teshair_decls.h"
#include <malloc.h>
#include "fnv/decl/FUN_005fdf60_shell.h"
#include "fnv/decl/FUN_005fdf80_shell.h"

// @fnv 0x005fdaa0
TESHair::TESHair() : TESForm(), TESFullName(), TESModel(), TESTexture()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)10)));
    reinterpret_cast<::FUN_005fdc30_shell *>(this)->FUN_005fdc30();
}

// Loads a hair record: verifies form type 10, reads the record header, then dispatches EDID, OBND, FULL, MODL/MODD, ICON and DATA chunks until no chunks remain.
// @fnv 0x005fdcb0
bool TESHair::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((((TESFileFormInt*)file)))->FUN_00472660() != 10)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    unsigned int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch ((int)chunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
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
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x4e4f4349:
            ::TESTexture::ReadTextureData(this, file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&cFlags), 1);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_005fdf60_shell : public TESHair
{
    bool FUN_005fdf60();
};

// @fnv 0x005fdf60
bool FUN_005fdf60_shell::FUN_005fdf60()
{
    if (*((char*)this + 0x48) & 2)
        return false;
    return true;
}

struct TESNPC;
struct TESRace;
struct TESRaceForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static TESRace* GetFormRace(TESForm*);
    TESRace* GetFormRace();
    static char* GetFormRaceEditorID(TESForm*);
    char* GetFormRaceEditorID();
    void SetFormRace(TESRace*);
    TESRace* m_pRace;
};
struct FUN_005fdfa0_shell : public TESHair
{
    bool IsHairValidForNPC(TESNPC*);
};

struct FUN_005fdf40_shell
{
// @fnv 0x005fdf40
    virtual ~FUN_005fdf40_shell()
    {}
    bool FUN_005fdf40();
};

bool FUN_005fdf40_shell::FUN_005fdf40()
{
    return (bool)((*(signed char*)((char*)this + 0x48) & 1) != 0);
}

struct FUN_005fdf80_shell
{
    bool IsFlag4Clear();
};
// @fnv 0x005fdfa0
bool FUN_005fdfa0_shell::IsHairValidForNPC(TESNPC* apNPC)
{
    bool bretval = false;
    BGSQuestObjective* hair;
    if (apNPC && ((::TESHairRaceResult *)(reinterpret_cast<::FUN_004ac110_shell *>((((TESHairCanBeNPCData*)apNPC)))->FUN_004ac110())) != 0)
    {
        hair = (BGSQuestObjective*)this;
        if (reinterpret_cast<::RefList *>((((::BSSimpleList< ::BGSQuestObjective *> *)(::FUN_0045bb80((int)(((::TESHairRaceResult *)(reinterpret_cast<::FUN_004ac110_shell *>((((TESHairCanBeNPCData*)apNPC)))->FUN_004ac110()))))))))->FUN_005f65d0((void **)&(hair)))
        {
            switch (((TESActorBase*)apNPC)->GetSex())
            {
            case eSex_Male:
                if (reinterpret_cast<::FUN_005fdf60_shell *>(this)->FUN_005fdf60())
                {
                    bretval = true;
                }
                break;
            case eSex_Female:
                if (reinterpret_cast<::FUN_005fdf80_shell *>(this)->IsFlag4Clear())
                {
                    bretval = true;
                }
                break;
            }
        }
    }
    return bretval;
}

// @fnv 0x005fdf80
bool FUN_005fdf80_shell::IsFlag4Clear()
{
    if (((char*)this)[0x48] & 0x4)
        return false;
    return true;
}

struct FUN_005e78f0_t
{
};

struct FUN_005fde80_shell
{
    void CopyFromHair(TESForm* apCopy);
};

// @fnv 0x005fde80
void FUN_005fde80_shell::CopyFromHair(TESForm* apCopy)
{
    TESHair* pcopy = dynamic_cast<TESHair*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
    ((char*)this)[0x48] = ((char*)pcopy)[0x48];
}

struct S
{
    void* FUN_005fdb60(unsigned int);
};
// Calls FUN_005fdb90, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x005fdb60
void* S::FUN_005fdb60(unsigned int flags)
{
    reinterpret_cast<::FUN_005fdb90 *>(this)->FUN_005fdb90::~FUN_005fdb90();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct S_00487010
{
};
struct FUN_0048e370_obj
{
};
struct FUN_004891d0_holder
{
};

struct FUN_005fdc50_shell
{
    void FUN_005fdc50();
};

// @fnv 0x005fdc50
void FUN_005fdc50_shell::FUN_005fdc50()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<S_00487010*>(reinterpret_cast<char*>(this) + 0x18)))->FUN_00487010();
    reinterpret_cast<::FUN_004891d0_cls *>((reinterpret_cast<FUN_004891d0_holder*>(reinterpret_cast<char*>(this) + 0x24)))->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>((reinterpret_cast<FUN_0048e370_obj*>(reinterpret_cast<char*>(this) + 0x3c)))->FUN_0048e370(0x4e4f4349);
    FUN_004858f0(0x41544144, reinterpret_cast<char*>(this)[0x48]);
    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

struct HairComparisonEntry : public TESHair
{
    bool FUN_005fded0(TESForm*);
};
// Returns true if apCompare is not a TESHair, differs per FUN_00485270, or has a different cFlags value.
// @fnv 0x005fded0
bool HairComparisonEntry::FUN_005fded0(TESForm* apCompare)
{
    TESHair* pCompare = dynamic_cast<TESHair*>(apCompare);
    if (!pCompare)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(pCompare))
        return true;
    if (pCompare->cFlags != cFlags)
        return true;
    return false;
}

// sub ecx,0x24; jmp FUN_005fdb60  ==  MSVC adjustor thunk (multiple inheritance).
// The primary base occupies 0x24 bytes; both bases declare the same virtual, and the
// derived class defines only its constructor, so the compiler emits the this-adjusting
// thunk for the secondary base's vtable slot.
struct PrimaryBase
{
    virtual void FUN_005fe030();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct SecondaryBase
{
    virtual void FUN_005fe030();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x005fe030
    virtual void FUN_005fe030();
};

Derived::Derived()
{}
