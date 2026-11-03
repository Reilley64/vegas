// fallout_shared/music_local.h: declares TESSoundFile, BGSMusicType, MusicTrack
#ifndef FNV_MUSIC_LOCAL_H
#define FNV_MUSIC_LOCAL_H

#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/TESActorBase.h"
#include "TESForm.h"
#include "TESFile.h"
class TESSoundFile : public BaseFormComponent
{
  public:
    BSStringT<char> m_kSoundFile;
    virtual void SetSoundFile(const char* name);
    unsigned int GetSoundFileLength() const;
};
class BGSMusicType : public TESForm, public TESSoundFile
{
  public:
    class MusicTrack
    {
      public:
        char m_acTrackName[260];
        MusicTrack(const char* name);
    };
    float fVolumeScale;
    BSSimpleList<MusicTrack*> m_kMusicFiles;
    unsigned int m_uiSelectedSoundIndex;
    virtual bool Load(TESFile* file);
    virtual void InitItem();
};
#endif
