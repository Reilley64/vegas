
// src/gamebryo2.2/corelibs/nimain/niambientlight.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niambientlight.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/FUN_00a72010_owner.h"
#include "fnv/decl/FUN_00a721e0_shell.h"
#include "fnv/decl/NiDirectionalLight.h"
#include "fnv/decl/NiLight.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011f5000.h"
struct S00
{
    void* DestroyIfFlagged(unsigned int);
};
// Calls _FUN_00a72010, then if flags has bit 1 set deletes this with size 0xF0, and returns this.
// @fnv 0x00a9b3a0
void* S00::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_00a72010_owner *>(this)->FUN_00a72010();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xF0);
    return this;
}

struct StrArr
{
    char _0[8];
    unsigned short m_usMax;
    unsigned short m_usSize;
    char _c[2];
    unsigned short m_usGrow;
};
// Appends the string returned by _FUN_00a7d330(g_011f5f6c) to the StrArr, growing it via SetSize when the size reaches the max.
// @fnv 0x00a9b430
void FUN_00a9b430(StrArr* pStrArr)
{
    reinterpret_cast<::FUN_00a721e0_shell *>((pStrArr))->AppendEffectProperties({});
    char* pkString = ::FUN_00a7d330((const char *)((*reinterpret_cast<const void *const *>(&::g_011f5f6c))));
    unsigned int uiIndex = pStrArr->m_usSize;
    if (uiIndex >= pStrArr->m_usMax)
    {
        reinterpret_cast<::ViewerStrings *>((pStrArr))->SetSize(uiIndex + pStrArr->m_usGrow);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pStrArr))->SetAt(uiIndex, pkString);
}


// @fnv 0x00a75c00
void __cdecl FUN_00a75c00()
{
    static_cast<::NiLight *>(nullptr)->LoadBinary(*(::NiStream *)nullptr);
}

void FUN_00a90010();

// @fnv 0x00a75c10
void FUN_00a75c10()
{
    FUN_00a90010();
}

class CloningProcessA9B3;

class TESObjectDoorController
{
  public:
    static void* operator new(unsigned int n);
};

class FUN_00a71f60
{
  public:
    FUN_00a71f60() throw();
    virtual ~FUN_00a71f60() throw();
    char unk004[0x99];
    bool m_b9d;
    char unk09e[0x52];
};

class CloneA9B3 : public FUN_00a71f60
{
  public:
    CloneA9B3() throw()
    {
        m_b9d = false;
    }
    virtual ~CloneA9B3() throw();

    static void* operator new(unsigned int n)
    {
        return TESObjectDoorController::operator new(n);
    }

    CloneA9B3* FUN_00a9b3d0(CloningProcessA9B3& cloning);
};

// Allocates a new CloneA9B3, calls FUN_00a71ec0 with the instance and cloning argument, then returns it.
// @fnv 0x00a9b3d0
CloneA9B3* CloneA9B3::FUN_00a9b3d0(CloningProcessA9B3& cloning)
{
    CloneA9B3* p = new CloneA9B3;
    reinterpret_cast<::NiDirectionalLight *>(this)->CopyMemberData((::NiDirectionalLight *)(p), (::CloningProcess &)(cloning));
    return p;
}
