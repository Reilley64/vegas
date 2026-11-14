// WinMain's four log-path builders (statements S2 to S5), the functions
// that return three of their buffers, and those buffers, in a unit of their
// own so that a link that reaches them loads no other code (VEGAS-127).
// FUN_00c3bb80 was defined in src/fallout_shared/tesfile.cpp, the others
// and DAT_01202b48 in src/staging/blk_00c20000_od.cpp. Generated data
// defined DAT_01202938, DAT_01202a40 and DAT_01202c50; the native data
// composition retires those lines (docs/native-data-ownership.md).
#include <cstring>
#include "runtime/crt.h"
#include "fnv/symbols_00c3b000.h"
#include "fnv/symbols_01202000.h"

char DAT_01202938[260];
char DAT_01202a40[260];
char DAT_01202c50[260];

// @fnv 0x00c3bb80
char* FUN_00c3bb80()
{
    return ::DAT_01202c50;
}

// @fnv 0x00c3bb90
void FUN_00c3bb90(const char* src)
{
    strcpy_s(DAT_01202c50, 260, DAT_01202fa0);
    strcat_s(DAT_01202c50, 260, src);
}

namespace fnv_00c3bbe0 {
// @fnv 0x00c3bbe0
void __cdecl FUN_00c3bbe0(const char* pcSuffix)
{
    fnv::crt::strcpy_s(::DAT_01202b48, 260, ::DAT_01202fa0);
    fnv::crt::strcat_s(::DAT_01202b48, 260, pcSuffix);
}
}  // namespace fnv_00c3bbe0

extern char DAT_01202a40[0x104];
// Copies DAT_01202fa0 into DAT_01202a40, then appends p to it.
// @fnv 0x00c3bc30
void __cdecl FUN_00c3bc30(const char* pcSuffix)
{
    strcpy_s(DAT_01202a40, 0x104, DAT_01202fa0);
    strcat_s(DAT_01202a40, 0x104, pcSuffix);
}

namespace fnv_00c3bc80 {
// Copies DAT_01202fa0 into DAT_01202938, then appends src to that buffer.
// @fnv 0x00c3bc80
void __cdecl FUN_00c3bc80(const char* pcSuffix)
{
    fnv::crt::strcpy_s(::DAT_01202938, 0x104, ::DAT_01202fa0);
    fnv::crt::strcat_s(::DAT_01202938, 0x104, pcSuffix);
}
}  // namespace fnv_00c3bc80

char DAT_01202b48[260];
// @fnv 0x00c3bbd0
char* __cdecl FUN_00c3bbd0()
{
    // fnv_00c3bbe0::FUN_00c3bbe0 writes up to 260 characters there. The
    // recipe binds the next address, 0x01202c50, 264 bytes after the buffer.
    static_assert(sizeof(DAT_01202b48) == 260);
    return DAT_01202b48;
}

extern char DAT_01202a40[0x104];

// @fnv 0x00c3bc20
char* __cdecl FUN_00c3bc20()
{
    return DAT_01202a40;
}
