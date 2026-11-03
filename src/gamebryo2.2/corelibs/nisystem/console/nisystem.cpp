//
// Gamebryo engine system support.
//
// The MSVC runtime supplies the case-insensitive string comparison;
// the engine exposes it under its own name so shared game code does
// not depend directly on the CRT spelling.


#include "runtime/crt.h"
// @fnv 0x00aa1360
int NiStricmp(const char* a, const char* b)
{
    return fnv::crt::stricmp(a, b);
}

extern "C" void FUN_00ec7ec0(void);

// @fnv 0x00aa1370
void FUN_00aa1370()
{
    FUN_00ec7ec0();
}
