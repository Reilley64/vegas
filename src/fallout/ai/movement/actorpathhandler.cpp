// src/fallout/ai/movement/actorpathhandler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/movement/actorpathhandler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_009dfed0_cls.h"
#include "fnv/symbols_00401000.h"
struct Base_009e03e0
{
    virtual ~Base_009e03e0();
};


struct ActorPathHandler : Base_009e03e0
{
    void* FUN_009dfe10(unsigned int flags);
};

// Destructs the object and, when flags has bit 0 set, deallocates this; returns this.
// @fnv 0x009dfe10
void* ActorPathHandler::FUN_009dfe10(unsigned int flags)
{
    reinterpret_cast<::FUN_009dfed0_cls *>(this)->FUN_009dfed0_cls::~FUN_009dfed0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
