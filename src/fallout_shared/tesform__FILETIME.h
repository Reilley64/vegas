// Source layout: _FILETIME. PC corrections are in generate_headers.py.
#ifndef FNV_UNIT_TESFORM__FILETIME_H
#define FNV_UNIT_TESFORM__FILETIME_H
#include "tesform_layout_support.h"
class _FILETIME
{
  public:
    unsigned long dwHighDateTime;  // +0x0
    unsigned long dwLowDateTime;   // +0x4
};
#endif
