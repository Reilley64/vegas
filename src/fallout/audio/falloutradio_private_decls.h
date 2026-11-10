// fallout/audio/falloutradio_private_decls.h: declares TESForm, TESObjectREFR, BGSLoadGameBuffer, FalloutRadio, RadioReceiver and more
#ifndef FALLOUTRADIO_PRIVATE_DECLS_H
#define FALLOUTRADIO_PRIVATE_DECLS_H


#include "fnv/decl/FUN_00835f10_shell.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/s835fe0__RefHandle.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00832000.h"
#include "fnv/symbols_00833000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
class DialoguePackage;
class DialogueItem;
class BGSPerkEntry;
class TESGrass;
class MediaSet;
class PerkButtonEntry;
class PlayerCharacter;
class TESSound;
class BGSTalkingActivator;

class TESForm
{
  public:
    virtual void FNV_type_anchor();
public:
    bool GetDisabled() const;
};

class TESObjectREFR : public TESForm
{
};

struct BGSLoadGameBuffer
{
  public:
    virtual unsigned char vfn_0();
};

union SETTING_VALUE
{
    unsigned int value;
};

enum MEDIATYPE
{
    MEDIATYPE_RADIO = 7
};

struct SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char padding[3];
    unsigned int eState;
    bool Release();
public:
    ::SoundPlaybackHandle &operator=(const ::SoundPlaybackHandle &);
public:
    bool IsPlaying() const;
public:
    bool IsValid() const;
public:
    void SetCompletionCallback(void (*)(void *, bool), void *);
};

#include "fnv/bs_simple_list.h"

class Conversation_decl;
void __cdecl FUN_00832c40();

class FalloutRadio
{
  public:
    class RadioReceiver
    {
      public:
        void* form;
        SoundPlaybackHandle sound;
        char padding[12];
        unsigned char active;
        void* FUN_00832190(bool);
    };

    class RadioConversation
    {
      public:
        ::Conversation_decl* conversation;
        unsigned int unk04;
        unsigned int nextUpdate;
        int state;
        char padding[8];
    };

    class RadioStationState
    {
      public:
        void* form;
        RadioConversation station;
        BSSimpleList<RadioReceiver*> receivers;
        void* FUN_00832160(bool);
    };

    static bool SetRadioEnabled(bool);
    static void RefreshRadioReceivers(bool);
    static bool Update(bool);
    static void InitLoadGame(BGSLoadGameBuffer*);
    static RadioConversation* GetRadioConversation(BGSTalkingActivator*);
    static void RadioSynchUnPaused();

  protected:
    friend void __cdecl ::FUN_00832c40();
    static unsigned int ms_uiRadioSyncFlags;
};

struct TeleportableReference
{
  public:
};

class FalloutAudioMedia
{
  public:
    static void BeginMediaUpdate();
    static void EndMediaUpdate();
    static bool IsRadioPlaying();
};

struct Interface
{
  public:
    static bool IsGamePaused();
};

class TimeGlobal
{
  public:
};

class SettingT_GameSettingCollection_
{
  public:
};

class LowProcess
{
  public:
    TESObjectREFR* GetTarget();
};

class TESObjectCELL
{
  public:
    bool IsCellInterior() const;
};

class TESDataHandler
{
  public:
    TESSound* GetSoundByEditorID(const char*);
};

extern bool DAT_011dd434;
extern unsigned char DAT_011dd436;
extern unsigned char DAT_011dd437;
extern unsigned int DAT_011dd424;
extern unsigned char DAT_011dd435;
extern unsigned int DAT_011dd43c;
extern TESSound* DAT_011dd440;
extern const char DAT_0107ce14[];


#endif
