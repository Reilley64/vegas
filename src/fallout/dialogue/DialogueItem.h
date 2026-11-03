// Authored check-time copy of the canonical generated DialogueItem layout.
// Content mirrors include/DialogueItem.h; the member declarations appended at
// the end are the canonical generated-header additions requested for
// FNV_DIALOGUEITEM_H guard keeps this copy conflict-free until the canonical
// header is regenerated and this file retires.
#ifndef FNV_DIALOGUEITEM_H
#define FNV_DIALOGUEITEM_H

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
    DialogueResponse* GetActiveResponse();
    TESTopicInfo* GetInfo();
    TESQuest* GetQuest();
    TESTopic* GetAudioBackendData();
};
#endif
