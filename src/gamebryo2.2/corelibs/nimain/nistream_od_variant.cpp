
// src/gamebryo2.2/corelibs/nimain/nistream_od_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nistream.cpp functions whose prologue its flags cannot
// produce (ebp frame in an /O2 unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "fnv/decl/FUN_00a2ceb0_cls.h"
#include "fnv/decl/FUN_00a63460_shell.h"
#include "fnv/decl/FUN_00c4c920_class.h"
#include "fnv/decl/StreamHack.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00a89000.h"
#include "nistream_decls.h"

struct NiStream2
{
    void FUN_00c3b370();
};
// @fnv 0x00c3b370
void NiStream2::FUN_00c3b370()
{
    reinterpret_cast<::NiStream *>(this)->ClearTopLevelObjects();
    *(int*)((char*)this + 0x25c) = 0;
    *(int*)((char*)this + 0x26c) = 0;
    *(int*)((char*)this + 0x260) = 0;
    *(int*)((char*)this + 0x270) = 0;
    reinterpret_cast<::StreamHack *>(this)->Clear();
}

struct S_Obj
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc(S_Obj* pkA, int flag);
};

struct S_Stream
{
};

struct S_Arr
{
};

struct S_Class
{
    int unk00;
    int unk04;
    S_Arr unk08;
    void __thiscall FUN_00c64ad0(S_Stream* stream);
};

// @fnv 0x00c64ad0
void __thiscall S_Class::FUN_00c64ad0(S_Stream* stream)
{
    ::FUN_00a89af0((int)this);
    unsigned int count = reinterpret_cast<::FUN_00a63460_shell *>((stream))->FUN_00a63460();
    if (count)
    {
        reinterpret_cast<::FUN_00c4c920_class *>(&(unk08))->FUN_00c4c920(count);
        count >>= 1;
        for (unsigned int i = 0; i < count; i++)
        {
            int pkParent[3];
            S_Obj* pkA;
            S_Obj* ref;
            ref = ((::S_Obj *)(reinterpret_cast<::NiStream *>((stream))->GetLoadedObject()));
            pkA = ((::S_Obj *)(reinterpret_cast<::NiStream *>((stream))->GetLoadedObject()));
            if (ref && pkA)
            {
                ref->vfn_dc(pkA, 0);
            }
        }
    }
}
