// src/bsshader/bsshadernolightingproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/bsshadernolightingproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "fnv/decl/ScriptPool.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00b6f4a0_class.h"
#include "fnv/symbols_00b6f000.h"
struct ArgObject
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual int GetCount();
};

struct ScopedRef
{
    int unk00;

    ScopedRef(ArgObject* apArg);
    ~ScopedRef();
};

struct Sub24Object
{
};

struct FUN_00439410_cls
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
    Sub24Object m_k24;

    void FUN_00439410(ArgObject* apArg);
};

// If apArg's count is below 7, constructs a ScopedRef from apArg and passes it to m_k24.FUN_00439fd0.
// @fnv 0x00439410
void FUN_00439410_cls::FUN_00439410(ArgObject* apArg)
{
    if (apArg->GetCount() < 7)
    {
        ScopedRef ref(apArg);
        reinterpret_cast<::ScriptPool *>(&(m_k24))->FUN_00439fd0(&ref);
    }
}

struct S_00b6fa40_Link
{
    int unk00, unk04, unk08, unk0c;
    int unk10;
};

struct S_00b6fa40_Prop
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    int unk1c;
    unsigned int unk20;
    int unk24, unk28, unk2c, unk30, unk34;
    int unk38;
    S_00b6fa40_Link* unk3c;
};

struct S_00b6fa40_Obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual S_00b6fa40_Obj* v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
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
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    S_00b6fa40_Obj** unka0;
    short unka4;
    unsigned short unka6;
};

static inline int IsLighting(S_00b6fa40_Prop* p)
{
    if (!p)
        return 0;
    return p->unk1c == 0x15;
}

// @fnv 0x00b6fa40
void __cdecl FUN_00b6fa40(S_00b6fa40_Obj* obj, const float* pf)
{
    if (!obj)
        return;
    if (obj->v7())
    {
        S_00b6fa40_Prop* p = ((::S_00b6fa40_Prop *)(reinterpret_cast<::FUN_00a59d30_C *>((obj))->FUN_00a59d30(3)));
        if (!IsLighting(p))
            return;
        if (*pf != -1.0f)
        {
            if (!((char)p->unk20 & 0x40))
            {
                p->unk38 = 0;
            }
            p->unk20 |= 0x40;
            reinterpret_cast<::FUN_00b6f4a0_class *>((p))->CopySourceValues(pf);
        }
        else
        {
            if ((char)p->unk20 & 0x40)
            {
                p->unk38 = 0;
            }
            p->unk20 &= ~0x40;
        }
        if (p->unk3c)
        {
            p->unk3c->unk10 = 0;
        }
        return;
    }
    S_00b6fa40_Obj* n = obj->v3();
    if (n)
    {
        unsigned int count = n->unka6;
        for (unsigned int i = 0; i < count; i++)
        {
            S_00b6fa40_Obj* c = n->unka0[i];
            if (c)
            {
                FUN_00b6fa40(c, pf);
            }
        }
    }
}
