// fallout_shared/tesloadscreentype.cpp: TESLoadScreenType, ScalarStandIn, LoadScreenTypeData_FUN (7 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "tesloadscreentype_decls.h"

struct FUN_005e78f0_t
{
};

struct TESLoadScreenType_Shell
{
    void __thiscall CopyFrom(TESForm* apCopy);
};

// @fnv 0x005a7690
void __thiscall TESLoadScreenType_Shell::CopyFrom(TESForm* apCopy)
{
    TESLoadScreenType* pmisc = (TESLoadScreenType*)dynamic_cast<TESLoadScreenType*>(apCopy);
    if (!pmisc)
    {
        return;
    }
    __memcpy((char*)this + 0x18, (char*)pmisc + 0x18, 0x58);
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(apCopy);
}

struct ScalarStandIn
{
    void* __thiscall DestroyIfFlagged(unsigned int);
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_00485e00_shell
{
};
struct FUN_005a7630_shell
{
    char _pad[24];
    LoadScreenTypeData _data;
    void __thiscall SwapEndianAndProcess();
};
struct ScriptS
{
};
int __cdecl _memcmp(const void*, const void*, unsigned int);
struct FUN_005e79a0_t
{
};
struct FUN_005a76f0_shell
{
    char _pad[0x18];
    bool __thiscall FUN_005a76f0(TESForm* apCompare);
};
// Compares a TESLoadScreenType against this object's header bytes and a nested check, returning true when either differs or the cast fails.
// @fnv 0x005a76f0
bool __thiscall FUN_005a76f0_shell::FUN_005a76f0(TESForm* apCompare)
{
    TESLoadScreenType* pcomp = dynamic_cast<TESLoadScreenType*>(apCompare);
    if (!pcomp)
        return true;
    if (_memcmp(&this->_pad[0x18], ((void *)(reinterpret_cast<::BGSCameraPath *>((((ScriptS*)pcomp)))->GetConditions())), 0x58))
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pcomp))
        return true;
    return false;
}

struct FUN_005a72d0_base
{
    virtual ~FUN_005a72d0_base();
};

struct FUN_005a72d0_cls : FUN_005a72d0_base
{
    virtual ~FUN_005a72d0_cls();
};
// Calls FUN_005a72d0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x005a72a0
void* __thiscall ScalarStandIn::DestroyIfFlagged(unsigned int flags)
{
    reinterpret_cast<::FUN_005a72d0_cls *>(this)->FUN_005a72d0_cls::~FUN_005a72d0_cls();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x005a72d0
FUN_005a72d0_cls::~FUN_005a72d0_cls()
{}

struct EndianTag
{
};
struct LoadScreenTypeData_FUN
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
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    void SwapEndianFields();
};
// Reads the record header and chunks (EDID, OBND, DATA) from file, applies endian conversion to data, and returns true.
// @fnv 0x005a72f0
bool TESLoadScreenType::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    unsigned int chunk;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
        }
        break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((BGSImpactData*)this)))->FUN_004861f0(file, &data, 88);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (file->IsEndianConversionRequired())
        reinterpret_cast<::LoadScreenTypeData_FUN *>(&(data))->SwapEndianFields();
    return true;
}
// Calls M, conditionally byte-swaps _data before and after FUN_00485e20, then calls M again.
// @fnv 0x005a7630
void __thiscall FUN_005a7630_shell::SwapEndianAndProcess()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::LoadScreenTypeData_FUN *>(&(_data))->SwapEndianFields();
    reinterpret_cast<::SDSaveForm *>((((FUN_00485e00_shell*)this)))->FUN_00485e20((const void *)((int)&_data), 0x58);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::LoadScreenTypeData_FUN *>(&(_data))->SwapEndianFields();
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}
// Byte-swaps every integer field of the structure by calling FUN_00401080 on each member.
// @fnv 0x005a7400
void LoadScreenTypeData_FUN::SwapEndianFields()
{
    ::FUN_00401080(&unk28);
    ::FUN_00401080(&unk10);
    ::FUN_00401080(&unk04);
    ::FUN_00401080(&unk08);
    ::FUN_00401080(&unk14);
    ::FUN_00401080(&unk0C);
    ::FUN_00401080(&unk1C);
    ::FUN_00401080(&unk20);
    ::FUN_00401080(&unk24);
    ::FUN_00401080(&unk38);
    ::FUN_00401080(&unk2C);
    ::FUN_00401080(&unk30);
    ::FUN_00401080(&unk3C);
    ::FUN_00401080(&unk34);
    ::FUN_00401080(&unk44);
    ::FUN_00401080(&unk48);
    ::FUN_00401080(&unk4C);
    ::FUN_00401080(&unk50);
    ::FUN_00401080(&unk00);
    ::FUN_00401080(&unk18);
    ::FUN_00401080(&unk40);
    ::FUN_00401080(&unk54);
}
