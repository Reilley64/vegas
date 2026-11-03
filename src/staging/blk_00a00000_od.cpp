
// src/staging/blk_00a00000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include <cstring>
#include <stdexcept>
#include "runtime/crt.h"
#include "fnv/decl/A0D2A0_StringMap.h"
#include "fnv/decl/AE91F0Map.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/FNV_MemoryManager.h"
#include "fnv/decl/FUN_0043a010_shell.h"
#include "fnv/decl/FUN_0044a8d0_Class.h"
#include "fnv/decl/FUN_0045cee0_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/MemoryManagerStandIn.h"
#include "fnv/decl/Node185.h"
#include "fnv/decl/RequestQueue.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00aa1000.h"
#include "fnv/symbols_01017000.h"
#include "fnv/symbols_01095000.h"
#include "fnv/symbols_011f6000.h"
#include "../../include/layout_support.h"
#include "fnv/decl/FUN_00ae8bf0_t.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/fnv_00a1c2d0__FUN_00a1c2d0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_0109b000.h"
#include "fnv/symbols_011f3000.h"
#include <string.h>

struct P03MM
{
};


struct FUN_00a1c020_Class
{
    void* AllocateShifted(unsigned int size);
};

// Allocates size << 5 bytes through g_memoryManager and returns the resulting pointer.
// @fnv 0x00a1c020
void* FUN_00a1c020_Class::AllocateShifted(unsigned int size)
{
    void* result = reinterpret_cast<::MemoryManagerStandIn *>(&((*reinterpret_cast<::P03MM *>(&::g_memoryManager))))->FUN_00aa3e40(size << 5);
    return result;
}

namespace fnv_00a1c050 {
struct MemoryManager
{
    void* Reallocate(void* p, unsigned int size);
};


struct FUN_00a1c050_Class
{
    void* FUN_00a1c050(void* p, unsigned int n);
};

// @fnv 0x00a1c050
void* FUN_00a1c050_Class::FUN_00a1c050(void* p, unsigned int n)
{
    return (*reinterpret_cast<::fnv_00a1c050::MemoryManager *>(&::g_memoryManager)).Reallocate(p, n << 5);
}
}  // namespace fnv_00a1c050

struct FUN_00a1e720_class
{
    void FUN_00a1e720(intptr_t a, int b, int c);
};

// @fnv 0x00a1e720
void FUN_00a1e720_class::FUN_00a1e720(intptr_t pObject, int b, int c)
{
    *(int*)((char*)pObject + 4) = b;
    *(int*)((char*)pObject + 8) = c;
}


struct FUN_00a1e1a0_class
{
    intptr_t m_vtbl;
    intptr_t m_field;
    void FUN_00a1e1a0();
};

// Sets the vtable pointer to DAT_01095524 and frees the m_field pointer via NiFreeAlias.
// @fnv 0x00a1e1a0
void FUN_00a1e1a0_class::FUN_00a1e1a0()
{
    m_vtbl = (intptr_t)&DAT_01095524;
    void* p = (void*)m_field;
    ::FUN_00aa10f0(p);
}

struct MemoryManager
{
};
struct FUN_00a11d80_Class
{
    void InitAndClear();
    void* DestroyIfFlagged(unsigned int flags);
};
// Calls InitAndClear, then deallocates this via g_memoryManager when flags has bit 1 set, and returns this.
// @fnv 0x00a11d80
void* FUN_00a11d80_Class::DestroyIfFlagged(unsigned int flags)
{
    InitAndClear();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

namespace fnv_00a1c100 {

struct MemoryManager
{
};

struct FUN_00a1c100_Class
{
    void Reset();
    void* FUN_00a1c100(unsigned int flags);
};

// @fnv 0x00a1c100
void* FUN_00a1c100_Class::FUN_00a1c100(unsigned int flags)
{
    Reset();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00a1c100

namespace fnv_00a1e400 {
struct MemoryManager
{
};

struct FUN_00a1e400_class
{
    intptr_t m_vtbl;
    intptr_t m_field;
    FUN_00a1e400_class* FUN_00a1e400(int flags);
};

// Sets the vtable, frees m_field via NiFree, and if flags has bit 0 set deallocates this through the memory manager; returns this.
// @fnv 0x00a1e400
FUN_00a1e400_class* FUN_00a1e400_class::FUN_00a1e400(int flags)
{
    void* old;
    m_vtbl = (intptr_t)&DAT_01095524;
    old = (void*)m_field;
    ::FUN_00aa10f0(old);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}
}  // namespace fnv_00a1e400

struct _Secure_char_traits_tag
{
    char _Dummy;
};
struct StrA
{
    int _Alval;
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    bool _Inside(const char*);
    StrA& FUN_00a0c430(const char* _Ptr, unsigned int _Count);
};

extern int DAT_01094e1c;
struct FUN_00a0d5f0_class
{
    int* m_vtbl;
    int m_iElementCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00a0d5f0_class* FUN_00a0d5f0(unsigned int size);
};
// Sets the vtable, stores size, allocates size*4 bytes, zeroes them and stores the pointer in m_data.
// @fnv 0x00a0d5f0
FUN_00a0d5f0_class* FUN_00a0d5f0_class::FUN_00a0d5f0(unsigned int size)
{
    unsigned int iAllocationSize;
    unsigned int memsetSize;
    void* data2;
    m_vtbl = (int*)&DAT_01094e1c;
    m_iElementCount = size;
    m_auiShapeKeys = 0;
    iAllocationSize = m_iElementCount << 2;
    m_data = ::FUN_00aa1070(iAllocationSize);
    memsetSize = m_iElementCount << 2;
    data2 = m_data;
    std::memset(data2, 0, memsetSize);
    return this;
}

extern int DAT_01094e9c;
struct FUN_00a0d8e0
{
    int* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00a0d8e0(int count);
};
// Sets the vtable, stores count, allocates count*4 bytes, and zero-fills the buffer.
// @fnv 0x00a0d8e0
FUN_00a0d8e0::FUN_00a0d8e0(int count)
{
    m_vtbl = (int*)&DAT_01094e9c;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    int sz3 = m_uiItemCount << 2;
    m_data = ::FUN_00aa1070(sz3);
    int sz2 = m_uiItemCount << 2;
    void* p2 = m_data;
    std::memset(p2, 0, sz2);
}

struct FUN_00a1c080_Class
{
    FUN_00a1c080_Class* m_next;
    int m_field;
    int m_uiItemCount;
    int PopFront();
};
// Unlinks the head node from a singly linked list, clears its field, deallocates it, decrements the count and returns the node's stored value.
// @fnv 0x00a1c080
int FUN_00a1c080_Class::PopFront()
{
    FUN_00a1c080_Class* oldNext;
    FUN_00a1c080_Class* next6 = m_next;
    m_next = m_next->m_next;
    if (m_next)
        m_next->m_field = 0;
    else
        m_field = 0;
    int result5 = next6->m_uiItemCount;
    next6->m_uiItemCount = 0;
    oldNext = next6;
    reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(oldNext);
    --m_uiItemCount;
    return result5;
}


struct FUN_00a1e450_Class
{
    int* m_vtbl;
    void* m_data;
    unsigned short m_iElementCount;
    unsigned short m_auiShapeKeys;
    unsigned short m_uiX;
    unsigned short m_uiY;
    FUN_00a1e450_Class(unsigned short size, unsigned short x);
};

// Sets the vtable, stores size and x, zeroes two fields, and allocates size*4 bytes into m_data when size is greater than zero.
// @fnv 0x00a1e450
FUN_00a1e450_Class::FUN_00a1e450_Class(unsigned short size, unsigned short x)
{
    m_vtbl = (int*)&DAT_01095524;
    m_iElementCount = size;
    m_uiY = x;
    m_auiShapeKeys = 0;
    m_uiX = 0;
    if (m_iElementCount > 0)
    {
        unsigned int n = m_iElementCount;
        m_data = ::FUN_00aa1070(n * 4);
    }
    else
    {
        m_data = 0;
    }
}

extern int DAT_010955e4;
struct FUN_00a1eaa0
{
    int* vtbl;
    int count;
    int* data;
    int pad;
    FUN_00a1eaa0(int n);
};
// Sets the vtable, stores n as count, allocates count*4 bytes and zero-fills the data buffer.
// @fnv 0x00a1eaa0
FUN_00a1eaa0::FUN_00a1eaa0(int aiCount)
{
    int size;
    int size2;
    int* p3;
    vtbl = &DAT_010955e4;
    count = aiCount;
    pad = 0;
    size = count << 2;
    data = (int*)::FUN_00aa1070(size);
    size2 = count << 2;
    p3 = data;
    std::memset(p3, 0, size2);
}

struct FUN_00a1ede0
{
    int* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00a1ede0(int count);
};
// Sets the vtable, stores count and zeroes a newly allocated count*4-byte buffer.
// @fnv 0x00a1ede0
FUN_00a1ede0::FUN_00a1ede0(int count)
{
    m_vtbl = &DAT_01095664;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    int sz2 = m_uiItemCount << 2;
    m_data = ::FUN_00aa1070(sz2);
    int sz1 = m_uiItemCount << 2;
    void* p5 = m_data;
    std::memset(p5, 0, sz1);
}

extern int DAT_0109568c;

struct FUN_00a1eeb0_class
{
    void* vtbl;
    void* data;
    unsigned short count;
    unsigned short a;
    unsigned short stride;
    unsigned short b;
    FUN_00a1eeb0_class(unsigned short c, unsigned short s);
};

// Sets the vtable, stores count and s, zeroes a and stride, and allocates count*4 bytes for data when count > 0, otherwise data is null.
// @fnv 0x00a1eeb0
FUN_00a1eeb0_class::FUN_00a1eeb0_class(unsigned short ausCount, unsigned short s)
{
    vtbl = (void*)&DAT_0109568c;
    count = ausCount;
    b = s;
    a = 0;
    stride = 0;
    unsigned int sz;
    if (count > 0)
    {
        sz = count;
        data = ::FUN_00aa1070(sz * 4);
    }
    else
    {
        data = 0;
    }
}

extern int DAT_01094e5c;
struct FUN_00a0d710_class
{
    int* m_vtbl;
    int m_iElementCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00a0d710_class* FUN_00a0d710(unsigned int size);
};
// @fnv 0x00a0d710
FUN_00a0d710_class* FUN_00a0d710_class::FUN_00a0d710(unsigned int size)
{
    unsigned int a;
    void* b;
    unsigned int c;
    m_vtbl = &DAT_01094e5c;
    m_iElementCount = size;
    m_auiShapeKeys = 0;
    a = m_iElementCount << 2;
    m_data = ::FUN_00aa1070(a);
    c = m_iElementCount << 2;
    b = m_data;
    std::memset(b, 0, c);
    return this;
}

struct FUN_00a1ee60_class
{
    int* m_vtbl;
    void* m_data;
    FUN_00a1ee60_class(unsigned short c);
    FUN_00a1ee60_class* FUN_00a1ee60(int freeMem);
};
// @fnv 0x00a1ee60
FUN_00a1ee60_class* FUN_00a1ee60_class::FUN_00a1ee60(int freeMem)
{
    m_vtbl = &DAT_0109568c;
    void* data = m_data;
    ::FUN_00aa10f0(data);
    if (freeMem & 1)
        reinterpret_cast<::FNV_MemoryManager *>((((MemoryManager*)&(*reinterpret_cast<::P03MM *>(&::g_memoryManager)))))->FUN_00aa4060(this);
    return this;
}

struct S00a0d390
{
    int* m_vtbl;
    int m_field;
};

struct FUN_00a0d960_class : S00a0d390
{
    void* m_data;
    void FUN_00a0d960();
};

// @fnv 0x00a0d960
void FUN_00a0d960_class::FUN_00a0d960()
{
    int unused;
    int padding;
    m_vtbl = &DAT_01094e9c;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(m_data);
}

struct _BSAHelper
{
    void Clear(bool);
};

extern unsigned int DAT_0109504c;

// Sets the object's vtable pointer to DAT_0109504c, then calls Clear(true) on the object.
// @fnv 0x00a11d00
void FUN_00a11d80_Class::InitAndClear()
{
    int unused;

    *reinterpret_cast<int**>(this) = reinterpret_cast<int*>(&DAT_0109504c);
    reinterpret_cast<::RequestQueue *>((reinterpret_cast<_BSAHelper*>(this)))->FUN_00a1bfa0(true);
}

struct FUN_00a1e520_class
{
    int* m_vtbl;
    int* m_data;
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_live;
    void Resize(unsigned int size);
};

// @fnv 0x00a1e520
void FUN_00a1e520_class::Resize(unsigned int size)
{
    unsigned short b;
    unsigned int o;
    int* d;

    if (size == m_iElementCount)
    {
        return;
    }

    if (size < m_uiItemCount)
    {
        for (b = static_cast<unsigned short>(size); b < m_uiItemCount; b++)
        {
            if (m_data[b] != 0)
            {
                m_data[b] = 0;
                --m_live;
            }
        }
        m_uiItemCount = static_cast<unsigned short>(size);
    }

    d = m_data;
    m_iElementCount = static_cast<unsigned short>(size);

    if (size > 0)
    {
        o = m_iElementCount;
        m_data = static_cast<int*>(::FUN_00aa1070(o * 4));

        for (b = 0; b < m_uiItemCount; b++)
        {
            m_data[b] = d[b];
        }

        for (b = m_uiItemCount; b < m_iElementCount; b++)
        {
            m_data[b] = 0;
        }
    }
    else
    {
        m_data = 0;
    }

    ::FUN_00aa10f0(d);
}

struct FUN_00a0d2a0_Obj
{
};

struct FUN_00aa4060_Class
{
};


struct FUN_00a0d5c0_Local
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};

struct FUN_00a0d5c0_Class
{
    intptr_t FUN_00a0d5c0(int arg);
};

// Calls FUN_00a0d2a0 on this, then if bit 0 of arg is set calls FUN_00aa4060 on this, and returns this as an int.
// @fnv 0x00a0d5c0
intptr_t FUN_00a0d5c0_Class::FUN_00a0d5c0(int aiFlags)
{
    FUN_00a0d5c0_Local local;

    reinterpret_cast<::A0D2A0_StringMap *>((reinterpret_cast<FUN_00a0d2a0_Obj*>(this)))->A0D2A0_StringMap::~A0D2A0_StringMap();

    if ((aiFlags & 1) != 0)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_Class *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }

    return reinterpret_cast<intptr_t>(this);
}

struct FUN_00a0d7c0_Arg
{
    int unk00;
    int unk04;
    int m08;
};

struct FUN_00a0d7c0_Sub
{
    int unk00;
};

struct FUN_00a0d7c0_Locals
{
    int unk00;
    int unk04;
    int unk08;
};

struct FUN_00a0d7c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00a0d7c0_Sub m0c;
    void ResetAndProcess(FUN_00a0d7c0_Arg* arg);
};

// Clears arg->m08 and forwards arg to m0c.Process.
// @fnv 0x00a0d7c0
void FUN_00a0d7c0_cls::ResetAndProcess(FUN_00a0d7c0_Arg* arg)
{
    FUN_00a0d7c0_Locals locals;
    arg->m08 = 0;
    reinterpret_cast<::FUN_0045cee0_shell *>(&(m0c))->FUN_0045cee0(arg);
}

namespace fnv_00a11fa0 {

class FUN_00a11fa0_pool
{
  public:
};

class FUN_00a11fa0_cls
{
  public:
    void* m_00;
    FUN_00a11fa0_cls* m_04;
    int m_08;

    int RemoveNextNode();
};

// Unlinks the node after this one, releases it to the pool, decrements the count and returns the removed node's value.
// @fnv 0x00a11fa0
int FUN_00a11fa0_cls::RemoveNextNode()
{
    FUN_00a11fa0_cls* node2 = this->m_04;
    this->m_04 = this->m_04->m_04;
    if (this->m_04 != 0)
    {
        this->m_04->m_00 = 0;
    }
    else
    {
        this->m_00 = 0;
    }
    int result2 = node2->m_08;
    node2->m_08 = 0;
    FUN_00a11fa0_cls* volatile released = node2;
    reinterpret_cast<::FNV_MemoryManager *>((reinterpret_cast<FUN_00a11fa0_pool*>(&(*reinterpret_cast<int *>(&::g_memoryManager)))))->FUN_00aa4060(released);
    this->m_08 = this->m_08 - 1;
    return result2;
}
}  // namespace fnv_00a11fa0

struct FUN_00a1e880_class : S00a0d390
{
    void* m_data;
    void FUN_00a1e880();
};
// @fnv 0x00a1e880
void FUN_00a1e880_class::FUN_00a1e880()
{
    m_vtbl = (int*)&DAT_010955e4;
    void* pAssertA;
    void* pAssertB;  // only used by debug asserts in the original build
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(m_data);
}

// FUN_00a1ea70 (unit_1a635d660b3a.cpp) - 48B scalar-deleting-destructor shape
// v0: verbatim transcription of IDA a1ea70..0xa1eaa0 (push ebp/mov/sub esp,20h/
// mov[ebp-20h],ecx; call FUN_00a1e900(this); if(a2&1) MemoryManager::_g_memoryManager.Deallocate(this); return this)
// frame pinned via unused Q7 struct (probe2/probe3 verified sub esp,20h + this@-20h, zero extra insns)
struct FUN_00a1e900_Class
{
    int FUN_00a1e900();
};

struct Q7
{
    int v4, v8, vC, v10, v14, v18, v1C;
};
struct FUN_00a1ea70_Class
{
    void* FUN_00a1ea70(unsigned int a2);
};

namespace fnv_00a1ebf0 {

struct FUN_00aa4060_Manager
{
};


struct FUN_00a1ebf0_Class : S00a0d390
{
    void* m_data;
    int m_auiShapeKeys;
    void* FUN_00a1ebf0(int flags);
};


// @fnv 0x00a1ebf0
void* FUN_00a1ebf0_Class::FUN_00a1ebf0(int flags)
{
    int _temp1;
    int _temp2;
    m_vtbl = &::DAT_01095664;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(m_data);
    if ((flags & 1) != 0)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::fnv_00a1ebf0::FUN_00aa4060_Manager *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return this;
}
}  // namespace fnv_00a1ebf0

struct FUN_00a0c7a0_shell
{
    BSSimpleList<unsigned char*> m_kNode;
    void ClearList();
};
// @fnv 0x00a0c7a0
void FUN_00a0c7a0_shell::ClearList()
{
    int local_c;
    int local_8;
    int local_4;
    reinterpret_cast<::Node185 *>(&(m_kNode))->FUN_00ae83e0();
}

struct S_00a0c9f0_Node
{
    S_00a0c9f0_Node* m_pkNext;
    S_00a0c9f0_Node* m_pkPrev;
    int m_val;
};

struct S_00a0c9f0_Pool
{
    int m_uiCount;
};

class S_00a0c9f0
{
    S_00a0c9f0_Node* m_pkHead;
    S_00a0c9f0_Node* m_pkTail;
    S_00a0c9f0_Pool m_kNodePool;

  public:
    void FUN_00a0c9f0(int* pValue);
};

// @fnv 0x00a0c9f0
void S_00a0c9f0::FUN_00a0c9f0(int* pValue)
{
    volatile int dummy_frame[7];
    S_00a0c9f0_Node* pNode = ((::S_00a0c9f0_Node *)(reinterpret_cast<::FUN_0043a010_shell *>(&(m_kNodePool))->FUN_0043a010()));
    pNode->m_val = *pValue;
    pNode->m_pkPrev = 0;
    pNode->m_pkNext = m_pkHead;

    if (m_pkHead)
    {
        m_pkHead->m_pkPrev = pNode;
    }
    else
    {
        m_pkTail = pNode;
    }

    m_pkHead = pNode;
    m_kNodePool.m_uiCount++;
    (void)dummy_frame;
}

struct FUN_00a0d790_class : S00a0d390
{
    void* m_data;
    void FUN_00a0d790();
};
// @fnv 0x00a0d790
void FUN_00a0d790_class::FUN_00a0d790()
{
    int unusedA;
    int unusedB;
    m_vtbl = &DAT_01094e5c;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(m_data);
}

extern int DAT_01094e9c;

struct FUN_00a0d990_cls : S00a0d390
{
    void* m_data;
    intptr_t FUN_00a0d990(int arg);
};

// @fnv 0x00a0d990
intptr_t FUN_00a0d990_cls::FUN_00a0d990(int aiFlags)
{
    int a;
    int b;
    (void)a;
    (void)b;
    this->m_vtbl = reinterpret_cast<int*>(&DAT_01094e9c);
    reinterpret_cast<::AE91F0Map *>((this))->ClearAll();
    ::FUN_00aa10f0(this->m_data);
    if ((aiFlags & 1) != 0)
    {
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_Class *>(&::g_memoryManager))))->FUN_00aa4060(this);
    }
    return reinterpret_cast<intptr_t>(this);
}

struct FUN_00a1ebc0
{
    int m_field;
    void* m_data;
    virtual ~FUN_00a1ebc0();
};

// @fnv 0x00a1ebc0
FUN_00a1ebc0::~FUN_00a1ebc0()
{
    unsigned int i;
    void* node;
    reinterpret_cast<::AE91F0Map *>((((S00a0d390*)this)))->ClearAll();
    ::FUN_00aa10f0(m_data);
}

struct S
{
    int* m_vtbl;
    void Clear(bool);
    void Reset();
};
extern int DAT_0109527c;
// Sets m_vtbl to DAT_0109527c and calls Clear(true).
// @fnv 0x00a1bf80
void S::Reset()
{
    int unused;
    m_vtbl = &DAT_0109527c;
    reinterpret_cast<::RequestQueue *>(this)->FUN_00a1bfa0(true);
}


struct FUN_00a1ec40_Class
{
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1c;
    FUN_00a1ec40_Class* FUN_00a1ec40(unsigned int flags);
};


struct S00a0ca70_Node
{
    S00a0ca70_Node* m_pkNext;
    void* m_pkPrev;
    unsigned int m_val;
};
struct S00a0ca70_Pool
{
    unsigned int m_uiCount;
};
struct S00a0ca70_Blk
{
    int v4, v8, vC, v10, v14, v18, v1C;
};
class S00a0ca70_List
{
  public:
    unsigned int m_unk00;
    S00a0ca70_Node* m_pkHead;
    S00a0ca70_Pool m_kNodePool;
    S00a0ca70_Node* FUN_00a0ca70(S00a0ca70_Node** pos, const unsigned int* value);
};
// Allocates a node from m_kNodePool, sets its m_val, and splices it into the linked list at the position pointed to by pos.
// @fnv 0x00a0ca70
S00a0ca70_Node* S00a0ca70_List::FUN_00a0ca70(S00a0ca70_Node** pos, const unsigned int* value)
{
    S00a0ca70_Node** pForm;
    S00a0ca70_Blk blk;
    S00a0ca70_Node* node2;
    node2 = ((::S00a0ca70_Node *)(reinterpret_cast<::FUN_0043a010_shell *>(&(m_kNodePool))->FUN_0043a010()));
    node2->m_val = *value;
    pForm = pos;
    node2->m_pkPrev = pForm;
    node2->m_pkNext = *pForm;
    if (*pForm != 0)
    {
        (*pForm)->m_pkPrev = node2;
    }
    else
    {
        m_pkHead = node2;
    }
    *pForm = node2;
    m_kNodePool.m_uiCount = 1 + m_kNodePool.m_uiCount;
    return node2;
}

void* __cdecl _fnv_zlib_memset(void* dst, int c, unsigned int n);

void* _fnv_zlib_memset(void* dest, int val, unsigned int size);

void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);

void* __cdecl fnv_zlib_memset(void* dest, int c, unsigned int size);

struct CountedRange
{
    void* data;
    unsigned short count, capacity;
};

struct FloatBounds
{
    float left, top, right, bottom;
};

static __inline unsigned short SaturateU16(unsigned int v)
{
    return v <= 0xffffu ? (unsigned short)v : 0xffffu;
}

struct FUN_00a0beb0 : CountedRange
{
    CountedRange second, third;
    FloatBounds bounds;
    FUN_00a0beb0();
};

// @fnv 0x00a0beb0
FUN_00a0beb0::FUN_00a0beb0()
{
    CountedRange* a;
    CountedRange* b;
    FloatBounds* c;
    data = 0;
    count = SaturateU16(0);
    capacity = SaturateU16(0);
    a = &second;
    a->data = 0;
    a->count = SaturateU16(0);
    a->capacity = SaturateU16(0);
    b = &third;
    b->data = 0;
    b->count = SaturateU16(0);
    b->capacity = SaturateU16(0);
    c = &bounds;
    c->left = 0.0f;
    c->top = 0.0f;
    c->right = 0.0f;
    c->bottom = 0.0f;
}

struct S00a0d7f0 : S00a0d390
{
    void* m_data;
    int m_live;

    void RemoveAll()
    {
        unsigned int i;
        void* pkSave;
        for (i = 0; i < (unsigned int)m_field; i++)
        {
            if (((void**)m_data)[i] != 0)
            {
                pkSave = ((void**)m_data)[i];
                ((void**)m_data)[i] = *(void**)pkSave;
                ::FUN_00aa10f0(pkSave);
            }
        }
        m_live = 0;
    }

    void* FUN_00a0d7f0(unsigned int flags);
};

// @fnv 0x00a0d7f0
void* S00a0d7f0::FUN_00a0d7f0(unsigned int flags)
{
    m_vtbl = (int*)&DAT_01094e5c;
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    ::FUN_00aa10f0(m_data);
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060(this);
    return this;
}

class NiFixedString
{
  public:
    const char* m_pcString;
    ~NiFixedString();
};

inline NiFixedString::~NiFixedString()
{
    if (m_pcString == ::DAT_0109b220)
    {
        return;
    }
    char* pcBlock = (char*)m_pcString - 8;
    InterlockedDecrement((long*)pcBlock);
}

// @fnv 0x00a1c790
void __cdecl FUN_00a1c790()
{
    delete (*reinterpret_cast<::NiFixedString * *>((void *)&::tileext::DAT_011f34cc));
}

struct NiNodeRef
{
    NiNode* m_pObject;
    NiNodeRef& operator=(NiNode* object);
};

struct Tile3D
{
    Tile3D();
    virtual ~Tile3D();
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
    NiNodeRef m_pController;
    int unk30;
    int unk34;
};

struct TileStr
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    __forceinline void SetLength(unsigned int length)
    {
        sLen = length <= 0xffff ? (unsigned short)length : 0xffff;
    }
    __forceinline void SetMaxLength(unsigned int length)
    {
        sMaxLen = length <= 0xffff ? (unsigned short)length : 0xffff;
    }
    __forceinline TileStr()
    {
        pString = 0;
        SetLength(0);
        SetMaxLength(0);
    }
    ~TileStr();
};

struct FUN_00a0bc80 : Tile3D
{
    int unk38;
    int unk3C;
    TileStr str40;
    TileStr str48;
    FUN_00a0bc80();
    __forceinline void Dead2()
    {
        int aiF[2];
    }
    virtual ~FUN_00a0bc80();
};

// @fnv 0x00a0bc80
FUN_00a0bc80::FUN_00a0bc80()
{
    int aiD[7];
    Dead2();
    m_pController = 0;
    unk38 = 0;
    unk3C = 0;
}

struct StrTraitsB
{
    static char* copy_s(char* _First1, unsigned int _Size_in_bytes, const char* _First2, unsigned int _Count,
                        _Secure_char_traits_tag _Tg)
    {
        fnv::crt::memcpy_s(_First1, _Size_in_bytes, _First2, _Count);
        return _First1;
    }
    static void assign(char& _Left, const char& _Right)
    {
        _Left = _Right;
    }
};

inline _Secure_char_traits_tag _Char_traits_cat()
{
    _Secure_char_traits_tag _Cat;
    return _Cat;
}

struct StrTraitsHelperB
{
    static char* copy_s(char* _First1, unsigned int _Size, const char* _First2, unsigned int _Count)
    {
        int aiD[6];
        return StrTraitsB::copy_s(_First1, _Size, _First2, _Count, _Char_traits_cat());
    }
};

struct StrB
{
    int _Alval;
    union
    {
        char _Buf[16];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;
    bool _Grow(unsigned int, bool _Trim = false);
    unsigned int size() const
    {
        return _Mysize;
    }
    char* _Myptr()
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    const char* _Myptr() const
    {
        return 16 <= _Myres ? _Bx._Ptr : _Bx._Buf;
    }
    void _Eos(unsigned int _Newsize)
    {
        StrTraitsB::assign(_Myptr()[_Mysize = _Newsize], char());
    }
    StrB& FUN_00a0c570(const StrB& _Right, unsigned int _Roff, unsigned int _Count);
};

// @fnv 0x00a0c570
StrB& StrB::FUN_00a0c570(const StrB& _Right, unsigned int _Roff, unsigned int _Count)
{
    if (_Right.size() < _Roff)
        throw std::out_of_range("invalid string position");
    unsigned int _Num = _Right.size() - _Roff;
    if (_Num < _Count)
        _Count = _Num;
    if (::g_010173f0 - _Mysize <= _Count || _Mysize + _Count < _Mysize)
        throw std::length_error("string too long");
    if (0 < _Count && _Grow(_Num = _Mysize + _Count))
    {
        StrTraitsHelperB::copy_s(_Myptr() + _Mysize, _Myres - _Mysize, _Right._Myptr() + _Roff, _Count);
        _Eos(_Num);
    }
    return *this;
}

struct FUN_00a1bc70_Base
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
// @fnv 0x00a1bc70
    FUN_00a1bc70_Base()
    {
        m_08 = 0;
        m_00 = 0;
        m_04 = 0;
    }
};

struct FUN_00a1bc70_Sub
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    ~FUN_00a1bc70_Sub();
};

class FUN_00a1bc70 : public FUN_00a1bc70_Base
{
  public:
    FUN_00a1bc70_Sub m_10;
    unsigned int m_20[8];
    unsigned int m_40;

    FUN_00a1bc70(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4);
    int CallStep(unsigned int a, unsigned int b);
};

FUN_00a1bc70::FUN_00a1bc70(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
    m_10.m_00 = 0;
    m_10.m_04 = a3;
    m_10.m_08 = a4;
    m_40 = a1;
    for (int i = 0; i < 8; i++)
    {
        m_20[i] = 0;
    }
    m_10.m_0c = 0x23;
    CallStep(a2, 0);
}

struct CharTraitsQ
{
    static bool eq(const char& _Left, const char& _Right)
    {
        return _Left == _Right;
    }
    static int compare(const char* _First1, const char* _First2, unsigned int _Count)
    {
        return memcmp(_First1, _First2, _Count);
    }
};

struct StringQ
{
    enum
    {
        _BUF_SIZE = 16
    };
    int _Alval;
    union
    {
        char _Buf[_BUF_SIZE];
        char* _Ptr;
    } _Bx;
    unsigned int _Mysize;
    unsigned int _Myres;


    const char* _Myptr() const
    {
        return (_BUF_SIZE <= _Myres ? _Bx._Ptr : _Bx._Buf);
    }

    unsigned int FUN_00a0c300(const char* _Ptr, unsigned int _Off, unsigned int _Count) const;
};

// @fnv 0x00a0c300
unsigned int StringQ::FUN_00a0c300(const char* _Ptr, unsigned int _Off, unsigned int _Count) const
{
    if (_Count == 0)
        return (_Off < _Mysize ? _Off : _Mysize);
    if (_Count <= _Mysize)
    {
        const char* _Uptr = _Myptr() + (_Off < _Mysize - _Count ? _Off : _Mysize - _Count);
        for (;; --_Uptr)
            if (CharTraitsQ::eq(*_Uptr, *_Ptr) && CharTraitsQ::compare(_Uptr, _Ptr, _Count) == 0)
                return (_Uptr - _Myptr());
            else if (_Uptr == _Myptr())
                break;
    }

    return (::g_010173f0);
}

struct S00a1bc20_Guard
{
    ~S00a1bc20_Guard()
    {
        int u1;
        int u2;
    }
};

class S00a1bc20_Obj
{
  public:
    void FUN_00a1bc20();
};

// @fnv 0x00a1bc20
void S00a1bc20_Obj::FUN_00a1bc20()
{
    S00a1bc20_Guard guard;
    reinterpret_cast<::fnv_00a1c2d0::FUN_00a1c2d0_shell *>((this))->FUN_00a1c2d0();
}

struct MapItemE900
{
    MapItemE900* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBaseE900
{
  public:
    virtual ~MapBaseE900()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItemE900* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItemE900* pkItem);
    virtual MapItemE900* NewItem();
    virtual void DeleteItem(MapItemE900* pkItem);

    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemE900* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    MapItemE900** m_ppkHashTable;
    unsigned int m_uiCount;
};

class PointerMapE900 : public MapBaseE900
{
  public:
    virtual ~PointerMapE900()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

class FUN_00a1e900 : public PointerMapE900
{
  public:
    virtual ~FUN_00a1e900();
    bool m_bCopy;
};

// @fnv 0x00a1e900
FUN_00a1e900::~FUN_00a1e900()
{
    if (m_bCopy)
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            MapItemE900* pkItem = m_ppkHashTable[i];
            while (pkItem)
            {
                MapItemE900* pkSave = pkItem;
                pkItem = pkItem->m_pkNext;
                ::FUN_00aa10f0((char*)pkSave->m_key);
            }
        }
    }
}

struct MapItemE9F0
{
    MapItemE9F0* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBaseE9F0
{
  public:
    virtual ~MapBaseE9F0()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItemE9F0* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItemE9F0* pkItem);
    virtual MapItemE9F0* NewItem();
    virtual void DeleteItem(MapItemE9F0* pkItem);

    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemE9F0* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    MapItemE9F0** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00a1e9f0 : public MapBaseE9F0
{
  public:
    virtual ~FUN_00a1e9f0();
};

// @fnv 0x00a1e9f0
FUN_00a1e9f0::~FUN_00a1e9f0()
{
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
}

struct BucketNode
{
    BucketNode* next;
    void* key;
};

struct PointerArrayBase
{
    unsigned int bucketCount;
    BucketNode** buckets;
    unsigned int itemCount;
    virtual ~PointerArrayBase()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(buckets);
    }
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void ReleaseValue(BucketNode* node);
    virtual void Reserved5();
    virtual void FreeNode(BucketNode* node);
    void ClearAll()
    {
        for (unsigned int index = 0; index < bucketCount; ++index)
        {
            while (buckets[index])
            {
                BucketNode* node = buckets[index];
                buckets[index] = node->next;
                ReleaseValue(node);
                FreeNode(node);
            }
        }
        itemCount = 0;
    }
};

struct KeyMapBase : PointerArrayBase
{
    virtual ~KeyMapBase()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

struct FUN_00a1ec70 : KeyMapBase
{
    bool freeKeys;
    virtual ~FUN_00a1ec70();
};

// @fnv 0x00a1ec70
FUN_00a1ec70::~FUN_00a1ec70()
{
    if (freeKeys)
    {
        for (unsigned int i = 0; i < bucketCount; ++i)
        {
            BucketNode* node = buckets[i];
            while (node)
            {
                BucketNode* saved = node;
                node = node->next;
                ::FUN_00aa10f0(saved->key);
            }
        }
    }
}

namespace fnv_00a1ed60 {
struct WeightedMapNode
{
    WeightedMapNode* next;
};

struct PointerArrayBase
{
    unsigned int bucketCount;
    WeightedMapNode** buckets;
    unsigned int itemCount;
    virtual ~PointerArrayBase()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(buckets);
    }
    virtual void Reserved1();
    virtual void Reserved2();
    virtual void Reserved3();
    virtual void ReleaseValue(WeightedMapNode* node);
    virtual void Reserved5();
    virtual void FreeNode(WeightedMapNode* node);
    void ClearAll()
    {
        for (unsigned int index = 0; index < bucketCount; ++index)
        {
            while (buckets[index])
            {
                WeightedMapNode* node = buckets[index];
                buckets[index] = node->next;
                ReleaseValue(node);
                FreeNode(node);
            }
        }
        itemCount = 0;
    }
};

struct FUN_00a1ed60 : PointerArrayBase
{
    virtual ~FUN_00a1ed60();
};

// @fnv 0x00a1ed60
FUN_00a1ed60::~FUN_00a1ed60()
{
    reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
}
}

// namespace fnv_00a1ed60


struct MemoryManagerD4D0
{
};

struct MapItemD4D0
{
    MapItemD4D0* m_pkNext;
    const char* m_key;
    void* m_val;
};

class FUN_00a0d4d0
{
  public:

// @fnv 0x00a0d4d0
    virtual ~FUN_00a0d4d0()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItemD4D0* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItemD4D0* pkItem);
    virtual MapItemD4D0* NewItem();
    virtual void DeleteItem(MapItemD4D0* pkItem);

    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemD4D0* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    MapItemD4D0** m_ppkHashTable;
    unsigned int m_uiCount;
};

void* MakeMapD4D0()
{
    return new FUN_00a0d4d0;
}

struct MemoryManagerD520
{
};

struct MapItemD520
{
    MapItemD520* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBaseD520
{
  public:
    virtual ~MapBaseD520()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItemD520* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItemD520* pkItem);
    virtual MapItemD520* NewItem();
    virtual void DeleteItem(MapItemD520* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemD520* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItemD520** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00a0d520 : public MapBaseD520
{
// @fnv 0x00a0d520
  public:
    __forceinline FUN_00a0d520()
    {}
    virtual ~FUN_00a0d520()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

void* MakeMapD520()
{
    return new FUN_00a0d520;
}

struct MemoryManagerD840
{
};

struct MapItemD840
{
    MapItemD840* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBaseD840
{
  public:
    virtual ~MapBaseD840()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItemD840* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItemD840* pkItem);
    virtual MapItemD840* NewItem();
    virtual void DeleteItem(MapItemD840* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemD840* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItemD840** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00a0d840 : public MapBaseD840
{
// @fnv 0x00a0d840
  public:
    __forceinline FUN_00a0d840()
    {}
    virtual ~FUN_00a0d840()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

void* MakeMapD840()
{
    return new FUN_00a0d840;
}

struct MemoryManagerE7E0
{
};

struct MapItemE7E0
{
    MapItemE7E0* m_pkNext;
    const char* m_key;
    void* m_val;
};

class MapBaseE7E0
{
  public:
    virtual ~MapBaseE7E0()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItemE7E0* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItemE7E0* pkItem);
    virtual MapItemE7E0* NewItem();
    virtual void DeleteItem(MapItemE7E0* pkItem);
    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemE7E0* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }
    unsigned int m_uiHashSize;
    MapItemE7E0** m_ppkHashTable;
    unsigned int m_uiCount;
};

class FUN_00a1e7e0 : public MapBaseE7E0
{
// @fnv 0x00a1e7e0
  public:
    __forceinline FUN_00a1e7e0()
    {}
    virtual ~FUN_00a1e7e0()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

void* MakeMapE7E0()
{
    return new FUN_00a1e7e0;
}

struct MemoryManagerE8B0
{
};

struct MapItemE8B0
{
    MapItemE8B0* m_pkNext;
    const char* m_key;
    void* m_val;
};

class FUN_00a1e8b0
{
  public:

// @fnv 0x00a1e8b0
    virtual ~FUN_00a1e8b0()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_ppkHashTable);
    }
    virtual unsigned int KeyToHashIndex(const char* key) const;
    virtual bool IsKeysEqual(const char* key1, const char* key2) const;
    virtual void SetValue(MapItemE8B0* pkItem, const char* key, void* val);
    virtual void ClearValue(MapItemE8B0* pkItem);
    virtual MapItemE8B0* NewItem();
    virtual void DeleteItem(MapItemE8B0* pkItem);

    void RemoveAll()
    {
        for (unsigned int i = 0; i < m_uiHashSize; i++)
        {
            while (m_ppkHashTable[i])
            {
                MapItemE8B0* pkSave = m_ppkHashTable[i];
                m_ppkHashTable[i] = m_ppkHashTable[i]->m_pkNext;
                ClearValue(pkSave);
                DeleteItem(pkSave);
            }
        }
        m_uiCount = 0;
    }

    unsigned int m_uiHashSize;
    MapItemE8B0** m_ppkHashTable;
    unsigned int m_uiCount;
};

void* MakeMapE8B0()
{
    return new FUN_00a1e8b0;
}

struct C_00a1eb20
{
    int m_uiItemCount;
    void** m_data;
    int m_live;
    virtual void v10(void* p)
    {}
    virtual void v18(void* p)
    {}
    void RemoveAll()
    {
        for (int i = 0; i < m_uiItemCount; i++)
        {
            if (m_data[i])
            {
                void* pkSave = m_data[i];
                m_data[i] = *(void**)m_data[i];
                v10(pkSave);
                v18(pkSave);
            }
        }
        m_live = 0;
    }
    virtual ~C_00a1eb20()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_data);
    }
};

struct FUN_00a1eb20 : C_00a1eb20
{
// @fnv 0x00a1eb20
    virtual ~FUN_00a1eb20()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

void make_00a1eb20()
{
    new FUN_00a1eb20;
}

struct StrMem
{
    char* data;
    unsigned short length, capacity;
    unsigned int MaxLength();
    void SetLength(unsigned int);
    void SetMaxLength(unsigned int);
    bool Set(const char* source, unsigned int requested)
    {
        unsigned int len = source ? ::FUN_0044a670(source) : 0;
        unsigned int max = ::FUN_00403940(len, requested);
        if (max <= MaxLength())
        {
            if (max)
            {
                if (source)
                    memcpy(data, source, len + 1);
                else
                    data[0] = 0;
            }
            else
            {
                if (data)
                {
                    char* released = data;
                    delete[] released;
                }
                data = 0;
                max = 0;
                SetMaxLength(max);
            }
        }
        else
        {
            char* old = data;
            data = new char[max + 1];
            if (source)
                memcpy(data, source, len + 1);
            else
                data[0] = 0;
            if (old)
            {
                char* released = old;
                delete[] released;
            }
            SetMaxLength(max);
        }
        SetLength(len);
        return len != 0;
    }
    ~StrMem()
    {
        reinterpret_cast<::TextString *>(this)->FUN_004037f0(0, 0);
    }
};

class FUN_00a0bb50
{
  public:
    StrMem first, second, third;
    ~FUN_00a0bb50();
};

// @fnv 0x00a0bb50
FUN_00a0bb50::~FUN_00a0bb50()
{}

struct Base670
{
    int m_field;
    void* m_data;
    void ClearAll()
    {
        while (m_field)
        {
            void* p1 = m_data;
            ::FUN_00aa10f0(p1);
            void* p2 = m_data;
            ::FUN_00aa10f0(p2);
            m_field--;
        }
    }
    virtual ~Base670()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
        ::FUN_00aa10f0(m_data);
    }
};

struct FUN_00a0d670 : Base670
{
// @fnv 0x00a0d670
    virtual ~FUN_00a0d670()
    {
        reinterpret_cast<::AE91F0Map *>(this)->ClearAll();
    }
};

void Make670()
{
    delete new FUN_00a0d670;
}

struct TNode_a1be10
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
    void* unk2c;
};

static __forceinline void Dead8()
{
    int aiD[8];
}

struct ListHead_a1be10
{
    int m_00;
    int m_04;
    int m_08;
    ListHead_a1be10()
    {
        m_08 = 0;
        m_00 = 0;
        m_04 = 0;
        Dead8();
    }
    ~ListHead_a1be10();
};

struct Owner_a1be10
{
    ListHead_a1be10 m_kNode;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20[8];
    int m_40;

    Owner_a1be10(int p1, TNode_a1be10* p2, int p3, int p4);
};

// @fnv 0x00a1be10
Owner_a1be10::Owner_a1be10(int p1, TNode_a1be10* p2, int p3, int p4)
{
    m_10 = p2->unk18 + p2->unk14;
    m_14 = p3;
    m_18 = p4;
    m_40 = p1;
    reinterpret_cast<::FUN_00ae8bf0_t *>(this)->AddItem(&p2);
    m_1c = 0x23;
    p2->unk2c = this;
    for (int i = 0; i < 8; ++i)
        m_20[i] = 0;
}

// Appends _Count characters from _Ptr to the string, growing the buffer if needed and handling self-referential input.
// @fnv 0x00a0c430
StrA& StrA::FUN_00a0c430(const char* apChars, unsigned int auiCount)
{
    if (_Inside(apChars))
        return (*(::StrA *)&(reinterpret_cast<::StrB *>(this)->FUN_00a0c570((const ::StrB &)(*this), apChars - (16 <= _Myres ? _Bx._Ptr : _Bx._Buf), auiCount)));
    if (::g_010173f0 - _Mysize <= auiCount || _Mysize + auiCount < _Mysize)
        throw std::length_error("string too long");
    unsigned int uiNewSize;
    char acReserved[44];
    if (0 < auiCount && reinterpret_cast<::FUN_0044a8d0_Class *>(this)->FUN_0044a8d0(uiNewSize = _Mysize + auiCount, false))
    {
        _Secure_char_traits_tag _Tag;
        _Secure_char_traits_tag _Tag2;
        {
            char* pDest;
            {
                unsigned int uiTailSize;
                pDest = (16 <= _Myres ? _Bx._Ptr : _Bx._Buf) + (uiTailSize = _Myres - _Mysize, _Mysize);
                _Tag2 = _Tag;
                fnv::crt::memcpy_s(pDest, uiTailSize, apChars, auiCount);
                char cNul = 0;
                _Mysize = uiNewSize;
                (16 <= _Myres ? _Bx._Ptr : _Bx._Buf)[uiNewSize] = cNul;
            }
        }
    }
    return *this;
}

// @fnv 0x00a1ea70
void* FUN_00a1ea70_Class::FUN_00a1ea70(unsigned int auiFlags)
{
    Q7 q;
    (void)q;
    reinterpret_cast<::FUN_00a1e900 *>((((FUN_00a1e900_Class*)this)))->FUN_00a1e900::~FUN_00a1e900();
    if ((auiFlags & 1) != 0)
        reinterpret_cast<::FNV_MemoryManager *>(&(::g_memoryManager))->FUN_00aa4060((void*)this);
    return this;
}

// Calls FUN_00a1ec70, then if bit 0 of flags is set calls DAT_011f6238.FUN_00aa4060 on this, and returns this.
// @fnv 0x00a1ec40
FUN_00a1ec40_Class* FUN_00a1ec40_Class::FUN_00a1ec40(unsigned int flags)
{
    int l0, l1, l2, l3, l4, l5, l6;
    reinterpret_cast<::FUN_00a1ec70 *>(this)->FUN_00a1ec70::~FUN_00a1ec70();
    if (flags & 1)
        reinterpret_cast<::FNV_MemoryManager *>(&((*reinterpret_cast<::FUN_00aa4060_Class *>(&::g_memoryManager))))->FUN_00aa4060(this);
    return this;
}
