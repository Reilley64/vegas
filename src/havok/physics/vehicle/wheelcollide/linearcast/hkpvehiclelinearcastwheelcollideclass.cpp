// src/havok/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollideclass.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/wheelcollide/linearcast/hkpvehiclelinearcastwheelcollideclass.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkMemoryRouter.h"
#include "fnv/symbols_00c85000.h"

void FUN_00e36b80();


class PCls
{
  public:
    virtual void PV0();
    virtual void PV1();
    virtual void PV2(void* a1, unsigned int a2);
};

class SELF
{
  public:
    int pad;
    unsigned short w;
    SELF* FUN_00dfbd80(unsigned char flag);
};

// Calls FUN_00e36b80, and if bit 0 of flag is set, frees this block of w bytes on the router heap, then returns this.
// @fnv 0x00dfbd80
SELF* SELF::FUN_00dfbd80(unsigned char flag)
{
    FUN_00e36b80();
    if (flag & 1)
    {
        hkMemoryRouter::getInstance().m_heap->blockFree(this, w);
    }
    return this;
}
