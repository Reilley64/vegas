
// src/fallout/ai/combat/combatprocedureusecombatitem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatprocedureusecombatitem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/CPStandIn009caae0.h"
#include "fnv/decl/FUN_00440e30_This.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00498d30_t.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008c1f80_shell.h"
#include "fnv/decl/FUN_0097f450_shell.h"
#include "fnv/decl/FUN_00996de0_Class.h"
#include "fnv/decl/FUN_00996ef0_shell.h"
#include "fnv/decl/FUN_009ca6c0_class.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/ProcessProxy.h"
#include "fnv/decl/fnv_004985f0__FUN_004985f0_s.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_0099a840__FUN_0099a840_shell.h"
#include "fnv/decl/fnv_009ca680__FUN_009ca680.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_005b5000.h"
struct CombatProcedure
{
    enum COMBAT_PROCEDURES
    {
        eUseCombatItem = 0xb
    };
};

struct CombatProcedureUseCombatItem : CombatProcedure
{
    COMBAT_PROCEDURES GetProcedureType();
};

// @fnv 0x009daa50
CombatProcedure::COMBAT_PROCEDURES CombatProcedureUseCombatItem::GetProcedureType()
{
    return eUseCombatItem;
}

struct FUN_009ca6c0_shell
{
};

extern void* DAT_0109214c;

struct FUN_009daa90_shell
{
    void SetVtableAndInit(void);
};

// @fnv 0x009daa90
void FUN_009daa90_shell::SetVtableAndInit()
{
    *reinterpret_cast<void**>(this) = &DAT_0109214c;
    reinterpret_cast<::FUN_009ca6c0_class *>((reinterpret_cast<FUN_009ca6c0_shell*>(this)))->FUN_009ca6c0();
}

struct FUN_009daa60_shell : FUN_009daa90_shell
{
    void* DestroyIfFlagged(unsigned int flags);
};

// Calls SetVtableAndInit, deletes this when flags has bit 1 set, and returns this.
// @fnv 0x009daa60
void* FUN_009daa60_shell::DestroyIfFlagged(unsigned int flags)
{
    SetVtableAndInit();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct TESBoundObject;
struct Base_009daa10
{
    char _pad[16];
};
struct FUN_009daa10 : Base_009daa10
{
    TESBoundObject* pItem;
    bool m_bItemFlag;
    FUN_009daa10(TESBoundObject* apItem);
};
// Calls the base constructor, installs the vtable, stores apItem in pItem and clears the flag.
// @fnv 0x009daa10
FUN_009daa10::FUN_009daa10(TESBoundObject* apItem)
{
    new ((void *)this) ::fnv_009ca680::FUN_009ca680();
    *reinterpret_cast<unsigned int*>(this) = reinterpret_cast<unsigned int>(&DAT_0109214c);
    pItem = apItem;
    m_bItemFlag = 0;
}

struct BGSLoadFormBuffer
{
};
struct TESForm
{
    virtual ~TESForm();
};
struct TESBoundObject : TESForm
{
    virtual ~TESBoundObject();
};
struct CombatProcedureUseCombatItem_LoadGame : CombatProcedureUseCombatItem
{
    void FUN_009dac80(BGSLoadFormBuffer* apLoadGameBuffer);
};
// @fnv 0x009dac80
void CombatProcedureUseCombatItem_LoadGame::FUN_009dac80(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_00996ef0_shell *>(this)->FUN_00996ef0(apLoadGameBuffer);
    ((FUN_009daa10*)this)->pItem = dynamic_cast<TESBoundObject*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apLoadGameBuffer))->FUN_008648a0()));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&((FUN_009daa10*)this)->m_bItemFlag), 1);
}

typedef void(__cdecl* FnPrint4)(void*, unsigned int, unsigned int, const char*);
typedef void(__cdecl* FnPrint6)(void*, unsigned int, unsigned int, const char*, const char*, unsigned int);

struct FUN_009dabd0_item
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* v76();
};


struct FUN_009dabd0_obj
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void __cdecl v05(unsigned int a2, unsigned int a3, const char* fmt, ...);
};

struct FUN_009dabd0_cls
{
    char unk00[0x10];
    FUN_009dabd0_item* pItem;
    bool m_bItemFlag;
    void PrintDebugInfo(FUN_009dabd0_obj* a1, unsigned int a2, unsigned int a3);
};

// If the flag is set, prints "ANIMATING"; if pItem is set, prints the item's name (or a fallback) and its id via the object's print method.
// @fnv 0x009dabd0
void FUN_009dabd0_cls::PrintDebugInfo(FUN_009dabd0_obj* pPrinter, unsigned int a2, unsigned int a3)
{
    if (this->m_bItemFlag)
    {
        pPrinter->v05(a2, a3, "ANIMATING");
    }
    if (this->pItem != 0)
    {
        pPrinter->v05(a2, a3, "Item: '%s' (%08X)",
                      (((unsigned int)(reinterpret_cast<::BGSCameraPath *>((this->pItem))->HasNameForWarning())) != 0) ? this->pItem->v76() : ::FUN_00482720((::TESForm *)(this->pItem)),
                      ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((this->pItem))->FUN_0084e3a0())));
    }
}

struct UCIItem
{
    int FUN_00401170();
};
struct UCIWeapon : UCIItem
{
};
struct UCICombatProcess
{
};
struct UCIAmmo
{
};
struct UCIActor
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual UCIAmmo* GetAmmo();
};
struct UCICombatState
{
};
struct UCIController
{
};

struct FUN_009daab0_Proc
{
    void* pVtable;
    UCIController* pController;
    int unk08;
    int unk0C;
    UCIItem* pItem;
    bool m_bItemFlag;

    void UpdateCombatItemUse();
};

// Checks the actor's combat process and ammo, then applies the combat item to the actor and combat state based on its form type.
// @fnv 0x009daab0
void FUN_009daab0_Proc::UpdateCombatItemUse()
{
    UCIActor* pActor2;
    UCICombatState* pState2;
    UCIAmmo* pAmmo;

    pActor2 = ((::UCIActor *)(reinterpret_cast<::FUN_00996de0_Class *>(this)->FUN_00996de0()));
    pState2 = ((::UCICombatState *)(reinterpret_cast<::InterfaceManager *>((pController))->FUN_00586150()));
    if (!((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::UCICombatProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor2))->GetBaseTexture()))))->FUN_0045cd60())))
    {
        pAmmo = pActor2->GetAmmo();
        if (pAmmo && (!reinterpret_cast<::fnv_004985f0::FUN_004985f0_s *>((pAmmo))->FUN_004985f0() || reinterpret_cast<::FUN_00498d30_t *>((pAmmo))->HasIdleForm((::TESIdleForm *)(0))))
            return;
        if (!m_bItemFlag)
        {
            UCICombatProcess* pProcess = ((::UCICombatProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((pActor2))->GetBaseTexture()));
            reinterpret_cast<::ProcessProxy *>((pProcess))->FUN_008ff0b0((::ActorProxy *)(pActor2), (int)(pItem), (::ActorProxy *)(0));
            m_bItemFlag = true;
            return;
        }
    }

    reinterpret_cast<::fnv_0099a840::FUN_0099a840_shell *>((pState2))->FUN_0099a840(pItem);
    switch (pItem->FUN_00401170())
    {
    case 0x2f: {
        UCIWeapon* pWeapon = static_cast<UCIWeapon*>(pItem);
        reinterpret_cast<::FUN_008c1f80_shell *>((pActor2))->EquipItemWithCaster((::FUN_008c1de0_item *)(pWeapon), 0, 1);
        reinterpret_cast<::FUN_0097f450_shell *>((pState2))->SetAttacker(1);
        break;
    }
    default:
        ::FUN_005b5e40();
    }
    reinterpret_cast<::CPStandIn009caae0 *>(this)->SetState();
}
