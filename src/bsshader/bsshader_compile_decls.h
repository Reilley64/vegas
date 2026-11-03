// bsshader/bsshader_compile_decls.h: declares _FILETIME, NiBinaryStream, FileFinder, ShaderBufferCollection, ShaderBufferTableBuilder and more
#ifndef BSSHADER_COMPILE_DECLS_H
#define BSSHADER_COMPILE_DECLS_H

#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00af5000.h"
#include "fnv/symbols_00afe000.h"
#include "fnv/symbols_00be0000.h"
#include "fnv/symbols_00ee6000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_0106e000.h"
#include "fnv/symbols_01094000.h"
#include "fnv/symbols_011c1000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "bsshader_decls.h"
class IMemoryHeap;
#include "MemoryManager.h"

extern "C" void __security_check_cookie(unsigned int);
extern "C" int strcpy_s(char*, unsigned int, const char*);
extern "C" int strcat_s(char*, unsigned int, const char*);
struct _iobuf;
extern "C" _iobuf* fopen(const char*, const char*);
extern "C" unsigned int fwrite(const void*, unsigned int, unsigned int, _iobuf*);
extern "C" int fclose(_iobuf*);
struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
struct _FILETIME
{
    unsigned int dwLowDateTime, dwHighDateTime;
};
class BSFile;
class NiBinaryStream
{
  public:
    unsigned int Read(void*, unsigned int);
};
class FileFinder
{
  public:
    static BSFile* GetFile(const char*, NiFile::OpenMode, unsigned int, unsigned int);
};
class ShaderBufferRecord;
class ShaderBufferCollection
{
  public:
    ShaderBufferRecord* Get(const char*);
};
class ShaderBufferTableBuilder
{
  public:
    void Add(const char*, char*, unsigned int);
};
class ID3DXBuffer;
class ID3DXConstantTable;
class ID3DXInclude;
class NiMemObjectAllocation
{
  public:
    static void* operator new(unsigned int);
};
class GraphicsRenderer;
class NiD3DVertexShader
{
  public:
    // This aliases the constructor entry: MSVC inline assembly cannot name a constructor.
public:
    NiD3DVertexShader(::GraphicsRenderer *const);
};
extern bool DAT_011ae638;
extern bool DAT_011f94a7;
extern ShaderBufferTableBuilder* DAT_011f9494;

// Pooled strings, the include vtable and the compiler exception handler.

int FUN_00f2d322(void*, void*, void*, void*);
extern const unsigned char DAT_01063ec8[];
extern const unsigned char DAT_010bc610[];
extern const unsigned char DAT_010bc754[];
extern const unsigned char DAT_010bc784[];
extern const unsigned char DAT_010bc7b8[];
extern const unsigned char DAT_010bc7e4[];
extern const unsigned char DAT_010bc7fc[];
extern const unsigned char DAT_010bc808[];
extern const unsigned char DAT_010bc820[];
extern const unsigned char DAT_010bc824[];
extern const unsigned char DAT_010bc828[];
extern const unsigned char DAT_010bc82c[];
extern const unsigned char DAT_010bc860[];
extern const unsigned char DAT_010bc868[];
void FUN_00ec8660();
#endif
