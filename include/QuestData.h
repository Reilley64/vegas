#ifndef FNV_QUEST_DATA_H
#define FNV_QUEST_DATA_H

#include "layout_support.h"
class QuestData
{
  public:
    unsigned char m_ucEntryType;  // +0x0
    unsigned char ucPriority;     // +0x1
    unsigned short layoutPadding2;
    float fQuestDelayTime;  // +0x4
};
#endif
