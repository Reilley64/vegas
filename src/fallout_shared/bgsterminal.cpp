// fallout_shared/bgsterminal.cpp: BGSTerminal, TermHack, PlayerCharacter, TerminalCleanup and more (31 functions)

#include <new>
#include <cstring>
#include "fnv/decl/ACTIView.h"
#include "fnv/decl/ActiV511.h"
#include "fnv/decl/BGSCameraPath.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CombatProcedure.h"
#include "fnv/decl/DownloadableContentManager.h"
#include "fnv/decl/Dummy00501c30.h"
#include "fnv/decl/FUN_00401660_Class.h"
#include "fnv/decl/FUN_00414220_shell.h"
#include "fnv/decl/FUN_00418830_shell.h"
#include "fnv/decl/FUN_0041bf50_class.h"
#include "fnv/decl/FUN_00461150_shell.h"
#include "fnv/decl/FUN_004726b0_class.h"
#include "fnv/decl/FUN_00477f20_shell.h"
#include "fnv/decl/FUN_0047d7c0_Class.h"
#include "fnv/decl/FUN_00482cb0_shell.h"
#include "fnv/decl/FUN_00487010_shell.h"
#include "fnv/decl/FUN_0048a520_shell.h"
#include "fnv/decl/FUN_0048a7b0_shell.h"
#include "fnv/decl/FUN_004f15a0_shell.h"
#include "fnv/decl/FUN_005010c0_class.h"
#include "fnv/decl/FUN_00501c10_cls.h"
#include "fnv/decl/FUN_00510770_shell.h"
#include "fnv/decl/FUN_00511860_holder.h"
#include "fnv/decl/FUN_00568260_shell.h"
#include "fnv/decl/FUN_00568680_shell.h"
#include "fnv/decl/FUN_00569b80_shell.h"
#include "fnv/decl/FUN_005aa420_shell.h"
#include "fnv/decl/FUN_005aae70_shell.h"
#include "fnv/decl/FUN_005abe00.h"
#include "fnv/decl/FUN_005d43c0_.h"
#include "fnv/decl/FUN_005d43e0_shell.h"
#include "fnv/decl/FUN_00680910_shell.h"
#include "fnv/decl/FUN_00680a70_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/Holder.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/InventoryStackRecord.h"
#include "fnv/decl/KarmaActor.h"
#include "fnv/decl/MagicProjectile.h"
#include "fnv/decl/OwnerLookupView.h"
#include "fnv/decl/OwnershipReferenceView.h"
#include "fnv/decl/PlayerCharShell.h"
#include "fnv/decl/RefList.h"
#include "fnv/decl/S00485110.h"
#include "fnv/decl/S_0048cca0.h"
#include "fnv/decl/S_005118c0.h"
#include "fnv/decl/Scr.h"
#include "fnv/decl/ScriptCompareOwner.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00403570__FUN_00403570_shell.h"
#include "fnv/decl/fnv_0041be10__FUN_0041be10_Class.h"
#include "fnv/decl/fnv_0041bf80__FUN_0041bf80_Class.h"
#include "fnv/decl/fnv_0041c060__MyThis.h"
#include "fnv/decl/fnv_00422c20__FUN_0042dec0_shell.h"
#include "fnv/decl/fnv_004280f0__FUN_004280f0_shell.h"
#include "fnv/decl/fnv_00472890__FUN_00472890_cls.h"
#include "fnv/decl/fnv_004855a0__ArrSI.h"
#include "fnv/decl/fnv_00567e10__FUN_00567e10_shell.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0043b000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_0046e000.h"
#include "fnv/symbols_00478000.h"
#include "fnv/symbols_0047a000.h"
#include "fnv/symbols_0047e000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_00485000.h"
#include "fnv/symbols_00487000.h"
#include "fnv/symbols_004ff000.h"
#include "fnv/symbols_00501000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005e5000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011c8000.h"
#include "fnv/symbols_011cd000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "bgsterminal_decls.h"

// Loads a terminal record from the file, dispatching each chunk to set the editor ID, model, script, menu items, sounds, and conditions.
// @fnv 0x00500000
bool BGSTerminal::Load(TESFile* file)
{
    reinterpret_cast<::S00485110 *>(this)->CallWithThis((::T00485110 *)(file));
    SetInitializationState(false);
    TerminalMenuItem* current = 0;
    int uiChunkID;
    while ((uiChunkID = ((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0()))) != 0)
    {
        switch (uiChunkID)
        {
        case 'DIDE': {
            char* editorID = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(editorID), 0x200);
            SetEditorID(editorID);
            break;
        }
        case 'DNBO':
            readOBNDSubRecord(file);
            break;
        case 'LLUF':
            ::ReadFullName(this, file);
            break;
        case 'LDOM':
        case 'TDOM':
        case 'DDOM':
        case 'DSOM':
            TESModel::LoadModelData(this, file);
            break;
        case 'SDOM': {
            void* textureData;
            unsigned int textureSize = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            textureData = _alloca(textureSize);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(textureData), textureSize);
            reinterpret_cast<::FUN_0048a7b0_shell *>(this)->LoadTextureSwapList(textureData, textureSize, reinterpret_cast<::fnv_00403570::FUN_00403570_shell *>((file))->FUN_00403570());
            break;
        }
        case 'IRCS': {
            Script* script = 0;
            file->GetChunkData((unsigned int*)&script);
            reinterpret_cast<::CombatProcedure *>(this)->Initialize((::CombatController *)(script));
            TESScriptableForm::InitItem(this);
            break;
        }
        case 'TSED':
        case 'DTSD':
            ::FUN_004781e0(this, file);
            break;
        case 'CSED':
            TESDescription::ReadDescriptionFromFile(this, file);
            break;
        case 'DSLS':
        case 'RVCS': {
            if (((unsigned int)(reinterpret_cast<::FUN_004726b0_class *>((file))->FUN_004726b0())) == 'DSLS')
            {
                DAT_011c83d4 = new ScriptVariableInfo;
                DAT_011c83d4->Load(file);
                reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptVariableInfo *> *)(reinterpret_cast<::FUN_005d43e0_shell *>(&(current->m_kScript))->FUN_005d43e0()))))->FUN_00905820((void *)&(DAT_011c83d4));
            }
            else if (DAT_011c83d4)
            {
                char* variableName = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(variableName), 0x200);
                reinterpret_cast<::TextString *>(&(DAT_011c83d4->m_kName))->FUN_004037f0(variableName, 0);
            }
            break;
        }
        case 'RHCS':
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(current->m_kScript))->GetConditions()))), 0);
            if (file->IsEndianConversionRequired())
                reinterpret_cast<::FUN_00414220_shell *>((((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(current->m_kScript))->GetConditions()))))->FUN_00414220();
            break;
        case 'ADCS': {
            unsigned int size = reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C();
            char* data = (char*)_alloca(size);
            memset(data, 0, size);
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(data), 0);
            reinterpret_cast<::FUN_005aae70_shell *>(&(current->m_kScript))->FUN_005aae70(size, data);
            break;
        }
        case 'ORCS': {
            unsigned int formID;
            ScriptReferencedObject* reference = new ScriptReferencedObject;
            file->GetChunkData(&formID);
            reference->form = (TESForm*)(std::uintptr_t)formID;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(&(current->m_kScript))->FUN_005d43c0()))))->FUN_00905820((void *)&(reference));
            break;
        }
        case 'VRCS': {
            struct
            {
                ScriptReferencedObject* reference;
                unsigned int variableID;
            } loadedVariable;
            loadedVariable.reference = new ScriptReferencedObject;
            file->GetChunkData(&loadedVariable.variableID);
            loadedVariable.reference->variableID = loadedVariable.variableID;
            reinterpret_cast<::Callees *>((((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>(&(current->m_kScript))->FUN_005d43c0()))))->FUN_00905820((void *)&(loadedVariable.reference));
            break;
        }
        case 'MANS': {
            TESSound* sound = 0;
            file->GetChunkData((unsigned int*)&sound);
            SetLoopingSound(sound);
            break;
        }
        case 'MANP': {
            BGSNote* password = 0;
            file->GetChunkData((unsigned int*)&password);
            reinterpret_cast<::InterfaceManager *>(this)->FUN_00500a20((::Tile *)(password));
            break;
        }
        case 'MAND':
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&Data), 4);
            break;
        case 'TXTI': {
            char* text = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
            reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(text), 0);
            TerminalMenuItem* item = new TerminalMenuItem;
            reinterpret_cast<::TextString *>(&(item->ResponseText))->FUN_004037f0(text, 0);
            AddMenuItem(item);
            current = item;
            break;
        }
        case 'MANR': {
            if (current)
            {
                char* text = (char*)_alloca(reinterpret_cast<::FUN_00401660_Class *>((file))->GetField25C());
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(text), 0);
                reinterpret_cast<::TextString *>(&(current->m_kMenuText))->FUN_004037f0(text, 0);
            }
            break;
        }
        case 'MANI': {
            if (current)
            {
                BGSNote* note = 0;
                file->GetChunkData((unsigned int*)&note);
                current->m_pNote = note;
            }
            break;
        }
        case 'MANT': {
            if (current)
            {
                BGSTerminal* menu = 0;
                file->GetChunkData((unsigned int*)&menu);
                current->m_pTerminal = menu;
            }
            break;
        }
        case 'MANA':
            if (current)
                reinterpret_cast<::fnv_00472890::FUN_00472890_cls *>((file))->FUN_00472890((char *)(void *)(&current->cFlags), 1);
            break;
        case 'ADTC':
            if (current)
                current->Conditions.Load(file);
            break;
        }
        if (!file->NextChunk())
            break;
    }
    return true;
}

// Resolves the terminal's password and each menu item's note/submenu forms, runs their InitItem scripts and conditions, and warns on lookup or script errors.
// @fnv 0x004ffcb0
void BGSTerminal::InitItem()
{
    int count;
    if (reinterpret_cast<::TESForm *>((void *)this)->GetInitialized())
        return;
    reinterpret_cast<::FUN_00510770_shell *>(this)->FUN_00510770();
    unsigned int formID = (unsigned int)(std::uintptr_t)pPassword;
    if (formID)
    {
        ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
        pPassword = dynamic_cast<BGSNote*>(::FUN_004839c0(formID));
        if (!pPassword)
            ::FUN_005b5e40();
    }
    count = 0;
    BSSimpleList<TerminalMenuItem*>* pList = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::FUN_00461150_shell *>(this)->FUN_00461150()));
    while (pList && !pList->IsEmpty())
    {
        TerminalMenuItem* item = (pList->item);
        pList = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::Callees *>((pList))->FUN_00726070()));
        if (item->m_pNote)
        {
            formID = (unsigned int)(std::uintptr_t)item->m_pNote;
            ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
            item->m_pNote = dynamic_cast<BGSNote*>(::FUN_004839c0(formID));
            if (!item->m_pNote)
                ::FUN_005b5e40();
        }
        if (item->m_pTerminal)
        {
            formID = (unsigned int)(std::uintptr_t)item->m_pTerminal;
            ::ResolveFormID((unsigned int *)&(formID), GetFile(-1));
            item->m_pTerminal = dynamic_cast<BGSTerminal*>(::FUN_004839c0(formID));
            if (!item->m_pTerminal)
                ::FUN_005b5e40();
        }
        struct
        {
            int errors;
            int previous;
        } errors;
        errors.previous = ::FUN_0046e8a0();
        ::FUN_0043b2b0(true);
        ::FUN_004fffe0(0);
        reinterpret_cast<::Scr *>(&(item->m_kScript))->FUN_005ab400(this);
        ::FUN_0043b2b0(false);
        errors.errors = ::FUN_0046e8a0();
        ::FUN_004fffe0(errors.previous);
        if (errors.errors)
            ::FUN_005b5e40(
                );
        errors.previous = ::FUN_0046e8a0();
        ::FUN_0043b2b0(true);
        ::FUN_004fffe0(0);
        item->Conditions.InitItem(this);
        ::FUN_0043b2b0(false);
        errors.errors = ::FUN_0046e8a0();
        ::FUN_004fffe0(errors.previous);
        if (errors.errors)
            ::FUN_005b5e40(
                );
        ++count;
    }
    SetInitializationState(true);
}

// @fnv 0x004ffc50
void BGSTerminal::ResetFormData()
{
    TESObjectACTI::ResetFormData();
    pPassword = 0;
    memset(&Data, 0, sizeof(Data));
}

// Returns true if note is non-null and present in the notes list.
// @fnv 0x00966c10
bool PlayerCharacter::HasNote(BGSNote* note)
{
    return note && reinterpret_cast<::RefList *>(&(notes))->FUN_005f65d0((void **)&(note));
}

struct BaseExtraList
{
};

// @fnv 0x00501a10
void __cdecl FUN_00501a10(Script* apScript)
{
    if (apScript)
        reinterpret_cast<::fnv_00422c20::FUN_0042dec0_shell *>((reinterpret_cast<BaseExtraList*>(((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apScript))->FUN_005d43c0())))))->RemoveExtra(0x50);
}

struct TESObjectREFR
{
};

// @fnv 0x005012c0
bool __cdecl FUN_005012c0(TESObjectREFR* apRef)
{
    bool bretval = false;
    if (apRef)
    {
        TESObjectREFR* plinkedref = reinterpret_cast<::FUN_00569b80_shell *>((apRef))->FUN_00569b80();
        if (plinkedref)
        {
            if (reinterpret_cast<::FUN_00568680_shell *>((plinkedref))->FUN_00568680())
            {
                if (!reinterpret_cast<::FUN_00568260_shell *>((plinkedref))->FUN_00568260(true))
                    bretval = true;
            }
        }
    }
    return bretval;
}

struct FUN_005015d0_shell
{
    unsigned char m_a5;
    bool FUN_005015d0();
};

// @fnv 0x005015d0
bool FUN_005015d0_shell::FUN_005015d0()
{
    return ((unsigned char*)this)[0xa5] & 2;
}

struct BSSimpleList_REF
{
};

struct FUN_00501b40_shell
{
    void FUN_00501b40(Script* a1);
};

// @fnv 0x00501b40
void FUN_00501b40_shell::FUN_00501b40(Script* pScript)
{
    if (pScript)
    {
        if (reinterpret_cast<::FUN_005015d0_shell *>(this)->FUN_005015d0())
            reinterpret_cast<::fnv_0041bf80::FUN_0041bf80_Class *>((((BSSimpleList_REF*)((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((pScript))->FUN_005d43c0())))))->FUN_0041bf80(-1);
        else
            reinterpret_cast<::fnv_0041bf80::FUN_0041bf80_Class *>((((BSSimpleList_REF*)((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((pScript))->FUN_005d43c0())))))->FUN_0041bf80(-2);
    }
}

struct FUN_00511860_shell
{
    void FUN_00511860(void* apSaveGameBuffer);
};

void FUN_00511860_shell::FUN_00511860(void* apSaveGameBuffer)
{}

struct FUN_00501b90_shell : FUN_00511860_shell
{
    void FUN_00501b90(void* apSaveGameBuffer);
};

// @fnv 0x00501b90
void FUN_00501b90_shell::FUN_00501b90(void* apSaveGameBuffer)
{
    reinterpret_cast<::FUN_00511860_holder *>((this))->FUN_00511860((::BGSSaveFormBuffer *)(apSaveGameBuffer));
}

struct FUN_00501270_shell : public TESForm
{
    int FUN_005011a0(TESObjectREFR* apRef);
    unsigned int FUN_00501270(TESObjectREFR* apRef);
};
// @fnv 0x00501270
unsigned int FUN_00501270_shell::FUN_00501270(TESObjectREFR* apRef)
{
    int ilockval;
    ilockval = FUN_005011a0(apRef);
    ilockval <<= 1;
    ilockval += ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>(this)->FUN_0084e3a0())) & 1;
    ilockval += 4;
    if (ilockval > 12)
        ilockval = 12;
    return ilockval;
}

struct TermHack
{
    float FUN_005017a0(TESObjectREFR* apItemActivated);
    bool IsSkillSufficient(TESObjectREFR* apItemActivated, float afSkill);
};
// Returns whether the skill value returned by FUN_005017a0 for the activated reference is less than or equal to afSkill.
// @fnv 0x00501760
bool TermHack::IsSkillSufficient(TESObjectREFR* apItemActivated, float afSkill)
{
    return FUN_005017a0(apItemActivated) <= afSkill;
}

struct Dummy0041BF50
{
};
// Returns true if apRef is non-null and the state byte from its referenced object list has bit 0x80 set.
// @fnv 0x00501870
bool __cdecl FUN_00501870(TESObjectREFR* apRef)
{
    bool bretval;
    unsigned char cstate;
    bretval = false;
    if (apRef)
    {
        cstate = reinterpret_cast<::FUN_0041bf50_class *>((((Dummy0041BF50*)((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((((Script*)apRef)))->FUN_005d43c0())))))->FUN_0041bf50();
        if (cstate & 0x80)
            bretval = true;
    }
    return bretval;
}

struct FUN_0041c060_Cls
{
};
struct FUN_00501a30_shell
{
    unsigned char _pad[0xA4];
    char _mA4;
    int FUN_00501a30(Script* apScript);
};
// @fnv 0x00501a30
int FUN_00501a30_shell::FUN_00501a30(Script* apScript)
{
    char c = -1;
    if (apScript)
    {
        c = reinterpret_cast<::fnv_0041c060::MyThis *>((((FUN_0041c060_Cls*)((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apScript))->FUN_005d43c0())))))->FUN_0041c060();
    }
    if (c < 0)
    {
        c = _mA4;
    }
    return c;
}

struct FUN_00501a80_shell : FUN_005015d0_shell
{
    void FUN_00501a80(Script* a1, int a2);
};
// @fnv 0x00501a80
void FUN_00501a80_shell::FUN_00501a80(Script* apScript, int aiValue)
{
    if (apScript)
    {
        if (aiValue == ((unsigned char*)this)[0xA4] && !FUN_005015d0())
            reinterpret_cast<::fnv_0041bf80::FUN_0041bf80_Class *>((((BSSimpleList_REF*)(((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apScript))->FUN_005d43c0()))))))->FUN_0041bf80(-1);
        else
            reinterpret_cast<::fnv_0041bf80::FUN_0041bf80_Class *>((((BSSimpleList_REF*)(((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apScript))->FUN_005d43c0()))))))->FUN_0041bf80((unsigned char)aiValue);
    }
}

struct FUN_0041c060_shell
{
};
struct FUN_00501ae0_shell : FUN_005015d0_shell
{
    bool FUN_00501ae0(TESObjectREFR* apRef);
};
// @fnv 0x00501ae0
bool FUN_00501ae0_shell::FUN_00501ae0(TESObjectREFR* apRef)
{
    bool bunlocked;
    bunlocked = FUN_005015d0();
    if (apRef)
    {
        char clock;
        clock = reinterpret_cast<::fnv_0041c060::MyThis *>((((FUN_0041c060_shell*)((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((((Script*)apRef)))->FUN_005d43c0())))))->FUN_0041c060();
        if (clock == -2)
            bunlocked = true;
        else if (clock != -1)
            bunlocked = false;
    }
    return bunlocked;
}

struct FormChangeMask
{
    int m_flags;
    FormChangeMask();
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    virtual unsigned char GetVersion();
    FormChangeMask GetChangeFlags(unsigned int);
};
struct BaseStub501bb0
{
};
struct Host501bb0 : BaseStub501bb0
{
    void FUN_00501bb0(BGSLoadFormBuffer*);
};
// @fnv 0x00501bb0
void Host501bb0::FUN_00501bb0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned char ucTempData;
    reinterpret_cast<::S_005118c0 *>(this)->FUN_005118c0((::FUN_00428110_cls *)(apLoadGameBuffer));
    if (reinterpret_cast<::fnv_004280f0::FUN_004280f0_shell *>((void *)&(const ::FormChangeMask &)(apLoadGameBuffer->GetChangeFlags(0x80000000)))->FUN_004280f0(0x80000000))
    {
        if (apLoadGameBuffer->GetVersion() < 13)
        {
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&ucTempData), 1);
        }
    }
}

struct FUN_00501250_shell
{
    bool IsFlagSet();
};
// @fnv 0x00501250
bool FUN_00501250_shell::IsFlagSet()
{
    return (*(unsigned char*)((char*)this + 0xa5) & 1) ? true : false;
}

struct Setting_S
{
};
struct GlobalObject_0044f440 : Setting_S
{
};

// @fnv 0x005017a0
float TermHack::FUN_005017a0(TESObjectREFR* apItemActivated)
{
    switch (((FUN_00501270_shell*)this)->FUN_005011a0(apItemActivated))
    {
    case 0:
        return *((float *)&(::FUN_00403e20((float *)&(::g_011d961c))));
    case 1:
        return *((float *)&(::FUN_00403e20((float *)&(::g_011d9660))));
    case 2:
        return *((float *)&(::FUN_00403e20((float *)&(::g_011d9684))));
    case 3:
        return *((float *)&(::FUN_00403e20((float *)&(::g_011d95d4))));
    case 4:
        return *((float *)&(::FUN_00403e20((float *)&(::g_011d9640))));
    default:
        return 3.402823466e+38F;
    }
}


// Checks the script's referenced object state: returns false for state 0, compares a perk modifier against _gModifierZero for state 1, and true otherwise.
// @fnv 0x00501990
bool __cdecl FUN_00501990(Script* apScript)
{
    if (apScript)
    {
        unsigned char cstate = reinterpret_cast<::FUN_0041bf50_class *>((reinterpret_cast<Dummy0041BF50*>(((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apScript))->FUN_005d43c0())))))->FUN_0041bf50();
        switch (cstate & 0x7f)
        {
        case 0:
            return false;
        case 1: {
            float fPerkModifier = 0.0f;
            ::ApplyPerkModifiers(0x14, (::Actor *)((*reinterpret_cast<void * *>(&::_g_thePlayer))), &fPerkModifier);
            return fPerkModifier == ::_DAT_01012060;
        }
        default:
            return true;
        }
    }
    return false;
}

struct ListProxy
{
};
struct VProxy
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18(unsigned int a1);
};
// @fnv 0x00501930
void __cdecl SetScriptLockState(Script* apRef, bool abLock)
{
    unsigned char cstate;
    if (apRef)
    {
        cstate = reinterpret_cast<::FUN_0041bf50_class *>((((ListProxy*)((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apRef))->FUN_005d43c0())))))->FUN_0041bf50();
        if (abLock)
            cstate++;
        else
            cstate = 0;
        reinterpret_cast<::fnv_0041be10::FUN_0041be10_Class *>((((ListProxy*)((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apRef))->FUN_005d43c0())))))->SetExtraState(cstate);
        ((VProxy*)apRef)->v18(0x80000000);
    }
}

class ScriptLocals;

struct ExtraDataList
{
};

class ScriptLocals;
class TESObjectREFR;
struct FUN_005ac1e0_shell
{
public:
    bool FUN_005ac1e0(::TESObjectREFR *, ::ScriptLocals *, ::TESObjectREFR *, bool);
};

struct FUN_00501830_shell
{
    unsigned char _pad[0x10];
    Script m_kScript;

    void FUN_00501830(Script* apScript);
};

// @fnv 0x00501830
void FUN_00501830_shell::FUN_00501830(Script* apScript)
{
    ((::ScriptHeaderData *)(reinterpret_cast<::BGSCameraPath *>(&(m_kScript))->GetConditions()))->quest = false;

    reinterpret_cast<FUN_005ac1e0_shell*>(&m_kScript)->FUN_005ac1e0(reinterpret_cast<TESObjectREFR*>(apScript),
                       reinterpret_cast<::FUN_00418830_shell *>((reinterpret_cast<ExtraDataList*>(((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apScript))->FUN_005d43c0())))))->FUN_00418830(), (::TESObjectREFR *)(::ScriptLocals *)(0),
                       true);
}

// @fnv 0x005018b0
void FUN_005018b0(Script* apRef, bool abVal)
{
    unsigned char cstate;
    unsigned char ucNewState;
    if (apRef != 0)
    {
        cstate = reinterpret_cast<::FUN_0041bf50_class *>((((ListProxy*)((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apRef))->FUN_005d43c0())))))->FUN_0041bf50();
        if (abVal)
        {
            cstate = cstate | 0x80;
            ucNewState = cstate;
        }
        else
        {
            cstate = cstate & 0xffffff7f;
            ucNewState = cstate;
        }
        reinterpret_cast<::fnv_0041be10::FUN_0041be10_Class *>((((ListProxy*)((::BSSimpleList< ::ScriptReferencedObject *> *)(reinterpret_cast<::FUN_005d43c0_ *>((apRef))->FUN_005d43c0())))))->SetExtraState(cstate);
        ((VProxy*)apRef)->v18(0x80000000);
    }
}


class B408A80String
{
  public:
    int FUN_00408a80(const char* pcOther, bool bIgnoreCase);

    char* m_pcData;
    unsigned short m_usLength;
    unsigned short m_usMaxLength;
};

// Compares this string's C string with pcOther, case-insensitively when bIgnoreCase is set, returning 0 when both are null.
// @fnv 0x00408a80
int B408A80String::FUN_00408a80(const char* pcOther, bool bIgnoreCase)
{
    int iResult;
    if (pcOther && ((const char *)(::FUN_00559450((int *)this))))
        iResult = bIgnoreCase ? FUN_00404dc0(((const char *)(::FUN_00559450((int *)this))), pcOther) : FUN_00408b20(((const char *)(::FUN_00559450((int *)this))), pcOther);
    else if (!pcOther && !((const char *)(::FUN_00559450((int *)this))))
        iResult = 0;
    else
        iResult = pcOther ? -1 : 1;
    return iResult;
}

struct TerminalCleanup
{
    void FUN_004ffc90();
};

struct TerminalPasswordAccess
{
};
struct BSStringCopy
{
    BSStringCopy& operator=(const BSStringCopy& arString);
};
struct ScriptCopy
{
};
struct ConditionCopy
{
};

struct BGSTerminalEx : BGSTerminal
{
    void CopyFromTerminal(TESForm* apForm);
};

struct TerminalStringCmp
{
};
struct TerminalScriptCmp
{
};
struct TerminalConditionCmp
{
};
struct TerminalMenuList
{
    int GetSize();
};

struct TerminalCompare : public BGSTerminal
{
    bool IsDifferentFrom(TESForm* apForm);
};

// @fnv 0x00500e60
bool TerminalCompare::IsDifferentFrom(TESForm* apForm)
{
    BGSTerminal* pTerminal = dynamic_cast<BGSTerminal*>(apForm);
    if (!pTerminal)
        return true;
    if (((void *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())) != ((void *)(reinterpret_cast<::MagicProjectile *>((static_cast<TerminalCompare*>(pTerminal)))->FUN_004fd400())))
        return true;
    if (memcmp(&Data, &pTerminal->Data, sizeof(TerminalCompareData)))
        return true;

    BSSimpleList<TerminalMenuItem*>* pThisIter5 = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::FUN_00461150_shell *>(this)->FUN_00461150()));
    BSSimpleList<TerminalMenuItem*>* pOtherIter = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::FUN_00461150_shell *>((pTerminal))->FUN_00461150()));
    if (((TerminalMenuList*)pThisIter5)->GetSize() != ((TerminalMenuList*)pOtherIter)->GetSize())
        return true;

    while (pOtherIter && !pOtherIter->IsEmpty() && pThisIter5 && !pThisIter5->IsEmpty())
    {
        TerminalMenuItem* pOtherItem = (pOtherIter->item);
        TerminalMenuItem* pThisItem5 = (pThisIter5->item);
        if (reinterpret_cast<::Dummy00501c30 *>((((TerminalStringCmp*)&pThisItem5->ResponseText)))->FUN_00501c30((const char *)(const ::BSStringT<char> *)(&pOtherItem->ResponseText)))
            return true;
        if (reinterpret_cast<::Dummy00501c30 *>((((TerminalStringCmp*)&pThisItem5->m_kMenuText)))->FUN_00501c30((const char *)(const ::BSStringT<char> *)(&pOtherItem->m_kMenuText)))
            return true;
        if (reinterpret_cast<::ScriptCompareOwner *>((((TerminalScriptCmp*)&pThisItem5->m_kScript)))->IsDifferentFrom(&pOtherItem->m_kScript))
            return true;
        if (reinterpret_cast<::PerkEntryConditionSet *>((((TerminalConditionCmp*)&pThisItem5->Conditions)))->Compare(&pOtherItem->Conditions))
            return true;
        if (pThisItem5->m_pNote != pOtherItem->m_pNote)
            return true;
        if (pThisItem5->m_pTerminal != pOtherItem->m_pTerminal)
            return true;
        if (pThisItem5->cFlags != pOtherItem->cFlags)
            return true;
        pOtherIter = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::Callees *>((pOtherIter))->FUN_00726070()));
        pThisIter5 = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::Callees *>((pThisIter5))->FUN_00726070()));
    }

    if (reinterpret_cast<::ACTIView *>(this)->FUN_005111e0((::TESForm *)(pTerminal)))
        return true;
    return false;
}

struct FUN_00501050_ref
{
};

struct FUN_00501050_sub
{
    bool FUN_008256d0();
    void FUN_0063f7b0();
};

class FUN_00501050_cls
{
  public:
    unsigned char unk00[0x98];
    FUN_00501050_sub sub;
    void FUN_00501050();
};
// @fnv 0x004ffc90
void TerminalCleanup::FUN_004ffc90()
{
    reinterpret_cast<::TESForm *>(this)->ClearData();
    reinterpret_cast<::FUN_00501050_cls *>(this)->FUN_00501050();
}
// @fnv 0x00500cb0
void BGSTerminalEx::CopyFromTerminal(TESForm* apForm)
{
    BGSTerminal* pTerminal = dynamic_cast<BGSTerminal*>(apForm);
    if (!pTerminal)
        return;
    BSSimpleList<TerminalMenuItem*>* pIter = 0;
    reinterpret_cast<::InterfaceManager *>(this)->FUN_00500a20((::Tile *)(::BGSNote *)(((::BGSNote *)(reinterpret_cast<::MagicProjectile *>((((TerminalPasswordAccess*)pTerminal)))->FUN_004fd400()))));
    memcpy(&Data, &pTerminal->Data, sizeof(Data));
    reinterpret_cast<::FUN_00501050_cls *>(this)->FUN_00501050();
    pIter = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::FUN_00461150_shell *>((pTerminal))->FUN_00461150()));
    while (pIter && !pIter->IsEmpty())
    {
        TerminalMenuItem* pSrc = (pIter->item);
        pIter = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        TerminalMenuItem* pItem = new TerminalMenuItem;
        reinterpret_cast<::FUN_00501c10_cls *>((void *)&(const ::BSStringCopy &)(*(BSStringCopy*)&pItem->ResponseText))->CallAndReturnSelf((std::intptr_t)&(*(BSStringCopy*)&pSrc->ResponseText));
        reinterpret_cast<::FUN_00501c10_cls *>((void *)&(const ::BSStringCopy &)(*(BSStringCopy*)&pItem->m_kMenuText))->CallAndReturnSelf((std::intptr_t)&(*(BSStringCopy*)&pSrc->m_kMenuText));
        pItem->m_pNote = pSrc->m_pNote;
        pItem->m_pTerminal = pSrc->m_pTerminal;
        pItem->cFlags = pSrc->cFlags;
        reinterpret_cast<::FUN_005aa420_shell *>((((ScriptCopy*)&pItem->m_kScript)))->CopyFromScript(&pSrc->m_kScript);
        reinterpret_cast<::FUN_00680a70_shell *>((((ConditionCopy*)&pItem->Conditions)))->CopyConditions(&pSrc->Conditions, (::PerkEntryConditionSet *)(false));
        AddMenuItem(pItem);
    }
    reinterpret_cast<::ActiV511 *>(this)->FUN_00511120(pTerminal);
}

// @fnv 0x00501050
void FUN_00501050_cls::FUN_00501050()
{
    while (sub.FUN_008256d0() == 0)
    {
        FUN_00501050_ref* a = *((::FUN_00501050_ref **)((void *)&(sub)));
        sub.FUN_0063f7b0();
        FUN_00501050_ref* tmp = a;
        FUN_00501050_ref* b2 = tmp;
        (b2 != 0 ? ((std::intptr_t)(reinterpret_cast<::FUN_005010c0_class *>((b2))->FUN_005010c0(1))) : 0);
    }
}

struct SaveForm
{
};
struct SaveFullName : TESFullName
{
};
struct SaveModel : TESModelTextureSwap
{
};
struct SaveScriptable : TESScriptableForm
{
};
struct S_00477f20 : BGSDestructibleObjectForm
{
};
struct SaveDescription : TESDescription
{
};
struct SaveScript
{
};
struct TESConditionSave
{
};
struct SaveGameString
{
    operator const char*() const;
};
struct ActivatorSoundFields : TESBoundAnimObject,
                              TESFullName,
                              TESModelTextureSwap,
                              TESScriptableForm,
                              BGSDestructibleObjectForm
{
    unsigned int unk70;
    TESSound* loopingSound;
};
struct SaveSound
{
};
struct SaveActivator : TESBoundAnimObject, SaveFullName, SaveModel, SaveScriptable, S_00477f20
{
    unsigned int unk70;
    TESSound* loopingSound;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
};
struct TerminalSave : SaveActivator, SaveDescription
{
    BSSimpleList<TerminalMenuItem*> m_kMenuItems;
    BGSNote* pPassword;
    TerminalCompareData Data;
    void FUN_00500a40();
};

// @fnv 0x00500a40
void TerminalSave::FUN_00500a40()
{
    reinterpret_cast<::fnv_004855a0::ArrSI *>((reinterpret_cast<SaveForm*>(this)))->FUN_004855a0();
    reinterpret_cast<::FUN_00487010_shell *>(this)->FUN_00487010();
    reinterpret_cast<::FUN_0048a520_shell *>(this)->ProcessAndFreeData(0x4c444f4d, 0x54444f4d, 0x53444f4d);
    reinterpret_cast<::S_0048cca0 *>(this)->FUN_0048cca0();
    reinterpret_cast<::FUN_00477f20_shell *>(this)->FUN_00477f20();
    reinterpret_cast<::FUN_00482cb0_shell *>(this)->FUN_00482cb0();
    if (loopingSound)
    {
        unsigned int soundID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((reinterpret_cast<SaveSound*>(loopingSound)))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e53, soundID);
    }
    if (((::BGSNote *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400())))
    {
        unsigned int passwordID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::BGSNote *)(reinterpret_cast<::MagicProjectile *>(this)->FUN_004fd400()))))->FUN_0084e3a0()));
        ::FUN_00485910(0x4d414e50, passwordID);
    }
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::TESForm *>((reinterpret_cast<TerminalCleanup*>(&Data)))->ClearData();
    ::AppendChunk(0x4d414e44, &Data, 4);
    if (((bool)(::FUN_00401500())))
        reinterpret_cast<::TESForm *>((reinterpret_cast<TerminalCleanup*>(&Data)))->ClearData();
    BSSimpleList<TerminalMenuItem*>* pMenuNode = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::FUN_00461150_shell *>(this)->FUN_00461150()));
    while (pMenuNode && !pMenuNode->IsEmpty())
    {
        TerminalMenuItem* item = (pMenuNode->item);
        pMenuNode = ((::BSSimpleList< ::TerminalMenuItem *> *)(reinterpret_cast<::Callees *>((pMenuNode))->FUN_00726070()));
        if (static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->ResponseText)))
            ::FUN_004856f0(
                (void *)(0x54585449), (void *)(static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->ResponseText))),
                (void *)(::FUN_0044a670(static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->ResponseText))) + 1));
        else
            ::FUN_00485910(0x54585449, 0);
        if (static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->m_kMenuText)))
            ::FUN_004856f0(
                (void *)(0x4d414e52), (void *)(static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->m_kMenuText))),
                (void *)(::FUN_0044a670(static_cast<const char*>(*reinterpret_cast<SaveGameString*>(&item->m_kMenuText))) + 1));
        else
            ::FUN_00485910(0x4d414e52, 0);
        FUN_004858f0(0x4d414e41, item->cFlags);
        if (item->m_pNote)
        {
            unsigned int noteID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((item->m_pNote))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e49, noteID);
        }
        if (item->m_pTerminal)
        {
            unsigned int submenuID = ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((item->m_pTerminal))->FUN_0084e3a0()));
            ::FUN_00485910(0x4d414e54, submenuID);
        }
        reinterpret_cast<::FUN_005abe00 *>((reinterpret_cast<SaveScript*>(&item->m_kScript)))->ProcessHeader();
        reinterpret_cast<::FUN_00680910_shell *>((reinterpret_cast<TESConditionSave*>(&item->Conditions)))->ProcessItems();
    }
    reinterpret_cast<::Holder *>((reinterpret_cast<SaveForm*>(this)))->FUN_00485680();
}

struct Ref;
struct Form
{
    int Type();
};
struct Ref
{
};
struct Player
{
};
struct Open
{
    static int GetOpenState(Ref*);
};
struct Text
{
    char* data;
    unsigned short length, capacity;
    Text();
    ~Text();
    operator const char*() const;
};
struct Sound
{
    int id;
    int state;
    int flags;
    ~Sound();
};
struct Audio
{
    Sound GetSoundHandleByEditorID(const char*, unsigned int);
};
struct Setting
{
};
struct Activate
{
    virtual void Run(Ref*, Ref*);
};
struct Values
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual float Get(int);
};
struct OwnerActor
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
    Values values;
};
struct Faction
{
};
struct Terminal
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    Activate activation;
    bool ActivateTerminal(Ref*, Ref*, int, int, int);
};
// @fnv 0x00501310
bool Terminal::ActivateTerminal(Ref* target, Ref* user, int arg3, int arg4, int arg5)
{
    if (FUN_00709bc0())
    {
        return false;
    }
    else if (Open::GetOpenState(target) == 1)
    {
        activation.Run(target, user);
    }
    else if (user == (Ref*)(*reinterpret_cast<::Player * *>(&::_g_thePlayer)) && reinterpret_cast<::PlayerCharShell *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->GetTerminalAccessResult((::TESObjectREFR *)(target)) == 4)
    {
        Text message;
        ::FUN_00406f60((::FUN_00406f90_this *)(::Text *)(&message), ((const char *)(reinterpret_cast<::DownloadableContentManager *>(&((*reinterpret_cast<::Setting *>(&::g_011c8394))))->IsDLCAvailable())), ::ActorValue::GetActorValueName((::ActorValue::Index)(40)), (int)::InventoryStackRecord::RoundToNearestStep(reinterpret_cast<::TermHack *>(this)->FUN_005017a0((::TESObjectREFR *)(target)), 1.0f));
        ::DispatchMessageToSink((const char *)(message.data), 0, (const char *)("Interface\\Icons\\Message Icons\\glow_message_vaultboy_angry.dds"), (const char *)(0), 2.0f, false);
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::Sound &)(((::Audio *)(::FUN_00453a70()))->GetSoundHandleByEditorID("UIPopUpMessageGeneral", 0x121)))->FUN_00ad8830(false);
    }
    else if (user == (Ref*)(*reinterpret_cast<::Player * *>(&::_g_thePlayer)) && ::FUN_005012c0((::TESObjectREFR *)(target)))
    {
        ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d4810))))->GetMenuTitle()))), 0, (const char *)(0), (const char *)(0), 2.0f, false);
        return false;
    }
    else
    {
        Ref* actor = user;
        if (((::Form *)(reinterpret_cast<::OwnerLookupView *>((target))->FUN_00567790())) && !reinterpret_cast<::OwnershipReferenceView *>((target))->FUN_005785e0((::Actor *)(actor), true) && !reinterpret_cast<::FUN_005015d0_shell *>(this)->FUN_005015d0())
        {
            bool crime = false;
            Form* owner = ((::Form *)(reinterpret_cast<::OwnerLookupView *>((target))->FUN_00567790()));
            int unused = 0;
            if (owner->Type() == 8)
            {
                Faction* faction = (Faction*)owner;
                if (!reinterpret_cast<::FUN_0047d7c0_Class *>((faction))->FUN_0047d7c0())
                    crime = true;
            }
            else
            {
                OwnerActor* pOwnerActor = (OwnerActor*)owner;
                if (pOwnerActor)
                {
                    unsigned int rank = ((unsigned int)(::fnv_0047e040::FUN_0047e040(pOwnerActor->values.Get(23))));
                    if (rank != 2 && rank != 4)
                        crime = true;
                }
            }
            if (crime)
                reinterpret_cast<::KarmaActor *>(((*reinterpret_cast<::Player * *>(&::_g_thePlayer))))->FUN_0094fd30((int)*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::Setting *>(&::originalRuntimeFloatSetting282)))))));
        }
        ::FUN_0047a560((::TESObjectREFR *)(target), (::TESObjectREFR *)(user), (::BGSOpenCloseForm *)(0));
    }
    return true;
}

struct TermFormBase
{
    virtual void Vf00();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
};
struct TermFullName
{
    virtual void Vf30();
    int unk04, unk08;
};
struct TermModel
{
    virtual void Vf3c();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct TermScriptable
{
    virtual void Vf5c();
    int unk04, unk08;
};
struct TermDestructible
{
    virtual void Vf68();
    int unk04;
};
struct TermOpenClose
{
    virtual void Vf70();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
};
struct TermActivator : TermFormBase, TermFullName, TermModel, TermScriptable, TermDestructible, TermOpenClose
{
    TermActivator();
    ~TermActivator();
};
struct TermDescription
{
    virtual void Vf90();
    unsigned int text;
    TermDescription();
};
struct TermMenuList
{
    void* item;
    TermMenuList* next;
    TermMenuList();
    ~TermMenuList();
};

struct FUN_004ffaa0 : TermActivator, TermDescription
{
    TermMenuList m_kMenuItems;
    void* pPassword;
    unsigned int Data;
    FUN_004ffaa0();
};

// @fnv 0x004ffaa0
FUN_004ffaa0::FUN_004ffaa0()
{
    reinterpret_cast<::FUN_004f15a0_shell *>(this)->FUN_004f15a0(0x17);
    reinterpret_cast<::BGSTerminal *>(this)->ResetFormData();
}

struct RefLevel
{
};

// Returns the initial result, optionally adding a scaled level value and capping it at 4 when the flag is set.
// @fnv 0x005011a0
int FUN_00501270_shell::FUN_005011a0(TESObjectREFR* apRef)
{
    unsigned int result = reinterpret_cast<FUN_00501a30_shell*>(this)->FUN_00501a30(reinterpret_cast<Script*>(apRef));
    if (reinterpret_cast<FUN_00501250_shell*>(this)->IsFlagSet())
    {
        unsigned int level =
            apRef ? reinterpret_cast<::fnv_00567e10::FUN_00567e10_shell *>((reinterpret_cast<RefLevel*>(apRef)))->FUN_00567e10(false) : reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<void * *>(&::_g_thePlayer))))->FUN_0087f9f0();
        result += (unsigned int)((double)level * *((float *)&(::FUN_00403e20(&(*reinterpret_cast<float *>(&::originalRuntimeFloatSetting33))))));
        if (result > 4)
            result = 4;
    }
    return result;
}

#include "generated/data/fallout_shared/bgsterminal.inc"
