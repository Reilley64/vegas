#include <cstdarg>
#include <cstdio>
#include "nisystem_decls.h"

// @fnv 0x00a305b0
int __cdecl NiSprintf(char* buffer, unsigned int size, const char* format, ...)
{
    if (!size)
        return 1;
    va_list args;
    va_start(args, format);
    int result = std::vsnprintf(buffer, size, format, args);
    va_end(args);
    buffer[size - 1] = 0;
    return result;
}
