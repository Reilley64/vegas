// fallout/magic/magichiteffect.cpp: MagicHitEffect (17 functions)

#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00973fd0_cls.h"
#include "fnv/decl/Holder00682a30.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicTarget.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_0081b000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011df000.h"
#include "fnv/symbols_011e0000.h"
#include "magichiteffect_decls.h"
// @fnv 0x0081bc50
void MagicHitEffect::ResetTargetPointer()
{
    pTarget = 0;
}
// Constructs a MagicHitEffect: stores the target and effect, derives the cell from the target, and initialises the float and bool members.
// @fnv 0x0081b700
MagicHitEffect::MagicHitEffect(TESObjectREFR* target, ActiveEffect* effect) : BSTempEffect(0, 0.0f)
{
    pTarget = target;
    if (pTarget)
        pCell = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((pTarget))->GetTarget()));
    pEffect = effect;
    m_fFirstFloatValue = 0.0f;
    m_fParticleParameter5 = 3.402823466e+38f;
    bWasPlaying = false;
}

struct Arg_0081b830
{
    int value;
};

struct Sub_00905330
{
};

struct Owner_0081b830
{
    char pad_00[0x40];
    Sub_00905330* unk40;
};

// If the subobject at offset 0x40 is non-null, forwards the argument to its _ref_00905330 method.
// @fnv 0x0081b830
void ForwardArgToSubobject(Owner_0081b830* pThis, Arg_0081b830 arg)
{
    if (pThis->unk40 != 0)
    {
        reinterpret_cast<::ItemChangeListNode *>((pThis->unk40))->FUN_00905330((*(::InventoryStackRecord *const *)(&arg)));
    }
}

struct FUN_0081b6c0_shell;

// @fnv 0x0081b6c0
int FUN_0081b6c0(int)
{
    return 4;
}


struct FUN_0081b6b0_s
{
    const char* const* GetArg1Ptr() const;
};

// @fnv 0x0081b6b0
const char* const* FUN_0081b6b0_s::GetArg1Ptr() const
{
    return &(*reinterpret_cast<const char *const *>(&::g_011dc6b4));
}

struct FUN_0081b6d0_s
{
    void FUN_0081b7b0();
    void* FUN_0081b6d0(unsigned int flags);
};

// @fnv 0x0081b6d0
void* FUN_0081b6d0_s::FUN_0081b6d0(unsigned int flags)
{
    FUN_0081b7b0();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x28);
    return this;
}

namespace fnv_0081b7b0 {
struct Owner_0081b830
{
};

struct FUN_0081b7b0 : BSTempEffect
{
    ActiveEffect* pEffect;
    TESObjectREFR* pTarget;
    virtual ~FUN_0081b7b0();
};

// Clears pTarget, notifies pEffect via ForwardArgToSubobject if set, then clears pEffect.
// @fnv 0x0081b7b0
FUN_0081b7b0::~FUN_0081b7b0()
{
    pTarget = 0;
    if (pEffect)
        ::ForwardArgToSubobject((::Owner_0081b830 *)(((Owner_0081b830*)pEffect)), (::Arg_0081b830)(this));
    pEffect = 0;
}
}  // namespace fnv_0081b7b0

struct ActiveEffect;

struct FUN_008df040_shell
{
    unsigned char FUN_008df040();
};
typedef FUN_008df040_shell TESSaveLoadGame;


struct FUN_0081bd30_s
{
    unsigned short GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);
};

// Returns the save size for an active effect: 5 bytes, plus 4 more when the save version is at least 0x72.
// @fnv 0x0081bd30
unsigned short FUN_0081bd30_s::GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    unsigned short isize = 0;
    isize += 4;
    isize += 1;
    if ((*reinterpret_cast<::FUN_008df040_shell * *>(&::g_TESSaveLoadGame))->FUN_008df040() >= 0x72)
        isize += 4;
    return isize;
}

namespace fnv_0081bd80 {
struct ActiveEffect;

struct TESSaveLoadGame
{
};


struct FUN_0081bd80_s
{
    void FUN_0081bd80(ActiveEffect* apEffect, TESObjectREFR* apTarget);
};

// @fnv 0x0081bd80
void FUN_0081bd80_s::FUN_0081bd80(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0081bd80::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((char*)this + 0x20, 4);
    reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0081bd80::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((char*)this + 0x24, 1);
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_0081bd80::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x72)
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0081bd80::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0((char*)this + 8, 4);
}
}  // namespace fnv_0081bd80

struct ActiveEffect;

struct FUN_0081be50_s
{
    void SetTargetCell(ActiveEffect* apEffect, TESObjectREFR* apTarget);
};

// If apTarget is non-null, stores the cell returned by apTarget->GetTarget() at offset 0xc of this object.
// @fnv 0x0081be50
void FUN_0081be50_s::SetTargetCell(ActiveEffect* apEffect, TESObjectREFR* apTarget)
{
    if (apTarget)
        *(TESObjectCELL**)((char*)this + 0xc) = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((apTarget))->GetTarget()));
}

struct BGSSaveFormBuffer
{
};

struct FUN_00682a30_base
{
};

struct FUN_0081be80_s : FUN_00682a30_base
{
    void FUN_0081be80(BGSSaveFormBuffer* apSaveGameBuffer);
};

// Calls the base save, writes the 4-byte field at 0x20 and the byte at 0x24, then saves the TESObjectREFR pointer at 0x1c.
// @fnv 0x0081be80
void FUN_0081be80_s::FUN_0081be80(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::Holder00682a30 *>(this)->FUN_00682a30(apSaveGameBuffer);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((char*)this + 0x20, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50((char*)this + 0x24, 1, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(*(TESObjectREFR**)((char*)this + 0x1c)), 0);
}

struct BGSLoadFormBuffer
{
};

struct FUN_00682a80_shell
{
    void FUN_00682a80(BGSLoadFormBuffer* apBuffer);
};

struct FUN_0081bed0_s : FUN_00682a80_shell
{
    void LoadFormData(BGSLoadFormBuffer* apLoadGameBuffer);
};

// @fnv 0x0081bed0
void FUN_0081bed0_s::LoadFormData(BGSLoadFormBuffer* apLoadGameBuffer)
{
    FUN_00682a80(apLoadGameBuffer);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x20), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 0x24), 1);
    reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apLoadGameBuffer))->FUN_008648e0((unsigned int *)(void *)((char*)this + 0x1c));
}

namespace fnv_0081bde0 {
struct TESSaveLoadGame
{
};


struct FUN_0081bde0_shell
{
    char pad[0x18];
    ActiveEffect* pEffect;
    TESObjectREFR* pTarget;
    char pad2[0x14];
    char pad3[4];
    char pad4[4];
    char pad5[4];

    void SaveLoad(ActiveEffect* apActiveEffect, TESObjectREFR* apTarget);
};

// @fnv 0x0081bde0
void FUN_0081bde0_shell::SaveLoad(ActiveEffect* apActiveEffect, TESObjectREFR* apTarget)
{
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0081bde0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(reinterpret_cast<char*>(this) + 0x20, 4);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0081bde0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(reinterpret_cast<char*>(this) + 0x24, 1);
    if (reinterpret_cast<::FUN_008df040_shell *>(((*reinterpret_cast<::fnv_0081bde0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008df040() >= 0x72)
    {
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0081bde0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(reinterpret_cast<char*>(this) + 8, 4);
    }
    this->pEffect = apActiveEffect;
    this->pTarget = apTarget;
}
}  // namespace fnv_0081bde0

struct FUN_0081b860_vt
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual int vf116();
};

struct FUN_00440d80_shell
{
    unsigned char FUN_00440d80();
};

struct FUN_0081b860_cls : MagicHitEffect
{
    bool UpdateMagicHitEffect(float afDelta);
};

// @fnv 0x0081b860
bool FUN_0081b860_cls::UpdateMagicHitEffect(float afDelta)
{
    m_fFirstFloatValue += afDelta;
    if (pTarget == 0 || reinterpret_cast<FUN_0081b860_vt*>(pTarget)->vf116() == 0 ||
        reinterpret_cast<FUN_00440d80_shell*>(pTarget)->FUN_00440d80() != 0)
    {
        return false;
    }
    if (m_fFirstFloatValue > m_fParticleParameter5)
    {
        bWasPlaying = true;
    }
    return true;
}

struct Node;

struct VObj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55(Node* apArg, int aiFlag);
};

struct Node
{
};

struct FUN_0081bc70_s
{
    void FUN_0081bc70(Node* apArg);
};

// @fnv 0x0081bc70
void FUN_0081bc70_s::FUN_0081bc70(Node* apArg)
{
    if (((::Node *)(reinterpret_cast<::BGSTerrainManager *>(this)->GetMinLevel())))
    {
        reinterpret_cast<::FUN_0041fd00_shell *>(this)->FUN_0041fd00((int)(((void *)(reinterpret_cast<::LowProcess *>((((::Node *)(reinterpret_cast<::BGSTerrainManager *>(this)->GetMinLevel()))))->GetTarget()))));
        if (apArg)
        {
            if (((::Node *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) && ((::Node *)(reinterpret_cast<::FUN_00545cb0_shell *>((((::Node *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->FUN_00545cb0())))
            {
                if (!((::Node *)(reinterpret_cast<::FUN_009611e0_shell *>((apArg))->FUN_009611e0())) || ((::Node *)(reinterpret_cast<::FUN_00545cb0_shell *>((((::Node *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->FUN_00545cb0())) != ((::Node *)(reinterpret_cast<::FUN_009611e0_shell *>((((::Node *)(reinterpret_cast<::FUN_009611e0_shell *>((apArg))->FUN_009611e0()))))->FUN_009611e0())))
                {
                    VObj* m = ((::VObj *)(reinterpret_cast<::TESObjectCELL *>((((::Node *)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0()))))->GetDynamicNode()));
                    m->v55(apArg, 1);
                }
            }
        }
    }
}

// Revert a form-call that keeps a reference target, re-resolving the target and keeping it only if it is still a reference.

class TESForm
{
  public:
    virtual ~TESForm();
};


class BF20FormCall
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;

};

class BF20RefFormCall : public BF20FormCall
{
  public:
    TESObjectREFR* m_pkTarget;

    void FUN_0081bf20(unsigned int uiFlags);
};

// Reverts the base form call with uiFlags, then re-resolves m_pkTarget through BF20ResolveForm or clears it if null.
// @fnv 0x0081bf20
void BF20RefFormCall::FUN_0081bf20(unsigned int uiFlags)
{
    reinterpret_cast<::FUN_004534f0_shell *>(this)->FUN_004534f0(uiFlags);
    m_pkTarget = m_pkTarget ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)(m_pkTarget))) : 0;
}

class TESActorBase
{
  public:
    virtual ~TESActorBase();
};
class TESCreature : public TESActorBase
{
  public:
    bool FUN_005fbf20() const;
};
class Actor
{
  public:
    virtual ~Actor();
    TESActorBase* GetActorBase();
};
class Character : public Actor
{
  public:
    virtual void v004(), v008(), v00C(), v010(), v014(), v018(), v01C(), v020(), v024(), v028(), v02C(), v030(), v034(),
        v038(), v03C(), v040(), v044(), v048(), v04C(), v050(), v054(), v058(), v05C(), v060(), v064(), v068(), v06C(),
        v070(), v074(), v078(), v07C(), v080(), v084(), v088(), v08C(), v090(), v094(), v098(), v09C(), v0A0(), v0A4(),
        v0A8(), v0AC(), v0B0(), v0B4(), v0B8(), v0BC(), v0C0(), v0C4(), v0C8(), v0CC(), v0D0(), v0D4(), v0D8(), v0DC(),
        v0E0(), v0E4(), v0E8(), v0EC(), v0F0(), v0F4(), v0F8(), v0FC(), v100(), v104(), v108(), v10C(), v110(), v114(),
        v118(), v11C(), v120(), v124(), v128(), v12C(), v130(), v134(), v138(), v13C(), v140(), v144(), v148(), v14C(),
        v150(), v154(), v158(), v15C(), v160(), v164(), v168(), v16C(), v170(), v174(), v178(), v17C(), v180(), v184(),
        v188(), v18C(), v190(), v194(), v198(), v19C(), v1A0(), v1A4(), v1A8(), v1AC(), v1B0(), v1B4(), v1B8(), v1BC(),
        v1C0(), v1C4(), v1C8(), v1CC(), v1D0(), v1D4(), v1D8(), v1DC(), v1E0(), v1E4(), v1E8(), v1EC(), v1F0(), v1F4(),
        v1F8(), v1FC(), v200(), v204(), v208(), v20C(), v210(), v214();
    virtual void V218();
};
class ActiveEffect;
class EffectSetting
{
  public:
};
class TESObjectREFR;
class CasterX
{
  public:
    virtual void v00();
    virtual TESObjectREFR* V04(ActiveEffect* pEffect);
};
class EffectSetting;
class ActiveEffect
{
  public:
    bool HasFlag(unsigned int uiFlag);
public:
    ::EffectSetting *GetEffectSetting() const;
};
class EffBase
{
  public:
    virtual ~EffBase();
    virtual void v004(), v008(), v00C(), v010(), v014(), v018(), v01C(), v020(), v024(), v028(), v02C(), v030(), v034(),
        v038(), v03C(), v040(), v044(), v048(), v04C(), v050(), v054(), v058(), v05C(), v060(), v064(), v068(), v06C(),
        v070(), v074(), v078(), v07C(), v080(), v084(), v088(), v08C(), v090(), v094(), v098(), v09C(), v0A0(), v0A4(),
        v0A8(), v0AC(), v0B0(), v0B4(), v0B8(), v0BC(), v0C0();
    virtual bool VC4();
};
struct FUN_00aa13e0
{
    void* operator new(unsigned int);
};
class FUN_0081c630 : public EffBase, public FUN_00aa13e0
{
  public:
    FUN_0081c630(TESObjectREFR* pRef);
    unsigned int unk[14];
};
class FUN_0081f350 : public EffBase, public FUN_00aa13e0
{
  public:
    FUN_0081f350(TESObjectREFR* pRef);
    unsigned int unk[26];
};
class FUN_00470440
{
  public:
    FUN_00470440(EffBase* const& pItem);
    void FUN_005ae3d0(EffBase* const& pItem);
    EffBase* m_pInventoryEntryData;
    FUN_00470440* m_pNext;
};
class SettingX
{
  public:
    bool* FUN_00408d60();
};
class MgrX
{
  public:
};

// Creates effect instances for an ActiveEffect, links successful instances, and may return early based on a setting.
// @fnv 0x0081b8e0
FUN_00470440* __cdecl CreateEffectEntries(ActiveEffect* pEffect)
{
    if (reinterpret_cast<::MagicTarget *>((((::CasterX *)(reinterpret_cast<::ActorMover *>((pEffect))->GetCurrentMoveModeType()))))->GetOwnerActor())
    {
        TESCreature* pCreature = dynamic_cast<TESCreature*>(reinterpret_cast<::MagicTarget *>((((::CasterX *)(reinterpret_cast<::ActorMover *>((pEffect))->GetCurrentMoveModeType()))))->GetOwnerActor()->GetActorBase());
        Character* pCharacter = dynamic_cast<Character*>(reinterpret_cast<::MagicTarget *>((((::CasterX *)(reinterpret_cast<::ActorMover *>((pEffect))->GetCurrentMoveModeType()))))->GetOwnerActor());
        if ((!pCreature || !pCreature->FUN_005fbf20()) && pCharacter)
            pCharacter->V218();
    }
    FUN_00470440* c = 0;
    EffBase* a = 0;
    if (0)
    {
    }
    bool bSkip = reinterpret_cast<::S3e60 *>((pEffect->GetEffectSetting()))->FUN_00403e60(0x1000) && *(*reinterpret_cast<::SettingX *>(&::g_011df7f8)).FUN_00408d60();
    if (bSkip)
        return c;
    if (!pEffect->HasFlag(4) && !FUN_00525420())
    {
        a = new FUN_0081c630(((::CasterX *)(reinterpret_cast<::ActorMover *>((pEffect))->GetCurrentMoveModeType()))->V04(pEffect));
        if (a->VC4())
        {
            reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::MgrX *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(a));
            c = new FUN_00470440(a);
        }
        else
        {
            delete a;
        }
    }
    if (!pEffect->HasFlag(2))
    {
        a = new FUN_0081f350(((::CasterX *)(reinterpret_cast<::ActorMover *>((pEffect))->GetCurrentMoveModeType()))->V04(pEffect));
        if (a->VC4())
        {
            reinterpret_cast<::FUN_00973fd0_cls *>(&((*reinterpret_cast<::MgrX *>(&::g_011e0e80))))->FUN_00973fd0((::FnvArgObj *)(a));
            if (c)
                c->FUN_005ae3d0(a);
            else
                c = new FUN_00470440(a);
        }
        else
        {
            delete a;
        }
    }
    return c;
}
