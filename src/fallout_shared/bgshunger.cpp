// fallout_shared/bgshunger.cpp: BGSHungerStage, BGSHungerStage_copy (11 functions)

#include <cstring>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00401ac0.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00402000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c3000.h"
#include "bgshunger_decls.h"
#include <malloc.h>

// @fnv 0x00401b40
void BGSHungerStage::ClearData()
{
    ClearStageData(this);
}


struct RemoveStageLocals
{
    BGSHungerStage** oldStages;  // ebp - 0x1c
    unsigned int source;         // ebp - 0x18
    unsigned int destination;    // ebp - 0x14
    unsigned int index;          // ebp - 0x10
    unsigned char padding0;
    unsigned char padding1;
    unsigned char padding2;
    bool found;                       // ebp - 0x09
    unsigned int newCount;            // ebp - 0x08
    BGSDehydrationStage** newStages;  // ebp - 0x04
};

// @fnv 0x00401f20
void BGSHungerStage::ClearStageData(BGSHungerStage* stage)
{
    RemoveStageLocals locals;

    if (!gHungerStageCount)
        return;

    locals.found = false;
    locals.index = 0;
    for (; !locals.found && locals.index < gHungerStageCount; ++locals.index)
    {
        if (gHungerStages[locals.index] == stage)
            locals.found = true;
    }

    if (!locals.found)
        return;

    locals.newCount = gHungerStageCount - 1;
    locals.newStages = BGSDehydrationStage::AllocateStageArray(locals.newCount);
    if (locals.newStages)
    {
        locals.destination = 0;
        locals.source = 0;
        for (; locals.source < gHungerStageCount; ++locals.source)
        {
            if (gHungerStages[locals.source] != stage)
            {
                ((BGSHungerStage**)locals.newStages)[locals.destination] = gHungerStages[locals.source];
                ++locals.destination;
            }
        }
    }

    locals.oldStages = gHungerStages;
    ::FUN_00401030(locals.oldStages);
    gHungerStageCount = locals.newCount;
    gHungerStages = (BGSHungerStage**)locals.newStages;
}

// Reads a hunger stage record from the TESFile: validates form type 0x77, loads the record header, then processes EDID, OBND and DATA chunks.
// @fnv 0x00401cd0
bool BGSHungerStage::Load(TESFile* file)
{
    unsigned char formType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (formType != 0x77)
        return false;

    form.ClearData();
    reinterpret_cast<::S00485110 *>(&(form))->CallWithThis((::T00485110 *)(file));
    form.SetInitializationState(false);

    unsigned int chunk;
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* buffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0x200);
            form.SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444e424f:
            form.readOBNDSubRecord(file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSDehydrationStage*>(this)))->FUN_004861f0(
                file, ((void *)(reinterpret_cast<::BGSCameraPath *>((reinterpret_cast<BGSDehydrationStage*>(this)))->GetConditions())), {});
            break;
        }

        if (chunk == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<::S_00462230 *>(&(data))->FUN_00462230();
        if (!file->NextChunk())
            break;
    }
    return true;
}

// @fnv 0x00401b60
void BGSHungerStage::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)&(form))->GetInitialized())
        return;

    unsigned int formID = reinterpret_cast<::BGSTerrainManager *>((reinterpret_cast<BGSDehydrationStage*>(this)))->GetMinLevel();
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), form.GetFile(-1));
        reinterpret_cast<BGSDehydrationStage*>(this)->FUN_0050f9a0(
            dynamic_cast<SpellItem*>(::FUN_004839c0(formID)));
    }

    form.SetInitializationState(true);
    InsertHungerStage(this);
}

struct AddStageLocals
{
    BGSHungerStage** oldStages;
    unsigned int index;
    unsigned char padding00;
    unsigned char padding01;
    unsigned char padding02;
    unsigned char newCount;
    unsigned int destination;
    unsigned char padding10;
    unsigned char padding11;
    unsigned char padding12;
    bool inserted;
    BGSHungerStage** newStages;
};

// @fnv 0x00401e20
void InsertHungerStage(BGSHungerStage* stage)
{
    AddStageLocals locals;
    locals.newCount = (unsigned char)(gHungerStageCount + 1);
    locals.newStages = (BGSHungerStage**)BGSDehydrationStage::AllocateStageArray(locals.newCount);
    locals.destination = 0;
    locals.inserted = false;
    locals.index = 0;
    for (; locals.index < gHungerStageCount; ++locals.index)
    {
        if (((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((stage))->GetConditions()))->m_uiStageLevel > ((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((gHungerStages[locals.index]))->GetConditions()))->m_uiStageLevel &&
            !locals.inserted)
        {
            locals.newStages[locals.destination] = stage;
            ++locals.destination;
            locals.inserted = true;
        }
        locals.newStages[locals.destination] = gHungerStages[locals.index];
        ++locals.destination;
    }
    if (!locals.inserted)
    {
        locals.newStages[locals.destination] = stage;
        ++locals.destination;
    }
    locals.oldStages = gHungerStages;
    ::FUN_00401030(locals.oldStages);
    gHungerStageCount = locals.newCount;
    gHungerStages = locals.newStages;
}

class Calendar
{
  public:
};

// Returns the first hunger stage whose GetDaysPassed threshold is at or below level, or null if none match.
// @fnv 0x00402030
BGSHungerStage* __cdecl FindHungerStage(float level)
{
    BGSHungerStage* result = 0;
    for (unsigned int index = 0; index < gHungerStageCount && !result; ++index)
    {
        BGSHungerStage* stage = ((::BGSHungerStage *)(::GetHungerStage(index)));
        if (stage && level >= ((unsigned int)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<Calendar*>(stage)))->FUN_009611e0())))
            result = stage;
    }
    return result;
}

struct FUN_00843170_shell : public HungerStageData
{
    void ClearFields();
};

// @fnv 0x00843170
void FUN_00843170_shell::ClearFields()
{
    *(int*)((char*)this + 0) = 0;
    *(int*)((char*)this + 4) = 0;
}

struct FUN_00401a90_StandIn
{
    void* FUN_00401a90(unsigned int);
};
// Calls FUN_00401ac0, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x00401a90
void* FUN_00401a90_StandIn::FUN_00401a90(unsigned int flags)
{
    reinterpret_cast<::FUN_00401ac0 *>(this)->FUN_00401ac0::~FUN_00401ac0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

struct FUN_005e78f0_t
{
};
struct BGSHungerStage_copy
{
    void CopyFromForm(TESForm* source);
};
// @fnv 0x00401bf0
void BGSHungerStage_copy::CopyFromForm(TESForm* source)
{
    BGSHungerStage* copy = dynamic_cast<BGSHungerStage*>(source);
    if (!copy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0((TESForm*)copy);
    ::__memcpy(((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((((BGSHungerStage*)this)))->GetConditions())), ((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((copy))->GetConditions())), 8);
}


struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct FUN_00485e00_shell
{
};

struct FUN_00591e10_shell : public BGSDehydrationStage
{
    void InitDehydrationStage();
};

// @fnv 0x00591e10
void FUN_00591e10_shell::InitDehydrationStage()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();

    SpellItem* pSavedSpell = reinterpret_cast<SpellItem*>(reinterpret_cast<::BGSTerrainManager *>(this)->GetMinLevel());

    FUN_0050f9a0(reinterpret_cast<::BGSTerrainManager *>(this)->GetMinLevel() ? reinterpret_cast<SpellItem*>(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(reinterpret_cast<::BGSTerrainManager *>(this)->GetMinLevel())))->FUN_0084e3a0())))
                                : 0);

    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::S_00462230 *>((reinterpret_cast<FUN_005a71d0*>(reinterpret_cast<char*>(this) + 0x18)))->FUN_00462230();
    }

    reinterpret_cast<::SDSaveForm *>((reinterpret_cast<FUN_00485e00_shell*>(this)))->FUN_00485e20((const void *)(reinterpret_cast<int>(this) + 0x18), 8);

    if (((bool)(::FUN_00401500())))
    {
        reinterpret_cast<::S_00462230 *>((reinterpret_cast<FUN_005a71d0*>(reinterpret_cast<char*>(this) + 0x18)))->FUN_00462230();
    }

    FUN_0050f9a0(pSavedSpell);

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}

extern char DAT_01183028;


class FUN_00401c50_cls : public BGSHungerStage
{
  public:
    bool FUN_00401c50(void* arg);
};

// @fnv 0x00401c50
bool FUN_00401c50_cls::FUN_00401c50(void* pOther)
{
    BGSHungerStage* r = (BGSHungerStage*)dynamic_cast<::TESForm *>(reinterpret_cast<::TESForm *>(pOther));
    if (r == 0)
    {
        return true;
    }
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(r)))
    {
        return true;
    }
    if (std::memcmp(((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((this))->GetConditions())), ((::HungerStageData *)(reinterpret_cast<::BGSCameraPath *>((r))->GetConditions())), 8) != 0)
    {
        return true;
    }
    return false;
}

#include "generated/data/fallout_shared/bgshunger.inc"
