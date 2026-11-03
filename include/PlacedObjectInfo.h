#ifndef FNV_OBJ_REFR_H
#define FNV_OBJ_REFR_H
#include "layout_support.h"
#include "NiPoint3.h"
class PlacedObjectInfo
{
  public:
    TESBoundObject* m_pPlacedObject;  // +0x0
    NiPoint3 Angle;                    // +0x4
    NiPoint3 Location;                 // +0x10
};
#endif
