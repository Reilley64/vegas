// Provisional build file (plan B2): exact copies of the nisystem recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
//
//
// The MSVC runtime supplies the case-insensitive string comparison;
// the engine exposes it under its own name so shared game code does
// not depend directly on the CRT spelling.


#include "runtime/crt.h"
// @fnv 0x00404dc0
int FUN_00404dc0(const char* pcString1, const char* pcString2)
{
    return fnv::crt::stricmp(pcString1, pcString2);
}
