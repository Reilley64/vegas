// Source layout: DialogueItem. PC corrections are in generate_headers.py.
#ifndef FNV_DIALOGUEITEM_H
#define FNV_DIALOGUEITEM_H

#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "layout_support.h"
class DialogueResponse;
class TESObjectREFR;
class DialogueItem
{
  public:
    BSSimpleList<DialogueResponse*> m_kResponseList;          // +0x0
    BSSimpleList<DialogueResponse*>* m_pCurrentResponseList;  // +0x8
    TESTopicInfo* pInfo;                                      // +0xC
    TESTopic* pTopic;                                         // +0x10
    TESQuest* pQuest;                                         // +0x14
    TESObjectREFR* m_pDialogueSpeaker;                        // +0x18
public:
    ::TESObjectREFR *FUN_005e3fa0();
public:
    bool SelectDefaultResponseList();
public:
    ::DialogueResponse *GetActiveResponse();
};
#endif
