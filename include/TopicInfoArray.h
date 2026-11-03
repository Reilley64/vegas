// Source layout: TopicInfoArray. PC corrections are in generate_headers.py.
#ifndef FNV_TOPICINFOARRAY_H
#define FNV_TOPICINFOARRAY_H
#include "fnv/decl/NiFormArray.h"
#include "layout_support.h"
#pragma pack(push, 4)
class TopicInfoArray : public NiTLargePrimitiveArray<TESTopicInfo*>
{
  public:
    TopicInfoArray();
    ~TopicInfoArray();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TopicInfoArray) == 0x18);
#endif
