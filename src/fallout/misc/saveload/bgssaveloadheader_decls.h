// fallout/misc/saveload/bgssaveloadheader_decls.h: declares SaveLoadHeader, BGSSaveLoadManager, BGSLoadGameBuffer, SaveLoadFile, NiPixelData and more
#ifndef FNV_BGSSAVELOADHEADER_DECLS_H
#define FNV_BGSSAVELOADHEADER_DECLS_H


#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/FUN_004381b0_shell.h"
#include "fnv/decl/FUN_00846490_t.h"
#include "fnv/decl/FUN_0084ff90_shell.h"
#include "fnv/decl/FUN_00864740_shell.h"
#include "fnv/decl/S_0064dac0.h"
#include "fnv/decl/fnv_0043b1b0__FUN_0043b1b0_shell.h"
#include "fnv/decl/fnv_008646f0__FUN_008646f0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_004f3000.h"
#include "fnv/symbols_00846000.h"
#include "fnv/symbols_0084d000.h"
#include "fnv/symbols_00a5f000.h"
#include "fnv/symbols_011aa000.h"
#include "fnv/symbols_011c1000.h"
class SaveLoadFile;
class NiPixelFormat;
class NiTexture;

class SaveLoadHeader
{
  public:
};

class BGSSaveLoadManager
{
  public:
};

class BGSLoadGameBuffer
{
  public:
    BGSLoadGameBuffer();
    void FUN_008464f0(SaveLoadFile* file);
};

class SaveLoadFile
{
  public:
    unsigned int Read(void* buffer, unsigned int size);
    void SetFilePosition(int offset);
};

class NiPixelData
{
  public:
    NiPixelData(unsigned int width, unsigned int height, const NiPixelFormat& format, unsigned int flags,
                unsigned int extra);
};

class BSFadeNode
{
  public:
    BSFadeNode(const char* name, void* rectangle);
};

class FUN_004f31d0_holder
{
  public:
};

class NiMemObject
{
  public:
    static void* operator new(unsigned int size);
};

extern int(__cdecl* DAT_00fdf0d4)(char* path);
extern char* DAT_011a2224;

extern "C" void* __cdecl fnv_zlib_memset(void* destination, int value, unsigned int size);

#endif
