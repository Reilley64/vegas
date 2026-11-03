
// src/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <windows.h>
#include <new>
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00a311e0_s.h"
#include "fnv/decl/FUN_00a41520_cls.h"
#include "fnv/decl/FUN_00a645b0_cls.h"
#include "fnv/decl/FUN_00a6d290.h"
#include "fnv/decl/FUN_00a6d730_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/NiStream.h"
#include "fnv/decl/NiTimeControllerCM.h"
#include "fnv/decl/NiTimeController_Luna.h"
#include "fnv/decl/S_00b601a0_Map.h"
#include "fnv/decl/ViewerStrings.h"
#include "fnv/decl/fnv_00b5c7d0__StrArr.h"
#include "fnv/symbols_00a6c000.h"
#include "fnv/symbols_00a6d000.h"
#include "fnv/symbols_00a7d000.h"
#include "fnv/symbols_00a89000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_0109a000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/decl/Q52Obj.h"
#include "fnv/decl/S_0060ba10.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00a3d000.h"
#include "fnv/symbols_00c53000.h"
#include "fnv/symbols_010c1000.h"
#include "fnv/symbols_01203000.h"
#include <cstddef>
#include "fnv/decl/OwnerAB.h"
#include "fnv/symbols_00a26000.h"
extern int DAT_0109a2a4;

struct FUN_00a543f0_shell
{
    void* m_kPointA;
    void* m_ptr;
    void FUN_00a543f0();
};

// @fnv 0x00a543f0
void FUN_00a543f0_shell::FUN_00a543f0()
{
    void* p = m_ptr;
    m_kPointA = &DAT_0109a2a4;
    ::FUN_00aa10f0(p);
}

struct GlobalObjectO2_00a7b610
{
};


// @fnv 0x00a55120
GlobalObjectO2_00a7b610* __cdecl FUN_00a55120()
{
    return &::g_011f405c;
}

struct NiTMapBaseStub
{
};
extern int DAT_0109a264;
struct P03MM
{
};
struct FUN_00a54370_shell : NiTMapBaseStub
{
    void* m_kPointA;
    void* m_auiShapeKeys;
    void* m_ptr;
    FUN_00a54370_shell* FUN_00a54370(bool);
};
// Resets the two map bases, frees m_ptr, and optionally deallocates the object via g_memoryManager, returning this.
// @fnv 0x00a54370
FUN_00a54370_shell* FUN_00a54370_shell::FUN_00a54370(bool abFree)
{
    m_kPointA = &DAT_0109a284;
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
    m_kPointA = &DAT_0109a264;
    reinterpret_cast<::S_00b601a0_Map *>(this)->FUN_00b601a0();
    ::FUN_00aa10f0(m_ptr);
    if (abFree & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}

struct NiStreamLinkIDSet
{
    void* m_kPointA;
    unsigned int m_uiItemCount;
    unsigned int m_pRayCursor;
};

struct NiStreamLinkIDSetShell
{
    void AppendLinkID(unsigned int* value);
};

// Grows the set's storage when full, then stores the given value at the end and increments the count.
// @fnv 0x00a543b0
void NiStreamLinkIDSetShell::AppendLinkID(unsigned int* value)
{
    NiStreamLinkIDSet* set = reinterpret_cast<NiStreamLinkIDSet*>(this);
    if (set->m_pRayCursor == set->m_uiItemCount)
    {
        unsigned int size = set->m_uiItemCount;
        if (size > 0)
            size *= 2;
        else
            size = 1;
        reinterpret_cast<::FUN_00a311e0_s *>((set))->FUN_00a311e0(size);
    }
    unsigned int* puiData = reinterpret_cast<unsigned int*>(set->m_kPointA);
    puiData[set->m_pRayCursor] = *value;
    set->m_pRayCursor++;
}

namespace fnv_00a54410 {
struct MemoryManager
{
};
struct FUN_00a54410_shell
{
    void* m_kPointA;
    void* m_ptr;
    void* FreeAndMaybeDeallocate(unsigned int);
};
// @fnv 0x00a54410
void* FUN_00a54410_shell::FreeAndMaybeDeallocate(unsigned int flags)
{
    void* tmp = m_ptr;
    m_kPointA = (void*)&DAT_0109a2ac;
    ::FUN_00aa10f0(tmp);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a54410::MemoryManager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00a54410

struct CloningProcess;
struct NiObject
{
public:
    virtual void LinkObject(NiStream&);
};
struct BSFadeNode
{
};
struct NiBoneLODController : public NiObject
{
    char m_auiShapeKeys[0x34];
    int m_iLOD;
    unsigned int m_uiNumLODs;
    NiBoneLODController* FUN_00a550b0();
    NiBoneLODController* FUN_00a552c0(CloningProcess&);
};
namespace fnv_00a553f0 {
extern int DAT_0109a2d4;
struct S55190
{
    void ClearEntries();
};
struct S6D290
{
};
struct NiBoneLODController
{
    void* FUN_00a553f0(unsigned int);
};
// @fnv 0x00a553f0
void* NiBoneLODController::FUN_00a553f0(unsigned int flags)
{
    *(void**)this = (void*)&DAT_0109a2d4;
    ((S55190*)this)->ClearEntries();
    ::FUN_00aa10f0(*(void**)((char*)this + 0x5c));
    void* p1 = *(void**)((char*)this + 0x50);
    *(void**)((char*)this + 0x4c) = (void*)&::fnv_00a54410::DAT_0109a2ac;
    ::FUN_00aa10f0(p1);
    void* p2 = *(void**)((char*)this + 0x40);
    *(void**)((char*)this + 0x3c) = (void*)&DAT_0109a2a4;
    ::FUN_00aa10f0(p2);
    reinterpret_cast<struct ::FUN_00a6d290 *>((((S6D290*)this)))->FUN_00a6d290::~FUN_00a6d290();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x68);
    return this;
}
}  // namespace fnv_00a553f0

namespace fnv_00a54340 {
struct NiStream;
struct NiObject
{
    virtual void LinkObject(NiStream&);
};
struct NiBoneLODController : NiObject
{
    unsigned char _pad[0x30];
    int m_iLOD;
    void FUN_00a541f0(int);
    void FUN_00a54340(NiStream&);
};
// Calls NiObject::LinkObject, saves m_iLOD, sets m_iLOD to -1, then passes the saved value to FUN_00a541f0.
// @fnv 0x00a54340
void NiBoneLODController::FUN_00a54340(NiStream& kStream)
{
    ::FUN_00a89af0((intptr_t)this);
    int iLOD = m_iLOD;
    m_iLOD = -1;
    FUN_00a541f0(iLOD);
}
}  // namespace fnv_00a54340

namespace fnv_00a55130 {
struct NiRTTI
{
    const char* m_pcName;
    NiRTTI* m_pBaseRTTI;
};
struct TargetObj
{
    virtual void f0();
    virtual void f1();
    virtual NiRTTI* GetRTTI() const;
};
struct NiBoneLODController
{
    char _pad[0x2c];
    TargetObj* m_target;
    bool IsTargetOfType() const;
};
// Checks whether m_target's RTTI chain contains DAT_011f4428, returning false if m_target or its RTTI is null.
// @fnv 0x00a55130
bool NiBoneLODController::IsTargetOfType() const
{
    TargetObj* pkTarget = m_target;
    if (!pkTarget)
        return false;
    NiRTTI* pkRTTI = pkTarget->GetRTTI();
    if (!pkRTTI)
        return false;
    do
    {
        if (pkRTTI == &(*reinterpret_cast<::fnv_00a55130::NiRTTI *>(&::g_011f4428)))
            return true;
        pkRTTI = pkRTTI->m_pBaseRTTI;
    } while (pkRTTI);
    return false;
}
}  // namespace fnv_00a55130

namespace fnv_00a55160 {
struct NiUpdateData
{
};
extern int DAT_011a90c4;
struct NiBoneLODController
{
    char _pad[0x34];
    int m_iLOD;
    int m_uiNumLODs;
    void FUN_00a541f0(int);
    void UpdateLOD(NiUpdateData&);
};
// Clamps the global LOD value to the controller's LOD count and, if it differs from the current LOD, applies it via FUN_00a541f0.
// @fnv 0x00a55160
void NiBoneLODController::UpdateLOD(NiUpdateData& UpdateData)
{
    int iNewLOD = DAT_011a90c4;
    if (iNewLOD == -1)
        return;
    if (iNewLOD == m_iLOD)
        return;
    if (iNewLOD > m_uiNumLODs)
        iNewLOD = m_uiNumLODs - 1;
    if (iNewLOD == m_iLOD)
        return;
    FUN_00a541f0(iNewLOD);
}
}  // namespace fnv_00a55160

struct A51BF0Base
{
};

// @fnv 0x00a55300
NiBoneLODController* CreateBoneLODController()
{
    NiBoneLODController* p = (NiBoneLODController*)::operator new(0x68);
    if (p)
        return p->FUN_00a550b0();
    return 0;
}

class NiStream;

class NiObjectA53
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void unkv10();
    virtual void unkv14();
    virtual void unkv18();
    virtual void unkv1C();
    virtual void unkv20();
    virtual void unkv24();
    virtual void unkv28();
    virtual void unkv2C();
    virtual void unkv30();
    virtual void unkv34();
    virtual void unkv38();
    virtual void unkv3C();
    virtual void unkv40();
    virtual void unkv44();
    virtual void unkv48();
    virtual void unkv4C();
    virtual void unkv50();
    virtual bool RegisterStreamables(NiStream& kStream);
};

template <class T> class NiPointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

class NiSkinInstance : public NiObjectA53
{
};

class NiTriBasedGeom;

class GeometrySkinInstancePair
{
  public:
    NiTriBasedGeom* m_pkGeom;
    NiPointer<NiSkinInstance> m_spInstance;
};

template <class T> class NiTPrimitiveSet
{
  public:
    unsigned int GetSize() const
    {
        return m_uiAllocatedCapacity;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }

    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};

typedef NiTPrimitiveSet<GeometrySkinInstancePair*> SkinInfoSet;

template <class T> class NiTPrimitiveArray
{
  public:
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }

    void* m_vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class CloningProcess;
class NiStream;
class NiObjectNET;
class NiTimeController : public NiObjectA53
{
  public:
    bool RegisterStreamables(NiStream& kStream);

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
public:
    void ProcessClone(::CloningProcess &);
public:
    void LinkObject(::NiStream &);
public:
    void SetTarget(::NiObjectNET *);
};

class NiBoneLODControllerA53 : public NiTimeController
{
  public:
    bool FUN_00a53d00(NiStream& kStream);

    int m_iLOD;
    unsigned int m_uiNumLODs;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    NiTPrimitiveArray<SkinInfoSet*> m_kSkinInfoSets;
};

// Calls the base RegisterStreamables, then registers the skin instance of every skin info in each LOD skin info set, returning false if the base call fails.
// @fnv 0x00a53d00
bool NiBoneLODControllerA53::FUN_00a53d00(NiStream& kStream)
{
    if (!::FUN_00a6d0f0((::TCReg *)this, (intptr_t)&(kStream), *(::NiStream *)nullptr))
        return false;

    for (unsigned int ui = 0; ui < m_kSkinInfoSets.GetSize(); ui++)
    {
        SkinInfoSet* pkSkinInfoSet = m_kSkinInfoSets.GetAt(ui);
        if (pkSkinInfoSet)
        {
            for (unsigned int uj = 0; uj < pkSkinInfoSet->GetSize(); uj++)
            {
                GeometrySkinInstancePair* pkSkinInfo = pkSkinInfoSet->GetAt(uj);
                if (pkSkinInfo->m_spInstance)
                    pkSkinInfo->m_spInstance->RegisterStreamables(kStream);
            }
        }
    }

    return true;
}

struct RefObject
{
    virtual void UnknownVirtual();
    virtual void Destroy();
    volatile long referenceCount;
};
struct LODNode
{
    unsigned int unknown00;
    unsigned int unknown04;
    unsigned int unknown08;
    unsigned int unknown0c;
    unsigned int unknown10;
    unsigned int unknown14;
    unsigned int unknown18;
    unsigned int unknown1c;
    unsigned int unknown20;
    unsigned int unknown24;
    unsigned int unknown28;
    unsigned int unknown2c;
    volatile unsigned int stateFlags;
    unsigned int unknown34;
    unsigned int unknown38;
    unsigned int unknown3c;
    unsigned int unknown40;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned int unknown4c;
    unsigned int unknown50;
    unsigned int unknown54;
    unsigned int unknown58;
    unsigned int unknown5c;
    unsigned int unknown60;
    unsigned int unknown64;
    unsigned int unknown68;
    unsigned int unknown6c;
    unsigned int unknown70;
    unsigned int unknown74;
    unsigned int unknown78;
    unsigned int unknown7c;
    unsigned int unknown80;
    unsigned int unknown84;
    unsigned int unknown88;
    unsigned int unknown8c;
    unsigned int unknown90;
    unsigned int unknown94;
    unsigned int unknown98;
    unsigned int unknown9c;
    unsigned int unknowna0;
    unsigned int unknowna4;
    unsigned int unknowna8;
    unsigned int unknownac;
    unsigned int unknownb0;
    unsigned int unknownb4;
    unsigned int unknownb8;
    RefObject* volatile activeReference;
};
struct NodeCollection
{
    LODNode** elements;
    unsigned int capacity;
    unsigned int count;
};
struct LinkPair
{
    LODNode* node;
    RefObject* reference;
};
struct PairCollection
{
    LinkPair** elements;
    unsigned int capacity;
    unsigned int count;
};
struct LODManager : NiBoneLODController
{
    void* unknown3c;
    NodeCollection** nodeGroups;
    unsigned short unknown44;
    unsigned short groupCount;
    void* unknown48;
    void* unknown4c;
    PairCollection** linkGroups;
    void* unknown54;
    void* unknown58;
    LODNode** defaultNodes;
    unsigned int unknown60;
    unsigned int defaultNodeCount;
    bool FUN_00a541f0(int desiredLOD);
};
// Switches the LOD level: toggles stateFlags on group and default nodes, updates link-group references, and stores the new LOD if it differs and is valid.
// @fnv 0x00a541f0
bool LODManager::FUN_00a541f0(int desiredLOD)
{
    if (m_uiNumLODs > 0 && m_iLOD != desiredLOD &&
        (desiredLOD == -1 || (desiredLOD > -1 && (unsigned int)desiredLOD < m_uiNumLODs)))
    {

        bool enableFollowing = false;
        for (unsigned int groupIndex = 0; groupIndex < groupCount; ++groupIndex)
        {
            NodeCollection* group = nodeGroups[groupIndex];
            if (group)
            {
                if (groupIndex == (unsigned int)desiredLOD)
                    enableFollowing = true;
                for (unsigned int i = 0; i < group->count; ++i)
                {
                    LODNode* node = group->elements[i];
                    if (enableFollowing)
                        node->stateFlags |= 2;
                    else
                        node->stateFlags &= ~2u;
                }
            }
        }

        for (unsigned int i = 0; i < defaultNodeCount; ++i)
        {
            LODNode* node = defaultNodes[i];
            node->stateFlags = (node->stateFlags & ~2u) | 1u;
        }

        if (desiredLOD != -1)
        {
            PairCollection* group = linkGroups[desiredLOD];
            if (group)
            {
                for (unsigned int i = 0; i < group->count; ++i)
                {
                    LODNode* node = group->elements[i]->node;
                    node->stateFlags = (node->stateFlags & ~1u) | 2u;
                    RefObject* newRef = group->elements[i]->reference;
                    RefObject* oldRef = node->activeReference;
                    if (oldRef != newRef)
                    {
                        if (oldRef && InterlockedDecrement(&oldRef->referenceCount) == 0)
                            oldRef->Destroy();
                        node->activeReference = newRef;
                        if (newRef)
                            InterlockedIncrement(&newRef->referenceCount);
                    }
                }
            }
        }

        m_iLOD = desiredLOD;
        return true;
    }
    return false;
}

struct MemoryAllocator
{
};

struct RefCounter
{
    virtual void Keep();
    virtual void Release();
    volatile long count;
};

struct FirstEntry
{
    void* allocation;
};

struct NestedEntry
{
    void* object;
    RefCounter* reference;
};
struct EntryGroup
{
    NestedEntry** objects;
    unsigned int reserved;
    unsigned int count;
};

struct FUN_00a55190_owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    FirstEntry** smallEntries;
    unsigned short unk44;
    unsigned short smallCount;
    unsigned short smallCapacity;
    unsigned short unk4a;
    unsigned int unk4c;
    EntryGroup** largeEntries;
    unsigned short unk54;
    unsigned short largeCount;
    unsigned short largeCapacity;
    unsigned short unk5a;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int current;

    void ClearEntries();
};

// Frees every small and large entry, nulls the entry arrays, resets their counts and capacities, and clears current.
// @fnv 0x00a55190
void FUN_00a55190_owner::ClearEntries()
{
    for (unsigned int i = 0; i < smallCount; ++i)
    {
        FirstEntry* entry = smallEntries[i];
        if (entry)
        {
            ::FUN_00aa10f0(entry->allocation);
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MemoryAllocator *>(&::g_memoryManager))))->FUN_00aa4060(entry);
        }
    }
    for (unsigned short i = 0; i < smallCount; ++i)
        smallEntries[i] = 0;
    smallCount = 0;
    smallCapacity = 0;

    for (unsigned int i = 0; i < largeCount; ++i)
    {
        EntryGroup* group = largeEntries[i];
        if (group)
        {
            for (unsigned int j = 0; j < group->count; ++j)
            {
                NestedEntry* object = group->objects[j];
                if (object)
                {
                    RefCounter* reference = object->reference;
                    if (reference && InterlockedDecrement(&reference->count) == 0)
                        reference->Release();
                    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MemoryAllocator *>(&::g_memoryManager))))->FUN_00aa4060(object);
                }
            }
            ::FUN_00aa10f0(group->objects);
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::MemoryAllocator *>(&::g_memoryManager))))->FUN_00aa4060(group);
        }
    }
    for (unsigned short i = 0; i < largeCount; ++i)
        largeEntries[i] = 0;
    largeCount = 0;
    largeCapacity = 0;
    *(volatile unsigned int*)&current = 0;
}

class BA55320StringArray
{
  public:
    virtual ~BA55320StringArray();
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::ViewerStrings *>(this)->SetSize(uiIndex + m_usGrowBy);
        reinterpret_cast<::fnv_00b5c7d0::StrArr *>(this)->SetAt(uiIndex, (char *&)(pcElement));
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};



class A55320Object
{
  public:
    void* m_pVtbl;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int m_iLOD;
    unsigned int m_uiNumLODs;

    void AppendViewerStrings(BA55320StringArray* pkStrings);
};

// Appends the class name and formatted m_iLOD and m_uiNumLODs strings to pkStrings.
// @fnv 0x00a55320
void A55320Object::AppendViewerStrings(BA55320StringArray* pkStrings)
{
    pkStrings->Add(FUN_00a7d330((*reinterpret_cast<const char * *>(&::g_011f405c))));
    pkStrings->Add(::FUN_00a7d4d0("m_iLOD", m_iLOD));
    pkStrings->Add(::FUN_00a7d510("m_uiNumLODs", m_uiNumLODs));
}

class EqObject
{
  public:
    virtual void unkv00();
    virtual void unkv04();
    virtual void unkv08();
    virtual void unkv0C();
    virtual void unkv10();
    virtual void unkv14();
    virtual void unkv18();
    virtual void unkv1C();
    virtual void unkv20();
    virtual void unkv24();
    virtual void unkv28();
    virtual void unkv2C();
    virtual void unkv30();
    virtual void unkv34();
    virtual void unkv38();
    virtual void unkv3C();
    virtual void unkv40();
    virtual void unkv44();
    virtual void unkv48();
    virtual void unkv4C();
    virtual void unkv50();
    virtual void unkv54();
    virtual void unkv58();
    virtual bool IsEqual(EqObject* pkObject);
};
template <class T> class EqPointer
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};
struct EqSkinInfo
{
    EqObject* m_pkGeom;
    EqPointer<EqObject> m_spInstance;
};
template <class T> class EqPrimitiveSet
{
  public:
    unsigned int GetSize() const
    {
        return m_uiAllocatedCapacity;
    }
    T& GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }

    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};
template <class T> class EqPrimitiveArray
{
  public:
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }

    void* m_vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
typedef EqPrimitiveSet<EqObject*> EqNodeSet;
typedef EqPrimitiveSet<EqSkinInfo*> EqSkinInfoSet;
class EqTimeController : public EqObject
{
  public:

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
};
class EqBoneLODController : public EqTimeController
{
  public:
    bool FUN_00a53ea0(EqObject* pkObject);

    int m_iLOD;
    unsigned int m_uiNumLODs;
    EqPrimitiveArray<EqNodeSet*> m_kBoneSetArray;
    EqPrimitiveArray<EqSkinInfoSet*> m_kSkinInfoSets;
    EqPrimitiveSet<EqObject*> m_kShapeArray;
};

// Compares LOD, LOD counts, node/skin/shape sets and their elements against pkObject after BaseIsEqual, returning false on any mismatch.
// @fnv 0x00a53ea0
bool EqBoneLODController::FUN_00a53ea0(EqObject* pkObject)
{
    if (!::FUN_00a6cc80((::TCEq *)this, (intptr_t)(pkObject), {}))
        return false;

    EqBoneLODController* pkDest = (EqBoneLODController*)pkObject;

    if (m_iLOD != pkDest->m_iLOD || m_uiNumLODs != pkDest->m_uiNumLODs ||
        m_kBoneSetArray.GetSize() != pkDest->m_kBoneSetArray.GetSize() ||
        m_kSkinInfoSets.GetSize() != pkDest->m_kSkinInfoSets.GetSize() ||
        m_kShapeArray.GetSize() != pkDest->m_kShapeArray.GetSize())
    {
        return false;
    }

    unsigned int ui;
    for (ui = 0; ui < m_kBoneSetArray.GetSize(); ui++)
    {
        EqNodeSet* pkSet = m_kBoneSetArray.GetAt(ui);
        EqNodeSet* pkDestSet = pkDest->m_kBoneSetArray.GetAt(ui);
        if ((pkSet && !pkDestSet) || (!pkSet && pkDestSet))
            return false;
        if (pkSet && pkDestSet)
        {
            if (pkSet->GetSize() != pkDestSet->GetSize())
                return false;
            for (unsigned int uj = 0; uj < pkSet->GetSize(); uj++)
            {
                if (!pkSet->GetAt(uj)->IsEqual(pkDestSet->GetAt(uj)))
                    return false;
            }
        }
    }

    for (ui = 0; ui < m_kSkinInfoSets.GetSize(); ui++)
    {
        EqSkinInfoSet* pkSet = m_kSkinInfoSets.GetAt(ui);
        EqSkinInfoSet* pkDestSet = pkDest->m_kSkinInfoSets.GetAt(ui);
        if ((pkSet && !pkDestSet) || (!pkSet && pkDestSet))
            return false;
        if (pkSet && pkDestSet)
        {
            if (pkSet->GetSize() != pkDestSet->GetSize())
                return false;
            for (unsigned int uj = 0; uj < pkSet->GetSize(); uj++)
            {
                EqSkinInfo* pkInfo = pkSet->GetAt(uj);
                EqSkinInfo* pkDestInfo = pkDestSet->GetAt(uj);
                if (!pkInfo->m_pkGeom->IsEqual(pkDestInfo->m_pkGeom))
                    return false;
                if (!pkInfo->m_spInstance->IsEqual(pkDestInfo->m_spInstance))
                    return false;
            }
        }
    }

    for (ui = 0; ui < m_kShapeArray.GetSize(); ui++)
    {
        if (!m_kShapeArray.GetAt(ui)->IsEqual(pkDest->m_kShapeArray.GetAt(ui)))
            return false;
    }

    return true;
}

struct StreamBinary
{
    unsigned int unknown;
    unsigned int position;
    unsigned int(__cdecl* read)(StreamBinary*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* data, unsigned int size)
    {
        unsigned int amount = read(this, data, size, &size, 1);
        position += amount;
        return amount;
    }
};
struct LODStream
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    StreamBinary* binary;
    void Read32(void* data)
    {
        StreamBinary* file = binary;
        file->Read(data, 4);
    }
};
struct LODPool
{
};
template <class T> struct LinkGroup
{
    T* data;
    unsigned int capacity;
    unsigned int count;
    LinkGroup() : data(0), capacity(0), count(0)
    {}
    void Reserve(unsigned int size)
    {
        if (size != capacity)
        {
            T* replacement;
            if (size > 0)
            {
                replacement = (T*)FUN_00aa1070(size * sizeof(T));
                for (unsigned int i = 0; i < count; i++)
                    replacement[i] = data[i];
            }
            else
                replacement = 0;
            ::FUN_00aa10f0(data);
            data = replacement;
            capacity = size;
        }
    }
    void Add(T const& element)
    {
        if (count == capacity)
            Reserve(capacity > 0 ? capacity * 2 : 1);
        data[count] = element;
        count++;
    }
};
struct LinkSkinInfo
{
    void* object;
    void* skin;
    LinkSkinInfo() : skin(0)
    {}
};
template <class T> struct LinkGroupArray
{
    void* vtable;
    LinkGroup<T>** data;
    unsigned short capacity, size, used, growBy;
    void FUN_00a90180(unsigned int);
    __forceinline void SetAt(unsigned int index, LinkGroup<T>* const& group)
    {
        if (index >= capacity)
            reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00a90180(index + growBy);
        if (index >= size)
        {
            size = (unsigned short)(index + 1);
            if (group)
                used++;
        }
        else
        {
            if (group)
            {
                if (!data[index])
                    used++;
            }
            else if (data[index])
                used--;
        }
        data[index] = group;
    }
};
struct BoneLODLoader
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
    int currentLOD;
    unsigned int lodCount;
    LinkGroupArray<void*> nodeGroups;
    LinkGroupArray<LinkSkinInfo*> skinGroups;
    LinkGroup<void*> extraLinks;
    void ReadFromStream(LODStream*);
};
// Reads the current LOD, LOD count, node groups, skin groups and extra links from the stream, building the group arrays.
// @fnv 0x00a54c40
void BoneLODLoader::ReadFromStream(LODStream* stream)
{
    unsigned int i;
    reinterpret_cast<::NiTimeController_Luna *>(this)->FUN_00a6d5e0((*(::NiStream *)(stream)));
    stream->Read32(&currentLOD);
    stream->Read32(&lodCount);
    unsigned int nodeCount = 0;
    stream->Read32(&nodeCount);
    for (i = 0; i < nodeCount; i++)
    {
        LinkGroup<void*>* group = new LinkGroup<void*>;
        nodeGroups.SetAt(i, group);
        unsigned int childCount = 0;
        stream->Read32(&childCount);
        for (unsigned int j = 0; j < childCount; j++)
        {
            void* object = this;
            group->Add(object);
            reinterpret_cast<::FUN_00a645b0_cls *>((stream))->FUN_00a645b0();
        }
    }
    unsigned int skinCount = 0;
    stream->Read32(&skinCount);
    for (i = 0; i < skinCount; i++)
    {
        LinkGroup<LinkSkinInfo*>* group = new LinkGroup<LinkSkinInfo*>;
        skinGroups.SetAt(i, group);
        unsigned int childCount = 0;
        stream->Read32(&childCount);
        for (unsigned int j = 0; j < childCount; j++)
        {
            LinkSkinInfo* info = new LinkSkinInfo;
            group->Add(info);
            reinterpret_cast<::FUN_00a645b0_cls *>((stream))->FUN_00a645b0();
            reinterpret_cast<::FUN_00a645b0_cls *>((stream))->FUN_00a645b0();
        }
    }
    unsigned int extraCount = 0;
    stream->Read32(&extraCount);
    for (i = 0; i < extraCount; i++)
    {
        void* object = this;
        extraLinks.Add(object);
        reinterpret_cast<::FUN_00a645b0_cls *>((stream))->FUN_00a645b0();
    }
}

namespace fnv_00a549d0 {
struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
template <class T> inline void SerializeValue(NiBinaryStream& binstream, const T& value)
{
    unsigned int uiSize = sizeof(T);
    binstream.BinaryWrite(&value, sizeof(T), &uiSize, 1);
}
struct NiStream
{
    virtual void unknownV00();
    virtual void unknownV04();
    virtual void unknownV08();
    virtual void unknownV0c();
    virtual void unknownV10();
    virtual void unknownV14();
    virtual void unknownV18();
    virtual void unknownV1c();
    virtual void unknownV20();
    virtual void unknownV24();
    virtual void unknownV28();
    virtual void unknownV2c();
    virtual void SaveLink(void* object);
    unsigned int unknown004;
    unsigned int unknown008;
    unsigned int unknown00c;
    unsigned int unknown010;
    unsigned int unknown014;
    unsigned int unknown018;
    unsigned int unknown01c;
    unsigned int unknown020;
    unsigned int unknown024;
    unsigned int unknown028;
    unsigned int unknown02c;
    unsigned int unknown030;
    unsigned int unknown034;
    unsigned int unknown038;
    unsigned int unknown03c;
    unsigned int unknown040;
    unsigned int unknown044;
    unsigned int unknown048;
    unsigned int unknown04c;
    unsigned int unknown050;
    unsigned int unknown054;
    unsigned int unknown058;
    unsigned int unknown05c;
    unsigned int unknown060;
    unsigned int unknown064;
    unsigned int unknown068;
    unsigned int unknown06c;
    unsigned int unknown070;
    unsigned int unknown074;
    unsigned int unknown078;
    unsigned int unknown07c;
    unsigned int unknown080;
    unsigned int unknown084;
    unsigned int unknown088;
    unsigned int unknown08c;
    unsigned int unknown090;
    unsigned int unknown094;
    unsigned int unknown098;
    unsigned int unknown09c;
    unsigned int unknown0a0;
    unsigned int unknown0a4;
    unsigned int unknown0a8;
    unsigned int unknown0ac;
    unsigned int unknown0b0;
    unsigned int unknown0b4;
    unsigned int unknown0b8;
    unsigned int unknown0bc;
    unsigned int unknown0c0;
    unsigned int unknown0c4;
    unsigned int unknown0c8;
    unsigned int unknown0cc;
    unsigned int unknown0d0;
    unsigned int unknown0d4;
    unsigned int unknown0d8;
    unsigned int unknown0dc;
    unsigned int unknown0e0;
    unsigned int unknown0e4;
    unsigned int unknown0e8;
    unsigned int unknown0ec;
    unsigned int unknown0f0;
    unsigned int unknown0f4;
    unsigned int unknown0f8;
    unsigned int unknown0fc;
    unsigned int unknown100;
    unsigned int unknown104;
    unsigned int unknown108;
    unsigned int unknown10c;
    unsigned int unknown110;
    unsigned int unknown114;
    unsigned int unknown118;
    unsigned int unknown11c;
    unsigned int unknown120;
    unsigned int unknown124;
    unsigned int unknown128;
    unsigned int unknown12c;
    unsigned int unknown130;
    unsigned int unknown134;
    unsigned int unknown138;
    unsigned int unknown13c;
    unsigned int unknown140;
    unsigned int unknown144;
    unsigned int unknown148;
    unsigned int unknown14c;
    unsigned int unknown150;
    unsigned int unknown154;
    unsigned int unknown158;
    unsigned int unknown15c;
    unsigned int unknown160;
    unsigned int unknown164;
    unsigned int unknown168;
    unsigned int unknown16c;
    unsigned int unknown170;
    unsigned int unknown174;
    unsigned int unknown178;
    unsigned int unknown17c;
    unsigned int unknown180;
    unsigned int unknown184;
    unsigned int unknown188;
    unsigned int unknown18c;
    unsigned int unknown190;
    unsigned int unknown194;
    unsigned int unknown198;
    unsigned int unknown19c;
    unsigned int unknown1a0;
    unsigned int unknown1a4;
    unsigned int unknown1a8;
    unsigned int unknown1ac;
    unsigned int unknown1b0;
    unsigned int unknown1b4;
    unsigned int unknown1b8;
    unsigned int unknown1bc;
    unsigned int unknown1c0;
    unsigned int unknown1c4;
    unsigned int unknown1c8;
    unsigned int unknown1cc;
    unsigned int unknown1d0;
    unsigned int unknown1d4;
    unsigned int unknown1d8;
    unsigned int unknown1dc;
    unsigned int unknown1e0;
    unsigned int unknown1e4;
    unsigned int unknown1e8;
    unsigned int unknown1ec;
    unsigned int unknown1f0;
    unsigned int unknown1f4;
    unsigned int unknown1f8;
    unsigned int unknown1fc;
    unsigned int unknown200;
    unsigned int unknown204;
    unsigned int unknown208;
    unsigned int unknown20c;
    unsigned int unknown210;
    unsigned int unknown214;
    unsigned int unknown218;
    unsigned int unknown21c;
    unsigned int unknown220;
    unsigned int unknown224;
    unsigned int unknown228;
    unsigned int unknown22c;
    unsigned int unknown230;
    unsigned int unknown234;
    unsigned int unknown238;
    unsigned int unknown23c;
    unsigned int unknown240;
    unsigned int unknown244;
    unsigned int unknown248;
    unsigned int unknown24c;
    NiBinaryStream* output;
};
struct BaseHack : NiTimeController
{
    virtual void FUN_00a6d730(NiStream& stream);
};
struct BoneLODSerializer : BaseHack
{
    int lod;
    unsigned int lodCount;
    NiTPrimitiveArray<NodeCollection*> nodes;
    NiTPrimitiveArray<PairCollection*> skins;
    NodeCollection defaultNodes;
    virtual void FUN_00a549d0(NiStream& stream);
};
template <class T> inline void SaveStream(NiStream& kStream, const T& value)
{
    SerializeValue(*kStream.output, value);
}
// Serializes the LOD level, node groups, skin groups, and default nodes of a bone LOD entry to the stream.
// @fnv 0x00a549d0
void BoneLODSerializer::FUN_00a549d0(NiStream& stream)
{
    reinterpret_cast<::FUN_00a6d730_shell *>(this)->FUN_00a6d730((::Stream_a6d730 &)(stream));
    SaveStream(stream, lod);
    SaveStream(stream, lodCount);
    {
        unsigned int uiNumNodeGroups = nodes.GetSize();
        SaveStream(stream, uiNumNodeGroups);
    }
    unsigned int i;
    for (i = 0; i < nodes.GetSize(); i++)
    {
        NodeCollection* pkSet = nodes.GetAt(i);
        if (pkSet)
        {
            unsigned int uiElementCount = pkSet->count;
            SaveStream(stream, uiElementCount);
            for (unsigned int j = 0; j < pkSet->count; j++)
                stream.SaveLink(pkSet->elements[j]);
        }
        else
        {
            unsigned int uiElementCount = 0;
            SaveStream(stream, uiElementCount);
        }
    }
    {
        unsigned int uiNumSkinGroups = skins.GetSize();
        SaveStream(stream, uiNumSkinGroups);
    }
    for (i = 0; i < skins.GetSize(); i++)
    {
        PairCollection* pkSet = skins.GetAt(i);
        if (pkSet)
        {
            unsigned int uiElementCount = pkSet->count;
            SaveStream(stream, uiElementCount);
            for (unsigned int j = 0; j < pkSet->count; j++)
            {
                LinkPair* pkPair = pkSet->elements[j];
                stream.SaveLink(pkPair->node);
                stream.SaveLink(pkPair->reference);
            }
        }
        else
        {
            unsigned int uiElementCount = 0;
            SaveStream(stream, uiElementCount);
        }
    }
    {
        unsigned int uiNumDefaultNodes = defaultNodes.count;
        SaveStream(stream, uiNumDefaultNodes);
    }
    for (i = 0; i < defaultNodes.count; i++)
        stream.SaveLink(defaultNodes.elements[i]);
}
}  // namespace fnv_00a549d0

namespace a550 {
class FUN_00a6d220
{
  public:
    FUN_00a6d220() throw();
    virtual void unk00();
    char unk04[0x30];
};
}
template <class T> class NiTMallocInterfaceA55
{
  public:
    static T* Allocate(unsigned int auiCount) throw();
};
template <class T, class TAlloc> class NiTArrayA55
{
  public:
    NiTArrayA55(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
    {
        m_usMaxSize = (unsigned short)uiMaxSize;
        m_usGrowBy = (unsigned short)uiGrowBy;
        m_usSize = 0;
        m_usESize = 0;
        if (m_usMaxSize > 0)
            m_pBase = TAlloc::Allocate(m_usMaxSize);
        else
            m_pBase = 0;
    }
    virtual ~NiTArrayA55();
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};
template <class T> class NiTPrimitiveArrayA55 : public NiTArrayA55<T, NiTMallocInterfaceA55<T> >
{
  public:
    NiTPrimitiveArrayA55(unsigned int uiMaxSize = 0, unsigned int uiGrowBy = 1)
        : NiTArrayA55<T, NiTMallocInterfaceA55<T> >(uiMaxSize, uiGrowBy)
    {}
};
template <class T> class NiTPrimitiveSetA55
{
  public:
    NiTPrimitiveSetA55(unsigned int uiInitialSize = 0)
    {
        if (uiInitialSize > 0)
            m_pBase = NiTMallocInterfaceA55<T>::Allocate(uiInitialSize);
        else
            m_pBase = 0;
        m_uiElementCount = uiInitialSize;
        m_uiAllocatedCapacity = 0;
    }
    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};
class NiNodeA55;
class SkinInfoA55;
class NiGeometryA55;
class FUN_00a550b0 : public a550::FUN_00a6d220
{
  public:
    FUN_00a550b0();
    int m_iLOD;
    unsigned int m_uiNumLODs;
    NiTPrimitiveArrayA55<NiTPrimitiveSetA55<NiNodeA55*>*> m_kNodeArray;
    NiTPrimitiveArrayA55<NiTPrimitiveSetA55<SkinInfoA55*>*> m_kSkinInfoSets;
    NiTPrimitiveSetA55<NiGeometryA55*> m_kShaderSet;
};
// @fnv 0x00a552c0
NiBoneLODController* NiBoneLODController::FUN_00a552c0(CloningProcess& kCloning)
{
    NiBoneLODController* pkObject = static_cast<NiBoneLODController*>(::operator new(0x68));
    if (pkObject)
        pkObject = ((::NiBoneLODController *)(new ((void *)(pkObject)) ::FUN_00a550b0()));
    else
        pkObject = 0;
    reinterpret_cast<::NiTimeControllerCM *>(this)->FUN_00a6cfe0((::NiTimeController *)(pkObject), (*(::CloningProcess *)(&kCloning)));
    pkObject->m_iLOD = m_iLOD;
    pkObject->m_uiNumLODs = m_uiNumLODs;
    return pkObject;
}
// Default constructor that initializes m_iLOD to -1 and m_uiNumLODs to 0.
// @fnv 0x00a550b0
FUN_00a550b0::FUN_00a550b0() : m_iLOD(-1), m_uiNumLODs(0)
{}

struct A54440Remap;
struct RefObject;
struct A54440Clonable
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual RefObject* MakeClone(A54440Remap* remap);
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void ProcessClone(A54440Remap* remap);
};
struct A54440Manager;
struct A54440Remap;
struct A54440HashItem
{
    A54440HashItem* next;
    void* source;
    void* replacement;
};
struct A54440Hash
{
    virtual void Unused();
    virtual unsigned int BucketFor(void* source);
    virtual bool Equals(void* source, void* key);
    unsigned int reserved;
    A54440HashItem** buckets;
    __declspec(noinline) bool FUN_00a53c30(A54440Manager* source, A54440Manager** out);
public:
};
struct A54440Remap
{
    A54440Hash* map;
};
struct A54440Heap : MemoryAllocator
{
};
struct A54440PointerGroup
{
    A54440PointerGroup() : elements(0), capacity(0), count(0)
    {}
    void** elements;
    unsigned int capacity;
    unsigned int count;
    void Append(void* item)
    {
        if (count == capacity)
            reinterpret_cast<::FUN_00a311e0_s *>(this)->FUN_00a311e0(capacity > 0 ? capacity * 2 : 1);
        elements[count++] = item;
    }
};
struct A54440Link
{
    void* data;
    RefObject* ref;
};
struct A54440GrowGroup
{
    void** elements;
    unsigned int capacity;
    unsigned int count;
    __forceinline void Append(void* item)
    {
        if (count == capacity)
        {
            unsigned int newCapacity = 2 * (capacity);
            if (!(capacity > 0))
                newCapacity = 1;
            if (newCapacity != capacity)
            {
                void** newData;
                if (newCapacity > 0)
                {
                    newData = (void**)FUN_00aa1070(newCapacity * 4);
                    for (unsigned int j = 0; j < count; j++)
                        newData[j] = elements[j];
                }
                else
                    newData = 0;
                ::FUN_00aa10f0(elements);
                elements = newData;
                capacity = newCapacity;
            }
        }
        elements[(count)++] = item;
    }
};
struct A54440LinkGroup
{
    A54440LinkGroup() : entries(0), capacity(0), count(0)
    {}
    __forceinline void Append(A54440Link* item)
    {
        if (count == capacity)
        {
            unsigned int newCapacity = 2 * (capacity);
            if (!(capacity > 0))
                newCapacity = 1;
            if (newCapacity != capacity)
            {
                A54440Link** newData;
                if (newCapacity > 0)
                {
                    newData = (A54440Link**)FUN_00aa1070(newCapacity * 4);
                    for (unsigned int j = 0; j < count; j++)
                        newData[j] = entries[j];
                }
                else
                    newData = 0;
                ::FUN_00aa10f0(entries);
                entries = newData;
                capacity = newCapacity;
            }
        }
        entries[(count)++] = item;
    }
    A54440Link** entries;
    unsigned int capacity;
    unsigned int count;
};
struct A54440Array
{
    void* vtable;
    void** elements;
    unsigned short capacity;
    unsigned short count;
    unsigned short elementSize;
    unsigned short growBy;
    void FUN_00ba3aa0(unsigned int, void* const*);
    void SetCloneGroup(unsigned int index, void* const& ptr)
    {
        if (index >= capacity)
            reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00a90180(index + growBy);
        reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00ba3aa0(index, (::KeyPair **)(void *const *)(&ptr));
    }
    __forceinline void SetAtGrow(unsigned int index, void* value)
    {
        if (index >= capacity)
            reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00a90180(index + growBy);
        if (index >= count)
        {
            count = (unsigned short)(index + 1);
            if (value)
                ++elementSize;
        }
        else
        {
            if (value)
            {
                if (!elements[index])
                    ++elementSize;
            }
            else if (elements[index])
                --elementSize;
        }
        elements[index] = value;
    }
};
struct A54440Manager
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
    int currentLOD;
    unsigned int numLODs;
    A54440Array groups;
    A54440Array links;
    A54440GrowGroup defaults;
    void CloneFrom(A54440Remap* source);
};
struct A54440RefSlots
{
    void* vtable;
    volatile long referenceCount;
};
static A54440HashItem* A54440Find(A54440Hash* hash, void* key)
{
    for (A54440HashItem* item = hash->buckets[hash->BucketFor(key)]; item; item = item->next)
    {
        if (hash->Equals(key, item->source))
            return item;
    }
    return 0;
}
static void* A54440Map(A54440Hash* hash, void* key)
{
    A54440HashItem* item = A54440Find(hash, key);
    return item ? item->replacement : key;
}
struct A54440SourceLink
{
    A54440SourceLink() : ref(0)
    {}
    void* source;
    RefObject* ref;
};
typedef RefObject*(* A54440CopyRef)(RefObject*, A54440Remap*);
typedef void(* A54440FinishRef)(RefObject*, A54440Remap*);
static RefObject* A54440Copy(RefObject* ref, A54440Remap* ctx)
{
    return ((A54440Clonable*)ref)->MakeClone(ctx);
}
static void A54440Finish(RefObject* ref, A54440Remap* ctx)
{
    ((A54440Clonable*)ref)->ProcessClone(ctx);
}

__declspec(noinline) bool A54440Hash::FUN_00a53c30(A54440Manager* source, A54440Manager** out)
{
    A54440HashItem* item = A54440Find(this, source);
    if (item)
    {
        *out = (A54440Manager*)item->replacement;
        return true;
    }
    return false;
}

static __forceinline bool A54440Lookup(A54440Hash* hash, void* key, void*& replacement)
{
    A54440HashItem* entry = A54440Find(hash, key);
    if (entry)
    {
        replacement = entry->replacement;
        return true;
    }
    return false;
}

__declspec(noinline) void A54440Array::FUN_00ba3aa0(unsigned int index, void* const* pvalue)
{
    void* value = *pvalue;
    if (index >= count)
    {
        count = (unsigned short)(index + 1);
        if (value)
            ++elementSize;
    }
    else
    {
        if (value)
        {
            if (!elements[index])
                ++elementSize;
        }
        else if (elements[index])
            --elementSize;
    }
    elements[index] = value;
}

struct A54440CloneWork
{
    A54440Manager* clone;
    union
    {
        unsigned int boneIndex;
        A54440SourceLink* skinSource;
    };
    union
    {
        void* boneValue;
        unsigned int skinIndex;
    };
    union
    {
        A54440Array* boneArray;
        A54440LinkGroup* skinSet;
    };
};

// Copies this manager's groups, links, and defaults into its mapped clone, applying mapped references where available.
// @fnv 0x00a54440
void A54440Manager::CloneFrom(A54440Remap* remap)
{
    unsigned int i;
    reinterpret_cast<::NiTimeController *>(this)->ProcessClone((*(::CloningProcess *)(remap)));
    A54440CloneWork work;
    remap->map->FUN_00a53c30(this, &work.clone);
    i = 0;
    if (i < groups.count)
    {
        work.boneArray = &work.clone->groups;
        do
        {
            A54440PointerGroup* boneSource = (A54440PointerGroup*)groups.elements[i];
            if (boneSource)
            {
                A54440PointerGroup* dst = new A54440PointerGroup;
                work.boneValue = dst;
                work.boneArray->SetCloneGroup(i, work.boneValue);
                for (work.boneIndex = 0; work.boneIndex < boneSource->count; work.boneIndex++)
                {
                    void* item = boneSource->elements[work.boneIndex];
                    A54440HashItem* entry = A54440Find(remap->map, item);
                    if (entry)
                        dst->Append(entry->replacement);
                    else
                        dst->Append(item);
                }
            }
            else
            {
                work.boneValue = 0;
                work.boneArray->SetCloneGroup(i, work.boneValue);
            }
        } while (++i < groups.count);
    }
    for (i = 0; i < links.count; i++)
    {
        work.skinSet = (A54440LinkGroup*)links.elements[i];
        if (work.skinSet)
        {
            A54440LinkGroup* dst = new A54440LinkGroup;
            work.clone->links.SetAtGrow(i, dst);
            for (work.skinIndex = 0; work.skinIndex < work.skinSet->count; work.skinIndex++)
            {
                work.skinSource = (A54440SourceLink*)work.skinSet->entries[work.skinIndex];
                A54440SourceLink* skinCopy = new A54440SourceLink;
                dst->Append((A54440Link*)skinCopy);
                void* mapped;
                if (A54440Lookup(remap->map, work.skinSource->source, mapped))
                    skinCopy->source = mapped;
                else
                    skinCopy->source = work.skinSource->source;
                RefObject* newRef = A54440Copy(work.skinSource->ref, remap);
                if (skinCopy->ref != newRef)
                {
                    RefObject* oldRef = skinCopy->ref;
                    if (oldRef)
                    {
                        if (InterlockedDecrement(&oldRef->referenceCount) == 0)
                            oldRef->Destroy();
                    }
                    skinCopy->ref = newRef;
                    if (newRef)
                        InterlockedIncrement(&newRef->referenceCount);
                }
                A54440Finish(work.skinSource->ref, remap);
            }
        }
        else
        {
            work.clone->links.SetAtGrow(i, 0);
        }
    }

    for (i = 0; i < defaults.count; i++)
    {
        void* node = defaults.elements[i];
        A54440HashItem* entry = A54440Find(remap->map, node);
        if (entry)
            work.clone->defaults.Append(entry->replacement);
        else
            work.clone->defaults.Append(node);
    }
    int lod = work.clone->currentLOD;
    work.clone->currentLOD = -1;
    reinterpret_cast<::LODManager *>((work.clone))->FUN_00a541f0(lod);
}

namespace fnv_00a53d70 {

struct NiStream
{
};

struct NiRefObject
{
    virtual ~NiRefObject();
    virtual void DeleteThis();
    long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct NiTriBasedGeom;
struct NiNode;
struct NiSkinInstance : NiRefObject
{
};

template <class T> struct NiPointer
{
    T* m_pObject;
    NiPointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};

template <class T> struct NiTPrimitiveSet
{
    T* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
    unsigned int GetSize() const
    {
        return m_uiAllocatedCapacity;
    }
    T GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
    void ReplaceAt(unsigned int i, T e)
    {
        if (i >= m_uiAllocatedCapacity)
            return;
        m_pBase[i] = e;
    }
};

template <class T> struct NiTArrayStub
{
    void* vtbl;
    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    unsigned short GetSize() const
    {
        return m_usSize;
    }
    T GetAt(unsigned int i) const
    {
        return m_pBase[i];
    }
};

struct GeometrySkinInstancePair
{
    NiTriBasedGeom* m_pkGeom;
    NiPointer<NiSkinInstance> m_spInstance;
};

struct NiTimeControllerStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
};

struct BoneLODCtrl : NiTimeControllerStub
{
    int m_iLOD;
    unsigned int m_uiNumLODs;
    NiTArrayStub<NiTPrimitiveSet<NiNode*>*> m_kBoneSetArray;
    NiTArrayStub<NiTPrimitiveSet<GeometrySkinInstancePair*>*> m_kSkinInfoSets;
    NiTPrimitiveSet<NiTriBasedGeom*> m_kShapeGroups;
    void FUN_00a53d70(NiStream& kStream);
};

// Calls the base LinkObject, then loads objects into bone sets, skin pair fields, and shape groups.
// @fnv 0x00a53d70
void BoneLODCtrl::FUN_00a53d70(NiStream& kStream)
{
    reinterpret_cast<::NiTimeController *>(this)->LinkObject((::NiStream &)(kStream));

    unsigned int i;
    for (i = 0; i < m_kBoneSetArray.GetSize(); i++)
    {
        NiTPrimitiveSet<NiNode*>* pkBones = m_kBoneSetArray.GetAt(i);
        if (pkBones)
        {
            for (unsigned int j = 0; j < pkBones->GetSize(); j++)
                pkBones->ReplaceAt(j, (NiNode*)((void *)(reinterpret_cast<::NiStream *>(&(kStream))->GetLoadedObject())));
        }
    }

    for (i = 0; i < m_kSkinInfoSets.GetSize(); i++)
    {
        NiTPrimitiveSet<GeometrySkinInstancePair*>* pkSkins = m_kSkinInfoSets.GetAt(i);
        if (pkSkins)
        {
            for (unsigned int j = 0; j < pkSkins->GetSize(); j++)
            {
                GeometrySkinInstancePair* pkInfo = pkSkins->GetAt(j);
                pkInfo->m_pkGeom = (NiTriBasedGeom*)((void *)(reinterpret_cast<::NiStream *>(&(kStream))->GetLoadedObject()));
                pkInfo->m_spInstance = (NiSkinInstance*)((void *)(reinterpret_cast<::NiStream *>(&(kStream))->GetLoadedObject()));
            }
        }
    }

    for (i = 0; i < m_kShapeGroups.GetSize(); i++)
        m_kShapeGroups.ReplaceAt(i, (NiTriBasedGeom*)((void *)(reinterpret_cast<::NiStream *>(&(kStream))->GetLoadedObject())));
}
}  // namespace fnv_00a53d70

GlobalObjectO2_00a7b610* __cdecl FUN_00a55120();

struct Unknown_00c536a0
{
    bool FUN_00c536a0(int);
};
// @fnv 0x00c536a0
bool Unknown_00c536a0::FUN_00c536a0(int a)
{
    if (::FUN_00a6d0f0((::TCReg *)this, a, *(::NiStream *)nullptr) == 0)
        return false;
    return true;
}

class NiObject;
struct NiBSBoneLODController : NiObject
{
    void* m_34;
    void FUN_00c53ab0(NiStream& s);
};
// @fnv 0x00c53ab0
void NiBSBoneLODController::FUN_00c53ab0(NiStream& s)
{
    ::FUN_00a89af0((intptr_t)this);
    void* old = *(void**)((char*)this + 0x34);
    *(void**)((char*)this + 0x34) = (void*)0xffffffff;
    reinterpret_cast<::Q52Obj *>(this)->FUN_00c52960((uintptr_t)(old));
}

namespace fnv_00c53cd0 {
struct NiObject;
struct NiStream
{
};
// @fnv 0x00c53cd0
int __cdecl FUN_00c53cd0()
{
    return ::NiStream::RegisterObjectLoader(::g_012031b8_arg0, (::NiObject *(*)())(((fnv_00c53cd0::NiObject *(&)())::fnv_00c537f0::FUN_00c537f0)));
}
}  // namespace fnv_00c53cd0

struct FUN_00c53e00_shell
{
    GlobalObjectO2_00a7b610* FUN_00c53e00();
};
// @fnv 0x00c53e00
GlobalObjectO2_00a7b610* FUN_00c53e00_shell::FUN_00c53e00()
{
    return &(*reinterpret_cast<::GlobalObjectO2_00a7b610 *>(&::g_012031b8));
}

class NiControllerManager
{
  public:
    char _pad[0x34];
    int m34;
    int m38;
};
class CloningProcess
{
};
class CloneableObj
{
  public:
    char _pad[0x34];
    int m34;
    int m38;
    void FUN_00c533f0(NiControllerManager*, CloningProcess*);
};
// @fnv 0x00c533f0
void CloneableObj::FUN_00c533f0(NiControllerManager* a, CloningProcess* b)
{
    reinterpret_cast<::NiTimeControllerCM *>(this)->FUN_00a6cfe0((::NiTimeController *)(a), (*(::CloningProcess *)(b)));
    a->m34 = m34;
    a->m38 = m38;
}

struct S_00c53e10
{
    void* FUN_00c53e10(unsigned int);
public:
    void FUN_00c53e40();
};
struct ControllerBase
{
    virtual void vf();
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
    ~ControllerBase();
};
struct GroupArray
{
    virtual void vf();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usGrowBy;
    ~GroupArray()
    {
        void* data = m_pBase;
        ::FUN_00aa10f0(data);
    }
};
class FUN_00c53e40 : public ControllerBase
{
  public:
    int unk34;
    int unk38;
    GroupArray m_groups;
    ~FUN_00c53e40();
};
// @fnv 0x00c53e10
void* S_00c53e10::FUN_00c53e10(unsigned int flags)
{
    int pad[2];
    reinterpret_cast<::FUN_00c53e40 *>((this))->FUN_00c53e40::~FUN_00c53e40();
    if (flags & 1)
        ::FUN_00aa1460(this, 0x4c);
    return this;
}

struct Inner_00c53ed0
{
    virtual void F0();
    virtual void F1();
    virtual void F2();
    virtual int F3();
};
struct S_00c53ed0
{
    char _pad[0x2C];
    Inner_00c53ed0* m_ptr;
    bool FUN_00c53ed0();
};
// @fnv 0x00c53ed0
bool S_00c53ed0::FUN_00c53ed0()
{
    if (m_ptr != 0 && m_ptr->F3() != 0)
        return true;
    return false;
}

struct ObjectWriter
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void WriteObjectWithClass(void*);
};
struct BoneEntryGroup
{
    void** objects;
    int unk04;
    unsigned int count;
};
struct BoneLODControllerSave : NiBSBoneLODController
{
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
    void* m_34field;
    void* m_38field;
    int unk3c;
    BoneEntryGroup** groupArray;
    unsigned short unk44;
    unsigned short groupCount;
    void FUN_00c536d0(NiStream*);
};
// @fnv 0x00c536d0
void BoneLODControllerSave::FUN_00c536d0(NiStream* stream)
{
    BoneEntryGroup* i;
    unsigned int n;
    unsigned int groupTotal;
    void* group;
    unsigned int savedCount;
    unsigned int zero;
    unsigned int object;
    unsigned int innerCount;
    unsigned int j;

    reinterpret_cast<::FUN_00a6d730_shell *>(this)->FUN_00a6d730((*(::Stream_a6d730 *)(stream)));
    ::CallAnimCallback((::FUN_00a3da50_Owner *)(stream), (intptr_t)(&m_34field));
    ::FUN_0044adf0((::MiddleHighProcess *)(stream), (intptr_t)(&m_38field));
    savedCount = groupCount;
    ::FUN_0044adf0((::MiddleHighProcess *)(stream), (intptr_t)(&savedCount));

    for (n = 0; n < groupCount; ++n)
    {
        i = groupArray[n];
        if (i)
        {
            innerCount = i->count;
            zero = innerCount;
            ::FUN_0044adf0((::MiddleHighProcess *)(stream), (intptr_t)(&zero));
            for (groupTotal = 0; groupTotal < (j = i->count); ++groupTotal)
            {
                group = i->objects[groupTotal];
                reinterpret_cast<ObjectWriter*>(stream)->WriteObjectWithClass(group);
            }
        }
        else
        {
            object = 0;
            ::CallAnimCallback((::FUN_00a3da50_Owner *)(stream), (intptr_t)(&object));
        }
    }
}

struct RefList
{
    unsigned int* elements;
    unsigned int unk04;
    unsigned int count;
};
struct BinaryStream
{
};
struct ControllerObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    RefList** lists;
    unsigned short unk44;
    unsigned short listCount;
    void FUN_00c53a10(BinaryStream*);
};
// @fnv 0x00c53a10
void ControllerObject::FUN_00c53a10(BinaryStream* stream)
{
    reinterpret_cast<::NiTimeController *>(this)->LinkObject((*(::NiStream *)(stream)));
    for (unsigned int i = 0; i < listCount; ++i)
    {
        RefList* list = lists[i];
        if (list != 0)
        {
            unsigned int value = 0;
            uintptr_t size;
            unsigned int j;
            for (; value < (j = list->count); ++value)
            {
                size = ((uintptr_t)(reinterpret_cast<::NiStream *>((stream))->GetLoadedObject()));
                if (value >= list->count)
                {
                }
                else
                {
                    list->elements[value] = size;
                }
            }
        }
    }
}

struct S_00c53cf0_Arr
{
    void** unk00;
    int unk04;
    unsigned int unk08;
};
struct S_00c53cf0_Cls
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
    S_00c53cf0_Arr** unk40;
    short unk44;
    unsigned short unk46;
    bool FUN_00c53cf0();
};
// @fnv 0x00c53cf0
bool S_00c53cf0_Cls::FUN_00c53cf0()
{
    for (unsigned int i = 0; i < unk46; i++)
    {
        S_00c53cf0_Arr* a = unk40[i];
        if (a)
        {
            unsigned int idx;
            unsigned int size;
            for (idx = 0; idx < (size = a->unk08); idx++)
            {
                if (a->unk00[idx])
                {
                    return true;
                }
            }
        }
    }
    return false;
}


extern "C" char str_0109a388[];
extern "C" char str_0109a394[];

struct NiTPrimitiveArray_unsigned_int
{
};

struct FUN_00c53c50_Class
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;

    void FUN_00c53c50(NiTPrimitiveArray_unsigned_int* array);
};

struct FUN_00c53c50_Padding
{
    unsigned int p00;
    unsigned int p04;
    unsigned int p08;
    unsigned int p0c;
    unsigned int p10;
    unsigned int p14;
    unsigned int p18;
    unsigned int p1c;
    unsigned int p20;
    unsigned int p24;
    unsigned int p28;
    unsigned int p2c;
};

struct FUN_00c53c50_Values
{
    uintptr_t value3;
    uintptr_t value2;
    uintptr_t value1;
    uintptr_t value0;
};

// @fnv 0x00c53c50
void FUN_00c53c50_Class::FUN_00c53c50(NiTPrimitiveArray_unsigned_int* array)
{
    FUN_00c53c50_Padding padding;
    FUN_00c53c50_Values values;

    values.value3 = *(unsigned int*)&(*reinterpret_cast<::GlobalObjectO2_00a7b610 *>(&::g_012031b8));
    values.value0 = (uintptr_t)::FUN_00a7d330((const char *)(values.value3));
    reinterpret_cast<::S_0060ba10 *>((array))->FUN_0096a610((intptr_t)&(values.value0));

    values.value1 = (uintptr_t)::FUN_00a7d4d0(str_0109a394, this->unk34);
    reinterpret_cast<::S_0060ba10 *>((array))->FUN_0096a610((intptr_t)&(values.value1));

    values.value2 = (uintptr_t)::FUN_00a7d510(str_0109a388, this->unk38);
    reinterpret_cast<::S_0060ba10 *>((array))->FUN_0096a610((intptr_t)&(values.value2));
}


class FUN_00a6d220
{
  public:
    FUN_00a6d220();
    virtual ~FUN_00a6d220();
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
};

class FUN_00a54190
{
  public:
    FUN_00a54190(unsigned int uiMaxSize, unsigned int uiGrowBy);
    virtual ~FUN_00a54190();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class PrimitiveArray475 : public FUN_00a54190
{
  public:
    __forceinline PrimitiveArray475() : FUN_00a54190(0, 1)
    {
        int q;
    }
    virtual ~PrimitiveArray475();
};

class FUN_00c53d70 : public FUN_00a6d220
{
  public:
    FUN_00c53d70();
    virtual ~FUN_00c53d70();
    int m_iIndex;
    int m_iArrayLength;
    PrimitiveArray475 m_kArray;
};

// @fnv 0x00c53d70
FUN_00c53d70::FUN_00c53d70() : m_iIndex(-1), m_iArrayLength(0)
{}




// @fnv 0x00c53e40
FUN_00c53e40::~FUN_00c53e40()
{
    reinterpret_cast<::OwnerAB *>(this)->FUN_00c52880();
}

struct PoolW
{
};
struct ArrW
{
    void** m_pBase;
    unsigned int m_uiMax;
    unsigned int m_uiSize;
    ArrW(unsigned int uiMax = 0)
    {
        if (uiMax > 0)
            m_pBase = (void**)FUN_00aa1070(sizeof(void*) * uiMax);
        else
            m_pBase = 0;
        m_uiMax = 0;
        m_uiSize = 0;
    }
    unsigned int GetSize()
    {
        unsigned int n = m_uiSize;
        int aiD[14];
        return n;
    }
};
struct TArrW
{
    void* m0;
    void* m4;
    unsigned short m_us8;
    unsigned short m_usA;
    unsigned short m_usC;
    unsigned short m_usGrow;
    void SetAtGrow(unsigned int i, ArrW* const& p)
    {
        if (i >= m_us8)
            reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00a90180(i + m_usGrow);
        reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00ba3aa0(i, (::KeyPair **)&(p));
    }
};
struct TargetW
{
    char pad[0x34];
    int m_i34;
    char pad2[0x3c - 0x38];
    TArrW m_kArr;
};
struct ObjW;
struct MapW
{
};
struct StreamW
{
    MapW* m_pTaskMap;
};
class SelfW
{
  public:
    char pad[0x40];
    ArrW** m_ppkArr;
    unsigned short m44;
    unsigned short m_usElementCount;
    void FUN_00c53430(StreamW* pkStream);
};
// @fnv 0x00c53430
void SelfW::FUN_00c53430(StreamW* pkStream)
{
    int iSaved;
    {
        unsigned int i;
        reinterpret_cast<::NiTimeController *>(this)->ProcessClone((*(::CloningProcess *)(pkStream)));
        {
            TargetW* pkTarget = 0;
            reinterpret_cast<::A54440Hash *>((pkStream->m_pTaskMap))->FUN_00a53c30((::A54440Manager *)(void *)(this), (::A54440Manager **)(void *)(&pkTarget));
            for (i = 0; i < m_usElementCount; i++)
            {
                ArrW* pkSrc = m_ppkArr[i];
                if (pkSrc)
                {
                    ArrW* pkNew = new ArrW;
                    pkTarget->m_kArr.SetAtGrow(i, pkNew);
                    for (unsigned int j = 0; j < pkSrc->GetSize(); j++)
                    {
                        void* pkObj = pkSrc->m_pBase[j];
                        if (pkObj)
                        {
                            void* pkLinked = 0;
                            bool bFound = reinterpret_cast<::A54440Hash *>((pkStream->m_pTaskMap))->FUN_00a53c30((::A54440Manager *)(pkObj), (::A54440Manager **)(void *)(&pkLinked));
                            if (bFound)
                                reinterpret_cast<::NiStreamLinkIDSetShell *>((pkNew))->AppendLinkID((unsigned int *)&(pkLinked));
                            else
                                reinterpret_cast<::NiStreamLinkIDSetShell *>((pkNew))->AppendLinkID((unsigned int *)&(const void *const &)(0));
                        }
                        else
                        {
                            reinterpret_cast<::NiStreamLinkIDSetShell *>((pkNew))->AppendLinkID((unsigned int *)&(const void *const &)(0));
                        }
                    }
                }
                else
                {
                    pkTarget->m_kArr.SetAtGrow(i, 0);
                }
            }
            iSaved = pkTarget->m_i34;
            pkTarget->m_i34 = -1;
            reinterpret_cast<::Q52Obj *>((pkTarget))->FUN_00c52960(iSaved);
        }
    }
}

struct ObjX
{
    virtual void v00(), v01(), v02(), v03(), v04(), v05(), v06(), v07(), v08(), v09(), v10(), v11(), v12(), v13(),
        v14(), v15(), v16(), v17(), v18(), v19(), v20(), v21(), v22();
    virtual bool IsEqual(ObjX* pkObj);
};
struct ListX
{
    ObjX** m_pBase;
    unsigned int m_uiMax;
    unsigned int m_uiSize;
    unsigned int GetSize() const
    {
        unsigned int n = m_uiSize;
        return n;
    }
    ObjX*& GetAt(unsigned int i)
    {
        return m_pBase[i];
    }
};
struct FUN_00c53af0
{
    char pad[0x34];
    int m_i34;
    int m_i38;
    char pad3c[4];
    ListX** m_ppkLists;
    char pad44[2];
    unsigned short m_usElementCount;
    unsigned int GetCount() const
    {
        unsigned int n = m_usElementCount;
        return n;
    }
    bool IsEqual(FUN_00c53af0* pkObj);
};
// @fnv 0x00c53af0
bool FUN_00c53af0::IsEqual(FUN_00c53af0* pkObj)
{
    unsigned int i;
    if (!::FUN_00a6cc80((::TCEq *)this, (intptr_t)(pkObj), {}))
        return false;
    FUN_00c53af0* pkOther = pkObj;
    if (m_i34 != pkOther->m_i34 || m_i38 != pkOther->m_i38 || GetCount() != pkOther->m_usElementCount)
        return false;
    for (i = 0; i < m_usElementCount; i++)
    {
        ListX* pkA = m_ppkLists[i];
        ListX* pkB_fuj = pkOther->m_ppkLists[i];
        if ((pkA && !pkB_fuj) || (!pkA && pkB_fuj))
            return false;
        if (pkA && pkB_fuj)
        {
            if (pkA->GetSize() != pkB_fuj->GetSize())
                return false;
            for (unsigned int j = 0; j < pkA->GetSize(); j++)
            {
                if (!pkA->GetAt(j)->IsEqual(pkB_fuj->GetAt(j)))
                    return false;
            }
        }
    }
    return true;
}


struct MemoryManager
{
    void* Allocate(unsigned int uiSize);
};

struct NiBinaryStream
{
    typedef unsigned int (*ReadFunc)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                     unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    void BinaryRead(void* pvBuffer, unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents)
    {
        m_uiStreamFlags += m_pfnRead(this, pvBuffer, uiBytes, puiComponentSizes, uiNumComponents);
    }

    void* m_pvVtbl;
    unsigned int m_uiStreamFlags;
    ReadFunc m_pfnRead;
};

template <class T> inline void NiBinaryStreamLoad(NiBinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct LinkIDSet
{
    void FUN_00a311e0(unsigned int uiNewSize);
    unsigned int Add(const unsigned int& uiElement)
    {
        if (m_uiAllocatedCapacity == m_uiElementCount)
            FUN_00a311e0(m_uiElementCount > 0 ? (2 * m_uiElementCount) : 1);
        m_pBase[m_uiAllocatedCapacity] = uiElement;
        return m_uiAllocatedCapacity++;
    }

    unsigned int* m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};

struct NiStreamLoader
{
    void ResetStreamState()
    {
        unsigned int uiLinkID;
        NiBinaryStreamLoad(*m_pUnderlyingStream, &uiLinkID, 1);
        m_kSecondFollowingStreamField.Add(uiLinkID);
    }

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    NiBinaryStream* m_pUnderlyingStream;
    int m_iUnk250;
    LinkIDSet m_kSecondFollowingStreamField;
};


class BoneLODController;

class NiMemObject
{
  public:
};

class BoneLODControllerArray : public NiMemObject
{
  public:
    BoneLODControllerArray(unsigned int uiInitialSize = 0)
    {
        if (uiInitialSize > 0)
            m_pBase = (BoneLODController**)::FUN_00aa1070(uiInitialSize * sizeof(BoneLODController*));
        else
            m_pBase = 0;
        m_uiElementCount = uiInitialSize;
        m_uiAllocatedCapacity = 0;
    }

    BoneLODController** m_pBase;
    unsigned int m_uiElementCount;
    unsigned int m_uiAllocatedCapacity;
};

class BoneSetArray
{
  public:
    void FUN_00a90180(unsigned int uiMaxSize)
    {
        if (uiMaxSize == m_usMaxSize)
            return;

        unsigned int i;
        if (uiMaxSize < m_usSize)
        {
            for (i = uiMaxSize; i < m_usSize; i++)
            {
                if (m_pBase[i] != 0)
                {
                    m_pBase[i] = 0;
                    m_usESize--;
                }
            }
            m_usSize = (unsigned short)uiMaxSize;
        }

        BoneLODControllerArray** pSaveBase = m_pBase;
        m_usMaxSize = (unsigned short)uiMaxSize;
        if (uiMaxSize > 0)
        {
            m_pBase = (BoneLODControllerArray**)::FUN_00aa1070(m_usMaxSize * sizeof(BoneLODControllerArray*));
            for (i = 0; i < m_usSize; i++)
                m_pBase[i] = pSaveBase[i];
            for (i = m_usSize; i < m_usMaxSize; i++)
                m_pBase[i] = 0;
        }
        else
        {
            m_pBase = 0;
        }
        ::FUN_00aa10f0(pSaveBase);
    }
    void FUN_00ba3aa0(unsigned int uiIndex, BoneLODControllerArray* const& pkElement)
    {
        if (uiIndex >= m_usMaxSize)
            return;
        BoneLODControllerArray* pkOld = m_pBase[uiIndex];
        if (uiIndex >= m_usSize)
        {
            m_usSize = (unsigned short)(uiIndex + 1);
            if (pkElement != 0)
                m_usESize++;
        }
        else
        {
            if (pkElement != 0)
            {
                if (m_pBase[uiIndex] == 0)
                    m_usESize++;
            }
            else
            {
                if (m_pBase[uiIndex] != 0)
                    m_usESize--;
            }
        }
        m_pBase[uiIndex] = pkElement;
    }
    unsigned int SetAtGrow(unsigned int uiIndex, BoneLODControllerArray* const& pkElement)
    {
        if (uiIndex >= m_usMaxSize)
            reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00a90180(uiIndex + m_usGrowBy);
        reinterpret_cast<::FUN_00a41520_cls *>(this)->FUN_00ba3aa0(uiIndex, (::KeyPair **)&(pkElement));
        return uiIndex;
    }

    void* m_pvVtbl;
    BoneLODControllerArray** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class TimeController
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
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
};

class BoneLODController : public TimeController
{
  public:
    void FUN_00c53870(NiStreamLoader& kStream);

    int m_iLOD;
    unsigned int m_uiNumLODs;
    BoneSetArray m_kBoneSetArray;
};

// @fnv 0x00c53870
void BoneLODController::FUN_00c53870(NiStreamLoader& kStream)
{
    reinterpret_cast<::NiTimeController_Luna *>(this)->FUN_00a6d5e0((::NiStream &)(kStream));

    ::FUN_00a26df0((::MyStream *)(::NiStreamLoader *)(&kStream), &m_iLOD);
    ::FUN_00a26df0((::MyStream *)(::NiStreamLoader *)(&kStream), &m_uiNumLODs);

    unsigned int i;
    unsigned int uiNumLODs5 = 0;
    ::FUN_00a26df0((::MyStream *)(::NiStreamLoader *)(&kStream), &uiNumLODs5);

    for (i = 0; i < uiNumLODs5; i++)
    {
        BoneLODControllerArray* pkSet = new BoneLODControllerArray;
        m_kBoneSetArray.SetAtGrow(i, pkSet);

        unsigned int uiNumBones4 = 0;
        ::FUN_00a26df0((::MyStream *)(::NiStreamLoader *)(&kStream), &uiNumBones4);
        for (unsigned int j = 0; j < uiNumBones4; j++)
        {
            reinterpret_cast<::NiStreamLinkIDSetShell *>((pkSet))->AppendLinkID((unsigned int *)&(const ::BoneLODController *const &)(this));
            reinterpret_cast<::FUN_00a645b0_cls *>(&(kStream))->FUN_00a645b0();
        }
    }
}

namespace fnv_00c53360 {
struct Allocator_c53360
{
    virtual void slot0();
    virtual void* Allocate(unsigned int& size, unsigned int& alignment, int eventType, bool accurate, const char* file,
                           int line, const char* function);
};
struct Manager_c53360
{
    Allocator_c53360* allocator;
};
extern Manager_c53360* DAT_011f6080;
class NiMemObject
{
  public:
    static void* operator new(std::size_t size)
    {
        unsigned int requested = size ? size : 1;
        unsigned int alignment = 4;
        return DAT_011f6080->allocator->Allocate(requested, alignment, 1, true, 0, -1, 0);
    }
    static void operator delete(void* ptr);
};
class FUN_00c53d70 : public NiControllerManager, public NiMemObject
{
  public:
    int unk3C, unk40, unk44, unk48;
    FUN_00c53d70();
};
class CloneOwner_c53360 : public CloneableObj
{
  public:
    NiControllerManager* FUN_00c53360(CloningProcess* process);
};
// @fnv 0x00c53360
NiControllerManager* CloneOwner_c53360::FUN_00c53360(CloningProcess* process)
{
    NiControllerManager* result = new FUN_00c53d70;
    this->FUN_00c533f0(result, process);
    return result;
}
}  // namespace fnv_00c53360

namespace fnv_00c537f0 {

struct FUN_00c53d70
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    FUN_00c53d70();
};
// @fnv 0x00c537f0
FUN_00c53d70* __cdecl FUN_00c537f0()
{
    return new FUN_00c53d70;
}
}  // namespace fnv_00c537f0
#include "generated/data/gamebryo2.2/corelibs/nianimation/nibonelodcontroller.inc"
