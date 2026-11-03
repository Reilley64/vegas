// fallout/audio/falloutaudio.cpp: SoundPlaybackManager, PlayerCharacter, std, Interface and more (14 functions)

#include "fnv/simple_list_node_view.h"
#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/C6b7f20_Map.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004516b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00547590_shell.h"
#include "fnv/decl/FUN_0063a610_shell.h"
#include "fnv/decl/FUN_0063dd50_shell.h"
#include "fnv/decl/FUN_0063e210_shell.h"
#include "fnv/decl/FUN_0063e2f0_shell.h"
#include "fnv/decl/FUN_0068a810_class.h"
#include "fnv/decl/FUN_0082d6e0_Class.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00ad79b0_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad8b60_h.h"
#include "fnv/decl/FUN_00ad8d60_shell.h"
#include "fnv/decl/FUN_00ad9030_shell.h"
#include "fnv/decl/GList.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/RainSystem.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004188d0__FUN_004188d0_shell.h"
#include "fnv/decl/fnv_00455690__FUN_00455690_shell.h"
#include "fnv/decl/fnv_0063ef20__FUN_0063ef20_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_00ad7fa0__AudioUpdateStand.h"
#include "fnv/decl/fnv_00ad8100__FUN_00ad8100_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_004df000.h"
#include "fnv/symbols_00511000.h"
#include "fnv/symbols_0058a000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e3000.h"
#include "fnv/symbols_0069b000.h"
#include "fnv/symbols_0082d000.h"
#include "fnv/symbols_00839000.h"
#include "fnv/symbols_00966000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011cc000.h"
#include "fnv/symbols_011dc000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
#include "falloutaudio_decls.h"
// Updates ambient and region sounds from the player's target acoustic space, weather and time of day, starting/stopping sound handles and pruning stale ones.
// @fnv 0x0082d7c0
void SoundPlaybackManager::ProcessPendingSounds()
{
    bool updated = false;
    SoundPlaybackHandle* pendingHandle = 0;
    SoundPlaybackHandle* existingHandle;
    float fStartHour;
    float soundEndHour;
    BSSimpleList<RegionSound*>* sounds = ::_g_thePlayer->GetRegionSounds();
    bool isSubmerged = ::FUN_00453a70()->FUN_00ad7c50();
    BGSAcousticSpace* acousticSpace = !::_g_thePlayer                ? 0
                                      : !::_g_thePlayer->GetTarget() ? 0
                                                                  : reinterpret_cast<::FUN_00547590_shell *>((::_g_thePlayer->GetTarget()))->FUN_00547590();
    if ((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)) && !((bool)(::GetByteAtOffset48((void *)((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))))) && acousticSpace && ((bool)(::GetByteAtOffset48((void *)(acousticSpace)))))
    {
        SetAcousticSpace(acousticSpace);
        DAT_011dcfb1 = false;
        DAT_011dcfb8 = 0;
    }
    if (DAT_011dcfb1)
    {
        if (DAT_011dcfb8 == (*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))
        {
            DAT_011dcfb8 = 0;
            DAT_011dcfb1 = false;
        }
        else
            SetAcousticSpace(DAT_011dcfb8);
    }
    if (!DAT_011dcfa8)
    {
        DAT_011dcfa8 = (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->GetSoundByEditorID("UIActivateNothing");
        if (DAT_011dcfa8)
            reinterpret_cast<::fnv_00ad8100::FUN_00ad8100_shell *>((::FUN_00453a70()))->FUN_00ad8100((char *)(::FUN_00511840((char *)(DAT_011dcfa8))), 0x121, DAT_011dcfa8);
    }
    if (!(*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)) && ::_g_thePlayer && ::_g_thePlayer->GetTarget() &&
        reinterpret_cast<::FUN_00547590_shell *>((::_g_thePlayer->GetTarget()))->FUN_00547590() != (*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))
        SetAcousticSpace(reinterpret_cast<::FUN_00547590_shell *>((::_g_thePlayer->GetTarget()))->FUN_00547590());
    else if (!::_g_thePlayer || (!::_g_thePlayer->GetTarget() && !::_g_thePlayer->IsRegionSoundsEnabled()))
        ResetAcousticSpace(0);
    if ((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)) && (*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4))->GetDecalTextureSet())
    {
        RegionSoundSource source;
        source.region = (*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4))->GetDecalTextureSet();
        source.data = ((::TESRegionData *)(reinterpret_cast<::GList *>((((::RegionDataList *)(reinterpret_cast<::FUN_009611e0_shell *>((source.region))->FUN_009611e0()))))->FUN_004f35b0(7)));
        if (source.data)
            sounds = ((::BSSimpleList< ::RegionSound *> *)(::GetOffsetC((int)(source.data))));
    }
    if ((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))
        reinterpret_cast<::FUN_00ad79b0_shell *>((::FUN_00453a70()))->FUN_00ad79b0(reinterpret_cast<::FUN_0068a810_class *>(((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4))))->GetField4C());
    else
        reinterpret_cast<::FUN_00ad79b0_shell *>((::FUN_00453a70()))->FUN_00ad79b0(0);
    if (isSubmerged && ::_g_thePlayer->GetTarget() && !reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0a0))))->IsPlaying())
    {
        (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0a0)) = ::FUN_00453a70()->GetSoundHandleByEditorID("AMBUnderwaterLP", 0x2101);
        reinterpret_cast<::FUN_004f15a0_shell *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0a0))))->FUN_004f15a0(1);
        reinterpret_cast<::FUN_00ad8830_shell *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0a0))))->FUN_00ad8830(false);
    }
    else if ((!isSubmerged || !::_g_thePlayer->GetTarget()) && reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0a0))))->IsPlaying())
        (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0a0)).StopWithFade(300);
    ::fnv_00839ab0::InitFootstepImpacts();
    ::InitializeSlots();
    if (DAT_011dcfa6)
        return;
    Sky* pWeatherSky = ((::Sky *)(reinterpret_cast<::BSShaderNoLightingProperty *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetBaseTexture()));
    float time = pWeatherSky ? ::GetFieldEC((const char *)(pWeatherSky)) : 0.0f;
    ::FUN_00453a70()->FUN_00ad77f0(time, 0);
    if (std::abs(::FUN_00453a70()->GetCurrentTimeMilliseconds() - DAT_011dcfc0) > 1000)
    {
        if (::_g_thePlayer)
            ::_g_thePlayer->ResetRegionSoundTimer();
        if (!Interface::GetSelectedTargetIndex(Interface::MenuLoading))
            reinterpret_cast<::fnv_00455690::FUN_00455690_shell *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00455690();
        float fade = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd044))))))->f;
        if (reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->IsPlaying())
            fade = ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd094))))))->f;
        if ((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)) && ::_g_thePlayer)
        {
            if (((bool)(::GetByteAtOffset48((void *)((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))))))
            {
                bool changed = DAT_011dcfb1;
                if (!reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->IsValid())
                    changed = true;
                if (changed)
                {
                    if (DAT_011dcfb1)
                    {
                        DAT_011dcfb8 = 0;
                        DAT_011dcfb1 = false;
                    }
                    if (reinterpret_cast<::SoundPlaybackHandle *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->IsPlaying())
                    {
                        (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8)).StopWithFade((unsigned int)(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd050))))))->f * 500.0));
                        reinterpret_cast<::fnv_004188d0::FUN_004188d0_shell *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->FUN_004188d0();
                    }
                    DAT_011dcfb0 = false;
                    TESSound* sound = ((::TESSound *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<LowProcess*>((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))))->GetPrevPath()));
                    if (sound)
                    {
                        (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8)) = ::FUN_00453a70()->GetSoundHandleByFilePath(::FUN_00511840((char *)(sound)),
                                                                                                  0x11011, sound);
                        reinterpret_cast<::FUN_00ad8d60_shell *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->FUN_00ad8d60((unsigned int)(fade * 1000.0));
                    }
                }
            }
            else
            {
                bool changed = DAT_011dcfb1;
                if (!changed)
                {
                    switch (DAT_011dcfac)
                    {
                    case 0:
                        if (time > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f6dcc))))))->f)
                            changed = true;
                        break;
                    case 1:
                        if (time > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f6dd8))))))->f)
                            changed = true;
                        break;
                    case 2:
                        if (time > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f6de4))))))->f)
                            changed = true;
                        break;
                    case 3:
                        if (time > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f6dc0))))))->f && time < ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f6de4))))))->f)
                            changed = true;
                        break;
                    }
                }
                if (changed)
                {
                    if (DAT_011dcfb1)
                    {
                        DAT_011dcfb8 = 0;
                        DAT_011dcfb1 = false;
                    }
                    else
                    {
                        (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8)).StopWithFade((unsigned int)(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd050))))))->f * 1000.0));
                        reinterpret_cast<::fnv_004188d0::FUN_004188d0_shell *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->FUN_004188d0();
                    }
                    DAT_011dcfb0 = false;
                    TESSound* sound;
                    if (time > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f6dc0))))))->f)
                    {
                        if (time > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f6dcc))))))->f)
                        {
                            if (time > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f6dd8))))))->f)
                            {
                                if (time > ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011f6de4))))))->f)
                                {
                                    sound = reinterpret_cast<LowProcess*>((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))->GetTarget();
                                    DAT_011dcfac = 3;
                                }
                                else
                                {
                                    sound = ((::TESSound *)(reinterpret_cast<::Twin_00639b40 *>((reinterpret_cast<TESTopicInfo*>((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))))->GetEntryPoint()));
                                    DAT_011dcfac = 2;
                                }
                            }
                            else
                            {
                                sound = ((::TESSound *)(::GetField38((char *)(reinterpret_cast<TESTopicInfo*>((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))))));
                                DAT_011dcfac = 1;
                            }
                        }
                        else
                        {
                            sound = ((::TESSound *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<LowProcess*>((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))))->GetPrevPath()));
                            DAT_011dcfac = 0;
                        }
                    }
                    else
                    {
                        sound = reinterpret_cast<LowProcess*>((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))->GetTarget();
                        DAT_011dcfac = 3;
                    }
                    if (sound)
                    {
                        (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8)) = ::FUN_00453a70()->GetSoundHandleByFilePath(::FUN_00511840((char *)(sound)),
                                                                                                  0x11011, sound);
                        reinterpret_cast<::FUN_00ad8d60_shell *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->FUN_00ad8d60((unsigned int)(fade * 1000.0));
                    }
                }
            }
        }
        else
        {
            (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8)).StopWithFade(1000);
            reinterpret_cast<::fnv_004188d0::FUN_004188d0_shell *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->FUN_004188d0();
        }
        if (!sounds->IsEmpty() && !Interface::GetSelectedTargetIndex(Interface::MenuLoading))
        {
            updated = true;
            BSSimpleList<RegionSound*>* pRegionCursor = sounds;
            RegionSound* soundEntry = 0;
            TESSound* pActiveSound = 0;
            SoundPlaybackHandle* loopSoundHandle = 0;
            SoundPlaybackHandle kPlaybackHandle(false);
            NiPoint3 location;
            bool isSoundAllowed = true;
            bool looping = false;
            bool soundFound = false;
            float fPlayProbability;
            BSAudio* pCurrentListener = static_cast<BSAudio*>(((void *)(reinterpret_cast<::MagicCaster_shell *>((::FUN_00453a70()))->FUN_0044edb0())));
            while (pRegionCursor && !pRegionCursor->IsEmpty())
            {
                isSoundAllowed = true;
                soundEntry = (*((::RegionSound * *)(&reinterpret_cast<::SimpleListNodeView*>(pRegionCursor)->m_item)));
                pActiveSound = soundEntry->sound;
                if (!soundEntry || !pActiveSound)
                {
                    pRegionCursor = ((::BSSimpleList< ::RegionSound *> *)(reinterpret_cast<::Callees *>((pRegionCursor))->FUN_00726070()));
                    continue;
                }
                fStartHour = reinterpret_cast<::FUN_0082d6e0_Class *>((pActiveSound))->GetHighByteOfField4E() * 0.09375;
                soundEndHour = ((unsigned char)(::FUN_0082d700((void *)(pActiveSound)))) * 0.09375;
                looping = ((unsigned int)(::GetFlagMask((*(::SoundData *)(reinterpret_cast<::Holder *>((pActiveSound))->CopyBig({}))).flags))) != 0;
                if (pWeatherSky)
                {
                    if ((soundEntry->weatherFlags & 0xffff) && ((::TESWeather *)(reinterpret_cast<::MagicCaster_shell *>((pWeatherSky))->FUN_0044edb0())))
                    {
                        unsigned int weather = reinterpret_cast<::FUN_0063dd50_shell *>((((::TESWeather *)(reinterpret_cast<::MagicCaster_shell *>((pWeatherSky))->FUN_0044edb0()))))->FUN_0063dd50(11);
                        if (!((soundEntry->weatherFlags & 0xffff) & weather) && weather)
                            isSoundAllowed = false;
                    }
                    if (std::abs(soundEndHour - fStartHour) >= 0.09375)
                    {
                        if ((fStartHour < soundEndHour && (fStartHour > time || soundEndHour < time)) ||
                            (fStartHour > soundEndHour && fStartHour > time && soundEndHour < time))
                            isSoundAllowed = false;
                    }
                }
                soundFound = reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->FUN_00853130(reinterpret_cast<::TESForm *>(pActiveSound)->iFormID, (::fnv_00853130::CombatThreatRecord *&)(existingHandle));
                if (looping && !soundFound && isSoundAllowed)
                {
                    loopSoundHandle = new SoundPlaybackHandle;
                    *loopSoundHandle = ::FUN_00453a70()->GetSoundHandleByFilePath(
                        ::FUN_00511840((char *)(pActiveSound)), 0x11011, pActiveSound);
                    reinterpret_cast<::FUN_004f15a0_shell *>((loopSoundHandle))->FUN_004f15a0(1);
                    reinterpret_cast<::FUN_00844700_Class *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->FUN_00844700(reinterpret_cast<::TESForm *>(pActiveSound)->iFormID, (unsigned int)(loopSoundHandle));
                    reinterpret_cast<::FUN_00ad8d60_shell *>((loopSoundHandle))->FUN_00ad8d60((unsigned int)(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd06c))))))->f * 1000.0));
                }
                else if (looping && soundFound)
                {
                    if (existingHandle->IsPlaying() && !isSoundAllowed)
                    {
                        existingHandle->StopWithFade((unsigned int)(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dcfe4))))))->f * 1000.0));
                        reinterpret_cast<::NiTMap_S *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->RemoveKey(reinterpret_cast<::TESForm *>(pActiveSound)->iFormID);
                        delete existingHandle;
                    }
                    else if (existingHandle->IsValid() && !existingHandle->IsPlaying() && isSoundAllowed)
                        reinterpret_cast<::FUN_00ad8d60_shell *>((existingHandle))->FUN_00ad8d60((unsigned int)(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd06c))))))->f * 1000.0));
                }
                else if (!looping && isSoundAllowed)
                {
                    fPlayProbability = soundEntry->chance / 20000000.0;
                    if (RandomBoolean(fPlayProbability))
                    {
                        if ((*(::SoundData *)(reinterpret_cast<::Holder *>((pActiveSound))->CopyBig({}))).flags & 0x40)
                            kPlaybackHandle = ::FUN_00453a70()->GetSoundHandleByFilePath(
                                ::FUN_00511840((char *)(pActiveSound)), 0x11101, pActiveSound);
                        else
                            kPlaybackHandle = ::FUN_00453a70()->GetSoundHandleByFilePath(
                                ::FUN_00511840((char *)(pActiveSound)), 0x11102, pActiveSound);
                        location = ::_g_thePlayer->GetPos();
                        if (pCurrentListener)
                            location = pCurrentListener->GetPosition();
                        RegionSoundOffset offset;
                        offset.x = DialogueRandom() % 650 + 100;
                        offset.y = DialogueRandom() % 650 + 100;
                        if (RandomBoolean(0.5f))
                            offset.x *= -1.0;
                        if (RandomBoolean(0.5f))
                            offset.y *= -1.0;
                        location.x += offset.x;
                        location.y += offset.y;
                        location.z += 200.0;
                        reinterpret_cast<::FUN_00ad9030_shell *>(&(kPlaybackHandle))->FUN_00ad9030(255);
                        reinterpret_cast<::FUN_00ad8b60_h *>(&(kPlaybackHandle))->FUN_00ad8b60(location.x, location.y, location.z);
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(kPlaybackHandle))->FUN_00ad8830(false);
                    }
                }
                pRegionCursor = ((::BSSimpleList< ::RegionSound *> *)(reinterpret_cast<::Callees *>((pRegionCursor))->FUN_00726070()));
            }
            unsigned int key = 0;
            bool bKeepSound = false;
            void* soundIterator = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->GetFirstPos();
            pRegionCursor = sounds;
            while (soundIterator)
            {
                reinterpret_cast<::C6b7f20_Map *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->FUN_006b7f20((::C6b7f20_Node **)&(soundIterator), (unsigned int *)&(key), (void **)&(existingHandle));
                while (pRegionCursor && !pRegionCursor->IsEmpty())
                {
                    soundEntry = (*((::RegionSound * *)(&reinterpret_cast<::SimpleListNodeView*>(pRegionCursor)->m_item)));
                    pActiveSound = soundEntry->sound;
                    if (key == reinterpret_cast<::TESForm *>(pActiveSound)->iFormID)
                    {
                        bKeepSound = true;
                        break;
                    }
                    pRegionCursor = ((::BSSimpleList< ::RegionSound *> *)(reinterpret_cast<::Callees *>((pRegionCursor))->FUN_00726070()));
                }
                if (!bKeepSound)
                {
                    reinterpret_cast<::NiTMap_S *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->RemoveKey(key);
                    soundIterator = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->GetFirstPos();
                    existingHandle->StopWithFade((unsigned int)(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dcfe4))))))->f * 1000.0));
                    delete existingHandle;
                    existingHandle = 0;
                }
            }
        }
        DAT_011dcfc0 = ::FUN_00453a70()->GetCurrentTimeMilliseconds();
    }
    else if (sounds->IsEmpty() && !::IsFieldCZero((::Dummy_0069b080 *)&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014)))))
    {
        void* pos;
        {
            bool cleared = false;
            pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->GetFirstPos();
            while (pos)
            {
                unsigned int key;
                reinterpret_cast<::C6b7f20_Map *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->FUN_006b7f20((::C6b7f20_Node **)&(pos), (unsigned int *)&(key), (void **)&(existingHandle));
                reinterpret_cast<::NiTMap_S *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->RemoveKey(key);
                pos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&((*reinterpret_cast<::NiTPointerMap<unsigned int, ::SoundPlaybackHandle *> *>(&::g_011dd014))))->GetFirstPos();
                existingHandle->StopWithFade(300);
                delete existingHandle;
                existingHandle = 0;
            }
        }
    }
}

// Switches the sky mode, unloading textures and stopping sounds when leaving full/exterior mode, then updates HDR values.
// @fnv 0x0063a3f0
void Sky::SetMode(Sky__SKY_MODE mode)
{
    if ((eMode == SM_NONE || eMode == SM_INTERIOR || eMode == SM_COUNT) && (mode == SM_FULL || mode == SM_FAKEEXTERIOR))
    {
        reinterpret_cast<::FUN_0063e2f0_shell *>(this)->FUN_0063e2f0();
        if (m_pClouds)
            reinterpret_cast<::FUN_0063a610_shell *>((m_pClouds))->FUN_0063a610();
        if (static_cast<NiNode*>(m_pRootNode))
            reinterpret_cast<::TaskQueueInterface *>((static_cast<NiNode*>(m_pRootNode)))->QueueActorDisarm(false);
        if (m_pSun)
            reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)(m_pSun))))))->QueueActorDisarm(false);
    }
    else if ((eMode == SM_FULL || eMode == SM_FAKEEXTERIOR || eMode == SM_COUNT) &&
             (mode == SM_NONE || mode == SM_INTERIOR))
    {
        reinterpret_cast<::FUN_0063e210_shell *>(this)->FUN_0063e210();
        if (static_cast<NiNode*>(m_pRootNode))
            reinterpret_cast<::TaskQueueInterface *>((static_cast<NiNode*>(m_pRootNode)))->QueueActorDisarm(true);
        if (m_pSun)
            reinterpret_cast<::TaskQueueInterface *>((((::NiNode *)(::fnv_0043b230::FUN_0043b230((const char *)(m_pSun))))))->QueueActorDisarm(true);
        while (!m_pSkySounds->IsEmpty())
        {
            if ((*((::SkySound * *)(&reinterpret_cast<::SimpleListNodeView*>(m_pSkySounds)->m_item)))->IsPlaying())
                reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>(((*((::SkySound * *)(&reinterpret_cast<::SimpleListNodeView*>(m_pSkySounds)->m_item)))))->FUN_00ad88f0();
            (*((::SkySound * *)(&reinterpret_cast<::SimpleListNodeView*>(m_pSkySounds)->m_item)))->Release();
            delete (*((::SkySound * *)(&reinterpret_cast<::SimpleListNodeView*>(m_pSkySounds)->m_item)));
            m_pSkySounds->RemoveHead();
        }
        DAT_011ccb74 = false;
        eMode = mode;
        if (m_pPrecipitation)
            reinterpret_cast<::RainSystem *>((m_pPrecipitation))->FUN_00636ed0(0.0f);
        m_fWeatherFade = 0.0f;
    }
    eMode = mode;
    reinterpret_cast<::fnv_0063ef20::FUN_0063ef20_shell *>(this)->FUN_0063ef20();
}

// @fnv 0x0082d280
bool SoundPlaybackManager::ResolveSoundFile(const char* name, char* path, unsigned int* apuiFlags, void** extra)
{
    if (!name)
        return false;
    TESSound* sound = (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->GetSoundByEditorID(name);
    if (sound && ::FUN_00511840((char *)(sound)) && path)
    {
        TaskQueueInterface::CopyStringToBuffer(path, 260, ::FUN_00511840((char *)(sound)));
    }
    else
    {
        if ((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)) && !reinterpret_cast<::FUN_004516b0_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->FUN_004516b0() && (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->GetCompiledFileCount() != 0)
            ::FUN_005b5e40();
        return false;
    }
    if ((*(::SoundData *)(reinterpret_cast<::Holder *>((sound))->CopyBig({}))).flags & 0x40)
    {
        *apuiFlags |= 1;
        *apuiFlags &= ~2;
    }
    else if (!(*apuiFlags & 1) && !(*apuiFlags & 2))
    {
        *apuiFlags |= 2;
        *apuiFlags &= ~1;
    }
    if ((*(::SoundData *)(reinterpret_cast<::Holder *>((sound))->CopyBig({}))).flags & 1)
        *apuiFlags |= 0x40;
    if ((*(::SoundData *)(reinterpret_cast<::Holder *>((sound))->CopyBig({}))).flags & 0x800)
        *apuiFlags |= 0x8000000;
    *apuiFlags |= ((unsigned int)(::GetFlagMask((*(::SoundData *)(reinterpret_cast<::Holder *>((sound))->CopyBig({}))).flags)));
    *extra = sound;
    return true;
}

// Returns true if sound is non-null, the audio object exists, and position is within sound->GetField45()*100*scale of the listener position on all axes.
// @fnv 0x0082eca0
bool SoundPlaybackManager::CanPlaySoundAt(TESSound* sound, NiPoint3 position, float scale)
{
    BSAudio* m_pAudioListener = static_cast<BSAudio*>(((void *)(reinterpret_cast<::MagicCaster_shell *>((::FUN_00453a70()))->FUN_0044edb0())));
    if (!sound || !m_pAudioListener)
        return false;
    {
        NiPoint3 kListenerPosition = m_pAudioListener->GetPosition();
        float fDistance = sound->GetField45() * 100.0 * scale;
        if (std::abs(position.x - kListenerPosition.x) > fDistance ||
            std::abs(position.y - kListenerPosition.y) > fDistance ||
            std::abs(position.z - kListenerPosition.z) > fDistance)
            return false;
    }
    return true;
}

// @fnv 0x0082eb70
void SoundPlaybackManager::ResetAcousticSpace(BGSAcousticSpace* space)
{
    if (DAT_011dcfa7 || (space && space != (*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4))) || !(*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)))
        return;
    (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8)).StopWithFade((unsigned int)(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd050))))))->f * 1000.0));
    reinterpret_cast<::fnv_004188d0::FUN_004188d0_shell *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->FUN_004188d0();
    (*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)) = 0;
    DAT_011dcfb1 = true;
    reinterpret_cast<::FUN_00ad79b0_shell *>((::FUN_00453a70()))->FUN_00ad79b0(0);
}

// @fnv 0x0082ec60
void SoundPlaybackManager::LoadGame(BGSLoadGameBuffer* buffer)
{
    DAT_011dcfa8 = dynamic_cast<TESSound*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
}

// @fnv 0x0082eae0
void SoundPlaybackManager::SetAcousticSpace(BGSAcousticSpace* space)
{
    if ((*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)) == space)
        return;
    (*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8)).StopWithFade((unsigned int)(((::SETTING_VALUE *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011dd050))))))->f * 1000.0));
    reinterpret_cast<::fnv_004188d0::FUN_004188d0_shell *>(&((*reinterpret_cast<::SoundPlaybackHandle *>(&::g_011dd0d8))))->FUN_004188d0();
    if (space)
        reinterpret_cast<::FUN_00ad79b0_shell *>((::FUN_00453a70()))->FUN_00ad79b0(reinterpret_cast<::FUN_0068a810_class *>((space))->GetField4C());
    (*reinterpret_cast<::BGSAcousticSpace * *>(&::DAT_011dcfb4)) = space;
    DAT_011dcfb1 = true;
}
// @fnv 0x0082ea80
void PlayerCharacter::ResetRegionSoundTimer()
{
    regionSoundTimer = 0;
}
// @fnv 0x0082eac0
bool PlayerCharacter::IsRegionSoundsEnabled()
{
    return regionSoundsEnabled;
}
// @fnv 0x0082eaa0
BSSimpleList<RegionSound*>* PlayerCharacter::GetRegionSounds()
{
    return &regionSounds;
}


// Returns the cached TESSound named "UIActivateNothing", looking it up via g_dataHandler if not yet set.
// @fnv 0x0082ec10
TESSound* __cdecl GetUIActivateNothingSound()
{
    if (DAT_011dcfa8 == 0)
        DAT_011dcfa8 = (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->GetSoundByEditorID("UIActivateNothing");
    return DAT_011dcfa8;
}

struct BGSSaveFormBuffer
{
};
// @fnv 0x0082ec40
void FUN_0082ec40(BGSSaveFormBuffer* buffer)
{
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((buffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(DAT_011dcfa8), 0);
}

struct Snd_
{
};
// @fnv 0x0082ed80
void __cdecl PlayMysteriousStrangerMusic()
{
    SoundPlaybackHandle hndle =
        ::FUN_00453a70()->GetSoundHandleByEditorID("MUSMysteriousStrangerA01", 0x210101);
    reinterpret_cast<::FUN_00ad8830_shell *>(&(hndle))->FUN_00ad8830(false);
    reinterpret_cast<::fnv_00ad7fa0::AudioUpdateStand *>((((Snd_*)::FUN_00453a70())))->FUN_00ad7fa0((char *)("MUSMysteriousStrangerA02"), 0x20200101);
}

// @fnv 0x0082ee10
void __cdecl PlayMysteriousStrangerSound()
{
    SoundPlaybackHandle hndle =
        ::FUN_00453a70()->GetSoundHandleByEditorID("MUSMysteriousStrangerA02", 0x200101);
    reinterpret_cast<::FUN_00ad8830_shell *>(&(hndle))->FUN_00ad8830(false);
}

#include "generated/data/fallout/audio/falloutaudio.inc"
