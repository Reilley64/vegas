
#include "fnv/decl/FUN_00658930_class.h"
#include "fnv/decl/NiObject_b.h"
#include "gamebryo2.2/corelibs/nimain/niobject.h"

// @fnv 0x0045a120
unsigned int BSFaceGenMorphData::DynamicCast()
{
    return reinterpret_cast<::FUN_00658930_class *>(&(array_1ec))->GetShortAtOffsetA();
}

// @fnv 0x00653290
NiObject* NiObject::DynamicCast(const NiRTTI* rtti)
{
    return reinterpret_cast<::NiObject_b *>((void *)this)->FUN_006532c0((const ::NiRTTI_b *)(rtti)) ? this : 0;
}
