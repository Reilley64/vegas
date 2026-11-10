// fallout_shared/tesmodellist.cpp: TESModelList, ActorValue, FileEntryListCollection, DelStandIn (16 functions)

#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_00461560_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00475220.h"
#include "fnv/decl/FUN_0047ded0_shell.h"
#include "fnv/decl/List_48a2c0.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_0048d000.h"
#include "fnv/symbols_005f8000.h"
#include "fnv/symbols_01183000.h"
#include "tesmodellist_types_TESModelList.h"
#include <new>

namespace ActorValue {
enum Index
{
    IndexPlaceholder = 0
};
}

class ActorValueOwner
{
  public:
    virtual int GetActorValue(ActorValue::Index index);
};

class TESModelListCopyTarget
{
  public:
    virtual void vfn_00() = 0;
    virtual void vfn_04() = 0;
    virtual void vfn_08() = 0;
    virtual void vfn_0c() = 0;
    virtual unsigned short vfn_10() = 0;
};

// @fnv 0x004753a0
FileEntryListCollection* FileEntryListCollection::ClearData(unsigned int flags)
{
    reinterpret_cast<::FUN_00475220 *>(this)->FUN_00475220::~FUN_00475220();
    if (flags & 1)
        ::operator delete(this);
    return this;
}

// @fnv 0x00489ae0
TESModelList::~TESModelList()
{
    ClearComponent();
}

// @fnv 0x005fa180
unsigned int TESModelList::BaseFormRecord(unsigned int type)
{
    unsigned int result = 0;
    if (::FUN_00406d70((*(int *)&(const ::ActorValue::Index &)((ActorValue::Index)type)), 0x400))
    {
        result = ((bool)(::FUN_005f8f70((char *)(((TESModelList*)((char*)this - 0x100))))));
    }
    else
    {
        switch (type)
        {
        case 0x38:
            result = ((TESModelListCopyTarget*)&this->m_kModelData.m_uiFileEntryCount)->vfn_10();
            break;
        default:
            result = ((ActorValueOwner*)this)->ActorValueOwner::GetActorValue((ActorValue::Index)type);
            break;
        }
    }
    return result;
}

struct BGSLoadFormBuffer;
struct BGSMessageIcon;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
class NiAVObject;
struct NiColor;
struct NiPoint3;
class Script;
class TESBoundObject;
class TESForm;
class TESFullName;
struct TESIcon;
class TESModel;
class TESModelTextureSwap;
class TESObject;
struct TESFormList;
class TESObjectREFR;
class TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00478690_shell : public TESModelList
{
    void FUN_00478690();
};

struct Dummy004753a0
{
    void* Destroy(unsigned int);
};

// Releases the object stored at offset 4 by calling its virtual method with 1, then sets that pointer to null.
// @fnv 0x00478690
void FUN_00478690_shell::FUN_00478690()
{
    Dummy004753a0* p;
    Dummy004753a0* p2;
    p2 = *(Dummy004753a0**)&this->m_kModelPaths.m_item;
    p = p2;
    p ? p->Destroy(1) : 0;
    *(void**)&this->m_kModelPaths.m_item = 0;
}

union SETTING_VALUE
{
    float f;
};

class SettingT_GameSettingCollection_
{
  public:
};

struct GameSettingCollection;
template <class T> class SettingT;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting43;

struct TESActorBaseData
{
};

// Returns the byte at pThis+0x12d, adding the scaled level from the actor base data when it matches the PC level.
// @fnv 0x005f8f70
unsigned char FUN_005f8f70(char* pThis)
{
    unsigned char ucLevel = static_cast<unsigned char>(pThis[0x12d]);
    if (reinterpret_cast<::FUN_00461560_shell *>((reinterpret_cast<TESActorBaseData*>(pThis + 0x30)))->FUN_00461560())
    {
        short slevel = reinterpret_cast<::FUN_0047ded0_shell *>((reinterpret_cast<TESActorBaseData*>(pThis + 0x30)))->FUN_0047ded0();
        if (slevel < 1)
            slevel = 1;
        ucLevel =
            ucLevel +
            static_cast<unsigned char>(
                slevel * ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(reinterpret_cast<SettingT_GameSettingCollection_&>(originalRuntimeFloatSetting43)))))->f);
    }
    return ucLevel;
}

struct FUN_005fa180_cls : public ActorValueOwner
{
    char pad[0xc - 4];
    int FUN_005fa180(ActorValue::Index aeIndex);
};
// @fnv 0x005fa180
int FUN_005fa180_cls::FUN_005fa180(ActorValue::Index aeIndex)
{
    int result = 0;
    if (::FUN_00406d70((*(int *)&(aeIndex)), 0x400))
    {
        result = ((bool)(::FUN_005f8f70((char *)(((TESModelList*)((char*)this - 0x100))))));
    }
    else
    {
        switch (aeIndex)
        {
        case 0x38:
            result = ((TESModelListCopyTarget*)((char*)this + 0xc))->vfn_10();
            break;
        default:
            result = ActorValueOwner::GetActorValue(aeIndex);
            break;
        }
    }
    return result;
}

extern unsigned int _data_011c16bc;
struct BFC_s
{
    virtual void v();
    BFC_s();
};
struct SL
{
    char p[8];
    SL();
    ~SL();
};
struct SL2
{
    char p[8];
    SL2();
};
struct FUN_00489a60 : public BFC_s
{
    SL a;
    SL2 b;
    FUN_00489a60();
    virtual void ClearData();
};
// Initializes the object by calling ClearData().
// @fnv 0x00489a60
FUN_00489a60::FUN_00489a60()
{
    ClearData();
}

struct Sub00489ce0
{
};
struct S00489ce0
{
    char pad[0xc];
    Sub00489ce0 sub;
    void FUN_00489fa0(const char*);
    void LoadStringChunk(void* p1, TESFile* apFile);
};
// @fnv 0x00489ce0
void S00489ce0::LoadStringChunk(void* p1, TESFile* apFile)
{
    if (!apFile || !p1)
        return;
    unsigned int id = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((apFile))->FUN_004726b0()));
    switch (id)
    {
    case 0x5a46494e: {
        char* pChunkBuffer = new char[reinterpret_cast<::FUN_00401660_Class *>((apFile))->GetField25C()];
        {
            char* pString = pChunkBuffer;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((apFile))->FUN_00472890((char *)(pChunkBuffer), 0);
            while (*pString)
            {
                FUN_00489fa0(pString);
                pString += ::FUN_0044a670(pString) + 1;
            }
        }
        delete pChunkBuffer;
        break;
    }
    case 0x5446494e:
        reinterpret_cast<::FileEntryListCollection *>(&(sub))->LoadFromTESFile((::TESModelList *)(p1), apFile);
        break;
    }
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* Destroy(unsigned int flags);
};
// Runs the destructor on this object, frees it when flags has bit 0 set, and returns this.
// @fnv 0x004753a0
void* DelStandIn::Destroy(unsigned int flags)
{
    reinterpret_cast<::FUN_00475220 *>((((DtorStandIn*)this)))->FUN_00475220::~FUN_00475220();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

struct FUN_0048a010_shell : public FileEntryListCollection
{
    void ClearAndDeleteArray();
};
// Deletes every filename string in the list at offset 4, then calls ClearAndDeleteArray on the object at offset 12.
// @fnv 0x00489b40
void TESModelList::ClearComponent()
{
    while (!this->m_kModelPaths.IsEmpty())
    {
        const char* filenameToDelete;
        const char* filename;
        filenameToDelete = (((&this->m_kModelPaths))->m_item);
        this->m_kModelPaths.RemoveHead();
        filename = filenameToDelete;
        ::operator delete((void*)filename);
    }
    reinterpret_cast<::FUN_0048a010_shell *>(((&this->m_kModelData)))->ClearAndDeleteArray();
}

struct FUN_0048a0a0
{
    ~FUN_0048a0a0();
};
// Deletes each element of the array at this+4, frees the array, nulls the pointer, and resets the count at this+0 to zero.
// @fnv 0x0048a010
void FUN_0048a010_shell::ClearAndDeleteArray()
{
    unsigned int i;
    if (*(FUN_0048a0a0***)&this->m_ppElementArray)
    {
        for (i = 0; i < *(unsigned int*)this; i++)
            delete (*(FUN_0048a0a0***)&this->m_ppElementArray)[i];
        delete *(FUN_0048a0a0***)&this->m_ppElementArray;
        *(FUN_0048a0a0***)&this->m_ppElementArray = 0;
    }
    *(unsigned int*)this = 0;
}

namespace fnv_00489db0 {
struct PackedRecordData;
class Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
class ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct MagicItemForm;
class NiAVObject;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
class TESActorBase;
struct TESActorBaseData;
struct TESAmmo;
class TESBoundObject;
class TESContainer;
struct TESFaction;
class TESForm;
struct TESHealthForm;
struct TESLevItem;
struct TESLevSpell;
class TESObject;
class TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
class TESObjectREFR;
class TESObjectWEAP;
class TESPackage;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00489db0_shell : public TESModelList
{
    void CopyModelListFromComponent(BaseFormComponent*);
};

struct S00489ce0
{
    void FUN_00489fa0(const char*);
};
struct PathingLocation;
struct PathingRequest
{
};
struct FUN_0048a2c0_shell
{
};
// Casts component to TESModelList, copies each filename via FUN_00489fa0, then copies the origin pathing location.
// @fnv 0x00489db0
void FUN_00489db0_shell::CopyModelListFromComponent(BaseFormComponent* component)
{
    TESModelList* source = dynamic_cast<TESModelList*>(component);
    if (!source)
        return;
    ((TESModelListCopyTarget*)this)->vfn_04();
    BSSimpleList<char const*>* list = &source->m_kModelPaths;
    while (list)
    {
        const char* filename = (list->m_item);
        if (filename)
            ((S00489ce0*)this)->FUN_00489fa0(filename);
        list = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(list))->FUN_00726070()));
    }
    reinterpret_cast<::List_48a2c0 *>((((FUN_0048a2c0_shell*)&this->m_kModelData.m_uiFileEntryCount)))->FUN_0048a2c0((::List_48a2c0 *)(::fnv_00489db0::PathingLocation *)(((::fnv_00489db0::PathingLocation *)(::GetOffsetC((std::intptr_t)(((PathingRequest*)source)))))));
}
}  // namespace fnv_00489db0

namespace fnv_00489fa0 {
struct TaskQueueInterface
{
};
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_00489fa0_shell
{
    char pad[4];
    bool ContainsFile(const char*);
    void FUN_00489fa0(const char*);
};
// If the string is not already present, allocates a copy of it, copies the text into it, and appends it to the list at this+4.
// @fnv 0x00489fa0
void FUN_00489fa0_shell::FUN_00489fa0(const char* apString)
{
    if (!ContainsFile(apString))
    {
        int size = ((int)(::FUN_0044a670(apString))) + 1;
        char* copy = static_cast<char*>(operator new(size));
        char* dest = copy;
        ::TaskQueueInterface::CopyStringToBuffer(dest, size, apString);
        reinterpret_cast<::Callees *>((((SoundListView*)((char*)this + 4))))->FUN_00905820((void *)&(dest));
    }
}
}  // namespace fnv_00489fa0

struct FNV_NodeIter
{
};

extern char DAT_01186b14;


struct FUN_00489e40_cls
{
    char pad[4];
    bool HasAnyMismatchedEntry(unsigned int arg);
};

// Looks up a record via FUN_00ec43fb and walks both node lists, returning true if any pair of entries differs or the lists have different lengths.
// @fnv 0x00489e40
bool FUN_00489e40_cls::HasAnyMismatchedEntry(unsigned int arg)
{
    char* p = (char*)dynamic_cast<::TESModelList *>(reinterpret_cast<::BaseFormComponent *>(arg));
    if (p == 0)
    {
        return true;
    }
    FNV_NodeIter* a = (FNV_NodeIter*)((char*)this + 4);
    FNV_NodeIter* b = (FNV_NodeIter*)(p + 4);
    std::intptr_t y4;
    std::intptr_t x3;
    while (a != 0 && b != 0)
    {
        x3 = *((int *)((void *)(a)));
        y4 = *((int *)((void *)(b)));
        if ((x3 == 0 && y4 != 0) || (x3 != 0 && y4 == 0))
        {
            return true;
        }
        else
        {
            if (x3 != 0 && y4 != 0 && ::FUN_00404dc0((const char *)(x3), (const char *)(y4)) != 0)
            {
                return true;
            }
        }
        a = ((::FNV_NodeIter *)(reinterpret_cast<::Callees *>((a))->FUN_00726070()));
        b = ((::FNV_NodeIter *)(reinterpret_cast<::Callees *>((b))->FUN_00726070()));
    }
    if (a != 0 || b != 0)
    {
        return true;
    }
    return false;
}


struct FUN_00489f20_shell : TESModelList
{
    bool ContainsFile(const char* filename);
};

// Returns true if filename is non-null and matches an entry in the model list, otherwise false.
// @fnv 0x00489f20
bool FUN_00489f20_shell::ContainsFile(const char* filename)
{
    if (m_kModelPaths.IsEmpty() || filename == 0)
        return false;

    BSSimpleList<const char*>* entry = &m_kModelPaths;
    while (entry != 0)
    {
        const char* value = (entry->m_item);
        if (value && FUN_00404dc0(value, filename) == 0)
            return true;
        entry = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(entry))->FUN_00726070()));
    }

    return false;
}


struct FUN_00489ba0_shell : public TESModelList
{
    void CopyModelListToBuffer(void* destination, unsigned int flags);
};

// If the model list is non-empty, concatenates its strings into a new buffer, copies it to destination, frees it, then clears the list data.
// @fnv 0x00489ba0
void FUN_00489ba0_shell::CopyModelListToBuffer(void* destination, unsigned int flags)
{
    if (!m_kModelPaths.IsEmpty())
    {
        std::uintptr_t iStack_8 = 1;
        BSSimpleList<const char*>* iStack7 = &m_kModelPaths;
        const char* piVar4;
        char* allocResult;
        char* puVar4;
        char* puStack_18;
        unsigned int iStack_c;
        const char* iVarTmp;
        unsigned int count9;
        char* freeBuffer_;

        while (iStack7 != 0)
        {
            piVar4 = (iStack7->m_item);
            if (piVar4 != 0)
                iStack_8 = iStack_8 + FUN_0044a670(piVar4) + 1;
            iStack7 = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(iStack7))->FUN_00726070()));
        }

        allocResult = (char*)::operator new(iStack_8);
        puVar4 = allocResult;
        puStack_18 = puVar4;
        iStack7 = &m_kModelPaths;
        iStack_c = iStack_8;
        while (iStack7 != 0)
        {
            iVarTmp = (iStack7->m_item);
            if (iVarTmp != 0)
            {
                ::TaskQueueInterface::CopyStringToBuffer(puStack_18, iStack_c, iVarTmp);
                count9 = FUN_0044a670(iVarTmp) + 1;
                puStack_18 = puStack_18 + count9;
                iStack_c = iStack_c - count9;
            }
            iStack7 = ((::BSSimpleList<const char *> *)(reinterpret_cast<::Callees *>((void *)(iStack7))->FUN_00726070()));
        }
        *puStack_18 = 0;
        ::FUN_004856f0(destination, puVar4, (void *)(iStack_8));
        freeBuffer_ = puVar4;
        ::operator delete(freeBuffer_);
    }
    reinterpret_cast<::FUN_004534f0_shell *>(&(m_kModelData))->FUN_004534f0(flags);
}
