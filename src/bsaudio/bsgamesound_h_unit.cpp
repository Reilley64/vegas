
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the bsgamesound.h header unit.
//
// The original build compiled bsaudio/bsgamesound.h inside an audio
// translation unit. This translation unit plays that role for the matcher
// build: it includes the header unit and references the covered functions
// so the compiler emits their COMDAT bodies the same way the original
// translation unit did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/symbols_00450000.h"
#include "bsgamesound.h"

void BSGameSoundEmitCoveredFunctions()
{
    BSGameSound* sound = 0;
    // Qualified calls: keep the inline bodies in this object file.
    sound->IsPlaying();
    sound->HasStatusFlag0x80000();
    sound->IsPaused();
    sound->GetVolume();
    sound->SetListenerID(0);
}
