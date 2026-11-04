// bshavok/bhkconvert_decls.h: declares hkRotation, hkTransform, NiPoint3, NiTransform
#pragma once

#include "fnv/decl/FUN_0056d300_S.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S004586d0_Obj.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_004a3000.h"
#include "fnv/symbols_0056d000.h"
struct hkRotation;
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
};
struct __declspec(align(16)) VectorComponentValue
{
    char data[16];
};
struct __declspec(align(16)) hkVector4
{
    union
    {
        float data[4];
        char bytes[16];
    };
};
struct hkRotation
{
    float data[12];
};
struct hkTransform : hkRotation
{
    hkVector4 position;
};
struct NiPoint3
{
    float x, y, z;
};
struct ThreeByThreeMatrix
{
    float data[9];
};
struct NiTransform
{
    ThreeByThreeMatrix rotation;
    NiPoint3 position;
    float scale;
};
