// fallout/interface/menus/dialogmenu.cpp: DialogMenu, TESTopicInfo, Interface, ListBoxProxy (19 functions)

#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/B61F2B0Object.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/C764930ListMenu.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ClearOwner.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004eaf60_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00516bf0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00619d00_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061f170_cls.h"
#include "fnv/decl/FUN_0063f790_shell.h"
#include "fnv/decl/FUN_00672850_shell.h"
#include "fnv/decl/FUN_0071aa60_class.h"
#include "fnv/decl/FUN_00762130_dummy.h"
#include "fnv/decl/FUN_00833c20_shell.h"
#include "fnv/decl/FUN_0083e110_shell.h"
#include "fnv/decl/FUN_0083e430_shell.h"
#include "fnv/decl/FUN_0083ec30_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_008b3ab0_shell.h"
#include "fnv/decl/FUN_00934250_shell.h"
#include "fnv/decl/FUN_009344a0_shell.h"
#include "fnv/decl/FUN_00953ce0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009655a0_Class.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1db20_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8650_cls.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FlagS.h"
#include "fnv/decl/IntListBox.h"
#include "fnv/decl/ItemChangeList.h"
#include "fnv/decl/ListOwner.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/Mgr.h"
#include "fnv/decl/Owner83F1A0.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S8840.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/TopicS.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0061a720__FUN_0061a720_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00881680__FUN_00881680_shell.h"
#include "fnv/decl/fnv_008bb650__PlayerView.h"
#include "fnv/decl/fnv_00951a10__ThisCls.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00529000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00574000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005d2000.h"
#include "fnv/symbols_005d4000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00721000.h"
#include "fnv/symbols_008bc000.h"
#include "fnv/symbols_008c1000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "dialogmenu_decls.h"
#include "dialogmenu_runtime.h"

// @fnv 0x007628C0
bool DialogMenu::HandleMenuInput(int button, float value)
{
    if (Interface::GetSelectedTargetIndex(Interface::Dialog))
    {
        switch (button)
        {
        case 9:
            // The Menu tile getter shares the canonical +4 pointer getter.
            if (reinterpret_cast<::FUN_00a01230_shell *>((reinterpret_cast<Tile*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(this)))->FUN_00726070())))))->IsTraitNonZero(ms_iDialogMenuValue))
                HandleSelection(0, 0);
            else
                HandleSelection(-1, m_kResponseListBox.GetSelectedTile());
            return true;
        }
    }
    return false;
}

// Sets the goodbye type to forced or natural based on the topic's parent rumor flag and its next response matching a conversation topic.
// @fnv 0x00762860
void DialogMenu::SetCurrentTopic(MenuTopic* topic)
{
    // The MenuTopic info/original-topic accessors share the canonical +18/+1C
    // getters; the first predicate shares TESTopic's flag predicate.
    if (reinterpret_cast<::FUN_00619df0_shell *>((void *)(reinterpret_cast<TESTopic*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(topic)))->FUN_009611e0())))))->FUN_00619df0())
        m_eGoodbyeState = eForceGoodbye;
    else if (reinterpret_cast<TESTopic*>(((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((reinterpret_cast<TESResponse*>(topic)))->FUN_0045cd60()))) ==
             ((::TESTopic *)(::fnv_0061a2d0::GetTopicSubTypeName((*(int *)&(const ::DIALOGUE_TYPE &)(DIALOGUE_TYPE_DT_CONVERSATION)), 2))))
        m_eGoodbyeState = eNaturalGoodbye;
}

// @fnv 0x00762FF0
DialogMenu::DialogState DialogMenu::BeginDialogueResponse(bool usePrefix)
{
    MenuTopic* topic = pDialogueItem->GetSelectedTopic();
    DialogueResponse* response = topic ? topic->GetActiveResponse() : 0;
    DialogState state = eSpeechIdle;
    if (topic)
        ::FUN_00406d00(m_cCurrentTopicLabel, 128, "%s (%d)",
                  reinterpret_cast<TESTopic*>(((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((reinterpret_cast<TESResponse*>(topic)))->FUN_0045cd60())))->GetName(),
                  ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((reinterpret_cast<TESResponse*>(topic)))->FUN_0045cd60())))))->FUN_0084e3a0())));
    else
        TaskQueueInterface::CopyStringToBuffer(m_cCurrentTopicLabel, 128, "----");
    if (response)
    {
        char text[512];
        bool responseStarted = false;
        m_bResponseStarted = true;
        reinterpret_cast<::FUN_0083e110_shell *>((topic))->AdvanceAndCheckNode();
        m_pDialogueSpeaker->vfn_264(0.0f, response, true);
        m_kActorProcessResult =
            reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)))->GetBaseTexture())))
                ->vfn_48c(false);
        if (!m_bServiceDialogue)
        {
            if (usePrefix)
            {
                if (((bool)(reinterpret_cast<::FUN_00833c20_shell *>((pDialogueItem))->FUN_00833c20())))
                {
                    if (((const char *)(::FUN_00559450((int *)(reinterpret_cast<BSStringT<char>*>(
                            ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response))->m_item))))))))
                        ::FUN_00406d00(text, 512, "%s %s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d27fc))))->GetMenuTitle())),
                                  ((const char *)(::FUN_00559450((int *)(reinterpret_cast<BSStringT<char>*>(
                                      ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response))->m_item))))))));
                    else
                        ::FUN_00406d00(text, 512, "%s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d27fc))))->GetMenuTitle())));
                }
                else
                {
                    if (((const char *)(::FUN_00559450((int *)(reinterpret_cast<BSStringT<char>*>(
                            ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response))->m_item))))))))
                        ::FUN_00406d00(text, 512, "%s %s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3fe8))))->GetMenuTitle())),
                                  ((const char *)(::FUN_00559450((int *)(reinterpret_cast<BSStringT<char>*>(
                                      ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response))->m_item))))))));
                    else
                        ::FUN_00406d00(text, 512, "%s", ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3fe8))))->GetMenuTitle())));
                }
            }
            else
            {
                if (((const char *)(::FUN_00559450((int *)(reinterpret_cast<BSStringT<char>*>(
                        ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response))->m_item))))))))
                    TaskQueueInterface::CopyStringToBuffer(
                        text, 512,
                        ((const char *)(::FUN_00559450((int *)(reinterpret_cast<BSStringT<char>*>(
                            ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(response))->m_item))))))));
                else
                    TaskQueueInterface::CopyStringToBuffer(text, 512, " ");
            }
            reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[2]))->FUN_00a01350(0xFC4, (char *)(text), true);
            reinterpret_cast<Tile*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(this)))->FUN_00726070())))
                ->Set(ms_iDialogMenuValue, 1);
            state = ePlaySpeech;
        }
    }
    else
    {
        if (!m_bResponseStarted)
            ::FUN_005b5e40();
        if (DAT_011d9518 && m_eGoodbyeState != eForceGoodbye && !::FUN_00579200((const char *)(DAT_011d9518)))
        {
            reinterpret_cast<::FUN_0061f170_cls *>((DAT_011d9518))->FUN_0061f170((void *)(true), (::ArgObj *)(m_pDialogueSpeaker));
            TESTopicInfo* follow;
            bool bDispositionFailure;
            follow = ::FUN_0061af30(DAT_011d9518, (*(bool *)(&bDispositionFailure)),
                                           (::TESObjectREFR *)(void *)(((::TESTopicInfo *)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<DialogueItem*>(pDialogueItem)))->FUN_0084e3a0()))), (::TESObjectREFR *)(::_g_thePlayer),
                                           false, (::BSSimpleList< ::DialogueItem *> *)(false));
            if (follow && topic)
            {
                BSSimpleList<MenuTopic*>* pNewTopicList =
                    reinterpret_cast<BSSimpleList<MenuTopic*>*>(new BSSimpleList<TESTopic*>);
                MenuTopic* pNextTopic =
                    new MenuTopic(((::TESQuest *)(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<DialogueItem*>(topic)))->FUN_00825c00())),
                                  reinterpret_cast<TESTopic*>(((::TESResponse *)(reinterpret_cast<::FUN_0045cd60_shell *>((reinterpret_cast<TESResponse*>(topic)))->FUN_0045cd60()))), follow,
                                  m_pDialogueSpeaker, false);
                reinterpret_cast<::TopicS *>((pNextTopic))->HasCur();
                reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<MediaSet*>*>(pNewTopicList)))->FUN_00905820((void *)&(const ::MediaSet *const &)(reinterpret_cast<MediaSet*>(pDialogueItem->GetFirstTopic())));
                reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<MediaSet*>*>(pNewTopicList)))->FUN_00905820((void *)&(reinterpret_cast<MediaSet* const&>(pNextTopic)));
                reinterpret_cast<::Owner83F1A0 *>((pDialogueItem))->AddHeadIfNotNull((int *)(pNewTopicList));
                pDialogueItem->SelectTopic(true);
                if (reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pNextTopic)))->FUN_009611e0())))
                        ->IsChallengeFlagSet())
                {
                    if (reinterpret_cast<::Mgr *>((pDialogueItem))->CheckTopicInfoChance(pNextTopic))
                        pNextTopic = pDialogueItem->GetSelectedTopic();
                    else
                    {
                        if ((int)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>(pDialogueItem)))->FUN_00825c00() > 0)
                        {
                            ::_g_thePlayer->RewardXP(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>(pDialogueItem)))->FUN_00825c00());
                            TopicMenuController::IncrementMiscStat(12);
                        }
                        else
                            TopicMenuController::IncrementMiscStat(12);
                    }
                }
                else if (reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pNextTopic)))->FUN_009611e0())))
                             ->GetActorValue() ||
                         reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pNextTopic)))->FUN_009611e0())))
                             ->GetPerk())
                {
                    PerkEntryConditionSet* pConditions =
                        reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pNextTopic)))->FUN_009611e0())))))->GetConditions();
                    BSSimpleList<TESConditionItem*>* pConditionItem =
                        reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                            ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pConditions))->m_item)));
                    while (pConditionItem && ((::TESConditionItem *)(reinterpret_cast<::SimpleListNodeView*>(pConditionItem)->m_item)))
                    {
                        DialogMenuConditionFunction* function = reinterpret_cast<DialogMenuConditionFunction*>(
                            reinterpret_cast<TESTopicInfoData*>(((::TESConditionItem *)(reinterpret_cast<::SimpleListNodeView*>(pConditionItem)->m_item)))->GetLinkToList());
                        if (function && function->function == 14)
                        {
                            ActorValue::Index value = function->actorValue;
                            int required = (int)((::TESConditionItem *)(reinterpret_cast<::SimpleListNodeView*>(pConditionItem)->m_item))->GetConditionValue();
                            int current = ::_g_thePlayer->actorValueOwner.GetActorValueAsInteger(value);
                            if (current < required)
                                TopicMenuController::IncrementMiscStat(31);
                            else
                                TopicMenuController::IncrementMiscStat(12);
                            break;
                        }
                        pConditionItem = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                            ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(pConditionItem)))->FUN_00726070())));
                    }
                }
                SetCurrentTopic(pNextTopic);
                pDialogueItem->RunTopicResultScript();
                m_bResponseStarted = false;
                DAT_011d9518 = reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pNextTopic)))->FUN_009611e0())));
                return BeginDialogueResponse(usePrefix);
            }
            DAT_011d9518 = 0;
        }
        if (!m_bServiceDialogue || m_eDialogState == eServiceFadeOut)
        {
            reinterpret_cast<::FUN_0083ec30_shell *>((pDialogueItem))->UpdateTopicList();
            if (!pDialogueItem->SelectTopic(true) && m_eGoodbyeState == eInDialogue)
                m_eGoodbyeState = eInvalidChoiceList;
            if (m_eGoodbyeState != eInDialogue)
            {
                Close();
                m_fCameraTransitionTime = 0.0f;
                state = eCameraZoomOut;
                m_eDialogState = eCameraZoomOut;
            }
            else
            {
                reinterpret_cast<Tile*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(this)))->FUN_00726070())))
                    ->Set(ms_iDialogMenuValue, 0);
                LoadTopicsList();
                state = eSpeechIdle;
            }
        }
    }
    if (bPaused)
        m_eStateBeforePause = state;
    return state;
}

// Advances the dialogue camera zoom/speech state machine, closing the menu and updating the player's focus and camera each frame.
// @fnv 0x00762950
void DialogMenu::UpdateDialog()
{
    if (bPaused || ::fnv_00703d50::FUN_00703d50())
        return;
    if (m_eDialogState != eCameraZoomOut)
    {
        if (!((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)))->GetBaseTexture())) ||
            reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)))->GetBaseTexture())))
                    ->vfn_610() == 2 ||
            reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)))->GetBaseTexture())))
                    ->vfn_610() >= 4)
        {
            Close();
            m_fCameraTransitionTime = 0.0f;
            m_eDialogState = eCameraZoomOut;
        }
    }
    if (((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)))->GetBaseTexture())) &&
        ((int)(reinterpret_cast<::FUN_0045cd60_shell *>((reinterpret_cast<HighProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(m_pDialogueSpeaker)))->GetBaseTexture())))))->FUN_0045cd60())) &&
        m_eDialogState != eCameraZoomOut)
    {
        Close();
        m_fCameraTransitionTime = 0.0f;
        m_eDialogState = eCameraZoomOut;
    }
    switch (m_eDialogState)
    {
    case eCameraZoomIn:
        if (m_bSuppressDialogueText && m_fCameraTransitionTime == 0.0)
        {
            m_bSuppressDialogueText =
                reinterpret_cast<::TutorialMessageGate718 *>(&(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->tutorial))->FUN_00718630(17, FUN_007620e0(), (unsigned int)((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1219))))))->f * 1400);
            if (!m_bSuppressDialogueText)
            {
                if (m_pDialogueSpeaker)
                    m_pDialogueSpeaker->bDialogueSelected = true;
                BeginDialogueResponse(false);
            }
        }
        else if (!m_bSuppressDialogueText && m_fCameraTransitionAlpha >= 0.1)
            reinterpret_cast<Tile*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(this)))->FUN_00726070())))->Set(DAT_011d9508, 1);
        m_fCameraTransitionTime += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue();
        m_fCameraTransitionAlpha = FUN_0040ebd0(m_fCameraTransitionTime / ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1219))))))->f, 1.0f);
        if (m_fCameraTransitionAlpha == 1.0)
        {
            if (!m_bSuppressDialogueText)
            {
                m_fCameraTransitionTime = 0.0f;
                m_eDialogState = ePlaySpeech;
            }
            else if (reinterpret_cast<::S8840 *>(&(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->tutorial))->FUN_00718840(17) && Interface::GetSelectedTargetIndex(Interface::Dialog))
            {
                m_fCameraTransitionTime = 0.0f;
                reinterpret_cast<Tile*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(this)))->FUN_00726070())))
                    ->Set(DAT_011d9508, 1);
                if (m_pDialogueSpeaker)
                    m_pDialogueSpeaker->bDialogueSelected = true;
                BeginDialogueResponse(false);
                m_eDialogState = ePlaySpeech;
            }
        }
        break;
    case ePlaySpeech:
        if (DAT_011d951c > 0.0)
        {
            DAT_011d951c -= reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue();
            break;
        }
        if (m_pDialogueSpeaker && m_pDialogueSpeaker->bDialogueSelected)
        {
            m_fCameraTransitionTime = 0.0f;
            m_eDialogState = eLoadSpeech;
            m_uiDialogMenuFlags = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
        }
        break;
    case eLoadSpeech:
        if (!m_pDialogueSpeaker->bDialogueSelected)
        {
            reinterpret_cast<::FUN_00934250_shell *>((m_pDialogueSpeaker))->FUN_00934250();
            if (DAT_011d9594 == 0)
                DAT_011d9594 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
            if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() - DAT_011d9594 >= 500.0)
                ::ResetActorState((void *)(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(m_pDialogueSpeaker)))->FUN_0084e3a0()))), true);
        }
        else
        {
            m_fCameraTransitionTime = 0.0f;
            m_eDialogState = BeginDialogueResponse(false);
            DAT_011d9594 = 0;
        }
        break;
    case eSpeechIdle:
        if (m_bServiceDialogue && m_bServiceMenuRequested)
            m_eDialogState = eServiceFadeOut;
        break;
    case eServiceFadeOut:
        if (m_bServiceMenuRequested && m_eFadeState == 4)
        {
            BeginDialogueResponse(false);
            m_bServiceMenuRequested = false;
            m_eDialogState = eSpeechIdle;
        }
        break;
    case eCameraZoomOut:
        m_fCameraTransitionTime += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue();
        m_fCameraTransitionAlpha = 1.0f - FUN_0040ebd0(m_fCameraTransitionTime / ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1220))))))->f, 1.0f);
        if (m_fCameraTransitionAlpha == 0.0)
        {
            DAT_011f21d0 = true;
            DAT_011f21d1 = !m_bPauseRequested;
            ::_g_thePlayer->FocusOnActor(m_pDialogueSpeaker, 0.0f, true);
            ::_g_thePlayer->UpdateCamera(false, false);
            reinterpret_cast<::FUN_0063f790_shell *>((m_pDialogueDepthOfFieldModifier))->FUN_0063f790(0.0f);
            delete reinterpret_cast<Tile*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(this)))->FUN_00726070())));
            return;
        }
        break;
    }
    if (::_g_thePlayer->IsInDialogueWithPlayer())
        m_pDialogueSpeaker->vfn_264(reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->GetStoredFloatValue(), 0, false);
    ::_g_thePlayer->FocusOnActor(m_pDialogueSpeaker,
                              (float)(m_fCameraTransitionAlpha * (DAT_011a008c == 0.0 ? 1.0 : DAT_011a008c / 100.0)),
                              m_eDialogState == eCameraZoomOut);
    ::_g_thePlayer->UpdateCamera(false, false);
    reinterpret_cast<::FUN_0063f790_shell *>((m_pDialogueDepthOfFieldModifier))->FUN_0063f790(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1223))))))->f * m_fCameraTransitionAlpha);
}

// @fnv 0x00762160
void DialogMenu::Close()
{
    if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)))
    {
        MobileObject* speaker = (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueSpeaker;
        Actor* actor = 0;
        if (speaker->IsActor())
            actor = static_cast<Actor*>(speaker);
        TESTopicInfo* pInfo = DAT_011d9518;
        bool runEndScript =
            (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_eGoodbyeState == eForceGoodbye || (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_eGoodbyeState == eInvalidChoiceList;
        if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_eGoodbyeState == eInvalidChoiceList)
            ::FUN_005b5e40();
        if (speaker->GetFaceGenNodeBiped(0))
            reinterpret_cast<::FUN_00762130_dummy *>((speaker->GetFaceGenNodeBiped(0)))->SetIAmInDialogue(false);
        if (speaker->GetFaceGenNodeSkinned(0))
            reinterpret_cast<::FUN_00762130_dummy *>((speaker->GetFaceGenNodeSkinned(0)))->SetIAmInDialogue(false);
        reinterpret_cast<::FUN_00934250_shell *>((speaker))->FUN_00934250();
        speaker->vfn_278(false);
        ::_g_thePlayer->vfn_278(false);
        speaker->vfn_288();
        DAT_011d9514 = false;
        if (((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(speaker)))->GetBaseTexture())))
        {
            reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(speaker)))->GetBaseTexture())))->vfn_2ec(0);
            if (actor && !((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((reinterpret_cast<PlayerCharacter*>(actor)))->FUN_00493bb0())))
                reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(actor)))->GetBaseTexture())))
                    ->vfn_24(actor, true);
        }
        if (actor && ((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(actor)))->GetBaseTexture())))
            reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(actor)))->GetBaseTexture())))->vfn_650(true);
        if (((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(speaker)))->GetBaseTexture())) && actor && !actor->vfn_22c(false) &&
            !actor->vfn_2e8())
            reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(speaker)))->GetBaseTexture())))
                ->vfn_4b4(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting183))))))->f);
        if (actor)
            reinterpret_cast<::FUN_008b3ab0_shell *>((actor))->FUN_008b3ab0();
        reinterpret_cast<::FUN_00953ce0_Class *>((::_g_thePlayer))->FUN_00953ce0();
        reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(::_g_thePlayer)))->GetBaseTexture())))->vfn_650(true);
        if (pInfo && runEndScript && !::FUN_00579200((const char *)(pInfo)))
        {
            reinterpret_cast<::FUN_0061f170_cls *>((pInfo))->FUN_0061f170((void *)(true), (::ArgObj *)(speaker));
            pInfo->AddTopicList();
            pInfo = 0;
            if (actor && !((bool)(reinterpret_cast<::FUN_00493bb0_Class *>((reinterpret_cast<PlayerCharacter*>(actor)))->FUN_00493bb0())) &&
                ((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(actor)))->GetBaseTexture())) &&
                reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(actor)))->GetBaseTexture())))
                    ->vfn_24(actor, true))
                reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(actor)))->GetBaseTexture())))->vfn_524(actor);
        }
        reinterpret_cast<Tile*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)))))->FUN_00726070())))->Set(0xFA3, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>(((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))))->FUN_00a1d910();
    }
    reinterpret_cast<::FUN_00ad8650_cls *>((reinterpret_cast<DialogMenuAudioCalls*>(::FUN_00453a70())))->FUN_00ad8650();
    BSAudio::DeactivateAudio();
}

// @fnv 0x007624f0
void DialogMenu::HandleSelection(int id, Tile* tile)
{
    bool bSpeechChallenge = false;
    if (m_eDialogState == eCameraZoomIn || m_eDialogState == eCameraZoomOut)
        return;
    if (m_uiDialogMenuFlags)
    {
        if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() - m_uiDialogMenuFlags >= 500)
            m_uiDialogMenuFlags = 0;
        else
            return;
    }
    if (id == -1 && reinterpret_cast<::ListOwner *>(&(m_kResponseListBox))->ContainsKey((int)(tile)) &&
        reinterpret_cast<::FUN_0083e430_shell *>((pDialogueItem))->FUN_0083e430((int)reinterpret_cast<TileListBoxCalls*>(tile)->GetFloat(0xFAC)))
    {
        MenuTopic* pTopic = pDialogueItem->GetSelectedTopic();
        bool wasNew = pTopic->m_bInfoHasBeenRead;
        pTopic->m_bInfoHasBeenRead = false;
        if (reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))->IsChallengeFlagSet())
        {
            bSpeechChallenge = true;
            if (reinterpret_cast<::Mgr *>((pDialogueItem))->CheckTopicInfoChance(pTopic))
                pTopic = pDialogueItem->GetSelectedTopic();
            else
            {
                if ((int)reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->pDialogueItem)))->FUN_00825c00() > 0)
                {
                    ::_g_thePlayer->RewardXP(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->pDialogueItem)))->FUN_00825c00());
                    TopicMenuController::IncrementMiscStat(12);
                }
                else
                    TopicMenuController::IncrementMiscStat(12);
            }
        }
        else if (reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))->GetActorValue() ||
                 reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))->GetPerk())
        {
            PerkEntryConditionSet* pConditions =
                reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))))->GetConditions();
            BSSimpleList<TESConditionItem*>* pConditionItem = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pConditions))->m_item)));
            while (pConditionItem && ((::TESConditionItem *)(reinterpret_cast<::SimpleListNodeView*>(pConditionItem)->m_item)))
            {
                DialogMenuConditionFunction* function = reinterpret_cast<DialogMenuConditionFunction*>(
                    reinterpret_cast<TESTopicInfoData*>(((::TESConditionItem *)(reinterpret_cast<::SimpleListNodeView*>(pConditionItem)->m_item)))->GetLinkToList());
                if (function && function->function == 14)
                {
                    ActorValue::Index value = function->actorValue;
                    int required = (int)((::TESConditionItem *)(reinterpret_cast<::SimpleListNodeView*>(pConditionItem)->m_item))->GetConditionValue();
                    int current = ::_g_thePlayer->actorValueOwner.GetActorValueAsInteger(value);
                    if (current < required)
                    {
                        if (wasNew)
                            TopicMenuController::IncrementMiscStat(31);
                    }
                    else
                        TopicMenuController::IncrementMiscStat(12);
                    break;
                }
                pConditionItem = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                    ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(pConditionItem)))->FUN_00726070())));
            }
        }
        SetCurrentTopic(pTopic);
        pDialogueItem->RunTopicResultScript();
        m_bResponseStarted = false;
        DAT_011d9518 = reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())));
        m_eDialogState = BeginDialogueResponse(bSpeechChallenge);
    }
    else if (reinterpret_cast<::FUN_00a01230_shell *>((reinterpret_cast<Tile*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(this)))->FUN_00726070())))))->IsTraitNonZero(ms_iDialogMenuValue) &&
             id == 0)
        m_eDialogState = eLoadSpeech;
}

// @fnv 0x007627e0
ActorValueInfo* TESTopicInfo::GetActorValue()
{
    return m_pPerkSkillStat && reinterpret_cast<TESBoundObject*>(m_pPerkSkillStat)->GetFormType() != 0x56
               ? reinterpret_cast<ActorValueInfo*>(m_pPerkSkillStat)
               : 0;
}

// @fnv 0x00762820
BGSPerk* TESTopicInfo::GetPerk()
{
    return m_pPerkSkillStat && reinterpret_cast<TESBoundObject*>(m_pPerkSkillStat)->GetFormType() == 0x56
               ? reinterpret_cast<BGSPerk*>(m_pPerkSkillStat)
               : 0;
}

// @fnv 0x007627c0
bool TESTopicInfo::IsChallengeFlagSet()
{
    return (challengeFlags & 0x80) ? true : false;
}

struct FUN_007620f0_shell : public DialogMenu
{
    bool FUN_007620f0();
};
// @fnv 0x00761A20
Tile* DialogMenu::Create(MobileObject* speaker, TESTopic* topic, MobileObject* alternate)
{
    InterfaceManager* pManager = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
    Tile* existing = ((::Tile *)(::FUN_00a09030(1009)));
    if (existing)
        return existing;
    if (!speaker)
    {
        ::FUN_005b5e40(
            );
        return 0;
    }
    Tile* m_pFourthMenuObject = reinterpret_cast<::fnv_00a01b00::TileLoader *>((pManager->FUN_00586150()))->FUN_00a01b00((void *)("Data\\Menus\\Dialog\\dialog_menu.xml"));
    (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)) = static_cast<DialogMenu*>(reinterpret_cast<::FUN_00a03c90_shell *>((m_pFourthMenuObject))->FUN_00a03c90());
    if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)) && (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->GetClass() == (unsigned int)FUN_007620e0())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>(((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))))->FUN_00a1dc70(reinterpret_cast<TileMenu*>(m_pFourthMenuObject), false);
        if (!reinterpret_cast<::FUN_007620f0_shell *>(((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))))->FUN_007620f0())
        {
            ::FUN_005b5e40();
            return 0;
        }
        if (reinterpret_cast<TileListBoxCalls*>(m_pFourthMenuObject)->GetFloat(0xFA7) == 6006.0 ||
            reinterpret_cast<TileListBoxCalls*>(m_pFourthMenuObject)->GetFloat(0xFA7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((m_pFourthMenuObject))->FUN_00a012d0(0xFAD, Tile::GetInterfaceScale(), true);
        (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueSpeaker = speaker;
        ImageSpaceModifierInstanceForm::Stop(::FUN_005d2860());
        if (speaker->GetFaceGenNodeBiped(0))
            reinterpret_cast<::FUN_00762130_dummy *>((speaker->GetFaceGenNodeBiped(0)))->SetIAmInDialogue(true);
        if (speaker->GetFaceGenNodeSkinned(0))
            reinterpret_cast<::FUN_00762130_dummy *>((speaker->GetFaceGenNodeSkinned(0)))->SetIAmInDialogue(true);
        TESPackage* pCurrentPackage = reinterpret_cast<::FUN_009344a0_shell *>((speaker))->FUN_009344a0();
        if (speaker->IsActor())
        {
            Actor* actor = reinterpret_cast<Actor*>(speaker);
            TESPackage* extra = reinterpret_cast<::FUN_0041cb10_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((reinterpret_cast<TESObjectREFR*>(actor)))->FUN_005d43c0()))))->FUN_0041cb10();
            if (extra && extra->GetPackType() == 15)
                DAT_011a008c = reinterpret_cast<::FUN_00672850_shell *>((extra))->GetPackageFloatValue();
        }
        if (!pCurrentPackage || pCurrentPackage->GetPackType() != 28 || speaker->vfn_2c8() != ::_g_thePlayer)
        {
            if (speaker->IsActor() && !speaker->vfn_274(true))
                reinterpret_cast<::fnv_00881680::FUN_00881680_shell *>((reinterpret_cast<Actor*>(speaker)))->FUN_00881680(false);
            if (speaker->vfn_274(true))
            {
                reinterpret_cast<::FUN_008b3ab0_shell *>((reinterpret_cast<Actor*>(speaker)))->FUN_008b3ab0();
                speaker->vfn_280(::_g_thePlayer, 0, 0, true, false, true, false, false, false);
            }
            else
                speaker->vfn_280(::_g_thePlayer, 0, 0, true, false, true, false, false, false);
        }
        MobileObject* pTopicSpeaker = speaker;
        if (alternate)
            pTopicSpeaker = alternate;
        if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->pDialogueItem->Initialize(pTopicSpeaker, topic))
            (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->SetCurrentTopic((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->pDialogueItem->GetFirstTopic());
        if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->pDialogueItem->GetFirstTopic())
            DAT_011d9518 = reinterpret_cast<TESTopicInfo*>(
                ((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->pDialogueItem->GetFirstTopic())))->FUN_009611e0())));
        ::_g_thePlayer->vfn_278(true);
        if (speaker->IsActor())
        {
            reinterpret_cast<BaseProcess*>(((::Date *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<PlayerQuestData*>(speaker)))->GetBaseTexture())))
                ->vfn_288(reinterpret_cast<Actor*>(speaker), 2);
            speaker->vfn_278(true);
        }
        (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_bPauseRequested = reinterpret_cast<::FUN_004eaf60_shell *>((::_g_thePlayer))->FUN_004eaf60();
        if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_eGoodbyeState != eForceGoodbye)
        {
            reinterpret_cast<::fnv_00951a10::ThisCls *>((::_g_thePlayer))->FUN_00951a10(true);
            ::_g_thePlayer->FocusOnActor(speaker, 0.0f, true);
        }
        if (!(*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueDepthOfFieldModifier)
        {
            float distance = reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::NiPoint3 &)((*speaker->GetPos() - *::_g_thePlayer->GetPos())))->ComputeMagnitude();
            (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueDepthOfFieldModifier = ImageSpaceModifierInstanceDOF::CreateAndRegister(
                distance, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1222))))))->f, ImageSpaceModifierInstanceDOF::Back, 0.0f, 0.0f, 0.0f);
            (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueDepthOfFieldModifier->FUN_005bbd60(true);
        }
        reinterpret_cast<::fnv_008bb650::PlayerView *>((::_g_thePlayer))->SetActiveState(false, false, false);
        reinterpret_cast<::FUN_009655a0_Class *>((::_g_thePlayer))->FUN_009655a0();
        (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_kResponseListBox.Initialize((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pTiles[3], "DM_TopicTemplate");
        reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>(((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pTiles[3]))->FUN_00a03da0((char *)("lb_scrollbar"))->Set(0xFA2, 40);
        reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>(((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pTiles[3]))->FUN_00a03da0((char *)("lb_highlight_box"))->Set(0xFA1, 40);
        reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>(((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pTiles[3]))->FUN_00a03da0((char *)("lb_highlight_box"))->Set(0xFB1, 960);
        DAT_011d9508 = ::FUN_00a01860("_DialogVisible");
        ms_iDialogMenuValue = ::FUN_00a01860("_ShowingText");
        DAT_011d9504 = ::FUN_00a01860("_current_value");
        bool bSubtitles =
            (*reinterpret_cast<::SettingT< ::INISettingCollection> *>(&::g_011d8934)).Bool()->b || speaker->IsActor() && ::FUN_008c1bc0((int)(reinterpret_cast<Actor*>(speaker)));
        reinterpret_cast<Tile*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)))))->FUN_00726070())))
            ->Set(::FUN_00a01860("_ShowSubtitles"), bSubtitles);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pTiles[1]))->FUN_00a01350(0xFC4, (char *)(reinterpret_cast<::FUN_0055d520_shell *>((speaker))->FUN_0055d520()), true);
        if (((bool)(::fnv_005d4a40::FUN_005d4a40())) && !reinterpret_cast<::S8840 *>(&(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))->tutorial))->FUN_00718840(17))
            (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_bSuppressDialogueText = true;
        else
            (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->BeginDialogueResponse(false);
        (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->SetMenuVisibility(false);
        BSAudio::EnableAudio();
        reinterpret_cast<DialogMenuAudioCalls*>(::FUN_00453a70())->EnableAudio();
        speaker->SetAltered(true);
        ::Interface::SetHUDVisible(false);
        return m_pFourthMenuObject;
    }
    else
    {
        if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)) && ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)))))->FUN_00726070())))
            delete (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510));
    }
    return 0;
}

// Returns true only if all four pointers stored at offset 0x30 in this DialogMenu are non-null.
// @fnv 0x007620f0
bool FUN_007620f0_shell::FUN_007620f0()
{
    for (int iIndex = 0; iIndex < 4; ++iIndex)
    {
        if (((void**)&this->m_pTiles[0])[iIndex] == 0)
            return false;
    }
    return true;
}

struct FUN_00763fd0_shell : public TESTopicInfo
{
    bool IsFlagSet();
};
// @fnv 0x007638B0
void DialogMenu::LoadTopicsList()
{
    m_kResponseListBox.Clear();
    int iIndex = 0;
    int iTopicHeight = 0;
    char text[512];
    bool bNextTopic = pDialogueItem->SelectTopic(true);
    while (bNextTopic)
    {
        MenuTopic* pTopic = pDialogueItem->GetSelectedTopic();
        bool bDisabled = false;
        TESFullName* pFullName = 0;
        if (reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))->GetActorValue())
        {
            pFullName =
                reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))->GetActorValue();
        }
        else
        {
            pFullName = reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))->GetPerk();
        }
        if (pFullName)
        {
            ::FUN_00406d00(text, 512, "[%s", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)(reinterpret_cast<TESSoundFile*>(pFullName)))->FUN_00408da0())));
            if (reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))
                    ->IsChallengeFlagSet())
            {
                MobileObject* actor = 0;
                if (m_pDialogueSpeaker->IsActor())
                    actor = m_pDialogueSpeaker;
                else if (((bool)(::FUN_00574900((const unsigned char *)(m_pDialogueSpeaker)))))
                    actor = reinterpret_cast<MobileObject*>(
                        ((::BGSImpactDataSet *)(reinterpret_cast<::FUN_00516bf0_shell *>((reinterpret_cast<BGSExplosion*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((reinterpret_cast<DialogueItem*>(m_pDialogueSpeaker)
                                                            ->FUN_005e3fa0()))->FUN_007af430())))))->FUN_00516bf0())));
                ::FUN_00406d00(
                    text, 512, "%s, %i", text,
                    ComputeWeightedValue(
                        ::_g_thePlayer->actorValueOwner.GetActorValueFloatByIndex(ActorValue::ActorValue__Index_SPEECH),
                        m_pDialogueSpeaker->IsActor() ? (float)m_pDialogueSpeaker->CalculateDisposition(::_g_thePlayer, 0)
                                                      : ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::originalRuntimeFloatSetting1109))))))->f,
                        reinterpret_cast<::B61F2B0Object *>((reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))))->FUN_0061f2b0()));
                strcat_s(text, 512, "%");
            }
            else
            {
                PerkEntryConditionSet* pConditions =
                    reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))))->GetConditions();
                BSSimpleList<TESConditionItem*>* cursor = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                    ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pConditions))->m_item)));
                while (cursor && ((::TESConditionItem *)(reinterpret_cast<::SimpleListNodeView*>(cursor)->m_item)))
                {
                    DialogMenuConditionFunction* function = reinterpret_cast<DialogMenuConditionFunction*>(
                        reinterpret_cast<TESTopicInfoData*>(((::TESConditionItem *)(reinterpret_cast<::SimpleListNodeView*>(cursor)->m_item)))->GetLinkToList());
                    if (function && function->function == 14)
                    {
                        ActorValue::Index value = function->actorValue;
                        int required = (int)((::TESConditionItem *)(reinterpret_cast<::SimpleListNodeView*>(cursor)->m_item))->GetConditionValue();
                        int current = ::_g_thePlayer->actorValueOwner.GetActorValueAsInteger(value);
                        if (current < required)
                        {
                            ::FUN_00406d00(text, 512, "%s %d/%d", text, current, required);
                            bDisabled = true;
                        }
                        else
                            ::FUN_00406d00(text, 512, "%s %d", text, required);
                        break;
                    }
                    cursor = reinterpret_cast<BSSimpleList<TESConditionItem*>*>(
                        ((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(cursor)))->FUN_00726070())));
                }
            }
            ::FUN_00406d00(
                text, 512, "%s]  %s", text,
                ((const char *)(::FUN_00559450((int *)(reinterpret_cast<BSStringT<char>*>(((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pTopic))->m_item))))))));
        }
        else
        {
            if (((const char *)(::FUN_00559450((int *)(reinterpret_cast<BSStringT<char>*>(((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pTopic))->m_item))))))))
                TaskQueueInterface::CopyStringToBuffer(
                    text, 512,
                    ((const char *)(::FUN_00559450((int *)(reinterpret_cast<BSStringT<char>*>(
                        ((::BGSPerkEntry * *)(&reinterpret_cast<::SimpleListNodeView*>(reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(pTopic))->m_item))))))));
            else
            {
                text[0] = 0;
                ::FUN_005b5e40();
            }
        }
        Tile* pItemTile = ((::Tile *)(reinterpret_cast<::IntListBox *>(&(m_kResponseListBox))->FUN_00764430(iIndex, text, (int (*)(BoxItem *, BoxItem *))(int (*)(ListBoxItem_int_ *, ListBoxItem_int_ *))(0), 0)));
        ::FUN_00406d00(text, 512, "topic_%i", iIndex);
        pItemTile->SetName(text);
        pItemTile->Set(0xFAC, iIndex);
        pItemTile->Set(
            ::FUN_00a01860("_line_alpha"),
            pTopic->m_bInfoHasBeenRead &&
                    !reinterpret_cast<::FUN_00763fd0_shell *>((reinterpret_cast<TESTopicInfo*>(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(pTopic)))->FUN_009611e0())))))->IsFlagSet()
                ? 255
                : 128);
        if (bDisabled)
            reinterpret_cast<::FUN_0071aa60_class *>((pItemTile))->FUN_0071aa60(true);
        if (iIndex <= 2)
            iTopicHeight += (int)reinterpret_cast<TileListBoxCalls*>(pItemTile)->GetFloat(0xFB0);
        bNextTopic = pDialogueItem->AdvanceTopic();
        ++iIndex;
    }
    reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[3]))->FUN_00a012d0(0xFB0, (float)iTopicHeight, false);
    reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<Tile*>(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>(&m_kResponseListBox)))->FUN_00825c00())))->FUN_00a012d0(::FUN_00a01860("_height"),
              reinterpret_cast<TileListBoxCalls*>(((::BSSimpleList< ::TESTopic *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESTopic*>*>(this)))->FUN_00726070())))
                  ->GetFloat(::FUN_00a01860("_ScrollbarHeight")),
              true);
    reinterpret_cast<::FUN_00a012d0_t *>((reinterpret_cast<Tile*>(reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>((reinterpret_cast<TimeGlobal*>(&m_kResponseListBox)))->FUN_00825c00())))->FUN_00a012d0(DAT_011d9504, 0.0f, false);
    reinterpret_cast<::C764930ListMenu *>(&(m_kResponseListBox))->RebuildVisibleTiles();
    m_uiDialogMenuFlags = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
}

// @fnv 0x00763fd0
bool FUN_00763fd0_shell::IsFlagSet()
{
    return (bool)(*reinterpret_cast<char*>(&this->infoPadding26[0]) & 2);
}

struct ListX
{
    ~ListX();
};
namespace p07 {
struct FUN_007643c0
{
    ListX list;
    virtual ~FUN_007643c0();
};
// @fnv 0x007643c0
FUN_007643c0::~FUN_007643c0()
{
    reinterpret_cast<::ClearOwner *>(this)->FUN_007646d0();
    ::fnv_007211c0::FUN_007211c0((int *)(void *)(this));
}
}

// @fnv 0x007620e0
int __cdecl FUN_007620e0()
{
    return 0x3f1;
}

struct Holder00761930
{
    void FUN_00761960();
    void* FUN_00761930(unsigned int);
};
// @fnv 0x00764290
void FUN_00764290()
{
    MenuTopic* pMenuTopicEntry;
    TopicMenuController* pmgr;
    if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)))
    {
        pmgr = (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->pDialogueItem;
        pMenuTopicEntry = 0;
        for (pmgr->SelectTopic(true); (pMenuTopicEntry = pmgr->GetSelectedTopic()) != 0; pmgr->AdvanceTopic())
            pMenuTopicEntry->m_bInfoHasBeenRead = 1;
    }
}

struct WeatherEntry;
struct BSSimpleList_WeatherEntry
{
  public:
    void* m_item;
    void* m_next;
    void Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*)) const;
};
struct ListBoxProxy : public ListBoxBase
{
    BSSimpleList_WeatherEntry list;
    void SortAndSynchronize(int(__cdecl*)(ListBoxItem_int_*, ListBoxItem_int_*));
};
// Sorts the list using the given comparison function, then synchronizes the list box.
// @fnv 0x00764900
void ListBoxProxy::SortAndSynchronize(int(__cdecl* apCompareFn)(ListBoxItem_int_*, ListBoxItem_int_*))
{
    reinterpret_cast<::ItemChangeList *>((void *)&(list))->SortItems((int (*)(InventoryStackRecord *, InventoryStackRecord *))(int (*)(WeatherEntry *, WeatherEntry *))(reinterpret_cast<int(__cdecl*)(WeatherEntry*, WeatherEntry*)>(apCompareFn)));
    reinterpret_cast<::C764930ListMenu *>((reinterpret_cast<ListBox_int_*>(this)))->RebuildVisibleTiles();
}

// @fnv 0x00763ff0
void FUN_00763ff0()
{
    if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)) && (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_eGoodbyeState == 0)
    {
        (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_bServiceDialogue = true;
        (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_bServiceMenuRequested = true;
        if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->pDialogueItem->GetSelectedTopic())
        {
            (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueSpeaker->vfn_264(
                0.0f, (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->pDialogueItem->GetSelectedTopic()->GetActiveResponse(), false);
            (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueSpeaker->bDialogueSelected = true;
        }
        reinterpret_cast<::FUN_00a1d910_shell *>(((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))))->FUN_00a1d910();
    }
}

struct FUN_00ad88b0_h
{
    bool FUN_00ad88b0();
};

struct BSSoundHandleEx
{
};

struct FUN_00764200_shell
{
    void SetActive(bool b);
};

// @fnv 0x00764200
void FUN_00764200_shell::SetActive(bool abActive)
{
    if (((const unsigned char*)this)[0x131] && !abActive)
    {
        reinterpret_cast<::FUN_00ad8830_shell *>((((BSSoundHandleEx*)((char*)this + 0x74))))->FUN_00ad8830(false);
        ((unsigned char*)this)[0x131] = 0;
        ((int*)this)[0x28 / 4] = ((int*)this)[0x134 / 4];
    }
    else if (!((const unsigned char*)this)[0x131] && abActive)
    {
        ((FUN_00ad88b0_h*)((char*)this + 0x74))->FUN_00ad88b0();
        ((unsigned char*)this)[0x131] = 1;
        ((int*)this)[0x134 / 4] = ((int*)this)[0x28 / 4];
        ((int*)this)[0x28 / 4] = 2;
    }
}

void __cdecl FUN_0083e510();
struct FUN_00761960 : Menu
{
    DialogMenu::DialogState m_eDialogState;
    DialogMenu::GoodbyeState m_eGoodbyeState;
    Tile* m_pTiles[4];
    ListBox_int_ m_kResponseListBox;
    TopicMenuController* pDialogueItem;
    SoundPlaybackHandle m_kActorProcessResult;
    MobileObject* m_pDialogueSpeaker;
    char m_cCurrentTopicLabel[128];
    bool m_bResponseStarted;
    unsigned char layoutPadding105[3];
    float m_fCameraTransitionTime;
    unsigned int m_uiDialogMenuFlags;
    DialogMenuPoint2 m_kDialogMenuPoint1, m_kDialogMenuPoint2, m_kDialogMenuPoint3;
    float m_fCameraTransitionAlpha;
    ImageSpaceModifierInstanceDOF* m_pDialogueDepthOfFieldModifier;
    bool m_bPauseRequested, bPaused;
    unsigned char layoutPadding132[2];
    DialogMenu::DialogState m_eStateBeforePause;
    bool m_bServiceDialogue, m_bSuppressDialogueText, m_bServiceMenuRequested;
    unsigned char layoutPadding13B[1];
    ~FUN_00761960();
};
// Calls FUN_00761960, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00761930
void* Holder00761930::FUN_00761930(unsigned int flags)
{
    reinterpret_cast<::FUN_00761960 *>(this)->FUN_00761960::~FUN_00761960();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// @fnv 0x00761960
FUN_00761960::~FUN_00761960()
{
    DAT_011d9514 = false;
    if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueDepthOfFieldModifier)
    {
        ::FUN_005293f0((::ImageSpaceModifierInstance *)(m_pDialogueDepthOfFieldModifier));
        m_pDialogueDepthOfFieldModifier = 0;
    }
    FUN_0083e510();
    (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)) = 0;
}

struct SpeakerStandIn
{
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
    virtual void vf100();
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
    virtual void vf1d0();
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
    virtual void vf224();
    virtual void vf228();
    virtual void vf22c();
    virtual void vf230();
    virtual void vf234();
    virtual void vf238();
    virtual void vf23c();
    virtual void vf240();
    virtual void vf244();
    virtual void vf248();
    virtual void vf24c();
    virtual void vf250();
    virtual void vf254();
    virtual void vf258();
    virtual void vf25c();
    virtual void vf260();
    virtual void SayResponse(float delay, void* response);
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
    bool bDialogueStarted;
};

struct TopicStandIn : public TESTopic
{
};

struct MenuTopicStandIn : public MenuTopic
{
};

struct DialogMenuStandIn : public DialogMenu
{
};

// If a dialogue menu exists, clears its flag, finds the topic's info for the player, speaks the first response, and refreshes the topics.
// @fnv 0x007640a0
void StartDialogueForTopic(TESTopic* topic)
{
    if ((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)))
    {
        (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_bServiceDialogue = false;
        if (topic)
        {
            TESTopicInfo* info4 = reinterpret_cast<::fnv_0061a720::FUN_0061a720_shell *>((((TopicStandIn*)topic)))->FUN_0061a720((*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueSpeaker, ::_g_thePlayer);
            MenuTopic* menuTopic = new MenuTopic(reinterpret_cast<::FUN_00619d00_shell *>((((TopicStandIn*)topic)))->FindQuestForTopicInfo(info4), topic, info4,
                                                 (*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueSpeaker, false);
            reinterpret_cast<::TopicS *>((menuTopic))->HasCur();
            ((SpeakerStandIn*)(*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueSpeaker)
                ->SayResponse(0.0f, ((void *)(reinterpret_cast<::MenuTopic *>((((MenuTopicStandIn*)menuTopic)))->GetActiveResponse())));
            ((SpeakerStandIn*)(*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510))->m_pDialogueSpeaker)->bDialogueStarted = true;
            delete menuTopic;
        }
        reinterpret_cast<::FUN_00a1db20_shell *>((((DialogMenuStandIn*)(*reinterpret_cast<::DialogMenu * *>(&::DAT_011d9510)))))->FUN_00a1db20();
    }
}

struct FUN_007240c0
{
    virtual void vfn00();
    FUN_007240c0();
};
struct FUN_0096a2d0
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_0096a2d0();
    ~FUN_0096a2d0();
};
struct FUN_007642f0 : FUN_007240c0, FUN_0096a2d0
{
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short unk1c;
    unsigned short unk1e;
    float unk20;
    float unk24;
    float unk28;
    unsigned short unk2c;
    FUN_007642f0();
};
// @fnv 0x007642f0
FUN_007642f0::FUN_007642f0()
{
    unk14 = 0;
    unk10 = 0;
    unk0c = 0;
    unk18 = 0;
    unk2c = 0;
    unk1c = 0;
    unk28 = 0.0f;
    unk24 = 0.0f;
    unk20 = 0.0f;
    reinterpret_cast<::FlagS *>(this)->FUN_007a1950(0, 1);
    ::AddToHeadList((int *)(::FUN_007642f0 *)(this));
}

#include "generated/data/fallout/interface/menus/dialogmenu.inc"
