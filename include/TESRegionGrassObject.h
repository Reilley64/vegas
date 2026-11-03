// Source layout: TESRegionGrassObject. PC corrections are in generate_headers.py.
#ifndef FNV_TESREGIONGRASSOBJECT_H
#define FNV_TESREGIONGRASSOBJECT_H

#include "layout_support.h"
#include "TESRegionObjectBase.h"
class TESRegionGrassObject : public TESRegionObjectBase
{
  public:
    TESGrass* pObject;        // +0x4
    TESLandTexture* pParent;  // +0x8
    void AssignLandTexture(TESLandTexture*);
};
#endif
