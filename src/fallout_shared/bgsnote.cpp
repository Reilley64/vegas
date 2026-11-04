// fallout_shared/bgsnote.cpp: BGSNote, Proxy, BGSNoteStandin, NoteRecord and more (25 functions)

#include <new>
#include "fnv/decl/BGSExplosion.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_004891d0_cls.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_0047b560__FUN_0047b560_shell.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_0048e370__FUN_0048e370_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048e000.h"
#include "fnv/symbols_005b5000.h"
#include "bgsnote_decls.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/symbols_00472000.h"
// @fnv 0x005e8240
void BGSNote::ResetFormData()
{
    cType = 0;
    m_pText = 0;
    m_pDialogueSpeaker = 0;
    m_bIsRead = false;
}

// @fnv 0x005e8060
BGSNote::BGSNote()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(kNote)));
    ResetFormData();
}

// If type differs from cType, deletes the current TESDescription or TESTexture, stores the new type, and allocates the matching object.
// @fnv 0x005e8f90
void BGSNote::ChangeNoteType(NOTE_TYPE type)
{
    if (type != cType)
    {
        switch (cType)
        {
        case 1:
            delete (TESDescription*)m_pText;
            m_pText = 0;
            break;
        case 2:
            delete (TESTexture*)m_pText;
            m_pText = 0;
            break;
        }
        cType = (signed char)type;
        switch (cType)
        {
        case 1:
            m_pText = new TESDescription;
            break;
        case 2:
            m_pText = new TESTexture;
            break;
        }
    }
}

struct FUN_005e8d40_shell : public BGSNote
{
    int GetNoteType();
};
// Returns the note's TESDescription when GetNoteType reports 1, otherwise returns null.
// @fnv 0x005e91d0
TESDescription* BGSNote::GetNoteDescription()
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == 1)
        return (TESDescription*)m_pText;
    return 0;
}

// @fnv 0x005e8d40
int FUN_005e8d40_shell::GetNoteType()
{
    return cType;
}

// Returns the note's sound if its type is NoteSound, otherwise returns null.
// @fnv 0x005e9100
TESSound* BGSNote::FUN_005e9100()
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == NoteSound)
        return (TESSound*)m_pText;
    return 0;
}

// Returns the note texture if the note type is NoteTexture, otherwise returns null.
// @fnv 0x005e9160
TESTexture* BGSNote::GetNoteTexture()
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == NoteTexture)
        return (TESTexture*)m_pText;
    return 0;
}

// Returns the stored topic when GetNoteType() equals 3, otherwise returns null.
// @fnv 0x005e9240
TESTopic* BGSNote::FUN_005e9240()
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == 3)
        return (TESTopic*)m_pText;
    return 0;
}

struct FUN_005e9270_shell : public BGSNote
{
    void FUN_005e9270(TESTopic*);
};

// @fnv 0x005e9270
void FUN_005e9270_shell::FUN_005e9270(TESTopic* apTopic)
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == 3)
        m_pText = apTopic;
}

// Returns the stored TESActorBase pointer when GetNoteType() equals 3, otherwise returns null.
// @fnv 0x005e92a0
TESActorBase* BGSNote::FUN_005e92a0()
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == 3)
        return (TESActorBase*)m_pDialogueSpeaker;
    return 0;
}

struct FUN_005e92d0_shell : public BGSNote
{
    void FUN_005e92d0(TESActorBase*);
};

// If GetNoteType() returns 3, stores apSpeaker into a field.
// @fnv 0x005e92d0
void FUN_005e92d0_shell::FUN_005e92d0(TESActorBase* apSpeaker)
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == 3)
        m_pDialogueSpeaker = apSpeaker;
}

struct FUN_005e9130_shell : BGSNote
{
    void FUN_005e9130(std::intptr_t a1);
};
// @fnv 0x005e8900
void BGSNote::InitItem()
{
    if (GetInitialized())
        return;
    BSSimpleList<TESQuest*>* current = &ownerQuests;
    BSSimpleList<TESQuest*>* previous = 0;
    while (current && !current->IsEmpty())
    {
        BGSNoteReference<TESQuest> noteRef;
        noteRef.id = (unsigned int)(std::uintptr_t)(current->item);
        ::ResolveFormID((unsigned int *)&(noteRef.id), GetFile(-1));
        noteRef.form = dynamic_cast<TESQuest*>(::FUN_004839c0(noteRef.id));
        if (noteRef.form)
        {
            current->SetItem(noteRef.form);
            previous = current;
            current = ((::BSSimpleList< ::TESQuest *> *)(reinterpret_cast<::Callees *>((current))->FUN_00726070()));
        }
        else
        {
            ::FUN_005b5e40();
            if (previous)
            {
                reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330((::InventoryStackRecord *const &)((current->item)));
                current = ((::BSSimpleList< ::TESQuest *> *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
            }
            else
                current->RemoveHead();
        }
    }
    if (FUN_005e9100())
    {
        BGSNoteReference<TESSound> noteRef;
        noteRef.id = (unsigned int)(std::uintptr_t)FUN_005e9100();
        ::ResolveFormID((unsigned int *)&(noteRef.id), GetFile(-1));
        noteRef.form = dynamic_cast<TESSound*>(::FUN_004839c0(noteRef.id));
        reinterpret_cast<::FUN_005e9130_shell *>(this)->FUN_005e9130((std::intptr_t)(noteRef.form));
        if (!noteRef.form)
            ::FUN_005b5e40();
    }
    if (FUN_005e9240())
    {
        BGSNoteReference<TESTopic> noteRef;
        noteRef.id = (unsigned int)(std::uintptr_t)FUN_005e9240();
        ::ResolveFormID((unsigned int *)&(noteRef.id), GetFile(-1));
        noteRef.form = dynamic_cast<TESTopic*>(::FUN_004839c0(noteRef.id));
        reinterpret_cast<::FUN_005e9270_shell *>(this)->FUN_005e9270(noteRef.form);
        if (!noteRef.form)
            ::FUN_005b5e40();
    }
    if (FUN_005e92a0())
    {
        BGSNoteReference<TESActorBase> noteRef;
        noteRef.id = (unsigned int)(std::uintptr_t)FUN_005e92a0();
        ::ResolveFormID((unsigned int *)&(noteRef.id), GetFile(-1));
        noteRef.form = dynamic_cast<TESActorBase*>(::FUN_004839c0(noteRef.id));
        reinterpret_cast<::FUN_005e92d0_shell *>(this)->FUN_005e92d0(noteRef.form);
        if (!noteRef.form)
            ::FUN_005b5e40();
    }
    BGSPickupPutdownSounds::InitItem(this);
    SetInitializationState(true);
}
// Reads a NOTE record's chunks from the file, dispatching editor ID, bounds, full name, model, texture, sounds, type, owner quests and type-specific chunks.
// @fnv 0x005e84e0
bool BGSNote::Load(TESFile* file)
{
    if (file->GetTESForm() != kNote)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int chunk;
    while (chunk = reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID(editorID);
            break;
        }
        case 0x444e424f:
            LoadBounds(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x4c444f4d:
        case 0x54444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(this, file);
            break;
        case 0x4d414e59: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(::TESSound *)((TESSound*)(std::uintptr_t)id));
            break;
        }
        case 0x4d414e5a: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            reinterpret_cast<::TESRegionGrassObject *>(this)->AssignLandTexture((::TESLandTexture *)(::TESSound *)((TESSound*)(std::uintptr_t)id));
            break;
        }
        case 0x41544144: {
            unsigned char type = 0;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&type), 1);
            ChangeNoteType((NOTE_TYPE)type);
            break;
        }
        case 0x4d414e4f: {
            unsigned int id = 0;
            file->GetChunkData(&id);
            ownerQuests.AddHead((TESQuest*)(std::uintptr_t)id);
            break;
        }
        case 0x4d414e58: {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            if (size)
            {
                char* name = (char*)_alloca(size);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), size);
                if (GetNoteTexture())
                    reinterpret_cast<::TESFullName *>((GetNoteTexture()))->SetFullName(name);
            }
            break;
        }
        default:
            switch (cType)
            {
            case 0:
                if (chunk == 0x4d414e53)
                {
                    unsigned int id = 0;
                    file->GetChunkData(&id);
                    reinterpret_cast<::FUN_005e9130_shell *>(this)->FUN_005e9130((std::intptr_t)((TESSound*)(std::uintptr_t)id));
                }
                break;
            case 1:
                if (chunk == 0x4d414e54)
                {
                    TESDescription* description = GetNoteDescription();
                    if (description)
                        TESDescription::ReadDescriptionFromFile(description, file);
                }
                break;
            case 2:
                if (IsChunkTypeIcon(chunk))
                {
                    TESTexture* texture = GetNoteTexture();
                    if (texture)
                        TESTexture::ReadTextureData(texture, file);
                }
                break;
            case 3:
                if (chunk == 0x4d414e53)
                {
                    unsigned int id = 0;
                    file->GetChunkData(&id);
                    reinterpret_cast<::FUN_005e92d0_shell *>(this)->FUN_005e92d0((TESActorBase*)(std::uintptr_t)id);
                }
                else if (chunk == 0x4d414e54)
                {
                    unsigned int id = 0;
                    file->GetChunkData(&id);
                    reinterpret_cast<::FUN_005e9270_shell *>(this)->FUN_005e9270((TESTopic*)(std::uintptr_t)id);
                }
                break;
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// If GetNoteType returns 0, stores a1 at offset 0x6c of this object.
// @fnv 0x005e9130
void FUN_005e9130_shell::FUN_005e9130(std::intptr_t a1)
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == 0)
        *(int*)((char*)this + 0x6c) = a1;
}

struct Proxy
{
    void FUN_005e8170();
    void* Release(unsigned int);
};
struct Fake9190
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2(int)
    {}
};
struct FUN_005e9190_shell : BGSNote
{
    void FUN_005e9190(std::intptr_t);
};
// @fnv 0x005e9190
void FUN_005e9190_shell::FUN_005e9190(std::intptr_t a)
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == 2)
        ((Fake9190*)m_pText)->f2(a);
}

struct Helper005e9200
{
    virtual void f0();
    virtual void f1();
    virtual void f2(void*);
};
struct FUN_005e9200_shell : BGSNote
{
    void FUN_005e9200(void*);
};
// @fnv 0x005e9200
void FUN_005e9200_shell::FUN_005e9200(void* apArg)
{
    if (reinterpret_cast<::FUN_005e8d40_shell *>(this)->GetNoteType() == 1)
        ((Helper005e9200*)m_pText)->f2(apArg);
}

struct FormChangeMask
{
    unsigned int m_flags;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};
struct TESFormBufferAccess
{
};
struct BGSNoteStandin : ::BGSNote
{
    void FUN_005e9480(BGSLoadFormBuffer*);
};
// @fnv 0x005e9480
void BGSNoteStandin::FUN_005e9480(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::TESForm *>((((TESFormBufferAccess*)this)))->LoadGame(apLoadGameBuffer);
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(0x80000000)))->FUN_004280f0(0x80000000))
        *(unsigned char*)&this->m_bIsRead = 1;
}

namespace fnv_005e94d0 {
struct FormChangeMask
{
    int data;
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetOldChangeFlags(unsigned int);
};
struct FUN_004534f0_shell
{
};
struct FUN_005e94d0_shell : ::BGSNote
{
    void FUN_005e94d0(BGSLoadFormBuffer*);
};
// @fnv 0x005e94d0
void FUN_005e94d0_shell::FUN_005e94d0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    reinterpret_cast<::FUN_004534f0_shell *>((((FUN_004534f0_shell*)this)))->FUN_004534f0(reinterpret_cast<std::uintptr_t>(apLoadGameBuffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::fnv_005e94d0::FormChangeMask &)(apLoadGameBuffer->GetOldChangeFlags(0x80000000)))->FUN_004280f0(0x80000000))
        *(char*)&this->m_bIsRead = 0;
}
}  // namespace fnv_005e94d0

struct FUN_005e9300_Host
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
    virtual void v18(unsigned int);
    virtual void v19(unsigned int);
    char _pad[0x79];
    bool mRead;
    void SetRead(bool abRead);
};
// @fnv 0x005e9300
void FUN_005e9300_Host::SetRead(bool abRead)
{
    if (mRead == abRead)
        return;
    mRead = abRead;
    if (mRead)
        v18(0x80000000);
    else
        v19(0x80000000);
}

struct FUN_005e8170 : public TESBoundObject,
                      public TESModel,
                      public TESFullName,
                      public TESIcon,
                      public BGSPickupPutdownSounds
{
    void* m_pText;
    void* m_pDialogueSpeaker;
    BSSimpleList<TESQuest*> ownerQuests;
    signed char cType;
    bool m_bIsRead;
    char padding7e[2];
    virtual ~FUN_005e8170();
};
// Calls FUN_005e8170, frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x005e8140
void* Proxy::Release(unsigned int flags)
{
    reinterpret_cast<::FUN_005e8170 *>((this))->FUN_005e8170::~FUN_005e8170();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct NoteQuestList
{
    unsigned int head;
    unsigned int tail;
};
struct NoteRecord
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
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    TESDescription* noteData;
    void* speaker;
    NoteQuestList ownerQuests;
    unsigned char noteType;
    unsigned char wasRead;
    void Destroy();
};
// Destructor that calls ClearNoteData to release the note's data.
// @fnv 0x005e8170
FUN_005e8170::~FUN_005e8170()
{
    reinterpret_cast<::NoteRecord *>(this)->Destroy();
}
// @fnv 0x005e8270
void NoteRecord::Destroy()
{
    reinterpret_cast<::FileMatchList *>(&(ownerQuests))->RemoveAll();
    switch (noteType)
    {
    case 1:
        delete noteData;
        noteData = 0;
        break;
    case 2:
        delete reinterpret_cast<TESTexture*>(noteData);
        noteData = 0;
        break;
    }
}

struct SaveForm
{
};
struct SaveTexture : TESTexture
{
    unsigned int GetNameLength();
};
struct SaveFullName : TESFullName
{
};
struct SaveModel : TESModel
{
};
struct SaveIcon : TESIcon
{
};
struct SavePickup : BGSPickupPutdownSounds
{
};
struct SaveQuestList
{
    bool IsListEmpty();
};


struct BGSNoteSave : TESBoundObject, SaveModel, SaveFullName, SaveIcon, SavePickup
{
    void* m_pText;
    void* m_pDialogueSpeaker;
    BSSimpleList<TESQuest*> ownerQuests;
    signed char cType;
    bool m_bIsRead;
    void SaveNote();
};

// @fnv 0x005e8300
void BGSNoteSave::SaveNote()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(this)->FUN_00487010();
    reinterpret_cast<::FUN_004891d0_cls *>(this)->WriteToBuffer((char *)(0x4c444f4d), (void *)(0x54444f4d));
    reinterpret_cast<::fnv_0048e370::FUN_0048e370_shell *>(this)->FUN_0048e370(0x4e4f4349);
    reinterpret_cast<::fnv_0047b560::FUN_0047b560_shell *>(this)->LogFormIDs();
    ::FUN_004858f0(0x41544144, cType);
    SaveQuestList* pNode = ((::SaveQuestList *)(reinterpret_cast<::BGSExplosion *>(this)->FUN_004fadc0()));
    while (pNode && !pNode->IsListEmpty())
    {
        TESQuest* pOwner = ((::TESQuest *)((void *)(pNode)));
        unsigned int uiOwnerQuestID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((SaveForm*)pOwner)))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e4f, uiOwnerQuestID);
        pNode = ((::SaveQuestList *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    switch (cType)
    {
    case 0: {
        TESSound* SoundAssetTmp = reinterpret_cast<::BGSNote *>(this)->FUN_005e9100();
        if (SoundAssetTmp)
        {
            unsigned int uiSoundID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((SaveForm*)SoundAssetTmp)))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e53, uiSoundID);
        }
        break;
    }
    case 1: {
        void* pText = ((void *)(reinterpret_cast<::BGSNote *>(this)->GetNoteDescription()));
        if (pText)
            ::WriteDescChunk(pText, 0x4d414e54);
        break;
    }
    case 2: {
        SaveTexture* pNoteTexture = (SaveTexture*)reinterpret_cast<::BGSNote *>(this)->GetNoteTexture();
        if (pNoteTexture)
            ::FUN_004856f0((void *)(0x4d414e58), (void *)(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((pNoteTexture))->FUN_00408da0()))), (void *)(std::uintptr_t)(pNoteTexture->GetNameLength() + 1));
        break;
    }
    case 3: {
        TESTopic* pTopic = reinterpret_cast<::BGSNote *>(this)->FUN_005e9240();
        if (pTopic)
        {
            unsigned int uiTopicFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((SaveForm*)pTopic)))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e54, uiTopicFormID);
        }
        TESActorBase* m_pDialogueSpeaker = reinterpret_cast<::BGSNote *>(this)->FUN_005e92a0();
        if (m_pDialogueSpeaker)
        {
            unsigned int uiSpeakerFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((SaveForm*)m_pDialogueSpeaker)))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e53, uiSpeakerFormID);
        }
        break;
    }
    }
    reinterpret_cast<::Holder *>(this)->FUN_00485680();
}

namespace fnv_005e8c00 {
struct NoteQuestList
{
};

class BGSNoteCopy : public BGSNote
{
  public:

    void CopyFromNote(TESForm* apForm);
};

// Copies generic components, flags, speaker, type-specific data and owner quests from another BGSNote into this one.
// @fnv 0x005e8c00
void BGSNoteCopy::CopyFromNote(TESForm* apForm)
{
    BGSNoteCopy* pSource = (BGSNoteCopy*)dynamic_cast<BGSNote*>(apForm);
    if (!pSource)
        return;

    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(apForm);
    BSSimpleList<TESQuest*>* pIter = 0;
    reinterpret_cast<::BGSNote *>(this)->ChangeNoteType((::NOTE_TYPE)(reinterpret_cast<::FUN_005e8d40_shell *>((pSource))->GetNoteType()));
    reinterpret_cast<::FUN_005e92d0_shell *>(this)->FUN_005e92d0(pSource->FUN_005e92a0());
    switch (cType)
    {
    case 0:
        reinterpret_cast<::FUN_005e9130_shell *>(this)->FUN_005e9130((std::intptr_t)(pSource->FUN_005e9100()));
        break;
    case 1:
        reinterpret_cast<::FUN_005e9200_shell *>(this)->FUN_005e9200(reinterpret_cast<::BGSNote *>((pSource))->GetNoteDescription());
        break;
    case 2:
        reinterpret_cast<::FUN_005e9190_shell *>(this)->FUN_005e9190((std::intptr_t)(pSource->GetNoteTexture()));
        break;
    case 3:
        reinterpret_cast<::FUN_005e9270_shell *>(this)->FUN_005e9270(pSource->FUN_005e9240());
        break;
    }

    reinterpret_cast<::FileMatchList *>((((NoteQuestList*)&ownerQuests)))->RemoveAll();
    pIter = ((::BSSimpleList< ::TESQuest *> *)(reinterpret_cast<::BGSExplosion *>((pSource))->FUN_004fadc0()));
    while (pIter && !pIter->IsEmpty())
    {
        ownerQuests.AddHead((pIter->item));
        pIter = ((::BSSimpleList< ::TESQuest *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }
    m_bIsRead = pSource->m_bIsRead;
}
}  // namespace fnv_005e8c00

namespace fnv_005e8d60 {
struct NoteCompareData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual bool IsDifferent(NoteCompareData* apOther);
};

struct NoteQuestList
{
    TESQuest* pItem;
    NoteQuestList* pNext;

    int GetSize();
    bool IsEmpty();
};

struct NoteCompare : BGSNote
{
    bool FUN_005e8d60(TESForm* apForm);
};

// Compares this note against apForm by base data, type-specific data and owner quest lists, returning true when they differ.
// @fnv 0x005e8d60
bool NoteCompare::FUN_005e8d60(TESForm* apForm)
{
    BGSNote* pNote = dynamic_cast<BGSNote*>(apForm);
    if (!pNote)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(pNote)))
        return true;
    if (pNote->cType != cType)
        return true;

    switch (cType)
    {
    case 0:
        if (FUN_005e9100() != pNote->FUN_005e9100())
            return true;
        break;
    case 1: {
        NoteCompareData* pMine = ((::fnv_005e8d60::NoteCompareData *)(reinterpret_cast<::BGSNote *>(this)->GetNoteDescription()));
        NoteCompareData* pTheirs = ((::fnv_005e8d60::NoteCompareData *)(reinterpret_cast<::BGSNote *>((((NoteCompare*)pNote)))->GetNoteDescription()));
        if (pMine && pTheirs)
        {
            if (pMine->IsDifferent(pTheirs))
                return true;
        }
        else if (pMine || pTheirs)
            return true;
        break;
    }
    case 2: {
        NoteCompareData* pMine = ((::fnv_005e8d60::NoteCompareData *)(reinterpret_cast<::BGSNote *>(this)->GetNoteTexture()));
        NoteCompareData* pTheirs = ((::fnv_005e8d60::NoteCompareData *)(reinterpret_cast<::BGSNote *>((((NoteCompare*)pNote)))->GetNoteTexture()));
        if (pMine && pTheirs)
        {
            if (pMine->IsDifferent(pTheirs))
                return true;
        }
        else if (pMine || pTheirs)
            return true;
        break;
    }
    case 3:
        if (FUN_005e9240() != pNote->FUN_005e9240())
            return true;
        if (FUN_005e92a0() != pNote->FUN_005e92a0())
            return true;
        break;
    }

    if (((::fnv_005e8d60::NoteQuestList *)(reinterpret_cast<::BGSExplosion *>(this)->FUN_004fadc0()))->GetSize() != ((::fnv_005e8d60::NoteQuestList *)(reinterpret_cast<::BGSExplosion *>((((NoteCompare*)pNote)))->FUN_004fadc0()))->GetSize())
        return true;

    NoteQuestList* pNode = ((::fnv_005e8d60::NoteQuestList *)(reinterpret_cast<::BGSExplosion *>(this)->FUN_004fadc0()));
    while (pNode && !pNode->IsEmpty())
    {
        TESQuest* pQuest = ((::TESQuest *)((void *)(pNode)));
        if (!reinterpret_cast<::RefList *>((((::fnv_005e8d60::NoteQuestList *)(reinterpret_cast<::BGSExplosion *>((((NoteCompare*)pNote)))->FUN_004fadc0()))))->FUN_005f65d0((void **)&(pQuest)))
            return true;
        pNode = ((::fnv_005e8d60::NoteQuestList *)(reinterpret_cast<::Callees *>((pNode))->FUN_00726070()));
    }
    return false;
}
}  // namespace fnv_005e8d60

// Adjustor thunk: the derived class inherits a virtual that is declared by a
// secondary base, so MSVC emits a this-adjusting thunk that moves `this` back
// to the primary sub-object (sizeof(NotePrimaryBase) == 0x30) before jumping
// to the implementation.
struct NotePrimaryBase
{
    virtual void FUN_005e9520();
    char unk04[0x2c];
};

struct NoteSecondaryBase
{
    virtual void FUN_005e9520();
};

struct NoteDerived : NotePrimaryBase, NoteSecondaryBase
{
    NoteDerived();
// @fnv 0x005e9520
    virtual void FUN_005e9520();
};

NoteDerived::NoteDerived()
{}
