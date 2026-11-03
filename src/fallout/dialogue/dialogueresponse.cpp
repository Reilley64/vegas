
// src/fallout/dialogue/dialogueresponse.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/dialogue/dialogueresponse.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/ActorMover.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_00616f40_shell.h"
#include "fnv/decl/FUN_00843150_shell.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/TESResponse.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_011de000.h"
struct FUN_0083d420_shell
{
    unsigned short FUN_0083d420();
};

struct S7010
{
};

struct FUN_0083d890_shell : S7010
{
    unsigned int FUN_0083d890();
};
// Sums the sizes returned by two FUN_0083d890 calls plus one each, then adds 8, and returns the total.
// @fnv 0x0083d420
unsigned short FUN_0083d420_shell::FUN_0083d420()
{
    unsigned short result = 0;
    unsigned char b2 = ((unsigned char)(reinterpret_cast<::FUN_0083d890_shell *>(this)->FUN_0083d890()));
    result += (unsigned short)b2 + 1;
    unsigned char b1 = ((unsigned char)(reinterpret_cast<::FUN_0083d890_shell *>((((FUN_0083d420_shell*)((char*)this + 0x10))))->FUN_0083d890()));
    result += (unsigned short)b1 + 1;
    result += 4;
    result += 4;
    return result;
}

// @fnv 0x0083d890
unsigned int FUN_0083d890_shell::FUN_0083d890()
{
    return ((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(this)->FUN_004048e0()));
}

struct TESSaveLoadGame
{
};

struct Flt
{
    operator unsigned int() const;
};

struct FUN_0083d490_shell : FUN_0083d420_shell
{
    void SaveToGame();
};

// Writes two length-prefixed byte blocks from this and this+0x10, then the 4-byte values at offsets 8 and 0xc, to the save game stream.
// @fnv 0x0083d490
void FUN_0083d490_shell::SaveToGame()
{
    unsigned char c1 = ((unsigned char)(reinterpret_cast<::FUN_0083d890_shell *>(this)->FUN_0083d890()));
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&c1, 1);
    if (c1)
        reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0((void*)(unsigned int)((Flt*)this)->operator unsigned int(), c1);
    unsigned char c2 = ((unsigned char)(reinterpret_cast<::FUN_0083d890_shell *>((((FUN_0083d420_shell*)((char*)this + 0x10))))->FUN_0083d890()));
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0(&c2, 1);
    if (c2)
        reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0((void*)(unsigned int)((Flt*)((char*)this + 0x10))->operator unsigned int(), c2);
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0((char*)this + 8, 4);
    reinterpret_cast<::FUN_008579b0_shell *>((g_TESSaveLoadGame))->FUN_008579b0((char*)this + 0xc, 4);
}

struct FUN_0083d1e0_SubA
{
    int unk00;
    int unk04;

    FUN_0083d1e0_SubA();
    ~FUN_0083d1e0_SubA();
};

struct FUN_0083d1e0_SubB
{
    int unk00;
    int unk04;

    FUN_0083d1e0_SubB();
};

struct FUN_0083d1e0
{
    FUN_0083d1e0_SubA m_00;
    int unk08;
    int unk0C;
    FUN_0083d1e0_SubB m_10;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;

    FUN_0083d1e0();
};

// Initializes the object's fields unk08, unk0C, unk18, unk1C, unk20 and unk28 to zero.
// @fnv 0x0083d1e0
FUN_0083d1e0::FUN_0083d1e0()
{
    unk18 = 0;
    unk1C = 0;
    unk08 = 0;
    unk0C = 0;
    unk20 = 0;
    unk28 = 0;
}

struct FUN_0083d280_Obj
{
    int unk00;
    int unk04;

    ~FUN_0083d280_Obj();
};

struct FUN_0083d280_Sub
{
    int unk00;
    int unk04;

    FUN_0083d280_Sub();
    ~FUN_0083d280_Sub();
    FUN_0083d280_Obj Get();
};

struct FUN_0083d280_Src
{
};


struct FUN_0083d280_cls
{
    FUN_0083d280_Sub m_sub00;
    int m_08;
    void* m_0c;
    FUN_0083d280_Sub m_sub10;
    void* m_18;
    int m_1c;
    void* m_20;
    unsigned char m_24;
    int m_28;

    void Set(const FUN_0083d280_Obj& aValue);
    FUN_0083d280_cls(int a1, int a2, int a3, int a4, FUN_0083d280_Src* apSrc);
};

// @fnv 0x0083d280
FUN_0083d280_cls::FUN_0083d280_cls(int aiArg1, int aiArg2, int aiArg3, int aiArg4, FUN_0083d280_Src* apSrc)
{
    if (apSrc != 0)
    {
        FUN_0083d280_Sub tmp;
        reinterpret_cast<::TextString *>(&(tmp))->FUN_004037f0((const char *)(reinterpret_cast<::TESResponse *>((apSrc))->GetDialogueText()), {});
        Set(tmp.Get());
        m_08 = ((unsigned int)(::FUN_00559450((int *)(apSrc))));
        m_0c = reinterpret_cast<::Callees *>((apSrc))->FUN_00726070();
        reinterpret_cast<::FUN_00616f40_shell *>((apSrc))->DispatchOnNextFormType((::TESObject *)(aiArg4), aiArg1, ((unsigned int)(::fnv_0061a310::FindTopicByInfo((::TESTopicInfo *)(aiArg3)))), aiArg3, (int)(&m_sub10));
        m_18 = reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((apSrc))->FUN_007af430();
        m_1c = reinterpret_cast<::ActorMover *>((apSrc))->GetCurrentMoveModeType();
        m_20 = reinterpret_cast<::MagicCaster_shell *>((apSrc))->FUN_0044edb0();
        m_24 = ((unsigned char)(reinterpret_cast<::FUN_00843150_shell *>((apSrc))->FUN_00843150()));
        m_28 = reinterpret_cast<::TESResponse *>((apSrc))->GetResponseID();
    }
    else
    {
        m_18 = 0;
        m_1c = 0;
        m_08 = 0;
        m_0c = 0;
        m_20 = 0;
        m_24 = 1;
        m_28 = 0;
    }
}

namespace fnv_0083d550 {
struct FUN_008579e0_shell
{
};
struct BSStr
{
    char* data;
    unsigned short length, capacity;
};
struct Record
{
    BSStr first;
    unsigned int flags, value;
    BSStr second;
    void FUN_0083d550();
};
// Reads two BSStr fields, flags, and value from g_TESSaveLoadGame via FUN_008579e0, setting empty strings when lengths are zero.
// @fnv 0x0083d550
void Record::FUN_0083d550()
{
    unsigned char firstLength, secondLength;
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0083d550::FUN_008579e0_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&firstLength, 1);
    if (firstLength)
    {
        char firstBuffer[260];
        ::FUN_00403d30(firstBuffer, 0, 260);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0083d550::FUN_008579e0_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(firstBuffer, firstLength);
        reinterpret_cast<::TextString *>(&(first))->FUN_004037f0(firstBuffer, 0);
    }
    else
        reinterpret_cast<::TextString *>(&(first))->FUN_004037f0("", 0);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0083d550::FUN_008579e0_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&secondLength, 1);
    if (secondLength)
    {
        char secondBuffer[260];
        ::FUN_00403d30(secondBuffer, 0, 260);
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0083d550::FUN_008579e0_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(secondBuffer, secondLength);
        reinterpret_cast<::TextString *>(&(second))->FUN_004037f0(secondBuffer, 0);
    }
    else
        reinterpret_cast<::TextString *>(&(second))->FUN_004037f0("", 0);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0083d550::FUN_008579e0_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&flags, 4);
    reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0083d550::FUN_008579e0_shell * *>(&::g_TESSaveLoadGame))))->FUN_008579e0(&value, 4);
}
}  // namespace fnv_0083d550
