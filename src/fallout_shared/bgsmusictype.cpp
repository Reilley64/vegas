// fallout_shared/bgsmusictype.cpp: BGSMusicType, MusicTypeDeletion, MusicTypeWriter, MusicTypeCopyEntry and more (8 functions)

#include <new>
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_0048cea0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/MusicFileBuilder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00944000.h"
#define BSSimpleList BSSimpleListWithoutItemsInList
#include "music_local.h"
#undef BSSimpleList
#include <malloc.h>
#include "fnv/decl/FUN_00591a20_Class.h"
#include "fnv/decl/TESActorBase.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00462000.h"
#include "fnv/symbols_00472000.h"
#include <windows.h>

template <class T> struct BSSimpleList
{
    bool IsEmpty();
    unsigned int ItemsInList();
};

// Loads a music type record: reads the header, then handles EDID, OBND, FNAM and ANAM chunks until no more chunks remain, returning true.
// @fnv 0x00591550
bool BGSMusicType::Load(TESFile* file)
{
    int iChunkID;
    unsigned int size = 0;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    while (iChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (iChunkID)
        {
        case 0x44494445: {
            char* editorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4d414e46: {
            char* soundFile = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(soundFile), 0);
            SetSoundFile(soundFile);
            break;
        }
        case 0x4d414e41: {
            float attenuation = 0.0f;
            file->GetChunkData(reinterpret_cast<unsigned int*>(&attenuation));
            fVolumeScale = attenuation;
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}


// Prefixes the sound file with Data\\Music unless it ends in a backslash, then selects a random track index when tracks exist.
// @fnv 0x00591410
void BGSMusicType::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    struct SoundFileNames
    {
        const char* name;
        const char* soundFile;
    } soundFileNames;
    if (GetSoundFileLength() > 2)
    {
        soundFileNames.soundFile = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)this)->FUN_00408da0()));
        if (soundFileNames.soundFile[GetSoundFileLength() - 1] == '\\')
        {
            reinterpret_cast<::MusicFileBuilder *>(this)->FUN_005917b0();
        }
        else
        {
            soundFileNames.name = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)this)->FUN_00408da0()));
            char fullPath[260];
            ::FUN_00406d00(fullPath, 260, "%s\\%s", "Data\\Music", soundFileNames.name);
            SetSoundFile(fullPath);
        }
    }
    m_uiSelectedSoundIndex =
        reinterpret_cast<BSSimpleList<MusicTrack*>&>(m_kMusicFiles).IsEmpty()
            ? 0
            : GetRandomNumberInRange(0, reinterpret_cast<BSSimpleList<MusicTrack*>&>(m_kMusicFiles).ItemsInList() - 1);
    SetInitializationState(true);
}

struct MusicTypeDeletion : public BGSMusicType
{
    void* FUN_005912a0(unsigned int flags);
};

class MusicType_00591320 : public TESForm, public TESSoundFile
{
  public:
    float fVolumeScale;
    BSSimpleListWithoutItemsInList<BGSMusicType::MusicTrack*> m_kMusicFiles;
    unsigned int m_uiSelectedSoundIndex;
    virtual ~MusicType_00591320();
};
// Calls the BGSMusicType destructor and frees the object with operator delete when the low bit of flags is set.
// @fnv 0x005912a0
void* MusicTypeDeletion::FUN_005912a0(unsigned int flags)
{
    reinterpret_cast<::MusicType_00591320 *>((this))->MusicType_00591320::~MusicType_00591320();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct MusicTypeFileList_005913b0 : BGSMusicType
{
    void FUN_005913b0();
};
// Destructor for MusicType_00591320 that calls FUN_005913b0 to perform cleanup.
// @fnv 0x00591320
MusicType_00591320::~MusicType_00591320()
{
    reinterpret_cast<::MusicTypeFileList_005913b0 *>(this)->FUN_005913b0();
}
// Removes and frees every entry in m_kMusicFiles until the list is empty.
// @fnv 0x005913b0
void MusicTypeFileList_005913b0::FUN_005913b0()
{
    void* pEntry = 0;
    while (!m_kMusicFiles.IsEmpty())
    {
        pEntry = ((::BGSMusicType::MusicTrack *)(new ((void *)&(m_kMusicFiles)) ::Vec3()));
        m_kMusicFiles.RemoveHead();
        void* p = pEntry;
        ::FUN_00401030(p);
        pEntry = 0;
    }
}

struct MusicSoundWriter : TESSoundFile
{
};

struct MusicSaveComponents
{
    TESForm form;
    MusicSoundWriter soundFile;
};


struct MusicTypeWriter : BGSMusicType
{
    void FUN_005916b0();
};

// Writes the music type save components by calling FUN_004855a0, the sound file writer, and FUN_00485910 with the MANA chunk and fVolumeScale.
// @fnv 0x005916b0
void MusicTypeWriter::FUN_005916b0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_0048cea0_shell *>(&(reinterpret_cast<MusicSaveComponents*>(this)->soundFile))->FUN_0048cea0();
    ::FUN_00485910(0x4d414e41, fVolumeScale);
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

class MusicTypeCopyEntry : public BGSMusicType
{
  public:
    void FUN_005916f0(TESForm* source);
};

// Copies fVolumeScale from a BGSMusicType source and delegates the remaining copy to FUN_004851b0.
// @fnv 0x005916f0
void MusicTypeCopyEntry::FUN_005916f0(TESForm* source)
{
    BGSMusicType* music = dynamic_cast<BGSMusicType*>(source);
    if (!music)
        return;
    fVolumeScale = music->fVolumeScale;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(music);
}

struct MusicFormComponentCompareView
{
};

struct MusicTypeCompareEntry : ::BGSMusicType
{
    bool FUN_00591740(::TESForm* form);
};

// Returns true if the given form is not a BGSMusicType, or if its fVolumeScale or form component differs from this entry.
// @fnv 0x00591740
bool MusicTypeCompareEntry::FUN_00591740(::TESForm* form)
{
    ::BGSMusicType* other = dynamic_cast< ::BGSMusicType*>(form);
    if (!other)
        return true;
    if (fVolumeScale != other->fVolumeScale)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<MusicFormComponentCompareView*>(this)))->FUN_00485270(other))
        return true;
    return false;
}

class AutoMemHelper
{
  public:
    int unk00;
    AutoMemHelper(int context, bool leave, const char* file, int line);
    ~AutoMemHelper();
};

class BSDirectoryIterator
{
  public:
    void* m_hFindHandle;
    _WIN32_FIND_DATAA m_findData;
    BGSMusicType::MusicTrack m_path;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    BSDirectoryIterator(const char* path);
    ~BSDirectoryIterator();
    int Next(bool* outDone);
};

class MusicFileBuilder_ctx : public BGSMusicType
{
  public:
    void FUN_005917b0();
};

// @fnv 0x005917b0
void MusicFileBuilder_ctx::FUN_005917b0()
{
    AutoMemHelper memContext(11, true, "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\BGSMusicType.cpp", 352);
    const char* soundFile5 = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((void *)this)->FUN_00408da0()));
    char path5[260];
    char fullPathA[260];
    ::FUN_00406d00(path5, 0x104, "%s\\%s", "Data\\Music", soundFile5);
    const char* ext_2 = ".mp3";
    bool done4 = false;
    BSDirectoryIterator iter(path5);
    int res3 = iter.Next(&done4);
    while (!done4 && res3 == 0)
    {
        if (!((bool)(reinterpret_cast<::FUN_00591a20_Class *>(&(iter))->IsFlagBit4Set())) && ((const char *)(reinterpret_cast<::TESTopicInfo *>(&(iter))->GetAddTopicList())))
        {
            char fileExt[260];
            FUN_00462d40(((const char *)(reinterpret_cast<::TESTopicInfo *>(&(iter))->GetAddTopicList())), 0, 0, 0, 0, 0, 0, fileExt, 0x104);
            if (FUN_00404dc0(fileExt, ext_2) == 0)
            {
                ::FUN_00406d00(fullPathA, 0x104, "%s%s", path5, ((const char *)(reinterpret_cast<::TESTopicInfo *>(&(iter))->GetAddTopicList())));
                MusicTrack* entry = new MusicTrack(fullPathA);
                m_kMusicFiles.AddHead(entry);
            }
        }
        res3 = iter.Next(&done4);
    }
}
