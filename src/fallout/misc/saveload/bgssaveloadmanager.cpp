#include <windows.h>
#include "AutoMemContext.h"
// fallout/misc/saveload/bgssaveloadmanager.cpp: BGSSaveLoadManager, PathManager, Interface, FakeSaveMgr and more (39 functions)

#include <cstdint>
#include "fnv/game_timer.h"
#include "fnv/save_load_game_view.h"
#include <cstring>
#include "runtime/crt.h"
#include "fnv/decl/BSAudioManager.h"
#include "fnv/decl/BSShaderNoLightingProperty.h"
#include "fnv/decl/FUN_004048e0_cls.h"
#include "fnv/decl/FUN_004f8960_shell.h"
#include "fnv/decl/FUN_00525430_Class.h"
#include "fnv/decl/FUN_00527fc0_cls.h"
#include "fnv/decl/FUN_0055d520_shell.h"
#include "fnv/decl/FUN_005621d0_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_00620b80_shell.h"
#include "fnv/decl/FUN_006ebcd0_shell.h"
#include "fnv/decl/FUN_006ebcf0_cls.h"
#include "fnv/decl/FUN_00714d70.h"
#include "fnv/decl/FUN_0084cc40_shell.h"
#include "fnv/decl/FUN_0084e250_shell.h"
#include "fnv/decl/FUN_0084ff90_shell.h"
#include "fnv/decl/FUN_00850030_shell.h"
#include "fnv/decl/FUN_00851680_class.h"
#include "fnv/decl/FUN_0086f670_shell.h"
#include "fnv/decl/FUN_009373f0_shell.h"
#include "fnv/decl/FUN_009ca410_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00aa4db0_shell.h"
#include "fnv/decl/FUN_00ad7230_shell.h"
#include "fnv/decl/FUN_00ad8740_shell.h"
#include "fnv/decl/FUN_00c3e310_shell.h"
#include "fnv/decl/FUN_00c3e340_cls.h"
#include "fnv/decl/FadeAttachedTES.h"
#include "fnv/decl/FileEnumerator.h"
#include "fnv/decl/MessageHUD.h"
#include "fnv/decl/ReconstructSession.h"
#include "fnv/decl/RecordList.h"
#include "fnv/decl/S457d70.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESForm.h"
#include "fnv/decl/TextString.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/fnv_00448420__ModelLoader.h"
#include "fnv/decl/fnv_00448620__FUN_00448620_cls.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00578870__FUN_00578870_Class.h"
#include "fnv/decl/fnv_0063ac70__FUN_0063ac70_shell.h"
#include "fnv/decl/fnv_006c3640__C006c3640.h"
#include "fnv/decl/fnv_006c39c0__FUN_006c39c0_shell.h"
#include "fnv/decl/fnv_00847850__W20Save.h"
#include "fnv/decl/fnv_0084ab20__FUN_0084ab20_shell.h"
#include "fnv/decl/fnv_0086f6a0__FUN_0086f6a0_shell.h"
#include "fnv/decl/fnv_00877430__FUN_00877430_shell.h"
#include "fnv/decl/fnv_00977660__FUN_00977660_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_0047d000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004dc000.h"
#include "fnv/symbols_005a9000.h"
#include "fnv/symbols_005ae000.h"
#include "fnv/symbols_006c0000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00846000.h"
#include "fnv/symbols_0084d000.h"
#include "fnv/symbols_00850000.h"
#include "fnv/symbols_0086d000.h"
#include "fnv/symbols_0093a000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a25000.h"
#include "fnv/symbols_00c3b000.h"
#include "fnv/symbols_01011000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_01020000.h"
#include "fnv/symbols_0105d000.h"
#include "fnv/symbols_01076000.h"
#include "fnv/symbols_0107f000.h"
#include "fnv/symbols_011a2000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c9000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "fnv/symbols_01202000.h"
#include "bgssaveloadmanager_decls.h"

template <class T> unsigned int __cdecl BSStringLength(const T* text);

template <> unsigned int __cdecl BSStringLength<char>(const char* text);

extern "C" int __cdecl _mbsnicmp(const char* left, const char* right, unsigned int count);
extern "C" const char g_autosaveName[];
extern "C" const char g_scrubChars[];
extern "C" const char g_versionInfoFormat[];
extern "C" const char g_dateTimeFormat[];

struct FNVSystemTime
{
    unsigned short year;
    unsigned short month;
    unsigned short dayOfWeek;
    unsigned short day;
    unsigned short hour;
    unsigned short minute;
    unsigned short second;
    unsigned short milliseconds;
};
struct FNVGetVersionInfoLocals
{
    FNVSystemTime time;
    char versionPrefix[260];
    unsigned char padding[8];
    unsigned int dateTimeSize;
    char dateTime[260];
};
typedef void(* FNVDateFunction)(char* output, unsigned int* size);
typedef void(* FNVSystemTimeFunction)(FNVSystemTime* time);
extern "C" FNVDateFunction g_fnvDateFunction;
extern "C" FNVSystemTimeFunction g_fnvSystemTimeFunction;

// Returns true when name is non-null and case-insensitively matches g_quicksaveName over its length.
// @fnv 0x00851a60
bool BGSSaveLoadManager::IsQuickSaveFileName(const char* name)
{
    if (name != 0 && _mbsnicmp(name, g_quicksaveName, ::FUN_0044a670(g_quicksaveName)) == 0)
        return true;
    return false;
}

// @fnv 0x00851b00
bool BGSSaveLoadManager::IsAutoSaveFileName(const char* name)
{
    if (name != 0 && _mbsnicmp(name, g_autosaveName, ::FUN_0044a670(g_autosaveName)) == 0)
        return true;
    return false;
}

// Replaces characters in name that are below '0', above 'z', or in g_scrubChars with a space, turning '"' into '\''.
// @fnv 0x008518d0
void BGSSaveLoadManager::SanitizeSaveFileName(char* name)
{
    unsigned int length = ::FUN_0044a670(name);
    for (unsigned int index = 0; index < length; ++index)
    {
        if (name[index] < '0')
            name[index] = ' ';
        if (name[index] > 'z')
            name[index] = ' ';
        else if (strchr(g_scrubChars, name[index]) != 0)
        {
            if (name[index] == '"')
                name[index] = '\'';
            else
                name[index] = ' ';
        }
    }
}

// Builds a version prefix and formatted date/time, then writes the version info string into output using capacity.
// @fnv 0x00851120
void BGSSaveLoadManager::GetFNVVersionInfo(char* output, unsigned int capacity)
{
    FNVGetVersionInfoLocals locals;

    locals.versionPrefix[0] = ::DAT_01011584[0];
    std::memset(locals.versionPrefix + 1, 0, 0x103);
    locals.dateTime[0] = ::DAT_01011584[0];
    std::memset(locals.dateTime + 1, 0, 0x103);
    locals.dateTimeSize = 0x104;
    g_fnvDateFunction(locals.versionPrefix, &locals.dateTimeSize);
    g_fnvSystemTimeFunction(&locals.time);
    ::FUN_00406d00(locals.dateTime, 0x104, g_dateTimeFormat, locals.time.month, locals.time.day, locals.time.year,
              locals.time.hour, locals.time.minute, locals.time.second);
    ::FUN_00406d00(output, capacity, g_versionInfoFormat, locals.versionPrefix, locals.dateTime, ::xg_ExeVersion, 48,
              27);
}

// @fnv 0x00876ad0
void BGSSaveLoadManager::GetSaveDirectory(char* pcPath)
{
    bool useMyGames = true;
    ::FUN_00406d00(pcPath, 260, DAT_01082dc4, DAT_011a2ff4);
    if (!DAT_00fdf0c4(g_011d3eb0_arg1, DAT_01082dac, 1, pcPath))
        useMyGames = false;
    ::FUN_00406d00(pcPath, 260, DAT_01082dc4, ::_DAT_011a2ff0);
    if (useMyGames && !DAT_00fdf0c4(g_011d3eb0_arg1, DAT_01082dac, 1, pcPath))
        useMyGames = false;
    if (useMyGames)
    {
        char folder[260];
        pcPath[0] = 0;
        DAT_00fdf274(0, 28, 0, 0, folder);
        fnv::crt::strcat_s(folder, 260, DAT_01082da0);
        DAT_00fdf0b8(folder, 0);
        TaskQueueInterface::CopyStringToBuffer(((char *)(::FUN_0086d480())), 260, folder);
        DAT_00fdf274(0, 5, 0, 0, folder);
        fnv::crt::strcat_s(folder, 260, DAT_01082d94);
        DAT_00fdf0b8(folder, 0);
        fnv::crt::strcat_s(folder, 260, DAT_01082d88);
        DAT_00fdf0b8(folder, 0);
        TaskQueueInterface::CopyStringToBuffer(::FUN_004dc110(), 260, folder);
    }
    else
    {
        TaskQueueInterface::CopyStringToBuffer(((char *)(::FUN_0086d480())), 260, g_011dece4_arg1);
        TaskQueueInterface::CopyStringToBuffer(::FUN_004dc110(), 260, g_011dece4_arg1);
    }
    TaskQueueInterface::CopyStringToBuffer(pcPath, 260, ::FUN_004dc110());
    fnv::crt::strcat_s(pcPath, 260, ::_DAT_011a2ff0);
    ((int(*)(char*))DAT_00fdf0d4)(((char *)(::FUN_00c3bb80())));
    ((int(*)(char*))DAT_00fdf0d4)(((char *)(::FUN_00c3bbd0())));
    ((int(*)(char*))DAT_00fdf0d4)(FUN_00c3bc20());
    if (fnv::crt::access(pcPath, 0) == -1)
    {
        char defaultIni[260];
        TaskQueueInterface::CopyStringToBuffer(defaultIni, 260, DAT_01082d70);
        CopyFileA(defaultIni, pcPath, 1);
    }
}

// @fnv 0x00850d60
void BGSSaveLoadManager::FinishLoadingGame()
{
    ChallengeManager::CheckCompletedChallenges();
    reinterpret_cast<::fnv_0086f6a0::FUN_0086f6a0_shell *>((reinterpret_cast<Main*>(g_osGlobals)))->FUN_0086f6a0();
    reinterpret_cast<::FUN_0086f670_shell *>((reinterpret_cast<Main*>(g_osGlobals)))->FUN_0086f670();
    reinterpret_cast<::fnv_00448620::FUN_00448620_cls *>((g_modelLoader))->FUN_00448620(false);
    reinterpret_cast<::FadeAttachedTES *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00459a00();
    reinterpret_cast<::TESForm *>((reinterpret_cast<ActorMover*>(g_osGlobals)))->ClearData();
    reinterpret_cast<GridCellArray*>((*reinterpret_cast<::TES * *>(&::g_TES))->pGridCellArray)
        ->ReleaseGridCells();
    reinterpret_cast<::FUN_009ca410_shell *>((reinterpret_cast<VATS*>(&g_011f2250)))->ProcessVATSCommands();
    TESWorldSpace* world = ((::TESWorldSpace *)(reinterpret_cast<::fnv_00575d70::FUN_00575d70_shell *>((::_g_thePlayer))->FUN_00575d70()));
    if (world)
        world->GetWorldTerrainManager()->FUN_006fca90(*::_g_thePlayer->GetPos(), 15);
    if (((::BGSSaveLoadUI *)(::FUN_00a25920())))
    {
        ((::BGSSaveLoadUI *)(::FUN_00a25920()))->FUN_007d0bd0(true);
        ((::BGSSaveLoadUI *)(::FUN_00a25920()))->FUN_007d0bb0();
    }
    reinterpret_cast<FaderManager*>(DAT_011d8804)->AddFader((FADER_ENUM)1, ((::SETTING_VALUE *)&(::FUN_00403e20((float *)&(originalRuntimeFloatSetting16))))->f, true);
    LoadingMenu::UpdateLoadingScreenThread();
    reinterpret_cast<::S457d70 *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00457d70(0, (::Form457 *)(0), 0);
    reinterpret_cast<::FUN_00ad8740_shell *>((::FUN_00453a70()))->FUN_00ad8740();
    FUN_00830660();
    reinterpret_cast<::fnv_00977660::FUN_00977660_shell *>(&(g_011e0e80))->FUN_00977660();
    reinterpret_cast<::FUN_0084cc40_shell *>((::g_BGSSaveLoadGame))->FUN_0084cc40(false);
    reinterpret_cast<::fnv_006c39c0::FUN_006c39c0_shell *>((((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c39c0();
    reinterpret_cast<::FUN_006ebcd0_shell *>((::GetPathManager()))->FUN_006ebcd0();
}

// @fnv 0x00850c20
void BGSSaveLoadManager::ProcessQueuedLoads()
{
    reinterpret_cast<::FUN_00527fc0_cls *>((DAT_011c9618))->SubmitQueuedItems();
    reinterpret_cast<::fnv_00448420::ModelLoader *>((g_modelLoader))->FUN_00448420();
    FUN_005b4940();
    FUN_005ae270();
    FUN_005a9d60();
    reinterpret_cast<::BSAudioManager *>((::FUN_00453a70()))->FUN_00ad84e0((void *)(-1), (void *)(false));
    bool wasMultiThreaded = reinterpret_cast<::FUN_005bb4d0_shell *>((::FUN_00453a70()))->FUN_005bb4d0();
    reinterpret_cast<::FUN_00ad7230_shell *>((::FUN_00453a70()))->FUN_00ad7230(false);
    for (unsigned int index = 0; index < 10; ++index)
        ::FUN_00453a70()->Update(false);
    reinterpret_cast<::FUN_00ad7230_shell *>((::FUN_00453a70()))->FUN_00ad7230(wasMultiThreaded);
    if (reinterpret_cast<::FUN_00525430_Class *>((reinterpret_cast<HUDMainMenu*>(&g_011f2250)))->FUN_00525430())
    {
        reinterpret_cast<::VATS *>((reinterpret_cast<InventoryStackRecord*>(&g_011f2250)))->FUN_009c8950(true, false);
        reinterpret_cast<NiPoint3Interpolator*>(&g_011f2250)->CreateObject(0, false);
    }
    ::fnv::timer::SetMultiplier(1.0f, true);
    if (::_g_thePlayer)
        reinterpret_cast<VATS*>(::_g_thePlayer)->Update(2, true);
    reinterpret_cast<::S457d70 *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_00457d70(1, (::Form457 *)(0), 0);
    while (!::GetPathManager()->CallMemberFunction())
    {
        reinterpret_cast<ScriptLocals*>(::GetPathManager())->ProcessPendingTasks();
        reinterpret_cast<::fnv_006c3640::C006c3640 *>((((::NavMeshObstacleManager *)(::fnv_006c0720::GetNavMeshObstacleManager()))))->FUN_006c3640();
    }
    reinterpret_cast<::FUN_006ebcf0_cls *>((::GetPathManager()))->CallInner();
}

// Reads the save file version and returns false after showing an error message if it is not 47 or 48.
// @fnv 0x00850ed0
bool BGSSaveLoadManager::CanLoadSaveGame(SaveLoadFile* file)
{
    int version = ::ReadSaveHeader(file);
    if (version > 48 || version < 47)
    {
        if (version <= 0)
        {
            ::fnv_00703e80::FUN_00703e80(reinterpret_cast<DownloadableContentManager*>(&g_011d3d0c)->IsDLCAvailable(), 0,
                                        0, 0, 0, 23, 0.0f, 0.0f,
                                        ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d38b8)))->GetMenuTitle())), 0);
        }
        else
        {
            char message[260];
            if (version < 48)
                ::FUN_00406d00(message, 260, DAT_0107fb78, version, 48);
            else
                ::FUN_00406d00(message, 260, DAT_0107faf8, version, 48);
            ::fnv_00703e80::FUN_00703e80(message, 0, 0, 0, 0, 23, 0.0f, 0.0f,
                                        ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d38b8)))->GetMenuTitle())), 0);
        }
        return false;
    }
    return true;
}

// @fnv 0x00850fe0
bool BGSSaveLoadManager::CanSave(bool skipMenus)
{
    if (::_g_thePlayer)
    {
        if ((uintptr_t)((::TESFile *)(reinterpret_cast<::FUN_004f8960_shell *>((((GameSettingCollection*)::_g_thePlayer)))->FUN_004f8960())) == 2 ||
            (uintptr_t)((::TESFile *)(reinterpret_cast<::FUN_004f8960_shell *>((((GameSettingCollection*)::_g_thePlayer)))->FUN_004f8960())) == 1)
            return false;
        if (::FUN_0093a740((::FUN_0093a740_s *)(::_g_thePlayer)))
            return false;
    }
    if (reinterpret_cast<::FUN_00525430_Class *>((((HUDMainMenu*)&g_011f2250)))->FUN_00525430())
        return false;
    if (!skipMenus)
    {
        unsigned int count = FUN_00702440();
        for (unsigned int index = 0; index < count; ++index)
        {
            int iMenuType = ::fnv_00702400::FUN_00702400(index);
            switch (iMenuType)
            {
            case 0:
            case 3:
            case 1013:
                break;
            case 1001:
                if (FUN_008510e0() > 0)
                    return false;
                break;
            default:
                return false;
            }
        }
    }
    return true;
}
// Builds the default save-file prefix from a game setting plus a suffix and compares it case-insensitively against name.
// @fnv 0x00851980
bool BGSSaveLoadManager::IsSaveFileNameDefault(const char* name)
{
    char prefix[260];
    TaskQueueInterface::CopyStringToBuffer(prefix, 260, ((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011d4060)))->GetMenuTitle())));
    fnv::crt::strcat_s(prefix, 260, ::DAT_01020770);
    if (name && _mbsnicmp(name, prefix, ::FUN_0044a670(prefix)) == 0)
        return true;
    return false;
}
// @fnv 0x00851aa0
bool BGSSaveLoadManager::IsSaveFileNameCustom(const char* name)
{
    if (IsSaveFileNameDefault(name) || IsSaveFileNameLegacyAutosave(name) || IsQuickSaveFileName(name) ||
        IsAutoSaveFileName(name))
        return false;
    return true;
}
// Formats the autosave name from g_autosaveName and the player's full name, truncates it to 27 characters, and passes it to DAT_011de134.
// @fnv 0x00850b40
void BGSSaveLoadManager::BuildAutosaveName(char* name)
{
    ::FUN_00406d00(name, 260, DAT_01012058, g_autosaveName, reinterpret_cast<::FUN_0055d520_shell *>((::_g_thePlayer))->FUN_0055d520());
    if (::FUN_0044a670(name) > 27)
        name[27] = 0;
    ::DAT_011de134->SanitizeSaveFileName(name);
}
// Returns true if name is non-null and starts with the prefix DAT_0107fae0 (case-insensitive compare).
// @fnv 0x00851a20
bool BGSSaveLoadManager::IsSaveFileNameLegacyAutosave(const char* name)
{
    if (name && _mbsnicmp(name, DAT_0107fae0, ::FUN_0044a670(DAT_0107fae0)) == 0)
        return true;
    return false;
}
// @fnv 0x00851d10
void BGSSaveLoadManager::UpdateSaveTimestamp()
{
    unk78c = ((unsigned int)(::FUN_00457fe0()));
}

struct FUN_0084fec0_shell : public BGSSaveLoadManager
{
    void EnsureFosExtension(char*, char*);
};


// Appends ".fos" to apFullFileName when its length is under 4 or it does not already end in ".fos".
// @fnv 0x0084fec0
void FUN_0084fec0_shell::EnsureFosExtension(char* apFileName, char* apFullFileName)
{
    TaskQueueInterface::CopyStringToBuffer(apFullFileName, 0x104, apFileName);
    unsigned int ilength = ::FUN_0044a670(apFullFileName);
    if (ilength < 4 || ::FUN_00404dc0(&apFullFileName[ilength - 4], ".fos") != 0)
        fnv::crt::strcat_s(apFullFileName, 0x104, ".fos");
}

struct FUN_00851250_shell : public BGSSaveLoadManager
{
    void SetSaveFileName(char*, int);
};
// @fnv 0x00850760
bool BGSSaveLoadManager::LoadGame(const char* name, int deviceID, bool recent, bool allowMissing)
{
    bool result;
    {
        char savedName[260];
        if (name)
            TaskQueueInterface::CopyStringToBuffer(savedName, 260, name);
        SaveLoadFile* file = 0;
        if (m_pSaveFile)
            file = m_pSaveFile;
        else
            file = reinterpret_cast<::FUN_00850030_shell *>((reinterpret_cast<SaveLoadHeader*>(this)))->FUN_00850030(
                (char *)(::SaveLoadFile *)(reinterpret_cast<SaveLoadFile*>(const_cast<char*>(name))), false, 1, deviceID);
        result = false;
        if (file)
        {
            bool consoleWasVisible = ::fnv_00703d50::FUN_00703d50();
            if (!reinterpret_cast<SettingT<INISettingCollection>*>(&g_011de248)->Bool()->b)
                allowMissing = true;
            if (::FUN_008463c0((::UnknownOwner008463c0 *)(reinterpret_cast<BGSLoadGameBuffer*>(file))))
            {
                if (CanLoadSaveGame(file))
                {
                    m_bLoadingGame = true;
                    result = reinterpret_cast<::ReconstructSession *>((::g_BGSSaveLoadGame))->LoadSaveGame((::SaveFile *)(file), allowMissing);
                    m_bLoadingGame = false;
                    if (result)
                        FinishLoadingGame();
                    else
                    {
                        TaskQueueInterface::CopyStringToBuffer(DAT_011de138, 260, name);
                        DAT_011a224c = deviceID;
                        DAT_011de23c = recent;
                        ::fnv_00703e80::FUN_00703e80(
                            ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d2100)))->GetMenuTitle())), 0, 0,
                            ::fnv_00850720::FUN_00850720, 1, 23, 0.0f, 0.0f,
                            ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d34f8)))->GetMenuTitle())),
                            ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d3684)))->GetMenuTitle())), 0);
                    }
                }
                else
                    result = false;
            }
            if (file != m_pSaveFile)
                reinterpret_cast<::BGSSaveLoadManager *>(this)->FUN_00850100((::SaveLoadHeader *)(file), false);
            if (result && recent)
            {
                char fullPath[260];
                reinterpret_cast<::FUN_0084ff90_shell *>(this)->BuildWeaponPath(const_cast<char*>(name), fullPath, false);
                DumpTextAndOpen(fullPath);
            }
            if (consoleWasVisible)
            {
                ::fnv_00703e10::FUN_00703e10();
                reinterpret_cast<::FUN_00714d70 *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->SetField(DAT_011dea24);
            }
            if (result)
                reinterpret_cast<::FUN_00851250_shell *>(this)->SetSaveFileName(savedName, deviceID);
        }
        reinterpret_cast<::fnv_00877430::FUN_00877430_shell *>((reinterpret_cast<Main*>(g_osGlobals)))->FUN_00877430();
    }
    return result;
}


// @fnv 0x00851250
void FUN_00851250_shell::SetSaveFileName(char* apSaveFileName, int aiDeviceID)
{
    if (!apSaveFileName)
        return;

    if (this->unk14 && !FUN_00408b20(this->unk14, apSaveFileName))
        return;

    delete this->unk14;
    unsigned int ilength = ::FUN_0044a670(apSaveFileName) + 1;
    this->unk14 = new char[ilength];
    TaskQueueInterface::CopyStringToBuffer(this->unk14, ilength, apSaveFileName);
    this->unk18 = aiDeviceID;
}

struct IOManager;

// Calls FUN_00c3e340 on DAT_01202d98, then calls FUN_006ebcd0 on the PathManager singleton.
// @fnv 0x00850bf0
void FUN_00850bf0(void*)
{
    reinterpret_cast<::FUN_00c3e340_cls *>((DAT_01202d98))->FUN_00c3e340();
    reinterpret_cast<::FUN_006ebcd0_shell *>((::GetPathManager()))->FUN_006ebcd0();
}

struct FUN_00765340_shell
{
    unsigned int GetUnfilteredCount();
};

// Returns the result of calling GetUnfilteredCount on the object at DAT_011da4f0 + 0x40, or 0 when DAT_011da4f0 is null.
// @fnv 0x008510e0
unsigned int FUN_008510e0()
{
    unsigned int result;
    if (DAT_011da4f0)
        result = reinterpret_cast<FUN_00765340_shell*>(DAT_011da4f0 + 0x40)->GetUnfilteredCount();
    else
        result = 0;
    return result;
}

struct FUN_00851d30_shell
{
    void FUN_00851d30();
    char pad00[0xf];
    unsigned char unk0f;
};

// @fnv 0x00851d30
void FUN_00851d30_shell::FUN_00851d30()
{
    this->unk0f = 1;
}

// @fnv 0x00851d50
void FUN_00851d50(void* apObject)
{
    ((char*)apObject)[0x10] = 1;
}

struct FUN_00851110_shell
{
    int GetConstant27();
};

// @fnv 0x00851110
int FUN_00851110_shell::GetConstant27()
{
    return 0x1b;
}

struct FUN_00851230_shell
{
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    bool IsField5Set();
};

// @fnv 0x00851230
bool FUN_00851230_shell::IsField5Set()
{
    return (field5 != 0) ? true : false;
}

struct FUN_00851d70_shell
{
    void SetFlagByte();
    char pad00[0x11];
    char unk11;
    char pad12[0x2];
};
// @fnv 0x00851d70
void FUN_00851d70_shell::SetFlagByte()
{
    this->unk11 = 1;
}

extern GlobalObject_0040c150 g_011d3600;
struct FUN_008509a0_Holder : BGSSaveLoadManager
{
    void FUN_008509a0();
};
struct FUN_008509f0_Holder : BGSSaveLoadManager
{
    void LoadQuickSave();
};
// Queues a UI message using a game setting string and then loads the quicksave.
// @fnv 0x008509f0
void FUN_008509f0_Holder::LoadQuickSave()
{
    ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d35ac))))->GetMenuTitle()))), 0, (const char *)(g_011cba4c_arg1), (const char *)(0), ::DAT_010162c0, 0);
    LoadGame(g_quicksaveName, -1, false, true);
}

struct Sky
{
};
class BaseProcess;
class MobileObject
{
};
struct FakeSaveMgr
{
    void ResetAndUpdate();
};
struct IOManager;
struct FUN_006ebc70_shell
{
    void FUN_006ebc70();
};
struct FUN_006ebc90_shell
{
    bool FUN_006ebc90();
};
struct FUN_00850ba0_shell
{
    void FUN_00850ba0();
};
// @fnv 0x00850ba0
void FUN_00850ba0_shell::FUN_00850ba0()
{
    ((FUN_006ebc70_shell*)::GetPathManager())->FUN_006ebc70();
    reinterpret_cast<::FUN_00c3e310_shell *>((DAT_01202d98))->FUN_00c3e310();
    while (!((FUN_006ebc90_shell*)::GetPathManager())->FUN_006ebc90())
    {
        ((ScriptLocals*)::GetPathManager())->ProcessPendingTasks();
    }
}

struct FUN_00847d00_shell
{
    void SetFlag4(bool);
};
struct FUN_00850ea0_shell
{
    void FUN_00850ea0(void*);
};
// @fnv 0x00850ea0
void FUN_00850ea0_shell::FUN_00850ea0(void* apArg)
{
    reinterpret_cast<FUN_00847d00_shell*>(::g_BGSSaveLoadGame)->SetFlag4(true);
    ::FUN_0084d4b0((::HeaderFile *)(apArg));
}

struct S00851cd0
{
    unsigned char _pad[0x78C];
    unsigned int f78C;
    unsigned int f790;
    void FUN_00851cd0();
};
// Adds the elapsed time since the last tick to f790 and calls UpdateSaveTimestamp on the BGSSaveLoadManager.
// @fnv 0x00851cd0
void S00851cd0::FUN_00851cd0()
{
    f790 += ((unsigned int)(::FUN_00457fe0())) - f78C;
    ((BGSSaveLoadManager*)this)->UpdateSaveTimestamp();
}

struct FUN_00851bf0_shell
{
    void FormatPlayTime(char* output, bool useThreeDigitHours);
};


struct FUN_00851cb0_shell
{
    unsigned int GetField790();
};

// Converts the player's total playing time into hours, minutes and seconds and writes them to output as a formatted string.
// @fnv 0x00851bf0
void FUN_00851bf0_shell::FormatPlayTime(char* output, bool useThreeDigitHours)
{
    unsigned int totalPlayingTime2 = ((FUN_00851cb0_shell*)::_g_thePlayer)->GetField790();
    unsigned int hours2 = totalPlayingTime2 / 0x36ee80;
    totalPlayingTime2 -= hours2 * 0x36ee80;
    unsigned int minutes = totalPlayingTime2 / 0xea60;
    totalPlayingTime2 -= minutes * 0xea60;
    unsigned int seconds = totalPlayingTime2 / 0x3e8;
    if (useThreeDigitHours)
        ::FUN_00406d00(output, 0x104, "%03i.%02i.%02i", hours2, minutes, seconds);
    else
        ::FUN_00406d00(output, 0x104, "%02i.%02i.%02i", hours2, minutes, seconds);
}

namespace fnv_00851cb0 {
struct S00851cd0
{
    int m_790;
    int GetField790();
    unsigned int pad04[0x1e3];
    int unk790;
};

// @fnv 0x00851cb0
int S00851cd0::GetField790()
{
    reinterpret_cast<::S00851cd0 *>(this)->FUN_00851cd0();
    return this->unk790;
}
}  // namespace fnv_00851cb0

namespace fnv_008517c0 {

extern unsigned int _data_011c16bc;
extern void __cdecl _ref_00ec408c(unsigned int value);


struct FUN_00851bf0_shell
{
};

struct FUN_008517c0_shell
{
    unsigned char reserved[8];
    unsigned int m_uiSaveLoadSubstate;

    void BuildSaveFileName(char* saveFileName, bool autosave, bool displayOnly);
    void CopyPlayerName(char* playerLocationName);
};

// Builds a save file name from the player name, location and play time, truncating it to fit and passing it to the save manager unless autosaving.
// @fnv 0x008517c0
void FUN_008517c0_shell::BuildSaveFileName(char* saveFileName, bool autosave, bool displayOnly)
{
    const char* pplayerName;
    char pplayTimeString[260];
    char pplayerLocationName[260];

    pplayerName = reinterpret_cast<::FUN_0055d520_shell *>(((*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer))))->FUN_0055d520();

    this->CopyPlayerName(pplayerLocationName);
    reinterpret_cast<::FUN_00851bf0_shell *>((reinterpret_cast<FUN_00851bf0_shell*>(this)))->FormatPlayTime(pplayTimeString, autosave);

    ::FUN_00406d00(saveFileName, 0x104, "%s %i - %s, %s, %s",
               displayOnly ? ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&::g_011d3ed4)))->GetMenuTitle()))
                           : ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d4060)))->GetMenuTitle())),
               m_uiSaveLoadSubstate, pplayerName, pplayerLocationName, pplayTimeString);

    if (!autosave)
    {
        unsigned int imaxFileNameLength = 0x104;
        if (::FUN_0044a670(saveFileName) > imaxFileNameLength - 5)
            saveFileName[imaxFileNameLength - 5] = 0;

        reinterpret_cast<BGSSaveLoadManager*>(this)->SanitizeSaveFileName(saveFileName);
    }
}
}  // namespace fnv_008517c0

using FUN_00404eb0 = ::AutoMemContext;
struct MessageSink
{
};
extern "C" const char str_0106eb78[];

// Creates a scope object, and if an interface manager and message sink exist, forwards the six arguments to the sink; returns false.
// @fnv 0x007052f0
bool __cdecl DispatchMessageToSink(const char* aiArg1, int aiArg2, const char* aiArg3, const char* aiArg4, float value, unsigned char option)
{
    FUN_00404eb0 scope(13, 1, str_0106eb78, 0x901);
    if (((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())) && reinterpret_cast<::FUN_009373f0_shell *>((((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()))))->FUN_009373f0() && (*reinterpret_cast<::MessageSink * *>(&::g_pHudMainMenuInstance)))
        reinterpret_cast<::MessageHUD *>(((*reinterpret_cast<::MessageSink * *>(&::g_pHudMainMenuInstance))))->AddMessage(aiArg1, aiArg2, aiArg3, aiArg4, value, option);
    return false;
}

struct SaveGameDetails
{
};
struct SaveGameOps
{
};
struct SettingString
{
    const char* GetString();
};
struct SaveManager
{
    int field00;
    int field04;
    int index;
    char field0c;
    bool saving;
    short field0e;
    bool force;
    char field11;
    short field12;
    int field14;
    int field18;
    int field1c;
    SaveLoadFile* file;
    bool FUN_008503b0(const char*, int, bool);
};
// @fnv 0x00851d90
void BGSSaveLoadManager::ProcessQueuedSaveLoad()
{
    if (m_cQueuedSaveLoad)
    {
        if (m_cQueuedSaveLoad > 1)
            --m_cQueuedSaveLoad;
        else if (!reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)1) &&
                 !reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)2) &&
                 !Interface::IsInterfaceActive())
            reinterpret_cast<::FakeSaveMgr *>((::DAT_011de134))->ResetAndUpdate();
    }
    else if (m_cAutosaveCountdown)
    {
        if (m_cAutosaveCountdown > 1)
            --m_cAutosaveCountdown;
        else if (!reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)1) &&
                 !reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)2) &&
                 !Interface::IsInterfaceActive())
        {
            reinterpret_cast<::SaveManager *>((::DAT_011de134))->FUN_008503b0(0, -1, false);
            m_cAutosaveCountdown = 0;
        }
    }
    else if (cQueuedQuicksave)
    {
        if (cQueuedQuicksave > 1)
            --cQueuedQuicksave;
        else if (!reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)1) &&
                 !reinterpret_cast<FaderManager*>(DAT_011d8804)->HasFader((FADER_ENUM)2) &&
                 !Interface::IsInterfaceActive())
            ::DAT_011de134->FUN_00850a90();
    }
}
// Queues a UI message from the game setting string and then calls FUN_008503b0 with g_quicksaveName and -1, 0.
// @fnv 0x008509a0
void FUN_008509a0_Holder::FUN_008509a0()
{
    ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011d3600)))->GetMenuTitle()))), 0, (const char *)(g_011cba4c_arg1), (const char *)(0), DAT_010162c0, 0);
    reinterpret_cast<::SaveManager *>(this)->FUN_008503b0(g_quicksaveName, -1, 0);
}
// Clears two fields on this manager, updates the current AI process's Sky with FUN_00453850(), then calls FUN_008503b0(DAT_0107fae0, -1, 0).
// @fnv 0x00850a40
void FakeSaveMgr::ResetAndUpdate()
{
    ((BGSSaveLoadManager*)this)->m_cQueuedSaveLoad = 0;
    ((BGSSaveLoadManager*)this)->prefix[14] = 0;
    reinterpret_cast<::fnv_0063ac70::FUN_0063ac70_shell *>((((Sky*)((::BaseProcess *)(reinterpret_cast<::BSShaderNoLightingProperty *>((void *)(((MobileObject*)(*reinterpret_cast<::TES * *>(&::g_TES)))))->GetBaseTexture())))))->FUN_0063ac70(FUN_00453850());
    reinterpret_cast<::SaveManager *>((((BGSSaveLoadManager*)this)))->FUN_008503b0(DAT_0107fae0, -1, 0);
}
// @fnv 0x008503b0
bool SaveManager::FUN_008503b0(const char* acFileName, int mode, bool remove)
{
    bool q = reinterpret_cast<::BGSSaveLoadManager *>(this)->IsSaveFileNameLegacyAutosave(acFileName);
    bool b = reinterpret_cast<::BGSSaveLoadManager *>(this)->IsQuickSaveFileName(acFileName);
    bool a = reinterpret_cast<::BGSSaveLoadManager *>(this)->IsAutoSaveFileName(acFileName);
    bool eb = false;
    char f[260];
    char cf[260];
    char ba[260];
    if (q || force || a)
        eb = true;
    if (!reinterpret_cast<::BGSSaveLoadManager *>(this)->CanSave(q))
    {
        if (!eb)
            ::DispatchMessageToSink((const char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d2364))))->GetMenuTitle()))), 0, (const char *)(::g_011cba18_arg1), (const char *)(0), DAT_010162c0, false);
        return false;
    }
    if (index == 0)
    {
        reinterpret_cast<::FileEnumerator *>(this)->FUN_00851330();
        reinterpret_cast<::RecordList *>(this)->FUN_00851540();
    }
    if (!acFileName)
    {
        reinterpret_cast<::fnv_008517c0::FUN_008517c0_shell *>(this)->BuildSaveFileName(cf, 0, 0);
        acFileName = cf;
    }
    ::TaskQueueInterface::CopyStringToBuffer(f, 260, acFileName);
    reinterpret_cast<::fnv_0084ab20::FUN_0084ab20_shell *>((((SaveGameOps*)::g_BGSSaveLoadGame)))->FUN_0084ab20();
    unsigned int h = reinterpret_cast<::FUN_00620b80_shell *>((((::SaveGameDetails *)(reinterpret_cast<::BGSSaveLoadGameView *>(::g_BGSSaveLoadGame)->pSaveLoadHistory))))->GetReferenceFlags();
    reinterpret_cast<::FUN_00850ba0_shell *>(this)->FUN_00850ba0();
    SaveLoadFile* i = 0;
    if (file)
        i = file;
    else
        i = reinterpret_cast<::FUN_00850030_shell *>(this)->FUN_00850030((char *)(acFileName), 1, 2, mode);
    if (!i)
    {
        ::FUN_00850bf0(this);
        return false;
    }
    if (eb)
    {
        saving = false;
        ::DispatchMessageToSink((const char *)((*reinterpret_cast<::SettingString *>(&::g_011d4930)).GetString()), 0, (const char *)(::g_011cba4c_arg1), (const char *)(0), DAT_010162c0, true);
    }
    reinterpret_cast<::FUN_00850ea0_shell *>(this)->FUN_00850ea0(i);
    reinterpret_cast<::fnv_00847850::W20Save *>((((SaveGameOps*)::g_BGSSaveLoadGame)))->FUN_00847850((::fnv_00847850::W20File *)(i));
    if (reinterpret_cast<::FUN_005621d0_shell *>((((SaveGameOps*)::g_BGSSaveLoadGame)))->FUN_005621d0())
    {
        reinterpret_cast<::FUN_00847d00_shell *>((((SaveGameOps*)::g_BGSSaveLoadGame)))->SetFlag4(false);
        ::DispatchMessageToSink((const char *)((*reinterpret_cast<::SettingString *>(&::g_011d4f0c)).GetString()), 0, (const char *)(::g_011cba18_arg1), (const char *)(0), DAT_010162c0, false);
        ::FUN_00850bf0(this);
        return false;
    }
    ::FUN_00850bf0(this);
    if (i != file)
        reinterpret_cast<::BGSSaveLoadManager *>(this)->FUN_00850100((::SaveLoadHeader *)(i), true);
    if (remove)
    {
        reinterpret_cast<::FUN_0084ff90_shell *>(this)->BuildWeaponPath((char *)(acFileName), ba, false);
        DumpTextAndOpen(ba);
    }
    reinterpret_cast<::FUN_0084e250_shell *>((((::SaveGameDetails *)(reinterpret_cast<::BGSSaveLoadGameView *>(::g_BGSSaveLoadGame)->pSaveLoadHistory))))->DeleteItemsFrom(h);
    if (i != file && field00)
        reinterpret_cast<::FUN_00851680_class *>(this)->AddFileToList(f, mode, index);
    if (!b && !q)
        index = index + 1;
    reinterpret_cast<::FUN_00851250_shell *>(this)->SetSaveFileName(f, mode);
    bool p = true;
    return p;
}

struct StrStandIn851
{
    char* m_data;
    unsigned short m_dataLen;
    unsigned short m_bufLen;
    StrStandIn851();
    ~StrStandIn851();
    operator const char*() const;
};
struct PlayerStandIn851
{
};
struct MgrStandIn851
{
    void CopyPlayerName(char* dest);
};
// Copies the player's name into dest (up to 0x104 bytes), or an empty string if the name is null.
// @fnv 0x00851b40
void MgrStandIn851::CopyPlayerName(char* dest)
{
    StrStandIn851 name;
    reinterpret_cast<::fnv_00578870::FUN_00578870_Class *>(((*reinterpret_cast<::PlayerStandIn851 * *>(&::_g_thePlayer))))->FUN_00578870((*(::fnv_00578870::BSStr *)(&name)));
    if ((const char*)name)
        ::TaskQueueInterface::CopyStringToBuffer(dest, 0x104, name);
    else
        ::TaskQueueInterface::CopyStringToBuffer(dest, 0x104, "");
}

struct Modifier
{
  public:
};

class Menu
{
  public:
    virtual ~Menu();
};

class DialogMenu : public Menu
{
};

class Tile_
{
  public:
};

class FUN_00764200_shell
{
  public:
    void SetActive(bool b);
};


// If a modifier key is held, look up tile 0x3f1, cast its menu to DialogMenu, and call SetActive on it.
// @fnv 0x00705110
void __cdecl SetDialogMenuActive(bool abActive)
{
    if (((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())) && ((unsigned char)(reinterpret_cast<::FUN_009373f0_shell *>((reinterpret_cast<Modifier*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_009373f0())))
    {
        DialogMenu* pkMenu;
        Tile_* pkTile = ((::Tile_ *)(::FUN_00a09030(0x3f1)));
        pkMenu = pkTile ? dynamic_cast<DialogMenu*>(reinterpret_cast<::FUN_00a03c90_shell *>((pkTile))->FUN_00a03c90()) : 0;
        if (pkMenu)
            reinterpret_cast<FUN_00764200_shell*>(pkMenu)->SetActive(abActive);
    }
}

struct BSStr
{
};

struct S7010
{
};

class Actor
{
};


// @fnv 0x00850a90
void BGSSaveLoadManager::FUN_00850a90()
{
    char autosaveName[260];

    cQueuedQuicksave = 0;
    prefix[14] = 0;

    reinterpret_cast<::fnv_0063ac70::FUN_0063ac70_shell *>((reinterpret_cast<Sky*>(((void *)(reinterpret_cast<::BSShaderNoLightingProperty *>((reinterpret_cast<Actor*>((*reinterpret_cast<::TES * *>(&::g_TES)))))->GetBaseTexture())))))->FUN_0063ac70(FUN_00453850());

    BGSSaveLoadManager::BuildAutosaveName(autosaveName);

    if (((unsigned int)(reinterpret_cast<::FUN_004048e0_cls *>(&unk30)->FUN_004048e0())) == 0)
    {
        reinterpret_cast<::TextString *>(&unk30)->FUN_004037f0(autosaveName, 0);
    }

    reinterpret_cast<::SaveManager *>(this)->FUN_008503b0(autosaveName, -1, false);
}

#include "generated/data/fallout/misc/saveload/bgssaveloadmanager.inc"
