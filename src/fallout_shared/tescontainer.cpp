// fallout_shared/tescontainer.cpp: TESContainer, InventoryItemEntry, DelStandIn, ContainerOperation and more (31 functions)

#include <new>
#include <cstdlib>
#include <cstring>
#include "fnv/decl/ActorBaseTarget.h"
#include "fnv/decl/AddInventory.h"
#include "fnv/decl/AmmoOwner.h"
#include "fnv/decl/B81390ContainerObject.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/ChallengeManager.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/CombatState.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0040eb90_shell.h"
#include "fnv/decl/FUN_00418800_shell.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_00419ad0_shell.h"
#include "fnv/decl/FUN_00419ed0_shell.h"
#include "fnv/decl/FUN_00419f80_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00452e90_Class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00487620.h"
#include "fnv/decl/FUN_00487980_shell.h"
#include "fnv/decl/FUN_00488350_shell.h"
#include "fnv/decl/FUN_005a8080.h"
#include "fnv/decl/FUN_005abf60_shell.h"
#include "fnv/decl/FUN_005ac1e0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_0088d7d0_shell.h"
#include "fnv/decl/FUN_008a1710_shell.h"
#include "fnv/decl/Fn40ea20.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/Owner.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/PickupSoundActorView.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESBipedModelForm.h"
#include "fnv/decl/TESWeightForm.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0041d280__FUN_0041d280_shell.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00574fa0__AddBoundItemRef.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00482000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004c0000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0101c000.h"
#include "fnv/symbols_01030000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "tescontainer_decls.h"
#include "BaseFormComponent.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_0040e7f0_owner.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_005b5000.h"

class ContainerItemExtra
{
  public:
    void* m_pForm;
    union
    {
        void* m_pGlobal;
        int m_cRank;
        unsigned int bits;
    };
    float m_fHealth;
    ContainerItemExtra();
    void Copy(ContainerItemExtra* other);
    bool IsDefault();
public:
    bool Compare(::ContainerItemExtra *);
};

struct InventoryItemEntry
{
  public:
    int count;
    void* object;
    ContainerItemExtra* extra;
    void Copy(InventoryItemEntry* other);
    void InitItem(TESForm* form);
};

struct ContainerCountState
{
    int count;
    BSSimpleList<InventoryStackRecord*>* list;
};

class TESContainer;

struct CopyComponentState
{
    BSSimpleList<InventoryStackRecord*>* list;
    TESContainer* source;
};

// Copies object, count and, when the source extra is non-default, allocates a new ContainerItemExtra and copies it.
// @fnv 0x00481540
void InventoryItemEntry::Copy(InventoryItemEntry* other)
{
    if (other)
    {
        object = other->object;
        count = other->count;
        if (other->extra && !other->extra->IsDefault())
        {
            extra = new ContainerItemExtra();
            extra->Copy(other->extra);
        }
    }
}

class TESContainer : public BaseFormComponent
{
  public:
    BSSimpleList<InventoryStackRecord*> objectList;
    virtual void Init();
    void ClearObjects();
    void InitItem(TESForm* form);
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    ~TESContainer();
    bool HasObjectOfType(TESObject* object);
    int GetObjectCount(TESObject* object);
    static bool IsValidContainerType(unsigned char type);
    TESContainer();
};

// @fnv 0x004816e0
void TESContainer::Free()
{
    ClearObjects();
}

// @fnv 0x00481680
TESContainer::~TESContainer()
{
    Free();
}

// Searches the container's object list for an entry whose object pointer equals object and returns whether one is found.
// @fnv 0x00481eb0
bool TESContainer::HasObjectOfType(TESObject* object)
{
    BSSimpleList<InventoryStackRecord*>* list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    if ((list->m_item) == 0)
        list = 0;
    while (list != 0)
    {
        InventoryItemEntry* item = reinterpret_cast<InventoryItemEntry*>((list->m_item));
        if (item->object == object)
            return true;
        list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
    }
    return false;
}

// Counts how many items in the container's object list match the given object, summing their counts.
// @fnv 0x00482a90
int TESContainer::GetObjectCount(TESObject* object)
{
    ContainerCountState state;
    state.count = 0;
    state.list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    while (state.list != 0 && (state.list->m_item) != 0)
    {
        if (reinterpret_cast<InventoryItemEntry*>((state.list->m_item))->object == object)
            state.count += reinterpret_cast<InventoryItemEntry*>((state.list->m_item))->count;
        state.list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((state.list))->FUN_00726070()));
    }
    return state.count;
}

// @fnv 0x00481f30
bool TESContainer::IsValidContainerType(unsigned char type)
{
    switch (type)
    {
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x28:
    case 0x29:
    case 0x2e:
    case 0x2f:
    case 0x31:
    case 0x32:
    case 0x34:
    case 0x67:
    case 0x6c:
    case 0x73:
    case 0x74:
        return true;
    default:
        return false;
    }
}

// @fnv 0x00481700
void TESContainer::ClearObjects()
{
    BSSimpleList<InventoryStackRecord*>* list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    InventoryItemEntry* item;
    while ((item = reinterpret_cast<InventoryItemEntry*>((list->m_item))) != 0)
    {
        InventoryItemEntry* deletion = item;
        InventoryItemEntry* temporary = deletion;
        temporary ? reinterpret_cast<BGSPerkEntry*>(temporary)->Destroy(1) : 0;
        list->RemoveHead();
    }
}
// Initializes each entry in the object list with form, removing and deleting entries whose object becomes null.
// @fnv 0x00481bb0
void TESContainer::InitItem(TESForm* form)
{
    BSSimpleList<InventoryStackRecord*>* list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    BSSimpleList<InventoryStackRecord*>* previous = 0;
    while (list != 0 && !list->IsEmpty())
    {
        InventoryItemEntry* item = reinterpret_cast<InventoryItemEntry*>((list->m_item));
        reinterpret_cast<::B81390ContainerObject *>((item))->FUN_00481390(form);
        if (item->object == 0)
        {
            if (previous != 0)
            {
                reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330(reinterpret_cast<InventoryStackRecord* const&>(item));
                list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
            }
            else
            {
                list->RemoveHead();
            }
            InventoryItemEntry* deletion = item;
            InventoryItemEntry* temporary = deletion;
            temporary ? reinterpret_cast<BGSPerkEntry*>(temporary)->Destroy(1) : 0;
            item = 0;
        }
        else
        {
            previous = list;
            list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((list))->FUN_00726070()));
        }
    }
}

struct ContainerObjectNew : InventoryItemEntry
{
    ContainerObjectNew();
};

struct FUN_00481a90_shell : TESContainer
{
    void AddContainerCopy(InventoryItemEntry* object);
};
// Copies the object list from the source TESContainer component into this container, adding each item.
// @fnv 0x00481c80
void TESContainer::CopyFromBase(BaseFormComponent* component)
{
    CopyComponentState state;
    state.source = dynamic_cast<TESContainer*>(component);
    if (state.source == 0)
        return;
    ClearObjects();
    state.list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>((state.source))->GetCurrentProcessData()));
    while (state.list != 0 && !state.list->IsEmpty())
    {
        InventoryItemEntry* item = reinterpret_cast<InventoryItemEntry*>((state.list->m_item));
        reinterpret_cast<::FUN_00481a90_shell *>(this)->AddContainerCopy(item);
        state.list = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((state.list))->FUN_00726070()));
    }
}

// If object is non-null, allocates a ContainerObjectNew, copies object into it, and adds it to the head of the object list.
// @fnv 0x00481a90
void FUN_00481a90_shell::AddContainerCopy(InventoryItemEntry* object)
{
    if (!object)
        return;
    InventoryItemEntry* newObj = new ContainerObjectNew;
    newObj->Copy(object);
    ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()))->AddHead((InventoryStackRecord*&)newObj);
}

struct FUN_00481fd0_shell : public TESContainer
{
    void AddAllFromContainer(TESContainer*);
};


struct TeleportableReference
{
    int& GetPosition();
};

class TESContainer_Add : public TESContainer
{
  public:
    void AddObject(TESForm* form, int count, ContainerItemExtra* extra);
};

// Iterates the object list of apAddCont and adds each entry's object, count and extra to this container.
// @fnv 0x00481fd0
void FUN_00481fd0_shell::AddAllFromContainer(TESContainer* apAddCont)
{
    if (apAddCont)
    {
        void* pListEntry = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>((apAddCont))->GetCurrentProcessData()));
        while (pListEntry)
        {
            InventoryItemEntry* pcont = *((::InventoryItemEntry **)((void *)(pListEntry)));
            if (pcont)
            {
                reinterpret_cast<TESContainer_Add*>(this)->AddObject(static_cast<TESForm*>(pcont->object), pcont->count,
                                                                     pcont->extra);
            }
            pListEntry = reinterpret_cast<::Callees *>((pListEntry))->FUN_00726070();
        }
    }
}

struct FUN_00482040_shell : public TESContainer
{
    void ScaleEntryCounts(int);
};


// Walks the object list and multiplies each contained entry's count by aiMult.
// @fnv 0x00482040
void FUN_00482040_shell::ScaleEntryCounts(int aiMult)
{
    void* pCurrentElementNext = (void*)((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    while (pCurrentElementNext)
    {
        InventoryItemEntry* pcont = *((::InventoryItemEntry **)((void *)(pCurrentElementNext)));
        if (pcont)
        {
            pcont->count *= aiMult;
        }
        pCurrentElementNext = reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070();
    }
}

namespace fnv_00482090 {
struct FUN_00482090_shell : public TESContainer
{
    void FUN_00482090(float);
};

struct NiPoint3;
struct TeleportableReference
{
  public:
    NiPoint3 const& GetPosition(void);
};
bool _ref_008256d0(void* pThis);

struct ContainerItemExtra_helper
{
};

// Walks the container's item list, creating each item's extra data if missing, applies afHealthPerc to it, and deletes extras that become default.
// @fnv 0x00482090
void FUN_00482090_shell::FUN_00482090(float afHealthPerc)
{
    void* pCurrentElementNext = (void*)&(*(const ::fnv_00482090::NiPoint3 *)(reinterpret_cast<::BaseProcess *>((((TeleportableReference*)this)))->GetCurrentProcessData()));
    while (pCurrentElementNext && !_ref_008256d0(pCurrentElementNext))
    {
        InventoryItemEntry* pcont = *((::InventoryItemEntry **)((void *)(pCurrentElementNext)));
        if (!pcont->extra)
            pcont->extra = new ContainerItemExtra;
        reinterpret_cast<::FUN_0040eb90_shell *>((((ContainerItemExtra_helper*)pcont->extra)))->FUN_0040eb90(afHealthPerc);
        if (pcont->extra->IsDefault())
        {
            delete pcont->extra;
            pcont->extra = 0;
        }
        pCurrentElementNext = reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070();
    }
}
}  // namespace fnv_00482090

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct LeveledObject;
class NiAVObject;
struct NiColor;
struct NiPoint3;
class TESActorBase;
class TESBoundObject;
class TESForm;
struct TESGlobal;
class TESModel;
class TESModelTextureSwap;
class TESObject;
struct TESFormList;
class TESObjectREFR;
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
class TESLeveledList : public BaseFormComponent
{
  public:
    virtual unsigned char GetChanceNone();
    virtual bool UsesAllEntries();
    virtual int GetMaxLevelDifference();
    virtual void ErrorCheckList();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void SetChanceNone(unsigned char);
    bool GetCalcAllBelow();
    void SetCalcAllBelow(bool);
    void SetMultCalc(bool);
    bool GetUseAll();
    void SetUseAll(bool);
    TESGlobal* GetChanceGlobal();
    void SetChanceGlobal(TESGlobal*);
    void InitializeLeveledList();
    void SortLeveledList();
    LeveledObject* CreateLeveledObject(unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void DeleteLeveledObject(LeveledObject*);
    void SelectLeveledObject(unsigned short, TESForm**, unsigned short*, ContainerItemExtra**, bool, int);
    void PopulateContainerWithLeveledItems(unsigned short, unsigned short, TESContainer*, int);
    void AddScriptAddedLeveledObject(TESForm*, unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    void Revert(BGSLoadFormBuffer*);
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static TESLeveledList* GetFormAsLeveledList(TESForm*);
    void* GetLeveledList();
    void* __vecDelDtor(unsigned int);
    char leveledList[8];
    unsigned char m_pChanceGlobal;
    unsigned char m_ucChanceNone;
    char _pad_e[2];
    TESGlobal* m_pLevelGlobal;
    char m_kLeveledObjects[8];
};

int FNV_GetFormType(TESForm*);

struct TESLevPad
{
    virtual void Dummy();
    char pad[0x2C];
};

struct TESLevFormStub : public TESLevPad, public TESLeveledList
{
};

// Returns apForm cast to TESLeveledList when its form type is 0x34, 0x2C, 0x2D or 0x4C, otherwise null.
// @fnv 0x00487be0
TESLeveledList* __cdecl FUN_00487be0(TESForm* apForm)
{
    TESLeveledList* pLeveledList = 0;
    if (apForm)
    {
        switch (FNV_GetFormType(apForm))
        {
        case 0x34: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        case 0x2C: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        case 0x2D: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        case 0x4C: {
            TESLevFormStub* pLevStub = (TESLevFormStub*)apForm;
            pLeveledList = pLevStub;
            break;
        }
        }
    }
    return pLeveledList;
}

namespace p07 {
struct DtorStandIn
{
};
struct DelStandIn
{
    void* Destroy_00481760(unsigned int flags);
};
// Runs the destructor on this object, frees it with Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00481760
void* DelStandIn::Destroy_00481760(unsigned int flags)
{
    reinterpret_cast<::FUN_00487620 *>((((DtorStandIn*)this)))->FUN_00487620::~FUN_00487620();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

namespace fnv_004817f0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
class NiAVObject;
struct NiColor;
struct NiPoint3;
class TESBoundObject;
class TESForm;
class TESObject;
struct TESFormList;
class TESObjectREFR;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct FUN_004817f0_shell : public TESContainer
{
    InventoryItemEntry* AddContainerObject(ContainerChanges*);
};

struct ContainerObjectNew : public InventoryItemEntry
{
    ContainerObjectNew();
};
// If apObj is non-null, allocates a ContainerObjectNew copying its object and count, adds it to the head of the object list, and returns it.
// @fnv 0x004817f0
InventoryItemEntry* FUN_004817f0_shell::AddContainerObject(ContainerChanges* apObj)
{
    if (!apObj)
        return 0;
    InventoryItemEntry* pcobj;
    BSSimpleList<InventoryStackRecord*>* pList = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    pcobj = new ContainerObjectNew;
    pcobj->object = *(void**)apObj;
    pcobj->count = ((int*)apObj)[1];
    ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()))->AddHead(reinterpret_cast<InventoryStackRecord*&>(pcobj));
    return pcobj;
}
}  // namespace fnv_004817f0

struct CompareHelper
{
};

struct FUN_00481470_shell
{
    int count;
    void* object;
    ContainerItemExtra* extra;
    bool IsNotEqual(InventoryItemEntry* apCompare);
};

// Returns true when apCompare is null or its count, object or extra differ from this shell's, comparing extras via CompareHelper::Compare.
// @fnv 0x00481470
bool FUN_00481470_shell::IsNotEqual(InventoryItemEntry* apCompare)
{
    if (!apCompare)
        return true;
    if (count != apCompare->count)
        return true;
    if (object != apCompare->object)
        return true;
    if (extra && !extra->IsDefault() && !apCompare->extra)
        return true;
    if (!extra && apCompare->extra && !apCompare->extra->IsDefault())
        return true;
    if (extra && apCompare->extra && reinterpret_cast<::ContainerItemExtra *>((((CompareHelper*)extra)))->Compare(apCompare->extra))
        return true;
    return false;
}

struct FUN_0084e3a0_shell
{
};

// @fnv 0x00481f10
bool __cdecl FUN_00481f10(TESObject* pObj)
{
    if (pObj && reinterpret_cast<::FUN_0084e3a0_Class *>((((FUN_0084e3a0_shell*)pObj)))->FUN_0084e3a0() == 0xF)
        return true;
    return false;
}

namespace fnv_004818e0 {
namespace N {
class BSSimpleList
{
  public:
    bool _ref_008256d0();
};
class ContainerItemExtra
{
};
}
struct TgtOps
{
    void* GetPosition();
};
struct G2
{
    void AddHead(int*);
};
struct ContainerObjectNew
{
    int a, b, c;
    ContainerObjectNew();
};
struct FUN_004818e0_t : public TESContainer
{
    InventoryItemEntry* FUN_004818e0(TESObject* apObj, int aiCount, ContainerItemExtra* apExtra);
};
// Finds a container entry matching apObj and apExtra, adds aiCount to its count, or creates a new entry and prepends it to the list.
// @fnv 0x004818e0
InventoryItemEntry* FUN_004818e0_t::FUN_004818e0(TESObject* apObj, int aiCount, ContainerItemExtra* apExtra)
{
    if (!apObj || !aiCount)
        return 0;
    N::BSSimpleList* pCurrentElementNext;
    InventoryItemEntry* pcobj;
    pcobj = 0;
    pCurrentElementNext = (N::BSSimpleList*)((void *)(reinterpret_cast<::BaseProcess *>((((TgtOps*)this)))->GetCurrentProcessData()));
    while (pCurrentElementNext && !pCurrentElementNext->_ref_008256d0())
    {
        pcobj = *((::InventoryItemEntry **)((void *)(pCurrentElementNext)));
        if (pcobj->object == apObj)
        {
            if (pcobj->extra)
            {
                if (apExtra && !reinterpret_cast<::ContainerItemExtra *>((((N::ContainerItemExtra*)pcobj->extra)))->Compare(apExtra))
                    break;
            }
            else if (!apExtra)
                break;
        }
        pcobj = 0;
        pCurrentElementNext = ((::fnv_004818e0::N::BSSimpleList *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
    }
    if (pcobj)
    {
        pcobj->count += aiCount;
    }
    else
    {
        pcobj = (InventoryItemEntry*)new ContainerObjectNew;
        pcobj->count = aiCount;
        pcobj->object = apObj;
        if (apExtra)
        {
            pcobj->extra = new ContainerItemExtra;
            pcobj->extra->Copy(apExtra);
        }
        ((G2*)((void *)(reinterpret_cast<::BaseProcess *>((((TgtOps*)this)))->GetCurrentProcessData())))->AddHead((int*)&pcobj);
    }
    return pcobj;
}
}  // namespace fnv_004818e0

namespace fnv_00482770 {
class Actor;
struct ActorCause;
struct ActorPackageData;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
class BGSAcousticSpace;
class BGSEncounterZone;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSMusicType;
class BGSPrimitive;
struct BGSSaveFormBuffer;
struct BGSTalkingActivator;
class BSExtraData;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BSOcclusionPlane;
struct BSPortal;
struct SoundPlaybackHandle;
class BaseExtraList;
struct BipedAnim;
struct CellMopp;
struct CollisionData;
struct Crime;
struct TeleportableReference;
struct ExtraAction;
struct ExtraActorCause;
class ExtraAmmo;
struct ExtraAnim;
struct ExtraAshPileReference;
struct ExtraAudioBuoyMarker;
struct ExtraAudioMarker;
struct ExtraCannotWearData;
class ExtraDataList;
class ExtraDismemberedLimbs;
class ExtraFactionChanges;
class ExtraFollower;
struct ExtraFollowerSwimBreadcrumbs;
class ExtraLeveledItem;
struct ExtraLight;
struct ExtraLock;
struct ExtraMapMarker;
struct ExtraNavMeshPortal;
class ExtraRefractionProperty;
struct ExtraSayToTopicInfo;
struct ExtraSayTopicInfoOnceADay;
struct ExtraStartingPosition;
struct ExtraTalkingActor;
struct ExtraTeleport;
struct PositionRotation;
struct ImpactSwap;
struct InventoryIterator;
class InventoryStackRecord;
class MapMarkerData;
struct MenuTopic;
class Point3Offset;
class NiNode;
struct NiPoint3;
struct NiRenderedTexture;
struct IndexedPointerCollection;
struct PatrolReferenceData;
struct PatrolRefData;
struct LinkedReferencePair;
struct RadioReferenceData;
struct ReferenceLightData;
class LockExtraData;
struct ReferenceFloatEntry;
class RagDollData;
struct PointerFlagNode;
struct TopicInfoVisitRecord;
class Script;
struct ScriptLocals;
struct SeenData;
class TESActorBase;
struct TESAmmo;
class TESBoundObject;
struct TESClimate;
struct TESCombatStyle;
struct TESFaction;
class TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESLevItem;
class TESModel;
class TESNPC;
class TESObject;
class TESObjectCELL;
class TESObjectLAND;
class TESObjectREFR;
class TESObjectWEAP;
class TESPackage;
class TESRegionList;
class TESTopic;
class TESTopicInfo;
struct TESWaterForm;
class TESWorldSpace;
struct TrespassPackage;
struct WorldLocation;
struct WaterZone;
struct _D3DLOCKED_RECT;
struct bhkWorld;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct InventoryChanges
{
    void ForceWeightRecalculation();
    static void KillTempRef();
    void AddItemToEntry(TESBoundObject*, int, Actor*, ExtraDataList*, InventoryStackRecord*);
    bool IsEmpty();
    void AddItem(TESBoundObject*, ExtraDataList*, int);
    void AddItem(TESObjectREFR*, int, bool, bool);
    void AddChangeEntry(InventoryStackRecord*, bool);
    void RemoveChangeItem(TESBoundObject*);
    TESObjectREFR* RemoveItem(TESObjectREFR*, TESBoundObject*, bool, int, ExtraDataList*, bool, TESObjectREFR*, void*,
                              void*, bool, bool, InventoryStackRecord*);
    void UpdateItemCount(int, bool, int);
    TESObjectREFR* DropItem(TESObjectREFR*, TESBoundObject*, int, TESObjectREFR*, void*, void*);
    void PutItemIntoContainer(TESBoundObject*, int, TESObjectREFR*, ExtraDataList*);
    void DamageItem(TESBoundObject*, float);
    void RepairBatch(TESBoundObject*, float);
    void AddOwnership(TESBoundObject*, TESForm*);
    void RemoveOwnership(TESBoundObject*);
    TESContainer* GetOriginalContainer();
    void RemoveBoundItem(TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool);
    bool RemoveInventoryItem(bool*, TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool, InventoryStackRecord*, bool*);
    void ResetInventoryChanges();
    bool RunScripts(TESObjectREFR*);
    void ResetInventoryState();
    void CleanUpBoundItems(Actor*);
    TESBoundObject* GetLeveledCalculatedBaseObject(TESLevItem*);
    void ModifyCharge(float);
    InventoryStackRecord* GetOrCreateInventoryEntry(TESBoundObject*, bool, unsigned int);
    static InventoryChanges* CreateForReference(TESObjectREFR*);
    ExtraDataList* GetExtraDataListForObject(TESBoundObject*, bool);
    bool WearingWeapon(TESBoundObject**);
    bool WearingAmmo(TESBoundObject**);
    bool WearingTorch(TESBoundObject**);
    InventoryStackRecord* WearingRing(bool);
    bool WearingVoiceModulateItem();
    bool HasItemOfType(unsigned int);
    bool FindItemInInventory(TESBoundObject*, int, int, int*, unsigned int, TESObjectREFR*);
    bool HasQuestObject();
    bool HasScript();
    TESBoundObject* GetObjectAtIndex(int, int*);
    TESBoundObject* GetBoundObjectByIndex(int, int*);
    InventoryStackRecord* GetPotion(void*);
    InventoryStackRecord* GetBestAmmoForActor(TESActorBase*, bool);
    TESAmmo* GetBestAmmoForWeapon(TESObjectWEAP*, bool*);
    InventoryStackRecord* GetBestWeapon(TESActorBase*, float*, int, bool);
    InventoryStackRecord* FindBestArmor(TESActorBase*, int, bool);
    void* GetListBestArmor(TESActorBase*);
    InventoryStackRecord* GetBestClothing(TESActorBase*, int, bool);
    InventoryStackRecord* GetBestLight(TESActorBase*, bool);
    InventoryStackRecord* GetInventoryEntryData(int, bool);
    InventoryStackRecord* GetEquippedItemForSlot(int);
    InventoryStackRecord** GetEntryPointerByIndices(int, int);
    void SetHotKeyItem(InventoryStackRecord*, ExtraDataList*, int);
    void SetInventoryEntryCount(InventoryStackRecord*, int);
    void RemoveAllObjectsWorn(bool, TESObjectREFR*);
    bool RechargeAll();
    void RemoveAllHealth();
    int GetCount(bool);
    InventoryStackRecord* GetInventoryEntryAtIndex(int);
    IndexedPointerCollection* GetFirstItem();
    InventoryStackRecord* GetEntryForListNode(IndexedPointerCollection*);
    void RemoveItemChangeEntry(TESBoundObject*, void*);
    void RefreshItemChange(TESBoundObject*, void*);
    void UpdateItemChangeEntry(TESBoundObject*, void*);
    int GetObjectCount(int);
    int GetObjectCount(TESBoundObject*);
    InventoryStackRecord* GetFirstInventoryEntry();
    int GetInventoryEntryCount();
    void TransferItemToReference(TESObjectREFR*, int, TESObjectREFR*);
    float RemoveAllTypedItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    float RemoveAllItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    void DuplicateAllItems(TESObjectREFR*, TESObjectREFR*);
    void MoveItemsOfType(TESObjectREFR*, TESObjectREFR*, TESForm*);
    void RemoveNonStolenItems(TESObjectREFR*, TESObjectREFR*);
    float GetInventoryWeight(bool);
    unsigned int GetTotalItemCount(bool, bool);
    void AddAmountToItemChange(TESBoundObject*, int);
    float GetArmorValueForActor(Actor*);
    void UpdateArmorWeight();
    void UpdateWeight();
    void RemoveDefaultLeveledItems();
    bool IsLevelItemInited(int);
    InventoryStackRecord* FindEntryForObject(TESBoundObject*, unsigned int);
    void SetItemsBacktoDefaultState();
    void CopyInventoryChanges(InventoryChanges*, TESObjectREFR*, bool);
    void ResetEntryList();
    void ResetCachedWeights();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    int GetExtraDataListIndexForItem(TESBoundObject*, ExtraDataList*);
    ExtraDataList* GetExtraDataListFromIndexForItem(TESBoundObject*, int);
    unsigned int FindItemEntryData(int*, void*, unsigned int);
    bool GetNextItem(InventoryIterator*, InventoryStackRecord**, unsigned int);
    TESObjectREFR* GetRef();
    static TESObjectREFR* GetTempRef();
    void RemoveExtraFromObject(TESObject*, ExtraDataList*);
    void DeleteExtraData(TESBoundObject*, ExtraDataList*);
    void* __vecDelDtor(unsigned int);
    void* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    char _pad_11[3];
};
struct FUN_00482770_shell : public TESContainer
{
    void AddLeveledItemsToChanges(int, InventoryChanges*);
};

class ExtraDataList
{
  public:
    char pad[0x20];
    ExtraDataList();
};
struct FUN_00419ad0_shell
{
};
struct TESHealthForm
{
};
struct Fn40ea20
{
};
class TESForm
{
  public:
    void SetFormFlags(int);
};
struct FUN_004c29a0_t
{
};
struct PatrolActorPackageData
{
};
struct BGSSaveLoadGame
{
};
struct GridArray
{
};
struct TgtOps
{
    void* GetPosition();
};

// @fnv 0x00482770
void FUN_00482770_shell::AddLeveledItemsToChanges(int aiLevItemIndex, InventoryChanges* apChanges)
{
    bool bhadChanges = false;
    if (apChanges)
    {
        ::BSSimpleList< ::InventoryStackRecord *>* pCurrentElementNext = (::BSSimpleList< ::InventoryStackRecord *>*)((void *)(reinterpret_cast<::BaseProcess *>((((TgtOps*)this)))->GetCurrentProcessData()));
        while (pCurrentElementNext && !pCurrentElementNext->IsEmpty())
        {
            InventoryItemEntry* pcont = *((::InventoryItemEntry **)((void *)(pCurrentElementNext)));
            if (pcont)
            {
                bhadChanges = true;
                ExtraDataList* pextra = new ExtraDataList();
                reinterpret_cast<::fnv_0041d280::FUN_0041d280_shell *>((pextra))->SetLeveledItemIndex(aiLevItemIndex);
                reinterpret_cast<::FUN_00419ad0_shell *>((((FUN_00419ad0_shell*)pextra)))->FUN_00419ad0(pcont->count);
                if (pcont->extra)
                    reinterpret_cast<::Fn40ea20 *>((((Fn40ea20*)pcont->extra)))->FUN_0040ea20((::ExtraL *)(pextra), (::HealthForm *)(::fnv_00482770::TESHealthForm *)(((::fnv_00482770::TESHealthForm *)(::GetHealthForm((::TESForm *)(::fnv_00482770::TESForm *)((TESForm*)pcont->object))))));
                reinterpret_cast<::AddInventory *>((((FUN_004c29a0_t*)apChanges)))->FUN_004c29a0((::AddForm *)(pcont->object), (::AddExtra *)(pextra), pcont->count);
            }
            pCurrentElementNext = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((pCurrentElementNext))->FUN_00726070()));
        }
        if (bhadChanges && ((::fnv_00482770::TESForm *)(reinterpret_cast<::Callees *>((((GridArray*)apChanges)))->FUN_00726070())) && reinterpret_cast<::PatrolActorPackageData *>(((*reinterpret_cast<::fnv_00482770::PatrolActorPackageData * *>(&::g_osGlobals))))->IsPatrolling())
        {
            if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_00482770::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10() || reinterpret_cast<::FUN_00452e90_Class *>(((*reinterpret_cast<::fnv_00482770::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->IsFlag20Set())
                ((::fnv_00482770::TESForm *)(reinterpret_cast<::Callees *>((((GridArray*)apChanges)))->FUN_00726070()))->SetFormFlags(0x8000000);
        }
    }
}
}  // namespace fnv_00482770

struct RefH
{
};
struct ItemNode
{
    int pad;
    RefH* ref;
};
struct FUN_00481310_shell
{
    void FUN_00481310();
};
struct TgtOps
{
    void* GetPosition();
};
struct FUN_00481b40_shell
{
    void FUN_00481b40();
};
// Iterates the list returned by GetPosition and calls FUN_00481310 on each item whose ref is not deleted.
// @fnv 0x00481b40
void FUN_00481b40_shell::FUN_00481b40()
{
    BSSimpleList<ItemNode*>* node = (BSSimpleList<ItemNode*>*)((void *)(reinterpret_cast<::BaseProcess *>((((TgtOps*)this)))->GetCurrentProcessData()));
    if (!(node->m_item))
        node = 0;
    while (node)
    {
        ItemNode* item = (node->m_item);
        if (!reinterpret_cast<::FUN_00440d80_shell *>((void *)(item->ref))->FUN_00440d80())
            ((FUN_00481310_shell*)item)->FUN_00481310();
        node = (BSSimpleList<ItemNode*>*)((::BSSimpleList< ::ItemNode *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
    }
}

struct ObjectReference
{
};
struct ContainerNode
{
};
struct FUN_00481e10_shell
{
    float FUN_00481e10(unsigned char);
};
// @fnv 0x00481e10
float FUN_00481e10_shell::FUN_00481e10(unsigned char flag)
{
    ContainerNode* node;
    float sum = 0.0f;
    node = ((::ContainerNode *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    if (*((::InventoryItemEntry **)((void *)(node))) == 0)
        node = 0;
    while (node != 0)
    {
        InventoryItemEntry* entry = *((::InventoryItemEntry **)((void *)(node)));
        node = ((::ContainerNode *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        if (reinterpret_cast<::FUN_00440d80_shell *>((reinterpret_cast<ObjectReference*>(entry->object)))->FUN_00440d80())
            continue;
        sum = static_cast<float>((double)std::abs(entry->count) * ((double)(::TESWeightForm::GetWeightForForm((::TESForm *)(entry->object), flag))) + sum);
    }
    return sum;
}

struct ScriptLocals;
class Script;
class ExtraDataList;
class TESForm
{
  public:
    unsigned FUN_00401170();
public:
    void ClearData();
public:
    void NotifySaveLoadGameOfFormChange();
};
// Constructs a TESContainer, initializing its objectList and calling Init().
// @fnv 0x00481610
TESContainer::TESContainer() : objectList()
{
    Init();
}
class TESObjectREFR
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03();
    virtual ~TESObjectREFR();
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    TESObjectREFR();
};
class Actor : public TESObjectREFR
{
  public:
    virtual void Unk05();
    virtual void Unk06();
    virtual void Unk07();
    virtual void Unk08();
    virtual void Unk09();
    virtual void Unk0a();
    virtual void Unk0b();
    virtual void Unk0c();
    virtual void Unk0d();
    virtual void Unk0e();
    virtual void Unk0f();
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
    virtual void Unk1a();
    virtual void Unk1b();
    virtual void Unk1c();
    virtual void Unk1d();
    virtual void Unk1e();
    virtual void Unk1f();
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
    virtual void Unk2a();
    virtual void Unk2b();
    virtual void Unk2c();
    virtual void Unk2d();
    virtual void Unk2e();
    virtual void Unk2f();
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
    virtual void Unk3a();
    virtual void Unk3b();
    virtual void Unk3c();
    virtual void Unk3d();
    virtual void Unk3e();
    virtual void Unk3f();
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
    virtual void Unk4a();
    virtual void Unk4b();
    virtual void Unk4c();
    virtual void Unk4d();
    virtual void Unk4e();
    virtual void Unk4f();
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
    virtual void Unk5a();
    virtual void Unk5b();
    virtual void Unk5c();
    virtual void Unk5d();
    virtual void Unk5e();
    virtual void Unk5f();
    virtual void Unk60();
    virtual void Unk61();
    virtual void Unk62();
    virtual void Unk63();
    virtual void AddItem(TESForm*, ExtraDataList*, int);
};
class ExtraDataList
{
  public:
    unsigned unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    ExtraDataList();
};
class Script
{
  public:
};
struct ItemExtra
{
};
struct Item
{
    int count;
    TESForm* form;
    ItemExtra* extra;
};
struct Node
{
};
struct SettingString
{
    const char* FUN_00403df0();
};
struct ContainerOperation
{
    void FUN_004821a0(TESObjectREFR*, bool);
};
// @fnv 0x004821a0
void ContainerOperation::FUN_004821a0(TESObjectREFR* target, bool silent)
{
    if (target)
    {
        Actor* last = dynamic_cast<Actor*>(target);
        Item* actor = 0;
        Node* node = ((::Node *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
        while (node)
        {
            Item* item = *((::Item **)((void *)(node)));
            if (item)
            {
                Script* script = ((::Script *)(::fnv_004826d0::FUN_004826d0((::fnv_004826d0::TESForm *)(item->form))));
                int count = item->count;
                actor = item;
                if (script)
                {
                    for (int index = 0; index < count; ++index)
                    {
                        ExtraDataList* extra = 0;
                        extra = new ExtraDataList;
                        reinterpret_cast<::FUN_00419ad0_shell *>((extra))->FUN_00419ad0(1);
                        if (extra && !reinterpret_cast<::FUN_00418800_shell *>((extra))->FUN_00418800())
                        {
                            reinterpret_cast<::FUN_00419ed0_shell *>((extra))->FUN_00419ed0(script);
                            reinterpret_cast<::FUN_00419f80_shell *>((extra))->FUN_00419f80(reinterpret_cast<::FUN_005abf60_shell *>((script))->FUN_005abf60());
                            TESObjectREFR* ref = new TESObjectREFR;
                            reinterpret_cast<::TESForm *>((ref))->NotifySaveLoadGameOfFormChange();
                            reinterpret_cast<::FUN_005ac1e0_shell *>((script))->FUN_005ac1e0(ref, reinterpret_cast<::FUN_00418830_shell *>((extra))->FUN_00418830(), 0, false);
                            delete ref;
                            if (item->extra)
                                reinterpret_cast<::Fn40ea20 *>((item->extra))->FUN_0040ea20((::ExtraL *)(extra), (::HealthForm *)(void *)(((void *)(::GetHealthForm(item->form)))));
                        }
                        if (last)
                            last->AddItem(item->form, extra, 1);
                        else
                            reinterpret_cast<::fnv_00574fa0::AddBoundItemRef *>((target))->FUN_00574fa0((::TESBoundObject *)(item->form), extra, 1);
                    }
                }
                else
                {
                    ExtraDataList* data = 0;
                    if (item->extra)
                    {
                        data = new ExtraDataList;
                        reinterpret_cast<::FUN_00419ad0_shell *>((data))->FUN_00419ad0((unsigned short)item->count);
                        reinterpret_cast<::Fn40ea20 *>((item->extra))->FUN_0040ea20((::ExtraL *)(data), (::HealthForm *)(void *)(((void *)(::GetHealthForm(item->form)))));
                    }
                    if (last)
                        last->AddItem(item->form, data, item->count);
                    else
                        reinterpret_cast<::fnv_00574fa0::AddBoundItemRef *>((target))->FUN_00574fa0((::TESBoundObject *)(item->form), data, item->count);
                }
            }
            node = ((::Node *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
        }
        if (last == (*reinterpret_cast<::Actor * *>(&::_g_thePlayer)) && actor && !silent)
        {
            BSStringT<char> text;
            if (actor->count > 1)
                ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&text), "%i %s%s %s", actor->count, ::FUN_00482720(actor->form), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d3114))))->GetMenuTitle())),
                             ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d4e7c))))->GetMenuTitle())));
            else
                ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&text), "%s %s", ::FUN_00482720(actor->form), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d4e7c))))->GetMenuTitle())));
            switch (actor->form->FUN_00401170())
            {
            case 25:
            case 30:
            case 31:
            case 40:
            case 41:
            case 46:
            case 47:
            case 50:
            case 103:
            case 108:
            case 115:
            case 116:
                ::DispatchMessageToSink((const char *)(((const char *)(::FUN_00559450((int *)&(text))))), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_giftbox.dds"),
                               (const char *)(silent ? 0 : reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_008adcf0((::TESBoundObject *)(actor->form), 1, 0)), 2.0f, false);
                break;
            case 24:
                ::DispatchMessageToSink((const char *)(((const char *)(::FUN_00559450((int *)&(text))))), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_giftbox.dds"),
                               (const char *)(silent ? 0 : reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::Actor * *>(&::_g_thePlayer))))->FUN_008adcf0((::TESBoundObject *)(actor->form), 1, 0)), 2.0f, false);
                break;
            }
        }
    }
}


struct FUN_00482910_rec
{
    int unk00;
    std::intptr_t unk04;
};

struct FUN_00482910_node
{
};

struct FUN_00482910_obj
{
};

std::intptr_t __cdecl FUN_00ec43fb(std::intptr_t a, int b, void* c, void* d, int e);

class FUN_00482910_cls
{
  public:
    FUN_00482910_rec* FindBestRecord(FUN_00482910_obj* a1);
};

// Walks the node list, scores each record via a1->FUN_005f0d60, and returns the record with the highest score above DAT_01015f5c.
// @fnv 0x00482910
FUN_00482910_rec* FUN_00482910_cls::FindBestRecord(FUN_00482910_obj* pScorer)
{
    FUN_00482910_node* p = ((::FUN_00482910_node *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    float best = DAT_01015f5c;
    FUN_00482910_rec* result2 = 0;
    while (p != 0)
    {
        FUN_00482910_rec* t3 = *(FUN_00482910_rec**)((void *)((void *)(p)));
        if (t3 != 0)
        {
            FUN_00482910_rec* r = (FUN_00482910_rec*)FUN_00ec43fb(t3->unk04, 0, &DAT_01183108, &DAT_01183998, 0);
            if (r != 0)
            {
                float f7 = reinterpret_cast<::ActorBaseTarget *>((pScorer))->FUN_005f0d60((::FormTarget *)(r));
                if (f7 > best)
                {
                    best = f7;
                    result2 = r;
                }
            }
        }
        p = ((::FUN_00482910_node *)(reinterpret_cast<::Callees *>((p))->FUN_00726070()));
    }
    return result2;
}

struct FUN_00481d10_shell : TESContainer
{
    bool FUN_00481d10(BaseFormComponent* other);
};
int _ref_005ae380(void*);
// Compares this container's entries against another TESContainer's entries, returning true when they differ or the counts do not match.
// @fnv 0x00481d10
bool FUN_00481d10_shell::FUN_00481d10(BaseFormComponent* other)
{
    TESContainer* otherContainer = dynamic_cast<TESContainer*>(other);
    if (otherContainer == 0)
        return true;
    int matchCount = 0;
    void* current = ((void *)(reinterpret_cast<::BaseProcess *>((this))->GetCurrentProcessData()));
    void* otherCurrent = 0;
    InventoryItemEntry* itemBeingChecked;
    while (current != 0)
    {
        itemBeingChecked = *((::InventoryItemEntry **)((void *)(current)));
        if (itemBeingChecked != 0)
        {
            otherCurrent = ((void *)(reinterpret_cast<::BaseProcess *>((otherContainer))->GetCurrentProcessData()));
            bool differenceFound = false;
            while (otherCurrent != 0)
            {
                InventoryItemEntry* compareItem = *((::InventoryItemEntry **)((void *)(otherCurrent)));
                if (compareItem != 0)
                {
                    if (!reinterpret_cast<FUN_00481470_shell*>(compareItem)->IsNotEqual(itemBeingChecked))
                    {
                        differenceFound = true;
                        break;
                    }
                }
                otherCurrent = reinterpret_cast<::Callees *>((otherCurrent))->FUN_00726070();
            }
            if (!differenceFound)
                return true;
            ++matchCount;
        }
        current = reinterpret_cast<::Callees *>((current))->FUN_00726070();
    }
    if (_ref_005ae380(((void *)(reinterpret_cast<::BaseProcess *>((otherContainer))->GetCurrentProcessData()))) != matchCount)
        return true;
    return false;
}

class InventoryStackRecord
{
  public:
    int count;
    void* object;
};
struct Source08
{
    int unk00;
    BSSimpleList<InventoryStackRecord*> objects;
    BSSimpleList<InventoryStackRecord*>* CopyUniqueObjects();
};
// Copies the objects list into a new list in reverse order, then removes duplicate entries that share the same object pointer.
// @fnv 0x00482b00
BSSimpleList<InventoryStackRecord*>* Source08::CopyUniqueObjects()
{
    BSSimpleList<InventoryStackRecord*>* pNewList = new BSSimpleList<InventoryStackRecord*>;
    BSSimpleList<InventoryStackRecord*>* pList = &objects;
    while (pList && (pList->m_item))
    {
        pNewList->AddHead((pList->m_item));
        pList = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
    }
    pList = pNewList;
    BSSimpleList<InventoryStackRecord*>* iter = 0;
    while (pList && (pList->m_item))
    {
        iter = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        while (iter && (iter->m_item))
        {
            if ((pList->m_item)->object == (iter->m_item)->object)
            {
                reinterpret_cast<::ItemChangeListNode *>((pList))->FUN_00905330((iter->m_item));
                iter = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
            }
            else
                iter = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
        }
        pList = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
    }
    return pNewList;
}

struct VATSCommand;
struct ContNode;
struct VATS_CommandList
{
};
struct FUN_00481790_t
{
    void FUN_00481790(BGSPerkEntry* apEntry);
};
// @fnv 0x00481790
void FUN_00481790_t::FUN_00481790(BGSPerkEntry* apEntry)
{
    if (!apEntry)
        return;
    reinterpret_cast<::ItemChangeListNode *>((((VATS_CommandList*)((::ContNode *)(reinterpret_cast<::BaseProcess *>((this))->GetCurrentProcessData())))))->FUN_00905330((::InventoryStackRecord *const &)((VATSCommand* const&)apEntry));
    BGSPerkEntry* pkEntry = apEntry;
    BGSPerkEntry* pkDeleteCur = pkEntry;
    pkDeleteCur ? reinterpret_cast<::p07::DelStandIn *>((pkDeleteCur))->Destroy_00481760(1) : 0;
}

class TESBoundObject
{
  public:
    virtual ~TESBoundObject();
};
struct ArmorSlotMask
{
};
class TESObjectARMO : public TESBoundObject
{
  public:
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c;
    ArmorSlotMask bipedSlots;
};
struct ArmorRater
{
};
static const float kNegInfinity = -3.402823466e+38f;
struct ArmorContainer : TESContainer
{
    TESObjectARMO* FindBestArmorForSlot(ArmorRater* rater, int slot);
};
// Scans the container's object list for armor matching the given biped slot and returns the one with the highest rater score, or null.
// @fnv 0x004829c0
TESObjectARMO* ArmorContainer::FindBestArmorForSlot(ArmorRater* rater, int slot)
{
    BSSimpleList<InventoryStackRecord*>* iter = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::BaseProcess *>(this)->GetCurrentProcessData()));
    float best = kNegInfinity;
    TESObjectARMO* pkResult = 0;
    while (iter)
    {
        InventoryItemEntry* pkObject = (InventoryItemEntry*)(iter->m_item);
        if (pkObject)
        {
            TESObjectARMO* armor = dynamic_cast<TESObjectARMO*>((TESBoundObject*)pkObject->object);
            if (armor && slot != -1 && reinterpret_cast<::TESBipedModelForm *>(&(armor->bipedSlots))->HasBipedModel((::BIPED_OBJECT)(slot), 0, (::BGSBipedModelList *)(0)))
            {
                float fVal = reinterpret_cast<::ActorBaseTarget *>((rater))->FUN_005f0d60((::FormTarget *)(armor));
                if (fVal > best)
                {
                    best = fVal;
                    pkResult = armor;
                }
            }
        }
        iter = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((iter))->FUN_00726070()));
    }
    return pkResult;
}

struct RecipeAmmoData
{
};

struct RecipeProcess
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual bool IsBoundObject();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual RecipeAmmoData* GetAmmoData();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void RemoveItem(void* item, int extra, int count, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
};

struct RecipeActorForm
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
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
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual bool IsBoundObject();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual RecipeAmmoData* GetAmmoData();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void RemoveItem(void* item, int extra, int count, int a4, int a5, int a6, int a7, int a8, int a9, int a10);

    int FUN_00401170();
};

struct RecipeListBox
{
};

struct RecipeMenuState
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
    RecipeActorForm* crafterRef;
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
    RecipeListBox* recipeList;
};

struct ActiveRecipe
{
};

struct RecipeComponentItem
{
};

struct FUN_004f2770_Class
{
};

struct GameSettingStr
{
    const char* FUN_00403df0();
};

struct WeaponFormOps
{
};

struct RecipeContainerOps : TESContainer
{
};

struct RecipeStringOps : BSStringT<char>
{
};

extern const char str_0101c140[];

void __cdecl FUN_004d5e10(int statId, int delta);
void __cdecl FUN_00727430();

// Removes recipe components from the crafter and adds the crafted item, queuing a UI message with the item name and quantity.
// @fnv 0x007284f0
void CraftRecipe(int count)
{
    bool playedSound;
    bool isCasinoChip;
    {
        int compQty;
        {
            void* compForm;
            {
                ::BSSimpleList< ::InventoryStackRecord *>* node;
                {
                    RecipeActorForm* itemForm;
                    {
                        void* recipeTile = ((void *)(reinterpret_cast<::Owner *>(((*reinterpret_cast<::RecipeMenuState * *>(&::DAT_011d8e90))->recipeList))->FindItemData((int *)(void *)(&(*reinterpret_cast<::ActiveRecipe * *>(&::fnv_00726df0::DAT_011d8e94))))));
                        node = (::BSSimpleList< ::InventoryStackRecord *>*)reinterpret_cast<struct ::FUN_005a8080 *>(((*reinterpret_cast<::ActiveRecipe * *>(&::fnv_00726df0::DAT_011d8e94))))->GetField();
                        itemForm = 0;
                        compForm = 0;
                        compQty = 0;
                        if (count == 0)
                        {
                            return;
                        }
                        playedSound = 0;
                        isCasinoChip = 0;
                        for (; node != 0 && !node->IsEmpty();)
                        {
                            compForm = reinterpret_cast<::Callees *>(((*((::RecipeComponentItem **)((void *)(node))))))->FUN_00726070();
                            if (!playedSound)
                            {
                                ::ChallengeManager::UpdateChallengeProgress((::CHALLENGE_TYPE)(12), 1, (::TESForm *)(compForm), (::TESForm *)(0), 0, 0, 0);
                                if (((RecipeActorForm*)compForm)->FUN_00401170() == 0x6c)
                                {
                                    isCasinoChip = 1;
                                }
                            }
                            playedSound = 1;
                            compQty = ::FUN_00559450((int *)((*((::RecipeComponentItem **)((void *)(node))))));
                            if (compForm != 0 && ((RecipeActorForm*)compForm)->IsBoundObject())
                            {
                                itemForm = (RecipeActorForm*)compForm;
                            }
                            if (itemForm != 0)
                            {
                                RecipeActorForm* actor;
                                {
                                    bool isCurrentAmmo = 0;
                                    actor = ((*reinterpret_cast<::RecipeMenuState * *>(&::DAT_011d8e90))->crafterRef != 0 && (*reinterpret_cast<::RecipeMenuState * *>(&::DAT_011d8e90))->crafterRef->IsActor())
                                                ? (*reinterpret_cast<::RecipeMenuState * *>(&::DAT_011d8e90))->crafterRef
                                                : 0;
                                    if (actor != 0 && ((void *)(reinterpret_cast<::FUN_008a1710_shell *>((actor))->FUN_008a1710())) != 0)
                                    {
                                        isCurrentAmmo =
                                            (((void *)(reinterpret_cast<::AmmoOwner *>((((WeaponFormOps*)((void *)(reinterpret_cast<::FUN_008a1710_shell *>((actor))->FUN_008a1710())))))->FUN_00525980((::AmmoActor *)((*reinterpret_cast<::FUN_004f2770_Class * *>(&::_g_thePlayer)))))) ==
                                             reinterpret_cast<::Callees *>(((*((::RecipeComponentItem **)((void *)(node))))))->FUN_00726070());
                                    }
                                    if (itemForm->FUN_00401170() == 0x28)
                                    {
                                        if (reinterpret_cast<::CombatState *>((actor))->GetInventoryItemCount((::TESForm *)(itemForm)) == 1 && itemForm == ((void *)(reinterpret_cast<::FUN_008a1710_shell *>((actor))->FUN_008a1710())))
                                        {
                                            reinterpret_cast<::FUN_0088d7d0_shell *>((actor))->FUN_0088d7d0((::TESBoundObject *)(itemForm), 1, (::ExtraDataList *)(void *)(0), 0, 0, 1);
                                        }
                                    }
                                    (*reinterpret_cast<::RecipeMenuState * *>(&::DAT_011d8e90))->crafterRef->RemoveItem(itemForm, 0, compQty * count, 0, 0, 0, 0, 0, 1,
                                                                         0);
                                    if (isCurrentAmmo)
                                    {
                                        reinterpret_cast<::CombatProcedure *>((((::RecipeProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((actor))->GetBaseTexture()))->GetAmmoData()))->Initialize((::CombatController *)(0));
                                    }
                                }
                            }
                            node = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
                        }
                        if (!isCasinoChip)
                        {
                            FUN_004d5e10(0x20, count);
                        }
                        node = (::BSSimpleList< ::InventoryStackRecord *>*)reinterpret_cast<::FUN_005d43c0_ *>(((*reinterpret_cast<::ActiveRecipe * *>(&::fnv_00726df0::DAT_011d8e94))))->FUN_005d43c0();
                        itemForm = 0;
                        compForm = 0;
                        compQty = 0;
                        for (; node != 0 && !node->IsEmpty();)
                        {
                            compForm = reinterpret_cast<::Callees *>(((*((::RecipeComponentItem **)((void *)(node))))))->FUN_00726070();
                            compQty = ::FUN_00559450((int *)((*((::RecipeComponentItem **)((void *)(node))))));
                            if (compForm != 0 && ((RecipeActorForm*)compForm)->IsBoundObject())
                            {
                                itemForm = (RecipeActorForm*)compForm;
                            }
                            if (itemForm != 0)
                            {
                                if (itemForm->FUN_00401170() == 0x28)
                                {
                                    RecipeActorForm* weapForm = itemForm;
                                    if (::FUN_004c0bf0((::TESObjectWEAP *)(weapForm)))
                                    {
                                        reinterpret_cast<::fnv_00574fa0::AddBoundItemRef *>(((*reinterpret_cast<::RecipeMenuState * *>(&::DAT_011d8e90))->crafterRef))->FUN_00574fa0((::TESBoundObject *)(itemForm), (::ExtraDataList *)(0), compQty * count);
                                    }
                                    else
                                    {
                                        TESContainer tempCont1;
                                        if (itemForm != 0)
                                        {
                                            reinterpret_cast<::fnv_004818e0::FUN_004818e0_t *>((((RecipeContainerOps*)&tempCont1)))->FUN_004818e0((::TESObject *)(::TESForm *)((TESForm*)itemForm), compQty * count, 0);
                                        }
                                        reinterpret_cast<::fnv_00482090::FUN_00482090_shell *>((((RecipeContainerOps*)&tempCont1)))->FUN_00482090(::DAT_01030ff0);
                                        reinterpret_cast<::ContainerOperation *>((((RecipeContainerOps*)&tempCont1)))->FUN_004821a0((::TESObjectREFR *)((*reinterpret_cast<::RecipeMenuState * *>(&::DAT_011d8e90))->crafterRef), 0);
                                    }
                                }
                                else if (itemForm->FUN_00401170() == 0x18 || itemForm->FUN_00401170() == 0x1a)
                                {
                                    TESContainer tempCont2;
                                    if (itemForm != 0)
                                    {
                                        reinterpret_cast<::fnv_004818e0::FUN_004818e0_t *>((((RecipeContainerOps*)&tempCont2)))->FUN_004818e0((::TESObject *)(::TESForm *)((TESForm*)itemForm), compQty * count, 0);
                                    }
                                    reinterpret_cast<::fnv_00482090::FUN_00482090_shell *>((((RecipeContainerOps*)&tempCont2)))->FUN_00482090(::DAT_01030ff0);
                                    reinterpret_cast<::ContainerOperation *>((((RecipeContainerOps*)&tempCont2)))->FUN_004821a0((::TESObjectREFR *)((*reinterpret_cast<::RecipeMenuState * *>(&::DAT_011d8e90))->crafterRef), 0);
                                }
                                else
                                {
                                    reinterpret_cast<::fnv_00574fa0::AddBoundItemRef *>(((*reinterpret_cast<::RecipeMenuState * *>(&::DAT_011d8e90))->crafterRef))->FUN_00574fa0((::TESBoundObject *)(itemForm), (::ExtraDataList *)(0), compQty * count);
                                }
                                BSStringT<char> msgStr;
                                if (compQty * count > 1)
                                {
                                    ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&msgStr), ::DAT_0101c178, compQty * count, ::FUN_00482720((::TESForm *)(itemForm)),
                                                 ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d3114))))->GetMenuTitle())), ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d4e7c))))->GetMenuTitle())));
                                }
                                else
                                {
                                    ::FUN_00406f60((::FUN_00406f90_this *)(::BSStringT<char> *)(&msgStr), ::DAT_01012058, ::FUN_00482720((::TESForm *)(itemForm)),
                                                 ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d4e7c))))->GetMenuTitle())));
                                }
                                ::DispatchMessageToSink((const char *)(((const char *)(::FUN_00559450((int *)(((RecipeStringOps*)&msgStr)))))), 0, (const char *)(str_0101c140),
                                               (const char *)(reinterpret_cast<::PickupSoundActorView *>(((*reinterpret_cast<::FUN_004f2770_Class * *>(&::_g_thePlayer))))->FUN_008adcf0((::TESBoundObject *)(itemForm), 1, 0)), DAT_010162c0, 0);
                            }
                            node = ((::BSSimpleList< ::InventoryStackRecord *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
                        }
                        FUN_00727430();
                    }
                }
            }
        }
    }
}

namespace fnv_004826d0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
class Script;
class TESBoundObject;
class TESForm;
class TESObjectREFR;
struct blob8
{
    char b[8];
};
struct TESScriptableForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static Script* GetScriptForForm(TESForm*);
    Script* GetScriptForForm();
    static char* GetFormScriptEditorID(TESForm*);
    char* GetFormScriptEditorID();
    static void SetFormScript(TESForm*, Script*);
    void SetFormScript(Script*);
    Script* m_pFormScript;
    bool m_bHasScript;
    char _pad_9[3];
};

class Script;

extern "C" void* __cdecl FNV_DynamicCast(void*, long, void*, void*, int);
// Dynamic-casts apForm to TESScriptableForm and returns its script, or null if the cast fails.
// @fnv 0x004826d0
Script* FUN_004826d0(TESForm* apForm)
{
    TESScriptableForm* pSF =
        static_cast<TESScriptableForm*>(FNV_DynamicCast(apForm, 0, &(*reinterpret_cast<unsigned char *>(&::DAT_01183028)), &(*reinterpret_cast<unsigned char *>(&::load_extra_fixup::DAT_01183254)), 0));
    return pSF ? ((::fnv_004826d0::Script *)(reinterpret_cast<::Callees *>((pSF))->FUN_00726070())) : 0;
}
}  // namespace fnv_004826d0

class ContainerItemExtra_rtti2
{
  public:
    void* m_pForm;
    union
    {
        void* m_pGlobal;
        int m_cRank;
        unsigned int bits;
    };
    float m_fHealth;
    ContainerItemExtra_rtti2();
    void Copy(ContainerItemExtra_rtti2* other);
    bool IsDefault();
};

class InventoryItemEntry_rtti2
{
  public:
    int count;
    void* object;
    ContainerItemExtra_rtti2* extra;
    void Copy(InventoryItemEntry_rtti2* other);
};

class TESContainer_rtti2;

struct CopyComponentState_rtti2
{
    BSSimpleList<InventoryStackRecord*>* list;
    TESContainer_rtti2* source;
};

class TESForm_rtti2;

class TESContainer_rtti2 : public BaseFormComponent
{
  public:
    BSSimpleList<InventoryStackRecord*> objectList;
    virtual void Init();
    void ClearObjects();
    void InitItem(TESForm_rtti2* form);
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    ~TESContainer_rtti2();
    bool HasObjectOfType(TESObject* object);
    int GetObjectCount(TESObject* object);
    static bool IsValidContainerType(unsigned char type);
    TESContainer_rtti2();
};

class TESFile;

class TESForm_rtti2
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual const char* GetEditorID();

public:
    ::TESFile *GetFile(int);
};

class TESBoundObject_rtti2 : public TESForm_rtti2
{
};

class B81390Extra
{
  public:
};

class B81390ContainerObject_rtti2
{
  public:
    void FUN_00481390(TESForm_rtti2* pkOwner);

    int m_iArrayLength;
    TESBoundObject_rtti2* m_pPointer;
    B81390Extra* m_pkExtra;
};

// @fnv 0x00481390
void B81390ContainerObject_rtti2::FUN_00481390(TESForm_rtti2* pkOwner)
{
    unsigned int auiFormId = (unsigned int)(std::uintptr_t)m_pPointer;
    ::ResolveFormID(&auiFormId, (::TESFile *)(((std::intptr_t)(pkOwner->GetFile(-1)))));
    m_pPointer = dynamic_cast<TESBoundObject_rtti2*>(reinterpret_cast<TESForm_rtti2*>(FUN_004839c0(auiFormId)));
    if (!m_pPointer)
    {
        if (pkOwner)
        {
            if (reinterpret_cast<::BGSCameraPath *>((pkOwner))->HasNameForWarning())
                ::FUN_005b5e40();
            else
                ::FUN_005b5e40();
        }
        else
        {
            ::FUN_005b5e40();
        }
    }
    if (m_pkExtra)
        reinterpret_cast<::FUN_0040e7f0_owner *>((m_pkExtra))->ResolveFormReferences((::FormContext *)(pkOwner));
}

#include "generated/data/fallout_shared/tescontainer.inc"
