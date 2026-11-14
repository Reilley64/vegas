
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include <new>
#include "fnv/decl/FUN_00438af0_Class.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_004a49e0_shell.h"
#include "fnv/decl/FUN_004edf70.h"
#include "fnv/decl/fnv_004edfe0__FUN_004edfe0.h"
#include "fnv/decl/fnv_00adddd0__FUN_00a1b940.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_004ed000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01023000.h"
#include <cstdint>
#include "fnv/symbols_004b0000.h"
#include "fnv/symbols_011f4000.h"
#include <windows.h>

struct FUN_004edb30_t
{
    void* vtbl;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    void FUN_004edb30();
    void* FUN_004edd50(unsigned int flags);
};

// Calls FUN_004edb30, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x004edd50
void* FUN_004edb30_t::FUN_004edd50(unsigned int flags)
{
    FUN_004edb30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

extern int DAT_010232b4;

class NiTMallocInterface
{
};

struct NiPointerListBase
{
    void* p;
    void* q;
    void FUN_004edc60();
};

// @fnv 0x004edc60
void NiPointerListBase::FUN_004edc60()
{
    p = &DAT_010232b4;
    ::FUN_004ede70((void**)q);
}

extern int DAT_010232bc;
struct FUN_004edf70_t
{
};
struct FUN_004edc90_t
{
    void* FUN_004edc90(int a, int b);
};
// Calls FUN_004edf70 with the two arguments, then stores the address of DAT_010232bc as the object's first field and returns this.
// @fnv 0x004edc90
void* FUN_004edc90_t::FUN_004edc90(int a, int b)
{
    new ((void *)(reinterpret_cast<FUN_004edf70_t*>(this))) ::FUN_004edf70(a, b);
    *reinterpret_cast<int**>(this) = &DAT_010232bc;
    return this;
}

namespace fnv_004edcc0 {
struct ActorCombatGroup;
class NiTMallocInterface
{
};
struct FUN_004edcc0_t
{
    void* m;
    ActorCombatGroup** m_pBase;
    void InitAndDeallocate();
};
// Sets m to the address of DAT_010232c4, then deallocates m_pBase via NiTMallocInterface::Deallocate.
// @fnv 0x004edcc0
void FUN_004edcc0_t::InitAndDeallocate()
{
    m = &DAT_010232c4;
    ::FUN_004ede70(m_pBase);
}
}  // namespace fnv_004edcc0

extern int DAT_010232cc;
struct FUN_004edcf0_t
{
    int* InitWithGlobal(int, int);
};
// Calls FUN_004edfe0 with the two arguments, stores the address of DAT_010232cc at the start of this object, and returns this.
// @fnv 0x004edcf0
int* FUN_004edcf0_t::InitWithGlobal(int a, int b)
{
    new ((void *)this) ::fnv_004edfe0::FUN_004edfe0(a, b);
    *reinterpret_cast<int**>(this) = &DAT_010232cc;
    return reinterpret_cast<int*>(this);
}


// @fnv 0x004ede70
void __cdecl FUN_004ede70(void* apMemory)
{
    ::FUN_00aa10f0(apMemory);
}

extern int DAT_01023254;
struct MyMap
{
};
struct FUN_004eda30_t
{
    void* vtbl;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
    unsigned int m_uiCount;
    void FUN_004eda30();
};
// @fnv 0x004eda30
void FUN_004eda30_t::FUN_004eda30()
{
    vtbl = &DAT_01023254;
    reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)(void*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(m_ppkHashTable);
}

namespace fnv_004edc30 {
struct MyMap
{
    void* vtbl;
    unsigned int m_uiHashSize;
    void* m_ppkHashTable;
};
struct FUN_004edc30_t
{
    void ClearAndFreeMap();
};
// @fnv 0x004edc30
void FUN_004edc30_t::ClearAndFreeMap()
{
    ((MyMap*)this)->vtbl = &::DAT_01023294;
    reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(((MyMap*)this)->m_ppkHashTable);
}
}  // namespace fnv_004edc30

class Script;
struct NiTListItem
{
    NiTListItem* m_pNext;
    void* m_pkElement;
};
struct NiTPointerListBaseRaw
{
    NiTListItem* m_pkHead;
    NiTListItem* m_pkTail;
    int m_uiCount;
    void FUN_004ed900();
};
// Walks the list from m_pkHead, deleting each item via DeleteItem, then resets m_uiCount, m_pkHead and m_pkTail.
// @fnv 0x004ed900
void NiTPointerListBaseRaw::FUN_004ed900()
{
    NiTListItem* pkCurr = m_pkHead;
    while (pkCurr)
    {
        NiTListItem* pkDel = pkCurr;
        pkCurr = pkCurr->m_pNext;
        reinterpret_cast<::FUN_004a49e0_shell *>(this)->FUN_004a49e0(pkDel);
    }
    m_uiCount = 0;
    m_pkHead = 0;
    m_pkTail = 0;
}


struct FUN_004ed960
{
    void* vtbl;
    unsigned int size;
    void* data;
    unsigned int count;
    void* Init(unsigned int size);
};

// Sets the vtable, stores sz in size, allocates size*4 bytes for data, zeroes them, and returns this.
// @fnv 0x004ed960
void* FUN_004ed960::Init(unsigned int uiSize)
{
    vtbl = (void*)&DAT_01023254;
    size = uiSize;
    count = 0;
    unsigned int n = size << 2;
    data = ::FUN_00aa1070(n);
    ::FUN_00403d30(data, 0, size << 2);
    return this;
}

extern int DAT_01023274;
struct FUN_004eda60_t
{
    void* vtbl;
    unsigned int size;
    void* data;
    unsigned int count;
    void* FUN_004eda60(unsigned int count);
};
// Sets the vtable, stores count, allocates count*4 bytes, zeroes the buffer, and returns this.
// @fnv 0x004eda60
void* FUN_004eda60_t::FUN_004eda60(unsigned int uiCount)
{
    unsigned int uiBytes;
    vtbl = &DAT_01023274;
    size = uiCount;
    count = 0;
    uiBytes = size * 4;
    data = ::FUN_00aa1070(uiBytes);
    ::FUN_00403d30(data, 0, size * 4);
    return this;
}

struct FUN_004edb60_t
{
    void* vtbl;
    int size;
    void* data;
    int count;
    int* FUN_004edb60(int size);
};
// Sets the vtable, stores size, allocates size*4 bytes, zeroes the buffer and returns this.
// @fnv 0x004edb60
int* FUN_004edb60_t::FUN_004edb60(int iSize)
{
    int tmp;
    vtbl = &DAT_01023294;
    size = iSize;
    count = 0;
    tmp = size << 2;
    data = ::FUN_00aa1070((unsigned int)tmp);
    ::FUN_00403d30(data, 0, (unsigned int)(size << 2));
    return (int*)this;
}

extern int DAT_01023234;
struct FUN_004edc30_t
{
    virtual ~FUN_004edc30_t();
};
struct FUN_004edbd0 : FUN_004edc30_t
{
    virtual ~FUN_004edbd0();
};
// @fnv 0x004edbd0
FUN_004edbd0::~FUN_004edbd0()
{
    reinterpret_cast<::FUN_00438af0_Class *>(this)->FUN_00438af0();
}

namespace fnv_004edd80 {
struct FUN_004edc30_t
{
    void* FUN_004edd80(unsigned int flags);
};
// @fnv 0x004edd80
void* FUN_004edc30_t::FUN_004edd80(unsigned int flags)
{
    reinterpret_cast<::fnv_004edc30::FUN_004edc30_t *>(this)->ClearAndFreeMap();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_004edd80

struct FUN_004eddb0_t
{
    void* FUN_004eddb0(unsigned int flags);
};
// @fnv 0x004eddb0
void* FUN_004eddb0_t::FUN_004eddb0(unsigned int flags)
{
    ((NiPointerListBase*)this)->FUN_004edc60();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004ebb30_shell
{
    void FUN_004ebb30();
    void* FUN_004edde0(unsigned int flags);
};
// Calls FUN_004ebb30, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x004edde0
void* FUN_004ebb30_shell::FUN_004edde0(unsigned int flags)
{
    FUN_004ebb30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_004ebb50_shell
{
    void* FUN_004ede10(unsigned int flags);
public:
    void FUN_004ebb50();
};
// @fnv 0x004ede10
void* FUN_004ebb50_shell::FUN_004ede10(unsigned int flags)
{
    reinterpret_cast<::fnv_004edcc0::FUN_004edcc0_t *>(this)->InitAndDeallocate();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

namespace fnv_004ede40 {
struct FUN_004ebb50_shell
{
    void* FUN_004ede40(unsigned int flags);
};
// Calls FUN_004ebb50, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x004ede40
void* FUN_004ebb50_shell::FUN_004ede40(unsigned int flags)
{
    reinterpret_cast<::FUN_004ebb50_shell *>(this)->FUN_004ebb50();
    if (flags & 1)
        operator delete(this);
    return this;
}
}  // namespace fnv_004ede40

struct NiTMapItem;
struct NodePoolView
{
};
struct ListItemAe8bf0
{
    ListItemAe8bf0* m_pkNext;
    ListItemAe8bf0* m_pkPrev;
    void* m_element;
};
struct FUN_00ae8bf0_t
{
    ListItemAe8bf0* m_pkHead;
    ListItemAe8bf0* m_pkTail;
    NodePoolView m_kPool;
    void AddItem(const void* element);
};
// Allocates a list node from the node pool, stores the element's first pointer in it, and inserts the node into the list.
// @fnv 0x00ae8bf0
void FUN_00ae8bf0_t::AddItem(const void* element)
{
    NiTMapItem* node;
    {
        int a;
        int b;
        int c;
        int d;
        int e;
        int f;
        int g;
        node = ((::NiTMapItem *)(reinterpret_cast<::FUN_0043a010_shell *>(&m_kPool)->FUN_0043a010()));
    }
    reinterpret_cast<ListItemAe8bf0*>(node)->m_element = *(void* const*)element;
    reinterpret_cast<::fnv_00adddd0::FUN_00a1b940 *>(this)->FUN_00a11db0((::fnv_00adddd0::MsgNode *)(node));
}

struct FUN_004edd20_shell
{
    void* FUN_004edd20(unsigned int flags);
};
// @fnv 0x004edd20
void* FUN_004edd20_shell::FUN_004edd20(unsigned int flags)
{
    ((FUN_004eda30_t*)this)->FUN_004eda30();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_00438af0_t
{
};
struct FUN_004eda30
{
    virtual ~FUN_004eda30();
};
struct FUN_004ed9d0 : FUN_004eda30
{
    virtual ~FUN_004ed9d0();
};
// Destructor that forwards to FUN_00438af0 on this object.
// @fnv 0x004ed9d0
FUN_004ed9d0::~FUN_004ed9d0()
{
    reinterpret_cast<::FUN_00438af0_Class *>((((FUN_00438af0_t*)this)))->FUN_00438af0();
}

namespace fnv_004edad0 {
struct FUN_00438af0_t
{
};

struct FUN_004edb30
{
    virtual ~FUN_004edb30();
};

struct FUN_004edad0 : FUN_004edb30
{
    virtual ~FUN_004edad0();
};

// Destructor that forwards to FUN_00438af0 on this object.
// @fnv 0x004edad0
FUN_004edad0::~FUN_004edad0()
{
    reinterpret_cast<::FUN_00438af0_Class *>((reinterpret_cast<FUN_00438af0_t*>(this)))->FUN_00438af0();
}
}  // namespace fnv_004edad0

struct S_00ae8370_Node
{
    S_00ae8370_Node* unk00;
    int unk04;
    int unk08;
};
struct S_00ae8370_Alloc
{
    int unk00;
};
struct S_00ae8370_List
{
    S_00ae8370_Node* unk00;
    int unk04;
    S_00ae8370_Alloc unk08;
    void FUN_00ae8370();
};
// @fnv 0x00ae8370
void S_00ae8370_List::FUN_00ae8370()
{
    S_00ae8370_Node* pos = unk00;
    while (pos)
    {
        S_00ae8370_Node* cur = pos;
        unsigned int pad[3];
        pos = pos->unk00;
        cur->unk08 = 0;
        reinterpret_cast<::FUN_0045cee0_shell *>(&(unk08))->FUN_0045cee0(cur);
    }
    unk08.unk00 = 0;
    unk00 = 0;
    unk04 = 0;
}

extern int DAT_01023274;

// Sets the vtable to DAT_01023274, calls RemoveAll, then frees the hash table with NiFreeAlias.
// @fnv 0x004edb30
void FUN_004edb30_t::FUN_004edb30()
{
    vtbl = &DAT_01023274;
    reinterpret_cast<::FUN_00438af0_Class *>((((MyMap*)this)))->FUN_00438af0();
    ::FUN_00aa10f0(m_ppkHashTable);
}

struct A5E9C0RTTI
{
    const char* m_pcName;
    const A5E9C0RTTI* m_pBaseRTTI;
};

// @fnv 0x00a5e9c0
const A5E9C0RTTI* __cdecl FUN_00a5e9c0()
{
    return &(*reinterpret_cast<::A5E9C0RTTI *>(&::g_011f4428));
}

struct AlphaKey
{
    void* value;
};

struct AlphaNode
{
    AlphaNode* next;
    AlphaNode* prev;
    AlphaKey key;
};

struct AlphaList
{
    AlphaNode* head;

    unsigned int RemovePos(AlphaNode** pos);
    std::uintptr_t FUN_00e7db70(void* const* keyPtr);
};

// @fnv 0x00e7db70
std::uintptr_t AlphaList::FUN_00e7db70(void* const* keyPtr)
{
    AlphaNode* sel;
    AlphaNode* node = head;
    if (node != 0)
    {
        void* k = *keyPtr;
        do
        {
            AlphaKey* p = &node->key;
            sel = node;
            node = node->next;
            if (k == p->value)
            {
                goto found;
            }
        } while (node != 0);
    }
    sel = 0;
found:
    AlphaNode* pos = sel;
    if (pos != 0)
    {
        return RemovePos(&pos);
    }
    return (std::uintptr_t)*keyPtr;
}

struct A5E930RefObject
{
    virtual ~A5E930RefObject();
    virtual void DeleteThis();

    unsigned int m_uiRefCount;

    void DecRefCount()
    {
        if (InterlockedDecrement((LONG*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

struct A5E930Buffer
{
    virtual ~A5E930Buffer()
    {
        ::FUN_004b0220(reinterpret_cast<std::intptr_t>(m_pBase));
    }

    void* m_pBase;
};

class A5E930Base
{
  public:
    virtual ~A5E930Base();
    virtual void DeleteThis();
    virtual void vfunc008();
    virtual void vfunc00C();
    virtual void vfunc010();
    virtual void vfunc014();
    virtual void vfunc018();
    virtual void vfunc01C();
    virtual void vfunc020();
    virtual void vfunc024();
    virtual void vfunc028();
    virtual void vfunc02C();
    virtual void vfunc030();
    virtual void vfunc034();
    virtual void vfunc038();
    virtual void vfunc03C();
    virtual void vfunc040();
    virtual void vfunc044();
    virtual void vfunc048();
    virtual void vfunc04C();
    virtual void vfunc050();
    virtual void vfunc054();
    virtual void vfunc058();
    virtual void vfunc05C();
    virtual void vfunc060();
    virtual void vfunc064();
    virtual void vfunc068();
    virtual void vfunc06C();
    virtual void vfunc070();
    virtual void vfunc074();
    virtual void vfunc078();
    virtual void vfunc07C();
    virtual void vfunc080();
    virtual void vfunc084();
    virtual void vfunc088();
    virtual void vfunc08C();
    virtual void vfunc090();
    virtual void vfunc094();
    virtual void vfunc098();
    virtual void vfunc09C();
    virtual void vfunc0A0();
    virtual void vfunc0A4();
    virtual void vfunc0A8();
    virtual void vfunc0AC();
    virtual void vfunc0B0();
    virtual void vfunc0B4();
    virtual void vfunc0B8();
    virtual void vfunc0BC();
    virtual void vfunc0C0();
    virtual void vfunc0C4();
    virtual void vfunc0C8();
    virtual void vfunc0CC();
    virtual void vfunc0D0();
    virtual void vfunc0D4();
    virtual void vfunc0D8();
    virtual void vfunc0DC();
    virtual void vfunc0E0();
    virtual void vfunc0E4();
    virtual void vfunc0E8();
    virtual void GetChildAt(unsigned int uiIndex, A5E930RefObject*& pkChild);

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
};

class FUN_00a5e930 : public A5E930Base
{
  public:
    virtual ~FUN_00a5e930() throw();

    A5E930Buffer m_kBuffer;
    unsigned short unkA4;
    unsigned short m_usChildCount;
};

// @fnv 0x00a5e930
FUN_00a5e930::~FUN_00a5e930() throw()
{
    for (unsigned int i = 0; i < m_usChildCount; i++)
    {
        A5E930RefObject* pkChild = 0;
        static_cast<A5E930Base*>(this)->GetChildAt(i, pkChild);
        if (pkChild)
            pkChild->DecRefCount();
    }
}
