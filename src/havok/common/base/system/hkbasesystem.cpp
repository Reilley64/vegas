
// src/havok/common/base/system/hkbasesystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/hkbasesystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.


// @fnv 0x00cbb950
#include "fnv/symbols_00c85000.h"
#include <cstdint>
#include <cstddef>
#include <windows.h>
#include <new>
#include "fnv/decl/BufferOwner.h"
#include "fnv/decl/Candidate.h"
#include "havok/hkBaseSystem.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_00c903b0_class.h"
#include "fnv/decl/hkBufStreamWriterD274.h"
#include "fnv/decl/hkReferencedObjectC905.h"
#include "fnv/symbols_00b4d000.h"
#include "fnv/symbols_00c90000.h"
#include "fnv/symbols_00cb0000.h"
#include "fnv/symbols_00cbb000.h"
#include "fnv/symbols_011b3000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01268000.h"
void __cdecl FUN_00cbb950(unsigned char* out)
{
    *out = havok::base::IsInitialized();
}

struct FUN_00c903b0_Class
{
};
extern intptr_t DAT_011b3dec;
extern "C" void __cdecl FUN_00cbbbd0();
extern "C" void* DAT_011b3dbc;
typedef void(__cdecl* Callback)(int, int);
// @fnv 0x00cbbd20
void InvokeCallback(int first, int second)
{
    ((Callback)DAT_011b3dbc)(first, second);
}

inline hkMemoryRouter* audio()
{
    return static_cast<hkMemoryRouter*>(::FUN_00c85750());
}

struct LocalBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[32];
};


struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct ObjA : RefObj
{
    int unk08, unk0c;
};

struct ObjB : RefObj
{
    int pad[5];
};

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().blockAlloc(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

// @fnv 0x00cbbee0
ObjB* FUN_00cbbee0(const char* a)
{
    LocalBuf localBuf;
    reinterpret_cast<::BufferOwner *>(&(localBuf))->InitBuffer();
    ObjA* objA = (ObjA*)hkAlloc(sizeof(ObjA));
    ObjA* src = ((::ObjA *)(reinterpret_cast<::Candidate *>((objA))->OpenFile(DAT_011b3dc0(a, &localBuf))));
    ObjB* objB = (ObjB*)hkAlloc(sizeof(ObjB));
    ObjB* result = ((::ObjB *)(new ((void *)(objB)) ::hkBufStreamWriterD274((::hkStreamWriterD274 *)(src), 0x1000)));
    reinterpret_cast<::hkReferencedObjectC905 *>((src))->FUN_00c905b0();
    hkMemoryAllocator& alloc = audio()->temp();
    localBuf.m_iElementCount = 0;
    if ((localBuf.m_iCapacityState & 0x80000000) == 0)
        alloc.bufFree(localBuf.m_data, localBuf.m_iCapacityState & 0x3fffffff);
    return result;
}

struct FUN_00cbc810_cls;

struct FUN_00aa4060_cls
{
};


struct FUN_00cbc810_cls
{
    unsigned int m_key;
    FUN_00cbc810_cls* m_next;

    void RemoveKey(unsigned int* pKey);
};

// @fnv 0x00cbc810
void FUN_00cbc810_cls::RemoveKey(unsigned int* puiKey)
{
    unsigned int key = *puiKey;
    if (key == 0)
    {
        return;
    }
    FUN_00cbc810_cls* head_next = m_next;
    if (head_next == 0 && m_key == 0)
    {
        return;
    }
    FUN_00cbc810_cls* cur = this;
    FUN_00cbc810_cls* prev = this;
    do
    {
        if (cur->m_key == key)
        {
            goto found;
        }
        prev = cur;
        cur = cur->m_next;
    } while (cur != 0);
    return;

found:
    if (cur == this)
    {
        if (head_next != 0)
        {
            m_next = head_next->m_next;
            m_key = head_next->m_key;
            head_next->m_next = 0;
            ::FUN_00b4df30((void *)(head_next));
            reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_cls *>(&::g_memoryManager))))->FUN_00aa4060(head_next);
            return;
        }
        m_key = 0;
        return;
    }
    prev->m_next = cur->m_next;
    cur->m_next = 0;
    ::FUN_00b4df30((void *)(cur));
    reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_cls *>(&::g_memoryManager))))->FUN_00aa4060(cur);
}

extern intptr_t DAT_01268790;

struct SoundNode
{
    int unk00;
    int unk04;
    SoundNode* m_next;
    FUN_00c903b0_Class** m_handle;
};

struct PendingArray
{
    SoundNode** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    SoundNode* m_kStorage[128];
};

// @fnv 0x00cbbbd0
extern "C" void __cdecl FUN_00cbbbd0()
{
    SoundNode* node = (SoundNode*)DAT_01268790;
    PendingArray pendingList;
    pendingList.m_data = pendingList.m_kStorage;
    pendingList.m_iElementCount = 0;
    pendingList.m_iCapacityState = 0x80000080;

    while (node)
    {
        hkMemoryRouter* pAudioMgr = audio();
        if (pendingList.m_iElementCount == (pendingList.m_iCapacityState & 0x3fffffff))
            ::ResizeAudioStream((::AudioAllocator *)(void *)(&pAudioMgr->heap()), (::AudioStream *)(void *)(&pendingList), 4);
        pendingList.m_data[pendingList.m_iElementCount++] = node;
        node = node->m_next;
    }

    for (int i = pendingList.m_iElementCount - 1; i >= 0; --i)
    {
        FUN_00c903b0_Class* pHandleObj = *pendingList.m_data[i]->m_handle;
        if (pHandleObj)
        {
            reinterpret_cast<::FUN_00c903b0_class *>((pHandleObj))->ReleaseReference();
            *pendingList.m_data[i]->m_handle = 0;
        }
    }

    hkMemoryAllocator& heap = audio()->heap();
    pendingList.m_iElementCount = 0;
    if (!(pendingList.m_iCapacityState & 0x80000000))
        heap.bufFree(pendingList.m_data, (pendingList.m_iCapacityState & 0x3fffffff) * sizeof(SoundNode*));
}

extern intptr_t DAT_01268790;
struct SpawnedListNode
{
    int m_00;
    int(__cdecl* m_04)();
    SpawnedListNode* m_08;
    int* m_0c;
};


template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void AddBack(hkMemoryAllocator* alloc, T val)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
        {
            ::ResizeAudioStream((::AudioAllocator *)(alloc), (::AudioStream *)(void *)(this), sizeof(T));
        }
        m_data[m_iElementCount++] = val;
    }

    void removeAt(int i)
    {
        m_iElementCount--;
        if (m_iElementCount != i)
        {
            m_data[i] = m_data[m_iElementCount];
        }
    }

    void ClearAndRelease(hkMemoryAllocator* alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc->bufFree(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        }
    }
};

// Walks the chain, calls m_04 for nodes with zero m_0c, and retries deferred nodes until their calls return nonzero.
// @fnv 0x00cbb9f0
void __cdecl FUN_00cbb9f0()
{
    SpawnedListNode** link = (SpawnedListNode**)&DAT_01268790;
    SpawnedListNode* node = *link;

    hkArray<SpawnedListNode*> pendingNodes;
    pendingNodes.m_data = 0;
    pendingNodes.m_iElementCount = 0;
    pendingNodes.m_iCapacityState = 0x80000000;

    while (node != 0)
    {
        if (*node->m_0c == 0 && node->m_04 != 0)
        {
            int r = node->m_04();
            if (r != 0)
            {
                *node->m_0c = r;
                link = &node->m_08;
                node = *link;
                continue;
            }
            else
            {
                pendingNodes.AddBack(audio()->m_temp, node);
                SpawnedListNode* linked = *link;
                node = node->m_08;
                linked->m_08 = 0;
                *link = node;
                continue;
            }
        }
        link = &node->m_08;
        node = *link;
    }

    if (pendingNodes.m_iElementCount != 0)
    {
        do
        {
            for (int i = pendingNodes.m_iElementCount - 1; i >= 0; --i)
            {
                SpawnedListNode* item = pendingNodes.m_data[i];
                int r = item->m_04();
                if (r != 0)
                {
                    *item->m_0c = r;
                    *link = item;
                    link = &item->m_08;
                    if (--pendingNodes.m_iElementCount != i)
                    {
                        pendingNodes.m_data[i] = pendingNodes.m_data[pendingNodes.m_iElementCount];
                    }
                    else
                    {
                        link = &item->m_08;
                    }
                }
            }
        } while (pendingNodes.m_iElementCount != 0);
    }

    pendingNodes.ClearAndRelease(audio()->m_temp);
}

#include <windows.h>
// Queries the system processor count via GetSystemInfo and stores the minimum of that count and 4 into apiOut.
// @fnv 0x00cbb960
void __cdecl GetProcessorCount(int* piProcessorCount)
{
    SYSTEM_INFO kInfo;
    GetSystemInfo(&kInfo);

    int iProcessorCount = (int)kInfo.dwNumberOfProcessors;
    *piProcessorCount = iProcessorCount < 4 ? iProcessorCount : 4;
}

namespace fnv_00cbb9c0 {
struct SpawnedAllocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int auiSize);
};

struct SpawnedHolder
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    SpawnedAllocator* m_pAllocator;
};


struct SpawnedObject
{
    virtual void v00();
    unsigned short m_w04;
    unsigned short m_w06;

    SpawnedObject()
    {}

};

// Allocates 8 bytes through the holder's allocator, sets m_w04 and m_w06, then placement-constructs a SpawnedObject there.
// @fnv 0x00cbb9c0
void __cdecl FUN_00cbb9c0()
{
    SpawnedHolder* pHolder = static_cast<SpawnedHolder*>(::FUN_00c85750());
    SpawnedAllocator* pAllocator = pHolder->m_pAllocator;
    SpawnedObject* pSpawnedObject = (SpawnedObject*)pAllocator->Alloc(8);
    pSpawnedObject->m_w04 = 8;
    pSpawnedObject->m_w06 = 1;
    new (pSpawnedObject) SpawnedObject();
}
}  // namespace fnv_00cbb9c0

namespace fnv_00cbbde0 {
struct S_00cbbde0_Allocator
{
    virtual void vfn0();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void vfn8();
    virtual void vfnc();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S_00cbbde0_Router
{
    void* unk0;
    void* unk4;
    void* unk8;
    S_00cbbde0_Allocator* unkc;
    S_00cbbde0_Allocator* unk10;
    S_00cbbde0_Allocator& temp()
    {
        return *unkc;
    }
    S_00cbbde0_Allocator& heap()
    {
        return *unk10;
    }
};


struct S_00cbbde0_Bool
{
    char m_cBooleanValue;
    S_00cbbde0_Bool()
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S_00cbbde0_StringBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    // inline storage for 128 chars; declared as ints because the original has no /GS cookie
    unsigned int m_kStorage[32];

    S_00cbbde0_StringBuf() throw();
    ~S_00cbbde0_StringBuf() throw()
    {
        S_00cbbde0_Allocator& a = static_cast<S_00cbbde0_Router*>(::FUN_00c85750())->temp();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(char));
    }
};

struct S_00cbbde0_RefObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    virtual ~S_00cbbde0_RefObject() throw();
    void* operator new(std::size_t n)
    {
        S_00cbbde0_RefObject* b = static_cast<S_00cbbde0_RefObject*>(static_cast<S_00cbbde0_Router*>(::FUN_00c85750())->heap().AllocateMemoryBlock(n));
        b->m_usMemSizeAndFlags = (unsigned short)n;
        return b;
    }
    void operator delete(void*)
    {}
};

struct S_00cbbde0_Reader : S_00cbbde0_RefObject
{
    virtual void vfn4();
    virtual void vfn8();
    virtual void vfnc();
    virtual void vfn10();
    virtual void vfn14();
    virtual S_00cbbde0_Bool vfn18();
};

struct S_00cbbde0_StdioReader : S_00cbbde0_Reader
{
    int unk8;
    int unkc;
    int unk10;
    S_00cbbde0_StdioReader(const char* name) throw();
};

struct S_00cbbde0_BufferedReader : S_00cbbde0_Reader
{
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S_00cbbde0_BufferedReader(S_00cbbde0_Reader* s, int bufSize) throw();
};


// Creates a StdioReader from the resolved path, wraps it in a 4096-byte BufferedReader when vfn18() is false, and returns the resulting reader.
// @fnv 0x00cbbde0
S_00cbbde0_Reader* FUN_00cbbde0(const char* name) throw()
{
    S_00cbbde0_StringBuf buf;
    S_00cbbde0_Reader* reader = new S_00cbbde0_StdioReader((*reinterpret_cast<const char *(**)(const char *, fnv_00cbbde0::S_00cbbde0_StringBuf &)>(&::DAT_011b3dc0))(name, buf));
    if (!reader->vfn18())
    {
        S_00cbbde0_Reader* pBufferedReader = new S_00cbbde0_BufferedReader(reader, 0x1000);
        reinterpret_cast<::hkReferencedObjectC905 *>((reader))->FUN_00c905b0();
        return pBufferedReader;
    }
    return reader;
}
}  // namespace fnv_00cbbde0

#include "generated/data/havok/common/base/system/hkbasesystem.inc"
