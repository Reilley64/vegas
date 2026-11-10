// src/gamebryo2.2/corelibs/nimain/niaccumulator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niaccumulator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00aa0b00
#include "fnv/decl/FUN_00a5d3d0.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f6000.h"
char const* const* __cdecl FUN_00aa0b00()
{
    return &(*reinterpret_cast<const char *const *>(&::g_011f6060));
}

class NiRefObject
{
  public:
    virtual ~NiRefObject();
};
extern int DAT_010a2304;
class NiAccumulator : public NiRefObject
{
  public:
    void* FUN_00aa0b10(unsigned int);
};
// Sets the vtable to DAT_010a2304, runs the NiRefObject destructor, and frees this with _delete when a1 has bit 0 set.
// @fnv 0x00aa0b10
void* NiAccumulator::FUN_00aa0b10(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_010a2304;
    reinterpret_cast<class ::FUN_00a5d3d0 *>((this))->FUN_00a5d3d0::~FUN_00a5d3d0();
    if (auiFlags & 1)
        ::FUN_00aa1460(this, 12);
    return this;
}
