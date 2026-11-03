// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00ee6d86
#include <winsock2.h>
#include <windows.h>
int FUN_00ee6d86(unsigned short version, void* data)
{
    return WSAStartup(version, data);
}
