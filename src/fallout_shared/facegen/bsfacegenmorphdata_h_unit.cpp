
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the bsfacegenmorphdata.h header unit.
//
// The original build compiled fallout_shared/facegen/bsfacegenmorphdata.h
// inside a fallout_shared translation unit. This translation unit plays
// that role for the matcher build: it includes the header unit and defines
// the covered function's body the same way the original translation unit
// did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_011d5000.h"
#include "BSFaceGenMorphData.h"

const NiRTTI BSFaceGenMorphDataHead::ms_kRTTI{};

// @fnv 0x00661d90
const NiRTTI* BSFaceGenMorphDataHead::GetRTTI() const
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_011d5bb8));
}
