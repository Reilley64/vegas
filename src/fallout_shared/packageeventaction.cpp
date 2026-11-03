// fallout_shared/packageeventaction.cpp: PackageEventActionData (7 functions)

#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_00537e90.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abed0_shell.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/Scr.h"
#include "fnv/decl/ScriptCompareOwner.h"
#include "fnv/decl/TESRegionGrassObject.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_005ac4f0__FUN_005ac4f0_shell.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004ff000.h"
#include "fnv/symbols_005b5000.h"
#include "packageeventaction_decls.h"
#include <malloc.h>
#include <string.h>

// @fnv 0x00680890
PackageEventActionData::PackageEventActionData()
{}

// @fnv 0x0067e190
void PackageEventActionData::InitItem(TESForm* owner)
{
    unsigned int id = (unsigned int)m_item;
    ::ResolveFormID((unsigned int *)&(id), owner->GetFile(-1));
    TESObjectANIO* idle = dynamic_cast<TESObjectANIO*>(::FUN_004839c0(id));
    if (idle)
        m_item = idle;
    else if (id)
    {
        if (((BGSCameraPath*)owner)->HasNameForWarning())
            ::FUN_005b5e40();
        else
            ::FUN_005b5e40();
        m_item = 0;
    }
    id = (unsigned int)pTopic;
    ::ResolveFormID((unsigned int *)&(id), owner->GetFile(-1));
    TESTopic* topic = dynamic_cast<TESTopic*>(::FUN_004839c0(id));
    if (topic)
        pTopic = topic;
    else if (id)
    {
        if (((BGSCameraPath*)owner)->HasNameForWarning())
            ::FUN_005b5e40();
        else
            ::FUN_005b5e40();
        pTopic = 0;
    }
    if (m_pkNext)
    {
        int errors;
        int oldWarning = ::FUN_0046e8a0();
        ::FUN_0043b2b0(true);
        ::FUN_004fffe0(0);
        ((Script*)m_pkNext)->NotifySaveLoadGameOfFormChange();
        reinterpret_cast<::Scr *>((((Script*)m_pkNext)))->FUN_005ab400(owner);
        ((ScriptHeaderData*)((BGSCameraPath*)m_pkNext)->GetConditions())->m_bQuest = false;
        ::FUN_0043b2b0(false);
        errors = ::FUN_0046e8a0();
        ::FUN_004fffe0(oldWarning);
        if (errors)
            ::FUN_005b5e40();
    }
}

// Loads a Script from a TESFile: reads variable, condition, data, reference and item/topic chunks, then discards the script if it has no data.
// @fnv 0x0067dd20
void PackageEventActionData::Load(TESFile* file)
{
    unsigned int id;
    m_item = 0;
    pTopic = 0;
    if (m_pkNext)
    {
        delete (Script*)m_pkNext;
        m_pkNext = 0;
    }
    m_pkNext = (BSSimpleList<TESForm*>*)new Script;
    for (;;)
    {
        bool done = false;
        switch ((int)((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())))
        {
        case 0x44534c53:
        case 0x52564353:
            if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 0x44534c53)
            {
                DAT_011d66ac = new ScriptVariableInfo;
                DAT_011d66ac->Load(file);
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>((((Script*)m_pkNext)))->FUN_005d43e0()))))->FUN_00905820((void *)&(DAT_011d66ac));
            }
            else if (DAT_011d66ac)
            {
                char* name = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(name), 512);
                reinterpret_cast<::TextString *>(&(DAT_011d66ac->m_kName))->FUN_004037f0(name, 0);
            }
            break;
        case 0x52484353:
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(((BGSCameraPath*)m_pkNext)->GetConditions()), 0);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00414220_shell *>((((ScriptHeaderData*)((BGSCameraPath*)m_pkNext)->GetConditions())))->FUN_00414220();
            break;
        case 0x41444353: {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            char* data = (char*)_alloca(size);
            memset(data, 0, size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(data), 0);
            reinterpret_cast<::FUN_005aae70_shell *>((((Script*)m_pkNext)))->FUN_005aae70(size, data);
            break;
        }
        case 0x4f524353: {
            unsigned int formID;
            ScriptReferencedObject* object = new ScriptReferencedObject;
            file->GetChunkData(&formID);
            object->pForm = (TESForm*)formID;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((((Script*)m_pkNext)))->FUN_005d43c0()))))->FUN_00905820((void *)&(object));
            break;
        }
        case 0x56524353: {
            unsigned int formID;
            ScriptReferencedObject* object = new ScriptReferencedObject;
            file->GetChunkData(&formID);
            object->m_uiFormID = formID;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((((Script*)m_pkNext)))->FUN_005d43c0()))))->FUN_00905820((void *)&(object));
            break;
        }
        break;
        case 0x4d414e49:
            file->GetChunkData(&id);
            m_item = (TESForm*)id;
            break;
        case 0x4d414e54:
            file->GetChunkData(&id);
            pTopic = (TESForm*)id;
            done = true;
            break;
        }
        if (done)
            break;
        file->NextChunk();
    }
    ((Script*)m_pkNext)->SetInitializationState(false);
    if (!((Script*)m_pkNext)->GetData())
    {
        delete (Script*)m_pkNext;
        m_pkNext = 0;
    }
}

struct FUN_0067da80_shell : public PackageEventActionData
{
    void FUN_0067da80();
};

struct DummyVtable
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~DummyVtable();
};

// @fnv 0x0067da80
void FUN_0067da80_shell::FUN_0067da80()
{
    *(int*)this = 0;
    *((int*)this + 2) = 0;
    delete *((DummyVtable**)&this->m_pkNext);
}

struct FUN_005abe00
{
    void ProcessHeader();
};
struct FUN_0067dc80
{
    TESForm* m_pIdleForm;
    FUN_005abe00* m_pScript;
    TESForm* pTopic;
    void Save(int aeChunk);
};
// @fnv 0x0067dc80
void FUN_0067dc80::Save(int aeChunk)
{
    ::FUN_004856d0(aeChunk);
    unsigned int iid = m_pIdleForm ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((m_pIdleForm))->FUN_0084e3a0())) : 0;
    ::FUN_00485910(0x4d414e49, iid);
    iid = pTopic ? ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((pTopic))->FUN_0084e3a0())) : 0;
    if (m_pScript)
        m_pScript->ProcessHeader();
    ::FUN_00485910(0x4d414e54, iid);
}

struct QuantityData
{
};

struct MagicCaster
{
};

struct TESObjectREFR
{
};

struct ArrSI
{
};

struct GO
{
    operator unsigned int() const;
};

struct FUN_0067dad0_shell
{
    void* m_pIdleForm;
    Script* m_pScript;

    void FUN_0067dad0(PackageEventActionData* apCopy);
};


// Copies quantity, flags and form ID from apCopy, then clones or clears the script pointer depending on whether apCopy has one.
// @fnv 0x0067dad0
void FUN_0067dad0_shell::FUN_0067dad0(PackageEventActionData* apCopy)
{
    reinterpret_cast<::FUN_00537e90 *>((reinterpret_cast<QuantityData*>(this)))->SetQuantity(reinterpret_cast<GO*>(apCopy)->operator unsigned int());

    reinterpret_cast<::TESRegionGrassObject *>((reinterpret_cast<TESObjectREFR*>(this)))->AssignLandTexture((::TESLandTexture *)(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<ArrSI*>(apCopy)))->GetName()))));

    reinterpret_cast<::FUN_0041fd00_shell *>((reinterpret_cast<MagicCaster*>(this)))->FUN_0041fd00(((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<TESForm*>(apCopy)))->FUN_0084e3a0())));

    if (reinterpret_cast<FUN_0067dad0_shell*>(apCopy)->m_pScript)
    {
        if (!m_pScript)
        {
            m_pScript = new Script;
            m_pScript->NotifySaveLoadGameOfFormChange();
        }
        reinterpret_cast<::FUN_005aa420_shell *>((m_pScript))->CopyFromScript(reinterpret_cast<FUN_0067dad0_shell*>(apCopy)->m_pScript);
    }
    else
    {
        delete m_pScript;
        m_pScript = 0;
    }
}

struct TESObjectREFR_GetFlags_caller
{
    operator const char*() const;
};

struct FUN_00726070_shell
{
};

struct FUN_005ab240_shell
{
};

struct FUN_0067dbf0_shell
{
    int unk00;
    int unk04;
    int unk08;
    bool FUN_0067dbf0(TESObjectREFR_GetFlags_caller* apParam);
};

// @fnv 0x0067dbf0
bool FUN_0067dbf0_shell::FUN_0067dbf0(TESObjectREFR_GetFlags_caller* apParam)
{
    if (unk00 != (int)(void*)apParam->operator const char*())
        return true;
    if (unk08 != ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((apParam))->GetName())))
        return true;
    if ((void*)unk04 || reinterpret_cast<::Callees *>((((FUN_00726070_shell*)apParam)))->FUN_00726070())
    {
        if (!(void*)unk04 || !reinterpret_cast<::Callees *>((((FUN_00726070_shell*)apParam)))->FUN_00726070())
            return true;
        if (reinterpret_cast<::ScriptCompareOwner *>((((FUN_005ab240_shell*)unk04)))->IsDifferentFrom((::Script *)(void *)(reinterpret_cast<::Callees *>((((FUN_00726070_shell*)apParam)))->FUN_00726070())))
            return true;
    }
    return false;
}

#include "generated/data/fallout_shared/packageeventaction.inc"
