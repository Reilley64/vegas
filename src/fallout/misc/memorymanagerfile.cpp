
// src/fallout/misc/memorymanagerfile.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/memorymanagerfile.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


#include "fnv/decl/FUN_008526d0_shell.h"
#include "fnv/decl/FUN_00856350_shell.h"
#include "fnv/decl/FUN_008799f0_shell.h"
#include "fnv/decl/S_008785e0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_01083000.h"
struct FUN_00878430_shell
{
    int* m_ptr;
    void FUN_00878430();
};

// @fnv 0x00878430
void FUN_00878430_shell::FUN_00878430()
{
    m_ptr = &(*reinterpret_cast<int *>(&::fnv_008784b0::DAT_01083b00));
}

namespace fnv_008784b0 {

struct FUN_008784b0
{
    void* m_p;
    FUN_008784b0();
};

// @fnv 0x008784b0
FUN_008784b0::FUN_008784b0()
{
    m_p = &DAT_01083b00;
}
}  // namespace fnv_008784b0

struct SeenData_S
{
};

struct FUN_008799c0_shell
{
    SeenData_S mSeenData;  // +0x00
    bool __thiscall IsValueSeen(void* arg1, unsigned int arg2);
};

// Computes an offset from arg1 and arg2 and forwards it to mSeenData.IsBitSet, returning its result.
// @fnv 0x008799c0
bool FUN_008799c0_shell::IsValueSeen(void* pBase, unsigned int uiIndex)
{
    unsigned int nValue = (uiIndex << 4) + (unsigned int)pBase;
    return reinterpret_cast<::FUN_008799f0_shell *>(&(mSeenData))->IsBitSet(nValue);
}


struct FUN_00878450_shell : FUN_00878430_shell
{
    void* __thiscall FUN_00878450(unsigned int flags);
};

// @fnv 0x00878450
void* __thiscall FUN_00878450_shell::FUN_00878450(unsigned int flags)
{
    FUN_00878430();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00878480_shell : FUN_00878450_shell
{
    void* __thiscall FUN_00878480(unsigned int flags);
    void __thiscall FUN_008784d0();
};
struct FileSizeInfo
{
public:
    unsigned int FUN_0065c290(::_LARGE_INTEGER &);
};
struct MemoryManagerFile
{
    int _pad;
    FileSizeInfo mFile;
    int __thiscall Read(void* apData, unsigned int aSize);
};
// Reads aSize bytes from mFile into apData and returns the number of bytes read.
// @fnv 0x00878530
int __thiscall MemoryManagerFile::Read(void* apData, unsigned int aSize)
{
    unsigned __int64 uiBytesRead;
    reinterpret_cast<::FUN_008526d0_shell *>(&(mFile))->SetFromCall((int)(apData), aSize, (int)(&uiBytesRead), {});
    return (int)uiBytesRead;
}

namespace fnv_00878560 {
typedef unsigned __int64 uint64;
struct FileInner
{
};
struct MemoryManagerFile
{
    int _0;
    FileInner _4;
    int __thiscall Write(const void* apData, unsigned int aSize);
};
// Writes aSize bytes from apData through the inner file object and returns the number of bytes written.
// @fnv 0x00878560
int MemoryManagerFile::Write(const void* apData, unsigned int aSize)
{
    uint64 uiwritten;
    reinterpret_cast<::FUN_00856350_shell *>(&(_4))->SetAndReturnPointer((void *)(apData), (void *)(aSize), &uiwritten, {});
    return (int)uiwritten;
}
}  // namespace fnv_00878560

namespace fnv_00878590 {
struct FileSizeInfo
{
};
struct FUN_00878590_shell : FileSizeInfo
{
    int __thiscall FUN_00878590();
};
// @fnv 0x00878590
int __thiscall FUN_00878590_shell::FUN_00878590()
{
    unsigned __int64 size;
    reinterpret_cast<::FileSizeInfo *>((((FileSizeInfo*)((char*)this + 4))))->FUN_0065c290((::_LARGE_INTEGER &)(size));
    return (int)size;
}
}  // namespace fnv_00878590

namespace fnv_008785b0 {
typedef unsigned __int64 uint64;
struct FUN_008785e0_holder
{
};
struct MemoryManagerFile
{
    void __thiscall FUN_008785b0(int aiPos);
};
// @fnv 0x008785b0
void __thiscall MemoryManagerFile::FUN_008785b0(int aiPos)
{
    uint64 uipos;
    reinterpret_cast<::S_008785e0 *>((reinterpret_cast<FUN_008785e0_holder*>(reinterpret_cast<char*>(this) + 4)))->SetAndGetField0(aiPos, 0, (int)(&uipos), {});
}
}  // namespace fnv_008785b0

class FUN_00b00950
{
  public:
    ~FUN_00b00950();

    int unk00;
};

class FUN_00878430
{
  public:
    virtual ~FUN_00878430();
};

class FUN_008784d0 : public FUN_00878430
{
  public:
    FUN_00b00950 m_04;

    virtual ~FUN_008784d0();
};
// Calls FUN_008784d0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00878480
void* __thiscall FUN_00878480_shell::FUN_00878480(unsigned int flags)
{
    reinterpret_cast<::FUN_008784d0 *>(this)->FUN_008784d0::~FUN_008784d0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x008784d0
FUN_008784d0::~FUN_008784d0()
{}
