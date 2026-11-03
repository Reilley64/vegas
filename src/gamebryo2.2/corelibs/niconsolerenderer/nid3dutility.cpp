// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// Splits pcFilename into drive, directory, file name and extension buffers via __splitpath_s and returns true.
#include "runtime/crt.h"
// @fnv 0x00e983f0
bool __cdecl FUN_00e983f0(const char* pcPath, char* pcDriveOut, char* pcDirOut, char* pcFnameOut, char* pcExtOut)
{
    fnv::crt::splitpath_s(pcPath, pcDriveOut, 3, pcDirOut, 0x104, pcFnameOut, 0x104, pcExtOut, 0x100);
    return true;
}

#include <string.h>

struct SplitPathOutputBuffers
{
    unsigned int driveStorage;
    char ext[0x100];
    char fname[0x100];
    char dir[0x104];
};

// Extracts the file extension from pcFilename via __splitpath_s and copies it into pcDest, returning true.
// @fnv 0x00e98430
bool __cdecl FUN_00e98430(const char* pcFilename, char* pcDest, unsigned int uiDestSize)
{
    SplitPathOutputBuffers buffers;
    unsigned int uiLen;

    fnv::crt::splitpath_s(pcFilename, (char*)&buffers.driveStorage, 3, buffers.dir, 0x104, buffers.fname, 0x100, buffers.ext,
                  0x100);

    uiLen = strlen(buffers.ext);
    strncpy_s(pcDest, uiDestSize, buffers.ext, uiLen);
    return true;
}
