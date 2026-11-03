// fallout/misc/saveload/bgsloadgamesubbuffer.cpp: BGSLoadGameSubBuffer, LoadGameSubBufferQueue, SubBufferMap, Holder and more (20 functions)

#include "fnv/decl/AnimSelf.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00422940_shell.h"
#include "fnv/decl/FUN_00422ac0_shell.h"
#include "fnv/decl/FUN_00435b20_shell.h"
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00486620_shell.h"
#include "fnv/decl/FUN_0049bb50_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_00576d30_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_00844700_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00851110_shell.h"
#include "fnv/decl/FUN_0085efc0_Class.h"
#include "fnv/decl/FUN_008657e0_cls.h"
#include "fnv/decl/PlayerL.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_0043fcd0__FUN_0043fcd0_shell.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_0050f9c0__FUN_0050f9c0_shell.h"
#include "fnv/decl/fnv_00562de0__FUN_00562de0_cls.h"
#include "fnv/decl/fnv_00562ed0__RefX.h"
#include "fnv/decl/fnv_00563650__FUN_00563650_Class.h"
#include "fnv/decl/fnv_005636e0__FUN_005636e0_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/decl/fnv_008647f0__FUN_008647f0_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865ad0__BGSSaveFormBuffer.h"
#include "fnv/decl/fnv_008a8150__FUN_008a8150_shell.h"
#include "fnv/decl/fnv_009306d0__FUN_009306d0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_00846000.h"
#include "fnv/symbols_0084d000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_011de000.h"
#include "bgsloadgamesubbuffer_types_QUEUED_SUB_BUFFER_TYPE.h"
#include "bgsloadgamesubbuffer_types_BGSSaveLoadQueuedSubBufferMap.h"
#include "bgsloadgamesubbuffer_decls.h"

extern unsigned int __cdecl GetEncodedIntegerSize(unsigned int value);
extern void __cdecl WriteEncodedInteger(char* destination, unsigned int value);
extern "C" void* __cdecl memcpy(void* destination, const void* source, unsigned int size);

typedef LockFreeMap<TESObjectREFR*, BSTreeNode*>::ThreadSafeHashTableNode QueuedHashListNode;
typedef LockFreeMap<TESObjectREFR*, BSTreeNode*>::ThreadSafePointer<QueuedHashListNode> QueuedMarkedPointer;

// @fnv 0x008655a0
void BGSLoadGameSubBuffer::LoadGame(BGSLoadGameBuffer* buffer)
{
    char* byteDestination;
    {
        unsigned int size;
        {
            unsigned int value = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((reinterpret_cast<BGSLoadFormBuffer*>(buffer)))->FUN_00864a60();
            if (value == 0)
                return;
            {
                unsigned int total;
                {
                    char* cursor;
                    size = GetEncodedIntegerSize(value);
                    total = value + size + 1;
                    cursor = new char[total];
                    reinterpret_cast<::FUN_00537e90 *>((reinterpret_cast<QuantityData*>(this)))->SetQuantity((unsigned int)cursor);
                    byteDestination = cursor;
                    typedef unsigned char(__thiscall * ReadByte)(BGSLoadGameBuffer*);
                    *byteDestination = ((ReadByte)buffer->m_ppVirtualMethodTable[0])(buffer);
                    cursor++;
                    WriteEncodedInteger(cursor, value);
                    cursor += size;
                    memcpy(cursor, ((char *)(::GetCombinedValue((int)(buffer)))), value);
                    reinterpret_cast<::FUN_0049bb50_shell *>((reinterpret_cast<ActorPackageContext*>(buffer)))->AddToOffset(value);
                }
            }
        }
    }
}

// Loads a queued sub-buffer, resolves the form key, and stores the loaded reference in the map for the given type.
// @fnv 0x008652f0
void LoadGameSubBufferQueue::ProcessSubBuffer(QUEUED_SUB_BUFFER_TYPE type, BGSLoadFormBuffer* buffer, TESForm* form)
{
    TESForm* key;
    {
        QueuedMarkedPointer subBuffer;
        reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)->LoadGame(reinterpret_cast<BGSLoadGameBuffer*>(buffer));
        if (!(TESForm*)subBuffer)
            return;
        typedef TESForm*(__thiscall * GetForm)(BGSLoadFormBuffer*);
        key = form ? form : ((GetForm)buffer->m_ppVirtualMethodTable[1])(buffer);
        reinterpret_cast<::FUN_00844700_Class *>((reinterpret_cast<NiTPointerMap<unsigned int, TESObjectREFR*>*>(&m_kSubBuffersByType[type])))->FUN_00844700((unsigned int)key, (unsigned int)(reinterpret_cast<TESObjectREFR*>(subBuffer.m_pObject)));
    }
}

// @fnv 0x00864e20
BGSLoadFormBuffer* BGSLoadGameSubBuffer::CreateFormBuffer(TESForm* form)
{
    BGSLoadFormBuffer* result = new BGSLoadFormBuffer;
    {
        unsigned int offset;
        {
            char* data = pBuffer;
            reinterpret_cast<TESRecipe*>(result)->SetRequiredSkill((::ActorValue::Index)((int)form));
            reinterpret_cast<::fnv_008a8150::FUN_008a8150_shell *>((result))->FUN_008a8150((unsigned char)*data);
            offset = 1;
            {
                unsigned int value;
                {
                    char* encoded = pBuffer + 1;
                    value = 0;
                    offset += ReadEncodedInteger(encoded, value);
                    reinterpret_cast<::fnv_008647f0::FUN_008647f0_shell *>((result))->FUN_008647f0(pBuffer, value + offset, offset);
                    pBuffer = 0;
                    return result;
                }
            }
        }
    }
}

// Resolves the form's load buffer and loads its queued animation for actors, or logs an error for non-references and actors without animation.
// @fnv 0x00864b00
void BGSLoadGameSubBuffer::RestoreAnimation(TESForm* form)
{
    BGSLoadFormBuffer* loadBuffer;
    {
        bool firstPerson = false;
        if (form == reinterpret_cast<TESForm*>(((::TESBoundObject *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((::_g_thePlayer))->FUN_007af430()))))
        {
            firstPerson = true;
            form = ::_g_thePlayer;
        }
        loadBuffer = CreateFormBuffer(form);
        if (form->GetIsReference())
        {
            TESForm* reference = form;
            typedef bool(__thiscall * IsActor)(TESForm*);
            if (((IsActor)(*reinterpret_cast<void***>(reference))[0x40])(reference))
            {
                Animation* animation = 0;
                if (reference == ::_g_thePlayer)
                    animation = ::_g_thePlayer->GetAnimation(firstPerson);
                else
                {
                    typedef Animation*(__thiscall * GetAnimation)(TESForm*);
                    animation = ((GetAnimation)(*reinterpret_cast<void***>(reference))[0x79])(reference);
                }
                if (animation)
                    reinterpret_cast<::AnimSelf *>((animation))->Load(loadBuffer);
                else
                    ::FUN_00845cc0("ANIMATION: Actor '%s' %08X with queued animation does not have one to load",
                               form->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())));
            }
            else
                reinterpret_cast<::fnv_005636e0::FUN_005636e0_shell *>((reinterpret_cast<TESObjectREFR*>(reference)))->FUN_005636e0((::fnv_005636e0::BGSLoadFormBuffer *)(loadBuffer));
        }
        else
            ::FUN_00845cc0("SAVELOAD: Form '%s' %08X with queued havok data is not a reference", form->GetName(),
                       ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())));
        delete reinterpret_cast<BGSLoadGameBuffer*>(loadBuffer);
    }
}

// @fnv 0x00864c50
void BGSLoadGameSubBuffer::ReadAnimationState(TESForm* form)
{
    BGSLoadFormBuffer* loadBuffer = CreateFormBuffer(form);
    if (form->GetIsReference())
    {
        TESForm* reference = form;
        if (reference->IsMobileObject())
        {
            MobileObject* mobile = reinterpret_cast<MobileObject*>(form);
            if (((::bhkCharacterController *)(reinterpret_cast<::fnv_009306d0::FUN_009306d0_shell *>((mobile))->FUN_009306d0())))
            {
                MiddleHighProcess* process = reinterpret_cast<MiddleHighProcess*>(
                    ((::TargetDoorController *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<MiddleHighProcess*>(mobile)))->GetBaseTexture())));
                TargetDoorController* saved = reinterpret_cast<TargetDoorController*>(process);
                reinterpret_cast<::PlayerL *>((reinterpret_cast<MiddleHighProcess*>(saved)))->FUN_00928a50((::BGSLoadFormBufferL *)(loadBuffer));
            }
            else
                ::FUN_00845cc0("SAVELOAD: Mobile Object '%s' %08X with queued char controller does not have one to load",
                           form->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())));
        }
        else
            ::FUN_00845cc0("SAVELOAD: Reference '%s' %08X with queued char controller is not a mobile object",
                       form->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())));
    }
    else
        ::FUN_00845cc0("SAVELOAD: Form '%s' %08X with queued char controller is not a reference", form->GetName(),
                   ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())));
    delete reinterpret_cast<BGSLoadGameBuffer*>(loadBuffer);
}

// @fnv 0x00865360
void LoadGameSubBufferQueue::QueueAnimationAndCharController()
{
    ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE_QUEUED_SUB_BUFFER_ANIMATION);
    ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE_QUEUED_SUB_BUFFER_CHAR_CONTROLLER);
    ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE_QUEUED_SUB_BUFFER_HAVOK_DATA);
}

// Empty constructor for the class; performs no initialization.
// @fnv 0x008651d0
LoadGameSubBufferQueue::LoadGameSubBufferQueue()
{}

// @fnv 0x00865200
void NiTMap_TESForm___BGSLoadGameSubBuffer_Constructor(void)
{
    // this is in ecx (thiscall calling convention for MSVC)
    // The thunk constructs the NiTMap by calling the constructor with size 0x25 (37)
}

// 0x00865200 is the compiler-generated member constructor thunk for m_kSubBuffersByType
// (??_FNiTMap_TESForm___BGSLoadGameSubBuffer_@@QAEXXZ): the compiler builds the three
// queued-sub-buffer maps through it inside eh_vector_constructor_iterator, so it carries
// no @fnv annotation of its own.

struct SubBufferValue
{
    void* data;
};
struct SubBufferMapItem
{
    SubBufferMapItem* m_pkNext;
    TESForm* m_key;
    SubBufferValue m_val;
};
struct SubBufferMap
{
    virtual unsigned int Reserved();
    virtual unsigned int KeyToHashIndex(TESForm* key) const;
    unsigned int m_uiHashSize;
    SubBufferMapItem** m_ppkHashTable;
    void GetNextEntry(void*& pos, TESForm*& key, SubBufferValue& val) const;
};

// Reads the key and value from the item at pos, then advances pos to the next item in the chain or the next non-empty hash bucket, or null.
// @fnv 0x00865730
void SubBufferMap::GetNextEntry(void*& apPosition, TESForm*& key, SubBufferValue& aValue) const
{
    unsigned int i;
    SubBufferMapItem* pkItem = (SubBufferMapItem*)apPosition;
    key = pkItem->m_key;
    aValue = pkItem->m_val;
    if (pkItem->m_pkNext)
    {
        apPosition = pkItem->m_pkNext;
    }
    else
    {
        i = KeyToHashIndex(pkItem->m_key);
        for (i++; i < m_uiHashSize; i++)
        {
            pkItem = m_ppkHashTable[i];
            if (pkItem)
            {
                apPosition = pkItem;
                return;
            }
        }
        apPosition = 0;
    }
}

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct Holder
{
    void FUN_0085f010(TESForm*, unsigned short);
};
// Looks up the parent form's ID in the map at offset 0x58; if present, uses 0 instead, then passes the ID and type to FUN_0085efc0.
// @fnv 0x0085f010
void Holder::FUN_0085f010(TESForm* apParentForm, unsigned short aeType)
{
    unsigned int uiExistingValue;
    unsigned int formID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((apParentForm))->FUN_0084e3a0()));
    if (reinterpret_cast<::fnv_00853130::NiTMapBase *>((void *)((*(DummyPointerMap**)((char*)this + 0x58))))->FUN_00853130(formID, (::fnv_00853130::CombatThreatRecord *&)(uiExistingValue)))
        formID = 0;
    reinterpret_cast<::FUN_0085efc0_Class *>(this)->FUN_0085efc0(*(DummyPointerMap**)((char*)this + 0x58), formID, aeType);
}

struct BGSSaveGameBuffer
{
    void FUN_00865f60(unsigned int);
    void WriteAtOffset(void*, unsigned int, unsigned int);
};
struct FakeBGSLoadGameSubBuffer
{
    char* pBuffer;
    void WriteToSaveGameBuffer(BGSSaveGameBuffer* apSaveGameBuffer);
};
// Reads a size from the buffer, writes it to the save game buffer, then writes the following data of that size.
// @fnv 0x00865510
void FakeBGSLoadGameSubBuffer::WriteToSaveGameBuffer(BGSSaveGameBuffer* apSaveGameBuffer)
{
    char* padvancedBuffer;
    unsigned int isize;
    padvancedBuffer = pBuffer + 1;
    isize = 0;
    padvancedBuffer += ReadEncodedInteger(padvancedBuffer, isize);
    apSaveGameBuffer->FUN_00865f60(isize);
    apSaveGameBuffer->WriteAtOffset(padvancedBuffer, isize, 1);
}

struct FUN_00865660_This
{
    void* vtable;
    FUN_00865660_This* Construct(unsigned int);
};
extern int DAT_01082288;
struct Dummy00865690
{
    void* DestroyAndFreeIfFlagged(unsigned int);
};
// Destructs the NiTMap_TESForm___BGSLoadGameSubBuffer_ object and, if bit 0 of flags is set, frees it with operator delete; returns this.
// @fnv 0x00865690
void* Dummy00865690::DestroyAndFreeIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_008657e0_cls *>((((NiTMap_TESForm___BGSLoadGameSubBuffer_*)this)))->FUN_008657e0_cls::~FUN_008657e0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct TESObjectREFR_Havok : public TESForm
{
};
struct FUN_00864d80_shell : public BGSLoadGameSubBuffer
{
    void LoadQueuedHavokData(TESForm* form);
};
// Iterates the queued sub-buffer for the given type, loading or deferring each form, then clears the map.
// @fnv 0x00865390
void LoadGameSubBufferQueue::ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE eSubBufferType)
{
    void* pIterPos =
        reinterpret_cast<BGSReconstructFormsInAllFilesMap*>(&m_kSubBuffersByType[eSubBufferType])->GetFirstPos();
    while (pIterPos)
    {
        TESForm* form = 0;
        QueuedMarkedPointer subBuffer;
        {
            reinterpret_cast<::SubBufferMap *>((reinterpret_cast<QueuedMap*>(&m_kSubBuffersByType[eSubBufferType])))->GetNextEntry(pIterPos, form, (::SubBufferValue &)(subBuffer));
            {
                unsigned char load = true;
                {
                    TESObjectREFR* actor;
                    {
                        TESObjectREFR* reference = 0;
                        actor = 0;
                        if (form->GetIsReference())
                        {
                            reference = reinterpret_cast<TESObjectREFR*>(form);
                            load = reinterpret_cast<unsigned int>(((::NiAVObject *)(reinterpret_cast<::fnv_0043fcd0::FUN_0043fcd0_shell *>((reference))->FUN_0043fcd0()))) != 0;
                            typedef bool(__thiscall * IsActor)(TESObjectREFR*);
                            if (((IsActor)(*reinterpret_cast<void***>(reference))[0x40])(reference))
                                actor = reference;
                        }
                        if (load)
                        {
                            switch (eSubBufferType)
                            {
                            case 0:
                                reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)->RestoreAnimation(form);
                                break;
                            case 1:
                                reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)->ReadAnimationState(form);
                                break;
                            case 2:
                                reinterpret_cast<::FUN_00864d80_shell *>((reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)))->LoadQueuedHavokData(form);
                                break;
                            }
                        }
                        else
                        {
                            switch (eSubBufferType)
                            {
                            case 0:
                                if (actor)
                                    reinterpret_cast<::FUN_00435b20_shell *>((reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)))->FUN_00435b20();
                                else if (reference)
                                    reinterpret_cast<::FUN_00422940_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00422940(
                                        reinterpret_cast<char*>((TESForm*)subBuffer));
                                break;
                            case 1:
                                reinterpret_cast<::FUN_00435b20_shell *>((reinterpret_cast<BGSLoadGameSubBuffer*>(&subBuffer)))->FUN_00435b20();
                                break;
                            case 2:
                                if (reference)
                                    reinterpret_cast<::FUN_00422ac0_shell *>((((::ExtraDataList *)(reinterpret_cast<::FUN_005d43c0_ *>((reference))->FUN_005d43c0()))))->FUN_00422ac0(
                                        reinterpret_cast<char*>((TESForm*)subBuffer));
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<NiTPointerMap<unsigned int, unsigned int>*>(&m_kSubBuffersByType[eSubBufferType])))->FUN_00438af0();
}
// Loads queued havok data into the form if it is a reference, otherwise logs an error, then deletes the load buffer.
// @fnv 0x00864d80
void FUN_00864d80_shell::LoadQueuedHavokData(TESForm* form)
{
    BGSLoadFormBuffer* buffer = CreateFormBuffer(form);
    if (form->GetIsReference())
    {
        TESForm* reference = form;
        reinterpret_cast<::fnv_00562ed0::RefX *>((reinterpret_cast<TESObjectREFR_Havok*>(reference)))->FUN_00562ed0((::fnv_00562ed0::BooleanIntegerAccessor *)(buffer));
    }
    else
        ::FUN_00845cc0("SAVELOAD: Form '%s' %08X with queued havok data is not a reference", form->GetName(),
                   ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())));
    delete reinterpret_cast<BGSLoadGameBuffer*>(buffer);
}

extern int DAT_010822a8;
struct FUN_008656c0_This
{
    void* vtable;
    unsigned int m_uiCount;
    void* m_pItems;
    unsigned int m_uiSize;
    FUN_008656c0_This* FUN_008656c0(unsigned int count);
};
// Calls FUN_008656c0 with size, sets the vtable to DAT_01082288, and returns this.
// @fnv 0x00865660
FUN_00865660_This* FUN_00865660_This::Construct(unsigned int size)
{
    reinterpret_cast<::FUN_008656c0_This *>(this)->FUN_008656c0(size);
    vtable = (void*)&DAT_01082288;
    return this;
}
// Sets the vtable, stores count, allocates count*4 bytes for m_pItems, zeroes them, and returns this.
// @fnv 0x008656c0
FUN_008656c0_This* FUN_008656c0_This::FUN_008656c0(unsigned int count)
{
    unsigned int uiBytes;
    vtable = (void*)&DAT_010822a8;
    m_uiCount = count;
    m_uiSize = 0;
    uiBytes = m_uiCount << 2;
    m_pItems = ::FUN_00aa1070(uiBytes);
    ::FUN_00403d30(m_pItems, 0, m_uiCount << 2);
    return this;
}

struct VersionByte
{
    unsigned char cVersion;
};

struct BGSSaveFormBuffer : public BSSimpleList<TESForm*>
{
    unsigned char GetVersion();
};

unsigned char BGSSaveFormBuffer::GetVersion()
{
    return 0;
}

struct FUN_00865120_shell
{
    char* pBuffer;
    void FUN_00865120(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x00865120
void FUN_00865120_shell::FUN_00865120(BGSSaveFormBuffer* apSaveGameBuffer)
{
    char* pbuffer;
    unsigned int isize;
    unsigned int isubBufferSize;
    unsigned int ivariableValueSize;
    VersionByte* pheader;

    isubBufferSize = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(apSaveGameBuffer)))->FUN_0084e3a0()));
    if (isubBufferSize == 0)
        return;

    ivariableValueSize = GetEncodedIntegerSize(isubBufferSize);
    isize = isubBufferSize + ivariableValueSize + 1;

    this->pBuffer = new char[isize];
    pbuffer = this->pBuffer;
    pheader = reinterpret_cast<VersionByte*>(pbuffer);

    pheader->cVersion = reinterpret_cast<::BGSLoadFormBuffer *>((apSaveGameBuffer))->GetVersion();
    ++pbuffer;

    WriteEncodedInteger(pbuffer, isubBufferSize);

    pbuffer += ivariableValueSize;

    memcpy(pbuffer, ((::BSSimpleList< ::TESForm *> *)(reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<TESForm*>*>(apSaveGameBuffer)))->FUN_00726070())),
           isubBufferSize);
}

// Destructor of the per-type save-game sub-buffer table: release every buffer in the three maps,
// empty them, then destroy the maps.

class TESForm;

struct QueuedSubBufferValue
{
    char* m_pBuffer;

};

class QueuedSubBufferTable
{
  public:
    void* m_pVtbl;
    unsigned int m_uiHashSize;
    void** m_ppHashTable;
    unsigned int m_uiCount;

    ~QueuedSubBufferTable();
    void RemoveAll();
};

class FUN_00865220
{
  public:
    QueuedSubBufferTable m_akMaps[3];

    ~FUN_00865220();
};

// Frees every queued sub-buffer value in each of the three maps, then removes all entries from each map.
// @fnv 0x00865220
FUN_00865220::~FUN_00865220()
{
    for (unsigned int i = 0; i < 3; i++)
    {
        void* pIterPos = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(m_akMaps[i]))->GetFirstPos();
        while (pIterPos)
        {
            TESForm* pkForm = 0;
            QueuedSubBufferValue kVal;
            ::FUN_0044dee0((::BGSLoadGameSubBuffer *)&(kVal));
            reinterpret_cast<::SubBufferMap *>((void *)&(m_akMaps[i]))->GetNextEntry(pIterPos, pkForm, (::SubBufferValue &)(kVal));
            reinterpret_cast<::FUN_00435b20_shell *>(&(kVal))->FUN_00435b20();
        }
        reinterpret_cast<::FUN_00438af0_Class *>(&(m_akMaps[i]))->FUN_00438af0();
    }
}

// SaveAnimation: record the animation state of a reference into a save entry, or log that the form is not a reference.

class F4F20Param
{
  public:
    F4F20Param(int iValue);
    F4F20Param(const F4F20Param& rkOther);
    int m_iValue;
};

class F4F20Ref
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual bool GetBoolAt0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual const char* GetName();

    int GetFormType();
};

class F4F20Actor : public F4F20Ref
{
  public:
};

class F4F20Response
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;

    F4F20Response();
    ~F4F20Response();
};

class F4F20Counter
{
  public:
};



class F4F20Queue
{
  public:
    void QueueResponseForRef(F4F20Ref* pkRef);
};

// @fnv 0x00864f20
void F4F20Queue::QueueResponseForRef(F4F20Ref* pkRef)
{
    if (pkRef->GetBoolAt0F0())
    {
        F4F20Actor* pkActor = static_cast<F4F20Actor*>(pkRef);
        F4F20Response kResponse;
        reinterpret_cast<::fnv_00865ad0::BGSSaveFormBuffer *>(&(kResponse))->InitFormEntry(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkRef))->FUN_0084e3a0())), (*(unsigned int *)&(const ::F4F20Param &)(F4F20Param(4))), pkRef->GetFormType(), reinterpret_cast<::FUN_00851110_shell *>(((*reinterpret_cast<::F4F20Counter * *>(&::DAT_011de134))))->GetConstant27());
        reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>(&(kResponse))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(pkRef));
        reinterpret_cast<::fnv_00563650::FUN_00563650_Class *>((pkActor))->FUN_00563650((::fnv_00563650::BGSSaveFormBuffer *)(void *)(&kResponse));
        reinterpret_cast<::FUN_00865120_shell *>(this)->FUN_00865120((::BGSSaveFormBuffer *)(::F4F20Response *)(&kResponse));
    }
    else
    {
        ::FUN_00845cc0("SAVELOAD: Form '%s' %08X passed to BGSLoadGameSubBuffer::SaveAnimation() is not a reference",
                 pkRef->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pkRef))->FUN_0084e3a0())));
    }
}

extern "C" const char DAT_01082228[];
struct FUN_008c71b0
{
    unsigned int value;
    explicit FUN_008c71b0(unsigned int v);
    FUN_008c71b0(const FUN_008c71b0& other);
};
struct SaveContext_00851110
{
};
struct FUN_008659c0_Buffer
{
    void* vtable;
    char* data;
    char* next;
    char* end;
    unsigned int capacity;
    unsigned int offset;
    TESForm* form;
    unsigned int flags;
    void* stream;
    FUN_008659c0_Buffer();
    ~FUN_008659c0_Buffer();
};
struct ReferenceSaveAccess : TESObjectREFR
{
    TESBoundObject* FUN_00401170();
};
struct SubBufferSaveShell
{
    char* pBuffer;
    void FUN_00865020(TESForm* form);
};
// Saves a reference form to a sub-buffer, or logs a warning if the form is not a reference.
// @fnv 0x00865020
void SubBufferSaveShell::FUN_00865020(TESForm* form)
{
    if (form->GetIsReference())
    {
        ReferenceSaveAccess* ref = static_cast<ReferenceSaveAccess*>(form);
        FUN_008659c0_Buffer buffer;
        reinterpret_cast<::fnv_00865ad0::BGSSaveFormBuffer *>(&(buffer))->InitFormEntry(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())), (*(unsigned int *)&(const ::FUN_008c71b0 &)(FUN_008c71b0(4))), (unsigned int)(static_cast<ReferenceSaveAccess*>(form)->FUN_00401170()),
                            (unsigned char)(((void *)(reinterpret_cast<::FUN_00851110_shell *>(((*reinterpret_cast<::SaveContext_00851110 * *>(&::DAT_011de134))))->GetConstant27()))));
        reinterpret_cast<::fnv_0050f9c0::FUN_0050f9c0_shell *>(&(buffer))->FUN_0050f9c0((::fnv_0050f9c0::TESForm *)(form));
        reinterpret_cast<::fnv_00562de0::FUN_00562de0_cls *>((ref))->FUN_00562de0((::fnv_00562de0::TargetRef *)(::FUN_008659c0_Buffer *)(&buffer));
        reinterpret_cast<::FUN_00865120_shell *>(this)->FUN_00865120((::BGSSaveFormBuffer *)(::FUN_008659c0_Buffer *)(&buffer));
    }
    else
    {
        ::FUN_00845cc0(DAT_01082228, form->GetName(), ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((form))->FUN_0084e3a0())));
    }
}
