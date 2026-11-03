
// src/havok/common/base/system/io/reader/stdio/hkstdiostreamreader.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/reader/stdio/hkstdiostreamreader.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstdio>
#include "fnv/symbols_0102e000.h"
#include "fnv/symbols_010cc000.h"

struct FUN_00d2bcd0_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    char m_10;
    void ReadOrMarkFailed(void* buffer, unsigned int count);
};

// Reads count bytes from the stream at m_0c into buffer; if fread returns no bytes, sets m_10 to 0.
// @fnv 0x00d2bcd0
void FUN_00d2bcd0_class::ReadOrMarkFailed(void* buffer, unsigned int count)
{
    if ((int)std::fread(buffer, 1, count, (std::FILE *)(m_0c)) > 0)
        return;
    m_10 = 0;
}

extern int DAT_010ce6c0;

struct FUN_00d2bda0_cls
{
    void DestroyFileHandle();
};

// Resets the vtable pointers and closes the stored file handle if present.
// @fnv 0x00d2bda0
void FUN_00d2bda0_cls::DestroyFileHandle()
{
    intptr_t file = *(int*)((char*)this + 0xc);
    *(int*)this = (intptr_t)&DAT_010ce6c0;
    if (file)
        std::fclose((std::FILE *)(file));
    *(int*)this = (intptr_t)&(*reinterpret_cast<int *>(&::DAT_0102e388));
}

struct FUN_00d2bd50_cls
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    long FUN_00d2bd50();
};
// @fnv 0x00d2bd50
long FUN_00d2bd50_cls::FUN_00d2bd50()
{
    return std::ftell((std::FILE *)(m_0c));
}

// @fnv 0x00d2bd10
void FUN_00d2bd10(unsigned char* output)
{
    *output = 1;
}

// @fnv 0x00d2bd20
void FUN_00d2bd20(char* a1)
{
    *a1 = 1;
}

struct FileObject
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* stream;
    int unk10;
    bool Seek(long offset, int origin);
};
// @fnv 0x00d2bd30
bool FileObject::Seek(long lOffset, int origin)
{
    return std::fseek((std::FILE *)(stream), lOffset, origin) != 0;
}

struct ReaderWithPosition
{
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual int GetPosition() = 0;
    int unk04;
    int position;
    int SetPositionFromReader(int unused);
};
// @fnv 0x00d2bdd0
int ReaderWithPosition::SetPositionFromReader(int unused)
{
    int value = GetPosition();
    int failed = value == -1;
    position = value;
    return failed;
}

struct DispatchObject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void invoke(void* value, int flag);
};
struct Owner : DispatchObject
{
    int unk04;
    void* unk08;
    void FUN_00d2bdf0();
};
// @fnv 0x00d2bdf0
void Owner::FUN_00d2bdf0()
{
    invoke(unk08, 0);
}

struct Prefix
{
    intptr_t vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ~Prefix();
};

struct FUN_00cb0a70_Class
{
    void FUN_00cb0a70(int);
};
struct FUN_00d2c7e0_class : Prefix
{
    FUN_00cb0a70_Class sub;
    FUN_00d2c7e0_class(int value);
};
// Sets the vtable pointer and forwards value to the sub-object's FUN_00cb0a70.
// @fnv 0x00d2c7e0
FUN_00d2c7e0_class::FUN_00d2c7e0_class(int value)
{
    vtable = (intptr_t)&DAT_010cc2fc;
    sub.FUN_00cb0a70(value);
}

struct FUN_00d2bd00_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char unk10;
    void FUN_00d2bd00(unsigned char* out);
};

// @fnv 0x00d2bd00
void FUN_00d2bd00_cls::FUN_00d2bd00(unsigned char* volatile out)
{
    unsigned char value = unk10;
    *out = value;
}

extern "C" void _ReadWriteBarrier(void);
extern int DAT_010ce6c0;
extern const char kModeReadBinary[];

struct StdioStreamReader
{
    intptr_t m_vptr;
    unsigned short unk04;
    unsigned short refCount;
    int lastSeek;
    void* handle;
    unsigned char IsStreamValid;
    StdioStreamReader* OpenFile(const char* fname);
};

// Initialises the stream object and opens fname in binary read mode, storing the handle and setting the flag to whether opening succeeded.
// @fnv 0x00d2bd60
StdioStreamReader* StdioStreamReader::OpenFile(const char* fname)
{
    refCount = 1;
    lastSeek = -1;
    m_vptr = (intptr_t)&DAT_010ce6c0;
    *(volatile unsigned char*)&IsStreamValid = 1;
    handle = std::fopen(fname, kModeReadBinary);
    IsStreamValid = handle != 0;
    return this;
}

struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    CpuObject* FUN_00d2be00(unsigned int flags);
};
// @fnv 0x00d2be00
CpuObject* CpuObject::FUN_00d2be00(unsigned int flags)
{
    reinterpret_cast<::FUN_00d2bda0_cls *>(this)->DestroyFileHandle();
    if (flags & 1)
    {
        CpuAllocatorHolder* holder = static_cast<CpuAllocatorHolder*>(::FUN_00c85750());
        holder->allocator->Invoke(this, size);
    }
    return this;
}
