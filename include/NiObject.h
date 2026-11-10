// Source layout: NiObject. PC corrections are in generate_headers.py.
#ifndef FNV_NIOBJECT_H
#define FNV_NIOBJECT_H
#include "layout_support.h"
#include "NiRefObject.h"
struct NiRTTI;
struct NiObject : public NiRefObject
{
  public:
public:
    ::NiObject *DynamicCast(const ::NiRTTI *);
};
#endif
