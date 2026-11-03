
// src/fallout_shared/tesobjectstat_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout_shared/tesobjectstat.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0046dce0_class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "tesobjectstat_load.h"
#include "tesobjectstat_global.h"
#include "tesobjectstat_types_TESObjectSTAT.h"

struct Primary231
{
    virtual void* DestroyIfFlagged(unsigned int);
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
};
struct Secondary231
{
    virtual void* DestroyIfFlagged(unsigned int) = 0;
};
struct FUN_0051b6d0 : Primary231, Secondary231
{
// @fnv 0x0051b6d0
    FUN_0051b6d0();
    void* DestroyIfFlagged(unsigned int);
};
struct Complete231 : FUN_0051b6d0
{
};
void* operator new(unsigned int, void* storage)
{
    return storage;
}
void* Make231(void* storage)
{
    return new (storage) Complete231;
}
