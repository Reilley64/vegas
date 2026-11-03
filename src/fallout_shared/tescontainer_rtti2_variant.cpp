// src/fallout_shared/tescontainer_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (-). The skeleton of src/fallout_shared/tescontainer.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/BaseProcess.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_0040e7f0_owner.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00481a90_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/p07__DelStandIn.h"
#include "fnv/symbols_00472000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "tescontainer_decls.h"
#include "BaseFormComponent.h"
class ContainerItemExtra
{
  public:
    void* m_pForm;
    union
    {
        void* m_pGlobal;
        int m_cRank;
        unsigned int bits;
    };
    float m_fHealth;
    ContainerItemExtra();
    void Copy(ContainerItemExtra* other);
    bool IsDefault();
};
class InventoryItemEntry
{
  public:
    int count;
    void* object;
    ContainerItemExtra* extra;
    void Copy(InventoryItemEntry* other);
};
struct ContainerCountState
{
    int count;
    BSSimpleList<InventoryStackRecord*>* list;
};
class TESContainer;
struct CopyComponentState
{
    BSSimpleList<InventoryStackRecord*>* list;
    TESContainer* source;
};
class TESContainer : public BaseFormComponent
{
  public:
    BSSimpleList<InventoryStackRecord*> objectList;
    virtual void Init();
    void ClearObjects();
    void InitItem(TESForm* form);
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent* component);
    ~TESContainer();
    bool HasObjectOfType(TESObject* object);
    int GetObjectCount(TESObject* object);
    static bool IsValidContainerType(unsigned char type);
    TESContainer();
};

class TESFile;
class TESForm
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual const char* GetEditorID();

public:
    ::TESFile *GetFile(int);
};

class TESBoundObject : public TESForm
{
};

class B81390Extra
{
  public:
};


class B81390ContainerObject
{
  public:
    void FUN_00481390(TESForm* pkOwner);

    int m_iArrayLength;
    TESBoundObject* m_pPointer;
    B81390Extra* m_pkExtra;
};

// @fnv 0x00481390
void B81390ContainerObject::FUN_00481390(TESForm* pkOwner)
{
    unsigned int auiFormId = (unsigned int)m_pPointer;
    ::ResolveFormID(&auiFormId, (::TESFile *)(((int)(pkOwner->GetFile(-1)))));
    m_pPointer = dynamic_cast<TESBoundObject*>(FUN_004839c0(auiFormId));
    if (!m_pPointer)
    {
        if (pkOwner)
        {
            if (reinterpret_cast<::BGSCameraPath *>((pkOwner))->HasNameForWarning())
                ::FUN_005b5e40();
            else
                ::FUN_005b5e40();
        }
        else
        {
            ::FUN_005b5e40();
        }
    }
    if (m_pkExtra)
        reinterpret_cast<::FUN_0040e7f0_owner *>((m_pkExtra))->ResolveFormReferences((::FormContext *)(pkOwner));
}
