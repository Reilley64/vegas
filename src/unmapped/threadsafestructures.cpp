#include "AutoMemContext.h"

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/C44D510Cache.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/FUN_0040fbf0_shell.h"
#include "fnv/decl/FUN_006665a0_shell.h"
#include "fnv/decl/FUN_006ebde0_shell.h"
#include "fnv/decl/FUN_006ec9b0_Class.h"
#include "fnv/decl/MapMarkerData.h"
#include "fnv/decl/Owner_44e550.h"
#include "fnv/decl/Queue_44e680.h"
#include "fnv/decl/TSMap.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Walker_44ea60.h"
#include "fnv/decl/fnv_00722f60__SL.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0040b000.h"
#include "fnv/symbols_0044d000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_01017000.h"
extern int DAT_01017458;

struct FUN_0044b4b0_Class
{
    int* p;
    void FUN_0044b4b0();
};

// @fnv 0x0044b4b0
void FUN_0044b4b0_Class::FUN_0044b4b0()
{
    p = &DAT_01017458;
}

struct FUN_0044b730_Class
{
    int* p;
    char pad04[0x18 - 0x4];
    long m_lLock;
    void FUN_0044b730();
};
// @fnv 0x0044b730
void FUN_0044b730_Class::FUN_0044b730()
{
    ::WaitForSingleObjectEx(&m_lLock);
}


struct FUN_0044bbc0_Class
{
    char pad00[0x18];
    unsigned int m_uiLock;
    void FUN_0044bbc0();
};

// @fnv 0x0044bbc0
void FUN_0044bbc0_Class::FUN_0044bbc0()
{
    ::FUN_0040b460(&m_uiLock);
}

struct FUN_0044c1c0_Class
{
    bool IsGreaterOrEqual(unsigned int a, unsigned int b);
};

// @fnv 0x0044c1c0
bool FUN_0044c1c0_Class::IsGreaterOrEqual(unsigned int auiValue, unsigned int auiThreshold)
{
    return auiValue >= auiThreshold;
}

struct FUN_0044f220_Node;
struct FUN_0044f200_Class
{
    int* p;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_0044f220_Node* m_pHead;
    int m_iArrayLength;
    void FUN_0044f200();
    void FilterListByQueueData();
};

// @fnv 0x0044f200
void FUN_0044f200_Class::FUN_0044f200()
{
    while (m_iArrayLength)
        FilterListByQueueData();
}

struct RecursiveSpinLock
{
public:
    void FUN_0040fba0();
};
struct FUN_0044bd60_Class
{
    void* m;
    void* n;
    void* o;
    void* p;
    void* q;
    void* r;
    void* s;
    void* t;
    RecursiveSpinLock lock;
    void* FUN_00449f80();
    bool FUN_0044bd60(void* a, void* b);
};
using AutoMemHelper = ::AutoMemContext;
struct InterfacedClass
{
    InterfacedClass();
    ~InterfacedClass();
    virtual void Interface();
};
struct CF_0081c630
{
    int v;
    CF_0081c630();
};
struct SL
{
    void* item;
    void* next;
    SL();
};
class bhkRigidBody;
template <class T> class LockFreeQueue
{
  public:
    class QueueDeleteManagerTag
    {
    };
};
template <class T> class ThreadInterfaceManager
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    ThreadInterfaceManager(unsigned int);
};

struct FUN_0044c920 : InterfacedClass
{
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;
    FUN_0044c920(unsigned int a, unsigned int buckets, int c);
};

// Allocates bucket array, slot array and manager, and initializes the bucket count, parameter and counter fields.
// @fnv 0x0044c920
FUN_0044c920::FUN_0044c920(unsigned int auiSlotCount, unsigned int auiBucketCount, int aiParam)
{
    AutoMemHelper mem(6, true, ::kThreadSafeStructuresSourceFile, 0x390);
    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new std::uintptr_t[auiSlotCount * 3];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(auiSlotCount);
}

struct FUN_0044c760_class : InterfacedClass
{
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_0044c760_class(unsigned int a, unsigned int b, unsigned int c);
};

// Initializes the object: allocates bucket and slot arrays, stores the bucket count and parameter, and creates the manager.
// @fnv 0x0044c760
FUN_0044c760_class::FUN_0044c760_class(unsigned int auiSlotCount, unsigned int auiBucketCount, unsigned int aiParam)
    : InterfacedClass()
{
    AutoMemHelper autoMemHelper(6, true, ::kThreadSafeStructuresSourceFile, 0x390);

    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new std::uintptr_t[3 * auiSlotCount];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(auiSlotCount);
}


struct FUN_006ec660 : InterfacedClass
{
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_006ec660(unsigned int a, unsigned int b, int c);
};

// Allocates the bucket array, slot array and manager from the given sizes, storing the counts and parameter.
// @fnv 0x006ec660
FUN_006ec660::FUN_006ec660(unsigned int auiSlotCount, unsigned int auiBucketCount, int aiParam)
{
    AutoMemHelper memHelper(6, true, ::kThreadSafeStructuresSourceFile, 0x390);

    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new std::uintptr_t[auiSlotCount * 3];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(auiSlotCount);
}

template <class T> class NiPointer
{
};
class QueuedReference
{
};

template <> class LockFreeQueue<NiPointer<QueuedReference> >
{
  public:
    class LockFreeQueueEntry
    {
      public:
        void* m_pFirst;
        void* m_pSecond;
        LockFreeQueueEntry();
    };
};

typedef LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag FUN_0044b500_LockFreeQueueInterface;

struct FUN_0044b500 : public InterfacedClass
{
    LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueEntry* m_pHead;
    LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueEntry* m_pTail;
    void* m_pIntegerData;
    std::uintptr_t* m_pSlots;
    ThreadInterfaceManager<FUN_0044b500_LockFreeQueueInterface>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_0044b500(unsigned int numBuckets, void* value);
};

// @fnv 0x0044b500
FUN_0044b500::FUN_0044b500(unsigned int numBuckets, void* value)
{
    AutoMemHelper autoMemHelper(6, true, ::kThreadSafeStructuresSourceFile, 0xfd);

    m_iArrayLength = 0;
    m_pHead = new LockFreeQueue<NiPointer<QueuedReference> >::LockFreeQueueEntry;
    m_pTail = m_pHead;
    m_pIntegerData = value;
    m_pSlots = new std::uintptr_t[numBuckets * 2];
    m_pManager = new ThreadInterfaceManager<FUN_0044b500_LockFreeQueueInterface>(numBuckets);
}

extern int DAT_0108864c;

struct FUN_00906160
{
    InterfacedClass m_interface;
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    unsigned char m_kNode[8];

    FUN_00906160(int a, unsigned int b, int c);
};

// @fnv 0x00906160
FUN_00906160::FUN_00906160(int a, unsigned int auiBucketCount, int aiParam)
{
    *reinterpret_cast<void**>(&m_interface) = &DAT_0108864c;
    new ((void *)(reinterpret_cast<SL*>(m_kNode))) ::fnv_00722f60::SL();

    AutoMemHelper helper(6, true, ::kThreadSafeStructuresSourceFile, 0x390);

    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new std::uintptr_t[a * 3];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(a);
}

struct Item
{
    bool FUN_00528bb0();
};
struct Iteration
{
    int unk00;
    unsigned int index;
    unsigned int value;
};
struct FUN_0044b8d0_Class
{
    void* vfptr;
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    int unk0c, unk10, unk14, unk18, unk1c;
    RecursiveSpinLock lock;
    Item* FUN_00449f80();
    Item* FUN_00449f80(unsigned int);
    bool ProcessIteration(Iteration*, unsigned int*, std::intptr_t, bool);
};
struct FUN_0044c000_Target
{
    virtual void v00() = 0;
    virtual void v01() = 0;
    virtual void v02() = 0;
    virtual void v03() = 0;
    virtual void v04() = 0;
    virtual void v05() = 0;
    virtual void v06() = 0;
    virtual void v07() = 0;
    virtual void v08() = 0;
    virtual int v09(unsigned int uiKey) = 0;
};

struct FUN_0044c000_cls
{
    FUN_0044c000_Target* m_00;

    void FUN_0044c000(unsigned int uiKey, const QHeadPtr& rValue, unsigned char ucReplace);
};

// Hashes uiKey with m_00's virtual 9 and inserts rValue under it, replacing an existing value when ucReplace is set.
// @fnv 0x0044c000
void FUN_0044c000_cls::FUN_0044c000(unsigned int uiKey, const QHeadPtr& rValue, unsigned char ucReplace)
{
    reinterpret_cast<::TSMap *>(this)->InsertOrReplace(uiKey, m_00->v09(uiKey), rValue, ucReplace);
}

struct FUN_0044c270 : InterfacedClass
{
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_0044c270(unsigned int a, unsigned int buckets, int c);
};

// Initializes the object: allocates bucket and slot arrays, stores the bucket count and parameter, and creates the manager.
// @fnv 0x0044c270
FUN_0044c270::FUN_0044c270(unsigned int a, unsigned int auiBucketCount, int aiParam)
{
    AutoMemHelper mem(6, true, ::kThreadSafeStructuresSourceFile, 0x390);
    m_iArrayLength = 0;
    m_uiBuckets = auiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new std::uintptr_t[a * 3];
    m_iParam = aiParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(a);
}

struct BaseInterface
{
    virtual void Interface();
    void FUN_0044b4b0();
    ~BaseInterface()
    {
        FUN_0044b4b0();
    }
};
struct FUN_0044c3f0 : BaseInterface
{
    void* first;
    void* unused;
    void* second;
    ~FUN_0044c3f0();
};

struct TSNode;
struct TSNodePtr
{
    TSNode* p;
};
struct TSNode
{
    int unk00;
    int unk04;
    TSNodePtr m_next;
};
struct TSManager
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    TSManager(unsigned int);
    ~TSManager();
};

struct TSHashTable
{
    void* vtbl;
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    TSNodePtr* m_pBuckets;
    int m_iParam;
    TSManager* m_pManager;
    int m_iArrayLength;
    int unk1C;
    RecursiveSpinLock m_lock;

    void FUN_0044c480(bool bNoRecreate);
};
// Calls FUN_0044c480(1), then frees the second and first pointers with operator delete.
// @fnv 0x0044c3f0
FUN_0044c3f0::~FUN_0044c3f0()
{
    reinterpret_cast<::TSHashTable *>(this)->FUN_0044c480(1);
    void* savedSecond = second;
    ::FUN_00401030(savedSecond);
    void* savedFirst = first;
    ::FUN_00401030(savedFirst);
}

struct QueueEntry44c640
{
};
struct QueueIter44c640
{
    int unk00;
    unsigned int uiIndex;
    void* pItem;
};
struct Queue44c640
{
    void* vfptr;
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    RecursiveSpinLock lock;
    QueueEntry44c640* GetEntry();
    bool TryGetNextEntry(QueueIter44c640* iter, void** out, std::intptr_t param, bool repeat);
};

class C44C8E0Hasher
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual unsigned int Hash(int iKey);
};

class C44C8E0Map
{
  public:
    C44C8E0Hasher* m_pkHasher;

    int LookupBucket(int iKey, C44D510Pointer& spResult);
};
// Locks the object's lock, looks up key a in the map FUN_00449f80 returns (the value goes to b), unlocks, and returns whether it was found.
// @fnv 0x0044bd60
bool FUN_0044bd60_Class::FUN_0044bd60(void* a, void* b)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool r = ((bool)(reinterpret_cast<::C44C8E0Map *>((FUN_00449f80()))->LookupBucket(static_cast<int>(reinterpret_cast<std::intptr_t>(a)), *static_cast<::C44D510Pointer *>(b))));
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return r;
}

// Hashes iKey with the map's hasher and looks it up, copying the value into spResult; returns whether it was found.
// @fnv 0x0044c8e0
int C44C8E0Map::LookupBucket(int iKey, C44D510Pointer& spResult)
{
    return ((int)(reinterpret_cast<::C44D510Cache *>(this)->LookupAndUnlock(iKey, m_pkHasher->Hash(iKey), spResult)));
}


struct CleanupBaseDtor
{
    virtual void unk00();
    ~CleanupBaseDtor();
};

struct FUN_0044cae0_cls : CleanupBaseDtor
{
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    void* m_pBuckets;

    ~FUN_0044cae0_cls();
};

// @fnv 0x0044cae0
FUN_0044cae0_cls::~FUN_0044cae0_cls()
{
    reinterpret_cast<::TSHashTable *>(this)->FUN_0044c480(1);
    FUN_00401030(m_pBuckets);
    FUN_00401030(m_pSlots);
}

struct Dispatch
{
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A(unsigned int value);
    void FUN_0044dde0(unsigned int* argument);
};
// Locks the table, deletes m_pManager, frees every bucket node, and unless bNoRecreate recreates m_pManager with the saved param, then unlocks.
// @fnv 0x0044c480
void TSHashTable::FUN_0044c480(bool bNoRecreate)
{
    AutoMemHelper memContext2(6, true, ::kThreadSafeStructuresSourceFile, 0x42c);
    if (m_pManager == 0)
        return;
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(m_lock))->FUN_0040fbf0((char *)(0));
    unsigned int aParam = ((unsigned int)(::FUN_00559450((int *)(m_pManager))));
    delete m_pManager;
    m_pManager = 0;
    m_iArrayLength = 0;
    for (unsigned int i = 0; i < m_uiBuckets; i++)
    {
        TSNode* pNode = ((::TSNode *)(::ClearLowBit(&(m_pBuckets[i]))));
        reinterpret_cast<::FUN_006665a0_shell *>(&(m_pBuckets[i]))->FUN_006665a0();
        while (pNode)
        {
            TSNode* next = ((::TSNode *)(::ClearLowBit(&(pNode->m_next))));
            reinterpret_cast<::FUN_006665a0_shell *>(&(pNode->m_next))->FUN_006665a0();
            pNode->unk04 = 0;
            reinterpret_cast<::Dispatch *>(this)->FUN_0044dde0((unsigned int *)(pNode));
            pNode = next;
        }
    }
    if (!bNoRecreate)
        m_pManager = new TSManager(aParam);
    reinterpret_cast<::RecursiveSpinLock *>(&(m_lock))->FUN_0040fba0();
}
// Calls Slot0A with the value pointed to by argument, then passes argument to FUN_00401030.
// @fnv 0x0044dde0
void Dispatch::FUN_0044dde0(unsigned int* puiValue)
{
    Slot0A(*puiValue);
    void* target = puiValue;
    FUN_00401030(target);
}

struct FUN_0044de20_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned char unk0C;
    bool IsFlagSet();
};
// Locks, walks the iteration to find a matching item via FUN_00449f80, stores its value in result, and returns whether the item passes FUN_00528bb0.
// @fnv 0x0044b8d0
bool FUN_0044b8d0_Class::ProcessIteration(Iteration* pIteration, unsigned int* puiResult, std::intptr_t extra,
                                          bool retry)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool success = false;
    if (reinterpret_cast<::FUN_006ebde0_shell *>((pIteration))->FUN_006ebde0())
    {
        success = false;
    }
    else
    {
        while (true)
        {
            if (!reinterpret_cast<::FUN_0044de20_cls *>((pIteration))->IsFlagSet())
            {
                success = reinterpret_cast<::Owner_44e550 *>((FUN_00449f80()))->FUN_0044e550(pIteration->index, (int *)&pIteration->value, reinterpret_cast<::QHeadPtrDest_44e550 *>(extra));
                reinterpret_cast<::MapMarkerData *>((pIteration))->SetVisible(true);
            }
            else
            {
                success = reinterpret_cast<::Queue_44e680 *>((FUN_00449f80()))->FindEntry(pIteration->index, (int *)&pIteration->value, reinterpret_cast<::Ptr_44e680 *>(extra));
            }
            if (!success)
            {
                pIteration->index++;
                if (pIteration->index >= m_uiBuckets)
                {
                    reinterpret_cast<::MapMarkerData *>((pIteration))->SetTravelLocation(true);
                }
                else if (retry)
                {
                    reinterpret_cast<::MapMarkerData *>((pIteration))->SetVisible(false);
                    continue;
                }
            }
            else
            {
                *puiResult = pIteration->value;
            }
            break;
        }
    }
    if (success)
    {
        success = FUN_00449f80(*puiResult)->FUN_00528bb0();
    }
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return success;
}
// @fnv 0x0044c640
bool Queue44c640::TryGetNextEntry(QueueIter44c640* iter, void** out, std::intptr_t param, bool repeat)
{
    reinterpret_cast<::FUN_0040fbf0_shell *>(&(lock))->FUN_0040fbf0((char *)(0));
    bool result = false;
    if (reinterpret_cast<::FUN_006ebde0_shell *>((iter))->FUN_006ebde0())
    {
        result = false;
    }
    else
    {
        while (1)
        {
            if (!reinterpret_cast<::FUN_0044de20_cls *>((iter))->IsFlagSet())
            {
                result = reinterpret_cast<::Walker_44ea60 *>((GetEntry()))->FindAndProcessNode(iter->uiIndex, (int *)&iter->pItem, reinterpret_cast<int *>(param));
                reinterpret_cast<::MapMarkerData *>((iter))->SetVisible(true);
            }
            else
            {
                result = reinterpret_cast<::FUN_006ec9b0_Class *>((GetEntry()))->FUN_0044eb80(iter->uiIndex, (int *)&iter->pItem, reinterpret_cast<int *>(param));
            }
            if (!result)
            {
                iter->uiIndex++;
                if (iter->uiIndex >= m_uiBuckets)
                {
                    reinterpret_cast<::MapMarkerData *>((iter))->SetTravelLocation(true);
                }
                else if (repeat)
                {
                    reinterpret_cast<::MapMarkerData *>((iter))->SetVisible(false);
                    continue;
                }
            }
            else
            {
                *out = iter->pItem;
            }
            break;
        }
    }
    reinterpret_cast<::RecursiveSpinLock *>(&(lock))->FUN_0040fba0();
    return result;
}
// @fnv 0x0044de20
bool FUN_0044de20_cls::IsFlagSet()
{
    return (this->unk0C & 1) ? true : false;
}

struct FUN_006661e0 : InterfacedClass
{
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ~FUN_006661e0();
};
// Calls FUN_0044c480(1), then deletes m_pBuckets and m_pSlots.
// @fnv 0x006661e0
FUN_006661e0::~FUN_006661e0()
{
    reinterpret_cast<::TSHashTable *>(this)->FUN_0044c480(1);
    delete m_pBuckets;
    delete m_pSlots;
}

struct FUN_006ec870 : InterfacedClass
{
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;

    ~FUN_006ec870();
};

// @fnv 0x006ec870
FUN_006ec870::~FUN_006ec870()
{
    reinterpret_cast<::TSHashTable *>(this)->FUN_0044c480(1);
    delete m_pBuckets;
    delete m_pSlots;
}

using AutoMemHelper44B = ::AutoMemContext;

extern const char g_pcFile44B[];

class Container44B;

class Iterator44B
{
  public:
    Iterator44B(Container44B* pkContainer, void** ppvFirst, void** ppvLast);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};

class Container44B
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void** m_ppvBuckets;

    Iterator44B* CreateBucketIterator(int iSubBucketIndex);
};

// @fnv 0x0044b660
Iterator44B* Container44B::CreateBucketIterator(int iBucketIndex)
{
    AutoMemHelper44B kHelper(6, true, g_pcFile44B, 0x95);
    return new Iterator44B(this, &m_ppvBuckets[iBucketIndex * 2], &m_ppvBuckets[iBucketIndex * 2 + 1]);
}


struct FUN_0044f220_Queue
{
    void* vtable;
    void* m_pData;
    int FUN_0044f3e0();
};

struct FUN_0044f220_Node
{
    int unk00;
    int unk04;
};

struct FUN_0044f220_Class : FUN_0044f200_Class
{
};

// Copies the queue's data into a temporary array, keeps only list nodes whose address appears in it, relinks them, and stores the kept count.
// @fnv 0x0044f220
void FUN_0044f200_Class::FilterListByQueueData()
{
    AutoMemHelper guard5(6, true, ::kThreadSafeStructuresSourceFile, 0x362);
    int numSlots = ((FUN_0044f220_Queue*)p)->FUN_0044f3e0() * 3;
    std::uintptr_t* pArray = new std::uintptr_t[numSlots];
    ::__memcpy(pArray, ((FUN_0044f220_Queue*)p)->m_pData, numSlots * sizeof(std::uintptr_t));
    FUN_0044f220_Node* pTail = 0;
    int iCount2 = 0;
    while (((FUN_0044f220_Class*)this)->m_pHead != 0)
    {
        FUN_0044f220_Node* pEntry2 = ((FUN_0044f220_Class*)this)->m_pHead;
        ((FUN_0044f220_Class*)this)->m_pHead = ((::FUN_0044f220_Node *)(reinterpret_cast<::Callees *>((((FUN_0044f220_Class*)this)->m_pHead))->FUN_00726070()));
        bool found4 = false;
        for (unsigned int i2 = 0; i2 < (unsigned int)numSlots; ++i2)
        {
            if (reinterpret_cast<std::uintptr_t>(pEntry2) == pArray[i2])
            {
                found4 = true;
                break;
            }
        }
        if (found4)
        {
            reinterpret_cast<::CombatProcedure *>((pEntry2))->Initialize((::CombatController *)(pTail));
            pTail = pEntry2;
            ++iCount2;
        }
        else
        {
            reinterpret_cast<::CombatProcedure *>((pEntry2))->Initialize((::CombatController *)(void *)(0));
            reinterpret_cast<::Dispatch *>((((FUN_0044f220_Queue*)p)))->FUN_0044dde0((unsigned int *)(pEntry2));
        }
    }
    delete[] pArray;
    ((FUN_0044f220_Class*)this)->m_pHead = pTail;
    ((FUN_0044f220_Class*)this)->m_iArrayLength = iCount2;
}

struct FUN_00665cb0 : InterfacedClass
{
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>* m_pManager;
    int m_iArrayLength;
    int unk1C;
    SL m_kNode;

    FUN_00665cb0(unsigned int a, unsigned int buckets, int c);
};

// Allocates bucket array, slot array and manager, and stores the bucket count and parameter.
// @fnv 0x00665cb0
FUN_00665cb0::FUN_00665cb0(unsigned int a, unsigned int uiBucketCount, int iParam)
{
    AutoMemHelper mem(6, true, ::kThreadSafeStructuresSourceFile, 0x390);
    m_iArrayLength = 0;
    m_uiBuckets = uiBucketCount;
    m_pBuckets = new CF_0081c630[m_uiBuckets];
    m_pSlots = new std::uintptr_t[a * 3];
    m_iParam = iParam;
    m_pManager = new ThreadInterfaceManager<LockFreeQueue<bhkRigidBody*>::QueueDeleteManagerTag>(a);
}

struct HashBase44c1e0
{
    virtual void Interface();
    ~HashBase44c1e0();
};
struct HashMap44c1e0 : HashBase44c1e0
{
    std::uintptr_t* m_pSlots;
    unsigned int m_uiBuckets;
    CF_0081c630* m_pBuckets;
    int m_iParam;
    ~HashMap44c1e0();
};
// Destructor that calls FUN_0044c480(1) and deletes m_pBuckets and m_pSlots.
// @fnv 0x0044c1e0
HashMap44c1e0::~HashMap44c1e0()
{
    reinterpret_cast<::TSHashTable *>(this)->FUN_0044c480(1);
    delete m_pBuckets;
    delete m_pSlots;
}

#include "generated/data/unmapped/threadsafestructures.inc"
