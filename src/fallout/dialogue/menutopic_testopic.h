// Source layout: TESTopic. PC corrections are in generate_headers.py.
#ifndef FNV_TESTOPIC_H
#define FNV_TESTOPIC_H

#include "fnv/decl/FUN_00619d00_shell.h"
#include "fnv/decl/FUN_0061a760_shell.h"
#include "fnv/decl/FUN_0083dea0_class.h"
#include "fnv/decl/TESRegion.h"
#include "fnv/decl/TopicMethods.h"
#include "fnv/decl/fnv_0061a720__FUN_0061a720_shell.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_0061b000.h"
#include "fnv/symbols_006a9000.h"
#include "layout_support.h"
#include "DialogueTopicData.h"
#include "TESForm.h"
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
    bool IsNew();
};
#endif
