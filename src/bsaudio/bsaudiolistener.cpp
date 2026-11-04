// bsaudio/bsaudiolistener.cpp: BSAudioListener (2 functions)

#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/symbols_00450000.h"
#include "BSAudioListener.h"

// @fnv 0x00aeab50
void BSAudioListener::SetListenerID(unsigned int argument0)
{
    m_uiListenerFlags = argument0;
}
// @fnv 0x00aeab70
unsigned int BSAudioListener::GetListenerID()
{
    return m_uiListenerFlags;
}
