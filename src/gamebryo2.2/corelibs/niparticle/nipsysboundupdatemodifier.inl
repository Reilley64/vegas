
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_004a51d0_shell.h"
#include "fnv/symbols_011f6000.h"
#include "nipsysboundupdatemodifier_decls.h"

// @fnv 0x00c2d720
void NiPSysBoundUpdateModifier::SetUpdateSkipCounter(int iUpdateSkip)
{
    m_usUpdateSkip = (short)iUpdateSkip;
    reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(m_pkBounds);
    int iSkip = (short)iUpdateSkip;
    short sNumBounds = iSkip > 1 ? iSkip : 1;
    m_pkBounds = new NiBound[sNumBounds];
    for (int i = 0; i < sNumBounds; ++i) {
        reinterpret_cast<::FUN_004a51d0_shell *>(&(m_pkBounds[i]))->FUN_004a51d0((void *)&(::NiPoint3::ZERO), 0.0f);
    }
}
