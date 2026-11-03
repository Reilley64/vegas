// fallout_shared/bgsbodypartdata.cpp: BGSBodyPartData (10 functions)

#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00440d80_shell.h"
#include "fnv/decl/FUN_00472660_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00485c10_shell.h"
#include "fnv/decl/FUN_004a0c10_s.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005e5190_Class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/Obj5e5300.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_00484730__FUN_00484730_shell.h"
#include "fnv/decl/fnv_006838b0__FUN_006838b0_shell.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_011c3000.h"
#include "bgsbodypartdata.h"
#include "string.h"
#include <malloc.h>

BGSBodyPartData* BGSBodyPartData::ms_pBodyPartData;
BGSBodyPartData* BGSBodyPartData::ms_pBodyPartDataInstance;

static const char s_ragdollWarning[] = "MASTERFILE: Could not find ragdoll (%08X) for bodypart data '%s' (%08X).";
static const char s_loadFailedWarning[] = "MASTERFILE: Load failed for body part data '%s' (%08X).";
static const char s_advancedTooFarWarning[] =
    "MASTERFILE: Body part data for '%s' (%08X) advanced file too far. Attempting recovery.";
static const char s_partWarningsWarning[] =
    "MASTERFILE: Warnings encountered loading part '%s' for body part data '%s' (%08X).";
static const char s_alreadyInUseWarning[] = "MODELS: Body part index %i already in use in body part data %s (%08X).";
static const char s_invalidIndexWarning[] = "MODELS: Invalid body part index %i in body part data %s (%08X).";
static const char s_defaultBodyPartData[] = "DefaultBodyPartData";
static const char s_playerBodyPartData[] = "PlayerBodyPartData";

// @fnv 0x005e4af0
BGSBodyPartData::BGSBodyPartData()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0((*(int *)&(const ::ENUM_FORM_ID &)(ENUM_FORM_ID_BPTD_ID)));
    ResetFormData();
}

// @fnv 0x005e4c40
void BGSBodyPartData::ResetFormData()
{
    memset(m_apBodyParts, 0, sizeof(m_apBodyParts));
    m_pRagdoll = 0;
}

// @fnv 0x005e4c70
void BGSBodyPartData::ClearData()
{
    ClearBodyParts();
}

// Deletes all 15 entries in the body part array and sets each pointer to null.
// @fnv 0x005e51b0
void BGSBodyPartData::ClearBodyParts()
{
    for (int i = 0; i < 15; ++i)
    {
        delete m_apBodyParts[i];
        m_apBodyParts[i] = 0;
    }
}

// @fnv 0x005e4c90
void BGSBodyPartData::InitItem()
{
    if (reinterpret_cast<::TESForm *>((void *)(static_cast<TESFormInitFlag*>(static_cast<TESForm*>(this))))->GetInitialized())
        return;
    for (int i = 0; i < 15; ++i)
    {
        BGSBodyPart* part = m_apBodyParts[i];
        if (part)
            part->InitItem(this);
    }
    unsigned int ragdollID = reinterpret_cast<unsigned int>(m_pRagdoll);
    if (ragdollID)
    {
        ::ResolveFormID((unsigned int *)&(ragdollID), GetFile(-1));
        m_pRagdoll = dynamic_cast<BGSRagdoll*>(::FUN_004839c0(ragdollID));
        if (!m_pRagdoll)
            ::FUN_005b5e40();
    }
    SetInitializationState(true);
}

// Loads a BGSBodyPartData from a TESFile: validates the BPTD form ID, reads the record header and dispatches EDID/OBND/MODL/MODT/PNAM/BPNN/BPTN/NAM0/RAGA chunks.
// @fnv 0x005e4d80
bool BGSBodyPartData::Load(TESFile* file)
{
    if (reinterpret_cast<::FUN_00472660_shell *>((static_cast<TESFileFormInt*>(file)))->FUN_00472660() != ENUM_FORM_ID_BPTD_ID)
        return false;
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    int chunk;
    bool bRecovered;
read_chunk:
    chunk = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()));
    if (chunk)
    {
        bRecovered = false;
        switch (chunk)
        {
        case 0x44494445:  // EDID
        {
            char* buffer = static_cast<char*>(_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C()));
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(buffer), 0x200);
            SetEditorID_AtRuntime(buffer);
            break;
        }
        case 0x444E424F:  // OBND
            readOBNDSubRecord(file);
            break;
        case 0x4C444F4D:  // MODL
        case 0x54444F4D:  // MODT
            TESModel::LoadModelData(static_cast<TESModel*>(this), file);
            break;
        case 0x4D414E50:  // PNAM
        case 0x4E4E5042:  // BPNN
        case 0x4E545042:  // BPTN
        {
            BGSBodyPart* part = new BGSBodyPart;
            int warnings = ::FUN_0046e8a0();
            if (!part->Load(file))
            {
                ::FUN_005b5e40();
                delete part;
                return false;
                goto check_warnings;
            }
            switch (static_cast<int>(((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))))
            {
            case 0x4E4E5042:  // BPNN
            case 0x41474152:  // RAGA
            case 0x4D414E50:  // PNAM
            case 0x4E545042:  // BPTN
                ::FUN_005b5e40();
                bRecovered = true;
                break;
            }
        check_warnings:
            if (::FUN_0046e8a0() != warnings)
                ::FUN_005b5e40();
            AddBodyPart(part);
            break;
        }
        case 0x41474152:  // RAGA
        {
            unsigned int ragdollID = 0;
            file->GetChunkData(&ragdollID);
            m_pRagdoll = reinterpret_cast<BGSRagdoll*>(ragdollID);
            break;
        }
        }
        if (!bRecovered && !file->NextChunk())
            goto done;
        goto read_chunk;
    }
done:
    return true;
}

// Stores a body part in the slot given by its limb index, warning and deleting any existing part if the slot is occupied or the index is out of range.
// @fnv 0x005e5220
void BGSBodyPartData::AddBodyPart(BGSBodyPart* part)
{
    if (part)
    {
        int index = ((int)(reinterpret_cast<::Obj5e5300 *>((part))->GetByte61()));
        if (index >= 0 && index < 15)
        {
            if (m_apBodyParts[index])
            {
                ::FUN_005b5e40();
                delete m_apBodyParts[index];
            }
            m_apBodyParts[index] = part;
        }
        else
            ::FUN_005b5e40();
    }
}

// @fnv 0x005e5590
void BGSBodyPartData::QueueResourceLoad(IO_TASK_PRIORITY priority, QueuedFile* file)
{
    for (int i = 0; i < 15; ++i)
    {
        BGSBodyPart* part = m_apBodyParts[i];
        if (part)
            part->QueueResourceLoad(priority, file);
    }
}

// Looks up BGSBodyPartData forms 0x1D and 0x1C, creating and registering them with editor IDs if missing.
// @fnv 0x005e53a0
void BGSBodyPartData::InitializeBodyPartData()
{
    ms_pBodyPartData = dynamic_cast<BGSBodyPartData*>(::FUN_004839c0(0x1D));
    if (!ms_pBodyPartData)
    {
        ms_pBodyPartData = new BGSBodyPartData;
        ms_pBodyPartData->SetRefID(0x1D, true);
        ms_pBodyPartData->SetEditorID_AtRuntime(s_defaultBodyPartData);
        reinterpret_cast<::TESDataHandler *>((static_cast<TESDataHandlerForms*>((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->AddFormToDataHandler(ms_pBodyPartData);
        ms_pBodyPartData->SetAltered(false);
    }
    ms_pBodyPartDataInstance = dynamic_cast<BGSBodyPartData*>(::FUN_004839c0(0x1C));
    if (!ms_pBodyPartDataInstance)
    {
        ms_pBodyPartDataInstance = new BGSBodyPartData;
        ms_pBodyPartDataInstance->SetRefID(0x1C, true);
        ms_pBodyPartDataInstance->SetEditorID_AtRuntime(s_playerBodyPartData);
        reinterpret_cast<::TESDataHandler *>((static_cast<TESDataHandlerForms*>((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->AddFormToDataHandler(ms_pBodyPartDataInstance);
        ms_pBodyPartDataInstance->SetAltered(false);
        ms_pBodyPartDataInstance = 0;
    }
}

struct FUN_005e5130_Elem
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    signed char flag;
    signed char unk61, unk62, unk63;
};
struct FUN_005e5130_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30;
    FUN_005e5130_Elem* entries[15];
    FUN_005e5130_Elem* FUN_005e5130(int value);
};
// Searches the entries array for an element whose GetByte63 matches value and returns it, or null if none found.
// @fnv 0x005e5130
FUN_005e5130_Elem* FUN_005e5130_Class::FUN_005e5130(int value)
{
    FUN_005e5130_Elem* pFound = 0;
    for (int index = 0; index < 15; ++index)
    {
        FUN_005e5130_Elem* pEntry = entries[index];
        if (!pEntry)
            continue;
        if (((signed char)(reinterpret_cast<::FUN_005e5190_Class *>((pEntry))->GetByte63())) == value)
        {
            pFound = pEntry;
            break;
        }
    }
    return pFound;
}
