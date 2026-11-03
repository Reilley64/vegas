#include <cstdint>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005be5c0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_008579b0_shell.h"
#include "fnv/decl/FUN_008579e0_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00968670__FUN_00968670_shell.h"
#include "fnv/symbols_00421000.h"
#include "fnv/symbols_011de000.h"
// src/fallout_shared/tesvalueform.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/tesvalueform.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Base1
{
    virtual void FUN_004f9c90();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
};
struct Base2
{
    virtual void FUN_004f9c90();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x004f9c90
    virtual void FUN_004f9c90();
};
Derived::Derived()
{}

namespace fnv_004f9ca0 {
// sub ecx,0x74; jmp FUN_0051b020 == MSVC adjustor thunk: Derived overrides a virtual that both bases declare;
// the secondary base's vtable gets a thunk moving this back by sizeof(PrimaryBase) = 0x74.
struct PrimaryBase
{
    virtual void FUN_004f9ca0();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
};

struct SecondaryBase
{
    virtual void FUN_004f9ca0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004f9ca0
    virtual void FUN_004f9ca0();
};

Derived::Derived()
{}
}  // namespace fnv_004f9ca0

namespace fnv_004f9cc0 {
// sub ecx,0x74; jmp target == MSVC adjustor thunk: Derived overrides a virtual shared by two bases,
// the secondary base's thunk moves `this` back by sizeof(PrimaryBase) == 0x74.
struct PrimaryBase
{
    virtual void FUN_004f9cc0();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
};

struct SecondaryBase
{
    virtual void FUN_004f9cc0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x004f9cc0
    virtual void FUN_004f9cc0();
};

Derived::Derived()
{}
}  // namespace fnv_004f9cc0

namespace fnv_00503bc0 {
struct Base1
{
    virtual void FUN_00503bc0();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};
struct Base2
{
    virtual void FUN_00503bc0();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x00503bc0
    virtual void FUN_00503bc0();
};
Derived::Derived()
{}
}  // namespace fnv_00503bc0

namespace fnv_00504fe0 {
struct PrimaryBase
{
    virtual void FUN_00504fe0();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};

struct SecondaryBase
{
    virtual void FUN_00504fe0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00504fe0
    virtual void FUN_00504fe0();
};

Derived::Derived()
{}
}  // namespace fnv_00504fe0

// FUN_005144f0 : MSVC this-adjusting thunk  (sub ecx, 0x58 ; jmp <impl>)
struct A1_005144f0
{
    A1_005144f0();
    virtual void FUN_005144f0();
    char pad[0x54];
};
struct A2_005144f0
{
    A2_005144f0();
    virtual void FUN_005144f0();
};
struct Own_005144f0 : A1_005144f0, A2_005144f0
{
    Own_005144f0();
    virtual void key_fn();
// @fnv 0x005144f0
    void FUN_005144f0();
};
Own_005144f0::Own_005144f0()
{}
void Own_005144f0::key_fn()
{}
Own_005144f0* make_005144f0()
{
    static Own_005144f0 o;
    return &o;
}

namespace fnv_00515410 {
// sub ecx,0x84; jmp target == MSVC adjustor thunk: Derived overrides a virtual shared by both bases; the second base sits at +0x84.
struct PrimaryBase
{
    virtual void FUN_00515410();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
};

struct SecondaryBase
{
    virtual void FUN_00515410();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00515410
    virtual void FUN_00515410();
};

Derived::Derived()
{}
}  // namespace fnv_00515410

namespace fnv_00515420 {
// sub ecx,0x84; jmp FUN_00515290  ==  MSVC adjustor thunk for the second base's vtable.
// PrimaryBase is vptr + 32 int fields = 0x84 bytes.
struct PrimaryBase
{
    virtual void FUN_00515420();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
};

struct SecondaryBase
{
    virtual void FUN_00515420();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00515420
    virtual void FUN_00515420();
};

Derived::Derived()
{}
}  // namespace fnv_00515420

// FUN_005160d0 - MSVC 2008 adjustor thunk for a *secondary* base.
//
// The original code is exactly:
//     005160d0  83 e9 58        sub ecx, 0x58
//     005160d3  e9 98 ff ff ff  jmp 0x00516070
//
// This is the "virtual adjustor thunk" that MSVC 2008 emits for the
// per-base vftable of a derived class which re-declares (overrides) a
// virtual function that one of its secondary bases also declares: the
// thunk moves `this` back from the secondary base sub-object to the start
// of the complete object and tail-jumps to the derived implementation.
//
// The secondary base sub-object lives 0x58 bytes into the derived object,
// so the primary base has to be exactly 0x58 bytes long.  The overriding
// implementation is only DECLARED here, so the jump target stays an
// unresolved external and the checker resolves the relocation from the
// original image.  The thunk's own mangled name carries the tag, which
// satisfies the canary.

struct ThunkPrimaryBase
{
    ThunkPrimaryBase();
    virtual void FUN_005160d0(int flag, int value);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
};

struct ThunkSecondaryBase
{
    ThunkSecondaryBase();
// @fnv 0x005160d0
    virtual void FUN_005160d0(int flag, int value);
};

struct ThunkDerived : public ThunkPrimaryBase, public ThunkSecondaryBase
{
    ThunkDerived();
    virtual void FUN_005160d0(int flag, int value);  // declared, never defined
};

ThunkPrimaryBase::ThunkPrimaryBase()
{}
ThunkSecondaryBase::ThunkSecondaryBase()
{}
ThunkDerived::ThunkDerived() : ThunkPrimaryBase(), ThunkSecondaryBase()
{}

// Adjustor thunk: the secondary-base (+0x58) entry for an override defined on the derived class.

class X160E0Primary
{
  public:
    virtual void FUN_005160e0(unsigned int uiValue);
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
    int unk50;
    int unk54;
};

class X160E0Secondary
{
  public:
    virtual void FUN_005160e0(unsigned int uiValue);
};

class X160E0Derived : public X160E0Primary, public X160E0Secondary
{
  public:
    X160E0Derived();
// @fnv 0x005160e0
    virtual void FUN_005160e0(unsigned int uiValue);
};

X160E0Derived::X160E0Derived()
{}

// FUN_0051a660 : MSVC this-adjusting thunk  (sub ecx, 0x7c ; jmp <impl>)
struct A1_0051a660
{
    A1_0051a660();
    virtual void FUN_0051a660();
    char pad[0x78];
};
struct A2_0051a660
{
    A2_0051a660();
    virtual void FUN_0051a660();
};
struct Own_0051a660 : A1_0051a660, A2_0051a660
{
    Own_0051a660();
    virtual void key_fn();
// @fnv 0x0051a660
    void FUN_0051a660();
};
Own_0051a660::Own_0051a660()
{}
void Own_0051a660::key_fn()
{}
Own_0051a660* make_0051a660()
{
    static Own_0051a660 o;
    return &o;
}

// sub ecx,0x7c; jmp FUN_0051a5d0: adjustor thunk from multiple inheritance.
// PrimaryBase is vptr + 30 dwords = 0x7c bytes.
struct PrimaryBase
{
    virtual void FUN_0051a670();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
};

struct SecondaryBase
{
    virtual void FUN_0051a670();
};

struct AdjustedObject : PrimaryBase, SecondaryBase
{
    AdjustedObject();
// @fnv 0x0051a670
    virtual void FUN_0051a670();
};

AdjustedObject::AdjustedObject()
{}

// 0x51a690 = VC9 adjustor thunk (sub ecx,0x7c; jmp ?FUN_0051a5a0@...@@QAEXI@Z).
// Recipe: primary base of size 0x7c, secondary base re-declaring the same virtual,
// derived override declared-only, static instance forces both vftables -> thunk comdat.
struct AdjPrim
{
// @fnv 0x0051a690
    virtual void FUN_0051a690();
    int p04;
    int p08;
    int p0C;
    int p10;
    int p14;
    int p18;
    int p1C;
    int p20;
    int p24;
    int p28;
    int p2C;
    int p30;
    int p34;
    int p38;
    int p3C;
    int p40;
    int p44;
    int p48;
    int p4C;
    int p50;
    int p54;
    int p58;
    int p5C;
    int p60;
    int p64;
    int p68;
    int p6C;
    int p70;
    int p74;
    int p78;
};
struct AdjB1
{
    virtual void FUN_0051a690();
};
struct AdjTO : AdjPrim, AdjB1
{
    virtual void FUN_0051a690();
};
static AdjTO g_adjThunk;

// FUN_00525c10: MSVC adjustor thunk (sub ecx,0x84; jmp target) emitted for a virtual that
// lives in the first base but is reached through the second base's vtable slot.
// 0x84 = sizeof(AdjustPrimaryBase) = vptr + 32 int fields.
struct AdjustPrimaryBase
{
    virtual void FUN_00525c10();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
};

struct AdjustSecondaryBase
{
    virtual void FUN_00525c10();
};

struct AdjustDerived : AdjustPrimaryBase, AdjustSecondaryBase
{
    AdjustDerived();
// @fnv 0x00525c10
    virtual void FUN_00525c10();
};

AdjustDerived::AdjustDerived()
{}

// sub ecx,0x84; jmp FUN_00523020 == MSVC adjustor thunk (multiple inheritance).
struct AdjPrimaryBase
{
    virtual void FUN_00525c20();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
};

struct AdjSecondaryBase
{
    virtual void FUN_00525c20();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00525c20
    virtual void FUN_00525c20();
};

AdjDerived::AdjDerived()
{}

// Adjustor thunk: the secondary-base (+0x84) vtable entry for an override defined on the derived class.

class C5C30Primary
{
  public:
    virtual void FUN_00525c30(unsigned int uiA, unsigned int uiB);
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
};

class C5C30Secondary
{
  public:
    virtual void FUN_00525c30(unsigned int uiA, unsigned int uiB);
};

class C5C30Derived : public C5C30Primary, public C5C30Secondary
{
  public:
    C5C30Derived();
// @fnv 0x00525c30
    virtual void FUN_00525c30(unsigned int uiA, unsigned int uiB);
};

C5C30Derived::C5C30Derived()
{}

struct BF50Primary
{
    virtual void vfunc00();
    virtual void FUN_0059bf50(unsigned int a, unsigned int b);

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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};

struct BF50Secondary
{
    virtual void FUN_0059bf50(unsigned int a, unsigned int b);
};

struct BF50Object : BF50Primary, BF50Secondary
{
    BF50Object();

// @fnv 0x0059bf50
    virtual void FUN_0059bf50(unsigned int a, unsigned int b);
};

BF50Object::BF50Object()
{}

// FUN_0059bf60 : MSVC this-adjusting thunk  (sub ecx, 0x78 ; jmp <impl>)
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them and the compiler emits one adjustor thunk per
// secondary base.  The first base is padded to 120 bytes so the second
// base lands at +0x78.  The override is DECLARED ONLY, so this thunk
// is the single defined function symbol carrying the name FUN_0059bf60; a defined
// key function makes the vftable that references the thunk be emitted here.
struct A1_0059bf60
{
    A1_0059bf60();
    virtual void FUN_0059bf60();
    char pad[0x74];
};

struct A2_0059bf60
{
    A2_0059bf60();
// @fnv 0x0059bf60
    virtual void FUN_0059bf60();
};

struct Own_0059bf60 : A1_0059bf60, A2_0059bf60
{
    Own_0059bf60();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void FUN_0059bf60();    // the shared override - declared only
};

Own_0059bf60::Own_0059bf60()
{}
void Own_0059bf60::key_fn()
{}

Own_0059bf60* make_0059bf60()
{
    static Own_0059bf60 o;
    return &o;
}

namespace fnv_0059bf80 {
struct Base1
{
    virtual void FUN_0059bf80();
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
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};
struct Base2
{
    virtual void FUN_0059bf80();
};
struct Derived : Base1, Base2
{
    Derived();
// @fnv 0x0059bf80
    virtual void FUN_0059bf80();
};
Derived::Derived()
{}
}  // namespace fnv_0059bf80

struct S_0059bf90_Base1
{
    virtual void FUN_0059bf90();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
};

struct S_0059bf90_Base2
{
    virtual void FUN_0059bf90();
};

struct S_0059bf90_Derived : S_0059bf90_Base1, S_0059bf90_Base2
{
    S_0059bf90_Derived();
// @fnv 0x0059bf90
    virtual void FUN_0059bf90();
};

S_0059bf90_Derived::S_0059bf90_Derived()
{}

struct BaseFormComponent
{
    virtual ~BaseFormComponent();
};

struct TESValueForm : BaseFormComponent
{
    void SetFormValue(unsigned int);
    void FUN_0048e7f0(BaseFormComponent*);
};

// @fnv 0x0048e7f0
void TESValueForm::FUN_0048e7f0(BaseFormComponent* component)
{
    TESValueForm* form = dynamic_cast<TESValueForm*>(component);
    if (!form)
        return;
    SetFormValue(((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((form))->FUN_00726070())));
}

namespace fnv_0048e9b0 {
struct TESValueForm
{
    unsigned short FUN_0048e9b0(unsigned int aiFlags);
};

// @fnv 0x0048e9b0
unsigned short TESValueForm::FUN_0048e9b0(unsigned int aiFlags)
{
    unsigned short isize = 0;
    if (aiFlags & 2)
        isize += 4;
    return isize;
}
}

// namespace fnv_0048e9b0

namespace fnv_0048e9e0 {
struct TESSaveLoadGame
{
};

struct TESValueForm
{
    void FUN_0048e9e0(unsigned int flags);
};

// @fnv 0x0048e9e0
void TESValueForm::FUN_0048e9e0(unsigned int flags)
{
    if (flags & 2)
        reinterpret_cast<::FUN_008579b0_shell *>(((*reinterpret_cast<::fnv_0048e9e0::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579b0(reinterpret_cast<char*>(this) + 4, 4);
}
}

// namespace fnv_0048e9e0

namespace fnv_0048ea10 {
struct TESSaveLoadGame
{
};

struct TESValueForm
{
    void FUN_0048ea10(unsigned int a, std::uintptr_t b);
};

// @fnv 0x0048ea10
void TESValueForm::FUN_0048ea10(unsigned int a, std::uintptr_t b)
{
    if (a & 2)
        reinterpret_cast<::FUN_008579e0_shell *>(((*reinterpret_cast<::fnv_0048ea10::TESSaveLoadGame * *>(&::g_TESSaveLoadGame))))->FUN_008579e0((char*)this + 4, 4);
}
}

// namespace fnv_0048ea10

namespace fnv_0048ea40 {
struct FormChangeMask
{
    int flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(int);
};
struct BGSSaveFormBuffer
{
};
struct TESValueForm
{
    void FUN_0048ea40(BGSSaveFormBuffer*);
};
// @fnv 0x0048ea40
void TESValueForm::FUN_0048ea40(BGSSaveFormBuffer* aBuffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_0048ea40::FormChangeMask &)(((BGSLoadFormBuffer*)aBuffer)->GetChangeFlags(2)))->FUN_004280f0(2))
        reinterpret_cast<::FUN_00865e50_shell *>((aBuffer))->FUN_00865e50((char*)this + 4, 4, 0);
}
}

// namespace fnv_0048ea40

struct FormChangeMask
{
    unsigned int flags;
    operator bool() const;
};

struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};

struct FUN_0048ea80_Class
{
    void FUN_0048ea80(BGSLoadFormBuffer* buffer);
};

// @fnv 0x0048ea80
void FUN_0048ea80_Class::FUN_0048ea80(BGSLoadFormBuffer* buffer)
{
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(buffer->GetChangeFlags(2)))->FUN_004280f0(2))
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)((char*)this + 4), 4);
}

struct BaseData
{
};

struct Item
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
    virtual bool v64();
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
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual bool v134();
};

struct Collection
{
    int unk00;
};

struct Holder
{
    int unk00;
    Collection items;
    Item* FUN_00970a20(void*, int);
};

// @fnv 0x00970a20
Item* Holder::FUN_00970a20(void* key, int unused)
{
    Item* current = 0;
    Item* result = 0;
    for (unsigned int index = 0; index < reinterpret_cast<::FUN_005be5c0_shell *>(&(items))->FUN_005be5c0(0); index++)
    {
        result = ((::Item *)(reinterpret_cast<::fnv_00968670::FUN_00968670_shell *>(&(items))->FUN_00968670(index)));
        if (result && !current && !reinterpret_cast<::FUN_00576d30_shell *>((result))->FUN_00576d30())
        {
            Item* actor = 0;
            if (result && result->v64())
                actor = result;
            if (actor)
            {
                void* target = 0;
                if (actor->v134())
                    target = ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((actor))->FUN_007af430()));
                if (target && key == target)
                    current = actor;
                else if (((void *)(::FUN_004216f0((::BaseExtraList *)(((::BaseData *)(reinterpret_cast<::FUN_005d43c0_ *>((actor))->FUN_005d43c0())))))) == key)
                    current = actor;
            }
        }
    }
    return current;
}

struct FUN_0048e840_shell
{
    bool FUN_0048e840(BaseFormComponent* other);
};

// @fnv 0x0048e840
bool FUN_0048e840_shell::FUN_0048e840(BaseFormComponent* other)
{
    TESValueForm* form = dynamic_cast<TESValueForm*>(other);
    if (!form)
        return true;
    if (((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((reinterpret_cast<TESValueForm*>(this)))->FUN_00726070())) != ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Callees *>((form))->FUN_00726070())))
        return true;
    return false;
}
