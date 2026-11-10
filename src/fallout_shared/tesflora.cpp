
// src/fallout_shared/tesflora.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesflora.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <malloc.h>
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_0048b670_shell.h"
#include "fnv/decl/FUN_0048b720_Cls.h"
#include "fnv/decl/FUN_00508510_Activator.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_00510770_shell.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESFile.h"
#include "fnv/decl/TESModel.h"
#include "fnv/decl/TESScriptableForm.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_01183000.h"
struct S_00477f20
{
};
struct FUN_004855a0
{
};
struct FUN_00485680
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
struct FUN_0048b5c0_shell
{
    void FUN_0048b5c0();
};

struct FUN_00508920_obj
{
    void FUN_00508920();
};

// @fnv 0x00508920
void FUN_00508920_obj::FUN_00508920()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((reinterpret_cast<S_00487010*>(reinterpret_cast<char*>(this) + 0x30)))->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>((reinterpret_cast<S_0048a520*>(reinterpret_cast<char*>(this) + 0x3c)))->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<S_0048cca0*>(reinterpret_cast<char*>(this) + 0x5c)->FUN_0048cca0();
    reinterpret_cast<::FUN_00477f20_shell *>((reinterpret_cast<S_00477f20*>(reinterpret_cast<char*>(this) + 0x68)))->FUN_00477f20();
    reinterpret_cast<FUN_0048b5c0_shell*>(reinterpret_cast<char*>(this) - 0xc)->FUN_0048b5c0();
    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

class TESForm
{
  public:
    virtual void f00();
public:
    bool GetInitialized() const;
public:
    void SetInitializationState(bool);
};
struct FUN_005e78f0_t : TESForm
{
};
struct TESFlora : FUN_005e78f0_t
{
    void FUN_00508990(TESForm*);
};
// @fnv 0x00508990
void TESFlora::FUN_00508990(TESForm* apCopy)
{
    TESFlora* pcopy = dynamic_cast<TESFlora*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(apCopy);
}

struct FUN_00508510_shell
{
};
struct FUN_00508dc0_shell
{
    void* FUN_00508dc0(unsigned int flags);
};
// Calls FUN_00508510 on this, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00508dc0
void* FUN_00508dc0_shell::FUN_00508dc0(unsigned int flags)
{
    reinterpret_cast<::FUN_00508510_Activator *>((((FUN_00508510_shell*)this)))->FUN_00508510_Activator::~FUN_00508510_Activator();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct S_005085b0_Sec;
struct S_005085b0_Prim
{
    virtual void vf00();
    int unk04;
    int unk08;
};
struct S_005085b0_Sec
{
    int unk00;
    void FUN_005085b0();
};
struct S_005085b0_D : S_005085b0_Prim, S_005085b0_Sec
{
};
// If FUN_004013e0 returns 0, calls FUN_00510770, invokes ResolveIngredient on the containing object, then FUN_00484ab0(1).
// @fnv 0x005085b0
void S_005085b0_Sec::FUN_005085b0()
{
    if (((unsigned char)(reinterpret_cast<::TESForm *>(this)->GetInitialized())) != 0)
    {
        return;
    }
    reinterpret_cast<::FUN_00510770_shell *>(this)->FUN_00510770();
    reinterpret_cast<::FUN_0048b720_Cls *>((((S_005085b0_D*)((char*)this - 0xc))))->ResolveIngredient((::FUN_00485b60_Cls *)(::S_005085b0_Sec *)((S_005085b0_D*)((char*)this - 0xc)));
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(1);
}

struct FloraFile
{
    void ReadChunkInt(unsigned int* puiFormID);
};

struct FloraProduce
{
    virtual void p00();
    int unk04, unk08;
};

struct FloraFormBase;
struct FloraFullName
{
    int unk00, unk04, unk08;
};
struct FloraModel
{
    int unk00[8];
};
struct FloraScript
{
    int unk00, unk04, unk08;
};
struct FloraDestructible
{
    int unk00;
};


struct FloraFormBase
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();

    virtual void LoadBounds(FloraFile* pkFile);
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void SetEditorID(const char* pcEditorID);
    int unk04[0x2c / 4];

    virtual bool FUN_00508610(FloraFile* pkFile) = 0;
};

struct FloraFull : FloraProduce, FloraFormBase, FloraFullName, FloraModel, FloraScript, FloraDestructible
{
    virtual bool FUN_00508610(FloraFile* pkFile);
};

// Reads chunk records from pkFile, dispatching each chunk tag to the matching loader and returning true.
// @fnv 0x00508610
bool FloraFull::FUN_00508610(FloraFile* pkFile)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(pkFile));
    reinterpret_cast<::TESForm *>(this)->SetInitializationState(0);
    int iChunk;
    while ((iChunk = reinterpret_cast<::FUN_004726b0_class *>((pkFile))->FUN_004726b0()) != 0)
    {
        switch (iChunk)
        {
        case 0x44494445: {
            char* pcEditorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((pkFile))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(pcEditorID), 0x200);
            SetEditorID(pcEditorID);
            break;
        }
        case 0x444e424f:
            LoadBounds(pkFile);
            break;
        case 0x4c4c5546:
            ::ReadFullName((::TESFullName *)(::FloraFullName *)(this), (::TESFile *)(pkFile));
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44444f4d:
        case 0x44534f4d:
            ::TESModel::LoadModelData((::TESModel *)(::FloraModel *)(this), (::TESFile *)(pkFile));
            break;
        case 0x53444f4d: {
            unsigned int uiSizeX = reinterpret_cast<::FUN_00401660_Class *>((pkFile))->GetField25C();
            char* pcDataZ = (char*)_alloca(uiSizeX);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(pcDataZ), uiSizeX);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(pcDataZ, uiSizeX, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((pkFile))->FUN_00403570());
            break;
        }
        case 0x49524353: {
            unsigned int uiScript = 0;
            pkFile->ReadChunkInt(&uiScript);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(std::uintptr_t)(uiScript));
            reinterpret_cast<::TESScriptableForm *>(this)->InitItem((::TESForm *)(::FloraFormBase *)(this));
            break;
        }
        case 0x47494650: {
            unsigned int uiIngredient = 0;
            pkFile->ReadChunkInt(&uiIngredient);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(std::uintptr_t)(uiIngredient));
            break;
        }
        case 0x43504650: {
            int m_ucSortOrder;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((pkFile))->FUN_00472890((char *)(void *)(&m_ucSortOrder), 4);
            reinterpret_cast<::FUN_0048b670_shell *>(this)->CopyFromSource(&m_ucSortOrder);
            break;
        }
        case 0x44545344:
        case 0x54534544:
            ::FUN_004781e0((::BGSDestructibleObjectForm *)(::FloraDestructible *)(this), (::TESFile *)(pkFile));
            break;
        }
        if (!reinterpret_cast<::TESFile *>((pkFile))->NextChunk())
            break;
    }
    return true;
}

extern int DAT_01189f7c;


struct FUN_005089d0_cls
{
    bool FUN_005089d0(void* apObject);
};

// @fnv 0x005089d0
bool FUN_005089d0_cls::FUN_005089d0(void* apObject)
{
    void* pFound;
    pFound = dynamic_cast<::TESFlora *>(reinterpret_cast<::TESForm *>(apObject));
    if (pFound == 0)
    {
        return true;
    }
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(void *)(pFound != 0 ? (char*)pFound + 0xc : 0)))
    {
        return true;
    }
    return false;
}

struct Prim_508db0
{
    virtual void FUN_00508db0();
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
    int p20;
    int p24;
    int p28;
    int p2c;
    int p30;
    int p34;
    int p38;
    int p3c;
    int p40;
    int p44;
};

struct B1_508db0
{
    virtual void FUN_00508db0();
};

struct TO_508db0 : Prim_508db0, B1_508db0
{
// @fnv 0x00508db0
    virtual void FUN_00508db0();
};

static TO_508db0 g_thunk;

// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase_00508df0
{
    virtual void FUN_00508df0();
    int unk04;
    int unk08;
};

struct SecondaryBase_00508df0
{
    virtual void FUN_00508df0();
};

struct Derived_00508df0 : PrimaryBase_00508df0, SecondaryBase_00508df0
{
    Derived_00508df0();
// @fnv 0x00508df0
    virtual void FUN_00508df0();
};

Derived_00508df0::Derived_00508df0()
{}
