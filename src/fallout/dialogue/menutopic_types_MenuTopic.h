// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_MENUTOPIC_H
#define FNV_MENUTOPIC_H

#include "fnv/decl/BraceString530.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/TopicS.h"
#include "layout_support.h"
#include "TESQuest.h"
#include "TESTopic.h"
#include "TESTopicInfo.h"
#include "layout_support.h"
class MenuTopic;
class MenuTopic
{
  public:
    BSStringT<char> m_kPrompt;  // +0x0, 8 bytes
    bool m_bFirstFlag;          // +0x8, 1 bytes
    bool m_bIsRefusal;          // +0x9, 1 bytes
    bool m_bThirdFlag;          // +0xA, 1 bytes
    unsigned char layoutPaddingB[1];
    BSSimpleList<DialogueResponse*> m_kResponseList;          // +0xC, 8 bytes
    TESQuest* pQuest;                                         // +0x14, 4 bytes
    TESTopicInfo* pInfo;                                      // +0x18, 4 bytes
    TESTopic* m_pOriginalTopic;                               // +0x1C, 4 bytes
    BSSimpleList<DialogueResponse*>* m_pCurrentResponseList;  // +0x20, 4 bytes
    bool m_bIsRemappedRumor;                                  // +0x24, 1 bytes
    bool m_bInfoHasBeenRead;                                  // +0x25, 1 bytes
    unsigned char layoutPadding26[2];
    TESTopic* pTopic;  // +0x28, 4 bytes
    // MenuTopic
    // void __cdecl MenuTopic::*()
    // FillResponseList
    // bool __cdecl MenuTopic::*()
    // const BSStringT<char>& __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // TESTopicInfo* __cdecl MenuTopic::*()
    // TESTopic* __cdecl MenuTopic::*()
    // TESQuest* __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // TESTopic* __cdecl MenuTopic::*()
    // void __cdecl MenuTopic::*(TESTopic*)
    // bool __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // DialogueResponse* __cdecl MenuTopic::*()
    // bool __cdecl MenuTopic::*()
    // void __cdecl MenuTopic::*(bool)
    // bool __cdecl MenuTopic::*()
    // void __cdecl MenuTopic::*(bool)
    // unsigned short __cdecl MenuTopic::*()
    // SaveGame
    // LoadGame
    // MenuTopic& __cdecl MenuTopic::*(const MenuTopic&)
    // void* __cdecl MenuTopic::*(unsigned int)
    MenuTopic(TESQuest*, TESTopic*, TESTopicInfo*, MobileObject*, bool);
    DialogueResponse* GetActiveResponse();
    void FUN_0083df80(TESQuest*, TESTopic*, TESTopicInfo*, MobileObject*);
    TESTopicInfo* GetTopicInfo();
};
#endif
