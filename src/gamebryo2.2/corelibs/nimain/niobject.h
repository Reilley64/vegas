#ifndef FNV_NIOBJECT_UNIT_H
#define FNV_NIOBJECT_UNIT_H

#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/NiObject_b.h"
#include "niobject_declarations.h"
#include "niobject_packet_decls.h"

// @fnv 0x0045a120
inline unsigned int BSFaceGenMorphData::DynamicCast()
{
    return reinterpret_cast<::FUN_00658930_class *>(&(array_1ec))->GetShortAtOffsetA();
}

// @fnv 0x00653290
inline NiObject* NiObject::DynamicCast(const NiRTTI* rtti)
{
    return reinterpret_cast<::NiObject_b *>((void *)this)->FUN_006532c0((const ::NiRTTI_b *)(rtti)) ? this : 0;
}

#endif
