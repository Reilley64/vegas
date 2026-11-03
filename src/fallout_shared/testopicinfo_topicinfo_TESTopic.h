// Source layout: TESTopic. PC corrections are in generate_headers.py.
#ifndef FNV_TESTOPIC_H
#define FNV_TESTOPIC_H

#include "fnv/decl/FUN_00619c50_shell.h"
#include "fnv/decl/FUN_00619d00_shell.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/symbols_00619000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "testopicinfo_topicinfo_layout_support.h"
#include "DialogueTopicData.h"
#include "testopicinfo_topicinfo_TESForm.h"
#include "TESFullName.h"
class TESTopic : public TESForm
{
  public:
    TESFullName tESFullNameComponent;  // +0x18
    DialogueTopicData m_Data;              // +0x24
    unsigned char layoutPadding26[2];
    float m_fTopicParamB;                        // +0x28
    BSSimpleList<QuestDialogueInfo*> m_kQuestInfoList;  // +0x2C
    BSStringT<char> m_kDummyPrompt;              // +0x34
    int m_iTopicFlags;                           // +0x3C
    TESTopicInfo* FindMatchingTopicInfo(bool& deferred, TESObjectREFR* speaker, TESObjectREFR* listener, bool filter,
                                        TESTopic* previousTopic, BSSimpleList<DialogueItem*>* history);
    static TESTopicInfo* FindMatchingTopicInfo(const TESTopic* topic, bool& deferred, TESObjectREFR* speaker,
                                               TESObjectREFR* listener, bool filter, TESTopic* previousTopic,
                                               BSSimpleList<DialogueItem*>* history);
};
FNV_STATIC_ASSERT(sizeof(TESTopic) == 0x40);
FNV_STATIC_ASSERT(offsetof(TESTopic, tESFullNameComponent) == 0x18);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_Data) == 0x24);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_fTopicParamB) == 0x28);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_kQuestInfoList) == 0x2C);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_kDummyPrompt) == 0x34);
FNV_STATIC_ASSERT(offsetof(TESTopic, m_iTopicFlags) == 0x3C);
#endif
