
// src/gamebryo2.2/corelibs/nimain/nicolorextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nicolorextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/symbols_00aa1000.h"
#include "fnv/decl/ExtraDataObject.h"
#include "fnv/decl/ExtraDataStrings.h"
#include "fnv/decl/FUN_00a698a0_class.h"
#include "fnv/decl/FUN_00a7b2c0_shell.h"
#include "fnv/decl/FUN_00a7b300_shell.h"
#include "fnv/decl/FUN_00a7b330_shell.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_004a4c90__FUN_004a4c90_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011f5000.h"
struct FUN_00a893b0_shell
{
    void SetValues(int a, int b, int c, int d);
};

// @fnv 0x00a893b0
void FUN_00a893b0_shell::SetValues(int aiValue0, int aiValue1, int aiValue2, int aiValue3)
{
    *(int*)(this + 0xc) = aiValue0;
    *(int*)(this + 0x10) = aiValue1;
    *(int*)(this + 0x14) = aiValue2;
    *(int*)(this + 0x18) = aiValue3;
}


// @fnv 0x00a893f0
void* __cdecl FUN_00a893f0()
{
    return &(*reinterpret_cast<void * *>(&::g_011f5b68));
}

extern void __cdecl _delete(void*, unsigned int);
extern int DAT_0109eccc;

struct NiColorExtraData_shell
{
    NiColorExtraData_shell* Destroy(unsigned int flags);
};

// @fnv 0x00a89560
NiColorExtraData_shell* NiColorExtraData_shell::Destroy(unsigned int flags)
{
    *reinterpret_cast<int**>(this) = &DAT_0109eccc;
    static_cast<::FUN_00a7b300_shell *>(nullptr)->FUN_00a7b300();
    if (flags & 1)
        _delete(this, 0x1c);
    return this;
}

struct NiStream;

struct NiStream;
class NiExtraData
{
  public:
    NiExtraData();
    virtual ~NiExtraData();
public:
    void LoadBinary(::NiStream &);
};

struct NiStream;
struct RgbaColor
{
    RgbaColor();
public:
    char *ToString(const char *);
public:
    void LoadBinary(::NiStream &);
};

struct NiColorExtraData : NiExtraData
{
    unsigned char _pad[8];
    RgbaColor m_kPrimaryColor;
    void FUN_00a893d0(NiStream& kStream);
};

// @fnv 0x00a893d0
void NiColorExtraData::FUN_00a893d0(NiStream& kStream)
{
    reinterpret_cast<::FUN_00a7b2c0_shell *>(this)->FUN_00a7b2c0(kStream);
    reinterpret_cast<::FUN_00a698a0_class *>(&(m_kPrimaryColor))->FUN_00a698a0((void *)&(kStream));
}

struct NiColor
{
    float r, g, b;
    void LoadBinary(NiStream& kStream);
};

struct NiStream
{
    unsigned char _pad[0xd8];
    unsigned int m_uiNifVersion;
};

struct NiColorA_LoadBinary_helper
{
};

struct NiExtraData_LoadBinary_helper
{
};

struct FUN_00a894f0_shell : NiColorExtraData
{
    void FUN_00a894f0(NiStream& kStream);
};

// @fnv 0x00a894f0
void FUN_00a894f0_shell::FUN_00a894f0(NiStream& kStream)
{
    reinterpret_cast<::NiExtraData *>((((NiExtraData_LoadBinary_helper*)this)))->LoadBinary(kStream);
    if (kStream.m_uiNifVersion < 0x0500000e)
    {
        NiColor kTmpColor;
        kTmpColor.r = 0.0f;
        kTmpColor.g = 0.0f;
        kTmpColor.b = 0.0f;
        kTmpColor.LoadBinary(kStream);
        float* pColor = (float*)&m_kPrimaryColor;
        pColor[0] = kTmpColor.r;
        pColor[1] = kTmpColor.g;
        pColor[2] = kTmpColor.b;
        pColor[3] = 1.0f;
    }
    else
    {
        reinterpret_cast<::RgbaColor *>((((NiColorA_LoadBinary_helper*)&m_kPrimaryColor)))->LoadBinary(kStream);
    }
}

class A89400CloningProcess;

class A89400ColorA
{
  public:
    float r;
    float g;
    float b;
    float a;

    A89400ColorA() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}

};

class A89400ExtraData
{
  public:
    A89400ExtraData() throw();
    virtual ~A89400ExtraData();

    void CopyMemberData(A89400ExtraData* pkDest, A89400CloningProcess& kCloning);

    unsigned int m_uiRefCount;
    char* m_kName;
};

class A89400ColorExtraData : public A89400ExtraData
{
  public:
    __forceinline A89400ColorExtraData() throw()
    {
        m_kFogTint = (*reinterpret_cast<const ::A89400ColorA *>(&::DAT_011a9bd0));
    }
    virtual ~A89400ColorExtraData();

    void CopyMemberData(A89400ColorExtraData* pkDest, A89400CloningProcess& kCloning)
    {
        reinterpret_cast<::FUN_00a7b330_shell *>(this)->FUN_00a7b330((::NiBinaryExtraData *)(pkDest), (::CloningProcess *)&(kCloning));
        pkDest->m_kFogTint = m_kFogTint;
    }
    A89400ColorExtraData* FUN_00a89400(A89400CloningProcess& kCloning);

    A89400ColorA m_kFogTint;
};

// @fnv 0x00a89400
A89400ColorExtraData* A89400ColorExtraData::FUN_00a89400(A89400CloningProcess& kCloning)
{
    A89400ColorExtraData* pkDest = new A89400ColorExtraData;
    CopyMemberData(pkDest, kCloning);
    return pkDest;
}

struct S_00a89590_Member
{
    int unk00;
    int unk04;
    int unk08;
};

struct S_00a89590
{
    int unk00;
    int unk04;
    int unk08;
    S_00a89590_Member m_unk0c;
    bool FUN_00a89590(S_00a89590* other);
};

// @fnv 0x00a89590
bool S_00a89590::FUN_00a89590(S_00a89590* other)
{
    if (!other)
        return false;
    if (reinterpret_cast<::fnv_004a4c90::FUN_004a4c90_shell *>(&(m_unk0c))->FUN_004a4c90(&other->m_unk0c))
        return false;
    return true;
}


struct StreamShell
{
    unsigned char unk0[8];
    unsigned short m_usSize;
    unsigned short m_usPos;
    unsigned short m_usHold;
    unsigned short m_usAdd;

};


struct NameSink
{
};

class ClaimCls
{
    unsigned char unk0[0xc];
    NameSink m_sink;

  public:
    void WriteColorToStream(StreamShell& kStream);
};

// Writes a pointer obtained from g_011f5b68 and the result of ToString("Color = ") into kStream, growing the stream when its position reaches its size.
// @fnv 0x00a895c0
void ClaimCls::WriteColorToStream(StreamShell& kStream)
{
    reinterpret_cast<::ExtraDataStrings *>((&kStream))->FUN_00a7b580({});
    void* p = ((void *)(::FUN_00a7d330((const char *)((*reinterpret_cast<void * *>(&::g_011f5b68))))));
    unsigned int uiPos = kStream.m_usPos;
    unsigned int uiSize = kStream.m_usSize;
    if (uiPos >= uiSize)
    {
        reinterpret_cast<::ViewerStrings *>(&(kStream))->SetSize(uiPos + kStream.m_usAdd);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(kStream))->SetAt(uiPos, (*(char * *)(&p)));
    p = ((void *)(reinterpret_cast<::RgbaColor *>(&(m_sink))->ToString("Color = ")));
    uiPos = kStream.m_usPos;
    uiSize = kStream.m_usSize;
    if (uiPos >= uiSize)
    {
        reinterpret_cast<::ViewerStrings *>(&(kStream))->SetSize(uiPos + kStream.m_usAdd);
    }
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>(&(kStream))->SetAt(uiPos, (*(char * *)(&p)));
}

#include <stddef.h>
struct NiExtraData_StandIn
{
    virtual ~NiExtraData_StandIn();
};


extern int DAT_0109eccc;

// Obtains a 0x1c byte block, calls a method on it, writes a global pointer and four global values, and returns it.
// @fnv 0x00a89490
unsigned int* __cdecl FUN_00a89490()
{
    unsigned int* ptr = (unsigned int*)FUN_00aa13e0(0x1c);

    if (ptr != NULL)
    {
        reinterpret_cast<::ExtraDataObject *>((((NiExtraData_StandIn*)ptr)))->FUN_00a7b2e0();

        ptr[0] = (uintptr_t)&DAT_0109eccc;

        float f[4];
        f[0] = 0.0f;
        f[1] = 0.0f;
        f[2] = 0.0f;
        f[3] = 0.0f;

        volatile float* vf = (volatile float*)&ptr[3];
        vf[0] = f[0];
        vf[1] = f[1];
        vf[2] = f[2];
        vf[3] = f[3];

        ptr[3] = (*reinterpret_cast<int *>(&::DAT_011a9bd0));
        ptr[4] = DAT_011a9bd4;
        ptr[5] = DAT_011a9bd8;
        ptr[6] = DAT_011a9bdc;

        return ptr;
    }

    return NULL;
}
