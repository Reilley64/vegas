
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>

struct FUN_00aff000_tbl
{
    char pad[0x10];
    HANDLE m10;
    unsigned int GetValue(unsigned int* param);
};

// Calls GO with m10; on success stores the returned 64-bit value through param and returns 0, otherwise stores 0 and returns 4.
// @fnv 0x00aff000
unsigned int FUN_00aff000_tbl::GetValue(unsigned int* param)
{
    unsigned int res;
    LARGE_INTEGER local;

    if (GetFileSizeEx(this->m10, &local))
    {
        *(unsigned __int64*)param = local.QuadPart;
        res = 0;
    }
    else
    {
        *(unsigned __int64*)param = 0;
        res = 4;
    }
    return res;
}
