// gamebryo2.2/corelibs/nisystem/nimemobject.cpp: NiPoint2 (3 functions)

#include "fnv/decl/FUN_00633ba0_Class.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "nimemobject_decls.h"

// @fnv 0x004393c0
void Flag512Receiver::SetFlag512(bool enabled)
{
    reinterpret_cast<::FUN_00633ba0_Class *>(this)->FUN_00633ba0(enabled, 0x200);
}

// Initializes the point's x and y components from the two float arguments.
// @fnv 0x00452dc0
NiPoint2::NiPoint2(float afX, float afY)
{
    x = afX;
    y = afY;
}

#pragma optimize("gsty", on)
#pragma optimize("", off)

struct _NiAllocatorDummy
{
    virtual void v0();
    virtual void v1();
    virtual void Deallocate(void* pvMemory, int aiAllocationType, size_t stSizeInBytes);
};

__pragma(optimize("gsty", on))
// @fnv 0x00aa1490
    void __cdecl FUN_00aa1490(void* apMemory, unsigned int stElementSize)
{
    if (apMemory != 0)
    {
        (*reinterpret_cast<_NiAllocatorDummy**>((*reinterpret_cast<void * *>(&::DAT_011f6080))))->Deallocate(apMemory, 4, static_cast<size_t>(-1));
    }
}
