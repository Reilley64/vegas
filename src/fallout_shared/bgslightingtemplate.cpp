// fallout_shared/bgslightingtemplate.cpp: BGSLightingTemplate, SwapBlock, LightingDelete, LightingTemplateInit and more (11 functions)

#include <cstring>
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
#include "bgslightingtemplate.h"
#include <malloc.h>
#include <string.h>

// @fnv 0x005265c0
BGSLightingTemplate::BGSLightingTemplate()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_LGTM_ID)));
    ResetFormData();
}

// @fnv 0x00526710
void BGSLightingTemplate::ResetFormData()
{
    memset(&Data, 0, sizeof(Data));
}

struct FUN_00526640
{
    int a;
    int b;
    int c;
    float d;
    float e;
    int f;
    int g;
    float h;
    float i;
    float j;
    int k;
    FUN_00526640();
};
// Initialises all members of FUN_00526640 to zero, with h and j set to 1.0f.
// @fnv 0x00526640
FUN_00526640::FUN_00526640()
{
    a = 0;
    b = 0;
    c = 0;
    d = 0.0f;
    e = 0.0f;
    f = 0;
    g = 0;
    h = 1.0f;
    i = 0.0f;
    j = 1.0f;
    k = 0;
}

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_005266f0 : Base5a
{
    virtual ~FUN_005266f0();
};
// @fnv 0x005266f0
FUN_005266f0::~FUN_005266f0()
{}

struct FUN_004855a0_shell
{
};
struct FUN_00485680_shell
{
};
struct FUN_00485e00_shell
{
};
struct FUN_00526730_obj : FUN_004855a0_shell
{
    void FUN_00526730();
};
struct SwapTag
{
};


struct SwapBlock
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

    void SwapBytes();
};
// Reads the LGTM record header and chunks (EDID, OBND, DATA) into the lighting template, converting endianness if required.
// @fnv 0x005268a0
bool BGSLightingTemplate::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((static_cast<TESFileFormInt*>(file)))->FUN_00472660() != ENUM_FORM_ID_LGTM_ID)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int iChunkID;
    while ((iChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (iChunkID)
        {
        case 0x44494445:  // EDID
        {
            char* pEditorID = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(pEditorID), 0x200);
            SetEditorID_AtRuntime(pEditorID);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x41544144:  // DATA
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>(this)->FUN_004861f0(file, &Data, sizeof(Data));
            break;
        }
        if (!file->NextChunk())
            break;
    }
    if (file->IsEndianConversionRequired())
        reinterpret_cast<::SwapBlock *>(&(Data))->SwapBytes();
    return true;
}
// @fnv 0x00526730
void FUN_00526730_obj::FUN_00526730()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>(this)->FUN_004855a0();
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::SwapBlock *>((((InteriorData*)((char*)this + 0x18))))->SwapBytes();
    reinterpret_cast<::SDSaveForm *>((((FUN_00485e00_shell*)this)))->FUN_00485e20((const void *)((std::intptr_t)((char*)this + 0x18)), 0x2c);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::SwapBlock *>((((InteriorData*)((char*)this + 0x18))))->SwapBytes();
    reinterpret_cast<::Holder *>((((FUN_00485680_shell*)this)))->FUN_00485680();
}

// Swaps the byte order of every 32-bit field in the block by calling SwapInt on each member.
// @fnv 0x00526790
void SwapBlock::SwapBytes()
{
    ::FUN_00401080(&unk00);
    ::FUN_00401080(&unk04);
    ::FUN_00401080(&unk08);
    ::FUN_00401080(&unk0C);
    ::FUN_00401080(&unk10);
    ::FUN_00401080(&unk14);
    ::FUN_00401080(&unk18);
    ::FUN_00401080(&unk1C);
    ::FUN_00401080(&unk20);
    ::FUN_00401080(&unk24);
}


struct FUN_005054b0_shell : TESForm
{
};

struct FUN_005269f0_Lighting : BGSLightingTemplate
{
    void FUN_005269f0(TESForm* arg);
};

// Copies InteriorData from a BGSLightingTemplate source and calls the base class copy routine.
// @fnv 0x005269f0
void FUN_005269f0_Lighting::FUN_005269f0(TESForm* apSource)
{
    BGSLightingTemplate* src = dynamic_cast<BGSLightingTemplate*>(apSource);
    if (src == 0)
    {
    }
    else
    {
        ::__memcpy(&Data, &src->Data, sizeof(InteriorData));
        reinterpret_cast<::FormCloneOperation *>((reinterpret_cast<FUN_005054b0_shell*>(this)))->FUN_004851b0(apSource);
    }
}


struct LightingDelete : BGSLightingTemplate
{
    void FUN_005266f0();
    void* FUN_005266c0(unsigned int flags);
};

// Calls FUN_005266f0, then deallocates this via _Deallocate when the low bit of flags is set, and returns this.
// @fnv 0x005266c0
void* LightingDelete::FUN_005266c0(unsigned int flags)
{
    reinterpret_cast<::FUN_005266f0 *>(this)->FUN_005266f0::~FUN_005266f0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct LightingTemplateInit : BGSLightingTemplate
{
    void FUN_005269c0();
};
// If the form is not yet initialized, clears its data and marks it as initialized.
// @fnv 0x005269c0
void LightingTemplateInit::FUN_005269c0()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    TESForm::ClearData();
    SetInitializationState(true);
}

struct LightingComparison : public BGSLightingTemplate
{
    bool FUN_00526a50(TESForm*);
};
// Returns true when the cast fails, the InteriorData bytes differ, or TESForm::Compare returns true.
// @fnv 0x00526a50
bool LightingComparison::FUN_00526a50(TESForm* form)
{
    BGSLightingTemplate* other = dynamic_cast<BGSLightingTemplate*>(form);
    if (!other)
        return true;
    if (std::memcmp(&Data, &other->Data, sizeof(InteriorData)))
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270(other))
        return true;
    return false;
}
