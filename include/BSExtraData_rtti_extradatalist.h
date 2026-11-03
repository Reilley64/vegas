// Source layout: BSExtraData. PC corrections are in generate_headers.py.
#ifndef FNV_BSEXTRADATA_H
#define FNV_BSEXTRADATA_H

#include "layout_support.h"
class BSExtraData
{
  public:
    virtual ~BSExtraData();  // the original class is polymorphic (rtti_variants.py)
  public:
    unsigned char m_ucExtraDataType;  // +0x4
    unsigned char layoutPadding5;
    unsigned short layoutPadding6;
    BSExtraData* pNext;  // +0x8
};
#endif
