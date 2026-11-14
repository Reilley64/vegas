// Source layout: TopicInfoArray. PC corrections are in generate_headers.py.
#ifndef FNV_TOPICINFOARRAY_H
#define FNV_TOPICINFOARRAY_H
#include "fnv/decl/NiFormArray.h"
#include "layout_support.h"
class TopicInfoArray : public NiTLargePrimitiveArray<TESTopicInfo*>
{
  public:
    TopicInfoArray();
    ~TopicInfoArray();
};
#endif
