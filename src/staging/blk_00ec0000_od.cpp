
// src/staging/blk_00ec0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <windows.h>
#include <cstdint>
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiRenderer.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_00aa2000.h"
#include "fnv/symbols_00ebf000.h"
#include "fnv/symbols_00ec0000.h"
#include "fnv/symbols_00ec1000.h"
#include "fnv/symbols_010f1000.h"
#include "fnv/symbols_011ad000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_011f9000.h"
#include "fnv/symbols_01202000.h"
#include "fnv/symbols_0126f000.h"
#include "../../include/layout_support.h"

struct BGSMoviePlayer
{
};
// @fnv 0x00ec16b0
int FUN_00ec16b0(int a)
{
    reinterpret_cast<::MoviePlayerA *>((::DAT_0126fac4))->FUN_00ec2760((const char *)(a));
    return 0;
}

struct P03MM
{
};
struct FUN_00ec1a40_Class
{
    void* FUN_00ec1a40();
};
// @fnv 0x00ec1a40
void* FUN_00ec1a40_Class::FUN_00ec1a40()
{
    void* result = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(0xc);
    return result;
}


struct FUN_00ec1c90_class
{
    int AreStringsEqualIgnoreCase(const char* a, const char* b);
};

// Returns nonzero when the two strings compare equal ignoring case, via _NiStricmp.
// @fnv 0x00ec1c90
int FUN_00ec1c90_class::AreStringsEqualIgnoreCase(const char* pcStringA, const char* pcStringB)
{
    return !::NiStricmp(pcStringA, pcStringB);
}


struct FUN_00ec1dc0_Class
{
    int IsStringEqualIgnoreCase(const char* a, const char* b);
};

// Returns nonzero when the two strings are equal ignoring case, using __stricmp.
// @fnv 0x00ec1dc0
int FUN_00ec1dc0_Class::IsStringEqualIgnoreCase(const char* pcStringA, const char* pcStringB)
{
    return !fnv::crt::stricmp(pcStringA, pcStringB);
}

struct FUN_00ec1f20Class
{
    void* FUN_00ec1f20();
};

// @fnv 0x00ec1f20
void* FUN_00ec1f20Class::FUN_00ec1f20()
{
    ::FUN_00ec1570((::FUN_00ec1570_t *)this);
    return this;
}

struct FUN_00ec1f40Class
{
    void FUN_00ec1f40();
};

namespace fnv_00ec20a0 {
struct MemoryManager
{
};
// @fnv 0x00ec20a0
void FUN_00ec20a0(void* apMemory)
{
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ec20a0::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(apMemory);
}
}  // namespace fnv_00ec20a0

struct FUN_00ec29b0_class
{
    void FUN_00ec29b0();
};
// @fnv 0x00ec29b0
void FUN_00ec29b0_class::FUN_00ec29b0()
{
    ((char*)this)[0x21] = 1;
}

struct FUN_00ec2c10
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    void SetThreadPriorityLevel(int);
    void FUN_00ec2c10_init();
};
// If m_002c is below 5, calls SetThreadPriorityLevel with m_002c + 1.
// @fnv 0x00ec2c10
void FUN_00ec2c10::FUN_00ec2c10_init()
{
    if (m_002c < 5)
        SetThreadPriorityLevel(m_002c + 1);
}

struct FUN_00ec1570_t
{
    int a;
    int b;
    int c;
    int d;
    int e;
    float f;
    float g;
    float h;
    int i;
    bool j;
};
// Resets all fields of the structure: integer fields to 0, f to 1.0, g and h to 0.0, and j to false.
// @fnv 0x00ec1570
void FUN_00ec1570(FUN_00ec1570_t* p)
{
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
    p->e = 0;
    p->f = 1.0f;
    p->g = 0.0f;
    p->h = 0.0f;
    p->i = 0;
    p->j = false;
}

struct MemoryManager
{
    void Deallocate(void*);
};
struct FUN_00ec15e0_shell
{
};
struct FUN_00ec19d0_class
{
    void* FUN_00ec19d0(unsigned int flags);
};
// @fnv 0x00ec19d0
void* FUN_00ec19d0_class::FUN_00ec19d0(unsigned int flags)
{
    reinterpret_cast<::fnv_00ec15e0::BSMoviePlayer *>((((FUN_00ec15e0_shell*)this)))->fnv_00ec15e0::BSMoviePlayer::~BSMoviePlayer();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

struct FUN_00ec0cd0_Class
{
};
struct FUN_00ec1f60_Class
{
    int m_0020;
    unsigned char m_0024;
    unsigned char InitAndCheck(int a, unsigned char b);
};
struct FUN_00ec1fb0_class
{
    void DisableThreadPriorityBoost();
};
struct FUN_00ec2a10_class
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    void PauseMovie();
};
// If a movie is set, warns when another is already paused, calls DisableThreadPriorityBoost on it, stores it as the paused movie and clears the active movie pointer.
// @fnv 0x00ec2a10
void FUN_00ec2a10_class::PauseMovie()
{
    if (!m_000c)
        return;
    if (m_0010)
        ::FUN_005b5e40(
            );
    ((FUN_00ec1fb0_class*)m_000c)->DisableThreadPriorityBoost();
    m_0010 = m_000c;
    m_000c = 0;
}

struct FUN_00ec2d40_class
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    void SetValueAndReset(int a);
};
// Stores a into m_0014, clears m_0004, calls the callback at m_001c, then clears m_001c.
// @fnv 0x00ec2d40
void FUN_00ec2d40_class::SetValueAndReset(int aiValue)
{
    m_0014 = aiValue;
    m_0004 = 0;
    ((void(*)(void))this->m_001c)();
    m_001c = 0;
}

struct FUN_00ec2aa0_Class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual unsigned int v10();
    virtual unsigned int v11();
    float ComputeRatio(unsigned int a, unsigned int b, bool c);
};
// Returns v10() divided by a when c is true, otherwise v11() divided by b, as a float.
// @fnv 0x00ec2aa0
float FUN_00ec2aa0_Class::ComputeRatio(unsigned int auiDivisorA, unsigned int auiDivisorB, bool abUseFirst)
{
    if (abUseFirst)
        return (float)v10() / auiDivisorA;
    else
        return (float)v11() / auiDivisorB;
}


// Maps a level 0-5 to a thread priority, stores the level in m_002c and applies the priority to the thread handle at offset 8.
// @fnv 0x00ec18a0
void FUN_00ec2c10::SetThreadPriorityLevel(int aiLevel)
{
    int b;
    switch (aiLevel)
    {
    case 0:
        b = -2;
        break;
    case 1:
        b = -1;
        break;
    case 2:
        b = 0;
        break;
    case 3:
        b = 1;
        break;
    case 4:
        b = 2;
        break;
    case 5:
        b = 15;
        break;
    default:
        b = 0;
        break;
    }
    m_002c = aiLevel;
    SetThreadPriority(*(void**)((char*)this + 8), b);
}

struct FUN_00ec1fd0_shell
{
    void UnpauseBink();
};
struct FUN_00ec2a60_class
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    void FUN_00ec2a60();
};
// If m_000c is clear and m_0010 is set, moves m_0010 into m_000c, clears m_0010 and calls UnpauseBink on it.
// @fnv 0x00ec2a60
void FUN_00ec2a60_class::FUN_00ec2a60()
{
    if (m_000c)
        return;
    if (m_0010)
    {
        m_000c = m_0010;
        m_0010 = 0;
        ((FUN_00ec1fd0_shell*)m_000c)->UnpauseBink();
    }
}

struct FUN_00ec2bb0_Class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual unsigned int v10();
    virtual unsigned int v11();
    float FUN_00ec2bb0(float, unsigned int, bool);
};

// If c is set, returns half of the difference between v11() and b times a; otherwise returns 0.0f.
// @fnv 0x00ec2bb0
float FUN_00ec2bb0_Class::FUN_00ec2bb0(float afValue, unsigned int b, bool abEnabled)
{
    if (!abEnabled)
        return 0.0f;
    return (v11() - b * afValue) / 2.0;
}


struct FUN_00ec17c0_Class
{
    int m_0000;
    int m_0004;
    void* m_0008;
    bool FUN_00ec17c0();
};

// Returns true when m_0008 is set and GetExitCodeThread reports exit code 0x103 for it.
// @fnv 0x00ec17c0
bool FUN_00ec17c0_Class::FUN_00ec17c0()
{
    if (!m_0008)
        return false;
    unsigned long iexitCode;
    GetExitCodeThread(m_0008, &iexitCode);
    return iexitCode == 0x103;
}

struct FUN_00ec19a0_Class
{
    int m_0000;
    void* m_0004;
    void FUN_00ec19a0();
};


// If m_0004 is non-null, calls FUN_00fdf1c8 with m_0004 and -1.
// @fnv 0x00ec19a0
void FUN_00ec19a0_Class::FUN_00ec19a0()
{
    if (m_0004)
        WaitForSingleObject(m_0004, -1);
}

struct FUN_00ec1a60_t
{
    int a;
    int b;
    int c;
};
struct FUN_00ec1a60_class
{
    void FreeStruct(FUN_00ec1a60_t* p);
};
// Clears the third field of the struct, then deallocates it through g_memoryManager.
// @fnv 0x00ec1a60
void FUN_00ec1a60_class::FreeStruct(FUN_00ec1a60_t* pStruct)
{
    pStruct->c = 0;
    FUN_00ec1a60_t* q = pStruct;
    reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(q);
}

extern int DAT_010f1ca4;
struct FUN_00ec1b80_Map
{
    void RemoveAll();
};
struct FUN_00ec1b80_Class
{
    int m_0000;
    int m_0004;
    int m_0008;
    void Initialize();
};
// @fnv 0x00ec1b80
void FUN_00ec1b80_Class::Initialize()
{
    int pad1;
    int pad2;
    m_0000 = (int)&DAT_010f1ca4;
    reinterpret_cast<::FUN_00438af0_Class *>((((FUN_00ec1b80_Map*)this)))->FUN_00438af0();
    ::FUN_00aa10f0((void*)m_0008);
}


struct FUN_00ec1cc0_Class
{
    void AssignString(void* a, const char* b, int c);
};

// Stores a string into a+4 (copying it when this+0x10 is set) and stores c into a+8.
// @fnv 0x00ec1cc0
void FUN_00ec1cc0_Class::AssignString(void* apTarget, const char* apString, int aiValue)
{
    if (*(unsigned char*)((char*)this + 0x10))
    {
        unsigned int uiLen = std::strlen(apString) + 1;
        *(void**)((char*)apTarget + 4) = ::FUN_00aa1070(uiLen);
        void* dest = *(void**)((char*)apTarget + 4);
        fnv::crt::strcpy_s((char*)dest, uiLen, apString);
    }
    else
    {
        *(void**)((char*)apTarget + 4) = (void*)apString;
    }
    *(int*)((char*)apTarget + 8) = aiValue;
}

struct FUN_00ec1a90_Class
{
    int m_ppVirtualMethodTable;
};
struct FUN_00ec1d30_Class : FUN_00ec1a90_Class
{
    void FUN_00ec1d30();
};
// @fnv 0x00ec1d30
void FUN_00ec1d30_Class::FUN_00ec1d30()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    m_ppVirtualMethodTable = (int)&DAT_010f1c20;
    reinterpret_cast<::NiTStringMapCopy *>(this)->NiTStringMapCopy::~NiTStringMapCopy();
}

struct FUN_00ec0460_cls
{
    virtual void v00(void);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(void);
    virtual void v04(void);
    virtual void v05(void);
    virtual void v06(void);
    virtual void v07(void);
    virtual void v08(void);
    virtual void v09(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void v24(void);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void v28(void);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void v39(void);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
    virtual void v47(void);
    virtual void v48(void);
    virtual void v49(void);
    virtual void v50(void);
    virtual void v51(void);
    virtual void v52(void);
    virtual void v53(void);
    virtual void v54(void);
    virtual void v55(void);
    virtual void v56(void);
    virtual void v57(int a, int b);
    virtual void v58(void);
    virtual void v59(void);
    virtual void v60(void);
    virtual void v61(void);
    virtual void v62(void);
    virtual void v63(void);
    virtual void v64(void);
    virtual void v65(void);
    virtual void v66(void);
    virtual void v67(int a, int b, int c);
    virtual void v68(void);
    virtual void v69(int a, int b, int c);
};

// @fnv 0x00ec0460
void __cdecl FUN_00ec0460(FUN_00ec0460_cls* p)
{
    p->v57(0x1b, 0);
    p->v67(0, 4, 2);
    p->v67(0, 2, 2);
    p->v67(0, 5, 2);
    p->v67(0, 1, 4);
    p->v69(0, 6, 2);
    p->v69(0, 5, 2);
    p->v69(0, 7, 2);
    p->v69(0, 1, 3);
    p->v69(0, 2, 3);
}

struct GridDesc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int cols;
    unsigned int rows;
    unsigned int extraX;
    unsigned int extraY;
    int unk34;
    int unk38;
    unsigned int cellSize;
};


// @fnv 0x00ec0550
void __cdecl FUN_00ec0550(GridDesc* grid, float startX, float startY, float scaleX, float scaleY)
{
    float x;
    unsigned int row;
    unsigned int col_2;
    float stepY;
    float y_;
    float stepX4;

    stepX4 = (float)grid->cellSize * scaleX;
    stepY = (float)grid->cellSize * scaleY;
    y_ = startY;
    for (row = 0; row < grid->rows; row++)
    {
        x = startX;
        for (col_2 = 0; col_2 < grid->cols; col_2++)
        {
            ::FUN_00ec0720((::FUN_00ec0720_Device *)(grid->unk00), x, y_, scaleX, scaleY, grid->cellSize, grid->cellSize);
            x += stepX4;
        }
        if (grid->extraX)
        {
            ::FUN_00ec0720((::FUN_00ec0720_Device *)(grid->unk00), x, y_, scaleX, scaleY, grid->extraX, grid->cellSize);
        }
        y_ += stepY;
    }
    if (grid->extraY)
    {
        x = startX;
        for (col_2 = 0; col_2 < grid->cols; col_2++)
        {
            ::FUN_00ec0720((::FUN_00ec0720_Device *)(grid->unk00), x, y_, scaleX, scaleY, grid->cellSize, grid->extraY);
            x += stepX4;
        }
        if (grid->extraX)
        {
            ::FUN_00ec0720((::FUN_00ec0720_Device *)(grid->unk00), x, y_, scaleX, scaleY, grid->extraX, grid->extraY);
        }
    }
}

struct NiPlaybackFrameSize
{
    unsigned int uiWidth;
    unsigned int uiHeight;
};

class NiPlaybackManager
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual int GetRenderer();
};


class NiPlaybackFile
{
  public:
    NiPlaybackFrameSize* m_pkSize;
    int m_iRenderer;
    void* m_pkTextures;
    int m_unk0C;
    int m_unk10;
    float m_fTextureScale;
    float m_fWidthScale;
    float m_fHeightScale;
    int m_iFadeIndex;

    bool FindString(const char* pcName, bool bQuiet, bool bLoop, bool bFlag);
    bool InitPlayback(const char* pcName, bool bQuiet, bool bLoop, bool bLooping);
};
// @fnv 0x00ec1f60
unsigned char FUN_00ec1f60_Class::InitAndCheck(int aiValue, unsigned char b)
{
    *(int*)((char*)this + 0x20) = 2;
    *(unsigned char*)((char*)this + 0x24) = 1;
    if (!((unsigned char)(reinterpret_cast<::NiPlaybackFile *>((((FUN_00ec0cd0_Class*)this)))->InitPlayback((const char *)(aiValue), 1, b, 0))))
    {
        *(unsigned char*)((char*)this + 0x24) = 0;
        return 0;
    }
    *(unsigned char*)((char*)this + 0x24) = 0;
    return 1;
}

extern "C" __declspec(dllimport) void BinkClose(int handle);

struct FUN_00ec1020_cls
{
    int m_00;
    int m_04;
    int m_08;
    void FUN_00ec1020();
};
// @fnv 0x00ec1f40
void FUN_00ec1f40Class::FUN_00ec1f40()
{
    reinterpret_cast<::FUN_00ec1020_cls *>(this)->FUN_00ec1020();
}

// @fnv 0x00ec1020
void FUN_00ec1020_cls::FUN_00ec1020()
{
    if (m_00 != 0)
    {
        BinkClose(m_00);
    }
    if (m_08 != 0)
    {
        ::ReleaseInterfaceArray((::Struct_00ebfd20 *)(m_08));
    }
    FUN_00ec1570((FUN_00ec1570_t*)this);
}

struct FUN_00ec14d0_bink
{
    void* m_00;
    unsigned int m_04;
};


extern "C" __declspec(dllimport) int BinkDoFrame(void* hBink);
extern "C" __declspec(dllimport) int BinkCopyToBufferRect(void* hBink, void* dest, int destPitch,
                                                                    unsigned int destHeight, unsigned int destX,
                                                                    unsigned int destY, unsigned int srcX,
                                                                    unsigned int srcY, unsigned int srcWidth,
                                                                    unsigned int srcHeight, unsigned int flags);

// @fnv 0x00ec14d0
unsigned char __cdecl DecodeBinkFrame(FUN_00ec14d0_bink* a1, unsigned int a2, int a3)
{
    int result2 = 1;
    int v1;
    int v2;
    int v3;
    int v8;
    int vB;
    int v7;

    BinkDoFrame(a1);
    while (::LockNextTile((::TiledTexture *)(a2), (void **)(int *)(&v7), &vB, (unsigned int *)(int *)(&v8), (unsigned int *)(int *)(&v3), (unsigned int *)(int *)(&v2), (unsigned int *)(int *)(&v1)) != 0)
    {
        result2 = BinkCopyToBufferRect(a1, (void*)v7, vB, a1->m_04, 0, 0, v8, v3, v2, v1,
                                       ((a3 != 0 ? -1 : 0) & 0x80000000u) | 3u);
        ::ApplyLastEffect((::EffectStackEBF *)(a2));
    }
    return result2 != 0;
}

// EnableSoundSystem: enables the Bink direct-sound output path.
// The Bink library is reached through the executable's import table; the
// address of the direct-sound entry point is passed to BinkSetSoundSystem.

extern "C" __declspec(dllimport) void BinkOpenDirectSound(void* apDirectSound);
extern "C" __declspec(dllimport) void BinkSetSoundSystem(void* system, unsigned int flags);

class FUN_00ec1680_cls
{
  public:
    void EnableSoundSystem(bool bEnableSound);
};

// If bEnableSound is set, installs BinkOpenDirectSound as the Bink sound system with flags 0.
// @fnv 0x00ec1680
void FUN_00ec1680_cls::EnableSoundSystem(bool bEnableSound)
{
    if (bEnableSound)
    {
        BinkSetSoundSystem((void*)&BinkOpenDirectSound, 0);
    }
}



struct BEC16D0Setting
{
    void* m_pvVtable;
    int m_iValue;
};


struct BEC16D0Semaphore
{
    volatile long m_lCount;
    void* m_pSemaphore;
};

class BEC16D0MoviePlayerThread
{
  public:
    int unk00;
    int unk04;
    void* m_hThread;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    short unk20;
    bool m_bFlag22;
    bool m_bFlag23;
    bool m_bFlag24;
    float m_fValue28;
    int unk2C;
    BEC16D0Semaphore m_kStartSemaphore;

    void FUN_00ec16d0(void* pvParam, bool bFlag22, int iPriority, bool bFlag23, bool bFlag24, float fValue28);
};

// Creates the movie player thread, stores the flags and value, sets its priority, resumes it and waits on the start semaphore.
// @fnv 0x00ec16d0
void BEC16D0MoviePlayerThread::FUN_00ec16d0(void* pvParam, bool bFlag22, int iPriority, bool bFlag23, bool bFlag24,
                                            float fValue28)
{
    unsigned long ulThreadId3;
    m_hThread = CreateThread(0, 0, (unsigned long(*)(void*))FUN_00ec16b0, pvParam, 4, &ulThreadId3);
    ::SetDebuggerThreadName(ulThreadId3, "MoviePlayer");
    m_bFlag22 = bFlag22;
    m_bFlag23 = bFlag23;
    m_bFlag24 = bFlag24;
    m_fValue28 = fValue28;
    if (iPriority == -1)
    {
        int* piPriority = &(*reinterpret_cast<::BEC16D0Setting *>(&::g_0126fae0)) ? &(*reinterpret_cast<::BEC16D0Setting *>(&::g_0126fae0)).m_iValue
                                                    : (::DAT_01202800 = 0, &::DAT_01202800);
        reinterpret_cast<::FUN_00ec2c10 *>(this)->SetThreadPriorityLevel(*piPriority);
    }
    else
    {
        reinterpret_cast<::FUN_00ec2c10 *>(this)->SetThreadPriorityLevel(iPriority);
    }
    ResumeThread(m_hThread);
    ulThreadId3 = 0;
    {
        BEC16D0Semaphore* pkSemaphore = &m_kStartSemaphore;
        WaitForSingleObject(pkSemaphore->m_pSemaphore, 0xffffffff);
        InterlockedDecrement(&pkSemaphore->m_lCount);
    }
}

extern int DAT_010f1ca4;

struct FUN_00ec1df0_pool
{
};

struct FUN_00ec1df0_cls
{
    int m_vptr;
    int m_04;
    int m_08;


    FUN_00ec1df0_cls* FUN_00ec1df0(unsigned int acFlags);
};

// @fnv 0x00ec1df0
FUN_00ec1df0_cls* FUN_00ec1df0_cls::FUN_00ec1df0(unsigned int acFlags)
{
    int unk00;
    int unk04;
    m_vptr = (int)&DAT_010f1ca4;
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    ::FUN_00aa10f0((void *)(m_08));
    if (acFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00ec1df0_pool *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}

namespace fnv_00ec1ee0 {

class FUN_00ec1ee0_pool
{
  public:
};

struct FUN_00ec1ee0_frame
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

struct FUN_00ec1ee0_cls
{
    int m_vptr;
    int unk04;


    FUN_00ec1ee0_cls* FUN_00ec1ee0(unsigned int auiFlags);
};

// @fnv 0x00ec1ee0
FUN_00ec1ee0_cls* FUN_00ec1ee0_cls::FUN_00ec1ee0(unsigned int auiFlags)
{
    FUN_00ec1ee0_frame frame;
    m_vptr = (int)&::DAT_010f1c20;
    reinterpret_cast<::NiTStringMapCopy *>(this)->NiTStringMapCopy::~NiTStringMapCopy();
    if (auiFlags & 1)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ec1ee0::FUN_00ec1ee0_pool *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}
}  // namespace fnv_00ec1ee0

extern "C" __declspec(dllimport) int BinkPause(void* hThread, int fDisable);

// @fnv 0x00ec1fb0
void FUN_00ec1fb0_class::DisableThreadPriorityBoost()
{
    BinkPause(reinterpret_cast<void*>(reinterpret_cast<int*>(this)[0]), 1);
}


// @fnv 0x00ec1fd0
void FUN_00ec1fd0_shell::UnpauseBink()
{
    BinkPause(*(void**)this, 0);
}

namespace fnv_00ec25e0 {
struct FUN_00aa4060_Obj
{
};

struct FUN_00ec25e0_cls
{
    int m_0000;
    int m_0004;
    int m_0008;
    FUN_00ec1f40Class* m_000c;
    void FUN_00ec25e0();
};

// If m_000c is set, calls FUN_00ec1f40 and DAT_011f6238.FUN_00aa4060 on it, clears m_000c, then calls FUN_00ec2a60.
// @fnv 0x00ec25e0
void FUN_00ec25e0_cls::FUN_00ec25e0()
{
    if (m_000c != 0)
    {
        FUN_00ec1f40Class* t2 = m_000c;
        FUN_00ec1f40Class* p = t2;
        p != 0 ? (p->FUN_00ec1f40(), (((0, 1) & 1) ? reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00ec25e0::FUN_00aa4060_Obj *>(&::g_memoryManager))))->FUN_00aa4060(p) : (void)0), p) : 0;
        m_000c = 0;
    }
    reinterpret_cast<::FUN_00ec2a60_class *>(this)->FUN_00ec2a60();
}
}  // namespace fnv_00ec25e0

struct S_00ec2b20
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual unsigned int v10();
    virtual unsigned int v11();
    virtual unsigned int v12();
    virtual unsigned int v13();
    float ComputeAdjustedValue(float a, unsigned int b, bool c);
};
// Loads the playback size if needed, queries the manager for renderer, frame rate and scales, allocates textures and warns on failure.
// @fnv 0x00ec0cd0
bool NiPlaybackFile::InitPlayback(const char* pcName, bool bQuiet, bool bLoop, bool bLooping)
{
    if (m_pkSize == 0 && !FindString(pcName, bQuiet, bLoop, false))
        return false;

    m_iRenderer = ((NiPlaybackManager*)::DAT_0126fac4)->GetRenderer();
    m_fTextureScale = reinterpret_cast<::FUN_00ec2aa0_Class *>((((NiPlaybackManager*)::DAT_0126fac4)))->ComputeRatio(m_pkSize->uiWidth, m_pkSize->uiHeight, bLooping);
    m_fWidthScale = reinterpret_cast<::S_00ec2b20 *>((((NiPlaybackManager*)::DAT_0126fac4)))->ComputeAdjustedValue(m_fTextureScale, m_pkSize->uiWidth, bLooping);
    m_fHeightScale = reinterpret_cast<::FUN_00ec2bb0_Class *>((((NiPlaybackManager*)::DAT_0126fac4)))->FUN_00ec2bb0(m_fTextureScale, m_pkSize->uiHeight, bLooping);
    m_pkTextures = ((void *)(::CreateTiledTexture((void *)(m_iRenderer), m_pkSize->uiWidth, m_pkSize->uiHeight, 4, 0x100, 0x16)));
    if (m_pkTextures == 0)
    {
        if (!bQuiet)
            ::FUN_005b5e40();
        m_iFadeIndex = 0;
        return false;
    }
    return true;
}
// Returns v13() as a float when c is set, otherwise v13() plus half of (v10() minus b times a).
// @fnv 0x00ec2b20
float S_00ec2b20::ComputeAdjustedValue(float afScale, unsigned int auiValue, bool abDirect)
{
    if (abDirect)
        return (float)v13();
    return (float)((double)v13() + ((double)v10() - (double)auiValue * afScale) / 2.0);
}

extern int DAT_0126fae4;

struct FUN_00ec2c40_cls
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    void FUN_00ec2c40();
};

// If m_002c exceeds the current limit (DAT_0126fae4 or DAT_01202800), calls SetThreadPriorityLevel with m_002c - 1.
// @fnv 0x00ec2c40
void FUN_00ec2c40_cls::FUN_00ec2c40()
{
    int* q = (&(*reinterpret_cast<int *>(&::g_0126fae0)) != 0) ? &DAT_0126fae4 : (DAT_01202800 = 0, &DAT_01202800);
    if (m_002c > *q)
    {
        reinterpret_cast<::FUN_00ec2c10 *>(this)->SetThreadPriorityLevel(m_002c - 1);
    }
}

namespace fnv_00ec2d80 {
struct S_00ec2f00_Class
{
    void AddOrUpdate(int a, char* b);
};

struct S_00aa3e40_Class
{
};

struct S_00ec2d80_Class
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    int m_0024;
    int m_0028;
    int m_002c;
    int m_0030;
    int m_0034;
    int m_0038;
    int m_003c;
    S_00ec2f00_Class m_0040;

    void FUN_00ec2d80(int a, int b);
};



// @fnv 0x00ec2d80
void S_00ec2d80_Class::FUN_00ec2d80(int a, int b)
{
    char* p;
    char* oB;
    char* n;
    char* m;
    char* l;
    char* k;
    char* j;

    oB = ((char *)(std::uintptr_t)(std::strlen((const char *)(b))));
    n = ((char *)(reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::fnv_00ec2d80::S_00aa3e40_Class *>(&::g_memoryManager))))->FUN_00aa3e40((unsigned int)(oB + 1))));
    p = n;

    fnv::crt::strcpy_s(p, (std::size_t)(std::uintptr_t)(oB + 1), (const char *)(b));
    this->m_0040.AddOrUpdate(a, p);
}
}  // namespace fnv_00ec2d80

// Look up the file name registered under a key and copy it into a MAX_PATH buffer.


class EC2DF0NameMap
{
  public:
    bool GetAt(unsigned int uiKey, const char*& rpcName) const;
};

class EC2DF0Registry
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    EC2DF0NameMap m_kNames;

    bool GetNameByKey(uintptr_t uiKey, char* pcPath);
};

// Looks up uiKey in m_kNames and, if found, copies the name into pcPath with strcpy_s and returns true; otherwise returns false.
// @fnv 0x00ec2df0
bool EC2DF0Registry::GetNameByKey(uintptr_t uiKey, char* pcPath)
{
    const char* pcFile = 0;
    char* pcDest;             // declared but never used in this build
    unsigned int uiDestSize;  // declared but never used in this build
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&(m_kNames))->FUN_00853130(uiKey, (::fnv_00853130::CombatThreatRecord *&)(pcFile)))
    {
        const char* pcSource = pcFile;
        fnv::crt::strcpy_s(pcPath, 260, pcSource);
        return true;
    }
    return false;
}

struct EC0280Vertex
{
    float x;
    float y;
    float z;
    float rhw;
    float u;
    float v;
};
struct EC0280Device
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual long DrawPrimitiveUP(int eType, unsigned int ItemUpdateArray, const void* pvData, unsigned int uiStride);
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual long SetVertexDeclaration(void* pkDecl);
    virtual long GetVertexDeclaration(void** ppkDecl);
    virtual long SetFVF(unsigned int uiFVF);
};
struct EC0280RenderState
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void SetTexture(int a, int b);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void SetStage(int a, int b);
    virtual void v36();
    virtual void Commit();
};
struct EC0280Renderer
{
    int unk0000;
    int unk0004;
    int unk0008;
    int unk000C;
    int unk0010;
    int unk0014;
    int unk0018;
    int unk001C;
    int unk0020;
    int unk0024;
    int unk0028;
    int unk002C;
    int unk0030;
    int unk0034;
    int unk0038;
    int unk003C;
    int unk0040;
    int unk0044;
    int unk0048;
    int unk004C;
    int unk0050;
    int unk0054;
    int unk0058;
    int unk005C;
    int unk0060;
    int unk0064;
    int unk0068;
    int unk006C;
    int unk0070;
    int unk0074;
    int unk0078;
    int unk007C;
    int unk0080;
    int unk0084;
    int unk0088;
    int unk008C;
    int unk0090;
    int unk0094;
    int unk0098;
    int unk009C;
    int unk00A0;
    int unk00A4;
    int unk00A8;
    int unk00AC;
    int unk00B0;
    int unk00B4;
    int unk00B8;
    int unk00BC;
    int unk00C0;
    int unk00C4;
    int unk00C8;
    int unk00CC;
    int unk00D0;
    int unk00D4;
    int unk00D8;
    int unk00DC;
    int unk00E0;
    int unk00E4;
    int unk00E8;
    int unk00EC;
    int unk00F0;
    int unk00F4;
    int unk00F8;
    int unk00FC;
    int unk0100;
    int unk0104;
    int unk0108;
    int unk010C;
    int unk0110;
    int unk0114;
    int unk0118;
    int unk011C;
    int unk0120;
    int unk0124;
    int unk0128;
    int unk012C;
    int unk0130;
    int unk0134;
    int unk0138;
    int unk013C;
    int unk0140;
    int unk0144;
    int unk0148;
    int unk014C;
    int unk0150;
    int unk0154;
    int unk0158;
    int unk015C;
    int unk0160;
    int unk0164;
    int unk0168;
    int unk016C;
    int unk0170;
    int unk0174;
    int unk0178;
    int unk017C;
    int unk0180;
    int unk0184;
    int unk0188;
    int unk018C;
    int unk0190;
    int unk0194;
    int unk0198;
    int unk019C;
    int unk01A0;
    int unk01A4;
    int unk01A8;
    int unk01AC;
    int unk01B0;
    int unk01B4;
    int unk01B8;
    int unk01BC;
    int unk01C0;
    int unk01C4;
    int unk01C8;
    int unk01CC;
    int unk01D0;
    int unk01D4;
    int unk01D8;
    int unk01DC;
    int unk01E0;
    int unk01E4;
    int unk01E8;
    int unk01EC;
    int unk01F0;
    int unk01F4;
    int unk01F8;
    int unk01FC;
    int unk0200;
    int unk0204;
    int unk0208;
    int unk020C;
    int unk0210;
    int unk0214;
    int unk0218;
    int unk021C;
    int unk0220;
    int unk0224;
    int unk0228;
    int unk022C;
    int unk0230;
    int unk0234;
    int unk0238;
    int unk023C;
    int unk0240;
    int unk0244;
    int unk0248;
    int unk024C;
    int unk0250;
    int unk0254;
    int unk0258;
    int unk025C;
    int unk0260;
    int unk0264;
    int unk0268;
    int unk026C;
    int unk0270;
    int unk0274;
    int unk0278;
    int unk027C;
    int unk0280;
    int unk0284;
    int unk0288;
    int unk028C;
    int unk0290;
    int unk0294;
    int unk0298;
    int unk029C;
    int unk02A0;
    int unk02A4;
    int unk02A8;
    int unk02AC;
    int unk02B0;
    int unk02B4;
    int unk02B8;
    int unk02BC;
    int unk02C0;
    int unk02C4;
    int unk02C8;
    int unk02CC;
    int unk02D0;
    int unk02D4;
    int unk02D8;
    int unk02DC;
    int unk02E0;
    int unk02E4;
    int unk02E8;
    int unk02EC;
    int unk02F0;
    int unk02F4;
    int unk02F8;
    int unk02FC;
    int unk0300;
    int unk0304;
    int unk0308;
    int unk030C;
    int unk0310;
    int unk0314;
    int unk0318;
    int unk031C;
    int unk0320;
    int unk0324;
    int unk0328;
    int unk032C;
    int unk0330;
    int unk0334;
    int unk0338;
    int unk033C;
    int unk0340;
    int unk0344;
    int unk0348;
    int unk034C;
    int unk0350;
    int unk0354;
    int unk0358;
    int unk035C;
    int unk0360;
    int unk0364;
    int unk0368;
    int unk036C;
    int unk0370;
    int unk0374;
    int unk0378;
    int unk037C;
    int unk0380;
    int unk0384;
    int unk0388;
    int unk038C;
    int unk0390;
    int unk0394;
    int unk0398;
    int unk039C;
    int unk03A0;
    int unk03A4;
    int unk03A8;
    int unk03AC;
    int unk03B0;
    int unk03B4;
    int unk03B8;
    int unk03BC;
    int unk03C0;
    int unk03C4;
    int unk03C8;
    int unk03CC;
    int unk03D0;
    int unk03D4;
    int unk03D8;
    int unk03DC;
    int unk03E0;
    int unk03E4;
    int unk03E8;
    int unk03EC;
    int unk03F0;
    int unk03F4;
    int unk03F8;
    int unk03FC;
    int unk0400;
    int unk0404;
    int unk0408;
    int unk040C;
    int unk0410;
    int unk0414;
    int unk0418;
    int unk041C;
    int unk0420;
    int unk0424;
    int unk0428;
    int unk042C;
    int unk0430;
    int unk0434;
    int unk0438;
    int unk043C;
    int unk0440;
    int unk0444;
    int unk0448;
    int unk044C;
    int unk0450;
    int unk0454;
    int unk0458;
    int unk045C;
    int unk0460;
    int unk0464;
    int unk0468;
    int unk046C;
    int unk0470;
    int unk0474;
    int unk0478;
    int unk047C;
    int unk0480;
    int unk0484;
    int unk0488;
    int unk048C;
    int unk0490;
    int unk0494;
    int unk0498;
    int unk049C;
    int unk04A0;
    int unk04A4;
    int unk04A8;
    int unk04AC;
    int unk04B0;
    int unk04B4;
    int unk04B8;
    int unk04BC;
    int unk04C0;
    int unk04C4;
    int unk04C8;
    int unk04CC;
    int unk04D0;
    int unk04D4;
    int unk04D8;
    int unk04DC;
    int unk04E0;
    int unk04E4;
    int unk04E8;
    int unk04EC;
    int unk04F0;
    int unk04F4;
    int unk04F8;
    int unk04FC;
    int unk0500;
    int unk0504;
    int unk0508;
    int unk050C;
    int unk0510;
    int unk0514;
    int unk0518;
    int unk051C;
    int unk0520;
    int unk0524;
    int unk0528;
    int unk052C;
    int unk0530;
    int unk0534;
    int unk0538;
    int unk053C;
    int unk0540;
    int unk0544;
    int unk0548;
    int unk054C;
    int unk0550;
    int unk0554;
    int unk0558;
    int unk055C;
    int unk0560;
    int unk0564;
    int unk0568;
    int unk056C;
    int unk0570;
    int unk0574;
    int unk0578;
    int unk057C;
    int unk0580;
    int unk0584;
    int unk0588;
    int unk058C;
    int unk0590;
    int unk0594;
    int unk0598;
    int unk059C;
    int unk05A0;
    int unk05A4;
    int unk05A8;
    int unk05AC;
    int unk05B0;
    int unk05B4;
    int unk05B8;
    int unk05BC;
    int unk05C0;
    int unk05C4;
    int unk05C8;
    int unk05CC;
    int unk05D0;
    int unk05D4;
    int unk05D8;
    int unk05DC;
    int unk05E0;
    int unk05E4;
    int unk05E8;
    int unk05EC;
    int unk05F0;
    int unk05F4;
    int unk05F8;
    int unk05FC;
    int unk0600;
    int unk0604;
    int unk0608;
    int unk060C;
    int unk0610;
    int unk0614;
    int unk0618;
    int unk061C;
    int unk0620;
    int unk0624;
    int unk0628;
    int unk062C;
    int unk0630;
    int unk0634;
    int unk0638;
    int unk063C;
    int unk0640;
    int unk0644;
    int unk0648;
    int unk064C;
    int unk0650;
    int unk0654;
    int unk0658;
    int unk065C;
    int unk0660;
    int unk0664;
    int unk0668;
    int unk066C;
    int unk0670;
    int unk0674;
    int unk0678;
    int unk067C;
    int unk0680;
    int unk0684;
    int unk0688;
    int unk068C;
    int unk0690;
    int unk0694;
    int unk0698;
    int unk069C;
    int unk06A0;
    int unk06A4;
    int unk06A8;
    int unk06AC;
    int unk06B0;
    int unk06B4;
    int unk06B8;
    int unk06BC;
    int unk06C0;
    int unk06C4;
    int unk06C8;
    int unk06CC;
    int unk06D0;
    int unk06D4;
    int unk06D8;
    int unk06DC;
    int unk06E0;
    int unk06E4;
    int unk06E8;
    int unk06EC;
    int unk06F0;
    int unk06F4;
    int unk06F8;
    int unk06FC;
    int unk0700;
    int unk0704;
    int unk0708;
    int unk070C;
    int unk0710;
    int unk0714;
    int unk0718;
    int unk071C;
    int unk0720;
    int unk0724;
    int unk0728;
    int unk072C;
    int unk0730;
    int unk0734;
    int unk0738;
    int unk073C;
    int unk0740;
    int unk0744;
    int unk0748;
    int unk074C;
    int unk0750;
    int unk0754;
    int unk0758;
    int unk075C;
    int unk0760;
    int unk0764;
    int unk0768;
    int unk076C;
    int unk0770;
    int unk0774;
    int unk0778;
    int unk077C;
    int unk0780;
    int unk0784;
    int unk0788;
    int unk078C;
    int unk0790;
    int unk0794;
    int unk0798;
    int unk079C;
    int unk07A0;
    int unk07A4;
    int unk07A8;
    int unk07AC;
    int unk07B0;
    int unk07B4;
    int unk07B8;
    int unk07BC;
    int unk07C0;
    int unk07C4;
    int unk07C8;
    int unk07CC;
    int unk07D0;
    int unk07D4;
    int unk07D8;
    int unk07DC;
    int unk07E0;
    int unk07E4;
    int unk07E8;
    int unk07EC;
    int unk07F0;
    int unk07F4;
    int unk07F8;
    int unk07FC;
    int unk0800;
    int unk0804;
    int unk0808;
    int unk080C;
    int unk0810;
    int unk0814;
    int unk0818;
    int unk081C;
    int unk0820;
    int unk0824;
    int unk0828;
    int unk082C;
    int unk0830;
    int unk0834;
    int unk0838;
    int unk083C;
    int unk0840;
    int unk0844;
    int unk0848;
    int unk084C;
    int unk0850;
    int unk0854;
    int unk0858;
    int unk085C;
    int unk0860;
    int unk0864;
    int unk0868;
    int unk086C;
    int unk0870;
    int unk0874;
    int unk0878;
    int unk087C;
    int unk0880;
    int unk0884;
    int unk0888;
    int unk088C;
    int unk0890;
    int unk0894;
    int unk0898;
    int unk089C;
    int unk08A0;
    int unk08A4;
    int unk08A8;
    int unk08AC;
    int unk08B0;
    int unk08B4;
    EC0280RenderState* m_pCurrentRenderState;
};

// @fnv 0x00ec0280
void __cdecl DrawTexturedQuad(EC0280Device* pkDevice, float fX, float fY, float fScaleX, float fScaleY, int iWidth,
                              int iHeight)
{
    EC0280Vertex akVertsVal[4];
    {
        void* pkDecl_2;
        EC0280Renderer* pkRenderer5;
        EC0280RenderState* _pkRet1;
        EC0280Renderer* pkRendererTmp;
        EC0280RenderState* pkRetVal;
        EC0280Renderer* pkRenderer4;
        EC0280RenderState* pkRet4;
        akVertsVal[0].x = fX;
        akVertsVal[0].y = fY;
        akVertsVal[0].z = 0.0f;
        akVertsVal[0].rhw = 1.0f;
        akVertsVal[0].u = 0.0f;
        akVertsVal[0].v = 0.0f;
        akVertsVal[1] = akVertsVal[0];
        akVertsVal[1].y = iHeight * fScaleY + fY;
        akVertsVal[1].v = 1.0f;
        akVertsVal[2] = akVertsVal[0];
        akVertsVal[2].x = iWidth * fScaleX + fX;
        akVertsVal[2].u = 1.0f;
        akVertsVal[3] = akVertsVal[2];
        akVertsVal[3].y = akVertsVal[1].y;
        akVertsVal[3].v = 1.0f;

        {
            pkRenderer5 = (*reinterpret_cast<::EC0280Renderer * *>(&::NiRenderer::ms_pRenderer));
            EC0280RenderState* kPkState1 = _pkRet1;
            kPkState1 = pkRenderer5->m_pCurrentRenderState;
            kPkState1->SetStage(0, 1);
            pkRendererTmp = (*reinterpret_cast<::EC0280Renderer * *>(&::NiRenderer::ms_pRenderer));
            EC0280RenderState* pkState2 = pkRetVal;
            pkState2 = pkRendererTmp->m_pCurrentRenderState;
            pkState2->SetTexture(0, 0);
            pkDecl_2 = 0;
            pkDevice->GetVertexDeclaration(&pkDecl_2);
            pkDevice->SetFVF(0x104);
            pkDevice->DrawPrimitiveUP(5, 2, akVertsVal, sizeof(EC0280Vertex));
            pkDevice->SetFVF(0);
            pkDevice->SetVertexDeclaration(pkDecl_2);
            pkRenderer4 = (*reinterpret_cast<::EC0280Renderer * *>(&::NiRenderer::ms_pRenderer));
            EC0280RenderState* pkState5 = pkRet4;
            pkState5 = pkRenderer4->m_pCurrentRenderState;
            pkState5->Commit();
        }
    }
}

struct FUN_00ec0720_Vertex
{
    float x;
    float y;
    float z;
    float rhw;
    float u;
    float v;
};

struct FUN_00ec0720_Device : FUN_00ec0460_cls
{
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83(int a, int b, const void* c, unsigned int d);
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89(unsigned int a);
    virtual void v90();
    virtual void v91();
    virtual void v92(int a);
};

// @fnv 0x00ec0720
void __cdecl FUN_00ec0720(FUN_00ec0720_Device* pDevice, float x, float y, float fScaleX, float fScaleY, int iWidth,
                          int iHeight)
{
    FUN_00ec0720_Vertex vertices[12];

    vertices[0].x = x;
    vertices[0].y = y;
    vertices[0].z = 0.0f;
    vertices[0].rhw = 1.0f;
    vertices[0].u = 0.0f;
    vertices[0].v = 0.0f;

    vertices[1] = vertices[0];
    vertices[1].x = (float)iWidth * fScaleX + x;
    vertices[1].y = y;

    vertices[2] = vertices[1];

    vertices[3] = vertices[1];
    vertices[3].y = (float)iHeight * fScaleY + y;

    vertices[4] = vertices[3];

    vertices[5] = vertices[3];
    vertices[5].x = x;

    vertices[6] = vertices[5];

    vertices[7] = vertices[0];

    vertices[8] = vertices[0];

    vertices[9] = vertices[3];

    vertices[10] = vertices[2];

    vertices[11] = vertices[6];

    pDevice->v67(0, 2, 0);
    pDevice->v67(0, 5, 0);
    pDevice->v92(0);
    pDevice->v89(0x104);
    pDevice->v83(2, 6, vertices, 0x18);
}

struct EC1060Size
{
    int a, b;
    unsigned int width, height;
};
struct EC1060Rect
{
    unsigned int left, top, right, bottom;
};
struct EC1060Viewport
{
    float lo, hi;
    unsigned int x, y;
};
struct EC1060Player
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual bool v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual bool v16(bool);
    char pad[21];
    bool paused;
};
struct EC1060Renderer
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual EC1060Size& v53();
};
struct EC1060Device
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(int, int, int, int);
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43(int, int, int, unsigned int, float, int);
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47(EC1060Rect*);
};
extern "C" char DAT_010f1be4;
extern "C" __declspec(dllimport) int BinkWait(void*);
extern "C" __declspec(dllimport) void BinkNextFrame(void*);
struct EC1060Bink
{
    int a, b;
    unsigned int frames;
};
struct EC1060File
{
    EC1060Bink* apDirectSound;
    EC1060Device* device;
    unsigned int texture, frame, decoded;
    float scale, x, y;
    int state;
    bool Update(bool, bool, bool);
};
// @fnv 0x00ec1060
bool EC1060File::Update(bool arg1, bool abLoop, bool abNoClip)
{
    EC1060Viewport h, i;
    EC1060Rect a, s;
    EC1060Size *eb, *cf, *q, *b;
    unsigned char p = false;
    if (!((EC1060Player*)::DAT_0126fac4)->v16(arg1))
        return false;
    bool f = ((EC1060Player*)::DAT_0126fac4)->paused;
    if (!f)
    {
        if (!BinkWait(apDirectSound))
        {
            p = DecodeBinkFrame((FUN_00ec14d0_bink*)apDirectSound, texture, 0);
            if (p)
            {
                decoded++;
                ::FUN_0040fbe0();
            }
            BinkNextFrame(apDirectSound);
            frame++;
        }
        else if (!(unsigned char)(state == 2))
        {
            Sleep(1);
            return true;
        }
    }
    device->v43(0, 0, 1, 0xff000000, 1.0f, 0);
    if (!abNoClip && *(unsigned char*)&(*reinterpret_cast<char *>(&::DAT_011f9426)))
    {
        eb = &(*(EC1060Renderer* volatile*)&(*reinterpret_cast<char *>(&::NiRenderer::ms_pRenderer)))->v53();
        h.x = eb->width;
        cf = &(*(EC1060Renderer* volatile*)&(*reinterpret_cast<char *>(&::NiRenderer::ms_pRenderer)))->v53();
        h.y = cf->height;
        h.lo = 0.0f;
        h.hi = 1.0f;
        a.left = (unsigned int)(h.x * *(float*)&DAT_011ad840);
        a.right = (unsigned int)((*(float*)&DAT_011ad844 - *(float*)&DAT_011ad840) * h.x);
        a.top = (unsigned int)(h.y * *(float*)&(*reinterpret_cast<char *>(&::DAT_011ad84c)));
        a.bottom = (unsigned int)((*(float*)&(*reinterpret_cast<char *>(&::DAT_011ad848)) - *(float*)&(*reinterpret_cast<char *>(&::DAT_011ad84c))) * h.y);
        device->v47(&a);
    }
    if (!((EC1060Player*)::DAT_0126fac4)->v12())
        device->v41();
    ::fnv_00ebff30::FUN_00ebff30((::fnv_00ebff30::TileGrid *)(texture), x, y, scale, scale);
    if (!((EC1060Player*)::DAT_0126fac4)->v12())
        device->v42();
    if (!(unsigned char)(state == 2))
        device->v17(0, 0, 0, 0);
    if (!abNoClip && *(unsigned char*)&(*reinterpret_cast<char *>(&::DAT_011f9426)))
    {
        q = &(*(EC1060Renderer* volatile*)&(*reinterpret_cast<char *>(&::NiRenderer::ms_pRenderer)))->v53();
        i.x = q->width;
        b = &(*(EC1060Renderer* volatile*)&(*reinterpret_cast<char *>(&::NiRenderer::ms_pRenderer)))->v53();
        i.y = b->height;
        i.lo = 0.0f;
        i.hi = 1.0f;
        s.left = 0;
        s.top = 0;
        s.right = i.x;
        s.bottom = i.y;
        device->v47(&s);
    }
    if (frame >= apDirectSound->frames && !abLoop)
        return false;
    return true;
}

class StrMapW
{
  public:
    void* vtbl;
    unsigned int m_uiHashSize;
    unsigned int HashKey(const char* pKey);
};
// Computes a rolling hash over the characters of pKey and returns it modulo m_uiHashSize.
// @fnv 0x00ec1c30
unsigned int StrMapW::HashKey(const char* pKey)
{
    unsigned int uiHash = 0;
    while (*pKey)
    {
        char c = *pKey;
        uiHash = uiHash + (c + (uiHash << 5));
        pKey++;
    }
    return uiHash % m_uiHashSize;
}


struct MovieJob
{
    int m_0000;
    int m_0004;
    int m_0008;
    int m_000c;
    int m_0010;
    int m_0014;
    int m_0018;
    int m_001c;
    int m_0020;
    unsigned char m_0024;
};

struct MoviePlayer
{
    int m_0000;
    int m_0004;
    int m_0008;
    MovieJob* m_000c;
    void WaitForJobCompletion();
};

// Sleeps 1 ms in a loop while m_0008 is set and the job is missing or its m_0024 flag is nonzero.
// @fnv 0x00ec29d0
void MoviePlayer::WaitForJobCompletion()
{
    unsigned char busy;
    while (m_0008 != 0 && (m_000c == 0 || (busy = m_000c->m_0024) != 0))
        Sleep(1);
}

struct FUN_00ec2f00_item
{
    FUN_00ec2f00_item* next;
    void* m04;
    unsigned int m08;
};

struct FUN_00ec2f00_cls
{
    virtual void v00();
    virtual int v01(void* a);
    virtual bool v02(void* a, void* b);
    virtual void v03(void* a, void* b, void* c);
    int unk04;
    FUN_00ec2f00_item** m08;
    int m0c;
    unsigned char m10;

    void AddOrUpdate(void* arg8, unsigned int argc);
};

// Finds an item in the m08 bucket matching arg8 via v02, updates it, or allocates and inserts a new one via v03.
// @fnv 0x00ec2f00
void FUN_00ec2f00_cls::AddOrUpdate(void* apKey, unsigned int uiValue)
{
    void* mem;
    FUN_00ec2f00_item* item;
    int idx = v01(apKey);
    item = m08[idx];
    int count = 0;
    while (item)
    {
        count++;
        if (v02(apKey, item->m04))
        {
            if (!m10)
            {
                item->m04 = apKey;
            }
            item->m08 = uiValue;
            return;
        }
        item = item->next;
    }
    mem = reinterpret_cast<::MemoryManagerStandIn *>((reinterpret_cast<P03MM*>(&(*reinterpret_cast<::FUN_00ec1df0_pool *>(&::g_memoryManager)))))->FUN_00aa3e40(12);
    item = (FUN_00ec2f00_item*)mem;
    v03(item, apKey, (void*)uiValue);
    item->next = m08[idx];
    m08[idx] = item;
    m0c++;
}

extern "C" int __cdecl _tolower(int c);

struct FUN_00ec1d50_class
{
    int unk00;
    unsigned int unk04;

    unsigned int HashString(const char* a);
};

// Computes a case-insensitive string hash using a shift-and-add algorithm and returns the result modulo unk04.
// @fnv 0x00ec1d50
unsigned int FUN_00ec1d50_class::HashString(const char* apString)
{
    unsigned int h = 0;
    char cLower;
    if (1)
    {
    }
    if (1)
    {
    }
    while (*apString)
        h = (h << 5) + h + (cLower = (char)_tolower(*apString++));
    return h % unk04;
}

namespace fnv_00ec1940 {
#include <windows.h>
#include "fnv/decl/MapOwnerStandIn.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01063000.h"
#include "fnv/symbols_01272000.h"

DWORD WINAPI FUN_00ec2ca0(LPVOID param);

class FUN_00ec1940_cls
{
  public:
    int unk00;
    HANDLE m_04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int m_1c;
    void FUN_00ec1940(void* param, int value);
};

// Stores value in m_1c, creates a suspended thread running FUN_00ec2ca0 with param, names it MovieLoader, then resumes it.
// @fnv 0x00ec1940
void FUN_00ec1940_cls::FUN_00ec1940(void* apThreadArg, int value)
{
    DWORD threadId;
    m_1c = value;
    m_04 = CreateThread(NULL, 0, FUN_00ec2ca0, apThreadArg, CREATE_SUSPENDED, &threadId);
    ::SetDebuggerThreadName(threadId, "MovieLoader");
    ResumeThread(m_04);
    threadId = 0;
}
}  // namespace fnv_00ec1940


struct MovieSignalState : BEC16D0MoviePlayerThread
{
    int unk38;
    unsigned char signaled;

    void FUN_00ec1a00();
};

// Releases m_kStartSemaphore, increments its m_lCount, and sets the signaled flag to 1.
// @fnv 0x00ec1a00
void MovieSignalState::FUN_00ec1a00()
{
    BEC16D0Semaphore* semaphore = &m_kStartSemaphore;
    ReleaseSemaphore(semaphore->m_pSemaphore, 1, 0);
    InterlockedIncrement(&semaphore->m_lCount);
    signaled = 1;
}

struct PlaybackMessage
{
    void* window;
    unsigned int message;
    unsigned int wParam;
    long lParam;
    unsigned long time;
    long cursorX;
    long cursorY;
};


struct PlaybackContinueState : MoviePlayer
{
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    bool unk20;
    unsigned char interrupted;

    bool FUN_00ec1840(bool allowInterruption);
};

// Pumps pending Windows messages and returns false if the playback was interrupted, otherwise true.
// @fnv 0x00ec1840
bool PlaybackContinueState::FUN_00ec1840(bool allowInterruption)
{
    PlaybackMessage msg;
    while (PeekMessageA(&msg, 0, 0, 0, 1))
    {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    unsigned char c = interrupted;
    if (c)
        return false;
    return true;
}

int FUN_00ec16b0(int a);

extern int __cdecl __stricmp(const char*, const char*);


int __cdecl _strcpy_s(char* dest, unsigned int size, const char* src);

void __cdecl FUN_00ec0550(GridDesc* grid, float startX, float startY, float scaleX, float scaleY);

unsigned char __cdecl DecodeBinkFrame(FUN_00ec14d0_bink* a1, unsigned int a2, int a3);

// Look up the file name registered under a key and copy it into a MAX_PATH buffer.
extern "C" int __cdecl strcpy_s(char* pcDest, unsigned int uiSize, const char* pcSrc);

// VEGAS17-CONFLICT: EC2DF0Registry (variant definition below differs from the one above)
class EC2DF0Registry
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    EC2DF0NameMap m_kNames;

    bool GetNameByKey(unsigned int uiKey, char* pcPath);
};

struct ThreadData2490
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    unsigned int unk1A4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int unk1B0;
    unsigned int unk1B4;
    unsigned int unk1B8;
    unsigned int unk1BC;
    unsigned int unk1C0;
    unsigned int unk1C4;
    unsigned int unk1C8;
    unsigned int unk1CC;
    unsigned int unk1D0;
    unsigned int unk1D4;
    unsigned int unk1D8;
    unsigned int unk1DC;
    unsigned int unk1E0;
    unsigned int unk1E4;
    unsigned int unk1E8;
    unsigned int unk1EC;
    unsigned int unk1F0;
    unsigned int unk1F4;
    unsigned int unk1F8;
    unsigned int unk1FC;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20C;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21C;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22C;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23C;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24C;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25C;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26C;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27C;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28C;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29C;
    unsigned int unk2A0;
    unsigned int unk2A4;
    unsigned int unk2A8;
    unsigned int unk2AC;
    unsigned int unk2B0;
    unsigned int context;
};

struct Scope2490
{
    unsigned int previous;
    Scope2490()
    {
        unsigned int current = (*reinterpret_cast<::ThreadData2490 *>(&::g_tlsBlock)).context;
        previous = current;
        (*reinterpret_cast<::ThreadData2490 *>(&::g_tlsBlock)).context = 20;
    }
    ~Scope2490()
    {
        unsigned int restored = previous;
        (*reinterpret_cast<::ThreadData2490 *>(&::g_tlsBlock)).context = restored;
    }
};

struct Movie2490
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    Movie2490();
};

struct FUN_00ec2490_Class
{
    int unk00, unk04, unk08;
    Movie2490* movie;
    int unk10;
    Movie2490* cached;
    bool hasCached;
    unsigned char FUN_00ec2490(int, unsigned char);
};

// @fnv 0x00ec2490
unsigned char FUN_00ec2490_Class::FUN_00ec2490(int value, unsigned char option)
{
    Scope2490 scope;
    reinterpret_cast<::FUN_00ec2a10_class *>(this)->PauseMovie();
    if (hasCached && cached)
    {
        movie = cached;
        cached = 0;
        hasCached = false;
    }
    else
    {
        movie = new Movie2490;
    }
    unsigned char result = reinterpret_cast<::FUN_00ec1f60_Class *>((movie))->InitAndCheck(value, option);
    if (!result)
        reinterpret_cast<::fnv_00ec25e0::FUN_00ec25e0_cls *>(this)->FUN_00ec25e0();
    return result;
}

namespace fnv_00ec2ca0 {
struct MemMgr_cls
{
    int unk00;
};

struct SpawnedObject
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;

    SpawnedObject();
};

// @fnv 0x00ec2ca0
int FUN_00ec2ca0(int a1)
{
    SpawnedObject* obj = new SpawnedObject();
    reinterpret_cast<::NiPlaybackFile *>((obj))->FindString((const char *)(a1), 1, 1, 1);
    reinterpret_cast<FUN_00ec2d40_class*>(::DAT_0126fac4)->SetValueAndReset((int)obj);
    return 0;
}
}

// namespace fnv_00ec2ca0

struct MovieSemaphore
{
    int unk00;
    void* handle;
};

struct ScopedAllocTag
{
    int saved;
    __forceinline ScopedAllocTag(int previous)
    {
        saved = previous;
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = 0x14;
    }
    __forceinline ~ScopedAllocTag()
    {
        int old = saved;
        (*reinterpret_cast<int *>(&::currentAllocationContext)) = old;
    }
};

struct MovieMemMgr
{
    void Deallocate(void* p);
};

struct MovieBoolSetting
{
    int vtbl;
    bool value;
};

extern const char g_movieExt[];

extern const char g_movieWarnFmt[];

struct MoviePlayerA
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void Lock();
    virtual void Unlock();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual unsigned long GetThreadId();
    virtual bool CanQueue(bool first);

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    bool unk20;
    bool unk21;
    bool unk22;
    bool unk23;
    bool unk24;
    char unk25;
    char unk26;
    char unk27;
    int unk28;
    int unk2c;
    MovieSemaphore semaphore30;
    int unk38;
    bool unk3c;

    void FUN_00ec1a00()
    {
        MovieSemaphore* semaphore = &semaphore30;
        ReleaseSemaphore(semaphore->handle, 1, 0);
        InterlockedIncrement(semaphore);
        unk3c = true;
    }
    void FUN_00ec2760(const char* list);
};

struct MemoryManager1BB0
{
    void Deallocate(void* pvMem);
};

extern MemoryManager1BB0 g_kMemoryManager1BB0;

struct MapItem1BB0
{
    MapItem1BB0* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBase1BB0
{
  public:
    static void operator delete(void* pvMem)
    {
        g_kMemoryManager1BB0.Deallocate(pvMem);
    }
    virtual ~MapBase1BB0()
    {
        reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItem1BB0* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItem1BB0* pkItem);
    virtual MapItem1BB0* NewItem();
    virtual void DeleteItem(MapItem1BB0* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItem1BB0* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItem1BB0** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00ec1bb0 : public MapBase1BB0
{
  public:
    virtual ~FUN_00ec1bb0();
};

// @fnv 0x00ec1bb0
FUN_00ec1bb0::~FUN_00ec1bb0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

struct TlsData
{
    unsigned int unk0000;
    unsigned int unk0004;
    unsigned int unk0008;
    unsigned int unk000C;
    unsigned int unk0010;
    unsigned int unk0014;
    unsigned int unk0018;
    unsigned int unk001C;
    unsigned int unk0020;
    unsigned int unk0024;
    unsigned int unk0028;
    unsigned int unk002C;
    unsigned int unk0030;
    unsigned int unk0034;
    unsigned int unk0038;
    unsigned int unk003C;
    unsigned int unk0040;
    unsigned int unk0044;
    unsigned int unk0048;
    unsigned int unk004C;
    unsigned int unk0050;
    unsigned int unk0054;
    unsigned int unk0058;
    unsigned int unk005C;
    unsigned int unk0060;
    unsigned int unk0064;
    unsigned int unk0068;
    unsigned int unk006C;
    unsigned int unk0070;
    unsigned int unk0074;
    unsigned int unk0078;
    unsigned int unk007C;
    unsigned int unk0080;
    unsigned int unk0084;
    unsigned int unk0088;
    unsigned int unk008C;
    unsigned int unk0090;
    unsigned int unk0094;
    unsigned int unk0098;
    unsigned int unk009C;
    unsigned int unk00A0;
    unsigned int unk00A4;
    unsigned int unk00A8;
    unsigned int unk00AC;
    unsigned int unk00B0;
    unsigned int unk00B4;
    unsigned int unk00B8;
    unsigned int unk00BC;
    unsigned int unk00C0;
    unsigned int unk00C4;
    unsigned int unk00C8;
    unsigned int unk00CC;
    unsigned int unk00D0;
    unsigned int unk00D4;
    unsigned int unk00D8;
    unsigned int unk00DC;
    unsigned int unk00E0;
    unsigned int unk00E4;
    unsigned int unk00E8;
    unsigned int unk00EC;
    unsigned int unk00F0;
    unsigned int unk00F4;
    unsigned int unk00F8;
    unsigned int unk00FC;
    unsigned int unk0100;
    unsigned int unk0104;
    unsigned int unk0108;
    unsigned int unk010C;
    unsigned int unk0110;
    unsigned int unk0114;
    unsigned int unk0118;
    unsigned int unk011C;
    unsigned int unk0120;
    unsigned int unk0124;
    unsigned int unk0128;
    unsigned int unk012C;
    unsigned int unk0130;
    unsigned int unk0134;
    unsigned int unk0138;
    unsigned int unk013C;
    unsigned int unk0140;
    unsigned int unk0144;
    unsigned int unk0148;
    unsigned int unk014C;
    unsigned int unk0150;
    unsigned int unk0154;
    unsigned int unk0158;
    unsigned int unk015C;
    unsigned int unk0160;
    unsigned int unk0164;
    unsigned int unk0168;
    unsigned int unk016C;
    unsigned int unk0170;
    unsigned int unk0174;
    unsigned int unk0178;
    unsigned int unk017C;
    unsigned int unk0180;
    unsigned int unk0184;
    unsigned int unk0188;
    unsigned int unk018C;
    unsigned int unk0190;
    unsigned int unk0194;
    unsigned int unk0198;
    unsigned int unk019C;
    unsigned int unk01A0;
    unsigned int unk01A4;
    unsigned int unk01A8;
    unsigned int unk01AC;
    unsigned int unk01B0;
    unsigned int unk01B4;
    unsigned int unk01B8;
    unsigned int unk01BC;
    unsigned int unk01C0;
    unsigned int unk01C4;
    unsigned int unk01C8;
    unsigned int unk01CC;
    unsigned int unk01D0;
    unsigned int unk01D4;
    unsigned int unk01D8;
    unsigned int unk01DC;
    unsigned int unk01E0;
    unsigned int unk01E4;
    unsigned int unk01E8;
    unsigned int unk01EC;
    unsigned int unk01F0;
    unsigned int unk01F4;
    unsigned int unk01F8;
    unsigned int unk01FC;
    unsigned int unk0200;
    unsigned int unk0204;
    unsigned int unk0208;
    unsigned int unk020C;
    unsigned int unk0210;
    unsigned int unk0214;
    unsigned int unk0218;
    unsigned int unk021C;
    unsigned int unk0220;
    unsigned int unk0224;
    unsigned int unk0228;
    unsigned int unk022C;
    unsigned int unk0230;
    unsigned int unk0234;
    unsigned int unk0238;
    unsigned int unk023C;
    unsigned int unk0240;
    unsigned int unk0244;
    unsigned int unk0248;
    unsigned int unk024C;
    unsigned int unk0250;
    unsigned int unk0254;
    unsigned int unk0258;
    unsigned int unk025C;
    unsigned int unk0260;
    unsigned int unk0264;
    unsigned int unk0268;
    unsigned int unk026C;
    unsigned int unk0270;
    unsigned int unk0274;
    unsigned int unk0278;
    unsigned int unk027C;
    unsigned int unk0280;
    unsigned int unk0284;
    unsigned int unk0288;
    unsigned int unk028C;
    unsigned int unk0290;
    unsigned int unk0294;
    unsigned int unk0298;
    unsigned int unk029C;
    unsigned int unk02A0;
    unsigned int unk02A4;
    unsigned int unk02A8;
    unsigned int unk02AC;
    unsigned int unk02B0;
    unsigned int m_2b4;
};

struct MemPoolCalls
{
};

inline unsigned int GetAllocContext()
{
    return (*reinterpret_cast<::TlsData *>(&::g_tlsBlock)).m_2b4;
}

inline void SetAllocContext(unsigned int v)
{
    (*reinterpret_cast<::TlsData *>(&::g_tlsBlock)).m_2b4 = v;
}

struct ScopedAllocContext
{
    unsigned int m_saved;
    inline ScopedAllocContext(unsigned int ctx)
    {
        m_saved = GetAllocContext();
        (*reinterpret_cast<::TlsData *>(&::g_tlsBlock)).m_2b4 = ctx;
    }
    inline ~ScopedAllocContext()
    {
        SetAllocContext(m_saved);
    }
};

// @fnv 0x00ec1ff0
void* FUN_00ec1ff0(unsigned int size)
{
    ScopedAllocContext ctx(0x14);
    return reinterpret_cast<::MemoryManagerStandIn *>((((MemPoolCalls*)&(*reinterpret_cast<::FUN_00ec1df0_pool *>(&::g_memoryManager)))))->FUN_00aa3e40(size);
}

struct MemoryManagerEC2200
{
    void Deallocate(void* pvMem);
};

inline unsigned int GetMemContextEC2200()
{
    return ::currentAllocationContext;
}

inline void SetMemContextEC2200(unsigned int m_uiGeometryShaderFlags)
{
    ::currentAllocationContext = m_uiGeometryShaderFlags;
}

class AutoMemContextEC2200
{
  public:
    AutoMemContextEC2200(unsigned int m_uiGeometryShaderFlags)
    {
        m_uiPrevious = GetMemContextEC2200();
        SetMemContextEC2200(m_uiGeometryShaderFlags);
    }
    ~AutoMemContextEC2200()
    {
        SetMemContextEC2200(m_uiPrevious);
    }
    unsigned int m_uiPrevious;
};

class PlaybackFileEC2200
{
  public:
    PlaybackFileEC2200();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};

class PlaybackEC2200
{
  public:
    bool FUN_00ec2200(const char* pcName, bool bA, bool bB, bool bC);
    int unk00;
    int unk04;
    int unk08;
    PlaybackFileEC2200* m_pFile;
};

// @fnv 0x00ec2200
bool PlaybackEC2200::FUN_00ec2200(const char* pcName, bool bA, bool bB, bool bC)
{
    AutoMemContextEC2200 kContext(20);
    m_pFile = new PlaybackFileEC2200;
    bool bSuccess = reinterpret_cast<::NiPlaybackFile *>((m_pFile))->FindString(pcName, bA, bB, bC);
    if (!bSuccess)
        reinterpret_cast<::fnv_00ec25e0::FUN_00ec25e0_cls *>(this)->FUN_00ec25e0();
    return bSuccess;
}

inline int GetMemContext()
{
    return (*reinterpret_cast<int *>(&::currentAllocationContext));
}

inline void SetMemContext(int aiMemoryContext)
{
    (*reinterpret_cast<int *>(&::currentAllocationContext)) = aiMemoryContext;
}

struct MemContextGuard
{
    int m_iSaved;
    MemContextGuard(int aiMemoryContext)
    {
        m_iSaved = GetMemContext();
        SetMemContext(aiMemoryContext);
    }
    ~MemContextGuard()
    {
        SetMemContext(m_iSaved);
    }
};

class BSMovieJob
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    BSMovieJob();
};

class BSMovieThread
{
  public:
    int unk00, unk04, unk08;
    BSMovieJob* m_pkCurrent;
    int unk10;
    BSMovieJob* m_pkSaved;
    bool m_bPending;
    int unk1c, unk20, unk24;
    float m_fScale;
    bool FUN_00ec2320(void* pFile, bool a, bool b, bool c, bool d, bool e, bool bReuse, bool f, bool g);
};

// @fnv 0x00ec2760
void MoviePlayerA::FUN_00ec2760(const char* list)
{
    char* ext2;
    int tidTmp3 = (*reinterpret_cast<int *>(&::currentAllocationContext));
    ScopedAllocTag tag(tidTmp3);
    Lock();
    unsigned int size;
    size = std::strlen(list) + 1;
    char* buf2 = (char*)reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::MovieMemMgr *>(&::g_memoryManager))))->FUN_00aa3e40(size);
    std::strcpy(buf2, list);
    char* tok_2 = std::strtok(buf2, (*reinterpret_cast<const char (*)[]>(&::fnv_00ac9790::DAT_01063cd8)));
    bool first = true;
    unk3c = 0;
    while (tok_2)
    {
        if (!unk21 && CanQueue(first))
        {
            ext2 = tok_2 + std::strlen(tok_2) - 3;
            if (fnv::crt::stricmp(ext2, g_movieExt) == 0)
            {
                bool* setting =
                    &(*reinterpret_cast<::MovieBoolSetting *>(&::g_0126fac8)) ? &(*reinterpret_cast<::MovieBoolSetting *>(&::g_0126fac8)).value : (*(bool*)& DAT_01202800 = false, (bool*)&DAT_01202800);
                reinterpret_cast<::BSMovieThread *>(this)->FUN_00ec2320((void *)(tok_2), first, 1, 0, *setting, unk22, 0, unk23, unk24);
            }
            else
            {
                ::FUN_005b5e40();
            }
        }
        tok_2 = std::strtok(0, (*reinterpret_cast<const char (*)[]>(&::fnv_00ac9790::DAT_01063cd8)));
    }
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MovieMemMgr *>(&::g_memoryManager))))->FUN_00aa4060(buf2);
    unk21 = 0;
    if (!unk20)
        unk08 = 0;
    {
        unsigned long previous5 = GetCurrentThreadId();
        if (previous5 != GetThreadId() && !unk3c)
            reinterpret_cast<::MovieSignalState *>(this)->FUN_00ec1a00();
    }
    Unlock();
}

struct ThreadContext
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    int m_uiMemoryContext;
};

__forceinline int GetMemoryContext()
{
    return (*reinterpret_cast<::ThreadContext *>(&::g_tlsBlock)).m_uiMemoryContext;
}
__forceinline void SetMemoryContext(int value)
{
    (*reinterpret_cast<::ThreadContext *>(&::g_tlsBlock)).m_uiMemoryContext = value;
}

struct HeapZoneGuard
{
    int saved;
    __forceinline HeapZoneGuard(int zone)
    {
        saved = GetMemoryContext();
        (*reinterpret_cast<::ThreadContext *>(&::g_tlsBlock)).m_uiMemoryContext = zone;
    }
    __forceinline ~HeapZoneGuard()
    {
        SetMemoryContext(saved);
    }
};

struct EC1060Target
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    __forceinline unsigned char IsReady() const
    {
        return unk20 != 0;
    }
};

struct EC2650Owner
{
    int unk00;
    int unk04;
    int unk08;
    EC1060Target* unk0c;
    unsigned char FUN_00ec2650(unsigned char a, unsigned char b);
};

// @fnv 0x00ec2650
unsigned char EC2650Owner::FUN_00ec2650(unsigned char a, unsigned char b)
{
    HeapZoneGuard guard(0x14);
    if (unk0c && unk0c->IsReady())
    {
        return ((unsigned char)(reinterpret_cast<::EC1060File *>((unk0c))->Update(a, b, 0)));
    }
    return 0;
}

void NiFree(void* p);

class NiTStringMapBase
{
  public:
    unsigned int m_uiHashSize;
    NiTMapItem<const char*, char*>** m_ppkHashTable;
    unsigned int m_uiCount;
    virtual void ClearValue(NiTMapItem<const char*, char*>* pkItem);
    virtual void DeleteItem(NiTMapItem<const char*, char*>* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                NiTMapItem<const char*, char*>* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    virtual ~NiTStringMapBase()
    {
        reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
};

class NiTStringMapMid : public NiTStringMapBase
{
  public:
    virtual ~NiTStringMapMid()
    {
        reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    }
};

class NiTStringMapCopy : public NiTStringMapMid
{
  public:
    bool m_bCopy;
    virtual ~NiTStringMapCopy();
};

// @fnv 0x00ec1a90
NiTStringMapCopy::~NiTStringMapCopy()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            NiTMapItem<const char*, char*>* pkItem = m_ppkHashTable[i];
            while (pkItem)
            {
                NiTMapItem<const char*, char*>* pkSave = pkItem;
                pkItem = pkItem->m_pkNext;
                ::FUN_00aa10f0((char*)pkSave->m_key);
            }
        }
    }
}

struct MapItemE40
{
    MapItemE40* m_pkNext;
    int m_key;
    int m_val;
};

struct BaseE40
{
    unsigned int m_uiHashSize;
    MapItemE40** m_ppkHashTable;
    int m_uiCount;
    virtual ~BaseE40()
    {
        reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
        ::FUN_00aa10f0((void *)((int)m_ppkHashTable));
    }
    virtual unsigned int KeyToHashIndex(int key) const;
    virtual bool IsKeysEqual(int a, int b) const;
    virtual void SetValue(MapItemE40* pkItem, int key, int val);
    virtual void ClearValue(MapItemE40* pkItem);
    virtual MapItemE40* NewItem();
    virtual void DeleteItem(MapItemE40* pkItem);
    void FUN_00438af0()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemE40* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
};

struct FUN_00ec1e40 : BaseE40
{
// @fnv 0x00ec1e40
    virtual ~FUN_00ec1e40()
    {
        reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
    }
};

void MakeE40()
{
    new FUN_00ec1e40;
}

namespace fnv_00ec15e0 {
class MovieSemaphore
{
  public:
    long count;
    void* handle;
    long maximum;
    ~MovieSemaphore()
    {
        CloseHandle(handle);
    }
};
template <class K, class V> class NiTMapItem;

extern MemoryManager g_movieHeap;
inline void NiFree(void* p)
{
    reinterpret_cast<::FNV_MemoryManager *>(&(g_movieHeap))->FUN_00aa4060(p);
}
template <class T> class DFALL;
typedef void* NiTMapIterator;
template <class A, class K, class V> class NiTMapBase
{
  public:
    virtual ~NiTMapBase();
    unsigned int hashSize;
    NiTMapItem<K, V>** buckets;
    unsigned int count;
    NiTMapIterator GetFirstPos() const
    {
        for (unsigned int i = 0; i < hashSize; i++)
        {
            if (buckets[i])
                return buckets[i];
        }
        return 0;
    }
    void GetNext(NiTMapIterator& pos, K& key, V& val) const;
    void RemoveAll();
};
template <class K, class V> class NiTMap : public NiTMapBase<DFALL<NiTMapItem<K, V> >, K, V>
{
  public:
    virtual ~NiTMap();
};
template <class Base, class V> class NiTStringTemplateMap : public Base
{
  public:
    bool copyStrings;
    virtual ~NiTStringTemplateMap();
};
template <class V> class NiTStringMap : public NiTStringTemplateMap<NiTMap<const char*, V>, V>
{
  public:
};
template <class V> class BSTCaseInsensitiveStringMap : public NiTStringMap<V>
{
  public:
    virtual ~BSTCaseInsensitiveStringMap()
    {}
};
class BSMoviePlayer
{
  public:
    virtual void Run();
    int unk04, unk08, unk0c, unk10, unk14;
    unsigned char unk18, unk19, unk1a, unk1b;
    int unk1c;
    unsigned char unk20, unk21, unk22, unk23, unk24, unk25, unk26, unk27;
    int unk28, unk2c;
    MovieSemaphore semaphore;
    int unk3c;
    BSTCaseInsensitiveStringMap<char*> strings;
    void FUN_00ec2e50()
    {
        NiTMapIterator pos = strings.GetFirstPos();
        while (pos)
        {
            const char* key = 0;
            char* val = 0;
            strings.GetNext(pos, key, val);
            NiFree(val);
        }
        strings.RemoveAll();
    }
    virtual ~BSMoviePlayer();
};
// @fnv 0x00ec15e0
BSMoviePlayer::~BSMoviePlayer()
{
    while (unk0c != 0)
        reinterpret_cast<::fnv_00ec25e0::FUN_00ec25e0_cls *>(this)->FUN_00ec25e0();
    reinterpret_cast<::MapOwnerStandIn *>(this)->FUN_00ec2e50();
}
}

// namespace fnv_00ec15e0

namespace fnv_00ec20c0 {
class MovieSemaphore
{
  public:
    long count;
    void* handle;
    long maximum;
    MovieSemaphore(long initial = 0, long maxCount = 1) : count(initial), maximum(maxCount)
    {
        handle = CreateSemaphoreA(0, count, maximum, 0);
    }
    ~MovieSemaphore()
    {
        CloseHandle(handle);
    }
};
template <class K, class V> class NiTMapItem;
template <class T> class DFALL;
void* __cdecl NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dst, int val, unsigned int size);
inline void* NiAllocBytes(unsigned int uiBytes)
{
    return NiMalloc(uiBytes);
}
inline void NiZeroBytes(void* pvDest, unsigned int uiBytes)
{
    memset(pvDest, 0, uiBytes);
}
template <class A, class K, class V> class NiTMapBase
{
  public:
    virtual ~NiTMapBase();
    unsigned int hashSize;
    NiTMapItem<K, V>** buckets;
    unsigned int count;
    NiTMapBase(unsigned int uiHashSize)
    {
        hashSize = uiHashSize;
        count = 0;
        buckets = (NiTMapItem<K, V>**)NiAllocBytes(sizeof(NiTMapItem<K, V>*) * hashSize);
        NiZeroBytes(buckets, sizeof(NiTMapItem<K, V>*) * hashSize);
    }
};
template <class K, class V> class NiTMap : public NiTMapBase<DFALL<NiTMapItem<K, V> >, K, V>
{
  public:
    NiTMap(unsigned int size = 37) : NiTMapBase<DFALL<NiTMapItem<K, V> >, K, V>(size)
    {}
    virtual ~NiTMap()
    {}
};
template <class Base, class V> class NiTStringTemplateMap : public Base
{
  public:
    bool copyStrings;
    NiTStringTemplateMap(unsigned int size = 37, bool copy = true) : Base(size), copyStrings(copy)
    {}
    virtual ~NiTStringTemplateMap()
    {}
};
template <class V> class NiTStringMap : public NiTStringTemplateMap<NiTMap<const char*, V>, V>
{
  public:
    NiTStringMap(unsigned int size = 37, bool copy = true) : NiTStringTemplateMap<NiTMap<const char*, V>, V>(size, copy)
    {}
    virtual ~NiTStringMap()
    {}
};
template <class V> class BSTCaseInsensitiveStringMap : public NiTStringMap<V>
{
  public:
    BSTCaseInsensitiveStringMap(unsigned int size = 37, bool copy = true) : NiTStringMap<V>(size, copy)
    {}
    virtual ~BSTCaseInsensitiveStringMap()
    {}
};
class BSMoviePlayer
{
  public:
    virtual void Run();
    int unk04, unk08, unk0c, unk10, unk14;
    unsigned char unk18, unk19, unk1a, unk1b;
    int unk1c;
    unsigned char unk20, unk21, unk22, unk23, unk24, unk25, unk26, unk27;
    int unk28, unk2c;
    MovieSemaphore semaphore;
    int unk3c;
    BSTCaseInsensitiveStringMap<char*> strings;
    BSMoviePlayer();
};
// @fnv 0x00ec20c0
BSMoviePlayer::BSMoviePlayer()
    : unk04(0), unk08(0), unk0c(0), unk10(0), unk14(0), unk18(0), unk19(0), unk1c(0), unk20(0), unk21(0), unk22(0),
      unk23(1), unk24(1), unk2c(0)
{}
}

// namespace fnv_00ec20c0


struct S0ERTTI
{
    const char* m_pcName;
    const S0ERTTI* m_pBaseRTTI;
};

struct S0ERenderer;

struct S0EObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual const S0ERTTI* GetRTTI() const;

    bool IsKindOfType(const S0ERTTI* pkRTTI) const
    {
        const S0ERTTI* pkTmp = GetRTTI();
        while (pkTmp)
        {
            if (pkTmp == pkRTTI)
                return true;
            pkTmp = pkTmp->m_pBaseRTTI;
        }
        return false;
    }
};

struct S0ESurface;

struct S0EBufferData : S0EObject
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S0ESurface* m_pkSurface;

    S0ESurface* GetSurface() const
    {
        return m_pkSurface;
    }
};

struct S0ETargetGroup
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual S0EObject* GetRenderTargetBuffer(unsigned int uiIndex);
};

struct S0ERenderer
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual S0ETargetGroup* GetDefaultRenderTargetGroup();

    static S0ERenderer* GetRenderer()
    {
        return (*reinterpret_cast<::S0ERenderer * *>(&::NiRenderer::ms_pRenderer));
    }
};

struct S0EDevice
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual long SetRenderTarget(unsigned long RenderTargetIndex, S0ESurface* pRenderTarget);
};

struct S0EMoviePlayer
{
    virtual void v00();
    virtual void BeginA();
    virtual void EndA();
    virtual void BeginB();
    virtual void EndB();
};

struct S0EBink
{
    int unk00;
    int unk04;
    unsigned int m_uiFrames;
};

struct S0EPlaybackFile
{
    S0EBink* m_pkBink;
    S0EDevice* m_pkDevice;
    unsigned int m_uiTexture;
    unsigned int m_uiFrame;
    unsigned int m_uiDecoded;
    float m_fScale;
    float m_fVectorY;
    float m_fVectorZ;
    int m_iFadeIndex;
    bool m_bBusy;

    unsigned char FUN_00ec0e00(const char* pcName, bool b1, bool b2, bool b3, bool b4, bool b5, bool b6, bool b7,
                               float afFinalFloat);
};

// @fnv 0x00ec2320
bool BSMovieThread::FUN_00ec2320(void* pFile, bool a, bool b, bool c, bool d, bool e, bool bReuse, bool f, bool g)
{
    MemContextGuard kGuard(20);
    if (!bReuse)
    {
        reinterpret_cast<::FUN_00ec2a10_class *>(this)->PauseMovie();
        if (m_bPending && m_pkSaved)
        {
            m_pkCurrent = m_pkSaved;
            m_pkSaved = 0;
            m_bPending = false;
        }
        else
        {
            m_pkCurrent = new BSMovieJob;
        }
    }
    bool bResult = ((bool)(reinterpret_cast<::S0EPlaybackFile *>((m_pkCurrent))->FUN_00ec0e00((const char *)(pFile), a, b, c, d, e, f, g, m_fScale)));
    reinterpret_cast<::fnv_00ec25e0::FUN_00ec25e0_cls *>(this)->FUN_00ec25e0();
    return bResult;
}

__forceinline S0EBufferData* DynamicCastBufferData(S0EObject* pkObject)
{
    if (!pkObject)
        return 0;
    return pkObject->IsKindOfType(&(*reinterpret_cast<::S0ERTTI *>(&::g_0126f59c))) ? (S0EBufferData*)pkObject : 0;
}

// @fnv 0x00ec0e00
unsigned char S0EPlaybackFile::FUN_00ec0e00(const char* pcName, bool b1, bool b2, bool b3, bool b4, bool b5, bool b6,
                                            bool b7, float afFinalFloat)
{
    S0EBufferData* pkCast2;
    bool bWait;
    unsigned char bRet;
    unsigned int uiStart;
    unsigned int uiNow3;

    m_iFadeIndex = 1;
    m_bBusy = true;
    if (!reinterpret_cast<::NiPlaybackFile *>(this)->InitPlayback(pcName, b2, b4, b5))
    {
        m_bBusy = false;
        return false;
    }
    m_bBusy = false;

    if (b6)
        ((S0EMoviePlayer*)::DAT_0126fac4)->BeginA();
    if (b7)
        ((S0EMoviePlayer*)::DAT_0126fac4)->BeginB();

    pkCast2 =
        DynamicCastBufferData(S0ERenderer::GetRenderer()->GetDefaultRenderTargetGroup()->GetRenderTargetBuffer(0));
    if (pkCast2)
        m_pkDevice->SetRenderTarget(0, pkCast2->GetSurface());

    bWait = b1;
    if (afFinalFloat != ::_DAT_01012060)
        bWait = false;
    uiStart = GetTickCount();
    while (reinterpret_cast<::EC1060File *>(this)->Update(bWait, b3, b5))
    {
        if (afFinalFloat != ::_DAT_01012060)
        {
            uiNow3 = GetTickCount();
            if (uiNow3 - uiStart > (unsigned int)(afFinalFloat * 1000.0))
            {
                bWait = true;
                afFinalFloat = 0.0f;
            }
        }
    }

    bRet = m_uiFrame >= m_pkBink->m_uiFrames;
    reinterpret_cast<::FUN_00ec1020_cls *>(this)->FUN_00ec1020();
    if (b6)
        ((S0EMoviePlayer*)::DAT_0126fac4)->EndA();
    if (b7)
        ((S0EMoviePlayer*)::DAT_0126fac4)->EndB();
    return bRet;
}

#include "generated/data/staging/blk_00ec0000_od.inc"
#include "generated/data/staging/blk_00ec0000_od_ob1_variant.inc"
