
// src/havok/common/base/container/string/hkstring_od_oy_noo2_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /GS /EHsc /Gy /Oy- (unit src/havok/common/base/container/string/hkstring.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/base/container/string/hkstring.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstring.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "fnv/decl/B6266F0Array.h"
#include "fnv/symbols_00c85000.h"
#include "fnv/symbols_00cb1000.h"
extern "C" void __cdecl FUN_00ecc7b0(char* dest, const char* src, int count);
void __cdecl FUN_00ec8d33(int a, int b, int c);
struct BSAudio;
struct UnkRet
{
    void* p;
};
struct UnkHolder
{
};
double __cdecl FUN_00ecdf2d(unsigned int value, int mode);
float __cdecl ConvertToFloat(unsigned int value);
class hkBool
{
  public:
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};
hkBool StartsWith(const char* str, const char* prefix);
bool* __cdecl EndsWith(bool* result, const char* text, const char* suffix);
class NineIntegerRecord
{
  public:
    NineIntegerRecord();
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
struct BSAudio
{
    int unk00, unk04, unk08, unk0c;
    int unk10;
};
void __cdecl FUN_00cb13e0(int a, int b);
int __cdecl FUN_00cb1390(const char* str, char c);
struct S_00cb1410_Buf
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
    S_00cb1410_Buf();
};

struct Cls;

struct BoolGuard
{
    bool flag;
    int Get(Cls* owner, int value);
};

struct Cls
{
    void FUN_00626420(int value);
};

// @fnv 0x00626420
void Cls::FUN_00626420(int value)
{
    BoolGuard g = {};
    reinterpret_cast<::B6266F0Array *>(this)->FUN_006266f0((::B6266F0Allocator *)(g.Get(this, value)), *(const ::B6266F0Entry *)nullptr);
}
