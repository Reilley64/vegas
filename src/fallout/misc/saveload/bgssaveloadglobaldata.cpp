// fallout/misc/saveload/bgssaveloadglobaldata.cpp: SaveGameLoader (23 functions)

#include <new>
#include "fnv/decl/ActorMover.h"
#include "fnv/decl/BGSReconstructFormsInAllFilesMap.h"
#include "fnv/decl/BGSTerrainManager.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/Candidate.h"
#include "fnv/decl/CombatGroup532.h"
#include "fnv/decl/CombatThreatMap.h"
#include "fnv/decl/EffectSetting.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_004534f0_shell.h"
#include "fnv/decl/FUN_004539a0_cls.h"
#include "fnv/decl/FUN_00459840_shell.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00461330_shell.h"
#include "fnv/decl/FUN_00461c20_Holder.h"
#include "fnv/decl/FUN_004623f0_shell.h"
#include "fnv/decl/FUN_0046dce0_class.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_00545cb0_shell.h"
#include "fnv/decl/FUN_00549580_shell.h"
#include "fnv/decl/FUN_00586260_shell.h"
#include "fnv/decl/FUN_0061cc40_shell.h"
#include "fnv/decl/FUN_0063eb70_shell.h"
#include "fnv/decl/FUN_0063f790_shell.h"
#include "fnv/decl/FUN_006694c0_shell.h"
#include "fnv/decl/FUN_00846330_shell.h"
#include "fnv/decl/FUN_0084d310_class.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00853570_shell.h"
#include "fnv/decl/FUN_00864520_shell.h"
#include "fnv/decl/FUN_00864740_shell.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00865f20_shell.h"
#include "fnv/decl/FUN_00865ff0_shell.h"
#include "fnv/decl/FUN_0095f530_shell.h"
#include "fnv/decl/FUN_0096a400_cls.h"
#include "fnv/decl/FUN_00975930_shell.h"
#include "fnv/decl/FUN_00975b60_shell.h"
#include "fnv/decl/FakeGame.h"
#include "fnv/decl/GridHolder.h"
#include "fnv/decl/Holder0084.h"
#include "fnv/decl/ListReader.h"
#include "fnv/decl/LoadingMenu.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/NiTMap_S.h"
#include "fnv/decl/ReconstructSession.h"
#include "fnv/decl/S457d70.h"
#include "fnv/decl/SaveLoadGame_8495d0.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESActorBaseData.h"
#include "fnv/decl/TESGridOwner.h"
#include "fnv/decl/TESObjectTREE.h"
#include "fnv/decl/TESRecipe.h"
#include "fnv/decl/TESTopicInfo.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/WS458200_Shell.h"
#include "fnv/decl/WorldCellLoader.h"
#include "fnv/decl/WorldQuery.h"
#include "fnv/decl/fnv_00454450__ReloadManager.h"
#include "fnv/decl/fnv_00455600__FUN_00455600_shell.h"
#include "fnv/decl/fnv_00459750__FUN_00459750_cls.h"
#include "fnv/decl/fnv_0054ca90__Cell.h"
#include "fnv/decl/fnv_00570f00__FUN_00570f00_shell.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_007af430__FUN_007af430_shell.h"
#include "fnv/decl/fnv_00843630__FUN_00843630_shell.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00864a60__FUN_00864a60_cls.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0093db60__PlayerCenterOnCell.h"
#include "fnv/decl/fnv_009932d0__FUN_009932d0_shell.h"
#include "fnv/decl/fnv_00993440__FUN_00993440_shell.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0045a000.h"
#include "fnv/symbols_00461000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004d5000.h"
#include "fnv/symbols_004d6000.h"
#include "fnv/symbols_0066e000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_0078d000.h"
#include "fnv/symbols_00836000.h"
#include "fnv/symbols_00845000.h"
#include "fnv/symbols_0084c000.h"
#include "fnv/symbols_00868000.h"
#include "fnv/symbols_00c45000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f1000.h"
#include "bgssaveloadglobaldata_packet.h"
class BGSLoadGameBuffer;
class TESObjectCELL;

class ProcessLists
{
  public:
    void InitLoadGame(BGSLoadGameBuffer* buffer);
    void Revert(BGSLoadGameBuffer*);
};

class TESObjectCELL;
class TESWorldSpace
{
  public:
    TESObjectCELL* LookupCellByEditorID(const char* editorID);
public:
    ::TESObjectCELL *GetCellAtGridPosition(int, int);
};


class ActorCause
{
  public:
    static void SaveActorCauses(BGSLoadGameBuffer* buffer);
    static void ClearActorCauseList(BGSLoadGameBuffer*);
};

class FalloutRadio
{
  public:
    static void InitLoadGame(BGSLoadGameBuffer* buffer);
};

class SaveGameLoader
{
  public:
    static void UnloadGameData();
    static bool LoadFormType(unsigned int, BGSLoadGameBuffer*);
    static void LoadEffects(BGSLoadGameBuffer*);
    static bool LoadFormRange(unsigned int, BGSLoadGameBuffer*, bool);
    static bool LoadGlobalDataRange(unsigned int, BGSLoadGameBuffer*);
};


// Dispatches loading of global game data by type to the matching loader, logging an error for unknown types.
// @fnv 0x0084c190
bool SaveGameLoader::LoadFormType(unsigned int type, BGSLoadGameBuffer* buffer)
{
    switch (type)
    {
    case 1:
        return false;
    case 2:
        reinterpret_cast<::fnv_00459750::FUN_00459750_cls *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->ProcessItems((unsigned int)(buffer));
        return true;
    case 3:
        return false;
    case 4:
        return false;
    case 5:
        ((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)->ApplyLoadBuffer(buffer);
        return true;
    case 6:
        ::fnv_00706a90::FUN_00706a90();
        return true;
    case 7:
        return false;
    case 0:
        return false;
    case 8:
        return false;
    case 9:
        return false;
    case 10:
        ::UpdateRadioReceivers((int)(buffer));
        return true;
    case 11:
        return false;
    case 1000:
        return false;
    default:
        ::FUN_00845cc0("DEFAULT: Unknown global data type %i in FinishLoadGlobalData()", type);
        return false;
    }
}

// @fnv 0x0084d070
void SaveGameLoader::LoadEffects(BGSLoadGameBuffer* buffer)
{
    unsigned int count = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((buffer))->FUN_00864a60();
    for (unsigned int i = 0; i < count; ++i)
    {
        float strength = 0.0f;
        reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&strength), 4);
        TESImageSpaceModifier* modifier;
        {
            float age = 0.0f;
            if (buffer->GetVersion() >= 14)
                reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&age), 4);
            modifier = 0;
            modifier = dynamic_cast<TESImageSpaceModifier*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
            if (modifier)
            {
                ImageSpaceModifierInstanceForm* instance =
                    ImageSpaceModifierInstanceForm::Trigger(modifier, strength, 0);
                if (instance)
                    reinterpret_cast<::FUN_006694c0_shell *>((instance))->SetPad5(::fnv_00563f30::DAT_011c3c08 - age);
            }
        }
    }
}

// Dispatches on a global data type to revert the matching subsystem from the load buffer, returning false for unsupported types.
// @fnv 0x0084c330
bool SaveGameLoader::LoadFormRange(unsigned int type, BGSLoadGameBuffer* buffer, bool globals)
{
    switch (type)
    {
    case 1:
        return false;
    case 2:
        reinterpret_cast<::FUN_00459840_shell *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00459840((unsigned int)(buffer));
        return true;
    case 3:
        if (globals)
        {
            ::fnv_0084ced0::ReconstructAllGlobals();
            return true;
        }
        return false;
    case 4:
        reinterpret_cast<::FUN_00975b60_shell *>((((FalloutRadio*)&g_011e0e80)))->CleanupCrimeLists(buffer);
        return true;
    case 5:
        reinterpret_cast<::CombatThreatMap *>((((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)))->FUN_00993800((int)(buffer));
        return true;
    case 6:
        ::ResetInterfaceState();
        return true;
    case 7:
        UnloadGameData();
        return true;
    case 0:
        ::FUN_004d60c0();
        return true;
    case 8:
        return false;
    case 9:
        ActorCause::ClearActorCauseList(buffer);
        return true;
    case 10:
        ::ResetRadioGlobals();
        return true;
    case 11:
        ::FUN_0040fbe0();
        return true;
    case 1000:
        ((ProcessLists*)&g_011e0e80)->Revert(buffer);
        return true;
    default:
        ::FUN_00845cc0("DEFAULT: Unknown global data type %i in RevertGlobalData()", type);
        return false;
    }
}

// Dispatches loading of global game data to the handler for the given type, returning false and logging an error for unknown types.
// @fnv 0x0084be40
bool SaveGameLoader::LoadGlobalDataRange(unsigned int type, BGSLoadGameBuffer* buffer)
{
    switch (type)
    {
    case 1:
        ::LoadPlayerLocation(buffer);
        return true;
    case 2:
        reinterpret_cast<::GridHolder *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->Load((::LoadBuffer *)(buffer));
        return true;
    case 3:
        FUN_0084cd40(buffer);
        return true;
    case 4:
        reinterpret_cast<::FUN_00975930_shell *>((((FalloutRadio*)&g_011e0e80)))->FUN_00975930((::LoadBuffer *)(buffer));
        return true;
    case 5:
        reinterpret_cast<::fnv_00993440::FUN_00993440_shell *>((((CombatManager*)BGSSaveLoadGlobalDataWorldspacePtr)))->LoadCombatState((::fnv_00993440::BGSLoadGameBuffer *)(buffer));
        return true;
    case 6:
        ::fnv_00706860::LoadMenuState((::fnv_00706860::BGSLoadGameBuffer *)(buffer));
        return true;
    case 7:
        LoadEffects(buffer);
        return true;
    case 0:
        ::ReadSavedSettings(buffer);
        return true;
    case 8:
        Sky::GetInstance()->LoadGame(buffer);
        return true;
    case 9:
        ::FUN_0066e750(buffer);
        return true;
    case 10:
        FUN_008368b0(buffer);
        return true;
    case 11:
        SoundPlaybackManager::LoadGame(buffer);
        return true;
    case 1000:
        reinterpret_cast<::FUN_004534f0_shell *>((((MagicCaster*)&g_011e0e80)))->FUN_004534f0((unsigned int)((MagicItem*)buffer));
        return true;
    default:
        ::FUN_00845cc0("SAVELOAD: Unknown global data type %i in LoadGlobalData()", type);
        return false;
    }
}

extern int _data_011c16bc;
class SaveLoadFile;
struct LGB : BGSLoadGameBuffer
{
    int pad[3];
    ~LGB()
    {}
};
// Reads count entries from file, each a type followed by a buffer, and loads each global data range.
// @fnv 0x0084bc20
void __cdecl LoadGlobalDataRanges(SaveLoadFile* file, unsigned int count)
{
    for (unsigned int i = 0; i < count; ++i)
    {
        LGB buffer;
        {
            unsigned int type = 0;
            ReadFileIntoBuffer(file, &type, 4);
            reinterpret_cast<::FUN_00864740_shell *>(&(buffer))->ReadAndVerifySize(file);
            SaveGameLoader::LoadGlobalDataRange(type, &buffer);
        }
    }
}

namespace Local {
class BGSLoadGameBuffer
{
  public:
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
    int pad[4];
};
}

// @fnv 0x0084bfb0
void __cdecl FUN_0084bfb0(unsigned int start, unsigned int end)
{
    Local::BGSLoadGameBuffer buffer;
    for (unsigned int i = start; i < end; ++i)
    {
        ::FUN_0084c030(i, reinterpret_cast< ::BGSLoadGameBuffer*>(&buffer));
    }
}

struct G975
{
};
struct W993
{
};
// @fnv 0x0084c030
bool __cdecl FUN_0084c030(unsigned int type, BGSLoadGameBuffer* buffer)
{
    switch (type)
    {
    case 1:
        return false;
    case 2:
        return false;
    case 3:
        return false;
    case 4:
        reinterpret_cast<::ProcessLists *>((((G975*)&g_011e0e80)))->InitLoadGame(buffer);
        return true;
    case 5:
        reinterpret_cast<::CombatGroup532 *>((((W993*)BGSSaveLoadGlobalDataWorldspacePtr)))->FUN_00993600(buffer);
        return true;
    case 6:
        return false;
    case 7:
        return false;
    case 0:
        return false;
    case 8:
        return false;
    case 9:
        ((void(__cdecl*)(BGSLoadGameBuffer*))((void (&)())::UpdateOrRemoveItems))(buffer);
        return true;
    case 10:
        ((void(__cdecl*)(BGSLoadGameBuffer*))((void (&)())::FalloutRadio::InitLoadGame))(buffer);
        return true;
    case 11:
        return false;
    case 1000:
        return false;
    }
    ((void(__cdecl*)(const char*, unsigned int))((void (&)())::FUN_00845cc0))(
        "DEFAULT: Unknown global data type %i in InitGlobalData()", type);
    return false;
}

namespace fnv_0084c110 {
struct LGB : BGSLoadGameBuffer
{
    int pad[3];
    ~LGB()
    {}
};
// @fnv 0x0084c110
void __cdecl FUN_0084c110(unsigned int aiStart, unsigned int aiEnd)
{
    LGB loadGameBuffer;
    for (unsigned int i = aiStart; i < aiEnd; ++i)
        SaveGameLoader::LoadFormType(i, &loadGameBuffer);
}
}  // namespace fnv_0084c110

struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESObjectCELL;
struct TESObjectREFR;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadGame
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    void SaveGame(SaveLoadFile*);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};
struct FUN_0084cc40_shell : public BGSSaveLoadGame
{
    void FUN_0084cc40(bool);
};

// Sets or clears bit 0x40 in the flags field according to abValue.
// @fnv 0x0084cc40
void FUN_0084cc40_shell::FUN_0084cc40(bool abValue)
{
    if (abValue)
        m_uiInitializationFlags |= 0x40;
    else
        m_uiInitializationFlags &= ~0x40;
}

struct FUN_0084d050_shell : public ImageSpaceModifierInstance
{
    bool IsFlagSet();
};
// @fnv 0x0084d160
void SaveGameLoader::UnloadGameData()
{
    ScreenSplatter::Clear();
    ScreenCustomSplatter::Clear();
    ((::BSPortal *)(::FUN_0045a190()))->BSPortal::~BSPortal();
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* node = ((::BSSimpleList< ::NiPointer< ::ImageSpaceModifierInstance>> *)(reinterpret_cast<::TESObjectTREE *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetData()));
    while (node)
    {
        ImageSpaceModifierInstance* effect =
            (ImageSpaceModifierInstance*)((NiPointer<NiNode>*)&((::BGSPerkEntry *)(new ((void *)(((BSSimpleList<BGSPerkEntry*>*)node))) ::Vec3())))
                ->
                operator->();
        if (effect && !reinterpret_cast<::FUN_0084d050_shell *>((effect))->IsFlagSet())
        {
            NiPointer<NiAVObject> ref((NiAVObject*)effect);
            reinterpret_cast<::ListReader *>((node))->FUN_00631620((const ::NodeValue &)(ref));
            continue;
        }
        else
        {
            if (effect)
                reinterpret_cast<::FUN_0063f790_shell *>((((ImageSpaceModifierInstanceDOF*)effect)))->FUN_0063f790(0.0f);
        }
        node = (BSSimpleList<NiPointer<ImageSpaceModifierInstance> >*)((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((((BSSimpleList<BGSPerkEntry*>*)node)))->FUN_00726070()));
    }
}

// @fnv 0x0084d050
bool FUN_0084d050_shell::IsFlagSet()
{
    return (*(unsigned int*)((char*)this + 0x18) & 1) ? true : false;
}

class FUN_0084c580_shell
{
  public:
    unsigned int field208;
    unsigned int GetField208();
};

// @fnv 0x0084c580
unsigned int FUN_0084c580_shell::GetField208()
{
    return *(unsigned int*)((char*)this + 0x208);
}

class TESGlobal : public TESForm
{
  public:
};

struct GlobalListNode
{
};

struct TESDataHandler
{
};

struct BGSSaveFormBuffer
{
};


// @fnv 0x0084cc90
void FUN_0084cc90(BGSSaveFormBuffer* apBuffer)
{
    GlobalListNode* pList = ((::GlobalListNode *)(::FUN_00461190((int)((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))));
    int iCount = 0;
    unsigned int uiStart = reinterpret_cast<::FUN_00865f20_shell *>((apBuffer))->FUN_00865f20();
    GlobalListNode* pIter = pList;
    while (pIter)
    {
        TESGlobal* pGlobalForm = ((::TESGlobal *)(new ((void *)(pIter)) ::Vec3()));
        if (pGlobalForm && !reinterpret_cast<::FUN_00549580_shell *>((pGlobalForm))->FUN_00549580())
        {
            reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pGlobalForm), 0);
            float fValue = reinterpret_cast<::FUN_00526ac0_shell *>((pGlobalForm))->FUN_00526ac0();
            reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50(&fValue, 4, 0);
            ++iCount;
        }
        pIter = ((::GlobalListNode *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((apBuffer))->FUN_00865ff0(iCount, uiStart);
}

namespace fnv_00866200 {
struct SaveLoadFile
{
};

struct PackedFormID
{
    unsigned char m_ucIDByte0;
    unsigned char m_ucIDByte1;
    unsigned char m_ucIDByte2;
};

struct BGSSaveLoadChangeFlags
{
    unsigned char cFlags1;
    unsigned char cFlags2;
    unsigned char cFlags3;
    unsigned char cFlags4;
};

struct BGSSaveLoadFormType
{
    unsigned char m_ucFormType;
};

struct FormLoadContext
{
    PackedFormID iFormID;
    BGSSaveLoadChangeFlags m_pDeathItem;
    BGSSaveLoadFormType m_ucFormType;
    unsigned char cVersion;
    FormLoadContext();
};


struct FUN_00866200_owner
{
    char* pBuffer;
    void FUN_00866200(SaveLoadFile* apFile, unsigned int auiFormID, BGSSaveLoadChangeFlags aChangeFlags);
};

// @fnv 0x00866200
void FUN_00866200_owner::FUN_00866200(SaveLoadFile* apFile, unsigned int auiFormID, BGSSaveLoadChangeFlags aChangeFlags)
{
    char* pData = pBuffer;
    char* pCurrent = pBuffer + 2;
    FormLoadContext header;
    reinterpret_cast<::FUN_00853570_shell *>(&(header.iFormID))->WriteFormIDBytes(auiFormID);
    header.m_pDeathItem = aChangeFlags;
    header.m_ucFormType.m_ucFormType = pData[0];
    header.cVersion = pData[1];
    reinterpret_cast<::FUN_00846330_shell *>((apFile))->WriteToFile(&header, 9);
    int iSize = reinterpret_cast<::FUN_00864520_shell *>(&(header.m_ucFormType))->FUN_00864520();
    unsigned int uiValue = 0;
    pCurrent += ((int)(::ReadValueBySizeType(pCurrent, &uiValue, iSize)));
    ::fnv_00845d80::WriteValueByType((::fnv_00845d80::FUN_00846330_shell *)(apFile), uiValue, iSize);
    if (uiValue)
        reinterpret_cast<::FUN_00846330_shell *>((apFile))->WriteToFile(pCurrent, uiValue);
}
}  // namespace fnv_00866200

namespace fnv_00975840 {
struct BGSSaveFormBuffer
{
};

struct SavedItem
{
};

struct ItemListNode
{
};

struct FUN_00975840_owner
{
    void FUN_00975840(BGSSaveFormBuffer* apBuffer);
};

// @fnv 0x00975840
void FUN_00975840_owner::FUN_00975840(BGSSaveFormBuffer* apBuffer)
{
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x154, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x158, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x103b4, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apBuffer))->FUN_00865e50((char*)this + 0x103b8, 4, 0);
    for (unsigned int i = 0; i < 5; ++i)
    {
        unsigned int ItemUpdateArray = 0;
        unsigned int uiStart = reinterpret_cast<::FUN_00865f20_shell *>((apBuffer))->FUN_00865f20();
        ItemListNode* pIter = ((ItemListNode**)((char*)this + 0x44))[i];
        while (pIter)
        {
            SavedItem* pSavedItem = ((::fnv_00975840::SavedItem *)(new ((void *)(pIter)) ::Vec3()));
            if (pSavedItem)
            {
                reinterpret_cast<::Candidate *>((pSavedItem))->SaveToStream((::SaveLocal *)(apBuffer));
                ++ItemUpdateArray;
            }
            pIter = ((::fnv_00975840::ItemListNode *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
        reinterpret_cast<::FUN_00865ff0_shell *>((apBuffer))->FUN_00865ff0(ItemUpdateArray, uiStart);
    }
}
}  // namespace fnv_00975840

struct FUN_0084cbf0_shell
{
    unsigned int flags;
    void SetFlag20(bool set);
};

// Sets or clears bit 0x20 in the flags word at offset 0x244 based on the set argument.
// @fnv 0x0084cbf0
void FUN_0084cbf0_shell::SetFlag20(bool set)
{
    if (set)
        ((unsigned int*)((char*)this + 0x244))[0] |= 0x20;
    else
        ((unsigned int*)((char*)this + 0x244))[0] &= 0xffffffdf;
}

namespace fnv_0084ced0 {
class TESGlobal;
struct BGSReconstructFormsInAllFilesMap
{
  public:
};
struct BGSSaveLoadGame
{
  public:
};
class TESDataHandler
{
  public:
};
struct DH : public TESDataHandler
{
};
struct ListStub
{
  public:
};
// Iterates the data handler's TESGlobal list and calls FUN_00843630 on each global through the save-load reconstruct map.
// @fnv 0x0084ced0
void ReconstructAllGlobals()
{
    BSSimpleList<TESGlobal*>* pGlobalList;
    BGSReconstructFormsInAllFilesMap* pReconstructMap;
    pReconstructMap = ((::fnv_0084ced0::BGSReconstructFormsInAllFilesMap *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>(((*reinterpret_cast<::fnv_0084ced0::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_007af430()));
    pGlobalList = ((::BSSimpleList< ::fnv_0084ced0::TESGlobal *> *)(::FUN_00461190((int)((*reinterpret_cast<::fnv_0084ced0::DH * *>(&::g_dataHandler))))));
    while (pGlobalList)
    {
        TESGlobal* pglobal;
        pglobal = *((::fnv_0084ced0::TESGlobal **)(new ((void *)(((ListStub*)pGlobalList))) ::Vec3()));
        reinterpret_cast<::fnv_00843630::FUN_00843630_shell *>((pReconstructMap))->FUN_00843630((::TESForm *)(pglobal), 0);
        pGlobalList = (BSSimpleList<TESGlobal*>*)((::fnv_0084ced0::ListStub *)(reinterpret_cast<::Callees *>((((ListStub*)pGlobalList)))->FUN_00726070()));
    }
}
}  // namespace fnv_0084ced0

union LLD_SettingValue
{
    bool b;
    float f;
    const char* s;
};
class LLD_INISettingCollection;
template <class T> class LLD_SettingT
{
  public:
    LLD_SettingValue* Bool();
    const char* String();
};
struct LLD_Point3
{
    float x;
    float y;
    float z;
    LLD_Point3();
};
struct LLD_FullName
{
};
struct LLD_FullNameLen
{
    unsigned int GetModelLength();
};
class LLD_Cell;
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_0a();
    virtual void vfn_0b();
    virtual void vfn_0c();
    virtual void vfn_0d();
    virtual void vfn_0e();
    virtual void vfn_0f();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_1a();
    virtual void vfn_1b();
    virtual void vfn_1c();
    virtual void vfn_1d();
    virtual void vfn_1e();
    virtual void vfn_1f();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_2a();
    virtual void vfn_2b();
    virtual void vfn_2c();
    virtual void vfn_2d();
    virtual void vfn_2e();
    virtual void vfn_2f();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_3a();
    virtual void vfn_3b();
    virtual void vfn_3c();
    virtual void vfn_3d();
    virtual void vfn_3e();
    virtual void vfn_3f();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    virtual void vfn_46();
    virtual void vfn_47();
    virtual void vfn_48();
    virtual void vfn_49();
    virtual void vfn_4a();
    virtual void vfn_4b();
    virtual void vfn_4c();
    virtual void vfn_4d();
    virtual void vfn_4e();
    virtual void vfn_4f();
    virtual void vfn_50();
    virtual void vfn_51();
    virtual void vfn_52();
    virtual void vfn_53();
    virtual void vfn_54();
    virtual void vfn_55();
    virtual void vfn_56();
    virtual void vfn_57();
    virtual void vfn_58();
    virtual void vfn_59();
    virtual void vfn_5a();
    virtual void vfn_5b();
    virtual void vfn_5c();
    virtual void vfn_5d();
    virtual void vfn_5e();
    virtual void vfn_5f();
    virtual void vfn_60();
    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual void vfn_64();
    virtual void vfn_65();
    virtual void vfn_66();
    virtual void vfn_67();
    virtual void vfn_68();
    virtual void vfn_69();
    virtual void vfn_6a();
    virtual void vfn_6b();
    virtual void vfn_6c();
    virtual void vfn_6d();
    virtual void vfn_6e();
    virtual void vfn_6f();
    virtual void vfn_70();
    virtual void vfn_71();
    virtual void vfn_72();
    virtual void vfn_73();
    virtual void vfn_74();
    virtual void vfn_75();
    virtual void vfn_76();
    virtual void vfn_77();
    virtual void vfn_78();
    virtual void vfn_79();
    virtual void vfn_7a();
    virtual void vfn_7b();
    virtual void vfn_7c();
    virtual const LLD_Point3& GetPos() const;
};
class LLD_Quest : public TESForm
{
  public:
};
class LLD_PlayerCharacter : public TESObjectREFR
{
  public:
    void FUN_0093c200(LLD_Point3, LLD_Point3, LLD_Cell*, bool);
    void FUN_0093cce0(LLD_Point3, LLD_Point3, TESWorldSpace*, bool);
};
class LLD_Cell
{
  public:
};
struct LLD_WorldSpaceHelper
{
};
struct LLD_TESHelper
{
};
class LLD_DataHandler
{
  public:
};
class LLD_SaveLoadGame
{
  public:
};
class LLD_LoadingMenu
{
  public:
};
int FNV_GetFormType(TESForm*);
void __cdecl FUN_0084cbd0(const char*, ...);
char* __cdecl FUN_00ec7750(const char*, const char*);
unsigned int __cdecl FUN_00ec8d08(const char*, char**, int);
class PlayerCharacter;
class TESDataHandler;
class BGSSaveLoadGame;

// @fnv 0x0084c5a0
void LoadPlayerLocation(BGSLoadGameBuffer* apLoadGameBuffer)
{
    TESForm* plocation;
    TESWorldSpace* ptesWorldSpace;
    int icurrentGridY;
    unsigned int inextID;
    int icurrentGridX;
    bool bvalidPlayerLocation;

    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&inextID), 4);
    ptesWorldSpace = dynamic_cast<TESWorldSpace*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apLoadGameBuffer))->FUN_008648a0()));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&icurrentGridX), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&icurrentGridY), 4);
    plocation = ::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((apLoadGameBuffer))->FUN_008648a0());
    LLD_Point3 playerLocation;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((apLoadGameBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&playerLocation), 12);
    ::LoadingMenu::LoadGame(apLoadGameBuffer);
    bvalidPlayerLocation = true;

    if (plocation)
    {
        if (FNV_GetFormType(plocation) == 0x39)
        {
            LLD_Cell* pcell = (LLD_Cell*)plocation;
            if (((::LLD_Cell *)(reinterpret_cast<::LowProcess *>((((LLD_PlayerCharacter*)::_g_thePlayer)))->GetTarget())) != pcell)
                ((LLD_PlayerCharacter*)::_g_thePlayer)
                    ->FUN_0093c200(playerLocation, (*(const ::LLD_Point3 *)(reinterpret_cast<::TESRecipe *>((void *)(((LLD_PlayerCharacter*)::_g_thePlayer)))->GetData())), pcell, false);
            if (ptesWorldSpace)
                reinterpret_cast<::WS458200_Shell *>((((LLD_TESHelper*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_00458200((::WS458200_World *)(ptesWorldSpace));
            reinterpret_cast<::TESRecipe *>((((LLD_TESHelper*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->SetRequiredSkill((::ActorValue::Index)(icurrentGridX));
            reinterpret_cast<::FUN_0061cc40_shell *>((((LLD_TESHelper*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_0061cc40(icurrentGridY);
        }
        else if (FNV_GetFormType(plocation) == 0x41)
        {
            if (ptesWorldSpace)
                reinterpret_cast<::WS458200_Shell *>((((LLD_TESHelper*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_00458200((::WS458200_World *)(ptesWorldSpace));
            TESWorldSpace* pworld = (TESWorldSpace*)plocation;
            if (reinterpret_cast<::FUN_00586260_shell *>((((LLD_WorldSpaceHelper*)pworld)))->IsFlag8Set() && (*reinterpret_cast<::LLD_SettingT< ::LLD_INISettingCollection> *>(&::g_011e08e0)).Bool()->b &&
                !reinterpret_cast<::WorldQuery *>((((LLD_WorldSpaceHelper*)pworld)))->ContainsPoint((const ::NiPoint3 *)(::LLD_Point3 *)(&playerLocation)))
                bvalidPlayerLocation = false;
            if (bvalidPlayerLocation)
            {
                LLD_Point3 centerGridLocation;
                int icellX;
                LLD_Cell* pcell;
                int icellY;
                centerGridLocation.x = (float)(icurrentGridX << 12);
                centerGridLocation.y = (float)(icurrentGridY << 12);
                centerGridLocation.z = 0.0f;
                reinterpret_cast<::TES *>((((LLD_TESHelper*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FindCellAtPosition((const ::NiPoint3 *)(const ::LLD_Point3 *)(&centerGridLocation), false);
                reinterpret_cast<::S457d70 *>((((LLD_TESHelper*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_00457d70(1, (::Form457 *)(plocation), 0);
                icellX = ::FUN_00406d90(playerLocation.x) >> 12;
                icellY = ::FUN_00406d90(playerLocation.y) >> 12;
                pcell = ((::LLD_Cell *)(reinterpret_cast<::FUN_00461c20_Holder *>((((LLD_DataHandler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetOrCreateCell(icellX, icellY, pworld, false)));
                if (!pcell || !reinterpret_cast<::FUN_00545cb0_shell *>((pcell))->FUN_00545cb0())
                {
                    if (((::LLD_Cell *)(reinterpret_cast<::LowProcess *>((((LLD_PlayerCharacter*)::_g_thePlayer)))->GetTarget())))
                        reinterpret_cast<::fnv_0054ca90::Cell *>((((::LLD_Cell *)(reinterpret_cast<::LowProcess *>((((LLD_PlayerCharacter*)::_g_thePlayer)))->GetTarget()))))->FUN_0054ca90((::fnv_0054ca90::Ref *)(::TESObjectREFR *)((LLD_PlayerCharacter*)::_g_thePlayer));
                    reinterpret_cast<::fnv_00454450::ReloadManager *>((((LLD_TESHelper*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_00454450((::fnv_00454450::ReloadPoint *)(::LLD_Point3 *)(&centerGridLocation));
                    pcell = ((::LLD_Cell *)(reinterpret_cast<::FUN_00461c20_Holder *>((((LLD_DataHandler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->GetOrCreateCell(icellX, icellY, pworld, true)));
                }
                if (pcell)
                {
                    reinterpret_cast<::FUN_0084cbf0_shell *>((((LLD_SaveLoadGame*)g_BGSSaveLoadGame)))->SetFlag20(true);
                    ((LLD_PlayerCharacter*)::_g_thePlayer)
                        ->FUN_0093c200(playerLocation, (*(const ::LLD_Point3 *)(reinterpret_cast<::TESRecipe *>((void *)(((LLD_PlayerCharacter*)::_g_thePlayer)))->GetData())), pcell, false);
                    reinterpret_cast<::FUN_0084cbf0_shell *>((((LLD_SaveLoadGame*)g_BGSSaveLoadGame)))->SetFlag20(false);
                }
                else
                    bvalidPlayerLocation = false;
            }
        }
        else
            bvalidPlayerLocation = false;
    }
    else
        bvalidPlayerLocation = false;

    if (!bvalidPlayerLocation)
    {
        unsigned int isafeMarkerID;
        TESObjectREFR* pref;
        reinterpret_cast<::FUN_0084cc40_shell *>((((LLD_SaveLoadGame*)g_BGSSaveLoadGame)))->FUN_0084cc40(true);
        BSSimpleList<LLD_Quest*>* pIter = ((::BSSimpleList< ::LLD_Quest *> *)(reinterpret_cast<::fnv_00455600::FUN_00455600_shell *>((((LLD_DataHandler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->FUN_00455600()));
        while (pIter && ((::LLD_Quest *)(new ((void *)(pIter)) ::Vec3())))
        {
            FUN_0084cbd0("Quest %s (%08x) compared to Patch04Debug\n",
                         ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((LLD_FullName*)((char*)((::LLD_Quest *)(new ((void *)(pIter)) ::Vec3())) + 0x30))))->FUN_00408da0())),
                         ((unsigned int)(reinterpret_cast<::FUN_0084e3a0_Class *>((((::LLD_Quest *)(new ((void *)(pIter)) ::Vec3()))))->FUN_0084e3a0())));
            if (((LLD_FullNameLen*)((char*)((::LLD_Quest *)(new ((void *)(pIter)) ::Vec3())) + 0x30))->GetModelLength() > 8 &&
                FUN_00ec7750(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>((((LLD_FullName*)((char*)((::LLD_Quest *)(new ((void *)(pIter)) ::Vec3())) + 0x30))))->FUN_00408da0())), "Patch04Debug"))
            {
                *(LLD_Quest**)((char*)::_g_thePlayer + 0xe4c) = ((::LLD_Quest *)(new ((void *)(pIter)) ::Vec3()));
                break;
            }
            pIter = ((::BSSimpleList< ::LLD_Quest *> *)(reinterpret_cast<::Callees *>((pIter))->FUN_00726070()));
        }
        reinterpret_cast<::FUN_0095f530_shell *>((((LLD_PlayerCharacter*)::_g_thePlayer)))->FUN_0095f530((::TESObjectREFR *)(false), (::TESObjectREFR *)(0xff));
        isafeMarkerID = FUN_00ec8d08(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::LLD_SettingT< ::LLD_INISettingCollection> *>(&::g_011de25c))))->GetMenuTitle())), 0, 16);
        pref = dynamic_cast<TESObjectREFR*>(::FUN_004839c0(isafeMarkerID));
        if (pref)
        {
            LLD_Point3 loc = pref->GetPos();
            LLD_Point3 angle = (*(const ::LLD_Point3 *)(reinterpret_cast<::TESRecipe *>((void *)(pref))->GetData()));
            LLD_Cell* pcell = ((::LLD_Cell *)(reinterpret_cast<::LowProcess *>((pref))->GetTarget()));
            TESWorldSpace* pworld = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((void *)(pref))->FUN_00575d70()));
            bvalidPlayerLocation = true;
            if (pworld)
                ((LLD_PlayerCharacter*)::_g_thePlayer)->FUN_0093cce0(loc, angle, pworld, true);
            else if (pcell)
                ((LLD_PlayerCharacter*)::_g_thePlayer)->FUN_0093c200(loc, angle, pcell, true);
            else
                bvalidPlayerLocation = false;
        }
        if (!bvalidPlayerLocation)
        {
            TESWorldSpace* pworld = dynamic_cast<TESWorldSpace*>(::FUN_004839c0(0xda726));
            if (pworld)
            {
                LLD_Cell* pcell = ((::LLD_Cell *)(reinterpret_cast<::TESWorldSpace *>((((LLD_WorldSpaceHelper*)pworld)))->GetCellAtGridPosition(-18, 0)));
                if (!pcell)
                    pcell = ((::LLD_Cell *)(reinterpret_cast<::WorldCellLoader *>((((LLD_WorldSpaceHelper*)pworld)))->FUN_00585b30(-18, 0)));
                if (!pcell)
                    pcell = ((::LLD_Cell *)(reinterpret_cast<::TESWorldSpace *>((((LLD_WorldSpaceHelper*)pworld)))->GetCellAtGridPosition(0, 0)));
                if (!pcell)
                    pcell = ((::LLD_Cell *)(reinterpret_cast<::WorldCellLoader *>((((LLD_WorldSpaceHelper*)pworld)))->FUN_00585b30(0, 0)));
                if (!pcell)
                    pcell = ((::LLD_Cell *)(reinterpret_cast<::FUN_00461330_shell *>((((LLD_DataHandler*)(*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler)))))->FUN_00461330((const char *)(0), 0, 0, pworld)));
                if (pcell)
                    reinterpret_cast<::fnv_0093db60::PlayerCenterOnCell *>((((LLD_PlayerCharacter*)::_g_thePlayer)))->FUN_0093db60((const char *)(0), (::fnv_0093db60::CellS *)(pcell));
            }
        }
    }

    reinterpret_cast<::FUN_004539a0_cls *>((((LLD_TESHelper*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->FUN_004539a0(true, 0);
    ::FUN_00868d70(0);
    ::FUN_00c459d0(0);
}

class B84C490Form;

struct B84C490Point3
{
    float x;
    float y;
    float z;
};

class B84C490SaveBuffer
{
  public:
};

class B84C490DataHandler
{
  public:
};

class B84C490TES
{
  public:
};

class B84C490Player
{
  public:
    const B84C490Point3* GetPos();
};



// @fnv 0x0084c490
void __cdecl SavePlayerLocation(B84C490SaveBuffer* pkBuffer)
{
    unsigned int ItemUpdateArray = reinterpret_cast<::FUN_0084c580_shell *>(((*reinterpret_cast<::B84C490DataHandler * *>(&::g_dataHandler))))->GetField208();
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&ItemUpdateArray, 4, 0);
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pkBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(::B84C490Form *)(((::B84C490Form *)(reinterpret_cast<::EffectSetting *>(((*reinterpret_cast<::B84C490TES * *>(&::g_TES))))->GetHitSound()))), 0);
    unsigned int uiGridX = reinterpret_cast<::ActorMover *>(((*reinterpret_cast<::B84C490TES * *>(&::g_TES))))->GetCurrentMoveModeType();
    int iGridY = ((int)(reinterpret_cast<::FUN_0045cd60_shell *>(((*reinterpret_cast<::B84C490TES * *>(&::g_TES))))->FUN_0045cd60()));
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&uiGridX, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&iGridY, 4, 0);
    B84C490Form* pkWorldSpace2 = ((::B84C490Form *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>(((*reinterpret_cast<::B84C490Player * *>(&::_g_thePlayer))))->FUN_00575d70()));
    if (!pkWorldSpace2)
        pkWorldSpace2 = ((::B84C490Form *)(reinterpret_cast<::LowProcess *>(((*reinterpret_cast<::B84C490Player * *>(&::_g_thePlayer))))->GetTarget()));
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((pkBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pkWorldSpace2), 0);
    B84C490Point3 kPos = *((const ::B84C490Point3 *)(reinterpret_cast<::TESTopicInfo *>(((*reinterpret_cast<::B84C490Player * *>(&::_g_thePlayer))))->GetAddTopicList()));
    reinterpret_cast<::FUN_00865e50_shell *>((pkBuffer))->FUN_00865e50(&kPos, 12, 0);
    ::SaveLoadScreenData((::BGSSaveFormBuffer *)(pkBuffer));
}

void __cdecl FUN_0082ec40(BGSSaveFormBuffer*);
struct TES84
{
};
struct Manager84
{
};
struct World84
{
};
struct Sky84
{
};
// Dispatches saving of global data to a handler based on the type id, logging an error and returning false for unknown types.
// @fnv 0x0084bcd0
bool __cdecl FUN_0084bcd0(unsigned int type, BGSSaveFormBuffer* buffer)
{
    switch (type)
    {
    case 1:
        ::SavePlayerLocation((::B84C490SaveBuffer *)(buffer));
        return true;
    case 2:
        reinterpret_cast<::TESGridOwner *>((((TES84*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->SaveGridState((::SaveBuffer *)(buffer));
        return true;
    case 3:
        FUN_0084cc90(buffer);
        return true;
    case 4:
        reinterpret_cast<::fnv_00975840::FUN_00975840_owner *>((((Manager84*)&g_011e0e80)))->FUN_00975840((::fnv_00975840::BGSSaveFormBuffer *)(buffer));
        return true;
    case 5:
        reinterpret_cast<::fnv_009932d0::FUN_009932d0_shell *>((((World84*)BGSSaveLoadGlobalDataWorldspacePtr)))->FUN_009932d0((::fnv_009932d0::BGSSaveFormBuffer *)(buffer));
        return true;
    case 6:
        ::FUN_007066d0((::Buffer *)(buffer));
        return true;
    case 7:
        ::SaveImageSpaceModifierInstances((int)(buffer));
        return true;
    case 0:
        ::SaveMiscStats((::BGSSaveGameBuffer *)(buffer));
        return true;
    case 8:
        reinterpret_cast<::FUN_0063eb70_shell *>((((::Sky84 *)(::Sky::GetInstance()))))->FUN_0063eb70(buffer);
        return true;
    case 9:
        ::SaveE6D0Items((::E6D0SaveBuffer *)(buffer));
        return true;
    case 10:
        ::fnv_008366e0::FUN_008366e0((::fnv_008366e0::LoadBuffer *)(buffer));
        return true;
    case 11:
        FUN_0082ec40(buffer);
        return true;
    case 1000:
        reinterpret_cast<::FUN_004534f0_shell *>((((Manager84*)&g_011e0e80)))->FUN_004534f0((unsigned int)(buffer));
        return true;
    default:
        FUN_00845cc0("SAVELOAD: Unknown global data type %i in SaveGlobalData()", type);
        return false;
    }
}

struct TESGlobalEx : public TESGlobal
{
};

struct SaveLoadChangeHistory
{
};

struct GlobalSeenMap
{
    GlobalSeenMap(int hashSize);
    ~GlobalSeenMap();
    int vtbl;
    int hashSize;
    int buckets;
    int count;
};

// @fnv 0x0084cd40
void FUN_0084cd40(BGSLoadGameBuffer* pLoadBuffer)
{
    SaveLoadChangeHistory* history5 = ((::SaveLoadChangeHistory *)(reinterpret_cast<::fnv_007af430::FUN_007af430_shell *>((g_BGSSaveLoadGame))->FUN_007af430()));
    GlobalSeenMap unchanged2(37);
    GlobalListNode* node2 = ((::GlobalListNode *)(::FUN_00461190((int)((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))));
    while (node2)
    {
        TESGlobal* globalVal = ((::TESGlobal *)(new ((void *)(node2)) ::Vec3()));
        if (globalVal)
            reinterpret_cast<::FUN_0084d310_class *>(&(unchanged2))->FUN_0084d310((int)(globalVal), true);
        node2 = ((::GlobalListNode *)(reinterpret_cast<::Callees *>((node2))->FUN_00726070()));
    }
    {
        unsigned int count8 = reinterpret_cast<::fnv_00864a60::FUN_00864a60_cls *>((pLoadBuffer))->FUN_00864a60();
        for (unsigned int aI = 0; aI < count8; aI++)
        {
            TESGlobal* loaded =
                dynamic_cast<TESGlobal*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((pLoadBuffer))->FUN_008648a0()));
            float value9 = 0.0f;
            reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((pLoadBuffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&value9), 4);
            if (loaded)
            {
                if (!reinterpret_cast<::FUN_00549580_shell *>((void *)(static_cast<TESGlobalEx*>(loaded)))->FUN_00549580())
                    reinterpret_cast<::FUN_0046dce0_class *>((static_cast<TESGlobalEx*>(loaded)))->FUN_0046dce0(value9);
                reinterpret_cast<::NiTMap_S *>(&(unchanged2))->RemoveKey((unsigned int)(loaded));
            }
        }
    }
    void* pos2 = reinterpret_cast<::BGSReconstructFormsInAllFilesMap *>(&(unchanged2))->GetFirstPos();
    while (pos2)
    {
        TESGlobal* key3 = 0;
        bool seen4 = false;
        reinterpret_cast<::FUN_0096a400_cls *>(&(unchanged2))->GetNextEntry((::FUN_0096a400_Node **)&(pos2), (unsigned int *)&(key3), (unsigned char *)&(seen4));
        if (!reinterpret_cast<::FUN_00549580_shell *>((void *)(static_cast<TESGlobalEx*>(key3)))->FUN_00549580())
            reinterpret_cast<::fnv_00843630::FUN_00843630_shell *>((history5))->FUN_00843630((::TESForm *)(key3), 0);
    }
}

struct NiBound
{
};

struct NiTimeController
{
};

struct FUN_00865df0_buf
{
};

struct FUN_00529990_Class
{
};

struct FUN_0047c860_Class
{
};

// @fnv 0x0084cf30
void __cdecl SaveImageSpaceModifierInstances(int pBuffer)
{
    int aV11;
    BSSimpleList<NiPointer<ImageSpaceModifierInstance> >* i6;
    int v3;
    ImageSpaceModifierInstance* v8_2;
    void* v2;
    float aV6;
    float v5;

    v3 = 0;
    aV11 = reinterpret_cast<::FUN_00865f20_shell *>((((BGSSaveFormBuffer*)pBuffer)))->FUN_00865f20();
    i6 = ((::BSSimpleList< ::NiPointer< ::ImageSpaceModifierInstance>> *)(reinterpret_cast<::TESObjectTREE *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->GetData()));
    while (i6 != 0)
    {
        v8_2 = (*(::NiPointer< ::ImageSpaceModifierInstance> *)(new ((void *)(i6)) ::Vec3())).operator->();
        if (v8_2 != 0 && !reinterpret_cast<::FUN_0084d050_shell *>((v8_2))->IsFlagSet())
        {
            v2 = (void*)(*(int(**)(int))(*(int*)v8_2 + 148))((int)v8_2);
            if (v2 != 0)
            {
                aV6 = reinterpret_cast<::Twin_0084d030 *>((((NiBound*)v2)))->GetStoredFloatValue();
                reinterpret_cast<::FUN_00865e50_shell *>((((BGSSaveFormBuffer*)pBuffer)))->FUN_00865e50(&aV6, 4, 0);
                v5 = (float)(((double)(::ImageSpaceModifierInstance::GetTime())) - ((double)(reinterpret_cast<::TESActorBaseData *>((((FUN_0047c860_Class*)v2)))->GetHealthRegeneration())));
                reinterpret_cast<::FUN_00865e50_shell *>((((BGSSaveFormBuffer*)pBuffer)))->FUN_00865e50(&v5, 4, 0);
                reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((((FUN_00865df0_buf*)pBuffer)))->FUN_00865df0((::fnv_00865df0::TESForm *)(void *)((void*)((int)(reinterpret_cast<::BGSTerrainManager *>((((NiTimeController*)v2)))->GetMinLevel()))), 0);
                ++v3;
            }
        }
        i6 = ((::BSSimpleList< ::NiPointer< ::ImageSpaceModifierInstance>> *)(reinterpret_cast<::Callees *>((i6))->FUN_00726070()));
    }
    reinterpret_cast<::FUN_00865ff0_shell *>((((BGSSaveFormBuffer*)pBuffer)))->FUN_00865ff0(v3, aV11);
}

#include <stdarg.h>
void __cdecl FUN_00ecbe60(const char* fmt, va_list args);

// @fnv 0x0084cbd0
void __cdecl FUN_0084cbd0(const char* apFormat, ...)
{
    va_list args;
    va_start(args, apFormat);
    FUN_00ecbe60(apFormat, args);
}
