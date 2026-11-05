#include "havok/ErrorDiagnostics.h"
#ifdef _WIN32
#include <intrin.h>
#endif
namespace havok::diagnostics
{
void Breakpoint()
{
#ifdef _WIN32
    __debugbreak();
#else
    __builtin_debugtrap();
#endif
}
}
