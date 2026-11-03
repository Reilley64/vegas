// fallout/ai/actor_magic.cpp: Actor, ActorStandIn, SummonOwner, Controller and more (40 functions)

#include <new>
#include <cstdio>
#include "fnv/decl/ActionOwner.h"
#include "fnv/decl/ActorSoundStub.h"
#include "fnv/decl/ActorX.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/B88B5A0Actor.h"
#include "fnv/decl/B8B10Owner.h"
#include "fnv/decl/B968730Actor.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSDehydrationStage.h"
#include "fnv/decl/BGSRadiationStage.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSAnimGroupSequence.h"
#include "fnv/decl/BSFaceGenMorphData.h"
#include "fnv/decl/BSFadeNode.h"
#include "fnv/decl/BSOcclusionPlane.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CastingCheck.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/Dummy_0056c7d0.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00409700_Class.h"
#include "fnv/decl/FUN_00418770_shell.h"
#include "fnv/decl/FUN_0041aed0_shell.h"
#include "fnv/decl/FUN_00422820_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_00439ef0_class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00453470_shell.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004543c0_cls.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00460250_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00491040_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_0049bb50_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004a39f0_shell.h"
#include "fnv/decl/FUN_004a3c20.h"
#include "fnv/decl/FUN_004a3eb0_shell.h"
#include "fnv/decl/FUN_004def90_Class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004fd380_shell.h"
#include "fnv/decl/FUN_00508100_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_005471e0_shell.h"
#include "fnv/decl/FUN_005673e0_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_0057b0a0_shell.h"
#include "fnv/decl/FUN_0059ce80_shell.h"
#include "fnv/decl/FUN_0059ceb0_shell.h"
#include "fnv/decl/FUN_005a2030_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005dbf20.h"
#include "fnv/decl/FUN_00619a70_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/FUN_00626660_Class.h"
#include "fnv/decl/FUN_00632ce0_Class.h"
#include "fnv/decl/FUN_00644930_shell.h"
#include "fnv/decl/FUN_0068a810_class.h"
#include "fnv/decl/FUN_0081c470_shell.h"
#include "fnv/decl/FUN_008248e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087afa0_Holder.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_0087faa0_shell.h"
#include "fnv/decl/FUN_00881650_shell.h"
#include "fnv/decl/FUN_008845a0_shell.h"
#include "fnv/decl/FUN_008854d0_.h"
#include "fnv/decl/FUN_0088b510_cls.h"
#include "fnv/decl/FUN_0088c570_shell.h"
#include "fnv/decl/FUN_0088c650_shell.h"
#include "fnv/decl/FUN_00893500_shell.h"
#include "fnv/decl/FUN_008a16d0_shell.h"
#include "fnv/decl/FUN_008aced0_cls.h"
#include "fnv/decl/FUN_008adcb0_shell.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_00935a40_cls.h"
#include "fnv/decl/FUN_0094c950_shell.h"
#include "fnv/decl/FUN_00950bb0_shell.h"
#include "fnv/decl/FUN_0096d490_shell.h"
#include "fnv/decl/FUN_0098adb0_shell.h"
#include "fnv/decl/FUN_009acce0_shell.h"
#include "fnv/decl/FUN_009b2c90_class.h"
#include "fnv/decl/FUN_00ad8570_S.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FlaggedData.h"
#include "fnv/decl/FloatValueProvider.h"
#include "fnv/decl/Handler.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Host00881620.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/LocationDescriptor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicEffectCollection.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/NiNode.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/PackageEx.h"
#include "fnv/decl/PathingRequest.h"
#include "fnv/decl/PlayerCharacter_StandIn.h"
#include "fnv/decl/Point3Offset.h"
#include "fnv/decl/RefS.h"
#include "fnv/decl/RestoreActionPointsDetail__RestoreActionPointsEntry.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S00628640_Vector.h"
#include "fnv/decl/S219c0.h"
#include "fnv/decl/S3e60.h"
#include "fnv/decl/S_00627920.h"
#include "fnv/decl/ScriptLocals.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TES.h"
#include "fnv/decl/TESCallHelper.h"
#include "fnv/decl/TESObjectWEAP.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/Target96.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TopicFlagStandIn.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/UnloadMagic.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/VecHolder.h"
#include "fnv/decl/W004702f0.h"
#include "fnv/decl/bhkCharacterController.h"
#include "fnv/decl/fnv_0040ff60__FUN_0040ff60_shell.h"
#include "fnv/decl/fnv_00410220__FUN_00410220_shell.h"
#include "fnv/decl/fnv_00418940__FUN_00418940_shell.h"
#include "fnv/decl/fnv_00419700__FUN_00419700_shell.h"
#include "fnv/decl/fnv_0041a090__FUN_0041a090_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004518e0__TESObjectCELL.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_004a3a20__FUN_004a3a20_shell.h"
#include "fnv/decl/fnv_004a3da0__FUN_004a3da0_shell.h"
#include "fnv/decl/fnv_004bda70__FUN_004bda70_shell.h"
#include "fnv/decl/fnv_005653d0__FUN_005653d0_shell.h"
#include "fnv/decl/fnv_00567400__FUN_00567400_shell.h"
#include "fnv/decl/fnv_00572d30__FUN_00572d30_shell.h"
#include "fnv/decl/fnv_00576260__FUN_00576260_shell.h"
#include "fnv/decl/fnv_00671d30__FUN_00671d30_shell.h"
#include "fnv/decl/fnv_006777b0__FUN_006777b0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00804210__ActiveEffectUpdateShell.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/decl/fnv_008853a0__FUN_008853a0_shell.h"
#include "fnv/decl/fnv_00887d00__InitActor.h"
#include "fnv/decl/fnv_008be940__FloatValueProvider.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00421000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00499000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_00525000.h"
#include "fnv/symbols_00553000.h"
#include "fnv/symbols_0056f000.h"
#include "fnv/symbols_005ac000.h"
#include "fnv/symbols_005b9000.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00643000.h"
#include "fnv/symbols_00646000.h"
#include "fnv/symbols_00653000.h"
#include "fnv/symbols_0066f000.h"
#include "fnv/symbols_00670000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00804000.h"
#include "fnv/symbols_00892000.h"
#include "fnv/symbols_008bc000.h"
#include "fnv/symbols_008c7000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_01024000.h"
#include "fnv/symbols_01029000.h"
#include "fnv/symbols_0103a000.h"
#include "fnv/symbols_0104b000.h"
#include "fnv/symbols_011a3000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f3000.h"
#include "actor_magic_decls.h"
#include "actor_magic_actor.h"
#include "BaseProcess.h"

// HighProcess call targets used by actor magic (canonical HighProcess
// header has no method declarations yet; only calls are emitted here,
// so no layout is required).
class HighProcess
{
  public:
};

class NiNode;

struct BSShaderRenderUtility
{
    static void SetAlphaOnNode(NiNode* pNode, float fAlpha);
public:
    bool IsRenderTargetId(unsigned int);
};

// Node getter behind 0x00950bb0. It reads a node pointer at +0x694, which
// only exists on PlayerCharacter-sized objects, so it is declared here on
// a minimal PlayerCharacter until its canonical home is confirmed.
class PlayerCharacter
{
  public:
    NiNode* GetNode(bool bFirstPerson);
};

// @fnv 0x00961de0
void Actor::SetAlphaAndFade(float fAlpha)
{
    Actor::SetAlpha(fAlpha);
    NiNode* pNode = ((::NiNode *)(reinterpret_cast<::FUN_00950bb0_shell *>((((PlayerCharacter*)this)))->FUN_00950bb0(true)));
    if (pNode)
        BSShaderRenderUtility::SetAlphaOnNode(pNode, fAlpha);
}

// @fnv 0x008a1800
void Actor::SetActorLifeState(ACTOR_LIFE_STATE state)
{
    if (*(bool*)(*reinterpret_cast<::ProcessLists *>(&::g_011e0888)).GetLifeStateControlFlag() && reinterpret_cast<::FUN_0087f3d0_shell *>(this)->FUN_0087f3d0() && (state == 2 || state == 1))
        state = (ACTOR_LIFE_STATE)6;
    if (state == 6 && !reinterpret_cast<::FUN_008845a0_shell *>(this)->FUN_008845a0())
        state = (ACTOR_LIFE_STATE)0;
    if (m_eLifeState == 0 && (state == 1 || state == 2 || state == 6))
        reinterpret_cast<::FUN_008b3ab0_shell *>(this)->FUN_008b3ab0();
    if (state == 2)
    {
        BSFaceGenAnimationData* inventory = reinterpret_cast<::FUN_008adcb0_shell *>(this)->FUN_008adcb0();
        if (inventory)
            inventory->vfn_d8(true, true);
        InventoryChanges* sound = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))->GetContainerChangeData();
        if (sound)
            reinterpret_cast<::FUN_004534f0_shell *>((((MagicCaster*)sound)))->FUN_004534f0((unsigned int)((MagicItem*)this));
        SoundPlaybackHandle face;
        reinterpret_cast<::fnv_00418940::FUN_00418940_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_00418940((::fnv_00418940::SoundPlaybackHandle *)(::SoundPlaybackHandle *)(&face));
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(face))->FUN_00ad88f0();
        face.Release();
        reinterpret_cast<::fnv_0041a090::FUN_0041a090_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->FUN_0041a090(&face);
        reinterpret_cast<::FUN_00ad8570_S *>((::FUN_00453a70()))->FUN_00ad8570((int)(((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>(this)->FUN_0043fcd0()))), 0.0f, false);
    }
    if (state != 0 && m_pBaseProcess && ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)m_pBaseProcess)))->FUN_0045cd60())) == 0)
    {
        ActorMagicProcess* process = (ActorMagicProcess*)m_pBaseProcess;
        if (process->GetCurrentFadeState() == 3 || process->GetCurrentFadeState() == 4)
            reinterpret_cast<::C *>((((HighProcess*)process)))->SetContentCount((int)(this), false);
    }
    if (m_eLifeState != state)
        MarkAsModified(0x400);
    ACTOR_LIFE_STATE old = m_eLifeState;
    m_eLifeState = state;
    if (old != m_eLifeState && ((old == 2 && m_eLifeState != 1) || m_eLifeState == 2))
        reinterpret_cast<::fnv_00887d00::InitActor *>(this)->FUN_00887d00();
}

// @fnv 0x008c2e50
void Actor::AddDefaultSpells()
{
    BSSimpleList<SpellItem*>* defaultForm = ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::BaseProcess *>(&(GetActorBase()->spells))->GetCurrentProcessData()));
    while (defaultForm)
    {
        SpellItem* spell = ((::SpellItem *)(new ((void *)(defaultForm)) ::Vec3()));
        if (spell && ::FUN_00804b30((int)(spell->vfn_18())))
            spell->Preload(false);
        defaultForm = ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::Callees *>((defaultForm))->FUN_00726070()));
    }
    defaultForm = GetRace() ? ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::BaseProcess *>(&(GetRace()->spells))->GetCurrentProcessData())) : 0;
    while (defaultForm)
    {
        SpellItem* raceSpell = ((::SpellItem *)(new ((void *)(defaultForm)) ::Vec3()));
        if (raceSpell && ::FUN_00804b30((int)(raceSpell->vfn_18())))
            raceSpell->Preload(false);
        defaultForm = ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::Callees *>((defaultForm))->FUN_00726070()));
    }
    InventoryChanges* inventory = ::InventoryChanges::CreateForReference(this);
    for (unsigned int index = 0; index < 5; ++index)
    {
        InventoryStackRecord* item = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((inventory))->FUN_004c8c10((*(int *)&(DAT_011a337c[index])), false)));
        TESEnchantableForm* enchantment = item ? dynamic_cast<TESEnchantableForm*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((item))->GetName()))) : 0;
        SpellItem* enchantable = enchantment ? (SpellItem*)((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<SpellItem*>*)enchantment)))->FUN_00726070())) : 0;
        if (enchantable)
            enchantable->Preload(false);
        delete item;
    }
    TESForm* spells = ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(19));
    if (spells)
    {
        SpellItem* defaultSpell = dynamic_cast<SpellItem*>(spells);
        if (defaultSpell && ::FUN_00804b30((int)(defaultSpell->vfn_18())))
            defaultSpell->Preload(false);
    }
}

struct FUN_008c4560_shell : public Actor
{
    bool FUN_008c4560();
};

struct BaseProcessVtbl
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual bool UpdateIdleAnimation();
};

// @fnv 0x008c4560
bool FUN_008c4560_shell::FUN_008c4560()
{
    return ((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())) ? reinterpret_cast<BaseProcessVtbl*>(((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))->UpdateIdleAnimation() : false;
}

struct FUN_008c47d0_shell : public HighProcess
{
    void FUN_008c47d0(float);
};
// If the actor's high process exists and is at process level 0, forwards fAlpha to its SetMaxAlpha.
// @fnv 0x008c4790
void Actor::SetAlpha(float fAlpha)
{
    if (m_pBaseProcess && ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)m_pBaseProcess)))->FUN_0045cd60())) == 0)
        reinterpret_cast<::FUN_008c47d0_shell *>((((HighProcess*)m_pBaseProcess)))->FUN_008c47d0(fAlpha);
}

// @fnv 0x008c47d0
void FUN_008c47d0_shell::FUN_008c47d0(float afAlpha)
{
    *(float*)((char*)this + 0x2b0) = afAlpha;
}

struct FUN_008c51c0_shell : public Actor
{
    bool FUN_008c51c0();
};
// Computes the actor's alpha from process fade/invisibility values, applies the player multiplier, and calls SetAlpha or Unk_E1.
// @fnv 0x008c4640
void Actor::UpdateActorPresentation()
{
    if (FUN_005b9b00() && reinterpret_cast<::FUN_008c51c0_shell *>(this)->FUN_008c51c0())
    {
        Unk_E1(true, reinterpret_cast<::FUN_00422820_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()))))->GetRefractionProperty()->alpha);
    }
    else
    {
        float processAlpha = 1.0f;
        bool invisAlpha = false;
        float invisible = invisAlpha ? 0.0f : 1.0f;
        float fade = 1.0f;
        float alpha = 1.0f;
        if (m_pBaseProcess && ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((HighProcess*)m_pBaseProcess)))->FUN_0045cd60())) == 0)
        {
            alpha = ((ActorMagicProcess*)m_pBaseProcess)->GetFadeAlpha();
            fade = ::GetField3EC((char *)(((ActorMagicProcess*)m_pBaseProcess)));
            if (((ActorMagicProcess*)m_pBaseProcess)->GetCurrentFadeState() == 2)
                invisible = 1.0f;
        }
        float base = processAlpha * invisible * fade * alpha;
        if (this == (Actor*)::_g_thePlayer)
        {
            if (invisAlpha && base < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1165))))))->f)
                base = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1165))))))->f;
            base *= DAT_011a3b38;
        }
        SetAlpha(base);
    }
}

// @fnv 0x008c51c0
bool FUN_008c51c0_shell::FUN_008c51c0()
{
    ExtraDataList* pextraDataList = ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0()));
    if (pextraDataList && reinterpret_cast<::FUN_00422820_shell *>((pextraDataList))->GetRefractionProperty())
        return true;
    return false;
}

class GlobalObject_0040e0b0 : public SettingT_GameSettingCollection_
{
};
extern GlobalObject_0040e0b0 g_011c36d8;

// @fnv 0x0040df50
float FUN_0040df50()
{
    return ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(g_011c36d8))))->f;
}

// Returns true when aeType is 1, 4 or 10.
// @fnv 0x00804b30
bool FUN_00804b30(int aeType)
{
    return aeType == 1 || aeType == 4 || aeType == 10;
}


struct FUN_0088b850_shell
{
    void SetRefractionProperty();
};

// Calls FUN_006463e0 with the float value of originalRuntimeFloatSetting588.
// @fnv 0x0088b850
void FUN_0088b850_shell::SetRefractionProperty()
{
    ::FUN_006463e0(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting588))))))->f);
}

struct FUN_008c5330_shell
{
    void ClearField4C();
};
// @fnv 0x008c5330
void FUN_008c5330_shell::ClearField4C()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x4c) = 0;
}

struct FUN_008d4a80_shell
{
    int FUN_008d4a80(int);
};
struct FUN_00880580_shell
{
    void FUN_00880580(int);
    void FUN_008d4840(int a);
};
// Calls FUN_008d4a80 on the object at this-0xa4 with a, then passes the result to FUN_00880580.
// @fnv 0x008d4840
void FUN_00880580_shell::FUN_008d4840(int a)
{
    FUN_00880580(reinterpret_cast<FUN_008d4a80_shell*>(reinterpret_cast<char*>(this) - 0xa4)->FUN_008d4a80(a));
}

struct PCStub
{
    float GetActorValueModifierAmount(int, int);
};
struct FUN_0094c490_t
{
    float FUN_0094c490(int param_1);
};
// Forwards to the PCStub at this-0xA4, calling its method with arguments 2 and param_1 and returning the float result.
// @fnv 0x0094c490
float FUN_0094c490_t::FUN_0094c490(int param_1)
{
    return ((PCStub*)((char*)this - 0xA4))->GetActorValueModifierAmount(2, param_1);
}

namespace fnv_0094c4c0 {
struct PCStub
{
    float GetActorValueModifierAmount(int, ActorValue::Index);
};
struct FUN_0094c4c0_t
{
    float FUN_0094c4c0(ActorValue::Index);
};
// Reads an actor value by index from the owning object via a stub call with mode 1.
// @fnv 0x0094c4c0
float FUN_0094c4c0_t::FUN_0094c4c0(ActorValue::Index aeActorValue)
{
    return ((PCStub*)((char*)this - 0xA4))->GetActorValueModifierAmount(1, aeActorValue);
}
}  // namespace fnv_0094c4c0

struct FUN_009b28a0_efx
{
    void* m_pEffectInstance;
    char pad[2];
    char f6;
};
struct FUN_009b28a0_node
{
    bool FUN_008256d0();
};
struct FUN_009b28a0_t
{
    char pad[0xa4];
    FUN_009b28a0_node list;
    void FUN_009b28a0(unsigned int c);
};

class MagicProcVt
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual void vfn_1f4();
    virtual void vfn_1f8();
    virtual void vfn_1fc();
    virtual void vfn_200();
    virtual void vfn_204();
    virtual void vfn_208();
    virtual void vfn_20c();
    virtual void vfn_210();
    virtual void vfn_214();
    virtual void vfn_218();
    virtual void vfn_21c();
    virtual void vfn_220();
    virtual void vfn_224();
    virtual void vfn_228();
    virtual void vfn_22c();
    virtual void vfn_230();
    virtual void vfn_234();
    virtual void vfn_238();
    virtual void vfn_23c();
    virtual void vfn_240();
    virtual void vfn_244();
    virtual void vfn_248();
    virtual void vfn_24c();
    virtual void vfn_250();
    virtual void vfn_254();
    virtual void vfn_258();
    virtual void vfn_25c();
    virtual void vfn_260();
    virtual void vfn_264();
    virtual void vfn_268();
    virtual void vfn_26c();
    virtual void vfn_270();
    virtual void vfn_274();
    virtual void vfn_278();
    virtual void vfn_27c();
    virtual void vfn_280();
    virtual void vfn_284();
    virtual void vfn_288();
    virtual void vfn_28c();
    virtual void vfn_290();
    virtual void vfn_294();
    virtual void vfn_298();
    virtual void vfn_29c();
    virtual void vfn_2a0();
    virtual void vfn_2a4();
    virtual void vfn_2a8();
    virtual void vfn_2ac();
    virtual void vfn_2b0();
    virtual void vfn_2b4();
    virtual void vfn_2b8();
    virtual void vfn_2bc();
    virtual void vfn_2c0();
    virtual void vfn_2c4();
    virtual void vfn_2c8();
    virtual void vfn_2cc();
    virtual void vfn_2d0();
    virtual void vfn_2d4();
    virtual void vfn_2d8();
    virtual void vfn_2dc();
    virtual void vfn_2e0();
    virtual void vfn_2e4();
    virtual void vfn_2e8();
    virtual void vfn_2ec();
    virtual void vfn_2f0();
    virtual void vfn_2f4(void* a, int b, int c);
    virtual void vfn_2f8();
};

struct FUN_006777b0_class
{
};

class FUN_008985d0_shell : public MagicProcVt
{
  public:
    int FUN_00931850();
    void FUN_008985d0();
};

struct FUN_008c1de0_comp
{
    int unk00;
};
struct FUN_008c1de0_mid : public TESForm
{
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};
struct FUN_008c1de0_item : public FUN_008c1de0_mid, public FUN_008c1de0_comp
{
};
class TESSound;
class AlchemyItem : public TESBoundObject, public MagicItem
{
public:
    void SetSound(::TESSound *);
};
// @fnv 0x009b28a0
void FUN_009b28a0_t::FUN_009b28a0(unsigned int c)
{
    if (reinterpret_cast<::FUN_009acce0_shell *>(this)->GetFieldC8() == c)
        reinterpret_cast<::AlchemyItem *>(this)->SetSound((::TESSound *)(void *)(0));
    if (reinterpret_cast<::BSFadeNode *>(this)->FUN_009ad610() == c)
        reinterpret_cast<::Dummy_0056c7d0 *>(this)->FUN_0056c7d0(0);
    FUN_009b28a0_node* pNode = &list;
    while (pNode && !pNode->FUN_008256d0())
    {
        FUN_009b28a0_efx* peffect;
        FUN_009b28a0_node* m_pActionSuccessor = ((::FUN_009b28a0_node *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
        peffect = *((::FUN_009b28a0_efx **)(new ((void *)(pNode)) ::Vec3()));
        if (peffect && (unsigned int)peffect->m_pEffectInstance == c)
        {
            peffect->f6 = 1;
            peffect->m_pEffectInstance = 0;
        }
        pNode = m_pActionSuccessor;
    }
}
struct FUN_00815380_shell : public MagicCaster
{
};
struct ActorConsumeShell : public MobileObject, public FUN_00815380_shell
{
    void FUN_008c2090(MagicItem* pItem, bool bApply);
};

struct FUN_008c1de0_player
{
};
struct TESSaveLoadGame
{
};
class GlobalObject_0040c150
{
  public:
};
struct FUN_008c1de0_shell : public Actor
{
    void FUN_008c1de0(TESForm* pItem, ExtraDataList* pExtra, bool bSilent);
};

// @fnv 0x008c1de0
void FUN_008c1de0_shell::FUN_008c1de0(TESForm* pItem, ExtraDataList* pExtra, bool bSilent)
{
    if (!pItem)
    {
        return;
    }
    if (pItem->IsQuestItem())
    {
        if (this == (Actor*)::_g_thePlayer)
        {
            ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::StartMenu *>(&(g_011d39fc))->GetMenuTitle()))), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_sad.dds"), (const char *)(0),
                           2.0, false);
        }
        return;
    }
    if (!reinterpret_cast<::FUN_0047c850 *>((g_TESSaveLoadGame))->EvaluateCondition())
    {
        FUN_005ac750(this, pExtra, 2);
        FUN_005ac750(pItem, ((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>(this)->FUN_005d43c0())), 2);
    }
    FUN_008c1de0_comp* pComp = 0;
    if (pItem->Unk_3B())
    {
        FUN_008c1de0_item* pItemForm = (FUN_008c1de0_item*)pItem;
        pComp = pItemForm;
    }
    if (this != (Actor*)::_g_thePlayer || bSilent)
    {
        SetCurrentSpellState((int)pComp);
        reinterpret_cast<::CastingCheck *>((reinterpret_cast<FUN_00815380_shell*>(static_cast<MagicCaster *>(this))))->TryCast((::TESBoundObject *)(0));
        if (this != (Actor*)::_g_thePlayer)
        {
            RemoveItem(pItem, pExtra, 1, 0, 0, 0, 0, 0, 1, 0);
        }
    }
    else
    {
        if (reinterpret_cast<::PlayerCharacter_StandIn *>((((FUN_008c1de0_player*)::_g_thePlayer)))->AddMagicItem((::MagicItem *)(pComp)))
        {
            RemoveItem(pItem, pExtra, 1, 0, 0, 0, 0, 0, 1, 0);
        }
    }
}

class B8C4890Process
{
  public:
    virtual void vfunc000();
    virtual void vfunc001();
    virtual void vfunc002();
    virtual void vfunc003();
    virtual void vfunc004();
    virtual void vfunc005();
    virtual void vfunc006();
    virtual void vfunc007();
    virtual void vfunc008();
    virtual void vfunc009();
    virtual void vfunc00A();
    virtual void vfunc00B();
    virtual void vfunc00C();
    virtual void vfunc00D();
    virtual void vfunc00E();
    virtual void vfunc00F();
    virtual void vfunc010();
    virtual void vfunc011();
    virtual void vfunc012();
    virtual void vfunc013();
    virtual void vfunc014();
    virtual void vfunc015();
    virtual void vfunc016();
    virtual void vfunc017();
    virtual void vfunc018();
    virtual void vfunc019();
    virtual void vfunc01A();
    virtual void vfunc01B();
    virtual void vfunc01C();
    virtual void vfunc01D();
    virtual void vfunc01E();
    virtual void vfunc01F();
    virtual void vfunc020();
    virtual void vfunc021();
    virtual void vfunc022();
    virtual void vfunc023();
    virtual void vfunc024();
    virtual void vfunc025();
    virtual void vfunc026();
    virtual void vfunc027();
    virtual void vfunc028();
    virtual void vfunc029();
    virtual void vfunc02A();
    virtual void vfunc02B();
    virtual void vfunc02C();
    virtual void vfunc02D();
    virtual void vfunc02E();
    virtual void vfunc02F();
    virtual void vfunc030();
    virtual void vfunc031();
    virtual void vfunc032();
    virtual void vfunc033();
    virtual void vfunc034();
    virtual void vfunc035();
    virtual void vfunc036();
    virtual void vfunc037();
    virtual void vfunc038();
    virtual void vfunc039();
    virtual void vfunc03A();
    virtual void vfunc03B();
    virtual void vfunc03C();
    virtual void vfunc03D();
    virtual void vfunc03E();
    virtual void vfunc03F();
    virtual void vfunc040();
    virtual void vfunc041();
    virtual void vfunc042();
    virtual void vfunc043();
    virtual void vfunc044();
    virtual void vfunc045();
    virtual void vfunc046();
    virtual void vfunc047();
    virtual void vfunc048();
    virtual void vfunc049();
    virtual void vfunc04A();
    virtual void vfunc04B();
    virtual void vfunc04C();
    virtual void vfunc04D();
    virtual void vfunc04E();
    virtual void vfunc04F();
    virtual void vfunc050();
    virtual void vfunc051();
    virtual void vfunc052();
    virtual void vfunc053();
    virtual void vfunc054();
    virtual void vfunc055();
    virtual void vfunc056();
    virtual void vfunc057();
    virtual void vfunc058();
    virtual void vfunc059();
    virtual void vfunc05A();
    virtual void vfunc05B();
    virtual void vfunc05C();
    virtual void vfunc05D();
    virtual void vfunc05E();
    virtual void vfunc05F();
    virtual void vfunc060();
    virtual void vfunc061();
    virtual void vfunc062();
    virtual void vfunc063();
    virtual void vfunc064();
    virtual void vfunc065();
    virtual void vfunc066();
    virtual void vfunc067();
    virtual void vfunc068();
    virtual void vfunc069();
    virtual void vfunc06A();
    virtual void vfunc06B();
    virtual void vfunc06C();
    virtual void vfunc06D();
    virtual void vfunc06E();
    virtual void vfunc06F();
    virtual void vfunc070();
    virtual void vfunc071();
    virtual void vfunc072();
    virtual void vfunc073();
    virtual void vfunc074();
    virtual void vfunc075();
    virtual void vfunc076();
    virtual void vfunc077();
    virtual void vfunc078();
    virtual void vfunc079();
    virtual void vfunc07A();
    virtual void vfunc07B();
    virtual void vfunc07C();
    virtual void vfunc07D();
    virtual void vfunc07E();
    virtual void vfunc07F();
    virtual void vfunc080();
    virtual void vfunc081();
    virtual void vfunc082();
    virtual void vfunc083();
    virtual void vfunc084();
    virtual void vfunc085();
    virtual void vfunc086();
    virtual void vfunc087();
    virtual void vfunc088();
    virtual void vfunc089();
    virtual void vfunc08A();
    virtual void vfunc08B();
    virtual void vfunc08C();
    virtual void vfunc08D();
    virtual void vfunc08E();
    virtual void vfunc08F();
    virtual void vfunc090();
    virtual void vfunc091();
    virtual void vfunc092();
    virtual void vfunc093();
    virtual void vfunc094();
    virtual void vfunc095();
    virtual void vfunc096();
    virtual void vfunc097();
    virtual void vfunc098();
    virtual void vfunc099();
    virtual void vfunc09A();
    virtual void vfunc09B();
    virtual void vfunc09C();
    virtual void vfunc09D();
    virtual void vfunc09E();
    virtual void vfunc09F();
    virtual void vfunc0A0();
    virtual void vfunc0A1();
    virtual void vfunc0A2();
    virtual void vfunc0A3();
    virtual void vfunc0A4();
    virtual void vfunc0A5();
    virtual void vfunc0A6();
    virtual void vfunc0A7();
    virtual void vfunc0A8();
    virtual void vfunc0A9();
    virtual void vfunc0AA();
    virtual void vfunc0AB();
    virtual void vfunc0AC();
    virtual void vfunc0AD();
    virtual void vfunc0AE();
    virtual void vfunc0AF();
    virtual void vfunc0B0();
    virtual void vfunc0B1();
    virtual void vfunc0B2();
    virtual void vfunc0B3();
    virtual void vfunc0B4();
    virtual void vfunc0B5();
    virtual void vfunc0B6();
    virtual void vfunc0B7();
    virtual void vfunc0B8();
    virtual void vfunc0B9();
    virtual void vfunc0BA();
    virtual void vfunc0BB();
    virtual void vfunc0BC();
    virtual void vfunc0BD();
    virtual void vfunc0BE();
    virtual void vfunc0BF();
    virtual void vfunc0C0();
    virtual void vfunc0C1();
    virtual void vfunc0C2();
    virtual void vfunc0C3();
    virtual void vfunc0C4();
    virtual void vfunc0C5();
    virtual void vfunc0C6();
    virtual void vfunc0C7();
    virtual void vfunc0C8();
    virtual void vfunc0C9();
    virtual void vfunc0CA();
    virtual void vfunc0CB();
    virtual void vfunc0CC();
    virtual void vfunc0CD();
    virtual void vfunc0CE();
    virtual void vfunc0CF();
    virtual void vfunc0D0();
    virtual void vfunc0D1();
    virtual void vfunc0D2();
    virtual void vfunc0D3();
    virtual void vfunc0D4();
    virtual void vfunc0D5();
    virtual void vfunc0D6();
    virtual void vfunc0D7();
    virtual void vfunc0D8();
    virtual void vfunc0D9();
    virtual void vfunc0DA();
    virtual void vfunc0DB();
    virtual void vfunc0DC();
    virtual void vfunc0DD();
    virtual void vfunc0DE();
    virtual void vfunc0DF();
    virtual void vfunc0E0();
    virtual void vfunc0E1();
    virtual void vfunc0E2();
    virtual void vfunc0E3();
    virtual void vfunc0E4();
    virtual void vfunc0E5();
    virtual void vfunc0E6();
    virtual void vfunc0E7();
    virtual void vfunc0E8();
    virtual void vfunc0E9();
    virtual void vfunc0EA();
    virtual void vfunc0EB();
    virtual void vfunc0EC();
    virtual void vfunc0ED();
    virtual void vfunc0EE();
    virtual void vfunc0EF();
    virtual void vfunc0F0();
    virtual void vfunc0F1();
    virtual void vfunc0F2();
    virtual void vfunc0F3();
    virtual void vfunc0F4();
    virtual void vfunc0F5();
    virtual void vfunc0F6();
    virtual void vfunc0F7();
    virtual void vfunc0F8();
    virtual void vfunc0F9();
    virtual void vfunc0FA();
    virtual void vfunc0FB();
    virtual void vfunc0FC();
    virtual void vfunc0FD();
    virtual void vfunc0FE();
    virtual void vfunc0FF();
    virtual void vfunc100();
    virtual void vfunc101();
    virtual void vfunc102();
    virtual void vfunc103();
    virtual void vfunc104();
    virtual void vfunc105();
    virtual void vfunc106();
    virtual void vfunc107();
    virtual void vfunc108();
    virtual void vfunc109();
    virtual void vfunc10A();
    virtual void vfunc10B();
    virtual void vfunc10C();
    virtual void vfunc10D();
    virtual void vfunc10E();
    virtual void vfunc10F();
    virtual void vfunc110();
    virtual void vfunc111();
    virtual void vfunc112();
    virtual void vfunc113();
    virtual void vfunc114();
    virtual void vfunc115();
    virtual void vfunc116();
    virtual void vfunc117();
    virtual void vfunc118();
    virtual void vfunc119();
    virtual void vfunc11A();
    virtual void vfunc11B();
    virtual void vfunc11C();
    virtual void vfunc11D();
    virtual void vfunc11E();
    virtual void vfunc11F();
    virtual void vfunc120();
    virtual void vfunc121();
    virtual void vfunc122();
    virtual void vfunc123();
    virtual void vfunc124();
    virtual void vfunc125();
    virtual void vfunc126();
    virtual void vfunc127();
    virtual void vfunc128();
    virtual void vfunc129();
    virtual void vfunc12A();
    virtual void vfunc12B();
    virtual void vfunc12C();
    virtual void vfunc12D();
    virtual void vfunc12E();
    virtual void vfunc12F();
    virtual void vfunc130();
    virtual void vfunc131();
    virtual void vfunc132();
    virtual void vfunc133();
    virtual void vfunc134();
    virtual void vfunc135();
    virtual void vfunc136();
    virtual void vfunc137();
    virtual void vfunc138();
    virtual void vfunc139();
    virtual void vfunc13A();
    virtual void vfunc13B();
    virtual void vfunc13C();
    virtual void vfunc13D();
    virtual void vfunc13E();
    virtual void vfunc13F();
    virtual void vfunc140();
    virtual void vfunc141();
    virtual void vfunc142();
    virtual void vfunc143();
    virtual void vfunc144();
    virtual void vfunc145();
    virtual void vfunc146();
    virtual void vfunc147();
    virtual void vfunc148();
    virtual void vfunc149();
    virtual void vfunc14A();
    virtual void vfunc14B();
    virtual void vfunc14C();
    virtual void vfunc14D();
    virtual void vfunc14E();
    virtual void vfunc14F();
    virtual void vfunc150();
    virtual void vfunc151();
    virtual void vfunc152();
    virtual void vfunc153();
    virtual void vfunc154();
    virtual void vfunc155();
    virtual void vfunc156();
    virtual void vfunc157();
    virtual void vfunc158();
    virtual void vfunc159();
    virtual void vfunc15A();
    virtual void vfunc15B();
    virtual void vfunc15C();
    virtual void vfunc15D();
    virtual void vfunc15E();
    virtual void vfunc15F();
    virtual void vfunc160();
    virtual void vfunc161();
    virtual void vfunc162();
    virtual void vfunc163();
    virtual void vfunc164();
    virtual void vfunc165();
    virtual void vfunc166();
    virtual void vfunc167();
    virtual void vfunc168();
    virtual void vfunc169();
    virtual void vfunc16A();
    virtual void vfunc16B();
    virtual void SetValue(float fValue);
};

class B8C4890Actor
{
  public:
    int unk00;
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    B8C4890Process* m_pkProcess;

    void SetProcessValue(float fValue);
};

// If m_pkProcess is set, forwards fValue to m_pkProcess->SetValue.
// @fnv 0x008c4890
void B8C4890Actor::SetProcessValue(float fValue)
{
    if (m_pkProcess)
        m_pkProcess->SetValue(fValue);
}

struct EffectSetting
{
};
class SummonCreatureEffect;
class EffectSetting;
class ActiveEffect
{
  public:
    virtual ~ActiveEffect();
public:
    ::EffectSetting *GetEffectSetting() const;
};
struct EffectNode
{
    bool IsEmpty();
};
struct MagicTargetS
{
    virtual void mt0();
    virtual void mt1();
    virtual EffectNode* GetActiveEffectList();
};
struct TargetActorS
{
    int unk00;
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    MagicTargetS magicTarget;
};
struct ProcessS
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual TargetActorS* GetTargetActor();
};
struct SummonOwner;
class SummonCreatureEffect : public ActiveEffect
{
  public:
};
struct SummonOwner
{
    bool DispelSummonEffects();
};

// Walks the target actor's active effect list, unsummons and dispels summon effects owned by this owner, returning whether any were dispelled.
// @fnv 0x008c51f0
bool SummonOwner::DispelSummonEffects()
{
    bool bDispelled5 = false;
    if (!((::ProcessS *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())) || !((::ProcessS *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->GetTargetActor())
        return false;
    TargetActorS* pTarget3 = ((::ProcessS *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))->GetTargetActor();
    EffectNode* pNode6 = pTarget3->magicTarget.GetActiveEffectList();
    while (pNode6 && !pNode6->IsEmpty())
    {
        ActiveEffect* pEffect = *((::ActiveEffect **)(new ((void *)(pNode6)) ::Vec3()));
        if (pEffect && reinterpret_cast<::S3e60 *>((pEffect->GetEffectSetting()))->FUN_00403e60(0x40000))
        {
            SummonCreatureEffect* pSummon = dynamic_cast<SummonCreatureEffect*>(pEffect);
            SummonOwner* pOwner4 = pSummon ? ((::SummonOwner *)(reinterpret_cast<::FUN_0068a810_class *>((pSummon))->GetField4C())) : 0;
            if (pOwner4 == this)
            {
                reinterpret_cast<::FUN_008c5330_shell *>((pSummon))->ClearField4C();
                reinterpret_cast<::fnv_00804210::ActiveEffectUpdateShell *>((pEffect))->FUN_00804210(true);
                bDispelled5 = true;
            }
        }
        pNode6 = ((::EffectNode *)(reinterpret_cast<::Callees *>((pNode6))->FUN_00726070()));
    }
    return bDispelled5;
}

struct Item
{
};
struct Ref
{
    int FUN_004459e0(int);
};
struct Controller
{
    void FUN_0095e670(Item*, int);
};
struct XAmmoFields17
{
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
    int count;
};
struct XForm17;

struct XRefr17;

struct XNode17;

struct XItem17;

struct XExtraList17;

struct XProc17;

struct XGlob17;

struct XSingleton17;

struct XHostVtbl17
{

    virtual void vfn_0();

    virtual void vfn_4();

    virtual void vfn_8();

    virtual void vfn_c();

    virtual void vfn_10();

    virtual void vfn_14();

    virtual void vfn_18();

    virtual void vfn_1c();

    virtual void vfn_20();

    virtual void vfn_24();

    virtual void vfn_28();

    virtual void vfn_2c();

    virtual void vfn_30();

    virtual void vfn_34();

    virtual void vfn_38();

    virtual void vfn_3c();

    virtual void vfn_40();

    virtual void vfn_44();

    virtual void vfn_48();

    virtual void vfn_4c();

    virtual void vfn_50();

    virtual void vfn_54();

    virtual void vfn_58();

    virtual void vfn_5c();

    virtual void vfn_60();

    virtual void vfn_64();

    virtual void vfn_68();

    virtual void vfn_6c();

    virtual void vfn_70();

    virtual void vfn_74();

    virtual void vfn_78();

    virtual void vfn_7c();

    virtual void vfn_80();

    virtual void vfn_84();

    virtual void vfn_88();

    virtual void vfn_8c();

    virtual void vfn_90();

    virtual void vfn_94();

    virtual void vfn_98();

    virtual void vfn_9c();

    virtual void vfn_a0();

    virtual void vfn_a4();

    virtual void vfn_a8();

    virtual void vfn_ac();

    virtual void vfn_b0();

    virtual void vfn_b4();

    virtual void vfn_b8();

    virtual void vfn_bc();

    virtual void vfn_c0();

    virtual void vfn_c4();

    virtual void vfn_c8();

    virtual void vfn_cc();

    virtual void vfn_d0();

    virtual void vfn_d4();

    virtual void vfn_d8();

    virtual void vfn_dc();

    virtual void vfn_e0();

    virtual void vfn_e4();

    virtual void vfn_e8();

    virtual void vfn_ec();

    virtual void vfn_f0();

    virtual void vfn_f4();

    virtual void vfn_f8();

    virtual void vfn_fc();

    virtual void vfn_100();

    virtual void vfn_104();

    virtual void vfn_108();

    virtual void vfn_10c();

    virtual void vfn_110();

    virtual void vfn_114();

    virtual void vfn_118();

    virtual void vfn_11c();

    virtual void vfn_120();

    virtual void vfn_124();

    virtual void vfn_128();

    virtual void vfn_12c();

    virtual void vfn_130();

    virtual void vfn_134();

    virtual void vfn_138();

    virtual void vfn_13c();

    virtual void vfn_140();

    virtual void vfn_144();

    virtual void vfn_148();

    virtual void vfn_14c();

    virtual void vfn_150();

    virtual void vfn_154();

    virtual void vfn_158();

    virtual void vfn_15c();

    virtual void vfn_160();

    virtual void vfn_164();

    virtual void vfn_168();

    virtual void vfn_16c();

    virtual void vfn_170();

    virtual void vfn_174();

    virtual void vfn_178();

    virtual void vfn_17c();

    virtual void vfn_180();

    virtual void vfn_184();

    virtual void vfn_188();

    virtual void vfn_18c();

    virtual void vfn_190();

    virtual void vfn_194();

    virtual void vfn_198();

    virtual void vfn_19c();

    virtual void vfn_1a0();

    virtual void vfn_1a4();

    virtual void vfn_1a8();

    virtual void vfn_1ac();

    virtual void vfn_1b0();

    virtual void vfn_1b4();

    virtual void vfn_1b8();

    virtual void vfn_1bc();

    virtual void vfn_1c0();

    virtual void vfn_1c4();

    virtual void vfn_1c8();

    virtual void vfn_1cc();

    virtual void vfn_1d0();

    virtual void vfn_1d4();

    virtual void vfn_1d8();

    virtual void vfn_1dc();

    virtual void vfn_1e0();

    virtual int vfn_1e4();

    virtual int vfn_1e8();

    virtual void vfn_1ec();

    virtual void vfn_1f0();

    virtual void vfn_1f4();

    virtual void vfn_1f8();

    virtual void vfn_1fc();

    virtual void vfn_200();

    virtual void vfn_204();

    virtual void vfn_208();

    virtual void vfn_20c();

    virtual void vfn_210();

    virtual void vfn_214();

    virtual bool vfn_218();

    virtual void vfn_21c();

    virtual void vfn_220();

    virtual void vfn_224();

    virtual void vfn_228();

    virtual void vfn_22c();

    virtual void vfn_230();

    virtual void vfn_234();

    virtual void vfn_238();

    virtual void vfn_23c();

    virtual void vfn_240();

    virtual void vfn_244();

    virtual void vfn_248();

    virtual void vfn_24c();

    virtual void vfn_250();

    virtual void vfn_254();

    virtual void vfn_258();

    virtual void vfn_25c();

    virtual void vfn_260();

    virtual void vfn_264();

    virtual void vfn_268();

    virtual void vfn_26c();

    virtual void vfn_270();

    virtual void vfn_274();

    virtual void vfn_278();

    virtual void vfn_27c();

    virtual void vfn_280();

    virtual void vfn_284();

    virtual void vfn_288();

    virtual void vfn_28c();

    virtual void vfn_290();

    virtual void vfn_294();

    virtual void vfn_298();

    virtual void vfn_29c();

    virtual void vfn_2a0();

    virtual void vfn_2a4();

    virtual void vfn_2a8();

    virtual void vfn_2ac();

    virtual void vfn_2b0();

    virtual void vfn_2b4();

    virtual void vfn_2b8();

    virtual void vfn_2bc();

    virtual void vfn_2c0();

    virtual void vfn_2c4();

    virtual void vfn_2c8();

    virtual void vfn_2cc();

    virtual void vfn_2d0();

    virtual void vfn_2d4();

    virtual void vfn_2d8();

    virtual void vfn_2dc();

    virtual void vfn_2e0();

    virtual void vfn_2e4();

    virtual void vfn_2e8();

    virtual void vfn_2ec();

    virtual void vfn_2f0();

    virtual void vfn_2f4();

    virtual void vfn_2f8();

    virtual void vfn_2fc();

    virtual void vfn_300();

    virtual void vfn_304();

    virtual void vfn_308();

    virtual void vfn_30c();

    virtual void vfn_310();

    virtual void vfn_314();

    virtual void vfn_318();

    virtual void vfn_31c();

    virtual void vfn_320();

    virtual void vfn_324();

    virtual void vfn_328();

    virtual void vfn_32c();

    virtual void vfn_330();

    virtual void vfn_334();

    virtual void vfn_338();

    virtual void vfn_33c();

    virtual void vfn_340();

    virtual void vfn_344();

    virtual void vfn_348();

    virtual void vfn_34c();

    virtual void vfn_350();

    virtual void vfn_354();

    virtual void vfn_358();

    virtual void vfn_35c();

    virtual void vfn_360();

    virtual void vfn_364();

    virtual void vfn_368();

    virtual void vfn_36c();

    virtual void vfn_370();

    virtual void vfn_374();

    virtual void vfn_378();

    virtual void vfn_37c();

    virtual void vfn_380();

    virtual void vfn_384();

    virtual void vfn_388();

    virtual void vfn_38c();

    virtual void vfn_390();

    virtual void vfn_394();

    virtual void vfn_398();

    virtual void vfn_39c();

    virtual void vfn_3a0();

    virtual void vfn_3a4();

    virtual void vfn_3a8();

    virtual void vfn_3ac();

    virtual void vfn_3b0();

    virtual void vfn_3b4();

    virtual void vfn_3b8();

    virtual XForm17* vfn_3bc(int);

    virtual void vfn_3c0();

    virtual void vfn_3c4();

    virtual void vfn_3c8();

    virtual void vfn_3cc();

    virtual void vfn_3d0();

    virtual void vfn_3d4();

    virtual void vfn_3d8();

    virtual void vfn_3dc();

    virtual void vfn_3e0();

    virtual void vfn_3e4();

    virtual void vfn_3e8();

    virtual void vfn_3ec(void*, int, int, int);
};

struct XRefrVtbl17
{

    virtual void vfn_0();

    virtual void vfn_4();

    virtual void vfn_8();

    virtual void vfn_c();

    virtual void vfn_10();

    virtual void vfn_14();

    virtual void vfn_18();

    virtual void vfn_1c();

    virtual void vfn_20();

    virtual void vfn_24();

    virtual void vfn_28();

    virtual void vfn_2c();

    virtual void vfn_30();

    virtual void vfn_34();

    virtual void vfn_38();

    virtual void vfn_3c();

    virtual void vfn_40();

    virtual void vfn_44();

    virtual void vfn_48();

    virtual void vfn_4c(int);

    virtual void vfn_50();

    virtual void vfn_54();

    virtual void vfn_58();

    virtual void vfn_5c();

    virtual void vfn_60();

    virtual void vfn_64();

    virtual void vfn_68();

    virtual void vfn_6c();

    virtual void vfn_70();

    virtual void vfn_74();

    virtual void vfn_78();

    virtual void vfn_7c();

    virtual void vfn_80();

    virtual void vfn_84();

    virtual void vfn_88();

    virtual void vfn_8c();

    virtual void vfn_90();

    virtual void vfn_94();

    virtual void vfn_98();

    virtual void vfn_9c();

    virtual void vfn_a0();

    virtual void vfn_a4();

    virtual void vfn_a8();

    virtual void vfn_ac();

    virtual void vfn_b0();

    virtual void vfn_b4();

    virtual void vfn_b8();

    virtual void vfn_bc();

    virtual void vfn_c0();

    virtual void vfn_c4(int);

    virtual void vfn_c8();

    virtual void vfn_cc();

    virtual void vfn_d0();

    virtual void vfn_d4();

    virtual void vfn_d8();

    virtual void vfn_dc();

    virtual void vfn_e0();

    virtual void vfn_e4();

    virtual void vfn_e8();

    virtual void vfn_ec();

    virtual void vfn_f0();

    virtual void vfn_f4();

    virtual void vfn_f8();

    virtual void vfn_fc();

    virtual void vfn_100();

    virtual void vfn_104();

    virtual void vfn_108();

    virtual void vfn_10c();

    virtual void vfn_110();

    virtual void vfn_114();

    virtual void vfn_118();

    virtual void vfn_11c();

    virtual void vfn_120();

    virtual void vfn_124();

    virtual void vfn_128();

    virtual void vfn_12c();

    virtual void vfn_130();

    virtual void vfn_134();

    virtual void vfn_138();

    virtual void vfn_13c();

    virtual void vfn_140();

    virtual void vfn_144();

    virtual void vfn_148();

    virtual void vfn_14c();

    virtual void vfn_150();

    virtual void vfn_154();

    virtual void vfn_158();

    virtual void vfn_15c();

    virtual void vfn_160();

    virtual void vfn_164();

    virtual void vfn_168();

    virtual void vfn_16c();

    virtual void vfn_170();

    virtual void vfn_174();

    virtual void vfn_178();

    virtual void vfn_17c();

    virtual void vfn_180();

    virtual void vfn_184();

    virtual void vfn_188();

    virtual void vfn_18c();

    virtual void vfn_190();

    virtual void vfn_194();

    virtual void vfn_198();

    virtual void vfn_19c();

    virtual void vfn_1a0();

    virtual void vfn_1a4();

    virtual void vfn_1a8();

    virtual void vfn_1ac();

    virtual void vfn_1b0();

    virtual void vfn_1b4();

    virtual void vfn_1b8();

    virtual void vfn_1bc();

    virtual void vfn_1c0();

    virtual void vfn_1c4();

    virtual void vfn_1c8();

    virtual void vfn_1cc();

    virtual void vfn_1d0();

    virtual void vfn_1d4();

    virtual void vfn_1d8();

    virtual void vfn_1dc();

    virtual void vfn_1e0();

    virtual void vfn_1e4();

    virtual void vfn_1e8();

    virtual void vfn_1ec();

    virtual void vfn_1f0();

    virtual void vfn_1f4();

    virtual void vfn_1f8();

    virtual void vfn_1fc();

    virtual void vfn_200();

    virtual void vfn_204();

    virtual void vfn_208();

    virtual void vfn_20c();

    virtual void vfn_210();

    virtual void vfn_214();

    virtual void vfn_218();

    virtual void vfn_21c();

    virtual void vfn_220();

    virtual bool vfn_224();
};

struct XProcVtbl17
{

    virtual void vfn_0();

    virtual void vfn_4();

    virtual void vfn_8();

    virtual void vfn_c();

    virtual void vfn_10();

    virtual void vfn_14();

    virtual void vfn_18();

    virtual void vfn_1c();

    virtual void vfn_20();

    virtual void vfn_24();

    virtual void vfn_28();

    virtual void vfn_2c();

    virtual void vfn_30();

    virtual void vfn_34();

    virtual void vfn_38();

    virtual void vfn_3c();

    virtual void vfn_40();

    virtual void vfn_44();

    virtual void vfn_48();

    virtual void vfn_4c();

    virtual void vfn_50();

    virtual void vfn_54();

    virtual void vfn_58();

    virtual void vfn_5c();

    virtual void vfn_60();

    virtual void vfn_64();

    virtual void vfn_68();

    virtual void vfn_6c();

    virtual void vfn_70();

    virtual void vfn_74();

    virtual void vfn_78();

    virtual void vfn_7c();

    virtual void vfn_80();

    virtual void vfn_84();

    virtual void vfn_88();

    virtual void vfn_8c();

    virtual void vfn_90();

    virtual void vfn_94();

    virtual void vfn_98();

    virtual void vfn_9c();

    virtual void vfn_a0();

    virtual void vfn_a4();

    virtual void vfn_a8();

    virtual void vfn_ac();

    virtual void vfn_b0();

    virtual void vfn_b4();

    virtual void vfn_b8();

    virtual void vfn_bc();

    virtual void vfn_c0();

    virtual void vfn_c4();

    virtual void vfn_c8();

    virtual void vfn_cc();

    virtual void vfn_d0();

    virtual void vfn_d4();

    virtual void vfn_d8();

    virtual void vfn_dc();

    virtual void vfn_e0();

    virtual void vfn_e4();

    virtual void vfn_e8();

    virtual void vfn_ec();

    virtual void vfn_f0();

    virtual void vfn_f4();

    virtual void vfn_f8();

    virtual void vfn_fc();

    virtual void vfn_100();

    virtual void vfn_104();

    virtual void vfn_108();

    virtual void vfn_10c();

    virtual void vfn_110();

    virtual void vfn_114();

    virtual void vfn_118();

    virtual void vfn_11c();

    virtual void vfn_120();

    virtual void vfn_124();

    virtual void vfn_128();

    virtual void vfn_12c();

    virtual void vfn_130();

    virtual void vfn_134();

    virtual void vfn_138();

    virtual void vfn_13c();

    virtual void vfn_140();

    virtual void vfn_144();

    virtual void* vfn_148();

    virtual void* vfn_14c();

    virtual void vfn_150();

    virtual void vfn_154();

    virtual void vfn_158();

    virtual void vfn_15c();

    virtual void vfn_160();

    virtual void vfn_164();

    virtual void vfn_168();

    virtual void vfn_16c();

    virtual void vfn_170();

    virtual void vfn_174();

    virtual void vfn_178();

    virtual void vfn_17c();

    virtual void vfn_180();

    virtual void vfn_184();

    virtual void vfn_188();

    virtual void vfn_18c();

    virtual void vfn_190();

    virtual void vfn_194();

    virtual void vfn_198();

    virtual void vfn_19c();

    virtual void vfn_1a0();

    virtual void vfn_1a4();

    virtual void vfn_1a8();

    virtual void vfn_1ac();

    virtual void vfn_1b0();

    virtual void vfn_1b4();

    virtual void vfn_1b8();

    virtual void vfn_1bc();

    virtual void vfn_1c0();

    virtual void vfn_1c4();

    virtual void vfn_1c8();

    virtual void vfn_1cc(int, int, int, void*);
};

int FUN_00401170(void*);







struct XForm17
{

    int FUN_00446390();

    int FUN_004459e0(int);
};

struct XItem17
{


};

struct XNode17
{




};

struct XExtraList17
{



};

struct XRefr17 : public XRefrVtbl17
{









};

struct XProc17 : public XProcVtbl17
{
};

struct XWeap17
{

};

struct XW17
{

};

struct XDbl17
{

};

struct XGlob17
{

};

struct XSingleton17
{

};

struct XHigh17
{

};

struct XHost17 : public XHostVtbl17
{

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

    XProc17* m_pBaseProcess;





    void FUN_00574b30(XRefr17*, int, bool, bool);




    void FUN_00891e00(XRefr17*, int, bool);
};

// @fnv 0x00891e00
void XHost17::FUN_00891e00(XRefr17* pRefr, int iCount, bool a2)

{

    bool flag1;
    bool flag2;
    XForm17* t4;
    pRefr->vfn_4c(0);

    XForm17* bound = pRefr != 0 ? ((::XForm17 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRefr))->FUN_007af430())) : 0;

    int node = bound != 0 ? FUN_00401170(bound) : 0;

    XNode17* s = ((::XNode17 *)(reinterpret_cast<::Target96 *>((((XGlob17*)&(*reinterpret_cast<::ActorDeletionQueue *>(&::g_011e0e80)))))->FUN_0096f450((unsigned int)(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((pRefr))->FUN_0084e3a0()))), {})));

    XNode17* node2 = s;

    reinterpret_cast<::ActorSoundStub *>(this)->PlayActorSound((int)(bound), 1, 0);

    while (s != 0 && *((::XItem17 **)(new ((void *)(s)) ::Vec3())) != 0)
    {

        XItem17* efx = *((::XItem17 **)(new ((void *)(s)) ::Vec3()));

        if (efx != 0 && ((::XRefr17 *)(reinterpret_cast<::FUN_00881650_shell *>((efx))->FUN_00881650())) == pRefr)
        {

            reinterpret_cast<::Host00881620 *>((efx))->FUN_00881620((int)this);
        }
        else
        {

            reinterpret_cast<::Host00881620 *>((efx))->FUN_00881620(0);
        }

        s = ((::XNode17 *)(reinterpret_cast<::Callees *>((s))->FUN_00726070()));
    }

    {
        XForm17* bov;
        void* bo2;
        XForm17* bo;
        if (node2 != 0)
        {

            reinterpret_cast<::FileMatchList *>((node2))->RemoveAll();

            XNode17* val;

            val = node2;

            XNode17* t2 = val;

            t2 != 0 ? ((int)(reinterpret_cast<::W004702f0 *>((t2))->FUN_004702f0(1))) : 0;
        }

        if (vfn_218())
        {

            if (((::XForm17 *)(reinterpret_cast<::OwnerLookupView *>((pRefr))->FUN_00567790())) != 0 && !reinterpret_cast<::OwnershipReferenceView *>((pRefr))->FUN_005785e0((::Actor *)(void *)(this), true) && ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((((::XHigh17 *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture()))))->FUN_0045cd60())) == 0)
            {

                reinterpret_cast<::ActorX *>(this)->FUN_008bfa40((::RefObj *)(pRefr), (int)bound, iCount, 0, (::TESForm *)(::XForm17 *)(((::XForm17 *)(reinterpret_cast<::OwnerLookupView *>((pRefr))->FUN_00567790()))));

                if (((bool)(reinterpret_cast<::FUN_00493bb0_Class *>(this)->FUN_00493bb0())) && this != (XHost17*)::_g_thePlayer)
                {

                    reinterpret_cast<::FUN_0041aed0_shell *>((((::XExtraList17 *)(reinterpret_cast<::FUN_005d43c0_ *>((pRefr))->FUN_005d43c0()))))->FUN_0041aed0();
                }
                else
                {

                    bov = 0;

                    bov = ((::XForm17 *)(::FUN_004216f0((::BaseExtraList *)(::XExtraList17 *)(((::XExtraList17 *)(reinterpret_cast<::FUN_005d43c0_ *>((pRefr))->FUN_005d43c0()))))));

                    if (bov == 0)
                        bov = ((::XForm17 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRefr))->FUN_007af430()));

                    reinterpret_cast<::fnv_00419700::FUN_00419700_shell *>((((::XExtraList17 *)(reinterpret_cast<::FUN_005d43c0_ *>((pRefr))->FUN_005d43c0()))))->FUN_00419700((::fnv_00419700::TESForm *)(bov));
                }
            }
            else
            {

                reinterpret_cast<::FUN_0041aed0_shell *>((((::XExtraList17 *)(reinterpret_cast<::FUN_005d43c0_ *>((pRefr))->FUN_005d43c0()))))->FUN_0041aed0();
            }
        }

        flag2 = false;

        t4 = 0;

        switch (FUN_00401170(((::XForm17 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRefr))->FUN_007af430()))))
        {

        case 41:

            a2 = false;

            if ((int)reinterpret_cast<::FUN_00418770_shell *>((((::XExtraList17 *)(reinterpret_cast<::FUN_005d43c0_ *>((pRefr))->FUN_005d43c0()))))->FUN_00418770() < 1)
            {

                iCount = FUN_00401170(&((XAmmoFields17*)((::XForm17 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRefr))->FUN_007af430())))->count);
            }

            break;

        case 40:

            t4 = ((::XForm17 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((pRefr))->FUN_007af430()));

            if (((XForm17*)t4)->FUN_00446390() == 10 || ((XForm17*)t4)->FUN_00446390() == 11)
            {

                if (m_pBaseProcess->vfn_14c() != 0)
                {

                    if (t4 == ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((m_pBaseProcess->vfn_14c()))->GetName())))
                    {

                        if (reinterpret_cast<::FUN_008a16d0_shell *>(this)->FUN_008a16d0())
                        {

                            m_pBaseProcess->vfn_1cc(0, vfn_1e8(), vfn_1e4(), this);

                            flag2 = true;
                        }
                    }
                }
            }

            break;
        }

        flag1 = false;

        if (reinterpret_cast<::FUN_00460250_shell *>((pRefr))->FUN_00460250() || ((int)(reinterpret_cast<::TESForm *>((pRefr))->GetFile(-1))) != 0 || reinterpret_cast<::fnv_005653d0::FUN_005653d0_shell *>((pRefr))->FUN_005653d0())
        {

            FUN_00574b30(pRefr, iCount, a2, false);
        }
        else
        {

            if (reinterpret_cast<::fnv_00572d30::FUN_00572d30_shell *>((pRefr))->FUN_00572d30(2) || pRefr->vfn_224())
            {

                FUN_00574b30(pRefr, iCount, false, false);
            }
            else
            {

                FUN_00574b30(pRefr, iCount, false, false);

                flag1 = true;
            }
        }

        if (flag2)
        {

            vfn_3ec(t4, 0, 0, 0);

            m_pBaseProcess->vfn_1cc(1, vfn_1e8(), vfn_1e4(), this);
        }

        if (m_pBaseProcess->vfn_14c() == 0 || reinterpret_cast<::Callees *>((m_pBaseProcess->vfn_14c()))->FUN_00726070() == 0)
        {

            if (m_pBaseProcess->vfn_148() != 0)
            {

                if (bound == ((void *)(reinterpret_cast<::AmmoOwner *>((((XWeap17*)((void *)(reinterpret_cast<::Twin_0044ddc0 *>((m_pBaseProcess->vfn_148()))->GetName())))))->FUN_00525980((::AmmoActor *)(void *)(this)))))
                {

                    if (((double)(reinterpret_cast<::TESObjectWEAP *>((((XDbl17*)((void *)(reinterpret_cast<::Twin_0044ddc0 *>((m_pBaseProcess->vfn_148()))->GetName())))))->FUN_00709430(reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((((XW17*)m_pBaseProcess->vfn_148())))->HasEffect(6)))) <= 0.0)
                    {

                        vfn_3ec(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((m_pBaseProcess->vfn_148()))->GetName())), reinterpret_cast<::FUN_008a16d0_shell *>(this)->FUN_008a16d0(),
                                reinterpret_cast<::fnv_004bda70::FUN_004bda70_shell *>((((XW17*)m_pBaseProcess->vfn_148())))->HasEffect(2), 0);
                    }
                }
            }
        }

        if (!((bool)(reinterpret_cast<::FUN_00493bb0_Class *>(this)->FUN_00493bb0())))
        {

            bo = 0;

            switch (node)
            {

            case 40:

                bo = vfn_3bc(6);

                break;
            }

            if (bo != 0)
            {

                bo2 = ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((bo))->GetName()));

                if (reinterpret_cast<::ActionOwner *>(this)->FUN_008bc9d0((::TargetObject *)(bo2), 1))
                {

                    reinterpret_cast<::FUN_0088c650_shell *>(this)->FUN_0088c650((::TESBoundObject *)(void *)(((void *)(reinterpret_cast<::Twin_0044ddc0 *>((bo))->GetName()))), 1, (::ExtraDataList *)(0), 1, 0, 1);
                }

                XForm17* t3 = bo;

                XForm17* pRef2 = t3;

                pRef2 != 0 ? pRef2->FUN_004459e0(1) : 0;
            }
        }

        pRefr->vfn_c4(1);

        if (FUN_008c7aa0())
        {

            reinterpret_cast<::FUN_0087afa0_Holder *>((((::XSingleton17 *)(::TaskQueueInterface::GetSingleton()))))->FUN_0087afa0(pRefr, flag1);
        }
        else
        {

            ::FUN_00892460((::FnvActorProxy *)(pRefr), flag1);
        }
    }
}

enum PTYPE
{
    PTYPE_26 = 26
};
enum PACKAGE_PROCEDURE_TYPE
{
    PROC_21 = 21
};

struct FUN_00670b30
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00670b30();
    ~FUN_00670b30();
};

class TESPackage
{
  public:
    PTYPE GetPackType();
    void SetMustReachLocation(bool);
    void SetMustComplete(bool);
    void SetProcedureType(PACKAGE_PROCEDURE_TYPE);
};
// @fnv 0x008985d0
void FUN_008985d0_shell::FUN_008985d0()
{
    reinterpret_cast<::FUN_0087faa0_shell *>(this)->FUN_0087faa0();
    FUN_006777b0_class* p = (FUN_006777b0_class*)((void *)(::CreatePackageByType(0x24)));
    reinterpret_cast<::fnv_006777b0::FUN_006777b0_shell *>((p))->ComputePackageFlags((::TESObjectREFR *)(0));
    if (FUN_00931850() <= 1)
    {
        vfn_2f4(p, 1, 1);
    }
    else
    {
        reinterpret_cast<::TESPackage *>((p))->SetMustComplete(1);
        vfn_2f4(p, 0, 0);
    }
}


struct BaseProcessExt
{
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
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual TESPackage* v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0(void*, int, int, int);
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual int v4d0();
};

struct ActorVtbl2f4
{
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
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4(TESPackage*, bool, bool);
};

struct FUN_008a75a0_shell : public Actor
{
    void EnsurePackage26();
};

// @fnv 0x008a75a0
void FUN_008a75a0_shell::EnsurePackage26()
{
    TESPackage* pPkg = ((::BaseProcessExt *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)this)->GetBaseTexture()))->v27c();
    if (reinterpret_cast<::FUN_00437bf0_shell *>(this)->FUN_00437bf0() || ((bool)(reinterpret_cast<::FUN_00437bd0_stub *>(this)->FUN_00437bd0())) || (pPkg && pPkg->GetPackType() == PTYPE_26))
    {
        return;
    }
    if (((BaseProcessExt*)m_pBaseProcess)->v4d0() == 127)
    {
        ((BaseProcessExt*)m_pBaseProcess)->v4c0(this, 0, 0, 127);
        return;
    }
    TESPackage* pNewPkg3 = ::CreatePackageByType((*(int *)&(const ::PTYPE &)(PTYPE_26)));
    reinterpret_cast<::PackageEx *>((pNewPkg3))->SetPackageType(26);
    pNewPkg3->SetMustReachLocation(false);
    pNewPkg3->SetMustComplete(true);
    FUN_00670b30* pLoc = new FUN_00670b30();
    reinterpret_cast<::LocationDescriptor *>((pLoc))->FUN_0067f3c0((::TESObjectREFR *)(void *)(this));
    reinterpret_cast<::fnv_00671d30::FUN_00671d30_shell *>((pNewPkg3))->FUN_00671d30((::fnv_00671d30::LocationDescriptor *)(pLoc));
    delete pLoc;
    pNewPkg3->SetProcedureType(PROC_21);
    ((::BaseProcessExt *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)this)->GetBaseTexture()))->v028();
    ((ActorVtbl2f4*)this)->v2f4(pNewPkg3, true, true);
}

class Form8C1
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class Entry8C1
{
  public:
    int m_iArrayLength;
};

class Item8C1 : public Form8C1, public Entry8C1
{
};

class ItemList8C1
{
  public:
};

class Object8C1
{
  public:

    int unk00;
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    ItemList8C1 m_kUnsortedGeometryList;
};

class EntryList8C1
{
  public:
    void Add(Entry8C1* pkEntry, int iCount, int iFlags);
};

class Actor8C1
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void EquipObject(Object8C1* pkObject, int iArg1, int iArg2, int iArg3, int iArg4, int iArg5, int iArg6,
                             int iArg7, int iArg8, int iArg9);

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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    EntryList8C1 m_kEntries;

    void EquipPlayableObject(Object8C1* pkObject, int iCount);
};
// @fnv 0x0095e670
void Controller::FUN_0095e670(Item* item, int mode)
{
    reinterpret_cast<::Actor8C1 *>(this)->EquipPlayableObject((::Object8C1 *)(item), mode);
    Ref* ref = ((::Ref *)(reinterpret_cast<::fnv_00576260::FUN_00576260_shell *>(this)->FUN_00576260((::fnv_00576260::TESBoundObject *)(item), reinterpret_cast<::FUN_0084e3a0_Class *>((item))->FUN_0084e3a0())));
    if (ref)
    {
        Ref* selectedRef = ref;
        Ref* activeRef = selectedRef;
        activeRef ? activeRef->FUN_004459e0(1) : 0;
        reinterpret_cast<::FUN_0094c950_shell *>(this)->SetArg((::ArgObj *)(item));
    }
    else
    {
        reinterpret_cast<::FUN_0094c950_shell *>(this)->SetArg((::ArgObj *)(::Item *)(0));
    }
}

class Player8C1 : public Actor8C1
{
  public:
};


// If pkObject is playable and has a first list entry, equips it, adds that entry to m_kEntries, and refreshes the player when this is g_pkPlayer8C1.
// @fnv 0x008c1d20
void Actor8C1::EquipPlayableObject(Object8C1* pkObject, int iCount)
{
    if (pkObject && reinterpret_cast<::FUN_00409700_Class *>((pkObject))->FUN_00409700() && ((::Item8C1 *)(reinterpret_cast<::Callees *>(&(pkObject->m_kUnsortedGeometryList))->FUN_00726070())))
    {
        EquipObject(pkObject, 0, 1, 0, 0, 0, 0, 0, 1, 0);
        reinterpret_cast<::Handler *>(&(m_kEntries))->FUN_00815480((::Event *)(::Entry8C1 *)(((::Item8C1 *)(reinterpret_cast<::Callees *>(&(pkObject->m_kUnsortedGeometryList))->FUN_00726070()))), iCount, 0);
        if (this == (*reinterpret_cast<::Player8C1 * *>(&::_g_thePlayer)))
            reinterpret_cast<::FUN_0094c950_shell *>(((*reinterpret_cast<::Player8C1 * *>(&::_g_thePlayer))))->SetArg((::ArgObj *)(0));
    }
}

struct FUN_008c1f80_caster
{
    virtual void c00();
    virtual void c04();
    virtual void c08();
    virtual void c0c();
    virtual void c10();
    virtual void c14();
    virtual void c18();
    virtual void c1c();
    virtual void c20();
    virtual void c24();
    virtual void c28();
    virtual void c2c();
    virtual void c30();
    virtual void c34();
    virtual void c38();
    virtual void c3c();
    virtual void SetActiveItem(FUN_008c1de0_comp* pItem);
    int unk04;
    int unk08;
};
struct FUN_008c1f80_shell
{
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
    virtual void EquipItem(TESForm* pItem, int iCount, bool b1, bool b2, bool b3, bool b4, bool b5, bool b6, bool b7,
                           bool b8);
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    FUN_008c1f80_caster caster;
    bool EquipItemWithCaster(FUN_008c1de0_item* pItem, int iCount, bool bForce);
};
// @fnv 0x008c1f80
bool FUN_008c1f80_shell::EquipItemWithCaster(FUN_008c1de0_item* pItem, int iCount, bool bForce)
{
    if (!pItem)
        return false;
    bool bResult = true;
    if ((void*)this != (void*)::_g_thePlayer || bForce)
    {
        caster.SetActiveItem(pItem);
        reinterpret_cast<::CastingCheck *>((((FUN_00815380_shell*)&caster)))->TryCast((::TESBoundObject *)(0));
        if ((void*)this != (void*)::_g_thePlayer)
            EquipItem(pItem, iCount, true, false, false, false, false, false, true, false);
    }
    else
    {
        bResult = reinterpret_cast<::PlayerCharacter_StandIn *>((((FUN_008c1de0_player*)::_g_thePlayer)))->AddMagicItem((::MagicItem *)(pItem));
        if (bResult)
            EquipItem(pItem, iCount, true, false, false, false, false, false, true, false);
    }
    return bResult;
}

struct FUN_008c2b60_node
{
};

struct FUN_008c2e30_spell
{
};

struct FUN_004459e0
{
    ~FUN_004459e0();
};

struct FUN_004c8c10_inv
{
};


struct FUN_00824400_target
{
};

struct FUN_008c2b60_vtbl
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
    virtual void v056();
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
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual TESRace* v223();
};

struct FUN_008c2b60_shell : public Actor
{
    TESRace* FUN_008c2b60_race();
    void ApplyActorSpells();
};

// @fnv 0x008c2b60
void FUN_008c2b60_shell::ApplyActorSpells()
{
    FUN_008c2b60_node* pNode2 = ((::FUN_008c2b60_node *)(reinterpret_cast<::BaseProcess *>((&GetActorBase()->spells))->GetCurrentProcessData()));
    while (pNode2)
    {
        SpellItem* pSpell_2 = *((::SpellItem **)(new ((void *)(pNode2)) ::Vec3()));
        if (pSpell_2 && FUN_00804b30((int)pSpell_2->vfn_18()) && !((bool)(reinterpret_cast<::FlaggedData *>((((FUN_008c2e30_spell*)pSpell_2)))->FUN_008c2e30())))
            reinterpret_cast<::MagicTarget *>((((FUN_00824400_target*)static_cast<MagicTarget *>(this))))->Dispel(pSpell_2, (::MagicCaster *)(void *)(0), (::ActiveEffect *)(void *)(0));
        pNode2 = ((::FUN_008c2b60_node *)(reinterpret_cast<::Callees *>((pNode2))->FUN_00726070()));
    }

    pNode2 = ((FUN_008c2b60_vtbl*)this)->v223() ? ((::FUN_008c2b60_node *)(reinterpret_cast<::BaseProcess *>((&((FUN_008c2b60_vtbl*)this)->v223()->spells))->GetCurrentProcessData())) : 0;
    while (pNode2)
    {
        SpellItem* _pRaceSpell = *((::SpellItem **)(new ((void *)(pNode2)) ::Vec3()));
        if (_pRaceSpell && FUN_00804b30((int)_pRaceSpell->vfn_18()))
            reinterpret_cast<::MagicTarget *>((((FUN_00824400_target*)static_cast<MagicTarget *>(this))))->Dispel(_pRaceSpell, (::MagicCaster *)(void *)(0), (::ActiveEffect *)(void *)(0));
        pNode2 = ((::FUN_008c2b60_node *)(reinterpret_cast<::Callees *>((pNode2))->FUN_00726070()));
    }

    InventoryChanges* pChanges = ::InventoryChanges::CreateForReference(this);
    for (unsigned int i_ = 0; i_ < 5; i_++)
    {
        InventoryStackRecord* pItemCur = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((((FUN_004c8c10_inv*)pChanges)))->FUN_004c8c10((*(int *)&(DAT_011a337c[i_])), false)));
        TESEnchantableForm* pEnchantable = pItemCur ? dynamic_cast<TESEnchantableForm*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pItemCur))->GetName()))) : 0;
        FUN_008c2b60_node* pEnchantmentItem = pEnchantable ? ((::FUN_008c2b60_node *)(reinterpret_cast<::Callees *>((((FUN_008c2b60_node*)pEnchantable)))->FUN_00726070())) : 0;
        if (pEnchantmentItem)
            reinterpret_cast<::FUN_008248e0_shell *>((((FUN_00824400_target*)static_cast<MagicTarget *>(this))))->FUN_008248e0((MagicItem*)((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pItemCur))->GetName())), false);
        delete (FUN_004459e0*)pItemCur;
    }

    TESForm* pFormCur = ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0x13));
    if (pFormCur)
    {
        SpellItem* pAddiction = dynamic_cast<SpellItem*>(pFormCur);
        if (pAddiction && FUN_00804b30((int)pAddiction->vfn_18()))
            reinterpret_cast<::MagicTarget *>((((FUN_00824400_target*)static_cast<MagicTarget *>(this))))->Dispel(pAddiction, (::MagicCaster *)(void *)(0), (::ActiveEffect *)(void *)(0));
    }
}

struct SpellListStub : public ActorMagicSpellList
{
};
struct ActorBaseVtbl
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void MarkAsModified(unsigned int flags);
};
struct MagicTargetStub : public MagicTarget
{
};
struct MagicCasterStub
{
    MagicEffectCollection* apTargetLight;
    MagicCaster__State eState;
    virtual void CastSpellOnCaster(SpellItem* spell, bool immediate);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void CastSpellAtTarget(SpellItem* spell, MagicTarget* target, bool immediate);
};
// Mirrors Actor's leading bases so member calls adjust `this` like the original.
struct ActorAddSpell : public MobileObject, public MagicCasterStub, public MagicTargetStub
{
    bool AddSpellToActor(SpellItem* spell);
};

// @fnv 0x008c32f0
bool ActorAddSpell::AddSpellToActor(SpellItem* spell)
{
    bool bResult = reinterpret_cast<::FloatValueProvider *>(&(static_cast<SpellListStub&>(reinterpret_cast<::Actor *>(this)->GetActorBase()->spells)))->FUN_0048d170(spell);
    if (bResult)
    {
        reinterpret_cast<ActorBaseVtbl*>(reinterpret_cast<::Actor *>(this)->GetActorBase())->MarkAsModified(0x10);
    }
    if (::FUN_00804b30((int)(spell->vfn_18())))
    {
        if (!reinterpret_cast<::MagicTarget *>(this)->HasSpell(spell, true))
        {
            bResult = true;
            CastSpellOnCaster(spell, false);
            CastSpellAtTarget(spell, this, false);
        }
    }
    return bResult;
}

class MagicItem8c30 : public MagicItem
{
  public:
};

class SpellItem8c30 : public TESForm, public MagicItem8c30
{
};

class EnchantableHolder8c30
{
  public:
};

class Actor8c30 : public Actor
{
  public:
    void FUN_008c30a0();
};

// @fnv 0x008c30a0
void Actor8c30::FUN_008c30a0()
{
    BSSimpleList<SpellItem*>* pkIter = ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::BaseProcess *>(&(GetActorBase()->spells))->GetCurrentProcessData()));
    while (pkIter)
    {
        SpellItem8c30* pkSpell = (SpellItem8c30*)((::SpellItem *)(new ((void *)(pkIter)) ::Vec3()));
        if (pkSpell && ::FUN_00804b30((int)(pkSpell->vfn_18())))
            reinterpret_cast<::UnloadMagic *>((pkSpell))->FUN_0040b800(true);
        pkIter = ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070()));
    }
    pkIter = GetRace() ? ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::BaseProcess *>(&(GetRace()->spells))->GetCurrentProcessData())) : 0;
    while (pkIter)
    {
        SpellItem8c30* pkRaceSpell = (SpellItem8c30*)((::SpellItem *)(new ((void *)(pkIter)) ::Vec3()));
        if (pkRaceSpell && ::FUN_00804b30((int)(pkRaceSpell->vfn_18())))
            reinterpret_cast<::UnloadMagic *>((pkRaceSpell))->FUN_0040b800(true);
        pkIter = ((::BSSimpleList< ::SpellItem *> *)(reinterpret_cast<::Callees *>((pkIter))->FUN_00726070()));
    }
    InventoryChanges* pkInvChanges = ::InventoryChanges::CreateForReference(this);
    for (unsigned int i = 0; i < 5; i++)
    {
        InventoryStackRecord* pkWorn = ((::InventoryStackRecord *)(reinterpret_cast<::Target *>((pkInvChanges))->FUN_004c8c10((*(int *)&(DAT_011a337c[i])), false)));
        TESEnchantableForm* pkEnchantable = pkWorn ? dynamic_cast<TESEnchantableForm*>(((::TESBoundObject *)(reinterpret_cast<::Twin_0044ddc0 *>((pkWorn))->GetName()))) : 0;
        SpellItem8c30* pkEnchForm = pkEnchantable ? ((::SpellItem8c30 *)(reinterpret_cast<::Callees *>((((EnchantableHolder8c30*)pkEnchantable)))->FUN_00726070())) : 0;
        if (pkEnchForm)
            reinterpret_cast<::UnloadMagic *>((pkEnchForm))->FUN_0040b800(true);
        delete pkWorn;
    }
    TESForm* pkForm = ::BGSDefaultObjectManager::GetDefaultObjectByIndex((::DEFAULT_OBJECT)(0x13));
    if (pkForm)
    {
        SpellItem8c30* pkDefaultSpell = (SpellItem8c30*)dynamic_cast<SpellItem*>(pkForm);
        if (pkDefaultSpell && ::FUN_00804b30((int)(pkDefaultSpell->vfn_18())))
            reinterpret_cast<::UnloadMagic *>((pkDefaultSpell))->FUN_0040b800(false);
    }
}

struct Sequence8c37
{
};

struct Manager8c37
{
};

class NiRTTI;

struct Child8c37
{
};

struct Node8c37
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void RemoveChildAt(unsigned int uiIndex);
    unsigned int FUN_0043b480();
};

struct AnimSeq8c37
{
};

struct AnimData8c37
{
};

struct Holder8c37
{
    virtual void H000();
    virtual void H001();
    virtual void H002();
    virtual void H003();
    virtual void H004();
    virtual void H005();
    virtual void H006();
    virtual void H007();
    virtual void H008();
    virtual void H009();
    virtual void H010();
    virtual void H011();
    virtual Node8c37* GetNode();
    virtual void* GetSecondary();
};

struct Actor8c37
{
    virtual void A000();
    virtual void A001();
    virtual void A002();
    virtual void A003();
    virtual void A004();
    virtual void A005();
    virtual void A006();
    virtual void A007();
    virtual void A008();
    virtual void A009();
    virtual void A010();
    virtual void A011();
    virtual void A012();
    virtual void A013();
    virtual void A014();
    virtual void A015();
    virtual void A016();
    virtual void A017();
    virtual void A018();
    virtual void A019();
    virtual void A020();
    virtual void A021();
    virtual void A022();
    virtual void A023();
    virtual void A024();
    virtual void A025();
    virtual void A026();
    virtual void A027();
    virtual void A028();
    virtual void A029();
    virtual void A030();
    virtual void A031();
    virtual void A032();
    virtual void A033();
    virtual void A034();
    virtual void A035();
    virtual void A036();
    virtual void A037();
    virtual void A038();
    virtual void A039();
    virtual void A040();
    virtual void A041();
    virtual void A042();
    virtual void A043();
    virtual void A044();
    virtual void A045();
    virtual void A046();
    virtual void A047();
    virtual void A048();
    virtual void A049();
    virtual void A050();
    virtual void A051();
    virtual void A052();
    virtual void A053();
    virtual void A054();
    virtual void A055();
    virtual void A056();
    virtual void A057();
    virtual void A058();
    virtual void A059();
    virtual void A060();
    virtual void A061();
    virtual void A062();
    virtual void A063();
    virtual void A064();
    virtual void A065();
    virtual void A066();
    virtual void A067();
    virtual void A068();
    virtual void A069();
    virtual void A070();
    virtual void A071();
    virtual void A072();
    virtual void A073();
    virtual void A074();
    virtual void A075();
    virtual void A076();
    virtual void A077();
    virtual void A078();
    virtual void A079();
    virtual void A080();
    virtual void A081();
    virtual void A082();
    virtual void A083();
    virtual void A084();
    virtual void A085();
    virtual void A086();
    virtual void A087();
    virtual void A088();
    virtual void A089();
    virtual void A090();
    virtual void A091();
    virtual void A092();
    virtual void A093();
    virtual void A094();
    virtual void A095();
    virtual void A096();
    virtual void A097();
    virtual void A098();
    virtual void A099();
    virtual void A100();
    virtual void A101();
    virtual void A102();
    virtual void A103();
    virtual void A104();
    virtual void A105();
    virtual void A106();
    virtual void A107();
    virtual void A108();
    virtual void A109();
    virtual void A110();
    virtual void A111();
    virtual void A112();
    virtual void A113();
    virtual void A114();
    virtual void A115();
    virtual void A116();
    virtual void A117();
    virtual void A118();
    virtual void A119();
    virtual void A120();
    virtual AnimData8c37* GetAnimData();
    char m_acPad4[0x84];
    Holder8c37 m_kHolder;
    void UpdateAnimationState();
};
// @fnv 0x008c3c40
void Actor::ConfigureActorState(bool first, bool second)
{
    if (reinterpret_cast<::FUN_00576d30_shell *>(this)->FUN_00576d30())
        return;
    AutoMemContext delta((MEM_CONTEXT)50, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\AI\\Actor_Magic.cpp",
                         1253);
    float context = 0.0f;
    float time = reinterpret_cast<::FUN_0096d490_shell *>(&((*reinterpret_cast<::ActorDeletionQueue *>(&::g_011e0e80))))->FUN_0096d490();
    if (first)
        context = DAT_01012640 / (*reinterpret_cast<::Calendar *>(&::g_011de7b8)).GetGameTimeScale();
    else if (second)
        context = ::AngularDashpotApplyD4DCB0::DAT_01017d00;
    else
    {
        context = time - ActorConditionAndAnimationState;
        if (ActorConditionAndAnimationState > time || ActorConditionAndAnimationState < ::_DAT_01012060)
        {
            ActorConditionAndAnimationState = time;
            context = 0.0f;
            if (time > ::_DAT_01012060 && time < DAT_010290d0)
            {
                ActorConditionAndAnimationState = 0.0f;
                context = time;
            }
        }
    }
    if (m_pBaseProcess)
        ((ActorMagicProcess*)m_pBaseProcess)->vfn_700(this, context);
    if (GetSelectedMagicItem())
    {
        bool reset = true;
        NiControllerSequence* sequence = ((ActorMagicProcess*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>(this)->GetBaseTexture())))->GetCurrentSequence();
        if (sequence)
        {
            switch (reinterpret_cast<::BSAnimGroupSequence *>((sequence))->GetAnimGroup()->GetType())
            {
            case 26:
            case 29:
            case 32:
            case 35:
            case 38:
            case 41:
            case 44:
            case 47:
            case 50:
            case 53:
            case 56:
            case 59:
            case 62:
            case 65:
            case 68:
            case 71:
            case 74:
            case 77:
            case 92:
                reset = false;
                break;
            }
        }
        if (reset)
            SetCurrentSpellState(0);
    }
    if (reinterpret_cast<::FUN_008c4560_shell *>(this)->FUN_008c4560())
        reinterpret_cast<::Actor8c37 *>(this)->UpdateAnimationState();
    if (apTargetLight)
        reinterpret_cast<::B8B10Owner *>(this)->UpdateEffect(context);
    MagicTarget::UpdateActiveEffects(context);
    if (!HasHealth(false))
    {
        if (IsPlayerRef())
            reinterpret_cast<::RestoreActionPointsDetail::RestoreActionPointsEntry *>(this)->FUN_0088b660(context);
        if (m_pBaseProcess && reinterpret_cast<::FUN_008aced0_cls *>((((ActorMagicProcess*)m_pBaseProcess)))->HasCachedFlag(0x20000000))
            reinterpret_cast<::FUN_0088b510_cls *>(this)->SetScaledValue(context);
        if ((m_pBaseProcess && reinterpret_cast<::FUN_008aced0_cls *>((((ActorMagicProcess*)m_pBaseProcess)))->HasCachedFlag(0x40000000)) ||
            reinterpret_cast<::FUN_00893500_shell *>(this)->FUN_00893500() < ::_DAT_01012060)
            reinterpret_cast<::B88B5A0Actor *>(this)->ApplyFatigueDamage(context);
        Unk_F7(context);
    }
    ActorConditionAndAnimationState = time;
}

class NiRTTI;

struct Sequence8c39
{
};

struct Manager8c39
{
};

static const float s_fMaxTime = 3.402823466e+38F;


struct Model8c39
{
};

struct Node8c39
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void AttachChildInAvailableSlot(Model8c39* pkChild, bool abFirstAvailableSlot);
};

struct LightData8c39
{
};

struct SoundFile8c39
{
    unsigned int FUN_0048cee0();
};

struct Effect8c39
{
    char m_acForm[0x18];
    SoundFile8c39 m_kSound;
};

struct Source8c39
{
    Effect8c39* FUN_0040a300(int iIndex);
};

Model8c39* __cdecl FUN_0081e440(Effect8c39* pkEffect);

struct FUN_0081bf80
{
    FUN_0081bf80(void* pkLightData, Node8c39* pkMagicNode);
    ~FUN_0081bf80();
    int m_kNextStreamField[7];
};

struct Holder8c39
{
    virtual void H000();
    virtual void H001();
    virtual void H002();
    virtual void H003();
    virtual void H004();
    virtual void H005();
    virtual void H006();
    virtual void H007();
    virtual void H008();
    virtual void H009();
    virtual void H010();
    virtual void H011();
    virtual Node8c39* GetNode();
};

struct Actor8c39
{
    char m_acPad0[0x88];
    Holder8c39 m_kHolder;
    FUN_0081bf80* m_pkLight;
    void AttachMagicEffect(Source8c39* pkSource);
};
// @fnv 0x008c3790
void Actor8c37::UpdateAnimationState()
{
    Node8c37* pkGroupNode = m_kHolder.GetNode();
    if (!pkGroupNode)
    {
        reinterpret_cast<::TES *>(this)->FUN_008c45a0(0);
        return;
    }
    void* pkAttachRoot = m_kHolder.GetSecondary();
    bool bFound = false;
    AnimData8c37* pkAnimData = GetAnimData();
    if (pkAnimData)
    {
        if (pkAttachRoot)
        {
            bool bAlt = false;
            AnimSeq8c37* pkSeq = ((::AnimSeq8c37 *)(reinterpret_cast<::FUN_00491040_shell *>((pkAnimData))->FUN_00491040(bAlt ? 4 : 2)));
            if (pkSeq && ((int)(reinterpret_cast<::LowProcess *>((pkSeq))->GetActiveCombatTarget())) == 1)
                bFound = true;
        }
        else
        {
            AnimSeq8c37* pkSeq2 = ((::AnimSeq8c37 *)(reinterpret_cast<::FUN_00491040_shell *>((pkAnimData))->FUN_00491040(2)));
            if (pkSeq2 && ((int)(reinterpret_cast<::LowProcess *>((pkSeq2))->GetActiveCombatTarget())) == 1)
                bFound = true;
        }
    }
    if (pkAttachRoot)
    {
        if (((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((pkGroupNode))->FUN_00453470())) == 0 && bFound)
            reinterpret_cast<::Actor8c39 *>(this)->AttachMagicEffect((::Source8c39 *)(pkAttachRoot));
        return;
    }
    if (((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((pkGroupNode))->FUN_00453470())) > 0)
    {
        if (!bFound)
            reinterpret_cast<::FUN_004def90_Class *>((pkGroupNode))->FUN_004def90();
        for (unsigned int i = 0; i < pkGroupNode->FUN_0043b480(); i++)
        {
            Child8c37* pkElem = ((::Child8c37 *)(reinterpret_cast<::NiNode *>((pkGroupNode))->GetAt(i)));
            void* pkTimeCtrl = pkElem ? ((void *)(::fnv_0043b230::FUN_0043b230((const char *)(pkElem)))) : 0;
            Manager8c37* pkManager = pkTimeCtrl ? (Manager8c37*)((void *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(pkTimeCtrl)))) : 0;
            Sequence8c37* pkSequence = pkManager ? ((::Sequence8c37 *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((pkManager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)(::NiFixedString *)(FUN_00499b80())))) : 0;
            if (pkSequence && reinterpret_cast<::BSFaceGenMorphData *>((pkSequence))->FUN_00508120() > reinterpret_cast<::FUN_00508100_shell *>((pkSequence))->FUN_00508100())
                pkGroupNode->RemoveChildAt(i);
        }
    }
    if (((unsigned int)(reinterpret_cast<::FUN_00453470_shell *>((pkGroupNode))->FUN_00453470())) == 0)
        reinterpret_cast<::TES *>(this)->FUN_008c45a0(0);
}

// @fnv 0x008c39b0
void Actor8c39::AttachMagicEffect(Source8c39* pkSource)
{
    Model8c39* pkModel = 0;
    Effect8c39* pkEffect = 0;
    if (pkSource)
    {
        pkEffect = pkSource->FUN_0040a300(0);
        if (pkEffect && pkEffect->m_kSound.FUN_0048cee0() > 0)
            pkModel = FUN_0081e440(pkEffect);
    }
    Node8c39* pkMagicNode = m_kHolder.GetNode();
    if (pkMagicNode && pkModel)
    {
        reinterpret_cast<::FUN_004def90_Class *>((pkMagicNode))->FUN_004def90();
        pkMagicNode->AttachChildInAvailableSlot(pkModel, true);
        if (((::LightData8c39 *)(reinterpret_cast<::FUN_004fd380_shell *>((pkEffect))->FUN_004fd380())) && !((bool)(::FUN_00525420())))
        {
            if (m_pkLight)
                delete m_pkLight;
            m_pkLight = 0;
            FUN_0081bf80* pkLight = new FUN_0081bf80(((void *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::LightData8c39 *)(reinterpret_cast<::FUN_004fd380_shell *>((pkEffect))->FUN_004fd380()))))->FUN_0084e3a0())), pkMagicNode);
            reinterpret_cast<::CombatProcedure *>(&(m_kHolder))->Initialize((::CombatController *)(pkLight));
        }
        void* pkControl = ((void *)(::fnv_0043b230::FUN_0043b230((const char *)(pkModel))));
        Manager8c39* pkManager = (Manager8c39*)((void *)(::FUN_00653270(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac)), (::NiObject *)(pkControl))));
        Sequence8c39* pkSequence = pkManager ? ((::Sequence8c39 *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((pkManager))->FUN_0047a520((::fnv_0047a520::NFSHelper *)(::NiFixedString *)(FUN_00499b80())))) : 0;
        if (pkSequence)
        {
            reinterpret_cast<::NiControllerManager *>((pkManager))->DeactivateAllSequences(0.0f);
            reinterpret_cast<::NiControllerManager *>((pkManager))->ActivateControllerSequence((::NiControllerSequence *)(pkSequence), 0, 0, 1.0f, 0.0f, (::NiControllerSequence *)(0));
            reinterpret_cast<::TaskQueueInterface *>((pkManager))->QueueReferenceStateTask(true);
            reinterpret_cast<::FUN_0098adb0_shell *>((pkSequence))->FUN_0098adb0(-s_fMaxTime);
            if (m_pkLight)
                reinterpret_cast<::FUN_0081c470_shell *>((m_pkLight))->FUN_0081c470(true, reinterpret_cast<::FUN_00508100_shell *>((pkSequence))->FUN_00508100() * 0.75);
        }
        if (m_pkLight)
            reinterpret_cast<::MagicEffectCollection *>((m_pkLight))->UpdateLightFade(0.0f);
    }
}

struct Setting5610
{
};
struct Sound5610
{
};
struct Magic5610
{
    char x;
};
struct Prefix5610
{
    char x[24];
};
struct Spell5610 : Prefix5610, Magic5610
{
};
struct Stage5610
{
};
struct Target5610
{
};
struct Value5610
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float Get(int);
};
struct Caster5610
{
    virtual void v0();
    virtual void v1();
    virtual void Cast(Spell5610*, int);
};
template <int N> struct Tag5610
{
};
template <int N> struct Virtual5610 : Virtual5610<N - 1>
{
    virtual void gap(Tag5610<N>*);
};
template <> struct Virtual5610<0>
{
    virtual void gap(Tag5610<0>*);
};
struct Actor5610 : Virtual5610<215>
{
    virtual bool Valid();
};
struct UI5610
{
};
struct Owner5610
{
    static void UpdateStageChange(void*, int, float, float);
};
// Compares the actor's current and previous stage values and, when they differ, applies the old/new stage effects and shows a HUD message for the player.
// @fnv 0x008c5610
void Owner5610::UpdateStageChange(void* apActor, int aiValueIndex, float oldValue, float delta)
{
    Actor5610* actor = apActor ? (Actor5610*)((char*)apActor - 0xa4) : 0;
    if (!actor || !actor->Valid())
        return;
    float current = ((Value5610*)((char*)actor + 0xa4))->Get(aiValueIndex);
    Stage5610* oldStage = ((::Stage5610 *)(::BGSDehydrationStage::FindStage(oldValue)));
    Stage5610* newStage = ((::Stage5610 *)(::BGSDehydrationStage::FindStage(current)));
    if (oldStage != newStage)
    {
        if (oldStage)
            reinterpret_cast<::MagicTarget *>((((Target5610*)((char*)actor + 0x94))))->Dispel((::MagicItem *)(::Magic5610 *)(((::Spell5610 *)(reinterpret_cast<::BGSTerrainManager *>((oldStage))->GetMinLevel()))), (::MagicCaster *)(void *)(0), (::ActiveEffect *)(void *)(0));
        if (newStage)
            ((Caster5610*)((char*)actor + 0x88))->Cast(((::Spell5610 *)(reinterpret_cast<::BGSTerrainManager *>((newStage))->GetMinLevel())), 0);
        if (actor == *(Actor5610**)&(*reinterpret_cast<char *>(&::_g_thePlayer)))
        {
            char buffer[256];
            if (delta > 0.0)
            {
                std::sprintf(buffer, ((const char *)(reinterpret_cast<::StartMenu *>((((Setting5610*)&(*reinterpret_cast<char *>(&::g_011d2f40)))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)(&(*reinterpret_cast<char *>((void *)&::g_011cba64_arg1))), (const char *)(0), 2.0f, false);
            }
            else
            {
                std::sprintf(buffer, ((const char *)(reinterpret_cast<::StartMenu *>((((Setting5610*)&(*reinterpret_cast<char *>(&::g_011d4b7c)))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)(&(*reinterpret_cast<char *>((void *)&::g_011cba00_arg1))), (const char *)(0), 2.0f, false);
            }
            if (newStage)
            {
                std::sprintf(buffer, &(*reinterpret_cast<char *>((void *)&::DAT_01012058)), ((const char *)(reinterpret_cast<::StartMenu *>((((Setting5610*)&(*reinterpret_cast<char *>(&::g_011d3ebc)))))->GetMenuTitle())),
                             ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((Sound5610*)((char*)((::Spell5610 *)(reinterpret_cast<::BGSTerrainManager *>((newStage))->GetMinLevel())) + 0x18))))->FUN_00408da0())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)(&(*reinterpret_cast<char *>((void *)&::g_011cba64_arg1))), (const char *)(0), 2.0f, false);
            }
            else
            {
                std::sprintf(buffer, ((const char *)(reinterpret_cast<::StartMenu *>((((Setting5610*)&(*reinterpret_cast<char *>(&::g_011d4fd8)))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)(&(*reinterpret_cast<char *>((void *)&::g_011cba00_arg1))), (const char *)(0), 2.0f, false);
            }
            reinterpret_cast<::MagicTarget *>((((Target5610*)((char*)actor + 0x94))))->UpdateActiveEffects(0.0f);
        }
    }
}

struct Sound5890
{
};
struct Prefix5890
{
    char pad[0x18];
};
struct Spell5890 : Prefix5890, Sound5890
{
};
struct Stage5890
{
};
struct Setting5890
{
};
struct Target5890
{
    char pad[0x10];
};
struct Caster5890
{
    virtual void x0();
    virtual void x1();
    virtual void FUN_cast(Spell5890*, int);
    char pad[8];
};
struct Values5890
{
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual float FUN_value(int);
};
struct Slots8
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};
struct Slots16 : Slots8
{
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
};
struct Slots32 : Slots16
{
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
};
struct Slots64 : Slots32
{
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
};
struct Slots128 : Slots64
{
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
};
struct Slots216 : Slots128
{
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
    virtual void f177();
    virtual void f178();
    virtual void f179();
    virtual void f180();
    virtual void f181();
    virtual void f182();
    virtual void f183();
    virtual void f184();
    virtual void f185();
    virtual void f186();
    virtual void f187();
    virtual void f188();
    virtual void f189();
    virtual void f190();
    virtual void f191();
    virtual void f192();
    virtual void f193();
    virtual void f194();
    virtual void f195();
    virtual void f196();
    virtual void f197();
    virtual void f198();
    virtual void f199();
    virtual void f200();
    virtual void f201();
    virtual void f202();
    virtual void f203();
    virtual void f204();
    virtual void f205();
    virtual void f206();
    virtual void f207();
    virtual void f208();
    virtual void f209();
    virtual void f210();
    virtual void f211();
    virtual void f212();
    virtual void f213();
    virtual void f214();
    virtual void f215();
};
struct Actor5890 : Slots216
{
    virtual bool FUN_valid();
    char pad[0x84];
    Caster5890 caster;
    Target5890 target;
    Values5890 values;
};
struct Entry5890
{
    static void __cdecl UpdateStageTransition(Values5890*, int, float, float);
};
// @fnv 0x008c5890
void __cdecl Entry5890::UpdateStageTransition(Values5890* pValues, int index, float before, float delta)
{
    char buffer[256];
    Actor5890* actor = pValues ? reinterpret_cast<Actor5890*>(reinterpret_cast<char*>(pValues) - 0xa4) : 0;
    if (!actor || !actor->FUN_valid())
        return;
    float current = actor->values.FUN_value(index);
    Stage5890* oldStage = ((::Stage5890 *)(::FindHungerStage(before)));
    Stage5890* newStage = ((::Stage5890 *)(::FindHungerStage(current)));
    if (oldStage != newStage)
    {
        if (oldStage)
            reinterpret_cast<::MagicTarget *>(&(actor->target))->Dispel((::MagicItem *)(::Sound5890 *)(((::Spell5890 *)(reinterpret_cast<::BGSTerrainManager *>((oldStage))->GetMinLevel()))), (::MagicCaster *)(void *)(0), (::ActiveEffect *)(void *)(0));
        if (newStage)
            actor->caster.FUN_cast(((::Spell5890 *)(reinterpret_cast<::BGSTerrainManager *>((newStage))->GetMinLevel())), 0);
        if (actor == *reinterpret_cast<Actor5890**>(&(*reinterpret_cast<char *>(&::_g_thePlayer))))
        {
            if (delta > 0.0)
            {
                sprintf(buffer, ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<Setting5890*>(&(*reinterpret_cast<char *>(&::g_011d1fd4)))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)(&(*reinterpret_cast<char *>((void *)&::g_011cba64_arg1))), (const char *)(0), 2.0f, false);
            }
            else
            {
                sprintf(buffer, ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<Setting5890*>(&(*reinterpret_cast<char *>(&::g_011d4c6c)))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)(&(*reinterpret_cast<char *>((void *)&::g_011cba00_arg1))), (const char *)(0), 2.0f, false);
            }
            if (newStage)
            {
                sprintf(buffer, &(*reinterpret_cast<char *>((void *)&::DAT_01012058)), ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<Setting5890*>(&(*reinterpret_cast<char *>(&::g_011d3ebc)))))->GetMenuTitle())),
                        ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(((::Spell5890 *)(reinterpret_cast<::BGSTerrainManager *>((newStage))->GetMinLevel()))))->FUN_00408da0())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)(&(*reinterpret_cast<char *>((void *)&::g_011cba64_arg1))), (const char *)(0), 2.0f, false);
            }
            else
            {
                sprintf(buffer, ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<Setting5890*>(&(*reinterpret_cast<char *>(&::g_011d3a14)))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)(&(*reinterpret_cast<char *>((void *)&::g_011cba00_arg1))), (const char *)(0), 2.0f, false);
            }
            reinterpret_cast<::MagicTarget *>(&(actor->target))->UpdateActiveEffects(0.0f);
        }
    }
}


struct ActorRefStandIn
{
    virtual void v000();
    int unk04;
};

struct ActorValueOwnerStandIn
{
    virtual int GetBaseActorValue(int aeActorValueIndex);
    virtual float GetBaseActorValueFloat(int aeActorValueIndex);
    virtual int GetActorValue(int aeActorValueIndex);
    virtual float GetCurrentActorValue(int aeActorValueIndex);
    virtual float GetPermanentActorValueFloat(int aeActorValueIndex);
    virtual float GetTemporaryActorValue(int aeActorValueIndex);
    virtual float GetDamageActorValue(int aeActorValueIndex);
    virtual int FUN_0093ad30(int aeActorValueIndex);
    virtual float GetPermanentActorValueAdjustment(int aeActorValueIndex);
};

struct ActorStandIn : ActorRefStandIn, ActorValueOwnerStandIn
{
    virtual int FUN_0093ad30(int aeActorValueIndex);
};

// @fnv 0x0093ad30
int ActorStandIn::FUN_0093ad30(int aiActorValueIndex)
{
    return (int)FUN_00406ce0(GetPermanentActorValueAdjustment(aiActorValueIndex));
}

namespace fnv_0093ad60 {

struct ActorRefStandIn
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c();
    virtual void v020(), v024(), v028(), v02c(), v030(), v034(), v038(), v03c();
    virtual void v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c();
    virtual void v060(), v064(), v068(), v06c(), v070(), v074(), v078(), v07c();
    virtual void v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c();
    virtual void v0a0(), v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc();
    virtual void v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(), v0dc();
    virtual void v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc();
    virtual void v100(), v104(), v108(), v10c(), v110(), v114(), v118(), v11c();
    virtual void v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c();
    virtual void v140(), v144(), v148(), v14c(), v150(), v154(), v158(), v15c();
    virtual void v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c();
    virtual void v180(), v184(), v188(), v18c(), v190(), v194(), v198(), v19c();
    virtual void v1a0(), v1a4(), v1a8(), v1ac(), v1b0(), v1b4(), v1b8(), v1bc();
    virtual void v1c0(), v1c4(), v1c8(), v1cc(), v1d0(), v1d4(), v1d8(), v1dc();
    virtual void v1e0(), v1e4(), v1e8(), v1ec(), v1f0(), v1f4(), v1f8(), v1fc();
    virtual void v200(), v204(), v208(), v20c(), v210(), v214(), v218(), v21c();
    virtual void v220(), v224(), v228(), v22c(), v230(), v234(), v238(), v23c();
    virtual void v240(), v244(), v248(), v24c(), v250(), v254(), v258(), v25c();
    virtual void v260(), v264(), v268(), v26c(), v270(), v274(), v278(), v27c();
    virtual void v280(), v284(), v288(), v28c(), v290(), v294(), v298(), v29c();
    virtual void v2a0(), v2a4(), v2a8(), v2ac(), v2b0(), v2b4(), v2b8(), v2bc();
    virtual void v2c0(), v2c4(), v2c8(), v2cc(), v2d0(), v2d4(), v2d8(), v2dc();
    virtual void v2e0(), v2e4(), v2e8(), v2ec(), v2f0(), v2f4(), v2f8(), v2fc();
    virtual void v300(), v304(), v308(), v30c(), v310(), v314(), v318(), v31c();
    virtual void v320(), v324(), v328(), v32c(), v330(), v334(), v338(), v33c();
    virtual void v340(), v344(), v348(), v34c(), v350(), v354(), v358(), v35c();
    virtual void v360(), v364(), v368(), v36c(), v370(), v374(), v378(), v37c();
    virtual void v380(), v384(), v388(), v38c(), v390(), v394(), v398(), v39c();
    virtual void v3a0(), v3a4(), v3a8(), v3ac(), v3b0(), v3b4(), v3b8(), v3bc();
    virtual void v3c0(), v3c4(), v3c8(), v3cc(), v3d0(), v3d4(), v3d8(), v3dc();
    virtual void v3e0(), v3e4(), v3e8(), v3ec(), v3f0(), v3f4(), v3f8(), v3fc();
    virtual void v400(), v404(), v408(), v40c(), v410(), v414(), v418(), v41c();
    virtual void v420(), v424(), v428(), v42c(), v430(), v434(), v438(), v43c();
    virtual void v440(), v444(), v448(), v44c(), v450(), v454(), v458(), v45c();
    virtual void v460(), v464(), v468(), v46c(), v470(), v474(), v478(), v47c();
    virtual void v480(), v484(), v488();
    virtual float GetSkillBonus(int aeActorValueIndex, bool* pbFlag);
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    int unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
    int unk44, unk48, unk4c, unk50, unk54, unk58, unk5c, unk60;
    int unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    int unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0;
};

struct ActorValueOwnerStandIn
{
    virtual int GetBaseActorValue(int aeActorValueIndex);
    virtual float GetBaseActorValueFloat(int aeActorValueIndex);
    virtual int GetActorValue(int aeActorValueIndex);
    virtual float FUN_0093ad60(int aeActorValueIndex);
    virtual float GetPermanentActorValueFloat(int aeActorValueIndex);
    virtual float GetTemporaryActorValue(int aeActorValueIndex);
    virtual float GetDamageActorValue(int aeActorValueIndex);
};

struct ActorStandIn : ActorRefStandIn, ActorValueOwnerStandIn
{
    virtual float FUN_0093ad60(int aeActorValueIndex);
};


// @fnv 0x0093ad60
float ActorStandIn::FUN_0093ad60(int aiActorValue)
{
    bool bFlag;
    float fResult = 0.0f;
    if (::FUN_0047f060(aiActorValue))
    {
        fResult = ::GetSkillValue((::ActorStub *)(void *)(static_cast<ActorValueOwnerStandIn*>((*reinterpret_cast<::fnv_0093ad60::ActorStandIn * *>(&::_g_thePlayer)))), aiActorValue, true) +
                  GetSkillBonus(aiActorValue, &bFlag) + GetDamageActorValue(aiActorValue);
    }
    else
    {
        fResult = GetBaseActorValueFloat(aiActorValue) + GetDamageActorValue(aiActorValue);
    }
    return ::ActorValue::ClampValue((::ActorValue::Index)(aiActorValue), fResult);
}
}  // namespace fnv_0093ad60

namespace fnv_008c5350 {
struct StandMagicItem
{
};
struct SpellBase
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
};
struct Spell : SpellBase, StandMagicItem
{
};
struct Stage
{
};
struct StandMagicCaster
{
    virtual void v0();
    virtual void v1();
    virtual void Cast(Spell*, bool);
    int unk04, unk08;
};
struct StandMagicTarget
{
    virtual void v0();
    int unk04, unk08, unk0C;
};
struct StandActorValueOwner
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float Get(int);
    int unk04;
};
struct ActorBase
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual bool IsPlayer();
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
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
};
struct StandActor : ActorBase, StandMagicCaster, StandMagicTarget, StandActorValueOwner
{
};
struct Setting
{
};
// When the player's actor value crosses a spell stage boundary, remove the old stage spell, cast the new one, and queue Vault Boy UI messages.
// @fnv 0x008c5350
void OnActorValueStageChange(StandActorValueOwner* owner, int aiActorValue, float oldValue, float delta)
{
    StandActor* actor = static_cast<StandActor*>(owner);
    if (!actor || !actor->IsPlayer())
        return;
    float value = actor->Get(aiActorValue);
    if (actor->IsPlayer() && delta != 0.0)
        reinterpret_cast<::B968730Actor *>(((*reinterpret_cast<::fnv_008c5350::StandActor * *>(&::_g_thePlayer))))->FUN_00968730();
    Stage* oldStage = ((::fnv_008c5350::Stage *)(::BGSRadiationStage::GetStageForLevel(oldValue)));
    Stage* newStage = ((::fnv_008c5350::Stage *)(::BGSRadiationStage::GetStageForLevel(value)));
    if (oldStage != newStage)
    {
        if (oldStage)
            reinterpret_cast<::MagicTarget *>((actor))->Dispel((::MagicItem *)(::fnv_008c5350::StandMagicItem *)(static_cast<StandMagicItem*>(((::fnv_008c5350::Spell *)(reinterpret_cast<::BGSTerrainManager *>((oldStage))->GetMinLevel())))), (::MagicCaster *)(void *)(0), (::ActiveEffect *)(void *)(0));
        if (newStage)
            actor->Cast(((::fnv_008c5350::Spell *)(reinterpret_cast<::BGSTerrainManager *>((newStage))->GetMinLevel())), false);
        if (actor == (*reinterpret_cast<::fnv_008c5350::StandActor * *>(&::_g_thePlayer)))
        {
            char buffer[256];
            if (delta > 0.0)
            {
                sprintf(buffer, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_008c5350::Setting *>(&::g_011d3384))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_in_pain.dds"), (const char *)(0), 2.0f,
                               false);
            }
            else
            {
                sprintf(buffer, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_008c5350::Setting *>(&::g_011d40a8))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_very_happy.dds"), (const char *)(0),
                               2.0f, false);
            }
            if (newStage)
            {
                sprintf(buffer, "%s %s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_008c5350::Setting *>(&::g_011d3ebc))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::fnv_008c5350::Spell *)(reinterpret_cast<::BGSTerrainManager *>((newStage))->GetMinLevel()))))->FUN_00408da0())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_in_pain.dds"), (const char *)(0), 2.0f,
                               false);
            }
            else
            {
                sprintf(buffer, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_008c5350::Setting *>(&::g_011d29ac))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(buffer), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_very_happy.dds"), (const char *)(0),
                               2.0f, false);
            }
            reinterpret_cast<::MagicTarget *>((actor))->UpdateActiveEffects(0.0f);
        }
    }
}
}  // namespace fnv_008c5350

#include <xmmintrin.h>
struct SightActor;
struct SightVec
{
    float x, y, z;
};
struct SightBase;
struct SightProcess;
struct SightWorld;
struct SightScene;
struct SightFilter;
struct SightFilterBits
{
    unsigned int bits;
    unsigned int FUN_004a3a20();
};
struct SightCollector
{
    int word00;
    int word04;
    int word08;
    int word0c;
    int word10;
    int word14;
    int word18;
    int word1c;
    int word20;
    int word24;
    int word28;
    int word2c;
    int word30;
    int word34;
    int word38;
    int word3c;
    int word40;
    int word44;
    int word48;
    int word4c;
    int word50;
    int word54;
    int word58;
    int word5c;
    int word60;
    int word64;
    int word68;
    int word6c;
    int word70;
    int word74;
    int word78;
    int word7c;
    int word80;
    SightCollector(int, SightActor*);
    ~SightCollector();
};
struct SightRay
{
    int word00;
    int word04;
    int word08;
    int word0c;
    int word10;
    int word14;
    int word18;
    int word1c;
    int word20;
    int word24;
    int word28;
    int word2c;
    int word30;
    int word34;
    int word38;
    int word3c;
    int word40;
    int word44;
    int word48;
    int word4c;
    int word50;
    int word54;
    int word58;
    int word5c;
    int word60;
    int word64;
    int word68;
    int word6c;
    int word70;
    int word74;
    int word78;
    int word7c;
    int word80;
    int word84;
    int word88;
    int word8c;
    int word90;
    int word94;
    int word98;
    int word9c;
    int worda0;
    int worda4;
    int worda8;
    int wordac;
    void FUN_004a3f70(unsigned int);
};
struct SightFilter
{
    unsigned int bits;
    SightFilter(int);
    unsigned int FUN_004a3a20();
};
struct __declspec(align(16)) SightHkVec
{
    __m128 q;
};
struct SightBounds
{
    SightHkVec low, high;
};
void* __cdecl FUN_006e7620(int, int);
void __cdecl FUN_005e0b60(void*);
struct SightSetting
{
};
extern unsigned char DAT_011df678;
extern float runtimeInitializationFloat3647;
extern float DAT_011a32dc;
struct SightTES
{
    void* FUN_00458420(SightRay*);
};
struct SightBase
{
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
    virtual void* Race();
};
struct SightProcess
{
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
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22c();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual bool Test(SightActor*, SightActor*, int, bool);
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual void v69c();
    virtual void v6a0();
    virtual void v6a4();
    virtual void v6a8();
    virtual void v6ac();
    virtual void v6b0();
    virtual void v6b4();
    virtual void v6b8();
    virtual void v6bc();
    virtual void v6c0();
    virtual void v6c4();
    virtual void v6c8();
    virtual void v6cc();
    virtual void v6d0();
    virtual SightScene* Head();
    virtual SightScene* Body();
};
struct SightScene
{
    const SightVec& FUN_0045bb80();
};
struct SightFilterWorld
{
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
    virtual int Count();
    virtual void v064();
    virtual void Query(SightBounds*, void*);
};
struct SightWorldInner
{
};
struct SightWorld
{
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
    virtual SightWorldInner* GetInner();
};
struct SightActor
{
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
    virtual bool IsActorLike();
    virtual bool IsActor();
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
    virtual void* HasNode();
    virtual void v1d4();
    virtual SightVec Min();
    virtual SightVec Max();
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
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual bool IsDead(int);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual bool CanSeeDead();
    virtual void v364();
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual int Unk428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual bool ShortRay();
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    SightProcess* process;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    SightActor* target;

    void FUN_00931ed0(SightFilterBits*);
    bool FUN_0088b880(bool, SightActor*, bool, int*, bool);
};
struct SightCell
{
};

// Checks visibility through the sight process or ray checks; ray checks can write a code to result.
// @fnv 0x0088b880
bool SightActor::FUN_0088b880(bool force, SightActor* other, bool mode, int* result, bool skipAngle)
{
    bool visible = false;
    SightActor* actor = 0;
    if (!other || !other->HasNode())
        return visible;
    bool state = ((bool)(reinterpret_cast<::FUN_00493bb0_Class *>(this)->FUN_00493bb0()));
    if (other->IsDead(0) && !CanSeeDead() && !force)
        return visible;
    if (other->IsActor())
        actor = other;
    if (((double)(reinterpret_cast<::RefS *>(this)->FUN_005723b0((::RefS *)(other), 0, 0))) <= 2.0)
    {
        skipAngle = true;
        return true;
    }
    if (!force)
    {
        if (process)
            visible = process->Test(this, actor, 0, skipAngle);
    }
    else if (force || !actor)
    {
        if (result)
            *result = 3;
        if (other)
        {
            if (skipAngle ||
                reinterpret_cast<::FUN_0088c570_shell *>(this)->IsPointInConeFOV(((::SightVec *)(reinterpret_cast<::TESTopicInfo *>((other))->GetAddTopicList())),
                                 (float)(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SightSetting *>(&::originalRuntimeFloatSetting103)))))) * 0.01745329238474369)))
            {
                if (DAT_011df678)
                {
                    if (result)
                        *result = 2;
                    return true;
                }
                SightCell* cell = (SightCell*)((void *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
                if (!cell)
                    return false;
                SightVec start;
                new ((void *)&(start)) ::Vec3();
                SightScene* source = 0;
                SightBase* base = ((::SightBase *)(reinterpret_cast<::Actor *>(this)->GetActorBase()));
                void* race = base->Race();
                if (race && this != (*reinterpret_cast<::SightActor * *>(&::_g_thePlayer)))
                    source = process->Head();
                if (source)
                    start = source->FUN_0045bb80();
                else
                    start = *((::SightVec *)(reinterpret_cast<::TESTopicInfo *>(this)->GetAddTopicList()));
                float height = 0.0f;
                if (reinterpret_cast<::Actor *>(this)->IsSneaking())
                    height = reinterpret_cast<::FUN_008854d0_ *>(this)->FUN_008854d0(mode);
                else
                    height = mode ? reinterpret_cast<::fnv_008be940::FloatValueProvider *>(this)->FUN_008be940() : reinterpret_cast<::fnv_008853a0::FUN_008853a0_shell *>(this)->GetActorHeight() * 0.75;
                if (!source)
                    start.z += height;
                if (reinterpret_cast<::TESCallHelper *>(((*reinterpret_cast<::SightTES * *>(&::g_TES))))->IsCellBuffered((::TESObjectCELL *)(cell), 1))
                {
                    SightRay ray;
                    new ((void *)&(ray)) ::FUN_004a3c20();
                    SightActor* ref = 0;
                    if (other && other->IsActorLike())
                        ref = other;
                    SightCollector collector(0x25, ref);
                    reinterpret_cast<::FUN_0059ceb0_shell *>(&(ray))->FUN_0059ceb0((::hkpClosestRayHitCollector *)(::SightCollector *)(&collector));
                    SightVec end = *((::SightVec *)(reinterpret_cast<::TESTopicInfo *>((other))->GetAddTopicList()));
                    reinterpret_cast<::fnv_004a3da0::FUN_004a3da0_shell *>(&(ray))->FUN_004a3da0(&start);
                    SightFilterBits filter;
                    FUN_00931ed0(&filter);
                    SightFilter rayFilter(0);
                    reinterpret_cast<::FUN_004a39f0_shell *>(&(rayFilter))->FUN_004a39f0(0x25);
                    reinterpret_cast<::FUN_0059ce80_shell *>(&(rayFilter))->FUN_0059ce80(reinterpret_cast<::fnv_004a3a20::FUN_004a3a20_shell *>(&(filter))->FUN_004a3a20());
                    ray.FUN_004a3f70(rayFilter.bits);
                    float extent = reinterpret_cast<::fnv_00567400::FUN_00567400_shell *>((other))->FUN_00567400() * (other->Max().z - other->Min().z);
                    float fractions[3] = {0.75f, 0.5f, 0.25f};
                    int codes[3] = {2, 1, 0};
                    SightScene* nodes[3] = {0, 0, 0};
                    if (actor)
                    {
                        SightBase* targetBase = ((::SightBase *)(reinterpret_cast<::Actor *>((actor))->GetActorBase()));
                        void* targetRace = targetBase->Race();
                        if (targetRace)
                        {
                            SightProcess* p = ((::SightProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()));
                            nodes[0] = p->Head();
                            SightProcess* pProcess2 = ((::SightProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()));
                            nodes[1] = pProcess2->Body();
                        }
                    }
                    float baseZ = end.z;
                    int count = 1;
                    int unusedState = Unk428();
                    if ((actor && actor == (*reinterpret_cast<::SightActor * *>(&::_g_thePlayer))) || actor == target || this == (*reinterpret_cast<::SightActor * *>(&::_g_thePlayer)))
                        count = 3;
                    void* buffer = 0;
                    SightWorld* world = ((::SightWorld *)(reinterpret_cast<::FUN_004543c0_cls *>((cell))->FUN_004543c0()));
                    SightHkVec pos;
                    new ((void *)&(pos)) ::Vec3();
                    ::CopyCharacterControllerVector((::bhkCharacterController *)(::SightHkVec *)(&pos), (const ::NiPoint3 &)(start));
                    SightBounds bounds;
                    reinterpret_cast<::Holder *>(&(bounds))->FUN_00628950((::Holder *)(::SightHkVec *)(&pos), (::Holder *)(::SightHkVec *)(&pos));
                    for (int i = 0; i < count; ++i)
                    {
                        if (nodes[i])
                            ::CopyCharacterControllerVector((::bhkCharacterController *)(::SightHkVec *)(&pos), (const ::NiPoint3 &)(nodes[i]->FUN_0045bb80()));
                        else
                        {
                            ::CopyCharacterControllerVector((::bhkCharacterController *)(::SightHkVec *)(&pos), (const ::NiPoint3 &)(end));
                            reinterpret_cast<::bhkCharacterController *>(&(pos))->GetVectorElement(2) = extent * fractions[i] + baseZ;
                        }
                        reinterpret_cast<::VecHolder *>(&(bounds))->FUN_006285e0(&bounds, &pos);
                        reinterpret_cast<::S00628640_Vector *>(&(bounds.high))->FUN_00628640((const ::S00628640_Source *)(::SightHkVec *)(&bounds.high), (const ::S00628640_Source *)(::SightHkVec *)(&pos));
                    }
                    SightHkVec expansion;
                    new ((void *)&(expansion)) ::FUN_005dbf20(runtimeInitializationFloat3647);
                    reinterpret_cast<::S_00627920 *>(&(bounds))->FUN_00627920((::S_00561240 *)(::SightHkVec *)(&expansion));
                    SightHkVec expansion2;
                    new ((void *)&(expansion2)) ::FUN_005dbf20(runtimeInitializationFloat3647);
                    reinterpret_cast<::S_00627920 *>(&(bounds.high))->FUN_00627920((::S_00561240 *)(::SightHkVec *)(&expansion2));
                    reinterpret_cast<::S219c0 *>((world))->DestroyDate();
                    SightFilterWorld* filterWorld = ((::SightFilterWorld *)(reinterpret_cast<::LowProcess *>((world->GetInner()))->GetPackageObjectType()));
                    int capacity = filterWorld->Count();
                    if (capacity > 0)
                    {
                        buffer = FUN_006e7620(capacity, 0);
                        if (buffer)
                        {
                            SightFilterWorld* pFilterWorld2 = ((::SightFilterWorld *)(reinterpret_cast<::LowProcess *>((world->GetInner()))->GetPackageObjectType()));
                            pFilterWorld2->Query(&bounds, buffer);
                            reinterpret_cast<::InterfaceManager *>(&(ray))->FUN_00500a20((::Tile *)(buffer));
                        }
                    }
                    reinterpret_cast<::S219c0 *>((world))->DestroyDate();
                    for (int j = 0; j < count; ++j)
                    {
                        if (nodes[j])
                            reinterpret_cast<::FUN_004a3eb0_shell *>(&(ray))->FUN_004a3eb0((SightVec*)&nodes[j]->FUN_0045bb80());
                        else
                        {
                            end.z = extent * fractions[j] + baseZ;
                            reinterpret_cast<::FUN_004a3eb0_shell *>(&(ray))->FUN_004a3eb0(&end);
                        }
                        ++DAT_011dea34;
                        if (ShortRay())
                        {
                            SightVec difference;
                            float distance = reinterpret_cast<::NiPoint3 *>((((::SightVec *)(reinterpret_cast<::FUN_00439ef0_class *>(&(end))->FUN_00439ef0((::NiPoint3 *)(::SightVec *)(&difference), (const ::NiPoint3 &)(start))))))->ComputeMagnitude();
                            float fraction = DAT_011a32dc / distance;
                            reinterpret_cast<::PathingRequest *>(&(collector))->SetCenterRadius(fraction);
                        }
                        else
                            reinterpret_cast<::PathingRequest *>(&(collector))->SetCenterRadius(0.0f);
                        void* hit = (*reinterpret_cast<::SightTES * *>(&::g_TES))->FUN_00458420(&ray);
                        SightActor* hitRef = hit ? ((::SightActor *)(::FUN_0056f930((::NiAVObject *)(hit)))) : 0;
                        if (!reinterpret_cast<::FUN_00632ce0_Class *>(&(ray))->FUN_00632ce0() && (!hit || hitRef == other))
                        {
                            visible = true;
                            if (result)
                                *result = codes[j];
                            break;
                        }
                    }
                    if (buffer)
                        FUN_005e0b60(buffer);
                }
            }
        }
    }
    return visible;
}

namespace ns8c5b10 {

class RefBase
{
  public:
    virtual void vr000();
    virtual void vr001();
    virtual void vr002();
    virtual void vr003();
    virtual void vr004();
    virtual void vr005();
    virtual void vr006();
    virtual void vr007();
    virtual void vr008();
    virtual void vr009();
    virtual void vr00a();
    virtual void vr00b();
    virtual void vr00c();
    virtual void vr00d();
    virtual void vr00e();
    virtual void vr00f();
    virtual void vr010();
    virtual void vr011();
    virtual void vr012();
    virtual void vr013();
    virtual void vr014();
    virtual void vr015();
    virtual void vr016();
    virtual void vr017();
    virtual void vr018();
    virtual void vr019();
    virtual void vr01a();
    virtual void vr01b();
    virtual void vr01c();
    virtual void vr01d();
    virtual void vr01e();
    virtual void vr01f();
    virtual void vr020();
    virtual void vr021();
    virtual void vr022();
    virtual void vr023();
    virtual void vr024();
    virtual void vr025();
    virtual void vr026();
    virtual void vr027();
    virtual void vr028();
    virtual void vr029();
    virtual void vr02a();
    virtual void vr02b();
    virtual void vr02c();
    virtual void vr02d();
    virtual void vr02e();
    virtual void vr02f();
    virtual void vr030();
    virtual void vr031();
    virtual void vr032();
    virtual void vr033();
    virtual void vr034();
    virtual void vr035();
    virtual void vr036();
    virtual void vr037();
    virtual void vr038();
    virtual void vr039();
    virtual void vr03a();
    virtual void vr03b();
    virtual void vr03c();
    virtual void vr03d();
    virtual void vr03e();
    virtual void vr03f();
    virtual void vr040();
    virtual void vr041();
    virtual void vr042();
    virtual void vr043();
    virtual void vr044();
    virtual void vr045();
    virtual void vr046();
    virtual void vr047();
    virtual void vr048();
    virtual void vr049();
    virtual void vr04a();
    virtual void vr04b();
    virtual void vr04c();
    virtual void vr04d();
    virtual void vr04e();
    virtual void vr04f();
    virtual void vr050();
    virtual void vr051();
    virtual void vr052();
    virtual void vr053();
    virtual void vr054();
    virtual void vr055();
    virtual void vr056();
    virtual void vr057();
    virtual void vr058();
    virtual void vr059();
    virtual void vr05a();
    virtual void vr05b();
    virtual void vr05c();
    virtual void vr05d();
    virtual void vr05e();
    virtual void vr05f();
    virtual void vr060();
    virtual void vr061();
    virtual void vr062();
    virtual void vr063();
    virtual void vr064();
    virtual void vr065();
    virtual void vr066();
    virtual void vr067();
    virtual void vr068();
    virtual void vr069();
    virtual void vr06a();
    virtual void vr06b();
    virtual void vr06c();
    virtual void vr06d();
    virtual void vr06e();
    virtual void vr06f();
    virtual void vr070();
    virtual void vr071();
    virtual void vr072();
    virtual void vr073();
    virtual void vr074();
    virtual void vr075();
    virtual void vr076();
    virtual void vr077();
    virtual void vr078();
    virtual void vr079();
    virtual void vr07a();
    virtual void vr07b();
    virtual void vr07c();
    virtual void vr07d();
    virtual void vr07e();
    virtual void vr07f();
    virtual void vr080();
    virtual void vr081();
    virtual void vr082();
    virtual void vr083();
    virtual void vr084();
    virtual void vr085();
    virtual void vr086();
    virtual void vr087();
    virtual void vr088();
    virtual void vr089();
    virtual void vr08a();
    virtual void vr08b();
    virtual void vr08c();
    virtual void vr08d();
    virtual void vr08e();
    virtual void vr08f();
    virtual void vr090();
    virtual void vr091();
    virtual void vr092();
    virtual void vr093();
    virtual void vr094();
    virtual void vr095();
    virtual void vr096();
    virtual void vr097();
    virtual void vr098();
    virtual void vr099();
    virtual void vr09a();
    virtual void vr09b();
    virtual void vr09c();
    virtual void vr09d();
    virtual void vr09e();
    virtual void vr09f();
    virtual void vr0a0();
    virtual void vr0a1();
    virtual void vr0a2();
    virtual void vr0a3();
    virtual void vr0a4();
    virtual void vr0a5();
    virtual void vr0a6();
    virtual void vr0a7();
    virtual void vr0a8();
    virtual void vr0a9();
    virtual void vr0aa();
    virtual void vr0ab();
    virtual void vr0ac();
    virtual void vr0ad();
    virtual void vr0ae();
    virtual void vr0af();
    virtual void vr0b0();
    virtual void vr0b1();
    virtual void vr0b2();
    virtual void vr0b3();
    virtual void vr0b4();
    virtual void vr0b5();
    virtual void vr0b6();
    virtual void vr0b7();
    virtual void vr0b8();
    virtual void vr0b9();
    virtual void vr0ba();
    virtual void vr0bb();
    virtual void vr0bc();
    virtual void vr0bd();
    virtual void vr0be();
    virtual void vr0bf();
    virtual void vr0c0();
    virtual void vr0c1();
    virtual void vr0c2();
    virtual void vr0c3();
    virtual void vr0c4();
    virtual void vr0c5();
    virtual void vr0c6();
    virtual void vr0c7();
    virtual void vr0c8();
    virtual void vr0c9();
    virtual void vr0ca();
    virtual void vr0cb();
    virtual void vr0cc();
    virtual void vr0cd();
    virtual void vr0ce();
    virtual void vr0cf();
    virtual void vr0d0();
    virtual void vr0d1();
    virtual void vr0d2();
    virtual void vr0d3();
    virtual void vr0d4();
    virtual void vr0d5();
    virtual void vr0d6();
    virtual void vr0d7();
    virtual bool IsPlayerRef();
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
};

class SpellItem;

class MagicCaster
{
  public:
    virtual void vc000();
    virtual void vc001();
    virtual void CastSpellOnCaster(SpellItem* pSpell, bool bNoHitEffect);
    int unk04;
    int unk08;
};

class MagicItem
{
  public:
};

class MagicTarget
{
  public:
    virtual void vt000();
    int unk04;
    int unk08;
    int unk0c;
};

class ActorValueOwner
{
  public:
    virtual void va000();
    virtual void va001();
    virtual void va002();
    virtual float GetActorValue(int eAV);
};

class Actor : public RefBase, public MagicCaster, public MagicTarget, public ActorValueOwner
{
};

class SpellBase
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};

class SpellItem : public SpellBase, public MagicItem
{
};

class SleepStage
{
  public:
};

class Setting
{
  public:
};



// When the player's sleep deprivation stage changes, remove the old stage spell, cast the new one, and show a message sink notification.
// @fnv 0x008c5b10
void OnSleepDeprivationStageChanged(ActorValueOwner* pOwner, int eAV, float fOldValue, float fTimeSinceScaleStart)
{
    float fNewValue;
    Actor* pActor4;
    SleepStage* pOldStage;
    SleepStage* pNewStageB;

    pActor4 = static_cast<Actor*>(pOwner);
    if (!pActor4 || !pActor4->IsPlayerRef())
        return;

    fNewValue = pActor4->GetActorValue(eAV);
    pOldStage = ((::ns8c5b10::SleepStage *)(::GetSleepDeprivationStage(fOldValue)));
    pNewStageB = ((::ns8c5b10::SleepStage *)(::GetSleepDeprivationStage(fNewValue)));
    if (pOldStage != pNewStageB)
    {
        if (pOldStage)
            reinterpret_cast<::MagicTarget *>((pActor4))->Dispel((::MagicItem *)(::ns8c5b10::MagicItem *)(((::ns8c5b10::SpellItem *)(reinterpret_cast<::BGSTerrainManager *>((pOldStage))->GetMinLevel()))), (::MagicCaster *)(0), (::ActiveEffect *)(0));
        if (pNewStageB)
            pActor4->CastSpellOnCaster(((::ns8c5b10::SpellItem *)(reinterpret_cast<::BGSTerrainManager *>((pNewStageB))->GetMinLevel())), false);
        if (pActor4 == (*reinterpret_cast<::ns8c5b10::Actor * *>(&::_g_thePlayer)))
        {
            char aAcBuffer[256];

            if (fTimeSinceScaleStart > 0.0)
            {
                std::sprintf(aAcBuffer, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ns8c5b10::Setting *>(&::g_011d2fac))))->GetMenuTitle())));
                ::DispatchMessageToSink(
                    (const char *)(aAcBuffer), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_in_pain.dds"), (const char *)(0), 2.0f, false);
            }
            else
            {
                std::sprintf(aAcBuffer, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ns8c5b10::Setting *>(&::g_011d33b4))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(aAcBuffer), 0,
                                      (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_very_happy.dds"), (const char *)(0), 2.0f,
                                      false);
            }
            if (pNewStageB)
            {
                std::sprintf(aAcBuffer, "%s %s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ns8c5b10::Setting *>(&::g_011d3ebc))))->GetMenuTitle())),
                             ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((::ns8c5b10::SpellItem *)(reinterpret_cast<::BGSTerrainManager *>((pNewStageB))->GetMinLevel()))))->FUN_00408da0())));
                ::DispatchMessageToSink(
                    (const char *)(aAcBuffer), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_in_pain.dds"), (const char *)(0), 2.0f, false);
            }
            else
            {
                std::sprintf(aAcBuffer, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::ns8c5b10::Setting *>(&::g_011d40d8))))->GetMenuTitle())));
                ::DispatchMessageToSink((const char *)(aAcBuffer), 0,
                                      (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_very_happy.dds"), (const char *)(0), 2.0f,
                                      false);
            }
            reinterpret_cast<::MagicTarget *>((pActor4))->UpdateActiveEffects(0.0f);
        }
    }
}

}

namespace fnv_009b2940 {
struct PhysicsAccess;
struct QueryWorld;
struct WorldAccess
{
};
struct CellAccess
{
};
struct PhysicsAccess
{
};
struct QueryPoint : NiPoint3
{
    QueryPoint();
};

struct QueryVector
{
    __m128 value;
};
struct FUN_00437c10
{
    QueryVector from, to;
    FUN_00437c10();
};
struct HitBody
{
};
struct HitPair
{
    float fraction;
    HitBody* body;
};
struct HitStorage
{
    HitPair* data;
    int size;
    int capacity;
    HitPair entries[128];
};
struct FUN_009b2db0 : HitStorage
{
    ~FUN_009b2db0();
};
struct FUN_009b2e30 : FUN_009b2db0
{
    FUN_009b2e30(int);
};
struct QueryWorld
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void Query(const FUN_00437c10&, HitStorage&);
};
struct WaterActor : TESObjectREFR
{
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
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    unsigned char unkd8;
    unsigned char waterFlags;
    bool FUN_009b2940();
};
QueryPoint __cdecl FUN_004a3760(float, const QueryPoint&);
struct XForm17
{
    int FUN_00446390();
    int FUN_004459e0(int);
};
struct XRefr17
{
};
int FUN_00401170(void*);

// Checks if the water actor is below the cell water level or below another water actor via a physics ray query, then sets waterFlags.
// @fnv 0x009b2940
bool WaterActor::FUN_009b2940()
{
    bool bBelow = false;
    float scale = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1033))))))->f;
    CellAccess* cell = ((::fnv_009b2940::CellAccess *)(reinterpret_cast<::LowProcess *>(this)->GetTarget()));
    if (!((bool)(reinterpret_cast<::BSOcclusionPlane *>(this)->IsNotCulled())) && cell)
    {
        if (GetPos()->z + reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930() * scale < reinterpret_cast<::FUN_005471e0_shell *>((cell))->FUN_005471e0())
        {
            bBelow = true;
        }
        else
        {
            WorldAccess* world = cell ? ((::fnv_009b2940::WorldAccess *)(reinterpret_cast<::FUN_004543c0_cls *>((cell))->FUN_004543c0())) : 0;
            PhysicsAccess* physics = world ? ((::fnv_009b2940::PhysicsAccess *)(reinterpret_cast<::ScriptLocals *>((world))->GetLocalData())) : 0;
            QueryWorld* query = physics ? ((::fnv_009b2940::QueryWorld *)(reinterpret_cast<::LowProcess *>((physics))->GetPackageObjectType())) : 0;
            if (query)
            {
                QueryPoint from = (*(::fnv_009b2940::QueryPoint *)(reinterpret_cast<::FUN_00439ef0_class *>((void *)(((QueryPoint*)GetPos())))->FUN_00439ef0((::NiPoint3 *)&(const ::fnv_009b2940::QueryPoint &)(FUN_004a3760(1.0f, (*reinterpret_cast<::fnv_009b2940::QueryPoint *>(&::DAT_011a9490)))), *(const ::NiPoint3 *)nullptr)));
                QueryPoint to = (*(::fnv_009b2940::QueryPoint *)(reinterpret_cast<::Point3Offset *>((void *)(((QueryPoint*)GetPos())))->ProjectileLaunched((::NiPoint3 *)&(const ::fnv_009b2940::QueryPoint &)(FUN_004a3760(1.0f, (*reinterpret_cast<::fnv_009b2940::QueryPoint *>(&::DAT_011a9490)))), {})));
                FUN_00437c10 ray;
                ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(ray.from), (const ::fnv_004a3e00::NiPoint3 &)(from));
                ::fnv_004a3e00::FUN_004a3e00((::fnv_004a3e00::bhkCharacterController &)(ray.to), (const ::fnv_004a3e00::NiPoint3 &)(to));
                FUN_009b2e30 hits(0);
                query->Query(ray, hits);
                for (int i = 0; !bBelow && i < ((int)(reinterpret_cast<::Callees *>(&(hits))->FUN_00726070())); ++i)
                {
                    HitPair* hit = ((::fnv_009b2940::HitPair *)(reinterpret_cast<::FUN_00626660_Class *>(&(hits))->FUN_00626660(i)));
                    HitBody* body = hit->body;
                    void* root = ((void *)(reinterpret_cast<::FUN_009b2c90_class *>((body))->FUN_009b2c90()));
                    void* object = ((void *)(::FUN_004b5820((::FormLike *)(root))));
                    WaterActor* reference = ((::fnv_009b2940::WaterActor *)(::FUN_0056f930((::NiAVObject *)(object))));
                    if (reference && FUN_00401170(((::fnv_009b2940::XForm17 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((XRefr17*)reference)))->FUN_007af430()))) == 0x23)
                    {
                        if (GetPos()->z + reinterpret_cast<::FUN_00644930_shell *>(this)->FUN_00644930() * scale < reference->GetPos()->z)
                            bBelow = true;
                    }
                }
            }
        }
    }
    waterFlags = waterFlags | bBelow;
    return bBelow;
}
}  // namespace fnv_009b2940

// For virtual type codes 7 or 8, uses the matching item path when bApply is true; otherwise sets spell state, casts, and removes the object.
// @fnv 0x008c2090
void ActorConsumeShell::FUN_008c2090(MagicItem* pItem, bool bApply)
{
    if ((int)pItem->vfn_18() == 7 || (int)pItem->vfn_18() == 8)
    {
        TESBoundObject* pObject = dynamic_cast<TESBoundObject*>(pItem);
        if (bApply)
        {
            if ((int)pItem->vfn_18() == 7)
            {
                AlchemyItem* pAlchemy = dynamic_cast<AlchemyItem*>(pItem);
                reinterpret_cast<::FUN_008c1f80_shell *>(this)->EquipItemWithCaster((::FUN_008c1de0_item *)(pAlchemy), 0, 1);
            }
            else
            {
                reinterpret_cast<::FUN_008c1de0_shell *>(this)->FUN_008c1de0((::TESForm *)(pObject), (::ExtraDataList *)(0), 1);
            }
        }
        else
        {
            SetCurrentSpellState((int)pItem);
            reinterpret_cast<::CastingCheck *>(this)->TryCast((::TESBoundObject *)(0));
            RemoveItem(pObject, 0, 1, 0, 0, 0, 0, 0, 1, 0);
        }
    }
}

#include "generated/data/fallout/ai/actor_magic.inc"
