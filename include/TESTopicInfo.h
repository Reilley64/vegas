// Source layout: TESTopicInfo. PC corrections are in generate_headers.py.
#ifndef FNV_TESTOPICINFO_H
#define FNV_TESTOPICINFO_H

#include <cstdint>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00409480_shell.h"
#include "fnv/decl/FUN_00508d70_shell.h"
#include "fnv/decl/FUN_0061cdc0_shell.h"
#include "fnv/decl/FUN_0061cfd0_shell.h"
#include "fnv/decl/FUN_0061e600_t.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/fnv_0087ce80__FUN_0087ce80_shell.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_009e3000.h"
#include "layout_support.h"
#include "PerkEntryConditionSet.h"
#include "TESForm.h"
#include "TopicInfoData.h"
class TESTopicInfo : public TESForm
{
  public:
    PerkEntryConditionSet m_kInfoConditions;  // +0x18
    unsigned short m_uiInfoIndex;    // +0x20
    bool m_bGoodbye;                 // +0x22
    TopicInfoData m_Data;          // +0x23
    unsigned char layoutPadding27;
    BSStringT<char> m_kPrompt;                  // +0x28
    BSSimpleList<TESTopic*> m_kAddTopicList;    // +0x30
    TESTopicInfoData* m_pResponseData;       // +0x38
    TESActorBase* m_pDialogueSpeaker;           // +0x3C
    TESForm* m_pPerkSkillStat;                  // +0x40
    SPEECH_CHALLENGE_LEVEL m_eDifficultyLevel;  // +0x44
    TESQuest* m_pOwnerQuest;                    // +0x48
    unsigned long m_ulTopicFlags;               // +0x4C
    Script* GetResultScript(uintptr_t onEnd);
    TESTopicInfo(DIALOGUE_TYPE type);
    void SetTopicInfoData(TESTopicInfoData* data);
    virtual void InitializeComponent();
    virtual void ClearData();
    void SetOwnerTopic(TESTopic* owner);
    void ResetResponseList();
    void ClearResponses();
    BSSimpleList<TESTopic*>* GetAddTopicList();
    virtual bool LoadForm(TESFile* file);
public:
    void AddTopicList();
};
#endif
