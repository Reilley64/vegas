#ifndef FNV_TOPIC_INFO_DATA_H
#define FNV_TOPIC_INFO_DATA_H

#include "layout_support.h"
class TopicInfoData
{
  public:
    char type;              // +0x0
    char nextSpeaker;       // +0x1
    char flags;             // +0x2
    char DialogueMetadata;  // +0x3
};
#endif
