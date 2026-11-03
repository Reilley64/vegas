// src/gamebryo2.2/corelibs/nimain/niscreenelements_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/niscreenelements.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_0043b370_cls.h"
#include "fnv/decl/FUN_00a89760_cls.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00a74690__FUN_00a74690_shell.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a74000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109e000.h"
#include "fnv/symbols_011f5000.h"
#include "niscreenelements_flags.h"


// @fnv 0x00a87800
void* __cdecl FUN_00a87800()
{
    return &(*reinterpret_cast<void * *>(&::g_011f5b48));
}


struct NiScreenElements
{
    void* m_pVftable;
    NiScreenElements* __thiscall FUN_00a87830(unsigned int flags);
};

// @fnv 0x00a87830
NiScreenElements* __thiscall NiScreenElements::FUN_00a87830(unsigned int flags)
{
    m_pVftable = (void*)0x0109e984;
    reinterpret_cast<::FUN_00a89760_cls *>(this)->FUN_00a89760_cls::~FUN_00a89760_cls();
    if (flags & 1)
        ::FUN_00aa1460(this, 0xc4);
    return this;
}

namespace fnv_00a878b0 {
struct StrArr
{
    char pad0[8];
    unsigned short s8;
    unsigned short sa;
    char padC[2];
    unsigned short se;
};
struct BaseCls
{
};
struct MyTarg : BaseCls
{
    void FUN_00a878b0(StrArr*);
};
// @fnv 0x00a878b0
void MyTarg::FUN_00a878b0(StrArr* pkStrings)
{
    reinterpret_cast<::fnv_00a74690::FUN_00a74690_shell *>(this)->FUN_00a74690((::fnv_00a74690::StrArr *)(pkStrings));
    char* tmp = ::FUN_00a7d330((*reinterpret_cast<char * *>(&::g_011f5b48)));
    unsigned int sz = pkStrings->sa;
    if (sz >= pkStrings->s8)
        reinterpret_cast<::ViewerStrings *>((pkStrings))->SetSize(pkStrings->se + sz);
    reinterpret_cast<::fnv_00b5c7d0::StrArr *>((pkStrings))->SetAt(sz, tmp);
}
}  // namespace fnv_00a878b0

class FUN_00a74480
{
  public:
    void* m_pVftable;
    FUN_00a74480(unsigned int flags);
};
class FUN_00a87810 : public FUN_00a74480
{
  public:
    FUN_00a87810(unsigned int flags);
};
// @fnv 0x00a87810
FUN_00a87810::FUN_00a87810(unsigned int flags) : FUN_00a74480(flags)
{
    m_pVftable = &(*reinterpret_cast<char *>((void *)&::DAT_0109e984));
}

struct ChildBase
{
    virtual void v00();

    int m_i04;

    ChildBase() throw();
};

struct ChildObject : ChildBase
{
    int m_i008;
    int m_i00c;
    int m_i010;
    int m_i014;
    int m_i018;
    int m_i01c;
    int m_i020;
    int m_i024;
    int m_i028;
    int m_i02c;
    int m_i030;
    int m_i034;
    int m_i038;
    int m_i03c;
    int m_i040;
    int m_i044;
    int m_i048;
    int m_i04c;
    int m_i050;
    int m_i054;
    int m_i058;
    int m_i05c;
    int m_i060;
    int m_i064;
    int m_i068;
    int m_i06c;
    int m_i070;
    int m_i074;
    int m_i078;
    int m_i07c;
    int m_i080;
    int m_i084;
    int m_i088;
    int m_i08c;
    int m_i090;
    int m_i094;
    int m_i098;
    int m_i09c;
    int m_i0a0;
    int m_i0a4;
    int m_i0a8;
    int m_i0ac;
    int m_i0b0;
    int m_i0b4;
    int m_i0b8;
    int m_i0bc;
    int m_i0c0;

    static void* operator new(unsigned int auiSize) throw();

    ChildObject() throw()
    {}
};

struct FUN_00a87860_cls
{
    ChildObject* FUN_00a87860(void* apArg);
};

// @fnv 0x00a87860
ChildObject* FUN_00a87860_cls::FUN_00a87860(void* apArg)
{
    ChildObject* pChild = new ChildObject();
    ::FUN_00a744c0();
    return pChild;
}
