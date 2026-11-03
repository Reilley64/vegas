// gamebryo2.2/corelibs/nisystem/nimemobject.cpp: NiPoint2 (3 functions)

#include "fnv/decl/FUN_00633ba0_Class.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "nimemobject_decls.h"
#include <cstdint>

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


// @fnv 0x00a5c230
void* __cdecl FUN_00a5c230()
{
    return static_cast<void*>(&(*reinterpret_cast<unsigned char (*)[]>(&::g_011f4304))[0]);
}


struct FUN_00a5c200 : ::NiObject
{
    ::NiFixedString name;
    void* controller;
    void* extraData;
    unsigned short extraDataSize, extraDataCapacity;
    FUN_00a5c200();
};
// @fnv 0x00a5c200
FUN_00a5c200::FUN_00a5c200()
{
    words[0] = (uintptr_t)::DAT_0109b244;
    name = (*reinterpret_cast<::NiFixedString *>(&::DAT_0109b220));
    controller = 0;
    extraData = 0;
    extraDataSize = 0;
    extraDataCapacity = 0;
}

struct S_00aa1420_Object
{
    virtual void S_00aa1420_v0();
    virtual void* S_00aa1420_v1(int* size, int* alignment, int eventType, int accurateSize, int file, int line, int function);
};

struct S_00aa1420_Holder
{
    S_00aa1420_Object* m_00;
};

// Defaults the size to 1 if zero, then allocates through the memory manager's allocator (size, alignment 4, array new) and returns the block.
// @fnv 0x00aa1420
void* __cdecl FUN_00aa1420(size_t arg)
{
    int value = arg ? static_cast<int>(arg) : 1;
    int alignment = 4;
    S_00aa1420_Object* obj = reinterpret_cast<S_00aa1420_Holder*>((*reinterpret_cast<void * *>(&::DAT_011f6080)))->m_00;
    return obj->S_00aa1420_v1(&value, &alignment, 2, 0, 0, -1, 0);
}

namespace SizedDeleteDetail {
enum MemoryOperation
{
    ScalarDelete = 3
};

class Allocator
{
  public:
    virtual ~Allocator();
    virtual void* Allocate();
    virtual void Deallocate(void* memory, MemoryOperation operation, unsigned int size);
};

class Manager
{
    Allocator* allocator;

  public:
    static Manager& Current()
    {
        return *static_cast<Manager*>((*reinterpret_cast<void * *>(&::DAT_011f6080)));
    }

    void Deallocate(void* memory, unsigned int size)
    {
        allocator->Deallocate(memory, ScalarDelete, size);
    }
};
}

// @fnv 0x00aa1460
void FUN_00aa1460(void* memory, unsigned int size)
{
    if (memory)
        SizedDeleteDetail::Manager::Current().Deallocate(memory, size);
}
