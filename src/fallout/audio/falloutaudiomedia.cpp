// fallout/audio/falloutaudiomedia.cpp: FalloutAudioMedia, FAMThread (30 functions)

#include <cstdint>
#include <windows.h>
#include <cmath>
#include "fnv/decl/BSFile.h"
#include "fnv/decl/FUN_00591a40_class.h"
#include "fnv/decl/FUN_00595cb0_shell.h"
#include "fnv/decl/FUN_0082f6c0.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_009698a0_shell.h"
#include "fnv/decl/GList.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/S2f760.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/fnv_00992d90__FUN_00992d90_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004dd000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00c80000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01014000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01032000.h"
#include "fnv/symbols_01073000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f1000.h"
#include "falloutaudiomedia_decls.h"

// @fnv 0x008304a0
void FalloutAudioMedia::BeginMediaUpdate()
{
    ::FUN_00830470();
    ::ResetTaskQueueGlobals();
    ::fnv_00830490::FUN_00830490();
}

// @fnv 0x008304c0
void FalloutAudioMedia::EndMediaUpdate()
{
    ::FUN_00830470();
    DAT_011dd310 &= ~2;
    DAT_011dd311 &= ~2;
    ::fnv_00830490::FUN_00830490();
}

// @fnv 0x00830680
void FalloutAudioMedia::FadeOutMedia(int fadeTime, MEDIATYPE mediaType)
{
    ::FUN_00830470();
    unsigned int currentTime = ((FORenderedMenu*)((void *)(::FUN_00453a70())))->GetCurrentTimeMilliseconds();
    if ((*reinterpret_cast<unsigned long *>(&::DAT_011dd314)) == mediaType || mediaType == 0)
    {
        if ((DAT_011dd310 & 8) == 0)
        {
            DAT_011dd310 |= 0x18;
            DAT_011dd304 = DAT_011dd300;
            DAT_011dd308 = 0.0f;
            (*reinterpret_cast<unsigned long *>(&::DAT_011dd328)) = fadeTime;
            (*reinterpret_cast<unsigned long *>(&::DAT_011dd32c)) = currentTime + (*reinterpret_cast<unsigned long *>(&::DAT_011dd328));
        }
    }
    if ((*reinterpret_cast<unsigned long *>(&::DAT_011dd348)) == mediaType || mediaType == 0)
    {
        if ((DAT_011dd311 & 8) == 0)
        {
            DAT_011dd311 |= 0x18;
            DAT_011dd33c = DAT_011dd338;
            DAT_011dd340 = 0.0f;
            (*reinterpret_cast<unsigned long *>(&::DAT_011dd35c)) = fadeTime;
            (*reinterpret_cast<unsigned long *>(&::DAT_011dd360)) = currentTime + (*reinterpret_cast<unsigned long *>(&::DAT_011dd35c));
        }
    }
    ::fnv_00830490::FUN_00830490();
}

namespace fnv_anon_falloutaudiomedia {}
using namespace fnv_anon_falloutaudiomedia;
namespace fnv_anon_falloutaudiomedia {
// Historical member-form copy; FUN_0082f7b0 owns the recipe binding.
unsigned int FAMThread::ThreadProc()
{
    state |= 2;
    while (state & 1)
    {
        WaitForThread();
        ::EnsureArenaAllocated((::ArenaOwner *)(void *)(&event));
        if (state & 1)
            ::RunAudioChannel((int *)(void *)(&threadID));
    }
    state &= ~2;
    ::FUN_00c80240((::ArenaManagedOwner *)(void *)(&event));
    return 0;
}
}

// Checks whether either radio state is active or a flag is set, stores the result in state.result, calls FUN_00830490 and returns it.
// @fnv 0x00830ad0
char FalloutAudioMedia::IsRadioPlaying()
{
    struct RadioState
    {
        int isRadio;
        char padding0;
        char padding1;
        char padding2;
        char result;
    } state;

    ::FUN_00830470();
    if (!(((*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd314)) == 7) || ((*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd348)) == 7) || DAT_011dd313 != 0))
        state.isRadio = 0;
    else
        state.isRadio = 1;
    state.result = (char)state.isRadio;
    ::fnv_00830490::FUN_00830490();
    return state.result;
}


namespace fnv_anon_falloutaudiomedia {}
using namespace fnv_anon_falloutaudiomedia;
namespace fnv_anon_falloutaudiomedia {
// @fnv 0x0082f790
void FAMThread::WaitForThread()
{
    WaitForSingleObject(this->hThread, 0xFFFFFFFF);
}
}

// @fnv 0x0082f7b0
unsigned int FUN_0082f7b0(FAMThread* pThis)
{
    pThis->state |= 2;
    while (pThis->state & 1)
    {
        pThis->WaitForThread();
        ::EnsureArenaAllocated((::ArenaOwner *)(void *)(&pThis->event));
        if (pThis->state & 1)
            ::RunAudioChannel((int *)(void *)(&pThis->threadID));
    }
    pThis->state &= ~2;
    ::FUN_00c80240((::ArenaManagedOwner *)(void *)(&pThis->event));
    return 0;
}

struct SETTING_VALUE
{
    float f;
};

class SettingT_GameSettingCollection_
{
  public:
};

class BSAudio
{
  public:
    float GetMusicVolume();
    float FUN_00ad7ab0();
    float GetMasterVolume();
};

extern float DAT_0107cc20;

float __cdecl FUN_0082ffd0(float);

// Computes a volume from the media type's setting or BSAudio value, applies attenuation and dB clamping, then scales by the BSAudio factor and clamps the result.
// @fnv 0x0082fec0
float __cdecl ComputeAttenuatedVolume(int aeMediaType, float attenuation)
{
    float vol = 0.0f;
    float fVolumeDb;

    if (aeMediaType == 8)
    {
        vol = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd084))))))->f;
    }
    else if (aeMediaType == 7)
    {
        vol = ((BSAudio*)((void *)(::FUN_00453a70())))->GetMusicVolume();
    }
    else
    {
        vol = ((BSAudio*)((void *)(::FUN_00453a70())))->FUN_00ad7ab0();
    }

    fVolumeDb = (float)(FUN_0082ffd0(vol) * DAT_01073490 + attenuation * g_d100);
    if (fVolumeDb < -10000.0)
        fVolumeDb = DAT_0107cc20;
    else if (fVolumeDb > ::_DAT_01012060)
        fVolumeDb = 0.0f;

    vol = ::fnv_004dd130::FUN_004dd130(10.0f, (float)(fVolumeDb / DAT_01073490));
    vol = ((BSAudio*)((void *)(::FUN_00453a70())))->GetMasterVolume() * vol;

    if (vol < DAT_01032980)
        vol = ::DAT_010141cc;
    else if (vol > g_d100)
        vol = 100.0f;

    return vol;
}

float __cdecl FUN_0082fff0(float);

// @fnv 0x0082ffd0
float FUN_0082ffd0(float _X)
{
    return FUN_0082fff0(_X);
}


// @fnv 0x0082fff0
float __cdecl FUN_0082fff0(float value)
{
    return static_cast<float>(std::log10(value));
}

// If aiMusicType is non-null, plays it as music media using its random entry, FUN_00830050 and FUN_00830080 values.
// @fnv 0x00830010
void __cdecl PlayMusicType(BGSMusicType* aiMusicType)
{
    if (aiMusicType)
        ::fnv_008300c0::PlayAudioMedia((*(int *)&(const ::MEDIATYPE &)(kMediaType_Music)), ((const char *)(reinterpret_cast<::FUN_00591a40_class *>((aiMusicType))->GetRandomItem())), 1000, aiMusicType->FUN_00830050(),
                                     false, aiMusicType->FUN_00830080(), 0);
}

struct FUN_00830050_shell : public BGSMusicType
{
    bool FUN_00830050();
    char pad00[0x24];
    float fVolumeScale;
};

// Returns true if the music type's volume scale is greater than zero.
// @fnv 0x00830050
bool FUN_00830050_shell::FUN_00830050()
{
    return fVolumeScale > 0.0f ? true : false;
}

struct FUN_00830080_shell : public BGSMusicType
{
    float FUN_00830080();
    char pad00[0x24];
    float fVolumeScale;
};
// @fnv 0x00830010
void FalloutAudioMedia::PlayMedia(BGSMusicType* musicType)
{
    if (musicType)
        ::fnv_008300c0::PlayAudioMedia((*(int *)&(const ::MEDIATYPE &)(kMediaType_Music)), ((const char *)(reinterpret_cast<::FUN_00591a40_class *>((musicType))->GetRandomItem())), 1000, reinterpret_cast<::FUN_00830050_shell *>((musicType))->FUN_00830050(), false,
                  reinterpret_cast<::FUN_00830080_shell *>((musicType))->FUN_00830080(), 0);
}

// Returns the volume scale negated when it is greater than zero, otherwise returns it unchanged.
// @fnv 0x00830080
float FUN_00830080_shell::FUN_00830080()
{
    return (fVolumeScale > 0.0) ? -fVolumeScale : fVolumeScale;
}

class ActorTaskManager
{
  public:
public:
    void WaitForTasksDuringRendering();
};


// @fnv 0x00830470
void FUN_00830470()
{
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::ActorTaskManager *>(&::g_011dd3d8))))->FUN_004538a0(0);
}


// @fnv 0x00830660
void FUN_00830660()
{
    ::FUN_00830470();
    (*reinterpret_cast<char *>(&::DAT_011dd312)) = 0;
    ::fnv_00830490::FUN_00830490();
}

// @fnv 0x00830680
void __cdecl StartFade(int aiFadeTime, int aeType)
{
    ::FUN_00830470();
    unsigned int ticks =
        reinterpret_cast<FORenderedMenu*>(((void *)(::FUN_00453a70())))->GetCurrentTimeMilliseconds();
    if (((*reinterpret_cast<unsigned long *>(&::DAT_011dd314)) == aeType || aeType == 0) && !(DAT_011dd310 & 8))
    {
        DAT_011dd310 |= 0x18;
        DAT_011dd304 = DAT_011dd300;
        DAT_011dd308 = 0.0f;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd328)) = aiFadeTime;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd32c)) = ticks + (*reinterpret_cast<unsigned long *>(&::DAT_011dd328));
    }
    if (((*reinterpret_cast<unsigned long *>(&::DAT_011dd348)) == aeType || aeType == 0) && !(DAT_011dd311 & 8))
    {
        DAT_011dd311 |= 0x18;
        DAT_011dd33c = DAT_011dd338;
        DAT_011dd340 = 0.0f;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd35c)) = aiFadeTime;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd360)) = ticks + (*reinterpret_cast<unsigned long *>(&::DAT_011dd35c));
    }
    ::fnv_00830490::FUN_00830490();
}

// @fnv 0x00830750
bool __cdecl FUN_00830750(unsigned long aeType, bool abIncludeFading)
{
    ::FUN_00830470();
    bool ret = false;
    if (abIncludeFading)
    {
        if (aeType == 0)
        {
            ret = ((*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) != 0 && (DAT_011dd310 & 2) == 0) || ((*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) != 0 && (DAT_011dd311 & 2) == 0);
        }
        else
        {
            ret = ((*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd314)) == aeType && (DAT_011dd310 & 2) == 0) ||
                  ((*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd348)) == aeType && (DAT_011dd311 & 2) == 0);
        }
    }
    else
    {
        if (aeType == 0)
        {
            ret = ((*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) != 0 && (DAT_011dd310 & 8) == 0) || ((*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) != 0 && (DAT_011dd311 & 8) == 0);
        }
        else
        {
            ret = ((*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd314)) == aeType && (DAT_011dd310 & 8) == 0) ||
                  ((*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd348)) == aeType && (DAT_011dd311 & 8) == 0);
        }
    }
    ::fnv_00830490::FUN_00830490();
    return ret;
}


// @fnv 0x00830970
int __cdecl FUN_00830970(int auiThreadId)
{
    ::FUN_00830470();
    int result = 0;
    if (auiThreadId == 0)
    {
        if (DAT_011dd36c == 1 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) != 0)
            result = DAT_011dd324;
        else if (DAT_011dd36c == 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) != 0)
            result = DAT_011dd358;
    }
    if (DAT_011dd36c == 1 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd314)) == (unsigned long)auiThreadId)
        result = DAT_011dd324;
    else if (DAT_011dd36c == 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd348)) == (unsigned long)auiThreadId)
        result = DAT_011dd358;
    ::fnv_00830490::FUN_00830490();
    return result;
}

namespace fnv_00830a20 {

// @fnv 0x00830a20
unsigned long __cdecl FUN_00830a20(unsigned long param_1)
{
    ::FUN_00830470();
    unsigned long result = 0;
    if (param_1 == 0)
    {
        if ((*reinterpret_cast<unsigned long *>(&::DAT_011dd36c)) == 1 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) != 0)
        {
            result = (*reinterpret_cast<unsigned long *>(&::DAT_011dd31c));
        }
        else if ((*reinterpret_cast<unsigned long *>(&::DAT_011dd36c)) == 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) != 0)
        {
            result = (*reinterpret_cast<unsigned long *>(&::DAT_011dd350));
        }
    }
    if ((*reinterpret_cast<unsigned long *>(&::DAT_011dd36c)) == 1 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd314)) == param_1)
    {
        result = (*reinterpret_cast<unsigned long *>(&::DAT_011dd31c));
    }
    else if ((*reinterpret_cast<unsigned long *>(&::DAT_011dd36c)) == 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) != 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd348)) == param_1)
    {
        result = (*reinterpret_cast<unsigned long *>(&::DAT_011dd350));
    }
    ::fnv_00830490::FUN_00830490();
    return result;
}
}  // namespace fnv_00830a20

namespace fnv_00830490 {
struct ATM
{
};


// @fnv 0x00830490
void __cdecl FUN_00830490()
{
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_00830490::ATM *>(&::g_011dd3d8))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_00830490

float __cdecl ComputeAttenuatedVolume(int, float);

// @fnv 0x008304f0
void FUN_008304f0()
{
    ::FUN_00830470();
    if (DAT_011dd36c == 0)
    {
        DAT_011dd311 |= 2;
        DAT_011dd338 = ComputeAttenuatedVolume((*reinterpret_cast<unsigned long *>(&::DAT_011dd348)), DAT_011dd344);
        DAT_011dd34c = 0;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd35c)) = 0;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd360)) = 0;
        DAT_011dd350 = 0;
        DAT_011dd310 |= 1;
    }
    else
    {
        DAT_011dd310 |= 2;
        DAT_011dd300 = ComputeAttenuatedVolume((*reinterpret_cast<unsigned long *>(&::DAT_011dd314)), DAT_011dd30c);
        DAT_011dd318 = 0;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd328)) = 0;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd32c)) = 0;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd31c)) = 0;
        DAT_011dd311 |= 1;
    }
    ::fnv_00830490::FUN_00830490();
}

// @fnv 0x008305e0
void FUN_008305e0()
{
    ::FUN_00830470();
    DAT_011dd310 |= 4;
    DAT_011dd311 |= 4;
    ::fnv_00830490::FUN_00830490();
}

// @fnv 0x00830610
void ResetThreadFlags()
{
    ::FUN_00830470();
    DAT_011dd310 &= -5;
    DAT_011dd311 &= -5;
    ::fnv_00830490::FUN_00830490();
}


// @fnv 0x00830640
void __cdecl FUN_00830640()
{
    ::FUN_00830470();
    (*reinterpret_cast<char *>(&::DAT_011dd312)) = 1;
    ::fnv_00830490::FUN_00830490();
}


// @fnv 0x008308c0
unsigned int FUN_008308c0(unsigned long aeType)
{
    ::FUN_00830470();
    unsigned int ret = 0;
    if (!aeType)
    {
        if (DAT_011dd36c == 1 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd334)))
            ret = DAT_011dd320;
        else if (DAT_011dd36c == 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd368)))
            ret = DAT_011dd354;
    }
    if (DAT_011dd36c == 1 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) && (*reinterpret_cast<unsigned long *>(&::DAT_011dd314)) == aeType)
        ret = DAT_011dd320;
    else if (DAT_011dd36c == 0 && (*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) && (*reinterpret_cast<unsigned long *>(&::DAT_011dd348)) == aeType)
        ret = DAT_011dd354;
    ::fnv_00830490::FUN_00830490();
    return ret;
}

struct FUN_0082f950_shell
{
    void FUN_0082f6c0();
    void* ScalarDeletingDestructor(unsigned int flags);
};

extern void FUN_00ec5fce(void*, unsigned int, unsigned int, void (FUN_0082f950_shell::*)());

// Destructor that runs cleanup, optionally frees the object (and its 4-byte header when flags bit 2 is set), and returns the object pointer.
// @fnv 0x0082f950
void* FUN_0082f950_shell::ScalarDeletingDestructor(unsigned int flags)
{
    if ((flags & 2) != 0)
    {
        FUN_00ec5fce(this, 0x4c, ((unsigned int*)this)[-1], &FUN_0082f950_shell::FUN_0082f6c0);
        if ((flags & 1) != 0)
            FUN_00401030((char*)this - 4);
        return (char*)this - 4;
    }

    reinterpret_cast<::FUN_0082f6c0 *>(this)->FUN_0082f6c0::~FUN_0082f6c0();
    if ((flags & 1) != 0)
        FUN_00401030(this);
    return this;
}

extern void* DAT_011dd3b0;
class AudioClock
{
  public:
    unsigned int GetSynchTime();
};
class MediaLocationController
{
  public:
    bool Update(bool);
};
class MediaSet
{
  public:
    bool Update(unsigned int, bool, MediaLocationController*);
};
class WorldSpace
{
  public:
};
class MediaLocationRecord
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual void Unk04();
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0a();
    virtual void Unk0b();
    virtual MediaSet* GetExploreSet();
    virtual MediaSet* GetCombatSet();
};
class AcousticEntry
{
  public:
};
class AcousticSpace
{
  public:
};
class AcousticSpaceOwner
{
  public:
    AcousticSpace* FUN_006733e0();
};
class PlayerMedia
{
  public:
    virtual void Unk000();
    virtual void Unk001();
    virtual void Unk002();
    virtual void Unk003();
    virtual void Unk004();
    virtual void Unk005();
    virtual void Unk006();
    virtual void Unk007();
    virtual void Unk008();
    virtual void Unk009();
    virtual void Unk00a();
    virtual void Unk00b();
    virtual void Unk00c();
    virtual void Unk00d();
    virtual void Unk00e();
    virtual void Unk00f();
    virtual void Unk010();
    virtual void Unk011();
    virtual void Unk012();
    virtual void Unk013();
    virtual void Unk014();
    virtual void Unk015();
    virtual void Unk016();
    virtual void Unk017();
    virtual void Unk018();
    virtual void Unk019();
    virtual void Unk01a();
    virtual void Unk01b();
    virtual void Unk01c();
    virtual void Unk01d();
    virtual void Unk01e();
    virtual void Unk01f();
    virtual void Unk020();
    virtual void Unk021();
    virtual void Unk022();
    virtual void Unk023();
    virtual void Unk024();
    virtual void Unk025();
    virtual void Unk026();
    virtual void Unk027();
    virtual void Unk028();
    virtual void Unk029();
    virtual void Unk02a();
    virtual void Unk02b();
    virtual void Unk02c();
    virtual void Unk02d();
    virtual void Unk02e();
    virtual void Unk02f();
    virtual void Unk030();
    virtual void Unk031();
    virtual void Unk032();
    virtual void Unk033();
    virtual void Unk034();
    virtual void Unk035();
    virtual void Unk036();
    virtual void Unk037();
    virtual void Unk038();
    virtual void Unk039();
    virtual void Unk03a();
    virtual void Unk03b();
    virtual void Unk03c();
    virtual void Unk03d();
    virtual void Unk03e();
    virtual void Unk03f();
    virtual void Unk040();
    virtual void Unk041();
    virtual void Unk042();
    virtual void Unk043();
    virtual void Unk044();
    virtual void Unk045();
    virtual void Unk046();
    virtual void Unk047();
    virtual void Unk048();
    virtual void Unk049();
    virtual void Unk04a();
    virtual void Unk04b();
    virtual void Unk04c();
    virtual void Unk04d();
    virtual void Unk04e();
    virtual void Unk04f();
    virtual void Unk050();
    virtual void Unk051();
    virtual void Unk052();
    virtual void Unk053();
    virtual void Unk054();
    virtual void Unk055();
    virtual void Unk056();
    virtual void Unk057();
    virtual void Unk058();
    virtual void Unk059();
    virtual void Unk05a();
    virtual void Unk05b();
    virtual void Unk05c();
    virtual void Unk05d();
    virtual void Unk05e();
    virtual void Unk05f();
    virtual void Unk060();
    virtual void Unk061();
    virtual void Unk062();
    virtual void Unk063();
    virtual void Unk064();
    virtual void Unk065();
    virtual void Unk066();
    virtual void Unk067();
    virtual void Unk068();
    virtual void Unk069();
    virtual void Unk06a();
    virtual void Unk06b();
    virtual void Unk06c();
    virtual void Unk06d();
    virtual void Unk06e();
    virtual void Unk06f();
    virtual void Unk070();
    virtual void Unk071();
    virtual void Unk072();
    virtual void Unk073();
    virtual void Unk074();
    virtual void Unk075();
    virtual void Unk076();
    virtual void Unk077();
    virtual void Unk078();
    virtual void Unk079();
    virtual void Unk07a();
    virtual void Unk07b();
    virtual void Unk07c();
    virtual void Unk07d();
    virtual void Unk07e();
    virtual void Unk07f();
    virtual void Unk080();
    virtual void Unk081();
    virtual void Unk082();
    virtual void Unk083();
    virtual void Unk084();
    virtual void Unk085();
    virtual void Unk086();
    virtual void Unk087();
    virtual void Unk088();
    virtual void Unk089();
    virtual void Unk08a();
    virtual bool IsInCombat(bool);
};
// @fnv 0x0082fb70
void UpdateMediaLocation()
{
    SetEvent(DAT_011dd3b0);
    if (DAT_011dd313)
        return;
    if (FUN_00830750(6, true) || FUN_00830750(8, true))
    {
        if (DAT_011dd374)
            DAT_011dd374 = 0;
        return;
    }
    // Saved media category; mediaType below is the audio synchronization clock.
    unsigned long time;
    if (DAT_011dd36c == 0)
        time = (*reinterpret_cast<unsigned long *>(&::DAT_011dd348));
    else
        time = (*reinterpret_cast<unsigned long *>(&::DAT_011dd314));
    unsigned int mediaType = ((::AudioClock *)(::FUN_00453a70()))->GetSynchTime();
    bool combat =
        (*reinterpret_cast<::WorldSpace * *>(&::BGSSaveLoadGlobalDataWorldspacePtr)) ? reinterpret_cast<::fnv_00992d90::FUN_00992d90_shell *>(((*reinterpret_cast<::WorldSpace * *>(&::BGSSaveLoadGlobalDataWorldspacePtr))))->UpdateCombatMusic() : false;
    if (FUN_007027b0(1007))
        return;
    if (!(*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)) || ((*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)) && !(*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378))->Update(mediaType, combat, 0)))
    {
        if ((*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)))
            (*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)) = 0;
        if ((*reinterpret_cast<::PlayerMedia * *>(&::_g_thePlayer)) &&
            (!reinterpret_cast<::FUN_009698a0_shell *>(((*reinterpret_cast<::PlayerMedia * *>(&::_g_thePlayer))))->GetMediaLocationController() || !reinterpret_cast<::FUN_009698a0_shell *>(((*reinterpret_cast<::PlayerMedia * *>(&::_g_thePlayer))))->GetMediaLocationController()->Update(combat)))
        {
            DAT_011dd374 = 0;
            if (DAT_011dcfb4 && DAT_011dcfb4->FUN_006733e0())
            {
                if (FUN_00830750(2, true))
                    ::FalloutAudioMedia::FadeOutMedia(1000, (::MEDIATYPE)(2));
                if (FUN_00830750(3, true))
                    ::FalloutAudioMedia::FadeOutMedia(1000, (::MEDIATYPE)(3));
                AcousticSpace* location = DAT_011dcfb4->FUN_006733e0();
                MediaLocationRecord* space = DAT_011dd380 ? DAT_011dd380 : ((::MediaLocationRecord *)(reinterpret_cast<::GList *>((((::AcousticEntry *)(reinterpret_cast<::FUN_009611e0_shell *>((location))->FUN_009611e0()))))->FUN_004f35b0({})));
                if (space)
                {
                    if (combat && !(*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)))
                    {
                        (*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)) = space->GetCombatSet();
                        if ((*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)))
                            reinterpret_cast<::FUN_00595cb0_shell *>(((*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378))))->ResetState();
                    }
                    if (!(*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)) || ((*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)) && !(*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378))->Update(mediaType, combat, 0)))
                    {
                        (*reinterpret_cast<::MediaSet * *>(&::DAT_011dd378)) = 0;
                        if (space->GetExploreSet() && time == 0)
                            space->GetExploreSet()->Update(mediaType, false, 0);
                    }
                }
            }
        }
        else if ((*reinterpret_cast<::PlayerMedia * *>(&::_g_thePlayer)))
        {
            if ((*reinterpret_cast<::PlayerMedia * *>(&::_g_thePlayer))->IsInCombat(false))
                ::FalloutAudioMedia::FadeOutMedia(1000, (::MEDIATYPE)(0));
            else if (FUN_00830750(0, true) && !((bool)(::FalloutAudioMedia::IsRadioPlaying())) && !DAT_011dd374)
            {
                ::FalloutAudioMedia::FadeOutMedia(5000, (::MEDIATYPE)(4));
                ::FalloutAudioMedia::FadeOutMedia(5000, (::MEDIATYPE)(5));
                ::FalloutAudioMedia::FadeOutMedia(5000, (::MEDIATYPE)(2));
                ::FalloutAudioMedia::FadeOutMedia(5000, (::MEDIATYPE)(3));
            }
        }
    }
}

struct BSThread
{
    int unk00;
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    void Initialize(int stackSize, const char* name, bool suspended);
    void SetThreadPriority(int priority);
public:
    void SetSchedulingPriority(unsigned int);
};

struct FAMThread : BSThread
{
    FAMThread();
    ~FAMThread();
};

extern const char DAT_0107cc08[];
extern const char DAT_0107cbf0[];

// Allocates two FAMThread objects, initializes each with a 0x4000 stack and name, sets priority 1, and calls FUN_00aa6550 with 0.
// @fnv 0x0082f830
void __cdecl FUN_0082f830()
{
    (*reinterpret_cast<::BSThread * *>(&::DAT_011dd1f4)) = new ::FAMThread[2];
    (*reinterpret_cast<::BSThread * *>(&::DAT_011dd1f4))->Initialize(0x4000, DAT_0107cc08, false);
    (*reinterpret_cast<::BSThread * *>(&::DAT_011dd1f4))->SetThreadPriority(1);
    ((*reinterpret_cast<::BSThread * *>(&::DAT_011dd1f4)) + 1)->Initialize(0x4000, DAT_0107cbf0, false);
    ((*reinterpret_cast<::BSThread * *>(&::DAT_011dd1f4)) + 1)->SetThreadPriority(1);
    int zero = 0;
    (*reinterpret_cast<::BSThread * *>(&::DAT_011dd1f4))->SetSchedulingPriority(zero);
    ((*reinterpret_cast<::BSThread * *>(&::DAT_011dd1f4)) + 1)->SetSchedulingPriority(zero);
}

namespace fnv_008300c0 {
struct EmptyType
{
};

struct BSFile
{
    virtual ~BSFile();
    BSFile(char const*, int, unsigned int, bool);

    unsigned char padding[0x154];

};

struct S2f760
{
    unsigned char padding[0x4c];

};

struct TaskQueueInterface
{
};

struct GlobalObject_0096a2d0
{
    int value;
};


extern int DAT_011a163c;
extern int DAT_011dd3c8;

// Validates and queues an audio media file for playback, storing fade, loop, and attenuation settings into the active or standby media slot.
// @fnv 0x008300c0
void __cdecl PlayAudioMedia(int aeMediaType, char const* apFileName, unsigned int auiFadeTime, bool abLoop,
                            bool abForce, float afAttenuation, unsigned int auiSynchTime)
{
    char const* pRealFilename;
    EmptyType* pTask;

    ::FUN_00830470();

    if (aeMediaType == 9)
    {
        ::ResetTaskQueueGlobals();
        ::fnv_00830490::FUN_00830490();
        return;
    }

    if (aeMediaType != 8 && ::DAT_011dcfa5)
    {
        ::fnv_00830490::FUN_00830490();
        return;
    }

    if (!apFileName || !apFileName[0])
    {
        ::fnv_00830490::FUN_00830490();
        return;
    }

    if (!abForce && ((aeMediaType < static_cast<int>((*reinterpret_cast<unsigned long *>(&::DAT_011dd314))) && ::DAT_011dd36c == 1) ||
                     (aeMediaType < static_cast<int>((*reinterpret_cast<unsigned long *>(&::DAT_011dd348))) && ::DAT_011dd36c == 0)))
    {
        ::FUN_005b5e40();
        ::fnv_00830490::FUN_00830490();
        return;
    }

    pRealFilename = apFileName;
    {
        BSFile fileCheck(pRealFilename, 0, 0x4000, false);
        if (!reinterpret_cast<::BSFile *>(&(fileCheck))->Write())
        {
            ::FUN_005b5e40();
            ::fnv_00830490::FUN_00830490();
            return;
        }
    }

    pTask = reinterpret_cast<EmptyType*>(
        static_cast<FORenderedMenu*>(((void *)(::FUN_00453a70())))->GetCurrentTimeMilliseconds());

    if (::DAT_011dd36c == 0)
    {
        DAT_011dd300 = 0.0f;
        DAT_011dd304 = 0.0f;
        DAT_011dd308 = ::ComputeAttenuatedVolume(aeMediaType, afAttenuation);
        ::DAT_011dd30c = afAttenuation;
        DAT_011dd310 = static_cast<char>((abLoop ? 0x20 : 0) | 0x10);

        ::TaskQueueInterface::CopyStringToBuffer((*reinterpret_cast<char (*)[260]>(&::DAT_011dd0f0)), 0x104, apFileName);

        (*reinterpret_cast<unsigned long *>(&::DAT_011dd314)) = static_cast<unsigned long>(aeMediaType);
        ::DAT_011dd318 = static_cast<int>(auiSynchTime);
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd328)) = auiFadeTime;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd32c)) = reinterpret_cast<uintptr_t>(pTask) + (*reinterpret_cast<unsigned long *>(&::DAT_011dd328));
        (*reinterpret_cast<int *>(&::DAT_011dd330)) = 0;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd334)) = DAT_011a163c;
        (*reinterpret_cast<::fnv_008300c0::GlobalObject_0096a2d0 *>(&::g_011dd3c4)).value = DAT_011a163c;
        ++DAT_011a163c;
        DAT_011dd3c8 = ::DAT_011dd36c;
        reinterpret_cast<::S2f760 *>(&((*reinterpret_cast<::fnv_008300c0::S2f760 * *>(&::DAT_011dd1f4))[::DAT_011dd36c]))->CopyAndSleep(&(*reinterpret_cast<::fnv_008300c0::GlobalObject_0096a2d0 *>(&::g_011dd3c4)));
        ::DAT_011dd36c = 1;
        DAT_011dd311 = static_cast<char>(DAT_011dd311 | 0x18);
        DAT_011dd33c = DAT_011dd338;
        DAT_011dd340 = 0.0f;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd35c)) = (*reinterpret_cast<unsigned long *>(&::DAT_011dd328));
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd360)) = (*reinterpret_cast<unsigned long *>(&::DAT_011dd32c));
    }
    else
    {
        DAT_011dd338 = 0.0f;
        DAT_011dd33c = 0.0f;
        DAT_011dd340 = ::ComputeAttenuatedVolume(aeMediaType, afAttenuation);
        ::DAT_011dd344 = afAttenuation;
        DAT_011dd311 = static_cast<char>((abLoop ? 0x20 : 0) | 0x10);

        ::TaskQueueInterface::CopyStringToBuffer((*reinterpret_cast<char (*)[260]>(&::DAT_011dd1f8)), 0x104, apFileName);

        (*reinterpret_cast<unsigned long *>(&::DAT_011dd348)) = static_cast<unsigned long>(aeMediaType);
        ::DAT_011dd34c = static_cast<int>(auiSynchTime);
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd35c)) = auiFadeTime;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd360)) = reinterpret_cast<uintptr_t>(pTask) + (*reinterpret_cast<unsigned long *>(&::DAT_011dd35c));
        (*reinterpret_cast<int *>(&::DAT_011dd364)) = 0;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd368)) = DAT_011a163c;
        (*reinterpret_cast<::fnv_008300c0::GlobalObject_0096a2d0 *>(&::g_011dd3c4)).value = DAT_011a163c;
        ++DAT_011a163c;
        DAT_011dd3c8 = ::DAT_011dd36c;
        reinterpret_cast<::S2f760 *>(&((*reinterpret_cast<::fnv_008300c0::S2f760 * *>(&::DAT_011dd1f4))[::DAT_011dd36c]))->CopyAndSleep(&(*reinterpret_cast<::fnv_008300c0::GlobalObject_0096a2d0 *>(&::g_011dd3c4)));
        ::DAT_011dd36c = 0;
        DAT_011dd310 = static_cast<char>(DAT_011dd310 | 0x18);
        DAT_011dd304 = DAT_011dd300;
        DAT_011dd308 = 0.0f;
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd328)) = (*reinterpret_cast<unsigned long *>(&::DAT_011dd35c));
        (*reinterpret_cast<unsigned long *>(&::DAT_011dd32c)) = (*reinterpret_cast<unsigned long *>(&::DAT_011dd360));
    }

    ::fnv_00830490::FUN_00830490();
}
}  // namespace fnv_008300c0

#include "generated/data/fallout/audio/falloutaudiomedia.inc"
