// fallout_shared/magic/magicitemobject.cpp: MagicItemObject, MagicItemObjectShell (5 functions)

#include "fnv/decl/B5B10Owner.h"
#include "fnv/decl/EffectItemList4056.h"
#include "fnv/decl/EffectListCmp.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/List.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "magicitemobject_decls.h"
// @fnv 0x0040c9d0
void MagicItemObject::InitItem()
{
    if (GetInitialized())
        return;
    LoadEffectsFromForm(this);
    SetInitializationState(true);
}

#include <malloc.h>
// Reads a magic item record's chunks (editor ID, bounds, full name, effects), warns when the effect list is empty, and returns true.
// @fnv 0x0040c650
bool MagicItemObject::Load(TESFile* file)
{
    int chunk;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    while (chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editor = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editor), 512);
            SetEditorID_AtRuntime(editor);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4c4c5546:
            ::ReadFullName(this, file);
            break;
        case 0x44494645:
        case 0x41445443:
            reinterpret_cast<::List *>(&(effectList))->FUN_00405760((::File *)(file), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(this)->FUN_00408da0())));
            break;
        }
        Unk_10(file, chunk);
        if (chunk == GetTypeSignature())
        {
            memset(Unk_0A(), 0, Unk_0B());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(Unk_0A()), Unk_0B());
            if (file->IsEndianConversionRequired())
                vfn_180();
        }
        if (!file->NextChunk())
            break;
    }
    if (!effectList.effects.ItemsInList())
        ::FUN_005b5e40();
    return true;
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct DoorPart30
{
};

struct FUN_0040c5f0_shell
{
    void FUN_0040c5f0();
};

// Calls M on the object, invokes FUN_00487010 and two virtual methods at offsets 0x38/0x3c on the subobject at 0x30, then FUN_004056d0 on this+0x3c and M again.
// @fnv 0x0040c5f0
void FUN_0040c5f0_shell::FUN_0040c5f0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((DoorPart30*)((char*)this + 0x30))))->FUN_00487010();
    (*(void(__thiscall**)(void*))(*(int*)((char*)this + 0x30) + 0x38))((char*)this + 0x30);
    (*(void(__thiscall**)(void*))(*(int*)((char*)this + 0x30) + 0x3c))((char*)this + 0x30);
    reinterpret_cast<::EffectItemList4056 *>(((char*)this + 0x3c))->FUN_004056d0();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct MagicItemCompare
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual bool CompareMagic(MagicItem* other);
    char name[8];
};
struct EffectListCompare
{
};
struct MagicItemObjectShell : TESForm, MagicItemCompare
{
    EffectItemList effectList;
    bool FUN_0040c870(TESForm* other);
};
// @fnv 0x0040c870
bool MagicItemObjectShell::FUN_0040c870(TESForm* other)
{
    MagicItemObject* converted = dynamic_cast<MagicItemObject*>(other);
    if (!converted)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(other))
        return true;
    if (CompareMagic(static_cast<MagicItem*>(converted)))
        return true;
    if (reinterpret_cast<::EffectListCmp *>((reinterpret_cast<EffectListCompare*>(&effectList)))->FUN_00405a00((::EffectListCmp *)(::EffectItemList *)(converted ? &converted->effectList : 0)))
        return true;
    return false;
}

struct FUN_0040c930_m30
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34(MagicItem* other);
};

struct FUN_00405b10_Obj
{
};

struct FUN_005054b0_shell
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
    FUN_0040c930_m30 m30;
    int unk34;
    int unk38;
    FUN_00405b10_Obj m3c;

    void FUN_0040c930(TESForm* arg);
};

extern int DAT_011830e8;

MagicItemObject* __cdecl FUN_00ec43fb(TESForm* arg, int a, int* b, int* c, int d);

// @fnv 0x0040c930
void FUN_005054b0_shell::FUN_0040c930(TESForm* pForm)
{
    MagicItemObject* result = FUN_00ec43fb(pForm, 0, &DAT_01183028, &DAT_011830e8, 0);
    if (!result)
        return;

    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(pForm);

    m30.vfn_34(result ? reinterpret_cast<MagicItem*>(reinterpret_cast<char*>(result) + 0x30) : 0);

    reinterpret_cast<::B5B10Owner *>(&(m3c))->CopyItemsFromList((::EffectItemList *)(result ? reinterpret_cast<int>(reinterpret_cast<char*>(result) + 0x3C) : 0));
}
