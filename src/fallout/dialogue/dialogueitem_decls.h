// Authored check-time copy of the canonical generated DialogueItem layout.
// Content mirrors include/DialogueItem.h; the member declarations appended at
// the end are the canonical generated-header additions requested for
// FNV_DIALOGUEITEM_H guard keeps this copy conflict-free until the canonical
// header is regenerated and this file retires.
#ifndef FNV_DIALOGUEITEM_H
#define FNV_DIALOGUEITEM_H

#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "layout_support.h"
class DialogueItem
{
  public:
    BSSimpleList<DialogueResponse*> m_kResponseList;          // +0x0
    BSSimpleList<DialogueResponse*>* m_pCurrentResponseList;  // +0x8
    TESTopicInfo* pInfo;                                      // +0xC
    TESTopic* pTopic;                                         // +0x10
    TESQuest* pQuest;                                         // +0x14
    TESObjectREFR* m_pDialogueSpeaker;                        // +0x18
    ~DialogueItem();
    TESObjectREFR* SelectDefaultResponseList();
    DialogueResponse* GetActiveResponse();
};
#endif
