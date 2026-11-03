
// src/speedtree/fileaccess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/fileaccess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdlib>
#include "fnv/decl/S_00aadeb0_Class.h"
#include "fnv/decl/fnv_0044a730__FUN_0044a730_cls.h"
#include "fnv/symbols_01017000.h"
struct FUN_00b3ede0_shell
{
    void* p;
    void* next;
    void* prev;
    unsigned int used;
    unsigned int size;
    void* FUN_00b3ede0();
};


// Checks the block has room for alloc bytes, calls FUN_00ec7c56 if not, advances p twice and returns the pointer at used+alloc.
// @fnv 0x00b3ede0
void* FUN_00b3ede0_shell::FUN_00b3ede0()
{
    unsigned int alloc = *(unsigned int*)this;
    FUN_00b3ede0_shell* block = (FUN_00b3ede0_shell*)((char*)this + 4);
    if (alloc >= (block->size - block->used))
        std::abort();
    void* result = (void*)((unsigned int)block->used + alloc);
    p = (void*)((unsigned int)p + 4);
    p = (void*)((unsigned int)p + 4);
    return *(void**)result;
}

struct Vector3D
{
    float m_fComponents[3];
};

struct FUN_00b3ef80_shell
{
    int m_iValueAt00;
    void* m_pObjectAt04;
    Vector3D GetVector3();
};

struct FUN_00b3ed20_range
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uBase;
    unsigned int m_uEnd;
};


struct FUN_00b3ed20_cls
{
    unsigned int m_nCursor;
    FUN_00b3ed20_range m_range;
    float FUN_00b3ed20();
};
// Builds a 3-component vector by calling FUN_00b3ed20 once per component and returns it.
// @fnv 0x00b3ef80
Vector3D FUN_00b3ef80_shell::GetVector3()
{
    Vector3D vecResult;
    int iComponent;
    vecResult.m_fComponents[2] = 0.0f;
    vecResult.m_fComponents[1] = 0.0f;
    vecResult.m_fComponents[0] = 0.0f;
    for (iComponent = 0; iComponent < 3; iComponent++)
        vecResult.m_fComponents[iComponent] = reinterpret_cast<::FUN_00b3ed20_cls *>(this)->FUN_00b3ed20();
    return vecResult;
}

// @fnv 0x00b3ed20
float FUN_00b3ed20_cls::FUN_00b3ed20()
{
    unsigned int idx = m_nCursor;
    FUN_00b3ed20_range* p2 = &m_range;
    if (idx >= p2->m_uEnd - p2->m_uBase)
    {
        std::abort();
    }
    float* ptr = (float*)(p2->m_uBase + idx);
    m_nCursor = m_nCursor + 4;
    return *ptr;
}

// Stand-in for the element array the object points at.
struct S_00b3ed80_Array
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* m_pData;       // +0x0c  first element
    void* m_pRecordEnd;  // +0x10  one past the last element
};

struct S_00b3ed80
{
    unsigned int m_nOffset;     // +0x00  byte offset of the next element
    S_00b3ed80_Array m_ppData;  // +0x04
    void* GetNextElement();
};

// Returns the element at m_nOffset in the array, advances m_nOffset by 4, and calls FUN_00ec7c56 if the offset is out of bounds.
// @fnv 0x00b3ed80
void* S_00b3ed80::GetNextElement()
{
    unsigned int offset = m_nOffset;
    S_00b3ed80_Array* pArray = &m_ppData;
    if (offset >= (unsigned int)((char*)pArray->m_pRecordEnd - (char*)pArray->m_pData))
        std::abort();
    void** element = (void**)((char*)pArray->m_pData + offset);
    m_nOffset = m_nOffset + 4;
    return *element;
}

// Constructor of an object whose base class constructor lives in another unit.

struct FUN_00b40150_base
{
    virtual void vBaseSlot();
    FUN_00b40150_base();
};

struct FUN_00b40150_cls : public FUN_00b40150_base
{
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    unsigned char m_unk10;
    int m_i14;
    unsigned char m_unk18;
    Vector3D m_vec1;
    Vector3D m_vec2;
    Vector3D m_vec3;
    unsigned char m_unk40;
    float m_f44;
    int m_i48;

    FUN_00b40150_cls();
};

// @fnv 0x00b40150
FUN_00b40150_cls::FUN_00b40150_cls()
{
    m_unk10 = 0;
    m_i14 = -1;
    m_unk18 = 0;

    Vector3D* v1 = &m_vec1;
    v1->m_fComponents[2] = 0.0f;
    v1->m_fComponents[1] = 0.0f;
    v1->m_fComponents[0] = 0.0f;

    Vector3D* v2 = &m_vec2;
    v2->m_fComponents[2] = 0.0f;
    v2->m_fComponents[1] = 0.0f;
    v2->m_fComponents[0] = 0.0f;

    Vector3D* v5 = &m_vec3;
    v5->m_fComponents[2] = 0.0f;
    v5->m_fComponents[1] = 0.0f;
    v5->m_fComponents[0] = 0.0f;

    m_unk40 = 0;
    m_f44 = 0.0f;
    m_i48 = 0;
}

struct Alloc_00b3ee40
{
    Alloc_00b3ee40()
    {}
};

struct Str_00b3ee40
{
    int f00;
    union
    {
        char buf[16];
        char* ptr;
    } bx;
    unsigned int mysize;
    unsigned int myres;
    Str_00b3ee40()
    {
        int k;
        Alloc_00b3ee40 c;
        Alloc_00b3ee40* pal = &c;
        int j, o, e, t, f7;
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
    }
    Str_00b3ee40(const Str_00b3ee40& rhs)
    {
        int k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16;
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(false, 0);
        AssignSubstring(rhs, 0, ::g_010173f0);
    }
    ~Str_00b3ee40()
    {
        reinterpret_cast<::fnv_0044a730::FUN_0044a730_cls *>(this)->FUN_0044a730(true, 0);
    }
    Str_00b3ee40& AssignSubstring(const Str_00b3ee40&, unsigned int, unsigned int);
    Str_00b3ee40& operator+=(char ch)
    {
        int k;
        char c;
        return (*(::Str_00b3ee40 *)(reinterpret_cast<::S_00aadeb0_Class *>(this)->AppendChars(1, ch)));
    }
};

struct Buf_00b3ee40
{
    int f00;
    int f04;
    int f08;
    char* first;
    char* last;
    unsigned int size() const
    {
        return last - first;
    }
    char& at(unsigned int i)
    {
        if (i >= size())
            std::abort();
        return first[i];
    }
};

struct Reader_00b3ee40
{
    unsigned int pos;
    Buf_00b3ee40 buf;
    Str_00b3ee40 FUN_00b3ee40();
};

// @fnv 0x00b3ee40
Str_00b3ee40 Reader_00b3ee40::FUN_00b3ee40()
{
    Str_00b3ee40 s;
    int count4 = ((int)(reinterpret_cast<::S_00b3ed80 *>(this)->GetNextElement()));
    for (int i3 = 0; i3 < count4; i3++)
    {
        s += buf.at(pos++);
    }
    return s;
}
