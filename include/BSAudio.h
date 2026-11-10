// Source layout: BSAudio. PC corrections are in generate_headers.py.
#ifndef FNV_BSAUDIO_H
#define FNV_BSAUDIO_H

#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/symbols_00453000.h"
#include "layout_support.h"
#include "BSAudioSyncTimer.h"
struct BSAudio
{
  public:
    void** m_ppVirtualMethodTable;             // +0x0
    bool m_bAudioEnabled;        // +0x4
    bool bInitialized;           // +0x5
    bool m_bUseMultipleThreads;  // +0x6
    unsigned char layoutPadding7;
    unsigned int m_uiAudioFlags;  // +0x8
    bool m_bAudioOutputPaused;    // +0xC
    unsigned char layoutPaddingD;
    unsigned short layoutPaddingE;
    BSAudioListener* m_pAudioListener;                                                      // +0x10
    BSAudioSyncTimer m_kAudioBackendData;                                                  // +0x14
    bool___cdecl__unsigned_int__char___unsigned_int___void___* m_pfnReadAudioData;          // +0x20
    bool___cdecl__const_char___char___unsigned_int___void___* m_pfnReadAudioFile;           // +0x24
    bool___cdecl__char__* m_pfnIsAudioFileAvailable;                                        // +0x28
    unsigned_int___cdecl__BSSoundHandle___void___unsigned_int__* m_pfnGetSoundHandleValue;  // +0x2C
    void___cdecl___* m_pfnInitializeAudio;                                                  // +0x30
    void___cdecl___* m_pfnShutdownAudio;                                                    // +0x34
    void SetAudioState(unsigned int);
    SoundPlaybackHandle GetSoundHandleByFormID(unsigned int formID, unsigned int flags);
};
#endif
