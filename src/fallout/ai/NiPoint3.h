// Source layout: NiPoint3. PC corrections are in generate_headers.py.
#ifndef FNV_NIPOINT3_H
#define FNV_NIPOINT3_H
#include "fnv/decl/FUN_00416870_t.h"
#include "layout_support.h"
#pragma pack(push, 4)
class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
    // Declaration recovered for 0x00416870 (?Set@NiPoint3@@QAEXMMM@Z); not part of the layout.
public:
    static const ::NiPoint3 ZERO;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPoint3, x) == 0x0);
FNV_STATIC_ASSERT(offsetof(NiPoint3, y) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiPoint3, z) == 0x8);
#endif
