
// src/gamebryo2.2/corelibs/nisystem/nifile_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nisystem/nifile.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/symbols_00aa8000.h"
#include "fnv/symbols_00afd000.h"
#include "fnv/symbols_011f8000.h"
#include "nifile_packet.h"
// The dispatch helper retains the original unoptimized request construction.
#pragma optimize("", off)

class FUN_00afe9f0
{
  public:
    FUN_00afe9f0(int aiFlags);
    ~FUN_00afe9f0();
    int unk00;
};

struct Dummy_0086bce0;
extern bool DAT_011f81e0;

void __cdecl FUN_00aa1b90(void (*apfnCallback)(const char*, int, unsigned int));
void __cdecl FUN_00aa1a70(void (*apfnCallback)());

class FUN_00afdc60 : public FUN_00afe9f0
{
  public:
    FUN_00afdc60(int aiArg1, int aiArg2, bool abFlag);
};

// @fnv 0x00afdc60
FUN_00afdc60::FUN_00afdc60(int aiArg1, int aiArg2, bool abFlag) : FUN_00afe9f0(0)
{
    int aiUnused[3];
    (void)aiUnused;
    if (!(*reinterpret_cast<::Dummy_0086bce0 * *>(&::g_fileFinder)))
        (*reinterpret_cast<::Dummy_0086bce0 * *>(&::g_fileFinder)) = (Dummy_0086bce0*)this;
    FUN_00aa1b90(FUN_00afdf00);
    FUN_00aa1a70(((void (&)())::FUN_00afde50));
    DAT_011f81e0 = abFlag;
}

#include "generated/data/gamebryo2.2/corelibs/nisystem/nifile_od_variant.inc"
