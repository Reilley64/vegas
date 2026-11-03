// fallout_shared/magic/magicitemform.cpp: MagicItemForm (5 functions)

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
#include "magicitemform_decls.h"
#include <malloc.h>
#include <string.h>

// @fnv 0x0040c230
bool MagicItemForm::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));

    int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* chunkData = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(chunkData), 0x200);
            SetEditorID_AtRuntime(chunkData);
            break;
        }

        case 0x444e424f:
            readOBNDSubRecord(file);
            break;

        case 0x4c4c5546: {
            ::ReadFullName(this ? (TESFullName*)((char*)this + 0x18) : 0, file);
            break;
        }

        case 0x44494645:
        case 0x41445443:
            reinterpret_cast<::List *>((((EffectItemList*)((char*)this + 0x24))))->FUN_00405760((::File *)(file), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((TESFullName*)((char*)this + 0x18))))->FUN_00408da0())));
            break;

        default:
            break;
        }

        ((MagicItem*)((char*)this + 0x18))->LoadMagicItemChunk(file, chunkID);

        if (chunkID == ((MagicItem*)((char*)this + 0x18))->GetTypeSignature())
        {
            memset(((MagicItem*)((char*)this + 0x18))->GetData(), 0, ((MagicItem*)((char*)this + 0x18))->GetDataSize());

            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(((MagicItem*)((char*)this + 0x18))->GetData()),
                               ((MagicItem*)((char*)this + 0x18))->GetDataSize());

            if (file->IsEndianConversionRequired())
                Endian();
        }

        if (!file->NextChunk())
            break;
    }

    if (((BSSimpleList<EffectSetting*>*)((char*)this + 0x28))->ItemsInList() == 0)
    {
        ::FUN_005b5e40();
    }

    return true;
}

// @fnv 0x0040c5b0
void MagicItemForm::InitItem()
{
    if (GetInitialized())
        return;
    ((MagicItem*)((char*)this + 0x18))->LoadEffectsFromForm(this);
    SetInitializationState(true);
}

struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct S_00487010
{
};
struct V18
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};
struct FUN_0040c1d0_obj
{
    void FUN_0040c1d0();
};
// Calls M on the object, runs FUN_00487010 and v14/v15 on the sub-object at offset 0x18, then FUN_004056d0 on offset 0x24 and M again.
// @fnv 0x0040c1d0
void FUN_0040c1d0_obj::FUN_0040c1d0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>((((S_00487010*)((char*)this + 0x18))))->FUN_00487010();
    ((V18*)((char*)this + 0x18))->v14();
    ((V18*)((char*)this + 0x18))->v15();
    reinterpret_cast<::EffectItemList4056 *>(((void*)((char*)this + 0x24)))->FUN_004056d0();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

struct FUN_005e79a0_t
{
};

struct FUN_0040c450_MagicItem
{
    virtual bool v0();
    virtual bool v1();
    virtual bool v2();
    virtual bool v3();
    virtual bool v4();
    virtual bool v5();
    virtual bool v6();
    virtual bool v7();
    virtual bool v8();
    virtual bool v9();
    virtual bool v10();
    virtual bool v11();
    virtual bool v12(FUN_0040c450_MagicItem*);
};

struct FUN_0040c450_EffectItemList
{
};

struct FUN_0040c450_shell
{
    bool FUN_0040c450(TESForm*);
};

// @fnv 0x0040c450
bool FUN_0040c450_shell::FUN_0040c450(TESForm* apCompare)
{
    MagicItemForm* pmagicItem = dynamic_cast<MagicItemForm*>(apCompare);

    if (!pmagicItem)
        return true;

    if (reinterpret_cast<::FUN_00509540_obj *>((reinterpret_cast<FUN_005e79a0_t*>(this)))->FUN_00485270(apCompare))
        return true;

    if (reinterpret_cast<FUN_0040c450_MagicItem*>(reinterpret_cast<char*>(this) + 0x18)
            ->v12(pmagicItem ? reinterpret_cast<FUN_0040c450_MagicItem*>(reinterpret_cast<char*>(pmagicItem) + 0x18)
                             : 0))
        return true;

    if (reinterpret_cast<::EffectListCmp *>((reinterpret_cast<FUN_0040c450_EffectItemList*>(reinterpret_cast<char*>(this) + 0x24)))->FUN_00405a00(
                (::EffectListCmp *)(::FUN_0040c450_EffectItemList *)(pmagicItem ? reinterpret_cast<FUN_0040c450_EffectItemList*>(reinterpret_cast<char*>(pmagicItem) + 0x24)
                           : 0)))
        return true;

    return false;
}

extern const char DAT_0118395c[];

class MagicComp
{
  public:
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D(MagicComp* other);

    int unk18;
    int unk1C;
};

class EndianComp
{
  public:
};

struct FUN_0040c510_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    MagicComp m18;
    EndianComp m24;
    void FUN_0040c510(TESForm* form);
};

FUN_0040c510_cls* __cdecl FUN_00ec43fb(TESForm* form, int a2, const char* a3, const char* a4, int a5);

// @fnv 0x0040c510
void FUN_0040c510_cls::FUN_0040c510(TESForm* form)
{
    FUN_0040c510_cls* rec = FUN_00ec43fb(form, 0, (*reinterpret_cast<const char (*)[]>(&::DAT_01183028)), DAT_0118395c, 0);
    if (rec == 0)
    {
        return;
    }
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(form);
    m18.v0D(rec ? &rec->m18 : (MagicComp*)0);
    reinterpret_cast<::B5B10Owner *>(&(m24))->CopyItemsFromList((::EffectItemList *)(::EndianComp *)(rec ? &rec->m24 : (EndianComp*)0));
}
