// fallout_shared/bgsdefaultobjectmanager.cpp: BGSDefaultObjectManager, NavMesh (11 functions)

#include "fnv/decl/FUN_00401290_Class.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00483630_holder.h"
#include "fnv/decl/FUN_00485c10_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "bgsdefaultobjectmanager_form.h"
#include "bgsdefaultobjectmanager.h"
#include <string.h>

// Zeroes the default object array with memset.
// @fnv 0x0058d840
void BGSDefaultObjectManager::ResetFormData()
{
    memset(m_apDefaultObjects, 0, sizeof(m_apDefaultObjects));
}

// @fnv 0x0058db10
TESForm* BGSDefaultObjectManager::GetDefaultObjectByIndex(DEFAULT_OBJECT index)
{
    if (!reinterpret_cast<::TESForm *>((void *)(Instance()))->GetInitialized())
        return 0;
    return Instance()->m_apDefaultObjects[index];
}

// Returns the singleton BGSDefaultObjectManager, allocating it with new if it has not been created yet.
// @fnv 0x0058d680
BGSDefaultObjectManager* BGSDefaultObjectManager::Instance()
{
    if (!ms_pSystemUtility)
        ms_pSystemUtility = new BGSDefaultObjectManager;
    return ms_pSystemUtility;
}

#include "bgsdefaultobjectmanager_endian.h"

// Reads a TESFile record of form type 100, loads the DATA chunk into the default object array and byte-swaps it when endian conversion is required.
// @fnv 0x0058d920
bool BGSDefaultObjectManager::Load(TESFile* file)
{
    unsigned char form = ((unsigned char)(reinterpret_cast<::FUN_00472660_shell *>((file))->FUN_00472660()));
    if (form != 100)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    while (unsigned int chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
    {
        switch (chunk)
        {
        case 0x41544144:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(m_apDefaultObjects), sizeof(m_apDefaultObjects));
            if (file->IsEndianConversionRequired())
            {
                for (int i = 0; i < DEFAULT_OBJECT_DO_COUNT; ++i)
                    ::FUN_00401080((int *)(unsigned int *)((unsigned int*)&m_apDefaultObjects[i]));
            }
            break;
        }
        if (!file->NextChunk())
            break;
    }
    SetInitializationState(false);
    return true;
}

#include "bgsdefaultobjectmanager_decls.h"
// If not yet initialized, resolves each of the 34 default object IDs to a form, clears mismatched types, warns on failures, then marks the manager initialized.
// @fnv 0x0058da10
void BGSDefaultObjectManager::InitItem()
{
    if (GetInitialized())
        return;
    for (int i = 0; i < 34; ++i)
    {
        unsigned int uiFormId = (unsigned int)m_apDefaultObjects[i];
        if (uiFormId)
        {
            ::ResolveFormID((unsigned int *)&(uiFormId), GetFile(-1));
            m_apDefaultObjects[i] = ::FUN_004839c0(uiFormId);
            if (m_apDefaultObjects[i] && m_apDefaultObjects[i]->GetFormType() != DAT_0118c360[i].type)
                m_apDefaultObjects[i] = 0;
            if (!m_apDefaultObjects[i])
                ::FUN_005b5e40();
        }
    }
    SetInitializationState(true);
}

#include "bgsdefaultobjectmanager_nav.h"
// @fnv 0x0068eb80
NavMesh::NavMesh() : POVPointerArray(37)
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_NAVM_ID)));
    m_pOwningCell = 0;
    m_pNavigationMesh = 0;
    pTriangleToObstacleMap = new NiTMap_unsigned_short_NiPointer_ObstacleData___(37);
}

// Deletes the BGSDefaultObjectManager singleton instance and clears its pointer if it is set.
// @fnv 0x0058d710
void DestroyDefaultObjectManager()
{
    if (BGSDefaultObjectManager::ms_pSystemUtility)
    {
        delete BGSDefaultObjectManager::ms_pSystemUtility;
        BGSDefaultObjectManager::ms_pSystemUtility = 0;
    }
}

struct ActorValueInfo
{
};

struct FUN_0058d760 : public TESForm
{
    FUN_0058d760();
    virtual ~FUN_0058d760();
};

// @fnv 0x0058d760
FUN_0058d760::FUN_0058d760() : TESForm()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)((ENUM_FORM_ID)100)));
    SetRefID(0x31, 1);
    reinterpret_cast<::FUN_00401290_Class *>((((ActorValueInfo*)this)))->FUN_00401290((int)("DefaultObjectManager"));
    ((BGSDefaultObjectManager*)this)->ResetFormData();
}

struct S_0058d7f0
{
    void* FUN_0058d7f0(unsigned int);
};
struct FUN_004855a0
{
};
struct FUN_00485680
{
};
struct FUN_0058d870_shell
{
    void FUN_0058d870();
};
// @fnv 0x0058d870
void FUN_0058d870_shell::FUN_0058d870()
{
    unsigned int pidarray4[34];
    int i;
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0*)this)))->FUN_004855a0();
    for (i = 0; i < 34; ++i)
    {
        if (*(void**)((char*)this + 0x18 + i * 4))
            pidarray4[i] = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((TESForm*)*(void**)((char*)this + 0x18 + i * 4))))->FUN_0084e3a0()));
        else
            pidarray4[i] = 0;
    }
    ::FUN_00485710((void *)(0x41544144), pidarray4, (void *)(34));
    reinterpret_cast<::Holder *>((((FUN_00485680*)this)))->FUN_00485680();
}

// InitializeVTable: constructor-like member that installs the class vtable
// pointer into *this and then calls a base routine with this as `this`.
extern int DAT_01032dc4;

struct FUN_0058d820_cls
{
    void* m_pVTable;
    void InitializeVTable();
};
// Calls InitializeVTable, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0058d7f0
void* S_0058d7f0::FUN_0058d7f0(unsigned int flags)
{
    reinterpret_cast<::FUN_0058d820_cls *>(this)->InitializeVTable();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// @fnv 0x0058d820
void FUN_0058d820_cls::InitializeVTable()
{
    m_pVTable = (void*)&DAT_01032dc4;
    reinterpret_cast<::FUN_00483630_holder *>(this)->FUN_00483630_holder::~FUN_00483630_holder();
}
