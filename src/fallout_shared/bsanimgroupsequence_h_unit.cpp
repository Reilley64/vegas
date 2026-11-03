
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the bsanimgroupsequence.h header unit.
//
// The original build compiled fallout_shared/bsanimgroupsequence.h inside a
// fallout_shared translation unit. This translation unit plays that role for
// the matcher build: it includes the header unit and defines the covered
// function's body the same way the original translation unit did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_011c7000.h"
#include "BSAnimGroupSequence.h"

const NiRTTI BSAnimGroupSequence::ms_kRTTI{};

// @fnv 0x0049bb10
const NiRTTI* BSAnimGroupSequence::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011c7d74));
}
