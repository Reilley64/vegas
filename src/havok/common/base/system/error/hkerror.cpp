
// src/havok/common/base/system/error/hkerror.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/error/hkerror.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include "havok/ErrorDiagnostics.h"
#include <cstddef>
#include <new>
#include "fnv/decl/CC0280Writer.h"
#include "fnv/decl/FUN_00c903a0_class.h"
#include "fnv/decl/FUN_00cc00e0.h"
#include "fnv/decl/SinkOwner.h"
#include "fnv/decl/hkOstreamDBB7.h"
#include "fnv/symbols_01268000.h"
void __cdecl __debugbreak();
struct CharBuffer
{
    char* begin;
    char* end;
    unsigned int capacity;
};
struct FUN_00cb1600_class
{
    void FUN_00cb1600(char* storage, unsigned int size);
};
struct FUN_00cc01c0_class
{
};
struct FUN_00cc00e0_class
{
};
struct ErrorReporter
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual int Report(int severity, unsigned int category, const char* text, const char* file, int line);
};
struct CB1600Bool
{
    char m_cBooleanValue;

    CB1600Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class CB1600ReferencedObject
{
  public:
    virtual void unk00();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

};

class CB1600MemoryStreamWriter : public CB1600ReferencedObject
{
  public:

    CB1600MemoryStreamWriter(void* buf, int bufSize, CB1600Bool isString);

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class CB1600StreamBase
{
  public:
    CB1600StreamBase(void* writer);
    virtual void unk00();

    int unk04;
    CB1600MemoryStreamWriter* m_pStreamWriter;
};

class FUN_00cb1600 : public CB1600StreamBase
{
  public:
    FUN_00cb1600(void* buf, int bufSize);
    virtual void unk00();
};

// Constructs a CB1600MemoryStreamWriter in place at the end of the buffer and stores it as the stream's writer, then removes its reference.
// @fnv 0x00cb1600
FUN_00cb1600::FUN_00cb1600(void* apBuffer, int aiBufferSize) : CB1600StreamBase(0)
{
    CB1600MemoryStreamWriter* writer =
        new (static_cast<char*>(apBuffer) + aiBufferSize - sizeof(CB1600MemoryStreamWriter))
            CB1600MemoryStreamWriter(apBuffer, aiBufferSize - sizeof(CB1600MemoryStreamWriter), true);
    m_pStreamWriter = writer;
    reinterpret_cast<::FUN_00c903a0_class *>((writer))->FUN_00c903a0();
}

struct S_00cb17b0_Allocator
{
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct S_00cb17b0_Router
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    S_00cb17b0_Allocator* m_pStreamAllocator;
    S_00cb17b0_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
struct S_00cb17b0_RefObj
{
    virtual ~S_00cb17b0_RefObj();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void operator delete(void* p)
    {
        S_00cb17b0_RefObj* b = static_cast<S_00cb17b0_RefObj*>(p);
        static_cast<S_00cb17b0_Router*>(::FUN_00c85750())->heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};
struct FUN_00cb17b0 : S_00cb17b0_RefObj
{
    FUN_00cb17b0();
    virtual ~FUN_00cb17b0();
};
// @fnv 0x00cb17b0
FUN_00cb17b0::FUN_00cb17b0()
{}

#include "generated/data/havok/common/base/system/error/hkerror.inc"
