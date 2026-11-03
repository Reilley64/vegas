// Source layout: TESTopic. PC corrections are in generate_headers.py.
#ifndef FNV_TESTOPIC_H
#define FNV_TESTOPIC_H
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "lowprocess_support.h"
#include "DialogueTopicData.h"
#include "lowprocess_TESForm.h"
#include "TESFullName.h"
class TESTopic : public TESForm
{
  public:
    bool FUN_00508d70();
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
#endif
