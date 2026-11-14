#include <stddef.h>
#include <windows.h>
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00aa29e0
int __cdecl FUN_00aa29e0(const char* pcText, const char* pcTitle)
{
    MessageBoxA(NULL, pcText, pcTitle, MB_TOPMOST);
    return 0;
}
