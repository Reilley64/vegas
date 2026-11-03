// src/fallout/ai/lowprocess_rtm_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout/ai/lowprocess.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /Od /Oy- /GS /EHsc /Gy /GF (unit lists /MT /Od /Oy- /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton.

#include <new>
#include "fnv/decl/AIFormFlags.h"
#include "fnv/decl/ActorGoldQuery.h"
#include "fnv/decl/ActorInventoryQueryViews__ActorQuery.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/B_008b3630.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatTargetTimestamp.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_0041c8d0_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_0046f070_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00568680_shell.h"
#include "fnv/decl/FUN_00569160_shell.h"
#include "fnv/decl/FUN_00569250_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_00575770_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005c1a00.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/FUN_00621b00_shell.h"
#include "fnv/decl/FUN_00672930_cls.h"
#include "fnv/decl/FUN_00672dd0_shell.h"
#include "fnv/decl/FUN_00672f20_cls.h"
#include "fnv/decl/FUN_00674e70_Shell.h"
#include "fnv/decl/FUN_006757e0_shell.h"
#include "fnv/decl/FUN_00675830_shell.h"
#include "fnv/decl/FUN_00678ec0_shell.h"
#include "fnv/decl/FUN_0067a480_shell.h"
#include "fnv/decl/FUN_0067efd0_shell.h"
#include "fnv/decl/FUN_0067f430_shell.h"
#include "fnv/decl/FUN_0067f480_shell.h"
#include "fnv/decl/FUN_0067f970_shell.h"
#include "fnv/decl/FUN_0083c850.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00881450_shell.h"
#include "fnv/decl/FUN_00884f80_shell.h"
#include "fnv/decl/FUN_008ad910_cls.h"
#include "fnv/decl/FUN_008b36f0_cls.h"
#include "fnv/decl/FUN_008b3b90_shell.h"
#include "fnv/decl/FUN_008b3bf0_shell.h"
#include "fnv/decl/FUN_008c6130_shell.h"
#include "fnv/decl/FUN_008d7e00_shell.h"
#include "fnv/decl/FUN_008d7e60_shell.h"
#include "fnv/decl/FUN_008e30e0_Class.h"
#include "fnv/decl/FUN_008e3100_class.h"
#include "fnv/decl/FUN_008e3120_This.h"
#include "fnv/decl/FUN_008e7c50_cls.h"
#include "fnv/decl/FUN_00903cd0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_00937b30_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00962720_shell.h"
#include "fnv/decl/FUN_009f2ba0_shell.h"
#include "fnv/decl/FUN_009f3390_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/PatrolData.h"
#include "fnv/decl/Proxy758a0.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/Reference.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/State.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TESCombatStyle.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00421310__FUN_00421310_shell.h"
#include "fnv/decl/fnv_00564db0__FUN_00564db0_cls.h"
#include "fnv/decl/fnv_00565870__FUN_00565870_shell.h"
#include "fnv/decl/fnv_005692a0__FUN_005692a0_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_0057ace0__FUN_0057ace0_shell.h"
#include "fnv/decl/fnv_0057ad20__FUN_0057ad20_shell.h"
#include "fnv/decl/fnv_0057bd60__fnv_anon_tesobjectrefr__Dummy.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/decl/fnv_00674f30__FUN_00674f30_shell.h"
#include "fnv/decl/fnv_00675a50__FUN_00675a50_shell.h"
#include "fnv/decl/fnv_00675c20__PHost.h"
#include "fnv/decl/fnv_00676140__FUN_00676140_shell.h"
#include "fnv/decl/fnv_006780e0__TESPackageExt.h"
#include "fnv/decl/fnv_00678670__FUN_00678670_shell.h"
#include "fnv/decl/fnv_006787e0__Package.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00881470__FUN_00881470_shell.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_008a0b10__FUN_008a0b10_shell.h"
#include "fnv/decl/fnv_008a6a40__TargetActor.h"
#include "fnv/decl/fnv_008a8f60__FUN_008a8f60_shell.h"
#include "fnv/decl/fnv_008b3690__TES.h"
#include "fnv/decl/fnv_008b3880__FUN_008b3880_target.h"
#include "fnv/decl/fnv_008b3d30__FUN_008b3d30_shell.h"
#include "fnv/decl/fnv_00903e00__FUN_00903e00_shell.h"
#include "fnv/decl/fnv_00903e20__FUN_00903e20_shell.h"
#include "fnv/decl/fnv_00937c60__ModifierList_h.h"
#include "fnv/decl/fnv_00962620__FUN_00962620_cls.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/decl/s56ae10__Owner.h"
#include "fnv/decl/xPkg.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00464000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_00573000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00884000.h"
#include "fnv/symbols_008a6000.h"
#include "fnv/symbols_008b1000.h"
#include "fnv/symbols_008e7000.h"
#include "fnv/symbols_00903000.h"
#include "fnv/symbols_0090d000.h"
#include "fnv/symbols_0090e000.h"
#include "fnv/symbols_00936000.h"
#include "fnv/symbols_0096a000.h"
#include "fnv/symbols_009f2000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01013000.h"
#include "fnv/symbols_01018000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_0119b000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "lowprocess_decls.h"

__if_not_exists(TESNPC::InitWornForm)
{
    class TESNPC : public ::TESBoundObject
    {
      public:
        void InitWornForm(::Actor*, ::ValidBip01Names*, bool);
    };
}

namespace acquire907_rework {
using ::TESForm;
using ::TESObjectREFR;
using ::TESBoundObject;

class AcquireBase907;

class Acq907
{
  public:
    TESObjectREFR* pObject;    // 0x00
    TESBoundObject* pItem;     // 0x04
    bool bActivate;            // 0x08
    bool m_bUseSpecialAction;  // 0x09
    unsigned short unk0A;
    int iA;     // 0x0c
    int iB;     // 0x10
    int iC;     // 0x14
    int eType;  // 0x18
    ~Acq907();
};

class List907
{
  public:
    Acq907* m_item;
    List907* m_pkNext;
};

class Shell8e
{
  public:
};

class Act907
{
  public:
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual bool v21c();

};

class ProjSub907
{
  public:
};

class AcquireBase907
{
  public:
    unsigned int unk00;
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
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    ProjSub907 sub90;
};

class Ref907
{
  public:
};

class Projectile907
{
  public:
};

class Proc907 : public ::LowProcess
{
  public:
    void FUN_00907d90(Act907* arg);
};


// @fnv 0x00907d90
void Proc907::FUN_00907d90(Act907* arg)
{
    List907* itF = reinterpret_cast<List907*>(&this->m_kDetectionDataList);
    Shell8e* pkg_h = (Shell8e*)this->vfn_27c();
    bool bA7 = pkg_h ? reinterpret_cast<::FUN_008e30e0_Class *>((pkg_h))->FUN_008e30e0() : false;
    bool bBI = pkg_h ? reinterpret_cast<::FUN_008e3120_This *>((pkg_h))->IsFlag400Set() : false;
    bool bCB = pkg_h ? reinterpret_cast<::FUN_008e3100_class *>((pkg_h))->FUN_008e3100() : false;
    bool bDoneZ;

    while (itF != 0 && ((::acquire907_rework::Acq907 *)(new ((void *)(itF)) ::Vec3())))
    {
        Acq907* pNodeM = ((::acquire907_rework::Acq907 *)(new ((void *)(itF)) ::Vec3()));
        TESObjectREFR* pRefA = pNodeM->pObject;
        TESObjectREFR* pOther3 = 0;
        TESBoundObject* pItemR = pNodeM->pItem;
        Act907* actor_p;
        bool bValid7;

        actor_p = pRefA->IsActor() ? (Act907*)pRefA : 0;
        bDoneZ = false;
        bValid7 = true;
        if (actor_p)
        {
            if (reinterpret_cast<::MiddleHighProcess *>((actor_p))->IsActorInCombat())
                bValid7 = false;
        }

        if ((reinterpret_cast<::OwnerLookupView *>((pRefA))->FUN_00567790() && reinterpret_cast<::OwnerLookupView *>((pRefA))->FUN_00567790() != ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((arg))->FUN_007af430()))) || pRefA->IsActor())
        {
            bool b313 = false;
            bool b32Ptr = false;
            int nG = ::FUN_0048e8a0((::TESForm *)(pItemR));
            TESNPC* pNPCA = 0;

            if (!pRefA->vfn_22c(false) && reinterpret_cast<::ActorGoldQuery *>((arg))->FUN_00891d70() >= nG)
            {
                Projectile907* pProjQ = 0;
                if (pRefA->vfn_218())
                {
                    pProjQ = (Projectile907*)pRefA;
                }
                else
                {
                    pNPCA = dynamic_cast<TESNPC*>(reinterpret_cast<::OwnerLookupView *>((pRefA))->FUN_00567790());
                    if (pNPCA)
                        pProjQ = (Projectile907*)(*(<dependent type> *)(reinterpret_cast<::Holder *>(&((*reinterpret_cast<::TESValueForm *>(&::g_011e0e80))))->FUN_00970a20(pNPCA, false)));
                }
                if (pProjQ && bA7 && reinterpret_cast<::AIFormFlags *>(&(((::acquire907_rework::AcquireBase907 *)(reinterpret_cast<::Actor *>((void *)(pProjQ))->GetActorBase()))->sub90))->FUN_0047f600((::TESForm *)(pItemR)))
                {
                    if (!((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((arg))->FUN_00493bb0())))
                    {
                        pNodeM->eType = 2;
                        pNodeM->iB = (int)reinterpret_cast<::RefS *>((arg))->FUN_005723b0((::RefS *)(pRefA), 0, 0);
                        bDoneZ = true;
                    }
                    else
                    {
                        bValid7 = false;
                    }
                }
            }

            if (!bDoneZ && !(actor_p && reinterpret_cast<::MiddleHighProcess *>((actor_p))->IsActorInCombat()))
            {
                if (!pRefA->IsActor())
                {
                    if (bBI)
                        b313 = true;
                }
                else if (pRefA->vfn_22c(false))
                {
                    bValid7 = true;
                }
                else if (pRefA->vfn_218())
                {
                    pOther3 = pRefA;
                    if (bBI)
                        b313 = true;
                    if (bCB)
                        b32Ptr = true;
                }

                if ((b313 || b32Ptr) && !(actor_p && reinterpret_cast<::MiddleHighProcess *>((actor_p))->IsActorInCombat()))
                {
                    if (!pRefA->IsActor())
                    {
                        if (pNodeM->eType == 1)
                        {
                            int x = 0;
                            pNodeM->eType = 4;
                            bool okD = reinterpret_cast<::ActorInventoryQueryViews::ActorQuery *>((arg))->FUN_00891db0(::g_pLockpickItem, 0, 1, 0, (*(int *)(&x)));
                            if (!okD && ((int)(reinterpret_cast<::FUN_00569160_shell *>((((Ref907*)pRefA)))->FUN_00569160())))
                                bValid7 = false;
                        }
                        else
                        {
                            pNodeM->eType = 3;
                        }
                    }
                    else if (b313)
                    {
                        if (!((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((arg))->FUN_00493bb0())))
                        {
                            pNodeM->eType = 4;
                        }
                        else
                        {
                            bValid7 = false;
                        }
                    }
                    else if (b32Ptr)
                    {
                        if (!((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((arg))->FUN_00493bb0())) && !reinterpret_cast<::MiddleHighProcess *>((arg))->IsActorInCombat())
                        {
                            if (!actor_p || (actor_p && !reinterpret_cast<::MiddleHighProcess *>((actor_p))->IsActorInCombat()))
                                pNodeM->eType = 5;
                        }
                        else
                        {
                            bValid7 = false;
                        }
                    }
                    pNodeM->bActivate = b313;
                    pNodeM->m_bUseSpecialAction = b32Ptr;
                }
                else
                {
                    if (arg->v21c())
                    {
                        bValid7 = false;
                    }
                    else if (pRefA->IsActor() && !pRefA->vfn_218() && reinterpret_cast<::OwnerLookupView *>((pRefA))->FUN_00567790() != ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((arg))->FUN_007af430())) &&
                             !reinterpret_cast<::MiddleHighProcess *>((arg))->IsActorInCombat())
                    {
                        if (actor_p && !reinterpret_cast<::MiddleHighProcess *>((actor_p))->IsActorInCombat())
                        {
                            pNodeM->eType = 5;
                            bValid7 = true;
                        }
                    }
                    else
                    {
                        bValid7 = false;
                    }
                }
            }
        }
        else
        {
            pNodeM->iB = (int)reinterpret_cast<::RefS *>((arg))->FUN_005723b0((::RefS *)(pRefA), 0, 0);
        }

        if (bValid7)
        {
            reinterpret_cast<::fnv_00564db0::FUN_00564db0_cls *>((pNodeM->pObject))->FUN_00564db0(true);
            reinterpret_cast<::Callees *>(&(reinterpret_cast<List907&>(this->ReferenceListNode)))->FUN_00905820((void *)&(pNodeM));
        }
        else
        {
            delete reinterpret_cast< ::TargetDoorController*>(pNodeM);
        }
        itF = ((::acquire907_rework::List907 *)(reinterpret_cast<::Callees *>((itF))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>(&(reinterpret_cast<List907&>(this->m_kDetectionDataList)))->RemoveAll();
}

}
