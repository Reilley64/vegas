// fallout_shared/teslevitem.cpp: TESLevItem, LevItemCopyEntry, LevItemComparison (10 functions)

#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FakeForm.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Owner487a60.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TmpEndian.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00488c50__FUN_00488c50_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "teslevitem_decls.h"
// @fnv 0x0050b8d0
int TESLevItem::GetMaxLevelDifference()
{
    return ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)&(g_011c8f00))))->i;
}

// @fnv 0x0050b560
bool TESLevItem::Load(TESFile* file)
{
    unsigned char ucFormType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (ucFormType != 0x34)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    do
    {
        switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEditorId), 512);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4f4c564c:
        case 0x44454f43:
            switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
            {
            case 0x4f4c564c: {
                LeveledObject entry;
                memset(&entry, 0, 12);
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&entry), 12);
                if (file->IsEndianConversionRequired())
                    reinterpret_cast<::TmpEndian *>(&(entry))->SwapEndian();
                DAT_011c8f1c = ((::LeveledObject *)(reinterpret_cast<::Owner487a60 *>(&(list))->InsertEntryByPriority(entry.level, entry.count, (std::intptr_t)(entry.form), (int)(0))));
                break;
            }
            case 0x44454f43:
                if (DAT_011c8f1c)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(file);
                    *(ContainerItemExtra**)((char*)DAT_011c8f1c + 8) = extra;
                    DAT_011c8f1c = 0;
                }
                break;
            }
            break;
        case 0x444c564c: {
            unsigned char chance = 0;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&chance), 0);
            list.FUN_0042e680(chance);
            break;
        }
        case 0x464c564c:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&list.flags), 0);
            break;
        case 0x474c564c: {
            unsigned int global = 0;
            file->GetChunkData(&global);
            list.global = global;
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

// @fnv 0x0050b890
void TESLevItem::InitItem()
{
    if (GetInitialized())
        return;
    list.InitItem(this);
    SetInitializationState(true);
}

struct B1_4fe : public TESForm
{
    B1_4fe();
    ~B1_4fe();
    char pad[0x18];
};
struct FUN_00487650
{
    FUN_00487650();
    ~FUN_00487650();
    virtual void vf();
    int v;
};
struct FUN_0050b400 : public B1_4fe, public FUN_00487650
{
    FUN_0050b400();
    ~FUN_0050b400();
};
// Initializes the form by setting its form type to 0x34 and clearing its data.
// @fnv 0x0050b400
FUN_0050b400::FUN_0050b400()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)0x34)));
    ClearData();
}

struct FUN_004855a0_shell
{
    void FUN_004855a0();
};
struct FUN_00488400_shell
{
    void SaveLeveledList();
};
struct FUN_00485680_shell
{
    void FUN_00485680();
};

void FUN_004855a0_shell::FUN_004855a0()
{}
void FUN_00485680_shell::FUN_00485680()
{}

struct FUN_0050b530_shell : public B1_4fe, public FUN_00487650
{
    void FUN_0050b530();
};

// Calls FUN_004855a0, TESForm::ClearData, SaveLeveledList on the member at offset 0x30, then FUN_00485680.
// @fnv 0x0050b530
void FUN_0050b530_shell::FUN_0050b530()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_shell*)this)))->FUN_004855a0();
    TESForm::ClearData();
    ((FUN_00488400_shell*)static_cast<FUN_00487650 *>(this))->SaveLeveledList();
    reinterpret_cast<::Holder *>((((FUN_00485680_shell*)this)))->FUN_00485680();
}

struct BGSSaveFormBuffer;
struct FUN_00484d60_holder
{
    char pad[0x30];
};
struct FUN_00488c50_holder
{
    char dummy;
};
struct FUN_0050adb0_shell : FUN_00484d60_holder, FUN_00488c50_holder
{
    void FUN_0050adb0(BGSSaveFormBuffer*);
};
// @fnv 0x0050adb0
void FUN_0050adb0_shell::FUN_0050adb0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    reinterpret_cast<::FakeForm *>(this)->SaveIfChanged(apSaveGameBuffer);
    reinterpret_cast<::fnv_00488c50::FUN_00488c50_shell *>(this)->SaveLeveledListEntries((::fnv_00488c50::BGSSaveFormBuffer *)(apSaveGameBuffer));
}

struct S_0050b490
{
    void FUN_0050b4c0();
    void* DestroyIfFlagged(unsigned int);
};
struct FUN_0050b4c0 : public B1_4fe, public FUN_00487650
{
    ~FUN_0050b4c0();
};
// Calls FUN_0050b4c0, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x0050b490
void* S_0050b490::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_0050b4c0 *>(this)->FUN_0050b4c0::~FUN_0050b4c0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
// Empty destructor for a class deriving from B1_4fe and FUN_00487650.
// @fnv 0x0050b4c0
FUN_0050b4c0::~FUN_0050b4c0()
{}

struct LevItemCopyEntry : public ::TESLevItem
{
    void FUN_0050b800(::TESForm* source);
};

// Casts the source TESForm to a TESLevItem and, if valid, calls FUN_004851b0 to copy the source into this entry.
// @fnv 0x0050b800
void LevItemCopyEntry::FUN_0050b800(::TESForm* source)
{
    ::TESLevItem* sourceItem;
    sourceItem = dynamic_cast< ::TESLevItem*>(source);
    if (!sourceItem)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(source);
}

struct LevItemComparison : public ::TESLevItem
{
    bool FUN_0050b840(::TESForm*);
};

// @fnv 0x0050b840
bool LevItemComparison::FUN_0050b840(::TESForm* other)
{
    ::TESLevItem* pLevItem = dynamic_cast< ::TESLevItem*>(other);
    if (!pLevItem)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(pLevItem))
        return true;
    return false;
}

#include "generated/data/fallout_shared/teslevitem.inc"
