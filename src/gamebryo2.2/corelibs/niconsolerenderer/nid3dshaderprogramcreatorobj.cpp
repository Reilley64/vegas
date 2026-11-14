
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <windows.h>
#include <cstring>
#include "fnv/symbols_00aa0000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00e93000.h"
// Allocates a buffer of size b, copies a into it, stores the pointer and size in c and d, and returns false with an error if a or b is zero.
// @fnv 0x00e98370
bool CopyShaderBuffer(intptr_t apSource, int uiSize, int* pOutBuffer, int* pOutSize, int* e, int* f, int g)
{
    *pOutBuffer = 0;
    *pOutSize = 0;
    *e = 0;
    *f = 0;
    if (apSource != 0 && uiSize != 0)
    {
        void* pBuffer = FUN_00aa1070((unsigned int)uiSize);
        *pOutBuffer = (intptr_t)pBuffer;
        memmove(pBuffer, (const void*)apSource, (unsigned int)uiSize);
        *pOutSize = uiSize;
        return true;
    }
    ::FUN_00aa0020(1, g, "Invalid shader buffer\n");
    return false;
}

extern "C" const char str_010f1338[];
extern "C" const char str_010f1628[];
extern "C" const char str_010f12a8[];



typedef int(__cdecl* FUN_00aa0020_4args)(int, int, const char*, const char*);

// Resolves a file path, opens it, reads its entire contents into a newly allocated buffer, and returns the buffer and size via out parameters.
// @fnv 0x00e981f0
bool FUN_00e981f0(const char* apFilePath, void** apOutBuffer, unsigned int* outSize,
                            unsigned int* apOutExtra1, unsigned int* apOutExtra2, int aiContext)
{
    char szResolvedPath[0x104];
    void* hFile;
    unsigned int uiFileSize;
    DWORD uiBytesRead;
    void* pBuffer;

    *apOutBuffer = 0;
    *outSize = 0;
    *apOutExtra1 = 0;
    *apOutExtra2 = 0;

    if (apFilePath == 0 || *apFilePath == 0)
    {
        ::FUN_00aa0020(1, aiContext, str_010f12a8);
        return false;
    }

    if (!::FindShaderProgramFile(apFilePath, szResolvedPath, 0x104))
    {
        ((FUN_00aa0020_4args)((int (&)(int, int, const char *))::FUN_00aa0020))(1, aiContext, str_010f1338, apFilePath);
        return false;
    }

    hFile = CreateFileA(szResolvedPath, 0x80000000, 1, 0, 3, 0, 0);
    if (hFile == (void*)-1)
    {
        ((FUN_00aa0020_4args)((int (&)(int, int, const char *))::FUN_00aa0020))(1, aiContext, str_010f1628, szResolvedPath);
        return false;
    }

    uiFileSize = GetFileSize(hFile, 0);
    pBuffer = FUN_00aa1070(uiFileSize + 4);
    if (pBuffer == 0)
    {
        return false;
    }
    std::memset(pBuffer, 0, uiFileSize + 4);
    ReadFile(hFile, pBuffer, uiFileSize, &uiBytesRead, 0);
    CloseHandle(hFile);
    if (uiBytesRead != uiFileSize)
    {
        ::FUN_00aa10f0(pBuffer);
        return false;
    }
    *outSize = uiFileSize;
    *apOutBuffer = pBuffer;
    return true;
}

#include "generated/data/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramcreatorobj.inc"
