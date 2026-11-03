
// src/fallout_shared/tescaravan_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tescaravan.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00489000.h"
#include "tescaravan_decls.h"
class RegionDataEntry
{
  public:
};
class BGSImpactData
{
  public:
};
extern "C" void* memset(void* dst, int val, unsigned int size);

// Adjustor thunk (MSVC this-adjusting thunk for a secondary base sub-object).
// The secondary base sits at offset 0x3c inside the derived object, so the
// thunk rewinds 'this' to the start of the derived object and tail-jumps to
// the overriding implementation.
class PrimaryBase
{
  public:
    virtual void FUN_0059bf40();
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
};

class SecondaryBase
{
  public:
    virtual void FUN_0059bf40();
};

class Derived : public PrimaryBase, public SecondaryBase
{
  public:
// @fnv 0x0059bf40
    virtual void FUN_0059bf40();
    Derived();
};

Derived::Derived()
{}

namespace fnv_0059bf70 {
// Adjustor (this-adjusting) thunk for FUN_0059bf70: "sub ecx, 0x3c; jmp Release".
//
// The thunk is emitted for a virtual function inherited from a secondary base: it moves the
// secondary-base sub-object pointer back to the derived object pointer (sub ecx, 0x3c) and
// tail jumps to the final overrider. The subtracted offset is the size of the primary base,
// so PrimaryBase is laid out as a vtable pointer plus 14 int members (4 + 56 = 0x3c).
// Both bases declare the same virtual function; the derived class redeclares it and defines
// only its constructor, which is what makes the compiler emit the vtables and the thunk.
struct PrimaryBase
{
    virtual void FUN_0059bf70();
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
};

struct SecondaryBase
{
    virtual void FUN_0059bf70();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0059bf70
    virtual void FUN_0059bf70();
};

Derived::Derived()
{}
}  // namespace fnv_0059bf70
