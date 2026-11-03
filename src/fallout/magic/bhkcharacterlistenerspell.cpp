
// src/fallout/magic/bhkcharacterlistenerspell.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/bhkcharacterlistenerspell.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <new>
#include "fnv/decl/AlignedVector.h"
#include "fnv/decl/FUN_0043b4d0_shell.h"
#include "fnv/decl/FUN_005532a0_cls.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_00807730_shell.h"
#include "fnv/decl/FUN_00807770_Class.h"
#include "fnv/decl/FUN_0089f4e0_shell.h"
#include "fnv/decl/FnvCpu_FUN_00c89720_CpuInterface.h"
#include "fnv/decl/FnvCpu_FUN_00cac950_CpuObject.h"
#include "fnv/decl/GlobalObject_008c71b0.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00458000.h"
#include "fnv/symbols_004b5000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_01268000.h"
struct NiRTTI
{
};

struct bhkCharacterProxy
{
    virtual ~bhkCharacterProxy();
    const NiRTTI* GetRTTI();
};


// @fnv 0x00806f00
const NiRTTI* bhkCharacterProxy::GetRTTI()
{
    return &(*reinterpret_cast<const ::NiRTTI *>(&::g_01268344));
}

struct FUN_00806f10_shell
{
    unsigned int FUN_00806f10();
};

// @fnv 0x00806f10
unsigned int FUN_00806f10_shell::FUN_00806f10()
{
    return 0xc0;
}

struct NiObject
{
    virtual const NiRTTI* GetStreamableRTTI();
};
struct ProxyHolder
{
};
struct Holder00807080
{
    const char* FUN_00807080();
};
// Looks up a proxy holder via GetReferenceFlags; if found, returns its FUN_00cac950 result, otherwise returns FUN_00458b20's result.
// @fnv 0x00807080
const char* Holder00807080::FUN_00807080()
{
    ProxyHolder* pProxy = (ProxyHolder*)((int)(reinterpret_cast<::FUN_00620b80_shell *>((this))->GetReferenceFlags()));
    const char* pResult = ((const char *)(::FUN_00458b20()));
    if (pProxy)
    {
        reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>((((NiObject*)this)))->FUN_00c89720();
        pResult = reinterpret_cast<::FnvCpu_FUN_00cac950_CpuObject *>((pProxy))->FUN_00cac950();
        reinterpret_cast<::FnvCpu_FUN_00c89720_CpuInterface *>((((NiObject*)this)))->FUN_00c89720();
    }
    return pResult;
}

#include <xmmintrin.h>
struct Owner1;
struct Item;
struct Node;
struct Arg2;

struct Node2
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct Node
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
    Node2* m_48;
    int unk4C;
};

struct Str20
{
    int unk00;
};

struct __declspec(align(16)) Vec16
{
    __m128 m_v;
};

struct Item
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
};

struct ItemSub
{
};

struct Arg2
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
    Item* m_48;
    int m_4C;
};

struct Owner1
{
};

struct Global
{
};


struct ProxyUpdate
{
    void FUN_00806f20(Owner1* a1, Arg2* a2);
};

// For each item, checks its node's m_48 and calls FUN_004a3f10 on the item when branch conditions are met.
// @fnv 0x00806f20
void ProxyUpdate::FUN_00806f20(Owner1* apOwner, Arg2* apArgs)
{
    int count = apArgs->m_4C;
    for (int i = 0; i < count; i++)
    {
        Item* item = apArgs->m_48 + i;
        Node* pNode = ((::Node *)(reinterpret_cast<::FUN_00807770_Class *>((apOwner))->FUN_00807770(i)));
        int iResult1 = ((int)(::FUN_004b59f0(pNode->m_48)));
        Str20 s;
        new ((void *)&(s)) ::GlobalObject_008c71b0((int)(((void *)(::FUN_0043b540((char *)(pNode->m_48))))));
        int iResult3 = reinterpret_cast<::FUN_0043b4d0_shell *>(&(s))->FUN_0043b4d0();
        if (iResult1 == 0)
        {
            if (iResult3 != 0x1e)
            {
                reinterpret_cast<::AlignedVector *>((((ItemSub*)&item->unk10)))->FUN_004a3f10((*(const ::AlignedVector *)(((int)(reinterpret_cast<::Holder00807080 *>((this))->FUN_00807080())))));
                Vec16 t;
                reinterpret_cast<::AlignedVector *>((item))->FUN_004a3f10((*(const ::AlignedVector *)(((int)(reinterpret_cast<::FUN_005532a0_cls *>(&(t))->FUN_005532a0(0.0f, 0.0f, 0.0f, 1.0f))))));
            }
        }
        else
        {
            int iResult4 = ((int)(reinterpret_cast<::FUN_00807730_shell *>((this))->FUN_00807730(pNode->m_48)));
            if (iResult4 != 0 && iResult4 == ((int)(reinterpret_cast<::FUN_0089f4e0_shell *>(((*reinterpret_cast<::Global * *>(&::_g_thePlayer))))->FUN_0089f4e0())))
            {
                reinterpret_cast<::AlignedVector *>((((ItemSub*)&item->unk10)))->FUN_004a3f10((*(const ::AlignedVector *)(((int)(reinterpret_cast<::Holder00807080 *>((this))->FUN_00807080())))));
                Vec16 t;
                reinterpret_cast<::AlignedVector *>((item))->FUN_004a3f10((*(const ::AlignedVector *)(((int)(reinterpret_cast<::FUN_005532a0_cls *>(&(t))->FUN_005532a0(0.0f, 0.0f, 0.0f, 1.0f))))));
                break;
            }
        }
    }
}
