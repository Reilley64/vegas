// Source layout: NiPoint3. PC corrections are in generate_headers.py.
#ifndef FNV_NIPOINT3_H
#define FNV_NIPOINT3_H
#include "layout_support.h"
struct NiPoint3
{
  public:
    NiPoint3(float x, float y, float z);
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
};
#endif
