// fallout/misc/bgsmovieplayer_decls.h: declares Direct3DDeviceInterface, NiRenderer, BSAudio, OSGlobals, BGSMoviePlayer
#ifndef FNV_BGSMOVIEPLAYER_DECLS_H
#define FNV_BGSMOVIEPLAYER_DECLS_H


#include <cstdint>
#include "fnv/decl/BSAudio_.h"
#include "fnv/decl/FUN_004dc020_Class.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00ad7230_shell.h"
#include "fnv/decl/FUN_00ec17c0_Class.h"
#include "fnv/decl/FUN_00ec29b0_class.h"
#include "fnv/decl/InputPoller.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/PlaybackContinueState.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/decl/fnv_004e9530__NiRenderer.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004bc000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004de000.h"
#include "fnv/symbols_011de000.h"
class Direct3DDeviceInterface
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual int TestCooperativeLevel();
};

class NiRenderer
{
  public:
    char _pdbpad_1[7];
    char m_spAccum_pad7_pad7[4];
    void* m_pCamera;
    void* m_pActiveRenderTargetGroup;
    char m_acRendererDataB[4];
    char _pdbpad_18[104];
    char m_acRendererDataC[128];
    char m_acRendererDataD[128];
    char m_acRendererDataE[128];
    int m_iRendererState;
    unsigned int m_uiRendererFlags;
    bool m_bRendererFlagA;
    bool m_bRendererFlagB;
    char _pdbpad_20a[118];
};


class BSAudio
{
  public:
    void Update(bool);
    void DisableAudioPlayback();
};

extern unsigned char DAT_011de714;

float FUN_004de0e0();
float FUN_004de0f0();

class HotkeyWheelDisplay;

class HotkeyWheelDisplay
{
  public:
public:
    int SetHotkeyItem(int, int);
};

class OSGlobals
{
  public:
};


class BGSMoviePlayer
{
  public:
    unsigned char layout_00[0x20];
    unsigned char field_20;

    Direct3DDeviceInterface* GetDevice();
    void StartScene();
    void FinishScene();
    void BeginMoviePlayback();
    void EndMoviePlayback();
    uintptr_t GetUptimeMilliseconds();
    unsigned int UpdateInterfaceState();
    unsigned int GetScreenWidthOverride();
    unsigned int GetFirstInterfaceFloat();
    bool IsDeviceReady();
    bool UpdateMoviePlayback(bool);
};

#endif
