
// src/fallout_shared/pathfinding/navmeshbounds.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/navmeshbounds.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "runtime/crt.h"
#include "fnv/decl/FUN_0069ccf0_class.h"
#include "fnv/decl/FUN_0076b610_Class.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00407000.h"
// Replaces the integer pointed to by p with the result of calling FUN_00ec3bad on its current value.
// @fnv 0x00401080
void FUN_00401080(int* piValue)
{
    int* q = piValue;
    *q = fnv::crt::byteswap_ulong(*q);
}

struct Vec3i
{
    int x;
    int y;
    int z;
};
struct Elem12
{
    int x;
    int y;
    int z;
    Elem12();
};
struct Elem6
{
    short x;
    short y;
    short z;
};
struct Arr12
{
    int f0;
    Elem12* m_data;
    unsigned int m_uiItemCount;
    int f12;
    Elem12* FUN_006a1440(unsigned int);
};
struct Arr6
{
    int f0;
    Elem6* m_data;
    unsigned int m_uiItemCount;
    int f12;
};
struct ByteArg
{
    unsigned char c;
};

struct Owner69c4c0
{
    Vec3i m_kPointA;
    Vec3i m_kPointB;
    Arr6 m_arr6;
    Arr12 m_arr12;
    void WriteToBuffer(char* p);
};

// @fnv 0x0069c4c0
void Owner69c4c0::WriteToBuffer(char* apBuffer)
{
    unsigned short w;
    Vec3i v;
    unsigned int count2;
    Elem12* arr;
    unsigned int bytes5;
    Elem6* arr2_2;
    unsigned int i3;
    unsigned int i4;
    int j;

    v = m_kPointA;
    if (((bool)(::FUN_00401500())))
    {
        ::FUN_00401080(&v.x);
        ::FUN_00401080(&v.y);
        ::FUN_00401080(&v.z);
    }
    ::__memcpy(apBuffer, &v, 12);
    apBuffer += 12;
    v = m_kPointB;
    if (((bool)(::FUN_00401500())))
    {
        ::FUN_00401080(&v.x);
        ::FUN_00401080(&v.y);
        ::FUN_00401080(&v.z);
    }
    ::__memcpy(apBuffer, &v, 12);
    apBuffer += 12;
    w = (unsigned short)((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_arr12))->GetName()));
    if (((bool)(::FUN_00401500())))
    {
        ::FUN_00407a90((short*)&w);
    }
    ::__memcpy(apBuffer, &w, 2);
    apBuffer += 2;
    w = (unsigned short)((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_arr6))->GetName()));
    if (((bool)(::FUN_00401500())))
    {
        ::FUN_00407a90((short*)&w);
    }
    ::__memcpy(apBuffer, &w, 2);
    apBuffer += 2;
    if (!reinterpret_cast<::FUN_0076b610_Class *>(&(m_arr12))->FUN_0076b610())
    {
        count2 = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_arr12))->GetName()));
        bytes5 = count2 * 12;
        arr = new Elem12[count2];
        ::__memcpy(arr, m_arr12.FUN_006a1440(0), bytes5);
        if (((bool)(::FUN_00401500())))
        {
            for (i3 = 0; i3 < count2; i3++)
            {
                ::FUN_00401080(&arr[i3].x);
                ::FUN_00401080(&arr[i3].y);
                ::FUN_00401080(&arr[i3].z);
            }
        }
        ::__memcpy(apBuffer, arr, bytes5);
        apBuffer += bytes5;
        delete[] arr;
        arr = 0;
        count2 = ((unsigned int)(std::uintptr_t)(reinterpret_cast<::Twin_0044ddc0 *>(&(m_arr6))->GetName()));
        bytes5 = count2 * 6;
        arr2_2 = new Elem6[count2];
        ::__memcpy(arr2_2, ((::Elem6 *)(std::uintptr_t)(reinterpret_cast<::FUN_0069ccf0_class *>(&(m_arr6))->FUN_0069ccf0(0))), bytes5);
        if (((bool)(::FUN_00401500())))
        {
            for (i4 = 0; i4 < count2; i4++)
            {
                for (j = 0; j < 3; j++)
                {
                    ::FUN_00407a90(&arr2_2[i4].x + j);
                }
            }
        }
        ::__memcpy(apBuffer, arr2_2, bytes5);
        apBuffer += bytes5;
        delete[] arr2_2;
        arr2_2 = 0;
    }
}
