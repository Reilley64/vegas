// fallout/interface/interfacemanager_h_unit.cpp: TargetClass (1 function)

#include "fnv/decl/FUN_00719390_class.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00717000.h"
#include "interfacemanager.h"

struct TargetClass
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00719390, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x00719360
void* TargetClass::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00719390_class *>(this)->FUN_00719390();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
