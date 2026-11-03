// fallout/ai/spectatorpackage.cpp: SpectatorPackage (1 function)
#include "fnv/symbols_009f9000.h"
#include "spectatorpackage_decls.h"

// @fnv 0x009f9c80
int SpectatorPackage::IsComplete(const SpectatorPackage& other)
{
    if (&other != this)
    {
        ::FUN_009f9c20((::FUN_009f9c20_cls *)(::SpectatorPackage *)(this));
        if (::FUN_009f9bb0((::S_009f9bb0_Rec *)(::SpectatorPackage *)(this), (::S_009f9bb0_Rec *)(&other)) < 0)
            return 0x8007000e;
    }
    return 0;
}
