// fallout/audio/falloutradio.cpp: FalloutRadio, RadioConvTask, FalloutAudioMedia, Interface and more (61 functions)

#include <new>
#include "fnv/decl/Actor.h"
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DialogueItem.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/FUN_00458b30_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_0061f170_cls.h"
#include "fnv/decl/FUN_00632d20_shell.h"
#include "fnv/decl/FUN_00700270_class.h"
#include "fnv/decl/FUN_00798450_shell.h"
#include "fnv/decl/FUN_008321c0_Class.h"
#include "fnv/decl/FUN_008321e0.h"
#include "fnv/decl/FUN_00835f10_shell.h"
#include "fnv/decl/FUN_00835f80_shell.h"
#include "fnv/decl/FUN_008363a0_shell.h"
#include "fnv/decl/FUN_00836600_class.h"
#include "fnv/decl/FUN_00836630.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0084a9c0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865e70_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad88b0_h.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8be0_shell.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/MessageHUD.h"
#include "fnv/decl/Mid83b9a0.h"
#include "fnv/decl/NiPoint3.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S_00836470.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESObjectREFR_Flags.h"
#include "fnv/decl/TESPackage.h"
#include "fnv/decl/TESSound.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0056b190__FUN_0056b190_shell.h"
#include "fnv/decl/fnv_0056b1d0__XActor.h"
#include "fnv/decl/fnv_0056b210__FUN_0056b210_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0083d130__S_0083d130_Class.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_008648e0__FUN_008648e0_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_008649a0__FUN_008649a0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/fnv_00ad8fd0__FUN_00ad8fd0_h.h"
#include "fnv/decl/s835fe0__RefHandle.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00481000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004dd000.h"
#include "fnv/symbols_004fd000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00579000.h"
#include "fnv/symbols_005aa000.h"
#include "fnv/symbols_0061a000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00824000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00832000.h"
#include "fnv/symbols_00833000.h"
#include "fnv/symbols_00835000.h"
#include "fnv/symbols_00837000.h"
#include "fnv/symbols_00944000.h"
#include "fnv/symbols_00ad8000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01019000.h"
#include "fnv/symbols_0101f000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "falloutradio_private_decls.h"

// Toggles the radio on or off: starts playback when enabling, stops and releases streams when disabling, and stores the new state.
// @fnv 0x008324e0
bool FalloutRadio::SetRadioEnabled(bool enable)
{
    if (DAT_011dd436)
        return false;

    if (enable)
    {
        if (!DAT_011dd437)
        {
            FalloutAudioMedia::BeginMediaUpdate();
            ::FUN_008325a0(true);
            ::fnv_008300c0::PlayAudioMedia((*(int *)&(const ::MEDIATYPE &)(MEDIATYPE_RADIO)), 0, 1000, false, false, 0.0f, 0);
            FalloutAudioMedia::EndMediaUpdate();
        }
    }
    else
    {
        if (FalloutAudioMedia::IsRadioPlaying())
        {
            FalloutAudioMedia::BeginMediaUpdate();
            ::FUN_008325a0(false);
        }

        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc))))->FUN_00ad88f0();
        (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)).Release();
        ::DAT_011dd42c = 0;
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd638))))->FUN_00ad88f0();
        (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd638)).Release();
    }

    DAT_011dd434 = enable;
    return DAT_011dd434;
}

// @fnv 0x00832ad0
bool FalloutRadio::Update(bool force)
{
    bool update = false;

    if (DAT_011dd424 == 0)
        DAT_011dd424 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();

    if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00() - DAT_011dd424 > ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd5cc))))))->value && !Interface::IsGamePaused())
    {
        update = true;
        DAT_011dd424 = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::TimeGlobal *>(&::g_timeGlobal))))->FUN_00825c00();
    }

    if (::_g_thePlayer != 0)
    {
        if (reinterpret_cast<LowProcess*>(::_g_thePlayer)->GetTarget() != 0)
        {
            if (reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(::_g_thePlayer)->GetTarget())
                    ->IsCellInterior())
            {
                if (DAT_011dd435 == 0)
                    update = true;
                else
                    update = false;
                DAT_011dd435 = 1;
            }
        }
    }

    if (force)
        update = true;

    if (::FalloutRadio::ms_uiRadioSyncFlags & 1)
    {
        DAT_011dd43c &= ~2;
        DAT_011dd43c |= 1;
    }
    else if (::FalloutRadio::ms_uiRadioSyncFlags & 2)
    {
        DAT_011dd43c &= ~1;
        DAT_011dd43c |= 2;
    }
    ::FalloutRadio::ms_uiRadioSyncFlags = 0;

    FalloutRadio::RefreshRadioReceivers(false);
    if (DAT_011dd440 == 0)
        DAT_011dd440 = (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->GetSoundByEditorID(DAT_0107ce14);
    ::UpdateRadioSignals(update);
    FalloutRadio::RefreshRadioReceivers(false);
    DAT_011dd43c = 0;
    return true;
}

// Clears bit 0 and sets bit 1 of the radio state flags.
// @fnv 0x00832c80
void FalloutRadio::RadioSynchUnPaused()
{
    ms_uiRadioSyncFlags &= ~1;
    ms_uiRadioSyncFlags |= 2;
}

bool __fastcall _ref_008256d0(void*);

// Walks the DAT_011dd58c list until an entry whose first int equals param_1 is found, returning that entry or null.
// @fnv 0x00832930
FalloutRadio::RadioReceiver* __cdecl FUN_00832930(int param_1)
{
    FalloutRadio::RadioReceiver* result = 0;
    BSSimpleList<FalloutRadio::RadioReceiver*>* node = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c));
    {
        bool found = false;
        while (node && !_ref_008256d0(node) && !found)
        {
            if (param_1 == *(int*)*((::FalloutRadio::RadioReceiver **)(new ((void *)(node)) ::Vec3())))
            {
                result = *((::FalloutRadio::RadioReceiver **)(new ((void *)(node)) ::Vec3()));
                found = true;
            }
            node = ((::BSSimpleList< ::FalloutRadio::RadioReceiver *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
    }
    return result;
}

struct FORadioReceiver_Stub
{
    void* pRef;
    SoundPlaybackHandle sound;
    char pad[0x1c - 0x4 - sizeof(SoundPlaybackHandle)];
    bool bFlag;
};

struct TESObjectREFR_Stub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool v64();
};

FORadioReceiver_Stub* __cdecl FUN_00832930(TESObjectREFR_Stub*);

// If the reference has a radio emitter, stops and releases its sound, clears the flag and reference pointer.
// @fnv 0x00835980
void __cdecl FUN_00835980(TESObjectREFR_Stub* apNPCRadio)
{
    if (!apNPCRadio->v64())
        return;

    FORadioReceiver_Stub* pemitter = FUN_00832930(apNPCRadio);
    if (pemitter)
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(pemitter->sound))->FUN_00ad88f0();
        pemitter->sound.Release();
        pemitter->bFlag = false;
        pemitter->pRef = 0;
    }
}

struct FUN_008373d0_struct
{
    float f;
    void* p;
};

// @fnv 0x008373d0
FUN_008373d0_struct* __fastcall ClearStruct(FUN_008373d0_struct* pThis)
{
    pThis->f = 0.0f;
    pThis->p = 0;
    return pThis;
}


// @fnv 0x008373f0
void __fastcall FUN_008373f0(void* pThis)
{
    ::FUN_00837410((::Node_00837410 *)(pThis));
}

template <class T> class BSSimpleListEx : public BSSimpleList<T>
{
  public:
    BSSimpleListEx();
    ~BSSimpleListEx();
    void RemoveAll();
    void AddHead(T& item);
};

template <class T> class BSStringT
{
  public:
    T* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    BSStringT();
    ~BSStringT();
    int PrintfString(const char* fmt, ...);
    operator const T*() const;
};

class BSSoundHandleEx
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned int eState;
    ~BSSoundHandleEx();
};

class BSAudio
{
  public:
    BSSoundHandleEx GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
public:
    float GetMusicVolume();
};

class RadioStationRef : public TESObjectREFR
{
  public:
};

class TESObjectREFR;
template <class> class BSSimpleList;
class BGSTalkingActivator
{
  public:
public:
    static void FindRadioStations(::TESObjectREFR *, ::BSSimpleList< ::TESObjectREFR *> *, ::BSSimpleList<float> *);
};

class RadioSignal
{
  public:
    void FUN_00834210(bool abLost);
};

class SettingString
{
  public:
};

class SettingFloat
{
  public:
};

void __cdecl FUN_00834260(FalloutRadio::RadioStationState* apStation);
extern unsigned char DAT_011a179c;

// Updates radio station signal strength and static from player distances, queues a UI alert for newly found stations, and clears the temporary station lists.
// @fnv 0x00833d00
void UpdateRadioSignals(bool abUpdateSignals)
{
    bool bmatch;
    BSSimpleList<FalloutRadio::RadioStationState*>* pactStations;
    unsigned char isignalPower;
    float fradioRadius;
    float fstaticRatio;
    float fstaticDistance;
    BSSimpleListEx<RadioStationRef*> stationlist;
    float fdistance;
    BSSimpleList<RadioStationRef*>* stations;
    BSSimpleList<float>* pdistances;
    BSSimpleListEx<float> stationDistances;

    if (DAT_011dd436)
        return;

    if (abUpdateSignals)
    {
        ::BGSTalkingActivator::FindRadioStations((TESObjectREFR*)::_g_thePlayer, (::BSSimpleList< ::TESObjectREFR *> *)(::BSSimpleList< ::RadioStationRef *> *)(&stationlist), &stationDistances);
        for (BSSimpleList<RadioStationRef*>* pstationObj = &stationlist; pstationObj && ((::RadioStationRef *)(new ((void *)(pstationObj)) ::Vec3()));
             pstationObj = ((::BSSimpleList< ::RadioStationRef *> *)(reinterpret_cast<::Callees *>((pstationObj))->FUN_00726070())))
        {
            if (!reinterpret_cast<::TESForm *>((((::RadioStationRef *)(new ((void *)(pstationObj)) ::Vec3()))))->GetDisabled() || ::fnv_005aa680::FUN_005aa680((::Actor *)(((::RadioStationRef *)(new ((void *)(pstationObj)) ::Vec3())))))
            {
                if (!reinterpret_cast<::RefList *>(&((*reinterpret_cast<::BSSimpleList<unsigned int> *>(&::g_011dd59c))))->FUN_005f65d0((void **)&((unsigned int&)((::RadioStationRef *)(new ((void *)(pstationObj)) ::Vec3())))))
                {
                    if (!DAT_011a179c)
                    {
                        BSStringT<char> strtemp;
                        BSSoundHandleEx alertSound =
                            ::FUN_00453a70()->GetSoundHandleByEditorID("UIRadioSignalFound", 0x100121);
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(alertSound))->FUN_00ad8830(false);
                        ::FUN_00406f60((::FUN_00406f90_this *)&(strtemp), ((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::SettingString *>(&::g_011d4348))))->IsDLCAvailable())), reinterpret_cast<::FUN_0055d520_shell *>((((::RadioStationRef *)(new ((void *)(pstationObj)) ::Vec3()))))->FUN_0055d520());
                        ::DispatchMessageToSink((int)(strtemp), 0, (int)("Interface\\Icons\\Message Icons\\glow_message_radio_tower.dds"), (int)(0),
                                       2.0f, false);
                    }
                    static_cast<BSSimpleListEx<unsigned int>&>((*reinterpret_cast<::BSSimpleList<unsigned int> *>(&::g_011dd59c)))
                        .AddHead((unsigned int&)((::RadioStationRef *)(new ((void *)(pstationObj)) ::Vec3())));
                }
            }
        }
        DAT_011a179c = 0;
    }

    stations = 0;
    pdistances = 0;
    bmatch = false;
    fdistance = 3.402823466e+38f;
    fradioRadius = 0.0f;
    fstaticRatio = 0.0f;
    isignalPower = 0;
    fstaticDistance = 1.0f - *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011dd580))))));
    pactStations = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554));
    while (pactStations && !pactStations->IsEmpty())
    {
        stations = &stationlist;
        pdistances = &stationDistances;
        bmatch = false;
        fdistance = 3.402823466e+38f;
        FalloutRadio::RadioStationState* pstation = ((::FalloutRadio::RadioStationState *)(new ((void *)(pactStations)) ::Vec3()));
        if (pstation)
        {
            while (abUpdateSignals && stations && pdistances)
            {
                if (((::RadioStationRef *)(new ((void *)(stations)) ::Vec3())) == pstation->form)
                {
                    bmatch = true;
                    isignalPower = 100;
                    ((RadioSignal*)((char*)pstation + 4))->FUN_00834210(false);
                    fdistance = ((float)(new ((void *)(pdistances)) ::Vec3()));
                    fradioRadius = reinterpret_cast<::fnv_0056b190::FUN_0056b190_shell *>((((RadioStationRef*)pstation->form)))->FUN_0056b190();
                    if (reinterpret_cast<::fnv_0056b1d0::XActor *>((((RadioStationRef*)pstation->form)))->FUN_0056b1d0() != 0.0)
                        fstaticDistance =
                            1.0 - reinterpret_cast<::fnv_0056b1d0::XActor *>((((RadioStationRef*)pstation->form)))->FUN_0056b1d0() / 100.0;
                    if (reinterpret_cast<::fnv_0056b210::FUN_0056b210_shell *>((((RadioStationRef*)pstation->form)))->FUN_0056b210() == 0 && fradioRadius > 0.0 &&
                        fdistance > 0.0)
                    {
                        fstaticRatio = fdistance / fradioRadius;
                        if (fstaticRatio > fstaticDistance)
                            isignalPower = 100 - (unsigned char)((fstaticRatio - fstaticDistance) /
                                                                 (1.0f - fstaticDistance) * 100.0);
                    }
                    reinterpret_cast<::FUN_00458b30_class *>((((RadioSignal*)((char*)pstation + 4))))->SetByteAtOffset17(isignalPower);
                    stations = 0;
                    pdistances = 0;
                }
                else
                {
                    stations = ((::BSSimpleList< ::RadioStationRef *> *)(reinterpret_cast<::Callees *>((stations))->FUN_00726070()));
                    pdistances = ((::BSSimpleList<float> *)(reinterpret_cast<::Callees *>((pdistances))->FUN_00726070()));
                }
            }
            if (abUpdateSignals && !bmatch)
            {
                ((RadioSignal*)((char*)pstation + 4))->FUN_00834210(true);
                reinterpret_cast<::FUN_00458b30_class *>((((RadioSignal*)((char*)pstation + 4))))->SetByteAtOffset17(0);
            }
            if (bmatch && DAT_011dd430 == (unsigned int)pstation)
            {
                BSStringT<char> strtemp;
                BSSoundHandleEx alertSound =
                    ::FUN_00453a70()->GetSoundHandleByEditorID("UIRadioSignalFound", 0x100121);
                reinterpret_cast<::FUN_00ad8830_shell *>(&(alertSound))->FUN_00ad8830(false);
                ::FUN_00406f60((::FUN_00406f90_this *)&(strtemp), ((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::SettingString *>(&::g_011d4348))))->IsDLCAvailable())), reinterpret_cast<::FUN_0055d520_shell *>((((RadioStationRef*)pstation->form)))->FUN_0055d520());
                ::DispatchMessageToSink((int)(strtemp), 0, (int)("Interface\\Icons\\Message Icons\\glow_message_radio_tower.dds"), (int)(0), 2.0f,
                               false);
                FalloutRadio::SetRadioEnabled(true);
                ::fnv_00832240::FUN_00832240((::fnv_00832240::RefView *)(pstation->form), false);
                DAT_011dd430 = 0;
            }
            FUN_00834260(pstation);
        }
        pactStations = ((::BSSimpleList< ::FalloutRadio::RadioStationState *> *)(reinterpret_cast<::Callees *>((pactStations))->FUN_00726070()));
    }
    ::FUN_00837410((::Node_00837410 *)&(stationDistances));
    reinterpret_cast<::FileMatchList *>(&(stationlist))->RemoveAll();
}

extern unsigned char DAT_011dd313;

// @fnv 0x008325a0
void FUN_008325a0(unsigned char value)
{
    DAT_011dd313 = value;
}

void __cdecl FUN_00834260(FalloutRadio::RadioStationState* apStation);

// Clears bit 1 of DAT_011dd438, sets bit 0, and if DAT_011dd42c is non-null passes it to FUN_00834260.
// @fnv 0x00832c40
void __cdecl FUN_00832c40()
{
    ::FalloutRadio::ms_uiRadioSyncFlags &= 0xfffffffd;
    ::FalloutRadio::ms_uiRadioSyncFlags |= 1;
    if (::DAT_011dd42c != 0)
        FUN_00834260((FalloutRadio::RadioStationState*)::DAT_011dd42c);
}

struct FUN_00833040_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    bool __thiscall IsFlag20Set();
};

// @fnv 0x00833040
bool __thiscall FUN_00833040_shell::IsFlag20Set()
{
    return ((m_14 & 0x20) != 0);
}

struct FUN_008330b0_shell
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    void SetFlag(bool a2);
};

// Sets or clears bit 0x10 in m_14 according to a2.
// @fnv 0x008330b0
void FUN_008330b0_shell::SetFlag(bool a2)
{
    a2 ? m_14 |= 0x10 : m_14 &= ~0x10;
}

struct FUN_00833bc0_shell
{
    int mFlags;  // +0x14
    bool IsFlagSet();
};

// @fnv 0x00833bc0
bool FUN_00833bc0_shell::IsFlagSet()
{
    return (*(int*)((char*)this + 0x14) & 4) != 0;
}

// @fnv 0x00833c00
bool __fastcall IsFlag80Set(void* thisPtr)
{
    return (((int*)thisPtr)[5] & 0x80) != 0;
}

// @fnv 0x00833ce0
unsigned char FUN_00833ce0()
{
    return DAT_011dd437;
}


// @fnv 0x00833cf0
unsigned char __cdecl FUN_00833cf0()
{
    return ::DAT_011dcfa4;
}

struct FUN_00835650_shell
{
    int m_uiSoundFlags;
    bool FUN_00835650();
};

// @fnv 0x00835650
bool FUN_00835650_shell::FUN_00835650()
{
    return (*(int*)((char*)this + 0x14) & 1) != 0;
}

struct FUN_00835670_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    int m_usTrailingValue;
    int m_f;
    bool IsFlag8Set();
};

// @fnv 0x00835670
bool FUN_00835670_shell::IsFlag8Set()
{
    return (m_f & 8) != 0;
}


struct RadioConvTask
{
    bool __thiscall GetDescription(char* apDescription, unsigned int aiBufferSize);
};

// Writes the string "Radio conversation task" into apDescription using the given buffer size and returns true.
// @fnv 0x008373a0
bool __thiscall RadioConvTask::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    ::FUN_00406d00(apDescription, aiBufferSize, "Radio conversation task");
    return true;
}

struct FUN_00832440_shell
{
    unsigned int pad0_0;
    unsigned int pad1_4;
    unsigned int pad2_8;
    unsigned int pad3_c;
    unsigned int pad4_10;
    unsigned int flags;
    void FUN_00832440(bool enabled);
};

// Sets or clears bit 0 of the flags field according to enabled.
// @fnv 0x00832440
void FUN_00832440_shell::FUN_00832440(bool enabled)
{
    enabled ? flags |= 1 : flags &= ~1;
}

struct FUN_00833060_shell
{
    int m_auiShapeKeys;               // +0x00
    int m_pAuxiliaryObject;  // +0x04
    int m_pad3;              // +0x08
    int m_pad4;              // +0x0c
    int m_pad5;              // +0x10
    int m_flags;             // +0x14
    void FUN_00833060(bool enabled);
};

// @fnv 0x00833060
void FUN_00833060_shell::FUN_00833060(bool enabled)
{
    enabled ? m_flags |= 2 : m_flags &= ~2;
}

struct FUN_00833100_shell
{
    int m_kPointA;                // +0x00
    int m_kPointB;                // +0x04
    int m_iThirdValue;                // +0x08
    int m_iFourthElementInteger;                // +0x0c
    int m_usTrailingValue;  // +0x10
    int m_flags;            // +0x14
    void FUN_00833100(bool enabled);
};

// Sets or clears bit 0x20 in m_flags according to enabled.
// @fnv 0x00833100
void FUN_00833100_shell::FUN_00833100(bool enabled)
{
    enabled ? m_flags |= 0x20 : m_flags &= ~0x20;
}

struct FUN_00833be0_shell
{
    int FUN_00833be0();
};

// @fnv 0x00833be0
int FUN_00833be0_shell::FUN_00833be0()
{
    return (reinterpret_cast<int*>(this)[5] & 0x10) != 0;
}

struct FUN_00833c20_shell
{
// @fnv 0x00833c20
    virtual ~FUN_00833c20_shell()
    {}
    unsigned char FUN_00833c20();
};

unsigned char FUN_00833c20_shell::FUN_00833c20()
{
    return ((char*)this)[0x10];
}

struct FUN_00834210_shell
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    void FUN_00834210(bool enabled);
};

// @fnv 0x00834210
void FUN_00834210_shell::FUN_00834210(bool enabled)
{
    enabled ? m_14 |= 4 : m_14 &= ~4;
}

struct FUN_00835690_shell
{
    unsigned int a;      // +0x00
    unsigned int b;      // +0x04
    unsigned int c;      // +0x08
    unsigned int d;      // +0x0c
    unsigned int e;      // +0x10
    unsigned int flags;  // +0x14
    void SetFlag80(bool value);
};

// Sets or clears bit 0x80 in flags according to value.
// @fnv 0x00835690
void FUN_00835690_shell::SetFlag80(bool abSet)
{
    abSet ? flags |= 0x80 : flags &= ~0x80;
}

struct Holder00832160
{
    void* FUN_00832160(unsigned int);
};
// Calls FUN_008321c0, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00832160
void* Holder00832160::FUN_00832160(unsigned int flags)
{
    reinterpret_cast<::FUN_008321c0_Class *>((this))->FUN_008321c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00832190_shell
{
    void* FUN_00832190(unsigned int);
};
// Iterates the receiver list, removing inactive receivers (or all when force is set) and detaching them from every station's receiver list.
// @fnv 0x008329a0
void FalloutRadio::RefreshRadioReceivers(bool force)
{
    struct Locals
    {
        void* result;
        RadioReceiver* deletion;
        RadioReceiver* copy;
        RadioStationState* station;
        BSSimpleList<RadioStationState*>* stationNode;
        RadioReceiver* receiver;
        BSSimpleList<RadioReceiver*>* node;
    } locals;
    locals.node = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c));
    locals.receiver = 0;
    while (locals.node && !locals.node->IsEmpty())
    {
        if (!((::FalloutRadio::RadioReceiver *)(new ((void *)(locals.node)) ::Vec3()))->active || force)
        {
            locals.receiver = ((::FalloutRadio::RadioReceiver *)(new ((void *)(locals.node)) ::Vec3()));
            reinterpret_cast<::ItemChangeListNode *>(&((*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c))))->FUN_00905330((::InventoryStackRecord *const &)(((::FalloutRadio::RadioReceiver *)(new ((void *)(locals.node)) ::Vec3()))));
            locals.node = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c));
            locals.stationNode = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554));
            while (locals.stationNode && !locals.stationNode->IsEmpty())
            {
                locals.station = ((::FalloutRadio::RadioStationState *)(new ((void *)(locals.stationNode)) ::Vec3()));
                if (locals.station)
                {
                    while (reinterpret_cast<::RefList *>(&(locals.station->receivers))->FUN_005f65d0((void **)&(locals.receiver)))
                    {
                        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(locals.receiver->sound))->FUN_00ad88f0();
                        locals.receiver->sound.Release();
                        reinterpret_cast<::ItemChangeListNode *>(&(locals.station->receivers))->FUN_00905330((::InventoryStackRecord *const &)(locals.receiver));
                    }
                }
                locals.stationNode = ((::BSSimpleList< ::FalloutRadio::RadioStationState *> *)(reinterpret_cast<::Callees *>((locals.stationNode))->FUN_00726070()));
            }
            locals.deletion = locals.receiver;
            locals.copy = locals.deletion;
            if (locals.copy)
                locals.result = reinterpret_cast<::FUN_00832190_shell *>((locals.copy))->FUN_00832190(true);
            else
                locals.result = 0;
        }
        else
            locals.node = ((::BSSimpleList< ::FalloutRadio::RadioReceiver *> *)(reinterpret_cast<::Callees *>((locals.node))->FUN_00726070()));
    }
}
// Calls FUN_008321e0, then deallocates this if flags has bit 0 set, and returns this.
// @fnv 0x00832190
void* FUN_00832190_shell::FUN_00832190(unsigned int flags)
{
    reinterpret_cast<::FUN_008321e0 *>(this)->FUN_008321e0::~FUN_008321e0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00832490_shell
{
    int _pad[5];
    int _f14;
    void SetFlag100(bool);
};
// Sets or clears bit 0x100 in the field at offset 0x14 according to the enabled argument.
// @fnv 0x00832490
void FUN_00832490_shell::SetFlag100(bool enabled)
{
    enabled ? _f14 |= 0x100 : _f14 &= ~0x100;
}

struct GlobalObject_0041a250
{
    int _00;
    int _04;
    int _08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
};
struct FUN_008327d0
{
    int _00;
    GlobalObject_0041a250 _04;
    GlobalObject_0041a250 _10;
    FUN_008327d0();
};
// Default constructor for a structure holding two GlobalObject_0041a250 members; the member constructors run implicitly.
// @fnv 0x008327d0
FUN_008327d0::FUN_008327d0()
{}

struct SL
{
    SL();
};
struct FUN_00833170
{
    int m0;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    SL m6;
    FUN_00833170();
};
// Initializes the object's fields m0 through m3 and m5 to zero.
// @fnv 0x00833170
FUN_00833170::FUN_00833170()
{
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m5 = 0;
}

// If flag is false and p is non-null, writes 1 to p[4].
// @fnv 0x008357e0
void FUN_008357e0(int* p, bool abSkip)
{
    if (!abSkip && p != 0)
    {
        int* q = p;
        q[4] = 1;
    }
}

namespace fnv_00835b90 {
struct FNVHelper00835b90
{
};
struct FUN_00833040_shell
{
};
// Returns false if DAT_011dd436 is set; otherwise resolves the target's object reference to a station and returns whether IsFlag20Set on it succeeds.
// @fnv 0x00835b90
bool FUN_00835b90(TESObjectREFR* apTargetStation)
{
    FalloutRadio::RadioConversation* pstation;
    bool bretValue;
    if (DAT_011dd436)
        return false;
    bretValue = false;
    pstation = FalloutRadio::GetRadioConversation(((::BGSTalkingActivator *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((FNVHelper00835b90*)apTargetStation)))->FUN_007af430())));
    if (pstation)
        bretValue = reinterpret_cast<::FUN_00833040_shell *>((((FUN_00833040_shell*)((char*)pstation + 4))))->IsFlag20Set();
    return bretValue;
}
}  // namespace fnv_00835b90

struct ListStandIn
{
};
struct StateStandIn
{
    TESObjectREFR* f0;
    ListStandIn f4;
    void FUN_00836660(void*);
};
// Loads game state into the radio's station, receiver and ID lists, removing entries whose form or reference no longer resolves.
// @fnv 0x00836af0
void FalloutRadio::InitLoadGame(BGSLoadGameBuffer* buffer)
{
#pragma pack(push, 1)
    struct LoadLocals
    {
        void* receiverResult;
        void* stationResult;
        RadioReceiver* receiverDeletion;
        RadioReceiver* receiverCopy;
        RadioStationState* stationDeletion;
        RadioStationState* stationCopy;
        unsigned int id;
        unsigned char padID1, padID2, padID3;
        bool removeID;
        BSSimpleList<unsigned int>* idNode;
        BSSimpleList<unsigned int>* idPrevious;
        RadioReceiver* receiver;
        unsigned char padReceiver1, padReceiver2, padReceiver3;
        bool removeReceiver;
        BSSimpleList<RadioReceiver*>* receiverNode;
        BSSimpleList<RadioReceiver*>* receiverPrevious;
        RadioStationState* station;
        unsigned char padStation1, padStation2, padStation3;
        bool removeStation;
        BSSimpleList<RadioStationState*>* stationNode;
        BSSimpleList<RadioStationState*>* stationPrevious;
        RadioReceiver* firstReceiver;
        BSSimpleList<RadioReceiver*>* firstNode;
    } locals;
#pragma pack(pop)
    void* pRefr;
    locals.firstNode = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c));
    while (locals.firstNode)
    {
        locals.firstReceiver = ((::FalloutRadio::RadioReceiver *)(new ((void *)(locals.firstNode)) ::Vec3()));
        if (locals.firstReceiver)
            reinterpret_cast<::s835fe0::RefHandle *>((reinterpret_cast<TeleportableReference*>(locals.firstReceiver)))->ResolveRef(buffer);
        locals.firstNode = ((::BSSimpleList< ::FalloutRadio::RadioReceiver *> *)(reinterpret_cast<::Callees *>((locals.firstNode))->FUN_00726070()));
    }
    locals.stationNode = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554));
    locals.stationPrevious = 0;
    while (locals.stationNode && !locals.stationNode->IsEmpty())
    {
        locals.station = ((::FalloutRadio::RadioStationState *)(new ((void *)(locals.stationNode)) ::Vec3()));
        locals.removeStation = false;
        if (locals.station)
        {
            reinterpret_cast<::StateStandIn *>((locals.station))->FUN_00836660(buffer);
            if (!locals.station->form)
            {
                locals.stationDeletion = locals.station;
                locals.stationCopy = locals.stationDeletion;
                if (locals.stationCopy)
                    locals.stationResult = reinterpret_cast<::Holder00832160 *>((locals.stationCopy))->FUN_00832160(true);
                else
                    locals.stationResult = 0;
                locals.station = 0;
                locals.removeStation = true;
            }
        }
        else
            locals.removeStation = true;
        if (locals.removeStation)
        {
            if (locals.stationPrevious)
            {
                reinterpret_cast<::ItemChangeListNode *>((locals.stationPrevious))->FUN_00905330((::InventoryStackRecord *const &)(((::FalloutRadio::RadioStationState *)(new ((void *)(locals.stationNode)) ::Vec3()))));
                locals.stationNode = ((::BSSimpleList< ::FalloutRadio::RadioStationState *> *)(reinterpret_cast<::Callees *>((locals.stationPrevious))->FUN_00726070()));
            }
            else
                locals.stationNode->RemoveHead();
        }
        else
        {
            locals.stationPrevious = locals.stationNode;
            locals.stationNode = ((::BSSimpleList< ::FalloutRadio::RadioStationState *> *)(reinterpret_cast<::Callees *>((locals.stationNode))->FUN_00726070()));
        }
    }
    locals.receiverNode = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c));
    locals.receiverPrevious = 0;
    while (locals.receiverNode && !locals.receiverNode->IsEmpty())
    {
        locals.receiver = ((::FalloutRadio::RadioReceiver *)(new ((void *)(locals.receiverNode)) ::Vec3()));
        locals.removeReceiver = false;
        if (locals.receiver)
        {
            if (!locals.receiver->form)
            {
                locals.receiverDeletion = locals.receiver;
                locals.receiverCopy = locals.receiverDeletion;
                if (locals.receiverCopy)
                    locals.receiverResult = reinterpret_cast<::FUN_00832190_shell *>((locals.receiverCopy))->FUN_00832190(true);
                else
                    locals.receiverResult = 0;
                locals.receiver = 0;
                locals.removeReceiver = true;
            }
        }
        else
            locals.removeReceiver = true;
        if (locals.removeReceiver)
        {
            if (locals.receiverPrevious)
            {
                reinterpret_cast<::ItemChangeListNode *>((locals.receiverPrevious))->FUN_00905330((::InventoryStackRecord *const &)(((::FalloutRadio::RadioReceiver *)(new ((void *)(locals.receiverNode)) ::Vec3()))));
                locals.receiverNode = ((::BSSimpleList< ::FalloutRadio::RadioReceiver *> *)(reinterpret_cast<::Callees *>((locals.receiverPrevious))->FUN_00726070()));
            }
            else
                locals.receiverNode->RemoveHead();
        }
        else
        {
            locals.receiverPrevious = locals.receiverNode;
            locals.receiverNode = ((::BSSimpleList< ::FalloutRadio::RadioReceiver *> *)(reinterpret_cast<::Callees *>((locals.receiverNode))->FUN_00726070()));
        }
    }
    if (::DAT_011dd42c)
        ::DAT_011dd42c =
            reinterpret_cast<unsigned int>(GetRadioConversation(reinterpret_cast<BGSTalkingActivator*>(::DAT_011dd42c)));
    if (DAT_011dd430)
        DAT_011dd430 =
            reinterpret_cast<unsigned int>(GetRadioConversation(reinterpret_cast<BGSTalkingActivator*>(DAT_011dd430)));
    if (buffer->vfn_0() >= 10)
    {
        locals.idNode = &(*reinterpret_cast<::BSSimpleList<unsigned int> *>(&::g_011dd59c));
        locals.idPrevious = 0;
        while (locals.idNode && !locals.idNode->IsEmpty())
        {
            locals.id = ((unsigned int)(new ((void *)(locals.idNode)) ::Vec3()));
            locals.removeID = false;
            if (locals.id)
            {
                if (locals.id)
                    pRefr = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(locals.id));
                else
                    pRefr = 0;
                locals.id = reinterpret_cast<unsigned int>(pRefr);
                if (locals.id)
                    locals.idNode->SetItem(locals.id);
                else
                    locals.removeID = true;
            }
            else
                locals.removeID = true;
            if (locals.removeID)
            {
                if (locals.idPrevious)
                {
                    reinterpret_cast<::ItemChangeListNode *>((locals.idPrevious))->FUN_00905330((::InventoryStackRecord *const &)(((unsigned int)(new ((void *)(locals.idNode)) ::Vec3()))));
                    locals.idNode = ((::BSSimpleList<unsigned int> *)(reinterpret_cast<::Callees *>((locals.idPrevious))->FUN_00726070()));
                }
                else
                    locals.idNode->RemoveHead();
            }
            else
            {
                locals.idPrevious = locals.idNode;
                locals.idNode = ((::BSSimpleList<unsigned int> *)(reinterpret_cast<::Callees *>((locals.idNode))->FUN_00726070()));
            }
        }
    }
}
// @fnv 0x00836660
void StateStandIn::FUN_00836660(void* apLoadGameBuffer)
{
    f0 = f0 ? dynamic_cast<TESObjectREFR*>(::FUN_004839c0((unsigned int)f0)) : 0;
    reinterpret_cast<::FUN_008363a0_shell *>(&(f4))->FUN_008363a0((::BGSLoadFormBuffer *)(apLoadGameBuffer));
}

namespace fnv_00837290 {
struct RadioConvTask
{
    void FUN_008372c0();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_008372c0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00837290
void* RadioConvTask::DestroyIfFlagged(unsigned int flags)
{
    FUN_008372c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_00837290

struct FUN_0083b9f0_node
{
};
struct FUN_0083b9f0_shell
{
    int _pad0;
    int _pad4;
    FUN_0083b9f0_node* _f8;
    bool FUN_0083b9f0();
};
// If _f8 is set, replaces it with the result of _ref_00726070, then returns whether _f8 is non-null and its _ref_006815c0 value is non-zero.
// @fnv 0x0083b9f0
bool FUN_0083b9f0_shell::FUN_0083b9f0()
{
    if (_f8)
        _f8 = ((::FUN_0083b9f0_node *)(reinterpret_cast<::Callees *>((_f8))->FUN_00726070()));
    return _f8 && *((int *)(new ((void *)(_f8)) ::Vec3()));
}

namespace fnv_0083c470 {
bool __fastcall _ref_008256d0(void*);
struct FUN_0083c470_holder
{
    void FUN_0083c470();
};
// @fnv 0x0083c470
void FUN_0083c470_holder::FUN_0083c470()
{
    void* pNode = this;
    while (pNode && !_ref_008256d0(pNode))
    {
        if (pNode && *((void **)(new ((void *)(pNode)) ::Vec3())))
            reinterpret_cast<::fnv_0083d130::S_0083d130_Class *>((*((void **)(new ((void *)(pNode)) ::Vec3()))))->ProcessNodeChain();
        pNode = reinterpret_cast<::Callees *>((pNode))->FUN_00726070();
    }
}
}  // namespace fnv_0083c470

namespace fnv_00833150 {
struct FUN_00833170
{
    FUN_00833170();
    void Call();
};

struct FUN_00833150_shell
{
    int a;
    FUN_00833170 b;
    int c;
    FUN_00833150_shell* FUN_00833150();
};

FUN_00833170::FUN_00833170()
{}

void FUN_00833170::Call()
{}

// @fnv 0x00833150
FUN_00833150_shell* FUN_00833150_shell::FUN_00833150()
{
    new ((void *)&(b)) ::FUN_00833170();
    return this;
}
}  // namespace fnv_00833150

struct FUN_00836470_shell
{
};

struct FUN_008366c0_shell
{
    void __thiscall FUN_008366c0(int a);
};

// @fnv 0x008366c0
void __thiscall FUN_008366c0_shell::FUN_008366c0(int a)
{
    reinterpret_cast<::S_00836470 *>((((FUN_00836470_shell*)((char*)this + 4))))->UpdateSoundItems(a);
}

struct FUN_00832420_shell
{
    char _pad[0x14];
    unsigned int mFlags;
    bool IsFlag100Set();
};

// @fnv 0x00832420
bool FUN_00832420_shell::IsFlag100Set()
{
    return (mFlags & 0x100) != 0;
}

struct FUN_00833c40_shell
{
    char _pad[0x14];
    unsigned int kData;
    void FUN_00833c40(bool enabled);
};

// @fnv 0x00833c40
void FUN_00833c40_shell::FUN_00833c40(bool enabled)
{
    enabled ? (this->kData |= 8) : (this->kData &= ~8);
}

struct FUN_00833c90_shell
{
    unsigned int pad0[5];  // +0x00 .. +0x13
    unsigned int flags;    // +0x14
    void SetFlag40(bool enabled);
};

// Sets or clears bit 0x40 in flags according to enabled.
// @fnv 0x00833c90
void FUN_00833c90_shell::SetFlag40(bool enabled)
{
    enabled ? flags |= 0x40 : flags &= ~0x40;
}

namespace fnv_008372e0 {
struct TESTopic
{
};
struct Character;
struct PlayerCharacter;
struct Conversation
{
    Conversation(Character*, Character*, TESTopic*);
    char m_data[12];
};
struct RadioConversation
{
    Character* pCharacter;
    Character* pCharacter2;
    Conversation* m_pkConversation;
};
struct QueuedFileEntry
{
    char m_data[0x30];
    RadioConversation* pCurrentRadioStation;
};
struct RadioConvTask : QueuedFileEntry
{
    void FUN_008372e0();
};

// @fnv 0x008372e0
void RadioConvTask::FUN_008372e0()
{
    if (pCurrentRadioStation && !pCurrentRadioStation->m_pkConversation)
        pCurrentRadioStation->m_pkConversation = new Conversation(
            pCurrentRadioStation->pCharacter, pCurrentRadioStation->pCharacter, ((::fnv_008372e0::TESTopic *)(::fnv_0061a2d0::GetTopicSubTypeName(7, 0))));
}
}  // namespace fnv_008372e0

class TESActorBase : public TESForm
{
  public:
};


class LoadBuffer
{
  public:
};

class SaveRef
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
    virtual void Unk10();
    virtual void Unk11();
    virtual void Unk12();
    virtual void Unk13();
    virtual void Unk14();
    virtual void Unk15();
    virtual void Unk16();
    virtual void Unk17();
    virtual void Unk18();
    virtual void Unk19();
    virtual void Unk20();
    virtual void Unk21();
    virtual void Unk22();
    virtual void Unk23();
    virtual void Unk24();
    virtual void Unk25();
    virtual void Unk26();
    virtual void Unk27();
    virtual void Unk28();
    virtual void Unk29();
    virtual void Unk30();
    virtual void Unk31();
    virtual void Unk32();
    virtual void Unk33();
    virtual void Unk34();
    virtual void Unk35();
    virtual void Unk36();
    virtual void Unk37();
    virtual void Unk38();
    virtual void Unk39();
    virtual void Unk40();
    virtual void Unk41();
    virtual void Unk42();
    virtual void Unk43();
    virtual void Unk44();
    virtual void Unk45();
    virtual void Unk46();
    virtual void Unk47();
    virtual void Unk48();
    virtual void Unk49();
    virtual void Unk50();
    virtual void Unk51();
    virtual void Unk52();
    virtual void Unk53();
    virtual void Unk54();
    virtual void Unk55();
    virtual void Unk56();
    virtual void Unk57();
    virtual void Unk58();
    virtual void Unk59();
    virtual void Unk60();
    virtual void Unk61();
    virtual void Unk62();
    virtual void Unk63();
    virtual void Unk64();
    virtual void Unk65();
    virtual void Unk66();
    virtual void Unk67();
    virtual void Unk68();
    virtual void Unk69();
    virtual void Unk70();
    virtual void Unk71();
    virtual void Unk72();
    virtual void Unk73();
    virtual void Restore(unsigned int auiID, bool abFlag);
};

struct GridCellStub
{
    SaveRef* pRef;
};

class GridCellArray
{
  public:
    GridCellStub* Get(unsigned int x, unsigned int y);
};

class DataHandlerStub
{
  public:
};

class SaveLoadStub
{
  public:
};


struct ActorEntry
{
    TESActorBase* pActor;
    unsigned short usValue;
};

template <class T> class SimpleList
{
  public:
    T m_item;
    SimpleList<T>* m_pkNext;
    void AddHead(T& item);
};

class GridHolder
{
  public:
    int unk00;
    int unk04;
    GridCellArray* pGrid;
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
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    SimpleList<ActorEntry*> kEntries;
    void Load(LoadBuffer* apBuffer);
};

// @fnv 0x004595e0
void GridHolder::Load(LoadBuffer* apBuffer)
{
    unsigned int uiActorCount = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((apBuffer))->FUN_00864a60()));
    for (unsigned int i = 0; i < uiActorCount; i++)
    {
        ActorEntry* pEntry = new ActorEntry;
        pEntry->pActor = dynamic_cast<TESActorBase*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apBuffer))->FUN_008648a0()));
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&pEntry->usValue), 2);
        kEntries.AddHead(pEntry);
    }
    unsigned int uiSize = 0;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&uiSize), 4);
    for (unsigned int x = 0; x < uiSize; x++)
    {
        for (unsigned int y = 0; y < uiSize; y++)
        {
            SaveRef* pRef = pGrid->Get(x, y)->pRef;
            unsigned int uiRefID = 0;
            reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((apBuffer))->FUN_008648e0(&uiRefID);
            if (pRef && uiRefID && reinterpret_cast<::BSShaderRenderUtility *>(((*reinterpret_cast<::DataHandlerStub * *>(&::g_dataHandler))))->IsRenderTargetId(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pRef))->FUN_0084e3a0()))))
            {
                reinterpret_cast<::FUN_0084a9c0_shell *>(((*reinterpret_cast<::SaveLoadStub * *>(&::g_BGSSaveLoadGame))))->LookupFormByID(uiRefID);
                pRef->Restore(uiRefID, true);
            }
        }
    }
}


// @fnv 0x00832830
FalloutRadio::RadioReceiver* __cdecl FUN_00832830(unsigned int aiFormID)
{
    BSSimpleList<FalloutRadio::RadioReceiver*>* pNode;
    FalloutRadio::RadioReceiver* pFound2 = 0;
    pNode = (BSSimpleList<FalloutRadio::RadioReceiver*>*)&(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554));
    unsigned int iFoundState = 0;

    if (DAT_011dd436)
        return 0;

    while (pNode != 0 && !pNode->IsEmpty())
    {
        if (aiFormID == ((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::FalloutRadio::RadioReceiver *)(new ((void *)(pNode)) ::Vec3()))->form))->FUN_007af430())))
        {
            if (pFound2 == 0 || (reinterpret_cast<::TESForm *>((pFound2->form))->GetDisabled() && !reinterpret_cast<::TESForm *>((((::FalloutRadio::RadioReceiver *)(new ((void *)(pNode)) ::Vec3()))->form))->GetDisabled()) ||
                (iFoundState == 0 && ((unsigned int)(reinterpret_cast<::fnv_0056b210::FUN_0056b210_shell *>((((::FalloutRadio::RadioReceiver *)(new ((void *)(pNode)) ::Vec3()))->form))->FUN_0056b210()))) ||
                (iFoundState != 1 && ((unsigned int)(reinterpret_cast<::fnv_0056b210::FUN_0056b210_shell *>((((::FalloutRadio::RadioReceiver *)(new ((void *)(pNode)) ::Vec3()))->form))->FUN_0056b210())) == 1))
            {
                pFound2 = ((::FalloutRadio::RadioReceiver *)(new ((void *)(pNode)) ::Vec3()));
                iFoundState = ((unsigned int)(reinterpret_cast<::fnv_0056b210::FUN_0056b210_shell *>((pFound2->form))->FUN_0056b210()));
            }
        }
        pNode = ((::BSSimpleList< ::FalloutRadio::RadioReceiver *> *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return pFound2;
}

class Character;
class TESTopic;
class Conversation
{
  public:
    void* unk00;
    void* unk04;
    void* unk08;
    Conversation(Character*, PlayerCharacter*, TESTopic*);
    ~Conversation();
};
struct RadioState
{
    Character* character;
    Conversation* current;
    Conversation* next;
};
struct FUN_00837250
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
    FUN_00837250(RadioState*);
};
struct IOManagerView
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18(FUN_00837250*);
};
// @fnv 0x00837060
bool AdvanceConversation(RadioState* state, TESTopic* apSuppliedTopic)
{
    bool queued = false;
    TESTopic* pTopic = apSuppliedTopic == 0 ? ((::TESTopic *)(::fnv_0061a2d0::GetTopicSubTypeName(7, 0))) : apSuppliedTopic;
    FUN_00837250* pTopicTask;
    if (state->next)
    {
        if (state->current)
        {
            Conversation* previous = state->current;
            Conversation* deleting = previous;
            deleting ? reinterpret_cast<::FUN_00798450_shell *>((deleting))->FUN_00798450(1) : 0;
            state->current = 0;
        }
        state->current = state->next;
        {
            Conversation* following = state->next;
            Conversation* deletingNext = following;
            deletingNext ? reinterpret_cast<::FUN_00798450_shell *>((deletingNext))->FUN_00798450(1) : 0;
            state->next = 0;
        }
        {
            pTopicTask = new FUN_00837250(state);
        }
        (*reinterpret_cast<::IOManagerView * *>(&::DAT_01202d98))->vfn18(pTopicTask);
        queued = true;
    }
    else
    {
        if (state->current)
        {
            delete state->current;
            state->current = 0;
        }
        state->current = new Conversation(state->character, (PlayerCharacter*)state->character, pTopic);
        queued = false;
    }
    return queued;
}

struct FUN_008372c0_Base
{
    virtual void vf0();
    ~FUN_008372c0_Base();
};
struct FUN_008372c0 : FUN_008372c0_Base
{
// @fnv 0x008372c0
    FUN_008372c0(int)
    {}
    virtual ~FUN_008372c0();
};
FUN_008372c0::~FUN_008372c0()
{}

namespace fnv_00832240 {
struct RefView
{
};
struct AudioClock
{
    unsigned int FUN_0063d040();
};
struct RadioSub
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, flags;
};
struct RadioState
{
    RefView* form;
    RadioSub sub;
};
RadioState* FUN_00832830(void*);
RadioState* CreateRadioStationState(RefView*, int);
// Clears DAT_011dd448, resolves a radio station from the player or the given form, stores it in g_011dd42c and updates its sub-state timers and flags.
// @fnv 0x00832240
bool FUN_00832240(RefView* form, bool flag)
{
    if (!DAT_011dd434 || DAT_011dd436)
        return false;
    ::FUN_00403d30((*reinterpret_cast<char (*)[260]>(&::DAT_011dd448)), 0, 260);
    int state = 0;
    if (!form)
    {
        BSSimpleListEx<RadioStationRef*> item;
        ::BGSTalkingActivator::FindRadioStations((TESObjectREFR*)::_g_thePlayer, (::BSSimpleList< ::TESObjectREFR *> *)(::BSSimpleList< ::RadioStationRef *> *)(&item), 0);
        BSSimpleList<RadioStationRef*>* list = &item;
        if (list && ((::RadioStationRef *)(new ((void *)(list)) ::Vec3())) && ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((RefView*)((::RadioStationRef *)(new ((void *)(list)) ::Vec3())))))->FUN_007af430())))
            form = (RefView*)((::RadioStationRef *)(new ((void *)(list)) ::Vec3()));
    }
    else if (flag)
    {
        DAT_011dd430 = 0;
        UpdateRadioSignals(true);
    }
    (*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c)) = FUN_00832830(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((form))->FUN_007af430())));
    if (!(*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c)))
    {
        (*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c)) = CreateRadioStationState(form, 0);
        if (!(*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c)))
            ::FalloutRadio::SetRadioEnabled(0);
        if (!flag)
            UpdateRadioSignals(true);
    }
    else if (((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c))->form))->FUN_007af430())) == ((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((form))->FUN_007af430())))
    {
        (*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c))->form = form;
    }
    if (reinterpret_cast<::FUN_00832420_shell *>(&((*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c))->sub))->IsFlag100Set())
    {
        (*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c))->sub.unk08 = ((::fnv_00832240::AudioClock *)(::FUN_00453a70()))->FUN_0063d040() + 50;
        reinterpret_cast<::FUN_00832490_shell *>(&((*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c))->sub))->SetFlag100(false);
    }
    reinterpret_cast<::FUN_00832440_shell *>(&((*reinterpret_cast<::fnv_00832240::RadioState * *>(&::DAT_011dd42c))->sub))->FUN_00832440(true);
    DAT_011dd430 = 0;
    return true;
}
}  // namespace fnv_00832240

namespace RadioUpdate {
extern const char DAT_0107ce80[], DAT_0107ce44[], DAT_0107ce34[], DAT_0107ce2c[], DAT_0107ce20[];
struct Station;
struct Player;
struct Vec3
{
    float x, y, z;
};
struct Sound
{
    unsigned int id;
    bool success;
    char unk05, unk06, unk07;
    int state;
    Sound(const Sound&);
    ~Sound();
    Sound& operator=(const Sound&);
};
struct String
{
    char* text;
    unsigned short length, capacity;
    String();
    String(const char*);
    ~String();
};
struct Activator
{
};
struct SoundForm
{
    const char* FUN_00511840();
};
struct Info
{
};
struct Entry
{
};
struct Track
{
};
struct Node
{
};
struct State
{
    Node* node;
    int unk04;
    unsigned int elapsed;
    int duration;
};
struct Station
{
    Activator* form;
    State state;
};
struct Manager
{
    Sound FUN_00ad7550(const char*, unsigned int);
    Sound FUN_00ad7480(const char*, unsigned int, SoundForm*);
    unsigned int FUN_0063d040();
};
struct UI
{
};
struct Player
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual const Vec3& Position();
};
int FUN_00ec7750(const char*, const char*);
void FUN_00705210(const char*, Sound, Vec3, Player*, bool);
// Updates the radio station state: plays or stops sounds, sets volume, handles voice tracks and resets the current sound when idle.
// @fnv 0x008331c0
void UpdateRadio(bool force)
{
    float volume = (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c)) ? reinterpret_cast<::FUN_00833c20_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833c20() / ::g_d100 : 0.0;
    bool volumeSet = false;
    if ((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c)) && reinterpret_cast<::FUN_00833bc0_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->IsFlagSet())
    {
        String message3;
        Sound sound = ((::RadioUpdate::Manager *)(::FUN_00453a70()))->FUN_00ad7550(DAT_0107ce80, 0x100121);
        reinterpret_cast<::FUN_00ad8830_shell *>(&(sound))->FUN_00ad8830(0);
        ::FUN_00406f60((::FUN_00406f90_this *)(::RadioUpdate::String *)(&message3), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::RadioUpdate::String *>(&::g_011d25f8))))->GetMenuTitle())), reinterpret_cast<::FUN_0055d520_shell *>(((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->form))->FUN_0055d520());
        (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd430)) = (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c));
        ::FalloutRadio::SetRadioEnabled(0);
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->Release();
        reinterpret_cast<::MessageHUD *>(((*reinterpret_cast<::RadioUpdate::UI * *>(&::g_pHudMainMenuInstance))))->AddMessage(((const char *)(::FUN_00559450((int *)&(message3)))), 0, DAT_0107ce44, (const char *)(0), ::DAT_010162c0, 0);
        return;
    }
    else if ((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c)) && reinterpret_cast<::FUN_00833c20_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833c20() < 100)
    {
        if (!reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->IsValid())
        {
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->Release();
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::RadioUpdate::Sound &)((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->operator=((const ::SoundPlaybackHandle &)((const ::RadioUpdate::Sound &)(((::RadioUpdate::Manager *)(::FUN_00453a70()))->FUN_00ad7550(DAT_0107ce34, 0x100031))));
            reinterpret_cast<::FUN_00ad8830_shell *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->FUN_00ad8830(0);
        }
        reinterpret_cast<::FUN_00ad89e0_shell *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->FUN_00ad89e0(
            ::FUN_004dd150((100 - reinterpret_cast<::FUN_00833c20_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833c20()) / ::g_d100, ::DAT_01016264));
    }
    else if ((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c)) && reinterpret_cast<::FUN_00833c20_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833c20() == 100 && reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->IsValid())
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd638))))->Release();
    }
    if ((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c)) && (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.duration <= 0 && reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->IsValid() && ::FUN_00ad8b30((unsigned int *)&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc)))))
        (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.duration = ::FUN_00ad8b30((unsigned int *)&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))));
    if ((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c)) && (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.node && ((!::FUN_00830750(7, 1) && !reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->IsValid()) || force))
    {
        Track* track = ((::RadioUpdate::Track *)(reinterpret_cast<::DialogueItem *>(((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.node))->GetActiveResponse()));
        if (!track)
            return;
        bool hasVoice_ = false;
        bool FlushUsageData = false;
        bool hasSound3 = false;
        unsigned int kindB = 0;
        if (!((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse())))
            reinterpret_cast<::DialogueItem *>((track))->SelectDefaultResponseList();
        if (((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse())) && ((::RadioUpdate::SoundForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse()))))->FUN_007af430())) && !((bool)(::FUN_00833ce0())))
        {
            hasVoice_ = true;
            if ((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c)))
                reinterpret_cast<::FUN_00833c40_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833c40(true);
        }
        else
        {
            if ((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c)))
                reinterpret_cast<::FUN_00833c40_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833c40(false);
        }
        if (((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse())) && ((const char *)(::FUN_00559450((int *)(((::RadioUpdate::String *)(new ((void *)(((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse())))) ::Vec3())))))))
        {
            kindB = ::FUN_0044a670(((const char *)(::FUN_00559450((int *)(((::RadioUpdate::String *)(new ((void *)(((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse())))) ::Vec3())))))));
            hasSound3 = kindB > 2 && reinterpret_cast<::FUN_00700270_class *>((((::RadioUpdate::Info *)(::FUN_00460140((int)(((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse()))))))))->operator==(0);
            if (!hasSound3 && ((::RadioUpdate::SoundForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse()))))->FUN_007af430())) &&
                FUN_00ec7750(::FUN_00511840((char *)(((::RadioUpdate::SoundForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse()))))->FUN_007af430())))), DAT_0107ce2c))
                hasSound3 = true;
        }
        unsigned int age = ((::RadioUpdate::Manager *)(::FUN_00453a70()))->FUN_0063d040() - (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.elapsed;
        if (hasSound3)
        {
            bool formSound = ((::RadioUpdate::SoundForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse()))))->FUN_007af430())) != 0;
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->Release();
            if (formSound)
                reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::RadioUpdate::Sound &)((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->operator=((const ::SoundPlaybackHandle &)((const ::RadioUpdate::Sound &)(((::RadioUpdate::Manager *)(::FUN_00453a70()))->FUN_00ad7480(::FUN_00511840((char *)(((::RadioUpdate::SoundForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse()))))->FUN_007af430())))),
                                                            0x100101, ((::RadioUpdate::SoundForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse()))))->FUN_007af430()))))));
            else
                reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::RadioUpdate::Sound &)((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->operator=((const ::SoundPlaybackHandle &)((const ::RadioUpdate::Sound &)(((::RadioUpdate::Manager *)(::FUN_00453a70()))->FUN_00ad7480(((const char *)(::FUN_00559450((int *)(((::RadioUpdate::Info *)(::FUN_00460140((int)(((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse())))))))))), 0x100101, 0))));
            reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->SetCompletionCallback((void (*)(void *, bool))(((void (&)(RadioUpdate::Station *))::FUN_008357e0)), (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c)));
            reinterpret_cast<::fnv_00ad8fd0::FUN_00ad8fd0_h *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_00ad8fd0((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.elapsed);
            if (((bool)(::FUN_00833cf0())))
                reinterpret_cast<::FUN_00ad89e0_shell *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_00ad89e0(volume * ::DAT_0101ffa0);
            else
                reinterpret_cast<::FUN_00ad89e0_shell *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_00ad89e0(reinterpret_cast<::BSAudio *>((((::RadioUpdate::Manager *)(::FUN_00453a70()))))->GetMusicVolume() * volume);
            volumeSet = true;
            reinterpret_cast<::FUN_00ad8830_shell *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_00ad8830(0);
            if (!reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->IsValid())
                FUN_00705210(((const char *)(::FUN_00559450((int *)(((::RadioUpdate::String *)(new ((void *)(((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse())))) ::Vec3())))))), (*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc)),
                             (*reinterpret_cast<::RadioUpdate::Player * *>(&::_g_thePlayer))->Position(), (*reinterpret_cast<::RadioUpdate::Player * *>(&::_g_thePlayer)), false);
        }
        if (hasVoice_ && !((bool)(::FUN_00833ce0())))
        {
            char path2[260];
            ::FUN_00406d00(path2, 260, ::DAT_0101996c, DAT_0107ce20, ::FUN_00511840((char *)(((::RadioUpdate::SoundForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdate::Entry *)(reinterpret_cast<::DialogueItem *>((track))->GetActiveResponse()))))->FUN_007af430())))));
            String filename(path2);
            ::fnv_008300c0::PlayAudioMedia(7, path2, 500, 0, 1, 0.0f, (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.elapsed);
            ::TaskQueueInterface::CopyStringToBuffer((*reinterpret_cast<char (*)[260]>(&::DAT_011dd448)), 260, path2);
            reinterpret_cast<::FUN_00833c40_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833c40(true);
            if ((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.duration <= 0 && ::FUN_008308c0(7) > 0)
                (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.duration = ::FUN_008308c0(7);
        }
        else
            reinterpret_cast<::FUN_00833c40_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833c40(false);
        if (!hasVoice_ && !hasSound3)
            (*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state.duration = 1;
    }
    else if (!reinterpret_cast<::FUN_00833040_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->IsFlag20Set() && !::IsFlag80Set((void *)&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state)) &&
             !((bool)(reinterpret_cast<::FUN_00833be0_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833be0())) && !reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->IsPlaying())
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->Release();
        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::RadioUpdate::Sound &)((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->operator=((const ::SoundPlaybackHandle &)((const ::RadioUpdate::Sound &)(((::RadioUpdate::Manager *)(::FUN_00453a70()))->FUN_00ad7550(DAT_0107ce34, 0x100031))));
        reinterpret_cast<::FUN_004f15a0_shell *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_004f15a0(1);
        reinterpret_cast<::FUN_00ad8830_shell *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_00ad8830(0);
        reinterpret_cast<::FUN_00833c90_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->SetFlag40(true);
        reinterpret_cast<::FUN_00833c40_shell *>(&((*reinterpret_cast<::RadioUpdate::Station * *>(&::DAT_011dd42c))->state))->FUN_00833c40(false);
    }
    if (!volumeSet)
    {
        if (((bool)(::FUN_00833cf0())))
            reinterpret_cast<::FUN_00ad89e0_shell *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_00ad89e0(volume * ::DAT_0101ffa0);
        else
            reinterpret_cast<::FUN_00ad89e0_shell *>(&((*reinterpret_cast<::RadioUpdate::Sound *>(&::g_011dd5bc))))->FUN_00ad89e0(reinterpret_cast<::BSAudio *>((((::RadioUpdate::Manager *)(::FUN_00453a70()))))->GetMusicVolume() * volume);
    }
}
}

struct S_008356e0_Item
{
};
struct S_008356e0_Node
{
};
struct S_008356e0_Ref;

// Builds a list via FUN_004ff1a0 from b or DAT_011dea3c, walks it, and returns the first item whose FUN_007af430 equals a.
// @fnv 0x008356e0
S_008356e0_Item* __cdecl FUN_008356e0(int a, S_008356e0_Ref* apRef)
{
    S_008356e0_Item* result = 0;
    BSSimpleListEx<S_008356e0_Item*> _list;
    if (apRef == 0)
    {
        ::BGSTalkingActivator::FindRadioStations((::TESObjectREFR *)((*reinterpret_cast<::S_008356e0_Ref * *>(&::_g_thePlayer))), (::BSSimpleList< ::TESObjectREFR *> *)(::BSSimpleListEx< ::S_008356e0_Item *> *)(&_list), (::BSSimpleList<float> *)(0));
    }
    else
    {
        ::BGSTalkingActivator::FindRadioStations((::TESObjectREFR *)(apRef), (::BSSimpleList< ::TESObjectREFR *> *)(::BSSimpleListEx< ::S_008356e0_Item *> *)(&_list), (::BSSimpleList<float> *)(0));
    }
    S_008356e0_Node* node = (S_008356e0_Node*)&_list;
    bool foundTmp = false;
    while (!foundTmp && node && *((::S_008356e0_Item **)(new ((void *)(node)) ::Vec3())) && ((int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*((::S_008356e0_Item **)(new ((void *)(node)) ::Vec3())))))->FUN_007af430())))
    {
        if (a == ((int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*((::S_008356e0_Item **)(new ((void *)(node)) ::Vec3())))))->FUN_007af430())))
        {
            result = *((::S_008356e0_Item **)(new ((void *)(node)) ::Vec3()));
            foundTmp = true;
        }
        node = ((::S_008356e0_Node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
    return result;
}

#include <windows.h>

namespace radio_detail {
struct FUN_008327d0
{
    void* form;
    SoundPlaybackHandle sound;
    int unk10;
    int unk14;
    int unk18;
    unsigned char active;
    unsigned char playing;
    unsigned char unk1e;
    unsigned char changed;
    FUN_008327d0();
};
}
struct ReceiverList
{
    void FUN_005ae3d0(radio_detail::FUN_008327d0**);
};
struct StationView
{
    void* form;
    FUN_00832440_shell state;
    ReceiverList receivers;
};
struct ReferenceView
{
};
struct AudioView
{
    unsigned int FUN_0063d040();
};
StationView* FUN_00832830(void*);
StationView* CreateRadioStationState(void*, ReferenceView*);
// Creates or finds the radio station for ref, marks it active/playing/changed, registers it with the receiver list and enables the receiver state.
// @fnv 0x00835810
void FUN_00835810(TESObjectREFR_Stub* ref, ReferenceView* source)
{
    int elapsed = 0;
    radio_detail::FUN_008327d0* station = (radio_detail::FUN_008327d0*)FUN_00832930(ref);
    unsigned int soundTime = 0;
    bool created = false;
    if (DAT_011dd436)
        return;
    StationView* receiver = FUN_00832830(((void *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((source))->FUN_007af430())));
    if (receiver)
        soundTime = ((::AudioView *)(::FUN_00453a70()))->FUN_0063d040() - receiver->state.pad2_8;
    else
    {
        receiver = CreateRadioStationState(ref, source);
        if (receiver && !receiver->form)
            DebugBreak();
        if (!receiver)
            return;
    }
    if (!station)
    {
        station = new radio_detail::FUN_008327d0;
        created = true;
    }
    station->form = ref;
    station->active = 1;
    station->playing = 1;
    station->changed = 1;
    if (created)
        ((ReceiverList*)&(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c)))->FUN_005ae3d0(&station);
    receiver->receivers.FUN_005ae3d0(&station);
    receiver->state.FUN_00832440(true);
}

namespace fnv_008359e0 {
struct Conversation
{
    ~Conversation();
};
struct RadioStateData
{
    Conversation* conversation;
    unsigned int unk04, unk08, unk0c, unk10, flags;
};
struct RadioStation
{
    void* form;
    RadioStateData data;
    BSSimpleList<FalloutRadio::RadioReceiver*> receivers;
};
struct RadioRef
{
};
struct RadioSource
{
};
struct SoundHandleHelper : SoundPlaybackHandle
{
};
RadioStation* FUN_00832830(RadioRef*);
struct GlobalObject_0044fae0
{
};
// @fnv 0x008359e0
void FUN_008359e0(RadioSource* source, bool enabled)
{
    if (DAT_011dd436)
        return;
    RadioStation* station = FUN_00832830(((::fnv_008359e0::RadioRef *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((source))->FUN_007af430())));
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::fnv_008359e0::GlobalObject_0044fae0 *>(&::g_011dd5e8))))->FUN_004538a0((int)("FalloutRadio::SetBroadcastState"));
    reinterpret_cast<::TESObjectREFR_Flags *>((((::fnv_008359e0::RadioRef *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((source))->FUN_007af430()))))->SetRefFlag40000000(enabled);
    if (station)
    {
        if (reinterpret_cast<::FUN_00833040_shell *>(&(station->data))->IsFlag20Set() && !enabled)
        {
            BSSimpleList<FalloutRadio::RadioReceiver*>* node = &station->receivers;
            while (node && !_ref_008256d0(node))
            {
                if (reinterpret_cast<::SoundPlaybackHandle *>((((SoundHandleHelper*)&(*((::FalloutRadio::RadioReceiver **)(new ((void *)(node)) ::Vec3())))->sound)))->IsValid())
                {
                    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*((::FalloutRadio::RadioReceiver **)(new ((void *)(node)) ::Vec3())))->sound))->FUN_00ad88f0();
                    (*((::FalloutRadio::RadioReceiver **)(new ((void *)(node)) ::Vec3())))->sound.Release();
                }
                node = ((::BSSimpleList< ::FalloutRadio::RadioReceiver *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
            }
            if (::DAT_011dd42c == (unsigned int)station && DAT_011dd434)
            {
                reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc))))->FUN_00ad88f0();
                (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)).Release();
                if (!FUN_00833ce0())
                {
                    ::FalloutAudioMedia::BeginMediaUpdate();
                    ::FUN_008325a0(true);
                    ::fnv_008300c0::PlayAudioMedia(7, 0, 1000, false, false, 0.0f, 0);
                    ::FalloutAudioMedia::EndMediaUpdate();
                }
            }
            reinterpret_cast<::FUN_008330b0_shell *>(&(station->data))->SetFlag(false);
            delete station->data.conversation;
            station->data.conversation = 0;
        }
        reinterpret_cast<::FUN_00833100_shell *>(&(station->data))->FUN_00833100(enabled);
    }
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::fnv_008359e0::GlobalObject_0044fae0 *>(&::g_011dd5e8))))->WaitForTasksDuringRendering();
}
}  // namespace fnv_008359e0

// Iterates the radio receiver list, calls FUN_008366c0 on each receiver, removes null entries, then calls FUN_008324e0 and UpdateRadio.
// @fnv 0x00836e20
void __cdecl UpdateRadioReceivers(int updateMode)
{
    BSSimpleList<FalloutRadio::RadioStationState*>* current = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554));
    BSSimpleList<FalloutRadio::RadioStationState*>* previous = 0;
    while (current != 0 && !current->IsEmpty())
    {
        FalloutRadio::RadioStationState* receiver = ((::FalloutRadio::RadioStationState *)(new ((void *)(current)) ::Vec3()));
        bool remove = false;
        if (receiver != 0)
            reinterpret_cast<FUN_008366c0_shell*>(receiver)->FUN_008366c0(updateMode);
        else
            remove = true;
        if (remove)
        {
            if (previous != 0)
            {
                reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330((::InventoryStackRecord *const &)(((::FalloutRadio::RadioStationState *)(new ((void *)(current)) ::Vec3()))));
                current = ((::BSSimpleList< ::FalloutRadio::RadioStationState *> *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
            }
            else
                current->RemoveHead();
        }
        else
        {
            previous = current;
            current = ((::BSSimpleList< ::FalloutRadio::RadioStationState *> *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
        }
    }
    ::FalloutRadio::SetRadioEnabled(DAT_011dd434);
    if (::DAT_011dd42c != 0)
        ::RadioUpdate::UpdateRadio(true);
}

struct FUN_00832160
{
    ~FUN_00832160();
};
struct SoundCleanup
{
};
struct FUN_00832190
{
    void* form;
    SoundCleanup sound;
    ~FUN_00832190();
};
struct RadioListCleanup
{
};
// Resets radio globals, deletes all queued items from two lists, and stops the sound objects in the radio lists.
// @fnv 0x00836ef0
void ResetRadioGlobals()
{
    ::DAT_011dd42c = 0;
    DAT_011dd430 = 0;
    DAT_011dd424 = 1;
    DAT_011dd428 = 0;
    DAT_011dd434 = false;
    DAT_011a179c = 1;
    DAT_011dd448 = false;
    while (!(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554)).IsEmpty())
    {
        delete reinterpret_cast<FUN_00832160*>(((::FalloutRadio::RadioStationState *)(new ((void *)&((*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554)))) ::Vec3())));
        (*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554)).RemoveHead();
    }
    while (!(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c)).IsEmpty())
    {
        FUN_00832190* receiver = reinterpret_cast<FUN_00832190*>(((::FalloutRadio::RadioReceiver *)(new ((void *)&((*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c)))) ::Vec3())));
        if (reinterpret_cast<::SoundPlaybackHandle *>(&(receiver->sound))->IsValid())
        {
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(receiver->sound))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&(receiver->sound))->Release();
        }
        delete receiver;
        (*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c)).RemoveHead();
    }
    reinterpret_cast<::FileMatchList *>(&(reinterpret_cast<RadioListCleanup&>((*reinterpret_cast<::BSSimpleList<unsigned int> *>(&::g_011dd59c)))))->RemoveAll();
    if (reinterpret_cast<::SoundPlaybackHandle *>(&(reinterpret_cast<SoundCleanup&>((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->IsValid())
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(reinterpret_cast<SoundCleanup&>((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&(reinterpret_cast<SoundCleanup&>((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->Release();
    }
    if (reinterpret_cast<::SoundPlaybackHandle *>(&(reinterpret_cast<SoundCleanup&>((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd638)))))->IsValid())
    {
        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(reinterpret_cast<SoundCleanup&>((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd638)))))->FUN_00ad88f0();
        reinterpret_cast<::SoundPlaybackHandle *>(&(reinterpret_cast<SoundCleanup&>((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd638)))))->Release();
    }
}

// 0x008325b0  /MT /Od /Oy- /GS /EHsc /Gy

class Rec;

struct SndH
{
    unsigned int m_uiSoundResourceID;
    unsigned char m_bLooping;
    unsigned char pad[3];
    unsigned int eState;
};

class Rec
{
  public:
    Rec();
    void* form;
    SndH snd;
    SndH snd2;
    unsigned char active;
    unsigned char f1d;
    unsigned char f1e;
    unsigned char f1f;
};

struct RecList
{
    void SetItem(Rec*& r);
};

struct Sta
{
    void* form;
    SndH sound;
    int pad[3];
    RecList receivers;
};

class Form2
{
  public:
    int GetFormType();
};

class Ref
{
  public:
};

class EffSetting : public Form2
{
  public:
};

class BSAud
{
  public:
    unsigned int GetSynchTime();
};

Rec* __cdecl FUN_00832930(Ref*);
Sta* __cdecl FUN_00832830(TESSound*);
Sta* __cdecl CreateRadioStationState(Ref*, bool);

class Shell
{
  public:
    static void FUN_008325b0(Ref* ref, bool bArg);
};

// Enables or disables the bolt sound for a reference, creating or releasing its sound record and updating the sound state.
// @fnv 0x008325b0
void Shell::FUN_008325b0(Ref* ref, bool abEnable)
{
    if (DAT_011dd436)
    {
        return;
    }
    TESSound* pSound8 = 0;
    Rec* rec = FUN_00832930(ref);
    int iUnused = 0;
    bool bNewRec = false;
    if (rec != 0 && ((abEnable && rec->active) || (!abEnable && !rec->active)))
    {
        return;
    }
    if (ref != 0 && ((::Form2 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430()))->GetFormType() == 0x15)
    {
        pSound8 = ((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((EffSetting*)((::Form2 *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((ref))->FUN_007af430())))))));
    }
    if (pSound8 == 0)
    {
        return;
    }
    Sta* sta = FUN_00832830(pSound8);
    if (abEnable)
    {
        if (sta == 0)
        {
            sta = CreateRadioStationState(ref, 0);
            if (sta == 0)
            {
                return;
            }
        }
        if (rec == 0)
        {
            rec = new Rec();
            bNewRec = true;
        }
        rec->form = ref;
        rec->active = 1;
        rec->f1d = 1;
        rec->f1f = 0;
        if (bNewRec)
        {
            ((RecList*)&(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c)))->SetItem(rec);
        }
        sta->receivers.SetItem(rec);
        reinterpret_cast<::FUN_00832440_shell *>(&(sta->sound))->FUN_00832440(1);
        if (reinterpret_cast<::FUN_00832420_shell *>(&(sta->sound))->IsFlag100Set())
        {
            sta->sound.eState = ((::BSAud *)(::FUN_00453a70()))->GetSynchTime() + 0x32;
            reinterpret_cast<::FUN_00832490_shell *>(&(sta->sound))->SetFlag100(0);
        }
    }
    else
    {
        if (rec != 0)
        {
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(rec->snd))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&(rec->snd))->Release();
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&(rec->snd2))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&(rec->snd2))->Release();
            rec->active = 0;
            ::FalloutRadio::RefreshRadioReceivers(0);
        }
    }
}

namespace fnv_00832cb0 {
class P01ObjA
{
  public:
};

class FUN_00475120_shell
{
  public:
    int GetFormType();
};

class EffectSetting
{
  public:
};

class FUN_00832160
{
  public:
    ~FUN_00832160();
};

class FUN_00833100_shell
{
  public:
};

class FUN_00833040_shell
{
  public:
};

class FUN_008330b0_shell
{
  public:
};

class FUN_00833060_shell
{
  public:
};

class BSAudio
{
  public:
    unsigned int GetSynchTime();
};


class G2
{
  public:
    void AddHead(int*&);
};


class FUN_00833150 : public FalloutRadio::RadioStationState
{
  public:
    FUN_00833150();
};

class MyForm : public TESForm
{
  public:
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual bool vfn_b4();
};

class MyREFR : public TESObjectREFR
{
  public:
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual bool vfn_100();
};

struct StationData
{
    void* form;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned char unk14;
    unsigned char unk15;
};

// Builds a new radio station state from a1 (and a2), resolving the station form via sound or activator, initialising timing fields and adding it to the list.
// @fnv 0x00832cb0
FalloutRadio::RadioStationState* CreateRadioStationState(TESObjectREFR* a1, TESObjectREFR* a2)
{
    FalloutRadio::RadioStationState* state3;
    bool isTalkingActivator;
    bool isStation3;
    void* stationForm3;
    TESSound* sound;
    void* space5;

    if (!a1)
        return 0;

    isStation3 = false;
    isTalkingActivator = false;
    stationForm3 = 0;

    state3 = new FUN_00833150();

    if (((FUN_00475120_shell*)((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)a1)))->FUN_007af430())))->GetFormType() == 0x15 ||
        ((FUN_00475120_shell*)((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)a1)))->FUN_007af430())))->GetFormType() == 0x2a ||
        ((FUN_00475120_shell*)((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)a1)))->FUN_007af430())))->GetFormType() == 0x2b ||
        ((FUN_00475120_shell*)((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)a1)))->FUN_007af430())))->GetFormType() == 0x2c ||
        ((FUN_00475120_shell*)((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)a1)))->FUN_007af430())))->GetFormType() == 0x2d)
    {
        isStation3 = true;
    }

    if (((FUN_00475120_shell*)((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)a1)))->FUN_007af430())))->GetFormType() == 0x16)
    {
        isTalkingActivator = true;
    }

    if (isStation3 && !((MyREFR*)a1)->vfn_100())
    {
        sound = ((::TESSound *)(::fnv_004fd3c0::FUN_004fd3c0((::fnv_004fd3c0::TESSaveLoadGame *)(((EffectSetting*)((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)a1)))->FUN_007af430())))))));
        if (!sound)
        {
            delete ((FUN_00832160*)state3);
            return 0;
        }
        stationForm3 = ((void *)(::FUN_008356e0((int)(sound), (::S_008356e0_Ref *)(a1))));
        if (!stationForm3)
        {
            delete ((FUN_00832160*)state3);
            return 0;
        }
    }
    else if (isStation3 && ((MyREFR*)a1)->vfn_100() && a2)
    {
        space5 = ((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)a2)))->FUN_007af430()));
        if (!space5)
        {
            delete ((FUN_00832160*)state3);
            return 0;
        }
        stationForm3 = ((void *)(::FUN_008356e0((int)(space5), (::S_008356e0_Ref *)(a1))));
        if (!stationForm3)
        {
            delete ((FUN_00832160*)state3);
            return 0;
        }
    }
    else if (isTalkingActivator)
    {
        stationForm3 = a1;
    }

    if (!stationForm3)
    {
        delete ((FUN_00832160*)state3);
        return 0;
    }

    ((StationData*)state3)->form = stationForm3;
    ((StationData*)state3)->unk04 = 0;
    ((StationData*)state3)->unk08 = 0;

    ((StationData*)state3)->unk0C = ((::fnv_00832cb0::BSAudio *)(::FUN_00453a70()))->GetSynchTime() - ::GetRandomNumberInRange(0, 30000);
    ((StationData*)state3)->unk10 = 1;

    reinterpret_cast<::FUN_00833100_shell *>((((FUN_00833100_shell*)((char*)state3 + 4))))->FUN_00833100(((MyForm*)((::TESForm *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((P01ObjA*)((StationData*)state3)->form)))->FUN_007af430())))->vfn_b4());
    reinterpret_cast<::FUN_008330b0_shell *>((((FUN_008330b0_shell*)((char*)state3 + 4))))->SetFlag(reinterpret_cast<::FUN_00833040_shell *>((((FUN_00833040_shell*)((char*)state3 + 4))))->IsFlag20Set());
    reinterpret_cast<::FUN_00833060_shell *>((((FUN_00833060_shell*)((char*)state3 + 4))))->FUN_00833060(true);

    ((StationData*)state3)->unk14 = 0x64;
    ((StationData*)state3)->unk15 = 0x64;

    ((G2*)&(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554)))->AddHead((int*&)state3);

    return state3;
}
}  // namespace fnv_00832cb0

namespace fnv_008366e0 {


struct LoadBuffer : BGSLoadGameBuffer
{





};

struct RadioStationSaveView : FalloutRadio::RadioStationState
{
};

struct RadioForm
{

};

// Reads radio receiver, station, and form data from a load buffer, initializing each item and writing back the counts.
// @fnv 0x008366e0
void __cdecl FUN_008366e0(LoadBuffer* buffer)

{

    unsigned int secondID5;

    unsigned int receiverNode4;

    FalloutRadio::RadioReceiver* formID;

    unsigned int formCount;

    BSSimpleList<FalloutRadio::RadioReceiver*>* stationPosition4;

    unsigned int firstID2;

    unsigned int receiverCount;

    unsigned int stationCount;

    BSSimpleList<FalloutRadio::RadioStationState*>* formNode2;

    FalloutRadio::RadioStationState* receiverPosition;

    unsigned int station_2;

    unsigned int formPosition4;

    BSSimpleList<unsigned int>* stationNode;

    unsigned int receiver5;

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&::DAT_011dd428, 4, 0);

    reinterpret_cast<::FUN_00865e50_shell *>((buffer))->FUN_00865e50(&DAT_011dd434, 1, 0);

    reinterpret_cast<::FUN_00865e70_shell *>((buffer))->FUN_00865e70((const char *)(void *)(&(*reinterpret_cast<unsigned int *>(&::DAT_011dd448))), 0);

    firstID2 = 0;

    formCount = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();

    stationPosition4 = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c));

    while (stationPosition4)
    {

        formID = ((::FalloutRadio::RadioReceiver *)(new ((void *)(stationPosition4)) ::Vec3()));

        if (formID)
        {

            reinterpret_cast<::FUN_00835f10_shell *>((formID))->FUN_00835f10((::BGSSaveFormBuffer *)(buffer));

            ++firstID2;
        }

        stationPosition4 = ((::BSSimpleList< ::FalloutRadio::RadioReceiver *> *)(reinterpret_cast<::Callees *>((stationPosition4))->FUN_00726070()));
    }

    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(firstID2, formCount);

    stationCount = 0;

    receiverCount = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();

    formNode2 = &(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554));

    while (formNode2)
    {

        receiverPosition = ((::FalloutRadio::RadioStationState *)(new ((void *)(formNode2)) ::Vec3()));

        if (receiverPosition)
        {

            reinterpret_cast<::FUN_00836600_class *>((((RadioStationSaveView*)receiverPosition)))->FUN_00836600((::BGSLoadFormBuffer *)(buffer));

            ++stationCount;
        }

        formNode2 = ((::BSSimpleList< ::FalloutRadio::RadioStationState *> *)(reinterpret_cast<::Callees *>((formNode2))->FUN_00726070()));
    }

    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(stationCount, receiverCount);

    secondID5 = 0;

    if (::DAT_011dd42c)

        secondID5 = ((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*(RadioForm**)::DAT_011dd42c)))->FUN_007af430()));

    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(secondID5), 0);

    receiverNode4 = 0;

    if (DAT_011dd430)

        receiverNode4 = ((unsigned int)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*(RadioForm**)DAT_011dd430)))->FUN_007af430()));

    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(receiverNode4), 0);

    station_2 = 0;

    formPosition4 = reinterpret_cast<::FUN_00865f20_shell *>((buffer))->FUN_00865f20();

    stationNode = &(*reinterpret_cast<::BSSimpleList<unsigned int> *>(&::g_011dd59c));

    while (stationNode)
    {

        receiver5 = ((unsigned int)(new ((void *)(stationNode)) ::Vec3()));

        if (receiver5)
        {

            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(receiver5), 0);

            ++station_2;
        }

        stationNode = ((::BSSimpleList<unsigned int> *)(reinterpret_cast<::Callees *>((stationNode))->FUN_00726070()));
    }

    reinterpret_cast<::FUN_00865ff0_shell *>((buffer))->FUN_00865ff0(station_2, formPosition4);
}
}  // namespace fnv_008366e0

static const char radioUpdateProfile[] = "FalloutRadio::UpdateStation";
static const char radioUpdateStaticSound[] = "UIRadioStaticLP";
static const char radioUpdateMonoSuffix[] = "_mono.";

struct RadioUpdateVec3
{
    float x, y, z;
    RadioUpdateVec3 operator-(const RadioUpdateVec3& o) const;
};

class RadioUpdateSndHandle
{
  public:
    unsigned int id;
    unsigned char b;
    unsigned int st;
    ~RadioUpdateSndHandle();
    RadioUpdateSndHandle& operator=(const RadioUpdateSndHandle&);
};

class RadioUpdateSnd
{
  public:
};

class RadioUpdateCell
{
  public:
};

class TESBoundObject : public TESForm
{
};

class RadioUpdateBoundName
{
  public:
    const char* FUN_00511840();
};

class TESObjectACTI : public TESBoundObject
{
  public:
};

class RadioUpdateActivator
{
  public:
    RadioUpdateSnd* FUN_00407840();
};

class RadioUpdateObj
{
  public:
    RadioUpdateSnd* FUN_00407840();
    const char* FUN_00511840();
    int FUN_004181e0();
    ~RadioUpdateObj();
};

class RadioUpdateRefObj
{
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual bool v100();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual RadioUpdateVec3* v1f4();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual bool v21c();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual float v284(char*, RadioUpdateSndHandle*, void*, RadioUpdateObj*, int, void*, void*, RadioUpdateRefObj*, int,
                       int, int, int, int);
    int FUN_004181e0();
};

struct RadioUpdateReceiver
{
    RadioUpdateRefObj* ref;
    RadioUpdateSndHandle snd4;
    RadioUpdateSndHandle snd10;
    unsigned char active;
    unsigned char b1d;
};

class RadioUpdateRList
{
  public:
    RadioUpdateReceiver* m_item;
    RadioUpdateRList* m_next;
    bool FUN_008256d0();
};

class RadioUpdateSub4
{
  public:
    RadioUpdateObj* ptr;
};

struct RadioUpdateState
{
    RadioUpdateObj* form;
    RadioUpdateSub4 sub;
    int f8;
    unsigned int fc;
    int f10;
    int f14;
    int f18;
    RadioUpdateRList list;
};

class RadioUpdateTimer
{
  public:
    unsigned int FUN_0063d040();
};

class RadioUpdateAudio
{
  public:
    void FUN_00ad78e0(RadioUpdateVec3*);
    unsigned int FUN_0063d040();
    RadioUpdateSndHandle FUN_00ad7550(const char*, unsigned int);
    RadioUpdateSndHandle FUN_00ad7480(const char*, unsigned int, RadioUpdateSnd*);
};

class RadioUpdateProf
{
  public:
};

class RadioUpdateFSetting
{
  public:
};

unsigned char __cdecl FUN_00833ce0();
void __cdecl FUN_00406d50(char*, unsigned int, const char*);
char* __cdecl FUN_0043b9d0(const char*, int);
void* __cdecl DynCast(void*, int, void*, void*, int);

extern char DAT_01186584;

// @fnv 0x00834260
void __cdecl FUN_00834260(FalloutRadio::RadioStationState* apState)
{
    bool aEnabled = false;
    bool aFlag = false;
    bool aSame = false;
    bool bFound = false;
    unsigned int aCont = 0;
    unsigned char aTmp = 100;
    bool aState = false;
    bool aCur = false;

    if (!((RadioUpdateState*)apState) || !((RadioUpdateState*)apState)->form)
        return;

    bool aDone = reinterpret_cast<::TESForm *>((((RadioUpdateState*)apState)->form))->GetDisabled();
    bool aTag = (DAT_011dd43c & 1) != 0;
    bool bVal = (DAT_011dd43c & 2) != 0;
    bool bCurrentVal = ((RadioUpdateState*)apState) == ((RadioUpdateState*)::DAT_011dd42c);
    float aBound = 3000.0f;
    RadioUpdateVec3 aLight;
    ((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_00ad78e0(&aLight);
    reinterpret_cast<::GlobalObject_0044fae0 *>(&((*reinterpret_cast<::RadioUpdateProf *>(&::g_011dd5e8))))->FUN_004538a0((int)(radioUpdateProfile));
    RadioUpdateObj* aActor =
        ((RadioUpdateState*)apState)->sub.ptr ? ((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse())) : 0;
    RadioUpdateRList* aNext = &((RadioUpdateState*)apState)->list;

    if (DAT_011dd436)
        return;

    if (!bCurrentVal && ((RadioUpdateState*)apState)->list.FUN_008256d0())
    {
        reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::RadioUpdateProf *>(&::g_011dd5e8))))->WaitForTasksDuringRendering();
        return;
    }

    RadioUpdateSnd* aData = ((RadioUpdateSnd*)DAT_011dd440);
    if (((RadioUpdateState*)apState) && ((RadioUpdateState*)apState)->form)
    {
        TESObjectACTI* act = dynamic_cast<TESObjectACTI*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((RadioUpdateState*)apState)->form))->FUN_007af430())));
        if (act && ((::RadioUpdateSnd *)(reinterpret_cast<::TESPackage *>((((RadioUpdateActivator*)act)))->GetRefCount())))
            aData = ((::RadioUpdateSnd *)(reinterpret_cast<::TESPackage *>((((RadioUpdateActivator*)act)))->GetRefCount()));
    }

    if (aDone || aTag || bVal)
    {
        RadioUpdateRList* it = &((RadioUpdateState*)apState)->list;
        while (it && !it->FUN_008256d0())
        {
            if (reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->snd4))->IsValid())
            {
                if (aDone)
                {
                    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->snd4))->FUN_00ad88f0();
                    reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->snd4))->Release();
                    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->snd10))->FUN_00ad88f0();
                    reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->snd10))->Release();
                }
                else if (aTag)
                {
                    reinterpret_cast<::FUN_00ad88b0_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->snd4))->FUN_00ad88b0();
                    reinterpret_cast<::FUN_00ad88b0_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->snd10))->FUN_00ad88b0();
                }
                else if (bVal && (*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->active)
                {
                    reinterpret_cast<::FUN_00ad8830_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->snd4))->FUN_00ad8830(0);
                    reinterpret_cast<::FUN_00ad8830_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(it)) ::Vec3())))->snd10))->FUN_00ad8830(0);
                }
            }
            it = ((::RadioUpdateRList *)(reinterpret_cast<::Callees *>((it))->FUN_00726070()));
        }
        if (bCurrentVal)
        {
            if (aDone)
                ::FalloutRadio::SetRadioEnabled(0);
            if (((RadioUpdateState*)::DAT_011dd42c) && reinterpret_cast<::FUN_00835670_shell *>(&(((RadioUpdateState*)::DAT_011dd42c)->sub))->IsFlag8Set())
            {
                if (aTag)
                {
                    reinterpret_cast<::FUN_00ad88b0_h *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd638)))))->FUN_00ad88b0();
                    FUN_008305e0();
                }
                else if (bVal)
                {
                    reinterpret_cast<::FUN_00ad8830_shell *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd638)))))->FUN_00ad8830(0);
                    ResetThreadFlags();
                }
            }
            else if (aTag)
            {
                reinterpret_cast<::FUN_00ad88b0_h *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd638)))))->FUN_00ad88b0();
                reinterpret_cast<::FUN_00ad88b0_h *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->FUN_00ad88b0();
            }
            else if (bVal)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd638)))))->FUN_00ad8830(0);
                reinterpret_cast<::FUN_00ad8830_shell *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->FUN_00ad8830(0);
            }
        }
        reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::RadioUpdateProf *>(&::g_011dd5e8))))->WaitForTasksDuringRendering();
        return;
    }

    if (((RadioUpdateState*)apState)->f10 <= 0 && ((RadioUpdateState*)apState) == ((RadioUpdateState*)::DAT_011dd42c))
    {
        if (reinterpret_cast<::SoundPlaybackHandle *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->IsValid())
            ((RadioUpdateState*)apState)->f10 = ::FUN_00ad8b30((unsigned int *)&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))));
        else if (aActor && ((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse()))))->FUN_007af430())) && ((int)(::FUN_008308c0(7))))
            ((RadioUpdateState*)apState)->f10 = ((int)(::FUN_008308c0(7)));
    }

    unsigned int aIndex = ((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_0063d040();
    if (((RadioUpdateState*)apState)->fc > aIndex + 100)
        ((RadioUpdateState*)apState)->fc = aIndex;

    if (((RadioUpdateState*)apState) && ((RadioUpdateState*)apState)->f10 > 0 &&
        ((RadioUpdateState*)apState)->fc + ((RadioUpdateState*)apState)->f10 < aIndex)
    {
        bool b4d = false;
        if (((RadioUpdateState*)apState)->sub.ptr && ((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse())))
        {
            if (reinterpret_cast<::FUN_0083b9f0_shell *>((((RadioUpdateState*)apState)->sub.ptr))->FUN_0083b9f0())
            {
                b4d = true;
                if (((::RadioUpdateObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse()))))->FUN_0084e3a0())) &&
                    !::FUN_00579200((const char *)(((::RadioUpdateObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse()))))->FUN_0084e3a0())))))
                    reinterpret_cast<::FUN_0061f170_cls *>((((::RadioUpdateObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)
                        ->sub.ptr))->GetActiveResponse()))))->FUN_0084e3a0()))))->FUN_0061f170((void *)(0), (::ArgObj *)(((RadioUpdateState*)apState)->form));
                reinterpret_cast<::DialogueItem *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse()))))->SelectDefaultResponseList();
                ((RadioUpdateState*)apState)->fc = ((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_0063d040() + 50;
                ((RadioUpdateState*)apState)->f10 = 0;
                if (((RadioUpdateState*)apState)->list.FUN_008256d0() && !((RadioUpdateState*)::DAT_011dd42c))
                    reinterpret_cast<::FUN_00832490_shell *>(&(((RadioUpdateState*)apState)->sub))->SetFlag100(1);
            }
            else
            {
                delete ((RadioUpdateState*)apState)->sub.ptr;
                ((RadioUpdateState*)apState)->sub.ptr = 0;
                aActor = 0;
                ((RadioUpdateState*)apState)->fc = 0;
                ((RadioUpdateState*)apState)->f10 = 0;
                if (::IsFlag80Set((void *)&(((RadioUpdateState*)apState)->sub)))
                    reinterpret_cast<::FUN_00835690_shell *>(&(((RadioUpdateState*)apState)->sub))->SetFlag80(0);
            }
            aNext = &((RadioUpdateState*)apState)->list;
            while (aNext && !aNext->FUN_008256d0())
            {
                reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->FUN_00ad88f0();
                reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->Release();
                aNext = ((::RadioUpdateRList *)(reinterpret_cast<::Callees *>((aNext))->FUN_00726070()));
            }
            if (((RadioUpdateState*)apState) == ((RadioUpdateState*)::DAT_011dd42c))
            {
                reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->FUN_00ad88f0();
                reinterpret_cast<::SoundPlaybackHandle *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->Release();
                if (!FUN_00833ce0())
                {
                    ::FalloutAudioMedia::BeginMediaUpdate();
                    ::FUN_008325a0(1);
                    ::fnv_008300c0::PlayAudioMedia(7, 0, 1000, 0, 0, 0.0f, 0);
                    ::FalloutAudioMedia::EndMediaUpdate();
                }
            }
        }
        if (!((RadioUpdateState*)apState)->sub.ptr || !((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse())))
        {
            if (reinterpret_cast<::FUN_00833040_shell *>(&(((RadioUpdateState*)apState)->sub))->IsFlag20Set())
            {
                reinterpret_cast<::FUN_008330b0_shell *>(&(((RadioUpdateState*)apState)->sub))->SetFlag(1);
                ::AdvanceConversation((::RadioState *)(::RadioUpdateState *)(((RadioUpdateState*)apState)), (::TESTopic *)(0));
                reinterpret_cast<::fnv_0083c470::FUN_0083c470_holder *>((((RadioUpdateState*)apState)->sub.ptr))->FUN_0083c470();
                reinterpret_cast<::Mid83b9a0 *>((((RadioUpdateState*)apState)->sub.ptr))->FUN_0083b9a0();
                if (((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse())))
                {
                    aActor = ((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse()));
                    if (((::RadioUpdateObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse()))))->FUN_0084e3a0())) &&
                        !::FUN_00579200((const char *)(((::RadioUpdateObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse()))))->FUN_0084e3a0())))))
                        reinterpret_cast<::FUN_0061f170_cls *>((((::RadioUpdateObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)
                            ->sub.ptr))->GetActiveResponse()))))->FUN_0084e3a0()))))->FUN_0061f170((void *)(0), (::ArgObj *)(((RadioUpdateState*)apState)->form));
                    reinterpret_cast<::DialogueItem *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse()))))->SelectDefaultResponseList();
                    ((RadioUpdateState*)apState)->fc = ((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_0063d040() + 50;
                    ((RadioUpdateState*)apState)->f10 = 0;
                    aNext = &((RadioUpdateState*)apState)->list;
                    while (aNext && !aNext->FUN_008256d0())
                    {
                        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->FUN_00ad88f0();
                        reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->Release();
                        aNext = ((::RadioUpdateRList *)(reinterpret_cast<::Callees *>((aNext))->FUN_00726070()));
                    }
                    if (((RadioUpdateState*)apState) == ((RadioUpdateState*)::DAT_011dd42c))
                    {
                        reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->FUN_00ad88f0();
                        reinterpret_cast<::SoundPlaybackHandle *>(&((*(RadioUpdateSndHandle*)&(*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd5bc)))))->Release();
                    }
                }
            }
            else
            {
                reinterpret_cast<::FUN_008330b0_shell *>(&(((RadioUpdateState*)apState)->sub))->SetFlag(0);
            }
        }
    }

    if (((RadioUpdateState*)apState)->sub.ptr && ((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse())))
    {
        aActor = ((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((((RadioUpdateState*)apState)->sub.ptr))->GetActiveResponse()));
        if (!((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse())) && !reinterpret_cast<::FUN_0083c7e0_shell *>((aActor))->FUN_0083c7e0())
        {
            ((RadioUpdateState*)apState)->fc = ((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_0063d040() + 50;
            ((RadioUpdateState*)apState)->f10 = 1;
        }
    }

    reinterpret_cast<::FUN_00632d20_shell *>(&(((RadioUpdateState*)apState)->sub))->FUN_00632d20(((bool)(::GetByteAtOffset17((const char *)&(((RadioUpdateState*)apState)->sub)))));
    aTmp = reinterpret_cast<::FUN_00833c20_shell *>(&(((RadioUpdateState*)apState)->sub))->FUN_00833c20();
    if (aTmp < 100)
        bFound = true;

    aNext = &((RadioUpdateState*)apState)->list;
    while (aNext && !aNext->FUN_008256d0())
    {
        if (!(*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->active)
        {
            aNext = ((::RadioUpdateRList *)(reinterpret_cast<::Callees *>((aNext))->FUN_00726070()));
            continue;
        }
        if (((RadioUpdateState*)apState)->f10 <= 0 && reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->IsValid() &&
            ::FUN_00ad8b30((unsigned int *)&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4)))
            ((RadioUpdateState*)apState)->f10 = ::FUN_00ad8b30((unsigned int *)&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4));

        RadioUpdateVec3 pos = (*reinterpret_cast<::RadioUpdateVec3 *>((void *)&::NiPoint3::ZERO));
        pos.x = 3.402823466e+38F;
        pos.y = 3.402823466e+38F;
        pos.z = 3.402823466e+38F;
        if (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())) && (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref)
        {
            pos = *(*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref->v1f4();
        }
        else if (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())) && !(*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref)
        {
            (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->active = 0;
            aNext = ((::RadioUpdateRList *)(reinterpret_cast<::Callees *>((aNext))->FUN_00726070()));
            continue;
        }

        if ((((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((RadioUpdateObj*)(*reinterpret_cast<::S_008356e0_Ref * *>(&::_g_thePlayer)))))->FUN_00575d70())) &&
             ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((((RadioUpdateObj*)(*reinterpret_cast<::S_008356e0_Ref * *>(&::_g_thePlayer)))))->FUN_00575d70())) != ((void *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref))->FUN_00575d70()))) ||
            (reinterpret_cast<::TESObjectCELL *>((((::RadioUpdateCell *)(reinterpret_cast<::LowProcess *>((((RadioUpdateObj*)(*reinterpret_cast<::S_008356e0_Ref * *>(&::_g_thePlayer)))))->GetTarget()))))->IsCellInterior() &&
             ((::RadioUpdateCell *)(reinterpret_cast<::LowProcess *>(((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref))->GetTarget())) != ((::RadioUpdateCell *)(reinterpret_cast<::LowProcess *>((((RadioUpdateObj*)(*reinterpret_cast<::S_008356e0_Ref * *>(&::_g_thePlayer)))))->GetTarget()))))
        {
            reinterpret_cast<::FUN_00ad89e0_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->FUN_00ad89e0(0.0f);
            (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->active = 0;
        }

        if (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())) && reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->IsValid())
            reinterpret_cast<::FUN_00ad8b60_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->FUN_00ad8b60(pos.x, pos.y, pos.z);

        if (bFound && !reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->IsValid())
        {
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->Release();
            reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::RadioUpdateSndHandle &)((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->operator=((const ::SoundPlaybackHandle &)((const ::RadioUpdateSndHandle &)(((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_00ad7550(radioUpdateStaticSound, 0x100012))));
            reinterpret_cast<::FUN_004f15a0_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->FUN_004f15a0(1);
            reinterpret_cast<::FUN_00ad8b60_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->FUN_00ad8b60(pos.x, pos.y, pos.z);
            reinterpret_cast<::FUN_00ad89e0_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->FUN_00ad89e0(FUN_004dd150((float)(100 - aTmp) / 100.0, 0.75f));
            reinterpret_cast<::FUN_00ad8830_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->FUN_00ad8830(0);
        }
        else if (bFound)
        {
            reinterpret_cast<::FUN_00ad89e0_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->FUN_00ad89e0(FUN_004dd150((float)(100 - aTmp) / 100.0, 0.75f));
            reinterpret_cast<::FUN_00ad8b60_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->FUN_00ad8b60(pos.x, pos.y, pos.z);
        }
        else if (!bFound && reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->IsValid())
        {
            reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->FUN_00ad88f0();
            reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd10))->Release();
        }

        if (aActor && !reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->IsValid() &&
            reinterpret_cast<::FUN_00835650_shell *>(&(((RadioUpdateState*)apState)->sub))->FUN_00835650() && (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->active &&
            (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref)
        {
            if (aActor && ((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse())))
            {
                char buf[0x104];
                if (((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse()))))->FUN_007af430())))
                    aEnabled = true;
                if (((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse())) && ((const char *)(::FUN_00559450((int *)(((::RadioUpdateObj *)(new ((void *)(((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse())))) ::Vec3())))))))
                {
                    aCont = ::FUN_0044a670((const char *)(::RadioUpdateObj *)((RadioUpdateObj*)((const char *)(::FUN_00559450((int *)(((::RadioUpdateObj *)(new ((void *)(((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse())))) ::Vec3()))))))));
                    aSame = aCont > 1 && ((const char *)(::FUN_00559450((int *)(((::RadioUpdateObj *)(::FUN_00460140((int)(((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse()))))))))));
                }
                if (aEnabled)
                {
                    ::TaskQueueInterface::CopyStringToBuffer(buf, 0x104,
                                 ::FUN_00511840((char *)(((RadioUpdateBoundName*)((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse()))))->FUN_007af430()))))));
                    if (!((int)(::FUN_004812f0(buf, radioUpdateMonoSuffix))))
                    {
                        char* dot = FUN_0043b9d0(buf, '.');
                        if (dot)
                        {
                            char ext[4];
                            ::TaskQueueInterface::CopyStringToBuffer(ext, 4, dot + 1);
                            *dot = 0;
                            FUN_00406d50(buf, 0x104, radioUpdateMonoSuffix);
                            FUN_00406d50(buf, 0x104, ext);
                        }
                    }
                    reinterpret_cast<::FUN_00833c40_shell *>(&(((RadioUpdateState*)apState)->sub))->FUN_00833c40(1);
                }
                else if (aSame)
                {
                    ::TaskQueueInterface::CopyStringToBuffer(buf, 0x104, ((const char *)(::FUN_00559450((int *)(((::RadioUpdateObj *)(::FUN_00460140((int)(((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse())))))))))));
                    reinterpret_cast<::FUN_00833c40_shell *>(&(((RadioUpdateState*)apState)->sub))->FUN_00833c40(0);
                }
                else
                {
                    ((RadioUpdateState*)apState)->f10 = 1;
                    aNext = ((::RadioUpdateRList *)(reinterpret_cast<::Callees *>((aNext))->FUN_00726070()));
                    reinterpret_cast<::FUN_00833c40_shell *>(&(((RadioUpdateState*)apState)->sub))->FUN_00833c40(0);
                    continue;
                }

                bool bSame = false;
                bool bNpcVal = false;
                RadioUpdateRefObj* aRec = 0;
                if ((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref && (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref->v100())
                {
                    aRec = (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref;
                    if (((::RadioUpdateObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((aActor))->FUN_0084e3a0())) && ((int)(reinterpret_cast<::Actor *>((aRec))->GetActorBase())) == ((int)(reinterpret_cast<::Twin_00639b40 *>((((::RadioUpdateObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((aActor))->FUN_0084e3a0()))))->GetEntryPoint())))
                        bSame = true;
                    if (aRec->v21c())
                        bNpcVal = true;
                }
                if (aData && !bNpcVal)
                    aBound = reinterpret_cast<::TESSound *>((aData))->GetField45() * 110.0;
                else if (bNpcVal)
                    aBound = *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RadioUpdateFSetting *>(&::g_011dd62c)))))) * 1.100000023841858;

                if (aBound < reinterpret_cast<::NiPoint3 *>((void *)(void *)&(const ::RadioUpdateVec3 &)((aLight - pos)))->ComputeMagnitude())
                {
                    aNext = ((::RadioUpdateRList *)(reinterpret_cast<::Callees *>((aNext))->FUN_00726070()));
                    continue;
                }
                int elapsed = ((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_0063d040() - ((RadioUpdateState*)apState)->fc;
                if (aRec && bSame)
                {
                    aRec->v284(buf, &(*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4, ((void *)(reinterpret_cast<::Twin_0044ddc0 *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse()))))->GetName())),
                               ((::RadioUpdateObj *)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse()))))->FUN_0084e3a0())), 0x96, ((void *)(reinterpret_cast<::FUN_009611e0_shell *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse()))))->FUN_009611e0())),
                               ((void *)(reinterpret_cast<::BGSTerrainManager *>((((::RadioUpdateObj *)(reinterpret_cast<::DialogueItem *>((aActor))->GetActiveResponse()))))->GetMinLevel())), (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref, 0, 0, 0, 1, 1);
                }
                else
                {
                    unsigned int flags = 0;
                    if (bNpcVal)
                    {
                        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::RadioUpdateSndHandle &)((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->operator=((const ::SoundPlaybackHandle &)((const ::RadioUpdateSndHandle &)(((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_00ad7480(buf, flags | 0x500102, 0))));
                        reinterpret_cast<::FUN_00ad8be0_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))
                            ->snd4))->FUN_00ad8be0(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RadioUpdateFSetting *>(&::g_011dd5b0)))))), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::RadioUpdateFSetting *>(&::g_011dd62c)))))));
                    }
                    else
                    {
                        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::RadioUpdateSndHandle &)((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->operator=((const ::SoundPlaybackHandle &)((const ::RadioUpdateSndHandle &)(((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_00ad7480(buf, flags | 0x500102, aData))));
                    }
                    reinterpret_cast<::SoundPlaybackHandle *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->SetCompletionCallback((void (*)(void *, bool))(((void (&)(void *))::FUN_008357e0)), ((RadioUpdateState*)apState));
                    reinterpret_cast<::fnv_00ad8fd0::FUN_00ad8fd0_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->FUN_00ad8fd0(((RadioUpdateState*)apState)->fc);
                    reinterpret_cast<::FUN_00ad8b60_h *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->FUN_00ad8b60(pos.x, pos.y, pos.z);
                    reinterpret_cast<::FUN_00ad89e0_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->FUN_00ad89e0((float)aTmp / 100.0);
                    reinterpret_cast<::FUN_00ad8830_shell *>(&((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->snd4))->FUN_00ad8830(0);
                }
                if (bCurrentVal && !(*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->b1d && !aState)
                {
                    aState = true;
                    ::RadioUpdate::UpdateRadio(1);
                }
                if ((*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->b1d)
                    (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->b1d = 0;
            }
            else if (aActor && !reinterpret_cast<::FUN_0083c7e0_shell *>((aActor))->FUN_0083c7e0() && !reinterpret_cast<::DialogueItem *>((aActor))->SelectDefaultResponseList())
            {
                ((RadioUpdateState*)apState)->fc = ((RadioUpdateAudio*)((::AudioView *)(::FUN_00453a70())))->FUN_0063d040() + 50;
                ((RadioUpdateState*)apState)->f10 = 1;
            }
        }
        else if (!(*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->ref)
        {
            (*((::RadioUpdateReceiver **)(new ((void *)(aNext)) ::Vec3())))->active = 0;
        }
        aNext = ((::RadioUpdateRList *)(reinterpret_cast<::Callees *>((aNext))->FUN_00726070()));
    }

    if (((RadioUpdateState*)apState) == ((RadioUpdateState*)::DAT_011dd42c) && !aState)
        ::RadioUpdate::UpdateRadio(0);
    reinterpret_cast<::ActorTaskManager *>(&((*reinterpret_cast<::RadioUpdateProf *>(&::g_011dd5e8))))->WaitForTasksDuringRendering();
}

class RadioLoadBufferView : public BGSLoadGameBuffer
{
  public:
};

struct RadioLoadReceiverEntry : public ::radio_detail::FUN_008327d0
{
    __forceinline RadioLoadReceiverEntry() : ::radio_detail::FUN_008327d0()
    {}
};

template <class T> struct RadioLoadListView : public BSSimpleList<T>
{
    void FUN_005ae3d0(T* item);
};


struct RadioLoadStationEntry : public ::fnv_00832cb0::FUN_00833150
{
    __forceinline RadioLoadStationEntry() : ::fnv_00832cb0::FUN_00833150()
    {}
};

struct RadioLoadReceiverView : public FalloutRadio::RadioReceiver
{
};

struct RadioLoadStationView : public FalloutRadio::RadioStationState
{
};

// @fnv 0x008368b0
void FUN_008368b0(BGSLoadGameBuffer* apBuffer)
{
    ::TESBoundObject* f;
    ::TESBoundObject* eb;
    unsigned int cf;
    unsigned int q;
    FalloutRadio::RadioReceiver* b;
    unsigned int ba;
    unsigned int k;
    FalloutRadio::RadioStationState* l;
    unsigned int c;
    unsigned int e;
    unsigned int j;

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((RadioLoadBufferView*)apBuffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&::DAT_011dd428), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((((RadioLoadBufferView*)apBuffer)))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&DAT_011dd434), 1);
    reinterpret_cast<::fnv_008649a0::FUN_008649a0_shell *>((((RadioLoadBufferView*)apBuffer)))->FUN_008649a0((*reinterpret_cast<char (*)[260]>(&::DAT_011dd448)));

    cf = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((((RadioLoadBufferView*)apBuffer)))->FUN_00864a60()));
    for (q = 0; q < cf; ++q)
    {
        b = (FalloutRadio::RadioReceiver*)new RadioLoadReceiverEntry();
        reinterpret_cast<::FUN_00835f80_shell *>((((RadioLoadReceiverView*)b)))->FUN_00835f80((::BGSLoadFormBuffer *)(apBuffer));
        ((RadioLoadListView<FalloutRadio::RadioReceiver*>*)&(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioReceiver *> *>(&::g_011dd58c)))->FUN_005ae3d0(&b);
    }

    ba = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((((RadioLoadBufferView*)apBuffer)))->FUN_00864a60()));
    for (k = 0; k < ba; ++k)
    {
        l = (FalloutRadio::RadioStationState*)new RadioLoadStationEntry();
        reinterpret_cast<::FUN_00836630 *>((((RadioLoadStationView*)l)))->LoadGame((::BGSLoadFormBuffer *)(apBuffer));
        ((RadioLoadListView<FalloutRadio::RadioStationState*>*)&(*reinterpret_cast<::BSSimpleList< ::FalloutRadio::RadioStationState *> *>(&::g_011dd554)))->FUN_005ae3d0(&l);
    }

    f = 0;
    f = dynamic_cast< ::TESBoundObject*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((((RadioLoadBufferView*)apBuffer)))->FUN_008648a0()));
    ::DAT_011dd42c = (unsigned int)f;

    eb = 0;
    eb = dynamic_cast< ::TESBoundObject*>(FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((((RadioLoadBufferView*)apBuffer)))->FUN_008648a0()));
    DAT_011dd430 = (unsigned int)eb;

    if (apBuffer->vfn_0() >= 10)
    {
        c = ((unsigned int)(reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((((RadioLoadBufferView*)apBuffer)))->FUN_00864a60()));
        for (e = 0; e < c; ++e)
        {
            j = 0;
            reinterpret_cast<::fnv_008648e0::FUN_008648e0_shell *>((((RadioLoadBufferView*)apBuffer)))->FUN_008648e0(&j);
            ((RadioLoadListView<unsigned int>*)&(*reinterpret_cast<::BSSimpleList<unsigned int> *>(&::g_011dd59c)))->FUN_005ae3d0(&j);
        }
    }
}
