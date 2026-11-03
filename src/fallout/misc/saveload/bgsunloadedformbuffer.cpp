
// src/fallout/misc/saveload/bgsunloadedformbuffer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/misc/saveload/bgsunloadedformbuffer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/FUN_0084b750.h"
#include "fnv/decl/FUN_00864520_shell.h"
#include "fnv/decl/SaveLoadFile.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_008647f0__FUN_008647f0_shell.h"
#include "fnv/decl/fnv_008a8150__FUN_008a8150_shell.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_00866000.h"
extern int DAT_0107f494;

struct FUN_0084b4e0_shell
{
    int FUN_0084b4e0(void* arg);
};

// Calls FUN_0084b750 with arg, stores the address of DAT_0107f494 into this, and returns this.
// @fnv 0x0084b4e0
int FUN_0084b4e0_shell::FUN_0084b4e0(void* arg)
{
    new ((void *)this) ::FUN_0084b750((int)(arg));
    *(int*)this = (int)&DAT_0107f494;
    return (int)this;
}

struct BGSSaveLoadFormInfo
{
    int dummy;
};

struct FormInfoRecord
{
    BGSSaveLoadFormInfo FormInfo;
};

struct FormBufferContext
{
    char* pBuffer;
    char* FUN_00866390();
};

unsigned int __cdecl FUN_00845d70(unsigned int);

// If pBuffer is set, computes a size from the header via FUN_00864520 and FUN_00845d70 and returns pBuffer plus that size plus 2; otherwise returns 0.
// @fnv 0x00866390
char* FormBufferContext::FUN_00866390()
{
    FormInfoRecord* punloadedHeader;
    unsigned int isizeTypeSize;
    if (pBuffer)
    {
        punloadedHeader = (FormInfoRecord*)pBuffer;
        isizeTypeSize = FUN_00845d70(((unsigned int)(reinterpret_cast<::FUN_00864520_shell *>((punloadedHeader))->FUN_00864520())));
        return (char*)(pBuffer + isizeTypeSize + 2);
    }
    return 0;
}

typedef unsigned int SIZE_TYPE;


// @fnv 0x00866430
SIZE_TYPE FUN_00866430(void* a)
{
    return ((unsigned int)(reinterpret_cast<::FUN_00864520_shell *>((*(void**)a))->FUN_00864520()));
}

struct FUN_00866450_shell
{
    unsigned int GetAdjustedValue();
};

unsigned int __cdecl FUN_00845d70(unsigned int);

// Calls FUN_00845d70 on the result of FUN_00866430 and returns that value plus 9.
// @fnv 0x00866450
unsigned int FUN_00866450_shell::GetAdjustedValue()
{
    unsigned int result = FUN_00845d70(::FUN_00866430((void *)this));
    return result + 9;
}

struct FUN_008663e0_shell
{
    char* pBuffer;
    unsigned int FUN_008663e0();
};
// @fnv 0x008663e0
unsigned int FUN_008663e0_shell::FUN_008663e0()
{
    unsigned int uiOut;
    if (pBuffer == 0)
        return 0;
    {
        unsigned int uiSize = FUN_00866430(this);
        char* pData = pBuffer + 2;
        uiOut = 0;
        ::ReadValueBySizeType(pData, &uiOut, uiSize);
    }
    return uiOut;
}

void* __cdecl operator new(unsigned int);
unsigned int _data_011c16bc;

struct BGSLoadFormBuffer
{
    unsigned int field00;
    unsigned int field04;
    unsigned int field08;
    unsigned int field0C;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1C;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2C;

    BGSLoadFormBuffer();
};

struct FUN_0084b450_Class
{
    unsigned char FUN_0084b450();
};

struct FUN_00866480_shell : FormBufferContext
{
    BGSLoadFormBuffer* FUN_00866480();
};

// @fnv 0x00866480
BGSLoadFormBuffer* FUN_00866480_shell::FUN_00866480()
{
    SIZE_TYPE esizeType;
    char* padvancedBuffer;
    unsigned int isize;
    unsigned int iposition;
    BGSLoadFormBuffer* ploadFormBuffer;

    ploadFormBuffer = new BGSLoadFormBuffer;
    reinterpret_cast<::fnv_008a8150::FUN_008a8150_shell *>((ploadFormBuffer))->FUN_008a8150(reinterpret_cast<FUN_0084b450_Class*>(this)->FUN_0084b450());
    esizeType = ::FUN_00866430((void *)(this));
    iposition = 2;
    padvancedBuffer = this->pBuffer + 2;
    isize = 0;
    iposition += (*reinterpret_cast<unsigned int(__cdecl*)(void const*, unsigned int*, unsigned int)>(
        &((void (&)(void *, unsigned int *, unsigned int))::ReadValueBySizeType)))(padvancedBuffer, &isize, esizeType);
    reinterpret_cast<::fnv_008647f0::FUN_008647f0_shell *>((ploadFormBuffer))->FUN_008647f0(this->pBuffer, isize + iposition, iposition);
    return ploadFormBuffer;
}

struct FUN_0044ddc0_shell
{
};

struct FUN_00866da0_shell
{
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
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    FUN_0044ddc0_shell** unk50;

    void CallSlotMethod(int index);
};

// @fnv 0x00866da0
void FUN_00866da0_shell::CallSlotMethod(int index)
{
    reinterpret_cast<::Twin_0044ddc0 *>((unk50[index]))->GetName();
}

class Version866
{
  public:

    unsigned char m_ucMajor;
    unsigned char m_ucMinor;
};

class Header866
{
  public:
    Header866();

    unsigned char m_ucMagic0;
    unsigned char m_ucMagic1;
    unsigned char m_ucMagic2;
    unsigned char m_ucMagic3;
    unsigned char m_ucMagic4;
    unsigned char m_ucMagic5;
    unsigned char m_ucMagic6;
    Version866 m_kVersion;
};

class SaveFile866
{
  public:
};


class Buffer866
{
  public:
    char* m_pcData;

    void ReadBuffer(SaveFile866* pkFile);
};

// @fnv 0x008662c0
void Buffer866::ReadBuffer(SaveFile866* pkFile)
{
    unsigned int uiLength_;
    int iExtra;
    Version866* pkVersion2;
    unsigned int uiSize;
    int iFormat2;
    char* pcCur6;
    Header866 kHeader5;

    reinterpret_cast<::SaveLoadFile *>((pkFile))->Read(&kHeader5, 9);
    iFormat2 = reinterpret_cast<::FUN_00864520_shell *>(&(kHeader5.m_kVersion))->FUN_00864520();
    uiLength_ = 0;
    iExtra = ((int)(::ReadSizedUnsignedInt((::SaveLoadFile *)(pkFile), (*(unsigned int *)(&uiLength_)), (::SIZE_TYPE)(iFormat2))));
    uiSize = uiLength_ + iExtra + 2;
    m_pcData = new char[uiSize];
    pcCur6 = m_pcData;
    pkVersion2 = (Version866*)pcCur6;
    pkVersion2->m_ucMinor = kHeader5.m_kVersion.m_ucMinor;
    pkVersion2->m_ucMajor = kHeader5.m_kVersion.m_ucMajor;
    pcCur6 += 2;
    ::WriteTypedValue(pcCur6, uiLength_, iFormat2);
    pcCur6 += iExtra;
    if (uiLength_)
        reinterpret_cast<::SaveLoadFile *>((pkFile))->Read(pcCur6, uiLength_);
}
