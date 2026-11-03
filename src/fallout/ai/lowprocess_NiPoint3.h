// Source layout: NiPoint3. PC corrections are in generate_headers.py.
#ifndef FNV_NIPOINT3_H
#define FNV_NIPOINT3_H

#include "fnv/decl/TESCombatStyle.h"
#include "lowprocess_support.h"
#include "NiMemObject.h"
#pragma pack(push, 4)
class NiPoint3 : public NiMemObject
{
  public:
    NiPoint3& Subtract(const NiPoint3&);
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
public:
    float ComputeMagnitude() const;
public:
    static const ::NiPoint3 ZERO;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPoint3, x) == 0x0);
FNV_STATIC_ASSERT(offsetof(NiPoint3, y) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiPoint3, z) == 0x8);
#endif
