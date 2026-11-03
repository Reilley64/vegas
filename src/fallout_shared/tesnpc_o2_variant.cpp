
// src/fallout_shared/tesnpc_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesnpc.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/ActorSpellView.h"
#include "fnv/decl/ActorStandIn008a.h"
#include "fnv/decl/B441420Owner.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/BipedAnimWeap.h"
#include "fnv/decl/C42CE30.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/Dummy_00607810.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004169d0_shell.h"
#include "fnv/decl/FUN_0041c930_shell.h"
#include "fnv/decl/FUN_0041ca90.h"
#include "fnv/decl/FUN_0041cb10_shell.h"
#include "fnv/decl/FUN_0041cb70_shell.h"
#include "fnv/decl/FUN_0041d8a0_shell.h"
#include "fnv/decl/FUN_00437bd0_stub.h"
#include "fnv/decl/FUN_00437bf0_shell.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440460_S.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_00462e80_shell.h"
#include "fnv/decl/FUN_00471870_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00472840_impl.h"
#include "fnv/decl/FUN_0047bdd0_shell.h"
#include "fnv/decl/FUN_0047c850.h"
#include "fnv/decl/FUN_0047d800_shell.h"
#include "fnv/decl/FUN_0047ded0_shell.h"
#include "fnv/decl/FUN_0047fb50_shell.h"
#include "fnv/decl/FUN_00480000_shell.h"
#include "fnv/decl/FUN_00480160_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_004870f0_shell.h"
#include "fnv/decl/FUN_00487240_shell.h"
#include "fnv/decl/FUN_00493bb0_Class.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004ac110_shell.h"
#include "fnv/decl/FUN_004bfe50_t.h"
#include "fnv/decl/FUN_004c8220_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00503240_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_00565210_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005f7b50_Class.h"
#include "fnv/decl/FUN_00601800_shell.h"
#include "fnv/decl/FUN_00601c10_shell.h"
#include "fnv/decl/FUN_00602130_shell.h"
#include "fnv/decl/FUN_00602170_shell.h"
#include "fnv/decl/FUN_006031e0_shell.h"
#include "fnv/decl/FUN_00603200_shell.h"
#include "fnv/decl/FUN_00604210_shell.h"
#include "fnv/decl/FUN_00606050_shell.h"
#include "fnv/decl/FUN_00606800_shell.h"
#include "fnv/decl/FUN_00607350_shell.h"
#include "fnv/decl/FUN_00607830_helper.h"
#include "fnv/decl/FUN_00608d80_shell.h"
#include "fnv/decl/FUN_0060b370_shell.h"
#include "fnv/decl/FUN_00613870_Class.h"
#include "fnv/decl/FUN_00619df0_shell.h"
#include "fnv/decl/FUN_0061b320_shell.h"
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/FUN_00634890_shell.h"
#include "fnv/decl/FUN_006727b0_shell.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0087f3d0_shell.h"
#include "fnv/decl/FUN_008ace90_shell.h"
#include "fnv/decl/FUN_00a5a040_Class.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/FUN_00c748d0_C.h"
#include "fnv/decl/FlagSet.h"
#include "fnv/decl/FleeActorEntry.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/HeadNPC.h"
#include "fnv/decl/Header47cb90.h"
#include "fnv/decl/HealthReferenceEntry.h"
#include "fnv/decl/HostActor.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MiddleHighProcess.h"
#include "fnv/decl/ModelCopyView.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S9fb0.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESEnchantableForm.h"
#include "fnv/decl/TESOffsetWorker.h"
#include "fnv/decl/Target.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TeleportableReference.h"
#include "fnv/decl/Thing.h"
#include "fnv/decl/Thing575.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Unk_0097fa10.h"
#include "fnv/decl/VATS.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047d220__ABD_47d220.h"
#include "fnv/decl/fnv_0047f500__FUN_0047f500_shell.h"
#include "fnv/decl/fnv_004817f0__FUN_004817f0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0048cce0__FUN_0048cce0_shell.h"
#include "fnv/decl/fnv_0048d290__FUN_0048d290_shell.h"
#include "fnv/decl/fnv_0048d630__SpellListAccess.h"
#include "fnv/decl/fnv_00496940__FUN_00496940_shell.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/decl/fnv_0057b7c0__Actor57.h"
#include "fnv/decl/fnv_00613c50__FUN_00613c50_C.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_0088c830__ThisC.h"
#include "fnv/decl/fnv_008a7a90__ActorAnimView.h"
#include "fnv/decl/fnv_008a8e50__ActorP_S.h"
#include "fnv/decl/fnv_008b3c30__FUN_008b3c30_shell.h"
#include "fnv/decl/fnv_008bb520__TES.h"
#include "fnv/decl/s428110__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00407000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047f000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004aa000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_00505000.h"
#include "fnv/symbols_00537000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00605000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00643000.h"
#include "fnv/symbols_00648000.h"
#include "fnv/symbols_00649000.h"
#include "fnv/symbols_00652000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_00754000.h"
#include "fnv/symbols_008f2000.h"
#include "fnv/symbols_009a3000.h"
#include "fnv/symbols_00a6e000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011cb000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011cf000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "tesnpc_pc_decls.h"

// Adjustor thunk for FUN_0060c440: "sub ecx, 0xdc; jmp FUN_00601370".
//
// This is the MSVC this-adjusting thunk that the compiler emits for a virtual
// function inherited from a secondary base: it converts the secondary base
// sub-object pointer (this + 0xdc) back into the derived object pointer
// (sub ecx, 0xdc) and tail-jumps to the final overrider.
//
// The subtracted offset is the size of the first base, so the first base is
// laid out as a vtable pointer plus 54 int members (4 + 54 * 4 = 0xdc bytes).
// Both bases declare the same virtual function, the derived class redeclares
// it and only defines its constructor, which is what makes the compiler emit
// the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0060c440();
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
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
};

struct SecondaryBase
{
    virtual void FUN_0060c440();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c440
    virtual void FUN_0060c440();
};

Derived::Derived()
{}

// FUN_0060c450 is a MSVC this-adjusting thunk (adjustor thunk).
//
// The class AdjustorThunkHolder inherits AdjustorSecondaryBase at offset
// 0x7c (the primary base is 0x7c bytes long), and overrides the virtual
// function FUN_0060c450 that AdjustorSecondaryBase declares.  For that
// override the compiler emits a thunk that moves `this` back to the
// secondary base sub-object and jumps to the implementation:
//
//     sub ecx, 0x7c
//     jmp AdjustorThunkHolder::FUN_0060c450
//
// The overriding implementation itself lives in another translation unit,
// so it is only declared here.

struct AdjustorPrimaryBase
{
    virtual void FUN_0060c450();
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
    int unk78;
};

struct AdjustorSecondaryBase
{
    virtual void FUN_0060c450();
};

struct AdjustorThunkHolder : AdjustorPrimaryBase, AdjustorSecondaryBase
{
// @fnv 0x0060c450
    virtual void FUN_0060c450();
    AdjustorThunkHolder();
};

AdjustorThunkHolder::AdjustorThunkHolder()
{}

namespace fnv_0060c460 {
struct PrimaryBase
{
    virtual void FUN_0060c460();
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
    int unk84;
    int unk88;
    int unk8C;
};

struct SecondaryBase
{
    virtual void FUN_0060c460();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c460
    virtual void FUN_0060c460();
};

Derived::Derived()
{}
}  // namespace fnv_0060c460

namespace fnv_0060c470 {
// Adjustor (this-adjusting) thunk for FUN_0060c470:
//     sub ecx, 0x90 ; jmp FUN_00608e00
// MSVC emits such a thunk in the vftable of a class that inherits the same
// virtual from two bases: the thunk converts the secondary base sub-object
// pointer back to the primary base pointer by subtracting the size of the
// primary base (0x90 = 4 byte vptr + 35 int members) and tail jumps to the
// implementation.  Both bases declare the virtual, the derived class
// redeclares it and defines only its constructor, which makes the compiler
// emit the vtables and the adjusting thunk.
struct PrimaryBase
{
    virtual void FUN_0060c470();
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
    int unk84;
    int unk88;
    int unk8C;
};

struct SecondaryBase
{
    virtual void FUN_0060c470();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c470
    virtual void FUN_0060c470();
};

Derived::Derived()
{}
}  // namespace fnv_0060c470

// Adjustor thunk: sub ecx,0x90 ; jmp <base virtual>.
// The primary base occupies 0x90 bytes, so the secondary base sub-object starts
// at +0x90 and the compiler emits an adjustor thunk for the secondary base's
// virtual slot, moving 'this' back onto the secondary base before the jump.
struct AdjPrimaryBase
{
    virtual void FUN_0060c490();
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
    int unk84;
    int unk88;
    int unk8C;
};

struct AdjSecondaryBase
{
    virtual void FUN_0060c490();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x0060c490
    virtual void FUN_0060c490();
};

AdjDerived::AdjDerived()
{}

namespace fnv_0060c4a0 {
// Adjustor (this-adjusting) thunk for FUN_0060c4a0: "sub ecx, 0x7c; jmp FUN_00608e00".
// PrimaryBase is the first base (vptr + 30 int fields = 0x7c bytes); SecondaryBase
// declares the same virtual; Derived derives from both, redeclares the virtual and
// defines only its constructor, so the compiler emits the adjusting thunk.
struct PrimaryBase
{
    virtual void* FUN_0060c4a0(unsigned int flags);
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
    virtual void* FUN_0060c4a0(unsigned int flags);
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x0060c4a0
    virtual void* FUN_0060c4a0(unsigned int flags);
};

Derived::Derived()
{}
}  // namespace fnv_0060c4a0
