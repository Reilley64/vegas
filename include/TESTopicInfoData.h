#ifndef FNV_TESCONVERSATIONDATA_H
#define FNV_TESCONVERSATIONDATA_H

#include "fnv/decl/TopicLinkLists.h"
#include "fnv/decl/Vec3.h"
#include "fnv/symbols_00460000.h"
#include "layout_support.h"
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*> m_kLinkFromList;          // +0x0
    BSSimpleList<TESTopic*> m_kLinkToList;            // +0x8
    BSSimpleList<TESTopicInfo*> m_kFollowUpInfoList;  // +0x10
    TESTopicInfoData();
    ~TESTopicInfoData();
    BSSimpleList<TESTopic*>* GetLinkToList();
};
#endif
