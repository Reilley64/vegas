// Source layout: TESDescription. PC corrections are in generate_headers.py.
#ifndef FNV_TESDESCRIPTION_H
#define FNV_TESDESCRIPTION_H

#include "layout_support.h"
#include "BaseFormComponent.h"
class TESDescription : public BaseFormComponent
{
  public:
    unsigned long m_uiDescriptionFileOffset;  // +0x4
};
#endif
