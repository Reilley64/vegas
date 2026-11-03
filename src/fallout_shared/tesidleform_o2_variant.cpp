
// src/fallout_shared/tesidleform_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesidleform.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005ff4d0_shell.h"
#include "fnv/decl/FUN_005ffbf0_shell.h"
#include "fnv/decl/FUN_006004f0_shell.h"
#include "fnv/decl/FUN_00600d90.h"
#include "fnv/decl/FUN_00843150_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/IdleFormDetach.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/ValueModifierEffect.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cb000.h"
#include "tesidleform_match_decls.h"
class LowProcess
{
  public:
    TESObjectREFR* GetActiveCombatTarget();
};
extern "C" char* __cdecl strrchr(const char* string, int character);
template <int N> struct EndianSizeTag
{
};
struct FUN_005fea20_shell
{
    void SwapEndian();
};
struct FUN_005ff190_shell
{
    char pad[0x38];
    unsigned char m_0x38;
    void FUN_005ff190(bool set);
};
struct FUN_005ff1d0_shell : public TESIdleForm
{
    bool FUN_005ff1d0();
};
struct FUN_005ff200_shell
{
    unsigned char m_0x38;
    bool IsFlag40Set();
};
struct FUN_005ff220_shell
{
    void SetFlag40(bool bFlag);
};
struct FUN_005ff260_shell
{
    unsigned char m_3e;
    bool FUN_005ff260();
};
struct FUN_005ff4a0_shell : public TESIdleForm
{
    unsigned int FUN_005ff4a0();
};
struct FUN_005ff160_shell : public TESIdleForm
{
    int GetFlagsMasked();
};
struct FUN_00600d90_shell
{
};
struct FUN_00600d70_shell
{
    void FUN_00600d70();
};

// FUN_005ff880 : 8-byte MSVC this-adjusting (virtual) thunk.
//     sub ecx, 0x18 ; jmp FUN_005fe130
//
// MSVC emits such a stub in the vtable of a class that inherits the same
// virtual slot through two bases: the slot of the second base holds a tiny
// stub that moves `this` back onto the complete object (sub ecx, size of the
// primary base) and tail-jumps to the implementation.
//
// The subtracted offset is therefore the size of the primary base: a vtable
// pointer plus 5 int members (4 + 20 = 0x18 bytes).  Both bases declare the
// same virtual function; the derived class redeclares it and defines only its
// constructor, which is what makes the compiler emit the vtables and the
// adjusting thunk.
struct IdlePrimaryBase
{
    virtual void FUN_005ff880();
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};

struct IdleSecondaryBase
{
    virtual void FUN_005ff880();
};

struct IdleDerived : IdlePrimaryBase, IdleSecondaryBase
{
    IdleDerived();
// @fnv 0x005ff880
    virtual void FUN_005ff880();
};

IdleDerived::IdleDerived()
{}
