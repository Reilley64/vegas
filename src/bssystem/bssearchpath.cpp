#include <cstddef>

// src/bssystem/bssearchpath.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bssystem/bssearchpath.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "runtime/crt.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00b01c20.h"
#include "fnv/decl/fnv_00aa24f0__FUN_00aa24f0_cls.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/decl/MemoryManagerStandIn.h"
struct BSSearchPath
{
    bool FUN_00b013e0(char* apFile);
};

// @fnv 0x00b013e0
bool BSSearchPath::FUN_00b013e0(char* apFile)
{
    return true;
}

namespace fnv_00b01480 {
struct MemoryManager
{
};


struct BSSearchPath
{
    void* FUN_00b01480(unsigned int flags);
};

// Calls FUN_00aa24f0, then deallocates this via g_memoryManager._DeallocateAlias when flags has bit 1 set, and returns this.
// @fnv 0x00b01480
void* BSSearchPath::FUN_00b01480(unsigned int flags)
{
    reinterpret_cast<::fnv_00aa24f0::FUN_00aa24f0_cls *>((this))->FUN_00aa24f0();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00b01480::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00b01480

struct FUN_00b01c40_shell
{
    void SetByteAt45(unsigned char u8);
};

// @fnv 0x00b01c40
void FUN_00b01c40_shell::SetByteAt45(unsigned char u8)
{
    *reinterpret_cast<unsigned char*>(this + 0x45) = u8;
}

struct FUN_00b01c70_shell
{
    int FUN_00b01c70(int a, int b);
};

// @fnv 0x00b01c70
int FUN_00b01c70_shell::FUN_00b01c70(int a, int b)
{
    return 0;
}

struct FUN_00b01c80_shell
{
    void FUN_00b01c80(int a1);
};

// @fnv 0x00b01c80
void FUN_00b01c80_shell::FUN_00b01c80(int a1)
{}

struct BSWin32FileCache
{
    int FUN_00b01c90(int arg);
};

// @fnv 0x00b01c90
int BSWin32FileCache::FUN_00b01c90(int arg)
{
    return 0;
}

struct FUN_00b01ca0_shell
{
    void FUN_00b01ca0(int a, int b);
};

// @fnv 0x00b01ca0
void FUN_00b01ca0_shell::FUN_00b01ca0(int a, int b)
{}

struct FUN_00b01cb0_shell
{
    bool FUN_00b01cb0(int arg1);
};

// @fnv 0x00b01cb0
bool FUN_00b01cb0_shell::FUN_00b01cb0(int arg1)
{
    return false;
}

struct FUN_00b01cc0_shell
{
    void FUN_00b01cc0(int);
};

// @fnv 0x00b01cc0
void FUN_00b01cc0_shell::FUN_00b01cc0(int)
{}

struct FUN_00b01cd0_shell
{
    void FUN_00b01cd0();
};

// @fnv 0x00b01cd0
void FUN_00b01cd0_shell::FUN_00b01cd0()
{}

struct FUN_00b01ce0_shell
{
    void FUN_00b01ce0(int);
};

// @fnv 0x00b01ce0
void FUN_00b01ce0_shell::FUN_00b01ce0(int)
{}

struct FUN_00b01cf0_shell
{
    void FUN_00b01cf0(float a, float b, float c, float d);
};

// @fnv 0x00b01cf0
void FUN_00b01cf0_shell::FUN_00b01cf0(float a, float b, float c, float d)
{}

struct FUN_00b01d10_shell
{
    bool FUN_00b01d10(int a);
};

// @fnv 0x00b01d10
bool FUN_00b01d10_shell::FUN_00b01d10(int a)
{
    return 0;
}

struct FUN_00b01c60_shell
{
    void FUN_00b01c60();
};
// @fnv 0x00b01c60
void FUN_00b01c60_shell::FUN_00b01c60()
{}

struct FUN_00b01d00_shell
{
    void FUN_00b01d00();
};

// @fnv 0x00b01d00
void FUN_00b01d00_shell::FUN_00b01d00()
{}

struct S_00b01d20_MemoryManager
{
};
struct S_00b01d20_FileCache
{
    virtual ~S_00b01d20_FileCache();
    S_00b01d20_FileCache* DestroyFileCache(unsigned int uiFlags);
};
// Destructs the object and, when bit 0 of uiFlags is set, deallocates it through g_00b01d20_MemoryManager, returning this.
// @fnv 0x00b01d20
S_00b01d20_FileCache* S_00b01d20_FileCache::DestroyFileCache(unsigned int uiFlags)
{
    reinterpret_cast<::FUN_00b01c20 *>((this))->FUN_00b01c20::~FUN_00b01c20();
    if (uiFlags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::S_00b01d20_MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

struct FUN_00b01390_cls
{
    int unk00;
    int m_uiItemCount;
    char m_path[0x104];

    bool CopyPathOnce(char* out, int unused);
};


// @fnv 0x00b01390
bool FUN_00b01390_cls::CopyPathOnce(char* out, int unused)
{
    switch (m_uiItemCount)
    {
    case 0:
        fnv::crt::strcpy_s(out, 0x104, m_path);
        m_uiItemCount = m_uiItemCount + 1;
        return true;
    }
    return false;
}

int __cdecl FUN_00ec65a6(char* dst, unsigned int size, const char* src);

struct MemMgrSP
{
};

struct NiSearchPathSP
{
    NiSearchPathSP();
    virtual ~NiSearchPathSP();
    int m_004, m_008, m_00c, m_010, m_014, m_018, m_01c, m_020;
    int m_024, m_028, m_02c, m_030, m_034, m_038, m_03c, m_040;
    int m_044, m_048, m_04c, m_050, m_054, m_058, m_05c, m_060;
    int m_064, m_068, m_06c, m_070, m_074, m_078, m_07c, m_080;
    int m_084, m_088, m_08c, m_090, m_094, m_098, m_09c, m_0a0;
    int m_0a4, m_0a8, m_0ac, m_0b0, m_0b4, m_0b8, m_0bc, m_0c0;
    int m_0c4, m_0c8, m_0cc, m_0d0, m_0d4, m_0d8, m_0dc, m_0e0;
    int m_0e4, m_0e8, m_0ec, m_0f0, m_0f4, m_0f8, m_0fc, m_100;
    int m_104, m_108, m_10c;
};

struct BSSearchPathSP : NiSearchPathSP
{
    virtual ~BSSearchPathSP();
    int m_110, m_114, m_118, m_11c, m_120, m_124, m_128, m_12c;
    int m_130, m_134, m_138, m_13c, m_140, m_144, m_148, m_14c;
    int m_150, m_154, m_158, m_15c, m_160, m_164, m_168, m_16c;
    int m_170, m_174, m_178, m_17c, m_180, m_184, m_188, m_18c;
    int m_190, m_194, m_198, m_19c, m_1a0, m_1a4, m_1a8, m_1ac;
    int m_1b0, m_1b4, m_1b8, m_1bc, m_1c0, m_1c4, m_1c8, m_1cc;
    int m_1d0, m_1d4, m_1d8, m_1dc, m_1e0, m_1e4, m_1e8, m_1ec;
    int m_1f0, m_1f4, m_1f8, m_1fc, m_200, m_204, m_208, m_20c;
    static void* operator new(std::size_t uiSize)
    {
        return reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::MemMgrSP *>(&::g_memoryManager))))->FUN_00aa3e40(uiSize);
    }
};

// @fnv 0x00b013f0
void* FUN_00b013f0()
{
    return new BSSearchPathSP;
}
