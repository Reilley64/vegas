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

// @fnv 0x00aa1370
int FUN_00aa1370(const char* a, const char* b, unsigned int n)
{
    return fnv::crt::strnicmp(a, b, n);
}
