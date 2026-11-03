// src/fallout_shared/tesobjectcell_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESObjectREFR). The skeleton of src/fallout_shared/tesobjectcell.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include <cstdint>
#include <new>
#include "fnv/decl/BGSImpactData.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CellShell.h"
#include "fnv/decl/CollectionView.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_004120b0_shell.h"
#include "fnv/decl/FUN_00418660_shell.h"
#include "fnv/decl/FUN_00421c30_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004512a0_shell.h"
#include "fnv/decl/FUN_00452440_shell.h"
#include "fnv/decl/FUN_00453490_shell.h"
#include "fnv/decl/FUN_00458400_cls.h"
#include "fnv/decl/FUN_004610d0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_005445d0_shell.h"
#include "fnv/decl/FUN_00544600_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00545cf0_Cls.h"
#include "fnv/decl/FUN_005535f0_shell.h"
#include "fnv/decl/FUN_00558b40_shell.h"
#include "fnv/decl/FUN_00558b80_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_009604f0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/LodGrid.h"
#include "fnv/decl/ML.h"
#include "fnv/decl/ProcessLists.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00548880__FNV_Cell.h"
#include "fnv/decl/fnv_0054bc10__CellStub.h"
#include "fnv/decl/fnv_0054c740__FUN_0054c740_shell.h"
#include "fnv/decl/fnv_00550c60__FUN_00550c60_shell.h"
#include "fnv/decl/fnv_00558b60__FUN_00558b60_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00541000.h"
#include "fnv/symbols_0054f000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "tesobjectcell_packet_rtti2_tesobjectcell.h"
const char kTESObjectCELLCellRefLockEnter[] = "TESObjectCELL::CellRefLockEnter()";
NiAVObject* FUN_0054f4f0();

class TESFormB54
{
  public:
    int FUN_00401170();
};

class TESObjectREFRB54
{
  public:
    virtual void vf000();
    virtual void vf004();
    virtual void vf008();
    virtual void vf00c();
    virtual void vf010();
    virtual void vf014();
    virtual void vf018();
    virtual void vf01c();
    virtual void vf020();
    virtual void vf024();
    virtual void vf028();
    virtual void vf02c();
    virtual void vf030();
    virtual void vf034();
    virtual void vf038();
    virtual void vf03c();
    virtual void vf040();
    virtual void vf044();
    virtual void vf048();
    virtual void vf04c();
    virtual void vf050();
    virtual void vf054();
    virtual void vf058();
    virtual void vf05c();
    virtual void vf060();
    virtual void vf064();
    virtual void vf068();
    virtual void vf06c();
    virtual void vf070();
    virtual void vf074();
    virtual void vf078();
    virtual void vf07c();
    virtual void vf080();
    virtual void vf084();
    virtual void vf088();
    virtual void vf08c();
    virtual void vf090();
    virtual void vf094();
    virtual void vf098();
    virtual void vf09c();
    virtual void vf0a0();
    virtual void vf0a4();
    virtual void vf0a8();
    virtual void vf0ac();
    virtual void vf0b0();
    virtual void vf0b4();
    virtual void vf0b8();
    virtual void vf0bc();
    virtual void vf0c0();
    virtual void vf0c4();
    virtual void vf0c8();
    virtual void vf0cc();
    virtual void vf0d0();
    virtual void vf0d4();
    virtual void vf0d8();
    virtual void vf0dc();
    virtual void vf0e0();
    virtual void vf0e4();
    virtual void vf0e8();
    virtual void vf0ec();
    virtual void vf0f0();
    virtual void vf0f4();
    virtual void vf0f8();
    virtual void vf0fc();
    virtual bool IsVf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10c();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11c();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12c();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13c();
    virtual void vf140();
    virtual void vf144();
    virtual void vf148();
    virtual void vf14c();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15c();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16c();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17c();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18c();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19c();
    virtual void vf1a0();
    virtual void vf1a4();
    virtual void vf1a8();
    virtual void vf1ac();
    virtual void vf1b0();
    virtual void vf1b4();
    virtual void vf1b8();
    virtual void vf1bc();
    virtual void vf1c0();
    virtual void vf1c4();
    virtual void vf1c8();
    virtual void vf1cc();
    virtual int IsVf1d0();
    virtual void vf1d4();
    virtual void vf1d8();
    virtual void vf1dc();
    virtual void vf1e0();
    virtual void vf1e4();
    virtual void vf1e8();
    virtual void vf1ec();
    virtual void vf1f0();
    virtual void vf1f4();
    virtual void vf1f8();
    virtual void vf1fc();
    virtual void vf200();
    virtual void vf204();
    virtual void vf208();
    virtual void vf20c();
    virtual void vf210();
    virtual void vf214();
    virtual void vf218();
    virtual void vf21c();
    virtual void vf220();
    virtual bool IsVf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void Vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void Vf260();
};
class Actor : public TESObjectREFRB54
{
};

struct NiPoint3B54
{
    NiPoint3B54(float fX, int iY, int iZ);
    float x, y, z;
};
struct ControllerB54
{
};
struct NodeB54
{
};
class SceneB54;
struct ManagerB54
{
};
struct SettingsB54
{
};
struct ModeB54
{
};
struct ProcessListB54
{
};
struct LoaderB54
{
};

class SceneB54
{
  public:
    void FUN_0054bcf0(bool bArg);
};

// @fnv 0x0054bcf0
void SceneB54::FUN_0054bcf0(bool bArg)
{
    ControllerB54* pController2 = ((::ControllerB54 *)(reinterpret_cast<::FUN_00545cf0_Cls *>(this)->GetOrCreateWidget()));
    reinterpret_cast<::fnv_0054c740::FUN_0054c740_shell *>(this)->FUN_0054c740(0, 0);
    bool bState5 = reinterpret_cast<::CellShell *>(this)->FUN_0054df30();
    reinterpret_cast<::fnv_00550c60::FUN_00550c60_shell *>(this)->RecalcLeveledActorBases(bState5);
    if (reinterpret_cast<::FUN_00453490_shell *>((((ManagerB54*)(*reinterpret_cast<::ManagerB54 * *>(&::g_TES)))))->FUN_00453490((::TESObjectCELL *)(::SceneB54 *)(this)))
    {
        if (pController2)
        {
            NiPoint3B54 kPoint_(0.0f, 0, 0);
            reinterpret_cast<::FUN_00a59c60_cls *>((pController2))->FUN_00a59c60((std::intptr_t)(&kPoint_));
        }
        reinterpret_cast<::fnv_0054bc10::CellStub *>(this)->ProcessCellReferences();
    }
    else
    {
        reinterpret_cast<::TESObjectCELL *>(this)->CellRefLockEnter();
        int iPass4;
        void* pCell9 = ((void *)(reinterpret_cast<::LodGrid *>((((ManagerB54*)(*reinterpret_cast<::ManagerB54 * *>(&::g_TES)))))->FUN_00458be0((::LodCell *)(::SceneB54 *)(this), (::LodPoint *)(0))));
        NodeB54* pNode5 = ((::NodeB54 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
        int iCountA = 0;
        iPass4 = 0;
        while (iPass4 < 2 && pNode5)
        {
            TESObjectREFRB54* pRef = *((::TESObjectREFRB54 **)(new ((void *)(pNode5)) ::Vec3()));
            pNode5 = ((::NodeB54 *)(reinterpret_cast<::Callees *>((pNode5))->FUN_00726070()));
            if (!pNode5)
            {
                iPass4++;
                if (iPass4 < 2)
                    pNode5 = ((::NodeB54 *)(reinterpret_cast<::FUN_009604f0_shell *>(this)->FUN_009604f0()));
            }
            if (pRef)
            {
                bool bSpecial_2 = ((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430())) &&
                                  (((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430())) == (*reinterpret_cast<::TESFormB54 * *>(&::DAT_011ca238)) || ((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430())) == (*reinterpret_cast<::TESFormB54 * *>(&::DAT_011ca230)));
                if (iPass4 == 0 && !bSpecial_2)
                    continue;
                if (iPass4 == 1 && bSpecial_2)
                    continue;
                iCountA++;
                if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::SettingsB54 * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
                {
                    ::FUN_005ac190((::TESObjectREFR *)(pRef), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((pRef))->FUN_005d43c0()));
                    ::FUN_005ac750((::TESForm *)(pRef), (::ExtraDataList *)(void *)(reinterpret_cast<::FUN_005d43c0_ *>((pRef))->FUN_005d43c0()), 0x1000);
                }
                bool bDisabled4 = false;
                bDisabled4 = reinterpret_cast<::TESForm *>((pRef))->GetDisabled();
                if (!bDisabled4 && !reinterpret_cast<::FUN_00440d80_shell *>((pRef))->FUN_00440d80())
                {
                    if (pRef->IsVf100() && (!reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::ModeB54 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition() || reinterpret_cast<::FUN_0047c850 *>(((*reinterpret_cast<::ModeB54 * *>(&::g_TESSaveLoadGame))))->EvaluateCondition()))
                    {
                        Actor* pActor7 = dynamic_cast<Actor*>(reinterpret_cast< ::TESObjectREFR*>(pRef));
                        if (pActor7)
                        {
                            pActor7->Vf240();
                            reinterpret_cast<::ProcessLists *>((((ProcessListB54*)&(*reinterpret_cast<::ProcessListB54 *>(&::g_011e0e80)))))->RemoveMobileObjectFromList((::MobileObject *)(pActor7));
                        }
                    }
                    else if (pRef->IsVf224())
                    {
                        TESObjectREFRB54* pTarget = pRef;
                        pTarget->Vf260();
                    }
                    reinterpret_cast<::ML *>((((LoaderB54*)(*reinterpret_cast<::LoaderB54 * *>(&::g_modelLoader)))))->FUN_00444850((::Ref *)(pRef), (int)(pCell9), 0);
                    if (pRef->IsVf1d0())
                    {
                        bool bProcess3 = true;
                        if (((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430()))->FUN_00401170() == 0x23)
                        {
                            TESFormB54* pBase2 = ((::TESFormB54 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRef))->FUN_007af430()));
                            if (reinterpret_cast<::FUN_00452440_shell *>((pBase2))->FUN_00452440())
                                bProcess3 = false;
                        }
                        if (bProcess3)
                            reinterpret_cast<::fnv_00548880::FNV_Cell *>(this)->FUN_00548880((::fnv_00548880::FNV_Ref *)(pRef), 0);
                    }
                }
            }
        }
        ::FUN_00541ae0((char *)this);
    }
    if (bArg)
        reinterpret_cast<::FUN_005535f0_shell *>(this)->FUN_005535f0();
    reinterpret_cast<::FUN_004512a0_shell *>(this)->SetState(6);
}
