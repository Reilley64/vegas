// fallout_shared/tesscriptvariable.cpp: SL_standin, Rec (6 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00501c10_cls.h"
#include "fnv/decl/T2870.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00472000.h"
#include "tesscriptvariable_decls.h"
#include "TESFile.h"
#include "ScriptVariableInfo.h"

// Reads a 24-byte chunk from the file when its chunk ID matches, then converts endianness if required.
// @fnv 0x005e2a20
void ScriptVariableInfo::Load(TESFile* file)
{
    if (file && ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x44534c53)
    {
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(this), 24);
        if (file->IsEndianConversionRequired())
            reinterpret_cast<::T2870 *>((reinterpret_cast<ScriptVariableEndian*>(this)))->FUN_005e2870();
    }
}

struct SL_standin
{
    SL_standin* FUN_005ac150(SL_standin* apCopy);
};
// Copies the byte at offset 0x10, the uint at offset 0, and the double at offset 8 from apCopy into this, then returns this.
// @fnv 0x005ac150
SL_standin* SL_standin::FUN_005ac150(SL_standin* apCopy)
{
    *((char*)this + 0x10) = *((char*)apCopy + 0x10);
    *(unsigned int*)this = *(unsigned int*)apCopy;
    *(double*)((char*)this + 8) = *(double*)((char*)apCopy + 8);
    return this;
}

// Zeroes the object's first field, sets the double at offset 0x8 to 0.0, clears the bool at 0x10, and returns the object.
// @fnv 0x005e28e0
ScriptLocalVariable* __fastcall FUN_005e28e0(ScriptLocalVariable* apObject)
{
    *(unsigned int*)((char*)apObject + 0x0) = 0;
    *(double*)((char*)apObject + 0x8) = 0.0;
    *(bool*)((char*)apObject + 0x10) = false;
    return apObject;
}

struct Dummy00501c30
{
    bool FUN_00501c30(const char*);
};

struct FUN_005e29a0_shell
{
    void* m_p;
    double m_iFourthElementInteger;
    unsigned char m_kPointB;
    char m_pAuxiliaryObject[3];
    Dummy00501c30 m_dum;
    bool FUN_005e29a0(FUN_005e29a0_shell* other);
};

// @fnv 0x005e29a0
bool FUN_005e29a0_shell::FUN_005e29a0(FUN_005e29a0_shell* other)
{
    if (!other)
        return true;
    if (m_kPointB != other->m_kPointB)
        return true;
    if (m_p != other->m_p)
        return true;
    if (m_iFourthElementInteger != other->m_iFourthElementInteger)
        return true;
    if (((Dummy00501c30*)((char*)this + 0x18))->FUN_00501c30((const char*)other + 0x18))
        return true;
    return false;
}

template <int N> struct EndianSizeTag
{
    char v;
};


struct FUN_00414220_shell
{
    void FUN_00414220();
};

// @fnv 0x00414220
void FUN_00414220_shell::FUN_00414220()
{
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 4));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 8));
    ::FUN_00401080((int *)(unsigned char *)((unsigned char*)this + 12));
}

namespace fnv_005e2910 {
struct FUN_005e28e0
{
    int v;
    FUN_005e28e0();
};
struct FUN_004037b0
{
    int a, b;
    FUN_004037b0();
    ~FUN_004037b0();
    FUN_004037b0& operator=(const FUN_004037b0& o)
    {
        return (*(::fnv_005e2910::FUN_004037b0 *)(reinterpret_cast<::FUN_00501c10_cls *>(this)->CallAndReturnSelf((int)&(o))));
    }
};
struct Rec
{
    FUN_005e28e0 m0;
    int unk04;
    double d8;
    char c10;
    char pad11;
    char pad12;
    char pad13;
    int unk14;
    FUN_004037b0 m18;
    Rec(const Rec& o);
};
// Copy-constructs Rec by copying m0.v, d8, c10, and m18 from the source Rec.
// @fnv 0x005e2910
Rec::Rec(const Rec& aRec)
{
    m0.v = aRec.m0.v;
    d8 = aRec.d8;
    c10 = aRec.c10;
    reinterpret_cast<::FUN_00501c10_cls *>(&(m18))->CallAndReturnSelf((int)&(aRec.m18));
}
}  // namespace fnv_005e2910
