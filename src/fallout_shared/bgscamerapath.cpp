// fallout_shared/bgscamerapath.cpp: BGSCameraPath, CameraPathCompare, CameraPathClone, CameraPath and more (24 functions)

#include <new>
#include <cstring>
#include <malloc.h>
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_004226e0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00464f40_class.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004867a0_cls.h"
#include "fnv/decl/FUN_004d6170_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0058b630_shell.h"
#include "fnv/decl/FUN_005ffbf0_shell.h"
#include "fnv/decl/FUN_00680910_shell.h"
#include "fnv/decl/FUN_00680a70_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/Holder730.h"
#include "fnv/decl/ItemChangeListNode.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/SDSaveForm.h"
#include "fnv/decl/S_00462230.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_004861f0__Form_004861f0.h"
#include "fnv/decl/fnv_00853130__NiTMapBase.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_0058b000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011ca000.h"
#include "bgscamerapath.h"

// @fnv 0x0058a620
void BGSCameraPath::ResetFormData()
{
    data.cFlags = 0;
    m_pFirstCameraPath = 0;
    m_pSecondCameraPath = 0;
}

// @fnv 0x005f4bb0
void BGSCameraPath::AssignParentPath(BGSCameraPath* parent)
{
    m_pFirstCameraPath = parent;
}

// @fnv 0x0058a650
void BGSCameraPath::ClearData()
{
    GetConditions()->InitializeConditionItems();
    reinterpret_cast<::FileMatchList *>(&(m_kCameraShotList))->RemoveAll();
}

// @fnv 0x0058a380
BGSCameraPath::BGSCameraPath()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_CPTH_ID)));
    m_pPathArray = 0;
    ResetFormData();
}

class BGSCameraShot : public TESForm
{
};
extern "C" const char fnv_MessageWithName[];
extern "C" const char fnv_MessageWithFormID[];

// Initializes conditions and walks the shot list, resolving each form ID to a BGSCameraShot and removing entries that fail to resolve, warning for each.
// @fnv 0x0058ad90
void BGSCameraPath::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;

    reinterpret_cast<::PerkEntryConditionSet *>((((TESConditionInit*)GetConditions())))->InitItem(this);

    BSSimpleList<BGSCameraShot*>* pShotNode = GetShotList();
    BSSimpleList<BGSCameraShot*>* previous = 0;
    struct InitItemLocals
    {
        BGSCameraShot* cameraShot;
        unsigned int formID;
    } shotEntry;
    while (pShotNode && !pShotNode->IsEmpty())
    {
        shotEntry.formID = (unsigned int)(std::uintptr_t)(pShotNode->m_item);
        ::ResolveFormID((unsigned int *)&(shotEntry.formID), GetFile(-1));
        shotEntry.cameraShot = dynamic_cast<BGSCameraShot*>(::FUN_004839c0(shotEntry.formID));
        if (!shotEntry.cameraShot)
        {
            if (previous)
            {
                reinterpret_cast<::ItemChangeListNode *>((previous))->FUN_00905330((::InventoryStackRecord *const &)((pShotNode->m_item)));
                pShotNode = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((previous))->FUN_00726070()));
            }
            else
                pShotNode->RemoveHead();

            if (HasNameForWarning())
                ::FUN_005b5e40();
            else
                ::FUN_005b5e40();
        }
        else
        {
            pShotNode->SetItem(shotEntry.cameraShot);
            previous = pShotNode;
            pShotNode = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((pShotNode))->FUN_00726070()));
        }
    }

    SetInitializationState(true);
}

extern "C" const char fnv_MessageMultipleNext[];

// @fnv 0x0058b190
void BGSCameraPath::SetPathArray(NiFormArray* paths)
{
    if (!paths)
        return;

    struct FixNextLocals
    {
        unsigned int index;
        unsigned int invalidCount;
        unsigned int nextIndex;
        unsigned int currentIndex;
        BGSCameraPath* nextPath;
        unsigned int pathCount;
    } locals;

    locals.invalidCount = 0;
    locals.currentIndex = 0xffffffff;
    locals.pathCount = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((paths))->FUN_0084e3a0()));
    locals.nextIndex = 0xffffffff;
    locals.nextPath = 0;
    locals.index = 0;

    for (; locals.index < locals.pathCount; ++locals.index)
    {
        BGSCameraPath* path = dynamic_cast<BGSCameraPath*>(paths->FUN_00877a30(locals.index));
        if (path)
        {
            if (path == this)
                locals.currentIndex = locals.index;
            else if (path->GetPrevPath() == this)
            {
                if (!locals.nextPath)
                {
                    locals.nextPath = path;
                    locals.nextIndex = locals.index;
                }
                else
                {
                    BSStringT<char> name;
                    GetDebugName(&name);
                    ::FUN_005b5e40();
                }
            }
        }
        else
            ++locals.invalidCount;
    }

    if (locals.currentIndex != 0xffffffff && locals.nextIndex != 0xffffffff &&
        locals.nextIndex != locals.currentIndex + 1)
    {
        unsigned int oldSize = 0;
        paths->SetSize(locals.nextIndex, &oldSize);
        paths->Compact();
        if (locals.nextIndex < locals.currentIndex)
            ++locals.invalidCount;
        locals.currentIndex -= locals.invalidCount;
        paths->SetFormAtIndex(locals.currentIndex + 1, locals.nextPath);
        paths->Compact();
        locals.nextPath->SetPathArray(paths);
    }
}

#pragma intrinsic(_alloca)
// @fnv 0x0058a9e0
bool BGSCameraPath::Load(TESFile* file)
{
    int chunk;
    if (((CameraFileFormType*)file)->GetTESForm() != 0x5c)
        return false;
    if (this == ::CameraPathManager::GetTextureResourcePath())
    {
        struct
        {
            unsigned int index;
            NiFormArray* paths;
        } removalInfo;
        removalInfo.paths = ((::NiFormArray *)((void *)(DAT_011ca700)));
        removalInfo.index = removalInfo.paths->GetIndexOfForm(this);
        if (removalInfo.index != 0xffffffff)
        {
            ((NiTLargeArray<TESTopicInfo*, NiTMallocInterface<TESTopicInfo*> >*)removalInfo.paths)
                ->RemoveAt(removalInfo.index);
            removalInfo.paths->Compact();
        }
    }
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    while ((chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunk)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 512);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x41544144:
            reinterpret_cast<::fnv_004861f0::Form_004861f0 *>((((BGSImpactData*)this)))->FUN_004861f0(file, &data, 1);
            break;
        case 0x41445443:
            reinterpret_cast<::PerkEntryConditionSet *>((((CameraCondition*)GetConditions())))->Load(file);
            break;
        case 0x4d414e53: {
            unsigned int formID = 0;
            file->GetChunkData(&formID);
            reinterpret_cast<::Callees *>((((BSSimpleList<ScriptVariableInfo*>*)&m_kCameraShotList)))->FUN_00905820((void *)&(const ::ScriptVariableInfo *const &)((ScriptVariableInfo*)(std::uintptr_t)formID));
            break;
        }
        case 0x4d414e41: {
            FUN_005a71d0 parentInfo;
            memset(&parentInfo, 0, 8);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&parentInfo), 8);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::S_00462230 *>(&(parentInfo))->FUN_00462230();
            m_pFirstCameraPath = (BGSCameraPath*)parentInfo.parent;
            m_pSecondCameraPath = (BGSCameraPath*)parentInfo.previous;
            reinterpret_cast<::FUN_005ffbf0_shell *>((DAT_011ca700))->AddIdleToArray((::TESIdleForm *)(::BGSCameraPath *)(this));
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

extern "C" const char fnv_MessageMissingParent[];
extern "C" const char fnv_MessageMissingPrevious[];
extern "C" const char fnv_MessageMissingArray[];
// Resolves the parent and previous camera paths by form ID, warns if missing, and inserts this path into the parent's or global path array at the computed index.
// @fnv 0x0058aef0
bool BGSCameraPath::HasMissingPathArray()
{
    struct ParentLocals
    {
        BGSCameraPath* parent;
        unsigned int formID;
        unsigned int index;
        BGSCameraPath* previous;
        NiFormArray* paths;
        char pad0, pad1, pad2;
        bool success;
    } locals;
    locals.success = true;
    locals.parent = 0;
    locals.formID = (unsigned int)(std::uintptr_t)m_pFirstCameraPath;
    if (locals.formID)
    {
        ::ResolveFormID((unsigned int *)&(locals.formID), GetFile(-1));
        locals.parent = dynamic_cast<BGSCameraPath*>(::FUN_004839c0(locals.formID));
        if (!locals.parent)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            ::FUN_005b5e40();
            locals.success = false;
        }
        AssignParentPath(locals.parent);
    }
    locals.previous = 0;
    locals.formID = (unsigned int)(std::uintptr_t)m_pSecondCameraPath;
    if (locals.formID)
    {
        ::ResolveFormID((unsigned int *)&(locals.formID), GetFile(-1));
        locals.previous = dynamic_cast<BGSCameraPath*>(::FUN_004839c0(locals.formID));
        if (!locals.previous)
        {
            BSStringT<char> name;
            GetDebugName(&name);
            ::FUN_005b5e40();
            locals.success = false;
        }
        reinterpret_cast<::LowProcess *>((((BGSAcousticSpace*)this)))->SetCurrentBoundObject((::TESBoundObject *)(::TESSound *)((TESSound*)locals.previous));
    }
    locals.index = 0;
    locals.paths = 0;
    if (locals.parent)
        locals.paths = locals.parent->GetEntryObject();
    else
        locals.paths = ((::NiFormArray *)((void *)(DAT_011ca700)));
    if (locals.paths)
    {
        if (locals.previous)
        {
            unsigned int previousIndex = locals.paths->GetIndexOfForm(locals.previous);
            if (previousIndex != 0xffffffff)
                ++previousIndex;
            locals.index = previousIndex;
        }
        if (locals.index == 0xffffffff || reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
            locals.index = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((locals.paths))->FUN_0084e3a0())) + 1;
        locals.paths->SetFormAtIndex(locals.index, this);
        SetPathArray(locals.paths);
    }
    else
    {
        BSStringT<char> name;
        GetDebugName(&name);
        ::FUN_005b5e40();
        locals.success = false;
    }
    return locals.success;
}

extern int DAT_010326fc;
struct NTL
{
    void NiTLargePrimitiveArray(unsigned int, unsigned int);
};
// Calls NiTLargePrimitiveArray(0, 1) on self, stores &DAT_010326fc at self, and returns self.
// @fnv 0x0058b3f0
void* FUN_0058b3f0(void* self)
{
    ((NTL*)self)->NiTLargePrimitiveArray(0, 1);
    *(int**)self = &DAT_010326fc;
    return self;
}

struct FUN_0058b600_shell
{
    char pad[0x2c];
    TESForm* m_field_2c;
};

// Returns the form ID of the TESForm stored at m_field_2c, or 0 if it is null.
// @fnv 0x0058b600
unsigned int GetStoredFormID(FUN_0058b600_shell* thisPtr)
{
    unsigned int result = 0;
    if (thisPtr->m_field_2c)
        result = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((thisPtr->m_field_2c))->FUN_0084e3a0()));
    return result;
}

struct S_58a420
{
    void FUN_0058a450();
    void* FUN_0058a420(unsigned int);
};
struct Unk58
{
    void* FUN_0058b420(unsigned int);
};
struct FUN_00464f40_shell
{
    void FUN_00464f40();
    void FUN_0058b450();
};
// Calls FUN_0058b450, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0058b420
void* Unk58::FUN_0058b420(unsigned int flags)
{
    reinterpret_cast<::FUN_00464f40_shell *>(this)->FUN_0058b450();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

void FUN_00464f40_shell::FUN_00464f40()
{}

// @fnv 0x0058b450
void FUN_00464f40_shell::FUN_0058b450()
{
    reinterpret_cast<::FUN_00464f40_class *>(this)->FUN_00464f40();
}

struct FUN_0058b4f0_shell
{
    bool IsFlag2Set();
};
// @fnv 0x0058b4f0
bool FUN_0058b4f0_shell::IsFlag2Set()
{
    if (((const unsigned char*)this)[0x28] & 2)
        return true;
    return false;
}

struct FUN_0058b470_shell
{
    unsigned char _pad[0x28];
    unsigned char cFlags;
    bool IsFlag80Set();
};

// Returns true when the cFlags bit 0x80 is set, otherwise false.
// @fnv 0x0058b470
bool FUN_0058b470_shell::IsFlag80Set()
{
    if (cFlags & 0x80)
        return true;
    else
        return false;
}

struct S0058b4a0
{
    unsigned char _pad[0x28];
    unsigned char _flag;
    bool FUN_0058b4a0();
};
// Returns true when neither bit 0 nor bit 1 of _flag is set, otherwise false.
// @fnv 0x0058b4a0
bool S0058b4a0::FUN_0058b4a0()
{
    if (_flag & 1 || _flag & 2)
        return false;
    return true;
}

struct FUN_0058b4d0_shell
{
    unsigned char pad[0x28];
    unsigned char flags28;
    bool FUN_0058b4d0();
};

// @fnv 0x0058b4d0
bool FUN_0058b4d0_shell::FUN_0058b4d0()
{
    if (flags28 & 1)
        return true;
    return false;
}

struct IdentifierHistoryEntry
{
    unsigned int m_uiCurrentId;
    unsigned int ipreviousID;
};

struct Script
{
    char* GetData();
};

struct TESConditionSave
{
};

struct FUN_004855a0
{
};

struct FUN_00485680
{
};

struct BSSimpleList_shell
{
    bool _ref_008256d0();
};

struct FUN_00485e00_shell
{
};


struct FUN_0058ac10_shell : public BGSCameraPath
{
    void FUN_0058ac10();
};

// @fnv 0x0058ac10
void FUN_0058ac10_shell::FUN_0058ac10()
{
    BSSimpleList_shell* pShotList;
    IdentifierHistoryEntry ids;

    {
        BGSCameraPath* pprev;
        BGSCameraShot* pshot;
        unsigned int shotFormID;

        reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<FUN_004855a0*>(this)))->FUN_004855a0();
        reinterpret_cast<::FUN_00680910_shell *>((reinterpret_cast<TESConditionSave*>(GetConditions())))->ProcessItems();

        memset(&ids, 0, 8);

        if (reinterpret_cast<Script*>(this)->GetData())
            ids.m_uiCurrentId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(reinterpret_cast<Script*>(this)->GetData())))->FUN_0084e3a0()));

        if (!reinterpret_cast<::FUN_00440d80_shell *>((void *)this)->FUN_00440d80())
        {
            pprev = GetPrevPath();
            while (pprev && reinterpret_cast<::FUN_00440d80_shell *>((void *)(pprev))->FUN_00440d80())
                pprev = pprev->GetPrevPath();

            if (pprev)
                ids.ipreviousID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pprev))->FUN_0084e3a0()));
        }

        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::S_00462230 *>((reinterpret_cast<FUN_005a71d0*>(&ids)))->FUN_00462230();

        ::AppendChunk(0x4d414e41, &ids, 8);

        if (((bool)(::FUN_00401500())))
            reinterpret_cast<::S_00462230 *>((reinterpret_cast<FUN_005a71d0*>(&ids)))->FUN_00462230();

        if (((bool)(::FUN_00401500())))
            reinterpret_cast<TESForm*>(&data)->TESForm::ClearData();

        reinterpret_cast<::SDSaveForm *>((reinterpret_cast<FUN_00485e00_shell*>(this)))->FUN_00485e20((const void *)(reinterpret_cast<std::intptr_t>(&data)), 1);

        if (((bool)(::FUN_00401500())))
            reinterpret_cast<TESForm*>(&data)->TESForm::ClearData();

        pShotList = reinterpret_cast<BSSimpleList_shell*>(((char *)(reinterpret_cast<::BGSCameraPath *>((void *)(reinterpret_cast<TESForm*>(this)))->GetShotList())));

        while (pShotList && !pShotList->_ref_008256d0())
        {
            pshot = reinterpret_cast<BGSCameraShot*>(((void **)((void *)(pShotList)))[0]);
            pShotList = ((::BSSimpleList_shell *)(reinterpret_cast<::Callees *>((pShotList))->FUN_00726070()));
            shotFormID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pshot))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e53, shotFormID);
        }
    }

    reinterpret_cast<::Holder *>((reinterpret_cast<FUN_00485680*>(this)))->FUN_00485680();
}


struct Cond_58a680
{
};

struct CameraPath_58a680 : public BGSCameraPath
{
    void CopyFromForm(TESForm* apForm);
};

// Casts apForm to BGSCameraPath, copies common data, conditions, data and the shot list into this camera path.
// @fnv 0x0058a680
void CameraPath_58a680::CopyFromForm(TESForm* apForm)
{
    BGSCameraPath* p = dynamic_cast<BGSCameraPath*>(apForm);
    if (!p)
        return;
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(p);
    reinterpret_cast<::FUN_00680a70_shell *>((((Cond_58a680*)GetConditions())))->CopyConditions(p->GetConditions(), (::PerkEntryConditionSet *)(void *)(0));
    __memcpy(&data, &p->data, sizeof(CameraShotData));
    BSSimpleList<BGSCameraShot*>* h = 0;
    reinterpret_cast<::FileMatchList *>(&(m_kCameraShotList))->RemoveAll();
    h = p->GetShotList();
    while (h && !h->IsEmpty())
    {
        BGSCameraShot* e = (h->m_item);
        h = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((h))->FUN_00726070()));
        reinterpret_cast<::Callees *>(&(m_kCameraShotList))->FUN_00905820((void *)&(e));
    }
}

struct FormCompareStub
{
};
struct ConditionCompareStub
{
};

struct CameraPathCompare : BGSCameraPath
{
    bool FUN_0058a750(TESForm* form);
};

// Compares this camera path against another form's camera path: base form, conditions, a data byte, and shot lists; returns true if any differ.
// @fnv 0x0058a750
bool CameraPathCompare::FUN_0058a750(TESForm* form)
{
    BGSCameraPath* pathForm = dynamic_cast<BGSCameraPath*>(form);
    if (!pathForm)
        return true;
    if (reinterpret_cast<::FUN_00509540_obj *>((((FormCompareStub*)this)))->FUN_00485270((::TESForm *)(pathForm)))
        return true;
    if (reinterpret_cast<::PerkEntryConditionSet *>((((ConditionCompareStub*)GetConditions())))->Compare(pathForm->GetConditions()))
        return true;
    if (memcmp(&data, &pathForm->data, 1))
        return true;
    BSSimpleList<BGSCameraShot*>* pShotNode = GetShotList();
    BSSimpleList<BGSCameraShot*>* pOtherShotNode = pathForm->GetShotList();
    while (pOtherShotNode && !pOtherShotNode->IsEmpty())
    {
        if (!pShotNode || (pShotNode->m_item) != (pOtherShotNode->m_item))
            return true;
        pOtherShotNode = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((pOtherShotNode))->FUN_00726070()));
        pShotNode = ((::BSSimpleList< ::BGSCameraShot *> *)(reinterpret_cast<::Callees *>((pShotNode))->FUN_00726070()));
    }
    if (pShotNode && !pShotNode->IsEmpty())
        return true;
    return false;
}

class FUN_0058a450;

class PathFormArray
{
  public:
    virtual ~PathFormArray();
    TESTopicInfo* RemoveAt(unsigned int index);
    void Compact();
};

class DataHandlerStub
{
  public:
};

class CameraPathFormBase : public TESForm
{
  public:
    virtual ~CameraPathFormBase();
};

class FUN_0058a450 : public CameraPathFormBase
{
  public:
    PerkEntryConditionSet Conditions;
    BSSimpleList<BGSCameraShot*> m_kCameraShotList;
    CameraShotData data;
    unsigned char pad29;
    unsigned char pad2a;
    unsigned char pad2b;
    PathFormArray* m_pPathArray;
    FUN_0058a450* m_pFirstCameraPath;
    FUN_0058a450* m_pSecondCameraPath;

    virtual ~FUN_0058a450();
    virtual void ClearData();
};
// Calls FUN_0058a450, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x0058a420
void* S_58a420::FUN_0058a420(unsigned int flags)
{
    reinterpret_cast<::FUN_0058a450 *>(this)->FUN_0058a450::~FUN_0058a450();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Clears data, unlinks the path from its parent or the global path array while not loading, then deletes all children and the child array.
// @fnv 0x0058a450
FUN_0058a450::~FUN_0058a450()
{
    ClearData();
    if (!reinterpret_cast<::FUN_004226e0_shell *>(((*reinterpret_cast<::DataHandlerStub * *>(&::g_dataHandler))))->FUN_004226e0())
    {
        if (((::FUN_0058a450 *)(reinterpret_cast<::Script *>(this)->GetData())))
        {
            reinterpret_cast<::Holder730 *>((((::FUN_0058a450 *)(reinterpret_cast<::Script *>(this)->GetData()))))->FUN_0058b730((std::intptr_t)(this));
        }
        else
        {
            PathFormArray* pArray = (PathFormArray*)((::NiFormArray *)((void *)(DAT_011ca700)));
            if (pArray)
            {
                unsigned int uiPathIndex = reinterpret_cast<::NiFormArray *>((pArray))->GetIndexOfForm(this);
                if (uiPathIndex != -1)
                {
                    FUN_0058a450* pNextPath = ((::FUN_0058a450 *)(reinterpret_cast<::FUN_004d6170_shell *>((pArray))->FUN_004d6170(uiPathIndex + 1)));
                    if (pNextPath)
                    {
                        reinterpret_cast<::LowProcess *>((pNextPath))->SetCurrentBoundObject((::TESBoundObject *)(::FUN_0058a450 *)(((::FUN_0058a450 *)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath()))));
                    }
                    pArray->RemoveAt(uiPathIndex);
                    pArray->Compact();
                }
            }
        }
    }
    if (m_pPathArray)
    {
        unsigned int ItemUpdateArray = ::GetStoredFormID((::FUN_0058b600_shell *)this);
        if (ItemUpdateArray)
        {
            for (unsigned int i = 0; i < ItemUpdateArray; i++)
            {
                FUN_0058a450* pChildPath = ((::FUN_0058a450 *)(reinterpret_cast<::FUN_0058b630_shell *>(this)->GetCameraPathAt(i)));
                reinterpret_cast<::BGSCameraPath *>((pChildPath))->AssignParentPath((::BGSCameraPath *)(::FUN_0058a450 *)(0));
                delete pChildPath;
            }
        }
        delete m_pPathArray;
    }
}

struct CameraPathMap
{
};

struct CameraPathArrayResize
{
    void Resize(unsigned int size);
};

struct CameraPathClone : public BGSCameraPath
{
    TESForm* FUN_0058a870(bool abPersist, CameraPathMap* apMap);
};

// Clones the base camera path, remaps its parent and previous paths through apMap, and copies the child form array when present.
// @fnv 0x0058a870
TESForm* CameraPathClone::FUN_0058a870(bool abPersist, CameraPathMap* apMap)
{
    CameraPathClone* pClone_ =
        static_cast<CameraPathClone*>(dynamic_cast<BGSCameraPath*>(((::TESForm *)(reinterpret_cast<::FUN_004867a0_cls *>(this)->FUN_004867a0((void *)(abPersist), apMap)))));
    BGSCameraPath* pFound4 = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((apMap))->FUN_00853130((std::uintptr_t)(m_pFirstCameraPath), (::fnv_00853130::CombatThreatRecord *&)(pFound4)) || !pFound4)
        pFound4 = m_pFirstCameraPath;
    BGSCameraPath* pParent3 = pFound4;
    reinterpret_cast<::BGSCameraPath *>((pClone_))->AssignParentPath(pParent3);
    pFound4 = 0;
    if (!reinterpret_cast<::fnv_00853130::NiTMapBase *>((apMap))->FUN_00853130((std::uintptr_t)(m_pSecondCameraPath), (::fnv_00853130::CombatThreatRecord *&)(pFound4)) || !pFound4)
        pFound4 = m_pSecondCameraPath;
    BGSCameraPath* pPrev = pFound4;
    reinterpret_cast<::LowProcess *>((pClone_))->SetCurrentBoundObject((::TESBoundObject *)(pPrev));
    if (m_pPathArray)
    {
        m_pPathArray->Compact();
        unsigned int uiCount5 = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pPathArray))->FUN_0084e3a0()));
        NiFormArray* pArray = pClone_->GetEntryObject();
        ((CameraPathArrayResize*)pArray)->Resize(uiCount5);
        TESForm* pLastVal = 0;
        for (unsigned int i5 = 0; i5 < uiCount5; i5++)
        {
            TESForm* pChildA = m_pPathArray->FUN_00877a30(i5);
            TESForm* pNewChildB1 = pChildA->CreateForm((void*)(int)abPersist, apMap);
            unsigned int uiValueC2 = (unsigned int)(std::uintptr_t)pNewChildB1;
            pArray->SetSize(i5, &uiValueC2);
            pLastVal = pNewChildB1;
        }
    }
    return pClone_;
}

struct CameraResponse
{
};
struct CameraFlag
{
    bool FUN_008256d0();
};
struct CameraPath : FUN_0058b600_shell
{
    CameraPath* FUN_0058b510(unsigned int context, unsigned int flags);
};

// @fnv 0x0058b510
CameraPath* CameraPath::FUN_0058b510(unsigned int context, unsigned int flags)
{
    CameraPath* result = 0;
    if (!reinterpret_cast<::FUN_00440d80_shell *>(this)->FUN_00440d80())
    {
        if (reinterpret_cast<::PerkEntryConditionSet *>((((::CameraResponse *)(reinterpret_cast<::BGSCameraPath *>(this)->GetConditions()))))->ContainsTrait({}, {}))
        {
            if (reinterpret_cast<FUN_0058b470_shell*>(this)->IsFlag80Set() || !((::CameraFlag *)(reinterpret_cast<::BGSCameraPath *>(this)->GetShotList()))->FUN_008256d0())
            {
                result = this;
            }
            unsigned int count = GetStoredFormID(this);
            if (count != 0)
            {
                CameraPath* descendant = 0;
                for (unsigned int i = 0; i < count; ++i)
                {
                    CameraPath* child = ((::CameraPath *)(reinterpret_cast<::FUN_0058b630_shell *>(this)->GetCameraPathAt(i)));
                    if (child != 0)
                        descendant = child->FUN_0058b510(context, flags);
                    if (descendant != 0)
                        break;
                }
                if (descendant != 0)
                    result = descendant;
            }
        }
    }
    return result;
}

namespace fnv_0058b350 {
class FUN_0058b3f0
{
  public:
    FUN_0058b3f0();
    unsigned int unk0, unk4, unk8, unkC, unk10, unk14;
};
class OwnerX
{
  public:
    unsigned int unk[11];
    FUN_0058b3f0* m_pEntryObject;
    FUN_0058b3f0* GetEntryObject();
};
// Returns m_pEntryObject, allocating a new FUN_0058b3f0 and storing it in m_pEntryObject if it was null.
// @fnv 0x0058b350
FUN_0058b3f0* OwnerX::GetEntryObject()
{
    return m_pEntryObject ? m_pEntryObject : (m_pEntryObject = new FUN_0058b3f0);
}
}  // namespace fnv_0058b350

#include "generated/data/fallout_shared/bgscamerapath.inc"
