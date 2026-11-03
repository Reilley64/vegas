// fallout/misc/bgsmovieplayer.cpp: BGSMoviePlayer (16 functions)

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
#include "fnv/decl/fnv_00ec15e0__BSMoviePlayer.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004bc000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_004de000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_011de000.h"
#include "bgsmovieplayer_decls.h"

// @fnv 0x00867290
Direct3DDeviceInterface* BGSMoviePlayer::GetDevice()
{
    NiRenderer* renderer = ((::NiRenderer *)(::FUN_004bc3f0()));
    return ((::Direct3DDeviceInterface *)(reinterpret_cast<::FUN_004dc020_Class *>((renderer))->FUN_004dc020()));
}

// @fnv 0x008672b0
void BGSMoviePlayer::StartScene()
{
    NiRenderer* renderer = ((::NiRenderer *)(::FUN_004bc3f0()));
    ::FUN_004a0370((char *)(renderer));
}

// @fnv 0x008672d0
void BGSMoviePlayer::FinishScene()
{
    NiRenderer* renderer = ((::NiRenderer *)(::FUN_004bc3f0()));
    reinterpret_cast<::fnv_004a03c0::DD *>((renderer))->FUN_004a03c0();
}

// @fnv 0x00867410
unsigned int BGSMoviePlayer::GetUptimeMilliseconds()
{
    if (g_osGlobals)
        return ((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((g_osGlobals))->FUN_0044edb0()));
    return 0;
}

// Returns whether the current NiRenderer reports a value of 1 from FUN_004e9530.
// @fnv 0x008673e0
bool BGSMoviePlayer::IsDeviceReady()
{
    NiRenderer* renderer = ((::NiRenderer *)(::FUN_004bc3f0()));
    return ((int)(reinterpret_cast<::fnv_004e9530::NiRenderer *>((renderer))->FUN_004e9530())) == 1;
}

// @fnv 0x00867220
void BGSMoviePlayer::EndMoviePlayback()
{
    if (DAT_011de714 && reinterpret_cast<::FUN_005bb4d0_shell *>((::FUN_00453a70()))->FUN_005bb4d0())
    {
        reinterpret_cast<::FUN_00ad7230_shell *>((::FUN_00453a70()))->FUN_00ad7230(false);
        DAT_011de714 = 0;
    }
    ::FUN_00453a70()->DisableAudioPlayback();
}

// Returns the result of FUN_004de0e0 when FUN_004de070 and FUN_004de080 both succeed, otherwise returns FUN_004dc1f0.
// @fnv 0x008672f0
unsigned int BGSMoviePlayer::UpdateInterfaceState()
{
    if (FUN_004de070() && FUN_004de080())
        return (unsigned int)FUN_004de0e0();
    return FUN_004dc1f0();
}

// Returns the result of FUN_004de0f0 when FUN_004de070 and FUN_004de080 both succeed, otherwise returns FUN_004dc200.
// @fnv 0x00867340
unsigned int BGSMoviePlayer::GetFirstInterfaceFloat()
{
    if (FUN_004de070() && FUN_004de080())
        return (unsigned int)FUN_004de0f0();
    return ((unsigned int)(::FUN_004dc200()));
}

// @fnv 0x008671a0
void BGSMoviePlayer::BeginMoviePlayback()
{
    if (!reinterpret_cast<::FUN_005bb4d0_shell *>((::FUN_00453a70()))->FUN_005bb4d0())
    {
        reinterpret_cast<::FUN_00ad7230_shell *>((::FUN_00453a70()))->FUN_00ad7230(true);
        DAT_011de714 = 1;
    }
    reinterpret_cast<::BSAudio_ *>((::FUN_00453a70()))->FUN_007eb8a0();
    if (!reinterpret_cast<::FUN_005bb4d0_shell *>((::FUN_00453a70()))->FUN_005bb4d0())
    {
        DAT_011de714 = 0;
        ::FUN_00453a70()->Update(true);
        ::FUN_00453a70()->Update(true);
    }
}

// @fnv 0x00867440
bool BGSMoviePlayer::UpdateMoviePlayback(bool continuePlaying)
{
    int deviceStatus;

    if (!reinterpret_cast<::PlaybackContinueState *>(this)->FUN_00ec1840(continuePlaying))
        return false;

    deviceStatus = ((::Direct3DDeviceInterface *)(reinterpret_cast<::FUN_004dc020_Class *>((FUN_0043c4b0()))->FUN_004dc020()))->TestCooperativeLevel();
    if (deviceStatus < 0)
        return false;

    if (continuePlaying || field_20)
    {
        HotkeyWheelDisplay* wheel = ((::HotkeyWheelDisplay *)(reinterpret_cast<::FUN_00877720_shell *>((g_osGlobals))->FUN_00877720()));
        reinterpret_cast<::InputPoller *>((wheel))->FUN_00a23010();
        if (wheel->SetHotkeyItem(5, true) || wheel->SetHotkeyItem(0x1c, true))
        {
            if (reinterpret_cast<::FUN_00ec17c0_Class *>(this)->FUN_00ec17c0())
                reinterpret_cast<::FUN_00ec29b0_class *>(this)->FUN_00ec29b0();
            reinterpret_cast<::InputPoller *>((wheel))->FUN_00a23010();
            return false;
        }
    }
    return true;
}

// Returns the screen width override from FUN_004de0e0 when FUN_004de070 and FUN_004de080 both succeed, otherwise returns 0.
// @fnv 0x00867390
unsigned int BGSMoviePlayer::GetScreenWidthOverride()
{
    if (FUN_004de070() && FUN_004de080())
        return (unsigned int)FUN_004de0e0();
    return 0;
}

extern "C" float DAT_01189494;

// @fnv 0x004de0e0
float FUN_004de0e0()
{
    return DAT_01189494;
}

struct FUN_00867270_shell
{
    void FUN_00867270();
};
// @fnv 0x00867270
void FUN_00867270_shell::FUN_00867270()
{
    FUN_008305e0();
}

struct FUN_00867150_shell
{
    void FUN_00867180();
    void* FUN_00867150(unsigned int);
};
// Calls FUN_00867180, then deallocates this if the low bit of flags is set, and returns this.
// @fnv 0x00867150
void* FUN_00867150_shell::FUN_00867150(unsigned int flags)
{
    FUN_00867180();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00867280_shell
{
    void FUN_00867280();
};
// @fnv 0x00867280
void FUN_00867280_shell::FUN_00867280()
{
    ResetThreadFlags();
}

extern int DAT_01082564;
struct FUN_00ec15e0_shell
{
};

// @fnv 0x00867180
void FUN_00867150_shell::FUN_00867180()
{
    *(void**)this = &DAT_01082564;
    reinterpret_cast<::fnv_00ec15e0::BSMoviePlayer *>((((FUN_00ec15e0_shell*)this)))->fnv_00ec15e0::BSMoviePlayer::~BSMoviePlayer();
}
