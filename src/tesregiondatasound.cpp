// tesregiondatasound.cpp: TESRegionDataSound, F4BD0Owner, RegionSoundWriter, RegionBlend (17 functions)

#include <new>
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00476b90_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_004f15c0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/RegionSource.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00503210__Unk.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "tesregiondatasound_decls.h"
#include "fnv/decl/FUN_004615d0_shell.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/symbols_00944000.h"

struct Arg_004727f0
{
    int* out;
};

// @fnv 0x004f4860
bool TESRegionDataSound::LoadRegionSoundData(TESFile* file)
{
    unsigned int sound = 0;
    switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
    case 0x444d4452: {
        unsigned int music = 0;
        reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&music), 0);
        break;
    }
    case 0x4f4d4452: {
        unsigned int unused = 0;
        {
            unsigned int id = 0;
            ::ReadChunkInt((::TESFile *)(file), ::Arg_004727f0{reinterpret_cast<int*>(&id)});
            if (id)
            {
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::fnv_00503210::Unk *>(&(Data))->FUN_00503210();
                ::ResolveFormID((unsigned int *)&(id), file);
                BGSMusicType* music = dynamic_cast<BGSMusicType*>(::FUN_004839c0(id));
                if (!music)
                    ::FUN_005b5e40();
                SetMusicType(music);
            }
        }
        break;
    }
    case 0x49534452: {
        unsigned int id = 0;
        ::ReadChunkInt((::TESFile *)(file), ::Arg_004727f0{reinterpret_cast<int*>(&id)});
        if (id)
            incidental = id;
        break;
    }
    case 0x42534452: {
        unsigned int id = 0;
        ::ReadChunkInt((::TESFile *)(file), ::Arg_004727f0{reinterpret_cast<int*>(&id)});
        reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<ScriptVariableInfo*>*>(&Battle)))->FUN_00905820(
            (void *)&(reinterpret_cast<ScriptVariableInfo* const&>(id)));
        break;
    }
    case 0x44534452: {
        unsigned int uiChunkSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
        {
            unsigned int count;
            {
                unsigned int stride = sizeof(RegionSoundEntry);
                count = uiChunkSize / stride;
                if (uiChunkSize == 4)
                    return false;
                RegionSoundEntry* buffer = new RegionSoundEntry[count];
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), count * sizeof(RegionSoundEntry));
                {
                    RegionSoundEntry* entry;
                    for (unsigned int i = 0; i < count; i++)
                    {
                        entry = new RegionSoundEntry;
                        *entry = buffer[i];
                        if (file->IsEndianConversionRequired())
                            reinterpret_cast<::Class005a6b10 *>((reinterpret_cast<ContainerItemExtraFileData*>(entry)))->FUN_005a6b10();
                        ::ResolveFormID((unsigned int *)&(entry->sound), file);
                        if (entry && entry->sound && (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->FUN_004615d0(entry->sound))
                        {
                            sound = (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->FUN_004615d0(entry->sound);
                            entry->sound = sound;
                            reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<ScriptVariableInfo*>*>(&Sounds)))->FUN_00905820(
                                (void *)&(reinterpret_cast<ScriptVariableInfo* const&>(entry)));
                        }
                        else
                            delete entry;
                    }
                }
                delete[] buffer;
            }
        }
        break;
    }
    default:
        return false;
    }
    return true;
}

struct MersenneTwister
{
    void Init(unsigned int);
    void Seed(unsigned int);
    void Kill();
    unsigned int GetRandomUInt(unsigned int, unsigned int);
    unsigned int GetRandomUInt();
    unsigned int GetRandomUInt(unsigned int);
    int Int(int, int);
    int Int();
    float Float0To1();
    float FloatNeg1To1();
    float FloatTwoPi();
    float FloatNegPiToPi();
    bool Bool(float);
    unsigned int m_uiSeed;
    unsigned int m_uiLastValue;
    char mt[2496];
    unsigned int mti;
};
struct FUN_00944480_shell : public MersenneTwister
{
    int IntInRange(int, int);
};

// @fnv 0x00944480
int FUN_00944480_shell::IntInRange(int aiMin, int aiMax)
{
    return GetRandomUInt(aiMax - aiMin) + aiMin;
}

template <int N> struct EndianSizeTag
{
};
// Reads a 4-byte chunk value into a.out and byte-swaps it when endian conversion is required; returns whether the read succeeded.
// @fnv 0x004727f0
bool ReadChunkInt(TESFile* self, Arg_004727f0 aChunkArg)
{
    bool ok = reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((self))->FUN_00472890((char *)(aChunkArg.out), 4);
    if (self->IsEndianConversionRequired())
        ::FUN_00401080(aChunkArg.out);
    return ok;
}


struct FUN_004f4330_shell : TESRegionDataSound
{
    TESForm* GetSoundForm();
};

// @fnv 0x004f4330
TESForm* FUN_004f4330_shell::GetSoundForm()
{
    return ::FUN_004839c0(this->incidental);
}

struct FUN_004f4830_shell
{
    int a;
    int b;
    int c;
    FUN_004f4830_shell* Reset();
};

// Initialises the object's fields to a=0, b=0xf and c=0, then returns this.
// @fnv 0x004f4830
FUN_004f4830_shell* FUN_004f4830_shell::Reset()
{
    a = 0;
    b = 0xf;
    c = 0;
    return this;
}

struct FUN_004f4f70_shell
{
    int m_auiShapeKeys[2];
    int m_sounds;
    bool Validate();
};

// @fnv 0x004f4f70
bool FUN_004f4f70_shell::Validate()
{
    if (m_sounds)
        return false;
    return true;
}

struct MediaSet;
struct C0084e3a0
{
};
struct S004f4350
{
    void SetMediaSet(MediaSet* ms);
};
// @fnv 0x004f4350
void S004f4350::SetMediaSet(MediaSet* pMediaSet)
{
    *(unsigned int*)((char*)this + 0x14) = pMediaSet ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((C0084e3a0*)pMediaSet)))->FUN_0084e3a0())) : 0;
}

struct F4390_standin
{
    void* FUN_004f4390(unsigned int);
};
struct SL
{
    int _00;
    int _04;
    int _08;
    SL();
    ~SL();
};
struct FUN_004f43c0
{
    int _00;
    SL _04;
    SL _10;
    FUN_004f43c0();
};
// @fnv 0x004f43c0
FUN_004f43c0::FUN_004f43c0()
{}

struct ListX
{
    int _00, _04, _08;
    ~ListX();
};
struct FUN_004f4420
{
    int _00;
    ListX _04;
    ListX _10;
    ~FUN_004f4420();
};
// Destructor for the object; destroys its two ListX members and returns.
// @fnv 0x004f4420
FUN_004f4420::~FUN_004f4420()
{}

struct FUN_004f4c40_shell
{
    char _pad[8];
    void* field8;
    bool FUN_004f4c40(void* apType);
};
// Stores apType in field8 and returns true when apType is non-null and differs from the current field8; otherwise returns false.
// @fnv 0x004f4c40
bool FUN_004f4c40_shell::FUN_004f4c40(void* apType)
{
    if (apType && apType != field8)
    {
        field8 = apType;
        return true;
    }
    return false;
}

// Copy constructor: copy the base, re-attach the source's owner, copy the id and start with an empty list.

class F4480Owner;

class F4480Base
{
  public:
    F4480Base(const F4480Base& kOther);
    virtual ~F4480Base();
    int unk04;
};

class F4480Children
{
  public:
    F4480Children();
    ~F4480Children();
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};

class F4480List
{
  public:
    void* m_pkHead;
    void* m_pkTail;
};

class FUN_004f4480 : public F4480Base
{
  public:
    FUN_004f4480(const FUN_004f4480& kOther);
    virtual ~FUN_004f4480();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual F4480Owner* GetOwner() const;


    F4480Children m_kChildList;
    int m_iID;
    F4480List m_kPending;
};

// Copy-constructs from kOther: copies the base, sets the owner, copies m_iID and clears m_kPending.
// @fnv 0x004f4480
FUN_004f4480::FUN_004f4480(const FUN_004f4480& kOther) : F4480Base(kOther)
{
    reinterpret_cast<::FUN_004f4c40_shell *>(this)->FUN_004f4c40(kOther.GetOwner());
    m_iID = kOther.m_iID;
    reinterpret_cast<::FileMatchList *>(&(m_kPending))->RemoveAll();
}


struct F4BD0Item
{

    int unk00;
};

class F4BD0List
{
  public:
    void RemoveHead();
    void Clear();

    F4BD0Item* m_pkItem;
    F4BD0List* m_pkNext;
};

class F4BD0Owner
{
  public:
    void ClearItems();

    int unk00;
    int unk04;
    int unk08;
    F4BD0List m_kUnsortedGeometryList;
};

// Repeatedly takes the head item from the list, deletes it, and finally clears the list.
// @fnv 0x004f4bd0
void F4BD0Owner::ClearItems()
{
    F4BD0List* pkList = &m_kUnsortedGeometryList;
    F4BD0Item* pkItem = 0;
    while (pkList && *((::F4BD0Item **)(new ((void *)(pkList)) ::Vec3())))
    {
        pkItem = *((::F4BD0Item **)(new ((void *)(pkList)) ::Vec3()));
        pkList->RemoveHead();
        delete pkItem;
        pkList = &m_kUnsortedGeometryList;
    }
    m_kUnsortedGeometryList.Clear();
}

struct SndBase
{
    virtual ~SndBase();
    unsigned int m_04;
};

struct FUN_004f4520_cls : SndBase
{
    FUN_004f4420 m_08;
    virtual ~FUN_004f4520_cls();
};
// Calls FUN_004f4520, then frees this via _Deallocate when flags has bit 1 set, and returns this.
// @fnv 0x004f4390
void* F4390_standin::FUN_004f4390(unsigned int flags)
{
    reinterpret_cast<::FUN_004f4520_cls *>(this)->FUN_004f4520_cls::~FUN_004f4520_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x004f4520
FUN_004f4520_cls::~FUN_004f4520_cls()
{
    reinterpret_cast<::F4BD0Owner *>(this)->ClearItems();
}

template <class T> struct RegionListAccess
{
    unsigned int FUN_005ae380();
    T& FUN_006815c0();
    RegionListAccess* FUN_00726070();
};
struct RegionSoundWriter : TESRegionDataSound
{
    void WriteRegionSoundData();
};
// Serializes the region's music type, incidental sound, battle music IDs and sound records through FUN_00485910/AppendChunk.
// @fnv 0x004f4590
void RegionSoundWriter::WriteRegionSoundData()
{
    reinterpret_cast<::RegionSource *>((this))->WriteSaveData();
    if (GetMusicType())
    {
        unsigned int musicID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((C0084e3a0*)GetMusicType())))->FUN_0084e3a0()));
        ::FUN_00485910(0x4f4d4452, musicID);
    }
    if (incidental)
        ::FUN_00485910(0x49534452, incidental);
    unsigned int battleID = 0;
    unsigned int count = ((RegionListAccess<unsigned int>*)&Battle)->FUN_005ae380();
    if (count)
    {
        RegionListAccess<unsigned int>* node = (RegionListAccess<unsigned int>*)&Battle;
        for (unsigned int i = 0; node && ((unsigned int)(new ((void *)(node)) ::Vec3())) && i < count; i++)
        {
            ::FUN_00485910(0x42534452, ((unsigned int)(new ((void *)(node)) ::Vec3())));
            node = ((::RegionListAccess<unsigned int> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
    }
    RegionSoundEntry* sound = 0;
    count = ((RegionListAccess<RegionSoundEntry*>*)&Sounds)->FUN_005ae380();
    if (count)
    {
        RegionListAccess<RegionSoundEntry*>* records = (RegionListAccess<RegionSoundEntry*>*)&Sounds;
        RegionSoundEntry* node = new RegionSoundEntry[count];
        for (unsigned int i = 0; records && ((::RegionSoundEntry *)(new ((void *)(records)) ::Vec3())) && i < count; i++)
        {
            sound = ((::RegionSoundEntry *)(new ((void *)(records)) ::Vec3()));
            node[i] = *sound;
            records = ((::RegionListAccess< ::RegionSoundEntry *> *)(reinterpret_cast<::Callees *>((records))->FUN_00726070()));
        }
        if (((bool)(::FUN_00401500())))
        {
            for (unsigned int i = 0; i < count; i++)
                reinterpret_cast<::Class005a6b10 *>((((ContainerItemExtraFileData*)&node[i])))->FUN_005a6b10();
        }
        ::AppendChunk(0x44534452, node, count * sizeof(RegionSoundEntry));
        if (((bool)(::FUN_00401500())))
        {
            for (unsigned int i = 0; i < count; i++)
                reinterpret_cast<::Class005a6b10 *>((((ContainerItemExtraFileData*)&node[i])))->FUN_005a6b10();
        }
        delete[] node;
    }
}

double __cdecl blendFloor(float);
class RegionBlend
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int Type();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void* Music();
    virtual void SetMusic(void*);
    unsigned char overrideFlag;
    unsigned char emptyFlag;
    unsigned char priority;
    unsigned char unk07;
    void BlendFrom(RegionBlend*, void*);
};
// Blends this region's override, priority and music from a type-7 source region, weighting priorities when neither overrides.
// @fnv 0x004f4cf0
void RegionBlend::BlendFrom(RegionBlend* source, void* context)
{
    RegionBlend* other = source;
    if (!source || source->Type() != 7 || !context)
        return;
    if (emptyFlag)
    {
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling())));
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())));
        SetMusic(other->Music());
    }
    else if (other->emptyFlag)
    {
        return;
    }
    else if (overrideFlag)
    {
        if (((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling())) && ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())) > ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())))
        {
            reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling())));
            reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())));
            SetMusic(other->Music());
        }
        return;
    }
    else if (((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling())))
    {
        reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(((unsigned char)(reinterpret_cast<::PatrolActorPackageData *>((other))->IsPatrolling())));
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0(((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())));
        SetMusic(other->Music());
    }
    else
    {
        if (((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())) > ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())))
            SetMusic(other->Music());
        float weight = ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) + (100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0()));
        weight += (100 - ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0()))) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>(this)->FUN_005bb4d0())) + ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0())) * ((unsigned char)(reinterpret_cast<::FUN_005bb4d0_shell *>((other))->FUN_005bb4d0()));
        weight *= 0.004999999888241291;
        reinterpret_cast<::FUN_004f15c0_shell *>(this)->FUN_004f15c0((unsigned char)blendFloor(weight));
    }
}

struct S004;
struct Obj4480
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Obj4480* FUN_004f4480(S004* owner);
    Obj4480(S004* owner)
    {
        FUN_004f4480(owner);
    }
};
struct S004
{
    Obj4480* CreateObj4480();
};
// Allocates a new Obj4480 instance with this S004 as owner and returns the pointer.
// @fnv 0x004f4c70
Obj4480* S004::CreateObj4480()
{
    Obj4480* result = new Obj4480(this);
    return result;
}

struct FUN_004f4f90_node : BSSimpleList<unsigned int>
{
    void FUN_005ae3d0(unsigned int* out);
};

struct FUN_004f4f90_shell : TESRegionDataSound
{
    int FUN_004f4f90();
};

// @fnv 0x004f4f90
int FUN_004f4f90_shell::FUN_004f4f90()
{
    unsigned int found;
    FUN_004f4f90_node* node7 = (FUN_004f4f90_node*)&Battle;
    found = 0;
    if (node7 != 0 && *((unsigned int *)(new ((void *)(node7)) ::Vec3())) != 0)
    {
        while (node7 != 0 && *((unsigned int *)(new ((void *)(node7)) ::Vec3())) != 0)
        {
            if (((int)(::GetRandomNumberInRange(0, 3))) == 0 || found == 0)
            {
                found = *((unsigned int *)(new ((void *)(node7)) ::Vec3()));
            }
            node7 = ((::FUN_004f4f90_node *)(reinterpret_cast<::Callees *>((node7))->FUN_00726070()));
        }
    }
    else
    {
        return 0;
    }
    if (found != 0)
    {
        reinterpret_cast<::ItemChangeListNode *>((((FUN_004f4f90_node*)&Battle)))->FUN_00905330((*(::InventoryStackRecord *const *)(&found)));
        ((FUN_004f4f90_node*)&Battle)->FUN_005ae3d0(&found);
        return ((int)(::FUN_004839c0(found)));
    }
    return 0;
}
