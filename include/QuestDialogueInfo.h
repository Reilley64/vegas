#ifndef FNV_QUEST_INFO_H
#define FNV_QUEST_INFO_H

#include "fnv/decl/BaseProcess.h"
#include "layout_support.h"
#include "INFO_LINK_ELEMENT.h"
#include "TopicInfoArray.h"
class QuestDialogueInfo
{
  public:
    TESQuest* pQuest;                                     // +0x0
    TopicInfoArray infoArray;                             // +0x4
    BSSimpleArray<INFO_LINK_ELEMENT, 1024> m_kInfoLinks;  // +0x1C
    TESQuest* m_pAlternateQuest;                          // +0x2C
    bool bInitialized;                                    // +0x30
    unsigned char layoutPadding31;
    unsigned short layoutPadding32;
};
#endif
