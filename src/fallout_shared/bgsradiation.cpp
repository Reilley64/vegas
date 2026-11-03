// fallout_shared/bgsradiation.cpp: BGSRadiationStage (10 functions)

#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00592000.h"
#include "fnv/symbols_011ca000.h"
#include "bgsradiation_decls.h"
#include <typeinfo>
#include <new>
#include "bgsradiation_types_BGSRadiationStage.h"
#undef IsFormInitialized

// @fnv 0x00591c80
void BGSRadiationStage::ClearData()
{
    ClearStageData(this);
}

#pragma pack(push, 4)
union RadiationLevelValue
{
    __int64 value;
    struct
    {
        unsigned int low;
        unsigned int high;
    } words;
};
#pragma pack(pop)

// @fnv 0x00592220
BGSRadiationStage* BGSRadiationStage::GetStageForLevel(float level)
{
    struct SearchState
    {
        unsigned int index;
        unsigned int result;
    };
    SearchState searchState;
    searchState.result = 0;
    searchState.index = 0;
    for (; searchState.index < DAT_011ca87c && searchState.result == 0; ++searchState.index)
    {
        BGSRadiationStage* stage = ((::BGSRadiationStage *)(::FUN_005922a0(searchState.index)));
        if (stage != 0)
        {
            RadiationLevelValue value;
            value.words.low = (unsigned int)(((::NiNode *)(reinterpret_cast<::FUN_009611e0_shell *>((reinterpret_cast<NiAVObject*>(stage)))->FUN_009611e0())));
            value.words.high = 0;
            if (level >= value.value)
                searchState.result = (unsigned int)stage;
        }
    }
    return reinterpret_cast<BGSRadiationStage*>(searchState.result);
}

#pragma pack(push, 4)
struct InsertStageLocals
{
    BGSRadiationStage** oldArray;
    unsigned int index;
    unsigned char pad0;
    unsigned char pad1;
    unsigned char pad2;
    unsigned char newCount;
    unsigned int newIndex;
    unsigned char pad3;
    unsigned char pad4;
    unsigned char pad5;
    unsigned char inserted;
    BGSRadiationStage** m_ppNewArray;
};
#pragma pack(pop)

// Inserts stage into the global radiation stage array ordered by condition value, reallocating the array and updating the count.
// @fnv 0x00592010
void InsertRadiationStage(BGSRadiationStage* stage)
{
    InsertStageLocals locals;
    locals.newCount = DAT_011ca87c + 1;
    locals.m_ppNewArray =
        reinterpret_cast<BGSRadiationStage**>(BGSDehydrationStage::AllocateStageArray(locals.newCount));
    locals.newIndex = 0;
    locals.inserted = false;
    for (locals.index = 0; locals.index < DAT_011ca87c; ++locals.index)
    {
        if (*(unsigned int*)reinterpret_cast<BGSCameraPath*>(stage)->GetConditions() >
                *(unsigned int*)reinterpret_cast<BGSCameraPath*>(DAT_011ca880[locals.index])->GetConditions() &&
            !locals.inserted)
        {
            locals.m_ppNewArray[locals.newIndex] = stage;
            ++locals.newIndex;
            locals.inserted = true;
        }
        locals.m_ppNewArray[locals.newIndex] = DAT_011ca880[locals.index];
        ++locals.newIndex;
    }
    if (!locals.inserted)
    {
        locals.m_ppNewArray[locals.newIndex] = stage;
        ++locals.newIndex;
    }
    locals.oldArray = DAT_011ca880;
    ::operator delete(locals.oldArray);
    DAT_011ca87c = locals.newCount;
    DAT_011ca880 = locals.m_ppNewArray;
}

// @fnv 0x00591ca0
void BGSRadiationStage::InitItem()
{
    if (GetInitialized())
    {
    }
    else
    {
        unsigned int formID = reinterpret_cast<::BGSTerrainManager *>((reinterpret_cast<BGSDehydrationStage*>(this)))->GetMinLevel();
        if (formID != 0)
        {
            ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
            reinterpret_cast<BGSDehydrationStage*>(this)->FUN_0050f9a0(
                dynamic_cast<SpellItem*>(::FUN_004839c0(formID)));
        }
        SetInitializationState(true);
        InsertRadiationStage(this);
    }
}

#pragma pack(push, 4)
struct RemoveStageLocals
{
    BGSRadiationStage** oldArray;
    unsigned int oldIndex;
    unsigned int newIndex;
    unsigned int index;
    unsigned char padding0;
    unsigned char padding1;
    unsigned char padding2;
    unsigned char found;
    unsigned int newCount;
    BGSDehydrationStage** replacement;
};
#pragma pack(pop)

// Removes the given stage from the global stage array, rebuilding the array without it and updating the count.
// @fnv 0x00592110
void BGSRadiationStage::ClearStageData(BGSRadiationStage* stage)
{
    RemoveStageLocals locals;
    if (DAT_011ca87c == 0)
    {
    }
    else
    {
        locals.found = 0;
        locals.index = 0;
        for (; locals.found == 0 && locals.index < DAT_011ca87c; ++locals.index)
        {
            if (DAT_011ca880[locals.index] == stage)
                locals.found = 1;
        }
        if (locals.found == 0)
        {
        }
        else
        {
            locals.newCount = DAT_011ca87c - 1;
            locals.replacement = BGSDehydrationStage::AllocateStageArray(locals.newCount);
            if (locals.replacement != 0)
            {
                locals.newIndex = 0;
                locals.oldIndex = 0;
                for (; locals.oldIndex < DAT_011ca87c; ++locals.oldIndex)
                {
                    if (DAT_011ca880[locals.oldIndex] != stage)
                    {
                        locals.replacement[locals.newIndex] =
                            reinterpret_cast<BGSDehydrationStage*>(DAT_011ca880[locals.oldIndex]);
                        ++locals.newIndex;
                    }
                }
            }
            locals.oldArray = DAT_011ca880;
            ::operator delete(locals.oldArray);
            DAT_011ca87c = locals.newCount;
            DAT_011ca880 = reinterpret_cast<BGSRadiationStage**>(locals.replacement);
        }
    }
}

#include <malloc.h>
// Reads a radiation stage record from the file: validates the 0x5a form type, clears data, loads the header, then handles EDID, OBND and DATA chunks.
// @fnv 0x00591ec0
bool BGSRadiationStage::Load(TESFile* file)
{
    unsigned char ucFormType = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (ucFormType != 0x5a)
        return false;
    ClearData();
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    unsigned int uiChunkID;
    while ((uiChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (uiChunkID)
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
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((reinterpret_cast<BGSImpactData*>(this)))->FUN_004861f0(
                file, reinterpret_cast<BGSCameraPath*>(this)->GetConditions(), 8);
            break;
        }
        if (uiChunkID == 0x41544144 && file->IsEndianConversionRequired())
            reinterpret_cast<::S_00462230 *>((reinterpret_cast<FUN_005a71d0*>(&data)))->FUN_00462230();
        if (!file->NextChunk())
            break;
    }
    return true;
}

struct Unnamed_00591bf0
{
    void* __thiscall FUN_00591bf0(unsigned int);
};
struct FUN_005e78f0_t
{
};
struct FUN_00591d30_t
{
    void CopyFrom(TESForm* apCopy);
};
// @fnv 0x00591d30
void FUN_00591d30_t::CopyFrom(TESForm* apCopy)
{
    BGSRadiationStage* pcopy = dynamic_cast<BGSRadiationStage*>(apCopy);
    if (!pcopy)
        return;
    reinterpret_cast<::FormCloneOperation *>((((FUN_005e78f0_t*)this)))->FUN_004851b0(pcopy);
    __memcpy(((BGSCameraPath*)this)->GetConditions(), ((BGSCameraPath*)pcopy)->GetConditions(), 8);
}

struct FUN_005e79a0_t
{
};
int __cdecl _memcmp(const void*, const void*, unsigned int);
struct FUN_00591d90_shell : BGSRadiationStage
{
    bool FUN_00591d90(TESForm* apCompare);
};
// @fnv 0x00591d90
bool FUN_00591d90_shell::FUN_00591d90(TESForm* apCompare)
{
    BGSRadiationStage* pOtherStage = dynamic_cast<BGSRadiationStage*>(apCompare);
    if (!pOtherStage)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FUN_005e79a0_t*)this)))->FUN_00485270(pOtherStage))
        return true;
    if (_memcmp(((BGSCameraPath*)this)->GetConditions(), ((BGSCameraPath*)pOtherStage)->GetConditions(), 8))
        return true;
    return false;
}

class B591C20Form
{
  public:
    virtual ~B591C20Form();
    virtual void ClearData();

    unsigned char m_cFormType;
    unsigned int m_iFormFlags;
    unsigned int m_iFormID;
    void* m_pkSourceFile;
    void* m_pkNextSourceFile;
};

class FUN_00591c20_ListForm : public B591C20Form
{
  public:
    virtual ~FUN_00591c20_ListForm();
    virtual void ClearData();

    void* m_pkFirstItem;
    void* m_pkNextItem;
    unsigned int m_uiAddedCount;
};
// Calls FUN_00591c20, then frees this with _Deallocate when flags has bit 0 set, and returns this.
// @fnv 0x00591bf0
void* __thiscall Unnamed_00591bf0::FUN_00591bf0(unsigned int flags)
{
    reinterpret_cast<::FUN_00591c20_ListForm *>(this)->FUN_00591c20_ListForm::~FUN_00591c20_ListForm();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x00591c20
FUN_00591c20_ListForm::~FUN_00591c20_ListForm()
{
    ClearData();
}
