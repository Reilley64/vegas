
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the bsaudiodefines.h header unit.
//
// The original build compiled bsaudio/bsaudiodefines.h inside an audio
// translation unit. This translation unit plays that role for the matcher
// build: it includes the header unit and references the covered functions
// so the compiler emits their bodies the same way the original
// translation unit did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/SndStack70.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00c45000.h"
#include "bsaudiodefines.h"

typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, SoundMessageRecord*> BSSoundMessageList;

void BSAudioDefinesEmitCoveredFunctions()
{
    // Qualified calls: keep the inline bodies in this object file.
    BSAudioDefinition kDebug;
    kDebug = kDebug;
    BSSoundInfo* pInfo = 0;
    BSSoundInfo kCopy(pInfo);
    pInfo->~BSSoundInfo();
    BSSoundMessageList* pList = 0;
    reinterpret_cast<::SndStack70 *>((pList))->FUN_00ae7f90();
}

#include "generated/data/bsaudio/bsaudiodefines_h_unit.inc"
