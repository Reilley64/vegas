// tesloadscreen.cpp: TESLoadScreen, LoadScreenA6C, FormT (13 functions)

#include <new>
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Class005a6b10.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00509540_obj.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FormCloneOperation.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00587000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_01183000.h"
#include "fnv/symbols_011c3000.h"
#include "tesloadscreen.h"
#include "tesloadscreen_decls.h"

extern "C" const char kTESLoadScreenWarning[];
const char kTESLoadScreenWarning[] = "MASTERFILE: File %s contains old data for loadscreen %s (%08X).";

// Empty destructor for TESLoadScreen; performs no work.
// @fnv 0x005a67b0
TESLoadScreen::~TESLoadScreen()
{}

// Reads the load screen record header and chunks (EDID, OBND, ICON, DESC, LNAM, FNAM, WMI1), storing editor ID, text, form list entries and load screen type.
// @fnv 0x005a68d0
bool TESLoadScreen::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);

    int chunkID;
    while ((chunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (chunkID)
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID_AtRuntime(editorID);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4e4f4349:
            TESTexture::ReadTextureData(static_cast<TESTexture*>(this), file);
            break;
        case 0x43534544: {
            char* text = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(text), 0);
            reinterpret_cast<::TextString *>(&(m_kLoadScreenText))->FUN_004037f0(text, 0);
            break;
        }
        case 0x4d414e4c: {
            WorldCellRecord* loadForm = new WorldCellRecord;
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(loadForm), 12);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::Class005a6b10 *>((reinterpret_cast<ContainerItemExtraFileData*>(loadForm)))->FUN_005a6b10();
            reinterpret_cast<BSSimpleList<TESObjectREFR*>*>(&m_kWorldCellRecordList)
                ->AddHead(reinterpret_cast<TESObjectREFR*&>(loadForm));
            break;
        }
        case 0x4d414e46:
            ::FUN_005b5e40();
            break;
        case 0x31494d57: {
            unsigned int loadScreenType = 0;
            file->GetChunkData(&loadScreenType);
            if (loadScreenType)
                m_pLoadScreenType = reinterpret_cast<TESLoadScreenType*>(loadScreenType);
            break;
        }
        }
        if (!file->NextChunk())
            break;
    }

    return true;
}

// @fnv 0x005a66e0
TESLoadScreen::TESLoadScreen()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(FORM_ID_LSCR)));
    SetInitializationState(true);
    m_pLoadScreenType = 0;
}

// @fnv 0x005a6880
void TESLoadScreen::ClearData()
{
    ClearLoadScreenData();
    m_pLoadScreenType = 0;
    TESForm::ClearData();
}

// Deletes every element of the loading screen list and then clears the list.
// @fnv 0x005a6e50
void TESLoadScreen::ClearLoadScreenData()
{
    BSSimpleList<WorldCellRecord*>* item = &m_kWorldCellRecordList;
    while (item && !item->IsEmpty())
    {
        WorldCellRecord* data = ((::WorldCellRecord *)(new ((void *)(item)) ::Vec3()));
        delete data;
        item = ((::BSSimpleList< ::WorldCellRecord *> *)(reinterpret_cast<::Callees *>((item))->FUN_00726070()));
    }
    reinterpret_cast<::FileMatchList *>(&(m_kWorldCellRecordList))->RemoveAll();
}

// @fnv 0x005a6b70
void TESLoadScreen::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    BSSimpleList<WorldCellRecord*>* item = &m_kWorldCellRecordList;
    BSSimpleList<WorldCellRecord*>* previous = 0;
    while (item && !item->IsEmpty())
    {
        WorldCellRecord* data = ((::WorldCellRecord *)(new ((void *)(item)) ::Vec3()));
        if (data->auiFormId)
            ::ResolveFormID((unsigned int *)&(data->auiFormId), GetFile(-1));
        if (data->uiWorldID)
            ::ResolveFormID((unsigned int *)&(data->uiWorldID), GetFile(-1));
        previous = item;
        item = ((::BSSimpleList< ::WorldCellRecord *> *)(reinterpret_cast<::Callees *>((item))->FUN_00726070()));
    }
    if (m_pLoadScreenType)
    {
        unsigned int formID = 0;
        formID = reinterpret_cast<unsigned int>(m_pLoadScreenType);
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        m_pLoadScreenType = (*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))->GetLoadScreenType(formID);
    }
    SetInitializationState(true);
}

// Builds a location key from the form's cell, worldspace or reference and checks whether it matches an entry in the load screen location list.
// @fnv 0x005a6ec0
bool TESLoadScreen::MatchesFormLocation(TESForm* form)
{
    bool validLocation = false;
    WorldCellRecord location = {0, 0, 0};
    bool display = false;
    switch (form->GetFormType())
    {
    case FORM_ID_CELL: {
        TESObjectCELL* cell = static_cast<TESObjectCELL*>(form);
        if (cell->IsCellInterior())
        {
            location.auiFormId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((cell))->FUN_0084e3a0()));
            location.uiWorldID = 0;
            location.uiCellKey = 0;
            display = true;
        }
        else
        {
            TESWorldSpace* world = cell->GetParentWorldSpace();
            if (world)
            {
                location.auiFormId = 0;
                location.uiWorldID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((world))->FUN_0084e3a0()));
                location.uiCellKey = ::PackShortPair(cell->GetCellGridX(), cell->GetCellGridY());
                display = true;
            }
        }
        break;
    }
    case FORM_ID_WRLD: {
        TESWorldSpace* world = static_cast<TESWorldSpace*>(form);
        location.auiFormId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((world))->FUN_0084e3a0()));
        location.uiWorldID = 0;
        location.uiCellKey = 0;
        display = true;
        break;
    }
    case FORM_ID_REFR:
    case FORM_ID_ACHR:
    case FORM_ID_ACRE:
    case FORM_ID_PMIS:
    case FORM_ID_PGRE:
    case FORM_ID_PBEA:
    case FORM_ID_PFLA:
    case FORM_ID_PBAR: {
        TESObjectREFR* ref = static_cast<TESObjectREFR*>(form);
        TESObjectCELL* cell = ((::TESObjectCELL *)(reinterpret_cast<::LowProcess *>((void *)(ref))->GetTarget()));
        if (cell && cell->IsCellInterior())
        {
            location.auiFormId = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((cell))->FUN_0084e3a0()));
            location.uiWorldID = 0;
            location.uiCellKey = 0;
            display = true;
        }
        else
        {
            TESWorldSpace* world = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((ref))->FUN_00575d70()));
            if (world)
            {
                location.auiFormId = 0;
                location.uiWorldID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((world))->FUN_0084e3a0()));
                location.uiCellKey = ::FUN_00587440((const ::NiPoint3 *)&(*ref->GetPos()));
                display = true;
            }
        }
        break;
    }
    }
    if (display)
    {
        BSSimpleList<WorldCellRecord*>* item = &m_kWorldCellRecordList;
        while (item && !item->IsEmpty())
        {
            WorldCellRecord* data = ((::WorldCellRecord *)(new ((void *)(item)) ::Vec3()));
            if (location.auiFormId)
            {
                if (data->auiFormId == location.auiFormId)
                {
                    validLocation = true;
                    break;
                }
            }
            else if (location.uiWorldID)
            {
                if (data->uiWorldID == location.uiWorldID && data->uiCellKey == location.uiCellKey)
                {
                    validLocation = true;
                    break;
                }
            }
            item = ((::BSSimpleList< ::WorldCellRecord *> *)(reinterpret_cast<::Callees *>((item))->FUN_00726070()));
        }
    }
    return validLocation;
}

struct FUN_005a7110_shell : public TESLoadScreen
{
    bool FUN_005a7110();
};

bool _ref_008256d0(void*);

// @fnv 0x005a7110
bool FUN_005a7110_shell::FUN_005a7110()
{
    return _ref_008256d0((char*)&this->m_kWorldCellRecordList);
}

struct FUN_005a7130_shell : public TESLoadScreen
{
    int FUN_005a7130();
};

// Returns the int at offset 0x18 of the object stored at this+0x34, or 0 if that pointer is null.
// @fnv 0x005a7130
int FUN_005a7130_shell::FUN_005a7130()
{
    int eRetVal = 0;
    if (*(int**)&this->m_pLoadScreenType)
    {
        eRetVal = *(int*)((char*)*(int**)&this->m_pLoadScreenType + 0x18);
    }
    return eRetVal;
}

struct FUN_005a68b0_shell
{
    void FUN_005a68b0();
};

struct FUN_004855a0_standin
{
};
struct FUN_00485680_standin
{
};

// @fnv 0x005a68b0
void FUN_005a68b0_shell::FUN_005a68b0()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((((FUN_004855a0_standin*)this)))->FUN_004855a0();
    reinterpret_cast<::Holder *>((((FUN_00485680_standin*)this)))->FUN_00485680();
}

// TESLoadScreen destructor: clear the form data; members and base components are destroyed afterwards.

class A67E0Form
{
  public:
    virtual ~A67E0Form();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class A67E0Texture
{
  public:
    virtual ~A67E0Texture();
    char* m_pcPath;
    unsigned short m_usLen;
    unsigned short m_usMax;
};

class A67E0Description
{
  public:
    virtual void Unk_00();
    int unk04;
};

class A67E0LocationList
{
  public:
    ~A67E0LocationList();
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};

class A67E0String
{
  public:
    ~A67E0String();
    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMax;
};

class FUN_005a67e0 : public A67E0Form, public A67E0Texture, public A67E0Description
{
  public:
    virtual ~FUN_005a67e0();
    virtual void ClearData();

    A67E0LocationList m_kLocations;
    A67E0String m_kLoadingText;
};

// @fnv 0x005a67e0
FUN_005a67e0::~FUN_005a67e0()
{
    ClearData();
}

class LoadFormListA6C : public BSSimpleList<WorldCellRecord*>
{
  public:
};

class LoadScreenA6C : public TESLoadScreen
{
  public:
    void CopyLoadScreenData(TESForm* pkForm);
};

// Copies the load-screen type, form data and list items from another TESLoadScreen into this one.
// @fnv 0x005a6c70
void LoadScreenA6C::CopyLoadScreenData(TESForm* pkForm)
{
    BSSimpleList<WorldCellRecord*>* pkDstNode = 0;
    LoadScreenA6C* pkSource = static_cast<LoadScreenA6C*>(dynamic_cast<TESLoadScreen*>(pkForm));
    if (!pkSource)
        return;

    ClearLoadScreenData();

    BSSimpleList<WorldCellRecord*>* pkSrcIter = &pkSource->m_kWorldCellRecordList;
    pkDstNode = &m_kWorldCellRecordList;
    while (pkSrcIter && !pkSrcIter->IsEmpty())
    {
        reinterpret_cast<::Callees *>((static_cast<LoadFormListA6C*>(pkDstNode)))->FUN_00905820((void *)&(((::WorldCellRecord *)(new ((void *)(pkSrcIter)) ::Vec3()))));
        if (((::BSSimpleList< ::WorldCellRecord *> *)(reinterpret_cast<::Callees *>((pkDstNode))->FUN_00726070())))
            pkDstNode = ((::BSSimpleList< ::WorldCellRecord *> *)(reinterpret_cast<::Callees *>((pkDstNode))->FUN_00726070()));
        pkSrcIter = ((::BSSimpleList< ::WorldCellRecord *> *)(reinterpret_cast<::Callees *>((pkSrcIter))->FUN_00726070()));
    }

    reinterpret_cast<::LowProcess *>(this)->SetCurrentBoundObject((::TESBoundObject *)(::TESLoadScreenType *)(((::TESLoadScreenType *)(reinterpret_cast<::BGSCameraPath *>((pkSource))->GetPrevPath()))));
    reinterpret_cast<::FormCloneOperation *>(this)->FUN_004851b0(pkSource);
}

extern char DAT_01186260;
class ListX
{
  public:
    int FUN_005ae380();
    bool FUN_008256d0();
    void* head;
    void* next;
};
class FormT
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    ListX kList;
    bool FUN_005a6d30(void* pOther);
};
// @fnv 0x005a6d30
bool FormT::FUN_005a6d30(void* pOther)
{
    FormT* pOtherForm = (FormT*)dynamic_cast<::TESLoadScreen *>(reinterpret_cast<::TESForm *>(pOther));
    if (!pOtherForm)
        return true;
    ListX* it = &pOtherForm->kList;
    if (kList.FUN_005ae380() != it->FUN_005ae380())
        return true;
    while (it && !it->FUN_008256d0())
    {
        if (!reinterpret_cast<::RefList *>(&(kList))->FUN_005f65d0((void **)(void *)(((void *)(new ((void *)(it)) ::Vec3())))))
            return true;
        it = ((::ListX *)(reinterpret_cast<::Callees *>((it))->FUN_00726070()));
    }
    if (reinterpret_cast<::FUN_00509540_obj *>(this)->FUN_00485270((::TESForm *)(pOtherForm)))
        return true;
    if (((int)(reinterpret_cast<::BGSCameraPath *>(this)->GetPrevPath())) != ((int)(reinterpret_cast<::BGSCameraPath *>((pOtherForm))->GetPrevPath())))
        return true;
    return false;
}
