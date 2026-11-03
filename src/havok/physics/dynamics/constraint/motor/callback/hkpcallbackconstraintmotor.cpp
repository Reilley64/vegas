
// src/havok/physics/dynamics/constraint/motor/callback/hkpcallbackconstraintmotor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/motor/callback/hkpcallbackconstraintmotor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include <new>
#include "fnv/decl/FUN_00e48400.h"
#include "havok/hkpCallbackConstraintMotor.h"

struct FUN_00e483d0_Class;



struct FUN_00e483d0_Object
{
    virtual void unused() = 0;
    unsigned short type;

};

struct FUN_00e483d0_Class
{
    void FUN_00e483d0();
};

// Allocates a 0x28-byte object from the heap allocator, sets its type to 0x28, and passes this to its FUN_00e48400 method.
// @fnv 0x00e483d0
void FUN_00e483d0_Class::FUN_00e483d0()
{
    FUN_00e483d0_Object* object = static_cast<FUN_00e483d0_Object*>(hkMemoryRouter::getInstance().heap().blockAlloc(0x28));

    object->type = 0x28;
    new ((void *)(object)) ::FUN_00e48400((const ::SourceData *)(::FUN_00e483d0_Class *)(this));
}
