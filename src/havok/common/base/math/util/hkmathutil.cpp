// src/havok/common/base/math/util/hkmathutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/util/hkmathutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
#include "fnv/decl/FUN_00827200_class.h"
#include "fnv/decl/FUN_00cdf230_cls.h"
#include "fnv/decl/MalleableGetterStandIn.h"
#include "fnv/decl/QuatResult.h"
#include "fnv/decl/RotationRows.h"
#include "fnv/decl/hkQuaternion.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_simd.h"

struct __declspec(align(16)) S_c7a410_Vec
{
    float x, y, z, w;
};
struct S_c7a410_A
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_c7a410_B
{
    __m128 r[3];
};
struct S_c7a410_C
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S_c7a410_D
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

struct S_c7a410_Node
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetType();
};
struct S_c7a410_Item
{
    int unk00;
    int unk04;
    int unk08;
    S_c7a410_Node* unk0c;
};
struct S_c7a410_Cnt
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_c7a410_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    S_c7a410_Item** unk14;
    int unk18;
    int unk1c;
    int* unk20;
    int unk24;
    int unk28;
    S_c7a410_Cnt* unk2c;
};

// Iterates indexed items, dispatches on node type, and reads per-item data from arr at 0x10 plus 0x30-byte strides.
// @fnv 0x00c7a410
void FUN_00c7a410(S_c7a410_Obj* obj, char* apBuffer)
{
    int iCount = obj->unk2c->unk1c;
    for (int iIndex = 0; iIndex < iCount; iIndex++)
    {
        int iArrayIndex = obj->unk20[iIndex] - 1;
        if (iArrayIndex < 0)
            continue;
        S_c7a410_Item* pItem = obj->unk14[iArrayIndex];
        if (!pItem)
            continue;
        S_c7a410_Node* p = pItem->unk0c;
        if (p->GetType() == 13)
            p = ((::S_c7a410_Node *)(reinterpret_cast<::MalleableGetterStandIn *>((p))->FUN_00cdf6c0()));
        switch (p->GetType())
        {
        case 7: {
            S_c7a410_B tTransform;
            reinterpret_cast<::RotationRows *>(&(tTransform))->FUN_00cb2d90((void *)(apBuffer + 0x10 + iIndex * 0x30));
            reinterpret_cast<::FUN_00cdf230_cls *>((p))->FUN_00cdf230((int)(&tTransform));
            break;
        }
        case 2: {
            S_c7a410_A a;
            reinterpret_cast<::FUN_00827200_class *>(&(a))->FUN_00cb26e0((int)((char*)p + 0x20));
            S_c7a410_A b;
            reinterpret_cast<::FUN_00827200_class *>(&(b))->FUN_00cb26e0((int)((char*)p + 0x60));
            S_c7a410_C c;
            ::fnv_00c66320::FUN_00c66320((::fnv_00c66320::__m128 *)&(c), (void *)(apBuffer + 0x10 + iIndex * 0x30), (const ::fnv_00c66320::__m128 *)(::S_c7a410_A *)(&a), {});
            S_c7a410_D d;
            reinterpret_cast<::QuatResult *>(&(d))->FUN_00c74b70((const float *)(::S_c7a410_A *)(&b), (const float *)(::S_c7a410_C *)(&c));
            S_c7a410_Vec v;
            _mm_store_ps(&v.x, _mm_setr_ps(DAT_01012068, ::DAT_01011d78, ::DAT_01011d78, ::DAT_01011d78));
            float out;
            S_c7a410_A o;
            reinterpret_cast<::hkQuaternion *>(&(d))->FUN_00cb2ca0((*(const ::hkVector4 *)(&v)), (*(::hkQuaternion *)(&o)), (*(float *)(&out)));
            *(float*)((char*)p + 0xac) = out;
            break;
        }
        }
    }
}
