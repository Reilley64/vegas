
// src/havok/common/base/reflection/hkclassmemberaccessor.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassmemberaccessor.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cstdint>
#include "fnv/decl/FUN_00d87150_class.h"
struct FUN_00d87210_class
{
    char* m_p;
    char* FUN_00d87210(int index);
};

// @fnv 0x00d87210
char* FUN_00d87210_class::FUN_00d87210(int index)
{
    return m_p + index * 4;
}

// @fnv 0x00d87220
char* FUN_00d87220(char* self, int edx, int index)
{
    return *(char**)self + index * 4;
}

struct FUN_00d87260_cls
{
    char* FUN_00d87260(int a);
};

// @fnv 0x00d87260
char* FUN_00d87260_cls::FUN_00d87260(int a)
{
    return *reinterpret_cast<char**>(this) + a * 2;
}

// @fnv 0x00d87290
const void* FUN_00d87290(const void* pThis, int, int index)
{
    return (const char*)(*(const char**)pThis) + index * 8;
}

struct FUN_00d872a0_t
{
    void* FUN_00d872a0(int arg);
};

// @fnv 0x00d872a0
void* FUN_00d872a0_t::FUN_00d872a0(int arg)
{
    return (char*)*(void**)this + 8 * arg;
}

// @fnv 0x00d872c0
short* FUN_00d872c0(short** self, int edx, int offset)
{
    return *self + offset;
}

struct FUN_00d87300_class
{
    int* FUN_00d87300(int index);
};

// @fnv 0x00d87300
int* FUN_00d87300_class::FUN_00d87300(int index)
{
    return *(int**)this + index * 4;
}

// @fnv 0x00d87310
void* FUN_00d87310(void* self, int, int index)
{
    return (char*)*(void**)self + index * 3 * 16;
}

// @fnv 0x00d87350
intptr_t FUN_00d87350(int* self, int, int idx)
{
    int base = *self;
    return base + idx * 12;
}

struct IntArrayView
{
    int* data;
    int* FUN_00d87270(int index);
};
// @fnv 0x00d87270
int* IntArrayView::FUN_00d87270(int index)
{
    return data + index;
}

struct FUN_00d87280_class
{
    int* m_p;
    int* FUN_00d87280(int index);
};

// @fnv 0x00d87280
int* FUN_00d87280_class::FUN_00d87280(int index)
{
    return m_p + index;
}

struct FUN_00d872b0_class
{
    int* data;
    int* FUN_00d872b0(int index);
};

// @fnv 0x00d872b0
int* FUN_00d872b0_class::FUN_00d872b0(int index)
{
    return &data[index];
}

struct FUN_00d872d0_class
{
    char* m_p;
    char* FUN_00d872d0(int index);
};

// @fnv 0x00d872d0
char* FUN_00d872d0_class::FUN_00d872d0(int index)
{
    return m_p + index * 2;
}

struct CpuObject
{
    char* value;
    signed char* FUN_00d872e0(int amount);
};
// @fnv 0x00d872e0
signed char* CpuObject::FUN_00d872e0(int amount)
{
    return (signed char*)(value + amount);
}

struct FUN_00d87360_class
{
    char* m_p;
    char* FUN_00d87360(int index);
};
// @fnv 0x00d87360
char* FUN_00d87360_class::FUN_00d87360(int index)
{
    return m_p + index * 8;
}

struct Pair
{
    void* first;
    void* second;
    Pair& FUN_00d873d0(const Pair& other);
};

// @fnv 0x00d873d0
Pair& Pair::FUN_00d873d0(const Pair& other)
{
    first = other.first;
    second = other.second;
    return *this;
}

struct D871A0Array
{
    void* m_data;
    intptr_t m_iElementCount;
    int m_iCapacityState;
};

struct D871A0Buffer
{
    D871A0Buffer& FUN_00d871a0(const D871A0Array& a, intptr_t flags);
};

// Appends the array's data buffer with its size and flags to this buffer, then returns this buffer.
// @fnv 0x00d871a0
D871A0Buffer& D871A0Buffer::FUN_00d871a0(const D871A0Array& apArray, intptr_t flags)
{
    reinterpret_cast<::FUN_00d87150_class *>(this)->InitBitOffset((intptr_t)(apArray.m_data), (::FUN_00d46fe0_class *)(apArray.m_iElementCount), (const char *)(flags));
    return *this;
}

struct TargetClass
{
    void* ptr;
    bool* FUN_00d871e0(bool* out);
};

// @fnv 0x00d871e0
bool* TargetClass::FUN_00d871e0(bool* out)
{
    *out = (this->ptr != 0);
    return out;
}

struct D87240Array
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    char& FUN_00d87240(int i);
};

// @fnv 0x00d87240
char& D87240Array::FUN_00d87240(int i)
{
    return m_data[i];
}

struct D87250Array
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int& FUN_00d87250(int i);
};

// @fnv 0x00d87250
int& D87250Array::FUN_00d87250(int i)
{
    return m_data[i];
}

struct FUN_00d872f0_class
{
    char* m_uiFilterValue;
    unsigned char* FUN_00d872f0(int offset);
};

// @fnv 0x00d872f0
unsigned char* FUN_00d872f0_class::FUN_00d872f0(int offset)
{
    return (unsigned char*)(m_uiFilterValue + offset);
}

struct SearchObject
{
    unsigned int field00;
    int FUN_00d87320(unsigned int arg0);
};
// @fnv 0x00d87320
int SearchObject::FUN_00d87320(unsigned int arg0)
{
    return (int)((arg0 << (6u & 31u)) + field00);
}

struct FUN_00d87330_class
{
    char* m_p;
    char* FUN_00d87330(int index);
};

// @fnv 0x00d87330
char* FUN_00d87330_class::FUN_00d87330(int index)
{
    return m_p + index * 0x30;
}

struct FUN_00d87340_cls
{
    Pair* m_p;

    Pair* FUN_00d87340(int index);
};

// @fnv 0x00d87340
Pair* FUN_00d87340_cls::FUN_00d87340(int index)
{
    return m_p + index;
}

struct FnvCpu_FUN_00d871f0_CpuObject
{
    int value;
    intptr_t FUN_00d871f0();
};
// @fnv 0x00d871f0
intptr_t FnvCpu_FUN_00d871f0_CpuObject::FUN_00d871f0()
{
    return value;
}

struct FUN_00d87200_cls
{
    void* m_data;
    void* FUN_00d87200();
};

// @fnv 0x00d87200
void* FUN_00d87200_cls::FUN_00d87200()
{
    return m_data;
}

struct D87370Obj
{
    void* unk00;
    int unk04;
    intptr_t FUN_00d87370();
};

// @fnv 0x00d87370
intptr_t D87370Obj::FUN_00d87370()
{
    return unk04;
}

struct StringMemberAccessor
{
    int* values;
    int* FUN_00d87230(int index);
};

// @fnv 0x00d87230
int* StringMemberAccessor::FUN_00d87230(int index)
{
    return values + index;
}
