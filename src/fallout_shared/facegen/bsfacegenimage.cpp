// src/fallout_shared/facegen/bsfacegenimage.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/facegen/bsfacegenimage.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_0064ce20.h"
#include "fnv/symbols_00aa1000.h"
struct BSFaceGenImage
{
    virtual ~BSFaceGenImage();
    void* FUN_0064cdf0(unsigned int);
};


// @fnv 0x0064cdf0
void* BSFaceGenImage::FUN_0064cdf0(unsigned int flags)
{
    reinterpret_cast<::FUN_0064ce20 *>((this))->FUN_0064ce20::~FUN_0064ce20();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x2c);
    return this;
}
